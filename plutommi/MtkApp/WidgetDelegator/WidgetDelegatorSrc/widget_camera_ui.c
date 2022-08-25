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
 *   widget_view_ui.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements widget view UI presentation
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "stack_common.h"  
#include "stack_msgs.h"
#include "stack_ltlcom.h"       	/* Task message communiction */
//#include "syscomp_config.h"
#include "task_config.h"      	/* Task creation */
#include "widget_adp_struct.h"
#include "gdi_features.h"

#include "mmi_features.h"
#include "globalresdef.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"    
#include "mmi_frm_events_gprot.h"
#include "Unicodexdcl.h"
#include "cameracuigprot.h"
#include "idlegprot.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_rp_app_widget_delegator_def.h"

void *g_user_data = NULL;
int response_sent = 0;

static mmi_ret mmi_widget_camera_event_handler_proc(mmi_event_struct *evt);

static void send_capture_image_response(void *user_data, int ret, kal_uint8 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_capture_image_rsp_struct *rsp = (widget_capture_image_rsp_struct *)
      construct_local_para(sizeof(widget_capture_image_rsp_struct), TD_RESET);
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp->ret = ret;
    rsp->user_data = user_data;
    if (file_path)
    {
        mmi_ucs2ncpy((CHAR *)rsp->img_path, (const CHAR *)file_path, sizeof(rsp->img_path));
    }

    /* allocate ilm */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) rsp;
    ilm_ptr->msg_id = MSG_ID_WIDGET_CAPTURE_IMAGE_RSP;
    ilm_ptr->peer_buff_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_GADGET, MMI_GADGET_SAP, ilm_ptr);
    response_sent = 1;
}

void widget_handle_capture_image_req(void *param)
{
    widget_capture_image_req_struct *req = (widget_capture_image_req_struct *)param;
    
#if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_id;
		mmi_frm_node_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    response_sent = 0;
    g_user_data = req->user_data;

    group_info.id = GRP_ID_WIDGET_ADP;
    group_info.entry_proc = mmi_widget_camera_event_handler_proc;

    if (mmi_frm_group_is_present(GRP_ID_WIDGET_VIEW))
    {
        mmi_frm_group_insert(GRP_ID_ROOT, GRP_ID_WIDGET_VIEW, &group_info, MMI_FRM_NODE_AFTER_FLAG);
        mmi_frm_group_enter(GRP_ID_WIDGET_ADP, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    else      
    {
        mmi_frm_group_insert(GRP_ID_ROOT, mmi_idle_get_group_id(), &group_info, MMI_FRM_NODE_AFTER_FLAG);
        mmi_frm_group_enter(GRP_ID_WIDGET_ADP, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    cui_id = cui_camera_create(GRP_ID_WIDGET_ADP);
    
    if (cui_id != GRP_ID_INVALID)
    {
        cui_camera_run_struct camera_struct;
        cui_camera_struct_init(&camera_struct);
        cui_camera_run(cui_id, &camera_struct);
    }
    else
    {
        // error handler
        send_capture_image_response(req->user_data, WIDGET_API_GALLERY_FILE_SELECT_ERROR, NULL);
    }
#else
    send_capture_image_response(req->user_data, WIDGET_API_CAMERA_CAPTURE_ERROR, NULL);
    return;
#endif
}


#if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)

static mmi_ret mmi_widget_camera_event_handler_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            if (!response_sent)
            {
                send_capture_image_response(g_user_data, WIDGET_API_CAMERA_CAPTURE_ERROR, NULL);
            }
            break;
        }
        case CUI_CAMERA_EVENT_RESULT_SUCCESS:
            cui_camera_close(((cui_camera_event_struct*)evt)->sender_id);
            send_capture_image_response(g_user_data, WIDGET_API_NO_ERROR, (kal_uint8 *)(((cui_camera_event_struct*)evt)->file_path));
            mmi_frm_group_close(GRP_ID_WIDGET_ADP);
            break;
        case CUI_CAMERA_EVENT_RESULT_FAILED:
        case CUI_CAMERA_EVENT_RESULT_CLOSE_ME:
            cui_camera_close(((cui_camera_event_struct*)evt)->sender_id);
            send_capture_image_response(g_user_data, WIDGET_API_CAMERA_CAPTURE_ERROR, NULL);
            mmi_frm_group_close(GRP_ID_WIDGET_ADP);
            break;
    }
    return MMI_RET_OK;
}

#endif /* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */
