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
 *  mmi_rp_audio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Plutommi Resource Generator Ver 2.0 (XML style) Audio handler
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
#include "mmi_rp_audio.h"
#include "mmi_rp_theme.h"

#include "mmi_res_range_def.h"

// Fredeirc: TBC
#include "CustDataProts.h"

#if defined(__MMI_FRM_INPUT_EVT__)
//xml
#define CUST_INPUT_EVENT_AUD_DST "..\\..\\..\\custom\\common\\nvram_input_event_aud_cfg.h"
#define MAX_INPUT_EVENT_AUD_LEN (20)
#define CUST_INPUT_EVENT_CFG_SRC_TMP "..\\..\\..\\custom\\common\\nvram_input_event_cfg.h.tmp"
#define CUST_INPUT_EVENT_CFG_SRC_DST "..\\..\\..\\custom\\common\\nvram_input_event_cfg.h"
#define CUST_INPUT_EVENT_CFG_INC_CONST_DST "..\\..\\..\\custom\\common\\nvram_input_event_const.h"

#define CUST_INPUT_EVENT_CFG_DESC_TMP "..\\..\\..\\custom\\common\\nvram_input_event_cfg_desc.tmp"
#define CUST_INPUT_EVENT_CFG_DESC "..\\..\\..\\custom\\common\\nvram_input_event_cfg_desc.txt"


U32 g_aud_file_path_num = 0;
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/

const U32 MMI_AUDIO_TYPE_MAPPING[3]=
{
    0xFF,
    AUTO_ADO_TYPE,
    FORCE_ADO_MIDI
};

void mmi_rp_aud_output_phase1_app_def_h_file(U32 app_index, FILE *p_file);
void mmi_rp_aud_output_phase2_venus_theme(FILE *p_file);

#if defined(__MMI_FRM_INPUT_EVT__)
static void mmi_rp_input_event_read_cfg_info_from_tmp(void);
void mmi_rp_aud_output_phase2_aud_file(FILE *p_file);
static void mmi_rp_input_event_read_desc_info_from_tmp(void);
static void mmi_rp_input_event_output_aud_desc_info(void);

#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/

#ifdef __RESGEN_INTERNAL_POP_FILE_REDUCE__
void mmi_rp_aud_output_phase2_app_c_file(U32 app_index);
#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
void mmi_rp_aud_output_phase2_app_c_file(U32 app_index, FILE *p_file);
#endif // __RESGEN_INTERNAL_POP_FILE_REDUCE__

extern const mmi_resource_base_struct g_mmi_resource_base_table[];

#define MMI_RP_AUD_CURR_APP_AUD       g_mmi_rp_aud_cntx.app_aud_data[g_mmi_rp_mgr_cntx.cur_app_index]

mmi_rp_aud_cntx_struct g_mmi_rp_aud_cntx;


/* These ENUM id strings will be used in ReadRes for audio force type */
/* These are defined in CustDataProts.h */
static U8 *g_mmi_rp_aud_force_type_enum_str[MMI_RP_AUD_FORCE_TYPE_TOTAL] = 
{
    "",
    MMI_RP_MGR_VAL_AUD_AUTO_ADO_TYPE,
    MMI_RP_MGR_VAL_AUD_FORCE_ADO_MIDI,
};


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_aud_init
 * DESCRIPTION
 *  Initializes the aud context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_aud_init(void)
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

    memset(&g_mmi_rp_aud_cntx, 0, sizeof(g_mmi_rp_aud_cntx));
    g_mmi_rp_aud_cntx.app_aud_data = (mmi_rp_aud_data_struct*)malloc(sizeof(mmi_rp_aud_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    if(!g_mmi_rp_aud_cntx.app_aud_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_aud_cntx.app_aud_data, 0, sizeof(mmi_rp_aud_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_aud_cntx.id_hash = mmi_rp_hash_create(0xFFFF);              /* 0xFFFF is the resource ID range */
    g_mmi_rp_aud_cntx.file_path_hash = mmi_rp_hash_create(0xFFFF);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_aud_deinit
 * DESCRIPTION
 *  DeInitializes the aud context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_aud_deinit(void)
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
 *  mmi_rp_aud_set_app_range
 * DESCRIPTION
 *  Initializes the aud context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_aud_set_app_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 range = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_RP_AUD_CURR_APP_AUD.audios == NULL)
    {
        range = g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min + 1;
        MMI_RP_AUD_CURR_APP_AUD.audios = (mmi_rp_aud_id_struct*)malloc(sizeof(mmi_rp_aud_id_struct) * range);

        if((!MMI_RP_AUD_CURR_APP_AUD.audios) && (range > 0))
        {
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }

        memset(MMI_RP_AUD_CURR_APP_AUD.audios, 0, sizeof(mmi_rp_aud_id_struct) * range);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_aud_start_handler
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
int mmi_rp_aud_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    mmi_rp_scope_enum curr_scope = MMI_RP_SCOPE_NONE;
    U8 *curr_aud_id = NULL;
    U8 *curr_aud_desc = NULL;
	U8 *curr_aud_path = NULL;
    U8 *curr_aud_format = NULL;
    mmi_rp_flag_bin_enum curr_bin = MMI_RP_FLAG_SINGLE_BIN;
    mmi_rp_aud_force_type_enum curr_force_type = MMI_RP_AUD_FORCE_TYPE_NONE;
    S32 parent_tag_id = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Audio-start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0 &&
       strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_THEME) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /* Audio ID exceeded the app_range - 1 (BASE_ID is reserved for Mainmenu app) */
    if(MMI_RP_AUD_CURR_APP_AUD.total_count >= (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID) == 0)
        {
            curr_aud_id = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_DESC) == 0)
        {
            curr_aud_desc = (U8*)attr[index + 1];
        }
#if defined(__MMI_FRM_INPUT_EVT__)		
		else if(strcmp(attr[index], MMI_RP_MGR_ATTR_AUD_PATH) == 0)
        {
            curr_aud_path = (U8*)attr[index + 1];
        }
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/		
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_FORMAT) == 0)
        {
            curr_aud_format = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_FLAG) == 0)
        {
            if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_MULTIBIN) == 0 || strcmp(attr[index + 1], MMI_RP_MGR_VAL_REPLACEABLE) ==0)
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
            if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_AUD_AUTO_ADO_TYPE) == 0)
            {
                curr_force_type = MMI_RP_AUD_FORCE_TYPE_AUTO;
            }
            else if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_AUD_FORCE_ADO_MIDI) == 0)
            {
                curr_force_type = MMI_RP_AUD_FORCE_TYPE_MIDI;
            }
            else /* Default for scope. */
            {
                curr_force_type = MMI_RP_AUD_FORCE_TYPE_NONE;
            }                 
        }
        else
        {
            MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        
        index += 2;
    }

    if(curr_aud_id != NULL)
    {
        if(!mmi_rp_hash_find(g_mmi_rp_aud_cntx.id_hash, curr_aud_id))
        {
            MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].aud_id_str = mmi_rp_hash_add(g_mmi_rp_aud_cntx.id_hash, curr_aud_id);
#if defined(__MMI_FRM_INPUT_EVT__)
			if (curr_aud_path != NULL)
            {
            	//length must be less than 20
            	if(strlen(curr_aud_path)<MAX_INPUT_EVENT_AUD_LEN)
            	{
                	MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].aud_path = (U8*)malloc(strlen(curr_aud_path)+1);
                	strcpy(MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].aud_path, curr_aud_path);
            	}
				else
				{
					//fprintf(stdout, "[Err]Audio %s path %s len is over %d\n",curr_aud_id,curr_aud_path, MAX_INPUT_EVENT_AUD_LEN);
					fprintf(stderr, "[Error]Audio %s path len is over %d\n",curr_aud_id, MAX_INPUT_EVENT_AUD_LEN);
					exit(0);
				}
            }
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/
			

            if (curr_aud_desc != NULL)
            {
            #if defined(__MMI_FRM_INPUT_EVT__)
				//length must be less than 20
            	if(strlen(curr_aud_desc)<MAX_INPUT_EVENT_AUD_LEN)
            	{
					MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].aud_desc_str = (U8*)malloc(strlen(curr_aud_desc)+1);
               		strcpy(MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].aud_desc_str, curr_aud_desc);
				}
				else
				{
					MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].aud_desc_str = (U8*)malloc(MAX_INPUT_EVENT_AUD_LEN);
					memset(MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].aud_desc_str, 0, MAX_INPUT_EVENT_AUD_LEN);
               		strncpy(MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].aud_desc_str, curr_aud_desc, MAX_INPUT_EVENT_AUD_LEN-1);
				}
			#else/*#if defined(__MMI_FRM_INPUT_EVT__)*/
                MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].aud_desc_str = (U8*)malloc(strlen(curr_aud_desc)+1);
                strcpy(MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].aud_desc_str, curr_aud_desc);
			#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/	
            }
            
            if (curr_aud_format != NULL)
            {
                MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].format = (U8*)malloc(strlen(curr_aud_format)+1);
                strcpy(MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].format, curr_aud_format);
            }
            
            MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].is_theme = g_mmi_rp_is_theme;
            MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].flag = curr_bin;
            MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count].force_type = curr_force_type;
            MMI_RP_AUD_CURR_APP_AUD.total_count++;
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
 *  mmi_rp_aud_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_aud_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Audio-end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_aud_data_handler
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
int mmi_rp_aud_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Audio-data: %s\n", data);

    if(data != NULL)
    {
        memset(temp, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);

        if((strlen(g_mmi_rp_mgr_cntx.path.def_img_path) + strlen(data)) < MMI_RP_MGR_MAX_FILE_NAME_LEN)
        {
            mmi_rp_mgr_path_create(temp, g_mmi_rp_mgr_cntx.path.def_ado_path, (U8*)data);
        }
        else
        {
            MMI_RP_PARSE_WARNING_DATA(RP_WARN_BUFFER_LENGTH_EXCEEDED, data);
        }
        
        /* Adding at total_count - 1 index as the total_count has already been increased in start tag handler */
        MMI_RP_AUD_CURR_APP_AUD.audios[MMI_RP_AUD_CURR_APP_AUD.total_count - 1].file_path = mmi_rp_hash_add(g_mmi_rp_aud_cntx.file_path_hash, temp);
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_aud_filter
 * DESCRIPTION
 *  This function is for resgen to filter image resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_aud_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0, k =0;
    MMI_BOOL found = MMI_FALSE;
    mmi_rp_aud_data_struct *curr_app_aud = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        curr_app_aud = &(g_mmi_rp_aud_cntx.app_aud_data[i]);
        for(j =0; j < curr_app_aud->total_count; j++)
        {
            found = MMI_TRUE;   /* Currently, there's no condition to filter any audio res. So, populate all audio res. */

            /* Put condition here */
            /* if(XXX) { found = MMI_FALSE; }            */

            curr_app_aud->audios[j].filter = found;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_aud_output_phase1
 * DESCRIPTION
 *  Output ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_aud_output_phase1(void)
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
            mmi_rp_aud_output_phase1_app_def_h_file(i, p_file);
            fclose(p_file);
        }
        else
        {
            /* Error writing output file. Exit. */
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_aud_output_phase1_app_def_h_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_aud_output_phase1_app_def_h_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0;
    U8 str_enum_name[MMI_RP_OUTPUT_ENUM_NAME_MAX], str_enum_max[MMI_RP_OUTPUT_ENUM_NAME_MAX];
    MMI_BOOL first = MMI_TRUE;
    mmi_rp_aud_data_struct *curr_app_aud = &(g_mmi_rp_aud_cntx.app_aud_data[app_index]);
    S32 app_enum_log_counter = -1;      /* -1 for debug purpose */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        memset(str_enum_name, 0, sizeof(str_enum_name));
        strcpy(str_enum_name, "mmi_rp_");
        strcat(str_enum_name, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_name, "_aud_enum");
        for(i = 0; i < strlen(str_enum_name); i++)
        {
            str_enum_name[i] = tolower(str_enum_name[i]);
        }

        memset(str_enum_max, 0, sizeof(str_enum_max));
        strcpy(str_enum_max, "MMI_RP_");
        strcat(str_enum_max, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_max, "_AUD_MAX");
        for(i = 0; i < strlen(str_enum_max); i++)
        {
            str_enum_max[i] = toupper(str_enum_max[i]);
        }

        /* Check if no aud IDs. */
        if(curr_app_aud->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            fprintf(p_file, "\n\n");
            fprintf(p_file, "/******************** Audio resource IDs - begin ********************/\n");
            fprintf(p_file, "typedef enum\n{\n");


            for(i = 0; i < curr_app_aud->total_count; i++)
            {
                if(curr_app_aud->audios[i].filter == MMI_FALSE)
                {
                    continue;
                }

                if(first)
                {
                    fprintf(p_file, "    %s = %d + 1, /* BASE_ID + 1 */\n", curr_app_aud->audios[i].aud_id_str, g_mmi_resource_base_table[app_index].min);
                    first = MMI_FALSE;

                    app_enum_log_counter = g_mmi_resource_base_table[app_index].min + 1;
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_aud->audios[i].aud_id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
                else
                {
                    fprintf(p_file, "    %s,\n", curr_app_aud->audios[i].aud_id_str);
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_aud->audios[i].aud_id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
            }

            fprintf(p_file, "    %s\n", str_enum_max);
            fprintf(p_file, "}%s;\n", str_enum_name);
            fprintf(p_file, "/******************** Audio resource IDs - finish ********************/\n");
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
 *  mmi_rp_aud_output_phase2
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_aud_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0;
    U8 *str_output_filename = NULL;
    U8 str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    // Frederic: TBC
    CHAR * str_output_filename_header =NULL;
    CHAR * str_function_name = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. Output all APPs .c files. */
#ifdef __RESGEN_INTERNAL_OFFLINE__ 
    AudioAdaptorStartOfflinePopulation(DEFAULT_OFFLINE_XML_AUDIO_DB);
#endif //__RESGEN_INTERNAL_OFFLINE__
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        {
            continue;
        }

#ifdef __RESGEN_INTERNAL_POP_FILE_REDUCE__
        mmi_rp_aud_output_phase2_app_c_file(i);
#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
        /* dotC file name */
        str_output_filename = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_C_FILE_PATH, g_mmi_resource_base_table[i].appname);
        /* Header file name*/
        str_output_filename_header = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_H_FILE, g_mmi_resource_base_table[i].appname);
        /* Populate function name */
        str_function_name = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_POPULATE_FUNCTION, g_mmi_resource_base_table[i].appname);

        /* Menu resource module has already written the header and started the function. */ 
        /* Open the file in append mode */
        if(p_file = fopen(str_output_filename, "a"))            
        {
            mmi_rp_aud_output_phase2_app_c_file(i, p_file);
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
    AudioAdaptorStopOfflinePopulation();
#endif //__RESGEN_INTERNAL_OFFLINE__
    
    /* 2. Output all debug\venus_theme_log.txt file. */
    memset(str_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_filename, MMI_RP_MGR_XML_VENUS_THEME_LOG);
    
    if(p_file = fopen(str_filename, "a"))           
    {
        mmi_rp_aud_output_phase2_venus_theme(p_file);
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
	
#if defined(__MMI_FRM_INPUT_EVT__)
	/* 3. Output all debug\venus_theme_log.txt file. */
	mmi_rp_input_event_read_cfg_info_from_tmp();
	
    memset(str_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_filename, CUST_INPUT_EVENT_CFG_SRC_DST);
    
    if(p_file = fopen(str_filename, "a"))           
    {
        mmi_rp_aud_output_phase2_aud_file(p_file);
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

	//4.
	mmi_rp_input_event_output_aud_desc_info();
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/	
}

#if defined(__MMI_FRM_INPUT_EVT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_input_event_read_cfg_info_from_tmp
 * DESCRIPTION
 *  This function is for resgen to read led&vib info from tmp file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_input_event_read_cfg_info_from_tmp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 1
	/*write to nvram config*/
	fprintf(stdout, "start to write nvram file");
	if(p_file = fopen(CUST_INPUT_EVENT_CFG_SRC_TMP, "r"))
	{
		U8 buf[512];
		FILE* dst_file;
		if(dst_file=fopen(CUST_INPUT_EVENT_CFG_SRC_DST, "w"))
		{
			while(!feof(p_file))
			{
			//	memset(buf, 0, sizeof(buf));
			//	fread(buf, 512, 1, p_file);
			//	fwrite(buf, 512, 1, dst_file);

				fgets(buf, 512, p_file);
				fputs(buf, dst_file);
					
				//fputc(&ch, dst_file);
				//fprintf(dst_file, &ch);
				//fputc(ch, dst_file);
				//fwrite(&ch, 1, 1, dst_file);
			}

			fclose(dst_file);
		}
		else
		{
			 fprintf(stderr, "open dst file failed");
			 exit(0);
		}
		fclose(p_file);
	}
	else
	{
		fprintf(stderr, "open tmp file failed\n");
		exit(0);

	}
#endif//0	

}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_aud_output_phase2_venus_theme
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_aud_output_phase2_aud_file(FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_aud_data_struct *curr_app_aud = NULL;
    U32 i =0, j = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	fprintf(p_file, "/*******************aud info********************/\n");

	fprintf(p_file, "nvram_input_event_aud_notify nv_input_event_notify_aud_info_tbl[] = \n");
	fprintf(p_file, "{\n");

	g_aud_file_path_num = 0;
	
  //  fprintf(p_file, "[RP_AUDIO]\n");
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        curr_app_aud = &(g_mmi_rp_aud_cntx.app_aud_data[i]);
        
        for(j = 0; j < curr_app_aud->total_count; j++)
        {
            if (curr_app_aud->audios[j].aud_path)
            {
            	g_aud_file_path_num++;
				
                fprintf(p_file, "	{%s, \"%s\", \"%s\"},\n", 
                    curr_app_aud->audios[j].aud_id_str, 
                    curr_app_aud->audios[j].aud_path, 
                    curr_app_aud->audios[j].aud_desc_str);
            }
        }
    }    

	fprintf(p_file, "};\n");
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rp_input_event_read_desc_info_from_tmp
 * DESCRIPTION
 *  This function is for resgen to read led&vib desc info from tmp file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_input_event_read_desc_info_from_tmp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 1
	/*write to nvram config*/
	fprintf(stdout, "start to write nvram file");
	if(p_file = fopen(CUST_INPUT_EVENT_CFG_DESC_TMP, "r"))
	{
		U8 buf[512];
		FILE* dst_file;
		if(dst_file=fopen(CUST_INPUT_EVENT_CFG_DESC, "w"))
		{
			while(!feof(p_file))
			{
			//	memset(buf, 0, sizeof(buf));
			//	fread(buf, 512, 1, p_file);
			//	fwrite(buf, 512, 1, dst_file);

				fgets(buf, 512, p_file);
				fputs(buf, dst_file);
					
				//fputc(&ch, dst_file);
				//fprintf(dst_file, &ch);
				//fputc(ch, dst_file);
				//fwrite(&ch, 1, 1, dst_file);
			}

			fclose(dst_file);
		}
		else
		{
			 fprintf(stderr, "open dst file failed");
			 exit(0);
		}
		fclose(p_file);
	}
	else
	{
		fprintf(stderr, "open tmp file failed\n");
		exit(0);

	}
#endif//0	

}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_input_event_read_desc_info_from_tmp
 * DESCRIPTION
 *  This function is for resgen to read led&vib desc info from tmp file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_input_event_output_aud_desc_info(void)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_aud_data_struct *curr_app_aud = NULL;
	FILE *p_file = NULL; 
    U32 i =0, j = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_rp_input_event_read_desc_info_from_tmp();

	/* 1. Output all APPs .c files. */
	 if((p_file = fopen(CUST_INPUT_EVENT_CFG_DESC, "a")) == NULL)
	 {
		 fprintf(stderr, "[Audio] output Audio desc failed !!\n");
		 exit(0);
	 }
	
	 //write to nvarm cfg
	 if((p_file = fopen(CUST_INPUT_EVENT_CFG_DESC, "a"))== NULL)
	 {	 
	 	/* Error writing output file. Exit. */
		 MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);

		 return;

	 }
	
	
	fprintf(p_file, "\n\n[Audio info desc]\n");
	
  //  fprintf(p_file, "[RP_AUDIO]\n");
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        curr_app_aud = &(g_mmi_rp_aud_cntx.app_aud_data[i]);
        
        for(j = 0; j < curr_app_aud->total_count; j++)
        {
            if (curr_app_aud->audios[j].aud_path)
            {
				
                fprintf(p_file, "{%s, %s}\n", 
                    curr_app_aud->audios[j].aud_id_str,  
                    curr_app_aud->audios[j].aud_desc_str);
            }
        }
    } 

	 fclose(p_file);


}


