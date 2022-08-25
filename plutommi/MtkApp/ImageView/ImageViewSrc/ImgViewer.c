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
*  ImgViewer.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  Imageviewer App.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_IMAGE_VIEWER__

#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "FS_gprot.h"
#include "Wgui_categories_util.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "Filemgrcuigprot.h"
#include "MMI_features_camera.h"        /* features - in custom folder */
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#include "USBDeviceGprot.h"
#endif
#include "mmi_frm_app_launcher_gprot.h"
#include "ImgViewerConfig.h"
#include "mmi_rp_app_imageviewer_def.h"
#include "ImageviewCuiGprot.h"
#include "ImgViewerGprot.h"
#include "ImgViewer.h"
#ifdef __MMI_SNS_PHOTO_UPLOAD__
#include "SnsAppGprot.h"
#endif

/***********************************************************
*            APP API Decrearation                         *
**********************************************************/
#ifndef __MMI_IV_PLUTO_SLIM__
static cui_fmgr_ui_style_enum iv_app_get_view_style(void);
#endif
static void iv_app_popup_msg(
                mmi_id parent_gid,
                MMI_STR_ID str_id,
                mmi_event_notify_enum event,
                mmi_frm_screen_rotate_enum rotate,
                iv_alert_quit_func quit_func);

static MMI_BOOL iv_app_init(imgview_cnxt_t *pcontext);
static mmi_ret iv_app_enter_browser(imgview_cnxt_t *pcontext);

static imgview_cnxt_t g_imgview_cntx;
static mmi_ret mmi_imgview_launch_int(mmi_event_struct *evt);

typedef struct
{
    MMI_EVT_PARAM_HEADER
    MMI_ID app_id;
} mmi_iv_app_post_launch_event_struct;

#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) 
extern MMI_BOOL mmi_camera_enter_imageviewer_check(void);
#endif
MMI_BOOL enter_imageviewer = MMI_FALSE;
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_malloc_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static imgview_cnxt_t *mmi_imgview_malloc_cntx()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_imgview_cntx;
}

#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata = "DYNAMIC_CODE_CAMIMGV_RODATA",code = "DYNAMIC_CODE_CAMIMGV_ROCODE"
#endif

#ifdef __MMI_SLIM_FILE_MANAGER__


/*****************************************************************************
 * FUNCTION
 *  iv_app_fs_error_get_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fs_error        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_str_id iv_app_fs_error_get_string(S32 fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fs_error == FS_DISK_FULL)
    {
        return STR_GLOBAL_NOT_ENOUGH_MEMORY;
    }

    return srv_fmgr_fs_error_get_string(fs_error);
}

#else /* __MMI_SLIM_FILE_MANAGER__ */ 

#define iv_app_fs_error_get_string(err) srv_fmgr_fs_error_get_string(err)

#endif /* __MMI_SLIM_FILE_MANAGER__ */ 

/***********************************************************************
*                Storage Functions                                     *
**********************************************************************/
#ifdef __MMI_IVF_STORAGE__


/*****************************************************************************
 * FUNCTION
 *  iv_app_storage_confirm_quit
 * DESCRIPTION
 *  quit proc of storage confirm screen.
 * PARAMETERS
 *  pcontext        [?]     
 *  evt             [?]     Events pointer.
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
static iv_app_storage_confirm_quit(struct imgview_cnxt *pcontext, mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_evt = (mmi_alert_result_evt_struct*) evt;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_evt->result == MMI_ALERT_CNFM_YES)
    {
        ret = mmi_imgview_set_storage((U16) SRV_FMGR_PUBLIC_DRV);
        if (ret == FS_NO_ERROR) /* avoid enter endless loop for the drv confirmed is full or bad */
        {
            mmi_imgview_get_storage_file_path(pcontext->folder);
            pcontext->browser_gid = iv_app_enter_browser(pcontext);
        }
        else
        {
            iv_app_popup_msg(
                pcontext->top_group_id,
                iv_app_fs_error_get_string(ret),
                (mmi_event_notify_enum) MMI_EVENT_FAILURE,
                pcontext->scrn_rot,
                NULL);
        }
    }
    else if (alert_evt->result == MMI_ALERT_CNFM_NO ||      /* select no */
             alert_evt->result == MMI_ALERT_INTERRUPT_EXIT) /* interrupt close */
    {
        mmi_frm_group_close(pcontext->top_group_id);
    }

}


