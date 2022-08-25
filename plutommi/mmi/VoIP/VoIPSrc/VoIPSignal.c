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
 *  VoIPSignal.c
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

#include "DateTimeGprot.h"
#include "PhoneBookGprot.h"
#include "VolumeHandler.h"
#include "UCMGProt.h"
#include "..\..\..\Service\UcmSrv\UcmSrvIntProt.h"

#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "VoIPProt.h"


#ifdef SIP_CONFORMANCE_TEST
/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_option_query_check
 * DESCRIPTION
 *  Determine target's URI and get ready to process option query action.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_option_query_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *unicodeUri = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) g_voip_cntx_p->call_misc_info.dispUri))
    {
        memset(unicodeUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
        mmi_ucs2ncpy((S8*)unicodeUri, (S8*)g_voip_cntx_p->call_misc_info.dispUri, VOIP_URI_LEN);
        mmi_voip_parse_uri(unicodeUri);
        memset(g_voip_cntx_p->call_misc_info.inputUri, 0, VOIP_URI_LEN);
        mmi_ucs2_n_to_asc(
            (S8*)g_voip_cntx_p->call_misc_info.inputUri,
            (S8*)unicodeUri,
            (VOIP_URI_LEN * ENCODING_LENGTH));
        if (mmi_voip_validate_uri(unicodeUri) == TRUE)
        {
            mmi_voip_set_processing_parameter(
                STR_GLOBAL_SEARCHING,
                STR_ID_VOIP_PROCESSING,
                IMG_GLOBAL_PROGRESS,
                0,
                0,
                0,
                0,
                0,
                0);
            mmi_voip_entry_processing_screen();
            mmi_voip_option_query_req();
        }
        else
        {
            mmi_display_popup(
                get_string(STR_ID_VOIP_INVALID_USERNAME),
                MMI_EVENT_FAILURE);
        }
    }
    else    /* not allow to query an empty number */
    {
        mmi_display_popup(
            get_string(STR_ID_VOIP_EMPTY_USERNAME),
            MMI_EVENT_FAILURE);
    }
    OslMfree(unicodeUri);
}
#endif /* SIP_CONFORMANCE_TEST */


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_pre_dial
 * DESCRIPTION
 *  Determine to dial or not based on current state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_pre_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 opCode = SRV_UCM_INT_DIAL_ACT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_PRE_DIAL);

    /* check register state */
    if (g_voip_cntx_p->reg_state_info == MMI_VOIP_REG_STATE)
    {
        /* check call boundary */
        if ((mmi_voip_is_codec_compatible(g_voip_cntx_p->call_setting_info.codecEnum, FALSE)) &&
            (g_voip_cntx_p->call_list_info.numTotal < MMI_VOIP_MAX_NUM_CALL))
        {
            mmi_voip_entry_dial();
        }
        else /* current codec does not support or call boundary exceeds */
        {
            g_voip_cntx_p->call_misc_info.isSOS = FALSE;
            mmi_voip_ucm_dial_act_rsp(opCode, SRV_UCM_INVALID_ID, SRV_UCM_INVALID_ID, FALSE, (U8*)GetString(STR_ID_VOIP_NOT_ALLOW_TO_DIAL));
            memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
        }
    }
    else if (g_voip_cntx_p->reg_state_info == MMI_VOIP_DEREG_STATE)
    {
        /* in case user intends to dial sos originally but change his mind after login */
        g_voip_cntx_p->call_misc_info.isSOS = FALSE;
        if (mmi_voip_is_auto_redial() == MMI_TRUE)
        {
            /* in case receiving deregister_ind in redialing process */
            //MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_ABORT_REDIAL, GetTotalCallCount(), g_voip_cntx_p->reg_state_info);
            mmi_voip_entry_abort_redial();
        }
        mmi_voip_ucm_dial_act_rsp(opCode, SRV_UCM_INVALID_ID, SRV_UCM_INVALID_ID, FALSE, NULL);        
        memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
        mmi_voip_entry_login_confirm(); // TODO: send display confirm to UCM
    }
    else /* g_voip_cntx_p->reg_state_info == MMI_VOIP_PROCESS_STATE */
    {
        /* in case user intends to dial sos originally but change his mind after login */
        g_voip_cntx_p->call_misc_info.isSOS = FALSE;
        if (mmi_voip_is_auto_redial() == MMI_TRUE)
        {
            /* in case receiving deregister_ind in redialing process */
            //MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_ABORT_REDIAL, GetTotalCallCount(), g_voip_cntx_p->reg_state_info);
            mmi_voip_entry_abort_redial();
        }
        mmi_voip_ucm_dial_act_rsp(opCode, SRV_UCM_INVALID_ID, SRV_UCM_INVALID_ID, FALSE, (U8*)GetString(STR_ID_VOIP_NOT_ALLOW_TO_DIAL));    
        memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_dial
 * DESCRIPTION
 *  Entry function of VoIP\New Call\Option\Dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *unicodeUri = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    U8 *unicodeOwner = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    S32 profIndex = g_voip_cntx_p->prof_setting_info.actprofIndex;
    S32 activecallId = 0;
    U8 opCode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_ENTRY_DIAL);

    if (mmi_voip_is_sos_number(g_voip_cntx_p->call_misc_info.dispUri) == TRUE)
    {
        mmi_voip_entry_dial_sos();
        DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR);
        DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION);
        OslMfree(unicodeUri);
        OslMfree(unicodeOwner);
        return;
    }
    activecallId = mmi_voip_get_active_call_id();
    opCode = SRV_UCM_INT_DIAL_ACT;
    if (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_misc_info.dispUri))
    {
        MMI_ASSERT(g_voip_cntx_p->call_misc_info.dispUri[VOIP_URI_LEN * ENCODING_LENGTH - 2] == '\0' && g_voip_cntx_p->call_misc_info.dispUri[VOIP_URI_LEN * ENCODING_LENGTH - 1] == '\0');
        memset(unicodeUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
        mmi_ucs2ncpy((S8*)unicodeUri, (S8*)g_voip_cntx_p->call_misc_info.dispUri, VOIP_URI_LEN);
        mmi_voip_parse_uri(unicodeUri);
        memset(unicodeOwner, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
        mmi_asc_n_to_ucs2(
            (S8*)unicodeOwner, 
            (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.username, 
            VOIP_URI_LEN);
        if (mmi_voip_is_owner_number(unicodeUri, unicodeOwner) == TRUE)
        {
            mmi_voip_ucm_dial_act_rsp(opCode, SRV_UCM_INVALID_ID, SRV_UCM_INVALID_ID, FALSE, (U8*)GetString(STR_ID_VOIP_CANNOT_DIAL_OWNER));
            memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
        }
        else /* normal call */
        {
            if (mmi_voip_validate_uri(unicodeUri) == TRUE)
            {
                memset(g_voip_cntx_p->call_misc_info.inputUri, 0, VOIP_URI_LEN);
                mmi_ucs2_n_to_asc(
                    (S8*)g_voip_cntx_p->call_misc_info.inputUri,
                    (S8*)unicodeUri,
                    (VOIP_URI_LEN * ENCODING_LENGTH));
                if (mmi_voip_is_auto_redial() == MMI_TRUE)
                {
                    MMI_ASSERT(g_voip_cntx_p->call_misc_info.inputUri[VOIP_URI_LEN - 1] == '\0');
                    memcpy(g_voip_cntx_p->call_redial_info.redialUri, g_voip_cntx_p->call_misc_info.inputUri, VOIP_URI_LEN);
                }
                /* set all rtp directions as inactive before action */
                mmi_voip_switch_rtp(TRUE, -1, -1);
                //mmi_voip_ucm_dial_act_rsp(opCode, SRV_UCM_INVALID_ID, SRV_UCM_INVALID_ID, TRUE, NULL);
                DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR);
                DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION);
                activecallId = mmi_voip_get_active_call_id();
                if (activecallId != -1)
                {
                    mmi_voip_hold_and_dial_req(activecallId);
                }
                else
                {
                    mmi_voip_dial_req();
                }
            }
            else
            {
                mmi_voip_ucm_dial_act_rsp(opCode, SRV_UCM_INVALID_ID, SRV_UCM_INVALID_ID, FALSE, (U8*)GetString(STR_ID_VOIP_INVALID_USERNAME));
                DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION);
                memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
            }
        }
    }
    else /* not allow to dial an empty number */
    {
        mmi_voip_ucm_dial_act_rsp(opCode, SRV_UCM_INVALID_ID, SRV_UCM_INVALID_ID, FALSE, (U8*)GetString(STR_ID_VOIP_EMPTY_USERNAME));
        DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION);
        memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
    }
    OslMfree(unicodeUri);
    OslMfree(unicodeOwner);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_dial_sos
 * DESCRIPTION
 *  Dial emergency number.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_dial_sos(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_ENTRY_DIAL_SOS);

    memset(g_voip_cntx_p->call_misc_info.inputUri, 0, VOIP_URI_LEN);
    mmi_ucs2_n_to_asc(
        (S8*)g_voip_cntx_p->call_misc_info.inputUri,
        (S8*)g_voip_cntx_p->call_misc_info.dispUri,
        (VOIP_URI_LEN * ENCODING_LENGTH));
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    mmi_voip_dial_sos_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_abort_call
 * DESCRIPTION
 *  Abort outgoing call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_abort_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_ENTRY_ABORT_CALL);

    if (mmi_voip_is_auto_redial() == MMI_TRUE)
    {
        mmi_voip_entry_abort_redial();
    }
    /* set all rtp directions as inactive before action */
    mmi_voip_switch_rtp(TRUE, -1, -1);
    callId = mmi_voip_get_outgoing_call_id();
    g_voip_cntx_p->call_misc_info.isAbort = TRUE;
    if (callId != -1)
    {
        mmi_voip_release_req(callId, 0);
        mmi_voip_force_release_req(callId, 0);
    }
    else
    {
        /* progressing_ind is not received yet */
        mmi_voip_release_req(g_voip_cntx_p->call_list_info.maxnumCall, 0);
        mmi_voip_force_release_req(g_voip_cntx_p->call_list_info.maxnumCall, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_abort_redial
 * DESCRIPTION
 *  Abort redialing call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_abort_redial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_ENTRY_ABORT_REDIAL);

    memset(&g_voip_cntx_p->call_redial_info, 0, sizeof(mmi_voip_call_redial_struct));
    g_voip_cntx_p->call_redial_info.maxAttempt = 3;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_outgoing_call_id
 * DESCRIPTION
 *  Check if outgoing call exists and get its call id.
 * PARAMETERS
 *  void
 * RETURNS
 *  call id if outgoing call exists; -1 if outgoing call does not exist.
 *****************************************************************************/
S32 mmi_voip_get_outgoing_call_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, call_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = (MMI_VOIP_MAX_NUM_CALL - 1); i >= 0; i--)
    {
        if (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_OUTGOING_STATE)
        {
            call_id = g_voip_cntx_p->call_list_info.call_info[i].callId;
            break;
        }
    }
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_GET_OUTGOING_CALL_ID, call_id);

    return call_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_incoming_call_id
 * DESCRIPTION
 *  Check if incoming call exists and get its call id.
 * PARAMETERS
 *  void
 * RETURNS
 *  call id if incoming call exists; -1 if incoming call does not exist.
 *****************************************************************************/
