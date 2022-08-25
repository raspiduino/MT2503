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
 *  UCMInterfaceBT.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM exported APIs source file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if !defined(__MMI_TELEPHONY_SUPPORT__) && !defined(__MMI_BT_CALL_SUPPORT__)
#include "GlobalResDef.h"
#include "UCMGProt.h"
#endif /* __MMI_TELEPHONY_SUPPORT__ */

#ifdef __MMI_BT_CALL_SUPPORT__
//#include "mmi_rp_core_ucm_def.h"
#ifdef __MMI_TELEPHONY_SUPPORT__
#include "mmi_rp_app_ucm_def.h"
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#include "mmi_rp_app_ucmbt_def.h"
#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "UcmProtBT.h"
#include "UcmGProtBT.h"
#include "UcmBTSrvGprot.h"
#include "Conversions.h"
#include "VolumeHandler.h" // for mmi_vol_set_speech_vol
#include "Gpiosrvgprot.h" // for srv_speech_get_mode_volume
#include "custom_ecc.h" /* ecc_custom_verify_emergency_number */

mmi_ucm_bt_cntx_struct g_mmi_ucm_cntx_bt;
mmi_ucm_bt_cntx_struct *g_ucm_p_bt = &g_mmi_ucm_cntx_bt;


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_context_bt
 * DESCRIPTION
 *  Initialize UCM app context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init_context_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_ucm_p_bt, 0, sizeof(mmi_ucm_bt_cntx_struct));
#ifdef __MMI_UCM_BT_CALL_RECORDER__
    memset(&g_ucm_bt_start_record_time, 0, sizeof(MYTIME));
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_bt_call_para
 * DESCRIPTION
 *  PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init_bt_call_para(mmi_ucm_bt_make_call_para_struct* bt_para, mmi_ucm_make_call_para_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(para && bt_para);
    memset(bt_para, 0, sizeof(mmi_ucm_bt_make_call_para_struct));
    bt_para->after_make_call_callback = para->adv_para.after_make_call_callback;
    bt_para->after_callback_user_data = para->adv_para.after_callback_user_data;
    if (para->adv_para.phb_data != NULL)
    {
        len = mmi_ucs2strlen((CHAR*)para->adv_para.phb_data);
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_LAUNCH_STEP_P1, 201, len);
        if (len > 0 && len < SRV_UCM_BT_MAX_DIS_NAME_FROM_APP)
        {
            memcpy(bt_para->phb_name, para->adv_para.phb_data, sizeof(bt_para->phb_name));
        }
    }
    memcpy(bt_para->num_uri, para->ucs2_num_uri, (SRV_UCM_BT_MAX_NUM_URI_LEN+1)*ENCODING_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_launch_bt
 * DESCRIPTION
 *  PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_call_launch_bt(mmi_ucm_bt_make_call_para_struct *make_call_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_atd_act_req_struct act_req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(make_call_para);
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SET_PARA, 
          make_call_para->after_make_call_callback, make_call_para->after_callback_user_data);

    memset(g_ucm_p_bt->num_uri, 0, SRV_UCM_BT_MAX_NUM_URI_LEN+1);
    mmi_ucs2_to_asc((CHAR*)g_ucm_p_bt->num_uri, (CHAR*)make_call_para->num_uri);

    g_ucm_p_bt->callback = make_call_para->after_make_call_callback;
    g_ucm_p_bt->callback_para = make_call_para->after_callback_user_data;

    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
    {
        act_req.srv_hd = srv_ucm_bt_query_service_hd(&make_call_para->dev_addr);
        memcpy(act_req.num_uri, make_call_para->num_uri, sizeof(act_req.num_uri));
        memcpy(act_req.dis_name, make_call_para->phb_name, sizeof(act_req.dis_name));
        mmi_ucm_dial_action_bt(&act_req);
    }
    else
    {
        mmi_popup_display_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, NULL);
        mmi_ucm_exec_dial_cb_bt(SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL);
        if (mmi_frm_group_is_present(GRP_ID_UCM_MO_SELECT))
        {
            mmi_frm_group_close(GRP_ID_UCM_MO_SELECT);
        }
    }
}

