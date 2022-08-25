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
 *  SmsAppEditor.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application SMS/EMS Editor 
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *****************************************************************************/
#include "MMI_features.h"
#ifndef __UNIFIED_COMPOSER_SUPPORT__

/**************************************************************
* Header Files Include
**************************************************************/
#include "GlobalResDef.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "GlobalConstants.h"
#include "gui_data_types.h"
#include "wgui_categories_util.h"
#include "gui_typedef.h"
#include "Unicodexdcl.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "ImeGprot.h"
#include "string.h"
#include "ps_public_enum.h"
#include "mmi_rp_app_sms_def.h"
#include "MessagesMiscell.h"

#include "Wgui_ems.h"
#include "Ems.h"
#include "SmsAppGprot.h"
#include "SmsAppProt.h"
#include "SmsAppType.h"
#include "SmsAppUtil.h"
#include "SmsCuiGprot.h"
#include "SmsSrvGprot.h"

#include "AlarmFrameworkProt.h"

#include "PhbSrvGprot.h"
#include "PhbCuiGprot.h"

#include "Conversions.h"
#include "wgui_categories_inputs.h"
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__ 
#include "BookmarkCuiGprot.h"
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__  */

#include "UcmSrvGprot.h"
#ifdef __MMI_SMS_APP_EMS_SUPPORT__
#include "SmsAppEms.h"
#endif
#include "MenuCuiGprot.h"
#include "SimCtrlSrvGProt.h"
#include "NwUsabSrvGprot.h"

#ifdef __ULC_SLIM_EMS__
/* used when EMS lib did not provide charactor counter function */
#include "Gsm7BitNationalLang.h"
#include "wgui_categories_UCE.h"
#endif /* __ULC_SLIM_EMS__ */
#ifdef __MMI_BT_MAP_CLIENT__
#include "SmsBtAppProt.h"
#include "SmsbtmapcSrvStorage.h"
#endif
/**************************************************************
* MARCO
**************************************************************/
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
typedef enum
{
    MMI_SMS_STATE_START = 0,
    MMI_SMS_STATE_GET_DATA,
    
    MMI_SMS_STATE_END
}mmi_sms_state_enum;

/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    wgui_cat28_recipients_struct sms_recipient[CUI_SMS_MAX_RECIPIENTS_NUM];
    U16 curr_index;
    U16 curr_num;
    U16 total_num;
    U8 highlight_state;
    MMI_BOOL is_invalid;
    MMI_BOOL is_full;
    MMI_ID search_phb_cui_id;
    MMI_ID select_phb_cui_id;
    MMI_ID edit_id;
    mmi_sms_state_enum state;
    FuncPtr  callback;
}mmi_sms_recipient_crtl_struct;
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

/**************************************************************
* Global Variables Declaration
**************************************************************/

/**************************************************************
* Global Function Declaration
**************************************************************/
extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__ 
extern int wap_entry_select_bookmark(void);
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__  */
#ifdef __MMI_BT_MAP_CLIENT__		
extern MMI_ID g_sms_bt_gid;		
extern mmi_sms_bt_context_struct g_sms_bt_cntx;		
extern mmi_sms_bt_cntx_struct *g_sms_bt_ui_p;
extern srv_sms_btmapc_bt_enum	g_sms_active_dev_index;	   /* Bt index ID */

extern U16 srv_sms_btmapc_get_usable_text_len(U8 dcs);
#endif/*__MMI_BT_MAP_CLIENT__*/


/**************************************************************
* Static Variables Defination
**************************************************************/
static mmi_id sms_save_to_draft_child_gid  = GRP_ID_INVALID;
static mmi_id sms_save_to_draft_parent_gid  = GRP_ID_INVALID;
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
static mmi_sms_recipient_crtl_struct g_sms_recip_data;
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

#ifdef __MMI_BT_PBAP_CLIENT__
static MMI_BOOL mmi_sms_advance_insert_name = MMI_FALSE;
#endif /* __MMI_BT_PBAP_CLIENT__ */

/**************************************************************
* Static Function Declaration
**************************************************************/
/*FM_SG*/
static mmi_ret mmi_sms_editor_scrn_leave_proc(mmi_event_struct *param);
static void mmi_sms_save_to_drafts_bg_del_rsp(srv_sms_callback_struct *callback_data);
static void mmi_sms_save_to_drafts_background(srv_sms_sim_enum sim);
static void mmi_sms_save_to_drafts_background_callback(srv_sms_callback_struct *callback_data);
static void mmi_sms_entry_editor_options(void);

static void mmi_sms_ed_send(void);

static void mmi_sms_ed_opt_send_to(void);
static void mmi_sms_ed_send_to(void);
#ifdef __MMI_MESSAGES_SMS_EMAIL__
static void mmi_sms_ed_opt_send_as_email(void);
static void mmi_sms_ed_send_as_email(void);
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
#ifdef __MMI_MESSAGES_TEMPLATE__
static void mmi_sms_ed_opt_insert_template(void);
static void mmi_sms_insert_template(S8* text_buff);
#endif /* __MMI_MESSAGES_TEMPLATE__ */

#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__     
static void mmi_sms_ed_opt_insert_bookmark(MMI_ID group_id);
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__  */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
static void mmi_sms_ed_opt_insert_from_phb_internal(MMI_ID group_id, U32 filter);
static mmi_ret mmi_sms_insert_from_phb_internal(mmi_event_struct *evt);

static MMI_BOOL mmi_sms_insert_text_to_editor(S8* text_buff);
#ifdef __MMI_ICON_BAR_SUPPORT__
#define MMI_SMS_EDITOR_FTE_TOOLBAR_NUM  2
static void mmi_sms_editor_set_toolbar(void);
static void mmi_sms_editor_set_toolbar_callback(S32 index);
static void mmi_sms_editor_update_toolbar(void);
#endif /* __MMI_ICON_BAR_SUPPORT__ */

#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
static void mmi_sms_editor_highlight_callback(S32 pre_hilite_index, S32 cur_hilite_index, MMI_BOOL is_pre_text_changed);
static void mmi_sms_editor_add_callback(S32 recipient_index);
static void mmi_sms_editor_remove_callback(S32 recipient_index);
static void mmi_sms_editor_change_callback(S32 recipient_index);
static void mmi_sms_editor_add_recipient(void);
static void mmi_sms_check_ricipient(MMI_ID group_id, void (*f) (void));
static void mmi_sms_get_ricipient_number(void);
static mmi_ret mmi_sms_check_ricipient_proc(mmi_event_struct *evt);
static void mmi_sms_ed_pre_send(void);
static U16 mmi_sms_add_phb_number_to_recipient(U16 count, U16 *phb_index, U8 *num_type);
static MMI_BOOL mmi_sms_add_recipient_to_category(S8 *ucs2_name, S8 *ucs2_addr);
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

#ifdef __ULC_SLIM_EMS__
//static U32 mmi_sms_editor_get_message_size_callback(wgui_uce_text_info_struct *current_text_info, wgui_uce_msg_type_enum uce_msg_type);
//static wgui_uce_text_change_result_enum mmi_sms_editor_text_change_callback(wgui_uce_text_info_struct *new_text_info);
//static wgui_uce_display_enum mmi_sms_editor_display_type_callback(void);
static void mmi_sms_count_buffer_charactor(const S8 *content_buffer, mmi_7bit_counter_struct *content_text_info);
static MMI_BOOL mmi_sms_is_gsm_counter_exceeding(const mmi_7bit_counter_struct *gsm_counter);
//static U32 mmi_sms_editor_remaining_char_count(wgui_uce_text_info_struct *current_text_info);
//static U32 mmi_sms_editor_segment_count(wgui_uce_text_info_struct *current_text_info);
//static void mmi_sms_update_editor_info(CHAR* text_buff);
#endif /* __ULC_SLIM_EMS__ */


/**************************************************************
* Function Defination
**************************************************************/
#ifndef __ULC_SLIM_EMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_editor
 * DESCRIPTION
 *  Pre-Entry SMS/EMS Editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_pre_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sms_is_sms_ready() == MMI_FALSE)
    {
        mmi_sms_display_popup_ext(
            STR_SMS_MSG_NOT_READY_YET,
            MMI_EVENT_FAILURE);
    }
    else
    {
        EMSData *pEMS;
        GetEMSDataForEdit(&pEMS, 0);
    #ifdef __SMS_R8_NATION_LANGUAGE__
    #ifndef __UNIFIED_COMPOSER_SUPPORT__
        mmi_msg_ems_handle_national_lang_change(pEMS);
    #endif
    #else /* __SMS_R8_NATION_LANGUAGE__ */
        if (pEMS->dcs == SMSAL_DEFAULT_DCS)
        {
            if (mmi_msg_ems_need_add_or_remove_escape_char(pEMS) == MMI_TRUE)
            {
                mmi_msg_ems_remove_escape_char(pEMS);
                mmi_msg_ems_add_escape_char(pEMS);
            }
        }
    #endif /* __SMS_R8_NATION_LANGUAGE__ */

    #ifdef __EMS_DYNAMIC_SEG_NUM__
        if (pEMS->dcs == SMSAL_UCS2_DCS && mmi_sms_gui_check_ucs2((S8*) pEMS->textBuffer, (U16) (pEMS->textLength >> 1)) == MMI_FALSE)
        {
            EMSSetDCS(pEMS, SMSAL_DEFAULT_DCS);

            if (mmi_msg_ems_need_add_or_remove_escape_char(pEMS) == MMI_TRUE)
            {
                mmi_msg_ems_remove_escape_char(pEMS);
                mmi_msg_ems_add_escape_char(pEMS);
            }
        }

        if (srv_sms_is_long_sms_dynamic_seg_setting(SRV_SMS_SIM_1) == MMI_TRUE)
        {
            EMSCancelRedundancyData(pEMS, MMI_SMS_MAX_MSG_SEG);
            EMSSetEditSegs(pEMS, MMI_SMS_MAX_MSG_SEG);
        }
        else
        {       
            EMSCancelRedundancyData(pEMS, 1);        
            EMSSetEditSegs(pEMS, 1);
        }
    #endif /* __EMS_DYNAMIC_SEG_NUM__ */

        mmi_sms_set_is_recipient_modify(MMI_FALSE);
        mmi_sms_set_is_sent_false();
        
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        {
            U16 i = 0;

            while (i < CUI_SMS_MAX_RECIPIENTS_NUM)
            {
                if (g_sms_recip_data.sms_recipient[i].is_valid)
                {
                    if (mmi_ucs2strlen(g_sms_recip_data.sms_recipient[i].input_buf) > 0)
                    {
                        mmi_sms_set_highlight_region(WGUI_CAT28_EDITOR);
                        break;
                    }
                    i++;
                }
                else
                {
                    break;
                }
            }
        }
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        mmi_sms_entry_editor();
    }
}

