 /*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2007
 *
 *****************************************************************************/ 

 /*******************************************************************************
 * Filename:
 * ---------
 *  mmi_rp_xml.h
 *
 * Project:
 * --------
 *   Resgen XML
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *           HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 *
 * removed!
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


#ifndef RESGEN_XML_H
#define RESGEN_XML_H

#include "MMIDataType.h"
#include "mmi_res_range_def.h"

/* xmlparser defines */
typedef unsigned char  kal_uint8;
typedef unsigned short kal_uint16;
typedef unsigned long  kal_uint32;
typedef char           kal_int8;
typedef short          kal_int16;
typedef long           kal_int32;
typedef char           kal_char;
typedef unsigned short kal_wchar;


#define FS_HANDLE      FILE*

#define FS_FILE_BEGIN  SEEK_SET
#define FS_FILE_END    SEEK_END

#define FS_NO_ERROR                       0
#define FS_ERROR_RESERVED                -1
#define FS_FILE_NOT_FOUND                -9    /* User or Normal */
#define FS_MSDC_READ_SECTOR_ERROR      -101    /* Normal */

#define MMI_RP_OUTPUT_ENUM_NAME_MAX 100

// Frederic: TBC
////////////////////////////////////////////////
// Resoure file output mask
////////////////////////////////////////////////
#define RES_LEGACY_POP_NON 0x00
#define RES_LEGACY_POP_STRING_MASK 0x01
#define RES_LEGACY_POP_IMAGE_MASK 0x02
#define RES_LEGACY_POP_AUDIO_MASK 0x04
#define RES_LEGACY_POP_BINARY_MASK 0x08
#define RES_LEGACY_POP_MENU_MASK 0x10
#define RES_LEGACY_POP_SCREEN_MASK 0x20
#define RES_LEGACY_POP_TIMER_MASK 0x40
#define RES_LEGACY_POP_CUSTOM_MASK 0x80

typedef enum 
{
    KAL_FALSE,
    KAL_TRUE
} kal_bool;


#define OslMalloc(nob)  malloc(nob)
#define OslMfree(frp)   free(frp)
/* ---------------------------End------------------------- */

#ifndef ASSERT
#define ASSERT(x) {if(!x)while(1){}}
#endif

typedef enum 
{
    RP_WARN_RES_ID_NULL,
    RP_WARN_APP_PACKAGE_NAME_UNKNOWN,
    RP_WARN_UNKNOW_ATTR,
    RP_WARN_INVALID_CONT,
    RP_WARN_USE_ERROR,
    RP_WARN_USE_ERROR_MENUSET,
    RP_WARN_USE_ERROR_SEPARATOR,
    RP_WARN_DUPLICATE_ID,
    RP_WARN_RES_COUNT_ZERO,
    RP_WARN_CHILD_MENU_ID_NOT_FOUND,
    RP_WARN_GROUP_NAME_NOT_FOUND,
    RP_WARN_HASH_SAME_STRING,
    RP_WARN_MEM_CONFIG_NOT_SPECIFIED,
    RP_WARN_BUFFER_LENGTH_EXCEEDED,
    RP_WARN_DUPLICATE_UNIQUE_KEY,
    RP_WARN_UNKNOWN_VAL,
    RP_WARN_TOTAL
} MMI_RP_PARSE_WARNING_TYPE;

