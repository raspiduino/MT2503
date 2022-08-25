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
*   tst_fw_pluto.c
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   3rd Party Integration Development Environment
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#include "mmi_features.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __MAUI_SDK_TEST__

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

/* NON SDK API */
#include "gui_data_types.h"
#include "CommonScreens.h"
#include "SettingDefs.h"
#include "Gui_Themes.h"
#include "sst_sla.h"
#include "med_utility.h"

/* internal */
#include "mmi_rp_app_sdk_test_def.h"
#include "TimerEvents.h"
#include "AppMgrSrvGprot.h"
#include "AppMgrSrvGprot.h"

#ifndef __SRV_APPMGR_UT__ 
mmi_ret srv_appmgr_test_1_proc (mmi_event_struct *param)
{
    return MMI_RET_OK;
}

mmi_ret srv_appmgr_test_2_proc (mmi_event_struct *param)
{
    return MMI_RET_OK;
}

mmi_ret srv_appmgr_test_3_proc (mmi_event_struct *param)
{
    return MMI_RET_OK;
}


MMI_ID srv_appmgr_test_1_launch (void* param, U32 param_size)
{
    MMI_ID group_id;

    group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, srv_appmgr_test_1_proc, NULL);
    mmi_frm_group_enter(group_id, MMI_FRM_NODE_NONE_FLAG);

    return group_id;
}

MMI_ID srv_appmgr_test_2_launch (void* param, U32 param_size)
{
    MMI_ID group_id;

    group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, srv_appmgr_test_2_proc, NULL);

    return group_id;
}

MMI_ID srv_appmgr_test_3_launch (void* param, U32 param_size)
{
    MMI_ID group_id;

    group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, srv_appmgr_test_3_proc, NULL);

    return group_id;
}

mmi_ret srv_appmgr_test_1_package_proc(mmi_event_struct *in)
{
    return MMI_RET_DONT_CARE;
}

mmi_ret srv_appmgr_test_2_package_proc(mmi_event_struct *in)
{
    return MMI_RET_DONT_CARE;
}

mmi_ret srv_appmgr_test_3_package_proc(mmi_event_struct *in)
{
    return MMI_RET_DONT_CARE;
}
 
mmi_ret srv_appmgr_test_4_package_proc(mmi_event_struct *in)
{
    return MMI_RET_DONT_CARE;
}


#else

#include "NativeAppFactorySrvGprot.h"
#include "mmi_include.h"
#include "CommonScreens.h"
#include "GlobalResDef.h"
#include "app_str.h"

#define TEST_APP3_LAUNCH_BY_FILE_CATEGORY   (MMI_LAUNCH_APP_IN_CUSTOMIZE_CATEGORY + 1)
MMI_ID test_1_id = GRP_ID_INVALID;
MMI_ID test_2_id = GRP_ID_INVALID;
MMI_ID test_3_id = GRP_ID_INVALID;
mmi_ret srv_appmgr_test_launch_cb(mmi_alert_result_evt_struct *in)
{
    MMI_ID *id = (MMI_ID *)in->user_tag;
    mmi_frm_app_config_evt_struct *evt = (mmi_frm_app_config_evt_struct*)in;
    mmi_scenario_evt_struct       *g_evt = (mmi_scenario_evt_struct*)in;
    WCHAR title[100];

    if (in->evt_id == EVT_ID_ALERT_QUIT)
    {
        mmi_alert_dismiss(*id);
        *id = GRP_ID_INVALID;
    }
    else if (in->evt_id == EVT_ID_GROUP_EXIT)
    {
        mmi_alert_dismiss(g_evt->targ_group);
    }
    else if (in->evt_id == EVT_ID_APP_CONFIG)
    {
        app_asc_str_n_to_ucs2_wcs((kal_wchar*)title, evt->string, 100);
        if (evt->index == 'S')
        {
            /* srv_appmgr_send_test */
            mmi_popup_display_simple(title, MMI_EVENT_WARNING, GRP_ID_ROOT, NULL);
            return -100;
        }
        else if (evt->index == 'P')
        {
            /* srv_appmgr_post_test */
            mmi_popup_display_simple(title, MMI_EVENT_WARNING, GRP_ID_ROOT, NULL);
            /* Should not launch test_3 */
            MMI_ASSERT(test_3_id != GRP_ID_INVALID);
            srv_appmgr_close_app(test_1_id);
            srv_appmgr_close_app(test_2_id);
            srv_appmgr_close_app(test_3_id);
        }
        else if (evt->index == 'C')
        {
            /* srv_appmgr_config_test */
            mmi_popup_display_simple(title, MMI_EVENT_WARNING, GRP_ID_ROOT, NULL);
            srv_appmgr_close_app(test_1_id);
            srv_appmgr_close_app(test_2_id);
        }
    }
    return MMI_RET_OK;
}

MMI_ID srv_appmgr_test_1_launch (void* param, U32 param_size)
{
    mmi_confirm_property_struct arg;
//    test_1_id = 0xFFFFFFFF;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func) srv_appmgr_test_launch_cb;
    arg.user_tag = (void*)(&test_1_id);
    arg.f_enter_history = MMI_TRUE;
    arg.parent_id = GRP_ID_ROOT;
    test_1_id = mmi_confirm_display((WCHAR*) L"Launch TEST_1", MMI_EVENT_QUERY, &arg);

    return test_1_id;
}
/*-tongzhibo add start 2011-03-05 -*/

void  srv_appmgr_test_2_launch_display_screen(void)
{
//    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_move_text_cursor(5, 75); 
    gui_print_bordered_text((UI_string_type) L"backlight mode:");    
}
void goback_previous_screen(void)
{
    GoBackHistory();
}

void test_2(void)
{
#if defined(__MAUI_SDK_TEST__)&& defined(__MAUI_SDK_11A__)

    ShowCategory227Screen(NULL, 0, STR_ID_VS_MM_PASS, 0, STR_ID_VS_MM_FAIL, 0, srv_appmgr_test_2_launch_display_screen, NULL);

    SetLeftSoftkeyFunction(goback_previous_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(goback_previous_screen, KEY_EVENT_UP);
/*    
    SetKeyHandler(vs_dev_gpio_set_device_level_volume_add,        KEY_UP_ARROW,   KEY_EVENT_UP);
    SetKeyHandler(vs_dev_gpio_set_device_level_volume_sub,        KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_dev_gpio_set_device_level_device_add,      KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(vs_dev_gpio_set_device_level_device_sub,      KEY_RIGHT_ARROW,KEY_EVENT_UP);  
*/    
#endif
}


/*-tongzhibo add end 2011-03-05 -*/
MMI_ID srv_appmgr_test_2_launch (void* param, U32 param_size)
{
    mmi_confirm_property_struct arg;
    mmi_app_launch_param_struct *launch_evt = (mmi_app_launch_param_struct*)param;
    WCHAR *pFile;
    MMI_BOOL ret = MMI_FALSE;
#if defined(__MAUI_SDK_TEST__)&& defined(__MAUI_SDK_11A__)
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNOCANCEL);
    arg.callback = (mmi_proc_func) srv_appmgr_test_launch_cb;
    arg.user_tag = (void*)(&test_2_id);
    arg.f_enter_history = MMI_TRUE;
    arg.parent_id = GRP_ID_ROOT;
    if (param == NULL && param_size == 0)
    {
        /* launch the application directly */
        //  test_2_id = mmi_confirm_display((WCHAR*) L"Launch TEST_2 Directly", MMI_EVENT_SUCCESS, &arg);
        if(!mmi_frm_group_is_present(GRP_ID_TEST_2))
        {
//            ret = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_TEST_2, srv_appmgr_test_2_package_proc, NULL);
//            ret += mmi_frm_group_enter(GRP_ID_TEST_2, MMI_FRM_NODE_SMART_CLOSE_FLAG);
//            mmi_frm_scrn_enter(GRP_ID_TEST_2, SCR_ID_VS_FW_PLUTO_APPMNG_TEST_2, test_2, NULL, MMI_FRM_FULL_SCRN);
            mmi_confirm_display((WCHAR*) L"Launch TEST_2 Directly", MMI_EVENT_SUCCESS, &arg);
            test_2_id = GRP_ID_TEST_2;
            return test_2_id;
        }
        else
        {
            test_2_id = GRP_ID_TEST_2;
            return test_2_id;
        }
        if( MMI_TRUE == ret )
        {
            return test_2_id;
        }
        else
        {
            return GRP_ID_INVALID;
        }
    }
    else
    {
        if (launch_evt->cat == MMI_LAUNCH_APP_IN_OPEN_CATEGORY)
        {
            /* launch the application with the file */
            pFile = (WCHAR*)launch_evt->param;
            test_2_id = mmi_confirm_display((WCHAR*)pFile, MMI_EVENT_SUCCESS, &arg);
        }
        else
        {
            test_2_id = mmi_confirm_display((WCHAR*) L"ERROR!! Launch TEST_2 Failed", MMI_EVENT_FAILURE, &arg);
        }
    }
#endif
    return test_2_id;
}

