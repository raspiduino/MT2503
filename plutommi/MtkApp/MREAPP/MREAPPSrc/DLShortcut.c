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
*  AMDLAgent.c
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
*==============================================================================
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
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
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
*==============================================================================
*******************************************************************************/
#include "MMI_features.h"
#include "AlertScreen.h"
#include "GlobalResDef.h"
#include "CommonScreensResDef.h"
#include "conversions.h"
#include "mmi_rp_app_mre_def.h"
#include "mmi_trc.h"
#include "MMI_mre_trc.h"
#include "custom_events_notify.h"
#include "fs_gprot.h"
//#include "APPSDKFrameworkGProt.h"

#include "DLShortcut.h"
#include "MREAppMgrSrvGprot.h"

#include "vmswitch.h"
#include "vmsys.h"
#include "vmmem.h"
#include "vmsock.h"
//#undef __MRE_SAL_SOCKET__
#if defined(__MRE_SAL_SOCKET__)
#define MRE_DL_SHORTCUT
#endif

#ifdef MRE_DL_SHORTCUT
static MMI_ID s_group_id;
static MMI_ID s_group_id_query;
extern void srv_mre_update_cancel_sync_cdr(void);
extern kal_bool srv_usb_is_in_mass_storage_mode(void);
extern void mmi_usb_app_unavailable_popup(U16 stringId);
extern VMINT vm_preload_status(VMINT app_id);
static void mmi_shortcut_download_wait();
static void mmi_shortcut_download_wait_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_ID group_id, scrn_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cancel cdr update */

    //mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
    srv_mre_update_cancel_sync_cdr();
}

static void mmi_shortcut_download_wait()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    //MMI_ID scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s_group_id = mmi_frm_group_get_active_id();
    ret = mmi_frm_scrn_enter(
        s_group_id, 
        SCR_ID_DLS_WAIT, 
        (FuncPtr)mmi_shortcut_download_wait_scrn, 
        (FuncPtr)mmi_shortcut_download_wait, 
        MMI_FRM_FG_ONLY_SCRN);

    if (ret == MMI_FALSE)
    {
        s_group_id = 0;
        return;
    }

    ShowCategory63Screen((U8*) GetString(STR_GLOBAL_PLEASE_WAIT), IMG_GLOBAL_PROGRESS, NULL);
}

static void mmi_shortcut_download_popup(UI_string_type str_ptr, mmi_event_notify_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID parent_gid;
    mmi_popup_property_struct arg;   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_gid = mmi_frm_group_get_active_id();


    mmi_popup_property_init(&arg);              
    arg.callback = NULL;       
    arg.user_tag = NULL;          
    arg.parent_id = parent_gid; 
    arg.rotation = MMI_FRM_SCREEN_ROTATE_0;
    mmi_popup_display(                          
        str_ptr,                                
        type,                                   
        &arg);  

}

//static VMINT g_installing = 0;

#define MAX_INSTALLING 10
static  U32 g_installing[MAX_INSTALLING] = {0};
typedef struct
{
    U16 filepath[MMI_MAX_FILE_NAME_LEN];
    U32 app_id;
}mmi_shortcut_ctx;

static VMINT mmi_shortcut_state_is_app_installing(U32 app_id)
{
    VMINT i = 0;
    for (i = 0; i < MAX_INSTALLING; i++)
    {
        if (g_installing[i] == app_id)
        {
            return 1;
        }
    }

    return 0;
}

static VMINT mmi_shortcut_state_set_installing(U32 app_id)
{
    VMINT i = 0;
    for (i = 0; i < MAX_INSTALLING; i++)
    {
        if (0 == g_installing[i])
        {
            g_installing[i] = app_id;
            return 1;
        }
    }

    return 0;
}

static VMINT mmi_shortcut_state_unset_installing(U32 app_id)
{
    VMINT i = 0;
    for (i = 0; i < MAX_INSTALLING; i++)
    {
        if (app_id == g_installing[i])
        {
            g_installing[i] = 0;
            return 1;
        }
    }

    return 0;
}

//shortcut download UI
static void mmi_shortcut_download_install_cb(VMINT result, VMWSTR path, void* user_data)
{
    U32 app_id = (U32)user_data;
    mmi_frm_scrn_close(s_group_id, SCR_ID_DLS_WAIT);
    if (result)
    {
        //mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DLS_INSTALL_FAIL), MMI_EVENT_FAILURE, NULL);
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)(UI_string_type)GetString(STR_ID_DLS_INSTALL_FAIL));
    }
    else
    {
        //mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DLS_INSTALL_SECC), MMI_EVENT_SUCCESS, NULL);
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*)(UI_string_type)GetString(STR_ID_DLS_INSTALL_SECC));
    }
    //g_installing = 0;
    mmi_shortcut_state_unset_installing(app_id);
}


