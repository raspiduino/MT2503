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
 * JavaAgencyMidsInstall.c                           
 *                                        
 * Project:                               
 * --------                               
 *   MAUI                                 
 *                                        
 * Description:                           
 * ------------                           
 *   This file is intends to handle all scenario of Java Content Manager and              
 *   interaction betweens MMI and Java task.                                              
 *                                        
 * Author:                                
 * -------                                
 *
 *
 *******************************************************************************/         
                                          
#ifdef __J2ME__                           
#include "MMI_include.h"                  
#include "jal.h"
#include "jvm_adaptor.h"
#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
#include "jam_msg_handler.h"
#include "j2me_custom.h"
#include "jam_internal.h"
#include "CommonScreens.h"                  /* EntryScrForInputMethodAndDone */           
#include "SettingDefs.h"
#include "GpioSrvGprot.h"                        /* SRV_BACKLIGHT_SHORT_TIME */
#include "app_mine.h"                       /* MIME_SUBTYPE_JAD*/
#include "jam_internal.h"
#include "DLAgentSrvGProt.h"
#include "IdleGprot.h"
#include "app_str.h"
#ifdef __MMI_SCREEN_SAVER__
#include "ScrSaverGprot.h"
#endif
#include "drm_gprot.h"
#include "drm_def.h"
#include "RightsMgrGProt.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
#if( defined (__MMI_USB_SUPPORT__) && defined( __PLUTO_MMI_PACKAGE__ ))
#include "USBDeviceGprot.h"
#endif
#include "MyFavoriteResDef.h"
#include "idleappdef.h"

#include "timerevents.h"
#include "FileMgrSrvGProt.h"
#include "FilemgrCuiGprot.h"
#include "CommonScreensResDef.h"
#ifdef  __DM_SCOMO_SUPPORT__
#include "DmSrvGprot.h"
#include "SatAppGprot.h"
#endif /* __DM_SCOMO_SUPPORT__*/

#ifdef __PLUTO_MMI_PACKAGE__

#include "mmi_rp_app_downloadagent_def.h"
#ifndef __DISABLE_SHORTCUTS_IMPL__
#include "shortcutsGProts.h"
#include "ScrLockerGprot.h"
#endif

#endif

#include "JavaAppFactorySrvProt.h"
#include "AppMgrSrvGprot.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_java_srv.h"
#include "vapp_screen_lock_gprot.h"
#include "vapp_launcher_gprot.h"

#endif
#ifdef __MMI_NCENTER_SUPPORT__
#include "vapp_ncenter_gprot.h"
#endif
#ifdef MRE_VERSION  
#include "vmjava.h"
#endif
/*  notify state variables */
#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__ 
MMI_BOOL g_mmi_java_post_notify_result = MMI_TRUE;
#endif

mmi_java_abort_error_code_enum g_mmi_java_abort_error_code = MMI_JAVA_ABORT_NO_ERROR;
extern java_context_struct g_java;
U32 g_java_need_storage_size;
S32 g_java_need_storage_free_size;
S32 g_java_storage_drive = 0;
S32 g_mmi_java_install_mids_id = -1;
U8* g_mmi_java_current_installing_mids_name = NULL;
U8 g_mmi_java_install_progress;
U8 g_mmi_java_reinstall_state = 0;
MMI_BOOL g_mmi_java_is_background_display = MMI_FALSE;      /* indicate whether current install or remove is user*/                       
mmi_java_cmd_enum g_mmi_java_current_running_cmd = MMI_JAVA_CMD_END;

static java_cmd_state_enum g_mmi_java_cmd_state = JAVA_CMD_IDLE_STATE;
kal_int32 g_mmi_java_install_terminate_vm_id = -1;                                          
mmi_java_push_install_node_struct *g_mmi_java_push_install_start = NULL;
mmi_java_push_install_node_struct *g_mmi_java_push_install_end = NULL;
U8 g_mmi_java_push_install_count = 0;

CHAR g_java_current_install_app_name[MMI_APP_NAME_MAX_LEN];

void mmi_java_mids_install(               
        U16 *jad_file_name,               
        U16 *jar_file_name,               
        U16 *download_url,                
        MMI_BOOL delete);
void mmi_java_send_mids_install_req(U16 *jad_file_path, U16 *jar_file_path, U16 *download_url);
void mmi_java_send_at_loacl_install_cnf(S32 error_code);
void mmi_java_entry_mids_install_start(void);

extern MMI_BOOL mdi_audio_is_idle(void);
extern MMI_BOOL g_mmi_java_is_in_package;
extern U8 mmi_java_clean_list_related_screen_when_install(void);
extern void mmi_java_send_delete_menu_abort_req(void);  
extern U16 mmi_java_get_install_title_icon(void);
extern MMI_BOOL mmi_usb_webcam_is_active(void);
MMI_BOOL g_mmi_java_is_allow_push_install = KAL_TRUE;
#define MMI_JAVA_MAX_DRM_FILE_NAME SRV_FMGR_PATH_MAX_FILE_NAME_LEN
#define MMI_JAVA_MAX_INSTALL_URL_LENGTH (255)
void mmi_java_hide_install_file(U16* file_name);

extern kal_bool g_is_asm_allow_to_launch;
extern MMI_BOOL g_mmi_java_is_launching_midlet;
mmi_id  g_java_installer_cui_gid = GRP_ID_INVALID; 
extern kal_bool g_jam_user_update_setting_exclusive;

#ifdef __MMI_JAVA_INSTALL_PUSHINSTALL__
U16* g_mmi_java_install_drm_path_aquire_right = NULL;
U16* g_mmi_java_install_drm_path_push_install = NULL;
void mmi_java_register_push_install(U16* drm_file_path, S32 drm_serial);
static kal_bool g_mmi_java_push_install_timer_set = KAL_FALSE;

extern void mmi_java_entry_drm_acquire_right_confirm(void);
extern mmi_ret mmi_java_mids_entry_drm_acquire_right_proc(mmi_event_struct* evt);
extern void mmi_rmgr_send_rights_request(void);
extern void mmi_rmgr_request_rights_confirm_ext(U16 *confirm_string,kal_bool showimediately);

#endif //__MMI_JAVA_INSTALL_PUSHINSTALL__


#ifdef __MMI_JAVA_INSTALL_AUTHENTICATION__  
#define JAVA_CAPTION_USERNAME              CUI_INLINE_ITEM_ID_BASE+1
#define JAVA_TEXTEDIT_USERNAME            CUI_INLINE_ITEM_ID_BASE+2 
#define JAVA_CAPTION_PASSWORD            CUI_INLINE_ITEM_ID_BASE+3
#define JAVA_TEXTEDIT_PASSWORD          CUI_INLINE_ITEM_ID_BASE+4
mmi_id g_java_auth_inline;
static void mmi_java_auth_confirm_hdlr(void);
#endif

void mmi_java_send_get_install_drv_res(S8 drv);
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_is_installing                
 * DESCRIPTION                            
 *  To check if java is installing or updating MIDlet.                                    
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
MMI_BOOL mmi_java_is_installing(void)     
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
                                          
    return (MMI_BOOL)( g_java.mids_install_state > INSTALL_VALID_STATE ||                           
             g_java.mids_update_state > UPDATE_VALID_STATE ||g_mmi_java_reinstall_state > 0);                              
                                          
}                                         
static void mmi_java_mids_installer_group_close(void)
{
    mmi_frm_group_close(g_java_installer_cui_gid);
    g_java_installer_cui_gid = GRP_ID_INVALID;
}
mmi_ret mmi_java_mids_installer_group_close_proc(mmi_event_struct* evt)                           
{ 
    switch(evt->evt_id)                   
    {          
        case EVT_ID_POPUP_QUIT:   
            mmi_java_mids_installer_group_close();  
            break;                            
    }                                     
    return MMI_RET_OK;
}                                           
MMI_BOOL mmi_java_is_installing_by_dm(void)
{
   return (MMI_BOOL)(g_mmi_java_current_running_cmd == MMI_JAVA_CMD_INSTALL_BY_DM);
}
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_mids_install_clean_screen    
 * DESCRIPTION                            
 *                                        
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_mids_install_clean_screen(void)                                          
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    /* delete select disk screen of package */                                            
    mmi_java_mids_installer_group_close();
                                      
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_da_java_setting                   
 * DESCRIPTION                            
 *  Please refer to the comments for further detail.                                      
 *                                        
 *  (Old description)                     
 *  This setting is used for application want to control the file by itself               
 *  User cannot input filename and select drv.                                            
 *  Download agent will save the file into temp folder.                                   
 *  Application must move the file to suitable folder if they want reserve                
 *  the file. The temp folder would be deleted.                                           
 * PARAMETERS                             
 *  session_id          [IN]    Session ID
 *  mime_type           [IN]    applib_mime_type_enum                                     
 *  mime_subtype        [IN]    applib_mime_subtype_enum                                  
 *  action              [IN]    mmi_da_action_enum                                        
 *  filesize            [IN]    File size 
 *  url                 [IN]    URL: url[WAP_DL_MAX_URL_LEN]                              
 *  mime_type_string    [IN]    MIME type string: mime_type_string[WAP_DL_MAX_MIME_TYPE_LEN]                                              
 *  content_len         [IN]    Content-Length in HTTP header, may be 0.                  
 *  content             [IN]    Content in HTTP response, may be NULL                     
 *  setting             [OUT]   Appropriate behavior setting by previous information.     
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_da_java_setting(                 
        S32    session_id,                
        S32    mime_type,                 
        S32    mime_subtype,              
        S32 action,                       
        U32    filesize,                  
        CHAR*    url,                       
        CHAR*    mime_type_string,          
        U32    content_len,               
        CHAR*    content,                   
        srv_da_setting_struct *setting)   
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
                                          
    srv_da_bypass_setting(        
        session_id,
        mime_type,
        mime_subtype,
        action,
        filesize,
        url,
        mime_type_string,
        content_len,
        content,
        setting);
    /* Let DLAgent to decide the storage */
    setting->storage = SRV_DA_STORAGE_AUTO;
    setting->drv = 0;
                                          
    /* Let DLAgent to decide the filename */
    setting->default_filename = MMI_TRUE;
    setting->filename[0] = setting->filename[1] = L'\0';
                                          
    /* Folder & background download setting */
    switch (mime_subtype)
    {
        case MIME_SUBTYPE_JAD:
        case MIME_SUBTYPE_JAR:
            setting->can_minimize = MMI_FALSE; /* Only foreground is allowed */
            mmi_ucs2cpy((CHAR *)setting->folder, (CHAR *)FMGR_DEFAULT_FOLDER_RECEIVED);
            break;
                                          
        case MIME_SUBTYPE_ZDD:
            setting->can_minimize = MMI_FALSE; /* Only foreground is allowed */
            mmi_ucs2cpy((CHAR *)setting->folder, (CHAR *)FMGR_DEFAULT_FOLDER_TEMP);
            break;
                                          
        default:
            setting->can_minimize = MMI_TRUE; /* Background download is allowed */
            mmi_ucs2cpy((CHAR *)setting->folder, (CHAR *)FMGR_DEFAULT_FOLDER_TEMP);
            break;
    }
                                          
    /* Don't confirm with user before dispatch */
    setting->confirm_dispatch = MMI_FALSE;
                                          
    /* Popup when received via push. */
    setting->confirm_push = MMI_TRUE;
                                          
    /* Dispatch after file received. */
    setting->do_dispatch = MMI_TRUE;
                                          
    /* Not need to report during downloading. */
    setting->filepath_hdlr = NULL;
    setting->report_hdlr = NULL;
                                          
                                          
    /* --- OBSOLETE --- */                
    setting->bypass = MMI_DA_BYPASS_LEVEL_2;                                              
    setting->keepfile = MMI_FALSE;        
    setting->percentage_bar = MMI_TRUE;   
}                                         
                                          
mmi_ret mmi_java_da_setting_hdlr(mmi_event_struct *param)
{
    srv_da_setting_java_file_struct  *evt = (srv_da_setting_java_file_struct *)param;
    mmi_da_java_setting(evt->session_id, evt->mime_type, evt->mime_subtype, evt->action, evt->filesize, evt->url, evt->mime_type_string, evt->content_len, evt->content, evt->setting);
    return MMI_RET_OK;
}
                                          
static U16 *g_mmi_java_ota_url_buf = NULL;
static U16 *g_mmi_java_ota_file_path = NULL;
static S32  g_mmi_java_ota_mime_subtype = 0;
void mmi_java_receive_da_file_success_cb(void)
{
    if(g_mmi_java_ota_mime_subtype == MIME_SUBTYPE_JAD)  
    {  
        /* Local browser is treated as local install */                                   
        if (mmi_ucs2ncmp((CHAR *)g_mmi_java_ota_url_buf, (CHAR *)L"file", 4) == 0)                             
        {
            mmi_java_local_install_content_routing(g_mmi_java_ota_file_path); 
        }                                 
        else                              
        {
            g_mmi_java_current_running_cmd = MMI_JAVA_CMD_INSTALL_BY_USER;
            mmi_java_hide_install_file(g_mmi_java_ota_file_path);   
            mmi_java_mids_install(g_mmi_java_ota_file_path, NULL, g_mmi_java_ota_url_buf, MMI_TRUE);                 
        }                                 
    }                                     
    else                                  
    {                                     
        g_mmi_java_current_running_cmd = MMI_JAVA_CMD_INSTALL_BY_USER;                    
        mmi_java_hide_install_file(g_mmi_java_ota_file_path);                                            
        mmi_java_mids_install(NULL, g_mmi_java_ota_file_path, g_mmi_java_ota_url_buf, MMI_TRUE);                     
    } 
    if(g_mmi_java_ota_url_buf)
    {
        free_ctrl_buffer(g_mmi_java_ota_url_buf);   
        g_mmi_java_ota_url_buf = NULL;
    }    
    if(g_mmi_java_ota_file_path)
    {
        free_ctrl_buffer(g_mmi_java_ota_file_path);   
        g_mmi_java_ota_file_path = NULL;
    }
}

mmi_ret mmi_java_receive_da_file_success_proc(mmi_event_struct* evt)                           
{ 
    switch(evt->evt_id)                   
    {          
        case EVT_ID_POPUP_QUIT:   
            mmi_java_receive_da_file_success_cb();  
            break;                            
    }                                     
    return MMI_RET_OK;
}  
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_receive_da_file              
 * DESCRIPTION                            
 *  handler function:  Download agent send a jad/jar file to MMI                          
 * PARAMETERS                             
 *  mime_type           [IN]              
 *  mime_subtype        [IN]              
 *  action              [IN]              
 *  file_path           [IN]              
 *  url                 [IN]              
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_receive_da_file (S32 session_id, S32 mime_type, S32 mime_subtype,S32 action, PU16 file_path, CHAR * url, CHAR * mime_type_string) 
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    S32 url_length;                       
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if(g_mmi_java_current_running_cmd != MMI_JAVA_CMD_END)                                
    {                                     
#ifdef __PLUTO_MMI_PACKAGE__
        mmi_java_display_is_busy();       
#elif __COSMOS_MMI_PACKAGE__
        vapp_java_display_popup(STR_ID_VAPP_JAVA_VM_BUSY,VJAVA_POPUP_WARNING,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
#endif
        if (!mmi_java_is_drm_file(file_path))                                             
        {                                 
            FS_Delete((WCHAR *)file_path);
        }                                 
        return;                           
    }                                     
    g_mmi_java_is_background_display = KAL_FALSE;                                         
#ifdef __MMI_USB_SUPPORT__             
    if (srv_usb_is_in_mass_storage_mode())
    {                                     
        /* in mass storage mode */    
        #ifdef __PLUTO_MMI_PACKAGE__
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */ 
        #endif
        if (!mmi_java_is_drm_file(file_path))                                             
        {                                 
            FS_Delete((WCHAR *)file_path);
        }                                 
        return;                           
    }                                     
#endif /* __USB_IN_NORMAL_MODE__ */       
                                          
    if (mmi_java_need_block_msg())        
    {                                     
        #ifdef __PLUTO_MMI_PACKAGE__
        {
            mmi_popup_property_struct arg;
            mmi_popup_property_init(&arg);
            mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)), MMI_EVENT_FAILURE, &arg);
            mmi_java_mids_installer_group_close();
        }                         
        #elif __COSMOS_MMI_PACKAGE__
        vapp_java_display_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
        #else
            ASSERT(0);
        #endif

        
        if (!mmi_java_is_drm_file(file_path))                                             
        {                                 
            FS_Delete((WCHAR *)file_path);
        }                                 
        return;                           
    }
    if(url)
    {
        url_length = strlen(url);             
        g_mmi_java_ota_url_buf = (U16*)get_ctrl_buffer((url_length+1) * ENCODING_LENGTH);
        kal_wsprintf(g_mmi_java_ota_url_buf,"%s",url);
    }
    else
    {
        g_mmi_java_ota_url_buf = (U16*)get_ctrl_buffer((10) * ENCODING_LENGTH);
        kal_wsprintf(g_mmi_java_ota_url_buf,"%s","file://");
    }
    g_mmi_java_ota_mime_subtype = mime_subtype;
    g_mmi_java_ota_file_path = (U16*)get_ctrl_buffer((app_ucs2_strlen((const kal_int8*)file_path)+1) * ENCODING_LENGTH);
    app_ucs2_strcpy((kal_int8*)g_mmi_java_ota_file_path,(const kal_int8*)file_path);
#ifdef __OP01__
    {                                     
        mmi_popup_property_struct arg;
        mmi_popup_property_init(&arg);
        arg.callback = mmi_java_receive_da_file_success_proc;
        if(g_mmi_java_ota_mime_subtype == MIME_SUBTYPE_JAD)
        {                                 
            mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_JAVA_JAD_DOWNLOAD_SUCCESS)), MMI_EVENT_SUCCESS, &arg);
        }                                 
        else                              
        {                                 
            mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_JAVA_JAR_DOWNLOAD_SUCCESS)), MMI_EVENT_SUCCESS, &arg);
        }                                 
    }                                     
#else
    mmi_java_receive_da_file_success_cb();
#endif
#ifdef __MMI_JAVA_BACK_UP_DOWNLOAD_MIDS_FILE__  // backup download jad to phonedisk for debug
    {
        kal_wchar jad_name_buffer[30];
        if(mime_subtype == MIME_SUBTYPE_JAD)
        {
            kal_wsprintf(jad_name_buffer, "%c:\\%s\0", SRV_FMGR_PUBLIC_DRV,"temp.jad");
        }
        else
        {
            kal_wsprintf(jad_name_buffer, "%c:\\%s\0", SRV_FMGR_PUBLIC_DRV,"temp.jar");
        }
        FS_Move(file_path, jad_name_buffer, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);
    }
#endif
    return;                               
}                                         
                                          
mmi_ret mmi_java_recieve_da_file_hdlr(mmi_event_struct *param)
{
    srv_da_receive_java_file_struct  *evt = (srv_da_receive_java_file_struct*) param;
    mmi_java_receive_da_file (evt->session_id, evt->mime_type, evt->mime_subtype, evt->action, evt->file_path, evt->url,  evt->mime_type_string);
    return MMI_RET_OK;
}

/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_mids_install_delete_callback 
 * DESCRIPTION                            
 *  Send abort message to VM to terminate installing                                      
 * PARAMETERS                             
 *  in_param    [IN]    no use here       
 * RETURNS                                
 *  return if we want to stop delete the screen                                           
 *****************************************************************************/           
U8 mmi_java_mids_install_delete_callback(void *in_param)                                  
{                                         
    if (( g_java.mids_install_state > INSTALL_VALID_STATE &&                              
           g_java.mids_install_state != INSTALL_ABORT_STATE)    ||                        
         ( g_java.mids_update_state > UPDATE_VALID_STATE &&                               
           g_java.mids_update_state != UPDATE_ABORT_STATE))                               
    {                                     
        /* for terminate FS_MOVE */       
        jam_stop_FS_action();             
        mmi_java_send_java_abort_req();   
                                          
    }                                     
    return MMI_FALSE;                     
}                                         
void mmi_java_mids_install_abort(void)
{
    if(g_mmi_java_reinstall_state > 0)
    {
        mmi_java_send_delete_menu_abort_req();
    }
    else
    {
        mmi_java_mids_install_delete_callback(NULL);
    }
    g_java.screen_after_terminate = TER_ENTRY_NONE;
}
U16 *mmi_jad_file_name;            
U16 *mmi_jar_file_name;            
U16 *mmi_download_url;             
MMI_BOOL  mmi_delete_after_install_fail = MMI_FALSE;                               
static U16 *mmi_saved_jad_file_name;      
static U16 *mmi_saved_jar_file_name;      
static U16 *mmi_saved_download_url;       
static mmi_java_cmd_enum mmi_saved_current_java_cmd = MMI_JAVA_CMD_END;                                   
static MMI_BOOL  mmi_saved_delete_after_install_fail = MMI_FALSE;                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_remove_temp_install_file     
 * DESCRIPTION                            
 *                                        
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_remove_temp_install_file(void)                                              
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    S32  returnCode;                      
    S32 handle = 0;                       
    U16 *dummy;                           
    FS_DOSDirEntry fileInfo;              
    U16 *pszUCS2Filename = NULL;          
    S32 str_len;                          
    S32 dir_len;                          
    U8 test_drive;                        
    U16 *delete_file_path = NULL;         
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    dummy = (kal_wchar*)get_ctrl_buffer(512);                                             
    pszUCS2Filename = get_ctrl_buffer((mmi_ucs2strlen((CHAR *)FMGR_DEFAULT_FOLDER_RECEIVED) +5)<<1);                                         
    kal_wsprintf(pszUCS2Filename,"C:\\\0");                                               
    mmi_ucs2cat((CHAR *)pszUCS2Filename,(CHAR *)FMGR_DEFAULT_FOLDER_RECEIVED);                  
    mmi_ucs2cat((CHAR *)pszUCS2Filename,(CHAR *)L"*");                                          
                                          
    for (test_drive = 'A'; test_drive < 'Z'; test_drive ++)                               
    {                                     
        pszUCS2Filename[0] = test_drive;  
                                          
        handle = FS_FindFirst(pszUCS2Filename, 0, NULL, &fileInfo, dummy, 512);           
        if (handle < 0)                   
        {                                 
           continue;                      
        }                                 
        else                              
        {                                 
            do                            
            {                             
                if(!(fileInfo.Attributes & FS_ATTR_DIR) && (fileInfo.Attributes & FS_ATTR_HIDDEN))                                        
                {                         
                    str_len = mmi_ucs2strlen((CHAR *)dummy);                                 
                    if(!mmi_ucs2cmp((CHAR *)(dummy + str_len - 4), (CHAR *)(L".jad")) ||        
                        !mmi_ucs2cmp((CHAR *)(dummy + str_len - 4), (CHAR *)(L".JAD")) ||       
                        !mmi_ucs2cmp((CHAR *)(dummy + str_len - 4), (CHAR *)(L".jar")) ||       
                        !mmi_ucs2cmp((CHAR *)(dummy + str_len - 4), (CHAR *)(L".JAR")))         
                    {                     
                        dir_len =  mmi_ucs2strlen((CHAR *)pszUCS2Filename);                  
                        delete_file_path = get_ctrl_buffer((dir_len+str_len+1)<<1);       
                        mmi_ucs2cpy((CHAR *)delete_file_path,(CHAR *)pszUCS2Filename);          
                        delete_file_path[dir_len-1] = L'\0';                              
                        mmi_ucs2cat((CHAR *)delete_file_path,(CHAR *)dummy);                    
                        FS_Delete(delete_file_path);                                      
                        free_ctrl_buffer(delete_file_path);                               
                    }                     
                }                         
                returnCode = FS_FindNext(handle, &fileInfo, dummy, 512);                  
             } while(returnCode == FS_NO_ERROR);                                          
            if (handle > 0)               
            {                             
                 FS_FindClose(handle);    
            }                             
        }                                 
    }                                     
          
    if (pszUCS2Filename)                  
    {                                     
        free_ctrl_buffer(pszUCS2Filename);
    }                                     
    if (dummy)                            
    {                                     
        free_ctrl_buffer(dummy);          
    }                                     
    if (handle > 0)                       
    {                                     
        FS_FindClose(handle);             
    }                                     
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_hide_install_file            
 * DESCRIPTION                            
 *                                        
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_hide_install_file(U16* file_name)                                           
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    kal_int32 attribute;                  
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    attribute = FS_GetAttributes(file_name);                                              
    FS_SetAttributes(file_name, (BYTE) (attribute | (FS_ATTR_HIDDEN)));                   
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_unhide_install_file          
 * DESCRIPTION                            
 *                                        
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_unhide_install_file(void)   
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    kal_int32 attribute;                  
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if(mmi_jad_file_name)                 
    {                                     
        attribute = FS_GetAttributes(mmi_jad_file_name);                                  
        FS_SetAttributes(mmi_jad_file_name, (BYTE) (attribute & (~FS_ATTR_HIDDEN)));      
    }                                     
                                          
    if(mmi_jar_file_name)                 
    {                                     
        attribute = FS_GetAttributes(mmi_jar_file_name);                                  
        FS_SetAttributes(mmi_jar_file_name, (BYTE) (attribute & (~FS_ATTR_HIDDEN)));      
    }                                     
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_clear_install_info           
 * DESCRIPTION                            
 *  clear the install information         
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_clear_install_info(void)    
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if(mmi_jad_file_name)                 
    {                                     
        if(mmi_delete_after_install_fail) 
        {                                 
            FS_Delete(mmi_jad_file_name); 
        }                                 
        free_ctrl_buffer(mmi_jad_file_name);                                              
    }                                     
    if(mmi_jar_file_name)                 
    {                                     
        if(mmi_delete_after_install_fail) 
        {                                 
            FS_Delete(mmi_jar_file_name); 
        }                                 
        free_ctrl_buffer(mmi_jar_file_name);                                              
    }                                     
    if(mmi_download_url)                  
    {                                     
        free_ctrl_buffer(mmi_download_url);                                               
    }                                     
                                          
    mmi_jad_file_name = mmi_jar_file_name = mmi_download_url = NULL;                      
    mmi_delete_after_install_fail = MMI_FALSE;                                            
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_clear_saved_install_info     
 * DESCRIPTION                            
 *  Clear saved install information       
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_clear_saved_install_info(void)                                              
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
                                          
    if(mmi_saved_jad_file_name)           
    {                                     
        free_ctrl_buffer(mmi_saved_jad_file_name);                                        
    }                                     
    if(mmi_saved_jar_file_name)           
    {                                     
        free_ctrl_buffer(mmi_saved_jar_file_name);                                        
    }                                     
    if(mmi_saved_download_url)            
    {                                     
        free_ctrl_buffer(mmi_saved_download_url);                                         
    }                                     
                                          
    mmi_saved_jad_file_name = mmi_saved_jar_file_name = mmi_saved_download_url = NULL;    
    mmi_saved_delete_after_install_fail = MMI_FALSE;                                      
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_set_allow_push_install       
 * DESCRIPTION                            
 *  when the right of pre-install jar is received, ask user want to continue              
 *  install or not.                       
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_set_allow_push_install(MMI_BOOL set)                                        
{                                         
    g_mmi_java_is_allow_push_install = set;                                               
}

