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
 *  mmi_rp_mmi_cache.c
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "MMIDataType.h"
#include "mmi_rp_xml.h"
#include "mmi_rp_xml_def.h"
#include "mmi_rp_hash.h"
#include "mmi_rp_mmi_cache.h"


#ifdef VENUS_MMI
#define MMI_FOLDER "VENUS_MMI\\"
#else
#define MMI_FOLDER "PLUTO_MMI\\"
#endif

#define MMI_CACHE_DEFAULT_VALUE_H_FILE  "mmi_cache_default_value.h"
#define MMI_CACHE_TABLE_C_FILE  "mmi_cache_table.c"
#define MMI_CACHE_TABLE_H_FILE  "mmi_cache_table.h"
#define MMI_CACHE_NVRAM_EDIOTR_H_FILE "mmi_cache_nvram_editor.h"
#define MMI_CACHE_CAT_XML_FILE "custom_mmi_cache_cat.xml"

#ifdef RESXML_VC_DEBUG
#define CAT_XML_OUTPUT_FOLDER   "..\\..\\..\\..\\..\\custom\\common\\"
#else
#define CAT_XML_OUTPUT_FOLDER   "..\\..\\..\\custom\\common\\"
#endif

#define MMI_CACHE_DEFAULT_VALUE_PATH MMI_RP_MGR_XML_TEMP_CMP_H_FILES MMI_CACHE_DEFAULT_VALUE_H_FILE
#define MMI_CACHE_TABLE_C_PATH MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES  MMI_CACHE_TABLE_C_FILE
#define MMI_CACHE_TABLE_H_PATH MMI_RP_MGR_XML_TEMP_CMP_H_FILES  MMI_CACHE_TABLE_H_FILE
#define MMI_CAHCE_NVRAM_EDITOR_PATH MMI_RP_MGR_XML_TEMP_CMP_H_FILES MMI_CACHE_NVRAM_EDIOTR_H_FILE
#define MMI_CACHE_CAT_XML_PATH CAT_XML_OUTPUT_FOLDER MMI_CACHE_CAT_XML_FILE

extern const mmi_resource_base_struct g_mmi_resource_base_table[];

static mmi_rp_mmi_cache_cntx_struct g_mmi_rp_mmi_cache_cntx;

#define MMI_RP_MMI_CACHE_CURR_APP_CNTX g_mmi_rp_mmi_cache_cntx.curr_app_cntx
#define MMI_RP_MMI_CACHE_CURR_DATA (MMI_RP_MMI_CACHE_CURR_APP_CNTX)->cache_data_tail
#define MMI_RP_MMI_CACHE_CURR_FIELD (MMI_RP_MMI_CACHE_CURR_DATA)->field_list_tail
#define MMI_RP_MMI_CACHE_CURR_OPTION (MMI_RP_MMI_CACHE_CURR_FIELD)->option_list_tail

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
const kal_char * mmi_rp_mmi_cache_get_type_str(mmi_rp_mmi_cache_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(type)
    {
        case MMI_RP_MMI_CACHE_TYPE_BYTE:
            return "BYTE";
        case MMI_RP_MMI_CACHE_TYPE_SHORT:
            return "SHORT";
        case MMI_RP_MMI_CACHE_TYPE_DOUBLE:
            return "DOUBLE";
        default:
            return NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
const kal_char * mmi_rp_mmi_cache_get_type_lower_str(mmi_rp_mmi_cache_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(type)
    {
        case MMI_RP_MMI_CACHE_TYPE_BYTE:
            return "byte";
        case MMI_RP_MMI_CACHE_TYPE_SHORT:
            return "short";
        case MMI_RP_MMI_CACHE_TYPE_DOUBLE:
            return "double";
        default:
            return NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_int32 mmi_rp_mmi_cache_get_value_len(mmi_rp_mmi_cache_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(type)
    {
        case MMI_RP_MMI_CACHE_TYPE_BYTE:
            return 1;
        case MMI_RP_MMI_CACHE_TYPE_SHORT:
            return 2;
        case MMI_RP_MMI_CACHE_TYPE_DOUBLE:
            return 8;
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_unique_key
 * DESCRIPTION
 * PARAMETERS
 *  s       [?]
 * RETURNS
 *
 *****************************************************************************/
kal_uint32 mmi_rp_mmi_cache_unique_key(const kal_char *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 99991;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(*s != '\0')
    {
        i = 31 * i + *s;
        s++;
    }
    return i;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_parser_hex_array
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_rp_parser_hex_array(const kal_char *data, kal_int32 data_len, kal_uint8 *value_array, kal_int32 value_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data[0] == '[' && data[data_len-1] == ']')
    {
        kal_char *value_str = (kal_char *) data;
        kal_char *token;
        kal_uint32 i = 0, value = 0;

        value_str[data_len-1] = ',';
        token = strtok(value_str + 1, " ,\n\t");
        while(token)
        {
            MMI_RP_DEBUG_INFO("Token: %s\n", token);

            if (strchr(token, 'x') || strchr(token, 'X'))
            {
                if (sscanf(token , "%X",  &value)== 1)
                {
                    if (value <= 255)
                    {
                        value_array[i] = (kal_uint8)value;
                        i++;
                    }
                    else if (value <= 65535)
                    {
                        value_array[i] = (kal_uint8) (value & 0xFF);
                        value_array[i + 1] = (kal_uint8) (value >> 8);
                        i += 2;
                    }
                }
            }
            else if (sscanf(token , "%u",  &value) == 1)
            {
                if (value_len == 1)
                {
                    value_array[i] = (kal_uint8) (value & 0xFF);
                    i ++;
                }
                else if (value_len == 2)
                {
                    value_array[i] = (kal_uint8) (value & 0xFF);
                    value_array[i + 1] = (kal_uint8) ((value >> 8) & 0xFF);
                    i += 2;
                }
                else if (value_len == 3)
                {
                    value_array[i] = (kal_uint8) (value & 0xFF);
                    value_array[i + 1] = (kal_uint8) ((value >> 8) & 0xFF);
                    i += 3;
                }
                else
                {
                    value_array[i] = (kal_uint8) (value & 0xFF);
                    value_array[i + 1] = (kal_uint8) ((value >> 8) & 0xFF);
                    value_array[i + 2] = (kal_uint8) ((value >> 16) & 0xFF);
                    value_array[i + 3] = (kal_uint8) ((value >> 24) & 0xFF);
                    i += 4;
                }
            }
            else
            {
                //MMI_RP_ERROR_DATA(RP_ERR_VAL_UNKNOWN, token);
            }

            token = strtok(NULL, " ,\n\t");
        }
        value_str[data_len-1] = ']';

        if (i != value_len)
        {
            for(i=0; i<value_len; i++)
            {
                value_array[i] = 0xFF;

            }
            MMI_RP_ERROR_DATA(RP_ERR_VAL_UNKNOWN, data);
        }
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_init
 * DESCRIPTION
 *  Initializes the template context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mmi_cache_init(void)
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

    memset(&g_mmi_rp_mmi_cache_cntx, 0, sizeof(g_mmi_rp_mmi_cache_cntx));

    /* allocate one more cntx for replace item */
    g_mmi_rp_mmi_cache_cntx.app_cache_data = (mmi_rp_mmi_cache_app_struct*) malloc(sizeof(mmi_rp_mmi_cache_app_struct) * (g_mmi_rp_mgr_cntx.total_apps + 1));
    if(!g_mmi_rp_mmi_cache_cntx.app_cache_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }

    memset(g_mmi_rp_mmi_cache_cntx.app_cache_data, 0, sizeof(mmi_rp_mmi_cache_app_struct) * (g_mmi_rp_mgr_cntx.total_apps + 1));

    g_mmi_rp_mmi_cache_cntx.str_id_hash = mmi_rp_hash_create(0xFFFF); /* 0xFFFF is the resource ID range */

    g_mmi_rp_mmi_cache_cntx.replace_str_id_hash = mmi_rp_hash_create(0xFFFF); /* 0xFFFF is the resource ID range */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_set_app_range
 * DESCRIPTION
 *  Initializes the template context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mmi_cache_set_app_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_mmi_cache_app_struct *app_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    app_cntx = &(g_mmi_rp_mmi_cache_cntx.app_cache_data[g_mmi_rp_mgr_cntx.cur_app_index]);

    if(app_cntx->total_count == 0 && app_cntx->cache_data_head == NULL)
    {
        app_cntx->max_enum_id = g_mmi_rp_mgr_cntx.cur_app->min;
        app_cntx->app = g_mmi_rp_mgr_cntx.cur_app;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_start_handler
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
int mmi_rp_mmi_cache_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index = 0;
//    mmi_rp_scope_enum curr_scope = MMI_RP_SCOPE_NONE;
    kal_int32 parent_tag_id = -1;
    mmi_rp_mmi_cache_app_struct *app_cntx;
    mmi_rp_mmi_cache_data_struct *new_cache_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache -start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    new_cache_data = (mmi_rp_mmi_cache_data_struct*) malloc(sizeof(mmi_rp_mmi_cache_data_struct));
    memset(new_cache_data, 0, sizeof(mmi_rp_mmi_cache_data_struct));
    memset(new_cache_data->default_value, 0xFF, sizeof(new_cache_data->default_value));

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if (stricmp(attr[index], MMI_RP_MMI_CACHE_ATTR_ID) == 0)
        {
            new_cache_data->id_str = (kal_char *)attr[index + 1];
        }
        else if (stricmp(attr[index], MMI_RP_MMI_CACHE_ATTR_TYPE) == 0)
        {
            if (stricmp(attr[index + 1], MMI_RP_MMI_CACHE_VAL_BYTE) == 0)
            {
                new_cache_data->type = MMI_RP_MMI_CACHE_TYPE_BYTE;
            }
            else if (stricmp(attr[index + 1], MMI_RP_MMI_CACHE_VAL_SHORT) == 0)
            {
                new_cache_data->type = MMI_RP_MMI_CACHE_TYPE_SHORT;
            }
            else if (stricmp(attr[index + 1], MMI_RP_MMI_CACHE_VAL_DOUBLE) == 0)
            {
                new_cache_data->type = MMI_RP_MMI_CACHE_TYPE_DOUBLE;
            }
            else
            {
                MMI_RP_PARSE_WARNING(RP_WARN_INVALID_CONT);
                new_cache_data->type = MMI_RP_MMI_CACHE_TYPE_BYTE;
            }
        }
        else if (stricmp(attr[index], MMI_RP_MMI_CACHE_ATTR_RESTORE_FLAG) == 0)
        {
            if (stricmp(attr[index + 1], MMI_RP_MMI_CACHE_VAL_TRUE) == 0)
            {
                new_cache_data->restore_flag = KAL_TRUE;
            }
            else if (stricmp(attr[index + 1], MMI_RP_MMI_CACHE_VAL_FALSE) == 0)
            {
                new_cache_data->restore_flag = KAL_FALSE;
            }
            else
            {
                MMI_RP_PARSE_WARNING(RP_WARN_INVALID_CONT);
                new_cache_data->restore_flag = KAL_FALSE;
            }
        }
        else if (stricmp(attr[index], MMI_RP_MMI_CACHE_ATTR_RESTORE_ID) == 0)
        {
            if (attr[index + 1][0]!= '@')
            {
                MMI_RP_ERROR_DATA(RP_ERR_VAL_UNKNOWN, attr[index + 1]);
                free(new_cache_data);
                return MMI_RP_PARSE_ERROR_SKIP_TAG;
            }
            new_cache_data->restore_id_str = (kal_char *)malloc(strlen(attr[index + 1]));
            strcpy(new_cache_data->restore_id_str, attr[index + 1] + 1);
        }
        else if (stricmp(attr[index], MMI_RP_MMI_CACHE_ATTR_REPLACE_LEVEL) == 0)
        {
            if (stricmp(attr[index + 1], MMI_RP_MMI_CACHE_VAL_CUSTOM) == 0)
            {
                new_cache_data->replace_level = MMI_RP_MMI_CACHE_REPLACE_LEVEL_CUSTOM;
            }
        }
        else
        {
            MMI_RP_PARSE_WARNING_DATA(RP_WARN_UNKNOW_ATTR, attr[index]);
        }

        index += 2;
    }

    if (new_cache_data->replace_level == MMI_RP_MMI_CACHE_REPLACE_LEVEL_NORMAL)
    {
        MMI_RP_MMI_CACHE_CURR_APP_CNTX = &(g_mmi_rp_mmi_cache_cntx.app_cache_data[g_mmi_rp_mgr_cntx.cur_app_index]);

        app_cntx = MMI_RP_MMI_CACHE_CURR_APP_CNTX;

        /* String ID exceeded the app_range */
        if(app_cntx->total_count >= (kal_uint32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min))
        {
            MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
            if (new_cache_data->restore_id_str)
                free(new_cache_data->restore_id_str);
            free(new_cache_data);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
    }
    else
    {
        MMI_RP_MMI_CACHE_CURR_APP_CNTX = &(g_mmi_rp_mmi_cache_cntx.app_cache_data[g_mmi_rp_mgr_cntx.total_apps]);
    }

    app_cntx = MMI_RP_MMI_CACHE_CURR_APP_CNTX;

    if (new_cache_data->replace_level == MMI_RP_MMI_CACHE_REPLACE_LEVEL_NORMAL)
    {
        if (!mmi_rp_hash_find(g_mmi_rp_mmi_cache_cntx.str_id_hash, (U8*)new_cache_data->id_str))
        {
            /* add into hash table and create another buffer to save it */
            new_cache_data->id_str = mmi_rp_hash_add(g_mmi_rp_mmi_cache_cntx.str_id_hash, (U8*)new_cache_data->id_str);

            app_cntx->total_count++;

            if (!app_cntx->cache_data_head)
            {
                app_cntx->cache_data_head = app_cntx->cache_data_tail  = new_cache_data;
            }
            else
            {
                app_cntx->cache_data_tail->next = new_cache_data;
                app_cntx->cache_data_tail = new_cache_data;
            }

            new_cache_data->unique_key = mmi_rp_mmi_cache_unique_key(new_cache_data->id_str);
            new_cache_data->id = app_cntx->max_enum_id + 1;
            app_cntx->max_enum_id++;
        }
        else
        {
            MMI_RP_ERROR_DATA(RP_ERR_DUPLICATE_UNIQUE_KEY, new_cache_data->id_str);

            if (new_cache_data->restore_id_str)
                free(new_cache_data->restore_id_str);
            free(new_cache_data);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
    }
    else
    {
        /* add into hash table and create another buffer to save it */
        new_cache_data->id_str = mmi_rp_hash_add(g_mmi_rp_mmi_cache_cntx.replace_str_id_hash, (U8*)new_cache_data->id_str);

        app_cntx->total_count++;

        if (!app_cntx->cache_data_head)
        {
            app_cntx->cache_data_head = app_cntx->cache_data_tail  = new_cache_data;
        }
        else
        {
            app_cntx->cache_data_tail->next = new_cache_data;
            app_cntx->cache_data_tail = new_cache_data;
        }
    }

    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mmi_cache_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache -end: %s\n", el);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the data of the element, application could
    * add the process code here, and could put the data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, el);
    * 2) ...
    */
    return MMI_RP_PARSE_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_default_value_start_handler
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
int mmi_rp_mmi_cache_default_value_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32   index = 0;
    kal_int32 parent_tag_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - Default Value - start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MMI_CACHE_TAG_CACHEDATA) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /*
    * TODO: Add any code here...
    * If it wants to deal with the data of the element, application could
    * add the process code here, and could put the data string to buffer, or
    * to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, el);
    * 2) ...
    */

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        /*
        * TODO: Add any code here...
        * If it wants to deal with the data of the element and attribute list,
        * application could add the process code here, and could put the data to
        * buffer, to file, or to other structure, it depends on the special usages.
        * [Example]:
        * 1) strcpy(app_buf, attr[index]);
        * 2) strcpy(app_buf, attr[index + 1]);
        * 3) ...
        */

        index += 2;
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_default_value_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mmi_cache_default_value_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - Default Value - end: %s\n", el);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the data of the element, application could
    * add the process code here, and could put the data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, el);
    * 2) ...
    */
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_default_value_data_handler
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
int mmi_rp_mmi_cache_default_value_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_mmi_cache_app_struct *app_cntx = MMI_RP_MMI_CACHE_CURR_APP_CNTX;
    mmi_rp_mmi_cache_data_struct *cache_data = MMI_RP_MMI_CACHE_CURR_DATA;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - Default Value - data: %s\n", data);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the real data of the xml, application could
    * add the process code here, and could put the real data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, data);
    * 2) ...
    */

    mmi_rp_parser_hex_array(data, len, cache_data->default_value, mmi_rp_mmi_cache_get_value_len(cache_data->type));

    return MMI_RP_PARSE_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_description_start_handler
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
int mmi_rp_mmi_cache_description_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32   index = 0;
    kal_int32 parent_tag_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - Description -start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MMI_CACHE_TAG_CACHEDATA) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /*
    * TODO: Add any code here...
    * If it wants to deal with the data of the element, application could
    * add the process code here, and could put the data string to buffer, or
    * to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, el);
    * 2) ...
    */

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        /*
        * TODO: Add any code here...
        * If it wants to deal with the data of the element and attribute list,
        * application could add the process code here, and could put the data to
        * buffer, to file, or to other structure, it depends on the special usages.
        * [Example]:
        * 1) strcpy(app_buf, attr[index]);
        * 2) strcpy(app_buf, attr[index + 1]);
        * 3) ...
        */

        index += 2;
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_description_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mmi_cache_description_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - Description -end: %s\n", el);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the data of the element, application could
    * add the process code here, and could put the data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, el);
    * 2) ...
    */
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_description_data_handler
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
int mmi_rp_mmi_cache_description_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_mmi_cache_app_struct *app_cntx = MMI_RP_MMI_CACHE_CURR_APP_CNTX;
    mmi_rp_mmi_cache_data_struct *cache_data = MMI_RP_MMI_CACHE_CURR_DATA;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - Description -data: %s\n", data);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the real data of the xml, application could
    * add the process code here, and could put the real data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, data);
    * 2) ...
    */
    cache_data->description = (kal_char *) malloc(strlen(data) + 1);
    strcpy(cache_data->description, data);

    return MMI_RP_PARSE_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_field_start_handler
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
int mmi_rp_mmi_cache_field_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32   index = 0;
    kal_int32 parent_tag_id = -1;
    mmi_rp_mmi_cache_app_struct *app_cntx;
    mmi_rp_mmi_cache_data_struct *cache_data;
    mmi_rp_mmi_cache_field_struct *new_field;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - FIELD -start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MMI_CACHE_TAG_CACHEDATA) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    app_cntx = MMI_RP_MMI_CACHE_CURR_APP_CNTX;
    cache_data = MMI_RP_MMI_CACHE_CURR_DATA;
    new_field = (mmi_rp_mmi_cache_field_struct*) malloc(sizeof(mmi_rp_mmi_cache_field_struct));
    memset(new_field, 0, sizeof(mmi_rp_mmi_cache_field_struct));
    new_field->size = mmi_rp_mmi_cache_get_value_len(cache_data->type);
    new_field->min = MMI_RP_MMI_CACHE_MIN_DEFAULT;
    new_field->max = MMI_RP_MMI_CACHE_MAX_DEFAULT;

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if (stricmp(attr[index], MMI_RP_MMI_CACHE_ATTR_NAME) == 0)
        {
            new_field->name = (kal_char*) malloc(strlen(attr[index + 1])+ 1);
            strcpy(new_field->name, attr[index + 1]);
        }
        else if (stricmp(attr[index], MMI_RP_MMI_CACHE_ATTR_SIZE) == 0)
        {
            if (sscanf(attr[index + 1] , "%d",  &new_field->size) == 1)
            {
                ;
            }
            else
            {
                MMI_RP_PARSE_WARNING_DATA(RP_WARN_UNKNOWN_VAL, attr[index + 1]);
            }
        }
        else if (stricmp(attr[index], MMI_RP_MMI_CACHE_ATTR_MAX) == 0)
        {
            if (sscanf(attr[index + 1] , "%d",  &new_field->max) == 1)
            {
                ;
            }
            else
            {
                MMI_RP_PARSE_WARNING_DATA(RP_WARN_UNKNOWN_VAL, attr[index + 1]);
            }
        }
        else if (stricmp(attr[index], MMI_RP_MMI_CACHE_ATTR_MIN) == 0)
        {
            if (sscanf(attr[index + 1] , "%d",  &new_field->min) == 1)
            {
                ;
            }
            else
            {
                MMI_RP_PARSE_WARNING_DATA(RP_WARN_UNKNOWN_VAL, attr[index + 1]);
            }
        }
        else
        {
            MMI_RP_PARSE_WARNING(RP_WARN_UNKNOW_ATTR);
        }

        index += 2;
    }

    /* define too many field */
    if (cache_data->total_field_size + new_field->size > mmi_rp_mmi_cache_get_value_len(cache_data->type))
    {
        MMI_RP_ERROR(RP_ERR_MMI_CACHE_TOO_MANY_FIELD);
        if (new_field->name)
            free(new_field->name);
        free(new_field);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    cache_data->total_field_size += new_field->size;

    if (cache_data->field_list_head == NULL)
    {
        cache_data->field_list_head = cache_data->field_list_tail = new_field;
    }
    else
    {
        cache_data->field_list_tail->next = new_field;
        cache_data->field_list_tail = new_field;
    }

    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_field_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mmi_cache_field_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - FIELD -end: %s\n", el);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the data of the element, application could
    * add the process code here, and could put the data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, el);
    * 2) ...
    */
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_field_data_handler
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
int mmi_rp_mmi_cache_field_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - FIELD - data: %s\n", data);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the real data of the xml, application could
    * add the process code here, and could put the real data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, data);
    * 2) ...
    */
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_option_start_handler
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
int mmi_rp_mmi_cache_option_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32   index = 0;
    kal_int32 parent_tag_id = -1;
    mmi_rp_mmi_cache_app_struct *app_cntx;
    mmi_rp_mmi_cache_data_struct *cache_data;
    mmi_rp_mmi_cache_field_struct *field;
    mmi_rp_mmi_cache_option_struct *new_option;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - OPTION -start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MMI_CACHE_TAG_FIELD) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    app_cntx = MMI_RP_MMI_CACHE_CURR_APP_CNTX;
    cache_data = MMI_RP_MMI_CACHE_CURR_DATA;
    field = MMI_RP_MMI_CACHE_CURR_FIELD;
    new_option = (mmi_rp_mmi_cache_option_struct*) malloc(sizeof(mmi_rp_mmi_cache_option_struct));
    memset(new_option, 0, sizeof(mmi_rp_mmi_cache_option_struct));

    if (field->option_list_tail)
    {
        kal_int32 i;

        memcpy(new_option->value, field->option_list_tail->value, field->size);

        new_option->value[0]++;

        for (i = 0 ; i < field->size; i++)
        {
            if (new_option->value[i] == 0)
            {
                new_option->value[i + 1]++;
            }
            else
            {
                break;
            }
        }
    }

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if (stricmp(attr[index], MMI_RP_MMI_CACHE_ATTR_HINT) == 0)
        {
            new_option->hint = (kal_char*) malloc(strlen(attr[index + 1])+ 1);
            strcpy(new_option->hint, attr[index + 1]);
        }
        else
        {
            MMI_RP_PARSE_WARNING(RP_WARN_UNKNOW_ATTR);
        }

        index += 2;
    }

    if (field->option_list_head == NULL)
    {
        field->option_list_head = field->option_list_tail = new_option;
    }
    else
    {
        field->option_list_tail->next = new_option;
        field->option_list_tail = new_option;
    }

    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_option_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mmi_cache_option_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - OPTION -end: %s\n", el);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the data of the element, application could
    * add the process code here, and could put the data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, el);
    * 2) ...
    */
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_option_data_handler
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
int mmi_rp_mmi_cache_option_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_mmi_cache_app_struct *app_cntx = MMI_RP_MMI_CACHE_CURR_APP_CNTX;
    mmi_rp_mmi_cache_data_struct *cache_data = MMI_RP_MMI_CACHE_CURR_DATA;
    mmi_rp_mmi_cache_field_struct *field = MMI_RP_MMI_CACHE_CURR_FIELD;
    mmi_rp_mmi_cache_option_struct *option = MMI_RP_MMI_CACHE_CURR_OPTION;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - OPTION -data: %s\n", data);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the real data of the xml, application could
    * add the process code here, and could put the real data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, data);
    * 2) ...
    */
    mmi_rp_parser_hex_array(data, len, option->value, field->size);
    return MMI_RP_PARSE_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_minimum_start_handler
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
int mmi_rp_mmi_cache_minimum_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 parent_tag_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - MINIMUM -start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MMI_CACHE_TAG_FIELD) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_minimum_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mmi_cache_minimum_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - MINIMUM -end: %s\n", el);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the data of the element, application could
    * add the process code here, and could put the data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, el);
    * 2) ...
    */

    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_minimum_data_handler
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
int mmi_rp_mmi_cache_minimum_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_mmi_cache_app_struct *app_cntx = MMI_RP_MMI_CACHE_CURR_APP_CNTX;
    mmi_rp_mmi_cache_data_struct *cache_data = MMI_RP_MMI_CACHE_CURR_DATA;
    mmi_rp_mmi_cache_field_struct *field = MMI_RP_MMI_CACHE_CURR_FIELD;
    mmi_rp_mmi_cache_option_struct *option = MMI_RP_MMI_CACHE_CURR_OPTION;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - OPTION -data: %s\n", data);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the real data of the xml, application could
    * add the process code here, and could put the real data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, data);
    * 2) ...
    */
    memset(field->min_array, 0, sizeof(field->min_array));
    mmi_rp_parser_hex_array(data, len, field->min_array, field->size);

    field->min = field->min_array[0] |
                 field->min_array[1] << 8  |
                 field->min_array[2] << 16 |
                 field->min_array[3] << 24;
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_maximum_start_handler
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
int mmi_rp_mmi_cache_maximum_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 parent_tag_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - MAXIMUM -start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MMI_CACHE_TAG_FIELD) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_maximum_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mmi_cache_maximum_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - MAXIMUM -end: %s\n", el);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the data of the element, application could
    * add the process code here, and could put the data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, el);
    * 2) ...
    */
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_maximum_option_data_handler
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
int mmi_rp_mmi_cache_maximum_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_mmi_cache_app_struct *app_cntx = MMI_RP_MMI_CACHE_CURR_APP_CNTX;
    mmi_rp_mmi_cache_data_struct *cache_data = MMI_RP_MMI_CACHE_CURR_DATA;
    mmi_rp_mmi_cache_field_struct *field = MMI_RP_MMI_CACHE_CURR_FIELD;
    mmi_rp_mmi_cache_option_struct *option = MMI_RP_MMI_CACHE_CURR_OPTION;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - MAXIMUM -data: %s\n", data);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the real data of the xml, application could
    * add the process code here, and could put the real data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, data);
    * 2) ...
    */
    memset(field->max_array, 0, sizeof(field->max_array));
    mmi_rp_parser_hex_array(data, len, field->max_array, field->size);
    field->max = field->max_array[0] |
                 field->max_array[1] << 8  |
                 field->max_array[2] << 16 |
                 field->max_array[3] << 24;
    return MMI_RP_PARSE_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_lessthan_start_handler
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
int mmi_rp_mmi_cache_lessthan_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 parent_tag_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - LESSTHAN -start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MMI_CACHE_TAG_FIELD) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_lessthan_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mmi_cache_lessthan_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - LESSTHAN -end: %s\n", el);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the data of the element, application could
    * add the process code here, and could put the data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, el);
    * 2) ...
    */
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_lessthan_data_handler
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
int mmi_rp_mmi_cache_lessthan_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_mmi_cache_app_struct *app_cntx = MMI_RP_MMI_CACHE_CURR_APP_CNTX;
    mmi_rp_mmi_cache_data_struct *cache_data = MMI_RP_MMI_CACHE_CURR_DATA;
    mmi_rp_mmi_cache_field_struct *field = MMI_RP_MMI_CACHE_CURR_FIELD;
    mmi_rp_mmi_cache_option_struct *option = MMI_RP_MMI_CACHE_CURR_OPTION;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - LESSTHAN -data: %s\n", data);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the real data of the xml, application could
    * add the process code here, and could put the real data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, data);
    * 2) ...
    */
    memset(field->max_array, 0, sizeof(field->max_array));
    mmi_rp_parser_hex_array(data, len, field->max_array, field->size);
    field->max = field->max_array[0] |
                 field->max_array[1] << 8  |
                 field->max_array[2] << 16 |
                 field->max_array[3] << 24;
    field->max--;
    return MMI_RP_PARSE_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_morethan_start_handler
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
int mmi_rp_mmi_cache_morethan_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 parent_tag_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - MORETHAN -start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MMI_CACHE_TAG_FIELD) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_morethan_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mmi_cache_morethan_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - MORETHAN -end: %s\n", el);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the data of the element, application could
    * add the process code here, and could put the data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, el);
    * 2) ...
    */
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_morethan_option_data_handler
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
int mmi_rp_mmi_cache_morethan_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_mmi_cache_app_struct *app_cntx = MMI_RP_MMI_CACHE_CURR_APP_CNTX;
    mmi_rp_mmi_cache_data_struct *cache_data = MMI_RP_MMI_CACHE_CURR_DATA;
    mmi_rp_mmi_cache_field_struct *field = MMI_RP_MMI_CACHE_CURR_FIELD;
    mmi_rp_mmi_cache_option_struct *option = MMI_RP_MMI_CACHE_CURR_OPTION;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("MMI Cache - MORETHAN -data: %s\n", data);

    /*
    * TODO: Add any code here...
    * If it wants to deal with the real data of the xml, application could
    * add the process code here, and could put the real data string to buffer,
    * or to file, it depends on the special usages.
    * [Example]:
    * 1) strcpy(app_buf, data);
    * 2) ...
    */
    memset(field->min_array, 0, sizeof(field->min_array));
    mmi_rp_parser_hex_array(data, len, field->min_array, field->size);
    field->min = field->min_array[0] |
                 field->min_array[1] << 8  |
                 field->min_array[2] << 16 |
                 field->min_array[3] << 24;
    field->min++;
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_filter
 * DESCRIPTION
 *  This function is for resgen to filter your resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mmi_cache_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i, j ,k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(g_mmi_rp_mmi_cache_cntx.cache_number, 0, sizeof(g_mmi_rp_mmi_cache_cntx.cache_number));
    memset(g_mmi_rp_mmi_cache_cntx.sort_table, 0, sizeof(g_mmi_rp_mmi_cache_cntx.sort_table));

    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        if (g_mmi_rp_mmi_cache_cntx.app_cache_data[i].total_count != 0)
        {
            kal_int32 checkpoint = 0;
            mmi_rp_mmi_cache_data_struct* data = g_mmi_rp_mmi_cache_cntx.app_cache_data[i].cache_data_head;

            while(data != NULL)
            {
                kal_int32 index = g_mmi_rp_mmi_cache_cntx.cache_number[data->type]++;
                g_mmi_rp_mmi_cache_cntx.sort_table[data->type][index] = data;
                data = data->next;
                checkpoint++;
            }

            if (checkpoint != g_mmi_rp_mmi_cache_cntx.app_cache_data[i].total_count)
            {
                MMI_RP_ERROR(RP_ERR_ID_NOT_FOUND);
            }
        }
    }

    /* sort the data */
    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        if (g_mmi_rp_mmi_cache_cntx.cache_number[i] > (MMI_CACHE_SIZE / mmi_rp_mmi_cache_get_value_len(i)))
        {
            MMI_RP_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }
    }

    /* sort the data */
    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        for (j = g_mmi_rp_mmi_cache_cntx.cache_number[i] - 1; j >= 0 ; j--)
        {
            for (k = j-1 ; k >= 0 ; k--)
            {
                if (g_mmi_rp_mmi_cache_cntx.sort_table[i][k]->unique_key >
                    g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->unique_key)
                {
                    mmi_rp_mmi_cache_data_struct *tmp;
                    tmp = g_mmi_rp_mmi_cache_cntx.sort_table[i][k];
                    g_mmi_rp_mmi_cache_cntx.sort_table[i][k] = g_mmi_rp_mmi_cache_cntx.sort_table[i][j];
                    g_mmi_rp_mmi_cache_cntx.sort_table[i][j] = tmp;
                }
                /* check if there is any unique key duplicated */
                else if (g_mmi_rp_mmi_cache_cntx.sort_table[i][k]->unique_key ==
                         g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->unique_key)
                {
                    MMI_RP_PARSE_WARNING_DATA(RP_WARN_DUPLICATE_UNIQUE_KEY, g_mmi_rp_mmi_cache_cntx.sort_table[i][k]->id_str);
                    MMI_RP_PARSE_WARNING_DATA(RP_WARN_DUPLICATE_UNIQUE_KEY, g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->id_str);
                    MMI_RP_ERROR(RP_ERR_DUPLICATE_UNIQUE_KEY);
                }
            }
        }
    }

    /* fill in sorted id */
    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        for (j = 0; j < g_mmi_rp_mmi_cache_cntx.cache_number[i]; j++)
        {
            g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->sorted_id = j;
        }
    }

    /* fill in restore id */
    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        for (j = 0; j < g_mmi_rp_mmi_cache_cntx.cache_number[i]; j++)
        {
            if (g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->restore_flag &&
                g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->restore_id_str)
            {
                kal_char *id_str;

                if (!(id_str = mmi_rp_hash_find(g_mmi_rp_mmi_cache_cntx.str_id_hash, (U8*)(g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->restore_id_str))))
                {
                    MMI_RP_ERROR_DATA(RP_ERR_ID_NOT_FOUND, g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->restore_id_str);
                }

                for (k = 0 ; k < g_mmi_rp_mmi_cache_cntx.cache_number[i] ; k++)
                {
                    if (g_mmi_rp_mmi_cache_cntx.sort_table[i][k]->id_str == id_str)
                    {
                        g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->restore_data = g_mmi_rp_mmi_cache_cntx.sort_table[i][k];
                        break;
                    }
                }

                if (k == g_mmi_rp_mmi_cache_cntx.cache_number[i])
                {
                    MMI_RP_ERROR(RP_ERR_ID_NOT_FOUND);
                }
            }
        }
    }

    /* fill in replace dafualt value */
    if (g_mmi_rp_mmi_cache_cntx.app_cache_data[g_mmi_rp_mgr_cntx.total_apps].total_count != 0)
    {
        mmi_rp_mmi_cache_data_struct* data = g_mmi_rp_mmi_cache_cntx.app_cache_data[g_mmi_rp_mgr_cntx.total_apps].cache_data_head;

        while(data != NULL)
        {

            kal_char *id_str;

            if (!(id_str = mmi_rp_hash_find(g_mmi_rp_mmi_cache_cntx.str_id_hash, (U8*)data->id_str)))
            {
                MMI_RP_PARSE_WARNING_DATA(RP_ERR_ID_NOT_FOUND, (U8*)data->id_str);
            }

            for (i = 0 ; i < g_mmi_rp_mmi_cache_cntx.cache_number[data->type] ; i++)
            {
                if (g_mmi_rp_mmi_cache_cntx.sort_table[data->type][i]->id_str == id_str)
                {
                    if (data->replace_level > g_mmi_rp_mmi_cache_cntx.sort_table[data->type][i]->replace_level)
                    {
                        memcpy(g_mmi_rp_mmi_cache_cntx.sort_table[data->type][i]->default_value,
                               data->default_value, sizeof(data->default_value));
                        g_mmi_rp_mmi_cache_cntx.sort_table[data->type][i]->replace_level = data->replace_level;
                    }
                    break;
                }
            }

            if (i == g_mmi_rp_mmi_cache_cntx.cache_number[data->type])
            {
                MMI_RP_PARSE_WARNING_DATA(RP_ERR_ID_NOT_FOUND, (U8*)data->id_str);
            }
            data = data->next;
        }

    }

}

