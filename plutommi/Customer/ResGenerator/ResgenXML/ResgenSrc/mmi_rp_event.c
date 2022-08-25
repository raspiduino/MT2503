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
 *  mmi_rp_event.c
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
#include "mmi_rp_event.h"
#include "mmi_rp_hash.h"

#include "mmi_res_range_def.h"


extern const mmi_resource_base_struct g_mmi_resource_base_table[];

void mmi_rp_event_output_phase1_app_def_h_file(U32 app_index, FILE *p_file);
void mmi_rp_event_output_phase2_app_c_file(U32 app_index, FILE *p_file);

#define MMI_RP_EVENT_CURR_APP_EVENT       g_mmi_rp_event_cntx.app_event_data[g_mmi_rp_mgr_cntx.cur_app_index]

mmi_rp_event_cntx_struct g_mmi_rp_event_cntx;
mmi_rp_event_type_list_node_struct *g_mmi_rp_event_type_list_header = NULL;
mmi_rp_event_type_list_node_struct *g_mmi_rp_event_type_list_trail = NULL;
static U8 *g_mmi_rp_event_type_name_str[MMI_RP_EVENT_TYPE_TOTAL] = 
{
    MMI_RP_MGR_VAL_NONE,
    MMI_RP_MGR_VAL_SENDER
};



