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
 *  PhotoEditor.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Photo Editor Applcation Source of PhotoEditor
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files
*****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_PHOTOEDITOR__

#include "MMIDataType.h"
#ifdef __MMI_CAMERA__
#include "CameraCuiGprot.h"
#ifdef __MMI_CAMCORDER__
#include "mmi_features_camcorder.h"
#include "CamcorderGprot.h"     /* mmi_camco_get_ext_memory_usage */
#else
#include "CameraGprot.h"        /* mmi_camera_get_ext_memory_usage */
#endif
#endif

#include "GlobalResDef.h"
#include "FileMgrSrvGProt.h"
#include "Filemgrcuigprot.h"
#include "Menucuigprot.h"
#include "PhotoEditor.h"
#include "PhotoEditorCui.h"
#include "PhotoEditorCuiGProt.h"
#include "ImgEdtSrvGprot.h"
#include "Drm_Gprot.h"
#include "Commonscreens.h"      /* popup */
#include "FileMgrResDef.h"      /* fmgr string */
#include "FileMgrType.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBSrvGProt.h"        /* srv_usb_is_in_mass_storage_mode */
#include "USBDeviceGprot.h"     /* mmi_usb_get_error_info */
#endif /* __USB_IN_NORMAL_MODE__ */
#include "CommonScreensResDef.h"    /* EVT_ID_ALERT_QUIT */
#include "wgui_categories_util.h"   /* SetLeftSoftkeyFunction */


#define PHOEDT_MAIN_FRAME_COLOR             (GDI_COLOR_WHITE)

#define PHOEDT_ASM_FRAMEBUFFER_OVERHEAD     (100)

/*****************************************************************************
* Define
*****************************************************************************/
#define PHOEDT_APP_DISPLAY_POPUP(parent_gid, message_str, event_id)     \
    mmi_popup_display_simple(                   \
    (WCHAR*)(message_str),                      \
    (mmi_event_notify_enum)(event_id),          \
    (parent_gid),                               \
    NULL)

#define PHOEDT_APP_TRACE_CNTX()                 \
    MMI_TRACE(                                  \
        MMI_MEDIA_TRC_G2_APP,                   \
        MMI_TRC_PHOEDT_CNTX,                    \
        g_phoedt_cntx_p->app_gid,               \
        g_phoedt_cntx_p->filepath,              \
        g_phoedt_cntx_p->cui_memory_ptr,        \
        g_phoedt_cntx_p->cui_memory_size,       \
        __LINE__)


/*****************************************************************************
* Local Vairable
*****************************************************************************/
static phoedt_cntx_struct           *g_phoedt_cntx_p;
static phoedt_app_run_para_struct   *g_phoedt_app_run_para_p;


/*****************************************************************************
* internal APIs
*****************************************************************************/
#define PHOEDT_LOGIC_MANAGER
static void mmi_phoedt_close(void);
static MMI_BOOL mmi_phoedt_mem_malloc_memory(phoedt_app_run_para_struct *run_para);
static void mmi_phoedt_mem_prompt_cancel_cb(mmi_frm_appmem_evt_struct *evt);
static void mmi_phoedt_mem_prompt_success_cb(void);
static void  mmi_phoedt_mem_free_memory(void);
static void mmi_phoedt_mem_prompt_stop_cb(void);
static void mmi_phoedt_launch_int(phoedt_app_run_para_struct *run_para);
static void mmi_phoedt_entry_main_editor(void);
static mmi_ret mmi_phoedt_proc(mmi_event_struct *evt);
static mmi_ret mmi_phoedt_main_editor_proc(mmi_event_struct *evt);
static mmi_ret mmi_phoedt_file_selector_proc(mmi_event_struct *evt);
#ifdef __MMI_CAMERA__
static mmi_ret mmi_phoedt_camera_proc(mmi_event_struct *evt);
#endif /* __MMI_CAMERA__ */
static mmi_ret mmi_phoedt_menu_proc(mmi_event_struct *evt);
static mmi_ret mmi_phoedt_menu_entry_proc(cui_menu_event_struct *evt_menu);
static mmi_ret mmi_phoedt_menu_select_proc(cui_menu_event_struct *evt_menu);
static void mmi_phoedt_rh_exit_cb(void);
static void mmi_phoedt_rh_reentry_cb(MMI_BOOL result, phoedt_rh_reentry_para_union *para);

