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
 * MMSAppDataManager.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * 
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
// #include "MMI_include.h"
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "fs_errcode.h"
#include "fs_type.h"
#include "fs_func.h"
#include "FileMgrSrvGProt.h"
#include "MMSAppUICommon.h"
// #include "CommonScreens.h"
#include "MmsSrvGprot.h"
// #include "inlineCuiGprot.h"
#include "MMSAppDataManager.h"
#include "MMSMemoryManagerSrv.h"
#include "MMSAppResDef.h"
#include "mmi_rp_app_umms_mms_def.h"
// #include "mmi_rp_app_unifiedmessage_def.h"
#include "mmi_rp_srv_mms_def.h"
// #include "UMSrvGprot.h"
#include "UcAppGProt.h"
//#include "SmsGuiInterfaceType.h"
//#include "gpioInc.h"
//#include "SimDetectionGprot.h"
#include "MMSAppSrvHdlr.h"
#include "Med_global.h"
//#include "Resource_audio.h"
//#include "MessagesResourceData.h"
#include "MMSAppSrvHdlr.h"
// #include "MMSAppUtil.h"
#include "MMSAppUIPlugin.h"
#include "MMSAppOp.h"
#include "USBDeviceGprot.h"
#include "MsgViewerCuiGProt.h"
#include "UmSrvDefs.h"
#include "MmsXMLDefSrv.h"
#include "kal_general_types.h"
#include "MMSAppInterfaceGprot.h"
#include "MMSAppInterfaceprot.h"
#include "kal_public_api.h"
#include "string.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mma_api.h"
#include "app_mem.h"
#include "Unicodexdcl.h"
#include "mma_struct.h"

#include "mmi_frm_timer_gprot.h"
#include "mms_sap_struct.h"
#include "app_usedetails.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "wgui_categories_MMS_viewer.h"
#include "custom_phb_config.h"
#include "UcSrvGprot.h"
#include "customer_email_num.h"
#include "wap_adp.h"
// #include "SimDetectionStruct.h"
#include "gui.h"
#include "gui_data_types.h"
#include "CustDataRes.h"
#include "UmSrvStruct.h"
#include "mmi_frm_scenario_gprot.h"
#include "custom_wap_config.h"
#include "mmi_frm_events_gprot.h"
#include "mms_api.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "UMGProt.h"
#include "mmi_cb_mgr_gprot.h"
#include "MMSTemplateGenSrv.h"
#ifdef __MMI_MMS_IMAGE_VIEW_ENHANCEMENT__
#include "gdi_include.h"
#include "med_api.h"
#define MMS_DECODED_FOLDER_NAME "@mmsimage"
#define MMS_DECODED_FILE_NAME "temp_image.jpg"
mmi_umms_app_dtmgr_image_decode_struct g_umms_viewer_image_decoder_struct;
static wgui_mv_image_decode_status_enum mmi_umms_app_dtmgr_decode_image_for_viewer(U16 *file_path);
static void mmi_umms_app_dtmgr_gdi_decode_done_cb(GDI_RESULT result,gdi_handle handle);
static void mmi_umms_app_dtmgr_resize_and_encode_image(void);
static S32 mmi_umms_app_dtmgr_encode_file_for_viewer(S32 cf, S32 layer_handle);
static U16 * mmi_umms_app_dtmgr_gdi_create_file_path(void);
#endif
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__

static mmi_id g_dtmgr_um_bck_up_grp_id = GRP_ID_INVALID;

/* amit added for template */
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
static srv_um_msg_info_struct *g_template_msg_list_info = NULL;
mmi_umms_app_dtmgr_create_mms_struct g_dtmgr_default_mms_creation;

U8 g_template_count = 0;

/* Amit added for templates */
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
/**************************************for settings*************************/
#if 0
#if defined(__MMI_MMS_UMMS_VIDEO_FEATURE__) || defined(__MMI_MMS_UMMS_AUDIO_FEATURE__) || defined(__MMI_MMS_UMMS_IMAGE_FEATURE__)
/* under construction !*/
/* under construction !*/
#endif
#endif /* 0 */ 
/**************************************for settings*************************/
/* U8 g_compose_signature_done = E_OFF;
   U8 compose_signature_remove_objects_done = E_OFF;
   U8 g_signature_current_highlighted = 0; */
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
S8 *g_disp_buffer_audio = NULL;
#endif 
/*****************************************************************************/
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__

U8 g_is_message_deleted_from_phone_suite = MMI_FALSE;
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 

extern kal_uint32 applib_get_file_size(kal_wchar *filename);
extern kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);

/* Amit added for templates ends here */
#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
mmi_umms_app_dtmgr_phb_notify_struct g_umms_app_dtmgr_phb_notify;
#endif 

static mmi_umms_app_dtmgr_context *mmi_umms_app_dtmgr_get_free_cntx(U16 scr_id);

/* static void mmi_umms_app_dtmgr_save_header_info(srv_mms_xml_msg_header_struct *srv_header_info); */
static void mmi_umms_app_dtmgr_get_use_details_for_viewer_cb(srv_mms_result_enum result, void *msgrsp, void *user_data);

/* static void mmi_umms_app_dtmgr_get_template_info_cb(U16 uid, void *msgrsp); */
S8 *mmi_umms_app_dtmgr_get_addr_content_by_index_for_screen_display(S32 index, U8 *type);
static S8 *mmi_umms_app_dtmgr_get_addr_content_by_index(S32 index);
static mmi_umms_app_dtmgr_context g_dtmgr_cntx[MMI_UMMS_MAX_DTMGR_HANDLES];

/**************************for popup data ***********************************/
static MMI_BOOL mmi_umms_app_dtmgr_add_node_to_from_list(srv_mms_addr_struct **list_addr, U8 *addr, U8 addr_type);
static void mmi_umms_app_dtmgr_viewer_xml_timer_expire(void);
static void mmi_umms_app_dtmgr_viewer_use_detail_timer_expire(void);

/***************************************************************************/
/* SAMPLE APIs */
   /* U8 is_sim1_valid;
      U8 is_sim2_valid;
      U8 profile_set_for_sim1;
      U8 profile_set_for_sim2; */

/* amit added for phone suite delete message from phone suite A BUG */
/* amit added for Bookmark */
U16 g_umms_bookmark_cui_id = 0;

/* Get Context using scr_id */

#ifdef __MMI_MMS_ITERATOR_VIEWER__
static MMI_BOOL g_umms_refresh_templates;
static MMI_BOOL g_iterator_active;
static mmi_um_iter_viewer_result_struct g_other_msg_data;
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
extern kal_uint8 mma_get_mms_storage(kal_uint32 msg_id);
static U32 g_mms_last_tick = 0;

#ifdef __MMI_MSG_FTE_ENHANCE__
S32 g_parent_fh;
#endif 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dtmgr_update_for_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         [?]
 *  scr_id          [IN]        
 *  new_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_dtmgr_update_for_option(mmi_umms_app_start_struct *data, U16 scr_id, U8 new_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *data_new;
    srv_mms_mem_mgr_get_asm_alloc_struct asm_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&asm_cntx, 0, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
    asm_cntx.img_id = IMG_ID_SRV_MMS_VIEWER_APP;
    asm_cntx.str_id = STR_ID_MMS_VIEWER_APP;
    asm_cntx.success_cb = mmi_umms_app_core_mms_app_asm_success_callback;
    asm_cntx.stop_cb = mmi_ummsapp_core_mms_app_asm_stop_callback;
    srv_mms_mem_mgr_init_app_asm_pool(APPLIB_MEM_AP_ID_UMMS, SRV_MMS_INSTANCE_DEFAULT_INDEX, &asm_cntx);
    memset(&asm_cntx, 0, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
    asm_cntx.img_id = IMG_ID_SRV_MMS_VIEWER_APP;
    asm_cntx.str_id = STR_GLOBAL_MULTIMEDIA_MESSAGE;
    asm_cntx.success_cb = mmi_umms_app_core_asm_viewer_success_callback;
    asm_cntx.stop_cb = mmi_umms_app_core_asm_viewer_stop_callback;
    srv_mms_mem_mgr_init_viewer_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER, SRV_MMS_INSTANCE_DEFAULT_INDEX, &asm_cntx);
    data_new =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_option_scr_data_struct));

    memset(data_new, 0, sizeof(mmi_umms_app_dtmgr_option_scr_data_struct));
    data_new->msg_id = data->msg_id;
    data_new->action = data->action;

    data_new->folder_id = mmi_umms_app_dtmgr_prop_convert_umbox_type_to_mma_folder(data->msg_box_type);
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    mmi_umms_app_dtmgr_update_state((void*)data->um_data, MMI_UMMS_APP_DTMGR_REQ_UM_USER_DATA, new_state);
#endif 
    if (mmi_umms_app_dtmgr_get_parent_grp_id() == GRP_ID_INVALID)
    {
        mmi_umms_app_dtmgr_set_parent_grp_id(data->parent_grp_id);
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_INTERFACE_UPDATE_DTMGR_FOR_OPTION, data_new->msg_id, data_new->folder_id);
    mmi_umms_app_dtmgr_update_state((void*)data_new, MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO, new_state);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dtmgr_update_for_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         [?]
 *  scr_id          [IN]        
 *  new_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_dtmgr_update_for_viewer(mmi_umms_app_start_struct *data, U16 scr_id, U8 new_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *data_new;
    srv_mms_mem_mgr_get_asm_alloc_struct asm_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&asm_cntx, 0, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
    asm_cntx.img_id = IMG_ID_SRV_MMS_VIEWER_APP;
    asm_cntx.str_id = STR_ID_MMS_VIEWER_APP;
    asm_cntx.success_cb = mmi_umms_app_core_mms_app_asm_success_callback;
    asm_cntx.stop_cb = mmi_ummsapp_core_mms_app_asm_stop_callback;
    srv_mms_mem_mgr_init_app_asm_pool(APPLIB_MEM_AP_ID_UMMS, SRV_MMS_INSTANCE_DEFAULT_INDEX, &asm_cntx);
    memset(&asm_cntx, 0, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
    asm_cntx.img_id = IMG_ID_SRV_MMS_VIEWER_APP;
    asm_cntx.str_id = STR_GLOBAL_MULTIMEDIA_MESSAGE;
    asm_cntx.success_cb = mmi_umms_app_core_asm_viewer_success_callback;
    asm_cntx.stop_cb = mmi_umms_app_core_asm_viewer_stop_callback;
    srv_mms_mem_mgr_init_viewer_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER, SRV_MMS_INSTANCE_DEFAULT_INDEX, &asm_cntx);
    kal_get_time((kal_uint32*) & g_mms_last_tick);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PERFORMANCE_VIEWER_START_TIME, g_mms_last_tick);

    data_new =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    if (data_new == NULL)
    {
        data_new =
            (mmi_umms_app_dtmgr_option_scr_data_struct*)
            srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_option_scr_data_struct));

        memset(data_new, 0, sizeof(mmi_umms_app_dtmgr_option_scr_data_struct));
    }
    data_new->action = data->action;

    data_new->msg_id = data->msg_id;
    data_new->folder_id = mmi_umms_app_dtmgr_prop_convert_umbox_type_to_mma_folder(data->msg_box_type);
    if (
#ifdef __MMI_MMS_POSTCARD__
           data->action == MMI_UMMS_OPEN_MMS_PREVIEWER_POSTCARD ||
#endif 
           data->action == MMI_UMMS_OPEN_MMS_PREVIEWER_MMS)
    {
        data_new->is_preview = 1;
        data_new->action = MMI_UMMS_OPEN_MMS_VIEWER;
    }
    if (data_new->is_preview)
    {
        data_new->msg_info =
            (mmi_umms_app_dtmgr_msg_info_data_struct*)
            srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_msg_info_data_struct));
        ASSERT(data_new->msg_info);
        memset(data_new->msg_info, 0, sizeof(mmi_umms_app_dtmgr_msg_info_data_struct));
    #ifdef __MMI_MMS_POSTCARD__
        if (data->action == MMI_UMMS_OPEN_MMS_PREVIEWER_POSTCARD)
        {
            data_new->msg_info->msg_type = MMA_MSG_TYPE_POSTCARD;
        }
        else
    #endif /* __MMI_MMS_POSTCARD__ */ 
        {
            data_new->msg_info->msg_type = MMA_MSG_TYPE_MMS;
        }
    #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__)
        data_new->msg_info->msg_storage = mma_get_mms_storage(data_new->msg_id);
    #endif 
    }
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    if (mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_UM_USER_DATA) == NULL)
    {
        mmi_umms_app_dtmgr_update_state((void*)data->um_data, MMI_UMMS_APP_DTMGR_REQ_UM_USER_DATA, new_state);
    }
    mmi_umms_app_dtmgr_set_iterator_status(data->is_iterting);
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
    mmi_umms_app_dtmgr_set_parent_grp_id(data->parent_grp_id);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_UMMS_INTERFACE_UPDATE_DTMGR_FOR_VIEWER,
        data_new->msg_id,
        data_new->folder_id,
        data_new->is_preview);
    mmi_umms_app_dtmgr_update_state((void*)data_new, MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO, new_state);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_current_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_umms_app_dtmgr_context *mmi_umms_app_dtmgr_get_current_cntx(U16 req_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < MMI_UMMS_MAX_DTMGR_HANDLES)
    {
        if (g_dtmgr_cntx[i].req_type == req_type)
        {
            return &g_dtmgr_cntx[i];
        }
        i++;
    }
    return NULL;
}

/* Get New Available Context */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_free_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_umms_app_dtmgr_context *mmi_umms_app_dtmgr_get_free_cntx(U16 req_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < MMI_UMMS_MAX_DTMGR_HANDLES)
    {
        if (g_dtmgr_cntx[i].is_used == FALSE)
        {
            /* Reset g_dtmgr_cntx[i] */
            g_dtmgr_cntx[i].is_used = TRUE;
            g_dtmgr_cntx[i].req_type = req_type;
            g_dtmgr_cntx[i].uid = i + 1;
            return &g_dtmgr_cntx[i];
        }
        i++;
    }
    return NULL;
}

/* Get Context using uid related to interaction with service */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_current_cntx_from_uid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  uid     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_umms_app_dtmgr_context *mmi_umms_app_dtmgr_get_current_cntx_from_uid(U16 uid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < MMI_UMMS_MAX_DTMGR_HANDLES)
    {
        if (g_dtmgr_cntx[i].uid == uid)
        {
            return &g_dtmgr_cntx[i];
        }
        i++;
    }
    return NULL;
}

