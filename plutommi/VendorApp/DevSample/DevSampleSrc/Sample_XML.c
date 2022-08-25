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
 *  Sample_XML.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sample code for XML Parser
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#include "APPSDKFrameworkGProt.h"
#include "APPSDKNetworkGProt.h"


/****************************************************************************
*
*  [Sample]
*  Purpose   : This sample code provides correct flow about the way of using the 
*              XML Parser APIs.
*  
*  Function  : The XML Parser provides a set of APIs for applications to parse
*              XML document and extract useful information from the XML document
*              what they need.
*  
*  Notice    : When parsing an XML document, an application firstly must to create
*              an XML Parser object to do the parsing and register a few functions
*              as element or data handlers to handle the information parsed from
*              the XML document.
*              XML Paeser will return corresponsive error code if error
*              occurs when parsing. If it wants to query which error it is,
*              application can call function "xml_get_err_string" to get it.
*              The parsing will not be stopped when error occurs, xml
*              parser will just ignore it, and continue to do next parsing.
*  
*  Branch    : 08A, 08B, MAUI
*  
*  API Ref   : xml_new_parser
*              xml_close_parser
*              xml_register_doctype_handler
*              xml_register_element_handler
*              xml_register_data_handler
*              xml_configure_memory
*              xml_parse
*              xml_parse_buffer
*              xml_get_err_string
*  
*****************************************************************************/

const static kal_char mmi_sample_xml_parser_buffer[] = {"<?xml version=\"1.0\" encoding=\"UTF-8\"?><adobehelp type=\"product\"><title>Adobe Reader 8</title><files type=\"nav\"><file type=\"contents\">nav_toc.xml</file><file type=\"search\">final_search_entries.xml</file></files></adobehelp>"};

#define MMI_SAMPLE_XML_FILE_PATH_LEN        (128)   //XML File Path length

#define MMI_SAMPLE_XML_SAMPLE_FILE          "%c:\\xml_sample.xml"

typedef struct
{
    XML_PARSER_STRUCT    xml_parser;        /* xml parser context struct */
}mmi_sample_xml_parser_context_struct;

static mmi_sample_xml_parser_context_struct g_sample_xml_parser_cntx;

