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
 *  VoIPMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_include.h"

#ifdef __MMI_VOIP__

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"

#include "ConnectManageGProt.h"

#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "VoIPProt.h"
#include "UcmSrvGProt.h"
#include "..\..\..\Service\UcmSrv\UcmSrvIntProt.h"
#include "CbmSrvGprot.h"
#include "ShutdownSrvGprot.h"

extern U32 voip_custom_get_max_call_num(void);

mmi_voip_cntx_struct g_voip_cntx;
mmi_voip_cntx_struct *g_voip_cntx_p = &g_voip_cntx;

extern srv_ucm_result_enum mmi_voip_ucm_act_permit_check(srv_ucm_call_type_enum call_type, srv_ucm_int_prmt_opcode_enum prmt_type, void *ptr);
extern void mmi_voip_ucm_act_req_cbk(srv_ucm_call_type_enum call_type, srv_ucm_int_act_opcode_enum act_op, void *act_data, void *user_data, srv_ucm_int_act_rsp_callback_func_ptr rsp_callback);
extern MMI_BOOL mmi_voip_ucm_utility_cbk(srv_ucm_call_type_enum call_type, srv_ucm_int_query_enum query_type, void *ptr);


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init
 * DESCRIPTION
 *  Initialize VoIP application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_voip_init_context();
    mmi_voip_init_protocol_hdlr();
    mmi_voip_init_register_ucm_cbk();
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_INIT);
    mmi_voip_entry_auto_login(); /* send request to voip cc in the background */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_deinit
 * DESCRIPTION
 *  Deinitialize VoIP application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->reg_state_info == MMI_VOIP_REG_STATE)
    {
        mmi_voip_deregister_req();
    }    
}


mmi_ret mmi_voip_main_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    switch (event->evt_id)
    {
    #ifdef __MMI_WLAN_FEATURES__
        case EVT_ID_SRV_DTCNT_WLAN_CONNECTED:
            if (g_voip_cntx_p->reg_state_info == MMI_VOIP_DEREG_STATE) /* wlan is connected but voip is deregistered */
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_WLAN);
                mmi_voip_entry_auto_login(); /* send request to voip cc in the background */
            }            
            break;
    #endif
        case EVT_ID_SRV_SHUTDOWN_DEINIT:
        {
            mmi_voip_deinit();
            break;
        }
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_context
 * DESCRIPTION
 *  Initialize all global context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_voip_init_setting_context();
    mmi_voip_init_call_context();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_setting_context
 * DESCRIPTION
 *  Initialize setting related global context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_setting_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U8 app_id = 0;
    cbm_app_info_struct app_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->reg_state_info = MMI_VOIP_DEREG_STATE;

