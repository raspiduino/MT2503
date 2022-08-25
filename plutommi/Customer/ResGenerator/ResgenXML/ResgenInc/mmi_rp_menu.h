/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
*
*****************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  mmi_rp_menu.h
*
* Project:
* --------
*   Resgen XML header file of menu resource
*
* Description:
* ------------
*
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef RESXML_MENU_H
#define RESXML_MENU_H

#include "GlobalConstants.h"
#include "MMIDataType.h"

#define MMI_RP_MENU_CHILDREN_MENU_SIZE MAX_SUB_MENUS        /* (60) From GlobalConstants.h */
#define MMI_RP_MENU_GROUP_ID_MAX 100
#define MMI_RP_MENU_MAINMENUITEM_ID_MAX 100
#define MMI_RP_MENU_GROUP_MENU_MAX 512
#define MMI_RP_MENU_PARENT_STACK_MAX 5
#define MMI_RP_MENU_SET_ID_MAX 100
#define MMI_RP_MENU_SET_MENU_MAX 512
#define MMI_RP_MENU_SHORTCUT_MAX 100

#define MMI_RP_MENU_OLD_ID_FLAG_ID              0x00000001
#define MMI_RP_MENU_OLD_ID_FLAG_STR             0x00000002
#define MMI_RP_MENU_OLD_ID_FLAG_IMG             0x00000004
#define MMI_RP_MENU_OLD_ID_FLAG_MM_LIST_IMG     0x00000008
#define MMI_RP_MENU_OLD_ID_FLAG_MM_MATRIX_IMG   0x00000010
#define MMI_RP_MENU_OLD_ID_FLAG_MM_PAGE_IMG     0x00000020
#define MMI_RP_MENU_OLD_ID_FLAG_MM_VENUS1_IMG   0x00000040
#define MMI_RP_MENU_OLD_ID_FLAG_MM_VENUS2_IMG   0x00000080

#define MMI_RP_MENU_OLD_ID_TAG "@OID:"
#define MMI_RP_MENU_OLD_ID_TAG_LEN 5        /* String length of MMI_RP_MENU_OLD_ID_TAG */

#define MMI_RP_STR_MMI_RG_MENU_TYPE_ORIGINAL "MMI_RG_MENU_TYPE_ORIGINAL"
#define MMI_RP_STR_MMI_RG_MENU_TYPE_APP_MAIN "MMI_RG_MENU_TYPE_APP_MAIN"
#define MMI_RP_STR_MMI_RG_MENU_TYPE_APP_SUB "MMI_RG_MENU_TYPE_APP_SUB"
#define MMI_RP_STR_MMI_RG_MENU_TYPE_OPTION "MMI_RG_MENU_TYPE_OPTION"

#define MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_LIST           "LIST_MENU"
#define MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_MATRIX         "MATRIX_MENU"
#define MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_CIRCULAR_3D    "CIRCULAR_3D_MENU"
#define MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_PAGE           "PAGE_MENU"
#define MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_ANI_BG_LIST    "ANI_BG_LIST_MENU"
#define MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_MATRIX_EMS     "MATRIX_MENU_EMS"
#define MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_ROTATE         "ROTATE_MENU"
#define MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_MOTION         "LIST_MATRIX_MENU"
#define MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_LIST_MATRIX    "MOTION_MENU"
#define MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_MATRIX_PAGE    "MATRIX_PAGE_MENU"

#define MMI_RP_MENU_PARENT_STACK_PUSH(x)\
do{\
    if(g_mmi_rp_menu_cntx.parent_stack.top >= MMI_RP_MENU_PARENT_STACK_MAX)\
    {\
       MMI_RP_ERROR(RP_ERR_MENU_PARENT_STACK_OVERFLOW_ERROR);\
    }\
    else\
    {\
        g_mmi_rp_menu_cntx.parent_stack.menu_id[++g_mmi_rp_menu_cntx.parent_stack.top] = x;\
    }\
}while(0)\

#define MMI_RP_MENU_PARENT_STACK_POP()\
do{\
    if(g_mmi_rp_menu_cntx.parent_stack.top >= 0)\
    {\
        g_mmi_rp_menu_cntx.parent_stack.menu_id[g_mmi_rp_menu_cntx.parent_stack.top--] = 0;\
    }\
}while(0)\

