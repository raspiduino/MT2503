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
 *  JavaAgencyNCenter.cpp
 *
 * Project:
 * --------
 *  Venus
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __J2ME__
#include "MMI_features.h" 
#ifdef __MMI_NCENTER_SUPPORT__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_include.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "jal.h"
#include "jam_internal.h"
#include "jam_mvm_manager.h"
#include "JavaAgencyGProt.h"
#include "JavaAgencyProt.h"
#include "wgui_categories_util.h"
#include "gui_typedef.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
#ifdef __cplusplus
}
#endif
#include "vapp_java_srv.h"
#include "mmi_rp_app_ncenter_def.h"
#include "vsrv_ncenter.h"
#include "vsrv_notification.h"
//#include "vapp_ncenter_gprot.h"
#include "AlertScreen.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_WCHAR_FILENAME_LEN         (260)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
kal_int32 g_mmi_java_selected_ongoing_cell = -1;
extern "C" mmi_java_push_cntx_struct g_mmi_java_push_cntx;
extern "C" NMGR_HANDLE g_mmi_java_push_nmgr_handle;

/***************************************************************************** 
 * Function
 *****************************************************************************/
 #ifdef __SUPPORT_JAVA_PUSH__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_ncenter_event_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
extern "C" mmi_ret mmi_java_push_ncenter_event_proc(mmi_event_struct *evt)   
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    VSRV_NOTIFICATION_CLOSE_EX(VAPP_JAVA, (VsrvNotificationId)-1);
#else
    VSRV_NOTIFICATION_CLOSE_EX(APP_JAVA, (VsrvNotificationId)-1);
#endif
    mmi_java_push_confirm_hdlr();
    mmi_frm_nmgr_alert_cancel(g_mmi_java_push_nmgr_handle);
#ifdef __MMI_USB_SUPPORT__
    if (g_mmi_java_push_cntx.option_choice == 2 && srv_usb_is_in_mass_storage_mode())
    {
    #ifndef __COSMOS_MMI_PACKAGE__
        mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE), MMI_EVENT_FAILURE, NULL);
    #else
        vapp_java_display_push_popup(STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE);
    #endif
    }
#endif
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_ncenter_event_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
extern "C" void mmi_java_push_ncenter_event_callback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(intent.type == VSRV_NINTENT_TYPE_LAUNCH)
    {
        mmi_event_struct evt;

#ifdef __MMI_USB_SUPPORT__
        if(srv_usb_is_in_mass_storage_mode())
        {
            g_mmi_java_push_cntx.option_choice = 2;
        }
        else
#endif
        {
            g_mmi_java_push_cntx.option_choice = 0;
        }

        MMI_FRM_INIT_EVENT(&evt, 0);
        MMI_FRM_POST_EVENT(&evt, mmi_java_push_ncenter_event_proc, NULL);
    }
    else if(intent.type == VSRV_NINTENT_TYPE_CLEAR)
    {
        g_mmi_java_push_cntx.scrn_force_del_check = MMI_FALSE; 
        mmi_java_push_send_push_res(g_mmi_java_push_cntx.processing_idx, g_java.mids_setting.permission_push, KAL_FALSE);
        mmi_frm_nmgr_alert_cancel(g_mmi_java_push_nmgr_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_ncenter_event_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
extern "C" void mmi_java_push_ncenter_event_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VsrvNGroupSingleTitle *group = NULL;
    VsrvNotificationEvent *noti;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_JAVA));
#else
    VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (APP_JAVA));
#endif
    group->setTitle(VFX_WSTR_RES(STR_SCR_JAVA_CAPTION));
	
    VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroup*)group, (VsrvNotificationId)-1));
    noti->setIcon(VfxImageSrc(VAPP_IMG_NCENTER_DEFAULT_EVENT_ICON));
    noti->setMainText(VFX_WSTR_RES(STR_JAVA_PUSH_ARRIVE));
    noti->setIntentCallback(&mmi_java_push_ncenter_event_callback);
    noti->notify();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_push_ncenter_event_hide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
extern "C" void mmi_java_push_ncenter_event_hide(void)   
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_java_push_cntx.is_processing)
    {
#ifdef __COSMOS_MMI_PACKAGE__
        VSRV_NOTIFICATION_CLOSE_EX(VAPP_JAVA, (VsrvNotificationId)-1);
#else
        VSRV_NOTIFICATION_CLOSE_EX(APP_JAVA, (VsrvNotificationId)-1);
#endif
        mmi_java_push_send_push_res(g_mmi_java_push_cntx.processing_idx, g_java.mids_setting.permission_push, KAL_FALSE);
        mmi_frm_nmgr_alert_cancel(g_mmi_java_push_nmgr_handle);
    }
}

#endif
/*****************************************************************************
 * FUNCTION
 *	mmi_java_ncenter_terminate
 * DESCRIPTION
 *	
 * PARAMETERS
 *	
 * RETURNS
 *
 *****************************************************************************/
extern "C" mmi_ret mmi_java_ncenter_terminate(mmi_event_struct *evt)	
{
    g_mmi_java_current_selected_vm_id = g_mmi_java_selected_ongoing_cell;
    jam_enter_terminate_mode(g_mmi_java_current_selected_vm_id);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ncenter_resume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
extern "C" mmi_ret mmi_java_ncenter_resume(mmi_event_struct *evt)
{
    if(jam_is_busy())
    {
        mmi_java_display_is_busy();
        return MMI_RET_OK;
    }
	
    if (jam_mvm_get_current_vm_id() != INVALIDE_VM_ID && jam_mvm_get_current_vm_id() != g_mmi_java_selected_ongoing_cell)
    {
        jam_enter_minimize_mode(jam_mvm_get_current_vm_id(), KAL_TRUE);
#ifdef __COSMOS_MMI_PACKAGE__
        vapp_java_close_venus_screen();
#endif
    }

    g_mmi_java_current_selected_vm_id = g_mmi_java_selected_ongoing_cell;
    mmi_java_update_mids_runtime_setting(g_mmi_java_current_selected_vm_id);
    jam_resume_screen();
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_ncenter_on_going_cell_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
extern "C" void mmi_java_ncenter_on_going_cell_callback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id = (kal_int32) (noti->getId());
    mmi_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(intent.type == VSRV_NINTENT_TYPE_LAUNCH)
    {
        if(jam_mvm_get_vm_state(vm_id) == JVM_TERMINATE_STATE ||
           jam_mvm_get_vm_state(vm_id) == JVM_TERMINATING_STATE)
        {
            return;
        }

        if (vm_id == -1)
        {
            return;
        }

        g_mmi_java_selected_ongoing_cell = vm_id;

        MMI_FRM_INIT_EVENT(&evt, 0);
        MMI_FRM_POST_EVENT(&evt, mmi_java_ncenter_resume, NULL);
    }
    else if(intent.type == VSRV_NINTENT_TYPE_TERMINATE)
    {
        g_mmi_java_selected_ongoing_cell = vm_id;
        MMI_FRM_INIT_EVENT(&evt, 0);
        MMI_FRM_POST_EVENT(&evt, mmi_java_ncenter_terminate, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_add_ncenter_on_going_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
extern "C" void mmi_java_ncenter_on_going_cell_add(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VsrvNGroupSingleTitle *group = NULL;
    VsrvNotificationOngoing *noti;
    kal_wchar *mid_name = NULL;
    kal_char *storage_name;
    kal_int32 handle = -1;
    VfxWChar *filename;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_JAVA));
#else
    VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (APP_JAVA));
#endif
    group->setTitle(VFX_WSTR_RES(STR_SCR_JAVA_CAPTION));
	
    VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationOngoing, ((VsrvNGroup*)group, vm_id));
    filename = (VfxWChar*)get_ctrl_buffer(sizeof(VfxWChar) * MAX_WCHAR_FILENAME_LEN);
    storage_name = jam_mvm_get_storage_name_by_vm_id(vm_id);
    kal_wsprintf(filename, "%s\\%s.icon", work_dir_path, storage_name);
    handle = FS_Open((VfxU16*) filename, FS_READ_ONLY | FS_OPEN_SHARED);
    if(handle == FS_FILE_NOT_FOUND)
    {
        noti->setIcon(VfxImageSrc(IMG_JAVA_STAR1));
    }
    else
    {
        noti->setIcon(VfxImageSrc((VfxWString)VFX_WSTR_MEM(filename)));
    }
    FS_Close(handle);
    free_ctrl_buffer(filename);
    mid_name = jam_mvm_get_vm_mid_name(vm_id);
    noti->setMainText(VFX_WSTR_MEM(mid_name));
    noti->setQuestionText(VFX_WSTR_RES(STR_JAVA_NCENTER_TERMINATE_JAVA_GAME));
    noti->setIntentCallback(&mmi_java_ncenter_on_going_cell_callback);
    noti->notify();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_remove_ncenter_on_going_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
extern "C" void mmi_java_ncenter_on_going_cell_remove(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    VSRV_NOTIFICATION_CLOSE_EX(VAPP_JAVA, vm_id);
#else
    VSRV_NOTIFICATION_CLOSE_EX(APP_JAVA, vm_id);
#endif
}

#endif /* __MMI_NCENTER_SUPPORT__ */
#endif /* __J2ME__ */
