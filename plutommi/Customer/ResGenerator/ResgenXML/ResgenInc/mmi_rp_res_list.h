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
*  mmi_rp_res_list.h
*
* Project:
* --------
*   Resgen XML
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

#ifndef RESOURCE_LIST_H
#define RESOURCE_LIST_H

#include "mmi_rp_xml.h"
#include "mmi_rp_xml_def.h"

#include "mmi_rp_audio.h"
#include "mmi_rp_menu.h"
#include "mmi_rp_string.h"
#include "mmi_rp_screen.h"
#include "mmi_rp_timer.h"
#include "mmi_rp_theme.h"
#include "mmi_rp_event.h"
#include "mmi_rp_image.h"
#include "mmi_rp_mem_config.h"

mmi_rp_mgr_tag_callback g_res_handlers_standard[] = {
    {MMI_RP_MGR_TAG_APP, mmi_rp_mgr_app_start_handler, mmi_rp_mgr_app_end_handler, mmi_rp_mgr_app_data_handler},
    {MMI_RP_MGR_TAG_LINE, mmi_rp_mgr_line_start_handler, mmi_rp_mgr_line_end_handler, mmi_rp_mgr_line_data_handler},
    {MMI_RP_MGR_TAG_INCLUDE, mmi_rp_mgr_include_start_handler, mmi_rp_mgr_include_end_handler, NULL},
    {MMI_RP_MGR_TAG_PATH, mmi_rp_mgr_path_start_handler, mmi_rp_mgr_path_end_handler, mmi_rp_mgr_path_data_handler},

    {MMI_RP_MGR_TAG_IMAGE, mmi_rp_img_start_handler, mmi_rp_img_end_handler, mmi_rp_img_data_handler},
    {MMI_RP_MGR_TAG_MULTI_IMAGE, mmi_rp_multi_img_start_handler, mmi_rp_multi_img_end_handler, mmi_rp_multi_img_data_handler},
    {MMI_RP_MGR_TAG_MEDIA, mmi_rp_med_start_handler, mmi_rp_med_end_handler, mmi_rp_med_data_handler},
    {MMI_RP_MGR_TAG_ENFB, mmi_rp_enfb_start_handler, mmi_rp_enfb_end_handler, NULL},
    
    {MMI_RP_MGR_TAG_STRING, mmi_rp_str_start_handler, mmi_rp_str_end_handler, mmi_rp_str_data_handler},
    
    {MMI_RP_MGR_TAG_AUDIO, mmi_rp_aud_start_handler, mmi_rp_aud_end_handler, mmi_rp_aud_data_handler},
    
    {MMI_RP_MGR_TAG_MENU, mmi_rp_menu_start_handler, mmi_rp_menu_end_handler, NULL},
    {MMI_RP_MGR_TAG_MENUITEM, mmi_rp_menuitem_start_handler, mmi_rp_menuitem_end_handler, NULL},
    {MMI_RP_MGR_TAG_MAINMENUITEM, mmi_rp_mainmenuitem_start_handler, mmi_rp_mainmenuitem_end_handler, NULL},
    {MMI_RP_MGR_TAG_MENUSET, mmi_rp_menuset_start_handler, mmi_rp_menuset_end_handler, NULL},
    {MMI_RP_MGR_TAG_MENUSET_ID, mmi_rp_menuset_id_start_handler, mmi_rp_menuset_id_end_handler, mmi_rp_menuset_id_data_handler},
    {MMI_RP_MGR_TAG_MENUITEM_ID, mmi_rp_menuitem_id_start_handler, mmi_rp_menuitem_id_end_handler, mmi_rp_menuitem_id_data_handler},

    {MMI_RP_MGR_TAG_SCREEN, mmi_rp_scr_start_handler, mmi_rp_scr_end_handler, mmi_rp_scr_data_handler},
    {MMI_RP_MGR_TAG_TIMER, mmi_rp_timer_start_handler, mmi_rp_timer_end_handler, mmi_rp_timer_data_handler},
    {MMI_RP_MGR_TAG_EVENT, mmi_rp_event_start_handler, mmi_rp_event_end_handler, mmi_rp_event_data_handler},
        
    {MMI_RP_MGR_TAG_MEMORY, mmi_rp_mem_config_start_handler, mmi_rp_mem_config_end_handler, NULL},
    {MMI_RP_MGR_TAG_APPCONCURRENT, mmi_rp_appconcurrent_start_handler, mmi_rp_appconcurrent_end_handler, NULL},

    {MMI_RP_MGR_TAG_THEME,      mmi_rp_theme_start_handler,     mmi_rp_theme_end_handler,   NULL},
    {MMI_RP_MGR_TAG_COLOR,      mmi_rp_color_start_handler,     mmi_rp_color_end_handler,   NULL},
    {MMI_RP_MGR_TAG_FONTSTYLE,  mmi_rp_fontstyle_start_handler, mmi_rp_fontstyle_end_handler, NULL},
    {MMI_RP_MGR_TAG_BINARY,     mmi_rp_binary_start_handler,    mmi_rp_binary_end_handler,  NULL},
    {MMI_RP_MGR_TAG_INTEGER,    mmi_rp_integer_start_handler,   mmi_rp_integer_end_handler, NULL},
    /*-------------------Add Res Before this line--------------------------*/
    {MMI_RP_MGR_TAG_END, NULL, NULL, NULL}
};

#include "mmi_rp_cust_res_list.h"

#endif /* RESOURCE_LIST_H */