#define MMI_CACHE_AUTO_GEN_DESCRIPTION  \
"/********************************************************\n" \
" *  This file is generated automatically by resource gen\n" \
" *  Please do not modify it here manually \n" \
" ***********************************************************/\n"

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_output_phase1_app_def_h_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mmi_cache_output_phase1_app_def_h_file(kal_uint32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char str_enum_name[MMI_RP_OUTPUT_ENUM_NAME_MAX], str_enum_max[MMI_RP_OUTPUT_ENUM_NAME_MAX];
    mmi_rp_mmi_cache_app_struct *app_cntx = &(g_mmi_rp_mmi_cache_cntx.app_cache_data[app_index]);
    mmi_rp_mmi_cache_data_struct *data;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        if (app_cntx->total_count == 0)
        {
            return;
        }

        memset(str_enum_name, 0, sizeof(str_enum_name));
        strcpy(str_enum_name, "mmi_rp_");
        strcat(str_enum_name, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_name, "_mmi_cache_enum");
        for(i = 0; i < strlen(str_enum_name); i++)
        {
            str_enum_name[i] = tolower(str_enum_name[i]);
        }

        memset(str_enum_max, 0, sizeof(str_enum_max));
        strcpy(str_enum_max, "MMI_RP_");
        strcat(str_enum_max, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_max, "_MMI_CACHE_MAX");
        for(i = 0; i < strlen(str_enum_max); i++)
        {
            str_enum_max[i] = toupper(str_enum_max[i]);
        }



        fprintf(p_file, "\n\n");
        fprintf(p_file, "/******************** MMI Cache IDs - Begin ********************/\n");
        fprintf(p_file, "typedef enum\n{\n");

        for(data = app_cntx->cache_data_head,  i = 0; i < app_cntx->total_count; i++, data = data->next)
        {
            if(i == 0)
            {
                if (data->id != g_mmi_resource_base_table[app_index].min + 1)
                {
                    MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
                }

                fprintf(p_file, "    %s = %d + 1, /* BASE_ID + 1 */ %*c /* %12s */ \n",
                    data->id_str,
                    g_mmi_resource_base_table[app_index].min,
                    27-strlen(data->id_str), ' ',
                    mmi_rp_mmi_cache_get_type_str(data->type));
                MMI_RP_OUTPUT_ENUM_LOG(data->id_str, data->id);
            }
            else
            {
                if (data->id != g_mmi_resource_base_table[app_index].min + 1 + i)
                {
                    MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
                }

                fprintf(p_file, "    %s, %*c /* %12s */ \n",
                    data->id_str,
                    57-strlen(data->id_str), ' ',
                    mmi_rp_mmi_cache_get_type_str(data->type));
                MMI_RP_OUTPUT_ENUM_LOG(data->id_str, data->id);
            }
        }

        fprintf(p_file, "    %s\n", str_enum_max);
        fprintf(p_file, "} %s;\n", str_enum_name);
        fprintf(p_file, "/******************** MMI Cache IDs - End ********************/\n");
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_output_phase1
 * DESCRIPTION
 *  Output IDs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mmi_cache_output_phase1(void)
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

        if (g_mmi_rp_mmi_cache_cntx.app_cache_data[i].total_count == 0)
        {
            continue;
        }

        str_output_filename = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_H_FILE_PATH, g_mmi_resource_base_table[i].appname);

        /* Menu resource module has already written the header and header guard. */
        /* Open the file in append mode */
        if(p_file = fopen(str_output_filename, "a"))
        {
            mmi_rp_mmi_cache_output_phase1_app_def_h_file(i, p_file);
            fclose(p_file);
        }
        else
        {
            /* Error writing output file. Exit. */
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
        }
    }

    /* 2. If you have any other header files, you can output it here*/
    ///TODO: output header files.
}

#define MMI_CACHE_RESTORE_FUNCTION_HEAD \
"/*****************************************************************************\n" \
" * FUNCTION\n" \
" *  nvram_restore_%s_cache()\n" \
" * DESCRIPTION\n" \
" *  used to restore mmi_cache_%s to default value\n" \
" * PARAMETERS\n" \
" *  buffer    [IN]\n" \
" * RETURNS\n" \
" *  none\n" \
" *****************************************************************************/\n"

#define MMI_CACHE_RESTORE_FUNCTION_NAME \
"void nvram_restore_%s_cache(nvram_reset_category_enum category,nvram_app_id_enum app_id, kal_uint8 *buffer)\n" \
"{\n" \
"    /*----------------------------------------------------------------*/\n" \
"    /* Local Variables                                                */\n" \
"    /*----------------------------------------------------------------*/\n" \
"\n" \
"    /*----------------------------------------------------------------*/\n" \
"    /* Code Body                                                      */\n" \
"    /*----------------------------------------------------------------*/\n"

#define MMI_CACHE_RESTORE_FUNCTION_BREAK    \
"        if (category == NVRAM_RESET_CERTAIN)\n" \
"        {\n" \
"            break;\n" \
"        }\n"


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_output_phase2_restore_function
 * DESCRIPTION
 * PARAMETERS
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mmi_cache_output_phase2_restore_function(FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i,j,k;
    mmi_rp_mmi_cache_data_struct *tmp_data;
    kal_int32 value_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!p_file)
    {
        MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

    fprintf(p_file, MMI_CACHE_AUTO_GEN_DESCRIPTION);

    fprintf(p_file,"\n\n\n");
    fprintf(p_file,"#include \"mmi_res_range_def.h\"\n");
    fprintf(p_file,"#include \"nvram_enums.h\"\n");
    fprintf(p_file,"#include \"nvram_interface.h\"\n");

    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX; i++)
    {
        value_len = mmi_rp_mmi_cache_get_value_len(i);

        fprintf(p_file,"\n\n\n");
        fprintf(p_file, MMI_CACHE_RESTORE_FUNCTION_HEAD,
            mmi_rp_mmi_cache_get_type_lower_str(i), mmi_rp_mmi_cache_get_type_lower_str(i));
        fprintf(p_file, MMI_CACHE_RESTORE_FUNCTION_NAME, mmi_rp_mmi_cache_get_type_lower_str(i));
        fprintf(p_file, "    kal_uint8 *def_buf;\n");
        fprintf(p_file, "    nvram_get_default_value(NVRAM_EF_CACHE_%s_LID, 1, &def_buf);\n",
            mmi_rp_mmi_cache_get_type_str(i));
        fprintf(p_file, "    switch(app_id)\n");
        fprintf(p_file, "    {\n");
        fprintf(p_file, "    case 0:  /* for restore factory, reset all app item */\n");

        for (j = 0; j < g_mmi_rp_mgr_cntx.total_apps; j++)
        {
            if (g_mmi_rp_mmi_cache_cntx.app_cache_data[j].total_count > 0)
            {
                tmp_data = g_mmi_rp_mmi_cache_cntx.app_cache_data[j].cache_data_head;

                fprintf(p_file, "    case %s: \n", g_mmi_rp_mmi_cache_cntx.app_cache_data[j].app->appname);

                while(tmp_data != NULL)
                {
                    if (tmp_data->type == i && tmp_data->restore_flag == KAL_TRUE)
                    {
                        if (!tmp_data->restore_data)
                        {
                            for (k = 0; k < value_len ; k++)
                            {
                                fprintf(p_file,"        buffer[%3d] = def_buf[%3d];",
                                    tmp_data->sorted_id * value_len + k,
                                    tmp_data->sorted_id * value_len + k);

                                if (k == 0)
                                {
                                    fprintf(p_file, "     /* %5d: %s */\n", tmp_data->id, tmp_data->id_str);
                                }
                                else
                                {
                                    fprintf(p_file, "\n");
                                }
                            }
                        }
                        else
                        {
                            for (k = 0; k < value_len ; k++)
                            {
                                fprintf(p_file,"        buffer[%3d] = def_buf[%3d];",
                                    tmp_data->sorted_id * value_len + k,
                                    tmp_data->restore_data->sorted_id * value_len + k);

                                if (k == 0)
                                {
                                    fprintf(p_file, "     /* %5d: %s = %5d: %s*/\n",
                                        tmp_data->id, tmp_data->id_str,
                                        tmp_data->restore_data->id, tmp_data->restore_data->id_str);
                                }
                                else
                                {
                                    fprintf(p_file, "\n");
                                }
                            }

                        }
                    }
                    tmp_data = tmp_data->next;
                };
                fprintf(p_file, MMI_CACHE_RESTORE_FUNCTION_BREAK);
            }
        }

        fprintf(p_file, "    default:\n");
        fprintf(p_file, "        break;\n");
        fprintf(p_file, "    };\n");
        fprintf(p_file, "}\n");
    }
    fprintf(p_file,"\n\n");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_output_phase2_default_value_c_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mmi_cache_output_phase2_default_value_h_file(FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i,j,k, value_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!p_file)
    {
        MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

    fprintf(p_file, MMI_CACHE_AUTO_GEN_DESCRIPTION);
    fprintf(p_file,"/********************************************************\n");
    fprintf(p_file," *  The count of byte configuration:   %d \n", g_mmi_rp_mmi_cache_cntx.cache_number[0]);
    fprintf(p_file," *  The count of short configuration:  %d \n", g_mmi_rp_mmi_cache_cntx.cache_number[1]);
    fprintf(p_file," *  The count of double configuration: %d \n", g_mmi_rp_mmi_cache_cntx.cache_number[2]);
    fprintf(p_file," ***********************************************************/\n");

    fprintf(p_file,"#ifndef MMI_RP_MMI_CACHE_DEFAULT_VALUE_H\n");
    fprintf(p_file,"#define MMI_RP_MMI_CACHE_DEFAULT_VALUE_H\n");

    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        value_len = mmi_rp_mmi_cache_get_value_len(i);

        fprintf(p_file, "\n\nconst kal_uint8 NVRAM_EF_MMI_CACHE_%s_DEFAULT[NVRAM_CACHE_SIZE] =\n", mmi_rp_mmi_cache_get_type_str(i));
        fprintf(p_file, "{\n");

        for (j = 0; j < MMI_CACHE_SIZE / value_len; j++)
        {
            if (g_mmi_rp_mmi_cache_cntx.sort_table[i][j])
            {
                fprintf(p_file, "    ");
                for(k = 0; k < value_len; k++)
                {
                    fprintf(p_file, "0x%02X,", g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->default_value[k]);
                }
                fprintf(p_file, "%10c", ' ');
                fprintf(p_file, "/* %3d : %5d : %s */\n",
                    j,
                    g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->id,
                    g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->id_str);
            }
            else
            {
                fprintf(p_file, "    ");
                for(k = 0; k < value_len; k++)
                {
                    fprintf(p_file, "0xFF,");
                }
                fprintf(p_file, "\n");
            }
        }
        fprintf(p_file, "};\n\n");
    }

    fprintf(p_file,"#endif /* MMI_RP_MMI_CACHE_DEFAULT_VALUE_H */\n");
    fprintf(p_file,"\n\n");

}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_output_phase2_table
 * DESCRIPTION
 * PARAMETERS
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mmi_cache_output_phase2_table_c_file(FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i,j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!p_file)
    {
        MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

    fprintf(p_file, MMI_CACHE_AUTO_GEN_DESCRIPTION);
    fprintf(p_file,"#include \"common_nvram_editor_data_item.h\"\n");

    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        fprintf(p_file,"#define MMI_CACHE_%s_NUMBER %d\n",
            mmi_rp_mmi_cache_get_type_str(i),
            g_mmi_rp_mmi_cache_cntx.cache_number[i]);
    }

    fprintf(p_file,"\n\n");

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        fprintf(p_file,"kal_uint16 mmi_rp_mmi_cache_get_%s_number(void)\n",
            mmi_rp_mmi_cache_get_type_lower_str(i));
        fprintf(p_file,"{\n    return MMI_CACHE_%s_NUMBER;\n}\n",
            mmi_rp_mmi_cache_get_type_str(i));
    }

    fprintf(p_file,"\n\n");


    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        fprintf(p_file, "const kal_uint16 MMI_CACHE_%s_ENUM_TABLE[MMI_CACHE_%s_NUMBER] =\n",
            mmi_rp_mmi_cache_get_type_str(i),
            mmi_rp_mmi_cache_get_type_str(i));
        fprintf(p_file, "{\n");

        for (j = 0; j < g_mmi_rp_mmi_cache_cntx.cache_number[i] ; j++)
        {
            fprintf(p_file, "    %5d,   /* %d -- %s */\n",
                g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->id,
                j,
                g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->id_str);
        }
        fprintf(p_file, "};\n\n");
    }

    fprintf(p_file,"\n\n");

    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        fprintf(p_file, "const kal_uint32 NVRAM_EF_MMI_CACHE_%s_KEY_DEFAULT[NVRAM_MMI_CACHE_%s_KEY_SIZE * NVRAM_MMI_CACHE_%s_KEY_TOTAL / sizeof(kal_uint32)] =\n",
            mmi_rp_mmi_cache_get_type_str(i),
            mmi_rp_mmi_cache_get_type_str(i),
            mmi_rp_mmi_cache_get_type_str(i));
        fprintf(p_file, "{\n");

        for (j = 0; j < g_mmi_rp_mmi_cache_cntx.cache_number[i] ; j++)
        {
            fprintf(p_file, "    0x%08X,   /* %d -- %s */\n",
                g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->unique_key,
                j,
                g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->id_str);
        }
        fprintf(p_file, "};\n\n");
    }
    fprintf(p_file,"\n\n");

    fprintf(p_file, "#ifdef __MTK_INTERNAL__\n");
    fprintf(p_file, "/* type (1: byte cache,  2: short cache   8:double cache) */\n");
    fprintf(p_file, "/* This API is only used for meta tool */\n");
    fprintf(p_file, "kal_int16 mmi_rp_mmi_cache_search_index(kal_uint16 nDataItemId, kal_uint8 nDataType)\n");
    fprintf(p_file, "{\n");
    fprintf(p_file, "    kal_uint16 index, total= 0;\n");
    fprintf(p_file, "    const kal_uint16 *tbl;\n\n");
    fprintf(p_file, "    switch(nDataType)\n");
    fprintf(p_file, "    {\n");
    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        fprintf(p_file, "    case %d:\n", mmi_rp_mmi_cache_get_value_len(i));
        fprintf(p_file, "        tbl = MMI_CACHE_%s_ENUM_TABLE;\n", mmi_rp_mmi_cache_get_type_str(i));
        fprintf(p_file, "        total = MMI_CACHE_%s_NUMBER;\n", mmi_rp_mmi_cache_get_type_str(i));
        fprintf(p_file, "        break;\n");
    }
    fprintf(p_file, "    default:\n");
    fprintf(p_file, "        tbl = NULL;\n");
    fprintf(p_file, "        total = 0;\n");
    fprintf(p_file, "    }\n");
    fprintf(p_file, "    for( index = 0 ; index < total ; index++)\n");
    fprintf(p_file, "    {\n");
    fprintf(p_file, "        if (tbl[index] == nDataItemId)\n");
    fprintf(p_file, "            return index;\n");
    fprintf(p_file, "    }\n");
    fprintf(p_file, "    return -1;\n");
    fprintf(p_file, "}\n");
    fprintf(p_file, "#endif\n");

    fprintf(p_file,"\n\n");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_output_phase2_nvram_editor_h_file
 * DESCRIPTION
 * PARAMETERS
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mmi_cache_output_phase2_table_h_file(FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i,j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!p_file)
    {
        MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

    fprintf(p_file, "#ifndef MMI_RP_MMI_CACHE_TABLE_H\n");
    fprintf(p_file, "#define MMI_RP_MMI_CACHE_TABLE_H\n");

    fprintf(p_file, "\n\n");

    fprintf(p_file, "#include \"nvram_enums.h\"\n");
    fprintf(p_file, "#include \"custom_nvram_config.h\"\n");

    fprintf(p_file, "\n\n");

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        fprintf(p_file, "extern kal_uint16 mmi_rp_mmi_cache_get_%s_number(void);\n",
            mmi_rp_mmi_cache_get_type_lower_str(i));
    }

    fprintf(p_file, "\n\n");

    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        fprintf(p_file, "extern const kal_uint16 MMI_CACHE_%s_ENUM_TABLE[];\n", mmi_rp_mmi_cache_get_type_str(i));
    }

    fprintf(p_file, "\n\n");

    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        fprintf(p_file, "extern const kal_uint32 NVRAM_EF_MMI_CACHE_%s_KEY_DEFAULT[];\n", mmi_rp_mmi_cache_get_type_str(i));
    }

    fprintf(p_file, "\n\n");

    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        fprintf(p_file, "extern void nvram_restore_%s_cache(nvram_reset_category_enum category,nvram_app_id_enum app_id, kal_uint8 *buffer);\n",
            mmi_rp_mmi_cache_get_type_lower_str(i));
    }

    fprintf(p_file, "extern kal_int16 mmi_rp_mmi_cache_search_index(kal_uint16 nDataItemId, kal_uint8 nDataType);\n");

    fprintf(p_file, "\n\n#endif /* MMI_CACHE_TABLE_H */");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_output_phase2_nvram_editor_h_file
 * DESCRIPTION
 * PARAMETERS
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mmi_cache_output_phase2_nvram_editor_h_file(FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i,j,k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!p_file)
    {
        MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

    fprintf(p_file, MMI_CACHE_AUTO_GEN_DESCRIPTION);

    fprintf(p_file,"#ifndef MMI_RP_MMI_CACHE_NVRAM_EDITOR_H\n");
    fprintf(p_file,"#define MMI_RP_MMI_CACHE_NVRAM_EDITOR_H\n");

    for (i = 0 ; i < MMI_RP_MMI_CACHE_TYPE_MAX ; i++)
    {
        kal_int32 value_len = mmi_rp_mmi_cache_get_value_len(i);

        fprintf(p_file,"\n\n\n");
        fprintf(p_file,"/***********************************************************************\n");
        fprintf(p_file," ***  This is a nvram data item bit level description for meta tools nvram editor\n");
        fprintf(p_file," ***\n");
        fprintf(p_file," ***  Logical Data Item ID : NVRAM_EF_CACHE_%s_LID\n", mmi_rp_mmi_cache_get_type_str(i));
        fprintf(p_file," ***\n");
        fprintf(p_file," ***  Module:\n");
        fprintf(p_file," ***\n");
        fprintf(p_file," ***  Description:\n");
        fprintf(p_file," ***\n");
        fprintf(p_file," ***  Maintainer:\n");
        fprintf(p_file," ***\n");
        fprintf(p_file," ***********************************************************************/\n");


        fprintf(p_file,"LID_BIT VER_LID(NVRAM_EF_CACHE_%s_LID)\n", mmi_rp_mmi_cache_get_type_str(i));
        fprintf(p_file,"    nvram_cache_%s_struct * NVRAM_CACHE_TOTAL\n", mmi_rp_mmi_cache_get_type_lower_str(i));
        fprintf(p_file,"    {\n");
        fprintf(p_file,"        Cache%s:\"%d-byte parameter setting\";\n", mmi_rp_mmi_cache_get_type_lower_str(i), mmi_rp_mmi_cache_get_value_len(i));

        for (j = 0; j < g_mmi_rp_mmi_cache_cntx.cache_number[i] ; j++)
        {
            fprintf(p_file, "        Cache%s[%3d]\n", mmi_rp_mmi_cache_get_type_lower_str(i), j);
            fprintf(p_file, "        {\n");

            for (k = 0 ; k < value_len ; k++)
            {
                fprintf(p_file, "            %s_byte%d:8 \"%s\"\n",
                                g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->id_str,
                                k,
                                g_mmi_rp_mmi_cache_cntx.sort_table[i][j]->description);

                fprintf(p_file, "            {\n");
                fprintf(p_file, "            };\n");
            }
            fprintf(p_file, "        };\n");
        }
        fprintf(p_file, "    };\n");
    }
    fprintf(p_file,"#endif /* MMI_RP_MMI_CACHE_NVRAM_EDITOR_H */\n");
    fprintf(p_file,"\n\n");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_output_phase2_cat_xml_file
 * DESCRIPTION
 * PARAMETERS
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mmi_cache_output_phase2_cat_xml_file(FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i,j,k;
    kal_int32 value_len;
    mmi_rp_mmi_cache_data_struct *data;
    mmi_rp_mmi_cache_field_struct *field;
    mmi_rp_mmi_cache_option_struct *option;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!p_file)
    {
        MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

    fprintf(p_file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");


    for (i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        if (g_mmi_rp_mmi_cache_cntx.app_cache_data[i].total_count > 0)
        {

            fprintf(p_file, "<APP id=%\"%s\">\n", g_mmi_rp_mmi_cache_cntx.app_cache_data[i].app->appname);

            data = g_mmi_rp_mmi_cache_cntx.app_cache_data[i].cache_data_head;

            while(data != NULL)
            {
                /* output cache data tag and its attributes*/

                fprintf(p_file, "\n    <%s %s=\"%s\" %s=\"%s\"",
                    MMI_RP_MMI_CACHE_TAG_CACHEDATA,
                    MMI_RP_MMI_CACHE_ATTR_TYPE, mmi_rp_mmi_cache_get_type_lower_str(data->type),
                    MMI_RP_MMI_CACHE_ATTR_ID, data->id_str);

                if (data->restore_flag == KAL_TRUE)
                {
                    fprintf(p_file, " %s=\"%s\"", MMI_RP_MMI_CACHE_ATTR_RESTORE_FLAG, MMI_RP_MMI_CACHE_VAL_TRUE);
                }

                if (data->restore_id_str)
                {
                    fprintf(p_file, " %s=\"@%s\"", MMI_RP_MMI_CACHE_ATTR_RESTORE_ID, data->restore_id_str);
                }

                fprintf(p_file, ">\n");


                /* output default value tag */
                fprintf(p_file, "        <%s> [", MMI_RP_MMI_CACHE_TAG_DEFAULT_VALUE);

                value_len = mmi_rp_mmi_cache_get_value_len(data->type);

                for(j = 0; j < value_len; j++)
                {
                    if (j == value_len - 1)
                    {
                        fprintf(p_file, "0x%02X] ", data->default_value[j]);
                    }
                    else
                    {
                        fprintf(p_file, "0x%02X,", data->default_value[j]);
                    }
                }

                fprintf(p_file, "</%s>\n", MMI_RP_MMI_CACHE_TAG_DEFAULT_VALUE);

                /* output Description */
                fprintf(p_file, "        <%s> %s </%s>\n", MMI_RP_MMI_CACHE_TAG_DESCRIPTION, data->description, MMI_RP_MMI_CACHE_TAG_DESCRIPTION);


                /* output field */
                field = data->field_list_head;

                while(field != NULL)
                {
                    fprintf(p_file, "        <%s", MMI_RP_MMI_CACHE_TAG_FIELD);

                    if (field->name!= NULL)
                    {
                        fprintf(p_file, " %s=\"%s\"", MMI_RP_MMI_CACHE_ATTR_NAME, field->name);
                    }

                    if (field->size)
                    {
                        fprintf(p_file, " %s=\"%d\"", MMI_RP_MMI_CACHE_ATTR_SIZE, field->size);
                    }

                    if (field->min != MMI_RP_MMI_CACHE_MIN_DEFAULT)
                    {
                        fprintf(p_file, " %s=\"%d\"", MMI_RP_MMI_CACHE_ATTR_MIN, field->min);
                    }

                    if (field->max != MMI_RP_MMI_CACHE_MAX_DEFAULT)
                    {
                        fprintf(p_file, " %s=\"%d\"", MMI_RP_MMI_CACHE_ATTR_MAX, field->max);
                    }

                    fprintf(p_file, ">\n");

                    /* output option */
                    option = field->option_list_head;

                    while(option != NULL)
                    {
                        fprintf(p_file, "            <%s", MMI_RP_MMI_CACHE_TAG_OPTION);

                        if (option->hint)
                        {
                            fprintf(p_file, " %s=\"%s\"", MMI_RP_MMI_CACHE_ATTR_HINT, option->hint);
                        }

                        fprintf(p_file, "> [");

                        for(j = 0; j < field->size; j++)
                        {
                            if (j == field->size - 1)
                            {
                                fprintf(p_file, "0x%02X] </%s>\n", option->value[j], MMI_RP_MMI_CACHE_TAG_OPTION);
                            }
                            else
                            {
                                fprintf(p_file, "0x%02X,", option->value[j]);
                            }
                        }

                        option = option->next;
                    }

                    fprintf(p_file, "        </%s>\n", MMI_RP_MMI_CACHE_TAG_FIELD);

                    field = field->next;
                }

                fprintf(p_file, "    </%s>\n", MMI_RP_MMI_CACHE_TAG_CACHEDATA);
                data = data->next;
            }
            fprintf(p_file, "</APP>\n\n\n");
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mmi_cache_output_phase2
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mmi_cache_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(p_file = fopen(MMI_CACHE_DEFAULT_VALUE_PATH, "w+"))
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
            p_file,
            MMI_CACHE_DEFAULT_VALUE_H_FILE,
            "Resource populate function generated by XML resgen",
            "03 13 2011 yan.liang");

        mmi_rp_mmi_cache_output_phase2_default_value_h_file(p_file);
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

    if(p_file = fopen(MMI_CACHE_TABLE_C_PATH, "w+"))
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
            p_file,
            MMI_CACHE_TABLE_C_FILE,
            "Resource populate function generated by XML resgen",
            "03 13 2011 yan.liang");

        mmi_rp_mmi_cache_output_phase2_table_c_file(p_file);
        mmi_rp_mmi_cache_output_phase2_restore_function(p_file);
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

    if(p_file = fopen(MMI_CACHE_TABLE_H_PATH, "w+"))
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
            p_file,
            MMI_CACHE_TABLE_H_FILE,
            "Resource populate function generated by XML resgen",
            "03 13 2011 yan.liang");

        mmi_rp_mmi_cache_output_phase2_table_h_file(p_file);
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

    if(p_file = fopen(MMI_CAHCE_NVRAM_EDITOR_PATH, "w+"))
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
            p_file,
            MMI_CACHE_NVRAM_EDIOTR_H_FILE,
            "Resource populate function generated by XML resgen",
            "03 13 2011 yan.liang");
        mmi_rp_mmi_cache_output_phase2_nvram_editor_h_file(p_file);
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

    if(p_file = fopen(MMI_CACHE_CAT_XML_PATH, "w+"))
    {
        mmi_rp_mmi_cache_output_phase2_cat_xml_file(p_file);
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

}


