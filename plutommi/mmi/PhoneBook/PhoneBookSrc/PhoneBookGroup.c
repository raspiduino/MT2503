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
 *  PhoneBookGroup.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Implementation of feature "Group" in the Phobebook Application
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef PHONEBOOKGROUP_C
#define PHONEBOOKGROUP_C
#include "MMI_features.h"

#ifdef __MMI_PHB_CALLER_GROUP__

#include "PhoneBookAppMem.h"
#include "MMIDataType.h"
#include "CommonScreens.h"
#include "PhonebookResDef.h"
#include "PhoneBookTypes.h"
#include "PhoneBookProt.h"
#include "PhbSrvGprot.h"
#include "PhbCuiGprot.h"
#include "MenuCuiGprot.h"
#include "InlineCuiGprot.h"
#include "mmi_frm_scenario_gprot.h"

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UcAppGProt.h"
#endif /* __MMI_UNIFIED_COMPOSER__ */
#include "SmsSrvGprot.h"
#include "SmsAppGProt.h"
#include "MessagesMiscell.h"

#if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
#include "CameraCuiGprot.h"
#endif

#include "custom_phb_config.h"
#include "kal_general_types.h"
#include "PhoneBookCore.h"
#include "mmi_rp_app_phonebook_def.h"
#include "GlobalResDef.h"
#include "FileMgrCuiGProt.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "ps_public_enum.h"
#include "gui_typedef.h"
#include "gui_data_types.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "wgui_categories_text_viewer.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "MMI_common_app_trc.h"
#include "PhoneBookGprot.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "custom_wap_config.h"
#include "mmi_rp_app_sms_def.h"
#include "UcSrvGprot.h"
#include "customer_email_num.h"
#include "wgui_touch_screen.h"
#include "wgui_categories.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_include.h"
#include "mms_api.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "mms_adp_struct.h"
#include "mma_api.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mms_adp.h"
#include "SimCtrlSrvGprot.h"
#if defined(__MMI_IMAGE_CLIP_CUI__) && defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
#include "ImageClipCuiGprot.h"
#endif

/*
 * Define
 */
typedef enum
{
    MMI_PHB_GRP_OP_NONE,                     /* No operation */
    MMI_PHB_GRP_OP_ADD,                      /* add group */
    MMI_PHB_GRP_OP_REMOVE,               /* remove one group */
    MMI_PHB_GRP_OP_REMOVE_ALL,           /* remove all group */
    MMI_PHB_GRP_OP_TOTAL_TOTAL           /* enmu total */
} mmi_phb_group_op_enum;

typedef struct
{
    S32 hilite_index;
    U8 group_id_list[MMI_PHB_GROUP_COUNT + MMI_PHB_MAX_GAS_COUNT * MMI_MAX_SIM_NUM + MMI_PHB_GROUP_TCARD_COUNT];
 #ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__ 
    U8 *group_array;
 #endif
    U16 group_count;
    MMI_BOOL refresh;
    S32 refresh_id;
} mmi_phb_group_list_struct;

typedef struct
{
    S32 hilite_index;
    U16 origin_store_index;
    U16 *member_list;
    U16 member_count;
    MMI_BOOL refresh;
    U16 active_store_index;
    U16 active_index;
    U16 *address_type;
    U16 address_buffer[100];
    mmi_phb_group_member_op_enum memeber_op;
    U8 dest_group_id;
} mmi_phb_group_member_struct;

typedef struct
{
    srv_phb_group_info_struct group_info;
#ifndef __MMI_PHB_UI_IN_TABS__
    mmi_phb_group_list_struct main_list;
#endif
    mmi_phb_group_member_struct member;
    mmi_phb_caller_res_struct group_res;
    mmi_id inline_id;
    U16 inline_item_id;
    MMI_BOOL add_new;
    phb_storage_enum storage; /*group manager change*/
} mmi_phb_group_cntx_struct;

/*
 * Local Variable
 */
#ifdef __MMI_PHB_UI_IN_TABS__
static mmi_phb_group_list_struct g_mmi_phb_group_list_tab;
#endif

/*
 * Extern Variable
 */

#ifndef __MMI_MAINLCD_96X64__
extern MMI_BOOL is_from_group_add_member;
#endif

extern mmi_phb_confirm_user_data_struct g_mmi_phb_confirm_user_data;

/*
 * Local Function
 */
static mmi_ret mmi_phb_caller_group_proc(mmi_event_struct *evt);
static mmi_ret mmi_phb_entry_group_option_proc(mmi_event_struct *evt);
static mmi_ret mmi_phb_entry_group_editor_proc(mmi_event_struct *evt);
static mmi_ret mmi_phb_entry_group_editor_option_proc(mmi_event_struct *evt);
static mmi_ret mmi_phb_entry_group_member_list_option_proc(mmi_event_struct *evt);
static mmi_ret mmi_phb_entry_group_choose_storage_add_proc(mmi_event_struct *evt);

static void mmi_phb_entry_caller_group(void);
static void mmi_phb_entry_group_list(void);
static void mmi_phb_entry_group_unavailable(void);

static void mmi_phb_entry_group_option(void);
static void mmi_phb_entry_group_editor_option(void);
static phb_storage_enum mmi_phb_entry_get_group_storage(void);
static void mmi_phb_entry_add_group(void);
static void mmi_phb_entry_edit_group(void);

static void mmi_phb_entry_delete_group_confirm(void);
static void mmi_phb_entry_delete_all_group_confirm(void);

static void mmi_phb_save_group(void);
static void mmi_phb_delete_group(void);
static void mmi_phb_delete_all_group(void);

static void mmi_phb_entry_group_view_member(void);
static void mmi_phb_entry_group_member_list(void);

static void mmi_phb_entry_group_member_list_option(void);
static void mmi_phb_entry_group_member_list_option_view(void);
#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
static void mmi_phb_entry_ms_member_cb(S32 result, void* user_data);
static void mmi_phb_group_member_list_option_ms_remove(void);
static void mmi_phb_entry_group_member_list_option_ms_add(void);
#ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__
static void mmi_phb_entry_group_member_list_option_ms_move(void);
#endif
#else
static void mmi_phb_entry_member_cb(S32 result, void* user_data);
static void mmi_phb_group_member_list_option_remove(mmi_phb_group_member_op_enum op);
static void mmi_phb_group_member_list_option_remove_all(void);
static void mmi_phb_entry_group_member_list_option_add(void);
#endif
#ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__
static void mmi_phb_group_member_list_option_move(void);
#endif

#ifdef __MMI_UNIFIED_COMPOSER__
static void mmi_phb_pre_entry_group_send_uc(void);
static void mmi_phb_group_send_uc_choose_address(MMI_ID group_id);
static void mmi_phb_entry_group_send_uc_choose_address(void);
static void mmi_phb_group_send_uc_choose_address_more(void);
static void mmi_phb_entry_group_send_uc(void);
#else /* __MMI_UNIFIED_COMPOSER__ */
static void mmi_phb_pre_entry_group_send_sms(void);
static void mmi_phb_group_send_sms_choose_address(MMI_ID group_id);
static void mmi_phb_entry_group_send_sms_choose_address(void);
static void mmi_phb_group_send_sms_choose_address_more(void);
static void mmi_phb_entry_group_send_sms(MMI_ID group_id);
#if defined(__MMI_MMS__) && defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__)
static void mmi_phb_pre_entry_group_send_mms(void);
static void mmi_phb_group_send_mms_choose_address(MMI_ID group_id);
static void mmi_phb_entry_group_send_mms_choose_address(void);
static void mmi_phb_group_send_mms_choose_address_more(void);
static void mmi_phb_group_send_mms_req(void);
static void mmi_phb_group_send_mms_rsp(void *info);
static void mmi_phb_group_send_mms_insert_more_ind(U32 req_id);
static void mmi_phb_group_send_mms_prepare_buffer(U16 start_index, U16 end_index, void *buffer);
#endif /* defined(__MMI_MMS__) && defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__) */
#endif /* __MMI_UNIFIED_COMPOSER__ */

#define MMI_PHB_CALLER_GROUP
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_group_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_caller_group_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data =
        (mmi_phb_group_cntx_struct*) mmi_phb_mem_malloc(sizeof(mmi_phb_group_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data->member.member_list = NULL;
    group_data->member.address_type = NULL;
    group_data->storage = PHB_STORAGE_NVRAM;

    mmi_frm_group_create_ex(
        GRP_ID_PHB_MAIN,
        GRP_ID_PHB_GROUP,
        mmi_phb_caller_group_proc,
        (void*)group_data,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_phb_caller_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    U16 menu_id = (U16) (U32) menu_evt->app_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_RES__
#ifdef __MMI_PHB_CALLER_VIDEO__
    if (MMI_RET_OK == mmi_phb_video_audio_menu_cui_proc(evt))
    {
        return MMI_RET_OK;
    }
#endif /* __MMI_PHB_CALLER_VIDEO__ */
#endif /* __MMI_PHB_CALLER_RES__ */

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            switch(menu_id)
            {
                case MENU_ID_PHB_CALLER_GROUPS_OP:
                    mmi_phb_entry_group_option_proc(evt);
                    break;

                case MENU_ID_PHB_CALLERGROUP_MEMBER_VIEW_OPTION:
                    mmi_phb_entry_group_editor_option_proc(evt);
                    break;

                case MENU_ID_PHB_CALLER_GROUPS_MEMBERS_LIST_OP:
                    mmi_phb_entry_group_member_list_option_proc(evt);
                    break;

                case MITEM102_PBOOK_NEW_ENTRY:
                    mmi_phb_entry_group_choose_storage_add_proc(evt);
                    break;

                default:
                    break;
            }
            break;

        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_ABORT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_NOTIFY:
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
            mmi_phb_entry_group_editor_proc(evt);
            break;

        case EVT_ID_GROUP_DEINIT:
            if (group_data->member.member_list)
            {
                mmi_phb_mem_free(group_data->member.member_list);
                group_data->member.member_list = NULL;
            }
            mmi_phb_mem_free(group_data);
            break;

        case EVT_ID_GROUP_ACTIVE:
            if (mmi_frm_is_in_backward_scenario() && mmi_frm_scrn_get_count(GRP_ID_PHB_GROUP) == 0)
            {
                mmi_frm_group_close(GRP_ID_PHB_GROUP);
            }
            break;

        case EVT_ID_GROUP_INACTIVE:
        #ifdef __MMI_PHB_CALLER_RES__
            mmi_phb_stop_ring_tone_id();
        #endif
            break;

	#ifndef __MMI_PHB_GENERIC_MULTI_SELECT__
        case EVT_ID_PHB_SELECT_CONTACT:
            {
                cui_phb_select_contact_result_struct *select_result = (cui_phb_select_contact_result_struct*) evt;
            
            #ifndef __MMI_PHB_UI_IN_TABS__
                U8 caller_group_id = group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1];
            #else
                U8 caller_group_id = g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1];
            #endif
                srv_phb_group_add_members_req add_member_req;
                mmi_phb_group_member_data_struct *member_data;
                 
                member_data = (mmi_phb_group_member_data_struct*)mmi_phb_mem_malloc(
                    sizeof(mmi_phb_group_member_data_struct), 
                    SRV_PHB_MEMORY_TYPE_CTR);
                member_data->op = MMI_PHB_GRP_MEM_OP_ADD;
                member_data->finished = MMI_FALSE;
                        
                add_member_req.id_array = &select_result->store_index;
                add_member_req.entry_count = 1;
                add_member_req.group_id = caller_group_id;
                add_member_req.cb = mmi_phb_entry_member_cb;
                add_member_req.is_reset = MMI_FALSE;
                add_member_req.user_data = member_data;
                srv_phb_add_group_members(&add_member_req);

                group_data->member.refresh = MMI_TRUE;
                group_data->member.active_store_index = select_result->store_index;
            }
            break;

        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
            {
                cui_phb_select_contact_result_struct *select_result = (cui_phb_select_contact_result_struct*) evt;

                cui_phb_list_select_contact_close(select_result->sender_id);
            }
            break;
	#endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */

    #ifdef __MMI_PHB_CALLER_RES__
    #if defined(__MMI_FILE_MANAGER__)
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
            {
                cui_file_selector_result_event_struct *file_select = (cui_file_selector_result_event_struct*) evt;

                mmi_phb_fmgr_cui_res_handle(file_select);
            }
            break;

    #if defined(__MMI_IMAGE_CLIP_CUI__) && defined(__MMI_FILE_USEAS_SUPPORT__)
	#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
		case EVT_ID_CUI_IMAGE_CLIP_CLOSE_REQUEST:
		{
			cui_image_clip_close(((cui_image_clip_evt_struct*)evt)->sender_id);
			break;
		}

		case EVT_ID_CUI_IMAGE_CLIP_RESULT_SUCCESS:
		{
			cui_image_clip_evt_struct *clip_result = (cui_image_clip_evt_struct*)evt;
			mmi_phb_clip_image_finish(clip_result->save_file_path);
			break;
		}
	#endif
	#endif
            
    #if defined(__MMI_FILE_USEAS_SUPPORT__)
    #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
        case CUI_CAMERA_EVENT_RESULT_SUCCESS:
            mmi_phb_camera_cui_res_handle((WCHAR*)(((cui_camera_event_struct*)evt)->file_path));
        case CUI_CAMERA_EVENT_RESULT_FAILED:
        case CUI_CAMERA_EVENT_RESULT_CLOSE_ME:
            cui_camera_close(((cui_camera_event_struct*)evt)->sender_id);
            break;
    #endif /* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */
    #endif /* defined(__MMI_FILE_USEAS_SUPPORT__) */
    #endif /* defined(__MMI_FILE_MANAGER__) */
    #endif /* __MMI_PHB_CALLER_RES__ */

        case EVT_ID_ALERT_QUIT:
            {
                mmi_alert_result_evt_struct *alert_result = (mmi_alert_result_evt_struct*) evt;

                mmi_phb_confirm_display_handle(alert_result);
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fte_group_list_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tap_type        [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fte_group_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        if (index == 0)
        {
            mmi_phb_entry_add_group();
        }
        else
        {
            mmi_phb_entry_group_view_member();
        }
    }
}
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_caller_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_caller_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phb_storage_enum storage;
#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
    U32 field;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PHB_UI_IN_TABS__
    if (!mmi_frm_group_is_present(GRP_ID_PHB_GROUP))
    {
        mmi_phb_caller_group_create();
    }
#endif /* __MMI_PHB_UI_IN_TABS__ */
#ifndef __MMI_PHB_SLIM_NEW__
    storage = (phb_storage_enum)mmi_phb_get_preferred_storage();
#else
	storage = PHB_STORAGE_MAX;
#endif
    switch (storage)
    {
        case PHB_STORAGE_NVRAM:
        case PHB_STORAGE_MAX:
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        case PHB_STORAGE_TCARD:
    #endif
            mmi_phb_entry_group_list();
            break; 
            
    #ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
        case PHB_STORAGE_SIM:
        case PHB_STORAGE_SIM2:
        case PHB_STORAGE_SIM3:
        case PHB_STORAGE_SIM4:
            field = srv_phb_get_support_field(storage);
            if (field & MMI_PHB_CONTACT_FIELD_GROUP)
            {
                mmi_phb_entry_group_list();
            }
            else
            {
                mmi_phb_entry_group_unavailable();
            }
            break;
    #endif
    
        default:
            mmi_phb_entry_group_unavailable();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_list_seperate_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  flag        [?]         
 *  flag_ex     [?]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phb_group_list_seperate_line(S32 index, U32 *flag, U32 *flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        *flag |= UI_MENUITEM_DISABLE_ICON;
        *flag_ex |= UI_MENUITEM_EXT_SHOW_DOWN_SEPARATORLINE;
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_get_item_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  storage      [IN]                 
 * RETURNS
 *  U16
 *****************************************************************************/
void mmi_phb_group_get_item_image(phb_storage_enum storage, PU8* image_buffer1, PU8* image_buffer2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id1;
    U16 img_id2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PHB_STORAGE_NVRAM == storage)
    {   
        img_id1 = IMG_STORAGE_HANDSET;
    }
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    else if (PHB_STORAGE_TCARD == storage)
    {
        img_id1 = IMG_ID_PHB_TCARD_LIST;
    }
#endif
    else
    {
        img_id1 = IMG_STORAGE_SIM;
    }

    switch (storage)
    {
        case PHB_STORAGE_SIM:
            img_id2 = IMG_GLOBAL_SIM1;
            break;

    #if (MMI_MAX_SIM_NUM >= 2)
        case PHB_STORAGE_SIM2:
            img_id2 = IMG_GLOBAL_SIM2;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 3)
        case PHB_STORAGE_SIM3:
            img_id2 = IMG_GLOBAL_SIM3;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 4)
        case PHB_STORAGE_SIM4:
            img_id2 = IMG_GLOBAL_SIM4;
            break;
    #endif
    
        default:
            img_id2 = 0;
            break;
    }

    if (image_buffer1)
    {
        *image_buffer1 = get_image(img_id1);
    }

    if (image_buffer2)
    {
        if (0 == img_id2)
        {
           *image_buffer2 = NULL; 
        }
        else
        {
            *image_buffer2 = get_image(img_id2);
        }
    }
}