MMI_ID srv_appmgr_test_3_launch (void* param, U32 param_size)
{
    mmi_confirm_property_struct arg;
    mmi_app_launch_param_struct *launch_evt = (mmi_app_launch_param_struct*)param;
    WCHAR *pFile;
//    test_3_id = 0xFFFFFFF0;

    mmi_confirm_property_init(&arg, CNFM_TYPE_OKCANCEL);
    arg.callback = (mmi_proc_func) srv_appmgr_test_launch_cb;
    arg.user_tag = (void*)(&test_3_id);
    arg.f_enter_history = MMI_TRUE;
    arg.parent_id = GRP_ID_ROOT;
//    if (param == NULL && param_size == 0)
    {
        /* launch the application directly */
        test_3_id = mmi_confirm_display((WCHAR*) L"Launch TEST_3 Directly", MMI_EVENT_INFO, &arg);
    }
/*
    else
    {

        if (launch_evt->cat == TEST_APP3_LAUNCH_BY_FILE_CATEGORY)
        {
            // launch the application with the file 
            pFile = (WCHAR*)launch_evt->param;
            test_3_id = mmi_confirm_display((WCHAR*)pFile, MMI_EVENT_INFO, &arg);
        }
        else
        {
            test_3_id = mmi_confirm_display((WCHAR*) L"ERROR!! Launch TEST_3 Failed", MMI_EVENT_FAILURE, &arg);
        }
    }
*/
    return test_3_id;
}




mmi_ret srv_appmgr_test_1_package_proc(mmi_event_struct *in)
{
    switch (in->evt_id)
    {
    case EVT_ID_APP_CONFIG:
        {
            return  MMI_RET_DONT_CARE;
        }
        break;
    case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_NAME:
        {
            /* return the application name string. (should according the current language setting) */
            /* The application prepare the application name by itself
            srv_nativeappfactory_query_app_name_evt_struct *evt = (srv_nativeappfactory_query_app_name_evt_struct*)in;
            mmi_wcsncpy((*evt).app_string, (const WCHAR*)L"appmgr_test_2", MMI_APP_NAME_MAX_LEN);
            return MMI_RET_OK;
            */
            
            /* Use application .res setting */
            return MMI_RET_DONT_CARE;
        }
        break;
        
    case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_IMAGE:
        {
            /* return the application image icon. res_id or file path */
            /* The application prepare the application image by itself
            srv_nativeappfactory_query_app_image_evt_struct *evt = (srv_nativeappfactory_query_app_image_evt_struct*)in;
            (*evt).app_img.type = MMI_IMAGE_SRC_TYPE_RES_ID;
            (*evt).app_img.data.res_id = IMG_ID_APP_XXX;
            return MMI_RET_OK;
            */

            /* Use application .res setting */
            return MMI_RET_DONT_CARE;
        }
        break;

    case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_INFO:
        {
            /* return the application name & image The application prepare the application info. by itself
            srv_nativeappfactory_query_app_info_evt_struct *evt = (srv_nativeappfactory_query_app_info_evt_struct*)in;...
            return MMI_RET_OK;
        */

            /* Use application .res setting */
            return MMI_RET_DONT_CARE;
        }
        break;
    case EVT_ID_SRV_NATIVEAPPFACTORY_LAUNCH_APP:
        {
            /* The application prepare the application image by itselfreturn (mmi_ret)vapp_hello_world_launch();*/
            /* Use application .res setting */
            return MMI_RET_DONT_CARE;
        }
        break;
    default:
        /* do nothing */
        return MMI_RET_DONT_CARE;
    }
    return MMI_RET_OK;
}


mmi_ret srv_appmgr_test_2_package_proc(mmi_event_struct *in)
{
    mmi_confirm_property_struct arg;

    switch (in->evt_id)
    {
    case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_NAME:
        {
            /* return the application name string. (should according the current language setting) */
            /* The application prepare the application name by itself
            srv_nativeappfactory_query_app_name_evt_struct *evt = (srv_nativeappfactory_query_app_name_evt_struct*)in;
            mmi_wcsncpy(in->app_string, L"appmgr_test_2", MMI_APP_NAME_MAX_LEN);
            return MMI_RET_OK;
            */
            /* Use application .res setting */
            return MMI_RET_DONT_CARE;
        }
        break;
        
    case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_IMAGE:
        {
            /* return the application image icon. res_id or file path */
            /* The application prepare the application image by itself
            srv_nativeappfactory_query_app_image_evt_struct *evt = (srv_nativeappfactory_query_app_image_evt_struct*)in;
            (*evt).app_img.type = MMI_IMAGE_SRC_TYPE_RES_ID;
            (*evt).app_img.data.res_id = IMG_GLOBAL_SUCCESS;
            return MMI_RET_OK;
            */
            /* Use application .res setting */
            return MMI_RET_DONT_CARE;
        }
        break;

    case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_INFO:
        {
            /* return the application name & image */
            /* The application prepare the application info. by itself
            srv_nativeappfactory_query_app_info_evt_struct *evt = (srv_nativeappfactory_query_app_info_evt_struct*)in;
            ...
            return MMI_RET_OK;
            */

            /* Use application .res setting */
            return MMI_RET_DONT_CARE;
        }
        break;
    case EVT_ID_SRV_NATIVEAPPFACTORY_LAUNCH_APP:
        {
            srv_nativeappfactory_launch_app_evt_struct *launch_evt = (srv_nativeappfactory_launch_app_evt_struct*)in;
            /* The application prepare the application image by itself */
            return srv_appmgr_test_2_launch(launch_evt->param, launch_evt->param_size);
    
            /* Use application .res setting
            return MMI_RET_DONT_CARE;
            */
        }
        break;
    case EVT_ID_APP_CONFIG:
        {
            mmi_confirm_property_init(&arg, CNFM_TYPE_OKCANCEL);
            arg.callback = (mmi_proc_func) srv_appmgr_test_launch_cb;
            arg.user_tag = (void*)(&test_2_id);
            arg.f_enter_history = MMI_TRUE;
            arg.parent_id = GRP_ID_ROOT;
           
            /* launch the application directly */
//            mmi_confirm_display((WCHAR*) L"EVT_ID_APP_CONFIG SUCCESS", MMI_EVENT_INFO, &arg);
        }
        break;
    default:
        /* do nothing */
        return MMI_RET_DONT_CARE;
    }
    return MMI_RET_OK;
}

