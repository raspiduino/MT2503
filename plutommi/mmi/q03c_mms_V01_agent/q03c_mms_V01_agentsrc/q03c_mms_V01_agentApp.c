/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 * q03c_mms_v01_agentApp.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#if defined(OBIGO_Q03C_MMS_V01)

#include "mmi_frm_gprot.h"
#include "mms_adp_struct.h"
#include "CommonScreens.h"
#include "app_asyncfile.h"
#include "profileGprots.h"
#include "app_str.h"


#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
#include "mma_struct.h"
#include "mma_sap.h"
#include "mma_api.h"
#include "mms_sap_struct.h"
#endif


#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif
#ifndef __UNIFIED_COMPOSER_SUPPORT__
#ifdef __MMI_BACKGROUND_CALL__
#include  "UCMGProt.h"
#endif 
#include "UcmSrvGprot.h" /*isInCall*/
#endif

#ifdef __WIFI_SUPPORT__
/* WLAN includes */
#include "NetworkSetupDefs.h"
#endif /* __WIFI_SUPPORT__ */ 

#include "conversions.h"
#include "custom_wap_config.h"
/*mms_api.h*/
#include "mms_api.h"
/* For Engineer mode */
#include "EngineerModeInetAppGprot.h"
#include "q03c_mms_V01_agentprot.h"
#include "q03c_mms_V01_agentResDef.h"
#include "q03c_mms_V01_agentSettings.h"
#ifdef __MMI_URI_AGENT__
#include "URIAgentGProt.h"
#endif /*#ifdef __MMI_URI_AGENT__*/

#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "UMGProt.h"
#include "UcAppGprot.h"
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 

#ifdef __MMI_MMS_BGSR_SUPPORT__
#include "MMSBGSRGProt.h"
#endif

#ifdef __DRM_SUPPORT__
#include "drm_def.h"
#include "drm_gprot.h"

#endif /* __DRM_SUPPORT__ */ 

#include "med_global.h"

#include "mea_api.h"

#ifdef __MMI_MMS_V01_USE_ASM__
#include "app_mem.h"
#endif 

/*******************************************************************************
 * Global Variable
 *******************************************************************************/

#ifdef MEA_CFG_WARNING_MODE_SUPPORT
typedef struct
{
    mms_content_entry_struct data;
} warning_mode_cntx_struct;

warning_mode_cntx_struct *g_warning_inst = NULL;
#endif  /*MEA_CFG_WARNING_MODE_SUPPORT*/

/*******************************************************************************
 * Extern declaration
 *******************************************************************************/
extern mmi_mms_v01_agent_context_struct g_mmi_mms_V01_agent_ctx;
extern void goto_mms_editor(mms_content_entry_struct *data);

/* For widget APIs */
extern void HDIa_widgetExtEntryVirtualWidgetScreen(U16 scrnID);
extern void HDIa_widgetExtDisplayTransitionAnimationNoEnd(kal_bool is_MMS);
/* Used only for URI*/
extern void HDIa_widgetExtDisplayMMSTransitionAnimation(void);
extern int mmi_bootup_get_active_flight_mode(void);
#ifndef __MMI_MMS_DUAL_SIM__
    extern int mmi_bootup_is_sim_valid(void);
#endif 
#ifdef __WIFI_SUPPORT__
    extern U8 mmi_netset_get_active_preferred_mode(void);
#endif 

extern kal_uint16 widget_get_mms_screen_id(void);

#ifdef __MMI_BROWSER_2__
extern MMI_BOOL mmi_brw_is_browser_active(void);
#endif /* __MMI_BROWSER_2__ */

/*******************************************************************************
 * Functions
 *******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mms_is_ready
 * DESCRIPTION
 *  The function is used to check if mms application is ready
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int mms_is_ready()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret_val = 0;

    /*----------------------------------------------------------------*/
    /* extern declaration                                             */
    /*----------------------------------------------------------------*/

    extern kal_uint16 wap_get_screen_id(void);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_val = (mea_mmsV01_agent_is_wap_ready() && (!IsScreenPresent(wap_get_screen_id()) && !IsScreenPresent(widget_get_mms_screen_id())) &&
               /*                                  *
                   widget screen can't be re-entry *
                                                   */
#ifdef __MMI_BROWSER_2__
                !mmi_brw_is_browser_active() &&
#endif /* __MMI_BROWSER_2__ */
#ifndef __MMI_MMS_IN_UM__
#ifdef __MMI_BACKGROUND_CALL__
               (!srv_ucm_is_background_call() || !IsScreenPresent((mmi_ucm_app_get_intermediate_marker_scrn_id()))) &&
#else 
               !(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0) &&
#endif 
#endif /* __MMI_MMS_IN_UM__ */ 
               /*                                                                      *
                   if not defined Uuified Message, because widget screen will check if it's in call *
                   and if it's in call, widget won't show anything                     *
                   so we wiil check if it's in call when not defined Unified Message or UC                *
                                                                                       */
               mmi_bootup_get_active_flight_mode() == 0 &&
#ifndef __MMI_MMS_DUAL_SIM__
               mmi_bootup_is_sim_valid()
#else 
               (g_mmi_mms_V01_agent_ctx.is_sim1_valid || g_mmi_mms_V01_agent_ctx.is_sim2_valid)
#endif /* __MMI_WAP_DUAL_SIM__ */
#ifdef __WIFI_SUPPORT__
               && mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY
#endif 
#ifdef __MMI_MMS_IN_UM__
               && mmi_um_check_ready()
#endif 
        );

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_MMS_IS_READY, ret_val);

    return ret_val;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_send_mea_startup_req
 * DESCRIPTION
 *  This function is used to send the startup primitive to MEA (WAP Task)
 * PARAMETERS
 *  new_mms_data_cntx_struct
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_send_mea_startup_req(new_mms_data_cntx_struct *temp_data)
{
    ilm_struct *ilm_ptr = NULL;

    switch(temp_data->startup_mode)
    {
        case MMI_MMSV01_AGENT_STARTUP_MODE_EDITOR:
         {
            mms_content_entry_struct *data = &temp_data->data.editor_data;
            switch (data->mode)
            {
                case MMS_NEW_GENERAL:
                case MMS_NEW_FILE:
                {
                    mea_new_mms_req_struct *p = NULL;
                    peer_buff_struct *peer_buff_ptr = NULL;
                    mms_content_entry_struct_peer_buf *peer_pdu = NULL;
                    kal_int16 buffer_size = 0;
                    kal_int16 peer_pdu_len = 0;                    

                    p = (mea_new_mms_req_struct*) construct_local_para((kal_uint16) sizeof(mea_new_mms_req_struct), TD_RESET);
                    ilm_ptr = allocate_ilm(MOD_MMI);
                    ilm_ptr->msg_id = MSG_ID_MEA_STARTUP_NEW_MMS_REQ;
                    p->mode = data->mode;
                    p->funcPtr = (void*)data->callback;
                    p->funcParam = data->callback_param;

                    if (data->mode == MMS_NEW_GENERAL)
                    {
                        if (app_ucs2_strlen((const kal_int8*)data->subject) > MEA_MAX_SUBJECT_LENGTH ||
                            app_ucs2_strlen((const kal_int8*)data->text_buffer) > MEA_MAX_TEXT_LENGTH)
                        {
                            p->isContentTruncated = TRUE;
                        }
                        else
                        {
                            p->isContentTruncated = FALSE;
                        }

                        buffer_size = 2000;
                        peer_buff_ptr = construct_peer_buff(buffer_size, 0, 0, TD_RESET);
                        peer_pdu =
                            (mms_content_entry_struct_peer_buf*) get_pdu_ptr(peer_buff_ptr, (kal_uint16*) & peer_pdu_len);
                        ASSERT(peer_pdu_len == buffer_size);
                        memset(peer_pdu, 0x00, sizeof(mms_content_entry_struct_peer_buf));
                        if (peer_pdu)
                        {
                            if (data->subject != NULL)
                            {
                                buffer_size = MMS_MAX_ENCODE_SUBJECT_LENGTH/ENCODING_LENGTH - ENCODING_LENGTH;    /* 82 */
                                app_ucs2_strncpy((kal_int8*) peer_pdu->subject, (const kal_int8*)data->subject, buffer_size);
                            }

                            if (data->text_buffer != NULL)
                            {
                                buffer_size = MMS_MAX_ENCODE_TEXT_LENGTH/ENCODING_LENGTH - ENCODING_LENGTH;       /* 1226 */
                                app_ucs2_strncpy(
                                    (kal_int8*) peer_pdu->text_buffer,
                                    (const kal_int8*)data->text_buffer,
                                    buffer_size);
                            }
                            if (data->addr != NULL)
                            {
                                buffer_size = MMS_MAX_ENCODE_ADDRESS_LENGTH/ENCODING_LENGTH - ENCODING_LENGTH;    /* 122 */
                                app_ucs2_strncpy((kal_int8*) peer_pdu->addr, (const kal_int8*)data->addr, buffer_size);
                            }
                        }
                    }

                    if (data->file_path != NULL)
                    {
                        app_ucs2_strcpy((kal_int8*) p->commandInfo, (const kal_int8*)data->file_path);
                    }
                    ilm_ptr->msg_id = MSG_ID_MEA_STARTUP_NEW_MMS_REQ;
#ifdef __MMI_MMS_V01_USE_ASM__
                    p->asm_pool_id = g_mmi_mms_V01_agent_ctx.asm_pool_id;
#endif 

                    ilm_ptr->peer_buff_ptr = peer_buff_ptr;
                    ilm_ptr->local_para_ptr = (local_para_struct*) p;
                    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

                    HDIa_widgetExtDisplayTransitionAnimationNoEnd(KAL_TRUE);
                    HDIa_widgetExtEntryVirtualWidgetScreen(GetExitScrnID());

                    break;
                }

                case MMS_NEW_ADDRESS:
                {
                    mea_new_mms_req_struct *p = NULL;

                    HDIa_widgetExtDisplayTransitionAnimationNoEnd(KAL_TRUE);
                    p = (mea_new_mms_req_struct*) construct_local_para((kal_uint16) sizeof(mea_new_mms_req_struct), 0);

                    ilm_ptr = allocate_ilm(MOD_MMI);
                    ilm_ptr->msg_id = MSG_ID_MEA_STARTUP_NEW_MMS_REQ;
#ifdef __MMI_MMS_V01_USE_ASM__
                    p->asm_pool_id = g_mmi_mms_V01_agent_ctx.asm_pool_id;
#endif 
                    p->mode = MMS_NEW_ADDRESS;
                    app_ucs2_strcpy((kal_int8*) p->commandInfo, (const kal_int8*)data->addr);

                    ilm_ptr->peer_buff_ptr = NULL;
                    ilm_ptr->local_para_ptr = (local_para_struct*) p;
                    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
                    break;
                }

                case MMS_NEW_BUFFER:
                {
                    mea_new_mms_req_struct *local_para_ptr = NULL;
                    peer_buff_struct *peer_buff_ptr = NULL;
                    kal_uint8 *peer_pdu = NULL;
                    kal_uint16 buffer_size = 0;
                    kal_uint16 peer_pdu_len = 0;

                    /* Should replace with mmi specific */
                    HDIa_widgetExtDisplayTransitionAnimationNoEnd(KAL_TRUE);

                    /* Set the screen that wants to enter the widget screen */
                    HDIa_widgetExtEntryVirtualWidgetScreen(GetExitScrnID());    /* sanjeev patch */

                    local_para_ptr = (mea_new_mms_req_struct*)
                        construct_local_para((kal_uint16) sizeof(mea_new_mms_req_struct), TD_RESET);

                    ilm_ptr = allocate_ilm(MOD_MMI);
                    ilm_ptr->msg_id = MSG_ID_MEA_STARTUP_NEW_MMS_REQ;
                    local_para_ptr->mode = MMS_NEW_BUFFER;
                    if (data->subject && app_ucs2_strlen((const kal_int8*)data->text_buffer))
                    {
                        if (app_ucs2_strlen((const kal_int8*)data->subject) > MEA_MAX_SUBJECT_LENGTH ||
                            app_ucs2_strlen((const kal_int8*)data->text_buffer) > MEA_MAX_TEXT_LENGTH)
                        {
                            local_para_ptr->isContentTruncated = TRUE;
                        }
                        else
                        {
                            local_para_ptr->isContentTruncated = FALSE;
                        }

                        buffer_size = MEA_MAX_SUBJECT_LENGTH * ENCODING_LENGTH + ENCODING_LENGTH;       /* 82 */
                        app_ucs2_strncpy(
                            (kal_int8*) local_para_ptr->commandInfo,
                            (const kal_int8*)data->subject,
                            MEA_MAX_SUBJECT_LENGTH);
                    }

                    buffer_size = MEA_MAX_TEXT_LENGTH * ENCODING_LENGTH + ENCODING_LENGTH;      /* 1226 */
                    peer_buff_ptr = (peer_buff_struct*) construct_peer_buff(buffer_size, 0, 0, TD_CTRL);
                    peer_pdu = (kal_uint8*) get_pdu_ptr(peer_buff_ptr, (kal_uint16*) & peer_pdu_len);
                    if (peer_pdu)
                    {
                        app_ucs2_strncpy((kal_int8*) peer_pdu, (const kal_int8*)data->text_buffer, MEA_MAX_TEXT_LENGTH);
                    }

                    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;
#ifdef __MMI_MMS_V01_USE_ASM__
                   local_para_ptr->asm_pool_id = g_mmi_mms_V01_agent_ctx.asm_pool_id;
#endif 
                    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
                    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
                    break;
                }
            #ifdef __MMI_URI_AGENT__
                case MMS_NEW_URI:
                {
                    mea_new_mms_req_struct *local_para_ptr = NULL;
                    peer_buff_struct *peer_buff_ptr = NULL;
                    kal_uint8 *peer_pdu = NULL;
                    kal_uint16 buffer_size = 0, peer_pdu_len = 0;

                   // HDIa_widgetExtDisplayTransitionAnimationNoEnd(KAL_TRUE);
                    HDIa_widgetExtDisplayMMSTransitionAnimation();
                    HDIa_widgetExtEntryVirtualWidgetScreen(GetExitScrnID());

                    local_para_ptr = (mea_new_mms_req_struct*)
                        construct_local_para((kal_uint16) sizeof(mea_new_mms_req_struct), 0);

                    ilm_ptr = allocate_ilm(MOD_MMI);
                    ilm_ptr->msg_id = MSG_ID_MEA_STARTUP_NEW_MMS_REQ;
                    local_para_ptr->mode = MMS_NEW_URI;

                    buffer_size = MEA_MAX_TEXT_LENGTH * ENCODING_LENGTH + ENCODING_LENGTH;      /* 1226 */
                    peer_buff_ptr = (peer_buff_struct*) construct_peer_buff(buffer_size, 0, 0, TD_CTRL);
                    peer_pdu = (kal_uint8*) get_pdu_ptr(peer_buff_ptr, &peer_pdu_len);
                    if (peer_pdu)
                    {
                        strncpy((char*)peer_pdu, (char*)data->text_buffer, buffer_size);
                    }

                    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;
#ifdef __MMI_MMS_V01_USE_ASM__
                   local_para_ptr->asm_pool_id = g_mmi_mms_V01_agent_ctx.asm_pool_id;
#endif           
                    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
                    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
                    break;

                }
            #endif /* __MMI_URI_AGENT__ */ /* #ifdef __MMI_URI_AGENT__ */
                default:
                   {
                        ASSERT(0);
                        break;
                   }
                }
                
             }
             break;

        case MMI_MMSV01_AGENT_STARTUP_MODE_FOLDER:
            {
                /* TODO:: Rahul Add log here*/
                mea_startup_req_struct *req = NULL;
                req = (mea_startup_req_struct*) construct_local_para((kal_uint16) sizeof(mea_startup_req_struct), TD_CTRL);

                req->folder_id = MEA_FOLDER_NONE;
#ifdef __MMI_MMS_V01_USE_ASM__
                req->asm_pool_id = g_mmi_mms_V01_agent_ctx.asm_pool_id;
#endif 

                ilm_ptr = allocate_ilm(MOD_MMI);
                ilm_ptr->msg_id = MSG_ID_MEA_STARTUP_REQ;
                ilm_ptr->peer_buff_ptr = NULL;
                ilm_ptr->local_para_ptr = (local_para_struct*)req;
                SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
                HDIa_widgetExtDisplayTransitionAnimationNoEnd(KAL_TRUE);

            }
            break;
        case MMI_MMSV01_AGENT_STARTUP_MODE_INBOX:
            {
                mea_startup_req_struct *req = NULL;
                req = (mea_startup_req_struct*) construct_local_para((kal_uint16) sizeof(mea_startup_req_struct), TD_CTRL);

                req->folder_id = MEA_FOLDER_INBOX;
#ifdef __MMI_MMS_V01_USE_ASM__
                req->asm_pool_id = g_mmi_mms_V01_agent_ctx.asm_pool_id;
#endif

                ilm_ptr = allocate_ilm(MOD_MMI);
                ilm_ptr->msg_id = MSG_ID_MEA_STARTUP_REQ;
                ilm_ptr->peer_buff_ptr = NULL;
                ilm_ptr->local_para_ptr = (local_para_struct*)req;
                SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
                HDIa_widgetExtDisplayTransitionAnimationNoEnd(KAL_TRUE);
            }

            break;
        default:
            ASSERT(0);  /*For erroneous condition*/
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  goto_mms_screen
 * DESCRIPTION
 *  MMS entry point from MMI menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* Executed in MMI task */
void goto_mms_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_DUAL_SIM__
    extern int mmi_bootup_is_sim_valid(void);
#endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_GOTO_MMS_SCREEN);

#ifndef __MMI_MMS_DUAL_SIM__
    if(!mmi_bootup_is_sim_valid())
#else 
    if (!g_mmi_mms_V01_agent_ctx.is_sim1_valid && !g_mmi_mms_V01_agent_ctx.is_sim2_valid)
#endif /* __MMI_WAP_DUAL_SIM__ */
    {
        mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        return;
    }
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())   /* Check if MMS should be disabled */
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_IN_USB_MODE);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (!mea_mmsV01_agent_is_wap_ready()
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
        || g_mmi_mms_V01_agent_ctx.cvm_state != MMI_MMSV01_AGENT_CVM_STATE_NONE
#endif
        )
    {
        mmi_mmsv01_agent_wap_not_ready();
        return;
    }

    /* Disable key to prevent sending duplicated requests */
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