static void mmi_shortcut_download_update_cb(S32 hdl, void * para)
{
    //VMCHAR buff[256];
    vm_update_download_param param;
    vm_preload_recv_data_t* data = (vm_preload_recv_data_t*)para;
    mmi_shortcut_ctx * sc_ctx = data->head.user_data;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_S, 2, __LINE__);

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_LOG, 
        data->head.state,
        0,
        0,
        0,
        0,
        data->head.user_data,
        2, __LINE__);

    if (E_PRELOAD_AVAILABLE_UPDATE == data->head.state)
    {
        //param.bSaveOnCard = 1;
        if (FS_GetDevStatus((unsigned int)FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, 	FS_NO_ALT_DRIVE), FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
        {
            param.bSaveOnCard = 1;
        }
        else
        {
            param.bSaveOnCard = 0;
        }
        param.callback = mmi_shortcut_download_update_cb;
        param.user_data = data->head.user_data;
        param.handle = hdl;
        //param.app_path = (VMWSTR)data->head.user_data;
        param.app_path = (VMWSTR)sc_ctx->filepath;

        if (0 > vm_update_download_ex(&param))
        {
            MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E6, 2, __LINE__);
            mmi_frm_scrn_close(s_group_id, SCR_ID_DLS_WAIT);
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)(UI_string_type)GetString(STR_ID_DLS_INSTALL_FAIL));
            return;
        }
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E1, 2, __LINE__);
    }
    else if (E_PRELOAD_DOWNLOADED == data->head.state)
    {
        VMINT ret = 0;
        ret = vm_update_update_file_ex((VMWSTR)/*data->head.user_data*/sc_ctx->filepath,mmi_shortcut_download_install_cb, (void*)sc_ctx->app_id);
        // close wait screen.
        mmi_frm_scrn_close(s_group_id, SCR_ID_DLS_WAIT);
        //mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DLS_DOWNLOADED), MMI_EVENT_SUCCESS, NULL);
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*)(UI_string_type)GetString(STR_ID_DLS_DOWNLOADED));
        //g_installing = 1;
        if (VM_UPDATE_OK == ret)
        {
            mmi_shortcut_state_set_installing(sc_ctx->app_id);
        }
        //_vm_kernel_free(data->head.user_data);
        _vm_kernel_free(sc_ctx);
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E2, 2, __LINE__);
    }
    else if (data->head.state != E_PRELOAD_DOWNLOADING && data->head.state != E_PRELOAD_QUERYING &&
        data->head.state != E_PRELOAD_CONNECTING && data->head.state != E_PRELOAD_CONNECTED)
    {
        // close wait screen.
        mmi_frm_scrn_close(s_group_id, SCR_ID_DLS_WAIT);
        switch (data->head.state)
        {
        case E_PRELOAD_NO_UPDATE: // query result
            {
                //mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DLS_NO_UPDATE), MMI_EVENT_SUCCESS, NULL);
                mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)(UI_string_type)GetString(STR_ID_DLS_NO_UPDATE));
            }break;
        case E_PRELOAD_HOST_NOT_FOUND: // query result
            {
                //mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DLS_HOST_NOT_FOUND), MMI_EVENT_FAILURE, NULL);
                mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)(UI_string_type)GetString(STR_ID_DLS_HOST_NOT_FOUND));
                MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E3, 2, __LINE__);
            }break;
        case E_PRELOAD_PIPE_CLOSED: // query result
            {
                //mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DLS_PIPE_CLOSED), MMI_EVENT_FAILURE, NULL);
                mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)(UI_string_type)GetString(STR_ID_DLS_PIPE_CLOSED));
            }break;
        case E_PRELOAD_PIPE_BROKEN: // query result
            {

                //mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_DI_DLS_NETWORK_PROBLEM), MMI_EVENT_FAILURE, NULL);
                mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)(UI_string_type)GetString(STR_DI_DLS_NETWORK_PROBLEM));
            }break;
        case E_PRELOAD_FAILURE: // query result (disk not enough maybe)
            {
                //mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_DI_DLS_FAIL_MAY_DISK_FULL), MMI_EVENT_FAILURE, NULL);
                mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)(UI_string_type)GetString(STR_DI_DLS_FAIL_MAY_DISK_FULL));
            }break;
        case E_PRELOAD_ERR_PATH: // download result
            {
                //mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DLS_ERR_PATH), MMI_EVENT_FAILURE, NULL);
                mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)(UI_string_type)GetString(STR_ID_DLS_ERR_PATH));
                MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E5, 2, __LINE__);
            }break;
        }
        _vm_kernel_free(data->head.user_data);
        data->head.user_data = NULL;
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E4, 2, __LINE__);
    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E, 2, __LINE__);
}