/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_set_install_info             
 * DESCRIPTION                            
 *  setup the install information         
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_set_install_info(           
    U16 *jad_file_name,                   
    U16 *jar_file_name,                   
    U16 *download_url,                    
    MMI_BOOL  delete)                     
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
                                          
    mmi_java_clear_install_info();        
                                          
    if(jad_file_name)                     
    {                                     
        mmi_jad_file_name = (U16*)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)jad_file_name)+1) * ENCODING_LENGTH);                              
        mmi_ucs2cpy((CHAR *)mmi_jad_file_name, (CHAR *)jad_file_name);                          
    }                                     
    if(jar_file_name)                     
    {                                     
        mmi_jar_file_name = (U16*)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)jar_file_name)+1) * ENCODING_LENGTH);                              
        mmi_ucs2cpy((CHAR *)mmi_jar_file_name, (CHAR *)jar_file_name);                          
    }                                     
                                          
    if(download_url)                      
    {                                     
        mmi_download_url = (U16*)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)download_url)+1) * ENCODING_LENGTH);                                
        mmi_ucs2cpy((CHAR *)mmi_download_url, (CHAR *)download_url);                            
    }                                     
    mmi_delete_after_install_fail = delete;                                               
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_backup_install_information   
 * DESCRIPTION                            
 *  backup information for next installation after delete                                 
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_backup_install_information(void)                                            
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_GET_JAVA_APP_MIDS_INDEX);                          
    mmi_java_clear_saved_install_info();  
                                          
    if(mmi_jad_file_name)                 
    {                                     
        mmi_saved_jad_file_name = (U16 *)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)mmi_jad_file_name)+1) * ENCODING_LENGTH);                   
        mmi_ucs2cpy((CHAR *)mmi_saved_jad_file_name, (CHAR *)mmi_jad_file_name);                
    }                                     
    if(mmi_jar_file_name)                 
    {                                     
        mmi_saved_jar_file_name = (U16 *)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)mmi_jar_file_name)+1) * ENCODING_LENGTH);                   
        mmi_ucs2cpy((CHAR *)mmi_saved_jar_file_name, (CHAR *)mmi_jar_file_name);                
    }                                     
                                          
    if(mmi_download_url)                  
    {                                     
        mmi_saved_download_url = (U16 *)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)mmi_download_url)+1) * ENCODING_LENGTH);                     
        mmi_ucs2cpy((CHAR *)mmi_saved_download_url, (CHAR *)mmi_download_url);                  
    }                                     
    mmi_saved_current_java_cmd = g_mmi_java_current_running_cmd;                          
    mmi_saved_delete_after_install_fail = mmi_delete_after_install_fail;                  
                                          
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_restore_install_information  
 * DESCRIPTION                            
 *  restore information for next installation after delete                                
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
/* void mmi_java_get_mids_index(S32 nIndex) */                                            
void mmi_java_restore_install_information(void)                                           
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_GET_JAVA_APP_MIDS_INDEX);                          
    //mmi_java_clear_install_info();      
                                          
    if(mmi_saved_jad_file_name)           
    {                                     
        mmi_jad_file_name = (U16 *)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)mmi_saved_jad_file_name)+1) * ENCODING_LENGTH);                   
        mmi_ucs2cpy((CHAR *)mmi_jad_file_name, (CHAR *)mmi_saved_jad_file_name);                
    }                                     
    if(mmi_saved_jar_file_name)           
    {                                     
        mmi_jar_file_name = (U16 *)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)mmi_saved_jar_file_name)+1) * ENCODING_LENGTH);                   
        mmi_ucs2cpy((CHAR *)mmi_jar_file_name, (CHAR *)mmi_saved_jar_file_name);                
    }                                     
                                          
    if(mmi_saved_download_url)            
    {                                     
        mmi_download_url = (U16 *)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)mmi_saved_download_url)+1) * ENCODING_LENGTH);                     
        mmi_ucs2cpy((CHAR *)mmi_download_url, (CHAR *)mmi_saved_download_url);                  
    }                                     
    mmi_delete_after_install_fail = mmi_saved_delete_after_install_fail;                  
    g_mmi_java_current_running_cmd =   mmi_saved_current_java_cmd;                        
                                          
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_set_jad_file_name            
 * DESCRIPTION                            
 *  set mmi_jar_file_name when using jad OTA installation.                                
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_set_jad_file_name(U16* jad_path)                                            
{                                         
    if (jad_path)                         
    {                                     
        mmi_jad_file_name = (U16*)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)jad_path)+1) * ENCODING_LENGTH);                                   
        mmi_ucs2cpy((CHAR *)mmi_jad_file_name, (CHAR *)jad_path);                               
    }                                     
                                          
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_set_jar_file_name            
 * DESCRIPTION                            
 *  set mmi_jar_file_name when using jad OTA installation.                                
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_set_jar_file_name(U16* jar_path)                                            
{                                         
    if (jar_path)                         
    {                                     
        if (mmi_jar_file_name)            
        {                                 
            free_ctrl_buffer(mmi_jar_file_name);                                          
        }                                 
        mmi_jar_file_name = (U16*)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)jar_path)+1) * ENCODING_LENGTH);                                   
        mmi_ucs2cpy((CHAR *)mmi_jar_file_name, (CHAR *)jar_path);                               
    }                                     
                                          
}
/*****************************************************************************            
 * FUNCTION                               
 * DESCRIPTION                            
 * PARAMETERS                             
 * RETURNS                                
 *****************************************************************************/           
void mmi_java_mids_install_internal(void) 
{           
    g_java.install_progress = 0;  
    if (g_mmi_java_reinstall_state > 0)   
    {                                     
        if (g_java.install_progress < g_mmi_java_install_progress)                        
        {                                 
            g_java.install_progress = g_mmi_java_install_progress;                        
        }
        
    }
    if (g_mmi_java_reinstall_state == 0)                                    
    {                                     
        if (g_mmi_java_current_installing_mids_name)                                      
        {                                 
            free_ctrl_buffer(g_mmi_java_current_installing_mids_name);                    
        }                                 
        g_mmi_java_current_installing_mids_name = NULL;                                   
    } 
    if(!g_mmi_java_is_background_display)                                         
    {                             
        #ifdef __PLUTO_MMI_PACKAGE__
        mmi_java_entry_mids_install_start();                                      
        #elif __COSMOS_MMI_PACKAGE__
        vapp_java_entry_mids_install_start();
        #else
        ASSERT(0);
        #endif
    }
    else
    {
        mmi_java_mids_install_request_start();
    }                          
                             
}                 
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_mids_install_request_start
 * DESCRIPTION                            
 *  This App must be called after UI start successfully.          
 * PARAMETERS                             
 *  void
 * RETURNS                                
 *  void                                  
 *****************************************************************************/  
void mmi_java_mids_install_request_start(void)
{
    if(g_mmi_java_reinstall_state != 0)
    {
        g_mmi_java_reinstall_state = 0;
    }                                    
    if (mmi_jad_file_name)        
    {                             
        g_java.is_jad_file_install = MMI_TRUE;                                    
        mmi_java_send_mids_install_req(mmi_jad_file_name, mmi_jar_file_name, mmi_download_url);                                   
    }                             
    else                          
    {                             
        g_java.is_jad_file_install = MMI_FALSE;                                   
        mmi_java_send_mids_install_req(mmi_jad_file_name, mmi_jar_file_name, mmi_download_url);                                   
    }                             
    /* suspend background play */ 
    mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_JAVA);            
                    
    if (g_java.is_jad_file_install)                                               
    {                             
        g_java.mids_install_state = INSTALL_JAD_DOWNLOAD_STATE;                   
    }                             
    else                          
    {                             
        g_java.mids_install_state = INSTALL_JAR_DOWNLOAD_STATE;                   
    }                             
    g_java.mids_update_state = UPDATE_INVALID_STATE;    

}
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_mids_install_ask_terminate_cb
 * DESCRIPTION                            
 *  Callback function to handle           
 *  Ask user if they want to terminate VM first before install MIDlet                     
 * PARAMETERS                             
 *  teminate    [IN]    user select yes/No
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_mids_install_ask_terminate_cb(MMI_BOOL terminate)                           
{                                         
    if(terminate)                         
    {                                     
        g_mmi_java_abort_error_code = MMI_JAVA_ABORT_NO_ERROR;
        g_java.screen_after_terminate = TER_ENTRY_INSTALL_JAVA;
        jam_enter_terminate_mode(g_mmi_java_install_terminate_vm_id);
        mmi_java_entry_terminating(MMI_FALSE);                                            
    }                                     
    else                                  
    {                                     
        g_mmi_java_abort_error_code = MMI_JAVA_ABORT_FOR_USER_CANCELED;
        g_java.screen_after_terminate = TER_ENTRY_NONE;
        if(jam_mvm_is_vm_running(g_mmi_java_install_terminate_vm_id)||jam_mvm_is_vm_terminating(g_mmi_java_install_terminate_vm_id)){       
            g_mmi_java_abort_error_code = MMI_JAVA_ABORT_FOR_USER_CANCELED;               
        }
        /* send to java cancel */     
        mmi_java_send_delete_menu_abort_req();                                        
        g_mmi_java_install_terminate_vm_id = -1;
    }                                         
}
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_mids_install                 
 * DESCRIPTION                            
 *  This routines handles MMI_JAVA_INSTALL_MIDS_IND from MOD_J2ME to                      
 *  indicate user whether installation process is successful                              
 * PARAMETERS                             
 *  session_id          [IN]              
 *  jad_file_name       [?]               
 *  jar_file_name       [?]               
 *  download_url        [?]               
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_mids_install(               
        U16 *jad_file_name,               
        U16 *jar_file_name,               
        U16 *download_url,                
        MMI_BOOL delete)                  
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
                                          
    if (g_java.mids_install_state != INSTALL_VALID_STATE                                  
        || g_java.mids_delete_state != DELETE_VALID_STATE                                 
        || g_java.mids_update_state != UPDATE_VALID_STATE                                 
        || g_mmi_java_reinstall_state > 0 
        || (g_java.msg_ctrl & SEND_MID_SET_SETTING_CTRL)                                  
        || g_mmi_java_is_in_package       
        || jam_is_busy()
        || jam_mvm_is_shutdowning())            
    {                                     
        #ifdef __PLUTO_MMI_PACKAGE__
        mmi_java_display_is_busy();       
        #elif __COSMOS_MMI_PACKAGE__
        vapp_java_display_popup(STR_ID_VAPP_JAVA_VM_BUSY,VJAVA_POPUP_WARNING,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
        #else
        ASSERT(0);
        #endif
        if(delete)                        
        {                                 
            if(jad_file_name)             
            {                             
                FS_Delete((WCHAR*)jad_file_name);                                         
            }                             
            if(jar_file_name)             
            {                             
                FS_Delete((WCHAR*)jar_file_name);                                         
            }                             
        }                                 
        mmi_java_report_status(g_mmi_java_current_running_cmd,J2ME_USER_CANCEL,NULL,NULL,NULL);                                           
        return;                           
    }                                     
                                          
                                          
    mmi_java_set_install_info(jad_file_name, jar_file_name, download_url, delete);        
                                          
#if (!defined(__SUPPORT_NATIVE_INSTALLER__)||defined(J2ME_SLIM_MEMORY_SUPPORT))
    if (jam_mvm_is_vm_running(0)||jam_mvm_is_vm_terminating(0))
    {                                
        g_mmi_java_install_terminate_vm_id = 0;
        g_java.screen_after_terminate = TER_ENTRY_INSTALL_JAVA;
        g_mmi_java_reinstall_state = 1;
        #ifdef __PLUTO_MMI_PACKAGE__
        mmi_java_entry_cb_terminate_dialog(mmi_java_mids_install_ask_terminate_cb, (U16*)GetString(STR_JAVA_TERMINATE_JAVA_GAME),1);  
        #elif __COSMOS_MMI_PACKAGE__
        vapp_java_entry_terminate_vm_confirm();
        #else
        #endif
                         
        return;                           
    }                                     
#endif /* J2ME_SUPPORT_PAUSE */           
    mmi_java_mids_install_internal();     
    return;                               
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_send_mids_install_req        
 * DESCRIPTION                            
 *  Send message "MMI_JAVA_SEND_INSTALL_MIDS_REQ" to java                                 
 * PARAMETERS                             
 *  jad_file_path           [?]           
 *  jar_file_path           [?]           
 *  download_url            [IN]        The url where we can update MIDlet                
 *  jad_file(?)             [IN]        If this MIDLet is a jad file                      
 *  file_path_name(?)       [IN]        The file path where we save in file system        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_send_mids_install_req(U16 *jad_file_path, U16 *jar_file_path, U16 *download_url)                                            
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_install_mids_req_struct *msg;
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_INSTALL_MIDS_REQ);                            
                                          
    /* g_java.is_jad_file_install = jad_file_path == NULL ? KAL_FALSE : KAL_TRUE ; */     
                                          
    msg = (mmi_java_install_mids_req_struct*) OslConstructDataPtr(sizeof(mmi_java_install_mids_req_struct));                              
                                          
    msg->jad_file_path = msg->jar_file_path = msg->download_url = NULL;                   
                                          
    if(jad_file_path)                     
    {                                     
        msg->jad_file_path = (kal_wchar *) get_ctrl_buffer( (mmi_ucs2strlen((CHAR *)jad_file_path) +1 )* ENCODING_LENGTH );                  
        mmi_ucs2cpy((CHAR *)msg->jad_file_path, (CHAR *)jad_file_path);                         
    }                                     
                                          
    if(jar_file_path)                     
    {                                     
        msg->jar_file_path = (kal_wchar *) get_ctrl_buffer( (mmi_ucs2strlen((CHAR *)jar_file_path) +1 )* ENCODING_LENGTH );                  
        mmi_ucs2cpy((CHAR *)msg->jar_file_path, (CHAR *)jar_file_path);                         
    }                                     
                                          
    if(download_url)                      
    {                                     
        msg->download_url =  (kal_wchar *) get_ctrl_buffer( (mmi_ucs2strlen((CHAR *)download_url) +1 )* ENCODING_LENGTH );                   
        mmi_ucs2cpy((CHAR *)msg->download_url, (CHAR *)download_url);                           
    }                                     
                                          
    mmi_java_send_message_from_active_mod( MOD_JAM,                                               
        MMI_J2ME_SAP,MSG_ID_MMI_JAVA_INSTALL_MIDS_REQ, msg);                        
}                                         
#ifdef __PLUTO_MMI_PACKAGE__
/*****************************************************************************            
 * mmi_java_mids_install_group_proc
 * DESCRIPTION                            
 *  Create app group                      
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
mmi_ret mmi_java_mids_install_group_proc(mmi_event_struct* evt)                           
{
    switch(evt->evt_id)                   
    {          
        case EVT_ID_GROUP_DEINIT:
            mmi_java_mids_install_delete_callback(NULL);
            mmi_java_mids_installer_group_close();
            break;
         case EVT_ID_CUI_INLINE_ABORT:
            mmi_java_send_java_abort_req();
#ifdef __MMI_JAVA_INSTALL_AUTHENTICATION__              
            cui_inline_close(g_java_auth_inline);
            break;            
        case EVT_ID_CUI_INLINE_SUBMIT:
            mmi_java_auth_confirm_hdlr();
#endif
            break;
        case EVT_ID_IDLE_GROUP_EXIT:
#if defined(__DM_SCOMO_SUPPORT__)
           mmi_java_dmui_scomo_exit_idle_cb();
#endif /*__DM_SCOMO_SUPPORT__ */ 
        break;
        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
            mmi_java_send_get_install_drv_res(((cui_storage_selector_result_event_struct*)evt)->result);
            cui_storage_selector_close(((cui_storage_selector_result_event_struct*)evt)->sender_id);
        break;
#ifdef __MMI_NCENTER_SUPPORT__
        case EVT_ID_VAPP_NCENTER_DRAG:
            return MMI_RET_ERR;
#endif
    }                                     
    return MMI_RET_OK;                    
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_mids_installer_create_group              
 * DESCRIPTION                            
 *  Create app group                      
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
mmi_id mmi_java_mids_installer_create_group(void)                                         
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_id temp_parent_gid;               
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    temp_parent_gid = mmi_frm_group_create_ex(GRP_ID_ROOT,GRP_ID_AUTO_GEN,mmi_java_mids_install_group_proc,NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (temp_parent_gid == GRP_ID_INVALID)
    {                                     
        mmi_frm_group_close(temp_parent_gid);                                             
    }                                     
    return temp_parent_gid;               
} 
extern void mmi_java_entry_launch_after_install_confirm(void);

mmi_ret mmi_java_mids_entry_after_install_proc(mmi_event_struct* evt)                           
{ 
    switch(evt->evt_id)                   
    {          
        case EVT_ID_POPUP_QUIT:   
    #ifdef __MMI_JAVA_LAUNCH_AFTER_INSTALL__
            if(g_mmi_java_install_mids_id>0 &&
                mmi_java_is_allow_to_popup_screen())
            {
                mmi_java_entry_launch_after_install_confirm();  
            }
    #endif /*__MMI_JAVA_LAUNCH_AFTER_INSTALL__*/
            mmi_java_mids_installer_group_close();
            break;                            
    }                                     
    return MMI_RET_OK;   

}

void mmi_java_entry_install_progress_bar(void)
{
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    U8* guiBuffer;                        
    PU8 image_ptr;
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if(g_java_installer_cui_gid == GRP_ID_INVALID)    
    {                                     
        g_java_installer_cui_gid = mmi_java_mids_installer_create_group();                
    }
 
    if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_START_INSTALLING, NULL, mmi_java_entry_install_progress_bar, MMI_FRM_FULL_SCRN))                                             
    {                                     
        return;                           
    }                                     
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_java_installer_cui_gid, SCR_JAVA_START_INSTALLING);                                            
#ifndef J2ME_SLIM_MEMORY_SUPPORT
    image_ptr = (PU8)GetImage(IMG_JAVA_LOADING);
#else
    image_ptr = NULL;
#endif
    ShowCategory412Screen(                
        (UI_string_type)GetString(STR_JAVA_START_INSTALLING),                             
        (PU8)GetImage(mmi_java_get_install_title_icon()),                                 
        NULL,                             
        NULL,                             
        (UI_string_type)GetString(STR_GLOBAL_CANCEL),                                     
        (PU8)GetImage(IMG_GLOBAL_BACK),   
        image_ptr,  
        (UI_string_type)GetString(STR_JAVA_VM_INSTALLING),                                
        g_java.install_progress,          
        (g_mmi_java_current_installing_mids_name!=NULL?1:0),                   
        (UI_string_type*)&g_mmi_java_current_installing_mids_name,                        
        guiBuffer);                       
                                          
    SetRightSoftkeyFunction(mmi_java_mids_install_abort, KEY_EVENT_UP); 
}
#endif
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_mids_install_start     
 * DESCRIPTION                            
 *  show a screen to indicate user JAD file or JAR file is downloading                    
 *  and start to install                  
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_entry_mids_install_start(void)                                              
{                                         
#ifdef __PLUTO_MMI_PACKAGE__
    mmi_java_entry_install_progress_bar();
    mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_JAVA); 
    mmi_java_mids_install_request_start();
#endif    
}                                         
void mmi_java_update_install_progress_bar(kal_int8 progress)
{
#ifdef __PLUTO_MMI_PACKAGE__
    if (mmi_frm_scrn_get_active_id() == SCR_JAVA_START_INSTALLING)                    
    {
        Cat412UpdateList(         
            (UI_string_type)GetString(STR_JAVA_VM_INSTALLING),                    
            progress,
            (g_mmi_java_current_installing_mids_name != NULL? 1:0),       
            (UI_string_type*)&g_mmi_java_current_installing_mids_name);
    }  
#endif
}
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_show_percentage_ind     
 * DESCRIPTION                            
 * PARAMETERS                             
 *  MsgStruct       [?]                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_install_progress_ind(void *MsgStruct)                                  
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_install_progress_ind_struct *msg = (mmi_java_install_progress_ind_struct*) MsgStruct;                                        
    kal_int8 progress;                          
    S32 str_length;                       
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if(g_mmi_java_is_background_display)  
    {                                     
        if (msg->list_of_items)           
        {                                 
            free_ctrl_buffer(msg->list_of_items);                                         
        }                                 
        return;                           
    }                                     
    if (g_mmi_java_current_installing_mids_name == NULL)                                  
    {                                     
        if(msg->list_of_items != NULL)    
        {                                 
            str_length = mmi_ucs2strlen((CHAR *)msg->list_of_items[0]);                      
            if (str_length > UI_device_width)                                             
            {                             
                str_length = UI_device_width;                                             
            }                             
            g_mmi_java_current_installing_mids_name = get_ctrl_buffer( (str_length + 1) * sizeof(kal_wchar));                             
            mmi_ucs2ncpy((CHAR *)g_mmi_java_current_installing_mids_name, (CHAR *)msg->list_of_items[0], str_length);                           
        }                                 
    }                                     
                                          
    if (msg->list_of_items)               
    {                                     
        free_ctrl_buffer(msg->list_of_items);                                             
    }                                     
                                          
    if  (g_java.mids_install_state > INSTALL_VALID_STATE ||                               
         g_java.mids_update_state > UPDATE_VALID_STATE )                                  
    {                                     
        if (msg->value >= 100)            
        {                                 
            progress = 100;                
        }                                 
        else                              
        {                                 
            progress = msg->value;        
        }                                 
                          
        if (progress < g_mmi_java_install_progress)                                   
        {                             
            progress = g_mmi_java_install_progress;                                   
        }                             
        if (g_java.install_progress < progress)                                      
        {                             
            #ifdef __PLUTO_MMI_PACKAGE__
            mmi_java_update_install_progress_bar(progress);
            #elif __COSMOS_MMI_PACKAGE__
            vapp_java_update_install_progress_bar(progress);
            #else
            ASSERT(0);
            #endif            
            g_java.install_progress = progress;                                               
            g_mmi_java_install_progress = progress;
        }                                 
    }                                     
}                                         
                                          
#define __MMI_JAVA_INSTALL_CONFIRM__   
mmi_java_install_confirm_ind_struct mmi_java_mids_install_confirm_ind_msg;    
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_send_mids_install_confirm_res
 * DESCRIPTION                            
 *  This routines send MSG_ID_MMI_JAVA_INSTALL_CONFIRM_RES to MOD_J2ME                    
 *  to send install request and set protocol event handler of  MSG_ID_MMI_JAVA_INSTALL_MIDS_CNF                                           
 * PARAMETERS                             
 *  confirm     [IN]        KAL_TRUE if really want to install this MIDS                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_send_mids_install_confirm_res(MMI_BOOL confirm)                             
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_install_confirm_res_struct *msg;                                             
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    /* ClearInputEventHandler(MMI_DEVICE_ALL); */                                         
                                          
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_INSTALL_CONFIRM_RES);                         
                                          
    msg = (mmi_java_install_confirm_res_struct*) OslConstructDataPtr(sizeof(mmi_java_install_confirm_res_struct));                        
    msg->confirm = confirm;               
                                          
    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,                                 
            MSG_ID_MMI_JAVA_INSTALL_CONFIRM_RES, msg);                              
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_mids_install_confirm_yes_hdlr
 * DESCRIPTION                            
 *  Handle Function, revoked when select "YES" in "INSTALL CONFIRM" screen                
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
/* void mmi_java_send_mids_install_confirm_res_yes(void) */                               
void mmi_java_mids_install_confirm_yes_hdlr(void)                                         
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    mmi_frm_scrn_close_active_id();       
    mmi_java_send_mids_install_confirm_res(MMI_TRUE);                                     
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_mids_install_confirm_no_hdlr 
 * DESCRIPTION                            
 *  Handle Function, revoked when select "NO" in "INSTALL CONFIRM" screen                 
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_mids_install_confirm_no_hdlr(void)                                          
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    mmi_frm_scrn_close_active_id();       
    mmi_java_send_mids_install_confirm_res(MMI_FALSE);                                    
                                          
    if(g_java.mids_install_state != INSTALL_INVALID_STATE)                                
    {                                     
        g_java.mids_install_state = INSTALL_ABORT_STATE;                                  
    }                                     
    else if(g_java.mids_update_state  != UPDATE_INVALID_STATE)                            
    {                                     
        g_java.mids_update_state = UPDATE_ABORT_STATE;                                    
    }                                     
    else                                  
    {                                     
        ASSERT(0);                        
    }                                     
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_mids_install_confirm   
 * DESCRIPTION                            
 *  Install Confirm screen Entry Function 
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_entry_mids_install_confirm(void)                                            
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    U8 *guiBuffer;                        
    U8 *str;                              
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_INSTALL_CONFIRM, NULL, mmi_java_entry_mids_install_confirm, MMI_FRM_FULL_SCRN))                                            
    {                                     
        return;                           
    }                                     
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_java_installer_cui_gid, SCR_JAVA_INSTALL_CONFIRM);                                             
                                          
    str = (U8*) mmi_java_mids_install_confirm_ind_msg.confirm_msg;                        
                                          
    ShowCategory74Screen(                 
        STR_GLOBAL_INSTALL,               
        mmi_java_get_install_title_icon(),
        STR_GLOBAL_YES,                   
        IMG_GLOBAL_YES,                   
        STR_GLOBAL_NO,                    
        IMG_GLOBAL_NO,                    
        (PU8) str,                        
        mmi_ucs2strlen((CHAR *) str),        
        guiBuffer);                       
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_mids_install_confirm_yes_hdlr,KEY_EVENT_UP);                                           
    SetLeftSoftkeyFunction(mmi_java_mids_install_confirm_yes_hdlr, KEY_EVENT_UP);         
    SetRightSoftkeyFunction(mmi_java_mids_install_confirm_no_hdlr, KEY_EVENT_UP);         
                                          
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);                                           
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_mids_install_confirm_ind
 * DESCRIPTION                            
 *  This routines handles MMI_JAVA_INSTALL_CONFIRM_IND from MOD_J2ME to                   
 *  prompt user whether or not install the MIDS                                           
 * PARAMETERS                             
 *  MsgStruct       [?]                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_mids_install_confirm_ind(void *MsgStruct)                              
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_INSTALL_CONFIRM_IND);                         
                                          
    if (g_java.mids_install_state > INSTALL_VALID_STATE ||                                
        g_java.mids_update_state > UPDATE_VALID_STATE )                                   
    {                                     
                                          
        kal_mem_cpy(                      
            &mmi_java_mids_install_confirm_ind_msg,                                       
            (mmi_java_install_confirm_ind_struct*) MsgStruct,                             
            sizeof(mmi_java_install_confirm_ind_struct));                                 
        if(g_mmi_java_is_background_display)                                              
        {                                 
            mmi_java_send_mids_install_confirm_res(MMI_TRUE);                             
            return;                       
        }                                 
        #ifdef __PLUTO_MMI_PACKAGE__
        mmi_java_entry_mids_install_confirm();                                            
        #elif __COSMOS_MMI_PACKAGE__
        vapp_java_entry_mids_install_confirm((U16*)mmi_java_mids_install_confirm_ind_msg.confirm_msg);
        #else
        ASSERT(0);        
        #endif
    }                                     
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_reset_delete_menu_parameter  
 * DESCRIPTION                            
 *  reset the CT898 delete menu parameter when user abort deletion                        
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
U8 mmi_java_reset_delete_menu_parameter(void *ptr)                                        
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_CONFIRM_ENDKEY_HDLR);                              
    mmi_java_send_delete_menu_abort_req();
    mdi_audio_resume_background_play();   
    return MMI_FALSE;                     
                                          
}
/*****************************************************************************            
 * FUNCTION                               
 *  reset_and_gobackhistory               
 * DESCRIPTION                            
 *                                        
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_delete_mids_menu_reset_and_gobackhistory(void)                              
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    mmi_java_reset_delete_menu_parameter(NULL);
#ifdef __PLUTO_MMI_PACKAGE__    
    mmi_java_mids_installer_group_close();
#endif
}


#if defined(__MMI_JAVA_INSTALL_DELETE_MENU__) && defined(__PLUTO_MMI_PACKAGE__) 
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_highlight_get_mids_index     
 * DESCRIPTION                            
 *  Set the handler of the highlight item 
 * PARAMETERS                             
 *  nIndex      [IN]        The index of highlight item                                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_highlight_get_mids_index_for_delete(S32 nIndex)                             
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_GET_JAVA_APP_MIDS_INDEX);                          
                                          
    g_java.mids_index = nIndex;           
    g_java.mid_index = 0;                 
                                          
}                                      
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_fetch_delete_mids_list       
 * DESCRIPTION                            
 *  This function is used to fetch delete list for Category427                            
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
S32 mmi_java_fetch_delete_mids_list(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)                                    
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    S32 i;                                
    S32 mids_size;                        
    jam_getlist_filter_struct* filter = NULL;                                             
    U16 temp_string[20];                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    /* only check the first item_index fetch request */                                   
    if (start_index < g_java.total_java_app_mids &&                                       
        g_java.mids_info_start <= start_index &&                                          
        (g_java.mids_info_end == g_java.total_java_app_mids ||                            
         start_index + data_size < g_java.mids_info_end))                                 
    {                                     
        /* nothing to do, because data is in cache. */                                    
    }                                     
    else                                  
    {                                     
        /* search the cache */            
        int i;                            
        U32 event_group;                  
        mmi_java_mids_getlist_cnf_struct *ptr;                                            
        S32 saved_item_index = start_index;                                               
                                          
        /* scroll up, item_index - 3 for speeding up */                                   
        if (g_java.mids_info_start > saved_item_index)                                    
        {                                 
            saved_item_index -= JAVA_LIST_CACHE_COUNT - data_size;                        
            if (saved_item_index < 0)     
            {                             
                saved_item_index = 0;     
            }                             
        }                                 
                                          
        if (g_java.total_java_app_mids < saved_item_index + JAVA_LIST_CACHE_COUNT)        
        {                                 
            saved_item_index = g_java.total_java_app_mids - JAVA_LIST_CACHE_COUNT;        
        }                                 
                                          
        if (g_java_need_storage_size > 0) 
        {                                 
            filter = (jam_getlist_filter_struct*)get_ctrl_buffer(sizeof(mmi_java_mids_getlist_req_struct));                               
            filter->filter_type = JAM_DISK_FILTER;                                        
            filter->vendor_name = NULL;   
            filter->disk_name = g_java_storage_drive;                                     
        }                                 
        if (filter)                       
        {                                 
            /* because it is used for CT898, filter must no NULL */                       
            mmi_java_send_mids_get_list_req(saved_item_index, MMI_TRUE, &ptr, filter);    
            kal_retrieve_eg_events(g_java_event_group_2, JAVA_EG_GETLIST_1, KAL_OR_CONSUME, (kal_uint32*)&event_group, KAL_SUSPEND);                 
            free_ctrl_buffer(filter);     
                                          
            for (i = 0; i < ptr->mids_list_count; i++)                                    
            {                             
                g_java.mids_info[i] = ptr->pmids_list[i];                                 
            }                             
                                          
            g_java.mids_info_start = ptr->start_indx;                                     
            g_java.mids_info_end = ptr->start_indx + ptr->mids_list_count;                
            g_java.total_java_app_mids = ptr->mids_count;                                 
                                          
            free_local_para((local_para_struct*) ptr);                                    
        }                                 
        else                              
        {                                 
            g_java.total_java_app_mids = 0;                                               
        }                                 
    }                                     
    if (g_java.total_java_app_mids == 0)  
    {                                     
        return MMI_TRUE;                  
    }                                     
                                          
    ASSERT(g_java.mids_info_start <= start_index && start_index < g_java.mids_info_end);  
                                          
    for (i = 0 ; i < data_size ; i++)     
    {                                     
        mmi_ucs2ncpy((CHAR *)menu_data[i].item_list[0], (CHAR *)g_java.mids_info[i + start_index - g_java.mids_info_start].mids_name, MAX_SUBMENU_CHARACTERS);                                  
        menu_data[i].item_list[1] = NULL; 
        mids_size = (g_java.mids_info[i + start_index - g_java.mids_info_start].mids_size);                                               
        if (mids_size == 0 || mids_size == 1)                                             
        {                                 
            kal_wsprintf(temp_string, "%d \0", mids_size);                                
            mmi_ucs2cat((CHAR *)temp_string,(CHAR *)GetString(STR_JAVA_INFO_BYTE));             
            mmi_ucs2ncpy((CHAR *)menu_data[i].item_list[2],(CHAR *)temp_string,20);             
        }                                 
        else                              
        {                                 
            kal_wsprintf(temp_string, "%d \0", mids_size);                                
            mmi_ucs2cat((CHAR *)temp_string,(CHAR *)GetString(STR_JAVA_INFO_BYTES));            
            mmi_ucs2ncpy((CHAR *)menu_data[i].item_list[2],(CHAR *)temp_string,20);             
        }
                            
        if (g_java.mids_info[i + start_index - g_java.mids_info_start].mid_count == 1)
        {                             
            menu_data[i].image_list[0] = (PU8) GetImage(IMG_JAVA_STAR1);              
        }                             
        else                          
        {                             
            menu_data[i].image_list[0] = (PU8) GetImage(IMG_JAVA_STAR2);              
        }                             
                              
    }                                     
                                          
    return i;                             
                                          
}     