#ifndef __MMI_PHB_UI_IN_TABS__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
static S32 mmi_phb_group_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    S32 index;
    srv_phb_group_info_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < data_size; index++)
    {
        if (item_index + index == 0)
        {
            mmi_ucs2cpy((CHAR*) menu_data[0].item_list[0], GetString(STR_ID_PHB_ADD_NEW_GROUP));
            menu_data[0].image_list[0] = NULL;
        }
        else
        {
            if (!srv_phb_get_group_info( group_data->main_list.group_id_list[item_index + index - 1], &group_info))
            {
                mmi_wcsncpy(menu_data[index].item_list[0], group_info.group_name, MAX_SUBMENU_CHARACTERS);
                mmi_phb_group_get_item_image(group_info.storage, &menu_data[index].image_list[0], &menu_data[index].image_list[1]);
            }
            else
            {
                menu_data[index].item_list[0] = NULL;
                menu_data[index].image_list[0] = NULL;
            }
        }
    }
    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data->main_list.hilite_index = index;

    if (index == 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_entry_add_group, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_phb_entry_add_group, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_phb_entry_group_option, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_phb_entry_group_view_member, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    U32 i, group_count;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(GRP_ID_PHB_GROUP, SCR_CALLER_GROUPS, NULL, mmi_phb_entry_group_list, MMI_FRM_UNKNOW_SCRN);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

#if defined(__MMI_PHB_USIM_GROUP_SUPPORT__) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
#ifndef __MMI_PHB_SLIM_NEW__
    group_count = srv_phb_get_group_list(group_data->main_list.group_id_list, NULL, mmi_phb_get_preferred_storage());
#else
	group_count = srv_phb_get_group_list(group_data->main_list.group_id_list, NULL, PHB_STORAGE_NVRAM);
#endif
#else
    group_count = srv_phb_get_group_list(group_data->main_list.group_id_list, NULL, PHB_STORAGE_NVRAM);
#endif
    group_data->main_list.group_count = group_count;

    if (gui_buffer == NULL)
    {
        if (group_count > 0)
        {
            group_data->main_list.hilite_index = 1;
        }
        else
        {
            group_data->main_list.hilite_index = 0;
        }
    }
    else
    {
        if (group_data->main_list.refresh)
        {
            for (i = 0; i < group_count; i++)
            {
                if (group_data->main_list.group_id_list[i] == group_data->main_list.refresh_id)
                {
                    group_data->main_list.hilite_index = i + 1;
                    break;
                }
            }
            gui_buffer = NULL;
            group_data->main_list.refresh = MMI_FALSE;
        }
    }

    RegisterHighlightHandler(mmi_phb_group_list_highlight_hdlr);
    wgui_fixed_list_register_get_flags_handler(mmi_phb_group_list_seperate_line);

#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
    wgui_cat1032_show(
            (WCHAR*) GetString(STR_SCR_CALLER_GROUP_CAPTION),
            (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
            (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
            (PU8) GetImage(IMG_GLOBAL_OPTIONS),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            group_count + 1,
            mmi_phb_group_list_get_item,
            NULL,
            group_data->main_list.hilite_index,
            0,    
            IMG_GLOBAL_L1,
            IMG_STORAGE_SIM,
            gui_buffer,
            NULL);
#else
   wgui_cat1032_show(
            (WCHAR*) GetString(STR_SCR_CALLER_GROUP_CAPTION),
            (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
            (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
            (PU8) GetImage(IMG_GLOBAL_OPTIONS),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            group_count + 1,
            mmi_phb_group_list_get_item,
            NULL,
            group_data->main_list.hilite_index,
            0,    
            IMG_GLOBAL_L1,
            0,
            gui_buffer,
            NULL);
#endif


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_fte_group_list_tap_callback);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_unavailable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_unavailable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(
        GRP_ID_PHB_GROUP,
        SCR_ID_PHB_NO_GROUP,
        NULL,
        mmi_phb_entry_group_unavailable,
        MMI_FRM_UNKNOW_SCRN);

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory7Screen(
        STR_SCR_CALLER_GROUP_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) GetString(STR_ID_PHB_NO_GROUP_INFO),
        gui_buffer);
}


#else /* __MMI_PHB_UI_IN_TABS__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
static S32 mmi_phb_group_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_list_struct *group_list = &g_mmi_phb_group_list_tab;
    S32 index;
    srv_phb_group_info_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < data_size; index++)
    {
        if (item_index + index == 0)
        {
            mmi_ucs2cpy((CHAR*) menu_data[0].item_list[0], GetString(STR_ID_PHB_ADD_NEW_GROUP));
            menu_data[0].image_list[0] = NULL;
        }
        else
        {
            if (!srv_phb_get_group_info( group_list->group_id_list[item_index + index - 1], &group_info))
            {
                mmi_wcsncpy(menu_data[index].item_list[0], group_info.group_name, MAX_SUBMENU_CHARACTERS);
                mmi_phb_group_get_item_image(group_info.storage, &menu_data[index].image_list[0], &menu_data[index].image_list[1]);
            }
            else
            {
                menu_data[index].item_list[0] = NULL;
                menu_data[index].image_list[0] = NULL;
            }
        }
    }
    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_list_struct *group_list = &g_mmi_phb_group_list_tab;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_list->hilite_index = index;

    if (index == 0)
    {
      
#ifndef __MMI_WGUI_DISABLE_CSK__		            
#ifndef __MMI_MAINLCD_96X64__
        ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_ADD);
#else
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 	
#endif 	
        SetCenterSoftkeyFunction(mmi_phb_entry_add_group, KEY_EVENT_UP);
    }
    else
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_phb_entry_group_view_member, KEY_EVENT_UP);
    }

    SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_list_struct *group_list = &g_mmi_phb_group_list_tab;
    U32 i, group_count;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	cui_tab_enter(
			GRP_ID_PHB_MAIN,
			SCR_CALLER_GROUPS,
			NULL,
			mmi_phb_entry_caller_group,
			MMI_FRM_FULL_SCRN);
	#else
    mmi_frm_scrn_tab_page_enter(
        GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        SCR_CALLER_GROUPS,
        NULL,
        mmi_phb_entry_caller_group,
        MMI_FRM_TAB_PAGE);
	#endif

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!gui_buffer)
	   {
	   		gui_buffer = cui_tab_get_screen_gui_buf(SCR_PBOOK_MAIN_MENU,SCR_CALLER_GROUPS);
	   	}
   #endif

#if defined(__MMI_PHB_USIM_GROUP_SUPPORT__) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
    //group_count = srv_phb_get_group_list(group_list->group_id_list, NULL, (phb_storage_enum)mmi_phb_get_preferred_storage());
#ifndef __MMI_PHB_SLIM_NEW__
    group_count = srv_phb_get_group_list(group_list->group_id_list, NULL, (phb_storage_enum)mmi_phb_get_preferred_storage());
#else
	group_count = srv_phb_get_group_list(group_list->group_id_list, NULL, PHB_STORAGE_NVRAM);
#endif
#else
    group_count = srv_phb_get_group_list(group_list->group_id_list, NULL, PHB_STORAGE_NVRAM);
#endif
    group_list->group_count = group_count;

    if (gui_buffer == NULL)
    {
        if (group_count > 0)
        {
            group_list->hilite_index = 1;
        }
        else
        {
            group_list->hilite_index = 0;
        }
    }
    else
    {
        if (group_list->refresh)
        {
            for (i = 0; i < group_count; i++)
            {
                if (group_list->group_id_list[i] == group_list->refresh_id)
                {
                    group_list->hilite_index = i + 1;
                    break;
                }
            }
            gui_buffer = NULL;
            group_list->refresh = MMI_FALSE;
        }
    }

    RegisterHighlightHandler(mmi_phb_group_list_highlight_hdlr);
    wgui_fixed_list_register_get_flags_handler(mmi_phb_group_list_seperate_line);

#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
    wgui_cat1032_show(
            (WCHAR*) GetString(STR_SCR_CALLER_GROUP_CAPTION),
            (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
            (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
            (PU8) GetImage(IMG_GLOBAL_OPTIONS),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            group_count + 1,
            mmi_phb_group_list_get_item,
            NULL,
            group_list->hilite_index,
            1,    
            IMG_GLOBAL_L1,
            IMG_STORAGE_SIM,
            gui_buffer,
            NULL); 
#else
    wgui_cat1032_show(
            (WCHAR*) GetString(STR_SCR_CALLER_GROUP_CAPTION),
            (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
            (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
            (PU8) GetImage(IMG_GLOBAL_OPTIONS),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            group_count + 1,
            mmi_phb_group_list_get_item,
            NULL,
            group_list->hilite_index,
            1,    
            IMG_GLOBAL_L1,
            0,
            gui_buffer,
            NULL); 
#endif

#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif

    SetLeftSoftkeyFunction(mmi_phb_entry_group_option, KEY_EVENT_UP);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_fte_group_list_tap_callback);
#endif

    SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_unavailable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_unavailable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(
        GRP_ID_PHB_MAIN,
        SCR_CALLER_GROUPS,
        NULL,
        mmi_phb_entry_caller_group,
        MMI_FRM_TAB_PAGE);

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    wgui_cat3001_show(
        get_string(STR_SCR_CALLER_GROUP_CAPTION),
        0,
        0,
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        (S8)1,
        MMI_TRUE,
        (U8*) GetString(STR_ID_PHB_NO_GROUP_INFO),
        100,
        gui_buffer);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif

    SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_PHB_UI_IN_TABS__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_get_member_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_type        
 * RETURNS
 *  member count
 *****************************************************************************/
static U16 mmi_phb_group_get_member_count(U16 filter_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    srv_phb_filter_struct filter;
    srv_phb_group_filter_struct group_filter;
    S32 result;
	U8 group_id; 
	phb_storage_enum storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PHB_UI_IN_TABS__
    group_id = group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1];
#else
    group_id = g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1];
#endif
	storage = srv_phb_get_storage_by_group_id(group_id);

#if defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__) || defined (__MMI_PHB_USIM_GROUP_SUPPORT__)
    if (group_id >= MMI_PHB_GROUP_COUNT + MMI_PHB_GROUP_USIM_COUNT)
    {
        group_id -= MMI_PHB_GROUP_COUNT + MMI_PHB_GROUP_USIM_COUNT;
    }
#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
    else if (group_id >= MMI_PHB_GROUP_COUNT)
    {
        group_id = (group_id - MMI_PHB_GROUP_COUNT) % MMI_PHB_MAX_GAS_COUNT;
    }
#endif
#endif

	group_filter.group_mask = (U32)(1 << group_id);
    group_filter.is_equal = MMI_TRUE;

    filter.storage = storage;
    filter.field_filter = (U32)filter_type;
    filter.name_filter = NULL;
    filter.qsearch_filter = NULL;
    filter.group_filter = &group_filter;

    if (group_data->member.member_list == NULL)
    {
        group_data->member.member_list = mmi_phb_mem_malloc(MMI_PHB_PHONE_ENTRIES * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
    }

    result = srv_phb_oplib_build_contact_list(&filter, group_data->member.member_list, MMI_PHB_PHONE_ENTRIES);
    if (result < 0)
    {
        return 0;
    }

    return (U16) result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_option_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_phb_entry_group_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    MMI_ID sender_id = menu_evt->sender_id;
    U16 member_count;
    MMI_MENU_ID highlighted_menu_id = menu_evt->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (menu_evt->parent_menu_id == MENU_ID_PHB_CALLER_GROUPS_OP)
            {
                cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            }
        #ifndef __MMI_PHB_UI_IN_TABS__
            if (group_data->main_list.hilite_index == 0)
        #else
            if (g_mmi_phb_group_list_tab.hilite_index == 0)
        #endif
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_VIEW, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUP_ADD, MMI_FALSE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_DELETE, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_DELETEALL, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_SETTINGS, MMI_TRUE);

            #ifdef __MMI_UNIFIED_COMPOSER__
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_SEND_MESSAGE, MMI_TRUE);
            #else /* __MMI_UNIFIED_COMPOSER__ */
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_SEND_SMS, MMI_TRUE);
            #if defined(__MMI_MMS__) && defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__)
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_SEND_MMS, MMI_TRUE);
            #endif
            #endif /* __MMI_UNIFIED_COMPOSER__ */

            #ifdef __MMI_PHB_UI_IN_TABS__
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_SETTINGS, MMI_FALSE);
                cui_menu_set_non_leaf_item(sender_id, MENU_ID_PHB_SETTINGS, MMI_FALSE);
            #endif
            }
            else
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_VIEW, MMI_FALSE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUP_ADD, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_DELETE, MMI_FALSE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_DELETEALL, MMI_FALSE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_SETTINGS, MMI_FALSE);

                group_data->member.member_count = mmi_phb_group_get_member_count(0xFFFF);
                member_count = group_data->member.member_count;

            #ifdef __MMI_UNIFIED_COMPOSER__
                if (mmi_uc_is_uc_ready() && member_count)
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_SEND_MESSAGE, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_SEND_MESSAGE, MMI_TRUE);
                }
            #else /* __MMI_UNIFIED_COMPOSER__ */
                if (member_count)
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_SEND_SMS, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_SEND_SMS, MMI_TRUE);
                }
            #if defined(__MMI_MMS__) && defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__)
                if (mms_is_ready() && member_count)
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_SEND_MMS, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_CALLER_GROUPS_OP_SEND_MMS, MMI_TRUE);
                }
            #endif /* defined(__MMI_MMS__) && defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__) */
            #endif /* __MMI_UNIFIED_COMPOSER__ */

            #ifdef __MMI_PHB_UI_IN_TABS__
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_SETTINGS, MMI_FALSE);
                cui_menu_set_non_leaf_item(sender_id, MENU_ID_PHB_SETTINGS, MMI_FALSE);
            #endif
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(highlighted_menu_id)
            {
                case MENU_ID_PHB_CALLER_GROUPS_OP_VIEW:
                    mmi_phb_entry_group_view_member();
                    break;

                case MENU_ID_PHB_CALLER_GROUP_ADD:
                    mmi_phb_entry_add_group();
                    break;

                case MENU_ID_PHB_CALLER_GROUPS_OP_DELETE:
                    mmi_phb_entry_delete_group_confirm();
                    break;

                case  MENU_ID_PHB_CALLER_GROUPS_OP_DELETEALL:
                    mmi_phb_entry_delete_all_group_confirm();
                    break;

                case  MENU_ID_PHB_CALLER_GROUPS_OP_SETTINGS:
                    mmi_phb_entry_edit_group();
                    break;

            #ifdef __MMI_UNIFIED_COMPOSER__
                case  MENU_ID_PHB_CALLER_GROUPS_OP_SEND_MESSAGE:
                    mmi_phb_pre_entry_group_send_uc();
                    break;
            #else /* __MMI_UNIFIED_COMPOSER__ */
                case  MENU_ID_PHB_CALLER_GROUPS_OP_SEND_SMS:
                    mmi_phb_pre_entry_group_send_sms();
                    break;
            #if defined(__MMI_MMS__) && defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__)
                case  MENU_ID_PHB_CALLER_GROUPS_OP_SEND_MMS:
                    mmi_phb_pre_entry_group_send_mms();
                    break;
            #endif /* defined(__MMI_MMS__) && defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__) */
            #endif /* __MMI_UNIFIED_COMPOSER__ */
#ifndef __MMI_MAINLCD_96X64__
            #ifdef __MMI_PHB_UI_IN_TABS__
                case  MENU_ID_PHB_SETTINGS:
                    mmi_phb_sg_entry_setting(GRP_ID_PHB_GROUP);
                    break;
            #endif /* __MMI_PHB_UI_IN_TABS__ */
#endif

                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_group_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    if (!mmi_frm_group_is_present(GRP_ID_PHB_GROUP))
    {
        mmi_phb_caller_group_create();
    }
	
    mmi_phb_entry_menu_cui_generic(
        GRP_ID_PHB_GROUP,
        MENU_ID_PHB_CALLER_GROUPS_OP,
        0);
}