#define MMI_RP_MENU_PARENT_STACK_TOP(x)\
do{\
    if(g_mmi_rp_menu_cntx.parent_stack.top >= 0)\
    {\
        x = g_mmi_rp_menu_cntx.parent_stack.menu_id[g_mmi_rp_menu_cntx.parent_stack.top];\
    }\
}while(0)\

typedef enum 
{
    MMI_RP_MENU_CHILD_MENU_DEFAULT_FALSE,
    MMI_RP_MENU_CHILD_MENU_DEFAULT_TRUE,
    MMI_RP_MENU_CHILD_MENU_DEFAULT_TOTAL
}mmi_rp_menu_child_menu_default_enum;

typedef enum 
{
    MMI_RP_MENU_CHILD_MENU_TYPE_MENU,
    MMI_RP_MENU_CHILD_MENU_TYPE_SEPARATOR,
    MMI_RP_MENU_CHILD_MENU_TYPE_TOTAL
}mmi_rp_menu_child_menu_type_enum;

typedef enum 
{
    MMI_RP_MENU_TYPE_ORIGINAL,
    MMI_RP_MENU_TYPE_APP_MAIN,
    MMI_RP_MENU_TYPE_APP_SUB,
    MMI_RP_MENU_TYPE_OPTION,
    
    MMI_RP_MENU_TYPE_DISP_LIST,       
    MMI_RP_MENU_TYPE_DISP_MATRIX,     
    MMI_RP_MENU_TYPE_DISP_CIRCULAR_3D,
    MMI_RP_MENU_TYPE_DISP_PAGE,       
    MMI_RP_MENU_TYPE_DISP_ANI_BG_LIST,
    MMI_RP_MENU_TYPE_DISP_MATRIX_EMS, 
    MMI_RP_MENU_TYPE_DISP_ROTATE,     
    MMI_RP_MENU_TYPE_DISP_MOTION,     
    MMI_RP_MENU_TYPE_DISP_LIST_MATRIX,
    MMI_RP_MENU_TYPE_DISP_MATRIX_PAGE,
   
    MMI_RP_MENU_TYPE_TOTAL
}mmi_rp_menu_type_enum;

typedef enum 
{
    MMI_RP_MENU_FLAG_NONMOVEABLE,
    MMI_RP_MENU_FLAG_MOVEABLEWITHINPARENT,
    MMI_RP_MENU_FLAG_MOVEABLEACROSSPARENT,
    MMI_RP_MENU_FLAG_INSERTABLE,
    MMI_RP_MENU_FLAG_SHORTCUTABLE,
    MMI_RP_MENU_FLAG_RADIO,
    MMI_RP_MENU_FLAG_CHECKBOX,
    MMI_RP_MENU_FLAG_TOTAL
}mmi_rp_menu_flag_enum;

typedef enum 
{
    MMI_RP_MENU_SHORTCUT_STATE_OFF,
    MMI_RP_MENU_SHORTCUT_STATE_ON,
    MMI_RP_MENU_SHORTCUT_STATE_TOTAL
}mmi_rp_menu_shortcut_state_enum;

typedef struct
{
    U8 *launch_func;
    U8 *menu_id; 
    U8 *str_id; 
    U8 *img_id; 
    U8 *shortcut_str_id; 
}mmi_rp_menu_shortcut_data_struct;

typedef struct
{
    mmi_rp_menu_shortcut_data_struct *shortcuts_data;
    U32 total;
}mmi_rp_menu_shortcut_struct;

typedef struct
{
    U8 *id_str;          
    U8 *str_id_str;          
    U8 *img_id_str;          
    U8 *group_str;          
    U8 *highlight_str;          
    U8 *hint_str;          
    U8 *notify_str;          
    U8 *parent_id_str;
    U32 old_id_flags; /* old IDs used for images, strings or menus. 8 bits used for 8 IDs */
}mmi_rp_menu_xmldata_struct;

typedef struct
{
    U16 id;
    U16 parent_id;
    U16 child_count;
    U8 *default_menu_id;        /* Default menu ID for CSK. String pointer as we don't have the numeric values, in case it is an old menu ID. */
    U8 *submenu[MMI_RP_MENU_CHILDREN_MENU_SIZE];    /* Use string pointers */
    mmi_rp_menu_xmldata_struct xml_data;
    MMI_BOOL filter;
    U8 type; /* "ORIGINAL", "APP_MAIN", "APP_SUB", "OPTION" */
    U8 flag;  /* RADIO or CHECKBOX */
}mmi_rp_menus_struct;

