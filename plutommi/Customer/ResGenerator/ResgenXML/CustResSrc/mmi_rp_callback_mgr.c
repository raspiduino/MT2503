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
 *============================================================================== 
 *******************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MMIDataType.h"
#include "mmi_rp_xml.h"
#include "mmi_rp_xml_def.h"
#include "mmi_rp_hash.h"
#include "mmi_rp_cust_template.h"
#include "mmi_rp_event.h"

extern const mmi_resource_base_struct g_mmi_resource_base_table[];
extern mmi_rp_event_type_list_node_struct *g_mmi_rp_event_type_list_header;
extern mmi_rp_event_cntx_struct g_mmi_rp_event_cntx;
#define CALLBACK_MGR_ID_ATTRI  "id"
#define CALLBACK_MGR_ID_SEND_ATTRI  "hfile"
#define CALLBACK_MGR_ID_RECIEVE_ATTRI  "proc"




typedef struct _mmi_rp_callback_mgr_sender
{
    char *id;
    char *headerfile;
    struct _mmi_rp_callback_mgr_sender *next;
} mmi_rp_callback_mgr_sender;


typedef struct _mmi_rp_callback_mgr_reciever
{
    char *id;
    char *proc;
    struct _mmi_rp_callback_mgr_reciever *next;
} mmi_rp_callback_mgr_reciever;


typedef struct
{
  mmi_rp_callback_mgr_sender *shead;
  mmi_rp_callback_mgr_sender *stail;
  mmi_rp_callback_mgr_reciever *rhead;
  mmi_rp_callback_mgr_reciever *rtail;
  mmi_rp_hash_struct *hash_headerfile;
} mmi_rp_callback_mgr_cntx;


static mmi_rp_callback_mgr_cntx g_mmi_rp_callback_cntx;