mmi_ret srv_appmgr_test_3_package_proc(mmi_event_struct *in)
{
    switch (in->evt_id)
    {
    case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_NAME:
        {
            /* return the application name string. (should according the current language setting) */
            /* The application prepare the application name by itself
            srv_nativeappfactory_query_app_name_evt_struct *evt = (srv_nativeappfactory_query_app_name_evt_struct*)in;
            mmi_wcsncpy(in->app_string, L"appmgr_test_2", MMI_APP_NAME_MAX_LEN);
            return MMI_RET_OK;
            */
            /* Use application .res setting */
            return MMI_RET_DONT_CARE;
        }
        break;
        
    case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_IMAGE:
        {
            /* return the application image icon. res_id or file path The application prepare the application image by itself */
            srv_nativeappfactory_query_app_image_evt_struct *evt = (srv_nativeappfactory_query_app_image_evt_struct*)in;
            (*evt).app_img.type = MMI_IMAGE_SRC_TYPE_RES_ID;
            (*evt).app_img.data.res_id = IMG_GLOBAL_SUCCESS;
            return MMI_RET_OK;
            /* Use application .res setting return MMI_RET_DONT_CARE;*/
        }
        break;

    case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_INFO:
        {
            /* return the application name & image The application prepare the application info. by itself */
            srv_nativeappfactory_query_app_info_evt_struct *evt = (srv_nativeappfactory_query_app_info_evt_struct*)in;
            mmi_wcsncpy((*evt).app_string, (const WCHAR *)get_string(STR_GLOBAL_FILE_ALREADY_EXISTS), MMI_APP_NAME_MAX_LEN);
            (*evt).app_img.type = MMI_IMAGE_SRC_TYPE_RES_ID;
            (*evt).app_img.data.res_id = IMG_GLOBAL_SUCCESS;
            return MMI_RET_OK;
            /* Use application .res setting return MMI_RET_DONT_CARE;*/
        }
        break;
    case EVT_ID_SRV_NATIVEAPPFACTORY_LAUNCH_APP:
        {
            /* The application prepare the application image by itself return (mmi_ret)vapp_hello_world_launch();*/
            /* Use application .res setting */
            return MMI_RET_DONT_CARE;
        }
        break;
    default:
        /* do nothing */
        return MMI_RET_DONT_CARE;
    }
    return MMI_RET_OK;
}
 
mmi_ret srv_appmgr_test_4_package_proc(mmi_event_struct *in)
{
    mmi_ret gid = 0;
    switch (in->evt_id)
    {
    case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_NAME:
        {
            /* return the application name string. (should according the current language setting) */
            /* The application prepare the application name by itself */
            srv_nativeappfactory_query_app_name_evt_struct *evt = (srv_nativeappfactory_query_app_name_evt_struct*)in;
            mmi_wcsncpy((*evt).app_string, (const WCHAR*)L"APPMGR_test_4", MMI_APP_NAME_MAX_LEN);
            return MMI_RET_OK;
            /* Use application .res setting return MMI_RET_DONT_CARE;*/
        }
        break;
        
    case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_IMAGE:
        {
            /* return the application image icon. res_id or file path The application prepare the application image by itself */
            srv_nativeappfactory_query_app_image_evt_struct *evt = (srv_nativeappfactory_query_app_image_evt_struct*)in;
            (*evt).app_img.type = MMI_IMAGE_SRC_TYPE_RES_ID;
            (*evt).app_img.data.res_id = IMG_GLOBAL_QUESTION;
            return MMI_RET_OK;
            /* Use application .res setting return MMI_RET_DONT_CARE;*/
        }
        break;

    case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_INFO:
        {
            /* return the application name & image */
            /* The application prepare the application info. by itself */
            srv_nativeappfactory_query_app_info_evt_struct *evt = (srv_nativeappfactory_query_app_info_evt_struct*)in;
            mmi_wcsncpy((*evt).app_string, (const WCHAR*)L"APPMGR_test_4", MMI_APP_NAME_MAX_LEN);
            (*evt).app_img.type = MMI_IMAGE_SRC_TYPE_RES_ID;
            (*evt).app_img.data.res_id = IMG_GLOBAL_QUESTION;
            return MMI_RET_OK;
            /* Use application .res setting return MMI_RET_DONT_CARE;*/
        }
        break;
    case EVT_ID_SRV_NATIVEAPPFACTORY_LAUNCH_APP:
        {
            /* The application prepare the application image by itself */
/*            
            gid = (mmi_ret)vapp_hello_world_launch();
            gid = 0x0000FFFF & gid;
            return gid;
*/            
            /* Use application .res setting return MMI_RET_DONT_CARE;*/
        }
        break;
    default:
        /* do nothing */
        return MMI_RET_DONT_CARE;
    }
    return MMI_RET_OK;
}


MMI_BOOL srv_appmgr_package_list_query_test(void)
{
    U32 app_num = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE);
    mmi_app_package_name_struct name[100];

    MMI_ASSERT(srv_appmgr_get_app_package_list(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE, name, 100) == MMI_RET_OK);
    app_num = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);
    MMI_ASSERT(srv_appmgr_get_app_package_list(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE, name, 100) == MMI_RET_OK);
    app_num = srv_appmgr_get_app_package_num(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    MMI_ASSERT(srv_appmgr_get_app_package_list(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE, name, 100) == MMI_RET_OK);

    return MMI_TRUE;
}

MMI_BOOL srv_appmgr_native_app1_query_test(void)
{
    WCHAR app_name[MMI_APP_NAME_MAX_LEN+1];
    mmi_image_src_struct app_img;
    srv_app_info_struct app_info;

    MMI_ASSERT(srv_appmgr_get_app_package_name("native.mtk.appmgr_test_1", app_name) == MMI_RET_OK);
    MMI_ASSERT(srv_appmgr_get_app_package_image("native.mtk.appmgr_test_1", &app_img) == MMI_RET_OK);
    MMI_ASSERT(srv_appmgr_get_app_package_info("native.mtk.appmgr_test_1", &app_info) == MMI_RET_OK);
    MMI_ASSERT(SRV_APPMGR_NATIVE_APP_PACKAGE_TYPE == srv_appmgr_get_app_package_type("native.mtk.appmgr_test_1"));

    return MMI_TRUE;
}

MMI_BOOL srv_appmgr_native_app2_query_test(void)
{
    WCHAR app_name[MMI_APP_NAME_MAX_LEN+1];
    mmi_image_src_struct app_img;
    srv_app_info_struct app_info;

    MMI_ASSERT(srv_appmgr_get_app_package_name("native.mtk.appmgr_test_2", app_name) == MMI_RET_OK);
    MMI_ASSERT(srv_appmgr_get_app_package_image("native.mtk.appmgr_test_2", &app_img) == MMI_RET_OK);
    MMI_ASSERT(srv_appmgr_get_app_package_info("native.mtk.appmgr_test_2", &app_info) == MMI_RET_OK);
    MMI_ASSERT(SRV_APPMGR_NATIVE_APP_PACKAGE_TYPE == srv_appmgr_get_app_package_type("native.mtk.appmgr_test_2"));

    return MMI_TRUE;
}

MMI_BOOL srv_appmgr_native_app3_query_test(void)
{
    WCHAR app_name[MMI_APP_NAME_MAX_LEN+1];
    mmi_image_src_struct app_img;
    srv_app_info_struct app_info;

    MMI_ASSERT(srv_appmgr_get_app_package_name("native.mtk.appmgr_test_3", app_name) == MMI_RET_OK);
    MMI_ASSERT(srv_appmgr_get_app_package_image("native.mtk.appmgr_test_3", &app_img) == MMI_RET_OK);
    MMI_ASSERT(srv_appmgr_get_app_package_info("native.mtk.appmgr_test_3", &app_info) == MMI_RET_OK);
    MMI_ASSERT(SRV_APPMGR_NATIVE_APP_PACKAGE_TYPE == srv_appmgr_get_app_package_type("native.mtk.appmgr_test_3"));

    return MMI_TRUE;
}

MMI_BOOL srv_appmgr_native_app4_query_test(void)
{
    WCHAR app_name[MMI_APP_NAME_MAX_LEN+1];
    mmi_image_src_struct app_img;
    srv_app_info_struct app_info;

    MMI_ASSERT(srv_appmgr_get_app_package_name("native.mtk.appmgr_test_4", app_name) == MMI_RET_OK);
    MMI_ASSERT(srv_appmgr_get_app_package_image("native.mtk.appmgr_test_4", &app_img) == MMI_RET_OK);
    MMI_ASSERT(srv_appmgr_get_app_package_info("native.mtk.appmgr_test_4", &app_info) == MMI_RET_OK);
    MMI_ASSERT(SRV_APPMGR_NATIVE_APP_PACKAGE_TYPE == srv_appmgr_get_app_package_type("native.mtk.appmgr_test_4"));

    return MMI_TRUE;
}


MMI_BOOL srv_appmgr_launch_test(void)
{
    mmi_app_launch_param_struct app_3_param = {0};
    
    MMI_ASSERT(GRP_ID_INVALID != srv_appmgr_launch("native.mtk.appmgr_test_1"));
    app_3_param.cat = TEST_APP3_LAUNCH_BY_FILE_CATEGORY;
    app_3_param.param = (void*)L"z://a.jpg";
    MMI_ASSERT(GRP_ID_INVALID != srv_appmgr_launch_ex("native.mtk.appmgr_test_3", (void*)&app_3_param, 0));
    MMI_ASSERT(MMI_TRUE == srv_appmgr_is_app_package_running("native.mtk.appmgr_test_1"));
    MMI_ASSERT(MMI_FALSE == srv_appmgr_is_app_package_running("native.mtk.appmgr_test_2"));
    MMI_ASSERT(MMI_TRUE == srv_appmgr_is_app_package_running("native.mtk.appmgr_test_3"));
    return MMI_TRUE;
}

MMI_BOOL srv_appmgr_running_query_test(void)
{
    U32 num = srv_appmgr_get_running_app_num(SRV_APPMGR_RUNNING_APP_FLAG_TYPE);
    mmi_app_package_name_struct name[10];
    
    MMI_ASSERT(srv_appmgr_get_running_app_list(SRV_APPMGR_RUNNING_APP_FLAG_TYPE, name, 10) == MMI_RET_OK);
    MMI_ASSERT(srv_appmgr_get_running_app_list(SRV_APPMGR_BG_RUNNING_APP_FLAG_TYPE, name, 10) == MMI_RET_OK);
    return MMI_TRUE;
}

MMI_BOOL srv_appmgr_running_query_instance_test(void)
{
    U32 num = srv_appmgr_get_running_app_num(SRV_APPMGR_RUNNING_APP_FLAG_TYPE);
    MMI_ID instance_id[10];
    
    MMI_ASSERT(srv_appmgr_query_instance_num("native.mtk.appmgr_test_1") == 1);
    MMI_ASSERT(srv_appmgr_query_instance_num("native.mtk.appmgr_test_2") == 0);
    MMI_ASSERT(srv_appmgr_query_instance_id("native.mtk.appmgr_test_1", instance_id, 10) == MMI_RET_OK);
    return MMI_TRUE;
}

MMI_BOOL srv_appmgr_close_app_test(void)
{
    U32 num = srv_appmgr_get_running_app_num(SRV_APPMGR_RUNNING_APP_FLAG_TYPE);
    U32 i = 0;
    MMI_ID instance_id[10];

    MMI_ASSERT(srv_appmgr_query_instance_id("native.mtk.appmgr_test_1", instance_id, 10) == MMI_RET_OK);
    for (i = 0; i < num; i++)
    {
        srv_appmgr_close_app(instance_id[i]);
    }
    MMI_ASSERT(srv_appmgr_query_instance_id("native.mtk.appmgr_test_3", instance_id, 10) == MMI_RET_OK);
    for (i = 0; i < num; i++)
    {
        srv_appmgr_close_app(instance_id[i]);
    }
    MMI_ASSERT(MMI_FALSE == srv_appmgr_is_app_package_running("native.mtk.appmgr_test_1"));
    return MMI_TRUE;
}

MMI_BOOL srv_appmgr_send_test(void)
{
    MMI_ID test_id1, test_id2;

    mmi_app_launch_param_struct  app_2_param = {0};
    mmi_frm_app_config_evt_struct       evt = {0};
    mmi_ret ret = MMI_RET_ERR;
    
    /* launch the applications first */
    test_id1 = srv_appmgr_launch("native.mtk.appmgr_test_1");
    app_2_param.cat = MMI_LAUNCH_APP_IN_OPEN_CATEGORY;
    app_2_param.param = (void*)L"z://Send_test.jpg";
    test_id2 = srv_appmgr_launch_ex("native.mtk.appmgr_test_2", (void*)&app_2_param, 0);

    /* send the event between the applications */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_APP_CONFIG);
    evt.index = (U8)'S';
    strcpy(evt.string, "Send: test_2->test_1");
    srv_appmgr_send_evt(test_id2, test_id1, (mmi_event_struct*)&evt);
    srv_appmgr_close_app(test_id1);
    srv_appmgr_close_app(test_id2);
    return MMI_TRUE;
}

MMI_BOOL srv_appmgr_post_test(void)
{
    MMI_ID test_id1, test_id2, test_id3;

    mmi_app_launch_param_struct  app_2_param = {0};
    mmi_frm_app_config_evt_struct       evt = {0};
    mmi_ret ret = MMI_RET_ERR;
    
    /* launch the applications first */
    test_id1 = srv_appmgr_launch("native.mtk.appmgr_test_1");
    app_2_param.cat = MMI_LAUNCH_APP_IN_OPEN_CATEGORY;
    app_2_param.param = (void*)L"z://Post_test.gif";
    test_id2 = srv_appmgr_launch_ex("native.mtk.appmgr_test_2", (void*)&app_2_param, 0);

    /* send the event between the applications */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_APP_CONFIG);
    evt.index = (U8)'P';
    strcpy(evt.string, "Post: test_2->test_1");
    srv_appmgr_post_evt(test_id2, test_id1, (mmi_event_struct*)&evt);
    test_id3 = srv_appmgr_launch("native.mtk.appmgr_test_3");
    return MMI_TRUE;
}

