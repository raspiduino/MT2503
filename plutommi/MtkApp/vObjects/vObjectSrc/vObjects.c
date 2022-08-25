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
 * vObjects.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is intends for common screen and functionality for vObjects.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_VOBJECTS_C
#define _MMI_VOBJECTS_C

#include "MMI_features.h"

#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)

#include "MMIDataType.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "GlobalResDef.h"
#include "DateTimeType.h"
#ifndef __COSMOS_MMI__
#include "mmi_cb_mgr_gprot.h"
#endif

#include "mmi_rp_file_type_def.h"
#include "fs_errcode.h"
#include "mmi_frm_mem_gprot.h"
#include "fs_func.h"
#include "fs_type.h"
#include "kal_general_types.h"
#include "mmi_common_app_trc.h"
#include "kal_public_api.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "Conversions.h"
#include "CustDataRes.h"
#include "NotificationGprot.h"
#include "ProfilesSrvGprot.h"
#include "SmsSrvGprot.h"
#include "CustMenuRes.h"
#include "FileMgrSrvGProt.h"
#include "vObjects.h"
#include "vCard.h"
#include "vCalendar.h"
#include "mmi_rp_srv_vobject_def.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif

#ifdef __MMI_VBOOKMARK__
#include "vBookmark.h"
#endif
#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"
#endif 
#include "ctype.h"     
#define MMIAPI_USING_SMS        
#include "mmiapi_struct.h"
#include "IdleNotificationManagerGprot.h"

#ifdef __MMI_NCENTER_SUPPORT__
#include "vsrv_ndeclaration.h" 
#include "vsrv_ncenter.h" 
#endif

#include "GlobalResDef.h"
/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
vobj_context_struct g_vobj_cntx;

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
const CHAR *g_vobj_encoding[VOBJ_EN_TOTAL] = 
{
    "7BIT",
    "8BIT",
    "QUOTED-PRINTABLE",
    "BASE64",
    "X-"
};

const CHAR *g_vobj_paras[VOBJ_PARA_TOTAL] = 
{
    "LANGUAGE",
    "CHARSET",
    "ENCODING"
};

const CHAR *g_vobj_charset[VOBJ_CH_TOTAL] = 
{
    "UTF-8",
    "BIG5",
    "UTF-7"
};

/* 
 * Global Function
 */
extern MMI_BOOL mmi_vobj_search_tmp_path(U16 index, WCHAR *result, vobj_object_type_enum* type);
extern void mmi_vobj_delete_tmp_path(U16 index, vobj_object_type_enum type);
extern void mmi_vobj_increase_file_buffer_counter(vobj_object_type_enum type);
extern MMI_BOOL mmi_vobj_decrease_file_buffer_counter(vobj_object_type_enum type);

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
static mmi_ret mmi_vobj_nmgr_cancel_event_handle(mmi_event_struct* param);
#endif

static MMI_BOOL mmi_vobj_sms_receive_ind(srv_sms_event_struct* event_data);


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_increase_sms_register
 * DESCRIPTION
 *  Add port number into sms register array
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_increase_sms_register(U16 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_vobj_cntx.sms_port_reg[g_vobj_cntx.sms_port_reg_count] = port;
    g_vobj_cntx.sms_port_reg_count++;    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_set_sms_register
 * DESCRIPTION
 *  Set sms port to receive vobject
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_set_sms_register(void)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (g_vobj_cntx.sms_port_reg_count = 0; 
         g_vobj_cntx.sms_port_reg_count < VOBJ_TYPE_NUM * MMI_MAX_SIM_NUM; 
         g_vobj_cntx.sms_port_reg_count++)
    {

        if (g_vobj_cntx.sms_port_reg_count % MMI_MAX_SIM_NUM == 0)
        {
            sim_id = SRV_SMS_SIM_1;
        }
#if (MMI_MAX_SIM_NUM >= 2)
        else if (g_vobj_cntx.sms_port_reg_count % MMI_MAX_SIM_NUM == 1)
        {
            sim_id = SRV_SMS_SIM_2;
        }
#if (MMI_MAX_SIM_NUM >= 3)
        else if (g_vobj_cntx.sms_port_reg_count % MMI_MAX_SIM_NUM == 2)
        {
            sim_id = SRV_SMS_SIM_3;
        }
#if (MMI_MAX_SIM_NUM >= 4)
        else if (g_vobj_cntx.sms_port_reg_count % MMI_MAX_SIM_NUM == 3)
        {
            sim_id = SRV_SMS_SIM_4;
        }
#endif
#endif
#endif /*  (MMI_MAX_SIM_NUM >= 2) */
    #ifdef __MMI_TELEPHONY_SUPPORT__
        srv_sms_reg_port(g_vobj_cntx.sms_port_reg[g_vobj_cntx.sms_port_reg_count / MMI_MAX_SIM_NUM], 
            sim_id, mmi_vobj_sms_receive_ind, NULL);
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
    }  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_register_sms_rsp
 * DESCRIPTION
 *  Response message of registering L4 modules for incoming messages.
 * PARAMETERS
 *  info        [IN]        Message response strut variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_register_sms_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_register_port_rsp_struct *local;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local = (mmiapi_sms_register_port_rsp_struct*) info;

    MMI_TRACE(MMI_VOBJ_TRACE_GROUP, TRC_MMI_VOBJ_REGISTER_SMS_RSP, local->result, local->cause);

    g_vobj_cntx.sms_port_reg_count++;
    mmi_vobj_set_sms_register();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_init
 * DESCRIPTION
 *  Initialization of vobject application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOBJ_TRACE_GROUP, TRC_MMI_VOBJ_INIT);

    memset(&g_vobj_cntx, 0, sizeof(vobj_context_struct));

    /* Clear file buffer */
#ifdef __MMI_VCARD__
    mmi_vobj_increase_sms_register(VOBJ_VCARD_PORT);
#endif 

#ifdef __MMI_VCALENDAR__
    mmi_vobj_increase_sms_register(VOBJ_VCLNDR_PORT);
#endif 

#ifdef __MMI_VBOOKMARK__
    mmi_vobj_increase_sms_register(VOBJ_VBKM_PORT);
    mmi_vbkm_init();
#endif
    mmi_vobj_set_sms_register();
#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
    mmi_frm_cb_reg_event(EVT_ID_NMGR_IDLE_CANCEL, mmi_vobj_nmgr_cancel_event_handle, NULL);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_deinit
 * DESCRIPTION
 *  Deinitialize function for vObjects. Free allocated buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOBJ_TRACE_GROUP, TRC_MMI_VOBJ_DEINIT);
#if defined(__MMI_VBOOKMARK__)
    mmi_vbkm_deinit();
#endif 
}