S32 mmi_voip_get_incoming_call_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, call_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = (MMI_VOIP_MAX_NUM_CALL - 1); i >= 0; i--)
    {
        if (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_INCOMING_STATE)
        {
            call_id = g_voip_cntx_p->call_list_info.call_info[i].callId;
            break;
        }
    }
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_GET_INCOMING_CALL_ID, call_id);

    return call_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_active_call_id
 * DESCRIPTION
 *  Check if active call exists and get its call id.
 * PARAMETERS
 *  void
 * RETURNS
 *  call id if active call exists; -1 if active call does not exist.
 *****************************************************************************/
S32 mmi_voip_get_active_call_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, numActive = 0, call_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numActive = g_voip_cntx_p->call_list_info.numTotal - g_voip_cntx_p->call_list_info.numHeld;

    if (numActive > 0)
    {
        for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i++)
        {
            if (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_ACTIVE_STATE)
            {
                call_id = g_voip_cntx_p->call_list_info.call_info[i].callId;
            }
        }
    }
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_GET_ACTIVE_CALL_ID, call_id);

    return call_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_held_call_list
 * DESCRIPTION
 *  Check if held call exists and get its call id.
 *  If more than one held calls exist, put them all in the held call list.
 * PARAMETERS
 *  singlecallOnly      [IN]        Single held call or don't care
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_get_held_call_list(MMI_BOOL singlecallOnly)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, callId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset held call list */
    memset(&g_voip_cntx_p->call_list_info.held_call_info, 0, sizeof(mmi_voip_held_call_struct));
    for (i = 0; i < MMI_VOIP_MAX_HELD_CALL; i++)
    {
        g_voip_cntx_p->call_list_info.held_call_info[i].callId = -1;
    }

    /* assign held call to held call list */
    if (g_voip_cntx_p->call_list_info.numHeld > 0)
    {
        for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i++)
        {
            if (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_HOLD_STATE)
            {
                callId = g_voip_cntx_p->call_list_info.call_info[i].callId;
                if (singlecallOnly)
                {
                    if (g_voip_cntx_p->call_list_info.call_info[i].numDialog == 1)
                    {
                        g_voip_cntx_p->call_list_info.held_call_info[j].callId = callId;
                        memcpy(
                            g_voip_cntx_p->call_list_info.held_call_info[j].dispName,
                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[0].dispName,
                            (VOIP_DISP_NAME_LEN * sizeof(U16)));
                        memcpy(
                            g_voip_cntx_p->call_list_info.held_call_info[j].remoteUri,
                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[0].remoteUri,
                            VOIP_URI_LEN);
                        memcpy(
                            g_voip_cntx_p->call_list_info.held_call_info[j].codecList,
                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[0].sdp_info.codec,
                            VOIP_MAX_NUM_CODEC);
                        j++;
                    }
                }
                else
                {
                    g_voip_cntx_p->call_list_info.held_call_info[j].callId = callId;
                    memcpy(
                        g_voip_cntx_p->call_list_info.held_call_info[j].dispName,
                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[0].dispName,
                        (VOIP_DISP_NAME_LEN * sizeof(U16)));
                    memcpy(
                        g_voip_cntx_p->call_list_info.held_call_info[j].remoteUri,
                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[0].remoteUri,
                        VOIP_URI_LEN);
                    memcpy(
                        g_voip_cntx_p->call_list_info.held_call_info[j].codecList,
                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[0].sdp_info.codec,
                        VOIP_MAX_NUM_CODEC);
                    j++;
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_call_index
 * DESCRIPTION
 *  Get call index based on the call id.
 * PARAMETERS
 *  callId      [IN]        Call id
 * RETURNS
 *  call index.
 *****************************************************************************/
S32 mmi_voip_get_call_index(S32 callId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i++)
    {
        if (g_voip_cntx_p->call_list_info.call_info[i].callId == callId)
        {
            return i;
        }
    }
    if (i == MMI_VOIP_MAX_NUM_CALL)
    {
        return -1;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_dialog_index
 * DESCRIPTION
 *  Get dialog index based on the dialog id.
 * PARAMETERS
 *  callIndex       [IN]        Call index
 *  dialogId        [IN]        Dialog id
 * RETURNS
 *  dialog index.
 *****************************************************************************/
S32 mmi_voip_get_dialog_index(S32 callIndex, S32 dialogId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VOIP_MAX_NUM_DIALOG; i++)
    {
        if (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].dialogId == dialogId)
        {
            return i;
        }
    }
    if (i == VOIP_MAX_NUM_DIALOG)
    {
        return -1;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_log_call_end_time
 * DESCRIPTION
 *  Put current time as end time and calculate call duration.
 * PARAMETERS
 *  callId          [IN]        Call id
 *  dialogId        [IN]        Dialog id
 *  duration        [IN]        Duration of the call
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_log_call_end_time(S32 callId, S32 dialogId, MYTIME *duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0;
    MYTIME currTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callIndex = mmi_voip_get_call_index(callId);
    if (callIndex != -1)
    {
        dialogIndex = mmi_voip_get_dialog_index(callIndex, dialogId);
        if (dialogIndex != -1)
        {
            DTGetRTCTime(&currTime);
            g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].endTime = currTime;
            /* overflow 2030/12/31/23:59:59 */
            if (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime.nYear == 2030 && 
                currTime.nYear < g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime.nYear)
            {
                currTime.nYear = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime.nYear;
                currTime.nMonth = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime.nMonth;
                currTime.nDay = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime.nDay + 1;
            }
            GetTimeDifference(
                &currTime,
                &g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].startTime,
                duration);
        }
    }
}

#endif /* __MMI_VOIP__ */

