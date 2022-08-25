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
 *  mmi_rp_image.c
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


#define WIN32_LEAN_AND_MEAN
#include "windows.h"

#include <stdio.h>
#include <stdlib.h>

#include "MMIDataType.h"
#include "mmi_rp_xml.h"
#include "mmi_rp_xml_def.h"
#include "mmi_rp_image.h"
#include "mmi_rp_menu.h"
#include "mmi_rp_theme.h"

#include "mmi_res_range_def.h"
#include "CustDataProts.h"  // For __RESGEN_INTERNAL_OFFLINE__

#define MMI_IMAGE_TYPE_MAPPING_MAX 8

#ifndef __RESGEN_INTERNAL_OFFLINE__
#define OFFLINE_RESGEN_NO_FORCE_TYPE 0xFF
#endif //__RESGEN_INTERNAL_OFFLINE__

const U32 MMI_IMAGE_TYPE_MAPPING[MMI_IMAGE_TYPE_MAPPING_MAX]=
{
    OFFLINE_RESGEN_NO_FORCE_TYPE,
    AUTO_TYPE,
    FORCE_ABM,
    FORCE_AB2,
    FORCE_BMP,
    FORCE_ABM_SEQUENCE,
    AUTO_TYPE,
    AUTO_TYPE
};


void mmi_rp_img_output_phase1_app_def_h_file(U32 app_index, FILE *p_file);
void mmi_rp_img_output_phase2_venus_theme(FILE *p_file);

#ifdef __RESGEN_INTERNAL_POP_FILE_REDUCE__
void mmi_rp_img_output_phase2_app_c_file(U32 app_index);
#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
void mmi_rp_img_output_phase2_app_c_file(U32 app_index, FILE *p_file);
#endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__
MMI_BOOL mmi_rp_img_add_img_to_groups(U8 *groups, U8 *img_id);

extern const mmi_resource_base_struct g_mmi_resource_base_table[];

#define MMI_RP_IMG_CURR_APP_IMG       g_mmi_rp_img_cntx.app_img_data[g_mmi_rp_mgr_cntx.cur_app_index]
mmi_rp_img_cntx_struct g_mmi_rp_img_cntx;

/* These ENUM id strings will be used in ReadRes for images force type */
/* These are defined in CustDataProts.h */
static const U8 *g_mmi_rp_img_force_type_enum_str[MMI_RP_IMG_FORCE_TYPE_TOTAL] = 
{
    "",
    MMI_RP_MGR_VAL_AUTO_TYPE,
    MMI_RP_MGR_VAL_FORCE_ABM,
    MMI_RP_MGR_VAL_FORCE_AB2,
    MMI_RP_MGR_VAL_FORCE_BMP,
    MMI_RP_MGR_VAL_FORCE_ABM_SEQUENCE,
    MMI_RP_MGR_VAL_FORCE_JPG
};


/*****************************************************************************
* FUNCTION
*  mmi_rp_img_init
* DESCRIPTION
*  Initializes the img context structure. Called for every .res file parsed.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_img_init(void)
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

    memset(&g_mmi_rp_img_cntx, 0, sizeof(g_mmi_rp_img_cntx));
    g_mmi_rp_img_cntx.app_img_data = (mmi_rp_img_data_struct*)malloc(sizeof(mmi_rp_img_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    if(!g_mmi_rp_img_cntx.app_img_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_img_cntx.app_img_data, 0, sizeof(mmi_rp_img_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_img_cntx.id_hash = mmi_rp_hash_create(0xFFFF);              /* 0xFFFF is the resource ID range */
    g_mmi_rp_img_cntx.file_path_hash = mmi_rp_hash_create(0xFFFF);    
    g_mmi_rp_img_cntx.hash_others = mmi_rp_hash_create(0xFFFF);    /* For Group names */
}