#if defined(__MMI_OPP_SUPPORT__) //|| defined(__MMI_FTP_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_opp_receive_ind
 * DESCRIPTION
 *  Indication handler when receiving a vObject message from BT.
 *  If it's in Idle screen, process the object immediatelly,
 *  otherwise, insert into the queue.
 * PARAMETERS
 *  path_src        [IN/OUT]        File path name of the vobject received from opp
 *  type            [IN]            Type of the object (vCard or vCalendar)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_opp_receive_ind(void *path_src, U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *path_name;
    S32 result;
    S32 check_result = mmi_vobj_fs_check_folder();
    vobj_object_type_enum obj_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOBJ_TRACE_GROUP, TRC_MMI_VOBJ_OPP_RECEIVE_IND);

    if (type == FMGR_TYPE_VCF)
    {
        obj_type = MMI_VOBJ_VCARD;
    }
#if defined(__MMI_VBOOKMARK__)
    else if (type == FMGR_TYPE_VBM || type == FMGR_TYPE_URL)
    {
        obj_type = MMI_VOBJ_VBKM;
    }
#endif /*__MMI_VBOOKMARK__*/
    else
    {
        obj_type = MMI_VOBJ_VCLNDR;
    }
    
    if (mmi_vobj_get_file_buffer_size(obj_type) == 0)
    {
        g_vobj_cntx.obj_type = obj_type;
    }

    /* Wrtie object to tempoary file, parsing later. */
    if (check_result == FS_NO_ERROR)
    {
    #if defined(__MMI_VBOOKMARK__)
        if (obj_type == MMI_VOBJ_VBKM)
        {
            if(!mmi_vbkm_space_available())
			  {
					mmi_vbkm_display_error_message();
					return;
			  }
			else
			 {
					mmi_vbkm_recv_file_save_file_info(path_src, VBKM_RECV_VIA_BT);
			  }
        }
    #endif /*__MMI_VBOOKMARK__*/

        path_name = OslMalloc(VOBJ_MAX_PATH_LENGTH);

        mmi_vobj_delete_tmp_path(g_vobj_cntx.buffer_end[obj_type], obj_type);
        mmi_vobj_get_full_path_name(g_vobj_cntx.buffer_end[obj_type], path_name, obj_type);

        FS_Delete((U16*) path_name);

        result = FS_Rename((U16*) path_src, (U16*) path_name);

        if (result == FS_NO_ERROR)
        {
            mmi_vobj_increase_file_buffer_counter(obj_type);

    //        FS_SetAttributes((const WCHAR *)path_name, (U8) FS_ATTR_HIDDEN);

            mmi_vobj_receive_ind_prompt(MMI_TRUE, obj_type, 0);
        }
        else
        {
            FS_Delete((U16*) path_src);
            mmi_vobj_receive_ind_prompt(MMI_FALSE, MMI_VOBJ_UNRECOGNIZED, STR_ID_VOBJ_RECEIVE_FALL);
        }

        OslMfree(path_name);
    }
    else
    {
        FS_Delete((U16*) path_src);
        mmi_vobj_receive_ind_prompt(MMI_FALSE, MMI_VOBJ_UNRECOGNIZED, srv_fmgr_fs_error_get_string(check_result));
    }
}

#endif /* defined(__MMI_OPP_SUPPORT__) || defined(__MMI_FTP_SUPPORT__) */ 


