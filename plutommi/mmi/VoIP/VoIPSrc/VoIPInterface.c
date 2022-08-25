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
 *  VoIPInterface.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "CallmanagementIdDef.h"
#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
#include "NetworkSetupDefs.h"
#endif
#include "PhoneBookDef.h"
#include "PhoneBookGprot.h"
#include "ProfileGprots.h"
#include "UCMGProt.h"

#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "VoIPProt.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "SimDetectionGprot.h"
#if defined(__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#include "..\..\..\Service\UcmSrv\UcmSrvIntProt.h"
#include "SettingGprots.h"
#include "ModeSwitchSrvGProt.h"
#include "NwUsabSrvGprot.h"

static U8 mmi_voip_ucm_act_opcode = 0;
static srv_ucm_int_act_rsp_callback_func_ptr g_voip_ucm_act_rsp;
void* g_voip_ucm_user_data = NULL;

static mmi_voip_keep_force_rel_call_struct g_voip_force_rel_call[MMI_VOIP_MAX_NUM_CALL * 2];
static U8 g_voip_force_rel_count = 0;
static U8 g_voip_force_rel_fail_count = 0;

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_app_get_register_state
 * DESCRIPTION
 *  Get VoIP register state. Mainly for preferred mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  VoIP register state, either MMI_VOIP_DEREG_STATE, MMI_VOIP_PROCESS_STATE, or MMI_VOIP_REG_STATE.
 *****************************************************************************/
