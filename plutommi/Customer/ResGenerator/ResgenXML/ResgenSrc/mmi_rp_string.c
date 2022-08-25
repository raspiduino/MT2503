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
 *  mmi_rp_string.c
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



#include <stdio.h>
#include <stdlib.h>

#include "MMIDataType.h"
#include "mmi_rp_xml.h"
#include "mmi_rp_xml_def.h"
#include "mmi_rp_string.h"
#include "mmi_rp_hash.h"
#include "mmi_rp_menu.h"

#include "mmi_res_range_def.h"

////////////////////////////////////////////
// Offilne Generator Headers
////////////////////////////////////////////
#ifdef __RESGEN_INTERNAL_OFFLINE__
#include "OfflineResPopCAPI.h"
#endif //__RESGEN_INTERNAL_OFFLINE__
////////////////////////////////////////////

extern const mmi_resource_base_struct g_mmi_resource_base_table[];

void mmi_rp_str_output_phase1_app_def_h_file(U32 app_index, FILE *p_file);

#ifdef __RESGEN_INTERNAL_POP_FILE_REDUCE__
void mmi_rp_str_output_phase2_app_c_file(U32 app_index);
#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
void mmi_rp_str_output_phase2_app_c_file(U32 app_index, FILE *p_file);
#endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__

#define MMI_RP_STR_CURR_APP_STR       g_mmi_rp_str_cntx.app_str_data[g_mmi_rp_mgr_cntx.cur_app_index]

mmi_rp_str_cntx_struct g_mmi_rp_str_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_str_init
 * DESCRIPTION
 *  Initializes the str context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_str_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_mmi_rp_mgr_cntx.total_apps <= 0)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_APP_UNKNOWN);
    }

    memset(&g_mmi_rp_str_cntx, 0, sizeof(g_mmi_rp_str_cntx));
    g_mmi_rp_str_cntx.app_str_data = (mmi_rp_str_data_struct*)malloc(sizeof(mmi_rp_str_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    if(!g_mmi_rp_str_cntx.app_str_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_str_cntx.app_str_data, 0, sizeof(mmi_rp_str_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_str_cntx.hash = mmi_rp_hash_create(0xFFFF);    /* 0xFFFF is the resource ID range */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_str_set_app_range
 * DESCRIPTION
 *  Initializes the str context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_str_set_app_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 range = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_RP_STR_CURR_APP_STR.strings == NULL)
    {
        range = g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min + 1;
        MMI_RP_STR_CURR_APP_STR.strings = (mmi_rp_str_id_struct*)malloc(sizeof(mmi_rp_str_id_struct) * range);

        if((!MMI_RP_STR_CURR_APP_STR.strings) && (range > 0))
        {
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }

        memset(MMI_RP_STR_CURR_APP_STR.strings, 0, sizeof(mmi_rp_str_id_struct) * range);
    }
}


    
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_str_start_handler
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
int mmi_rp_str_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    mmi_rp_scope_enum curr_scope = MMI_RP_SCOPE_NONE;
    U8 *curr_str_id = NULL;
    S32 parent_tag_id = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("String-start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /* String ID exceeded the app_range */
    if(MMI_RP_STR_CURR_APP_STR.total_count >= (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID) == 0)
        {
            curr_str_id = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_SCOPE) == 0)
        {
            if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_XML) == 0)
            {
                curr_scope = MMI_RP_SCOPE_XML;
            }
            else /* Default for scope. */
            {
                curr_scope = MMI_RP_SCOPE_NONE;
            }                 
        }
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        index += 2;
    }

    if(curr_str_id != NULL)
    {
        if(!mmi_rp_hash_find(g_mmi_rp_str_cntx.hash, curr_str_id))
        {
            MMI_RP_STR_CURR_APP_STR.strings[MMI_RP_STR_CURR_APP_STR.total_count].string_id_str = mmi_rp_hash_add(g_mmi_rp_str_cntx.hash, curr_str_id);
            MMI_RP_STR_CURR_APP_STR.strings[MMI_RP_STR_CURR_APP_STR.total_count].scope = curr_scope;
            MMI_RP_STR_CURR_APP_STR.total_count++;
        }
        else
        {
            MMI_RP_PARSE_WARNING(RP_WARN_DUPLICATE_ID);
        }
    }
    else
    {
        MMI_RP_PARSE_WARNING(RP_WARN_RES_ID_NULL);
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_str_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_str_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("String-end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_str_data_handler
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
int mmi_rp_str_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str_data[MMI_RP_STR_MAX_STRING_LEN];
    U32 str_len = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("String-data: %s\n", data);

    if(data != NULL)
    {
        str_len = strlen(data);

        if(data[0] == '"' || data[str_len - 1] == '"')
        {
            /* If one of the double quote is missing */
            if(data[0] != '"' || data[str_len - 1] != '"')
            {
                MMI_RP_ERROR_DATA(RP_ERR_STRING_MISSING_ENCLOSING_QUOTES, data);
                return MMI_RP_PARSE_ERROR_SKIP_TAG;
            }
            memset(str_data, 0, MMI_RP_STR_MAX_STRING_LEN);
            strncpy(str_data, data + 1, str_len - 2);
            MMI_RP_STR_CURR_APP_STR.strings[MMI_RP_STR_CURR_APP_STR.total_count - 1].string_data_str = mmi_rp_hash_add(g_mmi_rp_str_cntx.hash, (U8*)str_data);
        }
        else
        {
            /* Adding at (total_count - 1) index as the total_count has already been increased in start tag handler */
            MMI_RP_STR_CURR_APP_STR.strings[MMI_RP_STR_CURR_APP_STR.total_count - 1].string_data_str = mmi_rp_hash_add(g_mmi_rp_str_cntx.hash, (U8*)data);
        }
    }
    return MMI_RP_PARSE_OK;
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_str_add_app_name_str_id
 * DESCRIPTION
 *  This function is for XML parser to return start tag information to application
 * PARAMETERS
 *  str_name_id        [IN]        Reserved
 * RETURNS
 *  Pointer to String to the added APP name ID 
 *****************************************************************************/
U8* mmi_rp_str_add_app_name_str_id(const U8* str_name_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *curr_str_id = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("App Name String ID : %s\n", str_name_id);

    /* String ID exceeded the app_range */
    if(MMI_RP_STR_CURR_APP_STR.total_count >= (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return NULL;
    }
    
    if(str_name_id != NULL)
    {
        if(!mmi_rp_hash_find(g_mmi_rp_str_cntx.hash, (U8*)str_name_id))
        {
            curr_str_id = MMI_RP_STR_CURR_APP_STR.strings[MMI_RP_STR_CURR_APP_STR.total_count].string_id_str = mmi_rp_hash_add(g_mmi_rp_str_cntx.hash, (U8*)str_name_id);
            MMI_RP_STR_CURR_APP_STR.strings[MMI_RP_STR_CURR_APP_STR.total_count].scope = MMI_RP_SCOPE_NONE;
            MMI_RP_STR_CURR_APP_STR.total_count++;
        }
        else
        {
            MMI_RP_PARSE_WARNING(RP_WARN_DUPLICATE_ID);
        }
    }
    else
    {
        MMI_RP_PARSE_WARNING(RP_WARN_RES_ID_NULL);
    }

    return curr_str_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_str_filter
 * DESCRIPTION
 *  This function is for resgen to filter image resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_str_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0, k =0, app_c = 0, str_c = 0;
    U8 *search_id = NULL, *cand_id = NULL;
    MMI_BOOL found = MMI_FALSE;
    mmi_rp_str_data_struct *curr_app_str1 = NULL;
    mmi_rp_menu_data_struct *curr_menu_str2= NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(app_c = 0; app_c < g_mmi_rp_mgr_cntx.total_apps; app_c++)
    {
        curr_app_str1 = &(g_mmi_rp_str_cntx.app_str_data[app_c]);

        for(str_c =0; str_c < curr_app_str1->total_count; str_c++)
        {
            if(curr_app_str1->strings[str_c].scope != MMI_RP_SCOPE_XML)
            {
                curr_app_str1->strings[str_c].filter = MMI_TRUE;
                continue;
            }

            search_id = curr_app_str1->strings[str_c].string_id_str;
            found = MMI_FALSE;

            for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
            {
                curr_menu_str2 = &(g_mmi_rp_menu_cntx.app_menu_data[i]);
                for(j =0; j < curr_menu_str2->total_count; j++)
                {
                    cand_id = curr_menu_str2->menus[j].xml_data.str_id_str;

                    if((cand_id == NULL) || (curr_menu_str2->menus[j].filter == MMI_FALSE))
                    {
                        continue;
                    }

                    if(strcmp(search_id, cand_id) == 0)    
                    {
                        found = MMI_TRUE;
                        break;
                    }
                }
                if(found)
                {
                    break;
                }
            }
            curr_app_str1->strings[str_c].filter = found;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_str_output_phase1
 * DESCRIPTION
 *  Output ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_str_output_phase1(void)
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
            mmi_rp_str_output_phase1_app_def_h_file(i, p_file);
            fclose(p_file);
        }
        else
        {
            /* Error writing output file. Exit. */
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_str_output_phase1_app_def_h_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_str_output_phase1_app_def_h_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0;
    U8 str_enum_name[MMI_RP_OUTPUT_ENUM_NAME_MAX], str_enum_max[MMI_RP_OUTPUT_ENUM_NAME_MAX];
    MMI_BOOL first = MMI_TRUE;
    mmi_rp_str_data_struct *curr_app_str = &(g_mmi_rp_str_cntx.app_str_data[app_index]);
    S32 app_enum_log_counter = -1;      /* -1 for debug purpose */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        memset(str_enum_name, 0, sizeof(str_enum_name));
        strcpy(str_enum_name, "mmi_rp_");
        strcat(str_enum_name, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_name, "_str_enum");
        for(i = 0; i < strlen(str_enum_name); i++)
        {
            str_enum_name[i] = tolower(str_enum_name[i]);
        }

        memset(str_enum_max, 0, sizeof(str_enum_max));
        strcpy(str_enum_max, "MMI_RP_");
        strcat(str_enum_max, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_max, "_STR_MAX");
        for(i = 0; i < strlen(str_enum_max); i++)
        {
            str_enum_max[i] = toupper(str_enum_max[i]);
        }

        /* Check if no str IDs. */
        if(curr_app_str->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            fprintf(p_file, "\n\n");
            fprintf(p_file, "/******************** String resource IDs - begin ********************/\n");
            fprintf(p_file, "typedef enum\n{\n");

            for(i = 0; i < curr_app_str->total_count; i++)
            {
                if(curr_app_str->strings[i].filter == MMI_FALSE)
                {
                    continue;
                }

                if(first)
                {
                    fprintf(p_file, "    %s = %d + 1, /* BASE_ID + 1 */\n", curr_app_str->strings[i].string_id_str, g_mmi_resource_base_table[app_index].min);
                    first = MMI_FALSE;

                    app_enum_log_counter = g_mmi_resource_base_table[app_index].min + 1;
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_str->strings[i].string_id_str, app_enum_log_counter);
                    app_enum_log_counter++;

                }
                else
                {
                    fprintf(p_file, "    %s,\n", curr_app_str->strings[i].string_id_str);
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_str->strings[i].string_id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
            }

            fprintf(p_file, "    %s\n", str_enum_max);
            fprintf(p_file, "}%s;\n", str_enum_name);
            fprintf(p_file, "/******************** String resource IDs - finish ********************/\n");
        }
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }
}

#ifndef __POPULATE_NO_STRING_DATA__
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_str_output_phase2
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_str_output_phase2(void)
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
    /* 1. Output all APPs .c files. */
#ifdef __RESGEN_INTERNAL_OFFLINE__ 
    StringAdaptorStartOfflinePopulation(DEFAULT_OFFLINE_XML_STRING_DB);
#endif //__RESGEN_INTERNAL_OFFLINE__
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        {
            continue;
        }
#ifdef __RESGEN_INTERNAL_POP_FILE_REDUCE__
        mmi_rp_str_output_phase2_app_c_file(i);
#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
        str_output_filename = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_C_FILE_PATH, g_mmi_resource_base_table[i].appname);

        /* Menu resource module has already written the header and started the function. */ 
        /* Open the file in append mode */
        if(p_file = fopen(str_output_filename, "a"))            
        {
            mmi_rp_str_output_phase2_app_c_file(i, p_file);
            fclose(p_file);
        }
        else
        {
            /* Error writing output file. Exit. */
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
        }
#endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__
    }



#ifdef __RESGEN_INTERNAL_OFFLINE__ 
    //printf("StringAdaptorStopOfflinePopulation: %s\n",DEFAULT_OFFLINE_XML_STRING_DB );
    StringAdaptorStopOfflinePopulation();
#endif //__RESGEN_INTERNAL_OFFLINE__
}

#ifndef __RESGEN_INTERNAL_POP_FILE_REDUCE__
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_str_output_phase2_app_c_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_str_output_phase2_app_c_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0, j = 0;
    mmi_rp_str_data_struct *curr_app_str = &(g_mmi_rp_str_cntx.app_str_data[app_index]);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        /* Check if no str IDs. */
        if(curr_app_str->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            fprintf(p_file, "\n");
            fprintf(p_file, "/******************** String resource IDs - begin ********************/\n");

            /* 1. Add str items */
            for(i = 0; i < curr_app_str->total_count; i++)
            {
                if(curr_app_str->strings[i].filter == MMI_TRUE)
                {
                    fprintf(p_file, "    ADD_APPLICATION_STRING2(%s, \"%s\", \"%s\");\n", 
                        curr_app_str->strings[i].string_id_str, 
                        curr_app_str->strings[i].string_data_str ? curr_app_str->strings[i].string_data_str : curr_app_str->strings[i].string_id_str, /* Use STRID if English translation is not supplied. */
                        "Generated by Resgen_XML");
                }
            }
            fprintf(p_file, "/******************** String resource IDs - finish ********************/\n");
        }
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}
    
#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
    /*****************************************************************************
     * FUNCTION
     *  mmi_rp_str_output_phase2_app_c_file
     * DESCRIPTION
     *  Output Resources
     * PARAMETERS
     *  app_index      [IN]    App_index in resource base table
     *  p_file      [IN]    File pointer to output file
     * RETURNS
     *  void
     *****************************************************************************/
    void mmi_rp_str_output_phase2_app_c_file(U32 app_index)
    {

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0, j = 0;
    FILE * p_file = NULL;
    mmi_rp_str_data_struct *curr_app_str = &(g_mmi_rp_str_cntx.app_str_data[app_index]);
    U32 strResourId = g_mmi_resource_base_table[app_index].min + 1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Check if no str IDs. */
    if(curr_app_str->total_count <= 0)
    {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
    }
    else
    {
#ifndef __RESGEN_INTERNAL_OFFLINE__                    
            p_file = mmi_rp_open_population_c_file(app_index, RES_LEGACY_POP_STRING_MASK);
            
            if(p_file== NULL)            /* Rest resources will open the file in append mode */
            {
                 MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
            }
                
            fprintf(p_file, "\n");
            fprintf(p_file, "/******************** String resource IDs - begin ********************/\n");
#endif //__RESGEN_INTERNAL_OFFLINE__
                /* 1. Add str items */
                for(i = 0; i < curr_app_str->total_count; i++)
                {
                    if(curr_app_str->strings[i].filter == MMI_TRUE)
                    {
#ifdef __RESGEN_INTERNAL_OFFLINE__ 
                        //printf("    ADD_APPLICATION_STRING2(%s, \"%s\", \"%s\");\n", 
                        //    curr_app_str->strings[i].string_id_str, 
                        //    curr_app_str->strings[i].string_data_str ? curr_app_str->strings[i].string_data_str : curr_app_str->strings[i].string_id_str, /* Use STRID if English translation is not supplied. */
                        //    "Generated by Resgen_XML");
#ifdef __LOW_COST_SUPPORT_COMMON__
						StringAdaptorSetString(strResourId,
						                       curr_app_str->strings[i].string_data_str ? curr_app_str->strings[i].string_data_str : "?",
						                       ((g_mmi_resource_base_table[app_index].appname)?(g_mmi_resource_base_table[app_index].appname):("APP name unknown")),
                    "Generated by Resgen_XML",
						                       curr_app_str->strings[i].string_id_str,
						                       ((g_mmi_resource_base_table[app_index].res_path)?(g_mmi_resource_base_table[app_index].res_path):("Res path unknown")),
						                       0);
#else //__LOW_COST_SUPPORT_COMMON__
						StringAdaptorSetString(strResourId,
						                       curr_app_str->strings[i].string_data_str ? curr_app_str->strings[i].string_data_str : curr_app_str->strings[i].string_id_str,
						                       ((g_mmi_resource_base_table[app_index].appname)?(g_mmi_resource_base_table[app_index].appname):("APP name unknown")),
                    "Generated by Resgen_XML",
						                       curr_app_str->strings[i].string_id_str,
						                       ((g_mmi_resource_base_table[app_index].res_path)?(g_mmi_resource_base_table[app_index].res_path):("Res path unknown")),
						                       0);
#endif //__LOW_COST_SUPPORT_COMMON__
						strResourId++;
                        //printf("Emulate ADD_APPLICATION_STRING3: %s ,%s\n",curr_app_str->strings[i].string_id_str,curr_app_str->strings[i].string_data_str ? curr_app_str->strings[i].string_data_str : curr_app_str->strings[i].string_id_str);
#else //__RESGEN_INTERNAL_OFFLINE__
                        fprintf(p_file, "    ADD_APPLICATION_STRING2(%s, \"%s\", \"%s\");\n", 
                            curr_app_str->strings[i].string_id_str, 
                            curr_app_str->strings[i].string_data_str ? curr_app_str->strings[i].string_data_str : curr_app_str->strings[i].string_id_str, /* Use STRID if English translation is not supplied. */
                            "Generated by Resgen_XML");
    
#endif //__RESGEN_INTERNAL_OFFLINE__
                    }
                }
#ifndef __RESGEN_INTERNAL_OFFLINE__                 
                fprintf(p_file, "/******************** String resource IDs - finish ********************/\n");
                fclose(p_file);
#endif //__RESGEN_INTERNAL_OFFLINE__
    }

    }

#endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__
#endif //__POPULATE_NO_STRING_DATA__