#define MMI_PHB_GROUP_EDITOR
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_editor_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inline_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_editor_get_item(mmi_id inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(inline_id, INLINE_ID_PHB_GROUP_NAME, group_data->group_info.group_name);
#ifdef __MMI_PHB_CALLER_RES__
#if !defined(LOW_COST_SUPPORT) || (defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)&&defined(__SRV_PHB_CALLER_RES_DATA_STORE__))
    cui_inline_get_value(inline_id, INLINE_ID_PHB_GROUP_PICTURE, &g_mmi_phb_res_p->selected_pic_index);
#endif
    cui_inline_get_value(inline_id, INLINE_ID_PHB_GROUP_RINGTONE, &g_mmi_phb_res_p->selected_ring_index);
#if defined(__MMI_PHB_CALLER_VIDEO__)
    cui_inline_get_value(inline_id, INLINE_ID_PHB_GROUP_VIDEO, &g_mmi_phb_res_p->selected_video_index);
#endif
#endif /* __MMI_PHB_CALLER_RES__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_editor_set_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inline_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_editor_set_item(mmi_id inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_set_value(inline_id, INLINE_ID_PHB_GROUP_NAME, group_data->group_info.group_name);

#ifdef __MMI_PHB_CALLER_RES__
#if !defined(LOW_COST_SUPPORT) || (defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)&&defined(__SRV_PHB_CALLER_RES_DATA_STORE__))
    cui_inline_set_item_select(
        inline_id,
        INLINE_ID_PHB_GROUP_PICTURE,
        g_mmi_phb_resource.total_image_id,
        g_mmi_phb_resource.image_name_list,
        (U8) group_data->group_res.selected_pic_index);
#endif
    cui_inline_set_item_select(
        inline_id,
        INLINE_ID_PHB_GROUP_RINGTONE,
        g_mmi_phb_resource.total_ring_tone,
        g_mmi_phb_resource.ring_tone_name_list,
        (U8) group_data->group_res.selected_ring_index);

#if defined(__MMI_PHB_CALLER_VIDEO__)
    cui_inline_set_item_select(
        inline_id,
        INLINE_ID_PHB_GROUP_VIDEO,
        g_mmi_phb_resource.total_video_id,
        g_mmi_phb_resource.video_name_list,
        (U8) group_data->group_res.selected_video_index);
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
#endif /* __MMI_PHB_CALLER_RES__ */

    cui_inline_set_title_string_with_string_id(
        inline_id,
        STR_ID_PHB_CALLER_GROUPS_OP_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_editor_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_phb_entry_group_editor_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
            {
                cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*) evt;
                mmi_phb_group_editor_get_item(submit_evt->sender_id);
                if (submit_evt->sofktey_type == MMI_CENTER_SOFTKEY)
                {
                    mmi_phb_save_group();
                }
                else
                {
                    mmi_phb_entry_group_editor_option();
                }
            }
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            {
                cui_event_inline_abort_struct *abort_evt = (cui_event_inline_abort_struct*) evt;
                cui_inline_close(abort_evt->sender_id);
            }
            break;

        case EVT_ID_CUI_INLINE_CSK_PRESS:
            {
                cui_event_inline_csk_press_struct *csk_press_evt = (cui_event_inline_csk_press_struct*) evt;
                mmi_phb_group_editor_get_item(csk_press_evt->sender_id);
                mmi_phb_save_group();
            }
            break;

        case EVT_ID_CUI_INLINE_NOTIFY:
            {
                cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*) evt;
                MMI_ID sender_id = notify_evt->sender_id;
                U16 item_id = notify_evt->item_id;

                if (notify_evt->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
                {
                #ifdef __MMI_PHB_CALLER_RES__
                    mmi_phb_stop_ring_tone_id();
                #endif

                    group_data->inline_item_id = item_id;

                    cui_inline_set_softkey_text(
                        sender_id, item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OPTIONS);
                    cui_inline_set_softkey_icon(
                        sender_id, item_id, MMI_CENTER_SOFTKEY, IMG_GLOBAL_SAVE_CSK);
                }
                else if (notify_evt->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
                {
                    mmi_phb_group_editor_get_item(sender_id);

                #ifdef __MMI_PHB_CALLER_RES__
                    if (item_id == INLINE_ID_PHB_GROUP_RINGTONE)
                    {
                        mmi_phb_ring_tone_highlight_hdlr(g_mmi_phb_res_p->selected_ring_index);
                    }
                #endif /* __MMI_PHB_CALLER_RES__ */
                }
            }
            break;

        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
            {
            #ifdef __MMI_PHB_CALLER_RES__
                mmi_phb_contact_res_config();

                cui_inline_set_item_select(
                    group_data->inline_id,
                    INLINE_ID_PHB_GROUP_RINGTONE,
                    g_mmi_phb_resource.total_ring_tone,
                    g_mmi_phb_resource.ring_tone_name_list,
                    (U8) g_mmi_phb_res_p->selected_ring_index);
            #if !defined(LOW_COST_SUPPORT) || (defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)&&defined(__SRV_PHB_CALLER_RES_DATA_STORE__))
                cui_inline_set_item_select(
                    group_data->inline_id,
                    INLINE_ID_PHB_GROUP_PICTURE,
                    g_mmi_phb_resource.total_image_id,
                    g_mmi_phb_resource.image_name_list,
                    (U8) g_mmi_phb_res_p->selected_pic_index);
            #endif
            #if defined(__MMI_PHB_CALLER_VIDEO__)
                cui_inline_set_item_select(
                    group_data->inline_id,
                    INLINE_ID_PHB_GROUP_VIDEO,
                    g_mmi_phb_resource.total_video_id,
                    g_mmi_phb_resource.video_name_list,
                    (U8) g_mmi_phb_res_p->selected_video_index);
            #endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
            #endif /* __MMI_PHB_CALLER_RES__ */
            }
            break;

        case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
        #ifdef __MMI_PHB_CALLER_RES__
            mmi_phb_stop_ring_tone_id();
        #endif
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_choose_storage
 * DESCRIPTION
 *  choose storage entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_group_choose_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;
#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
    U32 field;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_ENTRY_CHOOSE_STORAGE);
    menu_gid = cui_menu_create(
        GRP_ID_PHB_GROUP,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPSUB,
        MITEM102_PBOOK_NEW_ENTRY,
        MMI_FALSE, 
        (void*)MITEM102_PBOOK_NEW_ENTRY);

    cui_menu_set_default_title_string_by_id(menu_gid, STR_ID_PHB_ADD_NEW_GROUP);

#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
    field = srv_phb_get_support_field(PHB_STORAGE_SIM);
    if (!(field & MMI_PHB_CONTACT_FIELD_GROUP))
    {
        cui_menu_set_item_hidden(menu_gid, MITEM_ADD_ENTRY_TO_SIM, MMI_TRUE);  
    }

#if (MMI_MAX_SIM_NUM >= 2)
    field = srv_phb_get_support_field(PHB_STORAGE_SIM2);
    if (!(field & MMI_PHB_CONTACT_FIELD_GROUP))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_ADD_SIM2, MMI_TRUE);  
    }
#endif /* MMI_MAX_SIM_NUM >= 2 */

#if (MMI_MAX_SIM_NUM >= 3)
    field = srv_phb_get_support_field(PHB_STORAGE_SIM3);
    if (!(field & MMI_PHB_CONTACT_FIELD_GROUP))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_ADD_SIM3, MMI_TRUE);  
    }
#endif

#if (MMI_MAX_SIM_NUM >= 4)
    field = srv_phb_get_support_field(PHB_STORAGE_SIM4);
    if (!(field & MMI_PHB_CONTACT_FIELD_GROUP))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_ADD_SIM4, MMI_TRUE);  
    }
#endif

#else
    cui_menu_set_item_hidden(menu_gid, MITEM_ADD_ENTRY_TO_SIM, MMI_TRUE);
#if (MMI_MAX_SIM_NUM >= 2)
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_ADD_SIM2, MMI_TRUE);
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_ADD_SIM3, MMI_TRUE);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_ADD_SIM4, MMI_TRUE); 
#endif
#endif /*  __MMI_PHB_USIM_GROUP_SUPPORT__  */

    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);
    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_get_group_storage
 * DESCRIPTION
 *  group manager change
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static phb_storage_enum mmi_phb_entry_get_group_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    U8 group_id;
    srv_phb_group_info_struct group_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PHB_UI_IN_TABS__
    group_id = group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1];
#else
    group_id = g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1];
#endif
    srv_phb_get_group_info(group_id, &group_info);
    return group_info.storage;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_cb
 * DESCRIPTION
 *  group manager change
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_group_cb(S32 result, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data;
    mmi_phb_group_op_enum type = (mmi_phb_group_op_enum)(user_data);
    U16 group_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG2(TRC_MMI_PHB_GROUP_OP_CB, result, type);
    group_data = (mmi_phb_group_cntx_struct*)mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    switch (result)
    {
        case SRV_PHB_GROUP_NAME_EMPTY:
            mmi_phb_popup_display_ext(STR_ID_GROUP_NAME_EMPTY, MMI_EVENT_FAILURE);
            break;

        case SRV_PHB_GROUP_NAME_DUP:
            mmi_phb_popup_display_ext(STR_ID_GROUP_NAME_DUP, MMI_EVENT_FAILURE);
            break;

        case SRV_PHB_ERROR:
            mmi_phb_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);
            break;

        case SRV_PHB_GROUP_FULL:
            mmi_phb_popup_display_ext(STR_ID_PHB_GROUP_FULL, MMI_EVENT_FAILURE);
            break;
                
        case SRV_PHB_STORAGE_EMPTY:
            mmi_phb_popup_display_ext(STR_GLOBAL_DELETED, MMI_EVENT_FAILURE);
            break;

    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        case SRV_PHB_TCARD_NOT_AVAILABLE:
            mmi_phb_popup_display_ext(STR_ID_PHB_MEMORY_CARD_NOT_AVAILABLE, MMI_EVENT_FAILURE);
            cui_inline_close(group_data->inline_id);
            break;
    #endif
    
        default:
            if (MMI_PHB_GRP_OP_ADD == type)
            {
            #ifndef __MMI_PHB_UI_IN_TABS__
                group_data->main_list.refresh = MMI_TRUE;
                group_data->main_list.refresh_id = result;
            #else /* __MMI_PHB_UI_IN_TABS__ */
                g_mmi_phb_group_list_tab.refresh = MMI_TRUE;
                g_mmi_phb_group_list_tab.refresh_id = result;
            #endif /* __MMI_PHB_UI_IN_TABS__ */
                mmi_phb_popup_display_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS);
                cui_inline_close(group_data->inline_id);
            }
            else if (MMI_PHB_GRP_OP_REMOVE == type)
            {
                mmi_frm_scrn_close(GRP_ID_PHB_GROUP, SCR_IN_PROGRESS_PHB);
                mmi_phb_popup_display_ext(STR_GLOBAL_DELETED, MMI_EVENT_SUCCESS);
            }
            else if (MMI_PHB_GRP_OP_REMOVE_ALL == type)
            {
            #ifndef __MMI_PHB_UI_IN_TABS__
                group_count = --group_data->main_list.group_count;
                if (0 == group_count)
                {
                    mmi_frm_scrn_close(GRP_ID_PHB_GROUP, SCR_IN_PROGRESS_PHB);
                    mmi_phb_popup_display_ext(STR_GLOBAL_DELETED, MMI_EVENT_SUCCESS);
                }
                else
                {
                    srv_phb_delete_group(group_data->main_list.group_id_list[group_count - 1], 
                        mmi_phb_entry_group_cb, 
                        (void *)MMI_PHB_GRP_OP_REMOVE_ALL);
                }
            #else /* __MMI_PHB_UI_IN_TABS__ */
                group_count = --g_mmi_phb_group_list_tab.group_count;
                if (0 == group_count)
                {
                    mmi_frm_scrn_close(GRP_ID_PHB_GROUP, SCR_IN_PROGRESS_PHB);
                    mmi_phb_popup_display_ext(STR_GLOBAL_DELETED, MMI_EVENT_SUCCESS);
                }
                else
                {
                    srv_phb_delete_group(g_mmi_phb_group_list_tab.group_id_list[group_count - 1], 
                        mmi_phb_entry_group_cb, 
                        (void *)MMI_PHB_GRP_OP_REMOVE_ALL);
                }
            #endif /* __MMI_PHB_UI_IN_TABS__ */
            }
            break;
    }
}