#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_aud_output_phase2_venus_theme
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_aud_output_phase2_venus_theme(FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_aud_data_struct *curr_app_aud = NULL;
    U32 i =0, j = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fprintf(p_file, "[RP_AUDIO]\n");
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        curr_app_aud = &(g_mmi_rp_aud_cntx.app_aud_data[i]);
        
        for(j = 0; j < curr_app_aud->total_count; j++)
        {
            if (curr_app_aud->audios[j].is_theme)
            {
                fprintf(p_file, "%s\t%s\t%s\n", 
                    curr_app_aud->audios[j].aud_id_str, 
                    curr_app_aud->audios[j].aud_desc_str, 
                    curr_app_aud->audios[j].format);
            }
        }
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_aud_output_phase2_app_c_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
 #ifndef __RESGEN_INTERNAL_POP_FILE_REDUCE__
void mmi_rp_aud_output_phase2_app_c_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0, j = 0;
    mmi_rp_aud_data_struct *curr_app_aud = &(g_mmi_rp_aud_cntx.app_aud_data[app_index]);
    mmi_rp_aud_force_type_enum curr_force_type = MMI_RP_AUD_FORCE_TYPE_NONE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        /* Check if no aud IDs. */
        if(curr_app_aud->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            fprintf(p_file, "\n");
            fprintf(p_file, "/******************** Audio resource IDs - begin ********************/\n");

            /* 1. Add aud items */
            for(i = 0; i < curr_app_aud->total_count; i++)
            {
                curr_force_type = MMI_RP_AUD_FORCE_TYPE_NONE;

                if(curr_app_aud->audios[i].filter == MMI_TRUE && curr_app_aud->audios[i].file_path != NULL)
                {
                    if(curr_app_aud->audios[i].force_type == MMI_RP_AUD_FORCE_TYPE_NONE)
                    {
                        if(curr_app_aud->audios[i].flag == MMI_RP_FLAG_MULTI_BIN)
                        {

                            fprintf(p_file, "    ADD_APPLICATION_AUDIO3(%s, %s, \"%s\");\n", 
                                curr_app_aud->audios[i].aud_id_str, 
                                (curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\""), 
                                "Generated by Resgen_XML");
                        }
                        else
                        {
                            fprintf(p_file, "    ADD_APPLICATION_AUDIO2(%s, %s, \"%s\");\n", 
                                curr_app_aud->audios[i].aud_id_str, 
                                (curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\""), 
                                "Generated by Resgen_XML");
                        }
                    }
                    else
                    {
                        curr_force_type = curr_app_aud->audios[i].force_type;
                        if(curr_app_aud->audios[i].flag == MMI_RP_FLAG_MULTI_BIN)
                        {

                            fprintf(p_file, "    ADD_APPLICATION_AUDIO_TYPE(%s, %s, \"%s\", %s, %s);\n", 
                                curr_app_aud->audios[i].aud_id_str, 
                                (curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\""), 
                                "Generated by Resgen_XML",
                                "TRUE",
                                g_mmi_rp_aud_force_type_enum_str[curr_force_type]);
                        }
                        else
                        {
                            fprintf(p_file, "    ADD_APPLICATION_AUDIO_TYPE(%s, %s, \"%s\", %s, %s);\n", 
                                curr_app_aud->audios[i].aud_id_str, 
                                (curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\""), 
                                "Generated by Resgen_XML",
                                "FALSE",
                                g_mmi_rp_aud_force_type_enum_str[curr_force_type]);
                        }
                    }
                }
            }
            fprintf(p_file, "/******************** Audio resource IDs - finish ********************/\n");
        }
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}