/* IMPS */
#ifdef __MMI_VCARD__
typedef struct
{
    mmi_id group_id;
    mmi_vobj_recv_from_other_app_callback cb;
    U16* path;
} mmi_vobj_imps_receive_cntx_struct;


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_opp_receive_ind
 * DESCRIPTION
 *  Indication handler when receiving a vObject message from BT.
 *  If it's in Idle screen, process the object immediatelly,
 *  otherwise, insert into the queue.
 * PARAMETERS
 *  path_src        [IN/OUT]        File path name of the vobject received from opp
 *  type            [IN]            Type of the object (vCard or vCalendar)
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_vobj_imps_receive_vcard_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    mmi_vobj_imps_receive_cntx_struct* cntx = (mmi_vobj_imps_receive_cntx_struct*)evt->user_data;
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_VCARD_CANCEL:
            cntx->cb(MMI_VOBJ_SAVE_DISCARD, (CHAR*)cntx->path);
            mmi_frm_group_close(GRP_ID_VOBJ_REC_IMPS);
            OslMfree(cntx);
            break;
        case EVT_ID_VCARD_DONE:
            switch (((cui_vcard_result_struct*)evt)->result)
            {
                case CUI_VARD_TO_PHONE_DONE:
                    result = MMI_VOBJ_SAVE_TO_PHONE;
                    break;
            #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_DUAL_SIM_MASTER__ */
                case CUI_VARD_TO_SIM_DONE:
                    result = MMI_VOBJ_SAVE_TO_SIM;
                    break;
                case CUI_VARD_TO_FMGR_DONE:
                    result = MMI_VOBJ_SAVE_TO_FILEMGR;
                    break;
                case CUI_VARD_TO_PHONE_FAIL:
                    result = MMI_VOBJ_SAVE_TO_PHONE_FAIL;
                    break;
            #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_DUAL_SIM_MASTER__ */
                case CUI_VARD_TO_SIM_FAIL:
                    result = MMI_VOBJ_SAVE_TO_SIM_FAIL;
                    break;
                case CUI_VARD_TO_FMGR_FAIL:
                    result = MMI_VOBJ_SAVE_TO_FILEMGR_FAIL;
                    break;
                default:
                    result = MMI_VOBJ_SAVE_DISCARD;
                    break;
            }
            cntx->cb((vobj_save_info_enum)result, (CHAR*)cntx->path);
            mmi_frm_group_close(GRP_ID_VOBJ_REC_IMPS);
            OslMfree(cntx);
            break;

        case EVT_ID_GROUP_DEINIT:
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_opp_receive_ind
 * DESCRIPTION
 *  Indication handler when receiving a vObject message from BT.
 *  If it's in Idle screen, process the object immediatelly,
 *  otherwise, insert into the queue.
 * PARAMETERS
 *  path_src        [IN/OUT]        File path name of the vobject received from opp
 *  type            [IN]            Type of the object (vCard or vCalendar)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_imps_receive_vcard(void *path_src, mmi_vobj_recv_from_other_app_callback call_back)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vobj_imps_receive_cntx_struct* cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path_src == NULL)
    {
        call_back(MMI_VOBJ_SAVE_DISCARD, path_src);
        return;
    }
    cntx = OslMalloc(sizeof(mmi_vobj_imps_receive_cntx_struct));
    cntx->path = (U16*)path_src;
    cntx->cb = call_back;
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_VOBJ_REC_IMPS, mmi_vobj_imps_receive_vcard_proc, cntx);
    mmi_frm_group_enter(GRP_ID_VOBJ_REC_IMPS, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cntx->group_id = cui_vcard_parse_vcard_creat(GRP_ID_VOBJ_REC_IMPS);
    cui_vcard_parse_vcard_set_path(cntx->group_id, cntx->path);
    cui_vcard_parse_vcard_set_type(cntx->group_id, MMI_VCARD_PARSE_VCARD_PHB);
    cui_vcard_parse_vcard_run(cntx->group_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_opp_receive_ind
 * DESCRIPTION
 *  Indication handler when receiving a vObject message from BT.
 *  If it's in Idle screen, process the object immediatelly,
 *  otherwise, insert into the queue.
 * PARAMETERS
 *  path_src        [IN/OUT]        File path name of the vobject received from opp
 *  type            [IN]            Type of the object (vCard or vCalendar)
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_vobj_idle_receive_vcard_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_VCARD_DONE:
            if (((cui_vcard_result_struct*)evt)->result >= 0)
            {
                mmi_vobj_clear_one_file_buffer();
            }
			else
			{
                mmi_vobj_decrease_file_buffer_counter(MMI_VOBJ_VCARD);
			}
        case EVT_ID_VCARD_CANCEL:
            mmi_frm_group_close(GRP_ID_VOBJ_REC_IDLE);
            break;

        case EVT_ID_GROUP_DEINIT:
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_opp_receive_ind
 * DESCRIPTION
 *  Indication handler when receiving a vObject message from BT.
 *  If it's in Idle screen, process the object immediatelly,
 *  otherwise, insert into the queue.
 * PARAMETERS
 *  path_src        [IN/OUT]        File path name of the vobject received from opp
 *  type            [IN]            Type of the object (vCard or vCalendar)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_idle_receive_vcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    mmi_id grp_id;
	U16 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_VOBJ_REC_IDLE, mmi_vobj_idle_receive_vcard_proc, NULL);
    mmi_frm_group_enter(GRP_ID_VOBJ_REC_IDLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	index = g_vobj_cntx.buffer_end[MMI_VOBJ_VCARD];
	index--;
    mmi_vobj_get_full_path_name(index, (CHAR*)path, MMI_VOBJ_VCARD);
	//mmi_vobj_get_full_path_name(g_vobj_cntx.buffer_begin[MMI_VOBJ_VCARD], (CHAR*)path, MMI_VOBJ_VCARD);
    grp_id = cui_vcard_parse_vcard_creat(GRP_ID_VOBJ_REC_IDLE);
    cui_vcard_parse_vcard_set_path(grp_id, path);
    cui_vcard_parse_vcard_set_type(grp_id, MMI_VCARD_PARSE_VCARD_PHB);
    cui_vcard_parse_vcard_run(grp_id);
}

#endif /* __MMI_VCARD__ */


#ifdef __MMI_VCALENDAR__
/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_idle_receive_vcalendar_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_vobj_idle_receive_vcalendar_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_VCAL_SUCCESS:
        case EVT_ID_CUI_VCAL_FAIL_NOT_ENOUGH_MEMORY:
        case EVT_ID_CUI_VCAL_NOT_SUPPORT:
        case EVT_ID_CUI_VCAL_FAIL:
        {
            mmi_vobj_clear_one_file_buffer();
            //No break here
        }
        case EVT_ID_CUI_VCAL_USER_CANCEL:
        {
            mmi_group_event_struct *evt_recv = (mmi_group_event_struct*)evt;
            cui_vcal_recv_close(evt_recv->sender_id);
            break;   
        } 

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_idle_receive_vcalendar
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_idle_receive_vcalendar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 path_name[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    mmi_id sg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_VOBJ_REC_IDLE, mmi_vobj_idle_receive_vcalendar_proc, NULL);
    mmi_frm_group_enter(GRP_ID_VOBJ_REC_IDLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    sg_id = cui_vcal_recv_create(GRP_ID_VOBJ_REC_IDLE);    
    mmi_vobj_get_full_path_name(g_vobj_cntx.buffer_begin[MMI_VOBJ_VCLNDR], (CHAR*)path_name, MMI_VOBJ_VCLNDR);    
    cui_vcal_recv_set_path(sg_id, path_name);
    cui_vcal_recv_run(sg_id);
}
#endif /* __MMI_VCALENDAR__ */


#ifdef __MMI_NCENTER_SUPPORT__
void mmi_vobj_ncenter_tap_callback(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vobj_object_type_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif

	switch(intent.type)
	{
      case VSRV_NINTENT_TYPE_LAUNCH:
	    {
		  type = *(vobj_object_type_enum*)userData;
		  g_vobj_cntx.obj_type = type;
	
        #ifdef __MMI_VCARD__
			if (type == MMI_VOBJ_VCARD)
			{
			  mmi_vobj_idle_receive_vcard();
			  return;
			}
        #endif /* __MMI_VCARD__ */ 
	
        #ifdef __MMI_VCALENDAR__
			if (type == MMI_VOBJ_VCLNDR)
			{
			  mmi_vobj_idle_receive_vcalendar();
			  return;
			}
        #endif /* __MMI_VCALENDAR__ */ 
	
        #ifdef __MMI_VBOOKMARK__
			if (type == MMI_VOBJ_VBKM)
			{
			  mmi_vbkm_recv_file_pre_entry_options();
			  return;
			}
        #endif /* __MMI_VBOOKMARK__ */ 
	      break;
		}
	  case VSRV_NINTENT_TYPE_CLEAR:
		  {
	       
        #ifdef __MMI_VBOOKMARK__		
			// type = mmi_vobj_check_curr_file_type();
			 type = *(vobj_object_type_enum*)userData;
			 if (type == MMI_VOBJ_VBKM )
			  {										
			    mmi_vbkm_clean_one_file_buffer();
			  }
	    #endif /* __MMI_VBOOKMARK__ */
			break;
	       
		  }
		 default:
		   return;
	}

}


mmi_ret mmi_vobj_text_preview_tap_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vobj_object_type_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH ||
		evt->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH)
	{
	    type = *(vobj_object_type_enum*)evt->user_data;
        g_vobj_cntx.obj_type = type;
#ifdef __MMI_VCARD__
	    if (type == MMI_VOBJ_VCARD)
	    {
	        mmi_vobj_idle_receive_vcard();
	    }
#endif /* __MMI_VCARD__ */ 

#ifdef __MMI_VCALENDAR__
	    if (type == MMI_VOBJ_VCLNDR)
	    {
	        mmi_vobj_idle_receive_vcalendar();
	    }
#endif /* __MMI_VCALENDAR__ */ 

#ifdef __MMI_VBOOKMARK__
	    if (type == MMI_VOBJ_VBKM)
	    {
	        mmi_vbkm_recv_file_pre_entry_options();
	    }
#endif /* __MMI_VBOOKMARK__ */ 
	}
	
	return MMI_TRUE;
}


