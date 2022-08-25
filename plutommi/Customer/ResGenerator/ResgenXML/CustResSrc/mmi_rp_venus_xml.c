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
 *  mmi_rp_venus_xml.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Plutommi Resource Generator Ver 2.0 (XML style)
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *              HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== *******************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "MMIDataType.h"
#include "mmi_rp_xml.h"
#include "mmi_rp_xml_def.h"
#include "mmi_rp_hash.h"

#include "mmi_rp_venus_xml.h"
// Frederic: TBC
// To use offline seetings so include CustDataProts.h
#include "CustDataProts.h"

/****************************************************************************
* Setting
*****************************************************************************/

#ifdef RESXML_VC_DEBUG
#define MMI_RP_VENUS_RESGEN_PATH    "plutommi\\Customer\\ResGenerator\\ResgenXML\\ResgenXML_VC"
#define MMI_RP_VENUS_OFFSET_PATH    "..\\..\\..\\..\\..\\"
#else
#define MMI_RP_VENUS_RESGEN_PATH    "plutommi\\Customer\\ResGenerator"
#define MMI_RP_VENUS_OFFSET_PATH    "..\\..\\..\\"
#endif

#define MMI_RP_VENUS_PYTHON_PATH    "tools\\python25\\python"
#define MMI_RP_VENUS_PREXML_PATH    "tools\\py\\prexml.py"
#define MMI_RP_VENUS_ENCODER_PATH   "venusmmi\\framework\\xml\\vfx_xml_conv.pl"
#define MMI_RP_VENUS_TABLE_PATH     "plutommi\\Customer\\ResGenerator\\debug\\resgen_xml_all_enum_IDs.log"
#define MMI_RP_VENUS_TEMP_PATH      "plutommi\\Customer\\ResGenerator\\debug\\vxml"
#define MMI_RP_VENUS_TEMP_PATH2     "..\\..\\Customer\\ResGenerator\\debug\\vxml\\"

#ifdef RESXML_VC_DEBUG
#define MMI_RP_VENUS_RESGEN_PATH    "plutommi\\Customer\\ResGenerator\\ResgenXML\\ResgenXML_VC"
#else
#define MMI_RP_VENUS_RESGEN_PATH    "plutommi\\Customer\\ResGenerator"
#endif

#define MMI_RP_MGR_ATTR_VENUS_ID    "id"
#define MMI_RP_MGR_ATTR_VENUS_FILE  "file"

#define TAG_MAX_NAME 127

/****************************************************************************
* MACRO
*****************************************************************************/

#define TAG_INSERT_LAYOUT(item)      

/****************************************************************************
* Define
*****************************************************************************/

enum {
    TAG_ENUM_LAYOUT_ID,
    TAG_ENUM_LAYOUT_XML,

    TAG_ENUM_END
};

#define TAG_BASE \
struct _tag_base        *next, *prev; \
    S32                     base_type; \
    char                    name[TAG_MAX_NAME+1]; \

typedef struct _tag_base
{
    TAG_BASE

} mmi_rp_tag_base_struct;

typedef struct _tag_xmlpath
{
    TAG_BASE
        S32         app_index;
    char        filepath[MMI_RP_MGR_MAX_FILE_NAME_LEN];

} mmi_rp_tag_xmlpath_struct;

typedef struct _list_struct
{
    mmi_rp_tag_base_struct *head, *tail;
} mmi_rp_taglist_struct;

typedef struct _app_struct
{
    mmi_rp_taglist_struct layout_id;
    mmi_rp_taglist_struct layout_xml;
} mmi_rp_app_struct;

typedef struct 
{
    mmi_rp_app_struct   *apps;
    S32                 count;

} mmi_rp_vxml_context_struct;

/****************************************************************************
* Global Variable
*****************************************************************************/

extern const mmi_resource_base_struct g_mmi_resource_base_table[];

/****************************************************************************
* Static Variable
*****************************************************************************/

mmi_rp_vxml_context_struct *g_vxml_ctxt = NULL;

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

static void mmi_rp_vxml_output_phase1_app_def_h_file(U32 app_index, FILE *p_file);

#ifdef __RESGEN_INTERNAL_POP_FILE_REDUCE__
static void mmi_rp_vxml_output_phase2_app_c_file(U32 app_index);
#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
static void mmi_rp_vxml_output_phase2_app_c_file(U32 app_index, FILE *p_file);
#endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__