/* update state of data manager */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_update_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         [?]
 *  req_type        [IN]        
 *  new_state       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_update_state(void *data, U16 req_type, U8 new_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(req_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL)
    {
        cntx = mmi_umms_app_dtmgr_get_free_cntx(req_type);
    }
    cntx->state = (mmi_umms_app_dtmgr_state_enum) new_state;
    cntx->data = data;
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_um_back_up_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_grp_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_um_back_up_id(U16 parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtmgr_um_bck_up_grp_id = parent_grp_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_um_back_up_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_dtmgr_get_um_back_up_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_dtmgr_um_bck_up_grp_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_parent_file_hdl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 *mmi_umms_app_dtmgr_get_parent_file_hdl(void)
{
#ifdef __MMI_MSG_FTE_ENHANCE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_parent_fh;
#else /* __MMI_MSG_FTE_ENHANCE__ */ 
    return 0;
#endif /* __MMI_MSG_FTE_ENHANCE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_umms_app_dtmgr_get_data(U8 req_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(req_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL || cntx->data == NULL)
    {
        return NULL;
    }
    return (void*)cntx->data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_free_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_free_data(U8 req_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(req_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx)
    {
        memset(cntx, 0, sizeof(mmi_umms_app_dtmgr_context));
    }
}

/* show mms 1st level option using all message info */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_check_option_scr_data_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_check_option_scr_data_ready(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MMI_UMMS_ERROR result; */
    mmi_umms_app_dtmgr_option_scr_data_struct *data = NULL;
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    MMI_UMMS_ERROR result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    if (cntx != NULL)
    {
        data = (mmi_umms_app_dtmgr_option_scr_data_struct*) cntx->data;
        if (data != NULL)
        {
            result = mmi_umms_app_dtmgr_get_option_scr_sync_data(
                        data,
                        MMI_FALSE,
                        (void*)mmi_umms_app_core_mms_app_asm_success_callback);
            if (result != MMI_UMMS_TRUE)
            {
                return MMI_UMMS_SYNC_FAIL;
            }
            return MMI_UMMS_TRUE;
        }
        return MMI_UMMS_FALSE;
    }
    return MMI_UMMS_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_option_scr_sync_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                [?]         
 *  is_viewer_flow      [IN]        
 *  success_cb          [?]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_option_scr_sync_data(
                mmi_umms_app_dtmgr_option_scr_data_struct *data,
                MMI_BOOL is_viewer_flow,
                void *success_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MMI_UMMS_ERROR result; */
    app_asm_sucess_cb success_callback = (app_asm_sucess_cb) success_cb;
    srv_mms_mma_get_msg_info_struct *msg_info;
    U8 count = 0;

    srv_mms_result_enum srv_result = SRV_MMS_RESULT_OK;

    U8 asm_error = 0;
    MMI_BOOL status = MMI_FALSE;
    mmi_umms_app_dtmgr_context *cntx = NULL;
    srv_mms_mem_mgr_get_asm_alloc_struct asm_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&asm_cntx, 0, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
    asm_cntx.img_id = IMG_ID_SRV_MMS_VIEWER_APP;
    asm_cntx.str_id = STR_ID_MMS_VIEWER_APP;
    asm_cntx.success_cb = mmi_umms_app_core_mms_app_asm_success_callback;
    asm_cntx.stop_cb = mmi_ummsapp_core_mms_app_asm_stop_callback;
    srv_mms_mem_mgr_init_app_asm_pool(APPLIB_MEM_AP_ID_UMMS, SRV_MMS_INSTANCE_DEFAULT_INDEX, &asm_cntx);
    memset(&asm_cntx, 0, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
    asm_cntx.img_id = IMG_ID_SRV_MMS_VIEWER_APP;
    asm_cntx.str_id = STR_GLOBAL_MULTIMEDIA_MESSAGE;
    asm_cntx.success_cb = mmi_umms_app_core_asm_viewer_success_callback;
    asm_cntx.stop_cb = mmi_umms_app_core_asm_viewer_stop_callback;
    srv_mms_mem_mgr_init_viewer_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER, SRV_MMS_INSTANCE_DEFAULT_INDEX, &asm_cntx);

    if (data->msg_info == NULL)
    {
        cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
        asm_error = srv_mms_mem_mgr_check_asm_total_pool(success_callback, SRV_MMS_INSTANCE_DEFAULT_INDEX);
        if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
            return asm_error;
        }

        asm_error = srv_mms_mem_mgr_alloc_asm_pool(APPLIB_MEM_AP_ID_UMMS, SRV_MMS_INSTANCE_DEFAULT_INDEX);
        if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
        {
            mmi_umms_app_sh_delete_umms_screens();
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
            return asm_error;
        }
        data->msg_info =
            (mmi_umms_app_dtmgr_msg_info_data_struct*)
            srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_msg_info_data_struct));
        ASSERT(data->msg_info);
        memset(data->msg_info, 0, sizeof(mmi_umms_app_dtmgr_msg_info_data_struct));

        if (data->header_info == NULL)
        {
            data->header_info =
                (mmi_umms_app_dtmgr_xml_header_info_struct*)
                srv_mms_mem_mgr_app_asm_alloc(sizeof(mmi_umms_app_dtmgr_xml_header_info_struct));
            ASSERT(data->header_info);
            memset(data->header_info, 0, sizeof(mmi_umms_app_dtmgr_xml_header_info_struct));
        }
        msg_info =
            (srv_mms_mma_get_msg_info_struct*) srv_mms_mem_mgr_app_asm_alloc(sizeof(srv_mms_mma_get_msg_info_struct));
        ASSERT(msg_info);
        memset(msg_info, 0, sizeof(srv_mms_mma_get_msg_info_struct));

        srv_result = srv_mms_mma_get_sync_msg_info(
                        data->msg_id,
                        msg_info,
                        srv_mms_mem_mgr_app_asm_alloc,
                        srv_mms_mem_mgr_app_asm_free);
        if (srv_result != SRV_MMS_RESULT_OK)
        {
            mmi_umms_app_if_show_error_pop_up(MMA_RESULT_FAIL); /* todo */
            /* srv_mms_mem_mgr_app_asm_free(msg_info);//Similar to MAUI_02296975 Group close request from UM Menu CUI when popup is drawn has already called reset data, that is deleting whole asm pool */
            mmi_umms_app_sh_delete_umms_screens();  /* Reset data will be called here also, deleting whole asm pool */
            return MMI_UMMS_FALSE;
        }

        data->msg_info->result = msg_info->result;
        data->msg_info->msg_storage = msg_info->storage_type;
        if (data->msg_info->result == MMA_RESULT_OK)
        {
            data->msg_info->media_type = msg_info->msg_media_type;
            data->msg_info->from_address_type = msg_info->from_address_type;
            data->msg_info->msg_class = msg_info->msg_class;
            data->msg_info->priority = msg_info->priority;
            data->msg_info->msg_size = msg_info->msg_size;
            data->msg_info->date = msg_info->date;
            data->msg_info->receive_date = msg_info->received_date;
            data->msg_info->expiry_date = msg_info->expiry_date + msg_info->received_date;
            data->msg_info->is_read = msg_info->isRead;
            data->msg_info->need_read_report = msg_info->need_read_report;
        #ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
            data->msg_info->need_delivery_report = msg_info->need_delivery_report;
        #endif 
            data->msg_info->is_forward_lock = msg_info->isForwardlock;
            data->msg_info->is_follow_phone_mms_content_class = msg_info->is_follow_phone_mms_content_class;
            data->msg_info->msg_type = msg_info->msg_type;
            data->msg_info->msg_sim_id = msg_info->sim_id;
            data->msg_info->is_lock_mode = msg_info->app_data[0];
            data->msg_info->notification_error_type = msg_info->app_data[1];
            data->msg_info->prev_folder = msg_info->app_data[2];
            mmi_ucs2ncpy(
                (PS8) data->msg_info->app_id,
                (PS8) msg_info->java_app_id,    /* MAX_PROGRESS_STRING_LENGTH */
                100);
            mmi_ucs2ncpy((PS8) data->msg_info->from_address, (PS8) msg_info->from_address, MMA_MAX_ADDR_LEN);
            mmi_ucs2ncpy((PS8) data->msg_info->subject, (PS8) msg_info->subject, MMA_MAX_SUBJECT_LEN);

        #ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
            data->msg_info->user_element_size = msg_info->user_elements_size;
        #endif 
            srv_mms_set_message_type(data->msg_info->msg_type);
            if (!msg_info->isRead)
            {
                data->set_read_mark = 1;
            }

            data->header_info->download_size = msg_info->msg_download_size;
            data->header_info->to_num = msg_info->to_addr_count;
            data->header_info->cc_num = msg_info->cc_addr_count;
            data->header_info->bcc_num = msg_info->bcc_addr_count;
            data->header_info->status = msg_info->msg_report_status;
            data->header_info->ph_num = msg_info->ph_num;
            data->header_info->email_num = msg_info->email_num;

            mmi_ucs2ncpy(
                (PS8) data->header_info->reported_subject,
                (PS8) msg_info->reported_subject,
                SRV_MMS_XML_MAX_SUBJECT_LEN + 1);
            if (msg_info->from_address[0] != '\0')
            {
                mmi_umms_app_dtmgr_add_node_to_from_list(
                    &(data->header_info->from),
                    (U8*) msg_info->from_address,
                    msg_info->from_address_type);
            }
            for (count = 0; count < MMA_MAX_SUPPORT_ADDR_COUNT; ++count)
            {

                if (msg_info->address[count].addr_len > 0)
                {
                    if (data->header_info->to || data->header_info->cc || data->header_info->bcc)
                    {
                        if (srv_mms_is_duplicate_address
                            ((U8*) (msg_info->address[count].address), msg_info->address[count].addr_type,
                             data->header_info->to, data->header_info->cc, data->header_info->bcc))
                        {
                            if (msg_info->address[count].addr_type == SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER)
                            {
                                --data->header_info->ph_num;
                            }
                            else if (msg_info->address[count].addr_type == SRV_MMS_ADDRESS_TYPE_EMAIL)
                            {
                                --data->header_info->email_num;
                            }

                            if (msg_info->address[count].addr_group == SRV_MMS_ADDRESS_GROUP_TYPE_TO)
                            {
                                --data->header_info->to_num;
                            }
                            else if (msg_info->address[count].addr_group == SRV_MMS_ADDRESS_GROUP_TYPE_CC)
                            {
                                --data->header_info->cc_num;
                            }
                            else if (msg_info->address[count].addr_group == SRV_MMS_ADDRESS_GROUP_TYPE_BCC)
                            {
                                --data->header_info->bcc_num;
                            }
                            continue;
                        }
                    }

                    switch (msg_info->address[count].addr_group)
                    {
                        case SRV_MMS_ADDRESS_GROUP_TYPE_TO:
                    #ifdef __MMI_MMS_POSTCARD__
                            if (msg_info->msg_type == MMA_MSG_TYPE_POSTCARD)
                            {
                                msg_info->address[count].addr_type = SRV_MMS_ADDRESS_TYPE_EMAIL;
                            }
                    #endif /* __MMI_MMS_POSTCARD__ */ 
                            mmi_umms_app_dtmgr_add_node_to_addr_list(
                                &(data->header_info->to),
                                &msg_info->address[count]);
                            break;

                        case SRV_MMS_ADDRESS_GROUP_TYPE_CC:
                            mmi_umms_app_dtmgr_add_node_to_addr_list(
                                &(data->header_info->cc),
                                &msg_info->address[count]);
                            break;

                        case SRV_MMS_ADDRESS_GROUP_TYPE_BCC:
                            mmi_umms_app_dtmgr_add_node_to_addr_list(
                                &(data->header_info->bcc),
                                &msg_info->address[count]);
                            break;
                            /* case SRV_MMS_ADDRESS_GROUP_TYPE_FROM:
                               mmi_umms_app_dtmgr_add_node_to_addr_list(&(data->header_info->from), &msg_info->address[count]);
                               break; */
                        default:
                            break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            if (data->msg_info->result == MMA_RESULT_FAIL_FILE_CORRUPTED)
            {
            #ifdef __MMI_MMS_ITERATOR_VIEWER__
                if (mmi_umms_app_dtmgr_get_iterator_status() == MMI_TRUE)
                {
                    mmi_umms_app_if_show_abnormal_view_screen();
                    return MMI_UMMS_FALSE;
                }
            #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
                mmi_umms_app_sh_show_corrupt_and_delete();
            }
            /* need new MMA enum for fail result */
            else if (data->msg_info->result == MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE)
            {
            #ifdef __MMI_MMS_ITERATOR_VIEWER__
                if (mmi_umms_app_dtmgr_get_iterator_status() == MMI_TRUE)
                {
                    mmi_umms_app_if_show_abnormal_view_screen();
                    return MMI_UMMS_FALSE;
                }
            #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
                mmi_umms_app_sh_show_unsupported_and_delete();
            }
            else
            {
                mmi_umms_app_if_show_error_pop_up(data->msg_info->result);
                /* srv_mms_mem_mgr_app_asm_free(msg_info);//MAUI_02296975 Group close request from UM Menu CUI when popup is drawn has already called reset data, that is deleting whole asm pool */
                mmi_umms_app_sh_delete_umms_screens();  /* Reset data will be called here also, deleting whole asm pool */
                return MMI_UMMS_FALSE;
            }
            srv_mms_mem_mgr_app_asm_free(msg_info);
            return MMI_UMMS_FALSE;
        }
        switch (data->folder_id)
        {
            case MMA_FOLDER_INBOX:
            case MMA_FOLDER_OUTBOX:
                status = MMI_TRUE;
                break;
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            case MMA_FOLDER_ARCHIVE:
                switch (data->msg_info->prev_folder)
                {
                    case MMA_FOLDER_INBOX:
                    case MMA_FOLDER_OUTBOX:
                        status = MMI_TRUE;
                        break;
					default :
						 if(data->msg_info->prev_folder != MMA_FOLDER_INBOX  || data->msg_info->prev_folder != MMA_FOLDER_SENT || data->msg_info->prev_folder != MMA_FOLDER_DRAFT )
						 {
                           data->msg_info->prev_folder = MMA_FOLDER_DRAFT ;
						 }
						 break ;
                }
                break;
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
        }
        if (status == MMI_TRUE && data->bgsr_msg_info == NULL)
        {
            data->bgsr_msg_info =
                (srv_mms_bgsr_msg_info_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_bgsr_msg_info_struct));
            ASSERT(data->bgsr_msg_info);
            memset(data->bgsr_msg_info, 0, sizeof(srv_mms_bgsr_msg_info_struct));

            data->bgsr_msg_info->status = srv_mms_bgsr_update_msg_status_info(
                                            data->msg_id,
                                            &(data->bgsr_msg_info->ntt),
                                            &(data->bgsr_msg_info->quota));
        }

        srv_mms_mem_mgr_app_asm_free(msg_info);
        if (is_viewer_flow == MMI_FALSE)
        {
            switch (data->msg_info->msg_type)
            {
                case MMA_MSG_TYPE_READ_REPORT:
                case MMA_MSG_TYPE_DELIVERY_REPORT:
                    mmi_umms_app_if_show_inbox_read_delivery_option();
                    break;
                case MMA_MSG_TYPE_NOTIFICATION:
                    mmi_umms_app_if_show_inbox_notification_option();
                    break;
                case MMA_MSG_TYPE_JAVA:
                    mmi_umms_app_if_show_java_mms_options();
                    break;
                case MMA_MSG_TYPE_MMS:
            #ifdef __MMI_MMS_POSTCARD__
                case MMA_MSG_TYPE_POSTCARD:
            #endif 
                    switch (data->folder_id)
                    {

                    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                        case MMA_FOLDER_ARCHIVE:
                            switch (data->msg_info->prev_folder)
                            {
                                case MMA_FOLDER_INBOX:
                                    mmi_umms_app_if_show_inbox_mms_option();
                                    break;
                                case MMA_FOLDER_DRAFT:
                                    mmi_umms_app_if_show_draft_option();
                                    break;
                                case MMA_FOLDER_SENT:
                                    mmi_umms_app_if_show_sent_option();
                                    break;
                            }
                            break;
                    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
                    }
                    return MMI_UMMS_TRUE;
                    break;
            }
        }
        else
        {
            return MMI_UMMS_TRUE;
        }
    }
    else
    {
        return MMI_UMMS_TRUE;
    }
    return MMI_UMMS_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_add_node_to_addr_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list_addr       [IN]        
 *  node            [?]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_dtmgr_add_node_to_addr_list(srv_mms_addr_struct **list_addr, srv_mms_msg_addr_info_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_addr_struct *temp = NULL, *list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list = *list_addr;
    if (!list)
    {
        list = srv_mms_mem_mgr_app_asm_alloc(sizeof(srv_mms_addr_struct));
        MMI_ASSERT(list);
        memset(list, 0, sizeof(srv_mms_addr_struct));

        list->addr = srv_mms_mem_mgr_app_asm_alloc((node->addr_len + 1) * ENCODING_LENGTH);
        MMI_ASSERT(list->addr);
        memset(list->addr, 0, (node->addr_len + 1) * ENCODING_LENGTH);

        list->group = node->addr_group;
        list->type = node->addr_type;
        list->next = NULL;
        list->previous = NULL;
        if (node->addr_type == SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER)
        {
            mmi_ucs2_n_to_asc((CHAR*) list->addr, (CHAR*) node->address, node->addr_len * ENCODING_LENGTH);
        }
        else
        {
            mmi_ucs2ncpy((PS8) list->addr, (PS8) node->address, node->addr_len);
        }
        *list_addr = list;
        return MMI_TRUE;
    }
    while (list->next != NULL)
    {
        list = list->next;
    }
    if (list)
    {
        temp = srv_mms_mem_mgr_app_asm_alloc(sizeof(srv_mms_addr_struct));
        MMI_ASSERT(temp);
        memset(temp, 0, sizeof(srv_mms_addr_struct));

        temp->addr = srv_mms_mem_mgr_app_asm_alloc((node->addr_len + 1) * ENCODING_LENGTH);
        MMI_ASSERT(temp->addr);
        memset(temp->addr, 0, (node->addr_len + 1) * ENCODING_LENGTH);

        temp->group = node->addr_group;
        temp->type = node->addr_type;
        temp->next = NULL;
        temp->previous = list;
        list->next = temp;

        if (node->addr_type == SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER)
        {
            mmi_ucs2_n_to_asc((CHAR*) temp->addr, (CHAR*) node->address, node->addr_len * ENCODING_LENGTH);
        }
        else
        {
            mmi_ucs2ncpy((PS8) temp->addr, (PS8) node->address, node->addr_len);
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_add_node_to_from_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list_addr       [IN]        
 *  addr            [?]         
 *  addr_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_dtmgr_add_node_to_from_list(srv_mms_addr_struct **list_addr, U8 *addr, U8 addr_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_addr_struct *temp = NULL, *list = NULL;
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list = *list_addr;
    if (!list)
    {
        list = srv_mms_mem_mgr_app_asm_alloc(sizeof(srv_mms_addr_struct));
        MMI_ASSERT(list);
        memset(list, 0, sizeof(srv_mms_addr_struct));
        len = mmi_ucs2strlen((const CHAR*)addr);
        list->addr = srv_mms_mem_mgr_app_asm_alloc((len + 1) * ENCODING_LENGTH);
        MMI_ASSERT(list->addr);
        memset(list->addr, 0, (len + 1) * ENCODING_LENGTH);

        list->group = SRV_MMS_ADDRESS_GROUP_TYPE_FROM;
        list->type = srv_mms_convert_mma_addr_type_to_srv_addr_type(addr_type);
        list->next = NULL;
        list->previous = NULL;
        if (list->type == SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER)
        {
            mmi_ucs2_n_to_asc((CHAR*) list->addr, (CHAR*) addr, len * ENCODING_LENGTH);
        }
        else
        {
            mmi_ucs2ncpy((PS8) list->addr, (PS8) addr, len);
        }
        *list_addr = list;
        return MMI_TRUE;
    }
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_option_scr_info_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_option_scr_info_int(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UMMS_TRUE;
}

/* callback for service to show mms 1st level option using all message info */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_option_scr_info_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         [?]
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_get_option_scr_info_cb(srv_mms_result_enum result, void *msgrsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/* Viewer display related data management */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_check_viewer_scr_data_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_check_viewer_scr_data_ready(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_viewer_info_data *data = NULL;
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx != NULL)
    {
        data = (mmi_umms_app_dtmgr_viewer_info_data*) cntx->data;
        if (data != NULL && /* data->cat_info != NULL */
            (cntx->state != MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT))
        {
            return TRUE;
        }
    }
    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_viewer_data_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_viewer_data_ready(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_viewer_info_data *data = NULL;
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);
    mmi_umms_app_dtmgr_context *cntx_ext = NULL;
    mmi_umms_app_dtmgr_option_scr_data_struct *option_scr_data = NULL;
    MMI_UMMS_ERROR result;
    srv_mms_result_enum srv_result;
    U32 curr_tick = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx != NULL)
    {
        data = (mmi_umms_app_dtmgr_viewer_info_data*) cntx->data;
        if (data != NULL && (cntx->state != MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT))
        {
            /* data->option_scr_data->is_already_viewed = TRUE; */
            return MMI_UMMS_TRUE;
        }
    }
    else
    {
        cntx = mmi_umms_app_dtmgr_get_free_cntx(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);
        data =
            (mmi_umms_app_dtmgr_viewer_info_data*)
            srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_viewer_info_data));
        ASSERT(data);
        memset(data, 0, sizeof(mmi_umms_app_dtmgr_viewer_info_data));
        cntx->data = (void*)data;
    }
    if (cntx->state == MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT)
    {
        cntx_ext = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
        ASSERT(cntx_ext);
        option_scr_data = (mmi_umms_app_dtmgr_option_scr_data_struct*) cntx_ext->data;
        result = mmi_umms_app_dtmgr_get_option_scr_sync_data(
                    option_scr_data,
                    MMI_TRUE,
                    (void*)mmi_umms_app_core_asm_viewer_success_callback);
        if (result != MMI_UMMS_TRUE)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_ERROR_FRM_SERVICE, result);
            if (result == MMI_UMMS_ASM_DRAW_SCR)
            {
                cntx->state = MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT;
            }
            /* to do */
            return result;
        }
        cntx->state = MMI_UMMS_APP_DTMGR_GET_MSG_INFO_WAIT;
		if (option_scr_data->msg_info->msg_type != MMA_MSG_TYPE_MMS
    #ifdef __MMI_MMS_POSTCARD__
            && option_scr_data->msg_info->msg_type != MMA_MSG_TYPE_POSTCARD
    #endif 
            )
        {
            cntx->state = MMI_UMMS_APP_DTMGR_MSG_DATA_READY;
            mmi_umms_app_core_handle_view();
            return MMI_UMMS_FALSE;
        }
        /* mmi_umms_app_dtmgr_forward_viewer_option_scrn_data(SRV_MMS_RESULT_OK, cntx->uid); */
        StartTimer(MMS_VIEWER_TIMER, DTMGR_MMS_UNBLOCK_TIME, mmi_umms_app_dtmgr_viewer_timer_expire);
        return MMI_UMMS_TRUE;
    }
    cntx_ext = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    ASSERT(cntx_ext);
    if (cntx_ext == NULL)
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
    option_scr_data = (mmi_umms_app_dtmgr_option_scr_data_struct*) cntx_ext->data;
    if (cntx_ext->state == MMI_UMMS_APP_DTMGR_MSG_INFO_DONE ||
        option_scr_data->is_preview == 1 /* && data->current_mms_info->msg_id = indata->msg_id */ )
    {
        srv_mms_get_content_req_struct msg_req;

        ASSERT(data);
        // data->cat_info =
        //   (mmi_umms_app_dtmgr_viewer_cateory_info_data*)
        //  srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_viewer_cateory_info_data));
        //ASSERT(data->cat_info);
        //memset(data->cat_info, 0, sizeof(mmi_umms_app_dtmgr_viewer_cateory_info_data));
        memset(&msg_req, 0, sizeof(srv_mms_get_content_req_struct));
        msg_req.msg_id = option_scr_data->msg_id;
        msg_req.user_data = (void*)&cntx->uid;
        msg_req.call_back = (srv_mms_funcptr_type) mmi_umms_app_dtmgr_get_viewer_data_ready_cb;
        msg_req.app_id = MMA_APP_ID_VIEWER;
        msg_req.mode = MMA_MODE_VIEW;
        kal_get_time((kal_uint32*) & curr_tick);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_UMMS_PERFORMANCE_TIME_CONSUMED_BFORE_GET_CONTENT_REQ,
            kal_ticks_to_milli_secs(curr_tick - g_mms_last_tick));
        g_mms_last_tick = curr_tick;
        srv_result = srv_mms_get_content(&msg_req);
        if (srv_result != SRV_MMS_RESULT_OK)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_ERROR_FRM_SERVICE, srv_result);
            ASSERT(0);
        }
        cntx->state = MMI_UMMS_APP_DTMGR_GET_CONTENT_INFO_WAIT;
        srv_mms_set_message_type(option_scr_data->msg_info->msg_type);
    }
    else
    {
        /* case of handling everything from starting not even get_msg_info has been done */
        /* srv_mms_mma_get_msg_info_req_struct msg_req; */
        /* prepare service data */
        /* memset(&msg_req, 0, sizeof(srv_mms_mma_get_msg_info_req_struct));
           msg_req.msg_id = option_scr_data->msg_id;
           msg_req.user_data = cntx->uid;
           msg_req.call_back = (srv_mms_funcptr_type) mmi_umms_app_core_viewer_info_callback;
           msg_req.app_id = MMA_APP_ID_VIEWER;
           srv_result = srv_mms_mma_get_msg_info((void*)&msg_req);
           if(srv_result != SRV_MMS_RESULT_OK)
           {
           MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_ERROR_FRM_SERVICE, srv_result);
           ASSERT(0);
           } */
        result = mmi_umms_app_dtmgr_get_option_scr_sync_data(
                    option_scr_data,
                    MMI_TRUE,
                    (void*)mmi_umms_app_core_asm_viewer_success_callback);
        if (result != MMI_TRUE)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_ERROR_FRM_SERVICE, result);
            if (result == MMI_UMMS_ASM_DRAW_SCR && cntx->state == MMI_UMMS_APP_DTMGR_GET_DATA_NONE)
            {
                cntx->state = MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT;
            }
            /* to do */
            return result;
        }
    #ifdef __MMI_MMS_ITERATOR_VIEWER__
        if (mmi_umms_app_dtmgr_get_iterator_status() == MMI_TRUE &&
            (srv_mms_bgsr_get_downloading_msg_id() == option_scr_data->msg_id ||
             srv_mms_bgsr_get_sending_msg_id() == option_scr_data->msg_id))
        {
            /* Do nothing in this case */
        }
        else
    #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
        {
            /* send get content req on basis of checks */
            if (mmi_umms_app_core_get_msg_state_from_mma() != MMI_UMMS_TRUE)
            {
                return MMI_UMMS_FALSE;
            }
        }
        cntx->state = MMI_UMMS_APP_DTMGR_GET_MSG_INFO_WAIT;
        if (option_scr_data->msg_info->msg_type != MMA_MSG_TYPE_MMS
    #ifdef __MMI_MMS_POSTCARD__
            && option_scr_data->msg_info->msg_type != MMA_MSG_TYPE_POSTCARD
    #endif 
            )
        {
            cntx->state = MMI_UMMS_APP_DTMGR_MSG_DATA_READY;
            mmi_umms_app_core_handle_view();
            return MMI_UMMS_FALSE;
        }
        mmi_umms_app_dtmgr_forward_viewer_option_scrn_data(SRV_MMS_RESULT_OK, (void*)&cntx->uid);

    }
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_viewer_timer_expire
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_viewer_timer_expire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);
    if (!cntx)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_APP_ALREADY_DEINIT);
        return;
    }
    mmi_umms_app_dtmgr_get_viewer_data_ready_cb(SRV_MMS_RESULT_OK, NULL, (void*)&cntx->uid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_state_asm_waiting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_dtmgr_state_asm_waiting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_APP_ALREADY_DEINIT);
        return MMI_FALSE;
    }
    else if (cntx->state == MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/* Callback for Viewer display related data management */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_viewer_data_ready_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         [?]
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_get_viewer_data_ready_cb(srv_mms_result_enum result, void *msgrsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *user_data_cn = (U16*) user_data;
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx_from_uid(*user_data_cn);
    mmi_umms_app_dtmgr_option_scr_data_struct *option_scr_data = NULL;
    mmi_umms_app_dtmgr_viewer_info_data *data = NULL;
    srv_mms_get_content_req_struct msg_req_content;
    srv_mms_get_content_rsp_struct *rsp_content = NULL;
    srv_mms_xml_parse_req_struct xml_req;

    /* U16 file_path_len = 0; */
    srv_mms_result_enum srv_result;
    MMI_BOOL not_free_rsp_data = MMI_FALSE;

    /* controller_DB data_fr_scrn; */
    srv_mms_xml_parse_rsp_struct *xml_rsp_struct = NULL;
    MMI_UMMS_ERROR asm_error = MMI_UMMS_FALSE;
    U32 curr_tick = 0;
    U16 index = 0;
    srv_mms_result_enum res;
    U16 id = APPLIB_MEM_AP_ID_MMS_VIEWER;
    mma_mms_description_struct *description = NULL;
    srv_mms_viewer_result_enum srv_viewer_result = SRV_MMS_VIEWER_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_APP_ALREADY_DEINIT);
        return;
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_SCR_CRNT_STATE, cntx->state);
    data = (mmi_umms_app_dtmgr_viewer_info_data*) cntx->data;
    switch (cntx->state)
    {
        case MMI_UMMS_APP_DTMGR_GET_MSG_INFO_WAIT:

            if (msgrsp)
            {
                mmi_umms_app_dtmgr_save_msg_info(msgrsp);
            }
            option_scr_data =
                (mmi_umms_app_dtmgr_option_scr_data_struct*)
                mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
        #ifdef __MMI_MMS_ITERATOR_VIEWER__
            if (mmi_umms_app_dtmgr_get_iterator_status() == MMI_TRUE &&
                (srv_mms_bgsr_get_downloading_msg_id() == option_scr_data->msg_id ||
                 srv_mms_bgsr_get_sending_msg_id() == option_scr_data->msg_id))
            {
                /* Do nothing in this case */
            }
            else
        #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
            {
                /* send get content req on basis of checks */
                if (mmi_umms_app_core_get_msg_state_from_mma() != MMI_UMMS_TRUE)
                {
                    return;
                }
            }
            /* prpare data for get content req */
            memset(&msg_req_content, 0, sizeof(srv_mms_get_content_req_struct));
            /* prpare data for get content req */
            msg_req_content.msg_id = option_scr_data->msg_id;
            msg_req_content.user_data = (void*)&cntx->uid;
            msg_req_content.call_back = (srv_mms_funcptr_type) mmi_umms_app_core_viewer_info_callback;
            msg_req_content.app_id = MMA_APP_ID_VIEWER;
            if (option_scr_data->msg_info->msg_type == MMA_MSG_TYPE_MMS
        #ifdef __MMI_MMS_POSTCARD__
                || option_scr_data->msg_info->msg_type == MMA_MSG_TYPE_POSTCARD
        #endif 
                )
            {
                msg_req_content.mode = MMA_MODE_VIEW;
            }
            else
            {
                msg_req_content.mode = MMA_MODE_HEADER; /* Special Check For (not mms or postcard)Delivery Report,notification etc. in case of direct view */
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_NOT_A_MMS);
            }
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_MODE_FOR_GET_CONTENT, msg_req_content.mode);
            kal_get_time((kal_uint32*) & curr_tick);
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                MMI_UMMS_PERFORMANCE_TIME_CONSUMED_BFORE_GET_CONTENT_REQ,
                kal_ticks_to_milli_secs(curr_tick - g_mms_last_tick));
            g_mms_last_tick = curr_tick;
            srv_result = srv_mms_get_content(&msg_req_content);
            if (srv_result != SRV_MMS_RESULT_OK)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_ERROR_FRM_SERVICE, srv_result);
                ASSERT(0);
            }
            cntx->state = MMI_UMMS_APP_DTMGR_GET_CONTENT_INFO_WAIT;
            break;
        case MMI_UMMS_APP_DTMGR_GET_CONTENT_INFO_WAIT:
            kal_get_time((kal_uint32*) & curr_tick);
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                MMI_UMMS_PERFORMANCE_TIME_CONSUMED_IN_GET_CONTENT_REQ,
                kal_ticks_to_milli_secs(curr_tick - g_mms_last_tick));
            g_mms_last_tick = curr_tick;
            rsp_content = (srv_mms_get_content_rsp_struct*) msgrsp;
            if (rsp_content->result != MMA_RESULT_OK)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_MV_TRACE_GET_CONTENT_RSP_ERR);
                srv_mms_viewer_send_event_to_exit(0, 0);
                return;
            }
            /* file_path_len = mmi_ucs2strlen((PS8) rsp_content->xml_filepath); */
            if (data == NULL)
            {
                data =
                    (mmi_umms_app_dtmgr_viewer_info_data*)
                    srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_viewer_info_data));
                ASSERT(data);
                memset(data, 0, sizeof(mmi_umms_app_dtmgr_viewer_info_data));
            }
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
            cntx->data = (void*)data;
            cntx->state = MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT;
        case MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT:
            /* Check for ASM */
            option_scr_data =
                (mmi_umms_app_dtmgr_option_scr_data_struct*)
                mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
            if (option_scr_data != NULL && option_scr_data->header_info == NULL && option_scr_data->is_preview != 1)
            {
                asm_error = srv_mms_mem_mgr_check_asm_total_pool(
                                mmi_umms_app_core_asm_viewer_success_callback,
                                SRV_MMS_INSTANCE_DEFAULT_INDEX);
                if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
                {
                    cntx->state = MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT;
                    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
                    return;
                }
                asm_error = srv_mms_mem_mgr_alloc_asm_pool(APPLIB_MEM_AP_ID_UMMS, SRV_MMS_INSTANCE_DEFAULT_INDEX);
                if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
                {
                    cntx->state = MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT;
                    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
                    return;
                }
            }
            asm_error = srv_mms_mem_mgr_alloc_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER, SRV_MMS_INSTANCE_DEFAULT_INDEX);
            if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
            {
                cntx->state = MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT;
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
                return;
            }
            /* prepare xml parser data */
            memset(&xml_req, 0, sizeof(srv_mms_xml_parse_req_struct));
            /* xml_req.xml_file_path = data->xml_file_path; */
            xml_req.user_data = (void*)&cntx->uid;
            xml_req.call_back = mmi_umms_app_core_viewer_info_callback;
            xml_req.app_id = MMA_APP_ID_VIEWER;
            /* check for header info */

            option_scr_data = mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
            if (option_scr_data != NULL && option_scr_data->header_info == NULL && option_scr_data->is_preview != 1)
            {
                xml_req.mode = SRV_MMS_XML_PARSE_COMPLETE;
            }
            else
            {
                xml_req.mode = SRV_MMS_XML_PARSE_BODY_ONLY;
            }
            if (option_scr_data == NULL)
            {
                EXT_ASSERT(0, 0, 0, 0);
            }
            if (option_scr_data->msg_info->msg_type != MMA_MSG_TYPE_MMS
        #ifdef __MMI_MMS_POSTCARD__
                && option_scr_data->msg_info->msg_type != MMA_MSG_TYPE_POSTCARD
        #endif 
                )
            {
                xml_req.mode = SRV_MMS_XML_PARSE_HEADER_ONLY;
            }
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_MODE_FOR_XML_PARSE, xml_req.mode);
            description = (mma_mms_description_struct*) rsp_content->content_info;

            srv_viewer_result = srv_mms_process_data_init((void*)description, (void*)&xml_req);
            if (srv_viewer_result != SRV_MMS_VIEWER_OK)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_ERROR_FRM_SERVICE, srv_viewer_result);
                srv_mms_viewer_send_event_to_exit(SRV_MMS_VIEWER_OUT_OF_MEM, 0);
                return;
            }
            option_scr_data =
                (mmi_umms_app_dtmgr_option_scr_data_struct*)
                mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
            if (option_scr_data->msg_info->msg_type != MMA_MSG_TYPE_MMS
        #ifdef __MMI_MMS_POSTCARD__
                && option_scr_data->msg_info->msg_type != MMA_MSG_TYPE_POSTCARD
        #endif 
                )
            {
                cntx->state = MMI_UMMS_APP_DTMGR_MSG_DATA_READY;
                mmi_umms_app_core_handle_view();
                srv_mms_mem_mgr_app_adm_free(xml_rsp_struct);
                xml_rsp_struct = NULL;
                return;
            }
            option_scr_data =
                (mmi_umms_app_dtmgr_option_scr_data_struct*)
                mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
            cntx->state = MMI_UMMS_APP_DTMGR_MSG_DATA_READY;
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_DATA_READY_GO_FOR_VIEW);
        #ifdef __MMI_MMS_BGSR_SUPPORT__
            if (option_scr_data->folder_id == MMA_FOLDER_OUTBOX &&
				option_scr_data->bgsr_msg_info == NULL)
            {
                option_scr_data->bgsr_msg_info =
                    (srv_mms_bgsr_msg_info_struct*)
                    srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_bgsr_msg_info_struct));
                ASSERT(option_scr_data->bgsr_msg_info);
                memset(option_scr_data->bgsr_msg_info, 0, sizeof(srv_mms_bgsr_msg_info_struct));
                srv_mms_bgsr_get_msg_info(
                    option_scr_data->msg_id,
                    option_scr_data->bgsr_msg_info,
                    mmi_umms_app_core_get_msg_info_from_bgsr_callback_for_csk_view,
                    option_scr_data->msg_info->msg_storage,
                    option_scr_data->msg_info->msg_type);
            }
            else
        #endif /* __MMI_MMS_BGSR_SUPPORT__ */ 

            {
                mmi_umms_app_core_handle_view();
            }

    }
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
#endif /* 0 */ 

#ifdef __MMI_MMS_ITERATOR_VIEWER__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_update_indexing_data_from_um
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_umms_app_dtmgr_update_indexing_data_from_um(mmi_event_struct *param)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *option_scr_data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    MMI_BOOL ret_from_um = MMI_FALSE;
    mmi_um_iter_viewer_info_struct um_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ASSERT(option_scr_data); */
    if (option_scr_data == NULL)
    {
        return MMI_FALSE;
    }
    if (option_scr_data->is_preview == MMI_TRUE)
    {
        memset(&g_other_msg_data, 0, sizeof(mmi_um_iter_viewer_result_struct));
        mmi_umms_app_dtmgr_update_state((void*)&g_other_msg_data, MMI_UMMS_APP_DTMGR_REQ_OTHER_MSG_INFO, 0);
        return;
    }
    memset(&um_req, 0, sizeof(mmi_um_iter_viewer_info_struct));
    memset(&g_other_msg_data, 0, sizeof(mmi_um_iter_viewer_result_struct));
    if (option_scr_data->folder_id != MMA_FOLDER_TEMPLATE && option_scr_data->folder_id != MMA_FOLDER_USRDEF_TEMPLATE)
    {
        um_req.msg_id = option_scr_data->msg_id;
        um_req.func_cb = mmi_umms_app_core_um_data_ready_cb;
        um_req.msg_type = SRV_UM_MSG_MMS;
        um_req.user_data = (void*)option_scr_data;
        /* UM Query Indexing and Fill Data */
        ret_from_um = mmi_um_query_indexing(
                        &um_req,
                        &g_other_msg_data,
                        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_UM_USER_DATA));
        mmi_umms_app_dtmgr_update_state((void*)&g_other_msg_data, MMI_UMMS_APP_DTMGR_REQ_OTHER_MSG_INFO, 0);
        //if ret_from_um is TRUE dont break application, if it is false break application till um calls 
        //message callback
        return ret_from_um;
    }
    else
    {
        mmi_umms_app_core_query_indexing_for_template_iter_view(&g_other_msg_data);
        mmi_umms_app_dtmgr_update_state((void*)&g_other_msg_data, MMI_UMMS_APP_DTMGR_REQ_OTHER_MSG_INFO, 0);
        return MMI_TRUE;
    }
}

#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_save_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgrsp      [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_save_msg_info(void *msgrsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    mmi_umms_app_dtmgr_option_scr_data_struct *option_scr_data = NULL;
    srv_mms_mma_get_msg_info_rsp_struct *rsp_msg_info = NULL;
    mmi_umms_app_dtmgr_msg_info_data_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_SAVE_MSG_INFO);
    if (cntx == NULL)
    {
        cntx = mmi_umms_app_dtmgr_get_free_cntx(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    }
    option_scr_data = (mmi_umms_app_dtmgr_option_scr_data_struct*) cntx->data;
    if (option_scr_data == NULL)
    {
        option_scr_data =
            (mmi_umms_app_dtmgr_option_scr_data_struct*)
            srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_option_scr_data_struct));
        ASSERT(option_scr_data);
        memset(option_scr_data, 0, sizeof(mmi_umms_app_dtmgr_option_scr_data_struct));
    }
    rsp_msg_info = (srv_mms_mma_get_msg_info_rsp_struct*) msgrsp;
    msg_info =
        (mmi_umms_app_dtmgr_msg_info_data_struct*)
        srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_app_dtmgr_msg_info_data_struct));
    ASSERT(msg_info);
    memset(msg_info, 0, sizeof(mmi_umms_app_dtmgr_msg_info_data_struct));
    /* fill get message info */
    msg_info->result = rsp_msg_info->result;
    msg_info->media_type = rsp_msg_info->msg_media_type;
    msg_info->from_address_type = rsp_msg_info->from_address_type;
    msg_info->msg_class = rsp_msg_info->msg_class;
    msg_info->priority = rsp_msg_info->priority;
    msg_info->msg_size = rsp_msg_info->msg_size;
    msg_info->date = rsp_msg_info->date;
    msg_info->receive_date = rsp_msg_info->received_date;
    msg_info->expiry_date = rsp_msg_info->expiry_date + rsp_msg_info->received_date;
    msg_info->is_read = rsp_msg_info->isRead;
    msg_info->need_read_report = rsp_msg_info->need_read_report;
    msg_info->is_forward_lock = rsp_msg_info->isForwardLock;
    msg_info->isDRM = rsp_msg_info->isDRM;
    msg_info->is_follow_phone_mms_content_class = rsp_msg_info->isFollowPhoneMMSContentClass;
    msg_info->hasAttachment = rsp_msg_info->hasAttachment;
    msg_info->msg_type = rsp_msg_info->msg_type;
    msg_info->msg_sim_id = rsp_msg_info->sim_id;
    msg_info->msg_storage = rsp_msg_info->storage_type;
    mmi_ucs2ncpy((PS8) msg_info->from_address, (PS8) rsp_msg_info->from_address, MMA_MAX_ADDR_LEN);
    mmi_ucs2ncpy((PS8) msg_info->subject, (PS8) rsp_msg_info->subject, MMA_MAX_SUBJECT_LEN);
    msg_info->is_lock_mode = rsp_msg_info->app_data[0];
    msg_info->notification_error_type = rsp_msg_info->app_data[1];
    msg_info->prev_folder = rsp_msg_info->app_data[2];
    mmi_ucs2ncpy((PS8) msg_info->app_id, (PS8) rsp_msg_info->java_app_id, /* MAX_PROGRESS_STRING_LENGTH */ 100);
    mmi_ucs2ncpy(
        (PS8) msg_info->reply_app_id,
        (PS8) rsp_msg_info->java_reply_app_id,
        100 /* MAX_PROGRESS_STRING_LENGTH */ );
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    msg_info->user_element_size = rsp_msg_info->user_elements_size;
#endif 
    option_scr_data->msg_info = msg_info;
    option_scr_data->msg_id = rsp_msg_info->msg_id;
    srv_mms_set_message_type(option_scr_data->msg_info->msg_type);
    if (!rsp_msg_info->isRead)
    {
        option_scr_data->set_read_mark = 1;
    }
    cntx->data = (void*)option_scr_data;
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_delete_viewer_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_delete_viewer_data(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_viewer_info_data *data = mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);
    mmi_umms_app_dtmgr_option_scr_data_struct *op_data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    U32 msg_id = 0;
    U8 sim_id = 0;
    U8 folder_id = 0, need_read_report = 0, set_readmark = 0;
    U8 storage_location = 0;
    srv_mms_um_refresh_ind_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_DELETE_VIEWER_DATA);
    if (op_data && op_data->msg_info)
    {
        msg_id = op_data->msg_id;
        sim_id = op_data->msg_info->msg_sim_id;
        folder_id = op_data->folder_id;
        set_readmark = op_data->set_read_mark;
        need_read_report = op_data->msg_info->need_read_report;
        storage_location = op_data->msg_info->msg_storage;
    }
    if (data)
    {
        srv_mms_mem_mgr_app_adm_free(data);
        data = NULL;
        srv_mms_delete_viewer_services();
        if (need_read_report)
        {
            srv_mms_bgsr_set_rr_flag(msg_id);
            if (set_readmark)
            {
                mmi_umms_app_dtmgr_set_readmark(msg_id, MMI_TRUE);
            #ifdef __MMI_MMS_ITERATOR_VIEWER__
                req.msg_box_type = folder_id;
                srv_mms_um_refresh_msg_list(&req);
            #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
            }
            mmi_umms_app_dtmgr_send_read_report(msg_id, sim_id, storage_location);
        }
    }
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    mmi_frm_cb_dereg_event(
        EVT_ID_MMI_UM_REFRESH,
        (mmi_proc_func) mmi_umms_app_dtmgr_update_indexing_data_from_um,
        NULL);
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
    mmi_umms_app_dtmgr_free_data(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);
    mmi_umms_app_dtmgr_reset_data();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_deinit_viewer_service_through_dtmgr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_deinit_viewer_service_through_dtmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_viewer_info_data *data = mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);
    S32 *parent_fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data)
    {
        srv_mms_mem_mgr_app_adm_free(data);
        data = NULL;
    }
    srv_mms_deinit_viewer(SRV_MMS_INSTANCE_DEFAULT_INDEX);
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    mmi_frm_cb_dereg_event(
        EVT_ID_MMI_UM_REFRESH,
        (mmi_proc_func) mmi_umms_app_dtmgr_update_indexing_data_from_um,
        NULL);
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
#ifdef __MMI_MSG_FTE_ENHANCE__
    parent_fh = mmi_umms_app_dtmgr_get_parent_file_hdl();
    if (parent_fh && *parent_fh)
    {
        FS_Close(*parent_fh);
        *parent_fh = 0;
    }