static void mmi_vobj_ncenter_notification(vobj_object_type_enum obj_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vsrv_ngroup_handle ghandle = NULL;
	vsrv_notification_handle nhandle = NULL;
    U16 str_id = 0;
	mmi_frm_nmgr_alert_struct alert_info;
    applib_time_struct timestamp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(obj_type)
	{
#ifdef __MMI_VCARD__	    
		case MMI_VOBJ_VCARD:
			str_id = STR_ID_VOBJ_RECV_VCARD;
			ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, SRV_VCARD);
			nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, ghandle, g_vobj_cntx.buffer_end[obj_type]);
			vsrv_ncenter_set_ngroup_title_id(ghandle, STR_ID_VCARD);
			vsrv_ncenter_set_notification_maintext_id(nhandle, str_id);
			vsrv_ncenter_set_notification_intent_callback(nhandle, mmi_vobj_ncenter_tap_callback, (void*)&obj_type, sizeof(S32));
			vsrv_ncenter_notify_notification(nhandle);
			break;
#endif /* __MMI_VCARD__ */ 

#ifdef __MMI_VCALENDAR__
		case MMI_VOBJ_VCLNDR:
			str_id = STR_ID_VOBJ_RECV_VCLNDR;
			ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, SRV_VCALENDAR);
			nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, ghandle, g_vobj_cntx.buffer_end[obj_type]);
	        vsrv_ncenter_set_ngroup_title_id(ghandle, STR_ID_VCLNDR);
	        vsrv_ncenter_set_notification_maintext_id(nhandle, str_id);
			vsrv_ncenter_set_notification_intent_callback(nhandle, mmi_vobj_ncenter_tap_callback, (void*)&obj_type, sizeof(S32));
			vsrv_ncenter_notify_notification(nhandle);
			break;
#endif /* __MMI_VCALENDAR__ */
			
#ifdef __MMI_VBOOKMARK__
        case MMI_VOBJ_VBKM:
			str_id = STR_ID_VOBJ_RECV_VBKM;
			ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, SRV_VBOOKMARK);
			nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, ghandle, g_vobj_cntx.buffer_end[obj_type]);
			vsrv_ncenter_set_ngroup_title_id(ghandle, STR_ID_VBKM);
	        vsrv_ncenter_set_notification_maintext_id(nhandle, str_id);
			vsrv_ncenter_set_notification_intent_callback(nhandle, mmi_vobj_ncenter_tap_callback, (void*)&obj_type, sizeof(S32));
			vsrv_ncenter_notify_notification(nhandle);
			break;
#endif /* __MMI_VBOOKMARK__ */ 	
	    default:
	        str_id = STR_ID_VOBJ_RECEIVE_FALL;
			break;
	}

	// N-Center
/*
	ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, SRV_VOBJECT);
	nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, ghandle, obj_type);
	GetDateTime(&timestamp);
	vsrv_ncenter_set_notification_timestamp(nhandle, &timestamp);
	vsrv_ncenter_set_ngroup_title_str(ghandle, (WCHAR*)L"vObjects");
	vsrv_ncenter_set_notification_maintext_str(nhandle, (WCHAR*)GetString(str_id));
	vsrv_ncenter_set_notification_intent_callback(nhandle, mmi_vobj_ncenter_tap_callback, (void*)&obj_type, sizeof(S32));
	vsrv_ncenter_notify_notification(nhandle);
*/
    // Test preview
	memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));	 
	alert_info.app_id = SRV_VOBJECT;
	alert_info.scen_id = SCR_ID_VOBJ_RECV_OBJECT;
	alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK;
	alert_info.behavior_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK;
	alert_info.alert_option = 0;
	alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
	alert_info.status_bar_para.display_string = (WCHAR*)GetString(str_id);	
	alert_info.app_proc_para.scrn_group_proc = mmi_vobj_text_preview_tap_callback;
	alert_info.app_proc_para.user_data = (void*)&obj_type;
	alert_info.app_proc_para.data_size = 4;	
	mmi_frm_nmgr_alert(&alert_info);	
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_opp_receive_ind
 * DESCRIPTION
 *  Indication handler when receiving a vObject message from BT.
 *  If it's in Idle screen, process the object immediatelly,
 *  otherwise, insert into the queue.
 * PARAMETERS
 *  path_src        [IN/OUT]        File path name of the vobject received from opp
 *  type            [IN]            Type of the object (vCard or vCalendar)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_imps_receive_ind(void *path_src, U32 type, mmi_vobj_recv_from_other_app_callback call_back)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOBJ_TRACE_GROUP, TRC_MMI_VOBJ_IMPS_RECEIVE_IND);

    g_vobj_cntx.recv_callback = call_back;
#ifdef __MMI_VCARD__
    if (type == FMGR_TYPE_VCF)
    {
        mmi_vobj_imps_receive_vcard((CHAR*)path_src, call_back);
    }
    else 
#endif /* __MMI_VCARD__ */
#ifdef __MMI_VCALENDAR__    
    if (type == FMGR_TYPE_VCS)
    {
        g_vcal_cntx.SrcType = VCLNDR_SAVE_FROM_APP;
        g_vobj_cntx.info = MMI_VOBJ_SAVE_DISCARD;
    }
    else