typedef struct
{
    U8 *group_name;
    U8 *menu_ids[MMI_RP_MENU_GROUP_MENU_MAX];
    U16 menu_count;
}mmi_rp_menu_group_struct;

typedef struct
{
    mmi_rp_menu_group_struct groups[MMI_RP_MENU_GROUP_ID_MAX];
    U16 group_count;
}mmi_rp_menu_group_data_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_menus_struct *menus;
}mmi_rp_menu_data_struct;

typedef struct
{
    U8 *id_str;
    U8 *mm_list_img_str;
    U8 *mm_matrix_img_str;
    U8 *mm_page_img_str;
    U8 *mm_venus1_img_str;
    U8 *mm_venus2_img_str;
    U8 *mm_matrix_highlight_img_str;
    U8 *mm_matrix_controlled_area_img_str;
    U8 *mm_venus1_highlight_img_str;
    U8 *mm_title_img_str;
    U8 *mm_3d_img_str;
    U8 *mm_launch_str;
}mmi_rp_menu_mainmenu_xmldata_struct;

typedef struct
{
    S32 main_menu_total;
    U8 *header_files_str;
    mmi_rp_menu_mainmenu_xmldata_struct *mainmenu_data;
    mmi_rp_hash_struct *main_menu_id_hash;
}mmi_rp_menu_mainmenuid_struct;

typedef struct
{
    U8 *set_name;
    U8* menu_ids[MMI_RP_MENU_SET_MENU_MAX];
    U16 menu_count;
}mmi_rp_menu_set_struct;

typedef struct
{
    mmi_rp_menu_set_struct sets[MMI_RP_MENU_SET_ID_MAX];
    S16 curr_set_index;
    U16 total;
    mmi_rp_hash_struct *set_hash;
}mmi_rp_menu_set_data_struct;

typedef struct
{
    U16 menu_id[MMI_RP_MENU_PARENT_STACK_MAX];
    S16 top;
}mmi_rp_menu_parent_id_stack_struct;

typedef struct
{
    mmi_rp_menu_data_struct *app_menu_data;
    mmi_rp_menu_mainmenuid_struct main_menu_ids;
    mmi_rp_menu_group_data_struct group_data;
    mmi_rp_menu_set_data_struct set_data;
    mmi_rp_menu_parent_id_stack_struct parent_stack;
    mmi_rp_menu_child_menu_default_enum current_default_id_flag; /* 0 - FALSE, 1 - TRUE */
    mmi_rp_menu_child_menu_type_enum current_type_flag;    /* 0 - MENU, 1- SEPARATOR */
    MMI_BOOL current_child_menu_check;
    mmi_rp_hash_struct *hash;
    mmi_rp_hash_struct *hash_others;
    mmi_rp_menu_shortcut_struct shortcut;
}mmi_rp_menu_cntx_struct;

extern mmi_rp_menu_cntx_struct g_mmi_rp_menu_cntx;

extern void mmi_rp_menu_init(void);
extern void mmi_rp_menu_set_app_range(void);

extern int mmi_rp_menu_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_menu_end_handler(void *data, const kal_char *el);

extern int mmi_rp_menuitem_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_menuitem_end_handler(void *data, const kal_char *el);

extern int mmi_rp_mainmenuitem_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mainmenuitem_end_handler(void *data, const kal_char *el);

extern int mmi_rp_menuset_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_menuset_end_handler(void *data, const kal_char *el);

extern int mmi_rp_menuset_id_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_menuset_id_end_handler(void *data, const kal_char *el);
extern int mmi_rp_menuset_id_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern int mmi_rp_menuitem_id_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_menuitem_id_end_handler(void *data, const kal_char *el);
extern int mmi_rp_menuitem_id_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern MMI_BOOL mmi_rp_menu_find_menu_id(U8* str_menu_id, U16* menu_id);
extern void mmi_rp_menu_filter_menuitem(void);

extern void mmi_rp_menu_output_phase1(void);
extern void mmi_rp_menu_output_phase2(void);

#endif /* RESXML_MENU_H */