typedef enum 
{
    RP_ERR_APP_UNKNOWN,
    RP_ERR_APP_PACKAGE_NAME_MISSING,
    RP_ERR_TAG_UNKNOWN,
    RP_ERR_UNKNOWN_ATTR,
    RP_ERR_TAG_OPEN_TWICE,
    RP_ERR_MENU_PARENT_STACK_OVERFLOW_ERROR,
    RP_ERR_TAG_STACK_OVERFLOW, 
    RP_ERR_TAG_STACK_UNDERFLOW,
    RP_ERR_TAG_USE_ERROR,
    RP_ERR_TAG_ENFB_OPEN_TWICE, 
    RP_ERR_TAG_ENFB_CLOSE_TWICE,
    RP_ERR_TAG_MENUITEM_ID_NOT_SPECIFIED,
    RP_ERR_TAG_MENUSET_ID_NOT_SPECIFIED,
    RP_ERR_TAG_APP_END,
    RP_ERR_PATH_TYPE_NOT_FOUND,
    RP_ERR_TAG_NOT_SUPPORT_DATA,
    RP_ERR_EXCEED_ID_RANGE,
    RP_ERR_EXCEED_CHILDREN_MENU_SIZE,
    RP_ERR_MEMORY_NOT_AVAILABLE,
    RP_ERR_WRITE_OUPUT_PHASE1,
    RP_ERR_WRITE_OUPUT_PHASE2,
    RP_ERR_ID_NOT_FOUND,
    RP_ERR_MEM_CONFIG_NOT_SUFFICIENT_DATA,
    RP_ERR_MEM_CONFIG_CONCURRENT_APPS_EXCEED,
    RP_ERR_MEM_CONFIG_APP_DATA_ALREADY_DECLARED,
    RP_ERR_MEM_CONFIG_APP_NAME_STR_ID_NOT_FOUND,
    RP_ERR_STRING_MISSING_ENCLOSING_QUOTES,
    RP_ERR_MENU_SHORTCUT_EXCEED_MAX_RANGE,
    RP_ERR_MENU_SHORTCUT_NO_LAUNCH_FUNC,
    RP_ERR_MENU_SHORTCUT_IMAGE_ID_NOT_SPECIFIED,
    RP_ERR_MENU_SHORTCUT_IMAGE_ID_NOT_FOUND,
    RP_ERR_BUFFER_LENGTH_EXCEEDED,
    RP_ERR_VAL_UNKNOWN,
    RP_ERR_DUPLICATE_UNIQUE_KEY,
    RP_ERR_MMI_CACHE_TOO_MANY_FIELD,
    RP_ERR_UNKNOWN_PARSE_ERROR,
    RP_ERR_UNKNOWN_GENERIC_ERROR,
    RP_ERR_TOTAL
} MMI_RP_PARSE_ERROR_TYPE;

typedef enum
{
    MMI_RP_COMPARE_INC_FILES,
    MMI_RP_COMPARE_SRC_FILES,
    MMI_RP_COMPARE_CUSTRESOURCE_FILES,
    MMI_RP_COMPARE_TOTAL
}mmi_rp_compare_files_enum;

extern void mmi_rp_mgr_trace_warning(U32 index, U8* string);
extern void mmi_rp_mgr_trace_error(U32 index, U8* string);

#define  MMI_RP_ERROR_TRACE_LINE(x) {printf("\nLine # %d\tFile # %s\n", __LINE__, __FILE__);}
#define  MMI_RP_ERROR_EXIT(x) {printf("\nLine # %d\tFile # %s\n", __LINE__, __FILE__); exit(2);}

#define  MMI_RP_PARSE_WARNING(x) mmi_rp_mgr_trace_warning(x, NULL);
#define  MMI_RP_PARSE_WARNING_DATA(x,s) mmi_rp_mgr_trace_warning(x,(U8*)s);

#define  MMI_RP_ERROR(x) {mmi_rp_mgr_trace_error(x, NULL);MMI_RP_ERROR_TRACE_LINE(x);}
#define  MMI_RP_ERROR_DATA(x,s) {mmi_rp_mgr_trace_error(x, (U8*)s);MMI_RP_ERROR_TRACE_LINE(x);}
#define  MMI_RP_FATAL_ERROR(x) {mmi_rp_mgr_trace_error(x, NULL);MMI_RP_ERROR_EXIT(x);}
#define  MMI_RP_FATAL_ERROR_DATA(x,s) {mmi_rp_mgr_trace_error(x, (U8*)s);MMI_RP_ERROR_EXIT(x);}

typedef enum
{
    MMI_RP_PARSE_OK,
    MMI_RP_PARSE_ERROR_CONTINUE,
    MMI_RP_PARSE_ERROR_SKIP_TAG
} mmi_rp_parse_error_code;