MMI_BOOL srv_appmgr_config_test(void)
{
    MMI_ID test_id1, test_id2;

    mmi_app_launch_param_struct  app_2_param = {0};
    mmi_frm_app_config_evt_struct       evt = {0};
    mmi_ret ret = MMI_RET_ERR;
    
    /* launch the applications first */
    test_id1 = srv_appmgr_launch("native.mtk.appmgr_test_1");
    app_2_param.cat = MMI_LAUNCH_APP_IN_OPEN_CATEGORY;
    app_2_param.param = (void*)L"z://Config_test.txt";
    test_id2 = srv_appmgr_launch_ex("native.mtk.appmgr_test_2", (void*)&app_2_param, 0);
    
    /* test config string and index */
    srv_appmgr_config(test_id2, "Config test", (U8)'C');
    return MMI_TRUE;
}

typedef MMI_BOOL (*srv_appmgr_test_case_fp)(void);
typedef struct
{
    S8 index;
    srv_appmgr_test_case_fp test_case_func;
} srv_appmgr_test_case_struct;

static const srv_appmgr_test_case_struct srv_appmgr_test_case_db[] =
{
    /* Test all cases */
    {0,     NULL},
    {1,     srv_appmgr_package_list_query_test},
    {2,     srv_appmgr_native_app1_query_test},
    {3,     srv_appmgr_native_app2_query_test},
    {4,     srv_appmgr_native_app3_query_test},
    {5,     srv_appmgr_native_app4_query_test},
    {6,     srv_appmgr_launch_test},
    {7,     srv_appmgr_running_query_test},
    {8,     srv_appmgr_running_query_instance_test},
    {9,     srv_appmgr_close_app_test},
    {10,    srv_appmgr_send_test},
    {11,    srv_appmgr_post_test},
    {12,    srv_appmgr_config_test},
    {-1,    NULL}
};

void mmi_srv_appmgr_test_case_expiry(void* arg)
{
    static U8 __i;

    if (arg == (void*)1)
    {
        __i = 1;
    }
    if (srv_appmgr_test_case_db[__i].index > 0 && srv_appmgr_test_case_db[__i].test_case_func)
    {
        srv_appmgr_test_case_db[__i].test_case_func();
        gui_start_timer_ex(100, mmi_srv_appmgr_test_case_expiry, (void*)2);
        __i++;
    }
    else
    {
        __i = 0;
    }
}


#endif /* __SRV_APPMGR_UT__ */

/* declaration */ 
/*
U32 srv_appmgr_get_app_package_num(srv_appmgr_flag_type flag);
mmi_ret srv_appmgr_get_app_package_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array, U32 num);
*/
#ifndef TEST_APP3_LAUNCH_BY_FILE_CATEGORY
#define TEST_APP3_LAUNCH_BY_FILE_CATEGORY   (MMI_LAUNCH_APP_IN_CUSTOMIZE_CATEGORY + 1)
#endif
    /*********************/
    extern U32 srv_appmgr_get_app_package_num(srv_appmgr_flag_type flag);
    extern mmi_ret srv_appmgr_get_app_package_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array, U32 num);
    extern mmi_ret srv_appmgr_get_app_package_name(const mmi_app_package_char *app_name, WCHAR *string);
    extern mmi_ret srv_appmgr_get_app_package_image(const mmi_app_package_char *app_name, mmi_image_src_struct *image);
    extern mmi_ret srv_appmgr_get_app_package_info(const mmi_app_package_char *app_name, srv_app_info_struct *info);

    extern srv_appmgr_app_package_type_enum srv_appmgr_get_app_package_type(const mmi_app_package_char *app_name);
    extern MMI_BOOL srv_appmgr_is_app_package_running(const mmi_app_package_char *app_name);
    extern MMI_ID srv_appmgr_launch(const mmi_app_package_char *app_name);
    extern MMI_ID srv_appmgr_launch_ex(const mmi_app_package_char *app_name, mmi_app_launch_param_struct* param, U32 param_size);
    extern U32 srv_appmgr_get_running_app_num(srv_appmgr_flag_type flag);

    extern mmi_ret srv_appmgr_get_running_app_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array, U32 num);
    extern U32 srv_appmgr_query_instance_num(const mmi_app_package_char *app_name);
    extern MMI_ID srv_appmgr_query_instance_single_id(const mmi_app_package_char *app_name);
    extern mmi_ret srv_appmgr_query_instance_id(const mmi_app_package_char *app_name, MMI_ID *instance_id_array, U32 num);
    extern void srv_appmgr_close_app(MMI_ID app_instance_id);

    extern void srv_appmgr_config(MMI_ID app_instance_id, CHAR* inject_string, U8 inject_index);
    extern mmi_ret srv_appmgr_send_evt(MMI_ID sender_app_instance_id, MMI_ID rec_app_instance_id, mmi_event_struct *evt);
    extern void srv_appmgr_post_evt(MMI_ID sender_app_instance_id, MMI_ID rec_app_instance_id, mmi_event_struct *evt);
    extern void srv_appmgr_post_evt_ex(MMI_ID sender_app_instance_id, MMI_ID rec_app_instance_id, mmi_event_struct *evt);
    /*********************/

    /* defination */
#ifdef __MAUI_SOFTWARE_LA__

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
/* under construction !*/
#endif

    // U32 srv_appmgr_get_app_package_num(srv_appmgr_flag_type flag);    
    void srv_appmgr_performance_profiling_entry_scr(void)   // VS_TA_FW_PLUTO_APPMGR_0
    {
        U32 app_num =1000000;
        mmi_ret retVal = MMI_RET_ERR;
        mmi_app_package_name_struct name[50];
        WCHAR app_name[MMI_APP_NAME_MAX_LEN+1];
        mmi_image_src_struct app_img ;
        U32 i;
        MMI_BOOL b_native = MMI_FALSE;
        MMI_BOOL b_java = MMI_FALSE;
        MMI_BOOL b_mre = MMI_FALSE;
        MMI_BOOL b_widget = MMI_FALSE;
        
        app_num =  srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE);
        retVal = srv_appmgr_get_app_package_list(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE, name, 50);

        for (i = 0; i < app_num; i ++)
        {
            if (0 == strncmp(name[i], "mre", 3) && !b_mre)
            {
                srv_appmgr_get_app_package_name(name[i], app_name);
                srv_appmgr_get_app_package_image(name[i], &app_img);
                b_mre = MMI_TRUE;
                break;
            }
        }

        for (i = 0; i < app_num; i ++)
        {
            if (0 == strncmp(name[i], "java", 4) && !b_java)
            {
                srv_appmgr_get_app_package_name(name[i], app_name);
                srv_appmgr_get_app_package_image(name[i], &app_img);
                b_java = MMI_TRUE;
                break;
            }
        }

        for (i = 0; i < app_num; i ++)
        {
            if (0 == strncmp(name[i], "widget", 6) && !b_widget)
            {
                srv_appmgr_get_app_package_name(name[i], app_name);
                srv_appmgr_get_app_package_image(name[i], &app_img);
                b_widget = MMI_TRUE;
                break;
            }
        }

        for (i = 0; i < app_num; i ++)
        {
            if (0 == strncmp(name[i], "native", 6) && !b_native)
            {
                srv_appmgr_get_app_package_name(name[i], app_name);
                srv_appmgr_get_app_package_image(name[i], &app_img);
                b_native = MMI_TRUE;
                break;
            }
        }
        
		AVK_CASE_RESULT(AVK_PASS);    
    }
