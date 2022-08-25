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
 *  mmi_rp_cust_notify.c
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
#include "mmi_rp_cust_input_event.h"


#if defined(__MMI_FRM_INPUT_EVT__)

/*notify*/
#define MMI_RP_MGR_ATTR_LED "led"
#define MMI_RP_MGR_ATTR_VOICE "voice"
#define MMI_RP_MGR_ATTR_VIB "vib"

/*input event*/
#define MMI_RP_MGR_ATTR_GRP_ID "grp_id"
#define MMI_RP_MGR_ATTR_GRP_DESC "grp_desc"
#define MMI_RP_MGR_ATTR_EVT_ID "evt_id"
#define MMI_RP_MGR_ATTR_EVT_DESC "evt_desc"
#define MMI_RP_MGR_ATTR_KEY_CODE "key_code"
#define MMI_RP_MGR_ATTR_KEY_TYPE "key_type"

/*app info*/
#define MMI_RP_MGR_ATTR_APP_INDEX "app_indx"
#define MMI_RP_MGR_ATTR_APP_LAUNCH_EVT "launch_evt"


#define CUST_INPUT_EVENT_CFG_SRC_PATH "..\\..\\framework\\eventHandling\\eventsSrc"
#define CUST_INPUT_EVENT_CFG_INC_PATH "..\\..\\framework\\eventHandling\\eventsInc"

#define CUST_INPUT_EVENT_CFG_SRC_TMP "..\\..\\..\\custom\\common\\nvram_input_event_cfg.h.tmp"
#define CUST_INPUT_EVENT_CFG_SRC_DST "..\\..\\..\\custom\\common\\nvram_input_event_cfg.h"
#define CUST_INPUT_EVENT_CFG_INC_CONST_DST "..\\..\\..\\custom\\common\\nvram_input_event_const.h"

//config description
#define CUST_INPUT_EVENT_CFG_DESC_TMP "..\\..\\..\\custom\\common\\nvram_input_event_cfg_desc.tmp"
#define CUST_INPUT_EVENT_CFG_DESC "..\\..\\..\\custom\\common\\nvram_input_event_cfg_desc.txt"
//xml
#define CUST_INPUT_EVENT_CFG_XML_DST "..\\..\\..\\custom\\common\\nvram_input_event_cfg.xml"


extern const mmi_resource_base_struct g_mmi_resource_base_table[];
extern U32 g_aud_file_path_num;

/*notify*/
#define MMI_RP_NOTIFY_CURR_APP_STR       g_mmi_rp_notify_cntx.app_notify_data[g_mmi_rp_mgr_cntx.cur_app_index]
mmi_rp_notify_cntx_struct g_mmi_rp_notify_cntx;

/*input event*/
#define MMI_RP_INPUT_EVENT_CURR_APP_STR       g_mmi_rp_input_event_cntx.app_input_event_data[g_mmi_rp_mgr_cntx.cur_app_index]
mmi_rp_input_event_cntx_struct g_mmi_rp_input_event_cntx;

/*app info*/
#define MMI_RP_APP_INFO_CURR_APP_STR       g_mmi_rp_app_info_cntx.app_info_data[g_mmi_rp_mgr_cntx.cur_app_index]
mmi_rp_app_info_cntx_struct g_mmi_rp_app_info_cntx;


/*notify*/
static void mmi_rp_notify_output_phase1_app_def_h_file(U32 app_index, FILE *p_file);
static void mmi_rp_notify_output_phase2_app_c_file(U32 app_index, FILE *p_file);
static void mmi_rp_notify_output_phase2_desc_file(void);

/*input event*/
static void mmi_rp_input_event_output_phase1_app_def_h_file(U32 app_index, FILE *p_file);
static void mmi_rp_input_event_output_phase2_app_c_file(U32 app_index, FILE *p_file);
static void mmi_rp_input_event_output_phase2_desc_file(void);

/*app info*/
static void mmi_rp_app_info_output_phase1_app_def_h_file(U32 app_index, FILE *p_file);
static void mmi_rp_app_info_output_phase2_app_c_file(U32 app_index, FILE *p_file);

/*
btbox head file
*/
static void mmi_rp_btbox_write_include_head_in_file(FILE* pfile);
/*
btbox table structure
*/
static void mmi_rp_btbox_write_tbl_structure_in_file(FILE* pfile);


/*file header*/
/*
btbox head file
*/
/*****************************************************************************
 * FUNCTION
 *	mmi_rp_btbox_write_include_head_in_file
 * DESCRIPTION
 *	Initializes the template context structure. Called for every .res file parsed.
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
static void mmi_rp_btbox_write_include_head_in_file(FILE* pfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fputs("\n\n", pfile);//mmi_frm_btbox_nolcd_cfg.h
	//fputs("#ifndef MMI_FRM_INPUT_EVENT_CFG_H\n", pfile);
   // fputs("#define MMI_FRM_INPUT_EVENT_CFG_H\n\n", pfile);
	fputs("#include \"MMI_features.h\"\n", pfile);
	fputs("#include \"MMIDataType.h\"\n", pfile);
	fputs("#include \"GlobalResDef.h\"\n", pfile);
	fputs("#include \"GlobalConstants.h\"\n", pfile);
    fputs("#include \"mmi_rp_all_defs.h\"\n", pfile);
    fputs("#include \"mmi_frm_input_event.h\"\n", pfile);


}


/*
btbox table structure
*/
/*****************************************************************************
 * FUNCTION
 *	mmi_rp_btbox_write_include_head_in_file
 * DESCRIPTION
 *	Initializes the template context structure. Called for every .res file parsed.
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
static void mmi_rp_btbox_write_tbl_structure_in_file(FILE* pfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*app info tbl structure*/
	fputs("\n\n", pfile);
	fputs("/*\n", pfile);
	fputs("this information can help to find the next app when switch to next local app\n", pfile);
	fputs("*/\n", pfile);
	fputs("typedef struct\n", pfile);
	fputs("{\n", pfile);
	fputs("	U16 app_indx;\n", pfile);
	fputs("	U16 app_id;//app group id\n", pfile);
	fputs("	U16 launch_evt_id;//\n", pfile);
	fputs("}mmi_input_event_local_app_info;\n", pfile);
	fputs("\n\n\n\n", pfile);	

	/*input event tbl structure*/
	fputs("/*\n", pfile);
	fputs("evt structure\n", pfile);
	fputs("\n", pfile);
	fputs("rule: in one app, one{key_code, key_type} only map one evt id\n", pfile);
	fputs("but can map serveral evt id among different apps.\n", pfile);
	fputs("and this will be checked when bootup\n", pfile);
	fputs("*/\n", pfile);
	fputs("typedef struct\n{\n", pfile);	
	fputs("	U16 app_id;//\n", pfile);
	fputs("	U16 evt_id;\n", pfile);
	fputs("	S16 key_code;\n", pfile);
	fputs("	S16 key_type;\n", pfile);
	fputs("}mmi_input_event_evt_info;\n", pfile);
	fputs("\n\n\n\n", pfile);


	/*notify tbl structure*/
	fputs("/*\n", pfile);
	fputs("notify: nolcd box app use notify to output, like led, voice, vibrate.\n", pfile);
	fputs("app only tell framework the notify id, framework will help to\n", pfile);
	fputs("find the led id(led show pattern), void id, vibrate id(vibrate).\n", pfile);
	fputs("and output these information.\n", pfile);
	fputs("*/\n", pfile);
	fputs("typedef struct\n", pfile);
	fputs("{\n", pfile);
	fputs("	U16 notify_id;//will be generated by resgen flow\n", pfile);
	fputs("	U16 led_indx;\n", pfile);
	fputs("	U16 voi_id;\n", pfile);
	fputs("	U16 vib_indx;//\n", pfile);
	fputs("}mmi_input_event_notify_info;\n", pfile);
	fputs("\n\n\n\n", pfile);

	/*led enum*/
	
	fputs("\n\n", pfile);


}