/*****************************************************************************
 * FUNCTION
 *  iv_app_storage_confirm
 * DESCRIPTION
 *  This function is to confirm save before saving setting.
 * PARAMETERS
 *  pcontext        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void iv_app_storage_confirm(imgview_cnxt_t *pcontext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_drv_type_enum storage_type_old;
    MMI_STR_ID query_str_id;
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage_type_old = (srv_fmgr_drv_type_enum) srv_fmgr_drv_get_type((U8)mmi_imgview_get_storage());

    if (storage_type_old >= SRV_FMGR_DRV_CARD_TYPE && storage_type_old <= SRV_FMGR_DRV_CARD_2_TYPE)
    {
        query_str_id = STR_GLOBAL_MC_REMOVED_USE_PHONE;
    }
    else if (storage_type_old >= SRV_FMGR_DRV_OTG_TYPE && storage_type_old <= SRV_FMGR_DRV_OTG_8_TYPE)
    {
        query_str_id = STR_GLOBAL_OTG_REMOVED_USE_PHONE_QUERY;
    }
    else
        return;

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = pcontext->top_group_id;
    arg.user_tag = (void*)iv_app_storage_confirm_quit;
    mmi_confirm_display((WCHAR*) GetString(query_str_id), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  iv_app_set_storage_screen
 * DESCRIPTION
 *  enter set storage screen
 * PARAMETERS
 *  gid     [IN]        
 *  drv     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void iv_app_set_storage_screen(MMI_ID gid, U16 drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fmgr_storage_selector_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((fmgr_storage_selector_gid = cui_storage_selector_create(gid, (U8) drv, CUI_STORAGE_SELECTOR_DRV_TYPE_ACCESIBLE_ONLY)) != GRP_ID_INVALID)
    {
        cui_storage_selector_set_title(fmgr_storage_selector_gid, NULL, GetRootTitleIcon(MENU_ID_IMGVIEW_APP));
        cui_storage_selector_set_ui_style(fmgr_storage_selector_gid, CUI_FMGR_UI_STYLE_BANNER_LIST);    /* NEED TEST */
        cui_storage_selector_run(fmgr_storage_selector_gid);
    }
    else
    {
        /* TODO: add trace, create error */
    }
}


/*****************************************************************************
 * FUNCTION
 *  iv_app_entry_set_storage_screen
 * DESCRIPTION
 *  enter set storage screen
 * PARAMETERS
 *  pcontext        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void iv_app_entry_set_storage_screen(imgview_cnxt_t *pcontext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fmgr_storage_selector_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((fmgr_storage_selector_gid = cui_storage_selector_create(pcontext->top_group_id, (U8)mmi_imgview_get_storage(), CUI_STORAGE_SELECTOR_DRV_TYPE_ACCESIBLE_ONLY)) != GRP_ID_INVALID)
    {
        cui_storage_selector_set_title(fmgr_storage_selector_gid, NULL, GetRootTitleIcon(MENU_ID_IMGVIEW_APP));
        cui_storage_selector_set_ui_style(fmgr_storage_selector_gid, CUI_FMGR_UI_STYLE_BANNER_LIST);    /* NEED TEST */
        cui_storage_selector_run(fmgr_storage_selector_gid);
    }
    else
    {
        /* TODO: add trace, create error */
    }
}


/*****************************************************************************
 * FUNCTION
 *  iv_app_storage_select_cb
 * DESCRIPTION
 *  entry storage screen
 * PARAMETERS
 *  pcontext        [?]         
 *  drv             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U32 iv_app_storage_select_cb(imgview_cnxt_t *pcontext, S32 drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    MMI_ID_TYPE error_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drv > 0)
    {
        /* Create Image folder & DB folder */
        ret = mmi_imgview_set_storage((U16)drv);

        if (ret < FS_NO_ERROR)
        {
            error_str_id = iv_app_fs_error_get_string(ret);
            iv_app_popup_msg(
                pcontext->top_group_id,
                error_str_id,
                (mmi_event_notify_enum) srv_fmgr_fs_error_get_popup_type(ret),
                MMI_FRM_SCREEN_ROTATE_0,
                NULL);
        }
        else
        {
            iv_app_init(pcontext);  /* always success */
            if (pcontext->browser_gid != GRP_ID_INVALID)
            {
                cui_folder_browser_set_folder_path(pcontext->browser_gid, (WCHAR*) (pcontext->folder));
            }
            else
            {
                pcontext->browser_gid = iv_app_enter_browser(pcontext);
            }

            return 0;
        }

    }
    else
    {
        return 0;
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  iv_app_on_alert_quit
 * DESCRIPTION
 *  Exit app on alert quit.
 * PARAMETERS
 *  pcontext        [?]     
 *  evt             [?]     Events pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void iv_app_on_alert_quit(struct imgview_cnxt *pcontext, mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iv_app_set_storage_screen(pcontext->top_group_id, mmi_imgview_get_storage());
}

#endif /* __MMI_IVF_STORAGE__ */ 

/*****************************************************************************
 * FUNCTION
 *  iv_app_enter_browser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pcontext        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret iv_app_enter_browser(imgview_cnxt_t *pcontext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    U32 option_flag;
    mmi_id browse_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_ENTER_BROWSER);
    /* Configure filter */
    mmi_imgview_init_img_filter(&filter);

    /* Configure option flag */
    option_flag = 0;
#if defined(__FMGR_CSK_FORWARD__)
    option_flag |= CUI_FOLDER_BROWSER_OPT_FAST_FORWARD_ON;
#endif 
    browse_gid = cui_folder_browser_create(
                    pcontext->top_group_id,
                    (WCHAR*) pcontext->folder,
                    &filter,
                    option_flag,
                    MENU_ID_IMGVIEW_FILE_OPTION,
					#if defined( __MMI_IVF_STORAGE__ )
                    MENU_ID_IMGVIEW_EMPTY_FOLDER_OPTION
					#else
					NULL
					#endif
					);
    if (browse_gid != GRP_ID_INVALID)
    {
    #ifndef __MMI_IV_PLUTO_SLIM__
        pcontext->browser_style = iv_app_get_view_style();
	#endif
        cui_folder_browser_set_title(browse_gid, STR_ID_IMGVIEW_NAME, GetRootTitleIcon(MENU_ID_IMGVIEW_APP));
	#ifndef __MMI_IV_PLUTO_SLIM__
        cui_folder_browser_set_ui_style(browse_gid, pcontext->browser_style);
	#endif
        cui_folder_browser_run(browse_gid);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_BROWSER_FAIL);
        mmi_frm_group_close(pcontext->top_group_id);
    }

    return browse_gid;
}