static S32 mmi_rp_tag_insert_obj(mmi_rp_tag_base_struct* obj, S32 obj_type, mmi_rp_taglist_struct* list);
static mmi_rp_tag_base_struct* mmi_rp_tag_find_obj_by_name(const char* name, mmi_rp_tag_base_struct* head);
static void mmi_rp_vxml_encode_phase1(void);
static void mmi_rp_vxml_encode_phase2(void);
static void mmi_rp_path_join(char* final_buf, S32 final_buf_size, const char *src, const char* dest);

#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function Body
*****************************************************************************/

#define VENUS_XML_MODULE
/*****************************************************************************
* FUNCTION
*  mmi_rp_vxml_init
* DESCRIPTION
*  Initializes the template context structure. Called for every .res file parsed.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_vxml_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char sys_str[MMI_RP_MGR_MAX_SYS_CMD_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_mmi_rp_mgr_cntx.total_apps <= 0)
        return;

    if(!g_vxml_ctxt)
    {
        g_vxml_ctxt = malloc(sizeof(mmi_rp_vxml_context_struct));
        memset(g_vxml_ctxt, 0, sizeof(mmi_rp_vxml_context_struct));

        g_vxml_ctxt->count = g_mmi_rp_mgr_cntx.total_apps;
        g_vxml_ctxt->apps = malloc(sizeof(mmi_rp_app_struct) * g_mmi_rp_mgr_cntx.total_apps);
        memset(g_vxml_ctxt->apps, 0, sizeof(mmi_rp_app_struct) * g_mmi_rp_mgr_cntx.total_apps);
    }

    /* update export header */
    printf("==VenusXML Begin== [venusmmi\\framework\\xml\\vfx_xml_export.xml]\n");
    memset(sys_str, 0, MMI_RP_MGR_MAX_SYS_CMD_LEN);
    sprintf(sys_str, "perl %s%s -e 2>&1", 
        MMI_RP_VENUS_OFFSET_PATH, MMI_RP_VENUS_ENCODER_PATH);
    fflush(stdout);
    if(system(sys_str))
    {
        MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }
    printf("==VenusXML End== [venusmmi\\framework\\xml\\vfx_xml_export.xml]\n");
}

/*****************************************************************************
* FUNCTION
*  mmi_rp_vxml_set_app_range
* DESCRIPTION
*  Initializes the template context structure. Called for every .res file parsed.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_vxml_set_app_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* You can use 
    g_mmi_rp_mgr_cntx.cur_app->max and g_mmi_rp_mgr_cntx.cur_app->min
    */
}





/*****************************************************************************
* FUNCTION
*  mmi_rp_vxml_filter
* DESCRIPTION
*  This function is for resgen to filter your resource.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_vxml_filter(void)
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
*  mmi_rp_vxml_output_phase1
* DESCRIPTION
*  Output IDs
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_vxml_output_phase1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    U8 *str_output_filename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* before output, do encode process */
    mmi_rp_vxml_encode_phase1();

    /* 1. Output all APPs .h files. */
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        {
            continue;
        }

        str_output_filename = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_H_FILE_PATH, g_mmi_resource_base_table[i].appname);

        /* Menu resource module has already written the header and header guard. */ 
        /* Open the file in append mode */
        if(p_file = fopen(str_output_filename, "a"))
        {
            mmi_rp_vxml_output_phase1_app_def_h_file(i, p_file);
            fclose(p_file);
        }
        else
        {
            /* Error writing output file. Exit. */
            printf("Error: Cannot open H file! [%s]\n", str_output_filename);
            MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
        }
    }

    /* 2. If you have any other header files, you can output it here*/
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_vxml_output_phase1_app_def_h_file
* DESCRIPTION
*  Output Resources
* PARAMETERS
*  app_index      [IN]    App_index in resource base table
*  p_file         [IN]    File pointer to output file
* RETURNS
*  void
*****************************************************************************/
static void mmi_rp_vxml_output_phase1_app_def_h_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_tag_base_struct   *it;
    MMI_BOOL first = MMI_TRUE;
    char app_name[TAG_MAX_NAME+1];
    char *ptr;
    S32 app_enum_log_counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        strncpy(app_name, g_mmi_resource_base_table[app_index].appname, TAG_MAX_NAME);

        fprintf(p_file, "\n/******************** Venus XML resource IDs - Begin ********************/\n");
        /* Output your IDs here */

        fprintf(p_file, "typedef enum \n{\n");
        it = g_vxml_ctxt->apps[app_index].layout_id.head;
        while(it)
        {
            if(first)
            {
                fprintf(p_file, "    %s = %d + 1, /* BASE_ID + 1 */\n", it->name, g_mmi_resource_base_table[app_index].min);
                first = MMI_FALSE;
                app_enum_log_counter = g_mmi_resource_base_table[app_index].min;
            }
            else
                fprintf(p_file, "    %s,\n", it->name);

            MMI_RP_OUTPUT_ENUM_LOG(it->name, ++app_enum_log_counter);
            it = it->next;
        }
        for(ptr = app_name; *ptr; ptr++) *ptr = toupper(*ptr);
        fprintf(p_file, "\n    MMI_RP_%s_VXML_LAYOUT_MAX\n", app_name);
        for(ptr = app_name; *ptr; ptr++) *ptr = tolower(*ptr);
        fprintf(p_file, "} mmi_rp_%s_vxml_layout_enum;\n", app_name);

        fprintf(p_file, "/******************** Venus XML resource IDs - End ********************/\n\n");
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_ERROR_DATA(RP_ERR_WRITE_OUPUT_PHASE1, "Cannot open H file!");
    }
}