#endif /* __MMI_MSG_FTE_ENHANCE__ */ 
    mmi_umms_app_dtmgr_free_data(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_check_use_details_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_check_use_details_ready(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_use_details_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_use_details_ready(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_use_details_struct *data = NULL;
    srv_mms_get_use_details_req_struct req;
    void *use_detail_rsp = NULL;
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx != NULL)
    {
        data = (mmi_umms_app_dtmgr_use_details_struct*) cntx->data;
        if (data == NULL)
        {
            EXT_ASSERT(0, 0, 0, 0);
        }
        if (data->get_use_details_rsp.num_list
            || data->get_use_details_rsp.email_list || data->get_use_details_rsp.url_list)
        {
            return MMI_UMMS_TRUE;
        }
        memset(&req, 0, sizeof(srv_mms_get_use_details_req_struct));
        req.request_type = data->mms_umms_app_slide;
    #ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_UMMS_DTMGR_SEND_USE_DETAILS_REQ,
            data->curr_index,
            data->is_more,
            data->applib_addr_type);
        req.curr_index = data->curr_index;
        req.is_more = data->is_more;
    #endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
        req.data_type = data->applib_addr_type;
        use_detail_rsp = srv_mms_get_use_details_req_hdlr((void*)&req);
        mmi_umms_app_core_get_use_details_list_cb(use_detail_rsp);
    }
    else
    {
        ASSERT(0);
    }
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_use_details_list_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgrsp              [?]         [?]
 *  user_data(?)        [IN]        
 *  result(?)           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_get_use_details_list_cb(void *msgrsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_use_details_struct *data = NULL;

    /* srv_mms_get_use_details_list_req_struct req; */
    srv_mms_get_use_details_rsp_struct *rsp = (srv_mms_get_use_details_rsp_struct*) msgrsp;

    /* U8 send_req; */
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_APP_ALREADY_DEINIT);
        return;
    }
    data = (mmi_umms_app_dtmgr_use_details_struct*) cntx->data;
    data->get_use_details_rsp.num_list = rsp->num_list;
    data->get_use_details_rsp.email_list = rsp->email_list;
    data->get_use_details_rsp.url_list = rsp->url_list;
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    data->get_use_details_rsp.start_index = rsp->start_index;
    data->get_use_details_rsp.end_index = rsp->end_index;
    data->get_use_details_rsp.total_count = rsp->total_count;
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_SEND_USE_DETAILS_RSP, rsp->start_index, rsp->end_index, rsp->result);
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
    data->get_use_details_rsp.result = rsp->result;
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_SEND_USE_DETAILS_RSP, 0, 0, rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_use_details_list_no_data_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  user_data(?)        [IN]        
 *  result(?)           [IN]        
 *  msgrsp          [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_umms_app_dtmgr_get_use_details_list_no_data_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_use_details_struct *data = mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    if (srv_mms_is_use_detail_parsing_going_on() == MMI_TRUE
        && (SRV_MMS_GET_USE_DETAILS_SENDER != data->mms_umms_app_slide)
        && (SRV_MMS_GET_USE_DETAILS_RECIPIENT != data->mms_umms_app_slide))
    {
        return STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
    }
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
    if (SRV_MMS_GET_USE_DETAILS_SENDER == data->mms_umms_app_slide)
    {
        return STR_GLOBAL_EMPTY;
    }
    switch (data->applib_addr_type)
    {
        case APPLIB_ADDR_TYPE_PHONENUMBER:
            return STR_ID_UMMS_USE_DETAILS_NO_NUMBER;
        case APPLIB_ADDR_TYPE_EMAIL:
            return STR_ID_UMMS_USE_DETAILS_NO_EMAIL_ID;
        case APPLIB_ADDR_TYPE_URL:
            return STR_ID_UMMS_USE_DETAILS_NO_URL;
        default:
            MMI_ASSERT(0);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_use_details_total_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_dtmgr_get_use_details_total_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_use_details_struct *data = mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);
    mmi_umms_app_dtmgr_option_scr_data_struct *op_data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    applib_address_node_struct *node1 = NULL;
    U8 count_number = 0;
    U8 count_email = 0;
    S32 num_item = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
    ASSERT(data);
    ASSERT(op_data->header_info);
    if ((SRV_MMS_GET_USE_DETAILS_NUMBER == data->mms_umms_app_slide) ||
        (SRV_MMS_GET_USE_DETAILS_EMAIL == data->mms_umms_app_slide) ||
        (SRV_MMS_GET_USE_DETAILS_URL == data->mms_umms_app_slide))
    {
        mmi_umms_app_dtmgr_get_use_details_ready(0);
        switch (data->applib_addr_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                node1 = data->get_use_details_rsp.num_list;
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                node1 = data->get_use_details_rsp.email_list;
                break;
            case APPLIB_ADDR_TYPE_URL:
                node1 = data->get_use_details_rsp.url_list;
                break;
            default:
                MMI_ASSERT(0);
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
                break;
        }

    #ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
        num_item = srv_mms_get_total_use_detail_count(data->applib_addr_type);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_SEND_USE_DETAILS_TOTAL_ITEMS_IN_UNLIMITED, num_item);
        data->get_use_details_rsp.total_count = num_item;
    #else /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
        while (node1 != NULL)
        {
            if ((node1->length != 0) || (node1->pos != 0))
            {
                num_item++;
            }

            node1 = node1->next;
        }
    #endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 

    }
    else if ((SRV_MMS_GET_USE_DETAILS_SENDER == data->mms_umms_app_slide) ||
             (SRV_MMS_GET_USE_DETAILS_RECIPIENT == data->mms_umms_app_slide))
    {
        if (op_data->header_info->from)
        {
            /* if(applib_is_valid_email_address_unicode((kal_wchar *)g_current_mms_info_list->umms_mms_xml_msg->from->addr)) */

            if (op_data->header_info->from->type == MMI_UMMS_ADDRESS_TYPE_EMAIL)
            {
                count_email = 1;
            }

            if (op_data->header_info->from->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
            {
                count_number = 1;
            }
        }
        if (SRV_MMS_GET_USE_DETAILS_SENDER == data->mms_umms_app_slide)
        {
            if (op_data->header_info->from)
            {
                num_item = 1;
                /* always there will be only one sender */
                /* if(applib_is_valid_email_address_unicode((kal_wchar *)g_current_mms_info_list->umms_mms_xml_msg->from->addr)) */
                if (op_data->header_info->from->type == MMI_UMMS_ADDRESS_TYPE_EMAIL)
                {
                    data->applib_addr_type = APPLIB_ADDR_TYPE_EMAIL;
                }

                if (op_data->header_info->from->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    data->applib_addr_type = APPLIB_ADDR_TYPE_PHONENUMBER;

                }
            }
            else
            {

                num_item = 0;
            }
        }
        else if (SRV_MMS_GET_USE_DETAILS_RECIPIENT == data->mms_umms_app_slide)
        {
            switch (data->applib_addr_type)
            {
                case APPLIB_ADDR_TYPE_PHONENUMBER:
                    num_item = op_data->header_info->ph_num - count_number;
                    break;
                case APPLIB_ADDR_TYPE_EMAIL:
                    num_item = op_data->header_info->email_num - count_email;
                    break;
                default:
                    MMI_ASSERT(0);
                    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
                    break;
            }
        }
        else
        {
            MMI_ASSERT(0);
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
        }
    }
    else
    {
        MMI_ASSERT(0);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
    }
    return num_item;
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_use_details_aysnc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  menuData        [?]         [?]
 *  num_item        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_dtmgr_get_use_details_aysnc(S32 item_index, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 len = 0;
    U8 type, send_req = 0;
    S8 *data_str = NULL;
    S32 i = 0, new_num_item, new_start_index;
    srv_mms_get_use_details_req_struct req;
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);
    mmi_umms_app_dtmgr_use_details_struct *data = NULL;
    void *use_detail_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cntx);
    if (cntx == NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
    }
    data = (mmi_umms_app_dtmgr_use_details_struct*) cntx->data;
    ASSERT(data);
    new_num_item = num_item;
    new_start_index = item_index;
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    if ((SRV_MMS_GET_USE_DETAILS_NUMBER == data->mms_umms_app_slide) ||
        (SRV_MMS_GET_USE_DETAILS_EMAIL == data->mms_umms_app_slide) ||
        (SRV_MMS_GET_USE_DETAILS_URL == data->mms_umms_app_slide))
    {
        if (item_index < data->get_use_details_rsp.start_index
            || (item_index + num_item - 1) > data->get_use_details_rsp.end_index)
        {
            data->curr_index = item_index;
            data->is_more = MMI_TRUE;
            memset(&req, 0, sizeof(srv_mms_get_use_details_req_struct));
            req.request_type = data->mms_umms_app_slide;
        #ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
            req.curr_index = data->curr_index;
            req.is_more = data->is_more;
        #endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
            req.data_type = data->applib_addr_type;
            use_detail_rsp = srv_mms_get_use_details_req_hdlr((void*)&req);
            mmi_umms_app_core_get_use_details_list_cb(use_detail_rsp);
        }
    }
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
    for (i = 0; i < new_num_item && item_index == new_start_index; ++i)
    {
        switch (data->applib_addr_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                menuData[i].image_list[0] = get_image(IMG_ID_UMMS_USE_DETAILS_IMAGE_NUMBER);
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                menuData[i].image_list[0] = get_image(IMG_ID_UMMS_USE_DETAILS_IMAGE_EMAIL);
                break;
            case APPLIB_ADDR_TYPE_URL:
                menuData[i].image_list[0] = get_image(IMG_ID_UMMS_USE_DETAILS_IMAGE_URL);
                break;
            default:
                MMI_ASSERT(0);
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
                break;
        }
        data_str = mmi_umms_app_dtmgr_get_addr_content_by_index_for_screen_display((S32) i + new_start_index, &type);
        if (type == UMMS_DTMGR_DATA_TYPE_UCS2)
        {
            len = (mmi_ucs2strlen((S8*) data_str)) * ENCODING_LENGTH;
            if (len <= (MAX_SUB_MENU_SIZE - ENCODING_LENGTH))
            {
                mmi_ucs2cpy((S8*) menuData[i].item_list[0], (S8*) data_str);
            }
            else
            {
                mmi_ucs2ncpy(
                    (S8*) menuData[i].item_list[0],
                    (S8*) data_str,
                    (MAX_SUB_MENU_SIZE - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                mmi_ucs2cat((S8*) menuData[i].item_list[0], (S8*) L"...");
            }
        }
        else if (type == UMMS_DTMGR_DATA_TYPE_ANSII)
        {
            len = (strlen((S8*) data_str)) * ENCODING_LENGTH;
            if (len <= (MAX_SUB_MENU_SIZE - ENCODING_LENGTH))
            {
                mmi_asc_to_ucs2((S8*) menuData[i].item_list[0], (S8*) data_str);
            }
            else
            {
                memset(menuData[i].item_list[0], 0, (MAX_SUB_MENU_SIZE - (3 * ENCODING_LENGTH)));
                mmi_asc_n_to_ucs2(
                    (S8*) menuData[i].item_list[0],
                    (S8*) data_str,
                    (MAX_SUB_MENU_SIZE - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
                mmi_ucs2cat((S8*) menuData[i].item_list[0], (S8*) L"...");
            }
        }
    }
    return num_item;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_change_use_detail_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_dtmgr_change_use_detail_title(void)
{
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mms_is_use_detail_parsing_going_on() == MMI_TRUE)
    {
        return IMG_ID_UMMS_USE_DETAIL_PROCESSING_ANI;
    }
    else
    {
        return IMG_ID_UMMS_USE_DETAIL_PROCESS_DONE;
    }
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
	return IMG_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_addr_content_by_index_for_screen_display
 * DESCRIPTION
 *  This API saves the item at the given index to the Global Context
 * PARAMETERS
 *  index       [IN]        
 *  type        [?]         [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
S8 *mmi_umms_app_dtmgr_get_addr_content_by_index_for_screen_display(S32 index, U8 *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *node1 = NULL;
    srv_mms_addr_struct *node2 = NULL;
    U8 parse_list = UMMS_FROM;
    S32 count = 0;

    /* U8 parse_list = UMMS_FROM; */
    mmi_umms_app_dtmgr_use_details_struct *data = mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);
    mmi_umms_app_dtmgr_option_scr_data_struct *op_data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(data);
    if (data == NULL)
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
    if ((SRV_MMS_GET_USE_DETAILS_NUMBER == data->mms_umms_app_slide) ||
        (SRV_MMS_GET_USE_DETAILS_EMAIL == data->mms_umms_app_slide) ||
        (SRV_MMS_GET_USE_DETAILS_URL == data->mms_umms_app_slide))
    {
        switch (data->applib_addr_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                node1 = data->get_use_details_rsp.num_list;
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                node1 = data->get_use_details_rsp.email_list;
                break;
            case APPLIB_ADDR_TYPE_URL:
                node1 = data->get_use_details_rsp.url_list;
                break;
            default:
                MMI_ASSERT(0);
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
                break;
        }

    #ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
        count = data->get_use_details_rsp.start_index - 1;
        while (count <= data->get_use_details_rsp.end_index)
        {
            /* if ((node1->length != 0) || (node1->pos != 0))
               {
               count++;
               } */
            ++count;
            if (count == index)
            {
                break;
            }
            node1 = node1->next;
        }
    #else /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
        count = -1;
        while (count < index)
        {
            if ((node1->length != 0) || (node1->pos != 0))
            {
                ++count;
            }
            if (count == index)
            {
                break;
            }
            node1 = node1->next;
        }
    #endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
        *type = UMMS_DTMGR_DATA_TYPE_UCS2;
        return (S8*) node1->data;

    }
    else if ((SRV_MMS_GET_USE_DETAILS_SENDER == data->mms_umms_app_slide) ||
             (SRV_MMS_GET_USE_DETAILS_RECIPIENT == data->mms_umms_app_slide))
    {
        --count;
        if (SRV_MMS_GET_USE_DETAILS_RECIPIENT == data->mms_umms_app_slide)
        {
            parse_list = UMMS_TO_LIST;
        }
        switch (data->applib_addr_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                while ((count < index) && (parse_list < (UMMS_BCC_LIST + 1)))
                {
                    switch (parse_list)
                    {
                        case UMMS_FROM:
                            node2 = op_data->header_info->from;
                            if (node2 != NULL)
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                {
                                    count++;
                                }
                            }
                            parse_list = UMMS_BCC_LIST + 1;
                            break;
                        case UMMS_TO_LIST:
                            node2 = op_data->header_info->to;
                            while ((node2 != NULL) && (count < index))
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                {
                                    count++;
                                }
                                if (count < index)
                                {
                                    node2 = node2->next;
                                }
                            }
                            parse_list++;
                            break;
                        case UMMS_CC_LIST:
                            node2 = op_data->header_info->cc;
                            while ((node2 != NULL) && (count < index))
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                {
                                    count++;
                                }
                                if (count < index)
                                {
                                    node2 = node2->next;
                                }
                            }
                            parse_list++;
                            break;
                        case UMMS_BCC_LIST:
                            node2 = op_data->header_info->bcc;
                            while ((node2 != NULL) && (count < index))
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                {
                                    count++;
                                }
                                if (count < index)
                                {
                                    node2 = node2->next;
                                }
                            }
                            parse_list++;
                            break;
                        default:
                            break;
                    }
                }
                *type = UMMS_DTMGR_DATA_TYPE_ANSII;
                if (node2 == NULL)
                {
                    EXT_ASSERT(0, 0, 0, 0);
                }

                /* ASSERT(node2->addr); */
                return (S8*) node2->addr;
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                while ((count < index) && (parse_list < (UMMS_BCC_LIST + 1)))
                {
                    switch (parse_list)
                    {
                        case UMMS_FROM:
                            node2 = op_data->header_info->from;
                            if (node2 != NULL)
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                {
                                    count++;
                                }
                            }
                            parse_list = UMMS_BCC_LIST + 1;
                            break;
                        case UMMS_TO_LIST:
                            node2 = op_data->header_info->to;
                            while ((node2 != NULL) && (count < index))
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                {
                                    count++;
                                }
                                if (count < index)
                                {
                                    node2 = node2->next;
                                }
                            }
                            parse_list++;
                            break;
                        case UMMS_CC_LIST:
                            node2 = op_data->header_info->cc;
                            while ((node2 != NULL) && (count < index))
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                {
                                    count++;
                                }
                                if (count < index)
                                {
                                    node2 = node2->next;
                                }
                            }
                            parse_list++;
                            break;
                        case UMMS_BCC_LIST:
                            node2 = op_data->header_info->bcc;
                            while ((node2 != NULL) && (count < index))
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                {
                                    count++;
                                }
                                if (count < index)
                                {
                                    node2 = node2->next;
                                }
                            }
                            parse_list++;
                            break;

                        default:
                            break;
                    }
                }
                *type = UMMS_DTMGR_DATA_TYPE_UCS2;
                if (node2 == NULL)
                {
                    EXT_ASSERT(0, 0, 0, 0);
                }

                /* ASSERT(node2->addr); */
                return (S8*) node2->addr;
                break;
            default:
                MMI_ASSERT(0);
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
                return NULL;
                break;
        }

    }
    MMI_ASSERT(0);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_reset_use_details_list_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_reset_use_details_list_data(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_use_details_struct *data = mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_DELETE_USE_DETAILS_LIST);
    srv_mms_mem_mgr_app_adm_free(data);
    data = NULL;
    mmi_umms_app_dtmgr_free_data(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);
    return MMI_UMMS_TRUE;
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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_use_details_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8 *mmi_umms_app_dtmgr_get_use_details_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_use_details_struct *data =
        (mmi_umms_app_dtmgr_use_details_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_umms_app_dtmgr_get_addr_content_by_index(data->hilite_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_addr_content_by_index
 * DESCRIPTION
 *  This API saves the item at the given index to the Global Context
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S8 *mmi_umms_app_dtmgr_get_addr_content_by_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *node1 = NULL;
    srv_mms_addr_struct *node2 = NULL;
    U16 *use_details_addr = NULL;
    S32 count = 0;

    U8 parse_list = UMMS_FROM;
    U32 len = 0;
    mmi_umms_app_dtmgr_use_details_struct *data =
        (mmi_umms_app_dtmgr_use_details_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);
    mmi_umms_app_dtmgr_option_scr_data_struct *op_data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (use_details_addr != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(use_details_addr);
        use_details_addr = NULL;
    }
    if ((SRV_MMS_GET_USE_DETAILS_NUMBER == data->mms_umms_app_slide) ||
        (SRV_MMS_GET_USE_DETAILS_EMAIL == data->mms_umms_app_slide) ||
        (SRV_MMS_GET_USE_DETAILS_URL == data->mms_umms_app_slide))
    {
        switch (data->applib_addr_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                node1 = data->get_use_details_rsp.num_list;
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                node1 = data->get_use_details_rsp.email_list;
                break;
            case APPLIB_ADDR_TYPE_URL:
                node1 = data->get_use_details_rsp.url_list;
                break;
            default:
                MMI_ASSERT(0);
                break;
        }
    #ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
        count = data->get_use_details_rsp.start_index - 1;
        while (count <= data->get_use_details_rsp.end_index)
        {
            ++count;
            if (count == index)
            {
                break;
            }
            node1 = node1->next;
        }
    #else /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
        count = -1;
        while (count < index)
        {
            if ((node1->length != 0) || (node1->pos != 0))
            {
                ++count;
            }
            if (count == index)
            {
                break;
            }
            node1 = node1->next;
        }
    #endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
        if (APPLIB_ADDR_TYPE_PHONENUMBER == data->applib_addr_type)
        {
            len = mmi_ucs2strlen((S8*) (node1->data2));
            if (len > MMI_UC_MAX_PHONE_NUMBER_LEN)
            {
                len = MMI_UC_MAX_PHONE_NUMBER_LEN + 1;
            }
            use_details_addr = (U16*) srv_mms_mem_mgr_app_adm_alloc((len + 1) * ENCODING_LENGTH);
            MMI_ASSERT(use_details_addr);
            memset(use_details_addr, 0, (len + 1) * ENCODING_LENGTH);
            mmi_ucs2ncpy((S8*) use_details_addr, (S8*) node1->data2, len);
        }
        else
        {
            len = mmi_ucs2strlen((S8*) (node1->data));
            if (APPLIB_ADDR_TYPE_EMAIL == data->applib_addr_type)
            {
                if (len > MMI_EMAIL_MAX_ADDR_LEN)
                {
                    len = MMI_EMAIL_MAX_ADDR_LEN + 1;
                }
            }
            else
            {
                if (len > MMI_UMMS_MAX_URL_LENGTH)
                {
                    len = MMI_UMMS_MAX_URL_LENGTH + 1;
                }
            }
            use_details_addr = (U16*) srv_mms_mem_mgr_app_adm_alloc((len + 1) * ENCODING_LENGTH);
            MMI_ASSERT(use_details_addr);
            memset(use_details_addr, 0, (len + 1) * ENCODING_LENGTH);
            mmi_ucs2ncpy((S8*) use_details_addr, (S8*) node1->data, len);
        }
    }

    else if ((SRV_MMS_GET_USE_DETAILS_SENDER == data->mms_umms_app_slide) ||
             (SRV_MMS_GET_USE_DETAILS_RECIPIENT == data->mms_umms_app_slide))
    {
        --count;
        if (SRV_MMS_GET_USE_DETAILS_RECIPIENT == data->mms_umms_app_slide)
        {
            parse_list = UMMS_TO_LIST;
        }
        switch (data->applib_addr_type)
        {
            case APPLIB_ADDR_TYPE_PHONENUMBER:
                while ((count < index) && (parse_list < (UMMS_BCC_LIST + 1)))
                {
                    switch (parse_list)
                    {
                        case UMMS_FROM:
                            node2 = op_data->header_info->from;
                            if (node2 != NULL)
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                {
                                    count++;
                                }
                            }
                            parse_list++;
                            break;
                        case UMMS_TO_LIST:
                            node2 = op_data->header_info->to;
                            while ((node2 != NULL) && (count < index))
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                {
                                    count++;
                                }
                                if (count < index)
                                {
                                    node2 = node2->next;
                                }
                            }
                            parse_list++;
                            break;
                        case UMMS_CC_LIST:
                            node2 = op_data->header_info->cc;
                            while ((node2 != NULL) && (count < index))
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                {
                                    count++;
                                }
                                if (count < index)
                                {
                                    node2 = node2->next;
                                }
                            }
                            parse_list++;
                            break;
                        case UMMS_BCC_LIST:
                            node2 = op_data->header_info->bcc;
                            while ((node2 != NULL) && (count < index))
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER == node2->type)
                                {
                                    count++;
                                }
                                if (count < index)
                                {
                                    node2 = node2->next;
                                }
                            }
                            parse_list++;
                            break;
                        default:
                            break;
                    }
                }
                if (node2 == NULL)
                {
                    EXT_ASSERT(0, 0, 0, 0);
                }
                len = strlen((S8*) (node2->addr));
                if (len > MMI_UC_MAX_PHONE_NUMBER_LEN)
                {
                    len = MMI_UC_MAX_PHONE_NUMBER_LEN + 1;
                }
                use_details_addr = (U16*) srv_mms_mem_mgr_app_adm_alloc((len + 1) * ENCODING_LENGTH);
                MMI_ASSERT(use_details_addr);
                memset(use_details_addr, 0, (len + 1) * ENCODING_LENGTH);
                mmi_asc_n_to_ucs2((S8*) use_details_addr, (S8*) node2->addr, len);
                break;
            case APPLIB_ADDR_TYPE_EMAIL:
                while ((count < index) && (parse_list < 4))
                {
                    switch (parse_list)
                    {
                        case UMMS_FROM:
                            node2 = op_data->header_info->from;
                            if (node2 != NULL)
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                {
                                    count++;
                                }
                            }
                            parse_list++;
                            break;
                        case UMMS_TO_LIST:
                            node2 = op_data->header_info->to;
                            while ((node2 != NULL) && (count < index))
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                {
                                    count++;
                                }
                                if (count < index)
                                {
                                    node2 = node2->next;
                                }
                            }
                            parse_list++;
                            break;
                        case UMMS_CC_LIST:
                            node2 = op_data->header_info->cc;
                            while ((node2 != NULL) && (count < index))
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                {
                                    count++;
                                }
                                if (count < index)
                                {
                                    node2 = node2->next;
                                }
                            }
                            parse_list++;
                            break;
                        case UMMS_BCC_LIST:
                            node2 = op_data->header_info->bcc;
                            while ((node2 != NULL) && (count < index))
                            {
                                if (MMI_UMMS_ADDRESS_TYPE_EMAIL == node2->type)
                                {
                                    count++;
                                }
                                if (count < index)
                                {
                                    node2 = node2->next;
                                }
                            }
                            parse_list++;
                            break;

                        default:
                            break;
                    }
                }
                if (node2 == NULL)
                {
                    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
                }
                len = mmi_ucs2strlen((S8*) (node2->addr));
                if (len > MMI_EMAIL_MAX_ADDR_LEN)
                {
                    len = MMI_EMAIL_MAX_ADDR_LEN + 1;
                }
                use_details_addr = (U16*) srv_mms_mem_mgr_app_adm_alloc((len + 1) * ENCODING_LENGTH);
                MMI_ASSERT(use_details_addr);
                memset(use_details_addr, 0, (len + 1) * ENCODING_LENGTH);
                mmi_ucs2ncpy((S8*) use_details_addr, (S8*) node2->addr, len);
                break;
            default:
                MMI_ASSERT(0);
                break;
        }

    }

    return (S8*) use_details_addr;
}

