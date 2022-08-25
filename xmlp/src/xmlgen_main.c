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
 *  xmlgen_main.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  xml generator file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __XML_SUPPORT__

#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include "kal_release.h"        /* Basic data type */
//#include "App_buff_alloc.h"

#include "fs_type.h"
//#include "fat_fs.h"

#include "xml_def.h"
#include "xmlgen.h"
#include "xmlgen_def.h"

#include "fs_func.h"
#include "fs_errcode.h"
#include "xmlgen_common.h"

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_internal_api.h"

#define XML_EQUAL   "="
#define xml_generate_get_buffer     get_ctrl_buffer
#define xml_generate_free_buffer    free_ctrl_buffer
#define XML_MAX_READ_BUF_LENGTH  384
#define NAME_LENGTH    32
#define TEMP_BUF_LEN 128
static xml_generator_struct xg_array[XG_MAX_HANDLE_NUM];

static kal_int32 xml_generate_push_tagstack(xml_generator_struct *p, const kal_char *tagname);
static void xml_generate_pop_tagstack(xml_generator_struct *p);
static kal_int32 xml_generate_flash_text(kal_int8 hd, kal_char *text, kal_uint32 textlen);

#define NUM_NAMED_CHAR 5
#define MAX_STRING_LEN 6
const named_char_entry_struct xml_gen_named_char_table[NUM_NAMED_CHAR] = 
{
    {"&lt;", '<'},
    {"&gt;", '>'},
    {"&amp;", '&'},
    {"&apos;", '\''},
    {"&quot;", '\"'}
};

/*****************************************************************************
 * FUNCTION
 *  ml_generate_convert_named_char
 * DESCRIPTION
 *  this function is used to write data from file to buffer
 * PARAMETERS
 *  q      
 *  dest       [IN]    src file handle  
 *  len         [IN]    actual length to be written
 * RETURNS
 *      <0 : means failed, returns error code;
 *      >0 :  means succeed
 *****************************************************************************/

kal_uint32  xml_generate_convert_named_char(xml_generator_struct *q, char **dest, kal_uint32 len)
{
    char  p;
    kal_uint32 convertlen, tempdatalen;
    kal_uint8 i;
    

    q->convertlen = 0;
    convertlen = 0;
    tempdatalen = 0;
    while((convertlen < len) && (tempdatalen <= (CONVERT_BUF_SIZE - MAX_STRING_LEN)))
    {   
        p = *(*dest + convertlen);
        for (i = 0; i < NUM_NAMED_CHAR; i++)
        {
            if (p == xml_gen_named_char_table[i].named_ch)
            {
                memcpy(q->convertbuf + tempdatalen, xml_gen_named_char_table[i].named_string, strlen(xml_gen_named_char_table[i].named_string));
                tempdatalen += strlen(xml_gen_named_char_table[i].named_string);
                break;
            }
        }

        if (i == NUM_NAMED_CHAR)
        {
            q->convertbuf[tempdatalen] = p;
            tempdatalen ++;
        }
        convertlen ++;
    }

    q->convertlen = tempdatalen;
    *dest = *dest + convertlen;
    return convertlen;

}

/*****************************************************************************
 * FUNCTION
 *  xml_new_generator
 * DESCRIPTION
 *  this function is used to create a new generator
 * PARAMETERS
 *  dest    [IN]    file or buffer to save xml text
 *  length  [IN]    buffer length if buffer
 * RETURNS
 *  handle of generator. 
 *      -1: means failed;
 *      0 or >0:  means succeed;
 *****************************************************************************/