#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__  
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_get_group_name_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_set_group_name_length(mmi_id inline_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_length;
    U8 edit_length;
    U32 input_type;
    S32 input_extended_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (PHB_STORAGE_NVRAM != storage)
    {
        input_type = IMM_INPUT_TYPE_SENTENCE |
            INPUT_TYPE_USE_ENCODING_BASED_LENGTH |
            INPUT_TYPE_ONE_LESS_CHARACTER |
            INPUT_TYPE_GSM_EXTENDED_HANDLING; 

    #if defined(__PHB_0x81_SUPPORT__)
        input_extended_type = INPUT_TYPE_EXT_USE_0x81_ENCODING | INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    #else
        input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    #endif
        cui_inline_set_input_method(inline_id, INLINE_ID_PHB_GROUP_NAME, input_type, NULL, input_extended_type);
    
        sim_length = srv_phb_startup_get_alpha_length((U8)(storage - PHB_STORAGE_SIM), PHB_GAS);
        edit_length = ((sim_length - MMI_PHB_GROUP_NAME_LENGTH) >= 0) ? MMI_PHB_GROUP_NAME_LENGTH : sim_length;
        cui_inline_set_text_len(inline_id, INLINE_ID_PHB_GROUP_NAME, edit_length + 1);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_add_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_edit_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data;
    mmi_id inline_id;
#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_caller_res_struct *group_res;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

#ifdef __MMI_PHB_CALLER_RES__
    g_mmi_phb_res_p = &group_data->group_res;
    group_res = &group_data->group_res;
    memset(group_data->group_info.group_name, 0, ENCODING_LENGTH);
    group_res->sg_id = GRP_ID_PHB_GROUP;
    group_res->curr_res_type = 0;
    group_res->ring_id = 0;
    *(group_res->ring_path) = 0;
    group_res->img_id = 0;
    *(group_res->img_path) = 0;
#if defined(__MMI_PHB_CALLER_VIDEO__)
    group_res->video_id = 0;
    *group_res->video_path = 0;
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
    mmi_phb_contact_build_res();
#endif /* __MMI_PHB_CALLER_RES__ */

    inline_id = cui_inline_create(GRP_ID_PHB_GROUP, mmi_phb_construct_group_editor(group_data->storage));
#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__   
    mmi_phb_entry_set_group_name_length(inline_id, group_data->storage);
#endif
    group_data->inline_id = inline_id;
    group_data->add_new = MMI_TRUE;
    cui_inline_set_title_string_with_string_id(
        inline_id,
        STR_ID_PHB_CALLER_GROUPS_OP_SETTINGS);
    cui_inline_run(inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_is_full
 * DESCRIPTION
 *  check if group count full
 * PARAMETERS
 *  storage
 * RETURNS
 *  true if full
 *****************************************************************************/
static MMI_BOOL mmi_phb_entry_group_is_full(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 group_count;
    U8 group_id_list[MMI_PHB_GROUP_TOTAL_COUNT];
    MMI_BOOL is_full = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_count = srv_phb_get_group_list(group_id_list, NULL, storage);
    if (PHB_STORAGE_NVRAM == storage)
    {
        if (MMI_PHB_GROUP_COUNT == group_count)
        {
            is_full = MMI_TRUE;
        }        
    }
    else if (PHB_STORAGE_MAX == storage)
    {
        if (MMI_PHB_GROUP_TOTAL_COUNT == group_count)
        {
            is_full = MMI_TRUE;     
        }
    }
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    else if (PHB_STORAGE_TCARD == storage)
    {
        if (MMI_PHB_GROUP_TCARD_COUNT == group_count)
        {
            is_full = MMI_TRUE;    
        }
    }
#endif
#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
    else
    {          
        if (group_count == srv_phb_get_usim_field_total(storage, 0, PHB_GAS))
        {
            is_full = MMI_TRUE;
        }
    }
#endif

    if (is_full)
    {
        mmi_phb_popup_display_ext(STR_ID_PHB_GROUP_FULL, MMI_EVENT_FAILURE);    
    }

    return is_full;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_add_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_add_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_USIM_GROUP_SUPPORT__) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
    mmi_phb_group_cntx_struct *group_data;
    phb_storage_enum storage;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_group_is_present(GRP_ID_PHB_GROUP))
    {
        mmi_phb_caller_group_create();
    }

#if defined(__MMI_PHB_USIM_GROUP_SUPPORT__) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)   
    group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    //storage = (phb_storage_enum)mmi_phb_get_preferred_storage();
#ifndef __MMI_PHB_SLIM_NEW__
		storage = (phb_storage_enum)mmi_phb_get_preferred_storage();
#else
		storage = PHB_STORAGE_MAX;
#endif
    if (PHB_STORAGE_MAX == storage)
    {
        /* go to choose storage srn*/
        if (!mmi_phb_entry_group_is_full(storage))
        {
            mmi_phb_entry_group_choose_storage();
        }
    }
    else
    {
        if (!mmi_phb_entry_group_is_full(storage))
        {
            group_data->storage = storage;
            mmi_phb_entry_group_edit_cui();
        }
    }
#else
    if (!mmi_phb_entry_group_is_full(PHB_STORAGE_NVRAM))
    {
        mmi_phb_entry_group_edit_cui();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_edit_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_edit_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    mmi_id inline_id;
#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_caller_res_struct *group_res;
    srv_phb_group_info_struct *group_info;
#endif
    phb_storage_enum storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_group_info(
    #ifndef __MMI_PHB_UI_IN_TABS__
        group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1],
    #else
        g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1],
    #endif
        (srv_phb_group_info_struct*) (&group_data->group_info));


#ifdef __MMI_PHB_CALLER_RES__
    g_mmi_phb_res_p = &group_data->group_res;

    group_res = &group_data->group_res;
    group_info = &(group_data->group_info);

    group_res->sg_id = GRP_ID_PHB_GROUP;
    group_res->curr_res_type = group_info->res_type;
    group_res->ring_id = group_info->ringtone_id;
    mmi_wcscpy(group_res->ring_path, group_info->ringtone_path);
    group_res->img_id = group_info->image_id;
    if (group_info->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
    {
        group_res->img_id |= 0x8000;
    }
    mmi_wcscpy(group_res->img_path, group_info->image_path);
#if defined(__MMI_PHB_CALLER_VIDEO__)
    group_res->video_id = group_info->video_id;
    if (group_info->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE)
    {
        group_res->video_id |= 0x8000;
    }
    if (group_info->res_type & SRV_PHB_RES_TYPE_VIDEO_SOUND_ON)
    {
        group_res->video_id |= 0x4000;    	
        group_res->video_audio = 1;
    }
    mmi_wcscpy(group_res->video_path, group_info->video_path);
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
    mmi_phb_contact_build_res();
#endif /* __MMI_PHB_CALLER_RES__ */

    storage = mmi_phb_entry_get_group_storage();
    inline_id = cui_inline_create(GRP_ID_PHB_GROUP, mmi_phb_construct_group_editor(storage));
#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__   
    mmi_phb_entry_set_group_name_length(inline_id, storage);
#endif
    group_data->inline_id = inline_id;
    group_data->add_new = MMI_FALSE;

    mmi_phb_group_editor_set_item(inline_id);
    cui_inline_run(inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_editor_option_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_phb_entry_group_editor_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    MMI_ID sender_id = menu_evt->sender_id;
    U16 inline_item_id = group_data->inline_item_id;
    U16 highlighted_menu_id = menu_evt->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (inline_item_id == INLINE_ID_PHB_GROUP_NAME)
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_IMAGE_OPTION_VIEW, MMI_TRUE);
            #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_RINGTONE_OPTION_SELECT, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_IMAGE_OPTION_SELECT, MMI_TRUE);
            #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_IMAGE_OPTION_CAMERA, MMI_TRUE);
            #endif /* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */
            #endif
            #ifdef __MMI_PHB_CALLER_VIDEO__
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_VIDEO_OPTION_PLAY, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_VIDEO_OPTION_SELECT, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET, MMI_TRUE);
            #endif /* __MMI_PHB_CALLER_VIDEO__ */
            }
        #ifdef __MMI_PHB_CALLER_RES__
            else if (inline_item_id == INLINE_ID_PHB_GROUP_RINGTONE)
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_IMAGE_OPTION_VIEW, MMI_TRUE);
            #ifdef __MMI_PHB_CALLER_VIDEO__
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_VIDEO_OPTION_PLAY, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_VIDEO_OPTION_SELECT, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET, MMI_TRUE);
            #endif /* __MMI_PHB_CALLER_VIDEO__ */
            #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_IMAGE_OPTION_SELECT, MMI_TRUE);
            #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_IMAGE_OPTION_CAMERA, MMI_TRUE);
            #endif /* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */
            #endif
            #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
                mmi_phb_edit_option_ringtone_highlight_hdlr(sender_id);
            #endif
            }
#if !defined(LOW_COST_SUPPORT) || (defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)&&defined(__SRV_PHB_CALLER_RES_DATA_STORE__))           
            else if (inline_item_id == INLINE_ID_PHB_GROUP_PICTURE)
            {
            #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_RINGTONE_OPTION_SELECT, MMI_TRUE);
            #endif
            #ifdef __MMI_PHB_CALLER_VIDEO__
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_VIDEO_OPTION_PLAY, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_VIDEO_OPTION_SELECT, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET, MMI_TRUE);
            #endif /* __MMI_PHB_CALLER_VIDEO__ */
                mmi_phb_edit_option_image_highlight_hdlr(sender_id);
            }
#endif
        #ifdef __MMI_PHB_CALLER_VIDEO__
            else if (inline_item_id == INLINE_ID_PHB_GROUP_VIDEO)
            {
            #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_RINGTONE_OPTION_SELECT, MMI_TRUE);
            #endif
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_IMAGE_OPTION_VIEW, MMI_TRUE);
            #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_IMAGE_OPTION_SELECT, MMI_TRUE);
            #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_EDIT_IMAGE_OPTION_CAMERA, MMI_TRUE);
            #endif /* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */
            #endif
                mmi_phb_edit_option_video_highlight_hdlr(sender_id);
                cui_menu_set_non_leaf_item(sender_id, MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET, MMI_FALSE);
            }
        #endif /* __MMI_PHB_CALLER_VIDEO__ */
        #endif /* __MMI_PHB_CALLER_RES__ */
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(highlighted_menu_id)
            {
                case MENU_ID_PHB_EDIT_OK:
                    mmi_phb_save_group();
                    break;

                case MENU_ID_PHB_EDIT_CANCEL:
                    cui_inline_close(group_data->inline_id);
                    cui_menu_close(sender_id);
                    break;
                
            #ifdef __MMI_PHB_CALLER_RES__
                case MENU_ID_PHB_EDIT_IMAGE_OPTION_VIEW:
                    mmi_phb_entry_image_view_ext(GRP_ID_PHB_GROUP);
                    break;

            #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
                case MENU_ID_PHB_EDIT_RINGTONE_OPTION_SELECT:
                    mmi_phb_ringtone_select_from_file_mamager();
                    break;

                case MENU_ID_PHB_EDIT_IMAGE_OPTION_SELECT:
                    mmi_phb_entry_choose_caller_pic();
                    break;

            #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
                case MENU_ID_PHB_EDIT_IMAGE_OPTION_CAMERA:
                   mmi_phb_image_select_from_camera();
                   break;
            #endif /* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */
            #endif /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) */

            #ifdef __MMI_PHB_CALLER_VIDEO__
                case MENU_ID_PHB_EDIT_VIDEO_OPTION_PLAY:
                    mmi_phb_entry_video_view_ext(GRP_ID_PHB_GROUP);
                    break;

                case MENU_ID_PHB_EDIT_VIDEO_OPTION_SELECT:
                    mmi_phb_entry_choose_caller_video();
                    break;

                case MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET:
                    mmi_phb_entry_video_audio_option(GRP_ID_PHB_GROUP);
                    break;
            #endif /* __MMI_PHB_CALLER_VIDEO__ */
            #endif /* __MMI_PHB_CALLER_RES__ */

                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_editor_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_menu_cui_generic(
        GRP_ID_PHB_GROUP,
        MENU_ID_PHB_CALLERGROUP_MEMBER_VIEW_OPTION,
        0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_save_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_save_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_caller_res_struct *group_res = &(group_data->group_res);
#endif
    srv_phb_group_info_struct *group_info = &(group_data->group_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_RES__
        group_info->res_type = 0;
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) && defined(__SRV_PHB_CALLER_RES_DATA_STORE__)
        if (group_res->selected_ring_index == g_mmi_phb_resource.total_ring_tone - 1)
        {
            if (group_res->ring_path[0] != 0)
            {
                group_info->ringtone_id = 0;
                group_info->res_type |= SRV_PHB_RES_TYPE_AUDIO_RING_FILE;
            }
            else
            {
                group_info->ringtone_id = 0;
                group_info->res_type |= SRV_PHB_RES_TYPE_RING_ID;
            }
        }
        else
#endif
        {
            group_info->ringtone_id = g_mmi_phb_resource.ring_tone_list[group_res->selected_ring_index];
            group_info->res_type |= SRV_PHB_RES_TYPE_RING_ID;
        }
        mmi_wcscpy(group_info->ringtone_path, group_res->ring_path);

        group_info->image_id = g_mmi_phb_resource.image_id_list[group_res->selected_pic_index];
        if (group_info->image_id == 0x8000)
        {
            group_info->image_id = 0;
            group_info->res_type |= SRV_PHB_RES_TYPE_IMAGE_FILE;
        }
        else if (group_info->image_id && (group_info->image_id != IMG_PHB_DEFAULT))
        {
            group_info->res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
        }
        mmi_wcscpy(group_info->image_path, group_res->img_path);

#ifdef __MMI_PHB_CALLER_VIDEO__
        group_info->video_id = g_mmi_phb_resource.video_id_list[group_res->selected_video_index];
        if (group_info->video_id == 0x8000)
        {
            group_info->video_id = 0;
            group_info->res_type |= SRV_PHB_RES_TYPE_VIDEO_FILE;
        }
        else if (group_info->video_id)
        {
            group_info->res_type |= SRV_PHB_RES_TYPE_VIDEO_ID;
        }
        if (group_res->video_audio)
        {
            group_info->res_type |= SRV_PHB_RES_TYPE_VIDEO_SOUND_ON;
        }
        mmi_wcscpy(group_info->video_path, group_res->video_path);
#endif /* __MMI_PHB_CALLER_VIDEO__ */
#endif /* __MMI_PHB_CALLER_RES__ */

    if (group_data->add_new)
    {   /* group manager change */
        group_info->storage = group_data->storage;
        group_info->cb = mmi_phb_entry_group_cb;
        group_info->user_data = (void *)MMI_PHB_GRP_OP_ADD;
        srv_phb_add_group((srv_phb_group_info_struct*) (&group_data->group_info));
    }
    else
    {
        group_info->storage = mmi_phb_entry_get_group_storage();
        group_info->cb = mmi_phb_entry_group_cb;
        group_info->user_data = (void *)MMI_PHB_GRP_OP_ADD;
        srv_phb_update_group_info(
                #ifndef __MMI_PHB_UI_IN_TABS__
                    group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1],
                #else
                    g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1],
                #endif
                    (srv_phb_group_info_struct*) (&(group_data->group_info)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_delete_group_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_delete_group_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_confirm_display_ext(
        STR_GLOBAL_DELETE_ASK,
        GRP_ID_PHB_GROUP,
        mmi_phb_delete_group,
        mmi_frm_scrn_close_active_id,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_delete_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_delete_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_show_in_progress(GRP_ID_PHB_GROUP, STR_GLOBAL_PLEASE_WAIT);

    srv_phb_delete_group(
    #ifndef __MMI_PHB_UI_IN_TABS__
        group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1],
    #else
        g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1],
    #endif
        mmi_phb_entry_group_cb,
        (void *)MMI_PHB_GRP_OP_REMOVE);

#ifndef __MMI_PHB_UI_IN_TABS__
    group_data->main_list.refresh = MMI_TRUE;
#else
    g_mmi_phb_group_list_tab.refresh = MMI_FALSE;
	if (g_mmi_phb_group_list_tab.hilite_index == g_mmi_phb_group_list_tab.group_count)
	{
		g_mmi_phb_group_list_tab.hilite_index--;
	}
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_delete_all_group_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_delete_all_group_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_confirm_display_ext(
        STR_ID_PHB_GROUP_DELETEALL_QUERY,
        GRP_ID_PHB_GROUP,
        mmi_phb_delete_all_group,
        mmi_frm_scrn_close_active_id,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_delete_all_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_delete_all_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_show_in_progress(GRP_ID_PHB_GROUP, STR_GLOBAL_PLEASE_WAIT);

#ifndef __MMI_PHB_UI_IN_TABS__
    srv_phb_delete_group(group_data->main_list.group_id_list[group_data->main_list.group_count - 1], 
        mmi_phb_entry_group_cb, 
        (void *)MMI_PHB_GRP_OP_REMOVE_ALL);
#else /* __MMI_PHB_UI_IN_TABS__ */
    srv_phb_delete_group(g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.group_count - 1], 
        mmi_phb_entry_group_cb, 
        (void *)MMI_PHB_GRP_OP_REMOVE_ALL);
#endif /* __MMI_PHB_UI_IN_TABS__ */

#ifndef __MMI_PHB_UI_IN_TABS__
    group_data->main_list.refresh = MMI_TRUE;
#else
    g_mmi_phb_group_list_tab.refresh = MMI_TRUE;
#endif
}


#define MMI_PHB_GROUP_MEMBER_LIST
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fte_group_member_list_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tap_type        [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fte_group_member_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_phb_entry_group_member_list_option_view();
    }
}
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_view_member
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_group_view_member(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
	U8 group_id; 
	phb_storage_enum storage;
#ifndef __MMI_PHB_UI_IN_TABS__
    mmi_phb_group_cntx_struct *group_data;
#endif
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (!mmi_frm_group_is_present(GRP_ID_PHB_GROUP))
    {
        mmi_phb_caller_group_create();
    }

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
#ifndef __MMI_PHB_UI_IN_TABS__
    group_data = (mmi_phb_group_cntx_struct*)mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    group_id = group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1];
#else
    group_id = g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1];
#endif
	storage = srv_phb_get_storage_by_group_id(group_id);
    if (!mmi_phb_memory_card_is_ready(storage, MMI_TRUE))
    {       
        return;
    }
#endif

    mmi_phb_entry_group_member_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_member_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
static S32 mmi_phb_group_member_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    U16 name[MMI_PHB_NAME_LENGTH + 1];
    S32 index;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < data_size; index++)
    {
        srv_phb_get_name(group_data->member.member_list[index + item_index], name, MAX_SUBMENU_CHARACTERS);

        if (*name != 0)
        {
            mmi_ucs2ncpy((CHAR*) menu_data[index].item_list[0], (CHAR*) name, MAX_SUBMENU_CHARACTERS);
        }
        else
        {
            mmi_ucs2ncpy((CHAR*) menu_data[index].item_list[0], GetString(STR_ID_PHB_UNNAMED), MAX_SUBMENU_CHARACTERS);
        }

        storage = srv_phb_get_storage(group_data->member.member_list[index + item_index]);
        if (PHB_STORAGE_NVRAM == storage)
        {
	    #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
            menu_data[index].image_list[0] = get_image(IMG_ID_PHB_LIST_PHOTO);
        #else
            menu_data[index].image_list[0] = get_image(IMG_STORAGE_HANDSET);
        #endif
        }
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        else if (PHB_STORAGE_TCARD == storage)
        {
        #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
            menu_data[index].image_list[0] = get_image(IMG_ID_PHB_LIST_PHOTO);
        #else
            menu_data[index].image_list[0] = get_image(IMG_ID_PHB_TCARD_LIST);
        #endif        
        }
    #endif
        else
        {
           menu_data[index].image_list[0] = get_image(IMG_STORAGE_SIM); 
        }
    }
    
    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_member_list_get_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_phb_group_member_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    srv_phb_get_default_number(group_data->member.member_list[item_index], (U16*)hint_array[0], NULL, MMI_PHB_NUMBER_LENGTH + 1);
    if (hint_array[0][0] == 0)
    {
        srv_phb_get_number(group_data->member.member_list[item_index], (U16*)hint_array[0], MAX_SUBMENU_CHARACTERS);
    }
#else /* __MMI_PHB_DEFAULT_NUMBER__ */
    srv_phb_get_number(group_data->member.member_list[item_index], (U16*)hint_array[0], MAX_SUBMENU_CHARACTERS);
#endif /* __MMI_PHB_DEFAULT_NUMBER__ */

    if (hint_array[0][0] != 0)
    {
        result = 1; 
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_member_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_member_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data->member.hilite_index = index;
    group_data->member.origin_store_index = group_data->member.member_list[index];
}


#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_store_id_by_list_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index            [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static U16 mmi_phb_get_store_id_by_member_index(S32 item_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item_idx < group_data->member.member_count);

    return group_data->member.member_list[item_idx];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_member_list_thumbnail_get_image_path_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_phb_member_list_thumbnail_get_image_path_callback(S32 item_idx, CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_phb_thumbnail_get_image_path_callback(mmi_phb_get_store_id_by_member_index(item_idx), path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_member_list_thumbnail_set_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_member_list_thumbnail_set_displayable(S32 item_idx, MMI_BOOL displayable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_thumbnail_set_displayable(mmi_phb_get_store_id_by_member_index(item_idx), displayable);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_member_list_thumbnail_get_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_phb_member_list_thumbnail_get_displayable(S32 item_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_phb_thumbnail_get_displayable(mmi_phb_get_store_id_by_member_index(item_idx));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_list_thumbnail_get_menuitem_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_member_list_thumbnail_get_menuitem_info(S32 item_idx, wgui_thumbnail_info_struct *menuitem_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_thumbnail_get_menuitem_info(mmi_phb_get_store_id_by_member_index(item_idx), menuitem_data);
}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_member_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_group_member_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    U8 *gui_buffer;
    U8 *item_list[1];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(
        GRP_ID_PHB_GROUP,
        SCR_ID_PHB_CALLERGROUP_MEMBER_LIST,
        NULL,
        mmi_phb_entry_group_member_list,
        MMI_FRM_UNKNOW_SCRN);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    group_data->member.member_count = mmi_phb_group_get_member_count(0xFFFF);

    if (group_data->member.member_count == 0)
    {
        item_list[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        group_data->member.hilite_index = 0;
        group_data->member.origin_store_index = 0xf000;

        
#ifndef __MMI_WGUI_DISABLE_CSK__		
#ifndef __MMI_MAINLCD_96X64__
        EnableCenterSoftkey(0, IMG_ID_PHB_CSK_ADD);
#else
	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 	
#endif
        ShowCategory6Screen(
            STR_ID_PHB_CALLERGROUP_MEMBER_LIST,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_ADD,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            item_list,
            NULL,
            0,
            gui_buffer);

	#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
        SetLeftSoftkeyFunction(mmi_phb_entry_group_member_list_option_ms_add, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_entry_group_member_list_option_ms_add, KEY_EVENT_UP);
	#else
	    SetLeftSoftkeyFunction(mmi_phb_entry_group_member_list_option_add, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_entry_group_member_list_option_add, KEY_EVENT_UP);
	#endif
    }
    else
    {
        if (gui_buffer != NULL)
        {
            if (group_data->member.refresh)
            {
                if (group_data->member.active_store_index > MMI_PHB_PHONE_ENTRIES)
                {
                    if (group_data->member.hilite_index == group_data->member.member_count)
                    {
                        group_data->member.hilite_index--;
                    }
                }
                else
                {
                    for (i = 0; i < group_data->member.member_count; i++)
                    {
                        if (group_data->member.origin_store_index == group_data->member.member_list[i])
                        {
                            group_data->member.hilite_index = i;
                            break;
                        }
                    }
                }
                gui_buffer = NULL;
                group_data->member.refresh = MMI_FALSE;
            }
        }
        else
        {
            group_data->member.hilite_index = 0;
        }

        RegisterHighlightHandler(mmi_phb_group_member_list_highlight_hdlr);

	#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
        mmi_phb_thumbnail_reset_displayable();
        wgui_thumbnail_register_get_image_path_func(mmi_phb_member_list_thumbnail_get_image_path_callback);
        wgui_thumbnail_register_set_displayable_func(mmi_phb_member_list_thumbnail_set_displayable);
        wgui_thumbnail_register_get_displayable_func(mmi_phb_member_list_thumbnail_get_displayable);
        wgui_thumbnail_register_get_image_info_func(mmi_phb_member_list_thumbnail_get_menuitem_info);
        wgui_thumbnail_register_get_store_id_func(mmi_phb_get_store_id_by_member_index);
	#endif

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
        wgui_cat1034_show(
                (WCHAR*) GetString(STR_ID_PHB_CALLERGROUP_MEMBER_LIST),
                (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
                (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
                (PU8) GetImage(IMG_GLOBAL_OPTIONS),
                (WCHAR*) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                group_data->member.member_count,
                mmi_phb_group_member_list_get_item,
                mmi_phb_group_member_list_get_hint,
                group_data->member.hilite_index,
                0,    
                IMG_ID_PHB_LIST_PHOTO,
                0,
                gui_buffer,
                NULL);
    #else
        wgui_cat1032_show(
                (WCHAR*) GetString(STR_ID_PHB_CALLERGROUP_MEMBER_LIST),
                (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
                (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
                (PU8) GetImage(IMG_GLOBAL_OPTIONS),
                (WCHAR*) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                group_data->member.member_count,
                mmi_phb_group_member_list_get_item,
                mmi_phb_group_member_list_get_hint,
                group_data->member.hilite_index,
                0,    
                IMG_STORAGE_HANDSET,
                0,
                gui_buffer,
                NULL);
    #endif

        SetLeftSoftkeyFunction(mmi_phb_entry_group_member_list_option, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_entry_group_member_list_option_view, KEY_EVENT_UP);
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_phb_fte_group_member_list_tap_callback);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_member_list_option_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_phb_entry_group_member_list_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
#ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__    
    U8 group_id_list[MMI_PHB_GROUP_COUNT];
    U32 group_count;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        #ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__
            group_count = srv_phb_get_group_list(group_id_list, NULL, mmi_phb_entry_get_group_storage());
            if (group_count == 1)
            {
        #if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PHB_CALLER_GROUPS_MEMBERS_LIST_OP_MS_MOVE, MMI_TRUE);    
        #else
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_PHB_CALLER_GROUPS_MEMBERS_LIST_OP_MOVE, MMI_TRUE);
        #endif
            }
        #endif
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_PHB_CALLER_GROUPS_MEMBERS_LIST_OP_VIEW:
                    mmi_phb_entry_group_member_list_option_view();
                    break;

            #if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
	            case MENU_ID_PHB_CALLER_GROUPS_MEMBERS_LIST_OP_MS_ADD:
	                mmi_phb_entry_group_member_list_option_ms_add();
	                break;
                    
			#ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__
	            case MENU_ID_PHB_CALLER_GROUPS_MEMBERS_LIST_OP_MS_MOVE:
                    mmi_phb_entry_group_member_list_option_ms_move();
	                break;
	        #endif
            
	            case MENU_ID_PHB_CALLER_GROUPS_MEMBERS_LIST_OP_MS_REMOVE:
                    mmi_phb_group_member_list_option_ms_remove();
	                break;
                    
            #else
                case MENU_ID_PHB_CALLER_GROUPS_MEMBERS_LIST_OP_ADD:
                    mmi_phb_entry_group_member_list_option_add();
                    break;
                    
            #ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__
	         case MENU_ID_PHB_CALLER_GROUPS_MEMBERS_LIST_OP_MOVE:
	            mmi_phb_group_member_list_option_move();
	            break;
            #endif
            
                case MENU_ID_PHB_CALLER_GROUPS_MEMBERS_LIST_OP_REMOVE:
                    mmi_phb_group_member_list_option_remove(MMI_PHB_GRP_MEM_OP_REMOVE);
                    break;

                case MENU_ID_PHB_CALLER_GROUPS_MEMBERS_LIST_OP_REMOVE_ALL:
                    mmi_phb_group_member_list_option_remove_all();
                    break;
	    #endif

                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_choose_storage_add_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_phb_entry_group_choose_storage_add_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    phb_storage_enum temp_storage = PHB_STORAGE_NVRAM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
        #if (MMI_MAX_SIM_NUM >= 2)
            mmi_phb_new_entry_choose_storage_check(menu_evt->sender_id, MITEM_ADD_ENTRY_TO_SIM, STR_ID_PHB_TO_SIM1);
        #else
            mmi_phb_new_entry_choose_storage_check(menu_evt->sender_id, MITEM_ADD_ENTRY_TO_SIM, STR_ID_PHB_TO_SIM);
        #endif
        #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
            mmi_phb_memory_card_not_available_hide_menu(menu_evt->sender_id, MITEM_ADD_ENTRY_TO_MEMORY_CARD);
        #endif
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                if (menu_evt->highlighted_menu_id == MITEM_ADD_ENTRY_TO_SIM)
                {
                    temp_storage = PHB_STORAGE_SIM;
                }
                else if (menu_evt->highlighted_menu_id == MITEM_ADD_ENTRY_TO_PHONE)
                {
                    temp_storage = PHB_STORAGE_NVRAM;
                }
            #if (MMI_MAX_SIM_NUM >= 2)
                else if (menu_evt->highlighted_menu_id == MENU_MTPNP_PB_ADD_SIM2)
                {
                    temp_storage = PHB_STORAGE_SIM2;
                }
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                else if(menu_evt->highlighted_menu_id == MENU_MTPNP_PB_ADD_SIM3)
                {
                    temp_storage = PHB_STORAGE_SIM3;
                }
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                else if(menu_evt->highlighted_menu_id == MENU_MTPNP_PB_ADD_SIM4)
                {
                    temp_storage = PHB_STORAGE_SIM4;
                }
            #endif
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__    
                else if(menu_evt->highlighted_menu_id == MITEM_ADD_ENTRY_TO_MEMORY_CARD)
                {
                    temp_storage = PHB_STORAGE_TCARD;
                }
            #endif
                if (!mmi_phb_entry_group_is_full(temp_storage))
                {
                    group_data->storage = temp_storage;
                    mmi_phb_entry_group_edit_cui();
                    cui_menu_close(menu_evt->sender_id);
                }
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_member_list_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_member_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_menu_cui_generic(
        GRP_ID_PHB_GROUP,
        MENU_ID_PHB_CALLER_GROUPS_MEMBERS_LIST_OP,
        0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_member_list_option_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_member_list_option_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phb_view_contact(GRP_ID_PHB_GROUP, group_data->member.member_list[group_data->member.hilite_index]);
}


#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_ms_member_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_ms_member_cb(S32 result, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_member_data_struct *data = (mmi_phb_group_member_data_struct*)(user_data);
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*)mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    srv_phb_group_add_members_req add_member_req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!data->count && data->op != MMI_PHB_GRP_MEM_OP_MS_ADD)
	{
		MMI_PHB_LOG4(TRC_MMI_PHB_GROUP_MEMBERS_CB, data->count, data->op, g_mmi_phb_list_p->sg_id, g_mmi_phb_list_p->mark_count);
		return;
	}
	
    switch (data->op)
    {
        case MMI_PHB_GRP_MEM_OP_MS_ADD:
            if (result < 0)
            {
                mmi_phb_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);    
            }
            mmi_frm_group_close(g_mmi_phb_list_p->sg_id);
            mmi_phb_mem_free(data);
            break;
    
        case MMI_PHB_GRP_MEM_OP_MS_MOVE:
            if (result >= 0)
            {
                data->count = data->count - 1;
                if (data->count == 0)
                {
                    data->op = MMI_PHB_GRP_MEM_OP_MS_ADD;
                    add_member_req.id_array = g_mmi_phb_list_p->mark_array;
                    add_member_req.entry_count = g_mmi_phb_list_p->mark_count;
                    add_member_req.group_id = group_data->member.dest_group_id;
                    add_member_req.cb = mmi_phb_entry_ms_member_cb;
                    add_member_req.is_reset = MMI_FALSE;
                    add_member_req.user_data = data;
                    srv_phb_add_group_members(&add_member_req);
                }
                else
                {
                    srv_phb_remove_group_member(
                        g_mmi_phb_list_p->mark_array[data->count - 1],
                    #ifndef __MMI_PHB_UI_IN_TABS__
                        group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1],
                    #else
                        g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1],
                    #endif
                        mmi_phb_entry_ms_member_cb,
                        data);
                }
            }
            else
            {
                mmi_frm_group_close(g_mmi_phb_list_p->sg_id);
                mmi_phb_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);
                mmi_phb_mem_free(data);
            }
            break;

        case MMI_PHB_GRP_MEM_OP_MS_REMOVE:
            if (result >= 0)
            {
                data->count = data->count - 1;
                if (data->count == 0)
                {
                    mmi_phb_mem_free(data);
                    mmi_frm_group_close(g_mmi_phb_list_p->sg_id);
                }
                else
                {
                    srv_phb_remove_group_member(
                        g_mmi_phb_list_p->mark_array[data->count - 1],
                    #ifndef __MMI_PHB_UI_IN_TABS__
                        group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1],
                    #else
                        g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1],
                    #endif
                        mmi_phb_entry_ms_member_cb,
                        data);
                }
            }
            else
            {
                mmi_phb_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);
                mmi_phb_mem_free(data);
                mmi_frm_group_close(g_mmi_phb_list_p->sg_id);
            }
            break;

        default:
            break;
   }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_ms_add_op
 * DESCRIPTION
 *  add several interfce
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_ms_add_op(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_group_add_members_req add_member_req;
    mmi_phb_group_member_data_struct *member_data;
    mmi_phb_group_member_struct *group_member;
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    U8 caller_group_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_show_in_progress(g_mmi_phb_list_p->sg_id, STR_GLOBAL_PLEASE_WAIT);
    member_data = (mmi_phb_group_member_data_struct*)mmi_phb_mem_malloc(
        sizeof(mmi_phb_group_member_data_struct), SRV_PHB_MEMORY_TYPE_CTR);
	memset(member_data, 0, sizeof(mmi_phb_group_member_data_struct));
    member_data->op = MMI_PHB_GRP_MEM_OP_MS_ADD;
                        
#ifdef __MMI_PHB_UI_IN_TABS__
    caller_group_id = g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1];