#ifndef __RESGEN_INTERNAL_POP_FILE_REDUCE__
/*****************************************************************************
* FUNCTION
*  mmi_rp_vxml_output_phase2
* DESCRIPTION
*  Output Resources
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_vxml_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    U8 *str_output_filename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_rp_vxml_encode_phase2();

    /* 1. Output all APPs .c files. */
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        {
            continue;
        }

        str_output_filename = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_C_FILE_PATH, g_mmi_resource_base_table[i].appname);

        /* Menu resource module has already written the header and started the function. */ 
        /* Open the file in append mode */
        if(p_file = fopen(str_output_filename, "a"))            
        {
            mmi_rp_vxml_output_phase2_app_c_file(i, p_file);
            fclose(p_file);
        }
        else
        {
            /* Error writing output file. Exit. */
            printf("Error: Cannot open C file! [%s]\n", str_output_filename);
            MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
        }
    }
}




/*****************************************************************************
* FUNCTION
*  mmi_rp_vxml_output_phase2_app_c_file
* DESCRIPTION
*  Output Resources
* PARAMETERS
*  app_index      [IN]    App_index in resource base table
*  p_file         [IN]    File pointer to output file
* RETURNS
*  void
*****************************************************************************/
static void mmi_rp_vxml_output_phase2_app_c_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_tag_base_struct   *it;
    char out_path[MMI_RP_MGR_MAX_FILE_NAME_LEN], *ptr1, *ptr2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        /* There's no current requirement to populate Template resources in .c files. */
        /* Keep it here for future reference. */
        fprintf(p_file, "\n");
        fprintf(p_file, "/******************** Venus XML resource IDs - begin ******************/\n");
        it = g_vxml_ctxt->apps[app_index].layout_id.head;
        while(it)
        {
            for(ptr1 = MMI_RP_VENUS_TEMP_PATH2, ptr2 = out_path;
                *ptr1;
                ptr1++, ptr2++)
            {
                if(*ptr1 != '\\')
                    *ptr2 = *ptr1;
                else
                {
                    ptr2[0] = ptr2[1] = ptr2[2] = ptr2[3] = '\\';
                    ptr2 += 3;
                }
            }
            strcpy(ptr2, it->name);
            fprintf(p_file, "    ADD_APPLICATION_BINARY(%s, \"%s.bin\", BINARY_TYPE_VENUS_XML, \"Generated by Resgen_XML\");\n", it->name, out_path);
            it = it->next;
        }
        fprintf(p_file, "/******************** Venus XML resource IDs - end ********************/\n");
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_ERROR_DATA(RP_ERR_WRITE_OUPUT_PHASE2, "Cannot open C file!");
    }
}
#elif defined(__RESGEN_INTERNAL_POP_FILE_REDUCE__) && defined(__RESGEN_INTERNAL_OFFLINE__) //__RESGEN_INTERNAL_POP_FILE_REDUCE__
/*****************************************************************************
* FUNCTION
*  mmi_rp_vxml_output_phase2
* DESCRIPTION
*  Output Resources, verision of offline resgenerator
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/

void mmi_rp_vxml_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    U8 *str_output_filename = NULL;
    CHAR * str_output_filename_header = NULL;
    CHAR *str_function_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_rp_vxml_encode_phase2();
    BinaryAdaptorStartOfflinePopulation(DEFAULT_OFFLINE_XML_BINARY_DB);
    /* 1. Output all APPs .c files. */
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        {
            continue;
        }

        mmi_rp_vxml_output_phase2_app_c_file(i);

    }
    BinaryAdaptorStopOfflinePopulation();
}




