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
 *  mmi_rp_file_type.c
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
 *============================================================================== *******************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "MMIDataType.h"
#include "mmi_rp_xml.h"
#include "mmi_rp_xml_def.h"
#include "mmi_rp_hash.h"
#include "mmi_rp_file_type.h"

/****************************************************************************
* Setting
*****************************************************************************/

#define FT_OUTPUT_NAME_H    "mmi_rp_file_type_def.h"
#define FT_OUTPUT_NAME_C    "mmi_rp_file_type_table.c"

#define FT_ATTR_FILE        "file"
#define FT_ATTR_ID          "type_id"
#define FT_ATTR_EXT         "extension"
#define FT_ATTR_ICON_SMALL  "small_icon"
#define FT_ATTR_ICON_LARGE  "large_icon"
#define FT_ATTR_MENU_OPT    "option"
#define FT_ATTR_MENU_USE    "use_option"
#define FT_ATTR_MENU_SEND   "send_option"
#define FT_ATTR_ICON_HDLR   "icon_handler"
#define FT_ATTR_ICON_DECODE "icon_decorder"
#define FT_ATTR_GROUP       "group"
#define FT_ATTR_IDS         "type_ids"
#define FT_ATTR_OPT_HANDLER "handler"
#define FT_ATTR_OPT_ENABLER "enabler"
#define FT_ATTR_OPT_HINT    "hint"

#define FT_MAX_NAME 127

/****************************************************************************
* MACRO
*****************************************************************************/

#define FT_INSERT_TYPE(ft)      mmi_rp_file_type_insert_obj((mmi_rp_ft_base_struct*)(ft), FT_ENUM_TYPE, (mmi_rp_ft_base_struct**)(&(g_ft_ctxt->type_head)), (mmi_rp_ft_base_struct**)(&(g_ft_ctxt->type_tail)))
#define FT_INSERT_GROUP(fg)     mmi_rp_file_type_insert_obj((mmi_rp_ft_base_struct*)(fg), FT_ENUM_GROUP, (mmi_rp_ft_base_struct**)(&(g_ft_ctxt->group_head)), (mmi_rp_ft_base_struct**)(&(g_ft_ctxt->group_tail)))
#define FT_INSERT_INC(fi)       mmi_rp_file_type_insert_obj((mmi_rp_ft_base_struct*)(fi), FT_ENUM_INC, (mmi_rp_ft_base_struct**)(&(g_ft_ctxt->inc_head)), (mmi_rp_ft_base_struct**)(&(g_ft_ctxt->inc_tail)))
#define FT_INSERT_DEC(fi)       mmi_rp_file_type_insert_obj((mmi_rp_ft_base_struct*)(fi), FT_ENUM_DEC, (mmi_rp_ft_base_struct**)(&(g_ft_ctxt->dec_head)), (mmi_rp_ft_base_struct**)(&(g_ft_ctxt->dec_tail)))
#define FT_INSERT_OPT(fi)       mmi_rp_file_type_insert_obj((mmi_rp_ft_base_struct*)(fi), FT_ENUM_OPT, (mmi_rp_ft_base_struct**)(&(g_ft_ctxt->opt_head)), (mmi_rp_ft_base_struct**)(&(g_ft_ctxt->opt_tail)))

#define FT_FIND_TYPE(name)      (mmi_rp_ft_type_struct*)mmi_rp_file_type_find_obj_by_name(name, (mmi_rp_ft_base_struct*)g_ft_ctxt->type_head)
#define FT_FIND_GROUP(name)     (mmi_rp_ft_group_struct*)mmi_rp_file_type_find_obj_by_name(name, (mmi_rp_ft_base_struct*)g_ft_ctxt->group_head)

/****************************************************************************
* Define
*****************************************************************************/

enum {
    FT_ENUM_TYPE,
    FT_ENUM_GROUP,
    FT_ENUM_INC,
    FT_ENUM_DEC,
    FT_ENUM_OPT,

    FT_ENUM_END
};

#define FT_BASE \
    struct _ft_base         *next, *prev; \
    S32                     base_type; \
    U32                     app_index; \
    char                    res_name[FT_MAX_NAME+1]; \
    char                    name[FT_MAX_NAME+1]; \

typedef struct 
{
    char                    icon_small[FT_MAX_NAME+1];
    char                    icon_large[FT_MAX_NAME+1];
    char                    menu_option[FT_MAX_NAME+1];
    char                    menu_use[FT_MAX_NAME+1];
    char                    menu_send[FT_MAX_NAME+1];

} mmi_rp_ft_attrs_struct;

typedef struct _ft_base
{
    FT_BASE

} mmi_rp_ft_base_struct;

typedef struct _ft_group
{
    FT_BASE

    mmi_rp_ft_attrs_struct  attrs;

    struct _ft_type         *child_head, *child_tail;

} mmi_rp_ft_group_struct;

typedef struct _ft_type
{
    FT_BASE

    char                    extension[FT_MAX_NAME+1];
    char                    group_name[FT_MAX_NAME+1];
    mmi_rp_ft_attrs_struct  attrs;

    mmi_rp_ft_group_struct  *group;

} mmi_rp_ft_type_struct;

typedef struct _ft_inc
{
    FT_BASE

} mmi_rp_ft_inc_struct;

typedef struct _ft_dec
{
    FT_BASE

} mmi_rp_ft_dec_struct;