#ifdef RESXML_VC_DEBUG
#define MMI_RP_DEBUG_INFO printf
#else
#define  MMI_RP_DEBUG_INFO(x,...) // printf(x, __VA_ARGS__);
#endif





#include "mmi_rp_xml_def.h"
#include "mmi_rp_hash.h"

/************** Tag names which are used in g_res_handlers array *********/
/* Also used in resource callbacks for checking the order of he tags declaration. */
#define MMI_RP_MGR_TAG_APP "APP"
#define MMI_RP_MGR_TAG_LINE "LINE"
#define MMI_RP_MGR_TAG_INCLUDE "INCLUDE"
#define MMI_RP_MGR_TAG_PATH "PATH"

#define MMI_RP_MGR_TAG_IMAGE "IMAGE"
#define MMI_RP_MGR_TAG_MULTI_IMAGE "MULTI_IMAGE"
#define MMI_RP_MGR_TAG_MEDIA "MEDIA"
#define MMI_RP_MGR_TAG_ENFB "ENFB"
#define MMI_RP_MGR_TAG_STRING "STRING"
#define MMI_RP_MGR_TAG_AUDIO "AUDIO"

#define MMI_RP_MGR_TAG_MENU "MENU"
#define MMI_RP_MGR_TAG_MENUITEM "MENUITEM"
#define MMI_RP_MGR_TAG_MAINMENUITEM "MAINMENUITEM"
#define MMI_RP_MGR_TAG_MENUSET "MENUSET"
#define MMI_RP_MGR_TAG_MENUSET_ID "MENUSET_ID"
#define MMI_RP_MGR_TAG_MENUITEM_ID "MENUITEM_ID"

#define MMI_RP_MGR_TAG_SCREEN "SCREEN"
#define MMI_RP_MGR_TAG_TIMER "TIMER"
#define MMI_RP_MGR_TAG_EVENT "EVENT"

#define MMI_RP_MGR_TAG_MEMORY "MEMORY"
#define MMI_RP_MGR_TAG_APPCONCURRENT "APPCONCURRENT"

#define MMI_RP_MGR_TAG_THEME        "THEME"
#define MMI_RP_MGR_TAG_COLOR        "COLOR"
#define MMI_RP_MGR_TAG_FONTSTYLE    "FONTSTYLE"
#define MMI_RP_MGR_TAG_BINARY       "BINARY"
#define MMI_RP_MGR_TAG_INTEGER      "INTEGER"

#define MMI_RP_MGR_TAG_BINARY3D       "BINARY3D"

#define MMI_RP_MGR_TAG_END "TAG_END"
/*****************************************************************/

/************** Attribute names **************/
#define MMI_RP_MGR_ATTR_LINE 'l'
#define MMI_RP_MGR_ATTR_FILE "file"
#define MMI_RP_MGR_ATTR_ID "id"
#define MMI_RP_MGR_ATTR_ID_START "id_start"
#define MMI_RP_MGR_ATTR_ID_END "id_end"
#define MMI_RP_MGR_ATTR_ID_COUNT "max_count"
#define MMI_RP_MGR_ATTR_STR "str"
#define MMI_RP_MGR_ATTR_IMG "img"
#define MMI_RP_MGR_ATTR_GROUP "group"
#define MMI_RP_MGR_ATTR_QUALITY "quality"
#define MMI_RP_MGR_ATTR_NOTIFY "notify"
#define MMI_RP_MGR_ATTR_HIGHLIGHT "highlight"
#define MMI_RP_MGR_ATTR_HINT "hint"
#define MMI_RP_MGR_ATTR_PARENT "parent"
#define MMI_RP_MGR_ATTR_DEFAULT "default"

#define MMI_RP_MGR_ATTR_SCOPE "scope"
#define MMI_RP_MGR_ATTR_FLAG "flag"
#define MMI_RP_MGR_ATTR_FORCE_TYPE "force_type"
#define MMI_RP_MGR_ATTR_TYPE "type"
#define MMI_RP_MGR_ATTR_COMPRESSION "compression"

