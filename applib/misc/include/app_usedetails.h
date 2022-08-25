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
 * app_usedetails.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains address parse function.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _APP_USEDETAILS_H
#define _APP_USEDETAILS_H

#include "kal_general_types.h"

/***************************************************************************** 
* Define
*****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
#define APPLIB_MIN_PHONE_NUM_LEN    3
#define APPLIB_MAX_PHONE_NUM_LEN    41
#define APPLIB_MIN_USSD_LEN    3
#define APPLIB_MAX_USSD_LEN    41
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
typedef enum
{
    APPLIB_INVALID_NUMBER,
    APPLIB_TEL_NUMBER,
    APPLIB_SSC_NUMBER
}applib_number_type_enum;
/* DOM-NOT_FOR_SDK-END */

/* The extraction address type */
typedef enum 
{
    APPLIB_ADDR_TYPE_EMAIL = 0x1,       /* The email address type */
    APPLIB_ADDR_TYPE_URL = 0x2,         /* The URL type */
    APPLIB_ADDR_TYPE_PHONENUMBER = 0x4, /* The phone number type */
    APPLIB_ADDR_TYPE_USSD = 0x8         /* The USSD type */
}applib_addr_type_enum;

/* The charset type of input data */
typedef enum 
{
    APPLIB_INPUT_DATA_TYPE_ASCII = 0x1, /* ASCII type */
    APPLIB_INPUT_DATA_TYPE_UTF8,        /* UTF8 type */
    APPLIB_INPUT_DATA_TYPE_UNICODE      /* UNICODE type */
}applib_charset_enum;

/* The extracted address node. When application use extraction function, output extracted address is an linked list and each node contains one address structure */
typedef struct applib_address_node_st
{
    kal_wchar *data;                        /* Extracted address data */
    kal_wchar *data2;                       /* Not null for APPLIB_ADDR_TYPE_PHONENUMBER. Same as *data but without written-seq, ex. '(', ')', '-' */
    kal_int32 dataType;                     /* APPLIB_ADDR_TYPE_EMAIL, APPLIB_ADDR_TYPE_URL, APPLIB_ADDR_TYPE_PHONENUMBER and APPLIB_ADDR_TYPE_USSD */ 
    kal_uint32 pos;                         /* The position of extracted address in original input data */
    kal_uint32 length;                      /* Length of address data. Count by byte not character */
    struct applib_address_node_st *next;    /* Next address node */
}applib_address_node_struct;

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  applib_mem_alloc_fn
 * DESCRIPTION
 *  Memory allocation function for allocating memory of output linked list structure.
 *  If this function cannot allocat memory, it will stop extracting address.
 * PARAMETERS
 *  size    :   [IN]    Memory size.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void *(*applib_mem_alloc_fn) (kal_uint32);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  applib_mem_free_fn
 * DESCRIPTION
 *  Memory free function.
 * PARAMETERS
 *  ptr :   [IN]    Pointer to memory.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*applib_mem_free_fn) (void *);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  applib_check_stop_fn
 * DESCRIPTION
 *  Check if parsing should be stopped (being invoked when every address is extracted).
 * PARAMETERS
 *  addr_type       :   [IN]    Address type.
 *  address_node    :   [IN]    The extracted address node.
 *  extracted_num   :   [IN]    Total number of extracted address.
 * RETURNS
 *  void
 *****************************************************************************/
typedef kal_bool (*applib_check_stop_fn) (applib_addr_type_enum, applib_address_node_struct *, kal_uint32);

/***************************************************************************** 
             
* Extern Global 
Variable                                                                    
*****************************************************************************/
/***************************************************************************** 
             
* Extern Global 
Function                                                                    
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_email_address
 * DESCRIPTION
 *  This function is used to validity input email address.Reference RFC 2822.
 * PARAMETERS
 *  str  :       [IN]            Pointer to UTF8 email address string
 * RETURN VALUES
 *  TRUE :  The input string is a valid email address.
 *  FALSE : The input string is an invalid email address.
 *****************************************************************************/