typedef struct _ft_opt
{
    FT_BASE
    char                    handler[FT_MAX_NAME+1];
    char                    enabler[FT_MAX_NAME+1];
    char                    hint_hdlr[FT_MAX_NAME+1];

} mmi_rp_ft_opt_struct;

typedef struct 
{
    mmi_rp_ft_group_struct  *group_head, *group_tail;
    mmi_rp_ft_type_struct   *type_head, *type_tail;
    mmi_rp_ft_inc_struct    *inc_head, *inc_tail;
    mmi_rp_ft_dec_struct    *dec_head, *dec_tail;
    mmi_rp_ft_opt_struct    *opt_head, *opt_tail;

    mmi_rp_ft_group_struct  *curr_group;

} mmi_rp_ft_context_struct;

typedef MMI_BOOL (*ft_output_funcptr)(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first);

/****************************************************************************
* Global Variable
*****************************************************************************/

extern const mmi_resource_base_struct g_mmi_resource_base_table[];

/****************************************************************************
* Static Variable
*****************************************************************************/

static mmi_rp_ft_context_struct* g_ft_ctxt = NULL;

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

static S32  mmi_rp_file_type_insert_obj(mmi_rp_ft_base_struct* obj, S32 obj_type, mmi_rp_ft_base_struct** head, mmi_rp_ft_base_struct** tail);
static mmi_rp_ft_base_struct*   mmi_rp_file_type_find_obj_by_name(const char* name, mmi_rp_ft_base_struct* head);


static MMI_BOOL mmi_rp_file_type_attrs_handler(const char* attr, const char* value, mmi_rp_ft_attrs_struct* out);

static void mmi_rp_output_helper(FILE* p_file, const char* tbl_name, const char* dummy, ft_output_funcptr output_hdlr);

static MMI_BOOL mmi_rp_output_extension(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first);
static MMI_BOOL mmi_rp_output_icon(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first);
static MMI_BOOL mmi_rp_output_option(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first);
static MMI_BOOL mmi_rp_output_range(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first);
static MMI_BOOL mmi_rp_output_include(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first);

static MMI_BOOL mmi_rp_output_option_extern1(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first);
static MMI_BOOL mmi_rp_output_option_extern2(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first);
static MMI_BOOL mmi_rp_output_option_extern3(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first);
static MMI_BOOL mmi_rp_output_option_handler(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first);
static MMI_BOOL mmi_rp_output_option_hint(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first);

static void mmi_rp_output_resinfo(char* buffer, mmi_rp_ft_base_struct *obj);
static void mmi_rp_store_resinfo(mmi_rp_ft_base_struct *obj);