/*****************************************************************************
* FUNCTION
*  mmi_rp_vxml_output_phase2_app_c_file
* DESCRIPTION
*  Output Resources,  verision of offline resgenerator
* PARAMETERS
*  app_index      [IN]    App_index in resource base table
*  p_file         [IN]    File pointer to output file
* RETURNS
*  void
*****************************************************************************/
static void mmi_rp_vxml_output_phase2_app_c_file(U32 app_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_tag_base_struct   *it;
    char out_path[MMI_RP_MGR_MAX_FILE_NAME_LEN], *ptr1, *ptr2;
    char bianry_path[MMI_RP_MGR_MAX_FILE_NAME_LEN]="";
    const U8 file_state_not_open = 0;
    const U8 file_state_opened = 1;    
    U8 file_state = file_state_not_open;

    U32 binaryResourId = g_mmi_resource_base_table[app_index].min + 1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* There's no current requirement to populate Template resources in .c files. */
    /* Keep it here for future reference. */

    it = g_vxml_ctxt->apps[app_index].layout_id.head;
    while(it)
    {
        for(ptr1 = MMI_RP_VENUS_TEMP_PATH2, ptr2 = out_path;
            *ptr1;
            ptr1++, ptr2++)
        {
            if(*ptr1 != '\\')
                *ptr2 = *ptr1;
            else
            {
                ptr2[0] = ptr2[1] = ptr2[2] = ptr2[3] = '\\';
                ptr2 += 3;
            }
        }

        strcpy(ptr2, it->name);

        //printf("    ADD_APPLICATION_BINARY(%s, \"%s.bin\", BINARY_TYPE_VENUS_XML, \"Generated by Resgen_XML\");\n", it->name, out_path);
        sprintf(bianry_path,"%s.bin",out_path);
        // 1. imageId
        // 2. Bin FilePath
        // 3  Description
        // 4. stringEnumName
        // 5. resFilePath
        // 6. noCompiling
        // 7. int forceType
        BinaryAdaptorSetBinary(
            binaryResourId,
            bianry_path,
            ((g_mmi_resource_base_table[app_index].appname)?(g_mmi_resource_base_table[app_index].appname):("APP name unknown")),
            "Generated by Resgen_XML",
            it->name,
            ((g_mmi_rp_mgr_cntx.app_res_filepath[app_index])?(g_mmi_rp_mgr_cntx.app_res_filepath[app_index]):("Res path unknown")),
            1,
            BINARY_TYPE_VENUS_XML);
        binaryResourId++;

        it = it->next;
    }


}

#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
/*****************************************************************************
* FUNCTION
*  mmi_rp_vxml_output_phase2
* DESCRIPTION
*  Output Resources
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_vxml_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    U8 *str_output_filename = NULL;
    CHAR * str_output_filename_header = NULL;
    CHAR *str_function_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_rp_vxml_encode_phase2();
    /* 1. Output all APPs .c files. */
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        {
            continue;
        }

        mmi_rp_vxml_output_phase2_app_c_file(i);

    }
}




