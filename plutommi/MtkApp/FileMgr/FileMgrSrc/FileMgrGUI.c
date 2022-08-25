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
 *  FileMgrGui.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GUI of Filemanager
 *
 * Author:
 * -------
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
#define _FMGR_INTERNAL_SOURCE_C_
/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"

#if defined (__MMI_FILE_MANAGER__)

#include "FileMgrGProt.h"
#include "FileMgrProt.h"
#include "FileMgrInstance.h"
#include "FileMgrGUI.h"
#include "FileMgrType.h"

#include "FileMgrResDef.h"
#include "Drm_def.h"
#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif

/* Temp. Fion need to modify */
#include "FileMgrFSData.h"

#include "Conversions.h"
#include "PhoneSetupGprots.h"

#include "wgui_categories_util.h"

#ifdef __MMI_VUI_MEDIAWALL__
#include "MediaWall\vadp_mediawall.h"
#endif

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "wgui_categories_fmgr.h"
#include "gui_data_types.h"
#include "gui_typedef.h"
#include "string.h"
#include "mmi_rp_file_type_def.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "FileMgrSrvGProt.h"
#include "Unicodexdcl.h"
#include "gui_effect_oem.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalConstants.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "kal_public_api.h"
#include "CustMenuRes.h"
#include "mmi_rp_app_filemanager_def.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "wgui_categories_list.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "lcd_sw_inc.h"
#include "gui.h"
#include "mmi_rp_app_uiframework_def.h"
#include "FileMgrServiceResDef.h"
/****************************************************************************
* Define
*****************************************************************************/

/* Async Matrix is not ready, dont turn on */
#define FMGR_USING_ASYNC_CATEGORY

/****************************************************************************
* Global Variable
*****************************************************************************/


/****************************************************************************
* Static Variable
*****************************************************************************/
mmi_fmgr_gui_context_struct fmgr_gui_context;
mmi_fmgr_gui_context_struct *fmgr_gui_p = &fmgr_gui_context;

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/
#ifdef __MMI_SLIM_FILE_MANAGER__
static S32 fmgr_gui_get_drv_asy_item_callback(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
#endif
static void fmgr_gui_set_index_displayable(S32 index, MMI_BOOL displayable);
static MMI_BOOL fmgr_gui_get_index_displayable(S32 item_idx);
static MMI_BOOL fmgr_gui_get_image_path_callback(S32 item_idx, S8 *file_path);

#ifndef __MMI_SLIM_FILE_MANAGER__
static void fmgr_gui_get_drv_info_callback(S32 item_idx, wgui_fmgr_info_struct *fmgr_info);
static void fmgr_gui_hide_drv_info_callback(void);
    
static void fmgr_gui_get_drv_menuitem_callback(S32 item_idx, BOOL is_hilighted, wgui_fmgr_menuitem_data_struct *menuitem_data);
static void fmgr_gui_hide_drv_menuitem_callback(void);
#endif

static void fmgr_gui_hide_file_callback(void);

#ifndef __MMI_SLIM_FILE_MANAGER__
static void fmgr_gui_get_file_info_callback(S32 item_idx, wgui_fmgr_info_struct *fmgr_info);
static void fmgr_gui_get_file_menuitem_callback(S32 item_idx, BOOL is_hilighted, wgui_fmgr_menuitem_data_struct *menuitem_data);

static pBOOL fmgr_gui_get_drv_item_callback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static S32 fmgr_gui_get_drv_hint_callback(S32 item_idx, UI_string_type *hint_array);
#endif
#ifndef __MMI_VUI_MEDIAWALL__
static void fmgr_gui_draw_file_matrix_callback(S32 idx, BOOL is_hilighted, wgui_fmgr_menuitem_data_struct *menuitem_data);
#endif
#if 0
/* under construction !*/
/* under construction !*/
#endif
static void fmgr_gui_hide_ext_name(S8 *str_buf_ptr, FMGR_FILE_INFO_STRUCT *info_ptr);

#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
static S32 fmgr_gui_get_file_marked_state(S32 index, PU8 *value);
static S32 fmgr_gui_set_file_marked_state(S32 item_index);
#endif

static void fmgr_gui_notify_highlight_callback(S32 index);
static S32  fmgr_gui_get_file_item_async_callback(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
//static S32  fmgr_gui_get_drv_item_async_callback(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);

#ifdef __MMI_VUI_MEDIAWALL__
static void fmgr_gui_mediawall_get_file_info_cb(S32 item_idx, BOOL is_hilighted, vapp_mediawall_fmgr_file_data_struct *file_info);
static S32 fmgr_gui_mediawall_get_file_path_cb(S32 item_idx, S8 *file_path, S32 file_path_size);
#endif

/****************************************************************************
* Function Body
*****************************************************************************/
#define FUNCTION_BODY
/*****************************************************************************
 * FUNCTION
 *  mmi_fmgri_gui_init
 * DESCRIPTION
 *  init gui context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgri_gui_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(fmgr_gui_p, 0, sizeof(mmi_fmgr_gui_context_struct));
#ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__
    wgui_cat21x_register_set_displayable(fmgr_gui_set_index_displayable);
    wgui_cat21x_register_get_displayable(fmgr_gui_get_index_displayable);
    wgui_cat21x_register_get_thumb_image(fmgr_gui_get_image_path_callback);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgri_gui_display_list
 * DESCRIPTION
 *  display file list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgri_gui_display_list(U8 instance_id, U32 file_count, U8 *guiBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlightId = 0;
    S8 *file_path;
    FMGR_FILTER filter_type;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_PERF_START(mmi_fmgri_gui_display_list, instance_id);
    fmgr_gui_p->instance_id = instance_id;
    fmgr_gui_p->instance = mmi_fmgri_get_instance_by_id(instance_id);
    highlightId = fmgr_gui_p->instance->cur_index;

    mmi_fmgri_instance_get_filepath_and_filter(instance_id, &file_path, &filter_type);

    FMGR_TRACE3(TRC_MMI_FMGR_778AEB8361E7457FBDCFCF6A8794E02B,
        "[MMIFMGR] > GUI > Display List > id=%d, index=%d, total=%d\n", instance_id, highlightId, file_count);

    wgui_async_list_register_update_callback(fmgr_gui_notify_highlight_callback);

    if (mmi_ucs2cmp((PS8)file_path, (PS8)SRV_FMGR_PATH_ROOT)==0)
    {
        /* Browse drive list */
        fmgr_gui_display_drv_list(highlightId, file_count, guiBuffer);
    }
    else
    {
        /* Browse file and folder list */
        fmgr_gui_display_file_list(highlightId, file_count, guiBuffer);
    }

    FMGR_PERF_END(mmi_fmgri_gui_display_list);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgri_gui_query_display_type_key
 * DESCRIPTION
 *  query display type key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8   mmi_fmgri_gui_query_display_type_key(fmgr_display_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(type)
    {
    #ifndef __MMI_IV_PLUTO_SLIM__
    case FMGR_DISPLAY_TYPE_MATRIX:
        return CAT213_ARROW_ALL;
    #endif
    default:
        return CAT213_ARROW_UP | CAT213_ARROW_DOWN;
    }
}


void mmi_fmgri_gui_display_progress(U8 instance_id, U8* guiBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon;
    U16 title_string_id, list_style;
    S8* display_buffer;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_gui_p->instance_id = instance_id;
    fmgr_gui_p->instance = mmi_fmgri_get_instance_by_id(instance_id);
#ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__
    /* get list style */
    list_style = mmi_fmgri_instance_get_list_style(fmgr_gui_p->instance_id);
#endif
    mmi_fmgri_instance_get_title_info(instance_id, &title_string_id, &icon);

    FMGR_TRACE1(TRC_MMI_FMGR_C8D5F4FCBBC9468EB95548D23E3C53B5,
        "[MMIFMGR] > GUI > Display Progress > id=%d\n",
        instance_id);

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_block(MMI_TRUE);
#endif

    display_buffer = (S8*)GetString(STR_GLOBAL_PLEASE_WAIT);
#ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__
    switch (list_style)
    {
    case FMGR_DISPLAY_TYPE_BANNER_LIST:
        if(fmgr_gui_p->instance->flag & FMGR_IFLAG_HIDE_LOADING_PATH)
            break;
        
        display_buffer = (S8*)subMenuData;
        mmi_ucs2cpy(display_buffer, (S8*)GetString(STR_GLOBAL_LOADING));
        mmi_ucs2cat(display_buffer, (S8*)L"\n");
        len = mmi_ucs2strlen(display_buffer);
        if(mmi_fmgri_instance_get_display_str(instance_id, 
            display_buffer + len*ENCODING_LENGTH, 
            MAX_SUBMENU_CHARACTERS) < 0)
        {
            display_buffer = (S8*)GetString(STR_GLOBAL_PLEASE_WAIT);
        }
        break;
    }
#endif  /* #ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__ */
#if defined(__MMI_MAINLCD_128X64__) || defined(__MMI_MAINLCD_96X64__)
	force_no_small_screen() ;
#endif
    

    ShowCategory66Screen(
        title_string_id,
        icon,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) display_buffer,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

}

void mmi_fmgri_gui_update_progress(U8 instance_id, U32 progress, U32 total)
{
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
#endif
}

#ifdef __FMGR_FTE_TOOLBAR_SUPPORT__

static void fmgr_gui_tb_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(index < fmgr_gui_p->tb_count)
    {
        para = (MMI_FMGRI_KEY_TOUCH << 16) | fmgr_gui_p->tb_menus[index];
        mmi_fmgri_instance_execute_command(fmgr_gui_p->instance_id, FMGRI_CMD_EXECUTE_MENU, para, NULL);
    }
}

