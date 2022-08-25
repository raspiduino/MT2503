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
 *  mmi_rp_theme.c
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
#include "mmi_rp_theme.h"
#include "mmi_rp_hash.h"

#include "mmi_res_range_def.h"


extern const mmi_resource_base_struct g_mmi_resource_base_table[];

void mmi_rp_theme_output_phase1_app_def_h_file(U32 app_index, FILE *p_file);

#ifdef __RESGEN_INTERNAL_POP_FILE_REDUCE__
    void mmi_rp_theme_output_phase2_app_c_file(U32 app_index);
#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
void mmi_rp_theme_output_phase2_app_c_file(U32 app_index, FILE *p_file);
#endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__


#define MMI_RP_THEME_CURR_APP_THEME       g_mmi_rp_theme_cntx.app_theme_data[g_mmi_rp_mgr_cntx.cur_app_index]
#define MMI_RP_THEME_CURR_APP_COLOR       g_mmi_rp_theme_cntx.app_color_data[g_mmi_rp_mgr_cntx.cur_app_index]
#define MMI_RP_THEME_CURR_APP_FONTSTYLE   g_mmi_rp_theme_cntx.app_fontstyle_data[g_mmi_rp_mgr_cntx.cur_app_index]
#define MMI_RP_THEME_CURR_APP_INTEGER     g_mmi_rp_theme_cntx.app_integer_data[g_mmi_rp_mgr_cntx.cur_app_index]
#define MMI_RP_THEME_CURR_APP_BINARY      g_mmi_rp_theme_cntx.app_binary_data[g_mmi_rp_mgr_cntx.cur_app_index]

mmi_rp_theme_cntx_struct g_mmi_rp_theme_cntx;
MMI_BOOL g_mmi_rp_is_theme = MMI_FALSE;


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_theme_init
 * DESCRIPTION
 *  Initializes the theme context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_theme_init(void)
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

    memset(&g_mmi_rp_theme_cntx, 0, sizeof(g_mmi_rp_theme_cntx));

    g_mmi_rp_theme_cntx.app_theme_data = (mmi_rp_theme_data_struct*)malloc(sizeof(mmi_rp_theme_data_struct) * g_mmi_rp_mgr_cntx.total_apps);
    if(!g_mmi_rp_theme_cntx.app_theme_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_theme_cntx.app_theme_data, 0, sizeof(mmi_rp_theme_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_theme_cntx.app_color_data = (mmi_rp_color_data_struct*)malloc(sizeof(mmi_rp_color_data_struct) * g_mmi_rp_mgr_cntx.total_apps);
    if(!g_mmi_rp_theme_cntx.app_color_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_theme_cntx.app_color_data, 0, sizeof(mmi_rp_color_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_theme_cntx.app_fontstyle_data = (mmi_rp_fontstyle_data_struct*)malloc(sizeof(mmi_rp_fontstyle_data_struct) * g_mmi_rp_mgr_cntx.total_apps);
    if(!g_mmi_rp_theme_cntx.app_fontstyle_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_theme_cntx.app_fontstyle_data, 0, sizeof(mmi_rp_fontstyle_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_theme_cntx.app_integer_data = (mmi_rp_integer_data_struct*)malloc(sizeof(mmi_rp_integer_data_struct) * g_mmi_rp_mgr_cntx.total_apps);
    if(!g_mmi_rp_theme_cntx.app_integer_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_theme_cntx.app_integer_data, 0, sizeof(mmi_rp_integer_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_theme_cntx.app_binary_data = (mmi_rp_binary_data_struct*)malloc(sizeof(mmi_rp_binary_data_struct) * g_mmi_rp_mgr_cntx.total_apps);
    if(!g_mmi_rp_theme_cntx.app_binary_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_theme_cntx.app_binary_data, 0, sizeof(mmi_rp_binary_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_theme_cntx.hash_color = mmi_rp_hash_create(0xFFFF);    /* 0xFFFF is the resource ID range */
    g_mmi_rp_theme_cntx.hash_fontstyle = mmi_rp_hash_create(0xFFFF);    /* 0xFFFF is the resource ID range */
    g_mmi_rp_theme_cntx.hash_integer = mmi_rp_hash_create(0xFFFF);    /* 0xFFFF is the resource ID range */
    g_mmi_rp_theme_cntx.hash_binary = mmi_rp_hash_create(0xFFFF);    /* 0xFFFF is the resource ID range */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_theme_deinit
 * DESCRIPTION
 *  Initializes the theme context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_theme_deinit(void)
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
 *  mmi_rp_theme_set_app_range
 * DESCRIPTION
 *  Initializes the theme context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_theme_set_app_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 range = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_RP_THEME_CURR_APP_THEME.theme == NULL)
    {
        range = g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min + 1;

        MMI_RP_THEME_CURR_APP_THEME.theme   = (mmi_rp_theme_id_struct*)malloc(sizeof(mmi_rp_theme_id_struct) * range);
        MMI_RP_THEME_CURR_APP_COLOR.color   = (mmi_rp_color_id_struct*)malloc(sizeof(mmi_rp_color_id_struct) * range);
        MMI_RP_THEME_CURR_APP_FONTSTYLE.fontstyle = (mmi_rp_fontstyle_id_struct*)malloc(sizeof(mmi_rp_fontstyle_id_struct) * range);
        MMI_RP_THEME_CURR_APP_BINARY.binary  = (mmi_rp_binary_id_struct*)malloc(sizeof(mmi_rp_binary_id_struct) * range);
        MMI_RP_THEME_CURR_APP_INTEGER.integer = (mmi_rp_integer_id_struct*)malloc(sizeof(mmi_rp_integer_id_struct) * range);

        if((!MMI_RP_THEME_CURR_APP_THEME.theme) && (range > 0))
        {
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }

        memset(MMI_RP_THEME_CURR_APP_THEME.theme, 0, sizeof(mmi_rp_theme_id_struct) * range);
        memset(MMI_RP_THEME_CURR_APP_COLOR.color, 0, sizeof(mmi_rp_color_id_struct) * range);
        memset(MMI_RP_THEME_CURR_APP_FONTSTYLE.fontstyle, 0, sizeof(mmi_rp_fontstyle_id_struct) * range);
        memset(MMI_RP_THEME_CURR_APP_BINARY.binary, 0, sizeof(mmi_rp_binary_id_struct) * range);
        memset(MMI_RP_THEME_CURR_APP_INTEGER.integer, 0, sizeof(mmi_rp_integer_id_struct) * range);
    }
}


    
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_theme_start_handler
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
int mmi_rp_theme_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    U8 *curr_theme_id = NULL;
    S32 parent_tag_id = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Theme - start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    g_mmi_rp_is_theme = MMI_TRUE;
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_theme_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_theme_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Theme -end: %s\n", el);
    g_mmi_rp_is_theme = MMI_FALSE;
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_theme_data_handler
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
int mmi_rp_theme_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Theme -data: %s\n", data);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_color_start_handler
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
int mmi_rp_color_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    U8 *curr_id = NULL;
    U8 *curr_desc = NULL;
    U8 *curr_opaque = NULL;
    S32 parent_tag_id = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Color - start: %s\n", el);
    
    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0 &&
       strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_THEME) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    /* String ID exceeded the app_range */
    if(MMI_RP_THEME_CURR_APP_COLOR.total_count >= (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);
        
        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID) == 0)
        {
            curr_id = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_DESC) == 0)
        {
            curr_desc = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_OPAQUE) == 0)
        {
            curr_opaque = (U8*)attr[index + 1];
        }
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        index += 2;
    }
    
    if(curr_id != NULL)
    {
        if(!mmi_rp_hash_find(g_mmi_rp_theme_cntx.hash_color, curr_id))
        {
            MMI_RP_THEME_CURR_APP_COLOR.color[MMI_RP_THEME_CURR_APP_COLOR.total_count].id_str = mmi_rp_hash_add(g_mmi_rp_theme_cntx.hash_color, curr_id);
            
            if (curr_desc != NULL)
            {
                MMI_RP_THEME_CURR_APP_COLOR.color[MMI_RP_THEME_CURR_APP_COLOR.total_count].desc_str = (U8*)malloc(strlen(curr_desc)+1);
                strcpy(MMI_RP_THEME_CURR_APP_COLOR.color[MMI_RP_THEME_CURR_APP_COLOR.total_count].desc_str, curr_desc);
            }
            
            if (curr_opaque != NULL)
            {
                MMI_RP_THEME_CURR_APP_COLOR.color[MMI_RP_THEME_CURR_APP_COLOR.total_count].opaque = (U8*)malloc(strlen(curr_opaque)+1);
                strcpy(MMI_RP_THEME_CURR_APP_COLOR.color[MMI_RP_THEME_CURR_APP_COLOR.total_count].opaque, curr_opaque);
            }

            MMI_RP_THEME_CURR_APP_COLOR.total_count++;
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
 *  mmi_rp_color_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_color_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Color -end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_fontstyle_start_handler
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
int mmi_rp_fontstyle_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    U8 *curr_id = NULL;
    U8 *curr_desc = NULL;
    S32 parent_tag_id = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Fontstyle - start: %s\n", el);
    
    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0 &&
       strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_THEME) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    /* String ID exceeded the app_range */
    if(MMI_RP_THEME_CURR_APP_FONTSTYLE.total_count >= (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);
        
        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID) == 0)
        {
            curr_id = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_DESC) == 0)
        {
            curr_desc = (U8*)attr[index + 1];
        }
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        index += 2;
    }
    
    if(curr_id != NULL)
    {
        if(!mmi_rp_hash_find(g_mmi_rp_theme_cntx.hash_fontstyle, curr_id))
        {
            MMI_RP_THEME_CURR_APP_FONTSTYLE.fontstyle[MMI_RP_THEME_CURR_APP_FONTSTYLE.total_count].id_str = mmi_rp_hash_add(g_mmi_rp_theme_cntx.hash_fontstyle, curr_id);
            
            if (curr_desc != NULL)
            {
                MMI_RP_THEME_CURR_APP_FONTSTYLE.fontstyle[MMI_RP_THEME_CURR_APP_FONTSTYLE.total_count].desc_str = (U8*)malloc(strlen(curr_desc)+1);
                strcpy(MMI_RP_THEME_CURR_APP_FONTSTYLE.fontstyle[MMI_RP_THEME_CURR_APP_FONTSTYLE.total_count].desc_str, curr_desc);
            }
            
            MMI_RP_THEME_CURR_APP_FONTSTYLE.total_count++;
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
 *  mmi_rp_fontstyle_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_fontstyle_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Fontstyle -end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_binary_start_handler
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
int mmi_rp_binary_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    U8 *curr_id = NULL;
    U8 *curr_desc = NULL;
    S32 parent_tag_id = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Binary - start: %s\n", el);
    
    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0 &&
       strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_THEME) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    /* String ID exceeded the app_range */
    if(MMI_RP_THEME_CURR_APP_BINARY.total_count >= (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);
        
        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID) == 0)
        {
            curr_id = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_DESC) == 0)
        {
            curr_desc = (U8*)attr[index + 1];
        }
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        index += 2;
    }
    
    if(curr_id != NULL)
    {
        if(!mmi_rp_hash_find(g_mmi_rp_theme_cntx.hash_binary, curr_id))
        {
            MMI_RP_THEME_CURR_APP_BINARY.binary[MMI_RP_THEME_CURR_APP_BINARY.total_count].id_str = mmi_rp_hash_add(g_mmi_rp_theme_cntx.hash_binary, curr_id);
            
            if (curr_desc != NULL)
            {
                MMI_RP_THEME_CURR_APP_BINARY.binary[MMI_RP_THEME_CURR_APP_BINARY.total_count].desc_str = (U8*)malloc(strlen(curr_desc)+1);
                strcpy(MMI_RP_THEME_CURR_APP_BINARY.binary[MMI_RP_THEME_CURR_APP_BINARY.total_count].desc_str, curr_desc);
            }

            MMI_RP_THEME_CURR_APP_BINARY.total_count++;
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
 *  mmi_rp_binary_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_binary_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Binary -end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_integer_start_handler
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
int mmi_rp_integer_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    U8 *curr_id = NULL;
    U8 *curr_desc = NULL;
    U8 *curr_min = NULL;
    U8 *curr_max = NULL;
    S32 parent_tag_id = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Integer - start: %s\n", el);
    
    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0 &&
       strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_THEME) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    /* String ID exceeded the app_range */
    if(MMI_RP_THEME_CURR_APP_INTEGER.total_count >= (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);
        
        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID) == 0)
        {
            curr_id = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_DESC) == 0)
        {
            curr_desc = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_MIN) == 0)
        {
            curr_min = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_MAX) == 0)
        {
            curr_max = (U8*)attr[index + 1];
        }
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        index += 2;
    }
    
    if(curr_id != NULL)
    {
        if(!mmi_rp_hash_find(g_mmi_rp_theme_cntx.hash_integer, curr_id))
        {
            MMI_RP_THEME_CURR_APP_INTEGER.integer[MMI_RP_THEME_CURR_APP_INTEGER.total_count].id_str = mmi_rp_hash_add(g_mmi_rp_theme_cntx.hash_integer, curr_id);
            
            if (curr_desc != NULL)
            {
                MMI_RP_THEME_CURR_APP_INTEGER.integer[MMI_RP_THEME_CURR_APP_INTEGER.total_count].desc_str = (U8*)malloc(strlen(curr_desc)+1);
                strcpy(MMI_RP_THEME_CURR_APP_INTEGER.integer[MMI_RP_THEME_CURR_APP_INTEGER.total_count].desc_str, curr_desc);
            }

            if (curr_min != NULL)
            {
                MMI_RP_THEME_CURR_APP_INTEGER.integer[MMI_RP_THEME_CURR_APP_INTEGER.total_count].min = (U8*)malloc(strlen(curr_min)+1);
                strcpy(MMI_RP_THEME_CURR_APP_INTEGER.integer[MMI_RP_THEME_CURR_APP_INTEGER.total_count].min, curr_min);
            }

            if (curr_max != NULL)
            {
                MMI_RP_THEME_CURR_APP_INTEGER.integer[MMI_RP_THEME_CURR_APP_INTEGER.total_count].max = (U8*)malloc(strlen(curr_max)+1);
                strcpy(MMI_RP_THEME_CURR_APP_INTEGER.integer[MMI_RP_THEME_CURR_APP_INTEGER.total_count].max, curr_max);
            }
            
            MMI_RP_THEME_CURR_APP_INTEGER.total_count++;
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
 *  mmi_rp_integer_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_integer_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Integer -end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_theme_filter
 * DESCRIPTION
 *  This function is for resgen to filter image resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_theme_filter(void)
{
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_theme_output_phase1
 * DESCRIPTION
 *  Output ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_theme_output_phase1(void)
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
            mmi_rp_theme_output_phase1_app_def_h_file(i, p_file);
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
 *  mmi_rp_theme_output_phase1_app_def_h_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_theme_output_phase1_app_def_h_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0;
    U8 str_enum_name[MMI_RP_OUTPUT_ENUM_NAME_MAX], str_enum_max[MMI_RP_OUTPUT_ENUM_NAME_MAX];
    MMI_BOOL first = MMI_TRUE;
    mmi_rp_theme_data_struct *curr_app_theme = &(g_mmi_rp_theme_cntx.app_theme_data[app_index]);
    mmi_rp_color_data_struct *curr_app_color = &(g_mmi_rp_theme_cntx.app_color_data[app_index]);
    mmi_rp_fontstyle_data_struct *curr_app_fontstyle = &(g_mmi_rp_theme_cntx.app_fontstyle_data[app_index]);
    mmi_rp_binary_data_struct *curr_app_binary = &(g_mmi_rp_theme_cntx.app_binary_data[app_index]);
    mmi_rp_integer_data_struct *curr_app_integer = &(g_mmi_rp_theme_cntx.app_integer_data[app_index]);
    S32 app_enum_log_counter = -1;      /* -1 for debug purpose */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        /* Output color */
        memset(str_enum_name, 0, sizeof(str_enum_name));
        strcpy(str_enum_name, "mmi_rp_");
        strcat(str_enum_name, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_name, "_color_enum");
        for(i = 0; i < strlen(str_enum_name); i++)
        {
            str_enum_name[i] = tolower(str_enum_name[i]);
        }

        memset(str_enum_max, 0, sizeof(str_enum_max));
        strcpy(str_enum_max, "MMI_RP_");
        strcat(str_enum_max, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_max, "_COLOR_MAX");
        for(i = 0; i < strlen(str_enum_max); i++)
        {
            str_enum_max[i] = toupper(str_enum_max[i]);
        }

        /* Check if no str IDs. */
        if(curr_app_color->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            fprintf(p_file, "\n\n");
            fprintf(p_file, "/******************** Color resource IDs - begin ********************/\n");
            fprintf(p_file, "typedef enum\n{\n");

            for(i = 0; i < curr_app_color->total_count; i++)
            {
                if(first)
                {
                    fprintf(p_file, "    %s = %d + 1, /* BASE_ID + 1 */\n", curr_app_color->color[i].id_str, g_mmi_resource_base_table[app_index].min);
                    first = MMI_FALSE;

                    app_enum_log_counter = g_mmi_resource_base_table[app_index].min + 1;
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_color->color[i].id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
                else
                {
                    fprintf(p_file, "    %s,\n", curr_app_color->color[i].id_str);
                    
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_color->color[i].id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
            }

            fprintf(p_file, "    %s\n", str_enum_max);
            fprintf(p_file, "}%s;\n", str_enum_name);
            fprintf(p_file, "/******************** Color resource IDs - finish ********************/\n");
        }
        first = MMI_TRUE;
        app_enum_log_counter = -1;


        /* Output Fontstyle */
        memset(str_enum_name, 0, sizeof(str_enum_name));
        strcpy(str_enum_name, "mmi_rp_");
        strcat(str_enum_name, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_name, "_fontstyle_enum");
        for(i = 0; i < strlen(str_enum_name); i++)
        {
            str_enum_name[i] = tolower(str_enum_name[i]);
        }
        
        memset(str_enum_max, 0, sizeof(str_enum_max));
        strcpy(str_enum_max, "MMI_RP_");
        strcat(str_enum_max, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_max, "_FONTSTYLE_MAX");
        for(i = 0; i < strlen(str_enum_max); i++)
        {
            str_enum_max[i] = toupper(str_enum_max[i]);
        }
        
        /* Check if no str IDs. */
        if(curr_app_fontstyle->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            fprintf(p_file, "\n\n");
            fprintf(p_file, "/******************** Fontstyle resource IDs - begin ********************/\n");
            fprintf(p_file, "typedef enum\n{\n");
            
            for(i = 0; i < curr_app_fontstyle->total_count; i++)
            {
                if(first)
                {
                    fprintf(p_file, "    %s = %d + 1, /* BASE_ID + 1 */\n", curr_app_fontstyle->fontstyle[i].id_str, g_mmi_resource_base_table[app_index].min);
                    first = MMI_FALSE;
                    
                    app_enum_log_counter = g_mmi_resource_base_table[app_index].min + 1;
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_fontstyle->fontstyle[i].id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
                else
                {
                    fprintf(p_file, "    %s,\n", curr_app_fontstyle->fontstyle[i].id_str);

                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_fontstyle->fontstyle[i].id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
            }
            
            fprintf(p_file, "    %s\n", str_enum_max);
            fprintf(p_file, "}%s;\n", str_enum_name);
            fprintf(p_file, "/******************** Fontstyle resource IDs - finish ********************/\n");
        }
        first = MMI_TRUE;
        app_enum_log_counter = -1;
        

        /* Output Binary */
        memset(str_enum_name, 0, sizeof(str_enum_name));
        strcpy(str_enum_name, "mmi_rp_");
        strcat(str_enum_name, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_name, "_binary_enum");
        for(i = 0; i < strlen(str_enum_name); i++)
        {
            str_enum_name[i] = tolower(str_enum_name[i]);
        }
        
        memset(str_enum_max, 0, sizeof(str_enum_max));
        strcpy(str_enum_max, "MMI_RP_");
        strcat(str_enum_max, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_max, "_BINARY_MAX");
        for(i = 0; i < strlen(str_enum_max); i++)
        {
            str_enum_max[i] = toupper(str_enum_max[i]);
        }
        
        /* Check if no str IDs. */
        if(curr_app_binary->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            fprintf(p_file, "\n\n");
            fprintf(p_file, "/******************** Binary resource IDs - begin ********************/\n");
            fprintf(p_file, "typedef enum\n{\n");
            
            for(i = 0; i < curr_app_binary->total_count; i++)
            {
                if(first)
                {
                    fprintf(p_file, "    %s = %d + 1, /* BASE_ID + 1 */\n", curr_app_binary->binary[i].id_str, g_mmi_resource_base_table[app_index].min);
                    first = MMI_FALSE;

                    app_enum_log_counter = g_mmi_resource_base_table[app_index].min + 1;
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_binary->binary[i].id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
                else
                {
                    fprintf(p_file, "    %s,\n", curr_app_binary->binary[i].id_str);
                    
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_binary->binary[i].id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
            }
            
            fprintf(p_file, "    %s\n", str_enum_max);
            fprintf(p_file, "}%s;\n", str_enum_name);
            fprintf(p_file, "/******************** Binary resource IDs - finish ********************/\n");
        }
        first = MMI_TRUE;
        app_enum_log_counter = -1;
        
        
        /* Output Integer */
        memset(str_enum_name, 0, sizeof(str_enum_name));
        strcpy(str_enum_name, "mmi_rp_");
        strcat(str_enum_name, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_name, "_integer_enum");
        for(i = 0; i < strlen(str_enum_name); i++)
        {
            str_enum_name[i] = tolower(str_enum_name[i]);
        }
        
        memset(str_enum_max, 0, sizeof(str_enum_max));
        strcpy(str_enum_max, "MMI_RP_");
        strcat(str_enum_max, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_max, "_INTEGER_MAX");
        for(i = 0; i < strlen(str_enum_max); i++)
        {
            str_enum_max[i] = toupper(str_enum_max[i]);
        }
        
        /* Check if no str IDs. */
        if(curr_app_integer->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            fprintf(p_file, "\n\n");
            fprintf(p_file, "/******************** Integer resource IDs - begin ********************/\n");
            fprintf(p_file, "typedef enum\n{\n");
            
            for(i = 0; i < curr_app_integer->total_count; i++)
            {
                if(first)
                {
                    fprintf(p_file, "    %s = %d + 1, /* BASE_ID + 1 */\n", curr_app_integer->integer[i].id_str, g_mmi_resource_base_table[app_index].min);
                    first = MMI_FALSE;

                    app_enum_log_counter = g_mmi_resource_base_table[app_index].min + 1;
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_integer->integer[i].id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
                else
                {
                    fprintf(p_file, "    %s,\n", curr_app_integer->integer[i].id_str);
                    
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_integer->integer[i].id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
            }
            
            fprintf(p_file, "    %s\n", str_enum_max);
            fprintf(p_file, "}%s;\n", str_enum_name);
            fprintf(p_file, "/******************** Integer resource IDs - finish ********************/\n");
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
 *  mmi_rp_theme_output_phase2
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_theme_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    U8 *str_output_filename = NULL;
    CHAR *str_output_filename_header = NULL;
    CHAR *str_function_name = NULL;
    U8 str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];

    mmi_rp_color_data_struct *curr_app_color = NULL;
    mmi_rp_fontstyle_data_struct *curr_app_fontstyle = NULL;
    mmi_rp_binary_data_struct *curr_app_binary = NULL;
    mmi_rp_integer_data_struct *curr_app_integer = NULL;
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

        /* dotC file name */
        str_output_filename = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_C_FILE_PATH, g_mmi_resource_base_table[i].appname);

#ifdef __RESGEN_INTERNAL_POP_FILE_REDUCE__
    mmi_rp_theme_output_phase2_app_c_file(i);

#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
        /* Menu resource module has already written the header and started the function. */ 
        /* Open the file in append mode */
        if(p_file = fopen(str_output_filename, "a"))            
        {
            mmi_rp_theme_output_phase2_app_c_file(i, p_file);
            fclose(p_file);
        }
        else
        {
            /* Error writing output file. Exit. */
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
        }
#endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__
    }
    
    memset(str_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_filename, MMI_RP_MGR_XML_VENUS_THEME_LOG);

    if(p_file = fopen(str_filename, "a"))           
    {
        fprintf(p_file, "[RP_COLOR]\n");
        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            curr_app_color = &(g_mmi_rp_theme_cntx.app_color_data[i]);

            for(j = 0; j < curr_app_color->total_count; j++)
            {
                fprintf(p_file, "%s\t%s\t%s\n", curr_app_color->color[j].id_str, curr_app_color->color[j].desc_str, curr_app_color->color[j].opaque);
            }
        }

        fprintf(p_file, "[RP_FONTSTYLE]\n");
        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            curr_app_fontstyle = &(g_mmi_rp_theme_cntx.app_fontstyle_data[i]);
            
            for(j = 0; j < curr_app_fontstyle->total_count; j++)
            {
                fprintf(p_file, "%s\t%s\n", curr_app_fontstyle->fontstyle[j].id_str, curr_app_fontstyle->fontstyle[j].desc_str);
            }
        }

        fprintf(p_file, "[RP_BINARY]\n");
        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            curr_app_binary = &(g_mmi_rp_theme_cntx.app_binary_data[i]);
            
            for(j = 0; j < curr_app_binary->total_count; j++)
            {
                fprintf(p_file, "%s\t%s\n", curr_app_binary->binary[j].id_str, curr_app_binary->binary[j].desc_str);
            }
        }

        fprintf(p_file, "[RP_INTEGER]\n");
        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            curr_app_integer = &(g_mmi_rp_theme_cntx.app_integer_data[i]);
            
            for(j = 0; j < curr_app_integer->total_count; j++)
            {
                fprintf(p_file, "%s\t%s\t%s\t%s\n", curr_app_integer->integer[j].id_str, curr_app_integer->integer[j].desc_str, curr_app_integer->integer[j].min, curr_app_integer->integer[j].max);
            }
        }

        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}


#ifndef __RESGEN_INTERNAL_POP_FILE_REDUCE__
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_theme_output_phase2_app_c_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_theme_output_phase2_app_c_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        /* There's no current requirement to populate Timer resources in .c files. */
        /* Keep it here for future reference. */
    }
}
#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_theme_output_phase2_app_c_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_theme_output_phase2_app_c_file(U32 app_index)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE * p_file = NULL;
    MMI_BOOL has_resource_to_populate = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

        /* There's no current requirement to populate Timer resources in .c files. */
        /* Keep it here for future reference. */
       if(has_resource_to_populate){
           // Use mmi_rp_open_population_c_file to open resource population output file for AP.
           // Don't use fopen API to open the file whose name is calculated with mmi_rp_mgr_contruct_name.
           // Such codes may corrupted the entire resgen system.
           p_file = mmi_rp_open_population_c_file(app_index, RES_LEGACY_POP_BINARY_MASK);        
           if(p_file == NULL){
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}
    }
#endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__