/* SAMPLE APIs */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_progress_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_progress_data(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_progress_ready_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_progress_ready_check(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_confirm_screen_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cfrm_data       [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_set_confirm_screen_data(void *cfrm_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_CONFIRM_SCRN_DATA);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL)
    {
        cntx = mmi_umms_app_dtmgr_get_free_cntx(MMI_UMMS_APP_DTMGR_REQ_CONFIRM_SCRN_DATA);
    }
    cntx->data = cfrm_data;
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_check_use_details_for_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_check_use_details_for_viewer(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);
    mmi_umms_app_dtmgr_viewer_info_data *data = NULL;
    mma_mms_description_struct *desc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cntx);
    data = (mmi_umms_app_dtmgr_viewer_info_data*) cntx->data;
    ASSERT(data);
    desc = srv_mms_get_desc_pointer();
    if (data->shown_slide_num == desc->body->curr_slide->slide_num)
    {
        return MMI_UMMS_TRUE;
    }
    else
    {
    #ifndef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
        if (desc->body->curr_slide->txt.id == 0 || desc->body->curr_slide->txt.str_id != 0)
        {
            return MMI_UMMS_TRUE;
        }
    #endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
        if (data->shown_slide_num > 0)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PERFORMANCE_START_SLIDE_SWITCH);
        }
        return MMI_UMMS_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_use_details_for_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_viewer_use_details_list *mmi_umms_app_dtmgr_get_use_details_for_viewer(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);
    mmi_umms_app_dtmgr_viewer_info_data *data = NULL;
    srv_mms_get_use_details_viewer_req_struct msgreq;
    mma_mms_description_struct *desc;
    U32 curr_tick = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time((kal_uint32*) & curr_tick);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_UMMS_PERFORMANCE_TIME_CONSUMED_CATEGORY_CALLS_VIEWER_CB,
        kal_ticks_to_milli_secs(curr_tick - g_mms_last_tick));
    g_mms_last_tick = curr_tick;
    data = (mmi_umms_app_dtmgr_viewer_info_data*) cntx->data;
    desc = srv_mms_get_desc_pointer();
    if (data->shown_slide_num == desc->body->curr_slide->slide_num)
    {
        return data->list_head;
    }
    else
    {
        /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_SEND_USE_DETAILS_REQ_FOR_SLIDE, data->cat_info->msg_cntx->current_slide->slide_num); */
        /* ask service */
        memset(&msgreq, 0, sizeof(srv_mms_get_use_details_viewer_req_struct));
        msgreq.call_back = mmi_umms_app_dtmgr_get_use_details_for_viewer_cb;
        msgreq.user_data = (void*)&cntx->uid;
        if (srv_mms_get_use_details_for_slide((void*)&msgreq) == SRV_MMS_RESULT_NEED_LEAVE_TIMER)
        {
        #ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
        #ifndef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
            cntx->state = MMI_UMMS_APP_DTMGR_USE_DETAIL_START;
            StartTimer(MMS_VIEWER_TIMER, DTMGR_MMS_UNBLOCK_TIME, mmi_umms_app_dtmgr_viewer_use_detail_timer_expire);
        #endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
        #endif /* __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__ */ 
        }
        return NULL;
    }
}

#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
#ifndef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_viewer_use_detail_timer_expire
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_viewer_use_detail_timer_expire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);
    if (!cntx)
    {
        return;
    }
    switch (cntx->state)
    {
        case MMI_UMMS_APP_DTMGR_USE_DETAIL_START:
            result = srv_mms_viewer_start_compute_use_details(SRV_MMS_INSTANCE_DEFAULT_INDEX);
            if (result == MMI_TRUE)
            {
                cntx->state = MMI_UMMS_APP_DTMGR_USE_DETAIL_NUMBER;
            }
            break;
        case MMI_UMMS_APP_DTMGR_USE_DETAIL_NUMBER:
            result = srv_mms_viewer_get_numbers_on_slide(SRV_MMS_INSTANCE_DEFAULT_INDEX);
            if (result == MMI_TRUE)
            {
                cntx->state = MMI_UMMS_APP_DTMGR_USE_DETAIL_EMAIL;
            }
            break;
        case MMI_UMMS_APP_DTMGR_USE_DETAIL_EMAIL:
            result = srv_mms_viewer_get_emails_on_slide(SRV_MMS_INSTANCE_DEFAULT_INDEX);
            if (result == MMI_TRUE)
            {
                cntx->state = MMI_UMMS_APP_DTMGR_USE_DETAIL_URL;
            }
            break;
        case MMI_UMMS_APP_DTMGR_USE_DETAIL_URL:
            result = srv_mms_viewer_get_urls_on_slide(SRV_MMS_INSTANCE_DEFAULT_INDEX);
            if (result == MMI_TRUE)
            {
                cntx->state = MMI_UMMS_APP_DTMGR_USE_DETAIL_SORT;
            }
            break;
        case MMI_UMMS_APP_DTMGR_USE_DETAIL_SORT:
            srv_mms_viewer_rsp_for_use_details_for_category(SRV_MMS_INSTANCE_DEFAULT_INDEX);
            break;
    }
    if (result == MMI_TRUE)
    {
        StartTimer(MMS_VIEWER_TIMER, DTMGR_MMS_UNBLOCK_TIME, mmi_umms_app_dtmgr_viewer_use_detail_timer_expire);
    }
}
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
#endif /* __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_use_details_for_viewer_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result              [IN]        
 *  msgrsp              [?]         [?]
 *  user_data_ex        [?]         
 *  user_data(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_umms_app_dtmgr_get_use_details_for_viewer_cb(
                srv_mms_result_enum result,
                void *msgrsp,
                void *user_data_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *user_data = (U16*) user_data_ex;
    mma_mms_description_struct *desc;
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx_from_uid((U16) * user_data);
    mmi_umms_app_dtmgr_viewer_info_data *data = NULL;
    srv_mms_get_use_details_viewer_rsp_struct *rsp = (srv_mms_get_use_details_viewer_rsp_struct*) msgrsp;
    U32 curr_tick = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time((kal_uint32*) & curr_tick);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_UMMS_PERFORMANCE_TIME_CONSUMED_USE_DETAILS_VIEWER_CB,
        kal_ticks_to_milli_secs(curr_tick - g_mms_last_tick));
    g_mms_last_tick = curr_tick;
    desc = srv_mms_get_desc_pointer();
    if (!cntx)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_APP_ALREADY_DEINIT);
        return;
    }
    data = (mmi_umms_app_dtmgr_viewer_info_data*) cntx->data;
    ASSERT(data);
    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_GET_USE_DETAILS_RSP_FOR_SLIDE, data->cat_info->msg_cntx->current_slide->slide_num); */
    data->list_head = rsp->list_head;
    data->shown_slide_num = desc->body->curr_slide->slide_num;
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PERFORMANCE_VIEWER_CONTENT_RENDERED);
    mmi_umms_app_ui_plug_in_viewer_handover_to_category();
}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_check_template_scr_data_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_check_template_scr_data_ready(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_template_msg_list_info != NULL)
    {
    return MMI_UMMS_TRUE;
}
    return MMI_UMMS_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_template_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_umms_app_dtmgr_get_template_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_template_count;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_user_template_scr_info_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_user_template_scr_info_int(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mms_get_list_info_req_struct template_list_info_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&template_list_info_req, 0, sizeof(srv_mms_get_list_info_req_struct));
    template_list_info_req.user_data = NULL;
    template_list_info_req.app_id = MMA_APP_ID_TEMPLATE;
    template_list_info_req.template_type = SRV_UM_MSG_BOX_USRDEF_TEMPLATES;
    template_list_info_req.call_back = mmi_umms_app_core_get_list_info_cb;
    srv_mms_um_get_list_info((void*)&template_list_info_req);
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_get_list_info_rsp_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp_data        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_get_list_info_rsp_data(void *rsp_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    srv_mms_get_list_info_rsp_struct *msg = (srv_mms_get_list_info_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_template_msg_list_info)
    {
        srv_mms_mem_mgr_app_adm_free(g_template_msg_list_info);
        g_template_msg_list_info = NULL;
    }
    g_template_msg_list_info =
        (srv_um_msg_info_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_um_msg_info_struct) * msg->msg_number);

    MMI_ASSERT(g_template_msg_list_info != NULL);

    memset(g_template_msg_list_info, 0, sizeof(srv_um_msg_info_struct) * msg->msg_number);
    for (index = 0; index < msg->msg_number; index++)
    {
        g_template_msg_list_info[index].msg_id = msg->list_info[index].msg_id;
        g_template_msg_list_info[index].timestamp = msg->list_info[index].timestamp;
    }
    mmi_umms_app_template_get_msg_info(msg->msg_number, msg->msg_box_type);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_template_get_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_number          [IN]        
 *  msg_box_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_template_get_msg_info(U8 msg_number, U16 msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 loop;
    srv_mms_get_msg_info_req_struct template_msg_info_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&template_msg_info_req, 0, sizeof(srv_mms_get_msg_info_req_struct));
    template_msg_info_req.user_data = NULL;
    template_msg_info_req.app_id = MMA_APP_ID_TEMPLATE;
    template_msg_info_req.template_type = msg_box_type;
    template_msg_info_req.call_back = mmi_umms_app_core_get_template_msg_info_cb;
    template_msg_info_req.msg_number = msg_number;
    for (loop = 0; loop < template_msg_info_req.msg_number; loop++)
    {
        template_msg_info_req.msg_id[loop] = g_template_msg_list_info[loop].msg_id;
    }
    srv_mms_um_get_template_msg_info((void*)&template_msg_info_req);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_template_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp_data        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_template_msg_info(void *rsp_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    srv_mms_get_msg_info_rsp_struct *msg = (srv_mms_get_msg_info_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_template_count = msg->msg_number;

    for (index = 0; index < msg->msg_number; index++)
    {
        g_template_msg_list_info[index].address_type = msg->msg_info[index].address_type;

        if (msg->msg_info[index].address_length > 0)
        {
            g_template_msg_list_info[index].address_length = msg->msg_info[index].address_length;
            mmi_ucs2ncpy(
                (S8*) g_template_msg_list_info[index].address,
                (S8*) msg->msg_info[index].address,
                msg->msg_info[index].address_length);

        }
        else
        {
            mmi_ucs2ncpy(
                (S8*) g_template_msg_list_info[index].address,
                (S8*) GetString(STR_ID_UMMS_USE_DETAILS_NO_NUMBER),
                SRV_UM_MAX_SUBJECT_LEN);
            g_template_msg_list_info[index].address_length = mmi_ucs2strlen((S8*) GetString(STR_ID_UMMS_USE_DETAILS_NO_NUMBER));
        }
        if (msg->msg_info[index].subject_length > 0)
        {
            g_template_msg_list_info[index].subject_length = msg->msg_info[index].subject_length;
            mmi_ucs2ncpy(
                (S8*) g_template_msg_list_info[index].subject,
                (S8*) msg->msg_info[index].subject,
                msg->msg_info[index].subject_length);
        }
        else
        {
            mmi_ucs2ncpy(
                (S8*) g_template_msg_list_info[index].subject,
                (S8*) GetString(STR_ID_UMMS_NO_SUBJECT),
                SRV_UM_MAX_SUBJECT_LEN);
            g_template_msg_list_info[index].subject_length = mmi_ucs2strlen((S8*) GetString(STR_ID_UMMS_NO_SUBJECT));
        }
        g_template_msg_list_info[index].icon_id = msg->msg_info[index].icon_id;
        
        g_template_msg_list_info[index].csk_icon_id = msg->msg_info[index].csk_icon_id;
        

    }
    if (msg->msg_box_type == SRV_UM_MSG_BOX_PREDEF_TEMPLATES)
    {
        g_dtmgr_default_mms_creation.template_type = MMI_UMMS_DEFAULT_TYPE;
    }
    else if (msg->msg_box_type == SRV_UM_MSG_BOX_USRDEF_TEMPLATES)
    {
        g_dtmgr_default_mms_creation.template_type = MMI_UMMS_USER_DEFINED_TYPE;
    }
    else
    {
        MMI_ASSERT(0);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_tmplt_gen_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct      [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_umms_app_dtmgr_tmplt_gen_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_base_event_struct *param = (srv_mms_base_event_struct*) evt;
    mma_result_enum *result = (mma_result_enum*) param->sender_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(*result == MMA_RESULT_OK)
    {
        if(mmi_frm_scrn_is_present (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS_TMPLT, MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_umms_app_dtmgr_get_default_template_scr_info_int(0);
        }
    }
    else
    {
        if(mmi_frm_scrn_is_present (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS_TMPLT, MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
            mmi_umms_app_if_show_display_popup_screen();

            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS_TMPLT);
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_default_template_scr_info_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_default_template_scr_info_int(U16 scr_id)
{

    if(srv_mms_default_template_is_ready())
        {

        mmi_umms_app_dtmgr_default_template_list_info_req();
        /* Show the template list */
    }
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_default_template_list_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_default_template_list_info_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_list_info_req_struct template_list_info_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&template_list_info_req, 0, sizeof(srv_mms_get_list_info_req_struct));
    template_list_info_req.user_data = NULL;
    template_list_info_req.app_id = MMA_APP_ID_TEMPLATE;
    template_list_info_req.template_type = SRV_UM_MSG_BOX_PREDEF_TEMPLATES;
    template_list_info_req.call_back = mmi_umms_app_core_get_list_info_cb;
    srv_mms_um_get_list_info((void*)&template_list_info_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_init_template_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_bootup       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_dtmgr_init_template_folder(MMI_BOOL is_bootup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result = FS_NO_ERROR;
    U8 folder_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(folder_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
    MMI_UMMS_MAKE_TEMPLATE_FOLDER_PATH(folder_path);

    /* if the dir exists, delete it */
    file_handle = FS_Open((WCHAR*) folder_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle >= 0)
    {
        FS_Close(file_handle);

        FS_XDelete((WCHAR*) folder_path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    }

    result = FS_CreateDir((WCHAR*) folder_path);
    if (!is_bootup)
    {
        if (result < 0)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_TEMLATE_DIR_FAIL);
            if (srv_mms_is_usb_mode())
            {
            #ifdef __USB_IN_NORMAL_MODE__
                mmi_usb_app_unavailable_popup(0);
            #endif 
            }
            else
            {
                mmi_umms_app_ui_plug_in_template_error_popup_handling(result);
            }
            mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS_TMPLT);
            return result;
        }
    }
    FS_SetAttributes((unsigned short*)folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    return result;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_template_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  menuData            [?]         [?]
 *  dnumber_of_item     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_ui_callback_template_get_data(S32 item_index, gui_iconlist_menu_item *menuData, S32 dnumber_of_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > 5))
    {
        return 0;
    }
    for (count = 0; count < dnumber_of_item; count++)
    {
        menuData[count].image_list[0] = get_image((U16) g_template_msg_list_info[item_index + count].icon_id);
        if (g_template_msg_list_info[count].subject_length)
        {
            mmi_ucs2cpy((S8*) menuData[count].item_list[0], (S8*) g_template_msg_list_info[item_index + count].subject);
        }
        else
        {
            mmi_ucs2cpy((S8*) menuData[count].item_list[0], (S8*) GetString(STR_ID_UMMS_NO_SUBJECT));
        }
    }
    return dnumber_of_item;

}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_current_hilighted_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_umms_app_dtmgr_get_current_hilighted_msg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hilighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hilighted_item = mmi_umms_app_dtmgr_get_current_message_index();
    return g_template_msg_list_info[hilighted_item].msg_id;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_current_message_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_current_message_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtmgr_default_mms_creation.current_msg_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_current_message_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_dtmgr_get_current_message_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_dtmgr_default_mms_creation.current_msg_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_current_template_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_umms_templates_type_enum mmi_umms_app_dtmgr_get_current_template_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_dtmgr_default_mms_creation.template_type;

}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
#ifdef __MMI_MMS_ITERATOR_VIEWER__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_msg_id_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_umms_app_dtmgr_get_msg_id_by_index(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    if (g_template_msg_list_info)
    {
        return g_template_msg_list_info[index].msg_id;
    }
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
    return 0;

}
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_reset_template_list_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_reset_template_list_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_template_msg_list_info)
    {
        srv_mms_mem_mgr_app_adm_free(g_template_msg_list_info);
        g_template_msg_list_info = NULL;
    }
    mmi_umms_app_dtmgr_reset_template_state_on_end_key();
    /* this is to close file handle at safe side */
    srv_mms_close_xml_file_handle();
    mmi_umms_app_dtmgr_reset_userdef_template_del_from_phone_suite_flag();
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    mmi_umms_app_dtmgr_set_refresh_flag(MMI_FALSE);
#endif 

}

#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_sim_status_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_sim_status_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if ((GetActiveScreenId() == SCR_ID_UMMS_SIM_OPTION) */
    {
        /* GoBackHistory(); */
    }
}

#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_data_for_phb_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_data_for_phb_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *scr_info;

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
    mmi_umms_op_op11_struct *op_data;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    if (scr_info->folder_id == MMA_FOLDER_INBOX ||
        ((scr_info->folder_id == MMA_FOLDER_ARCHIVE) && (scr_info->msg_info->prev_folder == MMA_FOLDER_INBOX)))
    {
        memset(&g_umms_app_dtmgr_phb_notify, 0, sizeof(mmi_umms_app_dtmgr_phb_notify_struct));
        /* g_umms_phb_notify_context->current_selected_sender_address = */
        g_umms_app_dtmgr_phb_notify.current_selected_sender_address_type = scr_info->msg_info->from_address_type;
        g_umms_app_dtmgr_phb_notify.current_selected_folde_type = scr_info->folder_id;
    #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
        op_data = mmi_umms_op_get_op11_data();
        g_umms_app_dtmgr_phb_notify.is_hs_active = srv_mms_get_hs_active();
        g_umms_app_dtmgr_phb_notify.is_hs_recent_event_active = srv_mms_get_hs_event();
    #endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 
        mmi_ucs2ncpy(
            (S8*) g_umms_app_dtmgr_phb_notify.current_selected_sender_address,
            (S8*) scr_info->msg_info->from_address,
            MMA_MAX_ADDR_LEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_data_for_phb_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_umms_app_dtmgr_phb_notify_struct *mmi_umms_app_dtmgr_get_data_for_phb_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_umms_app_dtmgr_phb_notify;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_reset_data_for_phb_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_reset_data_for_phb_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_umms_app_dtmgr_phb_notify, 0, sizeof(mmi_umms_app_dtmgr_phb_notify_struct));
}
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_reset_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_reset_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_RESET_DATA);
    if (info)
    {
        if (info->xml_file_path)
        {
            srv_mms_mem_mgr_app_adm_free(info->xml_file_path);
            info->xml_file_path = NULL;
        }
        if (info->msg_info)
        {
            srv_mms_mem_mgr_app_adm_free(info->msg_info);
            info->msg_info = NULL;
        }
        if (info->header_info)
        {
            srv_mms_mem_mgr_app_asm_free(info->header_info);
            info->header_info = NULL;
        }
        if (info->bgsr_msg_info)
        {
            srv_mms_mem_mgr_app_adm_free(info->bgsr_msg_info);
            info->bgsr_msg_info = NULL;
        }
        if (info->msg_path)
        {
            srv_mms_mem_mgr_app_adm_free(info->msg_path);
            info->msg_path = NULL;
        }
        if (info->file_path)
        {
            srv_mms_mem_mgr_app_adm_free(info->file_path);
            info->file_path = NULL;
        }
    #ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
        if (info->status_list)
        {
            mmi_umms_app_dtmgr_reset_status_data(info->status_list);
            info->status_list = NULL;
        }
    #endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ 
        /* memset(info, 0, sizeof(mmi_umms_app_dtmgr_option_scr_data_struct)); */
        srv_mms_mem_mgr_app_adm_free(info);
        info = NULL;
        srv_mms_mem_mgr_asm_deinit_memory(APPLIB_MEM_AP_ID_UMMS, SRV_MMS_INSTANCE_DEFAULT_INDEX);
        /* srv_mms_mem_mgr_asm_deinit_memory(APPLIB_MEM_AP_ID_ADM_UMMS); */
    }
    mmi_umms_app_dtmgr_free_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    mmi_umms_app_if_deinit_viewer();
#if defined(__MMI_OP12_TOOLBAR__)
    mmi_umms_op_reset_op12_data();
#endif 

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
    mmi_umms_op_reset_op11_data();
#endif 
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_umms_op_reset_op11_hs32_data();
#endif 
#ifdef __MMI_FTE_SUPPORT__
    srv_mms_reset_sync_data();
#endif 
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    mmi_umms_app_dtmgr_free_data(MMI_UMMS_APP_DTMGR_REQ_UM_USER_DATA);
    mmi_umms_app_dtmgr_free_data(MMI_UMMS_APP_DTMGR_REQ_OTHER_MSG_INFO);
    mmi_frm_cb_dereg_event(
        EVT_ID_MMI_UM_REFRESH,
        (mmi_proc_func) mmi_umms_app_dtmgr_update_indexing_data_from_um,
        NULL);
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
#ifdef __MMI_MMS_IMAGE_VIEW_ENHANCEMENT__
	mmi_umms_app_dtmgr_gdi_close_decoder(WGUI_MV_IMAGE_DECODED_FAILED, NULL, MMI_FALSE);
	memset(&g_umms_viewer_image_decoder_struct, 0, sizeof(mmi_umms_app_dtmgr_image_decode_struct));
#endif

}

#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_reset_status_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status_list     [?]     
 *  object_info     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_reset_status_data(wap_mma_mms_msg_report_status_struct *status_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_mms_msg_report_status_struct *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (status_list)
    {
        temp = status_list;
        status_list = status_list->next;
        srv_mms_mem_mgr_app_asm_free(temp);
        temp = NULL;
    }

}
#endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ /* __MMI_MMS_REPORT_BOX_SUPPORT__ */

/*****************************************************************************/
/*******************amit added for save objects here *************************/

/* flag will either on or off */

#if 0
#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
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
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
#endif /* 0 */ 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_signature_audio_disp_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_signature_audio_disp_path(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_disp_buffer_audio = path;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_signature_audio_disp_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8 *mmi_umms_app_dtmgr_get_signature_audio_disp_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_disp_buffer_audio;
}
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
#if 0
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
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
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
#endif /* 0 */ 
/*****signature path get function*************************/

/***************************************************************************/

/***************************set functions**********************************/

/***********************for template csk icon_id***********************/

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_template_list_csk_icon_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_dtmgr_get_template_list_csk_icon_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 message_index = mmi_umms_app_dtmgr_get_current_message_index();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    
    return g_template_msg_list_info[message_index].csk_icon_id;
    
         
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_reset_template_state_on_end_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_reset_template_state_on_end_key(void)
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
 *  mmi_umms_app_dtmgr_set_template_delete_and_stop_handling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_template_delete_and_stop_handling(U8 flag)
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
 *  mmi_umms_app_dtmgr_get_template_delete_and_stop_handling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_umms_app_dtmgr_get_template_delete_and_stop_handling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_template_default_creation_progress_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_template_default_creation_progress_check(U8 flag)
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
 *  mmi_umms_app_dtmgr_get_template_default_creation_progress_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_umms_app_dtmgr_get_template_default_creation_progress_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_userdef_template_del_from_phone_suite_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_dtmgr_set_userdef_template_del_from_phone_suite_flag(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    mmi_um_iter_viewer_result_struct *data = NULL;
    U8 index = 0, curr_index = 0;
    U32 *msg_id = (U32*) evt->user_data;
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_message_deleted_from_phone_suite = MMI_TRUE;
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    data = (mmi_um_iter_viewer_result_struct*) mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_OTHER_MSG_INFO);
    while (index < 5 && data != NULL && g_template_msg_list_info != NULL)
    {
        if (g_template_msg_list_info[index].msg_id == *msg_id)
        {
            curr_index = mmi_umms_app_dtmgr_get_current_message_index();
            if (index < curr_index)
            {
                mmi_umms_app_dtmgr_set_current_message_index(--curr_index);
                data->index_number--;
            }
            g_template_count--;
            data->total_number--;

            if (g_template_count == 1)
            {
                if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_MMS_VIEWER ||
                    mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN ||
                    mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN)
                {
                    mmi_umms_app_core_um_data_ready_cb(NULL);
                }
                else
                {
                    mmi_umms_app_core_query_indexing_for_template_iter_view(data);
                }
            }
            break;
        }
        index++;
    }

#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_reset_userdef_template_del_from_phone_suite_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_reset_userdef_template_del_from_phone_suite_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_message_deleted_from_phone_suite = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_userdef_template_del_from_phone_suite_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_umms_app_dtmgr_get_userdef_template_del_from_phone_suite_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_message_deleted_from_phone_suite;
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_bookmark_cui_id
 * DESCRIPTION
 *  set the global cui id value
 * PARAMETERS
 *  phb_cui_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_bookmark_cui_id(U16 phb_cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_bookmark_cui_id = phb_cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_bookmark_cui_id
 * DESCRIPTION
 *  get the global cui id value
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_umms_app_dtmgr_get_bookmark_cui_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_bookmark_cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_prop_convert_umbox_type_to_mma_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  um_box_type     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_dtmgr_prop_convert_umbox_type_to_mma_folder(U16 um_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (um_box_type)
    {
        case SRV_UM_MSG_BOX_INBOX:
            return MMA_FOLDER_INBOX;
        case SRV_UM_MSG_BOX_UNSENT:
            return MMA_FOLDER_OUTBOX;
        case SRV_UM_MSG_BOX_SENT:
            return MMA_FOLDER_SENT;
        case SRV_UM_MSG_BOX_DRAFT:
            return MMA_FOLDER_DRAFT;
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_UM_MSG_BOX_ARCHIVE:
            return MMA_FOLDER_ARCHIVE;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
        case SRV_UM_MSG_BOX_PREDEF_TEMPLATES:
            return MMA_FOLDER_TEMPLATE;
        case SRV_UM_MSG_BOX_USRDEF_TEMPLATES:
            return MMA_FOLDER_USRDEF_TEMPLATE;
    }
    return MMA_FOLDER_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_forward_option_scrn_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  user_data       [IN]        
 *  msgrsp          [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_forward_option_scrn_data(S32 result, U32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    mmi_umms_app_dtmgr_option_scr_data_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_APP_ALREADY_DEINIT);
        return;
    }
    data = (mmi_umms_app_dtmgr_option_scr_data_struct*) cntx->data;
    ASSERT(data);
    if (data == NULL)
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_MMS_DTMGR_CRITICAL_ERROR, __LINE__);
    mmi_umms_app_dtmgr_get_option_scr_info_cb(result, NULL, user_data);
    if (!cntx)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_APP_ALREADY_DEINIT);
        return;
    }
    switch (cntx->state)
    {
        case MMI_UMMS_APP_DTMGR_GET_MSG_INFO_WAIT:
            switch (data->msg_info->msg_type)
            {
                case MMA_MSG_TYPE_READ_REPORT:
                case MMA_MSG_TYPE_DELIVERY_REPORT:
                    mmi_umms_app_if_show_inbox_read_delivery_option();
                    break;
                case MMA_MSG_TYPE_NOTIFICATION:
                    /* mmi_umms_app_if_show_inbox_notification_option(); */
                    break;
                case MMA_MSG_TYPE_MMS:
            #ifdef __MMI_MMS_POSTCARD__
                case MMA_MSG_TYPE_POSTCARD:
            #endif 
                    break;
                case MMA_MSG_TYPE_TEMPLATE:
                    /* mmi_umms_entry_templates_options_screen(); */
                    break;
                case MMA_MSG_TYPE_JAVA:
                    mmi_umms_app_if_show_java_mms_options();
                    break;
                default:
                    MMI_ASSERT(data->msg_info->msg_type);
                    break;
            }
            break;

    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_forward_viewer_option_scrn_data
 * DESCRIPTION
 *  if ASM successfully freed memory then this is called
 * PARAMETERS
 *  result          [IN]        
 *  user_data       [IN]        
 *  msgrsp          [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_forward_viewer_option_scrn_data(S32 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_APP_ALREADY_DEINIT);
        return;
    }

    mmi_umms_app_dtmgr_get_viewer_data_ready_cb(result, NULL, user_data);

}