mmi_ret mmi_java_mids_delete_mids_menu_leave_proc(mmi_event_struct *evt)          
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    switch(evt->evt_id)                   
    {                                     
    case EVT_ID_SCRN_GOBACK_IN_END_KEY: 
        mmi_java_reset_delete_menu_parameter(NULL);
        break;                            
    case EVT_ID_SCRN_DEINIT:              
        mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);                                       
        break;                            
    }                                     
    return MMI_RET_OK;                    
}      
mmi_ret mmi_java_mids_delete_mids_menu_confirm_leave_proc(mmi_event_struct *evt)          
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    switch(evt->evt_id)                   
    {
    case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
    case EVT_ID_SCRN_GOBACK_IN_END_KEY:          
        mmi_java_reset_delete_menu_parameter(NULL);
        break;                            
    }                                     
    return MMI_RET_OK;                    
} 

/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_delete_mids_menu       
 * DESCRIPTION                            
 *  This function show the midlet suite list to delete to free storage size.              
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_entry_delete_mids_menu(void)
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    U32 count;                            
    U8 *guiBuffer;                        
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if (mmi_frm_is_in_backward_scenario()&&  g_java_storage_drive!='Z' && MMI_FALSE == mmi_java_driver_is_mounted(g_java_storage_drive))  
    {                                     
        g_mmi_java_abort_error_code = MMI_JAVA_ABORT_FOR_DISK_OPERATION_FAILED;           
        g_java.mids_install_state = INSTALL_VALID_STATE;                                  
        g_java.mids_update_state = UPDATE_VALID_STATE;                                    
        g_java.is_local_install = MMI_FALSE;                                              
        g_java.is_at_install = MMI_FALSE; 
        mmi_java_clear_install_info();    
        mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_DELETE_MENU);                
        mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_DELETE_MENU_CONFIRM);        
        return;                           
    }                                     
    g_java.mids_info_end = g_java.mids_info_start = -1;                                   
                                          
    /* get list at the very beginning */  
    needToSendGetListReq = MMI_TRUE;      
                                          
    mmi_java_fetch_delete_mids_list(0, NULL, NULL);                                       
                                          
    count = g_java.total_java_app_mids;   
    if(count > 0)                         
    {   mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);                            
        if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_DELETE_MENU, NULL, mmi_java_entry_delete_mids_menu, MMI_FRM_FULL_SCRN))
        {                                 
            mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
            return;                       
        }
        mmi_frm_scrn_set_leave_proc(g_java_installer_cui_gid,SCR_JAVA_DELETE_MENU, mmi_java_mids_delete_mids_menu_leave_proc); 
        guiBuffer = mmi_frm_scrn_get_gui_buf(g_java_installer_cui_gid, SCR_JAVA_DELETE_MENU);                                             
       /* suspend background play */      
        mdi_audio_suspend_background_play();                                              
        RegisterHighlightHandler(mmi_java_highlight_get_mids_index_for_delete);           
        ShowCategory427Screen((UI_string_type)GetString(STR_GLOBAL_DELETE),               
                              (PU8)GetImage(mmi_java_get_install_title_icon()),           
                              (UI_string_type)GetString(STR_GLOBAL_DELETE),               
                              NULL,       
                              (UI_string_type)GetString(STR_GLOBAL_CANCEL),               
                              NULL,       
                              count,      
                              mmi_java_fetch_delete_mids_list,                            
                              0,          
                              guiBuffer); 
        SetLeftSoftkeyFunction(mmi_java_send_mids_delete_req, KEY_EVENT_UP);              
        SetKeyHandler(mmi_java_send_mids_delete_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);    
                                          
        SetKeyHandler(mmi_java_delete_mids_menu_reset_and_gobackhistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);                                 
        SetRightSoftkeyFunction(mmi_java_delete_mids_menu_reset_and_gobackhistory, KEY_EVENT_UP);                                         
                                          
    }                                     
    else                                  
    {                                     
        /* should not happend, this condition should decide in VM */                      
        /* ASSERT(0); */                  
        mmi_java_delete_mids_menu_reset_and_gobackhistory();                              
    }                                     
                                          
                                          
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_exit_delete_mids_menu_confirm
 * DESCRIPTION                            
 *  the exit function of mmi_java_entry_delete_mids_menu_confirm                          
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static U16 *g_java_str_of_delete_mids_menu_confirm = NULL;                                
void mmi_java_exit_delete_mids_menu_confirm(void)                                         
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if (g_java_str_of_delete_mids_menu_confirm)                                           
    {                                     
        free_ctrl_buffer(g_java_str_of_delete_mids_menu_confirm);                         
        g_java_str_of_delete_mids_menu_confirm = NULL;                                    
    }
    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
}                                         
                                  
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_delete_mids_menu_confirm                                               
 * DESCRIPTION                            
 *  tell user storage is not enought and ask him to delete midlet suites or not           
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_entry_delete_mids_menu_confirm(void)                                        
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    U16 *str;                             
    U16 str2[20];                         
    U16 str_len;                          
    S16 i;                                
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if (mmi_frm_is_in_backward_scenario()&&  g_java_storage_drive!='Z' && MMI_FALSE == mmi_java_driver_is_mounted(g_java_storage_drive))  
    {                                     
        g_mmi_java_abort_error_code = MMI_JAVA_ABORT_FOR_DISK_OPERATION_FAILED;           
        g_java.mids_install_state = INSTALL_VALID_STATE;                                  
        g_java.mids_update_state = UPDATE_VALID_STATE;                                    
        g_java.is_local_install = MMI_FALSE;                                              
        g_java.is_at_install = MMI_FALSE; 
        mmi_java_clear_install_info();    
        mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_DELETE_MENU);                
        mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_DELETE_MENU_CONFIRM);        
        return;                           
    }
    if(g_java_installer_cui_gid == GRP_ID_INVALID)    
    {                                     
        g_java_installer_cui_gid =mmi_java_mids_installer_create_group();                
    } 
    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
    mdi_audio_suspend_background_play();  
    if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_DELETE_MENU_CONFIRM, mmi_java_exit_delete_mids_menu_confirm, mmi_java_entry_delete_mids_menu_confirm, MMI_FRM_FULL_SCRN))  
    {                                     
        return;                           
    } 
    mmi_frm_scrn_set_leave_proc(g_java_installer_cui_gid,SCR_JAVA_DELETE_MENU_CONFIRM, mmi_java_mids_delete_mids_menu_confirm_leave_proc); 
    if (g_java_need_storage_free_size<0)  
    {                                     

        #ifdef __PLUTO_MMI_PACKAGE__
        {
            mmi_popup_property_struct arg;
            mmi_popup_property_init(&arg);
            mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_JAVA_ERROR_CODE_DISK_OP_FAILURE)), MMI_EVENT_FAILURE, &arg);
            g_mmi_java_reinstall_state = 2;  
            mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_DELETE_MENU_CONFIRM); 
        }                         
        #elif __COSMOS_MMI_PACKAGE__
        vapp_java_display_popup(STR_JAVA_ERROR_CODE_DISK_OP_FAILURE, VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
        #else
            ASSERT(0);
        #endif

        return;                          
    }                                     
                                          
                                          
    str = (U16*) GetString(STR_JAVA_DELETE_MENU);                                         
    str_len=get_ucs2_len(str);            
    g_java_str_of_delete_mids_menu_confirm = (U16*)get_ctrl_buffer((str_len+20)<<1);      
                                          
    mmi_ucs2cpy((CHAR *)g_java_str_of_delete_mids_menu_confirm,(CHAR *)str);                    
    for (i=0; i<str_len; i++)             
    {                                   
        if (g_java_str_of_delete_mids_menu_confirm[i]==L'%')                           
        {                              
            g_java_str_of_delete_mids_menu_confirm[i] = L'\0';                       
            break;                         
        }                              
    }                                   
    if (i == str_len)                     
    {                                     
        ASSERT (0);                       
    }                                     
    kal_wsprintf(str2,"%d",g_java_need_storage_free_size);                                
                                          
    mmi_ucs2cat((CHAR *)g_java_str_of_delete_mids_menu_confirm,(CHAR *)str2);                   
    mmi_ucs2cat((CHAR *)g_java_str_of_delete_mids_menu_confirm,(CHAR *)&str[i+2]);              
                                          
    ShowCategory74Screen(                 
        STR_GLOBAL_INSTALL,               
        mmi_java_get_install_title_icon(),
        STR_GLOBAL_YES,                   
        IMG_GLOBAL_YES,                   
        STR_GLOBAL_NO,                    
        IMG_GLOBAL_NO,                    
        (PU8) g_java_str_of_delete_mids_menu_confirm,                                     
        str_len+20,                       
        NULL);                            
                                          
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_entry_delete_mids_menu,KEY_EVENT_UP);                                     
    SetLeftSoftkeyFunction(mmi_java_entry_delete_mids_menu, KEY_EVENT_UP);                
    SetRightSoftkeyFunction(mmi_java_delete_mids_menu_reset_and_gobackhistory, KEY_EVENT_UP);                                             
                                          
                                          
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);                                           
}                                         
#endif

#ifdef __PLUTO_MMI_PACKAGE__
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_terminate_vm_confirm   
 * DESCRIPTION                            
 *  ask user to terminate vm when installation.                                           
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_entry_terminate_vm_confirm(void)                                            
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/
    if (jam_mvm_is_vm_running(g_mmi_java_install_terminate_vm_id)||jam_mvm_is_vm_terminating(g_mmi_java_install_terminate_vm_id))
    {                                     
                         
            g_java.screen_after_terminate = TER_ENTRY_INSTALL_JAVA;
            mmi_java_entry_cb_terminate_dialog(mmi_java_mids_install_ask_terminate_cb, (U16*)GetString(STR_JAVA_TERMINATE_JAVA_GAME),1);  
        }                                 
        else                              
        {                                 
        /* vm not run keep on installation ? */                                           
        g_mmi_java_install_terminate_vm_id = -1;
        mmi_java_mids_install_internal(); 
    }                                     
                                          
}                                         
#endif 

/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_allow_to_popup_screen
 * DESCRIPTION
 *  This routines is used to check whehter a popup can be shown
 * PARAMETERS
 *  void       [?]     
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_java_is_allow_to_popup_screen(void)
{
    if(mmi_java_is_in_voice_call())
    {
        return MMI_FALSE;
    }
#ifdef __DM_LAWMO_SUPPORT__               
    if(srv_dm_lawmo_is_locked())          
    {                                     
        return MMI_FALSE;
    }                                     
#endif /* __DM_LAWMO_SUPPORT__ */         
#ifdef __MMI_WEBCAM__
    if(mmi_usb_webcam_is_active())        
    {                                     
        return MMI_FALSE;
    }                                     
#endif
    if(
#ifdef __PLUTO_MMI_PACKAGE__
    mmi_scr_locker_is_locked()
#elif __COSMOS_MMI_PACKAGE__
    vapp_screen_lock_is_locked()
#else
    0
#endif
    )
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_try_to_shutdown_vm
 * DESCRIPTION
 *  This function is used to check whether all midlet shut down, and vm no need to run.
 * PARAMETERS
 *  void       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_try_to_shutdown_vm(void)
{
    if(jam_mvm_is_shutdown())
    {
        return;
    }
    if(jam_mvm_is_shutdowning())
    {
        return;
    }
    if(jam_is_busy())
    {
        return;
    }
    if(jam_mvm_get_running_count() != 0)
    {
        return;
    }

    jam_mvm_shutdown_all_req();
}



/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_mids_install_cnf        
 * DESCRIPTION                            
 *  This routines handles MMI_JAVA_INSTALL_MIDS_CNF from MOD_J2ME to                      
 *  send a response back to MOD_J2ME      
 * PARAMETERS                             
 *  MsgStruct       [?]                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_mids_install_cnf(void *MsgStruct)                                      
{
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_install_mids_cnf_struct *msg;
    mmi_java_app_factory_record_struct *record = NULL;
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    #ifdef __COSMOS_MMI_PACKAGE__
    while(jam_is_busy())
    {
        kal_sleep_task(10);
    }
    #endif
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_INSTALL_MIDS_CNF); 
    g_java.mids_install_state = INSTALL_FINISH_STATE;                                 
    g_java.mids_update_state = UPDATE_FINISH_STATE;    
    if(!mmi_java_is_allow_to_popup_screen())        
    {
#ifdef __PLUTO_MMI_PACKAGE__
        mmi_java_mids_installer_group_close();
#elif __COSMOS_MMI_PACKAGE__
        vapp_java_close_venus_screen();
#else
        ASSERT(0);
#endif
        g_mmi_java_is_background_display = MMI_TRUE;                                      
    } 
    /* reset g_java_need_storage_size */  
    g_java_need_storage_size = 0;         
    g_mmi_java_reinstall_state= 0;        
    g_mmi_java_install_mids_id = -1;
                                  
    /* rename right name as original jar file name */                                     
#ifdef __DRM_SUPPORT__                    
    if(mmi_jar_file_name)                 
    {                                     
        DRM_register_file(mmi_jar_file_name);                                             
    }                                     
#endif                                    
    msg = (mmi_java_install_mids_cnf_struct*) MsgStruct;                                  
                             
    if (msg->error_code == J2ME_NO_ERROR || msg->error_code == POST_ERROR)            
    {                                 
        /* Resume background play */  
        mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_JAVA);             
                                      
#ifdef __MMI_JAVA_LAUNCH_AFTER_INSTALL__      
        if (!g_mmi_java_is_background_display && 
            mmi_java_is_allow_to_popup_screen())      
        {                             
            if (msg->need_lauch)      
            {                         
                g_mmi_java_install_mids_id = msg->mids_id;                            
            }                         
            mmi_java_set_allow_push_install(MMI_FALSE);                               
            mmi_java_clean_list_related_screen_when_install();
        }                             
#endif /* __MMI_JAVA_LAUNCH_AFTER_INSTALL__ */
                                      
        if (msg->error_code == J2ME_NO_ERROR)                                         
        {                             
#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__   
            if(g_mmi_java_post_notify_result)                                         
            {                         
#endif                                    
                if(!g_mmi_java_is_background_display )                                
                {                                
                #ifdef __PLUTO_MMI_PACKAGE__
                    mmi_popup_property_struct arg;
                    mmi_popup_property_init(&arg);
                    arg.callback = mmi_java_mids_entry_after_install_proc;
                    mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_JAVA_INSTALLED)), MMI_EVENT_SUCCESS, &arg);
                #elif __COSMOS_MMI_PACKAGE__
                    vapp_java_close_venus_screen();
                    vapp_java_display_popup(STR_JAVA_INSTALLED, VJAVA_POPUP_INFO,VAPP_JAVA_ENTRY_LAUNCH_AFTER_INSTALL);
                #else
                   ASSERT(0);                
                #endif 

                         
                }                     
#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__   
            }                         
            else                      
            {                         
                g_mmi_java_post_notify_result = MMI_TRUE;                             
                if(!g_mmi_java_is_background_display )                                
                {                     
                #ifdef __PLUTO_MMI_PACKAGE__
                    mmi_popup_property_struct arg;
                    mmi_popup_property_init(&arg);
                    arg.callback = mmi_java_mids_entry_after_install_proc;
                    mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_JAVA_INSTALLED_BUT_FAILED_TO_SEND_REPORT)), MMI_EVENT_SUCCESS, &arg);
                #elif __COSMOS_MMI_PACKAGE__
                    vapp_java_close_venus_screen();
                    vapp_java_display_popup(STR_JAVA_INSTALLED_BUT_FAILED_TO_SEND_REPORT, VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_LAUNCH_AFTER_INSTALL);
                #else
                   ASSERT(0);                
                #endif                     
                }                     
            }                         
#endif                                    
        }                             
        else                          
        {                             
            if(!g_mmi_java_is_background_display )                                    
            {                         
                #ifdef __PLUTO_MMI_PACKAGE__
                mmi_popup_property_struct arg;
                mmi_popup_property_init(&arg);
                arg.callback = mmi_java_mids_entry_after_install_proc;
                mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_JAVA_ERROR_CODE_POST_ERROR)), MMI_EVENT_SUCCESS, &arg);
                #elif __COSMOS_MMI_PACKAGE__
                vapp_java_close_venus_screen();
                vapp_java_display_popup(STR_JAVA_ERROR_CODE_POST_ERROR, VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_LAUNCH_AFTER_INSTALL);
                #else
                ASSERT(0);                
                #endif
            }                         
        }                             
        if(g_mmi_java_current_installing_mids_name)
        {
            free_ctrl_buffer(g_mmi_java_current_installing_mids_name);
            g_mmi_java_current_installing_mids_name = NULL;
        }
		record = (mmi_java_app_factory_record_struct*) get_ctrl_buffer( sizeof(mmi_java_app_factory_record_struct));
        memset(record, 0, sizeof(mmi_java_app_factory_record_struct));
		memcpy(
            record->mids_name,
            msg->mids_name,
            (mmi_ucs2strlen((CHAR*)msg->mids_name)>MMI_APP_NAME_MAX_LEN-1?MMI_APP_NAME_MAX_LEN-1:mmi_ucs2strlen((CHAR*)msg->mids_name))<<1);
        memcpy(
            record->mids_vendor,
            msg->mids_vendor,
            (mmi_ucs2strlen((CHAR*)msg->mids_vendor)>MIDLET_VENDOR_LEN-1?MIDLET_VENDOR_LEN-1:mmi_ucs2strlen((CHAR*)msg->mids_vendor))<<1);
        memcpy(record->mids_version,msg->mids_version, (strlen(msg->mids_version) > MIDLET_VERSION_LEN ? MIDLET_VERSION_LEN-1:strlen(msg->mids_version)));
        memcpy(record->storage_name,msg->mids_storage_id, strlen(msg->mids_storage_id));
        record->is_vk_on = KAL_FALSE;
        record->is_bg_enabled= KAL_TRUE;
        if(msg->mids_id <= j2me_default_game_count
			#ifdef __MMI_JAVA_PREINSTALL_TCARD_PACKAGE__  
			||srv_java_appfactory_mids_is_default( record->storage_name)
			#endif
		)
        {
            record->is_default =KAL_TRUE;
        }
        else
        {
            record->is_default =KAL_FALSE;            
        }
        record->installed_drive = msg->installed_drv;
		record->is_installed = KAL_TRUE;
        srv_java_appfactory_add_record(record);        
        srv_java_appfactory_get_app_name_by_storage_name(g_java_current_install_app_name, msg->mids_storage_id);
        srv_appmgr_update_app_info(g_java_current_install_app_name,EVT_ID_SRV_APPMGR_INSTALL_PACKAGE);
        free_ctrl_buffer(record);
        mmi_java_report_status(g_mmi_java_current_running_cmd,msg->error_code,(CHAR *)msg->mids_storage_id,(U16*)msg->mids_name,(CHAR *)msg->mids_version);                                 
    }                                 
    else                              
    {                                 
       /*                            
                * If current in background mode                                               
                *  or not in (CT898 or midlet running) then report immediately                
                *  SD DRM current also report failure.                                        
                */                            
        if(g_mmi_java_is_background_display ||
            #ifdef __PLUTO_MMI_PACKAGE__
            (msg->error_code == INSUFFICIENT_STORAGE && msg->storage_drive=='Z')||
            #endif
            (
            #ifdef __PLUTO_MMI_PACKAGE__
            msg->error_code != INSUFFICIENT_STORAGE &&
            #endif
            msg->error_code != MIDLET_RUNNING
            ))                                           
        {                             
            g_java_need_storage_size = 0;    
            g_mmi_java_reinstall_state = 0;
            mmi_java_report_status(g_mmi_java_current_running_cmd,msg->error_code,NULL,NULL,NULL);   
            if(g_mmi_java_current_installing_mids_name)
            {
                free_ctrl_buffer(g_mmi_java_current_installing_mids_name);
                g_mmi_java_current_installing_mids_name = NULL;
            }
        }                             
                                      
                                      
        if(mmi_java_is_drm_file(mmi_jad_file_name) || mmi_java_is_drm_file(mmi_jar_file_name)                                         
           #if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)         
           || jvm_util_is_midlet_msg_file(mmi_jar_file_name)                          
           #endif                     
           )                          
        {                             
            mmi_delete_after_install_fail = MMI_FALSE;                                
            mmi_java_unhide_install_file();                                           
        }                             
        if (!g_mmi_java_is_background_display                                         
            && msg->error_code == INSUFFICIENT_STORAGE)                               
        {                             
            /* CT 898 */
        #if (defined(__MMI_JAVA_INSTALL_DELETE_MENU__) && defined(__PLUTO_MMI_PACKAGE__))                                              
            if (msg->storage_drive != 'Z')                                            
            {                         
                #ifdef __PLUTO_MMI_PACKAGE__
                mmi_java_backup_install_information();                                
                g_mmi_java_reinstall_state = 1;                                       
                g_java_need_storage_size = msg->need_storage_size;                    
                g_java_storage_drive = msg->storage_drive;                            
                mmi_java_storage_size_is_enough();                                    
                g_mmi_java_current_running_cmd = MMI_JAVA_CMD_END; 
                mmi_java_mids_installer_group_close();
                mmi_java_entry_delete_mids_menu_confirm();                            
                #elif __COSMOS_MMI_PACKAGE__
                /* Resume background play */                                          
                mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_JAVA);   
                vapp_java_entry_delete_mids_menu_confirm();
                #else
                ASSERT(0);
                #endif                           
            }                         
            else                      
        #endif                        
            {           
                #ifdef __PLUTO_MMI_PACKAGE__      
                mmi_popup_property_struct arg;
                mmi_popup_property_init(&arg);
                /* delete midlet can't save you, and popup */                         
                arg.callback = mmi_java_mids_entry_after_install_proc;
                mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY)), MMI_EVENT_FAILURE, &arg);
                #elif __COSMOS_MMI_PACKAGE__
                vapp_java_close_venus_screen();
                vapp_java_display_popup(STR_GLOBAL_NOT_ENOUGH_MEMORY, VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
                #else
                ASSERT(0);
                #endif
                /* Resume background play */                                          
                mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_JAVA);     
                g_mmi_java_reinstall_state = 0;
                g_java_need_storage_size = 'Z';
                if(g_mmi_java_current_installing_mids_name)
                {
                    free_ctrl_buffer(g_mmi_java_current_installing_mids_name);
                    g_mmi_java_current_installing_mids_name = NULL;
                }
                mmi_java_report_status(g_mmi_java_current_running_cmd,msg->error_code,NULL,NULL,NULL);                                
            } 
            
        }                             
    #ifdef __MMI_JAVA_LAUNCH_AFTER_INSTALL__  
        else if(!g_mmi_java_is_background_display && msg->error_code == J2ME_USER_CANCEL && msg->need_lauch)      
        {            
            if (!mmi_java_is_in_voice_call())                                         
            {                         
                /* Resume background play */                                          
                mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_JAVA);     
                g_mmi_java_install_mids_id = msg->mids_id;                            
            }
            else
            {
                g_mmi_java_install_mids_id = -1;
            }
            if(g_mmi_java_current_installing_mids_name)
            {
                free_ctrl_buffer(g_mmi_java_current_installing_mids_name);
                g_mmi_java_current_installing_mids_name = NULL;
            }
            mmi_java_set_allow_push_install(MMI_FALSE);   
            srv_java_appfactory_get_app_name_by_storage_name(g_java_current_install_app_name, msg->mids_storage_id);
            #ifdef __PLUTO_MMI_PACKAGE__
            mmi_java_clean_list_related_screen_when_install();                    
            {
                mmi_popup_property_struct arg;
                mmi_popup_property_init(&arg);
                arg.callback = mmi_java_mids_entry_after_install_proc;
                mmi_popup_display((WCHAR*)GetString(get_str_id_by_error_code(msg->error_code)), MMI_EVENT_FAILURE, &arg);
            }                             
            #elif __COSMOS_MMI_PACKAGE__
                vapp_java_close_venus_screen();
                vapp_java_display_popup(get_str_id_by_error_code(msg->error_code), VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_LAUNCH_AFTER_INSTALL);
            #else
                ASSERT(0);
            #endif 
        }                             
    #endif                            
        else if(!g_mmi_java_is_background_display && msg->error_code == MIDLET_RUNNING)                                               
        {                             
            /* MF 9 */         
            #ifdef __PLUTO_MMI_PACKAGE__
            g_mmi_java_reinstall_state = 1;                                           
            g_mmi_java_install_terminate_vm_id = msg->vm_id;
            mmi_java_entry_terminate_vm_confirm();                                    
            #elif __COSMOS_MMI_PACKAGE__
            vapp_java_close_venus_screen();
            g_mmi_java_reinstall_state = 1;                                           
            g_mmi_java_install_terminate_vm_id = msg->vm_id;
            vapp_java_entry_terminate_vm_confirm();
            #else 
            ASSERT(0);
            #endif
        }                             
        else if(!g_mmi_java_is_background_display && msg->error_code == DRM_RIGHT_NOT_RECEIVED)                                       
        {       
             
            /* Resume background play */                                              
            mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_JAVA);         
            /* TCD 1114 */            
            mmi_delete_after_install_fail = MMI_FALSE; /* becasue it must be DRM file */                                              
            if(!g_mmi_java_is_background_display)                                     
            {
                if(g_mmi_java_current_installing_mids_name)
                {
                    free_ctrl_buffer(g_mmi_java_current_installing_mids_name);
                    g_mmi_java_current_installing_mids_name = NULL;
                }
                g_mmi_java_current_running_cmd = MMI_JAVA_CMD_END;                        
                #ifdef __MMI_JAVA_INSTALL_PUSHINSTALL__
                mmi_java_register_push_install(msg->drm_file_path,msg->drm_serial); 
                if (msg->acquire_right)   
                {                         
                    if (g_mmi_java_install_drm_path_aquire_right)                         
                    {                     
                        free_ctrl_buffer(g_mmi_java_install_drm_path_aquire_right);       
                        g_mmi_java_install_drm_path_aquire_right = NULL;                  
                    }                     
                    g_mmi_java_install_drm_path_aquire_right = get_ctrl_buffer((mmi_ucs2strlen((CHAR *)msg->drm_file_path)+1)<<1);       
                    memcpy(g_mmi_java_install_drm_path_aquire_right,msg->drm_file_path,((mmi_ucs2strlen((CHAR *)msg->drm_file_path)+1)<<1));                                             
                }
                #endif
                
                #ifdef __PLUTO_MMI_PACKAGE__
                {
                    mmi_popup_property_struct arg;
                    mmi_popup_property_init(&arg);
                    if(msg->acquire_right)
                    {                        
                        #ifdef __MMI_JAVA_INSTALL_PUSHINSTALL__
                        arg.callback = mmi_java_mids_entry_drm_acquire_right_proc;
                        #endif
                    }
                    mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_DRM_PROHIBITED)), MMI_EVENT_FAILURE, &arg);
                }                         
                #elif __COSMOS_MMI_PACKAGE__
                vapp_java_close_venus_screen();
                if(msg->acquire_right)
                {
                    vapp_java_display_popup(STR_GLOBAL_DRM_PROHIBITED, VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_RIGHT_MANAGER);
                }
                else
                {
                    vapp_java_display_popup(STR_GLOBAL_DRM_PROHIBITED, VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
                }
                #else
                    ASSERT(0);
                #endif
            }
        }                             
        else                          
        {
            if(g_mmi_java_current_installing_mids_name)
            {
                free_ctrl_buffer(g_mmi_java_current_installing_mids_name);
                g_mmi_java_current_installing_mids_name = NULL;
            }
            /* Resume background play */                                              
            mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_JAVA);   
            if(!g_mmi_java_is_background_display)                                     
            {    
                #ifdef __PLUTO_MMI_PACKAGE__
                mmi_popup_property_struct arg;
                mmi_popup_property_init(&arg);
                arg.callback = mmi_java_mids_entry_after_install_proc;
                mmi_popup_display((WCHAR*)GetString(get_str_id_by_error_code(msg->error_code)), MMI_EVENT_FAILURE, &arg);
                #elif __COSMOS_MMI_PACKAGE__
                vapp_java_close_venus_screen();
                vapp_java_display_popup(get_str_id_by_error_code(msg->error_code), VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_LAUNCH_AFTER_INSTALL);
                #else
                ASSERT(0);
                #endif
                mmi_java_report_status(g_mmi_java_current_running_cmd,msg->error_code,NULL,NULL,NULL);                                
            }  
        }                             
    }  

    if(g_java.is_at_install && g_mmi_java_reinstall_state == 0)                       
    {                                 
        mmi_java_send_at_loacl_install_cnf(msg->error_code);                          
        g_java.is_at_install = MMI_FALSE;                                             
    }                                 
    if (g_mmi_java_reinstall_state == 0)                                              
    {                                 
        mmi_java_clear_install_info();
    }                                 
                             

    if( msg->error_code != MIDLET_RUNNING||
        g_mmi_java_is_background_display||
        msg->need_lauch == KAL_FALSE
        )
    {
        mmi_java_try_to_shutdown_vm();
    }
    if(g_mmi_java_reinstall_state == 0)
    {
        g_mmi_java_install_progress = 0;
    }
    if(msg->mids_storage_id)              
    {                                     
        free_ctrl_buffer(msg->mids_storage_id);                                           
        msg->mids_storage_id = NULL;      
    }                                     
    if(msg->mids_name)                    
    {                                     
        free_ctrl_buffer(msg->mids_name); 
        msg->mids_name = NULL;            
    }                                     
    if(msg->mids_vendor)                  
    {                                     
        free_ctrl_buffer(msg->mids_vendor);                                               
        msg->mids_vendor = NULL;          
    }                                     
    if(msg->mids_version)                 
    {                                     
        free_ctrl_buffer(msg->mids_version);                                              
        msg->mids_version = NULL;         
    }                                     
    if(msg->drm_file_path != NULL)
    {
        free_ctrl_buffer(msg->drm_file_path);
        msg->drm_file_path = NULL;
    }
    g_java.mids_install_state = INSTALL_VALID_STATE;                                      
    g_java.mids_update_state = UPDATE_VALID_STATE;                                        
    g_java.is_local_install = MMI_FALSE;  
    if(g_java.download_midlet_name)       
    {                                     
        free_ctrl_buffer(g_java.download_midlet_name);                                    
        g_java.download_midlet_name = NULL;                                               
    }                                     
                                          
    if(g_java.download_string)            
    {                                     
        free_ctrl_buffer(g_java.download_string);                                         
        g_java.download_string = NULL;    
    }                                     