/*****************************************************************************
* FUNCTION
*  mmi_rp_vxml_output_phase2_app_c_file
* DESCRIPTION
*  Output Resources
* PARAMETERS
*  app_index      [IN]    App_index in resource base table
*  p_file         [IN]    File pointer to output file
* RETURNS
*  void
*****************************************************************************/
static void mmi_rp_vxml_output_phase2_app_c_file(U32 app_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_tag_base_struct   *it;
    char out_path[MMI_RP_MGR_MAX_FILE_NAME_LEN], *ptr1, *ptr2;
    const U8 file_state_not_open = 0;
    const U8 file_state_opened = 1;    
    U8 file_state = file_state_not_open;
    FILE * p_file = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* There's no current requirement to populate Template resources in .c files. */
    /* Keep it here for future reference. */

    it = g_vxml_ctxt->apps[app_index].layout_id.head;
    while(it)
    {
        for(ptr1 = MMI_RP_VENUS_TEMP_PATH2, ptr2 = out_path;
            *ptr1;
            ptr1++, ptr2++)
        {
            if(*ptr1 != '\\')
                *ptr2 = *ptr1;
            else
            {
                ptr2[0] = ptr2[1] = ptr2[2] = ptr2[3] = '\\';
                ptr2 += 3;
            }
        }

        if(file_state == file_state_not_open){                
            p_file = mmi_rp_open_population_c_file(app_index, RES_LEGACY_POP_BINARY_MASK);

            if(p_file== NULL)
            {
                MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
            }
            file_state = file_state_opened;
            fprintf(p_file, "\n");
            fprintf(p_file, "/******************** Venus XML resource IDs - begin ******************/\n");
        }

        if(p_file == NULL){
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
        }else{
            strcpy(ptr2, it->name);
            fprintf(p_file, "    ADD_APPLICATION_BINARY(%s, \"%s.bin\", BINARY_TYPE_VENUS_XML, \"Generated by Resgen_XML\");\n", it->name, out_path);
            it = it->next;
        }
    }

    if(p_file!=NULL && file_state ==file_state_opened){
        fprintf(p_file, "/******************** Venus XML resource IDs - end ********************/\n");
        fclose(p_file);
    }
}



#endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__



#define TAG_LAYOUT

/*****************************************************************************
* FUNCTION
*  mmi_rp_venus_layout_start_handler
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
int mmi_rp_venus_layout_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0, ret, i;
    S32 parent_tag_id = -1;
    S32 app_index = g_mmi_rp_mgr_cntx.cur_app_index;

    mmi_rp_tag_xmlpath_struct *xmlitem;
    char *ptr;
    S8 bError = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("VLayout -start: %s\n", el);

    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP))
    {
        MMI_RP_ERROR_DATA(RP_ERR_TAG_USE_ERROR, "<LAYOUT> should be in <APP>");
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        printf("%s = %s\n", attr[index], attr[index + 1]);

        do {
            if(strlen(attr[index+1]) > TAG_MAX_NAME)
            {
                printf("Error: Attr value too long [%s]\n", attr[index+1]);
                MMI_RP_ERROR(RP_ERR_BUFFER_LENGTH_EXCEEDED);
                bError = 1;
                break;
            }

            if(!strcmp(attr[index], MMI_RP_MGR_ATTR_VENUS_FILE))
            {
                xmlitem = malloc(sizeof(mmi_rp_tag_xmlpath_struct));
                memset(xmlitem, 0, sizeof(mmi_rp_tag_xmlpath_struct));
                i = strlen(attr[index+1]);
                while(i >= 0 && attr[index+1][i] != '\\') i--;
                i++;
                strcpy(xmlitem->name, attr[index+1] + i);
                ptr = xmlitem->name;
                while(*ptr != '.') ptr++;
                *ptr = 0;
                xmlitem->app_index = app_index;

                mmi_rp_path_join(xmlitem->filepath, MMI_RP_MGR_MAX_FILE_NAME_LEN, "plutommi", g_mmi_resource_base_table[app_index].res_path);
                mmi_rp_path_join(xmlitem->filepath, MMI_RP_MGR_MAX_FILE_NAME_LEN, NULL, attr[index+1]);

                ret = mmi_rp_tag_insert_obj((mmi_rp_tag_base_struct*)xmlitem, TAG_ENUM_LAYOUT_XML, &g_vxml_ctxt->apps[app_index].layout_xml);
                if(ret)
                {
                    if(ret == RP_ERR_TAG_OPEN_TWICE)
                    {
                        printf("Error: Duplicate xml file, skipped [%s]\n", attr[index+1]);
                    }
                    MMI_RP_ERROR_DATA(ret, attr[index+1]);
                    return MMI_RP_PARSE_ERROR_SKIP_TAG;
                }
                break;
            }

            // Unknown attr, just skip it
            MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
            bError = 1;

        } while(0);
        index += 2;
    }

    if(bError)
        return MMI_RP_PARSE_ERROR_CONTINUE;

    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_venus_layout_end_handler
* DESCRIPTION
*  This function is for XML parser to return end tag information to application
* PARAMETERS
*  data        [IN]        Reserved
*  el          [IN]        Element name
*  error       [IN]        Error code
* RETURNS
*  void
*****************************************************************************/
int mmi_rp_venus_layout_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("VLayout -end: %s\n", el);
    return MMI_RP_PARSE_OK;
}

