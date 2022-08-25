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
 *  MOTApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MOT App source file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/
#include "mmi_features.h"

#ifdef __MMI_MOT_SUPPORT__
#include "MOTGprot.h"
#include "MOTApp.h"
#include "MotSrvGprot.h"
#include "mmi_rp_app_mot_def.h"

#include "GlobalConstants.h"
#include "GlobalResDef.h"

#include "mmi_frm_app_launcher_gprot.h"
#include "gui_typedef.h"
#include "wgui_touch_screen.h"
#include "Wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_search.h"
#include "MenuCuiGprot.h"
#include "FileMgrCUIGProt.h"
#include "MediaAppGProt.h"

#include "AlertScreen.h"
#include "UcmSrvGprot.h"
#if defined(__USB_IN_NORMAL_MODE__)
#include "USBsrvGprot.h"
#include "USBDeviceGprot.h"
#endif
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__)
#include "UCMGProt.h"
#endif


/*****************************************************************************
*Flags
*****************************************************************************/
#define MMI_MOT_HAS_MOT_SRV_CREATED    0x00000001
#define MMI_MOT_HAS_MOT_SRV_OPENED      0x00000002
#define MMI_MOT_HAS_MOT_SRV_UPDATING      0x00000004
#define MMI_MOT_HAS_MOT_SRV_UPDATED      0x00000008

#define MMI_MOT_SET_FLAG(x)        (g_mot->flags |= (x))
#define MMI_MOT_CLEAR_FLAG(x)      (g_mot->flags &= (~(x)))
#define MMI_MOT_CHECK_FLAG(x)      ((g_mot->flags & x) ? MMI_TRUE : MMI_FALSE)

/*******************************************************************************
*App context point
*******************************************************************************/
static mmi_mot_context* g_mot = NULL;


/*******************************************************************************
*Static function declearation
*******************************************************************************/
static void         mmi_mot_display_popup(MMI_ID parent_id, MMI_STR_ID str_id, mmi_event_notify_enum type);
static void         mmi_mot_convert_time(U64 time, U32 *hour, U32 *minite, U32 *second);
static void         mmi_mot_prepare_description(srv_mot_content_info_struct *content_info);
static void         mmi_mot_add_header_for_image_buffer(PU8 dst_buffer, PU8 src_buffer, U32 img_size);


static MMI_RET      mmi_mot_screen_proc(mmi_event_struct* evt);

static MMI_RET      mmi_mot_menu_cui_proc(mmi_event_struct *evt);
static MMI_RET      mmi_mot_storage_selector_cui_proc(mmi_event_struct *evt);
static MMI_RET      mmi_mot_interrupt_proc(mmi_event_struct* evt);


static void         mmi_mot_app_entry(void);
static void         mmi_mot_app_exit(void);
static void         mmi_mot_app_prepare(void);
static void         mmi_mot_app_unprepare(void);

static MMI_BOOL     mmi_mot_app_pre_check(void);

static void         mmi_mot_entry_storage_select(void);

static void         mmi_mot_srv_prepare(void);


static void         mmi_mot_srv_update_begin(void);
static void         mmi_mot_srv_update_end(void);

static void         mmi_mot_entry_category_list_option(void);


static void         mmi_mot_category_open(void);
static void         mmi_mot_category_refresh(void);

static void         mmi_mot_entry_video_list_option(void);
static void         mmi_mot_video_play_video(void);
static void         mmi_mot_video_details(void);

static void         mmi_mot_create_waiting_screen(void);
static void         mmi_mot_create_category_list_screen(void);
static void         mmi_mot_create_video_list_screen(void);
static void         mmi_mot_create_details_screen(void);

static void         mmi_mot_entry_waiting_screen(void* gui_buffer);
static void         mmi_mot_entry_category_list_screen(void* gui_buffer);
static void         mmi_mot_entry_video_list_screen(void* gui_buffer);
static void         mmi_mot_entry_details_screen(void* gui_buffer);

static void         mmi_mot_show_waiting_screen(void* gui_buffer);
static void         mmi_mot_show_category_list_screen(void* gui_buffer);
static void         mmi_mot_show_video_list_screen(void* gui_buffer);
static void         mmi_mot_show_details_screen(void* gui_buffer);

static void         mmi_mot_category_list_highlight_hdlr(S32 index);
static void         mmi_mot_video_list_highlight_hdlr(S32 index);

static pBOOL        mmi_mot_get_category_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static S32          mmi_mot_get_video_list_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);

static MMI_BOOL     mmi_mot_get_thumbnail(S32 item_idx, wgui_thumbnail_img_info_struct* img_info);
static void         mmi_mot_get_image_info(S32 item_idx, wgui_thumbnail_info_struct *info_data);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void         mmi_mot_categoey_list_tap_callback(mmi_tap_type_enum tap_type,S32 index);
static void         mmi_mot_video_list_tap_callback(mmi_tap_type_enum tap_type,S32 index);
#endif

static srv_mot_cat_enum     mmi_mot_mapping_category(S32 index);

static S32                  mmi_mot_srv_callback(void* user_data, srv_mot_cb_evt_enum cb_event, srv_mot_ret_enum result, U32 param);
static MMI_BOOL             mmi_mot_create_srv_handle(void);
static MMI_BOOL             mmi_mot_open_srv_handle(void);
static MMI_BOOL             mmi_mot_update_srv(void);
static void                 mmi_mot_stop_update_srv(void);
static void                 mmi_mot_close_srv_handle(void);
static void                 mmi_mot_destroy_srv_handle(void);