/*FM_SG*/
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_editor
 * DESCRIPTION
 *  Entry SMS/EMS editor Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    EMSData *ems_data;
    mmi_id curr_gid = g_sms_gid;
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    wgui_cat28_recipients_label_struct  lable;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(curr_gid, SCR_ID_SMS_EDITOR, NULL, mmi_sms_entry_editor, MMI_FRM_FULL_SCRN))
    {
        //AlmDisableSPOF();
        srv_reminder_enable(SRV_REMINDER_TYPE_SPOF, MMI_FALSE);
        gui_buffer = mmi_frm_scrn_get_gui_buf(curr_gid, SCR_ID_SMS_EDITOR);
    
        GetEMSDataForEdit(&ems_data, 0);
        if (mmi_sms_is_send_enable())
        {
        #ifdef __MMI_WGUI_CSK_ENABLE__
            EnableCenterSoftkey(0, IMG_GLOBAL_SEND_MSG_CSK);
        #endif
        }
        else
        {
            EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        }
        /*mmi_imc_disable_csk();*/ /*FMKR*/
    #ifdef __MMI_ICON_BAR_SUPPORT__
        mmi_sms_editor_set_toolbar();
        mmi_sms_editor_update_toolbar();
    #endif /* __MMI_ICON_BAR_SUPPORT__ */

    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        lable.label_callback = mmi_sms_editor_add_recipient;
        lable.label_normal_image = get_image(IMG_SMS_TO_NORMAL);
        lable.label_pressed_image = get_image(IMG_SMS_TO_HIGHLIGHT);
        lable.label_string = (UI_buffer_type)get_string(STR_ID_SMS_TO_RECIPIENT);
        wgui_cat28_initialize_recipients(
            g_sms_recip_data.sms_recipient,
            CUI_SMS_MAX_RECIPIENTS_NUM,
            CUI_SMS_MAX_ADDR_LEN + 1,
            IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
            &lable,
            g_sms_recip_data.highlight_state,
            mmi_sms_editor_highlight_callback,
            mmi_sms_editor_add_callback,
            mmi_sms_editor_remove_callback
            );
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        ShowCategory28Screen(
            STR_WMESSAGE_MENUENTRY,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OPTIONS,
            IMG_SMS_COMMON_NOIMAGE,
            STR_GLOBAL_BACK,
            IMG_SMS_COMMON_NOIMAGE,
            ems_data,
            gui_buffer);

        SetCategory28RightSoftkeyFunction( mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

        SetLeftSoftkeyFunction(mmi_sms_entry_editor_options, KEY_EVENT_UP);      
        if (mmi_sms_is_send_enable())
        {
    #ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
            SetCenterSoftkeyFunction(mmi_sms_ed_send, KEY_EVENT_UP);
    #else
            SetCenterSoftkeyFunction(mmi_sms_ed_pre_send, KEY_EVENT_UP);
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        }
        else
        {
            SetCenterSoftkeyFunction(mmi_sms_entry_editor_options, KEY_EVENT_UP);
        }
        mmi_frm_scrn_set_leave_proc(
            curr_gid,
            SCR_ID_SMS_EDITOR,
            mmi_sms_editor_scrn_leave_proc);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_insert_text_to_editor
 * DESCRIPTION
 *  Insert Text to the SMS Editor
 * PARAMETERS
 *  text_buff       [IN] the Input Text Buffer
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_sms_insert_text_to_editor(S8* text_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 char_num;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    char_num = (U16)mmi_ucs2strlen(text_buff);

    if (char_num > 0)
    {
        EMSData *pEMS;
        U8 *guibuffer;
        historyNode *cat28_history;
        MMI_BOOL is_ucs2_char;
        U8 append_result;
        S8 *insert_ucs2_buff = NULL;
        
        guibuffer = mmi_frm_scrn_get_gui_buf(g_sms_gid, SCR_ID_SMS_EDITOR);

        pEMS = GetEMSDataForEdit(0, 0);
        if (pEMS->dcs == SMSAL_UCS2_DCS)
        {
            is_ucs2_char = MMI_TRUE;
        }
        else
        {
            is_ucs2_char = mmi_sms_gui_check_ucs2(text_buff, char_num);
        }

        if (is_ucs2_char == MMI_FALSE)
        {
            insert_ucs2_buff = OslMalloc((char_num * 2 + 1) * ENCODING_LENGTH);
            srv_sms_add_escape_char(insert_ucs2_buff, text_buff, char_num);
        }
        else
        {
            insert_ucs2_buff = text_buff;
        }

        append_result = AppendCategory28String(
                            IMM_INPUT_TYPE_SENTENCE,
                            pEMS,
                            (U8*)insert_ucs2_buff,
                            guibuffer);

        if (append_result == 0)
        {
            result = MMI_FALSE;
        }

        if (is_ucs2_char == MMI_FALSE)
        {
            OslMfree(insert_ucs2_buff);
        }
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        g_sms_recip_data.highlight_state = WGUI_CAT28_EDITOR;
    #endif
    }

    return result;
}



#else /* __ULC_SLIM_EMS__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_editor_no_ems
 * DESCRIPTION
 *  Pre-Entry SMS/EMS Editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_pre_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (mmi_sms_is_sms_ready() == MMI_FALSE)
    {
        mmi_sms_display_popup(
            (UI_string_type)GetString(STR_SMS_MSG_NOT_READY_YET),
            MMI_EVENT_FAILURE);
    }
#else
    if(0)
    {}
#endif
    /* check content is exceeded or not? */
    /* if exceeds, popup for prompt */
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
    else if(mmi_uc_is_uc_reenter())
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
    }
#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */
    else 
    {     
        mmi_sms_set_is_recipient_modify(MMI_FALSE);
        mmi_sms_set_is_sent_false();
        
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        {
            U16 i = 0;

            while (i < CUI_SMS_MAX_RECIPIENTS_NUM)
            {
                if (g_sms_recip_data.sms_recipient[i].is_valid)
                {
                    if (mmi_ucs2strlen(g_sms_recip_data.sms_recipient[i].input_buf) > 0)
                    {
                        mmi_sms_set_highlight_region(WGUI_CAT28_EDITOR);
                        break;
                    }
                    i++;
                }
                else
                {
                    break;
                }
            }
        }
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        mmi_sms_entry_editor();
    }
}


