extern "C"
{
 #include "xml_def.h"
 #include "xmlgen.h"
 #include "wbxmlp.h"
 #include "wbxmlgen.h"
 #include "wbxmlp_def.h"
}

AVK_ADD_ITEM(AVK_OTHER_XML_AUTO,L"Auto case",AVK_OTHER_XML);

const static kal_char xml_sample_buffer[] = {"<?xml version=\"1.0\" encoding=\"UTF-8\"?><adobehelp type=\"product\"><title>Adobe Reader 8</title><files type=\"nav\"><file type=\"contents\">nav_toc.xml</file><file type=\"search\">final_search_entries.xml</file></files></adobehelp>"};
const static kal_char wbxml_sample_buffer[] = {
    0x00, 0x02, 0x6A, 0x00, 0x45, 0xC6, 0x07, 0x87,
    0x08, 0x88, 0x01, 0xC3, 0x13, 0x62, 0x6F, 0x6F,
    0x6B, 0x31, 0x3A, 0x63, 0x6F, 0x6D, 0x70, 0x75,
    0x74, 0x65, 0x72, 0x20, 0x62, 0x6F, 0x6F, 0x6B,
    0x01, 0x4A, 0x03, 0x62, 0x6F, 0x6F, 0x6B, 0x32,
    0x3A, 0x61, 0x72, 0x74, 0x69, 0x73, 0x74, 0x20,
    0x62, 0x6F, 0x6F, 0x6B, 0x00, 0x01, 0x88, 0x06,
    0x85, 0x09, 0x86, 0x01, 0x01
};
const static kal_char wbxml_sample_mark[] = {"10F, North Building Raycom Infotech Park Tower C, $(MTK:escape) No.2 Kexuyuan Nanlu, Haidian District $(Mediatek:unesc) Beijing, China 100190$(MediaTek(Beijing):noesc)"};

#define VS_NW_XML_FILE_PATH_LEN         (128)   //XML File Path length
#define VS_NW_XML_ELEM_START_LEN        (1024)  //XML Start Element length
#define VS_NW_XML_ELEM_END_LEN          (128)   //XML End Tag length
#define VS_NW_XML_ERR_INFO_LEN          (128)   //XML Error Information length

#define VS_NW_XML_FILE_FOLDER           "%c:\\xml"
#define VS_NW_XML_RESULT_FILE           "%c:\\xml\\xml_result.txt"
#define VS_NW_XML_SAMPLE_FILE           "%c:\\xml\\xml_sample.xml"
#define VS_NW_WBXML_RESULT_FILE         "%c:\\xml\\wbxml_result.txt"
#define VS_NW_WBXML_SAMPLE_FILE         "%c:\\xml\\wbxml_sample.xml"


typedef struct
{
    XML_PARSER_STRUCT   xml_parser;
    FS_HANDLE           xml_parser_file;
} vs_nw_xml_parser_context_struct;


typedef struct
{
    FS_HANDLE           wbxml_parser_file;
} vs_nw_wbxml_parser_context_struct;

/* Define the xml paser type */
typedef enum
{
    PARSER_XML_FROM_BUFFER,      /* Parser file from buffer */
    PARSER_XML_FROM_FILE,        /* Parser file from file */
    PARSER_XML_FROM_FILE_OFFSET, /* Parser file from file offset */
    PARSER_XML_TYPE_END          /* END */
} XML_PARSER_TYPE_ENUM;

/* Define the generator type */
typedef enum
{
    GENERATOR_XML,              /* Basic Generator */
    GENERATOR_XML_FILE,         /* Generator from file */
    GENERATOR_XML_TYPE_END      /* END */
} XML_GENERATOR_TYPE_ENUM;

/* Define the wbxml paser type */
typedef enum
{
    PARSER_WBXML_FROM_BUFFER,      /* Parser file from buffer */
    PARSER_WBXML_FROM_FILE,        /* Parser file from file */
    PARSER_WBXML_TYPE_END          /* END */
} WBXML_PARSER_TYPE_ENUM;


typedef struct tagTAGTOKEN
{
    char *tag_name;
    int  tag_ref;
}TAGTOKEN;

typedef struct tagATTRSTARTTOKEN
{
    char* name;
    char* prefix;
    int ref;
}ATTRSTARTTOKEN;

typedef struct tagATTRVALUETOKEN
{
    char* value;
    int ref;
}ATTRVALUETOKEN;

const static TAGTOKEN tag_tokens_vs_nw_xml[] = {
    {"bookshop", 0x05},
    {"book1", 0x06},
    {"contact", 0x07},
    {"address", 0x08},
    {"email", 0x09},
    {"book2", 0x0A},
    {"book3", 0x0B},    
    {NULL, 0},
};

const static ATTRSTARTTOKEN attrstart_tokens_vs_nw_xml[] = {
    {"street", NULL, 0x05},
    {"city", NULL, 0x06},
    {"auther", NULL, 0x07},
    {"sex", NULL, 0x08},
    {"country", NULL, 0x09},
    {NULL, NULL, 0},
};

const static ATTRVALUETOKEN attrvalue_tokens_vs_nw_xml[] = {
    {"Beijing", 0x85},
    {"China", 0x86},
    {"Jonh", 0x87},
    {"Male", 0x88},
    {NULL, 0},    
};
/***************************************************************************** 
* XML test begin
*****************************************************************************/

/***************************************************************************** 
* XML test static global variable
*****************************************************************************/
static vs_nw_xml_parser_context_struct g_vs_nw_xml_parser_cntx;     //global XML parser context struct
static vs_nw_wbxml_parser_context_struct g_vs_nw_wbxml_parser_cntx; //global WBXML parser context struct

