/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  ScreenLockKeyImageSetting.c
 *
 * Project:
 * --------
 *  MAUI
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__

#include "ScrLockerMain.h"
#include "ScreenLockKeyImageSetting.h"
#include "mmi_rp_app_screen_lock_key_img_setting_def.h"

#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "GlobalDefs.h"
#include "lcd_sw_inc.h"
#include "MMI_common_app_trc.h"

#include "mmi_rp_app_mainmenu_def.h"

//menu cui
#include "menucuigprot.h"

//fmgr
#include "FileMgrCuiGProt.h"
#include "FileMgrType.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrGProt.h"
#include "FileMgrServiceResDef.h"

//category
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_fmgr.h"
#include "wgui_categories_util.h"

//popup
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "CommonScreensResDef.h"
#include "CommonScreens.h"

//gui, gdi
#include "gdi_datatype.h"
#include "gui_data_types.h"
#include "gdi_include.h"
#include "gdi_image.h"

//wgui
#include "wgui_include.h"
#include "wgui_categories_multimedia.h"

//string
#include "Unicodexdcl.h"

//nvram
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"

#ifdef __MMI_IMAGE_CLIP_CUI__
#include "ImageClipCuiGprot.h"
#endif
#include "GlobalResDef.h"

/***************************************************************************** 
* External Function
*****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

void vapp_screen_lock_key_get_img_size(S32 *dest_w, S32 *dest_h);

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
* Local Variable
*****************************************************************************/
mmi_screen_lock_key_img_setting_cntx g_screen_lock_key_cntx;

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* Extern Function
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

       void mmi_screen_lock_key_img_setting_entry(MMI_ID parent_gid);
       void mmi_screen_lock_key_img_setting_set_hint(void);
static void mmi_screen_lock_key_img_setting_entry_main(void);
static void mmi_screen_lock_key_img_setting_popup_id(MMI_STR_ID str_id, mmi_event_notify_enum event_type, U16 scrn_id);
static void mmi_screen_lock_key_img_setting_popup_str(WCHAR* string);
static void mmi_screen_lock_key_img_setting_sys_entry(void);
static void mmi_screen_lock_key_img_setting_usr_entry(void);

mmi_ret mmi_screen_lock_key_img_setting_group_proc(mmi_event_struct *evt);

void mmi_screen_lock_key_img_setting_sys_hiligt_hdlr(S32 idx);
void mmi_screen_lock_key_img_setting_sys_done_hdlr(void);
void mmi_screen_lock_key_img_setting_sys_draw_hdlr(S32 idx, S32 page_start_idx, S32 page_end_idx, BOOL is_hilighted,
        BOOL is_need_update, BOOL is_new_page, S32 x1, S32 y1, S32 x2, S32 y2);

static void mmi_screen_lock_key_img_setting_usr_res_hdlr(cui_file_selector_result_event_struct *file_select);
static MMI_BOOL mmi_screen_lock_key_img_setting_usr_check(void);
       void mmi_screen_lock_key_img_setting_usr_entry_store(void);
       void mmi_screen_lock_key_img_setting_usr_exitstore(void);
static void mmi_screen_lock_key_img_setting_usr_draw_loading(void);
static void mmi_screen_lock_key_img_setting_usr_stop_draw_loading(void);
static MMI_BOOL mmi_screen_lock_key_img_setting_usr_create_dir(void);
static void mmi_screen_lock_key_img_setting_usr_decode(void);
static void mmi_screen_lock_key_img_setting_usr_decode_cb(GDI_RESULT result, gdi_handle handle);
static void mmi_screen_lock_key_img_setting_usr_set_hint(void);
static void mmi_screen_lock_key_img_setting_usr_get_hint(WCHAR* hint);

static U16  mmi_screen_lock_key_img_setting_get_str_id(S32 res);

/* external apis */
mmi_screen_lock_key_img_setting_type_enum mmi_screen_lock_key_img_setting_get_type(void);
U16 mmi_screen_lock_key_img_setting_get_img_id(void);
WCHAR* mmi_screen_lock_key_img_setting_get_img_path(void);


//MMI_BOOL mmi_screen_lock_key_img_setting_event_hdlr(cui_event_struct *listevt);


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_screen_lock_key_img_setting_entry(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_screen_lock_key_cntx.gid = mmi_frm_group_create_ex(
                parent_gid,
                GRP_ID_AUTO_GEN,
                mmi_screen_lock_key_img_setting_group_proc,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (g_screen_lock_key_cntx.gid == GRP_ID_INVALID)
    {
        return;
    }
    
    mmi_screen_lock_key_img_setting_entry_main();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_set_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_screen_lock_key_img_setting_set_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_screen_lock_key_img_setting_type_enum type;
    WCHAR hint[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_screen_lock_key_cntx.sys_img_id = mmi_screen_lock_key_img_setting_get_img_id();
    type = mmi_screen_lock_key_img_setting_get_type();

    MMI_SLK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_IMGSET_TYPE, type));

    switch(type)
    {
        case MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_SYS:
            kal_wsprintf(hint, "%w%d", L"Lock ", g_screen_lock_key_cntx.sys_img_id - IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_START);
            break;

        case MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_USR:
            mmi_screen_lock_key_img_setting_usr_get_hint(hint);
            break;

        case MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_NOT_SET:
            kal_wsprintf(hint, "%w", L"Lock 1");
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    cui_menu_set_item_hint(
        mmi_frm_group_get_active_id(),
        MENU_ID_SCREEN_LOCK_KEY_IMG_SETTING,
        (WCHAR*)hint);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_entry_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_screen_lock_key_img_setting_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            }
            break;
    
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_SCREEN_LOCK_KEY_IMG_SETTING_SYS:
                        mmi_screen_lock_key_img_setting_sys_entry();
                        break;

                    case MENU_ID_SCREEN_LOCK_KEY_IMG_SETTING_USR:
                        mmi_screen_lock_key_img_setting_usr_entry();
                        break;
                }
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
                cui_menu_close(menu_evt->sender_id);
            }
            break;    
    
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
            mmi_screen_lock_key_img_setting_usr_res_hdlr((cui_file_selector_result_event_struct*) evt);
            break;

        case EVT_ID_POPUP_QUIT:
            {
                if (((mmi_event_popoupcallback_result_struct*)evt)->user_tag == NULL)
                {
                    //do nothing
                }
                else
                {
                    mmi_frm_scrn_close(g_screen_lock_key_cntx.gid, (MMI_ID)((mmi_event_popoupcallback_result_struct*)evt)->user_tag);
                }
            }
            break; 

    #ifdef __MMI_IMAGE_CLIP_CUI__
        case EVT_ID_CUI_IMAGE_CLIP_RESULT_SUCCESS:
            {
                S16 error;
                //cui_image_clip_evt_struct *c_evt = (cui_image_clip_evt_struct *)evt;
				g_screen_lock_key_cntx.img_typ = MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_USR;
            	WriteValue(NVRAM_SCREEN_LOCK_KEY_SETTING_IMG_TYPE, &g_screen_lock_key_cntx.img_typ, DS_SHORT, &error);
                mmi_screen_lock_key_img_setting_usr_set_hint();

                MMI_SLK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_IMGSET_USR_CLIP));
                
				cui_file_selector_close(g_screen_lock_key_cntx.usr_gid);
                mmi_frm_group_close(g_screen_lock_key_cntx.gid);
            break;
           }
        case EVT_ID_CUI_IMAGE_CLIP_CLOSE_REQUEST:
            {
                cui_image_clip_evt_struct *c_evt = (cui_image_clip_evt_struct *)evt;
				
                cui_image_clip_close(c_evt->sender_id);
                mmi_frm_group_close(g_screen_lock_key_cntx.gid);
            }
            break;
	#endif
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_entry_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_screen_lock_key_img_setting_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_screen_lock_key_cntx.sys_gid = cui_menu_create(
            g_screen_lock_key_cntx.gid,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_APPSUB,
            MENU_ID_SCREEN_LOCK_KEY_IMG_SETTING,
            MMI_TRUE,
            NULL);

    if (g_screen_lock_key_cntx.sys_gid == GRP_ID_INVALID)
    {
        mmi_frm_group_close(g_screen_lock_key_cntx.gid);
        return;
    }
        
    cui_menu_set_default_title_by_id(
            g_screen_lock_key_cntx.sys_gid,
            STR_ID_SCREEN_LOCK_KEY_IMG_SETTING,
            GetRootTitleIcon(MAIN_MENU_SETTINGS_MENUID));

    cui_menu_run(g_screen_lock_key_cntx.sys_gid);
                                    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_sys_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_screen_lock_key_img_setting_sys_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* gui_buffer;
    S32 highlight_item;
    U16 num_of_items;
    U8  num_per_row;
    U8  num_per_col;
    MMI_BOOL ret; 
	#if defined(__MMI_SLIM_FILE_MANAGER__)
	S32 *category_error_flag;
	#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = mmi_frm_scrn_enter(
            g_screen_lock_key_cntx.gid, 
            SCR_ID_SCREEN_LOCK_KEY_IMG_SETTING_SYS ,
            NULL,
            mmi_screen_lock_key_img_setting_sys_entry,
            MMI_FRM_UNKNOW_SCRN);
            
    if (!ret)
    {
        return;
    }        

    gui_buffer = mmi_frm_scrn_get_gui_buf(g_screen_lock_key_cntx.gid, SCR_ID_SCREEN_LOCK_KEY_IMG_SETTING_SYS);

    RegisterHighlightHandler(mmi_screen_lock_key_img_setting_sys_hiligt_hdlr);
    
    num_of_items = IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_END - IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_START - 1;
    num_per_row = MMI_SCREEN_LOCK_KEY_IMG_SETTING_NUM_PER_ROW;
    num_per_col = MMI_SCREEN_LOCK_KEY_IMG_SETTING_NUM_PER_COL;

    highlight_item = (g_screen_lock_key_cntx.sys_img_id == 0xFFFF) ? 0 : (g_screen_lock_key_cntx.sys_img_id - IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_START - 1);
    #if !defined(__MMI_SLIM_FILE_MANAGER__)
    ShowCategory214Screen(
        STR_ID_SCREEN_LOCK_KEY_IMG_SETTING,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        mmi_screen_lock_key_img_setting_sys_draw_hdlr,
        NULL,
        num_per_row,
        num_per_col,
        highlight_item,
        gui_buffer);
    #else
    ShowCategory219Screen(
        STR_ID_SCREEN_LOCK_KEY_IMG_SETTING,
        0,
        STR_GLOBAL_OK,
        STR_GLOBAL_BACK,
        num_of_items,
        mmi_screen_lock_key_img_setting_sys_draw_hdlr,
        NULL,
        num_per_row,
        num_per_col,
        highlight_item,
        gui_buffer,
        category_error_flag);
    #endif
    SetLeftSoftkeyFunction(mmi_screen_lock_key_img_setting_sys_done_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    SetKeyHandler(mmi_screen_lock_key_img_setting_sys_done_hdlr, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_screen_lock_key_img_setting_sys_done_hdlr, KEY_CSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_RSK, KEY_EVENT_UP);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_sys_hiligt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_screen_lock_key_img_setting_sys_hiligt_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_screen_lock_key_cntx.sys_hilight_idx = idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_sys_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_screen_lock_key_img_setting_sys_done_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_SLK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_IMGSET_SYS_DONE, g_screen_lock_key_cntx.sys_hilight_idx));
    
    g_screen_lock_key_cntx.img_typ = MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_SYS;
    g_screen_lock_key_cntx.sys_img_id = IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_START + g_screen_lock_key_cntx.sys_hilight_idx + 1;

    WriteValue(NVRAM_SCREEN_LOCK_KEY_SETTING_IMG_TYPE, &g_screen_lock_key_cntx.img_typ, DS_SHORT, &error);
    WriteValue(NVRAM_SCREEN_LOCK_KEY_SETTING_IMG_SYS, &g_screen_lock_key_cntx.sys_img_id, DS_SHORT, &error);

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    //mmi_frm_scrn_close(g_screen_lock_key_cntx.gid, SCR_ID_SCREEN_LOCK_KEY_IMG_SETTING_SYS);
    mmi_frm_group_close(g_screen_lock_key_cntx.gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_sys_draw_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_screen_lock_key_img_setting_sys_draw_hdlr(
    S32 idx,
    S32 page_start_idx,
    S32 page_end_idx,
    BOOL is_hilighted,
    BOOL is_need_update,
    BOOL is_new_page,
    S32 x1,
    S32 y1,
    S32 x2,
    S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlight_item;
    S32 image_width;
    S32 image_height;
    S32 resized_image_width;
    S32 resized_image_height;
    S32 offset_x;
    S32 offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    UI_UNUSED_PARAMETER(is_new_page);
    UI_UNUSED_PARAMETER(page_end_idx);
    UI_UNUSED_PARAMETER(page_start_idx);

    if (is_need_update)
    {
        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);

        image_id = IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_START + idx + 1;
        gdi_image_get_dimension_id(image_id, &image_width, &image_height);

        gdi_util_fit_box(
            GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
            x2 - x1 + 1, y2 - y1 + 1, image_width, image_height,
            &offset_x, &offset_y, &resized_image_width, &resized_image_height);

        gdi_image_draw_resized_id(
            x1 + offset_x, y1 + offset_y,
            resized_image_width, resized_image_height, image_id);

        highlight_item = (g_screen_lock_key_cntx.sys_img_id == 0xFFFF) ? 0 : (g_screen_lock_key_cntx.sys_img_id - IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_START - 1);
        
        if (idx == highlight_item)
        {
            gdi_image_get_dimension_id(IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_SELECT, &image_width, &image_height);
            gdi_image_draw_id(x2 - image_width - 2, y2 - image_height - 2, IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_SELECT);
        }

        gdi_layer_pop_clip();
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_usr_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_screen_lock_key_img_setting_usr_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_IMAGE(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    g_screen_lock_key_cntx.usr_gid = cui_file_selector_create(
                g_screen_lock_key_cntx.gid, 
                (WCHAR*) L"root", 
                &filter, 
                CUI_FILE_SELECTOR_STYLE_FILE_ONLY, 
                CUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON | CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);

    if (g_screen_lock_key_cntx.usr_gid > 0)
    {
        cui_file_selector_set_userdata(g_screen_lock_key_cntx.usr_gid, 0);        
        cui_file_selector_run(g_screen_lock_key_cntx.usr_gid);
    }
    else
    {   
        mmi_screen_lock_key_img_setting_popup_id(
            STR_GLOBAL_ERROR, 
            MMI_EVENT_FAILURE,
            NULL);
    }            
}

#ifdef __MMI_IMAGE_CLIP_CUI__
/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_usr_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_screen_lock_key_img_start_img_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_id;
	S32 img_width, img_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_id = cui_image_clip_create(g_screen_lock_key_cntx.gid,
                                   g_screen_lock_key_cntx.usr_src_path,
                                   NULL);

    if (cui_id == GRP_ID_INVALID)
        return;

	vapp_screen_lock_key_get_img_size(&img_width, &img_height);	
	cui_image_clip_set_dest_size(cui_id, img_width, img_height);
    cui_image_clip_set_dest_file_path(cui_id, mmi_screen_lock_key_img_setting_get_img_path());

    cui_image_clip_run(cui_id);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_usr_res_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_screen_lock_key_img_setting_usr_res_hdlr(cui_file_selector_result_event_struct *file_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_SLK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_IMGSET_USR_SELECT, file_select->result));

    if (file_select->result > 0)
    {
        cui_file_selector_get_selected_filepath(
            file_select->sender_id,
            NULL,
            g_screen_lock_key_cntx.usr_src_path,
            (SRV_FMGR_PATH_MAX_LEN) * ENCODING_LENGTH);

        if (mmi_screen_lock_key_img_setting_usr_check())
        {
            #ifdef __MMI_IMAGE_CLIP_CUI__
			    mmi_screen_lock_key_img_start_img_clip();
			#else
		        mmi_screen_lock_key_img_setting_usr_entry_store();
			#endif
        }        
    }
    else if (file_select->result == 0)
    {
        cui_file_selector_close(file_select->sender_id);
    }
    else
    {
        cui_file_selector_close(file_select->sender_id);
        /* if select error, still stay in file selector */
        mmi_screen_lock_key_img_setting_popup_id(
            STR_GLOBAL_ERROR, 
            MMI_EVENT_FAILURE,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_usr_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_screen_lock_key_img_setting_usr_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    mmi_str_id str_id;
    PS8 error_str_ptr;
    S32 event_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    handle = FS_Open((const WCHAR*)g_screen_lock_key_cntx.usr_src_path, FS_READ_ONLY);

    MMI_SLK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_IMGSET_USR_CHECK1, handle));
    
    if (handle < FS_NO_ERROR)
    {
        str_id = srv_fmgr_fs_error_get_string_and_popup_type(handle, &event_type);
        mmi_screen_lock_key_img_setting_popup_str((WCHAR*)GetString(str_id));
        return MMI_FALSE;
    }
    else
    {
        FS_Close(handle);
    }

    if (mmi_fmgr_util_file_limit_check(FMGR_LIMIT_WALLPAPER, (PS8)g_screen_lock_key_cntx.usr_src_path, &error_str_ptr) == FALSE)
    {
        MMI_SLK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_IMGSET_USR_CHECK2));
        
        mmi_screen_lock_key_img_setting_popup_str((WCHAR*)error_str_ptr);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_usr_entry_store
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_screen_lock_key_img_setting_usr_entry_store(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = mmi_frm_scrn_enter(
            g_screen_lock_key_cntx.gid, 
            SCR_ID_SCREEN_LOCK_KEY_IMG_SETTING_USR_STORE ,
            mmi_screen_lock_key_img_setting_usr_exitstore,
            mmi_screen_lock_key_img_setting_usr_entry_store,
            MMI_FRM_UNKNOW_SCRN);
            
    if (!ret)
    {
        return;
    }

    entry_full_screen();

    mmi_screen_lock_key_img_setting_usr_draw_loading();

    if (mmi_screen_lock_key_img_setting_usr_create_dir())
    {
        mmi_screen_lock_key_img_setting_usr_decode();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_usr_exitstore
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_screen_lock_key_img_setting_usr_exitstore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle  base_layer_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_get_base_handle(&base_layer_handle);
    
    gdi_layer_push_and_set_active(base_layer_handle);
    gdi_layer_reset_clip();
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_set_opacity(FALSE, 255);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    mmi_screen_lock_key_img_setting_usr_stop_draw_loading();

    if (g_screen_lock_key_cntx.is_decoding)
    {
        gdi_image_nb_stop(g_screen_lock_key_cntx.usr_decode_handle);
        g_screen_lock_key_cntx.is_decoding = MMI_FALSE;
        g_screen_lock_key_cntx.usr_decode_handle = GDI_LAYER_EMPTY_HANDLE;
    } 

    if (g_screen_lock_key_cntx.usr_img_handle)
    {
        gdi_layer_free(g_screen_lock_key_cntx.usr_img_handle);
        g_screen_lock_key_cntx.usr_img_handle = GDI_LAYER_EMPTY_HANDLE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_usr_draw_loading
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_screen_lock_key_img_setting_usr_draw_loading(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle base_layer_handle;
    S32 image_width = 0;
    S32 image_height = 0;
    S32 resized_image_offset_x = 0;
    S32 resized_image_offset_y = 0;
    S32 resized_image_width = 0;
    S32 resized_image_height = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_get_base_handle(&base_layer_handle);

    gdi_image_get_dimension_id(IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_LOADING, &image_width, &image_height);

    gdi_util_fit_box(
        GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
        LCD_WIDTH,
        LCD_HEIGHT,
        image_width,
        image_height,
        &resized_image_offset_x,
        &resized_image_offset_y,
        &resized_image_width,
        &resized_image_height);
    
    gdi_layer_push_and_set_active(base_layer_handle);
    gdi_layer_reset_clip();
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_set_opacity(FALSE, 255);
    gdi_layer_clear(GDI_COLOR_BLACK);
    
    gdi_anim_draw_id(resized_image_offset_x, resized_image_offset_y, IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_LOADING, &g_screen_lock_key_cntx.usr_anim_handle);            

    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(base_layer_handle, 0, 0, 0);
    gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_usr_stop_draw_loading
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_screen_lock_key_img_setting_usr_stop_draw_loading(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_screen_lock_key_cntx.usr_anim_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_image_stop_animation(g_screen_lock_key_cntx.usr_anim_handle);
        g_screen_lock_key_cntx.usr_anim_handle = GDI_LAYER_EMPTY_HANDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_usr_create_dir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_screen_lock_key_img_setting_usr_create_dir(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR buf_filepath[SRV_FMGR_PATH_MAX_LEN + 1];
    FS_HANDLE handle;
    S32 ret = FS_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wsprintf(buf_filepath, "%c:\\%w\\", MMI_SCREEN_LOCK_KEY_IMG_SETTING_DRV, MMI_SCREEN_LOCK_KEY_IMG_SETTING_FOLDER);
    handle = FS_Open(buf_filepath, FS_OPEN_DIR | FS_READ_ONLY);

    MMI_SLK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_IMGSET_USR_SAVE, handle));

    if (handle >= FS_NO_ERROR)
    {
        FS_Close(handle);
    }
    else
    {
        ret = FS_CreateDir(buf_filepath);
        if (ret < 0)
        {
            mmi_frm_scrn_close(g_screen_lock_key_cntx.gid, SCR_ID_SCREEN_LOCK_KEY_IMG_SETTING_USR_STORE);
            mmi_screen_lock_key_img_setting_popup_str((WCHAR*)GetString(srv_fmgr_fs_error_get_string(ret)));        
            return MMI_FALSE;
        }
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_usr_decode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_screen_lock_key_img_setting_usr_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width = 0;
    S32 image_height = 0;
    S32 card_width = 0;
    S32 card_height = 0;
    S32 layer_width = 0;
    S32 layer_height = 0;
    S32 offset_x = 0;
    S32 offset_y = 0;
    FLOAT img_scale;
    FLOAT card_scale;
    GDI_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_SLK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_IMGSET_USR_DECODE));

    //vapp_screen_lock_key_get_card_dimension(&card_width, &card_height);
    result = gdi_image_get_dimension_file((CHAR*)g_screen_lock_key_cntx.usr_src_path, &image_width, &image_height); 
    vapp_screen_lock_key_get_img_size(&card_width, &card_height);

    if (result < 0)
    {   
        mmi_frm_scrn_close(g_screen_lock_key_cntx.gid, SCR_ID_SCREEN_LOCK_KEY_IMG_SETTING_USR_STORE);

        mmi_screen_lock_key_img_setting_popup_id(
            mmi_screen_lock_key_img_setting_get_str_id(result), 
            MMI_EVENT_FAILURE,
            NULL);
            
        return;
    }
    else
    {
        if (image_width <= card_width && image_height <= card_height)
        {
            layer_width = image_width;
            layer_height = image_height;
        }
        else if (image_width <= card_width && image_height > card_height)
        {
            layer_width = image_width;
            layer_height = card_height;
            offset_y = (card_height - image_height) / 2;
        }
        else if (image_width > card_width && image_height <= card_height)
        {
            layer_width = card_width;
            layer_height = image_height;
            offset_x = (card_width - image_width) / 2;
        }
        else if (image_width > card_width && image_height > card_height)
        {
            layer_width = card_width;
            layer_height = card_height;

            img_scale = (FLOAT)image_width / (FLOAT)image_height;
            card_scale = (FLOAT)card_width / (FLOAT)card_height;

            if (img_scale <= card_scale)
            {
                image_width = card_width;
                image_height = image_width / img_scale;
                offset_y = (card_height - image_height) / 2;
            }
            else
            {
                image_height = card_height;
                image_width = image_height * img_scale;
                offset_x = (card_width - image_width) / 2;
            }
        }
    }

    gdi_layer_create(0, 0, layer_width, layer_height, &g_screen_lock_key_cntx.usr_img_handle);

    gdi_layer_push_and_set_active(g_screen_lock_key_cntx.usr_img_handle);
    gdi_layer_reset_clip();
    gdi_layer_clear(GDI_COLOR_BLACK);

    gdi_push_and_set_alpha_blending_source_layer(g_screen_lock_key_cntx.usr_img_handle);

    gdi_nb_set_done_callback(mmi_screen_lock_key_img_setting_usr_decode_cb);
    gdi_nb_set_blt(MMI_FALSE, MMI_FALSE);
    
    g_screen_lock_key_cntx.usr_decode_handle = gdi_image_nb_draw_resized_file(
            offset_x, 
            offset_y, 
            image_width, 
            image_height, 
            g_screen_lock_key_cntx.usr_src_path);

    g_screen_lock_key_cntx.is_decoding = MMI_TRUE;

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_and_restore_active();
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_usr_decode_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_screen_lock_key_img_setting_usr_decode_cb(GDI_RESULT result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_SLK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_IMGSET_USR_DECODE_CB, result));
    
    g_screen_lock_key_cntx.is_decoding = MMI_FALSE;
    g_screen_lock_key_cntx.usr_decode_handle = GDI_LAYER_EMPTY_HANDLE;
    
    if (result >= 0)
    {
        mmi_screen_lock_key_img_setting_get_img_path();
        
        result = gdi_image_encode_layer_to_jpeg(
            g_screen_lock_key_cntx.usr_img_handle, 
            (CHAR*)g_screen_lock_key_cntx.usr_dest_path);

        MMI_SLK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_IMGSET_USR_ENCODE, result));

        if (result >= 0)
        {
            g_screen_lock_key_cntx.img_typ = MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_USR;
            WriteValue(NVRAM_SCREEN_LOCK_KEY_SETTING_IMG_TYPE, &g_screen_lock_key_cntx.img_typ, DS_SHORT, &error);
            mmi_screen_lock_key_img_setting_usr_set_hint();
        }
    }

    if (result >= 0)
    {
        cui_file_selector_close(g_screen_lock_key_cntx.usr_gid);
        mmi_frm_group_close(g_screen_lock_key_cntx.gid);
    }
    else
    {
        mmi_frm_scrn_close(g_screen_lock_key_cntx.gid, SCR_ID_SCREEN_LOCK_KEY_IMG_SETTING_USR_STORE);
        mmi_screen_lock_key_img_setting_popup_id(
            mmi_screen_lock_key_img_setting_get_str_id(result), 
            MMI_EVENT_FAILURE,
            NULL);
    }
    
}   


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_usr_set_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_screen_lock_key_img_setting_usr_set_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR file_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    CHAR *p;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    p = mmi_ucs2rchr((CHAR*)g_screen_lock_key_cntx.usr_src_path, L'\\');
    p += 2;     //skip char "\"
    mmi_ucs2cpy((CHAR*)file_name, p);
    WriteRecord(
        NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_LID,
        1,
        file_name,
        NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_SIZE,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_usr_get_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_screen_lock_key_img_setting_usr_get_hint(WCHAR* hint)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR file_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ReadRecord(
        NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_LID,
        1,
        file_name,
        NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_SIZE,
        &error);
        
    mmi_ucs2cpy((CHAR*)hint, (CHAR*)file_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_get_str_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16  mmi_screen_lock_key_img_setting_get_str_id(S32 res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (res)
    {
        case GDI_JPEG_ERR_IMAGE_TOO_LARGE:
            return STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE;

        case GDI_JPEG_ERR_FILE_FORMAT_WRONG:
            return STR_GLOBAL_INVALID_FORMAT;

        case GDI_JPEG_ERR_DECODE_TIME_OUT:
            return STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE;

        case GDI_IMAGE_ERR_INVALID_IMG_TYPE:
            return STR_GLOBAL_INVALID_FORMAT;

        case GDI_IMAGE_ERR_UNSUPPORTED_FORMAT:
            return STR_GLOBAL_UNSUPPORTED_FORMAT;

        case GDI_IMAGE_ENCODER_ERR_MEMORY_NOT_ENOUGH:
        case GDI_IMAGE_ENCODER_ERR_DISK_FULL:
            return STR_GLOBAL_NOT_ENOUGH_MEMORY;

        case GDI_IMAGE_ENCODER_ERR_WRITE_PROTECTION:
            return FMGR_FS_WRITE_PROTECTION_TEXT;

        case GDI_IMAGE_ENCODER_ERR_ROOT_DIR_FULL:
            return FMGR_FS_ROOT_DIR_FULL_TEXT;

    #if !defined(__MMI_SLIM_FILE_MANAGER__)
        case GDI_IMAGE_ENCODER_ERR_NO_DISK:
            return FMGR_FS_MSDC_NOT_PRESENT_TEXT;
    #endif
        
        default:
            return STR_GLOBAL_ERROR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_popup_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_screen_lock_key_img_setting_popup_id(
    MMI_STR_ID str_id, 
    mmi_event_notify_enum event_type,
    U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_screen_lock_key_cntx.gid);

    mmi_popup_display_simple_ext(
        str_id,
        event_type,
        g_screen_lock_key_cntx.gid,
        (void*)scrn_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_popup_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_screen_lock_key_img_setting_popup_str(WCHAR* string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct property;  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&property);
    
    property.user_tag = NULL;
    property.parent_id = g_screen_lock_key_cntx.gid;
    
    mmi_popup_display(string, MMI_EVENT_FAILURE, &property);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_get_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_screen_lock_key_img_setting_type_enum mmi_screen_lock_key_img_setting_get_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 type;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ReadValue(NVRAM_SCREEN_LOCK_KEY_SETTING_IMG_TYPE, &type, DS_SHORT, &error);
    if (type == 0xFFFF)
    {
        return MMI_SCREEN_LOCK_KEY_IMG_SETTING_TYPE_NOT_SET;
    }
    else
    {
        return (mmi_screen_lock_key_img_setting_type_enum)type;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_get_img_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_screen_lock_key_img_setting_get_img_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ReadValue(NVRAM_SCREEN_LOCK_KEY_SETTING_IMG_SYS, &img_id, DS_SHORT, &error);

    return img_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_screen_lock_key_img_setting_get_img_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR* mmi_screen_lock_key_img_setting_get_img_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == g_screen_lock_key_cntx.usr_dest_path[0])
    {
        kal_wsprintf(
            g_screen_lock_key_cntx.usr_dest_path,
            "%c:\\%w\\%w",
            MMI_SCREEN_LOCK_KEY_IMG_SETTING_DRV,
            MMI_SCREEN_LOCK_KEY_IMG_SETTING_FOLDER,
            MMI_SCREEN_LOCK_KEY_IMG_SETTING_FILENAME);
    }
    return g_screen_lock_key_cntx.usr_dest_path;
}


#endif