/*****************************************************************************
 * FUNCTION
 *  iv_app_popup_msg
 * DESCRIPTION
 *  This function shows display popup.
 * PARAMETERS
 *  parent_gid      [IN]        
 *  str_id          [IN]        
 *  event           [IN]        
 *  rotate          [IN]        
 *  quit_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void iv_app_popup_msg(
                mmi_id parent_gid,
                MMI_STR_ID str_id,
                mmi_event_notify_enum event,
                mmi_frm_screen_rotate_enum rotate,
                iv_alert_quit_func quit_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);

    arg.parent_id = parent_gid;
    arg.user_tag = (void*)quit_func;

#if defined(__MMI_SCREEN_ROTATE__)
    arg.rotation = rotate;
#else 
    arg.rotation = MMI_FRM_SCREEN_ROTATE_0;
#endif 
    mmi_popup_display_ext(str_id, event, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  iv_app_init
 * DESCRIPTION
 *  image viewer entry point
 * PARAMETERS
 *  pcontext        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL iv_app_init(imgview_cnxt_t *pcontext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 create_result;
    MMI_STR_ID error_string_id;
    S32 error_type = MMI_EVENT_FAILURE;
    iv_alert_quit_func alert_quit = NULL;
    SRV_FMGR_DRVLIST_HANDLE drvlist;
    S32 total_drv_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init storage */
    create_result = mmi_imgview_get_storage_file_path(pcontext->folder);

    if (create_result == FS_NO_ERROR)
        return MMI_TRUE;

    /* error handle */

    /* Only support one storage */
    /* check driver list */
    drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
    total_drv_num = srv_fmgr_drivelist_count(drvlist);
    srv_fmgr_drivelist_destroy(drvlist);
    /* for 64+32 */
    if (total_drv_num == 0) /* only support one storage and it's not accessible */
    {
        error_string_id = STR_GLOBAL_INSERT_MEMORY_CARD;
    }

#ifdef __MMI_IVF_STORAGE__

    /* current drv not OK, there's one available */
    else if (total_drv_num == 1 && FS_MSDC_MOUNT_ERROR == create_result)
    {
        iv_app_storage_confirm(pcontext);
        return MMI_FALSE;
    }
#endif /* __MMI_IVF_STORAGE__ */ 
    /* there's one available, but error */
    else if (total_drv_num == 1)
    {
        error_string_id = iv_app_fs_error_get_string(create_result);

    }
#ifdef __MMI_IVF_STORAGE__

    /* current drv not OK, there's more than one available */
    else
    {
        if (FS_MSDC_MOUNT_ERROR == create_result)
        {
            iv_app_set_storage_screen(pcontext->top_group_id, mmi_imgview_get_storage());
            return MMI_FALSE;
        }
        else
        {
            error_string_id = iv_app_fs_error_get_string(create_result);
            alert_quit = iv_app_on_alert_quit;
        }
    }
#else /* __MMI_IVF_STORAGE__ */ 
    else
    {   /* never reached here, just for build warning */
        return MMI_FALSE;
    }