static mmi_ret mmi_shortcut_download_confirm_cb(mmi_alert_result_evt_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_b = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ASSERT(sg_dla_ctx_p);


    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            {              
                VMINT result;
                U16 app_name_w[MMI_MAX_FILE_NAME_LEN] = {0};
                //U16* filepath = NULL;
                mmi_shortcut_ctx * sc_ctx = NULL;
                vm_update_check_version_param param;
                CHAR* app_name = evt->user_tag; 

                //filepath = (U16*)_vm_kernel_malloc(MMI_MAX_FILE_NAME_LEN);
                //if (!filepath)
                sc_ctx = (mmi_shortcut_ctx *)_vm_kernel_malloc(sizeof(mmi_shortcut_ctx));
                if (!sc_ctx);
                {
                    _vm_kernel_free(app_name);
                    return MMI_RET_ERR;
                }
                mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_MAX_FILE_NAME_LEN*2);


                MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_S, 1, __LINE__);
                param.app_id = srv_mre_appmgr_get_appid(app_name_w);
                srv_mre_appmgr_get_file_path((mmi_app_package_char*)app_name, sc_ctx->filepath);
                param.URL = srv_mre_appmgr_get_app_url(app_name);//"http://appupgrade.services-mtk.com/gmas/AppsUpdate";
                _vm_kernel_free(app_name);    
                sc_ctx->app_id = param.app_id;
                param.port = 80;
                param.apn = 1;
                param.app_path = (VMWSTR)sc_ctx->filepath;
                param.app_ver = "0.0.0";
                param.app_info = NULL;
                param.callback = mmi_shortcut_download_update_cb;
                param.user_data = sc_ctx;
                result = vm_update_check_version_ex(&param);

                MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_LOG, 
                    result,
                    param.URL,
                    param.port,
                    param.apn,
                    sc_ctx->filepath,
                    param.app_id,
                    1, __LINE__);


                if (VM_UPDATE_OK_ALREADY_DOWNLOADED == result)
                {
                    VMINT ret = 0;
                    ret = vm_update_update_file_ex((VMWSTR)sc_ctx->filepath, mmi_shortcut_download_install_cb, (void*)param.app_id);
                    //_vm_kernel_free(filepath);
                    _vm_kernel_free(sc_ctx);
                    //g_installing = 1;
                    if (VM_UPDATE_OK == ret)
                    {
                        mmi_shortcut_state_set_installing(param.app_id);
                    }
                    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E1, 1, __LINE__);
                }
                else if (VM_UPDATE_OK  != result)
                {                    
                    //mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE, NULL);
                    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)(UI_string_type)GetString(STR_GLOBAL_FAILED));
                    //_vm_kernel_free(filepath);
                    _vm_kernel_free(sc_ctx);
                    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E2, 1, __LINE__);
                }
                else
                {
                    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E3, 1, __LINE__);
                    mmi_shortcut_download_wait();
                }
                MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E, 1, __LINE__);

            }
            break;
        case MMI_ALERT_CNFM_NO:
            {
                CHAR* app_name = evt->user_tag; 
                _vm_kernel_free(app_name);
                mmi_frm_scrn_close_active_id();

                MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E, 2, __LINE__);
            }
            break;
        }
    }
    return MMI_RET_OK;
}

static CHAR* g_app_name = NULL;
static void mmi_mre_shortcut_query_yes()
{              
    VMINT result;
    U16 app_name_w[MMI_MAX_FILE_NAME_LEN] = {0};
    //U16* filepath = NULL;
    mmi_shortcut_ctx * sc_ctx = NULL;
    vm_update_check_version_param param;

    //mmi_frm_scrn_close_active_id();
    mmi_frm_scrn_close(s_group_id_query, SCR_ID_DLS_QUERY);

    //filepath = (U16*)_vm_kernel_malloc(MMI_MAX_FILE_NAME_LEN);
    //if (!filepath)
    sc_ctx = (mmi_shortcut_ctx *)_vm_kernel_malloc(sizeof(mmi_shortcut_ctx));
    if (!sc_ctx)
    {
        _vm_kernel_free(g_app_name);
        return;
    }
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)g_app_name, (char *)app_name_w, MMI_MAX_FILE_NAME_LEN*2);


    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_S, 1, __LINE__);
    param.app_id = srv_mre_appmgr_get_appid(app_name_w);
    srv_mre_appmgr_get_file_path((mmi_app_package_char*)g_app_name, sc_ctx->filepath);
    param.URL = srv_mre_appmgr_get_app_url(g_app_name);//"http://appupgrade.services-mtk.com/gmas/AppsUpdate";
    _vm_kernel_free(g_app_name);
    g_app_name = NULL;
    sc_ctx->app_id = param.app_id;
    param.port = 80;
    param.apn = 1;
    param.app_path = (VMWSTR)sc_ctx->filepath;
    param.app_ver = "0.0.0";
    param.app_info = NULL;
    param.callback = mmi_shortcut_download_update_cb;
    param.user_data = sc_ctx;
    result = vm_update_check_version_ex(&param);

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_LOG, 
        result,
        param.URL,
        param.port,
        param.apn,
        sc_ctx->filepath,
        param.app_id,
        1, __LINE__);


    if (VM_UPDATE_OK_ALREADY_DOWNLOADED == result)
    {
        VMINT ret = 0;
        ret = vm_update_update_file_ex((VMWSTR)sc_ctx->filepath, mmi_shortcut_download_install_cb, (void*)param.app_id);
        //_vm_kernel_free(filepath);
        _vm_kernel_free(sc_ctx);
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E1, 1, __LINE__);
        mmi_shortcut_download_wait();
        //g_installing = 1;
        if (VM_UPDATE_OK == ret)
        {
            mmi_shortcut_state_set_installing(param.app_id);
        }
    }
    else if (VM_UPDATE_OK  != result)
    {                    
        //mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE, NULL);
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)(UI_string_type)GetString(STR_GLOBAL_FAILED));
        //_vm_kernel_free(filepath);
        _vm_kernel_free(sc_ctx->filepath);
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E2, 1, __LINE__);
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E3, 1, __LINE__);
        mmi_shortcut_download_wait();
    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E, 1, __LINE__);

}


static void mmi_mre_shortcut_query_no()
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_S, 2, __LINE__);

    if (g_app_name)
    {
        _vm_kernel_free(g_app_name);
        g_app_name = NULL;
    }
    //mmi_frm_scrn_close_active_id();
    mmi_frm_scrn_close(s_group_id_query, SCR_ID_DLS_QUERY);

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_E, 2, __LINE__);

}

static void mmi_mre_shortcut_query_entry_int()
{
    MMI_ID scrn_id;
    U8 *guiBuffer = NULL;

    //EntryNewScreen(scrn_id, NULL, NULL, NULL);
    mmi_frm_get_active_scrn_id(&s_group_id_query, &scrn_id); 
    s_group_id_query = mmi_frm_group_get_top_parent_group_id(s_group_id_query);
    mmi_frm_scrn_enter(s_group_id_query, 
        SCR_ID_DLS_QUERY,
        NULL,
        NULL,
        MMI_FRM_FULL_SCRN);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory66Screen(
        0,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_CANCEL,
        (U8*)GetString(STR_ID_DLS_QUERY),
        0, //mmi_get_event_based_image(MMI_EVENT_QUERY),
        guiBuffer);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    SetLeftSoftkeyFunction((FuncPtr)mmi_mre_shortcut_query_yes, KEY_EVENT_UP);
    SetCenterSoftkeyFunction((FuncPtr)mmi_mre_shortcut_query_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction((FuncPtr)mmi_mre_shortcut_query_no, KEY_EVENT_UP);

}

#endif /* MRE_DL_SHORTCUT */
typedef struct _mmi_shortcut_list_t mmi_shortcut_list_t;
typedef struct _mmi_shortcut_list_t
{
    void * ptr;
    mmi_shortcut_list_t * next;
}mmi_shortcut_list_t;

mmi_shortcut_list_t g_head;

extern srv_mre_appmgr_shortcut_info_struct g_shortcut_info_list[];
static mmi_mre_shortcut_get_sc_num(void)
{
    U32 i = 0;
    while (!(g_shortcut_info_list[i].app_id == (U32)-1 &&
        g_shortcut_info_list[i].icon_id == (U16)-1 &&
        g_shortcut_info_list[i].name_id == (U16)-1))
    {
        i++;
    }
    return i;

}
U32 mmi_mre_shortcut_is_shortcut(U16 string_id)
{
#ifdef MRE_DL_SHORTCUT // TODO:
    VMINT i = 0;
    VMINT num = mmi_mre_shortcut_get_sc_num();
    for (i = 0; i < num; i++)
    {
        if (g_shortcut_info_list[i].name_id == string_id)
        {
            return g_shortcut_info_list[i].app_id;
        }
    }

#endif

    return 0;
}

U32 mmi_mre_shortcut_is_NA(U32 app_id, U8 * string)
{
#ifdef MRE_DL_SHORTCUT // TODO:
    extern MMI_BOOL srv_mre_appmgr_is_shortcut_app_by_id(U32 app_id);
    MMI_BOOL is_shortcut, installed;

    is_shortcut = srv_mre_appmgr_is_shortcut_app_by_id(app_id);
    if (is_shortcut)
    {
        mmi_app_package_char tmp_str[260] = {0};
        mmi_shortcut_list_t * tmp = &g_head;
        S32 len = 0;
        //WCHAR app_name[260] = {0};
        srv_mre_appmgr_get_shortcut_app_name_package(app_id, tmp_str);
        //mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)tmp_str, (char *)app_name, MMI_APP_NAME_MAX_LEN);
        if (srv_mre_appmgr_is_app_installed(tmp_str))
            installed = MMI_TRUE;
        else
            installed = MMI_FALSE;
        if (installed)
            return (U32)string;
        len = 2*(kal_wstrlen((WCHAR*)string) + kal_wstrlen((WCHAR*)GetString(STR_ID_DLS_NA_NAME)) + 1);
        if (NULL == tmp->ptr)
        {
            tmp->ptr = (void*)_vm_kernel_malloc(len);
            memset(tmp->ptr, 0, len);
        }
        else
        {

            while (tmp->next)
            {
                tmp = tmp->next;
            }

            tmp->next = (void*)_vm_kernel_malloc(sizeof(mmi_shortcut_list_t));
            tmp->next->next = NULL;
            tmp->next->ptr = (void*)_vm_kernel_malloc(len);
            memset(tmp->next->ptr, 0, len);
            tmp = tmp->next;
        }
        kal_wstrcat((WCHAR *)tmp->ptr, (const WCHAR *)string);
        kal_wstrcat((WCHAR *)tmp->ptr, (const WCHAR *)GetString(STR_ID_DLS_NA_NAME));


        return (U32)tmp->ptr;
    }

#endif

    return 0;
}

U32 mmi_mre_shortcut_free(void)
{
    mmi_shortcut_list_t * tmp = &g_head;
    mmi_shortcut_list_t * tmp_next = &g_head;
    _vm_kernel_free(tmp->ptr);
    tmp = tmp->next;

    while (tmp)
    {
        tmp_next = tmp->next;
        _vm_kernel_free(tmp->ptr);
        _vm_kernel_free(tmp);
        tmp = tmp_next;
    }

    g_head.next = NULL;
    g_head.ptr = NULL;
    return 0;
}

void mmi_mre_shortcut_download(CHAR * appName)
{
#ifdef MRE_DL_SHORTCUT // TODO:

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID parent_gid;
    //mmi_confirm_property_struct arg;   
    //CHAR * app_name = NULL; 
    U32 app_id = 0;
    WCHAR app_name_w[MMI_MAX_FILE_NAME_LEN] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, can't use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */


    parent_gid = mmi_frm_group_get_active_id();
    g_app_name = (CHAR*)_vm_kernel_malloc(strlen(appName)+1);
    if (NULL == g_app_name)
    {
        return;
    }

    strcpy(g_app_name, appName);
    /*
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.f_msg_icon = 0;
    arg.callback = (mmi_proc_func) mmi_shortcut_download_confirm_cb;
    arg.parent_id = parent_gid;
    arg.user_tag = app_name;
    mmi_confirm_display((WCHAR*) GetString(STR_ID_DLS_QUERY), MMI_EVENT_QUERY, &arg);
    */

    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)g_app_name, (char *)app_name_w, MMI_MAX_FILE_NAME_LEN*2);


    app_id = srv_mre_appmgr_get_appid(app_name_w);
    if (E_PRELOAD_DOWNLOADING == vm_preload_status(app_id))
    {
        //mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_ID_DLS_DOWNLOADING), MMI_EVENT_FAILURE, NULL);
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)(UI_string_type)GetString(STR_ID_DLS_DOWNLOADING));
        return;
    }


    /* if (g_installing)*/
    if (mmi_shortcut_state_is_app_installing(app_id))
    {
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)(UI_string_type)GetString(STR_ID_DLS_INSTALLING));
        return;
    }




    mmi_mre_shortcut_query_entry_int();



    //wgui_set_left_softkey_handler(mmi_shortcut_download_confirm_cb);        
    //wgui_set_right_softkey_handler(GoBackHistory);