XG_HANDLE xml_new_generator(kal_char* dest, kal_uint32 length)
{
    kal_int32 index;
    XG_HANDLE hd = -1;
    xml_generator_struct *p = NULL;
    
    
    if(dest == NULL)
    {
        return (XG_HANDLE)(-1);
    }

    for (index = 0; index < XG_MAX_HANDLE_NUM; index++)
    {
        if (xg_array[index].occupy == 0)
        {
            p = &(xg_array[index]);
            memset (p, 0, sizeof(xml_generator_struct));
            p->occupy = 1;
            hd = (XG_HANDLE)index;
            break;
        }
    }
    
    if (index == XG_MAX_HANDLE_NUM)
    {
        return (XG_HANDLE)(-1);
    }
    
   
    if (length == 0)    /* xml text will be saved to file */
    {
       
        p->file = FS_Open((WCHAR*)dest, FS_READ_WRITE | FS_CREATE_ALWAYS);
        if (p->file < FS_NO_ERROR)
        {
            p->occupy = 0;
            return (XG_HANDLE)(-1);
        }

	
    }
    else    /* xml text will be saved to buffer */
    {
        p->buf = dest;
        p->buflen = length;
    }
    /* malloc temp buffer */
    p->tempbuf = xml_generate_get_buffer(XG_BUFFER_SIZE);
    if (p->tempbuf == NULL)
    {
        p->occupy = 0;
        return (XG_HANDLE)(-1);
    }
    p->convertbuf = xml_generate_get_buffer(CONVERT_BUF_SIZE);
    if (p->convertbuf == NULL)
    {
        p->occupy = 0;
        return (XG_HANDLE)(-1);
    }
    return hd;
}

/*****************************************************************************
 * FUNCTION
 *  xml_new_generator_file
 * DESCRIPTION
 *  this function is used to create a new generator
 * PARAMETERS
 *  fh  [IN]  file handle    
 * RETURNS
 *  handle of generator. 
 *      -1: means failed;
 *      0 or >0:  means succeed;
 *****************************************************************************/

XG_HANDLE xml_new_generator_file(FS_HANDLE fh)
{
    kal_int32 index;
    XG_HANDLE hd = -1;
    xml_generator_struct *p = NULL;
  

    for (index = 0; index < XG_MAX_HANDLE_NUM; index++)
    {
        if (xg_array[index].occupy == 0)
        {
            p = &(xg_array[index]);
            memset (p, 0, sizeof(xml_generator_struct));
            p->occupy = 1;
            hd = (XG_HANDLE)index;
            break;
        }
    }
    
    if (index == XG_MAX_HANDLE_NUM)
    {
        return (XG_HANDLE)(-1);
    }
    
   
    p->file = fh;
    if (p->file < FS_NO_ERROR)
    {
        p->occupy = 0;
        return (XG_HANDLE)(-1);
    }

   
    /* malloc temp buffer */
    p->tempbuf = xml_generate_get_buffer(XG_BUFFER_SIZE);
    if (p->tempbuf == NULL)
    {
        p->occupy = 0;
        return (XG_HANDLE)(-1);
    }
    p->convertbuf = xml_generate_get_buffer(CONVERT_BUF_SIZE);
    if (p->convertbuf == NULL)
    {
        p->occupy = 0;
        return (XG_HANDLE)(-1);
    }
    p->forfile = 1;
    return hd;
}

/*****************************************************************************
 * FUNCTION
 *  xml_close_generator
 * DESCRIPTION
 *  this function is used to close a generator
 * PARAMETERS
 *  hd    [IN]    handle of generator
 * RETURNS
 *  data length or error code. 
 *      -1: means failed;
 *      >0 :  means succeed, returns generated data length in dest buffer or file
 *****************************************************************************/

kal_int32 xml_close_generator(XG_HANDLE hd)
{
    xml_generator_struct *p = NULL;
    kal_uint32 index = 0, length;

    if ((hd < 0) || (hd >= XG_MAX_HANDLE_NUM))
    {
        return -1;
    }
    p = &(xg_array[hd]);

    if(p->forfile == 0)
    {
        if(p->file != 0)
        {
            FS_Close(p->file);       
        }
    }
    if (p->tempbuf != NULL)
    {
        xml_generate_free_buffer(p->tempbuf);
    }  
	
    if (p->convertbuf != NULL)
    {
        xml_generate_free_buffer(p->convertbuf);
    }
	
    while((index < XG_MAX_ELEM_DEPTH) && ((p->tagstack)[index] != NULL))
    {
        xml_generate_free_buffer((p->tagstack)[index]);
        index++;
    }  
    if (p->curdepth != 0)  
    {
        memset(p, 0, sizeof(xml_generator_struct));
        return XG_E_MISMATCH_TAG;
    }
    length = p->curlen;
    memset(p, 0, sizeof(xml_generator_struct));
    return length;
}