#define PHOEDT_UI_MANAGER
static void mmi_phoedt_entry_select_file_option_screen(void);
static void mmi_phoedt_entry_select_file_screen(void);
#ifdef __MMI_CAMERA__
static void mmi_phoedt_entry_capture_from_camera(void);
#endif /* __MMI_CAMERA__ */
static void mmi_phoedt_entry_view_image_screen(void);
#ifdef __MMI_PHOEDT_PREVIEW_BEFORE_EDIT__
static void mmi_phoedt_Cat222_result_callback(GDI_RESULT result);
#endif /* __MMI_PHOEDT_PREVIEW_BEFORE_EDIT__ */


#define PHOEDT_EXTERNAL_INTERFACES
/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_hilight_app
 * DESCRIPTION
 *  hilight phoedt menu item hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phoedt_hilight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phoedt_launch, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_init_app
 * DESCRIPTION
 *  init photo editor applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phoedt_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_PHOEDT,
        STR_ID_PHOEDT_APP_NAME,
        IMG_ID_PHOEDT_APP_ICON,
        mmi_phoedt_mem_prompt_stop_cb);
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_launch
* DESCRIPTION
*  launch app
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern void mmi_phoedt_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_rh_reentry_para_union para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para.app_para.filepath[0] = 0;

    mmi_phoedt_rh_add_ins(&para, NULL, mmi_phoedt_rh_exit_cb, mmi_phoedt_rh_reentry_cb);
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_entry_from_fmgr
* DESCRIPTION
*  entry from file manager
* PARAMETERS
*  filepath        [IN]        Path to edit
* RETURNS
*  void
*****************************************************************************/
extern void mmi_phoedt_entry_from_fmgr(const WCHAR *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_rh_reentry_para_union para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(para.app_para.filepath, filepath);

    mmi_phoedt_rh_add_ins(&para, NULL, mmi_phoedt_rh_exit_cb, mmi_phoedt_rh_reentry_cb);
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_get_spin_width
* DESCRIPTION
*  pen repeat hdlr
* PARAMETERS
*  pos     [IN]        Pen up postion
* RETURNS
*  void
*****************************************************************************/
extern S32 mmi_phoedt_get_spin_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (PHOEDT_MAIN_ARROW_FROM_CENTER * 2 - 10);
}


/*****************************************************************************
 * FUNCTION
*  mmi_phoedt_get_appmem_requirement
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern U32 mmi_phoedt_get_appmem_requirement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return PHOEDT_APP_BASED_MEM_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_fmgr_notify_handler
 * DESCRIPTION
 *  stop the program for app_based_memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_ret mmi_phoedt_fmgr_notify_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret         ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = cui_phoedt_fmgr_notify_hdlr(evt);

    return ret;
}


#define PHOEDT_INTERNAL_INTERFACES


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_launch_int
* DESCRIPTION
*  launch app
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_phoedt_launch_int(phoedt_app_run_para_struct *run_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_FALSE == mmi_phoedt_mem_malloc_memory(run_para))
    {
        return;
    }

    g_phoedt_cntx_p->app_gid = mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_AUTO_GEN,
        mmi_phoedt_proc,
        NULL);

    PHOEDT_APP_TRACE_CNTX();

    mmi_frm_group_enter(g_phoedt_cntx_p->app_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if(0 == run_para->filepath[0])
    {
        mmi_phoedt_entry_select_file_option_screen();
    }
    else
    {
        mmi_wcscpy(g_phoedt_cntx_p->filepath, run_para->filepath);
        mmi_phoedt_entry_main_editor();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_close
* DESCRIPTION
*  close current phoart app
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_phoedt_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL != g_phoedt_cntx_p)
    {
        mmi_frm_group_close(g_phoedt_cntx_p->app_gid);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_mem_malloc_memory
* DESCRIPTION
*  get memory
* PARAMETERS
*  sucess_callback      [IN]
* RETURNS
*  sucess or not
*****************************************************************************/
static MMI_BOOL mmi_phoedt_mem_malloc_memory(phoedt_app_run_para_struct *run_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL        success = MMI_TRUE;
    PU8             mem_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL == g_phoedt_cntx_p);

    mem_ptr = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_PHOEDT, PHOEDT_APP_BASED_MEM_SIZE);

    if(NULL == mem_ptr)
    {
        success = MMI_FALSE;
        g_phoedt_app_run_para_p = run_para;
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_PHOEDT,
            IMG_ID_PHOEDT_APP_ICON,
            PHOEDT_APP_BASED_MEM_SIZE,
            mmi_phoedt_mem_prompt_success_cb);

        mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_PHOEDT, mmi_phoedt_mem_prompt_cancel_cb);
    }
    else
    {
        /* set cntx at the tail to avoid alignment problems */
        g_phoedt_cntx_p = (phoedt_cntx_struct*)(mem_ptr + PHOEDT_CUI_NEED_SIZE);
        kal_mem_set(g_phoedt_cntx_p, 0, sizeof(phoedt_cntx_struct));
        g_phoedt_cntx_p->cui_memory_ptr = mem_ptr;
        g_phoedt_cntx_p->cui_memory_size   = PHOEDT_CUI_NEED_SIZE;
        PHOEDT_APP_TRACE_CNTX();
    }

    return success;
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_mem_free_memory
* DESCRIPTION
*  free memory
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_phoedt_mem_free_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_phoedt_cntx_p)
    {
        applib_mem_ap_free(g_phoedt_cntx_p->cui_memory_ptr);
        g_phoedt_cntx_p = NULL;
        mmi_phoedt_rh_remove_ins();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_mem_prompt_stop_cb
 * DESCRIPTION
 *  stop the program for app_based_memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phoedt_mem_prompt_stop_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    static void mmi_phoedt_rh_close_all_ins(void);

    /* if is cui, should close cui */
    mmi_phoedt_rh_close_all_ins();

    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_PHOEDT, MMI_TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_mem_prompt_cancel_cb
* DESCRIPTION
*  mmi_phoedt_mem_prompt_cancel_cb
* PARAMETERS
*  evt          [IN]
* RETURNS
*  None
*****************************************************************************/
static void mmi_phoedt_mem_prompt_success_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phoedt_launch_int(g_phoedt_app_run_para_p);
    g_phoedt_app_run_para_p = NULL;
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_mem_prompt_cancel_cb
* DESCRIPTION
*  mmi_phoedt_mem_prompt_cancel_cb
* PARAMETERS
*  evt          [IN]
* RETURNS
*  None
*****************************************************************************/
static void mmi_phoedt_mem_prompt_cancel_cb(mmi_frm_appmem_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phoedt_close();

    g_phoedt_app_run_para_p = NULL;

    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_PHOEDT, NULL);

    mmi_phoedt_rh_remove_ins();
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_entry_main_editor
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_phoedt_entry_main_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phoedt_run_struct   para;
    MMI_ID                  cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_id = cui_phoedt_create(g_phoedt_cntx_p->app_gid);

    cui_phoedt_struct_init(&para);
    para.origin_filepath = g_phoedt_cntx_p->filepath;

    mmi_phoedt_rh_remove_ins();

    cui_phoedt_run_ext(cui_id, &para, g_phoedt_cntx_p->cui_memory_ptr, g_phoedt_cntx_p->cui_memory_size, MMI_TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_proc
* DESCRIPTION
*
* PARAMETERS
*  evt              [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_phoedt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret     ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_TRUE == cui_phoedt_is_phoedt_event(evt))
    {
        ret = mmi_phoedt_main_editor_proc(evt);
    }
    else if(MMI_TRUE == cui_menu_is_menu_event(evt->evt_id))
    {
        ret = mmi_phoedt_menu_proc(evt);
    }
    else
    {
        switch(evt->evt_id)
        {
        case EVT_ID_GROUP_DEINIT:
            {
                mmi_scenario_evt_struct *scenario_evt = (mmi_scenario_evt_struct*)evt;
                if(scenario_evt->targ_group == g_phoedt_cntx_p->app_gid)
                {
                    mmi_phoedt_mem_free_memory();
                }
            }
            break;

            /* fmgr CUI begin ********************************************************/
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
            ret = mmi_phoedt_file_selector_proc(evt);
            break;
            /* fmgr CUI end **********************************************************/

            /* camera CUI begin ******************************************************/
    #if defined(__MMI_CAMERA__)
        case CUI_CAMERA_EVENT_RESULT_SUCCESS:
        case CUI_CAMERA_EVENT_RESULT_FAILED:
        case CUI_CAMERA_EVENT_RESULT_CLOSE_ME:
            ret = mmi_phoedt_camera_proc(evt);
            break;
    #endif /* defined(__MMI_CAMERA__) */
            /* camera CUI end ********************************************************/

        default:
            break;
        }
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_main_editor_proc
* DESCRIPTION
*  proc for phoart cui
* PARAMETERS
*  evt              [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_phoedt_main_editor_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret             = MMI_RET_OK;
    cui_phoedt_event_struct *phoart_evt     = (cui_phoedt_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(phoart_evt->evt_id)
    {
    case EVT_ID_CUI_PHOEDT_RESULT_CLOSE_ME:
        {
            mmi_phoedt_close();
        }
        break;

    case EVT_ID_CUI_PHOEDT_RESULT_FAILED:
        break;

    case EVT_ID_CUI_PHOEDT_RESULT_SUCCESS:
        break;

    default:
        break;
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_file_selector_proc
* DESCRIPTION
*
* PARAMETERS
*  evt              [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_phoedt_file_selector_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_file_selector_result_event_struct   *evt_fs = (cui_file_selector_result_event_struct *)evt;
    FS_HANDLE                               fs_handle;
    FS_DiskInfo                             disk_info;
    WCHAR                                   drv_name[4];
    mmi_ret                                 ret     = MMI_RET_OK;
    MMI_STR_ID                              err_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt_fs->result > 0)
    {
        cui_file_selector_get_selected_filepath(
            evt_fs->sender_id,
            NULL,
            g_phoedt_cntx_p->filepath,
            (PHOEDT_FULL_PATH_BUFFER_LEN * ENCODING_LENGTH));
    }
    else
    {
        cui_file_selector_close(evt_fs->sender_id);

        return ret;
    }

#ifdef __DRM_SUPPORT__
    if(DRM_METHOD_NONE != DRM_get_object_method(0, g_phoedt_cntx_p->filepath))
    {
        PHOEDT_APP_DISPLAY_POPUP(
            g_phoedt_cntx_p->app_gid,
            GetString(STR_GLOBAL_DRM_PROHIBITED),
            MMI_EVENT_FAILURE);
        return ret;
    }
#endif /* __DRM_SUPPORT__ */

    err_str_id = cui_phoedt_is_supported_format_ext(g_phoedt_cntx_p->filepath);
    if(PHOEDT_RES_DUMMY_ID != err_str_id)
    {
        PHOEDT_APP_DISPLAY_POPUP(
            g_phoedt_cntx_p->app_gid,
            GetString(err_str_id),
            MMI_EVENT_FAILURE);
        return ret;
    }

    mmi_wcsncpy(drv_name, g_phoedt_cntx_p->filepath, 3);

    fs_handle = FS_GetDiskInfo(drv_name, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if(fs_handle >= 0)
    {
        /* if no error - enter view screen */
        mmi_phoedt_entry_view_image_screen();
    }
    else
    {
        /* file system error */
        PHOEDT_APP_DISPLAY_POPUP(
            g_phoedt_cntx_p->app_gid,
            GetString(FMGR_FS_INVALID_FILE_SYSTEM_TEXT),
            MMI_EVENT_FAILURE);

        cui_file_selector_close(evt_fs->sender_id);

        return ret;
    }

    return ret;
}


#if defined(__MMI_CAMERA__)
/*****************************************************************************
* FUNCTION
*  mmi_phoedt_camera_proc
* DESCRIPTION
*
* PARAMETERS
*  evt              [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_phoedt_camera_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;
    cui_camera_event_struct *cam_evt    = (cui_camera_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case CUI_CAMERA_EVENT_RESULT_SUCCESS:
        {
            mmi_wcscpy(g_phoedt_cntx_p->filepath, (WCHAR*)cam_evt->file_path);
            mmi_phoedt_entry_view_image_screen();
            cui_camera_close(cam_evt->sender_id);
        }
        break;

    case CUI_CAMERA_EVENT_RESULT_FAILED:
    case CUI_CAMERA_EVENT_RESULT_CLOSE_ME:
        cui_camera_close(cam_evt->sender_id);
        break;

    default:
        break;
    }
    return ret;
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_menu_proc
* DESCRIPTION
*
* PARAMETERS
*  evt              [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_phoedt_menu_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;
    cui_menu_event_struct   *menu_evt   = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_evt->evt_id)
    {
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_evt->sender_id);
        break;

    case EVT_ID_CUI_MENU_LIST_ENTRY:
        ret = mmi_phoedt_menu_entry_proc(menu_evt);
        break;

    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        ret = mmi_phoedt_menu_select_proc(menu_evt);
        break;

    default:
        break;
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_menu_entry_proc
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_phoedt_menu_entry_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret                     = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt_menu->parent_menu_id)
    {
    case MENU_ID_PHOEDT_SELECT_FILE_OPTION:
        {
        #ifdef __MMI_CAMERA__
            U32 camera_buffer_pool_size = 0;
        #if defined(__MMI_CAMCORDER__)
            camera_buffer_pool_size = mmi_camco_get_ext_memory_usage();
        #else /* __MMI_CAMCORDER__ */
            camera_buffer_pool_size = mmi_camera_get_ext_memory_usage();
        #endif /* __MMI_CAMCORDER__ */
            if (applib_mem_ap_get_max_alloc_size() < (camera_buffer_pool_size + PHOEDT_ASM_FRAMEBUFFER_OVERHEAD))
            {
                cui_menu_set_item_hidden(evt_menu->sender_id, MENU_ID_PHOEDT_CAPTURE_CAMARA, MMI_TRUE);
            }
        #endif /* __MMI_CAMERA__ */
            cui_menu_set_currlist_flags(evt_menu->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
        }
        break;

    default:
        break;
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_menu_select_proc
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_phoedt_menu_select_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret                     = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt_menu->highlighted_menu_id)
    {
    case MENU_ID_PHOEDT_SELECT_FROM_FILE:
        {
            mmi_phoedt_entry_select_file_screen();
        }
        break;


#ifdef __MMI_CAMERA__
    case MENU_ID_PHOEDT_CAPTURE_CAMARA:
        {
            mmi_phoedt_entry_capture_from_camera();
        }
        break;
#endif /* __MMI_CAMERA__ */

    default:
        break;
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_entry_select_file_option_screen
* DESCRIPTION
*  entry select file option screen:select from file, capture from camera
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_phoedt_rh_exit_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phoedt_close();
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_entry_select_file_option_screen
* DESCRIPTION
*  entry select file option screen:select from file, capture from camera
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_phoedt_rh_reentry_cb(MMI_BOOL result, phoedt_rh_reentry_para_union *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_TRUE == result)
    {
        mmi_phoedt_launch_int(&para->app_para);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_entry_select_file_option_screen
* DESCRIPTION
*  entry select file option screen:select from file, capture from camera
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_phoedt_entry_select_file_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID          cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_id = cui_menu_create(
        g_phoedt_cntx_p->app_gid,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_FROM_RESOURCE,
        MENU_ID_PHOEDT_SELECT_FILE_OPTION,
        MMI_FALSE,
        NULL);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_CUI_ID, cui_id, __LINE__);

    cui_menu_set_default_title(
        cui_id,
        (WCHAR*)GetString(STR_ID_PHOEDT_APP_NAME),
        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_PHOEDT_APP)));

    cui_menu_run(cui_id);
}



/*****************************************************************************
* FUNCTION
*  mmi_phoedt_entry_select_file_screen
* DESCRIPTION
*  entry fmgr to select a file
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_phoedt_entry_select_file_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    MMI_ID      cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if(srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if(srv_usb_check_path_exported((WCHAR*) L"root"))
        {
            MMI_STR_ID error_str_id;
            mmi_event_notify_enum error_type;

            /* phone drive is exported, cant use this app */
            error_str_id = mmi_usb_get_error_info(SRV_USB_ERROR_UNAVAILABLE, &error_type);

            PHOEDT_APP_DISPLAY_POPUP(
                g_phoedt_cntx_p->app_gid,
                GetString(error_str_id),
                error_type);

            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    FMGR_FILTER_INIT(&filter);

    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    cui_id = cui_file_selector_create(
        g_phoedt_cntx_p->app_gid,
        (WCHAR*)L"root",
        &filter,
        CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
        CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL | CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_CUI_ID, cui_id, __LINE__);

    cui_file_selector_run(cui_id);
}


#if defined(__MMI_CAMERA__)
/*****************************************************************************
* FUNCTION
*  mmi_phoedt_entry_capture_from_camera
* DESCRIPTION
*  entry camera or camcoder to capture a image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_phoedt_entry_capture_from_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_camera_run_struct   camera_struct;
    MMI_ID                  cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cui_camera_check_and_display_popup())
    {
        cui_camera_struct_init(&camera_struct);

        cui_id = cui_camera_create(g_phoedt_cntx_p->app_gid);

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_CUI_ID, cui_id, __LINE__);

        cui_camera_run(cui_id, &camera_struct);
    }
}
#endif /* __MMI_CAMERA__ */


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_entry_view_image_screen
* DESCRIPTION
*  preview the selected/captured image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_phoedt_entry_view_image_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHOEDT_PREVIEW_BEFORE_EDIT__
    if(!mmi_frm_scrn_enter(
            g_phoedt_cntx_p->app_gid,
            SCR_ID_PHOEDT_VIEW_IMAGE,
            NULL,
            mmi_phoedt_entry_view_image_screen,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ShowCategory222Screen(
        PHOEDT_RES_DUMMY_ID,                            /* title */
        GetRootTitleIcon(MENU_ID_PHOEDT_APP),           /* title icon */
        PHOEDT_RES_DUMMY_ID,
        PHOEDT_RES_DUMMY_ID,                            /* left soft key */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                                /* right soft key */
        PHOEDT_MAIN_FRAME_COLOR,                        /* content BG color */
        NULL,                                           /* button bar string */
        g_phoedt_cntx_p->filepath,                    /* image file name */
        MMI_FALSE,                                      /* is_short */
        mmi_phoedt_Cat222_result_callback,
        GDI_IMAGE_SRC_FROM_FILE);                       /* decode result callback */
#else /* __MMI_PHOEDT_PREVIEW_BEFORE_EDIT__ */
    mmi_phoedt_entry_main_editor();
#endif /* __MMI_PHOEDT_PREVIEW_BEFORE_EDIT__ */
}


#ifdef __MMI_PHOEDT_PREVIEW_BEFORE_EDIT__
/*****************************************************************************
* FUNCTION
*  mmi_phoedt_Cat222_result_callback
* DESCRIPTION
*  category222screen show image callback
* PARAMETERS
*  result       [IN]    successed or failed
* RETURNS
*  void
*****************************************************************************/
static void mmi_phoedt_Cat222_result_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result >= GDI_SUCCEED)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phoedt_entry_main_editor, KEY_EVENT_UP);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_phoedt_entry_main_editor, KEY_EVENT_UP);
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_PHOEDT_PREVIEW_BEFORE_EDIT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_file_type_enabler
 * DESCRIPTION
 *  for fmgr option item "Edit"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phoedt_file_type_enabler(mmi_menu_id item_id, const WCHAR* filepath,
                                          const srv_fmgr_fileinfo_struct* fileinfo)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_FALSE == cui_phoedt_is_supported_format(filepath))
    {
        mmi_frm_hide_menu_item(item_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_file_type_handler
 * DESCRIPTION
 *  for fmgr option item "Edit"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phoedt_file_type_handler(mmi_menu_id item_id, const WCHAR* filepath,
                                          const srv_fmgr_fileinfo_struct* fileinfo)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phoedt_entry_from_fmgr(filepath);
}


#ifdef PHOEDT_REENTRY_HANDLER
#define PHOEDT_RH_DISPLAY_POPUP_CONFIRM(message_id)                 \
    do{                                                             \
        mmi_confirm_property_struct arg;                            \
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);           \
        arg.callback = mmi_phoedt_rh_confirm_proc;                  \
        arg.user_tag = (void*)(message_id);                         \
        mmi_confirm_display(                                        \
            (WCHAR*)GetString(message_id),                          \
            MMI_EVENT_QUERY,                                        \
            &arg);                                                  \
    }while(MMI_FALSE)