#define MMI_RP_MGR_ATTR_NAME "name"
#define MMI_RP_MGR_ATTR_PACKAGE_NAME "package_name"
#define MMI_RP_MGR_ATTR_PACKAGE_PROC "package_proc"
#define MMI_RP_MGR_ATTR_HIDDEN_IN_MAINMENU	"hidden_in_mainmenu"
#define MMI_RP_MGR_ATTR_APP_TYPE    "type"

/* <APPCONCURRENT> */
#define MMI_RP_MGR_ATTR_CONCURRENT "concurrent"
#define MMI_RP_MGR_ATTR_CONCURRENT_W_ORDER "concurrent_w_order"

/* <MEMORY> */
#define MMI_RP_MGR_ATTR_BASE    "base"
#define MMI_RP_MGR_ATTR_FG      "fg"
#define MMI_RP_MGR_ATTR_INC     "inc"
#define MMI_RP_MGR_ATTR_HEAP    "heap"
#define MMI_RP_MGR_ATTR_EXTRA_BASE  "extra_base"
#define MMI_RP_MGR_ATTR_CUI         "cui"
#define MMI_RP_MGR_ATTR_VRT_MEM_FACTOR  "vrt_mem_factor"

#define MMI_RP_MGR_ATTR_HEAP_S  "heap_shrink"
#define MMI_RP_MGR_ATTR_HEAP_SRC  "heap_source"

/* Menu shortcut */
#define MMI_RP_MGR_ATTR_SHORTCUT "shortcut"
#define MMI_RP_MGR_ATTR_SHORTCUT_IMG "shortcut_img"
#define MMI_RP_MGR_ATTR_SHORTCUT_STR "shortcut_str"
#define MMI_RP_MGR_ATTR_LAUNCH "launch"

/* Attribute for Venus Theme */
#define MMI_RP_MGR_ATTR_DESC    "desc"
#define MMI_RP_MGR_ATTR_FORMAT  "format"
#define MMI_RP_MGR_ATTR_OPAQUE  "opaque"
#define MMI_RP_MGR_ATTR_MIN     "min"
#define MMI_RP_MGR_ATTR_MAX     "max"
#define MMI_RP_MGR_ATTR_9SLICE  "9slice"

#define MMI_RP_MGR_ATTR_QVGA    "qvga"
#define MMI_RP_MGR_ATTR_LANDSCAPE "landscape"
#define MMI_RP_MGR_ATTR_WQVGA   "wqvga"
#define MMI_RP_MGR_ATTR_HVGA    "hvga"


/************** Attribute values **************/
#define MMI_RP_MGR_VAL_XML "XML"
#define MMI_RP_MGR_VAL_IMAGE "image"
#define MMI_RP_MGR_VAL_AUDIO "audio"
#define MMI_RP_MGR_VAL_MULTIBIN "MULTIBIN"
#define MMI_RP_MGR_VAL_REPLACEABLE "REPLACEABLE"

#define MMI_RP_MGR_VAL_FORCE_ABM "FORCE_ABM"
#define MMI_RP_MGR_VAL_FORCE_AB2 "FORCE_AB2"
#define MMI_RP_MGR_VAL_FORCE_BMP "FORCE_BMP"
#define MMI_RP_MGR_VAL_FORCE_ABM_SEQUENCE "FORCE_ABM_SEQUENCE"
#define MMI_RP_MGR_VAL_FORCE_JPG "FORCE_JPG"
#define MMI_RP_MGR_VAL_AUTO_TYPE "AUTO_TYPE"

#define MMI_RP_MGR_VAL_AUD_AUTO_ADO_TYPE  "AUTO_ADO_TYPE"
#define MMI_RP_MGR_VAL_AUD_FORCE_ADO_MIDI "FORCE_ADO_MIDI"

#define MMI_RP_MGR_VAL_AUTO_APP_MAIN "APP_MAIN"
#define MMI_RP_MGR_VAL_AUTO_APP_SUB "APP_SUB"
#define MMI_RP_MGR_VAL_AUTO_OPTION "OPTION"