void mmi_fmgri_gui_toolbar_init(const U16* btn_menus, const gui_icon_bar_item_resource_struct* btn_resources, U16 btn_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_icon_bar_item_resource_struct res_array[FMGR_FTE_TB_MAX_COUNT];
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_ASSERT(btn_count <= FMGR_FTE_TB_MAX_COUNT);

    for(i=0;i<btn_count;i++)
    {
        if(btn_resources[i].text_of_description)
            res_array[i].text_of_description = btn_resources[i].text_of_description;
        else
            res_array[i].text_of_description = (PU8)get_string(GetStringIdOfItem(btn_menus[i]));
        res_array[i].content_icon = btn_resources[i].content_icon;
        res_array[i].disabled_content_icon = btn_resources[i].disabled_content_icon;
        fmgr_gui_p->tb_menus[i] = btn_menus[i];
    }
    fmgr_gui_p->tb_count = btn_count;
    
    wgui_icon_bar_setup_by_resource(btn_count, res_array, fmgr_gui_tb_handler);
    for(i=0;i<btn_count;i++)
    {
        if(mmi_frm_test_menu_item_hide(btn_menus[i]))
            wgui_icon_bar_set_item_enable_state(i, MMI_FALSE);
    }

}

void mmi_fmgri_gui_toolbar_update(mmi_fmgri_gui_tb_update_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!fmgr_gui_p->tb_count)
    {
        return;
    }

    if (type == FMGR_FTE_TB_UPDATE_DISABLE_ALL)
    {
        for (i = 0; i < fmgr_gui_p->tb_count; i++)
        {
            wgui_icon_bar_set_item_enable_state(i, MMI_FALSE);
        }
    }
    else
    {
        for (i = 0; i < fmgr_gui_p->tb_count; i++)
        {
            if (mmi_frm_test_menu_item_hide(fmgr_gui_p->tb_menus[i]))
            {
                wgui_icon_bar_set_item_enable_state(i, MMI_FALSE);
            }
            else
            {
                wgui_icon_bar_set_item_enable_state(i, MMI_TRUE);
            }
        }
    }
    wgui_icon_bar_update();
}

#endif

void mmi_fmgri_gui_set_softkeys(mmi_fmgri_key_binding_flag sk_type, U16 string_id, U16 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(sk_type & MMI_FMGRI_KEY_LSK)
    {
        #ifdef __MMI_VUI_MEDIAWALL__
        vapp_mediawall_set_softkey(MMI_LEFT_SOFTKEY, string_id, icon_id);
        #endif
        ChangeLeftSoftkey(string_id, icon_id);
    }
    if(sk_type & MMI_FMGRI_KEY_RSK)
    {
        #ifdef __MMI_VUI_MEDIAWALL__
        vapp_mediawall_set_softkey(MMI_RIGHT_SOFTKEY, string_id, icon_id);
        #endif
        ChangeRightSoftkey(string_id, icon_id);
    }
#ifndef __MMI_WGUI_DISABLE_CSK__
    if(sk_type & MMI_FMGRI_KEY_CSK)
    {
        #ifdef __MMI_VUI_MEDIAWALL__
        vapp_mediawall_set_softkey(MMI_CENTER_SOFTKEY, string_id, icon_id);
        #endif
        ChangeCenterSoftkey(string_id, icon_id);
    }
#endif
}

#define LOCAL_FUNCTION

/****************************************************************************
 *****************************************************************************
 * Local Function
 *****************************************************************************
 *****************************************************************************/
#ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__
/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_set_index_displayable
 * DESCRIPTION
 *  Called by categories to set unable to show flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void fmgr_gui_set_index_displayable(S32 item_idx, MMI_BOOL displayable)
{
    mmi_fmgri_fsdata_gui_set_cache_flag(fmgr_gui_p->instance_id, item_idx, MMI_FMGR_FILEINFO_FLAG_IS_ABLE_DISPLAY, displayable);
}