#define MMI_RP_CALLBACK_MGR_HEADER_FILE  "mmi_rp_callback_mgr_header_file.h"
#define MMI_RP_CALLBACK_MGR_CONFIG_FILE  "mmi_rp_callback_mgr_config.h"
#define MMI_RP_CALLBACK_MGR_LOG_FILE     "mmi_rp_callback.log"
#define MMI_RP_CALLBACK_MGR_TABLE_FILE    "mmi_rp_callback_mgr_table.c"


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
void mmi_rp_callback_mgr_init(void)
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
    memset(&g_mmi_rp_callback_cntx, 0, sizeof(mmi_rp_callback_mgr_cntx));
    g_mmi_rp_callback_cntx.hash_headerfile = mmi_rp_hash_create(0xFFFF);
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
void mmi_rp_callback_mgr_set_app_range(void)
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
 *  mmi_rp_callback_mgr_sender_start_handler
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
int mmi_rp_callback_mgr_sender_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    mmi_rp_callback_mgr_sender *sendattri;
    mmi_rp_callback_mgr_sender  *temp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Callback MGR Sender -start: %s\n", el);
    
    if ((!attr[index]) || (!attr[index + 1]) || (!attr[index + 2]) || (!attr[index + 3]))
    {
        //error message
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    if (strcmp(attr[index], CALLBACK_MGR_ID_ATTRI) != 0)
    {
        //error message
        MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
    }
    if (strcmp(attr[index + 2], CALLBACK_MGR_ID_SEND_ATTRI) != 0)
    {
        //error message
        MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index + 2]);
    }
    if ((strcmp(attr[index + 3], "NULL") == 0) || (strcmp(attr[index + 3], "") == 0))// headfile could not be null
    {
        //error message
        MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index + 3]);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    if ((strcmp(attr[index + 1], "NULL") == 0) || (strcmp(attr[index + 1], "") == 0))// if id = null,return;
    {
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    // only compare header file, if previous node already have that.
    temp = g_mmi_rp_callback_cntx.shead;
    while (temp != NULL && temp->next != NULL)
    {

        if (strcmp(attr[index + 1], temp->next->id) == 0)// same id and header file
        {
            return MMI_RP_PARSE_ERROR_CONTINUE;
        }
        temp = temp->next;    
    }
    
    sendattri = malloc(sizeof(mmi_rp_callback_mgr_sender));
    sendattri->id = malloc(strlen(attr[index + 1]) + 1);
    sendattri->headerfile = malloc(strlen(attr[index + 3]) + 1);
    strcpy(sendattri->id , attr[index+1]);
    strcpy(sendattri->headerfile, attr[index+3]);
    sendattri->next = NULL;
    if ((g_mmi_rp_callback_cntx.shead == NULL) && (g_mmi_rp_callback_cntx.stail == NULL))
    {
        g_mmi_rp_callback_cntx.shead = malloc(sizeof(mmi_rp_callback_mgr_sender));
        g_mmi_rp_callback_cntx.stail = malloc(sizeof(mmi_rp_callback_mgr_sender));
        g_mmi_rp_callback_cntx.shead->next = sendattri;
        g_mmi_rp_callback_cntx.stail = sendattri;
    }
    else
    {
        g_mmi_rp_callback_cntx.stail->next = sendattri;
        g_mmi_rp_callback_cntx.stail = sendattri;
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
int mmi_rp_callback_mgr_sender_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Callback MGR Sender -end: %s\n", el);
    
    return MMI_RP_PARSE_OK;
}

int mmi_rp_callback_mgr_reciever_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    mmi_rp_callback_mgr_reciever *recattri;
    mmi_rp_callback_mgr_reciever *temp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Callback MGR Reciever -start: %s\n", el);
    if ((!attr[index]) || (!attr[index + 1]) || (!attr[index + 2]) || (!attr[index + 3]))
    {
        //error message
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    if (strcmp(attr[index], CALLBACK_MGR_ID_ATTRI)!= 0)
    {
        //error message
        MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    if (strcmp(attr[index + 2], CALLBACK_MGR_ID_RECIEVE_ATTRI) !=0)
    {
        //error message
        MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index + 2]);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    if ((strcmp(attr[index + 1], "NULL") == 0) || (strcmp(attr[index + 1], "") == 0))// if id == Null return
    {
        MMI_RP_PARSE_WARNING_DATA(RP_WARN_USE_ERROR, "id can not be null");
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    if ((strcmp(attr[index + 3], "NULL") == 0) || (strcmp(attr[index + 3], "") == 0)) // proc can not be null
    {
        MMI_RP_PARSE_WARNING_DATA(RP_WARN_USE_ERROR, "proc can not be null");
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    temp = g_mmi_rp_callback_cntx.rhead;
    while (temp != NULL && temp->next != NULL)
    {
        if ((strcmp(attr[index + 1], temp->next->id) == 0) && (strcmp(attr[index + 3], temp->next->proc) == 0)) //id and proc are the same with previous
        {
            MMI_RP_PARSE_WARNING_DATA(RP_WARN_USE_ERROR, "id and proc are the same with previous");
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        temp = temp->next;
    }

    
    recattri = malloc(sizeof(mmi_rp_callback_mgr_reciever));
    recattri ->id = malloc(strlen(attr[index + 1]) + 1);
    recattri ->proc = malloc(strlen(attr[index + 3]) + 1);
    strcpy(recattri ->id , attr[index + 1]);
    strcpy(recattri ->proc, attr[index + 3]);
    recattri ->next = NULL;
    if ((g_mmi_rp_callback_cntx.rhead == NULL) && (g_mmi_rp_callback_cntx.rtail == NULL))
    {
        g_mmi_rp_callback_cntx.rhead = malloc(sizeof(mmi_rp_callback_mgr_reciever));
        g_mmi_rp_callback_cntx.rtail = malloc(sizeof(mmi_rp_callback_mgr_reciever));
        g_mmi_rp_callback_cntx.rhead->next =  recattri;
        g_mmi_rp_callback_cntx.rtail = recattri;
    }
    else
    {
        g_mmi_rp_callback_cntx.rtail->next = recattri;
        g_mmi_rp_callback_cntx.rtail = recattri;
    }

    return MMI_RP_PARSE_OK;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_callback_mgr_reciever_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_callback_mgr_reciever_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Callback MGR Reciever -end: %s\n", el);
    
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
void mmi_rp_callback_mgr_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}

static void mmi_rp_callback_output_proc(FILE *Configfile, U8* sender_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_rp_callback_mgr_reciever *q, *rtemp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    q = g_mmi_rp_callback_cntx.rhead;
    while(q != NULL && q->next != NULL)
    {
        if ((strcmp(sender_id, q->next->id) == 0) && (q->next->proc != NULL))
        {
            fprintf(Configfile, "MMI_FRM_CB_REG(%s)\n", q->next->proc);
            rtemp = q->next;
            q->next = q->next->next;
            free(rtemp->id);
            free(rtemp->proc);
            free(rtemp);
            rtemp = NULL;
        }
        else
        {   
            q = q->next;
        }
   
    }
}

void mmi_rp_callback_mgr_output_phase1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str_headfile[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    U8 str_configfile[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    U8 str_cb_log[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    mmi_rp_callback_mgr_sender *p;
    mmi_rp_callback_mgr_reciever *q, *rtemp;
    FILE    *Headfile;
    FILE    *Configfile;
    FILE    *logfile;
    //mmi_rp_callback_mgr_sender *stemp;
    mmi_rp_event_type_list_node_struct* event_sender = g_mmi_rp_event_type_list_header;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/           
    strcpy(str_headfile, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    strcat(str_headfile, MMI_RP_CALLBACK_MGR_HEADER_FILE);
    strcpy(str_configfile, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    strcat(str_configfile, MMI_RP_CALLBACK_MGR_CONFIG_FILE);
    strcpy(str_cb_log, MMI_RP_MGR_XML_DEBUG_PATH);
    strcat(str_cb_log, MMI_RP_CALLBACK_MGR_LOG_FILE);
    Headfile = fopen(str_headfile, "w");
    Configfile = fopen(str_configfile, "w");
    logfile = fopen(str_cb_log, "w");
    mmi_rp_write_copy_right_header_in_file(Headfile);
    mmi_rp_write_copy_right_header_in_file(Configfile);
    mmi_rp_write_file_header_in_file(
        Headfile, 
        MMI_RP_CALLBACK_MGR_HEADER_FILE, 
        "Callback manager send's id is defined in these header files. And this file is generated by XML resgen", 
        "03 13 2011 yan.liang");

    mmi_rp_write_file_header_in_file(
        Configfile, 
        MMI_RP_CALLBACK_MGR_CONFIG_FILE, 
        "Callback manager config file, it's generated by XML resgen", 
        "03 13 2011 yan.liang");
    fprintf(Headfile, "#ifndef MMI_CALLBACK_APP_HEADER_H\n#define MMI_CALLBACK_APP_HEADER_H\n");
    fprintf(Headfile, "/* !!!Only cb mgr could include this header file!!! */\n");
    fprintf(Headfile, "#ifndef MMI_CB_MGR_C\n#error \"This header file only could be included by cb mananger!\"\n#endif\n");
    fprintf(Headfile, "#ifdef MMI_CB_MGR_UT\n #include \"mmi_cb_test_app_gprot.h\"\n#endif\n");
    fprintf(Configfile, "#ifndef MMI_CB_MGR_C\n#error \"This header file only could be included by cb mananger!\"\n#endif\n");
    //first parser event tag sender type, then parer my sender tag
    fprintf(logfile, "/* Callback Manager Log file */\n");
    fprintf(logfile, "/* The first is the Sender event id */ \n");
    fprintf(logfile, "/* The Next is the Reciever that use the wrong sender's event id or sender has not register the id */ \n");     
    while(event_sender)
    {
        if (event_sender->type == MMI_RP_EVENT_TYPE_SENDER)
        {
             if(!mmi_rp_hash_find(g_mmi_rp_callback_cntx.hash_headerfile, event_sender->filename))//find in headerfile hash
             {
                 //fprintf(Headfile, "/* %s */\n", event_sender->id_str);
                 fprintf(Headfile, "#include \"%s\"\n", event_sender->filename);
                 mmi_rp_hash_add(g_mmi_rp_callback_cntx.hash_headerfile, event_sender->filename);
             }
            fprintf(logfile, "%s\n\n",  event_sender->id_str);
            fprintf(Configfile, "MMI_FRM_CB_REG_BEGIN(%s)\n", event_sender->id_str);
            mmi_rp_callback_output_proc(Configfile, event_sender->id_str);
            fprintf(Configfile, "MMI_FRM_CB_REG_END(%s)\n\n", event_sender->id_str);
        }
        event_sender = event_sender->next;
    }
    
    p = g_mmi_rp_callback_cntx.shead;
    while(p != NULL && p->next != NULL)
    {
        // content can not be null, headfile write many times. we should check the duplicated id and headerfile, same proc.
        if (mmi_rp_hash_find(g_mmi_rp_event_cntx.hash,  p->next->id))
        {
			 p->next = p->next->next;
            continue;
        }
         if(!mmi_rp_hash_find(g_mmi_rp_callback_cntx.hash_headerfile, p->next->headerfile))//find in headerfile hash
         {
             //fprintf(Headfile, "/* %s */\n",  p->next->id);
             fprintf(Headfile, "#include \"%s\"\n", p->next->headerfile);
             mmi_rp_hash_add(g_mmi_rp_callback_cntx.hash_headerfile, p->next->headerfile);
         }
        fprintf(logfile, "%s\n\n",   p->next->id);
        fprintf(Configfile, "MMI_FRM_CB_REG_BEGIN(%s)\n", p->next->id);
        //q = g_mmi_rp_callback_cntx.rhead;
        mmi_rp_callback_output_proc(Configfile,  p->next->id);
        fprintf(Configfile, "MMI_FRM_CB_REG_END(%s)\n\n", p->next->id);
        p->next = p->next->next;
    }
	//free(g_mmi_rp_callback_cntx.shead);

    // free the reciever list, check the memory leak
    fprintf(logfile, "\n\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    fprintf(logfile, " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    fprintf(logfile, "Reciever uses wrong sender's id!!\n");
    while (g_mmi_rp_callback_cntx.rhead)
    {
        rtemp = g_mmi_rp_callback_cntx.rhead;
        if (rtemp->next)
        {
             fprintf(logfile, "%s\n", rtemp->next->proc);
        }
        g_mmi_rp_callback_cntx.rhead = rtemp->next;
        free(rtemp);
        rtemp = NULL;
    }
    //free sender list struct
    fprintf(Headfile, "#endif\n\n");
    fclose(Headfile);
    fclose(Configfile); 
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
void mmi_rp_callback_mgr_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8      str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    FILE    *p_file;
    time_t t = time(0);
    char tmp[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(str_filename, MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES);
    strcat(str_filename, MMI_RP_CALLBACK_MGR_TABLE_FILE);
    p_file = fopen(str_filename, "w");
    mmi_rp_write_copy_right_header_in_file(p_file);
    mmi_rp_write_file_header_in_file(
        p_file, 
        MMI_RP_CALLBACK_MGR_TABLE_FILE, 
        "Callback manager config table, it is generated by XML resgen", 
        "03 13 2011 yan.liang");
    fprintf(p_file, "#define MMI_CB_MGR_C\n\n");
    fprintf(p_file, "#include \"MMIDataType.h\"\n");
    fprintf(p_file, "#include \"mdi_datatype.h\"\n");
    fprintf(p_file, "#include \"mmi_rp_callback_mgr_header_file.h\"\n\n");
    fprintf(p_file, "/*****************************************************************************\n");
    fprintf(p_file, "* Typedef\n");
    fprintf(p_file, " *****************************************************************************/\n");
    fprintf(p_file, "typedef struct _mmi_cb_dynamic_node\n");
    fprintf(p_file, "{ \n");
    fprintf(p_file, "    mmi_proc_func cb;\n");
    fprintf(p_file, "    void *user_data;\n");
    fprintf(p_file, "    struct _mmi_cb_dynamic_node *next;\n");
    fprintf(p_file, "} mmi_cb_dynamic_node;\n\n");
    fprintf(p_file, "typedef struct\n");
    fprintf(p_file, "{\n");
    fprintf(p_file, "    U16 evt_id;\n");
    fprintf(p_file, "    mmi_proc_func *static_table;\n");
    fprintf(p_file, "    mmi_cb_dynamic_node *header;\n");
    fprintf(p_file, "} mmi_cb_map_struct;\n\n");
    fprintf(p_file, "/**************************************************************************************\n");
    fprintf(p_file, " * Parse information from mmi_cb_mgr_cfg.h into three contents for callback manager\n");
    fprintf(p_file, " * 1. extern mmi_ret callback_function(mmi_event_struct *arg);\n");
    fprintf(p_file, " * 2. const mmi_proc_func mmi_cb_table_EVT_APP_XXX[];\n");
    fprintf(p_file, " * 3. static mmi_cb_tbl_struct mmi_cb_table_map[];\n");
    fprintf(p_file, " **************************************************************************************/\n\n");
    fprintf(p_file, "/******************************************************************\n");
    fprintf(p_file, " * extern mmi_ret callback_function(mmi_event_struct *arg); \n");
    fprintf(p_file, " ******************************************************************/\n");
    fprintf(p_file, "#define MMI_FRM_CB_REG_BEGIN(_evt)\n");
    fprintf(p_file, "#define MMI_FRM_CB_REG(_cb) extern mmi_ret _cb(mmi_event_struct *arg);\n");
    fprintf(p_file, "#define MMI_FRM_CB_REG_END(_evt)\n");
    fprintf(p_file, "#include \"mmi_rp_callback_mgr_config.h\"\n\n");
    fprintf(p_file, "/******************************************************************\n");
    fprintf(p_file, " * const mmi_proc_func mmi_cb_table_EVT_APP_XXX[] = \n");
    fprintf(p_file, " * {\n");
    fprintf(p_file, " *     mmi_cb_xxx,\n");
    fprintf(p_file, " *     mmi_cb_yyy,\n");
    fprintf(p_file, " *     NULL\n");
    fprintf(p_file, " * };\n");
    fprintf(p_file, " ******************************************************************/\n");
    fprintf(p_file, "#undef MMI_FRM_CB_REG_BEGIN\n");
    fprintf(p_file, "#undef MMI_FRM_CB_REG\n");
    fprintf(p_file, "#undef MMI_FRM_CB_REG_END\n\n");
    fprintf(p_file, "#define MMI_FRM_CB_REG_BEGIN(_evt) static const mmi_proc_func mmi_cb_table_##_evt[] = {\n");
    fprintf(p_file, "#define MMI_FRM_CB_REG(_cb) _cb,\n");
    fprintf(p_file, "#define MMI_FRM_CB_REG_END(_evt) NULL \\\n");
    fprintf(p_file, "                                     };\n\n");
    fprintf(p_file, "#include \"mmi_rp_callback_mgr_config.h\"\n\n");
    fprintf(p_file, "/******************************************************************\n");
    fprintf(p_file, " * \n");
    fprintf(p_file, " * static mmi_cb_tbl_struct mmi_cb_table_map[] = \n");
    fprintf(p_file, " * {\n");
    fprintf(p_file, " *    {EVT_APP_XXX, mmi_cb_table_EVT_APP_XXX, NULL},\n");
    fprintf(p_file, " *    {EVT_APP_YYY, mmi_cb_table_EVT_APP_YYY, NULL},\n");
    fprintf(p_file, " * };\n");
    fprintf(p_file, " ******************************************************************/\n");
    
    fprintf(p_file, "#undef MMI_FRM_CB_REG_BEGIN\n");
    fprintf(p_file, "#undef MMI_FRM_CB_REG\n");
    fprintf(p_file, "#undef MMI_FRM_CB_REG_END\n\n");
    fprintf(p_file, "#define MMI_FRM_CB_REG_BEGIN(_evt) {(U16)(_evt), (mmi_proc_func *)mmi_cb_table_##_evt, NULL},\n");
    fprintf(p_file, "#define MMI_FRM_CB_REG(_cb)\n");    
    fprintf(p_file, "#define MMI_FRM_CB_REG_END(_evt)\n\n");
    fprintf(p_file, "mmi_cb_map_struct mmi_cb_table_map[] =\n");
    fprintf(p_file, "{\n");
    fprintf(p_file, "    #include \"mmi_rp_callback_mgr_config.h\"\n");
    fprintf(p_file, "    {0, NULL, NULL}\n");
    fprintf(p_file, "};\n\n");
    strftime(tmp, sizeof(tmp), "%Y/%m/%d %X",localtime(&t));
    fprintf(p_file, "/* %s */", tmp);
    fprintf(p_file, "\n\n");

    fclose(p_file);
}