#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function Body
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_file_type_init
 * DESCRIPTION
 *  Initializes the file_type context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_file_type_init(void)
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

    if(!g_ft_ctxt)
    {
        g_ft_ctxt = malloc(sizeof(mmi_rp_ft_context_struct));
        memset(g_ft_ctxt, 0, sizeof(mmi_rp_ft_context_struct));
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_file_type_set_app_range
 * DESCRIPTION
 *  Initializes the file_type context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_file_type_set_app_range(void)
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
 *  mmi_rp_file_type_filter
 * DESCRIPTION
 *  This function is for resgen to filter your resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_file_type_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_ft_type_struct   *ft, *ft_next;
    mmi_rp_ft_group_struct  *fg, *fg_prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* find group */
    ft = g_ft_ctxt->type_head;
    while(ft)
    {
        if(!ft->group && ft->group_name[0])
        {
            fg = FT_FIND_GROUP(ft->group_name);
            if(!fg)
            {
                MMI_RP_ERROR_DATA(RP_ERR_ID_NOT_FOUND, ft->group_name);
            }
            ft->group = fg;
            ft->group_name[0] = 0;
        }
        ft = (mmi_rp_ft_type_struct*)ft->next;
    }

    /* group by group */
    fg = g_ft_ctxt->group_head;
    while(fg)
    {
        fg->child_head = fg->child_tail = NULL;
        fg = (mmi_rp_ft_group_struct*)fg->next;
    }

    ft = g_ft_ctxt->type_head;
    while(ft)
    {
        ft_next = (mmi_rp_ft_type_struct*)ft->next;
        
        do {
            if(!ft->group)
                break;

            /* remove */
            if(ft == g_ft_ctxt->type_head)
                g_ft_ctxt->type_head = (mmi_rp_ft_type_struct*)ft->next;
            if(ft == g_ft_ctxt->type_tail)
                g_ft_ctxt->type_tail = (mmi_rp_ft_type_struct*)ft->prev;
            if(ft->prev)
                ft->prev->next = ft->next;
            if(ft->next)
                ft->next->prev = ft->prev;

            if(!ft->group->child_tail)
            {
                ft->group->child_head = ft->group->child_tail = ft;
                ft->next = ft->prev = NULL;
            }
            else
            {
                ft->prev = (mmi_rp_ft_base_struct*)ft->group->child_tail;
                ft->next = NULL;
                ft->group->child_tail->next = (mmi_rp_ft_base_struct*)ft;
                ft->group->child_tail = ft;
            }
        } while(0);
        
        ft = ft_next;
    }

    /* add them back */
    fg = g_ft_ctxt->group_tail;
    while(fg)
    {
        fg_prev = (mmi_rp_ft_group_struct*)fg->prev;

        do {
            if(!fg->child_head)
            {
                // TODO:
                /* no child??, remove ?? */
                break;
            }

            fg->child_tail->next = (mmi_rp_ft_base_struct*)g_ft_ctxt->type_head;
            g_ft_ctxt->type_head->prev = (mmi_rp_ft_base_struct*)fg->child_tail;
            g_ft_ctxt->type_head = fg->child_head;

        }while(0);

        fg = fg_prev;
    }

    /* update all items */
    ft = g_ft_ctxt->type_head;
    while(ft)
    {
        if(!ft->attrs.icon_small[0])
            strcpy(ft->attrs.icon_small, "0");
        if(!ft->attrs.icon_large[0])
            strcpy(ft->attrs.icon_large, "0");
        if(!ft->attrs.menu_option[0])
            strcpy(ft->attrs.menu_option, "0");
        if(!ft->attrs.menu_use[0])
            strcpy(ft->attrs.menu_use, "0");
        if(!ft->attrs.menu_send[0])
            strcpy(ft->attrs.menu_send, "0");
        ft = (mmi_rp_ft_type_struct*)ft->next;
    }

    fg = g_ft_ctxt->group_head;
    while(fg)
    {
        if(!fg->attrs.icon_small[0])
            strcpy(fg->attrs.icon_small, "0");
        if(!fg->attrs.icon_large[0])
            strcpy(fg->attrs.icon_large, "0");
        if(!fg->attrs.menu_option[0])
            strcpy(fg->attrs.menu_option, "0");
        if(!fg->attrs.menu_use[0])
            strcpy(fg->attrs.menu_use, "0");
        if(!fg->attrs.menu_send[0])
            strcpy(fg->attrs.menu_send, "0");
        fg = (mmi_rp_ft_group_struct*)fg->next;
    }
    
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_file_type_output_phase1
 * DESCRIPTION
 *  Output IDs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_file_type_output_phase1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8      str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    FILE    *p_file;
    S32     i;

    mmi_rp_ft_type_struct   *ft;
    mmi_rp_ft_group_struct  *fg;
    mmi_rp_ft_dec_struct    *fd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    strcpy(str_filename, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    strcat(str_filename, FT_OUTPUT_NAME_H);

    p_file = fopen(str_filename, "w");
    if(!p_file)
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
        return;
    }

    mmi_rp_write_copy_right_header_in_file(p_file);
    mmi_rp_write_file_header_in_file(
        p_file, 
        FT_OUTPUT_NAME_H, 
        "Resource populate function generated by XML resgen", 
        "MTK resgenerator XML parser");

    fprintf(p_file, "#ifndef _MMI_RP_FILE_TYPE_DEF_H\n#define _MMI_RP_FILE_TYPE_DEF_H\n");

    fprintf(p_file, "typedef enum \n{\n");
    fprintf(p_file, "    FMGR_TYPE_ALL,      /* this type represent all files (included not supported types, like *.doc */\n");
    fprintf(p_file, "    FMGR_TYPE_UNKNOWN,\n");
    fprintf(p_file, "    /* ================== App type begin ================== */\n");

    ft = g_ft_ctxt->type_head;
    while(ft)
    {
        if(strcmp(ft->name, "FMGR_TYPE_UNKNOWN"))
            fprintf(p_file, "    %s,\n", ft->name);
        ft = (mmi_rp_ft_type_struct*)ft->next;
    }
    
    fprintf(p_file, "    /* ================== App type end ================== */\n");

    fprintf(p_file, "    FMGR_TYPE_COUNT\n");
    fprintf(p_file, "} filetypes_file_type_enum;\n\n");

    fprintf(p_file, "typedef enum \n{\n");
    fprintf(p_file, "    FMGR_GROUP_TYPE_BEGIN = FMGR_TYPE_COUNT,\n");
    fprintf(p_file, "    FMGR_GROUP_UNKNOWN,\n");
    fprintf(p_file, "    /* ================== App group type begin ================== */\n");

    fg = g_ft_ctxt->group_head;
    while(fg)
    {
        fprintf(p_file, "    %s,\n", fg->name);
        fg = (mmi_rp_ft_group_struct*)fg->next;
    }
    
    fprintf(p_file, "    /* ================== App group type end ================== */\n");
    fprintf(p_file, "    FMGR_GROUP_TYPE_END\n");
    fprintf(p_file, "} filetypes_group_type_enum;\n\n");

    fprintf(p_file, "#define FMGR_MAX_FILTER_COUNT           (FMGR_TYPE_COUNT-5)\n");
    fprintf(p_file, "\n");
    fprintf(p_file, "typedef struct { \n");
    fprintf(p_file, "    unsigned int mask[(FMGR_TYPE_COUNT+32)/32];\n");
    fprintf(p_file, "} FMGR_FILTER;\n");
    fprintf(p_file, "\n");
    fprintf(p_file, "#define FMGR_FILTER_INIT(f)             do { memset((f)->mask, 0,    sizeof((f)->mask)); } while(0)\n");
    fprintf(p_file, "#define FMGR_FILTER_SET_ALL(a)          do { memset((a)->mask, 0xff, sizeof((a)->mask)); } while(0)\n");
    fprintf(p_file, "\n");
    fprintf(p_file, "#define FMGR_FILTER_SET(f,b)            do { if((b)<FMGR_TYPE_COUNT) ((f)->mask[b/32]) |= ( (((unsigned int)1)<<(b%%32))); } while(0)\n");
    fprintf(p_file, "#define FMGR_FILTER_CLEAR(f,b)          do { if((b)<FMGR_TYPE_COUNT) ((f)->mask[b/32]) &= (~(((unsigned int)1)<<(b%%32))); } while(0)\n");
    fprintf(p_file, "\n");
    fprintf(p_file, "#define FMGR_FILTER_IS_SET(f,b)         ( ((b)<FMGR_TYPE_COUNT) ? (((f)->mask[b/32]) &  (((unsigned int)1)<<(b%%32))) : 0)\n");
    fprintf(p_file, "\n");

    fprintf(p_file, "\n");
    fd = g_ft_ctxt->dec_head;
    i = 1;
    while(fd)
    {
        if(!FT_FIND_TYPE(fd->name))
            fprintf(p_file, "#define %s (FMGR_TYPE_COUNT + %d)\n", fd->name, i++);
        fd = (mmi_rp_ft_dec_struct*)fd->next;
    }
    fprintf(p_file, "\n");

    fprintf(p_file, "#endif /* _MMI_RP_FILE_TYPE_DEF_H */\n");
    fclose(p_file);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_rp_file_type_output_phase2
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_file_type_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8      str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    FILE    *p_file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    strcpy(str_filename, MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES);
    strcat(str_filename, FT_OUTPUT_NAME_C);

    p_file = fopen(str_filename, "w");
    if(!p_file)
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE1);
        return;
    }

    mmi_rp_write_copy_right_header_in_file(p_file);
    mmi_rp_write_file_header_in_file(
        p_file, 
        FT_OUTPUT_NAME_C, 
        "Resource populate function generated by XML resgen", 
        "MTK resgenerator XML parser");

    fprintf(p_file, "#define _MMI_RP_FILE_TYPE_DEF_C\n\n");

    fprintf(p_file, "#include \"MMIDataType.h\"\n");
    fprintf(p_file, "#include \"CustMenuRes.h\"\n");
    fprintf(p_file, "#include \"%s\"\n", FT_OUTPUT_NAME_H);
    fprintf(p_file, "#include \"filemgrsrvgprot.h\"\n");
    fprintf(p_file, "#include \"mmi_rp_all_defs.h\"\n");

    mmi_rp_output_helper(p_file, NULL, NULL, mmi_rp_output_include);

    fprintf(p_file, "\n");
    fprintf(p_file, "typedef struct {\n");
    fprintf(p_file, "    U16            file_type;\n");
    fprintf(p_file, "    const char     *extension;\n");
    fprintf(p_file, "    const WCHAR    *extension_ucs2;\n");
    fprintf(p_file, "} filetypes_extension_struct;\n\n");

    fprintf(p_file, "typedef struct {\n");
    fprintf(p_file, "    U16            file_type;\n");
    fprintf(p_file, "    mmi_img_id     small_icon;\n");
    fprintf(p_file, "    mmi_img_id     large_icon;\n");
    fprintf(p_file, "} filetypes_icons_struct;\n\n");

    fprintf(p_file, "typedef struct {\n");
    fprintf(p_file, "    U16            file_type;\n");
    fprintf(p_file, "    mmi_menu_id    option;\n");
    fprintf(p_file, "    mmi_menu_id    send_option;\n");
    fprintf(p_file, "    mmi_menu_id    use_option;\n");
    fprintf(p_file, "} filetypes_option_struct;\n\n");

    fprintf(p_file, "typedef struct {\n");
    fprintf(p_file, "    U16            group_type;\n");
    fprintf(p_file, "    U16            begin_id;\n");
    fprintf(p_file, "    U16            end_id;\n");
    fprintf(p_file, "} filetypes_group_range_struct;\n\n");

    fprintf(p_file, "typedef void (*filetypes_option_enabler_func_ptr)(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);\n");
    fprintf(p_file, "typedef void (*filetypes_option_handler_func_ptr)(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);\n");
    fprintf(p_file, "typedef void (*filetypes_option_hint_func_ptr)(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo, WCHAR* hint_buffer, S32 hint_buffer_size);\n");
    fprintf(p_file, "\n");

    fprintf(p_file, "typedef struct {\n");
    fprintf(p_file, "    mmi_menu_id    option;\n");
    fprintf(p_file, "    filetypes_option_handler_func_ptr handler;\n");
    fprintf(p_file, "    filetypes_option_enabler_func_ptr enabler;\n");
    fprintf(p_file, "} filetypes_opt_hdlr_struct;\n\n");

    fprintf(p_file, "typedef struct {\n");
    fprintf(p_file, "    mmi_menu_id    option;\n");
    fprintf(p_file, "    filetypes_option_hint_func_ptr hint_hdlr;\n");
    fprintf(p_file, "} filetypes_opt_hint_struct;\n\n");

    mmi_rp_output_helper(p_file, "extension",   "    {0, NULL, NULL}",  mmi_rp_output_extension);
    mmi_rp_output_helper(p_file, "icons",       "    {0, 0, 0}",        mmi_rp_output_icon);
    mmi_rp_output_helper(p_file, "option",      "    {0, 0, 0, 0}",     mmi_rp_output_option);
    mmi_rp_output_helper(p_file, "group_range", "    {0, 0, 0}",        mmi_rp_output_range);

    mmi_rp_output_helper(p_file, NULL,          NULL,                   mmi_rp_output_option_extern2);
    mmi_rp_output_helper(p_file, NULL,          NULL,                   mmi_rp_output_option_extern1);
    fprintf(p_file, "\n");
    mmi_rp_output_helper(p_file, "opt_hdlr",    "    {0, NULL, NULL}",  mmi_rp_output_option_handler);

    mmi_rp_output_helper(p_file, NULL,          NULL,                   mmi_rp_output_option_extern3);
    fprintf(p_file, "\n");
    mmi_rp_output_helper(p_file, "opt_hint",    "    {0, NULL}",        mmi_rp_output_option_hint);

    fclose(p_file);
}