#else
    //mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_NOT_AVAILABLE, NULL);
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_NOT_AVAILABLE, (WCHAR*)(UI_string_type)GetString(STR_GLOBAL_NOT_AVAILABLE));
#endif /* MRE_DL_SHORTCUT */
}

static U32 mmi_mre_shortcut_highlight_app_id;
static MMI_BOOL mmi_mre_shortcut_highlight_app_is_exist;
static void mmi_mre_shortcut_launch_submenu(void);

static void mmi_mre_shortcut_reg_submenu_highlight_hdlr(U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_app_package_char app_name[MMI_APP_NAME_MAX_LEN] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mre_appmgr_get_shortcut_app_name_package(app_id, app_name);
    if (srv_mre_appmgr_is_shortcut_app(app_name))
    {
        if ( srv_mre_appmgr_is_app_installed(app_name) && 
            (srv_mre_appmgr_is_app_exist(app_name) || 
            srv_mre_appmgr_is_bg_running(app_name)))
        {
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            mmi_mre_shortcut_highlight_app_is_exist = MMI_TRUE;
        }
        else
        {
            ChangeLeftSoftkey(STR_GLOBAL_DOWNLOAD, IMG_GLOBAL_OK);
            mmi_mre_shortcut_highlight_app_is_exist = MMI_FALSE;
        }
    }
    mmi_mre_shortcut_highlight_app_id = app_id;

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    if (!mmi_mre_shortcut_highlight_app_is_exist)
    {
        ChangeLeftSoftkey(STR_ID_DLS_NA_SLK, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }
    SetLeftSoftkeyFunction(mmi_mre_shortcut_launch_submenu, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mre_shortcut_launch_submenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


static void mmi_mre_shortcut_launch_submenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_app_package_char app_name[MMI_APP_NAME_MAX_LEN] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mre_appmgr_get_shortcut_app_name_package(
        mmi_mre_shortcut_highlight_app_id,
        app_name);
    if (mmi_mre_shortcut_highlight_app_is_exist == MMI_TRUE)
    {
        srv_mre_appmgr_launch(app_name, NULL, 0);
    }
    else
    {
        mmi_mre_shortcut_download(app_name);
    }
}


#ifdef __MMI_MRE_APP_CALCULATOR_SHORTCUT__
void mmi_mre_shortcut_calculator_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67140);
#elif defined(__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67141);
#elif defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67142);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67143);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67144);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67145);
#endif
}
#endif

