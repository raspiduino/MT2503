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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * BrowserUIPlugIn.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "FileMgrSrvGProt.h"
#ifndef MMI_BROWSERAPPSCRHDLR_C
#define MMI_BROWSERAPPSCRHDLR_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserAppScrHdlr.h"
#include "BrowserAppScrDB.h"
#include "BrowserAppUICallback.h"
#include "BrowserAppMain.h"
#include "BrowserAppTypes.h"
#include "BrowserAppDMgr.h"
#include "BrowserAppInterface.h"
#include "Menucuigprot.h"
#include "BrowserAppScrDB.h"
#include "BrowserAppUIPlugin.h"
#include "InlineCuiGprot.h"
#include "BrowserSrvBookmarks.h"
#include "FileMgrCUIGProt.h"
#include "fseditorcuigprot.h"

#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "BrowserResDef.h"
#include "wgui_categories_inputs.h"
#include "mmi_rp_app_browser_def.h"
#include "GlobalResDef.h"
#include "BrowserSrvProts.h"
#include "App_ltlcom.h"
#include "bam_struct.h"
#include "bam_api.h"
#include "mmi_frm_events_gprot.h"
#include "custom_events_notify.h"
#include "ProfilesSrvGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "app_buff_alloc.h"
#include "string.h"
#include "wgui_categories_util.h"
#include "Unicodexdcl.h"
#include "BookmarkCuiGprot.h"
#include "wps_struct.h"
#include "wgui_categories_search.h"
#include "gui_typedef.h"
#include "common_nvram_editor_data_item.h"
#include "BrowserSrvConfig.h"
#include "BrowserSrvInterface.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "mmi_rp_srv_browser_def.h"
#include "mmi_frm_timer_gprot.h"
#include "UriAgentSrvGprot.h"
#include "DebugInitDef_Int.h"
#include "wgui_inputs.h"
#include "Conversions.h"
#include "CustMenuRes.h"
#include "BrowserAppUIDraw.h"
#include "DLAgentSrvDef.h"
#include "ImeGprot.h"
#include "fs_errcode.h"


extern const U16 gIndexIconsImageList[];

/*  All the screen database pre function will be implemented here */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_init_function
 * DESCRIPTION
 *  This function is the init function of the screen database
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  Function pointer of the callback function
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_init_function(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    mmi_brw_app_result_enum ret_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_brw_app_get_curr_screenDB();
    if (scrDB->create_func != NULL)
    {
        ret_code = scrDB->create_func(screen_id);
        if(ret_code != MMI_BRW_TRUE)
        {
            return ret_code;
        }
    }
    if (scrDB->pre_func != NULL)
    {
        ret_code = scrDB->pre_func(screen_id);
    }
    if (scrDB->draw_func != NULL)
    {
        ret_code = scrDB->draw_func(screen_id);
        if(ret_code != MMI_BRW_TRUE)
        {
            return ret_code;
        }
    }
    if (scrDB->post_func != NULL)
    {
        ret_code = scrDB->post_func(screen_id);
        if(ret_code != MMI_BRW_TRUE)
        {
            return ret_code;
        }
    }
	return MMI_BRW_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_display_menu_cui
 * DESCRIPTION
 *  This function is to create and run menu CUI for a particular 
 * screen.
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_display_menu_cui(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;
    browser_cui_proc menu_cui_proc_func;
    mmi_id menu_gid;
    U16 parent_menu_id;
    cui_menu_src_type_enum cui_src;
    cui_menu_type_enum cui_menu_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_proc_func = mmi_brw_app_get_menu_cui_proc_func(screen_id);
    parent_menu_id = mmi_brw_app_get_parent_menu_id(screen_id);
    grp_id = mmi_brw_app_get_menu_cui_group_id(screen_id);
    mmi_frm_group_create_ex(g_brw_app_cntx.brw_scr_group_id,
                                                           grp_id,
                                                           menu_cui_proc_func,
                                                           (void*)NULL,
                                                           MMI_FRM_NODE_SMART_CLOSE_FLAG); 
    g_brw_app_cntx.brw_menu_cui_gid = grp_id;
    cui_src = mmi_brw_app_get_menu_cui_src_type(screen_id);
    cui_menu_type = mmi_brw_app_get_cui_menu_type(screen_id);

    menu_gid = cui_menu_create_and_run(g_brw_app_cntx.brw_menu_cui_gid,
                                    cui_src,
                                    cui_menu_type,
                                    parent_menu_id,
                                    MMI_TRUE,
                                    NULL);
    g_brw_app_cntx.brw_menu_cid = menu_gid;
    cui_menu_set_default_title_image_by_id(menu_gid, 
                                    mmi_brw_get_wap_icon());

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_display_inline_cui
 * DESCRIPTION
 *  This function is to create and run Inline CUI for a particular 
 * screen.
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_display_inline_cui(U16 screen_id, mmi_id parent_group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    browser_cui_proc inline_cui_proc_func;
    mmi_id inline_group_id;
    cui_inline_struct inline_struct;
    FuncPtr funcptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_cui_proc_func = mmi_brw_app_get_inline_cui_proc_func(screen_id);
    inline_group_id = mmi_brw_app_get_inline_group_id(screen_id);
    g_brw_app_cntx.brw_inline_cui_gid = mmi_frm_group_create_ex(parent_group_id, 
                                                           inline_group_id,
                                                           inline_cui_proc_func,
                                                           (void*)NULL,
                                                           MMI_FRM_NODE_SMART_CLOSE_FLAG); 

    inline_struct = mmi_brw_app_get_inline_cui_global_data(screen_id);
#ifdef INLINE_CUI_MEMORY_FROM_ASM 
    g_brw_app_cntx.brw_inline_cid = cui_inline_adm_create(g_brw_app_cntx.brw_inline_cui_gid,(const cui_inline_struct *)&inline_struct, g_srv_brw_cntx.brw_adm_id);
#else
    g_brw_app_cntx.brw_inline_cid = cui_inline_create(g_brw_app_cntx.brw_inline_cui_gid,(const cui_inline_struct *)&inline_struct);
#endif
    funcptr = mmi_brw_app_get_inline_cui_fill_func(screen_id);
    funcptr();
    cui_inline_set_parent_data(g_brw_app_cntx.brw_inline_cid, screen_id);
    cui_inline_set_title_icon(g_brw_app_cntx.brw_inline_cid, mmi_brw_get_wap_icon());
    cui_inline_run (g_brw_app_cntx.brw_inline_cid);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_display_fseditor_cui
 * DESCRIPTION
 *  This function is to create and run Full Screen Editor CUI for a particular 
 * screen.
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_display_fseditor_cui(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_proc_func fseditor_proc;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fseditor_proc = mmi_brw_app_get_proc_func_for_fseditor(screen_id);
    mmi_frm_group_create_ex(g_brw_app_cntx.brw_scr_group_id, BRW_FSEDITOR_GRP_ID, fseditor_proc, (void*)NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG); 

#ifdef FSEditor_CUI_MEMORY_FROM_ASM
    g_brw_app_cntx.fseditor_cid = cui_fseditor_adm_create(BRW_FSEDITOR_GRP_ID, g_srv_brw_cntx.brw_adm_id);
#else
    g_brw_app_cntx.fseditor_cid = cui_fseditor_create(BRW_FSEDITOR_GRP_ID);
#endif
    
    cui_fseditor_set_title(g_brw_app_cntx.fseditor_cid, mmi_brw_app_get_editor_title_string(screen_id), mmi_brw_get_wap_icon());
    cui_fseditor_set_buffer(g_brw_app_cntx.fseditor_cid,
                            (PU8) mmi_brw_app_get_editor_buffer(screen_id),
                            mmi_brw_app_get_editor_buffer_length(screen_id),
                            mmi_brw_app_get_editor_buffer_char_count(screen_id));

    cui_fseditor_set_input_method(g_brw_app_cntx.fseditor_cid,
                                  mmi_brw_app_get_editor_input_type(screen_id),
                                  NULL,
                                  INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

    cui_fseditor_run(g_brw_app_cntx.fseditor_cid);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_display_naming_rule_cui
 * DESCRIPTION
 *  This function is to create and run FMGR Naming Rule CUI for a particular 
 * screen.
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_display_naming_rule_cui(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id group_id, naming_rule_group_id;
    PU8 buffer;
    U8 operation;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    if(screen_id == SCR_ID_BRW_BKM_CREATE_FOLDER)
    {
        group_id = g_brw_app_cntx.brw_scr_group_id;
    }
    else
#endif
    {
        group_id = g_brw_app_cntx.brw_inline_cid;
    }
    buffer = mmi_brw_app_get_editor_buffer(screen_id);
    operation = mmi_brw_app_get_naming_rule_operation(screen_id);

    naming_rule_group_id = mmi_frm_group_create_ex(group_id, GRP_ID_AUTO_GEN, mmi_brw_app_file_naming_rule_cui_proc,(void*)NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG); 

    if(operation == 0)
    {
        g_brw_app_cntx.file_naming_rule_cid = cui_filename_editor_create(naming_rule_group_id, 
            (WCHAR *)buffer, 
            ((SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN + 1) * ENCODING_LENGTH), 
            SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN,
            NULL,
            NULL);
    }
    else
    {
        g_brw_app_cntx.file_naming_rule_cid = cui_filename_editor_create(naming_rule_group_id, 
            (WCHAR *)buffer, 
            ((SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH), 
            SRV_BRW_MAX_TITLE_LENGTH,
            NULL, 
            NULL);
    }

    cui_filename_editor_set_parent_data (g_brw_app_cntx.file_naming_rule_cid, operation);
    cui_filename_editor_set_title(g_brw_app_cntx.file_naming_rule_cid, STR_GLOBAL_EDIT, mmi_brw_get_wap_icon());
    cui_filename_editor_set_encoding_base_length(g_brw_app_cntx.file_naming_rule_cid, MMI_TRUE);
    cui_filename_editor_run(g_brw_app_cntx.file_naming_rule_cid);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_create_func
 * DESCRIPTION
 *  This is the create func for the internet services screen
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  MMI_BRW_TRUE if success otherwise MMI_BRW_FALSE.
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_create_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = mmi_brw_app_get_curr_screenDB();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrDB->rcDB = mmi_brw_app_get_current_resDB();

    //mmi_frm_create_new_screen(mmi_brw_app_sh_dummy_history_func, (void*)scrDB);
    //mmi_frm_scrn_first_enter(g_brw_app_cntx.brw_scr_group_id,scrDB->scrn_id,mmi_brw_app_sh_dummy_history_func,(void*)scrDB);
    return MMI_BRW_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_rendered_page_exit_func
 * DESCRIPTION
 *  This is the exit func for the internet services screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_rendered_page_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_suspend_browser_rendering();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_temp_progress_screen_exit_func
 * DESCRIPTION
 *  Exit function for temporary busy screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_temp_progress_screen_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q03C_BROWSER
    HDIa_widgetResetRenderingFlags();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_address_list_exit_func
 * DESCRIPTION
 *  Exit function for show address list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_address_list_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_MENU;
#endif /* __MMI_FTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_confirm_screen_exit_func
 * DESCRIPTION
 *  Exit function for confirmation screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_confirm_screen_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_QUERY));
}

/********************************END INTERNET SERVICES*******************/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_static_list_delete_scr_handler
 * DESCRIPTION
 *  This is the func to be registered on the delete screen callback to release
 * the OSL memory
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_app_sh_static_list_delete_scr_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrDB = (mmi_brw_app_screenDB_struct *)evt->user_data;
    if(scrDB != NULL)
    {
        if (NULL != scrDB->screen)
        {
            OslMfree(scrDB->screen);
            scrDB->screen = NULL;
        }
    }
    return MMI_RET_OK;
}


#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_static_list_delete_scr_handler
 * DESCRIPTION
 *  This is the func to be registered on the delete screen callback to release
 * the OSL memory
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_app_sh_recent_pages_delete_scr_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrDB = (mmi_brw_app_screenDB_struct *)evt->user_data;
    if(scrDB != NULL)
    {
        if (NULL != scrDB->screen)
        {
            OslMfree(scrDB->screen);
            scrDB->screen = NULL;
        }
    }
    srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_DYNAMIC_LIST);
    srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_RECENT_PAGES_LIST);
    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_static_list_delete_scr_handler
 * DESCRIPTION
 *  This is the func to be registered on the delete screen callback to release
 * the OSL memory
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_app_sh_view_certificate_delete_scr_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrDB = (mmi_brw_app_screenDB_struct *)evt->user_data;
    if(scrDB != NULL)
    {
        if (NULL != scrDB->screen)
        {
            OslMfree(scrDB->screen);
            scrDB->screen = NULL;
        }
    }
    if(g_brw_app_cntx.brw_dynamic_cntx_p->view_type == BRW_VIEW_TRUSTED_CERTIFICATE)
    {
        mmi_brw_app_free_browser_memory((void**)&(g_brw_app_cntx.brw_dynamic_cntx_p->trusted_cert_p));
    }
#ifdef OBIGO_Q05A
    if(g_brw_app_cntx.brw_dynamic_cntx_p->view_type == BRW_VIEW_CURRENT_CERTIFICATE)
    {
        mmi_brw_app_free_browser_memory((void**)&(g_brw_app_cntx.brw_dynamic_cntx_p->current_cert_p));
    }
    if(g_brw_app_cntx.brw_dynamic_cntx_p->view_type == BRW_VIEW_CURRENT_SESSION_INFO)
    {
        mmi_brw_app_free_browser_memory((void**)&(g_brw_app_cntx.brw_dynamic_cntx_p->session_info_p));
    }
#endif /* OBIGO_Q05A */
    return MMI_RET_OK;
}

/*******************************Bookmark*************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_dynamic_list_pre_func
 * DESCRIPTION
 *  This is the func pre function that will be called before entering the 
 * dynamic list menu
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_dynamic_list_pre_func(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_result_enum result = MMI_BRW_FALSE;
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    mmi_brw_app_scrhdlr_dynamic_screen_struct  **screen;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* define screen*/
	scrDB = mmi_brw_app_get_curr_screenDB();
	
    screen = (mmi_brw_app_scrhdlr_dynamic_screen_struct**) (&(scrDB->screen));
	if(scrDB->screen == NULL)
	{
		*screen = (mmi_brw_app_scrhdlr_dynamic_screen_struct*) srv_brw_malloc(sizeof (mmi_brw_app_scrhdlr_dynamic_screen_struct));
        memset(*screen, 0, (sizeof (mmi_brw_app_scrhdlr_dynamic_screen_struct)));

        (*screen)->scrn_id = screen_id;
        (*screen)->dynamic_list_handler = mmi_brw_app_ui_callback_get_dynamic_list_item;
    #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
        (*screen)->tap_callback_func = mmi_brw_app_get_tap_callback_func(screen_id);
    #ifdef __MMI_ICON_BAR_SUPPORT__
        (*screen)->show_toolbar_func = mmi_brw_app_get_show_toolbar_func(screen_id);
    #endif
    #endif /* #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)) */
		result = MMI_BRW_TRUE;
	}
    (*screen)->number_of_items = mmi_brw_app_get_dynamic_list_number_of_items(screen_id);
    return result;
}


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_bookmarks_list_post_func
 * DESCRIPTION
 *  This is the func post function that will be called after displaying the 
 * bookmark list menu
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_bookmarks_list_post_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_bkm_cntx.total_file_count == 0)
    {
    #ifdef __MMI_FTE_SUPPORT__
        wgui_icon_bar_set_item_enable_state(2,MMI_FALSE);
        wgui_icon_bar_update();
    #endif /*__MMI_FTE_SUPPORT__*/ 
    }
    return MMI_BRW_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_bookmarks_list_post_func
 * DESCRIPTION
 *  This is the exit function to be registered for the bookmark list with FW
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_bookmarks_list_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_MENU;
#endif
}

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_browse_path_exit_func
 * DESCRIPTION
 *  This is the exit function to be registered for the browse path list 
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_browse_path_lsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__
    if (g_brw_bkm_cntx.bkm_dynamic_cntx->is_first_level && g_brw_bkm_cntx.bkm_dynamic_cntx->sel_folder_index == BRW_BKM_EXTERNAL_MEMORY_MENU_ITEM_INDEX)
    {
        mmi_brw_app_if_browse_path_open_folder();
    }
    else
#endif /* __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__ */ 
    {
        mmi_brw_app_if_show_bookmark_browse_path_options();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_browse_path_exit_func
 * DESCRIPTION
 *  This is the exit function to be registered for the browse path list 
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_browse_path_exit_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_bookmarks_list_rsk_func
 * DESCRIPTION
 *  This is the function to be registered on RSK for the bookmark list with FW
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_bookmarks_list_rsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_bkm_cntx.sel_folder_name[0] == 0)
    {
    #if defined(__MMI_OP11_HOMESCREEN__)  || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        if(g_brw_app_cntx.isBookmarkLaunched)
        {
            g_brw_app_cntx.isBookmarkLaunched = MMI_FALSE;
		    mmi_brw_app_GoBackServicesMenu();
        }
        else
    #endif /* __MMI_OP11_HOMESCREEN__ */
        {
            mmi_frm_scrn_close_active_id();
        }
    }
#ifdef    __MMI_BRW_BKM_FOLDER_SUPPORT__
    else
    {
        U8 sel_folder_name[SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1] = {0};
        /* highlighting the selected folder */
        strcpy(sel_folder_name, g_brw_bkm_cntx.sel_folder_name);
        g_brw_bkm_cntx.sel_folder_name[0] = '\0';
        mmi_brw_app_create_bookmark_list();

        g_brw_bkm_cntx.sel_file_index = srv_brw_bookmarks_get_selected_item((U8*) sel_folder_name, g_brw_bkm_cntx.bookmark_list);

        /* here it is used for highlighting the default menu item */
        mmi_brw_app_if_show_browser_dummy_screen();
        mmi_frm_scrn_close_active_id();
    }
