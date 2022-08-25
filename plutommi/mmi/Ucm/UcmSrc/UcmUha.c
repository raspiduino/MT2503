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
 *  UCMMain.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM uri handler agnent source file
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_URI_AGENT__
#include "UcmSrvGProt.h"
#include "mmi_rp_app_ucm_def.h"
#include "mmi_rp_core_ucm_def.h"
#include "UcmGProt.h"  /* for call launch */
#include "UcmUhaProt.h"
#include "UcmCoreProt.h"
#include "ProfilesSrvGprot.h"
#include "Gpiosrvgprot.h"
#include "string.h"
#include "UriAgentSrvGprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "wgui_categories_popup.h"
#include "gui_data_types.h"
#include "custom_events_notify.h"
#include "GlobalConstants.h"
#include "CustDataRes.h"
#include "mmi_frm_timer_gprot.h"
#include "mdi_audio.h"
#include "AlertScreen.h"

mmi_ucm_uha_cntx_struct g_mmi_ucm_uha_cntx;
mmi_ucm_uha_cntx_struct *g_ucm_uha_p = &g_mmi_ucm_uha_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_init
 * DESCRIPTION
 *  Initialize UCM UHA application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_init(void)
{
    /* 1. init context */
    memset(&g_ucm_uha_p->uriagent_makecall, 0, sizeof(mmi_ucm_uha_make_call_struct));
    g_ucm_uha_p->uriagent_makecall.ura_id = SRV_URIAGENT_APPID_MAX;

    memset(&g_ucm_uha_p->uriagent_senddtmf, 0, sizeof(mmi_ucm_uha_send_dtmf_struct));
    g_ucm_uha_p->uriagent_senddtmf.ura_id = SRV_URIAGENT_APPID_MAX;
    
    /* 2. init URI agent registeration */
    mmi_ucm_uha_init_uri_agent_registration();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_reset_make_call_cntx
 * DESCRIPTION
 *  Reset uriagent make call context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_reset_make_call_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_RESET_MAKE_CALL_CNTX);
    
    g_ucm_uha_p->uriagent_makecall.ura_id = SRV_URIAGENT_APPID_MAX;
    g_ucm_uha_p->uriagent_makecall.callback = NULL;
    g_ucm_uha_p->uriagent_makecall.is_confirmed = MMI_FALSE;
    g_ucm_uha_p->uriagent_makecall.got_outgoing_ind = MMI_FALSE;

    if (g_ucm_uha_p->uriagent_makecall.num != NULL)
    {
        OslMfree(g_ucm_uha_p->uriagent_makecall.num);
        g_ucm_uha_p->uriagent_makecall.num = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_enter_make_call_confirm
 * DESCRIPTION
 *  enter uha make call confirm scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_enter_make_call_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_UHA, SCR_ID_UCM_URIAGENT_CONFIRM, 
        (FuncPtr)mmi_ucm_uha_make_call_entry_confirm, 
        (void*)NULL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_make_call_entry_confirm
 * DESCRIPTION
 *  uriagent confirm popup for make call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_make_call_entry_confirm(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* str = (U16*)subMenuData;
    U32 str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_URIAGENT_CONFIRM,
                    (FuncPtr)mmi_ucm_uha_make_call_exit_confirm,
                    (FuncPtr)mmi_ucm_uha_make_call_entry_confirm,
                    MMI_FRM_FG_ONLY_SCRN))
    {
        return;
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_MAKE_CALL_ENTRY_CONFIRM);
    

    str_len = mmi_ucs2strlen((CHAR*)get_string(STR_GLOBAL_DIAL)) + 
              strlen((CHAR*)g_ucm_uha_p->uriagent_makecall.num) +
              mmi_ucs2strlen((CHAR*)get_string(STR_ID_UCM_QUESTION_MARK));

    MMI_ASSERT((str_len * ENCODING_LENGTH) < sizeof(subMenuData));
    memset(subMenuData, 0, sizeof(subMenuData));
    
    mmi_ucs2cpy((CHAR*)str, (CHAR*)get_string(STR_GLOBAL_DIAL));
    mmi_ucs2cat((CHAR*)str, (CHAR*)L"\n");
    mmi_asc_to_ucs2((CHAR*)(str + mmi_ucs2strlen((CHAR*)get_string(STR_GLOBAL_DIAL)) + 1), (CHAR*)g_ucm_uha_p->uriagent_makecall.num);
    mmi_ucs2cat((CHAR*)str, (CHAR*)get_string(STR_ID_UCM_QUESTION_MARK));

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) str,
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        NULL);

    SetLeftSoftkeyFunction(mmi_ucm_uha_make_call_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_ucm_uha_make_call_confirm_no_hdlr, KEY_EVENT_UP);

    SetCenterSoftkeyFunction(mmi_ucm_uha_make_call_confirm_yes_hdlr, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_make_call_exit_confirm
 * DESCRIPTION
 *  uriagent exit func of confirm popup for make call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_make_call_exit_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_tone_enum tone_id = mmi_ucm_uha_get_warning_tone();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_stop_tone(tone_id);

    if (g_ucm_uha_p->uriagent_makecall.is_confirmed == MMI_FALSE)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_MAKE_CALL_EXIT_CONFIRM_CANCEL);

        mmi_ucm_uha_exec_callback(
            g_ucm_uha_p->uriagent_makecall.callback, 
            g_ucm_uha_p->uriagent_makecall.ura_id, 
            SRV_URIAGENT_APPID_CALLMANAGER, 
            SRV_UCM_RESULT_CANCEL);

        mmi_ucm_uha_reset_make_call_cntx();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_make_call_confirm_no_hdlr
 * DESCRIPTION
 *  uriagent no handler of confirm popup for make call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_make_call_confirm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_tone_enum tone_id = mmi_ucm_uha_get_warning_tone();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_MAKE_CALL_CONFIRM_NO_HDLR);

    srv_prof_stop_tone(tone_id);
    mmi_frm_group_close(GRP_ID_UCM_UHA);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_make_call_confirm_yes_hdlr
 * DESCRIPTION
 *  uriagent yes handler of confirm popup for make call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_make_call_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* ucs2_num = NULL;
    srv_prof_tone_enum tone_id = mmi_ucm_uha_get_warning_tone();
    mmi_ucm_make_call_para_struct *make_call_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_MAKE_CALL_CONFIRM_YES_HDLR);

    srv_prof_stop_tone(tone_id);
	
    g_ucm_uha_p->uriagent_makecall.is_confirmed = MMI_TRUE;

    mmi_frm_group_close(GRP_ID_UCM_UHA);
    make_call_para = OslMalloc(sizeof(mmi_ucm_make_call_para_struct));
    memset(make_call_para, 0, sizeof(mmi_ucm_make_call_para_struct));

    ucs2_num = OslMalloc((strlen((CHAR*)g_ucm_uha_p->uriagent_makecall.num) + 1) * ENCODING_LENGTH);
    memset(ucs2_num, 0, ((strlen((CHAR*)g_ucm_uha_p->uriagent_makecall.num) + 1) * ENCODING_LENGTH));
    mmi_asc_to_ucs2((CHAR*)ucs2_num, (CHAR*) g_ucm_uha_p->uriagent_makecall.num);

    mmi_ucm_init_call_para(make_call_para);

    make_call_para->ucs2_num_uri = (U16*)ucs2_num;
    make_call_para->dial_type = MMI_UCM_UHA_SUPPORT_CALL_TYPE;
    make_call_para->adv_para.module_id = SRV_UCM_MODULE_ORIGIN_URI_AGENT;
    /* use callback */
    make_call_para->adv_para.after_make_call_callback = mmi_ucm_uha_after_make_call_cb;
    make_call_para->adv_para.after_callback_user_data = NULL;

    mmi_ucm_call_launch(0, make_call_para);
        
    OslMfree(make_call_para);
    make_call_para = NULL;
    
    OslMfree(ucs2_num);
    ucs2_num = NULL;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_after_make_call_cb
 * DESCRIPTION
 *  the UHA callback after launch make call
 * PARAMETERS
 *  make_call_cb_para:          [IN]        callback parameter for make call result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_after_make_call_cb(mmi_ucm_after_make_call_cb_struct* make_call_cb_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_uha_AFTER_MAKE_CALL_CB_P1,make_call_cb_para->result);
    /* Dial successfully */
    if (SRV_UCM_RESULT_OK == make_call_cb_para->result)
    {
        /* if the call is intercepted, should use unspecified error */
        if (MMI_FALSE ==g_ucm_uha_p->uriagent_makecall.got_outgoing_ind)
        {
            mmi_ucm_uha_exec_callback(
                g_ucm_uha_p->uriagent_makecall.callback, 
                g_ucm_uha_p->uriagent_makecall.ura_id, 
                SRV_URIAGENT_APPID_CALLMANAGER, 
                SRV_UCM_RESULT_UNSPECIFIED_ERROR);
            mmi_ucm_uha_reset_make_call_cntx();
        }
        
        /* else do nothing, because the wtai cb will be handled in connect_ind or rel_ind */
    }
    /* Call type selection is deleted or user press back */
    else if ((SRV_UCM_RESULT_CANCEL == make_call_cb_para->result) ||
              (SRV_UCM_RESULT_USER_ABORT == make_call_cb_para->result))
    {
        mmi_ucm_uha_exec_callback(
            g_ucm_uha_p->uriagent_makecall.callback, 
            g_ucm_uha_p->uriagent_makecall.ura_id, 
            SRV_URIAGENT_APPID_CALLMANAGER, 
            SRV_UCM_RESULT_CANCEL);
        mmi_ucm_uha_reset_make_call_cntx();
    }
    else
    {
        /* The error cause that URI agent cares is already handled before confirm popup*/
        /* the fail for dial action will be returned in launch call permit part. if URI agent
        also cares this, UHA can add more for handling dial related notify and ucm srv should
        also provide module id in dial act notify or srv_ucm_act_rsp_struct cb */
        mmi_ucm_uha_exec_callback(
            g_ucm_uha_p->uriagent_makecall.callback, 
            g_ucm_uha_p->uriagent_makecall.ura_id, 
            SRV_URIAGENT_APPID_CALLMANAGER, 
            SRV_UCM_RESULT_UNSPECIFIED_ERROR);

        mmi_ucm_uha_reset_make_call_cntx();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the indication sent from ucm srv
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ucm_uha_ind_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_ucm_ind_evt_struct *ind = (srv_ucm_ind_evt_struct *) para;
    switch (ind->ind_type)
    {   
        /* care about the call disconnect before call is connected */
        case SRV_UCM_RELEASE_IND:
        {
            srv_ucm_release_ind_struct *release_ind = (srv_ucm_release_ind_struct*) ind->ptr;
            if ((SRV_UCM_MODULE_ORIGIN_URI_AGENT == release_ind->module_id) &&
                (SRV_UCM_OUTGOING_STATE == release_ind->previous_state))
            {
                /* call disconnected. callback to URI agent */        
                mmi_ucm_uha_exec_callback(
                    g_ucm_uha_p->uriagent_makecall.callback, 
                    g_ucm_uha_p->uriagent_makecall.ura_id, 
                    SRV_URIAGENT_APPID_CALLMANAGER, 
                    release_ind->call_end_error_cause);
                
                mmi_ucm_uha_reset_make_call_cntx();
            }

            if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) == 0)
            {
                if (g_ucm_uha_p->uriagent_senddtmf.ura_id != SRV_URIAGENT_APPID_MAX)
                {
                    if (srv_speech_is_phone_mute() == MMI_FALSE)
                    {
                        srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_FALSE);
                    }

                    mmi_ucm_uha_exec_callback(
                        g_ucm_uha_p->uriagent_senddtmf.callback, 
                        g_ucm_uha_p->uriagent_senddtmf.ura_id, 
                        SRV_URIAGENT_APPID_CALLMANAGER, 
                        SRV_UCM_RESULT_NO_ACTIVE_CALL);
        
                    mmi_ucm_uha_reset_uha_send_dtmf_cntx();
                    mmi_frm_scrn_close(GRP_ID_UCM_UHA, SCR_ID_UCM_SEND_DTMF);
                }
            }
        }
        break;

        case SRV_UCM_CONNECT_IND:
        {
            srv_ucm_connect_ind_struct *connect_ind = (srv_ucm_connect_ind_struct*)ind->ptr;
            if (SRV_UCM_MODULE_ORIGIN_URI_AGENT == connect_ind->module_id) 
            {
                /* connected. callback to URI agent */
                mmi_ucm_uha_exec_callback(
                    g_ucm_uha_p->uriagent_makecall.callback, 
                    g_ucm_uha_p->uriagent_makecall.ura_id, 
                    SRV_URIAGENT_APPID_CALLMANAGER, 
                    SRV_UCM_RESULT_OK);

                mmi_ucm_uha_reset_make_call_cntx();

            }
        }
        break;

        case SRV_UCM_OUTGOING_CALL_IND:
        {
            g_ucm_uha_p->uriagent_makecall.got_outgoing_ind = MMI_TRUE;
        }
        break;
        
        default:
        {
            /* do nothing */
        }
        break;
    }
    return MMI_RET_OK; 	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_enter_send_dtmf_confirm
 * DESCRIPTION
 *  enter uha make call confirm scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_enter_send_dtmf_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_UHA, SCR_ID_UCM_URIAGENT_CONFIRM, 
        (FuncPtr)mmi_ucm_uha_send_dtmf_entry_confirm, 
        (void*)NULL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_send_dtmf_entry_confirm
 * DESCRIPTION
 *  uriagent confirm popup for send dtmf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_send_dtmf_entry_confirm(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* str = (U16*)subMenuData;
    U32 str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_URIAGENT_CONFIRM,
                    (FuncPtr)mmi_ucm_uha_send_dtmf_exit_confirm,
                    (FuncPtr)mmi_ucm_uha_send_dtmf_entry_confirm,
                    MMI_FRM_FG_ONLY_SCRN))
    {
        return;
    }
    

    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_SEND_DTMF_ENTRY_CONFIRM);

    str_len = mmi_ucs2strlen((CHAR*)get_string(STR_GLOBAL_SEND)) + 
              mmi_ucs2strlen((CHAR*)get_string(STR_ID_UCM_DTMF)) + 
              strlen((CHAR*)g_ucm_uha_p->uriagent_senddtmf.num) +
              mmi_ucs2strlen((CHAR*)get_string(STR_ID_UCM_QUESTION_MARK));

    MMI_ASSERT((str_len * ENCODING_LENGTH) < sizeof(subMenuData));
    memset(subMenuData, 0, sizeof(subMenuData));
    
    mmi_ucs2cpy((CHAR*)str, (CHAR*)get_string(STR_GLOBAL_SEND));
    mmi_ucs2cat((CHAR*)str, (CHAR*) L" ");
    mmi_ucs2cat((CHAR*)str, (CHAR*)get_string(STR_ID_UCM_DTMF));
    mmi_ucs2cat((CHAR*)str, (CHAR*) L" ");
    mmi_asc_to_ucs2((CHAR*)(str + mmi_ucs2strlen((CHAR*)get_string(STR_GLOBAL_DIAL)) + mmi_ucs2strlen((CHAR*)get_string(STR_ID_UCM_DTMF)) + 2), (CHAR*)g_ucm_uha_p->uriagent_senddtmf.num);
    mmi_ucs2cat((CHAR*)str, (CHAR*)get_string(STR_ID_UCM_QUESTION_MARK));

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) str,
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        NULL);

    SetLeftSoftkeyFunction(mmi_ucm_uha_send_dtmf_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_ucm_uha_send_dtmf_confirm_no_hdlr, KEY_EVENT_UP);

    SetCenterSoftkeyFunction(mmi_ucm_uha_send_dtmf_confirm_yes_hdlr, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_send_dtmf_exit_confirm
 * DESCRIPTION
 *  uriagent exit func of confirm popup for send dtmf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_send_dtmf_exit_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_uha_p->uriagent_senddtmf.is_confirmed == MMI_FALSE)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_SEND_DTMF_EXIT_CONFIRM_CANCEL);

        mmi_ucm_uha_exec_callback(
            g_ucm_uha_p->uriagent_senddtmf.callback, 
            g_ucm_uha_p->uriagent_senddtmf.ura_id, 
            SRV_URIAGENT_APPID_CALLMANAGER, 
            SRV_UCM_RESULT_CANCEL);

        mmi_ucm_uha_reset_uha_send_dtmf_cntx();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_send_dtmf_confirm_no_hdlr
 * DESCRIPTION
 *  uriagent no handler of confirm popup for send dtmf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_send_dtmf_confirm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_SEND_DTMF_CONFIRM_NO_HDLR);
    
    mmi_frm_scrn_close(GRP_ID_UCM_UHA, SCR_ID_UCM_URIAGENT_CONFIRM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_send_dtmf_confirm_yes_hdlr
 * DESCRIPTION
 *  uriagent yes handler of confirm popup for send dtmf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_send_dtmf_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_SEND_DTMF_CONFIRM_YES_HDLR);
    
    g_ucm_uha_p->uriagent_senddtmf.is_confirmed = MMI_TRUE;
    mmi_ucm_uha_enter_send_dtmf();

    mmi_ucm_uha_send_dtmf_action();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_send_dtmf_action
 * DESCRIPTION
 *  execute send dtmf if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_send_dtmf_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    option_check_result = mmi_ucm_uha_send_dtmf_check_hdlr(g_ucm_uha_p->uriagent_senddtmf.num, mmi_ucm_uha_act_callback);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        mmi_ucm_uha_exec_callback(
            g_ucm_uha_p->uriagent_senddtmf.callback, 
            g_ucm_uha_p->uriagent_senddtmf.ura_id, 
            SRV_URIAGENT_APPID_CALLMANAGER, 
            option_check_result);
    
        mmi_ucm_uha_reset_uha_send_dtmf_cntx();        
      
        mmi_frm_scrn_close(GRP_ID_UCM_UHA, SCR_ID_UCM_SEND_DTMF);

        mmi_ucm_uha_display_popup(option_check_result);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_act_callback
 * DESCRIPTION
 *  callback of action
 * PARAMETERS
 *  event:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_uha_act_callback(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_result_evt_struct *act_result = (srv_ucm_act_result_evt_struct *) event;
    srv_ucm_act_rsp_struct *rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_ACT_CB_P1, act_result->act_op);

    switch(event->evt_id)
    {
        case EVT_ID_SRV_UCM_ACTION_RESULT:
        {
            switch (act_result->act_op)
            {
                case SRV_UCM_SEND_DTMF_DIGITS_ACT:
                {
                    rsp = (srv_ucm_act_rsp_struct*) act_result->act_result;

                    if (srv_speech_is_phone_mute() == MMI_FALSE)
                    {
                        srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_FALSE);
                    }

                    mmi_ucm_uha_exec_callback(
                        g_ucm_uha_p->uriagent_senddtmf.callback, 
                        g_ucm_uha_p->uriagent_senddtmf.ura_id, 
                        SRV_URIAGENT_APPID_CALLMANAGER, 
                        rsp->result_info.result);
    
                    mmi_ucm_uha_reset_uha_send_dtmf_cntx();        
                  
                    mmi_frm_scrn_close(GRP_ID_UCM_UHA, SCR_ID_UCM_SEND_DTMF);
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
    return MMI_RET_OK; 
}




/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_enter_send_dtmf_confirm
 * DESCRIPTION
 *  enter uha make call confirm scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_enter_send_dtmf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_UHA, SCR_ID_UCM_SEND_DTMF, 
        (FuncPtr)mmi_ucm_uha_entry_send_dtmf, 
        (void*)NULL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_entry_send_dtmf
 * DESCRIPTION
 *  sending DTMF screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_entry_send_dtmf(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_SEND_DTMF,
                    (FuncPtr)NULL,
                    (FuncPtr)mmi_ucm_uha_entry_send_dtmf,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
      
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_SEND_DTMF_SCREEN);

    ShowCategory66Screen(
        STR_ID_UCM_SENDING_DTMF,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_ID_UCM_PROCESSING),
        IMG_GLOBAL_PROGRESS,
        NULL);
    
    SetRightSoftkeyFunction(mmi_ucm_uha_abort_send_dtmf, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_abort_send_dtmf
 * DESCRIPTION
 *  Abort sending DTMF screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_abort_send_dtmf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_ABORT_SEND_DTMF_SCREEN);

    mmi_ucm_uha_stop_sending_dtmf();

    mmi_ucm_uha_exec_callback(
        g_ucm_uha_p->uriagent_senddtmf.callback, 
        g_ucm_uha_p->uriagent_senddtmf.ura_id, 
        SRV_URIAGENT_APPID_CALLMANAGER, 
        SRV_UCM_RESULT_USER_ABORT);

    mmi_ucm_uha_reset_uha_send_dtmf_cntx();
    mmi_frm_scrn_close(GRP_ID_UCM_UHA, SCR_ID_UCM_SEND_DTMF);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_uri_agent_registration
 * DESCRIPTION
 *  Initialize URI agent registration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_init_uri_agent_registration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uriagent_err_enum err_code = SRV_URIAGENT_ERR_UNSUPPORTED;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = srv_uriagent_register_hdlr_by_scheme("tel", mmi_ucm_uha_make_call, MMI_FALSE);

    if (err_code != SRV_URIAGENT_ERR_OK)
    {
        MMI_ASSERT(0);
    }

    err_code = srv_uriagent_register_hdlr_by_prefix("wtai://wp/mc", mmi_ucm_uha_wtai_make_call, MMI_FALSE);

    if (err_code != SRV_URIAGENT_ERR_OK)
    {
        MMI_ASSERT(0);
    }

    err_code = srv_uriagent_register_hdlr_by_prefix("wtai://wp/sd", mmi_ucm_uha_wtai_send_dtmf, MMI_FALSE);

    if (err_code != SRV_URIAGENT_ERR_OK)
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_wtai_send_dtmf
 * DESCRIPTION
 *  Handler for uri agent wtai send dtmf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_wtai_send_dtmf(srv_uriagent_appid_enum appid, char *url, char *param, srv_uriagent_options_enum options, srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* number_uri = NULL;
    U32 number_uri_len = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_WTAI_SEND_DTMF, appid, options, cb);

    /* pending uri agent send dtmf request */
    if (g_ucm_uha_p->uriagent_senddtmf.ura_id != SRV_URIAGENT_APPID_MAX)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_SEND_DTMF_BUSY);
        
        mmi_ucm_uha_display_popup(SRV_UCM_RESULT_UCM_BUSY);

        mmi_ucm_uha_exec_callback(cb, appid, SRV_URIAGENT_APPID_CALLMANAGER, SRV_UCM_RESULT_UCM_BUSY);

        return;
    }
    
    /* param should be //wp/sd;dtmf */
    number_uri = (U8*)strstr(param, ";");

    if (number_uri == NULL)
    {
        mmi_ucm_uha_display_popup(SRV_UCM_RESULT_INVALID_NUMBER);

        mmi_ucm_uha_exec_callback(cb, appid, SRV_URIAGENT_APPID_CALLMANAGER, SRV_UCM_RESULT_INVALID_NUMBER);
    }
    else    
    {
        number_uri++;

        if (strlen((char*)number_uri) == 0)
        {
            mmi_ucm_uha_display_popup(SRV_UCM_RESULT_EMPTY_NUMBER);

            mmi_ucm_uha_exec_callback(cb, appid, SRV_URIAGENT_APPID_CALLMANAGER, SRV_UCM_RESULT_EMPTY_NUMBER);

            return;
        }
        if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, MMI_UCM_UHA_SUPPORT_CALL_TYPE, NULL) == 0)
        {
            mmi_ucm_uha_display_popup(SRV_UCM_RESULT_NO_ACTIVE_CALL);

            mmi_ucm_uha_exec_callback(cb, appid, SRV_URIAGENT_APPID_CALLMANAGER, SRV_UCM_RESULT_NO_ACTIVE_CALL);

            return;
        }        
        else if (mmi_ucm_uha_check_gsm_dtmf((CHAR*)number_uri) != MMI_TRUE)
        {
            mmi_ucm_uha_display_popup(SRV_UCM_RESULT_INVALID_NUMBER);

            mmi_ucm_uha_exec_callback(cb, appid, SRV_URIAGENT_APPID_CALLMANAGER, SRV_UCM_RESULT_INVALID_NUMBER);

            return;
        }
        else
        {

            number_uri_len = strlen((char*)number_uri);

            if (number_uri_len > SRV_UCM_MAX_DTMF_STR_LEN)
            {
                mmi_ucm_uha_display_popup(SRV_UCM_RESULT_INVALID_NUMBER);

                mmi_ucm_uha_exec_callback(cb, appid, SRV_URIAGENT_APPID_CALLMANAGER, SRV_UCM_RESULT_INVALID_NUMBER);

                return;
            }
            else
            {
                mmi_ucm_uha_reset_uha_send_dtmf_cntx();

                if (mmi_frm_group_is_present(GRP_ID_UCM_UHA))
                {
                    mmi_frm_group_close(GRP_ID_UCM_UHA);
                }
                
                mmi_ucm_uha_sg_create(GRP_ID_ROOT, GRP_ID_UCM_UHA);  

                g_ucm_uha_p->uriagent_senddtmf.ura_id = appid;
                g_ucm_uha_p->uriagent_senddtmf.callback = cb;
                
                g_ucm_uha_p->uriagent_senddtmf.num = OslMalloc(number_uri_len + 1);
                memcpy(g_ucm_uha_p->uriagent_senddtmf.num, number_uri, number_uri_len);
                g_ucm_uha_p->uriagent_senddtmf.num[number_uri_len] = 0;


                if (options & SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP)
                {
                    g_ucm_uha_p->uriagent_senddtmf.is_confirmed = MMI_FALSE;
                    mmi_ucm_uha_enter_send_dtmf_confirm();
                }
                else
                {
                    g_ucm_uha_p->uriagent_senddtmf.is_confirmed = MMI_TRUE;
                    mmi_ucm_uha_send_dtmf_confirm_yes_hdlr();
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_wtai_make_call
 * DESCRIPTION
 *  Handler for uri agent wtai make call request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_wtai_make_call(srv_uriagent_appid_enum appid, char *url, char *param, srv_uriagent_options_enum options, srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char* number_uri = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_WTAI_MAKE_CALL, appid, options, cb);
 
    /* param should be //wp/mc;number */
    number_uri = strstr(param, ";");
    
    if (number_uri != NULL)
    {
        number_uri++;
        mmi_ucm_uha_make_call(appid, url, number_uri, options, cb);
    }
    else
    {
        mmi_ucm_uha_display_popup(SRV_UCM_RESULT_INVALID_NUMBER);

        if (cb != NULL)
        {
            cb(appid, SRV_URIAGENT_APPID_CALLMANAGER, SRV_UCM_RESULT_INVALID_NUMBER);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_make_call
 * DESCRIPTION
 *  Handler for uri agent wtai make call request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_make_call(srv_uriagent_appid_enum appid, char *url, char *param, srv_uriagent_options_enum options, srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum parse_result = SRV_UCM_RESULT_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_MAKE_CALL, appid, options, cb);

    /* pending uri agent make call request */
    if (g_ucm_uha_p->uriagent_makecall.ura_id != SRV_URIAGENT_APPID_MAX)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_MAKE_CALL_BUSY);
        
        mmi_ucm_uha_display_popup(SRV_UCM_RESULT_UCM_BUSY);

        mmi_ucm_uha_exec_callback(cb, appid, SRV_URIAGENT_APPID_CALLMANAGER, SRV_UCM_RESULT_UCM_BUSY);

        return;
    }
    mmi_ucm_uha_reset_make_call_cntx();
    
    parse_result = mmi_ucm_uha_parse_uri((U8*)param, &(g_ucm_uha_p->uriagent_makecall.num));

    if (parse_result != SRV_UCM_RESULT_OK)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_MAKE_CALL_PARSE_FAIL, parse_result);
        
        mmi_ucm_uha_display_popup(parse_result);

        mmi_ucm_uha_exec_callback(cb, appid, SRV_URIAGENT_APPID_CALLMANAGER, parse_result);
        
        mmi_ucm_uha_reset_make_call_cntx();
        return;
    }
    else
    {
			
        if (srv_ucm_is_valid_number(MMI_UCM_UHA_SUPPORT_CALL_TYPE, (U8*) g_ucm_uha_p->uriagent_makecall.num) == MMI_FALSE)
        {
            mmi_ucm_uha_display_popup(SRV_UCM_RESULT_INVALID_NUMBER);

            mmi_ucm_uha_exec_callback(cb, appid, SRV_URIAGENT_APPID_CALLMANAGER, SRV_UCM_RESULT_INVALID_NUMBER);
            
            mmi_ucm_uha_reset_make_call_cntx();

            return;
        }

    }

    if (mmi_frm_group_is_present(GRP_ID_UCM_UHA))
    {
        mmi_frm_group_close(GRP_ID_UCM_UHA);
    }

    mmi_ucm_uha_sg_create(GRP_ID_ROOT, GRP_ID_UCM_UHA);
    
    g_ucm_uha_p->uriagent_makecall.ura_id = appid;
    g_ucm_uha_p->uriagent_makecall.callback = cb;
    
    if (options & SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP)
    {
        g_ucm_uha_p->uriagent_makecall.is_confirmed = MMI_FALSE;
        mmi_ucm_uha_enter_make_call_confirm();
    }
    else
    {
        g_ucm_uha_p->uriagent_makecall.is_confirmed = MMI_TRUE;
        mmi_ucm_uha_make_call_confirm_yes_hdlr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_reset_uha_send_dtmf_cntx
 * DESCRIPTION
 *  Reset uriagent send dtmf context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_reset_uha_send_dtmf_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_RESET_SEND_DTMF_CNTX);
    
    g_ucm_uha_p->uriagent_senddtmf.ura_id = SRV_URIAGENT_APPID_MAX;
    g_ucm_uha_p->uriagent_senddtmf.callback = NULL;
    g_ucm_uha_p->uriagent_senddtmf.is_confirmed = MMI_FALSE;
    
        
    if (g_ucm_uha_p->uriagent_senddtmf.num != NULL)
    {
        OslMfree(g_ucm_uha_p->uriagent_senddtmf.num);
        g_ucm_uha_p->uriagent_senddtmf.num = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_exec_callback
 * DESCRIPTION
 *  Execute uriagent callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_exec_callback(srv_uriagent_uri_request_hdlr_cb cb, srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_EXEC_CALLBACK, cb, ura_appid, uha_appid, result);

    if (cb != NULL)
    {
        cb(ura_appid, uha_appid, (unsigned int)result);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_display_popup
 * DESCRIPTION
 *  Display result popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_display_popup(srv_ucm_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string_id = srv_ucm_query_error_message(result);    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_UHA_DISPLAY_POPUP_P2, result, string_id);
    mmi_popup_display_ext(string_id, MMI_EVENT_FAILURE, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_sg_proc
 * DESCRIPTION
 *  This function is to handle the sg result sent from fw for uha
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_uha_sg_proc(mmi_event_struct *evt)
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
        case EVT_ID_GROUP_INACTIVE:
        {
            
        }
        break;
        
        default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sg_create
 * DESCRIPTION
 *  create SG based on given sg id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_ucm_uha_sg_create(MMI_ID parent_id, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID enter_return_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (group_id)
    {
        case GRP_ID_UCM_UHA:
        {   
            enter_return_id = mmi_frm_group_create_ex(parent_id, group_id, mmi_ucm_uha_sg_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        }
        break;
        
        default: 
        { 
            MMI_ASSERT(0);       
        } 
        break; 
    }
    return enter_return_id;
}

#endif /* __MMI_URI_AGENT__ */
