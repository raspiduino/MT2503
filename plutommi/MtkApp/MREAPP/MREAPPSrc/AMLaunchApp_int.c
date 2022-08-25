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
*   AMLaunchApp_int.c
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/***************************************************************************** 
* Include header files
*****************************************************************************/
#include "vmswitch.h"
#ifdef __MRE_APP_LAUNCH__
#include "MMIDataType.h"
#include "MMI_features.h"
#include "GlobalConstants.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "Gui.h"
#include "gui_data_types.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "FileMgrSrvGProt.h"
#include "mmi_trc_int.h"
#include "gdi_include.h"
#include "AlertScreen.h"

#include "mmi_rp_app_am_def.h"
#include "AMGprot.h"
#include "AMConfig.h"
#include "AMUtil.h"
#include "AMMainScreen.h"
#include "MMI_mre_trc.h"
#include "MRESrvGProt.h"
#include "MREAppMgrSrvGprot.h"
#include "wgui_categories.h"
#include "Conversions.h"

//#ifdef __MRE_AM__
//extern void mmi_am_ms_draw_cert_check_popup(void);
//extern mmi_am_ms_draw_install_cert_check_popup(U16 *app_path);
//#endif
/***************************************************************************** 
* Local Variable
*****************************************************************************/
static U16 g_mre_app_path[SRV_FMGR_PATH_MAX_LEN + 1];
//#ifdef __MRE_AM__
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
extern mmi_am_cntx_struct g_am_cntx;
#endif

extern void* parameter_of_start;