#endif /*__MMI_VCALENDAR__*/
    {
#if defined(__MMI_VBOOKMARK__)
    {
    }
#endif /*__MMI_VBOOKMARK__*/
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_sms_receive_ind
 * DESCRIPTION
 *  indication of receive incoming SMS vobject message.
 * PARAMETERS
 *  info        [IN]        Message indication struct variable
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_vobj_sms_receive_ind(srv_sms_event_struct* event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_ind_struct *local;
    srv_sms_event_new_sms_struct * data = (srv_sms_event_new_sms_struct*)event_data->event_info;
    srv_sms_new_msg_struct *new_msg = (srv_sms_new_msg_struct *)data->msg_data;
    U16 len = new_msg->message_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOBJ_TRACE_GROUP, TRC_MMI_VOBJ_SMS_RECEIVE_IND, new_msg->dest_port);

    if (new_msg->message_len && (new_msg->dest_port == VOBJ_VCARD_PORT || new_msg->dest_port == VOBJ_VCLNDR_PORT
    #ifdef __MMI_VBOOKMARK__
        || new_msg->dest_port == VOBJ_VBKM_PORT
    #endif /* __MMI_VBOOKMARK__ */ 
       ))
    {
        g_vobj_cntx.curr_sms_port = new_msg->dest_port;
        mmi_vobj_sms_handle_msg_content(data->content, new_msg->message_len);
    }
	return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_sms_handle_msg_content
 * DESCRIPTION
 *  response to retrieve incoming vobject sms.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_sms_handle_msg_content(void *content, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    CHAR *path_name;
    U32 write_len;
    S32 check_result = mmi_vobj_fs_check_folder();
    vobj_object_type_enum obj_type = MMI_VOBJ_UNRECOGNIZED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOBJ_TRACE_GROUP, TRC_MMI_VOBJ_SMS_GET_INCOMING_MSG_RSP);

    path_name = OslMalloc(VOBJ_MAX_PATH_LENGTH);

    if (check_result == FS_NO_ERROR)
    {
        if (g_vobj_cntx.curr_sms_port == VOBJ_VCARD_PORT)
        {
            obj_type = MMI_VOBJ_VCARD;
        }
        else if(g_vobj_cntx.curr_sms_port == VOBJ_VCLNDR_PORT)
        {
            obj_type = MMI_VOBJ_VCLNDR;
        }
    #ifdef __MMI_VBOOKMARK__
        else
        {
            obj_type = MMI_VOBJ_VBKM;
        }
    #endif /* __MMI_VBOOKMARK__ */ 
        
        if (mmi_vobj_get_file_buffer_size(obj_type) == 0)
        {
            g_vobj_cntx.obj_type = obj_type;
        }

        mmi_vobj_delete_tmp_path(g_vobj_cntx.buffer_end[obj_type], obj_type);
        mmi_vobj_get_full_path_name(g_vobj_cntx.buffer_end[obj_type], path_name, obj_type);

        fh = FS_Open((U16*) path_name, FS_CREATE_ALWAYS | FS_READ_WRITE);

        if (fh > 0)
        {
            /* hide this received file*/
     //       FS_SetAttributes((const WCHAR *)path_name, (U8) FS_ATTR_HIDDEN);
            check_result = FS_Write(fh, content, len, (U32*) & write_len);
            FS_Close(fh);

            if (check_result == FS_NO_ERROR)
            {
			    mmi_vobj_increase_file_buffer_counter(obj_type);			
                mmi_vobj_receive_ind_prompt(MMI_TRUE, obj_type, 0);			
            }
            else
            {
                mmi_vobj_receive_ind_prompt(MMI_FALSE, MMI_VOBJ_UNRECOGNIZED, srv_fmgr_fs_error_get_string(check_result));
            }
        }
        else
        {
            mmi_vobj_receive_ind_prompt(MMI_FALSE, MMI_VOBJ_UNRECOGNIZED, srv_fmgr_fs_error_get_string(fh));
        }
    }
    else
    {
        mmi_vobj_receive_ind_prompt(MMI_FALSE, MMI_VOBJ_UNRECOGNIZED, srv_fmgr_fs_error_get_string(check_result));
    }
    OslMfree(path_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_is_pending_object
 * DESCRIPTION
 *  Check if there any pending objects.
 *  Criterion: if buffer size > 0 and rename succesfully.
 *  If there is any pending obejct, rename the temporary file.
 * PARAMETERS
 *  void
 * RETURNS
 *  ture if there is any pending object, otherwiser false.
 *****************************************************************************/
 #ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
MMI_BOOL mmi_vobj_is_pending_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOBJ_TRACE_GROUP, TRC_MMI_VOBJ_IS_PENDING_OBJECT, 1);

#ifdef __USB_IN_NORMAL_MODE__    
    if (srv_usb_is_in_mass_storage_mode_ext())
    {
        MMI_TRACE(MMI_VOBJ_TRACE_GROUP, TRC_MMI_VOBJ_IS_PENDING_OBJECT, 2);    
        return MMI_FALSE;
    }
#endif

    while (mmi_vobj_get_file_buffer_size(g_vobj_cntx.obj_type))
    {
        path = OslMalloc(VOBJ_MAX_PATH_LENGTH);
        if (mmi_vobj_search_tmp_path(g_vobj_cntx.buffer_begin[g_vobj_cntx.obj_type], path, &g_vobj_cntx.obj_type))
        {
            fh = FS_Open(path, FS_READ_ONLY);
            if (fh >= FS_NO_ERROR)
            {
                FS_Close(fh);
                OslMfree(path);
                MMI_TRACE(MMI_VOBJ_TRACE_GROUP, TRC_MMI_VOBJ_IS_PENDING_OBJECT, 3);                
                return MMI_TRUE;
            }
        }
        mmi_vobj_decrease_file_buffer_counter(g_vobj_cntx.obj_type);
        MMI_TRACE(MMI_VOBJ_TRACE_GROUP, TRC_MMI_VOBJ_IS_PENDING_OBJECT, 4);        
        OslMfree(path);
    } 

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_receive_ind_prompt
 * DESCRIPTION
 *  Display prompt message according to the current screen.
 *  Shall follow the SMS prompt scenario.
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_receive_ind_prompt(MMI_BOOL result, vobj_object_type_enum type, U16 error_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!result)
    {
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_VOBJECT, MMI_EVENT_FAILURE, (WCHAR *)GetString(error_string));
    }
    else
    {
#ifdef __MMI_NCENTER_SUPPORT__
        mmi_vobj_ncenter_notification(type);
#else  				
        mmi_frm_nmgr_notify_by_idle(MMI_SCENARIO_ID_VOBJECT, MMI_EVENT_INFO, NULL);
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_nmgr_cancel_event_handle
 * DESCRIPTION
 *  quick search cache update function 
 * PARAMETERS
 *  param     : [IN]   event data
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_vobj_nmgr_cancel_event_handle(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vobj_clear_one_file_buffer();
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_nmgr_cancel
 * DESCRIPTION
 *  Don't show idle notify again
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_nmgr_cancel(void)
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
 *  mmi_msg_nmgr_query_sim_sms_notify
 * DESCRIPTION
 *  SIM SMS notify mananger query function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_nmgr_query_pending_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vobj_object_type_enum type;
    U16 str_id = 0;
    mmi_nmgr_info_struct info;
    mmi_nmgr_hdlr_func_t handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = mmi_vobj_check_curr_file_type();

#ifdef __MMI_VCARD__
    if (type == MMI_VOBJ_VCARD)
    {
        str_id = STR_ID_VOBJ_RECV_VCARD;
        handle = (mmi_nmgr_hdlr_func_t) mmi_vobj_idle_receive_vcard;
    }
#endif /* __MMI_VCARD__ */ 

#ifdef __MMI_VCALENDAR__
    if (type == MMI_VOBJ_VCLNDR)
    {
        str_id = STR_ID_VOBJ_RECV_VCLNDR;
        handle = (mmi_nmgr_hdlr_func_t) mmi_vobj_idle_receive_vcalendar;
    }
#endif /* __MMI_VCALENDAR__ */ 

#ifdef __MMI_VBOOKMARK__
    if (type == MMI_VOBJ_VBKM)
    {
        str_id = STR_ID_VOBJ_RECV_VBKM;
        handle = (mmi_nmgr_hdlr_func_t) mmi_vbkm_recv_file_pre_entry_options;
    }
#endif /* __MMI_VBOOKMARK__ */ 

    info.idle_text1 = GetString(str_id);
    info.idle_text2 = NULL;
    info.image = NULL;
    info.left_softkey = STR_GLOBAL_OPTIONS;
    info.user_data = NULL;
    
    info.icon = 0;
    info.total_num = 1;
    mmi_nmgr_answer(
        MMI_NMGR_APP_VOBJ,
        MMI_NMGR_RESULT_OK,
        &info,
        handle);
}
#else
void mmi_vobj_alert_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vobj_object_type_enum type;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH ||evt->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH)
    {
	

        type = *(vobj_object_type_enum*)evt->user_data;

#ifdef __MMI_VCARD__
     if (type == MMI_VOBJ_VCARD)
    {
       

         mmi_vobj_idle_receive_vcard();
    }
#endif /* __MMI_VCARD__ */ 

#ifdef __MMI_VCALENDAR__
	    if (type == MMI_VOBJ_VCLNDR)
	    {
	        mmi_vobj_idle_receive_vcalendar();
	    }
#endif /* __MMI_VCALENDAR__ */ 

#ifdef __MMI_VBOOKMARK__
	    if (type == MMI_VOBJ_VBKM)
	    {
	        mmi_vbkm_recv_file_pre_entry_options();
	    }
#endif /* __MMI_VBOOKMARK__ */ 


		}
}