#ifndef __MMI_MMS_IN_UM__
    if (mea_mmsV01_agent_is_mea_running())
    {
        /* 
         * Abnormal case:
         * History node of MEA is deleted by someone, and users enter MMS menu again.
         */
        ilm_struct *ilm_ptr = NULL;

        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_GOTO_MMS_SCREEN_AND_MEA_RUNNING);

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_SHUTDOWN_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
        SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
#ifdef __MMI_MMS_V01_USE_ASM__
       if (mmi_mmsV01_agent_asm_pool_init())
#endif
        {
           new_mms_data_cntx_struct temp_data = {0,};

           MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_CALL_MEA_START_UP_REQ);
           temp_data.startup_mode = MMI_MMSV01_AGENT_STARTUP_MODE_FOLDER;
           mmi_mmsv01_agent_send_mea_startup_req(&temp_data);
        }
#ifdef __MMI_MMS_V01_USE_ASM__
        else
        {
            /* Save the current context in globals here */
            MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_SAVE_TEMP_CONTENT);
            mmi_mmsv01_agent_set_startup_mode_instance(NULL, MMI_MMSV01_AGENT_STARTUP_MODE_FOLDER);
        }
#endif
    }
    else
#endif /* __MMI_MMS_IN_UM__ */ 
    {
#ifdef __MMI_MMS_V01_USE_ASM__    
       if (mmi_mmsV01_agent_asm_pool_init())
        {
#endif
           new_mms_data_cntx_struct temp_data = {0,};

           MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_CALL_MEA_START_UP_REQ);
           temp_data.startup_mode = MMI_MMSV01_AGENT_STARTUP_MODE_FOLDER;
           mmi_mmsv01_agent_send_mea_startup_req(&temp_data);
#ifdef __MMI_MMS_V01_USE_ASM__

        }
        else
        {
            /* Save the current context in globals here */
            MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_SAVE_TEMP_CONTENT);
            mmi_mmsv01_agent_set_startup_mode_instance(NULL, MMI_MMSV01_AGENT_STARTUP_MODE_FOLDER);
        }
#endif /* __MMI_MMS_V01_USE_ASM__*/        
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mms_text_insert_hdlr
 * DESCRIPTION
 *  Start MEA in editor mode or UC with a text buffer (and subject) inserted
 * CALLS
 *  
 * PARAMETERS
 *  subject         [IN]        
 *  subject_len     [IN]        
 *  text            [IN]        
 *  text_len        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_text_insert_hdlr(char *subject, unsigned int subject_len, char *text, unsigned int text_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_TEXT_INSERT_HDLR);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_IN_USB_MODE);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (!mms_is_ready())
    {
        mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        return;
    }

#ifdef __UNIFIED_COMPOSER_SUPPORT__
    {
        mmi_uc_entry_write_struct data;

        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
        data.subject = (kal_uint8*) subject;
        data.text_buffer = (kal_uint8*) text;
        data.text_num = text_len;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
        return;
    }
#else /* __UNIFIED_COMPOSER_SUPPORT__ */ 
    {
        mms_content_entry_struct data;

        memset(&data, 0x00, sizeof(mms_content_entry_struct));
        data.mode = MMS_NEW_BUFFER;
        data.subject = subject;
        data.text_buffer = text;
        goto_mms_editor(&data);
    }
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mms_content_insert_hdlr
 * DESCRIPTION
 *  Start MEA in editor with a file inserted
 * CALLS
 *  
 * PARAMETERS
 *  content_source      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_content_insert_hdlr(char *content_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_CONTENT_INSERT_HDLR);
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_IN_USB_MODE);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (!mms_is_ready())
    {
        mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        return;
    }