#else
    caller_group_id = group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1];
#endif
    if (g_mmi_phb_list_p->mark_count > 0)
    {
        group_member = &group_data->member;
	    group_member->refresh = MMI_TRUE;
		group_member->active_store_index = g_mmi_phb_list_p->mark_array[0];
	}
    add_member_req.id_array = g_mmi_phb_list_p->mark_array;
    add_member_req.entry_count = g_mmi_phb_list_p->mark_count;
    add_member_req.group_id = caller_group_id;
    add_member_req.cb = mmi_phb_entry_ms_member_cb;
    add_member_req.is_reset = MMI_FALSE;
    add_member_req.user_data = member_data;
    srv_phb_add_group_members(&add_member_req);                                     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_mark_several_option
 * DESCRIPTION
 *  Entry group mark several Options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_entry_group_ms_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*)mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_mark_several_populate();

    menu_gid = cui_menu_create(
               GRP_ID_PHB_MARK_SEVERAL,
               CUI_MENU_SRC_TYPE_RESOURCE,
               CUI_MENU_TYPE_OPTION,
               MENU_ID_PHB_GROUP_MARK_SEVERAL_OP,
               MMI_FALSE, NULL);

    if (mmi_phb_bitmask_get_state(g_mmi_phb_list_p->bitmask, g_mmi_phb_list_p->store_index))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_MARK, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_UNMARK, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_MARK, MMI_FALSE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_UNMARK, MMI_TRUE);
    } 

    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_MARK_ALL, MMI_FALSE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_UNMARK_ALL, MMI_FALSE);
    
    if (mmi_phb_mark_several_search_count() == 0)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_UNMARK_ALL, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_DELETE_SELECTED, MMI_TRUE);
    #ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_MOVE_SELECTED, MMI_TRUE);
    #endif
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_ADD_SELECTED, MMI_TRUE);
    }
    else if (mmi_phb_mark_several_search_count() == g_mmi_phb_list_p->contact_count)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_MARK_ALL, MMI_TRUE);
    }

    if (group_data->member.memeber_op == MMI_PHB_GRP_MEM_OP_MS_REMOVE)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_ADD_SELECTED, MMI_TRUE);
    #ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_MOVE_SELECTED, MMI_TRUE);
    #endif
    }
#ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__
    else if (group_data->member.memeber_op == MMI_PHB_GRP_MEM_OP_MS_MOVE)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_ADD_SELECTED, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_DELETE_SELECTED, MMI_TRUE);
    }
#endif
    else if (group_data->member.memeber_op == MMI_PHB_GRP_MEM_OP_MS_ADD)
    {
    #ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_MOVE_SELECTED, MMI_TRUE);
    #endif
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_DELETE_SELECTED, MMI_TRUE);
    }
    
    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);
    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_ms_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_group_ms_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 group_id;
    srv_phb_group_info_struct group_info;
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*)mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifndef __MMI_PHB_UI_IN_TABS__
    group_id = group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1];
#else
    group_id = g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1];
#endif

    srv_phb_get_group_info(group_id, &group_info);
    cui_phb_list_select_contact_set_storage(g_mmi_phb_list_p->sg_id, group_info.storage);

    if (MMI_PHB_GRP_MEM_OP_MS_ADD == group_data->member.memeber_op)
    {
        cui_phb_list_select_contact_set_group(g_mmi_phb_list_p->sg_id, group_id, MMI_FALSE);
    }
    else
    {
        cui_phb_list_select_contact_set_group(g_mmi_phb_list_p->sg_id, group_id, MMI_TRUE);
    }

    mmi_phb_entry_group_mark_several_list(
        mmi_phb_entry_group_ms_option,
        mmi_phb_mark_several_check,
        mmi_phb_entry_group_ms_list,
        group_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_member_list_option_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_member_list_option_ms_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id = GRP_ID_PHB_GROUP;
    mmi_id new_sg_id;
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*)mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_MARK_SEVERAL);
    new_sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
    mmi_phb_cntx_mgr_set_parent_id(handle, sg_id);
    list_cntx = cui_phb_list_select_contact_create_cntx(MMI_PHB_LIST_TYPE_MULTI_SELECT);  
    list_cntx->sg_id = new_sg_id;
    list_cntx->parent_id = sg_id; 
    mmi_phb_cntx_mgr_set_data(handle, list_cntx);
    cui_phb_list_select_contact_set_cntx(list_cntx);

    mmi_frm_group_create_ex(
        sg_id,
        new_sg_id,
        cui_phb_list_select_group_member_proc,
        list_cntx,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    group_data->member.memeber_op = MMI_PHB_GRP_MEM_OP_MS_ADD;
    mmi_phb_entry_group_ms_list();
}


#ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_mark_several_move_pre_req
 * DESCRIPTION
 *  move several interfce
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_group_ms_move_op(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    mmi_phb_group_member_data_struct *member_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_show_in_progress(g_mmi_phb_list_p->sg_id, STR_GLOBAL_PLEASE_WAIT);
    member_data = (mmi_phb_group_member_data_struct*)mmi_phb_mem_malloc(sizeof(mmi_phb_group_member_data_struct), SRV_PHB_MEMORY_TYPE_CTR);
	memset(member_data, 0, sizeof(mmi_phb_group_member_data_struct));
    member_data->op = MMI_PHB_GRP_MEM_OP_MS_MOVE;
    member_data->count = g_mmi_phb_list_p->mark_count;

    srv_phb_remove_group_member(
        g_mmi_phb_list_p->mark_array[g_mmi_phb_list_p->mark_count - 1],
    #ifndef __MMI_PHB_UI_IN_TABS__
        group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1],
    #else
        g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1],
    #endif
        mmi_phb_entry_ms_member_cb,
        member_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_mark_several_move_coinfirm
 * DESCRIPTION
 *  confirm mark several move
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_group_ms_move_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = g_mmi_phb_list_p->sg_id;
    arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;
        
    mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
    g_mmi_phb_confirm_user_data.sg_id = g_mmi_phb_list_p->sg_id;
    g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_group_ms_move_op;

    arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;
    mmi_confirm_display(
        (WCHAR *) get_string(STR_ID_PHB_MULTI_OP_MOVE_SELECTED_ASK),
        MMI_EVENT_QUERY,
        &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_member_list_option_ms_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_member_list_option_ms_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id = GRP_ID_PHB_GROUP;
    mmi_id new_sg_id;
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*)mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_MARK_SEVERAL);
    new_sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
    mmi_phb_cntx_mgr_set_parent_id(handle, sg_id);
    list_cntx = cui_phb_list_select_contact_create_cntx(MMI_PHB_LIST_TYPE_MULTI_SELECT);  
    list_cntx->sg_id = new_sg_id;
    list_cntx->parent_id = sg_id; 
    mmi_phb_cntx_mgr_set_data(handle, list_cntx);
    cui_phb_list_select_contact_set_cntx(list_cntx);

    mmi_frm_group_create_ex(
        sg_id,
        new_sg_id,
        cui_phb_list_select_group_member_proc,
        list_cntx,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    group_data->member.memeber_op = MMI_PHB_GRP_MEM_OP_MS_MOVE;
    mmi_phb_entry_group_ms_list();
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fte_group_list_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tap_type        [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fte_group_ms_move_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_phb_group_ms_move_confirm();
    }
}
#endif
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_mark_several_move_pre_req
 * DESCRIPTION
 *  move several interfce
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_group_ms_remove_op(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    mmi_phb_group_member_data_struct *member_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_show_in_progress(g_mmi_phb_list_p->sg_id, STR_GLOBAL_PLEASE_WAIT);
    member_data = (mmi_phb_group_member_data_struct*)mmi_phb_mem_malloc(sizeof(mmi_phb_group_member_data_struct), SRV_PHB_MEMORY_TYPE_CTR);
	memset(member_data, 0, sizeof(mmi_phb_group_member_data_struct));
    member_data->op = MMI_PHB_GRP_MEM_OP_MS_REMOVE;
    member_data->count = g_mmi_phb_list_p->mark_count;
    member_data->finished = MMI_FALSE;
    
    srv_phb_remove_group_member(
        g_mmi_phb_list_p->mark_array[g_mmi_phb_list_p->mark_count - 1],
    #ifndef __MMI_PHB_UI_IN_TABS__
        group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1],
    #else
        g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1],
    #endif
        mmi_phb_entry_ms_member_cb,
        member_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_mark_several_move_coinfirm
 * DESCRIPTION
 *  confirm mark several move
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_group_ms_remove_confirm(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = group_id;
    arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;
        
    mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
    g_mmi_phb_confirm_user_data.sg_id = group_id;
    g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_group_ms_remove_op;
        
    arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;
        
    mmi_confirm_display(
        (WCHAR *) get_string(STR_ID_PHB_MULTI_OP_REMOVE_SELECTED_ASK),
        MMI_EVENT_QUERY,
        &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_member_list_option_ms_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_member_list_option_ms_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id = GRP_ID_PHB_GROUP;
    mmi_id new_sg_id;
    U32 handle;
    mmi_phb_list_cntx_struct *list_cntx;
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*)mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_MARK_SEVERAL);
    new_sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
    mmi_phb_cntx_mgr_set_parent_id(handle, sg_id);
    list_cntx = cui_phb_list_select_contact_create_cntx(MMI_PHB_LIST_TYPE_MULTI_SELECT);    
    list_cntx->sg_id = new_sg_id;
    list_cntx->parent_id = sg_id; 
    mmi_phb_cntx_mgr_set_data(handle, list_cntx);
    cui_phb_list_select_contact_set_cntx(list_cntx);

    mmi_frm_group_create_ex(
        sg_id,
        new_sg_id,
        cui_phb_list_select_group_member_proc,
        list_cntx,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    group_data->member.memeber_op = MMI_PHB_GRP_MEM_OP_MS_REMOVE;
    mmi_phb_entry_group_ms_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_select_contact_proc
 * DESCRIPTION
 *  Phonebook group - select contact list: proc function
 * PARAMETERS
 *  evt                   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phb_group_member_ms_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {   
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_MARK_ALL)
            {
                mmi_phb_op_mark_several_mark_all();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_UNMARK_ALL)
            {
                mmi_phb_op_mark_several_unmark_all();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_MARK)
            {
                mmi_phb_op_mark_several_mark_unmark();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_UNMARK)
            {
                mmi_phb_op_mark_several_mark_unmark();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_DELETE_SELECTED)
            {
                mmi_phb_group_ms_remove_confirm(g_mmi_phb_list_p->sg_id);
            }
        #ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_MOVE_SELECTED)
            {
                mmi_phb_group_member_list_option_move();
            }
        #endif
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_GROUP_MARK_SEVERAL_OP_ADD_SELECTED)
            {
                mmi_phb_group_ms_add_op();    
            }
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }
        
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
                       
        default:
            result = MMI_RET_DONT_CARE;
            break;
    }
 
    return result;
}


