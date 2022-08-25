/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    PictBridgeHandler.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for PictBridge appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifdef __MMI_PICT_BRIDGE_SUPPORT__

#ifdef __MTK_TARGET__
#include "Usbimage_drv.h"
#endif

#include "PictBridgeDef.h"
#include "PictBridgeProt.h"
#include "PictBridgeStruct.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#endif

/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "string.h"
#include "stack_config.h"
#include "fs_type.h"
#include "fs_func.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "kal_internal_api.h"
#include "Pictcuigprot.h"
#include "mmi_rp_srv_pict_bridge_def.h"
#include "Unicodexdcl.h"
#include "drm_def.h"
#include "fs_errcode.h"
/* auto add by kw_check end */

/*
 * Global Variable
 */
extern pict_bridge_context_struct g_pict_bridge_context;
extern pict_bridge_setting_struct g_pict_bridge_setting;
extern pict_bridge_xml_struct g_pict_bridge_xml;
extern mmi_id g_pict_gid;

/*
 * Local Variable
 */
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
#ifdef __MTK_TARGET__
__align(2)
#endif
static S8 image_file_path[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
#endif /* defined __MMI_FMGR_MULTI_SELECT_SUPPORT__ */

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
static S8 ansii_file_path[SRV_FMGR_PATH_MAX_LEN + 1];
#endif


#ifdef __MTK_TARGET__

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_init
 * DESCRIPTION
 *  PictBridge initialization function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_protocol_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_pict_dps_discovery_ind, MSG_ID_USB_MMI_DPS_DISCOVERY_IND);
    SetProtocolEventHandler(mmi_pict_receive_dps_operation_ind, MSG_ID_USB_MMI_DPS_HRESPONSE_IND);
    SetProtocolEventHandler(mmi_pict_receive_dps_event_ind, MSG_ID_USB_MMI_DPS_HREQUEST_IND);
    SetProtocolEventHandler(mmi_pict_send_dps_operation_rsp, MSG_ID_USB_MMI_DPS_DREQUEST_CONF);
    SetProtocolEventHandler(mmi_pict_send_dps_event_rsp, MSG_ID_USB_MMI_DPS_DRESPONSE_CONF);

    SetProtocolEventHandler(mmi_pict_connect_to_pc_ind, MSG_ID_USB_MMI_PTP_CONNECT_TO_PC_IND);
    SetProtocolEventHandler(mmi_pict_open_file_fail_ind, MSG_ID_USB_MMI_PTP_OPEN_FILE_FAIL_IND);
    SetProtocolEventHandler(mmi_pict_host_reset, MSG_ID_USB_MMI_PTP_HOST_RESET_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_send_dps_operation_rsp
 * DESCRIPTION
 *  Response from USB task of DPS operation to the printer
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_send_dps_operation_rsp(void *info)
{

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_send_dps_operation_req
 * DESCRIPTION
 *  Send DPS operation to the printer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_send_dps_operation_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usb_image_xml_struct *dps_operation_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_context.next_operation_request == NULL)
    {
        return;
    }

    /* prepare XML package */
    (*g_pict_bridge_context.next_operation_request) ();

    if (g_pict_bridge_context.next_operation_request == mmi_pict_prepare_xml_start_job)
    {
        MMI_ASSERT(strlen(g_pict_bridge_context.xml_operation_cmd) < g_pict_bridge_context.xml_start_job_cmd_size);
    }
    else
    {
        MMI_ASSERT(strlen(g_pict_bridge_context.xml_operation_cmd) < g_pict_bridge_context.xml_operation_cmd_size);
    }

    /* temporarily ignore DPS event from printer after DPS operation is sent */
    ClearProtocolEventHandler(MSG_ID_USB_MMI_DPS_HREQUEST_IND);
    /* ignore the pending message in queue because DPS operation is sent by the user manually */
    ClearProtocolEventHandler(MSG_ID_MMI_PICT_BRIDGE_PENDING_EVENT);

    dps_operation_req = (usb_image_xml_struct*) OslConstructDataPtr(sizeof(usb_image_xml_struct));
    dps_operation_req->xml_address = (U8*) g_pict_bridge_context.xml_operation_cmd;
    dps_operation_req->xml_packet_size = strlen(g_pict_bridge_context.xml_operation_cmd);

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
    mmi_pict_write_xml_data_to_file(dps_operation_req->xml_address, dps_operation_req->xml_packet_size);
#else
    kal_sleep_task(KAL_TICKS_50_MSEC);
#endif
    mmi_frm_send_ilm(MOD_USB,MSG_ID_MMI_USB_DPS_DREQUEST_REQ,(oslParaType*) dps_operation_req,NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_receive_dps_operation_ind
 * DESCRIPTION
 *  Receive DPS operation result from the printer
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_receive_dps_operation_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usb_image_xml_struct *dps_operation_ind;

    FS_HANDLE fs_handle;
    U32 written_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dps_operation_ind = (usb_image_xml_struct*) info;

    /* Continue to wait DPS event from printer */
    SetProtocolEventHandler(mmi_pict_receive_dps_event_ind, MSG_ID_USB_MMI_DPS_HREQUEST_IND);

    fs_handle = FS_Open((U16*) PICT_XML_PATH, FS_CREATE | FS_READ_WRITE);
    FS_Write(fs_handle, (void*) dps_operation_ind->xml_address, dps_operation_ind->xml_packet_size, &written_length);
    FS_Truncate(fs_handle); 
    FS_Close(fs_handle);

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
    mmi_pict_write_xml_data_to_file(dps_operation_ind->xml_address, dps_operation_ind->xml_packet_size);
#else
    kal_sleep_task(KAL_TICKS_50_MSEC);
#endif

    mmi_pict_parse_xml_script();

    mmi_frm_send_ilm(MOD_USB,MSG_ID_MMI_USB_DPS_HRESPONSE_CONF,NULL,NULL);
    //mmi_pict_send_dps_operation_req();
    kal_sleep_task(KAL_TICKS_100_MSEC * 3); /* sleep 300 msec to ensure that no DPS event from printer */

    SetProtocolEventHandler(mmi_pict_proc_pending_message, MSG_ID_MMI_PICT_BRIDGE_PENDING_EVENT);
    mmi_frm_send_ilm(MOD_MMI,MSG_ID_MMI_PICT_BRIDGE_PENDING_EVENT,NULL,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_send_dps_operation_rsp
 * DESCRIPTION
 *  Response from USB task of DPS event result to the printer
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_send_dps_event_rsp(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_context.next_event_request = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_send_dps_event_req
 * DESCRIPTION
 *  Send DPS event result to the printer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_send_dps_event_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usb_image_xml_struct *dps_event_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_context.next_event_request == NULL)
    {
        return;
    }

    /* prepare XML package */
    (*g_pict_bridge_context.next_event_request) ();

    MMI_ASSERT(strlen(g_pict_bridge_context.xml_event_cmd) < g_pict_bridge_context.xml_event_cmd_size);

    dps_event_req = (usb_image_xml_struct*) OslConstructDataPtr(sizeof(usb_image_xml_struct));
    dps_event_req->xml_address = (U8*) g_pict_bridge_context.xml_event_cmd;
    dps_event_req->xml_packet_size = strlen(g_pict_bridge_context.xml_event_cmd);

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
    mmi_pict_write_xml_data_to_file(dps_event_req->xml_address, dps_event_req->xml_packet_size);
#else
    kal_sleep_task(KAL_TICKS_50_MSEC);
#endif
    mmi_frm_send_ilm(MOD_USB,MSG_ID_MMI_USB_DPS_DRESPONSE_REQ,(oslParaType*) dps_event_req,NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_receive_dps_event_ind
 * DESCRIPTION
 *  Receive DPS event from the printer
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_receive_dps_event_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usb_image_xml_struct *dps_event_ind;

    FS_HANDLE fs_handle;
    U32 written_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dps_event_ind = (usb_image_xml_struct*) info;

    fs_handle = FS_Open((U16*) PICT_XML_PATH, FS_CREATE | FS_READ_WRITE);
    FS_Write(fs_handle, (void*) dps_event_ind->xml_address, dps_event_ind->xml_packet_size, &written_length); 
    FS_Truncate(fs_handle);
    FS_Close(fs_handle);

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
    mmi_pict_write_xml_data_to_file(dps_event_ind->xml_address, dps_event_ind->xml_packet_size);
#else
    kal_sleep_task(KAL_TICKS_50_MSEC);
#endif

    mmi_pict_parse_xml_script();

    mmi_frm_send_ilm(MOD_USB,MSG_ID_MMI_USB_DPS_HREQUEST_CONF,NULL,NULL);
    mmi_pict_send_dps_event_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_dps_disconnect_ind
 * DESCRIPTION
 *  DPS disconnect indication from USB application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_dps_disconnect_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_PICT, TRC_MMI_PICT_BRIDGE_USB_REMOVE);

    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_PRINT); /* hide print icon */
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_PRINT_FAIL); /* hide print error icon */
    wgui_status_icon_bar_update();

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    
    memset(&g_pict_bridge_context, 0, sizeof(pict_bridge_context_struct));
    memset(&g_pict_bridge_xml, 0, sizeof(pict_bridge_xml_struct));
    memset(&g_pict_bridge_setting, 0, sizeof(g_pict_bridge_setting));

    cui_pict_send_result_to_parent(CUI_PICT_RESULT_CANCEL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_dps_discovery_ind
 * DESCRIPTION
 *  DPS discovery indication from USB task
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_dps_discovery_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usb_mmi_dps_discovery_ind_struct *dps_discovery_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dps_discovery_ind = (usb_mmi_dps_discovery_ind_struct *) info;

    g_pict_bridge_context.xml_operation_cmd = (S8*) dps_discovery_ind->dps_xml_request_address;
    g_pict_bridge_context.xml_event_cmd = (S8*) dps_discovery_ind->dps_xml_response_address;

    g_pict_bridge_context.xml_operation_cmd_size = dps_discovery_ind->dps_xml_request_buffer_size;
    g_pict_bridge_context.xml_event_cmd_size = dps_discovery_ind->dps_xml_response_buffer_size;

    g_pict_bridge_context.xml_start_job_cmd_size = dps_discovery_ind->dps_xml_start_job_buffer_size;

    if (g_pict_bridge_context.xml_operation_cmd == NULL || g_pict_bridge_context.xml_event_cmd == NULL)
    {
        MMI_ASSERT(0);
    }

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
    mmi_pict_delete_xml_data_file();
#endif

#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
    mmi_pict_entry_printer_connected();
#endif

    g_pict_bridge_context.next_operation_request = mmi_pict_prepare_xml_configure_print_service;

    mmi_pict_send_dps_operation_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_proc_pending_message
 * DESCRIPTION
 *  Send a message to MMI to pending the next operation because there might be an incoming event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_proc_pending_message(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_MMI_PICT_BRIDGE_PENDING_EVENT);
    /* 
     * To get capability of the printer, MMI needs to continuously send DREQUEST to the printer.
     * To prevent from an incoming HREQUEST after HRESPONSE, MMI sends a message to itself.
     */
    mmi_pict_send_dps_operation_req();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_connect_to_pc_ind
 * DESCRIPTION
 *  PC connection indication from USB task
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_connect_to_pc_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pict_entry_error_connection_to_pc();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_open_file_fail_ind
 * DESCRIPTION
 *  Open file failure indication from USB task
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_open_file_fail_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_context.printing != PICT_PRINTING_NONE)
    {
        mmi_pict_entry_print_done(MMI_FALSE, STR_ID_PICT_INCOMPATIBLE_FILE);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_host_reset
 * DESCRIPTION
 *  USB host reset
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_host_reset(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_pict_is_dps_device_present())
    {
        mmi_pict_dps_disconnect_ind();
        //mmi_pict_host_reset_popop();

        mmi_frm_send_ilm(MOD_USB,MSG_ID_MMI_USB_PTP_HOST_RESET_CNF,NULL,NULL);
    }
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_drm_consume_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_drm_consume_callback(kal_int32 result, kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_return_print_file_handle_with_filename
 * DESCRIPTION
 *  Return image file hander to USB task for printing
 * PARAMETERS
 *  obj_handle      [IN]
 *  filename        [OUT]
 *  max_length      [IN/OUT]
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
FS_HANDLE mmi_pict_return_print_file_handle_with_filename(kal_uint32 obj_handle,  kal_uint16 *filename, kal_uint16 *max_filename_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle = NULL;

#ifdef __DRM_SUPPORT__
    S32 right_id;
#endif

#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__

    U8 i, j;
    U16 file_id_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(image_file_path, (S8*) g_pict_bridge_context.printing_filepath);
    srv_fmgr_path_remove_filename((WCHAR*)image_file_path);

    if (g_pict_bridge_setting.page_format == 1) /* multiple */
    {
        for (i = 0; i < g_pict_bridge_context.multi_file_select; i++)
        {
            for (j = 1; ; j++)
            {
                file_id_count++;
                if ((j == 1 && g_pict_bridge_setting.layout == 0) ||
                    (j == 2 && g_pict_bridge_setting.layout == 1) ||
                    (j == 4 && g_pict_bridge_setting.layout == 2))
                {
                    break;
                }
            }

            if (file_id_count >= (U16) obj_handle)
            {
                break;
            }
        }
    }
    else /* standard or index */
    {
        i = (U8) (obj_handle - 1);
    }

    /* drm consume */
#ifdef __DRM_SUPPORT__
    if ((g_pict_bridge_context.error_index == i) || 
        (((g_pict_bridge_context.error_index + 1) == i) && (i != 1)))
    {
        g_pict_bridge_context.error_index = 0;
    }
    else
    {
        fs_handle = DRM_open_file((U16*)g_pict_bridge_context.printing_filepath, FS_READ_ONLY, DRM_PERMISSION_PRINT);
    if (g_pict_bridge_context.multi_file_consume[i-1] == 0)
    {
        right_id = DRM_consume_rights(fs_handle, DRM_PERMISSION_PRINT, mmi_pict_drm_consume_callback);
        DRM_stop_consume(right_id);
        g_pict_bridge_context.multi_file_consume[i-1] = 1;
    }
        DRM_close_file(fs_handle);
    }

#endif
    g_pict_bridge_context.curr_index = i;
    mmi_ucs2cat(image_file_path, (S8*) g_pict_bridge_context.multi_file_path[i]);
    mmi_ucs2cpy((S8*) g_pict_bridge_context.printing_filepath, image_file_path);
    
#ifdef __DRM_SUPPORT__
    fs_handle = DRM_open_file((U16*) image_file_path, FS_READ_ONLY, DRM_PERMISSION_PRINT);
#else /* __DRM_SUPPORT__ */
    fs_handle = FS_Open((U16*) image_file_path, FS_READ_ONLY);
#endif /* __DRM_SUPPORT__ */
     mmi_ucs2cpy((S8*) filename, (S8*)srv_fmgr_path_get_filename_ptr((WCHAR*)image_file_path));
    *max_filename_length = mmi_ucs2strlen((S8*) filename) + 1; /* USB task requires to count the null-terminator */

#else /* defined __MMI_FMGR_MULTI_SELECT_SUPPORT__ */

#ifdef __DRM_SUPPORT__
    fs_handle = DRM_open_file((U16*) g_pict_bridge_context.printing_filepath, FS_READ_ONLY, DRM_PERMISSION_PRINT);
#else /* __DRM_SUPPORT__ */
    fs_handle = FS_Open((U16*) g_pict_bridge_context.printing_filepath, FS_READ_ONLY);
#endif /* __DRM_SUPPORT__ */
    mmi_ucs2cpy((S8*) filename, (S8*)srv_fmgr_path_get_filename_ptr((WCHAR*) g_pict_bridge_context.printing_filepath));
    *max_filename_length = mmi_ucs2strlen((S8*) filename) + 1; /* USB task requires to count the null-terminator */

#endif /* defined (__MMI_FMGR_MULTI_SELECT_SUPPORT__) */

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
    /* print debug message */
    #ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
        mmi_ucs2_to_asc(ansii_file_path, image_file_path);
    #else
        mmi_ucs2_to_asc(ansii_file_path, (S8*) g_pict_bridge_context.printing_filepath);
    #endif
#endif /* __MMI_PICT_BRIDGE_KEEP_XML_DATA__ */

    return fs_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_return_print_file_handle_with_filepath
 * DESCRIPTION
 *  Return image file hander to USB task for printing
 * PARAMETERS
 *  obj_handle      [IN]
 *  filepath        [OUT]
 *  max_length      [IN/OUT]
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
FS_HANDLE mmi_pict_return_print_file_handle_with_filepath(kal_uint32 obj_handle, kal_uint16 *filepath, kal_uint16 *max_filepath_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle = NULL;
#ifdef __DRM_SUPPORT__
    FS_FileInfo	file_info;
#endif

#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__

    U8 i, j;
    U16 file_id_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(image_file_path, (S8*) g_pict_bridge_context.printing_filepath);
    srv_fmgr_path_remove_filename((WCHAR*)image_file_path);

    if (g_pict_bridge_setting.page_format == 1) /* multiple */
    {
        for (i = 0; i < g_pict_bridge_context.multi_file_select; i++)
        {
            for (j = 1; ; j++)
            {
                file_id_count++;
                if ((j == 1 && g_pict_bridge_setting.layout == 0) ||
                    (j == 2 && g_pict_bridge_setting.layout == 1) ||
                    (j == 4 && g_pict_bridge_setting.layout == 2))
                {
                    break;
                }
            }

            if (file_id_count >= (U16) obj_handle)
            {
                break;
            }
        }
    }
    else /* standard or index */
    {
        i = (U8) (obj_handle - 1);
    }

    mmi_ucs2cat(image_file_path, (S8*) g_pict_bridge_context.multi_file_path[i]);

#ifdef __DRM_SUPPORT__
    fs_handle = FS_Open((U16*) image_file_path, FS_READ_ONLY);
    if (FS_GetFileInfo(fs_handle, &file_info) == FS_NO_ERROR)
    {
        memcpy((void *) &g_pict_bridge_context.printing_file_info, (void *) file_info.DirEntry, sizeof(FS_DOSDirEntry));
    }
    FS_Close(fs_handle);
#endif /* __DRM_SUPPORT__ */

#ifdef __DRM_SUPPORT__
    fs_handle = DRM_open_file((U16*) image_file_path, FS_READ_ONLY, DRM_PERMISSION_PRINT);
#else
    fs_handle = FS_Open((U16*) image_file_path, FS_READ_ONLY);
#endif
    mmi_ucs2cpy((S8*) filepath, image_file_path);
    *max_filepath_length = mmi_ucs2strlen((S8*) filepath) + 1; /* USB task requires to count the null-terminator */

#else /* defined(__MMI_FMGR_MULTI_SELECT_SUPPORT__) */

#ifdef __DRM_SUPPORT__
    fs_handle = DRM_open_file((U16*) g_pict_bridge_context.printing_filepath, FS_READ_ONLY, DRM_PERMISSION_PRINT);
#else
    fs_handle = FS_Open((U16*) g_pict_bridge_context.printing_filepath, FS_READ_ONLY);
#endif
    mmi_ucs2cpy((S8*) filepath, (S8*) g_pict_bridge_context.printing_filepath);
    *max_filepath_length = mmi_ucs2strlen((S8*) filepath) + 1; /* USB task requires to count the null-terminator */

#endif /* defined(__MMI_FMGR_MULTI_SELECT_SUPPORT__) */

    return fs_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_return_current_print_file_info
 * DESCRIPTION
 *  Return file info to USB task for printing
 * PARAMETERS
 *  info            [OUT]
 * RETURNS
 *  int
 *****************************************************************************/
int mmi_pict_return_current_print_file_info(FS_DOSDirEntry *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    memcpy((void *) info, (void *) &g_pict_bridge_context.printing_file_info, sizeof(FS_DOSDirEntry));
    return FS_NO_ERROR;
#else
    return FS_FILE_NOT_FOUND;
#endif
}


#endif /* __MTK_TARGET__ */


#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_write_xml_data_to_file
 * DESCRIPTION
 *  Write XML data to file
 * PARAMETERS
 *  data_addr       [IN]
 *  data_len        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_write_xml_data_to_file(U8 *data_addr, U32 data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    U32 written_length;
    kal_wchar root_dir[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(root_dir, "%c:\\", (S8) (SRV_FMGR_PUBLIC_DRV));
    mmi_ucs2cat((S8*)root_dir, (const S8*)(L"Received\\pict.xml"));
    fs_handle = FS_Open((U16*) root_dir, FS_CREATE | FS_READ_WRITE);
    FS_Seek(fs_handle, 0, FS_FILE_END);
    FS_Write(fs_handle, (void*) data_addr, data_len, &written_length); 
    FS_Truncate(fs_handle);
    FS_Close(fs_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_delete_xml_data_file
 * DESCRIPTION
 *  Delete XML data file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_delete_xml_data_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar root_dir[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(root_dir, "%c:\\", (S8) (SRV_FMGR_PUBLIC_DRV));
    mmi_ucs2cat((S8*)root_dir, (const S8*)(L"Received\\pict.xml"));
    FS_Delete((U16*) root_dir);
}

#endif /* __MMI_PICT_BRIDGE_KEEP_XML_DATA__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_is_dps_device_present
 * DESCRIPTION
 *  Check if DPS printer is present
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_pict_is_dps_device_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    return ((g_pict_bridge_context.xml_operation_cmd == NULL || g_pict_bridge_context.xml_event_cmd == NULL) ? MMI_FALSE : MMI_TRUE);
#else
    return 1;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_is_configure_ready
 * DESCRIPTION
 *  Check if already finish configuration
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL mmi_pict_is_configure_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( g_pict_bridge_context.next_operation_request == mmi_pict_prepare_xml_configure_print_service ||
        g_pict_bridge_context.next_operation_request == mmi_pict_prepare_xml_get_capability)
	{
		return MMI_FALSE;
	}

	return MMI_TRUE;
}

#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