#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__   
    g_mmi_java_post_notify_result = MMI_TRUE;                                             
#endif
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_mids_update            
 * DESCRIPTION                            
 *  Update Feature Entry Function         
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_entry_mids_update(void)     
{
#ifdef __PLUTO_MMI_PACKAGE__

#ifdef __MMI_USB_SUPPORT__             
    if (srv_usb_is_in_mass_storage_mode())
    {                                     
        /* in mass storage mode */   
        #ifdef __PLUTO_MMI_PACKAGE__
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */         
        #endif
        return;                           
                                          
    }                                     
#endif /* __USB_IN_NORMAL_MODE__ */       
    if (mmi_java_is_no_network_service()) 
    {                                     
        #ifdef __PLUTO_MMI_PACKAGE__
        {
            mmi_popup_property_struct arg;
            mmi_popup_property_init(&arg);
            mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_JAVA_ERROR_CODE_NETWORK_FAILTURE)), MMI_EVENT_FAILURE, &arg);
        }                         
        #elif __COSMOS_MMI_PACKAGE__
        vapp_java_display_popup(STR_JAVA_ERROR_CODE_NETWORK_FAILTURE, VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
        #else
            ASSERT(0);
        #endif
        
        return;                           
    }                                     
    if (jam_vm_is_busy())
    {
        mmi_java_display_is_busy();
        return ;
    }                                   
    #ifndef __MMI_JAVA_MIDS_UPDATE_CONFIRM__
    mmi_java_send_mids_update_req();
    #else
    mmi_java_entry_mids_update_confirm();
    #endif // __MMI_JAVA_MIDS_UPDATE_CONFIRM__
#endif
}                                         
                                          
#if defined(__PLUTO_MMI_PACKAGE__)&& defined(__MMI_JAVA_MIDS_UPDATE_CONFIRM__)                                  
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_mids_update_confirm    
 * DESCRIPTION                            
 *  Updating Ask Entry Function           
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
/* void mmi_java_enter_mids_update_req_asking(void) */                                    
void mmi_java_entry_mids_update_confirm(void)                                             
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    U8 *guiBuffer;                        
    U8 *str;                              
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if(g_java_installer_cui_gid == GRP_ID_INVALID)    
    {                                     
        g_java_installer_cui_gid =mmi_java_mids_installer_create_group();                 
    }                                     
    if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_UPDATE_CONFIRM, NULL, mmi_java_entry_mids_update_confirm, MMI_FRM_FULL_SCRN))                                              
    {                                     
        return;                           
    }                                     
                                          
    /* playRequestedTone(WARNING_TONE); */
                                          
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_java_installer_cui_gid,SCR_JAVA_UPDATE_CONFIRM);                                               
                                          
    str = (U8*) get_string(STR_JAVA_START_UPDATE_ASK);                                    
    ShowCategory74Screen(                 
        STR_GLOBAL_UPDATE,                
        mmi_java_get_install_title_icon(),
        STR_GLOBAL_YES,                   
        IMG_GLOBAL_YES,                   
        STR_GLOBAL_NO,                    
        IMG_GLOBAL_NO,                    
        (PU8) str,                        
        mmi_ucs2strlen((CHAR *) str),        
        guiBuffer);                       
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_mids_update_confirm_yes_hdlr,KEY_EVENT_UP);                                       
    SetLeftSoftkeyFunction(mmi_java_mids_update_confirm_yes_hdlr, KEY_EVENT_UP);          
    SetRightSoftkeyFunction(mmi_java_mids_update_confirm_no_hdlr, KEY_EVENT_UP);          
                                          
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_mids_update_confirm_yes_hdlr 
 * DESCRIPTION                            
 *  Handle Function: revoked when select "YES" in "UPDATE CONFIRM" screen                 
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
/* void mmi_java_send_mids_update_req_yes(void) */                                        
void mmi_java_mids_update_confirm_yes_hdlr(void)                                          
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    ClearInputEventHandler(MMI_DEVICE_ALL);                                               
    mmi_java_send_mids_update_req();      
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_mids_update_confirm_no_hdlr  
 * DESCRIPTION                            
 *  Handle Function: revoked when select "NO" in "UPDATE CONFIRM" screen                  
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
/* void mmi_java_send_mids_update_req_no(void) */                                         
void mmi_java_mids_update_confirm_no_hdlr(void)                                           
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    //ClearInputEventHandler(MMI_DEVICE_ALL);                                             
    /* quit the screen of SCR_JAVA_UPDATE_CONFIRM (Update?) */                            
    mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_UPDATE_CONFIRM);                 
    g_java.mids_install_state = INSTALL_VALID_STATE;                                      
    g_java.mids_update_state = UPDATE_VALID_STATE;                                        
}                                         
#endif /*__PLUTO_MMI_PACKAGE__ && __MMI_JAVA_MIDS_UPDATE_CONFIRM__*/

/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_send_mids_update_req         
 * DESCRIPTION                            
 *  This routines send MSG_ID_MMI_JAVA_MIDS_UPDATE_REQ to MOD_J2ME to send update         
 *  request and set protocol event handler of  MSG_ID_MMI_JAVA_MIDS_UPDATE_CNF            
 * PARAMETERS                             
 *  void                                  
 *  IN   confirm    KAL_TRUE if really want to install this MIDS(?)                       
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_send_mids_update_req(void)  
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_mids_update_req_struct *msg; 
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_UPDATE_REQ);                             
    /* ClearInputEventHandler(MMI_DEVICE_ALL); */                                         
    if (g_java.mids_install_state != INSTALL_VALID_STATE                                  
        || g_java.mids_delete_state != DELETE_VALID_STATE                                 
        || g_java.mids_update_state != UPDATE_VALID_STATE                                 
        || g_mmi_java_reinstall_state > 0 
        || (g_java.msg_ctrl & SEND_MID_SET_SETTING_CTRL)                                  
        || g_mmi_java_is_in_package       
        || jam_is_busy())            
    {                                     
        mmi_java_display_is_busy();       
        return;                           
    }                                     
    if (mmi_java_is_in_voice_call())      
    {                                     
        #ifndef __COSMOS_MMI_PACKAGE__
        mmi_popup_property_struct arg;
        mmi_popup_property_init(&arg);
        arg.parent_id = GRP_ID_ROOT;
        arg.callback = mmi_java_mids_installer_group_close_proc;
        arg.user_tag = (void *)(NULL); // not for parent proc
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL)), MMI_EVENT_FAILURE, &arg);
        #else
        vapp_java_display_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_FAILURE,VAPP_JAVA_ENTRY_NONE);
        #endif
        return;                           
    }
    g_java.mids_install_state = INSTALL_INVALID_STATE;                                    
    g_java.mids_update_state = UPDATE_JAD_DOWNLOAD_STATE;                                 
    msg = (mmi_java_mids_update_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_update_req_struct));                                
    msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;  
    #if defined (__COSMOS_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT )    
		if(!mmi_frm_group_is_present(APP_JAVA))
		{ 
			mmi_frm_group_create_ex(
				GRP_ID_ROOT,
				APP_JAVA,
				NULL,
				NULL,
				MMI_FRM_NODE_NONE_FLAG);

			mmi_java_dummy_entry();

		}
	#endif                                        
    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,                                 
        MSG_ID_MMI_JAVA_MIDS_UPDATE_REQ, msg);
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_mids_update_cnf         
 * DESCRIPTION                            
 *  This routines handles MMI_JAVA_MIDS_UPDATE_CNF from MOD_J2ME to                       
 *  popup a screen to indicate the user Update Done                                       
 * PARAMETERS                             
 *  MsgStruct       [?]                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_mids_update_cnf(void *MsgStruct)                                       
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_mids_update_cnf_struct * msg =(mmi_java_mids_update_cnf_struct*)MsgStruct;
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MIDS_UPDATE_CNF);                             
    #if defined (__COSMOS_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT )
        mmi_frm_scrn_set_leave_proc(APP_JAVA, SCR_JAVA_DUMMY, NULL);
        mmi_frm_group_close(APP_JAVA);
	#endif                                         
    if (g_java.mids_update_state > UPDATE_VALID_STATE ||                                  
        g_java.mids_update_state == UPDATE_ABORT_STATE)                                   
    {                                     
                                          
        g_java.mids_install_state = INSTALL_FINISH_STATE;                                 
        g_java.mids_update_state = UPDATE_FINISH_STATE;                                   
        mmi_java_mids_install_clean_screen();                                             
    }                                     
    g_java.mids_install_state = INSTALL_VALID_STATE;                                      
    g_java.mids_update_state = UPDATE_VALID_STATE;                                        
    g_java.is_local_install = MMI_FALSE;  
    g_java.is_at_install = MMI_FALSE;     
    if(g_java.download_midlet_name)       
    {                                     
        free_ctrl_buffer(g_java.download_midlet_name);                                    
        g_java.download_midlet_name = NULL;                                               
    }                                     
    if(g_java.download_string)            
    {                                     
        free_ctrl_buffer(g_java.download_string);                                         
        g_java.download_string = NULL;    
    }
    if(msg->error_code != J2ME_NO_ERROR)
    {
#ifdef __PLUTO_MMI_PACKAGE__
        {
            mmi_popup_property_struct arg;
            mmi_popup_property_init(&arg);
            mmi_popup_display((WCHAR*)GetString(get_str_id_by_error_code(msg->error_code)), MMI_EVENT_FAILURE, &arg);
        }                         
#elif __COSMOS_MMI_PACKAGE__
        vapp_java_display_popup(get_str_id_by_error_code(msg->error_code), VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
#else
            ASSERT(0);
#endif
    }
}                                         

#ifdef __MMI_JAVA_INSTALL_DOWNLOAD_JAR_IND__ 
void mmi_java_entry_pecentage_bar(void);
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_show_percentage_ind     
 * DESCRIPTION                            
 * PARAMETERS                             
 *  MsgStruct       [?]                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_show_percentage_ind(void *MsgStruct)                                   
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_show_percentage_ind_struct *msg = (mmi_java_show_percentage_ind_struct*) MsgStruct;                                          
    U8 percentage;                        
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_SHOW_PERCENTAGE_IND, msg->current, msg->total);                                               
                                          
    if  (g_java.mids_install_state > INSTALL_VALID_STATE ||                               
         g_java.mids_update_state > UPDATE_VALID_STATE )                                  
    {                                     
        if(g_java.download_midlet_name)   
        {                                 
            free_ctrl_buffer(msg->midlet_name);                                           
        }                                 
        else                              
        {                                 
            g_java.download_midlet_name = (U16*)msg->midlet_name;                         
        }                                 
                                          
        if (msg->total != 0)              
        {                                 
            percentage = (U8) (msg->current * 100 / msg->total);                          
        }                                 
        else                              
        {                                 
            percentage = 99;              
        }                                 
                                          
        /* Reset parameter */             
        if (msg->current == 0)            
        {                                 
            g_java.download_percentage = 0;                                               
        }                                 
                                          
        if (msg->current == 0 || (g_java.download_percentage != percentage && g_java.downloaded_size != msg->current))                    
        {                                 
            g_java.downloaded_size = msg->current;                                        
                                          
            if (g_java.download_string)   
            {                             
                free_ctrl_buffer(g_java.download_string);                                 
            }                             
                                          
            g_java.download_string = (U16*) get_ctrl_buffer(26 << 1);                     
                                          
            if ( (msg->current >> 10) == 0)                                               
            {                             
                kal_wsprintf(g_java.download_string, "%d%c(%dB)", percentage, '%', msg->current);                                         
            }                             
            else if ( (msg->current >> 20) > 0)                                           
            {                             
                kal_wsprintf(g_java.download_string, "%d%c(%d.%dM)", percentage, '%', msg->current >> 20, (msg->current >>18) & 0x07);    
            }                             
            else                          
            {                             
                kal_wsprintf(g_java.download_string, "%d%c(%d.%dK)", percentage, '%', msg->current >> 10, (msg->current >>8) & 0x07 );    
            }                             
        }                                 
        if(!g_mmi_java_is_background_display)                                             
        {                                 
            if (mmi_frm_scrn_get_active_id() == SCR_JAVA_SHOW_PERCENTAGE)                 
            {                             
                if (g_java.download_percentage != percentage)                             
                { 
                    #ifdef __PLUTO_MMI_PACKAGE__
                    UpdateCategory402Value(percentage, (U8*)g_java.download_string);      
                    #endif
                }                         
            }                             
            else if (!mmi_frm_scrn_is_present (g_java_installer_cui_gid, SCR_JAVA_SHOW_PERCENTAGE, MMI_FRM_NODE_ALL_FLAG))                
            {
                #ifdef __PLUTO_MMI_PACKAGE__
                mmi_java_entry_pecentage_bar();        
                #endif                                                         
            }                             
        }                                 
                                          
                                          
        g_java.download_percentage = percentage;                                          
    }                                     
    else                                  
    {                                     
        free_ctrl_buffer(msg->midlet_name);                                               
    }                                     
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_pecentage_bar          
 * DESCRIPTION                            
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_entry_pecentage_bar(void)   
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_SHOW_PERCENTAGE, NULL, mmi_java_entry_pecentage_bar, MMI_FRM_FULL_SCRN))   
    {                                     
        return;                           
    }                                     
                                          
#ifdef __MMI_SCREEN_SWITCH_EFFECT__       
    gui_screen_switch_effect_block(MMI_TRUE);                                             
#endif                                    
    ShowCategory402Screen(                
        (U8*) GetString(STR_GLOBAL_DOWNLOADING),                                          
        mmi_java_get_install_title_icon(),
        0,                                
        0,                                
        STR_GLOBAL_CANCEL,                
        IMG_GLOBAL_BACK,                  
        g_mmi_java_current_installing_mids_name,                                          
        g_java.download_percentage,       
        (U8*)g_java.download_string);     
                                          
    SetRightSoftkeyFunction(mmi_java_mids_install_abort, KEY_EVENT_UP);                      
#endif
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_get_file_and_save_ind   
 * DESCRIPTION                            
 *  This routines handles MMI_WAP_GET_FILE_AND_SAVE_IND  from MOD_WAP to                  
 *  display a animation to indicate the user Downloading is processing                    
 * PARAMETERS                             
 *  MsgStruct       [?]                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static mmi_java_get_file_and_save_ind_struct java_get_file_and_save_ind_msg;              
void mmi_java_recv_get_file_and_save_ind(void *MsgStruct)                                 
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_WAP_GET_FILE_AND_SAVE_IND);                             
                                          
    kal_mem_cpy(                          
        &java_get_file_and_save_ind_msg,  
        (mmi_java_get_file_and_save_ind_struct*) MsgStruct,                               
        sizeof(mmi_java_get_file_and_save_ind_struct));                                   
    if(g_mmi_java_is_background_display){ 
        mmi_java_send_get_file_and_sav_res();                                             
        return;                           
    }
#ifdef __PLUTO_MMI_PACKAGE__
    if(mmi_frm_scrn_get_active_id() == SCR_JAVA_SHOW_PERCENTAGE)                          
    {                                     
       mmi_frm_scrn_close_active_id();    
    }                                     
    mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_SHOW_PERCENTAGE);
#endif
    mmi_java_send_get_file_and_sav_res(); 
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_send_java_get_file_and_sav_res                                               
 * DESCRIPTION                            
 *  This routines send MSG_ID_MMI_WAP_GET_FILE_AND_SAVE_RES to MOD_WAP to send            
 *  response                              
 * PARAMETERS                             
 *  void                                  
 *  IN   confirm    KAL_TRUE if really want to install this MIDS(?)                       
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_send_get_file_and_sav_res(void)                                             
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_get_file_and_save_res_struct *msg;                                           
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_WAP_GET_FILE_AND_SAVE_RES);                             
    /* ClearInputEventHandler(MMI_DEVICE_ALL); */                                         
                                          
    msg = (mmi_java_get_file_and_save_res_struct*) OslConstructDataPtr(sizeof(mmi_java_get_file_and_save_res_struct));                    
                                          
    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,                                 
        MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_RES, msg);                                
}                                         
#endif // __MMI_JAVA_INSTALL_DOWNLOAD_JAR_IND__                                
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_send_java_abort_req          
 * DESCRIPTION                            
 *                                        
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_send_java_abort_req(void)   
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_abort_req_struct *msg;       
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_ABORT_REQ);                                   
                                          
    if (g_java.mids_install_state > INSTALL_VALID_STATE && g_java.mids_install_state != INSTALL_INVALID_STATE)                            
    {                                     
        g_java.mids_install_state = INSTALL_ABORT_STATE;                                  
    }                                     
    else if (g_java.mids_update_state > UPDATE_VALID_STATE && g_java.mids_update_state != UPDATE_INVALID_STATE)                           
    {                                     
        g_java.mids_update_state = UPDATE_ABORT_STATE;                                    
    }                                     
                                          
    msg = (mmi_java_abort_req_struct*) OslConstructDataPtr(sizeof(mmi_java_abort_req_struct));                                            
                                          
                                          
    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,                                 
        MSG_ID_MMI_JAVA_ABORT_REQ, msg);                                            
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_send_install_abort_req       
 * DESCRIPTION                            
 *                                        
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_send_delete_menu_abort_req(void)                                            
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if(g_mmi_java_reinstall_state>0)
    {
        g_java.mids_install_state = INSTALL_VALID_STATE;
        g_java.mids_update_state = UPDATE_VALID_STATE;
        g_java.is_local_install = MMI_FALSE;
        g_java.is_at_install = MMI_FALSE;
        mmi_java_clear_install_info();
        mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,MSG_ID_MMI_JAVA_DELETE_MENU_ABORT_REQ, NULL);                               
    }                                         
}
mmi_ret mmi_java_mids_after_delete_menu_abort_proc(mmi_event_struct* evt)                           
{ 
    switch(evt->evt_id)                   
    {          
        case EVT_ID_POPUP_QUIT:   
            mmi_java_mids_installer_group_close();  
            break;                            
    }                                     
    return MMI_RET_OK;
}


/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_delete_menu_abort_cnf   
 * DESCRIPTION                            
 *  This routines handles MMI_JAVA_ABORT_CNF  from MOD_J2ME to popup a screen             
 *  indicating VM terminates its process. 
 * PARAMETERS                             
 *  MsgStruct       [?]                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_delete_menu_abort_cnf(void *MsgStruct)                                 
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if (g_mmi_java_reinstall_state == 1)  
    {                                     
#ifdef __DM_LAWMO_SUPPORT__               
        if(srv_dm_lawmo_is_locked())      
        {                                 
            g_mmi_java_is_background_display = MMI_TRUE;                                  
        }                                 
#endif /* __DM_LAWMO_SUPPORT__ */         
        /* different case different popup */                                              
        if(!g_mmi_java_is_background_display)                                             
        {                                 
            U16 str_id;
            if (g_mmi_java_abort_error_code ==MMI_JAVA_ABORT_FOR_IN_VOICE_CALL)           
            {                             
                str_id = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;
            }                             
            else if(g_mmi_java_abort_error_code == MMI_JAVA_ABORT_FOR_DISK_OPERATION_FAILED)                                              
            {                             
                str_id = STR_JAVA_ERROR_CODE_DISK_OP_FAILURE;
            }                             
            else                          
            {                             
                str_id = STR_JAVA_ERROR_CODE_CANCEL;               
            }  
            g_mmi_java_abort_error_code = MMI_JAVA_ABORT_NO_ERROR;
            #ifdef __PLUTO_MMI_PACKAGE__
            {
                mmi_popup_property_struct arg;
                mmi_popup_property_init(&arg);  
                arg.callback = mmi_java_mids_installer_group_close_proc;
                mmi_popup_display((WCHAR*)((UI_string_type)GetString(str_id)), MMI_EVENT_FAILURE, &arg);
            }                             
            #elif __COSMOS_MMI_PACKAGE__
            vapp_java_close_venus_screen();
            vapp_java_display_popup(str_id,VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_NONE);
            #else
            ASSERT(0);
            #endif
        }                                 
        if(g_java.is_at_install)          
        {                                 
            mmi_java_send_at_loacl_install_cnf(USER_CANCEL);                              
            g_java.is_at_install = MMI_FALSE;                                             
        }                                 
    }                                     
                                          
    /* Resume background play */          
    mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_JAVA);                     
    if(g_java.mids_delete_state != DELETE_VM_STATE)                                       
    {                                     
        mmi_java_report_status(g_mmi_java_current_running_cmd,J2ME_ABORT_FAIL,NULL,NULL,NULL);                                            
    }
    if(g_mmi_java_current_installing_mids_name)
    {
        free_ctrl_buffer(g_mmi_java_current_installing_mids_name);
        g_mmi_java_current_installing_mids_name = NULL;
    }
    g_java_need_storage_size = 0;         
    g_mmi_java_reinstall_state = 0;       
    g_mmi_java_install_progress = 0;
    mmi_java_clear_install_info();
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_java_abort_cnf          
 * DESCRIPTION                            
 *  This routines handles MMI_JAVA_ABORT_CNF  from MOD_J2ME to popup a screen             
 *  indicating VM terminates its process. 
 * PARAMETERS                             
 *  MsgStruct       [?]                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_java_abort_cnf(void *MsgStruct)                                        
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_abort_cnf_struct *msg;       
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_ABORT_CNF);                                   
                                          
    msg = (mmi_java_abort_cnf_struct*) MsgStruct;                                         
                                          
    if (msg->error_code != J2ME_NO_ERROR) 
    {                                     
        #ifdef __PLUTO_MMI_PACKAGE__
        {
            mmi_popup_property_struct arg;
            mmi_popup_property_init(&arg);
            mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_JAVA_CANCELLED)), MMI_EVENT_FAILURE, &arg);
        }                         
        #elif __COSMOS_MMI_PACKAGE__
        vapp_java_display_popup(STR_JAVA_CANCELLED, VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
        #else
            ASSERT(0);
        #endif

    }                                     
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_local_install_content_routing
 * DESCRIPTION                            
 *  Parse information in the MIDlet before start to local install                         
 * PARAMETERS                             
 *  file_path       [IN]        The file path of MIDlet which user want to install        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_local_install_content_routing(U16* file_path)                              
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    int len;                              
    U16 *jad_file = NULL;                 
    U16 *jar_file = NULL;                 
    kal_int32 error_code = J2ME_NO_ERROR;
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if(g_mmi_java_current_running_cmd != MMI_JAVA_CMD_END)                                
    {                                     
#ifdef __PLUTO_MMI_PACKAGE__
        mmi_java_display_is_busy();       
#elif __COSMOS_MMI_PACKAGE__
        vapp_java_display_popup(STR_ID_VAPP_JAVA_VM_BUSY,VJAVA_POPUP_WARNING,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
#endif
        return;                       
    }                                     
                                          
    g_java.is_local_install = MMI_TRUE;   
    g_mmi_java_is_background_display = KAL_FALSE;                                         
                                          
    len = mmi_ucs2strlen((const CHAR *)file_path);                                           
                                          
    if (file_path[len - 1] == 'd' || file_path[len - 1] == 'D')                           
    {                                     
        jad_file = get_ctrl_buffer((len + 1) << 1);                                       
        mmi_ucs2cpy((CHAR *)jad_file, (CHAR *)file_path);                                       
        g_mmi_java_current_running_cmd = MMI_JAVA_CMD_INSTALL_BY_USER;                    
        mmi_java_mids_install(jad_file, NULL, L"file://", MMI_FALSE);              
    }                                     
    else                                  
    {                                     
        jar_file = get_ctrl_buffer((len + 1) << 1);                                       
        mmi_ucs2cpy((CHAR *)jar_file, (CHAR *)file_path);                                       
        g_mmi_java_current_running_cmd = MMI_JAVA_CMD_INSTALL_BY_USER;                    
        mmi_java_mids_install(NULL, jar_file, L"file://", MMI_FALSE); 
    }                                     
    if(error_code != J2ME_NO_ERROR)
    {
    
#ifdef __PLUTO_MMI_PACKAGE__
        {
            mmi_popup_property_struct arg;
            mmi_popup_property_init(&arg);
            mmi_popup_display((WCHAR*)GetString(get_str_id_by_error_code(error_code)), MMI_EVENT_FAILURE, &arg);
        }                         
#elif __COSMOS_MMI_PACKAGE__
        vapp_java_display_popup(get_str_id_by_error_code(error_code), VJAVA_POPUP_FAILURE,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
#else
            ASSERT(0);
#endif

    }
    if(jad_file) free_ctrl_buffer(jad_file);                                              
    if(jar_file) free_ctrl_buffer(jar_file);                                              
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_at_loacl_install_res    
 * DESCRIPTION                            
 *  Handle Function: revoked when receive MMI_JAVA_AT_LOCAL_INSTALL_CNF                   
 * PARAMETERS                             
 *  MsgStruct       [IN]        The message sent from AT command. We will pass to Java task.                                              
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_send_at_loacl_install_cnf(S32 error_code)                                   
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_local_install_res_req_struct* p;                                             
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_AT_LOCAL_INSTALL_CNF);                             
                                          
    p = (mmi_java_local_install_res_req_struct*) OslConstructDataPtr(sizeof(mmi_java_local_install_res_req_struct));                      
                                          
    p->error_code = error_code;           
                                          
    mmi_java_send_message_from_active_mod( MOD_L4C, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_LOCAL_INSTALL_RES_REQ, p);                                
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_at_local_install_req    
 * DESCRIPTION                            
 *  Handle Function: revoked when receive MMI_JAVA_AT_LOCAL_INSTALL_REQ                   
 * PARAMETERS                             
 *  MsgStruct       [IN]        The message sent from AT command. We will pass to java task                                               
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_at_local_install_req(void *MsgStruct)                                  
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_local_install_req_ind_struct *s = (mmi_java_local_install_req_ind_struct*) MsgStruct;                                        
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_AT_LOCAL_INSTALL_REQ);                             
    if(g_mmi_java_current_running_cmd != MMI_JAVA_CMD_END || !mmi_java_is_in_idle_screen()
    #ifndef __SUPPORT_NATIVE_INSTALLER__   
        ||jam_vm_is_busy() 
    #else
        ||!jam_vm_task_ready()
    #endif
    )                                
    {                                     
        #ifdef __PLUTO_MMI_PACKAGE__
        mmi_java_display_is_busy();       
        #elif __COSMOS_MMI_PACKAGE__        
        vapp_java_display_popup(STR_ID_VAPP_JAVA_VM_BUSY,VJAVA_POPUP_WARNING,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
        #else
        #endif
        mmi_java_send_at_loacl_install_cnf(J2ME_INSTALL_FAIL);                            
        goto FINAL;                       
    }                                     
    g_mmi_java_is_background_display = MMI_FALSE;                                         

    g_mmi_java_current_running_cmd = MMI_JAVA_CMD_INSTALL_BY_USER;                        
                                          
    g_java.is_at_install = MMI_TRUE;      
    mmi_java_mids_install((U16*)s->jad_file_name, (U16*)s->jar_file_name, L"file://", MMI_FALSE);                                      
                                          
FINAL:                                    
    if(s->jad_file_name!=NULL)            
        free_ctrl_buffer(s->jad_file_name);                                               
    if(s->jar_file_name!=NULL)            
        free_ctrl_buffer(s->jar_file_name);                                               
}                                         
                                          
                                          
#define __MMI_JAVA_INSTALL_SELECT_DRV__   
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_send_get_install_drv_res     
 * DESCRIPTION                            
 * PARAMETERS                             
 *  drv     [IN]                          
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_send_get_install_drv_res(S8 drv)                                           
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_get_install_drv_res_struct *msg;                                             
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    msg = (mmi_java_get_install_drv_res_struct*) OslConstructDataPtr(sizeof(mmi_java_get_install_drv_res_struct));                        
                                          
    if(drv == 0)  /* User Cancel */       
    {                                     
        msg->drv = -1;                    
    }                                     
    else                                  
    {                                     
        msg->drv = drv;                   
    }                                     
                                          
    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,                                 
        MSG_ID_MMI_JAVA_GET_INSTALL_DRV_RES, msg);                                  
}                                         
                                          