#ifdef __UNIFIED_COMPOSER_SUPPORT__
    {
        mmi_uc_entry_write_struct data;

        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
        data.file_path = (kal_uint8*) content_source;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
        return;
    }
#else /* __UNIFIED_COMPOSER_SUPPORT__ */ 
    {
        mms_content_entry_struct data;

        memset(&data, 0x00, sizeof(mms_content_entry_struct));
        data.mode = MMS_NEW_FILE;
        data.file_path = content_source;
        goto_mms_editor(&data);
    }
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mms_content_insert_hdlr_with_callback
 * DESCRIPTION
 *  Start MMS editor with the specified content. A callback function is provided so that MMS editor
 *  can evoke the function when work is done.
 * CALLS
 *  
 * PARAMETERS
 *  entry_data      [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mms_content_insert_hdlr_with_callback(mms_content_entry_struct *entry_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_CONTENT_INSERT_HDLR_WITH_CALLBACK);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_IN_USB_MODE);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (!mms_is_ready())
    {
        mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        if (entry_data && entry_data->callback)
        {
            entry_data->callback(entry_data->callback_param);
        }
        return;
    }

#ifdef __UNIFIED_COMPOSER_SUPPORT__
    {
        mmi_uc_entry_write_struct data;

        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
        data.file_path = (kal_uint8*) entry_data->file_path;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        data.callback = entry_data->callback;
        data.callback_para = entry_data->callback_param;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
        return;
    }
#else /* __UNIFIED_COMPOSER_SUPPORT__ */ 
    {
        goto_mms_editor(entry_data);
    }
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mms_address_insert_hdlr
 * DESCRIPTION
 *  Start MMS in editor with a file inserted
 * CALLS
 *  
 * PARAMETERS
 *  address     [IN]        Phone number to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void mms_address_insert_hdlr(char *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_ADDRESS_INSERT_HDLR);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_IN_USB_MODE);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (!mms_is_ready())
    {
        mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        return;
    }

    {
        int size = 0;
        char *strAddress = NULL;

        size = mmi_charset_ucs2_to_utf8_length_in_bytes((const kal_uint8*)address) + 1;
        strAddress = OslMalloc(size + 1);
        mmi_chset_ucs2_to_utf8_string((kal_uint8*) strAddress, size + 1, (kal_uint8*) address);

        if (mea_mmsV01_agent_get_valid_addr_type(strAddress) == MEA_ADDR_TYPE_NONE)
        {
            mmi_display_popup((UI_string_type) GetString(STR_ID_MMSV01_AGENT_INVALID_RECIP_ADDRESS), MMI_EVENT_FAILURE);

            return;
        }
        /* Deallocate the address string */
        if (strAddress)
        {
            OslMfree(strAddress);
        }
    }

#ifdef __UNIFIED_COMPOSER_SUPPORT__
    {
        mmi_uc_entry_write_struct data;
        mmi_uc_addr_struct addr;

        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
        memset(&addr, 0x00, sizeof(mmi_uc_addr_struct));
        data.addr_num = 1;
        addr.addr = (kal_uint8*) address;
        if (mmi_ucs2chr(address, L'@') == NULL)
        {
            addr.type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
        }
        else
        {
            addr.type = MMI_UC_ADDRESS_TYPE_EMAIL;
        }
        addr.group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
        data.addr = &addr;
        data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
        return;
    }
#else /* __UNIFIED_COMPOSER_SUPPORT__ */ 
    {
        mms_content_entry_struct data;

        memset(&data, 0x00, sizeof(mms_content_entry_struct));
        data.mode = MMS_NEW_ADDRESS;
        data.addr = address;
        goto_mms_editor(&data);
    }
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
}

#ifdef __UNIFIED_COMPOSER_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mms_uc_address_insert_hdlr
 * DESCRIPTION
 *  Start MMS in editor with a file inserted
 * CALLS
 *  
 * PARAMETERS
 *  address     [IN]        Phone number to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void mms_uc_address_insert_hdlr(char *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_UC_ADDRESS_INSERT_HDLR);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_IN_USB_MODE);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    {
        mmi_uc_entry_write_struct data;
        mmi_uc_addr_struct addr;

        memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
        memset(&addr, 0x00, sizeof(mmi_uc_addr_struct));
        data.addr_num = 1;
        addr.addr = (kal_uint8*) address;
        if (mmi_ucs2chr(address, L'@') == NULL)
        {
            addr.type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
        }
        else
        {
            addr.type = MMI_UC_ADDRESS_TYPE_EMAIL;
        }
        addr.group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
        data.addr = &addr;
        data.msg_type = MMI_UC_MSG_TYPE_DEFAULT;
        data.info_type = MMI_UC_INFO_TYPE_MMS;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
    }
}
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mms_general_insert_hdlr
 * DESCRIPTION
 *  Start MMS in editor with a mms_content_entry_struct is filled
 * CALLS
 *  
 * PARAMETERS
 *  data        [IN]        The mms_content_entry_struct data
 * RETURNS
 *  void
 *****************************************************************************/
void mms_general_insert_hdlr(mms_content_entry_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_GENERAL_INSERT_HDLR);
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {

        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_IN_USB_MODE);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (!mms_is_ready())
    {
        mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        if (data && data->callback)
        {
            data->callback(data->callback_param);
        }
        return;
    }

    if (data->addr != NULL)
    {
        int size;
        char *strAddress;

        size = mmi_charset_ucs2_to_utf8_length_in_bytes((const kal_uint8*)data->addr) + 1;
        strAddress = OslMalloc(size + 1);

        mmi_chset_ucs2_to_utf8_string((kal_uint8*) strAddress, size + 1, (kal_uint8*) data->addr);

        if (mea_mmsV01_agent_get_valid_addr_type(strAddress) == MEA_ADDR_TYPE_NONE)
        {
            mmi_display_popup((UI_string_type) GetString(STR_ID_MMSV01_AGENT_INVALID_RECIP_ADDRESS), MMI_EVENT_FAILURE);

            return;
        }
    }

#ifdef __UNIFIED_COMPOSER_SUPPORT__
    {
        mmi_uc_entry_write_struct uc_data;
        mmi_uc_addr_struct addr;

        memset(&uc_data, 0x00, sizeof(mmi_uc_entry_write_struct));
        memset(&addr, 0x00, sizeof(mmi_uc_addr_struct));

        uc_data.callback = data->callback;
        uc_data.callback_para = data->callback_param;
        uc_data.subject = (kal_uint8*) data->subject;
        uc_data.text_buffer = (kal_uint8*) data->text_buffer;
        uc_data.text_num = mmi_charset_ucs2_to_utf8_length_in_bytes((kal_uint8*) data->text_buffer);
        uc_data.file_path = (kal_uint8*) data->file_path;
        if (data->addr != NULL)
        {
            uc_data.addr_num = 1;
            addr.addr = (kal_uint8*) data->addr;
            if (mmi_ucs2chr(data->addr, L'@') == NULL)
            {
                addr.type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
            }
            else
            {
                addr.type = MMI_UC_ADDRESS_TYPE_EMAIL;
            }
            addr.group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
            uc_data.addr = &addr;
        }

        uc_data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        uc_data.info_type = MMI_UC_INFO_TYPE_MMS;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &uc_data);
        return;
    }
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
    data->mode = MMS_NEW_GENERAL;
    goto_mms_editor(data);
}


/*****************************************************************************
 * FUNCTION
 *  mms_is_content_forward
 * DESCRIPTION
 *  The function is used to check if the media can be forwarded to MMS
 * PARAMETERS
 *  filename        [IN]        Encoded by UCS2
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int mms_is_content_forward(const char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mms_is_file_can_be_forwarded_to_mms(filename);
}

#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
 * FUNCTION
 *  mms_on_enter_usb_mode
 * DESCRIPTION
 *  This function is invoked when entering USB mode. When WAP MMS is ready
 *  send MSG_ID_MMS_ENTER_USB_MODE_RSP to MMI.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_on_enter_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_ENTER_USB_MODE_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mms_on_exit_usb_mode
 * DESCRIPTION
 *  This function is invoked when leaving USB mode. When WAP MMS is ready
 *  send MSG_ID_MMS_EXIT_USB_MODE_RSP to MMI.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_on_exit_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_EXIT_USB_MODE_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}
#endif /* __USB_IN_NORMAL_MODE__ */ 



/*****************************************************************************
 * FUNCTION
 *  mms_get_content_class
 * DESCRIPTION
 *  This function is used to get mms content class
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  wap_mms_content_class_enum
 *****************************************************************************/
mms_content_class_enum mms_get_content_class(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_content_class_enum result = MMS_CONTENT_CLASS_TEXT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(MP4_DECODE) && defined(JPG_DECODE) && defined(__MMI_VCALENDAR__) && defined(__MMI_VCARD__) && defined(__DRM_SUPPORT__) && WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE >= 300*1024)
    result = MMS_CONTENT_CLASS_VIDEO_RICH;
#elif (defined(MP4_DECODE) && defined(JPG_DECODE) && defined(__MMI_VCALENDAR__) && defined(__MMI_VCARD__) && defined(__DRM_SUPPORT__) && WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE >= 100*1024)
    result = MMS_CONTENT_CLASS_VIDEO_BASIC;
#elif (defined(JPG_DECODE) && defined(__MMI_VCALENDAR__) && defined(__MMI_VCARD__) && defined(__DRM_SUPPORT__) && WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE >= 100*1024)
    result = MMS_CONTENT_CLASS_IMAGE_RICH;
#elif (defined(JPG_DECODE) && defined(__MMI_VCALENDAR__) && defined(__MMI_VCARD__) && WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE >= 30*1024)
    result = MMS_CONTENT_CLASS_IMAGE_BASIC;
#endif 
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mms_get_max_msg_size_in_restricted_mode
 * DESCRIPTION
 *  This function is used to get max mms size in restricted creation mode
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Max size
 *****************************************************************************/
kal_uint32 mms_get_max_msg_size_in_restricted_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_content_class_enum mms_content_class = mms_get_content_class();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mms_content_class == MMS_CONTENT_CLASS_VIDEO_RICH)
    {
        return 300 * 1024;
    }
    else if (mms_content_class == MMS_CONTENT_CLASS_VIDEO_BASIC || mms_content_class == MMS_CONTENT_CLASS_IMAGE_RICH)
    {
        return 100 * 1024;
    }
    else
    {
        return 30 * 1024;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mms_get_max_image_resolution_in_restricted_mode
 * DESCRIPTION
 *  The function is used to get image resolution limit in restricted mode
 * PARAMETERS
 *  width       [OUT]       
 *  height      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mms_get_max_image_resolution_in_restricted_mode(kal_int32 *width, kal_int32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_content_class_enum class = mms_get_content_class();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (class)
    {
        case MMS_CONTENT_CLASS_IMAGE_BASIC:
            *width = 160;
            *height = 120;
            break;

        case MMS_CONTENT_CLASS_IMAGE_RICH:
        case MMS_CONTENT_CLASS_VIDEO_BASIC:
        case MMS_CONTENT_CLASS_VIDEO_RICH:
            *width = 640;
            *height = 480;
            break;

        case MMS_CONTENT_CLASS_TEXT:
        case MMS_CONTENT_CLASS_UNKNOWN:
        default:
            *width = 0;
            *height = 0;
            break;
    }
}

#ifdef __MMI_MMS_IN_UM__


/*****************************************************************************
 * FUNCTION
 *  mms_um_entry_write_msg
 * DESCRIPTION
 *  This function is to enter MMS editor screen
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_um_entry_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mea_um_entry_req_struct *entry_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_UM_ENTRY_WRITE_MSG);
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_IN_USB_MODE);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* fill local parameter */
    entry_req = (mea_um_entry_req_struct*) construct_local_para((kal_uint16) sizeof(mea_um_entry_req_struct), TD_CTRL);
    entry_req->mode = MEA_UM_ENTRY_WRITE_MSG;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) entry_req;
    ilm_ptr->msg_id = MSG_ID_MEA_UM_ENTRY_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr)
}


/*****************************************************************************
 * FUNCTION
 *  mms_um_entry_msg
 * DESCRIPTION
 *  This function is to enter MMS reading (player) screen by specifying MMS folder and index in that folder
 * CALLS
 *  
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  msg_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_um_entry_msg(kal_uint16 msg_box_type, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mea_um_entry_req_struct *entry_req = NULL;
    MeaFolder_temp folder = wap_translate_um_folder_2_mea_folder(msg_box_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_UM_ENTRY_MSG);
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_IN_USB_MODE);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* fill local parameter */
    entry_req = (mea_um_entry_req_struct*) construct_local_para((kal_uint16) sizeof(mea_um_entry_req_struct), TD_CTRL);
    entry_req->mode = MEA_UM_ENTRY_READ_MSG;
    entry_req->msg_box = folder;
    entry_req->msg_index = (kal_uint16) msg_id;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) entry_req;
    ilm_ptr->msg_id = MSG_ID_MEA_UM_ENTRY_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr)
}


/*****************************************************************************
 * FUNCTION
 *  mms_um_entry_template
 * DESCRIPTION
 *  This function is to enter MMS template list screen
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_um_entry_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mea_um_entry_req_struct *entry_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_UM_ENTRY_TEMPLATE_MSG);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_IN_USB_MODE);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* fill local parameter */
    entry_req = (mea_um_entry_req_struct*) construct_local_para((kal_uint16) sizeof(mea_um_entry_req_struct), TD_CTRL);
    entry_req->mode = MEA_UM_ENTRY_TEMPLATE;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) entry_req;
    ilm_ptr->msg_id = MSG_ID_MEA_UM_ENTRY_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr)
}


/*****************************************************************************
 * FUNCTION
 *  mms_um_entry_setting
 * DESCRIPTION
 *  This function is to enter MMS setting screen
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_um_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mea_um_entry_req_struct *entry_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_UM_ENTRY_SETTING);
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_IN_USB_MODE);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* fill local parameter */
    entry_req = (mea_um_entry_req_struct*) construct_local_para((kal_uint16) sizeof(mea_um_entry_req_struct), TD_CTRL);
    entry_req->mode = MEA_UM_ENTRY_SETTING;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) entry_req;
    ilm_ptr->msg_id = MSG_ID_MEA_UM_ENTRY_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr)
}

/*****************************************************************************
 * FUNCTION
 *  mms_is_reentrant
 * DESCRIPTION
 *  The function is used to check if UM enter MMS menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_FASLE, KAL_TRUE
 *****************************************************************************/
int mms_is_reentrant()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Rahul:- This API is better to write in WAP */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //Rahul:- Require replacement for WGUI_CTX
    //if (!MSF_wapIsReady() || !MSF_moduleIsRunning(8 /*Rahul:- need to modify MSF_MODID_MEA*/)) || 
    //   IsScreenPresent(WAP_SCREEN_WIDGET) || IsScreenPresent(WAP_SCREEN_TRANSITION_ANIMATION)
    //|| WGUI_CTX->is_shutdown_UI == 1*/ ||
    //  wap_status != WAP_RUNNING)*/
    //   if (!MSF_wapIsReady() || !MSF_moduleIsRunning(8) || 
    //     IsScreenPresent(WAP_SCREEN_WIDGET) || IsScreenPresent(WAP_SCREEN_TRANSITION_ANIMATION) ||
    //   /*wap_status != 0/*WAP_RUNNING*/)
    {
        return KAL_FALSE;
    }
    /* return KAL_TRUE; */
}
#endif /* __MMI_MMS_IN_UM__ */ 

#if defined(__MMI_MMS_BGSR_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mms_send_msg
 * DESCRIPTION
 *  send message request
 * PARAMETERS
 *  simid       [IN]        
 *  msg_id      [IN]        -  the message id
 * RETURNS
 *  void
 *****************************************************************************/
void mms_send_msg(kal_int32 simid, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mms_bgsr_send_req(simid, msg_id, 0, mma_conf_get_send_setting());
}
#endif /* defined(__MMI_MMS_BGSR_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  mms_plmn_number_indication_callback
 * DESCRIPTION
 *  This function is used to infom WAP task of PLMN number of current operator.
 *  MMS version may be changed by this number. Ex: Taiwan FET => MMS v1.0
 * CALLS
 *  
 * PARAMETERS
 *  plmn_number     [IN]        PLMN number of network we campon
 * RETURNS
 *  void
 *****************************************************************************/
void mms_plmn_number_indication_callback(const unsigned char *plmn_number)
{
    //TODO:; [Rahul] This code is commented because PLMN number is getting set 
    // in MMSC version, which seems to be wrong. Also MMS V02 is not handling this primitive
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MYQUEUE Message;
    //peer_buff_struct *peer_buff_ptr = NULL;
    //kal_uint8 *peer_pdu = NULL;
    //kal_uint16 peer_pdu_len = 0;
    //mms_target_data_ind_struct *req = NULL;
    //mms_target_data_plmn_number_struct plmn_number_st = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //req = (mms_target_data_ind_struct  *) construct_local_para((kal_uint16) sizeof(mms_target_data_ind_struct),
    //                                    TD_CTRL | TD_RESET);

    /* memcpy(plmn_number_st.plmn_number, plmn_number, strlen((char*)plmn_number)); */

    //req->data_type = MMS_TARGET_DATA_PLMN_NUMBER;
    //peer_buff_ptr = (peer_buff_struct*) construct_peer_buff(sizeof(mms_target_data_plmn_number_struct), 0, 0, TD_CTRL);
    //peer_pdu = (kal_uint8*) get_pdu_ptr(peer_buff_ptr, &peer_pdu_len);
    //if (peer_pdu)
    //{
    //   memcpy((kal_uint8*) peer_pdu, &plmn_number_st, sizeof(mms_target_data_plmn_number_struct));
    //}

    //Message.oslSrcId = MOD_MMI;
    //Message.oslDestId = MOD_WAP;
    //Message.oslMsgId = MSG_ID_MMS_TARGET_DATA_IND;
    //Message.oslDataPtr = (local_para_struct*)req;
    //Message.oslPeerBuffPtr = (peer_buff_struct*) peer_buff_ptr;

    //OslMsgSendExtQueue(&Message);
    //return;
}


/*****************************************************************************
 * FUNCTION
 *  mms_roaming_status_indication_callback
 * DESCRIPTION
 *  This function is used to infom WAP task of PLMN number of current operator.
 *  MMS version may be changed by this number. Ex: Taiwan FET => MMS v1.0
 * CALLS
 *  
 * PARAMETERS
 *  simId           [IN]        SimId, ex: 0, 1, 2, 3, ...
 *  isRoaming       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_roaming_status_indication_callback(int simId, unsigned long isRoaming)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    peer_buff_struct *peer_buff_ptr = NULL;
    kal_uint8 *peer_pdu = NULL;
    kal_uint16 peer_pdu_len = 0;
    mms_target_data_ind_struct *req = NULL;
    mms_target_data_roaming_status_struct roaming_st = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req =
        (mms_target_data_ind_struct*) construct_local_para(
                                        (kal_uint16) sizeof(mms_target_data_ind_struct),
                                        TD_CTRL | TD_RESET);

    roaming_st.sim_id = simId;
    roaming_st.is_roaming = isRoaming;

    req->data_type = MMS_TARGET_DATA_ROAMING_STATUS;
    peer_buff_ptr =
        (peer_buff_struct*) construct_peer_buff(sizeof(mms_target_data_roaming_status_struct), 0, 0, TD_CTRL);
    peer_pdu = (kal_uint8*) get_pdu_ptr(peer_buff_ptr, (kal_uint16*) & peer_pdu_len);
    if (peer_pdu)
    {
        memcpy((kal_uint8*) peer_pdu, &roaming_st, sizeof(mms_target_data_roaming_status_struct));
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_MMS_TARGET_DATA_IND;
    Message.oslDataPtr = (local_para_struct*) req;
    Message.oslPeerBuffPtr = (peer_buff_struct*) peer_buff_ptr;

    OslMsgSendExtQueue(&Message);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mms_owner_number_indication_callback
 * DESCRIPTION
 *  Callback API for external AP, ex. Phonebook, to set owner number information
 * CALLS
 *  
 * PARAMETERS
 *  sim_id              [IN]        
 *  owner_number        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_owner_number_indication_callback(kal_uint8 sim_id, const kal_wchar *owner_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Q03C currently do not support */
}


/*****************************************************************************
 * FUNCTION
 *  mms_get_service_module
 * DESCRIPTION
 *  This function is to implement get module id to handle mms primitives
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        Primitve id
 * RETURNS
 *  module id, MOD_MMI or MOD_WAP
 *****************************************************************************/
module_type mms_get_service_module(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_id)
    {
        case MSG_ID_WAP_MMC_GET_MMS_PROF_REQ:

            return MOD_MMI;
        default:

    return MOD_WAP;
   }
}

#ifdef __MMI_MMS_BGSR_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_change_msg_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  result          [IN]        
 * RETURNS
 *****************************************************************************/