#define TAG_FILE_TYPE
   
int mmi_rp_file_type_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32   index = 0;
    S32 parent_tag_id = -1;
    
    mmi_rp_ft_type_struct   *item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("File Type -start: %s\n", el);

    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_FILE_TYPE_BASE) &&
        strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_FILE_GROUP_TYPE))
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    item = malloc(sizeof(mmi_rp_ft_type_struct));
    memset(item, 0, sizeof(mmi_rp_ft_type_struct));
    mmi_rp_store_resinfo((mmi_rp_ft_base_struct*)item);

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        printf("%s = %s\n", attr[index], attr[index + 1]);

        do {
            if(strlen(attr[index+1]) > FT_MAX_NAME)
            {
                MMI_RP_ERROR_DATA(RP_ERR_MEMORY_NOT_AVAILABLE, attr[index]);
                return MMI_RP_PARSE_ERROR_SKIP_TAG;
            }
            if(g_ft_ctxt->curr_group)
                item->group = g_ft_ctxt->curr_group;
            
            if(mmi_rp_file_type_attrs_handler(attr[index], attr[index+1], &(item->attrs)))
                break;

            if(!strcmp(attr[index], FT_ATTR_ID))
            {
                strcpy(item->name, attr[index+1]);
                break;
            }
            if(!strcmp(attr[index], FT_ATTR_EXT))
            {
                strcpy(item->extension, attr[index+1]);
                break;
            }
            if(!strcmp(attr[index], FT_ATTR_GROUP))
            {
                strcpy(item->group_name, attr[index+1]);
                break;
            }
            
            MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        } while(0);    
        
        index += 2;
    }

    index = FT_INSERT_TYPE(item);
    if(index)
    {
        MMI_RP_ERROR_DATA(index, item->name);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    return MMI_RP_PARSE_OK;
}