/*****************************************************************************
 * FUNCTION
 *  mmi_rp_event_init
 * DESCRIPTION
 *  Initializes the event context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_event_init(void)
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

    memset(&g_mmi_rp_event_cntx, 0, sizeof(g_mmi_rp_event_cntx));
    g_mmi_rp_event_cntx.app_event_data = (mmi_rp_event_data_struct*)malloc(sizeof(mmi_rp_event_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    if(!g_mmi_rp_event_cntx.app_event_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_event_cntx.app_event_data, 0, sizeof(mmi_rp_event_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_event_cntx.hash = mmi_rp_hash_create(0xFFFF);    /* 0xFFFF is the resource ID range */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_event_set_app_range
 * DESCRIPTION
 *  Initializes the event context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_event_set_app_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 range = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_RP_EVENT_CURR_APP_EVENT.events == NULL)
    {
        range = g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min + 1;
        MMI_RP_EVENT_CURR_APP_EVENT.events = (mmi_rp_event_id_struct*)malloc(sizeof(mmi_rp_event_id_struct) * range);

        if((!MMI_RP_EVENT_CURR_APP_EVENT.events) && (range > 0))
        {
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }

        memset(MMI_RP_EVENT_CURR_APP_EVENT.events, 0, sizeof(mmi_rp_event_id_struct) * range);
    }
}


    
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_event_start_handler
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
int mmi_rp_event_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    U8 *curr_event_id = NULL;
    mmi_rp_event_type_enum curr_event_type_id = MMI_RP_EVENT_TYPE_NONE;
    S32 parent_tag_id = -1;
    mmi_rp_event_type_list_node_struct *new_node = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Event -start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /* String ID exceeded the app_range - 1 (BASE_ID is reserved for Mainmenu app) */
    if(MMI_RP_EVENT_CURR_APP_EVENT.total_count >= (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID) == 0)
        {
            curr_event_id = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_TYPE) == 0)
        {
            if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_SENDER) == 0)
            {
                curr_event_type_id = MMI_RP_EVENT_TYPE_SENDER;
            }
        }
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        index += 2;
    }

    if(curr_event_id != NULL)
    {
        if(!mmi_rp_hash_find(g_mmi_rp_event_cntx.hash, curr_event_id))
        {
            MMI_RP_EVENT_CURR_APP_EVENT.events[MMI_RP_EVENT_CURR_APP_EVENT.total_count].event_id_str = mmi_rp_hash_add(g_mmi_rp_event_cntx.hash, curr_event_id);
            MMI_RP_EVENT_CURR_APP_EVENT.total_count++;

            /* Add the SENDER type event in the list. */
            new_node = (mmi_rp_event_type_list_node_struct*) malloc(sizeof(mmi_rp_event_type_list_node_struct));
            if (!new_node)
            {
                /* Memory not available */
                MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE); 
            }
            memset(new_node, 0, sizeof(mmi_rp_event_type_list_node_struct));
            new_node->id_str = MMI_RP_EVENT_CURR_APP_EVENT.events[MMI_RP_EVENT_CURR_APP_EVENT.total_count - 1].event_id_str;
            new_node->type = curr_event_type_id;
            new_node->filename = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_H_FILE, g_mmi_rp_mgr_cntx.cur_app->appname);
            if(!g_mmi_rp_event_type_list_header)
            {
                g_mmi_rp_event_type_list_trail = g_mmi_rp_event_type_list_header = new_node;
            }
            else
            {
                g_mmi_rp_event_type_list_trail->next = new_node;
                g_mmi_rp_event_type_list_trail = new_node;
            }
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
 *  mmi_rp_event_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_event_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Event -end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_event_data_handler
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
int mmi_rp_event_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Event -data: %s\n", data);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_event_filter
 * DESCRIPTION
 *  This function is for resgen to filter image resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_event_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0, k =0, app_c = 0, str_c = 0;
    U8 *search_id = NULL, *cand_id = NULL;
    MMI_BOOL found = MMI_FALSE;
    mmi_rp_event_data_struct *curr_app_event1 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        curr_app_event1 = &(g_mmi_rp_event_cntx.app_event_data[i]);
        for(j =0; j < curr_app_event1->total_count; j++)
        {
            found = MMI_TRUE;       /* Currently, populate all res. */

            /* Put condition here */
            /* if(XXX) { found = MMI_FALSE; } */

            curr_app_event1->events[j].filter = found;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_event_output_phase1
 * DESCRIPTION
 *  Output ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_event_output_phase1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    U8 *str_output_filename = NULL;
    FILE *p_event_type_log_file = NULL;
    U8 str_log_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    mmi_rp_event_type_list_node_struct *temp = NULL;

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
            mmi_rp_event_output_phase1_app_def_h_file(i, p_file);
            fclose(p_file);
        }
        else
        {
            /* Error writing output file. Exit. */
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
        }
    }

    /* 2. Output log file for event type "resgen_xml_event_type.log". */
    memset(str_log_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_log_filename, MMI_RP_MGR_XML_DEBUG_PATH);
    strcat(str_log_filename, MMI_RP_EVENT_TYPE_LOGE_FILE_NAME);
    
    if(p_event_type_log_file = fopen(str_log_filename, "w"))
    {
        fprintf(p_event_type_log_file, "EVENT ID\tType\tFile name\n");
        temp = g_mmi_rp_event_type_list_header;
        while(temp)
        {
            fprintf(p_event_type_log_file, "%s\t%s\t%s\n", temp->id_str, g_mmi_rp_event_type_name_str[temp->type], temp->filename);
            temp = temp->next;
        }
        fclose(p_event_type_log_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_event_output_phase1_app_def_h_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_event_output_phase1_app_def_h_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0;
    U8 str_enum_name[MMI_RP_OUTPUT_ENUM_NAME_MAX], str_enum_max[MMI_RP_OUTPUT_ENUM_NAME_MAX];
    MMI_BOOL first = MMI_TRUE;
    mmi_rp_event_data_struct *curr_app_event = &(g_mmi_rp_event_cntx.app_event_data[app_index]);
    S32 app_enum_log_counter = -1;      /* -1 for debug purpose */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        memset(str_enum_name, 0, sizeof(str_enum_name));
        strcpy(str_enum_name, "mmi_rp_");
        strcat(str_enum_name, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_name, "_event_enum");
        for(i = 0; i < strlen(str_enum_name); i++)
        {
            str_enum_name[i] = tolower(str_enum_name[i]);
        }

        memset(str_enum_max, 0, sizeof(str_enum_max));
        strcpy(str_enum_max, "MMI_RP_");
        strcat(str_enum_max, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_max, "_EVENT_MAX");
        for(i = 0; i < strlen(str_enum_max); i++)
        {
            str_enum_max[i] = toupper(str_enum_max[i]);
        }

        /* Check if no str IDs. */
        if(curr_app_event->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            fprintf(p_file, "\n\n");
            fprintf(p_file, "/******************** Events resource IDs - begin ********************/\n");
            fprintf(p_file, "typedef enum\n{\n");

            for(i = 0; i < curr_app_event->total_count; i++)
            {
                if(curr_app_event->events[i].filter == MMI_FALSE)
                {
                    continue;
                }

                if(first)
                {
                    fprintf(p_file, "    %s = %d + 1, /* BASE_ID + 1 */\n", curr_app_event->events[i].event_id_str, g_mmi_resource_base_table[app_index].min);
                    first = MMI_FALSE;

                    app_enum_log_counter = g_mmi_resource_base_table[app_index].min + 1;
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_event->events[i].event_id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
                else
                {
                    fprintf(p_file, "    %s,\n", curr_app_event->events[i].event_id_str);
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_event->events[i].event_id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
            }

            fprintf(p_file, "    %s\n", str_enum_max);
            fprintf(p_file, "}%s;\n", str_enum_name);
            fprintf(p_file, "/******************** Events resource IDs - begin ********************/\n");
        }
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_event_output_phase2
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_event_output_phase2(void)
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
            mmi_rp_event_output_phase2_app_c_file(i, p_file);
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
 *  mmi_rp_event_output_phase2_app_c_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_event_output_phase2_app_c_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        /* There's no current requirement to populate Event resources in .c files. */
        /* Keep it here for future reference. */
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}
    