void mmi_mms_bgsr_change_msg_cb(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    struct ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_ASSERT(msg_id == g_mmi_mms_V01_agent_ctx.mmi_mms_bgsr_op_msg_id);

    switch (g_mmi_mms_V01_agent_ctx.mmi_mms_bgsr_op)
    {
        case MMI_MMS_BGSR_OP_CANCEL_ALL_INBOX:
        {
            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MMS_BGSR_CANCEL_ALL_INBOX_RSP;
            ilm_ptr->peer_buff_ptr = NULL;
            ilm_ptr->local_para_ptr = NULL;

            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
            break;
        }
        case MMI_MMS_BGSR_OP_MOVE_TO_FOLDER:
        {
            wap_bgsr_move_to_folder_rsp_struct *msg_req;

            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MMS_BGSR_MOVE_TO_FOLDER_RSP;

            msg_req =
                (wap_bgsr_move_to_folder_rsp_struct*) construct_local_para(
                                                        sizeof(wap_bgsr_move_to_folder_rsp_struct),
                                                        TD_CTRL | TD_RESET);

            msg_req->msg_id = msg_id;
            msg_req->result = result;
            msg_req->folder = __MEA_FOLDER_DRAFTS;

            ilm_ptr->local_para_ptr = (local_para_struct*) msg_req;
            ilm_ptr->peer_buff_ptr = NULL;

            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
            break;
        }
        case MMI_MMS_BGSR_OP_DELETE:
        {
            wap_bgsr_delete_rsp_struct *msg_req;

            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MMS_BGSR_DELETE_MSG_RSP;

            msg_req =
                (wap_bgsr_delete_rsp_struct*) construct_local_para(
                                                sizeof(wap_bgsr_delete_rsp_struct),
                                                TD_CTRL | TD_RESET);

            msg_req->msg_id = msg_id;
            msg_req->result = result;

            ilm_ptr->local_para_ptr = (local_para_struct*) msg_req;
            ilm_ptr->peer_buff_ptr = NULL;

            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
            break;
        }
        case MMI_MMS_BGSR_OP_DELETE_ALL_INBOX:
        {
            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MMS_BGSR_DELETE_ALL_INBOX_RSP;
            ilm_ptr->peer_buff_ptr = NULL;
            ilm_ptr->local_para_ptr = NULL;

            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
            break;
        }
        case MMI_MMS_BGSR_OP_DELETE_ALL_OUTBOX:
        {
            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MMS_BGSR_DELETE_ALL_OUTBOX_RSP;
            ilm_ptr->peer_buff_ptr = NULL;
            ilm_ptr->local_para_ptr = NULL;

            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
            break;
        }
    }
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_get_msg_info_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  msg_info        [IN]         
  * RETURNS
 *****************************************************************************/
void mmi_mms_bgsr_get_msg_info_cb(U32 msg_id, mmi_mms_bgsr_msg_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    struct ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    ilm_ptr = allocate_ilm(MOD_MMI);

    ilm_ptr->msg_id = MSG_ID_MMS_BGSR_NAV_ACTIVATE_BGSR_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    return;

}


/*****************************************************************************
 * FUNCTION
 *  MEAa_downloadMessageReqNoProgressing
 * DESCRIPTION
 *  handle wap task to download the message
 * CALLS
 *  
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void MEAa_downloadMessageReqNoProgressing(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    param = (mmi_mms_bgsr_msg_struct*) p;

    mmi_mms_bgsr_download_req_no_progressing(1, param->msg_id, param->expire_time, param->size);

    /* MSF_MEM_FREE(MSF_MODID_WIDGET, param); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_send_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  result          [IN]        
 *  text            [IN]         
 * RETURNS
 *****************************************************************************/
void mmi_mms_send_rsp_callback(U32 msg_id, U8 result, U16 *text)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;
    wap_bgsr_send_rsp_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_BGSR_SEND_RSP;
    msg_req = (wap_bgsr_send_rsp_struct*) construct_local_para(sizeof(wap_bgsr_send_rsp_struct), TD_CTRL | TD_RESET);

    msg_req->msg_id = msg_id;
    msg_req->result = result;

    ilm_ptr->local_para_ptr = (local_para_struct*) msg_req;
    ilm_ptr->peer_buff_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_cancel_send_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  result          [IN]        
 * RETURNS
 *****************************************************************************/
void mmi_mms_cancel_send_rsp_callback(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_BGSR_CANCEL_SEND_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_download_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  result          [IN]        
 *  text            [IN]
 * RETURNS
 *****************************************************************************/
void mmi_mms_download_rsp_callback(U32 msg_id, U8 result, U16 *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;
    wap_bgsr_download_rsp_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_BGSR_DOWNLOAD_RSP;
    msg_req =
        (wap_bgsr_download_rsp_struct*) construct_local_para(sizeof(wap_bgsr_download_rsp_struct), TD_CTRL | TD_RESET);

    msg_req->msg_id = msg_id;
    msg_req->result = result;

    ilm_ptr->local_para_ptr = (local_para_struct*) msg_req;
    ilm_ptr->peer_buff_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_cancel_download_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  result          [IN]        
 * RETURNS
 *****************************************************************************/
void mmi_mms_cancel_download_rsp_callback(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_BGSR_CANCEL_DOWNLOAD_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_update_folder_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
void mmi_mms_update_folder_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_BGSR_UPDATE_FOLDER_IND;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_update_menu_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  status          [IN]        
 *  filepath(?)     [IN]        
 * RETURNS
 *****************************************************************************/
void mmi_mms_update_menu_callback(U32 msg_id, U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;
    wap_bgsr_update_menu_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    /* sanity check */
    if (msg_id == 0)
    {
        return;
    }

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_BGSR_UPDATE_MENU_IND;
    msg_req =
        (wap_bgsr_update_menu_struct*) construct_local_para(sizeof(wap_bgsr_update_menu_struct), TD_CTRL | TD_RESET);

    msg_req->msg_id = msg_id;
    msg_req->status = status;

    ilm_ptr->local_para_ptr = (local_para_struct*) msg_req;
    ilm_ptr->peer_buff_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    return;

}

#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mms_em_change_setting
 * DESCRIPTION
 *  This function is used to infom changes done in engineer-mode.
 * CALLS
 *  
 * PARAMETERS
 *  opt             [IN]        
 *  new_setting     [IN]         
 *  val(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_em_change_setting(mmi_em_inet_option_enum opt, mmi_em_inet_setting_struct *new_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mms_target_data_ind_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (mms_target_data_ind_struct*) construct_local_para(
                                            (kal_uint16) sizeof(mms_target_data_ind_struct),
                                            TD_CTRL | TD_RESET);
    switch (opt)
    {
        case MMI_EM_INET_UA_STRING_OPT:
            req->data_type = MMS_TARGET_DATA_USER_AGENT;
            break;

        case MMI_EM_INET_MMS_VERSION_OPT:
            req->data_type = MMS_TARGET_DATA_MMS_VERSION;
            break;

        default:
            ASSERT(0);
            break;
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_MMS_TARGET_DATA_IND;
    Message.oslDataPtr = (local_para_struct*) req;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    return;
}

#ifdef MEA_CFG_WARNING_MODE_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_set_warning_mode_instance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_set_warning_mode_instance(mms_content_entry_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create instance */
    g_warning_inst = OslMalloc(sizeof(warning_mode_cntx_struct));
    memcpy(&g_warning_inst->data, data, sizeof(warning_mode_cntx_struct));

    if (data->file_path)
    {
        kal_uint16 size = app_ucs2_strlen((const kal_int8*)data->file_path);
        g_warning_inst->data.file_path = NULL;
        g_warning_inst->data.file_path = OslMalloc(size * ENCODING_LENGTH + ENCODING_LENGTH);

        app_ucs2_strncpy((kal_int8*) g_warning_inst->data.file_path, (const kal_int8*)data->file_path, size);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_free_warning_mode_instance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_free_warning_mode_instance(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free the warning mode context */
    if (g_warning_inst)
    {
        if(g_warning_inst->data.file_path)
        {
            OslMfree(g_warning_inst->data.file_path);           
        }

        OslMfree(g_warning_inst);
        g_warning_inst = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_enter_mms_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_enter_mms_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    goto_mms_editor(&g_warning_inst->data);
    mmi_mmsv01_free_warning_mode_instance();
    if (GetExitScrnID() == SCR_ID_MMSV01_AGENT_SCREEN_WARNING_CONFIRM)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_MMSV01_AGENT_SCREEN_WARNING_CONFIRM);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_warning_go_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_warning_go_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_warning_inst && g_warning_inst->data.callback)
    {
        g_warning_inst->data.callback(g_warning_inst->data.callback_param);
    }
    mmi_mmsv01_free_warning_mode_instance();
    if (GetExitScrnID() == SCR_ID_MMSV01_AGENT_SCREEN_WARNING_CONFIRM)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_MMSV01_AGENT_SCREEN_WARNING_CONFIRM);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_display_popup_confirm_screen_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_mmsv01_agent_display_popup_confirm_screen_cb(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_warning_inst)
    {
        mmi_mmsv01_free_warning_mode_instance();
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_entry_display_popup_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_entry_display_popup_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    ALL_TONE_ENUM tone_id;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* show confirm screen */
    EntryNewScreen(
        SCR_ID_MMSV01_AGENT_SCREEN_WARNING_CONFIRM,
        NULL,
        mmi_mmsv01_agent_entry_display_popup_confirm,
        NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_MMSV01_AGENT_SCREEN_WARNING_CONFIRM);

    tone_id = mmi_get_event_based_sound(MMI_EVENT_QUERY);
    image_id = mmi_get_event_based_image(MMI_EVENT_QUERY);

    SetDelScrnIDCallbackHandler(
        SCR_ID_MMSV01_AGENT_SCREEN_WARNING_CONFIRM,
        mmi_mmsv01_agent_display_popup_confirm_screen_cb);

    ShowCategory66Screen(
        STR_ID_MMSV01_AGENT_MMS,
        IMG_ID_MMSV01_AGENT_TITLE_NORMAL,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U8*) get_string(STR_ID_MMSV01_AGENT_WARNING_MODE_CONFIRM),
        image_id,
        gui_buffer);
    if (gui_buffer == NULL)
    {
        if (!mmi_profiles_check_tone_playing(WARNING_TONE))
        {
            playRequestedTone(tone_id);
        }
    }
    /* LSK == YES, RSK == NO */
    SetLeftSoftkeyFunction(mmi_mmsv01_agent_enter_mms_editor, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_mmsv01_agent_warning_go_back, KEY_EVENT_UP);
    return;
}

#endif /* MEA_CFG_WARNING_MODE_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  goto_mms_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void goto_mms_editor(mms_content_entry_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    kal_wchar *resizefilename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mea_mmsV01_agent_is_wap_ready() 
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
        || g_mmi_mms_V01_agent_ctx.cvm_state != MMI_MMSV01_AGENT_CVM_STATE_NONE
#endif
        )
    {
        /* Currently here the control will never come as we don't show 
		the MMS opetion when wap is not ready */
		mmi_mmsv01_agent_wap_not_ready();
        
        if (data && data->callback)
        {
            data->callback(data->callback_param);
        }
        return;
    }

    /* Disable key to prevent sending duplicated requests (End key still set) */
    ClearAllKeyHandler();

    if (!mea_mmsV01_agent_get_no_of_free_msg())
    {
        mmi_display_popup((UI_string_type) GetString(STR_ID_MMSV01_AGENT_MAX_NUMBER_OF_MSG), MMI_EVENT_FAILURE);
        if (data && data->callback)
        {
            data->callback(data->callback_param);
        }
        return;
    }

#ifndef __MMI_MMS_IN_UM__
    if (mea_mmsV01_agent_is_mea_running())
    {
        /* 
         * Workaround for abnormal case:
         * History node of MEA is deleted by someone, and MEA is still running
         */
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_CONTENT_INSERT_HDLR_WITH_MEA_RUNNING);

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_SHUTDOWN_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
        SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    }
#endif /* __MMI_MMS_IN_UM__ */ 

    switch (data->mode)
    {

        case MMS_NEW_GENERAL:
        case MMS_NEW_FILE:

        {

            if (data->file_path != NULL)
            {

                kal_uint8 result;

                result = mea_mmsv01_agent_insert_object_check((const kal_wchar*)data->file_path, &resizefilename, mmi_mmsv01_get_image_resize());

                MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_INSER_OBJECT_CHECK, result);

                if (result == MEA_RESULT_RESIZING_SUCCEED)
                {

                    data->file_path = (char*)resizefilename;
                }
                else if (result == MEA_RESULT_RESIZING_SUCCEED_WITH_UNCHANGED ||
                         result == MEA_RESULT_RESIZING_OFF_CONTENT_UNCHANGED ||
                         result == MEA_RESULT_RESIZING_FAILED_NOT_IMAGE || result == MEA_RESULT_OK)
                {
                    /* Do Nothing */
                }
                else
                {
                    /* Some error has occured while resizing */
                    kal_int32 strid = mmi_mmsv01_agent_get_error_string(result);

                    mmi_display_popup((UI_string_type) GetString(strid), MMI_EVENT_FAILURE);
                    if (data && data->callback)
                    {
                        data->callback(data->callback_param);
                    }
                    /* TODO:: Rahul check if any cleanup is needed here */
                    if (resizefilename)
                    {
                        OslMfree(resizefilename);
                        resizefilename = NULL;
                    }
                    return;
                }

                result = mea_mmsv01_agent_insert_object_check_for_creation_mode((const kal_wchar*)data->file_path, mmi_mmsv01_get_creation_mode());

                if (result == MEA_RESULT_FAILED_RESTRICTED_CONTENT /* RESTRICTED_CONTENT */ )
                {
                    mmi_display_popup(
                        (UI_string_type) GetString(STR_ID_MMSV01_AGENT_RESTRICTED_MIME_ACTION_NONE),
                        MMI_EVENT_FAILURE);

                    if (data && data->callback)
                    {
                        data->callback(data->callback_param);
                    }
                    /* TODO:: Rahul check if any cleanup is needed here */
                    if (resizefilename)
                    {
                        OslMfree(resizefilename);
                        resizefilename = NULL;
                    }
                    /* wap_suppress_popup(suppress_popup_flag); */
                    return;
                }
            #ifdef MEA_CFG_WARNING_MODE_SUPPORT
                else if (result == MEA_RESULT_RESTRICTED_CONTENT_WITH_WARNING /* WARNING_CONTENT */ )
                {
                    if (g_warning_inst == NULL)
                    {

                        mmi_mmsv01_agent_set_warning_mode_instance(data);
                        mmi_mmsv01_agent_entry_display_popup_confirm();
                        if (resizefilename)
                        {
                            OslMfree(resizefilename);
                            resizefilename = NULL;
                        }
                        return;
                    }

                }
            #endif /* MEA_CFG_WARNING_MODE_SUPPORT */ 
            }
        }

        case MMS_NEW_ADDRESS:
        case MMS_NEW_BUFFER:
#ifdef __MMI_URI_AGENT__
        case MMS_NEW_URI:
#endif
            {

#ifdef __MMI_MMS_V01_USE_ASM__                
                if (mmi_mmsV01_agent_asm_pool_init())
                {
#endif
                    new_mms_data_cntx_struct temp_data = {0,};

                    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_CALL_MEA_START_UP_REQ);

                    temp_data.startup_mode = MMI_MMSV01_AGENT_STARTUP_MODE_EDITOR;
                    memcpy(&temp_data.data.editor_data, data, sizeof(mms_content_entry_struct));

                    mmi_mmsv01_agent_send_mea_startup_req(&temp_data);
#ifdef __MMI_MMS_V01_USE_ASM__
                }
                else
                {
                    /* Save the current context in globals here */
                    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_SAVE_TEMP_CONTENT);
                    mmi_mmsv01_agent_set_startup_mode_instance(data, MMI_MMSV01_AGENT_STARTUP_MODE_EDITOR);
                }
#endif
                if (resizefilename)
				{
					OslMfree(resizefilename);
               		resizefilename = NULL;               			
               	}
                break;
            }
        default:
            ASSERT(0);
        }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mms_v01agent_new_mms_handle_notification
 * DESCRIPTION
 *  This is the callback function used for NMGR for LSK on idle screen
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_v01agent_new_mms_handle_notification(void* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_NEW_MMS_HANDLE_NOTIFICATION);