#endif /* __MAUI_SOFTWARE_LA__ */

    // U32 srv_appmgr_get_app_package_num(srv_appmgr_flag_type flag);    
    void srv_appmgr_get_app_package_num_entry_scr(void)   // VS_TA_FW_PLUTO_APPMGR_0
    {
        U32 app_num =1000000;
        app_num =  srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE);
	    AVK_LOG_FUN(srv_appmgr_get_app_package_num,AVK_PASS);
        
        if (1000000 != app_num)
        {
		    AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
		    AVK_CASE_RESULT(AVK_FAIL);
        }    
    }

    //  mmi_ret srv_appmgr_get_app_package_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array, U32 num);
    void   srv_appmgr_get_app_package_list_entry_scr(void)  // VS_TA_FW_PLUTO_APPMGR_1
    {
        mmi_ret retVal = MMI_RET_ERR;
        mmi_app_package_name_struct name[50];
        retVal = srv_appmgr_get_app_package_list(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE, name, 50);
	    AVK_LOG_FUN(srv_appmgr_get_app_package_list,AVK_PASS);
        
        if ( MMI_RET_OK == retVal )
        {
		    AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
		    AVK_CASE_RESULT(AVK_FAIL);
        }        
    }    

    // mmi_ret srv_appmgr_get_app_package_name(const mmi_app_package_char *app_name, WCHAR *string)
    void   srv_appmgr_get_app_package_name_entry_scr(void)   // VS_TA_FW_PLUTO_APPMGR_2
    {
        WCHAR app_name[MMI_APP_NAME_MAX_LEN+1];
        mmi_ret retVal = MMI_RET_ERR;
        retVal = srv_appmgr_get_app_package_name("native.mtk.appmgr_test_1", app_name);
	    AVK_LOG_FUN(srv_appmgr_get_app_package_name,AVK_PASS);
        
        if ( MMI_RET_OK == retVal )
        {
		    AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
        	AVK_CASE_RESULT(AVK_FAIL);
        }            
    }    

    // mmi_ret srv_appmgr_get_app_package_image(const mmi_app_package_char *app_name, mmi_image_src_struct *image)
    void   srv_appmgr_get_app_package_image_entry_scr(void)  // VS_TA_FW_PLUTO_APPMGR_3
    {
        mmi_image_src_struct app_img ;
        mmi_ret retVal = MMI_RET_ERR;
        retVal = srv_appmgr_get_app_package_image("native.mtk.appmgr_test_1", &app_img);
	    AVK_LOG_FUN(srv_appmgr_get_app_package_image,AVK_PASS);
     
        if ( MMI_RET_OK == retVal )
        {
		    AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
        	AVK_CASE_RESULT(AVK_FAIL);
        }            
    }

    // mmi_ret srv_appmgr_get_app_package_info(const mmi_app_package_char *app_name, srv_app_info_struct *info)
    void   srv_appmgr_get_app_package_info_entry_scr(void)       // VS_TA_FW_PLUTO_APPMGR_4
    {
        srv_app_info_struct app_info;
        mmi_ret retVal = MMI_RET_ERR;
        retVal = srv_appmgr_get_app_package_info("native.mtk.appmgr_test_1", &app_info);
	    AVK_LOG_FUN(srv_appmgr_get_app_package_info,AVK_PASS);
        
        if (MMI_RET_OK == retVal)
        {
		    AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
        	AVK_CASE_RESULT(AVK_FAIL);
        }            
    }    


    //MMI_ID srv_appmgr_launch(const mmi_app_package_char *app_name)
    void   srv_appmgr_launch_entry_scr(void)                                // VS_TA_FW_PLUTO_APPMGR_5
    {
        MMI_ID group_id;
    
        group_id = srv_appmgr_launch("native.mtk.appmgr_test_1");

        if (group_id != GRP_ID_INVALID)
        {
		    AVK_CASE_RESULT(AVK_PASS);
            srv_appmgr_close_app(group_id);
        }
        else
        {
		    AVK_CASE_RESULT(AVK_FAIL);
        }            
    }    

	
    void   srv_appmgr_launch_ex_entry_scr(void)                         // VS_TA_FW_PLUTO_APPMGR_6
    {
        MMI_ID group_id;
        mmi_app_launch_param_struct app_3_param;
        app_3_param.cat = (mmi_app_launch_category_enum)TEST_APP3_LAUNCH_BY_FILE_CATEGORY;
        app_3_param.param = (void*)L"z://a.jpg";
        group_id  = srv_appmgr_launch_ex("native.mtk.appmgr_test_3", (mmi_app_launch_param_struct*)&app_3_param, 0);
 	    AVK_LOG_FUN(srv_appmgr_launch_ex,AVK_PASS);
        
        if (group_id != GRP_ID_INVALID)
        {
		    AVK_CASE_RESULT(AVK_PASS);
            srv_appmgr_close_app(group_id);
        }
        else
        {
        	AVK_CASE_RESULT(AVK_FAIL);
        }            
    }    


    // srv_appmgr_app_package_type_enum srv_appmgr_get_app_package_type(const mmi_app_package_char *app_name)
    void   srv_appmgr_get_app_package_type_entry_scr(void)      // VS_TA_FW_PLUTO_APPMGR_7
    {
        srv_appmgr_app_package_type_enum retVal = SRV_APPMGR_UNKNOWN_APP_PACKAGE_TYPE;
        retVal = srv_appmgr_get_app_package_type("native.mtk.appmgr_test_1");
	    AVK_LOG_FUN(srv_appmgr_get_app_package_type,AVK_PASS);
        
        if (SRV_APPMGR_UNKNOWN_APP_PACKAGE_TYPE  != retVal)
        {
		    AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
		    AVK_CASE_RESULT(AVK_FAIL);
        }            
    }    


    // MMI_BOOL srv_appmgr_is_app_package_running(const mmi_app_package_char *app_name)
    void   srv_appmgr_is_app_package_running_entry_scr(void)    // VS_TA_FW_PLUTO_APPMGR_8
    {
        mmi_ret retVal;
        MMI_ID group_id;
        mmi_app_package_name_struct name[10];
        MMI_BOOL is_running = MMI_FALSE;
        U32 i;
    
        group_id = srv_appmgr_launch("native.mtk.appmgr_test_1");

        memset(name, 0, sizeof(mmi_app_package_name_struct) * 10);
        
        retVal = srv_appmgr_get_running_app_list(SRV_APPMGR_RUNNING_APP_FLAG_TYPE, name, 10);
	    AVK_LOG_FUN(srv_appmgr_get_running_app_list,AVK_PASS);

        for (i = 0; i < 10; i ++)
        {
            if (name[i][0] != 0)
            {
                if (strcmp(name[i], "Known App Package Name") == 0)
                {
                    continue;
                }

                is_running = srv_appmgr_is_app_package_running(name[i]);
                AVK_LOG_FUN(srv_appmgr_is_app_package_running,AVK_PASS);
                
                break;
            }
        }

        srv_appmgr_close_app(group_id);
        
        if (is_running)
        {
		    AVK_CASE_RESULT(AVK_PASS);          
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);
        }
    } 


    // U32 srv_appmgr_get_running_app_num(srv_appmgr_flag_type flag)
    void   srv_appmgr_get_running_app_num_entry_scr(void)       // VS_TA_FW_PLUTO_APPMGR_9
    {
        U32 num = 0;
        
        num = srv_appmgr_get_running_app_num(SRV_APPMGR_RUNNING_APP_FLAG_TYPE);
	    AVK_LOG_FUN(srv_appmgr_get_running_app_num,AVK_PASS);	
        
        if (0 != num)
        {
		    AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
		    AVK_CASE_RESULT(AVK_FAIL);
        }
    }


    //mmi_ret srv_appmgr_get_running_app_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array, U32 num)
    void   srv_appmgr_get_running_app_list_entry_scr(void)          // VS_TA_FW_PLUTO_APPMGR_10
    {
        mmi_ret retVal = MMI_RET_ERR;
        mmi_app_package_name_struct name[10];
        
        retVal = srv_appmgr_get_running_app_list(SRV_APPMGR_RUNNING_APP_FLAG_TYPE, name, 10);
	    AVK_LOG_FUN(srv_appmgr_get_running_app_list,AVK_PASS);
        
        if (MMI_RET_OK == retVal)
        {
		    AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
		    AVK_CASE_RESULT(AVK_FAIL);
        }            
    }    



    // mmi_ret srv_appmgr_query_instance_id(const mmi_app_package_char *app_name, MMI_ID *instance_id_array, U32 num)
    void   srv_appmgr_query_instance_id_entry_scr(void)             // VS_TA_FW_PLUTO_APPMGR_11
    {
        MMI_ID instance_id[10] = {0};
        mmi_ret retVal = MMI_RET_ERR;
        mmi_app_package_name_struct name[10];
        U32 i;

        memset(name, 0, sizeof(mmi_app_package_name_struct) * 10);
        
        retVal = srv_appmgr_get_running_app_list(SRV_APPMGR_RUNNING_APP_FLAG_TYPE, name, 10);
	    AVK_LOG_FUN(srv_appmgr_get_running_app_list,AVK_PASS);

        for (i = 0; i < 10; i ++)
        {
            if (name[i][0] != 0)
            {
                if (strcmp(name[i], "Known App Package Name") == 0)
                {
                    continue;
                }

                retVal = srv_appmgr_query_instance_id(name[i], instance_id, 10);
                AVK_LOG_FUN(srv_appmgr_query_instance_id,AVK_PASS);
                
                break;
            }
        }
        
        if( MMI_RET_OK == retVal )
        {
		    AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
		    AVK_CASE_RESULT(AVK_FAIL);
        }            
    }    


    // U32 srv_appmgr_query_instance_num(const mmi_app_package_char *app_name)
    void   srv_appmgr_query_instance_num_entry_scr(void)        // VS_TA_FW_PLUTO_APPMGR_12
    {
        mmi_ret retVal = MMI_RET_ERR;
        MMI_ID group_id;
        U32 instance_num = 0;
        mmi_app_package_name_struct name[10];
        U32 i;
    
        group_id = srv_appmgr_launch("native.mtk.appmgr_test_1");

        memset(name, 0, sizeof(mmi_app_package_name_struct) * 10);
        
        retVal = srv_appmgr_get_running_app_list(SRV_APPMGR_RUNNING_APP_FLAG_TYPE, name, 10);
	    AVK_LOG_FUN(srv_appmgr_get_running_app_list,AVK_PASS);

        for (i = 0; i < 10; i ++)
        {
            if (name[i][0] != 0)
            {
                if (strcmp(name[i], "Known App Package Name") == 0)
                {
                    continue;
                }

                instance_num = srv_appmgr_query_instance_num(name[i]);
                AVK_LOG_FUN(srv_appmgr_query_instance_num,AVK_PASS);
                
                break;
            }
        }

        srv_appmgr_close_app(group_id);

        if (instance_num != 0)
        {
		    AVK_CASE_RESULT(AVK_PASS);            
        }
        else
        {
            AVK_CASE_RESULT(AVK_FAIL);
        }
    } 



    void   srv_appmgr_close_app_entry_scr(void)                         // VS_TA_FW_PLUTO_APPMGR_13
    {
        MMI_ID group_id;
        MMI_BOOL is_running = MMI_FALSE;

        group_id = srv_appmgr_launch("native.mtk.appmgr_test_1");
        AVK_LOG_FUN(srv_appmgr_launch,AVK_PASS);

        srv_appmgr_close_app(group_id);
        AVK_LOG_FUN(srv_appmgr_close_app,AVK_PASS);

        is_running = srv_appmgr_is_app_package_running("native.mtk.appmgr_test_1");

        if (! is_running)
        {
		    AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
		    AVK_CASE_RESULT(AVK_FAIL);
        }            
    }    


    // srv_appmgr_post_evt_ex
    void   srv_appmgr_post_evt_ex_entry_scr(void)                  // VS_TA_FW_PLUTO_APPMGR_14
    {
        MMI_ID group_id_1, group_id_2;

        mmi_app_launch_param_struct  app_2_param ;
        mmi_frm_app_config_evt_struct evt;
        mmi_ret ret = MMI_RET_ERR;

        /* launch the applications first */
        group_id_1 = srv_appmgr_launch("native.mtk.appmgr_test_1");
    	AVK_LOG_FUN(srv_appmgr_launch,AVK_PASS);
        
        app_2_param.cat = MMI_LAUNCH_APP_IN_OPEN_CATEGORY;
        app_2_param.param = (void*)L"z://Post_test.gif";
        group_id_2 = srv_appmgr_launch_ex("native.mtk.appmgr_test_3", (mmi_app_launch_param_struct*)&app_2_param, 0);
	    AVK_LOG_FUN(srv_appmgr_launch_ex,AVK_PASS);		

        /* send the event between the applications */
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_APP_CONFIG);
        evt.index = (U8)'P';
        strcpy((char*)evt.string, "Post: test_2->test_1");

        srv_appmgr_post_evt_ex(group_id_2, group_id_1, (mmi_event_struct*)&evt);   // how to test result?
	    AVK_LOG_FUN(srv_appmgr_post_evt,AVK_PASS);

        srv_appmgr_close_app(group_id_1);
        srv_appmgr_close_app(group_id_2);

        AVK_CASE_RESULT(AVK_PASS);
    }    


    // how to test this I/F
    //srv_appmgr_config(MMI_ID app_instance_id, CHAR* inject_string, U8 inject_index);
    // only this function can be use appmgr_test_2
    void   srv_appmgr_config_entry_scr(void)                               // VS_TA_FW_PLUTO_APPMGR_15
    {
        MMI_ID group_id;
        mmi_ret retValue = (mmi_ret)MMI_FALSE;

        group_id = srv_appmgr_launch("native.mtk.appmgr_test_1");
        AVK_LOG_FUN(srv_appmgr_launch,AVK_PASS);	

        srv_appmgr_config(group_id, "tongzhibo", 1);
        srv_appmgr_close_app(group_id);

        if (1)
        {
		    AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
		    AVK_CASE_RESULT(AVK_FAIL);
        }            
    }    

    // mmi_ret srv_appmgr_send_evt(MMI_ID sender_app_instance_id, MMI_ID rec_app_instance_id, mmi_event_struct *evt)
    void   srv_appmgr_send_evt_entry_scr(void)                          // VS_TA_FW_PLUTO_APPMGR_16
    {
        MMI_ID group_id_1, group_id_2;
        mmi_app_launch_param_struct  app_2_param;
        mmi_frm_app_config_evt_struct       evt;
        mmi_ret ret = MMI_RET_ERR;

        /* launch the applications first */
        group_id_1 = srv_appmgr_launch("native.mtk.appmgr_test_1");
	    AVK_LOG_FUN(srv_appmgr_launch,AVK_PASS);
        
        app_2_param.cat = MMI_LAUNCH_APP_IN_OPEN_CATEGORY;
        app_2_param.param = (void*)L"z://Send_test.jpg";
        group_id_2 = srv_appmgr_launch_ex("native.mtk.appmgr_test_3", (mmi_app_launch_param_struct*)&app_2_param, 0);
	    AVK_LOG_FUN(srv_appmgr_launch_ex,AVK_PASS);
        
        /* send the event between the applications */
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_APP_CONFIG);
        evt.index = (U8)'S';
        strcpy((char*)evt.string, "Send: test_2->test_1");
        ret = srv_appmgr_send_evt(group_id_2, group_id_1, (mmi_event_struct*)&evt);
	    AVK_LOG_FUN(srv_appmgr_send_evt,AVK_PASS);
        
        if ( MMI_RET_OK == ret)
        {
		    AVK_CASE_RESULT(AVK_PASS);
            srv_appmgr_close_app(group_id_1);
            srv_appmgr_close_app(group_id_2);
        }
        else
        {
		    AVK_CASE_RESULT(AVK_FAIL);
        }            
    }    


    //void srv_appmgr_post_evt(MMI_ID sender_app_instance_id, MMI_ID rec_app_instance_id, mmi_event_struct *evt)
    void   srv_appmgr_post_evt_entry_scr(void)                          // VS_TA_FW_PLUTO_APPMGR_17
    {
        MMI_ID group_id_1, group_id_2;

        mmi_app_launch_param_struct  app_2_param;
        mmi_frm_app_config_evt_struct       evt = {0};
        mmi_ret ret = MMI_RET_ERR;

        /* launch the applications first */
        group_id_1 = srv_appmgr_launch("native.mtk.appmgr_test_1");
	    AVK_LOG_FUN(srv_appmgr_launch,AVK_PASS);
        
        app_2_param.cat = MMI_LAUNCH_APP_IN_OPEN_CATEGORY;
        app_2_param.param = (void*)L"z://Post_test.gif";
        group_id_2 = srv_appmgr_launch_ex("native.mtk.appmgr_test_3", (mmi_app_launch_param_struct*)&app_2_param, 0);
	    AVK_LOG_FUN(srv_appmgr_launch_ex,AVK_PASS);
        
        /* send the event between the applications */
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_APP_CONFIG);
        evt.index = (U8)'P';
        strcpy((char*)evt.string, "Post: test_2->test_1");

        srv_appmgr_post_evt(group_id_2, group_id_1, (mmi_event_struct*)&evt);   // how to test result?
	    AVK_LOG_FUN(srv_appmgr_post_evt,AVK_PASS);

        srv_appmgr_close_app(group_id_1);
        srv_appmgr_close_app(group_id_2);
        
        AVK_CASE_RESULT(AVK_PASS);
    }    


    void   srv_appmgr_update_app_info_entry_scr(void)
    {
        MMI_ID group_id;

        group_id = srv_appmgr_launch("native.mtk.appmgr_test_1");
	    AVK_LOG_FUN(srv_appmgr_launch,AVK_PASS);

        srv_appmgr_update_app_info("native.mtk.appmgr_test_1", EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE);
        AVK_LOG_FUN(srv_appmgr_update_app_info,AVK_PASS);

        srv_appmgr_close_app(group_id);
        
        AVK_CASE_RESULT(AVK_PASS);
    }

    void   srv_appmgr_uninstall_app_entry_scr(void)
    {
        MMI_ID group_id;

        group_id = srv_appmgr_launch("native.mtk.appmgr_test_1");
	    AVK_LOG_FUN(srv_appmgr_launch,AVK_PASS);

        srv_appmgr_uninstall_app("native.mtk.appmgr_test_1", NULL, NULL);
        AVK_LOG_FUN(srv_appmgr_uninstall_app,AVK_PASS);

        srv_appmgr_close_app(group_id);
        
        AVK_CASE_RESULT(AVK_PASS);
    }

    // MMI_ID srv_appmgr_query_instance_single_id(const mmi_app_package_char *app_name)
    void   srv_appmgr_query_instance_single_id_entry_scr(void)       // VS_TA_FW_PLUTO_APPMGR_18
    {
        mmi_ret retVal;
        mmi_app_package_name_struct name[10];
        MMI_ID single_id = GRP_ID_INVALID;
        U32 i;
        MMI_ID group_id;

        group_id = srv_appmgr_launch("native.mtk.appmgr_test_1");

        memset(name, 0, sizeof(mmi_app_package_name_struct) * 10);
        
        retVal = srv_appmgr_get_running_app_list(SRV_APPMGR_RUNNING_APP_FLAG_TYPE, name, 10);
	    AVK_LOG_FUN(srv_appmgr_get_running_app_list,AVK_PASS);

        for (i = 0; i < 10; i ++)
        {
            if (name[i][0] != 0)
            {
                if (strcmp(name[i], "Known App Package Name") == 0)
                {
                    continue;
                }

                single_id = srv_appmgr_query_instance_single_id(name[i]);
                AVK_LOG_FUN(srv_appmgr_query_instance_single_id,AVK_PASS);
                
                break;
            }
        }

        srv_appmgr_close_app(group_id);

        if (GRP_ID_INVALID != single_id)
        {
		    AVK_CASE_RESULT(AVK_PASS);
        }
        else
        {
		    AVK_CASE_RESULT(AVK_FAIL);
        }                
    }