int mmi_rp_file_type_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("File Type -end: %s\n", el);
    
    return MMI_RP_PARSE_OK;
}


#define TAG_FILE_GROUP_TYPE

int mmi_rp_file_group_type_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32   index = 0;
    S32 parent_tag_id = -1;

    mmi_rp_ft_group_struct   *item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("File Group -start: %s\n", el);

    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_FILE_TYPE_BASE) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    item = malloc(sizeof(mmi_rp_ft_group_struct));
    memset(item, 0, sizeof(mmi_rp_ft_group_struct));
    mmi_rp_store_resinfo((mmi_rp_ft_base_struct*)item);
   
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        printf("%s = %s\n", attr[index], attr[index + 1]);
        
        do {
            if(strlen(attr[index+1]) > FT_MAX_NAME)
            {
                MMI_RP_ERROR_DATA(RP_ERR_MEMORY_NOT_AVAILABLE, attr[index]);
                return MMI_RP_PARSE_ERROR_SKIP_TAG;
            }
            
            if(mmi_rp_file_type_attrs_handler(attr[index], attr[index+1], &(item->attrs)))
                break;

            if(!strcmp(attr[index], FT_ATTR_ID))
            {
                strcpy(item->name, attr[index+1]);
                break;
            }

            MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        } while(0);    
        
        index += 2;
    }

    index = FT_INSERT_GROUP(item);
    if(index)
    {
        MMI_RP_ERROR_DATA(index, item->name);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    if(g_ft_ctxt->curr_group)
    {
        MMI_RP_ERROR_DATA(RP_ERR_TAG_USE_ERROR, item->name);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    g_ft_ctxt->curr_group = item;
    return MMI_RP_PARSE_OK;
}


int mmi_rp_file_group_type_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("File Group -end: %s\n", el);

    g_ft_ctxt->curr_group = NULL;
}

#define TAG_FILE_TYPE_INC
   
int mmi_rp_file_type_inc_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    S32 parent_tag_id = -1;
    
    char                    name[FT_MAX_NAME+1];
    char                    *token;
    mmi_rp_ft_inc_struct    *item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("File Type Inc -start: %s\n", el);
    
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_FILE_TYPE_BASE) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        printf("%s = %s\n", attr[index], attr[index + 1]);

        do {
            if(strlen(attr[index+1]) > FT_MAX_NAME)
            {
                MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
            }
            if(!strcmp(attr[index], FT_ATTR_FILE))
            {
                strcpy(name, attr[index+1]);
                break;
            }

            MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        } while(0);    
        
        index += 2;
    }

    item = NULL;
    token = strtok(name, " ,");
    while(token)
    {
        MMI_RP_DEBUG_INFO("Token: %s\n", token);

        item = malloc(sizeof(mmi_rp_ft_inc_struct));
        memset(item, 0, sizeof(mmi_rp_ft_inc_struct));
        mmi_rp_store_resinfo((mmi_rp_ft_base_struct*)item);

        if(strlen(token) > FT_MAX_NAME)
        {
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }
        strcpy(item->name, token);

        FT_INSERT_INC(item);

        token = strtok(NULL, " ,");
    }

    if(!item)
    {
        MMI_RP_ERROR_DATA(RP_ERR_TAG_USE_ERROR, el);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    return MMI_RP_PARSE_OK;
}


int mmi_rp_file_type_inc_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("File Type Inc -end: %s\n", el);
    
    return MMI_RP_PARSE_OK;
}

#define TAG_FILE_TYPE_DEC
   