/*notify*/
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_init
 * DESCRIPTION
 *  Initializes the template context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_notify_init(void)
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


	memset(&g_mmi_rp_notify_cntx, 0, sizeof(g_mmi_rp_notify_cntx));
    g_mmi_rp_notify_cntx.app_notify_data = (mmi_rp_notify_data_struct*)malloc(sizeof(mmi_rp_notify_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

	if(!g_mmi_rp_notify_cntx.app_notify_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_notify_cntx.app_notify_data, 0, sizeof(mmi_rp_notify_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_notify_cntx.hash = mmi_rp_hash_create(0xFFFF); 
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_set_app_range
 * DESCRIPTION
 *  Initializes the template context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_notify_set_app_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 range = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_RP_NOTIFY_CURR_APP_STR.notify_strings == NULL)
    {
        range = g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min + 1;
        MMI_RP_NOTIFY_CURR_APP_STR.notify_strings = (mmi_rp_notify_struct*)malloc(sizeof(mmi_rp_notify_struct) * range);

        if((!MMI_RP_NOTIFY_CURR_APP_STR.notify_strings) && (range > 0))
        {
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }

        memset(MMI_RP_NOTIFY_CURR_APP_STR.notify_strings, 0, sizeof(mmi_rp_notify_struct) * range);
    }

}


    
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_start_handler
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
int mmi_rp_notify_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   	kal_int32   index = 0;
    U8 *curr_notify_id = NULL;
	U8 *curr_led_id = NULL;
	U8 *curr_voice_id = NULL;
	U8 *curr_vib_id = NULL;
	U8 *curr_notify_desc=NULL;
	U8 default_str[]= "0";
	U8 default_aud_id[] = "AUD_ID_INPUT_EVT_DUMMY";
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("notify-start: %s\n", el);

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
            curr_notify_id = (U8*)attr[index + 1];
        }
		else if(strcmp(attr[index], MMI_RP_MGR_ATTR_LED) == 0)
		{
			curr_led_id = (U8*)attr[index + 1];
		}
		else if(strcmp(attr[index], MMI_RP_MGR_ATTR_VOICE) == 0)
		{
			curr_voice_id = (U8*)attr[index + 1];
		}
		else if(strcmp(attr[index], MMI_RP_MGR_ATTR_VIB) == 0)
		{
			curr_vib_id = (U8*)attr[index + 1];
		}
		else if(strcmp(attr[index], MMI_RP_MGR_ATTR_DESC) == 0)
		{
			curr_notify_desc = (U8*)attr[index + 1];
		}
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        index += 2;
    }

    if(curr_notify_id != NULL)
    {
		if(curr_led_id == NULL)
		{
			curr_led_id = default_str;
		}

		if(curr_voice_id == NULL)
		{
			curr_voice_id = default_aud_id;
		}

		if(curr_vib_id == NULL)
		{
			curr_vib_id = default_str;
		}

		if(curr_notify_desc == NULL)
		{
			curr_notify_desc = curr_notify_id;
		}
	
        if(!mmi_rp_hash_find(g_mmi_rp_notify_cntx.hash, curr_notify_id))
        {
            MMI_RP_NOTIFY_CURR_APP_STR.notify_strings[MMI_RP_NOTIFY_CURR_APP_STR.total_count].notify_id_str = mmi_rp_hash_add(g_mmi_rp_notify_cntx.hash, curr_notify_id);
			MMI_RP_NOTIFY_CURR_APP_STR.notify_strings[MMI_RP_NOTIFY_CURR_APP_STR.total_count].led_id_str = mmi_rp_hash_add(g_mmi_rp_notify_cntx.hash, curr_led_id);
	        MMI_RP_NOTIFY_CURR_APP_STR.notify_strings[MMI_RP_NOTIFY_CURR_APP_STR.total_count].voice_id_str = mmi_rp_hash_add(g_mmi_rp_notify_cntx.hash, curr_voice_id);
            MMI_RP_NOTIFY_CURR_APP_STR.notify_strings[MMI_RP_NOTIFY_CURR_APP_STR.total_count].vib_id_str = mmi_rp_hash_add(g_mmi_rp_notify_cntx.hash, curr_vib_id);
			MMI_RP_NOTIFY_CURR_APP_STR.notify_strings[MMI_RP_NOTIFY_CURR_APP_STR.total_count].notify_desc_str = mmi_rp_hash_add(g_mmi_rp_notify_cntx.hash, curr_notify_desc);
			MMI_RP_NOTIFY_CURR_APP_STR.total_count++;
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
 *  mmi_rp_notify_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_notify_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("notify -end: %s\n", el);
    
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
int mmi_rp_notify_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("notify -data: %s\n", data);

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
 *  mmi_rp_notify_filter
 * DESCRIPTION
 *  This function is for resgen to filter your resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_notify_filter(void)
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

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 1
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_notify_output_phase1
 * DESCRIPTION
 *  Output IDs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_notify_output_phase1(void)
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
            mmi_rp_notify_output_phase1_app_def_h_file(i, p_file);
            fclose(p_file);
        }
        else
        {
            /* Error writing output file. Exit. */
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
        }
    }

    /* 2. If you have any other header files, you can output it here*/

	//read led&vib info from tmp file