void mmi_vobj_receive_ind_prompt(MMI_BOOL result, vobj_object_type_enum type, U16 error_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!result)
    {
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_VOBJECT, MMI_EVENT_FAILURE, (WCHAR *)GetString(error_string));
    }
    else
    {
#ifdef __MMI_NCENTER_SUPPORT__
        mmi_vobj_ncenter_notification(type);
#else  				
      
    mmi_frm_nmgr_alert_struct alert_info; 
	U16 str_id = 0;

    switch(type)
	{
#ifdef __MMI_VCARD__	    
		case MMI_VOBJ_VCARD:
			str_id = STR_ID_VOBJ_RECV_VCARD;
			break;
#endif /* __MMI_VCARD__ */ 

#ifdef __MMI_VCALENDAR__
		case MMI_VOBJ_VCLNDR:
			str_id = STR_ID_VOBJ_RECV_VCLNDR;
			#endif /* __MMI_VCALENDAR__ */

#ifdef __MMI_VBOOKMARK__
        case MMI_VOBJ_VBKM:
			str_id = STR_ID_VOBJ_RECV_VBKM;
			break;
#endif /* __MMI_VBOOKMARK__ */ 	
	    default:
	        str_id = STR_ID_VOBJ_RECEIVE_FALL;
			break;
    	}
	/*		
    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));	 
	alert_info.app_id = SRV_VOBJECT;
	alert_info.scen_id = SCR_ID_VOBJ_RECV_OBJECT;
	alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK;
	alert_info.behavior_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK;
	alert_info.alert_option = 0;
	alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
	alert_info.status_bar_para.display_string = (WCHAR*)GetString(str_id);	
	alert_info.app_proc_para.scrn_group_proc = mmi_vobj_alert_proc;

	alert_info.app_proc_para.user_data = (void*)&type;
	
	alert_info.app_proc_para.data_size = 4;	
	mmi_frm_nmgr_alert(&alert_info);
	*/

	
	  memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));	   
	  alert_info.app_id = SRV_VOBJECT;
	  alert_info.scen_id = SCR_ID_VOBJ_RECV_OBJECT;
	  alert_info.ui_mask = MMI_FRM_NMGR_UI_POPUP_MASK;
	  alert_info.behavior_mask = MMI_FRM_NMGR_UI_POPUP_MASK;
	  alert_info.alert_option = 0;
	  //alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
	  alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
	  //alert_info.status_bar_para.display_string = (WCHAR*)GetString(str_id);	  
	  alert_info.popup_para.popup_string = (WCHAR*)GetString(str_id);
	  alert_info.popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_OK);
	  alert_info.app_proc_para.scrn_group_proc = mmi_vobj_alert_proc;

	alert_info.app_proc_para.user_data = (void*)&type;
	
	alert_info.app_proc_para.data_size = 4;	
	mmi_frm_nmgr_alert(&alert_info);
#endif

    }
}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_clear_one_file_buffer
 * DESCRIPTION
 *  remove current indexing file from file buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_clear_one_file_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path_name;
	vobj_object_type_enum type;
	U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOBJ_TRACE_GROUP, TRC_MMI_VOBJ_CLEAR_ONE_FILE_BUFFER);
    type = mmi_vobj_check_curr_file_type();
    path_name = OslMalloc(VOBJ_MAX_PATH_LENGTH);

    /* Delete temp file first. */
	index = g_vobj_cntx.buffer_end[type];
	index--;
    mmi_vobj_get_full_path_name(index, (CHAR*)path_name, type);
    //mmi_vobj_get_full_path_name(g_vobj_cntx.buffer_begin[type], (CHAR*)path_name, type);
    FS_Delete(path_name);

    /* Decrease counter */
    mmi_vobj_decrease_file_buffer_counter(type);

    OslMfree(path_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_get_file_buffer_size
 * DESCRIPTION
 *  return number of current pending objects
 * PARAMETERS
 *  void
 * RETURNS
 *  number of objects
 *****************************************************************************/
U16 mmi_vobj_get_file_buffer_size(vobj_object_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOBJ_TRACE_GROUP, TRC_MMI_VOBJ_GET_FILE_BUFFER_SIZE, g_vobj_cntx.buffer_begin[type], g_vobj_cntx.buffer_end[type]);

    return g_vobj_cntx.buffer_end[type] - g_vobj_cntx.buffer_begin[type];
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_exit_usb_ms_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_vobj_exit_usb_ms_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vobj_get_file_buffer_size(g_vobj_cntx.obj_type))
    {
#ifdef __MMI_NCENTER_SUPPORT__
        mmi_vobj_ncenter_notification(g_vobj_cntx.obj_type);
#else         
        mmi_frm_nmgr_notify_by_idle(MMI_SCENARIO_ID_VOBJECT, MMI_EVENT_INFO, NULL);
#endif        
    }
    return MMI_RET_OK;
}