#define MMI_RP_MGR_VAL_MOVEABLEWITHINPARENT "MOVEABLEWITHINPARENT"
#define MMI_RP_MGR_VAL_MOVEABLEACROSSPARENT "MOVEABLEACROSSPARENT"
#define MMI_RP_MGR_VAL_INSERTABLE "INSERTABLE"
#define MMI_RP_MGR_VAL_SHORTCUTABLE "SHORTCUTABLE"
#define MMI_RP_MGR_VAL_RADIO "RADIO"
#define MMI_RP_MGR_VAL_CHECKBOX "CHECKBOX"

#define MMI_RP_MGR_VAL_NONE "NONE"
#define MMI_RP_MGR_VAL_SENDER "SENDER"

#define MMI_RP_MGR_VAL_MM_LIST_IMG "mm_list_img"
#define MMI_RP_MGR_VAL_MM_MATRIX_IMG "mm_matrix_img"
#define MMI_RP_MGR_VAL_MM_PAGE_IMG "mm_page_img"
#define MMI_RP_MGR_VAL_MM_VENUS1_IMG "mm_venus1_img"
#define MMI_RP_MGR_VAL_MM_VENUS2_IMG "mm_venus2_img"
#define MMI_RP_MGR_VAL_MM_MATRIX_HIGHLIGHT_IMG "mm_matrix_highlight_img"
#define MMI_RP_MGR_VAL_MM_MATRIX_CONTROLLED_AREA_IMG "mm_matrix_controlled_area_img"
#define MMI_RP_MGR_VAL_MM_VENUS1_HIGHLIGHT_IMG "mm_venus1_highlight_img"
#define MMI_RP_MGR_VAL_MM_TITLE_IMG "mm_title_img"
#define MMI_RP_MGR_VAL_MM_3D_IMAGE "mm_3d_img"
#define MMI_RP_MGR_VAL_MM_LAUNCH "mm_launch"
#define MMI_RP_MGR_VAL_MM_HEADER "header"

#define MMI_RP_MGR_VAL_TRUE "TRUE"
#define MMI_RP_MGR_VAL_FALSE "FALSE"

#define MMI_RP_MGR_VAL_SEPARATOR "SEPARATOR"

#define MMI_RP_MGR_VAL_SHORTCUT_ON "ON"
#define MMI_RP_MGR_VAL_SHORTCUT_OFF "OFF"

#define MMI_RP_MGR_VAL_HIGH_QUALITY "high"
#define MMI_RP_MGR_VAL_LOW_QUALITY "low"
#define MMI_RP_MGR_VAL_MEDIUM_QUALITY "medium"



/************** Prefix definition **************/
#define MMI_RP_PREFIX_OID "@OID:"
#define MMI_RP_PREFIX_OID_LEN 5

/*****************************************************************/

#define MMI_RP_MGR_XML_TEMP_FOLDER_NAME                 "temp"
#define MMI_RP_APP_PACKAGE_CONFIG_HEADER_GUARD_DATA_H   "MMI_RP_NATIVE_APP_PACKAGE_DATA_H"
#define MMI_RP_APP_PACKAGE_CONFIG_FILE_NAME_DATA_H      "mmi_rp_native_app_package_data.h"
#define MMI_RP_APP_PACKAGE_CONFIG_FILE_NAME_DATA_C      "mmi_rp_native_app_package_data.c"

#ifdef RESXML_VC_DEBUG
#define MMI_RP_MGR_XML_CUSTRESOURCE_PATH      "..\\..\\..\\CustResource\\"
#define MMI_RP_MGR_XML_DEBUG_PATH             "..\\..\\debug\\"
#define MMI_RP_MGR_XML_SEARCH                 "..\\..\\debug\\res\\*.i"
#define MMI_RP_MGR_XML_SEARCH_PATH            "..\\..\\debug\\res\\"
#define MMI_RP_MGR_XML_TEMP_FOLDER            "..\\..\\temp\\res\\"
#define MMI_RP_MGR_XML_DEF_FOLDER             "..\\..\\..\\CustomerInc\\"
#define MMI_RP_MGR_TO_MCU_MMI_PATH            "..\\..\\..\\..\\..\\plutommi\\"