int mmi_rp_file_type_dec_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    S32 parent_tag_id = -1;
    
    char                    *name;
    char                    *token;
    mmi_rp_ft_dec_struct    *item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("File Type Dec -start: %s\n", el);
    
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_FILE_TYPE_BASE) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        printf("%s = %s\n", attr[index], attr[index + 1]);

        do {
            if(!strcmp(attr[index], FT_ATTR_IDS))
            {
                name = malloc(strlen(attr[index+1])+1);
                strcpy(name, attr[index+1]);
                break;
            }

            MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        } while(0);    
        
        index += 2;
    }

    item = NULL;
    token = strtok(name, " ,");
    while(token)
    {
        MMI_RP_DEBUG_INFO("Token: %s\n", token);

        item = malloc(sizeof(mmi_rp_ft_dec_struct));
        memset(item, 0, sizeof(mmi_rp_ft_dec_struct));
        mmi_rp_store_resinfo((mmi_rp_ft_base_struct*)item);

        if(strlen(token) > FT_MAX_NAME)
        {
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }
        strcpy(item->name, token);

        FT_INSERT_DEC(item);

        token = strtok(NULL, " ,");
    }

    if(!item)
    {
        MMI_RP_ERROR_DATA(RP_ERR_TAG_USE_ERROR, el);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    return MMI_RP_PARSE_OK;
}


int mmi_rp_file_type_dec_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("File Type Dec -end: %s\n", el);
    
}
#define TAG_FILE_TYPES

int mmi_rp_fts_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32   index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("File Types -start: %s\n", el);

    return MMI_RP_PARSE_OK;
}


int mmi_rp_fts_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("File Types -end: %s\n", el);
    
}

#define TAG_FILE_OPT_HDLR

int mmi_rp_file_opt_hdlr_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32   index = 0;
    S32 parent_tag_id = -1;

    mmi_rp_ft_opt_struct    *item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("File option -start: %s\n", el);

    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_FILE_TYPE_BASE) &&
        strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_FILE_GROUP_TYPE))
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    item = malloc(sizeof(mmi_rp_ft_opt_struct));
    memset(item, 0, sizeof(mmi_rp_ft_opt_struct));
    mmi_rp_store_resinfo((mmi_rp_ft_base_struct*)item);

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        printf("%s = %s\n", attr[index], attr[index + 1]);

        do {
            if(strlen(attr[index+1]) > FT_MAX_NAME)
            {
                MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
            }

            if(!strcmp(attr[index], FT_ATTR_MENU_OPT))
            {
                strcpy(item->name, attr[index+1]);
                break;
            }
            if(!strcmp(attr[index], FT_ATTR_OPT_HANDLER))
            {
                strcpy(item->handler, attr[index+1]);
                break;
            }
            if(!strcmp(attr[index], FT_ATTR_OPT_ENABLER))
            {
                strcpy(item->enabler, attr[index+1]);
                break;
            }
            if(!strcmp(attr[index], FT_ATTR_OPT_HINT))
            {
                strcpy(item->hint_hdlr, attr[index+1]);
                break;
            }
            
            MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        } while(0);    
        
        index += 2;
    }

    index = FT_INSERT_OPT(item);
    if(index)
    {
        MMI_RP_ERROR_DATA(index, item->name);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    
    return MMI_RP_PARSE_OK;
}


int mmi_rp_file_opt_hdlr_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("File option -end: %s\n", el);
    
    return MMI_RP_PARSE_OK;
}
#define LOCAL_FUNCTION

static MMI_BOOL mmi_rp_file_type_attrs_handler(const char* attr, const char* value, mmi_rp_ft_attrs_struct* out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const char* ft_attrs_table[] = 
    {
         FT_ATTR_ICON_SMALL
        ,FT_ATTR_ICON_LARGE
        ,FT_ATTR_MENU_OPT
        ,FT_ATTR_MENU_USE
        ,FT_ATTR_MENU_SEND
    };
    
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0;i<sizeof(ft_attrs_table)/sizeof(const char*);i++)
    {
        if(!strcmp(attr, ft_attrs_table[i]))
        {
            strcpy( (char*)out + i*(FT_MAX_NAME+1), value);
            return MMI_TRUE;
        }
    }
    return MMI_FALSE; 
}

static S32 mmi_rp_file_type_insert_obj(mmi_rp_ft_base_struct* obj, S32 obj_type, mmi_rp_ft_base_struct** head, mmi_rp_ft_base_struct** tail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* already exist */
    if(mmi_rp_file_type_find_obj_by_name(obj->name, (*head)))
    {
        return RP_ERR_TAG_OPEN_TWICE;
    }

    /* insert to tail */
    obj->base_type = obj_type;
    if(!(*tail))
    {
        (*head) = obj;
        (*tail) = obj;
        obj->next = obj->prev = NULL;
    }
    else
    {
        obj->prev = (*tail);
        obj->next = NULL;
        (*tail)->next = obj;
        (*tail) = obj;
    }
    return 0;
}

static mmi_rp_ft_base_struct* mmi_rp_file_type_find_obj_by_name(const char* name, mmi_rp_ft_base_struct* head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_ft_base_struct* obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!name || !name[0])
        return NULL;
        
    obj = head;
    while(obj)
    {
        if(!strcmp(obj->name, name))
            return obj;
        obj = obj->next;
    }
    return NULL;
}

#define OUTPUT_HELPER