//	mmi_rp_input_event_read_cfg_info_from_tmp();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_notify_output_phase1_app_def_h_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_notify_output_phase1_app_def_h_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i =0;
	 U8 str_enum_name[MMI_RP_OUTPUT_ENUM_NAME_MAX], str_enum_max[MMI_RP_OUTPUT_ENUM_NAME_MAX];
	 MMI_BOOL first = MMI_TRUE;
	 mmi_rp_notify_data_struct *curr_app_notify = &(g_mmi_rp_notify_cntx.app_notify_data[app_index]);
	 S32 app_enum_log_counter = -1; 	 /* -1 for debug purpose */
	
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 if(p_file)
	 {
		 memset(str_enum_name, 0, sizeof(str_enum_name));
		 strcpy(str_enum_name, "mmi_rp_");
		 strcat(str_enum_name, g_mmi_resource_base_table[app_index].appname);
		 strcat(str_enum_name, "_notify_enum");
		 for(i = 0; i < strlen(str_enum_name); i++)
		 {
			 str_enum_name[i] = tolower(str_enum_name[i]);
		 }
	
		 memset(str_enum_max, 0, sizeof(str_enum_max));
		 strcpy(str_enum_max, "MMI_RP_");
		 strcat(str_enum_max, g_mmi_resource_base_table[app_index].appname);
		 strcat(str_enum_max, "_NOTIFY_MAX");
		 for(i = 0; i < strlen(str_enum_max); i++)
		 {
			 str_enum_max[i] = toupper(str_enum_max[i]);
		 }
	
		 /* Check if no str IDs. */
		 if(curr_app_notify->total_count <= 0)
		 {
			 MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
		 }
		 else
		 {
			 fprintf(p_file, "\n\n");
			 fprintf(p_file, "/******************** Notify resource IDs - begin ********************/\n");
			 fprintf(p_file, "typedef enum\n{\n");
	
			 for(i = 0; i < curr_app_notify->total_count; i++)
			 {
	
				 if(first)
				 {
					 fprintf(p_file, "	  %s = %d + 1, /* BASE_ID + 1 */\n", curr_app_notify->notify_strings[i].notify_id_str, g_mmi_resource_base_table[app_index].min);
					 first = MMI_FALSE;
	
					 app_enum_log_counter = g_mmi_resource_base_table[app_index].min + 1;
					 MMI_RP_OUTPUT_ENUM_LOG(curr_app_notify->notify_strings[i].notify_id_str, app_enum_log_counter);
					 app_enum_log_counter++;
				 }
				 else
				 {
					 fprintf(p_file, "	  %s,\n", curr_app_notify->notify_strings[i].notify_id_str);
					 MMI_RP_OUTPUT_ENUM_LOG(curr_app_notify->notify_strings[i].notify_id_str, app_enum_log_counter);
					 app_enum_log_counter++;
				 }
			 }
	
			 fprintf(p_file, "	  %s\n", str_enum_max);
			 fprintf(p_file, "}%s;\n", str_enum_name);
			 fprintf(p_file, "/******************** Notify resource IDs - end ********************/\n");
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
 *  mmi_rp_template_output_phase2
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_notify_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0;	
	U32 total = 0;
    MMI_BOOL first = MMI_TRUE;
	mmi_rp_notify_data_struct *app_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. Output all APPs .c files. */
	if((p_file = fopen(CUST_INPUT_EVENT_CFG_SRC_DST, "a")) == NULL)
	{
        fprintf(stderr, "[Notify] output file nvram_input_event_cfg.h open failed !!\n");
        exit(0);
	}

	//write to nvarm cfg
	if(p_file = fopen(CUST_INPUT_EVENT_CFG_SRC_DST, "a"))
	{
		mmi_rp_notify_output_phase2_app_c_file(0, p_file);

		
		fclose(p_file);
	}
	else
	{
		/* Error writing output file. Exit. */
		MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);

	}
	

	//2. write to nvram const 
	total = 0;
	
	if(p_file = fopen(CUST_INPUT_EVENT_CFG_INC_CONST_DST, "w"))            
	{
		mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
                p_file, 
                (U8*)CUST_INPUT_EVENT_CFG_INC_CONST_DST, 
                "Resource populate function generated by XML resgen", 
                "MTK resgenerator XML parser");
		
		for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    	{
        	if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        	{
            	continue;
        	}

			total += g_mmi_rp_notify_cntx.app_notify_data[i].total_count;	
	 	}
		//mmi_rp_app_info_output_phase2_app_c_file(0, p_file);
		fputs("#ifndef NVRAM_INPUT_EVENT_CONST_H\n", p_file);
   		fputs("#define NVRAM_INPUT_EVENT_CONST_H\n\n", p_file);
		fprintf(p_file, "\n\n");
		fprintf(p_file, "/*************************notify total number***********************/\n");
		fprintf(p_file, "#define INPUT_EVENT_MAX_NOTIFY %d\n\n", total);

		fprintf(p_file, "/*************************audoio file total number***********************/\n");
		fprintf(p_file, "#define INPUT_EVENT_MAX_AUD %d\n\n", g_aud_file_path_num);
		
		fclose(p_file);
	}
	else
	{
		fprintf(stderr, "open const file failed\n");
		/* Error writing output file. Exit. */
		MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
	}

	//3. output notify desc, CUST_INPUT_EVENT_CFG_DESC
	mmi_rp_notify_output_phase2_desc_file();


}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_output_phase2_app_c_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_notify_output_phase2_app_c_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i =0, j = 0;
	mmi_rp_notify_data_struct *app_notify;//= &(g_mmi_rp_notify_cntx.app_notify_data[app_index]);
	MMI_BOOL zero_items = MMI_TRUE;
	
	/*----------------------------------------------------------------*/
	/* Code Body														*/
	/*----------------------------------------------------------------*/
	if(p_file)
	{
	  /* Check if no str IDs. */
	 	for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    	{
        	if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        	{
            	continue;
        	}

			if(g_mmi_rp_notify_cntx.app_notify_data[i].total_count != 0)
			{
				zero_items = MMI_FALSE;
				break;
			}	
	 	}

		if(zero_items)
		{
			MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
		}
		else
		{  
			 fprintf(p_file, "\n\n");
			 fprintf(p_file, "/******************** Notify info tbl ********************/\n");
			 fprintf(p_file, "nvram_input_event_notify_info nv_input_event_notify_tbl[] = \n{\n");
		
			for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
			{
				app_notify = &(g_mmi_rp_notify_cntx.app_notify_data[i]);

				if(app_notify->total_count != 0)
				{
					for(j=0; j<app_notify->total_count; j++)
					{
						fprintf(p_file, 
							"  {%s, %s, %s, %s},\n", 
							app_notify->notify_strings[j].notify_id_str,
							app_notify->notify_strings[j].led_id_str,
							app_notify->notify_strings[j].voice_id_str,
							app_notify->notify_strings[j].vib_id_str);		
					}

				}
				
				
			}

			fprintf(p_file, "};");
		}
	}
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