#define PHOEDT_RH_TRACE_CNTX()                  \
    MMI_TRACE(                                  \
        MMI_MEDIA_TRC_G2_APP,                   \
        MMI_TRC_PHOEDT_RH_CNTX,                 \
        g_phoedt_rh_cntx.current_ins.state,     \
        g_phoedt_rh_cntx.current_ins.save_cb,   \
        g_phoedt_rh_cntx.current_ins.exit_cb,   \
        g_phoedt_rh_cntx.reentry_ins.state,     \
        g_phoedt_rh_cntx.reentry_ins.save_cb,   \
        g_phoedt_rh_cntx.reentry_ins.exit_cb,   \
        &g_phoedt_rh_cntx.reentry_para,         \
        g_phoedt_rh_cntx.reentry_cb,            \
        __LINE__)

static void mmi_phoedt_rh_emit_cbs(MMI_BOOL is_success_reentry, MMI_BOOL is_save);
static void mmi_phoedt_rh_process_reentry(void);
static mmi_ret mmi_phoedt_rh_confirm_proc(mmi_event_struct *evt);
static phoedt_rh_cntx_struct    g_phoedt_rh_cntx;
/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_rh_add_ins
 * DESCRIPTION
 *  phoedt internal function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phoedt_rh_add_ins(
    const phoedt_rh_reentry_para_union    *para,
    callback                save_cb,
    callback                exit_cb,
    reentry_callback        reentry_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_RH_ADD_INS,
        para, save_cb, exit_cb, reentry_cb);

    PHOEDT_RH_TRACE_CNTX();

    if(PHOEDT_RH_INS_STATE_INITED == g_phoedt_rh_cntx.current_ins.state)
    {
        g_phoedt_rh_cntx.current_ins.state = PHOEDT_RH_INS_STATE_INACTIVED;
        g_phoedt_rh_cntx.current_ins.save_cb = save_cb;
        g_phoedt_rh_cntx.current_ins.exit_cb = exit_cb;
    }
    else if(PHOEDT_RH_INS_STATE_ACTIVED == g_phoedt_rh_cntx.current_ins.state ||
        PHOEDT_RH_INS_STATE_NOT_SAVED == g_phoedt_rh_cntx.current_ins.state)
    {
        g_phoedt_rh_cntx.reentry_ins.state = PHOEDT_RH_INS_STATE_INACTIVED;
        g_phoedt_rh_cntx.reentry_ins.save_cb = save_cb;
        g_phoedt_rh_cntx.reentry_ins.exit_cb = exit_cb;
    }
    else
    {
        MMI_ASSERT(0);
        return;
    }
    kal_mem_cpy(&g_phoedt_rh_cntx.reentry_para, para, sizeof(phoedt_rh_reentry_para_union));
    g_phoedt_rh_cntx.reentry_cb = reentry_cb;

    mmi_phoedt_rh_process_reentry();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_rh_remove_ins
 * DESCRIPTION
 *  phoedt internal function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phoedt_rh_remove_ins(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_RH_REMOVE_INS);

    PHOEDT_RH_TRACE_CNTX();

    if(PHOEDT_RH_INS_STATE_INITED == g_phoedt_rh_cntx.current_ins.state)
    {
        return;
    }
    else if(PHOEDT_RH_INS_STATE_ACTIVED == g_phoedt_rh_cntx.current_ins.state ||
        PHOEDT_RH_INS_STATE_NOT_SAVED == g_phoedt_rh_cntx.current_ins.state)
    {
        if(PHOEDT_RH_INS_STATE_INITED == g_phoedt_rh_cntx.reentry_ins.state)
        {
            kal_mem_set(&g_phoedt_rh_cntx, 0, sizeof(phoedt_rh_cntx_struct));
        }
        else if(PHOEDT_RH_INS_STATE_INACTIVED == g_phoedt_rh_cntx.reentry_ins.state)
        {
            g_phoedt_rh_cntx.current_ins = g_phoedt_rh_cntx.reentry_ins;
            kal_mem_set(&g_phoedt_rh_cntx.reentry_ins, 0, sizeof(phoedt_rh_ins_struct));
            mmi_phoedt_rh_emit_cbs(MMI_TRUE, MMI_FALSE);
        }
        else
        {
            MMI_ASSERT(0);
            return;
        }
    }
    else if(PHOEDT_RH_INS_STATE_INACTIVED == g_phoedt_rh_cntx.current_ins.state)
    {
        kal_mem_set(&g_phoedt_rh_cntx, 0, sizeof(phoedt_rh_cntx_struct));
    }
    else
    {
        MMI_ASSERT(0);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_rh_set_state
 * DESCRIPTION
 *  phoedt internal function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phoedt_rh_set_not_saved(MMI_BOOL is_not_save)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PHOEDT_RH_TRACE_CNTX();

    if(PHOEDT_RH_INS_STATE_ACTIVED == g_phoedt_rh_cntx.current_ins.state &&
        MMI_TRUE == is_not_save)
    {
        g_phoedt_rh_cntx.current_ins.state = PHOEDT_RH_INS_STATE_NOT_SAVED;
    }
    else if(PHOEDT_RH_INS_STATE_NOT_SAVED == g_phoedt_rh_cntx.current_ins.state &&
        MMI_FALSE == is_not_save)
    {
        g_phoedt_rh_cntx.current_ins.state = PHOEDT_RH_INS_STATE_ACTIVED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_rh_cb_ins
 * DESCRIPTION
 *  not reset para after call reentry_cb,
 *  because reentry may be have OOM, then CUI and APP will keep para to use
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phoedt_rh_emit_cbs(MMI_BOOL is_success_reentry, MMI_BOOL is_save)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_RH_EMIT_CBS);

    PHOEDT_RH_TRACE_CNTX();

    if(PHOEDT_RH_INS_STATE_INACTIVED == g_phoedt_rh_cntx.current_ins.state &&
        PHOEDT_RH_INS_STATE_INITED == g_phoedt_rh_cntx.reentry_ins.state)
    {
        if(NULL != g_phoedt_rh_cntx.reentry_cb)
        {
            g_phoedt_rh_cntx.reentry_cb(is_success_reentry, &g_phoedt_rh_cntx.reentry_para);
            if(PHOEDT_RH_INS_STATE_INACTIVED == g_phoedt_rh_cntx.current_ins.state)
            {
                /* cause reentry may be failed, then will remove the ins.
                at that time, g_phoedt_rh_cntx.current_ins.state will be PHOEDT_RH_INS_STATE_INITED */
                g_phoedt_rh_cntx.current_ins.state = PHOEDT_RH_INS_STATE_ACTIVED;
                g_phoedt_rh_cntx.reentry_cb = NULL;
            }
        }
        else
        {
            MMI_ASSERT(0);
        }
        return;
    }

    if(MMI_TRUE == is_success_reentry)
    {
        /* exit_cb and save_cb will let current_ins call remove_ins,
            remove_ins will trigger reentry reentry_ins */
        if(MMI_TRUE == is_save &&
            PHOEDT_RH_INS_STATE_NOT_SAVED == g_phoedt_rh_cntx.current_ins.state)
        {
            if(NULL != g_phoedt_rh_cntx.current_ins.save_cb)
            {
                g_phoedt_rh_cntx.current_ins.save_cb();
                return;
            }
        }
        else if(NULL != g_phoedt_rh_cntx.current_ins.exit_cb)
        {
            g_phoedt_rh_cntx.current_ins.exit_cb();
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        if(NULL != g_phoedt_rh_cntx.reentry_cb)
        {
            g_phoedt_rh_cntx.reentry_cb(MMI_FALSE, &g_phoedt_rh_cntx.reentry_para);
        }
        kal_mem_set(&g_phoedt_rh_cntx.reentry_ins, 0, sizeof(phoedt_rh_ins_struct));
        g_phoedt_rh_cntx.reentry_cb = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_rh_cb_ins
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phoedt_rh_process_reentry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PHOEDT_RH_TRACE_CNTX();

    if(PHOEDT_RH_INS_STATE_INITED == g_phoedt_rh_cntx.current_ins.state)
    {
        return;
    }

    if(PHOEDT_RH_INS_STATE_INACTIVED == g_phoedt_rh_cntx.current_ins.state &&
        PHOEDT_RH_INS_STATE_INITED == g_phoedt_rh_cntx.reentry_ins.state)
    {
        mmi_phoedt_rh_emit_cbs(MMI_TRUE, MMI_FALSE);
        return;
    }

    PHOEDT_RH_DISPLAY_POPUP_CONFIRM(STR_ID_PHOEDT_EXTERNAL_EXIT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_rh_confirm_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_phoedt_rh_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                     ret             = MMI_RET_OK;
    mmi_alert_result_evt_struct *alert_evt      = (mmi_alert_result_evt_struct*)evt;
    U32                         str_id          = (U32)alert_evt->user_tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PHOEDT_RH_TRACE_CNTX();

    if(EVT_ID_ALERT_QUIT == evt->evt_id)
    {
        switch (alert_evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            {
                if(PHOEDT_RH_INS_STATE_ACTIVED == g_phoedt_rh_cntx.current_ins.state)
                {
                    /* exit and success cb */
                    mmi_phoedt_rh_emit_cbs(MMI_TRUE, MMI_FALSE);
                }
                else if(PHOEDT_RH_INS_STATE_NOT_SAVED == g_phoedt_rh_cntx.current_ins.state)
                {
                    if(STR_ID_PHOEDT_EXTERNAL_EXIT_SAVE_PRE == str_id)
                    {
                        /* save and exit and success cb */
                        mmi_phoedt_rh_emit_cbs(MMI_TRUE, MMI_TRUE);
                    }
                    else if(STR_ID_PHOEDT_EXTERNAL_EXIT == str_id)
                    {
                        PHOEDT_RH_DISPLAY_POPUP_CONFIRM(STR_ID_PHOEDT_EXTERNAL_EXIT_SAVE_PRE);
                    }
                }
            }
            break;

        case MMI_ALERT_INTERRUPT_EXIT:
        case MMI_ALERT_CNFM_NO:
            {
                if(STR_ID_PHOEDT_EXTERNAL_EXIT_SAVE_PRE == str_id)
                {
                    /* exit without save and success cb */
                    mmi_phoedt_rh_emit_cbs(MMI_TRUE, MMI_FALSE);
                }
                else if(STR_ID_PHOEDT_EXTERNAL_EXIT == str_id)
                {
                    /* faile cb */
                    mmi_phoedt_rh_emit_cbs(MMI_FALSE, MMI_FALSE);
                }
            }
            break;

        default:
            break;
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_rh_close_all_ins
 * DESCRIPTION
 *  special handle function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phoedt_rh_close_all_ins(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PHOEDT_RH_TRACE_CNTX();

    if((PHOEDT_RH_INS_STATE_ACTIVED == g_phoedt_rh_cntx.current_ins.state ||
        PHOEDT_RH_INS_STATE_NOT_SAVED == g_phoedt_rh_cntx.current_ins.state) &&
        PHOEDT_RH_INS_STATE_INITED == g_phoedt_rh_cntx.reentry_ins.state &&
        NULL != g_phoedt_rh_cntx.current_ins.exit_cb)
    {
        /* exit_cb will let current_ins call remove_ins,
        remove_ins will trigger reentry reentry_ins */
        g_phoedt_rh_cntx.current_ins.exit_cb();
    }
    else
    {
        MMI_ASSERT(0);
        return;
    }
}

#endif /* PHOEDT_REENTRY_HANDLER */
#endif /* __MMI_PHOTOEDITOR__ */