#endif
}

#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_select_bookmark_rsk_func
 * DESCRIPTION
 *  Its is called when user selects back option from select bookmark list screen.
 *  Its purpose is to displays appropiate screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_select_bookmark_rsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_bkm_sel_bkm_cntx.sel_folder_name[0] == 0)
    {
        mmi_brw_sel_bkm_send_result(EVT_ID_CUI_BKM_ADD_BKM_CLOSE, NULL, NULL);
    }
#ifdef    __MMI_BRW_BKM_FOLDER_SUPPORT__
    else
    {
        U8 sel_folder_name[SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1] = {0};
        /* highlighting the selected folder */
        strcpy(sel_folder_name, g_brw_bkm_sel_bkm_cntx.sel_folder_name);
        g_brw_bkm_sel_bkm_cntx.sel_folder_name[0] = '\0';
        mmi_brw_app_create_select_bookmark_list();

        g_brw_bkm_sel_bkm_cntx.sel_file_index = srv_brw_bookmarks_get_selected_item((U8*) sel_folder_name, g_brw_bkm_sel_bkm_cntx.bookmark_list);

        /* here it is used for highlighting the default menu item */
        mmi_brw_app_if_show_browser_dummy_screen();
        mmi_frm_scrn_close_active_id();
    }
#endif
}
#endif

/*****************************End Bookmark***********************************/
#endif /* __MMI_VBOOKMARK__ */


/*******************************Viewer screen*********************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_viewer_screen_pre_func
 * DESCRIPTION
 *  This is the pre function for the viewer screens
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_viewer_screen_pre_func(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    mmi_brw_app_scrhdlr_view_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_brw_app_get_curr_screenDB();
	
	if(scrDB->screen == NULL)
	{
        screen = (mmi_brw_app_scrhdlr_view_screen_struct**) (&(scrDB->screen));
		*screen = (mmi_brw_app_scrhdlr_view_screen_struct*) OslMalloc (sizeof (mmi_brw_app_scrhdlr_view_screen_struct));
        memset(*screen, 0, (sizeof (mmi_brw_app_scrhdlr_view_screen_struct)));

        (*screen)->scrn_id = screen_id;

        return MMI_BRW_TRUE;
	}
    return MMI_BRW_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_scrhdlr_pre_small_screen
 * DESCRIPTION
 *  This is the pre function for the small screen
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_scrhdlr_pre_small_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    mmi_brw_app_confirm_screen_struct  **screen;
	mmi_brw_app_resourceDB_struct *resourceDB = NULL;
    U16 display_msg_str_id;
    U16 title_str_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_brw_app_get_curr_screenDB();
    resourceDB = scrDB->rcDB;

    screen = (mmi_brw_app_confirm_screen_struct**) (&(scrDB->screen));	
    if(scrDB->screen == NULL)
    {
        *screen = (mmi_brw_app_confirm_screen_struct*) srv_brw_malloc (sizeof (mmi_brw_app_confirm_screen_struct));
        memset(*screen, 0, (sizeof (mmi_brw_app_confirm_screen_struct)));

        (*screen)->scrn_id = screen_id;
        mmi_brw_app_get_small_screen_data(screen_id, 
                                          &display_msg_str_id, 
                                          &title_str_id,
                                          &(*screen)->msg_img_id,
                                          &(*screen)->tone_id);
        (*screen)->display_msg = get_string((U16) display_msg_str_id);
        (*screen)->lsk_str_id = resourceDB->lsk_str_id;
        (*screen)->lsk_img_id = resourceDB->lsk_icon_id;
        (*screen)->rsk_str_id = resourceDB->rsk_str_id;
        (*screen)->rsk_img_id = resourceDB->rsk_icon_id;

		return MMI_BRW_TRUE;
	}
    return MMI_BRW_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_scrhdlr_pre_osl_small_screen
 * DESCRIPTION
 *  This is the pre function for the progress screen
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_scrhdlr_pre_osl_small_screen (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    mmi_brw_app_scrhdlr_small_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_brw_app_get_curr_screenDB();

    screen = (mmi_brw_app_scrhdlr_small_screen_struct**) (&(scrDB->screen));	
	if(scrDB->screen == NULL)
	{
		*screen = (mmi_brw_app_scrhdlr_small_screen_struct*) OslMalloc (sizeof (mmi_brw_app_scrhdlr_small_screen_struct));
        memset(*screen, 0, (sizeof (mmi_brw_app_scrhdlr_small_screen_struct)));

        (*screen)->scrn_id = screen_id;
        mmi_brw_app_get_small_screen_data(screen_id, 
                                          &(*screen)->display_msg_str_id, 
                                          &(*screen)->title_str_id,
                                          &(*screen)->msg_img_id,
                                          &(*screen)->tone_id);
		return MMI_BRW_TRUE;
	}
    return MMI_BRW_FALSE;
}

#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_sec_confirm_pre_func
 * DESCRIPTION
 *  This is the pre function for the security confirmation small screen.
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_sec_confirm_pre_func (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    mmi_brw_app_confirm_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_brw_app_get_curr_screenDB();

    screen = (mmi_brw_app_confirm_screen_struct**) (&(scrDB->screen));	
	if(scrDB->screen == NULL)
	{
		*screen = (mmi_brw_app_confirm_screen_struct*) OslMalloc (sizeof (mmi_brw_app_confirm_screen_struct));
        memset(*screen, 0, (sizeof (mmi_brw_app_confirm_screen_struct)));

        (*screen)->scrn_id = screen_id;
        (*screen)->display_msg = get_string((U16) g_brw_app_cntx.sec_confirm_dlg_info_p->text_id);
        if (g_brw_app_cntx.sec_confirm_dlg_info_p->buttons == WPS_DLG_BUTTON_YESNO)
        {
            (*screen)->msg_img_id = mmi_get_event_based_image(MMI_EVENT_QUERY);
            (*screen)->tone_id = mmi_get_event_based_sound(MMI_EVENT_QUERY);
            (*screen)->lsk_str_id = STR_GLOBAL_YES;
            (*screen)->lsk_img_id = IMG_GLOBAL_YES;
            (*screen)->rsk_str_id = STR_GLOBAL_NO;
            (*screen)->rsk_img_id = IMG_GLOBAL_NO;
        }
        else
        {
            mmi_event_notify_enum event_id = mmi_brw_app_convert_wps_dialog_type_to_mmi_event();
            (*screen)->msg_img_id = mmi_get_event_based_image(event_id);
            (*screen)->tone_id = mmi_get_event_based_sound(event_id);
            (*screen)->lsk_str_id = STR_GLOBAL_OK;
            (*screen)->lsk_img_id = IMG_GLOBAL_OK;
            (*screen)->rsk_str_id = 0;
            (*screen)->rsk_img_id = 0;
        }
		return MMI_BRW_TRUE;
	}
    return MMI_BRW_FALSE;
}
#endif /* WAP_SEC_SUPPORT */

#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_enter_url_pre_func
 * DESCRIPTION
 *  This is the pre function for the Enter URL editor screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_enter_url_pre_func(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_result_enum result = MMI_BRW_FALSE;
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    mmi_brw_app_scrhdlr_enter_url_screen_struct  **screen;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* define screen*/
	scrDB = mmi_brw_app_get_curr_screenDB();
	
    screen = (mmi_brw_app_scrhdlr_enter_url_screen_struct**) (&(scrDB->screen));
	if(scrDB->screen == NULL)
	{
    #ifdef __MMI_BRW_URL_AUTO_COMPLETION__
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_items = 0;
    #endif
    #ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_search_items = 0;
    #endif
        mmi_ucs2cpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->user_input_url, (S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url);
		*screen = (mmi_brw_app_scrhdlr_enter_url_screen_struct*) srv_brw_malloc(sizeof(mmi_brw_app_scrhdlr_enter_url_screen_struct));
        memset(*screen, 0, sizeof(mmi_brw_app_scrhdlr_enter_url_screen_struct));

        (*screen)->scrn_id = screen_id;
        (*screen)->hilighted_item = CAT103_INVALID_HIGHLIGHT;
        (*screen)->get_number_of_matched_items_func = mmi_brw_app_ui_callback_get_matched_items_count;
        (*screen)->get_matched_item_func = (GetItemFuncPtr)mmi_brw_app_ui_callback_get_matched_item;
        (*screen)->get_hint_func = NULL;
        (*screen)->search_func = mmi_brw_app_ui_callback_find_entry;
        (*screen)->buffer = (U8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url;
        (*screen)->buffer_length = BRW_ADDRESS_LIST_URL_LENGTH;
		result = MMI_BRW_TRUE;
	}
#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
    if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_items_list && g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_items_list = (U8*) srv_brw_malloc(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items);
    }
#endif
#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_search_items_list && g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_search_items_list = (U8*) srv_brw_malloc(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items);
    }
#endif

    if (!g_brw_app_cntx.brw_dynamic_cntx_p->user_input_url)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->user_input_url = (U8*) srv_brw_malloc((SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
        mmi_ucs2cpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->user_input_url, (S8*) g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url);
    }
    return result;
}
#endif /* #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)*/

#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_upload_progress_pre_func
 * DESCRIPTION
 *  This is the pre function for the upload progress screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_upload_progress_pre_func(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    mmi_brw_app_scrhdlr_upload_screen_struct  **screen;
    mmi_brw_app_result_enum result = MMI_BRW_FALSE;
    U32 bytes_sent = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_sent;
    U32 bytes_total = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_total;
    UI_string_type display_str[1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_brw_app_get_curr_screenDB();

    screen = (mmi_brw_app_scrhdlr_upload_screen_struct**) (&(scrDB->screen));	
	if(scrDB->screen == NULL)
	{
        screen = (mmi_brw_app_scrhdlr_upload_screen_struct**) (&(scrDB->screen));
		*screen = (mmi_brw_app_scrhdlr_upload_screen_struct*) srv_brw_malloc (sizeof (mmi_brw_app_scrhdlr_upload_screen_struct));
        memset(*screen, 0, (sizeof (mmi_brw_app_scrhdlr_upload_screen_struct)));

        (*screen)->scrn_id = screen_id;
        (*screen)->message_count = 1;
        result = MMI_BRW_TRUE;
	}
    if (bytes_sent < bytes_total)
    {
        (*screen)->rsk_str_id = STR_GLOBAL_CANCEL;
    #ifndef SLIM_WAP_MMS
        (*screen)->progress_img_id = IMG_ID_BRW_UPLOAD_PROGRESS;
    #endif
    }
    /* if uploading has completed then RSK should be back and
       upload completed string should be displayed to user. Also
       the static banner image should be displayed and the upload completed
       flag should be made true, Also bytes sent should be made equal to 
       bytes total if they are greater */
    else
    {
        (*screen)->rsk_str_id = STR_GLOBAL_BACK;
    #ifndef SLIM_WAP_MMS
        (*screen)->progress_img_id = IMG_ID_BRW_UPLOAD_PROGRESS_STATIC;
    #endif
        g_brw_app_cntx.brw_dynamic_cntx_p->upload_status = BRW_UPLOAD_STATUS_COMPLETE;
        (*screen)->message_str_id = STR_ID_BRW_UPLOAD_COMPLETED;
        bytes_sent = bytes_total;
    }
    mmi_brw_app_free_browser_memory((void**)&(g_brw_display_info_str));
    g_brw_display_info_str = (U8*)srv_brw_malloc((BRW_MAX_UPLOAD_STRING_LENGTH + 1) * ENCODING_LENGTH);
    memset(g_brw_display_info_str, 0, (BRW_MAX_UPLOAD_STRING_LENGTH + 1) * ENCODING_LENGTH);
    (*screen)->percentage_value = (U8) (((float)bytes_sent / bytes_total) * 100);
    mmi_brw_app_format_size_total(bytes_sent, bytes_total);
    mmi_asc_to_ucs2((S8*)g_brw_display_info_str , (S8*) subMenuData[1]);
    (*screen)->display_str[0] = (UI_string_type)(g_brw_display_info_str);
    return result;
}
#endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_rendered_page_pre_func
 * DESCRIPTION
 *  This is the pre function for the rendered page screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_rendered_page_pre_func(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    mmi_brw_app_scrhdlr_rendered_page_screen_struct  **screen;
    mmi_brw_app_result_enum result = MMI_BRW_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_brw_app_get_curr_screenDB();
    screen = (mmi_brw_app_scrhdlr_rendered_page_screen_struct**) (&(scrDB->screen));	

	if(scrDB->screen == NULL)
	{
        screen = (mmi_brw_app_scrhdlr_rendered_page_screen_struct**) (&(scrDB->screen));
		*screen = (mmi_brw_app_scrhdlr_rendered_page_screen_struct*) srv_brw_malloc (sizeof (mmi_brw_app_scrhdlr_rendered_page_screen_struct));
        memset(*screen, 0, (sizeof (mmi_brw_app_scrhdlr_rendered_page_screen_struct)));
        
        (*screen)->scrn_id = screen_id;
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
#ifdef __MMI_ICON_BAR_SUPPORT__
        (*screen)->show_toolbar_func = mmi_brw_app_get_show_toolbar_func(screen_id);
#endif
#endif /* #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)) */
        (*screen)->pen_handler_func = mmi_brw_app_ui_callback_ren_page_pen_handler;        
        result = MMI_BRW_TRUE;
	}
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__    
    (*screen)->title_icon = mmi_brw_app_get_ren_page_title_icon();
#endif
    (*screen)->title_str_buffer = mmi_brw_app_get_ren_page_title_string();
#ifdef WAP_SEC_SUPPORT
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p && g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->security_id >= 0)
    {
        (*screen)->security_icon = IMG_ID_BRW_SECURE_ICON;
    }
    else
    {
        (*screen)->security_icon = 0;
    }
#endif /* WAP_SEC_SUPPORT */
    (*screen)->screen_size_status = g_srv_brw_cntx.screen_size_status;
#ifdef __MMI_BRW_PAGE_FETCHING_STATUS__
	if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching)
    {
		(*screen)->percentage = g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_progress;
        switch (g_brw_app_cntx.brw_dynamic_cntx_p->page_fetching_status)
        {
            case BRW_FETCHING_STATUS_CONNECTING:
            {
                (*screen)->display_str = (S8*) GetString(STR_ID_BRW_CONNECTING);
                break;
            }
            case BRW_FETCHING_STATUS_PROCESSING:
            {
                (*screen)->display_str = (S8*) GetString(STR_ID_BRW_PROCESSING);
                break;
            }
            case BRW_FETCHING_STATUS_LOADING:
            {
                (*screen)->display_str = (S8*) GetString(STR_ID_BRW_LOADING);
                break;
            }
            default:
            {
                (*screen)->display_str = (S8*) GetString(STR_ID_BRW_CONNECTING);
                break;
            }
        }
	}
	else
#endif /* __MMI_BRW_PAGE_FETCHING_STATUS__ */
	{
		(*screen)->percentage = -1;
		(*screen)->display_str = NULL;
	}

    return result;
}

#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_splash_screen_pre_func
 * DESCRIPTION
 *  This is the pre function for the rendered page splash screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_splash_screen_pre_func(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    mmi_brw_app_scrhdlr_img_screen_struct  **screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrDB = mmi_brw_app_get_curr_screenDB();

	if(scrDB->screen == NULL)
	{
        screen = (mmi_brw_app_scrhdlr_img_screen_struct**) (&(scrDB->screen));
		*screen = (mmi_brw_app_scrhdlr_img_screen_struct*) srv_brw_malloc (sizeof (mmi_brw_app_scrhdlr_img_screen_struct));
        memset(*screen, 0, (sizeof (mmi_brw_app_scrhdlr_img_screen_struct)));

        (*screen)->scrn_id = screen_id;
        (*screen)->img_id = IMG_ID_BRW_SPLASH_SCREEN;
        (*screen)->enable_full_screen_check_func = mmi_brw_ui_callback_get_full_screen_status;
        return MMI_BRW_TRUE;
	}
    return MMI_BRW_FALSE;
}
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
/*********************************Common function****************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_dummy_history_func
 * DESCRIPTION
 *  This is dummy function to be passed to mmi_frm_create_new_screen function
 * in the various screen handler functions
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  MMI_BRW_TRUE if success otherwise MMI_BRW_FALSE.
 *****************************************************************************/
void mmi_brw_app_sh_dummy_history_func(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_dynamic_list_delete_scr_handler
 * DESCRIPTION
 *  This is dummy function to be passed to mmi_frm_create_new_screen function
 * in the various screen handler functions
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  MMI_BRW_TRUE if success otherwise MMI_BRW_FALSE.
 *****************************************************************************/
mmi_ret mmi_brw_app_sh_dynamic_list_delete_scr_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            scrDB = (mmi_brw_app_screenDB_struct *)evt->user_data;
            if(scrDB != NULL)
            {
                if (NULL != scrDB->screen)
                {
                    srv_brw_free(scrDB->screen);
                    scrDB->screen = NULL;
                }
                mmi_brw_app_free_dynamic_list_memory(scrDB->scrn_id);
            }
        }
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_address_list_lsk_func
 * DESCRIPTION
 *  LSK handler for Address list screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_address_list_lsk_func(void)
{
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_address_list_rsk_func
 * DESCRIPTION
 *  RSK handler for Address list screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_address_list_rsk_func(void)
{
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    if(g_brw_app_cntx.isBookmarkLaunched)
    {
        g_brw_app_cntx.isBookmarkLaunched = MMI_FALSE;
        mmi_brw_app_GoBackServicesMenu();
    }
    else
#endif /* __MMI_OP11_HOMESCREEN__ */
    {
        mmi_frm_scrn_close_active_id();
    }
}

#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_enter_url_editor_delete_scr_handler
 * DESCRIPTION
 *  This is called when URL Editor screen is deleted
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_app_sh_enter_url_editor_delete_scr_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            scrDB = (mmi_brw_app_screenDB_struct *)evt->user_data;
        #ifdef __MMI_BRW_URL_AUTO_COMPLETION__
            mmi_brw_app_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_items_list));
        #endif
        #ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
            mmi_brw_app_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_search_items_list));
        #endif
            mmi_brw_app_free_browser_memory((void**)&(g_brw_app_cntx.brw_dynamic_cntx_p->user_input_url));
        #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
            if(g_brw_app_cntx.isBookmarkLaunched && (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items == 0))
            {
                g_brw_app_cntx.isBookmarkLaunched = MMI_FALSE;
                mmi_brw_app_GoBackServicesMenu();
            }
        #endif /* #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
            if(scrDB != NULL)
            {
                if (NULL != scrDB->screen)
                {
                    srv_brw_free(scrDB->screen);
                    scrDB->screen = NULL;
                }
            }
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_enter_url_rsk_func
 * DESCRIPTION
 *  RSK handler for Page objects options screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_enter_url_rsk_func(void)
{
#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
    mmi_brw_app_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_items_list));