static void mmi_rp_output_helper(FILE* p_file, const char* tbl_name, const char* dummy, ft_output_funcptr output_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_ft_base_struct   *head_table[] = {
         (mmi_rp_ft_base_struct*)g_ft_ctxt->type_head
         ,(mmi_rp_ft_base_struct*)g_ft_ctxt->group_head
         ,(mmi_rp_ft_base_struct*)g_ft_ctxt->inc_head
         ,(mmi_rp_ft_base_struct*)g_ft_ctxt->opt_head
    };
    S32                     i, head_count = sizeof(head_table)/sizeof(mmi_rp_ft_base_struct*);
    
    mmi_rp_ft_base_struct   *obj;
    
    MMI_BOOL                first_in_table, first_in_group;
    char                    buffer[1024];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    first_in_table = MMI_TRUE;
    if(tbl_name)
        fprintf(p_file, "const filetypes_%s_struct g_filetypes_%s_table[] = \n{", tbl_name, tbl_name);

    for(i=0;i<head_count;i++)
    {
        obj = head_table[i];
        first_in_group = MMI_TRUE;
        while(obj)
        {
            if(output_hdlr(buffer, obj, first_in_table))
            {
                if(first_in_table)
                    first_in_table = MMI_FALSE;
                
                if(first_in_group)
                {
                    fprintf(p_file, "\n");
                    first_in_group = MMI_FALSE;
                }
                
                fprintf(p_file, "%s\n", buffer);
            }
            obj = obj->next;
        }
    }

    if(tbl_name && first_in_table && dummy)
        fprintf(p_file, "\n%s\n", dummy);

    if(tbl_name)
    {
        fprintf(p_file, "};\n");
        fprintf(p_file, "const S32 g_filetypes_%s_table_size = sizeof(g_filetypes_%s_table) / sizeof(filetypes_%s_struct);\n\n", tbl_name, tbl_name, tbl_name);
    }
}

static void mmi_rp_store_resinfo(mmi_rp_ft_base_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern U8 g_cur_filename[512];
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj->app_index = g_mmi_rp_mgr_cntx.cur_app_index;
    strncpy(obj->res_name, g_cur_filename, FT_MAX_NAME);

    // replace .i to .res
    i = strlen(obj->res_name)-1;
    while(i >= 0 && obj->res_name[i] != '.') i--;
    if(i >= 0)
    {
        if(obj->res_name[i+1] == 'i')
            strcpy(obj->res_name +i+1, "res");
    }
}

static void mmi_rp_output_resinfo(char* buffer, mmi_rp_ft_base_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(obj->app_index > 0 && obj->app_index < g_mmi_rp_mgr_cntx.total_apps)
        sprintf(buffer, "\t/* %s%s */",  g_mmi_resource_base_table[obj->app_index].res_path, obj->res_name);
    else
        sprintf(buffer, "\t/* %s */",  obj->res_name);
}

static MMI_BOOL mmi_rp_output_extension(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_ft_type_struct   *ft;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(obj->base_type)
    {
    case FT_ENUM_TYPE:
        ft = (mmi_rp_ft_type_struct*)obj;
        if(!ft->extension[0])
            return MMI_FALSE;

        if(first)
            sprintf(buffer, "    ");
        else
            sprintf(buffer, "    ,");

        if(strlen(ft->extension) % 2)
            sprintf(buffer + strlen(buffer), "{%s, \"%s\", L\"%s\"}", ft->name, ft->extension, ft->extension);
        else
            sprintf(buffer + strlen(buffer), "{%s, \"%s\\0\", L\"%s\"}", ft->name, ft->extension, ft->extension);
        return MMI_TRUE;

    default:
        return MMI_FALSE;
    }

}

static MMI_BOOL mmi_rp_output_icon(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_ft_type_struct   *ft;
    mmi_rp_ft_group_struct  *fg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(obj->base_type)
    {
    case FT_ENUM_TYPE:
        ft = (mmi_rp_ft_type_struct*)obj;
        if(!strcmp("0", ft->attrs.icon_small) && !strcmp("0", ft->attrs.icon_large))
            return MMI_FALSE;
        
        if(first)
            sprintf(buffer, "    {%s, %s, %s}", ft->name, ft->attrs.icon_small, ft->attrs.icon_large);
        else
            sprintf(buffer, "    ,{%s, %s, %s}", ft->name, ft->attrs.icon_small, ft->attrs.icon_large);
        mmi_rp_output_resinfo(buffer+strlen(buffer), obj);
        return MMI_TRUE;

    case FT_ENUM_GROUP:
        fg = (mmi_rp_ft_group_struct*)obj;
        if(!strcmp("0", fg->attrs.icon_small) && !strcmp("0", fg->attrs.icon_large))
            return MMI_FALSE;
        
        if(first)
            sprintf(buffer, "    {%s, %s, %s}", fg->name, fg->attrs.icon_small, fg->attrs.icon_large);
        else
            sprintf(buffer, "    ,{%s, %s, %s}", fg->name, fg->attrs.icon_small, fg->attrs.icon_large);
        mmi_rp_output_resinfo(buffer+strlen(buffer), obj);
        return MMI_TRUE;

    default:
        return MMI_FALSE;
    }
    
}