#if defined( __USB_IN_NORMAL_MODE__) && defined (MMS_IN_LARGE_STORAGE)
    if (mmi_usb_is_in_mass_storage_mode() )   /* Check if MMS should be disabled */
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_IN_USB_MODE);
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (!mea_mmsV01_agent_is_wap_ready())
    {
        mmi_mmsv01_agent_wap_not_ready();
        return;
    }

    /* Disable key to prevent sending duplicated requests */
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
#ifdef __MMI_MMS_V01_USE_ASM__
    if (mmi_mmsV01_agent_asm_pool_init())
#endif 
    {
       new_mms_data_cntx_struct temp_data = {0,};

       MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_CALL_MEA_START_UP_REQ);
       temp_data.startup_mode = MMI_MMSV01_AGENT_STARTUP_MODE_INBOX;
       mmi_mmsv01_agent_send_mea_startup_req(&temp_data);
    }
#ifdef __MMI_MMS_V01_USE_ASM__
    else
    {        
        /* Save the current context in globals here */

        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_SAVE_TEMP_CONTENT);
        mmi_mmsv01_agent_set_startup_mode_instance(NULL, MMI_MMSV01_AGENT_STARTUP_MODE_INBOX);
        
    }
#endif /* __MMI_MMS_V01_USE_ASM__*/
}


void mmi_mmsv01_agent_send_obj_ind(kal_wchar* filepath, kal_uint8 sim_id)
{
	mmi_mmsv01_agent_mms_obj_ind_struct *msg_req = NULL;    
	ilm_struct *ilm_ptr = NULL;

	msg_req = (mmi_mmsv01_agent_mms_obj_ind_struct*) OslConstructDataPtr(sizeof(mmi_mmsv01_agent_mms_obj_ind_struct));
	
	if (filepath != NULL)
	{
		mmi_ucs2cpy((S8*)msg_req->mms_filepath, (S8*) filepath);
       // mmi_chset_ucs2_to_utf8_string(, MMSV01_MAX_OBJ_IND_FILE_PATH_LEN, (kal_uint8 *) filepath);
	}
	msg_req->sim_id = sim_id;

    
	ilm_ptr = allocate_ilm(MOD_MMI);
	ilm_ptr->msg_id = MSG_ID_MMS_OBJ_IND;
	ilm_ptr->peer_buff_ptr = NULL;
	ilm_ptr->local_para_ptr = (local_para_struct*) msg_req;

	SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}

void mmi_mmsv01_agent_send_set_profile_req(mmi_wap_prof_profile_content_struct *content, kal_uint8 sim_id)
{
	mmi_wap_prof_active_profile_changed_ind_struct *l_data;    
	ilm_struct *ilm_ptr = NULL;

    l_data =
        (mmi_wap_prof_active_profile_changed_ind_struct*)
        OslConstructDataPtr(sizeof(mmi_wap_prof_active_profile_changed_ind_struct));
    l_data->sim_id = sim_id;
    l_data->app_id = MMI_WAP_PROF_APPID_MMS;
    memcpy(&(l_data->profile_content_p), content, sizeof(mmi_wap_prof_profile_content_struct));

    
	ilm_ptr = allocate_ilm(MOD_MMI);
	ilm_ptr->msg_id = MSG_ID_MEA_SET_PROFILE_REQ;
	ilm_ptr->peer_buff_ptr = NULL;
	ilm_ptr->local_para_ptr = (local_para_struct*) l_data;

	SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}

void mmi_mmsv01_agent_send_add_bookmark_rsp(kal_uint8 *url, kal_uint8 result)
{
	mmi_mmsv01_agent_add_bookmark_rsp_struct *data = NULL;    
	ilm_struct *ilm_ptr = NULL;

	data = (mmi_mmsv01_agent_add_bookmark_rsp_struct*) OslConstructDataPtr
        (sizeof(mmi_mmsv01_agent_add_bookmark_rsp_struct));
    
    memset(data->url, 0X0, sizeof(data->url));
	
	if (url != NULL)
	{
		strncpy((char*)data->url, (char*)url, WAP_MAX_URL_LENGTH + 1);       
	}
	data->result = result;

    
	ilm_ptr = allocate_ilm(MOD_MMI);
	ilm_ptr->msg_id = MSG_ID_MEA_ADD_BOOKMARK_RSP;
    
	ilm_ptr->peer_buff_ptr = NULL;
	ilm_ptr->local_para_ptr = (local_para_struct*) data;

	SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}
