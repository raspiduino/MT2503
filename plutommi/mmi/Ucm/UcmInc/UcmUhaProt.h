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
 *  UCMProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM URI handling agent internal header file
 *
 * Author:
 * -------
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UCM_UHA_PROT_H
#define UCM_UHA_PROT_H

#include "MMI_features.h"
#ifdef __MMI_URI_AGENT__

#include "UriAgentSrvGprot.h"

#include "UcmSrvGprot.h"
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "UCMGProt.h"

/* Define----------------------------------------------------------------------------------- */
#define MMI_UCM_UHA_SEND_DTMF_SENDING_DURATION    (1000)
#define MMI_UCM_UHA_SEND_DTMF_PAUSE_DURATION    (500)
//#define MMI_UCM_UHA_DTMF_LEN                   (40)


/* Struct----------------------------------------------------------------------------------- */
typedef struct
{
    U8* num;
    srv_uriagent_uri_request_hdlr_cb callback;
    srv_uriagent_appid_enum ura_id;  
    MMI_BOOL got_outgoing_ind;
    MMI_BOOL is_confirmed;
} mmi_ucm_uha_make_call_struct;

typedef struct
{
    U8* num;
    srv_uriagent_uri_request_hdlr_cb callback;
    srv_uriagent_appid_enum ura_id;    
    MMI_BOOL is_confirmed;
} mmi_ucm_uha_send_dtmf_struct;


typedef struct
{
    mmi_ucm_uha_make_call_struct uriagent_makecall;
    mmi_ucm_uha_send_dtmf_struct uriagent_senddtmf;
} mmi_ucm_uha_cntx_struct;

extern mmi_ucm_uha_cntx_struct *g_ucm_uha_p;

/* API----------------------------------------------------------------------------------------- */
extern void mmi_ucm_uha_init(void);
extern void mmi_ucm_uha_reset_make_call_cntx(void);
extern void mmi_ucm_uha_enter_make_call_confirm(void);
extern void mmi_ucm_uha_make_call_entry_confirm(mmi_scrn_essential_struct* scr_info);
extern void mmi_ucm_uha_make_call_exit_confirm(void);
extern void mmi_ucm_uha_make_call_confirm_no_hdlr(void);
extern void mmi_ucm_uha_make_call_confirm_yes_hdlr(void);
extern void mmi_ucm_uha_after_make_call_cb(mmi_ucm_after_make_call_cb_struct* make_call_cb_para);
extern mmi_ret mmi_ucm_uha_ind_hdlr(mmi_event_struct* para);
extern void mmi_ucm_uha_enter_send_dtmf_confirm(void);
extern void mmi_ucm_uha_send_dtmf_entry_confirm(mmi_scrn_essential_struct* scr_info);
extern void mmi_ucm_uha_send_dtmf_exit_confirm(void);
extern void mmi_ucm_uha_send_dtmf_confirm_no_hdlr(void);
extern void mmi_ucm_uha_send_dtmf_confirm_yes_hdlr(void);
extern void mmi_ucm_uha_enter_send_dtmf(void);
extern void mmi_ucm_uha_entry_send_dtmf(mmi_scrn_essential_struct* scr_info);

extern void mmi_ucm_uha_abort_send_dtmf(void);
extern void mmi_ucm_uha_init_uri_agent_registration(void);
extern void mmi_ucm_uha_wtai_send_dtmf(srv_uriagent_appid_enum appid, char *url, char *param, srv_uriagent_options_enum options, srv_uriagent_uri_request_hdlr_cb cb);
extern void mmi_ucm_uha_wtai_make_call(srv_uriagent_appid_enum appid, char *url, char *param, srv_uriagent_options_enum options, srv_uriagent_uri_request_hdlr_cb cb);
extern void mmi_ucm_uha_make_call(srv_uriagent_appid_enum appid, char *url, char *param, srv_uriagent_options_enum options, srv_uriagent_uri_request_hdlr_cb cb);
extern void mmi_ucm_uha_reset_uha_send_dtmf_cntx(void);
extern void mmi_ucm_uha_send_dtmf_action(void);
extern mmi_ret mmi_ucm_uha_act_callback(mmi_event_struct *event);
extern void mmi_ucm_uha_exec_callback(srv_uriagent_uri_request_hdlr_cb cb, srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid, U32 result);
extern void mmi_ucm_uha_display_popup(srv_ucm_result_enum result);
extern mmi_ret mmi_ucm_uha_sg_proc(mmi_event_struct *evt);
extern MMI_ID mmi_ucm_uha_sg_create(MMI_ID parent_id, MMI_ID group_id);
#endif /* __MMI_URI_AGENT__ */

#endif /* UCM_UHA_PROT_H */ 