//
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_notify_output_phase2_desc_file
 * DESCRIPTION
 *  Output desc 
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_notify_output_phase2_desc_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FILE *p_file = NULL;
	U32 i =0, j = 0;
	mmi_rp_notify_data_struct *app_notify;//= &(g_mmi_rp_notify_cntx.app_notify_data[app_index]);
	MMI_BOOL zero_items = MMI_TRUE;
	
	/*----------------------------------------------------------------*/
	/* Code Body														*/
	/*----------------------------------------------------------------*/

	//mmi_rp_input_event_read_desc_info_from_tmp();
	
	/* 1. Output all APPs .c files. */
	 if((p_file = fopen(CUST_INPUT_EVENT_CFG_DESC, "a")) == NULL)
	 {
		 fprintf(stderr, "[Notify] output notify desc failed !!\n");
		 exit(0);
	 }
	
	 //write to nvarm cfg
	 if((p_file = fopen(CUST_INPUT_EVENT_CFG_DESC, "a"))== NULL)
	 {	 
	 	/* Error writing output file. Exit. */
		 MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);

	 }
	 else
	 {
		  /* Check if no str IDs. */
	 	for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    	{
        	if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        	{
            	continue;
        	}

			if(g_mmi_rp_notify_cntx.app_notify_data[i].total_count != 0)
			{
				zero_items = MMI_FALSE;
				break;
			}	
	 	}

		if(zero_items)
		{
			MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
		}
		else
		{  
			 fprintf(p_file, "\n\n");
			fprintf(p_file, "[Notify info desc]\n");

			for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
			{
				app_notify = &(g_mmi_rp_notify_cntx.app_notify_data[i]);

				if(app_notify->total_count != 0)
				{
					for(j=0; j<app_notify->total_count; j++)
					{
						fprintf(p_file, 
							"{%s, %s}\n", 
							app_notify->notify_strings[j].notify_id_str,
							app_notify->notify_strings[j].notify_desc_str);		
					}
				}		
			}

		}	 
		 fclose(p_file);
	 }	
}