#endif
#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    mmi_brw_app_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_search_items_list));
#endif
    mmi_brw_app_free_browser_memory((void**)&(g_brw_app_cntx.brw_dynamic_cntx_p->user_input_url));
    mmi_brw_app_sh_address_list_rsk_func();
}
#endif /* #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)*/

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_generic_post_func
 * DESCRIPTION
 *  Generic API to be called post the screen Draw
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_progress_screen_post_func(U16 screen_id)
{
    if(mmi_frm_group_get_active_id() == g_brw_app_cntx.brw_scr_group_id)
    {
        ClearAllKeyHandler();
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
    }
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_generic_post_func
 * DESCRIPTION
 *  Generic API to be called post the screen Draw
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_generic_post_func(U16 screen_id)
{
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_browser_options_rsk_func
 * DESCRIPTION
 *  A mmi_frm_scrn_close_active_id wrapper for Browser options screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_browser_options_rsk_func(void)
{
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_stored_pages_list_rsk_func
 * DESCRIPTION
 *  A mmi_frm_scrn_close_active_id wrapper for RSK handler on stored pages list screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_stored_pages_list_rsk_func(void)
{
	mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_rendered_page_post_func
 * DESCRIPTION
 *  This API is called as a "post" event after Rendered page screen draw is done
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_rendered_page_post_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN) && (mmi_frm_scrn_get_active_id() != mmi_brw_app_get_splash_scr_id()))
    {
        return MMI_BRW_TRUE;
    }
    if (g_brw_app_cntx.brw_dynamic_cntx_p->requested_url_p)
    {
        memset(g_brw_current_url, 0, sizeof(g_brw_current_url));
        mmi_asc_n_to_ucs2((S8*) g_brw_current_url, (S8*)g_brw_app_cntx.brw_dynamic_cntx_p->requested_url_p , SRV_BRW_MAX_URL_LEN);
        mmi_brw_srv_hdlr_load_url_req(g_brw_current_url);
        mmi_brw_app_free_browser_memory((void**)&(g_brw_app_cntx.brw_dynamic_cntx_p->requested_url_p));
    }
    mmi_brw_app_srv_hdlr_notify_screen_info();

    bam_resume_browser_rendering();
    bam_register_keypad_handler();
#ifdef __MMI_FTE_SUPPORT__
    mmi_brw_app_change_ren_page_FTE_toolbar_state();
#endif
    mmi_brw_app_ren_page_set_LSK();
    mmi_brw_app_ren_page_set_RSK();
	return MMI_BRW_TRUE;
}

#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_splash_screen_post_func
 * DESCRIPTION
 *  This API is called as a "post" event after Splash screen draw is done
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_sh_splash_screen_post_func(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(BRW_SPLASH_SCREEN_TIMER, BRW_SPLASH_SCREEN_TIMER_VALUE, mmi_brw_app_if_splash_screen_timer_callback);
    mmi_brw_app_ren_page_set_LSK();
    mmi_brw_app_ren_page_set_RSK();
    mmi_brw_app_set_splash_screen_title_icon();
	return MMI_BRW_TRUE;
}
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_ren_page_this_page_rsk_func
 * DESCRIPTION
 *  A mmi_frm_scrn_close_active_id wrapper for This page option of rendered page screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_ren_page_this_page_rsk_func(void)
{
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_memory_status_screen_rsk_func
 * DESCRIPTION
 *  RSK handler for memory status screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_memory_status_screen_rsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_free_browser_memory((void**)&(g_brw_display_info_str));
    mmi_frm_scrn_close_active_id();
}
#ifdef __OP01__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_memory_status_screen_rsk_func
 * DESCRIPTION
 *  RSK handler for memory status screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_view_url_screen_rsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_free_browser_memory((void**)&(g_brw_display_info_str));
    mmi_frm_scrn_close_active_id();
}
#endif /* __OP01__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_trusted_certificates_list_rsk_func
 * DESCRIPTION
 *  A mmi_frm_scrn_close_active_id wrapper for RSK handler on trusted cert list screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_trusted_certificates_list_rsk_func(void)
{
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_view_certificate_screen_rsk_func
 * DESCRIPTION
 *  RSK handler for Trusted certificate body screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_view_certificate_screen_rsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_free_browser_memory((void**)&(g_brw_display_info_str));
    mmi_frm_scrn_close_active_id();
}

#ifndef SLIM_WAP_MMS
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_page_actions_list_lsk_func
 * DESCRIPTION
 *  LSK handler for page actions list screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_page_actions_list_lsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlighted_item = GetHighlightedItem();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* don't take any action if the selected DO element is of type "prev" and */
    /* no previous page is available in page navigation list                 */
    if (!srv_brw_stricmp
        ((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list[highlighted_item].event_type, (S8*) BRW_DO_ELEMENT_EVENT_TYPE_PREVIOUS)
        && !srv_brw_is_backward_navigation())
    {
        mmi_brw_app_pre_entry_render_page();
        return;
    }
    mmi_brw_app_pre_entry_render_page();
    srv_brw_activate_do_element_req(highlighted_item);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_page_actions_list_rsk_func
 * DESCRIPTION
 *  A mmi_frm_scrn_close_active_id wrapper for Page actions list screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_page_actions_list_rsk_func(void)
{
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_page_object_types_lsk_func
 * DESCRIPTION
 *  LSK handler for page objects types screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef OBIGO_Q05A
void mmi_brw_app_sh_page_object_types_lsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 hilited_item_index;
    U8 index = 0;
    S16 active_item_count = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hilited_item_index = (U8) GetHighlightedItem();
    do
    {
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_object_type[index] == MMI_TRUE)
        {
            ++active_item_count;
            if (active_item_count == hilited_item_index)
            {
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->selected_page_object_type = index;
                break;
            }
        }
        ++index;
    } while (index < BRW_PAGE_OBJECT_TYPES_COUNT);

    mmi_brw_app_if_show_page_objects();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_page_object_types_rsk_func
 * DESCRIPTION
 *  A mmi_frm_scrn_close_active_id wrapper for Page objects types screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_page_object_types_rsk_func(void)
{
    mmi_frm_scrn_close_active_id();
}

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_recent_pages_host_lsk_func
 * DESCRIPTION
 *  LSK handler for recent pages host list
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_recent_pages_host_lsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item = GetHighlightedItem();
    mmi_brw_app_if_show_recent_pages_host_options_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_recent_pages_host_rsk_func
 * DESCRIPTION
 *  A mmi_frm_scrn_close_active_id wrapper for RSK handler on recent pages host screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_recent_pages_host_rsk_func(void)
{
    mmi_frm_scrn_close_active_id();
}
#endif
#endif /* OBIGO_Q05A */


#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_sec_confirm_lsk_func
 * DESCRIPTION
 *  LSK handler for Security confirm dialog screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_sec_confirm_lsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_sec_confirm_dialog_res(WPS_DLG_OK);
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_sec_confirm_rsk_func
 * DESCRIPTION
 *  RSK handler for Security confirm dialog screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_sec_confirm_rsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_sec_confirm_dialog_res(WPS_DLG_CANCEL);
    mmi_frm_scrn_close_active_id();
}
#endif /* WAP_SEC_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_out_of_mem_confirm_lsk_func
 * DESCRIPTION
 *  LSK handler for "Out of memory" Confirmation screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_out_of_mem_confirm_lsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_close_download_and_exit();
}
#ifdef __MMI_URI_AGENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_uha_uri_scheme_confirm_lsk_func
 * DESCRIPTION
 *  LSK handler for Browser as a handler application(UHA) for a URI scheme
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_uha_uri_scheme_confirm_lsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_app_cntx.uha_info_p->uri_agent_cb)
    {
        g_brw_app_cntx.uha_info_p->uri_agent_cb(g_brw_app_cntx.uha_info_p->ura_appid, SRV_URIAGENT_APPID_BRW, MMI_TRUE);
        g_brw_app_cntx.uha_info_p->uri_agent_cb = NULL;
    }

    mmi_brw_app_load_url(g_brw_app_cntx.uha_info_p->url);

    mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_UHA_URI_SCHEME_CONFIRM_SCREEN);

    OslMfree(g_brw_app_cntx.uha_info_p);
    g_brw_app_cntx.uha_info_p = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_uha_uri_scheme_confirm_rsk_func
 * DESCRIPTION
 *  RSK handler for Browser as a handler application(UHA) for a URI scheme
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_uha_uri_scheme_confirm_rsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_app_cntx.uha_info_p->uri_agent_cb)
    {
        g_brw_app_cntx.uha_info_p->uri_agent_cb(g_brw_app_cntx.uha_info_p->ura_appid, SRV_URIAGENT_APPID_BRW, MMI_TRUE);
        g_brw_app_cntx.uha_info_p->uri_agent_cb = NULL;
    }

    mmi_frm_scrn_close_active_id();
    OslMfree(g_brw_app_cntx.uha_info_p);
    g_brw_app_cntx.uha_info_p = NULL;
}
#endif /* #ifdef __MMI_URI_AGENT__ */

#ifdef __MMI_BRW_PAGE_SIZE_CHECKING__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_page_size_check_lsk_func
 * DESCRIPTION
 *  A mmi_frm_scrn_close_active_id wrapper for Page size check screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_page_size_check_lsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_page_size_check_rsk_func
 * DESCRIPTION
 *  RSK handler for page size check screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_page_size_check_rsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(BRW_RENDERED_PAGE_GRP_ID, SCR_ID_BRW_PAGE_SIZE_CHECK);
    mmi_brw_app_stop_ren_page_fetching();
    return;
}
#endif


#ifdef __MMI_BRW_LOADING_TIME_CHECKING__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_loading_time_check_lsk_func
 * DESCRIPTION
 *  A mmi_frm_scrn_close_active_id wrapper for Loading time check screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_loading_time_check_lsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_loading_time_check_rsk_func
 * DESCRIPTION
 *  RSK handler for loading time check screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_loading_time_check_rsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(BRW_RENDERED_PAGE_GRP_ID, SCR_ID_BRW_LOADING_TIME_CHECK);
    mmi_brw_app_stop_ren_page_fetching();
    return;
}
#endif


#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_upload_progress_rsk_func
 * DESCRIPTION
 *  RSK handler for Upload progress screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_upload_progress_rsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_sent >= g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_total)
    {
        StopTimer(BRW_UPLOAD_COMPLETED_TIMER);
        g_brw_app_cntx.brw_dynamic_cntx_p->upload_status = BRW_UPLOAD_STATUS_FINISHED;
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_brw_app_if_show_upload_cancel_confirm_screen();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_upload_cancel_lsk_func
 * DESCRIPTION
 *  LSK handler for Upload progress screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_upload_cancel_lsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_stop_page_fetching_req();
    //DeleteUptoScrID(SCR_ID_BRW_BROWSER_MAIN);
    mmi_frm_scrn_close(BRW_RENDERED_PAGE_GRP_ID, SCR_ID_BRW_UPLOAD_PROGRESS_SCREEN);
    mmi_frm_scrn_close_active_id();
    g_brw_app_cntx.brw_dynamic_cntx_p->upload_status = BRW_UPLOAD_STATUS_FINISHED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_upload_cancel_rsk_func
 * DESCRIPTION
 *  A mmi_frm_scrn_close_active_id wrapper for Upload cancel screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_upload_cancel_rsk_func(void)
{
    mmi_frm_scrn_close_active_id();
}

#endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_post_session_info_screen_lsk_func
 * DESCRIPTION
 *  A mmi_frm_scrn_close_active_id wrapper for Post session info screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_brw_app_sh_post_session_info_screen_lsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_ren_page_this_link_rsk_func
 * DESCRIPTION
 *  A mmi_frm_scrn_close_active_id wrapper for This link option of rendered page options screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_ren_page_this_link_rsk_func(void)
{
    mmi_frm_scrn_close_active_id();
}

#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_select_bookmark_delete_scr_handler
 * DESCRIPTION
 *  API is called when select bookmark screen is deleted
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_app_sh_select_bookmark_delete_scr_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrDB = (mmi_brw_app_screenDB_struct *)evt->user_data;
    if(scrDB != NULL)
    {
        if (NULL != scrDB->screen)
        {
            srv_brw_free(scrDB->screen);
            scrDB->screen = NULL;
        }
    }
    if(g_brw_bkm_sel_bkm_cntx.sel_folder_name)
    {
        mmi_brw_sel_bkm_send_result(EVT_ID_CUI_BKM_ADD_BKM_CLOSE, NULL, NULL);
    }
    mmi_brw_app_free_browser_memory((void**)&(g_brw_bkm_sel_bkm_cntx.sel_folder_name));

    if(g_brw_bkm_sel_bkm_pool)
    {
        mmi_brw_app_deinit();
    }
    return MMI_RET_OK;
}
#endif

#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_sec_confirm_dlg_delete_scr_handler
 * DESCRIPTION
 *  API is called when Security confirmation screen is deleted
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_app_sh_sec_confirm_dlg_delete_scr_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrDB = (mmi_brw_app_screenDB_struct *)evt->user_data;
    if(scrDB != NULL)
    {
        if (NULL != scrDB->screen)
        {
            OslMfree(scrDB->screen);
            scrDB->screen = NULL;
        }
    }
    /* sending the default response for security dialog, in case */
    /* user exit the screen without giving any response */
    if (g_brw_app_cntx.sec_confirm_dlg_info_p)
    {
        if (g_brw_app_cntx.sec_confirm_dlg_info_p->buttons == WPS_DLG_BUTTON_YESNO)
        {
            mmi_brw_app_sec_confirm_dialog_res(WPS_DLG_CANCEL);
        }
        else
        {
            mmi_brw_app_sec_confirm_dialog_res(WPS_DLG_OK);
        }
    }
    return MMI_RET_OK;
}
#endif /* WAP_SEC_SUPPORT */
#ifdef __MMI_URI_AGENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_uha_uri_scheme_confirm_dlg_delete_scr_handler
 * DESCRIPTION
 *  API is called when URI scheme confirm dialog is deleted
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/

mmi_ret mmi_brw_app_sh_uha_uri_scheme_confirm_dlg_delete_scr_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrDB = (mmi_brw_app_screenDB_struct *)evt->user_data;
    if(scrDB != NULL)
    {
        if (NULL != scrDB->screen)
        {
            OslMfree(scrDB->screen);
            scrDB->screen = NULL;
        }
    }
    /* Sending the default response for URI scheme screen. */
    /* In case user exit the screen without giving any response. */
    if (g_brw_app_cntx.uha_info_p && g_brw_app_cntx.uha_info_p->uri_agent_cb)
    {
        g_brw_app_cntx.uha_info_p->uri_agent_cb(g_brw_app_cntx.uha_info_p->ura_appid, SRV_URIAGENT_APPID_BRW, MMI_FALSE);
        g_brw_app_cntx.uha_info_p->uri_agent_cb = NULL;
    }
    return MMI_RET_OK;
}
#endif /* __MMI_URI_AGENT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_page_objects_rsk_func
 * DESCRIPTION
 *  A mmi_frm_scrn_close_active_id wrapper for Page objects screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_brw_app_sh_page_objects_rsk_func(void)
{
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_generic_rsk_func
 * DESCRIPTION
 *  A generic mmi_frm_scrn_close_active_id wrapper for various screens
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_brw_app_sh_generic_rsk_func(void)
{
    mmi_frm_scrn_close_active_id();
}


#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_bookmark_browse_path_rsk_func
 * DESCRIPTION
 *  Its is called when user selects back option from select path bookmark folder
 *  list screen. Its  purpose is to displays appropiate screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_bookmark_browse_path_rsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type end_sep_loc;
    U8 sel_folder_name[(SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_brw_bkm_cntx.bkm_dynamic_cntx->is_first_level)
    {
        mmi_brw_app_create_bookmark_list();
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        g_brw_bkm_cntx.bkm_dynamic_cntx->is_first_level = MMI_TRUE;
        mmi_brw_app_if_show_browser_dummy_screen();
        mmi_frm_scrn_close_active_id();
    }
}
#endif


mmi_ret mmi_brw_app_auth_sec_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
            break;
        case EVT_ID_GROUP_INACTIVE:
            break;
        case EVT_ID_GROUP_ACTIVE:
			 g_brw_app_cntx.brw_scr_group_id = BRW_AUTH_SEC_FROM_OUTSIDE_GRP_ID;
            break;
        
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            mmi_frm_group_close(BRW_AUTH_SEC_FROM_OUTSIDE_GRP_ID);
            g_brw_app_cntx.brw_scr_group_id = GRP_ID_INVALID;
            break;
        
        case EVT_ID_GROUP_DEINIT:
            mmi_frm_group_close(BRW_AUTH_SEC_FROM_OUTSIDE_GRP_ID);
            g_brw_app_cntx.brw_scr_group_id = GRP_ID_INVALID;
            break;
        
        case EVT_ID_GROUP_FOCUSED:
            break;
    }
    return MMI_RET_OK;
}


