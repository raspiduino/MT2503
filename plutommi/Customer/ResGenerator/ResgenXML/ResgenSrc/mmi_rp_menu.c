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
 *  mmi_rp_menu.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Plutommi Resource Generator Ver 2.0 (XML style) Menu Handler
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

#include "MMIDataType.h"
#include "mmi_rp_xml.h"
#include "mmi_rp_xml_def.h"
#include "mmi_rp_menu.h"
#include "mmi_rp_image.h"
#include "mmi_rp_hash.h"

#include "mmi_res_range_def.h"
#include "GlobalConstants.h"
    
    
extern const mmi_resource_base_struct g_mmi_resource_base_table[];

void mmi_rp_menu_output_phase1_app_def_h_file(U32 app_index, FILE *p_file);

#ifdef __RESGEN_INTERNAL_POP_FILE_REDUCE__
void mmi_rp_menu_output_phase2_app_c_file(U32 app_index);
#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
void mmi_rp_menu_output_phase2_app_c_file(U32 app_index, FILE *p_file);
#endif // __RESGEN_INTERNAL_POP_FILE_REDUCE__

MMI_BOOL mmi_rp_menu_add_menuitem(mmi_rp_menu_xmldata_struct temp);
MMI_BOOL mmi_rp_menu_add_menu_to_groups(U8 *groups, U8 *menu_id);
MMI_BOOL mmi_rp_menu_add_menu_child(U8 *child_menu_id_str, MMI_BOOL is_add_parent);
MMI_BOOL mmi_rp_menu_add_menu_to_menuset(U8 *menu_id);
void mmi_rp_menu_output_phase1_shortcut(void);
void mmi_rp_menu_output_phase2_shortcut(void);


#define MMI_RP_MENU_CURR_APP_MENU       g_mmi_rp_menu_cntx.app_menu_data[g_mmi_rp_mgr_cntx.cur_app_index]

mmi_rp_menu_cntx_struct g_mmi_rp_menu_cntx;

/* These ENUM id strings will be used in ReadRes for menu type */
/* These are defined in CustMenuRes.h */
static U8 *g_mmi_rp_menu_output_type_enum_str[MMI_RP_MENU_TYPE_TOTAL] = 
{
    MMI_RP_STR_MMI_RG_MENU_TYPE_ORIGINAL,
    MMI_RP_STR_MMI_RG_MENU_TYPE_APP_MAIN,
    MMI_RP_STR_MMI_RG_MENU_TYPE_APP_SUB,
    MMI_RP_STR_MMI_RG_MENU_TYPE_OPTION,
    MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_LIST,      
    MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_MATRIX,
    MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_CIRCULAR_3D, 
    MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_PAGE,        
    MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_ANI_BG_LIST, 
    MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_MATRIX_EMS,  
    MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_ROTATE,      
    MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_MOTION,      
    MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_LIST_MATRIX, 
    MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_MATRIX_PAGE
};

static U8 *g_mmi_rp_menu_output_flag_enum_str[MMI_RP_MENU_FLAG_TOTAL] = 
{
    "NONMOVEABLE",
    "MOVEABLEWITHINPARENT",
    "MOVEABLEACROSSPARENT",
    "INSERTABLE",
    "SHORTCUTABLE",
    "MMI_RG_MENU_FLAG_RADIO",
    "MMI_RG_MENU_FLAG_CHECKBOX"
};

static U8 *g_mmi_rp_menu_separator_str = "MMI_MENU_ID_SEPARATOR";


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menu_init
 * DESCRIPTION
 *  Initializes the menu context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_menu_init(void)
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

    memset(&g_mmi_rp_menu_cntx, 0, sizeof(g_mmi_rp_menu_cntx));

    g_mmi_rp_menu_cntx.app_menu_data = (mmi_rp_menu_data_struct*)malloc(sizeof(mmi_rp_menu_data_struct) * g_mmi_rp_mgr_cntx.total_apps);
    if(!g_mmi_rp_menu_cntx.app_menu_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_menu_cntx.app_menu_data, 0, sizeof(mmi_rp_menu_data_struct) * g_mmi_rp_mgr_cntx.total_apps);

    g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data = (mmi_rp_menu_mainmenu_xmldata_struct*)malloc(sizeof(mmi_rp_menu_mainmenu_xmldata_struct) * MMI_RP_MENU_MAINMENUITEM_ID_MAX);
    if(!g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data, 0, sizeof(mmi_rp_menu_mainmenu_xmldata_struct) * MMI_RP_MENU_MAINMENUITEM_ID_MAX);

    /* Shortcuts */
    g_mmi_rp_menu_cntx.shortcut.shortcuts_data = (mmi_rp_menu_shortcut_data_struct*)malloc(sizeof(mmi_rp_menu_shortcut_data_struct) * MMI_RP_MENU_SHORTCUT_MAX);
    if(!g_mmi_rp_menu_cntx.shortcut.shortcuts_data)
    {
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
    }
    memset(g_mmi_rp_menu_cntx.shortcut.shortcuts_data, 0, sizeof(mmi_rp_menu_shortcut_data_struct) * MMI_RP_MENU_SHORTCUT_MAX);

    /* Reset the menuset curr index */
    g_mmi_rp_menu_cntx.set_data.curr_set_index = -1;

    /* Reset the Parent menu ID stack top */
    g_mmi_rp_menu_cntx.parent_stack.top = -1;

    g_mmi_rp_menu_cntx.hash = mmi_rp_hash_create(0xFFFF);    /* 0xFFFF is the resource ID range */
    g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash = mmi_rp_hash_create(0xFFFF);    /* 0xFFFF is the resource ID range */
    g_mmi_rp_menu_cntx.hash_others = mmi_rp_hash_create(0xFFFF);    /* Assuming 0xFFFF */
    g_mmi_rp_menu_cntx.set_data.set_hash = mmi_rp_hash_create(MMI_RP_MENU_SET_ID_MAX);    /* Max sets are MMI_RP_MENU_SET_ID_MAX 100 */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menu_set_app_range
 * DESCRIPTION
 *  Initializes the menu context structure. Called for every .res file parsed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_menu_set_app_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 range = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_RP_MENU_CURR_APP_MENU.menus == NULL)
    {
        range = g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min + 1;
        MMI_RP_MENU_CURR_APP_MENU.menus = (mmi_rp_menus_struct*)malloc(sizeof(mmi_rp_menus_struct) * range);

        if((!MMI_RP_MENU_CURR_APP_MENU.menus) && (range > 0))
        {
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE);
        }

        memset(MMI_RP_MENU_CURR_APP_MENU.menus, 0, sizeof(mmi_rp_menus_struct) * range);
    }
}


/*****************************************************************************
 * FUNCTION
 *  res_menu_start_handler
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
int mmi_rp_menu_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    mmi_rp_menu_xmldata_struct temp_menuitem_data;
    MMI_BOOL result = MMI_FALSE;
    U8 menu_type = MMI_RP_MENU_TYPE_ORIGINAL, menu_flag = MMI_RP_MENU_FLAG_NONMOVEABLE;
    S32 parent_tag_id = -1;
    mmi_rp_scope_enum curr_scope = MMI_RP_SCOPE_NONE, parent_scope = MMI_RP_SCOPE_NONE;
    mmi_rp_menu_shortcut_state_enum curr_shortcut_state = MMI_RP_MENU_SHORTCUT_STATE_OFF;
    mmi_rp_menu_shortcut_data_struct temp_shortcut_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Menu-start: %s\n", el);

    /* Checking correct order of tags */
    if((strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0) &&
        (strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_MENU) != 0))
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    memset(&temp_menuitem_data, 0, sizeof(temp_menuitem_data));
    memset(&temp_shortcut_data, 0, sizeof(temp_shortcut_data));

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID) == 0)
        {
            temp_menuitem_data.id_str = (U8*)attr[index + 1]; /* Not adding into hash to check for duplicacy. */
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_TYPE) == 0)
        {
            if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_AUTO_APP_MAIN) == 0)
            {
                menu_type = MMI_RP_MENU_TYPE_APP_MAIN;
            }
            else if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_AUTO_APP_SUB) == 0)
            {
                menu_type = MMI_RP_MENU_TYPE_APP_SUB;
            }
            else if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_AUTO_OPTION) == 0)
            {
                menu_type = MMI_RP_MENU_TYPE_OPTION;
            }
            else if(strcmp(attr[index + 1], MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_LIST) == 0)
            {
                menu_type = MMI_RP_MENU_TYPE_DISP_LIST;
            }
            else if(strcmp(attr[index + 1], MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_MATRIX) == 0)
            {
                menu_type = MMI_RP_MENU_TYPE_DISP_MATRIX;
            }
            else if(strcmp(attr[index + 1], MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_CIRCULAR_3D) == 0)
            {
                menu_type = MMI_RP_MENU_TYPE_DISP_CIRCULAR_3D;
            }
            else if(strcmp(attr[index + 1], MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_PAGE) == 0)
            {
                menu_type = MMI_RP_MENU_TYPE_DISP_PAGE;
            }
            else if(strcmp(attr[index + 1], MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_ANI_BG_LIST) == 0)
            {
                menu_type = MMI_RP_MENU_TYPE_DISP_ANI_BG_LIST;
            }
            else if(strcmp(attr[index + 1], MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_MATRIX_EMS) == 0)
            {
                menu_type = MMI_RP_MENU_TYPE_DISP_MATRIX_EMS;
            }
            else if(strcmp(attr[index + 1], MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_ROTATE) == 0)
            {
                menu_type = MMI_RP_MENU_TYPE_DISP_ROTATE;
            }
            else if(strcmp(attr[index + 1], MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_MOTION) == 0)
            {
                menu_type = MMI_RP_MENU_TYPE_DISP_MOTION;
            }
            else if(strcmp(attr[index + 1], MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_LIST_MATRIX) == 0)
            {
                menu_type = MMI_RP_MENU_TYPE_DISP_LIST_MATRIX;
            }
            else if(strcmp(attr[index + 1], MMI_RP_STR_MMI_RG_MENU_TYPE_DISP_MATRIX_PAGE) == 0)
            {
                menu_type = MMI_RP_MENU_TYPE_DISP_MATRIX_PAGE;
            }            
            else /* Default for "APP_MAIN". */
            {
                menu_type = MMI_RP_MENU_TYPE_ORIGINAL;
            }
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_FLAG) == 0)
        {
            if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_MOVEABLEWITHINPARENT) == 0)
            {
                menu_flag = MMI_RP_MENU_FLAG_MOVEABLEWITHINPARENT;
            }
            else if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_MOVEABLEACROSSPARENT) == 0)
            {
                menu_flag = MMI_RP_MENU_FLAG_MOVEABLEACROSSPARENT;
            }
            else if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_INSERTABLE) == 0)
            {
                menu_flag = MMI_RP_MENU_FLAG_INSERTABLE;
            }
            else if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_SHORTCUTABLE) == 0)
            {
                menu_flag = MMI_RP_MENU_FLAG_SHORTCUTABLE;
            }
            else if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_RADIO) == 0)
            {
                menu_flag = MMI_RP_MENU_FLAG_RADIO;
            }
            else if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_CHECKBOX) == 0)
            {
                menu_flag = MMI_RP_MENU_FLAG_CHECKBOX;
            }
            else /* Default for "APP_MAIN". */
            {
                menu_flag = MMI_RP_MENU_FLAG_NONMOVEABLE;
            }
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_STR) == 0)
        {
            if(strstr(attr[index+1], MMI_RP_MENU_OLD_ID_TAG))
            {
                temp_menuitem_data.old_id_flags |= MMI_RP_MENU_OLD_ID_FLAG_STR;
                temp_menuitem_data.str_id_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)(&(attr[index + 1][MMI_RP_MENU_OLD_ID_TAG_LEN])));
            }
            else
            {
                temp_menuitem_data.str_id_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
            }
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_IMG) == 0)
        {
            if(strstr(attr[index+1], MMI_RP_MENU_OLD_ID_TAG))
            {
                temp_menuitem_data.old_id_flags |= MMI_RP_MENU_OLD_ID_FLAG_IMG;
                temp_menuitem_data.img_id_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)(&(attr[index + 1][MMI_RP_MENU_OLD_ID_TAG_LEN])));
            }
            else
            {
                temp_menuitem_data.img_id_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
            }
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_PARENT) == 0)
        {
            if(attr[index + 1] && attr[index + 1][0])
            {
                temp_menuitem_data.parent_id_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
            }
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_GROUP) == 0)
        {
            temp_menuitem_data.group_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_NOTIFY) == 0)
        {
            temp_menuitem_data.notify_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_HIGHLIGHT) == 0)
        {
            temp_menuitem_data.highlight_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_HINT) == 0)
        {
            temp_menuitem_data.hint_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
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
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_SHORTCUT) == 0)
        {
            if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_SHORTCUT_ON) == 0)
            {
                curr_shortcut_state = MMI_RP_MENU_SHORTCUT_STATE_ON;
            }
            else /* Default for scope. */
            {
                curr_shortcut_state = MMI_RP_MENU_SHORTCUT_STATE_OFF;
            }                 
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_SHORTCUT_IMG) == 0)
        {
            temp_shortcut_data.img_id = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_SHORTCUT_STR) == 0)
        {
            temp_shortcut_data.shortcut_str_id = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_LAUNCH) == 0)
        {
            temp_shortcut_data.launch_func = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
        }
        else 
        {
            MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
                    
        index += 2;
    }

    /* Add this menu in the menus array */
    if(temp_menuitem_data.id_str != NULL)
    {
        result = mmi_rp_menu_add_menuitem(temp_menuitem_data);
    }

    if(result == MMI_TRUE)
    {
        /* If this menu item belongs to a menu tree i.e. it is inside a MENU tag 
         *  Add it in the menu tree. */
        if(g_mmi_rp_menu_cntx.parent_stack.top >= 0)
        {
            mmi_rp_menu_add_menu_child(temp_menuitem_data.id_str, MMI_TRUE);

            /* If any parent MENU has XML scope, this should have the XML scope, too. */
            parent_scope = MMI_RP_MENU_CURR_APP_MENU.menus[g_mmi_rp_menu_cntx.parent_stack.menu_id[g_mmi_rp_menu_cntx.parent_stack.top] - (MMI_RP_CURR_APP_BASE_ID + 1)].filter;
            curr_scope = (parent_scope ? MMI_RP_SCOPE_NONE : MMI_RP_SCOPE_XML);
        }

        MMI_RP_MENU_PARENT_STACK_PUSH(MMI_RP_MENU_CURR_APP_MENU.total_count - 1 + (MMI_RP_CURR_APP_BASE_ID + 1));
        MMI_RP_MENU_CURR_APP_MENU.menus[MMI_RP_MENU_CURR_APP_MENU.total_count - 1].type = menu_type;
        MMI_RP_MENU_CURR_APP_MENU.menus[MMI_RP_MENU_CURR_APP_MENU.total_count - 1].flag = menu_flag;
        MMI_RP_MENU_CURR_APP_MENU.menus[MMI_RP_MENU_CURR_APP_MENU.total_count - 1].filter = (curr_scope == MMI_RP_SCOPE_XML ? MMI_FALSE : MMI_TRUE);

        /* Add the new menu id to group */
        if(temp_menuitem_data.group_str != NULL)
        {
            mmi_rp_menu_add_menu_to_groups(temp_menuitem_data.group_str, MMI_RP_MENU_CURR_APP_MENU.menus[MMI_RP_MENU_CURR_APP_MENU.total_count - 1].xml_data.id_str);
        }

        /* Add to Shortcut array */
        if(curr_shortcut_state == MMI_RP_MENU_SHORTCUT_STATE_ON)
        {
            if(g_mmi_rp_menu_cntx.shortcut.total >= MMI_RP_MENU_SHORTCUT_MAX)
            {
                /* Exceed the limit. Raise an error. */
                MMI_RP_ERROR_DATA(RP_ERR_MENU_SHORTCUT_EXCEED_MAX_RANGE, temp_menuitem_data.id_str);
                MMI_RP_MENU_PARENT_STACK_POP();
                return MMI_RP_PARSE_ERROR_SKIP_TAG;
            }

            if(temp_shortcut_data.launch_func == NULL || temp_shortcut_data.launch_func[0] == 0)
            {
                /* Launch function not specified. Raise the error. */
                MMI_RP_ERROR_DATA(RP_ERR_MENU_SHORTCUT_NO_LAUNCH_FUNC, temp_menuitem_data.id_str);
                MMI_RP_MENU_PARENT_STACK_POP();
                return MMI_RP_PARSE_ERROR_SKIP_TAG;
            }

            /* Removing this for new request */
            /* 
            if(temp_shortcut_data.img_id == NULL || temp_shortcut_data.img_id[0] == 0)
            {
                // Comment -> If Shortcut image ID is not specified, Raise an error.
                MMI_RP_PARSE_ERROR_DATA(RP_ERR_MENU_SHORTCUT_IMAGE_ID_NOT_SPECIFIED, temp_menuitem_data.id_str);
            }
            */

            temp_shortcut_data.menu_id = MMI_RP_MENU_CURR_APP_MENU.menus[MMI_RP_MENU_CURR_APP_MENU.total_count - 1].xml_data.id_str;
            temp_shortcut_data.str_id = MMI_RP_MENU_CURR_APP_MENU.menus[MMI_RP_MENU_CURR_APP_MENU.total_count - 1].xml_data.str_id_str;

            g_mmi_rp_menu_cntx.shortcut.shortcuts_data[g_mmi_rp_menu_cntx.shortcut.total].menu_id = temp_shortcut_data.menu_id;
            g_mmi_rp_menu_cntx.shortcut.shortcuts_data[g_mmi_rp_menu_cntx.shortcut.total].str_id = temp_shortcut_data.str_id;
            g_mmi_rp_menu_cntx.shortcut.shortcuts_data[g_mmi_rp_menu_cntx.shortcut.total].shortcut_str_id = temp_shortcut_data.shortcut_str_id;
            g_mmi_rp_menu_cntx.shortcut.shortcuts_data[g_mmi_rp_menu_cntx.shortcut.total].img_id = temp_shortcut_data.img_id;
            g_mmi_rp_menu_cntx.shortcut.shortcuts_data[g_mmi_rp_menu_cntx.shortcut.total].launch_func = temp_shortcut_data.launch_func;
            g_mmi_rp_menu_cntx.shortcut.total++;
        }
    }

    if(result == MMI_FALSE)
    {
        /* Duplicate ID found. Menuitem not added */
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  res_menu_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_menu_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Resetting the Parent menu tag */
    MMI_RP_MENU_PARENT_STACK_POP();
    MMI_RP_DEBUG_INFO("Menu-end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  res_menuitem_start_handler
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
int mmi_rp_menuitem_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    mmi_rp_menu_xmldata_struct temp_menuitem_data;
    MMI_BOOL result = MMI_FALSE;
    S32 parent_tag_id = -1;
    mmi_rp_menu_shortcut_state_enum curr_shortcut_state = MMI_RP_MENU_SHORTCUT_STATE_OFF;
    mmi_rp_menu_shortcut_data_struct temp_shortcut_data;
    mmi_rp_scope_enum curr_scope = MMI_RP_SCOPE_NONE, parent_scope = MMI_RP_SCOPE_NONE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Menuitem-start: %s\n", el);

    /* Checking correct order of tags */
    if((strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0) &&
        (strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_MENU) != 0) &&
        (strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_MENUSET) != 0))
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    memset(&temp_menuitem_data, 0, sizeof(temp_menuitem_data));
    memset(&temp_shortcut_data, 0, sizeof(temp_shortcut_data));
    
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID) == 0)
        {
            if(strstr(attr[index+1], MMI_RP_MENU_OLD_ID_TAG))
            {
                temp_menuitem_data.old_id_flags |= MMI_RP_MENU_OLD_ID_FLAG_ID;
                temp_menuitem_data.id_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)(&(attr[index + 1][MMI_RP_MENU_OLD_ID_TAG_LEN])));
            }
            else
            {
                temp_menuitem_data.id_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
            }
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_STR) == 0)
        {
            if(strstr(attr[index+1], MMI_RP_MENU_OLD_ID_TAG))
            {
                temp_menuitem_data.old_id_flags |= MMI_RP_MENU_OLD_ID_FLAG_STR;
                temp_menuitem_data.str_id_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)(&(attr[index + 1][MMI_RP_MENU_OLD_ID_TAG_LEN])));
            }
            else
            {
                temp_menuitem_data.str_id_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
            }
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_IMG) == 0)
        {
            if(strstr(attr[index+1], MMI_RP_MENU_OLD_ID_TAG))
            {
                temp_menuitem_data.old_id_flags |= MMI_RP_MENU_OLD_ID_FLAG_IMG;
                temp_menuitem_data.img_id_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)(&(attr[index + 1][MMI_RP_MENU_OLD_ID_TAG_LEN])));
            }
            else
            {
                temp_menuitem_data.img_id_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
            }
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_PARENT) == 0)
        {
            if(attr[index + 1] && attr[index + 1][0])
            {
                temp_menuitem_data.parent_id_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
            }
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_GROUP) == 0)
        {
            temp_menuitem_data.group_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_NOTIFY) == 0)
        {
            temp_menuitem_data.notify_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_HIGHLIGHT) == 0)
        {
            temp_menuitem_data.highlight_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_HINT) == 0)
        {
            temp_menuitem_data.hint_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_SHORTCUT) == 0)
        {
            if(strcmp(attr[index + 1], MMI_RP_MGR_VAL_SHORTCUT_ON) == 0)
            {
                curr_shortcut_state = MMI_RP_MENU_SHORTCUT_STATE_ON;
            }
            else /* Default for scope. */
            {
                curr_shortcut_state = MMI_RP_MENU_SHORTCUT_STATE_OFF;
            }                 
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_SHORTCUT_IMG) == 0)
        {
            temp_shortcut_data.img_id = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_SHORTCUT_STR) == 0)
        {
            temp_shortcut_data.shortcut_str_id = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
        }
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_LAUNCH) == 0)
        {
            temp_shortcut_data.launch_func = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)attr[index + 1]);
        }
        else 
        {
            MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        
        index += 2;
    }

    /* Add this menu in the menus array */
    if(temp_menuitem_data.id_str != NULL)
    {
        result = mmi_rp_menu_add_menuitem(temp_menuitem_data);
    }
    else
    {
        MMI_RP_PARSE_WARNING(RP_WARN_RES_ID_NULL);
    }

    if(result == MMI_FALSE)
    {
        /* Duplicate ID found. Menuitem not added */ 
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    if(result == MMI_TRUE)
    {
        /* If this menu item belongs to a menu tree i.e. it is inside a MENU tag 
         *  Add it in the menu tree. */
        if(g_mmi_rp_menu_cntx.parent_stack.top >= 0)
        {
            mmi_rp_menu_add_menu_child(temp_menuitem_data.id_str, MMI_TRUE);
            /* If any parent MENU has XML scope, this should have the XML scope, too. */
            parent_scope = MMI_RP_MENU_CURR_APP_MENU.menus[g_mmi_rp_menu_cntx.parent_stack.menu_id[g_mmi_rp_menu_cntx.parent_stack.top] - (MMI_RP_CURR_APP_BASE_ID + 1)].filter;
            curr_scope = (parent_scope ? MMI_RP_SCOPE_NONE : MMI_RP_SCOPE_XML);
        }
        MMI_RP_MENU_CURR_APP_MENU.menus[MMI_RP_MENU_CURR_APP_MENU.total_count - 1].filter = (curr_scope == MMI_RP_SCOPE_XML ? MMI_FALSE : MMI_TRUE);

        /* Add the new menu id to group */
        if(temp_menuitem_data.group_str != NULL)
        {
            mmi_rp_menu_add_menu_to_groups(temp_menuitem_data.group_str, MMI_RP_MENU_CURR_APP_MENU.menus[MMI_RP_MENU_CURR_APP_MENU.total_count - 1].xml_data.id_str);
        }

        /* Add the new menu id to menuset */
        if(g_mmi_rp_menu_cntx.set_data.curr_set_index != -1)
        {
            mmi_rp_menu_add_menu_to_menuset(temp_menuitem_data.id_str);
        }

        /* Add to Shortcut array */
        if(curr_shortcut_state == MMI_RP_MENU_SHORTCUT_STATE_ON)
        {
            if(g_mmi_rp_menu_cntx.shortcut.total >= MMI_RP_MENU_SHORTCUT_MAX)
            {
                /* Exceed the limit. Raise an error. */
                MMI_RP_ERROR_DATA(RP_ERR_MENU_SHORTCUT_EXCEED_MAX_RANGE, temp_menuitem_data.id_str);
                return MMI_RP_PARSE_ERROR_SKIP_TAG;
            }

            if(temp_shortcut_data.launch_func == NULL || temp_shortcut_data.launch_func[0] == 0)
            {
                /* Launch function not specified. Raise the error. */
                MMI_RP_ERROR_DATA(RP_ERR_MENU_SHORTCUT_NO_LAUNCH_FUNC, temp_menuitem_data.id_str);
                return MMI_RP_PARSE_ERROR_SKIP_TAG;
            }

            /* Removing this for new request */
            /* 
            if(temp_shortcut_data.img_id == NULL || temp_shortcut_data.img_id[0] == 0)
            {
                // Comment -> If Shortcut image ID is not specified, Raise an error.
                MMI_RP_PARSE_ERROR_DATA(RP_ERR_MENU_SHORTCUT_IMAGE_ID_NOT_SPECIFIED, temp_menuitem_data.id_str);
            }
            */

            temp_shortcut_data.menu_id = MMI_RP_MENU_CURR_APP_MENU.menus[MMI_RP_MENU_CURR_APP_MENU.total_count - 1].xml_data.id_str;
            temp_shortcut_data.str_id = MMI_RP_MENU_CURR_APP_MENU.menus[MMI_RP_MENU_CURR_APP_MENU.total_count - 1].xml_data.str_id_str;

            g_mmi_rp_menu_cntx.shortcut.shortcuts_data[g_mmi_rp_menu_cntx.shortcut.total].menu_id = temp_shortcut_data.menu_id;
            g_mmi_rp_menu_cntx.shortcut.shortcuts_data[g_mmi_rp_menu_cntx.shortcut.total].str_id = temp_shortcut_data.str_id;
            g_mmi_rp_menu_cntx.shortcut.shortcuts_data[g_mmi_rp_menu_cntx.shortcut.total].shortcut_str_id = temp_shortcut_data.shortcut_str_id;
            g_mmi_rp_menu_cntx.shortcut.shortcuts_data[g_mmi_rp_menu_cntx.shortcut.total].img_id = temp_shortcut_data.img_id;
            g_mmi_rp_menu_cntx.shortcut.shortcuts_data[g_mmi_rp_menu_cntx.shortcut.total].launch_func = temp_shortcut_data.launch_func;
            g_mmi_rp_menu_cntx.shortcut.total++;
        }
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  res_menuitem_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_menuitem_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Menuitem-end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_mainmenuitem_header_handler
 * DESCRIPTION
 *  This function is for XML parser to return start tag information to application
 * PARAMETERS
 *  header_files_str        [IN]        Reserved
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mainmenuitem_header_handler(U8 *header_files_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *last = NULL;
    U8 temp[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    
    if(g_mmi_rp_menu_cntx.main_menu_ids.header_files_str)           /* If this is the second header attrib, add the file name appended by ','. */
    {
        last = g_mmi_rp_menu_cntx.main_menu_ids.header_files_str;
        strcpy(temp, last);
        strcat(temp, ",");
        strcat(temp, header_files_str);
        g_mmi_rp_menu_cntx.main_menu_ids.header_files_str = (U8*)mmi_rp_hash_add(g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash, temp);
    }
    else
    {
        g_mmi_rp_menu_cntx.main_menu_ids.header_files_str = (U8*)mmi_rp_hash_add(g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash, header_files_str);
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  res_mainmenuitem_start_handler
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
int mmi_rp_mainmenuitem_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    mmi_rp_menu_mainmenu_xmldata_struct temp_menuitem_data;
    S32 parent_tag_id = -1;
    S32 curr_index = -1;
    U8 *temp_header_files_str = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Menuitem-start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_APP) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    if(g_mmi_rp_menu_cntx.main_menu_ids.main_menu_total >= MMI_RP_MENU_MAINMENUITEM_ID_MAX)
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    memset(&temp_menuitem_data, 0, sizeof(temp_menuitem_data));
    
    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if(strcmp(attr[index], MMI_RP_MGR_ATTR_ID) == 0)
        {
            temp_menuitem_data.id_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_VAL_MM_LIST_IMG) == 0)
        {
            temp_menuitem_data.mm_list_img_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_VAL_MM_MATRIX_IMG) == 0)
        {
            temp_menuitem_data.mm_matrix_img_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_VAL_MM_PAGE_IMG) == 0)
        {
            temp_menuitem_data.mm_page_img_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_VAL_MM_VENUS1_IMG) == 0)
        {
            temp_menuitem_data.mm_venus1_img_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_VAL_MM_VENUS2_IMG) == 0)
        {
            temp_menuitem_data.mm_venus2_img_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_VAL_MM_MATRIX_HIGHLIGHT_IMG) == 0)
        {
            temp_menuitem_data.mm_matrix_highlight_img_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_VAL_MM_MATRIX_CONTROLLED_AREA_IMG) == 0)
        {
            temp_menuitem_data.mm_matrix_controlled_area_img_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_VAL_MM_VENUS1_HIGHLIGHT_IMG) == 0)
        {
            temp_menuitem_data.mm_venus1_highlight_img_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_VAL_MM_TITLE_IMG) == 0)
        {
            temp_menuitem_data.mm_title_img_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_VAL_MM_3D_IMAGE) == 0)
        {
            temp_menuitem_data.mm_3d_img_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_VAL_MM_LAUNCH) == 0)
        {
            temp_menuitem_data.mm_launch_str = (U8*)attr[index + 1];
        }
        else if(strcmp(attr[index], MMI_RP_MGR_VAL_MM_HEADER) == 0)
        {
            temp_header_files_str = (U8*)attr[index + 1];
        }
        else 
        {
            MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }

        index += 2;
    }

    /* Add main menu in the main_menu_ids array */
    if(temp_menuitem_data.id_str != NULL)
    {
        /* Check main menu IDs array for duplicated main menu IDs. */
        if(mmi_rp_hash_find(g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash, temp_menuitem_data.id_str))
        {
            MMI_RP_PARSE_WARNING(RP_WARN_DUPLICATE_ID);
            /* Duplicate ID found. Menuitem not added */ 
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }
        else
        {
            curr_index = g_mmi_rp_menu_cntx.main_menu_ids.main_menu_total;

            g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[curr_index].id_str = 
                (U8*)mmi_rp_hash_add(
                    g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash,
                    temp_menuitem_data.id_str ? temp_menuitem_data.id_str : (U8*)(""));

            g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[curr_index].mm_list_img_str = 
                (U8*)mmi_rp_hash_add(
                    g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash, 
                    temp_menuitem_data.mm_list_img_str ? temp_menuitem_data.mm_list_img_str : (U8*)(""));

            g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[curr_index].mm_matrix_img_str = 
                (U8*)mmi_rp_hash_add(
                    g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash, 
                    temp_menuitem_data.mm_matrix_img_str ? temp_menuitem_data.mm_matrix_img_str : (U8*)(""));

            g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[curr_index].mm_page_img_str = 
                (U8*)mmi_rp_hash_add(
                    g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash,
                    temp_menuitem_data.mm_page_img_str ? temp_menuitem_data.mm_page_img_str : (U8*)(""));

            g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[curr_index].mm_venus1_img_str = 
                (U8*)mmi_rp_hash_add(
                    g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash, 
                    temp_menuitem_data.mm_venus1_img_str ? temp_menuitem_data.mm_venus1_img_str : (U8*)(""));

            g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[curr_index].mm_venus2_img_str = 
                (U8*)mmi_rp_hash_add(
                    g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash, 
                    temp_menuitem_data.mm_venus2_img_str ? temp_menuitem_data.mm_venus2_img_str : (U8*)(""));

            g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[curr_index].mm_matrix_highlight_img_str = 
                (U8*)mmi_rp_hash_add(
                    g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash, 
                    temp_menuitem_data.mm_matrix_highlight_img_str ? temp_menuitem_data.mm_matrix_highlight_img_str : (U8*)(""));

            g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[curr_index].mm_matrix_controlled_area_img_str = 
                (U8*)mmi_rp_hash_add(
                    g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash, 
                    temp_menuitem_data.mm_matrix_controlled_area_img_str ? temp_menuitem_data.mm_matrix_controlled_area_img_str : (U8*)(""));

            g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[curr_index].mm_venus1_highlight_img_str = 
                (U8*)mmi_rp_hash_add(
                    g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash, 
                    temp_menuitem_data.mm_venus1_highlight_img_str ? temp_menuitem_data.mm_venus1_highlight_img_str : (U8*)(""));

            g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[curr_index].mm_title_img_str = 
                (U8*)mmi_rp_hash_add(
                    g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash, 
                    temp_menuitem_data.mm_title_img_str ? temp_menuitem_data.mm_title_img_str : (U8*)(""));

            g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[curr_index].mm_3d_img_str = 
                (U8*)mmi_rp_hash_add(
                    g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash, 
                    temp_menuitem_data.mm_3d_img_str ? temp_menuitem_data.mm_3d_img_str : (U8*)(""));

            g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[curr_index].mm_launch_str = 
                (U8*)mmi_rp_hash_add(
                    g_mmi_rp_menu_cntx.main_menu_ids.main_menu_id_hash, 
                    temp_menuitem_data.mm_launch_str ? temp_menuitem_data.mm_launch_str : (U8*)(""));

            if(temp_header_files_str)
            {
                mmi_rp_mainmenuitem_header_handler(temp_header_files_str);
            }

            g_mmi_rp_menu_cntx.main_menu_ids.main_menu_total++;
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
 *  mmi_rp_mainmenuitem_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_mainmenuitem_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Menuitem-end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menuset_start_handler
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
int mmi_rp_menuset_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    U8 *id_str = NULL;
    S32 parent_tag_id = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Menuset-start: %s\n", el);

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
            id_str = (U8*)attr[index + 1];
        }
        else 
        {
            MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }            
        index += 2;
    }

    if(!id_str || !(*id_str))
    {
        MMI_RP_PARSE_WARNING(RP_WARN_RES_ID_NULL);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /* Check duplicate SET ID */
    if(id_str && mmi_rp_hash_find(g_mmi_rp_menu_cntx.set_data.set_hash, id_str))
    {
        /* Duplicate ID found. MenuSet not added */ 
        MMI_RP_PARSE_WARNING(RP_WARN_DUPLICATE_ID);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    if(g_mmi_rp_menu_cntx.set_data.total >= MMI_RP_MENU_SET_ID_MAX)
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    g_mmi_rp_menu_cntx.set_data.curr_set_index = g_mmi_rp_menu_cntx.set_data.total;
    g_mmi_rp_menu_cntx.set_data.sets[g_mmi_rp_menu_cntx.set_data.curr_set_index].set_name = (U8*)mmi_rp_hash_add(g_mmi_rp_menu_cntx.set_data.set_hash, id_str);
    g_mmi_rp_menu_cntx.set_data.total++;
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menuset_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_menuset_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_rp_menu_cntx.set_data.curr_set_index = -1;
    
    MMI_RP_DEBUG_INFO("Menuset-end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menuset_id_start_handler
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
int mmi_rp_menuset_id_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    U32 i = 0;
    S32 parent_tag_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Menuset-start: %s\n", el);

    /* Checking correct order of tags */
    if(strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_MENU) != 0)
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        /* Currently, MENUSET_ID tag doesn't require any attribute. */
        MMI_RP_ERROR_DATA(RP_ERR_UNKNOWN_ATTR, attr[index]);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;

        index += 2;
    }

    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menuset_id_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_menuset_id_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Menuset-end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menuset_id_data_handler
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
int mmi_rp_menuset_id_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 parent_id = 0;
    U8 *temp = NULL;
    U8 *id_str = NULL;
    S16 curr_set_index = -1; 
    U16 curr_menu_count = 0;
    S32 parent_tag_id = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Menuset_id-data: %s\n", data);

    MMI_RP_MENU_PARENT_STACK_TOP(parent_id);

    id_str = (U8*)data;

    if(!id_str || !(*id_str))
    {
        MMI_RP_PARSE_WARNING(RP_WARN_RES_ID_NULL);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    /* If the menuset belongs to a menu tree i.e. it is inside a MENU tag 
     *  Add it in the menu tree. */
    if(g_mmi_rp_menu_cntx.parent_stack.top >= 0)
    {
        for(i = 0; i < g_mmi_rp_menu_cntx.set_data.total; i++)
        {
            if(strcmp(g_mmi_rp_menu_cntx.set_data.sets[i].set_name, id_str) == 0)
            {
                curr_set_index = i;
                break;
            }
        }

        if(curr_set_index == -1)
        {
            /* MenuSet ID not created yet. Exit resgen. */
            MMI_RP_ERROR(RP_ERR_TAG_MENUSET_ID_NOT_SPECIFIED);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }

        curr_menu_count = g_mmi_rp_menu_cntx.set_data.sets[curr_set_index].menu_count;
        for(i = 0; i < curr_menu_count; i++)
        {
            mmi_rp_menu_add_menu_child(g_mmi_rp_menu_cntx.set_data.sets[curr_set_index].menu_ids[i], MMI_TRUE);
        }
    }
    else
    {
        /* No parent menu tag exists. Wrong usage of MENUSET_ID tag. */
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  res_menuitem_id_start_handler
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
int mmi_rp_menuitem_id_start_handler(void *data, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   index = 0;
    S32 parent_tag_id = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Checking correct order of tags */
    if((strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_MENU) != 0) &&
        (strcmp(mmi_rp_mgr_stack_top_tag_name(), MMI_RP_MGR_TAG_MENUSET) != 0))
    {
        MMI_RP_ERROR(RP_ERR_TAG_USE_ERROR);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    g_mmi_rp_menu_cntx.current_default_id_flag = MMI_RP_MENU_CHILD_MENU_DEFAULT_FALSE;
    g_mmi_rp_menu_cntx.current_type_flag = MMI_RP_MENU_CHILD_MENU_TYPE_MENU;
    g_mmi_rp_menu_cntx.current_child_menu_check = MMI_TRUE;
    
    MMI_RP_DEBUG_INFO("Menuitem_id-start: %s\n", el);

    while ((NULL != attr[index]) && (NULL != attr[index + 1]))
    {
        MMI_RP_DEBUG_INFO("%s = %s\n", attr[index], attr[index + 1]);

        if(strcmp(attr[index], MMI_RP_MGR_ATTR_DEFAULT) == 0)
        {
            if(strcmp(attr[index+1], MMI_RP_MGR_VAL_TRUE) == 0)
            {
                /* Add code to store the default flag */
                g_mmi_rp_menu_cntx.current_default_id_flag = MMI_RP_MENU_CHILD_MENU_DEFAULT_TRUE;
            }
        }            
        else if(strcmp(attr[index], MMI_RP_MGR_ATTR_TYPE) == 0)
        {
            if(strcmp(attr[index+1], MMI_RP_MGR_VAL_SEPARATOR) == 0)
            {
                /* Add code for separator */
                g_mmi_rp_menu_cntx.current_type_flag = MMI_RP_MENU_CHILD_MENU_TYPE_SEPARATOR;
                mmi_rp_menu_add_menu_child(g_mmi_rp_menu_separator_str, MMI_FALSE);
                g_mmi_rp_menu_cntx.current_child_menu_check = MMI_FALSE;
                break;
            }
        }            
        else
        {
            /* Attrib not recognized. */
        }

        index += 2;
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  res_menuitem_id_end_handler
 * DESCRIPTION
 *  This function is for XML parser to return end tag information to application
 * PARAMETERS
 *  data        [IN]        Reserved
 *  el          [IN]        Element name
 *  error       [IN]        Error code
 * RETURNS
 *  void
 *****************************************************************************/
int mmi_rp_menuitem_id_end_handler(void *data, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_mmi_rp_menu_cntx.current_child_menu_check)
    {
        /* No menu id specified. Error Exit resgen. */
        MMI_RP_ERROR(RP_ERR_TAG_MENUITEM_ID_NOT_SPECIFIED);
        return MMI_RP_PARSE_ERROR_SKIP_TAG;
    }

    g_mmi_rp_menu_cntx.current_default_id_flag = MMI_RP_MENU_CHILD_MENU_DEFAULT_FALSE;
    g_mmi_rp_menu_cntx.current_type_flag = MMI_RP_MENU_CHILD_MENU_TYPE_MENU;
    g_mmi_rp_menu_cntx.current_child_menu_check = MMI_FALSE;
    
    MMI_RP_DEBUG_INFO("Menuitem_id-end: %s\n", el);
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  res_menuitem_id_data_handler
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
int mmi_rp_menuitem_id_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 parent_id = 0;
    U8 *temp = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_DEBUG_INFO("Menu-data: %s\n", data);

    MMI_RP_MENU_PARENT_STACK_TOP(parent_id);

    if(g_mmi_rp_menu_cntx.current_type_flag == MMI_RP_MENU_CHILD_MENU_TYPE_SEPARATOR)
    {
        g_mmi_rp_menu_cntx.current_child_menu_check = MMI_FALSE;
        MMI_RP_PARSE_WARNING(RP_WARN_USE_ERROR_SEPARATOR);
    }
    else
    {
        if(data == NULL)
        {
            /* No menu id specified. Error Exit resgen. */
            MMI_RP_ERROR(RP_ERR_TAG_MENUITEM_ID_NOT_SPECIFIED);
            return MMI_RP_PARSE_ERROR_SKIP_TAG;
        }

        g_mmi_rp_menu_cntx.current_child_menu_check = MMI_FALSE;

        if(parent_id)
        {
            if(strstr(data, MMI_RP_MENU_OLD_ID_TAG))
            {
                /* Add old ID as a child */
                temp = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)data);
                mmi_rp_menu_add_menu_child(temp, MMI_FALSE);
            }
            else
            {
                /* Add the menu ID */
                mmi_rp_menu_add_menu_child((U8*)data, MMI_TRUE);
            }
        
            if(g_mmi_rp_menu_cntx.current_default_id_flag)
            {
                /* Only add if no default menu has been specified earlier. Ignore if already a menu is specified as DEFAULT for CSK.*/
                /* Don't add Old menu ID. */
                if(!temp && (MMI_RP_MENU_CURR_APP_MENU.menus[parent_id - (MMI_RP_CURR_APP_BASE_ID + 1)].default_menu_id == NULL)) 
                {
                    MMI_RP_MENU_CURR_APP_MENU.menus[parent_id - (MMI_RP_CURR_APP_BASE_ID + 1)].default_menu_id = (U8*)mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, (U8*)data);    
                }
            }
        }

        /* Add the new menu id to menuset */
        if(!temp && (g_mmi_rp_menu_cntx.set_data.curr_set_index != -1))
        {
            /* Don't add Old menu ID. */
            mmi_rp_menu_add_menu_to_menuset((U8*)data);
        }
    }
    return MMI_RP_PARSE_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menu_add_menuitem
 * DESCRIPTION
 *  This function is for XML parser to return element content information to application
 * PARAMETERS
 *  temp          [IN]        temp pointer to menuitem string data for elements
 * RETURNS
 *  Success or failed
 *****************************************************************************/
MMI_BOOL mmi_rp_menu_add_menuitem(mmi_rp_menu_xmldata_struct temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = MMI_RP_MENU_CURR_APP_MENU.total_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Add the menuitem after checking if this is in range. */
    /* If out of range. Exit resgen. */
    if(count >= (U32)(g_mmi_rp_mgr_cntx.cur_app->max - g_mmi_rp_mgr_cntx.cur_app->min))
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_FALSE;
    }

    /* If string is not already in HASH. Check this with own str ptr cause this is added recently. */
    if(mmi_rp_hash_find(g_mmi_rp_menu_cntx.hash, temp.id_str) != NULL)
    {
        MMI_RP_PARSE_WARNING(RP_WARN_DUPLICATE_ID);
        return MMI_FALSE;
    }

    /* Adding the string ID into hash now. */
    temp.id_str = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash, temp.id_str);
    
    MMI_RP_MENU_CURR_APP_MENU.menus[count].id = count + (MMI_RP_CURR_APP_BASE_ID + 1);
    MMI_RP_MENU_CURR_APP_MENU.menus[count].xml_data = temp;
    MMI_RP_MENU_CURR_APP_MENU.total_count++;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menu_add_menu_child
 * DESCRIPTION
 *  This function is for XML parser to return element content information to application
 * PARAMETERS
 *  child_menu_id          [IN]        Child menu id for a parent menu id
 *  is_add_parent           [IN]        Add parent if it is a new Menu ID
 * RETURNS
 *  Success or failed
 *****************************************************************************/
MMI_BOOL mmi_rp_menu_add_menu_child(U8 *child_menu_id_str, MMI_BOOL is_add_parent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 curr_parent_id = 0;
    U32 child_count = 0;
    U32 i =0, child_menu_id = 0;
    U8* temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_RP_MENU_PARENT_STACK_TOP(curr_parent_id);

    if(!curr_parent_id )
    {
        return MMI_FALSE;
    }

    child_count = MMI_RP_MENU_CURR_APP_MENU.menus[curr_parent_id - (MMI_RP_CURR_APP_BASE_ID + 1)].child_count;
    if(child_count == MMI_RP_MENU_CHILDREN_MENU_SIZE)
    {
        /* Children menus count exceeded. Exit resgen. */
        MMI_RP_ERROR(RP_ERR_EXCEED_CHILDREN_MENU_SIZE);
        return MMI_FALSE;
    }

    /* If menu ID not yet populated, add in others. Because, while declaring, it'll search in the menu "hash". */
    if(mmi_rp_hash_find(g_mmi_rp_menu_cntx.hash, child_menu_id_str))
    {
        temp = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash, child_menu_id_str);
    }
    else
    {
        /* No new id found. The new menu ID has not populated yet. Or an old ID. */
        MMI_RP_PARSE_WARNING(RP_WARN_CHILD_MENU_ID_NOT_FOUND);
        temp = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, child_menu_id_str);
    }
    MMI_RP_MENU_CURR_APP_MENU.menus[curr_parent_id  - (MMI_RP_CURR_APP_BASE_ID + 1)].submenu[child_count] = temp;
    MMI_RP_MENU_CURR_APP_MENU.menus[curr_parent_id  - (MMI_RP_CURR_APP_BASE_ID + 1)].child_count++;

    if(is_add_parent)
    {
        for(i = 0; i < MMI_RP_MENU_CURR_APP_MENU.total_count; i++)
        {
            if(strcmp(MMI_RP_MENU_CURR_APP_MENU.menus[i].xml_data.id_str, child_menu_id_str) == 0)
            {
                child_menu_id = i;
                break;
            }
        }

        if(i >= MMI_RP_MENU_CURR_APP_MENU.total_count)
        {
            /* New menu ID not found. Not populated yet. */
            MMI_RP_PARSE_WARNING(RP_WARN_CHILD_MENU_ID_NOT_FOUND);
        }
        else if(MMI_RP_MENU_CURR_APP_MENU.menus[child_menu_id].parent_id == 0)  /* Add the parent, only if child_menu_id is found. */
        {
            MMI_RP_MENU_CURR_APP_MENU.menus[child_menu_id].parent_id = curr_parent_id;
        }
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menu_find_menu_id
 * DESCRIPTION
 *  Search numerical id for a menu id enum str
 * PARAMETERS
 *  temp          [IN]        temp pointer to menuitem string data for elements
 * RETURNS
 *  Numerical menu ID
 *****************************************************************************/
MMI_BOOL mmi_rp_menu_find_menu_id(U8* str_menu_id, U16* menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0;
    mmi_rp_menu_data_struct *curr_app_menu = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        curr_app_menu = &(g_mmi_rp_menu_cntx.app_menu_data[i]);

        for(j = 0; j < curr_app_menu->total_count; j++)
        {
            if(strcmp(str_menu_id, curr_app_menu->menus[j].xml_data.id_str) == 0)
            {
                if(curr_app_menu->menus[j].filter == MMI_TRUE)
                {
                    *menu_id = curr_app_menu->menus[j].id;
                    return MMI_TRUE;
                }
                else
                {
                    return MMI_FALSE;
                }
            }
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menu_add_menu_to_groups
 * DESCRIPTION
 *  This function is add a menu item to a group
 * PARAMETERS
 *  temp          [IN]        temp pointer to menuitem string data for elements
 * RETURNS
 *  Success or failed
 *****************************************************************************/
MMI_BOOL mmi_rp_menu_add_menu_to_groups(U8 *groups, U8 *menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 gcount = g_mmi_rp_menu_cntx.group_data.group_count;
    U8 *temp1 = NULL, *temp2 = NULL;
    U8 temp[MMI_RP_MENU_GROUP_ID_MAX];
    U32 len = 0, i = 0;
    MMI_BOOL process_next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(gcount >= MMI_RP_MENU_GROUP_ID_MAX)
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

        if(mmi_rp_hash_find(g_mmi_rp_menu_cntx.hash_others, temp))      /* Add in the existing group. */
        {
            for(i = 0; i < gcount; i++)
            {
                if(strcmp(g_mmi_rp_menu_cntx.group_data.groups[i].group_name, temp) == 0)
                {
                    if(g_mmi_rp_menu_cntx.group_data.groups[i].menu_count < MMI_RP_MENU_GROUP_MENU_MAX)
                    {
                        g_mmi_rp_menu_cntx.group_data.groups[i].menu_ids[g_mmi_rp_menu_cntx.group_data.groups[i].menu_count] = menu_id;
                        g_mmi_rp_menu_cntx.group_data.groups[i].menu_count++;
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
            if(gcount == MMI_RP_MENU_GROUP_ID_MAX - 1)
            {        
                MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
                return MMI_FALSE;
            }

            g_mmi_rp_menu_cntx.group_data.groups[gcount].group_name = mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, temp);
            g_mmi_rp_menu_cntx.group_data.groups[gcount].menu_ids[g_mmi_rp_menu_cntx.group_data.groups[gcount].menu_count] = menu_id;
            g_mmi_rp_menu_cntx.group_data.groups[gcount].menu_count++;
            g_mmi_rp_menu_cntx.group_data.group_count++;
            gcount = g_mmi_rp_menu_cntx.group_data.group_count;
        }
    }while(process_next == MMI_TRUE);
        
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menu_add_menu_to_menuset
 * DESCRIPTION
 *  This function is add a menu item to a mennuset
 * PARAMETERS
 *  menu_id          [IN]       MENUID
 * RETURNS
 *  Success or failed
 *****************************************************************************/
MMI_BOOL mmi_rp_menu_add_menu_to_menuset(U8 *menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 curr_count = g_mmi_rp_menu_cntx.set_data.total;
    U16 curr_menu_index = 0;
    S16 curr_set_index = g_mmi_rp_menu_cntx.set_data.curr_set_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(curr_count >= MMI_RP_MENU_SET_ID_MAX)
    {
        MMI_RP_ERROR(RP_ERR_EXCEED_ID_RANGE);
        return MMI_FALSE;
    }

    if((menu_id == NULL) || (curr_set_index == -1))
    {
        MMI_RP_PARSE_WARNING(RP_WARN_USE_ERROR_MENUSET);
        return MMI_FALSE;
    }

    curr_menu_index = g_mmi_rp_menu_cntx.set_data.sets[curr_set_index].menu_count;
    g_mmi_rp_menu_cntx.set_data.sets[curr_set_index].menu_ids[curr_menu_index] = (U8*)mmi_rp_hash_add(g_mmi_rp_menu_cntx.hash_others, menu_id);
    g_mmi_rp_menu_cntx.set_data.sets[curr_set_index].menu_count++;
        
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menu_filter_menuitem
 * DESCRIPTION
 *  remove not used menuitems
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_menu_filter_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0, k =0, app_c = 0, menu_c = 0;
    U8 *search_id = NULL;
    MMI_BOOL found = MMI_FALSE, pass = MMI_TRUE;
    mmi_rp_menu_data_struct *curr_search_app = NULL, *curr_cand_app = NULL;
    mmi_rp_menus_struct *curr_menu = NULL;
    U32 curr_valid_id;
    MMI_BOOL flag_id_reorder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Pass 1 - Filter-in all <menu> trees ~ Already done while processing <MENU> tags */

    /* Pass 2 - Filter-in all <MENU scope="XML"> trees which are children of <menu> trees ~ With pass 3 */

    /* Pass 3 - Filter-in all menu items which are children of filtered in <menu> trees */

    do
    {
        pass = MMI_FALSE;       /* to stop the re-iterative approach for filtering menu-items */
        for(app_c = 0; app_c < g_mmi_rp_mgr_cntx.total_apps; app_c++)
        {
            curr_search_app = &(g_mmi_rp_menu_cntx.app_menu_data[app_c]);

            for(menu_c =0; menu_c < curr_search_app->total_count; menu_c++)
            {
                /* Already filtered-in. So, skip it. */
                if(curr_search_app->menus[menu_c].filter == MMI_TRUE)
                {
                    continue;
                }

                search_id = curr_search_app->menus[menu_c].xml_data.id_str;
                found = MMI_FALSE;

                for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
                {
                    curr_cand_app = &(g_mmi_rp_menu_cntx.app_menu_data[i]);

                    for(j =0; j < curr_cand_app->total_count; j++)
                    {
                        curr_menu = &(curr_cand_app->menus[j]);

                        /* Don't check children of those menus which are not filtered-in. */
                        if(curr_menu->filter == MMI_FALSE)
                        {
                            continue;
                        }

                        /* searching and candidate ID is same */
                        if((i == app_c) && (j == menu_c))    
                        {
                            continue;
                        }

                        for(k = 0; k < curr_menu->child_count; k++)
                        {
                            /* Added for child menuIDs added later */
                            if(strcmp(search_id, curr_menu->submenu[k]) == 0)
                            {
                                found = MMI_TRUE;
                                pass = MMI_TRUE;        /* If any menu is filtered in a pass, the pass should continue. Else the process will exit. */
                                break;
                            }
                        }

                        if(found)
                        {
                            break;
                        }
                    }
                    if(found)
                    {
                        break;
                    }
                }
                curr_search_app->menus[menu_c].filter = found;
            }
        }
    }while(pass == MMI_TRUE);

    /* After all passes - Re-ordering the menu item ID. Setting 0xFFFF for all those menu IDs which are filtered-out. */
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        curr_search_app = &(g_mmi_rp_menu_cntx.app_menu_data[i]);

        curr_valid_id = g_mmi_resource_base_table[i].min + 1; /* Base ID + 1 */
        flag_id_reorder = MMI_FALSE;
        
        for(j = 0; j < curr_search_app->total_count; j++)
        {
            /* If menu ID is filtered out. Preserve its ID to be swapped with next filtered-in Menu ID. */
            if(curr_search_app->menus[j].filter == MMI_FALSE)
            {
                /* If a consecutive filtered-out menu ID is found. Don't reset the curr valid ID which will be used next. Just make this filtered-out Menu ID as 0xFFFF.*/
                if(!flag_id_reorder)
                {
                    curr_valid_id = curr_search_app->menus[j].id;
                }
                curr_search_app->menus[j].id = 0xFFFF;
                flag_id_reorder = MMI_TRUE;
            }

            /* First check - whether there's previously a filtered-out menu ID has been found. */
            /* Second check - whether current menu ID is a filtered-in menu ID, so that its menu ID can be re-ordered. */
            /* Order of checks ~ to fasten-up. */
            if(flag_id_reorder && (curr_search_app->menus[j].filter == MMI_TRUE))
            {
                curr_search_app->menus[j].id = curr_valid_id;
                curr_valid_id++;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  res_menu_output_phase1
 * DESCRIPTION
 *  Output ID
 * PARAMETERS
 *  str_output_phase1_filename  [IN]    output file name
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_menu_output_phase1(void)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    U8 *str_output_filename = NULL, *str_header_guard = NULL;
    U8 str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    U8 temp_group_name[MMI_RP_MENU_GROUP_ID_MAX];
    mmi_rp_menu_data_struct *curr_app_menu = NULL;
    U16 curr_menu_id = 0, curr_img_id = 0, main_menu_count;
    U8 *temp1 = NULL;

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

        if(p_file = fopen(str_output_filename, "w"))            /* Rest resources will open the file in append mode */
        {
            mmi_rp_write_copy_right_header_in_file(p_file);
            mmi_rp_write_file_header_in_file(
                p_file, 
                mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_H_FILE, g_mmi_resource_base_table[i].appname), 
                "Resource populate function generated by XML resgen", 
                "MTK resgenerator XML parser");
            mmi_rp_output_phase1_begin(p_file, str_header_guard);             /* Write Header guard. Will finish after all resources. */
            mmi_rp_menu_output_phase1_app_def_h_file(i, p_file);
            mmi_rp_mgr_output_all_defs(str_output_filename);
            fclose(p_file);
        }
        else
        {
            /* Error writing output file. Exit. */
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
        }
    }

    /* 2. Output customer\CustInc\mmi_rp_menu_misc_def.h file. */
    memset(str_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_filename, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    strcat(str_filename, "mmi_rp_menu_misc_def.h");

    if(p_file = fopen(str_filename, "w"))            /* Rest resources will open the file in append mode */
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
            p_file, 
            "mmi_rp_menu_misc_def.h", 
            "Resource populate function generated by XML resgen", 
            "MTK resgenerator XML parser");
        fprintf(p_file, "#ifndef _MMI_RP_MENU_MISC_DEF_H\n#define _MMI_RP_MENU_MISC_DEF_H\n");
        fprintf(p_file, "#include \"MMIDataType.h\"\n");
        fprintf(p_file, "#include \"CustMenuRes.h\"\n");

        /* 2.a Output Group Id enum & extern decl for Group ID array for all applications */
        /* 2.a.i Group ID enum  */
        fprintf(p_file, "\n");

        fprintf(p_file, "/* Menu Group ID enum */\n");

        fprintf(p_file, "typedef enum\n");
        fprintf(p_file, "{\n");
        for(i = 0; i < g_mmi_rp_menu_cntx.group_data.group_count; i++)
        {
            for(j = 0; j < strlen(g_mmi_rp_menu_cntx.group_data.groups[i].group_name); j++)
            {
                temp_group_name[j] = toupper(g_mmi_rp_menu_cntx.group_data.groups[i].group_name[j]);
            }
            temp_group_name[j] = '\0';

            fprintf(p_file, "   %s,\n", temp_group_name);     /*MMI_RG_ Perfixing with MMI_RP_ for distinct names. */
        }
        fprintf(p_file, "   MMI_RG_MENU_GROUP_ID_MAX,\n");
        fprintf(p_file, "}mmi_rg_menu_group_id_enum;\n");

        /* 2.a.ii extern decl of group ID array */
        fprintf(p_file, "\n");
        fprintf(p_file, "/* Extern declaration for arrays of menu IDs, which are associated with group IDs */\n");
        for(i = 0; i < g_mmi_rp_menu_cntx.group_data.group_count; i++)
        {
            for(j = 0; j < strlen(g_mmi_rp_menu_cntx.group_data.groups[i].group_name); j++)
            {
                temp_group_name[j] = tolower(g_mmi_rp_menu_cntx.group_data.groups[i].group_name[j]);
            }
            temp_group_name[j] = '\0';

            fprintf(p_file, "extern const U16 %s[];\n", temp_group_name);
        }

        /* 2.b Other externs. */
        fprintf(p_file, "\n\n/* Extern declaration for Menu group array associated with Group ID enum */\n");
        fprintf(p_file, "extern const U16* mmi_rg_menu_group[];\n\n");

        fprintf(p_file, "/* Extern declaration for default menu ID associated with parent menu IDs */\n");
        fprintf(p_file, "/* Pair of 'parent menu ID', 'default menu ID' */\n");
        fprintf(p_file, "extern const mmi_rg_menu_default_struct mmi_rg_menu_default_menu_array[];\n\n");

        /* 2.c Notify handlers externs. */
        fprintf(p_file, "\n\n/* Extern declaration for notify handlers */\n");
        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            curr_app_menu = &(g_mmi_rp_menu_cntx.app_menu_data[i]);

            for(j = 0; j < curr_app_menu->total_count; j++)
            {
                if((curr_app_menu->menus[j].filter == MMI_TRUE) && curr_app_menu->menus[j].xml_data.notify_str)
                {
                    fprintf(p_file, "extern void %s(void);\n", curr_app_menu->menus[j].xml_data.notify_str);
                }
            }
        }

        fprintf(p_file, "#endif /* _MMI_RP_MENU_MISC_DEF_H */\n");
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

    /* 3. Output customer\CustomerInc\mainmenu_launch.h file. */
    memset(str_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_filename, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    strcat(str_filename, "mmi_rp_mainmenu_launch.h");

    if(p_file = fopen(str_filename, "w"))
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
            p_file, 
            "mmi_rp_mainmenu_launch.h", 
            "Resource populate function generated by XML resgen", 
            "MTK resgenerator XML parser");
        fprintf(p_file, "#ifndef _MMI_RP_MAINMENU_LAUNCH_H\n#define _MMI_RP_MAINMENU_LAUNCH_H\n");
        fprintf(p_file, "#include \"MMIDataType.h\"");

        /* 3.a.i Output Include header files for Mainmenu IDs or image IDs */
        temp1 = g_mmi_rp_menu_cntx.main_menu_ids.header_files_str;

        fprintf(p_file, "\n/* Application specified header files for MainMenu/Image IDs declared elsewhere. */\n");
        /* If there's no header file, don't print it. */
        if(temp1 && (*temp1 != '\0'))
        {
            /* Ignoring initial spaces and commas */
            while(*temp1 && (*temp1 == ' ' || *temp1 == ','))
            {
                temp1++;
            }

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

    
        /* 3.a Output extern decl for launch functions */
        fprintf(p_file, "\n\n");
        fprintf(p_file, "/* Struct declaration. */\n");
        fprintf(p_file, "typedef struct{\n");
        fprintf(p_file, "    MMI_ID menu_id;\n");
        fprintf(p_file, "    MMI_ID image_id;\n");
        fprintf(p_file, "    FuncPtr lanuch_func;\n");
        fprintf(p_file, "}mmi_mainmenu_lanuch_struct;\n");

        /* 3.b. Output extern decl for launch functions */
        fprintf(p_file, "\n");

        if(g_mmi_rp_menu_cntx.main_menu_ids.main_menu_total == 0)
        {
            fprintf(p_file, "/* No launch functions are populated. */\n");
        }
        else
        {
            fprintf(p_file, "/* Extern declarations for launch functions. */\n");
        }

        main_menu_count = 0;
        
        for(i = 0; i < (U32)g_mmi_rp_menu_cntx.main_menu_ids.main_menu_total; i++)
        {
            //curr_menu_id = 0;
            if(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_launch_str &&
                g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_launch_str[0])
            {
                //if(mmi_rp_menu_find_menu_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].id_str, &curr_menu_id))
                {
                    fprintf(p_file, "extern void %s(void);\n", g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_launch_str);
                    main_menu_count++;
                }
            }
        }

        /* 3.c. Output array entries for 3D menu. */
        fprintf(p_file, "\n");
        fprintf(p_file, "/* Size of the array. */\n");
        fprintf(p_file, "static U16 mmi_mainmenu_launch_count = %d;\n", main_menu_count);
        fprintf(p_file, "\n");
        fprintf(p_file, "/* Main menu handler array. */\n");
        fprintf(p_file, "const mmi_mainmenu_lanuch_struct mmi_mainmenu_app_launch_table[] = \n");
        fprintf(p_file, "{\n");

        if((g_mmi_rp_menu_cntx.main_menu_ids.main_menu_total == 0) || (main_menu_count == 0))
        {
            fprintf(p_file, "    { 0, 0, 0}\n");
        }
        else
        {
            for(i = 0; i < (U32)g_mmi_rp_menu_cntx.main_menu_ids.main_menu_total; i++)
            {
                curr_menu_id = 0;
                curr_img_id = 0;
                if(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_launch_str &&
                    g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_launch_str[0])
                {
                    fprintf(p_file, "    /* Menu ID : %s */\n", g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].id_str);
                    fprintf(p_file, "    /* 3D Image ID : %s */\n", g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_3d_img_str[0] ? g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_3d_img_str : "0");
                    fprintf(p_file, "    {");

                    /* Menu ID - O/P either numeric or string enum ID */
                    temp1 = NULL;

                    temp1 = g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].id_str;

                    if(!temp1 || temp1[0] == '\0')
                    {
                        fprintf(p_file, "0, ");
                    }
                    else if(mmi_rp_menu_find_menu_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].id_str, &curr_menu_id))
                    {
                        fprintf(p_file, "%d, ", curr_menu_id);
                    }
                    else
                    {
                        fprintf(p_file, "%s, ", temp1);
                    }
                    
                    /* Image ID - O/P either numeric or string enum ID */
                    temp1 = NULL;
                    temp1 = g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_3d_img_str;

                    if(!temp1 || temp1[0] == '\0')
                    {
                        fprintf(p_file, "0, ");
                    }
                    else if(mmi_rp_img_find_img_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_3d_img_str, &curr_img_id))
                    {
                        fprintf(p_file, "%d, ", curr_img_id);
                    }
                    else
                    {
                        fprintf(p_file, "%s, ", temp1);
                    }
                    
                    fprintf(p_file, "%s},\n\n", g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_launch_str);
                }
            }
        }

        fprintf(p_file, "};\n");
        
        fprintf(p_file, "\n#endif /* _MMI_RP_MAINMENU_LAUNCH_H */\n");
        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }

    mmi_rp_menu_output_phase1_shortcut();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menu_output_phase1_app_def_h_file
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_menu_output_phase1_app_def_h_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0;
    U8 str_enum_name[MMI_RP_OUTPUT_ENUM_NAME_MAX], str_enum_max[MMI_RP_OUTPUT_ENUM_NAME_MAX];
    MMI_BOOL first = MMI_TRUE;
    mmi_rp_menu_data_struct *curr_app_menu = &(g_mmi_rp_menu_cntx.app_menu_data[app_index]);
    S32 app_enum_log_counter = -1;      /* -1 for debug purpose */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        memset(str_enum_name, 0, sizeof(str_enum_name));
        strcpy(str_enum_name, "mmi_rp_");
        strcat(str_enum_name, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_name, "_menu_enum");
        for(i = 0; i < strlen(str_enum_name); i++)
        {
            str_enum_name[i] = tolower(str_enum_name[i]);
        }

        memset(str_enum_max, 0, sizeof(str_enum_max));
        strcpy(str_enum_max, "MMI_RP_");
        strcat(str_enum_max, g_mmi_resource_base_table[app_index].appname);
        strcat(str_enum_max, "_MENU_MAX");
        for(i = 0; i < strlen(str_enum_max); i++)
        {
            str_enum_max[i] = toupper(str_enum_max[i]);
        }

        /* Check if no menu IDs. */
        if(curr_app_menu->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            fprintf(p_file, "\n\n");
            fprintf(p_file, "/******************** Menu resource IDs - begin ********************/\n");
            fprintf(p_file, "typedef enum\n{\n");

            for(i = 0; i < curr_app_menu->total_count; i++)
            {
                if(curr_app_menu->menus[i].filter == MMI_FALSE)
                {
                    continue;
                }

                if(first)
                {
                    fprintf(p_file, "    %s = %d + 1, /* BASE_ID + 1 */\n", curr_app_menu->menus[i].xml_data.id_str, g_mmi_resource_base_table[app_index].min);
                    first = MMI_FALSE;

                    app_enum_log_counter = g_mmi_resource_base_table[app_index].min + 1;
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_menu->menus[i].xml_data.id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
                else
                {
                    fprintf(p_file, "    %s,\n", curr_app_menu->menus[i].xml_data.id_str);
                    MMI_RP_OUTPUT_ENUM_LOG(curr_app_menu->menus[i].xml_data.id_str, app_enum_log_counter);
                    app_enum_log_counter++;
                }
            }

            fprintf(p_file, "    %s\n", str_enum_max);
            fprintf(p_file, "}%s;\n", str_enum_name);
            fprintf(p_file, "/******************** Menu resource IDs - finish ********************/\n");
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
 *  mmi_rp_menu_output_phase1_shortcut
 * DESCRIPTION
 *  Output ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_menu_output_phase1_shortcut(void)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U8 str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    mmi_rp_menu_data_struct *curr_app_menu = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_filename, MMI_RP_MGR_XML_TEMP_CMP_H_FILES);
    strcat(str_filename, "mmi_rp_menu_shortcut_def.h");

    if(p_file = fopen(str_filename, "w"))            /* Rest resources will open the file in append mode */
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(
            p_file, 
            "mmi_rp_menu_shortcut_def.h", 
            "Resource populate function generated by XML resgen", 
            "MTK resgenerator XML parser");
        fprintf(p_file, "#ifndef _MMI_RP_MENU_SHORTCUT_DEF_H\n#define _MMI_RP_MENU_SHORTCUT_DEF_H\n");
        fprintf(p_file, "\n#include \"MMIDataType.h\"\n");

        /* Menu shortcut related data. */
        fprintf(p_file, "\n\n/* Menu shortcuts related data */\n");
        fprintf(p_file, "typedef struct {\n");
        fprintf(p_file, "    MMI_ID menu_id;\n");
        fprintf(p_file, "    MMI_STR_ID str_id;\n");
        fprintf(p_file, "    MMI_IMG_ID img_id;\n");
        fprintf(p_file, "    FuncPtr launch_func;\n");
        fprintf(p_file, "}mmi_shct_candidate_menu_info_struct;\n");

        fprintf(p_file, "\n/* Extern declaration for the shortcut array */\n");
        fprintf(p_file, "extern const mmi_shct_candidate_menu_info_struct mmi_shct_candidate_menu[];\n\n");

        fprintf(p_file, "extern U32 mmi_shct_get_candidate_menu_list_num(void);\n\n");
        
        fprintf(p_file, "#endif /* _MMI_RP_MENU_SHORTCUT_DEF_H */\n");
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
 *  res_menu_output_phase2
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_menu_output_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    U8 *str_output_filename = NULL, *str_output_filename_header = NULL, *str_function_name = NULL;
    U8 str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    mmi_rp_menu_data_struct *curr_app_menu = NULL;
    U8 temp_group_name[MMI_RP_MENU_GROUP_ID_MAX];
    MMI_BOOL temp_op = MMI_FALSE;
    U16 curr_default_menu_id = 0, curr_menu_id = 0, curr_img_id = 0;
    MMI_BOOL need_comma;
    U16 menu_id = 0;
    U8 *temp1 = NULL, *temp2 = NULL, *temp_str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. Output all APPs .c files. */
#ifndef __RESGEN_INTERNAL_POP_FILE_REDUCE__
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        {
            continue;
        }

        /* dotC file name */
        str_output_filename = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_C_FILE_PATH, g_mmi_resource_base_table[i].appname);
        /* Header file name*/
        str_output_filename_header = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_H_FILE, g_mmi_resource_base_table[i].appname);
        /* Populate function name */
        str_function_name = mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_POPULATE_FUNCTION, g_mmi_resource_base_table[i].appname);

        if(p_file = fopen(str_output_filename, "w"))            /* Rest resources will open the file in append mode */
        {
            mmi_rp_write_copy_right_header_in_file(p_file);
            mmi_rp_write_file_header_in_file(
                p_file, 
                mmi_rp_mgr_contruct_name(MMI_RP_OUTPUT_NAME_C_FILE, g_mmi_resource_base_table[i].appname), 
                "Resource populate function generated by XML resgen", 
                "MTK resgenerator XML parser");
            mmi_rp_output_phase2_begin(p_file, str_function_name, str_output_filename_header, g_mmi_rp_mgr_cntx.app_include[i]);             /* Will finish in the last resource output phase 2 */
            mmi_rp_menu_output_phase2_app_c_file(i, p_file);
            fclose(p_file);
            mmi_rp_mgr_output_populate_func(str_function_name);         /* Writes the function call in mmi_rp_populate.c */
        }
        else
        {
            /* Error writing output file. Exit. */
            MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
        }
        
    }
#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__
    
    for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
    {
        if(g_mmi_rp_mgr_cntx.app_populated[i] == MMI_FALSE)
        {
            continue;
    }

        mmi_rp_menu_output_phase2_app_c_file(i);
        
    }
#endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__

    /* 2. Output all customer\CustResource\mmi_rp_menu_misc_data.c file. */
    memset(str_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_filename, MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES);
    strcat(str_filename, "mmi_rp_menu_misc_data.c");

    if(p_file = fopen(str_filename, "w"))           
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(p_file, "mmi_rp_menu_misc_data.c", "Resource populate function generated by XML resgen", "MTK resgenerator XML parser");
        fprintf(p_file, "#include \"MMIDataType.h\"\n");
        fprintf(p_file, "#include \"CustMenuRes.h\"\n");
        fprintf(p_file, "#include \"mmi_rp_menu_misc_def.h\"\n");

        
        /* 2.a.i Output Include header files for Mainmenu IDs or image IDs */
        temp1 = g_mmi_rp_menu_cntx.main_menu_ids.header_files_str;

        fprintf(p_file, "\n/* Application specified header files for MainMenu/Image IDs declared elsewhere. */\n");
        /* If there's no header file, don't print it. */
        if(temp1 && (*temp1 != '\0'))
        {
            /* Ignoring initial spaces and commas */
            while(*temp1 && (*temp1 == ' ' || *temp1 == ','))
            {
                temp1++;
            }

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
        
        /* 2.a.ii Output mmi_rg_menu_mainmenu_img_id_array[]  */
        fprintf(p_file, "\n");
        fprintf(p_file, "/* Count of all main menu IDs */\n");
        fprintf(p_file, "const U32 mmi_rg_menu_mainmenuid_total = %d;\n", g_mmi_rp_menu_cntx.main_menu_ids.main_menu_total);

        fprintf(p_file, "\n");
        fprintf(p_file, "/* Array of Image IDs for main menu IDs */\n");
        fprintf(p_file, "/* 1) Main menu ID */\n");
        fprintf(p_file, "/* 2) List image ID */\n");
        fprintf(p_file, "/* 3) Matrix image ID */\n");
        fprintf(p_file, "/* 4) Page image ID */\n");
        fprintf(p_file, "/* 5) Venus1 image ID */\n");
        fprintf(p_file, "/* 6) Venus2 image ID */\n");
        fprintf(p_file, "/* 7) Matrix highlight image ID */\n");
        fprintf(p_file, "/* 8) Matrix controlled area image ID */\n");
        fprintf(p_file, "/* 9) Venus1 highlight image ID */\n");
        fprintf(p_file, "/* 10) Title image ID */\n");
        fprintf(p_file, "const mmi_rg_menu_mainmenu_img_id_struct mmi_rg_menu_mainmenu_img_id_array[] = {\n");

        /* The following code is to avoid compile error if there's no Main menu ID specified. */
        if(g_mmi_rp_menu_cntx.main_menu_ids.main_menu_total == 0)
        {
            fprintf(p_file, "    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }\n");
        }

        for(i = 0; i < (U32)g_mmi_rp_menu_cntx.main_menu_ids.main_menu_total; i++)
        {
            /* 1) Main menu ID */
            temp_str = NULL;
            temp_str = g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].id_str;

            if(!temp_str || temp_str[0] == '\0')
            {
                continue;       /* Can't associate image IDs with NULL menu ID. */
            }
            else if(mmi_rp_menu_find_menu_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].id_str, &curr_menu_id))
            {
                fprintf(p_file, "    { %d, ", curr_menu_id);
            }
            else
            {
                fprintf(p_file, "    { %s, ", temp_str);
            }

            /* 2) List image ID */
            temp_str = NULL;
            temp_str = g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_list_img_str;
            if(!temp_str || temp_str[0] == '\0')
            {
                fprintf(p_file, "0, ");
            }
            else if(mmi_rp_img_find_img_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_list_img_str, &curr_img_id))
            {
                fprintf(p_file, "%d, ", curr_img_id);
            }
            else
            {
                fprintf(p_file, "%s, ", temp_str);
            }

            /* 3) Matrix image ID */
            temp_str = NULL;
            temp_str = g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_matrix_img_str;
            if(!temp_str || temp_str[0] == '\0')
            {
                fprintf(p_file, "0, ");
            }
            else if(mmi_rp_img_find_img_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_matrix_img_str, &curr_img_id))
            {
                fprintf(p_file, "%d, ", curr_img_id);
            }
            else
            {
                fprintf(p_file, "%s, ", temp_str);
            }

            /* 4) Page image ID */
            temp_str = NULL;
            temp_str = g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_page_img_str;
            if(!temp_str || temp_str[0] == '\0')
            {
                fprintf(p_file, "0, ");
            }
            else if(mmi_rp_img_find_img_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_page_img_str, &curr_img_id))
            {
                fprintf(p_file, "%d, ", curr_img_id);
            }
            else
            {
                fprintf(p_file, "%s, ", temp_str);
            }

            /* 5) Venus1 image ID */
            temp_str = NULL;
            temp_str = g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_venus1_img_str;
            if(!temp_str || temp_str[0] == '\0')
            {
                fprintf(p_file, "0, ");
            }
            else if(mmi_rp_img_find_img_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_venus1_img_str, &curr_img_id))
            {
                fprintf(p_file, "%d, ", curr_img_id);
            }
            else
            {
                fprintf(p_file, "%s, ", temp_str);
            }

            /* 6) Venus2 image ID */
            temp_str = NULL;
            temp_str = g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_venus2_img_str;
            if(!temp_str || temp_str[0] == '\0')
            {
                fprintf(p_file, "0, ");
            }
            else if(mmi_rp_img_find_img_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_venus2_img_str, &curr_img_id))
            {
                fprintf(p_file, "%d, ", curr_img_id);
            }
            else
            {
                fprintf(p_file, "%s, ", temp_str);
            }

            /* 7) Matrix highlight image ID */
            temp_str = NULL;
            temp_str = g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_matrix_highlight_img_str;
            if(!temp_str || temp_str[0] == '\0')
            {
                fprintf(p_file, "0, ");
            }
            else if(mmi_rp_img_find_img_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_matrix_highlight_img_str, &curr_img_id))
            {
                fprintf(p_file, "%d, ", curr_img_id);
            }
            else
            {
                fprintf(p_file, "%s, ", temp_str);
            }

            /* 8) Matrix controlled area image ID */
            temp_str = NULL;
            temp_str = g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_matrix_controlled_area_img_str;
            if(!temp_str || temp_str[0] == '\0')
            {
                fprintf(p_file, "0, ");
            }
            else if(mmi_rp_img_find_img_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_matrix_controlled_area_img_str, &curr_img_id))
            {
                fprintf(p_file, "%d, ", curr_img_id);
            }
            else
            {
                fprintf(p_file, "%s, ", temp_str);
            }

            /* 9) Venus1 highlight image ID */
            temp_str = NULL;
            temp_str = g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_venus1_highlight_img_str;
            if(!temp_str || temp_str[0] == '\0')
            {
                fprintf(p_file, "0, ");
            }
            else if(mmi_rp_img_find_img_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_venus1_highlight_img_str, &curr_img_id))
            {
                fprintf(p_file, "%d, ", curr_img_id);
            }
            else
            {
                fprintf(p_file, "%s, ", temp_str);
            }

            /* 10) Title image ID */
            temp_str = NULL;
            temp_str = g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_title_img_str;
            if(!temp_str || temp_str[0] == '\0')
            {
                fprintf(p_file, "0},\n");
            }
            else if(mmi_rp_img_find_img_id(g_mmi_rp_menu_cntx.main_menu_ids.mainmenu_data[i].mm_title_img_str, &curr_img_id))
            {
                fprintf(p_file, "%d},\n", curr_img_id);
            }
            else
            {
                fprintf(p_file, "%s},\n", temp_str);
            }
        }
        fprintf(p_file, "};\n");
        
        /* 2.b Output mmi_rg_menu_default_menu_array[]  */
        fprintf(p_file, "\n");
        fprintf(p_file, "/* Default menu ID associated parent with menu IDs */\n");
        fprintf(p_file, "/* Pair of 'parent menu ID', 'default menu ID' */\n");
        fprintf(p_file, "const mmi_rg_menu_default_struct mmi_rg_menu_default_menu_array[] = {\n");

        temp_op = MMI_TRUE;
        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            curr_app_menu = &(g_mmi_rp_menu_cntx.app_menu_data[i]);

            for(j = 0; j < curr_app_menu->total_count; j++)
            {
                if((curr_app_menu->menus[j].filter == MMI_TRUE) && curr_app_menu->menus[j].default_menu_id)
                {
                    if(!mmi_rp_menu_find_menu_id(curr_app_menu->menus[j].default_menu_id, &curr_default_menu_id))
                    {
                        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
                    }
                    fprintf(p_file, "    {%d, %d},\n", curr_app_menu->menus[j].id, curr_default_menu_id);
                    temp_op = MMI_FALSE;
                }
            }
        }
        if(temp_op)
        {        
            fprintf(p_file, "   {NULL, NULL}\n");
        }      
        fprintf(p_file, "};\n");

        /* 2.c Output Group ID array for all applications and mmi_rg_menu_group[] array */
        /* 2.c.i All applications array */
        fprintf(p_file, "\n");

        fprintf(p_file, "/* Arrays of menu IDs for Group IDs */\n");
        for(i = 0; i < g_mmi_rp_menu_cntx.group_data.group_count; i++)
        {
            for(j = 0; j < strlen(g_mmi_rp_menu_cntx.group_data.groups[i].group_name); j++)
            {
                temp_group_name[j] = tolower(g_mmi_rp_menu_cntx.group_data.groups[i].group_name[j]);
            }
            temp_group_name[j] = '\0';

            if(g_mmi_rp_menu_cntx.group_data.groups[i].menu_count > 0)
            {
                fprintf(p_file, "const U16 %s[] = {", temp_group_name);
                need_comma = MMI_FALSE;

                for(j = 0; j < g_mmi_rp_menu_cntx.group_data.groups[i].menu_count; j++)
                {
                    if(mmi_rp_menu_find_menu_id(g_mmi_rp_menu_cntx.group_data.groups[i].menu_ids[j], &menu_id))
                    {
                        if(need_comma)
                        {
                            fprintf(p_file, ", %d", menu_id);
                        }
                        else
                        {
                            fprintf(p_file, "%d", menu_id);
                        }
                        need_comma = MMI_TRUE;
                    }
                }
                if(!need_comma)
                {
                    fprintf(p_file, " 0xFFFF ");
                }
                else
                {
                    fprintf(p_file, ", 0xFFFF");
                }
                fprintf(p_file, "};\n");
            }
        }

        /* 2.c.ii mmi_rg_menu_group[] array */
        fprintf(p_file, "\n/* Menu group array associated with Group ID enum */\n");
        fprintf(p_file, "const U16 *mmi_rg_menu_group[] = {\n");

        for(i = 0; i < g_mmi_rp_menu_cntx.group_data.group_count; i++)
        {
            for(j = 0; j < strlen(g_mmi_rp_menu_cntx.group_data.groups[i].group_name); j++)
            {
                temp_group_name[j] = tolower(g_mmi_rp_menu_cntx.group_data.groups[i].group_name[j]);
            }
            temp_group_name[j] = '\0';

            fprintf(p_file, "    %s,\n", temp_group_name);
        }
        fprintf(p_file, "    NULL\n");
        fprintf(p_file, "};\n");

        /* 2.d Output mmi_frm_const_notify_handler_table[]  */
        fprintf(p_file, "\n");
        fprintf(p_file, "/* Application's notify handlers */\n");
        fprintf(p_file, "const mmi_rg_notify_hdlr_struct mmi_frm_const_notify_handler_table[] = {\n");

        temp_op = MMI_TRUE;
        for(i = 0; i < g_mmi_rp_mgr_cntx.total_apps; i++)
        {
            curr_app_menu = &(g_mmi_rp_menu_cntx.app_menu_data[i]);

            for(j = 0; j < curr_app_menu->total_count; j++)
            {
                if((curr_app_menu->menus[j].filter == MMI_TRUE) && curr_app_menu->menus[j].xml_data.notify_str)
                {
                    fprintf(p_file, "   {%d, %s}\n", curr_app_menu->menus[j].id, curr_app_menu->menus[j].xml_data.notify_str);
                    temp_op = MMI_FALSE;
                }
            }
        }
        if(temp_op)
        {        
            fprintf(p_file, "   {0, NULL}\n");
        }      
        fprintf(p_file, "};\n");

        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
    mmi_rp_menu_output_phase2_shortcut();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menu_output_phase2_app_c_files
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  app_index      [IN]    App_index in resource base table
 *  p_file      [IN]    File pointer to output file
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __RESGEN_INTERNAL_POP_FILE_REDUCE__ 
void mmi_rp_menu_output_phase2_app_c_file(U32 app_index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    FILE *p_file = NULL;
    U32 i =0, j = 0, child_c = 0;
    U16 temp = 0;
    mmi_rp_menu_data_struct *curr_app_menu = &(g_mmi_rp_menu_cntx.app_menu_data[app_index]);
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        /* Check if no menu IDs. */
        if(curr_app_menu->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            printf("curr_app_menu->total_count = %d\n", curr_app_menu->total_count );
            p_file = mmi_rp_open_population_c_file(app_index, RES_LEGACY_POP_MENU_MASK);
            
            if(p_file== NULL)            /* Rest resources will open the file in append mode */
            {
                 MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
            }


            fprintf(p_file, "\n");
            fprintf(p_file, "/******************** Menu resource IDs - begin ********************/\n");

            /* 1. Add menu items */
            for(i = 0; i < curr_app_menu->total_count; i++)
            {
                if(curr_app_menu->menus[i].filter == MMI_TRUE)
                {
                    fprintf(p_file, "    ADD_APPLICATION_MENUITEM5((\n");

                    /* Menu id */
                    fprintf(p_file, "        %s,\n", curr_app_menu->menus[i].xml_data.id_str);       

                    /* Parent menu id */
                    if(curr_app_menu->menus[i].xml_data.parent_id_str)
                    {
                        fprintf(p_file, "        %s,\n", curr_app_menu->menus[i].xml_data.parent_id_str);
                    }
                    else
                    {
                        fprintf(p_file, "        %s,\n", 
                            curr_app_menu->menus[i].parent_id ? 
                            (const S8*)(curr_app_menu->menus[curr_app_menu->menus[i].parent_id - (g_mmi_resource_base_table[app_index].min + 1)].xml_data.id_str) : 
                            "0");       
                    }

                    /* Children menu ID count. Calculating how many of them are discarded. */
                    child_c = 0;
                    for(j = 0; j < curr_app_menu->menus[i].child_count; j++)
                    {
                        if(strstr(curr_app_menu->menus[i].submenu[j], MMI_RP_MENU_OLD_ID_TAG))
                        {
                            child_c++;
                        }
                        else if(mmi_rp_menu_find_menu_id(curr_app_menu->menus[i].submenu[j], &temp))
                        {
                            child_c++;
                        }
                    }
                    fprintf(p_file, "        %d,\n", child_c);

                    /* Sub menu ids */
                    for(j = 0; j < curr_app_menu->menus[i].child_count; j++)
                    {
                        if(strstr(curr_app_menu->menus[i].submenu[j], MMI_RP_MENU_OLD_ID_TAG))
                        {
                            fprintf(p_file, "        %s,\n", curr_app_menu->menus[i].submenu[j] + MMI_RP_MENU_OLD_ID_TAG_LEN);       
                        }
                        else if(mmi_rp_menu_find_menu_id(curr_app_menu->menus[i].submenu[j], &temp))
                        {
                            fprintf(p_file, "        %s,\n", curr_app_menu->menus[i].submenu[j]);       
                        }
                    }

                    /* Old flag for SHOW/HIDE */
                    fprintf(p_file, "        %s,\n", "SHOW");

                    /* Flag radio/checkbox (Old nMoveable attrib) */
                    fprintf(p_file, "        %s,\n", g_mmi_rp_menu_output_flag_enum_str[curr_app_menu->menus[i].flag]);

                    /* Type of menu (Old nDisplay attrib) */
                    fprintf(p_file, "        %s,\n", g_mmi_rp_menu_output_type_enum_str[curr_app_menu->menus[i].type]);

                    /* String ID */
                    fprintf(p_file, "        %s,\n", (curr_app_menu->menus[i].xml_data.str_id_str ? (const S8*)curr_app_menu->menus[i].xml_data.str_id_str : "0"));

                    /* Image ID */
                    fprintf(p_file, "        %s));\n", (curr_app_menu->menus[i].xml_data.img_id_str ? (const S8*)curr_app_menu->menus[i].xml_data.img_id_str : "0"));
                    fprintf(p_file, "\n");
                }
            }
            
            fprintf(p_file, "/******************** Menu resource IDs - finish ********************/\n");

            fprintf(p_file, "\n");

            /* 2. Add highlight handlers and hint handlers */
            /* Use ADD_APPLICATION_MENUITEM_HILITE_HANDLER and ADD_APPLICATION_MENUITEM_HINT_HANDLER */
            fprintf(p_file, "/******************** Menu Hilite/Hint Handlers - begin ********************/\n");
            
            for(i = 0; i < curr_app_menu->total_count; i++)
            {
                if(curr_app_menu->menus[i].filter == MMI_TRUE)
                {
                    if(curr_app_menu->menus[i].xml_data.highlight_str && curr_app_menu->menus[i].xml_data.highlight_str[0] != '\0')
                    {
                        fprintf(p_file, "    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(");
                        fprintf(p_file, "%s, ", curr_app_menu->menus[i].xml_data.id_str);
                        fprintf(p_file, "%s", curr_app_menu->menus[i].xml_data.highlight_str);
                        fprintf(p_file, ");\n");
                    }

                    if(curr_app_menu->menus[i].xml_data.hint_str && curr_app_menu->menus[i].xml_data.hint_str[0] != '\0')
                    {
                        fprintf(p_file, "    ADD_APPLICATION_MENUITEM_HINT_HANDLER(");
                        fprintf(p_file, "%s, ", curr_app_menu->menus[i].xml_data.id_str);
                        fprintf(p_file, "%s", curr_app_menu->menus[i].xml_data.hint_str);
                        fprintf(p_file, ");\n");
                    }
                }
            }
            
            fprintf(p_file, "/******************** Menu Hilite/Hint Handlers - finish ********************/\n");
            fclose(p_file);

        }
}

#else //__RESGEN_INTERNAL_POP_FILE_REDUCE__

void mmi_rp_menu_output_phase2_app_c_file(U32 app_index, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i =0, j = 0, child_c = 0;
    U16 temp = 0;
    mmi_rp_menu_data_struct *curr_app_menu = &(g_mmi_rp_menu_cntx.app_menu_data[app_index]);
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_file)
    {
        /* Check if no menu IDs. */
        if(curr_app_menu->total_count <= 0)
        {
            MMI_RP_PARSE_WARNING(RP_WARN_RES_COUNT_ZERO);
        }
        else
        {
            fprintf(p_file, "\n");
            fprintf(p_file, "/******************** Menu resource IDs - begin ********************/\n");

            /* 1. Add menu items */
            for(i = 0; i < curr_app_menu->total_count; i++)
            {
                if(curr_app_menu->menus[i].filter == MMI_TRUE)
                {
                    fprintf(p_file, "    ADD_APPLICATION_MENUITEM5((\n");

                    /* Menu id */
                    fprintf(p_file, "        %s,\n", curr_app_menu->menus[i].xml_data.id_str);       

                    /* Parent menu id */
                    if(curr_app_menu->menus[i].xml_data.parent_id_str)
                    {
                        fprintf(p_file, "        %s,\n", curr_app_menu->menus[i].xml_data.parent_id_str);
                    }
                    else
                    {
                        fprintf(p_file, "        %s,\n", 
                            curr_app_menu->menus[i].parent_id ? 
                            (const S8*)(curr_app_menu->menus[curr_app_menu->menus[i].parent_id - (g_mmi_resource_base_table[app_index].min + 1)].xml_data.id_str) : 
                            "0");       
                    }

                    /* Children menu ID count. Calculating how many of them are discarded. */
                    child_c = 0;
                    for(j = 0; j < curr_app_menu->menus[i].child_count; j++)
                    {
                        if(strstr(curr_app_menu->menus[i].submenu[j], MMI_RP_MENU_OLD_ID_TAG))
                        {
                            child_c++;
                        }
                        else if(mmi_rp_menu_find_menu_id(curr_app_menu->menus[i].submenu[j], &temp))
                        {
                            child_c++;
                        }
                    }
                    fprintf(p_file, "        %d,\n", child_c);

                    /* Sub menu ids */
                    for(j = 0; j < curr_app_menu->menus[i].child_count; j++)
                    {
                        if(strstr(curr_app_menu->menus[i].submenu[j], MMI_RP_MENU_OLD_ID_TAG))
                        {
                            fprintf(p_file, "        %s,\n", curr_app_menu->menus[i].submenu[j] + MMI_RP_MENU_OLD_ID_TAG_LEN);       
                        }
                        else if(mmi_rp_menu_find_menu_id(curr_app_menu->menus[i].submenu[j], &temp))
                        {
                            fprintf(p_file, "        %s,\n", curr_app_menu->menus[i].submenu[j]);       
                        }
                    }

                    /* Old flag for SHOW/HIDE */
                    fprintf(p_file, "        %s,\n", "SHOW");

                    /* Flag radio/checkbox (Old nMoveable attrib) */
                    fprintf(p_file, "        %s,\n", g_mmi_rp_menu_output_flag_enum_str[curr_app_menu->menus[i].flag]);

                    /* Type of menu (Old nDisplay attrib) */
                    fprintf(p_file, "        %s,\n", g_mmi_rp_menu_output_type_enum_str[curr_app_menu->menus[i].type]);

                    /* String ID */
                    fprintf(p_file, "        %s,\n", (curr_app_menu->menus[i].xml_data.str_id_str ? (const S8*)curr_app_menu->menus[i].xml_data.str_id_str : "0"));

                    /* Image ID */
                    fprintf(p_file, "        %s));\n", (curr_app_menu->menus[i].xml_data.img_id_str ? (const S8*)curr_app_menu->menus[i].xml_data.img_id_str : "0"));
                    fprintf(p_file, "\n");
                }
            }
            fprintf(p_file, "/******************** Menu resource IDs - finish ********************/\n");

            fprintf(p_file, "\n");

            /* 2. Add highlight handlers and hint handlers */
            /* Use ADD_APPLICATION_MENUITEM_HILITE_HANDLER and ADD_APPLICATION_MENUITEM_HINT_HANDLER */
            fprintf(p_file, "/******************** Menu Hilite/Hint Handlers - begin ********************/\n");
            for(i = 0; i < curr_app_menu->total_count; i++)
            {
                if(curr_app_menu->menus[i].filter == MMI_TRUE)
                {
                    if(curr_app_menu->menus[i].xml_data.highlight_str && curr_app_menu->menus[i].xml_data.highlight_str[0] != '\0')
                    {
                        fprintf(p_file, "    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(");
                        fprintf(p_file, "%s, ", curr_app_menu->menus[i].xml_data.id_str);
                        fprintf(p_file, "%s", curr_app_menu->menus[i].xml_data.highlight_str);
                        fprintf(p_file, ");\n");
                    }

                    if(curr_app_menu->menus[i].xml_data.hint_str && curr_app_menu->menus[i].xml_data.hint_str[0] != '\0')
                    {
                        fprintf(p_file, "    ADD_APPLICATION_MENUITEM_HINT_HANDLER(");
                        fprintf(p_file, "%s, ", curr_app_menu->menus[i].xml_data.id_str);
                        fprintf(p_file, "%s", curr_app_menu->menus[i].xml_data.hint_str);
                        fprintf(p_file, ");\n");
                    }
                }
            }
            fprintf(p_file, "/******************** Menu Hilite/Hint Handlers - finish ********************/\n");
        }
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}

#endif //__RESGEN_INTERNAL_POP_FILE_REDUCE__
/*****************************************************************************
 * FUNCTION
 *  mmi_rp_menu_output_phase2_shortcut
 * DESCRIPTION
 *  Output Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_menu_output_phase2_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *p_file = NULL;
    U32 i =0, j = 0;
    U8 str_filename[MMI_RP_MGR_MAX_FILE_NAME_LEN];
    U16 curr_img_id = 0;
    U8 *temp_shortcut_str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_filename, 0, MMI_RP_MGR_MAX_FILE_NAME_LEN);
    strcpy(str_filename, MMI_RP_MGR_XML_TEMP_CMP_CUSTRESOURCE_C_FILES);
    strcat(str_filename, "mmi_rp_menu_shortcut_data.c");

    if(p_file = fopen(str_filename, "w"))           
    {
        mmi_rp_write_copy_right_header_in_file(p_file);
        mmi_rp_write_file_header_in_file(p_file, "mmi_rp_menu_shortcut_data.c", "Resource populate function generated by XML resgen", "MTK resgenerator XML parser");
        fprintf(p_file, "#include \"MMIDataType.h\"\n");
        fprintf(p_file, "#include \"mmi_rp_menu_shortcut_def.h\"\n");
        fprintf(p_file, "#include \"GlobalResDef.h\"\n");
        fprintf(p_file, "#include \"mmi_rp_all_defs.h\"\n");

        /* Output Shortcut array[] */
        fprintf(p_file, "\n\n/* Extern declarations for Shortcut launch functions*/\n");
        for(i = 0; i < g_mmi_rp_menu_cntx.shortcut.total; i++)
        {
            fprintf(p_file, "extern void %s(void);\n", g_mmi_rp_menu_cntx.shortcut.shortcuts_data[i].launch_func);
        }

        fprintf(p_file, "\n\n/* Shortcut app array associated with menu IDs */\n");
        fprintf(p_file, "const mmi_shct_candidate_menu_info_struct mmi_shct_candidate_menu[] =\n");
        fprintf(p_file, "{\n");

        if(g_mmi_rp_menu_cntx.shortcut.total == 0)
        {
            fprintf(p_file, "    {0, 0, 0, 0}\n");
        }

        for(i = 0; i < g_mmi_rp_menu_cntx.shortcut.total; i++)
        {
            curr_img_id = 0;
            if((g_mmi_rp_menu_cntx.shortcut.shortcuts_data[i].img_id != 0) &&
                (g_mmi_rp_menu_cntx.shortcut.shortcuts_data[i].img_id[0] != 0))
            {
                mmi_rp_img_find_img_id(g_mmi_rp_menu_cntx.shortcut.shortcuts_data[i].img_id, &curr_img_id);
                /* If specified Shortcut image ID is not in a .res file, Raise an error. */
                /* MMI_RP_GENERIC_ERROR_DATA(RP_ERR_MENU_SHORTCUT_IMAGE_ID_NOT_FOUND, g_mmi_rp_menu_cntx.shortcut.shortcuts_data[i].img_id); */
            }

            temp_shortcut_str = NULL;
            temp_shortcut_str = g_mmi_rp_menu_cntx.shortcut.shortcuts_data[i].shortcut_str_id;
            if(!temp_shortcut_str || !(*temp_shortcut_str))
            {
                temp_shortcut_str = g_mmi_rp_menu_cntx.shortcut.shortcuts_data[i].str_id;
            }
            if(!temp_shortcut_str || !(*temp_shortcut_str))
            {
                temp_shortcut_str = "0";
            }

            
            fprintf(p_file, "    {%s, %s, %s, %s},\n", 
                g_mmi_rp_menu_cntx.shortcut.shortcuts_data[i].menu_id,
                temp_shortcut_str,
                curr_img_id ? g_mmi_rp_menu_cntx.shortcut.shortcuts_data[i].img_id : "0",
                g_mmi_rp_menu_cntx.shortcut.shortcuts_data[i].launch_func);
        }
        fprintf(p_file, "};\n");

        /* Function to get the size of the array */
        fprintf(p_file, "\n\n/*****************************************************************************\n");
        fprintf(p_file, " * FUNCTION\n");
        fprintf(p_file, " *  mmi_shct_get_candidate_menu_list_num\n");
        fprintf(p_file, " * DESCRIPTION\n");
        fprintf(p_file, " *  Get size of mmi_shct_candidate_menu[] array \n");
        fprintf(p_file, " * PARAMETERS\n");
        fprintf(p_file, " *  void\n");
        fprintf(p_file, " * RETURNS\n");
        fprintf(p_file, " *  Number of elements\n");
        fprintf(p_file, " *****************************************************************************/\n");
        fprintf(p_file, "U32 mmi_shct_get_candidate_menu_list_num(void)\n");
        fprintf(p_file, "{\n");
        if(g_mmi_rp_menu_cntx.shortcut.total == 0)
        {
            fprintf(p_file, "    return 0;       /* There's no element in the array. */\n");
        }
        else
        {
            fprintf(p_file, "    return sizeof(mmi_shct_candidate_menu)/sizeof(mmi_shct_candidate_menu[0]);\n");
        }
        fprintf(p_file, "}\n");

        fclose(p_file);
    }
    else
    {
        /* Error writing output file. Exit. */
        MMI_RP_FATAL_ERROR(RP_ERR_WRITE_OUPUT_PHASE2);
    }
}