void mmi_java_entry_select_install_drv(void)
{
    mmi_id fmgr_storage_selector_gid;
    if ((fmgr_storage_selector_gid = cui_storage_selector_create(g_java_installer_cui_gid, 0, CUI_STORAGE_SELECTOR_DRV_TYPE_ACCESIBLE_ONLY)) != GRP_ID_INVALID)
    {
        cui_storage_selector_set_title(fmgr_storage_selector_gid,0 , mmi_java_get_install_title_icon());
        cui_storage_selector_set_ui_style(fmgr_storage_selector_gid, CUI_FMGR_UI_STYLE_BANNER_LIST);//NEED TEST
#ifdef __PLUTO_MMI_PACKAGE__
        cui_storage_selector_set_is_disable_ncenter(fmgr_storage_selector_gid, KAL_TRUE);
#endif
        cui_storage_selector_run(fmgr_storage_selector_gid);
    }
}
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_get_install_drv_ind     
 * DESCRIPTION                            
 * PARAMETERS                             
 *  MsgStruct       [?]                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_get_install_drv_ind(void *MsgStruct)                                   
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if(g_mmi_java_is_background_display)  
    {                                     
        S8 drv =(S8)SRV_FMGR_PUBLIC_DRV;       
        mmi_java_send_get_install_drv_res(drv);                                           
        return;                           
    }                                     
    #ifdef __PLUTO_MMI_PACKAGE__
    mmi_java_entry_select_install_drv();
    #elif __COSMOS_MMI_PACKAGE__
    vapp_java_entry_select_install_drv();
    #endif
}                                         
                                          
#ifdef __MMI_JAVA_CATEGORY_SUPPORT__      
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_send_get_install_category_res
 * DESCRIPTION                            
 * PARAMETERS                             
 *  drv     [IN]                          
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_send_get_install_category_res(kal_int32 category)                           
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_get_install_category_res_struct *msg;                                        
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    msg = (mmi_java_get_install_category_res_struct*) OslConstructDataPtr(sizeof(mmi_java_get_install_category_res_struct));              
    msg->category = category;             
    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,                                 
        MSG_ID_MMI_JAVA_GET_INSTALL_CATEGORY_RES, msg);                             
}                                         
                                          
typedef struct _mmi_java_category_list_struct_t                                           
{                                         
    kal_uint16 img_idx;                   
    kal_uint16 title_idx;                 
}mmi_java_category_list_struct;           
mmi_java_category_list_struct g_install_category_list[]={                                 
    {                                     
        #ifdef __MMI_MY_FAVORITE_JAVABOX__
            IMG_ID_MY_FAVORITE_FOLDER_JAVABOX, STR_ID_MY_FAVORITE_FOLDER_JAVABOX          
        #else                             
            IMG_MENU3108_JAVA,STR_SCR_JAVA_CAPTION                                        
        #endif                            
    },                                    
    {                                     
        #ifdef __MMI_MY_FAVORITE_JAVABOX__
            IMG_ID_MY_FAVORITE_FOLDER_GPLUSGAME, STR_ID_MY_FAVORITE_FOLDER_GPLUSGAME      
        #else                             
            IMG_MENU3108_JAVA,STR_SCR_JAVA_CAPTION                                        
        #endif                            
    }                                     
                                          
};                                        
static kal_int32 g_mmi_java_category_current_hilite_index;                                
                                          
kal_uint32 get_java_category_list_count(void)                                             
{                                         
    return sizeof(g_install_category_list)/sizeof(mmi_java_category_list_struct);         
}                                         
mmi_java_category_list_struct* get_java_category_list_item(kal_int32 index)               
{                                         
    return &g_install_category_list[index];                                               
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  GetHiliteIndex                        
 * DESCRIPTION                            
 *  Get current highlight index           
 * PARAMETERS                             
 *  nIndex      [IN]                      
 *  a(?)        [IN]        Current highlight index                                       
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_get_install_category_hilite_Index(S32 nIndex)                               
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    g_mmi_java_category_current_hilite_index = nIndex;                                    
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_mids_get_install_category_select_hdlr                                        
 * DESCRIPTION                            
 *  Handle Function, revoked when select "YES" in "INSTALL CONFIRM" screen                
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_mids_select_category_lsk_hdlr(void)                                         
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    mmi_frm_scrn_close_active_id();       
    mmi_java_send_get_install_category_res(g_mmi_java_category_current_hilite_index);     
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_mids_select_install_category_cancel_hdlr                                     
 * DESCRIPTION                            
 *  Handle Function, revoked when select "NO" in "INSTALL CONFIRM" screen                 
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_mids_select_category_cancel_hdlr(void)                                      
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    mmi_frm_scrn_close_active_id();       
                                          
    mmi_java_send_get_install_category_res(-1);                                           
                                          
    if(g_java.mids_install_state != INSTALL_INVALID_STATE)                                
    {                                     
        g_java.mids_install_state = INSTALL_ABORT_STATE;                                  
    }                                     
    else if(g_java.mids_update_state  != UPDATE_INVALID_STATE)                            
    {                                     
        g_java.mids_update_state = UPDATE_ABORT_STATE;                                    
    }                                     
    else                                  
    {                                     
        ASSERT(0);                        
    }                                     
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_get_install_category   
 * DESCRIPTION                            
 *                                        
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
S32 mmi_java_get_install_category_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{                                         
    S32 index = 0;
    for(index = 0; index<data_size; index++)
    {
        mmi_java_category_list_struct* ptr = get_java_category_list_item(index); 
        mmi_ucs2cpy((CHAR *) menu_data[index].item_list[0], GetString(ptr->title_idx));
        menu_data[index].image_list[0]= (PU8) GetImage((U16) ptr->img_idx);
        start_index++;
    }
    return data_size;
}                                         

/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_select_install_category
 * DESCRIPTION                            
 *                                        
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_entry_select_category(void) 
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    U8 *guiBuffer;                        
    U8 *str;                              
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
 if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_INSTALL_CATEGORY, NULL, mmi_java_entry_select_category, MMI_FRM_FULL_SCRN))                                              
    {                                     
        return;                           
    }                                     
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_java_installer_cui_gid, SCR_JAVA_INSTALL_CATEGORY);                                            
                                          
    RegisterHighlightHandler(mmi_java_get_install_category_hilite_Index);                 
    
    wgui_cat1032_show(
        (WCHAR*) GetString(STR_GLOBAL_INSTALL),
        (PU8) GetImage(mmi_java_get_install_title_icon()),
        (WCHAR*) GetString(STR_GLOBAL_SELECT),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (WCHAR*) GetString(STR_GLOBAL_CANCEL),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        get_java_category_list_count(),
        (GetAsyncItemFuncPtr)mmi_java_get_install_category_item_async,
        NULL,
        0,
        0,    
        IMG_GLOBAL_L1,
        0,
        guiBuffer,
        NULL);    
            
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_mids_select_category_lsk_hdlr,KEY_EVENT_UP);  
    SetLeftSoftkeyFunction(mmi_java_mids_select_category_lsk_hdlr, KEY_EVENT_UP);         
    SetRightSoftkeyFunction(mmi_java_mids_select_category_cancel_hdlr, KEY_EVENT_UP);     
                                          
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);                                           
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_get_install_category_ind
 * DESCRIPTION                            
 * PARAMETERS                             
 *  MsgStruct       [?]                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_get_install_category_ind(void *MsgStruct)                              
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if(g_mmi_java_is_background_display)                                 
    {                                     
        mmi_java_send_get_install_category_res(0);                                        
    }                                     
    else                                  
    {   
#ifdef __PLUTO_MMI_PACKAGE__    
        mmi_java_entry_select_category(); 
#elif __COSMOS_MMI_PACKAGE__
        mmi_java_send_get_install_category_res(0);
#else
#endif
    }                                     
}                                         
#endif                                    
#ifdef __MMI_JAVA_INSTALL_AUTHENTICATION__                    
static U8 g_java_auth_username[ MMI_JAVA_AUTH_LEN_USERNAME * ENCODING_LENGTH];            
static U8 g_java_auth_password[ MMI_JAVA_AUTH_LEN_PASSWORD * ENCODING_LENGTH]; 

/*************************************************************************                
* FUNCTION                                
* DESCRIPTION                             
* PARAMETERS                              
* RETURNS                                 
*************************************************************************/                
void mmi_java_send_get_auth_res(U8* username, U8* password)                               
{                                         
                                          
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_get_auth_res_struct *msg;    
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    msg = (mmi_java_get_auth_res_struct*) OslConstructDataPtr(sizeof(mmi_java_get_auth_res_struct));                                      
                                          
    mmi_ucs2cpy((CHAR *)msg->username, (CHAR *) username);                                      
    mmi_ucs2cpy((CHAR *)msg->password, (CHAR *) password);                                      
                                          
    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,                                 
        MSG_ID_MMI_JAVA_GET_AUTH_RES, msg);                                         
}  

#ifdef __PLUTO_MMI_PACKAGE__
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_auth_yes_hdlr                
 * DESCRIPTION                            
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_auth_yes_hdlr(void)  
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    // TODO                               
    mmi_java_send_get_auth_res(g_java_auth_username, g_java_auth_password);  
    mmi_frm_scrn_close_active_id();
    cui_inline_close(g_java_auth_inline);
}                              
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_auth_cancel_hdlr             
 * DESCRIPTION                            
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_auth_no_hdlr(void)   
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    // TODO                               
    mmi_java_send_get_auth_res(NULL, NULL);  
    mmi_frm_scrn_close_active_id(); 
    cui_inline_close(g_java_auth_inline);
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_auth_confirm_hdlr            
 * DESCRIPTION                            
 *  Function for submitting the authentication information                                
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_auth_confirm_hdlr(void)                                              
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    cui_inline_get_value(g_java_auth_inline,JAVA_TEXTEDIT_USERNAME,(void *)g_java_auth_username);
    cui_inline_get_value(g_java_auth_inline,JAVA_TEXTEDIT_PASSWORD,(void *)g_java_auth_password);          
    if(mmi_ucs2strlen((CHAR *)g_java_auth_username) == 0)                                    
    {                                     
        mmi_popup_property_struct arg;
        mmi_popup_property_init(&arg);
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_DA_EMPTY_USERNAME)), MMI_EVENT_FAILURE, &arg);
        return;                           
    }                                     
    else                                  
    {                                     
        do {
            mmi_confirm_property_struct arg;
            mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
            arg.softkey[0].str = (WCHAR *)((UI_string_type)get_string(STR_GLOBAL_YES));
            arg.softkey[2].str = (WCHAR *)((UI_string_type)get_string(STR_GLOBAL_NO));
            arg.callback = (mmi_proc_func)NULL;
            arg.parent_id = GRP_ID_ROOT;
            mmi_confirm_display((WCHAR *)((UI_string_type)get_string(STR_ID_DA_POPUP_SEND_ASK)), MMI_EVENT_QUERY, &arg);
        } while(0);            
        SetLeftSoftkeyFunction(mmi_java_auth_yes_hdlr, KEY_EVENT_UP);                     
        SetRightSoftkeyFunction(mmi_java_auth_no_hdlr, KEY_EVENT_UP);                     
    }                                     
                                          
}                                         

/*************************************************************************                
* FUNCTION                                
* DESCRIPTION                             
* PARAMETERS                              
* RETURNS                                 
*************************************************************************/   
void mmi_java_entry_auth(void)            
{
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/  
    extern void cui_inline_register_lsk_handler(void);
    extern void cui_inline_register_rsk_handler(void);
    static const cui_inline_item_caption_struct caption_username =  {STR_GLOBAL_USERNAME};
    static const cui_inline_item_text_edit_struct textedit_username = {
                 0, 
                 0, 
                 MMI_JAVA_AUTH_LEN_USERNAME,
                 IMM_INPUT_TYPE_ENGLISH_SENTENCE, 
                 INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                 NULL };
    static const cui_inline_item_caption_struct caption_password =  {STR_GLOBAL_PASSWORD};
    static const cui_inline_item_text_edit_struct textedit_password = {
                 0, 
                 0, 
                 MMI_JAVA_AUTH_LEN_PASSWORD,
                 IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD, 
                 INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                 NULL };  

    static const cui_inline_set_item_struct java_auth_inline_content[ ] =
     {
         {JAVA_CAPTION_USERNAME, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void *)&caption_username},         
         {JAVA_TEXTEDIT_USERNAME, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void *)&textedit_username},
         {JAVA_CAPTION_PASSWORD, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void *)&caption_password},         
         {JAVA_TEXTEDIT_PASSWORD, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void *)&textedit_password},
     };    
 
    static const cui_inline_struct java_auth_inline = {
        4,  /* item count */
        STR_GLOBAL_AUTHENTICATION,                  /* screen title string id */
        0,  /* screen title icon id */
        CUI_INLINE_SCREEN_DEFAULT_TEXT,  /* screen attribute, set flag what you want */   
        NULL,  /* if you want to set all softkey the same label/icon, you can set here */
        java_auth_inline_content  /* item special data array. */
    };
           
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    /*---------- Modifed by mtk80493 for 10 A ------------*/
   // temp_parent_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_java_mids_install_group_proc, NULL);                            
   // mmi_frm_group_enter(temp_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);  
    g_java_auth_inline = cui_inline_create(g_java_installer_cui_gid, &java_auth_inline);
    cui_inline_set_title_icon(g_java_auth_inline,mmi_java_get_install_title_icon());
    cui_inline_register_lsk_handler();
    cui_inline_register_rsk_handler();
    cui_inline_run(g_java_auth_inline); 
    /* ---------------------------------------------- */
}                                         
#endif // __PLUTO_MMI_PACKAGE__

                                      
/*************************************************************************                
* FUNCTION                                
* DESCRIPTION                             
* PARAMETERS                              
* RETURNS                                 
*************************************************************************/                
void mmi_java_recv_get_auth_ind(void *MsgStruct)                                          
{                                         
                                          
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    memset(g_java_auth_username, 0, sizeof(g_java_auth_username));                        
    memset(g_java_auth_password, 0, sizeof(g_java_auth_password));                        
    if(g_mmi_java_is_background_display)  
    {                                     
        mmi_java_send_get_auth_res(NULL, NULL);                                           
        return;                           
    }
    
    #ifndef __COSMOS_MMI_PACKAGE__
    mmi_java_entry_auth();                
    #else
    vapp_java_entry_auth();
    #endif
}  

#endif //__MMI_JAVA_INSTALL_AUTHENTICATION__


/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_busy
 * DESCRIPTION
 *  the function checks is push allowed launch
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_java_is_busy(void)
{
    return (MMI_BOOL)(g_java.mids_install_state != INSTALL_VALID_STATE 
        || g_java.mids_delete_state != DELETE_VALID_STATE
        || g_java.mids_update_state != UPDATE_VALID_STATE                
        || g_mmi_java_reinstall_state > 0 
        || (g_java.msg_ctrl & SEND_MID_SET_SETTING_CTRL)
        || g_mmi_java_is_in_package
        || jam_is_busy());
}

/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_is_push_allowed_launch       
 * DESCRIPTION                            
 *  the function checks is push allowed launch                                            
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
MMI_BOOL mmi_java_is_push_allowed_to_launch(void)                                         
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
                                          
    /* install */                         
    if (g_java.mids_install_state != INSTALL_VALID_STATE || g_mmi_java_reinstall_state > 0)                                               
    {                                     
        return MMI_FALSE;                 
    }                                     
                                          
    /* update */                          
    if (g_java.mids_update_state != UPDATE_VALID_STATE)                                   
    {                                     
        return MMI_FALSE;                 
    }                                     
                                          
    /* delete */                          
    if (g_java.mids_delete_state != DELETE_VALID_STATE)                                   
    {                                     
        return MMI_FALSE;                 
    }
                                
#ifdef __MMI_WEBCAM__                    
    if(mmi_usb_webcam_is_active())
    {
        return MMI_FALSE;
    }
#endif

#ifdef __MMI_USB_SUPPORT__
    if(srv_usb_is_in_mass_storage_mode())
    {
        return MMI_FALSE;
    }
#endif

#ifdef __PLUTO_MMI_PACKAGE__     
#ifdef __DM_LAWMO_SUPPORT__
    if(srv_dm_lawmo_is_locked())
    {
         return MMI_FALSE;
    }
#endif /* __DM_LAWMO_SUPPORT__ */
#endif

    /* Do not allow push when ASM prompt */                                               
    if(g_is_asm_allow_to_launch == KAL_FALSE)                                             
    {                                 
        return MMI_FALSE;             
    }                                 
    
    if(g_jam_user_update_setting_exclusive)
    {
        return MMI_FALSE;
    }
    
    if (jam_mvm_is_shutdowning())
    {
        return MMI_FALSE;
    }
    
    if (jam_mvm_has_launching_midlet())
    {
        return MMI_FALSE;
    }
	
    return MMI_TRUE;                      
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_storage_size_is_enough       
 * DESCRIPTION                            
 *  This function is to calculate free size of current installed directory                
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
MMI_BOOL mmi_java_storage_size_is_enough(void)                                            
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    kal_uint64 free_space = 0;            
    FS_DiskInfo DiskInfo;                 
    U16 path[4] = {'C', ':', '\\', 0};    
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    path[0] = g_java_storage_drive;                                             
    if(FS_GetDiskInfo(path, &DiskInfo, FS_DI_FREE_SPACE|FS_DI_BASIC_INFO) >= 0)           
    {                                     
        free_space = (kal_uint64)DiskInfo.FreeClusters * (kal_uint64)DiskInfo.SectorsPerCluster * (kal_uint64)DiskInfo.BytesPerSector;    
    }                                     
    else                                  
    {                                     
        g_java_need_storage_free_size = -50;
        mmi_java_reset_delete_menu_parameter(NULL);
        return MMI_FALSE;                 
    }                                     
    if(free_space > g_java_need_storage_size)                                             
    {                                     
        return MMI_TRUE;                  
    }                                     
    else                                  
    {                                     
                                          
        g_java_need_storage_free_size = g_java_need_storage_size - free_space;            
        return MMI_FALSE;                 
    }                                     
                                          
}                                         
#ifdef __MMI_JAVA_INSTALL_PUSHINSTALL__  
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_backup_install_info_for_push_install                                         
 * DESCRIPTION                            
 *  add current push_install_ind to queue 
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_backup_install_info_for_push_install(mmi_java_push_install_record_struct *content, U16 *drm_file_path, S32 drm_serial)      
{                                         
     /*----------------------------------------------------------------*/                 
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_BACKUP_INSTALL_INFO_FOR_PUSH_INSTALL);             
    if(mmi_download_url)                  
    {                                     
        content->download_url= (U16 *)get_ctrl_buffer((7+1) * ENCODING_LENGTH);           
        kal_wsprintf(content->download_url,"file://");                                    
    }                                     
    else                                  
    {                                     
         content->download_url = NULL;    
    }                                     
    if(mmi_jad_file_name)                 
    {                                     
        content->jad_file_path = (U16 *)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)mmi_jad_file_name)+1) * ENCODING_LENGTH);                    
        mmi_ucs2cpy((CHAR *)content->jad_file_path, (CHAR *)mmi_jad_file_name);                 
    }                                     
    else                                  
    {                                     
        content->jad_file_path = NULL;    
    }                                     
    if(mmi_jar_file_name)                 
    {                                     
        content->jar_file_path = (U16 *)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)mmi_jar_file_name)+1) * ENCODING_LENGTH);                    
        mmi_ucs2cpy((CHAR *)content->jar_file_path, (CHAR *)mmi_jar_file_name);                 
    }                                     
    else                                  
    {                                     
        /* it means jad installation, but jar is downloaded as drm_file_path */           
        content->jar_file_path = (U16 *)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)drm_file_path)+1)<<2);                                       
        mmi_ucs2cpy((CHAR *)content->jar_file_path, (CHAR *)drm_file_path);                     
    }                                     
    if(drm_file_path)                     
    {                                     
        content->drm_file_path = (U16 *)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)drm_file_path)+1)<<2);                                       
        mmi_ucs2cpy((CHAR *)content->drm_file_path, (CHAR *)drm_file_path);                     
    }                                     
    else                                  
    {                                     
        content->drm_file_path = NULL;    
    }                                     
    content->delete_after_install_fail = mmi_delete_after_install_fail;                   
    content->drm_serial = drm_serial;     
                                          
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_restore_install_info_for_push_install                                        
 * DESCRIPTION                            
 *  retrieve install info from queue      
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_restore_install_info_for_push_install(mmi_java_push_install_record_struct *content)                                         
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RESTORE_INSTALL_INFO_FOR_PUSH_INSTALL);            
                                          
    if(content->download_url)             
    {                                     
        mmi_download_url = (U16 *)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)content->download_url)+1) * ENCODING_LENGTH);                      
        mmi_ucs2cpy((CHAR *)mmi_download_url, (CHAR *)content->download_url);                   
    }                                     
                                          
    if(content->jad_file_path)            
    {                                     
        mmi_jad_file_name = (U16 *)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)content->jad_file_path)+1) * ENCODING_LENGTH);                    
        mmi_ucs2cpy((CHAR *)mmi_jad_file_name, (CHAR *)content->jad_file_path);                 
    }                                     
    if(content->jar_file_path)            
    {                                     
        mmi_jar_file_name = (U16 *)get_ctrl_buffer((mmi_ucs2strlen((CHAR *)content->jar_file_path)+1) * ENCODING_LENGTH);                    
        mmi_ucs2cpy((CHAR *)mmi_jar_file_name, (CHAR *)content->jar_file_path);                 
    }                                     
    mmi_delete_after_install_fail = content->delete_after_install_fail;                   
                                          
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_free_install_info_for_push_install                                           
 * DESCRIPTION                            
 *  free target install info in queue     
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_free_install_info_for_push_install(mmi_java_push_install_record_struct *content)                                            
{                                         
     /*----------------------------------------------------------------*/                 
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_FREE_INSTALL_INFO_FOR_PUSH_INSTALL);               
    if(!content)return;                                      
    if(content->download_url)             
    {                                     
        free_ctrl_buffer(content->download_url);                                          
    }                                     
    if(content->jad_file_path)            
    {                                     
        free_ctrl_buffer(content->jad_file_path);                                         
    }                                     
    if(content->jar_file_path)            
    {                                     
        free_ctrl_buffer(content->jar_file_path);                                         
    }                                     
    if(content->drm_file_path)            
    {                                     
        free_ctrl_buffer(content->drm_file_path);                                         
    }                                     
    /* ungeister sophia */                
                                          
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_register_push_install        
 * DESCRIPTION                            
 *  register a push install.              
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_register_push_install(U16* drm_file_path, S32 drm_serial)            
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_push_install_node_struct *current_node;                                      
    mmi_java_push_install_node_struct *temp_node;                                         
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_REGISTER_PUSH_INSTALL,g_mmi_java_push_install_count);                                              
    current_node = (mmi_java_push_install_node_struct*)get_ctrl_buffer(sizeof(mmi_java_push_install_node_struct));                        
    mmi_java_backup_install_info_for_push_install(&(current_node->content),drm_file_path,drm_serial);                                     
    current_node->right_arrived = MMI_FALSE;                                              
    if (g_mmi_java_push_install_count == 0)                                               
    {                                     
        g_mmi_java_push_install_end = g_mmi_java_push_install_start = current_node;       
        current_node->prev = NULL;        
        current_node->next = NULL;        
        //kal_prompt_trace(MOD_J2ME, "[push install]register serial = %d\n", current_node->content.drm_serial);                           
        g_mmi_java_push_install_count ++; 
    }                                     
    else if(g_mmi_java_push_install_count == MAX_PUSH_INSTALL_REGISTRY)                   
    {                                     
        /* remove end */                  
        temp_node = g_mmi_java_push_install_end;                                          
        g_mmi_java_push_install_end = temp_node->prev;                                    
        g_mmi_java_push_install_end->next = NULL;                                         
        mmi_java_free_install_info_for_push_install(&(temp_node->content));               
        free_ctrl_buffer(temp_node);      
                                          
        /* add to head */                 
        current_node->prev = NULL;        
        current_node->next = g_mmi_java_push_install_start;                               
        g_mmi_java_push_install_start->prev = current_node;                               
        g_mmi_java_push_install_start = current_node;                                     
        //kal_prompt_trace(MOD_J2ME, "[push install]register serial = %d\n", current_node->content.drm_serial);                           
    }                                     
    else                                  
    {                                     
        /* add to head */                 
        current_node->prev = NULL;        
        current_node->next = g_mmi_java_push_install_start;                               
        g_mmi_java_push_install_start->prev = current_node;                               
        g_mmi_java_push_install_start = current_node;                                     
        //kal_prompt_trace(MOD_J2ME, "[push install]register serial = %d\n", current_node->content.drm_serial);                           
        g_mmi_java_push_install_count ++; 
    }                                     
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_find_and_set_push_install    
 * DESCRIPTION                            
 *  find the drm_file is register or not, and set it can install now.                     
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *                                        
 *****************************************************************************/           
static MMI_BOOL mmi_java_find_and_set_push_install(U16 *drm_file_path)                    
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    MMI_BOOL found = MMI_FALSE;           
    mmi_java_push_install_node_struct *current_node;                                      
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_FIND_AND_SET_PUSH_INSTALL);                        
                                          
    for (current_node = g_mmi_java_push_install_start; current_node != NULL; current_node = current_node->next)                           
    {                                     
        if (mmi_ucs2cmp((CHAR *)current_node->content.drm_file_path, (CHAR *)drm_file_path) == 0)                                               
        {                                 
            found = MMI_TRUE;             
            current_node->right_arrived = MMI_TRUE;                                       
        }                                 
    }                                     
    return found;                         
                                          
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_is_allow_push_install        
 * DESCRIPTION                            
 *  check if push install can start or not
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  TRUE or FALSE                         
 *****************************************************************************/           
static MMI_BOOL mmi_java_is_allow_push_install(void)                                      
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    //U8 is_popup_allow;                    
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if (g_mmi_java_is_allow_push_install &&
        mmi_java_is_push_allowed_to_launch())
    {                                     
       return MMI_TRUE;                   
    }                                     
    return MMI_FALSE;                     
                                          
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_get_push_install_node        
 * DESCRIPTION                            
 *  Find the push install node and remove it from the push install list                   
 *  now.                                  
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static mmi_java_push_install_node_struct* 
mmi_java_get_push_install_node(CHAR * drmfilename)                                           
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_push_install_node_struct *current_node = NULL;                               
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    for (current_node = g_mmi_java_push_install_end; current_node != NULL; current_node = current_node->prev)                             
    {                                     
        if ( current_node->content.drm_file_path && drmfilename && mmi_ucs2cmp((CHAR *)current_node->content.drm_file_path, (CHAR *)drmfilename) == 0)                                          
        {                                 
            if (current_node->next)       
            {                             
                current_node->next->prev = current_node->prev;                            
            }                             
            else                          
            {                             
                g_mmi_java_push_install_end = current_node->prev;                         
            }                             
            if (current_node->prev)       
            {                             
                current_node->prev->next = current_node->next;                            
            }                             
            else                          
            {                             
                g_mmi_java_push_install_start = current_node->next;                       
            }                             
            //kal_prompt_trace(MOD_J2ME, "[push install]free  serial = %d\n", current_node->content.drm_serial);                          
            g_mmi_java_push_install_count--;                                              
            break;                        
        }                                 
    }                                     
    return current_node;                  
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_set_push_install_info        
 * DESCRIPTION                            
 *  send push install information to start install      
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_set_push_install_info(void)                                              
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_push_install_node_struct *current_node;                                      
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    current_node = mmi_java_get_push_install_node((CHAR *)g_mmi_java_install_drm_path_push_install);                                         
    if(current_node){                     
        mmi_java_restore_install_info_for_push_install(&(current_node->content));         
        mmi_java_free_install_info_for_push_install(&(current_node->content));            
        if(current_node)free_ctrl_buffer(current_node);                                   
    }            
    g_mmi_java_current_running_cmd = MMI_JAVA_CMD_INSTALL_BY_USER;                        
    mmi_java_set_allow_push_install(KAL_TRUE);                                           
}

void mmi_java_discard_current_push_install_req(void)
{
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_push_install_node_struct *current_node = NULL;                                      
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    current_node = mmi_java_get_push_install_node((CHAR *)g_mmi_java_install_drm_path_push_install);                                         
    if(current_node)
    {
        mmi_java_free_install_info_for_push_install(&(current_node->content)); 
        free_ctrl_buffer(current_node);                                       
    }
    mmi_java_set_allow_push_install(KAL_TRUE);                                            
    g_mmi_java_is_launching_midlet = MMI_FALSE;    

}
#ifdef __PLUTO_MMI_PACKAGE__
static void mmi_java_entry_push_install_confirm_yes_handler(void)                          
{   
    mmi_java_set_push_install_info();
    mmi_java_mids_install_internal();     
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_push_install_confirm_no_hanlder                                        
 * DESCRIPTION                            
 *  when the right of pre-install jar is received, user don't want to install             
 *  now.                                  
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_entry_push_install_confirm_no_hanlder(void)                          
{                                         
    mmi_java_clear_install_info();
    mmi_frm_scrn_close_active_id();       
    mmi_java_set_allow_push_install(MMI_TRUE);
} 
#endif
                                        
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_push_install_confirm_delete_cb                                         
 * DESCRIPTION                            
 *                                        
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
U8 mmi_java_entry_push_install_confirm_delete_cb(void *ptr)                               
{                                         
    mmi_java_discard_current_push_install_req();                                       
    return MMI_FALSE;                     
}                                         
mmi_ret mmi_java_mids_push_install_confirm_screen_leave_proc(mmi_event_struct *evt)       
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    switch(evt->evt_id)                   
    {                                     
    case EVT_ID_SCRN_DEINIT:              
        mmi_java_entry_push_install_confirm_delete_cb(NULL); 
                mmi_java_mids_installer_group_close(); 
        break;                            
    }                                     
    return MMI_RET_OK;                    
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_get_push_install_confirm_string   
 * DESCRIPTION                            
 *  get comfrim string, which will be show on dialog.
 * PARAMETERS                             
 * void                       
 * RETURNS                                
 * U16* : need free by free ctrl buffer                              
 *****************************************************************************/           
U16* mmi_java_get_push_install_confirm_string(void)
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    U16 str2[MMI_JAVA_MAX_DRM_FILE_NAME+1];                                               
    U16 *str1 = NULL;                     
    U16 str_len;                          
    S16 i,j;                              
    U16 drm_path_len = get_ucs2_len(g_mmi_java_install_drm_path_push_install);            
    S32 fh;                               
    U16 *str;
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
        str = (U16*) GetString(STR_JAVA_PUSH_INSTALL_ASK);                                
        str_len=get_ucs2_len(str);        
        str1 = (U16*)get_ctrl_buffer((str_len+MMI_JAVA_MAX_DRM_FILE_NAME+1)<<1);          
                                          
        mmi_ucs2cpy((CHAR *)str1,(CHAR *)str);  
        for (i=0; i<str_len; i++)         
        {                                 
            if (str1[i]==L'%')            
            {                             
                 str1[i] = L'\0';         
                 break;                   
            }                             
        }                                 
                                          
        if (i == str_len)                 
        {                                 
            ASSERT (0);                   
        }                                 
                                          
        for (j=drm_path_len; j>0; j--)    
        {                                 
            if (g_mmi_java_install_drm_path_push_install[j] == L'\\')                     
            {                             
                break;                    
            }                             
        }                                 
        if (drm_path_len-j > MMI_JAVA_MAX_DRM_FILE_NAME+1)                                
        {                                 
            fh = FS_Open(g_mmi_java_install_drm_path_push_install, FS_READ_ONLY);         
            FS_MakeFileName(fh, 0, (WCHAR*)str2, MMI_JAVA_MAX_DRM_FILE_NAME);             
            FS_Close(fh);                 
        }                                 
        else                              
        {                                 
            mmi_ucs2ncpy((CHAR *)str2,(CHAR *)&g_mmi_java_install_drm_path_push_install[j+1],MMI_JAVA_MAX_DRM_FILE_NAME);                       
        }                                 
        mmi_ucs2cat((CHAR *)str1,(CHAR *)str2); 
        mmi_ucs2cat((CHAR *)str1,(CHAR *)&str[i+2]);                                            
    return str1;
                                          
}
#ifdef __PLUTO_MMI_PACKAGE__
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_push_install_confirm   
 * DESCRIPTION                            
 *  when the right of pre-install jar is received, ask user want to continue              
 *  install or not.                       
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_entry_push_install_confirm(void)                                     
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/  
    U16 *str1 = NULL; 
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_ENTRY_PUSH_INSTALL_CONFIRM);                       
                              
    mmi_frm_start_scenario(MMI_SCENARIO_ID_JAVA_MID_INSTALL);
    if(g_java_installer_cui_gid == GRP_ID_INVALID)
    {                                 
        g_java_installer_cui_gid =mmi_java_mids_installer_create_group();                         
    }                                 
    if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_PUSH_INSTALL_CONFIRM, NULL, mmi_java_entry_push_install_confirm, MMI_FRM_FULL_SCRN))                                   
    {                                 
        return;                       
    }                                 
                                      
    mmi_frm_scrn_set_leave_proc(g_java_installer_cui_gid, SCR_JAVA_PUSH_INSTALL_CONFIRM, mmi_java_mids_push_install_confirm_screen_leave_proc);                                       
                                      
    str1 = mmi_java_get_push_install_confirm_string();                                          
    ShowCategory74Screen(             
        STR_JAVA_RIGHT_ARRIVED,       
        mmi_java_get_install_title_icon(),                                            
        STR_GLOBAL_YES,               
        IMG_GLOBAL_YES,               
        STR_GLOBAL_NO,                
        IMG_GLOBAL_NO,                
        (PU8)str1,                    
        mmi_ucs2strlen((CHAR *) str1),   
        NULL);                        
                                      
    free_ctrl_buffer(str1);           
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_entry_push_install_confirm_yes_handler,KEY_EVENT_UP);  
    SetLeftSoftkeyFunction(mmi_java_entry_push_install_confirm_yes_handler, KEY_EVENT_UP);             
    SetRightSoftkeyFunction(mmi_java_entry_push_install_confirm_no_hanlder, KEY_EVENT_UP);                                            
}                                         
#endif

static MMI_BOOL mmi_java_push_install_confirm_entry_func(mmi_scenario_id scen_id, void *arg)
{
    mmi_java_set_allow_push_install(KAL_FALSE);
    #ifdef __PLUTO_MMI_PACKAGE__
    mmi_java_entry_push_install_confirm();
    #elif __COSMOS_MMI_PACKAGE__
    vapp_java_entry_push_install_confirm();
    #else
    #endif
    return MMI_TRUE;
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_push_install_callback        
 * DESCRIPTION                            
 *  this function is the call back of re-send push install time out.                      
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_push_install_callback(void)                                          
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_push_install_node_struct *current_node;                                      
    mmi_java_push_install_ind_struct *push_install_ind_ptr;                               
    S32 right_arrived_count = 0;          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    g_mmi_java_push_install_timer_set = KAL_FALSE;                                        
    for (current_node = g_mmi_java_push_install_end; current_node != NULL; current_node = current_node->prev)                             
    {                                     
        if (current_node->right_arrived)  
        {                                 
            if (right_arrived_count < 2)  
            {                             
                /* just send 2 message is enought */                                      
                MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_PUSH_INSTALL_REPUSH);                  
                                          
                push_install_ind_ptr = /*(mmi_java_timealarm_push_ind_struct*)*/          
                                 construct_local_para(sizeof(mmi_java_timealarm_push_ind_struct), TD_CTRL);                               
                push_install_ind_ptr->push_install_type=(kal_uint32)-1;                              
                                          
                push_install_ind_ptr->drm_file_path = current_node->content.drm_file_path;
                mmi_java_send_message_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_PUSH_INSTALL_IND,push_install_ind_ptr);
            }                             
            right_arrived_count ++;       
        }                                 
    }                                     
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_push_install_ind        
 * DESCRIPTION                            
 *  when right of a jar is recevied, mmi will recevied push_install_ind from              
 *  Java, it will determine popup or later.                                               
 * PARAMETERS                             
 *  MsgStruct       [?]                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_push_install_ind(void *MsgStruct)                                      
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    S32 len;                              
    mmi_java_push_install_ind_struct *pushMsg = (mmi_java_push_install_ind_struct*) MsgStruct;                                            
    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_PUSH_INSTALL_IND);

    if(((mmi_java_push_install_ind_struct*) MsgStruct)->push_install_type !=(kal_uint32) -1)
    {
        if(!mmi_java_find_and_set_push_install(((mmi_java_push_install_ind_struct*) MsgStruct)->drm_file_path))
        {
            /* the waiting for right file is not in queue*/
            free_ctrl_buffer(pushMsg->drm_file_path);
            return;
        }
    }
    if (!g_mmi_java_push_install_timer_set)
    {
        if (mmi_java_is_allow_push_install())
        {
            if (g_mmi_java_install_drm_path_push_install)
            {
                free_ctrl_buffer(g_mmi_java_install_drm_path_push_install);
                g_mmi_java_install_drm_path_push_install = NULL;
            }
            len = (get_ucs2_len(((mmi_java_push_install_ind_struct*) MsgStruct)->drm_file_path) + 1) << 1;
            g_mmi_java_install_drm_path_push_install = get_ctrl_buffer(len);
            memcpy(g_mmi_java_install_drm_path_push_install, ((mmi_java_push_install_ind_struct*) MsgStruct)->drm_file_path, len);
            mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_JAVA_MID_INSTALL, MMI_EVENT_QUERY, mmi_java_push_install_confirm_entry_func, NULL);
        }
        else
        {
            StartTimer(J2ME_PUSHINSTALL_TIMER, 10 * 1000, (FuncPtr) mmi_java_push_install_callback);
            g_mmi_java_push_install_timer_set = MMI_TRUE;
        }
    }
    if(((mmi_java_push_install_ind_struct*) MsgStruct)->push_install_type != (kal_uint32)-1)
    {
        free_ctrl_buffer(pushMsg->drm_file_path);
    }
}
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_drm_acquire_right_confirm                                              
 * DESCRIPTION                            
 *  ask user to acquire right or not.     
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_entry_drm_acquire_right_confirm(void)                                       
{                                         
#ifdef __DRM_SUPPORT__                    
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    S32 drm_result;                       
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    drm_result = mmi_rmgr_check_rights_by_path((U16*)g_mmi_java_install_drm_path_aquire_right, DRM_PERMISSION_NONE,mmi_java_get_title_icon(), NULL);                          
    if (drm_result == MMI_RMGR_STATUS_REQUEST_RIGHTS)                                     
    {                                     
        mmi_rmgr_request_rights_confirm_ext((U16*)get_string(STR_JAVA_DRM_ACQUIRE_RIGHT_CONFIRM), MMI_FALSE);                             
    }                                     
#endif                                    
}  

mmi_ret mmi_java_mids_entry_drm_acquire_right_proc(mmi_event_struct* evt)                           
{ 
    switch(evt->evt_id)                   
    {          
        case EVT_ID_POPUP_QUIT:             
            mmi_java_entry_drm_acquire_right_confirm(); 
            mmi_java_mids_installer_group_close();
            break;                            
    }                                     
    return MMI_RET_OK;   

}

#endif // __MMI_JAVA_INSTALL_PUSHINSTALL__  
 

#ifdef __MMI_JAVA_INSTALL_SEND_REPORT__
#ifdef __PLUTO_MMI_PACKAGE__

/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_show_notify_dialog           
 * DESCRIPTION                            
 *  show notify dialog when vm send report of installation or deltetion                   
 *                                        
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_show_waiting_right_dialog(void)                                      
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_WAITING_RIGHT_DIALOG, NULL, mmi_java_show_waiting_right_dialog, MMI_FRM_FULL_SCRN))                                        
    {                                     
        mmi_java_mids_installer_group_close();                                    
        return;                           
    }                                     
                                          
                                          
    ShowCategory8Screen(                  
        STR_JAVA_START_INSTALLING,        
        mmi_java_get_install_title_icon(),
        0,                                
        0,                                
        0,                                
        0,                                
        STR_JAVA_WAITING_RIGHT,           
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),                                    
        NULL);                            
                                          
}
static void mmi_java_close_waiting_right_dialog(void)
{
    if(mmi_frm_scrn_get_active_id() == SCR_JAVA_WAITING_RIGHT_DIALOG)                     
    {                                     
        mmi_frm_scrn_close_active_id();   
    }                                     
    else                                  
    {                                     
        mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_WAITING_RIGHT_DIALOG);       
    }
}
#endif
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_notify_start_req        
 * DESCRIPTION                            
 *  MSG_ID_MMI_JAVA_NOTIFY_POST_START_REQ msg handler, to start to show notify dialog     
 *                                        
 * PARAMETERS                             
 *  MsgStruct      [void*]                
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_waiting_right_start_req(void *MsgStruct)                               
{                                         
#ifdef __PLUTO_MMI_PACKAGE__                 
    mmi_java_show_waiting_right_dialog(); 
#endif
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_notify_end_req          
 * DESCRIPTION                            
 *  MSG_ID_MMI_JAVA_NOTIFY_POST_START_REQ msg handler, to finish showing notify dialog    
 *                                        
 * PARAMETERS                             
 *  MsgStruct      [void*]                
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_waiting_right_end_req(void *MsgStruct)                                 
{                                         
#ifdef __PLUTO_MMI_PACKAGE__                    
    mmi_java_close_waiting_right_dialog();
#endif
}                                         
#endif //__MMI_JAVA_INSTALL_SEND_REPORT__                                         
                                          
#define __MMI_JAVA_INSTLL_KEEP_RMS__  
static mmi_java_install_reset_rms_ind_struct reset_rms_ind_msg;      
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_send_reset_rms_res           
 * DESCRIPTION                            
 *  This routines send MMI_JAVA_SEND_RESET_RMS_RES to MOD_J2ME for user decision          
 * PARAMETERS                             
 *  confirm     [IN]        KAL_TRUE if really want to install this MIDS                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_send_reset_rms_res(S8 confirm)                                              
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_install_reset_rms_res_struct *msg;                                           
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_RESET_RMS_RES);                               
    //ClearInputEventHandler(MMI_DEVICE_ALL);                                             
                                          
    msg = (mmi_java_install_reset_rms_res_struct*) OslConstructDataPtr(sizeof(mmi_java_install_reset_rms_res_struct));                    
                                          
    msg->confirm =(kal_bool) confirm;               
                                          
    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,                                 
        MSG_ID_MMI_JAVA_INSTALL_RESET_RMS_RES, msg);                                
}            

#ifdef __PLUTO_MMI_PACKAGE__  
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_send_reset_rms_res_yes       
 * DESCRIPTION                            
 *  Handle Function: revoked when select "YES" in "RESET RMS" screen                      
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_send_reset_rms_res_yes(void)
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    ClearInputEventHandler(MMI_DEVICE_ALL);                                               
    mmi_frm_scrn_close_active_id();       
    mmi_java_send_reset_rms_res(KAL_TRUE);
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_send_reset_rms_res_no        
 * DESCRIPTION                            
 *  Handle Function: revoked when select "NO" in "RESET RMS" screen                       
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_send_reset_rms_res_no(void) 
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    ClearInputEventHandler(MMI_DEVICE_ALL);                                               
    mmi_frm_scrn_close_active_id();       
    mmi_java_send_reset_rms_res(KAL_FALSE);                                               
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_reset_rms_res          
 * DESCRIPTION                            
 *  Reset RMS Confirm screen Entry Function                                               
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_entry_reset_rms_res(void)   
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    U8 *guiBuffer;                        
    U8 *str;                              
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_RESET_RMS_CONFIRM, NULL, mmi_java_entry_reset_rms_res, MMI_FRM_FULL_SCRN)) 
    {                                     
        mmi_java_mids_installer_group_close();                                    
        return;                           
    }                                     
                                          
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_java_installer_cui_gid,SCR_JAVA_RESET_RMS_CONFIRM);                                            
                                          
    str = (U8*) get_string(STR_JAVA_RESET_RMS_ASK);                                       
                                          
    ShowCategory74Screen(                 
        STR_JAVA_KEEP_RMS,                
        mmi_java_get_install_title_icon(),
        STR_GLOBAL_YES,                   
        IMG_GLOBAL_YES,                   
        STR_GLOBAL_NO,                    
        IMG_GLOBAL_NO,                    
        (PU8) str,                        
        mmi_ucs2strlen((CHAR *) str),        
        guiBuffer);                       
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_send_reset_rms_res_yes, KEY_EVENT_UP);          
    SetLeftSoftkeyFunction(mmi_java_send_reset_rms_res_yes, KEY_EVENT_UP);                
    SetRightSoftkeyFunction(mmi_java_send_reset_rms_res_no, KEY_EVENT_UP);                
}                                         
#endif
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_reset_rms_ind           
 * DESCRIPTION                            
 *  This routines handles MMI_JAVA_INSTALL_RESET_RMS_IND from MOD_J2ME to                 
 *  prompt user whether or not reset RMS  
 * PARAMETERS                             
 *  MsgStruct       [?]                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
 void mmi_java_recv_reset_rms_ind(void *MsgStruct)                                         
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    kal_mem_cpy(                          
        &reset_rms_ind_msg,               
        (mmi_java_install_reset_rms_ind_struct*) MsgStruct,                               
        sizeof(mmi_java_install_reset_rms_ind_struct));                                   
                                          
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_RESET_RMS_IND);                               
    if(g_mmi_java_is_background_display)  
    {                                     
        mmi_java_send_reset_rms_res(KAL_TRUE);                                            
        return;                           
    }                                     
    #ifdef __PLUTO_MMI_PACKAGE__
    mmi_java_entry_reset_rms_res();       
    #else
    vapp_java_entry_reset_rms_res();
    #endif
}                                         
                                          
/*****************************************************************************            
*                                         
*                                         
*                                         
******************************************************************************/           
#ifdef __DM_SCOMO_SUPPORT__               
#define MMI_JAVA_MAX_BACKGROUND_CMD_TRY_COUNT 5                                           
static kal_int32 g_mmi_java_background_try_count = 0;                                     
static MMI_BOOL  g_mmi_java_background_is_aborting = MMI_FALSE;                           
static mmi_java_cmd_enum                  current_dm_cmd = MMI_JAVA_CMD_END;              
static MMI_BOOL                           current_dm_cmd_display_mode = MMI_FALSE;        
static srv_dm_scomo_java_cmd_info_struct* current_scomo_cmd_info_ptr  = NULL;             
/*****************************************************************************            
*                                         
* Function declare                        
*                                         
******************************************************************************/           
void mmi_java_dmui_scomo_cb(              
        srv_dm_scomo_cmd_enum cmd,            
        srv_dm_scomo_java_cmd_info_struct *scomo_info);                                   
void mmi_java_dmui_scomo_execute_cmd_entry(void);                                         
static void mmi_java_dmui_scomo_mids_install(void);                                       
static void mmi_java_dmui_scomo_mids_remove(void);  
#ifdef __PLUTO_MMI_PACKAGE__
static void mmi_java_dmui_scomo_entry_confirm(void);                                      
#endif
static void mmi_java_dmui_scomo_cmd_handler(void);                                        
static void mmi_java_dmui_scomo_report_status(                                            
        CHAR * dm_software_id,               
        srv_dm_scomo_cmd_enum cmd,            
        kal_int32 error_code,             
        CHAR * mids_storage_id,              
        U16* mids_name,                   
        CHAR * mids_version);                
static MMI_BOOL mmi_java_dmui_scomo_is_idle(void)                                         
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    kal_int32 debug_idx = 0;              
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
#ifdef __MMI_WEBCAM__                    
    if(mmi_usb_webcam_is_active())        
    {                                     
        debug_idx = 1;                    
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_IS_IDLE,debug_idx);       
        return MMI_FALSE;                 
    }                                     
#endif                                    
#ifdef __MMI_USB_SUPPORT__             
    if(srv_usb_is_in_mass_storage_mode()) 
    {                                     
        debug_idx = 2;                    
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_IS_IDLE,debug_idx);       
        return MMI_FALSE;                 
    }                                     
#endif                                    
    if(!current_dm_cmd_display_mode
    #ifdef __PLUTO_MMI_PACKAGE__
    && mmi_scr_locker_is_locked()
    #elif __COSMOS_MMI_PACKAGE__
    && vapp_screen_lock_is_locked()
    #else
        MMI_FALSE
    #endif
    )                               
    {                                     
        debug_idx = 3;                    
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_IS_IDLE,debug_idx);       
        return MMI_FALSE;                 
    }                                     

    if(
#ifdef __PLUTO_MMI_PACKAGE__
        mmi_idle_is_active()
#elif __COSMOS_MMI_PACKAGE__
        vapp_launcher_is_active()
#else
        MMI_FALSE
#endif
    )     
    {                                     
        debug_idx = 4;                    
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_IS_IDLE,debug_idx);       
        return MMI_TRUE;                  
    }                                     
#ifdef __MMI_SCREEN_SAVER__
    if(mmi_scr_saver_is_active()) 
    {                                     
        debug_idx = 5;                    
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_IS_IDLE,debug_idx);       
        return MMI_TRUE;                  
    }
#endif

#ifdef __MMI_OP11_HOMESCREEN__            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */      
#ifdef __DM_LAWMO_SUPPORT__               
    if(srv_dm_lawmo_is_locked()&&current_dm_cmd_display_mode)                             
    {                                     
        debug_idx = 8;                    
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_IS_IDLE,debug_idx);       
        return MMI_TRUE;                  
    }                                     
#endif /* __DM_LAWMO_SUPPORT__ */         
    debug_idx = -1;                       
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_IS_IDLE,debug_idx);           
                                          
    return MMI_FALSE;                     
}                                         
static MMI_BOOL mmi_java_dmui_scomo_can_exectute(void)                                    
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    kal_int32 debug_idx = 0;              
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if( g_mmi_java_cmd_state != JAVA_CMD_READY_STATE)                                     
    {                                     
        debug_idx = 1;                    
       MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_CAN_EXECUTE,debug_idx);    
       return MMI_FALSE;                  
    }                                     
    if(g_mmi_java_is_launching_midlet)    
    {                                     
        debug_idx = 2;                    
       MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_CAN_EXECUTE,debug_idx);    
       return MMI_FALSE;                  
    }                                     
   /* if(mmi_java_is_in_voice_call())       
    {                                     
        debug_idx = 3;                    
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_CAN_EXECUTE,debug_idx);   
        return MMI_FALSE;                 
    }   */                                  
    if(jam_vm_is_busy())                  
    {                                     
        debug_idx = 4;                    
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_CAN_EXECUTE,debug_idx);   
        return MMI_FALSE;                 
    }                                     
    if(g_mmi_java_reinstall_state != 0)   
    {                                     
        debug_idx = 5;                    
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_CAN_EXECUTE,debug_idx);   
        return MMI_FALSE;                 
    }                                     
                                          
    if(current_dm_cmd_display_mode && !mdi_audio_is_idle())                               
    {                                     
        debug_idx = 6;                    
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_CAN_EXECUTE,debug_idx);   
        return MMI_FALSE;                 
    }                                     
#ifdef __MMI_WEBCAM__                   
    if(mmi_usb_webcam_is_active())        
    {                                     
        debug_idx = 7;                    
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_CAN_EXECUTE,debug_idx);   
        return MMI_FALSE;                 
    }                                     
#endif                                    
#ifdef __MMI_USB_SUPPORT__             
        if (srv_usb_is_in_mass_storage_mode())                                            
        {                                 
            debug_idx = 8;                
            MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_CAN_EXECUTE,debug_idx);                                               
            return MMI_FALSE;             
         }                                
#endif /* __USB_IN_NORMAL_MODE__ */       
    if(srv_mode_switch_is_network_service_available() == MMI_FALSE)                                  
    {                                     
        debug_idx = 9;                    
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_CAN_EXECUTE,debug_idx);   
        return MMI_FALSE;                 
    }                                     
    if(!current_dm_cmd_display_mode 
#ifdef __PLUTO_MMI_PACKAGE__
        && mmi_scr_locker_is_locked()
#elif __COSMOS_MMI_PACKAGE__
        && vapp_screen_lock_is_locked()
#else
            MMI_FALSE
#endif

    )                               
    {                                     
        debug_idx = 10;                   
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_CAN_EXECUTE,debug_idx);   
        return MMI_FALSE;                 
    }                                     
                                          
    return MMI_TRUE;                      
                                          
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_dmui_scomo_cb                
 * DESCRIPTION                            
 * the call back  registered to dmui, used to notify java that need to install or remove mids                                             
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_dmui_scomo_cb(              
        srv_dm_scomo_cmd_enum cmd,            
        srv_dm_scomo_java_cmd_info_struct *scomo_info)                                    
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    U8 is_popup_allow = 0;                
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC,FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_CB, 0,cmd,g_mmi_java_cmd_state);                                          
    if (g_mmi_java_cmd_state != JAVA_CMD_IDLE_STATE                                    
        || srv_mode_switch_is_network_service_available() == MMI_FALSE                               
#ifdef __DM_LAWMO_SUPPORT__               
        || srv_dm_lawmo_is_locked() && scomo_info->display_mode != SRV_DM_SCOMO_DISPLAY_MODE_BACKGROUND                                   
#endif /* __DM_LAWMO_SUPPORT__ */         
        )                                 
    {                                     
        mmi_java_dmui_scomo_report_status(
            (CHAR *)scomo_info->dm_software_id,                                              
            cmd,                          
            J2ME_ACTION_FAILE,            
            NULL,                         
            NULL,                         
            NULL);                        
        return;                           
    }                                     
    g_mmi_java_cmd_state = JAVA_CMD_READY_STATE;                                          
    g_mmi_java_background_try_count = 0;  
    g_mmi_java_background_is_aborting = MMI_FALSE;                                        
    if(current_scomo_cmd_info_ptr != NULL)
    {                                     
        free_ctrl_buffer(current_scomo_cmd_info_ptr);                                     
    }                                     
    current_scomo_cmd_info_ptr =  get_ctrl_buffer(sizeof(srv_dm_scomo_java_cmd_info_struct));                                             
                                          
    ASSERT(current_scomo_cmd_info_ptr != NULL);                                           
    memcpy(current_scomo_cmd_info_ptr,scomo_info,sizeof(srv_dm_scomo_java_cmd_info_struct));                                              
    if (current_scomo_cmd_info_ptr->display_mode == SRV_DM_SCOMO_DISPLAY_MODE_BACKGROUND) 
    {                                     
        current_dm_cmd_display_mode = MMI_TRUE;                                           
    }                                     
    else                                  
    {                                     
        current_dm_cmd_display_mode = MMI_FALSE;                                          
    }                                     
                                          
    /* trans scomo cmd code into java cmd and backup into current_dm_cmd*/                
    switch(cmd)                           
    {                                     
        case SRV_DM_SCOMO_CMD_INSTALL:  
            current_dm_cmd = MMI_JAVA_CMD_INSTALL_BY_DM;          /* Command of install */
            break;                        
                                          
        case SRV_DM_SCOMO_CMD_INSTALL_INACTIVE:                                         
            current_dm_cmd = MMI_JAVA_CMD_INSTALL_INACTIVE; /* Command of install inactive */                                             
            break;                        
                                          
        case SRV_DM_SCOMO_CMD_ACTIVATE: 
            current_dm_cmd = MMI_JAVA_CMD_ACTIVATE;         /* Command of activate */     
            break;                        
                                          
        case SRV_DM_SCOMO_CMD_INACTIVATE:                                               
            current_dm_cmd = MMI_JAVA_CMD_INACTIVATE;       /* Command of inactivate */   
            break;                        
                                          
        case SRV_DM_SCOMO_CMD_REMOVE:   
            current_dm_cmd = MMI_JAVA_CMD_REMOVE_BY_DM;           /* Command of remove */ 
            break;                        
                                          
        case SRV_DM_SCOMO_CMD_REMOVE_ALL:                                               
            current_dm_cmd =  MMI_JAVA_CMD_REMOVE_ALL_BY_DM; /* Command of remove all software */                                         
            break;                        
                                          
        default:                          
            current_dm_cmd = MMI_JAVA_CMD_END;                                            
            break;                        
    }                                     
    if(mmi_java_dmui_scomo_is_idle())     
    {                                     
        mmi_java_dmui_scomo_execute_cmd_entry();                                          
    }                                 
}                                         
                                          
                                          
void mmi_java_dmui_scomo_execute_cmd_entry(void)                                          
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    U8 is_popup_allow = 0;                
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if (mmi_frm_scrn_is_present (g_java_installer_cui_gid, SCR_JAVA_DM_CONFIRM, MMI_FRM_NODE_ALL_FLAG)||                                  
            !mmi_java_dmui_scomo_can_exectute())                                              
    {
        return;
    }
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_EXECUTE_CMD_ENTRY,current_dm_cmd,current_dm_cmd_display_mode);                
    if(!current_dm_cmd_display_mode)      
    {                                     
        /*user mode need user confirm*/   
        mmi_java_set_allow_push_install(KAL_FALSE);                                       
        #ifdef __PLUTO_MMI_PACKAGE__
        mmi_java_dmui_scomo_entry_confirm();
        #elif __COSMOS_MMI_PACKAGE__
        vapp_java_entry_dm_install_confirm();
        #else
        ASSERT(0);
        #endif
    }                                     
    else                                  
    {                                     
        /*background mode need reentry idle screen*/                                      
        ++g_mmi_java_background_try_count;
        mmi_java_set_allow_push_install(KAL_FALSE);                                       
        mmi_java_dmui_scomo_cmd_handler();
    }                                     
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_dmui_scomo_cmd_handler       
 * DESCRIPTION                            
 * Dispatch the command handler.          
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_dmui_scomo_cmd_handler(void)                                         
{                                         
    g_mmi_java_cmd_state = JAVA_CMD_RUN_STATE;                                            
    mmi_java_set_allow_push_install(KAL_FALSE);                                           
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_CMD_HANDLER,current_dm_cmd);  
    g_mmi_java_current_running_cmd = current_dm_cmd;                                      
    g_mmi_java_is_background_display = current_dm_cmd_display_mode;                       
    switch(current_dm_cmd)                
    {                                     
        case MMI_JAVA_CMD_INSTALL_BY_DM:  /* Command of install */                        
            mmi_java_dmui_scomo_mids_install();                                           
            return;                       
        case MMI_JAVA_CMD_REMOVE_BY_DM:   /* Command of remove */                         
            mmi_java_dmui_scomo_mids_remove();                                            
            return;                       
        default:                          
            return;                       
    }                                     
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_dmui_scomo_retry_check       
 * DESCRIPTION                            
 * Called in IDLE to check whether need start timer to wait entry idle screen.            
 *                                        
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
U8 mmi_java_dmui_scomo_retry_check(void)  
{                                         
    if(current_dm_cmd_display_mode && 
        g_mmi_java_background_is_aborting && 
        g_mmi_java_cmd_state == JAVA_CMD_RUN_STATE)
    {
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_EXECUTE_CMD_CHECK,101);
        return MMI_TRUE;
    }
    if(g_mmi_java_cmd_state == JAVA_CMD_READY_STATE && mmi_java_is_no_network_service())
    {
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_EXECUTE_CMD_CHECK,102);
        return MMI_TRUE;
    }
    if(jam_vm_is_busy())
    {
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_EXECUTE_CMD_CHECK,103);
        return MMI_TRUE;
    }
    if(g_mmi_java_is_launching_midlet)
    {
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_EXECUTE_CMD_CHECK,104);
        return MMI_TRUE;
    }

    return MMI_FALSE;                  
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_dmui_scomo_execute_cmd_check 
 * DESCRIPTION                            
 * Called in IDLE to check whether need call mmi_java_dmui_scomo_execute_cmd_cb while entry IDLE screen.                                  
 *                                        
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
U8 mmi_java_dmui_scomo_execute_cmd_check(void)                                            
{                                         
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/ 
    /*if current is aborting by user or jam_vm_is_busy or is launching, we try check again after 5s */
    if(mmi_java_dmui_scomo_retry_check())
    {
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_EXECUTE_CMD_CHECK,1); 
        StartTimer(J2ME_DMINSTALL_TIMER, 5000, (FuncPtr) mmi_java_dmui_scomo_execute_cmd_check);
        return MMI_FALSE;
    }
    if(!mmi_java_dmui_scomo_can_exectute())
    {
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_EXECUTE_CMD_CHECK,0);
        return MMI_FALSE;
    }
    /*If current cmd is background, then no need block goto IDLE screen, so we start a timer to launch command execute*/
    if(current_dm_cmd_display_mode)
    {
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_EXECUTE_CMD_CHECK,2); 
        StartTimer(J2ME_DMINSTALL_TIMER, 5000, (FuncPtr) mmi_java_dmui_scomo_execute_cmd_entry);
        return MMI_FALSE;
    }
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_EXECUTE_CMD_CHECK,3); 
    return MMI_TRUE;                    
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_dmui_scomo_execute_cmd_cb    
 * DESCRIPTION                            
 * if mmi_java_dmui_scomo_execute_cmd_check(), then  this function will be call while entry idle screen.                                  
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_dmui_scomo_execute_cmd_cb(void)                                             
     {                                    
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
                                          
    mmi_java_dmui_scomo_execute_cmd_entry();                                              
}                                         
                                          
/*****************************************************************************            
 * FUNCTION                               
  *  mmi_java_dmui_scomo_need_abort       
 * DESCRIPTION                            
  *  this function is used to check whether need abort background command.                
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
  *  MMI_BOOL                             
 *****************************************************************************/           
static MMI_BOOL mmi_java_dmui_scomo_need_abort(void)                                      
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    kal_int32 debug_idx = 0;              
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if(g_mmi_java_cmd_state != JAVA_CMD_RUN_STATE )                                       
    {                                     
        debug_idx =1;                     
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_NEED_ABORT,debug_idx);    
        return MMI_FALSE;                 
    }                                     
    if(!g_mmi_java_is_background_display) 
    {                                     
        debug_idx =2;                     
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_NEED_ABORT,debug_idx);    
        return MMI_FALSE;                 
    }                                     
    if(
#ifdef __PLUTO_MMI_PACKAGE__
        mmi_idle_is_active()
#elif __COSMOS_MMI_PACKAGE__
        vapp_launcher_is_active()
#else
        MMI_FALSE
#endif
    )                                  
    {                                     
        debug_idx =3;                     
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_NEED_ABORT,debug_idx);    
        return MMI_FALSE;                 
    }                                     
    /*if(mmi_sat_is_group_active())                               
    {                                     
        debug_idx =4;                     
        MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_NEED_ABORT,debug_idx);    
        return MMI_FALSE;                 
    } */                                    
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_NEED_ABORT,0);                
    return MMI_TRUE;                      
}                                         
                                          
                                          
 /*****************************************************************************           
  * FUNCTION                              
  *  mmi_java_dmui_scomo_exit_idle_cb     
  * DESCRIPTION                           
  *  this function is the call back of abort background command.                          
  * PARAMETERS                            
  *  void                                 
  * RETURNS                               
  *  void                                 
  *****************************************************************************/          
void mmi_java_dmui_scomo_exit_idle_cb(void)                                               
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_EXIT_IDLE_CB);                
    if(mmi_java_dmui_scomo_need_abort())  
    {                                     
        mmi_java_send_java_abort_req();   
        g_mmi_java_background_is_aborting = MMI_TRUE;                                     
    }                                     
}                                         
void mmi_java_dmui_scomo_get_title_and_confirm_str(U16* title, U16* confirm_str)
{
    switch(current_dm_cmd)                
    {                                     
        case MMI_JAVA_CMD_INSTALL_BY_DM:  
            *title = STR_JAVA_DM_INSTALL_REQUSET;                                          
            *confirm_str = STR_JAVA_DM_ASK_EXECUATE_INSTALL;             
            break;                        
        case MMI_JAVA_CMD_REMOVE_BY_DM:   
            *title =STR_JAVA_DM_REMOVE_REQUSET;                                            
            *confirm_str = STR_JAVA_DM_ASK_EXECUATE_REMOVE;              
            break;                        
        default:                          
            return;                       
    } 
}                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_dm_mids_install        
 * DESCRIPTION                            
 *  when received an dm install command, ask user want to continue                        
 *  install or not.                       
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_dmui_scomo_mids_install(void)                                        
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    kal_int16 drv = 0;                    
    kal_int32 len = 0;                    
    kal_wchar* wdownload_url = NULL;      
    kal_wchar* wfilename = NULL;          
    kal_wchar* save_path = NULL;          
    kal_int32 result = 0;                 
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    /*parameter check*/                   
    if( current_scomo_cmd_info_ptr == NULL
        || current_scomo_cmd_info_ptr->pkg_install_path == NULL                           
        || mmi_ucs2strlen((const CHAR *) current_scomo_cmd_info_ptr->pkg_install_path) <= 4 
        || current_scomo_cmd_info_ptr->pkg_network_url == NULL                            
        || mmi_ucs2strlen((const CHAR *) current_scomo_cmd_info_ptr->pkg_network_url) == 0) 
    {                                     
        mmi_java_report_status(current_dm_cmd,J2ME_INVALID_REQUEST,NULL,NULL,NULL);       
        return;                           
    }                                     
    /*trans url to ucs2*/                 
    len = (strlen(current_scomo_cmd_info_ptr->pkg_network_url)+1)<<1;                     
    wdownload_url = (kal_wchar*)get_ctrl_buffer(len);                                     
    mmi_asc_to_ucs2((CHAR *)wdownload_url,(CHAR *)current_scomo_cmd_info_ptr->pkg_network_url);                                               
    /* check install path, whethe it is jad path,if yes then set jad path, otherwise set jar path*/                                       
    len = mmi_ucs2strlen((const CHAR *) current_scomo_cmd_info_ptr->pkg_install_path);      
    /*find filename from install file path end*/                                          
    wfilename = (kal_wchar*)mmi_ucs2rchr((const CHAR * )current_scomo_cmd_info_ptr->pkg_install_path,(U16)L'\\');                           
    if(wfilename == NULL)                 
    {                                     
        wfilename = current_scomo_cmd_info_ptr->pkg_install_path;                         
    }                                     
    if(*wfilename == L'\\')               
    {                                     
        wfilename++;                      
    }                                     
    /*Build jad file path : D:\Received\xxx.jad\0*/                                       
    len = 3 + mmi_ucs2strlen((const CHAR *)FMGR_DEFAULT_FOLDER_RECEIVED);                    
    len += mmi_ucs2strlen((const CHAR *) wfilename)+1;                                       
    save_path = get_ctrl_buffer(len<<1);  
    drv  = SRV_FMGR_PUBLIC_DRV;                
    save_path[0] =  drv;save_path[1] =  0;
    mmi_ucs2cat((CHAR *) save_path,(const CHAR *) L":\\");                                    
    mmi_ucs2cat((CHAR *) save_path,(const CHAR *) FMGR_DEFAULT_FOLDER_RECEIVED);              
    result = FS_Open(save_path, FS_OPEN_DIR | FS_READ_ONLY);                              
    if (result < FS_NO_ERROR)             
    {                                     
        result = FS_CreateDir(save_path); 
        if (FS_NO_ERROR > result)         
        {                                 
            mmi_java_report_status(current_dm_cmd,J2ME_INVALID_REQUEST,NULL,NULL,NULL);   
            return;                       
        }                                 
    }                                     
    else                                  
    {                                     
        FS_Close(result);                 
    }                                     
    mmi_ucs2cat((CHAR *) save_path,(const CHAR *) wfilename);                                 
    /* move the jad file into received folder*/                                           
    result = FS_Move((U16*)current_scomo_cmd_info_ptr->pkg_install_path,(U16*) save_path, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);                                               
    if(result != FS_NO_ERROR)             
    {                                     
        FS_Delete((const WCHAR*)save_path);                                               
        free_ctrl_buffer(save_path);      
        free_ctrl_buffer(wdownload_url);  
        mmi_java_report_status(current_dm_cmd,J2ME_INSUFFICIENT_STORAGE,NULL,NULL,NULL);  
        return;                           
    }                                     
    len = mmi_ucs2strlen((const CHAR *)save_path);                                          
    if(0 == mmi_ucs2icmp((const CHAR *)(save_path+len-4),(const CHAR *)L".jad"))              
    {                                     
        mmi_java_mids_install((U16*)save_path, NULL,(U16*)wdownload_url, MMI_TRUE);    
    }                                     
    else                                  
    {                                     
        mmi_java_mids_install(NULL,(U16*)save_path,(U16*)wdownload_url, MMI_TRUE);    
    }                                     
                                          
    free_ctrl_buffer(save_path);          
    free_ctrl_buffer(wdownload_url);      
}    
#ifdef __PLUTO_MMI_PACKAGE__
U8 mmi_java_dmui_scomo_confirm_del_cb(void* data)                                         
{                                         
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_CONFIRM_DEL_CB);              
    if(g_mmi_java_reinstall_state==0 && g_mmi_java_cmd_state!=JAVA_CMD_RUN_STATE)         
    {                                     
        mmi_java_report_status(current_dm_cmd,SRV_DM_SCOMO_RESULT_FAILURE,NULL,NULL,NULL);    
    }                                     
    return MMI_FALSE;                     
}                                         
mmi_ret mmi_java_dmui_scomo_confirm_screen_leave_proc(mmi_event_struct *evt)              
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    switch(evt->evt_id)                   
    {                                     
    case EVT_ID_SCRN_DEINIT:              
        mmi_java_dmui_scomo_confirm_del_cb(NULL);
        mmi_java_mids_installer_group_close();                      
        break;                            
    }                                     
    return MMI_RET_OK;                    
}                 

/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_dmui_scomo_entry_confirm     
 * DESCRIPTION                            
 *                                        
 *  Entry dm confirm screen.              
 *                                        
 * PARAMETERS                             
 * void                                   
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_dmui_scomo_entry_confirm(void)                                       
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    MMI_ID_TYPE title = 0;                        
    MMI_ID_TYPE confirm_str = 0;               
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    /*get disply info*/                   
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_DMUI_SCOMO_ENTRY_CONFIRM,current_dm_cmd);
    mmi_java_dmui_scomo_get_title_and_confirm_str(&title,&confirm_str);
    if(g_java_installer_cui_gid == GRP_ID_INVALID)    
    {                                     
        g_java_installer_cui_gid =mmi_java_mids_installer_create_group();                 
    }                                     
    if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_DM_CONFIRM, NULL, mmi_java_dmui_scomo_entry_confirm, MMI_FRM_FULL_SCRN))   
    {                                     
        mmi_java_mids_installer_group_close();                                    
        return;                           
    }                                     
                                          
    mmi_frm_scrn_set_leave_proc(g_java_installer_cui_gid, SCR_JAVA_DM_CONFIRM,mmi_java_dmui_scomo_confirm_screen_leave_proc);             
       
    ShowCategory74Screen(                 
        title,                            
        mmi_java_get_install_title_icon(),
        STR_GLOBAL_YES,                   
        IMG_GLOBAL_YES,                   
        STR_GLOBAL_NO,                    
        IMG_GLOBAL_NO,
        (U8*)get_string(confirm_str),                 
        mmi_ucs2strlen((CHAR *) get_string(confirm_str)),
        NULL);                            

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_dmui_scomo_cmd_handler,KEY_EVENT_UP);  
    SetLeftSoftkeyFunction(mmi_java_dmui_scomo_cmd_handler, KEY_EVENT_UP);                
    SetRightSoftkeyFunction(mmi_java_mids_installer_group_close, KEY_EVENT_UP);                  
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);                                           
}                                         
#endif
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_entry_dm_mids_remove         
 * DESCRIPTION                            
 *  when received an dm remove command    
 *  install or not.                       
 * PARAMETERS                             
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_dmui_scomo_mids_remove(void)                                         
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if( current_scomo_cmd_info_ptr == NULL
        || current_scomo_cmd_info_ptr->app_software_id == NULL                            
        || mmi_ucs2strlen((const CHAR *) current_scomo_cmd_info_ptr->app_software_id) == 0) 
    {                                     
        mmi_java_report_status(current_dm_cmd,J2ME_INVALID_REQUEST,NULL,NULL,NULL);       
        return;                           
    }                                     
    mmi_java_mids_delete(-1,(kal_char*)current_scomo_cmd_info_ptr->app_software_id, KAL_TRUE);      
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  get_dmui_scomo_error_code             
 * DESCRIPTION                            
 *                                        
 * Trans j2me error code into  scomo error code                                           
 *                                        
 * PARAMETERS                             
 *                                        
 * kal_int32 javaerrorcode,               
 *                                        
 * RETURNS                                
 *  kal_int32                             
 *****************************************************************************/           
static kal_int32 get_dmui_scomo_error_code(kal_int32 javaerrorcode)                       
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    switch(javaerrorcode)                 
    {                                     
        case POST_ERROR:                  
        case J2ME_NO_ERROR:               
            return SRV_DM_SCOMO_RESULT_SUCCESS;                                               
        case USER_CANCEL:                 
        case J2ME_USER_CANCEL:            
            return SRV_DM_SCOMO_RESULT_USER_CANCEL;                                     
        case INVALID_JAD_URL:             
        case INVALID_JAR_URL:             
        case MISSING_JAR_URL:             
        case  MISSING_VENDOR:             
        case CORRUPT_JAR:                 
        case JAR_SIZE_MISMATCH:           
        case VERSION_MISMATCH:            
        case VENDOR_MISMATCH:             
        case INVALID_KEY:                 
        case INVALID_VALUE:               
        case MISSING_CONFIGURATION:       
        case MISSING_PROFILE:             
        case INSTALL_NA:                  
        case DRM_RIGHT_NOT_RECEIVED:      
        case UNSUPPORT_MIDLET:            
        case ATTRIBUTE_MISMATCH:          
        case MISMATCH_RUNTIME_EXEC_ENV:   
        case INCORRECT_MIDLET_DATA:       
        case INSTALL_UNTRUSTED_MIDS_CONFIRM:                                              
        case MISSING_SUITE_INSTALL_NOTIFY:
        case MISSING_DELETE_NOTIFY:       
        case TRUSTED_OVERWRITE_FAILURE:   
        case DEFAULT_GAME_CAN_NOT_UPDATE: 
           return SRV_DM_SCOMO_RESULT_INSTALL_FAIL;                                     
                                          
        case DISK_OPERATION_FAIL:         
        case J2ME_FILE_DONWLOAD_FAILED:   
        case J2ME_FILE_DOWNLOAD_CANT_CREATE_FILE:                                         
        case J2ME_FILE_DOWNLOAD_CONNECTION_ABORT:                                         
            return SRV_DM_SCOMO_RESULT_DOWNLOAD_FAIL;                                   
                                          
        case MISSING_PROVIDER_CERT:       
        case CORRUPT_PROVIDER_CERT:       
        case DRM_PROHIBIT:                
        case AUTHORIZED_BY:               
        case J2ME_DRM_NO_RIGHT:           
        case J2ME_DRM_PROHIBIT:           
        case AUTHORIZATION_FAILURE:       
            return SRV_DM_SCOMO_RESULT_AUTH_FAIL;                                       
                                          
        case TOO_MANY_MID:                
        case OVER_MAX_INSTALL:            
        case ROOT_DIR_FULL:               
        case MEMORY_ALLACTION_FAILURE:    
        case J2ME_INSUFFICIENT_MEMORY:    
        case J2ME_INSUFFICIENT_MEMORY_WHOLE_POOL:                                         
        case J2ME_INSUFFICIENT_STORAGE:   
        case INSUFFICIENT_STORAGE:        
             return SRV_DM_SCOMO_RESULT_INSTALL_OUT_MEMORY;                             
                                          
        case DEFAULT_GAME:                
        case MIDLET_RUNNING:              
        case J2ME_ABORT_FAIL:             
        case J2ME_ACTION_FAILE:           
        case J2ME_INSTALL_NUM_OVER:       
        case J2ME_INVALID_REQUEST:        
        case J2ME_VM_IS_BUSY:             
            return SRV_DM_SCOMO_RESULT_OPERATION_REJECT;                                
        default:                          
            return SRV_DM_SCOMO_RESULT_FAILURE;                                               
    }                                     
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  get_dmui_scomo_cmd_code               
 * DESCRIPTION                            
 *                                        
 * Trans java cmd code into socomo  cmd code                                              
 *                                        
 * PARAMETERS                             
 *                                        
 * kal_int32 javacmdcode,                 
 *                                        
 * RETURNS                                
 *  kal_int32                             
 *****************************************************************************/           
static kal_int32 get_dmui_scomo_cmd_code(kal_int32 javacmdcode)                           
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    switch(javacmdcode)                   
    {                                     
        case MMI_JAVA_CMD_INSTALL_BY_DM:  
        case MMI_JAVA_CMD_INSTALL_BY_USER:
        case MMI_JAVA_CMD_INSTALL_BY_DEFAULT:                                             
            return SRV_DM_SCOMO_CMD_INSTALL;          /* Command of install */          
        case MMI_JAVA_CMD_INSTALL_INACTIVE:                                               
            return SRV_DM_SCOMO_CMD_INSTALL_INACTIVE; /* Command of install inactive */ 
        case MMI_JAVA_CMD_ACTIVATE:       
            return SRV_DM_SCOMO_CMD_ACTIVATE;         /* Command of activate */         
        case MMI_JAVA_CMD_INACTIVATE:     
            return SRV_DM_SCOMO_CMD_INACTIVATE;       /* Command of inactivate */       
        case MMI_JAVA_CMD_REMOVE_BY_DM:   
        case MMI_JAVA_CMD_REMOVE_BY_USER: 
            return SRV_DM_SCOMO_CMD_REMOVE;           /* Command of remove */           
        case MMI_JAVA_CMD_REMOVE_ALL_BY_DM:                                               
        case MMI_JAVA_CMD_REMOVE_ALL_BY_USER:                                             
            return SRV_DM_SCOMO_CMD_REMOVE_ALL; /* Command of remove all software */    
        default:                          
            return SRV_DM_SCOMO_CMD_END;      
    }                                     
}                                         
                                          
                                          
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_dmui_scomo_report_status     
 * DESCRIPTION                            
 *                                        
 * Report the cmd execute status to dm ui 
 *                                        
 * PARAMETERS                             
 *                                        
 * CHAR * dm_software_id,                    
 * srv_dm_scomo_cmd_enum cmd,                 
 * kal_int32 error_code,                  
 * CHAR * mids_storage_id,                   
 * U16* mids_name,                        
 * CHAR * mids_version                       
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
static void mmi_java_dmui_scomo_report_status(                                            
        CHAR * dm_software_id,               
        srv_dm_scomo_cmd_enum cmd,            
        kal_int32 error_code,             
        CHAR * mids_storage_id,          
        U16* mids_name,
        CHAR * mids_version)
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    kal_int32 len = 0;                    
    srv_dm_scomo_java_report_info_struct *app_info_ptr = NULL;                           
    srv_dm_scomo_result_enum result = SRV_DM_SCOMO_RESULT_SUCCESS; /* Result success */           
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    result = get_dmui_scomo_error_code(error_code);                                       
    app_info_ptr = get_ctrl_buffer(sizeof(srv_dm_scomo_java_report_info_struct));        
    memset(app_info_ptr,0,sizeof(srv_dm_scomo_java_report_info_struct));                 
    if(dm_software_id!=NULL&&(len = strlen((const kal_char*)dm_software_id)) > 0)         
    {                                     
        len = len < DM_MAX_ID_LEN-1? len+1 : DM_MAX_ID_LEN-1;                             
        memcpy(app_info_ptr->dm_software_id,dm_software_id,len);                          
    }                                     
    if(mids_storage_id!=NULL&&(len = strlen((const kal_char*)mids_storage_id))>0)         
    {                                     
        len = len < DM_MAX_ID_LEN-1? len+1 : DM_MAX_ID_LEN-1;                             
        memcpy(app_info_ptr->app_software_id,mids_storage_id,len);                        
    }                                     
    if(mids_name!=NULL&&(len = mmi_ucs2strlen((const CHAR *)mids_name))>0){                  
        len = len < DM_MAX_ID_LEN-1? len+1 : DM_MAX_ID_LEN-1;                             
        memcpy(app_info_ptr->software_name, mids_name,len<<1);                            
    }                                     
    if(mids_version!=NULL&&(len = strlen((const kal_char*)mids_version))>0)               
    {                                     
        len = len < DM_MAX_ID_LEN-1? len+1 : DM_MAX_ID_LEN-1;                             
        memcpy(app_info_ptr->software_version, mids_version,len);                         
    }                                     
#ifdef __MTK_TARGET__                     
    srv_dm_scomo_report(cmd,result, app_info_ptr);                 
#endif                                    
    free_ctrl_buffer(app_info_ptr);       
}                                         
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_recv_remove_mids_ind         
 * DESCRIPTION                            
 *  java already clean @java then call back.                                              
 * PARAMETERS                             
 *  void                                  
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_recv_remove_mids_ind(void *MsgStruct)                                       
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    mmi_java_remove_mids_ind_struct* msg= (mmi_java_remove_mids_ind_struct*)MsgStruct;    
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
 if(msg->deleteAll){                      
        g_mmi_java_current_running_cmd = MMI_JAVA_CMD_REMOVE_ALL_BY_USER;                 
        mmi_java_report_status(g_mmi_java_current_running_cmd,J2ME_NO_ERROR,NULL,NULL,NULL);                                              
        /*Aftre remove all mids then reponse JAM MSG_ID_MMI_JAVA_MIDS_REMOVE_RES, so that defautgame information can be reported*/        
        mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,                             
            MSG_ID_MMI_JAVA_MIDS_REMOVE_RES, NULL);                                 
    }else{                                
        g_mmi_java_current_running_cmd = MMI_JAVA_CMD_REMOVE_BY_USER;                     
        mmi_java_report_status(g_mmi_java_current_running_cmd,J2ME_NO_ERROR,msg->storage_name,NULL,NULL);                                 
        if(msg->storage_name)             
        {                                 
            free_ctrl_buffer(msg->storage_name);                                          
        }                                 
    }                                     
}                                         
                                          
void mmi_java_recv_preinstall_mids_ind(void * MsgStruct)                                  
{                                         
    mmi_java_preinstall_mids_ind_struct *msg = (mmi_java_preinstall_mids_ind_struct *)MsgStruct;                                          
    ASSERT(msg!=NULL);                    
    mmi_java_report_status(MMI_JAVA_CMD_INSTALL_BY_DEFAULT,J2ME_NO_ERROR,                 
          msg->mids_report_info.install_mids_storage_id,                                  
          msg->mids_report_info.install_mids_name,                                        
           msg->mids_report_info.install_mids_version);                                   
    if(msg->mids_report_info.install_mids_storage_id)                                     
    {                                     
        free_ctrl_buffer(msg->mids_report_info.install_mids_storage_id);                  
    }                                     
    if(msg->mids_report_info.install_mids_name)                                           
    {                                     
        free_ctrl_buffer(msg->mids_report_info.install_mids_name);                        
    }                                     
    if(msg->mids_report_info.install_mids_version)                                        
    {                                     
        free_ctrl_buffer(msg->mids_report_info.install_mids_version);                     
    }                                     
    if(msg->mids_report_info.install_mids_vendor)                                         
    {                                     
        free_ctrl_buffer(msg->mids_report_info.install_mids_vendor);                      
    }                                     
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,                                 
        MSG_ID_MMI_JAVA_MIDS_PRE_INSTALL_RES, NULL);                                
}                                         
void mmi_java_clean_dm_related_screen(void)                                               
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if (mmi_frm_scrn_get_active_id() == SCR_JAVA_DM_CONFIRM)                              
    {                                     
        mmi_frm_scrn_close_active_id();   
    }                                     
    mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_DM_CONFIRM);                     
}                                         
void mmi_java_init_dm_scomo(void)         
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    kal_int32 len = 0;                    
    kal_wchar *wpath = NULL;              
    #define TEMP_PATH L"scomo.jad"        
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
                                          
    /*Build jad file path : D:\Received\scomo.jad\0*/                                     
    len = (3 + mmi_ucs2strlen((const CHAR *)FMGR_DEFAULT_FOLDER_RECEIVED)+mmi_ucs2strlen((const CHAR *)TEMP_PATH)+1)<<1;                        
    wpath =(kal_wchar*)get_ctrl_buffer(len);                                              
    wpath[0] =  SRV_FMGR_PUBLIC_DRV;wpath[1] =  0;                                             
    mmi_ucs2cat((CHAR *) wpath,(const CHAR *) L":\\");                                        
    mmi_ucs2cat((CHAR *) wpath,(const CHAR *) FMGR_DEFAULT_FOLDER_RECEIVED);                  
    mmi_ucs2cat((CHAR *) wpath,(const CHAR *) TEMP_PATH);                                     
    FS_SetAttributes((const WCHAR*)wpath, 0);                                             
    FS_Delete((const WCHAR*)wpath);       
    free_ctrl_buffer(wpath);              
    srv_dm_scomo_register_notify(mmi_java_dmui_scomo_cb);                                  
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_remove_mids_ind, MSG_ID_MMI_JAVA_MIDS_REMOVE_IND);                                  
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_preinstall_mids_ind, MSG_ID_MMI_JAVA_MIDS_PRE_INSTALL_IND);                         
}                                         
#endif /*__DM_SCOMO_SUPPORT__*/           
                                          
#ifdef MRE_VERSION  
static mmi_java_cmd_enum           current_mre_cmd = MMI_JAVA_CMD_END;              
static vm_cmd_info_struct*         current_mre_cmd_info_ptr  = NULL; 
static void mmi_java_mre_mids_install(void)
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
    kal_int32 len = 0;                    
    kal_wchar* wdownload_url = NULL;      
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    /*parameter check*/                   
    if( current_mre_cmd_info_ptr == NULL
        || current_mre_cmd_info_ptr->pkg_install_path == NULL                           
        || mmi_ucs2strlen((const CHAR *) current_mre_cmd_info_ptr->pkg_install_path) <= 4) 
    {                                     
        mmi_java_report_status(current_mre_cmd,J2ME_INVALID_REQUEST,NULL,NULL,NULL);       
        return;                           
    }                                     
    /*trans url to ucs2*/
    if(current_mre_cmd_info_ptr->pkg_network_url != NULL                            
        && mmi_ucs2strlen((const CHAR *) current_mre_cmd_info_ptr->pkg_network_url) >4)
    {
        len = (strlen(current_mre_cmd_info_ptr->pkg_network_url)+1)<<1;                     
        wdownload_url = (kal_wchar*)get_ctrl_buffer(len);                                     
        mmi_asc_to_ucs2((CHAR *)wdownload_url,(CHAR *)current_mre_cmd_info_ptr->pkg_network_url);  
    }
    else
    {
	wdownload_url = (kal_wchar*)get_ctrl_buffer(30);                                     
        mmi_asc_to_ucs2((CHAR *)wdownload_url,(CHAR *)L"file://");
    }
    len = mmi_ucs2strlen((const CHAR *)current_mre_cmd_info_ptr->pkg_install_path);                                          
    if(0 == mmi_ucs2icmp((const CHAR *)(current_mre_cmd_info_ptr->pkg_install_path+len-4),(const CHAR *)L".jad"))              
    {                                     
        mmi_java_mids_install((U16*)current_mre_cmd_info_ptr->pkg_install_path, NULL,(U16*)wdownload_url, MMI_FALSE);    
    }                                     
    else                                  
    {                                     
        mmi_java_mids_install(NULL,(U16*)current_mre_cmd_info_ptr->pkg_install_path,(U16*)wdownload_url, MMI_FALSE);    
    }                                       
    if(wdownload_url)free_ctrl_buffer(wdownload_url); 

} 
static void mmi_java_mre_mids_remove(void)                                         
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    if( current_mre_cmd_info_ptr == NULL
        || current_mre_cmd_info_ptr->mids_storage_id == NULL                            
        || mmi_ucs2strlen((const CHAR *) current_mre_cmd_info_ptr->mids_storage_id) == 0) 
    {                                     
        mmi_java_report_status(current_mre_cmd,J2ME_INVALID_REQUEST,NULL,NULL,NULL);       
        return;                           
    }
    mmi_java_mids_delete((kal_uint32)-1,(kal_char*)current_mre_cmd_info_ptr->mids_storage_id,KAL_TRUE);
}  
static void mmi_java_mre_midlet_launch(void)
{
    kal_uint16  wstorage_id[30]={0};
    app_asc_str_to_ucs2_str((kal_int8 *)wstorage_id, (kal_int8 *)current_mre_cmd_info_ptr->mids_storage_id);
    mmi_java_launch_midlet((kal_char*)wstorage_id);
}
static void mmi_java_mre_cmd_handler(void)                                         
{                                         
    g_mmi_java_cmd_state = JAVA_CMD_RUN_STATE;                                            
    mmi_java_set_allow_push_install(KAL_FALSE);                                           
    g_mmi_java_current_running_cmd = current_mre_cmd;                                      
    g_mmi_java_is_background_display = KAL_FALSE;                       
    switch(current_mre_cmd)                
    {                                     
        case MMI_JAVA_CMD_INSTALL_BY_MRE:  /* Command of install */                        
            mmi_java_mre_mids_install();                                           
            return;                       
        case MMI_JAVA_CMD_REMOVE_BY_MRE:   /* Command of remove */                         
            mmi_java_mre_mids_remove();                                            
            return;
        case MMI_JAVA_CMD_LAUNCH_BY_MRE:
            mmi_java_mre_midlet_launch();
            g_mmi_java_cmd_state = JAVA_CMD_IDLE_STATE;
            return;
        default:                          
            return;                       
    }                                     
}  
void mmi_java_mre_report_status(mmi_java_cmd_enum java_cmd,VM_P_HANDLE  process_handle,vm_java_report_status_t vm_java_report_status, kal_int32 error_code, kal_char* mids_storage_id)
{
    vm_cmd_enum cmd;
    VMINT32 vm_error_code;
    switch(current_mre_cmd)                           
    {                                     
        case MMI_JAVA_CMD_INSTALL_BY_MRE:  
            cmd = VM_CMD_JAVA_INSTALL; 
            break;
        case MMI_JAVA_CMD_REMOVE_BY_MRE:                                         
            cmd = VM_CMD_JAVA_REMOVE;                                            
            break; 
        case MMI_JAVA_CMD_LAUNCH_BY_MRE:                                         
            cmd = VM_CMD_JAVA_START;                                        
            break;                 
        default:                          
            cmd =(vm_cmd_enum) -1;                                            
            break;                        
    }
    if(error_code){
        vm_error_code = 1;
    }else{
        vm_error_code = 0;
    }
    
    mmi_mre_report_status(cmd, process_handle, (vm_java_report_status_t) vm_java_report_status, (vm_process_result_enum)vm_error_code, (VMSTR)mids_storage_id);
}
kal_bool mmi_java_mre_is_removed(kal_char* mids_storage_id)
{
    kal_int32    mids_id = jam_call_back_functions.jam_get_mids_id_from_storage_name(mids_storage_id);
    return (kal_bool)(mids_id<0);
}
void mmi_java_mre_cb(  
         vm_cmd_enum cmd,            
         vm_cmd_info_struct *vm_cmd_info)                                    
 {                                         
     if ( g_mmi_java_cmd_state != JAVA_CMD_IDLE_STATE                                    
#ifdef __DM_LAWMO_SUPPORT__               
         ||  srv_dm_lawmo_is_locked ()                                 
#endif /* __DM_LAWMO_SUPPORT__ */         
         )                                 
     {                                     
         /*mmi_java_dmui_scomo_report_status(
             (CHAR *)vm_cmd_info->dm_software_id,                                              
             cmd,                          
             J2ME_ACTION_FAILE,            
             NULL,                         
             NULL,                         
             NULL); */                       
         return;                           
     }                                     
     g_mmi_java_cmd_state = JAVA_CMD_READY_STATE;                                          
     if(current_mre_cmd_info_ptr != NULL)
     {                                     
         free_ctrl_buffer(current_mre_cmd_info_ptr);                                     
     }                                     
     current_mre_cmd_info_ptr =  get_ctrl_buffer(sizeof(vm_cmd_info_struct));                                             
                                           
     ASSERT(current_mre_cmd_info_ptr != NULL);                                           
     memcpy(current_mre_cmd_info_ptr,vm_cmd_info,sizeof(vm_cmd_info_struct));                                              
                                           
     /* trans scomo cmd code into java cmd and backup into current_dm_cmd*/                
     switch(cmd)                           
     {                                     
         case VM_CMD_JAVA_INSTALL:  
             current_mre_cmd = MMI_JAVA_CMD_INSTALL_BY_MRE; 
             break;                        
                                           
         case VM_CMD_JAVA_REMOVE:                                         
             current_mre_cmd = MMI_JAVA_CMD_REMOVE_BY_MRE;                                            
             break;                        
         
         case VM_CMD_JAVA_START:                                         
             current_mre_cmd = MMI_JAVA_CMD_LAUNCH_BY_MRE;                                        
             break; 
             
         default:                          
             current_mre_cmd = MMI_JAVA_CMD_END;                                            
             break;                        
     }                                     
     mmi_java_mre_cmd_handler();
 }  

 #endif