#ifdef __MMI_Q05A_LAUNCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_sh_shortcuts_list_rsk_func
 * DESCRIPTION
 *  This is the func to be registered on the RSK of the shortcuts list 
 * screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_sh_shortcuts_list_rsk_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_GoBackServicesMenu(); //rename
}
#endif


/*  Menu CUI Procs */
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_internet_service_menu_cui_proc
 * DESCRIPTION
 *  This is the proc function for internet service menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_internet_service_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
            #ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
                mmi_menu_id *root_ids;
                U16 number_of_items;
            #endif /* __MMI_OP12_BRW_EMBEDDED_LINKS__ */
                mmi_brw_app_ui_callback_wap_scr_hide_handler(NULL);
                cui_menu_set_default_title_by_id(menu_evt->sender_id, 
                                            STR_ID_BRW_INTERNET_SERVICES, 
                                            mmi_brw_get_wap_icon());

            #ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
                number_of_items = mmi_brw_app_ui_callback_get_wap_scr_num_of_items(SERVICES_WAP_MENU_ID);
                root_ids = (mmi_menu_id*)srv_brw_malloc(sizeof(mmi_menu_id) * number_of_items);

                cui_menu_set_currlist_title_by_id(menu_evt->sender_id, STR_ID_BRW_INTERNET_SERVICES, mmi_brw_get_wap_icon());
                mmi_brw_app_fill_wap_menu_ids(root_ids);
                cui_menu_set_currlist(menu_evt->sender_id,number_of_items,(mmi_menu_id*)root_ids);
                mmi_brw_app_set_wap_menu_string_and_icon(menu_evt->sender_id, root_ids);
                srv_brw_free(root_ids);
            #endif /* __MMI_OP12_BRW_EMBEDDED_LINKS__ */
            #ifndef __MMI_WGUI_DISABLE_CSK __ 
                cui_menu_enable_center_softkey(menu_evt->sender_id, 0, IMG_GLOBAL_COMMON_CSK);
            #endif
                cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, g_brw_app_cntx.brw_dynamic_cntx_p->wap_highlighted_menu);
            }
             break;
        case EVT_ID_CUI_MENU_LIST_EXIT:
            if(menu_evt->cui_menu_event_flags == CUI_MENU_LIST_FROM_HISTORY)
            {
                mmi_brw_app_GoBackServicesMenu();
            }
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            g_brw_app_cntx.brw_dynamic_cntx_p->wap_highlighted_menu = menu_evt->highlighted_menu_id;
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_brw_app_sh_static_list_delete_scr_handler(evt);
            break;
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_menu_cui_gid = BRW_INTERNET_SERVICE_MENU_GRP;
            break;
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        #ifdef __MMI_OP12_BRW_SEARCH_MENU__
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEARCH_WEB)
            {
                mmi_brw_app_dmgr_open_search_web();
            }
        #endif /* __MMI_OP12_BRW_SEARCH_MENU__ */ 
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_HOMEPAGE)
            {
                mmi_brw_app_dmgr_open_homepage();
            }
        #ifdef __MMI_VBOOKMARK__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BOOKMARKS)
            {
                mmi_brw_app_dmgr_pre_entry_bookmark_list();
            }
        #endif /*__MMI_VBOOKMARK__*/
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_ENTER_ADDRESS)
            {
        #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
               mmi_brw_app_dmgr_pre_entry_enter_url_search_keywords();
        #else
            #ifdef __MMI_FTE_SUPPORT__
                g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_MENU;
            #endif /* __MMI_FTE_SUPPORT__ */   
               mmi_brw_app_dmgr_pre_entry_address_list();
        #endif
            }
        #ifdef OBIGO_Q05A
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_OPEN_FILE)
            {
                mmi_brw_app_if_open_file();
            }
        #endif /* OBIGO_Q05A */
        #ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_LAST_WEB_ADDR)
            {
                mmi_brw_app_dmgr_last_web_address();
            }
        #endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */
        #ifndef __MMI_BRW_RECENT_PAGES_SLIM__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGES)
            {
                mmi_brw_app_pre_entry_recent_page_list();
            }
        #endif
        #ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_STORED_PAGES)
            {
                mmi_brw_app_dmgr_pre_entry_stored_pages_list();
            }
        #endif /* __MMI_WAP_OFFLINE_PAGES_SUPPORT__ */
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SETTINGS)
            {
                mmi_brw_app_if_show_settings_menu();
            }
        #ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
            else if(menu_evt->highlighted_menu_id > BRW_EMBEDDED_LINK_START && menu_evt->highlighted_menu_id < BRW_EMBEDDED_LINK_TOTAL)
            {
                g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item = menu_evt->highlighted_menu_id - BRW_EMBEDDED_LINK_START - 1;
                mmi_brw_app_dmgr_launch_embedded_link();
            }
        #endif /* __MMI_OP12_BRW_EMBEDDED_LINKS__ */
        #ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_DOWNLOADS)
            {
                mmi_brw_app_display_bkgrd_downloads_list();
            }
        #endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */
           break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
                cui_menu_close(menu_evt->sender_id);
            break;
    }
    return MMI_RET_OK;
}


#ifdef __MMI_Q05A_LAUNCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_shortcut_options_menu_cui_proc
 * DESCRIPTION
 *  This is the proc function for shortcut options menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_shortcut_options_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
  	mmi_brw_app_screenDB_struct *scrDB = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                mmi_brw_app_ui_callback_shortcut_options_hide_handler(NULL);
            }
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_brw_app_sh_static_list_delete_scr_handler(evt);
            break;
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_menu_cui_gid = BRW_MENU_CUI_SHORTCUT_OPTIONS;
            break;
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        #ifdef __MMI_OP12_BRW_SEARCH_MENU__
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEARCH_WEB)
            {
                mmi_brw_app_dmgr_open_search_web();
            }
        #endif /* __MMI_OP12_BRW_SEARCH_MENU__ */ 
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_HOMEPAGE)
            {
                mmi_brw_app_dmgr_open_homepage();
            }
        #ifdef __MMI_VBOOKMARK__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BOOKMARKS)
            {
                mmi_brw_app_dmgr_pre_entry_bookmark_list();
            }
        #endif /*__MMI_VBOOKMARK__*/
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_ENTER_ADDRESS)
            {
            #ifdef __MMI_FTE_SUPPORT__
                g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_MENU;
            #endif /* __MMI_FTE_SUPPORT__ */   
               mmi_brw_app_dmgr_pre_entry_address_list();
            }
        #ifdef OBIGO_Q05A
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_OPEN_FILE)
            {
                mmi_brw_app_if_open_file();
            }
        #endif /* OBIGO_Q05A */
        #ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_LAST_WEB_ADDR)
            {
                mmi_brw_app_dmgr_last_web_address();
            }
        #endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */
        #ifndef __MMI_BRW_RECENT_PAGES_SLIM__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGES)
            {
                mmi_brw_app_pre_entry_recent_page_list();
            }
        #endif
        #ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_STORED_PAGES)
            {
                mmi_brw_app_dmgr_pre_entry_stored_pages_list();
            }
        #endif /* __MMI_WAP_OFFLINE_PAGES_SUPPORT__ */
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_LAUNCH_PAGE_SETTINGS)
            {
                mmi_brw_app_if_show_settings_menu();
            }
        #ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_DOWNLOADS)
            {
                mmi_brw_app_display_bkgrd_downloads_list();
            }
        #endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_LAUNCH_PAGE_ADD_SHORTCUT)
            {
                mmi_brw_app_dmgr_pre_entry_add_shortcut();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_LAUNCH_PAGE_GOTO)
            {
                mmi_brw_app_dmgr_launch_shortcut();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_LAUNCH_PAGE_EDIT_SHORTCUT)
            {
                mmi_brw_app_dmgr_pre_entry_edit_shortcut();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_LAUNCH_PAGE_DELETE_SHORTCUT)
            {
                mmi_brw_app_delete_shortcut_confirm();
            }
           break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_close(menu_evt->sender_id);
            }

            break;
    }
    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_bookmarks_options_menu_cui_proc
 * DESCRIPTION
 *  This is the proc function for bookmarks options menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_bookmarks_options_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    hide_hdlr_func_ptr hide_handler;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            hide_handler = mmi_brw_get_hide_handler_for_parent_menu_id(menu_evt->parent_menu_id);
            if (hide_handler != NULL)
            {
                (*(hide_handler)) (NULL);
            }
            //cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;
        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_brw_app_sh_static_list_delete_scr_handler(evt);
            g_brw_app_cntx.brw_menu_cui_gid = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_menu_cui_gid = BRW_MENU_CUI_BOOKMARK_OPT;
            break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_MEMORY_STATUS)
            {
                mmi_brw_app_if_show_memory_status_screen();
            }
        #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_ADD_BOOKMARK)
            {
                mmi_brw_app_dmgr_pre_entry_add_bookmark();
            }
        #endif
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_OPEN_FOLDER)
            {
                mmi_brw_app_dmgr_open_bookmark_folder();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_RENAME_FOLDER)
            {
                mmi_brw_app_dmgr_pre_entry_rename_folder();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_DELETE_FOLDER)
            {
                mmi_brw_app_delete_folder_confirm();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_CREATE_FOLDER)
            {
                mmi_brw_app_dmgr_pre_entry_create_folder();
            }
        #endif
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_GOTO)
            {
                mmi_brw_app_dmgr_launch_bookmark();
            }
        #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_VIEW)
            {
                mmi_chset_utf8_to_ucs2_string((S8*) g_brw_current_title, 
                    SRV_BRW_BKM_MAX_FILE_NAME_LEN * ENCODING_LENGTH,
                    (S8*) g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].title);
                mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*)g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].url);
                mmi_brw_app_if_show_view_bookmark_screen();
            }
        #endif
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_SET_AS_HOMEPAGE)
            {
                mmi_brw_app_set_url_as_homepage(g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].url);
            }
        #endif
        #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_EDIT)
            {
                mmi_brw_app_dmgr_pre_entry_edit_bookmark();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_DELETE_ALL_USER_FILES)
            {
                mmi_brw_app_delete_all_user_files_confirm();
            }
        #endif
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_DELETE)
            {
                mmi_brw_app_delete_bookmark_file_confirm();
            } 
        #if (defined __MMI_BRW_BKM_FOLDER_SUPPORT__ || defined __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_COPY_TO)
            {
                mmi_brw_app_if_copy_bookmark_to();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_MOVE_TO)
            {
                mmi_brw_app_if_move_bookmark_to();
            }
        #endif
    #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_SEND_BOOKMARK_AS_SMS)
            {
                mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*)g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].url);
                mmi_brw_app_if_send_addr_text_msg();
            }
        #if defined(__MMI_MMS__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_SEND_BOOKMARK_AS_MMS)
            {
                mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*)g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].url);
                mmi_brw_app_if_send_addr_multimedia_msg();
            }
        #endif
        #ifdef __MMI_OPP_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_BLUETOOTH)
            {
                mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*)g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].url);
                mmi_brw_app_if_send_addr_via_bluetooth();
            }
        #endif
        #if  defined(__MMI_EMAIL__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_EMAIL)
            {
                mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*)g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].url);
                mmi_brw_app_if_send_addr_via_email();
            }
        #endif
    #endif
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            if (menu_evt->sender_id == g_brw_app_cntx.brw_menu_cid)
            {
                mmi_frm_group_close(g_brw_app_cntx.brw_menu_cui_gid);
            }
            else
            {
                cui_menu_close(menu_evt->sender_id);
            }
            break;
    }
    return MMI_RET_OK;
}

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_browse_path_menu_cui_proc
 * DESCRIPTION
 *  This is the proc function for internet service menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_browse_path_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    hide_hdlr_func_ptr hide_handler;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            hide_handler = mmi_brw_get_hide_handler_for_parent_menu_id(menu_evt->parent_menu_id);
            if (hide_handler != NULL)
            {
                (*(hide_handler)) (NULL);
            }
        #ifndef __MMI_WGUI_DISABLE_CSK __ 
			cui_menu_enable_center_softkey(menu_evt->sender_id, 0, IMG_GLOBAL_COMMON_CSK);
        #endif
             break;
        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_brw_app_sh_static_list_delete_scr_handler(evt);
            g_brw_app_cntx.brw_menu_cui_gid = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_menu_cui_gid = BRW_MENU_CUI_BKM_BROWSE_PATH;
            break;
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_SELECT)
            {
                mmi_brw_app_dmgr_browse_path_select_folder();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_OPEN_FOLDER)
            {
                mmi_brw_app_if_browse_path_open_folder();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_CREATE_FOLDER)
            {
                mmi_brw_app_dmgr_pre_entry_create_folder();
            }
           break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            if (menu_evt->sender_id == g_brw_app_cntx.brw_menu_cid)
            {
                mmi_frm_group_close(g_brw_app_cntx.brw_menu_cui_gid);
            }
            else
            {
                cui_menu_close(menu_evt->sender_id);
            }

            break;
    }
    return MMI_RET_OK;
}
#endif


#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_enter_url_editor_options_menu_cui_proc
 * DESCRIPTION
 *  This is the proc function for input_address endter url editro options menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_enter_url_editor_options_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    hide_hdlr_func_ptr hide_handler;
    U16 scr_id; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_GROUP_DEINIT:
            g_brw_app_cntx.brw_menu_cui_gid = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_menu_cui_gid = BRW_MENU_CUI_EDITOR_OPTIONS;
            break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_EDITOR_OPTION_DONE)
            {
                mmi_brw_app_dmgr_add_search_or_input_url_item();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_EDITOR_OPTION_CANCEL)
            {
                mmi_frm_scrn_close( g_brw_app_cntx.brw_scr_group_id, SCR_ID_BRW_ENTER_URL);
                cui_menu_close(menu_evt->sender_id);
            }
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;
    }
    if(cui_menu_is_menu_event(menu_evt->evt_id))
    {
        wgui_inputs_options_menu_handler(evt, BRW_MENU_CUI_EDITOR_OPTIONS); // app_id is menu cui’s parent groupd ID
    }

    return MMI_RET_OK;
}
#endif /* #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)*/

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_recent_page_menu_cui_proc
 * DESCRIPTION
 *  This is the proc function for recent page options menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_recent_page_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    hide_hdlr_func_ptr hide_handler;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            hide_handler = mmi_brw_get_hide_handler_for_parent_menu_id(menu_evt->parent_menu_id);
            if (hide_handler != NULL)
            {
                (*(hide_handler)) (NULL);
            }
        #ifdef OBIGO_Q05A
            if(menu_evt->parent_menu_id == MENU_ID_BRW_RECENT_PAGE_SORT || menu_evt->parent_menu_id == MENU_ID_BRW_RECENT_HOST_SORT)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                if(menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
                {
                    cui_menu_set_currlist_highlighted_id(menu_evt->sender_id,
                                                         mmi_brw_app_get_highlighted_menu_for_parent_menu_id(menu_evt->parent_menu_id));
                }
            }
        #endif /* OBIGO_Q05A */
            break;
        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_brw_app_sh_static_list_delete_scr_handler(evt);
            g_brw_app_cntx.brw_menu_cui_gid = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_menu_cui_gid = BRW_MENU_CUI_RECENT_PAGE_OPT;
            break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGE_GOTO)
            {
                mmi_brw_app_dmgr_launch_recent_pages_url();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGE_DELETE)
            {
                mmi_brw_app_delete_recent_page_item_confirm();
            }
        #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
        #ifdef __MMI_VBOOKMARK__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGE_ADD_TO_BOOKMARK)
            {
                mmi_brw_app_dmgr_add_recent_page_list_item_to_bookmark();
            }
        #endif /*__MMI_VBOOKMARK__*/
        #endif
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGE_DELETE_ALL)
            {
                mmi_brw_app_delete_all_recent_pages_confirm();
            }
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGE_SET_AS_HOMEPAGE)
            {
                mmi_brw_app_dmgr_set_recent_page_url_as_homepage();
            }
        #endif
        #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_OPTIONS)
            {
                MMI_ASSERT(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_info_p);

                mmi_chset_utf8_to_ucs2_string(
                    (U8*) g_brw_current_url,
                    (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH,
                    (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_info_p->url);
            }
        #endif
        #ifdef OBIGO_Q05A
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGE_OPEN_HOST)
            {
                mmi_brw_app_dmgr_open_recent_page_host();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGE_DELETE_HOST)
            {
                mmi_brw_app_delete_recent_page_host_confirm();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGE_DELETE_ALL_HOST)
            {
                mmi_brw_app_delete_all_recent_pages_confirm();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGE_SORT_BY_LAST_VISITED)
            {
                mmi_brw_app_dmgr_sort_recent_page_by_last_visited();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGE_SORT_BY_MOST_VISITED)
            {
                mmi_brw_app_dmgr_sort_recent_page_by_most_visited();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGE_SORT_BY_SITE)
            {
                mmi_brw_app_dmgr_sort_recent_page_by_site();
            }

        #endif /* OBIGO_Q05A */

    #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
        #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_AS_SMS)
            {
                mmi_brw_app_if_send_addr_text_msg();
            }
        #endif
        #if defined(__MMI_MMS__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_AS_MMS)
            {
                mmi_brw_app_if_send_addr_multimedia_msg();
            }
        #endif
        #if  defined(__MMI_OPP_SUPPORT__)	&&  defined(__MMI_VBOOKMARK__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_VIA_BLUETOOTH)
            {
                mmi_brw_app_if_send_addr_via_bluetooth();
            }
        #endif
        #if  defined(__MMI_EMAIL__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_VIA_EMAIL)
            {
                mmi_brw_app_if_send_addr_via_email();
            }
        #endif
    #endif
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            //cui_menu_close(g_brw_app_cntx.brw_menu_cui_gid);
                if (menu_evt->sender_id == g_brw_app_cntx.brw_menu_cid)
                {
                    mmi_frm_group_close(g_brw_app_cntx.brw_menu_cui_gid);
                }
                else
                {
                    cui_menu_close(menu_evt->sender_id);
                }
             break;
    }
    return MMI_RET_OK;
}
#endif

#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_stored_page_menu_cui_proc
 * DESCRIPTION
 *  This is the proc function for stored page options menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_stored_page_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    hide_hdlr_func_ptr hide_handler;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            hide_handler = mmi_brw_get_hide_handler_for_parent_menu_id(menu_evt->parent_menu_id);
            if (hide_handler != NULL)
            {
                (*(hide_handler)) (NULL);
            }
            //cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;
        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_brw_app_sh_static_list_delete_scr_handler(evt);
            g_brw_app_cntx.brw_menu_cui_gid = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_menu_cui_gid = BRW_MENU_CUI_STORED_PAGE_OPT;
            break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_STORED_PAGE_OPEN)
            {
                mmi_brw_app_dmgr_open_stored_page();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_STORED_PAGE_DELETE)
            {
                mmi_brw_app_delete_stored_page_confirm();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_STORED_PAGE_DELETE_ALL)
            {
                mmi_brw_app_delete_all_stored_page_confirm();
            }
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_STORED_PAGE_SET_AS_HOMEPAGE)
            {
                mmi_brw_app_dmgr_set_stored_page_url_as_homepage();
            }
        #endif
        #ifdef __MMI_VBOOKMARK__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_STORED_PAGE_ADD_TO_BOOKMARK)
            {
                mmi_brw_app_dmgr_add_stored_pages_list_item_to_bookmark();
            }
        #endif /*__MMI_VBOOKMARK__*/
        #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_OPTIONS)
            {
                MMI_ASSERT(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p);

                mmi_chset_utf8_to_ucs2_string(
                    (U8*) g_brw_current_url,
                    (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH,
                    (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->url);
            }
        #endif
        #ifdef OBIGO_Q05A
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_STORED_PAGE_PROPERTIES)
            {
                mmi_brw_app_dmgr_pre_entry_stored_page_properties();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_STORED_PAGE_RENAME)
            {
                mmi_brw_app_dmgr_pre_entry_rename_stored_page();
            }
        #endif
    #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
        #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_AS_SMS)
            {
                mmi_brw_app_if_send_addr_text_msg();
            }
        #endif
        #if defined(__MMI_MMS__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_AS_MMS)
            {
                mmi_brw_app_if_send_addr_multimedia_msg();
            }
        #endif
        #if  defined(__MMI_OPP_SUPPORT__)	&&  defined(__MMI_VBOOKMARK__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_VIA_BLUETOOTH)
            {
                mmi_brw_app_if_send_addr_via_bluetooth();
            }
        #endif
        #if  defined(__MMI_EMAIL__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_VIA_EMAIL)
            {
                mmi_brw_app_if_send_addr_via_email();
            }
        #endif
    #endif
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            //cui_menu_close(g_brw_app_cntx.brw_menu_cui_gid);
                if (menu_evt->sender_id == g_brw_app_cntx.brw_menu_cid)
                {
                    mmi_frm_group_close(g_brw_app_cntx.brw_menu_cui_gid);
                }
                else
                {
                    cui_menu_close(menu_evt->sender_id);
                }
            break;
    }
    return MMI_RET_OK;
}
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_render_page_menu_cui_proc
 * DESCRIPTION
 *  This is the proc function for render page options menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_render_page_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    hide_hdlr_func_ptr hide_handler;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            hide_handler = mmi_brw_get_hide_handler_for_parent_menu_id(menu_evt->parent_menu_id);
            if (hide_handler != NULL)
            {
                (*(hide_handler)) (NULL);
            }
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;
        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_brw_app_sh_static_list_delete_scr_handler(evt);
            g_brw_app_cntx.brw_menu_cui_gid = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_menu_cui_gid = BRW_MENU_CUI_RENDERED_PAGE_OPT;
            break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_EDIT)
            {
                mmi_brw_app_dmgr_rendered_page_edit();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_RESET)
            {
                mmi_brw_app_dmgr_rendered_page_reset();
            }
        #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_SELECT_FILE)
            {
                mmi_brw_app_dmgr_rendered_page_select_file();
            }
        #endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
        #ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_DOWNLOADS)
            {
                mmi_brw_app_display_bkgrd_downloads_list();
            }
        #endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */
        #ifdef __MMI_OP12_BRW_SEARCH_MENU__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEARCH_WEB)
            {
                mmi_brw_app_dmgr_open_search_web();
            }
        #endif /* __MMI_OP12_BRW_SEARCH_MENU__ */ 
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_NAVIGATE_REFRESH)
            {
                mmi_brw_app_dmgr_refresh_page();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_HOMEPAGE)
            {
                mmi_brw_app_dmgr_open_homepage();
            }
        #ifdef __MMI_VBOOKMARK__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BOOKMARKS)
            {
                mmi_brw_app_dmgr_pre_entry_bookmark_list();
            }
        #endif /*__MMI_VBOOKMARK__*/
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_ENTER_ADDRESS)
            {
        #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
               mmi_brw_app_dmgr_pre_entry_enter_url_search_keywords();
        #else
            #ifdef __MMI_FTE_SUPPORT__
                g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_MENU;
            #endif /* __MMI_FTE_SUPPORT__ */   
               mmi_brw_app_dmgr_pre_entry_address_list();
        #endif
            }
        #ifdef OBIGO_Q05A
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_OPEN_FILE)
            {
                mmi_brw_app_if_open_file();
            }
        #endif
        #ifndef __MMI_BRW_RECENT_PAGES_SLIM__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RECENT_PAGES)
            {
                mmi_brw_app_pre_entry_recent_page_list();
            }
        #endif
        #ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_STORED_PAGES)
            {
                mmi_brw_app_dmgr_pre_entry_stored_pages_list();
            }
        #endif /* __MMI_WAP_OFFLINE_PAGES_SUPPORT__ */
        #ifdef __MMI_VBOOKMARK__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_ADD_TO_BOOKMARK)
            {
                mmi_brw_app_dmgr_add_this_page_to_bookmark();
            }
        #endif /*__MMI_VBOOKMARK__*/
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_SELECT_MODE)
            {
                mmi_brw_app_dmgr_rendered_page_select_mode();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_SETTINGS)
            {
                mmi_brw_app_if_show_settings_menu();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_EXIT)
            {
                mmi_brw_app_pre_exit_ren_page();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_GOTO)
            {
                mmi_brw_app_dmgr_launch_this_link();
            }
#ifdef __OP01__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_VIEW_URL)
            {
                mmi_brw_app_if_show_view_url_screen();
            }
#endif /* __OP01__ */
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_SET_AS_HOMEPAGE)
            {
                mmi_brw_app_dmgr_set_this_page_as_homepage();
            }
        #endif
        #ifdef __MMI_VBOOKMARK__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_ADD_TO_BOOKMARK)
            {
                mmi_brw_app_dmgr_add_this_page_to_bookmark();
            }
        #endif /*__MMI_VBOOKMARK__*/

        #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_OPTIONS)
            {
                MMI_ASSERT(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p);

                mmi_chset_utf8_to_ucs2_string(
                    (U8*) g_brw_current_url,
                    (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH,
                    (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url);
            }
        #endif
        #ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_STORE_OFFLINE)
            {
                mmi_brw_app_dmgr_store_this_page();
            }
        #endif /* __MMI_WAP_OFFLINE_PAGES_SUPPORT__ */
        #ifdef OBIGO_Q05A
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_PAGE_OBJECTS)
            {
                mmi_brw_app_if_show_page_object_types();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_PROPERTIES)
            {
                mmi_brw_app_dmgr_pre_entry_this_page_properties();
            }
		#endif /* OBIGO_Q05A */
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SELECT_MODE_SAVE_AS)
            {
                mmi_brw_app_dmgr_select_mode_save_as();
            }
        #ifdef OBIGO_Q05A
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SELECT_MODE_PROPERTIES)
            {
                mmi_brw_app_dmgr_pre_entry_select_mode_image_properties();
            }
        #endif /* OBIGO_Q05A */
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SELECT_MODE_EXIT)
            {
                mmi_brw_app_ren_page_select_mode_rsk_exit();
                /* here it is used for highlighting the default menu item */
                mmi_brw_app_if_show_browser_dummy_screen();
                mmi_frm_scrn_close_active_id();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_NAVIGATE_FORWARD)
            {
                mmi_brw_app_dmgr_navigate_forward();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_NAVIGATE_BACKWARD)
            {
                mmi_brw_app_dmgr_navigate_backward();
            }
#ifndef SLIM_WAP_MMS
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_REN_PAGE_NAVIGATE_PAGE_ACTIONS)
            {
                mmi_brw_app_if_show_page_actions_list();
            }
#endif
    #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
        #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_AS_SMS)
            {
                mmi_brw_app_if_send_addr_text_msg();
            }
        #endif
        #if defined(__MMI_MMS__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_AS_MMS)
            {
                mmi_brw_app_if_send_addr_multimedia_msg();
            }
        #endif
        #if  defined(__MMI_OPP_SUPPORT__)	&&  defined(__MMI_VBOOKMARK__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_VIA_BLUETOOTH)
            {
                mmi_brw_app_if_send_addr_via_bluetooth();
            }
        #endif
        #if  defined(__MMI_EMAIL__)
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SEND_ADDRESS_VIA_EMAIL)
            {
                mmi_brw_app_if_send_addr_via_email();
            }
        #endif
    #endif

            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            //cui_menu_close(g_brw_app_cntx.brw_menu_cui_gid);
                if (menu_evt->sender_id == g_brw_app_cntx.brw_menu_cid)
                {
                    mmi_frm_group_close(g_brw_app_cntx.brw_menu_cui_gid);
                }
                else
                {
                    cui_menu_close(menu_evt->sender_id);
                }
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_settings_menu_cui_proc
 * DESCRIPTION
 *  This is the proc function for settings options menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_settings_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    hide_hdlr_func_ptr hide_handler = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            hide_handler = mmi_brw_get_hide_handler_for_parent_menu_id(menu_evt->parent_menu_id);
            if (hide_handler != NULL)
            {
                (*(hide_handler)) (NULL);
            }
        #ifndef __MMI_WGUI_DISABLE_CSK __ 
            cui_menu_enable_center_softkey(menu_evt->sender_id, 0, IMG_GLOBAL_COMMON_CSK);
        #endif
            cui_menu_set_default_title_by_id(menu_evt->sender_id, 
                            GetStringIdOfItem(menu_evt->parent_menu_id), 
                            mmi_brw_get_wap_icon());

            switch(menu_evt->parent_menu_id)
            {
        #if (defined(OBIGO_Q05A) || !defined(__MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__))
			#ifdef OBIGO_Q05A
                case MENU_ID_BRW_BROWSER_OPTIONS_RENDERING_MODES:
                case MENU_ID_BRW_BROWSER_OPTIONS_NAVIGATION_MODES:
			#ifdef __MMI_VECTOR_FONT_SUPPORT__
                case MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE:
			#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
			#endif /* OBIGO_Q05A */
            #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
                case MENU_ID_BRW_SETTINGS_HOMEPAGE:
            #endif
                    {
                        cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                        if(menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
                        {
                            cui_menu_set_currlist_highlighted_id(menu_evt->sender_id,
                                                                 mmi_brw_app_get_highlighted_menu_for_parent_menu_id(menu_evt->parent_menu_id));
                        }
                    }
                    break ;
            #endif

                default :
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    break;
            }
            if(menu_evt->parent_menu_id == MENU_ID_BRW_BROWSER_OPTIONS)
            {
            #ifdef OBIGO_Q05A
                cui_menu_set_item_hint(
                            menu_evt->sender_id, 
                            MENU_ID_BRW_BROWSER_OPTIONS_RENDERING_MODES, 
                            (UI_string_type)mmi_brw_app_ui_plugin_get_rendering_mode_hint());
                cui_menu_set_item_hint(
                            menu_evt->sender_id, 
                            MENU_ID_BRW_BROWSER_OPTIONS_NAVIGATION_MODES, 
                            (UI_string_type)mmi_brw_app_ui_plugin_get_navigation_mode_hint());
                #ifdef __MMI_VECTOR_FONT_SUPPORT__
                    cui_menu_set_item_hint(
                                menu_evt->sender_id, 
                                MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE, 
                                (UI_string_type)mmi_brw_app_ui_plugin_get_font_size_hint());
                #endif /*__MMI_VECTOR_FONT_SUPPORT__*/ 
                cui_menu_set_item_hint(
                            menu_evt->sender_id, 
                            MENU_ID_BRW_BROWSER_OPTIONS_THUMBNAIL, 
                            (UI_string_type)mmi_brw_app_ui_plugin_get_thumbnail_hint());
                cui_menu_set_item_hint(
                            menu_evt->sender_id, 
                            MENU_ID_BRW_BROWSER_OPTIONS_SCREEN_SIZE, 
                            (UI_string_type)mmi_brw_app_ui_plugin_get_screen_size_hint());
                cui_menu_set_item_hint(
                            menu_evt->sender_id, 
                            MENU_ID_BRW_BROWSER_OPTIONS_ENCODING, 
                            (UI_string_type)mmi_brw_app_ui_plugin_get_encoding_method_hint());
            #endif
#ifdef __BAIDU_TRANSCODING_SUPPORT__
                cui_menu_set_item_hint(
                            menu_evt->sender_id, 
                            MENU_ID_BRW_BROWSER_OPTIONS_USE_BAIDU_PROXY, 
                            (UI_string_type)mmi_brw_app_ui_plugin_get_baidu_proxy_hint());
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
            #ifdef __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__
                cui_menu_set_item_hint(
                            menu_evt->sender_id, 
                            MENU_ID_BRW_BROWSER_OPTIONS_9WAY, 
                            (UI_string_type)mmi_brw_app_ui_plugin_get_nine_way_hint());
            #endif /* __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__ */
            }
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            else if (menu_evt->parent_menu_id == MENU_ID_BRW_SETTINGS)
            {
                cui_menu_set_item_hint(
                            menu_evt->sender_id, 
                            MENU_ID_BRW_SETTINGS_HOMEPAGE, 
                            (UI_string_type)mmi_brw_app_ui_plugin_get_homepage_setting_hint());
            }
        #endif
        }
        break;
        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_brw_app_sh_static_list_delete_scr_handler(evt);
            g_brw_app_cntx.brw_menu_cui_gid = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_menu_cui_gid = BRW_MENU_CUI_SETTINGS;
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            if(menu_evt->parent_menu_id == MENU_ID_BRW_BROWSER_OPTIONS)
            {
            #ifdef OBIGO_Q05A
                if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_THUMBNAIL)
                {
                    if (g_srv_brw_cntx.thumbnail_status == wap_bam_setting_val_thumb_enable)
                    {
                        cui_menu_change_left_softkey_string_by_id(menu_evt->sender_id, STR_GLOBAL_OFF);
                    }
                    else
                    {
                        cui_menu_change_left_softkey_string_by_id(menu_evt->sender_id, STR_GLOBAL_ON);
                    }
                }
                else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_SCREEN_SIZE)
                {
                    if (g_srv_brw_cntx.screen_size_status)
                    {
                        cui_menu_change_left_softkey_string_by_id(menu_evt->sender_id, STR_GLOBAL_NORMAL);
                    }
                    else
                    {
                        cui_menu_change_left_softkey_string_by_id(menu_evt->sender_id, STR_ID_BRW_FULL);
                    }
                }
                else
            #endif /* OBIGO_Q05A */
#ifdef __BAIDU_TRANSCODING_SUPPORT__
                if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_USE_BAIDU_PROXY)
                {
                    if (g_srv_brw_cntx.baidu_proxy_status)
                    {
                        cui_menu_change_left_softkey_string_by_id(menu_evt->sender_id, STR_GLOBAL_OFF);
                    }
                    else
                    {
                        cui_menu_change_left_softkey_string_by_id(menu_evt->sender_id, STR_GLOBAL_ON);
                    }
                }
                else
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
            #ifdef __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__
                if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_9WAY)
                {
                    if (g_brw_app_cntx.nine_way_mode)
                    {
                        cui_menu_change_left_softkey_string_by_id(menu_evt->sender_id, STR_GLOBAL_OFF);
                    }
                    else
                    {
                        cui_menu_change_left_softkey_string_by_id(menu_evt->sender_id, STR_GLOBAL_ON);
                    }
                }
                else
            #endif /* __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__ */
                {
                    cui_menu_change_left_softkey_string_by_id(menu_evt->sender_id, STR_GLOBAL_OK);
                }
            }
            break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_DATA_ACCOUNT)
            {
                mmi_brw_app_if_show_profile_list();
            }
       #ifdef OBIGO_Q05A
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_THUMBNAIL)
            {
                mmi_brw_app_dmgr_update_thumbnail_status();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_SCREEN_SIZE)
            {
                mmi_brw_app_dmgr_update_screen_size();
            }
        #endif /* OBIGO_Q05A */
        #ifndef SLIM_WAP_MMS
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_CACHE)
            {
                mmi_brw_app_clear_cache_confirm();
            }
        #endif
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_COOKIE)
            {
                mmi_brw_app_clear_cookie_confirm();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_AUTH_INFO)
            {
                mmi_brw_app_clear_auth_confirm();
            }
        #ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_SEARCH_HISTORY)
            {
                mmi_brw_app_clear_search_history_confirm();
            }
        #endif
        #ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_URL_HISTORY)
            {
                mmi_brw_app_clear_url_history_confirm();
            }
        #endif
        #ifdef WAP_SEC_SUPPORT
        #ifdef OBIGO_Q05A
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SECURITY_SETTINGS_SESSION_INFO)
            {
                g_brw_app_cntx.brw_dynamic_cntx_p->view_type = BRW_VIEW_CURRENT_SESSION_INFO;
                mmi_brw_app_if_show_view_certificate_screen();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SECURITY_SETTINGS_CURRENT_CERTIFICATE)
            {
                g_brw_app_cntx.brw_dynamic_cntx_p->view_type = BRW_VIEW_CURRENT_CERTIFICATE;
                mmi_brw_app_if_show_view_certificate_screen();
            }
        #endif
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SECURITY_SETTINGS_TRUSTED_CERTIFICATES)
            {
                mmi_brw_app_if_show_trusted_certificates_list();
            }
        #endif /* WAP_SEC_SUPPORT */
        #ifdef OBIGO_Q05A
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RENDERING_MODES_STANDARD)
            {
                mmi_brw_app_dmgr_rendering_modes_standard();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RENDERING_MODES_TEXT_WRAP)
            {
                mmi_brw_app_dmgr_rendering_modes_text_wrap();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RENDERING_MODES_SCREEN_OPTIMIZED)
            {
                mmi_brw_app_dmgr_rendering_modes_screen_optimized();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RENDERING_MODES_TEXT_ONLY)
            {
                mmi_brw_app_dmgr_rendering_modes_text_only();
            }
       #endif /* OBIGO_Q05A */
        #ifdef OBIGO_Q05A
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_NAVIGATION_MODES_FOUR_WAY)
            {
                mmi_brw_app_dmgr_navigation_modes_four_way();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_NAVIGATION_MODES_TWO_WAY)
            {
                mmi_brw_app_dmgr_navigation_modes_two_way();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_NAVIGATION_MODES_SCROLLING)
            {
                mmi_brw_app_dmgr_navigation_modes_scrolling();
            }
        #endif /* OBIGO_Q05A */

        #ifdef OBIGO_Q05A
        #ifdef __MMI_VECTOR_FONT_SUPPORT__
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_SMALL)
            {
                mmi_brw_app_dmgr_font_size_small();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_MEDIUM)
            {
                mmi_brw_app_dmgr_font_size_medium();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_LARGE)
            {
                mmi_brw_app_dmgr_font_size_large();
            }
        #endif /* __MMI_VECTOR_FONT_SUPPORT__ */
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_ENCODING)
            {
                mmi_brw_app_if_show_encoding_methods();
            }
        #endif /* OBIGO_Q05A */
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_PREFERENCES)
            {
                mmi_brw_app_if_show_browser_preferences_screen();
            }
        #ifdef __MMI_CBM_CONNECTION_MANAGER__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SETTINGS_CONNECTION_INFO)
            {
                mmi_brw_app_if_show_connection_info();
            }
        #endif /* __MMI_CBM_CONNECTION_MANAGER__ */
        #ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_RESTORE_BROWSER_SETTINGS)
            {
                mmi_brw_app_restore_browser_settings_confirm();
            }
        #endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */
        #ifdef __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_9WAY)
            {
                mmi_brw_app_dmgr_update_9way_mode();
            }
        #endif /* __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__ */
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SETTING_HOMEPAGE_DEFAULT)
            {
                mmi_brw_app_dmgr_update_homepage_setting(SRV_BRW_HOMEPAGE_SETTING_DEFAULT);
                mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
                mmi_frm_group_close(BRW_MENU_CUI_SETTINGS);
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_SETTING_HOMEPAGE_USER_DEFINED)
            {
                mmi_brw_app_dmgr_pre_entry_homepage_edit();
            }
        #endif
#ifdef __BAIDU_TRANSCODING_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BROWSER_OPTIONS_USE_BAIDU_PROXY)
            {
                mmi_brw_app_dmgr_update_baidu_proxy_status();
            }
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            //cui_menu_close(g_brw_app_cntx.brw_menu_cui_gid);
                if (menu_evt->sender_id == g_brw_app_cntx.brw_menu_cid)
                {
                    mmi_frm_group_close(g_brw_app_cntx.brw_menu_cui_gid);
                }
                else
                {
                    cui_menu_close(menu_evt->sender_id);
                }
                break;
    }
    return MMI_RET_OK;
}

#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_encoding_methods_cui_proc
 * DESCRIPTION
 *  This is the proc function for settings options menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_encoding_methods_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    hide_hdlr_func_ptr hide_handler = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            mmi_menu_id *root_ids;
            U16 number_of_items = (U16)bam_get_total_charset_num();
            cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_BRW_BROWSER_OPTIONS_ENCODING, MMI_TRUE);
        #ifndef __MMI_WGUI_DISABLE_CSK __ 
            cui_menu_enable_center_softkey(menu_evt->sender_id, 0, IMG_GLOBAL_COMMON_CSK);
        #endif
            cui_menu_set_default_title_by_id(menu_evt->sender_id, 
                            STR_ID_BRW_ENCODING, 
                            mmi_brw_get_wap_icon());

            root_ids = (mmi_menu_id*)srv_brw_malloc(sizeof(mmi_menu_id) * number_of_items);

            cui_menu_set_currlist_title_by_id(menu_evt->sender_id, STR_ID_BRW_ENCODING, mmi_brw_get_wap_icon());
            mmi_brw_app_fill_encoding_menu_ids(root_ids);
            cui_menu_set_currlist(menu_evt->sender_id,number_of_items,(mmi_menu_id*)root_ids);
            mmi_brw_app_set_emcoding_menu_string_and_icon(menu_evt->sender_id, root_ids);
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            if(menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
            {
                cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, BRW_ENCODING_START + g_srv_brw_cntx.encoding_method_index + 1);
            }
            srv_brw_free(root_ids);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_brw_app_sh_static_list_delete_scr_handler(evt);
            g_brw_app_cntx.brw_menu_cui_gid = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_menu_cui_gid = BRW_MENU_CUI_ENCODING_METHODS;
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            if(menu_evt->highlighted_menu_id > BRW_ENCODING_START && menu_evt->highlighted_menu_id < BRW_ENCODING_TOTAL)
            {
                g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item = menu_evt->highlighted_menu_id - BRW_ENCODING_START - 1;
                mmi_brw_app_dmgr_update_encoding_method();
                cui_menu_close(menu_evt->sender_id);
            }
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
                if (menu_evt->sender_id == g_brw_app_cntx.brw_menu_cid)
                {
                    mmi_frm_group_close(g_brw_app_cntx.brw_menu_cui_gid);
                }
                else
                {
                    cui_menu_close(menu_evt->sender_id);
                }
        break;
    }
    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_settings_trusted_certificate_options_menu_cui_proc
 * DESCRIPTION
 *  This is the proc function for security settings menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_settings_trusted_certificate_options_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    hide_hdlr_func_ptr hide_handler = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            hide_handler = mmi_brw_get_hide_handler_for_parent_menu_id(menu_evt->parent_menu_id);
            if (hide_handler != NULL)
            {
                (*(hide_handler)) (NULL);
            }
            //cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;
        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_brw_app_sh_static_list_delete_scr_handler(evt);
            g_brw_app_cntx.brw_menu_cui_gid = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_menu_cui_gid = BRW_MENU_CUI_SECURITY_SETTINGS;
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
		#ifdef WAP_SEC_SUPPORT
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS_VIEW)
            {
                g_brw_app_cntx.brw_dynamic_cntx_p->view_type = BRW_VIEW_TRUSTED_CERTIFICATE;
                mmi_brw_app_if_show_view_certificate_screen();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS_DELETE)
            {
                mmi_brw_app_dmgr_delete_trusted_certificates();
            }
            break;
		#endif /* WAP_SEC_SUPPORT */
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            //cui_menu_close(g_brw_app_cntx.brw_menu_cui_gid);
                if (menu_evt->sender_id == g_brw_app_cntx.brw_menu_cid)
                {
                    mmi_frm_group_close(g_brw_app_cntx.brw_menu_cui_gid);
                }
                else
                {
                    cui_menu_close(menu_evt->sender_id);
                }
                break;
    }
    return MMI_RET_OK;
}

#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_bookmark_in_fmgr_menu_cui_proc
 * DESCRIPTION
 *  This is the proc function for select profile menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_bookmark_in_fmgr_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
        #ifndef __MMI_WGUI_DISABLE_CSK __ 
			cui_menu_enable_center_softkey(menu_evt->sender_id, 0, IMG_GLOBAL_COMMON_CSK);
        #endif
            break;

        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_brw_app_sh_static_list_delete_scr_handler(evt);
            g_brw_app_cntx.brw_menu_cui_gid = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_menu_cui_gid = BRW_MENU_CUI_BOOKMARKS_IN_FMGR;
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_ADD_TO_BOOKMARK_FROM_FMGR)
            {
                mmi_brw_app_dmgr_add_to_bookmark_from_fmgr();
            }
        #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_VIEW)
            {
                mmi_ucs2cpy((S8*) g_brw_current_title, (S8*) g_brw_ext_bkm_cntx_p->bookmark_name);
                mmi_ucs2cpy((S8*) g_brw_current_url, (S8*) g_brw_ext_bkm_cntx_p->bookmark_url);
                mmi_brw_app_if_show_view_bookmark_screen();
            }
        #endif
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_BKM_SET_AS_HOMEPAGE)
            {
                U8 url_ascii[SRV_BRW_MAX_URL_LEN + 1];
                mmi_ucs2_to_asc((S8*) url_ascii, (S8*) g_brw_ext_bkm_cntx_p->bookmark_url);
                mmi_brw_app_set_url_as_homepage(url_ascii);
            }
        #endif
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            //cui_menu_close(g_brw_app_cntx.brw_menu_cui_gid);
                if (menu_evt->sender_id == g_brw_app_cntx.brw_menu_cid)
                {
                    mmi_frm_group_close(g_brw_app_cntx.brw_menu_cui_gid);
                }
                else
                {
                    cui_menu_close(menu_evt->sender_id);
                }
                break;
    }
    return MMI_RET_OK;
}
#endif


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_objects_options_menu_cui_proc
 * DESCRIPTION
 *  This is the proc function for select profile menu cui
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_objects_options_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    hide_hdlr_func_ptr hide_handler = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            hide_handler = mmi_brw_get_hide_handler_for_parent_menu_id(menu_evt->parent_menu_id);
            if (hide_handler != NULL)
            {
                (*(hide_handler)) (NULL);
            }
            break;

        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_GROUP_DEINIT:
            mmi_brw_app_sh_static_list_delete_scr_handler(evt);
            g_brw_app_cntx.brw_menu_cui_gid = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_menu_cui_gid = BRW_MENU_CUI_PAGE_OBJECTS_OPTION;
            break;
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
            if(menu_evt->highlighted_menu_id == MENU_ID_BRW_PAGE_OBJECTS_SAVE_AS)
            {
				mmi_brw_app_dmgr_save_page_object();
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_BRW_PAGE_OBJECTS_PROPERTIES)
            {
                mmi_brw_app_dmgr_pre_entry_page_object_properties();
            }
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            //cui_menu_close(g_brw_app_cntx.brw_menu_cui_gid);
                if (menu_evt->sender_id == g_brw_app_cntx.brw_menu_cid)
                {
                    mmi_frm_group_close(g_brw_app_cntx.brw_menu_cui_gid);
                }
                else
                {
                    cui_menu_close(menu_evt->sender_id);
                }
                break;
    }
    return MMI_RET_OK;
}
#endif /* OBIGO_Q05A */

/*  End of Menu CUI Procs */ 

/* Inline CUI procs */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bkm_save_bookmark_proc
 * DESCRIPTION
 *  This is the proc function for save bookmark inline CUI
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_bkm_save_bookmark_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            g_brw_app_cntx.brw_inline_cid = GRP_ID_INVALID;
			g_brw_app_cntx.brw_inline_cui_gid = GRP_ID_INVALID;
        }
        break;
        case EVT_ID_CUI_INLINE_SET_KEY:
            {
                cui_event_inline_set_key_struct *notify = (cui_event_inline_set_key_struct *)evt;
                cui_inline_set_softkey_text(notify->sender_id, BRW_INLINE_TITLE, MMI_LEFT_SOFTKEY, STR_GLOBAL_SAVE);
                cui_inline_set_softkey_text(notify->sender_id, BRW_INLINE_URL, MMI_LEFT_SOFTKEY, STR_GLOBAL_SAVE);
            #ifndef __MMI_WGUI_DISABLE_CSK __ 
				cui_inline_set_softkey_icon(
						notify->sender_id, 
						BRW_INLINE_TITLE, 
						MMI_CENTER_SOFTKEY, 
						IMG_GLOBAL_COMMON_CSK);
				cui_inline_set_softkey_icon(
						notify->sender_id, 
						BRW_INLINE_URL, 
						MMI_CENTER_SOFTKEY, 
						IMG_GLOBAL_COMMON_CSK);
            #endif
                break;
            }

        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_inline_cui_gid = BRW_INLINE_GRP_ID;
            break;

        case EVT_ID_CUI_INLINE_NOTIFY:
            break;

        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            mmi_brw_app_dmgr_save_to_bookmark();
            break;
        case EVT_ID_CUI_INLINE_ABORT:
                cui_inline_close(g_brw_app_cntx.brw_inline_cid);
            break;
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            cui_event_inline_common_struct *inline_common_event = (cui_event_inline_common_struct*)evt;
            g_brw_app_cntx.brw_inline_cid = inline_common_event->sender_id;
            cui_inline_set_title_string_with_string_id(inline_common_event->sender_id, STR_ID_BRW_SAVE_BOOKMARK);
        #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
            wgui_register_list_tap_callback(mmi_brw_app_ui_callback_save_bookmark_inline_tap_callback);
        #endif
            break;
        }
    }

    return MMI_RET_OK;
}


#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bkm_add_bookmark_inline_cui_proc
 * DESCRIPTION
 *  This is the proc function for add bookmark inline CUI
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_bkm_add_bookmark_inline_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 screen_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            g_brw_app_cntx.brw_inline_cid = GRP_ID_INVALID;
            g_brw_app_cntx.brw_inline_cui_gid = GRP_ID_INVALID;
            break;
        }
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_inline_cui_gid = BRW_ADD_BOOKMARK_GRP_ID;
            break;

        case EVT_ID_CUI_INLINE_SET_KEY:
            {
                cui_event_inline_set_key_struct *notify = (cui_event_inline_set_key_struct *)evt;

                if ((notify->item_id == BRW_INLINE_TITLE))
                {
                    //ChangeLeftSoftkey(STR_GLOBAL_EDIT, IMG_GLOBAL_OK);
                    cui_inline_set_softkey_text(notify->sender_id, BRW_INLINE_TITLE, MMI_LEFT_SOFTKEY, STR_GLOBAL_EDIT);
                    wgui_inline_set_lsk_function(mmi_brw_app_if_show_edit_bookmark_naming_rule_screen);
                #ifndef __MMI_WGUI_DISABLE_CSK __ 
					cui_inline_set_softkey_icon(
						notify->sender_id, 
						BRW_INLINE_TITLE, 
						MMI_CENTER_SOFTKEY, 
						IMG_GLOBAL_COMMON_CSK);
					SetCenterSoftkeyFunction(mmi_brw_app_if_show_edit_bookmark_naming_rule_screen, KEY_EVENT_UP);
                #endif
                }
                break;
            }
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                        BRW_INLINE_TITLE,
                        g_brw_current_title);
            cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                        BRW_INLINE_URL,
                        g_brw_current_url);

            screen_id = cui_inline_get_parent_data(g_brw_app_cntx.brw_inline_cid);
            if (screen_id == SCR_ID_BRW_ADD_BOOKMARK || screen_id == SCR_ID_BRW_ADD_TO_BOOKMARK)
            {
                mmi_brw_app_dmgr_add_bookmark();
            }
            else
            {
                mmi_brw_app_dmgr_edit_bookmark();
            }
            break;			
        }

        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_inline_close(g_brw_app_cntx.brw_inline_cid);
            break;
        }
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            cui_event_inline_common_struct *inline_common_event = (cui_event_inline_common_struct*)evt;
            g_brw_app_cntx.brw_inline_cid = inline_common_event->sender_id;
            if (g_brw_bkm_add_type == BRW_BKM_ADD_TO_BOOKMARK)
            {
                cui_inline_set_screen_attributes(g_brw_app_cntx.brw_inline_cid, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
            }
        #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
            wgui_register_list_tap_callback(mmi_brw_app_ui_callback_add_bookmark_inline_tap_callback);
        #endif
            break;
        }
    }

    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_pref_inline_cui_proc
 * DESCRIPTION
 *  This is the proc function for Browser Preferences inline CUI
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_settings_pref_inline_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            g_brw_app_cntx.brw_inline_cid = GRP_ID_INVALID;
            g_brw_app_cntx.brw_inline_cui_gid = GRP_ID_INVALID;
        }
        break;

        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_inline_cui_gid = BRW_INLINE_GRP_ID;
            break;

        case EVT_ID_CUI_INLINE_NOTIFY:
            break;

        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SUBMIT:
                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                        BRW_PREFERENCES_INLINE_TIMEOUT_EDIT,
                                        g_brw_app_cntx.brw_dynamic_cntx_p->BrwTimeoutValue);

                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                      BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT,
                                      &g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
            #ifdef OBIGO_Q05A
                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                      BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT,
                                      &g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT - CUI_INLINE_ITEM_ID_BASE)]);

                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                      BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT,
                                      &g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT - CUI_INLINE_ITEM_ID_BASE)]);

                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                      BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT,
                                      &g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT - CUI_INLINE_ITEM_ID_BASE)]);

                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                      BRW_PREFERENCES_INLINE_CSS_SELECT,
                                      &g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_CSS_SELECT - CUI_INLINE_ITEM_ID_BASE)]);

                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                      BRW_PREFERENCES_INLINE_SCRIPT_SELECT,
                                      &g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SCRIPT_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
            #endif /* OBIGO_Q05A */
            #ifndef SLIM_WAP_MMS
                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                      BRW_PREFERENCES_INLINE_CACHE_SELECT,
                                      &g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_CACHE_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
            #endif
                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                      BRW_PREFERENCES_INLINE_COOKIE_SELECT,
                                      &g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_COOKIE_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
            #ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                      BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT,
                                      &g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
        
            #endif 
            #ifdef BRW_SECURITY_WARNINGS_SUPPORT
                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                      BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT,
                                      &g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
        
            #endif 
            #ifdef BRW_SEND_DEVICE_ID_SUPPORT
                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                      BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT,
                                      &g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
       
            #endif 
            #ifdef __MMI_BRW_POST_SESSION_INFO__
                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                      BRW_PREFERENCES_INLINE_POST_SESSION_INFO_SELECT,
                                      &g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_POST_SESSION_INFO_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
        
            #endif
            mmi_brw_app_dmgr_save_browser_preferences();
            break;

        case EVT_ID_CUI_INLINE_ABORT:
                cui_inline_close(g_brw_app_cntx.brw_inline_cid);
                mmi_frm_group_close(g_brw_app_cntx.brw_inline_cui_gid);                
            break;
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            cui_event_inline_common_struct *inline_common_event = (cui_event_inline_common_struct*)evt;
            g_brw_app_cntx.brw_inline_cid = inline_common_event->sender_id;
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_authentication_inline_cui_proc
 * DESCRIPTION
 *  This function is the proc function for the authentication dialog screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_authentication_inline_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            g_brw_app_cntx.brw_inline_cid = GRP_ID_INVALID;
			g_brw_app_cntx.brw_inline_cui_gid = GRP_ID_INVALID;
        }
        break;

        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_inline_cui_gid = BRW_INLINE_GRP_ID;
            break;

        case EVT_ID_CUI_INLINE_NOTIFY:
            break;

        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SUBMIT:
                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                        BRW_AUTH_DLG_INLINE_USERNAME,
                                        g_brw_auth_username);

                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                        BRW_AUTH_DLG_INLINE_PASSWORD,
                                        g_brw_auth_password);
            #ifdef OBIGO_Q05A
                cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                                        BRW_AUTH_DLG_INLINE_SAVE_OPTION,
                                        &g_brw_auth_dlg_save_option);
            #endif /* OBIGO_Q05A */

            if(mmi_ucs2strlen((S8*)g_brw_auth_username))
            {
            #ifdef OBIGO_Q03C
                mmi_brw_app_send_auth_dlg_ok_rsp();
            #else
                mmi_brw_app_send_auth_dlg_ok_rsp();
            #endif
            }
            else
            {
                mmi_brw_app_ui_draw_display_popup_ext(STR_ID_BRW_PLEASE_INPUT_USERNAME, MMI_EVENT_FAILURE);
            }
            break;
        case EVT_ID_CUI_INLINE_ABORT:
                mmi_brw_app_send_auth_dlg_cancel_rsp();
                break;
        case EVT_ID_GROUP_DELETE_REQ:
            break;
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            cui_event_inline_common_struct *inline_common_event = (cui_event_inline_common_struct*)evt;
            g_brw_app_cntx.brw_inline_cid = inline_common_event->sender_id;
            break;
        }
    }

    return MMI_RET_OK;
}

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
mmi_ret mmi_brw_edit_shortcut_inline_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_brw_app_screenDB_struct *scrDB = NULL;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            scrDB = (mmi_brw_app_screenDB_struct *)evt->user_data;
            if (scrDB && (NULL != scrDB->screen))
            {
                srv_brw_free(scrDB->screen);
                scrDB->screen = NULL;
            }
            g_brw_app_cntx.brw_inline_cid = GRP_ID_INVALID;
            g_brw_app_cntx.brw_inline_cui_gid = GRP_ID_INVALID;
            break;
        }
        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_inline_cui_gid = BRW_INLINE_GRP_ID;
            break;

        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                        BRW_INLINE_TITLE,
                        g_brw_current_title);
            cui_inline_get_value(g_brw_app_cntx.brw_inline_cid,
                        BRW_INLINE_URL,
                        g_brw_current_url);

            mmi_brw_app_save_shortcut_confirm();
            break;			
        }

        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_inline_close(g_brw_app_cntx.brw_inline_cid);
            break;
        }
    }
    return MMI_RET_OK;
}
#endif

#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_properties_proc
 * DESCRIPTION
 *  This function is the proc function for the authentication dialog screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_brw_app_properties_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            g_brw_app_cntx.brw_inline_cid = GRP_ID_INVALID;
			g_brw_app_cntx.brw_inline_cui_gid = GRP_ID_INVALID;
        }
        break;

        case EVT_ID_GROUP_ACTIVE:
            g_brw_app_cntx.brw_inline_cui_gid = BRW_INLINE_GRP_ID;
            break;

        case EVT_ID_CUI_INLINE_NOTIFY:
            break;

        case EVT_ID_CUI_INLINE_SUBMIT:
            break;
        case EVT_ID_CUI_INLINE_ABORT:
                cui_inline_close(g_brw_app_cntx.brw_inline_cid);
            break;
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            cui_event_inline_common_struct *inline_common_event = (cui_event_inline_common_struct*)evt;
            g_brw_app_cntx.brw_inline_cid = inline_common_event->sender_id;
            mmi_brw_properties_inline_cui_update_item_icon();
            break;
        }
    }

    return MMI_RET_OK;
}
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_browser_preferences_write_inline_struct
 * DESCRIPTION
 *  This function is to fill the preferences structure with the current
 * settings to be displayed in the preferences screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_browser_preferences_write_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /****************** Time Out ******************/
    srv_brw_convert_int_to_unicode_string(g_brw_app_cntx.brw_dynamic_cntx_p->BrwTimeoutValue, (U32) g_srv_brw_cntx.timeout_value);
   /****************** Time Out ******************/

   /****************** Show Images ******************/
    if (g_srv_brw_cntx.show_images_status == wap_bam_setting_val_images_never)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_NEVER_INDEX;
    }
    else
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_ALWAYS_INDEX;
    }
   /****************** Show Images ******************/

#ifdef OBIGO_Q05A

   /****************** Show Videos ******************/
    if (g_srv_brw_cntx.show_videos_status == wap_bam_setting_val_movies_never)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_NEVER_INDEX;
    }
    else
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_ALWAYS_INDEX;
    }
   /****************** Show Videos ******************/

   /****************** Play Sounds ******************/
    if (g_srv_brw_cntx.play_sounds_status == wap_bam_setting_val_sounds_never)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_NEVER_INDEX;
    }
    else
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_ALWAYS_INDEX;
    }
   /****************** Play Sounds ******************/

   /****************** Load Unknown Media ******************/
    if (g_srv_brw_cntx.load_unknown_media_status == wap_bam_setting_val_no_mime_never)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_NEVER_INDEX;
    }
    else
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_ALWAYS_INDEX;
    }
   /****************** Load Unknown Media ******************/

   /****************** CSS ******************/
    if (g_srv_brw_cntx.css_status == wap_bam_setting_val_css_disable)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_CSS_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_DISABLE_INDEX;
    }
    else
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_CSS_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_ENABLE_INDEX;
    }
   /****************** CSS ******************/

   /****************** Script ******************/
    if (g_srv_brw_cntx.script_status == wap_bam_setting_val_script_disable)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SCRIPT_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_DISABLE_INDEX;
    }
    else
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SCRIPT_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_ENABLE_INDEX;
    }
   /****************** Script ******************/

#endif /* OBIGO_Q05A */

#ifndef SLIM_WAP_MMS
    /****************** Cache ******************/
    if (g_srv_brw_cntx.cache_status == wap_bam_setting_val_cache_disable)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_CACHE_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_DISABLE_INDEX;
    }
    else
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_CACHE_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_ENABLE_INDEX;
    }
   /****************** Cache ******************/
#endif
   /****************** Cookie ******************/
    if (g_srv_brw_cntx.cookie_status == wap_bam_setting_val_cookies_disable)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_COOKIE_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_DISABLE_INDEX;
    }
    else
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_COOKIE_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_ENABLE_INDEX;
    }
   /****************** Cookie ******************/

   /****************** Shortcuts ******************/
#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
    if (g_srv_brw_cntx.shortcuts_status == wap_bam_setting_val_shortcuts_disable)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_DISABLE_INDEX;
    }
    else
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_ENABLE_INDEX;
    }
   /****************** Shortcuts ******************/
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */ 

#ifdef BRW_SECURITY_WARNINGS_SUPPORT
   /****************** Security Warnings ******************/
    if (g_srv_brw_cntx.security_warnings_status == wap_bam_setting_val_sec_warning_disable)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_DISABLE_INDEX;
    }
    else
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_ENABLE_INDEX;
    }
   /****************** Security Warnings ******************/
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */ 

#ifdef BRW_SEND_DEVICE_ID_SUPPORT
   /****************** Send Device ID ******************/
    if (g_srv_brw_cntx.send_device_id_status == wap_bam_setting_val_imei_disable)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_DISABLE_INDEX;
    }
    else
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_ENABLE_INDEX;
    }
   /****************** Send Device ID ******************/
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */ 

#ifdef __MMI_BRW_POST_SESSION_INFO__
   /****************** Send Device ID ******************/
    if (g_srv_brw_cntx.post_session_info_status == MMI_FALSE)
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_POST_SESSION_INFO_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_DISABLE_INDEX;
    }
    else
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_POST_SESSION_INFO_SELECT - CUI_INLINE_ITEM_ID_BASE)] = BRW_PREF_ENABLE_INDEX;
    }
   /****************** Send Device ID ******************/
#endif /* __MMI_BRW_POST_SESSION_INFO__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_pref_inline_cui_fill_data
 * DESCRIPTION
 *  This is the function to fill data for preference screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_brw_settings_pref_inline_cui_fill_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U16 BrowserPreferencesImageList[BROWSER_PREFERENCES_ITEM_COUNT - (CUI_INLINE_ITEM_ID_BASE)];
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_browser_preferences_write_inline_struct();
    cui_inline_set_item_text_edit(g_brw_app_cntx.brw_inline_cid,
                                  BRW_PREFERENCES_INLINE_TIMEOUT_EDIT,
                                  g_brw_app_cntx.brw_dynamic_cntx_p->BrwTimeoutValue,
                                  BRW_TIME_OUT_LEN + 1,
                                  IMM_INPUT_TYPE_NUMERIC,
                                  INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                                  NULL,
                                  NULL);

    cui_inline_set_item_select(g_brw_app_cntx.brw_inline_cid,
                          BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT,
                          BRW_PREFERENCES_INLINE_SHOW_IMAGES_OPTION_COUNT,
                          (PU8*)g_brw_app_cntx.brw_dynamic_cntx_p->BrwAlwaysNeverStringArray,
                          g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
#ifdef OBIGO_Q05A
    cui_inline_set_item_select(g_brw_app_cntx.brw_inline_cid,
                          BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT,
                          BRW_PREFERENCES_INLINE_SHOW_VIDEOS_OPTION_COUNT,
                          (PU8*)g_brw_app_cntx.brw_dynamic_cntx_p->BrwAlwaysNeverStringArray,
                          g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT - CUI_INLINE_ITEM_ID_BASE)]);

    cui_inline_set_item_select(g_brw_app_cntx.brw_inline_cid,
                          BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT,
                          BRW_PREFERENCES_INLINE_PLAY_SOUNDS_OPTION_COUNT,
                          (PU8*)g_brw_app_cntx.brw_dynamic_cntx_p->BrwAlwaysNeverStringArray,
                          g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT - CUI_INLINE_ITEM_ID_BASE)]);

    cui_inline_set_item_select(g_brw_app_cntx.brw_inline_cid,
                          BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT,
                          BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_OPTION_COUNT,
                          (PU8*)g_brw_app_cntx.brw_dynamic_cntx_p->BrwAlwaysNeverStringArray,
                          g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT - CUI_INLINE_ITEM_ID_BASE)]);

    cui_inline_set_item_select(g_brw_app_cntx.brw_inline_cid,
                          BRW_PREFERENCES_INLINE_CSS_SELECT,
                          BRW_PREFERENCES_INLINE_CSS_OPTION_COUNT,
                          (PU8*)g_brw_app_cntx.brw_dynamic_cntx_p->BrwEnableDisableStringArray,
                          g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_CSS_SELECT - CUI_INLINE_ITEM_ID_BASE)]);

    cui_inline_set_item_select(g_brw_app_cntx.brw_inline_cid,
                          BRW_PREFERENCES_INLINE_SCRIPT_SELECT,
                          BRW_PREFERENCES_INLINE_SCRIPT_OPTION_COUNT,
                          (PU8*)g_brw_app_cntx.brw_dynamic_cntx_p->BrwEnableDisableStringArray,
                          g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SCRIPT_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
#endif /* OBIGO_Q05A */

#ifndef SLIM_WAP_MMS
    cui_inline_set_item_select(g_brw_app_cntx.brw_inline_cid,
                          BRW_PREFERENCES_INLINE_CACHE_SELECT,
                          BRW_PREFERENCES_INLINE_CACHE_OPTION_COUNT,
                          (PU8*)g_brw_app_cntx.brw_dynamic_cntx_p->BrwEnableDisableStringArray,
                          g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_CACHE_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
#endif
    cui_inline_set_item_select(g_brw_app_cntx.brw_inline_cid,
                          BRW_PREFERENCES_INLINE_COOKIE_SELECT,
                          BRW_PREFERENCES_INLINE_COOKIE_OPTION_COUNT,
                          (PU8*)g_brw_app_cntx.brw_dynamic_cntx_p->BrwEnableDisableStringArray,
                          g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_COOKIE_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
    cui_inline_set_item_select(g_brw_app_cntx.brw_inline_cid,
                          BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT,
                          BRW_PREFERENCES_INLINE_SHORTCUTS_OPTION_COUNT,
                          (PU8*)g_brw_app_cntx.brw_dynamic_cntx_p->BrwEnableDisableStringArray,
                          g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
        
#endif 
#ifdef BRW_SECURITY_WARNINGS_SUPPORT
    cui_inline_set_item_select(g_brw_app_cntx.brw_inline_cid,
                          BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT,
                          BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_OPTION_COUNT,
                          (PU8*)g_brw_app_cntx.brw_dynamic_cntx_p->BrwEnableDisableStringArray,
                          g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
        
#endif 
#ifdef BRW_SEND_DEVICE_ID_SUPPORT
    cui_inline_set_item_select(g_brw_app_cntx.brw_inline_cid,
                          BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT,
                          BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_OPTION_COUNT,
                          (PU8*)g_brw_app_cntx.brw_dynamic_cntx_p->BrwEnableDisableStringArray,
                          g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
       
#endif 
#ifdef __MMI_BRW_POST_SESSION_INFO__
    cui_inline_set_item_select(g_brw_app_cntx.brw_inline_cid,
                          BRW_PREFERENCES_INLINE_POST_SESSION_INFO_SELECT,
                          BRW_PREFERENCES_INLINE_POST_SESSION_INFO_OPTION_COUNT,
                          (PU8*)g_brw_app_cntx.brw_dynamic_cntx_p->BrwEnableDisableStringArray,
                          g_brw_app_cntx.brw_dynamic_cntx_p->brw_preferences[(BRW_PREFERENCES_INLINE_POST_SESSION_INFO_SELECT - CUI_INLINE_ITEM_ID_BASE)]);
        
#endif 

    for (index = 0; index < (BROWSER_PREFERENCES_ITEM_COUNT - (CUI_INLINE_ITEM_ID_BASE)); index++)
    {
        if (index % 2)
        {
            BrowserPreferencesImageList[index] = 0;
        }
        else
        {
            BrowserPreferencesImageList[index] = gIndexIconsImageList[index / 2];
        }
    }


    cui_inline_set_icon_list(g_brw_app_cntx.brw_inline_cid, BrowserPreferencesImageList);
}


#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_view_bookmark_inline_cui_fill_data
 * DESCRIPTION
 *  This is the function to fill data for view Bookmark
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_brw_view_bookmark_inline_cui_fill_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_set_item_displayonly(g_brw_app_cntx.brw_inline_cid,
                                    BRW_INLINE_TITLE,
                                    (PU8) g_brw_current_title);

    cui_inline_set_item_displayonly(g_brw_app_cntx.brw_inline_cid,
                                    BRW_INLINE_URL,
                                    (PU8) g_brw_current_url);

    cui_inline_set_softkey_text (g_brw_app_cntx.brw_inline_cid,
                                 BRW_INLINE_TITLE,
                                 MMI_LEFT_SOFTKEY,
                                 NULL);

    cui_inline_set_softkey_text (g_brw_app_cntx.brw_inline_cid,
                                 BRW_INLINE_URL,
                                 MMI_LEFT_SOFTKEY,
                                 NULL);
    cui_inline_set_screen_attributes(g_brw_app_cntx.brw_inline_cid,
                                      CUI_INLINE_SET_ATTRIBUTE, 
                                      CUI_INLINE_SCREEN_DISABLE_DONE);

    cui_inline_set_item_attributes(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_TITLE, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
    cui_inline_set_item_attributes(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_URL, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_add_bookmark_inline_cui_fill_data
 * DESCRIPTION
 *  This is the function to fill data for view Bookmark
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_brw_add_bookmark_inline_cui_fill_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_set_item_fullscreen_edit_struct fullscreen_attr;
 	mmi_brw_app_screenDB_struct *scrDB = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_inline_set_item_displayonly(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_TITLE, (PU8)g_brw_current_title);

    fullscreen_attr.buffer = (void*) g_brw_current_url;
    fullscreen_attr.default_text_id = NULL;
    fullscreen_attr.buffer_size = SRV_BRW_MAX_URL_LEN + 1;
    fullscreen_attr.title = STR_GLOBAL_EDIT;
    fullscreen_attr.title_icon = mmi_brw_get_wap_icon();
    fullscreen_attr.input_type = IMM_INPUT_TYPE_URL;
    fullscreen_attr.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    fullscreen_attr.required_input_mode_set = NULL;
                                             
    cui_inline_set_item_fullscreen_edit(g_brw_app_cntx.brw_inline_cid,
                                            BRW_INLINE_URL,
                                            &fullscreen_attr);

    scrDB = mmi_brw_app_get_curr_screenDB();

    if (scrDB->scrn_id == SCR_ID_BRW_ADD_TO_BOOKMARK)
    {
        cui_inline_set_screen_attributes(g_brw_app_cntx.brw_inline_cid,
                                  CUI_INLINE_SET_ATTRIBUTE, 
                                  CUI_INLINE_SCREEN_CHANGED);
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_authentication_inline_cui_fill_data
 * DESCRIPTION
 *  This is the function to fill data for view Bookmark
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_brw_authentication_inline_cui_fill_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_set_item_fullscreen_edit_struct fullscreen_attr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fullscreen_attr.buffer = (void*) g_brw_auth_username;
    fullscreen_attr.default_text_id = NULL;
    fullscreen_attr.buffer_size = WAP_BAM_MAX_USER_PASSWD_LENGTH + 1;
    fullscreen_attr.title = STR_GLOBAL_USERNAME;
    fullscreen_attr.title_icon = mmi_brw_get_wap_icon();
    fullscreen_attr.input_type = (IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE | INPUT_TYPE_ONE_LESS_CHARACTER) ;
    fullscreen_attr.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    fullscreen_attr.required_input_mode_set = NULL;

    cui_inline_set_item_fullscreen_edit(g_brw_app_cntx.brw_inline_cid,
                                             BRW_AUTH_DLG_INLINE_USERNAME,
                                             &fullscreen_attr);

    fullscreen_attr.buffer = (void*) g_brw_auth_password;
    fullscreen_attr.default_text_id = NULL;
    fullscreen_attr.buffer_size = WAP_BAM_MAX_USER_PASSWD_LENGTH + 1;
    fullscreen_attr.title = STR_GLOBAL_PASSWORD;
    fullscreen_attr.title_icon = mmi_brw_get_wap_icon();
    fullscreen_attr.input_type = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
    fullscreen_attr.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    fullscreen_attr.required_input_mode_set = NULL;
                                             
    cui_inline_set_item_fullscreen_edit(g_brw_app_cntx.brw_inline_cid,
                                            BRW_AUTH_DLG_INLINE_PASSWORD,
                                            &fullscreen_attr);
#ifdef OBIGO_Q05A
    cui_inline_set_item_select(g_brw_app_cntx.brw_inline_cid,
                          BRW_AUTH_DLG_INLINE_SAVE_OPTION,
                          BRW_APP_AUTH_DLG_SAVE_OPTION_TOTAL,
                          (PU8*)gBrwAuthDlgSaveOptionStringArray,
                          g_brw_auth_dlg_save_option);
#endif /* OBIGO_Q05A */
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_properties_inline_cui_fill_data
 * DESCRIPTION
 *  This is the function to fill data for properties screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_brw_properties_inline_cui_fill_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_NAME])
    {
        cui_inline_set_item_displayonly(g_brw_app_cntx.brw_inline_cid,
                                        BRW_INLINE_NAME,
                                        (PU8) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_name);
        cui_inline_set_item_attributes(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_NAME, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
    }
    else
    {
        cui_inline_delete_item(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_NAME_CAPTION);
        cui_inline_delete_item(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_NAME);

    }

    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_ADDRESS])
    {
        cui_inline_set_item_displayonly(g_brw_app_cntx.brw_inline_cid,
                                        BRW_INLINE_ADDRESS,
                                        (PU8) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_address);
        cui_inline_set_item_attributes(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_ADDRESS, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
    }
    else
    {
        cui_inline_delete_item(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_URL_CAPTION);
        cui_inline_delete_item(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_ADDRESS);
    }

    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_SIZE])
    {
        cui_inline_set_item_displayonly(g_brw_app_cntx.brw_inline_cid,
                                        BRW_INLINE_SIZE,
                                        (PU8) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_size);
        cui_inline_set_item_attributes(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_SIZE, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
    }
    else
    {
        cui_inline_delete_item(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_SIZE_CAPTION);
        cui_inline_delete_item(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_SIZE);
    }

    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_DATE])
    {
        cui_inline_set_item_displayonly(g_brw_app_cntx.brw_inline_cid,
                                        BRW_INLINE_DATE,
                                        (PU8) g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.obj_date);
        cui_inline_set_item_attributes(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_SIZE, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
    }
    else
    {
        cui_inline_delete_item(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_DATE_CAPTION);
        cui_inline_delete_item(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_DATE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_properties_inline_cui_update_title_icon
 * DESCRIPTION
 *  This is the function to update the icon corresponding to each icon
 * on the basis of which items are hidden.
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_brw_properties_inline_cui_update_item_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_icon_id = IMG_GLOBAL_L1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_NAME])
    {
        cui_inline_set_item_icon(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_NAME_CAPTION, item_icon_id);
        item_icon_id++;
    }

    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_ADDRESS])
    {
        cui_inline_set_item_icon(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_URL_CAPTION, item_icon_id);
        item_icon_id++;
    }

    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_SIZE])
    {
        cui_inline_set_item_icon(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_SIZE_CAPTION, item_icon_id);
        item_icon_id++;
    }

    if (g_brw_app_cntx.brw_dynamic_cntx_p->brw_obj_properties.prop_status[BRW_OBJECT_PROP_DATE])
    {
        cui_inline_set_item_icon(g_brw_app_cntx.brw_inline_cid, BRW_INLINE_DATE_CAPTION, item_icon_id);
        item_icon_id++;
    }
}