#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_auto_lock_state_bt
 * DESCRIPTION
 *  get auto lock state
 * PARAMETERS
 *  void
 * RETURNS
 *  Auto lock state
 *****************************************************************************/
mmi_ucm_bt_auto_lock_state_enum mmi_ucm_get_auto_lock_state_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ucm_p_bt->auto_lock_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_auto_lock_fsm_hdlr_bt
 * DESCRIPTION
 *  a FSM fpr auto lock mechanism. it will base on trigger event and original state and current existed calls situation
 *  to decide the next lock state
 * PARAMETERS
 *  event:     [IN] trigger event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_auto_lock_fsm_hdlr_bt(mmi_ucm_bt_auto_lock_trigger_event_enum event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_bt_auto_lock_state_enum orig_state = g_ucm_p_bt->auto_lock_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_FTE_FMS_HDLR, event, orig_state);

    switch(event)
    {
        case MMI_UCM_BT_AL_OUTGOING_EVENT:
        {
            switch (orig_state)
            {
                case  MMI_UCM_BT_UNLOCK_STATE:
                case  MMI_UCM_BT_WTL_STATE:     
                case  MMI_UCM_BT_LOCK_STATE:
                {
                    g_ucm_p_bt->auto_lock_state =  MMI_UCM_BT_LOCK_STATE;
                }
                break;
                
                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }
        }
        break;       
        
        case  MMI_UCM_BT_AL_INCOMING_EVENT:
        {
            switch (orig_state)
            {
                case  MMI_UCM_BT_UNLOCK_STATE:
                {
                    g_ucm_p_bt->auto_lock_state =  MMI_UCM_BT_UNLOCK_STATE; /* Todo: phone device lock status */
                }
                break;
                
                case  MMI_UCM_BT_WTL_STATE:
                {
                    g_ucm_p_bt->auto_lock_state =  MMI_UCM_BT_UNLOCK_STATE;
                }
                break;

                case  MMI_UCM_BT_LOCK_STATE:
                {
                    g_ucm_p_bt->auto_lock_state =  MMI_UCM_BT_LOCK_STATE;
                }
                break;
                
                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }
        }
        break; 

        case  MMI_UCM_BT_AL_CONNECT_EVENT:
        {
            switch (orig_state)
            {
                case  MMI_UCM_BT_UNLOCK_STATE:
                case  MMI_UCM_BT_WTL_STATE:
                case  MMI_UCM_BT_LOCK_STATE:
                {
                    g_ucm_p_bt->auto_lock_state =  MMI_UCM_BT_LOCK_STATE;
                }
                break;

                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }
        }
        break;     

        case  MMI_UCM_BT_AL_RELEASE_EVENT:
        {
            U32 call_count;
            call_count = srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, NULL);
            switch (orig_state)
            {
                case  MMI_UCM_BT_UNLOCK_STATE:
                {
                    if (0 == call_count)
                    {
                        g_ucm_p_bt->auto_lock_state =  MMI_UCM_BT_UNLOCK_STATE;
                    }
                    else
                    {
                        if (srv_ucm_bt_query_call_count(SRV_UCM_BT_INCOMING_STATE, NULL) == 0)
                        {
                            g_ucm_p_bt->auto_lock_state =  MMI_UCM_BT_WTL_STATE;
                        }
                    }
                }
                break;
                
                case  MMI_UCM_BT_WTL_STATE:
                {
                    if (0 == call_count)
                    {
                        g_ucm_p_bt->auto_lock_state =  MMI_UCM_BT_UNLOCK_STATE;
                    }
                }
                break;

                case  MMI_UCM_BT_LOCK_STATE:
                {
                    if (0 == call_count)
                    {
                        g_ucm_p_bt->auto_lock_state =  MMI_UCM_BT_UNLOCK_STATE;
                    }
                    else 
                    {
                        /* Keep orig state if any call exist */                      
                    }
                }
                break;
                
                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }
        }
        break; 

        /* User press unlock key on call screen to unlock */
        case  MMI_UCM_BT_AL_UNLOCK_EVENT: 
        {
            switch (orig_state)
            {
                case  MMI_UCM_BT_UNLOCK_STATE:
                case  MMI_UCM_BT_WTL_STATE:     
                {

                }
                break;
               
                case  MMI_UCM_BT_LOCK_STATE:
                {
                    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_INCOMING_STATE, NULL) > 0)
                    {
                        g_ucm_p_bt->auto_lock_state =  MMI_UCM_BT_UNLOCK_STATE;
                    }
                    else
                    {
                        g_ucm_p_bt->auto_lock_state =  MMI_UCM_BT_WTL_STATE;
                    }
                }
                break;

                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }
        }
        break; 

        case  MMI_UCM_BT_AL_WTL_TIMEOUT_EVENT:
        {
            switch (orig_state)
            {
                case  MMI_UCM_BT_UNLOCK_STATE:
                case  MMI_UCM_BT_LOCK_STATE:
                case  MMI_UCM_BT_WTL_STATE:
                {
                    g_ucm_p_bt->auto_lock_state =  MMI_UCM_BT_LOCK_STATE;
                }
                break;
                
                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }
        }
        break;
        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_FTE_FMS_RESULT, g_ucm_p_bt->auto_lock_state);
}

