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
 *  CbsAppMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CBS(Cell Broadcast Service) Application Main UI
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!

 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_TELEPHONY_SUPPORT__
#ifdef __MMI_CBS_SUPPORT__

/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "stdlib.h"
#include "string.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "kal_general_types.h"
#include "nvram_common_defs.h"
#include "l3_inc_enums.h"
#include "ps_public_enum.h"
#include "gui_data_types.h"
#include "ImeGprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "CustDataRes.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "Unicodexdcl.h"
#include "NetSetSrvGprot.h"

#include "SmsSrvGprot.h"
#include "AlertScreen.h"

#include "CbsSrvGprot.h"
#include "mmi_rp_app_cbs_def.h"
#include "mmi_rp_app_sms_def.h"
#include "MenuCuiGprot.h"
#include "InlineCuiGprot.h"
#include "SmsAppProt.h"
#include "CbsAppProt.h"
#include "SimCtrlSrvGprot.h"
#include "CphsSrvGprot.h"
#include "NetSetAppGprot.h"
#include "ModeSwitchsrvGprot.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#endif /* __MMI_DUAL_SIM_MASTER__ */
#include "mmi_frm_utility_gprot.h"
#pragma diag_remark 188

/**************************************************************
* MARCO
**************************************************************/
#define MAX_CBS_MAIN_MENU_ITEM_NUM      4
#define MAX_MODE_MENU_ITEM_NUM          2
#define MAX_CHNL_MENU_ITEM_NUM          5
#define CBS_CHNL_NUMBER_EDIT_LEN        3       /* 0 - 999 */
#define CBS_CHNL_NUMBER_DISP_LEN        5       /* 0 - 0xFFFF (0 - 65535) */
#define CBS_CHNL_INLINE_ITME_NUM        4

#define MENU_ID_CBS_ALL_LANGS           SRV_CBS_MAX_LANG_NUM
#define SCR_ID_CBS_NONE                 0


/**************************************************************
* Structure Declaration
**************************************************************/
typedef enum
{
    CBS_ACTION_NONE,
    CBS_ACTION_SUBSCRIBE,
    CBS_ACTION_ADD_CHNL,
    CBS_ACTION_SELECT_CHNL,
    CBS_ACTION_EDIT_CHNL,
    CBS_ACTION_DELETE_CHNL,
    CBS_ACTION_SELECT_LANG,

    CBS_ACTION_TOTAL,
} mmi_cbs_action_enum;

typedef struct
{
    MMI_MENU_ID root_menu_id;
} cbs_menu_cui_struct;

typedef struct
{
    MMI_BOOL mode;
    MMI_BOOL is_first_enter;
    MMI_ID menu_gid;
} mmi_cbs_mode_struct;

typedef struct
{
    srv_cbs_channel_struct chnl_data;
    WCHAR name[SRV_CBS_CHNL_NAME_LEN + 1];
    WCHAR number[CBS_CHNL_NUMBER_DISP_LEN + 1];
    U16 chnl_id;
    MMI_BOOL mask;
    MMI_ID inline_gid;
    MMI_ID menu_gid;
} mmi_cbs_chnl_struct;

typedef struct
{
    U8 check_state[SRV_CBS_MAX_LANG_NUM + 1];
    srv_cbs_language_struct info;
    MMI_ID menu_gid;
} mmi_cbs_lang_struct;

typedef struct
{
    MMI_ID owner_gid;
    srv_sms_sim_enum sim_id;

    MMI_BOOL is_deinit;
    MMI_BOOL mode;

    void *curr_stamp;

    S32 curr_idnex;

    U16 curr_scrn_id;
    mmi_cbs_action_enum curr_action;

    mmi_cbs_mode_struct *mode_info;
    mmi_cbs_lang_struct *lang_info;
    mmi_cbs_chnl_struct *chnl_info;
} cbs_app_cntx_struct;

typedef struct
{
    cbs_app_cntx_struct *cb_cntx;
} cbs_action_stamp_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/

/**************************************************************
* Static Variables Defination
**************************************************************/
static void mmi_cbs_entry_menu(
                MMI_ID parent_gid,
                cui_menu_src_type_enum src_type,
                cui_menu_type_enum menu_type,
                MMI_MENU_ID root_menu_id);
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
static void mmi_cbs_entry_main(cbs_app_cntx_struct *cb_cntx);

static mmi_ret mmi_cbs_group_proc(mmi_event_struct* evt);
static void mmi_cbs_group_deinit(cbs_app_cntx_struct *cb_cntx);
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
static mmi_ret mmi_cbs_main_menu_proc(cui_menu_event_struct* menu_evt);
static mmi_ret mmi_cbs_receive_mode_menu_proc(cui_menu_event_struct* menu_evt);
static mmi_ret mmi_cbs_lang_menu_proc(cui_menu_event_struct* menu_evt);
static mmi_ret mmi_cbs_chnl_option_menu_proc(cui_menu_event_struct* menu_evt);
static mmi_ret mmi_cbs_chnl_inline_edit_proc(cui_event_inline_common_struct *inline_evt);

static void mmi_cbs_entry_receive_mode(cbs_app_cntx_struct *cb_cntx);
static void mmi_cbs_delete_chnl(void);

static void mmi_cbs_entry_chnl(cbs_app_cntx_struct *cb_cntx);
static void mmi_cbs_entry_chnl_int(mmi_scrn_essential_struct* scrn_data);
static void mmi_cbs_refresh_chnl_list(cbs_app_cntx_struct* cb_cntx);

static void mmi_cbs_get_curr_index(S32 index);
static S32 mmi_cbs_chnl_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size);

static S32 mmi_cbs_chnl_get_hint(S32 item_index, UI_string_type *hint_array);

static void mmi_cbs_chnl_csk_hdlr(void);
static void mmi_cbs_entry_chnl_options(void);
static void mmi_cbs_entry_chnls_edit(cbs_app_cntx_struct *cb_cntx);

static void mmi_cbs_entry_lang(cbs_app_cntx_struct *cb_cntx);

static void mmi_cbs_save_edit_chnl(void);
static void mmi_cbs_select_lang(void);

static void mmi_cbs_init_app_cntx(
                cbs_app_cntx_struct *cb_cntx,
                MMI_ID owner_gid);
static void mmi_cbs_set_new_scrn(cbs_app_cntx_struct *cb_cntx, U16 scrn_id);

static void mmi_cbs_submit_action(
                cbs_app_cntx_struct *cb_cntx,
                mmi_cbs_action_enum action);
static void mmi_cbs_submit_action_callback(srv_sms_callback_struct* callback_data);

static void mmi_cbs_subscribe_hdlr(
                cbs_app_cntx_struct* cb_cntx,
                srv_sms_callback_struct* callback_data);
static void mmi_cbs_select_chnl_hdlr(
                cbs_app_cntx_struct* cb_cntx,
                srv_sms_callback_struct* callback_data);
static void mmi_cbs_add_chnl_hdlr(
                cbs_app_cntx_struct* cb_cntx,
                srv_sms_callback_struct* callback_data);
static void mmi_cbs_edit_chnl_hdlr(
                cbs_app_cntx_struct* cb_cntx,
                srv_sms_callback_struct* callback_data);
static void mmi_cbs_delete_chnl_hdlr(
                cbs_app_cntx_struct* cb_cntx,
                srv_sms_callback_struct* callback_data);
static void mmi_cbs_select_lang_hdlr(
                cbs_app_cntx_struct* cb_cntx,
                srv_sms_callback_struct* callback_data);
static S32 mmi_cbs_add_chnl_entry(
                srv_cbs_channel_struct* chnl_data,
                U16 chnl_id,
                WCHAR* chnl_name,
                MMI_BOOL mask);
static MMI_BOOL mmi_cbs_is_show_cb_menu_ext(mmi_sim_enum sim_id);
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__  
static MMI_BOOL mmi_cbs_is_entry_cb_menu(void);
static MMI_BOOL mmi_cbs_is_entry_cb_menu_ext(mmi_sim_enum sim_id);
static MMI_BOOL mmi_cbs_is_show_sim_select_menu(U32 *sim);
#endif
static void mmi_cbs_show_dummy_screen(void);