#endif /* __MMI_IVF_STORAGE__ */ 

    iv_app_popup_msg(
        pcontext->top_group_id,
        error_string_id,
        (mmi_event_notify_enum) error_type,
        pcontext->scrn_rot,
        alert_quit);

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  iv_app_enter_view_screen
 * DESCRIPTION
 *  Preentry function of imageviewer.
 * PARAMETERS
 *  app_id          [IN]        
 *  parent_id       [IN]        
 *  hlist           [IN]        
 *  cur_index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void iv_app_enter_view_screen(U16 app_id, MMI_ID parent_id, SRV_FMGR_FILELIST_HANDLE hlist, S32 cur_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_count;
    MMI_ID ivcui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_count = srv_fmgr_filelist_count(hlist);
    if (file_count)
    {
        cui_imgview_src_data srcdata;

        srcdata.file_list.h_list = hlist;
        srcdata.file_list.cur_index = cur_index;
        ivcui_id = cui_imgview_create_ex(app_id, parent_id);
        cui_imgview_init_source(ivcui_id, IMGVIEW_SRC_FILELIST, &srcdata);
        cui_imgview_run(ivcui_id);
    }
    else
    {
        iv_app_popup_msg(parent_id, STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, MMI_FRM_SCREEN_ROTATE_0, NULL);
    }
}

#ifndef __MMI_IV_PLUTO_SLIM__

/*****************************************************************************
 * FUNCTION
 *  iv_app_get_view_style
 * DESCRIPTION
 *  set meidaview style
 * PARAMETERS
 *  void
 * RETURNS
 *  cui_fmgr_ui_style_enum   style
 *****************************************************************************/
static cui_fmgr_ui_style_enum iv_app_get_view_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvram_value = CUI_FMGR_UI_STYLE_ICON_LIST;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_IMGVIEW_VIEW_SYTLE, &nvram_value, DS_BYTE, &error);
    return nvram_value == 0xFF ? CUI_FMGR_UI_STYLE_MATRIX : (cui_fmgr_ui_style_enum) nvram_value;
}


/*****************************************************************************
 * FUNCTION
 *  iv_app_set_view_style
 * DESCRIPTION
 *  set mediaview style
 * PARAMETERS
 *  pcontext        [?]         
 *  value           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void iv_app_set_view_style(imgview_cnxt_t *pcontext, mmi_menu_id value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 nvram_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value == MENU_ID_IMGVIEW_VIEW_STYLE_LIST)
    {
        nvram_value = CUI_FMGR_UI_STYLE_ICON_LIST;
    }
    else
    {
        nvram_value = CUI_FMGR_UI_STYLE_MATRIX;
    }

    WriteValue(NVRAM_IMGVIEW_VIEW_SYTLE, &nvram_value, DS_BYTE, &error);

    //iv_app_popup_msg(pcontext->ap_gid, STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, MMI_FRM_SCREEN_ROTATE_0, NULL);

    /* FMGR_Revise */
    cui_folder_browser_set_ui_style(pcontext->browser_gid, (cui_fmgr_ui_style_enum) nvram_value);
}

#endif
/*****************************************************************************
 * FUNCTION
 *  iv_app_fd_browser_proc
 * DESCRIPTION
 *  handle event comes from browser cui
 * PARAMETERS
 *  evt     [?]     Event struct
 * RETURNS
 *  void
 *****************************************************************************/