/*****************************************************************************            
 * FUNCTION                               
 *  mmi_java_dmui_scomo_report_status     
 * DESCRIPTION                            
 *                                        
 * Global function to  report dm status   
 *                                        
 * T case not need to report              
 * 1. no dm command and this command not exec successfully. since this operation is user command.                                         
 * 2. exist dm command and this command type is not current dm command type, the command also not execute successfully.                   
 * 3. background running abort number is below 10                                         
 * PARAMETERS                             
 *                                        
 * mmi_java_cmd_enum cmd,                 
 * kal_int32 error_code,                  
 * CHAR * mids_storage_id,                   
 * U16* mids_name,                        
 * CHAR * mids_version                       
 *                                        
 * RETURNS                                
 *  void                                  
 *****************************************************************************/           
void mmi_java_report_status(              
        mmi_java_cmd_enum java_cmd,       
        kal_int32 error_code,             
        CHAR * mids_storage_id,              
        U16* mids_name,                   
        CHAR * mids_version)/*parameter unused if no define macro : review 004*/             
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    MMI_TRACE(MMI_TRACE_FUNC, FUNC_J2ME_MMI_JAVA_REPORT_STATUS,java_cmd,error_code);      
    g_mmi_java_current_running_cmd = MMI_JAVA_CMD_END;                                    
#ifdef __DM_SCOMO_SUPPORT__               
    g_mmi_java_background_is_aborting = MMI_FALSE;                                        
    if(                                   
        error_code != J2ME_NO_ERROR && error_code != POST_ERROR &&                        
        (g_mmi_java_cmd_state == JAVA_CMD_IDLE_STATE ||                                   
        g_mmi_java_cmd_state != JAVA_CMD_IDLE_STATE && current_dm_cmd != java_cmd)        
      )                                   
    {                                     
        return;                           
    }                                     
    if( g_mmi_java_is_background_display  
        && current_dm_cmd == java_cmd     
        && g_mmi_java_cmd_state == JAVA_CMD_RUN_STATE                                     
        && error_code == J2ME_USER_CANCEL 
        && g_mmi_java_background_try_count < MMI_JAVA_MAX_BACKGROUND_CMD_TRY_COUNT)       
    {                                     
        /*Need re-try*/                   
        g_mmi_java_cmd_state = JAVA_CMD_READY_STATE;                                      
        return;                           
    }                                     
    if(current_dm_cmd == java_cmd)        
    {                                     
        if(current_scomo_cmd_info_ptr != NULL)                                            
        {                                 
            mmi_java_dmui_scomo_report_status(current_scomo_cmd_info_ptr->dm_software_id, get_dmui_scomo_cmd_code(java_cmd),error_code,mids_storage_id,mids_name,mids_version);           
            free_ctrl_buffer(current_scomo_cmd_info_ptr);                                 
            current_scomo_cmd_info_ptr = NULL;                                            
        }                                 
        else                              
        {                                 
            mmi_java_dmui_scomo_report_status(NULL, get_dmui_scomo_cmd_code(java_cmd),error_code,mids_storage_id,mids_name,mids_version); 
        }                                 
        g_mmi_java_cmd_state = JAVA_CMD_FINISH_STATE;                                     
        current_dm_cmd = MMI_JAVA_CMD_END;
        current_dm_cmd_display_mode = MMI_FALSE;                                          
        mmi_java_clean_dm_related_screen();                                               
        mmi_java_set_allow_push_install(KAL_TRUE);                                        
    }                                     
    else                                  
    {                                     
        mmi_java_dmui_scomo_report_status(NULL, get_dmui_scomo_cmd_code(java_cmd),error_code,mids_storage_id,mids_name,mids_version);     
    }                                     
#else                                     
    g_mmi_java_cmd_state = JAVA_CMD_FINISH_STATE;
#endif                                    

#ifdef MRE_VERSION
    if(current_mre_cmd_info_ptr)
    {
        mmi_java_mre_report_status(current_mre_cmd, current_mre_cmd_info_ptr->process_handle,current_mre_cmd_info_ptr->vm_java_report_status, error_code, mids_storage_id);
    }
    else
    {
        mmi_java_mre_report_status(current_mre_cmd, 0,0, error_code, mids_storage_id);
    }
    current_mre_cmd = MMI_JAVA_CMD_END;
#endif 
}  

#define __MMI_JAVA_DELETE_MIDS__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_delete
 * DESCRIPTION
 *  This function is used to launch delete flow, if user select delete menuitem then must set 
 *  mids_id = <mids_id in cache> and  mids_storage_id = NULL
 *  if dm want to delete the mids, if must set
 *  mids_id = 0xFFFFFFFF or -1, and  mids_storage_id = <pointer to mids_storage_id>
 *  midlets.
 * PARAMETERS
 *  kal_uint32  mids_id
 *  kal_char*   mids_storage_id
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool g_mmi_java_is_need_confirm = KAL_FALSE;
kal_int32 mmi_java_mids_delete(kal_uint32 mids_id, kal_char* mids_storage_id, kal_bool need_confirm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/
    kal_int32  len = 0;
    kal_char* ptr = NULL;
    mmi_java_mids_remove_req_struct *msg = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_MIDS_REMOVE_REQ);
    if(mids_id == (kal_uint32)-1 && mids_storage_id ==NULL)
    {
        mmi_java_report_status(g_mmi_java_current_running_cmd,J2ME_INVALID_REQUEST,NULL,NULL,NULL);
        return J2ME_ACTION_FAILE;
    }
    if(jam_is_busy()||g_java.mids_delete_state != DELETE_VALID_STATE)
    {
#ifdef __PLUTO_MMI_PACKAGE__    
        mmi_java_display_is_busy();
#else
        vapp_java_display_popup(STR_ID_VAPP_JAVA_VM_BUSY,VJAVA_POPUP_WARNING,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP); 
#endif
        mmi_java_report_status(g_mmi_java_current_running_cmd,J2ME_ACTION_FAILE,NULL,NULL,NULL);
        return J2ME_VM_IS_BUSY;
    }
    if(jam_mvm_is_minimize_mode(jam_mvm_get_vm_id(mids_storage_id, -1)))
    {
#ifdef __PLUTO_MMI_PACKAGE__
        mmi_popup_display_simple_ext(STR_JAVA_EXIT_RUNNING_APP, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
#else
        vapp_java_display_popup(STR_JAVA_EXIT_RUNNING_APP,VJAVA_POPUP_WARNING,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP); 
#endif
        mmi_java_report_status(g_mmi_java_current_running_cmd,J2ME_ACTION_FAILE,NULL,NULL,NULL);
        return MIDLET_RUNNING;
    }

#if defined(__MMI_USB_SUPPORT__) || defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if(!g_mmi_java_is_background_display)
        {
    #ifdef __MMI_USB_SUPPORT__
        mmi_usb_app_unavailable_popup(0);
    #elif __USB_IN_NORMAL_MODE__
        vapp_usb_unavailable_popup(0);
    #endif
        }
        mmi_java_report_status(g_mmi_java_current_running_cmd,J2ME_ACTION_FAILE,NULL,NULL,NULL);
        return USB_IN_USE;
        
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    msg = (mmi_java_mids_remove_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_remove_req_struct));
    if(mids_id != (kal_uint32)-1)
    {
        msg->mids_id = mids_id;
        msg->mids_storage_id = NULL;
    }
    else
    {
        msg->mids_id =(kal_uint32) -1;
        len = strlen((const char *) mids_storage_id)+1;
        ptr = (kal_char*)get_ctrl_buffer(len);
        memset(ptr,0,len);
        memcpy(ptr, mids_storage_id, len);
        msg->mids_storage_id = ptr;
    }
    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,
    MSG_ID_MMI_JAVA_MIDS_REMOVE_REQ, msg);
    g_mmi_java_is_need_confirm = need_confirm;
    g_java.mids_delete_state = DELETE_START_STATE;
    return J2ME_NO_ERROR;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_delete_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MIDS_REMOVE_REQ to MOD_JAM to send
 *  delete request of MIDS and set protocol event handler of MSG_ID_MMI_JAVA_MIDS_REMOVE_CNF and
 *  MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_IND
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_delete_req(void)
{
   kal_uint32 mids_id =g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;
   g_mmi_java_is_background_display = MMI_FALSE;
   g_mmi_java_current_running_cmd = MMI_JAVA_CMD_REMOVE_BY_USER;
   mmi_java_mids_delete(mids_id,NULL,KAL_TRUE);
}   

/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_delete_confirm_ind
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_REMOVE_CONFIRM_IND from MOD_J2ME to
 *  prompt user whether or not delete assigned MIDS
 * PARAMETERS
 *  MsgStruct       [?]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_java_mids_remove_confirm_ind_struct remove_cnf_ind_msg;
void mmi_java_recv_mids_delete_confirm_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/
    if (g_java.mids_delete_state == DELETE_START_STATE)
    {
        kal_mem_cpy(
            &remove_cnf_ind_msg,
            (mmi_java_mids_remove_confirm_ind_struct*) MsgStruct,
            sizeof(mmi_java_mids_remove_confirm_ind_struct));
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_MIDS_REMOVE_CONFIRM_IND);
        if(!g_mmi_java_is_background_display && g_mmi_java_is_need_confirm)
        {
            #ifdef __PLUTO_MMI_PACKAGE__
            mmi_java_entry_mids_delete_confirm();
            #elif __COSMOS_MMI_PACKAGE__
	    mmi_java_send_mids_delete_confirm_res(MMI_TRUE);
            #endif
            g_java.mids_delete_state = DELETE_CONFIRM_STATE;
        }
        else
        {
            mmi_java_send_mids_delete_confirm_res(MMI_TRUE);
            g_java.mids_delete_state = DELETE_VM_STATE;
        }
    }
}
#ifdef __PLUTO_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mids_delete_confirm_del_cb
 * DESCRIPTION
 *  Delete Confirm screen Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_java_entry_mids_delete_confirm_del_cb(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/

     mmi_java_send_mids_delete_confirm_res(MMI_FALSE);
     mmi_java_report_status(g_mmi_java_current_running_cmd, J2ME_ACTION_FAILE,NULL, NULL,NULL);
     g_java.mids_delete_state = DELETE_FINISH_STATE;

    return MMI_FALSE;
}

mmi_ret mmi_java_entry_mids_delete_confirm_screen_leave_proc(mmi_event_struct *evt)       
{                                         
    /*----------------------------------------------------------------*/                  
    /* Local Variables*/                  
    /*----------------------------------------------------------------*/                  
                                          
    /*----------------------------------------------------------------*/                  
    /* Code Body      */                  
    /*----------------------------------------------------------------*/                  
    switch(evt->evt_id)                   
    {                                     
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            mmi_java_entry_mids_delete_confirm_del_cb(NULL); 
        break;                            
    }                                     
    return MMI_RET_OK;                    
}                                         
    

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mids_delete_confirm
 * DESCRIPTION
 *  Delete Confirm screen Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_enter_mids_delete_confirm_ind(void) */
void mmi_java_entry_mids_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *str;

    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/
    if(g_java_installer_cui_gid == GRP_ID_INVALID)
    {                                 
        g_java_installer_cui_gid =mmi_java_mids_installer_create_group();                         
    }                   
    mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_DELETE_MENU); 
    if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_DELETE_CONFIRM, NULL, mmi_java_entry_mids_delete_confirm, MMI_FRM_FULL_SCRN))                                   
    {                                 
        mmi_java_mids_installer_group_close();                                
        return;                       
    } 

    guiBuffer = mmi_frm_scrn_get_gui_buf(g_java_installer_cui_gid, SCR_JAVA_DELETE_CONFIRM);
    mmi_frm_scrn_set_leave_proc(g_java_installer_cui_gid,SCR_JAVA_DELETE_CONFIRM, mmi_java_entry_mids_delete_confirm_screen_leave_proc);
  

    str = (U8*) remove_cnf_ind_msg.confirm_msg;

    ShowCategory74Screen(
        STR_GLOBAL_DELETE,
        /*MAUI_02144014*/
        g_java_need_storage_size > 0 ? mmi_java_get_install_title_icon() : mmi_java_get_title_icon(),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) str,
        mmi_ucs2strlen((CHAR *) str),
        guiBuffer);


    SetLeftSoftkeyFunction(mmi_java_mids_delete_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_mids_delete_confirm_no_hdlr, KEY_EVENT_UP);
}


mmi_ret mmi_java_deleting_scrn_key_proc(mmi_event_struct *param)
{
    if (param->evt_id == EVT_ID_PRE_KEY)
    {
        return MMI_RET_KEY_HANDLED;
    }
    return MMI_RET_OK;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mids_delete_confirmed
 * DESCRIPTION
 *  Deleting screen Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_enter_mids_delete_confirmed(void) */
void mmi_java_entry_mids_delete_confirmed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/
    U8* guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_DELETING, NULL, mmi_java_entry_mids_delete_confirmed, MMI_FRM_FULL_SCRN))                                   
    {                                 
        mmi_java_mids_installer_group_close();                                
        return;                       
    } 
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_java_installer_cui_gid, SCR_JAVA_DELETE_CONFIRM);
    mmi_frm_scrn_set_key_proc(g_java_installer_cui_gid,SCR_JAVA_DELETING,mmi_java_deleting_scrn_key_proc);
    ShowCategory66Screen(
        STR_GLOBAL_DELETING,
        mmi_java_get_title_icon(),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_DELETING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_delete_confirm_yes_hdlr
 * DESCRIPTION
 *  Handle function, revoked when user select yes to confirm delete.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_send_mids_delete_confirm_res_yes(void) */
void mmi_java_mids_delete_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/
    if(g_java.mids_delete_state == DELETE_VM_STATE)
    {
        return;
    }
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_java_send_mids_delete_confirm_res(MMI_TRUE);
    mmi_java_entry_mids_delete_confirmed();
    g_java.mids_delete_state = DELETE_VM_STATE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_delete_confirm_no_hdlr
 * DESCRIPTION
 *  Handle function, revoked when user select yes to confirm delete.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_send_mids_delete_confirm_res_no(void) */
void mmi_java_mids_delete_confirm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/
    if(g_java.mids_delete_state == DELETE_VM_STATE)
    {
        return;
    }
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_java_send_mids_delete_confirm_res(MMI_FALSE);
    mmi_java_report_status(g_mmi_java_current_running_cmd, J2ME_USER_CANCEL,NULL, NULL,NULL);
    g_java.mids_delete_state = DELETE_VM_STATE;
}
static void mmi_java_mids_check_reinstall(void)
{

#ifdef __MMI_JAVA_INSTALL_DELETE_MENU__
    if(!g_mmi_java_is_background_display && g_java_need_storage_size > 0)
    {
        /* calculate need size */
        if (mmi_java_storage_size_is_enough())
        {
            g_mmi_java_reinstall_state = 2;
            mmi_java_restore_install_information();
            mmi_java_mids_install_internal();
        }
        mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_DELETING);
        mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_DELETE_CONFIRM);
        mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_DELETE_MENU); 
        mmi_frm_group_close(GRP_ID_JAVA_OPT);
    }
    else
 #endif
    {
        mmi_java_send_delete_menu_abort_req();
        /* To avoid the current active screen don't allow to be deleted */        
        mmi_frm_group_close(g_java_installer_cui_gid);
        mmi_frm_group_close(GRP_ID_JAVA_OPT);
    }
#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__ 
    g_mmi_java_post_notify_result = MMI_TRUE;
#endif 

}

static mmi_ret mmi_java_mids_after_delete_proc(mmi_event_struct* evt)                           
{ 
    switch(evt->evt_id)                   
    {          
        case EVT_ID_POPUP_QUIT:   
            mmi_java_mids_check_reinstall();  
            break;                            
    }                                     
    return MMI_RET_OK;   

}

static mmi_java_mids_del_ui_notify(kal_int32 error_code)
{
    U16 popup_str_id = 0;
    mmi_event_notify_enum popup_type = MMI_EVENT_FAILURE;

    if(mmi_frm_scrn_get_active_id() == SCR_JAVA_DELETE_CONFIRM)                          
    {
       mmi_frm_scrn_close_active_id();    
    }
    if (error_code == J2ME_NO_ERROR)
    {
#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__         
        if(g_mmi_java_post_notify_result)
        {
#endif            
            popup_str_id = STR_GLOBAL_DELETED;

#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__ 
        }
        else
        {
            popup_str_id = STR_JAVA_DELETED_BUT_FAILED_TO_SEND_REPORT;
        }
#endif         
        popup_type = MMI_EVENT_SUCCESS;
    }
    else if(error_code == MIDLET_RUNNING)
    {
        popup_str_id = STR_JAVA_ERROR_CODE_MIDLET_RUNNING;
    }
    else if (error_code != J2ME_USER_CANCEL)
    {
        popup_str_id = STR_GLOBAL_UNFINISHED;
    }
    
    mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_DELETE_CONFIRM); 
    if(!g_mmi_java_is_background_display && g_mmi_java_is_need_confirm)
    {
        if(popup_str_id)
        {
            mmi_popup_property_struct arg;
            mmi_popup_property_init(&arg);
            arg.callback = mmi_java_mids_after_delete_proc;
            mmi_popup_display((WCHAR*)((UI_string_type)GetString(popup_str_id)), popup_type, &arg);
        }
    }
    else
    {
        mmi_java_send_delete_menu_abort_req();
        mmi_frm_group_close(g_java_installer_cui_gid);
        mmi_frm_group_close(GRP_ID_JAVA_OPT);
    }

}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_delete_confirm_res
 * DESCRIPTION
 *  This routines send positive MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_RES to MOD_JAM
 *  to send confirmed delete request of MIDS and set protocol event handler of
 *  MSG_ID_MMI_JAVA_MIDS_REMOVE_CNF
 * PARAMETERS
 *  confirm     [IN]        KAL_TRUE if really want to delete this MIDS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_delete_confirm_res(MMI_BOOL confirm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/
    mmi_java_mids_remove_confirm_res_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_MIDS_REMOVE_CONFIRM_RES);

    /* ClearInputEventHandler(MMI_DEVICE_ALL); */
    if(confirm)
    {
        srv_java_appfactory_remove_record(remove_cnf_ind_msg.storage_name);
    }

    msg =
        (mmi_java_mids_remove_confirm_res_struct*)
        OslConstructDataPtr(sizeof(mmi_java_mids_remove_confirm_res_struct));
    msg->confirm = (kal_bool)confirm;

    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_RES, msg);
}

extern void srv_java_app_factory_mids_del_notify(kal_int32 error_code,kal_char* storage_name);
/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_delete_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_REMOVE_CNF from MOD_J2ME to
 *  indicate user whether or not delete action is successful
 * PARAMETERS
 *  MsgStruct       [void*]  mmi_java_mids_remove_cnf_struct
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mids_delete_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/
    mmi_java_mids_remove_cnf_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_MIDS_REMOVE_CNF);
    msg = (mmi_java_mids_remove_cnf_struct*) MsgStruct;

    mmi_java_report_status(g_mmi_java_current_running_cmd, msg->error_code,(CHAR *)msg->mids_storage_id, NULL,NULL);

#if defined (__COSMOS_MMI_PACKAGE__)	|| defined(J2ME_SLIM_MEMORY_SUPPORT )
		if(javaruntime_size != DEFAULT_POOL_SIZE)
		{
			applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_JAVA, KAL_TRUE);
		}
#endif

    if(msg->error_code == J2ME_NO_ERROR)
    {
#ifdef __PLUTO_MMI_PACKAGE__
#ifndef __DISABLE_SHORTCUTS_IMPL__
#ifdef __MMI_VUI_SHELL_SHORTCUTS__
        {
            WCHAR mids_storage_id_w[16] = {0};
            mmi_asc_to_wcs(mids_storage_id_w, msg->mids_storage_id);
            mmi_shct_java_del_notify((CHAR *)mids_storage_id_w);
        }
#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */
#endif
#endif
    }
    srv_java_app_factory_mids_del_notify(msg->error_code,msg->mids_storage_id);
    
#ifdef __PLUTO_MMI_PACKAGE__
    mmi_java_mids_del_ui_notify(msg->error_code);
#elif __COSMOS_MMI_PACKAGE__
    vapp_java_mids_del_notify(msg->error_code);
#endif
    if(msg->mids_storage_id)
    {
        free_ctrl_buffer(msg->mids_storage_id);
        msg->mids_storage_id = NULL;
    }


#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__ 
    g_mmi_java_post_notify_result = MMI_TRUE;
#endif 

    g_java.mids_delete_state = DELETE_FINISH_STATE;
}

#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_notify_end_req
 * DESCRIPTION
 *  MSG_ID_MMI_JAVA_NOTIFY_POST_START_REQ msg handler, to finish showing notify dialog
 *  
 * PARAMETERS
 *  MsgStruct      [void*]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_notify_end_req(void *MsgStruct)
{
#ifndef __COSMOS_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/
    mmi_java_post_notify_end_req_struct *cnf_msg;

    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/
    
    cnf_msg = (mmi_java_post_notify_end_req_struct*) MsgStruct;  

    g_mmi_java_post_notify_result = cnf_msg->success;
    if(!g_mmi_java_is_background_display)
    {
        mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_POST_NOTIFY_DIALOG);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_show_notify_dialog
 * DESCRIPTION
 *  show notify dialog when vm send report of installation or deltetion
 *  
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_show_notify_dialog(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/
    if(g_java_installer_cui_gid == GRP_ID_INVALID)
    {                                 
        g_java_installer_cui_gid =mmi_java_mids_installer_create_group();                         
    }                   
    mmi_frm_scrn_close(g_java_installer_cui_gid,SCR_JAVA_POST_NOTIFY_DIALOG); 
    if (!mmi_frm_scrn_enter(g_java_installer_cui_gid, SCR_JAVA_POST_NOTIFY_DIALOG, NULL, mmi_java_show_notify_dialog, MMI_FRM_FULL_SCRN))                                   
    {                           
        return;                       
    } 

    ShowCategory8Screen(
        STR_JAVA_NOTIFY_POSTING,
        mmi_java_get_install_title_icon(),
        0,
        0,
        0,
        0,
        STR_JAVA_REPORT_SENDING,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    ClearAllKeyHandler();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_notify_start_req
 * DESCRIPTION
 *  MSG_ID_MMI_JAVA_NOTIFY_POST_START_REQ msg handler, to start to show notify dialog
 *  
 * PARAMETERS
 *  MsgStruct      [void*]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_notify_start_req(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body      */
    /*----------------------------------------------------------------*/
    g_mmi_java_post_notify_result = MMI_TRUE;
    if(!g_mmi_java_is_background_display)
    {
        mmi_java_show_notify_dialog();
    }
}
#endif

void mmi_java_install_init(void)
{
    /* DRM push install*/
#ifdef __MMI_JAVA_INSTALL_PUSHINSTALL__    
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_push_install_ind, MSG_ID_MMI_JAVA_PUSH_INSTALL_IND);
#endif
    /* AT command */
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_at_local_install_req, MSG_ID_MMI_JAVA_LOCAL_INSTALL_REQ_IND);

    /* User Confirm */
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_install_drv_ind, MSG_ID_MMI_JAVA_GET_INSTALL_DRV_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_install_confirm_ind, MSG_ID_MMI_JAVA_INSTALL_CONFIRM_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_install_cnf, MSG_ID_MMI_JAVA_INSTALL_MIDS_CNF);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_update_cnf, MSG_ID_MMI_JAVA_MIDS_UPDATE_CNF);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_install_progress_ind, MSG_ID_MMI_JAVA_INSTALL_PROGRESS_IND);

#ifdef __MMI_JAVA_INSTALL_AUTHENTICATION__
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_auth_ind, MSG_ID_MMI_JAVA_GET_AUTH_IND);
#endif

#ifdef __MMI_JAVA_INSTALL_DOWNLOAD_JAR_IND__
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_show_percentage_ind, MSG_ID_MMI_JAVA_SHOW_PERCENTAGE_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_file_and_save_ind, MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_IND);
#endif

#ifdef __MMI_JAVA_CATEGORY_SUPPORT__
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_install_category_ind, MSG_ID_MMI_JAVA_GET_INSTALL_CATEGORY_IND);    
#endif 

#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__        
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_notify_start_req, MSG_ID_MMI_JAVA_NOTIFY_POST_START_REQ);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_notify_end_req, MSG_ID_MMI_JAVA_NOTIFY_POST_END_REQ);
#endif 

#ifdef __MMI_JAVA_INSTALL_SEND_REPORT__
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_waiting_right_start_req, MSG_ID_MMI_JAVA_WAITING_RIGHT_START_REQ);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_waiting_right_end_req, MSG_ID_MMI_JAVA_WAITING_RIGHT_END_REQ);
#endif 


    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_delete_confirm_ind, MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_delete_cnf, MSG_ID_MMI_JAVA_MIDS_REMOVE_CNF);

#ifdef __DM_SCOMO_SUPPORT__
    mmi_java_init_dm_scomo();
#endif

}

#ifdef __DRM_SUPPORT__
static void mmi_java_fmgr_check_drm_rights_callback(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result)
    {
        mmi_fmgr_close_option_screen();
    }
}

BOOL mmi_java_fmgr_check_drm_rights(U16* filepath, U8 drm_permission, U16 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_rmgr_check_rights_full_procedure((U16*)filepath, 0, drm_permission, icon_id, mmi_java_fmgr_check_drm_rights_callback);
}
#endif

#ifdef __COSMOS_MMI_PACKAGE__
extern void vapp_java_fmgr_info_hdlr(const WCHAR* filepath, java_get_file_info_callback fileinfo);
#endif
void mmi_java_fmgr_install_hdlr(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT( filepath != NULL );
#ifdef __DRM_SUPPORT__
    if(!mmi_java_fmgr_check_drm_rights((U16*)filepath, DRM_PERMISSION_EXECUTE, 0))
    {
        mmi_fmgr_close_option_screen();
        return;
    }
#endif 
    mmi_java_local_install_content_routing((kal_uint16*) filepath);

    mmi_fmgr_close_option_screen();        
}


#endif /* __J2ME__ */                     