/***************************************************************************** 
* XML test static function list
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vs_nw_xml_create_folder
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL vs_nw_xml_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar xml_file_folder[VS_NW_XML_FILE_PATH_LEN];
    kal_int32 driver = 0;
    FS_HANDLE   fs_handler = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the xml folder is exist or not */
    driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
    memset(xml_file_folder, 0, sizeof(xml_file_folder));
    kal_wsprintf((kal_uint16 *)xml_file_folder, VS_NW_XML_FILE_FOLDER, driver);
    kal_prompt_trace(MOD_MMI, "xml file folder drive: %d\r\n", driver);

    fs_handler = FS_Open(xml_file_folder, (FS_OPEN_DIR | FS_READ_ONLY));

    /* if the first come in the XML App */
    if (fs_handler < FS_NO_ERROR)
    {
        /* if the folder is not exist, create it first */
        fs_handler = FS_CreateDir(xml_file_folder);
    
        if (fs_handler < FS_NO_ERROR)
        {
            /* create default folder failed! */
            return  FALSE;
        }
        else    /* create the floder success */
        {
            /* close the folder */
            FS_Close(fs_handler);
        }
    }
    else    /* close the folder */
    {
        FS_Close(fs_handler);
    }
    return  TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_xml_parser_doctype_start_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  data              [IN]        Reserved
 *  doctypeName       [IN]        Document type name string
 *  sysid             [IN]        System external id list
 *  pubid             [IN]        Public external id list
 *  internal_subset   [IN]        Internal subset presence
 *  error             [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_xml_parser_doctype_start_handler(
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
    kal_uint32  index = 0, length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (XML_NO_ERROR != error)
    {
        kal_char    *err_info = NULL;
        kal_char    *err_str = NULL;

        err_info = (kal_char *)get_ctrl_buffer(VS_NW_XML_ERR_INFO_LEN);
        memset(err_info, 0, VS_NW_XML_ERR_INFO_LEN);
        
        err_str = xml_get_err_string(&g_vs_nw_xml_parser_cntx.xml_parser);
        kal_wsprintf((kal_uint16*)err_info, "Error string in %s data: %s\r\n", doctypeName, err_str);
        kal_prompt_trace(MOD_MMI, err_info);
        
        FS_Write(g_vs_nw_xml_parser_cntx.xml_parser_file, err_info, strlen(err_info), (kal_uint32*)&length);

        free_ctrl_buffer(err_info);
        err_info = NULL;
    }
    index = 0;
    if (NULL != sysid)
    {
        while (sysid[index])
        {
            FS_Write(g_vs_nw_xml_parser_cntx.xml_parser_file, (WCHAR*)sysid[index], strlen(sysid[index]), (kal_uint32*)&length);
            FS_Write(g_vs_nw_xml_parser_cntx.xml_parser_file, (void *)"\r\n", 2, (kal_uint32*)&length);
            index++;
        }
    }
    index = 0;
    if (NULL != pubid)
    {
        while (pubid[index])
        {
            FS_Write(g_vs_nw_xml_parser_cntx.xml_parser_file, (WCHAR*)pubid[index], strlen(pubid[index]), (kal_uint32*)&length);
            FS_Write(g_vs_nw_xml_parser_cntx.xml_parser_file, (void *)"\r\n", 2, (kal_uint32*)&length);
            index++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_xml_parser_doctype_start_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  data        [IN]        Reserved
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_xml_parser_doctype_end_handler(void *data, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Pause XML Parser */
    xml_pause_parse(&g_vs_nw_xml_parser_cntx.xml_parser);
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_xml_parser_elem_start_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  attr        [IN]        Attribute list
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_xml_parser_elem_start_handler(void *data, const kal_char *el, const kal_char **attr, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0, length = 0;
    kal_char    *err_str = NULL;
    kal_char    *elem_info = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    elem_info = (kal_char *)get_ctrl_buffer(VS_NW_XML_ELEM_START_LEN);
    memset(elem_info, 0, VS_NW_XML_ELEM_START_LEN);

    if (XML_NO_ERROR != error)
    {
        err_str = xml_get_err_string(&g_vs_nw_xml_parser_cntx.xml_parser);
        strcat(elem_info, "Error string in element ");
        strcat(elem_info, el);
        strcat(elem_info, ":");
        strcat(elem_info, err_str);
        strcat(elem_info, "\r\n");
    }
    
    strcat(elem_info, "<");
    strcat(elem_info, el);
    strcat(elem_info, " ");
    while ((NULL != attr[index]) && (NULL != attr[index+1]))
    {
        strcat(elem_info, attr[index]);
        strcat(elem_info, " = ");
        strcat(elem_info, attr[index+1]);
        strcat(elem_info, "; ");
        index += 2;
    }
    strcat(elem_info, ">");
    strcat(elem_info, "\r\n");
    
    kal_prompt_trace(MOD_MMI, elem_info);
    
    FS_Write(g_vs_nw_xml_parser_cntx.xml_parser_file, elem_info, strlen(elem_info), (kal_uint32*)&length);
    
    free_ctrl_buffer(elem_info);
    elem_info = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_xml_parser_elem_end_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_xml_parser_elem_end_handler(void *data, const kal_char *el, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char    *end_tag;
    kal_int32   length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    end_tag = (kal_char *)get_ctrl_buffer(VS_NW_XML_ELEM_END_LEN);
    memset(end_tag, 0, VS_NW_XML_ELEM_END_LEN);
    
    if (XML_NO_ERROR != error)
    {
        kal_char    *err_str = NULL;
        
        err_str = xml_get_err_string(&g_vs_nw_xml_parser_cntx.xml_parser);
        strcat(end_tag, "Error string in element ");
        strcat(end_tag, el);
        strcat(end_tag, ":");
        strcat(end_tag, err_str);
        strcat(end_tag, "\r\n");
    }
    strcat(end_tag, "</");
    strcat(end_tag, el);
    strcat(end_tag, ">");
    strcat(end_tag, "\r\n");

    kal_prompt_trace(MOD_MMI, end_tag);
    FS_Write(g_vs_nw_xml_parser_cntx.xml_parser_file, end_tag, strlen(end_tag), (kal_uint32*)&length);

    free_ctrl_buffer(end_tag);
    end_tag = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_xml_parser_data_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  resv        [IN]        reserved
 *  el          [IN]        Element name
 *  data        [IN]        Data string
 *  len         [IN]        Data string length
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_xml_parser_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (XML_NO_ERROR != error)
    {
        kal_char    *err_info = NULL;
        kal_char    *err_str = NULL;

        err_info = (kal_char *)get_ctrl_buffer(VS_NW_XML_ERR_INFO_LEN);
        memset(err_info, 0, VS_NW_XML_ERR_INFO_LEN);
        
        err_str = xml_get_err_string(&g_vs_nw_xml_parser_cntx.xml_parser);
        kal_wsprintf((kal_uint16*)err_info, "Error string in %s data: %s\r\n", el, err_str);
        kal_prompt_trace(MOD_MMI, err_info);
        
        FS_Write(g_vs_nw_xml_parser_cntx.xml_parser_file, err_info, strlen(err_info), (kal_uint32*)&length);    

        free_ctrl_buffer(err_info);
        err_info = NULL;
    }
    kal_prompt_trace(MOD_MMI, data);
    kal_prompt_trace(MOD_MMI, "\r\n");
    
	if(len > 0)
    {
        FS_Write(g_vs_nw_xml_parser_cntx.xml_parser_file, (void*)data, strlen(data), (kal_uint32*)&length); 
        FS_Write(g_vs_nw_xml_parser_cntx.xml_parser_file, (void*)"\r\n", 2, (kal_uint32*)&length); 
    }
    else
    {
        FS_HANDLE   fs_handler = -1;
        kal_int32   size = 0, realsize = 0;
        kal_char    *file_info = NULL;
        fs_handler = FS_Open((const WCHAR *)data, FS_READ_ONLY);
        if(fs_handler >= 0)
        {
            FS_GetFileSize(fs_handler, (kal_uint32 *)&size);
            if(size >= MAX_CTRL_BUFFER_SIZE/2)
            {
                file_info = (kal_char *)get_ctrl_buffer(MAX_CTRL_BUFFER_SIZE/2);
                while(size > 0)
                {
                    FS_Read(fs_handler, file_info, MAX_CTRL_BUFFER_SIZE/2, (kal_uint32 *)&realsize);
                    FS_Write(g_vs_nw_xml_parser_cntx.xml_parser_file, file_info, realsize, NULL);
                    size -= (MAX_CTRL_BUFFER_SIZE/2);
                }
                free_ctrl_buffer(file_info);
            }
            else
            {
                file_info = (kal_char *)get_ctrl_buffer(size);
                FS_Read(fs_handler, file_info, size, (kal_uint32 *)&realsize);
                FS_Write(g_vs_nw_xml_parser_cntx.xml_parser_file, file_info, realsize, NULL);
                free_ctrl_buffer(file_info);
            }
            FS_Close(fs_handler);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  vs_nw_xml_parser_malloc_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  buff_size        [IN]        buffer size of malloc
 * RETURNS
 *  void
 *****************************************************************************/
static void *vs_nw_xml_parser_malloc_handler(kal_int32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (get_ctrl_buffer(buff_size));
}

/*****************************************************************************
 * FUNCTION
 *  vs_nw_xml_parser_malloc_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  buff_ptr        [IN]        point of buffer to free
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_xml_parser_free_handler(void * buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_ctrl_buffer(buff_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  vs_other_xml_parser_sub
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_other_xml_parser_sub(XML_PARSER_TYPE_ENUM type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 xml_result = 0;
    kal_wchar xml_parser_result_file[VS_NW_XML_FILE_PATH_LEN];
    kal_wchar xml_parser_file[VS_NW_XML_FILE_PATH_LEN];
    kal_int32 ret, driver, wsize = 0;
    FS_HANDLE MyHandle;
    kal_char  *error_str = NULL;
    void *vbuffer;

    /*Alloc memory*/
    //applib_mem_ap_register(APPLIB_MEM_AP_ID_VS_TEST, STR_GLOBAL_1, IMG_GLOBAL_L1, vs_other_xml_parser_alloc_cb);
    //vbuffer = (kal_char *)applib_mem_ap_alloc(APPLIB_MEM_AP_ID_VS_TEST, XML_VIRFILE_MIN);
	vbuffer=(kal_char *)AVK_MALLOC(XML_VIRFILE_MIN);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "vs_nw_xml_001_xml_parser function test\n");

    /* New XML Parser */
    xml_result = xml_new_parser(&g_vs_nw_xml_parser_cntx.xml_parser);
    if (XML_RESULT_OK != xml_result)
    {
       AVK_LOG_FUN(xml_new_parser,AVK_FAIL);
       return;
    } else {
	   AVK_LOG_FUN(xml_new_parser,AVK_PASS);
	}

    if (PARSER_XML_FROM_BUFFER == type)
    {
        memset(vbuffer, 0, XML_VIRFILE_MIN);
        /* New XML Parser */
        xml_result = xml_new_parser_ext(&g_vs_nw_xml_parser_cntx.xml_parser, (kal_char *)vbuffer,XML_VIRFILE_MIN);
        if (XML_RESULT_OK != xml_result)
        {
           AVK_LOG_FUN(xml_new_parser_ext,AVK_FAIL);
           return;
        }else{
		   AVK_LOG_FUN(xml_new_parser_ext,AVK_PASS);
		}
    }
    
    /* create the xml folder if it is not exist */
    vs_nw_xml_create_folder();

    /* get file path and name */
    driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
    memset(xml_parser_result_file, 0, sizeof(xml_parser_result_file));
    kal_wsprintf((kal_uint16 *)xml_parser_result_file, VS_NW_XML_RESULT_FILE, driver);
    kal_prompt_trace(MOD_MMI, "xml parser result file drive: %d\r\n", driver);
    
    /* create and open xml parse result file */
    g_vs_nw_xml_parser_cntx.xml_parser_file = FS_Open(xml_parser_result_file, (FS_READ_WRITE | FS_CREATE_ALWAYS));
    kal_prompt_trace(MOD_MMI, "xml parser result file handle: %d\r\n", g_vs_nw_xml_parser_cntx.xml_parser_file);
    if (g_vs_nw_xml_parser_cntx.xml_parser_file < FS_NO_ERROR)
    {
        /* Close XML Parser*/
        xml_close_parser(&g_vs_nw_xml_parser_cntx.xml_parser);
        return;
    }

    /* register xml parser document handler */
    xml_register_doctype_handler(
        &g_vs_nw_xml_parser_cntx.xml_parser,
        vs_nw_xml_parser_doctype_start_handler,
        vs_nw_xml_parser_doctype_end_handler);

    /* register xml parser element handler */
    xml_register_element_handler(
        &g_vs_nw_xml_parser_cntx.xml_parser,
        vs_nw_xml_parser_elem_start_handler,
        vs_nw_xml_parser_elem_end_handler);

    /* register xml parser data handler */
    xml_register_data_handler(
        &g_vs_nw_xml_parser_cntx.xml_parser,
        vs_nw_xml_parser_data_handler);
		
    /* register xml parser memory handler */
    xml_configure_memory(
        &g_vs_nw_xml_parser_cntx.xml_parser,
        vs_nw_xml_parser_malloc_handler,
        vs_nw_xml_parser_free_handler);

    /* Get sourcce XML file path*/
    memset(xml_parser_file, 0, sizeof(xml_parser_file));
    kal_wsprintf(xml_parser_file, VS_NW_XML_SAMPLE_FILE, driver);

    MyHandle = FS_CheckFile(xml_parser_file);
    if ( MyHandle >= FS_NO_ERROR)
    {
        FS_Delete(xml_parser_file);
    } 
    FS_Close(MyHandle);
    
    MyHandle = FS_Open(xml_parser_file, FS_CREATE | FS_READ_WRITE);
    if (MyHandle >= FS_NO_ERROR)
    {
       FS_Write(MyHandle, (void *)xml_sample_buffer, sizeof(xml_sample_buffer), (UINT *)&wsize);
	   FS_Close(MyHandle);
     }else{
       ASSERT(0);
     }

    /*Move the pointer to beginning*/
    g_vs_nw_xml_parser_cntx.xml_parser.pos = FS_FILE_BEGIN;

    switch (type)
    {
        case PARSER_XML_FROM_BUFFER:
            /* XML Parser start from buffer */
            xml_result = xml_parse_buffer(&g_vs_nw_xml_parser_cntx.xml_parser, xml_sample_buffer, strlen(xml_sample_buffer));    
			AVK_LOG_FUN(xml_parse_buffer,(XML_RESULT_OK == xml_result));
			break;
        case PARSER_XML_FROM_FILE:
            /* XML Parser start from file */
            xml_result = xml_parse(&g_vs_nw_xml_parser_cntx.xml_parser, xml_parser_file);
			AVK_LOG_FUN(xml_parse,(XML_RESULT_OK == xml_result));
            break;
        case PARSER_XML_FROM_FILE_OFFSET:
            MyHandle = FS_Open(xml_parser_file, FS_READ_ONLY);
            g_vs_nw_xml_parser_cntx.xml_parser.pos = FS_FILE_BEGIN;
            /* XML Parser start from file */
            xml_result = xml_parse_file_from_offset(&g_vs_nw_xml_parser_cntx.xml_parser, MyHandle);
			AVK_LOG_FUN(xml_parse_file_from_offset,(XML_RESULT_OK == xml_result));
            break;
    }
    /* Resume XML Parser */
    ret = xml_resume_parse(&g_vs_nw_xml_parser_cntx.xml_parser);
	AVK_LOG_FUN(xml_resume_parse,(XML_RESULT_OK == xml_result));

    /* Free XML Parser */
    xml_free_parse(&g_vs_nw_xml_parser_cntx.xml_parser);
	
    
    /* Stop XML Parser */
    xml_stop_parse(&g_vs_nw_xml_parser_cntx.xml_parser);
	
    switch (type)
    {
        case PARSER_XML_FROM_BUFFER:
            ;
        case PARSER_XML_FROM_FILE:
            /* Close XML Parser*/
            xml_close_parser(&g_vs_nw_xml_parser_cntx.xml_parser);
			AVK_LOG_FUN(xml_close_parser, MMI_TRUE);
            break;
        case PARSER_XML_FROM_FILE_OFFSET:

            /* Close XML Parser*/
            xml_close_parser_offset(&g_vs_nw_xml_parser_cntx.xml_parser);
			AVK_LOG_FUN(xml_close_parser_offset, MMI_TRUE);
            FS_Close(MyHandle);
            break;
    }  

    /* Close the XML Parser result file */
    FS_Close(g_vs_nw_xml_parser_cntx.xml_parser_file);

    /* Free memory*/
    //applib_mem_ap_free(vbuffer);
    AVK_FREE(vbuffer);
	
    /* Show the popup message */
	AVK_LOG_FUN(xml_register_doctype_handler,(XML_RESULT_OK == xml_result));
	AVK_LOG_FUN(xml_register_element_handler,(XML_RESULT_OK == xml_result));
	AVK_LOG_FUN(xml_register_data_handler,(XML_RESULT_OK == xml_result));
	AVK_LOG_FUN(xml_configure_memory,(XML_RESULT_OK == xml_result));
	AVK_LOG_FUN(xml_pause_parse,(XML_RESULT_OK == xml_result));
	AVK_LOG_FUN(xml_resume_parse,(XML_RESULT_OK == xml_result));
	AVK_LOG_FUN(xml_stop_parse,(XML_RESULT_OK == xml_result));
	AVK_LOG_FUN(xml_free_parse,(XML_RESULT_OK == xml_result));
	
	AVK_LOG_FUN_UNSUPPORTED(xml_get_err_string);
	
    if(XML_RESULT_OK != xml_result)
    {
       /* get XML parser error string */
       error_str = xml_get_err_string(&g_vs_nw_xml_parser_cntx.xml_parser);
       kal_prompt_trace(MOD_MMI, "xml parser error string is: %s\r\n", error_str);
       AVK_LOG_FUN(xml_get_err_string, MMI_TRUE);
    }        
}

/*****************************************************************************
 * FUNCTION
 *  tst_other_xml_parser
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_OTHER_XML_PARSER_AUTO,AVK_OTHER_XML_AUTO)
{
    vs_other_xml_parser_sub(PARSER_XML_FROM_BUFFER);
    vs_other_xml_parser_sub(PARSER_XML_FROM_FILE);
    vs_other_xml_parser_sub(PARSER_XML_FROM_FILE_OFFSET);
}

/*****************************************************************************
 * FUNCTION
 *  vs_nw_xml_002_xml_generator
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_other_xml_generator_sub(XML_GENERATOR_TYPE_ENUM type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XG_HANDLE       xml_gen_handle = -1;
    xg_attr_struct  attrlist[2];
    kal_char        *data = NULL, *dtd = NULL;
    kal_wchar       xml_generator_name[VS_NW_XML_FILE_PATH_LEN];
    kal_int32       ret, driver, len;
    FS_HANDLE       MyHandle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create the xml folder if it is not exist */
    vs_nw_xml_create_folder();
    
    driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
    kal_wsprintf((kal_uint16*)xml_generator_name, VS_NW_XML_SAMPLE_FILE, driver); 

    MyHandle = FS_CheckFile(xml_generator_name);
    if ( MyHandle >= FS_NO_ERROR)
    {
        FS_Delete(xml_generator_name);
    } 
    FS_Close(MyHandle);
    
    MyHandle = FS_Open(xml_generator_name, FS_CREATE | FS_READ_WRITE);
    if (MyHandle < FS_NO_ERROR)
    {
        return;//ASSERT(0); //Create File Fail
    }    

    switch (type)
    {
        case GENERATOR_XML:
            FS_Close(MyHandle);
            /* XML generator data to file */
            xml_gen_handle = xml_new_generator((kal_char*)xml_generator_name, 0);
			AVK_LOG_FUN(xml_new_generator,(xml_gen_handle >= 0));
            break;
        case GENERATOR_XML_FILE:
            xml_gen_handle = xml_new_generator_file(MyHandle);
			AVK_LOG_FUN(xml_new_generator_file,(xml_gen_handle >= 0));
            break;
        default:
            ASSERT(0);
    }
    
    if(xml_gen_handle >= 0)
    {
        /* XML generator xml declaration "<?xml version="1.0¡° encoding=¡°UTF-8¡± ?>" */
        ret = xml_generate_xmldecl(xml_gen_handle, "1.0", XML_ENCODING_UTF8);
        AVK_LOG_FUN(xml_generate_xmldecl, ret==0);
		
        /* XML generate document type declaration */
		if (GENERATOR_XML == type) {
        ret = xml_generate_doctypedecl(xml_gen_handle, "bookshop", XG_DOCTYPE_PUBLIC, "bookshop.dtd");
		AVK_LOG_FUN(xml_generate_doctypedecl, ret==0);
		
        dtd = "<!ELEMENT greeting (#PCDATA)>\n<!ELEMENT description (#PCDATA)>\n<!ELEMENT contact (#PCDATA)>\n<!ELEMENT address (#PCDATA)>\n<!ELEMENT email (#PCDATA)>\n<!ELEMENT msn (#PCDATA)>\n<!ENTITY copyright \"Copyright 2008\">";
        len = strlen(dtd);
		} else {
        	dtd = "<!ELEMENT greeting (#PCDATA)>\n<!ELEMENT description (#PCDATA)>\n<!ELEMENT contact (#PCDATA)>\n<!ELEMENT address (#PCDATA)>\n<!ELEMENT email (#PCDATA)>\n<!ELEMENT msn (#PCDATA)>\n<!ENTITY copyright \"Copyright 2008\">";
        	len = strlen(dtd);
        	ret = xml_generate_doctypedecl_ex(xml_gen_handle, "bookshop", dtd, len);
			
			AVK_LOG_FUN(xml_generate_doctypedecl_ex, ret==0);
		}
    
        /*  to generate:  <bookshop> */
        ret = xml_generate_stag(xml_gen_handle, "bookshop", NULL, 0);
		AVK_LOG_FUN(xml_generate_stag, ret==0);
     
        /* to generate: <book1>this is a book of computer</book1> */
        data = "Welcome come to my bookshop";
        ret = xml_generate_inline_element(xml_gen_handle, "greeting", data, strlen(data));
		AVK_LOG_FUN(xml_generate_inline_element, ret==0);
        
        /* to generate: <description>This is a book of computer</description> */
        data = "This is a book of computer";
        ret = xml_generate_inline_element(xml_gen_handle, "description", data, strlen(data));
        AVK_LOG_FUN(xml_generate_inline_element, ret==0);
			
        /*  to generate:  <contact> */
        ret = xml_generate_stag(xml_gen_handle, "contact", NULL, 0);
		AVK_LOG_FUN(xml_generate_stag, ret==0);
        
        /* to generate: <address street="Xi Dan Street"/> */
        attrlist[0].attrname = "street";
        attrlist[0].attrvalue = "Xi Dan Street";
        attrlist[1].attrname = "code";
        attrlist[1].attrvalue = "100022";
        ret = xml_generate_empty_element(xml_gen_handle, "address", attrlist, 2);
		AVK_LOG_FUN(xml_generate_empty_element, ret==0);
      
        /* to generate: <email>[![CDATA[bookshop@sohu.com]]></email> */
        ret = xml_generate_stag(xml_gen_handle, "email", NULL, 0);
		AVK_LOG_FUN(xml_generate_stag, ret==0);
        
        /* to generate: [![CDATA[bookshop@sohu.com]] */
        data = "bookshop@sohu.com";
        ret = xml_generate_cdata(xml_gen_handle, data, strlen(data));
		AVK_LOG_FUN(xml_generate_cdata, ret==0);
        
        /* to generate: </email> */
        ret = xml_generate_etag(xml_gen_handle, "email");
		AVK_LOG_FUN(xml_generate_etag, ret==0);
        
        /* to generate: <msn>iamlixia@hotmail.com</msn> */
        ret = xml_generate_stag(xml_gen_handle, "msn", NULL, 0);
		AVK_LOG_FUN(xml_generate_stag, ret==0);
        
        data = "iamlixia@hotmail.com";
        ret = xml_generate_data(xml_gen_handle, data, strlen(data));
		AVK_LOG_FUN(xml_generate_data, ret==0);
        
        ret = xml_generate_etag(xml_gen_handle, "msn");
		AVK_LOG_FUN(xml_generate_etag, ret==0);
        
        /* to generate: </contact> */
        ret = xml_generate_etag(xml_gen_handle, "contact");
		AVK_LOG_FUN(xml_generate_etag, ret==0);
        
        /* to generate: </sample> */
        ret = xml_generate_etag(xml_gen_handle, "bookshop");
		AVK_LOG_FUN(xml_generate_etag, ret==0);
    
        /* close xml generator */
        ret = xml_close_generator(xml_gen_handle);
		AVK_LOG_FUN(xml_close_generator, ret>=0);
		
        if (GENERATOR_XML_FILE == type )
        {
            FS_Close(MyHandle);
        }
      
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  tst_other_xml_parser
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_OTHER_XML_GENERATOR_AUTO,AVK_OTHER_XML_AUTO)
{
    vs_other_xml_generator_sub(GENERATOR_XML);
    vs_other_xml_generator_sub(GENERATOR_XML_FILE);
}

/*****************************************************************************
 * FUNCTION
 *  vs_nw_wbxml_parser_header_handler
 * DESCRIPTION
 *  this function is used as element start handler when testing.
 * PARAMETERS
 *  resv        [IN]        reserved
 *  publicid    [IN]        Public identifier
 *  charset     [IN]        Charset encoding
 *  mainver     [IN]        Main version
 *  subver      [IN]        Sub version
 * RETURNS
 *  void
 *****************************************************************************/
void vs_nw_wbxml_parser_header_handler(void *resv, kal_char *publicid, kal_uint32 charset, kal_uint8 mainver, kal_uint8 subver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  length = 0;
    kal_char    version_info[VS_NW_XML_FILE_PATH_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL != publicid)
    {
        kal_prompt_trace(MOD_MMI, publicid);
        FS_Write(g_vs_nw_wbxml_parser_cntx.wbxml_parser_file, publicid, strlen(publicid), (kal_uint32*)&length);
        FS_Write(g_vs_nw_wbxml_parser_cntx.wbxml_parser_file, (void *)"\r\n", 2, &length);

        kal_sprintf(version_info, "%d.%d\r\n", (kal_int8)mainver, (kal_int8)subver);
        FS_Write(g_vs_nw_wbxml_parser_cntx.wbxml_parser_file, version_info, strlen(version_info), &length);
    }
}

/*****************************************************************************
 * FUNCTION
 *  vs_nw_wbxml_parser_elem_stag_handler
 * DESCRIPTION
 *  this function is used as element start handler when testing.
 * PARAMETERS
 *  resv        [IN]        reserved
 *  el          [IN]        Element name
 *  attr        [IN]        Attribution list
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_wbxml_parser_elem_stag_handler(void *resv, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  index = 0, length = 0;
    kal_char    *elem_info = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    elem_info = (kal_char *)get_ctrl_buffer(VS_NW_XML_ELEM_START_LEN);
    memset(elem_info, 0, VS_NW_XML_ELEM_START_LEN);
    
    strcat(elem_info, "<");
    strcat(elem_info, el);
    strcat(elem_info, " ");
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        strcat(elem_info, attr[index]);
        strcat(elem_info, " = ");
        strcat(elem_info, attr[index + 1]);
        strcat(elem_info, "; ");
        index += 2;
    }
    strcat(elem_info, ">");
    strcat(elem_info, "\r\n");
    
    kal_prompt_trace(MOD_MMI, elem_info);
    FS_Write(g_vs_nw_wbxml_parser_cntx.wbxml_parser_file, elem_info, strlen(elem_info), (kal_uint32*)&length);

    free_ctrl_buffer(elem_info);
    elem_info = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wbxml_parser_elem_end_handler
 * DESCRIPTION
 *  this function is used as default element_end_handler when testing
 * PARAMETERS
 *  resv        [IN]        reserved
 *  el          [IN]        Element name
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_wbxml_parser_elem_end_handler(void *resv, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char    end_tag[VS_NW_XML_ELEM_END_LEN];
    kal_uint32  length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(end_tag, 0, sizeof(end_tag));
    strcat(end_tag, "</");
    strcat(end_tag, el);
    strcat(end_tag, ">");
    strcat(end_tag, "\r\n");
    
    kal_prompt_trace(MOD_MMI, end_tag);
    FS_Write(g_vs_nw_wbxml_parser_cntx.wbxml_parser_file, end_tag, strlen(end_tag), (kal_uint32*)&length);
    
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wbxml_parser_data_handler
 * DESCRIPTION
 *  this function is used as general data handler when testing
 * PARAMETERS
 *  resv        [IN]        reserved
 *  el          [IN]        Element name
 *  data        [IN]        Data to be handled
 *  len         [IN]        Length of data   
 *  datataype   [IN]        data type of data(1:string; 2:opaque; 3: entity; 4:extension; 5: mixed)
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_wbxml_parser_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_uint32 len, kal_uint8 datatype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 != len)
    {
        kal_prompt_trace(MOD_MMI, data);
        kal_prompt_trace(MOD_MMI, "\r\n");
        FS_Write(g_vs_nw_wbxml_parser_cntx.wbxml_parser_file, (void*)data, len, &length);
        FS_Write(g_vs_nw_wbxml_parser_cntx.wbxml_parser_file, (void*)"\r\n", 2, &length);
    }
    else
    {
        kal_prompt_trace(MOD_MMI, "data is saved in file");
        kal_prompt_trace(MOD_MMI, "\r\n");
        FS_Write(g_vs_nw_wbxml_parser_cntx.wbxml_parser_file, (void*)"data is saved in file", strlen("data is saved in file"), &length);
        FS_Write(g_vs_nw_wbxml_parser_cntx.wbxml_parser_file, (void*)"\r\n", 2, &length);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wbxml_parser_get_tagname_by_token
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 *  ptr             [IN]        buf to save tag name
 *  tagcp           [IN]        tag space code page
 *  token           [IN]        token of tag
 * RETURNS
 *  if < 0: failed
 *****************************************************************************/
static kal_int32 vs_nw_wbxml_parser_get_tagname_by_token(kal_char *ptr, kal_uint32 tagcp, kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    kal_int32   length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(1)
    {
        if (NULL == tag_tokens_vs_nw_xml[index].tag_name)
        {
            /* cannot find token in tag token space */
            return 0;
        }
        if (tag_tokens_vs_nw_xml[index].tag_ref == token)
        {
            length = strlen(tag_tokens_vs_nw_xml[index].tag_name);
            if (length < WBXML_MAX_BUFFER_SIZE)
            {
                strcpy(ptr, tag_tokens_vs_nw_xml[index].tag_name);
                return (length);
            }
            else    /* length is over 2k */
            {
                return (-1);
            }
        }
        index++;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wbxml_parser_get_attrname_by_token
 * DESCRIPTION
 *  this function is used to get attrname by token 
 * PARAMETERS
 *  ptr             [IN]        buf to save attribute name or attribute value
 *  prefix          [IN]        buf to save attribute value prefix if prefix is exsit in attrstart
 *  attrcp          [IN]        attribute code page
 *  token           [IN]        token of attrstart or attrvalue
 * RETURNS
 *  if < 0, failed
 *****************************************************************************/
static kal_int32 vs_nw_wbxml_parser_get_attrname_by_token(kal_char *ptr, kal_char *prefix, kal_uint32 attrcp, kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    kal_int32   length1 = 0, length2 = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (token < 128) /* attrstart token */
    {
        while(1)
        {
            if (NULL == attrstart_tokens_vs_nw_xml[index].name)
            {
                /* cannot find token in tag token space */
                return 0;
            }
            if (attrstart_tokens_vs_nw_xml[index].ref == token)
            {
                /* find token in token space */
                length1 = strlen(attrstart_tokens_vs_nw_xml[index].name);
                if (length1 < WBXML_MAX_BUFFER_SIZE)
                {
                    strcpy(ptr, attrstart_tokens_vs_nw_xml[index].name);
                }
                if (attrstart_tokens_vs_nw_xml[index].prefix != NULL)
                {
                    /* prefix is not NULL, copy it to attrvalue */
                    length2 = strlen(attrstart_tokens_vs_nw_xml[index].prefix);
                    if (length2 < WBXML_MAX_BUFFER_SIZE)
                    {
                        strcpy(prefix, attrstart_tokens_vs_nw_xml[index].prefix);
                    }
                }
                if (length1 < WBXML_MAX_BUFFER_SIZE)
                {
                    return (length1);
                }
                else    /* len is over 2k */
                {
                    return (-1);
                }
            }
            index++;
        }
    }
    else            /* attrvalue token */
    {
        while(1)
        {
            if (NULL == attrvalue_tokens_vs_nw_xml[index].value)
            {
                /* cannot find token in tag token space */
                return 0;
            }
            if (attrvalue_tokens_vs_nw_xml[index].ref == token)
            {
                length1 = strlen(attrvalue_tokens_vs_nw_xml[index].value);
                if (length1 < WBXML_MAX_BUFFER_SIZE)
                {
                    strcpy(ptr, attrvalue_tokens_vs_nw_xml[index].value);
                    return (length1);
                }
                else    /* length is over 2k */
                {
                    return (-1);
                }
            }
            index++;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wbxml_parser_malloc_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void *vs_nw_wbxml_parser_malloc_handler(kal_int32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (get_ctrl_buffer(buff_size));
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wbxml_parser_free_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vs_nw_wbxml_parser_free_handler(void * buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_ctrl_buffer(buff_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_xml_003_wbxml_parser
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vs_other_xml_wbxml_parser_sub(WBXML_PARSER_TYPE_ENUM type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WP_HANDLE   wp_handle = 0;
    kal_wchar   wbxml_parser_result_file[VS_NW_XML_FILE_PATH_LEN];
    kal_wchar   wbxml_parser_file[VS_NW_XML_FILE_PATH_LEN];
    kal_int32   ret = 0;
    kal_int32   driver = 0, wsize = 0;
    kal_char    *err_tag = NULL, *mark_data = NULL;
    kal_uint32  mark_len = 0;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* new WBXML parser */
    wp_handle = wbxml_new_parser();
	AVK_LOG_FUN(wbxml_new_parser,(wp_handle >= 0));
	
    if(wp_handle >= 0)
    {
        /* create the xml folder if it is not exist */
        vs_nw_xml_create_folder();

        /* get file path and name */
        driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
        memset(wbxml_parser_result_file, 0, sizeof(wbxml_parser_result_file));
        kal_wsprintf((kal_uint16 *)wbxml_parser_result_file, VS_NW_WBXML_RESULT_FILE, driver);
        kal_prompt_trace(MOD_MMI, "wbxml parser result file drive: %d\r\n", driver);

        /* create and open wbxml parser result file */
        g_vs_nw_wbxml_parser_cntx.wbxml_parser_file = FS_Open((WCHAR *)wbxml_parser_result_file, (FS_READ_WRITE | FS_CREATE_ALWAYS));
        kal_prompt_trace(MOD_MMI, "wbxml parser result file handle: %d\r\n", g_vs_nw_wbxml_parser_cntx.wbxml_parser_file);
        if (g_vs_nw_wbxml_parser_cntx.wbxml_parser_file >= FS_NO_ERROR)
        {
            /* WBXML Parser register header handler */
            wbxml_register_header_handler(wp_handle, vs_nw_wbxml_parser_header_handler);
			
            /* WBXML Parser register element handler */
            wbxml_register_element_handler(
                wp_handle,
                vs_nw_wbxml_parser_elem_stag_handler,
                vs_nw_wbxml_parser_elem_end_handler);
			
            /* WBXML Parser register data handler */
            wbxml_register_data_handler (wp_handle, vs_nw_wbxml_parser_data_handler);

            /* WBXML Parser register name handler */
            wbxml_register_get_name_handler(
                wp_handle,
                vs_nw_wbxml_parser_get_tagname_by_token,
                vs_nw_wbxml_parser_get_attrname_by_token);

            /* WBXML Parser configure memory functions */
            wbxml_configure_memory(
                wp_handle,
                vs_nw_wbxml_parser_malloc_handler,
                vs_nw_wbxml_parser_free_handler);
        
            /* Get sourcce WBXML file path*/
            memset(wbxml_parser_file, 0, sizeof(wbxml_parser_file));
            kal_wsprintf((WCHAR*)wbxml_parser_file, VS_NW_WBXML_SAMPLE_FILE, driver);
        
            ret = FS_CheckFile((WCHAR*)wbxml_parser_file);
            if (ret >= FS_NO_ERROR)
            {
                FS_Delete(wbxml_parser_file);
                FS_Close(ret);
            }

            ret = FS_Open((WCHAR*)wbxml_parser_file, FS_CREATE | FS_READ_WRITE);
            if (ret >= FS_NO_ERROR)
            {
                FS_Write(ret, (void *)wbxml_sample_buffer, sizeof(wbxml_sample_buffer), (UINT *)&wsize);
                FS_Close(ret);
            }else{
                ASSERT(0); //create file fail
            }
            
            if(PARSER_WBXML_FROM_FILE== type)
            {
                /* WBXML Parser start from file */
                ret = wbxml_parse(wp_handle, (kal_char*)wbxml_parser_file, 0);
            }
            
            if(PARSER_WBXML_FROM_BUFFER== type)
            {
                /* WBXML Parser start from buffer */
                ret = wbxml_parse(wp_handle, (kal_char*)wbxml_sample_buffer, 0x3D/*strlen(wbxml_sample_buffer)*/);
            }
            /* Stop WBXML Parser */
            wbxml_stop_parser(wp_handle);
        
            /* Close WBXML Parser */
            wbxml_close_parser(wp_handle);

            /* close the wbxml parser result file */
            FS_Close (g_vs_nw_wbxml_parser_cntx.wbxml_parser_file);

            mark_data = wbxml_get_ext_0(wbxml_sample_mark, &mark_len);
            mark_data = wbxml_get_ext_1(mark_data, &mark_len);
            mark_data = wbxml_get_ext_2(mark_data, &mark_len);
        
            AVK_LOG_FUN(wbxml_register_header_handler,(WBXML_RESULT_OK == ret));
			AVK_LOG_FUN(wbxml_register_element_handler,(WBXML_RESULT_OK == ret));
			AVK_LOG_FUN(wbxml_register_data_handler,(WBXML_RESULT_OK == ret));
			AVK_LOG_FUN(wbxml_register_get_name_handler,(WBXML_RESULT_OK == ret));
			AVK_LOG_FUN(wbxml_configure_memory,(WBXML_RESULT_OK == ret));
			AVK_LOG_FUN(wbxml_parse,(WBXML_RESULT_OK == ret));
			AVK_LOG_FUN(wbxml_stop_parser,(WBXML_RESULT_OK == ret));
			AVK_LOG_FUN(wbxml_close_parser,(WBXML_RESULT_OK == ret)); 
			AVK_LOG_FUN_UNSUPPORTED(wbxml_get_error_tag); 
				
        }
	}else {
		/* get wbxml parser error tag number */
        err_tag = wbxml_get_error_tag(wp_handle);
        kal_prompt_trace(MOD_MMI, "wbxml parser error tag is: %s\r\n", err_tag);
		AVK_LOG_FUN(wbxml_get_error_tag,MMI_TRUE); 
    }
	
}

/*****************************************************************************
 * FUNCTION
 *  vs_other_xml_wbxml_parser
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_OTHER_WBXML_PARSER_AUTO,AVK_OTHER_XML_AUTO)
{
    vs_other_xml_wbxml_parser_sub(PARSER_WBXML_FROM_BUFFER);
    vs_other_xml_wbxml_parser_sub(PARSER_WBXML_FROM_FILE);
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wbxml_generator_get_tagtoken_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 vs_nw_wbxml_generator_get_tagtoken_handler(const kal_char *tagname, kal_uint8 tagcp, kal_uint8 *token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(1)
    {
        if (NULL == tag_tokens_vs_nw_xml[index].tag_name)
        {
            return -1;
        }
        if (0 == strcmp(tagname, tag_tokens_vs_nw_xml[index].tag_name))
        {
            *token = tag_tokens_vs_nw_xml[index].tag_ref;
            return 0;
        }
        index++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wbxml_generator_get_attrnametoken_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 vs_nw_wbxml_generator_get_attrnametoken_handler(const kal_char *attrname, kal_uint8 attrcp, kal_uint8 *token, void *reserved)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(1)
    {
        if (NULL == attrstart_tokens_vs_nw_xml[index].name)
        {
            return -1;
        }
        if (0 == strcmp(attrname, attrstart_tokens_vs_nw_xml[index].name))
        {
            *token = attrstart_tokens_vs_nw_xml[index].ref;
            return 0;
        }
        index++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_wbxml_generator_get_attrnametoken_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 vs_nw_wbxml_generator_get_attrvaluetoken_handler(const kal_char *attrvalue, kal_uint8 attrcp, kal_uint8 *token, kal_uint8 *datatype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(1)
    {
        if (0 == attrvalue_tokens_vs_nw_xml[index].ref)
        {
             return -1;
        }
        if (0 == strcmp(attrvalue, attrvalue_tokens_vs_nw_xml[index].value))
        {
            *token = attrvalue_tokens_vs_nw_xml[index].ref;
            return 0;
        }
        index++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vs_nw_xml_004_wbxml_generator
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_OTHER_WBXML_GENERATOR_AUTO,AVK_OTHER_XML_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WG_HANDLE   wg_handle;
    kal_wchar   wbxml_generator_name[VS_NW_XML_FILE_PATH_LEN];
    xg_attr_struct  attrlist[2];
    kal_char    *data = NULL;
    kal_int32   ret, driver, index = 0;
    kal_uint32  len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create the xml folder if it is not exist */
    vs_nw_xml_create_folder();
    
    driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
    kal_wsprintf((kal_uint16*)wbxml_generator_name, VS_NW_WBXML_SAMPLE_FILE, driver); 

    /* create new WBXML Generator */
    wg_handle = wbxml_new_generator((kal_char*)wbxml_generator_name, 0);
	AVK_LOG_FUN(wbxml_new_generator,(wg_handle >= 0));
	
    if (wg_handle >= 0)
    {
        /* WBXML Generator register token handler */
        wbxml_register_get_token_handler(
            wg_handle,
            vs_nw_wbxml_generator_get_tagtoken_handler,
            vs_nw_wbxml_generator_get_attrnametoken_handler,
            vs_nw_wbxml_generator_get_attrvaluetoken_handler);
		AVK_LOG_FUN(wbxml_register_get_token_handler,1);
		
        /* WBXML generator header "<?xml version="1.0" encoding="UTF-8" ?>" */
        ret = wbxml_generate_header(
                wg_handle,                      /* WG_HANDLE */
                1,                              /* main version */
                1,                              /* sub version */
                "-//WAPFORUM//DTD WML 1.0//EN", /* public id */
                WBXML_CHARSET_UTF_8);           /* charset */
		AVK_LOG_FUN(wbxml_generate_header,ret==0);
		
        /* WBXML generator start tag */
        ret = wbxml_generate_stag(
                wg_handle,              /* WG_HANDLE */
                "bookshop",             /* element */
                0,                      /* attr_list*/
                0,                      /* attr num */
                KAL_TRUE);              /* iscontent */
		AVK_LOG_FUN(wbxml_generate_stag,ret==0);
		
        /* WBXML generator start tag */
        index = 0;
        attrlist[index].attrname = "auther";
        attrlist[index].attrvalue = "Jonh";
        index++;
        attrlist[index].attrname = "sex";
        attrlist[index].attrvalue = "Male";
        index++;
        ret = wbxml_generate_stag(
                wg_handle,              /* WG_HANDLE */
                "book1",                /* element */
                attrlist,               /* attr_list*/
                index,                  /* attr num */
                KAL_TRUE);              /* iscontent */
		AVK_LOG_FUN(wbxml_generate_stag,ret==0);
		
        /* WBXML generator data */
        data = "book1:computer book";
        len = strlen(data);
        ret = wbxml_generate_data(wg_handle, data, len, WBXML_DATA_TYPE_OPAQUE);
		AVK_LOG_FUN(wbxml_generate_data,ret==0);
		
        /* WBXML generator end tag */
        ret = wbxml_generate_etag(wg_handle, "book1");
        AVK_LOG_FUN(wbxml_generate_etag,ret>=0);
		
        /* WBXML generator inline element */
        data = "book2:artist book";
        len = strlen(data);
        ret = wbxml_generate_inline_element(
                wg_handle,                  /* WG_HANDLE */
                "book2",                    /* element */
                data,                       /* data */
                (len+1),                    /* data length */
                WBXML_DATA_TYPE_STRING);    /* data type */
		AVK_LOG_FUN(wbxml_generate_inline_element,ret>=0);
		
        /* WBXML generator empty element */
        index = 0;
        attrlist[index].attrname = "city";
        attrlist[index].attrvalue = "Beijing";
        index++;
        attrlist[index].attrname = "country";
        attrlist[index].attrvalue = "China";
        index++;
        ret = wbxml_generate_empty_element(wg_handle, "address", attrlist, index);
		AVK_LOG_FUN(wbxml_generate_empty_element,ret==0);
		
        /* WBXML generator end tag */
        ret = wbxml_generate_etag(wg_handle, "bookshop");
        AVK_LOG_FUN(wbxml_generate_etag,ret>=0);
		
        /* WBXML generator close */
        len = wbxml_close_generator(wg_handle);
		AVK_LOG_FUN(wbxml_close_generator,(S32)len >=0);
	}
	
}