#define LOCAL_FUNCTION

static char* _path_get_filename(char* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!path) return NULL;

    for(ptr=path; *ptr; ptr++);

    for(; *ptr!='\\' && ptr!=path; ptr--);

    if(*ptr == '\\')
        ptr++;

    return ptr;
}

static S32 mmi_rp_tag_insert_obj(mmi_rp_tag_base_struct* obj, S32 obj_type, mmi_rp_taglist_struct* list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* already exist */
    if(mmi_rp_tag_find_obj_by_name(obj->name, list->head))
    {
        return RP_ERR_TAG_OPEN_TWICE;
    }

    /* insert to tail */
    obj->base_type = obj_type;
    if(!list->tail)
    {
        list->head = obj;
        list->tail = obj;
        obj->next = obj->prev = NULL;
    }
    else
    {
        obj->prev = list->tail;
        obj->next = NULL;
        list->tail->next = obj;
        list->tail = obj;
    }
    return 0;
}

static mmi_rp_tag_base_struct* mmi_rp_tag_find_obj_by_name(const char* name, mmi_rp_tag_base_struct* head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_tag_base_struct* obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!name || !name[0])
        return NULL;

    obj = head;
    while(obj)
    {
        if(!strcmp(obj->name, name))
            return obj;
        obj = obj->next;
    }
    return NULL;
}

static void mmi_rp_vxml_parse_id_list(S32 app_index, const char* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE * fp;
    char linebuf[128];
    S32 ret;
    mmi_rp_tag_base_struct *item;
    char *ptr; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fp = fopen(path, "r");
    if(!fp)
    {
        printf("Error: Cannot open file [%s]\n", path);
        MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
        return;
    }

    while(fgets(linebuf, 128, fp))
    {
        ptr = linebuf;
        while(*ptr)
        {
            if(*ptr == 0x0d || *ptr == 0x0a)
            {
                *ptr = 0;
                break;
            }
            ptr++;
        }
        if(!linebuf[0])
            continue;

        item = malloc(sizeof(mmi_rp_tag_base_struct));
        strcpy(item->name, linebuf);

        ret = mmi_rp_tag_insert_obj(item, TAG_ENUM_LAYOUT_ID, &g_vxml_ctxt->apps[app_index].layout_id);
        if(ret)
        {
            if(ret == RP_ERR_TAG_OPEN_TWICE)
            {
                printf("Error: Duplicate layout ID, skipped [%s]\n", item->name);
            }
            MMI_RP_ERROR_DATA(ret, item->name);
        }
    }

    fclose(fp);
}

static void mmi_rp_vxml_encode_phase1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char sys_str[MMI_RP_MGR_MAX_SYS_CMD_LEN];
    char out_path[MMI_RP_MGR_MAX_FILE_NAME_LEN];

    mmi_rp_tag_base_struct      *it;
    mmi_rp_tag_xmlpath_struct   *xmlitem;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* for each app */
    for(i=0;i<g_vxml_ctxt->count;i++)
    {
        it = g_vxml_ctxt->apps[i].layout_xml.head;

        /* for each xml in this app */
        while(it)
        {
            xmlitem = (mmi_rp_tag_xmlpath_struct*)it;

            printf("==VenusXML Begin== [%s]\n", xmlitem->filepath);

            do {
                /* prepare out_path */
                sprintf(out_path, "%s\\%s", MMI_RP_VENUS_TEMP_PATH, _path_get_filename(xmlitem->filepath));

                /* do prexml to remove compile option */
                memset(sys_str, 0, MMI_RP_MGR_MAX_SYS_CMD_LEN);
                sprintf(sys_str, "%s%s %s%s %s%s %s%s 2>&1", 
                    MMI_RP_VENUS_OFFSET_PATH, MMI_RP_VENUS_PYTHON_PATH, 
                    MMI_RP_VENUS_OFFSET_PATH, MMI_RP_VENUS_PREXML_PATH, 
                    MMI_RP_VENUS_OFFSET_PATH, xmlitem->filepath, 
                    MMI_RP_VENUS_OFFSET_PATH, out_path);
                fflush(stdout);
                if(system(sys_str))
                {
                    printf("Error: Fail to preXML! [%s]\n", xmlitem->filepath);
                    MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
                    break;
                }

                /* do parsing, id list */
                memset(sys_str, 0, MMI_RP_MGR_MAX_SYS_CMD_LEN);
                sprintf(sys_str, "perl %s%s -i %s%s -l %s%s\\%s.txt 2>&1", 
                    MMI_RP_VENUS_OFFSET_PATH, MMI_RP_VENUS_ENCODER_PATH,
                    MMI_RP_VENUS_OFFSET_PATH, out_path,
                    MMI_RP_VENUS_OFFSET_PATH, MMI_RP_VENUS_TEMP_PATH, xmlitem->name);
                fflush(stdout);
                if(system(sys_str))
                {
                    printf("Error: Fail to gen id! [%s]\n", xmlitem->name);
                    MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
                    break;
                }

                /* open id list */
                sprintf(sys_str, "%s%s\\%s.txt", 
                    MMI_RP_VENUS_OFFSET_PATH, MMI_RP_VENUS_TEMP_PATH, xmlitem->name);
                mmi_rp_vxml_parse_id_list(xmlitem->app_index, sys_str);
            } while(0);

            printf("==VenusXML End== [%s]\n", xmlitem->filepath);

            it = it->next;
        }

        /* now we have all id, copy them to correct path */
    }
}