#define MMI_RP_MGR_XML_TEMP_CMP_C_FILES                             "..\\..\\temp\\res_out\\res\\"
#define MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES                "..\\..\\temp\\res_out\\custresource\\"
#define MMI_RP_MGR_XML_TEMP_CMP_H_FILES                             "..\\..\\temp\\res_out\\CustomerInc\\"
#define MMI_RP_MGR_XML_TEMP_CMP_C_FILES_SEARCH                      "..\\..\\temp\\res_out\\res\\*.c"
#define MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES_SEARCH         "..\\..\\temp\\res_out\\custresource\\*.c"
#define MMI_RP_MGR_XML_TEMP_CMP_H_FILES_SEARCH                      "..\\..\\temp\\res_out\\CustomerInc\\*.h"
#define MMI_RP_MGR_XML_AUTOGENERATED_C_FILES_SEARCH                 "..\\..\\debug\\res\\mmi_rp_*.c"
#define MMI_RP_MGR_XML_AUTOGENERATED_CUSTRESOURCE_C_FILES_SEARCH    "..\\..\\..\\CustResource\\mmi_rp_*.c"
#define MMI_RP_MGR_XML_AUTOGENERATED_H_FILES_SEARCH                 "..\\..\\..\\CustomerInc\\mmi_rp_*.h"
#define MMI_RP_MGR_XML_VENUS_THEME_LOG                              "..\\..\\debug\\venus_theme_log.txt"
#else
#define MMI_RP_MGR_XML_CUSTRESOURCE_PATH      "..\\CustResource\\"
#define MMI_RP_MGR_XML_DEBUG_PATH             ".\\debug\\"
#define MMI_RP_MGR_XML_SEARCH                 ".\\debug\\res\\*.i"
#define MMI_RP_MGR_XML_SEARCH_PATH            ".\\debug\\res\\"
#define MMI_RP_MGR_XML_TEMP_FOLDER            ".\\temp\\res\\"
#define MMI_RP_MGR_XML_DEF_FOLDER             "..\\CustomerInc\\"
#define MMI_RP_MGR_TO_MCU_MMI_PATH            "..\\..\\..\\plutommi\\"

#define MMI_RP_MGR_XML_TEMP_CMP_C_FILES                             ".\\temp\\res_out\\res\\"
#define MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES                ".\\temp\\res_out\\custresource\\"
#define MMI_RP_MGR_XML_TEMP_CMP_H_FILES                             ".\\temp\\res_out\\CustomerInc\\"
#define MMI_RP_MGR_XML_TEMP_CMP_C_FILES_SEARCH                      ".\\temp\\res_out\\res\\*.c"
#define MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES_SEARCH         ".\\temp\\res_out\\custresource\\*.c"
#define MMI_RP_MGR_XML_TEMP_CMP_H_FILES_SEARCH                      ".\\temp\\res_out\\CustomerInc\\*.h"
#define MMI_RP_MGR_XML_AUTOGENERATED_C_FILES_SEARCH                 ".\\debug\\res\\mmi_rp_*.c"
#define MMI_RP_MGR_XML_AUTOGENERATED_CUSTRESOURCE_C_FILES_SEARCH    "..\\CustResource\\mmi_rp_*.c"
#define MMI_RP_MGR_XML_AUTOGENERATED_H_FILES_SEARCH                 "..\\CustomerInc\\mmi_rp_*.h"
#define MMI_RP_MGR_XML_VENUS_THEME_LOG                              ".\\debug\\venus_theme_log.txt"
#endif

extern FILE *g_mmi_rp_output_enum_log_file;
#define MMI_RP_OUTPUT_ENUM_LOG(s,v) \
    do\
{\
    if(g_mmi_rp_output_enum_log_file)\
{\
    fprintf(g_mmi_rp_output_enum_log_file, "%s = %d\n", s, v);\
}\
}while(0)