/*FM_SG*/
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_editor
 * DESCRIPTION
 *  Entry SMS/EMS editor Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    EMSData *ems_data;
    mmi_id curr_gid = g_sms_gid;
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    wgui_cat28_recipients_label_struct  lable;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(curr_gid, SCR_ID_SMS_EDITOR, NULL, mmi_sms_entry_editor, MMI_FRM_FULL_SCRN))
    {
        //AlmDisableSPOF();
        srv_reminder_enable(SRV_REMINDER_TYPE_SPOF, MMI_FALSE);
        gui_buffer = mmi_frm_scrn_get_gui_buf(curr_gid, SCR_ID_SMS_EDITOR);
        GetEMSDataForEdit(&ems_data, 0);
        if (mmi_sms_is_send_enable())
        {
            EnableCenterSoftkey(0, IMG_GLOBAL_SEND_MSG_CSK);
        }
        else
        {
            EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        }
        /*mmi_imc_disable_csk();*/ /*FMKR*/
    #ifdef __MMI_ICON_BAR_SUPPORT__
        mmi_sms_editor_set_toolbar();
        mmi_sms_editor_update_toolbar();
    #endif /* __MMI_ICON_BAR_SUPPORT__ */

    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        lable.label_callback = mmi_sms_editor_add_recipient;
        lable.label_normal_image = get_image(IMG_SMS_TO_NORMAL);
        lable.label_pressed_image = get_image(IMG_SMS_TO_HIGHLIGHT);
        lable.label_string = (UI_buffer_type)get_string(STR_ID_SMS_TO_RECIPIENT);
        wgui_cat28_initialize_recipients(
            g_sms_recip_data.sms_recipient,
            CUI_SMS_MAX_RECIPIENTS_NUM,
            CUI_SMS_MAX_ADDR_LEN + 1,
            IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
            &lable,
            g_sms_recip_data.highlight_state,
            mmi_sms_editor_highlight_callback,
            mmi_sms_editor_add_callback,
            mmi_sms_editor_remove_callback
            );
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    wgui_uce_initialize_editor(
            ems_data->textBuffer,
            (ems_data->textBufferSize / ENCODING_LENGTH + 1),
            1,
            1,
            ems_data->textBufferSize / ENCODING_LENGTH,
            mmi_sms_editor_get_message_size_callback,
            mmi_sms_editor_text_change_callback,
            mmi_sms_editor_display_type_callback,
            mmi_sms_editor_remaining_char_count,
            mmi_sms_editor_segment_count,
            NULL,
            NULL);
    
    mmi_sms_update_editor_info((CHAR*)ems_data->textBuffer);
    
    /* show category here */
    ShowCategory280Screen(
        STR_WMESSAGE_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        WGUI_UCE_MSG_TYPE_SMS,
        IMM_INPUT_TYPE_SENTENCE,
        NULL,
        NULL,
        gui_buffer);
    /* set category rsk */
        SetCategory280RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_sms_entry_editor_options, KEY_EVENT_UP);   
        if (mmi_sms_is_send_enable())
        {
    #ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
            SetCenterSoftkeyFunction(mmi_sms_ed_send, KEY_EVENT_UP);
    #else
            SetCenterSoftkeyFunction(mmi_sms_ed_pre_send, KEY_EVENT_UP);
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
        }
        else
        {
            SetCenterSoftkeyFunction(mmi_sms_entry_editor_options, KEY_EVENT_UP);
        }
        mmi_frm_scrn_set_leave_proc(
            curr_gid,
            SCR_ID_SMS_EDITOR,
            mmi_sms_editor_scrn_leave_proc);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_get_message_size_callback
 * DESCRIPTION
 *  Return msg size
 * PARAMETERS
 *  current_text_info       [?]         
 *  uce_msg_type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_sms_editor_get_message_size_callback(wgui_uce_text_info_struct *current_text_info, wgui_uce_msg_type_enum uce_msg_type)
{
     return current_text_info->char_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_text_change_callback
 * DESCRIPTION
 *  Check if the text is allowed to be inserted
 * PARAMETERS
 *  new_text_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
wgui_uce_text_change_result_enum mmi_sms_editor_text_change_callback(wgui_uce_text_info_struct *new_text_info)
{   
    if (new_text_info->UCS2_count > 0)
    {
    #ifndef __MMI_BT_MAP_CLIENT__
        #ifdef __MMI_TELEPHONY_SUPPORT__
        if (new_text_info->char_count > (srv_sms_get_usable_text_len(SMSAL_UCS2_DCS) / 2))
        #endif
    #else
        if (new_text_info->char_count > SRV_SMS_BTMAPC_DISPLAY_CHAR_SIZE)
    #endif/*__MMI_BT_MAP_CLIENT__*/
        {
            return WGUI_UCE_TEXT_CHANGE_NOT_ALLOWED;
        }
    }
    else
    {
    #ifndef __MMI_BT_MAP_CLIENT__
        #ifdef __MMI_TELEPHONY_SUPPORT__
        if (new_text_info->char_count + new_text_info->extension_char_count >
            (srv_sms_get_usable_text_len(SMSAL_DEFAULT_DCS) / 2))
        #endif
    #else          
        #ifdef __MMI_TELEPHONY_SUPPORT__
        if (new_text_info->char_count + new_text_info->extension_char_count >
           (srv_sms_btmapc_get_usable_text_len(SMSAL_DEFAULT_DCS) / 2))
        #else
        if (new_text_info->char_count > SRV_SMS_BTMAPC_DISPLAY_CHAR_SIZE)
        #endif
    #endif/*__MMI_BT_MAP_CLIENT__*/
        {
            return WGUI_UCE_TEXT_CHANGE_NOT_ALLOWED;
        }
    }
    return WGUI_UCE_TEXT_CHANGE_ALLOWED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_display_type_callback
 * DESCRIPTION
 *  Check which display type should be used for mms , display  character or size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
wgui_uce_display_enum mmi_sms_editor_display_type_callback(void)
{
    return WGUI_UCE_DISPLAY_SIZE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_insert_text_to_editor
 * DESCRIPTION
 *  Insert Text to the SMS Editor
 * PARAMETERS
 *  text_buff       [IN] the Input Text Buffer
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_sms_insert_text_to_editor(S8* text_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_allow;
    mmi_id curr_gid = g_sms_gid;
    EMSData *edit_ems = GetEMSDataForEdit(NULL,0);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_allow = mmi_sms_check_if_insert_text_possible((CHAR*)edit_ems->textBuffer, (const CHAR*)text_buff);
    if (is_allow)
    {   
        mmi_scrn_node_struct node_info;
        mmi_frm_scrn_get_info(curr_gid, SCR_ID_SMS_EDITOR, &node_info);
        is_allow =  wgui_uce_insert_text_template(text_buff, mmi_ucs2strlen((const CHAR *)text_buff), node_info.gui_buf);
        mmi_sms_update_editor_info((CHAR*)edit_ems->textBuffer);
    }
    return is_allow;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_insert_text_to_editor
 * DESCRIPTION
 *  Insert Text to the SMS Editor
 * PARAMETERS
 *  text_buff       [IN] the Input Text Buffer
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_sms_update_editor_info(CHAR* text_buff)
{
    wgui_uce_text_info_struct editor_text_info;
    mmi_7bit_counter_struct gsm_text_info;
    mmi_sms_count_buffer_charactor(text_buff, &gsm_text_info);
    editor_text_info.char_count = gsm_text_info.gsm_count + gsm_text_info.ucs2_count + gsm_text_info.gsm_ext_count;
    editor_text_info.extension_char_count = gsm_text_info.gsm_ext_count;
    editor_text_info.UCS2_count = gsm_text_info.ucs2_count;
    editor_text_info.utf8_msg_len = 0;
    wgui_uce_set_current_text_info(&editor_text_info);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_count_buffer_charactor()
 * DESCRIPTION
 *  count content character nubmers
 * PARAMETERS
 *  content_buffer              : [IN]  content to be counted
 *  content_text_info           : [OUT] result of buffer count
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_count_buffer_charactor(const S8 *content_buffer, mmi_7bit_counter_struct *content_text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_7bit_counter_struct *temp_counter = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_7bit_counter_init((U8*)content_buffer);
    temp_counter = mmi_7bit_counter_get_info();
    if (content_text_info != NULL)
    {
        memcpy(content_text_info, temp_counter, sizeof(mmi_7bit_counter_struct));
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_gsm_counter_exceeding()
 * DESCRIPTION
 *  get buffer from 
 * PARAMETERS
 *  content_buffer              : [IN]  content to be counted
 *  capacity                    : [IN]  max ucs2 charactor nubmer of content, '\0'excluded
 * RETURNS
 *  TRUE    data exceeds buffer
 *  FALSE   data not exceeds, data can copy to sms buffer
 *****************************************************************************/
MMI_BOOL mmi_sms_is_gsm_counter_exceeding(const mmi_7bit_counter_struct *gsm_counter)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_exceeding;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(gsm_counter->ucs2_count > 0)
    {
        /* calculate text length with ucs2 capacity */
    #ifdef __MMI_TELEPHONY_SUPPORT__
        #ifdef __MMI_TELEPHONY_SUPPORT__
        is_exceeding = (MMI_BOOL)((gsm_counter->gsm_count + gsm_counter->ucs2_count)> (srv_sms_get_usable_text_len(SMSAL_UCS2_DCS) / 2));
        #endif
    #else
        is_exceeding = MMI_FALSE;
    #endif/*__MMI_BT_MAP_CLIENT__*/
    }
    else
    {
    /* if ucs2 not side */
        /* calculate text length with gsm 7bit char & extend char*/
        /* set return value*/
    #ifdef __MMI_TELEPHONY_SUPPORT__	
        #ifdef __MMI_TELEPHONY_SUPPORT__
        is_exceeding = (MMI_BOOL)((gsm_counter->gsm_count +  gsm_counter->gsm_ext_count) > (srv_sms_get_usable_text_len(SMSAL_DEFAULT_DCS) / 2));
        #endif	
    #else		
        is_exceeding = MMI_FALSE;
    #endif/*__MMI_BT_MAP_CLIENT__*/
    }
    /* END of ucs2 inside */
    return is_exceeding;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_if_insert_text_possible(WCHAR *dest,U32 dest_capacity, const WCHAR *source, U32 source_ucs2_string_length)
 * DESCRIPTION
 *  get buffer from 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sms_check_if_insert_text_possible(const CHAR*dest, const CHAR*source)
{
    mmi_7bit_counter_struct dest_counter;
    mmi_7bit_counter_struct src_counter;
    mmi_7bit_counter_struct total_counter;


    /* check dest, dest_ucs2_string_capacity, source, source_ucs2_string_length */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get dest text info */  
    mmi_sms_count_buffer_charactor(dest, &dest_counter);
    
    /* get source text info */  
    mmi_sms_count_buffer_charactor(source, &src_counter);

    /* get total text info */  
    total_counter.gsm_count = dest_counter.gsm_count + src_counter.gsm_count;
    total_counter.gsm_ext_count= dest_counter.gsm_ext_count + src_counter.gsm_ext_count;
    total_counter.ucs2_count = dest_counter.ucs2_count + src_counter.ucs2_count;

    return (MMI_BOOL)(!mmi_sms_is_gsm_counter_exceeding(&total_counter));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_remaining_char_count
 * DESCRIPTION
 *  Initialize editor
 * PARAMETERS
 *  current_text_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_sms_editor_remaining_char_count(wgui_uce_text_info_struct *current_text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call to do SMS srv internal operations. */
#ifndef __MMI_BT_MAP_CLIENT__
    #ifdef __MMI_TELEPHONY_SUPPORT__
    return (U32) srv_sms_get_last_segment_remaining(
                    current_text_info->UCS2_count,
                    current_text_info->char_count,
                    current_text_info->extension_char_count);
    #endif
#else
    #ifdef __MMI_TELEPHONY_SUPPORT__
    return (U32) srv_sms_btmapc_get_last_segment_remaining(
                    current_text_info->UCS2_count,
                    current_text_info->char_count,
                    current_text_info->extension_char_count);
    #else
    return (SRV_SMS_BTMAPC_DISPLAY_BUFFER_SIZE - current_text_info->char_count);
    #endif

#endif /* __MMI_BT_MAP_CLIENT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_segment_count
 * DESCRIPTION
 *  Initialize editor
 * PARAMETERS
 *  current_text_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_sms_editor_segment_count(wgui_uce_text_info_struct *current_text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 local_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BT_MAP_CLIENT__
    #ifdef __MMI_TELEPHONY_SUPPORT__
    local_value = srv_sms_get_sms_segment_number(
                    current_text_info->UCS2_count,
                    current_text_info->char_count,
                    current_text_info->extension_char_count);
    #endif
#else
    local_value = srv_sms_btmapc_get_sms_segment_number(
                    current_text_info->UCS2_count,
                    current_text_info->char_count,
                    current_text_info->extension_char_count);

#endif /* __MMI_BT_MAP_CLIENT__ */

    return local_value;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_update_ems_length
 * DESCRIPTION
 *  Initialize editor
 * PARAMETERS
 *  current_text_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_editor_update_ems_length(EMSData *ems_data)
{
    ems_data->textLength = mmi_ucs2strlen((const CHAR *)ems_data->textBuffer) * ENCODING_LENGTH;
    MMI_ASSERT(ems_data->textLength <= (ems_data->textBufferSize));
}
#endif /* __ULC_SLIM_EMS__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_scrn_leave_proc
 * DESCRIPTION
 *  SMS/EMS Editor Screen Delete Callback Function
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_ret mmi_sms_editor_scrn_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *ems_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            //AlmEnableSPOF();
            
            #ifdef __MMI_TELEPHONY_SUPPORT__
            srv_reminder_enable(SRV_REMINDER_TYPE_SPOF, MMI_TRUE);
            #endif /* __MMI_TELEPHONY_SUPPORT__ */
            GetEMSDataForEdit(&ems_data, 0);
            
            if(mmi_sms_get_is_sent() == MMI_TRUE)
            {
                ReleaseEMSEditBuffer();
                mmi_sms_reset_recipient_data();
            }
            else
            
            if (mmi_sms_is_ems_content_empty(ems_data) == MMI_FALSE)
            {
                mmi_sms_send_case_enum send_case = mmi_sms_get_send_msg_case();
            #ifdef __MMI_TELEPHONY_SUPPORT__
            #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
            #else
                srv_sms_sim_enum msg_sim_id = SRV_SMS_SIM_1;
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            
            
               if ((send_case == SMS_SEND_CASE_EDIT_DRAFT))
                {
                    srv_sms_sim_enum *origin_sim = OslMalloc(sizeof(srv_sms_sim_enum));
                    *origin_sim = msg_sim_id;
                    srv_sms_delete_msg(
                        g_sms_cntx.curr_msg_id,
                        mmi_sms_save_to_drafts_bg_del_rsp,
                        origin_sim);
                }
                else
                {
                    mmi_sms_save_to_drafts_background(msg_sim_id);
                }
            #endif/*__MMI_TELEPHONY_SUPPORT__*/
            }
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            break;
   
        default:
            break;
    }

    return MMI_RET_OK; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_save_to_drafts_bg_del_rsp
 * DESCRIPTION
 *  Delete the Edited Drafts's Msg Background Response
 * PARAMETERS
 *  data        [IN]    Dummy
 *  mod         [IN]    Module Type
 *  result      [IN]    SMS Framework Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_save_to_drafts_bg_del_rsp(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim = *((srv_sms_sim_enum*)callback_data->user_data);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OslMfree(callback_data->user_data);
    if (callback_data->result == MMI_TRUE)
    {
        mmi_sms_save_to_drafts_background(sim);
    }
    else
    {
        srv_sms_callback_struct data;
        data.result = MMI_FALSE;
        mmi_sms_save_to_drafts_background_callback(&data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_save_to_drafts_background_callback
 * DESCRIPTION
 *  Callback Function Of Save message in the editor to drafts background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_save_to_drafts_background(srv_sms_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE sms_handle;
    EMSData *ems_data;
#ifdef __MMI_TELEPHONY_SUPPORT__
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    mmi_sms_msg_type_enum msg_type = mmi_sms_get_send_type();
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForEdit(&ems_data, 0);
    sms_handle = srv_sms_get_save_handle();

    srv_sms_set_status(sms_handle, SRV_SMS_STATUS_DRAFT);

    srv_sms_set_sim_id(sms_handle, sim);

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (msg_type == SMS_MSG_TYPE_EMAIL)
    {
        srv_sms_set_pid(sms_handle, SRV_SMS_PID_EMAIL);
    }
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

#ifndef  __ULC_SLIM_EMS__
    srv_sms_set_content_ems(sms_handle, ems_data);
#else /* __ULC_SLIM_EMS__ */
    srv_sms_set_content(sms_handle, (char *)ems_data->textBuffer, ems_data->textBufferSize);
#endif /* __ULC_SLIM_EMS__ */
    srv_sms_save_msg(sms_handle, mmi_sms_save_to_drafts_background_callback, NULL);
#endif /* __MMI_TELEPHONY_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_save_to_drafts_background_callback
 * DESCRIPTION
 *  Callback Function Of Save message in the editor to drafts background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_save_to_drafts_background_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback_data->result == MMI_TRUE)
    {
        ReleaseEMSEditBuffer();
        mmi_sms_reset_recipient_data();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_ed_send
 * DESCRIPTION
 *  The Editor CSK Handler Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_ed_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    mmi_sms_msg_type_enum preferred_msg_type;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    preferred_msg_type = mmi_sms_get_preferred_msg_type();
    mmi_sms_set_send_type(preferred_msg_type);
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

#ifdef __ULC_SLIM_EMS__
    mmi_sms_editor_update_ems_length(g_sms_cntx.edit_ems_data);
#endif /* __ULC_SLIM_EMS__ */ 


#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    mmi_sms_pre_entry_add_recipient(MMI_FALSE);
#else
    if (mmi_sms_get_recipient_num() > 0)
    {
        mmi_sms_pre_entry_add_recipient(MMI_TRUE);
    }
    else
    {
        mmi_sms_editor_add_recipient();
    }
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
}


/*FM_SG*/
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_editor_options
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_entry_editor_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_sms_entry_menu_cui_options_generic(
        g_sms_gid,
        MENU_ID_SMS_EDITOR_OPTIONS,
        0);
}


/*****************************************************************************
* FUNCTION
*  mmi_sms_editor_opt_entry_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_sms_editor_opt_entry_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_evt->sender_id;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    mmi_sms_msg_type_enum preferred_type;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    preferred_type = mmi_sms_get_preferred_msg_type();

    switch (preferred_type)
    {
        case SMS_MSG_TYPE_TEXT:
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_ED_OPT_SEND_TO, MMI_FALSE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_ED_OPT_SEND_AS_EMAIL, MMI_TRUE);
            break;
        }

        case SMS_MSG_TYPE_EMAIL:
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_ED_OPT_SEND_TO, MMI_TRUE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_ED_OPT_SEND_AS_EMAIL, MMI_FALSE);
            break;
        }

        case SMS_MSG_TYPE_UNLIMITED:
        default:
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_ED_OPT_SEND_TO, MMI_FALSE);
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_ED_OPT_SEND_AS_EMAIL, MMI_FALSE);
            break;
        }
    }
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

#ifdef __MMI_TELEPHONY_SUPPORT__
    if (!srv_sms_is_sms_valid())
    {
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if (srv_sim_ctrl_get_num_of_inserted()==0)
        {
            cui_menu_set_item_disabled(cui_menu_gid, MENU_ID_SMS_ED_OPT_SEND_TO, MMI_TRUE);
#ifdef __MMI_MESSAGES_SMS_EMAIL__
            cui_menu_set_item_disabled(cui_menu_gid, MENU_ID_SMS_ED_OPT_SEND_AS_EMAIL, MMI_TRUE);
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
#if !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__)
          //  cui_menu_set_item_disabled(cui_menu_gid, MENU_ID_SMS_ED_OPT_ADD_RECIPIENT, MMI_TRUE);
#endif

        }
        else
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
        {
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_ED_OPT_SEND_TO, MMI_TRUE);
#ifdef __MMI_MESSAGES_SMS_EMAIL__
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_ED_OPT_SEND_AS_EMAIL, MMI_TRUE);
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
#if !defined(__MMI_UNIFIED_COMPOSER__) && defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__)
            cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_ED_OPT_ADD_RECIPIENT, MMI_TRUE);
#endif

        }
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    
#ifndef __MMI_TELEPHONY_SUPPORT__
if(g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered == SRV_SMS_BTMAPC_BOX_DRAFTS)
    cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS, MMI_TRUE);
#endif
#if (MMI_MAX_SIM_NUM >= 2) 
    mmi_sms_set_save_send_select_sim_leaf_item(cui_menu_gid, MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS, srv_nw_usab_is_usable);
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_opt_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_editor_opt_select_hdlr(mmi_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = (cui_menu_event_struct*)menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cui_menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SMS_ED_OPT_SEND_TO:
        #ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
            mmi_sms_ed_opt_send_to();
        #else
            mmi_sms_ed_pre_send();
        #endif
            break;
            
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
         case MENU_ID_SMS_ED_OPT_ADD_RECIPIENT:
            mmi_sms_editor_add_recipient();
            break;
    #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        case MENU_ID_SMS_ED_OPT_SEND_AS_EMAIL:
            mmi_sms_ed_opt_send_as_email();
            break;
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

    #ifdef __MMI_MESSAGES_TEMPLATE__
        case MENU_ID_SMS_ED_OPT_INSERT_TEMPLATE:
            mmi_sms_ed_opt_insert_template();
            break;
    #endif /* __MMI_MESSAGES_TEMPLATE__ */
    #ifndef __MMI_SMS_SLIM__
        case MENU_ID_SMS_ED_OPT_ADVANCED:
            break; /*no need deal, entry advance */
     #endif

    //#ifdef __MMI_TELEPHONY_SUPPORT__
        case MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS:
            {
            #ifndef __MMI_TELEPHONY_SUPPORT__
            if(g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered == SRV_SMS_BTMAPC_BOX_NONE || g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered != SRV_SMS_BTMAPC_BOX_DRAFTS)
            #endif
            {
			srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;
			mmi_sim_enum total_sim = MMI_SIM_NONE;
            #ifndef __MMI_TELEPHONY_SUPPORT__
            mmi_sim_enum sim1_valid = MMI_SIM_NONE;
            #else
			mmi_sim_enum sim1_valid = srv_nw_usab_is_usable(MMI_SIM1)? MMI_SIM1:MMI_SIM_NONE;
			 #if (MMI_MAX_SIM_NUM >=2)
			mmi_sim_enum sim2_valid = srv_nw_usab_is_usable(MMI_SIM2)?MMI_SIM2:MMI_SIM_NONE;
			#endif
			#if (MMI_MAX_SIM_NUM  >=3)
			mmi_sim_enum sim3_valid = srv_nw_usab_is_usable(MMI_SIM3)?MMI_SIM3:MMI_SIM_NONE;
			#endif
			 #if (MMI_MAX_SIM_NUM  >=4)
			mmi_sim_enum sim4_valid = srv_nw_usab_is_usable(MMI_SIM4)?MMI_SIM4:MMI_SIM_NONE;
			#endif
            #endif/*__MMI_TELEPHONY_SUPPORT__*/
			total_sim = sim1_valid
										 #if (MMI_MAX_SIM_NUM >=2)
										 |sim2_valid
										 #endif
										 #if (MMI_MAX_SIM_NUM  >=3)
										 |sim3_valid
										 #endif
										 #if (MMI_MAX_SIM_NUM  >=4)
										 |sim4_valid
										 #endif
										 ;
			
			switch(total_sim)
			{
				case MMI_SIM_NONE:
				case MMI_SIM1:
				 sim_id = SRV_SMS_SIM_1;
				 break;
				 
				   #if (MMI_MAX_SIM_NUM >=2)
				   case MMI_SIM2:
				  sim_id = SRV_SMS_SIM_2;
				 break;
				   #if (MMI_MAX_SIM_NUM  >=3)
				   case MMI_SIM3:
				  sim_id = SRV_SMS_SIM_3;
				 break;
				 
				  #if (MMI_MAX_SIM_NUM  >=4)
				   case MMI_SIM4:
				  sim_id = SRV_SMS_SIM_4;
                break;
				 #endif
 			    #endif
				 #endif
				
				 default:
				 return MMI_RET_OK;
                }

            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            #ifdef __MMI_TELEPHONY_SUPPORT__
					if(srv_sms_get_prefer_storage(SRV_SMS_SIM_1) == SRV_SMS_STORAGE_TCARD)
                {
						 if (!srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
                {
								 mmi_sms_entry_confirm(
								GRP_ID_ROOT,
								STR_ID_SMS_CARD_NOT_PRESENT_USE_PHONE_MEM,
								mmi_msg_pref_storage_unavail_yes,
								mmi_msg_pref_storage_unavail_no,
								MMI_TRUE);
								g_sms_cntx.tcard_sim_id = sim_id;
								return MMI_RET_OK;
                }
            }
            #endif
            #endif
            mmi_sms_ed_opt_save_to_drafts(g_sms_gid, sim_id);
          }
        }
            break;
    //#endif/*__MMI_TELEPHONY_SUPPORT__*/
            
        #if ((MMI_MAX_SIM_NUM >= 2))
            case   MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS_BY_SIM1:
                mmi_sms_ed_opt_save_to_drafts(g_sms_gid, SRV_SMS_SIM_1);
            break;
            case   MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS_BY_SIM2:
            mmi_sms_ed_opt_save_to_drafts(g_sms_gid, SRV_SMS_SIM_2);
            break;
        #if (MMI_MAX_SIM_NUM >= 3)
            case   MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS_BY_SIM3:
            mmi_sms_ed_opt_save_to_drafts(g_sms_gid, SRV_SMS_SIM_3);
            break;
            #if (MMI_MAX_SIM_NUM >= 4)
            case   MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS_BY_SIM4:
            mmi_sms_ed_opt_save_to_drafts(g_sms_gid, SRV_SMS_SIM_4);
            break;
        #endif /* (MMI_MAX_SIM_NUM >= 4) */
        #endif /* (MMI_MAX_SIM_NUM >= 3) */
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
    }

    return MMI_RET_OK;
}


#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_advanced_entry_hdlr
 * DESCRIPTION
 *  Entry the "Advanced" menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_editor_advanced_entry_hdlr(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__ 
    MMI_ID cui_menu_gid = menu_gid;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__ 
    /* Hide Insert Bookmark menu item if in-call. */
    /* Before UM, WAP widget is not allowed to be entered if in-call. */
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_ED_OPT_INSERT_BOOKMARK, MMI_TRUE);
    }
    else        
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_ED_OPT_INSERT_BOOKMARK, MMI_FALSE);
    }
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__  */

    return MMI_RET_OK;
}
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__  */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_advanced_select_hdlr
 * DESCRIPTION
 *  Entry the "Advanced" menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_editor_advanced_select_hdlr(mmi_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = (cui_menu_event_struct*)menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cui_menu_evt->highlighted_menu_id)
    {
    #ifdef __MMI_SMS_APP_EMS_SUPPORT__
        case MENU_ID_SMS_ED_OPT_INSERT_OBJECT:
            mmi_ems_entry_insert_object(g_sms_gid);
            break;
    #endif /* __MMI_SMS_APP_EMS_SUPPORT__ */
//#ifndef __MMI_SMS_SLIM__
        case MENU_ID_SMS_ED_OPT_INSERT_NUMBER:
        {
        #ifdef __MMI_BT_PBAP_CLIENT__
            mmi_sms_advance_insert_name = MMI_FALSE;
        #endif 
            mmi_sms_ed_opt_insert_from_phb_internal(g_sms_gid, SRV_PHB_ENTRY_FIELD_NUMBER);
        }
            break;
//#endif

#ifndef __MMI_SMS_SLIM__
        case MENU_ID_SMS_ED_OPT_INSERT_NAME:
        {
        #ifdef __MMI_BT_PBAP_CLIENT__
            mmi_sms_advance_insert_name = MMI_TRUE;
        #endif 
            mmi_sms_ed_opt_insert_from_phb_internal(g_sms_gid, SRV_PHB_ENTRY_FIELD_NAME);
        }
            break;
            #endif

    #ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__     
        case MENU_ID_SMS_ED_OPT_INSERT_BOOKMARK:
            mmi_sms_ed_opt_insert_bookmark(g_sms_gid);
            break;
    #endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__  */

    #ifdef __MMI_SMS_APP_EMS_SUPPORT__
        case MENU_ID_SMS_ED_OPT_TEXT_FORMAT:
            mmi_ems_entry_text_format(g_sms_gid);
            break;
    #endif /* __MMI_SMS_APP_EMS_SUPPORT__ */

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_ed_opt_send_to
 * DESCRIPTION
 *  The "Send to" menu LSK Handle Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_ed_opt_send_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_ed_send_to();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_ed_send_to
 * DESCRIPTION
 *  The "Send to" menu LSK Handle Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_ed_send_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    mmi_sms_set_send_type(SMS_MSG_TYPE_TEXT);
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifndef __MMI_TELEPHONY_SUPPORT__
if(g_sms_bt_ui_p[g_sms_active_dev_index].curr_entered != SRV_SMS_BTMAPC_BOX_DRAFTS)
    mmi_sms_pre_entry_add_recipient(MMI_FALSE);
else
    mmi_sms_pre_entry_add_recipient(MMI_TRUE);
#else
    mmi_sms_pre_entry_add_recipient(MMI_FALSE);
#endif
}


#ifdef __MMI_MESSAGES_SMS_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_ed_opt_send_as_email
 * DESCRIPTION
 *  The "Send as Email" menu LSK Handle Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_ed_opt_send_as_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_ed_send_as_email();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_ed_send_as_email
 * DESCRIPTION
 *  The "Send as Email" menu LSK Handle Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_ed_send_as_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_sms_set_send_type(SMS_MSG_TYPE_EMAIL);
    mmi_sms_pre_entry_add_recipient(MMI_FALSE);
}
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */


#ifdef __MMI_MESSAGES_TEMPLATE__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_highlight_mark_as_unread
 * DESCRIPTION
 *  The "Send as Email" menu LSK Handle Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_ed_opt_insert_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_template_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_template_gid = cui_sms_template_list_create(g_sms_gid, MMI_TRUE, CUI_SMS_TEMPLATE_NONE, MMI_TRUE);

    if (cui_template_gid != GRP_ID_INVALID)
    {
        cui_sms_template_list_set_csk_softkey(cui_template_gid, 0, IMG_GLOBAL_COMMON_CSK);
        cui_sms_template_list_run(cui_template_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_insert_template_hdlr
 * DESCRIPTION
 *  Highlight "Mark as unread" menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_ed_insert_template_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_template_evt_struct *temp_evt = (cui_sms_template_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (temp_evt->key_pressed)
    {
        case MMI_LEFT_SOFTKEY:
        case MMI_CENTER_SOFTKEY:
            {
                WCHAR *text_buff = cui_sms_template_list_get_select_content(temp_evt->sender_id);
                mmi_sms_insert_template((S8*)text_buff);
                cui_sms_template_close(temp_evt->sender_id);
            }
            break;

        case MMI_RIGHT_SOFTKEY:
            cui_sms_template_close(temp_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_highlight_mark_as_unread
 * DESCRIPTION
 *  Highlight "Mark as unread" menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_insert_template(S8* text_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID string_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((text_buff == NULL) || (mmi_ucs2strlen((const CHAR *)text_buff) == 0))
    {
        string_id = STR_GLOBAL_EMPTY;
    }
    else
    {
        MMI_BOOL result;
        result = mmi_sms_insert_text_to_editor(text_buff);
        if (result == MMI_FALSE)
        {
            string_id = STR_NO_SPACE_TO_INSERT_OBJECT;
        }
    }

    if (string_id != 0)
    {
        mmi_sms_display_popup_ext(
            string_id,
            MMI_EVENT_FAILURE);
    }
}

#endif /* __MMI_MESSAGES_TEMPLATE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_send_msg_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static mmi_ret mmi_sms_save_to_drafts_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
        case EVT_ID_GROUP_INACTIVE:
            break;

        case EVT_ID_GROUP_DEINIT:
            /* need addd code to release buffer */
            sms_save_to_draft_child_gid = GRP_ID_INVALID;
            break;

        case EVT_ID_CUI_SMS_SAVE:
            ReleaseEMSEditBuffer();
            mmi_sms_reset_recipient_data();

            mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_EDITOR);
            #if (defined(__MMI_BT_MAP_CLIENT__) && !defined(__MMI_TELEPHONY_SUPPORT__))
            cui_sms_save_close(g_sms_bt_gid);
            #endif
            cui_sms_save_close(sms_save_to_draft_child_gid);
            mmi_frm_group_close(sms_save_to_draft_parent_gid);
            break;
        case EVT_ID_CUI_SMS_SAVE_CANCEL:
            cui_sms_save_close(sms_save_to_draft_child_gid);
            mmi_frm_group_close(sms_save_to_draft_parent_gid);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_highlight_mark_as_unread
 * DESCRIPTION
 *  The "Send as Email" menu LSK Handle Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_ed_opt_save_to_drafts(MMI_ID group_id, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_save_to_draft_parent_gid = mmi_frm_group_create_ex(
                                        GRP_ID_ROOT,
                                        GRP_ID_AUTO_GEN,
                                        mmi_sms_save_to_drafts_proc,
                                        NULL,
                                        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    sms_save_to_draft_child_gid = cui_sms_save_create(sms_save_to_draft_parent_gid);

    if(sms_save_to_draft_child_gid != GRP_ID_INVALID)
    {
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        mmi_sms_msg_type_enum msg_type = mmi_sms_get_send_type();
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
        mmi_sms_send_case_enum send_case;
    
#ifdef __ULC_SLIM_EMS__
        mmi_sms_editor_update_ems_length(g_sms_cntx.edit_ems_data);
#endif /* __ULC_SLIM_EMS__ */ 


#ifndef __ULC_SLIM_EMS__
        cui_sms_set_save_content_ems(sms_save_to_draft_child_gid, g_sms_cntx.edit_ems_data);
#else /* __ULC_SLIM_EMS__ */ 
        #ifdef __MMI_TELEPHONY_SUPPORT__
        cui_sms_set_save_content_text(sms_save_to_draft_child_gid, (U16*)g_sms_cntx.edit_ems_data->textBuffer, g_sms_cntx.edit_ems_data->textBufferSize + ENCODING_LENGTH);
        #else
        cui_sms_set_save_content_text(sms_save_to_draft_child_gid, (U16*)g_sms_cntx.edit_ems_data->textBuffer, g_sms_cntx.edit_ems_data->textBufferSize);
        #endif
#endif /* __ULC_SLIM_EMS__ */ 
        cui_sms_set_save_msg_status(sms_save_to_draft_child_gid, SRV_SMS_STATUS_DRAFT);

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        cui_sms_set_save_title_id(sms_save_to_draft_child_gid, STR_SMS_SAVE_TO_DRAFTS_MENU_ITEM);
    #else /*__MMI_MESSAGES_DRAFT_BOX__*/
        cui_sms_set_save_title_id(sms_save_to_draft_child_gid, STR_GLOBAL_SAVE);
    #endif /*__MMI_MESSAGES_DRAFT_BOX__*/
        send_case = mmi_sms_get_send_msg_case();
    #if (defined(__MMI_BT_MAP_CLIENT__) && !defined(__MMI_TELEPHONY_SUPPORT__))
        if(send_case == SMS_SEND_CASE_EDIT_DRAFT)
        {
            cui_sms_set_save_edit_draft_msg_id(sms_save_to_draft_child_gid, g_sms_bt_cntx.curr_msg_id);
        }
    #else
        if (send_case == SMS_SEND_CASE_EDIT_DRAFT)
        {
            cui_sms_set_save_edit_draft_msg_id(sms_save_to_draft_child_gid, g_sms_cntx.curr_msg_id);
        }
    #endif

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (msg_type == SMS_MSG_TYPE_EMAIL)
        {
            cui_sms_set_save_pid(sms_save_to_draft_child_gid, SRV_SMS_PID_EMAIL);
        }
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
		#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
		#endif
		#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

        cui_sms_save_run(sms_save_to_draft_child_gid);
    }
    else
    {
        cui_sms_save_close(sms_save_to_draft_parent_gid);
    }
}


#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

static void mmi_sms_ed_opt_insert_from_phb_internal(MMI_ID group_id, U32 filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID phb_gid;
    MMI_ID select_phb_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_gid = mmi_frm_group_create_ex(
                group_id,
                GRP_ID_AUTO_GEN,
                mmi_sms_insert_from_phb_internal,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);

#ifndef __MMI_BT_PBAP_CLIENT__
    select_phb_cui_id = cui_phb_list_select_contact_create(phb_gid);
 
    if (select_phb_cui_id != GRP_ID_INVALID)
    {
        cui_phb_list_select_contact_set_field_filter(select_phb_cui_id, filter);

        cui_phb_list_select_contact_run(select_phb_cui_id);
    }
    else
    {
        mmi_frm_group_close(phb_gid);
    }
#else
    select_phb_cui_id = cui_phb_pbapc_select_contact_create(phb_gid);
 
    if (select_phb_cui_id != GRP_ID_INVALID)
    {
        cui_phb_pbapc_select_contact_run(select_phb_cui_id);
    }
    else
    {
        mmi_frm_group_close(phb_gid);
    }
#endif
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_insert_name_from_phb
 * DESCRIPTION
 *  Insert phonebook name into the SMS editor
 * PARAMETERS
 *  name        [IN]    Phonebook name
 *  number      [IN]    Phonebook number
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sms_insert_from_phb_internal(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_select_contact_result_struct* select_contact_result;

#ifdef __MMI_BT_PBAP_CLIENT__
    cui_phb_pbapc_select_contact_rsp_struct* select_result; 
    MMI_ID error_string = 0;
    S8 * data_to_insert;
    MMI_BOOL insert_result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    #ifndef __MMI_BT_PBAP_CLIENT__
        case EVT_ID_PHB_SELECT_CONTACT:
            select_contact_result = (cui_phb_select_contact_result_struct*)evt;
            {
                MMI_ID error_string = 0;
                S8 * data_to_insert = (S8 *)select_contact_result->name; 
                /* default to add name */
                if (select_contact_result->data_type == SRV_PHB_ENTRY_FIELD_NUMBER)
                {
                    data_to_insert = (S8 *)select_contact_result->select_data;
                }
                if (mmi_ucs2strlen((S8*)data_to_insert))
                {
                    MMI_BOOL insert_result;

                    insert_result = mmi_sms_insert_text_to_editor(data_to_insert);

                    if (insert_result == 0)
                    {
                        error_string = STR_NO_SPACE_TO_INSERT_OBJECT;
                    }
                }
                else
                {
                    error_string = STR_GLOBAL_EMPTY;
                }    
                if (error_string != 0)
                {
                    mmi_sms_display_popup_ext(
                        error_string,
                        MMI_EVENT_FAILURE);
                }
                cui_phb_list_select_contact_close(select_contact_result->sender_id);
            }
            break;

        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
            {
                mmi_group_event_struct *group_evt = (mmi_group_event_struct*)evt;
                cui_phb_list_select_contact_close(group_evt->sender_id);
            }
            break;
    #else
        case EVT_ID_PHB_PBAPC_SEL_CONTACT:            
            select_result = (cui_phb_pbapc_select_contact_rsp_struct*) evt;
            if (MMI_PHB_PBAPC_SEL_REQ_CLOSE == select_result->rsp_type)
                cui_phb_pbapc_select_contact_close(select_result->sender_id);
            else
            {
                cui_phb_pbapc_select_contact_ret_struct* select_ret_result = (cui_phb_pbapc_select_contact_ret_struct*)select_result->rsp;
                if (MMI_PHB_PBAPC_SEL_RET_OK == select_ret_result->ret)
                {
                    if (mmi_sms_advance_insert_name)
                        data_to_insert = (S8 *)select_ret_result->name; 
                    else                        
                        data_to_insert = (S8 *)select_ret_result->number; 
                    
                    if (mmi_ucs2strlen((S8*)data_to_insert))
                    {
                        insert_result = mmi_sms_insert_text_to_editor(data_to_insert);

                        if (insert_result == 0)
                        {
                            error_string = STR_NO_SPACE_TO_INSERT_OBJECT;
                        }
                    }
                    else
                    {
                        error_string = STR_GLOBAL_EMPTY;
                    }    
                    if (error_string != 0)
                    {
                        mmi_sms_display_popup_ext(
                            error_string,
                            MMI_EVENT_FAILURE);
                    }
                }
            }
            break;
    #endif
                
        default:
            break;
    }

    return MMI_RET_OK;
}


#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_insert_bookmark
 * DESCRIPTION
 *  Entry the bookmark list to select an inserted bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_ed_opt_insert_bookmark(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID boolmark_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    boolmark_gid = cui_bkm_sel_bkm_create(group_id);
    if (boolmark_gid != GRP_ID_INVALID)
    {
        cui_bkm_sel_bkm_run(boolmark_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_select_bookmark_rsp
 * DESCRIPTION
 *  Select Bookmark Response Handler
 * PARAMETERS
 *  inMsg       [IN]    the response msg data     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_handle_select_bookmark_rsp(U8 *selected_utf8_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 chars_num;
    MMI_BOOL insert_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chars_num = mmi_chset_utf8_strlen((const kal_uint8 *)selected_utf8_url);

    if (chars_num > 0)
    {
        U8 *ucs2_buffer = OslMalloc((chars_num + 1) * ENCODING_LENGTH);

        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8 *)ucs2_buffer,
            (kal_int32)((chars_num + 1) * ENCODING_LENGTH),
            (kal_uint8 *) selected_utf8_url);

        insert_result = mmi_sms_insert_text_to_editor((S8*)ucs2_buffer);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_HANDLE_SELECT_BOOKMARK_RSP, insert_result);

        OslMfree(ucs2_buffer);

        if (!insert_result)
        {            
            mmi_sms_display_popup_ext(
                STR_NO_SPACE_TO_INSERT_OBJECT,
                MMI_EVENT_FAILURE);
        }
    }
}
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__  */


#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_set_toolbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_editor_set_toolbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 item_icon[MMI_SMS_EDITOR_FTE_TOOLBAR_NUM] = {NULL, NULL};
    PU8 item_disable_icon[MMI_SMS_EDITOR_FTE_TOOLBAR_NUM]= {NULL, NULL};
    PU8 hint_string[MMI_SMS_EDITOR_FTE_TOOLBAR_NUM]= {NULL, NULL};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE);
    item_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_ADD_CONTACT);/* add recipient */
    item_disable_icon[0] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED);
    item_disable_icon[1] = get_image(IMG_GLOBAL_TOOLBAR_ADD_CONTACT_DISABLED);
    hint_string[0] = (U8 *)GetString(STR_GLOBAL_SEND);
    hint_string[1] = (U8 *)GetString(STR_ID_SMS_ADD_RECIPIENT); 
    
    wgui_icon_bar_setup(MMI_SMS_EDITOR_FTE_TOOLBAR_NUM, 
        item_icon, 
        item_disable_icon, 
        hint_string, 
        (GUIIconbarItemCallback)mmi_sms_editor_set_toolbar_callback);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_set_toolbar_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_editor_set_toolbar_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        mmi_sms_ed_pre_send();
    #else
        mmi_sms_send_sms();
     #endif
    }
    else
    {
    #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
        mmi_sms_editor_add_recipient();
    #else
        mmi_sms_ed_opt_send_to();
    #endif
    }  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_viewer_update_toolbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_editor_update_toolbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_icon_bar_set_item_enable_state(0, mmi_sms_is_send_enable());
   // wgui_icon_bar_set_item_enable_state(1, mmi_sms_is_send_enable());
}


#endif /* __MMI_ICON_BAR_SUPPORT__ */

#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_recipient_validy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_set_recipient_validy(U16 index, MMI_BOOL is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < MMI_SMS_MAX_RECIPIENTS_NUM)
    {
        g_sms_recip_data.sms_recipient[index].is_valid = is_valid;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_recipient_validy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sms_get_recipient_validy(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < MMI_SMS_MAX_RECIPIENTS_NUM);
    return g_sms_recip_data.sms_recipient[index].is_valid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_recipient_edit_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_set_recipient_edit_flag(U16 index, U16 editor_flags, MMI_BOOL is_set_cat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < MMI_SMS_MAX_RECIPIENTS_NUM)
    {
        g_sms_recip_data.sms_recipient[index].editor_flags= editor_flags;
        if (is_set_cat)
        {
            U16 name[MMI_SMS_MAX_NUM_LEN + 2];
            
            mmi_sms_get_recipient_name(index, name);
            wgui_cat28_set_phb_recipient(index, editor_flags, (UI_buffer_type)name);
        }
    }
    if (editor_flags == WGUI_CAT28_HIGHLIGHT_RECIPIENT)
    {
        g_sms_recip_data.is_invalid = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_recipient_edit_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_sms_get_recipient_edit_flag(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < MMI_SMS_MAX_RECIPIENTS_NUM);
    return g_sms_recip_data.sms_recipient[index].editor_flags;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_highlight_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_set_highlight_region(U8 highlight_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_recip_data.highlight_state = highlight_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_init_recipient_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_init_recipient_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_sms_recip_data.sms_recipient, 0, sizeof(mmi_sms_recipient_crtl_struct));
    for (i = 0; i < CUI_SMS_MAX_RECIPIENTS_NUM; i++)
    {
        g_sms_recip_data.sms_recipient[i].input_buf = mmi_sms_get_recipient_name_buffer(i);    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_highlight_callbacl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_editor_highlight_callback(S32 pre_hilite_index, S32 cur_hilite_index, MMI_BOOL is_pre_text_changed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_pre_text_changed)
    {
        mmi_sms_set_recipient_number_flag(pre_hilite_index);
        g_sms_recip_data.sms_recipient[pre_hilite_index].editor_flags = WGUI_CAT28_DEFAULT_FLAGS;
    } 
    wgui_cat28_register_recipient_change_callback(mmi_sms_editor_change_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_add_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_editor_add_callback(S32 recipient_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   mmi_sms_adjust_recipient_number(recipient_index);
   mmi_sms_set_is_recipient_modify(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_remove_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_editor_remove_callback(S32 recipient_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_delete_recipient_number(recipient_index);	
    mmi_sms_set_is_recipient_modify(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_change_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_editor_change_callback(S32 recipient_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((U32)recipient_index < CUI_SMS_MAX_RECIPIENTS_NUM)
    {
        mmi_sms_set_recipient_number_flag(recipient_index);
        wgui_cat28_register_recipient_change_callback(NULL);
        mmi_sms_set_is_recipient_modify(MMI_TRUE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_ricipient_proc
 * DESCRIPTION
 *  check the validy of ricipient from Phb cui
 * PARAMETERS
 *  evt        [IN]    event from phonebook
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sms_select_ricipient_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_GENERIC_MULTI_SELECT__
    cui_phb_multi_select_contact_result_struct *multi_select_result;
#endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */
    cui_phb_select_contact_result_struct *select_result;
    U16 invalid_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    { 
#ifndef __MMI_MAINLCD_96X64__    
    #ifdef __MMI_PHB_GENERIC_MULTI_SELECT__
        case EVT_ID_PHB_SELECT_MULTI_CONTACT:
            multi_select_result = (cui_phb_multi_select_contact_result_struct*) evt;
            invalid_count = mmi_sms_add_phb_number_to_recipient(
                multi_select_result->count,
                multi_select_result->store_index,
                multi_select_result->field);

            if (invalid_count > 0)
            {
                mmi_sms_display_popup_ext(
                    STR_ID_SMS_INVLAID_NUMBERS_REMOVED,
                    MMI_EVENT_INFO);            
            }
            cui_phb_list_group_select_contact_close(g_sms_recip_data.select_phb_cui_id);
            break;

        case EVT_ID_PHB_SELECT_MULTI_CONTACT_CANCEL:
            cui_phb_list_group_select_contact_close(g_sms_recip_data.select_phb_cui_id);
            break;
    #endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */
#endif
#ifndef __MMI_BT_PBAP_CLIENT__
        case EVT_ID_PHB_SELECT_CONTACT:
            {
                select_result = (cui_phb_select_contact_result_struct*) evt;

                if (srv_sms_check_ucs2_number((S8 *)select_result->select_data) == MMI_FALSE)
                {
                    mmi_sms_display_popup_ext(
                        STR_ID_SMS_INVLAID_NUMBERS_REMOVED,
                        MMI_EVENT_INFO); 
                }
                else
                {
                    mmi_sms_add_recipient_to_category(
                    (S8*)select_result->name,
                    (S8*)select_result->select_data);
                }
                cui_phb_list_select_contact_close(g_sms_recip_data.select_phb_cui_id);
            }
            break;
        
        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
            cui_phb_list_select_contact_close(g_sms_recip_data.select_phb_cui_id);
            break;
#else
        case EVT_ID_PHB_PBAPC_SEL_CONTACT:
            {
                cui_phb_pbapc_select_contact_rsp_struct* select_result = (cui_phb_pbapc_select_contact_rsp_struct*) evt;            
                if (MMI_PHB_PBAPC_SEL_REQ_CLOSE == select_result->rsp_type)
                    cui_phb_pbapc_select_contact_close(select_result->sender_id);
                else
                {
                    cui_phb_pbapc_select_contact_ret_struct* select_ret_result = (cui_phb_pbapc_select_contact_ret_struct*)select_result->rsp;
                    if (MMI_PHB_PBAPC_SEL_RET_OK == select_ret_result->ret)
                    {
                        if (srv_sms_check_ucs2_number((S8 *)select_ret_result->number) == MMI_FALSE)
                        {
                            mmi_sms_display_popup_ext(
                                STR_ID_SMS_INVLAID_NUMBERS_REMOVED,
                                MMI_EVENT_INFO); 
                        }
                        else
                        {
                            mmi_sms_add_recipient_to_category(
                            (S8*)select_ret_result->name,
                            (S8*)select_ret_result->number);
                        }
                    }
                }
            }
#endif

        default:
            break;
    }
 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_editor_add_recipient
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_editor_add_recipient(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num = mmi_sms_get_recipient_num();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num == CUI_SMS_MAX_RECIPIENTS_NUM)
    {
        mmi_popup_display_simple_ext(
            STR_ID_SMS_RECIPIENTS_FULL,
            MMI_EVENT_FAILURE,
            g_sms_gid,
            NULL);
    }
    else
    {
        U32 filter_type;
    #ifdef __MMI_PHB_GENERIC_MULTI_SELECT__
        U16 remaining_num;
    #endif
    MMI_ID phb_gid;

        filter_type = SRV_PHB_ENTRY_FIELD_NUMBER;
        phb_gid = mmi_frm_group_create_ex(
                    g_sms_gid,
                    GRP_ID_AUTO_GEN,
                    mmi_sms_select_ricipient_proc,
                    NULL,
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

#ifndef __MMI_MAINLCD_96X64__    
#ifndef __MMI_BT_PBAP_CLIENT__
    #ifdef __MMI_PHB_GENERIC_MULTI_SELECT__
        g_sms_recip_data.select_phb_cui_id = cui_phb_list_group_select_contact_create(phb_gid);
        if (g_sms_recip_data.select_phb_cui_id != GRP_ID_INVALID)
        {
            remaining_num = CUI_SMS_MAX_RECIPIENTS_NUM - num;
            cui_phb_list_select_contact_set_count(g_sms_recip_data.select_phb_cui_id, remaining_num);
            cui_phb_list_select_contact_set_field_filter(g_sms_recip_data.select_phb_cui_id, filter_type);
            cui_phb_list_group_select_contact_run(g_sms_recip_data.select_phb_cui_id);
        }
    #else /* __MMI_PHB_GENERIC_MULTI_SELECT__ */
        g_sms_recip_data.select_phb_cui_id = cui_phb_list_select_contact_create(phb_gid);
        if (g_sms_recip_data.select_phb_cui_id != GRP_ID_INVALID)
        {
            cui_phb_list_select_contact_set_field_filter(g_sms_recip_data.select_phb_cui_id, filter_type);
            cui_phb_list_select_contact_run(g_sms_recip_data.select_phb_cui_id);
        }
    #endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */
#else /* __MMI_BT_PBAP_CLIENT__ */
        g_sms_recip_data.select_phb_cui_id = cui_phb_pbapc_select_contact_create(phb_gid);
        if (g_sms_recip_data.select_phb_cui_id != GRP_ID_INVALID)
        {
            cui_phb_pbapc_select_contact_run(g_sms_recip_data.select_phb_cui_id);
        }
#endif
#else
g_sms_recip_data.select_phb_cui_id = cui_phb_list_select_contact_create(phb_gid);
 if (g_sms_recip_data.select_phb_cui_id != GRP_ID_INVALID)
        {
            cui_phb_list_select_contact_set_field_filter(g_sms_recip_data.select_phb_cui_id, filter_type);
            cui_phb_list_select_contact_run(g_sms_recip_data.select_phb_cui_id);
        }
#endif
    }
}

extern void mmi_phb_mark_several_for_msg_get_number(U8 *dest, U8 max_dest_len, U16 PhbIndex, U8 num_type);
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_add_phb_number_to_recipient
 * DESCRIPTION
 *  Get Number from Phonebook
 * PARAMETERS
 *  count       [IN]    total number
 *  phb_index   [IN]    Phonebook number entry index
 *  num_type    [IN]    number type
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_sms_add_phb_number_to_recipient(U16 count, U16 *phb_index, U8 *num_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 phb_numer[(MMI_PHB_EMAIL_LENGTH + 2) * ENCODING_LENGTH];
    U16 i;
    U16 invalid_recipient_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (count > 0)
    {
        for (i = 0; i < count; i++)
        {
            {
                mmi_phb_mark_several_for_msg_get_number(
                    phb_numer,
                    MMI_PHB_NUMBER_LENGTH,
                    phb_index[i],
                    num_type[i]);
            }
            if (srv_sms_check_ucs2_number((S8 *)phb_numer) == MMI_FALSE)
            {
                invalid_recipient_num++;
            }
            else
            {
                mmi_sms_add_recipient_to_category(NULL, (S8*)phb_numer);
            }
        }
    }

    return invalid_recipient_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_add_recipient_to_category
 * DESCRIPTION
 *  Add Recipient to the Recipient List
 * PARAMETERS
 *  ucs2_addr       [IN]    UCS2 Address
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_sms_add_recipient_to_category(S8 *ucs2_name, S8 *ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR recipient_name[ CUI_SMS_MAX_ADDR_LEN + 2];
    MMI_BOOL ret = MMI_FALSE;
    U16 len;
    U16 num;
    U16 num_len = mmi_ucs2strlen(ucs2_addr);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (num_len > CUI_SMS_MAX_ADDR_LEN)
    {
        mmi_sms_display_popup_ext(
            STR_ID_SMS_INVLAID_NUMBERS_REMOVED,
            MMI_EVENT_INFO); 
        return  MMI_SMS_MAX_RECIPIENTS_NUM;
    }   

    if (ucs2_name == NULL || mmi_ucs2strlen(ucs2_name) == 0)
    {
        if (num_len != 0)
        {
            srv_phb_get_name_by_number((U16 *)ucs2_addr, (U16 *)recipient_name, CUI_SMS_MAX_ADDR_LEN);
            if (mmi_ucs2strlen((S8*)recipient_name) == 0)
            {
                mmi_ucs2cpy((S8*)recipient_name, (S8*)ucs2_addr);
                recipient_name[num_len++] = L';';
                recipient_name[num_len] = '\0';
                ret = wgui_cat28_add_new_recipient((UI_buffer_type)recipient_name, WGUI_CAT28_DEFAULT_FLAGS, MMI_TRUE);
            }
            else
            {
                mmi_ucs2cat((S8*)recipient_name, (S8*)L";");
                ret = wgui_cat28_add_new_recipient((UI_buffer_type)recipient_name, WGUI_CAT28_WRAPPING_DELETE_RECIPIENT, MMI_TRUE);
            }
        }
    }
    else
    {
        len = mmi_ucs2strlen(ucs2_name);
        
        if (len > CUI_SMS_MAX_ADDR_LEN)
        {
            len = CUI_SMS_MAX_ADDR_LEN;
        }
         mmi_ucs2cpy((S8*)recipient_name, ucs2_name);
        mmi_ucs2cat((S8*)recipient_name, (S8*)L";");
        ret = wgui_cat28_add_new_recipient((UI_buffer_type)recipient_name, WGUI_CAT28_WRAPPING_DELETE_RECIPIENT, MMI_TRUE);
    }
    g_sms_recip_data.highlight_state = WGUI_CAT28_RECIPIENTS;

    if (num_len && ret)
    {
         num = wgui_cat28_get_recipients_num();
         mmi_sms_add_recipient_number(num - 1, ucs2_addr);
    }
    
    return  ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_recipient_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  U16 the number of current edited recipient
 *****************************************************************************/
U16 mmi_sms_get_recipient_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num = 0;
    U16 i = 0;
    U16 len = 0;
    U16 token[2] = {0xff1b, 0x00};
    U16 total_num = wgui_cat28_get_recipients_num();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < CUI_SMS_MAX_RECIPIENTS_NUM)
    {
        if (g_sms_recip_data.sms_recipient[i].is_valid)
        {
            len = mmi_ucs2strlen(g_sms_recip_data.sms_recipient[i].input_buf);
            /* categegory design,  the number of recipient is more than 1 */
            if ((total_num > 1) && ((len == 0) || mmi_ucs2cmp((S8 *)g_sms_recip_data.sms_recipient[i].input_buf, (S8 *)L";") == 0
                || mmi_ucs2cmp((S8 *)g_sms_recip_data.sms_recipient[i].input_buf, (S8 *)token) == 0))
            {
                wgui_cat28_remove_recipient(i);
                total_num--;
            }
            else
            {
                if (len > 0)
                {
                    num++;
                }
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    
    return num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_ed_opt_check_ricipient
 * DESCRIPTION
 *  Entry Phonebook list for inserting a name into editor 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_check_ricipient(MMI_ID group_id, void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_recip_data.state = MMI_SMS_STATE_START;
    g_sms_recip_data.callback = f;
    mmi_sms_get_ricipient_number();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_ed_opt_check_ricipient
 * DESCRIPTION
 *  Entry Phonebook list for inserting a name into editor 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_get_ricipient_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_search_contact_struct search_data;
    U16 name[MMI_SMS_MAX_NUM_LEN + 2];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_sms_recip_data.state)
    {
        case MMI_SMS_STATE_START:
        {
        	g_sms_recip_data.total_num = mmi_sms_get_recipient_num(); 
        	g_sms_recip_data.curr_num = 0;
        	g_sms_recip_data.is_invalid = MMI_FALSE;
        	g_sms_recip_data.is_full = MMI_FALSE;
        	g_sms_recip_data.state = MMI_SMS_STATE_GET_DATA;
        }
        break;

        case MMI_SMS_STATE_GET_DATA:
        {
            if (g_sms_recip_data.is_invalid)
            {
                g_sms_recip_data.is_invalid = MMI_FALSE;
                mmi_sms_display_popup_ext(
                STR_ID_SMS_INVALID_RECIPIENT,
                MMI_EVENT_FAILURE);
                return;
            }
            else if (g_sms_recip_data.is_full)
            {
                g_sms_recip_data.is_full = MMI_FALSE;
                mmi_popup_display_simple_ext(
                    STR_ID_SMS_RECIPIENTS_FULL,
                    MMI_EVENT_FAILURE,
                    g_sms_gid,
                    NULL);
                    return;
            }
            else
            {
                g_sms_recip_data.curr_num = 0;
            }
        }
        break;

        case MMI_SMS_STATE_END:
        {
        	if (g_sms_recip_data.callback != NULL)
        	{
        		g_sms_recip_data.callback();
        	}
            mmi_frm_group_close(g_sms_recip_data.edit_id);
        	return;
        }
    }
    g_sms_recip_data.curr_index = mmi_sms_check_recipient_number(g_sms_recip_data.total_num);
    if (g_sms_recip_data.curr_index == g_sms_recip_data.total_num)
    {
        g_sms_recip_data.state = MMI_SMS_STATE_END;
        mmi_sms_get_ricipient_number();
        return;
    }
    g_sms_recip_data.edit_id = mmi_frm_group_create_ex(
                                    g_sms_gid,
                                    GRP_ID_AUTO_GEN,
                                    mmi_sms_check_ricipient_proc,
                                    NULL,
                                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

    search_data.search_field = CUI_PHB_SEARCH_CONTACT_NAME;
    search_data.search_style = CUI_PHB_SEARCH_CONTACT_CONTAIN;
    search_data.get_field = SRV_PHB_ENTRY_FIELD_GSM_NUM;
    mmi_ucs2cpy((S8 *)name, (S8 *)g_sms_recip_data.sms_recipient[g_sms_recip_data.curr_index].input_buf);
    
    search_data.search_data = name;
    search_data.length = mmi_ucs2strlen(g_sms_recip_data.sms_recipient[g_sms_recip_data.curr_index].input_buf);
    /* check ';', english and chinese type(0xff1b) */
    if (search_data.length > 0 && (name[search_data.length - 1] == L';'|| name[search_data.length - 1] == 0xff1b ))
    {
        name[search_data.length - 1] = L'\0';
        search_data.length--;
    }
    g_sms_recip_data.search_phb_cui_id = cui_phb_search_contact_create(g_sms_recip_data.edit_id, &search_data); 
    if (g_sms_recip_data.search_phb_cui_id != GRP_ID_INVALID)
    { 
        cui_phb_search_contact_pre_run(g_sms_recip_data.search_phb_cui_id);
    }
    else
    {
         mmi_frm_group_close(g_sms_recip_data.search_phb_cui_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_ricipient_proc
 * DESCRIPTION
 *  check the validy of ricipient from Phb cui
 * PARAMETERS
 *  evt        [IN]    event from phonebook
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sms_check_ricipient_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_search_contact_result_struct* data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_INACTIVE:
            if (!mmi_frm_scrn_get_count(g_sms_recip_data.edit_id))
            {
                mmi_frm_group_close(g_sms_recip_data.edit_id);
            }
            break;

        case EVT_ID_PHB_SEARCH_CONTACT_PRE_RUN:
            {
                data = (cui_phb_search_contact_result_struct*)evt;

                if (data->num_count == 1 && data->count == 1)
                {
                    U16 recipient[MMI_PHB_NUMBER_LENGTH + 1];
                    
                    cui_phb_search_contact_get_data(
                        g_sms_recip_data.search_phb_cui_id,
                        data->id,
                        data->field_type,
                        recipient,
                        MMI_PHB_NUMBER_LENGTH,
                        MMI_FALSE
                        );
                    if (mmi_sms_update_recipient_name_number(g_sms_recip_data.curr_index, (S8 *)recipient, 0) == MMI_FALSE
                        && !g_sms_recip_data.is_invalid)
                    {
                        g_sms_recip_data.is_full = MMI_TRUE;
                    }
                    cui_pbh_search_contact_close(data->sender_id); 
                    mmi_sms_get_ricipient_number();
                }
                else if (data->count > 1 || data->num_count > 1)
                {
                    cui_phb_search_contact_run(g_sms_recip_data.search_phb_cui_id);                    
                }
                else
                {
                    mmi_sms_set_recipient_edit_flag(g_sms_recip_data.curr_index, WGUI_CAT28_HIGHLIGHT_RECIPIENT, MMI_TRUE);
                    cui_pbh_search_contact_close(data->sender_id);                    
                    mmi_sms_get_ricipient_number();
                }
            } 
            break;

        case EVT_ID_PHB_SEARCH_CONTACT:
            {                                
                U16 recipient[MMI_PHB_NUMBER_LENGTH + 1];
                MMI_BOOL more = MMI_TRUE;
                MMI_BOOL is_stop = MMI_FALSE;
                

                data = (cui_phb_search_contact_result_struct*)evt; 

                if (data->count == 0 && data->num_count == 0)
                {
                     cui_pbh_search_contact_close(data->sender_id);
                     break;
                }
                
                /*  need to revise */
                if (data->count == 0 || (g_sms_recip_data.curr_index + g_sms_recip_data.curr_num) >= CUI_SMS_MAX_RECIPIENTS_NUM)
                {
                    more = MMI_FALSE;
                }

                if (data->num_count)
                {
                    cui_phb_search_contact_get_data(
                        g_sms_recip_data.search_phb_cui_id,
                        data->id,
                        data->field_type,
                        recipient,
                        MMI_PHB_NUMBER_LENGTH,
                        more
                        );
                    if ( mmi_sms_update_recipient_name_number(g_sms_recip_data.curr_index, (S8 *)recipient, g_sms_recip_data.curr_num) == MMI_TRUE)
                    {
                        g_sms_recip_data.curr_num++;
                    }
                    /* if find the invalid number, stop current hanlde and pop up: invalid recipient */
                    else
                    {
                        is_stop = MMI_TRUE;
                        if (g_sms_recip_data.curr_num  > 1)
                        {
                            g_sms_recip_data.curr_index += g_sms_recip_data.curr_num - 1;
                            g_sms_recip_data.total_num += g_sms_recip_data.curr_num - 1;
                        }
                        if (!g_sms_recip_data.is_invalid)
                        {
                            g_sms_recip_data.is_full = MMI_TRUE;
                        }
                        g_sms_recip_data.curr_num = 0;
                    }
                }

                /*  need to revise */
                if (more == MMI_FALSE || is_stop)
                {
                    cui_pbh_search_contact_close(data->sender_id);
                    mmi_sms_get_ricipient_number();
                }               
            }
            break;
            
        case EVT_ID_PHB_SEARCH_CONTACT_CANCEL:
            {
                data = (cui_phb_search_contact_result_struct*)evt; 

                cui_pbh_search_contact_close(data->sender_id);
            }
            break;

        case EVT_ID_PHB_SEARCH_CONTACT_QUIT_BY_END_KEY:
            {
                data = (cui_phb_search_contact_result_struct*)evt; 
                cui_pbh_search_contact_close(data->sender_id);
            }
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_ed_pre_send
 * DESCRIPTION
 *  The Editor CSK Handler Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_ed_pre_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_check_ricipient(g_sms_gid, mmi_sms_ed_send);
}

#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */

