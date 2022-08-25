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
 *  mmi_rp_third_rom.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   third ROM Resource Generator
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
#include "mmi_rp_hash.h"
#include "mmi_rp_third_rom.h"
#include "CustResDef.h"


extern const mmi_resource_base_struct g_mmi_resource_base_table[];

#define MMI_RP_THIRD_ROM_CURR_APP_STR       g_mmi_rp_third_rom_cntx.app_third_rom_data[g_mmi_rp_mgr_cntx.cur_app_index]
mmi_rp_third_rom_cntx_struct g_mmi_rp_third_rom_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_thirdrom_init
 * DESCRIPTION
 *  Initializes the thirdrom context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_thirdrom_init(void)
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
	
    memset(&g_mmi_rp_third_rom_cntx, 0, sizeof(g_mmi_rp_third_rom_cntx));
    g_mmi_rp_third_rom_cntx.app_third_rom_data = (mmi_rp_third_rom_data_struct*)malloc(sizeof(mmi_rp_third_rom_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

	if(!g_mmi_rp_third_rom_cntx.app_third_rom_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_third_rom_cntx.app_third_rom_data, 0, sizeof(mmi_rp_third_rom_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_third_rom_cntx.hash = mmi_rp_hash_create(0xFFFF); 


}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_thirdrom_set_app_range
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_thirdrom_set_app_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 range = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_RP_THIRD_ROM_CURR_APP_STR.third_rom_strings == NULL)
    {
        range = g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min + 1;
        MMI_RP_THIRD_ROM_CURR_APP_STR.third_rom_strings = (mmi_rp_third_rom_id_struct*)malloc(sizeof(mmi_rp_third_rom_id_struct) * range);

        if((!MMI_RP_THIRD_ROM_CURR_APP_STR.third_rom_strings) && (range > 0))
        {
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }

        memset(MMI_RP_THIRD_ROM_CURR_APP_STR.third_rom_strings, 0, sizeof(mmi_rp_third_rom_id_struct) * range);
    }
}


    
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_thirdrom_start_handler
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
int mmi_rp_thirdrom_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    U8 *curr_third_rom_id = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("third rom-start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID) == 0)
        {
            curr_third_rom_id = (U8*)attr[index + 1];
        }
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        index += 2;
    }

    if(curr_third_rom_id != NULL)
    {
        if(!mmi_rp_hash_find(g_mmi_rp_third_rom_cntx.hash, curr_third_rom_id))
        {
            MMI_RP_THIRD_ROM_CURR_APP_STR.third_rom_strings[MMI_RP_THIRD_ROM_CURR_APP_STR.total_count].third_rom_id_str = mmi_rp_hash_add(g_mmi_rp_third_rom_cntx.hash, curr_third_rom_id);
            MMI_RP_THIRD_ROM_CURR_APP_STR.total_count++;
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
 *  mmi_rp_thirdrom_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_thirdrom_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("third rom-end: %s\n", el);
    return MMI_RP_PARSE_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_data_handler
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
int mmi_rp_thirdrom_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str_data[MMI_RP_THIRD_ROM_MAX_STRING_LEN];
    U32 str_len = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("third rom-data: %s\n", data);

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
            memset(str_data, 0, MMI_RP_THIRD_ROM_MAX_STRING_LEN);
            strncpy(str_data, data + 1, str_len - 2);
            MMI_RP_THIRD_ROM_CURR_APP_STR.third_rom_strings[MMI_RP_THIRD_ROM_CURR_APP_STR.total_count - 1].third_rom_bin_path = mmi_rp_hash_add(g_mmi_rp_third_rom_cntx.hash, (U8*)str_data);
        }
        else
        {
            /* Adding at (total_count - 1) index as the total_count has already been increased in start tag handler */
            MMI_RP_THIRD_ROM_CURR_APP_STR.third_rom_strings[MMI_RP_THIRD_ROM_CURR_APP_STR.total_count - 1].third_rom_bin_path = mmi_rp_hash_add(g_mmi_rp_third_rom_cntx.hash, (U8*)data);
        }
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_thirdrom_filter
 * DESCRIPTION
 *  This function is for resgen to filter your resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_thirdrom_filter(void)
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
 *  mmi_rp_thirdrom_output_phase1
 * DESCRIPTION
 *  Output IDs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_thirdrom_output_phase1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. Output all APPs .h files. */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_thirdrom_output_phase2
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_thirdrom_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0;	
    char thirdrom_output_filename[] = CUST_THIRD_ROM_BIN_PATH"\\NFBpack3rdromCust.txt";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. Output all APPs .c files. */
	if((p_file = fopen(thirdrom_output_filename, "w")) == NULL)
	{
        fprintf(stderr, "[Third Rom] output file NFBpack3rdromCust.txt open failed !!\n");
        exit(0);
	}
	
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        {
            continue;
        }

        if(p_file = fopen(thirdrom_output_filename, "a"))            
        {
            mmi_rp_thirdrom_output_phase2_app_c_file(i, p_file);
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
 *  mmi_rp_thirdrom_output_phase2_app_c_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_thirdrom_output_phase2_app_c_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0, j = 0;
    mmi_rp_third_rom_data_struct *curr_app_third_rom = &(g_mmi_rp_third_rom_cntx.app_third_rom_data[app_index]);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        /* Check if no str IDs. */
        if(curr_app_third_rom->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            /* Add third rom items */
            for(i = 0; i < curr_app_third_rom->total_count; i++)
            {
                fprintf(p_file, "\"%s\"=>\"%s\",\n",curr_app_third_rom->third_rom_strings[i].third_rom_id_str,
					            curr_app_third_rom->third_rom_strings[i].third_rom_bin_path);
            }
        }
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}
 