#define  MMI_RP_MGR_MAX_TAG_LEN        32
#define  MMI_RP_MGR_MAX_FILE_NAME_LEN  512
#define  MMI_RP_MGR_MAX_SYS_CMD_LEN 2048

#define MMI_RP_CURR_APP_BASE_ID    g_mmi_resource_base_table[g_mmi_rp_mgr_cntx.cur_app_index].min

#define MMI_RP_MGR_TAG_STACK_MAX 99      /* Should be set as the maximum depth a legal tag tree can be. */

typedef enum 
{
    MMI_RP_OUTPUT_NAME_C_FILE_PATH,
    MMI_RP_OUTPUT_NAME_H_FILE_PATH,
    MMI_RP_OUTPUT_NAME_H_FILE,
    MMI_RP_OUTPUT_NAME_C_FILE,
    MMI_RP_OUTPUT_NAME_HEADER_GUARD,
    MMI_RP_OUTPUT_NAME_POPULATE_FUNCTION,
    MMI_RP_OUTPUT_NAME_TOTAL
}mmi_rp_output_names_enum;

typedef enum 
{
    MMI_RP_SCOPE_NONE,
    MMI_RP_SCOPE_XML,
    MMI_RP_SCOPE_TOTAL
}mmi_rp_scope_enum;

typedef enum
{
    MMI_RP_FLAG_SINGLE_BIN,
    MMI_RP_FLAG_MULTI_BIN,
    MMI_RP_FLAG_TOTAL,
}mmi_rp_flag_bin_enum;


typedef enum
{   
    MMI_RP_RES_PATH_IMG,
    MMI_RP_RES_PATH_ADO
}mmi_rp_res_path_type_enum;

typedef struct
{
    U8   def_img_path[MMI_RP_MGR_MAX_FILE_NAME_LEN];             /* start path of image resources */
    U8   def_ado_path[MMI_RP_MGR_MAX_FILE_NAME_LEN];             /* start path of audio */
    mmi_rp_res_path_type_enum  path_type;                       /* Type of current setting path */
    MMI_BOOL is_null;
}mmi_rp_res_path_struct;


typedef int (*mmi_rp_XML_callback_start_elem_hdlr) (
    void *data,
    const kal_char *el,
    const kal_char **attr);

typedef int (*mmi_rp_XML_callback_end_elem_hdlr) (void *data, const kal_char *el);

typedef int (*mmi_rp_XML_callback_data_hdlr) (
    void *resv,
    const kal_char *el,
    const kal_char *data,
    kal_int32 len);

typedef struct
{
    U8 tag_name[MMI_RP_MGR_MAX_TAG_LEN];                   /* Tag name */
    mmi_rp_XML_callback_start_elem_hdlr start_elem_hdlr;        /* Callback function pointer of start element */
    mmi_rp_XML_callback_end_elem_hdlr end_elem_hdlr;            /* Callback function pointer of end element */
    mmi_rp_XML_callback_data_hdlr data_hdlr;                    /* Callback function pointer data */
} mmi_rp_mgr_tag_callback;


typedef void (*void_func) (void);
extern void mmi_rp_end_function(void);
typedef struct
{
    void_func mmi_rp_res_init;          /* Callback function pointer of start element */
    void_func mmi_rp_res_set_range;     /* Callback function pointer of end element */
    void_func mmi_rp_res_filter;        /* Callback function pointer data */
    void_func mmi_rp_res_output_1;      /* Callback function pointer data */
    void_func mmi_rp_res_output_2;      /* Callback function pointer data */
} mmi_rp_mgr_cust_res_callback;

typedef struct{
    U8 error_file[MMI_RP_MGR_MAX_FILE_NAME_LEN];           /* error occur in which file */
    U32 error_line;                             /* error occur in which line */
} mmi_rp_mgr_error;