extern mmi_ret srv_mre_launch_app_confirm_popup_proc (mmi_alert_result_evt_struct *evt);
extern mmi_ret srv_mre_install_app_confirm_popup_proc (mmi_alert_result_evt_struct *evt);
extern srv_mre_write_app_path(U16 *app_path);
extern S32 srv_mre_appmgr_get_file_type(WCHAR *path);
extern U32 mmi_la_get_build_in_app_array_size();
extern MMI_BOOL srv_usb_is_in_mass_storage_mode(void);
extern void mmi_usb_app_unavailable_popup(U16 stringId);
extern void _vm_kernel_free(void* ptr);
extern UI_string_type get_string(UI_string_ID_type stringID);
/*****************************************************************************
* FUNCTION
*  mmi_am_la_grp_proc
* DESCRIPTION
*  
* PARAMETERS
*  evt     [IN]     Event pointer.
* RETURNS
*  
*****************************************************************************/
static mmi_ret mmi_am_la_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* switch (evt->evt_id)
    {
    case EVT_ID_GROUP_ENTER:
    break;

    case EVT_ID_GROUP_ACTIVE:
    break;

    case EVT_ID_GROUP_INACTIVE:
    break;

    case EVT_ID_GROUP_DEINIT:
    break;
    }*/
    //return ret;
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_la_leave_loading_scrn
* DESCRIPTION
*  
* PARAMETERS
*  evt     [IN]     Event pointer.
* RETURNS
*  
*****************************************************************************/
static mmi_ret mmi_am_la_leave_loading_scrn(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_LA_LEAVE_SCREEN, evt->evt_id);

    switch (evt->evt_id)
    {
    case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
    break;

    case EVT_ID_SCRN_DEINIT:
    break;
    }

    return ret;*/
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_la_draw_loading_scrn
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_la_draw_loading_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width, img_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw background */
    gdi_draw_solid_rect(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT, GDI_COLOR_BLACK);

    /* get image width and height */
    gdi_image_get_dimension_id(IMG_ID_AM_LOADING, &img_width, &img_height);

    /* draw mre icon in the center of screen */
    gdi_image_draw_id((GDI_LCD_WIDTH - img_width) >> 1, (GDI_LCD_HEIGHT - img_height) >> 1, IMG_ID_AM_LOADING);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_la_entry_loading_scrn
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_la_entry_loading_scrn(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(
        GRP_ID_AM,
        SCR_ID_AM_LAUNCH_APP_LOADING,
        NULL,
        mmi_am_la_entry_loading_scrn,
        MMI_FRM_FG_ONLY_SCRN);

    if (ret == MMI_FALSE)
    {
        return;
    }
    if (srv_mre_appmgr_get_file_type(app_path)!=SRV_MRE_APPMGR_APP_TYPE_SERVICE)
    {
        ShowCategory221Screen(0, 0, 0, 0, 0, 0, GDI_COLOR_BLACK, mmi_am_la_draw_loading_scrn);
        //SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
        //SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    }
    /* set leave proc */
    mmi_frm_scrn_set_leave_proc(GRP_ID_AM, SCR_ID_AM_LAUNCH_APP_LOADING, mmi_am_la_leave_loading_scrn);    // TODO: modify
}


/*****************************************************************************
* FUNCTION
*  mmi_am_la_app_launch_cb
* DESCRIPTION
*  
* PARAMETERS
*  app_path        [IN]         Application path.
*  evt             [IN]        Event id.
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_la_app_launch_cb(U16 *app_path, srv_mre_launch_app_evt_enum evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt)
    {
    case SRV_MRE_LAUNCH_APP_EVT_SUCCESS:
        //#ifdef __MRE_AM__
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
        g_am_cntx.is_launch_app = MMI_TRUE;
#endif
        break;

    case SRV_MRE_LAUNCH_APP_ASM_READY:
        mmi_am_launch_app_by_path(app_path);
        break;

        //case SRV_MRE_LAUNCH_APP_EVT_INTERNEL_ERROR:
        //  break;

        //case SRV_MRE_LAUNCH_APP_EVT_QUIT:
        // TODO:
        // 1. bg running some apps -> asm stop list
        // 2. started normal app -> asm stop list
        // 3. started appstore -> asm stop list
        //   break;

    default:
        break;
    }
}

U16*    a_glb_app_path = NULL;
void mmi_am_la_app_launch_load_core_cb(srv_mre_load_core_evt_enum evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt)
    {
    case SRV_MRE_LOAD_CORE_EVT_SUCCESS:
        srv_mre_launch_app(a_glb_app_path, mmi_am_la_app_launch_cb);
        break;

        //case SRV_MRE_LOAD_CORE_EVT_INTERNAL_ERROR:
        //   break;

        //case SRV_MRE_LOAD_CORE_EVT_QUIT:
        //  break;

    default:
        break;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_am_la_app_launch
* DESCRIPTION
*  
* PARAMETERS
*  app_path        [IN]     Application path.
* RETURNS
*  
*****************************************************************************/
void mmi_am_ms_draw_cert_check_popup(void)
{
    // Notice user for CERT error. Is still launcher app?
    mmi_confirm_property_struct confirm_popup;
    mmi_confirm_property_init(&confirm_popup, CNFM_TYPE_YESNO);
    confirm_popup.parent_id = GRP_ID_ROOT;
    confirm_popup.callback	= srv_mre_launch_app_confirm_popup_proc;
    mmi_confirm_display(
        (UI_string_type) GetString(STR_ID_VAPP_AM_POPUP_NO_AUTH), 
        MMI_EVENT_QUERY, 
        &confirm_popup);
}

void mmi_am_ms_draw_install_cert_check_popup(U16 *app_path)
{
    // Notice user for CERT error. Is still launcher app?

    mmi_confirm_property_struct confirm_popup;
    srv_mre_write_app_path(app_path);
    mmi_confirm_property_init(&confirm_popup, CNFM_TYPE_YESNO);
    confirm_popup.parent_id = GRP_ID_ROOT;
    confirm_popup.callback	= srv_mre_install_app_confirm_popup_proc;
    mmi_confirm_display(
        (UI_string_type) GetString(STR_ID_VAPP_AM_INSTALL_POPUP_NO_AUTH), 
        MMI_EVENT_QUERY, 
        &confirm_popup);
}

static MMI_BOOL mmi_am_la_check_popup_internal(U16 *app_path,srv_mre_launch_app_result_enum result,MMI_BOOL flag)//0:launch, 1:install
{
    //result = srv_mre_launch_app(app_path, mmi_am_la_app_launch_cb);
    // MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_APP_LAUNCH_RESULT, result);
    MMI_BOOL ret = MMI_FALSE;
    switch (result)
    {
    case SRV_MRE_LAUNCH_APP_SUCCESS:
        ret = MMI_TRUE;
        break;
    case SRV_MRE_LAUNCH_APP_ILLEGAL:
    case SRV_MRE_LAUNCH_APP_CALL_STACK_FULL:
    case SRV_MRE_LAUNCH_APP_INTERNAL_ERROR:
    case SRV_MRE_LAUNCH_APP_BANNED_APP:
        mmi_popup_display_simple((WCHAR*) get_string(STR_ID_AM_FAIL_TO_START), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        break;
    case SRV_MRE_LAUNCH_APP_FORCE:
#if defined( __MMI_MRE_NO_POPUP_AUTHENTICATION_SUPPORT__)||!defined(__MRE_AM__)
        mmi_popup_display_simple((WCHAR*) get_string(STR_ID_AM_FAIL_TO_START), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
#else
        if(flag==MMI_FALSE)
        {
            mmi_am_ms_draw_cert_check_popup();
        }
        else
        {
            mmi_am_ms_draw_install_cert_check_popup(app_path); 
        }
#endif
        break;
    case SRV_MRE_LAUNCH_APP_NOT_ENOUGH_MEMORY:
        mmi_popup_display_simple(
            //                (WCHAR*) get_string(STR_ID_AM_NOT_ENOUGH_MEMORY),
            (WCHAR*) get_string(STR_GLOBAL_NOT_ENOUGH_MEMORY),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
        break;
    case SRV_MRE_LAUNCH_APP_PLATFORM_PARAM_DISMATCH:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_TAG_ERR_FAIL_TO_START),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
        break;
    case SRV_MRE_LAUNCH_APP_TIMESTAMP_ERROR:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_DATE_ERR_FAIL_TO_START),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
        break;
    case SRV_MRE_LAUNCH_APP_IMSI_DISMATCH:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_INVALID_SIM_FAIL_TO_START),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
        break;
    case SRV_MRE_LAUNCH_APP_CERT_OVERDUE:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_CERT_EXPIRED_FAIL_TO_START),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
        break;
    case SRV_MRE_LAUNCH_APP_EXCEED_FILE_IN_MRE_DIRECTORY:
        mmi_popup_display_simple((WCHAR*) get_string(STR_ID_AM_FILE_OVERFLOW), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        break;
    case SRV_MRE_LAUNCH_APP_MAX_NUM: 
        // when app reach the max num can be start ,should be pupop a notify to end-customer.
        mmi_popup_display_simple((WCHAR*) get_string(STR_ID_AM_POPUP_LIMITATION_APP), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        break;
    case SRV_MRE_LAUNCH_APP_SYS_ASYN_ASM:
        break;
    }
    return ret;
}
static MMI_BOOL mmi_am_la_app_launch(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    srv_mre_launch_app_result_enum result;
    srv_mre_load_core_result_enum load_mre_core_ret;    
    S8 file_name_log_out[SRV_FMGR_PATH_MAX_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!app_path)
    {
        return MMI_FALSE;
    }
    a_glb_app_path = app_path;
    memset(file_name_log_out, 0, sizeof(file_name_log_out));
    mmi_wcs_to_asc(file_name_log_out, app_path);
    MMI_PRINT(MOD_MRE, MMI_MRE_TRC_G1_AM, "[MRE] mmi_am_la_app_launch <app_path:%s>\n", file_name_log_out);

    /* Load MRE Core */
    if (!srv_mre_is_core_loaded())
    {
        load_mre_core_ret = srv_mre_load_core(mmi_am_la_app_launch_load_core_cb, SRV_MRE_CALLER_AM);
        if (load_mre_core_ret != SRV_MRE_LOAD_CORE_SUCCESS)
        {
            return MMI_FALSE;
        }
    }

    result = srv_mre_launch_app(app_path, mmi_am_la_app_launch_cb);
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_APP_LAUNCH_RESULT, result);
    mmi_am_la_check_popup_internal(app_path,result,MMI_FALSE);

    /* Add Start <Start With Parameter> */
    if(SRV_MRE_LAUNCH_APP_SYS_ASYN_ASM != result)
    {
        // free the memory.
        _vm_kernel_free(parameter_of_start);
        parameter_of_start = NULL;
    }
    /* Add END <Start With Parameter> */	 

    //if(SRV_MRE_LAUNCH_APP_SUCCESS != result)
    //{
       // srv_mre_unload_core(SRV_MRE_CALLER_AM);
   // }
    return ret;
}


MMI_BOOL mmi_am_install_app_check_popup(U16 *app_path)
{
    srv_mre_launch_app_result_enum result = srv_mre_launch_app_check_cert(app_path);
    MMI_BOOL ret=MMI_FALSE;
    ret = mmi_am_la_check_popup_internal(app_path,result,MMI_TRUE);
    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_am_launch_app_by_path_cb
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_launch_app_by_path_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* call MRE app launch api */
    //ret = 
    mmi_am_la_app_launch(g_mre_app_path);
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LAUNCH_APP_LOADING);   // TODO: verify this point
}


/*****************************************************************************
* FUNCTION
*  mmi_am_launch_app_by_path
* DESCRIPTION
*  
* PARAMETERS
*  app_path        [IN]     Application path.
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_launch_app_by_path(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    //    mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR)), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    //    return;
#endif /* __MTK_TARGET__ */ 

#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())/* is in storage mode */
    {
        /* phone drive is exported, can't use this app */
        mmi_usb_app_unavailable_popup(0);	/* pass 0 will show default string */
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PRE_START_CHECK_E2);
        return MMI_FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (!app_path)
    {
        return MMI_FALSE;
    }

    /* enter screen group */
    if (!mmi_frm_group_is_present(GRP_ID_AM))
    {
        /* enter screen group */
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AM, mmi_am_la_grp_proc, NULL);
        mmi_frm_group_enter(GRP_ID_AM, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    /* check whether the file exists */
    if (!srv_mre_is_buildin_app(app_path))
    {
        FS_HANDLE fd = -1;

        if ((fd = FS_Open(app_path, FS_OPEN_NO_DIR | FS_READ_ONLY)) < FS_NO_ERROR)
        {
            /* app is not exist */
            mmi_popup_display_simple(
                (WCHAR*) get_string(STR_ID_AM_FILE_NOT_EXIST),
                MMI_EVENT_FAILURE,
                GRP_ID_AM,
                NULL);
            return MMI_FALSE;
        }
        FS_Close(fd);
    }

    /* show a loading screen */
    mmi_am_la_entry_loading_scrn(app_path);

    mmi_wcscpy(g_mre_app_path, app_path);
    /* start a timer to launch app */
    gui_start_timer(100, mmi_am_launch_app_by_path_cb);
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_la_get_image_id
* DESCRIPTION
*  
* PARAMETERS
*  appid       [IN]        
* RETURNS
*  image id
*****************************************************************************/
U16 mmi_am_la_get_image_id(mmi_am_shortcut_id_enum appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (mmi_la_get_build_in_app_array_size()/sizeof(mmi_am_launch_app_info_struct)); i++)
    {
        if (g_am_la_info_list[i].app_id == appid)
        {
            return g_am_la_info_list[i].image_id;
        }
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_la_get_string_id
* DESCRIPTION
*  
* PARAMETERS
*  appid       [IN]        
* RETURNS
*  string id
*****************************************************************************/
U16 mmi_am_la_get_string_id(mmi_am_shortcut_id_enum appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (mmi_la_get_build_in_app_array_size()/sizeof(mmi_am_launch_app_info_struct)); i++)
    {
        if (g_am_la_info_list[i].app_id == appid)
        {
            return g_am_la_info_list[i].name_id;
        }
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_launch_app_by_id
* DESCRIPTION
*  
* PARAMETERS
*  appid       [IN]        
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_la_is_ota_vxp_exist(U16 *rom_app_path,U16 * new_app_path)
{
    U16 package_name_w[60];
    U8 package_name[60];
    U16 filepath[SRV_FMGR_PATH_MAX_LEN + 1];
    S32 app_type = 0;
    FS_HANDLE file_hdl = -1;
    U16 rom_app_update_path_w[100];
    memset(filepath, 0, sizeof(filepath));
    memset(rom_app_update_path_w, 0, sizeof(rom_app_update_path_w));
    memset(new_app_path,0,sizeof(new_app_path));
    if(srv_mre_appmgr_generate_identification(rom_app_path,package_name_w))
    {
        mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8 , (char *)package_name_w, (char *)package_name, 60);
        app_type = srv_mre_appmgr_get_app_type((char *)package_name);
    }
    
    if(app_type == (SRV_MRE_APPMGR_APP_TYPE_ROM|SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL))
    {
			if (srv_mre_appmgr_get_file_path((char *)package_name, filepath))
	    {
	        file_hdl = FS_Open(filepath, FS_OPEN_NO_DIR | FS_READ_ONLY);
	        FS_Close(file_hdl);
	    }
    }
     if(file_hdl >= FS_NO_ERROR)	
     {
     	  mmi_wcscpy(new_app_path,filepath);
        return MMI_TRUE;
     }
     if(vm_update_check_launch(rom_app_path,rom_app_update_path_w))
     {
        mmi_wcscpy(new_app_path,rom_app_update_path_w);
     	  return MMI_TRUE;
     }
    return MMI_FALSE;
}
MMI_BOOL mmi_am_launch_app_by_id(mmi_am_shortcut_id_enum appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 i;
    U16 rom_app_path[20];
    U16 new_app_path[260];
    #if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
    S8 *app_name;
    U16 app_path[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (appid <= APPID_NONE || appid >= APPID_MAX)
    {
        return MMI_FALSE;
    }
#ifdef WIN32
	mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE, NULL);
#else
    memset(new_app_path,0,sizeof(new_app_path));
    /* Check if the app is ROM app */
    for (i = 0; i < (mmi_la_get_build_in_app_array_size()/sizeof(mmi_am_launch_app_info_struct)); i++)
    {
        if (g_am_la_info_list[i].app_id == appid)
        {
            /* build app path */
            kal_wsprintf((WCHAR *)rom_app_path, "@:\\%u.rom", g_am_la_info_list[i].app_array);
            if(mmi_am_la_is_ota_vxp_exist(rom_app_path,new_app_path))
            {
            	return mmi_am_launch_app_by_path(new_app_path);
            }
            else
            {
            	return mmi_am_launch_app_by_path(rom_app_path);
            }
        }
    }

    //#ifdef __MRE_AM__
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
    app_name = mmi_am_config_get_ql_app_name_by_appid(appid);
    if (mmi_am_is_app_downloaded(app_name, app_path))
    {
        mmi_am_launch_app_by_path(app_path);
        return MMI_TRUE;
    }
    else
    {
        /* enter download flow */
        mmi_am_dla_op_outside_download(g_am_cntx.dla_h, appid);
        return MMI_TRUE;
    }
#endif /* __MRE_AM__ */
#endif
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_start_from_fm
* DESCRIPTION
*  
* PARAMETERS
*  path        [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_start_from_fm(U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_path(path);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_start_from_hs
* DESCRIPTION
*  
* PARAMETERS
*  path        [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_start_from_hs(U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_path(path);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_start_from_mm
* DESCRIPTION
*  
* PARAMETERS
*  appid       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_start_from_mm(mmi_am_shortcut_id_enum appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(appid);
}

//#ifdef __MRE_AM__
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
/*****************************************************************************
* FUNCTION
*  mmi_am_is_need_to_set_shortcut
* DESCRIPTION
*  
* PARAMETERS
*  idx       [IN]        
* RETURNS
*  
*****************************************************************************/
#if (defined (__MMI_MRE_APP_YAHOOMV1__) || defined(__MMI_MRE_APP_YAHOOMV2__))
extern const __align(4) U8 mre_app_yahoo_messengerv1[];
#endif

#ifdef __MMI_MRE_APP_OPERA__
extern const __align(4) U8 mre_app_opera_vxp[];
#endif

MMI_BOOL mmi_am_is_need_to_set_shortcut(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *app_path;
    U16 yahoo_app_path[MMI_AM_MAX_APP_FILE_PATH];
    U16 opera_app_path[MMI_AM_MAX_APP_FILE_PATH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_am_ms_is_rom_app(idx))
    {
        app_path = mmi_am_ms_get_app_path_by_index(idx);

        memset(yahoo_app_path, 0, sizeof(yahoo_app_path));
        memset(opera_app_path, 0, sizeof(opera_app_path));
#if (defined (__MMI_MRE_APP_YAHOOMV1__) || defined(__MMI_MRE_APP_YAHOOMV2__))
        /* build yahoo rom app path */
        kal_wsprintf(
            (WCHAR*) yahoo_app_path,
            "%c:\\%s\\%u.rom",
            MMI_AM_ROM_DIR,
            MMI_AM_MRE_HOME_DIR,
            mre_app_yahoo_messengerv1);
#endif
#ifdef __MMI_MRE_APP_OPERA__
        /* build opera rom app path */
        kal_wsprintf(
            (WCHAR*) opera_app_path,
            "%c:\\%s\\%u.rom",
            MMI_AM_ROM_DIR,
            MMI_AM_MRE_HOME_DIR,
            mre_app_opera_vxp);
#else
#endif

        if (app_path && (mmi_wcscmp(app_path, yahoo_app_path) == 0 || mmi_wcscmp(app_path, opera_app_path) == 0))
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}
#endif
/**********/


#endif /* __MRE_APP_LAUNCH__ */ 