static MMI_BOOL mmi_rp_output_option(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_ft_type_struct   *ft;
    mmi_rp_ft_group_struct  *fg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(obj->base_type)
    {
    case FT_ENUM_TYPE:
        ft = (mmi_rp_ft_type_struct*)obj;
        if(!strcmp("0", ft->attrs.menu_option) &&
            !strcmp("0", ft->attrs.menu_send) && 
            !strcmp("0", ft->attrs.menu_use))
            return MMI_FALSE;
        if(first)
            sprintf(buffer, "    {%s, %s, %s, %s}", ft->name, ft->attrs.menu_option, ft->attrs.menu_send, ft->attrs.menu_use);
        else
            sprintf(buffer, "    ,{%s, %s, %s, %s}", ft->name, ft->attrs.menu_option, ft->attrs.menu_send, ft->attrs.menu_use);
        mmi_rp_output_resinfo(buffer+strlen(buffer), obj);
        return MMI_TRUE;

    case FT_ENUM_GROUP:
        fg = (mmi_rp_ft_group_struct*)obj;
        if(!strcmp("0", fg->attrs.menu_option) &&
            !strcmp("0", fg->attrs.menu_send) && 
            !strcmp("0", fg->attrs.menu_use))
            return MMI_FALSE;
        if(first)
            sprintf(buffer, "    {%s, %s, %s, %s}", fg->name, fg->attrs.menu_option, fg->attrs.menu_send, fg->attrs.menu_use);
        else
            sprintf(buffer, "    ,{%s, %s, %s, %s}", fg->name, fg->attrs.menu_option, fg->attrs.menu_send, fg->attrs.menu_use);
        mmi_rp_output_resinfo(buffer+strlen(buffer), obj);
        return MMI_TRUE;

    default:
        return MMI_FALSE;
    }

}


static MMI_BOOL mmi_rp_output_range(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_ft_group_struct  *fg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(obj->base_type)
    {
    case FT_ENUM_GROUP:
        fg = (mmi_rp_ft_group_struct*)obj;
        if(!fg->child_head)
            return MMI_FALSE;
        if(first)
            sprintf(buffer, "    {%s, %s, %s}", fg->name, fg->child_head->name, fg->child_tail->name);
        else
            sprintf(buffer, "    ,{%s, %s, %s}", fg->name, fg->child_head->name, fg->child_tail->name);
        mmi_rp_output_resinfo(buffer+strlen(buffer), obj);
        return MMI_TRUE;

    default:
        return MMI_FALSE;
    }

}

static MMI_BOOL mmi_rp_output_include(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(obj->base_type)
    {
    case FT_ENUM_INC:
        sprintf(buffer, "#include \"%s\"", obj->name);
        mmi_rp_output_resinfo(buffer+strlen(buffer), obj);
        return MMI_TRUE;

    default:
        return MMI_FALSE;
    }

}

static MMI_BOOL mmi_rp_output_option_extern1(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_ft_opt_struct *opt = (mmi_rp_ft_opt_struct*)obj;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(obj->base_type)
    {
    case FT_ENUM_OPT:
        if(!opt->enabler[0])
            return MMI_FALSE;
        sprintf(buffer, "extern void %s(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);", opt->enabler);
        return MMI_TRUE;

    default:
        return MMI_FALSE;
    }
}

static MMI_BOOL mmi_rp_output_option_extern2(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_ft_opt_struct *opt = (mmi_rp_ft_opt_struct*)obj;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(obj->base_type)
    {
    case FT_ENUM_OPT:
        if(!opt->handler[0])
            return MMI_FALSE;
        sprintf(buffer, "extern void %s(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);", opt->handler);
        return MMI_TRUE;

    default:
        return MMI_FALSE;
    }
}

static MMI_BOOL mmi_rp_output_option_extern3(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_ft_opt_struct *opt = (mmi_rp_ft_opt_struct*)obj;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(obj->base_type)
    {
    case FT_ENUM_OPT:
        if(!opt->hint_hdlr[0])
            return MMI_FALSE;
        sprintf(buffer, "extern void %s(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo, WCHAR* hint_buffer, S32 hint_buffer_size);", opt->hint_hdlr);
        return MMI_TRUE;

    default:
        return MMI_FALSE;
    }
}

static MMI_BOOL mmi_rp_output_option_handler(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_ft_opt_struct *opt = (mmi_rp_ft_opt_struct*)obj;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(obj->base_type)
    {
    case FT_ENUM_OPT:
        if(!opt->enabler[0] && !opt->handler[0])
            return MMI_FALSE;

        if(first)
            sprintf(buffer, "    {%s, ", opt->name);
        else
            sprintf(buffer, "    ,{%s, ", opt->name);

        if(opt->handler[0])
            sprintf(buffer+strlen(buffer), "%s, ", opt->handler);
        else
            sprintf(buffer+strlen(buffer), "NULL, ");

        if(opt->enabler[0])
            sprintf(buffer+strlen(buffer), "%s}", opt->enabler);
        else
            sprintf(buffer+strlen(buffer), "NULL}");

        mmi_rp_output_resinfo(buffer+strlen(buffer), obj);
        return MMI_TRUE;

    default:
        return MMI_FALSE;
    }
}

static MMI_BOOL mmi_rp_output_option_hint(char* buffer, mmi_rp_ft_base_struct *obj, MMI_BOOL first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_ft_opt_struct *opt = (mmi_rp_ft_opt_struct*)obj;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(obj->base_type)
    {
    case FT_ENUM_OPT:
        if(!opt->hint_hdlr[0])
            return MMI_FALSE;
        
        if(first)
            sprintf(buffer, "    {%s, %s}", opt->name, opt->hint_hdlr);
        else
            sprintf(buffer, "    ,{%s, %s}", opt->name, opt->hint_hdlr);

        mmi_rp_output_resinfo(buffer+strlen(buffer), obj);
        return MMI_TRUE;

    default:
        return MMI_FALSE;
    }
}

