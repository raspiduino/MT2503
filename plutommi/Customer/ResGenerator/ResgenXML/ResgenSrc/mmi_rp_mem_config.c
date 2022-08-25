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
 *  mmi_rp_mem_config.c
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
#include "mmi_rp_mem_config.h"
#include "mmi_rp_hash.h"

#include "mmi_res_range_def.h"


extern const mmi_resource_base_struct g_mmi_resource_base_table[];

#define MMI_RP_MEM_CONFIG_CURR_APP       g_mmi_rp_mem_config_cntx.app_mem_config_data[g_mmi_rp_mgr_cntx.cur_app_index]

mmi_rp_mem_config_cntx_struct g_mmi_rp_mem_config_cntx;

#define MMI_RP_MEM_CFG_DATA_FILE_PATH   MMI_RP_MGR_XML_DEBUG_PATH
#define MMI_RP_MEM_CFG_DATA_FILE    "mmi_mem_cfg.txt"
#define MMI_RP_MEM_CFG_SCRIPT       "mmi_mem_cfg.pl"

#ifdef RESXML_VC_DEBUG
#define MMI_RP_MCU_PATH    "..\\..\\..\\..\\..\\"
#else
#define MMI_RP_MCU_PATH    "..\\..\\..\\"
#endif

FILE    *p_file_to_pl = NULL;

static const char *g_supported_attr[] = {
    MMI_RP_MGR_ATTR_BASE,       /* base memory size, base = extra_base + heap + base(CUI) */
    MMI_RP_MGR_ATTR_FG,         /* fg memory size, fg' = fg + fg(CUI) */
    MMI_RP_MGR_ATTR_INC,        /* include file(s) */
    MMI_RP_MGR_ATTR_HEAP,       /* heap size */
    MMI_RP_MGR_ATTR_HEAP_S,     /* heap shrink size */
    MMI_RP_MGR_ATTR_HEAP_SRC,   /* heap source */
    MMI_RP_MGR_ATTR_EXTRA_BASE, /* extra part of base memory size */
    MMI_RP_MGR_ATTR_CUI,        /* cui dependency */
    MMI_RP_MGR_ATTR_VRT_MEM_FACTOR  /* vrt memory factor */
};

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mem_config_init
 * DESCRIPTION
 *  Initializes the mem_config context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mem_config_init(void)
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

    memset(&g_mmi_rp_mem_config_cntx, 0, sizeof(g_mmi_rp_mem_config_cntx));

    g_mmi_rp_mem_config_cntx.app_mem_config_data = (mmi_rp_mem_config_data_struct*)malloc(sizeof(mmi_rp_mem_config_data_struct) * g_mmi_rp_mgr_cntx.total_apps);
    if(!g_mmi_rp_mem_config_cntx.app_mem_config_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mem_config_cntx.app_mem_config_data, 0, sizeof(mmi_rp_mem_config_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_mem_config_cntx.concurrent_apps.str_apps = (U8**)malloc(sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps);
    if(!g_mmi_rp_mem_config_cntx.concurrent_apps.str_apps)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mem_config_cntx.concurrent_apps.str_apps, 0, sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_mem_config_cntx.concurrent_apps.str_apps_converted = (U8**)malloc(sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps);
    if(!g_mmi_rp_mem_config_cntx.concurrent_apps.str_apps_converted)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mem_config_cntx.concurrent_apps.str_apps_converted, 0, sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_mem_config_cntx.hash = mmi_rp_hash_create(0xFFFF);    /* 0xFFFF is the resource ID range */

    if (p_file_to_pl == NULL)
    {
        U8      str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
        strcpy(str_filename, MMI_RP_MEM_CFG_DATA_FILE_PATH);
        strcat(str_filename, MMI_RP_MEM_CFG_DATA_FILE);

        p_file_to_pl = fopen(str_filename, "wt+");
        if(!p_file_to_pl)
        {
            /* Error writing output file. Exit. */
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
            return;
        }
    }
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mem_config_start_handler
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
int mmi_rp_mem_config_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    U8 *curr_heap_size = NULL;
    MMI_BOOL curr_cui_flag = MMI_FALSE, is_attr_supported = MMI_FALSE;
    U8 *curr_cuidep = NULL;
    S32 parent_tag_id = -1;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Memory -start: %s\n", el);

    /* Checking there's no parent tag */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    // check
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
     {
        if(!strcmp(g_mmi_resource_base_table[i].appname, g_mmi_rp_mgr_cntx.cur_app->appname))
        {
            if(!g_mmi_rp_mgr_cntx.app_str_id[i])
            {
                MMI_RP_ERROR(RP_ERR_MEM_CONFIG_APP_NAME_STR_ID_NOT_FOUND);
                return MMI_RP_PARSE_ERROR_SKIP_TAG;
            }
        }
    }

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        for (i=0; i<sizeof(g_supported_attr)/sizeof(char *); i++)
        {
            if (strcmp(attr[index], g_supported_attr[i]) == 0)
            {
                is_attr_supported = MMI_TRUE;
                break;
            }
        }

        if (!is_attr_supported)
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        index += 2;
    }

    // output
    // id should always be first
    fprintf(p_file_to_pl, "[id]%s", g_mmi_rp_mgr_cntx.cur_app->appname);

    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
     {
        if(!strcmp(g_mmi_resource_base_table[i].appname, g_mmi_rp_mgr_cntx.cur_app->appname))
        {
            /* output app string id to perl */
            fprintf(p_file_to_pl, "\t[str]%s", g_mmi_rp_mgr_cntx.app_str_id[i]);           

            /* output app type to perl */
            if (g_mmi_rp_mgr_cntx.app_type[i])
                fprintf(p_file_to_pl, "\t[app_type]%s", g_mmi_rp_mgr_cntx.app_type[i]);
        }
    }

    index = 0;
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        fprintf(p_file_to_pl, "\t[%s]%s", attr[index], attr[index + 1]);

        index += 2;
    }

    fprintf(p_file_to_pl, "\n");
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mem_config_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mem_config_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Memory -end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_appconcurrent_start_handler
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
int mmi_rp_appconcurrent_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    U8 *curr_concurrent_apps = NULL;
    S32 parent_tag_id = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Appconcurrent -start: %s\n", el);

    /* Checking there's no parent tag */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

     /* Concurrent apps shared mem exclusion exceeded the total_apps */
    if(g_mmi_rp_mem_config_cntx.concurrent_apps.count >= (g_mmi_rp_mgr_cntx.total_apps))
    {
        MMI_RP_ERROR(RP_ERR_MEM_CONFIG_CONCURRENT_APPS_EXCEED);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    // check
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        if((strcmp(attr[index], MMI_RP_MGR_ATTR_CONCURRENT) != 0) &&
           (strcmp(attr[index], MMI_RP_MGR_ATTR_CONCURRENT_W_ORDER) != 0))
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        index += 2;
    }

    // output
    index = 0;
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        fprintf(p_file_to_pl, "[%s]%s\t", attr[index], attr[index + 1]);

        index += 2;
    }
    fprintf(p_file_to_pl, "\n");
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_appconcurrent_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_appconcurrent_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Appconcurrent -end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mem_config_output_phase_1
 * DESCRIPTION
 *  Output mmi_rp_app_data.h file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mem_config_output_phase_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    U8 str_output_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    U8 *temp_str = NULL;
    U8 *temp_comma = NULL, *temp_asterisk = NULL, *temp__ = NULL;
    U8 temp[MMI_RP_MGR_MAX_FILE_NAME_LEN], temp_conv[MMI_RP_MGR_MAX_FILE_NAME_LEN], temp_check[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    U32 len = 0, temp_c = 0, temp_app_len = 0;
    MMI_BOOL temp_check_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. Output mmi_rp_app_data.h file. */
    memset(str_output_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_output_filename, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    strcat(str_output_filename, MMI_RP_MEM_CONFIG_FILE_NAME_DATA_H);

    if(p_file = fopen(str_output_filename, "w"))
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
            p_file, 
            MMI_RP_MEM_CONFIG_FILE_NAME_DATA_H, 
            "Resource populate function generated by XML resgen", 
            "MTK resgenerator XML parser");
        mmi_rp_output_phase1_begin(p_file, MMI_RP_MEM_CONFIG_HEADER_GUARD_DATA_H);             /* Write Header guard Begin */

        /* #define for heapsizes */
        fprintf(p_file, "\n/* App Heap size */\n"); 
        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            if(!g_mmi_resource_base_table[i].appname || !g_mmi_rp_mem_config_cntx.app_mem_config_data[i].str_heap_size)
            {
                continue;
            }
            fprintf(p_file, "#define HEAP_SIZE_%s    (%s)\n", 
                g_mmi_resource_base_table[i].appname, 
                g_mmi_rp_mem_config_cntx.app_mem_config_data[i].str_heap_size);
        }

        /* #define for mempool sizes */
        fprintf(p_file, "\n\n/* App Mempool size */\n"); 
        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            if(!g_mmi_resource_base_table[i].appname || !g_mmi_rp_mem_config_cntx.app_mem_config_data[i].str_heap_size)
            {
                continue;
            }

            temp_str = NULL;

            fprintf(p_file, "#define APPMEM_%s_POOL_SIZE    (HEAP_SIZE_%s", 
                g_mmi_resource_base_table[i].appname,
                g_mmi_resource_base_table[i].appname);

            if(g_mmi_rp_mem_config_cntx.app_mem_config_data[i].str_cuidep)
            {
                temp_str = g_mmi_rp_mem_config_cntx.app_mem_config_data[i].str_cuidep;

                fprintf(p_file, " + ");

                while(*temp_str)
                {
                    temp_comma = temp_asterisk = NULL;
                    temp[0] = 0;

                    while(*temp_str == ' ')
                    {
                        temp_str++;      /* Getting rid of leading spaces */
                    }

                    temp_comma = strchr(temp_str, ',');  /* One CUI_BASE*<N> */
                    if(temp_comma)
                    {
                        len = (U32)(temp_comma - temp_str);
            
                        if(len != 0)       
                        {
                            strncpy(temp, temp_str, len);
                            temp[len] = 0;
                            temp_str = temp_comma + 1;
                        }
                        else
                        {
                            temp_str++;
                            continue;           /* To remove consecutive ','.*/
                        }
                    }
                    else
                    {
                        len = strlen(temp_str);
                        strncpy(temp, temp_str, len);
                        temp[len] = 0;
                        temp_str += len;
                    }

                    temp_asterisk = strchr(temp, '*');  

                    if(*temp)
                    {
                        fprintf(p_file, "APPMEM_");
                        j = 0;
                        while((temp[j] != 0) && (temp[j] != ' ') && (temp[j] != '*'))
                        {
                            fprintf(p_file, "%c", temp[j]);
                            j++;
                        }
                        fprintf(p_file, "_POOL_SIZE");
                    }
                    if(temp_asterisk)
                    {
                        fprintf(p_file, "%s", temp_asterisk);
                    }
                    if(temp_comma)
                    {
                        fprintf(p_file, " + ");
                    }
                }
            }
            fprintf(p_file, ")\n");
        }

        /* #define for concurrent app mem pool */
        fprintf(p_file, "\n\n/* Concurrent Apps Mempool size */\n"); 
        for(i = 0; i < g_mmi_rp_mem_config_cntx.concurrent_apps.count; i++)
        {
            temp_comma = NULL;
            temp_str = g_mmi_rp_mem_config_cntx.concurrent_apps.str_apps[i];
            memset(temp, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
            temp_c = 0;

            if(temp_str)
            {
                /* Input */
                /* <APPCONCURRENT concurrent="APP1, APP2"/> */
                /* Output */
                /* <<#define  APPMEM_CONC_APP1_APP2_POOL_SIZE>>   APPMEM_APP1_POOL_SIZE + APPMEM_APP2_POOL_SIZE */
                while(*temp_str)
                {
                    /* Ignoring un-recognized apps */
                    memset(temp_check, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
                    temp_app_len = 0;

                    /* Each app is fetched */
                    sprintf(temp + (temp_c++), "%c", MMI_RP_MEM_CONFIG_CONC_APP_DELIM); 
                    while(*temp_str == ' ')
                    {
                        temp_str++;      /* Removing leading spaces. */
                    }

                    temp_comma = strchr(temp_str, ',');

                    if(temp_comma)
                    {
                        while((*temp_str != ' ') && (*temp_str != 0) && (*temp_str != ',')) 
                        {
                            temp_check[temp_app_len++] = *temp_str;
                            sprintf(temp + (temp_c++), "%c", *temp_str); 
                            temp_str++;
                        }
                        temp_str = temp_comma + 1;
                    }
                    else
                    {
                        while((*temp_str != ' ') && (*temp_str != 0)) 
                        {
                            temp_check[temp_app_len++] = *temp_str;
                            sprintf(temp + (temp_c++), "%c", *temp_str); 
                            temp_str++;
                        }
                        while(*temp_str)    /* Last APP : Pointing to EOS so that we can process the unrecognized apps */
                        {
                            temp_str++;
                        }
                    }

                    /* Ignoring un-recognized apps */
                    if(*temp_check)
                    {
                        temp_check_valid = MMI_FALSE;

                        for(j = 0; j < g_mmi_rp_mgr_cntx.total_apps; j++)
                        {
                            if(strcmp(temp_check, g_mmi_resource_base_table[j].appname) == 0)
                            {
                                temp_check_valid = MMI_TRUE;
                                if(!g_mmi_rp_mem_config_cntx.app_mem_config_data[j].str_heap_size)
                                {
                                    /* If no heapsize has been speified for this app,  we'll specify it here with 0 */
                                    fprintf(p_file, "#define APPMEM_%s_POOL_SIZE    (0)\n", temp_check);
                                }
                                break;
                            }
                        }
                        if(!temp_check_valid)
                        {
                            break;
                        }
                    }
                }
            }

            if(!temp_check_valid)
            {
                continue;       /* Ignore this concurrent config as some app isnot populated */
            }

            /* Store this value for o/p in app_asm_pool_sub_union */
            temp_c = 0;
            while(temp[temp_c])
            {
                temp_conv[temp_c] = ((temp[temp_c] == MMI_RP_MEM_CONFIG_CONC_APP_DELIM) ? '_' : temp[temp_c]);
                temp_c++;
            }
            temp_conv[temp_c] = 0;

            g_mmi_rp_mem_config_cntx.concurrent_apps.str_apps_converted[i] = mmi_rp_hash_add(g_mmi_rp_mem_config_cntx.hash, temp_conv);

            if(*temp)
            {
                fprintf(p_file, "#define APPMEM_CONC%s_POOL_SIZE    ", temp_conv);

                /* #define  APPMEM_CONC_APP1_APP2_POOL_SIZE   <<APPMEM_APP1_POOL_SIZE + APPMEM_APP2_POOL_SIZE>> */
                temp__ = strchr(temp, MMI_RP_MEM_CONFIG_CONC_APP_DELIM);      /* 1st app #APP1#APP2 */

                fprintf(p_file, "(");
                if(!temp__ || !(*temp__))
                {
                    fprintf(p_file, "0");
                }
                else
                {
                    temp__++;
                }
                
                while(*temp__)
                {
                    fprintf(p_file, "APPMEM_");
                    while((*temp__ != MMI_RP_MEM_CONFIG_CONC_APP_DELIM) && (*temp__ != 0))
                    {
                        fprintf(p_file, "%c", *temp__);
                        temp__++;
                    }
                    fprintf(p_file, "_POOL_SIZE");

                    if(*temp__ == MMI_RP_MEM_CONFIG_CONC_APP_DELIM)
                    {
                        fprintf(p_file, " + ");
                        temp__++;
                    }
                }
                fprintf(p_file, ")\n");
            }
        }

        /* String IDs for APP_name */
        fprintf(p_file, "\n\n/* mmi_app_info_struct structure declaration */\n");
        fprintf(p_file, "typedef struct {\n");
        fprintf(p_file, "    U16 baseId;\n");
        fprintf(p_file, "    U16 baseIdMax;\n");
        fprintf(p_file, "    U16 name;\n");
        fprintf(p_file, "    U32 heap_size;\n");
        fprintf(p_file, "    U32 asm_pool_size;\n");
        fprintf(p_file, "} mmi_app_info_struct;\n");

        fprintf(p_file, "\n/* extern declaration to use the mmi_app_info array */\n");
        fprintf(p_file, "extern const mmi_app_info_struct mmi_app_info[];\n");
        fprintf(p_file, "\n/* extern declaration to use the mmi_app_info_array_size() function to get the number of  elements */\n");
        fprintf(p_file, "extern U32 mmi_app_info_array_size(void);\n");
        
        mmi_rp_output_phase1_finish(p_file, MMI_RP_MEM_CONFIG_HEADER_GUARD_DATA_H);             /* Write Header guard Finish */
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mem_config_output_phase_2
 * DESCRIPTION
 *  Output mmi_rp_app_data.c file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mem_config_output_phase_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0;
    U8 str_output_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    MMI_BOOL is_empty = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 2. Output mmi_rp_app_data.c file. */
    memset(str_output_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_output_filename, MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES);
    strcat(str_output_filename, MMI_RP_MEM_CONFIG_FILE_NAME_DATA_C);

    if(p_file = fopen(str_output_filename, "w"))
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
            p_file, 
            MMI_RP_MEM_CONFIG_FILE_NAME_DATA_C, 
            "Resource populate function generated by XML resgen", 
            "MTK resgenerator XML parser");

        /* Include headers */
        fprintf(p_file, "\n\n#include \"MMIDataType.h\"\n");
        fprintf(p_file, "#include \"mmi_rp_app_data.h\"\n");
        fprintf(p_file, "#include \"mmi_rp_all_defs.h\"\n");

        fprintf(p_file, "\nconst mmi_app_info_struct mmi_app_info[] = {\n");
        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            if(!g_mmi_resource_base_table[i].appname || !g_mmi_rp_mem_config_cntx.app_mem_config_data[i].str_heap_size)
            {
                continue;
            }

            if(!g_mmi_rp_mgr_cntx.app_str_id[i])
            {
                MMI_RP_ERROR(RP_ERR_MEM_CONFIG_APP_NAME_STR_ID_NOT_FOUND);
                continue;
            }
              
            fprintf(p_file, "    {RESOURCE_BASE_%s, RESOURCE_BASE_%s_END, %s, HEAP_SIZE_%s, ", 
                g_mmi_resource_base_table[i].appname,
                g_mmi_resource_base_table[i].appname,
                g_mmi_rp_mgr_cntx.app_str_id[i],
                g_mmi_resource_base_table[i].appname);
            is_empty = MMI_FALSE;

            if(g_mmi_rp_mem_config_cntx.app_mem_config_data[i].is_cui)
            {
                fprintf(p_file, "0},\n");
            }
            else
            {
                fprintf(p_file, "APPMEM_%s_POOL_SIZE},\n",g_mmi_resource_base_table[i].appname); 
            }
        }

        if(is_empty)
        {
            fprintf(p_file, "    0\n");
        }
        fprintf(p_file, "};\n");

        /* Function to get the size of the array */
        fprintf(p_file, "\n\n/*****************************************************************************\n");
        fprintf(p_file, " * FUNCTION\n");
        fprintf(p_file, " *  mmi_app_info_array_size\n");
        fprintf(p_file, " * DESCRIPTION\n");
        fprintf(p_file, " *  Get size of mmi_app_info[] array \n");
        fprintf(p_file, " * PARAMETERS\n");
        fprintf(p_file, " *  void\n");
        fprintf(p_file, " * RETURNS\n");
        fprintf(p_file, " *  Number of elements\n");
        fprintf(p_file, " *****************************************************************************/\n");
        fprintf(p_file, "U32 mmi_app_info_array_size(void)\n");
        fprintf(p_file, "{\n");
        if(is_empty)
        {
            fprintf(p_file, "    return 0;       /* There's no element in the array. */\n");
        }
        else
        {
            fprintf(p_file, "    return sizeof(mmi_app_info)/sizeof(mmi_app_info_struct);\n");
        }
        fprintf(p_file, "}\n");

        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mem_config_output_phase_3
 * DESCRIPTION
 *  Output mmi_rp_app_mem_config.h file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mem_config_output_phase_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0;
    U8 str_output_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 3. Output mmi_rp_app_mem_config.h file. */
    memset(str_output_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_output_filename, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    strcat(str_output_filename, MMI_RP_MEM_CONFIG_FILE_NAME_MEM_CONFIG_H);

    if(p_file = fopen(str_output_filename, "w"))
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
            p_file, 
            MMI_RP_MEM_CONFIG_FILE_NAME_MEM_CONFIG_H, 
            "Resource populate function generated by XML resgen", 
            "MTK resgenerator XML parser");
        mmi_rp_output_phase1_begin(p_file, MMI_RP_MEM_CONFIG_HEADER_GUARD_MEM_CONFIG_H);             /* Write Header guard Begin */

        fprintf(p_file, "\ntypedef union {\n");

        /* All app mem pools */
        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            if(!g_mmi_resource_base_table[i].appname || 
                !g_mmi_rp_mem_config_cntx.app_mem_config_data[i].str_heap_size ||
                g_mmi_rp_mem_config_cntx.app_mem_config_data[i].is_cui)
            {
                continue;
            }

            fprintf(p_file, "    kal_uint8 APP_%s[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_%s_POOL_SIZE)];\n", 
                g_mmi_resource_base_table[i].appname,
                g_mmi_resource_base_table[i].appname);
        }

        /* All concurrent app mem pools */
        for(i = 0; i < g_mmi_rp_mem_config_cntx.concurrent_apps.count; i++)
        {
            if(!g_mmi_rp_mem_config_cntx.concurrent_apps.str_apps_converted[i])
            {
                continue;
            }
            fprintf(p_file, "    kal_uint8 APP_CONC%s[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_CONC%s_POOL_SIZE)];\n", 
                g_mmi_rp_mem_config_cntx.concurrent_apps.str_apps_converted[i],
                g_mmi_rp_mem_config_cntx.concurrent_apps.str_apps_converted[i]);
        }

        fprintf(p_file, "    kal_uint8 DEFAULT_POOL[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPLIB_MEM_AP_POOL_DEFAULT_SIZE)];");
        fprintf(p_file, "\n}app_asm_pool_sub_union;\n");

        mmi_rp_output_phase1_finish(p_file, MMI_RP_MEM_CONFIG_HEADER_GUARD_MEM_CONFIG_H);             /* Write Header guard Finish */
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mem_config_output_phase_4
 * DESCRIPTION
 *  Output resgen_xml_app_heap_size.log file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mem_config_output_phase_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0;
    U8 str_output_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    MMI_BOOL is_empty = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 2. Output Log for APP's which have not declared heapsize. */
    memset(str_output_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_output_filename, MMI_RP_MGR_XML_DEBUG_PATH);
    strcat(str_output_filename, MMI_RP_MEM_CONFIG_FILE_LOG);

    if(p_file = fopen(str_output_filename, "w"))
    {
        fprintf(p_file, "Resgen XML log for applications which did not specify heap size\n");
        fprintf(p_file, "S.No.\tApp name\tStatus\tHeap size\n");

        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            if(g_mmi_resource_base_table[i].appname)
            {
                fprintf(p_file, "%d\t%s\t", i+1, g_mmi_resource_base_table[i].appname);
                if(!g_mmi_rp_mem_config_cntx.app_mem_config_data[i].str_heap_size)
                {
                    fprintf(p_file, "Not defined\n");
                }
                else
                {
                    fprintf(p_file, "Defined\t%s\n", g_mmi_rp_mem_config_cntx.app_mem_config_data[i].str_heap_size);
                }
            }
        }
        fprintf(p_file, "\n");
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mem_config_output_phase
 * DESCRIPTION
 *  Output 3 files and 1 log file
 *  1. mmi_rp_app_data.h
 *  2. mmi_rp_app_data.c
 *  3. mmi_rp_app_mem_config.h
 *  4. resgen_xml_app_heap_size.log
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mem_config_output_phase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char sys_str[MMI_RP_MGR_MAX_SYS_CMD_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fclose(p_file_to_pl);
    
    memset(sys_str, 0, MMI_RP_MGR_MAX_SYS_CMD_LEN);
    printf("[Dependency] tools\\%s\n", MMI_RP_MEM_CFG_SCRIPT);
    sprintf(sys_str, "perl %s %s %s %s %s 2>&1", 
                MMI_RP_MCU_PATH "tools\\" MMI_RP_MEM_CFG_SCRIPT,
                MMI_RP_MEM_CFG_DATA_FILE_PATH MMI_RP_MEM_CFG_DATA_FILE,
                MMI_RP_MCU_PATH,
                MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES,
                MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    fflush(stdout);
    if(system(sys_str))
    {
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }
}    