/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_get_index_displayable
 * DESCRIPTION
 *  Called by categories to get is unable to show flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL fmgr_gui_get_index_displayable(S32 item_idx)
{
    /* if is corrupted file, show as icon */
    if (mmi_fmgri_fsdata_gui_get_cache_flag(fmgr_gui_p->instance_id, item_idx, MMI_FMGR_FILEINFO_FLAG_IS_ABLE_DISPLAY))    
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_get_image_path_callback
 * DESCRIPTION
 *  Called by categories to get image data by index.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL fmgr_gui_get_image_path_callback(S32 item_idx, S8 *file_path)
{
    MMI_BOOL                ret;
    FMGR_FILE_INFO_STRUCT   file_info;
#ifdef __MMI_FMGR_CUSTICON_SUPPORT__
    S8* buffer;
#endif

    FMGR_PERF_START(fmgr_gui_get_image_path_callback, item_idx);

    do {
        ret = MMI_FALSE;
        
        /* get file info */
        if(mmi_fmgri_fsdata_instance_get_file_info_ex(fmgr_gui_p->instance_id, (U16) (item_idx), &file_info) < 0)
            break;

        /* path too long */
        if(!mmi_fmgri_filepath_compose(file_path, (SRV_FMGR_PATH_MAX_LEN + 1),
                                       fmgr_gui_p->instance->file_path, &file_info, MMI_FALSE))
            break;

#ifdef __MMI_FMGR_CUSTICON_SUPPORT__
        buffer = mmi_fmgri_get_and_lock_buffer();
        if(0 == srv_fmgr_custicon_query((const WCHAR*)file_path, (WCHAR*)buffer, SRV_FMGR_PATH_BUFFER_SIZE))        
        {
            mmi_ucs2cpy(file_path, buffer);
            mmi_fmgri_free_and_unlock_buffer(buffer);
            ret = MMI_TRUE;
            break;
        }
        mmi_fmgri_free_and_unlock_buffer(buffer);
#endif
        

        if (!FMGR_FILTER_IS_SET_IMAGE(&file_info.file_type))
        {
            break;
        }

        /* check if has DRM right */
#ifdef __DRM_SUPPORT__
//        if (mmi_rmgr_check_rights_by_path((kal_wchar*)file_path, DRM_PERMISSION_DISPLAY) != MMI_RMGR_STATUS_OK)
        if (DRM_get_object_method(0, (kal_wchar*)file_path) != DRM_METHOD_NONE)
        {
            /* do not have permission, skip */
            break;
        }
#endif
            /*
        if (gdi_image_get_type_from_file(file_path) != GDI_IMAGE_TYPE_JPG_FILE)
        {
            break;
        }*/

        ret = MMI_TRUE;
    } while(0);

    if(!ret)
        fmgr_gui_set_index_displayable(item_idx, MMI_FALSE);
    
    FMGR_PERF_END(fmgr_gui_get_image_path_callback);
    return ret;

}
#endif/* __MMI_ULTRA_SLIM_FILE_MANAGER__ */
/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_display_file_list
 * DESCRIPTION
 *  init gui context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_gui_display_file_list(S32 highlightId, U32 file_count, U8 *guiBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cat_error;
#ifndef __MMI_SLIM_FILE_MANAGER__
    WCHAR *empty_str;
    U8 arrow_display;
#endif
    U16 empty_str_id;
    S8 *instance_path;
    U16 iconId, title_string_id, list_style, lsk_string_id;
#ifdef FMGR_TAB_SUPPORT
    S8 tab_index = 0;
#endif /* FMGR_TAB_SUPPORT */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SLIM_FILE_MANAGER__
    /* Detemine display arrow type, if is browse mode, only display up and down arrow */
    arrow_display = mmi_fmgri_instance_get_arrow_type(fmgr_gui_p->instance_id);
#endif
    /* Get title icon & string*/
    mmi_fmgri_instance_get_title_info(fmgr_gui_p->instance_id, &title_string_id, &iconId);

    /* Get list style */
    list_style = mmi_fmgri_instance_get_list_style(fmgr_gui_p->instance_id);

    /* Get path */
    mmi_fmgri_instance_get_filepath_and_filter(fmgr_gui_p->instance_id, &instance_path, NULL);

    lsk_string_id = STR_GLOBAL_OPTIONS;
    empty_str_id = 0;

    if (file_count == 0xFFFFFFFF)
    {
        file_count = 0;
        lsk_string_id = 0;
    }
    else if (file_count == 0)
    {
        lsk_string_id = 0;
        empty_str_id = STR_ID_FMGR_NO_FILES;
        mmi_fmgri_instance_execute_command(fmgr_gui_p->instance_id, FMGRI_CMD_GET_EMPTY_STR, 0, &empty_str_id);

    #ifdef FMGR_TAB_SUPPORT
        cat_error = mmi_fmgri_instance_cr_tab_get_index(fmgr_gui_p->instance_id);
        if (cat_error >= 0)
        {
            if (FS_DEVICE_TYPE_CARD == FS_GetDevType((WCHAR*)instance_path) &&
                FS_GetDevStatus(instance_path[0], FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
            {
                empty_str_id = STR_GLOBAL_NO_MEMORY_CARD;
            }
            else
            {
                if (srv_fmgr_fs_path_exist((WCHAR*)instance_path) < 0)
                {
                    empty_str_id = srv_fmgr_fs_error_get_string(FS_PATH_NOT_FOUND);
                }
            }
        }
    #endif /* FMGR_TAB_SUPPORT */
    }
#ifndef __MMI_SLIM_FILE_MANAGER__
    if (empty_str_id)
    {
        empty_str = get_string(empty_str_id);
    }
    else
    {
        empty_str = L"";
    }
#endif
#ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
    if (file_count > FMGR_MAX_SORT)
    {
        wgui_cat21x_fmgr_set_slow_data_mode(MMI_TRUE);
    }
#endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */

    switch (list_style)
    {
#ifndef __MMI_SLIM_FILE_MANAGER__
        case FMGR_DISPLAY_TYPE_ICON_LIST:          
            /* List image viewer */
            ShowCategory217FmgrScreen(
                title_string_id,
                iconId, /* title */
                lsk_string_id,
                IMG_GLOBAL_OPTIONS, /* lsk */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK, /* rsk */
                file_count,
                fmgr_gui_get_file_item_async_callback,
                NULL,
                fmgr_gui_get_file_menuitem_callback,
                fmgr_gui_hide_file_callback,
                empty_str,
                highlightId, /* hiligth item idx */
                arrow_display,
                (U8*) guiBuffer,
                &cat_error);
            break;

        case FMGR_DISPLAY_TYPE_MATRIX:
            /* Category214 not support negative highlight id */
            #ifdef __MMI_VUI_MEDIAWALL__
                vapp_mediawall_cat(
                    title_string_id,
                    iconId,
                    (U16)lsk_string_id,
                    (U16)IMG_GLOBAL_OPTIONS,
                    (U16)STR_GLOBAL_BACK,
                    (U16)IMG_GLOBAL_BACK,
                    (U16)file_count,
                    highlightId,
                    0,
                    instance_path,
                    (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH,
                    fmgr_gui_mediawall_get_file_info_cb,
                    fmgr_gui_mediawall_get_file_path_cb,
                    (U8*) guiBuffer);
            #else /* __MMI_VUI_MEDIAWALL__ */
                ShowCategory214FmgrScreen(
                    title_string_id,
                    iconId,
                    (U16)lsk_string_id,
                    (U16)IMG_GLOBAL_OPTIONS,
                    (U16)STR_GLOBAL_BACK,
                    (U16)IMG_GLOBAL_BACK,
                    (U16)file_count, /* num of item */
                    fmgr_gui_draw_file_matrix_callback, /* draw image callback */
                    fmgr_gui_hide_file_callback, /* hide image callback */
                    (U8)FMGR_MATRIX_ROW_NUM, /* number per row */
                    (U8)FMGR_MATRIX_COLUMN_NUM, /* number per col */
                    (highlightId < 0) ? 0 : highlightId, /* hilighted item */
                    (U8*) guiBuffer);
            #endif /* __MMI_VUI_MEDIAWALL__ */
                break;

        case FMGR_DISPLAY_TYPE_SIMPLE_LIST:
			wgui_cat_set_list_menu_empty_lable((UI_string_type)get_string(STR_ID_FMGR_NO_FILES));
			wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
			wgui_cat1032_show(
				get_string(title_string_id),
				get_image(iconId),
				get_string(lsk_string_id),
				get_image(IMG_GLOBAL_OPTIONS),
				get_string(STR_GLOBAL_BACK),
				get_image(IMG_GLOBAL_BACK),
               file_count, 
				fmgr_gui_get_file_item_async_callback,
				NULL,
               highlightId,
                0,
#ifdef __FS_CARD_SUPPORT__
				IMG_ID_FMGR_DRIVE_MEM_CARD,
#else
				0,
#endif
				0,
				(U8*) guiBuffer,
				&cat_error
				);
			wgui_restore_list_menu_slim_style();
            break;

        case FMGR_DISPLAY_TYPE_BANNER_LIST:
            ShowCategory216FmgrScreen(
                title_string_id,
                iconId,
                lsk_string_id,
                IMG_GLOBAL_OPTIONS, /* lsk */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK, /* rsk */
                file_count,
                fmgr_gui_get_file_item_async_callback,
                NULL,
                IMG_ID_FMGR_ICON_FILE_TYPE_FOLDER,
                fmgr_gui_get_file_info_callback,
                fmgr_gui_hide_file_callback,
                2, /* info box row count */
                0, /* info bg img id */
                empty_str,
                highlightId, /* hiligth item idx */
                (U8*) guiBuffer,
                &cat_error);
            break;

    #ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
        case FMGRI_DISPLAY_TYPE_MARK_SEVERL_LIST:
            ShowCategory216FmgrMarkScreen(
                (U16)STR_GLOBAL_SELECT,
                (U16)iconId,
                (U16)lsk_string_id,        
                (U16)IMG_GLOBAL_OPTIONS,
                (U16)STR_GLOBAL_BACK ,
                (U16)IMG_GLOBAL_BACK ,
                (S32)file_count,
                fmgr_gui_get_file_item_async_callback,
                NULL,
                IMG_ID_FMGR_ICON_FILE_TYPE_FOLDER,
                fmgr_gui_get_file_info_callback,
                fmgr_gui_hide_file_callback,
                fmgr_gui_get_file_marked_state,
                fmgr_gui_set_file_marked_state,
                2,
                0,            
                NULL,            
                empty_str,
                (S32)highlightId,
                (U8*)guiBuffer,
                &cat_error);
            break;

        case FMGRI_DISPLAY_TYPE_EXPAND_MS_LIST:
            /* 218FmgrMark can support count == 0 */
            ShowCategory218FmgrMarkScreen(
                (U16)STR_GLOBAL_SELECT,
                (U16)iconId,
                (U16)lsk_string_id,        
                (U16)IMG_GLOBAL_OPTIONS,
                (U16)STR_GLOBAL_BACK ,
                (U16)IMG_GLOBAL_BACK ,
                (S32)file_count,     
                fmgr_gui_get_file_item_async_callback,
                NULL,
                IMG_ID_FMGR_ICON_FILE_TYPE_FOLDER,
                fmgr_gui_get_file_info_callback,
                fmgr_gui_hide_file_callback,
                fmgr_gui_get_file_marked_state,
                fmgr_gui_set_file_marked_state,
                2,
                0,            
                NULL,            
                empty_str,
                (S32)highlightId,
                (U8*)guiBuffer,
                &cat_error);
            break;
    #endif /* __MMI_FMGR_MULTI_SELECT_SUPPORT__ */

        case FMGRI_DISPLAY_TYPE_EXPAND_LIST:
        #ifdef FMGR_TAB_SUPPORT
            cat_error = mmi_fmgri_instance_cr_tab_get_index(fmgr_gui_p->instance_id);
            if(cat_error >= 0)
            {
                tab_index = (S8)cat_error;
                ShowCategory218FmgrTabScreen(
                    title_string_id,
                    iconId,
                    lsk_string_id,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK, /* rsk */
                    file_count,
                    fmgr_gui_get_file_item_async_callback,
                    NULL,
                    IMG_ID_FMGR_ICON_FILE_TYPE_FOLDER,
                    fmgr_gui_get_file_info_callback,
                    fmgr_gui_hide_file_callback,
                    2, /* info box row count */
                    0, /* info bg img id */
                    empty_str,
                    highlightId, /* hiligth item idx */
                    tab_index,
                    (U8*) guiBuffer,
                    &cat_error);
                break;
            }
        #endif /* FMGR_TAB_SUPPORT */
            /* 218Fmgr can support count == 0 */
            ShowCategory218FmgrScreen(
                title_string_id,
                iconId,
                lsk_string_id,
                IMG_GLOBAL_OPTIONS, /* lsk */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK, /* rsk */
                file_count,
                fmgr_gui_get_file_item_async_callback,
                NULL,
                IMG_ID_FMGR_ICON_FILE_TYPE_FOLDER,
                fmgr_gui_get_file_info_callback,
                fmgr_gui_hide_file_callback,
                2, /* info box row count */
                0, /* info bg img id */
                empty_str,
                highlightId, /* hiligth item idx */
                (U8*) guiBuffer,
                &cat_error);
            break;

        default:
            break;
#else
        case FMGR_DISPLAY_TYPE_ICON_LIST:
        case FMGR_DISPLAY_TYPE_SIMPLE_LIST:
        case FMGRI_DISPLAY_TYPE_EXPAND_LIST:
        case FMGR_DISPLAY_TYPE_BANNER_LIST:
			wgui_cat_set_list_menu_empty_lable((UI_string_type)get_string(STR_ID_FMGR_NO_FILES));
#ifndef __MMI_MAINLCD_96X64__ 
			wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
#endif
			wgui_cat1032_show(
				get_string(title_string_id),
                           #ifndef __MMI_MAINLCD_96X64__
				get_image(iconId),
                           #else
                                NULL,
                           #endif  /* __MMI_MAINLCD_96X64__ */
				get_string(lsk_string_id),
				get_image(IMG_GLOBAL_OPTIONS),
				get_string(STR_GLOBAL_BACK),
				get_image(IMG_GLOBAL_BACK),
				file_count,
				fmgr_gui_get_file_item_async_callback,
				NULL,
				highlightId,
				0,
#ifdef __FS_CARD_SUPPORT__
				IMG_ID_FMGR_DRIVE_MEM_CARD,
#else
				0,
#endif
				0,
				(U8*) guiBuffer,
				&cat_error);
#ifndef __MMI_MAINLCD_96X64__
			wgui_restore_list_menu_slim_style();
#endif
            break;
#ifndef __MMI_IV_PLUTO_SLIM__
        case FMGR_DISPLAY_TYPE_MATRIX:
        /* Category214 not support negative highlight id */
        #ifdef __MMI_VUI_MEDIAWALL__
            vapp_mediawall_cat(
                title_string_id,
                iconId,
                (U16)lsk_string_id,
                (U16)IMG_GLOBAL_OPTIONS,
                (U16)STR_GLOBAL_BACK,
                (U16)IMG_GLOBAL_BACK,
                (U16)file_count,
                (highlightId < 0) ? 0 : highlightId,
                0,
                instance_path,
                (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH,
                fmgr_gui_mediawall_get_file_info_cb,
                fmgr_gui_mediawall_get_file_path_cb,
                (U8*) guiBuffer);
        #else /* __MMI_VUI_MEDIAWALL__ */
        /*
		 * ShowCategory219Fmgrscreen is async dynamic matrix style 
		 * to replace ShowCategory214FmgrScreen.
		 */
            ShowCategory219FmgrScreen(   
                title_string_id,
                iconId,
                (U16)lsk_string_id,
                (U16)IMG_GLOBAL_OPTIONS,
                (U16)STR_GLOBAL_BACK,
                (U16)IMG_GLOBAL_BACK,
                (U16)file_count, /* num of item */
	            fmgr_gui_get_file_item_async_callback,
				NULL,
                fmgr_gui_draw_file_matrix_callback, /* draw image callback */
                fmgr_gui_hide_file_callback, /* hide image callback */
                (U8)FMGR_MATRIX_ROW_NUM, /* number per row */
                (U8)FMGR_MATRIX_COLUMN_NUM, /* number per col */
                (highlightId < 0) ? 0 : highlightId, /* hilighted item */
                (U8*) guiBuffer,
				 &cat_error);
        #endif /* __MMI_VUI_MEDIAWALL__ */
            break;
#endif
    #ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
        case FMGRI_DISPLAY_TYPE_MARK_SEVERL_LIST:
			wgui_cat1024_show(
				get_string(STR_GLOBAL_SELECT),
				get_image(iconId),
				get_string(lsk_string_id),
				get_image(IMG_GLOBAL_OPTIONS),
				get_string(STR_GLOBAL_BACK),
				get_image(IMG_GLOBAL_BACK),
				NULL,
				file_count,
				fmgr_gui_get_file_item_async_callback,
                NULL,
                fmgr_gui_get_file_marked_state,
                fmgr_gui_set_file_marked_state,
				IMG_GLOBAL_L1,
				0,
				highlightId,
				(U8*)guiBuffer);
            break;
    #endif /* __MMI_FMGR_MULTI_SELECT_SUPPORT__ */
        default:
            break;
#endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_display_drv_list
 * DESCRIPTION
 *  init gui context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_gui_display_drv_list(S32 highlightId, U32 file_count, U8 *guiBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 iconId, title_string_id;
#ifndef __MMI_SLIM_FILE_MANAGER__
    U16 list_style;
#endif
#ifdef __MMI_SLIM_FILE_MANAGER__
    S32 cat_error;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get title icon & string */
    mmi_fmgri_instance_get_title_info(fmgr_gui_p->instance_id, &title_string_id, &iconId);
#ifndef __MMI_SLIM_FILE_MANAGER__    
    /* get list style */
    list_style = mmi_fmgri_instance_get_list_style(fmgr_gui_p->instance_id);
#endif
    //wgui_fmgr_create_thumb_image_cache(MMI_thick_menuitem_height);            

    if(file_count == 0xFFFFFFFF)
        file_count = 0;

#ifdef __MMI_SLIM_FILE_MANAGER__
#ifndef __MMI_MAINLCD_96X64__ 
	wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
#endif
   	wgui_cat1032_show(
		get_string(title_string_id),
            #ifndef __MMI_MAINLCD_96X64__
		get_image(iconId),
            #else
                NULL,
            #endif /* __MMI_MAINLCD_96X64__ */
		get_string(STR_GLOBAL_OPTIONS),
		get_image(IMG_GLOBAL_OPTIONS),
		get_string(STR_GLOBAL_BACK),
		get_image(IMG_GLOBAL_BACK),
		file_count,
		fmgr_gui_get_drv_asy_item_callback,
		NULL,
		highlightId,
		0,
#ifdef __FS_CARD_SUPPORT__
		IMG_ID_FMGR_DRIVE_MEM_CARD,
#else
		0,
#endif
		0,
		(U8*) guiBuffer,
		&cat_error);
#ifndef __MMI_MAINLCD_96X64__
	wgui_restore_list_menu_slim_style();
#endif 
#else
    switch (list_style)
    {
        case FMGR_DISPLAY_TYPE_ICON_LIST:
            ShowCategory213FmgrScreen(
                title_string_id,
                iconId,                     /* title */
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,         /* lsk */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,            /* rsk */
                file_count,
                fmgr_gui_get_drv_menuitem_callback,
                fmgr_gui_hide_drv_menuitem_callback,
                highlightId,                /* hiligth item idx */
                CAT213_ARROW_ALL,
                (U8*) guiBuffer);
            break;

        case FMGRI_DISPLAY_TYPE_EXPAND_LIST:
        case FMGR_DISPLAY_TYPE_SIMPLE_LIST:
            ShowCategory185Screen(
               title_string_id, 
               iconId, 
               IMG_GLOBAL_OPTIONS, 
               IMG_GLOBAL_OPTIONS, 
               STR_GLOBAL_BACK, 
               IMG_GLOBAL_BACK, 
               file_count, 
               fmgr_gui_get_drv_item_callback, 
               fmgr_gui_get_drv_hint_callback, 
               highlightId,
               MMI_FALSE,
               NULL,
               (U8*) guiBuffer);
            break;

        default:
            ShowCategory212FmgrScreen(
                title_string_id,
                iconId,                         /* title */
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,             /* lsk */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,                /* rsk */
                file_count,
                fmgr_gui_get_drv_item_callback,
                fmgr_gui_get_drv_hint_callback,
                fmgr_gui_get_drv_info_callback,
                fmgr_gui_hide_drv_info_callback,
                2,                              /* info box row count */
                0,                              /* info bg img id */
                highlightId,
                (U8*) guiBuffer);            
            break;
    }
#endif
}

#define GUI_DRV_CALLBACK

static void fmgr_gui_format_drv(srv_fmgr_drv_type_enum drv_type, const U16* path, U16* buf, S32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 drv_str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (drv_type)
    {
        case SRV_FMGR_DRV_PHONE_TYPE:
            drv_str_id = STR_FMGR_NOR_FLASH;
            break;
        case SRV_FMGR_DRV_PHONE_2_TYPE:
            drv_str_id = STR_FMGR_NAND_FLASH;
            break;
       case SRV_FMGR_DRV_CARD_TYPE:
            drv_str_id = STR_FMGR_REM_DEVICE;
            break;
        case SRV_FMGR_DRV_CARD_2_TYPE:
            drv_str_id = STR_FMGR_REM_DEVICE;
            break;
        default:
        #ifdef __OTG_ENABLE__
            if (drv_type >= SRV_FMGR_DRV_OTG_TYPE && drv_type < SRV_FMGR_DRV_OTG_8_TYPE)
            {
                drv_str_id = STR_FMGR_USB_STORAGE + (U16)(drv_type - SRV_FMGR_DRV_OTG_TYPE);
                break;
            }
        #endif /* __OTG_ENABLE__ */
       #ifdef __SIM_PLUS__
            if (drv_type >= SRV_FMGR_DRV_SIMPLUS_TYPE && drv_type < SRV_FMGR_DRV_SIMPLUS_4_TYPE)
            {
                drv_str_id = STR_FMGR_SIM_PLUS;
                break;
            }
        #endif /* __SIM_PLUS__ */
            ASSERT(0);
            break;
    }

    mmi_ucs2ncpy((S8*)buf, (S8*)GetString(drv_str_id), buf_size);
    
#ifdef __FS_CARD_SUPPORT__
    if (drv_type == SRV_FMGR_DRV_CARD_TYPE ||
        drv_type == SRV_FMGR_DRV_CARD_2_TYPE)
    {
        srv_fmgr_drv_get_name((U8)path[0], (WCHAR *)buf, buf_size);
    }
#endif /* __FS_CARD_SUPPORT__ */
}

#ifdef __MMI_SLIM_FILE_MANAGER__
static S32 fmgr_gui_get_drv_asy_item_callback(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmgr_drive_info_struct drv_info;
    S32 drv_type;
	S32 i;
	UI_string_type str_buff[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(i = 0; i < data_size; i++)
	{
		 mmi_fmgri_fsdata_instance_get_drive_info(fmgr_gui_p->instance_id, start_index+i, &drv_info);
	#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
		if (drv_info.string_id || drv_info.icon_id)
		{
			menu_data[i].image_list[0] = (PU8) GetImage(drv_info.icon_id);
			mmi_wcsncpy((U16*) menu_data[i].item_list[0], (U16*)GetString(drv_info.string_id), 128);
			continue;
		}
	#endif /* __FMGR_CUSTOM_ROOT_SUPPORT__ */
		    /* Drive */
		drv_type = drv_info.drv_type;

		/* String */
		fmgr_gui_format_drv((srv_fmgr_drv_type_enum)drv_type, (U16*)drv_info.drv_path, (U16*)str_buff, 128);
		mmi_wcsncpy((U16*) menu_data[i].item_list[0], (U16*)str_buff, 128);

		/* Icon */
#ifndef __MMI_MAINLCD_96X64__
#if !defined (__MMI_ULTRA_SLIM_FILE_MANAGER__) || defined (__PUBLIC_DRIVE_AVAILABLE__)
		if (drv_type < SRV_FMGR_DRV_CARD_TYPE)
		{
			menu_data[i].image_list[0] =  (PU8) GetImage(IMG_ID_FMGR_DRIVE_PHONE);
		}
	#ifdef __FS_CARD_SUPPORT__
		else
		{
			menu_data[i].image_list[0] = (PU8) GetImage(IMG_ID_FMGR_DRIVE_MEM_CARD);
		}
	#endif /* __FS_CARD_SUPPORT__ */
#else
        /* There is no Public Phone memory */
        #ifdef __FS_CARD_SUPPORT__
			menu_data[i].image_list[0] = (PU8) GetImage(IMG_ID_FMGR_DRIVE_MEM_CARD);
	    #endif /* __FS_CARD_SUPPORT__ */
#endif  /* __MMI_ULTRA_SLIM_FILE_MANAGER__ */
#endif /* __MMI_MAINLCD_96X64__ */
	}
	 return data_size;
}
#endif

#ifndef __MMI_SLIM_FILE_MANAGER__
/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_get_drv_item_callback
 * DESCRIPTION
 *  callback function for getting dynamic list item
 * PARAMETERS
 *  item_idx            [IN]        Index
 *  str_buff            [OUT]       String buffer
 *  img_buff_p          [OUT]       Image buffer ptr
 *  str_img_mask        [IN]        Mask
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL fmgr_gui_get_drv_item_callback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmgr_drive_info_struct drv_info;
    S32 ret;
    S32 drv_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *img_buff_p = NULL;

    ret = mmi_fmgri_fsdata_instance_get_drive_info(fmgr_gui_p->instance_id, item_idx, &drv_info);

    if (ret < 0)
    {
        return MMI_FALSE;
    }

#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
    if (drv_info.string_id || drv_info.icon_id)
    {
        *img_buff_p = (PU8) GetImage(drv_info.icon_id);
        mmi_wcsncpy((U16*)str_buff, (U16*)GetString(drv_info.string_id), 128);
        return MMI_TRUE;
    }
#endif /* __FMGR_CUSTOM_ROOT_SUPPORT__ */

    /* Drive */
    drv_type = drv_info.drv_type;

    if (drv_type < 0)
    {
        return MMI_FALSE;
    }

    /* String */
    fmgr_gui_format_drv((srv_fmgr_drv_type_enum)drv_type, (U16*)drv_info.drv_path, (U16*)str_buff, 128);

    /* Icon */
#ifndef __MMI_MAINLCD_96X64__
#if !defined (__MMI_ULTRA_SLIM_FILE_MANAGER__) || defined (__PUBLIC_DRIVE_AVAILABLE__)
    if (drv_type < SRV_FMGR_DRV_CARD_TYPE)
    {
        *img_buff_p = (PU8) GetImage(IMG_ID_FMGR_DRIVE_PHONE);
    }
#ifdef __FS_CARD_SUPPORT__
    else
    {
        *img_buff_p = (PU8) GetImage(IMG_ID_FMGR_DRIVE_MEM_CARD);
    }
#endif /* __FS_CARD_SUPPORT__ */
#else
    /* There is no Public Phone memory */
    #ifdef __FS_CARD_SUPPORT__
	    *img_buff_p = (PU8) GetImage(IMG_ID_FMGR_DRIVE_MEM_CARD);
	#endif /* __FS_CARD_SUPPORT__ */
#endif  /* __MMI_ULTRA_SLIM_FILE_MANAGER__ */
#endif /* __MMI_MAINLCD_96X64__ */
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_get_drv_hint_callback
 * DESCRIPTION
 *  callback function for getting dynamic list hint
 * PARAMETERS
 *  item_idx        [IN]        Index
 *  hint_array      [OUT]       Hint string
 * RETURNS
 *  void
 *****************************************************************************/
static S32 fmgr_gui_get_drv_hint_callback(S32 item_idx, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_get_drv_info_callback
 * DESCRIPTION
 *  callback function for getting drv info
 * PARAMETERS
 *  item_idx        [IN]        Index
 *  fmgr_info      [OUT]        data of drv info
 * RETURNS
 *  void
 *****************************************************************************/
static void fmgr_gui_get_drv_info_callback(S32 item_idx, wgui_fmgr_info_struct *fmgr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmgr_drive_info_struct drv_info;
    S32 fs_ret;
    U64 disk_free_space;
    U64 disk_total_space;
    U32 ratio;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fmgr_info->info_type = WGUI_CAT21X_INFO_TYPE_DRV;

    fs_ret = mmi_fmgri_fsdata_instance_get_drive_info(fmgr_gui_p->instance_id, item_idx, &drv_info);

    if (fs_ret < 0)
    {
        mmi_ucs2ncpy((S8*)fmgr_info->info_text_l1_s2, (S8*)drv_info.drv_path, 32);
        kal_wsprintf(fmgr_info->info_text_l2_s2, "%d", fs_ret);
    #ifndef __MMI_SLIM_FILE_MANAGER__
        fmgr_info->file_icon_ptr = (PU8) GetImage(IMG_ID_FMGR_DRIVE_SPACE_0);
    #else /* __MMI_SLIM_FILE_MANAGER__ */
        fmgr_info->file_icon_ptr = NULL;
    #endif /* __MMI_SLIM_FILE_MANAGER__ */
        return;
    }

#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
    if (drv_info.drv_type < 0)
    {
        /* Link folder, not support yet */
        ASSERT(0);
        return;
    }
#endif /* __FMGR_CUSTOM_ROOT_SUPPORT__ */

    if (srv_fmgr_drv_is_accessible((U8)drv_info.drv_path[0]) == MMI_FALSE)
    {
        fmgr_info->info_text_l1_s1 = (UI_string_type)GetString(STR_GLOBAL_NOT_AVAILABLE);
        fmgr_info->drv_ratio = 0;
    #ifndef __MMI_SLIM_FILE_MANAGER__
        fmgr_info->file_icon_ptr = (PU8) GetImage((U16) (IMG_ID_FMGR_DRIVE_SPACE_0));
    #else /* __MMI_SLIM_FILE_MANAGER__ */
        fmgr_info->file_icon_ptr = NULL;
    #endif /* __MMI_SLIM_FILE_MANAGER__ */
        return;
    }

    /* Get Drive info  */
    fs_ret = srv_fmgr_drv_get_size((U8)drv_info.drv_path[0], &disk_total_space, &disk_free_space);

    ratio = 0;

    if (fs_ret >= 0)
    {
        ratio = (U32) (disk_free_space * 100 / disk_total_space);
        ratio += 5;
        ratio /= 10;

        if (ratio > 10)
        {
            ratio = 0;
        }
    }

    fmgr_info->drv_ratio = ratio;
#ifndef __MMI_SLIM_FILE_MANAGER__
    fmgr_info->file_icon_ptr = (PU8) GetImage((U16) (IMG_ID_FMGR_DRIVE_SPACE_0 + ratio));
#else /* __MMI_SLIM_FILE_MANAGER__ */
    fmgr_info->file_icon_ptr = NULL;
#endif /* __MMI_SLIM_FILE_MANAGER__ */
    
    /* Total Size String */
    fmgr_info->info_text_l1_s1 = (UI_string_type)GetString(STR_ID_FMGR_DRV_TOTAL_SPACE);
    mmi_fmgri_gui_format_size(disk_total_space, fmgr_info->info_text_l1_s2, 32);

    /* Free Size String */
    fmgr_info->info_text_l2_s1 = (UI_string_type)GetString(STR_ID_FMGR_DRV_FREE_SPACE);
    mmi_fmgri_gui_format_size(disk_free_space, fmgr_info->info_text_l2_s2, 64);

}

/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_draw_drv_info_callback
 * DESCRIPTION
 *  callback function for draw seleted drv info
 * PARAMETERS
 *  item_idx        [IN]        Index
 *  x1              [IN]        X1 string
 *  y1              [IN]        Y1
 *  x2              [IN]        X2
 *  y2              [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
/*void fmgr_gui_draw_drv_info_callback(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    wgui_cat22x_get_info_ptr = wgui_cat22x_get_drv_info_data;
    wgui_cat22x_draw_info(item_idx, x1, y1, x2, y2);
}*/


/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_hide_drv_info_callback
 * DESCRIPTION
 *  callback function for stop draw seleted drv info
 *  this shall be called to stop animation, timer or non-blocking decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void fmgr_gui_hide_drv_info_callback(void)
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
 *  fmgr_gui_get_drv_menuitem_callback
 * DESCRIPTION
 *  callback function for get drv menuitem data
 * PARAMETERS
 *  item_idx        index of item
 *  is_hilighted    is highlight
 *  menuitem_data   data to add.
 * RETURNS
 *  void
 *****************************************************************************/
static void fmgr_gui_get_drv_menuitem_callback(S32 item_idx, BOOL is_hilighted, wgui_fmgr_menuitem_data_struct *menuitem_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmgr_drive_info_struct drv_info;
    S32 ret;
    srv_fmgr_drv_type_enum drv_type;
    S32 fs_ret;
    U64 disk_free_space;
    U64 disk_total_space;
    U32 ratio;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    menuitem_data->info_type = WGUI_CAT21X_INFO_TYPE_DRV;

    ret = mmi_fmgri_fsdata_instance_get_drive_info(fmgr_gui_p->instance_id, item_idx, &drv_info);

    if (ret < 0)
    {
        return;
    } 

#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
    if (drv_info.drv_type < 0)  /* link folder, not support yet */
    {
        ASSERT(0);
        return;
    }
#endif /* __FMGR_CUSTOM_ROOT_SUPPORT__ */

    drv_type = (srv_fmgr_drv_type_enum)drv_info.drv_type;

    /* Name */
    fmgr_gui_format_drv(drv_type, (U16*)drv_info.drv_path, (U16*)menuitem_data->menu_text_l1_s1, MAX_SUBMENU_CHARACTERS);

    if (srv_fmgr_drv_is_accessible((U8)drv_info.drv_path[0]) == MMI_FALSE)
    {
        mmi_wcscpy((U16*)menuitem_data->menu_text_l2_s1, (U16*)GetString(STR_GLOBAL_NOT_AVAILABLE));
        menuitem_data->drv_ratio = 0;
    #ifndef __MMI_SLIM_FILE_MANAGER__
        menuitem_data->file_icon_ptr = (PU8) GetImage((U16) (IMG_ID_FMGR_DRIVE_SPACE_0));
    #else /* __MMI_SLIM_FILE_MANAGER__ */
        menuitem_data->file_icon_ptr = NULL;
    #endif /* __MMI_SLIM_FILE_MANAGER__ */
        return;
    }

    /* Get Drive info */
    fs_ret = srv_fmgr_drv_get_size((U8)drv_info.drv_path[0], &disk_total_space, &disk_free_space);

    ratio = 0;

    if (fs_ret >= 0)
    {
        ratio = (U32) (disk_free_space * 100 / disk_total_space);
        ratio += 5;
        ratio /= 10;

        if (ratio > 10)
        {
            ratio = 0;
        }
    }

    /* Get  Drv Size */
    mmi_fmgri_gui_format_size(disk_free_space, menuitem_data->menu_text_l2_s1, 32);
    mmi_wcscat((U16*)menuitem_data->menu_text_l2_s1, L"/");
    fs_ret = mmi_wcslen((U16*)menuitem_data->menu_text_l2_s1);
    mmi_fmgri_gui_format_size(disk_total_space, menuitem_data->menu_text_l2_s1+fs_ret, 32-fs_ret);

    /* Get  Icon */
    menuitem_data->drv_ratio = ratio;
#ifndef __MMI_SLIM_FILE_MANAGER__
    menuitem_data->file_icon_ptr = (PU8) GetImage((U16) (IMG_ID_FMGR_DRIVE_SPACE_0 + ratio));
#else /* __MMI_SLIM_FILE_MANAGER__ */
    menuitem_data->file_icon_ptr = NULL;
#endif /* __MMI_SLIM_FILE_MANAGER__ */
    
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_hide_drv_menuitem_callback
 * DESCRIPTION
 *  hide drv menitem's callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void fmgr_gui_hide_drv_menuitem_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* #ifndef __MMI_SLIM_FILE_MANAGER__ */
#define GUI_FILE_CALLBACK

static void fmgr_gui_update_screen(void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(fmgr_gui_p->refresh_timer_on == MMI_FALSE)
    {
        return;
    }
    fmgr_gui_p->refresh_timer_on = MMI_FALSE;
    id = (U32)arg;
    mmi_fmgri_instance_general_refresh_by_id((U8)id, FMGRI_INSTANCE_INDEX_NOT_CHANGE);
}

void mmi_fmgri_gui_format_size(U64 file_size, U16* buffer, S32 buffer_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char postfix[] = {"BKMG"};
    U64 unit = 1;
    S32 i = 0;
    U32 part_int, part_mod;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (file_size >= 1024*unit && postfix[i] != 'G')
    {
        unit *= 1024;
        i++;
    }

    part_int = (U32)( file_size / unit );
    part_mod = (U32)( ((file_size % unit)*10)/unit );

    if (part_mod)
    {
        kal_wsprintf(buffer, "%d.%d%c", part_int, part_mod, postfix[i]);
    }
    else
    {
        kal_wsprintf(buffer, "%d%c", part_int, postfix[i]);
    }
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void fmgr_gui_hide_file_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

static S32 fmgr_gui_load_file_info(U8 id, S32 index, FMGR_FILE_INFO_STRUCT* file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_fmgri_fsdata_instance_get_file_info_ex(id, index, file_info);
    if (ret < 0)
    {
        if ((fmgr_gui_p->refresh_timer_on == MMI_FALSE) &&
            ((ret == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)))
        {
            fmgr_gui_p->refresh_timer_on = MMI_TRUE;
            StartNonAlignTimerEx(FMGR_SCR_TIMER, 10, fmgr_gui_update_screen, (void*)id);
        }
        return ret;
    }

    return 0;
}

#ifndef __MMI_SLIM_FILE_MANAGER__
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
#ifdef __FMGR_HYPERLINK_SUPPORT__
/* under construction !*/
#endif /* __FMGR_HYPERLINK_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
/* under construction !*/
#else /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
/* under construction !*/
#endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
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
#ifdef __FMGR_HYPERLINK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __FMGR_HYPERLINK_SUPPORT__ */
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
#endif /* #if 0 */

/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_get_file_info_callback
 * DESCRIPTION
 *  callback function for getting file info
 * PARAMETERS
 *  item_idx        [IN]        Index
 *  fmgr_info       [IN]        file info data
 * RETURNS
 *  void
 *****************************************************************************/
static void fmgr_gui_get_file_info_callback(S32 item_idx, wgui_fmgr_info_struct *fmgr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT *file_info = NULL;
    S8 *instance_path;
    S8 *buffer_path = NULL;
#ifdef __FMGR_HYPERLINK_SUPPORT__
    mmi_fmgr_hyperlink_info_struct info;
#endif /* __FMGR_HYPERLINK_SUPPORT__ */
#if (LCD_WIDTH <= 128)
    static const S8 empty_wstr[] = {0x00, 0x00};
#endif
    mmi_img_id icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_PERF_START(fmgr_gui_get_file_info_callback, item_idx);

    fmgr_info->file_icon_ptr = NULL;
    
    fmgr_info->info_type = WGUI_CAT21X_INFO_TYPE_FILE;

    file_info = OslMalloc(sizeof(FMGR_FILE_INFO_STRUCT));
    memset(file_info, 0, sizeof(FMGR_FILE_INFO_STRUCT));
    
    if (fmgr_gui_load_file_info(fmgr_gui_p->instance_id, item_idx, file_info) < 0)
    {
    #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
        fmgr_info->file_icon_ptr = get_image(IMG_ID_FMGR_FILE_TYPE_UNKNOWN);
    #endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
        fmgr_info->is_show_thumb = MMI_FALSE;
        OslMfree(file_info);
        return;
    }

    mmi_fmgri_instance_get_filepath_and_filter(fmgr_gui_p->instance_id, &instance_path, NULL);

#ifdef __FMGR_HYPERLINK_SUPPORT__
    if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_HYPER_LINK))
    {
        mmi_fmgri_instance_get_hyperlink_info(fmgr_gui_p->instance_id, item_idx, &info);
        fmgr_info->info_text_l1_s1 = (UI_string_type) info.string_ptr;
        fmgr_info->info_text_l2_s1 = (UI_string_type) info.sub_string_ptr;
        goto Draw_Large_Icon;
    }
#endif /* __FMGR_HYPERLINK_SUPPORT__ */

    /* Get Size Text */
    if (!(file_info->attribute & FS_ATTR_DIR))
    {
        fmgr_info->info_text_l1_s1 = (UI_string_type) GetString(STR_ID_FMGR_FILE_SIZE);
        mmi_fmgri_gui_format_size(file_info->file_size, fmgr_info->info_text_l1_s2, 32);
    }

    /* Get Date Text */
#if (LCD_WIDTH <= 128)
    /* We do not have enough room to put all dat format, skip "date:" display */
    {
        fmgr_info->info_text_l2_s1 = (UI_string_type)empty_wstr;
    }
#else /* (LCD_WIDTH <= 128) */
    fmgr_info->info_text_l2_s1 = (UI_string_type) GetString(STR_ID_FMGR_FILE_DATE);
#endif /* (LCD_WIDTH <= 128) */
    date_string(&file_info->time, (PU16)fmgr_info->info_text_l2_s2, DT_FILEMANAGER);

    /* Draw Large Icon */
    
#ifdef __FMGR_HYPERLINK_SUPPORT__
Draw_Large_Icon:
    if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_HYPER_LINK))
    {
        fmgr_info->file_icon_ptr = (PU8)GetImage(info.large_icon_id);
    }
    else
#endif /* __FMGR_HYPERLINK_SUPPORT__ */
    {
        icon = srv_fmgr_types_get_icon(srv_fmgr_types_get_main_type(&file_info->file_type),
                      NULL,
                      SRV_FMGR_TYPES_ICON_LARGE);
        fmgr_info->file_icon_ptr = (PU8)GetImage(icon);
    }

    fmgr_info->is_show_thumb = MMI_FALSE;

    /* Check if can preview */
    buffer_path = mmi_fmgri_get_and_lock_buffer();    
    do {
        
        if (!mmi_fmgri_filepath_compose(buffer_path, 
                  (SRV_FMGR_PATH_MAX_LEN + 1),
                  fmgr_gui_p->instance->file_path,
                  file_info,
                  MMI_FALSE))
        {
            break;
        }

        /* draw thumb image */
        if (file_info->attribute & FS_ATTR_DIR)
        {
            break;
        }

        if (FMGR_FILTER_IS_SET_IMAGE(&file_info->file_type))
        {
            fmgr_info->is_show_thumb = MMI_TRUE;
            break;
        }
        
    #ifdef __MMI_FMGR_CUSTICON_SUPPORT__
        if (srv_fmgr_custicon_query((WCHAR *)buffer_path, NULL, 0) == 0)
        {
            fmgr_info->is_show_thumb = MMI_TRUE;
            break;
        }
    #endif /* __MMI_FMGR_CUSTICON_SUPPORT__ */
    }while(0);
    mmi_fmgri_free_and_unlock_buffer(buffer_path);
    OslMfree(file_info);
    FMGR_PERF_END(fmgr_gui_get_file_info_callback);
}

/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_get_file_menuitem_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_idx        index of item
 *  is_hilighted    is highlight
 *  menuitem_data   data to add.
 * RETURNS
 *  void
 *****************************************************************************/
static void fmgr_gui_get_file_menuitem_callback(S32 item_idx, BOOL is_hilighted, wgui_fmgr_menuitem_data_struct *menuitem_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT *file_info = NULL;
    S8 *buffer_path = NULL;
#ifdef __FMGR_HYPERLINK_SUPPORT__
    mmi_fmgr_hyperlink_info_struct  info;
#endif /* __FMGR_HYPERLINK_SUPPORT__ */
    mmi_img_id icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_PERF_START(fmgr_gui_get_file_menuitem_callback, item_idx);

    menuitem_data->file_icon_ptr = NULL;
    menuitem_data->info_type = WGUI_CAT21X_INFO_TYPE_FILE;

    SET_UCS2STR_EMPTY(menuitem_data->menu_text_l1_s1);
    SET_UCS2STR_EMPTY(menuitem_data->menu_text_l2_s1);
    SET_UCS2STR_EMPTY(menuitem_data->menu_text_l2_s2);

    file_info = OslMalloc(sizeof(FMGR_FILE_INFO_STRUCT));
    memset(file_info, 0, sizeof(FMGR_FILE_INFO_STRUCT));

    if (fmgr_gui_load_file_info(fmgr_gui_p->instance_id, item_idx, file_info) < 0)
    {
        menuitem_data->is_show_thumb = MMI_FALSE;
        OslMfree(file_info);
        return;
    }

#ifdef __FMGR_HYPERLINK_SUPPORT__
    if (FMGR_FILTER_IS_SET(&(file_info->file_type), FMGR_TYPE_HYPER_LINK))
    {
        mmi_fmgri_instance_get_hyperlink_info(fmgr_gui_p->instance_id, item_idx, &info);

        mmi_ucs2ncpy((PS8)menuitem_data->menu_text_l1_s1, (PS8) info.string_ptr, MAX_SUBMENU_CHARACTERS);

        if(info.sub_string_ptr)
        {
            mmi_ucs2cpy((PS8) menuitem_data->menu_text_l2_s1, (PS8) info.sub_string_ptr);
        }

        menuitem_data->file_icon_ptr= (PU8)GetImage(info.large_icon_id);
        menuitem_data->is_show_thumb = MMI_FALSE;
        FMGR_PERF_END(fmgr_gui_get_file_menuitem_callback);
        OslMfree(file_info);
        return;
    }
#endif /* __FMGR_HYPERLINK_SUPPORT__ */

    /* Get  File Name */
    if (file_info->is_short)
    {
        mmi_chset_mixed_text_to_ucs2_str(
            (U8*) menuitem_data->menu_text_l1_s1,
            sizeof(menuitem_data->menu_text_l1_s1),
            (U8*) file_info->file_name,
            PhnsetGetDefEncodingType());
    }
    else
    {
        mmi_ucs2ncpy((PS8)menuitem_data->menu_text_l1_s1, (PS8)file_info->file_name, MAX_SUBMENU_CHARACTERS);
    }

    fmgr_gui_hide_ext_name((PS8) menuitem_data->menu_text_l1_s1, file_info);

    /* Get  File Creation Date */
    if ((file_info->attribute & FS_ATTR_DIR) || (!(file_info->attribute & FS_ATTR_DIR) && UI_device_width > 128))
    {
        /* we do not have enough room to put all dat format, we use sub's foramt */
        date_string(&file_info->time, (PU16) menuitem_data->menu_text_l2_s1, DT_FILEMANAGER);
    }    
    else
    {
        SET_UCS2STR_EMPTY(menuitem_data->menu_text_l2_s1);
    }

    /* Get  File Size */
    if (!(file_info->attribute & FS_ATTR_DIR))
    {
        mmi_fmgri_gui_format_size(file_info->file_size, menuitem_data->menu_text_l2_s2, 64);
    }
    else
    {
        SET_UCS2STR_EMPTY(menuitem_data->menu_text_l2_s2);
    }    

    /* Get  Large Icon */
#ifdef __FMGR_HYPERLINK_SUPPORT__
    if (FMGR_FILTER_IS_SET(&(file_info->file_type), FMGR_TYPE_HYPER_LINK))
    {
        mmi_fmgri_instance_get_hyperlink_info(fmgr_gui_p->instance_id, item_idx, &info);
        menuitem_data->file_icon_ptr= (PU8)GetImage(info.large_icon_id);
    }
    else
#endif /* __FMGR_HYPERLINK_SUPPORT__ */
    {
        icon = srv_fmgr_types_get_icon(srv_fmgr_types_get_main_type(&(file_info->file_type)),
                      NULL,
                      SRV_FMGR_TYPES_ICON_LARGE);
        menuitem_data->file_icon_ptr = (PU8)GetImage(icon);
    }

    menuitem_data->is_show_thumb = MMI_FALSE;


    /* Check if can preview */
    do {

        if (file_info->attribute & FS_ATTR_DIR)
        {
            break;
        }

        buffer_path = mmi_fmgri_get_and_lock_buffer();
        if (mmi_fmgri_filepath_compose(buffer_path,
                (SRV_FMGR_PATH_MAX_LEN + 1),
                fmgr_gui_p->instance->file_path,
                file_info,
                MMI_FALSE) == MMI_FALSE)
        {
            break;
        }

        if (FMGR_FILTER_IS_SET_IMAGE(&file_info->file_type))
        {
            menuitem_data->is_show_thumb = MMI_TRUE;
            break;
        }
    #ifdef __MMI_FMGR_CUSTICON_SUPPORT__
        if (srv_fmgr_custicon_query((WCHAR *)buffer_path, NULL, 0) == 0)
        {
            menuitem_data->is_show_thumb = MMI_TRUE;
            break;
        }
    #endif /* __MMI_FMGR_CUSTICON_SUPPORT__ */

    }while(0);

    if (buffer_path != NULL)
    {
        mmi_fmgri_free_and_unlock_buffer(buffer_path);
        buffer_path = NULL;
    }
    FMGR_PERF_END(fmgr_gui_get_file_menuitem_callback);
    OslMfree(file_info);

}
#endif /* __MMI_SLIM_FILE_MANAGER__ */

#ifndef __MMI_VUI_MEDIAWALL__
/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_draw_file_matrix_callback
 * DESCRIPTION
 *  draw matrix file item
 * PARAMETERS
 *  idx                     [IN]        Selected index
 *  page_start_idx          [IN]        Page's start index
 *  page_end_idx            [IN]        Page's end index
 *  is_hilighted            [IN]        
 *  is_need_update          [IN]        Is thie item need update
 *  is_new_page             [IN]        Is first time draw this page
 *  x1                      [IN]        Draw region's x1
 *  y1                      [IN]        Draw region's y1
 *  x2                      [IN]        Draw region's x2
 *  y2                      [IN]        Draw region's y2
 *  is_highlghted(?)        [IN]        Is this selection highlighted
 * RETURNS
 *  void
 *****************************************************************************/
static void fmgr_gui_draw_file_matrix_callback(S32 idx, BOOL is_hilighted, wgui_fmgr_menuitem_data_struct *menuitem_data) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT_SLIM__
    S8 buffer_path[SRV_FMGR_PATH_BUFFER_SIZE] = {0}; 
    FMGR_FILE_INFO_STRUCT *file_info = NULL;
    mmi_img_id file_icon;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT_SLIM__
    menuitem_data->file_icon_ptr = (PU8) GetImage(IMG_ID_FMGR_FILE_TYPE_BMP); //NULL;
    menuitem_data->is_show_thumb = MMI_TRUE;
	return;
#else
    menuitem_data->file_icon_ptr = NULL;
    menuitem_data->is_show_thumb = MMI_FALSE;

    file_info = OslMalloc(sizeof(FMGR_FILE_INFO_STRUCT));
    memset(file_info, 0, sizeof(FMGR_FILE_INFO_STRUCT));
    
    if (fmgr_gui_load_file_info(fmgr_gui_p->instance_id, idx, file_info) < 0)
    {
        OslMfree(file_info);
        return;
    }

    file_icon = srv_fmgr_types_get_icon((filetypes_file_type_enum)srv_fmgr_types_get_main_type(&file_info->file_type),
                        NULL,
                        SRV_FMGR_TYPES_ICON_LARGE);
    menuitem_data->file_icon_ptr = (PU8) GetImage(file_icon);
 
    /* Check if can preview */
    do {
        if (file_info->attribute & FS_ATTR_DIR)  /* No folder preview */
        {
            break;
        }

        if (mmi_fmgri_filepath_compose(buffer_path, (SRV_FMGR_PATH_MAX_LEN + 1),
                                      fmgr_gui_p->instance->file_path, file_info, MMI_FALSE) == MMI_FALSE)
        {
            break;
        }

        if (FMGR_FILTER_IS_SET_IMAGE(&file_info->file_type))
        {
            menuitem_data->is_show_thumb = MMI_TRUE;
            break;
        }

    #ifdef __MMI_FMGR_CUSTICON_SUPPORT__
        if (srv_fmgr_custicon_query((WCHAR*)buffer_path, NULL, 0) == 0)
        {
            menuitem_data->is_show_thumb = MMI_TRUE;
            break;
        }
    #endif /* __MMI_FMGR_CUSTICON_SUPPORT__ */
    } while(0); 

    if (file_info != NULL)
    {
        OslMfree(file_info);
    }
#endif
}
#endif

#ifdef __MMI_VUI_MEDIAWALL__
static void fmgr_gui_mediawall_get_file_info_cb(S32 item_idx, BOOL is_hilighted, vapp_mediawall_fmgr_file_data_struct *out_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
#ifdef __FMGR_HYPERLINK_SUPPORT__
    mmi_fmgr_hyperlink_info_struct  info;
#endif /* __FMGR_HYPERLINK_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    out_info->file_icon_ptr = NULL;
    out_info->info_type = WGUI_CAT21X_INFO_TYPE_FILE;
    out_info->is_show_thumb = MMI_FALSE;

    SET_UCS2STR_EMPTY(out_info->file_name);

    if (fmgr_gui_load_file_info(fmgr_gui_p->instance_id, item_idx, &file_info) < 0)
    {
        return;
    }

#ifdef __FMGR_HYPERLINK_SUPPORT__
    if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_HYPER_LINK))
    {
        mmi_fmgri_instance_get_hyperlink_info(fmgr_gui_p->instance_id, item_idx, &info);

        mmi_ucs2cpy((PS8) out_info->file_name, (PS8) info.string_ptr);
        out_info->file_icon_ptr= (PU8)GetImage(info.large_icon_id);
        return;
    }
#endif /* __FMGR_HYPERLINK_SUPPORT__ */

    /* Get  File Name */
    mmi_ucs2cpy((PS8) out_info->file_name, (PS8) file_info.file_name);
    fmgr_gui_hide_ext_name((PS8) out_info->file_name, &file_info);

    /* Get  Large Icon */
    out_info->file_icon_ptr = (PU8)GetImage(srv_fmgr_types_get_icon((U16)srv_fmgr_types_get_main_type(&file_info.file_type), NULL, SRV_FMGR_TYPES_ICON_LARGE));

    /* Get  Preview */
    do {

        if (file_info.attribute & FS_ATTR_DIR)
        {
            break;
        }
        
        out_info->is_show_thumb = MMI_TRUE;
        
    }while(0);
}

static S32 fmgr_gui_mediawall_get_file_path_cb(S32 item_idx, S8 *file_path, S32 file_path_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
        /* Get file info */
        ret = fmgr_gui_load_file_info(fmgr_gui_p->instance_id, (U16) (item_idx), &file_info);
        if (ret < 0)
        {
            break;
        }

        /* Path too long */
        if (!mmi_fmgri_filepath_compose(file_path, file_path_size/2,
                 fmgr_gui_p->instance->file_path, &file_info, MMI_FALSE))
        {
            ret = FS_PATH_OVER_LEN_ERROR;
            break;
        }

        ret = 0;
    } while(0);

    if (ret < 0)
    {
        fmgr_gui_set_index_displayable(item_idx, MMI_FALSE);
    }
    return ret;    
}
#endif /* __MMI_VUI_MEDIAWALL__ */

/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_hide_ext_name
 * DESCRIPTION
 *  hide ext. file name
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
static void fmgr_gui_hide_ext_name(S8 *str_buf_ptr, FMGR_FILE_INFO_STRUCT *info_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ext = (PS8 )srv_fmgr_path_get_extension_ptr((WCHAR*)str_buf_ptr);

#ifndef __MMI_SHOW_FILE_EXT__
    /* Hide all ext */
    if (!(info_ptr->attribute & FS_ATTR_DIR))   /* Not folder */
    {
        if (ext)
        {
            ext-=2;
            ext[0] = ext[1] = 0;
        }
    }
#else /* __MMI_SHOW_FILE_EXT__ */ 
    /* Show others except and test daf */
#ifndef __MMI_SHOW_DAF_FILE_EXT__
    /* Hide daf */
    if (FMGR_FILTER_IS_SET(&info_ptr->file_type, FMGR_TYPE_DAF) ||
        FMGR_FILTER_IS_SET(&info_ptr->file_type, FMGR_TYPE_MP2) )
    {
        if (ext)
        {
            ext -= 2;
            ext[0] = ext[1] = 0;
        }
    }
#endif /* __MMI_SHOW_DAF_FILE_EXT__ */ 
#endif /* __MMI_SHOW_FILE_EXT__ */ 

}

#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__        
static S32 fmgr_gui_get_file_marked_state(S32 index, PU8 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = 0;
    mmi_fmgri_instance_execute_command(fmgr_gui_p->instance_id, FMGRI_CMD_GET_MARK_STATE, index, &ret);
    if (ret)
    {
        *value = (PU8)GetImage(CHECKBOX_ON_IMAGE_ID);
    }
    else
    {
        *value = (PU8)GetImage(CHECKBOX_OFF_IMAGE_ID);
    }
    return MMI_TRUE;
}

static S32 fmgr_gui_set_file_marked_state(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_fmgri_instance_execute_command(fmgr_gui_p->instance_id, FMGRI_CMD_TOGGLE_MARK_STATE, index, NULL);
}
#endif

static void fmgr_gui_notify_highlight_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_gui_p->prefer_index = index;
}

static S32 fmgr_gui_get_file_item_async_callback(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *instance_path;
    U8 instance_id;
    S32 offset, ret;
#ifndef __MMI_MAINLCD_96X64__
    mmi_img_id icon;
    S8 *buffer;
#endif /* __MMI_MAINLCD_96X64__ */
    FMGR_FILE_INFO_STRUCT *file_info = NULL;
#ifdef __FMGR_HYPERLINK_SUPPORT__
    mmi_fmgr_hyperlink_info_struct  link_info;
#endif /* __FMGR_HYPERLINK_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    instance_id = fmgr_gui_p->instance_id;

    mmi_fmgri_instance_get_filepath_and_filter(instance_id, &instance_path, NULL);

    ret = 0;

    file_info = OslMalloc(sizeof(FMGR_FILE_INFO_STRUCT));
    memset(file_info, 0, sizeof(FMGR_FILE_INFO_STRUCT));
    
    for (offset = 0; offset < data_size; offset++)
    {
        ret = mmi_fmgri_fsdata_instance_get_file_info_ex(instance_id, start_index + offset, file_info);

        if (ret < 0)
        {
            /* Do refresh, should enter processing screen */
			if (ret > SRV_FMGR_FILELIST_ERROR_END)
			{
			    /* If it is file system's error code, file list may be not reliable.
                   So we release file list handle here, 
                   then it will be refreshed in mmi_fmgri_fsdata_instance_load_data_async */
				mmi_fmgri_fsdata_instance_release_load(instance_id);
			}

			mmi_fmgri_instance_general_refresh_by_id(instance_id, fmgr_gui_p->prefer_index);
            offset = WGUI_GET_DATA_NONE;
            break;
        }
        else
        {
            if (mmi_ucs2strlen((S8*)file_info->file_name) > MAX_SUBMENU_CHARACTERS)
            {
                mmi_ucs2ncpy((S8*) menu_data[offset].item_list[0], (S8*)file_info->file_name, MAX_SUBMENU_CHARACTERS - 3);
                mmi_ucs2cat((S8*) menu_data[offset].item_list[0], (S8*) L"...");
            }
            else
            {
                mmi_ucs2ncpy((S8*) menu_data[offset].item_list[0], (S8*)file_info->file_name, MAX_SUBMENU_CHARACTERS);
                fmgr_gui_hide_ext_name((S8*) menu_data[offset].item_list[0], file_info);
            }
#ifndef __MMI_MAINLCD_96X64__
            /* File icon */
            buffer = mmi_fmgri_get_and_lock_buffer();
            mmi_fmgri_filepath_compose(buffer, (SRV_FMGR_PATH_MAX_LEN + 1), instance_path, file_info, MMI_FALSE);

        #ifdef __FMGR_HYPERLINK_SUPPORT__
            if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_HYPER_LINK))
            {
                mmi_fmgri_instance_get_hyperlink_info(instance_id, start_index + offset, &link_info);
                menu_data[offset].image_list[0] = (PU8)GetImage(link_info.small_icon_id);
            }
            else
        #endif /* __FMGR_HYPERLINK_SUPPORT__ */
            {
                icon = srv_fmgr_types_get_icon(srv_fmgr_types_get_main_type(&file_info->file_type), (WCHAR*)buffer, SRV_FMGR_TYPES_ICON_SMALL);
                menu_data[offset].image_list[0] = (PU8)GetImage(icon);
            }
            mmi_fmgri_free_and_unlock_buffer(buffer);
#endif  /* __MMI_MAINLCD_96X64__ */
        }
    }

    OslMfree(file_info);
    return offset;
}


#endif /* (__MMI_FILE_MANAGER__) */