static void mmi_rp_vxml_encode_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char sys_str[MMI_RP_MGR_MAX_SYS_CMD_LEN];
    char out_path[MMI_RP_MGR_MAX_FILE_NAME_LEN];

    mmi_rp_tag_base_struct      *it;
    mmi_rp_tag_xmlpath_struct   *xmlitem;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* for each app */
    for(i=0;i<g_vxml_ctxt->count;i++)
    {
        it = g_vxml_ctxt->apps[i].layout_xml.head;

        /* for each xml in this app */
        while(it)
        {
            xmlitem = (mmi_rp_tag_xmlpath_struct*)it;

            printf("==VenusXML Begin== [%s]\n", xmlitem->filepath);

            do {
                /* prepare out_path */
                sprintf(out_path, "%s\\%s", MMI_RP_VENUS_TEMP_PATH, _path_get_filename(xmlitem->filepath));

                /* do encode, id list */
                memset(sys_str, 0, MMI_RP_MGR_MAX_SYS_CMD_LEN);
                sprintf(sys_str, "perl %s%s -i %s%s -o %s%s -m %s%s 2>&1", 
                    MMI_RP_VENUS_OFFSET_PATH, MMI_RP_VENUS_ENCODER_PATH,
                    MMI_RP_VENUS_OFFSET_PATH, out_path,
                    MMI_RP_VENUS_OFFSET_PATH, MMI_RP_VENUS_TEMP_PATH,
                    MMI_RP_VENUS_OFFSET_PATH, MMI_RP_VENUS_TABLE_PATH);
                fflush(stdout);
                if(system(sys_str))
                {
                    printf("Error: Fail to Encode! [%s]\n", xmlitem->filepath);
                    MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
                    break;
                }
            } while(0);

            printf("==VenusXML End== [%s]\n", xmlitem->filepath);

            it = it->next;
        }

        /* now we have all id, copy them to correct path */
    }
}

static void mmi_rp_path_join(char* final_buf, S32 final_buf_size, const char *src, const char* dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char token_buf[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    char *token;
    S32 src_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(src && final_buf != src)
    {
        strcpy(final_buf, src);
    }
    src_len = strlen(final_buf);
    if(final_buf[src_len-1] != '\\')
    {
        final_buf[src_len] = '\\';
        src_len++;
        final_buf[src_len] = 0;
    }

    strcpy(token_buf, dest);
    token = strtok(token_buf, "\\");
    while(token)
    {
        if(*token == 0 || strcmp(token, ".") == 0)
            ;
        else if(strcmp(token, "..") == 0)
        {
            src_len-=2;
            while(final_buf[src_len] != '\\' && src_len >= 0) src_len--;

            src_len++;
            final_buf[src_len] = 0;
        }
        else
        {
            strcat(final_buf, token);
            strcat(final_buf, "\\");
        }
        src_len = strlen(final_buf);

        token = strtok(NULL, "\\");
    }

    final_buf[src_len-1] = 0;

}