#ifdef __MMI_MRE_APP_HEALTH_SHORTCUT__
void mmi_mre_shortcut_health_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67150);
#elif defined(__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67151);
#elif defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67152);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67153);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67154);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67155);
#endif
}
#endif

#ifdef __MMI_MRE_APP_STOPWATCH_SHORTCUT__
void mmi_mre_shortcut_stopwatch_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67160);
#elif defined(__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67161);
#elif defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67162);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67163);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67164);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67165);
#endif
}
#endif

#ifdef __MMI_MRE_APP_CONVERTER_SHORTCUT__
void mmi_mre_shortcut_converter_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67170);
#elif defined(__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67171);
#elif defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67172);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67173);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67174);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67175);
#endif
}
#endif

#ifdef __MMI_MRE_APP_ZAKAT_SHORTCUT__
void mmi_mre_shortcut_zakat_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67180);
#elif defined(__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67181);
#elif defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67182);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67183);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67184);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67185);
#endif
}
#endif

#ifdef __MMI_MRE_GAME_EGYPTCODE_EN_SHORTCUT__
void mmi_mre_shortcut_egyptcode_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67000);
#elif defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67001);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67002);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67003);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67004);
#endif
}
#endif

#ifdef __MMI_MRE_GAME_GIRLSLOT_EN_SHORTCUT__
void mmi_mre_shortcut_girlslot_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67010);
#elif defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67011);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67012);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67013);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67014);
#endif
}
#endif

#ifdef __MMI_MRE_GAME_GOLDMINER_EN_SHORTCUT__
void mmi_mre_shortcut_goldminer_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67040);
#elif defined(__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67041);
#elif defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67042);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67043);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67044);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67045);
#endif
}
#endif

#ifdef __MMI_MRE_GAME_HAPPYEGG_EN_SHORTCUT__
void mmi_mre_shortcut_happyegg_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_128X160__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67080);
#elif defined(__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67081);
#elif defined(__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67082);
#elif defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67083);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67084);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67085);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67086);
#endif
}
#endif

#ifdef __MMI_MRE_GAME_HAPPYWAR_EN_SHORTCUT__
void mmi_mre_shortcut_happywar_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67070);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67071);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67072);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67073);
#endif
}
#endif

#ifdef __MMI_MRE_GAME_KINGCOMBAT_EN_SHORTCUT__
void mmi_mre_shortcut_kingcombat_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67050);
#elif defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67051);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67052);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67053);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67054);
#endif
}
#endif

#ifdef __MMI_MRE_GAME_MOTO_EN_SHORTCUT__
void mmi_mre_shortcut_moto_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67020);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67021);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67022);
#endif
}
#endif

#ifdef __MMI_MRE_GAME_PARKOUR_EN_SHORTCUT__
void mmi_mre_shortcut_parkour_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67030);
#elif defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67031);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67032);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67033);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67034);
#endif
}
#endif

#ifdef __MMI_MRE_GAME_TEARDRESS_EN_SHORTCUT__
void mmi_mre_shortcut_teardress_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67060);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67061);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67062);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67063);
#endif
}
#endif

#if defined(__MMI_MRE_APP_FACEBOOK_V2_SHORTCUT__) || defined(__MMI_MRE_APP_FACEBOOK_V2_STANDARD_SHORTCUT__)
void mmi_mre_shortcut_facebook_v2_highlight_hdlr(void)
{
#if defined(__MMI_MRE_APP_FACEBOOK_V2_SHORTCUT__)
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_220X176__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362580);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362581);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362582);
#endif
#elif defined(__MMI_MRE_APP_FACEBOOK_V2_STANDARD_SHORTCUT__)
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_220X176__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362583);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362585);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362587);
#endif
#endif
}
#endif