/*input event*/
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_init
 * DESCRIPTION
 *  Initializes the template context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_input_event_init(void)
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


	memset(&g_mmi_rp_input_event_cntx, 0, sizeof(g_mmi_rp_input_event_cntx));
    g_mmi_rp_input_event_cntx.app_input_event_data = (mmi_rp_input_event_data_struct*)malloc(sizeof(mmi_rp_input_event_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

	if(!g_mmi_rp_input_event_cntx.app_input_event_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_input_event_cntx.app_input_event_data, 0, sizeof(mmi_rp_input_event_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_input_event_cntx.hash = mmi_rp_hash_create(0xFFFF); 
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_set_app_range
 * DESCRIPTION
 *  Initializes the template context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_input_event_set_app_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 range = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_RP_INPUT_EVENT_CURR_APP_STR.input_event_strings == NULL)
    {
        range = g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min + 1;
        MMI_RP_INPUT_EVENT_CURR_APP_STR.input_event_strings = (mmi_rp_input_event_struct*)malloc(sizeof(mmi_rp_input_event_struct) * range);

        if((!MMI_RP_INPUT_EVENT_CURR_APP_STR.input_event_strings) && (range > 0))
        {
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }

        memset(MMI_RP_INPUT_EVENT_CURR_APP_STR.input_event_strings, 0, sizeof(mmi_rp_input_event_struct) * range);
    }

}


    
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_start_handler
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
int mmi_rp_input_event_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   	kal_int32   index = 0;
    U8 *curr_grp_id = NULL;
	U8 *curr_grp_desc = NULL;
	U8 *curr_evt_id = NULL;
	U8 *curr_evt_desc = NULL;
	U8 *curr_key_code = NULL;
	U8 *curr_key_type = NULL;
	U8 default_str[] = "-1";
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("input event-start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
	
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if(strcmp(attr[index], MMI_RP_MGR_ATTR_GRP_ID) == 0)
        {
            curr_grp_id = (U8*)attr[index + 1];
        }
		else if(strcmp(attr[index], MMI_RP_MGR_ATTR_EVT_ID) == 0)
		{
			curr_evt_id = (U8*)attr[index + 1];
		}
		else if(strcmp(attr[index], MMI_RP_MGR_ATTR_KEY_CODE) == 0)
		{
			curr_key_code = (U8*)attr[index + 1];
		}
		else if(strcmp(attr[index], MMI_RP_MGR_ATTR_KEY_TYPE) == 0)
		{
			curr_key_type = (U8*)attr[index + 1];
		}
		else if(strcmp(attr[index], MMI_RP_MGR_ATTR_GRP_DESC) == 0)
		{
			curr_grp_desc = (U8*)attr[index + 1];
		}
		else if(strcmp(attr[index], MMI_RP_MGR_ATTR_EVT_DESC) == 0)
		{
			curr_evt_desc = (U8*)attr[index + 1];
		}		
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        index += 2;
    }

    if(curr_grp_id != NULL && curr_evt_id != NULL)
    {   
    	if(curr_key_code == NULL)
    	{
			curr_key_code = default_str;
		}

		if(curr_key_type == NULL)
		{
			curr_key_type = default_str;
		}

		if(curr_grp_desc == NULL)
		{
			curr_grp_desc = curr_grp_id;
		}

		if(curr_evt_desc == NULL)
		{
			curr_evt_desc = curr_evt_id;
		}
		
		MMI_RP_INPUT_EVENT_CURR_APP_STR.input_event_strings[MMI_RP_INPUT_EVENT_CURR_APP_STR.total_count].grp_id_str = mmi_rp_hash_add(g_mmi_rp_input_event_cntx.hash, curr_grp_id);
		MMI_RP_INPUT_EVENT_CURR_APP_STR.input_event_strings[MMI_RP_INPUT_EVENT_CURR_APP_STR.total_count].grp_desc_str = mmi_rp_hash_add(g_mmi_rp_input_event_cntx.hash, curr_grp_desc);

		MMI_RP_INPUT_EVENT_CURR_APP_STR.input_event_strings[MMI_RP_INPUT_EVENT_CURR_APP_STR.total_count].evt_id_str = mmi_rp_hash_add(g_mmi_rp_input_event_cntx.hash, curr_evt_id);
		MMI_RP_INPUT_EVENT_CURR_APP_STR.input_event_strings[MMI_RP_INPUT_EVENT_CURR_APP_STR.total_count].evt_desc_str = mmi_rp_hash_add(g_mmi_rp_input_event_cntx.hash, curr_evt_desc);
		
        MMI_RP_INPUT_EVENT_CURR_APP_STR.input_event_strings[MMI_RP_INPUT_EVENT_CURR_APP_STR.total_count].key_code_str = mmi_rp_hash_add(g_mmi_rp_input_event_cntx.hash, curr_key_code);
        MMI_RP_INPUT_EVENT_CURR_APP_STR.input_event_strings[MMI_RP_INPUT_EVENT_CURR_APP_STR.total_count].key_type_str = mmi_rp_hash_add(g_mmi_rp_input_event_cntx.hash, curr_key_type);

		MMI_RP_INPUT_EVENT_CURR_APP_STR.total_count++;


	}
    else
    {
        MMI_RP_PARSE_WARNING(RP_WARN_RES_ID_NULL);
    }
	
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_notify_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_input_event_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("input event -end: %s\n", el);
    
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
int mmi_rp_input_event_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("input event -data: %s\n", data);

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
 *  mmi_rp_notify_filter
 * DESCRIPTION
 *  This function is for resgen to filter your resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_input_event_filter(void)
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
 *  mmi_rp_notify_output_phase1
 * DESCRIPTION
 *  Output IDs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_input_event_output_phase1(void)
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
      //      mmi_rp_notify_output_phase1_app_def_h_file(i, p_file);
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


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_notify_output_phase1_app_def_h_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_input_event_output_phase1_app_def_h_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i =0;
	 U8 str_enum_name[MMI_RP_OUTPUT_ENUM_NAME_MAX], str_enum_max[MMI_RP_OUTPUT_ENUM_NAME_MAX];
	 MMI_BOOL first = MMI_TRUE;
	S32 app_enum_log_counter = -1; 	 /* -1 for debug purpose */
	
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 if(p_file)
	 {
	
	 }

    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_output_phase2
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_input_event_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0;	
	U32 total = 0;
    MMI_BOOL first = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
	/* 1. Output all APPs .c files. */
	if((p_file = fopen(CUST_INPUT_EVENT_CFG_SRC_DST, "a")) == NULL)
	{
        fprintf(stderr, "[Notify] output file nvram_input_event_cfg.h open failed !!\n");
        exit(0);
	}
	
 
	
	/*2. output .h*/

	if(p_file = fopen(CUST_INPUT_EVENT_CFG_SRC_DST, "a"))            
	{
		

		mmi_rp_input_event_output_phase2_app_c_file(0, p_file);

		
		fclose(p_file);
	}
	else
	{
		/* Error writing output file. Exit. */
		MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
	}

	//write to cfg.h

	 /* 1. Output all APPs .c files. */
	if((p_file = fopen(CUST_INPUT_EVENT_CFG_INC_CONST_DST, "a")) == NULL)
	{
        fprintf(stderr, "[Notify] output file nvram_input_event_cfg.h open failed !!\n");
        exit(0);
	}
	
 
	
	/*2. output .c*/
	total  = 0;

	if(p_file = fopen(CUST_INPUT_EVENT_CFG_INC_CONST_DST, "a"))            
	{
		
		for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    	{
        	if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        	{
            	continue;
        	}

			total += g_mmi_rp_input_event_cntx.app_input_event_data[i].total_count;	
	 	}
		//mmi_rp_app_info_output_phase2_app_c_file(0, p_file);
		fprintf(p_file, "\n");
		fprintf(p_file, "/*************************input event total number************************/\n");
		fprintf(p_file, "#define INPUT_EVENT_MAX_EVT %d\n\n", total);
		
		fclose(p_file);
	}
	else
	{
		/* Error writing output file. Exit. */
		MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
	}

    mmi_rp_input_event_output_phase2_desc_file();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_output_phase2_app_c_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_input_event_output_phase2_app_c_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i =0, j = 0;
	mmi_rp_input_event_data_struct *input_event_notify;//= &(g_mmi_rp_notify_cntx.app_notify_data[app_index]);
	MMI_BOOL zero_items = MMI_TRUE;
	
	/*----------------------------------------------------------------*/
	/* Code Body														*/
	/*----------------------------------------------------------------*/
	if(p_file)
	{
	  /* Check if no str IDs. */
	 	for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    	{
        	if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        	{
            	continue;
        	}

			if(g_mmi_rp_input_event_cntx.app_input_event_data[i].total_count != 0)
			{
				zero_items = MMI_FALSE;
				break;
			}	
	 	}

		if(zero_items)
		{
			MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
		}
		else
		{  
			 fprintf(p_file, "\n\n");
			 fprintf(p_file, "/******************** input event tbl ********************/\n");
			 fprintf(p_file, "nvram_input_event_evt_info nv_input_event_evt_info_tbl[] = \n{\n");
		
			for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
			{
				input_event_notify = &(g_mmi_rp_input_event_cntx.app_input_event_data[i]);

				if(input_event_notify->total_count != 0)
				{
					for(j=0; j<input_event_notify->total_count; j++)
					{
						fprintf(p_file, 
							"  {%s, %s, %s, %s},\n", 
							input_event_notify->input_event_strings[j].grp_id_str,
							input_event_notify->input_event_strings[j].evt_id_str,
							input_event_notify->input_event_strings[j].key_code_str,
							input_event_notify->input_event_strings[j].key_type_str);		
					}

				}
				
				
			}

			fprintf(p_file, "};");
		}
	}
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}    

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_output_phase2_desc_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_input_event_output_phase2_desc_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FILE *p_file = NULL;
	U32 i =0, j = 0;
	mmi_rp_input_event_data_struct *input_event_notify;//= &(g_mmi_rp_notify_cntx.app_notify_data[app_index]);
	MMI_BOOL zero_items = MMI_TRUE;
	
	/*----------------------------------------------------------------*/
	/* Code Body														*/
	/*----------------------------------------------------------------*/
	if((p_file = fopen(CUST_INPUT_EVENT_CFG_DESC, "a")) != NULL)
	{
	  /* Check if no str IDs. */
	 	for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    	{
        	if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        	{
            	continue;
        	}

			if(g_mmi_rp_input_event_cntx.app_input_event_data[i].total_count != 0)
			{
				zero_items = MMI_FALSE;
				break;
			}	
	 	}

		if(zero_items)
		{
			MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
		}
		else
		{  
			 fprintf(p_file, "\n\n");
			 fprintf(p_file, "[Event info desc]\n");
		
			for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
			{
				input_event_notify = &(g_mmi_rp_input_event_cntx.app_input_event_data[i]);

				if(input_event_notify->total_count != 0)
				{
					for(j=0; j<input_event_notify->total_count; j++)
					{
						fprintf(p_file, 
							"{{%s, %s}, {%s, %s}}\n", 
							input_event_notify->input_event_strings[j].grp_id_str,
							input_event_notify->input_event_strings[j].grp_desc_str,							
							input_event_notify->input_event_strings[j].evt_id_str,
							input_event_notify->input_event_strings[j].evt_desc_str);		
					}
				}	
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



/*app info*/
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_init
 * DESCRIPTION
 *  Initializes the template context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_app_info_init(void)
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


	memset(&g_mmi_rp_app_info_cntx, 0, sizeof(g_mmi_rp_app_info_cntx));
    g_mmi_rp_app_info_cntx.app_info_data = (mmi_rp_app_info_data_struct*)malloc(sizeof(mmi_rp_app_info_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

	if(!g_mmi_rp_app_info_cntx.app_info_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_app_info_cntx.app_info_data, 0, sizeof(mmi_rp_app_info_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_app_info_cntx.hash = mmi_rp_hash_create(0xFFFF); 
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_set_app_range
 * DESCRIPTION
 *  Initializes the template context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_app_info_set_app_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 range = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_RP_APP_INFO_CURR_APP_STR.app_info_strings == NULL)
    {
        range = g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min + 1;
        MMI_RP_APP_INFO_CURR_APP_STR.app_info_strings = (mmi_rp_app_info_struct*)malloc(sizeof(mmi_rp_app_info_struct) * range);

        if((!MMI_RP_APP_INFO_CURR_APP_STR.app_info_strings) && (range > 0))
        {
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }

        memset(MMI_RP_APP_INFO_CURR_APP_STR.app_info_strings, 0, sizeof(mmi_rp_app_info_struct) * range);
    }

}


    
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_start_handler
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
int mmi_rp_app_info_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   	kal_int32   index = 0;
    U8 *curr_app_indx = NULL;
	U8 *curr_grp_id = NULL;
	U8 *curr_launch_evt = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("app info-start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if(strcmp(attr[index], MMI_RP_MGR_ATTR_APP_INDEX) == 0)
        {
            curr_app_indx = (U8*)attr[index + 1];
        }
		else if(strcmp(attr[index], MMI_RP_MGR_ATTR_GRP_ID) == 0)
		{
			curr_grp_id = (U8*)attr[index + 1];
		}
		else if(strcmp(attr[index], MMI_RP_MGR_ATTR_APP_LAUNCH_EVT) == 0)
		{
			curr_launch_evt= (U8*)attr[index + 1];
		}
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        index += 2;
    }

    if(curr_app_indx != NULL && 
		curr_grp_id != NULL &&
		curr_launch_evt != NULL)
	{
        MMI_RP_APP_INFO_CURR_APP_STR.app_info_strings[MMI_RP_APP_INFO_CURR_APP_STR.total_count].app_indx_str = mmi_rp_hash_add(g_mmi_rp_app_info_cntx.hash, curr_app_indx);
		MMI_RP_APP_INFO_CURR_APP_STR.app_info_strings[MMI_RP_APP_INFO_CURR_APP_STR.total_count].grp_id_str = mmi_rp_hash_add(g_mmi_rp_app_info_cntx.hash, curr_grp_id);
        MMI_RP_APP_INFO_CURR_APP_STR.app_info_strings[MMI_RP_APP_INFO_CURR_APP_STR.total_count].launch_evt_str = mmi_rp_hash_add(g_mmi_rp_app_info_cntx.hash, curr_launch_evt);

		MMI_RP_APP_INFO_CURR_APP_STR.total_count++;
    }
    else
    {
        MMI_RP_PARSE_WARNING(RP_WARN_RES_ID_NULL);
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_notify_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_app_info_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("app info -end: %s\n", el);
    
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
int mmi_rp_app_info_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("app info -data: %s\n", data);

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
 *  mmi_rp_notify_filter
 * DESCRIPTION
 *  This function is for resgen to filter your resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_app_info_filter(void)
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
 *  mmi_rp_notify_output_phase1
 * DESCRIPTION
 *  Output IDs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_app_info_output_phase1(void)
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
           // mmi_rp_notify_output_phase1_app_def_h_file(i, p_file);
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


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_notify_output_phase1_app_def_h_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_app_info_output_phase1_app_def_h_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i =0;
	 U8 str_enum_name[MMI_RP_OUTPUT_ENUM_NAME_MAX], str_enum_max[MMI_RP_OUTPUT_ENUM_NAME_MAX];
	 MMI_BOOL first = MMI_TRUE;
	 S32 app_enum_log_counter = -1; 	 /* -1 for debug purpose */
	
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 if(p_file)
	 {

	 }

    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_template_output_phase2
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_app_info_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0;	
	U32 total = 0;
    MMI_BOOL first = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
	   /* 1. Output all APPs .c files. */
	if((p_file = fopen(CUST_INPUT_EVENT_CFG_SRC_DST, "a")) == NULL)
	{
        fprintf(stderr, "[Notify] output file nvram_input_event_cfg.h open failed !!\n");
        exit(0);
	}
		
	/*2. output .c*/

	if(p_file = fopen(CUST_INPUT_EVENT_CFG_SRC_DST, "a"))            
	{
		mmi_rp_app_info_output_phase2_app_c_file(0, p_file);

		fclose(p_file);
	}
	else
	{
		/* Error writing output file. Exit. */
		MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
	}


	 /* 1. Output all APPs .c files. */
	if((p_file = fopen(CUST_INPUT_EVENT_CFG_INC_CONST_DST, "a")) == NULL)
	{
        fprintf(stderr, "[Notify] output file nvram_input_event_const.h open failed !!\n");
        exit(0);
	}
		
	/*2. output .c*/
	if(p_file = fopen(CUST_INPUT_EVENT_CFG_INC_CONST_DST, "a"))            
	{
		
		for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    	{
        	if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        	{
            	continue;
        	}

			total += g_mmi_rp_app_info_cntx.app_info_data[i].total_count;	
	 	}
		//mmi_rp_app_info_output_phase2_app_c_file(0, p_file);
		fprintf(p_file, "\n");
		fprintf(p_file, "/************************local app total number****************************/\n");
		fprintf(p_file, "#define INPUT_EVENT_TOTAL_LOCAL_APP %d\n\n", total);
		fprintf(p_file, "#endif//#define NVRAM_INPUT_EVENT_CONST_H\n");
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
 *  mmi_rp_template_output_phase2_app_c_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_app_info_output_phase2_app_c_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i =0, j = 0;
	mmi_rp_app_info_data_struct *app_info;//= &(g_mmi_rp_notify_cntx.app_notify_data[app_index]);
	MMI_BOOL zero_items = MMI_TRUE;

	U8 str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
	
	/*----------------------------------------------------------------*/
	/* Code Body														*/
	/*----------------------------------------------------------------*/
	if(p_file)
	{
	  /* Check if no str IDs. */
	 	for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    	{
        	if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        	{
            	continue;
        	}

			if(g_mmi_rp_app_info_cntx.app_info_data[i].total_count != 0)
			{
				zero_items = MMI_FALSE;
				break;
			}	
	 	}

		if(zero_items)
		{
			MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
		}
		else
		{  
			 fprintf(p_file, "\n\n");
			 fprintf(p_file, "/******************** app info tbl ********************/\n");
			 fprintf(p_file, "nvram_input_event_local_app_info nv_input_event_local_app_info_tbl[] = \n{\n");
		
			for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
			{
				app_info = &(g_mmi_rp_app_info_cntx.app_info_data[i]);

				if(app_info->total_count != 0)
				{
					for(j=0; j<app_info->total_count; j++)
					{
						fprintf(p_file, 
							"  {%s, %s, %s},\n", 
							app_info->app_info_strings[j].app_indx_str,
							app_info->app_info_strings[j].grp_id_str,
							app_info->app_info_strings[j].launch_evt_str);		
					}

				}
				
				
			}

			fprintf(p_file, "};\n\n");
		//	fprintf(p_file, "#endif//#define MMI_FRM_INPUT_EVENT_CFG_H\n");
		}
	}
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }


	/**/
	    /* 2. Output all info to xml file. */
    memset(str_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_filename, CUST_INPUT_EVENT_CFG_XML_DST);
    
    if(p_file = fopen(str_filename, "a"))           
    {
       // mmi_rp_input_event_output_phase2_all_info(p_file);
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
	
}
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/