//    g_voip_cntx_p->app_id = (kal_uint8)cbm_register_app_id(/*STR_ID_VOIP_MAIN, */&app_id);
    app_info.app_str_id = STR_ID_VOIP_MAIN;
    app_info.app_icon_id = IMG_ID_VOIP_MAIN;
    app_info.app_type = DTCNT_APPTYPE_DEF;
    g_voip_cntx_p->app_id = (kal_uint8)cbm_register_app_id_with_app_info (&app_info, &app_id);
    
    g_voip_cntx_p->app_id = app_id;

    //Leo
    //cbm_set_app_always_ask_bearer(g_voip_cntx_p->app_id, CBM_PS|CBM_WIFI);

    //Leo
    //mmi_cbm_register_acct_select_notify((U8)g_voip_cntx_p->app_id, mmi_voip_account_select_notify_cb);
    srv_cbm_register_bearer_event(SRV_CBM_BEARER_ALWAYS_ASK,
                            app_id,
                            mmi_voip_bear_event_callback,
                            NULL);

    g_voip_cntx_p->prof_setting_info.currDataAcct = 0xFF;

    memset(&g_voip_cntx_p->prof_setting_info, 0, sizeof(mmi_voip_prof_setting_struct));
    g_voip_cntx_p->prof_setting_info.actprofIndex = -1;

    memset(&g_voip_cntx_p->call_setting_info, 0, sizeof(mmi_voip_call_setting_struct));
    g_voip_cntx_p->call_setting_info.numCodec = MMI_VOIP_MAX_CODEC_NUM;

    for (i = 0; i < MMI_VOIP_MAX_PROFILE_NUM; i++)
    {
        mmi_voip_load_profile(i);
        /* register dda dtnct_id */
        //mmi_dtcnt_register_deletion_notify(g_voip_cntx_p->app_id,
        //                                                        g_voip_cntx_p->prof_setting_info.saved_prof[i].comm_info.dataAcct,
        //                                                        mmi_voip_dtcnt_delete_cb);

    }
    mmi_voip_load_profile_active_index();

    mmi_voip_load_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_call_context
 * DESCRIPTION
 *  Initialize call related global context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_call_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_voip_cntx_p->call_list_info, 0, sizeof(mmi_voip_call_list_struct));
    g_voip_cntx_p->call_list_info.maxnumCall = voip_custom_get_max_call_num();
    g_voip_cntx_p->call_list_info.processCId = -1;
    g_voip_cntx_p->call_list_info.processDId = -1;
    g_voip_cntx_p->call_list_info.bkrejCId = -1;
    g_voip_cntx_p->call_list_info.bkrejDId = -1;
    for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i++)
    {
        g_voip_cntx_p->call_list_info.call_info[i].callId = -1;
        for (j = 0; j < VOIP_MAX_NUM_DIALOG; j++)
        {
            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].dialogId = -1;
            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].rtpHandle = -1;
        }
    }
    for (i = 0; i < MMI_VOIP_MAX_HELD_CALL; i++)
    {
        g_voip_cntx_p->call_list_info.held_call_info[i].callId = -1;
    }

    memset(&g_voip_cntx_p->call_redial_info, 0, sizeof(mmi_voip_call_redial_struct));
    g_voip_cntx_p->call_redial_info.maxAttempt = 3;

    memset(&g_voip_cntx_p->dtmf_queue_info, 0, sizeof(mmi_voip_dtmf_queue_struct));
        
    memset(&g_voip_cntx_p->call_misc_info, 0, sizeof(mmi_voip_call_misc_struct));
    g_voip_cntx_p->call_misc_info.isDtmf = TRUE;

    memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
    
    memset(&g_voip_cntx_p->call_log_info, 0, sizeof(mmi_voip_call_log_struct));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_protocol_hdlr
 * DESCRIPTION
 *  Initialize all protocol handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_protocol_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_voip_register_rsp, MSG_ID_MMI_VOIP_REGISTER_RSP);
    SetProtocolEventHandler(mmi_voip_deregister_rsp, MSG_ID_MMI_VOIP_DEREGISTER_RSP);
    SetProtocolEventHandler(mmi_voip_deregister_ind, MSG_ID_MMI_VOIP_DEREGISTER_IND);
    SetProtocolEventHandler(mmi_voip_setting_rsp, MSG_ID_MMI_VOIP_SETTING_RSP);

    SetProtocolEventHandler(mmi_voip_progressing_ind, MSG_ID_MMI_VOIP_PROGRESSING_IND);
    SetProtocolEventHandler(mmi_voip_call_ring_ind, MSG_ID_MMI_VOIP_CALL_RING_IND);
    SetProtocolEventHandler(mmi_voip_call_end_ind, MSG_ID_MMI_VOIP_CALL_END_IND);
    SetProtocolEventHandler(mmi_voip_call_state_ind, MSG_ID_MMI_VOIP_CALL_STATE_IND);
    SetProtocolEventHandler(mmi_voip_call_replace_ind, MSG_ID_MMI_VOIP_CALL_REPLACE_IND);
    SetProtocolEventHandler(mmi_voip_call_replace_complete_ind, MSG_ID_MMI_VOIP_CALL_REPLACE_COMPLETE_IND);
    SetProtocolEventHandler(mmi_voip_background_reject_rsp, MSG_ID_MMI_VOIP_ACT_BK_REJ_RSP);
    SetProtocolEventHandler(mmi_voip_dispatch_call_act_rsp, MSG_ID_MMI_VOIP_CALL_ACT_RSP);

    SetProtocolEventHandler(mmi_voip_msg_waiting_ind, MSG_ID_MMI_VOIP_WAITING_MSG_IND);

    SetProtocolEventHandler(mmi_voip_at_call_ctrl_approve_ind, MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_init_register_ucm_cbk
 * DESCRIPTION
 *  register act, premit, utility callback function to ucm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_init_register_ucm_cbk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(srv_ucm_int_register_call_srv_act_callback(SRV_UCM_VOIP_CALL_TYPE, mmi_voip_ucm_act_req_cbk));
    ASSERT(srv_ucm_int_register_call_srv_permit_callback(SRV_UCM_VOIP_CALL_TYPE, mmi_voip_ucm_act_permit_check));
    ASSERT(srv_ucm_int_register_call_srv_query_callback(SRV_UCM_VOIP_CALL_TYPE, mmi_voip_ucm_utility_cbk));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_load_profile
 * DESCRIPTION
 *  Load profile data with specific index from NVRAM to
 *  g_voip_cntx_p->prof_setting_info.saved_prof[index].
 * PARAMETERS
 *  profIndex       [IN]        Index of intended to load profile
 * RETURNS
 *  TRUE means load success; FALSE means load fail.
 *****************************************************************************/
MMI_BOOL mmi_voip_load_profile(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S16 error;
    #ifndef __WIFI_SUPPORT__
    cbm_sim_id_enum sim_id;
    kal_uint8 app_id;
    kal_bool always_ask;
    kal_uint32 ori_acc_id;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((profIndex < 0) || (profIndex >= MMI_VOIP_MAX_PROFILE_NUM))
    {
        return FALSE;
    }

    result = ReadRecord(
                NVRAM_EF_VOIP_PROF_LID,
                (U16) (profIndex + 1),
                g_voip_cntx_p->prof_setting_info.saved_prof + profIndex,
                sizeof(mmi_voip_prof_struct),
                &error);
    if(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.dataAcct == -1)
    {
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.dataAcct= CBM_DEFAULT_ACCT_ID;
    }
    #ifndef __WIFI_SUPPORT__
    cbm_decode_data_account_id(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.dataAcct,
                                                    &sim_id,&app_id, &always_ask, &ori_acc_id);
    if(ori_acc_id == 20)
    {
        g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.dataAcct = 10;
        if(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.autoLogin == 1)
        {
            g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.autoLogin  = 0;
        }
    }
    #endif
    if (result < 0)
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_save_profile
 * DESCRIPTION
 *  Save g_voip_cntx_p->prof_setting_info.saved_prof[index] to NVRAM
 *  with profile data with specific index.
 * PARAMETERS
 *  profIndex       [IN]        Index of intended to save profile
 * RETURNS
 *  TRUE means save success; FALSE means save fail.
 *****************************************************************************/
MMI_BOOL mmi_voip_save_profile(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((profIndex < 0) || (profIndex >= MMI_VOIP_MAX_PROFILE_NUM))
    {
        return FALSE;
    }

    g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.dataAcct =
        cbm_set_app_id(g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].comm_info.dataAcct, g_voip_cntx_p->app_id);

    result = WriteRecord(
                NVRAM_EF_VOIP_PROF_LID,
                (U16) (profIndex + 1),
                g_voip_cntx_p->prof_setting_info.saved_prof + profIndex,
                sizeof(mmi_voip_prof_struct),
                &error);
    if (result < 0)
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_load_profile_active_index
 * DESCRIPTION
 *  Load activate profile index from NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_load_profile_active_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_VOIP_PROF_ACTIVATED, &data, DS_BYTE, &error);

    if (data == 0xFF)
    {
        data = 0;
        WriteValue(NVRAM_VOIP_PROF_ACTIVATED, &data, DS_BYTE, &error);
        g_voip_cntx_p->prof_setting_info.actprofIndex = -1;
    }
    else if (data == 0)
    {
        return;
    }
    else
    {
        if(mmi_voip_prof_validate_activation(data - 1) == 0)
        {
            g_voip_cntx_p->prof_setting_info.actprofIndex = data - 1;
        }
        else
        {
            g_voip_cntx_p->prof_setting_info.actprofIndex = 0;
            WriteValue(NVRAM_VOIP_PROF_ACTIVATED, &data, DS_BYTE, &error);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_save_profile_active_index
 * DESCRIPTION
 *  Save activate profile index to NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_save_profile_active_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = g_voip_cntx_p->prof_setting_info.actprofIndex + 1;
    WriteValue(NVRAM_VOIP_PROF_ACTIVATED, &data, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_load_setting
 * DESCRIPTION
 *  Load call setting data from NVRAM to
 *  g_voip_cntx_p->call_setting_info.saved_setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means load success; FALSE means load fail.
 *****************************************************************************/
MMI_BOOL mmi_voip_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result, i = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = ReadRecord(
                NVRAM_EF_VOIP_SETTING_LID,
                1,
                &g_voip_cntx_p->call_setting_info.saved_setting,
                sizeof(mmi_voip_setting_struct),
                &error);
    if (result < 0)
    {
        return FALSE;
    }

    /* check if codec order string empty */
    for (i = 0; i < MMI_VOIP_MAX_CODEC_NUM; i++)
    {
        if (!strlen((S8*)g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[i]))
        {
            mmi_ucs2_to_asc(
                (S8*)g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[i], 
                (S8*)GetString((U16)(STR_ID_VOIP_SETTING_CODEC2 + i)));
            MMI_ASSERT(g_voip_cntx_p->call_setting_info.saved_setting.codecOrder[i][MMI_VOIP_MAX_CODEC_NAME_LEN - 1] == '\0');
        }
    }
    /* set g_voip_cntx_p->call_setting_info.codecEnum */
    mmi_voip_update_setting_codec_cache_to_disp();
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_save_setting
 * DESCRIPTION
 *  Save g_voip_cntx_p->call_setting_info.saved_setting to NVRAM
 *  with call setting data.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means save success; FALSE means save fail.
 *****************************************************************************/
MMI_BOOL mmi_voip_save_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = WriteRecord(
                NVRAM_EF_VOIP_SETTING_LID,
                1,
                &g_voip_cntx_p->call_setting_info.saved_setting,
                sizeof(mmi_voip_setting_struct),
                &error);
    if (result < 0)
    {
        return FALSE;
    }

    return TRUE;
}
#endif /* __MMI_VOIP__ */