kal_bool applib_is_valid_email_address(const char *str);

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_email_address
 * DESCRIPTION
 *  This function is used to validity input email address.Reference RFC 2822.
 * PARAMETERS
 *  str  :       [IN]            Pointer to UCS2 email address string
 * RETURN VALUES
 *  TRUE :  The input string is a valid email address.
 *  FALSE : The input string is an invalid email address.
 *****************************************************************************/
kal_bool applib_is_valid_email_address_unicode(const kal_wchar *str);
/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_EMAIL__
kal_bool applib_is_valid_email_local_part_unicode(const kal_wchar *str, int cnt);
kal_bool applib_is_valid_email_local_part(const char *str, int cnt);
kal_bool applib_is_valid_email_domain_name(const char *str);
kal_bool applib_is_valid_email_domain_name_unicode(const kal_wchar *str);
/* DOM-NOT_FOR_SDK-END */
#endif /* __MMI_EMAIL__ */

/* DOM-NOT_FOR_SDK-BEGIN */
kal_uint8 applib_ss_string_parsing(kal_uint8 *string_ptr, kal_uint8 length, kal_uint8 sim_interface, kal_bool is_in_call);
kal_uint8 applib_ss_string_parsing_unicode(kal_wchar *string_ptr, kal_uint8 length, kal_uint8 sim_interface, kal_bool is_in_call);
/* DOM-NOT_FOR_SDK-END */
/*****************************************************************************
 * FUNCTION
 *  applib_get_exclusive_address_list_from_text_ext
 * DESCRIPTION
 *  This interface function is used to get all addresses from input text data.
 *  Input text data could be encoded as ASCII, UTF8 or UNICODE. Caller must specify in input_data_type.
 *  It will remove duplcate address.
 * PARAMETERS
 *  addr_type		:   [IN]        Address Types
 *  mem_alloc_fn    :   [IN]        Memory allocation function
 *  mem_free_fn		:   [IN]        Memory free function
 *  check_stop_fn   :   [IN]        Check if parsing should be stopped (being invoked when every address is parsed)
 *  input_data_type :   [IN]        The charset type of input data
 *  input_data		:   [IN]        Input text data
 *  dataLen       	:   [IN]        Length of input text data
 *  is_stopped      :   [IN/OUT]    Specify if parsing procedure being stopped by user
 * RETURNS
 *  Extracted addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_get_exclusive_address_list_from_text_ext(applib_addr_type_enum addr_type,
    applib_mem_alloc_fn mem_alloc_fn, applib_mem_free_fn mem_free_fn, applib_check_stop_fn check_stop_fn,
    applib_charset_enum input_data_type, char *input_data, kal_int32 dataLen, kal_bool *is_stopped);
    
/*****************************************************************************
 * FUNCTION
 *  applib_get_exclusive_address_list_from_text
 * DESCRIPTION
 *  This interface function is used to get all addresses from one UTF8-encoded text.
 *  It will remove duplcate address.
 * PARAMETERS
 *  addr_type		:   [IN]        Address Types
 *  mem_alloc_fn    :   [IN]        Memory allocation function
 *  mem_free_fn		:   [IN]        Memory free function
 *  input_data		:   [IN]        Input text data
 *  dataLen       	:   [IN]        Length of input text data
 * RETURNS
 *  Extracted addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_get_exclusive_address_list_from_text(applib_addr_type_enum addr_type,
    applib_mem_alloc_fn mem_alloc_fn, applib_mem_free_fn mem_free_fn, char *input_data, kal_int32 dataLen);
    
/*****************************************************************************
 * FUNCTION
 *  applib_get_address_list_from_text_ext
 * DESCRIPTION
 *  This interface function is used to get all addresses from input text data.
 *  Input text data could be encoded as ASCII, UTF8 or UNICODE. Caller must specify in input_data_type.
 *  It doesn't remove duplcate address.
 * PARAMETERS
 *  addr_type		:   [IN]        Address Types
 *  mem_alloc_fn    :   [IN]        Memory allocation function
 *  mem_free_fn		:   [IN]        Memory free function
 *  check_stop_fn   :   [IN]        Check if parsing should be stopped (being invoked when every address is parsed)
 *  input_data_type :   [IN]        The charset type of input data
 *  input_data		:   [IN]        Input text data
 *  dataLen       	:   [IN]        Length of input text data
 *  is_stopped      :   [IN/OUT]    Specify if parsing procedure being stopped by user
 * RETURNS
 *  Extracted addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_get_address_list_from_text_ext(applib_addr_type_enum addr_type,
    applib_mem_alloc_fn mem_alloc_fn, applib_mem_free_fn mem_free_fn, applib_check_stop_fn check_stop_fn,
    applib_charset_enum input_data_type, char *input_data, kal_int32 dataLen, kal_bool *is_stopped);
    
/*****************************************************************************
 * FUNCTION
 *  applib_get_address_list_from_text
 * DESCRIPTION
 *  This interface function is used to get all addresses from one UTF8-encoded text.
 *  It doesn't remove duplcate address.
 * PARAMETERS
 *  addr_type		:   [IN]        Address Types
 *  mem_alloc_fn    :   [IN]        Memory allocation function
 *  mem_free_fn		:   [IN]        Memory free function
 *  input_data		:   [IN]        Input text data
 *  dataLen       	:   [IN]        Length of input text data
 * RETURNS
 *  Extracted addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_get_address_list_from_text(applib_addr_type_enum addr_type,
    applib_mem_alloc_fn mem_alloc_fn, applib_mem_free_fn mem_free_fn, char *input_data, kal_int32 dataLen);
    
/*****************************************************************************
 * FUNCTION
 *  applib_free_address_list
 * DESCRIPTION
 *  This interface function is used to free all addresses of one list
 * PARAMETERS
 *  addr_list   :   [IN]    Addresses list
 *  mem_free_fn :   [IN]    Memory free function
 * RETURNS
 *  KAL_TRUE if successful or KAL_FALSE if failed
 *****************************************************************************/