void iv_app_fd_browser_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imgview_cnxt_t *pcontext = (imgview_cnxt_t*) evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FOLDER_BROWSER_ON_OPTION:
        {
            cui_folder_browser_on_option_event_struct *opt_evt = (cui_folder_browser_on_option_event_struct*) evt;
			#ifndef __MMI_IV_PLUTO_SLIM__
            if (opt_evt->menu_cui_evt->parent_menu_id == MENU_ID_IMGVIEW_VIEW_STYLE &&
                opt_evt->menu_cui_evt->evt_id == EVT_ID_CUI_MENU_LIST_ENTRY)
            {
                mmi_menu_id sub_id = (iv_app_get_view_style() == CUI_FMGR_UI_STYLE_ICON_LIST) ?
                    MENU_ID_IMGVIEW_VIEW_STYLE_LIST : MENU_ID_IMGVIEW_VIEW_STYLE_MATRIX;
                cui_menu_set_currlist_highlighted_id(opt_evt->menu_cui_id, sub_id);
            }
			#else
				#if !defined( __MMI_IVF_STORAGE__ )
					  cui_menu_set_item_hidden(opt_evt->menu_cui_id, MENU_ID_IMGVIEW_STORAGE, MMI_TRUE);
				#endif
			#endif
        }
            break;
        case EVT_ID_CUI_FOLDER_BROWSER_ON_MENU:
        {
            cui_folder_browser_on_menu_event_struct *menu_evt = (cui_folder_browser_on_menu_event_struct*) evt;

            switch (menu_evt->menuitem_id)
            {
                case MENU_ID_IMGVIEW_VIEW_DETAIL:
                {
                    SRV_FMGR_FILELIST_HANDLE hlist;
                    S32 cur_index;
                    S32 ret;

                    ret = cui_folder_browser_lock_filelist(pcontext->browser_gid, &hlist, &cur_index);
                    MMI_EXT_ASSERT(ret == 0, ret, 0, 0);
                    iv_app_enter_view_screen(APP_IMAGEVIEWER, pcontext->top_group_id, hlist, cur_index);
                }
                    break;
#ifndef __MMI_IV_PLUTO_SLIM__

                case MENU_ID_IMGVIEW_VIEW_STYLE_LIST:
                case MENU_ID_IMGVIEW_VIEW_STYLE_MATRIX:
                    iv_app_set_view_style(pcontext, menu_evt->menuitem_id);
                    break;
#endif
            #ifdef __MMI_IVF_STORAGE__
                case MENU_ID_IMGVIEW_STORAGE:
                    iv_app_entry_set_storage_screen(pcontext);
                    break;
            #endif /* __MMI_IVF_STORAGE__ */ 
                default:
                    break;
            }
        }
            break;

        case EVT_ID_CUI_FOLDER_BROWSER_ON_ENTRY:
            /* mmi_mediaview_browse_cui_enter_callback(((mmi_group_event_struct*)evt)->sender_id); */
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_group_proc
 * DESCRIPTION
 *  Media view cui process function.
 * PARAMETERS
 *  evt     [?]     Events pointer.
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
static mmi_ret mmi_imgview_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imgview_cnxt_t *pcontext = (imgview_cnxt_t*) evt->user_data;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_MEDIA_TRC_G2_APP, CUI_MEDIAVIEW_PROC, evt->evt_id); */
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            /* free App resource */
            break;

        case EVT_ID_CUI_FOLDER_BROWSER_ON_QUIT:
            mmi_frm_group_close(pcontext->browser_gid);
            break;

        case EVT_ID_IMGVIEW_CLOSE:
            index = cui_imgview_get_cur_index(((mmi_group_event_struct*) evt)->sender_id);
            mmi_frm_group_close(((mmi_group_event_struct*) evt)->sender_id);
            cui_folder_browser_unlock_filelist(pcontext->browser_gid);
            cui_folder_browser_set_highlight_index(pcontext->browser_gid, index);
            break;

        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert_evt = (mmi_alert_result_evt_struct*) evt;
            iv_alert_quit_func quit_func = (iv_alert_quit_func) alert_evt->user_tag;

            if (quit_func)
                quit_func(pcontext, evt);
        }
            break;

    #ifdef __MMI_IVF_STORAGE__
        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
        {
            if (iv_app_storage_select_cb(pcontext, ((cui_storage_selector_result_event_struct*) evt)->result) == 0)
                cui_storage_selector_close(((cui_storage_selector_result_event_struct*) evt)->sender_id);
        }
            break;
    #endif /* __MMI_IVF_STORAGE__ */ 

        case EVT_ID_CUI_FOLDER_BROWSER_ON_OPTION:
        case EVT_ID_CUI_FOLDER_BROWSER_ON_ENTRY:
        case EVT_ID_CUI_FOLDER_BROWSER_ON_EXIT:
        case EVT_ID_CUI_FOLDER_BROWSER_ON_EMPTY:
        case EVT_ID_CUI_FOLDER_BROWSER_ON_MENU:
        case EVT_ID_CUI_FOLDER_BROWSER_ON_CSK:
            iv_app_fd_browser_proc(evt);
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_launch_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_imgview_launch_proc (mmi_event_struct *evt) {
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
#ifdef __MMI_SUPPORT_ASMV2__
	MMI_ID app_id =	GET_APP_ID(evt);
#endif

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{

#ifdef __MMI_SUPPORT_ASMV2__
		case EVT_ID_APP_ENTER:
#else
		case EVT_ID_GROUP_ENTER:
#endif
		{
            mmi_iv_app_post_launch_event_struct event;
            MMI_FRM_INIT_EVENT(&event, 0);
#ifdef __MMI_SUPPORT_ASMV2__
            event.app_id = app_id;
#else
				event.app_id = APP_IMAGEVIEWER;
#endif
            MMI_FRM_POST_EVENT(&event, mmi_imgview_launch_int, NULL);
			break;
		}
#ifdef __MMI_SUPPORT_ASMV2__
		case EVT_ID_APP_DEINIT:
#else
		case EVT_ID_GROUP_DEINIT:
#endif
        enter_imageviewer = MMI_FALSE;
        #ifdef __MMI_AP_DCM_CAMIMGV__
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) 
		if(!mmi_camera_enter_imageviewer_check())
		{        
#endif
            mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_CAMIMGV);
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) 
        }
