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
 *  mmi_rp_xml.c
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
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
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
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#define  RESGEN_XML_C

#define WIN32_LEAN_AND_MEAN
#include "windows.h"

#include <stdio.h>
#ifdef RESXML_VC_DEBUG
#include <conio.h>
#endif
#include <stdlib.h>

#include "MMIDataType.h"
#include "CustResDef.h"

#include "mmi_rp_hash.h"
#include "mmi_rp_xml.h"
#include "mmi_rp_xml_def.h"
#include "mmi_rp_res_list.h"

#include "mmi_res_range_def.h"
#include "CustDataRes.h" // for MMI_RG_RES_BASE_TABLE_FILE

#define MAX_RES_FILE_NAME_SIZE 512

static void mmi_rp_mgr_init(void);
static void mmi_rp_mgr_deinit(void);
static void mmi_rp_mgr_parser(void);
static void mmi_rp_mgr_filter(void);
static void mmi_rp_mgr_output(void);
static void mmi_rp_mgr_output_start(void);
static void mmi_rp_mgr_output_end(void);
static void mmi_rp_output_phase2_finish_reduce();

static void mmi_rp_compare_output_files(void);

mmi_rp_mgr_parser_context_struct g_mmi_rp_mgr_cntx;
mmi_rp_mgr_tag_callback *g_res_handlers = NULL;
U8 g_cur_filename[512];
FILE *g_output_log_file = NULL;
FILE *g_mmi_rp_output_enum_log_file = NULL;

BOOL g_mmi_rp_is_in_parse_phase = FALSE;

// xml parse error handling
S32 g_mmi_rp_error_stack_top = -1;



// Stack Push and pop operation

static void mmi_rp_mgr_stack_push(S32 tag)
{
    if(g_mmi_rp_mgr_cntx.parent_tags.top >= MMI_RP_MGR_TAG_STACK_MAX)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_TAG_STACK_OVERFLOW);
    }
    else
    {
        g_mmi_rp_mgr_cntx.parent_tags.tag[g_mmi_rp_mgr_cntx.parent_tags.top] = tag;
        g_mmi_rp_mgr_cntx.parent_tags.top++;
    }
}

static void mmi_rp_mgr_stack_pop()
{
    if(g_mmi_rp_mgr_cntx.parent_tags.top >= 0)
    {
        g_mmi_rp_mgr_cntx.parent_tags.top--;
    }
    else
    {
        MMI_RP_FATAL_ERROR(RP_ERR_TAG_STACK_UNDERFLOW);
    }
}

static S32 mmi_rp_mgr_stack_tag_count()
{
    return g_mmi_rp_mgr_cntx.parent_tags.top;
}

const S8* mmi_rp_mgr_stack_top_tag_name()
{
    if(g_mmi_rp_mgr_cntx.parent_tags.top > 0)
    {
        S32 top = g_mmi_rp_mgr_cntx.parent_tags.tag[g_mmi_rp_mgr_cntx.parent_tags.top - 1];
        return g_res_handlers[top].tag_name;
    }
    else
    {
        MMI_RP_ERROR(RP_ERR_TAG_STACK_UNDERFLOW);
        return "";
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_write_copy_right_header_in_file
 * DESCRIPTION
 *  Writes the copy right header in an autogenerated file.
 * PARAMETERS
 *  file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_write_copy_right_header_in_file(FILE *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fputs("/*****************************************************************************\n", file);
    fputs("*  Copyright Statement:\n",  file);
    fputs("*  --------------------\n", file);
    fputs("*  This software is protected by Copyright and the information contained\n", file);
    fputs("*  herein is confidential. The software may not be copied and the information\n", file);
    fputs("*  contained herein may not be used or disclosed except with the written\n", file);
    fputs("*  permission of MediaTek Inc. (C) 2005\n", file);
    fputs("*\n", file);
    fputs("*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES\n", file);
    fputs("*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS (\"MEDIATEK SOFTWARE\")\n", file);
    fputs("*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON\n", file);
    fputs("*  AN \"AS-IS\" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,\n", file);
    fputs("*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF\n", file);
    fputs("*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.\n", file);
    fputs("*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE\n", file);
    fputs("*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR\n", file);
    fputs("*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH\n", file);
    fputs("*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO\n", file);
    fputs("*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S\n", file);
    fputs("*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.\n", file);
    fputs("*\n", file);
    fputs("*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE\n", file);
    fputs("*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,\n", file);
    fputs("*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,\n", file);
    fputs("*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO\n", file);
    fputs("*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. \n", file);
    fputs("*\n", file);
    fputs("*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE\n", file);
    fputs("*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF\n", file);
    fputs("*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND\n", file);
    fputs("*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER\n", file);
    fputs("*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).\n", file);
    fputs("*\n", file);
    fputs("*****************************************************************************/\n", file);
    fputs("\n", file);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_write_file_header_in_file
 * DESCRIPTION
 *  Writes the file header in an autogenerated file.
 * PARAMETERS
 *  file
 *  filename        [IN]    output file name
 *  desc            [IN]    Description
 *  autor           [IN]    author
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_write_file_header_in_file(FILE *file, S8 *filename, S8 *desc, S8 *author)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fputs("/*******************************************************************************\n", file);
    fputs(" * Filename:\n", file);
    fputs(" * ---------\n", file);
    fprintf( file, " *   %s\n", filename);
    fputs(" *\n", file);
    fputs(" * Project:\n", file);
    fputs(" * --------\n", file);
    fputs(" *   MAUI\n", file);
    fputs(" *\n", file);
    fputs(" * Description:\n", file);
    fputs(" * ------------\n", file);
    fprintf( file, " *   %s\n", desc);
    fputs(" *\n", file);
    fputs(" * Author:\n", file);
    fputs(" * -------\n", file);
    fprintf( file, " *   %s\n", author);
    fputs(" *\n", file);
    fputs(" *******************************************************************************/\n", file);
}



/*****************************************************************************
* FUNCTION
*  mmi_rp_output_phase1_begin
* DESCRIPTION
*  File write begin - output phase 1
* PARAMETERS
*  p_file  [IN]    output file pointer
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_output_phase1_begin(FILE* p_file, U8 *str_header_guard)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        fprintf(p_file, "\n\n");
        fprintf(p_file, "#ifndef %s\n", str_header_guard);
        fprintf(p_file, "#define %s\n", str_header_guard);
        fprintf(p_file, "\n\n");
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_output_phase1_finish
* DESCRIPTION
*  File write finish - output phase 1
* PARAMETERS
*  p_file  [IN]    output file pointer
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_output_phase1_finish(FILE *p_file, U8 *str_header_guard)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        fprintf(p_file, "\n\n");
        fprintf(p_file, "#endif /* %s */\n", str_header_guard);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_output_phase2_begin
* DESCRIPTION
*  File write begin - output phase 2
* PARAMETERS
*  p_file      [IN]    output file pointer
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_output_phase2_begin(FILE *p_file, U8 *str_function_name, U8 *str_header_file_name, U8* str_app_include_file_names)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        U8 *temp1 = NULL;
        MMI_BOOL has_include = MMI_FALSE;

        fprintf(p_file, "#include \"CustDataProts.h\"\n");

        /* If there's no header file, don't print it. */
        if(str_header_file_name && (*str_header_file_name != '\0'))
        {
            fprintf(p_file, "#include \"%s\"\n", str_header_file_name);
        }

        /* Application specified header files for old res IDs */
        /* ",   H1.h   , ,   H2.h , " */
        fprintf(p_file, "\n/* Application specified header files for using old res IDs */\n");

        // check if the .res file contains include tag
        temp1 = str_app_include_file_names;
        if(temp1 && (*temp1 != '\0'))
        {
            /* Ignoring initial spaces and commas */
            while(*temp1 && (*temp1 == ' ' || *temp1 == ','))
            {
                temp1++;
            }
            if (*temp1 != '\0')
            {
                has_include = MMI_TRUE;
            }
        }

        if (has_include)
        {
            fprintf(p_file, "#include \"MMI_features.h\"\n");
            fprintf(p_file, "#include \"MMIDataType.h\"    /* for resource base */\n\n");

            fprintf(p_file, "#include \"CustResDef.h\"         /* for image/audio path */\n");
            fprintf(p_file, "#include \"GlobalMenuItems.h\"    /* for menu resource */\n\n");

            while(*temp1)
            {
                fprintf(p_file, "#include \"");
                while(*temp1 && (*temp1 != ' ' && *temp1 != ','))
                {
                    fprintf(p_file, "%c", *temp1);
                    temp1++;
                }
                fprintf(p_file, "\"\n");

                /* Ignoring trailing spaces and commas */
                while(*temp1 && (*temp1 == ' ' || *temp1 == ','))
                {
                    temp1++;
                }
            }
        }

        fprintf(p_file, "\n\n");

        fprintf(p_file, "/*****************************************************************************\n");
        fprintf(p_file, "* FUNCTION\n");
        fprintf(p_file, "*  %s\n", str_function_name);
        fprintf(p_file, "* DESCRIPTION\n");
        fprintf(p_file, "*  Automatically generated populate function for %s\n", str_function_name);
        fprintf(p_file, "* PARAMETERS\n");
        fprintf(p_file, "*  void\n");
        fprintf(p_file, "* RETURNS\n");
        fprintf(p_file, "*  void\n");
        fprintf(p_file, "*****************************************************************************/\n");

        fprintf(p_file, "void %s(void)\n", str_function_name);
        fprintf(p_file, "{\n");
        fprintf(p_file, "    /*----------------------------------------------------------------*/\n");
        fprintf(p_file, "    /* Local Variables                                                */\n");
        fprintf(p_file, "    /*----------------------------------------------------------------*/\n");
        fprintf(p_file, "\n");
        fprintf(p_file, "    /*----------------------------------------------------------------*/\n");
        fprintf(p_file, "    /* Code Body                                                      */\n");
        fprintf(p_file, "    /*----------------------------------------------------------------*/\n");
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_rp_output_phase2_finish
* DESCRIPTION
*  File write finish - output phase 2
* PARAMETERS
*  p_file      [IN]    output file pointer
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_output_phase2_finish(FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        fprintf(p_file, "}\n");
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_rp_output_phase2_finish
* DESCRIPTION
*  File write finish - output phase 2
* PARAMETERS
*  p_file      [IN]    output file pointer
* RETURNS
*  void
*****************************************************************************/
void mmi_rp_output_phase2_finish_reduce()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    U8 *str_output_filename = NULL, *str_header_guard = NULL;
    U8 str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    U8 temp_group_name[MMI_RP_IMG_GROUP_ID_MAX];
    CHAR * str_output_filename_header =NULL;
    CHAR * str_function_name = NULL;
    printf("mmi_rp_output_phase2_finish_reduce\n");
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

        str_output_filename = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_C_FILE_PATH, g_mmi_resource_base_table[i].appname);
        /* Header file name*/
        str_output_filename_header = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_H_FILE, g_mmi_resource_base_table[i].appname);
        /* Populate function name */
        str_function_name = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_POPULATE_FUNCTION, g_mmi_resource_base_table[i].appname);

        printf("Finisheing %s\n", str_output_filename);
        
        if(g_mmi_rp_mgr_cntx.populating_file_created[i]!=RES_LEGACY_POP_NON){
            printf("Finished %s\n", str_output_filename);
            
            if(p_file = fopen(str_output_filename, "a"))            /* Rest resources will open the file in append mode */
            {
                fprintf(p_file, "}\n");
            }
            else
            {
                /* Error writing output file. Exit. */
                MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
            }
            fclose(p_file);
        }
            
    }

}

