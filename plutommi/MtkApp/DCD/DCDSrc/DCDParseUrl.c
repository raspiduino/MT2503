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
*  DCDParseUrl.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   DCD get url from sl 
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
*******************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OP01_DCD__
#include "wbxmlp.h"
#include "wbxmlp_def.h"
#include "xml_def.h"
#include "app_buff_alloc.h"
#include "DCDProt.h"
#include "kal_general_types.h"
#include "string.h"
#include "kal_release.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static kal_char * g_sl_url_p;
static kal_char * g_sl_action_p; 

static void dcd_xml_start_elem_hdlr(void *data, const kal_char*el, const kal_char**attr, kal_int32 error);
static void dcd_xml_end_elem_hdlr(void *data, const kal_char*el, kal_int32 error);
static void dcd_xml_data_hdlr( void *data, const kal_char*el, const kal_char*value, kal_int32 len, kal_int32 error);

static kal_int32 dcd_get_tagname_by_token(kal_char *ptr, kal_uint32 tagcp, kal_uint8 token);
static kal_int32 dcd_get_attrname_by_token(kal_char *ptr, kal_char *prefix, kal_uint32 attrcp, kal_uint8 token);
static void dcd_wbxml_stag_hdlr(void * resv, const kal_char  *tagname, const kal_char **attrlist);


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_attr_from_sl
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 *  filename        [IN]        File name of wap push sl
 *  url             [IN]        [out]       buf to save url
 *  action          [IN]        [out]       buf to save action
 * RETURNS
 *  if < 0: failed
 *****************************************************************************/