#endif
        #endif
			break;
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_launch_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_imgview_launch_int(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imgview_cnxt_t *pcontext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_LAUNCH);

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        iv_app_popup_msg(
            ((mmi_iv_app_post_launch_event_struct*) evt)->app_id,
            mmi_usb_get_error_info(0, NULL),
            MMI_EVENT_FAILURE,
            MMI_FRM_SCREEN_ROTATE_0,
            NULL);
        return MMI_RET_DONT_CARE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* malloc APP memory */
    pcontext = mmi_imgview_malloc_cntx();
    if (!pcontext)
    {
        return MMI_RET_DONT_CARE;
    }
    memset(pcontext, 0, sizeof(pcontext));
    pcontext->scrn_rot = MMI_FRM_SCREEN_ROTATE_0;
    pcontext->app_id = ((mmi_iv_app_post_launch_event_struct*) evt)->app_id;
    pcontext->top_group_id = mmi_frm_group_create_ex(
                        ((mmi_iv_app_post_launch_event_struct*) evt)->app_id,
                        GRP_ID_AUTO_GEN,
                        mmi_imgview_group_proc,
                        pcontext,
                        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (iv_app_init(pcontext) == MMI_TRUE)
    {
        /* enter Folder browser CUI */
        enter_imageviewer = MMI_TRUE;
        pcontext->browser_gid = iv_app_enter_browser(pcontext);
    }

    return MMI_RET_DONT_CARE;
}


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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif



#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata,code
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
APP_API void mmi_imgview_launch(void) {
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
#ifndef __MMI_SUPPORT_ASMV2__
	MMI_ID this_gid = GRP_ID_INVALID;
#endif
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef __MMI_SUPPORT_ASMV2__
    if (mmi_frm_app_is_launched(APP_IMAGEVIEWER)) {
        mmi_frm_app_close(APP_IMAGEVIEWER);
    }
#else
	if (mmi_frm_group_is_present(APP_IMAGEVIEWER)) {
		mmi_frm_group_close(APP_IMAGEVIEWER);
	}
#endif

#ifdef __MMI_AP_DCM_CAMIMGV__
    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_CAMIMGV);
#endif 
#ifndef __MMI_SUPPORT_ASMV2__
	this_gid = mmi_frm_group_create(
		GRP_ID_ROOT,
		APP_IMAGEVIEWER,
		mmi_imgview_launch_proc,
		NULL);

	mmi_frm_group_enter(this_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
#else
    mmi_frm_app_launch(APP_IMAGEVIEWER, 0, 0, mmi_imgview_launch_proc, NULL, MMI_FRM_APP_NORMAL_LAUNCH);
#endif
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_highlight_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
SYS_CALLBACK void mmi_imgview_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgview_launch, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_init_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
SYS_CALLBACK void mmi_imgview_init_app(void)
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
 *  mmi_imgview_fmgr_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [?]     
 * RETURNS
 *  
 *****************************************************************************/
SYS_CALLBACK mmi_ret mmi_imgview_fmgr_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_RET ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->evt_id)
    {
    #ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
        {
            srv_fmgr_notification_set_def_storage_event_struct *fmgr_storage
                = (srv_fmgr_notification_set_def_storage_event_struct*) event;

            if (fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_QUERY)       /* MMI_FMGR_NOTIFY_SET_STORAGE_PRE_CHK */
            {
                if (mmi_frm_scrn_get_active_id() == SCR_ID_IMGVIEW_VIEW)
                {
                    ret = MMI_RET_ERR;
                }
            }
            else if (fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)  /* MMI_FMGR_NOTIFY_SET_STORAGE */
            {
                mmi_imgview_set_storage((U16) fmgr_storage->drv_letter);
            }
        }
            break;

    #endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */ 

        default:
            break;
    }
    return ret;
}





/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_handler
 * DESCRIPTION
 *  for fmgr option item "view"
 * PARAMETERS
 *  item_id         [IN]        
 *  filepath        [IN]        
 *  fileinfo        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