/*****************************************************************************
* FUNCTION
*  mmi_rp_img_deinit
* DESCRIPTION
*  DeInitializes the img context structure. Called for every .res file parsed.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_img_deinit(void)
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
*  mmi_rp_img_set_app_range
* DESCRIPTION
*  Initializes the img context structure. Called for every .res file parsed.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_img_set_app_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 range = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_RP_IMG_CURR_APP_IMG.images == NULL)
    {
        range = g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min + 1;

        MMI_RP_IMG_CURR_APP_IMG.images = (mmi_rp_img_id_struct*)malloc(sizeof(mmi_rp_img_id_struct) * range);
        if((!MMI_RP_IMG_CURR_APP_IMG.images) && (range > 0))
        {
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }
        memset(MMI_RP_IMG_CURR_APP_IMG.images, 0, sizeof(mmi_rp_img_id_struct) * range);

        /* In the worst case, Toggles can be as big as the range itself. */
        MMI_RP_IMG_CURR_APP_IMG.toggle_index = (S32*)malloc(sizeof(mmi_rp_img_id_struct) * (range * 2));
        if((!MMI_RP_IMG_CURR_APP_IMG.toggle_index) && (range > 0))
        {
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }
        memset(MMI_RP_IMG_CURR_APP_IMG.toggle_index, -1, sizeof(mmi_rp_img_enfb_toggle_enum) * (range * 2));
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_img_start_handler
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
int mmi_rp_img_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    mmi_rp_scope_enum curr_scope = MMI_RP_SCOPE_NONE;
    U8 *curr_img_id = NULL, *group_str = NULL;
    U8 *curr_img_desc = NULL;
    U8 *curr_img_format = NULL;
    U8 *curr_img_9slice = NULL;
    U8 *size_limit[MMI_RP_IMG_SIZE_LIMIT_TOTAL];
    mmi_rp_flag_bin_enum curr_bin = MMI_RP_FLAG_SINGLE_BIN;
    mmi_rp_img_force_type_enum curr_force_type = MMI_RP_IMG_FORCE_TYPE_NONE;
    S32 curr_quality = OFFLINE_IMAGE_PARAM_QUALITY_MEDIUM;
	BOOLEAN compression = MMI_TRUE;
    S32 parent_tag_id = -1;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Image-start: %s\n", el);

    for (i = 0; i < MMI_RP_IMG_SIZE_LIMIT_TOTAL; i++)
    {
        size_limit[i] = NULL;
    }

    /* Checking correct order of tags */
    if((strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0) &&
        (strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_ENFB) != 0)&&
        (strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_THEME) != 0)&&
        (strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_MULTI_IMAGE) != 0))
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /* String ID exceeded the app_range - 1 (BASE_ID is reserved for Mainmenu app) */
    if(MMI_RP_IMG_CURR_APP_IMG.total_count >= (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID) == 0)
        {
            curr_img_id = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_DESC) == 0)
        {
            curr_img_desc = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_FORMAT) == 0)
        {
            curr_img_format = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_QVGA) == 0)
        {
            size_limit[MMI_RP_IMG_SIZE_LIMIT_QVGA] = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_WQVGA) == 0)
        {
            size_limit[MMI_RP_IMG_SIZE_LIMIT_WQVGA] = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_LANDSCAPE) == 0)
        {
            size_limit[MMI_RP_IMG_SIZE_LIMIT_LANDSCAPE] = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_HVGA) == 0)
        {
            size_limit[MMI_RP_IMG_SIZE_LIMIT_HVGA] = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_9SLICE) == 0)
        {
            curr_img_9slice = (U8*)attr[index + 1];
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
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_FLAG) == 0)
        {
           if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_MULTIBIN) == 0 || (strcmp(attr[index + 1], MMI_RP_MGR_VAL_REPLACEABLE) ==0))
            {
                curr_bin = MMI_RP_FLAG_MULTI_BIN;
            }
            else /* Default for scope. */
            {
                curr_bin = MMI_RP_FLAG_SINGLE_BIN;
            }
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_FORCE_TYPE) == 0)
        {
            if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_FORCE_ABM) == 0)
            {
                curr_force_type = MMI_RP_IMG_FORCE_TYPE_ABM;
            }
            else if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_FORCE_AB2) == 0)
            {
                curr_force_type = MMI_RP_IMG_FORCE_TYPE_AB2;
            }
            else if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_FORCE_BMP) == 0)
            {
                curr_force_type = MMI_RP_IMG_FORCE_TYPE_BMP;
            }
            else if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_FORCE_ABM_SEQUENCE) == 0)
            {
                curr_force_type = MMI_RP_IMG_FORCE_TYPE_ABM_SEQUENCE;
            }
            else if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_FORCE_JPG) == 0)
            {
                curr_force_type = MMI_RP_IMG_FORCE_TYPE_JPG;
            }
            else if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_AUTO_TYPE) == 0)
            {
                curr_force_type = MMI_RP_IMG_FORCE_TYPE_AUTO;
            }
            else /* Default for scope. */
            {
                curr_force_type = MMI_RP_IMG_FORCE_TYPE_NONE;
            }                 
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_GROUP) == 0)
        {
            group_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_QUALITY) == 0)
        {
            if(strcmp(attr[index+1],MMI_RP_MGR_VAL_HIGH_QUALITY)==0){
                curr_quality = OFFLINE_IMAGE_PARAM_QUALITY_HIGH;
            }else if(strcmp(attr[index+1],MMI_RP_MGR_VAL_LOW_QUALITY)==0){
                curr_quality = OFFLINE_IMAGE_PARAM_QUALITY_LOW;
            }else if(strcmp(attr[index+1],MMI_RP_MGR_VAL_MEDIUM_QUALITY)==0){
                curr_quality = OFFLINE_IMAGE_PARAM_QUALITY_MEDIUM;
            }else{
                curr_quality = OFFLINE_IMAGE_PARAM_QUALITY_MEDIUM;
            }                  
        }else if(strcmp(attr[index], MMI_RP_MGR_ATTR_COMPRESSION) == 0){
            if(strcmp(attr[index+1],MMI_RP_MGR_VAL_FALSE)==0){
                compression = MMI_FALSE;
            }
        }
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }

        index += 2;
    }

    if(curr_img_id != NULL)
    {
        if(!mmi_rp_hash_find(g_mmi_rp_img_cntx.id_hash, curr_img_id))
        {
            MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].img_id_str = mmi_rp_hash_add(g_mmi_rp_img_cntx.id_hash, curr_img_id);

            if (curr_img_desc != NULL)
            {
                MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].img_desc_str = (U8*)malloc(strlen(curr_img_desc)+1);
                strcpy(MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].img_desc_str, curr_img_desc);
            }

            if (curr_img_format != NULL)
            {
                MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].format = (U8*)malloc(strlen(curr_img_format)+1);
                strcpy(MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].format, curr_img_format);
            }

            for (i = 0; i < MMI_RP_IMG_SIZE_LIMIT_TOTAL; i++)
            {
                if (size_limit[i] != NULL)
                {
                    MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].size_limit[i] = (U8*)malloc(strlen(size_limit[i])+1);
                    strcpy(MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].size_limit[i], size_limit[i]);
                }
                else
                {
                    MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].size_limit[i] = NULL;
                }
            }

            if (curr_img_9slice != NULL)
            {
                MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].img_9slice = (U8*)malloc(strlen(curr_img_9slice)+1);
                strcpy(MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].img_9slice, curr_img_9slice);
            }

            MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].is_theme = g_mmi_rp_is_theme;
            MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].scope = curr_scope;
            MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].flag = curr_bin;
            MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].force_type = curr_force_type;
            MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].quality = curr_quality;
            MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].is_compression = compression;
            MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].toggle = MMI_RP_IMG_ENFB_TOGGLE_NONE;

            if(curr_force_type == MMI_RP_IMG_FORCE_TYPE_NONE)
            {
                MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].poulate_type = MMI_RP_IMG_POPULATE_TYPE_IMG;
            }
            else
            {
                MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].poulate_type = MMI_RP_IMG_POPULATE_TYPE_FORCE_IMG;
            }

            /* Add the new image id to group */
            if(group_str != NULL)
            {
                mmi_rp_img_add_img_to_groups(group_str, MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].img_id_str);
            }

            MMI_RP_IMG_CURR_APP_IMG.total_count++;

        }
        else
        {
            MMI_RP_PARSE_WARNING(RP_WARN_DUPLICATE_ID);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
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
*  mmi_rp_img_end_handler
* DESCRIPTION
*  This function is for XML parser to return end tag information to application
* PARAMETERS
*  data        [IN]        Reserved
*  el          [IN]        Element name
*  error       [IN]        Error code
* RETURNS
*  void
*****************************************************************************/
int mmi_rp_img_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Image-end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_img_data_handler
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
int mmi_rp_img_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp[MMI_RP_MGR_MAX_FILE_NAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Image-data: %s\n", data);

    if(data != NULL)
    {
        memset(temp, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);

        if((strlen(g_mmi_rp_mgr_cntx.path.def_img_path) + strlen(data)) < MMI_RP_MGR_MAX_FILE_NAME_LEN)
        {
            mmi_rp_mgr_path_create(temp, g_mmi_rp_mgr_cntx.path.def_img_path, (U8*)data);
        }
        else
        {
            MMI_RP_PARSE_WARNING_DATA(RP_WARN_BUFFER_LENGTH_EXCEEDED, data);
        }

        /* Adding at total_count - 1 index as the total_count has already been increased in start tag handler */
        MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count - 1].file_path = mmi_rp_hash_add(g_mmi_rp_img_cntx.file_path_hash, temp);
    }
    return MMI_RP_PARSE_OK;
}







U8 g_mi_curr_scope[MMI_RP_MGR_MAX_FILE_NAME_LEN];
U8 g_mi_curr_img_id_start[MMI_RP_MGR_MAX_FILE_NAME_LEN + 1];    // Use and extra char '_' as a delim
U8 g_mi_curr_img_id_end[MMI_RP_MGR_MAX_FILE_NAME_LEN];
U8 g_mi_curr_bin[MMI_RP_MGR_MAX_FILE_NAME_LEN];
U8 g_mi_curr_force_type[MMI_RP_MGR_MAX_FILE_NAME_LEN];
U8 g_mi_curr_path[MMI_RP_MGR_MAX_FILE_NAME_LEN];
S32 g_mi_max_id_count = 0;


/*****************************************************************************
* FUNCTION
*  mmi_rp_multi_img_start_handler
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
int mmi_rp_multi_img_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    S32 parent_tag_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Init Data */
    g_mi_curr_scope[0] = '\0';
    g_mi_curr_img_id_start[0] = '\0';
    g_mi_curr_img_id_end[0] = '\0';
    g_mi_curr_bin[0] = '\0';
    g_mi_curr_force_type[0] = '\0';
    g_mi_curr_path[0] = '\0';
    g_mi_max_id_count = '\0';

    MMI_RP_DEBUG_INFO("Multi-Image-start: %s\n", el);

    /* Checking correct order of tags */
    if((strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0) &&
        (strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_ENFB) != 0))
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /* String ID exceeded the app_range - 1 (BASE_ID is reserved for Mainmenu app) */
    if(MMI_RP_IMG_CURR_APP_IMG.total_count >= (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID_START) == 0)
        {
            if(strlen(attr[index + 1]) > MMI_RP_MGR_MAX_FILE_NAME_LEN)
            {
                MMI_RP_ERROR_DATA(RP_ERR_BUFFER_LENGTH_EXCEEDED, attr[index + 1]);
                return MMI_RP_PARSE_ERROR_SKIP_TAG;
            }
            strcpy(g_mi_curr_img_id_start, (U8*)attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID_END) == 0)
        {
            strcpy(g_mi_curr_img_id_end, (U8*)attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID_COUNT) == 0)
        {
            g_mi_max_id_count = atoi(attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_SCOPE) == 0)
        {
            strcpy(g_mi_curr_scope, (U8*)attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_FLAG) == 0)
        {
            strcpy(g_mi_curr_bin, (U8*)attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_FORCE_TYPE) == 0)
        {
            strcpy(g_mi_curr_force_type, (U8*)attr[index + 1]);
        }
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        index += 2;
    }


    return MMI_RP_PARSE_OK;

}