/*****************************************************************************
 * FUNCTION
 *  xml_generate_xmldecl
 * DESCRIPTION
 *  this function is used to generate xml declaration like this:"<?xml version="1.0" encoding="UTF-8" ?>"
 * PARAMETERS
 *  hd      [IN]    handle of generator
 *  verstr  [IN]    version string, format like this: x.x, if verstr == NULL, generator will use default verstr"1.0"    
 *  encode  [IN]    encoding type, is a value of XML_ENCODING_TYPE_ENUM
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/

kal_int32 xml_generate_xmldecl(XG_HANDLE hd, const kal_char *verstr, XML_ENCODING_TYPE_ENUM encode)
{
    char charset[XG_MAX_CHARSET_LEN + 10];
    kal_uint32  textlen = 0;
    kal_int32 ret;
    xml_generator_struct *p = NULL;

/* first check if parameters are correct */
    if ((hd < 0) || (hd >= XG_MAX_HANDLE_NUM))
    {
        return XG_E_HANDLE;
    }
    if (encode >= XML_ENCODING_UNKNOWN)
    {
        return XG_E_UNKNOWN_CHARSET;
    }
/* if verstr is NULL, use default version string "1.0" */
    if (verstr == NULL)
    {
        verstr = "1.0";
    }
/* to limit the verstr length is to avoid memory overflow of tempbuf */    
    if (strlen(verstr) > XG_MAX_VERSTR_LEN)
    {
        return XG_E_FAIL;
    }
/* construct charset */    
    charset[0] = 0;
    strcat(charset, XML_TAG_ENCODING);
    strcat(charset, "=\"");

    switch (encode)
    {
        case XML_ENCODING_UTF8:
            strcat(charset, XML_TAG_ENCODING_UTF8);
            break;
        case XML_ENCODING_UTF16:
            strcat(charset, XML_TAG_ENCODING_UTF16);
            break;
        case XML_ENCODING_UCS2:
            strcat(charset, XML_TAG_ENCODING_UCS2);
            break;
        case XML_ENCODING_UCS4:
            strcat(charset, XML_TAG_ENCODING_UCS4);
            break;
        default:
            strcat(charset, XML_TAG_ENCODING_UTF8);         
    }

    strcat(charset, XML_DOUBLE_QUOTE);
    p = &(xg_array[hd]);
/* temp buffer is used to load xml declaration string like this: "<?xml version="1.0" encoding="UTF-8" ?>" */    

    textlen += sprintf(p->tempbuf, "%s%s%s","<?xml version=\"", verstr, "\" ");
    textlen += sprintf(p->tempbuf+textlen, "%s%s%s\r\n", charset, XML_SPACE, XML_TAG_PROLOG_END);
//    ASSERT(textlen <= XG_BUFFER_SIZE);
    