SYS_CALLBACK void mmi_imgview_view_handler(
                    mmi_menu_id item_id,
                    const WCHAR *filepath,
                    const srv_fmgr_fileinfo_struct *fileinfo)
{
    if (item_id == MENU_ID_IMGVIEW_OPTION_IMG_VIEW)
    {
         mmi_imgview_simple_launch((PS8)filepath, STRING_ID_NULL, IMAGE_ID_NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_enabler
 * DESCRIPTION
 *  for fmgr option item "view"
 * PARAMETERS
 *  item_id         [IN]        
 *  filepath        [IN]        
 *  fileinfo        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
SYS_CALLBACK void mmi_imgview_view_enabler(
                    mmi_menu_id item_id,
                    const WCHAR *filepath,
                    const srv_fmgr_fileinfo_struct *fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_id == MENU_ID_IMGVIEW_OPTION_IMG_VIEW)
    {
        if (FMGR_GROUP_IMAGE != srv_fmgr_types_find_group_by_filename_str(filepath) ||
            FMGR_TYPE_ANM == fileinfo->type ||
            FMGR_TYPE_EMS == fileinfo->type ||
            FMGR_TYPE_SVG == fileinfo->type)
        {
            mmi_frm_hide_menu_item(item_id);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_file_type_handler
 * DESCRIPTION
 *  for fmgr option item "image information"
 * PARAMETERS
 *  item_id         [IN]        
 *  filepath        [IN]        
 *  fileinfo        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
SYS_CALLBACK void mmi_imgview_file_type_handler(
                    mmi_menu_id item_id,
                    const WCHAR *filepath,
                    const srv_fmgr_fileinfo_struct *fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_id == MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION)
    {
    #ifdef __MMI_AP_DCM_CAMIMGV__
        mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_CAMIMGV);
    #endif 
        mmi_imgview_show_img_info(GRP_ID_ROOT, filepath);
	#ifdef __MMI_AP_DCM_CAMIMGV__
	if(!enter_imageviewer
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) 
        && !mmi_camera_enter_imageviewer_check()
#endif
		)
        {
        	mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_CAMIMGV);
    	}
        #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_file_type_enabler
 * DESCRIPTION
 *  for fmgr option item "image information"
 * PARAMETERS
 *  item_id         [IN]        
 *  filepath        [IN]        
 *  fileinfo        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
SYS_CALLBACK void mmi_imgview_file_type_enabler(
                    mmi_menu_id item_id,
                    const WCHAR *filepath,
                    const srv_fmgr_fileinfo_struct *fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_id == MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION)
    {
        if (FMGR_GROUP_IMAGE != srv_fmgr_types_find_group_by_filename_str(filepath) ||
            FMGR_TYPE_ANM == fileinfo->type ||
            FMGR_TYPE_EMS == fileinfo->type ||
            FMGR_TYPE_SVG == fileinfo->type)
        {
            mmi_frm_hide_menu_item(MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION);
        }
    }
}


#ifdef __MMI_SNS_PHOTO_UPLOAD__
/*****************************************************************************
 * FUNCTION
 *  mmi_iv_sns_photo_upload_enabler
 * DESCRIPTION
 *  for fmgr option item "send->to sns"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_iv_sns_photo_upload_enabler(mmi_menu_id item_id, const WCHAR* filepath,
                                          const srv_fmgr_fileinfo_struct* fileinfo)

{
    FMGR_FILTER file_type;
    S32 ret;

    if(item_id == MENU_ID_FMGR_FWD_SNS_PHOTO_UPLOAD){
        FMGR_FILTER_INIT(&file_type);
        ret = srv_fmgr_types_find_type_by_filepath(filepath);
        if(ret >= 0)
        {
            FMGR_FILTER_SET(&file_type, ret);

            if(FMGR_FILTER_IS_SET_IMAGE(&file_type) == MMI_FALSE)
            {
                mmi_frm_hide_menu_item(MENU_ID_FMGR_FWD_SNS_PHOTO_UPLOAD);
            }
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_FMGR_FWD_SNS_PHOTO_UPLOAD);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_iv_sns_photo_upload_handler
 * DESCRIPTION
 *  for fmgr option item "send->to sns"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_iv_sns_photo_upload_handler(mmi_menu_id item_id, const WCHAR* filepath,
                                          const srv_fmgr_fileinfo_struct* fileinfo)

{
    if(item_id == MENU_ID_FMGR_FWD_SNS_PHOTO_UPLOAD){

        mmi_sns_upload_photo_from_imageviewer(GRP_ID_ROOT, (WCHAR*)filepath);
    }
}
#endif /* __MMI_SNS_PHOTO_UPLOAD__ */

/*
 * simple app
 */

#define APP_IMAGEVIEWER_SIMPLE (APP_IMAGEVIEWER)
typedef struct {
    MMI_ID app_id;
    WCHAR file_path[SRV_FMGR_PATH_BUFFER_SIZE];
    U16 string;
    U16 icon;
} mmi_imageviewer_simple_app_context;

static mmi_imageviewer_simple_app_context g_simple_app_context;

#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata = "DYNAMIC_CODE_CAMIMGV_RODATA",code = "DYNAMIC_CODE_CAMIMGV_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_image_view_group_proc
 * DESCRIPTION
 *  FMGR image view process
 * PARAMETERS
 *  evt      : [OUT] event pointer
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_fmgr_image_view_simple_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
        /* enter group ToDo1 */
            break;
        case EVT_ID_GROUP_ACTIVE:
        /* enter group ToDo2 */
            break;
        case EVT_ID_GROUP_FOCUSED:
        /* enter group ToDo3 */
            break;
        case EVT_ID_GROUP_GOBACK:
        /* gobackhistory ToDo1 */
            break;
        case EVT_ID_GROUP_INACTIVE:
        /* gobackhistory ToDo2 */
            break;
        case EVT_ID_GROUP_EXIT:
        /* gobackhistory ToDo3 */
            break;
        case EVT_ID_GROUP_DEINIT:
        /* gobackhistory ToDo4 */
            break;
        case EVT_ID_IMGVIEW_CLOSE_GID:
        /* closegroup ToDo1 */
        {
            mmi_group_event_struct *cui_evt = (mmi_group_event_struct*)evt;
            cui_imgview_close(cui_evt->sender_id);
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}


static mmi_ret mmi_imgview_simple_launch_int(mmi_event_struct *evt)
{
    mmi_id temp_parent_gid;
    mmi_id imgview_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_parent_gid = mmi_frm_group_create(g_simple_app_context.app_id, GRP_ID_AUTO_GEN, mmi_fmgr_image_view_simple_group_proc, NULL); 
    mmi_frm_group_enter(temp_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if ((imgview_gid = cui_imgview_create(temp_parent_gid)) != GRP_ID_INVALID)
    {
	    enter_imageviewer = MMI_TRUE;
        cui_imgview_set_mode_filename(imgview_gid, (CHAR *) g_simple_app_context.file_path);
        cui_imgview_set_app_id(imgview_gid, g_simple_app_context.app_id);
      //  cui_imgview_set_title(imgview_gid, NULL, g_simple_app_context.icon);
        cui_imgview_set_ui_direction(imgview_gid, CUI_IMGVIEW_UI_DIRECTION_VERTICAL);
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_ALL, MMI_TRUE);
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_COUNTER, MMI_FALSE);   
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_SLIDESHOW, MMI_FALSE);   
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_TITLE, MMI_FALSE);   
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_DB, MMI_FALSE);   
        cui_imgview_run(imgview_gid);
    }
    else
    {
        mmi_frm_group_close(temp_parent_gid);
    }
    return MMI_RET_DONT_CARE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_simple_launch_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_imgview_simple_launch_proc (mmi_event_struct *evt) {
	MMI_ID app_id =	GET_APP_ID(evt);
	switch (evt->evt_id)
	{
#ifdef __MMI_SUPPORT_ASMV2__
		case EVT_ID_APP_ENTER:
#else
		case EVT_ID_GROUP_ENTER:
#endif
		{
            mmi_iv_app_post_launch_event_struct event;
            MMI_FRM_INIT_EVENT(&event, 0);
            event.app_id = app_id;
            MMI_FRM_POST_EVENT(&event, mmi_imgview_simple_launch_int, NULL);
			break;
		}

#ifdef __MMI_SUPPORT_ASMV2__
		case EVT_ID_APP_DEINIT:
#else
		case EVT_ID_GROUP_DEINIT:
#endif
		enter_imageviewer = MMI_FALSE;
        #ifdef __MMI_AP_DCM_CAMIMGV__
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) 
        if(!mmi_camera_enter_imageviewer_check())
		{        
#endif
            mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_CAMIMGV);
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) 
        }