/*****************************************************************************
 * FUNCTION
 *  mmi_sample_xml_parser_doctype_start_handler
 * DESCRIPTION
 *  This function is for XML parser to return doctype start tag information to application
 * PARAMETERS
 *  data                [IN]        Reserved
 *  doctypeName         [IN]        Document type name string
 *  sysid               [IN]        System external id list
 *  pubid               [IN]        Public external id list
 *  internal_subset     [IN]        Internal subset presence
 *  error               [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_xml_parser_doctype_start_handler(
                                            void *data,
                                            const kal_char *doctypeName,
                                            const kal_char **sysid, 
                                            const kal_char **pubid,
                                            kal_int32 internal_subset,
                                            kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (XML_NO_ERROR == error)
    {
        index = 0;
        if (NULL != sysid)
        {
            while (sysid[index])
            {
                printf("%s\n", sysid[index]);
                
                /*
                 * TODO: Add any code here...
                 * If it wants to deal with the data of the system external id list, application
                 * could add the process code here, and could put the data to buffer, to file,
                 * or to other structure, it depends on the special usages.
                 * [Example]:
                 * 1) strcpy(app_buf, sysid[index]);
                 * 2) FS_Write(app_file, (WCHAR*)sysid[index], strlen(sysid[index]), NULL);
                 * 3) ...
                 */
                
                index++;
            }
        }
        index = 0;
        if (NULL != pubid)
        {
            while (pubid[index])
            {
                printf("%s\n", pubid[index]);
                
                /*
                 * TODO: Add any code here...
                 * If it wants to deal with the data of the public external id list, application
                 * could add the process code here, and could put the data to buffer, to file, 
                 * or to other structure, it depends on the special usages. 
                 * [Example]:
                 * 1) strcpy(app_buf, pubid[index]);
                 * 2) FS_Write(app_file, (WCHAR*)pubid[index], strlen(pubid[index]), NULL);
                 * 3) ...
                 */
                
                index++;
            }
        }
    }
    else
    {
        kal_char    *err_str = NULL;
        
        err_str = xml_get_err_string(&g_sample_xml_parser_cntx.xml_parser);
        printf("%s\n", err_str);
        
        /*
         * TODO: Add any code here...
         * If it wants to deal with the data of the error string, application could
         * add the process code here, and could put the error string to buffer, or to
         * file, it depends on the special usages. 
         * [Example]:
         * 1) strcpy(app_buf, err_str);
         * 2) FS_Write(app_file, (WCHAR*)err_str, strlen(err_str), NULL);
         * 3) ...
         */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_xml_parser_doctype_end_handler
 * DESCRIPTION
 *  This function is for XML parser to indicate the end of document type to application.
 * PARAMETERS
 *  data        [IN]        Reserved
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_xml_parser_doctype_end_handler(void *data, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (XML_NO_ERROR != error)
    {
        kal_char    *err_str = NULL;
        
        err_str = xml_get_err_string(&g_sample_xml_parser_cntx.xml_parser);
        printf("%s\n", err_str);
        
        /*
         * TODO: Add any code here...
         * If it wants to deal with the data of the error string, application could
         * add the process code here, and could put the error string to buffer, or to
         * file, it depends on the special usages. 
         * [Example]:
         * 1) strcpy(app_buf, err_str);
         * 2) FS_Write(app_file, (WCHAR*)err_str, strlen(err_str), NULL);
         * 3) ...
         */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_xml_parser_elem_start_handler
 * DESCRIPTION
 *  This function is for XML parser to return start tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  attr        [IN]        Attribute list
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_xml_parser_elem_start_handler(void *data, const kal_char *el, const kal_char **attr, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (XML_NO_ERROR == error)
    {
        printf("%s\n", el);

        /*
         * TODO: Add any code here...
         * If it wants to deal with the data of the element, application could
         * add the process code here, and could put the data string to buffer, or
         * to file, it depends on the special usages. 
         * [Example]:
         * 1) strcpy(app_buf, el);
         * 2) FS_Write(app_file, (WCHAR*)el, strlen(el), NULL);
         * 3) ...
         */
        
        while ((NULL != attr[index]) && (NULL != attr[index + 1]))
        {
            printf("%s = %s\n", attr[index], attr[index + 1]);

            /*
             * TODO: Add any code here...
             * If it wants to deal with the data of the element and attribute list,
             * application could add the process code here, and could put the data to
             * buffer, to file, or to other structure, it depends on the special usages.
             * [Example]:
             * 1) strcpy(app_buf, attr[index]);
             * 2) strcpy(app_buf, attr[index + 1]);
             * 3) FS_Write(app_file, (WCHAR*)attr[index], strlen(attr[index]), NULL);
             * 4) FS_Write(app_file, (WCHAR*)attr[index + 1], strlen(attr[index + 1]), NULL);
             * 5) ...
             */
            
            index += 2;
        }
    }
    else
    {
        kal_char    *err_str = NULL;
        
        err_str = xml_get_err_string(&g_sample_xml_parser_cntx.xml_parser);
        printf("%s\n", err_str);
        
        /*
         * TODO: Add any code here...
         * If it wants to deal with the data of the error string, application could
         * add the process code here, and could put the error string to buffer, or to
         * file, it depends on the special usages. 
         * [Example]:
         * 1) strcpy(app_buf, err_str);
         * 2) FS_Write(app_file, (WCHAR*)err_str, strlen(err_str), NULL);
         * 3) ...
         */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_xml_parser_elem_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_xml_parser_elem_end_handler(void *data, const kal_char *el, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (XML_NO_ERROR == error)
    {
        printf("%s\n", el);

        /*
         * TODO: Add any code here...
         * If it wants to deal with the data of the element, application could
         * add the process code here, and could put the data string to buffer,
         * or to file, it depends on the special usages. 
         * [Example]:
         * 1) strcpy(app_buf, el);
         * 2) FS_Write(app_file, (WCHAR*)el, strlen(el), NULL);
         * 3) ...
         */
    }
    else
    {
        kal_char    *err_str = NULL;
        
        err_str = xml_get_err_string(&g_sample_xml_parser_cntx.xml_parser);
        printf("%s\n", err_str);
        
        /*
         * TODO: Add any code here...
         * If it wants to deal with the data of the error string, application could
         * add the process code here, and could put the error string to buffer, or to
         * file, it depends on the special usages. 
         * [Example]:
         * 1) strcpy(app_buf, err_str);
         * 2) FS_Write(app_file, (WCHAR*)err_str, strlen(err_str), NULL);
         * 3) ...
         */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_xml_parser_data_handler
 * DESCRIPTION
 *  This function is for XML parser to return element content information to application
 * PARAMETERS
 *  resv        [IN]        Reserved
 *  el          [IN]        Element name
 *  data        [IN]        Data string
 *  len         [IN]        Data string length
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_xml_parser_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (XML_NO_ERROR == error)
    {
        printf("%s\n", data);

        /*
         * TODO: Add any code here...
         * If it wants to deal with the real data of the xml, application could
         * add the process code here, and could put the real data string to buffer,
         * or to file, it depends on the special usages. 
         * [Example]:
         * 1) strcpy(app_buf, data);
         * 2) FS_Write(app_file, (WCHAR*)data, strlen(data), NULL);
         * 3) ...
         */
    }
    else
    {
        kal_char    *err_str = NULL;
        
        err_str = xml_get_err_string(&g_sample_xml_parser_cntx.xml_parser);
        printf("%s\n", err_str);
        
        /*
         * TODO: Add any code here...
         * If it wants to deal with the data of the error string, application could
         * add the process code here, and could put the error string to buffer, or to
         * file, it depends on the special usages. 
         * [Example]:
         * 1) strcpy(app_buf, err_str);
         * 2) FS_Write(app_file, (WCHAR*)err_str, strlen(err_str), NULL);
         * 3) ...
         */
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sample_xml_parser_malloc_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  buff_size        [IN]        buffer size of malloc
 * RETURNS
 *  void
 *****************************************************************************/
static void *mmi_sample_xml_parser_malloc_handler(kal_int32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * TODO: Add any code here...
     * If it has been to register the handler of the custom functions for malloc and
     * free memory, application should add the mallc function here, and could use the
     * app-base memory, or scree-base memory, and then use the adm functions to management
     * the memory, and then use the adm malloc function to get the memory from the memory pool.
     * it depends on the special applications.
     * [Example]:
     * 1) kal_adm_alloc(adm_id, buff_size);
     * 2) ...
     */
     return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_xml_parser_free_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  buff_ptr        [IN]        point of buffer to free
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_xml_parser_free_handler(void * buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * TODO: Add any code here...
     * If it has been to register the handler of the custom functions for malloc and
     * free memory, application should add the free function here, and could use the
     * app-base memory, or scree-base memory, and then use the adm functions to management
     * the memory, and then use the adm free function to free the memory to the memory pool.
     * it depends on the special applications.
     * [Example]:
     * 1) kal_adm_free(adm_id, buff_ptr);
     * 2) ...
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_xml_parser
 * DESCRIPTION
 *  The sample of xml parser from file or buffer, the output data will be writed to file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_xml_parser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 xml_result = 0;
    kal_wchar xml_file_name[MMI_SAMPLE_XML_FILE_PATH_LEN];
    kal_int32 driver = 0, ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * [1]. Create an XML parser before parse a new XML document
     * Application has to allocate memory for the XML_PARSER_STRUCT structure
     * on it ownbefore calling this API to create parser.
     */
    xml_result = xml_new_parser(&g_sample_xml_parser_cntx.xml_parser);

    /* If the xml parser is created successful, then you can parse the file continue */
    if (XML_RESULT_OK == xml_result)
    {
        /*
         * [2]. Register the doctype, element, data and memory callback function before the parsing,
         * Application has to prepare the handlers as callback functions to perform actions it wants
         * according to application specific logic when the every element is encountered.
         */
        
        /*
         * Register start tag and end tag handler of document type.
         * [Note]: If application doesn't want to deal with the document type, this function could not
         * be called, or the second parameter start_hdlr and third parameter end_hdlr are set to NULL,
         * it will be processed by the default parser procedures, and the data of doc type will be ignored.
         */
        xml_register_doctype_handler(
            &g_sample_xml_parser_cntx.xml_parser,
            mmi_sample_xml_parser_doctype_start_handler,
            mmi_sample_xml_parser_doctype_end_handler);
    
        /*
         * Register start tag and end tag handler of an element.
         * [Note]: If application doesn't want to deal with the element, this function could not be
         * called, or the second parameter start_hdlr and third parameter end_hdlr are set to NULL,
         * it will be processed by the default parser procedures, and the data of element will be ignored.
         * But usually application should deal with the element for special applications. 
         */
        xml_register_element_handler(
            &g_sample_xml_parser_cntx.xml_parser,
            mmi_sample_xml_parser_elem_start_handler,
            mmi_sample_xml_parser_elem_end_handler);

        /*
         * Register data handler of an element.
         * [Note]: If application doesn't want to deal with the data, this function could not be called,
         * or the second parameter data_hdlr is set to NULL, it will be processed by the default parser
         * procedures, and the data of element will be ignored. But usually application should deal with
         * the data for special applications. 
         */
        xml_register_data_handler(
            &g_sample_xml_parser_cntx.xml_parser,
            mmi_sample_xml_parser_data_handler);

        /*
         * Configure malloc and free function pointer.
         * [Note]: If application wants to use the malloc and free functions by themseles, application
         * could call this function to register the handler of the custom functions, and the xml parser
         * will call the custom functions to malloc and free the memory. Otherwise, if application does
         * not register the function handler, xml parser will use the default procedures.
         */
        xml_configure_memory(
            &g_sample_xml_parser_cntx.xml_parser,
            mmi_sample_xml_parser_malloc_handler,
            mmi_sample_xml_parser_free_handler);
    
        /* Get sample XML file path*/
        driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
        memset(xml_file_name, 0, sizeof(xml_file_name));
        kal_wsprintf(xml_file_name, MMI_SAMPLE_XML_SAMPLE_FILE, driver);

        /* Check the sample xml file is existent or not */
        ret = FS_CheckFile(xml_file_name);

        /*
         * [3]. Parse an XML document.
         * If the xml document is existent, APP could call xml_parse function, the input file
         * will be parsed, and previously registered start, end tag handlers and data handler
         * will be called once corresponding segment is encountered during the parsing.
         * If the xml document is not existent, APP could call xml_parse_buffer function, the
         * input buffer will be parsed, and previously registered start, end tag handlers and
         * data handler will be called once corresponding segment is encountered during the
         * parsing.
         */
        if(FS_NO_ERROR == ret)
        {
            /* XML Parser start from file */
            xml_result = xml_parse(&g_sample_xml_parser_cntx.xml_parser, xml_file_name);
        }
        else
        {
            /* XML Parser start from buffer */
            xml_result = xml_parse_buffer(&g_sample_xml_parser_cntx.xml_parser, mmi_sample_xml_parser_buffer, strlen(mmi_sample_xml_parser_buffer));
        }
        
        /*
         * [4]. Close a parser.
         * APP call this function to close a parser after finish parsing and
         * to reset parser data structure or release internal allocated memory.
         */
        xml_close_parser(&g_sample_xml_parser_cntx.xml_parser);
        
    }
}