#ifdef __cplusplus
}
#endif


#endif

/***************************************************************************************/

AVK_ADD_ITEM(AVK_FW_PLUTO_MANUL_ITEM_001,L"AppManager_001",AVK_PLUTO_AM)
#ifdef __MAUI_SOFTWARE_LA__
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_001,AVK_FW_PLUTO_MANUL_ITEM_001) {	srv_appmgr_performance_profiling_entry_scr();	        // 0
#else
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_001,AVK_FW_PLUTO_MANUL_ITEM_001) {	srv_appmgr_get_app_package_num_entry_scr();	    	}	// 0
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_002,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_get_app_package_list_entry_scr();		}	// 1
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_003,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_get_app_package_name_entry_scr();		}	// 2
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_004,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_get_app_package_image_entry_scr();		}	// 3
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_005,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_get_app_package_info_entry_scr();		}	// 4
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_006,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_launch_entry_scr();						}	// 5
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_007,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_launch_ex_entry_scr();					}	// 6
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_008,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_get_app_package_type_entry_scr();		}	// 7
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_009,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_is_app_package_running_entry_scr();		}	// 8
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_010,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_get_running_app_num_entry_scr();	        }	// 9
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_011,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_get_running_app_list_entry_scr();		}	// 10
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_012,AVK_FW_PLUTO_MANUL_ITEM_001)	{ 	srv_appmgr_query_instance_id_entry_scr();      		}	// 11
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_013,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_query_instance_num_entry_scr();          }	// 12
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_014,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_close_app_entry_scr();	    			}	// 13
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_015,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_post_evt_ex_entry_scr();			    	}	// 14
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_016,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_config_entry_scr();						}	// 15
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_017,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_send_evt_entry_scr();					}	// 16
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_018,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_post_evt_entry_scr();					}	// 17
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_019,AVK_FW_PLUTO_MANUL_ITEM_001) {   srv_appmgr_update_app_info_entry_scr();             }   // 18
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_020,AVK_FW_PLUTO_MANUL_ITEM_001) {   srv_appmgr_uninstall_app_entry_scr();               }   // 19
AVK_CASE(AVK_FW_PLUTO_AM_MANUL_021,AVK_FW_PLUTO_MANUL_ITEM_001)	{	srv_appmgr_query_instance_single_id_entry_scr();	    // 20
#endif /* __MAUI_SOFTWARE_LA__ */
    GoBackHistory();
}