#endif
        #endif
			break;
	}
	return MMI_RET_OK;
}

#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata,code
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_launch
 * DESCRIPTION
 *  image viewer entry point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_simple_launch(PS8 file_path, U16 string, U16 icon) 
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
#ifndef __MMI_SUPPORT_ASMV2__
	MMI_ID this_gid = GRP_ID_INVALID;
#endif

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef __MMI_SUPPORT_ASMV2__
    if (mmi_frm_app_is_launched(APP_IMAGEVIEWER_SIMPLE)) {
        mmi_frm_app_close(APP_IMAGEVIEWER_SIMPLE);
    }
#else
	if (mmi_frm_group_is_present(APP_IMAGEVIEWER_SIMPLE)) {
		mmi_frm_group_close(APP_IMAGEVIEWER_SIMPLE);
	}
#endif
#ifdef __MMI_AP_DCM_CAMIMGV__
    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_CAMIMGV);
#endif 
    g_simple_app_context.app_id = APP_IMAGEVIEWER_SIMPLE;
    g_simple_app_context.string = string;
    g_simple_app_context.icon = icon;
    mmi_ucs2cpy((CHAR*) g_simple_app_context.file_path, (CHAR*) file_path);

#ifndef __MMI_SUPPORT_ASMV2__
		this_gid = mmi_frm_group_create(
		GRP_ID_ROOT,
		APP_IMAGEVIEWER_SIMPLE,
		mmi_imgview_simple_launch_proc,
		NULL);

	mmi_frm_group_enter(this_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
#else
    mmi_frm_app_launch(APP_IMAGEVIEWER_SIMPLE, 0, 0, mmi_imgview_simple_launch_proc, NULL, MMI_FRM_APP_NORMAL_LAUNCH);
#endif

}


#endif /* __MMI_IMAGE_VIEWER__ */ 