/* write tempbuf to file or buffer */
    if ((ret = xml_generate_flash_text(hd, p->tempbuf, textlen)) < 0)
    {
        return ret;
    }
    return XG_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  xml_generate_doctypedecl
 * DESCRIPTION
 *  this function is used to generate xml document type declaration like this:
 *  <!DOCTYPE bookshop SYSTEM "bookshop.dtd">
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  name        [IN]    doctype name, it should be the same as root element name    
 *  mark        [IN]    PUBLIC or SYSTEM
 *  externalid  [IN]    external id
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/
kal_int32 xml_generate_doctypedecl(XG_HANDLE hd, const kal_char* name, xg_doctype_mark_enum mark, const kal_char* externalid)
{
    xml_generator_struct *p = NULL;
    kal_uint32 textlen = 0;
    kal_int32 ret;


/* first check if parameters are correct */
    if ((hd < 0) || (hd >= XG_MAX_HANDLE_NUM))
    {
        return XG_E_HANDLE;
    }
    if (name == NULL)
    {
        return XG_E_FAIL;
    }
    if (externalid == NULL)
    {
        return XG_E_FAIL;
    }
    if ((strlen(name)+strlen(externalid)) > XG_MAX_NAME_EXTERNALID_LEN) /* this is to avoid overflow of tempbuf */
    {
        return XG_E_OVER_BUFFER;
    }

    p = &(xg_array[hd]);
    
/* construct doctype declaration to tempbuf: <!DOCTYPE bookshop SYSTEM "bookshop.dtd"> */
    p->tempbuf[0] = 0;
    textlen += sprintf(p->tempbuf, "%s%s%s%s", XML_TAG_DOCTYPE_START, XML_SPACE, name, XML_SPACE);
    switch (mark)
    {
        case XG_DOCTYPE_PUBLIC:
            textlen += sprintf(p->tempbuf+textlen, "%s%s%s%s", "PUBLIC", XML_SPACE, XML_DOUBLE_QUOTE, externalid);
            break;
            
        case XG_DOCTYPE_SYSTEM:
            textlen += sprintf(p->tempbuf+textlen, "%s%s%s%s", "SYSTEM", XML_SPACE, XML_DOUBLE_QUOTE, externalid);
            break;
        default:
            return XG_E_FAIL;
    }
    textlen += sprintf(p->tempbuf+textlen, "%s%s\r\n", XML_DOUBLE_QUOTE, XML_TAG_GENERAL_END);
//    ASSERT(textlen <= XG_BUFFER_SIZE);
        
/* write tempbuf to file or buffer */
    if ((ret = xml_generate_flash_text(hd, p->tempbuf, textlen)) < 0)
    {
        return ret;
    }
    return XG_RESULT_OK;
    
    
}

/*****************************************************************************
 * FUNCTION
 *  xml_generate_doctypedecl_ex
 * DESCRIPTION
 *  This function is for application to generate document type declaration as following:
 *      <!DOCTYPE bookshop[
 *      <!ELEMENT book1(#PCDATA)>
 *      <!ENTITY test "test case"> 
 *      ]>
 * PARAMETERS
 *  hd      [IN]    handle of generator
 *  name    [IN]    doctype name, it should be the same as root element name    
 *  dtd     [IN]    File or buffer to store dtd information
 *  len_dtd [IN]    If application passes dtd information with file, len_dtd should be 0;
 *                  If application passes dtd information with buffer, len_dtd is the length of buffer
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/
kal_int32 xml_generate_doctypedecl_ex(XG_HANDLE hd, const kal_char* name, kal_char* dtd, kal_uint32 len_dtd)
{
        xml_generator_struct *p = NULL;
        kal_uint32 textlen = 0;
        kal_int32 ret;
    

    /* first check if parameters are correct */
        if ((hd < 0) || (hd >= XG_MAX_HANDLE_NUM))
        {
            return XG_E_HANDLE;
        }
        if ((name == NULL)||(dtd == NULL))
        {
            return XG_E_FAIL;
        }
        if (strlen(name)> XG_MAX_NAME_EXTERNALID_LEN) /* this is to avoid overflow of tempbuf */
        {
            return XG_E_OVER_BUFFER;
        }
        
        p = &(xg_array[hd]);
        
   /* construct tempbuf :<!DOCTYPE bookshop[ */     
        p->tempbuf[0] = 0;
        textlen += sprintf(p->tempbuf+textlen, "%s%s%s%s", XML_TAG_DOCTYPE_START, XML_SPACE, name, XML_SPACE);
        textlen += sprintf(p->tempbuf+textlen, "%s\r\n", XML_SQUARE_LEFT_BRAKET);
        ret = xml_generate_flash_text(hd, p->tempbuf, textlen);

   /* write dtd */
        ret = xml_generate_flash_text(hd, dtd, len_dtd);   

   /* write "]" after dtd*/
        p->tempbuf[0] = 0;
        textlen = 0;
        textlen += sprintf(p->tempbuf, "\r\n%s%s\r\n", XML_SQUARE_RIGHT_BRAKET, XML_TAG_GENERAL_END); 
//        ASSERT(textlen <= XG_BUFFER_SIZE);        
        ret = xml_generate_flash_text(hd, p->tempbuf, textlen);
        if (ret < 0)
        {
            return ret;
        }      
        return XG_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  xml_generate_stag
 * DESCRIPTION
 *  This function is for application to generate start tag as following:
 *  <book1 auther="John" title="XML SPEC"> 
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  el          [IN]    element name
 *  attrlist    [IN]    attribute struct array.
 *                      If no attribute, attrlist should be NULL, and num_attr should be 
 *  num_attr    [IN]    number of attribute struct
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/

kal_int32 xml_generate_stag(XG_HANDLE hd, const kal_char* el, xg_attr_struct* attrlist, kal_uint32 num_attr)
{
    xml_generator_struct *p = NULL;
    kal_uint32 textlen = 0, index;
    kal_int32 ret;

/* first check if parameters are correct */
    if ((hd < 0) || (hd >= XG_MAX_HANDLE_NUM))
    {
        return XG_E_HANDLE;
    }
    if (el == NULL)
    {
        return XG_E_FAIL;
    }
    if ((attrlist == NULL) && (num_attr != 0))
    {
        return XG_E_FAIL;
    }
    
    p = &(xg_array[hd]);
    p->tempbuf[0] = 0;

    textlen += sprintf(p->tempbuf, "\r\n%s%s",XML_TAG_ELEMENT_START, el);
    for (index =0; index < num_attr; index++)
    {
        if ((attrlist[index].attrname == NULL) || (attrlist[index].attrvalue == NULL))
        {
            return XG_E_FAIL;
        }
        if ((textlen + strlen(attrlist[index].attrname) + strlen(attrlist[index].attrvalue) + 3) >= XG_BUFFER_SIZE)
        {
            return XG_E_OVER_BUFFER;
        }           
        textlen += sprintf(p->tempbuf+textlen, " %s%s%s%s%s", 
            attrlist[index].attrname, XML_EQUAL, XML_DOUBLE_QUOTE, attrlist[index].attrvalue, XML_DOUBLE_QUOTE);
    }
    textlen += sprintf(p->tempbuf+textlen, "%s", XML_TAG_GENERAL_END);
//    ASSERT(textlen <= XG_BUFFER_SIZE);

/* write tempbuf to file or buffer */
    if ((ret =xml_generate_flash_text(hd, p->tempbuf, textlen)) < 0) 
    {
        return ret;
    }

/* push tag to tagstack */
   return xml_generate_push_tagstack(p, el);  

}