#else
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_member_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_member_cb(S32 result, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_member_data_struct *data = (mmi_phb_group_member_data_struct*)(user_data);
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*)mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    srv_phb_group_add_members_req add_member_req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->op)
    {  
        case MMI_PHB_GRP_MEM_OP_ADD:
            if (data->finished)
            {
                mmi_frm_scrn_close(g_mmi_phb_list_p->sg_id, SCR_IN_PROGRESS_PHB);
            }
            else
            {
                mmi_frm_group_close(g_mmi_phb_list_p->sg_id);    
            }
            mmi_phb_mem_free(data);
            break;
        
        case MMI_PHB_GRP_MEM_OP_REMOVE:
        case MMI_PHB_GRP_MEM_OP_REMOVE_ALL:
            mmi_frm_scrn_close(g_mmi_phb_list_p->sg_id, SCR_IN_PROGRESS_PHB);
            if (result < 0)
            {
                mmi_phb_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);
            }
            else
            {   
                mmi_phb_popup_display_ext(STR_GLOBAL_REMOVED, MMI_EVENT_SUCCESS);
            }
            mmi_phb_mem_free(data);
            break;

        case MMI_PHB_GRP_MEM_OP_MOVE:
            if (result >= 0)
            {
                data->finished = MMI_TRUE;
                data->op = MMI_PHB_GRP_MEM_OP_ADD;
                add_member_req.id_array = &(group_data->member.member_list[group_data->member.hilite_index]);
                add_member_req.entry_count = 1;
                add_member_req.group_id = group_data->member.dest_group_id;
                add_member_req.cb = mmi_phb_entry_member_cb;
                add_member_req.is_reset = MMI_FALSE;
                add_member_req.user_data = data;
                srv_phb_add_group_members(&add_member_req);
            }
            else
            {
                mmi_frm_scrn_close(g_mmi_phb_list_p->sg_id, SCR_IN_PROGRESS_PHB);
                mmi_phb_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);
                mmi_phb_mem_free(data);
            }

        default:
            break;
   }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_member_list_option_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_member_list_option_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    mmi_id select_contact_id;
    srv_phb_group_info_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


	#ifndef __MMI_MAINLCD_96X64__
	is_from_group_add_member=MMI_TRUE;
	#endif

	
	group_data->member.memeber_op = MMI_PHB_GRP_MEM_OP_ADD;
    
    select_contact_id = cui_phb_list_select_contact_create(GRP_ID_PHB_GROUP);

    #ifndef __MMI_PHB_UI_IN_TABS__
        srv_phb_get_group_info(group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1], &group_info);
    #else
        srv_phb_get_group_info(g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1], &group_info);
    #endif 
    cui_phb_list_select_contact_set_storage(select_contact_id, group_info.storage);

    cui_phb_list_select_contact_set_group(
        select_contact_id,
    #ifndef __MMI_PHB_UI_IN_TABS__
        group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1],
    #else
        g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1],
    #endif
        MMI_FALSE);
    
    cui_phb_list_select_contact_run(select_contact_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_member_list_option_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_member_list_option_remove(mmi_phb_group_member_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    mmi_phb_group_member_data_struct *member_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    member_data = (mmi_phb_group_member_data_struct*)mmi_phb_mem_malloc(sizeof(mmi_phb_group_member_data_struct), SRV_PHB_MEMORY_TYPE_CTR);
    member_data->op = op;
    member_data->count = 1;

    mmi_phb_show_in_progress(g_mmi_phb_list_p->sg_id, STR_GLOBAL_PLEASE_WAIT);
    srv_phb_remove_group_member(
        group_data->member.member_list[group_data->member.hilite_index],
    #ifndef __MMI_PHB_UI_IN_TABS__
        group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1],
    #else
        g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1],
    #endif
        mmi_phb_entry_member_cb,
        member_data);

    group_data->member.member_count--;
    group_data->member.refresh = MMI_TRUE;
    group_data->member.active_store_index = MMI_PHB_PHONE_ENTRIES + 1;
}


#ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_move_op
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_move_op(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_show_in_progress(g_mmi_phb_list_p->sg_id, STR_GLOBAL_PLEASE_WAIT);
    mmi_frm_scrn_close(g_mmi_phb_list_p->sg_id, SCR_CALLER_GROUPS_SELECT);
    mmi_phb_group_member_list_option_remove(MMI_PHB_GRP_MEM_OP_MOVE);
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fte_group_list_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tap_type        [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fte_group_move_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_phb_group_move_op();
    }
}
#endif
#endif /* __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_member_list_option_remove_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_member_list_option_remove_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    mmi_phb_group_member_data_struct *member_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    member_data = (mmi_phb_group_member_data_struct*)mmi_phb_mem_malloc(sizeof(mmi_phb_group_member_data_struct), SRV_PHB_MEMORY_TYPE_CTR);
    member_data->op = MMI_PHB_GRP_MEM_OP_REMOVE_ALL;
    member_data->count = group_data->member.member_count;
    
    mmi_phb_show_in_progress(g_mmi_phb_list_p->sg_id, STR_GLOBAL_PLEASE_WAIT);
    srv_phb_remove_all_group_members(
    #ifndef __MMI_PHB_UI_IN_TABS__
        group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1],
    #else
        g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1],
    #endif
        mmi_phb_entry_member_cb,
        member_data);

    group_data->member.member_count = 0;
    group_data->member.refresh = MMI_TRUE;
    group_data->member.active_store_index = MMI_PHB_PHONE_ENTRIES + 1;
}
#endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */


#ifdef __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
static S32 mmi_phb_group_select_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PHB_UI_IN_TABS__
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
#endif
    S32 index;
    srv_phb_group_info_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < data_size; index++)
    {
    #ifndef __MMI_PHB_UI_IN_TABS__
        if (!srv_phb_get_group_info(group_data->main_list.group_array[item_index + index], &group_info))
    #else
        if (!srv_phb_get_group_info(g_mmi_phb_group_list_tab.group_array[item_index + index], &group_info))
    #endif
        {
            mmi_wcsncpy(menu_data[index].item_list[0], group_info.group_name, MAX_SUBMENU_CHARACTERS);
            mmi_phb_group_get_item_image(group_info.storage, &menu_data[index].image_list[0], &menu_data[index].image_list[1]);
        }
        else
        {
            menu_data[index].item_list[0] = NULL;
            menu_data[index].image_list[0] = NULL;
        }
    }
    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_select_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PHB_UI_IN_TABS__
    group_data->member.dest_group_id = group_data->main_list.group_array[index];
#else
    group_data->member.dest_group_id = g_mmi_phb_group_list_tab.group_array[index];
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_select_list_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PHB_UI_IN_TABS__
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*)mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PHB_UI_IN_TABS__
    mmi_phb_mem_free(group_data->main_list.group_array);
#else
    mmi_phb_mem_free(g_mmi_phb_group_list_tab.group_array);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_member_list_option_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_member_list_option_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*)mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    U16 group_count;
    U8 *gui_buffer;
    srv_phb_group_info_struct group_info;
    U8 group_id_list[MMI_PHB_GROUP_COUNT];
    U32 i;
    U32 j = 0;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_data->member.memeber_op = MMI_PHB_GRP_MEM_OP_MS_MOVE;
    
    if (mmi_frm_scrn_enter(
	    	g_mmi_phb_list_p->sg_id,
	    	SCR_CALLER_GROUPS_SELECT,
	    	mmi_phb_group_select_list_exit,
	    	mmi_phb_group_member_list_option_move,
	    	MMI_FRM_UNKNOW_SCRN))
	{
	    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
	    RegisterHighlightHandler(mmi_phb_group_select_list_highlight_hdlr);
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        
    #ifndef __MMI_PHB_UI_IN_TABS__
        srv_phb_get_group_info(group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1], &group_info);
        group_data->main_list.group_array = (U8*)mmi_phb_mem_malloc(sizeof(U8) * MMI_PHB_GROUP_COUNT, SRV_PHB_MEMORY_TYPE_CTR);
        group_count = srv_phb_get_group_list(group_id_list, NULL, group_info.storage);
        for (i = 0; i < group_count; i++)
        {
            if (group_id_list[i] != group_data->main_list.group_id_list[group_data->main_list.hilite_index - 1])
            {   
                group_data->main_list.group_array[j] = group_id_list[i];
                j++;
            }
        }
    #else
        srv_phb_get_group_info(g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1], &group_info);
        g_mmi_phb_group_list_tab.group_array = (U8*)mmi_phb_mem_malloc(sizeof(U8) * MMI_PHB_GROUP_COUNT, SRV_PHB_MEMORY_TYPE_CTR);
        group_count = srv_phb_get_group_list(group_id_list, NULL, group_info.storage);
        for (i = 0; i < group_count; i++)
        {
            if (group_id_list[i] != g_mmi_phb_group_list_tab.group_id_list[g_mmi_phb_group_list_tab.hilite_index - 1])
            {   
                g_mmi_phb_group_list_tab.group_array[j] = group_id_list[i];
                j++;
            }
        }
    #endif

    #ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
	    wgui_cat1032_show(
	            (WCHAR*) GetString(STR_ID_PHB_USIM_MOVE),
	            (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
	            (WCHAR*) GetString(STR_GLOBAL_SELECT),
	            (PU8) GetImage(IMG_GLOBAL_OK),
	            (WCHAR*) GetString(STR_GLOBAL_BACK),
	            (PU8) GetImage(IMG_GLOBAL_BACK),
	            group_count - 1,
	            mmi_phb_group_select_list_get_item,
	            NULL,
	            0,
	            0,    
	            IMG_GLOBAL_L1,
	            IMG_STORAGE_SIM,
	            gui_buffer,
	            NULL);
    #else
        wgui_cat1032_show(
	            (WCHAR*) GetString(STR_ID_PHB_USIM_MOVE),
	            (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
	            (WCHAR*) GetString(STR_GLOBAL_SELECT),
	            (PU8) GetImage(IMG_GLOBAL_OK),
	            (WCHAR*) GetString(STR_GLOBAL_BACK),
	            (PU8) GetImage(IMG_GLOBAL_BACK),
	            group_count - 1,
	            mmi_phb_group_select_list_get_item,
	            NULL,
	            0,
	            0,    
	            IMG_GLOBAL_L1,
	            0,
	            gui_buffer,
	            NULL);
    #endif

    #if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
	SetLeftSoftkeyFunction(mmi_phb_group_ms_move_confirm, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_phb_group_ms_move_confirm, KEY_EVENT_UP);
    #else
        SetLeftSoftkeyFunction(mmi_phb_group_move_op, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_phb_group_move_op, KEY_EVENT_UP);
    #endif
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    #if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
	wgui_register_tap_callback(mmi_phb_fte_group_ms_move_tap_callback);
    #else
        wgui_register_tap_callback(mmi_phb_fte_group_move_tap_callback);
    #endif
    #endif
    }
}
#endif


#define MMI_PHB_GROUP_SEND_MESSAGE
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_message_go_back_histoty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_send_message_go_back_histoty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_data->member.address_type != NULL)
    {
        OslMfree(group_data->member.address_type);
        group_data->member.address_type = NULL;
    }

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_message_go_back_histoty_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  group_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_group_send_message_go_back_histoty_ext(MMI_ID group_id)
{
    mmi_phb_group_send_message_go_back_histoty();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_message_get_member_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  max_count       [IN]        
 *  filter_type     [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phb_group_send_message_get_member_count(U16 max_count, U16 filter_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    U16 member_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    member_count = mmi_phb_group_get_member_count(filter_type);

    MMI_PHB_LOG2(TRC_MMI_PHB_GROUP_FILTER_FOR_SEND_MESSAGE, filter_type, member_count);

    if (member_count > max_count)
    {
        group_data->member.member_count = max_count;
        return MMI_TRUE;
    }
    else
    {
        group_data->member.member_count = member_count;
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_message_get_address_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  type        [IN]        
 * RETURNS
 *  number pointer
 *****************************************************************************/
static U8 *mmi_phb_group_send_message_get_address_callback(U16 index, U16 *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);
    U8 num_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG3(
        TRC_MMI_PHB_GROUP_SEND_MMS_GET_ADDRESS_CALLBACK,
        index,
        group_data->member.member_count,
        group_data->member.address_type);
    
    switch (group_data->member.address_type[index])
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case (U16)SRV_PHB_ENTRY_FIELD_EMAIL1:
            *type = MMI_PHB_ADDRESS_TYPE_EMAIL;
            srv_phb_get_email_address(
                group_data->member.member_list[index],
                group_data->member.address_buffer,
                MMI_PHB_EMAIL_LENGTH);
            return (U8*)group_data->member.address_buffer;
            
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__) 
        case (U16)SRV_PHB_ENTRY_FIELD_EMAIL2:
            *type = MMI_PHB_ADDRESS_TYPE_EMAIL;
            srv_phb_get_email_address2(
                group_data->member.member_list[index],
                group_data->member.address_buffer,
                MMI_PHB_EMAIL_LENGTH);
            return (U8*)group_data->member.address_buffer;
    #endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    #endif

        case (U16)SRV_PHB_ENTRY_FIELD_NUMBER:
            num_index = 0;
            break;

        case (U8)SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
            num_index = 1;
            break;

        case (U16)SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
            num_index = 2;
            break;

        case (U16)SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
            num_index = 3;
            break;

        default:
            break;
    }

    *type = MMI_PHB_ADDRESS_TYPE_NUMBER;

    srv_phb_get_number_ex(
        group_data->member.member_list[index],
        num_index,
        group_data->member.address_buffer,
        NULL,
        MMI_PHB_NUMBER_PLUS_LENGTH);

    return (U8*)group_data->member.address_buffer;
}


#ifdef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_group_send_uc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_pre_entry_group_send_uc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 max_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_PRE_ENTRY_GROUP_SEND_UC);

    if (IsMessagesReEntering())
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
    }
    else
    {
        max_count = wap_custom_get_max_mms_address();

        if (mmi_phb_group_send_message_get_member_count(max_count, SRV_PHB_ENTRY_FIELD_MMS))
        {
            mmi_phb_continue_send_multi_message_confirm(
                max_count,
                mmi_phb_group_send_uc_choose_address,
                mmi_phb_group_send_message_go_back_histoty_ext,
                GRP_ID_PHB_GROUP);
        }
        else
        {
            mmi_phb_group_send_uc_choose_address(GRP_ID_PHB_GROUP);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_uc_choose_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_send_uc_choose_address(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_GROUP_SEND_UC_CHOOSE_ADDRESS);

    if (group_data->member.member_count)
    {
        group_data->member.address_type = OslMalloc(group_data->member.member_count * 2);
        group_data->member.active_index = 0;
        mmi_phb_entry_group_send_uc_choose_address();
    }
    else
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_NO_NUMBER,
            MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_send_uc_choose_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_send_uc_choose_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_ENTRY_GROUP_SEND_UC_CHOOSE_ADDRESS);

    mmi_phb_entry_choose_field(
        GRP_ID_PHB_GROUP,
        group_data->member.member_list[group_data->member.active_index],
        SRV_PHB_ENTRY_FIELD_MMS,
        mmi_phb_entry_group_send_uc_choose_address,
        mmi_phb_group_send_uc_choose_address_more,
        mmi_phb_group_send_message_go_back_histoty,
        NULL,
        MMI_FALSE,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_uc_choose_address_more
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_send_uc_choose_address_more(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG2(
        TRC_MMI_PHB_GROUP_SEND_UC_CHOOSE_ADDRESS_MORE,
        group_data->member.active_index,
        group_data->member.member_count);

    group_data->member.address_type[group_data->member.active_index++]
        = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];

    mmi_frm_scrn_enter(GRP_ID_PHB_GROUP, GLOBAL_SCR_DUMMY, NULL, NULL, MMI_FRM_UNKNOW_SCRN);
    mmi_frm_scrn_close(GRP_ID_PHB_GROUP, SCR_CHOOSE_NUMBER);

    if (group_data->member.active_index < group_data->member.member_count)
    {
        mmi_phb_entry_group_send_uc_choose_address();
    }
    else
    {
        mmi_phb_entry_group_send_uc();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_send_uc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_send_uc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_entry_write_struct data = {0,};
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_ENTRY_GROUP_SEND_UC);

    data.addr_num = (U8) group_data->member.member_count;
    data.get_address_callback = (uc_func_ptr_general_insert_get_addr_fn) mmi_phb_group_send_message_get_address_callback;
    data.addr = NULL;
    data.msg_type = MMI_UC_MSG_TYPE_DEFAULT;

    mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);

    if (group_data->member.address_type != NULL)
    {
        OslMfree(group_data->member.address_type);
        group_data->member.address_type = NULL;
    }
}


#else /* __MMI_UNIFIED_COMPOSER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_group_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_pre_entry_group_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 max_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_PRE_ENTRY_GROUP_SEND_SMS);

    if (mmi_sms_is_reenter_message())
    {
        return;
    }

    max_count = mmi_sms_get_max_recipient_num();

    if (mmi_phb_group_send_message_get_member_count(max_count, SRV_PHB_ENTRY_FIELD_GSM_NUM))
    {
        mmi_phb_continue_send_multi_message_confirm(
            max_count,
            mmi_phb_group_send_sms_choose_address,
            mmi_phb_group_send_message_go_back_histoty_ext,
            GRP_ID_PHB_GROUP);
    }
    else
    {
        mmi_phb_group_send_sms_choose_address(GRP_ID_PHB_GROUP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_sms_choose_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_send_sms_choose_address(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_data->member.member_count)
    {
        group_data->member.address_type = OslMalloc(group_data->member.member_count * 2);
        group_data->member.active_index = 0;
        mmi_phb_entry_group_send_sms_choose_address();
    }
    else
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_NO_NUMBER,
            MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_send_sms_choose_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_send_sms_choose_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        GRP_ID_PHB_GROUP,
        group_data->member.member_list[group_data->member.active_index],
        SRV_PHB_ENTRY_FIELD_GSM_NUM,
        mmi_phb_entry_group_send_sms_choose_address,
        mmi_phb_group_send_sms_choose_address_more,
        mmi_phb_group_send_message_go_back_histoty,
        NULL,
        MMI_FALSE,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_sms_choose_address_more
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_send_sms_choose_address_more(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG2(
        TRC_MMI_PHB_GROUP_SEND_UC_CHOOSE_ADDRESS_MORE,
        group_data->member.active_index,
        group_data->member.member_count);

    group_data->member.address_type[group_data->member.active_index++]
        = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];

    mmi_frm_scrn_enter(GRP_ID_PHB_GROUP, GLOBAL_SCR_DUMMY, NULL, NULL, MMI_FRM_UNKNOW_SCRN);
    mmi_frm_scrn_close(GRP_ID_PHB_GROUP, SCR_CHOOSE_NUMBER);

    if (group_data->member.active_index < group_data->member.member_count)
    {
        mmi_phb_entry_group_send_sms_choose_address();
    }
    else
    {
        mmi_phb_entry_group_send_sms(GRP_ID_PHB_GROUP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_send_sms(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_ENTRY_GROUP_SEND_SMS);

    if (group_data->member.member_count)
    {
        mmi_sms_entry_write_msg_from_phb(
            group_data->member.member_count,
            (void*)mmi_phb_group_send_message_get_address_callback);
    }
    else
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_NO_NUMBER,
            MMI_EVENT_FAILURE);
    }
}


#if defined(__MMI_MMS__) && defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_group_send_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_pre_entry_group_send_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 max_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_PRE_ENTRY_GROUP_SEND_MMS);

    if (IsMessagesReEntering())
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
    }
    else
    {
        max_count = (U16) wap_custom_get_max_mms_address();

        if (mmi_phb_group_send_message_get_member_count(max_count, SRV_PHB_ENTRY_FIELD_MMS))
        {
            mmi_phb_continue_send_multi_message_confirm(
                max_count,
                mmi_phb_group_send_mms_choose_address,
                mmi_phb_group_send_message_go_back_histoty_ext,
                GRP_ID_PHB_GROUP);
        }
        else
        {
            mmi_phb_group_send_mms_choose_address(GRP_ID_PHB_GROUP);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_mms_choose_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_send_mms_choose_address(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_data->member.member_count)
    {
        group_data->member.address_type = OslMalloc(group_data->member.member_count * 2);
        group_data->member.active_index = 0;
        mmi_phb_entry_group_send_mms_choose_address();
    }
    else
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_NO_NUMBER,
            MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_send_mms_choose_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_group_send_mms_choose_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_ENTRY_GROUP_SEND_MMS_CHOOSE_ADDRESS);

    mmi_phb_entry_choose_field(
        GRP_ID_PHB_GROUP,
        group_data->member.member_list[group_data->member.active_index],
        SRV_PHB_ENTRY_FIELD_MMS,
        mmi_phb_entry_group_send_mms_choose_address,
        mmi_phb_group_send_mms_choose_address_more,
        mmi_phb_group_send_message_go_back_histoty,
        NULL,
        MMI_FALSE,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_mms_choose_address_more
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_send_mms_choose_address_more(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_GROUP_SEND_MMS_CHOOSE_ADDRESS_MORE);

    group_data->member.address_type[group_data->member.active_index++]
        = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];

    mmi_frm_scrn_enter(GRP_ID_PHB_GROUP, GLOBAL_SCR_DUMMY, NULL, NULL, MMI_FRM_UNKNOW_SCRN);
    mmi_frm_scrn_close(GRP_ID_PHB_GROUP, SCR_CHOOSE_NUMBER);

    if (group_data->member.active_index < group_data->member.member_count)
    {
        mmi_phb_entry_group_send_mms_choose_address();
    }
    else
    {
        mmi_phb_group_send_mms_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_mms_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_send_mms_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_multi_object_insert_req_struct *local_buffer;
    peer_buff_struct *peer_buffer;
    U16 start_index, end_index;
    U8 *peer_pdu;
    U16 peer_pdu_len;
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_GROUP_SEND_MMS_REQ);

    local_buffer =
        (mms_multi_object_insert_req_struct*) OslConstructDataPtr(sizeof(mms_multi_object_insert_req_struct));
    local_buffer->request_id = mma_get_request_id();

    start_index = 0;
    if (group_data->member.member_count > MAX_MMS_OBJECT)
    {
        end_index = MAX_MMS_OBJECT;
        group_data->member.active_index = end_index;
        local_buffer->more = MMI_TRUE;
    }
    else
    {
        end_index = group_data->member.member_count;
        group_data->member.active_index = end_index;
        local_buffer->more = MMI_FALSE;
    }

    local_buffer->num_of_object = end_index - start_index;

    peer_pdu_len = local_buffer->num_of_object * sizeof(mms_multi_object_struct);
    peer_buffer = construct_peer_buff(peer_pdu_len, 0, 0, TD_CTRL);
    peer_pdu = (U8*) get_peer_buff_pdu(peer_buffer, &peer_pdu_len);

    mmi_phb_group_send_mms_prepare_buffer(start_index, end_index, peer_pdu);

    SetProtocolEventHandler(mmi_phb_group_send_mms_rsp, MSG_ID_MMS_MULTI_OBJECT_INSERT_RSP);
    mmi_frm_send_ilm(
        mms_get_service_module(MSG_ID_MMS_MULTI_OBJECT_INSERT_REQ),
        MSG_ID_MMS_MULTI_OBJECT_INSERT_REQ,
        (oslParaType*) local_buffer,
        (peer_buff_struct*) peer_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_mms_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_send_mms_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_multi_object_insert_rsp_struct *local_buffer;
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_GROUP_SEND_MMS_RSP);

    local_buffer = (mms_multi_object_insert_rsp_struct*) info;
    if (local_buffer->result && group_data->member.active_index < group_data->member.member_count)
    {
        mmi_phb_group_send_mms_insert_more_ind(local_buffer->request_id);
    }
    else
    {
        if (group_data->member.address_type != NULL)
        {
            OslMfree(group_data->member.address_type);
            group_data->member.address_type = NULL;
        }

        mmi_frm_group_close(GRP_ID_PHB_GROUP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_mms_insert_more_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_send_mms_insert_more_ind(U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_multi_object_insert_continue_ind_struct *local_buffer;
    peer_buff_struct *peer_buffer;
    U16 start_index, end_index;
    U8 *peer_pdu;
    U16 peer_pdu_len;
    mmi_phb_group_cntx_struct *group_data = (mmi_phb_group_cntx_struct*) mmi_frm_group_get_user_data(GRP_ID_PHB_GROUP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_GROUP_SEND_MMS_INSERT_MORE_IND);

    local_buffer =
        (mms_multi_object_insert_continue_ind_struct*) OslConstructDataPtr(sizeof(mms_multi_object_insert_continue_ind_struct));
    local_buffer->request_id = req_id;
    local_buffer->is_aborted = MMI_FALSE;

    start_index = group_data->member.active_index;
    if (group_data->member.member_count > start_index + MAX_MMS_OBJECT)
    {
        end_index = start_index + MAX_MMS_OBJECT;
        group_data->member.active_index = end_index;
        local_buffer->more = MMI_TRUE;
    }
    else
    {
        end_index = group_data->member.member_count;
        group_data->member.active_index = end_index;
        local_buffer->more = MMI_FALSE;
    }

    local_buffer->num_of_object = end_index - start_index;

    peer_pdu_len = local_buffer->num_of_object * sizeof(mms_multi_object_struct);
    peer_buffer = construct_peer_buff(peer_pdu_len, 0, 0, TD_CTRL);
    peer_pdu = (U8*) get_peer_buff_pdu(peer_buffer, &peer_pdu_len);

    mmi_phb_group_send_mms_prepare_buffer(start_index, end_index, peer_pdu);

    SetProtocolEventHandler(mmi_phb_group_send_mms_rsp, MSG_ID_MMS_MULTI_OBJECT_INSERT_CONTINUE_RES);

    mmi_frm_send_ilm(
        mms_get_service_module(MSG_ID_MMS_MULTI_OBJECT_INSERT_CONTINUE_IND),
        MSG_ID_MMS_MULTI_OBJECT_INSERT_CONTINUE_IND,
        (oslParaType*) local_buffer,
        (peer_buff_struct*) peer_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_send_mms_prepare_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index     [IN]        
 *  end_index       [IN]        
 *  buffer          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_group_send_mms_prepare_buffer(U16 start_index, U16 end_index, void *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j = 0;
    U8 *ucs2_address;
    mms_multi_object_struct *peer_buffer;
    U16 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_GROUP_SEND_MMS_PREPARE_BUFFER);

    peer_buffer = (mms_multi_object_struct*) buffer;
    for (i = start_index; i < end_index; i++)
    {
        ucs2_address = mmi_phb_group_send_message_get_address_callback(i, &type);
        peer_buffer[j].type = (U32) type;
        mmi_ucs2_to_asc((CHAR*) (peer_buffer[j++].object), (CHAR*) ucs2_address);
    }
}
#endif /* defined(__MMI_MMS__) && defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__) */

#endif /* __MMI_UNIFIED_COMPOSER__ */


/*
 * Global Function
 */






#ifdef __MMI_PHB_UI_IN_TABS__


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_list_tab
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_group_list_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_caller_group();
}

#else /* __MMI_PHB_UI_IN_TABS__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_list_non_tab
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_group_list_non_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_caller_group();
}

#endif /* __MMI_PHB_UI_IN_TABS__ */

#endif /* __MMI_PHB_CALLER_GROUP__ */

#endif /* PHONEBOOKGROUP_C */