/*****************************************************************************
* FUNCTION
*  mmi_rp_mgr_on_exit
* DESCRIPTION
*  program exit function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_rp_mgr_on_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef RESXML_VC_DEBUG
    printf("\nPress any key to exit!\n");
    getch();
#endif
    if (g_mmi_rp_mgr_cntx.program_error == 1)  // normal exit
    {
        _exit(1);
    }
    else                // abnormal exit
    {
        _exit(2);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_create_temp_folders
 * DESCRIPTION
 *  This function is to create the temp folders
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mgr_create_temp_folders(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 sys_str[MMI_RP_MGR_MAX_SYS_CMD_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(sys_str, 0, MMI_RP_MGR_MAX_SYS_CMD_LEN);
    sprintf(sys_str, "if not exist %s md %s > nul", MMI_RP_MGR_XML_TEMP_CMP_H_FILES, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    system(sys_str);

    memset(sys_str, 0, MMI_RP_MGR_MAX_SYS_CMD_LEN);
    sprintf(sys_str, "if not exist %s md %s > nul", MMI_RP_MGR_XML_TEMP_CMP_C_FILES, MMI_RP_MGR_XML_TEMP_CMP_C_FILES);
    system(sys_str);

    memset(sys_str, 0, MMI_RP_MGR_MAX_SYS_CMD_LEN);
    sprintf(sys_str, "if not exist %s md %s > nul", MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES, MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES);
    system(sys_str);
}


/*****************************************************************************
* FUNCTION
*  main
* DESCRIPTION
*  program main function
* PARAMETERS
*  argc       [IN]   parameter count
*  argv       [IN]   parameter list
* RETURNS
*  void
*****************************************************************************/
int main(int argc, char *argv[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef RESXML_VC_DEBUG
    U8 tmpbuf[1024*4];
#endif
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set program exit */
    atexit(mmi_rp_mgr_on_exit);
    g_mmi_rp_mgr_cntx.program_error = -1;

#ifndef RESXML_VC_DEBUG
    if((argc==2) && strcmp(argv[1], "-p")==0)
#endif
    {
        printf("MediaTek Resource Generate System 2.0\n");

        mmi_rp_mgr_create_temp_folders();

        mmi_rp_mgr_init();

        g_mmi_rp_is_in_parse_phase = TRUE;

        mmi_rp_mgr_parser();

        g_mmi_rp_is_in_parse_phase = FALSE;

        printf("\nXML Parser ~ performing resource filter!\n");
        mmi_rp_mgr_filter();
        printf("\nXML Parser ~ resource filter finished!\n");

        printf("\nXML Parser ~ Starting output files!\n");
        mmi_rp_mgr_output();
        printf("\nXML Parser ~ Finished output files!\n");

        printf("\nXML Parser ~ Comparing output files ~ Begin!\n");
        mmi_rp_compare_output_files();
        printf("\nXML Parser ~ Comparing output files ~ Finish!\n");

        printf("\nXML Parser Successful!\n");

        mmi_rp_mgr_deinit();

        if (g_mmi_rp_mgr_cntx.program_error == -1)
        {
            g_mmi_rp_mgr_cntx.program_error = 1;
        }
        return 1;
    }
#ifndef RESXML_VC_DEBUG
    else if((argc==2 || argc==3) && strcmp(argv[1], "-c")==0)
    {
        // output res base table, the only data that must come from .c
        mmi_rp_mgr_output_res_base_table();

        // Copy files from APP folder, APP folder is defined in mmi_res_range_def.h
        printf("Copy APP's res file to specify folder. \n");
        if (argc==3 && strcmp(argv[2], "-v") == 0)
        {
            system("..\\..\\..\\" "tools\\python25\\python resgen_xml_copy.py -v");
        }
        else
        {
            system("..\\..\\..\\" "tools\\python25\\python resgen_xml_copy.py");
        }

        if (g_mmi_rp_mgr_cntx.program_error == -1)
        {
            g_mmi_rp_mgr_cntx.program_error = 1;
        }
        return 1;
    }
#endif

    printf("\nUsage: resgen_xml -c : Copy *.res files from app folder to specify folder.\n");
    printf("\n       resgen_xml -p : Parse all .i files in specify folder.\n");
    return 0;
    
}

void mmi_rp_end_function(void)
{
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_init
 * DESCRIPTION
 *  This function is for manager to init all data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Find last item of tags, get count of tags */
    g_mmi_rp_mgr_cntx.total_apps = sizeof(g_mmi_resource_base_table)/sizeof(mmi_resource_base_struct);
    if(g_mmi_rp_mgr_cntx.total_apps  <= 0)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_APP_UNKNOWN);
    }

    /* prepare standard + cust res array */
    g_mmi_rp_mgr_cntx.tag_count =
        sizeof(g_res_handlers_standard) / sizeof(mmi_rp_mgr_tag_callback) +
        sizeof(g_res_tag_handlers_cust) / sizeof(mmi_rp_mgr_tag_callback) - 1;
    g_res_handlers = malloc(sizeof(mmi_rp_mgr_tag_callback) * (g_mmi_rp_mgr_cntx.tag_count));
    if(g_res_handlers == NULL)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }

    {
        S32 i, j;
        j = i = sizeof(g_res_handlers_standard) / sizeof(mmi_rp_mgr_tag_callback) - 1;
        memcpy(g_res_handlers, g_res_handlers_standard, i*sizeof(mmi_rp_mgr_tag_callback));

        i = sizeof(g_res_tag_handlers_cust) / sizeof(mmi_rp_mgr_tag_callback) - 1;
        memcpy(&(g_res_handlers[j]), g_res_tag_handlers_cust, i*sizeof(mmi_rp_mgr_tag_callback));
    }

    g_mmi_rp_mgr_cntx.app_populated = NULL;
    g_mmi_rp_mgr_cntx.app_populated = (MMI_BOOL*)malloc(sizeof(MMI_BOOL) * g_mmi_rp_mgr_cntx.total_apps);
    g_mmi_rp_mgr_cntx.app_res_filepath = (char **)malloc(sizeof(char *) * g_mmi_rp_mgr_cntx.total_apps);

    if(g_mmi_rp_mgr_cntx.app_populated == NULL)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mgr_cntx.app_populated, 0, (sizeof(MMI_BOOL) * g_mmi_rp_mgr_cntx.total_apps));

    // Initialize populating_file_created attribute of each AP  
    // Frederic: check leak!!
    g_mmi_rp_mgr_cntx.populating_file_created = NULL;
    g_mmi_rp_mgr_cntx.populating_file_created = (U8*)malloc(sizeof(U8) * g_mmi_rp_mgr_cntx.total_apps);

    if(g_mmi_rp_mgr_cntx.populating_file_created == NULL)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mgr_cntx.populating_file_created, RES_LEGACY_POP_NON, (sizeof(U8) * g_mmi_rp_mgr_cntx.total_apps));


    g_mmi_rp_mgr_cntx.app_include = (U8**)malloc(sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps);
    if(g_mmi_rp_mgr_cntx.app_include == NULL)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mgr_cntx.app_include, 0, (sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps));

    g_mmi_rp_mgr_cntx.app_type = (U8**)malloc(sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps);
    if(g_mmi_rp_mgr_cntx.app_type == NULL)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mgr_cntx.app_type, 0, (sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps));

    g_mmi_rp_mgr_cntx.app_id = (U8**)malloc(sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps);
    if(g_mmi_rp_mgr_cntx.app_id == NULL)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mgr_cntx.app_id, 0, (sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps));

    g_mmi_rp_mgr_cntx.app_str_id = (U8**)malloc(sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps);
    if(g_mmi_rp_mgr_cntx.app_str_id == NULL)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mgr_cntx.app_str_id, 0, (sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps));

    g_mmi_rp_mgr_cntx.app_img_id = (U8**)malloc(sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps);
    if(g_mmi_rp_mgr_cntx.app_img_id == NULL)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mgr_cntx.app_img_id, 0, (sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps));

    g_mmi_rp_mgr_cntx.app_package_name = (U8**)malloc(sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps);
    if(g_mmi_rp_mgr_cntx.app_package_name == NULL)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mgr_cntx.app_package_name, 0, (sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps));

    g_mmi_rp_mgr_cntx.app_launch_func = (U8**)malloc(sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps);
    if(g_mmi_rp_mgr_cntx.app_launch_func == NULL)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mgr_cntx.app_launch_func, 0, (sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps));

    g_mmi_rp_mgr_cntx.app_package_proc = (U8**)malloc(sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps);
    if(g_mmi_rp_mgr_cntx.app_package_proc == NULL)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mgr_cntx.app_package_proc, 0, (sizeof(U8*) * g_mmi_rp_mgr_cntx.total_apps));

    g_mmi_rp_mgr_cntx.app_hidden_in_mainmenu = NULL;
    g_mmi_rp_mgr_cntx.app_hidden_in_mainmenu = (MMI_BOOL*)malloc(sizeof(MMI_BOOL) * g_mmi_rp_mgr_cntx.total_apps);

    if(g_mmi_rp_mgr_cntx.app_hidden_in_mainmenu == NULL)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_mgr_cntx.app_hidden_in_mainmenu, 0, (sizeof(MMI_BOOL) * g_mmi_rp_mgr_cntx.total_apps));

    g_mmi_rp_mgr_cntx.hash = mmi_rp_hash_create(g_mmi_rp_mgr_cntx.total_apps * 5);  /* for INCLUDE tags and file names and enum constructs */

    mmi_rp_mgr_path_reset();

    mmi_rp_menu_init();
    mmi_rp_str_init();
    mmi_rp_scr_init();
    mmi_rp_timer_init();
    mmi_rp_event_init();
    mmi_rp_aud_init();
    mmi_rp_mem_config_init();
    mmi_rp_img_init();
    mmi_rp_theme_init();

    /* Init cust resource type */
    i = 0;
    while(g_res_handlers_cust[i].mmi_rp_res_init != mmi_rp_end_function)
    {
        g_res_handlers_cust[i].mmi_rp_res_init();
        i++;
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_deinit
 * DESCRIPTION
 *  This function is for manager to deinit all data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mgr_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_rp_theme_deinit();
    mmi_rp_aud_deinit();
    mmi_rp_img_deinit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_parser_doctype_start_handler
 * DESCRIPTION
 *  This function is for XML parser to return doctype start tag information to application
 * PARAMETERS
 *  data                [IN]        Reserved
 *  doctypeName         [IN]        Document type name string
 *  sysid               [IN]        System external id list
 *  pubid               [IN]        Public external id list
 *  internal_subset     [IN]        Internal subset presence
 *  error               [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mgr_parser_doctype_start_handler(
                                            void *data,
                                            const kal_char *doctypeName,
                                            const kal_char **sysid,
                                            const kal_char **pubid,
                                            kal_int32 internal_subset,
                                            kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32  index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (XML_NO_ERROR == error)
    {
        index = 0;
        if (NULL != sysid)
        {
            while (sysid[index])
            {
                MMI_RP_DEBUG_INFO("%s\n", sysid[index]);
                index++;
            }
        }
        index = 0;
        if (NULL != pubid)
        {
            while (pubid[index])
            {
                MMI_RP_DEBUG_INFO("%s\n", pubid[index]);
                index++;
            }
        }
    }
    else
    {
        S8    *err_str = NULL;
        
        err_str = xml_get_err_string(&g_mmi_rp_mgr_cntx.xml_parser);
        MMI_RP_DEBUG_INFO("%s\n", err_str);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_parser_doctype_end_handler
 * DESCRIPTION
 *  This function is for XML parser to indicate the end of document type to application.
 * PARAMETERS
 *  data        [IN]        Reserved
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mgr_parser_doctype_end_handler(void *data, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (XML_NO_ERROR != error)
    {
        kal_char    *err_str = NULL;
        
        err_str = xml_get_err_string(&g_mmi_rp_mgr_cntx.xml_parser);
        printf("%s\n", err_str);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_parser_elem_start_handler
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
static void mmi_rp_mgr_parser_elem_start_handler(void *data, const kal_char *el, const kal_char **attr, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (XML_NO_ERROR == error)
    {
        for (i=0; i<g_mmi_rp_mgr_cntx.tag_count; i++)
        {
            if ((int)strcmp((char*)g_res_handlers[i].tag_name, el) == 0)
            {
                if (g_mmi_rp_error_stack_top == -1)
                {
                    int result = g_res_handlers[i].start_elem_hdlr(data, el, attr);
                    if (result != MMI_RP_PARSE_OK && result != MMI_RP_PARSE_ERROR_CONTINUE)
                    {
                        int index = 0;
                        g_mmi_rp_error_stack_top = mmi_rp_mgr_stack_tag_count();
                        //printf("mmi_rp_mgr_parser_elem_start_handler got error, error code: %d, stack %d, [%s]", result, g_mmi_rp_error_stack_top, el);
                        printf(">> Potential risk found in <%s>.(depth in tag stack= %d, err code= %d)\n", el, g_mmi_rp_error_stack_top, result);
                        printf(">> Not fatal error but some data may be skipped. Check the above *.i file for the detail.\n");
                        while (NULL != attr[index])
                        {
                            if(index %2 ==0){
                                printf(">> - Attribute may be skipped: %s = ", attr[index]);
                            }else{
                                printf("%s\n", attr[index]);
                            }
                            ++index;
                        }
                        if(index%2 !=0){
                            printf("\n");
                        }
                    }
                }
                else
                {
                    printf(">>Skipped start tag of element: <%s>", el);
                }
                /* Current parent tag is set here. It'll be preserved by all resource handlers by them and will be restored when their elem_end is called. */
                mmi_rp_mgr_stack_push(i);
                break;
            }
        }

        if (i == g_mmi_rp_mgr_cntx.tag_count)
        {
            printf("Not Found Tag [%s]\n", el);
        }
    }
    else
    {
        kal_char    *err_str = NULL;

        err_str = xml_get_err_string(&g_mmi_rp_mgr_cntx.xml_parser);
        MMI_RP_DEBUG_INFO("start: %s\n", err_str);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_parser_elem_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mgr_parser_elem_end_handler(void *data, const kal_char *el, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (XML_NO_ERROR == error)
    {
        for (i=0; i<g_mmi_rp_mgr_cntx.tag_count; i++)
        {
            if (strcmp(g_res_handlers[i].tag_name, el) == 0)
            {
                if (g_mmi_rp_error_stack_top == -1)
                {
                    g_res_handlers[i].end_elem_hdlr(data, el);
                }
                else
                {
                    printf(">> - Skipped end tag of element: <%s>, (depth in tag stack = %d)\n", el, mmi_rp_mgr_stack_tag_count());
                }
                if(strcmp(mmi_rp_mgr_stack_top_tag_name(), el) != 0)
                {
                    MMI_RP_ERROR(RP_ERR_UNKNOWN_PARSE_ERROR);
                }
                mmi_rp_mgr_stack_pop();
                if (g_mmi_rp_error_stack_top >= mmi_rp_mgr_stack_tag_count() )
                {
                    g_mmi_rp_error_stack_top = -1;
                }
                break;
            }
        }

        if (i == g_mmi_rp_mgr_cntx.tag_count)
        {
            printf("Not Found Tag [%s]\n", el);
        }
    }
    else
    {
        kal_char    *err_str = NULL;
        
        err_str = xml_get_err_string(&g_mmi_rp_mgr_cntx.xml_parser);
        MMI_RP_DEBUG_INFO("end: %s\n", err_str);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_parser_data_handler
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
static void mmi_rp_mgr_parser_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (XML_NO_ERROR == error)
    {
        for (i=0; i<g_mmi_rp_mgr_cntx.tag_count; i++)
        {
            if (strcmp(g_res_handlers[i].tag_name, el) == 0)
            {
                if (g_res_handlers[i].data_hdlr == NULL)
                {
                    MMI_RP_ERROR(RP_ERR_TAG_NOT_SUPPORT_DATA);
                    return;
                }
                if (g_mmi_rp_error_stack_top == -1)
                {
                    g_res_handlers[i].data_hdlr(resv, el, data, len);
                }
                else
                {
                    printf(">> - Skipped data of element: <%s>\n", el);
                }
                break;
            }
        }

        if (i == g_mmi_rp_mgr_cntx.tag_count)
        {
            printf("Not Found Tag [%s]\n", el);
        }
    }
    else
    {
        kal_char    *err_str = NULL;
        
        err_str = xml_get_err_string(&g_mmi_rp_mgr_cntx.xml_parser);
        MMI_RP_DEBUG_INFO("data: %s\n", err_str);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_parser_malloc_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  buff_size        [IN]        buffer size of malloc
 * RETURNS
 *  void
 *****************************************************************************/
static void *mmi_rp_mgr_parser_malloc_handler(kal_int32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return malloc(buff_size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_parser_free_handler
 * DESCRIPTION
 *  XML
 * PARAMETERS
 *  buff_ptr        [IN]        point of buffer to free
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mgr_parser_free_handler(void * buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free(buff_ptr);
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_parser_load_file_data
 * DESCRIPTION
 *  load data from file and add line number info
 * PARAMETERS
 *  filename        [IN]        file name
 *  data            [OUT]       pointer to the output data buffer
 * RETURNS
 *  BOOL            if loading data succeeded
 *****************************************************************************/
BOOL mmi_rp_mgr_parser_load_file_data(S8 * filename, S8 ** data)
{
    FILE *fp = NULL;
    U8 temp_folder[512];
    U8 line_buf[1024];
    U8 temp[1024];
    U32 cur_line, i, temp_cur_line;
    S32 line_len;
    MMI_BOOL is_tag_fin = MMI_TRUE;
    MMI_BOOL is_xml_start = MMI_FALSE;
    S32 file_size = 0;
    S8 *buf = NULL;

    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_PARSE_ERROR, "Test file can not open");
        return FALSE;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    buf = malloc((file_size+1) * 2);
    if (buf == NULL)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        return FALSE;
    }
    buf[0] = '\0';

    cur_line = 1;
    strcpy(temp_folder, MMI_RP_MGR_XML_TEMP_FOLDER_NAME);

    /* read file and add <LINE l=xxx/>  and remove unused code before <?xml */
    while (fgets(line_buf, 1024, fp) != NULL)
    {
        if (line_buf[0] == '<' &&
            line_buf[1] == '?' &&
            (line_buf[2] == 'x' || line_buf[2] == 'X') &&
            (line_buf[3] == 'm' || line_buf[3] == 'M') &&
            (line_buf[4] == 'l' || line_buf[4] == 'L'))
        {
            is_xml_start = MMI_TRUE;
        }
        
        if (line_buf[0] == '#' && line_buf[1] == ' ')
        {
            temp_cur_line = cur_line;
            sscanf(line_buf, "# %d %s", &cur_line, temp);
            
            /* This will help to filter some line number ,and save parse time. */
            /* We only need the files in temp folder. */
            if (temp[0] == '\"' &&
                temp[1] == temp_folder[0] &&
                temp[2] == temp_folder[1] &&
                temp[3] == temp_folder[2] &&
                temp[4] == temp_folder[3])
            {
                if (is_tag_fin)
                {
                    /* write next line number */
                    sprintf(temp, "<LINE l=\"%d\"/>", cur_line);
                    strcat(buf, temp);
                }
                else
                {
                    for(i = 0; i < (cur_line - temp_cur_line); i++)
                    {
                        temp[i] = '\n';
                    }
                    temp[i] = 0;
                    strcat(buf, temp);
                }
            }
        }
        else
        {
            cur_line++;

            if (is_xml_start)
            {
                strcat(buf, line_buf);
                
                line_len = strlen(line_buf);
                line_len-=2;
                
                while (line_len >= 0 && line_buf[line_len] == ' ')
                {
                    line_len--;
                }
                
                if(line_len < 0)
                {
                    /* empty line */
                    if (is_tag_fin)
                    {
                        /* write next line number */
                        sprintf(temp, "<LINE l=\"%d\"/>", cur_line);
                        strcat(buf, temp);
                    }
                }
                else
                {
                    if (line_buf[line_len] == '>')
                    {
                        /* write next line number */
                        sprintf(temp, "<LINE l=\"%d\"/>", cur_line);
                        strcat(buf, temp);
                        is_tag_fin = MMI_TRUE;
                    }
                    else
                    {
                        is_tag_fin = MMI_FALSE;
                    }
                }
            }
        }
    }
    
    fclose(fp);
    *data = buf;
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_parser_internal
 * DESCRIPTION
 *  parse data with the xml parser
 * PARAMETERS
 *  buf             [IN]       pointer to the data buffer
 * RETURNS
 *  BOOL            if parsing succeeded
 *****************************************************************************/
BOOL mmi_rp_mgr_parser_internal(S8 * buf)
{
    S32 xml_result = 0;
    BOOL parse_success = FALSE;
    /*
     * [1]. Create an XML parser before parse a new XML document
     * Application has to allocate memory for the XML_PARSER_STRUCT structure
     * on it ownbefore calling this API to create parser.
     */
    xml_result = xml_new_parser(&g_mmi_rp_mgr_cntx.xml_parser);

    /* If the xml parser is created successful, then you can parse the file continue */
    if (XML_RESULT_OK == xml_result)
    {
        /*
         * [2]. Register the doctype, element, data and memory callback function before the parsing,
         * Application has to prepare the handlers as callback functions to perform actions it wants
         * according to application specific logic when the every element is encountered.
         */
    
        /*
         * Register start tag and end tag handler of document type.
         * [Note]: If application doesn't want to deal with the document type, this function could not
         * be called, or the second parameter start_hdlr and third parameter end_hdlr are set to NULL,
         * it will be processed by the default parser procedures, and the data of doc type will be ignored.
         */
        xml_register_doctype_handler(
            &g_mmi_rp_mgr_cntx.xml_parser,
            mmi_rp_mgr_parser_doctype_start_handler,
            mmi_rp_mgr_parser_doctype_end_handler);

        /*
         * Register start tag and end tag handler of an element.
         * [Note]: If application doesn't want to deal with the element, this function could not be
         * called, or the second parameter start_hdlr and third parameter end_hdlr are set to NULL,
         * it will be processed by the default parser procedures, and the data of element will be ignored.
         * But usually application should deal with the element for special applications.
         */
        xml_register_element_handler(
            &g_mmi_rp_mgr_cntx.xml_parser,
            mmi_rp_mgr_parser_elem_start_handler,
            mmi_rp_mgr_parser_elem_end_handler);

        /*
         * Register data handler of an element.
         * [Note]: If application doesn't want to deal with the data, this function could not be called,
         * or the second parameter data_hdlr is set to NULL, it will be processed by the default parser
         * procedures, and the data of element will be ignored. But usually application should deal with
         * the data for special applications.
         */
        xml_register_data_handler(
            &g_mmi_rp_mgr_cntx.xml_parser,
            mmi_rp_mgr_parser_data_handler);

        /*
         * Configure malloc and free function pointer.
         * [Note]: If application wants to use the malloc and free functions by themseles, application
         * could call this function to register the handler of the custom functions, and the xml parser
         * will call the custom functions to malloc and free the memory. Otherwise, if application does
         * not register the function handler, xml parser will use the default procedures.
         */
        xml_configure_memory(
            &g_mmi_rp_mgr_cntx.xml_parser,
            mmi_rp_mgr_parser_malloc_handler,
            mmi_rp_mgr_parser_free_handler);

       
        /* XML Parser start from buffer */
        xml_result = xml_parse_buffer(&g_mmi_rp_mgr_cntx.xml_parser, buf, (int)strlen(buf));
        if (xml_result != XML_RESULT_OK)
        {
            /* Parse Failed */
            printf("Parser return error ret=[%d].\n", xml_result);
            MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_PARSE_ERROR, "Parser return error");
        }
        else
        {
            printf("\nParser return successful.\n\n");
            parse_success = TRUE;
        }

        /*
         * [4]. Close a parser.
         * APP call this function to close a parser after finish parsing and
         * to reset parser data structure or release internal allocated memory.
         */
        xml_close_parser(&g_mmi_rp_mgr_cntx.xml_parser);
    }
    else
    {
        printf("Parser open error ret=[%d].\n", xml_result);
        MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_PARSE_ERROR, "Parser open error");
    }

    return parse_success;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_parser
 * DESCRIPTION
 *  The sample of xml parser from file or buffer, the output data will be writed to file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mgr_parser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp_buf[2048];
    char check_cmd[1024];
    int cmd_result = 0;

    FILE * list_file = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    // filter valid xml list
#ifdef RESXML_VC_DEBUG
    strcpy(check_cmd, "..\\..\\..\\..\\..\\tools\\python25\\python ..\\..\\resgen_xml_check.py");
#else
    strcpy(check_cmd, "..\\..\\..\\tools\\python25\\python resgen_xml_check.py");
#endif
    cmd_result = system(check_cmd);
    if (cmd_result != 0)
    {
        MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_PARSE_ERROR, "some xml is not well-formed, check resgen_xml.log");
    }

#ifdef RESXML_VC_DEBUG
    list_file = fopen("..\\..\\debug\\resgen_valid_xml_list.txt", "r");
#else
    list_file = fopen("debug\\resgen_valid_xml_list.txt", "r");
#endif
    if (list_file == NULL)
    {
        printf("can not open xml list : debug/resgen_valid_xml_list.txt\n");
        return;
    }

    
    /* open log file of filename */
    strcpy(temp_buf, MMI_RP_MGR_XML_DEBUG_PATH);
    strcat(temp_buf, "output_file.log");
    g_output_log_file = fopen(temp_buf, "w");


    while (1)
    {
        BOOL open_file_failed = FALSE;
        char filename[1024];
        S8 *buf = NULL;

        if (!fgets(filename, 1024, list_file))
        {
            break;
        }
        if (strlen(filename) <= 1)
        {
            break;
        }
        filename[strlen(filename) - 1] = '\0';

        strcpy((S8*)g_cur_filename, filename);

        strcpy((S8*)temp_buf, MMI_RP_MGR_XML_SEARCH_PATH);
        strcat((S8*)temp_buf, filename);
        
        /* Set current filename and reset line number to error structure , easy to output log*/
        strcpy((S8*)g_mmi_rp_mgr_cntx.xml_error.error_file, temp_buf);
        g_mmi_rp_mgr_cntx.xml_error.error_line = 0;

        open_file_failed = !mmi_rp_mgr_parser_load_file_data(temp_buf, &buf);
        
        if (!open_file_failed)
        {
            BOOL parse_success = FALSE;
            parse_success = mmi_rp_mgr_parser_internal(buf);
        }

        if (g_mmi_rp_mgr_cntx.parent_tags.top != 0)
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_PARSE_ERROR);
            g_mmi_rp_mgr_cntx.parent_tags.top = 0;
        }

        if (buf != NULL)
        {
            free(buf);
            buf = NULL;
        }
        
    }

    if (list_file)
    {
        fclose(list_file);
    }

    if(g_output_log_file)
    {
        fclose(g_output_log_file);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_get_err_string
 * DESCRIPTION
 *  Get Error string from XML parser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_char *mmi_rp_mgr_get_err_string(void)
{
    return xml_get_err_string(&g_mmi_rp_mgr_cntx.xml_parser);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rp_filter
 * DESCRIPTION
 *  Filter the data that read from .res files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mgr_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* remove not used menuitems */
    mmi_rp_menu_filter_menuitem();
    
    /* remove XML scope resources */
    mmi_rp_str_filter();
    mmi_rp_scr_filter();
    mmi_rp_timer_filter();
    mmi_rp_event_filter();
    mmi_rp_aud_filter();
    mmi_rp_img_filter();
    mmi_rp_theme_filter();

    /* Filter cust resource type */
    i = 0;
    while(g_res_handlers_cust[i].mmi_rp_res_filter != mmi_rp_end_function)
    {
        g_res_handlers_cust[i].mmi_rp_res_filter();
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_contruct_name
 * DESCRIPTION
 *  Contructs names for output purpose
 * PARAMETERS
 *  mmi_rp_output_names_enum    type of name to be constructed
 * RETURNS
 *  void
 *****************************************************************************/
U8 *mmi_rp_mgr_contruct_name(mmi_rp_output_names_enum name_type, U8* str_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str_name[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    U32 j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_name, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);

    switch(name_type)
    {
        case MMI_RP_OUTPUT_NAME_C_FILE_PATH :
        {
            strcpy(str_name, MMI_RP_MGR_XML_TEMP_CMP_C_FILES);
            strcat(str_name, "mmi_rp_");
            strcat(str_name, str_app);
            strcat(str_name, ".c");
            for(j = 0; j < strlen(str_name); j++)
            {
                str_name[j] = tolower(str_name[j]);
            }
            break;
        }
        case MMI_RP_OUTPUT_NAME_H_FILE_PATH :
        {
            strcpy(str_name, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
            strcat(str_name, "mmi_rp_");
            strcat(str_name, str_app);
            strcat(str_name, "_def.h");
            for(j = 0; j < strlen(str_name); j++)
            {
                str_name[j] = tolower(str_name[j]);
            }
            break;
        }

        case MMI_RP_OUTPUT_NAME_H_FILE :
        {
            strcpy(str_name, "mmi_rp_");
            strcat(str_name, str_app);
            strcat(str_name, "_def.h");
            for(j = 0; j < strlen(str_name); j++)
            {
                str_name[j] = tolower(str_name[j]);
            }
            break;
        }

        case MMI_RP_OUTPUT_NAME_C_FILE :
        {
            strcpy(str_name, "mmi_rp_");
            strcat(str_name, str_app);
            strcat(str_name, ".c");
            for(j = 0; j < strlen(str_name); j++)
            {
                str_name[j] = tolower(str_name[j]);
            }
            break;
        }

        case MMI_RP_OUTPUT_NAME_HEADER_GUARD :
        {
            strcpy(str_name, "_MMI_RP_");
            strcat(str_name, str_app);
            strcat(str_name, "_DEF_H");
            for(j = 0; j < strlen(str_name); j++)
            {
                str_name[j] = toupper(str_name[j]);
            }
            break;
        }

        case MMI_RP_OUTPUT_NAME_POPULATE_FUNCTION :
        {
            strcpy(str_name, "mmi_rp_");
            strcat(str_name, str_app);
            strcat(str_name, "_populate");
            for(j = 0; j < strlen(str_name); j++)
            {
                str_name[j] = tolower(str_name[j]);
            }
            break;
        }

        default :
        {
            break;
        }
    }
    return (U8*)mmi_rp_hash_add(g_mmi_rp_mgr_cntx.hash, str_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_app_package_output_phase
 * DESCRIPTION
 *  Output 2 files
 *  1. mmi_rp_native_app_package_data.h
 *  2. mmi_rp_native_app_package_data.c
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_app_package_output_phase(void)
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
    /* 1. Output mmi_rp_native_app_package_data.h file. */
    memset(str_output_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_output_filename, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    strcat(str_output_filename, MMI_RP_APP_PACKAGE_CONFIG_FILE_NAME_DATA_H);
    if(p_file = fopen(str_output_filename, "w"))
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
            p_file,
            MMI_RP_MEM_CONFIG_FILE_NAME_DATA_H,
            "Resource populate function generated by XML resgen",
            "MTK resgenerator XML parser");
        mmi_rp_output_phase1_begin(p_file, MMI_RP_APP_PACKAGE_CONFIG_HEADER_GUARD_DATA_H);  /* Write Header guard Begin */
        
        /* String IDs for APP_name */
        fprintf(p_file, "\n\n/* srv_nativeappfactory_package_struct structure declaration */\n");
        fprintf(p_file, "typedef struct {\n");
        fprintf(p_file, "    mmi_app_package_name_struct    package_name;\n");
        fprintf(p_file, "    mmi_proc_func                  package_proc;\n");
        fprintf(p_file, "    mmi_app_launch_func            app_launch;\n\n");
        fprintf(p_file, "    U16 app_id;\n");        
        fprintf(p_file, "    U16 app_str_id;\n");
        fprintf(p_file, "    U16 app_img_id;\n");
        fprintf(p_file, "    MMI_BOOL app_is_hidden_in_mainmenu;\n");
        fprintf(p_file, "} srv_nativeappfactory_package_struct;\n");

        fprintf(p_file, "\n/* extern declaration to use the srv_native_app_package_struct array */\n");
        fprintf(p_file, "extern const srv_nativeappfactory_package_struct native_app_package_table[];\n");

        fprintf(p_file, "\n/* extern declaration to get size of native_app_package_table[] array  */\n");
        fprintf(p_file, "extern U32 srv_nativeappfactory_get_table_size(void);\n");

        fprintf(p_file, "\n/* extern native app package proc and native app launch function */\n");
        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            if (g_mmi_rp_mgr_cntx.app_package_proc[i])
            {
                fprintf(p_file, "extern mmi_ret %s(mmi_event_struct *param);\n", g_mmi_rp_mgr_cntx.app_package_proc[i]);
            }
            if (g_mmi_rp_mgr_cntx.app_launch_func[i])
            {
                fprintf(p_file, "extern MMI_ID %s(void* param, U32 param_size);\n", g_mmi_rp_mgr_cntx.app_launch_func[i]);
            }
        }

        mmi_rp_output_phase1_finish(p_file, MMI_RP_APP_PACKAGE_CONFIG_HEADER_GUARD_DATA_H);             /* Write Header guard Finish */
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }

    /* 2. Output mmi_rp_native_app_package_data.c file. */
    memset(str_output_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_output_filename, MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES);
    strcat(str_output_filename, MMI_RP_APP_PACKAGE_CONFIG_FILE_NAME_DATA_C);

    if(p_file = fopen(str_output_filename, "w"))
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
            p_file,
            MMI_RP_APP_PACKAGE_CONFIG_FILE_NAME_DATA_C,
            "Resource populate function generated by XML resgen",
            "MTK resgenerator XML parser");

        /* Include headers */
        fprintf(p_file, "\n\n#include \"MMIDataType.h\"\n");
        fprintf(p_file, "#include \"mmi_rp_native_app_package_data.h\"\n");
        fprintf(p_file, "#include \"mmi_rp_all_defs.h\"\n");
        fprintf(p_file, "#include \"GlobalResDef.h\"\n");

        is_empty = MMI_TRUE;
        fprintf(p_file, "\nconst srv_nativeappfactory_package_struct native_app_package_table[] = {\n");
        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            if (g_mmi_rp_mgr_cntx.app_package_name[i])
            {
                fprintf(p_file, "    {\"%s\", %s, (mmi_app_launch_func)%s, %s, %s, %s, (MMI_BOOL)%d},\n",
                    (g_mmi_rp_mgr_cntx.app_package_name[i])? g_mmi_rp_mgr_cntx.app_package_name[i] : "NULL",
                    (g_mmi_rp_mgr_cntx.app_package_proc[i])? g_mmi_rp_mgr_cntx.app_package_proc[i] : "NULL",
                    (g_mmi_rp_mgr_cntx.app_launch_func[i])? g_mmi_rp_mgr_cntx.app_launch_func[i] : "NULL",
                    (g_mmi_rp_mgr_cntx.app_id[i])? g_mmi_rp_mgr_cntx.app_id[i] : "NULL",
                    (g_mmi_rp_mgr_cntx.app_str_id[i])? g_mmi_rp_mgr_cntx.app_str_id[i] : "NULL",
                    (g_mmi_rp_mgr_cntx.app_img_id[i])? g_mmi_rp_mgr_cntx.app_img_id[i] : "IMG_GLOBAL_DEFAULT",
                    g_mmi_rp_mgr_cntx.app_hidden_in_mainmenu[i]);
                is_empty = MMI_FALSE;
            }
        }
        if(is_empty)
        {
            fprintf(p_file, "    0\n");
        }
        fprintf(p_file, "};\n\n");

        fprintf(p_file, "U32 srv_nativeappfactory_get_table_size(void)\n");
        fprintf(p_file, "{\n");
        fprintf(p_file, "    return sizeof(native_app_package_table)/sizeof(srv_nativeappfactory_package_struct);\n");
        fprintf(p_file, "}\n");


        
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
    }
}


static void mmi_rp_mgr_output_res_base_table()
{
    U32 i, j, t, total;
    U32 *sort_idx;
    FILE *fp;

    fp = fopen(".\\\\debug\\\\resgen_base_table.txt", "w");
    if (fp == NULL)
    {
        printf("output resource_base_table.txt fail.\n");
        fprintf(stderr, "output resource_base_table.txt fail.\n");
        return;
    }

    total = sizeof(g_mmi_resource_base_table)/sizeof(mmi_resource_base_struct);

    sort_idx = (U32*)malloc(sizeof(U32) * total);
    for(i=0;i<total;i++)
        sort_idx[i] = i;

    for(i=0;i<total;i++)
        for(j=i+1;j<total;j++)
            if(g_mmi_resource_base_table[sort_idx[i]].min > g_mmi_resource_base_table[sort_idx[j]].min)
            {
                t = sort_idx[j];
                sort_idx[j] = sort_idx[i];
                sort_idx[i] = t;
            }

    fprintf(fp, "min\tmax\tappname\n");
    for(i=0;i<total;i++)
    {
        fprintf(fp, "%d\t%d\t%s\t%s\n",
                g_mmi_resource_base_table[sort_idx[i]].min,
                g_mmi_resource_base_table[sort_idx[i]].max,
                g_mmi_resource_base_table[sort_idx[i]].appname,
                g_mmi_resource_base_table[sort_idx[i]].res_path);
    }

    free(sort_idx);

    fclose(fp);
    printf("output resource_base_table.txt done.\n");
    fprintf(stderr, "output resource_base_table.txt done.\n");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_output
 * DESCRIPTION
 *  Output all resource to dest files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mgr_output(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U8 str_output_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    U8 id_model_sourc_file[MMI_RP_MGR_MAX_FILE_NAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_output_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_output_filename, MMI_RP_MGR_XML_DEBUG_PATH);
    strcat(str_output_filename, "resgen_xml_all_enum_IDs.log");
    strcpy(id_model_sourc_file,str_output_filename);
    g_mmi_rp_output_enum_log_file = fopen(str_output_filename, "w");

    mmi_rp_mgr_output_start();

    /* Please don't modify the order in which they are called. */

    /***************************************************************/
    /* Phase 0. output Venus Mem-config data. Independent on Res IDs ordering. */
    /***************************************************************/
    mmi_rp_mem_config_output_phase();
    mmi_rp_app_package_output_phase();


    /***************************************************************/
    /* Phase 1. output IDs */
    /***************************************************************/
    mmi_rp_menu_output_phase1();        /* First resource ID to write beginning of header guard. */
    /* Please add the o/p for all other resource types below */
    /* Above function will start writing the header guard for the header file. */

    mmi_rp_str_output_phase1();
    mmi_rp_scr_output_phase1();
    mmi_rp_timer_output_phase1();
    mmi_rp_event_output_phase1();
    mmi_rp_aud_output_phase1();
    mmi_rp_theme_output_phase1();

    /* output phase 1 cust resource type */
    i=0;
    while(g_res_handlers_cust[i].mmi_rp_res_output_1 != mmi_rp_end_function)
    {
        g_res_handlers_cust[i].mmi_rp_res_output_1();
        i++;
    }

    // add for xml parsing in script
#ifdef RESXML_VC_DEBUG
    #ifndef __RESGEN_INTERNAL_3D_META_RESGEN_AUTO__
    system("..\\..\\..\\..\\..\\" "tools\\python25\\python" " ..\\..\\resgen_xml_handle.py");
#else
    system("..\\..\\..\\..\\..\\" "tools\\python25\\python" " ..\\..\\resgen_xml_3d_dev_handle.py");
    #endif //__RESGEN_INTERNAL_3D_META_RESGEN_AUTO__
#else
    #ifndef __RESGEN_INTERNAL_3D_META_RESGEN_AUTO__
    system("..\\..\\..\\" "tools\\python25\\python" " resgen_xml_handle.py");
    #else
    system("..\\..\\..\\" "tools\\python25\\python" " resgen_xml_3d_dev_handle.py");
    #endif //__RESGEN_INTERNAL_3D_META_RESGEN_AUTO__
#endif

    /* Please add the o/p for all other resource types above this. */
    /* The following function will close the header guard at the end of the line. */
    mmi_rp_img_output_phase1();     /* Last resource ID to write #endif of header guard. */
    
    if(g_mmi_rp_output_enum_log_file)
    {
        fclose(g_mmi_rp_output_enum_log_file);
    }
    /***************************************************************/
    /* Phase 2. output resources */
    /***************************************************************/

    // Init ID model objects from ID log file
    OfflineIdModelInit(id_model_sourc_file);

    mmi_rp_menu_output_phase2();    /* First resource ID to write starting of the populate function. */
    /* Please add the o/p for all other resource types below */
    /* Above function will start writing the function name and opening brace for the function body. */
    #ifndef __POPULATE_NO_STRING_DATA__    
    mmi_rp_str_output_phase2();
    #endif

    /* Following functions are not called, because currently they do nothing. Left here for future references. */
    /* mmi_rp_scr_output_phase2(); */
    /* mmi_rp_timer_output_phase2(); */
    /* mmi_rp_event_output_phase2(); */
    mmi_rp_aud_output_phase2();
    mmi_rp_theme_output_phase2();

    /* output phase 2 cust resource type */
    i=0;
    while(g_res_handlers_cust[i].mmi_rp_res_output_2 != mmi_rp_end_function)
    {
        g_res_handlers_cust[i].mmi_rp_res_output_2();
        i++;
    }

    /* Please add the o/p for all other resource types above this. */
    /* The following function will close the populate function by adding } at the end of the line. */
#ifndef __POPULATE_NO_IMAGE_DATA__
    mmi_rp_img_output_phase2();     /* Last resource ID to write the closing brace of the populate function. */
#endif

    #ifdef __RESGEN_INTERNAL_POP_FILE_REDUCE__
    mmi_rp_output_phase2_finish_reduce();    
    #endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__

    // Release ID Model objects
    OfflineIdModelDeinit();
    
    mmi_rp_mgr_output_end();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_output_start
 * DESCRIPTION
 *  Output common file header
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mgr_output_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str_output_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    FILE *p_file = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_output_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_output_filename, MMI_RP_MGR_XML_TEMP_CMP_C_FILES);
    strcat(str_output_filename, "mmi_rp_populate.c");

    if(p_file = fopen(str_output_filename, "w"))            /* Rest resources will open the file in append mode */
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(p_file, "mmi_rp_populate.c", "Resource populate function generated by XML resgen", "MTK resgenerator XML parser");

        fprintf(p_file, "\n");
        mmi_rp_output_phase2_begin(p_file, "mmi_rp_populate_resources", "", "");
        
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

    memset(str_output_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_output_filename, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    strcat(str_output_filename, "mmi_rp_all_defs.h");

    if(p_file = fopen(str_output_filename, "w"))            /* Rest resources will open the file in append mode */
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(p_file, "mmi_rp_all_defs.h", "Include all auto generated header files (for res IDs) by XML resgen", "MTK resgenerator XML parser");
        fprintf(p_file, "\n");
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }


    memset(str_output_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_output_filename, MMI_RP_MGR_XML_VENUS_THEME_LOG);
    if(p_file = fopen(str_output_filename, "w"))
    {
        fclose(p_file);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_output_populate_func
 * DESCRIPTION
 *  Output common file footer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mgr_output_populate_func(U8* populate_func_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str_output_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    FILE *p_file = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_output_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_output_filename, MMI_RP_MGR_XML_TEMP_CMP_C_FILES);
    strcat(str_output_filename, "mmi_rp_populate.c");

    if(p_file = fopen(str_output_filename, "a"))            /* Rest resources will open the file in append mode */
    {
        fprintf(p_file, "    extern void %s(void);\n", populate_func_name);
        fprintf(p_file, "    %s();\n\n", populate_func_name);
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
 *  mmi_rp_mgr_output_all_defs
 * DESCRIPTION
 *  Output name of all automatic header files.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mgr_output_all_defs(U8* str_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str_output_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    FILE *p_file = NULL;
    U8 *temp = NULL;
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_output_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_output_filename, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    strcat(str_output_filename, "mmi_rp_all_defs.h");

    if(p_file = fopen(str_output_filename, "a"))            /* Rest resources will open the file in append mode */
    {
        len = strlen(str_file_name);
        temp = str_file_name + len;
        while(*temp != '\\' && len > 0)
        {
            temp--;
            len--;
        }
        temp++;

        fprintf(p_file, "#include \"%s\"\n", temp);
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
 *  mmi_rp_mgr_output_end
 * DESCRIPTION
 *  Output common file footer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_mgr_output_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str_output_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    FILE *p_file = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_output_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_output_filename, MMI_RP_MGR_XML_TEMP_CMP_C_FILES);
    strcat(str_output_filename, "mmi_rp_populate.c");

    if(p_file = fopen(str_output_filename, "a"))            /* Rest resources will open the file in append mode */
    {
        mmi_rp_output_phase2_finish(p_file);
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
 *  mmi_rp_mgr_app_start_handler
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
int mmi_rp_mgr_app_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 attr_idx = 0;
    U32 base_idx = 0;
    U8 *curr_app_id = NULL;
    U8 *curr_app_str = NULL;
    U8 *curr_app_img = NULL;
    U8 *curr_app_hidden_in_mainmenu = NULL;
    U8 *curr_app_package_name = NULL;
    U8 *curr_app_launch_func = NULL;
    U8 *curr_app_package_proc = NULL;
    U8 *curr_app_type = NULL;
    U32 i = 0;
    U8 cur_filename[512];
    U8 res_filename[MAX_RES_FILE_NAME_SIZE]="";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("APP-start: %s\n", el);

    g_mmi_rp_mgr_cntx.cur_app = NULL;

    while ((NULL != attr[attr_idx]) && (NULL != attr[attr_idx + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[attr_idx], attr[attr_idx + 1]);

        if(strcmp(attr[attr_idx], MMI_RP_MGR_ATTR_ID) == 0)
        {
            /* Find APP_NAME in mmidatatype.h */
            while (!(g_mmi_resource_base_table[base_idx].appname[0] == 'E' &&
                     g_mmi_resource_base_table[base_idx].appname[1] == 'N' &&
                     g_mmi_resource_base_table[base_idx].appname[2] == 'D' &&
                     g_mmi_resource_base_table[base_idx].appname[3] == '\0'))
            {
                if ((int)strcmp((char*)g_mmi_resource_base_table[base_idx].appname, attr[attr_idx+1]) == 0)
                {
                    U8 str_name[MMI_RP_MGR_MAX_FILE_NAME_LEN*4];
                    U8 *temp_str = NULL;
                    U16 res_file_name_size = 0;

                    g_mmi_rp_mgr_cntx.cur_app = (mmi_resource_base_struct*)&(g_mmi_resource_base_table[base_idx]);
                    g_mmi_rp_mgr_cntx.cur_app_index = base_idx;
                    g_mmi_rp_mgr_cntx.app_populated[base_idx] = MMI_TRUE;
                    //Set the curent RES file path to context
                    ConvertToResFileName(res_filename,g_mmi_rp_mgr_cntx.cur_app->res_path,g_cur_filename,MAX_RES_FILE_NAME_SIZE-1);
                    res_filename[MAX_RES_FILE_NAME_SIZE-1] = 0; // make sure the string has the end
                    res_file_name_size = strlen(res_filename) + 1;
                    if(res_file_name_size > (MAX_RES_FILE_NAME_SIZE)){
                        res_file_name_size = (MAX_RES_FILE_NAME_SIZE);
                    }
                    g_mmi_rp_mgr_cntx.app_res_filepath[base_idx] = (U8*) malloc( sizeof(U8) * (res_file_name_size));
                    memset(g_mmi_rp_mgr_cntx.app_res_filepath[base_idx], 0, sizeof(U8) * res_file_name_size );
                    strncpy(g_mmi_rp_mgr_cntx.app_res_filepath[base_idx],res_filename, res_file_name_size - 1);
                    
                    /* output log of output_file -> input_file */
                    strcpy(str_name, "mmi_rp_");
                    strcat(str_name, g_mmi_rp_mgr_cntx.cur_app->appname);
                    strcat(str_name, ".c\t");
                    strcat(str_name, g_mmi_rp_mgr_cntx.cur_app->res_path);
                    strcpy(cur_filename, g_cur_filename); // add for multi <APP/> in .res
                    temp_str = strstr(/*g_cur_filename*/cur_filename, ".i");
                    if (temp_str == NULL)
                    {
                        MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_PARSE_ERROR, "ERROR: .i filename error");
                        return MMI_RP_PARSE_ERROR_SKIP_TAG;
                    }
                    strcpy(temp_str, ".res");
                    strcat(str_name, /*g_cur_filename*/cur_filename);

                    for(i = 0; i < strlen(str_name); i++)
                    {
                        str_name[i] = tolower(str_name[i]);
                    }
                    fprintf(g_output_log_file, "%s\n", str_name);
                    
                    break;
                }
                base_idx++;
            }
            if(g_mmi_rp_mgr_cntx.cur_app == NULL)
            {
                break;
            }
            curr_app_id = (U8*)attr[attr_idx + 1];
        }
        else if(strcmp(attr[attr_idx], MMI_RP_MGR_ATTR_APP_TYPE) == 0)
        {
            curr_app_type = (U8*)attr[attr_idx + 1];
        }
        else if(strcmp(attr[attr_idx], MMI_RP_MGR_ATTR_NAME) == 0)
        {
            curr_app_str = (U8*)attr[attr_idx + 1];
        }
        else if(strcmp(attr[attr_idx], MMI_RP_MGR_ATTR_IMG) == 0)
        {
            curr_app_img = (U8*)attr[attr_idx + 1];
        }
        else if(strcmp(attr[attr_idx], MMI_RP_MGR_ATTR_PACKAGE_NAME) == 0)
        {
            curr_app_package_name = (U8*)attr[attr_idx + 1];
        }
        else if(strcmp(attr[attr_idx], MMI_RP_MGR_ATTR_LAUNCH) == 0)
        {
            curr_app_launch_func = (U8*)attr[attr_idx + 1];
        }
        else if(strcmp(attr[attr_idx], MMI_RP_MGR_ATTR_PACKAGE_PROC) == 0)
        {
            curr_app_package_proc = (U8*)attr[attr_idx + 1];
        }
        else if(strcmp(attr[attr_idx], MMI_RP_MGR_ATTR_HIDDEN_IN_MAINMENU) == 0)
        {
            curr_app_hidden_in_mainmenu = (U8*)attr[attr_idx + 1];
        }
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            // continue parse remaining attributes
        }

        attr_idx += 2;
    }

    // if not found current APP, error. skip this tag
    if (g_mmi_rp_mgr_cntx.cur_app == NULL)
    {
        printf("ERROR: APP tag unknown app[%s]\n", attr[attr_idx+1]);
        MMI_RP_ERROR(RP_ERR_APP_UNKNOWN);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /* Call resources set app_range functions */
    mmi_rp_menu_set_app_range();
    mmi_rp_str_set_app_range();
    mmi_rp_scr_set_app_range();
    mmi_rp_timer_set_app_range();
    mmi_rp_event_set_app_range();
    mmi_rp_aud_set_app_range();
    mmi_rp_img_set_app_range();
    mmi_rp_theme_set_app_range();

    /* set range of  cust resource type */
    i=0;
    while(g_res_handlers_cust[i].mmi_rp_res_set_range != mmi_rp_end_function)
    {
        g_res_handlers_cust[i].mmi_rp_res_set_range();
        i++;
    }

    /* save app_type for <MEMORY> to use */
    if ((curr_app_type != NULL) && (g_mmi_rp_mgr_cntx.app_type[g_mmi_rp_mgr_cntx.cur_app_index] == NULL))
    {
        g_mmi_rp_mgr_cntx.app_type[g_mmi_rp_mgr_cntx.cur_app_index] = (U8**)malloc(strlen(curr_app_type)+1);
        strcpy((U8*)g_mmi_rp_mgr_cntx.app_type[g_mmi_rp_mgr_cntx.cur_app_index], curr_app_type);
    }
    /* Add app id for APP */
    if((curr_app_id != NULL) && (g_mmi_rp_mgr_cntx.app_id[g_mmi_rp_mgr_cntx.cur_app_index] == NULL))
    {
        /* We just keep "app_id" resource id, the application need to define app resource by <APP id> */
        g_mmi_rp_mgr_cntx.app_id[g_mmi_rp_mgr_cntx.cur_app_index] = (U8**)malloc(strlen(curr_app_id)+1);
        strcpy((U8*)g_mmi_rp_mgr_cntx.app_id[g_mmi_rp_mgr_cntx.cur_app_index], curr_app_id);
    }
    
    /* Add string id for APP name */
    if((curr_app_str != NULL) && (g_mmi_rp_mgr_cntx.app_str_id[g_mmi_rp_mgr_cntx.cur_app_index] == NULL))
    {

      /* @OID prefix and string size boundary check */
      if( strlen(curr_app_str) > MMI_RP_PREFIX_OID_LEN && strstr(curr_app_str, MMI_RP_PREFIX_OID))
      {
        /* Allow user to use gloabl string as app name here*/
        g_mmi_rp_mgr_cntx.app_str_id[g_mmi_rp_mgr_cntx.cur_app_index] = (U8**)malloc(strlen(curr_app_str+MMI_RP_PREFIX_OID_LEN)+1);
        strcpy((U8*)g_mmi_rp_mgr_cntx.app_str_id[g_mmi_rp_mgr_cntx.cur_app_index], curr_app_str+MMI_RP_PREFIX_OID_LEN);     
      }else{
        /* In original design, "name" will be added in string resource automatically. */
        g_mmi_rp_mgr_cntx.app_str_id[g_mmi_rp_mgr_cntx.cur_app_index] = mmi_rp_str_add_app_name_str_id(curr_app_str);
      }
    }
    /* Add image id for APP name */
    if((curr_app_img != NULL) && (g_mmi_rp_mgr_cntx.app_img_id[g_mmi_rp_mgr_cntx.cur_app_index] == NULL))
    {
        /* We just keep "image" resource id, the application need to define image resource by <IMAGE> */
        g_mmi_rp_mgr_cntx.app_img_id[g_mmi_rp_mgr_cntx.cur_app_index] = (U8**)malloc(strlen(curr_app_img)+1);
        strcpy((U8*)g_mmi_rp_mgr_cntx.app_img_id[g_mmi_rp_mgr_cntx.cur_app_index], curr_app_img);
    }
    /* Add app package name (UTF8 string) for APP name */
    if((curr_app_package_name != NULL) && (g_mmi_rp_mgr_cntx.app_package_name[g_mmi_rp_mgr_cntx.cur_app_index] == NULL))
    {
        /* We will keep "package_name" and put it into native_app_package_table[] */
        g_mmi_rp_mgr_cntx.app_package_name[g_mmi_rp_mgr_cntx.cur_app_index] = (U8**)malloc(strlen(curr_app_package_name)+1);
        strcpy((U8*)g_mmi_rp_mgr_cntx.app_package_name[g_mmi_rp_mgr_cntx.cur_app_index], curr_app_package_name);
    }
    else
    {
        /* "package_name" is mandatory element, and we will dump error message if it doesn't exist.  */
        MMI_RP_PARSE_WARNING(RP_WARN_APP_PACKAGE_NAME_UNKNOWN);
    }
    /* Add application launch function */
    if((curr_app_launch_func != NULL) && (g_mmi_rp_mgr_cntx.app_launch_func[g_mmi_rp_mgr_cntx.cur_app_index] == NULL))
    {
        if (curr_app_package_name == NULL)
        {
            /* If using "launch", it must have "package_name" */
            MMI_RP_ERROR(RP_ERR_APP_PACKAGE_NAME_MISSING);
        }
        else
        {
            /* We will keep "launch" and put it into native_app_package_table[] */
            g_mmi_rp_mgr_cntx.app_launch_func[g_mmi_rp_mgr_cntx.cur_app_index] = (U8**)malloc(strlen(curr_app_launch_func)+1);
            strcpy((U8*)g_mmi_rp_mgr_cntx.app_launch_func[g_mmi_rp_mgr_cntx.cur_app_index], curr_app_launch_func);
        }
    }
    /* Add application package proc */
    if((curr_app_package_proc != NULL) && (g_mmi_rp_mgr_cntx.app_package_proc[g_mmi_rp_mgr_cntx.cur_app_index] == NULL))
    {
        if (curr_app_package_name == NULL)
        {
            /* If using "launch", it must have "package_name" */
            MMI_RP_ERROR(RP_ERR_APP_PACKAGE_NAME_MISSING);
        }
        else
        {
            /* We will keep "package_proc" and put it into native_app_package_table[] */
            g_mmi_rp_mgr_cntx.app_package_proc[g_mmi_rp_mgr_cntx.cur_app_index] = (U8**)malloc(strlen(curr_app_package_proc)+1);
            strcpy((U8*)g_mmi_rp_mgr_cntx.app_package_proc[g_mmi_rp_mgr_cntx.cur_app_index], curr_app_package_proc);
        }
    }
    /* the application will be shown in main menu. It is the default value */
    g_mmi_rp_mgr_cntx.app_hidden_in_mainmenu[g_mmi_rp_mgr_cntx.cur_app_index] = MMI_FALSE;
    if((curr_app_hidden_in_mainmenu != NULL) && (g_mmi_rp_mgr_cntx.app_hidden_in_mainmenu[g_mmi_rp_mgr_cntx.cur_app_index] == NULL))
    {
        /* We set the application flag according "hidden_in_mainmenu" */
        if (strcmp(curr_app_hidden_in_mainmenu, "true") == 0)
        {
            g_mmi_rp_mgr_cntx.app_hidden_in_mainmenu[g_mmi_rp_mgr_cntx.cur_app_index] = MMI_TRUE;
        }
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_app_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mgr_app_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("APP-end: %s\n", el);

    /* if app end, set app name to NULL */
    if (g_mmi_rp_mgr_cntx.cur_app != NULL)
    {
        g_mmi_rp_mgr_cntx.cur_app = NULL;

        /* Reset Resource folder when APP end */
        mmi_rp_mgr_path_reset();
    }
    else
    {
        /* Start tag not found, error. */
        MMI_RP_ERROR(RP_ERR_TAG_APP_END);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_app_data_handler
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
int mmi_rp_mgr_app_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("APP-data: %s\n", data);
    return MMI_RP_PARSE_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_line_start_handler
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
int mmi_rp_mgr_line_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 attr_idx = 0;
    U32 base_idx = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((NULL != attr[attr_idx]) && (NULL != attr[attr_idx + 1]))
    {
        if (attr[attr_idx][0] == MMI_RP_MGR_ATTR_LINE)
        {
            g_mmi_rp_mgr_cntx.xml_error.error_line = atoi(attr[attr_idx + 1]);
        }
        attr_idx += 2;
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_line_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mgr_line_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_line_data_handler
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
int mmi_rp_mgr_line_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RP_PARSE_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_include_start_handler
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
int mmi_rp_mgr_include_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 attr_idx = 0;
    U32 base_idx = 0;
    S32 parent_tag_id = -1;
    U8 *file_str = NULL, *last = NULL;
    U8 temp[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("INCLUDE-start: %s\n", el);

    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    memset(temp, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    
    while ((NULL != attr[attr_idx]) && (NULL != attr[attr_idx + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[attr_idx], attr[attr_idx + 1]);

        if(strcmp(attr[attr_idx], MMI_RP_MGR_ATTR_FILE) == 0)
        {
            file_str = (U8*)attr[attr_idx + 1];
            if(g_mmi_rp_mgr_cntx.app_include[g_mmi_rp_mgr_cntx.cur_app_index])           /* 1 INCLUDE tag per app. If this is the second INCLUDE tag, add the file name appended by ','. */
            {
                last = g_mmi_rp_mgr_cntx.app_include[g_mmi_rp_mgr_cntx.cur_app_index];
                strcpy(temp, last);
                strcat(temp, ",");
                strcat(temp, file_str);
                g_mmi_rp_mgr_cntx.app_include[g_mmi_rp_mgr_cntx.cur_app_index] = (U8*)mmi_rp_hash_add(g_mmi_rp_mgr_cntx.hash, temp);
            }
            else
            {
                g_mmi_rp_mgr_cntx.app_include[g_mmi_rp_mgr_cntx.cur_app_index] = (U8*)mmi_rp_hash_add(g_mmi_rp_mgr_cntx.hash, (U8*)attr[attr_idx + 1]);
            }
        }
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }

        attr_idx += 2;
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_include_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mgr_include_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("INCLUDE-end: %s\n", el);
    return MMI_RP_PARSE_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_path_start_handler
 * DESCRIPTION
 *  This function is for XML parser to return path tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  attr        [IN]        Attribute list
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mgr_path_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 attr_idx = 0;
    U32 base_idx = 0;
    S32 parent_tag_id = -1;
    U8 *path_str = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("PATH-start: %s\n", el);
   
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    while ((NULL != attr[attr_idx]) && (NULL != attr[attr_idx + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[attr_idx], attr[attr_idx + 1]);

        if(strcmp(attr[attr_idx], MMI_RP_MGR_ATTR_TYPE) == 0)
        {
            if (!strcmp(attr[attr_idx + 1], MMI_RP_MGR_VAL_IMAGE))
            {
                g_mmi_rp_mgr_cntx.path.path_type = MMI_RP_RES_PATH_IMG;
            }
            else if (!strcmp(attr[attr_idx + 1], MMI_RP_MGR_VAL_AUDIO))
            {
                g_mmi_rp_mgr_cntx.path.path_type = MMI_RP_RES_PATH_ADO;
            }
            else
            {
                MMI_RP_PARSE_WARNING(RP_WARN_INVALID_CONT);
            }
        }
        else
        {
            MMI_RP_ERROR(RP_ERR_UNKNOWN_ATTR);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }

        attr_idx += 2;
    }
    g_mmi_rp_mgr_cntx.path.is_null = MMI_TRUE;
    return MMI_RP_PARSE_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_path_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return path tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mgr_path_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("PATH-end: %s\n", el);

     if(g_mmi_rp_mgr_cntx.path.is_null)
    {
        mmi_rp_mgr_path_reset();
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_path_data_handler
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
int mmi_rp_mgr_path_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0;
    U8 temp[MMI_RP_MGR_MAX_FILE_NAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* remove " in string */
    while(data[i] != '\0')
    {
        if (data[i] != '"')
        {
            temp[j] = data[i];
            j++;
        }
        i++;
    }
    temp[j] = '\0';

    switch(g_mmi_rp_mgr_cntx.path.path_type)
    {
    case MMI_RP_RES_PATH_IMG:
        strcpy(g_mmi_rp_mgr_cntx.path.def_img_path, temp);
        break;

    case MMI_RP_RES_PATH_ADO:
        strcpy(g_mmi_rp_mgr_cntx.path.def_ado_path, temp);
        break;

    default:
        MMI_RP_ERROR(RP_ERR_PATH_TYPE_NOT_FOUND);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    g_mmi_rp_mgr_cntx.path.is_null = MMI_FALSE;
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_path_reset
 * DESCRIPTION
 *  Reset resource path to default path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mgr_path_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_mmi_rp_mgr_cntx.path.def_img_path, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    memset(g_mmi_rp_mgr_cntx.path.def_ado_path, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_trace_warning
 * DESCRIPTION
 *  This function is output warning log.
 * PARAMETERS
 *  index       [IN]      Warning index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mgr_trace_warning(U32 index, U8* string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *err_string = NULL;

    MMI_BOOL is_from_parser = g_mmi_rp_is_in_parse_phase;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(index)
    {
    case RP_WARN_RES_ID_NULL:
        err_string = "Resource ID is NULL";
        break;
    case RP_WARN_APP_PACKAGE_NAME_UNKNOWN:
        err_string = "App \"package_name\" string ID is not found.";
        break;
    case RP_WARN_UNKNOW_ATTR:
        err_string = "Unknown atribute";
        break;
    case RP_WARN_INVALID_CONT:
        err_string = "Invalid content";
        break;
    case RP_WARN_USE_ERROR:
        err_string = "Wrong usage";
        break;
    case RP_WARN_USE_ERROR_MENUSET:
        err_string = "Wrong usage : No MENUSET or menu id is null";
        break;
    case RP_WARN_USE_ERROR_SEPARATOR:
        err_string = "Wrong usage : Separator Menu should not have data field";
        break;
    case RP_WARN_DUPLICATE_ID:
        err_string = "Duplicate ID";
        break;
    case RP_WARN_RES_COUNT_ZERO:
        // avoid SPAMMING
        //err_string = "Resource count 0";
        break;
    case RP_WARN_CHILD_MENU_ID_NOT_FOUND:
        err_string = "Child menu ID not found";
        break;
    case RP_WARN_GROUP_NAME_NOT_FOUND:
        err_string = "Group name not found";
        break;
    case RP_WARN_HASH_SAME_STRING:
        // avoid SPAMMING
        //err_string = "Hash same string";
        break;
    case RP_WARN_MEM_CONFIG_NOT_SPECIFIED:
        err_string = "This app doesn't specify mem-config";
        break;
    case RP_WARN_BUFFER_LENGTH_EXCEEDED:
        err_string = "Buffer length overrun. Data not processed.";
        break;
    case RP_WARN_DUPLICATE_UNIQUE_KEY:
        err_string = "Duplicated naming or key in mmi cache item.";
        break;
    case RP_WARN_UNKNOWN_VAL:
        err_string = "Unknown value, cannot parse";
        break;
    default:
        err_string = "Unknown warning";
        break;
    }

    if(!err_string)
        return;

    if(is_from_parser)
    {
        if (string == NULL)
        {
            printf("WARNING: [%d] %s, File=[%s] Line=[%d]  \n", index, err_string, g_mmi_rp_mgr_cntx.xml_error.error_file, g_mmi_rp_mgr_cntx.xml_error.error_line);
        }
        else
        {
            printf("WARNING: [%d] %s, File=[%s] Line=[%d] data=%s\n", index, err_string, g_mmi_rp_mgr_cntx.xml_error.error_file, g_mmi_rp_mgr_cntx.xml_error.error_line, string);
        }
    }
    else
    {
        if (string == NULL)
        {
            printf("WARNING: [%d] %s\n", index, err_string);
        }
        else
        {
            printf("WARNING: [%d] %s, data=%s\n", index, err_string, string);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_trace_error
 * DESCRIPTION
 *  This function is output error log.
 * PARAMETERS
 *  index       [IN]      Error index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_mgr_trace_error(U32 index, U8* string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *err_string = NULL;

    MMI_BOOL is_from_parser = g_mmi_rp_is_in_parse_phase;

    g_mmi_rp_mgr_cntx.program_error = 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(index)
    {
    case RP_ERR_APP_UNKNOWN:
        err_string = "APP unknown";
        break;
    case RP_ERR_APP_PACKAGE_NAME_MISSING:
        err_string = "Must define \"package_name\" attribute.";
        break;
    case RP_ERR_TAG_UNKNOWN:
        err_string = "Tag unknown";
        break;
    case RP_ERR_UNKNOWN_ATTR:
        err_string = "Unknown attribute";
        break;
    case RP_ERR_TAG_OPEN_TWICE:
        err_string = "Tag open twice";
        break;
    case RP_ERR_MENU_PARENT_STACK_OVERFLOW_ERROR:
        err_string = "Menu parent stack is overflown";
        break;
    case RP_ERR_TAG_STACK_OVERFLOW:
        err_string = "Tags stack is overflown";
        break;
    case RP_ERR_TAG_STACK_UNDERFLOW:
        err_string = "Tags stack is underflown";
        break;
    case RP_ERR_TAG_USE_ERROR:
        err_string = "Tag use error";
        break;
    case RP_ERR_TAG_ENFB_OPEN_TWICE:
        err_string = "ENFB tag opened twice";
        break;
    case RP_ERR_TAG_ENFB_CLOSE_TWICE:
        err_string = "ENFB tag closed twice";
        break;
    case RP_ERR_TAG_MENUITEM_ID_NOT_SPECIFIED:
        err_string = "No menu item ID is specified";
        break;
    case RP_ERR_TAG_MENUSET_ID_NOT_SPECIFIED:
        err_string = "No menu set ID is specified";
        break;
    case RP_ERR_TAG_APP_END:
        err_string = "APP end tag : No app specified";
        break;
    case RP_ERR_PATH_TYPE_NOT_FOUND:
        err_string = "Path res type (audio/image) not found";
        break;
    case RP_ERR_TAG_NOT_SUPPORT_DATA:
        err_string = "Tag do not support DATA";
        break;
    case RP_ERR_EXCEED_ID_RANGE:
        err_string = "Exceed ID range";
        break;
    case RP_ERR_EXCEED_CHILDREN_MENU_SIZE:
        err_string = "Exceed child menu size";
        break;
    case RP_ERR_MEMORY_NOT_AVAILABLE:
        err_string = "Memory not available";
        break;
    case RP_ERR_WRITE_OUPUT_PHASE1:
        err_string = "Output phase 1";
        break;
    case RP_ERR_WRITE_OUPUT_PHASE2:
        err_string = "Output phase 2";
        break;
    case RP_ERR_ID_NOT_FOUND:
        err_string = "ID not found";
        break;
    case RP_ERR_MEM_CONFIG_NOT_SUFFICIENT_DATA:
        err_string = "Not sufficient data for mem-config";
        break;
    case RP_ERR_MEM_CONFIG_CONCURRENT_APPS_EXCEED:
        err_string = "No of concurrent apps exceeded the range";
        break;
    case RP_ERR_MEM_CONFIG_APP_DATA_ALREADY_DECLARED:
        err_string = "This app has already declared mem-config.";
        break;
    case RP_ERR_MEM_CONFIG_APP_NAME_STR_ID_NOT_FOUND:
        err_string = "App \"name\" string ID not found.";
        break;
    case RP_ERR_STRING_MISSING_ENCLOSING_QUOTES:
        err_string = "String is missing one of the enclosing double quote.";
        break;
    case RP_ERR_MENU_SHORTCUT_EXCEED_MAX_RANGE:
        err_string = "Shortcut array size overrun.";
        break;
    case RP_ERR_MENU_SHORTCUT_NO_LAUNCH_FUNC:
        err_string = "Shortcut launch function is not specified.";
        break;
    case RP_ERR_MENU_SHORTCUT_IMAGE_ID_NOT_SPECIFIED:
        err_string = "Shortcut image ID is not specified.";
        break;
    case RP_ERR_MENU_SHORTCUT_IMAGE_ID_NOT_FOUND:
        err_string = "Shortcut image ID is not populated.";
        break;
    case RP_ERR_BUFFER_LENGTH_EXCEEDED:
        err_string = "Buffer length overrun. Data not processed.";
        break;
    case RP_ERR_VAL_UNKNOWN:
        err_string = "Format of data is wrong or unacceptable";
        break;
    case RP_ERR_DUPLICATE_UNIQUE_KEY:
        err_string = "Duplicated naming or key in mmi cache item.";
        break;
    default:
        err_string = "Unknown error";
        break;
    }

    if(is_from_parser)
    {
        if (string == NULL)
        {
            printf("PARSER ERROR: [%d] %s, File=[%s] Line=[%d]\n", index, err_string, g_mmi_rp_mgr_cntx.xml_error.error_file, g_mmi_rp_mgr_cntx.xml_error.error_line);
            fprintf(stderr, "PARSER ERROR: [%d] %s, File=[%s] Line=[%d]\n", index, err_string, g_mmi_rp_mgr_cntx.xml_error.error_file, g_mmi_rp_mgr_cntx.xml_error.error_line);
        }
        else
        {
            printf("PARSER ERROR: [%d] %s, File=[%s] Line=[%d] data=[%s]\n", index, err_string, g_mmi_rp_mgr_cntx.xml_error.error_file, g_mmi_rp_mgr_cntx.xml_error.error_line, string);
            fprintf(stderr, "PARSER ERROR: [%d] %s, File=[%s] Line=[%d] data=[%s]\n", index, err_string, g_mmi_rp_mgr_cntx.xml_error.error_file, g_mmi_rp_mgr_cntx.xml_error.error_line, string);
        }
    }
    else
    {
        if (string == NULL)
        {
            printf("ERROR: [%d] %s\n", index, err_string);
            fprintf(stderr,  "ERROR: [%d] %s\n", index, err_string);
        }
        else
        {
            printf("ERROR: [%d] %s data=[%s]\n", index, err_string, string);
            fprintf(stderr,  "ERROR: [%d] %s data=[%s]\n", index, err_string, string);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_compare_output_files_int
 * DESCRIPTION
 *  Output all resource to dest files
 * PARAMETERS
 *  mmi_rp_compare_files_enum
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_compare_output_files_int(mmi_rp_compare_files_enum file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error = 0;
    
    FILE *p_file = NULL;
    WIN32_FIND_DATA file_data;
    HANDLE folder_file = NULL;
    BOOL fFinished = FALSE;

    U8 file_name1[MMI_RP_MGR_MAX_FILE_NAME_LEN], file_name2[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    S8 sys_str[MMI_RP_MGR_MAX_SYS_CMD_LEN];

    S8 *p_search = NULL, *p_source_path = NULL, *p_dest_path = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(file_type)
    {
        case MMI_RP_COMPARE_INC_FILES :
        {
            p_search = MMI_RP_MGR_XML_TEMP_CMP_H_FILES_SEARCH;
            p_source_path = MMI_RP_MGR_XML_TEMP_CMP_H_FILES;
            p_dest_path = MMI_RP_MGR_XML_DEF_FOLDER;
            break;
        }
        case MMI_RP_COMPARE_SRC_FILES :
        {
            p_search = MMI_RP_MGR_XML_TEMP_CMP_C_FILES_SEARCH;
            p_source_path = MMI_RP_MGR_XML_TEMP_CMP_C_FILES;
            p_dest_path = MMI_RP_MGR_XML_SEARCH_PATH;
            break;
        }
        case MMI_RP_COMPARE_CUSTRESOURCE_FILES :
        {
            p_search = MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES_SEARCH;
            p_source_path = MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES;
            p_dest_path = MMI_RP_MGR_XML_CUSTRESOURCE_PATH;
            break;
        }
    }

    folder_file = FindFirstFile(p_search, &file_data);
    if (folder_file == INVALID_HANDLE_VALUE)
    {
        printf("Compare : Didn't find any file ret=[%d]\n", GetLastError());
        return;
    }
    else
    {
        printf("Compare : FindFirstFile[%s]\n", file_data.cFileName);
    }
    
    while (!fFinished)
    {
        memset(file_name1, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
        memset(file_name2, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
        memset(sys_str, 0, MMI_RP_MGR_MAX_SYS_CMD_LEN);

        /* New file name */
        strcpy((S8*)file_name1, p_source_path);
        strcat((S8*)file_name1, file_data.cFileName);

        /* Old file name */
        strcpy((S8*)file_name2, p_dest_path);
        strcat((S8*)file_name2, file_data.cFileName);

        p_file = fopen(file_name2, "r");
        if(!p_file)
        {
            /* New file does not exist. copy it. */
            sprintf(sys_str, "copy /Y %s %s > nul", file_name1, p_dest_path);
            system(sys_str);
        }
        else
        {
            fclose(p_file);
            /* New file exists. Compare it. */
            memset(sys_str, 0, MMI_RP_MGR_MAX_SYS_CMD_LEN);
            sprintf(sys_str, "fc /b %s %s > nul", file_name1, file_name2);
            error = system(sys_str);
            if(error)
            {
                /* Diff found. copy new file. */
                memset(sys_str, 0, MMI_RP_MGR_MAX_SYS_CMD_LEN);
                sprintf(sys_str, "copy /Y %s %s > nul", file_name1, p_dest_path);
                system(sys_str);
                printf("Compare : File compare[%s] :-> Difference found. \n", file_name1);
            }
            else
            {
                /* Files are same. Don't overwrite. */
                printf("Compare : File compare[%s] :-> No difference found. \n", file_name1);
            }
        }

        if (!FindNextFile(folder_file, &file_data))
        {
            printf("Compare : No more files. Search completed.\n");
            fFinished = TRUE;
        }
        else
        {
            printf("Compare : FindNextFile[%s]\n", file_data.cFileName);
        }
    }

    /* Close the search handle. */
    if (!FindClose(folder_file))
    {
        MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_GENERIC_ERROR, "Compare : Couldn't close search handle.");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_compare_prologue_int
 * DESCRIPTION
 *  Delete all files which are not needed.
 * PARAMETERS
 *  mmi_rp_compare_files_enum
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_compare_prologue_int(mmi_rp_compare_files_enum file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error = 0;
    
    FILE *p_file = NULL;
    WIN32_FIND_DATA file_data;
    HANDLE folder_file = NULL;
    BOOL fFinished = FALSE;

    U8 file_name1[MMI_RP_MGR_MAX_FILE_NAME_LEN], file_name2[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    S8 sys_str[MMI_RP_MGR_MAX_SYS_CMD_LEN];

    S8 *p_search = NULL, *p_source_path = NULL, *p_dest_path = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(file_type)
    {
        case MMI_RP_COMPARE_INC_FILES :
        {
            p_search = MMI_RP_MGR_XML_AUTOGENERATED_H_FILES_SEARCH;
            p_source_path = MMI_RP_MGR_XML_TEMP_CMP_H_FILES;
            p_dest_path = MMI_RP_MGR_XML_DEF_FOLDER;
            break;
        }
        case MMI_RP_COMPARE_SRC_FILES :
        {
            p_search = MMI_RP_MGR_XML_AUTOGENERATED_C_FILES_SEARCH;
            p_source_path = MMI_RP_MGR_XML_TEMP_CMP_C_FILES;
            p_dest_path = MMI_RP_MGR_XML_SEARCH_PATH;
            break;
        }
        case MMI_RP_COMPARE_CUSTRESOURCE_FILES :
        {
            p_search = MMI_RP_MGR_XML_AUTOGENERATED_CUSTRESOURCE_C_FILES_SEARCH;
            p_source_path = MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES;
            p_dest_path = MMI_RP_MGR_XML_CUSTRESOURCE_PATH;
            break;
        }
    }

    folder_file = FindFirstFile(p_search, &file_data);
    if (folder_file == INVALID_HANDLE_VALUE)
    {
        printf("Resgen XML Prologue : Didn't find any file ret=[%d]\n", GetLastError());
        return;
    }
    else
    {
        printf("Resgen XML Prologue : FindFirstFile[%s]\n", file_data.cFileName);
    }
    
    while (!fFinished)
    {
        memset(file_name1, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
        memset(file_name2, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
        memset(sys_str, 0, MMI_RP_MGR_MAX_SYS_CMD_LEN);

        /* New file name */
        strcpy((S8*)file_name1, p_source_path);
        strcat((S8*)file_name1, file_data.cFileName);

        /* Old file name */
        strcpy((S8*)file_name2, p_dest_path);
        strcat((S8*)file_name2, file_data.cFileName);

        p_file = fopen(file_name1, "r");
        if(!p_file)
        {
            /* New file does not exist. No need of it now. Delete it. */
            sprintf(sys_str, "del %s > nul", file_name2);
            system(sys_str);
            printf("Resgen XML Prologue : This file is not needed now and is deleted -> %s \n", file_name2);
        }
        else
        {
            fclose(p_file);
            /* New file exists. Check next. */
        }

        if (!FindNextFile(folder_file, &file_data))
        {
            printf("Resgen XML Prologue : No more files. Search completed.\n");
            fFinished = TRUE;
        }
        else
        {
            printf("Resgen XML Prologue : FindNextFile[%s]\n", file_data.cFileName);
        }
    }

    /* Close the search handle. */
    if (!FindClose(folder_file))
    {
        MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_GENERIC_ERROR, "Resgen XML Prologue : Couldn't close search handle.");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_compare_prologue
 * DESCRIPTION
 *  Delete all files which are not needed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_compare_prologue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rp_compare_prologue_int(MMI_RP_COMPARE_INC_FILES);
    mmi_rp_compare_prologue_int(MMI_RP_COMPARE_SRC_FILES);
    mmi_rp_compare_prologue_int(MMI_RP_COMPARE_CUSTRESOURCE_FILES);
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_compare_output_files
 * DESCRIPTION
 *  Output all resource to dest files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rp_compare_output_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. Prepare the list of existing .c and .h files
     *      Problem : The files are compared after parsing and only those files are copied from TEMP folders to DEST folders which are changed.
     *      Some files may be left in the DEST folders which are not needed after some modification. They're not deleted.
     *      So, We'll prepare a list of files in ORG and TEMP folders prior to compare and will check which files are not needed.
     *      We'll delete those files so that they're not compiled unnecessarilty.
     */
    mmi_rp_compare_prologue();

    /* 2. Compare .h files */
    mmi_rp_compare_output_files_int(MMI_RP_COMPARE_INC_FILES);
    /* 3. Compare .c files */
    mmi_rp_compare_output_files_int(MMI_RP_COMPARE_SRC_FILES);
    /* 4. Compare CustResource\*.c files */
    mmi_rp_compare_output_files_int(MMI_RP_COMPARE_CUSTRESOURCE_FILES);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mgr_path_create
 * DESCRIPTION
 *  Create a full path and remove '"' and ' '
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_rp_mgr_path_create(U8 *dest, U8 *prefix, U8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest[0] = '"';
    dest[1] = '\0';
    
    strcat(dest, prefix);
    j = strlen(dest);
    i = 0;

    /* remove " in string */
    while(path[i] != '\0')
    {
        if (path[i] != '"')
        {
            dest[j] = path[i];
            j++;
        }
        i++;
    }

    dest[j] = '"';
    dest[j+1] = '\0';

    return j+1;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_rp_create_population_c_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
FILE * mmi_rp_open_population_c_file(U32 app_index, U8 res_pop_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U8 str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    U8 *temp1 = NULL, *temp2 = NULL, *temp_str = NULL;
    CHAR * str_output_filename = NULL;
    CHAR* str_output_filename_header = NULL;
    CHAR * str_function_name = NULL;

    if(app_index<0 || app_index> g_mmi_rp_mgr_cntx.total_apps ){
           return;
    }
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_mmi_rp_mgr_cntx.populating_file_created[app_index]==RES_LEGACY_POP_NON){
    
        str_output_filename = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_C_FILE_PATH, g_mmi_resource_base_table[app_index].appname);
        /* Header file name*/
        str_output_filename_header = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_H_FILE, g_mmi_resource_base_table[app_index].appname);
        /* Populate function name */
        str_function_name = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_POPULATE_FUNCTION, g_mmi_resource_base_table[app_index].appname);
        /* dotC file name */

        if(p_file = fopen(str_output_filename, "w"))            /* Rest resources will open the file in append mode */
        {
            mmi_rp_write_copy_right_header_in_file(p_file);
            mmi_rp_write_file_header_in_file(
                p_file, 
           mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_C_FILE, g_mmi_resource_base_table[app_index].appname), 
                "Resource populate function generated by XML resgen", 
                "MTK resgenerator XML parser");
            mmi_rp_output_phase2_begin(p_file, str_function_name, str_output_filename_header, g_mmi_rp_mgr_cntx.app_include[app_index]);             /* Will finish in the last resource output phase 2 */
            //fclose(p_file);
            mmi_rp_mgr_output_populate_func(str_function_name);         /* Writes the function call in mmi_rp_populate.c */
            g_mmi_rp_mgr_cntx.populating_file_created[app_index]|= res_pop_mask;
            return p_file;
        }
        else
        {
            /* Error writing output file. Exit. */
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
        }
    }else{
        str_output_filename = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_C_FILE_PATH, g_mmi_resource_base_table[app_index].appname);
        //open file in append mode
        p_file = fopen(str_output_filename, "a");
        
             if(p_file== NULL)            /* Rest resources will open the file in append mode */
             {
                 MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
             }else{
                return p_file;
             }
}

}