#ifdef __MMI_MMS_V01_USE_ASM__
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_set_startup_mode_instance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_set_startup_mode_instance(mms_content_entry_struct *data, kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create instance */

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_SET_STARTUP_MODE,mode);

    g_mmi_mms_V01_agent_ctx.data = OslMalloc(sizeof(new_mms_data_cntx_struct));

    if (data != NULL)
    {
        memcpy(&g_mmi_mms_V01_agent_ctx.data->data, data, sizeof(mms_content_entry_struct));
    }
	else
	{
		memset(g_mmi_mms_V01_agent_ctx.data, 0X0, sizeof(new_mms_data_cntx_struct));
	}

    g_mmi_mms_V01_agent_ctx.data->startup_mode = mode;

    switch (mode)
    {
        case MMI_MMSV01_AGENT_STARTUP_MODE_EDITOR:
            {

                if (data->addr)
                {
                    kal_uint16 size = app_ucs2_strlen((const kal_int8*)data->addr);
                    g_mmi_mms_V01_agent_ctx.data->data.editor_data.addr = NULL;
                    g_mmi_mms_V01_agent_ctx.data->data.editor_data.addr = OslMalloc(size  * ENCODING_LENGTH + ENCODING_LENGTH);

                    app_ucs2_strncpy((kal_int8*) g_mmi_mms_V01_agent_ctx.data->data.editor_data.addr, 
                                            (const kal_int8*)data->addr, size);
                }

                if (data->subject)
                {
                    kal_uint16 size = app_ucs2_strlen((const kal_int8*)data->subject);
                    g_mmi_mms_V01_agent_ctx.data->data.editor_data.subject = NULL;
                    g_mmi_mms_V01_agent_ctx.data->data.editor_data.subject = OslMalloc(size  * ENCODING_LENGTH + ENCODING_LENGTH);

                    app_ucs2_strncpy((kal_int8*) g_mmi_mms_V01_agent_ctx.data->data.editor_data.subject,
                                (const kal_int8*)data->subject, size);
                }

                if (data->file_path)
                {
                    kal_uint16 size = app_ucs2_strlen((const kal_int8*)data->file_path);
                    g_mmi_mms_V01_agent_ctx.data->data.editor_data.file_path = NULL;
                    g_mmi_mms_V01_agent_ctx.data->data.editor_data.file_path = OslMalloc(size  * ENCODING_LENGTH + ENCODING_LENGTH);

                    app_ucs2_strncpy((kal_int8*) g_mmi_mms_V01_agent_ctx.data->data.editor_data.file_path, 
                            (const kal_int8*)data->file_path, size);
                }

                if (data->text_buffer)
                {
                    kal_uint16 size = app_ucs2_strlen((const kal_int8*)data->text_buffer);
                    g_mmi_mms_V01_agent_ctx.data->data.editor_data.text_buffer = NULL;
                    g_mmi_mms_V01_agent_ctx.data->data.editor_data.text_buffer = OslMalloc(size  * ENCODING_LENGTH + ENCODING_LENGTH);

                    app_ucs2_strncpy((kal_int8*) g_mmi_mms_V01_agent_ctx.data->data.editor_data.text_buffer,
                            (const kal_int8*)data->text_buffer, size);

                }

                if (data->callback_param)
                {
                    g_mmi_mms_V01_agent_ctx.data->data.editor_data.callback_param = data->callback_param;
                    /*kal_uint16 size = app_ucs2_strlen((const kal_int8*)data->callback_param);
                    g_mmi_mms_V01_agent_ctx.data->data.editor_data.callback_param = NULL;
                    g_mmi_mms_V01_agent_ctx.data->data.editor_data.callback_param = OslMalloc(size  * ENCODING_LENGTH + ENCODING_LENGTH);

                    app_ucs2_strncpy((kal_int8*) g_mmi_mms_V01_agent_ctx.data->data.editor_data.callback_param, 
                                (const kal_int8*)data->callback_param, size);*/
                }
            }

            break;
        case MMI_MMSV01_AGENT_STARTUP_MODE_FOLDER:
            {
               /* do nothing */

            }

            break;

        case MMI_MMSV01_AGENT_STARTUP_MODE_INBOX:
            {
                /* do nothing */

            }
            break;
        default:
            ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_free_startup_mode_instance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_free_startup_mode_instance(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free the warning mode context */
    if (g_mmi_mms_V01_agent_ctx.data)
    {

        if(g_mmi_mms_V01_agent_ctx.data->data.editor_data.file_path)
        {
            OslMfree(g_mmi_mms_V01_agent_ctx.data->data.editor_data.file_path);           
        }
        
        if(g_mmi_mms_V01_agent_ctx.data->data.editor_data.text_buffer)
        {
            OslMfree(g_mmi_mms_V01_agent_ctx.data->data.editor_data.text_buffer);           
        }

        if(g_mmi_mms_V01_agent_ctx.data->data.editor_data.addr)
        {
            OslMfree(g_mmi_mms_V01_agent_ctx.data->data.editor_data.addr);           
        }
        
        if(g_mmi_mms_V01_agent_ctx.data->data.editor_data.subject)
        {
            OslMfree(g_mmi_mms_V01_agent_ctx.data->data.editor_data.subject);           
        }

      /*  if(g_mmi_mms_V01_agent_ctx.data->data.editor_data.callback_param)
        {
            OslMfree(g_mmi_mms_V01_agent_ctx.data->data.editor_data.callback_param);           
        }*/

        OslMfree(g_mmi_mms_V01_agent_ctx.data);
        g_mmi_mms_V01_agent_ctx.data = NULL;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mmsV01_agent_internal_success_callback
 * DESCRIPTION
 *  Success callback function for ASM 
 * PARAMETERS
 *   void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsV01_agent_internal_success_callback(void)
{
    if (mmi_mmsV01_agent_asm_pool_init())
    {
        mmi_mmsv01_agent_send_mea_startup_req(g_mmi_mms_V01_agent_ctx.data);
        mmi_mmsv01_free_startup_mode_instance();
    }
    else
    {   
        /*Contetxt is already saved so do nothing, just print log here*/

    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsV01_agent_asm_cancel_callback
 * DESCRIPTION
 *  cancel callback function for ASM 
 * PARAMETERS
 *   void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsV01_agent_asm_cancel_callback(mmi_frm_appmem_evt_struct* event_type)
{
    /*Reset the global context*/
    mmi_mmsv01_free_startup_mode_instance();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsV01_agent_asm_pool_init
 * DESCRIPTION
 *  This will request the ASM pool memory, 
 * PARAMETERS
 *   void 
 * RETURNS
 *  TRUE    on Success
 *  FALSE   on Failure
 *****************************************************************************/
kal_bool mmi_mmsV01_agent_asm_pool_init()
{

    void* mms_mem_ptr = NULL;

    kal_uint32 mms_mem_size = mea_mmsV01_agent_get_asm_mem_pool_size();
    /*put log here to print the memory size*/
   
    mms_mem_ptr = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_MMS_V01, mms_mem_size);

	if(!mms_mem_ptr)
	{
         mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_MMS_V01,
                MEA_STR_ID_MMS,
                mms_mem_size,
                mmi_mmsV01_agent_internal_success_callback);

        mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_MMS_V01, 
                                mmi_mmsV01_agent_asm_cancel_callback);

        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_ASM_POOL_INIT_MEM_ALLOCATED);

        return FALSE;
		
	}
    /* set pool id in global context*/
    g_mmi_mms_V01_agent_ctx.asm_pool_id = mms_mem_ptr;
    g_mmi_mms_V01_agent_ctx.is_forced_shutdown = FALSE;

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_ASM_POOL_INIT_MEM_NOT_ALLOCATED);
    /*MEA can be launched successfully*/
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_asm_deinit
 * DESCRIPTION
 *  ASM dinit callback. This API will send the shutdown primitive to MEA(WAP Task)
 * PARAMETERS
 *   void 
 * RETURNS
 *  void
 *
 *****************************************************************************/
void mmi_mmsv01_agent_asm_deinit(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_ASM_POOL_DEINIT);
    /* Send shutdown indication to WAP */
    if (g_mmi_mms_V01_agent_ctx.asm_pool_id != NULL)
    {
        ilm_struct *ilm_ptr = NULL;
    
        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->msg_id = MSG_ID_MEA_SHUTDOWN_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
        SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
        g_mmi_mms_V01_agent_ctx.is_forced_shutdown = TRUE;
    }
    else
    {
        applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_MMS_V01, TRUE);
    }
}
#endif /*__MMI_MMS_V01_USE_ASM__*/


void mmi_mmsv01_send_settings_data(kal_uint16 msg_id,
                                   mmsV01_agent_compose_settings_struct* compose_settings,
                                   mmsV01_agent_sending_settings_struct* sending_settings,
                                   mmsV01_agent_retrieval_settings_struct* retrival_settings)
{
   
    mmi_mmsv01_agent_setting_req_struct *data = NULL;    
	ilm_struct *ilm_ptr = NULL;

	data = (mmi_mmsv01_agent_setting_req_struct*) OslConstructDataPtr
        (sizeof(mmi_mmsv01_agent_setting_req_struct));

    memcpy((char*)&(data->compose_settings), (char*)compose_settings, sizeof(mmsV01_agent_compose_settings_struct));
    memcpy((char*)&(data->sending_settings), (char*)sending_settings, sizeof(mmsV01_agent_sending_settings_struct));
    memcpy((char*)&(data->retrival_settings), (char*)retrival_settings, sizeof(mmsV01_agent_retrieval_settings_struct)); 


	ilm_ptr = allocate_ilm(MOD_MMI);
	ilm_ptr->msg_id = msg_id;
    
	ilm_ptr->peer_buff_ptr = NULL;
	ilm_ptr->local_para_ptr = (local_para_struct*) data;

	SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_mms_is_mms_can_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *   void 
 * RETURNS
 *  void
 *
 *****************************************************************************/
kal_bool mmi_mms_is_mms_can_enter(void)
{
    if( IsScreenPresent(wap_get_screen_id()) || IsScreenPresent(widget_get_mms_screen_id()))
    {
        return MMI_FALSE;
    }
#ifdef __MMI_BACKGROUND_CALL__
    if(srv_ucm_is_background_call() && IsScreenPresent((mmi_ucm_app_get_intermediate_marker_scrn_id())))
#else 
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
#endif 
    {
         return MMI_FALSE;
    }

#ifdef __MMI_BROWSER_2__
    if(mmi_brw_is_browser_active())
    {
        return MMI_FALSE;
    }
#endif /* __MMI_BROWSER_2__ */

   /* Not available in flight mode*/
    if (mmi_bootup_get_active_flight_mode())
    {
        return MMI_FALSE;
    }

#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
    {
        return MMI_FALSE;
    }
#endif

#ifndef __MMI_MMS_DUAL_SIM__
      if(mmi_bootup_is_sim_valid())
#else 
      if(g_mmi_mms_V01_agent_ctx.is_sim1_valid || g_mmi_mms_V01_agent_ctx.is_sim2_valid)
#endif /* __MMI_WAP_DUAL_SIM__ */
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mmsv01_agent_mms_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *   void 
 * RETURNS
 *  void
 *
 *****************************************************************************/
void mmi_mmsv01_agent_mms_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(goto_mms_screen, KEY_EVENT_UP);
    SetKeyHandler(goto_mms_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_process_vendor_create_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_vendor_create_req_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_req_struct *msg_req = NULL;
    peer_buff_struct *peer_buff_ptr = NULL;
    U32 read_size = 0;
    U16 peer_buff_len = 0;
    mmi_mms_vendor_create_req_struct *vendor_req = (mmi_mms_vendor_create_req_struct*) in_msg;
    ilm_struct *ilm_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_CREATE_REQ_HDLR);
    if(!mms_is_ready() ||
        /* Already a create request is in process*/
        g_mmi_mms_V01_agent_ctx.cvm_state != MMI_MMSV01_AGENT_CVM_STATE_NONE)
    {
        
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_VRE_BUSY, g_mmi_mms_V01_agent_ctx.cvm_state);
        mmi_mmsv01_agent_send_vendor_create_rsp(0 , MMI_MMS_VENDOR_FAIL);
        return;
    }


    msg_req = (wap_mma_create_req_struct*) OslConstructDataPtr(sizeof(wap_mma_create_req_struct));
    msg_req->msg_id = 0;


    msg_req->app_id = vendor_req->app_id; /* MMI_MMS_VENDOR_CVM_APP_ID*/
    
   
    if(vendor_req->mms_type == MMI_MMS_VENDOR_TYPE_SMIL_MMS)
    {
        msg_req->mode = MMA_MODE_EDIT;
    }
    else if(vendor_req->mms_type == MMI_MMS_VENDOR_TYPE_MIXED_MMS)
    {
        msg_req->mode = MMA_MODE_MIXED;
    }
    else
    {
        MMI_ASSERT(0);
    }
     

    if(vendor_req->sim_id == MMI_MMS_VENDOR_SIM_ID_SIM1)
    {
        msg_req->sim_id = MMA_SIM_ID_SIM1;
    }
    else if(vendor_req->sim_id == MMI_MMS_VENDOR_SIM_ID_SIM2)
    {
        msg_req->sim_id = MMA_SIM_ID_SIM2;
    }
    else
    {
        MMI_ASSERT(0);
    }

    mmi_ucs2cpy((PS8) msg_req->xml_filepath, (PS8) vendor_req->xml_filepath);
    msg_req->buffer_index = 0;
    msg_req->xml_size = applib_get_file_size(vendor_req->xml_filepath);


    if (0 == msg_req->xml_size)
    {
        mmi_mmsv01_agent_send_vendor_create_rsp(0 , MMI_MMS_VENDOR_FAIL);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_VRE_XML_ERROR);
        return;
    }

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_WAP_MMA_CREATE_REQ;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_req;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

        /*set the state*/
    g_mmi_mms_V01_agent_ctx.cvm_state |= MMI_MMSV01_AGENT_CVM_STATE_CREATE_PROCESS;


    return;

}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_vendor_create_rsp_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_rsp_struct *msg_rsp = (wap_mma_create_rsp_struct*) in_msg;
    U8 result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_VENDOR_CREATE_RSP_HDLR);
            
   if (msg_rsp->result != MMA_RESULT_OK)
   {
       if(msg_rsp->result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE) 
       {
           result = MMI_MMS_VENDOR_MEMORY_NOT_ENOUGH;
       }
       else
       {
           result = MMI_MMS_VENDOR_FAIL;
       }
              
   }
   else
   {
        result = MMI_MMS_VENDOR_PASS;
   }

   mmi_mmsv01_agent_send_vendor_create_rsp(msg_rsp->msg_id , result);

   /*Change state to Normal*/
   g_mmi_mms_V01_agent_ctx.cvm_state &= ~MMI_MMSV01_AGENT_CVM_STATE_CREATE_PROCESS;

}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_send_vendor_create_rsp(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mms_vendor_create_rsp_struct *msg_rsp;
    ilm_struct *ilm_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_rsp = (mmi_mms_vendor_create_rsp_struct*) OslConstructDataPtr(sizeof(mmi_mms_vendor_create_rsp_struct));

    msg_rsp->app_id = MMI_MMS_VENDOR_CVM_APP_ID;
    msg_rsp->msg_id = msg_id;
    msg_rsp->result = result;


    ilm_ptr = allocate_ilm(MOD_MMI);

    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_MMI_SAP;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->msg_id = MSG_ID_MMI_MMS_VENDOR_CREATE_RSP;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_rsp;

    msg_send_ext_queue(ilm_ptr);

    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_vendor_send_req_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = 0;
    wap_mma_send_req_struct *msg_req;
    ilm_struct *ilm_ptr = NULL;
    mmi_mms_vendor_send_req_struct *vendor_req = (mmi_mms_vendor_send_req_struct*) in_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_VENDOR_SEND_REQ_HDLR);

    if(!mms_is_ready() ||
        /* Already a send request is in process*/
        g_mmi_mms_V01_agent_ctx.cvm_state != MMI_MMSV01_AGENT_CVM_STATE_NONE)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_VRE_BUSY, g_mmi_mms_V01_agent_ctx.cvm_state);        
        mmi_mmsv01_agent_send_vendor_send_rsp(0 , MMI_MMS_VENDOR_FAIL);
        return;
    }
    
    if(vendor_req->sim_id == MMI_MMS_VENDOR_SIM_ID_SIM1)
    {
        sim_id = (U8)MMA_SIM_ID_SIM1;
    }
    else if(vendor_req->sim_id == MMI_MMS_VENDOR_SIM_ID_SIM2)
    {
        sim_id = (U8)MMA_SIM_ID_SIM2;
    }
    else
    {
        MMI_ASSERT(0);
    }

    /* Send request to SLIM MMA*/

    msg_req = (wap_mma_send_req_struct*) construct_local_para(sizeof(wap_mma_send_req_struct), TD_CTRL | TD_RESET);
   // msg_req->req_id = mma_get_request_id();

    msg_req->app_id = MMI_MMS_VENDOR_CVM_APP_ID;
    msg_req->msg_id = vendor_req->msg_id;
    msg_req->sim_id = sim_id;


    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_WAP_MMA_SEND_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_req;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    /*set the state*/
    g_mmi_mms_V01_agent_ctx.cvm_state |= MMI_MMSV01_AGENT_CVM_STATE_SEND_PROCESS;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_vendor_send_rsp_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_rsp_struct *rsp = NULL;
    kal_uint8 vendor_result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (wap_mma_send_rsp_struct*)in_msg;

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_VENDOR_SEND_RSP_HDLR, rsp->result);

    if(rsp->result == MMA_RESULT_OK)
    {
        vendor_result = MMI_MMS_VENDOR_PASS;
    }
    else if(rsp->result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE) 
    {
        vendor_result = MMI_MMS_VENDOR_MEMORY_NOT_ENOUGH;
    }
    else if (rsp->result == MMA_RESULT_FAIL_USER_CANCEL)
    {
        vendor_result = MMI_MMS_VENDOR_USER_CANCEL;
    }
    else
    {
        vendor_result = MMI_MMS_VENDOR_FAIL;
    }

    

    /* Send RSP*/
    mmi_mmsv01_agent_send_vendor_send_rsp(rsp->msg_id , vendor_result);
    /*Change the state*/
    g_mmi_mms_V01_agent_ctx.cvm_state &= ~MMI_MMSV01_AGENT_CVM_STATE_SEND_PROCESS;
}

