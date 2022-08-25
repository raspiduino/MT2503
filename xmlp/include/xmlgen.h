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
 *  xmlgen.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  xml generator extern header file
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
#ifndef XMLGEN_H
#define XMLGEN_H
#ifdef __XML_SUPPORT__

#include "kal_general_types.h"
#include "fs_type.h"

#include "xml_def.h"
#include "xmlgen_common.h"

/* define the document type mark */
typedef enum
{
    XG_DOCTYPE_PUBLIC = 0,  /* used to generate PUBLIC mark */
    XG_DOCTYPE_SYSTEM = 1   /* used to generate SYSTEM mark */
}xg_doctype_mark_enum;

/* define element start or end mark */
typedef enum 
{
    START_TAG_TYPE = 0, /* used to generate the start mark of element */
    END_TAG_TYPE,       /* used to generate the end mark of element */
    TOTAL_TAG_TYPE      /* used to check validity */
}search_type_enum;

/* file handle */
typedef kal_int8 XG_HANDLE;


/*****************************************************************************
 * FUNCTION
 *  xml_new_generator
 * DESCRIPTION
 *  this function is used to create a new generator
 * PARAMETERS
 *  dest:    [IN]    file or buffer to save xml text
 *  length:  [IN]    buffer length if buffer
 * RETURN VALUES
 *  -1: means failed;
 *  0 or >0:  means succeed;
 *****************************************************************************/
extern XG_HANDLE xml_new_generator(kal_char* dest, kal_uint32 length);


/*****************************************************************************
 * FUNCTION
 *  xml_close_generator
 * DESCRIPTION
 *  this function is used to close a generator
 * PARAMETERS
 *  hd:    [IN]    handle of generator
 * RETURN VALUES
 *  -1: means failed;
 *  >0 :  means succeed, returns generated data length in dest buffer or file
 *****************************************************************************/
extern kal_int32 xml_close_generator(XG_HANDLE hd);