/*****************************************************************************
 * FUNCTION
 *  xml_generate_data
 * DESCRIPTION
 *  This function is for application to generate element content.
 *  Application can pass data with file or buffer. If with file, data is the 
 *  file name encoded with Unicode, datalen should be 0; if with buffer, data
 *  is ptr to buffer, datalen is the length of buffer
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  data        [IN]    Filename or buffer with data. 
 *  datalen     [IN]    if with buffer, datalen is the length of buffer, 
 *                      if with file, datalen should be 0
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/
kal_int32  xml_generate_data(XG_HANDLE hd, kal_char* data, kal_uint32 datalen)
{
    kal_int32 ret;
    
    /* first check if parameters are correct */
    if ((hd < 0) || (hd >= XG_MAX_HANDLE_NUM))
    {
        return XG_E_HANDLE;
    }
    if (data == NULL)
    {
        return XG_E_FAIL;
    } 

    if ((ret = xml_generate_flash_text(hd, data, datalen)) < 0)
    {
        return ret;
    }
    return XG_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  xml_generate_Cdata
 * DESCRIPTION
 *  This function is for application to generate CDADA in element content as following:
 *  [![CDATA[<a>abc</a>]]>
 *  Application can pass data with file or buffer. If with file, data is the 
 *  file name encoded with Unicode, datalen should be 0; if with buffer, data
 *  is ptr to buffer, datalen is the length of buffer
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  cdata       [IN]    Filename or buffer with cdata. 
 *  datalen     [IN]    if with buffer, datalen is the length of buffer, 
 *                      if with file, datalen should be 0
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/

kal_int32 xml_generate_cdata(XG_HANDLE hd, kal_char* cdata, kal_uint32 datalen)
{
    kal_int32 ret;

    /* first check if parameters are correct */
    if ((hd < 0) || (hd >= XG_MAX_HANDLE_NUM))
    {
        return XG_E_HANDLE;
    }
    if (cdata == NULL)
    {
        return XG_E_FAIL;
    } 
    
    if ((ret = xml_generate_flash_text(hd, XML_TAG_CDATA_START, strlen(XML_TAG_CDATA_START))) < 0)
    {
        return ret;
    }        
    if ((ret = xml_generate_flash_text(hd, cdata, datalen)) < 0)
    {
        return ret;
    }
    if ((ret = xml_generate_flash_text(hd, XML_TAG_CDATA_END, strlen(XML_TAG_CDATA_END))) < 0)
    {
        return ret;
    }     
    
    return XG_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  xml_generate_etag
 * DESCRIPTION
 *  This function is for application to generate end tag as following:
 *  </book1>
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  el          [IN]    element name
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/
kal_int32  xml_generate_etag(XG_HANDLE hd, const kal_char* el)
{
    kal_uint32 textlen = 0;
    kal_int32 ret;
    xml_generator_struct *p = NULL;

    /* first check if parameters are correct */
    if ((hd < 0) || (hd >= XG_MAX_HANDLE_NUM))
    {
        return XG_E_HANDLE;
    }

    if (el == NULL)
    {
        return XG_E_FAIL;
    }

    if (strlen(el) > XG_MAX_NAME_EXTERNALID_LEN)
    {
        return XG_E_OVER_BUFFER;
    }   
    
    p = &(xg_array[hd]);
    p->tempbuf[0] = 0;

    if ((strcmp(p->tagstack[p->curdepth-1], el) != 0))
    {
        return XG_E_MISMATCH_TAG;
    }
    
    textlen = sprintf(p->tempbuf, "%s%s%s\r\n", XML_TAG_ELEMENT_END, el, XML_TAG_GENERAL_END);
//    ASSERT(textlen <= XG_BUFFER_SIZE); 
    ret = xml_generate_flash_text(hd, p->tempbuf, textlen);  
    if (ret < 0)
    {
        return ret;
    }

    xml_generate_pop_tagstack(p);
    return XG_RESULT_OK;

}

kal_int32 xml_generate_converted_data(XG_HANDLE hd, kal_char *text, kal_int32 textlen)
{    

	 kal_int32 ret, i, len;
     xml_generator_struct *p = NULL;
	 /* first check if parameters are correct */
	if ((hd < 0) || (hd >= XG_MAX_HANDLE_NUM))
    {
	     return XG_E_HANDLE;
    }

	 p = &(xg_array[hd]);
	 len = 0;
	 while(i = xml_generate_convert_named_char(p, &text, textlen))
     {   
           textlen -= i;
           if((ret =  xml_generate_data(hd, p->convertbuf, p->convertlen)) < 0)
           	{
           		return ret;
           	}
            
           len += i;
     }

	 return len;
            
}

/*****************************************************************************
 * FUNCTION
 *  xml_generate_inline_element
 * DESCRIPTION
 *  This function is for application to generate a whole element without child element
 *  and attribute, only content. just as following: <a> test </a>.
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  el          [IN]    element name
 *  data        [IN]    Filename or buffer with data. 
 *  datalen     [IN]    if with buffer, datalen is the length of buffer, 
 *                      if with file, datalen should be 0
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/
kal_int32 xml_generate_inline_element(XG_HANDLE hd, const kal_char* el, kal_char* data, kal_uint32 datalen)
{
    kal_int32 ret;
    kal_uint32 len_read, len;
    FS_HANDLE fhandle = -1;
    kal_char tempbuf[TEMP_BUF_LEN];
    if ((ret = xml_generate_stag(hd, el, NULL, 0)) < 0)
    {
        return ret;
    }

	if (datalen == 0)
	{   
	    fhandle = FS_Open((WCHAR*)data, FS_READ_ONLY);
        if (fhandle < 0)
        {
            return XG_E_FAIL;
        }
        ret = FS_GetFileSize(fhandle, &len);
        if (ret < 0)
        {
            FS_Close(fhandle);
            return XG_E_FAIL;
        }       
		while ((ret = FS_Read(fhandle, tempbuf, TEMP_BUF_LEN-1, &len_read)) >= FS_NO_ERROR)
        {
        	if (len_read == 0)
            {
            	break;
            }
			if ((ret=xml_generate_converted_data(hd, tempbuf, len_read)) < 0)
			{
				 return ret;
			}
		}
		FS_Close(fhandle);
	}
	else
    {
    	if ((ret = xml_generate_converted_data(hd, data, datalen)) < 0)
    {
        return ret;
    }
	}

/*
    if ((ret = xml_generate_data(hd, data, datalen)) < 0)
    {
        return ret;
    }
    */
    return xml_generate_etag(hd, el);
    
}

/*****************************************************************************
 * FUNCTION
 *  xml_generate_empty_element
 * DESCRIPTION
 *  This function is for application to generate empty which has no content and
 *  end tag as following: 
 *  <b b1="m" b2="n" />

 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  el          [IN]    element name
 *  attrlist    [IN]    attribute struct array.
 *                      If no attribute, attrlist should be NULL, and num_attr should be 
 *  num_attr    [IN]    number of attribute struct
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/
kal_int32 xml_generate_empty_element(XG_HANDLE hd, const kal_char* el, xg_attr_struct* attrlist, kal_uint32 num_attr)
{
    xml_generator_struct *p = NULL;
    kal_uint32 textlen = 0, index;
    kal_int32 ret;
    
    /* first check if parameters are correct */
    if ((hd < 0) || (hd >= XG_MAX_HANDLE_NUM))
    {
        return XG_E_HANDLE;
    }
    if (el == NULL)
    {
        return XG_E_FAIL;
    }
    if ((attrlist == NULL) && (num_attr != 0))
    {
        return XG_E_FAIL;
    }
    
    p = &(xg_array[hd]);
    p->tempbuf[0] = 0;
    
    textlen += sprintf(p->tempbuf, "\r\n%s%s",XML_TAG_ELEMENT_START, el);
    for (index =0; index < num_attr; index++)
    {
        if ((attrlist[index].attrname == NULL) || (attrlist[index].attrvalue == NULL))
        {
            return XG_E_FAIL;
        }
        textlen += sprintf(p->tempbuf+textlen, " %s%s%s%s%s", 
            attrlist[index].attrname, XML_EQUAL, XML_DOUBLE_QUOTE, attrlist[index].attrvalue, XML_DOUBLE_QUOTE);
    }
    textlen += sprintf(p->tempbuf+textlen, "%s", XML_TAG_SINGLE_END);
    ASSERT(textlen <= XG_BUFFER_SIZE);
    
    /* write tempbuf to file or buffer */
    if ((ret =xml_generate_flash_text(hd, p->tempbuf, textlen)) < 0) 
    {
        return ret;
    }

    return XG_RESULT_OK;
}
/*****************************************************************************
 * FUNCTION
 *  xml_generate_flash_text
 * DESCRIPTION
 *  this function is used to write xml text to file or buffer
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  text        [IN]    xml text. text can be a filename encoded in wchar, or buffer.
 *  textlen     [IN]    if xml text is in file, len is 0, else len is the length of text buffer
 * RETURNS
 *  handle of generator. 
 *      <0 : means failed, returns error code;
 *      >0 :  means succeed, returns the length of text written;
 *****************************************************************************/