#ifdef __MMI_MRE_APP_YAHOOMV2_SHORTCUT__
void mmi_mre_shortcut_yahoomv2_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362566);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362568);
#endif
}
#endif /* __MMI_MRE_APP_YAHOOMV2_SHORTCUT__ */
#ifdef __MMI_MRE_APP_YAHOONEWS_SHORTCUT__
void mmi_mre_shortcut_yahoonews_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_220X176__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362556);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362557);
#endif
}
#endif /* __MMI_MRE_APP_YAHOONEWS_SHORTCUT__ */
#ifdef __MMI_MRE_APP_YAHOOFINANCE_SHORTCUT__
void mmi_mre_shortcut_yahoofinance_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_220X176__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362554);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362555);
#endif
}
#endif /* __MMI_MRE_APP_YAHOOFINANCE_SHORTCUT__ */
#ifdef __MMI_MRE_APP_YAHOOWEATHER_SHORTCUT__
void mmi_mre_shortcut_yahooweather_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_220X176__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362558);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(1664362559);
#endif
}
#endif /* __MMI_MRE_APP_YAHOOWEATHER_SHORTCUT__ */
#ifdef __MMI_MRE_APP_YAHOOCRICKET_SHORTCUT__
void mmi_mre_shortcut_yahoocricket_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_128X160__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65705);
#elif defined(__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65701);
#elif defined(__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65704);
#elif defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65702);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65703);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65700);
#endif
}
#endif /* __MMI_MRE_APP_YAHOOCRICKET_SHORTCUT__ */
#ifdef __MMI_MRE_APP_TWITTER_SHORTCUT__
void mmi_mre_shortcut_twitter_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_128X160__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65850);
#elif defined(__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65851);
#elif defined(__MMI_MAINLCD_220X176__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65852);
#elif defined(__MMI_MAINLCD_320X240__)
#if !defined (REDUCED_KEYPAD) && !defined (TOUCH_PANEL_SUPPORT)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65855);
#elif defined(TOUCH_PANEL_SUPPORT)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65856);
#endif
#elif defined(__MMI_MAINLCD_240X320__)
#if !defined (REDUCED_KEYPAD) && !defined (TOUCH_PANEL_SUPPORT)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65853);
#elif defined(TOUCH_PANEL_SUPPORT)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65854);
#endif
#elif defined(__MMI_MAINLCD_240X400__)
#if defined (TOUCH_PANEL_SUPPORT) && !defined (REDUCED_KEYPAD)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65857);
#elif defined (TOUCH_PANEL_SUPPORT) && defined (REDUCED_KEYPAD)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65858);
#endif
#elif defined(__MMI_MAINLCD_320X480__)
#if defined (TOUCH_PANEL_SUPPORT) && !defined (REDUCED_KEYPAD)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65859);
#elif defined (TOUCH_PANEL_SUPPORT) && defined (REDUCED_KEYPAD)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65860);
#endif
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(65861);
#endif
}
#endif /* __MMI_MRE_APP_TWITTER_SHORTCUT__ */

#ifdef __MMI_MRE_APP_GAMELOFT_LIVE_SHORTCUT__
void mmi_mre_shortcut_gameloft_live_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67190);
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67191);
#endif
}
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_BC_SHORTCUT__
void mmi_mre_shortcut_gameloft_bc_highlight_hdlr(void)
{
#if defined (__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67300);
#elif defined (__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67301);
#elif defined (__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67302);
#elif defined (__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67303);
#elif defined (__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67304);
#elif defined (__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67305);
#endif
}
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_BB_SHORTCUT__
void mmi_mre_shortcut_gameloft_bb_highlight_hdlr(void)
{
#if defined (__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67260);
#elif defined (__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67261);
#elif defined (__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67262);
#elif defined (__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67263);
#elif defined (__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67264);
#elif defined (__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67265);
#endif
}
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_AC_SHORTCUT__
void mmi_mre_shortcut_gameloft_ac_highlight_hdlr(void)
{
#if defined (__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67280);
#elif defined (__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67281);
#elif defined (__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67282);
#elif defined (__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67283);
#elif defined (__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67284);
#elif defined (__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67285);
#endif
}
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_MC2_SHORTCUT__
void mmi_mre_shortcut_gameloft_mc2_highlight_hdlr(void)
{
#if defined (__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67320);
#elif defined (__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67321);
#elif defined (__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67322);
#elif defined (__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67323);
#elif defined (__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67324);
#elif defined (__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67325);
#endif
}
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_AS6_SHORTCUT__
void mmi_mre_shortcut_gameloft_as6_highlight_hdlr(void)
{
#if defined (__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67250);
#elif defined (__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67251);
#elif defined (__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67252);
#elif defined (__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67253);
#elif defined (__MMI_MAINLCD_176X220__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67254);
#elif defined (__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67255);
#endif
}
#endif

