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
 * app_url.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains URI parsing utilities.
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

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <app_usedetails.h>

#include "kal_public_api.h"
#include "app_url.h"
#include "app_str.h"

#include "kal_general_types.h"
#include "stdio.h"
#define APPLIB_USE_DETAILS_URL_SCHEME_NO 3
#define URL_SCHEME1 "http"
#define URL_SCHEME2 "https"
#define URL_SCHEME3 "rtsp"

#define URL_UNICODE_SCHEME1 L"http"
#define URL_UNICODE_SCHEME2 L"https"
#define URL_UNICODE_SCHEME3 L"rtsp"

#define APPLIB_USE_DETAILS_URL_PATTERN_NO 9
#define URL_PATTERN_1  "://"
#define URL_PATTERN_2  ":\\\\"
#define URL_PATTERN_3  "wap."
#define URL_PATTERN_4  "www."
#define URL_PATTERN_5  "<http://"
#define URL_PATTERN_6  "<://"
#define URL_PATTERN_7  "<:\\\\"
#define URL_PATTERN_8  "<wap."
#define URL_PATTERN_9  "<www."
#define URL_END_1 "/>"
#define URL_END_2 "<"
#define URL_END_PATTERN_1  L"/>"
#define URL_END_PATTERN_2  L"<"

#define URL_UNICODE_PATTERN_1  L"://"
#define URL_UNICODE_PATTERN_2  L":\\\\"
#define URL_UNICODE_PATTERN_3  L"wap."
#define URL_UNICODE_PATTERN_4  L"www."
#define URL_UNICODE_PATTERN_5  L"<http://"
#define URL_UNICODE_PATTERN_6  L"<://"
#define URL_UNICODE_PATTERN_7  L"<:\\\\"
#define URL_UNICODE_PATTERN_8  L"<wap."
#define URL_UNICODE_PATTERN_9  L"www."
static applib_scheme_struct supported_schemes[] = APPLIB_URL_SUPPORTED_SCHEMES;

extern kal_bool applib_is_valid_url_wchar(kal_wchar ch);


#define is_alpha(c)      (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
    
#define is_digit(c)        ((c >= '0') && (c <= '9'))

#define is_alphadigit(c)    (is_alpha(c) || is_digit(c))

static int _strncasecmp(const char *s1, const char *s2, unsigned int n)
{
    if (n == 0)
        return 0;

    while ((n-- != 0)
           && (tolower(*(unsigned char *) s1) ==
               tolower(*(unsigned char *) s2))) {
        if (n == 0 || *s1 == '\0' || *s2 == '\0')
            return 0;
        s1++;
        s2++;
    }

    return tolower(*(unsigned char *) s1) - tolower(*(unsigned char *) s2);
}


/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_url_scheme_char
 * DESCRIPTION
 *  This internal function is used to check if input char is valid URL scheme character
  * PARAMETERS
 *  ch		[IN]	character being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_is_valid_url_scheme_char(char ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (ch != NULL)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_url_scheme_wchar
 * DESCRIPTION
 *  This internal function is used to check if input char is valid URL scheme character
  * PARAMETERS
 *  ch		[IN]	character being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_is_valid_url_scheme_wchar(kal_wchar ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (ch != NULL)
    {
        if ((ch >= L'a' && ch <= L'z') || (ch >= L'A' && ch <= L'Z'))
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_url_char
 * DESCRIPTION
 *  This internal function is used to check if input char is valid URL character
  * PARAMETERS
 *  ch		[IN]	character being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool applib_is_valid_url_char(char ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    char url_special_chars[] = {':', ';', '/', '\\', '.', ',', '#', '?', '$', '+', '@', '&', '=', '%', '-', '_', '(', ')', '[', ']', '{', '}', '<', '>', '`', '~', '!', '^', '*', '|', '"', '\''};
    kal_int32 num_url_special_chars = sizeof(url_special_chars);
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (ch != NULL)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            return KAL_TRUE;
        }
        else
        {
            for (i = 0; i < num_url_special_chars; i++)
            {
                if (ch == url_special_chars[i])
                {
                    return KAL_TRUE;
                }
            }
            return KAL_FALSE;
        }
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_url_wchar
 * DESCRIPTION
 *  This internal function is used to check if input char is valid URL character
  * PARAMETERS
 *  ch		[IN]	character being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool applib_is_valid_url_wchar(kal_wchar ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    kal_wchar url_special_chars[] = {L':', L';', L'/', L'\\', L'.', L',', L'#', L'?', L'$', L'+', L'@', L'&', L'=', L'%', L'-', L'_', L'(', L')', L'[', L']', L'{', L'}', L'<', L'>', L'`', L'~', L'!', L'^', L'*', L'|', L'"', L'\''};
    kal_int32 num_url_special_chars = (sizeof(url_special_chars)/2);
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (ch != NULL)
    {
        if ((ch >= L'a' && ch <= L'z') || (ch >= L'A' && ch <= L'Z') || (ch >= L'0' && ch <= L'9'))
        {
            return KAL_TRUE;
        }
        else
        {
            for (i = 0; i < num_url_special_chars; i++)
            {
                if (ch == url_special_chars[i])
                {
                    return KAL_TRUE;
                }
            }
            return KAL_FALSE;
        }
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_url_last_char
 * DESCRIPTION
 *  This internal function is used to check if input char is valid last URL character
  * PARAMETERS
 *  ch		[IN]	character being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_is_valid_url_last_char(kal_char ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	

    kal_char url_invlid_chars[] = {'(', ')', '[', ']', '{', '}', '<', '>', ',' , '.', '"', '\'', '?', ':', ';', '-'};
	kal_int32 num_url_invalid_chars = sizeof(url_invlid_chars);
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (applib_is_valid_url_char(ch) == KAL_TRUE)
    {
        for (i = 0; i < num_url_invalid_chars; i++)
        {
            if (ch == url_invlid_chars[i])
            {
                return KAL_FALSE;
            }
        }
        return KAL_TRUE;        
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_url_last_wchar
 * DESCRIPTION
 *  This internal function is used to check if input char is valid last URL character
  * PARAMETERS
 *  ch		[IN]	character being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_is_valid_url_last_wchar(kal_wchar ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    kal_wchar url_invlid_chars[] = {L'(', L')', L'[', L']', L'{', L'}', L'<', L'>', L',' , L'.', L'"', L'\'', L'?', L':', L';', L'-'};
    kal_int32 num_url_invalid_chars = (sizeof(url_invlid_chars)/2);
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (applib_is_valid_url_wchar(ch) == KAL_TRUE)
    {
        for (i = 0; i < num_url_invalid_chars; i++)
        {
            if (ch == url_invlid_chars[i])
            {
                return KAL_FALSE;
            }
        }
        return KAL_TRUE;        
    }
    else
    {
        return KAL_FALSE;
    }
}

#ifdef BROWSER_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  applib_parse_url_from_text
 * DESCRIPTION
 *  This function is used to get specific addresses from one UTF8-encoded text.
 *  The list is in reverse order.
 * PARAMETERS
 *  mem_alloc_fn    [IN]	Memory allication function
 *  mem_free_fn		[IN]	Memory free function
 *  check_stop_fn   [IN]    Check if parsing should be stopped (being invoked when every address is parsed)
 *  input_data		[IN]	Input text data
 *  dataLen       	[IN]	Length of input text data
 *  is_stopped      [IN/OUT]Specify if parsing procedure being stopped by user
 *  is_remove_duplicate [IN] Remove duplicate address or not.
 * RETURNS
 *  addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_parse_url_from_text(
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        applib_check_stop_fn check_stop_fn,
        char *input_data, 
        kal_int32 dataLen,
        kal_bool *is_stopped,
        kal_bool is_remove_duplicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    int len = 0, parsed_no = 0;
    char *data = NULL;
    applib_address_node_struct *address_list = NULL;  
    char *pattern[APPLIB_USE_DETAILS_URL_PATTERN_NO] = {URL_PATTERN_1, URL_PATTERN_2, URL_PATTERN_3, URL_PATTERN_4,URL_PATTERN_5,URL_PATTERN_6,URL_PATTERN_7,URL_PATTERN_8,URL_PATTERN_9};
    char *scheme[APPLIB_USE_DETAILS_URL_SCHEME_NO] = {URL_SCHEME1, URL_SCHEME2, URL_SCHEME3};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mem_alloc_fn == NULL || mem_free_fn == NULL || input_data == NULL || dataLen == 0 || *is_stopped == KAL_TRUE)
    {
        return NULL;
    }

    data = input_data;
    len = dataLen;

    while (data - input_data < dataLen)
    {
        char *start = NULL, *end = NULL;
        int i = 0, type = 0;
        char *data_lc = mem_alloc_fn(len + 1);
        if (data_lc == NULL)
        {
            return address_list;
        }

        memset(data_lc, 0x00, len + 1);
        strncpy(data_lc, data, len);
        app_strtolower(data_lc);

        for(i = 0 ; i < APPLIB_USE_DETAILS_URL_PATTERN_NO; i++)  /* find the 1st show-up pattern */
        {
            char *new_start = NULL;

            new_start = strstr(data_lc, pattern[i]);
            if (new_start != NULL)
            {
				if((app_strnicmp(pattern[i], "<http:", 6) == 0) ||(app_strnicmp(pattern[i], "<www.", 5) == 0)||(app_strnicmp(pattern[i], "<wap.", 5) == 0)||(app_strnicmp(pattern[i], "<://", 4) == 0)||(app_strnicmp(pattern[i], "<:\\\\", 6) == 0) )
				new_start++;
                new_start = data + (int)(new_start - data_lc);
                if (start == NULL)
                {
                    start = new_start;
                    type = i;
                }
                else if((kal_uint32)new_start < (kal_uint32)start)
                {
                    start = new_start;
                    type = i;
                }
            }
        }

        mem_free_fn(data_lc);        
        if (start == NULL)  /* not found */
        {
                return address_list;
        }
        else if ((type == 0 || type == 1) &&
                 (start == data || applib_is_valid_url_scheme_char(*(start - 1)) == KAL_FALSE))  /* unknown scheme */
        {
            data = start + strlen(pattern[type]);  /* continue from the end of the pattern */
            len = dataLen - (data - input_data);
            continue;
        }
        else
        {
            end = start + strlen(pattern[type]);

            /* Get the begining of URL string */
            if (type == 0 || type == 1)  /* "://" or ":\\\\" */
            {
                kal_bool is_known_scheme = KAL_FALSE;
                
                /* Check known scheme */
                for(i = 0 ; i < APPLIB_USE_DETAILS_URL_SCHEME_NO; i++)
                {
                    int len = strlen(scheme[i]);
                    if ((start - len) >= input_data)
                    {
                        if (app_strnicmp(start - len, scheme[i], len) == 0)
                        {
                            start -= len;
                            is_known_scheme = KAL_TRUE;
                            break;
                        }
                    }
                }

                /* Unknown scheme */
                if (!is_known_scheme)
                {
                    data = end;  /* continue from the end of the pattern */
                    len = dataLen - (data - input_data);
                    continue;

/*                    while((start - 1 >= data) && applib_is_valid_url_scheme_char(*(start - 1)))
                    {
                        start--;
                    }*/
                }
                ASSERT(start >= data);
            }


            /* Find its end */
            while ((end - data) < len &&  applib_is_valid_url_char(*end) &&(!(app_strnicmp(end, URL_END_1, 2) == 0)) &&(!(app_strnicmp(end, URL_END_2, 1) == 0)))
            {
                if (app_strnicmp(end, URL_PATTERN_2, 3) == 0)  /* for fault tolerance */
                {
                    end += 3;
                }
                else
                {
                    end++;
                }
            }
#if 0
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
#endif				
            if ((end - data) <= len)
            {
                char tmp = *end;
                applib_address_node_struct *address = NULL;
                kal_bool is_duplicated = KAL_FALSE;

                *end = '\0';
			
                {
                    /*Remove invalied characters*/
                    kal_char *end_of_valid_char = end - 1;

                    while (end_of_valid_char > start && 
                           applib_is_valid_url_last_char(*end_of_valid_char) == KAL_FALSE)
                    {
                        end_of_valid_char--;
                    }
                    if (end_of_valid_char > start && end_of_valid_char < end)
                    {
                        end_of_valid_char++;
                        *end = tmp;
                        tmp = *end_of_valid_char;
                        end = end_of_valid_char;
                        *end = '\0';                          
                    }
                }

                if (is_remove_duplicate)
                {
                    address = address_list;
                    while (address != NULL)
                    {
                        if (app_stricmp((kal_char *)(address->data), start) == 0)
                        {
                            is_duplicated = KAL_TRUE;
                            break;
                        }
                        address = address->next;
                    }
                }

                if (is_remove_duplicate == KAL_FALSE || is_duplicated == KAL_FALSE)
                {
                    address = (applib_address_node_struct*)mem_alloc_fn(sizeof(applib_address_node_struct));

	                  if (address == NULL)
    	              {
        	              return address_list;
            	      }

                	  address->data = NULL;
	                  address->dataType = APPLIB_ADDR_TYPE_URL;
    	              address->pos = (kal_uint32)start;
        	          address->length = strlen(start);
            	      address->data = (kal_wchar *)mem_alloc_fn(address->length + 1);

            	      if (address->data == NULL)
            	      {
            	          mem_free_fn(address);
            	          return address_list;
            	      }
				
        	          strcpy((kal_char *)(address->data), start);
        	          address->data2 = NULL;


        	          address->next = address_list;
            	      address_list = address;

                	  parsed_no++;
				
	                  if (check_stop_fn != NULL && 
    	                  check_stop_fn(APPLIB_ADDR_TYPE_URL, address, parsed_no) == KAL_TRUE)
            	      {
            	          *end = tmp;	
            	          *is_stopped = KAL_TRUE;
                    	  return address_list;
	                  }					
                }

                /* continue from the following char */
                *end = tmp;				
                data = end;  
                len = dataLen - (end - input_data);
                continue;
            }
            else
            {
                return address_list;
            }
        }
    }
    return address_list;
}

/*****************************************************************************
 * FUNCTION
 *  applib_parse_url_from_text_unicode
 * DESCRIPTION
 *  This function is used to get specific addresses from one UTF8-encoded text.
 *  The list is in reverse order.
 * PARAMETERS
 *  mem_alloc_fn    [IN]	Memory allication function
 *  mem_free_fn		[IN]	Memory free function
 *  check_stop_fn   [IN]    Check if parsing should be stopped (being invoked when every address is parsed)
 *  input_data		[IN]	Input text data
 *  dataLen       	[IN]	Length of input text data
 *  is_stopped      [IN/OUT]Specify if parsing procedure being stopped by user
 *  is_remove_duplicate [IN] Remove duplicate address or not. 
 * RETURNS
 *  addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_parse_url_from_text_unicode(
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        applib_check_stop_fn check_stop_fn,
        kal_wchar *input_data, 
        kal_int32 dataLen,
        kal_bool *is_stopped,
        kal_bool is_remove_duplicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    int len = 0, parsed_no = 0;
    kal_wchar *data = NULL;
    applib_address_node_struct *address_list = NULL;  
    kal_wchar *pattern[APPLIB_USE_DETAILS_URL_PATTERN_NO] = {URL_UNICODE_PATTERN_1, URL_UNICODE_PATTERN_2, URL_UNICODE_PATTERN_3, URL_UNICODE_PATTERN_4,URL_UNICODE_PATTERN_5,URL_UNICODE_PATTERN_6,URL_UNICODE_PATTERN_7,URL_UNICODE_PATTERN_8,URL_UNICODE_PATTERN_9};
    kal_wchar *scheme[APPLIB_USE_DETAILS_URL_SCHEME_NO] = {URL_UNICODE_SCHEME1, URL_UNICODE_SCHEME2, URL_UNICODE_SCHEME3};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mem_alloc_fn == NULL || 
	 mem_free_fn == NULL || 
	 input_data == NULL || 
	 dataLen == 0 ||
	 *is_stopped == KAL_TRUE)
    {
        return NULL;
    }

    /*UCS2 character number*/
    dataLen = dataLen / 2;
    
    data = (kal_wchar *)input_data;
    len = dataLen;

    while ((data - input_data) < dataLen)
    {
        kal_wchar *start = NULL, *end = NULL;
        int i = 0, type = 0;
        kal_wchar *data_lc = mem_alloc_fn(len*2 + 2);
        if (data_lc == NULL)
        {
            return address_list;
        }

        memset(data_lc, 0x00, len*2 + 2);
        memcpy((char*)data_lc, (char*)data, len*2);
        app_ucs2_strtolower(data_lc);

        for(i = 0 ; i < APPLIB_USE_DETAILS_URL_PATTERN_NO; i++)  /* find the 1st show-up pattern */
        {
            kal_wchar *new_start = NULL;

            new_start = app_ucs2_strstr(data_lc, pattern[i]);
            if (new_start != NULL)
            {
		if((app_ucs2_strnicmp((kal_int8*)(pattern[i]),(kal_int8*)(L"<http:"), 6) == 0) ||(app_ucs2_strnicmp((kal_int8*)(pattern[i]), (kal_int8*)(L"<www."), 5) == 0) ||(app_ucs2_strnicmp((kal_int8*)(pattern[i]),(kal_int8*) (L"<wap."), 5) == 0) ||(app_ucs2_strnicmp((kal_int8*)(pattern[i]),(kal_int8*)( L"<://"), 4) == 0) ||(app_ucs2_strnicmp((kal_int8*)(pattern[i]),(kal_int8*)(L"<:\\\\"), 6) == 0))
				new_start++;
                new_start = data + (int)(new_start - data_lc);
                if (start == NULL)
                {
                    start = new_start;
                    type = i;
                }
                else if((kal_uint32)new_start < (kal_uint32)start)
                {
                    start = new_start;
                    type = i;
                }
            }
        }

        mem_free_fn(data_lc);
        if (start == NULL)  /* not found */
        {
            return address_list;
        }
        else if ((type == 0 || type == 1) &&
            (start == data || applib_is_valid_url_scheme_wchar(*(start - 1)) == KAL_FALSE))  /* unknown scheme */
        {
            data = start + app_ucs2_strlen((kal_int8 *)pattern[type]);  /* continue from the end of the pattern */
            len = dataLen - (data - input_data);
            continue;
        }
        else
        {
            end = start + app_ucs2_strlen((kal_int8*)pattern[type]);

            if (type == 0 || type == 1)  /* "://" or ":\\\\" */
            {
                kal_bool is_known_scheme = KAL_FALSE;

                /* Check known scheme */
                for(i = 0 ; i < APPLIB_USE_DETAILS_URL_SCHEME_NO; i++)
                {
                    int len = app_ucs2_strlen((kal_int8 *)scheme[i]);
					if ((start - len) >= input_data)
                    { 
                        if (app_ucs2_strnicmp((kal_int8*)(start - len), (kal_int8*)scheme[i], len) == 0)
                        {
                            start -= len;
                            is_known_scheme = KAL_TRUE;
                            break;
                        }
                    }
                }

                /* Unknown scheme */
                if (!is_known_scheme)
                {
                    data = end;  /* continue from the end of the pattern */
                    len = dataLen - (data - input_data);
                    continue;

/*                    while((start - 1 >= data) && applib_is_valid_url_scheme_wchar(*(start - 1)))
                    {
                        start--;
                    }*/
                }
                ASSERT(start >= data);
            }

            /* we get the begining of URL string and go to find its end */
            while ((end - data) < len &&  applib_is_valid_url_wchar(*end) && (!(app_ucs2_strnicmp((kal_int8 *)end, (kal_int8 *)URL_END_PATTERN_1, 2) == 0)) &&(!(app_ucs2_strnicmp((kal_int8 *)end, (kal_int8 *)URL_END_PATTERN_2, 1) == 0)))
            {
                if (app_ucs2_strnicmp((kal_int8 *)end, (kal_int8 *)URL_UNICODE_PATTERN_2, 3) == 0)  /* for fault tolerance */
                {
                    end += 3;
                }
                else
                {
                    end++;
                }
            }
#if 0
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
#endif
            if ((end - data) <= len)
            {
                kal_wchar tmp = *end;
                applib_address_node_struct *address = NULL;
                kal_bool is_duplicated = KAL_FALSE;
                
                *end = L'\0';

                {
                    /*Remove invalied characters*/
                    kal_wchar *end_of_valid_char = end - 1;

                    while (end_of_valid_char > start && 
                           applib_is_valid_url_last_wchar(*end_of_valid_char) == KAL_FALSE)
                    {
                        end_of_valid_char--;
                    }
                    if (end_of_valid_char > start && end_of_valid_char < end)
                    {
                        end_of_valid_char++;
                        *end = tmp;
                        tmp = *end_of_valid_char;
                        end = end_of_valid_char;
                        *end = L'\0';
                    }
                }
				
                if (is_remove_duplicate)
                {
                    address = address_list;
                    while (address != NULL)
                    {
                        if (app_ucs2_wcsicmp((kal_wchar*)address->data, (kal_wchar*)start) == 0)
                        {
                            is_duplicated = KAL_TRUE;
                            break;
                        }
                        address = address->next;
                    }
                }

                if (is_remove_duplicate == KAL_FALSE || is_duplicated == KAL_FALSE)
                {
                    address = (applib_address_node_struct*)mem_alloc_fn(sizeof(applib_address_node_struct));
                    if (address == NULL)
                    {
                        return address_list;
                    }
                    address->data = NULL;
                    address->dataType = APPLIB_ADDR_TYPE_URL;
                    address->pos = (kal_uint32)start;
                    address->length = app_ucs2_strlen((kal_int8 *)start)*2;
                    address->data = (kal_wchar *)mem_alloc_fn(address->length + 2);
                    if (address->data == NULL)
                    {
                        mem_free_fn(address);
                        return address_list;
                    }
                    app_ucs2_strcpy((kal_int8 *)(address->data), (kal_int8 *)start);
                    address->data2 = NULL;

                    address->next = address_list;
                    address_list = address;

                    parsed_no++;
                    if (check_stop_fn != NULL && 
          	            check_stop_fn(APPLIB_ADDR_TYPE_URL, address, parsed_no) == KAL_TRUE)
                    {
                        *end = tmp;
                        *is_stopped = KAL_TRUE;
                        return address_list;
                    }                   
                }
				
                /* continue from the following char */
                *end = tmp;
                data = end;  
                len = dataLen - (end - input_data);
                continue;
            }
            else
            {
                return address_list;
            }
        }
    }
    return address_list;
}

#endif /* BROWSER_SUPPORT */
static int is_number (const char *sz, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (len <= 0)
    {
        return 0;
    }
    
    for (i = 0; i < len; i++, sz++)
    {
        if (!is_digit (*sz))
        {
            return 0;
        }
    }

    return 1;
}


static const char *strnchr(const char *sz, char ch, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sz || len == 0)
    {
        return 0;
    }

    for(i = 0; i < len; i++)
    {
        if(sz[i] == ch)
        {
            return sz + i;
        }
    }
    return 0;
}


static url_scheme_type_enum applib_url_get_scheme_to_type(const char *url, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!url || len == 0)
    {
        return applib_scheme_empty;
    }

    for(i = 0; i < APPLIB_NBR_OF_SUPPORTED_SCHEMES; i++)
    {
        if((_strncasecmp(url, supported_schemes[i].leading_string, len) == 0) && (strlen(supported_schemes[i].leading_string)==len))
        {
            return (url_scheme_type_enum)supported_schemes[i].scheme_type;
        }
    }

    return applib_scheme_unknown;
}


/*****************************************************************************
 * FUNCTION
 *  applib_url_check_ip
 * DESCRIPTION
 *  This function check whether address is in the form of IP address,
 *  if so, validate the IP address with the valid IP range.
 * PARAMETERS
 *  url          [IN]
 *  len          [IN]
 * RETURNS
 *  1 if p is a valid address
 *****************************************************************************/
int applib_url_check_ip(const char *addr, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, count;
    int ip_addr[4] = {0};
    const char *p = addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* hostnumber     = digits "." digits "." digits "." digits */

    for (i = 0, count = 0; i < len; i++)
    {
		if (!is_digit(addr[i]))
		{
			if (addr[i] != '.')
			{
				return 0;
			}
			else
			{
				if (i == 0 || i + 1 == len)
            	{
                	return 0;
            	}

				if (addr[i-1] == '.')
				{
					return 0;
				}

				ip_addr[count] = atoi(p);

            	if (ip_addr[count] < 0 || ip_addr[count] > 255)
				{
					return 0;
				} 

				p = addr + i + 1;
				count++;

				if (count == 4)
				{
					return 0;
				}
			}
		}
    }

    ip_addr[count] = atoi(p);

    if(ip_addr[count] < 0 || ip_addr[count] > 255)
    {
        return 0;
    }

    if (count != 3 || (ip_addr[0] == 0 && ip_addr[1] == 0 && ip_addr[2] == 0 && ip_addr[3] == 0))
    {
        return 0;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  applib_url_check_domain_label
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url          [IN]
 *  len          [IN]
 * RETURNS
 *  1 if success
 *****************************************************************************/
static int applib_url_check_top_label(const char *p, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* toplabel       = alpha | alpha *[ alphadigit | "-" ] alphadigit */

    if(!is_alpha(p[0]))
    {
        return 0;
    }
    
    if(len == 1)
    {
        return 1;
    }

    for(i = 0; i < len - 1; i++)
    {
        if(!is_alphadigit(p[i]) && (p[i] != '-'))
        {
            return 0;
        }
    }
    return is_alphadigit(p[i]);
}

/*****************************************************************************
 * FUNCTION
 *  applib_url_check_domain_label
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url         [IN]
 *  st          [OUT]
 * RETURNS
 *  1 if success
 *****************************************************************************/
static int applib_url_check_domain_label(const char *p, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* domainlabel    = alphadigit | alphadigit *[ alphadigit | "-" ] alphadigit */

    if(!is_alphadigit(p[0]))
    {
        return 0;
    }
        
    if(len == 1)
    {
        return 1;
    }

    for(i = 1; i < len - 1; i++)
    {
        if(!is_alphadigit(p[i]) && (p[i] != '_') && (p[i] != '-'))
        {
            return 0;
        }
    }

    return is_alphadigit(p[i]);
}


/*****************************************************************************
 * FUNCTION
 *  applib_url_check_scheme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url         [IN]
 *  st          [OUT]
 * RETURNS
 *  0 if success
 *****************************************************************************/
int applib_url_check_scheme(applib_url_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, len;
    const char *scheme;
    char ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* scheme        = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." ) */
    
    scheme = p->parts[APPLIB_URL_SCHEME_PART];
    len = p->len[APPLIB_URL_SCHEME_PART];
    
    /* Scheme cannot be empty */
    if(!scheme || len == 0)
    {
        return APPLIB_URL_ERR_INVALID_SCHEME;
    }

    if(!is_alpha(*scheme))
    {
        return APPLIB_URL_ERR_INVALID_SCHEME;
    }

    for(i = 0; i < len; i++)
    {
        ch = scheme[i];
        if(!is_alphadigit(ch) && (ch != '+') && (ch != '-') && (ch != '.'))
        {
            return APPLIB_URL_ERR_INVALID_SCHEME;
        }
    }
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  applib_url_check_host
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url         [IN]
 *  st          [OUT]
 * RETURNS
 *  0 if success
 *****************************************************************************/
int applib_url_check_host(applib_url_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char *host;
    int i, k, len;
    char ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    host = p->parts[APPLIB_URL_HOST_PART];
    len = p->len[APPLIB_URL_HOST_PART];

    if (host == NULL || len == 0)
    {
        return APPLIB_URL_ERR_INVALID_HOST;
    }

	/* host = hostname | IPV4address
	 * hostname = *(domainlabel ".") toplabel ["."]
     */

    /* ignore the last '.' */	
    if (host[len - 1] == '.')
    {
        len--;
    }

    /* find the rightmost '.' */
    for (i = len - 1; i > 0 && host[i] != '.'; i--);


    if (i == 0)
    {
		/* host = toplabel */
        if (!applib_url_check_top_label(host, len))
        {
            return APPLIB_URL_ERR_INVALID_HOST;
        }
    }
    else if (is_digit(host[i + 1]))
    {
		/* host = IPV4address */
        if (!applib_url_check_ip(host, len))
        {
            return APPLIB_URL_ERR_INVALID_HOST;
        }
    }
    else
    {
	 	/* host = *(domainlabel ".") toplabel */

        for (i = 0, k = 0; k < len; k++)
        {
            ch = host[k];
            if (ch == '.')
            {
                if(!applib_url_check_domain_label(host + i, k - i))
                    return APPLIB_URL_ERR_INVALID_HOST;
                i = k + 1;
            }
        }
        if (!applib_url_check_top_label(host + i, k - i))
        {
            return APPLIB_URL_ERR_INVALID_HOST;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  applib_url_check_port
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url         [IN]
 *  st          [OUT]
 * RETURNS
 *  0 if success
 *****************************************************************************/
int applib_url_check_port(applib_url_struct *p)
{
    char port[6] = "";
    int i;

    strncpy(port, p->parts[APPLIB_URL_PORT_PART], (p->len[APPLIB_URL_PORT_PART] < 5) ? p->len[APPLIB_URL_PORT_PART] : 5);

    if (p->parts[APPLIB_URL_PORT_PART] == NULL)
    {
        return 0;
    }

    if (p->len[APPLIB_URL_PORT_PART] == 0 || p->len[APPLIB_URL_PORT_PART] > 5)
    {
        return APPLIB_URL_ERR_INVALID_PORT;
    }

    for (i = 0; i < p->len[APPLIB_URL_PORT_PART]; i++)
    {
        if (!is_digit(port[i]))
        {
            return APPLIB_URL_ERR_INVALID_PORT;
        }
    }

    if(atoi(port) < 0 || atoi(port) > 65535)
    {
        return APPLIB_URL_ERR_INVALID_PORT;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  app_parse_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url         [IN]
 *  st          [OUT]
 * RETURNS
 *  0 if success
 *****************************************************************************/
int applib_parse_url(const char *url, applib_url_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char *next, *iter;
    char ch = 0;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Basecase check */    
    if(!url || !p)
    {
        return -1;
    }

    /* Clear the structure first */
    {
        p->scheme_type = applib_scheme_empty;
        for(i = 0; i < APPLIB_URL_NUM_PARTS; i++)
        {
            p->parts[i] = NULL;
            p->len[i] = 0;
        }
    }
    
    next = url; /* start from the beginning of the URL */

    /* URI           = scheme ":" hier-part [ "?" query ] [ "#" fragment ] */

    /* Extract the scheme part */
    for(iter = next; *iter; iter++)
    {
        ch = *iter;
        if ((ch == ':') || (ch == '/') || (ch == '?') || (ch == '#'))
        {
            break;
        }
    }

    if(ch == ':')
    {
        p->parts[APPLIB_URL_SCHEME_PART] = next;
        p->len[APPLIB_URL_SCHEME_PART] = iter - next;
        next = iter + 1;
        p->scheme_type = applib_url_get_scheme_to_type(p->parts[APPLIB_URL_SCHEME_PART], p->len[APPLIB_URL_SCHEME_PART]);
    }

    if (p->scheme_type == applib_scheme_empty)
    {
        goto userinfo;
	}

    /* Parse autority part
       authority     = [ userinfo "@" ] host [ ":" port ] */
    if(!((next[0] == '/') && (next[1] == '/')))
    {
        goto path; /* No authority part */
    }

    /* Skip "//" */
    next += 2;

userinfo:
    /* Extract userinfo part */
    for(iter = next; *iter; iter++)
    {
        ch = *iter;
        if (ch == '@' || ch == '/')
        {
            break;
        }
    }

    if(ch == '@')
    {
        p->parts[APPLIB_URL_USERINFO_PART] = next;
        p->len[APPLIB_URL_USERINFO_PART] = iter - next;
        next = iter + 1;
    }

    /* Extract host part */
    for(iter = next; *iter; iter++)
    {
        ch = *iter;
        if ((ch == ':') || (ch == '/') || (ch == '#'))
        {
            break;
        }
    }

    p->parts[APPLIB_URL_HOST_PART] = next;
    p->len[APPLIB_URL_HOST_PART] = iter - next;

    /* Reach the end of string */
    if(*iter == 0)
    {
        goto end;
    }
    
    next = iter + 1;

    if(ch == '/')
    {
        /* There is no port part */
        goto path;
    }

    if(ch == '#')
    {
        goto fragment;
    }
    
    if(ch == ':')
    {
        /* Extract port part */
        for(iter = next; *iter; iter++)
        {
            ch = *iter;
            if (ch == '/')
            {
                break;
            }
        }

        p->parts[APPLIB_URL_PORT_PART] = next;
        p->len[APPLIB_URL_PORT_PART] = iter - next;

        if(ch == '/')
        {
            next = iter + 1;
        }
        else /* Reach the end of URL */
        {
            goto end;
        }
    }

path:
    /* Extract path part */
    for(iter = next; *iter; iter++)
    {
        ch = *iter;
        if((ch == '?') || (ch == '#'))
        {
            break;
        }
    }
    
    p->parts[APPLIB_URL_PATH_PART] = next;
    p->len[APPLIB_URL_PATH_PART] = iter - next;

    if ((p->parts[APPLIB_URL_SCHEME_PART] != NULL) &&
        (p->scheme_type != applib_scheme_http) &&
        (p->scheme_type != applib_scheme_https))
    {
        const char *s = strnchr (p->parts[APPLIB_URL_PATH_PART], '/', p->len[APPLIB_URL_PATH_PART]);
        int plen = (s != NULL) ? (s - p->parts[APPLIB_URL_PATH_PART]) : p->len[APPLIB_URL_PATH_PART];

        if ((strnchr (p->parts[APPLIB_URL_SCHEME_PART], '.', p->len[APPLIB_URL_SCHEME_PART]) != NULL) &&
            (p->parts[APPLIB_URL_PATH_PART] != NULL) && (plen > 0) &&
            is_number (p->parts[APPLIB_URL_PATH_PART], plen))
        {
            iter = next = url;        
            p->scheme_type = applib_scheme_empty;
            p->parts[APPLIB_URL_SCHEME_PART] = NULL;
            p->len[APPLIB_URL_SCHEME_PART] = 0;
            goto userinfo;
        }
    }

    /* Check if the URL has no scheme and has port number specified, eg: www.yahoo.com:80 */
    for(i = 0; i < p->len[APPLIB_URL_SCHEME_PART]; i++)
    {
        if(p->parts[APPLIB_URL_SCHEME_PART][i] == '.')
        {
            /* . is found in scheme, check if path is actually a port number */
            for(i = 0; i < p->len[APPLIB_URL_PATH_PART]; i++)
            {
                if(p->parts[APPLIB_URL_PATH_PART][i] < '0' || p->parts[APPLIB_URL_PATH_PART][i] > '9')
                {
                    /* Not a port number */
                    goto query;
                }
            }

            /* pattern found, restart from userinfo */
            p->parts[APPLIB_URL_SCHEME_PART] = NULL;
            p->len[APPLIB_URL_SCHEME_PART] = 0;
            next = url;
            p->scheme_type = applib_scheme_empty;
            
            goto userinfo;
        }
    }

query:    
    if((ch == '?') || (ch == '#'))
    {
        next = iter + 1;
    }
    else
    {
        goto end;
    }

    if(ch == '#')
    {
        /* There is no query part */
        goto fragment;
    }

    /* Extract query part */
    if(ch == '?')
    {
        for(iter = next; *iter; iter++)
        {
            ch = *iter;
            if (ch == '#')
              break;
        }

        p->parts[APPLIB_URL_QUERY_PART] = next;
        p->len[APPLIB_URL_QUERY_PART] = iter - next;
        if(ch == '#')
        {            
            next = iter + 1;
        }
        else
        {
            goto end;
        }
    }        

fragment:
    for(iter = next; *iter; iter++);
    p->parts[APPLIB_URL_FRAGMENT_PART] = next;
    p->len[APPLIB_URL_FRAGMENT_PART] = iter - next;

end:
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  applib_url_is_valid
 * DESCRIPTION
 *  To check if a URL is valid or not. Empty or unknown scheme is not allowed.
 * PARAMETERS
 *  url         [IN]
 * RETURNS
 *  0 if success
 *****************************************************************************/
int applib_url_is_valid(const char *url)
{
    applib_url_struct st;
	const char *temp_url=url;
    int ret;


	while(*temp_url)
	{
    if(applib_is_valid_url_char(*temp_url))
       temp_url++;
	else
	{  ret=-1;
	   return ret;
	}
	}
    ret = applib_parse_url(url, &st);
    if(ret < 0)
    {
        return ret;
    }

    ret = applib_url_check_scheme(&st);
    if(ret < 0)
    {
        return ret;
    }

    if(st.scheme_type == applib_scheme_unknown)
    {
        return APPLIB_URL_ERR_INVALID_SCHEME;
    }

    ret = applib_url_check_host(&st);
    if(ret < 0)
    {
        return ret;
    }

    ret = applib_url_check_port(&st);
    if(ret < 0)
    {
        return ret;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  applib_url_is_valid_ext
 * DESCRIPTION
 *  To check if a URL is valid or not based on allow_empty_scheme and allow_empty_scheme.
 * PARAMETERS
 *  url                   [IN]
 *  allow_empty_scheme    [IN]: Empty scheme is allowed or not.
 *  allow_unknown_scheme  [IN]: Scheme except for HTTP, HTTPS, FILE, WTAI, RTSP, TEL,
 *                              MAILTO, SMS, SMSTO, MMS, and MMSTO is alloed or not.
 * RETURNS
 *  0 if success
 *****************************************************************************/
int applib_url_is_valid_ext(const char *url, kal_bool allow_empty_scheme, kal_bool allow_unknown_scheme)
{
    applib_url_struct st;
    int ret;

    ret = applib_parse_url(url, &st);

    if(ret < 0)
    {
        return ret;
    }

    if (allow_empty_scheme == KAL_FALSE && st.scheme_type == applib_scheme_empty)
    {
        /* The URL has no scheme part. */
        return APPLIB_URL_ERR_INVALID_SCHEME;
    }

    if (allow_unknown_scheme == KAL_FALSE && st.scheme_type == applib_scheme_unknown)
    {
        /* Scheme is not HTTP, HTTPS, FILE, WTAI, RTSP, TEL, MAILTO, SMS, SMSTO, MMS, or MMSTO. */
        return APPLIB_URL_ERR_INVALID_SCHEME;
    }

    /* Check the validity of scheme if this URL has scheme part. */
    if (st.scheme_type != applib_scheme_empty)
    {       
        ret = applib_url_check_scheme(&st);

        if(ret < 0)
        {
            /* The syntax of scheme is invalid. */
            return ret;
        }
    }

    /* Check the validity of host part. */
    ret = applib_url_check_host(&st);
    if(ret < 0)
    {
        return ret;
    }

    /* Check the validity of port part. */
    ret = applib_url_check_port(&st);
    if(ret < 0)
    {
        return ret;
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  applib_cvt_escape_string_to_normal_string
 * DESCRIPTION
 *  This function is used to convert escape string to strings.
 * PARAMETERS
 *  input      [IN]        Pointer to escape string
 *  input_len  [IN]        Length of escape string
 *  output     [IN]        Pointer to output string
 *  output_len [IN]        Length of output string 
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool applib_cvt_escape_string_to_normal_string(kal_char *input, kal_int32 input_len, kal_char *output, kal_int32 output_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *s_wr = output;
    kal_char *s_rd = input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input == NULL || input_len == 0 || output == NULL || output_len == 0)
    {
        return KAL_FALSE;
    }
    while (input_len && output_len)
    {
        if (*s_rd != '%')
        {
            *s_wr = *s_rd;
            s_wr++;
            s_rd++;
            input_len--;
            output_len--;
        }
        else
        {
            if (input_len >= 3) /* The pattern shall be like %2b */
            {
                kal_char s_rd_1 = *(s_rd + 1);
                kal_char s_rd_2 = *(s_rd + 2);                

                if (((s_rd_1 >= '0' && s_rd_1 <= '9') || (s_rd_1 >= 'A' && s_rd_1 <= 'F') || (s_rd_1 >= 'a' && s_rd_1 <= 'f')) &&
                    ((s_rd_2 >= '0' && s_rd_2 <= '9') || (s_rd_2 >= 'A' && s_rd_2 <= 'F') || (s_rd_2 >= 'a' && s_rd_2 <= 'f')))                                  
                {
                    kal_char bak = *(s_rd + 3);
                    *(s_rd + 3) = '\0';
                    
                    s_rd++;                    
                    *s_wr = (kal_char) strtol(s_rd, NULL, 16); /*Convert Hex (ex:0x2b) to Dec (43) */
                    s_rd += 2;
                    *s_rd = bak;
                    s_wr++;
                    input_len -= 3;
                    output_len--;
                }
                else
                {
                    *s_wr = *s_rd;
                    s_wr++;
                    s_rd++;
                    input_len--;
                    output_len--;
                }
            }
            else
            {
              *s_wr = *s_rd;
              s_wr++;
              s_rd++;
              input_len--;
              output_len--;
            }
        }
    }
    if (output_len > 0)
    {
        *s_wr = '\0';
    }
    if (input_len == 0)
    {
        return KAL_TRUE;
    }
    else
    {
        /*Output buffer is not enough*/
        return KAL_FALSE;
    }   
}

/*****************************************************************************
 * FUNCTION
 *  applib_cvt_normal_string_to_escape_string
 * DESCRIPTION
 *  This function is used to convert string to escape strings.
 * PARAMETERS
 *  input      [IN]        Pointer to escape string
 *  input_len  [IN]        Length of escape string
 *  special_chars_arry [IN] The array contains some ASCII characters shall be converted to escape_string
 *  special_chars_arry_len [IN]The length of special_chars_arry
 *  output     [IN]        Pointer to output string
 *  output_len [IN]        Length of output string 
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool applib_cvt_normal_string_to_escape_string(kal_char *input, kal_int32 input_len, kal_char *special_chars_arry, kal_uint32 special_chars_arry_len, kal_char *output, kal_int32 output_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *s_wr = output;
    kal_char *s_rd = input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input == NULL || input_len == 0 || 
        output == NULL || output_len == 0 || 
        (special_chars_arry != NULL && special_chars_arry_len == 0))
    {
        return KAL_FALSE;
    }
    memset(output,0x00,output_len);
    while (input_len && output_len)
    {
        if (((kal_uint8)*s_rd) >= 0x20 && ((kal_uint8)*s_rd) <= 0x7E)
        {
            if (special_chars_arry != NULL)
            {
                kal_uint32 i = 0;
                for (i = 0; i < special_chars_arry_len; i++)
                {
                    if (*s_rd == special_chars_arry[i])
                    {
                        goto convert_escape_char;
                    }
                }
            }
            *s_wr = *s_rd;
            s_wr++;
            s_rd++;
            input_len--;
            output_len--;            
        }
        else
        {
convert_escape_char:
            if (output_len >= 4) /* four bytes, '%''2''b' + NULL terminator */
            {
                sprintf(s_wr, "%c%2x", '%', *s_rd);
                s_wr = s_wr + 3;
                s_rd++;
                input_len--;
                output_len -= 3;
            }
            else
            {
                return KAL_FALSE;
            }
        }
    }        
    if (output_len > 0)
    {
        *s_wr = '\0';
    }
    if (input_len == 0)
    {
        return KAL_TRUE;
    }
    else
    {
        /*Output buffer is not enough*/
        return KAL_FALSE;
    }
}