static U32          mmi_mot_get_category_num(void);
static U32          mmi_mot_get_content_num(U32 index);
static MMI_BOOL     mmi_mot_need_show_content_num(U32 index);
static MMI_BOOL     mmi_mot_prepare_active_file(void);
static MMI_ID       mmi_mot_get_category_string_id(U32 index);
static MMI_ID       mmi_mot_get_category_string_id_by_cat_enum(srv_mot_cat_enum cat_enum);

static void         mmi_mot_get_content_info(U32 index, srv_mot_content_info_struct* content_info);
static void         mmi_mot_get_list_info_start(U32 start_index, srv_mot_list_info_struct* list_info);
static void         mmi_mot_get_list_info_next(srv_mot_list_info_struct* list_info);
static MMI_ID_TYPE  mmi_mot_get_error_string_id(void);
static void         mmi_mot_smart_correct_content_info(srv_mot_content_info_struct* content_info, MMI_BOOL correct_all);
static U32          mmi_mot_srv_get_content_id(U32 item_index);


static void         mmi_mot_cache_build_start(U32 start_index, U32 content_id);
static void         mmi_mot_cache_update_next(U32 content_id);
static U32          mmi_mot_cache_get_content_id(U32 item_index);




#define __EXTERN_INTERFACE
/*****************************************************************************
 * FUNCTION
 *  mmi_mot_highlight_app
 * DESCRIPTION
 *  app hilight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mot_highlight_app(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    SetLeftSoftkeyFunction(mmi_mot_launch, KEY_EVENT_UP);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_launch
 * DESCRIPTION
 *  app launch function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mot_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MOT_LAUNCH, __LINE__);
    mmi_frm_app_launch(APP_MOT, 0, 0, mmi_mot_app_proc, NULL, 0); 
}

#define __UTILITY
/*****************************************************************************
 * FUNCTION
 *  mmi_mot_display_popup
 * DESCRIPTION
 *  Popup function using by mot app
 * PARAMETERS
 *  parent_id [IN] popup parent id
 * str_id       [IN] popup string id 
 * type         [IN] popup type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_display_popup(MMI_ID parent_id, MMI_STR_ID str_id, mmi_event_notify_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple_ext(str_id, type, parent_id, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_convert_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_convert_time(U64 time, U32 *hour, U32 *minite, U32 *second)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time = (time + 500)/1000;
    *hour = time/3600;
    *minite = (time%3600)/60;
    *second = time%60;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_prepare_description
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_prepare_description(srv_mot_content_info_struct *content_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 hour, minite, second;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mot_convert_time(content_info->duration, &hour, &minite, &second);
    kal_wsprintf(g_mot->description, "%w: %w\n%w: %02d:%02d:%02d\n%w: %w\n%w: %w\n%w: %w\n%w: %w\n",
            GetString(STR_ID_MOT_MOVIE_NAME), content_info->title, 
            GetString(STR_ID_MOT_DURATION), hour, minite, second, 
            GetString(STR_ID_MOT_STARRING), content_info->artist, 
            GetString(STR_ID_MOT_YEAR), content_info->datetime, 
            GetString(STR_ID_MOT_CATEGORY), GetString(mmi_mot_get_category_string_id_by_cat_enum(content_info->category)),
            GetString(STR_ID_MOT_PLOT), content_info->descript);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_add_header_for_image_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_add_header_for_image_buffer(PU8 dst_buffer, PU8 src_buffer, U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width,height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(img_size == 0)
    {
        return;
    }
    
    dst_buffer[0] = (U8)gdi_image_get_type_from_mem((PS8)src_buffer);

    gdi_image_get_dimension_mem(dst_buffer[0], src_buffer, img_size, &width, &height);

    dst_buffer[1] = 1;
    dst_buffer[2] = img_size & 0xff;
    dst_buffer[3] = (img_size >> 8) & 0xff;
    dst_buffer[4] = (img_size >> 16) & 0xff;
    dst_buffer[5] = height & 0xff;
    dst_buffer[6] = ((height & 0xf00) >> 8) + ((width & 0xf) << 4);
    dst_buffer[7] = (width >> 4) & 0xff;

    kal_mem_cpy(dst_buffer + 8, src_buffer, img_size);
}

#define __PROCFUNC
/*****************************************************************************
 * FUNCTION
 *  mmi_mot_app_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_mot_app_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
	    case EVT_ID_APP_ENTER:
            mmi_mot_app_entry();
            return MMI_RET_OK;

        case EVT_ID_APP_DEINIT:
            mmi_mot_app_exit();
            return MMI_RET_OK;

        case EVT_ID_SCRN_ACTIVE:
        case EVT_ID_SCRN_INACTIVE:
            return mmi_mot_screen_proc(evt);

        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            return mmi_mot_menu_cui_proc(evt);

        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
            return mmi_mot_storage_selector_cui_proc(evt);
        
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            return mmi_mot_interrupt_proc(evt);
        
        default:
		    return MMI_RET_OK;
	}
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_screen_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_mot_screen_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_SCRN_ACTIVE)
    {
        mmi_frm_scrn_active_evt_struct* scrn_evt = (mmi_frm_scrn_active_evt_struct*)evt;
        switch(scrn_evt->scrn_id)
        {
            case SCR_ID_MOT_WAITING_SCREEN:
                mmi_mot_entry_waiting_screen(scrn_evt->gui_buffer);
                break;
                
            case SCR_ID_MOT_VIDEO_CAT_LIST:
                mmi_mot_entry_category_list_screen(scrn_evt->gui_buffer);
                break;
                
            case SCR_ID_MOT_VIDEO_LIST:
                mmi_mot_entry_video_list_screen(scrn_evt->gui_buffer);
                break;
                
            case SCR_ID_MOT_VIDEO_DETAILS:
                mmi_mot_entry_details_screen(scrn_evt->gui_buffer);
                break;
                
            default:
                break;
        }
    }
    else if(evt->evt_id == EVT_ID_SCRN_INACTIVE)
    {
        mmi_frm_scrn_inactive_evt_struct* scrn_evt = (mmi_frm_scrn_inactive_evt_struct*)evt;
        switch(scrn_evt->scrn_id)
        {
            case SCR_ID_MOT_WAITING_SCREEN:
                mmi_mot_srv_update_end();
                break;
                
            default:
                break;
        }
    
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_menu_cui_proc
 * DESCRIPTION
 *  Dynamic list call back to get item title.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_RET mmi_mot_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {  
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_MOT_CATEGORY_LIST_OPEN:
                    mmi_mot_category_open();
                    break;
                    
                case MENU_ID_MOT_CATEGORY_LIST_REFRESH:
                    mmi_mot_category_refresh();
                    break;

                case MENU_ID_MOT_VIDEO_LIST_PLAY_VIDEO:
                    mmi_mot_video_play_video();
                    break;
                    
                case MENU_ID_MOT_VIDEO_LIST_DETAILS:
                    mmi_mot_video_details();
                    break;
                    
                default:
                    break;
            }
        }
        
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        
        default:
            break;
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 * mmi_mot_storage_selector_cui_proc
 * DESCRIPTION
 *  app hilight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_mot_storage_selector_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
	{
        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct *sel_evt = 
                        (cui_file_selector_result_event_struct*)evt;

            MMI_MOT_MSG_TRACE(sel_evt->result);
	    if (sel_evt->result > 0)
	    {
		g_mot->drive = (((cui_storage_selector_result_event_struct*)evt)->result);
                mmi_mot_srv_prepare();
	    }
            else if(sel_evt->result == 0)
            {
                mmi_frm_app_close(APP_MOT);
            }
	    else
	    {
		        //MMI_ID str_id = srv_fmgr_fs_error_get_string(sel_evt->result);
	            //mmi_mot_display_popup(GRP_ID_ROOT, str_id, MMI_EVENT_FAILURE);
				mmi_frm_app_close(APP_MOT);
	    }
            break;
        }      
        
        default:
            break;
	}
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_interrupt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_mot_interrupt_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MOT_MSG_TRACE(evt->evt_id);
    if(g_mot == NULL)
    {
        MMI_MOT_MSG_TRACE(g_mot);
	return MMI_RET_OK;
    }

    switch(evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            MMI_MOT_MSG_TRACE(g_mot->drive);
            if(g_mot->drive == SRV_FMGR_CARD_DRV)
            {
                mmi_frm_group_close(GRP_ID_MOT_VIDEO_CATEGORY);
            }            
            break;
        default:
            break;
    }
    
    return MMI_RET_OK;
}


#define __SCRFLOW
/*****************************************************************************
 * FUNCTION
 *  mmi_mot_app_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_app_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    MMI_ID gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_mot_app_pre_check();
    MMI_MOT_MSG_TRACE(ret);
    if(ret == MMI_FALSE)
    {
        mmi_frm_app_close(APP_MOT);
        return;
    }
    
    mmi_mot_app_prepare();

    gid = mmi_frm_group_create_ex(APP_MOT, GRP_ID_MOT, 
                mmi_mot_app_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    MMI_MOT_MSG_TRACE(gid);
    if(GRP_ID_INVALID == gid)
    {
        mmi_mot_display_popup(GRP_ID_ROOT, STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
        mmi_frm_app_close(APP_MOT);
        return;
    }
    
    ret = mmi_mot_create_srv_handle();
    MMI_MOT_MSG_TRACE(ret);
    if(ret == MMI_FALSE)
    {
        mmi_mot_display_popup(GRP_ID_ROOT, mmi_mot_get_error_string_id(), MMI_EVENT_FAILURE);
        mmi_frm_app_close(APP_MOT);
        return;
    }
    
    mmi_mot_entry_storage_select();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_app_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_app_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MOT_MSG_TRACE(g_mot);
    if(g_mot == NULL)
    {
        return;
    }
    
    mmi_mot_close_srv_handle();
    mmi_mot_destroy_srv_handle();
    mmi_mot_app_unprepare();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_app_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_app_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mot == NULL)
    {
	    g_mot = (mmi_mot_context*)mmi_frm_asm_alloc_r(APP_MOT, MMI_MOT_APP_CONTEXT_BUF_SIZE);
    }

    MMI_ASSERT(g_mot != NULL);
    kal_mem_set(g_mot, 0, MMI_MOT_APP_CONTEXT_BUF_SIZE);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_app_unprepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_app_unprepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mot != NULL)
    {
        mmi_frm_asm_free_r(APP_MOT, g_mot);
        g_mot = NULL;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_app_pre_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mot_app_pre_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        mmi_frm_app_close(APP_MOT);
        return MMI_FALSE;
    }
    #endif
    
    #if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        mmi_frm_app_close(APP_MOT);
        return MMI_FALSE;
    }
    #endif /* defined(__USB_IN_NORMAL_MODE__) */
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_entry_storage_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_entry_storage_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cid = cui_storage_selector_create(GRP_ID_MOT, g_mot->drive, CUI_STORAGE_SELECTOR_DRV_TYPE_ACCESIBLE_ONLY);
    if(GRP_ID_INVALID == cid)
    {
        mmi_mot_display_popup(GRP_ID_ROOT, STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE);
        mmi_frm_app_close(APP_MOT);
		return;
    }

    cui_storage_selector_set_title(cid, STR_ID_MOT_APP_NAME, GetRootTitleIcon(MENU_ID_MOT_APP));
    cui_storage_selector_run(cid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_srv_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_srv_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    MMI_ID gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ret = mmi_mot_open_srv_handle();
    MMI_MOT_MSG_TRACE(ret);
    if(MMI_TRUE != ret)
    {
        mmi_mot_display_popup(GRP_ID_MOT, mmi_mot_get_error_string_id(), MMI_EVENT_FAILURE);
        return;
    }

    gid = mmi_frm_group_create_ex(GRP_ID_MOT,GRP_ID_MOT_VIDEO_CATEGORY,mmi_mot_app_proc,
                            NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if(GRP_ID_INVALID == gid)
    {
        mmi_mot_display_popup(GRP_ID_MOT, STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
        return;
    }
    
    MMI_MOT_MSG_TRACE(g_mot->flags);
    if(MMI_MOT_CHECK_FLAG(MMI_MOT_HAS_MOT_SRV_UPDATED))
    {
        mmi_mot_create_category_list_screen();
        return;
    }

    mmi_mot_srv_update_begin();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_srv_update_begin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_srv_update_begin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_mot_update_srv();
    MMI_MOT_MSG_TRACE(ret);
    if(MMI_TRUE != ret)
    {
        mmi_mot_display_popup(GRP_ID_MOT, mmi_mot_get_error_string_id(), MMI_EVENT_FAILURE);
        return;
    }

    mmi_mot_create_waiting_screen();
}


/*****************************************************************************
 * FUNCTION
 * mmi_mot_srv_update_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_srv_update_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_mot == NULL)
    {
        MMI_MOT_MSG_TRACE(g_mot);
        return;
    }
    MMI_MOT_MSG_TRACE(g_mot->flags);
    mmi_frm_scrn_close(GRP_ID_MOT_VIDEO_CATEGORY, SCR_ID_MOT_WAITING_SCREEN);
    mmi_mot_stop_update_srv();
    
    if(MMI_MOT_CHECK_FLAG(MMI_MOT_HAS_MOT_SRV_UPDATED))
    {
        mmi_mot_create_category_list_screen();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_entry_category_list_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_mot_entry_category_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cid = cui_menu_create(
                 GRP_ID_MOT_VIDEO_CATEGORY,
                 CUI_MENU_SRC_TYPE_RESOURCE,
                 CUI_MENU_TYPE_OPTION,
                 MENU_ID_MOT_CATEGORY_LIST_OPTIONS,
                 MMI_FALSE, 
                 NULL);
    if(GRP_ID_INVALID == cid)
    {
        mmi_mot_display_popup(GRP_ID_MOT, STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
        return;
    }

   cui_menu_run(cid);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mot_category_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_category_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mot_create_video_list_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_category_refresh
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_category_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MOT_CLEAR_FLAG(MMI_MOT_HAS_MOT_SRV_UPDATED);
    mmi_mot_srv_update_begin();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_entry_video_list_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_mot_entry_video_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cid = cui_menu_create(
                 GRP_ID_MOT_VIDEO_CATEGORY,
                 CUI_MENU_SRC_TYPE_RESOURCE,
                 CUI_MENU_TYPE_OPTION,
                 MENU_ID_MOT_VIDEO_LIST_OPTIONS,
                 MMI_FALSE, 
                 NULL);
    if(GRP_ID_INVALID == cid)
    {
        mmi_mot_display_popup(GRP_ID_MOT, STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
        return;
    }

   cui_menu_run(cid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_video_play_video
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_mot_video_play_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_mot_prepare_active_file();
    MMI_MOT_MSG_TRACE(ret);
    if(ret == MMI_FALSE)
    {
        mmi_mot_display_popup(GRP_ID_MOT, mmi_mot_get_error_string_id(), MMI_EVENT_FAILURE);
        return;
    }
    
    mmi_media_app_play_video(g_mot->active_filepath.filepath, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_video_details
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_mot_video_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gid = mmi_frm_group_create_ex(GRP_ID_MOT_VIDEO_CATEGORY,GRP_ID_MOT_VIDEO_DETAILS,mmi_mot_app_proc,
                            NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if(GRP_ID_INVALID == gid)
    {
        mmi_mot_display_popup(GRP_ID_MOT, STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
        return;
    }
    
    mmi_mot_create_details_screen();
}

#define __SCREEN
/*****************************************************************************
 * FUNCTION
 *  mmi_mot_create_waiting_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_create_waiting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_create(GRP_ID_MOT_VIDEO_CATEGORY, SCR_ID_MOT_WAITING_SCREEN, mmi_mot_app_proc, NULL);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_create_category_list_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_create_category_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mot->total_category = mmi_mot_get_category_num();
    
    mmi_frm_scrn_create(GRP_ID_MOT_VIDEO_CATEGORY, SCR_ID_MOT_VIDEO_CAT_LIST, mmi_mot_app_proc, NULL);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_create_video_list_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_create_video_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mot->list_info.total = mmi_mot_get_content_num(g_mot->active_category_index);
    
    mmi_frm_scrn_create(GRP_ID_MOT_VIDEO_CATEGORY, SCR_ID_MOT_VIDEO_LIST, mmi_mot_app_proc, g_mot);    
}

/*****************************************************************************
 * FUNCTION
 * mmi_mot_create_details_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_create_details_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_create(GRP_ID_MOT_VIDEO_DETAILS, SCR_ID_MOT_VIDEO_DETAILS, mmi_mot_app_proc, NULL);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_entry_waiting_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_entry_waiting_screen(void* gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_mot_show_waiting_screen(gui_buffer);
    SetRightSoftkeyFunction(mmi_mot_srv_update_end, KEY_EVENT_UP);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mot_entry_category_list_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_entry_category_list_screen(void* gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_buffer == NULL)
    {
        g_mot->active_category_index = 0;
    }

    RegisterHighlightHandler(mmi_mot_category_list_highlight_hdlr);

    mmi_mot_show_category_list_screen(gui_buffer);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_mot_categoey_list_tap_callback);
#endif
    
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
	    SetCenterSoftkeyFunction(mmi_mot_category_open, KEY_EVENT_UP);
        SetKeyHandler(mmi_mot_category_open, KEY_ENTER, KEY_EVENT_UP);      
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    SetLeftSoftkeyFunction(mmi_mot_entry_category_list_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 * mmi_mot_entry_video_list_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_mot_entry_video_list_screen(void* gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_buffer == NULL)
    {
        g_mot->list_info.highlight = 0;
    }

    RegisterHighlightHandler(mmi_mot_video_list_highlight_hdlr);

    mmi_mot_show_video_list_screen(gui_buffer);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_mot_video_list_tap_callback);
#endif
    
    if (g_mot->list_info.total > 0 && mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
	    SetCenterSoftkeyFunction(mmi_mot_video_play_video, KEY_EVENT_UP);
        SetKeyHandler(mmi_mot_video_play_video, KEY_ENTER, KEY_EVENT_UP);      
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    SetLeftSoftkeyFunction(mmi_mot_entry_video_list_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}



/*****************************************************************************
 * FUNCTION
 * mmi_mot_entry_details_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_mot_entry_details_screen(void* gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mot_show_details_screen(gui_buffer);
    
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
	    SetCenterSoftkeyFunction(mmi_mot_video_play_video, KEY_EVENT_UP);
        SetKeyHandler(mmi_mot_video_play_video, KEY_ENTER, KEY_EVENT_UP);      
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    
    SetLeftSoftkeyFunction(mmi_mot_video_play_video, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_show_waiting_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_show_waiting_screen(void* gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory66Screen(
        STR_ID_MOT_APP_NAME,
        GetRootTitleIcon(MENU_ID_MOT_APP),
        0,
        0,
        STR_GLOBAL_STOP,
        0,
        (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        (U8*)gui_buffer); 
}


/*****************************************************************************
 * FUNCTION
 * mmi_mot_show_category_list_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_show_category_list_screen(void* gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_mot -> total_category == 0)
    {
        ShowCategory353Screen(
            (U8*)get_string(STR_ID_MOT_APP_NAME),
            GetRootTitleIcon(MENU_ID_MOT_APP),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            (U8*)gui_buffer);
    }
    else
    {
        ShowCategory183Screen(
            get_string(STR_ID_MOT_APP_NAME), 
            get_image(GetRootTitleIcon(MENU_ID_MOT_APP)),    
            get_string(STR_GLOBAL_OPTIONS),
            get_image(IMG_GLOBAL_OPTIONS),              
            get_string(STR_GLOBAL_BACK),
            get_image(IMG_GLOBAL_BACK), 
            g_mot -> total_category,
            mmi_mot_get_category_list_item,
            NULL,
            g_mot -> active_category_index,
            MMI_FALSE,
            NULL,
            (U8*)gui_buffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_show_video_list_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_show_video_list_screen(void* gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID cat_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat_str_id = mmi_mot_get_category_string_id(g_mot->active_category_index);
    if(g_mot->list_info.total == 0)
    {
        ShowCategory353Screen(
            (U8*)get_string(cat_str_id),
            GetRootTitleIcon(MENU_ID_MOT_APP),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            (U8*)gui_buffer);
    }
    else
    {
        wgui_thumbnail_register_get_image_info_func(mmi_mot_get_image_info);
        wgui_thumbnail_register_get_image_func(mmi_mot_get_thumbnail);
        wgui_cat1072_show(
            (U8*)get_string(cat_str_id), 
            get_image(GetRootTitleIcon(MENU_ID_MOT_APP)),
            STR_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            g_mot->list_info.total,
            mmi_mot_get_video_list_item,
            g_mot->list_info.highlight,
            IMG_ID_MOT_DEFAULT_THUMBNAIL,
            0,
            (U8*)gui_buffer);
    }
}

/*****************************************************************************
 * FUNCTION
 * mmi_mot_show_details_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_mot_show_details_screen(void* gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mot_content_info_struct* content_info = &g_mot->content_info_temp_buf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mot_get_content_info(g_mot->list_info.highlight, content_info);
    mmi_mot_prepare_description(content_info);
    mmi_mot_add_header_for_image_buffer(g_mot->thumbnail_image_data, 
            content_info->thumbnail_buf, content_info->thumbnail_size);

    wgui_cat3006_show(
        get_string(STR_GLOBAL_DETAILS),
        get_image(GetRootTitleIcon(MENU_ID_MOT_APP)),   
        get_string(STR_GLOBAL_PLAY),
        get_image(IMG_GLOBAL_OK),              
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK), 
        (UI_buffer_type)g_mot->description,
        (UI_buffer_type)gui_buffer,
        content_info->filename,
        0,
        ((content_info->thumbnail_size > 0) ? 
                g_mot->thumbnail_image_data : get_image(IMG_ID_MOT_DEFAULT_THUMBNAIL)),
        0,
        NULL,
        NULL,
        0,
        NULL,
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_category_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_category_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mot->active_category_index = index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_video_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_video_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mot->list_info.highlight = index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_get_category_list_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static pBOOL mmi_mot_get_category_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE cat_str_id;
    U32 cat_num;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    cat_str_id = mmi_mot_get_category_string_id(item_index);    
    
    if(mmi_mot_need_show_content_num(item_index))
    {
        cat_num = mmi_mot_get_content_num(item_index);    
        kal_wsprintf(str_buff, "%w(%d)", (CHAR*) get_string(cat_str_id), cat_num);
    }
    else
    {
        kal_wsprintf(str_buff, "%w", (CHAR*) get_string(cat_str_id));
    }
    
    *img_buff_p = get_image(IMG_GLOBAL_L1 + item_index);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_get_video_list_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_mot_get_video_list_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mot_list_info_struct list_info;
    U32 hour, minite, second; 
    S32 count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MOT_MSG_TRACE(start_index);
    MMI_MOT_MSG_TRACE(data_size);
    
    mmi_mot_get_list_info_start(start_index, &list_info);
    mmi_mot_convert_time(list_info.duration,&hour,&minite,&second);   
    
    mmi_ucs2ncpy((CHAR*)menu_data[count].item_list[0],(CHAR*)list_info.filename,MAX_SUBMENU_CHARACTERS);
    kal_wsprintf(menu_data[count].item_list[1],"%w  %02d:%02d:%02d", 
                        (WCHAR*) get_string(STR_ID_MOT_DURATION), hour, minite, second);
    menu_data[count].image_list[0] = get_image(IMG_ID_MOT_DEFAULT_THUMBNAIL);
    
    while(++count < data_size)
    {
        mmi_mot_get_list_info_next(&list_info);
        mmi_mot_convert_time(list_info.duration,&hour,&minite,&second);   
    
        kal_wsprintf(menu_data[count].item_list[0],"%w", list_info.filename);
        kal_wsprintf(menu_data[count].item_list[1],"%w  %02d:%02d:%02d", 
                        (WCHAR*) get_string(STR_ID_MOT_DURATION), hour, minite, second);
	menu_data[count].image_list[0] = get_image(IMG_ID_MOT_DEFAULT_THUMBNAIL);

    }
	return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_get_thumbnail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL mmi_mot_get_thumbnail(S32 item_idx, wgui_thumbnail_img_info_struct* img_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mot_content_info_struct* content_info = &g_mot->content_info_temp_buf;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MOT_MSG_TRACE(item_idx);
    MMI_MOT_MSG_TRACE(g_mot->flags);
    
    mmi_mot_get_content_info(item_idx, content_info);
    img_info->img_ptr = content_info->thumbnail_buf;
    img_info->img_type = (U8)gdi_image_get_type_from_mem((PS8)content_info->thumbnail_buf);
    img_info->img_size = content_info->thumbnail_size;
    img_info->img_src = WGUI_THUMBNAIL_IMG_SRC_TYPE_MEMORY;
    MMI_MOT_MSG_TRACE(img_info->img_type);
    MMI_MOT_MSG_TRACE(img_info->img_size);
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_get_image_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_get_image_info(S32 item_idx, wgui_thumbnail_info_struct *info_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info_data->is_show_thumb = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_categoey_list_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_mot_categoey_list_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return;
    }

    mmi_mot_category_open();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_video_list_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_video_list_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return;
    }

    mmi_mot_video_play_video();
}

#endif


#define __MMI_MOT_SRV_ADAPTER

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_mapping_category
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_mot_cat_enum mmi_mot_mapping_category(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(index)
    {
        case 0:
            return SRV_MOT_CAT_RECENT_PLAY;
        case 1:
            return SRV_MOT_CAT_ALL;
        default:
            return (srv_mot_cat_enum)(index - 2);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mot_srv_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_mot_srv_callback(void* user_data, srv_mot_cb_evt_enum cb_event, srv_mot_ret_enum result, U32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MOT_MSG_TRACE(cb_event);
    MMI_MOT_MSG_TRACE(result);
    if(cb_event == SRV_MOT_CB_EVT_UPDATED)
    {
        if(result == SRV_MOT_S_FINISH)
        {
            MMI_MOT_CLEAR_FLAG(MMI_MOT_HAS_MOT_SRV_UPDATING);
            MMI_MOT_SET_FLAG(MMI_MOT_HAS_MOT_SRV_UPDATED);
            mmi_mot_srv_update_end();
        }
        else
        {
            g_mot->srv_last_ret = result;
            str_id = mmi_mot_get_error_string_id();
            mmi_mot_srv_update_end();
            mmi_mot_display_popup(GRP_ID_MOT, str_id, MMI_EVENT_FAILURE);
        }        
    }
    return SRV_MOT_S_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_create_srv_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mot_create_srv_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mot_create_struct create_s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_s.app_id = APP_MOT;
    create_s.callback = mmi_mot_srv_callback;
    create_s.user_data = (void*)g_mot;
    
    g_mot->srv_handle = srv_mot_create(&create_s);
    MMI_MOT_MSG_TRACE(g_mot->srv_handle);
    return (g_mot->srv_handle) ? 
                 (MMI_MOT_SET_FLAG(MMI_MOT_HAS_MOT_SRV_CREATED), MMI_TRUE) : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_open_srv_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mot_open_srv_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mot_open_struct open_s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_mot_close_srv_handle();

    open_s.drive_letter = (U8)g_mot->drive;
    g_mot->srv_last_ret = srv_mot_open(g_mot->srv_handle, &open_s);
    MMI_MOT_MSG_TRACE(g_mot->srv_last_ret);

    switch(g_mot->srv_last_ret)
    {
        case SRV_MOT_S_OK:
            MMI_MOT_SET_FLAG(MMI_MOT_HAS_MOT_SRV_UPDATED);
            /*no break here*/
        case SRV_MOT_S_EMPTY:
            MMI_MOT_SET_FLAG(MMI_MOT_HAS_MOT_SRV_OPENED);
            return MMI_TRUE;
        default:
            return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_update_srv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mot_update_srv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mot->srv_last_ret = srv_mot_update(g_mot->srv_handle);
    MMI_MOT_MSG_TRACE(g_mot->srv_last_ret);
    if(g_mot->srv_last_ret == SRV_MOT_S_OK)
    {
        return MMI_TRUE;
    }
    else
    {
        return (g_mot->srv_last_ret == SRV_MOT_S_ASYNC) ? 
            (MMI_MOT_SET_FLAG(MMI_MOT_HAS_MOT_SRV_UPDATING), MMI_TRUE) : MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_stop_update_srv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_stop_update_srv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_MOT_CHECK_FLAG(MMI_MOT_HAS_MOT_SRV_UPDATING))
    {
        g_mot->srv_last_ret = srv_mot_stop_updating(g_mot->srv_handle);
        MMI_MOT_MSG_TRACE(g_mot->srv_last_ret);
        MMI_MOT_CLEAR_FLAG(MMI_MOT_HAS_MOT_SRV_UPDATING);
    }
}


/*****************************************************************************
 * FUNCTION
 * mmi_mot_close_srv_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_close_srv_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_MOT_CHECK_FLAG(MMI_MOT_HAS_MOT_SRV_OPENED))
    {
        g_mot->srv_last_ret = srv_mot_close(g_mot->srv_handle);
        MMI_MOT_MSG_TRACE(g_mot->srv_last_ret);
        MMI_MOT_CLEAR_FLAG(MMI_MOT_HAS_MOT_SRV_OPENED);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mot_destroy_srv_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_destroy_srv_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_MOT_CHECK_FLAG(MMI_MOT_HAS_MOT_SRV_CREATED))
    {
        g_mot->srv_last_ret = srv_mot_destroy(g_mot->srv_handle);
        MMI_MOT_MSG_TRACE(g_mot->srv_last_ret);
        MMI_MOT_CLEAR_FLAG(MMI_MOT_HAS_MOT_SRV_CREATED);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_get_category_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_mot_get_category_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MOT_MSG_TRACE(SRV_MOT_CAT_SYSTEM_DEFINE_NUM + 2);
    return SRV_MOT_CAT_SYSTEM_DEFINE_NUM + 2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_get_content_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_mot_get_content_num(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mot_cat_enum mapping_category;
    U32 num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mapping_category = mmi_mot_mapping_category(index);
    g_mot->srv_last_ret = srv_mot_get_content_number(g_mot->srv_handle, mapping_category, &num);
    MMI_MOT_MSG_TRACE(g_mot->srv_last_ret);
    return (g_mot->srv_last_ret == SRV_MOT_S_OK) ? num : 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_need_show_content_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mot_need_show_content_num(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mot_cat_enum mapping_category;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mapping_category = mmi_mot_mapping_category(index);
    MMI_MOT_MSG_TRACE(mapping_category);
    return (mapping_category != SRV_MOT_CAT_RECENT_PLAY) ? MMI_TRUE : MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_prepare_active_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mot_prepare_active_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 content_id;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MOT_MSG_TRACE(g_mot->list_info.highlight);
    content_id = mmi_mot_cache_get_content_id(g_mot->list_info.highlight);
    MMI_MOT_MSG_TRACE(content_id);
    g_mot->srv_last_ret = srv_mot_get_content_path(g_mot->srv_handle, content_id, &g_mot->active_filepath);
    MMI_MOT_MSG_TRACE(g_mot->srv_last_ret);
    if(SRV_MOT_S_OK != g_mot->srv_last_ret)
    {
        return MMI_FALSE;
    }
    
    g_mot->srv_last_ret = srv_mot_add_recent_playlist(g_mot->srv_handle, content_id, 0);
    MMI_MOT_MSG_TRACE(g_mot->srv_last_ret);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_get_category_string_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_ID mmi_mot_get_category_string_id(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mot_cat_enum cat_mapping_index;
    MMI_ID str_id;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat_mapping_index = mmi_mot_mapping_category(index);
    return mmi_mot_get_category_string_id_by_cat_enum(cat_mapping_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_get_category_string_id_by_cat_enum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_ID mmi_mot_get_category_string_id_by_cat_enum(srv_mot_cat_enum cat_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID str_id;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MOT_MSG_TRACE(cat_enum);
    g_mot->srv_last_ret = srv_mot_get_category_string_id(cat_enum, &str_id);
    MMI_MOT_MSG_TRACE(g_mot->srv_last_ret);
    return (g_mot->srv_last_ret == SRV_MOT_S_OK) ? str_id : STR_ID_MOT_UNKNOWN_CLASS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mot_get_content_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_get_content_info(U32 index, srv_mot_content_info_struct* content_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 content_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MOT_MSG_TRACE(index);
    content_id = mmi_mot_cache_get_content_id(index);
    MMI_MOT_MSG_TRACE(content_id);
    g_mot->srv_last_ret = srv_mot_get_content_info(g_mot->srv_handle, content_id, content_info);
    MMI_MOT_MSG_TRACE(g_mot->srv_last_ret);
    mmi_mot_smart_correct_content_info(content_info, (SRV_MOT_S_OK != g_mot->srv_last_ret) ? MMI_TRUE : MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_get_list_info_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_get_list_info_start(U32 start_index, srv_mot_list_info_struct* list_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mot_cat_enum mapping_category;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mapping_category = mmi_mot_mapping_category(g_mot->active_category_index);
    g_mot->srv_last_ret = srv_mot_get_list_info_start(g_mot->srv_handle, mapping_category,
                                                    start_index, SRV_MOT_SORT_DIR_ASC, list_info);
    mmi_mot_cache_build_start(start_index, list_info->content_id);
    MMI_MOT_MSG_TRACE(g_mot->srv_last_ret);
    if(SRV_MOT_S_OK != g_mot->srv_last_ret)
    {
        kal_mem_set(list_info, 0, sizeof(srv_mot_list_info_struct));
        mmi_ucs2cpy((CHAR*)list_info->filename, GetString(STR_ID_MOT_UNKNOWN_FILENAME));
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_get_list_info_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_get_list_info_next(srv_mot_list_info_struct* list_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mot->srv_last_ret = srv_mot_get_list_info_next(g_mot->srv_handle, list_info);
    mmi_mot_cache_update_next(list_info->content_id);
    MMI_MOT_MSG_TRACE(g_mot->srv_last_ret);
    if(SRV_MOT_S_OK != g_mot->srv_last_ret)
    {
        kal_mem_set(list_info, 0, sizeof(srv_mot_list_info_struct));
        mmi_ucs2cpy((CHAR*)list_info->filename, GetString(STR_ID_MOT_UNKNOWN_FILENAME));
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_get_error_string_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_ID_TYPE mmi_mot_get_error_string_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE error_str_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mot_get_error_string_id(g_mot->srv_handle, g_mot->srv_last_ret, &error_str_id);
    return error_str_id;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_smart_correct_content_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_smart_correct_content_info(srv_mot_content_info_struct* content_info, MMI_BOOL correct_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(correct_all == MMI_TRUE || (content_info->title[0] == '\0' && content_info->title[1] == '\0'))
    {
        srv_mot_get_default_string_id(SRV_MOT_DEFAULT_STR_MOVIE_NAME, &id);
	    kal_wsprintf(content_info->title, "%w", GetString(id));
    }
	
    if(correct_all == MMI_TRUE)
    {
        content_info->duration = 0;
    }

    if(correct_all == MMI_TRUE || (content_info->artist[0] == '\0' && content_info->artist[1] == '\0'))
    {
        srv_mot_get_default_string_id(SRV_MOT_DEFAULT_STR_STARRING, &id);
	kal_wsprintf(content_info->artist, "%w", GetString(id));
    }

    if(correct_all == MMI_TRUE || (content_info->datetime[0] == '\0' && content_info->datetime[1] == '\0'))
    {
        srv_mot_get_default_string_id(SRV_MOT_DEFAULT_STR_YEAR, &id);
	kal_wsprintf(content_info->datetime ,"%w",GetString(id));
    }

    if(correct_all == MMI_TRUE || (content_info->descript[0] == '\0' && content_info->descript[1] == '\0'))
    {
        srv_mot_get_default_string_id(SRV_MOT_DEFAULT_STR_PLOT, &id);
	kal_wsprintf(content_info->descript, "%w", GetString(id));
    }	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_srv_get_content_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_mot_srv_get_content_id(U32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mot_cat_enum mapping_category;
    srv_mot_list_info_struct list_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mapping_category = mmi_mot_mapping_category(g_mot->active_category_index);
    g_mot->srv_last_ret = srv_mot_get_list_info_start(g_mot->srv_handle, mapping_category,
                                                    item_index, SRV_MOT_SORT_DIR_ASC, &list_info);
    return list_info.content_id;
}



#define __MMI_MOT_CACHE
/*****************************************************************************
 * FUNCTION
 *  mmi_mot_cache_build_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_cache_build_start(U32 start_index, U32 content_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mot->total_cache_num = 0;
    g_mot->content_cache[g_mot->total_cache_num].item_index = start_index;
    g_mot->content_cache[g_mot->total_cache_num].content_id = content_id;
    g_mot->total_cache_num ++;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_cache_update_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mot_cache_update_next(U32 content_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mot->content_cache[g_mot->total_cache_num].item_index = g_mot->content_cache[g_mot->total_cache_num - 1].item_index + 1;
    g_mot->content_cache[g_mot->total_cache_num].content_id = content_id;
    g_mot->total_cache_num ++;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mot_cache_get_content_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_mot_cache_get_content_id(U32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = item_index - g_mot->content_cache[0].item_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(index>0 && index < g_mot->total_cache_num)
    {
        return g_mot->content_cache[index].content_id;
    }
    
    return mmi_mot_srv_get_content_id(item_index);
}


#endif