#ifdef __MMI_MRE_APP_GMOBI_APPSTORE_SHORTCUT__
void mmi_mre_shortcut_gmobi_appstore_highlight_hdlr(void)
{
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67090);
}
#endif

#ifdef __MMI_MRE_APP_MBOUNCE_APPSTORE_SHORTCUT__
void mmi_mre_shortcut_mbounce_appstore_highlight_hdlr(void)
{
#ifdef __COSMOS_MMI_PACKAGE__
#if defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67101);
#else
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67100);
#endif
#elif defined(__PLUTO_MMI_PACKAGE__)
#if defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67103);
#else
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67102);
#endif
#endif
}
#endif

#ifdef __MMI_MRE_APP_KKFUN_APPSTORE_SHORTCUT__
void mmi_mre_shortcut_kkfun_appstore_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_320X240__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67110);
#elif defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67111);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67112);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67113);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67114);
#endif
}
#endif

#ifdef __MMI_MRE_APP_MOBIM_APPSTORE_SHORTCUT__
void mmi_mre_shortcut_mobim_appstore_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67130);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67131);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67132);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67133);
#endif
}
#endif

#ifdef __MMI_MRE_APP_MTONE_APPSTORE_SHORTCUT__
void mmi_mre_shortcut_mtone_appstore_highlight_hdlr(void)
{
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67120);
}
#endif /* __MMI_MRE_APP_MTONE_APPSTORE_SHORTCUT__ */

#ifdef __MMI_MRE_APP_MODING_APPSTORE_SHORTCUT__
void mmi_mre_shortcut_moding_appstore_highlight_hdlr(void)
{
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67230);
}
#endif /* __MMI_MRE_APP_MODING_APPSTORE_SHORTCUT__ */

#ifdef __MMI_MRE_APP_MOMAGIC_APPSTORE_SHORTCUT__
void mmi_mre_shortcut_momagic_appstore_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67400);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67401);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67402);
#endif
}
#endif /* __MMI_MRE_APP_MOMAGIC_APPSTORE_SHORTCUT__ */
#if defined(__MMI_MRE_APP_MOBIM_FCWR__) && (__MMI_MRE_APP_MOBIM_FCWR__&__MRE_APP_SHORTCUT__)
void mmi_mre_shortcut_mobim_fcwr_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67360);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67361);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67362);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67363);
#endif
}
#endif /* __MMI_MRE_APP_MOBIM_FCWR__ */

#if defined(__MMI_MRE_APP_MITAKE_MSTOCK__) && (__MMI_MRE_APP_MITAKE_MSTOCK__&__MRE_APP_SHORTCUT__)
void mmi_mre_shortcut_mitake_mstock_highlight_hdlr(void)
{
#if defined(__MMI_MAINLCD_240X320__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67370);
#elif defined(__MMI_MAINLCD_240X400__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67371);
#elif defined(__MMI_MAINLCD_320X480__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67372);
#elif defined(__MMI_MAINLCD_480X800__)
    mmi_mre_shortcut_reg_submenu_highlight_hdlr(67373);
#endif
}
#endif /* __MMI_MRE_APP_MITAKE_MSTOCK__ */
// submenu in PLUTO
#ifdef MRE_SHORTCUT_SUBMENU
static void mmi_mre_shortcut_submenu_launch_test1(void);
static void mmi_mre_shortcut_submenu_launch_test2(void);


void mmi_mre_shortcut_submenu_launch_by_appid(U32 app_id)
{

}

void mmi_mre_shortcut_submenu_highlight_test1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_mre_shortcut_submenu_launch_test1, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mre_shortcut_submenu_launch_test1, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

void mmi_mre_shortcut_submenu_highlight_test2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_mre_shortcut_submenu_launch_test2, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mre_shortcut_submenu_launch_test2, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

static void mmi_mre_shortcut_submenu_launch_test1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_app_package_char app_name[MMI_APP_NAME_MAX_LEN] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_mre_appmgr_get_shortcut_app_name_package(0x0100a4, app_name);
    if (srv_mre_appmgr_is_shortcut_app(app_name))
    {
        if ( srv_mre_appmgr_is_app_installed(app_name))
        {
            srv_mre_appmgr_launch(app_name, NULL, 0);
        }
        else
        {
            mmi_mre_shortcut_download(app_name);
        }
    }
}

static void mmi_mre_shortcut_submenu_launch_test2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_app_package_char app_name[MMI_APP_NAME_MAX_LEN] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mre_appmgr_get_shortcut_app_name_package(0x0100a5, app_name);
    if (srv_mre_appmgr_is_shortcut_app(app_name))
    {
        if ( srv_mre_appmgr_is_app_installed(app_name))
        {
            srv_mre_appmgr_launch(app_name, NULL, 0);
        }
        else
        {
            mmi_mre_shortcut_download(app_name);
        }
    }
}
#endif /* MRE_SHORTCUT_SUBMENU */