typedef struct 
{
    S32 tag[MMI_RP_MGR_TAG_STACK_MAX];       /* Holds the parent tag index in g_res_handlers array for checking the right order in which the tags are written. */
    S32 top;    
}mmi_rp_mgr_tag_stack_struct;

// get stack top tag name
extern const S8* mmi_rp_mgr_stack_top_tag_name();

// Frederic: Added populating_file_created
typedef struct
{
    S32                         program_error;     /* exe run error flag */
    U32                         tag_count;         /* Total count of tags */
    XML_PARSER_STRUCT           xml_parser;        /* xml parser context struct */
    mmi_rp_mgr_error            xml_error;         /* xml parser error structure */
    mmi_resource_base_struct    *cur_app;          /* Current APP struct by tag APP */
    U32                         cur_app_index;     /* Current APP index by g_mmi_resource_base_table from MMIDataTypes.h */
    U32                         total_apps;        /* Total no of apps */
    MMI_BOOL                    *app_populated;    /* Map for index of parsed apps */
    char **                     app_res_filepath;  /* Path of RES file of a parsed apps*/
    mmi_rp_mgr_tag_stack_struct parent_tags;
    U8**                        app_include;
    mmi_rp_hash_struct          *hash;
    mmi_rp_res_path_struct      path;               /* resource default path information. */
    U8                          **app_type;         /* app type, e.g. "pluto", "venus", for <MEMORY> */
    U8                          **app_id;       /* APP ID. Used by MAIN MENU to query badge icon setting. */
    U8                          **app_str_id;       /* STR ID for APP name. Used by memory & AppMgr Srv. */
    U8                          **app_img_id;       /* IMG_ID for App icon. Used by AppMgr Srv. */
    U8                          **app_package_name; /* app package name (UTF8 string) */
    U8                          **app_launch_func;  /* application launch function */
    U8                          **app_package_proc; /* application package proc */

    MMI_BOOL                    *app_hidden_in_mainmenu;	/* applicaiton will be hidden in mainmenu */
    U8                    * populating_file_created;

}mmi_rp_mgr_parser_context_struct;

extern mmi_rp_mgr_parser_context_struct g_mmi_rp_mgr_cntx;
extern mmi_rp_mgr_tag_callback *g_res_handlers;

extern kal_char *mmi_rp_mgr_get_err_string(void);

extern int mmi_rp_mgr_app_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mgr_app_end_handler(void *data, const kal_char *el);
extern int mmi_rp_mgr_app_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern int mmi_rp_mgr_line_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mgr_line_end_handler(void *data, const kal_char *el);
extern int mmi_rp_mgr_line_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern int mmi_rp_mgr_include_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mgr_include_end_handler(void *data, const kal_char *el);

extern int mmi_rp_mgr_path_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mgr_path_end_handler(void *data, const kal_char *el);
extern int mmi_rp_mgr_path_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);
extern void mmi_rp_mgr_path_reset(void);

extern void mmi_rp_write_copy_right_header_in_file(FILE *file);
extern void mmi_rp_write_file_header_in_file(FILE *file, S8 *filename, S8 *desc, S8 *author);

extern void mmi_rp_output_phase1_begin(FILE* p_file, U8 *str_header_guard);
extern void mmi_rp_output_phase1_finish(FILE *p_file, U8 *str_header_guard);
extern void mmi_rp_output_phase2_begin(FILE *p_file, U8 *str_function_name, U8 *str_header_file_name, U8* str_app_include_file_names);
extern void mmi_rp_output_phase2_finish(FILE *p_file);

extern void mmi_rp_mgr_output_populate_func(U8* populate_func_name);
extern void mmi_rp_mgr_output_all_defs(U8* str_file_name);

extern U8 *mmi_rp_mgr_contruct_name(mmi_rp_output_names_enum name_type, U8* str_app);

extern U32 mmi_rp_mgr_path_create(U8 *dest, U8 *prefix, U8 *path);

extern FILE * mmi_rp_open_population_c_file(U32 app_index, U8 res_pop_mask);

#endif /* RESGEN_XML_H */