#endif /* OBIGO_Q05A */

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_edit_shortcut_inline_cui_fill_data
 * DESCRIPTION
 *  This is the function to fill data for Edit shortcut
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_brw_edit_shortcut_inline_cui_fill_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_set_item_fullscreen_edit_struct fullscreen_attr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fullscreen_attr.buffer = (void*) g_brw_current_title;
    fullscreen_attr.default_text_id = NULL;
    fullscreen_attr.buffer_size = SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1;
    fullscreen_attr.title = STR_GLOBAL_EDIT;
    fullscreen_attr.title_icon = mmi_brw_get_wap_icon();
    fullscreen_attr.input_type = (IMM_INPUT_TYPE_SENTENCE);
    fullscreen_attr.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    fullscreen_attr.required_input_mode_set = NULL;

    cui_inline_set_item_fullscreen_edit(g_brw_app_cntx.brw_inline_cid,
                                             BRW_INLINE_TITLE,
                                             &fullscreen_attr);

    fullscreen_attr.buffer = (void*) g_brw_current_url;
    fullscreen_attr.default_text_id = NULL;
    fullscreen_attr.buffer_size = SRV_BRW_MAX_URL_LEN + 1;
    fullscreen_attr.title = STR_GLOBAL_EDIT;
    fullscreen_attr.title_icon = mmi_brw_get_wap_icon();
    fullscreen_attr.input_type = IMM_INPUT_TYPE_URL;
    fullscreen_attr.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    fullscreen_attr.required_input_mode_set = NULL;
                                             
    cui_inline_set_item_fullscreen_edit(g_brw_app_cntx.brw_inline_cid,
                                            BRW_INLINE_URL,
                                            &fullscreen_attr);
}
#endif


/* End of Inline CUI procs */
/* Screen Group Procs */
void  mmi_brw_app_notify_wap_close(void)
{
    g_brw_app_cntx.allow_group_deleted = MMI_TRUE;
    switch (g_brw_app_cntx.close_evt)
    {
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        {
            mmi_frm_suspend_handle_key_process(MMI_FALSE);
            mmi_frm_group_close(BRW_CLOSE_GROUP_ID);
            break;
        }
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        {
            MMI_ID prev_app_id = mmi_frm_get_previous_app_id(BRW_CLOSE_GROUP_ID);
            mmi_frm_group_close(BRW_CLOSE_GROUP_ID);
            mmi_frm_suspend_handle_key_process(MMI_FALSE);
            mmi_frm_close_to_idle_group_with_start_id(prev_app_id);
            break;
        }
    }
    g_brw_app_cntx.close_evt = 0;
}

mmi_ret mmi_brw_close_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
            g_brw_app_cntx.allow_group_deleted = MMI_FALSE;
            g_brw_app_cntx.close_evt = 0;
            break;

        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            if (g_brw_app_cntx.allow_group_deleted == MMI_FALSE)
            {
                if(g_srv_brw_cntx.brw_instance_id > 0 && g_brw_app_cntx.close_evt == 0)
                {
                    g_brw_app_cntx.close_evt = evt->evt_id;
                    mmi_frm_suspend_handle_key_process(MMI_TRUE);
                    mmi_brw_app_deinit();
                    g_brw_app_cntx.brw_scr_group_id = BRW_CLOSE_GROUP_ID;
                     mmi_brw_app_show_progress_screen(STR_ID_BRW_INTERNET_SERVICES, STR_GLOBAL_PLEASE_WAIT);
                     if(evt->evt_id == EVT_ID_GROUP_GOBACK_IN_END_KEY || evt->evt_id == EVT_ID_GROUP_DELETE_REQ_IN_END_KEY)
                     {
                         return MMI_RET_STOP_END_KEY_FLOW; //forbid to delete if need to async free asm
                     }
                     else
                     {
                        return MMI_RET_ERR; //forbid to delete if need to async free asm
                     }
                }
                else if(g_srv_brw_cntx.brw_instance_id > 0 && g_brw_app_cntx.close_evt != 0)
                {
                    return MMI_RET_ERR;
                }
            }
            
            break;
        case EVT_ID_ASM_FORCE_FREE:
        {
            mmi_brw_app_if_asm_stop_callback();
            return MMI_FRM_ASM_WAITING_TO_FREE;
        }
    }
    return MMI_RET_OK;
}


mmi_ret mmi_brw_internet_service_screen_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static mmi_id previous_group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
            break;
        case EVT_ID_GROUP_INACTIVE:
            if (mmi_frm_scrn_get_count(BRW_SCREEN_GROUP) == 0)
            {
                mmi_frm_group_close(BRW_SCREEN_GROUP);
            }
            break;
        case EVT_ID_GROUP_ACTIVE:
        case EVT_ID_GROUP_FOCUSED:
            g_brw_app_cntx.brw_scr_group_id = BRW_SCREEN_GROUP;
            break;

        case EVT_ID_GROUP_REDRAW_START:
            previous_group_id = g_brw_app_cntx.brw_scr_group_id;
            g_brw_app_cntx.brw_scr_group_id = BRW_SCREEN_GROUP;
            break;

        case EVT_ID_GROUP_REDRAW_DONE:
            g_brw_app_cntx.brw_scr_group_id = previous_group_id;
            break;

        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            break;
        
        case EVT_ID_GROUP_DEINIT:
            if(!mmi_frm_group_is_present(BRW_RENDERED_PAGE_GRP_ID) && g_brw_app_cntx.allow_group_deleted)
            {
                mmi_frm_group_close(BRW_CLOSE_GROUP_ID);
            }
            break;
        
    }
    return MMI_RET_OK;

}

/* End of Screen Group Procs */

/*  File naming rule cui procs */
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_file_naming_rule_cui_proc
 * DESCRIPTION
 *  This is the group proc function for file naming rule cui proc
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_file_naming_rule_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_filename_editor_result_event_struct *response;
    MMI_ID_TYPE string_id;
    U32 parent_data;
    WCHAR path_buf[100];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT :
            response = (cui_filename_editor_result_event_struct *) evt;
            g_brw_app_cntx.file_naming_rule_cid = response->sender_id;
            parent_data = cui_filename_editor_get_parent_data(response->sender_id);
            if (response->result > 0)
            {
            #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
               if (parent_data == BRW_BKM_FOLDER_RENAME || parent_data == BRW_BKM_FOLDER_CREATE)
               {
                     mmi_brw_app_dmgr_create_bookmark_folder();
               }
               else
            #endif
               {
                    if(mmi_ucs2cmp((S8*) g_brw_bkm_cntx.sel_file_name, (S8*) g_brw_current_title))
                    {
                        cui_inline_set_screen_attributes(g_brw_app_cntx.brw_inline_cid, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
                    }
                    cui_filename_editor_close(response->sender_id);
              }
            }
            else if(response->result < 0) 
            {
            #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
                if ((parent_data == BRW_BKM_FOLDER_RENAME) || (parent_data == BRW_BKM_FOLDER_CREATE))
                {
	                string_id = srv_fmgr_fs_error_get_string(response->result);
	                mmi_brw_app_ui_draw_display_popup_ext(string_id, MMI_EVENT_FAILURE);
                }
                else
            #endif
                {
                    
                }
            }
            else 
            {
                cui_filename_editor_close(response->sender_id);
            }
    }
    return MMI_RET_OK;

}

/* End of File naming rule cui procs*/

/* FS editor procs */
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_stored_page_rename_fseditor_cui_proc
 * DESCRIPTION
 *  This is the group proc function for rename stored page FSEditor CUI
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_stored_page_rename_fseditor_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(evt->evt_id)
    {
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            cui_fseditor_get_text(g_brw_app_cntx.fseditor_cid, (WCHAR*)g_brw_display_info_str, ((SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH));
            mmi_brw_app_dmgr_rename_stored_page();
            break;
        case EVT_ID_CUI_FSEDITOR_ABORT:
            cui_fseditor_close(g_brw_app_cntx.fseditor_cid);
            break;
    }
    return MMI_RET_OK;
}
#endif /* OBIGO_Q05A */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_store_offline_fseditor_cui_proc
 * DESCRIPTION
 *  This is the group proc function for Store offline FSEditor CUI
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_store_offline_fseditor_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(evt->evt_id)
    {
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            cui_fseditor_get_text(g_brw_app_cntx.fseditor_cid, (WCHAR*)g_brw_display_info_str, ((SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH));
            mmi_brw_app_dmgr_save_stored_page();
            break;
        case EVT_ID_CUI_FSEDITOR_ABORT:
            cui_fseditor_close(g_brw_app_cntx.fseditor_cid);
            break;
    }
    return MMI_RET_OK;
}
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */


#if !(defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_enter_url_fseditor_cui_proc
 * DESCRIPTION
 *  This is the group proc function for Enter/Edit URL FSEditor CUI
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_enter_url_fseditor_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(evt->evt_id)
    {
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            cui_fseditor_get_text(g_brw_app_cntx.fseditor_cid, (WCHAR*)g_brw_app_cntx.brw_dynamic_cntx_p->brw_hist_selected_url, (SRV_BRW_ADDRESS_LIST_URL_LENGTH * ENCODING_LENGTH));
            mmi_brw_app_dmgr_add_search_or_input_url_item();
            break;
        case EVT_ID_CUI_FSEDITOR_ABORT:
            cui_fseditor_close(g_brw_app_cntx.fseditor_cid);
            break;
    }
    return MMI_RET_OK;
}
#endif

#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_edit_homepage_fseditor_cui_proc
 * DESCRIPTION
 *  This is the group proc function for Edit Homepage URL FSEditor CUI
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_edit_homepage_fseditor_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(evt->evt_id)
    {
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            cui_fseditor_get_text(g_brw_app_cntx.fseditor_cid, (WCHAR*)g_brw_current_url, (SRV_BRW_MAX_URL_LEN * ENCODING_LENGTH));
            mmi_brw_app_dmgr_update_user_defined_homepage();
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT:
            cui_fseditor_close(g_brw_app_cntx.fseditor_cid);
            break;
    }
    return MMI_RET_OK;
}
#endif
/* End of FS editor procs */

/* File Manager Procs */
#ifdef __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_browse_path_open_folder_proc
 * DESCRIPTION
 *  This is the group proc function for parent group of FMGR folder selector CUI
 * PARAMETERS
 *  void      
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_brw_app_browse_path_open_folder_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_folder_selector_result_event_struct *fmgr_evt ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FOLDER_SELECTOR_RESULT:
            {
                cui_folder_selector_result_event_struct *fmgr_evt = (cui_folder_selector_result_event_struct*)evt;
                if(fmgr_evt->result > 0)
                {
                    S32 error_code = FS_NO_ERROR;
                    srv_fmgr_fileinfo_struct info;
                    error_code = cui_folder_selector_get_selected_filepath(fmgr_evt->sender_id, &info, (WCHAR*)g_brw_open_file_cntx.file_path, (SRV_FMGR_PATH_MAX_LEN+1));
                    if(error_code < 0)
                    {
                        mmi_brw_app_file_system_error_handler(error_code);
                        cui_folder_selector_close(fmgr_evt->sender_id);
                    }
                    else
                    {
                        g_brw_app_cntx.file_selector_cid = fmgr_evt->sender_id;
                        mmi_brw_app_if_copy_move_boookmark();
                    }
                }
                else
                {
                    cui_folder_selector_close(fmgr_evt->sender_id);
                }
            }
            break;
    }
    return MMI_RET_OK;
}
#endif /* __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__ */

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPSCRHDLR_C */