mmi_voip_reg_state_enum mmi_voip_app_get_register_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_voip_cntx_p->reg_state_info;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_app_make_call
 * DESCRIPTION
 *  Make a VoIP call to the given URI. Mainly for phonebook and call history.
 * PARAMETERS
 *  unicodeUri      [IN]        Destination uri in unicode string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_app_make_call(U8 *unicodeUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_app_make_call(MMI_UCM_VOIP_CALL_TYPE, unicodeUri);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_app_set_conn_flag
 * DESCRIPTION
 *  Set the flag before disconnecting the other type of call.
 *  After disconnecting successfully, connect the given type of call.
 *  Mainly for the interaction of GSM and VoIP.
 * PARAMETERS
 *  needConn        [IN]        Need to connect what type of call
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_app_set_conn_flag(mmi_voip_call_conn_enum needConn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.needConn = needConn;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_app_get_conn_flag
 * DESCRIPTION
 *  Get the flag before connecting call so that we know what type of call that needs to connect.
 *  Mainly for the interaction of GSM and VoIP.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_VOIP_CALL_CONN_NONE means no need to connect call;
 *  MMI_VOIP_CALL_CONN_GSM means to connect gsm call;
 *  MMI_VOIP_CALL_CONN_VOIP means to connect voip call.
 *****************************************************************************/
mmi_voip_call_conn_enum mmi_voip_app_get_conn_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_voip_cntx_p->call_list_info.needConn;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_app_get_marker_screen
 * DESCRIPTION
 *  Get VoIP marker screen id so that other application can insert its screen 
 *  before VoIP call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  VoIP marker screen id.
 *****************************************************************************/
U16 mmi_voip_app_get_marker_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SCR_ID_VOIP_MARKER;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_need_msg_waiting_ind
 * DESCRIPTION
 *  Display message waiting screen in idle screen or not. Mainly for idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means need to show message waiting screen in idle;
 *  FALSE means need not to show message waiting screen in idle.
 *****************************************************************************/
U8 mmi_voip_need_msg_waiting_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_voip_cntx_p->msg_waiting_info.isDisp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_msg_waiting_ind
 * DESCRIPTION
 *  Message waiting screen in idle screen. Mainly for idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_msg_waiting_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 lskStr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_voip_cntx_p->msg_waiting_info.mwiStr, 0, MMI_VOIP_MAX_STRING_LEN);
    mmi_voip_get_mwi_string((U8*)g_voip_cntx_p->msg_waiting_info.mwiStr);

    if (mmi_voip_is_keypad_lock_state() == FALSE)
    {
        EntryNewScreen(SCR_ID_VOIP_MSG_WAITING, NULL, mmi_voip_entry_msg_waiting_ind, NULL);
        if ((g_voip_cntx_p->msg_waiting_info.mwiType == STR_ID_VOIP_VOICE_MESSAGE) &&
            (!strlen((S8*) g_voip_cntx_p->msg_waiting_info.mwiAcct)))
        {
            lskStr = STR_GLOBAL_DIAL;
            memset(g_voip_cntx_p->call_misc_info.dispUri, 0, VOIP_URI_LEN);
            mmi_asc_n_to_ucs2(
                (S8*) g_voip_cntx_p->call_misc_info.dispUri,
                (S8*) g_voip_cntx_p->msg_waiting_info.mwiAcct,
                VOIP_URI_LEN);
        }
        else
        {
            lskStr = 0;
        }
        ShowCategory141Screen(
            g_voip_cntx_p->msg_waiting_info.mwiType,
            GetRootTitleIcon(MENU_ID_VOIP_MAIN),
            lskStr,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8*)g_voip_cntx_p->msg_waiting_info.mwiStr,
            IMG_ID_VOIP_MSG_WAITING,
            NULL);
        if (lskStr)
        {
            SetLeftSoftkeyFunction(mmi_voip_pre_dial, KEY_EVENT_UP);
        }
        SetRightSoftkeyFunction(mmi_voip_go_back_to_idle, KEY_EVENT_UP);
        SetKeyHandler(mmi_voip_go_back_to_idle, KEY_END, KEY_EVENT_DOWN);
    }
    else    /* keypad lock */
    {
        ShowCategory141Screen(
            g_voip_cntx_p->msg_waiting_info.mwiType,
            GetRootTitleIcon(MENU_ID_VOIP_MAIN),
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (U8*)g_voip_cntx_p->msg_waiting_info.mwiStr,
            IMG_ID_VOIP_MSG_WAITING,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_go_back_to_idle
 * DESCRIPTION
 *  Handle RSK and END key in message waiting screen. Mainly for idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_go_back_to_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->msg_waiting_info.isDisp = FALSE;
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_msg_waiting_popup
 * DESCRIPTION
 *  Message waiting popup in other application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_msg_waiting_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 strId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_POPUP_SCREEN, NULL, NULL, NULL);
    strId = g_voip_cntx_p->msg_waiting_info.mwiType;
    ShowCategory65Screen((U8*) GetString(strId), IMG_GLOBAL_OK, NULL);
    SetGroupKeyHandler(NULL, (U16*) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(GoBackHistory, (U16*) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_map_voip2ucm_call_state
 * DESCRIPTION
 *  get call state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_call_state_enum mmi_voip_map_voip2ucm_call_state(mmi_voip_call_state_enum voip_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_state_enum ucm_state = SRV_UCM_IDLE_STATE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(voip_state)
    {
        case MMI_VOIP_OUTGOING_STATE:
            ucm_state = SRV_UCM_OUTGOING_STATE;
            break;
        case MMI_VOIP_INCOMING_STATE:
            ucm_state = SRV_UCM_INCOMING_STATE;
            break;
        case MMI_VOIP_ACTIVE_STATE:
        case MMI_VOIP_DISCONNECTING_STATE:
        case MMI_VOIP_HOLDING_STATE:
            ucm_state = SRV_UCM_ACTIVE_STATE;
            break;
        case MMI_VOIP_HOLD_STATE:
            ucm_state = SRV_UCM_HOLD_STATE;
            break;
        default:
            MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_MAP_VOIP2UCM_CALL_STATE, voip_state);
            break;
    };
    return ucm_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_add_call_to_force_rel_list
 * DESCRIPTION
 *  add force release group and call id into list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_add_call_to_force_rel_list(U16 group_id, U16 call_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 tmp_group_id, tmp_call_id;
    MMI_BOOL is_existed = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_voip_force_rel_fail_count; i++)
    {
        tmp_group_id = g_voip_force_rel_call[i].group_id;
        tmp_call_id = g_voip_force_rel_call[i].call_id;
        if (tmp_group_id == group_id && tmp_call_id == call_id)
        {
            is_existed = MMI_TRUE;
            break;
        }
    }
    if (is_existed == MMI_TRUE)
    {
        MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_ADD_CALL_TO_FORCE_REL_LIST_EXISTED,
                    group_id, call_id, g_voip_force_rel_fail_count, g_voip_force_rel_count);
        return;
    }
    
    if (g_voip_cntx_p->call_list_info.numTotal > 0)
    {
        ASSERT(g_voip_force_rel_fail_count < (MMI_VOIP_MAX_NUM_CALL * 2));
        g_voip_force_rel_call[g_voip_force_rel_fail_count].group_id = group_id;
        g_voip_force_rel_call[g_voip_force_rel_fail_count].call_id = call_id;
        g_voip_force_rel_fail_count++;
        g_voip_force_rel_count++;

        MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_ADD_CALL_TO_FORCE_REL_LIST_ADD_NEW,
                    group_id, call_id, g_voip_force_rel_fail_count, g_voip_force_rel_count);
    }
    else
    {
        MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_ADD_CALL_TO_FORCE_REL_LIST_NO_CALL,
                    group_id, call_id, g_voip_force_rel_fail_count, g_voip_force_rel_count);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_del_call_from_force_rel_list
 * DESCRIPTION
 *  delete force release group and call id into list
 *  after end call ind or fail release rsp.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_del_call_from_force_rel_list(U16 group_id, U16 call_id, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;
    MMI_BOOL is_found = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_TRUE)
    {
        for (i = 0; i < g_voip_force_rel_fail_count; i++)
        {
            if (g_voip_force_rel_call[i].group_id == group_id &&
                g_voip_force_rel_call[i].call_id == call_id)
            {
                for (j = i; j < (g_voip_force_rel_fail_count - 1); j++)
                {
                    memcpy(&(g_voip_force_rel_call[j]), &(g_voip_force_rel_call[j + 1]), sizeof(mmi_voip_keep_force_rel_call_struct));
                }
               
                g_voip_force_rel_fail_count--;
                g_voip_force_rel_count--;
                is_found = MMI_TRUE;
                break;
            }
        }
    }
    else
    {
        if (g_voip_cntx_p->call_list_info.numTotal > 0 && g_voip_force_rel_count > 0)
        {
            g_voip_force_rel_count--;
        }
    }

    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_DEL_CALL_FROM_FORCE_REL_LIST,
        group_id, call_id, result, is_found, g_voip_force_rel_fail_count, g_voip_force_rel_count);

    /* rel rest call */
    if (g_voip_force_rel_count == 0 && g_voip_force_rel_fail_count > 0)
    {
        U8 k;
        U16 ori_group_id, ori_call_id;
        U16 rel_group_id, rel_call_id;

        for (i = 0; i < g_voip_force_rel_fail_count; i++)
        {
            ori_group_id = g_voip_force_rel_call[i].group_id;
            ori_call_id = g_voip_force_rel_call[i].call_id;
            MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_DEL_CALL_FROM_FORCE_REL_LIST_REST_CALL, i, ori_group_id, ori_call_id);

            for (j = 0; j < g_voip_cntx_p->call_list_info.numTotal; j++)
            {
                for (k = 0; k < g_voip_cntx_p->call_list_info.call_info[j].numDialog; k++)
                {
                    if (g_voip_cntx_p->call_list_info.call_info[j].dialog_info[k].dialogIdx == ori_call_id)
                    {
                        rel_group_id = g_voip_cntx_p->call_list_info.call_info[j].callId;               
                        rel_call_id = g_voip_cntx_p->call_list_info.call_info[j].dialog_info[k].dialogId;

                        mmi_voip_switch_rtp(TRUE, -1, -1);
                        mmi_voip_release_req(rel_group_id, rel_call_id);
                        mmi_voip_force_release_req(rel_group_id, rel_call_id);
                    }
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_call_list
 * DESCRIPTION
 *  Assign VoIP call list to UCM call list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_get_call_list(srv_ucm_int_call_list_struct *callList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, numTotal = 0, rtpHandle = -1;
    S16 group_id = -1, call_id = -1, dialog_id = -1;
    U8 call_state = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(callList, 0, sizeof(srv_ucm_int_call_list_struct));
    
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_GET_CALL_LIST_GROUP, g_voip_cntx_p->call_list_info.numTotal);

    for (i = 0; i < g_voip_cntx_p->call_list_info.numTotal; i++)
    {
        for (j = 0; j < g_voip_cntx_p->call_list_info.call_info[i].numDialog; j++)
        {        
            MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_GET_CALL_LIST_CALL, i, g_voip_cntx_p->call_list_info.call_info[i].numDialog);

            callList->call_info[numTotal].uid_info.call_type = MMI_UCM_VOIP_CALL_TYPE;
            group_id = callList->call_info[numTotal].uid_info.group_id = (S16) g_voip_cntx_p->call_list_info.call_info[i].callId;
            dialog_id = callList->call_info[numTotal].uid_info.call_id = (S16) g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].dialogId;
            mmi_voip_ucm_get_log_name(
                callList->call_info[numTotal].uid_info.group_id, 
                callList->call_info[numTotal].uid_info.call_id, 
                callList->call_info[numTotal].remote_info.log_name);
            mmi_voip_ucm_get_disp_name(
                callList->call_info[numTotal].uid_info.group_id, 
                callList->call_info[numTotal].uid_info.call_id, 
                callList->call_info[numTotal].remote_info.disp_name);

            call_id = callList->call_info[numTotal].uid_info.call_id = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].dialogIdx;
            memcpy(callList->call_info[numTotal].remote_info.num_uri, g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].remoteUri, VOIP_URI_LEN);
            call_state = callList->call_info[numTotal].call_state = mmi_voip_map_voip2ucm_call_state(g_voip_cntx_p->call_list_info.call_info[i].currState);
            rtpHandle = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].rtpHandle;
            /* assign rtpHandle only for print trace */

            MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_GET_CALL_LIST_CALL_DETAIL, numTotal, i, j, group_id, call_id, dialog_id, call_state, rtpHandle);
            numTotal++;
        }
    }    
    callList->call_type = MMI_UCM_VOIP_CALL_TYPE;    
    callList->total_num = numTotal;

    for (i = 0; i < g_voip_force_rel_fail_count; i++)
    {
        group_id = g_voip_force_rel_call[i].group_id;
        call_id = g_voip_force_rel_call[i].call_id;

        for (j = 0; j < numTotal; j++)
        {
            if (callList->call_info[j].uid_info.call_id == call_id)
            {
                MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_GET_CALL_LIST_REPLACE_CALL, 
                    callList->call_info[j].uid_info.group_id, group_id, call_id);
                callList->call_info[j].uid_info.group_id = group_id;
                break;
            }
        }
    }

    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_GET_CALL_LIST_CALL_TOTAL, callList->total_num);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_log_name
 * DESCRIPTION
 *  Assign VoIP display name or application name to UCM log name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_get_log_name(S32 callId, S32 dialogId, U16* logName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(logName, 0, ((MMI_PHB_NAME_LENGTH + 1) * sizeof(U16)));
    callIndex = mmi_voip_get_call_index(callId);
    MMI_ASSERT(callId != -1);
    dialogIndex = mmi_voip_get_dialog_index(callIndex, dialogId);
    MMI_ASSERT(dialogIndex != -1);
    
    if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName) != 0)
    {
        mmi_ucs2ncpy(
            (S8*)logName,
            (S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName, 
            MMI_PHB_NAME_LENGTH);
    }
    else if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].appName) != 0)
    {
        mmi_ucs2ncpy(
            (S8*)logName, 
            (S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].appName, 
            MMI_PHB_NAME_LENGTH);
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_UCM_GET_LOG_NAME);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_disp_name
 * DESCRIPTION
 *  Assign VoIP display name, application name, or uri to UCM display name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_get_disp_name(S32 callId, S32 dialogId, U16 *dispName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dispName, 0, ((SRV_UCM_MAX_DISP_NAME_LEN + 1) * sizeof(U16)));
    callIndex = mmi_voip_get_call_index(callId);
    MMI_ASSERT(callId != -1);
    dialogIndex = mmi_voip_get_dialog_index(callIndex, dialogId);
    MMI_ASSERT(dialogIndex != -1);

    if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName) != 0)
    {
        mmi_ucs2ncpy(
            (S8*)dispName, 
            (S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName, 
            SRV_UCM_MAX_DISP_NAME_LEN);
    }
    else if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].appName) != 0)
    {
        mmi_ucs2ncpy(
            (S8*)dispName, 
            (S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].appName, 
            SRV_UCM_MAX_DISP_NAME_LEN);
    }
    else
    {
        mmi_asc_n_to_ucs2(
            (S8*)dispName, 
            (S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri,
            SRV_UCM_MAX_DISP_NAME_LEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_num_uri
 * DESCRIPTION
 *  Assign VoIP uri to UCM num and uri.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_get_num_uri(S32 callId, S32 dialogId, U8* numUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(numUri, 0, SRV_UCM_MAX_NUM_URI_LEN + 1);
    callIndex = mmi_voip_get_call_index(callId);
    MMI_ASSERT(callId != -1);
    dialogIndex = mmi_voip_get_dialog_index(callIndex, dialogId);
    MMI_ASSERT(dialogIndex != -1);

    memcpy(numUri, g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri, SRV_UCM_MAX_NUM_URI_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_speech_direction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_get_speech_direction(S32 rtpDirection, MMI_BOOL *localSwitch, MMI_BOOL *remoteSwitch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rtpDirection)
    {
        case VOIP_RTP_DIRECTION_SENDRECV: /* send and receive */
            *localSwitch = TRUE;
            *remoteSwitch = TRUE;
            break;
        case VOIP_RTP_DIRECTION_SENDONLY: /* send only */
            *localSwitch = TRUE;
            *remoteSwitch = FALSE;
            break;
        case VOIP_RTP_DIRECTION_RECVONLY: /* receive only */
            *localSwitch = FALSE;
            *remoteSwitch = TRUE;
            break;
        case VOIP_RTP_DIRECTION_INACTIVE: /* inactive */
            *localSwitch = FALSE;
            *remoteSwitch = FALSE;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_rtp_direction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_get_rtp_direction(MMI_BOOL localSwitch, MMI_BOOL remoteSwitch, S32 *rtpDirection)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((localSwitch == TRUE) && (remoteSwitch == TRUE))
    {
        *rtpDirection = VOIP_RTP_DIRECTION_SENDRECV;
    }
    else if ((localSwitch == TRUE) && (remoteSwitch == FALSE))
    {
        *rtpDirection = VOIP_RTP_DIRECTION_SENDONLY;
    }
    else if ((localSwitch == FALSE) && (remoteSwitch == TRUE))
    {
        *rtpDirection = VOIP_RTP_DIRECTION_RECVONLY;
    }
    else
    {
        *rtpDirection = VOIP_RTP_DIRECTION_INACTIVE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_act_opcode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_voip_ucm_get_act_opcode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    return mmi_voip_ucm_act_opcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_dial_req_permit_ext
 * DESCRIPTION
 *  check if voip call dial is allowed now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_dial_req_permit_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    S32 outgoingcallId = 0, incomingcallId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    // if not registered, then should prompt "log in?"
    if (g_voip_cntx_p->reg_state_info == MMI_VOIP_REG_STATE)
    {
        outgoingcallId = mmi_voip_get_outgoing_call_id();
        if (outgoingcallId != -1)
        {
            return SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
        }

        incomingcallId = mmi_voip_get_incoming_call_id();
        if (incomingcallId != -1)
        {
            return SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
        }

        if ((mmi_voip_is_codec_compatible(g_voip_cntx_p->call_setting_info.codecEnum, FALSE)) &&
            (g_voip_cntx_p->call_list_info.numTotal > MMI_VOIP_MAX_NUM_CALL))
        {
            return SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
        }
    }
    else
    {
        return SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
    }

    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_dial_req_permit
 * DESCRIPTION
 *  check if voip srv is available now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_dial_req_permit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    S32 activecallId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    // if not registered, then should prompt "log in?"
    if (g_voip_cntx_p->reg_state_info == MMI_VOIP_REG_STATE)
    {
        activecallId = mmi_voip_get_active_call_id();
        if (activecallId != -1)
        {
            return SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
        }
    }
    return mmi_voip_dial_req_permit_ext();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_accept_req_permit_ext
 * DESCRIPTION
 *  check if accept req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_accept_req_permit_ext(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_prmt_struct *acceptPrmt = (srv_ucm_int_single_call_act_prmt_struct*)prmtStruct;
    S32 outgoingcallId = 0, incomingcallId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    outgoingcallId = mmi_voip_get_outgoing_call_id();
    if (outgoingcallId != -1)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }

    incomingcallId = mmi_voip_get_incoming_call_id();
    if (incomingcallId != acceptPrmt->action_uid.group_id)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
    
    ASSERT((acceptPrmt->action_uid.call_type & SRV_UCM_VOIP_CALL_TYPE) == SRV_UCM_VOIP_CALL_TYPE);

    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_accept_req_permit
 * DESCRIPTION
 *  check if accept req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_accept_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_prmt_struct *acceptPrmt = (srv_ucm_int_single_call_act_prmt_struct*)prmtStruct;
    S32 activecallId = 0, outgoingcallId = 0, incomingcallId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    activecallId = mmi_voip_get_active_call_id();
    if (activecallId != -1)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }

    return mmi_voip_accept_req_permit_ext(acceptPrmt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hold_req_permit
 * DESCRIPTION
 *  check if hold req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_hold_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    S32 activecallId = 0;
    srv_ucm_int_single_group_act_prmt_struct *holdPrmt = (srv_ucm_int_single_group_act_prmt_struct*)prmtStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    activecallId = mmi_voip_get_active_call_id();
    if (activecallId == -1)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
    // ing call = active
    if (holdPrmt->action_group != activecallId)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_retrieve_req_permit
 * DESCRIPTION
 *  check if retrieve req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_retrieve_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    S32 activecallId = 0;
    srv_ucm_int_single_group_act_prmt_struct *retrievePrmt = (srv_ucm_int_single_group_act_prmt_struct*)prmtStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    activecallId = mmi_voip_get_active_call_id();
    if (activecallId != -1)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }

    if (!mmi_voip_query_call_count(MMI_VOIP_HOLD_STATE) > 0)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
// should check no active call?
// should check if there is any hold call? API?
// ucm_30 need_attention
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_swap_req_permit
 * DESCRIPTION
 *  check if swap req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_swap_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    S32 activecallId = 0;
    srv_ucm_int_multiple_group_act_prmt_struct *swapPrmt = (srv_ucm_int_multiple_group_act_prmt_struct*)prmtStruct;
    mmi_voip_call_list_struct *call_list = &g_voip_cntx_p->call_list_info;
    mmi_voip_call_struct *call = NULL;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    activecallId = mmi_voip_get_active_call_id();
    if (activecallId == -1)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
    
    for (i = 0; i < call_list->numTotal; i++)
    {
        call = &(call_list->call_info[i]);
        if (call->callId == swapPrmt->active_group)
        {
            if (call->currState != MMI_VOIP_ACTIVE_STATE)
            {
                return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
            }
        }
        else if (call->callId == swapPrmt->other_group)
        {
            if (call->currState != MMI_VOIP_HOLD_STATE)
            {
                return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
            }
        }
    }

// should check if there is any hold call? API?
// 1 A 1H
// ucm_30 need_attention
// ing call = (active and hold)

    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_conference_req_permit
 * DESCRIPTION
 *  check if conference req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_conference_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    srv_ucm_int_multiple_group_act_prmt_struct *conferencePrmt = (srv_ucm_int_multiple_group_act_prmt_struct*)prmtStruct;
    mmi_voip_call_list_struct *call_list = &g_voip_cntx_p->call_list_info;
    mmi_voip_call_struct *call = NULL;
    S32 activecallId = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    activecallId = mmi_voip_get_active_call_id();
    if (activecallId == -1)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
    
    for (i = 0; i < call_list->numTotal; i++)
    {
        call = &(call_list->call_info[i]);
        if (call->callId == conferencePrmt->active_group)
        {
            if (call->numDialog > 1 || call->currState != MMI_VOIP_ACTIVE_STATE)
            {
                return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
            }
        }
        else if (call->callId == conferencePrmt->other_group)
        {
            if (call->numDialog > 1 || call->currState != MMI_VOIP_HOLD_STATE)
            {
                return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
            }
        }
    }
// total >= 2
// at least 1A1H

// should check if there is any hold call? API?
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_split_req_permit
 * DESCRIPTION
 *  check if split req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_split_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_prmt_struct *splitPrmt = (srv_ucm_int_single_call_act_prmt_struct*)prmtStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
// at least 1 conference call
// ing call = conference
// should check if there is active call
// should check if there is any hold call? API?
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_transfer_req_permit
 * DESCRIPTION
 *  check if transfer req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_transfer_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    S32 activecallId = 0;
    srv_ucm_int_cd_or_ct_act_prmt_struct *transferPrmt = (srv_ucm_int_cd_or_ct_act_prmt_struct*)prmtStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    /* check the ing call = active call */
    activecallId = mmi_voip_get_active_call_id();
    if (activecallId == -1 || activecallId != transferPrmt->action_uid.group_id)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
// should check if there is active call
// should check if there is any hold call? API?
// ing call = active
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_end_single_req_permit
 * DESCRIPTION
 *  check if end single req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_end_single_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_prmt_struct *endPrmt = (srv_ucm_int_single_call_act_prmt_struct*)prmtStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    // 0915, ing call = active, not necessary
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_end_conference_req_permit
 * DESCRIPTION
 *  check if end conference req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_end_conference_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_group_act_prmt_struct *endPrmt = (srv_ucm_int_single_group_act_prmt_struct*)prmtStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    // ing call = conference
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_end_all_req_permit
 * DESCRIPTION
 *  check if end all req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_end_all_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    if (mmi_voip_query_call_count(MMI_VOIP_CALL_STATE_ALL) == 0)
    {
       return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
// should check if there is active call
// should check if there is any hold call? API?
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_force_release_req_permit
 * DESCRIPTION
 *  check if end all req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_force_release_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
// should check if there is active call
// should check if there is any hold call? API?
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_auto_reject_req_permit
 * DESCRIPTION
 *  check if end all req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_auto_reject_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_prmt_struct *rejectPrmt = (srv_ucm_int_single_call_act_prmt_struct*)prmtStruct;
    S32 incomingcallId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    incomingcallId = mmi_voip_get_incoming_call_id();
    if (incomingcallId != rejectPrmt->action_uid.group_id)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }

    ASSERT((rejectPrmt->action_uid.call_type & SRV_UCM_VOIP_CALL_TYPE) == SRV_UCM_VOIP_CALL_TYPE);

    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_explicit_call_transfer_req_permit
 * DESCRIPTION
 *  check if end all req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_explicit_call_transfer_req_permit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
// should check if there is active call
// should check if there is any hold call? API?
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_start_dtmf_req_permit
 * DESCRIPTION
 *  check if hold and accept req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_start_dtmf_req_permit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    S32 activecallId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
//    SRV_UCM_INT_HOLD_AND_ACCEPT_PRMT, /* srv_ucm_int_hold_and_accept_act_prmt_struct, srv_ucm_result_enum */
// ing call = active
// mt = incoming
    activecallId = mmi_voip_get_active_call_id();
    if (activecallId == -1)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }

// no, should check if there is any hold call? API?
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_stop_dtmf_req_permit
 * DESCRIPTION
 *  check if hold and accept req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_stop_dtmf_req_permit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    S32 activecallId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
//    SRV_UCM_INT_HOLD_AND_ACCEPT_PRMT, /* srv_ucm_int_hold_and_accept_act_prmt_struct, srv_ucm_result_enum */
// ing call = active
// mt = incoming
    activecallId = mmi_voip_get_active_call_id();
    if (activecallId == -1)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }

// no, should check if there is any hold call? API?
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_end_all_n_dial_req_permit
 * DESCRIPTION
 *  check if end all req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_end_all_n_dial_req_permit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    S32 activecallId = 0;
    srv_ucm_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    // should check outgoing, incoming call, in call
    result = mmi_voip_dial_req_permit_ext();
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_end_all_n_accept_req_permit
 * DESCRIPTION
 *  check if end all req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_end_all_n_accept_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_prmt_struct *acceptPrmt = (srv_ucm_int_single_call_act_prmt_struct*)prmtStruct;
    srv_ucm_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    result = mmi_voip_accept_req_permit_ext(acceptPrmt);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_end_all_active_n_retrieve_req_permit
 * DESCRIPTION
 *  check if end all req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_end_all_active_n_retrieve_req_permit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    // accept
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_end_all_active_n_accept_req_permit
 * DESCRIPTION
 *  check if end all req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_end_all_active_n_accept_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_prmt_struct *acceptPrmt = (srv_ucm_int_single_call_act_prmt_struct*)prmtStruct;
    S32 activecallId = 0;
    srv_ucm_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    /* there should be at least active call */
    activecallId = mmi_voip_get_active_call_id();
    if (activecallId == -1)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }

    result = mmi_voip_accept_req_permit_ext(acceptPrmt);
    return result;
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hold_n_dial_req_permit
 * DESCRIPTION
 *  check if hold and dial req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_hold_n_dial_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    srv_ucm_int_hold_and_dial_act_prmt_struct *dialPrmt = (srv_ucm_int_hold_and_dial_act_prmt_struct*)prmtStruct;
    S32 activecallId = 0;
    srv_ucm_result_enum dial_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    /* active_call_id equal */
    activecallId = mmi_voip_get_active_call_id();
    if (activecallId == -1 || activecallId != dialPrmt->active_group)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }

    dial_result = mmi_voip_dial_req_permit_ext();
    return dial_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hold_n_accept_req_permit
 * DESCRIPTION
 *  check if hold and accept req is permit now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_hold_n_accept_req_permit(void *prmtStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    srv_ucm_int_hold_and_accept_act_prmt_struct *acceptPrmt = (srv_ucm_int_hold_and_accept_act_prmt_struct*)prmtStruct;
    S32 activecallId = 0, incomingcallId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    /* active_call_id equal */
    activecallId = mmi_voip_get_active_call_id();
    if (activecallId == -1 || activecallId != acceptPrmt->action_group)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }

    /* incoming_call_id equal */
    incomingcallId = mmi_voip_get_incoming_call_id();
    if (incomingcallId == -1 || incomingcallId != acceptPrmt->mt_call_uid.group_id)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }

    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_act_permit_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_voip_ucm_act_permit_check(srv_ucm_call_type_enum call_type, srv_ucm_int_prmt_opcode_enum prmt_type, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum result = SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    ASSERT((call_type & SRV_UCM_VOIP_CALL_TYPE) == SRV_UCM_VOIP_CALL_TYPE);

    switch(prmt_type)
    {
        case SRV_UCM_INT_DIAL_PRMT:
        {
            result = mmi_voip_dial_req_permit();
            break;
        }
        case SRV_UCM_INT_ACCEPT_PRMT:
        {
            result = mmi_voip_accept_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_HOLD_PRMT:
        {
            result = mmi_voip_hold_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_RETRIEVE_PRMT:
        {
            result = mmi_voip_retrieve_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_SWAP_PRMT:
        {
            result = mmi_voip_swap_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_CONFERENCE_PRMT:
        {
            result = mmi_voip_conference_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_SPLIT_PRMT:
        {
            result = mmi_voip_split_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_DEFLECT_PRMT:
        {
            result = SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
            break;
        }
        case SRV_UCM_INT_TRANSFER_PRMT:
        {
            result = mmi_voip_transfer_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_END_SINGLE_PRMT:
        {
            result = mmi_voip_end_single_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_END_CONFERENCE_PRMT:
        {
            result = mmi_voip_end_conference_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_END_ALL_PRMT:
        {
            result = mmi_voip_end_all_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_FORCE_RELEASE_PRMT:
        {
            result = mmi_voip_force_release_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_AUTO_REJECT_PRMT:
        {
            result = mmi_voip_auto_reject_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_PRMT:
        {
            result = mmi_voip_explicit_call_transfer_req_permit();
            break;
        }
        case SRV_UCM_INT_START_DTMF_PRMT:
        {
            result = mmi_voip_start_dtmf_req_permit();
            break;
        }
        case SRV_UCM_INT_STOP_DTMF_PRMT:
        {
            result = mmi_voip_stop_dtmf_req_permit();
            break;
        }
        case SRV_UCM_INT_END_ALL_AND_DIAL_PRMT:
        {
            result = mmi_voip_end_all_n_dial_req_permit();
            break;
        }
        case SRV_UCM_INT_END_ALL_AND_ACCEPT_PRMT:
        {
            result = mmi_voip_end_all_n_accept_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_END_ALL_ACTIVE_AND_RETRIEVE_PRMT:
        {
            result = mmi_voip_end_all_active_n_retrieve_req_permit();
            break;
        }
        case SRV_UCM_INT_END_ALL_ACTIVE_AND_ACCEPT_PRMT:
        {
            result = mmi_voip_end_all_active_n_accept_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_HOLD_AND_DIAL_PRMT:
        {
            result = mmi_voip_hold_n_dial_req_permit(ptr);
            break;
        }
        case SRV_UCM_INT_HOLD_AND_ACCEPT_PRMT:
        {
            result = mmi_voip_hold_n_accept_req_permit(ptr);
            break;
        }
        default:
        {
            ASSERT(0);
            break;
        }
    }
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_ACT_PERMIT_CHECK, prmt_type, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_act_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_act_req(U8 opCode, void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_ACT_REQ, opCode);

    mmi_voip_ucm_act_opcode = opCode;
    switch (opCode)
    {
        case SRV_UCM_INT_DIAL_ACT:
            mmi_voip_ucm_dial_req(actStruct);
            break;
        case SRV_UCM_INT_ACCEPT_ACT:
            mmi_voip_ucm_accept_req(actStruct);
            break;
        case SRV_UCM_INT_HOLD_ACT:
            mmi_voip_ucm_hold_req(actStruct);
            break;
        case SRV_UCM_INT_RETRIEVE_ACT:
            mmi_voip_ucm_retrieve_req(actStruct);
            break;
        case SRV_UCM_INT_SWAP_ACT:
            mmi_voip_ucm_swap_req(actStruct);
            break;
        case SRV_UCM_INT_CONFERENCE_ACT:
            mmi_voip_ucm_conference_req(actStruct);
            break;
        case SRV_UCM_INT_SPLIT_ACT:
            mmi_voip_ucm_split_req(actStruct);
            break;
        case SRV_UCM_INT_TRANSFER_ACT:
            mmi_voip_ucm_transfer_req(actStruct);
            break;
        case SRV_UCM_INT_END_SINGLE_ACT:
            mmi_voip_ucm_end_single_req(actStruct);
            break;
        case SRV_UCM_INT_END_CONFERENCE_ACT:
            mmi_voip_ucm_end_conference_req(actStruct);
            break;
        case SRV_UCM_INT_END_ALL_ACT:
            mmi_voip_ucm_end_all_req(actStruct);
	        break;
        case SRV_UCM_INT_FORCE_RELEASE_ACT:
            mmi_voip_ucm_force_release_req(actStruct);
            break;
        case SRV_UCM_INT_AUTO_REJECT_ACT:
            mmi_voip_ucm_background_reject_req(actStruct);
            break;
        case SRV_UCM_INT_START_DTMF_ACT:
            mmi_voip_ucm_start_dtmf(actStruct);
            break;
        case SRV_UCM_INT_STOP_DTMF_ACT:
            mmi_voip_ucm_stop_dtmf(actStruct);
            break;
        default:
            /* including
                SRV_UCM_INT_NO_ACT
                SRV_UCM_INT_DEFLECT_ACT
                SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_ACT */
            MMI_ASSERT(0); /* not valid action */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_act_req_err_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_act_req_err_hdlr(srv_ucm_int_act_opcode_enum act_op, srv_ucm_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_ACT_REQ_ERR_HDLR, act_op, result);

    if (act_op == SRV_UCM_INT_DIAL_ACT)
    {        
        mmi_voip_ucm_dial_act_rsp(act_op, SRV_UCM_INVALID_ID, SRV_UCM_INVALID_ID, FALSE, (U8*)GetString(STR_ID_VOIP_NOT_ALLOW_TO_DIAL));
    }
    else
    {
        mmi_voip_ucm_act_rsp(act_op, FALSE, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_act_req_cbk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_act_req_cbk(srv_ucm_call_type_enum call_type, srv_ucm_int_act_opcode_enum act_op, void *act_data, void *user_data, srv_ucm_int_act_rsp_callback_func_ptr rsp_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum result = SRV_UCM_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((call_type & SRV_UCM_VOIP_CALL_TYPE) == SRV_UCM_VOIP_CALL_TYPE);

    // assign callback here
    g_voip_ucm_act_rsp = rsp_callback;
    g_voip_ucm_user_data = user_data;

    result = mmi_voip_ucm_act_permit_check(call_type, act_op, act_data);
    if (result != SRV_UCM_RESULT_OK)
    {
        mmi_voip_ucm_act_req_err_hdlr(act_op, result);
        return;
    }

    mmi_voip_ucm_act_req(act_op, act_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_dial_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_dial_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 activecallId = 0;
    S32 asciiLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
    activecallId = mmi_voip_get_active_call_id();
    if (activecallId != -1)
    {
        ASSERT(0);
    }
    else
    {
        srv_ucm_int_dial_act_req_struct *dialReq = (srv_ucm_int_dial_act_req_struct*)actStruct;

        asciiLen = ((VOIP_URI_LEN - 1) > strlen((S8*)dialReq->num_uri)) ? (strlen((S8*)dialReq->num_uri)) : (VOIP_URI_LEN - 1);
        memset(g_voip_cntx_p->call_misc_info.dispUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
        mmi_asc_n_to_ucs2((S8*)g_voip_cntx_p->call_misc_info.dispUri, (S8*)dialReq->num_uri, asciiLen);
    }    
    mmi_voip_set_outgoing_origin_app(MMI_VOIP_PHB);
    mmi_voip_set_outgoing_origin_app(MMI_VOIP_HISTORY);
    
    mmi_voip_pre_dial();

 /* pay attention here */
//    mmi_phb_call_set_dial_from_list(MMI_PHB_NONE);  /* reset dial from phonebook flag */
//    CHISTSetDialFromCallLogFlag(0);                 /* reset dial from call history flag */   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_accept_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_accept_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mtcallId = 0, activecallId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mtcallId = mmi_voip_get_incoming_call_id();
    if (mtcallId != -1)
    {    
        activecallId = mmi_voip_get_active_call_id();
        if (activecallId != -1)
        {
            /* should not have any active call */
            ASSERT(0);
        }
        else
        {
            srv_ucm_int_single_call_act_req_struct *acceptReq = (srv_ucm_int_single_call_act_req_struct*)actStruct;
            
            MMI_ASSERT(acceptReq->action_uid.group_id == mtcallId); /* incoming call id does not match */
            mmi_voip_switch_session(MMI_VOIP_ACTIVE_STATE);
            mmi_voip_accept_req(acceptReq->action_uid.group_id);
        }
    }
    else
    {
        MMI_ASSERT(mtcallId != -1); /* incoming call does not exist */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_hold_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_hold_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_group_act_req_struct *holdReq = (srv_ucm_int_single_group_act_req_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_hold_req(holdReq->action_group);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_retrieve_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_retrieve_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_group_act_req_struct *retrieveReq = (srv_ucm_int_single_group_act_req_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_retrieve_req(retrieveReq->action_group);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_swap_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_swap_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_multiple_group_act_req_struct *swapReq = (srv_ucm_int_multiple_group_act_req_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_swap_req(swapReq->active_group, swapReq->other_group);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_conference_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_conference_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_multiple_group_act_req_struct *confReq = (srv_ucm_int_multiple_group_act_req_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_merge_req(confReq->active_group, confReq->other_group);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_split_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_split_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_req_struct *splitReq = (srv_ucm_int_single_call_act_req_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_split_req(splitReq->action_uid.group_id, mmi_voip_get_actual_dialog_id(splitReq->action_uid.call_id));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_transfer_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_transfer_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_cd_or_ct_act_req_struct *transferReq = (srv_ucm_int_cd_or_ct_act_req_struct*)actStruct;
    U8 *unicodeUri = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    U8 *unicodeOwner = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    S32 profIndex = g_voip_cntx_p->prof_setting_info.actprofIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    memset(g_voip_cntx_p->call_misc_info.inputUri, 0, VOIP_URI_LEN);

    memset(unicodeUri, 0, VOIP_URI_LEN);
    mmi_asc_n_to_ucs2(
        (S8*)unicodeUri, 
        (S8*)transferReq->num_uri, 
        VOIP_URI_LEN - 1);
    mmi_voip_parse_uri(unicodeUri);

    memset(unicodeOwner, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)unicodeOwner, 
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.username, 
        VOIP_URI_LEN);
    if (mmi_voip_is_owner_number(unicodeUri, unicodeOwner) == TRUE)
    {
        mmi_voip_ucm_act_rsp(SRV_UCM_INT_TRANSFER_ACT, FALSE, (U8*)GetString(STR_ID_VOIP_TRANSFER_FAIL));
    }
    else
    {
        if (mmi_voip_validate_uri(unicodeUri) == TRUE)
        {
            memset(g_voip_cntx_p->call_misc_info.inputUri, 0, VOIP_URI_LEN);
            mmi_ucs2_n_to_asc(
                (S8*)g_voip_cntx_p->call_misc_info.inputUri,
                (S8*)unicodeUri,
                (VOIP_URI_LEN * ENCODING_LENGTH));
            mmi_voip_transfer_req(transferReq->action_uid.group_id, mmi_voip_get_actual_dialog_id(transferReq->action_uid.call_id));
        }
        else
        {
            mmi_voip_ucm_act_rsp(SRV_UCM_INT_TRANSFER_ACT, FALSE, (U8*)GetString(STR_ID_VOIP_TRANSFER_FAIL));
        }
    }
    OslMfree(unicodeUri);
    OslMfree(unicodeOwner);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_end_single_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_end_single_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_req_struct *releaseReq = (srv_ucm_int_single_call_act_req_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_VOIP_CALL_TYPE, NULL) > 0)
    {
        mmi_voip_entry_abort_call();
    }
    else
    {
        /* set all rtp directions as inactive before action */
        mmi_voip_switch_rtp(TRUE, -1, -1);
        mmi_voip_release_req(releaseReq->action_uid.group_id, mmi_voip_get_actual_dialog_id(releaseReq->action_uid.call_id));
        mmi_voip_force_release_req(releaseReq->action_uid.group_id, mmi_voip_get_actual_dialog_id(releaseReq->action_uid.call_id));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_end_conference_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_end_conference_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_group_act_req_struct *releaseReq = (srv_ucm_int_single_group_act_req_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_release_req(releaseReq->action_group, -1);
    mmi_voip_force_release_req(releaseReq->action_group, -1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_end_all_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_end_all_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_release_req(-1, -1);
    mmi_voip_force_release_req(-1, -1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_force_release_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_force_release_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_single_call_act_req_struct *releaseReq = (srv_ucm_int_single_call_act_req_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_VOIP_CALL_TYPE, NULL) > 0)
    {
        return;
    }
    else
    {
        mmi_voip_add_call_to_force_rel_list(releaseReq->action_uid.group_id, releaseReq->action_uid.call_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_background_reject_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_background_reject_req(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_ucm_int_single_call_act_req_struct *releaseReq = (srv_ucm_int_single_call_act_req_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_voip_background_reject_req(releaseReq->action_uid.group_id, mmi_voip_get_actual_dialog_id(releaseReq->action_uid.call_id));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_start_dtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_start_dtmf(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_ucm_dtmf_struct *startDTMFReq = (srv_ucm_dtmf_struct*)actStruct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_START_DTMF, startDTMFReq->digit);
    mmi_voip_dtmf_key_down(startDTMFReq->digit);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_stop_dtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_stop_dtmf(void *actStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_STOP_DTMF);

    mmi_voip_dtmf_key_up();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_dial_act_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  opCode          [IN]            Operation code
 *  groupId         [IN]            VoIP call id
 *  callId          [IN]            VoIP dialog id
 *  result          [IN]            Result, TRUE or FALSE
 *  dispMsg         [IN]            Error message if result is FALSE
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_dial_act_rsp(U8 opCode, S32 groupId, S32 callId, U8 result, U8 *dispMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_dial_act_rsp_struct *dialRsp = OslMalloc(sizeof(srv_ucm_int_dial_act_rsp_struct));
    srv_ucm_int_call_list_struct *callList = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    MMI_BOOL get_disp_name = MMI_FALSE;
    U32 alert_type = 0, light_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dialRsp, 0, sizeof(srv_ucm_int_dial_act_rsp_struct));
    if (result == TRUE)
    {
        dialRsp->result_info.result = SRV_UCM_RESULT_OK;
    }
    else
    {
        dialRsp->result_info.result = SRV_UCM_RESULT_UNSPECIFIED_ERROR;
    }
    if (dispMsg != NULL)
    {
        mmi_ucs2ncpy((S8*) &dialRsp->result_info.error_msg, (S8*) dispMsg, SRV_UCM_MAX_ERR_MSG_LEN);
    }

    mmi_asc_n_to_ucs2((S8*)g_voip_cntx_p->call_misc_info.dispUri, (S8*)g_voip_cntx_p->call_misc_info.inputUri, VOIP_URI_LEN);

    get_disp_name = mmi_voip_get_outgoing_disp_name(
            MMI_VOIP_PHB|MMI_VOIP_HISTORY|MMI_VOIP_SOS, 
            g_voip_cntx_p->call_misc_info.dispUri, 
            g_voip_cntx_p->call_misc_info.dispUri, 
            VOIP_URI_LEN);

    mmi_ucs2ncpy((S8*)dialRsp->remote_info.log_name, (S8*)g_voip_cntx_p->call_originapp_info.dispName, MMI_PHB_NAME_LENGTH);
    if (mmi_ucs2strlen((S8*)dialRsp->remote_info.log_name))
    {
        mmi_ucs2ncpy((S8*)dialRsp->remote_info.disp_name, (S8*)g_voip_cntx_p->call_originapp_info.dispName, SRV_UCM_MAX_DISP_NAME_LEN);
    }
    else
    {
        mmi_ucs2ncpy((S8*)dialRsp->remote_info.disp_name, (S8*)g_voip_cntx_p->call_misc_info.dispUri, SRV_UCM_MAX_DISP_NAME_LEN);
        if(get_disp_name)
        {
            mmi_ucs2ncpy((S8*)dialRsp->remote_info.log_name, (S8*)g_voip_cntx_p->call_misc_info.dispUri, MMI_PHB_NAME_LENGTH);
        }
    }
    memcpy(dialRsp->remote_info.num_uri, g_voip_cntx_p->call_misc_info.inputUri, SRV_UCM_MAX_NUM_URI_LEN);

    memset(callList, 0, sizeof(srv_ucm_int_call_list_struct));
    dialRsp->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    callList->call_type = SRV_UCM_VOIP_CALL_TYPE;
    /*
    if (dialRsp->result_info.result == SRV_UCM_RESULT_OK)
    {
        callList->call_info[callList->total_num].uid_info.call_type = MMI_UCM_VOIP_CALL_TYPE;
        callList->call_info[callList->total_num].uid_info.group_id = SRV_UCM_INVALID_ID;
        callList->call_info[callList->total_num].uid_info.call_id = SRV_UCM_INVALID_ID;
        mmi_ucs2ncpy((S8*)callList->call_info[callList->total_num].remote_info.log_name, (S8*)dialRsp->remote_info.log_name, MMI_PHB_NAME_LENGTH);
        mmi_ucs2ncpy((S8*)callList->call_info[callList->total_num].remote_info.disp_name, (S8*)dialRsp->remote_info.disp_name, SRV_UCM_MAX_DISP_NAME_LEN);
        memcpy(callList->call_info[callList->total_num].remote_info.num_uri, dialRsp->remote_info.num_uri, SRV_UCM_MAX_NUM_URI_LEN);
        callList->call_info[callList->total_num].call_state = SRV_UCM_OUTGOING_STATE;

        MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_UPDATE_CALL_LIST,
            callList->total_num,
            callList->call_info[callList->total_num].uid_info.group_id,
            callList->call_info[callList->total_num].uid_info.call_id,
            callList->call_info[callList->total_num].call_state);

        callList->total_num++;
    }
	*/    
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_ALERT_TYPE ,(void*)&alert_type);
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_STATUS_LED ,(void*)&light_id);

    dialRsp->display_info.alert_type = (U8)alert_type;
    dialRsp->display_info.light_id = (U16)light_id;
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_DIAL_ACT_RSP_CBK, dialRsp->result_info.result);

    g_voip_ucm_act_rsp(SRV_UCM_VOIP_CALL_TYPE, (srv_ucm_int_act_opcode_enum)opCode, dialRsp, g_voip_ucm_user_data);

    srv_ucm_int_mfree((void*)callList);
    OslMfree(dialRsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_act_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  opCode          [IN]            Operation code
 *  result          [IN]            Result, TRUE or FALSE
 *  dispMsg         [IN]            Error message if result is FALSE
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_act_rsp(U8 opCode, U8 result, U8 *dispMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_act_rsp_struct *actRsp = NULL;
    srv_ucm_int_call_list_struct *callList = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_ACT_RSP, opCode, mmi_voip_ucm_act_opcode);

    if (opCode != mmi_voip_ucm_act_opcode || opCode == SRV_UCM_INT_FORCE_RELEASE_ACT)
    {
        return;
    }

    actRsp = OslMalloc(sizeof(srv_ucm_int_act_rsp_struct));
    callList = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    memset(actRsp, 0, sizeof(srv_ucm_int_act_rsp_struct));

    if (result == TRUE)
    {
        actRsp->result_info.result = SRV_UCM_RESULT_OK;
    }
    else
    {
        actRsp->result_info.result = SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
    if (dispMsg != NULL)
    {
        mmi_ucs2ncpy((S8*) &actRsp->result_info.error_msg, (S8*) dispMsg, SRV_UCM_MAX_ERR_MSG_LEN);
    }
    actRsp->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    /* reset act_opcode before sending act_rsp back to UCM */
    mmi_voip_ucm_act_opcode = SRV_UCM_INT_NO_ACT;

    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_ACT_RSP_CBK, opCode, actRsp->result_info.result);
    g_voip_ucm_act_rsp(SRV_UCM_VOIP_CALL_TYPE, (srv_ucm_int_act_opcode_enum)opCode, actRsp, g_voip_ucm_user_data);
    srv_ucm_int_mfree((void*)callList);
    OslMfree(actRsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_sync_call_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_sync_call_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_sync_call_list_ind_struct *callList = srv_ucm_int_malloc(sizeof(srv_ucm_int_sync_call_list_ind_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_SYNC_CALL_LIST);

    callList->call_list = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));

    mmi_voip_ucm_get_call_list(callList->call_list);
    srv_ucm_int_indication(
        SRV_UCM_VOIP_CALL_TYPE,
        SRV_UCM_INT_SYNC_CALL_LIST_IND,
        (void*)callList);
    srv_ucm_int_mfree((void*)callList->call_list);
    srv_ucm_int_mfree((void*)callList);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_alert_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_alert_ind(S32 groupId, S32 callId, MMI_BOOL localGen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_alert_ind_struct *alertInd = OslMalloc(sizeof(srv_ucm_int_alert_ind_struct));
    srv_ucm_int_call_list_struct *callList = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_ALERT_IND, groupId, callId, localGen);

    memset(alertInd, 0, sizeof(srv_ucm_int_alert_ind_struct));

    alertInd->uid_info.call_type = SRV_UCM_VOIP_CALL_TYPE;
    alertInd->uid_info.group_id = groupId;
    alertInd->uid_info.call_id = callId;
    alertInd->local_gen = localGen;
    alertInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    
    srv_ucm_int_indication(
        SRV_UCM_VOIP_CALL_TYPE,
        SRV_UCM_INT_ALERT_IND,
        (void*)alertInd);
    srv_ucm_int_mfree((void*)callList);
    OslMfree(alertInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_connect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  groupId         [IN]            VoIP call id
 *  callId          [IN]            VoIP dialog id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_connect_ind(S32 groupId, S32 callId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_connect_ind_struct *connectInd = OslMalloc(sizeof(srv_ucm_int_connect_ind_struct));
    srv_ucm_int_call_list_struct *callList = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_CONNECT_IND, groupId, callId);

    memset(connectInd, 0, sizeof(srv_ucm_int_connect_ind_struct));
    connectInd->uid_info.call_type = SRV_UCM_VOIP_CALL_TYPE;
    connectInd->uid_info.group_id = groupId;
    connectInd->uid_info.call_id = callId;
    mmi_voip_ucm_get_log_name(connectInd->uid_info.group_id, connectInd->uid_info.call_id, connectInd->remote_info.log_name);
    mmi_voip_ucm_get_disp_name(connectInd->uid_info.group_id, connectInd->uid_info.call_id, connectInd->remote_info.disp_name);
    mmi_voip_ucm_get_num_uri(connectInd->uid_info.group_id, connectInd->uid_info.call_id, connectInd->remote_info.num_uri);
    connectInd->uid_info.call_id = mmi_voip_get_dialog_idx(groupId, callId);
    connectInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    srv_ucm_int_indication(
        SRV_UCM_VOIP_CALL_TYPE,
        SRV_UCM_INT_CONNECT_IND,
        (void*)connectInd);
    srv_ucm_int_mfree((void*)callList);
    OslMfree(connectInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_notify_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_notify_ind(U8* dispMsg, U16 imageId, U16 toneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_notify_ind_struct *notifyInd = OslMalloc(sizeof(srv_ucm_int_notify_ind_struct));
    srv_ucm_int_call_list_struct *callList = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_NOTIFY_IND);

    memset(notifyInd, 0, sizeof(srv_ucm_int_notify_ind_struct));
    notifyInd->call_type = SRV_UCM_VOIP_CALL_TYPE;
    if (dispMsg != NULL)
    {
        mmi_ucs2ncpy((S8*) &notifyInd->disp_msg, (S8*) dispMsg, SRV_UCM_MAX_DISP_MSG_LEN);
    }
    notifyInd->image_id = imageId;
    notifyInd->tone_id = toneId;
    notifyInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    srv_ucm_int_indication(
        SRV_UCM_VOIP_CALL_TYPE,
        SRV_UCM_INT_NOTIFY_IND,
        (void*)notifyInd);
    srv_ucm_int_mfree((void*)callList);
    OslMfree(notifyInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_session_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_session_ind(U8 sessionType, MMI_BOOL sessionSwitch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_session_ind_struct *sessionInd = OslMalloc(sizeof(srv_ucm_int_session_ind_struct));
    srv_ucm_int_call_list_struct *callList = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_SESSION_IND, sessionType, sessionSwitch);

    memset(sessionInd, 0, sizeof(srv_ucm_int_session_ind_struct));
    sessionInd->session_type = sessionType;
    sessionInd->session_switch = sessionSwitch;
    sessionInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    srv_ucm_int_indication(
        SRV_UCM_VOIP_CALL_TYPE,
        SRV_UCM_INT_SESSION_IND,
        (void*)sessionInd);
    srv_ucm_int_mfree((void*)callList);
    OslMfree(sessionInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_speech_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_speech_ind(U8 rtpHandle, MMI_BOOL localSwitch, MMI_BOOL remoteSwitch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_speech_ind_struct *speechInd = OslMalloc(sizeof(srv_ucm_int_speech_ind_struct));
    srv_ucm_int_call_list_struct *callList = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_SPEECH_IND, rtpHandle, localSwitch, remoteSwitch);

    memset(speechInd, 0, sizeof(srv_ucm_int_speech_ind_struct));
    speechInd->call_type = SRV_UCM_VOIP_CALL_TYPE;
    speechInd->session_type = 0;
    speechInd->rtp_handle = rtpHandle;
    speechInd->local_switch = localSwitch;
    speechInd->remote_switch = remoteSwitch;
    speechInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);
    srv_ucm_int_indication(
        SRV_UCM_VOIP_CALL_TYPE,
        SRV_UCM_INT_SPEECH_IND,
        (void*)speechInd);
    srv_ucm_int_mfree((void*)callList);
    OslMfree(speechInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_ring_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_ring_ind(S32 groupId, S32 callId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_ring_ind_struct *ringInd = OslMalloc(sizeof(srv_ucm_int_ring_ind_struct));
    srv_ucm_int_call_list_struct *callList = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_RING_IND, groupId, callId);

    memset(ringInd, 0, sizeof(srv_ucm_int_ring_ind_struct));

    ringInd->uid_info.call_type = SRV_UCM_VOIP_CALL_TYPE;
    ringInd->uid_info.group_id = groupId;
    ringInd->uid_info.call_id = callId;
    mmi_voip_ucm_get_log_name(ringInd->uid_info.group_id, ringInd->uid_info.call_id, ringInd->remote_info.log_name);
    mmi_voip_ucm_get_disp_name(ringInd->uid_info.group_id, ringInd->uid_info.call_id, ringInd->remote_info.disp_name);
    mmi_voip_ucm_get_num_uri(ringInd->uid_info.group_id, ringInd->uid_info.call_id, ringInd->remote_info.num_uri);
    ringInd->uid_info.call_id = mmi_voip_get_dialog_idx(groupId, callId);
    //ringInd->display_info.tone_id = GetRingToneID();
    //caller_res srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MT_CALL_TONE,(void*)&ringInd->display_info.tone_id);
    //caller_res ringInd->display_info.image_info.image_id = IMG_PHB_DEFAULT;
    //ringInd->display_info.alert_type = GetMtCallAlertTypeEnum();
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_ALERT_TYPE ,(void*)&ringInd->display_info.alert_type);
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_STATUS_LED ,(void*)&ringInd->display_info.light_id);
    ringInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);

    srv_ucm_int_indication(
        SRV_UCM_VOIP_CALL_TYPE,
        SRV_UCM_INT_RING_IND,
        (void*)ringInd);
    srv_ucm_int_mfree((void*)callList);
    OslMfree(ringInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_release_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_release_ind(S32 groupId, S32 callId, U8 *dispMsg, U16 imageId, U16 toneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_release_ind_struct *releaseInd = OslMalloc(sizeof(srv_ucm_int_release_ind_struct));
    srv_ucm_int_call_list_struct *callList = srv_ucm_int_malloc(sizeof(srv_ucm_int_call_list_struct));
    U16 group_id, call_id;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_RELEASE_IND, groupId, callId);

    memset(releaseInd, 0, sizeof(srv_ucm_int_release_ind_struct));
    releaseInd->uid_info.call_type = SRV_UCM_VOIP_CALL_TYPE;
    releaseInd->uid_info.group_id = groupId;
    releaseInd->uid_info.call_id = callId;

    for (i = 0; i < g_voip_force_rel_fail_count; i++)
    {
        group_id = g_voip_force_rel_call[i].group_id;
        call_id = g_voip_force_rel_call[i].call_id;

        if (callId == call_id)
        {
            MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_RELEASE_IND_REPLACE_CALL,
                releaseInd->uid_info.group_id, group_id, call_id);
            releaseInd->uid_info.group_id = group_id;
            break;
        }
    }

    if (dispMsg != NULL)
    {
        mmi_ucs2ncpy((S8*) &releaseInd->disp_msg, (S8*) dispMsg, SRV_UCM_MAX_ERR_MSG_LEN);
    }
    releaseInd->image_id = imageId;
    releaseInd->tone_id = toneId;
    releaseInd->call_list = callList;
    mmi_voip_ucm_get_call_list(callList);

    srv_ucm_int_indication(
        SRV_UCM_VOIP_CALL_TYPE,
        SRV_UCM_INT_RELEASE_IND,
        (void*)releaseInd);
    srv_ucm_int_mfree((void*)callList);
    OslMfree(releaseInd);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_replace_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_replace_ind(S32 groupId, S32 callId, S32 old_groupIdx, S32 new_groupIdx, S32 old_callIdx, S32 new_callIdx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_replace_ind_struct *replaceInd = OslMalloc(sizeof(srv_ucm_int_replace_ind_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_REPLACE_IND, groupId, callId, old_groupIdx, new_groupIdx, old_callIdx, new_callIdx);

    memset(replaceInd, 0, sizeof(srv_ucm_int_replace_ind_struct));

    replaceInd->old_uid_info.call_type = SRV_UCM_VOIP_CALL_TYPE;
    replaceInd->old_uid_info.group_id = old_groupIdx;
    replaceInd->old_uid_info.call_id = old_callIdx;
    replaceInd->new_uid_info.call_type = SRV_UCM_VOIP_CALL_TYPE;
    replaceInd->new_uid_info.group_id = new_groupIdx;
    replaceInd->new_uid_info.call_id = new_callIdx;
    replaceInd->call_origin = SRV_UCM_INT_MO_ORIGIN;
    if(mmi_ucs2strlen((S8*)g_voip_cntx_p->call_list_info.call_info[groupId].dialog_info[callId].dispName))
    {
        mmi_ucs2ncpy((S8*)replaceInd->remote_info.disp_name,
                                (S8*)g_voip_cntx_p->call_list_info.call_info[groupId].dialog_info[callId].dispName,
                                SRV_UCM_MAX_DISP_NAME_LEN);

    }
    else
    {
        mmi_asc_n_to_ucs2((S8*)replaceInd->remote_info.disp_name,
                                            (S8*) g_voip_cntx_p->call_list_info.call_info[groupId].dialog_info[callId].remoteUri,
                                            SRV_UCM_MAX_DISP_NAME_LEN);
    }
    memcpy(replaceInd->remote_info.num_uri,
                g_voip_cntx_p->call_list_info.call_info[groupId].dialog_info[callId].remoteUri,
                SRV_UCM_MAX_NUM_URI_LEN);
    replaceInd->log_call_now = MMI_TRUE;

    srv_ucm_int_indication(
        SRV_UCM_VOIP_CALL_TYPE,
        SRV_UCM_INT_REPLACE_IND,
        (void*)replaceInd);
    OslMfree(replaceInd);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_get_redial_str
 * DESCRIPTION
 *  To compose the string in redialing screen
 * PARAMETERS
 *  str_buf    IN/OUT    the reidaling string
 * RETURNS
 *  U8         the redialing timer
 *****************************************************************************/
U8 mmi_voip_ucm_get_redial_str(U8 *str_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL minFlag = FALSE;
    U8 timer, dispTimer;
    S8 temp[10], temp2[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_voip_cntx_p->call_redial_info.currAttempt)
    {
        case 1:
            timer = 7;
            dispTimer = 5;
            break;

        case 2:
        case 3:
        case 4:
            timer = 65;
            dispTimer = 1;
            minFlag = TRUE;
            break;
        default:
            timer = 190;
            dispTimer = 3;
            minFlag = TRUE;
            break;
    }

    memset(str_buf, 0, sizeof(str_buf));
    mmi_ucs2cpy((PS8) str_buf, GetString(STR_CM_REDIAL));

    sprintf((PS8) temp, "\n%d \0", g_voip_cntx_p->call_redial_info.currAttempt);
    mmi_asc_to_ucs2((PS8) temp2, (PS8) temp);
    mmi_ucs2cat((PS8) str_buf, (PS8) temp2);

    mmi_ucs2cat((PS8) str_buf, GetString(STR_CM_REDIAL_TIMES));
    mmi_ucs2cat((PS8) str_buf, GetString(STR_CM_REDIAL_NEXT_ATTEMPT));

    sprintf((PS8) temp, "\n%d \0", dispTimer);
    mmi_asc_to_ucs2((PS8) temp2, (PS8) temp);
    mmi_ucs2cat((PS8) str_buf, (PS8) temp2);

    if (minFlag == FALSE)
    {
        mmi_ucs2cat((PS8) str_buf, GetString(STR_CM_REDIAL_SEC));
    }
    else
    {
        mmi_ucs2cat((PS8) str_buf, GetString(STR_CM_REDIAL_MIN));
    }

    return timer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_auto_redial_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_auto_redial_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_auto_redial_ind_struct *redialInd = OslMalloc(sizeof(srv_ucm_int_auto_redial_ind_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_AUTO_REDIAL_IND);

    memset(redialInd, 0, sizeof(srv_ucm_int_auto_redial_ind_struct));
    redialInd->call_type = SRV_UCM_VOIP_CALL_TYPE;
    memcpy(redialInd->num_uri, g_voip_cntx_p->call_redial_info.redialUri, SRV_UCM_MAX_NUM_URI_LEN);
    redialInd->attempt = (U8)g_voip_cntx_p->call_redial_info.currAttempt;
    redialInd->time = mmi_voip_ucm_get_redial_str((U8*)redialInd->display_msg);
    redialInd->abort_hdlr = mmi_voip_entry_abort_redial;
    //Leo
    //redialInd->user_data = g_voip_ucm_user_data;

    srv_ucm_int_indication(
        SRV_UCM_VOIP_CALL_TYPE,
        SRV_UCM_INT_AUTO_REDIAL_IND,
        (void*)redialInd);

    OslMfree(redialInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_start_processing_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_start_processing_ind(S32 groupId, S32 callId, U8 *dispMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_start_processing_ind_struct *startInd = OslMalloc(sizeof(srv_ucm_int_start_processing_ind_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_START_PROCESSING_IND, groupId, callId);

    memset(startInd, 0, sizeof(srv_ucm_int_start_processing_ind_struct));
    startInd->uid_info.call_type = SRV_UCM_VOIP_CALL_TYPE;
    startInd->uid_info.group_id = groupId;
    startInd->uid_info.call_id = mmi_voip_get_dialog_idx(groupId, callId);
    if (dispMsg != NULL)
    {
        mmi_ucs2ncpy((S8*) &startInd->content, (S8*) dispMsg, SRV_UCM_MAX_DISP_MSG_LEN);
    }

    srv_ucm_int_indication(
        SRV_UCM_VOIP_CALL_TYPE,
        SRV_UCM_INT_START_PROCESSING_IND,
        (void*)startInd);

    OslMfree(startInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_stop_processing_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_stop_processing_ind(U8* dispMsg, U16 imageId, U16 toneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_stop_processing_ind_struct *stopInd = OslMalloc(sizeof(srv_ucm_int_stop_processing_ind_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_STOP_PROCESSING_IND);

    memset(stopInd, 0, sizeof(srv_ucm_int_stop_processing_ind_struct));
    if (dispMsg != NULL)
    {
        mmi_ucs2ncpy((S8*) &stopInd->disp_msg, (S8*) dispMsg, SRV_UCM_MAX_DISP_MSG_LEN);
    }
    stopInd->image_id = imageId;
    stopInd->tone_id = toneId;

    srv_ucm_int_indication(
        SRV_UCM_VOIP_CALL_TYPE,
        SRV_UCM_INT_STOP_PROCESSING_IND,
        (void*)stopInd);

    OslMfree(stopInd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_control_rtp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_control_rtp(U8 rtpHandle, U8 localSwitch, U8 remoteSwitch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rtpDirection = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_CONTROL_RTP, rtpHandle, localSwitch, remoteSwitch);

    mmi_voip_ucm_get_rtp_direction(localSwitch, remoteSwitch, &rtpDirection);
    mmi_voip_control_rtp(rtpHandle, rtpDirection);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_suspend_rtp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_ucm_suspend_rtp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UCM_SUSPEND_RTP);

    mmi_voip_ucm_speech_ind(0, MMI_FALSE, MMI_FALSE);
    for (i = 0; i < g_voip_cntx_p->call_list_info.numTotal; i++)
    {
        for (j = 0; j < g_voip_cntx_p->call_list_info.call_info[i].numDialog; j++)
        {
            mmi_voip_switch_rtp(TRUE, g_voip_cntx_p->call_list_info.call_info[i].callId, g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].dialogId);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_auto_redial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_voip_is_auto_redial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE; //AutoRedialOnOffStatus();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_IS_AUTO_REDIAL, result);
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_srv_available
 * DESCRIPTION
 *  check if voip srv is available now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_voip_is_srv_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    MMI_BOOL is_sim_ready = MMI_FALSE;
    MMI_BOOL is_allowed = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    
    #ifdef __MMI_DUAL_SIM_MASTER__
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
    #else
        if(mmi_bootup_is_sim_valid() == MMI_TRUE)
        {
            is_sim_ready = MMI_TRUE;
        }
    #endif

    #ifdef __MMI_WLAN_FEATURES__
        switch (mmi_netset_get_active_preferred_mode())
        {
            case P_GSM_ONLY:
                if(is_sim_ready)
                {
                    is_allowed = MMI_TRUE;
                }
                else
                {
                    is_allowed = MMI_FALSE;
                }
                break;
            case P_WLAN_ONLY:
            case P_GSM_PREFERRED:
            case P_WLAN_PREFERRED:
                is_allowed = MMI_TRUE;
                break;
        }
    #else
        is_allowed = is_sim_ready;
    #endif

    return is_allowed;
}

#endif /* __MMI_VOIP__ */