static void mmi_cbs_close_menu(
                MMI_ID menu_gid,
                void* app_data);


static mmi_ret mmi_cbs_setting_ready_event_hdlr(mmi_event_struct *evt);
/**************************************************************
* Static Function Declaration
**************************************************************/
static cbs_app_cntx_struct *mmi_cbs_cntx;

static const cui_inline_item_caption_struct chnl_name_caption =
{
    STR_ID_CBS_CHNL_NAME
};
static const cui_inline_item_fullscreen_edit_struct chnl_name_data = 
{
    0,
    0,
    STR_ID_CBS_CHNL_NAME,
    IMG_SMS_ENTRY_SCRN_CAPTION,
    0,
    IMM_INPUT_TYPE_SENTENCE,
    SRV_CBS_CHNL_NAME_LEN + 1,
    NULL
};
static const cui_inline_item_caption_struct chnl_num_caption =
{
    STR_ID_CBS_CHNL_NUMBER
};
static const cui_inline_item_text_edit_struct chnl_num_data = 
{
    0,
    0,
    CBS_CHNL_NUMBER_EDIT_LEN + 1,
    IMM_INPUT_TYPE_NUMERIC,
    0,
    NULL
};
static const cui_inline_set_item_struct chnl_inline_items[CBS_CHNL_INLINE_ITME_NUM] = 
{
    {CUI_INLINE_ITEM_ID_BASE + 0, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_CBS_CHNL_NAME, &chnl_name_caption},
    {CUI_INLINE_ITEM_ID_BASE + 1, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, &chnl_name_data},
    {CUI_INLINE_ITEM_ID_BASE + 2, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_CBS_CHNL_NUMBER, &chnl_num_caption},
    {CUI_INLINE_ITEM_ID_BASE + 3, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &chnl_num_data}
};

static const U16 lang_str_id[SRV_CBS_MAX_LANG_SUPPORT] = 
{
	STR_ID_CBS_LANG_GERMAN,
	STR_ID_CBS_LANG_ENGLISH,
	STR_ID_CBS_LANG_ITALIAN,
	STR_ID_CBS_LANG_FRENCH,
	STR_ID_CBS_LANG_SPANISH,
	STR_ID_CBS_LANG_DUTCH,
	STR_ID_CBS_LANG_SWEDISH,
	STR_ID_CBS_LANG_DANISH,
	STR_ID_CBS_LANG_PORTUGUESE,
	STR_ID_CBS_LANG_FINNISH,
	STR_ID_CBS_LANG_NORWEGIAN,
	STR_ID_CBS_LANG_GREEK,
	STR_ID_CBS_LANG_TURKISH,
	STR_ID_CBS_LANG_HUNGARIAN,
	STR_ID_CBS_LANG_POLISH,
	STR_ID_CBS_LANG_UNSPECIFIED,

	STR_ID_CBS_LANG_CZECH,
	STR_ID_CBS_LANG_HEBREW,
	STR_ID_CBS_LANG_ARABIC,
	STR_ID_CBS_LANG_RUSSIAN,
    STR_ID_CBS_LANG_ICELANDIC,


	STR_ID_CBS_LANG_OTHERS,
	0
};


/**************************************************************
* Function Defination
**************************************************************/
/*****************************************************************************
 * FUNCTION
 *  cui_sms_cbs_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_ID cui_sms_cbs_launch(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID curr_gid = GRP_ID_INVALID;
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    mmi_sim_enum sim = MMI_SIM_NONE;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_CUI_SMS_CBS_LAUNCH);

#if (MMI_MAX_SIM_NUM <2)
    if (!srv_cbs_is_ready(SRV_SMS_SIM_1))
    {
        mmi_cbs_display_common_failure(STR_ID_CBS_NOT_READY_YET);
    }
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__  
    else if(mmi_cbs_is_entry_cb_menu_ext(MMI_SIM1))
    {
        mmi_cbs_display_common_failure(STR_GLOBAL_UNAVAILABLE_SIM);
    }
#endif
    else
#else
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__  
    if(!mmi_cbs_is_entry_cb_menu())
    {
        mmi_cbs_display_common_failure(STR_GLOBAL_INSERT_SIM_CARD);
    }
    else
#endif
#endif
    {
        cbs_app_cntx_struct *cb_cntx;

        cb_cntx = OslMalloc(sizeof(cbs_app_cntx_struct));

        curr_gid = mmi_frm_group_create(
                        parent_gid,
                        GRP_ID_AUTO_GEN,
                        mmi_cbs_group_proc,
                        cb_cntx);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_CUI_SMS_CBS_LAUNCH_1, curr_gid);

        mmi_cbs_init_app_cntx(cb_cntx, curr_gid);
        cb_cntx->mode_info = OslMalloc(sizeof(mmi_cbs_mode_struct));
        cb_cntx->lang_info = OslMalloc(sizeof(mmi_cbs_lang_struct));
        cb_cntx->chnl_info = OslMalloc(sizeof(mmi_cbs_chnl_struct));
        
        mmi_frm_group_enter(curr_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

   #if (MMI_MAX_SIM_NUM >=2) 
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__ 
        if(mmi_cbs_is_show_sim_select_menu((U32*)(&sim)))
        {
#endif
            mmi_cbs_entry_sim_select(cb_cntx);
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__ 
        }
        else
        {
            cb_cntx->sim_id = sim | MMI_GSM;
            mmi_cbs_entry_main(cb_cntx);
        }
#endif
    #else /* __GEMINI__*/
        mmi_cbs_entry_main(cb_cntx);
    #endif /* __GEMINI__ */
    }

    return curr_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_entry_menu(
                MMI_ID parent_gid,
                cui_menu_src_type_enum src_type,
                cui_menu_type_enum menu_type,
                MMI_MENU_ID root_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_MENU, root_menu_id);


    menu_gid = cui_menu_create(
                    parent_gid,
                    src_type,
                    menu_type,
                    root_menu_id,
                    MMI_FALSE,
                    NULL);
#ifndef __MMI_SMS_SLIM__
    cui_menu_set_default_title_image(menu_gid, (UI_image_type)GetImage(IMG_SMS_ENTRY_SCRN_CAPTION));
#endif
    cui_menu_run(menu_gid);
}

static void mmi_cbs_close_menu(
                MMI_ID menu_gid,
                void* app_data)
{
    cui_menu_close(menu_gid);
}

#if (MMI_MAX_SIM_NUM >=2)
/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_sim_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_entry_sim_select(cbs_app_cntx_struct *cb_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_SIM_SELECT);

    mmi_cbs_entry_menu(
        cb_cntx->owner_gid,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPMAIN,
        MENU_ID_CBS_SIM_SELECT);
}
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_entry_main(cbs_app_cntx_struct *cb_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id = cb_cntx->sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_MAIN, sim_id);

#if (MMI_MAX_SIM_NUM >=2)
    if (!srv_cbs_is_ready(sim_id))
    {
        mmi_cbs_display_common_failure(STR_ID_CBS_NOT_READY_YET);
    }
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__  
    else if(!srv_sim_ctrl_is_available(sim_id & (~MMI_GSM)))
    {
        mmi_cbs_display_common_failure(STR_GLOBAL_UNAVAILABLE_SIM);//dynamic sim skyfyx  check the string
    }
#endif
    else
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        cb_cntx->mode = srv_cbs_get_receive_mode(sim_id);

        mmi_cbs_entry_menu(
            cb_cntx->owner_gid,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_APPMAIN,
            MENU_ID_CBS_MAIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_receive_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_entry_receive_mode(cbs_app_cntx_struct *cb_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cbs_mode_struct *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_RECEIVE_MODE);

    info = cb_cntx->mode_info;

    info->mode = cb_cntx->mode;
    info->is_first_enter = MMI_TRUE;

    mmi_cbs_entry_menu(
        cb_cntx->owner_gid,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPSUB,
        MENU_ID_CBS_RECEIVE_MODE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_chnl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_entry_chnl(cbs_app_cntx_struct *cb_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cbs_chnl_struct *chnl_info;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_CHNL);

    chnl_info = cb_cntx->chnl_info;

    result = srv_cbs_get_channel(&chnl_info->chnl_data, cb_cntx->sim_id);

    if (result)
    {
        cb_cntx->curr_idnex = 0;
        mmi_cbs_set_new_scrn(cb_cntx, SCR_ID_CBS_CHNL_LIST);
        mmi_frm_scrn_first_enter(
            cb_cntx->owner_gid,
            SCR_ID_CBS_CHNL_LIST,
            (FuncPtr)mmi_cbs_entry_chnl_int,
            cb_cntx);

    }
    else
    {
        mmi_cbs_display_common_not_finished();
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_chnl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_entry_chnl_int(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_frm_scrn_enter(
                scrn_data->group_id, 
                scrn_data->scrn_id,
                NULL,
                (FuncPtr)mmi_cbs_entry_chnl_int,
                MMI_FRM_FULL_SCRN);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_CHNL_INT, result);

    if (result)
    {
        U8 *gui_buffer = NULL;
        S32 hilite_item = 0;
        S32 total_item;
        if (srv_cbs_get_channel(&mmi_cbs_cntx->chnl_info->chnl_data, mmi_cbs_cntx->sim_id))
        {
            total_item = mmi_cbs_cntx->chnl_info->chnl_data.total;
        }
        else
        {
            total_item =  0;
        }

        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        if (gui_buffer != NULL)
        {
            list_menu_category_history *h;
    
            hilite_item = (mmi_cbs_cntx->curr_idnex < total_item) ? mmi_cbs_cntx->curr_idnex : total_item;
            h = (list_menu_category_history*)gui_buffer;
            h->highlighted_item = (S16)hilite_item;
        }

        RegisterHighlightHandler(mmi_cbs_get_curr_index);

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        wgui_cat1032_show(
            (WCHAR*)GetString(STR_ID_CBS_CHANNELS),
            (PU8)GetImage(IMG_SMS_ENTRY_SCRN_CAPTION),
            (WCHAR*)GetString(STR_GLOBAL_OPTIONS),
            (PU8)GetImage(IMG_GLOBAL_OPTIONS),
            (WCHAR*)GetString(STR_GLOBAL_BACK),
            (PU8)GetImage(IMG_GLOBAL_BACK),
            total_item,
            mmi_cbs_chnl_get_item,
            mmi_cbs_chnl_get_hint,
            hilite_item,
            0,
            IMG_ID_CBS_SUBSCRIBE,
            0,
            gui_buffer,
            NULL);

        SetCenterSoftkeyFunction(mmi_cbs_chnl_csk_hdlr, KEY_EVENT_UP);

        SetLeftSoftkeyFunction(mmi_cbs_entry_chnl_options, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_refresh_chnl_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_refresh_chnl_list(cbs_app_cntx_struct* cb_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_item = cb_cntx->chnl_info->chnl_data.total;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_REFRESH_CHNL_LIST, total_item);
	if (mmi_frm_scrn_get_active_id() == SCR_ID_CBS_CHNL_LIST)
	{
	    mmi_cat_refresh_asyncdynamic_list(total_item, cb_cntx->curr_idnex, mmi_cbs_chnl_get_item, mmi_cbs_chnl_get_hint);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_get_curr_index
 * DESCRIPTION
 *  Get current highlight index
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cbs_get_curr_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cbs_cntx->curr_idnex = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_chnl_get_item
 * DESCRIPTION
 *  Get CB channel list item
 * PARAMETERS
 *  item_index          [IN]            
 *  str_buff            [IN]            
 *  img_buff_p          [?]             
 *  str_img_mask        [IN]            
 *  a(?)                [IN]            Item index
 *  d(?)                [IN/OUT]        String image mask
 *  c(?)                [IN/OUT]        Image buffer
 *  b(?)                [IN/OUT]        String buffer
 * RETURNS
 * TRUE
 *****************************************************************************/
static S32 mmi_cbs_chnl_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_chnl_entry_struct *chnl_entry;
    srv_cbs_channel_struct *chnl_data = &mmi_cbs_cntx->chnl_info->chnl_data;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_size >= (S32)chnl_data->total)
    {
        data_size = (S32)chnl_data->total;
    }

    for(i = 0;  i < data_size;  i++)
    {
        WCHAR name[SRV_CBS_CHNL_NAME_LEN + 1];
        chnl_entry = &chnl_data->entry[start_index + i];

        if (mmi_wcslen(chnl_entry->name) == 0)
        {
            kal_wsprintf((WCHAR*)name, "%d", chnl_entry->id);
        }
        else
        {
            mmi_wcscpy((WCHAR*)name, chnl_entry->name);
        }
        mmi_ucs2ncpy((CHAR *)menu_data[i].item_list[0], (const CHAR*)name, MAX_SUBMENU_CHARACTERS);
        if (chnl_entry->mask)
        {
            menu_data[i].image_list[0] = get_image(IMG_ID_CBS_SUBSCRIBE);
        }
        else
        {
            menu_data[i].image_list[0] = get_image(IMG_ID_CBS_UNSUBSCRIBE);
        }
    }
    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_chnl_get_hint
 * DESCRIPTION
 *  Get CB channel list hint
 * PARAMETERS
 *  item_index      [IN]            
 *  hint_array      [?]             
 *  a(?)            [IN]            Item index
 *  b(?)            [IN/OUT]        Hint array
 * RETURNS
 *  TRUE: display hint, FALSE: not display hint
 *****************************************************************************/
static S32 mmi_cbs_chnl_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_chnl_entry_struct *chnl_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chnl_entry = &mmi_cbs_cntx->chnl_info->chnl_data.entry[item_index];

    if (mmi_wcslen(chnl_entry->name) == 0)
    {
		return 0;
    }

    kal_wsprintf((WCHAR*)hint_array[0], "%d", chnl_entry->id);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_chnl_csk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_chnl_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cbs_chnl_struct *chnl_info = mmi_cbs_cntx->chnl_info;
    srv_cbs_channel_struct *chnl_data = &chnl_info->chnl_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_CHNL_CSK_HDLR, chnl_data->total);

    if (chnl_data->total > 0)
    {
        chnl_info->menu_gid = GRP_ID_INVALID;
        mmi_cbs_submit_action(mmi_cbs_cntx, CBS_ACTION_SELECT_CHNL);
    }
    else
    {
        chnl_info->name[0] = '\0';
        chnl_info->number[0] = '\0';

        mmi_cbs_set_new_scrn(mmi_cbs_cntx, SCR_ID_CBS_ADD_CHNL);
        mmi_cbs_entry_chnls_edit(mmi_cbs_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_chnl_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_entry_chnl_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_CHNL_OPTIONS);

    mmi_cbs_entry_menu(
        mmi_cbs_cntx->owner_gid,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        MENU_ID_CBS_CHNL_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_chnls_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_entry_chnls_edit(cbs_app_cntx_struct *cb_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct inline_data;
    mmi_cbs_chnl_struct *chnl_info = cb_cntx->chnl_info;
    MMI_ID inline_gid;
#ifdef __MMI_SLIM_IMG_RES__
    MMI_ID icons [4] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0}; 
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_CHNLS_EDIT);

    if (cb_cntx->curr_scrn_id == SCR_ID_CBS_ADD_CHNL)
    {
        inline_data.title = STR_ID_CBS_ADD_CHNL;
    }
    else
    {
        inline_data.title = STR_ID_CBS_EDIT_CHNL;
    } 

    inline_data.items_count = CBS_CHNL_INLINE_ITME_NUM;
    inline_data.title_icon = IMG_SMS_ENTRY_SCRN_CAPTION;
    inline_data.screen_flag = CUI_INLINE_SCREEN_DEFAULT_TEXT;
    inline_data.softkey = NULL;
    inline_data.items = chnl_inline_items;

    inline_gid = cui_inline_create(cb_cntx->owner_gid, &inline_data);

    cb_cntx->chnl_info->inline_gid = inline_gid;

    cui_inline_set_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + 1, chnl_info->name);
    cui_inline_set_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + 3, chnl_info->number);
    
#ifdef __MMI_SLIM_IMG_RES__
    cui_inline_set_icon_list(inline_gid, icons);
#endif
    cui_inline_run (inline_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_pre_delete_chnl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_delete_chnl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_DELETE_CHNL);

    mmi_cbs_show_dummy_screen();
    mmi_cbs_submit_action(mmi_cbs_cntx, CBS_ACTION_DELETE_CHNL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_entry_lang
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_entry_lang(cbs_app_cntx_struct *cb_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cbs_lang_struct *lang_info;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ENTRY_LANG);

    lang_info = cb_cntx->lang_info;

    result = srv_cbs_get_language(&lang_info->info, cb_cntx->sim_id);

    if (result)
    {
        srv_cbs_language_struct *lang_data = &lang_info->info;
        U32 i;
        U8 *check_state = lang_info->check_state;

        check_state[0] = lang_data->is_all_on;

        check_state++;

        for (i = 0; i < lang_data->total; i++)
        {
            *check_state = (U8)lang_data->entry[i].mask;
            check_state++;
        }

        cb_cntx->lang_info = lang_info;

        mmi_cbs_entry_menu(
            cb_cntx->owner_gid,
            CUI_MENU_SRC_TYPE_APPCREATE,
            CUI_MENU_TYPE_APPSUB,
            MENU_ID_CBS_LANGUAGES);
    }
    else
    {
        mmi_cbs_display_common_not_finished();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_save_edit_chnl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_save_edit_chnl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SAVE_EDIT_CHNL);

    if (mmi_wcslen(mmi_cbs_cntx->chnl_info->number) == 0)
    {
        mmi_cbs_display_common_failure(STR_GLOBAL_NO_NUMBER);
    }
    else
    {
        mmi_cbs_show_dummy_screen();

        if (mmi_cbs_cntx->curr_scrn_id == SCR_ID_CBS_ADD_CHNL)
        {
            mmi_cbs_submit_action(mmi_cbs_cntx, CBS_ACTION_ADD_CHNL);
        }
        else
        {
            mmi_cbs_submit_action(mmi_cbs_cntx, CBS_ACTION_EDIT_CHNL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_select_lang
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_select_lang(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_cbs_language_struct *info = &mmi_cbs_cntx->lang_info->info;
    U8 *check_state = mmi_cbs_cntx->lang_info->check_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SELECT_LANG);

    info->is_all_on = (MMI_BOOL)check_state[0];

    for (i = 0; i < info->total; i++)
    {
        info->entry[i].mask = (MMI_BOOL)check_state[i + 1];
    }

    mmi_cbs_show_dummy_screen();

    mmi_cbs_submit_action(mmi_cbs_cntx, CBS_ACTION_SELECT_LANG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_cbs_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    U16 event_id = evt->evt_id;
    cbs_app_cntx_struct *cb_cntx = (cbs_app_cntx_struct*)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_GROUP_PROC, event_id);

    if (cui_menu_is_menu_event(event_id))
    {
        cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
        if (EVT_ID_CUI_MENU_CLOSE_REQUEST == event_id)
        {
            cui_menu_close(menu_evt->sender_id);
        }
        else
        {
            switch (menu_evt->parent_menu_id)
            {
            #if (MMI_MAX_SIM_NUM >=2)
                case MENU_ID_CBS_SIM_SELECT:
                    mmi_cbs_sim_select_menu_proc(menu_evt);
                    break;
            #endif /* __GEMINI__ */ 

                case MENU_ID_CBS_MAIN:
                    mmi_cbs_main_menu_proc(menu_evt);
                    break;

                case MENU_ID_CBS_RECEIVE_MODE:
                    mmi_cbs_receive_mode_menu_proc(menu_evt);
                    break;

                case MENU_ID_CBS_LANGUAGES:
                    mmi_cbs_lang_menu_proc(menu_evt);
                    break;

                case MENU_ID_CBS_CHNL_OPTIONS:
                    mmi_cbs_chnl_option_menu_proc(menu_evt);
                    break;

                default:
                    /* MMI_ASSERT(0); */
                    break;
            }
        }
    }
    else if ((event_id >= EVT_ID_CUI_INLINE_SUBMIT) && (event_id < EVT_ID_CUI_INLINE_MAX))
    {
        cui_event_inline_common_struct *inline_evt = (cui_event_inline_common_struct*)evt;

        mmi_cbs_chnl_inline_edit_proc(inline_evt);
    }
    else
    {
        switch (event_id)
        {
            case EVT_ID_GROUP_ACTIVE:
                mmi_cbs_cntx = cb_cntx;
                break;

            case EVT_ID_GROUP_DEINIT:
                mmi_cbs_group_deinit(cb_cntx);
                mmi_frm_cb_dereg_event(EVT_ID_SRV_CBS_READY_IND, mmi_cbs_setting_ready_event_hdlr, cb_cntx);
                break;

            case EVT_ID_GROUP_FIRST_ENTRY:
                mmi_frm_cb_reg_event(EVT_ID_SRV_CBS_READY_IND, mmi_cbs_setting_ready_event_hdlr, cb_cntx);
                break;
                
            case EVT_ID_GROUP_FOCUSED:
            case EVT_ID_GROUP_INACTIVE:
            case EVT_ID_GROUP_GOBACK:
            case EVT_ID_GROUP_DELETE_REQ:
            default:
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_group_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_group_deinit(cbs_app_cntx_struct *cb_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_GROUP_DEINIT);

    if (cb_cntx->curr_stamp == NULL)
    {
        OslMfree(cb_cntx->mode_info);
        OslMfree(cb_cntx->lang_info);
        OslMfree(cb_cntx->chnl_info);
        OslMfree(cb_cntx);
    }
    else
    {
        cb_cntx->is_deinit = MMI_TRUE;
        cb_cntx->curr_stamp = NULL;
    }

    if (cb_cntx == mmi_cbs_cntx)
    {
        mmi_cbs_cntx = NULL;
    }
}


#if (MMI_MAX_SIM_NUM >=2)
/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_sim_select_menu_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_cbs_sim_select_menu_proc(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__   
    WCHAR menu_str[MAX_SUBMENU_CHARACTERS];  
    U16 menu_string[] = {
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_GLOBAL_SIM_1,
        STR_GLOBAL_SIM_2,
    #if (MMI_MAX_SIM_NUM>=3)
        STR_GLOBAL_SIM_3,
    #if (MMI_MAX_SIM_NUM>=4)
        STR_GLOBAL_SIM_4,
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        };
#endif
    cbs_app_cntx_struct *cb_cntx = (cbs_app_cntx_struct*)menu_evt->user_data;
	    mmi_sim_enum sim_id = MMI_SIM1;
		U8 sim_no=0;
#if (MMI_MAX_SIM_NUM >=2)
		 mmi_menu_id menu_type_array[] =
				   { 
					MENU_ID_CBS_SIM_SELECT_SIM_1
					,MENU_ID_CBS_SIM_SELECT_SIM_2
		#if (MMI_MAX_SIM_NUM >= 3)
					,MENU_ID_CBS_SIM_SELECT_SIM_3
		#if (MMI_MAX_SIM_NUM >= 4)
					,MENU_ID_CBS_SIM_SELECT_SIM_4
		#endif
		#endif
				};
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SIM_SELECT_MENU_PROC, menu_evt->evt_id);

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            MMI_ID menu_gid = menu_evt->sender_id;
            mmi_cbs_set_new_scrn(cb_cntx, SCR_ID_CBS_SIM_SELECT);

            cui_menu_set_currlist_flags(
                menu_gid,
                CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

#ifndef __MMI_SMS_SLIM__
            cui_menu_set_default_title(
                menu_gid,
                (UI_string_type)GetString(STR_ID_CBS_CAPTION),
                (UI_image_type)GetImage(IMG_SMS_ENTRY_SCRN_CAPTION));
#endif
#if (MMI_MAX_SIM_NUM >=2)

            for(sim_no=0; sim_no< MMI_SIM_TOTAL; sim_id<<=1)
	    {
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__  
                if(!srv_sim_ctrl_is_inserted(sim_id))
            #else
		if(!mmi_cbs_is_show_cb_menu_ext(sim_id))
            #endif
		{
		    cui_menu_set_item_hidden(menu_gid, menu_type_array[sim_no], MMI_TRUE);
		}
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__   
				if(mmi_netset_get_sim_name(sim_id) != NULL)
				{
                    kal_wsprintf(menu_str, "%w(%w)", GetString(menu_string[sim_no]), mmi_netset_get_sim_name(sim_id));
					cui_menu_set_item_string(menu_gid, MENU_ID_CBS_SIM_SELECT_SIM_1 + sim_no, menu_str);
				}
                
#endif
					sim_no++;
					}
#endif /* __GEMINI__ */

            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            srv_sms_sim_enum sim_id;

            switch (menu_evt->highlighted_menu_id)
            {
#if (MMI_MAX_SIM_NUM >=2)
                case MENU_ID_CBS_SIM_SELECT_SIM_1:
                    sim_id = SRV_SMS_SIM_1;
                    break;

                case MENU_ID_CBS_SIM_SELECT_SIM_2:
                    sim_id = SRV_SMS_SIM_2;
                    break;

#if (MMI_MAX_SIM_NUM>=3)
		   case MENU_ID_CBS_SIM_SELECT_SIM_3:
			sim_id = SRV_SMS_SIM_3;
			break;

#if (MMI_MAX_SIM_NUM>=4)
		    case MENU_ID_CBS_SIM_SELECT_SIM_4:
			sim_id = SRV_SMS_SIM_4;
			break;
#endif
#endif
#endif

                default:
                    sim_id = SRV_SMS_SIM_1;
                    break;
            }

            cb_cntx->sim_id = sim_id;
            mmi_cbs_entry_main(cb_cntx);
            break;
        }

        default:
            break;
    }
 
    return MMI_RET_OK;
}
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_main_menu_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_cbs_main_menu_proc(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    cbs_app_cntx_struct *cb_cntx = (cbs_app_cntx_struct*)menu_evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_MAIN_MENU_PROC, menu_evt->evt_id);

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            MMI_ID owner_gid = menu_evt->sender_id;

            mmi_cbs_set_new_scrn(cb_cntx, SCR_ID_CBS_MAIN_MENU);
#ifndef __MMI_SMS_SLIM__
            cui_menu_set_default_title(
                owner_gid,
                (UI_string_type)GetString(STR_ID_CBS_CAPTION),
                (UI_image_type)GetImage(IMG_SMS_ENTRY_SCRN_CAPTION));
#endif
            if (cb_cntx->mode == MMI_TRUE)
            {
                cui_menu_set_item_hint(
                    owner_gid,
                    MENU_ID_CBS_RECEIVE_MODE,
                    (UI_string_type)GetString(STR_GLOBAL_ON));
            }
            else
            {
                cui_menu_set_item_hint(
                    owner_gid,
                    MENU_ID_CBS_RECEIVE_MODE,
                    (UI_string_type)GetString(STR_GLOBAL_OFF));
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_CBS_RECEIVE_MODE:
                    mmi_cbs_entry_receive_mode(cb_cntx);
                    break;

                case MENU_ID_CBS_CHANNELS:
                    mmi_cbs_entry_chnl(cb_cntx);
                    break;

                case MENU_ID_CBS_LANGUAGES:
                    mmi_cbs_entry_lang(cb_cntx);
                   break;

                case MENU_ID_CBS_INBOX:
                    mmi_cbs_inbox_launch(cb_cntx->owner_gid, cb_cntx->sim_id);
                    break;

                default:
                    MMI_ASSERT(0);
                    break;
            }
            break;
        }

    }
 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_receive_mode_menu_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_cbs_receive_mode_menu_proc(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    cbs_app_cntx_struct *cb_cntx = (cbs_app_cntx_struct*)menu_evt->user_data;
    mmi_cbs_mode_struct *mode_info = cb_cntx->mode_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_RECEIVE_MODE_MENU_PROC, menu_evt->evt_id);

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            MMI_ID owner_gid = menu_evt->sender_id;

            mmi_cbs_set_new_scrn(cb_cntx, SCR_ID_CBS_RECEIVE_MODE);
#ifndef __MMI_SMS_SLIM__
            cui_menu_set_default_title(
                owner_gid,
                (UI_string_type)GetString(STR_ID_CBS_RECEIVE_MODE),
                (UI_image_type)GetImage(IMG_SMS_ENTRY_SCRN_CAPTION));
#endif
            cui_menu_set_currlist_flags(
                owner_gid,
                CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

            if (mode_info->is_first_enter)
            {
                mode_info->is_first_enter = MMI_FALSE;

                if (mode_info->mode == MMI_TRUE)
                {
                    cui_menu_set_currlist_highlighted_id(owner_gid, MENU_ID_CBS_RECEIVE_MODE_ON);
                }
                else
                {
                    cui_menu_set_currlist_highlighted_id(owner_gid, MENU_ID_CBS_RECEIVE_MODE_OFF);
                }
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            MMI_BOOL curr_mode = MMI_FALSE;

            if (menu_evt->highlighted_menu_id == MENU_ID_CBS_RECEIVE_MODE_ON)
            {
                curr_mode = MMI_TRUE;
            }

            if (curr_mode != mode_info->mode)
            {
                mode_info->menu_gid = menu_evt->sender_id;
                mode_info->mode = curr_mode;

                mmi_cbs_submit_action(cb_cntx, CBS_ACTION_SUBSCRIBE);
            }
            else
            {
                mmi_cbs_close_menu(menu_evt->sender_id, menu_evt->app_data);
            }
            break;
        }
        default:
            break;
    }
 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_lang_menu_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_cbs_lang_menu_proc(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    cbs_app_cntx_struct *cb_cntx = (cbs_app_cntx_struct*)menu_evt->user_data;
    MMI_ID menu_gid = menu_evt->sender_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_LANG_MENU_PROC, menu_evt->evt_id);

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            U32 i;
            srv_cbs_language_struct *lang_info = &cb_cntx->lang_info->info;
            MMI_MENU_ID menu_list[SRV_CBS_MAX_LANG_NUM + 1];

            mmi_cbs_set_new_scrn(cb_cntx, SCR_ID_CBS_LANG_LIST);
            cui_menu_set_default_title(
                menu_gid,
                (UI_string_type)GetString(STR_ID_CBS_LANGUAGES),
                (UI_image_type)GetImage(IMG_SMS_ENTRY_SCRN_CAPTION));
            cui_menu_set_currlist_flags(
                menu_gid,
                CUI_MENU_NORMAL_CHECK_BOX_LIST);

            menu_list[0] = MENU_ID_CBS_ALL_LANGS;

            for (i = 0; i < lang_info->total; i++)
            {
                menu_list[i + 1] = i; 
            }

            cui_menu_set_currlist(menu_gid, (lang_info->total + 1), menu_list);

            cui_menu_set_item_string(
                menu_gid,
                MENU_ID_CBS_ALL_LANGS,
                (WCHAR*)GetString(STR_ID_CBS_ALL_LANGS));

            for (i = 0; i < lang_info->total; i++)
            {
                U16 str_id;

                str_id = lang_str_id[lang_info->entry[i].lang_type];

                cui_menu_set_item_string(
                    menu_gid,
                    (MMI_MENU_ID)i,
                    (WCHAR*)GetString(str_id));      
            }

            cui_menu_set_checkbox_state(menu_gid, cb_cntx->lang_info->check_state);
            break;
        }

        case EVT_ID_CUI_MENU_CHECKBOX_CHANGE_STATE:
        {
            U8 check_state[SRV_CBS_MAX_LANG_NUM + 1];
            U32 i;
            srv_cbs_language_struct *lang_info = &cb_cntx->lang_info->info;

            cui_menu_get_checkbox_state(menu_gid, check_state);

            if (menu_evt->highlighted_menu_id == MENU_ID_CBS_ALL_LANGS)
            {
                /* If the [All langugages] is On, the rest of language items should 
                 * be On; vice versa */
                for (i = 1; i < (U32)(lang_info->total + 1); i++)
                {
                    check_state[i] = check_state[0];
                }
            }
            else
            {
                U16 index = menu_evt->highlighted_menu_id + 1;

                if (check_state[index])
                {
                    /* If the rest of language items is On, Set [All Language] item On too */
                    check_state[0] = MMI_TRUE;

                    for (i = 1; i < (U32)(lang_info->total + 1); i++)
                    {
                        if (!check_state[i])
                        {
                            check_state[0] = MMI_FALSE;
                            break;
                        }
                    }
                }
                else
                {
                    /* If the All Lang Menu is On, and change other lang from On to Off,
                     * need to set All Lang to Off */
                    check_state[0] = MMI_FALSE;
                }
            }

            cui_menu_set_checkbox_state(menu_gid, check_state);
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_cbs_lang_struct *lang_info = cb_cntx->lang_info;

            lang_info->menu_gid = menu_gid;
        
            cui_menu_get_checkbox_state(menu_gid, lang_info->check_state);
            mmi_cbs_select_lang();

            break;
        }

        default:
            break;
    }
 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_chnl_option_menu_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_cbs_chnl_option_menu_proc(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    cbs_app_cntx_struct *cb_cntx = (cbs_app_cntx_struct*)menu_evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_CHNL_OPTION_MENU_PROC, menu_evt->evt_id);

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            MMI_ID owner_gid = menu_evt->sender_id;
            srv_cbs_channel_struct *chnl_data = &cb_cntx->chnl_info->chnl_data;

            mmi_cbs_set_new_scrn(cb_cntx, SCR_ID_CBS_CHNL_LIST_OPTIONS);

            if (chnl_data->total == 0)
            {
                cui_menu_set_item_hidden(owner_gid, MENU_ID_CBS_CHNL_OPT_SUBSCRIBE, MMI_TRUE);
                cui_menu_set_item_hidden(owner_gid, MENU_ID_CBS_CHNL_OPT_UNSUBSCRIBE, MMI_TRUE);
                cui_menu_set_item_hidden(owner_gid, MENU_ID_CBS_CHNL_OPT_DELETE, MMI_TRUE);
                cui_menu_set_item_hidden(owner_gid, MENU_ID_CBS_CHNL_OPT_EDIT, MMI_TRUE);
            }
            else
            {
                srv_cbs_chnl_entry_struct *chnl_entry;

                chnl_entry = &chnl_data->entry[cb_cntx->curr_idnex];

                if (chnl_entry->mask)
                {
                    cui_menu_set_item_hidden(owner_gid, MENU_ID_CBS_CHNL_OPT_SUBSCRIBE, MMI_TRUE);
                }
                else
                {
                    cui_menu_set_item_hidden(owner_gid, MENU_ID_CBS_CHNL_OPT_UNSUBSCRIBE, MMI_TRUE);
                }
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_cbs_chnl_struct *chnl_info = cb_cntx->chnl_info;
            srv_cbs_channel_struct *chnl_data = &chnl_info->chnl_data;

            chnl_info->menu_gid = menu_evt->sender_id;

            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_CBS_CHNL_OPT_ADD:
                {
                    if (chnl_data->total == chnl_data->max_entry)
                    {
                        mmi_cbs_display_common_failure(STR_ID_CBS_CHNL_FULL);
                    }
                    else
                    {
                        chnl_info->name[0] = '\0';
                        chnl_info->number[0] = '\0';

                        mmi_cbs_set_new_scrn(cb_cntx, SCR_ID_CBS_ADD_CHNL);
                        mmi_cbs_entry_chnls_edit(cb_cntx);
                    }
                    break;
                }

                case MENU_ID_CBS_CHNL_OPT_EDIT:
                {
                    srv_cbs_chnl_entry_struct *curr_chnl;

                    curr_chnl = &chnl_info->chnl_data.entry[cb_cntx->curr_idnex];

                    mmi_wcscpy(chnl_info->name, curr_chnl->name);
                    kal_wsprintf(chnl_info->number, "%d", curr_chnl->id);
                    chnl_info->mask = curr_chnl->mask;

                    mmi_cbs_set_new_scrn(cb_cntx, SCR_ID_CBS_EDIT_CHNL);
                    mmi_cbs_entry_chnls_edit(cb_cntx);
                    break;
                }

                case MENU_ID_CBS_CHNL_OPT_SUBSCRIBE:
                case MENU_ID_CBS_CHNL_OPT_UNSUBSCRIBE:
                {
                    mmi_cbs_submit_action(
                        cb_cntx,
                        CBS_ACTION_SELECT_CHNL);
                    break;
                }

                case MENU_ID_CBS_CHNL_OPT_DELETE:
                {
                    mmi_sms_entry_confirm(
                        cb_cntx->owner_gid,
                        STR_GLOBAL_DELETE_ASK,
                        mmi_cbs_delete_chnl,
                        mmi_frm_scrn_close_active_id,
                        MMI_TRUE);
                    break;
                }

                default:
                {
                    MMI_ASSERT(0);
                    break;
                }
            }
            break;
        }
    }
 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_chnl_inline_edit_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_cbs_chnl_inline_edit_proc(cui_event_inline_common_struct *inline_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    cbs_app_cntx_struct *cb_cntx = (cbs_app_cntx_struct*)inline_evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_CHNL_INLINE_EDIT_PROC, inline_evt->evt_id);

    switch (inline_evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_inline_close(inline_evt->sender_id);
            break;
        }

        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            mmi_cbs_chnl_struct *chnl_info = cb_cntx->chnl_info;
            MMI_ID inline_gid = inline_evt->sender_id;

            chnl_info->inline_gid = inline_gid;
        
            cui_inline_get_value(
                inline_gid,
                CUI_INLINE_ITEM_ID_BASE + 1,
                chnl_info->name);

            cui_inline_get_value(
                inline_gid,
                CUI_INLINE_ITEM_ID_BASE + 3,
                chnl_info->number);

            mmi_cbs_save_edit_chnl();
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_init_app_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_init_app_cntx(
                cbs_app_cntx_struct *cb_cntx,
                MMI_ID owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    memset(cb_cntx, 0, sizeof(*cb_cntx));
    cb_cntx->owner_gid = owner_gid;
    cb_cntx->sim_id = SRV_SMS_SIM_1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_set_new_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_set_new_scrn(cbs_app_cntx_struct *cb_cntx, U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SET_NEW_SCRN, scrn_id);

    cb_cntx->curr_action = CBS_ACTION_NONE;
    cb_cntx->curr_scrn_id = scrn_id;
    cb_cntx->curr_stamp = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_submit_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_submit_action(
                cbs_app_cntx_struct *cb_cntx,
                mmi_cbs_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbs_action_stamp_struct *action_stamp;
    srv_sms_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    action_stamp = OslMalloc(sizeof(cbs_action_stamp_struct));

    cb_cntx->curr_action = action;
    cb_cntx->curr_stamp = action_stamp;

    action_stamp->cb_cntx = cb_cntx;

    sim_id = cb_cntx->sim_id;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SUBMIT_ACTION, action, action_stamp);

    switch (action)
    {
        case CBS_ACTION_SUBSCRIBE:
        {
            srv_cbs_subscribe(
                cb_cntx->mode_info->mode,
                sim_id,
                mmi_cbs_submit_action_callback,
                action_stamp);
            break;
        }

        case CBS_ACTION_ADD_CHNL:
        {
            srv_cbs_chnl_entry_struct chnl_entry;
            mmi_cbs_chnl_struct *chnl_info = cb_cntx->chnl_info;
            S8 asc_num[CBS_CHNL_NUMBER_DISP_LEN + 1];
            U16 chnl_id;

            mmi_wcs_to_asc(asc_num, chnl_info->number);

            chnl_id = (U16)atoi(asc_num);

            chnl_info->chnl_id = chnl_id;
            chnl_info->mask = MMI_TRUE;

            chnl_entry.id = chnl_id;
            mmi_wcscpy(chnl_entry.name, chnl_info->name);
            chnl_entry.mask = MMI_TRUE;

            srv_cbs_add_channel(
                &chnl_entry,
                sim_id,
                mmi_cbs_submit_action_callback,
                action_stamp);
            break;
        }

        case CBS_ACTION_EDIT_CHNL:
        {
            srv_cbs_chnl_entry_struct new_chnl;
            srv_cbs_chnl_entry_struct *old_chnl;
            mmi_cbs_chnl_struct *chnl_info = cb_cntx->chnl_info;
            S8 asc_num[CBS_CHNL_NUMBER_DISP_LEN + 1];
            U16 chnl_id;

            old_chnl = &chnl_info->chnl_data.entry[cb_cntx->curr_idnex];

            mmi_wcs_to_asc(asc_num, chnl_info->number);

            chnl_id = (U16)atoi(asc_num);

            chnl_info->chnl_id = chnl_id;

            new_chnl.id = chnl_id;
            mmi_wcscpy(new_chnl.name, chnl_info->name);
            new_chnl.mask = chnl_info->mask;

            srv_cbs_update_channel(
                &new_chnl,
                old_chnl,
                sim_id,
                mmi_cbs_submit_action_callback,
                action_stamp);
            break;
        }

        case CBS_ACTION_SELECT_CHNL:
        {
            srv_cbs_chnl_entry_struct new_chnl;
            srv_cbs_chnl_entry_struct *old_chnl;

            old_chnl = &cb_cntx->chnl_info->chnl_data.entry[cb_cntx->curr_idnex];

            memcpy(&new_chnl, old_chnl, sizeof(srv_cbs_chnl_entry_struct));
            new_chnl.mask = (MMI_BOOL)!old_chnl->mask;

            srv_cbs_update_channel(
                &new_chnl,
                old_chnl,
                sim_id,
                mmi_cbs_submit_action_callback,
                action_stamp);
            break;
        }

        case CBS_ACTION_DELETE_CHNL:
        {
            U16 del_chnl_id;
            
            del_chnl_id = cb_cntx->chnl_info->chnl_data.entry[cb_cntx->curr_idnex].id;

            srv_cbs_delete_channel(
                del_chnl_id,
                sim_id,
                mmi_cbs_submit_action_callback,
                action_stamp);
            break;
        }

        case CBS_ACTION_SELECT_LANG:
        {
            srv_cbs_select_language(
                &cb_cntx->lang_info->info,
                sim_id,
                mmi_cbs_submit_action_callback,
                action_stamp);
            break;
        }

        default:
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_submit_action_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_submit_action_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbs_action_stamp_struct *action_stamp;
    cbs_app_cntx_struct *cb_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    action_stamp = (cbs_action_stamp_struct*)callback_data->user_data;
    cb_cntx = action_stamp->cb_cntx;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SUBMIT_ACTION_CALLBACK, action_stamp);

    OslMfree(action_stamp);

    if (cb_cntx->curr_stamp == action_stamp)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SUBMIT_ACTION_CALLBACK_1, cb_cntx->curr_action);

        cb_cntx->curr_stamp = NULL;
        switch (cb_cntx->curr_action)
        {
            case CBS_ACTION_SUBSCRIBE:
            {
                mmi_cbs_subscribe_hdlr(cb_cntx, callback_data);
                break;
            }

            case CBS_ACTION_SELECT_CHNL:
            {
                mmi_cbs_select_chnl_hdlr(cb_cntx, callback_data);
                break;
            }

            case CBS_ACTION_ADD_CHNL:
            {
                mmi_cbs_add_chnl_hdlr(cb_cntx, callback_data);
                break;
            }

            case CBS_ACTION_EDIT_CHNL:
            {
                mmi_cbs_edit_chnl_hdlr(cb_cntx, callback_data);
                break;
            }

            case CBS_ACTION_DELETE_CHNL:
            {
                mmi_cbs_delete_chnl_hdlr(cb_cntx, callback_data);
                break;
            }

            case CBS_ACTION_SELECT_LANG:
            {
                mmi_cbs_select_lang_hdlr(cb_cntx, callback_data);
                break;
            }
            
            default:
            {
                break;
            }
        }
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SUBMIT_ACTION_CALLBACK_2, cb_cntx->is_deinit);

        if (cb_cntx->is_deinit)
        {
            OslMfree(cb_cntx);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_subscribe_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_subscribe_hdlr(
                cbs_app_cntx_struct* cb_cntx,
                srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SUBSCRIBE_HDLR, callback_data->result);

    if (callback_data->result)
    {
        cb_cntx->mode = cb_cntx->mode_info->mode;
        mmi_cbs_display_common_success(STR_GLOBAL_SAVED);
    }
    else
    {
        mmi_cbs_display_common_not_finished();
    }

    {
        void *app_data = cui_menu_get_app_parent_data(cb_cntx->mode_info->menu_gid);
        mmi_cbs_close_menu(cb_cntx->mode_info->menu_gid, app_data);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_select_chnl_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_select_chnl_hdlr(
                cbs_app_cntx_struct* cb_cntx,
                srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cbs_chnl_struct *chnl_info = cb_cntx->chnl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SELECT_CHNL_HDLR, callback_data->result);

    if (callback_data->result)
    {
        srv_cbs_chnl_entry_struct *update_chnl;

        update_chnl = &chnl_info->chnl_data.entry[cb_cntx->curr_idnex];

        update_chnl->mask = (MMI_BOOL)(!update_chnl->mask);
    }
    else
    {
        mmi_cbs_display_common_not_finished();
    }

    /* Subscribe/Un-Subscribe Channel through Menu Item */
    if (chnl_info->menu_gid != GRP_ID_INVALID)
    {
        void *app_data = cui_menu_get_app_parent_data(chnl_info->menu_gid);
        mmi_cbs_close_menu(chnl_info->menu_gid, app_data);
    }
    else
    {
        mmi_cbs_refresh_chnl_list(cb_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_add_chnl_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_add_chnl_hdlr(
                cbs_app_cntx_struct* cb_cntx,
                srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cbs_chnl_struct *chnl_info = cb_cntx->chnl_info;
    U16 str_id;
    MMI_BOOL is_closed = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ADD_CHNL_HDLR, callback_data->result);

    if (callback_data->result)
    {
        cb_cntx->curr_idnex = mmi_cbs_add_chnl_entry(
                                &chnl_info->chnl_data,
                                chnl_info->chnl_id,
                                chnl_info->name,
                                chnl_info->mask);
        mmi_cbs_display_common_success(STR_GLOBAL_SAVED);
    }
    else
    {
        if (callback_data->cause == SRV_SMS_CAUSE_CB_CHNL_DUPLICATED)
        {
            str_id = STR_ID_CBS_CHNL_DUPLICTED;
            is_closed = MMI_FALSE;
        }
        else
        {
            str_id = STR_GLOBAL_UNFINISHED;
        }
        mmi_cbs_display_common_failure(str_id);
    }
    

    if (is_closed)
    {
        cui_inline_close(chnl_info->inline_gid);
    }
}




/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_edit_chnl_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_edit_chnl_hdlr(
                cbs_app_cntx_struct* cb_cntx,
                srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cbs_chnl_struct *chnl_info = cb_cntx->chnl_info;
    MMI_BOOL is_closed = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_EDIT_CHNL_HDLR, callback_data->result);

    if (callback_data->result)
    {
        srv_cbs_chnl_entry_struct *update_chnl;
        srv_cbs_channel_struct *chnl_data = &cb_cntx->chnl_info->chnl_data;

        update_chnl = &chnl_info->chnl_data.entry[cb_cntx->curr_idnex];

        if (update_chnl->id == chnl_info->chnl_id)
        {
            update_chnl->id = chnl_info->chnl_id;
            mmi_wcscpy(update_chnl->name, chnl_info->name);
            update_chnl->mask = chnl_info->mask;
        }
        else
        {
            U32 i;

            /* Delete Old Channel */
            for (i = (U32)cb_cntx->curr_idnex; i < (U32)(chnl_data->total - 1); i++)
            {
                memcpy(&chnl_data->entry[i], &chnl_data->entry[i + 1], sizeof(srv_cbs_chnl_entry_struct));
            }

            chnl_data->total--;

            cb_cntx->curr_idnex = mmi_cbs_add_chnl_entry(
                                    chnl_data,
                                    chnl_info->chnl_id,
                                    chnl_info->name,
                                    chnl_info->mask);
        }
        mmi_cbs_display_common_success(STR_GLOBAL_SAVED);
    }
    else
    {
        U16 str_id;
        if (callback_data->cause == SRV_SMS_CAUSE_CB_CHNL_DUPLICATED)
        {
            str_id = STR_ID_CBS_CHNL_DUPLICTED;
            is_closed = MMI_FALSE;
        }
        else
        {
            str_id = STR_GLOBAL_UNFINISHED;
        }
        mmi_cbs_display_common_failure(str_id);
    }

    if (is_closed)
    {
        cui_inline_close(chnl_info->inline_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_delete_chnl_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_delete_chnl_hdlr(
                cbs_app_cntx_struct* cb_cntx,
                srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_DELETE_CHNL_HDLR, callback_data->result);

    if (callback_data->result)
    {
        mmi_cbs_display_common_success(STR_GLOBAL_DELETED);
    }
    else
    {
        mmi_cbs_display_common_not_finished();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_select_lang_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cbs_select_lang_hdlr(
                cbs_app_cntx_struct* cb_cntx,
                srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_SELECT_LANG_HDLR, callback_data->result);

    if (callback_data->result)
    {
        mmi_cbs_display_common_success(STR_GLOBAL_SAVED);
    }
    else
    {
        mmi_cbs_display_common_not_finished();
    }
    {
    void *app_data = cui_menu_get_app_parent_data(cb_cntx->lang_info->menu_gid);
    mmi_cbs_close_menu(cb_cntx->lang_info->menu_gid, app_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_add_chnl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_cbs_add_chnl_entry(
                srv_cbs_channel_struct* chnl_data,
                U16 chnl_id,
                WCHAR* chnl_name,
                MMI_BOOL mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_CBS_ADD_CHNL_ENTRY, chnl_id);

    for (i = 0; i < chnl_data->total; i++)                    
    {
        if (chnl_data->entry[i].id > chnl_id)
        {
            break;
        }
    }

    for (j = chnl_data->total; j > i; j--)
    {
        memcpy(&chnl_data->entry[j], &chnl_data->entry[j - 1], sizeof(srv_cbs_chnl_entry_struct));
    }

    chnl_data->entry[i].id = chnl_id;
    mmi_wcscpy(chnl_data->entry[i].name, chnl_name);
    chnl_data->entry[i].mask = mask;

    chnl_data->total++;

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_is_show_cb_menu_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_cbs_is_show_cb_menu_ext(mmi_sim_enum sim_id)
{
#ifndef __MMI_DYNAMIC_SIM_DYNAMIC_UI__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_srv_valid;
    MMI_BOOL is_sim_valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        is_sim_valid = (MMI_BOOL) srv_sim_ctrl_is_available(sim_id);

        is_srv_valid = srv_cphs_is_service_available(
                            SRV_CPHS_GROUP_TELESERVICES,
                            SRV_CPHS_SERVICE_SM_CB,
                            sim_id);


        if (!is_sim_valid || !is_srv_valid)
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
#else
    return MMI_TRUE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_is_show_cb_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_cbs_is_show_cb_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_show = (MMI_BOOL)0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_show = mmi_cbs_is_show_cb_menu_ext(MMI_SIM1);

#if (MMI_MAX_SIM_NUM >=2)
	is_show = (MMI_BOOL)(is_show || mmi_cbs_is_show_cb_menu_ext(MMI_SIM2));
#endif
#if (MMI_MAX_SIM_NUM >=3)
	is_show = (MMI_BOOL)(is_show || mmi_cbs_is_show_cb_menu_ext(MMI_SIM3));
#endif
#if (MMI_MAX_SIM_NUM >=4)
	is_show = (MMI_BOOL)(is_show || mmi_cbs_is_show_cb_menu_ext(MMI_SIM4));
#endif
    return is_show;
}
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__  
/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_is_entry_cb_menu_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_cbs_is_entry_cb_menu_ext(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_entry = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_entry = srv_sim_ctrl_is_available(sim);
    return is_entry;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_is_entry_cb_menu_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_cbs_is_entry_cb_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_entry = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_entry = (MMI_BOOL) srv_sim_ctrl_is_inserted(MMI_SIM1);

#if (MMI_MAX_SIM_NUM >=2)
	is_entry = (MMI_BOOL)(is_entry || srv_sim_ctrl_is_inserted(MMI_SIM2));
#endif
#if (MMI_MAX_SIM_NUM >=3)
	is_entry = (MMI_BOOL)(is_entry || srv_sim_ctrl_is_inserted(MMI_SIM3));
#endif
#if (MMI_MAX_SIM_NUM >=4)
	is_entry = (MMI_BOOL)(is_entry || srv_sim_ctrl_is_inserted(MMI_SIM4));
#endif
    return is_entry;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_is_entry_cb_menu_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/

static MMI_BOOL mmi_cbs_is_show_sim_select_menu(U32 *sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    if(srv_sim_ctrl_is_inserted(MMI_SIM1))
    {
        *sim = (*sim)|MMI_SIM1;
        num ++;
    }
#if (MMI_MAX_SIM_NUM >=2)
	if(srv_sim_ctrl_is_inserted(MMI_SIM2))
    {
        *sim = (*sim)|MMI_SIM2;
        num ++;
    }
#endif
#if (MMI_MAX_SIM_NUM >=3)
	if(srv_sim_ctrl_is_inserted(MMI_SIM3))
    {
        *sim = (*sim)|MMI_SIM3;
        num ++;
    }
#endif
#if (MMI_MAX_SIM_NUM >=4)
	if(srv_sim_ctrl_is_inserted(MMI_SIM4))
    {
        *sim = (*sim)|MMI_SIM3;
        num ++;
    }
#endif
    if(num == 1)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_display_common_not_finished
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_cbs_display_common_not_finished(void)
{
    mmi_cbs_display_common_failure(STR_GLOBAL_UNFINISHED);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_display_common_failure
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_cbs_display_common_failure(MMI_ID string_id)
{
    mmi_popup_display_ext(
        string_id,
        MMI_EVENT_FAILURE,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_display_common_failure
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_cbs_display_common_success(MMI_ID string_id)
{
    mmi_popup_display_ext(
        string_id,
        MMI_EVENT_SUCCESS,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_setting_ready_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_cbs_setting_ready_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbs_app_cntx_struct *cb_cntx = (cbs_app_cntx_struct*)evt->user_data;
    mmi_id cb_setting_group = cb_cntx->owner_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(cb_setting_group) || mmi_frm_group_is_in_active_serial(cb_setting_group))
    {
        mmi_frm_group_close(cb_setting_group);
    }
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cbs_show_dummy_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_cbs_show_dummy_screen(void)
{
    mmi_frm_display_dummy_screen_ex(GRP_ID_ROOT, SCR_ID_DUMMY);
}


#endif /*__MMI_CBS_SUPPORT__*/
#endif /*__MMI_TELEPHONY_SUPPORT__*/