void mmi_mmsv01_agent_send_vendor_send_rsp(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mms_vendor_create_rsp_struct *msg_rsp;
    ilm_struct *ilm_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_rsp = (mmi_mms_vendor_create_rsp_struct*) OslConstructDataPtr(sizeof(mmi_mms_vendor_create_rsp_struct));

    msg_rsp->app_id = MMI_MMS_VENDOR_CVM_APP_ID;
    msg_rsp->msg_id = msg_id;

    
    msg_rsp->result = result;

    /* Send RSP*/
    ilm_ptr = allocate_ilm(MOD_MMI);

    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_MMI_SAP;
    ilm_ptr->dest_mod_id = MOD_MMI;    
    ilm_ptr->msg_id = MSG_ID_MMI_MMS_VENDOR_SEND_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_rsp;
    msg_send_ext_queue(ilm_ptr);
}



/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_vendor_cancel_send_req_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_mms_vendor_cancel_send_req_struct *msg_req = NULL;
    ilm_struct *ilm_ptr = NULL;
    mmi_mms_vendor_cancel_send_req_struct *vendor_req = (mmi_mms_vendor_cancel_send_req_struct*) in_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_VENDOR_CANCEL_SEND_REQ_HDLR);

    if(!mms_is_ready() ||
        /* Already a send request is in process*/
        !(g_mmi_mms_V01_agent_ctx.cvm_state & MMI_MMSV01_AGENT_CVM_STATE_SEND_PROCESS))
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_VRE_BUSY, g_mmi_mms_V01_agent_ctx.cvm_state);        
        mmi_mmsv01_agent_send_vendor_send_rsp(0 , MMI_MMS_VENDOR_FAIL);
        return;
    }
    

    /* Send request to SLIM MMA*/

    msg_req = (mmi_mms_vendor_cancel_send_req_struct*) construct_local_para(sizeof(mmi_mms_vendor_cancel_send_req_struct), TD_CTRL | TD_RESET);
   // msg_req->req_id = mma_get_request_id();


    msg_req->app_id = MMI_MMS_VENDOR_CVM_APP_ID;
    msg_req->msg_id = vendor_req->msg_id;   


    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_WAP_MMA_CANCEL_SEND_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_req;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);   
}



/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_vendor_cancel_send_rsp_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_rsp_struct *rsp = NULL;
    kal_uint8 vendor_result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (wap_mma_send_rsp_struct*)in_msg;

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_VRE_CANCEL_SEND_RSP, rsp->msg_id); 
    
}
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_vendor_delete_req_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mms_vendor_delete_req_struct *vendor_req = (mmi_mms_vendor_delete_req_struct*) in_msg;
    wap_mma_delete_req_struct *msg_req = NULL;
    ilm_struct *ilm_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_VENDOR_DELETE_REQ_HDLR);
    
    if(!mms_is_ready() ||
        /* Already a delete request is in process*/
        g_mmi_mms_V01_agent_ctx.cvm_state != MMI_MMSV01_AGENT_CVM_STATE_NONE)
    {
        mmi_mmsv01_agent_send_vendor_delete_rsp(vendor_req->msg_id, MMI_MMS_VENDOR_FAIL);
        return;
    }
    msg_req = (wap_mma_delete_req_struct*) OslConstructDataPtr(sizeof(wap_mma_delete_req_struct));
    msg_req->app_id = MMI_MMS_VENDOR_CVM_APP_ID;
   // msg_req->req_id = mma_get_request_id();
    msg_req->msg_id[0] = vendor_req->msg_id;
    msg_req->no_of_msg = 1;

    //Rahul:- Send Req    
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_WAP_MMA_DELETE_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_req;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    /*Change state*/
    g_mmi_mms_V01_agent_ctx.cvm_state |= MMI_MMSV01_AGENT_CVM_STATE_DELETE_PROCESS;
    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_vendor_delete_rsp_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;
    wap_mma_delete_rsp_struct *rsp = (wap_mma_delete_rsp_struct*) in_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_MMSV01_AGENT_VENDOR_DELETE_RSP_HDLR,rsp->result);

    if(rsp->result[0] == MMA_RESULT_OK)
    {
        result = MMI_MMS_VENDOR_PASS;
    }
    else if(rsp->result[0] == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE) 
    {
        result = MMI_MMS_VENDOR_MEMORY_NOT_ENOUGH;
    }
    else
    {
        result = MMI_MMS_VENDOR_FAIL;
    }
    
    mmi_mmsv01_agent_send_vendor_delete_rsp(rsp->msg_id[0], result);

    g_mmi_mms_V01_agent_ctx.cvm_state &= ~MMI_MMSV01_AGENT_CVM_STATE_DELETE_PROCESS;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mmsv01_agent_send_vendor_delete_rsp(kal_uint32 msg_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mms_vendor_delete_rsp_struct *msg_rsp;
    ilm_struct *ilm_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_rsp = (mmi_mms_vendor_delete_rsp_struct*) OslConstructDataPtr(sizeof(mmi_mms_vendor_delete_rsp_struct));
   
   // msg_rsp->app_id = g_umms_vendor_context->app_id;
    msg_rsp->msg_id = msg_id;
    msg_rsp->result = result;

    ilm_ptr = allocate_ilm(MOD_MMI);

    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_MMI_SAP;
    ilm_ptr->dest_mod_id = MOD_MMI;

    ilm_ptr->msg_id = MSG_ID_MMI_MMS_VENDOR_DELETE_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) msg_rsp;
    msg_send_ext_queue(ilm_ptr);
}
#endif /*__MMI_MMS_VENDOR_APP_SUPPORT__*/

void mmi_mmsv01_agent_sd_card_plug_out_hdlr(U32 notify_flag, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
	extern int wap_is_ready(void);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wap_is_ready())
    {
        return;
    }
#ifdef MEA_CFG_WARNING_MODE_SUPPORT
    if (g_warning_inst != NULL && g_warning_inst->data.file_path != NULL)
    {
        /*Check if file exists*/
        FS_HANDLE file_handle = 0;

        file_handle = FS_Open((const WCHAR*)g_warning_inst->data.file_path, FS_READ_ONLY);
        if (file_handle < 0)
        {
            mmi_mmsv01_agent_warning_go_back();
        }
        else
        {
            FS_Close(file_handle);
        }

    }
#endif 

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->msg_id = MSG_ID_WAP_MEM_CARD_PLUG_OUT;
    ilm_ptr->peer_buff_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}
#endif /* defined(OBIGO_Q03C_MMS_V01) */ 