#ifdef __MMI_MMS_ITERATOR_VIEWER__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_handle_action_on_curr_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  other_msg_data                          [IN]        
 *  folder_id                               [IN]        
 *  um_data                                 [?]         
 *  parent_id                               [IN]        
 *  mmi_um_iter_viewer_result_struct(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_handle_action_on_curr_msg(
        mmi_um_iter_viewer_result_struct other_msg_data,
        U8 folder_id,
        void *um_data,
        mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_um_refresh_ind_struct req;

    // mmi_id parent_id = mmi_umms_app_dtmgr_get_parent_grp_id();/*(U16 *)mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_UM_GRP_ID);*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (folder_id == MMA_FOLDER_TEMPLATE)
    {
        /* No action is possible on default templates so if any its an error case */
        mmi_umms_app_if_deinit_viewer();
        return;
    }
    if (folder_id == MMA_FOLDER_USRDEF_TEMPLATE)
    {
        if (other_msg_data.total_number > 1)    /* In case this is last template to be deleted */
            /* , dont refresh screen as while goin back it will auto refresh */
        {
            mmi_umms_app_dtmgr_set_refresh_flag(MMI_TRUE);
            mmi_umms_app_dtmgr_refresh_templates();
        }
    }
    else
    {
        req.msg_box_type = folder_id;
        srv_mms_um_refresh_msg_list(&req);
    }
    if (other_msg_data.next_launch_func_ptr)
    {
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        /* other_msg_data.index_number +=1; */
        if (folder_id == MMA_FOLDER_TEMPLATE || folder_id == MMA_FOLDER_USRDEF_TEMPLATE)
        {
            mmi_umms_app_dtmgr_set_current_message_index(other_msg_data.index_number - 1);
        }
    #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
        other_msg_data.next_launch_func_ptr(
                        parent_id,
                        other_msg_data.next_msg_id,
                        um_data,
                        CUI_MSG_VIEWER_TYPE_ITERATOR);
    }
    else if (other_msg_data.prev_launch_func_ptr)
    {
        /* other_msg_data.index_number +=1; */
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        if (folder_id == MMA_FOLDER_TEMPLATE || folder_id == MMA_FOLDER_USRDEF_TEMPLATE)
        {
            mmi_umms_app_dtmgr_set_current_message_index(other_msg_data.index_number - 2);
        }
    #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
        other_msg_data.prev_launch_func_ptr(
                        parent_id,
                        other_msg_data.prev_msg_id,
                        um_data,
                        CUI_MSG_VIEWER_TYPE_ITERATOR);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_refresh_templates
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_refresh_templates(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    mmi_umms_app_dtmgr_get_user_template_scr_info_int(0);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_refresh_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag            [IN]        
 *  MMI_BOOL(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_refresh_flag(MMI_BOOL flag)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_refresh_templates = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_refresh_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_dtmgr_get_refresh_flag(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_refresh_templates;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_iterator_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_active       [IN]        
 *  void *user_data  [In](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_iterator_status(MMI_BOOL is_active)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_iterator_active = is_active;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_iterator_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  user_data
 *****************************************************************************/
MMI_BOOL mmi_umms_app_dtmgr_get_iterator_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_iterator_active;
}
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ /* not defined __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
#endif /* __MMI_MMS_2__ */ 
#ifdef __MMI_MMS_2__
/* Common Utility functions so can not comment in slim macro */

/* Screen group */
static MMI_BOOL g_mmi_umms_dtmgr_screen_group_flag = MMI_FALSE;
static MMI_BOOL g_umms_app_dtmgr_proc_flag = MMI_FALSE;
static MMI_BOOL g_mmi_umms_dtmgr_tmplte_screen_group_flag;
static mmi_umms_app_dtmgr_progress_scrn_struct g_umms_dtmgr_progress_scrn_data;
static mmi_id g_dtmgr_um_grp_id = GRP_ID_INVALID;
static MMI_ID g_mmi_umms_dtmgr_screen_group_id = GRP_ID_INVALID;
mmi_umms_app_dtmgr_confrim_screen_struct g_umms_app_app_dtmgr_confirm_scr_data;
static MMI_ID g_umms_common_cui_id = GRP_ID_INVALID;
static MMI_ID g_umms_common_cui_id_ext = GRP_ID_INVALID;
static MMI_ID g_umms_menu_cui_id = GRP_ID_INVALID;
static MMI_ID g_umms_app_dtmgr_compose_image_gid = GRP_ID_INVALID;
static MMI_ID g_umms_fmgr_cui_id = GRP_ID_INVALID;
mmi_umms_app_dtmgr_inline_settings_struct dtmgr_settings_temp_context;
mmi_umms_app_dtmgr_inline_settings_struct *g_umms_context = &dtmgr_settings_temp_context;
mmi_umms_app_dtmgr_compose_signature_ui_handling_struct dtmgr_signature_handling;
mmi_umms_app_dtmgr_compose_signature_ui_handling_struct *dtmgr_sign_ui_handle = &dtmgr_signature_handling;
static void mmi_umms_app_core_set_setting_rsp_cb(srv_mms_result_enum result, void *rsp_data, void *user_data);
U8 g_dtmgr_recieve_filter_done = 0;


U8 g_active_sim = 0;

U16 g_umms_sim_sel_cui_id = 0;

/* Popup Data */
static mmi_umms_app_dtmgr_popup_screen_struct g_mms_app_dtmgr_popup_scr_data;
static mmi_umms_app_dtmgr_callback_popup_screen_struct g_mms_app_dtmgr_callback_popup_scr_data;
static mmi_umms_app_dtmgr_infinite_popup_screen_struct g_mms_app_dtmgr_infinite_popup_scr_data;


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dtmgr_set_proc_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_dtmgr_set_proc_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_app_dtmgr_proc_flag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dtmgr_get_proc_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_dtmgr_get_proc_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_app_dtmgr_proc_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_progress_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_umms_app_dtmgr_progress_scrn_struct *mmi_umms_app_dtmgr_get_progress_data()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_umms_dtmgr_progress_scrn_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dtmgr_set_group_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_dtmgr_set_group_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_umms_dtmgr_screen_group_flag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dtmgr_check_group_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_dtmgr_check_group_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_umms_dtmgr_screen_group_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_parent_grp_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_grp_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_parent_grp_id(U16 parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtmgr_um_grp_id = parent_grp_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_parent_grp_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_dtmgr_get_parent_grp_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_dtmgr_um_grp_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dtmgr_set_group_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_dtmgr_set_group_id(MMI_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_umms_dtmgr_screen_group_id = id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dtmgr_get_group_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_ID mmi_umms_dtmgr_get_group_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_umms_dtmgr_screen_group_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dtmgr_set_tenplate_group_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_dtmgr_set_tenplate_group_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_umms_dtmgr_tmplte_screen_group_flag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dtmgr_check_tenplate_group_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_dtmgr_check_tenplate_group_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_umms_dtmgr_tmplte_screen_group_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_common_cui_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cui_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_common_cui_id(U16 cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_common_cui_id = cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_common_cui_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_dtmgr_get_common_cui_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_common_cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_common_cui_id_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cui_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_common_cui_id_ext(U16 cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_common_cui_id_ext = cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_common_cui_id_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_dtmgr_get_common_cui_id_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_common_cui_id_ext;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_menu_cui_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cui_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_menu_cui_id(U16 cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_menu_cui_id = cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_menu_cui_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_dtmgr_get_menu_cui_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_menu_cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dtmgr_set_compose_image_gid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_dtmgr_set_compose_image_gid(MMI_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_app_dtmgr_compose_image_gid = id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dtmgr_use_compose_image_gid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_ID mmi_umms_dtmgr_use_compose_image_gid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_id = g_umms_app_dtmgr_compose_image_gid;
    g_umms_app_dtmgr_compose_image_gid = GRP_ID_INVALID;
    return grp_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_fmgr_file_select_cui_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  phb_cui_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_fmgr_file_select_cui_id(U16 phb_cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_fmgr_cui_id = phb_cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_fmgr_file_select_cui_id
 * DESCRIPTION
 *  get the global cui id value
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_umms_app_dtmgr_get_fmgr_file_select_cui_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_fmgr_cui_id;
}

#if(MMI_MAX_SIM_NUM >= 3)


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_sim_sel_cui_id
 * DESCRIPTION
 *  get the global cui id value
 * PARAMETERS
 *  cui_id      [IN]        
 * RETURNS
 *  U16(?)
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_sim_sel_cui_id(U16 cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_sim_sel_cui_id = cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_sim_sel_cui_id
 * DESCRIPTION
 *  get the global cui id value
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_umms_app_dtmgr_get_sim_sel_cui_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_umms_sim_sel_cui_id;
}
#endif /* (MMI_MAX_SIM_NUM >= 3) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_confirm_screen_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lsk_str_id          [IN]        
 *  lsk_icon_id         [IN]        
 *  rsk_str_id          [IN]        
 *  rsk_icon_id         [IN]        
 *  message             [?]         [?]
 *  mmi_event           [IN]        
 *  need_history        [IN]        
 *  need_csk            [IN]        
 *  lsk_handler         [IN]        
 *  rsk_handler         [IN]        
 *  exit_screen         [IN]        
 *  del_scr_handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_confirm_screen_para(
        U16 lsk_str_id,
        /* String id of LSK */ U16 lsk_icon_id,
        /* Icon id of LSK */ U16 rsk_str_id,
        /* String id of RSK */ U16 rsk_icon_id,
        U16 *message,
        U16 mmi_event,
        MMI_BOOL need_history,
        MMI_BOOL need_csk,
        void (*lsk_handler) (void),
        void (*rsk_handler) (void),
        void (*exit_screen) (void),
        mmi_ret del_scr_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_app_app_dtmgr_confirm_scr_data.lsk_str_id = lsk_str_id;
    g_umms_app_app_dtmgr_confirm_scr_data.lsk_icon_id = lsk_icon_id;
    g_umms_app_app_dtmgr_confirm_scr_data.rsk_str_id = rsk_str_id;
    g_umms_app_app_dtmgr_confirm_scr_data.rsk_icon_id = rsk_icon_id;
    memset(g_umms_app_app_dtmgr_confirm_scr_data.message, 0, MMI_UMMS_MAX_POPUP_LENGTH * ENCODING_LENGTH);
    memcpy(g_umms_app_app_dtmgr_confirm_scr_data.message, message, MMI_UMMS_MAX_POPUP_LENGTH * ENCODING_LENGTH);
    g_umms_app_app_dtmgr_confirm_scr_data.mmi_event = mmi_event;
    g_umms_app_app_dtmgr_confirm_scr_data.need_history = need_history;
    g_umms_app_app_dtmgr_confirm_scr_data.need_csk = need_csk;
    g_umms_app_app_dtmgr_confirm_scr_data.lsk_handler = lsk_handler;
    g_umms_app_app_dtmgr_confirm_scr_data.rsk_handler = rsk_handler;
    g_umms_app_app_dtmgr_confirm_scr_data.exit_screen = exit_screen;
    g_umms_app_app_dtmgr_confirm_scr_data.del_scr_handler = del_scr_handler;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_confirm_screen_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_umms_app_dtmgr_get_confirm_screen_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (void*)&g_umms_app_app_dtmgr_confirm_scr_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_popup_screen_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string_id       [?]         [?]
 *  event_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_popup_screen_para(U16 *string_id, U16 event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_mms_app_dtmgr_popup_scr_data.string_id, 0, MMI_UMMS_MAX_POPUP_LENGTH * ENCODING_LENGTH);
    memcpy(g_mms_app_dtmgr_popup_scr_data.string_id, string_id, MMI_UMMS_MAX_POPUP_LENGTH * ENCODING_LENGTH);
    g_mms_app_dtmgr_popup_scr_data.event_type = event_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_progress_scrn_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title_str_id        [IN]        
 *  display_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_progress_scrn_data(U16 title_str_id, U16 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_dtmgr_progress_scrn_data.title_str_id = title_str_id;
    g_umms_dtmgr_progress_scrn_data.display_id = display_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_infinite_popup_screen_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string_id           [?]         [?]
 *  image_id            [IN]        
 *  tone_id             [IN]        
 *  event_type(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_infinite_popup_screen_para(U16 *string_id, U16 image_id, U16 tone_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_mms_app_dtmgr_infinite_popup_scr_data.string_id, 0, MMI_UMMS_MAX_POPUP_LENGTH * ENCODING_LENGTH);
    memcpy(g_mms_app_dtmgr_infinite_popup_scr_data.string_id, string_id, MMI_UMMS_MAX_POPUP_LENGTH * ENCODING_LENGTH);
    g_mms_app_dtmgr_infinite_popup_scr_data.image_id = image_id;
    g_mms_app_dtmgr_infinite_popup_scr_data.tone_id = tone_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_callback_popup_screen_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string                  [?]         [?]
 *  event_type              [IN]        
 *  success_callback        [IN]        
 *  failure_callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_callback_popup_screen_para(
        U16 *string,
        U16 event_type,
        void (*success_callback) (void),
        void (*failure_callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_mms_app_dtmgr_callback_popup_scr_data.string, 0, MMI_UMMS_MAX_POPUP_LENGTH * ENCODING_LENGTH);
    memcpy(g_mms_app_dtmgr_callback_popup_scr_data.string, string, MMI_UMMS_MAX_POPUP_LENGTH * ENCODING_LENGTH);
    g_mms_app_dtmgr_callback_popup_scr_data.event_type = event_type;
    g_mms_app_dtmgr_callback_popup_scr_data.success_callback = success_callback;
    g_mms_app_dtmgr_callback_popup_scr_data.failure_callback = failure_callback;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_popup_screen_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_umms_app_dtmgr_get_popup_screen_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (void*)&g_mms_app_dtmgr_popup_scr_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_infinite_popup_screen_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_umms_app_dtmgr_get_infinite_popup_screen_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (void*)&g_mms_app_dtmgr_infinite_popup_scr_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_callback_popup_screen_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_umms_app_dtmgr_get_callback_popup_screen_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (void*)&g_mms_app_dtmgr_callback_popup_scr_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_readmark
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  read        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_readmark(U32 msg_id, MMI_BOOL read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 error = 0;
    U8 srv_result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_result = srv_mms_set_read_status(msg_id, read, &error);

    if (srv_result != SRV_MMS_RESULT_OK)
    {
        return;
    }
    if (error == SRV_MMS_RESULT_OK)
    {
        srv_mms_show_status_icon();
    }
    return;
}

#ifndef __MMI_MMS_NO_REPORT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_send_read_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id                  [IN]        
 *  sim_id                  [IN]        
 *  storage_location        [IN]        
 *  folder_id(?)            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_send_read_report(U32 msg_id, U8 sim_id, U8 storage_location)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_send_read_report_req_struct msgreq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&msgreq, 0, sizeof(srv_mms_send_read_report_req_struct));
    msgreq.sim_id = sim_id;
    msgreq.msg_id = msg_id;
    msgreq.storage_location = storage_location;
    srv_mms_send_read_report_req(&msgreq);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_abort_send_read_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_abort_send_read_report(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *op_data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_ABORT_SEND_RR);
    if (op_data->msg_info->need_read_report == 1)
    {
        if ((msg_id == 0xffffffff) || (msg_id == op_data->msg_id))
        {
            op_data->msg_info->need_read_report = KAL_FALSE;
        }
    }
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_update_read_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  read_status     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_update_read_status(U32 msg_id, MMI_BOOL read_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *op_data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_UPDATE_RR_STATUS, read_status);
    if (msg_id == op_data->msg_id)
    {
        op_data->set_read_mark = (U8) read_status;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_compose_settings_inline_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
umms_inline_compose_items_struct *mmi_umms_app_dtmgr_get_compose_settings_inline_item_list(U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mms_nvram_compose_settings_struct *nvram_compose_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag == MMI_TRUE)
    {
        return &g_umms_context->umms_inline_items.compose_items_list;
    }
    nvram_compose_items = (srv_mms_nvram_compose_settings_struct*) srv_mms_get_nvram_compose_settings();
    /* g_umms_context->umms_inline_items.compose_items_list */
    memset(&g_umms_context->umms_inline_items.compose_items_list, 0, sizeof(umms_inline_compose_items_struct));
    gui_itoa(
        (S32) nvram_compose_items->default_slide_time,
        (UI_string_type) g_umms_context->umms_inline_items.compose_items_list.defualt_slide_time_buffer,
        10);
#ifdef __DRM_SUPPORT__
    g_umms_context->umms_inline_items.compose_items_list.add_drm = nvram_compose_items->add_drm;
#endif 

#ifdef __MMI_MMS_SIGNATURE__
    /* g_umms_context->compose_signature_remove_objects_done = E_OFF; */
    g_umms_context->umms_inline_items.compose_items_list.signature_flag = 0;
    g_umms_context->umms_inline_items.compose_items_list.auto_signature = nvram_compose_items->auto_signature;

    mmi_ucs2ncpy(
        (S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_content,
        (S8*) nvram_compose_items->auto_signature_content,
        (128 /* MMA_MAX_EXTERNAL_FILE_PATH_LEN */ + 1) * ENCODING_LENGTH);

#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    mmi_ucs2ncpy(
        (S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file,
        (S8*) nvram_compose_items->auto_signature_image_file,
        (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
    mmi_ucs2ncpy(
        (S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file,
        (S8*) nvram_compose_items->auto_signature_video_file,
        (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    mmi_ucs2ncpy(
        (S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file,
        (S8*) nvram_compose_items->auto_signature_audio_file,
        (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
#endif /* __MMI_MMS_SIGNATURE__ */ 

#ifdef __MMI_MMS_BEST_PAGE_UISETTING_OPTION_SUPPORT__
    g_umms_context->umms_inline_items.compose_items_list.best_page_duration = nvram_compose_items->best_page_duration;
#endif 
    g_umms_context->umms_inline_items.compose_items_list.creation_mode = nvram_compose_items->creation_mode;
    g_umms_context->umms_inline_items.compose_items_list.image_resize_option = nvram_compose_items->image_resize_option;
#ifdef __LAYOUT_SUPPORT__
    g_umms_context->umms_inline_items.compose_items_list.layout = nvram_compose_items->layout;
#endif 
    gui_itoa(
        nvram_compose_items->max_no_pages,
        (UI_string_type) g_umms_context->umms_inline_items.compose_items_list.max_num_pages_buffer,
        10);

    return &g_umms_context->umms_inline_items.compose_items_list;

}

/* no need of flag just to get the current settings */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_current_compose_settings_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
umms_inline_compose_items_struct *mmi_umms_app_dtmgr_get_current_compose_settings_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_umms_context->umms_inline_items.compose_items_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_sending_settings_inline_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
umms_inline_sending_items_struct *mmi_umms_app_dtmgr_get_sending_settings_inline_item_list(U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_nvram_sending_settings_struct *nvram_sending_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag == MMI_TRUE)
    {
        return &g_umms_context->umms_inline_items.sending_items_list;
    }
    nvram_sending_items = (srv_mms_nvram_sending_settings_struct*) srv_mms_get_nvram_sending_settings();
    memset(&g_umms_context->umms_inline_items.sending_items_list, 0, sizeof(umms_inline_sending_items_struct));
    gui_itoa(
        (S32) nvram_sending_items->deadline_for_reply,
        (UI_string_type) g_umms_context->umms_inline_items.sending_items_list.deadline_for_reply_buffer,
        10);
    g_umms_context->umms_inline_items.sending_items_list.delivery_report = (S32) nvram_sending_items->delivery_report;
    g_umms_context->umms_inline_items.sending_items_list.delivery_time = (S32) nvram_sending_items->delivery_time;
    g_umms_context->umms_inline_items.sending_items_list.hide_sender = (S32) nvram_sending_items->hide_sender;
    g_umms_context->umms_inline_items.sending_items_list.priority = (S32) nvram_sending_items->priority;
    g_umms_context->umms_inline_items.sending_items_list.read_report = (S32) nvram_sending_items->read_report;
    g_umms_context->umms_inline_items.sending_items_list.reply_charging = (S32) nvram_sending_items->reply_charging;
    g_umms_context->umms_inline_items.sending_items_list.request_type = (S32) nvram_sending_items->request_type;

    g_umms_context->umms_inline_items.sending_items_list.send_and_save = (S32) nvram_sending_items->send_and_save;

    g_umms_context->umms_inline_items.sending_items_list.validity_period = (S32) nvram_sending_items->validity_period;

#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
    g_umms_context->umms_inline_items.sending_items_list.size = (S32) nvram_sending_items->size;
#else /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 
    gui_itoa(
        (S32) nvram_sending_items->size,
        (UI_string_type) g_umms_context->umms_inline_items.sending_items_list.reply_msg_size_buffer,
        10);
#endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 

    return &g_umms_context->umms_inline_items.sending_items_list;

}

/* no need of flag just to get the current settings */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_current_sending_settings_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
umms_inline_sending_items_struct *mmi_umms_app_dtmgr_get_current_sending_settings_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_umms_context->umms_inline_items.sending_items_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_retrieval_settings_inline_item_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
umms_inline_retrieval_items_struct *mmi_umms_app_dtmgr_get_retrieval_settings_inline_item_list(U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mms_nvram_retrieval_settings_struct *nvram_retrieval_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag == MMI_TRUE)
    {
        return &g_umms_context->umms_inline_items.retrieval_items_list;
    }
    nvram_retrieval_items = (srv_mms_nvram_retrieval_settings_struct*) srv_mms_get_nvram_retrieval_settings();
    memset(&g_umms_context->umms_inline_items.retrieval_items_list, 0, sizeof(umms_inline_retrieval_items_struct));
    g_umms_context->umms_inline_items.retrieval_items_list.advertisement_filter =
        (S32) nvram_retrieval_items->advertisement_filter;
    g_umms_context->umms_inline_items.retrieval_items_list.anonymous_filter =
        (S32) nvram_retrieval_items->anonymous_filter;
    g_umms_context->umms_inline_items.retrieval_items_list.delivery_report =
        (S32) nvram_retrieval_items->delivery_report;
#if defined(__MMI_OP12_MMS_SUPPORT_SETTINGS__)
    g_umms_context->umms_inline_items.retrieval_items_list.home_network = (S32) nvram_retrieval_items->home_network;
#else 
    g_umms_context->umms_inline_items.retrieval_items_list.home_network = (S32) nvram_retrieval_items->home_network - 1;
#endif 
    g_umms_context->umms_inline_items.retrieval_items_list.read_report = (S32) nvram_retrieval_items->read_report;
    g_umms_context->umms_inline_items.retrieval_items_list.roaming = (S32) nvram_retrieval_items->roaming;

    return &g_umms_context->umms_inline_items.retrieval_items_list;
}

/* no need of flag just to get the current settings */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_current_retrieval_settings_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
umms_inline_retrieval_items_struct *mmi_umms_app_dtmgr_get_current_retrieval_settings_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_umms_context->umms_inline_items.retrieval_items_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_inline_retrieval_settings_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_inline_retrieval_settings_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_nvram_retrieval_settings_struct *nvram_retrieval_settings;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_retrieval_settings = (srv_mms_nvram_retrieval_settings_struct*) srv_mms_get_nvram_retrieval_settings();

    nvram_retrieval_settings->advertisement_filter =
        (U8) g_umms_context->umms_inline_items.retrieval_items_list.advertisement_filter;
    nvram_retrieval_settings->anonymous_filter =
        (U8) g_umms_context->umms_inline_items.retrieval_items_list.anonymous_filter;
    nvram_retrieval_settings->delivery_report =
        (U8) g_umms_context->umms_inline_items.retrieval_items_list.delivery_report;
#if defined(__MMI_OP12_MMS_SUPPORT_SETTINGS__)
    nvram_retrieval_settings->home_network = (U8) g_umms_context->umms_inline_items.retrieval_items_list.home_network;
#else /* defined(__MMI_OP12_MMS_SUPPORT_SETTINGS__) */ /* defined(__MMI_MMS_2_RETRIVAL_MODE_SETTING__) || defined(__MMI_OP12_MMS_SUPPORT_SETTINGS__) */
    if (nvram_retrieval_settings->home_network !=
        g_umms_context->umms_inline_items.retrieval_items_list.home_network + 1)
    {
        if (E_HOME_NOETWORK_RETRIEVAL_IMMEDAITE == nvram_retrieval_settings->home_network)
        {
            if (E_HOME_NOETWORK_RETRIEVAL_DEFFERED ==
                g_umms_context->umms_inline_items.retrieval_items_list.home_network + 1)
            {
                mmi_umms_app_app_ui_plug_in_network_changed_from_immd_to_deffered_callback();
            }
        }
    }
    /* write code for settings */
    nvram_retrieval_settings->home_network =
        (U8) g_umms_context->umms_inline_items.retrieval_items_list.home_network + 1;
#endif /* defined(__MMI_OP12_MMS_SUPPORT_SETTINGS__) */ 
    nvram_retrieval_settings->read_report = (U8) g_umms_context->umms_inline_items.retrieval_items_list.read_report;
    nvram_retrieval_settings->roaming = (U8) g_umms_context->umms_inline_items.retrieval_items_list.roaming;

    srv_mms_write_nvram_retrieval_settings();
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_dtmgr_send_set_settings_to_service(NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_inline_compose_settings_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_inline_compose_settings_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 temp_max_no_pages = 0;
    srv_mms_nvram_compose_settings_struct *nvram_compose_settings;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_compose_settings = (srv_mms_nvram_compose_settings_struct*) srv_mms_get_nvram_compose_settings();

    temp_max_no_pages = gui_atoi((UI_string_type) g_umms_context->umms_inline_items.compose_items_list.max_num_pages_buffer);
    nvram_compose_settings->default_slide_time =
        (U32) gui_atoi((UI_string_type) g_umms_context->umms_inline_items.compose_items_list.defualt_slide_time_buffer);
#ifdef __MMI_MMS_SIGNATURE__
    /* g_umms_context->compose_signature_remove_objects_done = E_OFF; */
    nvram_compose_settings->auto_signature = g_umms_context->umms_inline_items.compose_items_list.auto_signature;
#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    if (mmi_ucs2cmp(
            (S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
    {
        mmi_ucs2cpy(
            (S8*) nvram_compose_settings->auto_signature_image_file,
            (S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_image_file);
    }
    else
    {
        memset(
            nvram_compose_settings->auto_signature_image_file,
            0,
            (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
    }
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
    if (mmi_ucs2cmp(
            (S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
    {
        mmi_ucs2cpy(
            (S8*) nvram_compose_settings->auto_signature_video_file,
            (S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_video_file);
    }
    else
    {
        memset(
            nvram_compose_settings->auto_signature_video_file,
            0,
            (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
    }
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    if (mmi_ucs2cmp(
            (S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file,
            (S8*) GetString(STR_ID_UMMS_SIGNATURE_SELECT_MEDIA)) != 0)
    {
        mmi_ucs2cpy(
            (S8*) nvram_compose_settings->auto_signature_audio_file,
            (S8*) g_umms_context->umms_inline_items.compose_items_list.auto_signature_audio_file);

    }
    else
    {
        memset(
            nvram_compose_settings->auto_signature_audio_file,
            0,
            (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
    }
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 

    mmi_ucs2cpy(
        (PS8) nvram_compose_settings->auto_signature_content,
        (PS8) g_umms_context->umms_inline_items.compose_items_list.auto_signature_content);

#endif /* __MMI_MMS_SIGNATURE__ */ 
#ifdef __MMI_MMS_BEST_PAGE_UISETTING_OPTION_SUPPORT__
    nvram_compose_settings->best_page_duration =
        g_umms_context->umms_inline_items.compose_items_list.best_page_duration;
#endif /* __MMI_MMS_BEST_PAGE_UISETTING_OPTION_SUPPORT__ */ 
    nvram_compose_settings->creation_mode = g_umms_context->umms_inline_items.compose_items_list.creation_mode;
    nvram_compose_settings->image_resize_option =
        g_umms_context->umms_inline_items.compose_items_list.image_resize_option;
#ifdef __DRM_SUPPORT__
    nvram_compose_settings->add_drm = g_umms_context->umms_inline_items.compose_items_list.add_drm;
#endif 
    nvram_compose_settings->layout = g_umms_context->umms_inline_items.compose_items_list.layout;
    nvram_compose_settings->max_no_pages = (U8) temp_max_no_pages;

    srv_mms_write_nvram_compose_settings();
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_dtmgr_send_set_settings_to_service(NULL);
#endif/*ndef __RAJKAMAL_SLIM__*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_inline_sending_settings_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_inline_sending_settings_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mms_nvram_sending_settings_struct *nvram_sending_settings;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_sending_settings = (srv_mms_nvram_sending_settings_struct*) srv_mms_get_nvram_sending_settings();

    nvram_sending_settings->delivery_report = (U8) g_umms_context->umms_inline_items.sending_items_list.delivery_report;
    nvram_sending_settings->delivery_time = (U8) g_umms_context->umms_inline_items.sending_items_list.delivery_time;
    nvram_sending_settings->hide_sender = (U8) g_umms_context->umms_inline_items.sending_items_list.hide_sender;
    nvram_sending_settings->priority = (U8) g_umms_context->umms_inline_items.sending_items_list.priority;
    nvram_sending_settings->read_report = (U8) g_umms_context->umms_inline_items.sending_items_list.read_report;
    nvram_sending_settings->reply_charging = (U8) g_umms_context->umms_inline_items.sending_items_list.reply_charging;
    nvram_sending_settings->request_type = (U8) g_umms_context->umms_inline_items.sending_items_list.request_type;
    nvram_sending_settings->validity_period = (U8) g_umms_context->umms_inline_items.sending_items_list.validity_period;

    nvram_sending_settings->send_and_save = (U32) g_umms_context->umms_inline_items.sending_items_list.send_and_save;

    nvram_sending_settings->deadline_for_reply =
        (U32) gui_atoi((UI_string_type) g_umms_context->umms_inline_items.sending_items_list.deadline_for_reply_buffer);

#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
    nvram_sending_settings->size = (U32) g_umms_context->umms_inline_items.sending_items_list.size;
#else /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 
    nvram_sending_settings->size =
        (U32) gui_atoi((UI_string_type) g_umms_context->umms_inline_items.sending_items_list.reply_msg_size_buffer);
#endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 

    srv_mms_write_nvram_sending_settings();
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mmi_umms_app_dtmgr_send_set_settings_to_service(NULL);
#endif
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_send_set_settings_to_service
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_dtmgr_send_set_settings_to_service(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mma_set_settings_req_struct set_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&set_setting, 0, sizeof(srv_mms_mma_set_settings_req_struct));
    set_setting.user_data = NULL;
    set_setting.app_id = MMA_APP_ID_SETTING;
    /* Create one setting Response Event and broadcast */
    set_setting.call_back = mmi_umms_app_core_set_setting_rsp_cb;
    srv_mms_set_setting((void*)&set_setting);
	return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_set_setting_rsp_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         [?]
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_set_setting_rsp_cb(srv_mms_result_enum result, void *rsp_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (result == MMI_TRUE)
    {
        return;
    }
    /* if ((mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS) && (GRP_ID_UMMS_LIST_SETTINGS == mmi_umms_dtmgr_get_group_id()))
       {
       if (response_result->result == MMA_RESULT_OK)
       {
       mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);
       mmi_umms_app_if_show_display_popup_screen();
       
       }
       else
       {
       mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
       mmi_umms_app_if_show_display_popup_screen();
       
       }
       } */
	#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    srv_mms_send_events(EVT_ID_SRV_MMS_DEINIT, NULL);
    #endif
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_change_in_compose_signature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_change_in_compose_signature(U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtmgr_sign_ui_handle->g_compose_signature_done = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_change_in_compose_signature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_umms_app_dtmgr_get_change_in_compose_signature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return dtmgr_sign_ui_handle->g_compose_signature_done;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_flag_for_signature_remove_objects
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_flag_for_signature_remove_objects(U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtmgr_sign_ui_handle->compose_signature_remove_objects_done = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_flag_for_signature_remove_objects
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_umms_app_dtmgr_get_flag_for_signature_remove_objects(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return dtmgr_sign_ui_handle->compose_signature_remove_objects_done;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_current_object_hilighted_in_signature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_current_object_hilighted_in_signature(U16 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtmgr_sign_ui_handle->g_signature_current_highlighted = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_current_object_hilighted_in_signature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_umms_app_dtmgr_get_current_object_hilighted_in_signature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return dtmgr_sign_ui_handle->g_signature_current_highlighted;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_recieve_filters_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_set_recieve_filters_done(U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dtmgr_recieve_filter_done = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_recieve_filters_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_umms_app_dtmgr_get_recieve_filters_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_dtmgr_recieve_filter_done;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_sim_validation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_sim_validation(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
#endif /* 0 */ 
    g_active_sim = srv_mms_get_sim_valid_flag();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_get_active_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_umms_app_dtmgr_get_active_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_active_sim;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_check_save_object_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_dtmgr_check_save_object_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *image_info = NULL;
    mma_mms_object_struct *video_info = NULL;
    mma_mms_object_struct *audio_info = NULL;
    mma_mms_object_struct *text_info = NULL;
    mma_mms_attachment_info_struct *attachment_list = NULL;
    U32 attachment_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_viewer_get_objects_from_current_slide(&image_info, &video_info, &audio_info, &text_info);
    srv_mms_viewer_get_attachment_list(&attachment_list, &attachment_count);

#ifdef __MMI_MMS_POSTCARD__
    if (MMA_MSG_TYPE_POSTCARD == srv_mms_get_message_type())
    {
        if (NULL == image_info)
        {
            return MMI_FALSE;
        }
    }
    else
#endif /* __MMI_MMS_POSTCARD__ */ 

    {
        if ((NULL == attachment_list) && (NULL == image_info) && (NULL == audio_info) && (NULL == video_info) &&
            (NULL == text_info))
        {

            return MMI_FALSE;
        }
    }
    return MMI_TRUE;

}

#ifdef __MMI_MMS_IMAGE_VIEW_ENHANCEMENT__

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_start_image_decoder
 * DESCRIPTION
 *  returns utf text length
 * PARAMETERS
 *  media       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
wgui_mv_image_decode_status_enum mmi_umms_app_dtmgr_start_image_decoder(U16 *src_path, U32 width_orig, U32 height_orig, U32 width_final, U32 height_final, U16 slide_id)
{
	if(g_umms_viewer_image_decoder_struct.slide_id == slide_id)
	{
		if(g_umms_viewer_image_decoder_struct.last_decoded_result == WGUI_MV_IMAGE_DECODED_SUCCESS)
		{
			return WGUI_MV_IMAGE_ALREADY_DECODED;
		}
		else if(g_umms_viewer_image_decoder_struct.last_decoded_result == WGUI_MV_IMAGE_DECODED_FAILED)
		{
			return WGUI_MV_IMAGE_DECODED_FAILED;
		}
	}
	memset(&g_umms_viewer_image_decoder_struct, 0, sizeof(mmi_umms_app_dtmgr_image_decode_struct));
	MMI_ASSERT(src_path && width_orig && width_final && height_final && height_orig);
	g_umms_viewer_image_decoder_struct.src_path = src_path;
	g_umms_viewer_image_decoder_struct.width_orig = width_orig;
	g_umms_viewer_image_decoder_struct.height_orig = height_orig;
	g_umms_viewer_image_decoder_struct.width_final = width_final;
	g_umms_viewer_image_decoder_struct.height_final = height_final;
	g_umms_viewer_image_decoder_struct.slide_id = slide_id;
	return (mmi_umms_app_dtmgr_decode_image_for_viewer(g_umms_viewer_image_decoder_struct.src_path));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_decode_image_for_viewer
 * DESCRIPTION
 *  returns utf text length
 * PARAMETERS
 *  media       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
wgui_mv_image_decode_status_enum mmi_umms_app_dtmgr_decode_image_for_viewer(U16 *file_path)
{
	    S32 gdi_result = GDI_FAILED;
        S32 bytesperpx;

		bytesperpx = (gdi_layer_get_bit_per_pixel()) >> 3;

        media_get_ext_buffer(
			MOD_MMI, 
			(void **)&(g_umms_viewer_image_decoder_struct.mms_image_buff),
			bytesperpx*(g_umms_viewer_image_decoder_struct.width_orig+1) * (g_umms_viewer_image_decoder_struct.height_orig+1));
        
        if(g_umms_viewer_image_decoder_struct.mms_image_buff !=NULL)
        {
			gdi_result = gdi_layer_create_cf_using_outside_memory(
							bytesperpx,
							MMI_CONTENT_X,
							0,
							g_umms_viewer_image_decoder_struct.width_orig + 1,
							g_umms_viewer_image_decoder_struct.height_orig + 1,
							&(g_umms_viewer_image_decoder_struct.mms_gdi_handle),
							g_umms_viewer_image_decoder_struct.mms_image_buff,
							(g_umms_viewer_image_decoder_struct.width_orig + 1) * (g_umms_viewer_image_decoder_struct.height_orig + 1) * bytesperpx);
        }
		else
		{
			mmi_umms_app_dtmgr_gdi_close_decoder(WGUI_MV_IMAGE_DECODED_FAILED, NULL, MMI_FALSE);
			return WGUI_MV_IMAGE_DECODED_FAILED;
		}
        if(gdi_result>=0)
		{
			g_umms_viewer_image_decoder_struct.mms_gdi_dec_handle = gdi_imgdec_nb_draw_resized_file(
									   g_umms_viewer_image_decoder_struct.mms_gdi_handle,
									   0,
									   0,
									   g_umms_viewer_image_decoder_struct.width_orig,
									   g_umms_viewer_image_decoder_struct.height_orig,
									  (U8*)file_path,
									   (gdi_imgdec_nb_done_callback_funcptr)mmi_umms_app_dtmgr_gdi_decode_done_cb);
        }
        else
		{
			mmi_umms_app_dtmgr_gdi_close_decoder(WGUI_MV_IMAGE_DECODED_FAILED, NULL, MMI_FALSE);
			return WGUI_MV_IMAGE_DECODED_FAILED;
		}
        if(g_umms_viewer_image_decoder_struct.mms_gdi_dec_handle < 0)
        {
			mmi_umms_app_dtmgr_gdi_close_decoder(WGUI_MV_IMAGE_DECODED_FAILED, NULL, MMI_FALSE); 
			return WGUI_MV_IMAGE_DECODED_FAILED;
	    }
		return WGUI_MV_IMAGE_DECODED_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_resize_and_encode_image
 * DESCRIPTION
 *  returns utf text length
 * PARAMETERS
 *  media       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_gdi_decode_done_cb(GDI_RESULT result,gdi_handle handle)
{
	S32 gdi_result = GDI_FAILED;
    if(result >= 0 && g_umms_viewer_image_decoder_struct.mms_gdi_dec_handle == handle)
    {
		mmi_umms_app_dtmgr_resize_and_encode_image(); 		 
    }
    else
    {
		mmi_umms_app_dtmgr_gdi_close_decoder(WGUI_MV_IMAGE_DECODED_FAILED, NULL, MMI_TRUE);
     }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_resize_and_encode_image
 * DESCRIPTION
 *  returns utf text length
 * PARAMETERS
 *  media       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_resize_and_encode_image(void)
{
	U8 *buf_ptr;
	S32 gdi_result = GDI_FAILED;
	gdi_handle mms_gdi_handle;
	S32 bytesperpx;
	int buf_size =  buf_size = (g_umms_viewer_image_decoder_struct.width_final * g_umms_viewer_image_decoder_struct.height_final * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
	bytesperpx = (gdi_layer_get_bit_per_pixel()) >> 3;
    buf_size = ((buf_size + 3) / 4) * 4;
	media_get_ext_buffer(MOD_MMI, (void **)&buf_ptr, buf_size);
	gdi_result = gdi_layer_create_cf_using_outside_memory(
							bytesperpx,
							MMI_CONTENT_X,
							0,
							g_umms_viewer_image_decoder_struct.width_final,
							g_umms_viewer_image_decoder_struct.height_final,
							&mms_gdi_handle,
							buf_ptr,
							(g_umms_viewer_image_decoder_struct.width_final) * (g_umms_viewer_image_decoder_struct.height_final) * bytesperpx);
	if(gdi_result < 0)
	{
		media_free_ext_buffer(MOD_MMI, (void **)&buf_ptr);
		mmi_umms_app_dtmgr_gdi_close_decoder(WGUI_MV_IMAGE_DECODED_FAILED, NULL, MMI_TRUE);
		return;
	}
	gdi_layer_push_and_set_active(mms_gdi_handle);
	gdi_result = gdi_bitblt_resized_with_resizer(
                g_umms_viewer_image_decoder_struct.mms_gdi_handle,
                0,
                0,
                g_umms_viewer_image_decoder_struct.width_orig,
                g_umms_viewer_image_decoder_struct.height_orig,
                0,
                0,
                g_umms_viewer_image_decoder_struct.width_final,
                g_umms_viewer_image_decoder_struct.height_final,
                GDI_RESIZER_SW_QUALITY_HIGH);
	if(gdi_result < 0)
	{
		gdi_layer_pop_and_restore_active();
		mmi_umms_app_dtmgr_gdi_close_decoder(WGUI_MV_IMAGE_DECODED_FAILED, NULL, MMI_TRUE);
		gdi_layer_free(mms_gdi_handle);
		media_free_ext_buffer(MOD_MMI, (void **)&buf_ptr);
		return;
	}
	gdi_layer_pop_and_restore_active();
	gdi_result = mmi_umms_app_dtmgr_encode_file_for_viewer(bytesperpx, mms_gdi_handle);
	gdi_layer_free(mms_gdi_handle);
	media_free_ext_buffer(MOD_MMI, (void **)&buf_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_encode_file_for_viewer
 * DESCRIPTION
 *  returns utf text length
 * PARAMETERS
 *  media       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_app_dtmgr_encode_file_for_viewer(S32 cf, S32 layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	PU16 decode_file_path = NULL;
	S32 gdi_result = GDI_FAILED;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	decode_file_path = mmi_umms_app_dtmgr_gdi_create_file_path();
	if(decode_file_path)
	{
		gdi_result = gdi_image_encode_layer_to_jpeg(layer_handle, (PS8)decode_file_path);
		if(gdi_result == GDI_SUCCEED)
		{
			mmi_umms_app_dtmgr_gdi_close_decoder(WGUI_MV_IMAGE_DECODED_SUCCESS, decode_file_path, MMI_TRUE);
		}
		else
		{
			mmi_umms_app_dtmgr_gdi_close_decoder(WGUI_MV_IMAGE_DECODED_FAILED, decode_file_path, MMI_TRUE);
		}
		srv_mms_mem_mgr_app_adm_free(decode_file_path);
	}
	else
	{
		mmi_umms_app_dtmgr_gdi_close_decoder(WGUI_MV_IMAGE_DECODED_FAILED, decode_file_path, MMI_TRUE);
	}
	decode_file_path = NULL;
	return gdi_result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_gdi_create_file_path
 * DESCRIPTION
 *  returns utf text length
 * PARAMETERS
 *  media       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 * mmi_umms_app_dtmgr_gdi_create_file_path(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	PU16 decode_file_path = NULL;
	S32 file_handle, res;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	decode_file_path = (PU16)srv_mms_mem_mgr_app_adm_alloc((SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
	memset(decode_file_path, 0, (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
	kal_wsprintf(decode_file_path, "%c:\\%s",SRV_FMGR_PUBLIC_DRV, MMS_DECODED_FOLDER_NAME);
	file_handle = FS_Open(decode_file_path, FS_READ_ONLY);
    if (file_handle > 0)
    {
        /* put traces */
        FS_Close(file_handle);
    }
    else
    {
        FS_CreateDir(decode_file_path);
        FS_SetAttributes(decode_file_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }
	memset(decode_file_path, 0, (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
	kal_wsprintf(decode_file_path, "%c:\\%s\\%s",SRV_FMGR_PUBLIC_DRV, MMS_DECODED_FOLDER_NAME, MMS_DECODED_FILE_NAME);
	file_handle = FS_Open(decode_file_path, FS_READ_ONLY);
	FS_Close(file_handle);
	if(file_handle > 0)
	{
		res = FS_Delete(decode_file_path);
	}
	return decode_file_path;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_gdi_close_decoder
 * DESCRIPTION
 *  returns utf text length
 * PARAMETERS
 *  media       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_dtmgr_gdi_close_decoder(wgui_mv_image_decode_status_enum result, U16 *file_path, MMI_BOOL notify_cat)
{
	U16 *decode_file_path  =NULL;
	g_umms_viewer_image_decoder_struct.last_decoded_result = result;
	if(g_umms_viewer_image_decoder_struct.mms_image_buff)
	{
		media_free_ext_buffer(MOD_MMI, (void **)&g_umms_viewer_image_decoder_struct.mms_image_buff);
		g_umms_viewer_image_decoder_struct.mms_image_buff = NULL;
	}
	if(g_umms_viewer_image_decoder_struct.mms_gdi_handle)
	{
		gdi_layer_free(g_umms_viewer_image_decoder_struct.mms_gdi_handle);
		g_umms_viewer_image_decoder_struct.mms_gdi_handle = GDI_NULL_HANDLE;
	}
	if(notify_cat)
	{
	if(result)
	{
		Category630ImageDecodeDoneNotify (WGUI_MV_IMAGE_DECODED_SUCCESS , file_path);
	}
	else
	{
		/*call category with failure*/
		Category630ImageDecodeDoneNotify (WGUI_MV_IMAGE_DECODED_FAILED , file_path);
	}
}
	else
	{
		decode_file_path = mmi_umms_app_dtmgr_gdi_create_file_path();
		srv_mms_mem_mgr_app_adm_free(decode_file_path);
	}
}
void mmi_umms_app_dtmgr_stop_image_decode()
  {
    g_umms_viewer_image_decoder_struct.last_decoded_result == WGUI_MV_IMAGE_DECODED_FAILED_INTERRUPT ;
	mmi_umms_app_dtmgr_gdi_close_decoder(WGUI_MV_IMAGE_DECODED_FAILED, NULL, MMI_FALSE);
    gdi_imgdec_nb_stop(g_umms_viewer_image_decoder_struct.mms_gdi_dec_handle);

  }
#endif
#endif /* __MMI_MMS_2__ */ 