static kal_int32 xml_generate_flash_text(kal_int8 hd, kal_char *text, kal_uint32 textlen)
{
    kal_uint32 length, len;
    kal_int32 ret;
    FS_HANDLE fhandle = -1;
    xml_generator_struct *p = NULL;


/* first to get xml text length */
    if(textlen == 0)/* text is in file */
    {
        fhandle = FS_Open((WCHAR*)text, FS_READ_ONLY);
        if (fhandle < 0)
        {
            return XG_E_FAIL;
        }
        ret = FS_GetFileSize(fhandle, &length);
	if (ret == FS_FILE_NOT_FOUND)
	{
	    return XG_E_FILE_NOT_FOUND;
	}
        if (ret < 0)
        {
            FS_Close(fhandle);
            return XG_E_FAIL;
        }       
    }
    else /* text is in buffer */
    {
        length = textlen;
    }

    p = &(xg_array[hd]);

        
/* then write xml text to dest */
    if(p->buf != NULL)     /* write xml text to buffer */    
    {
        /* verify if over-buffer */
        if(p->curlen+length > p->buflen)
        {
            if(fhandle != -1)
            {
                FS_Close(fhandle);
            }
            ASSERT(0);
            kal_printf("buffer to save will be overflow!!!!\r\n");
            return XG_E_OVER_BUFFER;            
        }
        if (textlen != 0) /* text is in buffer, write xml text from buffer to buffer */
        {
            memcpy(p->buf+p->curlen, text, textlen);
            len = textlen;
            ret = 0;
        }
        else /* text is in file, write xml text from file to buffer */
        {
            ret = xml_generate_write_filetobuf(p->buf+p->curlen, fhandle, &len);
            FS_Close(fhandle);
        }
    }
    else /* write xml text to file */
    {
        
        if (textlen != 0) /* text is in buffer, write xml text from buffer to file */
        {
            
              ret = FS_Write(p->file, text, textlen, &len);
              if(ret == FS_DISK_FULL)
        {
        	return XG_E_LACK_DISK;
        }
           
            
        }
        else    /* text is in file, write xml text from file to file */
        {
            ret = xml_generate_write_filetofile(p->file, fhandle, &len);
            FS_Close(fhandle);     
        }
    }
    if (ret < 0)
    {
        return ret;
    }  
    else
    {
        
        p->curlen += len;
        return len; 
    }      
}