#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_BT_CALL_SUPPORT__ */

/* Dummy Function */
#ifndef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init
 * DESCRIPTION
 *  Initialize UCM app context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init(void)
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
 *  mmi_ucm_entry_error_message
 * DESCRIPTION
 *  Error message API for applications which operations are not allowed during in-call.
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
void mmi_ucm_entry_error_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_FAILURE, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_entry_error_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_app_entry_error_message(void)
{
    mmi_ucm_entry_error_message();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_key(void)
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
 *  mmi_ucm_get_marker_scrn_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_ucm_get_marker_scrn_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GRP_ID_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_handle_sendkeys_for_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  newCallFunc    [IN]
 *  keyevent    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_handle_sendkeys_for_call(FuncPtr newCallFunc, mmi_key_types_enum keyevent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(keyevent)
    {
        case KEY_EVENT_UP:
            SetKeyUpHandler(newCallFunc, KEY_SEND);
            break;
        case KEY_EVENT_DOWN:
            SetKeyDownHandler(newCallFunc, KEY_SEND);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_show_aoc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ucm_get_show_aoc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_app_make_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type    [IN]
 *  num_uri    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_app_make_call(mmi_ucm_call_type_enum call_type, U8 *num_uri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_call_para(&make_call_para);  
    make_call_para.dial_type = (srv_ucm_call_type_enum)call_type;
    make_call_para.ucs2_num_uri = (U16*)num_uri;
    mmi_ucm_call_launch(0, &make_call_para);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_error_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_result    [IN]
 *  popup_type    [IN]
 * RETURNS
 *  MMI_STR_ID
 *****************************************************************************/
MMI_STR_ID mmi_ucm_get_error_info(S32 error_result, mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *popup_type = MMI_EVENT_FAILURE;
    return STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_call_para_for_sendkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  make_call_para    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init_call_para_for_sendkey(mmi_ucm_make_call_para_struct *make_call_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(make_call_para, 0, sizeof(mmi_ucm_make_call_para_struct));
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_valid_num_bt
 * DESCRIPTION
 * 
 * PARAMETERS
 *
 * RETURNS
 * 
 *****************************************************************************/
static MMI_BOOL mmi_ucm_is_valid_num_bt(U16* ucs2_num)
{
#ifdef __MMI_BT_CALL_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 num_uri[SRV_UCM_BT_MAX_NUM_URI_LEN + 1];    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ucs2_num == NULL)
    {
        return MMI_FALSE;
    }
    memset(num_uri, 0, sizeof(num_uri));
    mmi_ucs2_to_asc((CHAR*)num_uri, (CHAR*)ucs2_num);
    if (num_uri[0] == '*' || num_uri[0] == '#')
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
#else
    return MMI_FALSE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_call_para
 * DESCRIPTION
 * initialize make call parameter. The default value is for common use 
 * PARAMETERS
 *  make_call_para:            [IN]      Make call parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init_call_para(mmi_ucm_make_call_para_struct *make_call_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(make_call_para, 0, sizeof(mmi_ucm_make_call_para_struct));   
    make_call_para->dial_type = SRV_UCM_CALL_TYPE_NO_DATA_CSD;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  caller_gid    [IN]
 *  make_call_para    [IN]
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_ucm_call_launch(U16 caller_gid, mmi_ucm_make_call_para_struct *make_call_para)
{
#if defined(__MMI_BT_CALL_SUPPORT__) && !defined(__MMI_UCM_BT_BTBOX_NOLCD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_after_make_call_cb_struct make_call_cb_para;
    mmi_ucm_bt_make_call_para_struct* make_bt_call_para_p;
    S32 unicodeLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_CALL_LAUNCH);
    unicodeLen = mmi_ucs2strlen((CHAR*)make_call_para->ucs2_num_uri);

    if (unicodeLen == 0)
    {
        make_call_cb_para.result = SRV_UCM_RESULT_EMPTY_NUMBER;
        make_call_cb_para.user_data = make_call_para->adv_para.after_callback_user_data;
        if (make_call_para->adv_para.after_make_call_callback != NULL)
        {
            make_call_para->adv_para.after_make_call_callback(&make_call_cb_para);
        }
        mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, NULL);
        return GRP_ID_INVALID;
    }
    else if (!srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
    {
        make_call_cb_para.result = SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
        make_call_cb_para.user_data = make_call_para->adv_para.after_callback_user_data;
        if (make_call_para->adv_para.after_make_call_callback != NULL)
        {
            make_call_para->adv_para.after_make_call_callback(&make_call_cb_para);
        }
        mmi_popup_display_ext(STR_ID_UCM_CONN_BT_FIRST, MMI_EVENT_FAILURE, NULL);
        return GRP_ID_INVALID;
    }
    else if (!mmi_ucm_is_valid_num_bt(make_call_para->ucs2_num_uri))
    {
        make_call_cb_para.result = SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
        make_call_cb_para.user_data = make_call_para->adv_para.after_callback_user_data;
        if (make_call_para->adv_para.after_make_call_callback != NULL)
        {
            make_call_para->adv_para.after_make_call_callback(&make_call_cb_para);
        }
        mmi_popup_display_ext(STR_GLOBAL_INVALID_NUMBER, MMI_EVENT_FAILURE, NULL);
        return GRP_ID_INVALID;
    }
    else if (ecc_custom_verify_emergency_number((kal_uint8*)make_call_para->ucs2_num_uri,
                                                unicodeLen,
                                                ECC_ENCODING_UCS2,
                                                ECC_ALL_CALL,
                                                NULL,
                                                NULL,
                                                NULL)
           || srv_bt_cm_get_linked_dev_list_idx() == 1)
    {
        S32 srv_hd_list[SRV_UCM_BT_MAX_DEV];
        srv_ucm_bt_dev_info_struct dev_info;
        mmi_ucm_bt_make_call_para_struct make_call_bt;

        if (srv_ucm_bt_query_connected_dev_count(srv_hd_list) > 0)
        {
            if (srv_ucm_bt_query_connected_dev_info(srv_hd_list[0], &dev_info))
            {
                mmi_ucm_init_bt_call_para(&make_call_bt, make_call_para);
                memcpy(&make_call_bt.dev_addr, &dev_info.dev_addr, sizeof(srv_bt_cm_bt_addr));
                mmi_ucm_call_launch_bt(&make_call_bt);
            }
        }
        return GRP_ID_INVALID;
    }

    make_bt_call_para_p = OslMalloc(sizeof(mmi_ucm_bt_make_call_para_struct));

    mmi_ucm_init_bt_call_para(make_bt_call_para_p, make_call_para);

    mmi_frm_group_create_ex(GRP_ID_ROOT,
                            GRP_ID_UCM_MO_SELECT, 
                            mmi_ucm_call_select_bt_proc,
                            NULL,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_menu_create_and_run(GRP_ID_UCM_MO_SELECT,
                              CUI_MENU_SRC_TYPE_RESOURCE,
                              CUI_MENU_TYPE_APPMAIN,
                              MENU_ID_UCM_CALL_SELECT,
                              MMI_TRUE,
                              (void*)make_bt_call_para_p);
    return GRP_ID_UCM_MO_SELECT;
#else
    return GRP_ID_INVALID;
#endif /* __MMI_BT_CALL_SUPPORT__ */
}
#endif /* __MMI_TELEPHONY_SUPPORT__ */