int mmi_dcd_get_attr_from_sl(const kal_wchar  * filename, 
						   kal_char ** url,  kal_char ** action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	XML_PARSER_STRUCT parser;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sl_url_p = NULL;
    g_sl_action_p = NULL;

	xml_new_parser (&parser);

    /* xml_configure_memory (&parser, get_ctrl_buffer, free_ctrl_buffer); */

    xml_register_element_handler(&parser, dcd_xml_start_elem_hdlr, dcd_xml_end_elem_hdlr);

	xml_register_data_handler(&parser, dcd_xml_data_hdlr);

	xml_parse(&parser, (kal_wchar*)filename);

	xml_close_parser(&parser);

    if (url)
    {
	    *url = g_sl_url_p;
    }
    if (action)
    {
	    *action = g_sl_action_p;
    }
    /* no need to free, caller will free it */

	return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dcd_xml_start_elem_hdlr
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 * data        [IN]        Reserved
 * el          [IN]        Element name string
 * attr        [IN]        Attribute list
 *  error       [IN]        [out]       Error code
 * RETURNS   
 *  if < 0: failed(?)
 *****************************************************************************/
static void dcd_xml_start_elem_hdlr(void *data, const kal_char*el, const kal_char**attr, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int i;
	int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( mmi_dcd_stricmp(el, "sl") == 0)
	{
		i = 0;
		while ( attr[i] != NULL)
		{
			if ( mmi_dcd_stricmp(attr[i], "href") == 0)
			{
				i++;
				len  = strlen(attr[i]);
				g_sl_url_p = get_ctrl_buffer(len+1);
				strcpy(g_sl_url_p, attr[i]);
			}
			else if ( mmi_dcd_stricmp(attr[i], "action") == 0)
			{
				i++;
				len  = strlen(attr[i]);
				g_sl_action_p = get_ctrl_buffer(len+1);
				strcpy(g_sl_action_p, attr[i]);
			}
			i++;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  dcd_xml_end_elem_hdlr
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 * data        [IN]        Reserved
 * el          [IN]        Element name string
 *  error       [IN]        [out]       Error code
 * RETURNS   
 *  if < 0: failed(?)
 *****************************************************************************/
static void dcd_xml_end_elem_hdlr(void *data, const kal_char*el, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  dcd_xml_data_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  el          [IN]        
 *  value       [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void dcd_xml_data_hdlr( void *data, const kal_char*el, const kal_char*value, kal_int32 len, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/************************************************************************************
 * the following code is for parsing slc
*************************************************************************************/

typedef struct tagTAGTOKEN
{
    char *	tag_name;
    int		token;
}TAGTOKEN;

typedef struct tagATTRSTARTTOKEN
{
    char*	name;
    char*	prefix;
    int		token;
}ATTRSTARTTOKEN;

typedef struct tagATTRVALUETOKEN
{
    char*	value;
    int		token;
}ATTRVALUETOKEN;

const static TAGTOKEN tag_tokens_slc[]=
{
    { "sl", 0x05 }
};

const static ATTRSTARTTOKEN attrstart_tokens_slc[] = 
{
	{ "action",		"execute-low",		0x05 },
	{ "action",		"execute-high",		0x06 },
	{ "action",		"cache",			0x07 },
	{ "href",		NULL,				0x08 },
	{ "href",		"http://",			0x09 },
	{ "href",		"http://www.",		0x0A },
	{ "href",		"https://",			0x0B },
	{ "href",		"https://www.",		0x0C }
};

const ATTRVALUETOKEN attrvalue_tokens_slc[]=
{
    /* attributes value tokens */
    { ".com/", 0x85 },
    { ".edu/", 0x86 },
    { ".net/", 0x87 },
    { ".org/", 0x88 }
};


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_attr_from_slc
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 *  filename        [IN]        File name of wap push slc
 *  url             [IN]        [out]       buf to save url
 *  action          [IN]        [out]       buf to save action
 * RETURNS
 *  if < 0: failed
 *****************************************************************************/
int mmi_dcd_get_attr_from_slc(const kal_wchar  * filename, 
						   kal_char ** url,  kal_char ** action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    kal_char *err_tag;
    WP_HANDLE hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sl_url_p = NULL;
    g_sl_action_p = NULL;

    if ((hd = wbxml_new_parser()) == -1)
    {
        return -1;
    }
    wbxml_register_header_handler(hd, NULL);
    wbxml_register_data_handler (hd, NULL);
    wbxml_register_element_handler (hd, dcd_wbxml_stag_hdlr, NULL);
    wbxml_register_get_name_handler(hd, dcd_get_tagname_by_token, dcd_get_attrname_by_token);

    ret = wbxml_parse(hd, (char*)filename, 0);
    if (ret < 0)
    {
        err_tag = wbxml_get_error_tag(hd);
    }
    wbxml_close_parser(hd); 

    if (url)
    {
	    *url = g_sl_url_p;
    }
    if (action)
    {
	    *action = g_sl_action_p;
    }
    /* no need to free, caller will free it */
	return 1;
}


/*****************************************************************************
 * FUNCTION
 *  dcd_get_tagname_by_token
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 *  ptr         [IN]        Buf to save tag name
 *  tagcp       [IN]        Tag space code page
 *  token       [IN]        Token of tag
 * RETURNS
 *  if < 0: failed
 *****************************************************************************/
static kal_int32 dcd_get_tagname_by_token(kal_char *ptr, kal_uint32 tagcp, kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len, index=0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(1)
    {
        if (tag_tokens_slc[index].tag_name == NULL)
        {
            ASSERT(tag_tokens_slc[index].tag_name != NULL);
            return 0; /* cannot find token in tag token space */
        }
        if (tag_tokens_slc[index].token == token)
        {
            len = strlen(tag_tokens_slc[index].tag_name);
            if (len < WBXML_MAX_BUFFER_SIZE)
            {
                strcpy(ptr, tag_tokens_slc[index].tag_name);
                return len;
            }
            else    /* len is over 2k */
            {
                ASSERT(len < WBXML_MAX_BUFFER_SIZE);
                return -1;
            }
        }
        index++;
    }
     return 0;
}


/*****************************************************************************
 * FUNCTION
 *  dcd_get_attrname_by_token
 * DESCRIPTION
 *  this function is used to get attrname by token 
 * PARAMETERS
 *  ptr         [IN]        Buf to save attribute name or attribute value
 *  prefix      [IN]        Buf to save attribute value prefix if prefix is exsit in attrstart
 *  attrcp      [IN]        Attribute code page
 *  token       [IN]        Token of attrstart or attrvalue
 * RETURNS
 *  if < 0, failed
 *****************************************************************************/
static kal_int32 dcd_get_attrname_by_token(kal_char *ptr, kal_char *prefix, kal_uint32 attrcp, kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len1, len2, index=0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (token < 128) /* attrstart token */
    {
        while(1)
        {
            if (attrstart_tokens_slc[index].name == NULL)
            {
                ASSERT(attrstart_tokens_slc[index].name != NULL);
                return 0; /* cannot find token in tag token space */
            }
            if (attrstart_tokens_slc[index].token == token)
            {/* find token in token space */
                if ((len1 = strlen(attrstart_tokens_slc[index].name)) < WBXML_MAX_BUFFER_SIZE)
                {
                    strcpy(ptr, attrstart_tokens_slc[index].name);
                }
                if (attrstart_tokens_slc[index].prefix != NULL)
                {/* prefix is not NULL, copy it to attrvalue */
                    if ((len2 = strlen(attrstart_tokens_slc[index].prefix))<WBXML_MAX_BUFFER_SIZE)
                    {
                        strcpy(prefix, attrstart_tokens_slc[index].prefix);
                    }
                }
                if (len1 < WBXML_MAX_BUFFER_SIZE)
                {
                    return len1;
                }
                else    /* len is over 2k */
                {
                    ASSERT(len1 < WBXML_MAX_BUFFER_SIZE);
                    return -1;
                }
            }
            index++;
        }
    }
    else            /* attrvalue token */
    {
        while(1)
        {
            if (attrvalue_tokens_slc[index].value == NULL)
            {
                ASSERT(attrvalue_tokens_slc[index].value != NULL);
                return 0; /* cannot find token in tag token space */
            }
            if (attrvalue_tokens_slc[index].token == token)
            {
                len2 = strlen(attrvalue_tokens_slc[index].value);
                if (len2 < WBXML_MAX_BUFFER_SIZE)
                {
                    strcpy(ptr, attrvalue_tokens_slc[index].value);
                    return len2;
                }
                else    /* len is over 2k */
                {
                    ASSERT(len2 < WBXML_MAX_BUFFER_SIZE);
                    return -1;
                }
            }
            index++;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  dcd_wbxml_stag_hdlr
 * DESCRIPTION
 *  this function is used to get attrname by token 
 * PARAMETERS
 *  resv          [IN]        Reserved
 *  tagname       [IN]        Element name string
 *  attr          [IN]        Attribute list
 * RETURNS
 *  void
 *****************************************************************************/
static void dcd_wbxml_stag_hdlr(void * resv, const kal_char  *tagname, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int i;
	int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( mmi_dcd_stricmp(tagname, "sl") == 0)
	{
		i = 0;
		while ( attr[i] != NULL)
		{
			if ( mmi_dcd_stricmp(attr[i], "href") == 0)
			{
				i++;
				len  = strlen(attr[i]);
				g_sl_url_p = get_ctrl_buffer(len+1);
				strcpy(g_sl_url_p, attr[i]);
			}
			else if ( mmi_dcd_stricmp(attr[i], "action") == 0)
			{
				i++;
				len  = strlen(attr[i]);
				g_sl_action_p = get_ctrl_buffer(len+1);
				strcpy(g_sl_action_p, attr[i]);
			}
			i++;
		}
	}
}
#endif /* __MMI_OP01_DCD__*/