kal_bool applib_free_address_list(applib_address_node_struct **addr_list, applib_mem_free_fn mem_free_fn);

/*****************************************************************************
 * FUNCTION
 *  applib_concatenate_address_list
 * DESCRIPTION
 *  This interface function is used to concatenate list2 to the end of list1. 
 *  Users should be awared about the consistency of memory alloc/free owner
 * PARAMETERS
 *  list1   :   [IN]    Addresses list 1
 *  list2   :   [IN]    Addresses list 2
 * RETURNS
 *  Concatenate address (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_concatenate_address_list(applib_address_node_struct *list1, 
                                                            applib_address_node_struct *list2);

/*****************************************************************************
 * FUNCTION
 *  applib_remove_duplicate_address
 * DESCRIPTION
 *  This function is used to remove duplicate addresses
 * PARAMETERS
 *  addr_list   :   [IN]    Address list being checked
 *  mem_free_fn :   [IN]    Memory free function
 * RETURNS
 *  void
 *****************************************************************************/
void applib_remove_duplicate_address(applib_address_node_struct **addr_list, applib_mem_free_fn mem_free_fn);

/*****************************************************************************
 * FUNCTION
 *  applib_remove_duplicate_unicode_address
 * DESCRIPTION
 *  This function is used to remove duplicate unicode addresses
 * PARAMETERS
 *  addr_list   :   [IN]    Address list being checked
 *  mem_free_fn :   [IN]    Memory free function
 * RETURNS
 *  void
 *****************************************************************************/
void applib_remove_duplicate_unicode_address(applib_address_node_struct **addr_list, applib_mem_free_fn mem_free_fn);

/* DOM-NOT_FOR_SDK-BEGIN */
kal_uint8  applib_is_valid_number(kal_uint8 *number);
kal_uint8 applib_is_valid_number_unicode(kal_wchar *number);
kal_bool applib_is_valid_tel(kal_uint8 *number);
kal_bool applib_is_valid_ssc(kal_uint8 *number);
kal_uint8 applib_encode_number(kal_uint8 *src_num, kal_uint8 *des_num, kal_uint8 ton);
kal_uint8 applib_encode_number_unicode(kal_wchar *src_num, kal_wchar *des_num);
kal_uint8 applib_decode_number(kal_uint8 *src_num, kal_uint8 *des_num, kal_uint8 ton);
kal_uint8 applib_decode_number_unicode(kal_wchar *src_num, kal_wchar *des_num);
/* DOM-NOT_FOR_SDK-END */

#endif /* _APP_USEDETAILS_H */ 