#elif defined(__RESGEN_INTERNAL_POP_FILE_REDUCE__) && defined(__RESGEN_INTERNAL_OFFLINE__)// __RESGEN_INTERNAL_POP_FILE_REDUCE__
void mmi_rp_aud_output_phase2_app_c_file(U32 app_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0, j = 0;
    mmi_rp_aud_data_struct *curr_app_aud = &(g_mmi_rp_aud_cntx.app_aud_data[app_index]);
    mmi_rp_aud_force_type_enum curr_force_type = MMI_RP_AUD_FORCE_TYPE_NONE;
    U32 audioResourId = g_mmi_resource_base_table[app_index].min + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        /* Check if no aud IDs. */
        if(curr_app_aud->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {

            /* 1. Add aud items */
            for(i = 0; i < curr_app_aud->total_count; i++)
            {
                curr_force_type = MMI_RP_AUD_FORCE_TYPE_NONE;

                if(curr_app_aud->audios[i].filter == MMI_TRUE && curr_app_aud->audios[i].file_path != NULL)
                {
                    if(curr_app_aud->audios[i].force_type == MMI_RP_AUD_FORCE_TYPE_NONE)
                    {
                        if(curr_app_aud->audios[i].flag == MMI_RP_FLAG_MULTI_BIN)
                        {

                            //printf("    ADD_APPLICATION_AUDIO3(%s, %s, \"%s\");\n", 
                            //    curr_app_aud->audios[i].aud_id_str, 
                           //     (curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\""), 
                           //     "Generated by Resgen_XML");
                            AudioAdaptorSetAudio(audioResourId, ((curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\"")),
                            ((g_mmi_resource_base_table[app_index].appname)?(g_mmi_resource_base_table[app_index].appname):("APP name unknown")),
                            "Generated by Resgen_XML",
                            curr_app_aud->audios[i].aud_id_str,
                            ((g_mmi_resource_base_table[app_index].res_path)?(g_mmi_resource_base_table[app_index].res_path):("Res path unknown")),
                            1, OFFLINE_RESGEN_NO_FORCE_TYPE,1);
                            audioResourId++;
                        }
                        else
                        {
                            //printf( "    ADD_APPLICATION_AUDIO2(%s, %s, \"%s\");\n", 
                            //    curr_app_aud->audios[i].aud_id_str, 
                            //    (curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\""), 
                            //    "Generated by Resgen_XML");
                            
                            AudioAdaptorSetAudio(audioResourId, ((curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\"")),
                            ((g_mmi_resource_base_table[app_index].appname)?(g_mmi_resource_base_table[app_index].appname):("APP name unknown")),
                            "Generated by Resgen_XML",
                            curr_app_aud->audios[i].aud_id_str,
                            ((g_mmi_resource_base_table[app_index].res_path)?(g_mmi_resource_base_table[app_index].res_path):("Res path unknown")),
                            1, OFFLINE_RESGEN_NO_FORCE_TYPE,0);
                            audioResourId++;
                        }
                    }
                    else
                    {
                        curr_force_type = curr_app_aud->audios[i].force_type;
                        if(curr_app_aud->audios[i].flag == MMI_RP_FLAG_MULTI_BIN)
                        {

                            //printf("    ADD_APPLICATION_AUDIO_TYPE(%s, %s, \"%s\", %s, %s);\n", 
                            //    curr_app_aud->audios[i].aud_id_str, 
                            //    (curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\""), 
                            //    "Generated by Resgen_XML",
                            //    "TRUE",
                            //    g_mmi_rp_aud_force_type_enum_str[curr_force_type]);
                            
                            AudioAdaptorSetAudio(audioResourId, 
                                ((curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\"")),
                                 ((g_mmi_resource_base_table[app_index].appname)?(g_mmi_resource_base_table[app_index].appname):("APP name unknown")),
                            "Generated by Resgen_XML",
                                 curr_app_aud->audios[i].aud_id_str, 
                                 ((g_mmi_resource_base_table[app_index].res_path)?(g_mmi_resource_base_table[app_index].res_path):("Res path unknown")), 
                                 1, 
                                 MMI_AUDIO_TYPE_MAPPING[curr_force_type],1);
                             audioResourId++;
                        }
                        else
                        {
                            //printf("    ADD_APPLICATION_AUDIO_TYPE(%s, %s, \"%s\", %s, %s);\n", 
                            //    curr_app_aud->audios[i].aud_id_str, 
                            //    (curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\""), 
                            //    "Generated by Resgen_XML",
                            //     "FALSE",
                            //    g_mmi_rp_aud_force_type_enum_str[curr_force_type]);
                             AudioAdaptorSetAudio(audioResourId, 
                                 ((curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\"")),
	                             ((g_mmi_resource_base_table[app_index].appname)?(g_mmi_resource_base_table[app_index].appname):("APP name unknown")),
                            "Generated by Resgen_XML",
	                             curr_app_aud->audios[i].aud_id_str,
	                             ((g_mmi_resource_base_table[app_index].res_path)?(g_mmi_resource_base_table[app_index].res_path):("Res path unknown")),
	                             1, 
	                             MMI_AUDIO_TYPE_MAPPING[curr_force_type],0);
                             audioResourId++;
                        }
                    }
                }
            }
        }

}


#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_aud_output_phase2_app_c_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_aud_output_phase2_app_c_file(U32 app_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0, j = 0;
    mmi_rp_aud_data_struct *curr_app_aud = &(g_mmi_rp_aud_cntx.app_aud_data[app_index]);
    mmi_rp_aud_force_type_enum curr_force_type = MMI_RP_AUD_FORCE_TYPE_NONE;
    FILE * p_file = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        /* Check if no aud IDs. */
        if(curr_app_aud->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {

            p_file = mmi_rp_open_population_c_file(app_index, RES_LEGACY_POP_AUDIO_MASK);
            if(p_file== NULL)            /* Rest resources will open the file in append mode */
            {
                 MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
            }
            fprintf(p_file, "\n");
            fprintf(p_file, "/******************** Audio resource IDs - begin ********************/\n");

            /* 1. Add aud items */
            for(i = 0; i < curr_app_aud->total_count; i++)
            {
                curr_force_type = MMI_RP_AUD_FORCE_TYPE_NONE;

                if(curr_app_aud->audios[i].filter == MMI_TRUE && curr_app_aud->audios[i].file_path != NULL)
                {
                    if(curr_app_aud->audios[i].force_type == MMI_RP_AUD_FORCE_TYPE_NONE)
                    {
                        if(curr_app_aud->audios[i].flag == MMI_RP_FLAG_MULTI_BIN)
                        {

                            fprintf(p_file, "    ADD_APPLICATION_AUDIO3(%s, %s, \"%s\");\n", 
                                curr_app_aud->audios[i].aud_id_str, 
                                (curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\""), 
                                "Generated by Resgen_XML");
                        }
                        else
                        {
                            fprintf(p_file, "    ADD_APPLICATION_AUDIO2(%s, %s, \"%s\");\n", 
                                curr_app_aud->audios[i].aud_id_str, 
                                (curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\""), 
                                "Generated by Resgen_XML");
                        }
                    }
                    else
                    {
                        curr_force_type = curr_app_aud->audios[i].force_type;
                        if(curr_app_aud->audios[i].flag == MMI_RP_FLAG_MULTI_BIN)
                        {

                            fprintf(p_file, "    ADD_APPLICATION_AUDIO_TYPE(%s, %s, \"%s\", %s, %s);\n", 
                                curr_app_aud->audios[i].aud_id_str, 
                                (curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\""), 
                                "Generated by Resgen_XML",
                                "TRUE",
                                g_mmi_rp_aud_force_type_enum_str[curr_force_type]);
                        }
                        else
                        {
                            fprintf(p_file, "    ADD_APPLICATION_AUDIO_TYPE(%s, %s, \"%s\", %s, %s);\n", 
                                curr_app_aud->audios[i].aud_id_str, 
                                (curr_app_aud->audios[i].file_path ? (const S8*)curr_app_aud->audios[i].file_path : "\"\""), 
                                "Generated by Resgen_XML",
                                "FALSE",
                                g_mmi_rp_aud_force_type_enum_str[curr_force_type]);
                        }
                    }
                }
            }
            fprintf(p_file, "/******************** Audio resource IDs - finish ********************/\n");
            fclose(p_file);
        }

}
#endif // __RESGEN_INTERNAL_POP_FILE_REDUCE__