/*****************************************************************************
 * FUNCTION
 *  xml_generate_push_tagstack
 * DESCRIPTION
 *  This function is used to push tagstack to tag list
 * PARAMETERS
 *  p           [IN]        generator struct
 *  tagname     [IN]        Start tag name to be pused
 * RETURNS
 *  if successful, return XG_RESULT_OK
 *****************************************************************************/
static kal_int32 xml_generate_push_tagstack(xml_generator_struct *p, const kal_char *tagname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *namebuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if p->currdepth overs XG_MAX_ELEM_DEPTH, it maybe cause out of memory */
    if (p->curdepth >= XG_MAX_ELEM_DEPTH)
    {
        return XG_E_FAIL;
    }
    namebuffer = xml_generate_get_buffer(strlen(tagname) + 1);
    if (namebuffer == NULL)
    {
        return XG_E_NO_MEMORY;
    }
    strcpy(namebuffer, tagname);

    p->tagstack[p->curdepth] = namebuffer;
    p->curdepth++;

    return XG_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  xml_generate_pop_tagstack
 * DESCRIPTION
 *  This function is used to pop last start_tag in tag stack
 * PARAMETERS
 *  parser      [IN]        parser struct
 * RETURNS
 *  void
 *****************************************************************************/
static void xml_generate_pop_tagstack(xml_generator_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->curdepth--;
    if (p->tagstack[p->curdepth] != NULL)
    {
        xml_generate_free_buffer(p->tagstack[p->curdepth]);
        p->tagstack[p->curdepth] = NULL;
    }
    return;
}



#endif     /* __XML_SUPPORT__ */
