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
 *  mmi_rp_cust_template.c
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
#include "mmi_rp_cust_template.h"


extern const mmi_resource_base_struct g_mmi_resource_base_table[];

static void mmi_rp_template_output_phase1_app_def_h_file(U32 app_index, FILE *p_file);
#ifndef __RESGEN_INTERNAL_POP_FILE_REDUCE__
static void mmi_rp_template_output_phase2_app_c_file(U32 app_index, FILE *p_file);
#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
static void mmi_rp_template_output_phase2_app_c_file(U32 app_index);
#endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__

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
void mmi_rp_template_init(void)
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
void mmi_rp_template_set_app_range(void)
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
int mmi_rp_template_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32   index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Template -start: %s\n", el);
    
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
        printf("%s = %s\n", attr[index], attr[index + 1]);
        
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
 *  mmi_rp_template_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_template_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Template -end: %s\n", el);
    
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
int mmi_rp_template_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Template -data: %s\n", data);

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
 *  mmi_rp_template_filter
 * DESCRIPTION
 *  This function is for resgen to filter your resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_template_filter(void)
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
 *  mmi_rp_template_output_phase1
 * DESCRIPTION
 *  Output IDs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_template_output_phase1(void)
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
            mmi_rp_template_output_phase1_app_def_h_file(i, p_file);
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
 *  mmi_rp_template_output_phase1_app_def_h_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_template_output_phase1_app_def_h_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        fprintf(p_file, "/******************** Template resource IDs - Begin ********************/\n");
        /* Output your IDs here */
        ///TODO: output IDs
        fprintf(p_file, "/******************** Template resource IDs - End ********************/\n");
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }
}

#ifndef __RESGEN_INTERNAL_POP_FILE_REDUCE__

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
void mmi_rp_template_output_phase2(void)
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
            mmi_rp_template_output_phase2_app_c_file(i, p_file);
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
 *  mmi_rp_template_output_phase2_app_c_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file         [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_template_output_phase2_app_c_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        /* There's no current requirement to populate Template resources in .c files. */
        /* Keep it here for future reference. */
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
 *  mmi_rp_template_output_phase2
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_template_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    MMI_BOOL has_resource_to_populate = MMI_FALSE;

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
        
        // If there is output required for the app, invoke mmi_rp_template_output_phase2_app_c_file.
        if(has_resource_to_populate){
            mmi_rp_template_output_phase2_app_c_file(i);
        }
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
static void mmi_rp_template_output_phase2_app_c_file(U32 app_index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE * p_file = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* There's no current requirement to populate Template resources in .c files. */
    /* Keep it here for future reference. */

    // Use mmi_rp_open_population_c_file to open resource population output file for AP.
    // Don't use fopen API to open the file whose name is calculated with mmi_rp_mgr_contruct_name.
    // Such codes may corrupted the entire resgen system.
    p_file = mmi_rp_open_population_c_file(app_index, RES_LEGACY_POP_SCREEN_MASK);        

    if(p_file == NULL)
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
      
}

#endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__