/*****************************************************************************
 * FUNCTION
 *  xml_generate_xmldecl
 * DESCRIPTION
 *  this function is used to generate xml declaration like this:
 *  "<?xml version="1.0" encoding="UTF-8" ?>"
 * PARAMETERS
 *  hd:      [IN]    handle of generator
 *  verstr:  [IN]    version string, format like this: x.x, 
 *                  if verstr == NULL, generator will use default verstr"1.0"    
 *  encode:  [IN]    encoding type, is a value of XML_ENCODING_TYPE_ENUM
 * RETURN VALUES
 *  <0: means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 xml_generate_xmldecl(
                    XG_HANDLE hd,
                    const kal_char *verstr,
                    XML_ENCODING_TYPE_ENUM encode);


/*****************************************************************************
 * FUNCTION
 *  xml_generate_doctypedecl
 * DESCRIPTION
 *  this function is used to generate xml document type declaration like this:
 *  <!DOCTYPE bookshop SYSTEM "bookshop.dtd">
 * PARAMETERS
 *  hd:          [IN]    handle of generator
 *  name:        [IN]    doctype name, it should be the same as root element name
 *  mark:        [IN]    PUBLIC or SYSTEM
 *  externalid:  [IN]    external id
 * RETURN VALUES
 *  <0: means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 xml_generate_doctypedecl(
                    XG_HANDLE hd,
                    const kal_char* name,
                    xg_doctype_mark_enum mark,
                    const kal_char* externalid);


/*****************************************************************************
 * FUNCTION
 *  xml_generate_doctypedecl_ex
 * DESCRIPTION
 *  This function is for application to generate document type declaration as following:
 *  <!DOCTYPE bookshop[
 *  <!ELEMENT book1(#PCDATA)>
 *  <!ENTITY test "test case"> 
 *  ]>
 * PARAMETERS
 *  hd:      [IN]    handle of generator
 *  name:    [IN]    doctype name, it should be the same as root element name
 *  dtd:     [IN]    File or buffer to store dtd information
 *  len_dtd: [IN]    If application passes dtd information with file, len_dtd should be 0;
 *                  If application passes dtd information with buffer, 
 *                  len_dtd is the length of buffer
 * RETURN VALUES
 *  <0: means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 xml_generate_doctypedecl_ex(
                    XG_HANDLE hd,
                    const kal_char* name,
                    kal_char* dtd,
                    kal_uint32 len_dtd);


/*****************************************************************************
 * FUNCTION
 *  xml_generate_stag
 * DESCRIPTION
 *  This function is for application to generate start tag as following:
 *  \<book1 auther="John" title="XML SPEC"\> 
 * PARAMETERS
 *  hd:          [IN]    handle of generator
 *  el:          [IN]    element name
 *  attrlist:    [IN]    attribute struct array.
 *                      If no attribute, attrlist should be NULL, and num_attr should be
 *  num_attr:    [IN]    number of attribute struct
 * RETURN VALUES
 *  <0: means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 xml_generate_stag(
                    XG_HANDLE hd,
                    const kal_char* el,
                    xg_attr_struct* attrlist,
                    kal_uint32 num_attr);

/*****************************************************************************
 * FUNCTION
 *  xml_generate_data
 * DESCRIPTION
 *  This function is for application to generate element content.
 *  Application can pass data with file or buffer. If with file, data is the
 *  file name encoded with Unicode, datalen should be 0; if with buffer, data
 *  is ptr to buffer, datalen is the length of buffer
 * PARAMETERS
 *  hd:          [IN]    handle of generator
 *  data:        [IN]    Filename or buffer with data.
 *  datalen:     [IN]    if with buffer, datalen is the length of buffer,
 *                      if with file, datalen should be 0
 * RETURN VALUES
 *  <0: means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 xml_generate_data(XG_HANDLE hd, kal_char* data, kal_uint32 datalen);


/*****************************************************************************
 * FUNCTION
 *  xml_generate_Cdata
 * DESCRIPTION
 *  This function is for application to generate CDADA in element content as following:
 *  <![CDATA[\<a\>abc\</a\>]]>
 *  Application can pass data with file or buffer. If with file, data is the
 *  file name encoded with Unicode, datalen should be 0; if with buffer, data
 *  is ptr to buffer, datalen is the length of buffer
 * PARAMETERS
 *  hd:          [IN]    handle of generator
 *  cdata:       [IN]    Filename or buffer with cdata.
 *  datalen:     [IN]    if with buffer, datalen is the length of buffer,
 *                      if with file, datalen should be 0
 * RETURN VALUES
 *  <0: means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 xml_generate_cdata(XG_HANDLE hd, kal_char* cdata, kal_uint32 datalen);


/*****************************************************************************
 * FUNCTION
 *  xml_generate_etag
 * DESCRIPTION
 *  This function is for application to generate end tag as following:
 *  \</book1\>
 * PARAMETERS
 *  hd:          [IN]    handle of generator
 *  el:          [IN]    element name
 * RETURN VALUES
 *  <0: means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 xml_generate_etag(XG_HANDLE hd, const kal_char* el);


/*****************************************************************************
 * FUNCTION
 *  xml_generate_inline_element
 * DESCRIPTION
 *  This function is for application to generate a whole element without child element
 *  and attribute, only content. just as following: \<a\> test \</a\>.
 * PARAMETERS
 *  hd:          [IN]    handle of generator
 *  el:          [IN]    element name
 *  data:        [IN]    Filename or buffer with data.
 *  datalen:     [IN]    if with buffer, datalen is the length of buffer,
 *                      if with file, datalen should be 0
 * RETURN VALUES
 *  <0: means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 xml_generate_inline_element(
                    XG_HANDLE hd,
                    const kal_char* el,
                    kal_char* data,
                    kal_uint32 datalen);


/*****************************************************************************
 * FUNCTION
 *  xml_generate_empty_element
 * DESCRIPTION
 *  This function is for application to generate empty which has no content and
 *  end tag as following: 
 *  <b b1="m" b2="n" />
 * PARAMETERS
 *  hd:          [IN]    handle of generator
 *  el:          [IN]    element name
 *  attrlist:    [IN]    attribute struct array.
 *                      If no attribute, attrlist should be NULL, and num_attr should be 
 *  num_attr:    [IN]    number of attribute struct
 * RETURN VALUES
 *  <0: means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 xml_generate_empty_element(
                    XG_HANDLE hd,
                    const kal_char* el,
                    xg_attr_struct* attrlist,
                    kal_uint32 num_attr);


/*****************************************************************************
 * FUNCTION
 *  xml_new_generator_file
 * DESCRIPTION
 *  this function is used to create a new generator
 * PARAMETERS
 *  fh:  [IN]  file handle    
 * RETURN VALUES
 *  -1: means failed;
 *  0 or >0:  means succeed;
 *****************************************************************************/
XG_HANDLE xml_new_generator_file(FS_HANDLE fh);

#endif  /* __XML_SUPPORT__ */
#endif  /* XMLGEN_H */