void mmi_vobj_usb_mode_plugout_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vobj_get_file_buffer_size(g_vobj_cntx.obj_type))
    {
#ifdef __MMI_NCENTER_SUPPORT__
        mmi_vobj_ncenter_notification(g_vobj_cntx.obj_type);
#else         
        mmi_frm_nmgr_notify_by_idle(MMI_SCENARIO_ID_VOBJECT, MMI_EVENT_INFO, NULL);
#endif        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_phone_format_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_vobj_phone_format_handler(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_format_event_struct *p_event = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_event = (srv_fmgr_notification_format_event_struct*)event;

    switch (p_event->state)
    {
        case SRV_FMGR_NOTIFICATION_STATE_AFTER:
        {
			if(p_event->drv_letter == (CHAR)SRV_FMGR_PHONE_DRV)
			{
			#ifdef __MMI_VCARD__	
	            g_vobj_cntx.buffer_begin[MMI_VOBJ_VCARD] = 0;
	            g_vobj_cntx.buffer_end[MMI_VOBJ_VCARD] = 0; 
			#endif	
		    #ifdef __MMI_VCALENDAR__	
	            g_vobj_cntx.buffer_begin[MMI_VOBJ_VCLNDR] = 0;
	            g_vobj_cntx.buffer_end[MMI_VOBJ_VCLNDR] = 0; 
			#endif	
			#ifdef __MMI_VBOOKMARK__	
	            g_vobj_cntx.buffer_begin[MMI_VOBJ_VBKM] = 0;
	            g_vobj_cntx.buffer_end[MMI_VOBJ_VBKM] = 0; 
			#endif	
			}
            break;
        }
        default:
        {
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_increase_file_buffer_counter
 * DESCRIPTION
 *  increase file buffer counter by 1 and insert into event list
 * PARAMETERS
 *  type        [IN]        Type of vobject
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_increase_file_buffer_counter(vobj_object_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vobj_cntx.buffer_end[type]++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_decrease_file_buffer_counter
 * DESCRIPTION
 *  decrease file conter by 1.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_vobj_decrease_file_buffer_counter(vobj_object_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vobj_get_file_buffer_size(type) > 0)
    {
        g_vobj_cntx.buffer_end[type]--;
        //g_vobj_cntx.buffer_begin[type]++;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_fs_check_folder
 * DESCRIPTION
 *  check if vObject folder exists, if not, create the folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vobj_fs_check_path(WCHAR* path, MMI_BOOL hiden)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    S32 result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);

    /* Folder Exists */
    if (fh > 0)
    {
        if (hiden)
        {
            FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }
        FS_Close(fh);
    }
    /* Folder Does Not Exist */
    else
    {
        result = FS_CreateDir(path);
        /* Create Success */
        if (hiden && result == FS_NO_ERROR)
        {
            FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_fs_check_folder
 * DESCRIPTION
 *  check if vObject folder exists, if not, create the folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vobj_fs_check_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    S32 result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path = OslMalloc(VOBJ_MAX_PATH_LENGTH);
    kal_wsprintf(path, "%c:\\%s\\", VOBJ_DRV, (CHAR*) VOBJ_RECV_PATH);
    result = mmi_vobj_fs_check_path(path, MMI_FALSE);
    if (result == FS_NO_ERROR)
    {
        mmi_vobj_get_full_path_name(0, (CHAR*)path, MMI_VOBJ_UNRECOGNIZED);
        result = mmi_vobj_fs_check_path(path, MMI_FALSE);
    }

    OslMfree(path);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_check_curr_file_type
 * DESCRIPTION
 *  get current type of file
 * PARAMETERS
 *  void
 * RETURNS
 *  enum value of type
 *****************************************************************************/
vobj_object_type_enum mmi_vobj_check_curr_file_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vobj_cntx.obj_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_delete_tmp_path
 * DESCRIPTION
 *  This function is to generate full file path and name to store
 *  vCard and vCalendar objects from the network.
 * PARAMETERS
 *  index       [IN]            Sequence number of the object
 *  result      [IN/OUT]        String buffer to store the result path and name
 *  type        [OUT]            Type of the object, vCard/vCalendar
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_delete_tmp_path(U16 index, vobj_object_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR path[VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH];
    FS_HANDLE fh;
    FS_DOSDirEntry file_info;
    WCHAR filename[VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (type == MMI_VOBJ_VCARD)
	{
		kal_wsprintf(path, "%c:\\%s\\%d.vcf", VOBJ_DRV, (CHAR*) VOBJ_FILE_PATH, index);
	}
	else if (type == MMI_VOBJ_VCLNDR)
	{
		kal_wsprintf(path, "%c:\\%s\\%d.vcs", VOBJ_DRV, (CHAR*) VOBJ_FILE_PATH, index);
	}
#ifdef __MMI_VBOOKMARK__
	else if (type == MMI_VOBJ_VBKM)
	{
		kal_wsprintf(path, "%c:\\%s\\%d.vbm", VOBJ_DRV, (CHAR*) VOBJ_FILE_PATH, index);
	}
#endif /* __MMI_VBOOKMARK__ */ 
	else
	{
		kal_wsprintf(path, "%c:\\%s\\", VOBJ_DRV, (CHAR*) VOBJ_FILE_PATH);
	}

//    kal_wsprintf(path, "%c:\\%s\\%d.?*", VOBJ_DRV, (CHAR*)VOBJ_FILE_PATH, index);

    if ((fh = FS_FindFirst(path, 0, 0, &file_info, (U16*) filename, VOBJ_MAX_PATH_LENGTH)) >= 0)
    {
        /* Loop through all file with different extension. */
        do
        {
            kal_wsprintf(path, "%c:\\%s\\%w", VOBJ_DRV, (CHAR*)VOBJ_FILE_PATH, (CHAR*)filename);
            FS_Delete(path);
        } while (FS_FindNext(fh, &file_info, (U16*) filename, VOBJ_MAX_PATH_LENGTH) == FS_NO_ERROR);
    }
    FS_FindClose(fh);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_search_tmp_path
 * DESCRIPTION
 *  This function is to generate full file path and name to store
 *  vCard and vCalendar objects from the network.
 * PARAMETERS
 *  index       [IN]            Sequence number of the object
 *  result      [IN/OUT]        String buffer to store the result path and name
 *  type        [OUT]            Type of the object, vCard/vCalendar
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_vobj_search_tmp_path(U16 index, WCHAR *result, vobj_object_type_enum* type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR path[VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH];
    FS_HANDLE fh;
    FS_DOSDirEntry file_info;
    WCHAR filename[VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(path, "%c:\\%s\\%d.?*", VOBJ_DRV, (CHAR*)VOBJ_FILE_PATH, index);

    if ((fh = FS_FindFirst(path, 0, 0, &file_info, (U16*) filename, VOBJ_MAX_PATH_LENGTH)) >= 0)
    {
        /* Loop through all file with different extension. */
        do
        {
            /* filter out folder results */
            if (!(file_info.Attributes & FS_ATTR_DIR))
            {
                switch (srv_fmgr_types_find_type_by_filename_str((WCHAR*)filename))
                {
                #ifdef __MMI_VCARD__
                    case FMGR_TYPE_VCF:
                        *type = MMI_VOBJ_VCARD;
                        goto success;
                #endif
                #ifdef __MMI_VCALENDAR__
                    case FMGR_TYPE_VCS:
                        *type = MMI_VOBJ_VCLNDR;
                        goto success;
                #endif
                #ifdef __MMI_VBOOKMARK__
                    case FMGR_TYPE_URL:
                    case FMGR_TYPE_VBM:
                        *type = MMI_VOBJ_VBKM;
                        goto success;
                #endif /* __MMI_VBOOKMARK__ */

                    default:
                        break;
                }

            }
        } while (FS_FindNext(fh, &file_info, (U16*) filename, VOBJ_MAX_PATH_LENGTH) == FS_NO_ERROR);
    }
    FS_FindClose(fh);
    return MMI_FALSE;
    
success:
    kal_wsprintf(result, "%c:\\%s\\%w", VOBJ_DRV, (CHAR*)VOBJ_FILE_PATH, (CHAR*)filename);
    FS_FindClose(fh);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_get_full_path_name
 * DESCRIPTION
 *  This function is to generate full file path and name to store
 *  vCard and vCalendar objects from the network.
 * PARAMETERS
 *  index       [IN]            Sequence number of the object
 *  result      [IN/OUT]        String buffer to store the result path and name
 *  type        [IN]            Type of the object, vCard/vCalendar
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_get_full_path_name(U16 index, CHAR *result, vobj_object_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == MMI_VOBJ_VCARD)
    {
        kal_wsprintf((WCHAR*)result, "%c:\\%s\\%d.vcf", VOBJ_DRV, (CHAR*) VOBJ_FILE_PATH, index);
    }
    else if (type == MMI_VOBJ_VCLNDR)
    {
        kal_wsprintf((WCHAR*)result, "%c:\\%s\\%d.vcs", VOBJ_DRV, (CHAR*) VOBJ_FILE_PATH, index);
    }
#ifdef __MMI_VBOOKMARK__
    else if (type == MMI_VOBJ_VBKM)
    {
        kal_wsprintf((WCHAR*)result, "%c:\\%s\\%d.vbm", VOBJ_DRV, (CHAR*) VOBJ_FILE_PATH, index);
    }
#endif /* __MMI_VBOOKMARK__ */ 
    else
    {
        kal_wsprintf((WCHAR*)result, "%c:\\%s\\", VOBJ_DRV, (CHAR*) VOBJ_FILE_PATH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_fmgr_use_enabler
 * DESCRIPTION
 *  Forward a vCalendar object from file manager via SMS
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_fmgr_use_enabler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (srv_sms_is_hide_send_sms_menu_item())
    {
        mmi_frm_hide_menu_item(MENU_ID_VOBJ_FMGR_SEND_SMS);
        return;
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_fmgr_use_handler
 * DESCRIPTION
 *  Forward a vCalendar object from file manager via SMS
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vobj_fmgr_use_handler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_fmgr_types_query_fileinfo(&info);
    
#ifdef __MMI_VCARD__
    if (info.type == FMGR_TYPE_VCF)
    {
        mmi_vcard_fmgr_sms_forward((CHAR*)filepath);
        return;
    }
#endif /* __MMI_VCARD__ */
#ifdef __MMI_VCALENDAR__
    if (info.type == FMGR_TYPE_VCS)
    {
        mmi_vcal_fmgr_sms_forward((CHAR*)filepath);
        return;
    }
#endif /* __MMI_VCALENDAR__ */
#if defined (__MMI_VBOOKMARK__ ) && defined(__MMI_BRW_BOOKMARK_IN_FMGR__)
    if (info.type == FMGR_TYPE_URL || info.type == FMGR_TYPE_VBM)
    {
        mmi_vbkm_fmgr_sms_forward((CHAR*)filepath);
        return;
    }
#endif /* #if defined (__MMI_VBOOKMARK__ ) && defined(__MMI_BRW_BOOKMARK_IN_FMGR__) */
}


#define VOBJ_UTILITY


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_uti_strnicmp
 * DESCRIPTION
 *  Convert a charcater to lower case
 * PARAMETERS
 *  src         [IN]        String pointer to be compared
 *  dest        [IN]        String pointer to be compared
 *  maxlen      [IN]        Lengh to be compared
 * RETURNS
 *  Ture if two string is identical, otherwise, false
 *****************************************************************************/
CHAR mmi_vobj_uti_strnicmp(CHAR *src, CHAR *dest, S32 maxlen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ch1, ch2;
    CHAR *s1, *s2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s1 = src;
    s2 = dest;

    while (maxlen-- > 0)
    {
        ch1 = tolower(*s1++);
        ch2 = tolower(*s2++);
        if (ch1 != ch2)
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_uti_get_value
 * DESCRIPTION
 *  Get the string after ":"
 * PARAMETERS
 *  strString       [IN]        Input string.
 * RETURNS
 *  pointer to the starting point after ":"
 *****************************************************************************/
CHAR *mmi_vobj_uti_get_value(CHAR *strString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strstr(strString, (CHAR*) VOBJ_VALUE_SEP_STR) != NULL)
    {
        return (CHAR*) (strstr(strString, (CHAR*) VOBJ_VALUE_SEP_STR) + 1);
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_uti_cmp_filed
 * DESCRIPTION
 *  Check if the string constains a filed.
 * PARAMETERS
 *  srcString       [IN]        Source string to be compared.
 *  refString       [IN]        Header of the filed
 * RETURNS
 *  TRUE if string exists, otherwise FALSE.
 *****************************************************************************/
U8 mmi_vobj_uti_cmp_filed(CHAR *srcString, const CHAR *refString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 refLen, srcLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srcLen = strlen(srcString);
    refLen = strlen(refString);

    if (srcLen < refLen)
    {
        return FALSE;
    }
    if (mmi_vobj_uti_strnicmp(srcString, (CHAR*) refString, refLen))
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

#endif /* defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) */ /* END #if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) */

#endif /* _MMI_VOBJECTS_C */ /* END #define _MMI_VOBJECTS_C */