/*****************************************************************************
* FUNCTION
*  mmi_rp_get_dos_path
* DESCRIPTION
*  Chagne \\\\ to \ from string
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_get_dos_path(U8 *dest, U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef RESXML_VC_DEBUG
    strcpy(dest, "..\\..\\");
    strcat(dest, string);
#else
    strcpy(dest, string);
#endif
    while ((temp = strstr(dest, "\\\\\\\\")) != NULL)
    {
        strcpy(temp, temp+3);
    }

    while ((temp = strchr(dest, '"')) != NULL)
    {
        strcpy(temp, temp+1);
    }

}

/*****************************************************************************
* FUNCTION
*  mmi_rp_multi_img_end_handler
* DESCRIPTION
*  This function is for XML parser to return end tag information to application
* PARAMETERS
*  data        [IN]        Reserved
*  el          [IN]        Element name
*  error       [IN]        Error code
* RETURNS
*  void
*****************************************************************************/
int mmi_rp_multi_img_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Multi-Image-end: %s\n", el);

    return MMI_RP_PARSE_OK;

}



/*****************************************************************************
* FUNCTION
*  mmi_rp_multi_img_data_handler
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
int mmi_rp_multi_img_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    U8 path_temp[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    WIN32_FIND_DATA file_data;
    HANDLE search = NULL;    
    BOOL fFinished = FALSE; 
    U8 *pdest;
    S32 result;
    S32 index;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Multi-Image-data: %s\n", data);
    if (data != NULL)
    {
        strcpy(g_mi_curr_path, data);
    }

    if(g_mi_curr_path[0] != '\0')
    {
        memset(temp, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
        memset(path_temp, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);

        if((strlen(g_mmi_rp_mgr_cntx.path.def_img_path) + strlen(g_mi_curr_path)) < MMI_RP_MGR_MAX_FILE_NAME_LEN)
        {
            mmi_rp_mgr_path_create(temp, g_mmi_rp_mgr_cntx.path.def_img_path, (U8*)g_mi_curr_path);
        }
        else
        {
            MMI_RP_PARSE_WARNING_DATA(RP_WARN_BUFFER_LENGTH_EXCEEDED, g_mi_curr_path);
        }

        mmi_rp_get_dos_path(path_temp, temp);
        /* find all files and parse them. */
        search = FindFirstFile(path_temp, &file_data);  
        if (search == INVALID_HANDLE_VALUE)
        {
            printf("Didn't find any image file start_id=[%s] ret=[%d]\n", g_mi_curr_img_id_start, GetLastError());
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        else
        {
            index = 1;
            printf("FindFirstFile image=[%s]\n", file_data.cFileName);
        }    

        for (index=1; index<=g_mi_max_id_count; index++)
        {
            U8 attr[10][MMI_RP_MGR_MAX_FILE_NAME_LEN];
            U8 *attr_p[10];
            S32 attr_idx = 0;

            /* construct every image path */
            memset(path_temp, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);

            /* construct every attribut */
            memset(attr, 0, 10*MMI_RP_MGR_MAX_FILE_NAME_LEN);
            strcpy(attr[attr_idx], MMI_RP_MGR_ATTR_ID);
            attr_idx++;

            if (index == 1)
            {
                strcpy(attr[attr_idx], g_mi_curr_img_id_start);
            }
            else if(index == g_mi_max_id_count)
            {
                strcpy(attr[attr_idx], g_mi_curr_img_id_end);
            }
            else
            {
                strcpy(attr[attr_idx], g_mi_curr_img_id_start);
                strcat(attr[attr_idx], "_");
                itoa(index, (char*)(strrchr(attr[attr_idx], '_')+1), 10);
            }
            attr_idx++;


            if (!fFinished)
            {
                pdest = strrchr(temp, '\\');
                result = pdest - temp + 1;
                strncpy(path_temp, temp, result);
                strcat(path_temp, file_data.cFileName);
                strcat(path_temp, "\"");

                if (g_mi_curr_scope[0] != '\0')
                {
                    strcpy(attr[attr_idx], MMI_RP_MGR_ATTR_SCOPE);
                    attr_idx++;
                    strcpy(attr[attr_idx], g_mi_curr_scope);
                    attr_idx++;
                }

                if (g_mi_curr_bin[0] != '\0')
                {
                    strcpy(attr[attr_idx], MMI_RP_MGR_ATTR_FLAG);
                    attr_idx++;
                    strcpy(attr[attr_idx], g_mi_curr_bin);
                    attr_idx++;
                }

                if (g_mi_curr_force_type[0] != '\0')
                {
                    strcpy(attr[attr_idx], MMI_RP_MGR_ATTR_FORCE_TYPE);
                    attr_idx++;
                    strcpy(attr[attr_idx], g_mi_curr_force_type);
                    attr_idx++;
                }
            }
            else
            {
                strcpy(path_temp, MMI_RP_IMG_EMPTYIMAGE_PATH);
            }

            for (i=0;i<10;i++)
            {
                if(attr[i][0] != '\0')
                {
                    attr_p[i] = &(attr[i][0]);
                }
                else
                {
                    attr_p[i] = NULL;
                }
            }

            /* If count > 0, then need to populate current found image */
            mmi_rp_img_start_handler(NULL, MMI_RP_MGR_TAG_IMAGE, (U8**)&attr_p);
            mmi_rp_img_data_handler(NULL, MMI_RP_MGR_TAG_IMAGE, path_temp, strlen(path_temp));
            mmi_rp_img_end_handler(NULL, MMI_RP_MGR_TAG_IMAGE);

            if (!fFinished)
            {
                if (!FindNextFile(search, &file_data)) 
                {
                    printf("No more image files. Search completed.\n");
                    fFinished = TRUE; 
                }
                else
                {
                    printf("FindNextFile image=[%s]\n", file_data.cFileName);
                }
            }
        } 

        /* Close the search handle. */
        if (!FindClose(search)) 
        {
            MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_PARSE_ERROR, "Couldn't close search handle.");
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
    }

    return MMI_RP_PARSE_OK;
}













/*****************************************************************************
* FUNCTION
*  mmi_rp_med_start_handler
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
int mmi_rp_med_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    mmi_rp_scope_enum curr_scope = MMI_RP_SCOPE_NONE;
    U8 *curr_img_id = NULL, *group_str = NULL;
    mmi_rp_flag_bin_enum curr_bin = MMI_RP_FLAG_SINGLE_BIN;
    S32 parent_tag_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Media-start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /* String ID exceeded the app_range - 1 (BASE_ID is reserved for Mainmenu app) */
    if(MMI_RP_IMG_CURR_APP_IMG.total_count >= (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID) == 0)
        {
            curr_img_id = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_SCOPE) == 0)      /* Not used with Media resources. For future use only. */
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
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_FLAG) == 0)
        {
            if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_MULTIBIN) == 0 || (strcmp(attr[index + 1], MMI_RP_MGR_VAL_REPLACEABLE) ==0))
            {
                curr_bin = MMI_RP_FLAG_MULTI_BIN;
            }
            else /* Default for scope. */
            {
                curr_bin = MMI_RP_FLAG_SINGLE_BIN;
            }                 
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_GROUP) == 0)
        {
            group_str = (U8*)attr[index + 1];
        }
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }

        index += 2;
    }

    if(curr_img_id != NULL)
    {
        if(!mmi_rp_hash_find(g_mmi_rp_img_cntx.id_hash, curr_img_id))
        {
            MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].img_id_str = mmi_rp_hash_add(g_mmi_rp_img_cntx.id_hash, curr_img_id);
            MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].scope = curr_scope;
            MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].flag = curr_bin;
            MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].poulate_type = MMI_RP_IMG_POPULATE_TYPE_MED;

            /* Add the new media id to group */
            if(group_str != NULL)
            {
                mmi_rp_img_add_img_to_groups(group_str, MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count].img_id_str);
            }

            MMI_RP_IMG_CURR_APP_IMG.total_count++;

        }
        else
        {
            MMI_RP_PARSE_WARNING(RP_WARN_DUPLICATE_ID);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
    }
    else
    {
        MMI_RP_PARSE_WARNING(RP_WARN_RES_ID_NULL);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_med_end_handler
* DESCRIPTION
*  This function is for XML parser to return end tag information to application
* PARAMETERS
*  data        [IN]        Reserved
*  el          [IN]        Element name
*  error       [IN]        Error code
* RETURNS
*  void
*****************************************************************************/
int mmi_rp_med_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Media-end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_med_data_handler
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
int mmi_rp_med_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp[MMI_RP_MGR_MAX_FILE_NAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Media-data: %s\n", data);

    if(data != NULL)
    {
        memset(temp, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
        if((strlen(g_mmi_rp_mgr_cntx.path.def_img_path) + strlen(data)) < MMI_RP_MGR_MAX_FILE_NAME_LEN)
        {
            mmi_rp_mgr_path_create(temp, g_mmi_rp_mgr_cntx.path.def_img_path, (U8*)data);
        }
        else
        {
            MMI_RP_PARSE_WARNING_DATA(RP_WARN_BUFFER_LENGTH_EXCEEDED, data);
        }

        /* Adding at total_count - 1 index as the total_count has already been increased in start tag handler */
        MMI_RP_IMG_CURR_APP_IMG.images[MMI_RP_IMG_CURR_APP_IMG.total_count - 1].file_path = mmi_rp_hash_add(g_mmi_rp_img_cntx.file_path_hash, temp);
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_enfb_start_handler
* DESCRIPTION
*  This function will use toggle approach to use the SetENFBAssociatedID() and 
*  ResetENFBAssociatedID() APIs. The toggle list will contain the image IDs when  
*  to use one of the above mentioned APIs.
* PARAMETERS
*  data        [IN]        Reserved
*  el          [IN]        Element name
*  attr        [IN]        Attribute list
*  error       [IN]        Error code
* RETURNS
*  void
*****************************************************************************/
int mmi_rp_enfb_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    S32 parent_tag_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("ENFB-start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /* Toggles exceeded the app_range - 1 (BASE_ID is reserved for Mainmenu app) */
    if(MMI_RP_IMG_CURR_APP_IMG.total_count >= (2 * (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min)))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /* If set twice, exit resgen. */
    if(MMI_RP_IMG_CURR_APP_IMG.last_toggle == MMI_RP_IMG_ENFB_TOGGLE_SET)
    {
        MMI_RP_ERROR(RP_ERR_TAG_ENFB_OPEN_TWICE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        /* Currently, ENFB tag doesn't require any attribute. */
        MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;

        index += 2;
    }

    MMI_RP_IMG_CURR_APP_IMG.toggle_index[MMI_RP_IMG_CURR_APP_IMG.toggle_count] = MMI_RP_IMG_CURR_APP_IMG.total_count;
    MMI_RP_IMG_CURR_APP_IMG.toggle_count++;
    MMI_RP_IMG_CURR_APP_IMG.last_toggle = MMI_RP_IMG_ENFB_TOGGLE_SET;
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_enfb_end_handler
* DESCRIPTION
*  This function will use toggle approach to use the SetENFBAssociatedID() and 
*  ResetENFBAssociatedID() APIs. The toggle list will contain the image IDs when  
*  to use one of the above mentioned APIs.
* PARAMETERS
*  data        [IN]        Reserved
*  el          [IN]        Element name
*  error       [IN]        Error code
* RETURNS
*  void
*****************************************************************************/
int mmi_rp_enfb_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("ENFB-end: %s\n", el);

    /* Toggles exceeded the app_range - 1 (BASE_ID is reserved for Mainmenu app) */
    if(MMI_RP_IMG_CURR_APP_IMG.total_count >= (2 * (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min)))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /* If reset twice, exit resgen. */
    if(MMI_RP_IMG_CURR_APP_IMG.last_toggle == MMI_RP_IMG_ENFB_TOGGLE_RESET)
    {
        MMI_RP_ERROR(RP_ERR_TAG_ENFB_CLOSE_TWICE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    MMI_RP_IMG_CURR_APP_IMG.toggle_index[MMI_RP_IMG_CURR_APP_IMG.toggle_count] = MMI_RP_IMG_CURR_APP_IMG.total_count;
    MMI_RP_IMG_CURR_APP_IMG.toggle_count++;
    MMI_RP_IMG_CURR_APP_IMG.last_toggle = MMI_RP_IMG_ENFB_TOGGLE_RESET;
    return MMI_RP_PARSE_OK;
}


void mmi_rp_binary3d_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
}

void mmi_rp_binary3d_end_handler(void *data, const kal_char *el)
{
}

void mmi_rp_binary3d_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
}



/*****************************************************************************
* FUNCTION
*  mmi_rp_img_add_img_to_groups
* DESCRIPTION
*  This function is add a image res to a group
* PARAMETERS
*  groups          [IN]        Group name
*  img_id          [IN]        Asscoiated image IDs
* RETURNS
*  Success or failed
*****************************************************************************/
MMI_BOOL mmi_rp_img_add_img_to_groups(U8 *groups, U8 *img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 gcount = g_mmi_rp_img_cntx.group_data.group_count;
    U8 *temp1 = NULL, *temp2 = NULL;
    U8 temp[MMI_RP_IMG_GROUP_ID_MAX];
    U32 len = 0, i = 0;
    MMI_BOOL process_next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(gcount >= MMI_RP_IMG_GROUP_ID_MAX)
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_FALSE;
    }

    if(groups == NULL)
    {
        MMI_RP_PARSE_WARNING(RP_WARN_GROUP_NAME_NOT_FOUND);
        return MMI_FALSE;
    }

    temp1 = groups;

    process_next  = MMI_TRUE;
    do
    {
        temp2 = strchr(temp1, ',');
        if(temp2)
        {
            len = (U32)(temp2 - temp1);

            if(len != 0)                 
            {
                strncpy(temp, temp1, len);
                temp[len] = 0;
                temp1 = temp2 + 1;
                temp2 = NULL;
            }
            else
            {
                temp1++;
                temp2 = NULL;
                continue;           /* To remove consecutive ','.*/
            }
        }
        else
        {
            len = strlen(temp1);
            strncpy(temp, temp1, len);
            temp[len] = 0;
            process_next  = MMI_FALSE;
        }

        if(mmi_rp_hash_find(g_mmi_rp_img_cntx.hash_others, temp))      /* Add in the existing group. */
        {
            for(i = 0; i < gcount; i++)
            {
                if(strcmp(g_mmi_rp_img_cntx.group_data.groups[i].group_name, temp) == 0)
                {
                    if(g_mmi_rp_img_cntx.group_data.groups[i].img_count < MMI_RP_IMG_GROUP_IMG_MAX)
                    {
                        g_mmi_rp_img_cntx.group_data.groups[i].img_ids[g_mmi_rp_img_cntx.group_data.groups[i].img_count] = img_id;
                        g_mmi_rp_img_cntx.group_data.groups[i].img_count++;
                        break;
                    }
                    else
                    {
                        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
                        return MMI_FALSE;
                    }
                }
            }

            if(i == gcount)
            {
                MMI_RP_PARSE_WARNING(RP_WARN_GROUP_NAME_NOT_FOUND);
                return MMI_FALSE;
            }
        }
        else    /* Add a new group */
        {
            if(gcount == MMI_RP_IMG_GROUP_ID_MAX - 1)
            {        
                MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
                return MMI_FALSE;
            }

            g_mmi_rp_img_cntx.group_data.groups[gcount].group_name = mmi_rp_hash_add(g_mmi_rp_img_cntx.hash_others, temp);
            g_mmi_rp_img_cntx.group_data.groups[gcount].img_ids[g_mmi_rp_img_cntx.group_data.groups[gcount].img_count] = img_id;
            g_mmi_rp_img_cntx.group_data.groups[gcount].img_count++;
            g_mmi_rp_img_cntx.group_data.group_count++;
            gcount = g_mmi_rp_img_cntx.group_data.group_count;
        }
    }while(process_next == MMI_TRUE);

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_img_find_img_id
* DESCRIPTION
*  Search numerical id for a image id enum str
* PARAMETERS
*  temp          [IN]        temp pointer to menuitem string data for elements
* RETURNS
*  Numerical menu ID
*****************************************************************************/
MMI_BOOL mmi_rp_img_find_img_id(U8* str_img_id, U16* img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0, curr_valid_id = 0;
    mmi_rp_img_data_struct *curr_app_img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        curr_app_img = &(g_mmi_rp_img_cntx.app_img_data[i]);

        curr_valid_id = g_mmi_resource_base_table[i].min + 1; /* BASE_ID + 1 */
        for(j = 0; j < curr_app_img->total_count; j++)
        {
            if(curr_app_img->images[j].filter == MMI_TRUE)
            {
                if(strcmp(str_img_id, curr_app_img->images[j].img_id_str) == 0)
                {
                    *img_id = curr_valid_id;
                    return MMI_TRUE;
                }
                curr_valid_id++;
            }
            else if(strcmp(str_img_id, curr_app_img->images[j].img_id_str) == 0)    /* Fasten up. If image id is filtered-out. return FALSE. */
            {
                return MMI_FALSE;
            }
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_img_filter
* DESCRIPTION
*  This function is for resgen to filter image resource.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_img_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0, k =0, app_c = 0, img_c = 0;
    U8 *search_id = NULL, *cand_id = NULL;
    MMI_BOOL found = MMI_FALSE;
    mmi_rp_img_data_struct *curr_app_img1 = NULL;
    mmi_rp_menu_data_struct *curr_menu_img2= NULL;
    U16 temp_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(app_c = 0; app_c < g_mmi_rp_mgr_cntx.total_apps; app_c++)
    {
        curr_app_img1 = &(g_mmi_rp_img_cntx.app_img_data[app_c]);

        for(img_c =0; img_c < curr_app_img1->total_count; img_c++)
        {
            if(curr_app_img1->images[img_c].scope != MMI_RP_SCOPE_XML)
            {
                curr_app_img1->images[img_c].filter = MMI_TRUE;
                continue;
            }

            search_id = curr_app_img1->images[img_c].img_id_str;
            found = MMI_FALSE;

            for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
            {
                curr_menu_img2 = &(g_mmi_rp_menu_cntx.app_menu_data[i]);
                for(j =0; j < curr_menu_img2->total_count; j++)
                {
                    cand_id = curr_menu_img2->menus[j].xml_data.img_id_str;

                    if((cand_id == NULL) || (curr_menu_img2->menus[j].filter == MMI_FALSE))
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

            /* If still not found as an image for menu IDs, find it in images for main menu items. */
            if(!found)
            {
                for(i = 0; i < (U32)g_mmi_rp_menu_cntx.main_menu_ids.main_menu_total; i++)
                {
                    /* To check whether the main menu ID is filtered-in. Because, mainmenuID array is checked in Men uoutput phase 2. */
                    if(mmi_rp_menu_find_menu_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data->id_str, &temp_menu_id))
                    {
                        if(strcmp(search_id, g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data->mm_list_img_str) == 0)    
                        {
                            found = MMI_TRUE;
                            break;
                        }
                        if(strcmp(search_id, g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data->mm_matrix_img_str) == 0)    
                        {
                            found = MMI_TRUE;
                            break;
                        }
                        if(strcmp(search_id, g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data->mm_page_img_str) == 0)    
                        {
                            found = MMI_TRUE;
                            break;
                        }
                        if(strcmp(search_id, g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data->mm_venus1_img_str) == 0)    
                        {
                            found = MMI_TRUE;
                            break;
                        }
                        if(strcmp(search_id, g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data->mm_venus2_img_str) == 0)    
                        {
                            found = MMI_TRUE;
                            break;
                        }
                    }
                }
            }

            curr_app_img1->images[img_c].filter = found;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_img_output_phase1
* DESCRIPTION
*  Output ID
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_img_output_phase1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    U8 *str_output_filename = NULL, *str_header_guard = NULL;
    U8 str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    U8 temp_group_name[MMI_RP_IMG_GROUP_ID_MAX];


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
        str_header_guard = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_HEADER_GUARD, g_mmi_resource_base_table[i].appname);

        /* Menu resource module has already written the header and header guard. */ 
        /* Open the file in append mode */
        if(p_file = fopen(str_output_filename, "a"))
        {
            mmi_rp_img_output_phase1_app_def_h_file(i, p_file);
            mmi_rp_output_phase1_finish(p_file, str_header_guard);          /* Writes header guard finish */
            fclose(p_file);
        }
        else
        {
            /* Error writing output file. Exit. */
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
        }
    }

    /* 2. Output customer\CustInc\mmi_rp_img_misc_def.h file. */
    memset(str_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_filename, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    strcat(str_filename, "mmi_rp_img_misc_def.h");

    if(p_file = fopen(str_filename, "w"))            /* Rest resources will open the file in append mode */
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
            p_file, 
            "mmi_rp_img_misc_def.h", 
            "Resource populate function generated by XML resgen", 
            "MTK resgenerator XML parser");
        fprintf(p_file, "#ifndef _MMI_RP_IMG_MISC_DEF_H\n#define _MMI_RP_IMG_MISC_DEF_H\n");

        /* 2.a Output Group Id enum & extern decl for Group ID array for all applications */
        fprintf(p_file, "\n");

        fprintf(p_file, "/* Image Group ID enum */\n");

        fprintf(p_file, "typedef enum\n");
        fprintf(p_file, "{\n");
        for(i = 0; i < g_mmi_rp_img_cntx.group_data.group_count; i++)
        {
            for(j = 0; j < strlen(g_mmi_rp_img_cntx.group_data.groups[i].group_name); j++)
            {
                temp_group_name[j] = toupper(g_mmi_rp_img_cntx.group_data.groups[i].group_name[j]);
            }
            temp_group_name[j] = '\0';

            fprintf(p_file, "   MMI_RG_IMG_%s,\n", temp_group_name);     /* Perfixing with MMI_RP_IMG_ for distinct names. */
        }
        fprintf(p_file, "   MMI_RG_IMG_GROUP_ID_MAX,\n");
        fprintf(p_file, "}mmi_rg_img_group_id_enum;\n");

        /* 2.b extern decl of group ID array */
        fprintf(p_file, "\n");
        fprintf(p_file, "/* Extern declaration for arrays of image IDs, which are associated with group IDs */\n");
        for(i = 0; i < g_mmi_rp_img_cntx.group_data.group_count; i++)
        {
            for(j = 0; j < strlen(g_mmi_rp_img_cntx.group_data.groups[i].group_name); j++)
            {
                temp_group_name[j] = tolower(g_mmi_rp_img_cntx.group_data.groups[i].group_name[j]);
            }
            temp_group_name[j] = '\0';

            fprintf(p_file, "extern const U16 %s[];\n", temp_group_name);
        }

        /* 2.c Other externs. */
        fprintf(p_file, "\n\n/* Extern declaration for Image group array associated with Group ID enum */\n");
        fprintf(p_file, "extern const U16* mmi_rg_img_group[];\n\n");


        fprintf(p_file, "#endif /* _MMI_RP_IMG_MISC_DEF_H */\n");
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
*  mmi_rp_img_output_phase1_app_def_h_file
* DESCRIPTION
*  Output Resources
* PARAMETERS
*  app_index      [IN]    App_index in resource base table
*  p_file      [IN]    File pointer to output file
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_img_output_phase1_app_def_h_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0;
    U8 str_enum_name[MMI_RP_OUTPUT_ENUM_NAME_MAX], str_enum_max[MMI_RP_OUTPUT_ENUM_NAME_MAX];
    MMI_BOOL first = MMI_TRUE;
    mmi_rp_img_data_struct *curr_app_img = &(g_mmi_rp_img_cntx.app_img_data[app_index]);
    S32 app_enum_log_counter = -1;      /* -1 for debug purpose */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        memset(str_enum_name, 0, sizeof(str_enum_name));
        strcpy(str_enum_name, "mmi_rp_");
        strcat(str_enum_name, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_name, "_img_enum");
        for(i = 0; i < strlen(str_enum_name); i++)
        {
            str_enum_name[i] = tolower(str_enum_name[i]);
        }

        memset(str_enum_max, 0, sizeof(str_enum_max));
        strcpy(str_enum_max, "MMI_RP_");
        strcat(str_enum_max, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_max, "_IMG_MAX");
        for(i = 0; i < strlen(str_enum_max); i++)
        {
            str_enum_max[i] = toupper(str_enum_max[i]);
        }

        /* Check if no img IDs. */
        if(curr_app_img->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            fprintf(p_file, "\n\n");
            fprintf(p_file, "/******************** Image resource IDs - begin ********************/\n");
            fprintf(p_file, "typedef enum\n{\n");

            for(i = 0; i < curr_app_img->total_count; i++)
            {
                if(curr_app_img->images[i].filter == MMI_FALSE)
                {
                    continue;
                }

                if(first)
                {
                    fprintf(p_file, "    %s = %d + 1, /* BASE_ID + 1 */\n", curr_app_img->images[i].img_id_str, g_mmi_resource_base_table[app_index].min);
                    first = MMI_FALSE;

                    app_enum_log_counter = g_mmi_resource_base_table[app_index].min + 1;
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_img->images[i].img_id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
                else
                {
                    fprintf(p_file, "    %s,\n", curr_app_img->images[i].img_id_str);
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_img->images[i].img_id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
            }

            fprintf(p_file, "    %s\n", str_enum_max);
            fprintf(p_file, "}%s;\n", str_enum_name);
            fprintf(p_file, "/******************** Image resource IDs - finish ********************/\n");
        }
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }
}

#ifndef __POPULATE_NO_IMAGE_DATA__
/*****************************************************************************
* FUNCTION
*  mmi_rp_img_output_phase2
* DESCRIPTION
*  Output Resources
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_img_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    U8 *str_output_filename = NULL;
    CHAR * str_output_filename_header =NULL;
    U8 str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    U8 temp_group_name[MMI_RP_IMG_GROUP_ID_MAX];
    U16 img_id = 0;
    MMI_BOOL need_comma;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. Output all APPs .c files. */

#ifdef __RESGEN_INTERNAL_OFFLINE__ 
    ImageAdaptorStartOfflinePopulation(DEFAULT_OFFLINE_XML_IMAGE_DB);
#endif //__RESGEN_INTERNAL_OFFLINE__

    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        {
            continue;
        }
#ifdef __RESGEN_INTERNAL_POP_FILE_REDUCE__
        mmi_rp_img_output_phase2_app_c_file(i);

#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
        str_output_filename = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_C_FILE_PATH, g_mmi_resource_base_table[i].appname);

        /* Menu resource module has already written the header and started the function. */ 
        /* Open the file in append mode */
        if(p_file = fopen(str_output_filename, "a"))            
        {
            mmi_rp_img_output_phase2_app_c_file(i, p_file);
            mmi_rp_output_phase2_finish(p_file);
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
    ImageAdaptorStopOfflinePopulation();
#endif //__RESGEN_INTERNAL_OFFLINE__

    /* 2. Output all customer\CustResource\mmi_rp_misc_data.c file. */
    memset(str_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_filename, MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES);
    strcat(str_filename, "mmi_rp_img_misc_data.c");

    if(p_file = fopen(str_filename, "w"))           
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(p_file, "mmi_rp_img_misc_data.c", "Resource populate function generated by XML resgen", "MTK resgenerator XML parser");
        fprintf(p_file, "#include \"MMIDataType.h\"\n");
        fprintf(p_file, "#include \"mmi_rp_img_misc_def.h\"\n");

        /* 2.a Output Group ID array for all applications */
        fprintf(p_file, "\n");

        fprintf(p_file, "/* Arrays of image IDs for Group IDs */\n");
        for(i = 0; i < g_mmi_rp_img_cntx.group_data.group_count; i++)
        {
            for(j = 0; j < strlen(g_mmi_rp_img_cntx.group_data.groups[i].group_name); j++)
            {
                temp_group_name[j] = tolower(g_mmi_rp_img_cntx.group_data.groups[i].group_name[j]);
            }
            temp_group_name[j] = '\0';

            if(g_mmi_rp_img_cntx.group_data.groups[i].img_count > 0)
            {
                fprintf(p_file, "const U16 %s[] = {", temp_group_name);

                need_comma = MMI_FALSE;

                for(j = 0; j < g_mmi_rp_img_cntx.group_data.groups[i].img_count; j++)
                {
                    if(mmi_rp_img_find_img_id(g_mmi_rp_img_cntx.group_data.groups[i].img_ids[j], &img_id))
                    {
                        if(need_comma)
                        {
                            fprintf(p_file, ", %d", img_id);
                        }
                        else
                        {
                            fprintf(p_file, "%d", img_id);
                        }
                        need_comma = MMI_TRUE;
                    }
                }
                if(!need_comma)
                {
                    fprintf(p_file, " -1 ");
                }
                fprintf(p_file, "};\n");
            }
        }

        /* 2.b mmi_rg_img_group[] array */
        fprintf(p_file, "\n/* Image group array associated with Group ID enum */\n");
        fprintf(p_file, "const U16 *mmi_rg_img_group[] = {\n");

        for(i = 0; i < g_mmi_rp_img_cntx.group_data.group_count; i++)
        {
            for(j = 0; j < strlen(g_mmi_rp_img_cntx.group_data.groups[i].group_name); j++)
            {
                temp_group_name[j] = tolower(g_mmi_rp_img_cntx.group_data.groups[i].group_name[j]);
            }
            temp_group_name[j] = '\0';

            fprintf(p_file, "    %s,\n", temp_group_name);
        }
        fprintf(p_file, "    NULL\n");
        fprintf(p_file, "};\n");

        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }


    /* 3. Output all debug\venus_theme_log.txt file. */
    memset(str_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_filename, MMI_RP_MGR_XML_VENUS_THEME_LOG);

    if(p_file = fopen(str_filename, "a"))           
    {
        mmi_rp_img_output_phase2_venus_theme(p_file);
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
*  mmi_rp_img_output_phase2_venus_theme
* DESCRIPTION
*  Output Resources
* PARAMETERS
*  p_file      [IN]    File pointer to output file
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_img_output_phase2_venus_theme(FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0, j = 0, h = 0;
    mmi_rp_img_data_struct *curr_app_img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fprintf(p_file, "[RP_IMAGE]\n");
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        curr_app_img = &(g_mmi_rp_img_cntx.app_img_data[i]);

        for(j = 0; j < curr_app_img->total_count; j++)
        {
            if (curr_app_img->images[j].is_theme)
            {
                fprintf(p_file, "%s\t%s\t%s\t%s", 
                    curr_app_img->images[j].img_id_str, 
                    curr_app_img->images[j].img_desc_str, 
                    curr_app_img->images[j].format, 
                    curr_app_img->images[j].img_9slice);

                for (h = 0; h < MMI_RP_IMG_SIZE_LIMIT_TOTAL; h++)
                {
                    fprintf(p_file, "\t%s", curr_app_img->images[j].size_limit[h]);
                }

                fprintf(p_file, "\n");
            }
        }
    }
}

#ifndef __RESGEN_INTERNAL_POP_FILE_REDUCE__

/*****************************************************************************
* FUNCTION
*  mmi_rp_img_output_phase2_app_c_file
* DESCRIPTION
*  Output Resources
* PARAMETERS
*  app_index      [IN]    App_index in resource base table
*  p_file      [IN]    File pointer to output file
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_img_output_phase2_app_c_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0, j = 0;
    U32 curr_toggle = 0;
    mmi_rp_img_data_struct *curr_app_img = &(g_mmi_rp_img_cntx.app_img_data[app_index]);
    mmi_rp_img_force_type_enum curr_force_type = MMI_RP_IMG_FORCE_TYPE_NONE;
    mmi_rp_img_enfb_toggle_enum last_toggle = MMI_RP_IMG_ENFB_TOGGLE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        /* Check if no img IDs. */
        if(curr_app_img->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            fprintf(p_file, "\n");
            fprintf(p_file, "/******************** Image resource IDs - begin ********************/\n");

            /* 1. Add img items */
            for(i = 0; i < curr_app_img->total_count; i++)
            {
                curr_force_type = MMI_RP_IMG_FORCE_TYPE_NONE;

                /* Print SetENFBAssociatedID() or ResetENFBAssociatedID() */
                if(curr_toggle > curr_app_img->toggle_count)
                {
                    MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
                    break;
                }

                if(i == (U32)(curr_app_img->toggle_index[curr_toggle]))
                {
                    if(last_toggle == MMI_RP_IMG_ENFB_TOGGLE_RESET || last_toggle == MMI_RP_IMG_ENFB_TOGGLE_NONE)
                    {
                        fprintf(p_file, "\n");
                        fprintf(p_file, "#ifdef __MMI_RESOURCE_ENFB_SUPPORT__\n");
                        fprintf(p_file, "    SetENFBAssociatedID();\n");
                        fprintf(p_file, "#endif\n");
                        last_toggle = MMI_RP_IMG_ENFB_TOGGLE_SET;
                    }
                    else
                    {
                        fprintf(p_file, "#ifdef __MMI_RESOURCE_ENFB_SUPPORT__\n");
                        fprintf(p_file, "    ResetENFBAssociatedID();\n");
                        fprintf(p_file, "#endif\n");
                        fprintf(p_file, "\n");
                        last_toggle = MMI_RP_IMG_ENFB_TOGGLE_RESET;
                    }

                    curr_toggle++;
                    i--;                /* No ID wa populated. Only printed ENFB APIs. */
                    continue;
                }

                if(curr_app_img->images[i].filter == MMI_TRUE && curr_app_img->images[i].file_path != NULL)
                {
                    if(curr_app_img->images[i].poulate_type == MMI_RP_IMG_POPULATE_TYPE_IMG)
                    {
                        if(curr_app_img->images[i].flag == MMI_RP_FLAG_MULTI_BIN)
                        {

                            fprintf(p_file, "    ADD_APPLICATION_IMAGE3(%s, %s, \"%s\");\n", 
                                curr_app_img->images[i].img_id_str, 
                                (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                                "Generated by Resgen_XML");
                        }
                        else
                        {
                            fprintf(p_file, "    ADD_APPLICATION_IMAGE2(%s, %s, \"%s\");\n", 
                                curr_app_img->images[i].img_id_str, 
                                (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                                "Generated by Resgen_XML");
                        }
                    }                    
                    else if(curr_app_img->images[i].poulate_type == MMI_RP_IMG_POPULATE_TYPE_MED)
                    {
                        if(curr_app_img->images[i].flag == MMI_RP_FLAG_MULTI_BIN)
                        {

                            fprintf(p_file, "    ADD_APPLICATION_MEDIA3(%s, %s, \"%s\");\n", 
                                curr_app_img->images[i].img_id_str, 
                                (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                                "Generated by Resgen_XML");
                        }
                        else
                        {
                            fprintf(p_file, "    ADD_APPLICATION_MEDIA2(%s, %s, \"%s\");\n", 
                                curr_app_img->images[i].img_id_str, 
                                (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                                "Generated by Resgen_XML");
                        }
                    }
                    else /* FORCE_TYPE images */
                    {
                        curr_force_type = curr_app_img->images[i].force_type;

                        if(curr_app_img->images[i].flag == MMI_RP_FLAG_MULTI_BIN)
                        {
                            fprintf(p_file, "    ADD_APPLICATION_IMAGE_TYPE(%s, %s, \"%s\", %s, %s);\n", 
                                curr_app_img->images[i].img_id_str, 
                                (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                                "Generated by Resgen_XML",
                                "TRUE",
                                g_mmi_rp_img_force_type_enum_str[curr_force_type]);
                        }
                        else
                        {
                            fprintf(p_file, "    ADD_APPLICATION_IMAGE_TYPE(%s, %s, \"%s\", %s, %s);\n", 
                                curr_app_img->images[i].img_id_str, 
                                (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                                "Generated by Resgen_XML",
                                "FALSE",
                                g_mmi_rp_img_force_type_enum_str[curr_force_type]);
                        }
                    }
                }
            }

            if(last_toggle == MMI_RP_IMG_ENFB_TOGGLE_SET)
            {
                fprintf(p_file, "#ifdef __MMI_RESOURCE_ENFB_SUPPORT__\n");
                fprintf(p_file, "    ResetENFBAssociatedID();\n");
                fprintf(p_file, "#endif\n");
                last_toggle = MMI_RP_IMG_ENFB_TOGGLE_RESET;
            }
            fprintf(p_file, "/******************** Image resource IDs - finish ********************/\n");
        }
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}

#elif defined(__RESGEN_INTERNAL_POP_FILE_REDUCE__) && defined(__RESGEN_INTERNAL_OFFLINE__)// __RESGEN_INTERNAL_POP_FILE_REDUCE__
void mmi_rp_img_output_phase2_app_c_file(U32 app_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0, j = 0;
    U32 curr_toggle = 0;
    mmi_rp_img_data_struct *curr_app_img = &(g_mmi_rp_img_cntx.app_img_data[app_index]);
    mmi_rp_img_force_type_enum curr_force_type = MMI_RP_IMG_FORCE_TYPE_NONE;
    mmi_rp_img_enfb_toggle_enum last_toggle = MMI_RP_IMG_ENFB_TOGGLE_NONE;

    U32 imageResourId = g_mmi_resource_base_table[app_index].min + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /* Check if no img IDs. */
    if(curr_app_img->total_count <= 0)
    {
        MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
    }
    else
    {

        /* 1. Add img items */
        for(i = 0; i < curr_app_img->total_count; i++)
        {
            curr_force_type = MMI_RP_IMG_FORCE_TYPE_NONE;

            /* Print SetENFBAssociatedID() or ResetENFBAssociatedID() */
            if(curr_toggle > curr_app_img->toggle_count)
            {
                MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
                break;
            }

            if(i == (U32)(curr_app_img->toggle_index[curr_toggle]))
            {
                if(last_toggle == MMI_RP_IMG_ENFB_TOGGLE_RESET || last_toggle == MMI_RP_IMG_ENFB_TOGGLE_NONE)
                {
                    // Set ENFB flag here
                    last_toggle = MMI_RP_IMG_ENFB_TOGGLE_SET;
                }
                else
                {
                    // Clear ENFB flag here
                    last_toggle = MMI_RP_IMG_ENFB_TOGGLE_RESET;
                }

                curr_toggle++;
                i--;                /* No ID wa populated. Only printed ENFB APIs. */
                continue;
            }

            if(curr_app_img->images[i].filter == MMI_FALSE){
                continue;
            }

            if(curr_app_img->images[i].file_path != NULL){


                if(curr_app_img->images[i].poulate_type == MMI_RP_IMG_POPULATE_TYPE_IMG)
                {
                    if(curr_app_img->images[i].flag == MMI_RP_FLAG_MULTI_BIN)
                    {
                        //printf( "    ADD_APPLICATION_IMAGE3(%s, %s, \"%s\");\n", 
                        //curr_app_img->images[i].img_id_str, 
                        //(curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                        //"Generated by Resgen_XML");
                        ImageAdaptorSetImageAutoIdWithQuality(
                            (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""),
                            ((g_mmi_resource_base_table[app_index].appname)?(g_mmi_resource_base_table[app_index].appname):("APP name unknown")),
                            "Generated by Resgen_XML",
                            curr_app_img->images[i].img_id_str,
                            ((g_mmi_rp_mgr_cntx.app_res_filepath[app_index])?(g_mmi_rp_mgr_cntx.app_res_filepath[app_index]):("Res path unknown")),
                            1,
                            OFFLINE_RESGEN_NO_FORCE_TYPE,1, 0,curr_app_img->images[i].quality, curr_app_img->images[i].is_compression);

                    }
                    else
                    {
                        //printf( "    ADD_APPLICATION_IMAGE2(%s, %s, \"%s\");\n", 
                        //curr_app_img->images[i].img_id_str, 
                        //(curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                        // "Generated by Resgen_XML");
                        ImageAdaptorSetImageAutoIdWithQuality(
                            (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""),
                            ((g_mmi_resource_base_table[app_index].appname)?(g_mmi_resource_base_table[app_index].appname):("APP name unknown")),
                            "Generated by Resgen_XML",
                            curr_app_img->images[i].img_id_str,
                            ((g_mmi_rp_mgr_cntx.app_res_filepath[app_index])?(g_mmi_rp_mgr_cntx.app_res_filepath[app_index]):("Res path unknown")),
                            1,
                            OFFLINE_RESGEN_NO_FORCE_TYPE, 0, 0,curr_app_img->images[i].quality, curr_app_img->images[i].is_compression);
                    }
                }                    
                else if(curr_app_img->images[i].poulate_type == MMI_RP_IMG_POPULATE_TYPE_MED)
                {
                    if(curr_app_img->images[i].flag == MMI_RP_FLAG_MULTI_BIN)
                    {

                        ImageAdaptorSetImageAutoIdWithQuality(
                            (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""),
                            ((g_mmi_resource_base_table[app_index].appname)?(g_mmi_resource_base_table[app_index].appname):("APP name unknown")),
                            "Generated by Resgen_XML",
                            curr_app_img->images[i].img_id_str,
                            ((g_mmi_rp_mgr_cntx.app_res_filepath[app_index])?(g_mmi_rp_mgr_cntx.app_res_filepath[app_index]):("Res path unknown")),
                            1, OFFLINE_RESGEN_NO_FORCE_TYPE,1, 0, curr_app_img->images[i].quality, curr_app_img->images[i].is_compression);
                    }
                    else
                    {
                        ImageAdaptorSetImageAutoIdWithQuality(
                            (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""),
                            ((g_mmi_resource_base_table[app_index].appname)?(g_mmi_resource_base_table[app_index].appname):("APP name unknown")),
                            "Generated by Resgen_XML",
                            curr_app_img->images[i].img_id_str,
                            ((g_mmi_rp_mgr_cntx.app_res_filepath[app_index])?(g_mmi_rp_mgr_cntx.app_res_filepath[app_index]):("Res path unknown")),
                            1, OFFLINE_RESGEN_NO_FORCE_TYPE, 0, 0, curr_app_img->images[i].quality, curr_app_img->images[i].is_compression);

                    }
                }
                else /* FORCE_TYPE images */
                {
                    curr_force_type = curr_app_img->images[i].force_type;

                    if(curr_app_img->images[i].flag == MMI_RP_FLAG_MULTI_BIN)
                    {

                        ImageAdaptorSetImageAutoIdWithQuality(
                            (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""),
                            ((g_mmi_resource_base_table[app_index].appname)?(g_mmi_resource_base_table[app_index].appname):("APP name unknown")),
                            "Generated by Resgen_XML",
                            curr_app_img->images[i].img_id_str,
                            ((g_mmi_rp_mgr_cntx.app_res_filepath[app_index])?(g_mmi_rp_mgr_cntx.app_res_filepath[app_index]):("Res path unknown")),
                            1,
                            MMI_IMAGE_TYPE_MAPPING[curr_force_type],1, 0, curr_app_img->images[i].quality, curr_app_img->images[i].is_compression);
                    }
                    else
                    {
                        ImageAdaptorSetImageAutoIdWithQuality(
                            (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""),
                            ((g_mmi_resource_base_table[app_index].appname)?(g_mmi_resource_base_table[app_index].appname):("APP name unknown")),
                            "Generated by Resgen_XML",
                            curr_app_img->images[i].img_id_str,
                            ((g_mmi_rp_mgr_cntx.app_res_filepath[app_index])?(g_mmi_rp_mgr_cntx.app_res_filepath[app_index]):("Res path unknown")),
                            1,
                            MMI_IMAGE_TYPE_MAPPING[curr_force_type],0, 0, curr_app_img->images[i].quality, curr_app_img->images[i].is_compression);

                    }
                }                



            }
            imageResourId++;
        }

        if(last_toggle == MMI_RP_IMG_ENFB_TOGGLE_SET)
        {
            // Reset ENFB Flag
            last_toggle = MMI_RP_IMG_ENFB_TOGGLE_RESET;
        }

    }
}
#else
void mmi_rp_img_output_phase2_app_c_file(U32 app_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0, j = 0;
    U32 curr_toggle = 0;
    mmi_rp_img_data_struct *curr_app_img = &(g_mmi_rp_img_cntx.app_img_data[app_index]);
    mmi_rp_img_force_type_enum curr_force_type = MMI_RP_IMG_FORCE_TYPE_NONE;
    mmi_rp_img_enfb_toggle_enum last_toggle = MMI_RP_IMG_ENFB_TOGGLE_NONE;
    FILE * p_file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /* Check if no img IDs. */
    if(curr_app_img->total_count <= 0)
    {
        MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
    }
    else
    {
        p_file = mmi_rp_open_population_c_file(app_index, RES_LEGACY_POP_IMAGE_MASK);

        if(p_file== NULL)            /* Rest resources will open the file in append mode */
        {
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
        }

        fprintf(p_file, "\n");
        fprintf(p_file, "/******************** Image resource IDs - begin ********************/\n");

        /* 1. Add img items */
        for(i = 0; i < curr_app_img->total_count; i++)
        {
            curr_force_type = MMI_RP_IMG_FORCE_TYPE_NONE;

            /* Print SetENFBAssociatedID() or ResetENFBAssociatedID() */
            if(curr_toggle > curr_app_img->toggle_count)
            {
                MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
                break;
            }

            if(i == (U32)(curr_app_img->toggle_index[curr_toggle]))
            {
                if(last_toggle == MMI_RP_IMG_ENFB_TOGGLE_RESET || last_toggle == MMI_RP_IMG_ENFB_TOGGLE_NONE)
                {
                    fprintf(p_file, "\n");
                    fprintf(p_file, "#ifdef __MMI_RESOURCE_ENFB_SUPPORT__\n");
                    fprintf(p_file, "    SetENFBAssociatedID();\n");
                    fprintf(p_file, "#endif\n");
                    last_toggle = MMI_RP_IMG_ENFB_TOGGLE_SET;
                }
                else
                {
                    fprintf(p_file, "#ifdef __MMI_RESOURCE_ENFB_SUPPORT__\n");
                    fprintf(p_file, "    ResetENFBAssociatedID();\n");
                    fprintf(p_file, "#endif\n");
                    fprintf(p_file, "\n");
                    last_toggle = MMI_RP_IMG_ENFB_TOGGLE_RESET;
                }

                curr_toggle++;
                i--;                /* No ID wa populated. Only printed ENFB APIs. */
                continue;
            }

            if(curr_app_img->images[i].filter == MMI_TRUE && curr_app_img->images[i].file_path != NULL)
            {
                if(curr_app_img->images[i].poulate_type == MMI_RP_IMG_POPULATE_TYPE_IMG)
                {
                    if(curr_app_img->images[i].flag == MMI_RP_FLAG_MULTI_BIN)
                    {

                        fprintf(p_file, "    ADD_APPLICATION_IMAGE3(%s, %s, \"%s\");\n", 
                            curr_app_img->images[i].img_id_str, 
                            (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                            "Generated by Resgen_XML");
                    }
                    else
                    {
                        fprintf(p_file, "    ADD_APPLICATION_IMAGE2(%s, %s, \"%s\");\n", 
                            curr_app_img->images[i].img_id_str, 
                            (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                            "Generated by Resgen_XML");
                    }
                }                    
                else if(curr_app_img->images[i].poulate_type == MMI_RP_IMG_POPULATE_TYPE_MED)
                {
                    if(curr_app_img->images[i].flag == MMI_RP_FLAG_MULTI_BIN)
                    {

                        fprintf(p_file, "    ADD_APPLICATION_MEDIA3(%s, %s, \"%s\");\n", 
                            curr_app_img->images[i].img_id_str, 
                            (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                            "Generated by Resgen_XML");
                    }
                    else
                    {
                        fprintf(p_file, "    ADD_APPLICATION_MEDIA2(%s, %s, \"%s\");\n", 
                            curr_app_img->images[i].img_id_str, 
                            (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                            "Generated by Resgen_XML");
                    }
                }
                else /* FORCE_TYPE images */
                {
                    curr_force_type = curr_app_img->images[i].force_type;

                    if(curr_app_img->images[i].flag == MMI_RP_FLAG_MULTI_BIN)
                    {
                        fprintf(p_file, "    ADD_APPLICATION_IMAGE_TYPE(%s, %s, \"%s\", %s, %s);\n", 
                            curr_app_img->images[i].img_id_str, 
                            (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                            "Generated by Resgen_XML",
                            "TRUE",
                            g_mmi_rp_img_force_type_enum_str[curr_force_type]);
                    }
                    else
                    {
                        fprintf(p_file, "    ADD_APPLICATION_IMAGE_TYPE(%s, %s, \"%s\", %s, %s);\n", 
                            curr_app_img->images[i].img_id_str, 
                            (curr_app_img->images[i].file_path ? (const S8*)curr_app_img->images[i].file_path : "\"\""), 
                            "Generated by Resgen_XML",
                            "FALSE",
                            g_mmi_rp_img_force_type_enum_str[curr_force_type]);
                    }
                }
            }
        }

        if(last_toggle == MMI_RP_IMG_ENFB_TOGGLE_SET)
        {
            fprintf(p_file, "#ifdef __MMI_RESOURCE_ENFB_SUPPORT__\n");
            fprintf(p_file, "    ResetENFBAssociatedID();\n");
            fprintf(p_file, "#endif\n");
            last_toggle = MMI_RP_IMG_ENFB_TOGGLE_RESET;
        }
        fprintf(p_file, "/******************** Image resource IDs - finish ********************/\n");
        fclose(p_file);
    }
}

#endif
#endif //__POPULATE_NO_IMAGE_DATA__
