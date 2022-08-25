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
 *  CallLogPbapc.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  PBAPC
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/

#include "MMI_features.h"

#if defined(__MMI_BT_PBAP_CLIENT__)
#include "Custom_events_notify.h"
#include "AlertScreen.h"
#include "PhbpbapSrvGprot.h"
#if defined ( __MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#include "wgui_touch_screen.h"
#endif /*defined ( __MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)*/
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_rp_app_calllog_def.h"
#include "string.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_popup.h"
#include "CallLogAdpPbapc.h"
#include "CallLogProt.h"
#ifdef __MMI_BT_MAP_CLIENT__
#include "SmsUmBtMapGProt.h"
#endif /*__MMI_BT_MAP_CLIENT__*/
#ifdef __MMI_BT_DIALER_SUPPORT__
#include "UcmGProtBT.h"
#endif /*__MMI_BT_DIALER_SUPPORT__*/
#include "BTMMIScrGprots.h"
#include "MMI_common_app_trc.h"
#include "wgui_categories_popup.h"
#include "CallLogGprot.h"
#include "UcmGprot.h"
#include "PhbCuiGprot.h"
#include "SmsAppGprot.h"
#include "CallLogAdpProt.h"
#include "CallLogLayout.h"

MMI_BOOL g_only_update_data = MMI_FALSE; // only distinguish bt1 bt2.
typedef struct
{
    U16 sel_log_idx;
    srv_phb_pbap_storage_enum sel_lt_storage;    
    MMI_ID self_gid;
    U32 total_num; /* total log count in current screen */    
} mmi_clog_pbapc_lt_inst_struct;

typedef struct
{
    MMI_ID parent_gid;
    U16 log_idx; /* if 0, means empty */
} mmi_clog_pbapc_op_inst_struct;

typedef struct
{
    U16 log_idx;
    WCHAR *buf;
} mmi_clog_pbapc_vr_inst_struct;


static mmi_clog_pbapc_lt_inst_struct g_mmi_clog_pbapc_lt_inst;
static mmi_clog_pbapc_op_inst_struct g_mmi_clog_pbapc_op_inst;
static mmi_clog_pbapc_vr_inst_struct g_mmi_clog_pbapc_vr_inst;
mmi_clog_pbapc_processing_inst_struct g_mmi_clog_pbapc_processing_inst;
static mmi_clog_reslove_hlt_item_struct g_mmi_clog_need_save_hlt_idx;
void mmi_clog_prepare_data(MMI_MENU_ID sel_menu_id, MMI_ID gid);
static void mmi_clog_pbapc_lt_show_list(void);
void mmi_clog_bt_compare_log_by_timestamp(S32 ret);

static void mmi_clog_pbapc_entry_show_processing(void);

static MMI_RET mmi_clog_pbapc_lt_group_proc(mmi_event_struct *evt);
static void mmi_clog_pbapc_read_cb(S32 result);
static void mmi_clog_pbapc_lt_item_hlt_hdlr(S32 sel);
static void mmi_clog_pbapc_lt_lsk_hdlr(void);
static void mmi_clog_pbapc_lt_csk_hdlr(void);
static void mmi_clog_pbapc_lt_rsk_hdlr(void);
static S32 mmi_clog_pbapc_lt_get_multi_log_items(S32 start_index, gui_iconlist_menu_item *menu_data, S32 item_count);
static S32 mmi_clog_pbapc_lt_get_log_hint(S32 item_index, UI_string_type *hint_array);
#ifdef __MMI_CLOG_TAB_SUPPORT__
static void mmi_clog_pbapc_processing_show(MMI_ID parent_id, MMI_ID scrn_id, mmi_clog_pbapc_op_type_enum type, srv_phb_pbap_storage_enum sel_lt_storage);
#endif

void mmi_clog_pbapc_processing_abort(void);

#if defined ( __MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_clog_pbapc_lt_tap_action_hdlr(mmi_tap_type_enum tap_type, S32 index);
static void mmi_clog_pbapc_lt_set_tap_hdlr(void);
#endif /*defined ( __MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)*/
static MMI_ID mmi_clog_pbapc_op_enter(MMI_ID parent_gid, mmi_clog_pbapc_op_type_enum type, U16 log_idx);
static void mmi_clog_pbapc_viewer_enter(MMI_ID parent_gid, U16 log_idx);
static void mmi_clog_pbapc_make_call(U16 caller_gid,U16 log_idx, MMI_BOOL is_send_key);
static void mmi_clog_pbapc_send_sms(mmi_id parent_gid, U16 log_idx);
static void mmi_clog_pbapc_vr_show_text(void);
#ifdef __MMI_CLOG_PBAPC_CLOG_TYPE_DETAIL_SHOW__
static S32 mmi_clog_pbapc_vr_format_type(mmi_clog_pbap_info_struct *log, U32 *cur_len);
#endif /*__MMI_CLOG_PBAPC_CLOG_TYPE_DETAIL_SHOW__*/
static S32 mmi_clog_pbapc_vr_format_name(mmi_clog_pbap_info_struct *log, U32 *cur_len);
static S32 mmi_clog_pbapc_vr_format_number(mmi_clog_pbap_info_struct *log, U32 *cur_len);
static S32 mmi_clog_pbapc_vr_format_time(mmi_clog_pbap_info_struct *log, U32 *cur_len);
#ifdef __MMI_CLOG_TAB_SUPPORT__
static void mmi_clog_pbapc_lt_tab_set_page_info(mmi_frm_tab_struct *page_info, mmi_clog_lt_id_enum lt_id);
static void mmi_clog_pbapc_lt_tab_enter_page(mmi_scrn_essential_struct *grp_data);
static void mmi_clog_pbapc_lt_tab_exit(mmi_scrn_essential_struct *scr_info);
static void mmi_clog_pbapc_lt_tab_enter(mmi_scrn_essential_struct *scr_info);
#else /* __MMI_CLOG_TAB_SUPPORT__ */
static MMI_ID mmi_clog_pbapc_lt_list_enter(MMI_ID parent_id, srv_phb_pbap_storage_enum sel_lt_storage);
//static void mmi_clog_pbapc_select_hdlr(MMI_MENU_ID sel_menu_id);
//void mmi_clog_pbapc_select_hdlr(MMI_MENU_ID sel_menu_id, MMI_ID gid);
#endif /* __MMI_CLOG_TAB_SUPPORT__ */
mmi_ret mmi_clog_async_create_folder_result_proc(mmi_event_struct *param);
static MMI_IMG_ID mmi_clog_pbapc_lt_get_img_by_call_type(mmi_clog_pbapc_clt_enum call_type);

static void mmi_clog_send_key_hdler();
static void mmi_clog_pbapc_make_bt_call(U16 caller_gid, U16 log_idx);
static void mmi_clog_act_make_call_cb(mmi_ucm_after_make_call_cb_struct *para);
static MMI_RET mmi_clog_act_pbap_group_proc(mmi_event_struct *evt);
static void mmi_clog_pbapc_op_evt_mm_select_hdlr(cui_menu_event_struct *evt);
static MMI_RET mmi_clog_pbapc_send_key_group_proc(mmi_event_struct *evt);
#ifdef __MMI_HF_SUPPORT__
void mmi_clog_update_log_by_end_call(srv_ucm_bt_release_call_ind_struct *para);
#endif
void mmi_clog_pbapc_show_category(S32 error_code, U8 *gui_buffer);
void mmi_clog_pbapc_processing_show_ex(MMI_ID parent_id, mmi_clog_pbapc_op_type_enum type, srv_phb_pbap_storage_enum sel_lt_storage);
void mmi_clog_pbapc_select_hdlr(MMI_MENU_ID sel_menu_id, MMI_ID gid);
extern U32 g_exist_flag;
extern mmi_clog_get_last_num_struct g_mmi_clog_get_last_info;



/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define MMI_CLOG_PBAPC_VR_TEMP_BUF_LEN                        (256)
#define MMI_CLOG_PBAPC_VR_TEMP_BUF_SIZE                       ((MMI_CLOG_PBAPC_VR_TEMP_BUF_LEN + 1) * ENCODING_LENGTH)
#define MMI_CLOG_PBAPC_VR_BUF_MAX_LEN                         (MMI_CLOG_PBAPC_CID_MAX_LEN + MMI_CLOG_PBAPC_NAME_MAX_LEN + 200)
#define MMI_CLOG_PBAPC_VR_BUF_MAX_SIZE                        ((MMI_CLOG_PBAPC_VR_BUF_MAX_LEN + 1) * ENCODING_LENGTH)
#define MMI_CLOG_PBAPC_VR_FORMAT_DATA_LEN                     (sizeof("\n\n\n") - 1)

typedef S32(*MMI_CLOG_PBAPC_VR_FORMAT_TEXT_PARA_HDLR) (mmi_clog_pbap_info_struct *log, U32 *cur_len);

extern mmi_clog_pbapc_cntx_struct g_mmi_clog_pbapc_cntx;
extern U16 mmi_clog_pbap_current_num;
extern mmi_clog_pbap_clog_info_cache_struct g_mmi_clog_pbapc_clog_info_cache[MMI_CLOG_PBAPC_ENTRIES];

static const MMI_CLOG_PBAPC_VR_FORMAT_TEXT_PARA_HDLR g_mmi_clog_pbapc_vr_format_text_tbl[] = 
{
#ifdef __MMI_CLOG_PBAPC_CLOG_TYPE_DETAIL_SHOW__
	mmi_clog_pbapc_vr_format_type,
#endif /*__MMI_CLOG_PBAPC_CLOG_TYPE_DETAIL_SHOW__*/
    mmi_clog_pbapc_vr_format_name,
    mmi_clog_pbapc_vr_format_number,
    mmi_clog_pbapc_vr_format_time,
};

#define MMI_CLOG_PBAPC_MAIMENU_UI

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_clog_pbapc_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/            
    cui_menu_event_struct *mc_evt = (cui_menu_event_struct*) evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {      
    #ifndef __MMI_CLOG_TAB_SUPPORT__
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            //mmi_clog_pbapc_select_hdlr(mc_evt->highlighted_menu_id, GRP_ID_CLOG_PBAPC);
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(mc_evt->sender_id);
            break;
    #endif /* __MMI_CLOG_TAB_SUPPORT__ */
        case EVT_ID_GROUP_DEINIT: 
            mmi_clog_pbapc_free_op_handle();
           break;
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_enter(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLOG_TAB_SUPPORT__
    memset(&g_mmi_clog_pbapc_lt_inst, 0x00, sizeof(mmi_clog_pbapc_lt_inst_struct));

    g_mmi_clog_pbapc_lt_inst.self_gid = mmi_frm_group_create_ex(gid, 
                    GRP_ID_CLOG_PBAPC_LT, 
                    mmi_clog_pbapc_lt_group_proc, 
                    NULL, 
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(g_mmi_clog_pbapc_lt_inst.self_gid, 
                    SCR_ID_CLOG_PBAPC_LT, 
                    (FuncPtr)mmi_clog_pbapc_lt_tab_enter, 
                    NULL);
#else /* __MMI_CLOG_TAB_SUPPORT__ */
    menu_gid = cui_menu_create(gid,
                     CUI_MENU_SRC_TYPE_RESOURCE,
                     CUI_MENU_TYPE_APPSUB,
                     MEMU_ID_CLOG_PBAPC,
                     MMI_TRUE,
                     NULL);
        
    cui_menu_set_default_title_by_id(menu_gid, STR_ID_CLOG_CALL_LOG, GetRootTitleIcon(MAIN_MENU_CALL_LOG));
    
    cui_menu_set_default_left_softkey_by_id(menu_gid, STR_GLOBAL_OK);
    
    cui_menu_run(menu_gid);
#endif /* __MMI_CLOG_TAB_SUPPORT__ */
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid         [IN]   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_launch(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // here need to judge wheather the data is ready?

    if (mmi_frm_group_is_present(GRP_ID_CLOG_PBAPC))
    {
        mmi_frm_group_close(GRP_ID_CLOG_PBAPC);
    }

    gid = mmi_frm_group_create_ex(parent_gid, GRP_ID_CLOG_PBAPC, mmi_clog_pbapc_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_clog_pbapc_enter(gid);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_phapc_delaunch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_phapc_delaunch(void)
{
    if (mmi_frm_group_is_present(GRP_ID_CLOG_PBAPC))
    {
        mmi_frm_group_close(GRP_ID_CLOG_PBAPC);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_to_storage_path
 * DESCRIPTION
 *  
 * PARAMETERS      
 *  sel_menu_id         [IN]        
 * RETURNS
 *  srv_phb_pbap_storage_enum
 *****************************************************************************/
srv_phb_pbap_storage_enum mmi_clog_pbapc_menu_to_storage_path(MMI_MENU_ID sel_menu_id)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sel_menu_id)
    {
        case MENU_ID_CLOG_PBAPC_DIALED_CALL:
            return SRV_PHB_PBAP_STORAGE_PHONE_OCH;
        case MENU_ID_CLOG_PBAPC_MISSED_CALL:
            return SRV_PHB_PBAP_STORAGE_PHONE_MCH;
        case MENU_ID_CLOG_PBAPC_RECVED_CALL:
            return SRV_PHB_PBAP_STORAGE_PHONE_ICH;
        case MENU_ID_CLOG_PBAPC_ALL_CALL:
            return SRV_PHB_PBAP_STORAGE_PHONE_CCH;
        default:
            {
                EXT_ASSERT(0, 0, 0, 0);
            } 
            break;
    }
    return SRV_PHB_PBAP_STORAGE_PHONE_CCH;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_select_hdlr
 * DESCRIPTION
 *  change static to not static
 * PARAMETERS      
 *  sel_menu_id         [IN]        
 * RETURNS
 * add para gid to test ehy not show processing and change static to non-static
 *  
 *****************************************************************************/
 void mmi_clog_pbapc_select_hdlr(MMI_MENU_ID sel_menu_id, MMI_ID gid)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbap_storage_enum lt_storage;
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = NULL;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sel_menu_id)
    {
        case MENU_ID_CLOG_PBAPC_MISSED_CALL:
        case MENU_ID_CLOG_PBAPC_DIALED_CALL:       
        case MENU_ID_CLOG_PBAPC_RECVED_CALL:
        case MENU_ID_CLOG_PBAPC_ALL_CALL:
        {   
            lt_storage = mmi_clog_pbapc_menu_to_storage_path(sel_menu_id);

            clog_pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();         
            index =  clog_pbapc_cntx->index;
            clog_pbapc_cntx ->is_parse = 2;
            MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_SELECT_HDLR,g_mmi_clog_pbapc_cntx.path, lt_storage, index,clog_pbapc_cntx->only_update[index]);
            if (clog_pbapc_cntx->only_update[index])
            {   
                g_only_update_data = MMI_TRUE; 
            }
            else if (gid)
            {
                g_only_update_data = MMI_FALSE;  
                g_mmi_clog_pbapc_lt_inst.self_gid = gid;
            }
            mmi_clog_prepare_data(sel_menu_id,gid);
            mmi_clog_pbapc_read_folder(lt_storage);
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
            #endif               
        }
        break;
        default:
            break;
    }
}


void mmi_clog_prepare_data(MMI_MENU_ID sel_menu_id, MMI_ID gid)
{
    srv_phb_pbap_storage_enum lt_storage;
    U8 index;
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = NULL;
    lt_storage = mmi_clog_pbapc_menu_to_storage_path(sel_menu_id);
    clog_pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    index = clog_pbapc_cntx->index;

    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_IS_IN_BACKWARD, g_only_update_data, mmi_frm_is_in_backward_scenario(),index,clog_pbapc_cntx->flag[clog_pbapc_cntx->index]);
    if ((!g_folder_exist && 
    srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, &clog_pbapc_cntx->addr[index])) && !clog_pbapc_cntx->only_update[index]&& !clog_pbapc_cntx->flag[index])// two times & not first enter 
    {
        mmi_clog_pbapc_processing_show_ex(gid,MMI_CLOG_PBAPC_OP_TYPE_LT_LIST, lt_storage);
    }

    if (!srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, &clog_pbapc_cntx->addr[index]) || clog_pbapc_cntx->is_parse == 1)
    {
        if (gid != 0)
        {
            g_mmi_clog_pbapc_lt_inst.self_gid = gid;

        }
    }
    kal_prompt_trace(MOD_MMI, "[TEST]mmi_clog_prepare_data: self_gid = %d", g_mmi_clog_pbapc_lt_inst.self_gid);
    mmi_clog_pbapc_init();
    if (mmi_frm_is_in_backward_scenario())
    {
        g_mmi_clog_need_save_hlt_idx.is_need_save_idx = MMI_TRUE;
    }
    else
    {
        g_mmi_clog_need_save_hlt_idx.is_need_save_idx = MMI_FALSE;
    }
    
    g_mmi_clog_pbapc_cntx.cb = mmi_clog_pbapc_read_cb;
    g_mmi_clog_pbapc_cntx.path = lt_storage;//for mmi_clog_pbapc_vcard_object_to_clog interface
    //g_mmi_clog_pbapc_lt_inst.self_gid = gid;
}


#define MMI_CLOG_PBAPC_LT_UI

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET mmi_clog_pbapc_lt_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_GROUP_DEINIT)
    {     
        mmi_clog_pbapc_deinit();
        memset(&g_mmi_clog_pbapc_lt_inst, 0 , sizeof(mmi_clog_pbapc_lt_inst_struct));        
    }
  
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_item_hlt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sel     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_item_hlt_hdlr(S32 sel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_clog_pbapc_lt_inst.sel_log_idx = sel;
    g_mmi_clog_need_save_hlt_idx.call_info = &(g_mmi_clog_need_save_hlt_idx.save_info);
    memcpy( g_mmi_clog_need_save_hlt_idx.call_info, g_mmi_clog_pbapc_clog_info_cache[sel].clog_info, sizeof(mmi_clog_pbap_info_struct));
    //g_mmi_clog_need_save_hlt_idx.call_info = g_mmi_clog_pbapc_clog_info_cache[sel].clog_info;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_get_title_by_lt_id
 * DESCRIPTION
 *  
 * PARAMETERS        
 *  lt_storage       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_STR_ID mmi_clog_pbapc_lt_get_title_by_storageID(srv_phb_pbap_storage_enum lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_SHOW_LIST, lt_storage, 0);
    switch(lt_storage)
	{
		case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
            return STR_GLOBAL_DIALLED_CALLS;
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
            return STR_GLOBAL_MISSED_CALLS;
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
            return STR_GLOBAL_RECEIVED_CALLS;
        case SRV_PHB_PBAP_STORAGE_PHONE_CCH:
            return STR_ID_CLOG_ALL_CALL;
        default:
            break;
	}
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_get_img_by_lt_id
 * DESCRIPTION
 *  
 * PARAMETERS        
 *  lt_storage       [IN]        
 * RETURNS
 *  MMI_IMG_ID
 *****************************************************************************/
static MMI_IMG_ID mmi_clog_pbapc_lt_get_img_by_lt_storage(srv_phb_pbap_storage_enum lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(lt_storage)
	{
		case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
            return IMG_ID_CLOG_DIALED_CALL;
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
            return IMG_ID_CLOG_MISSED_CALL;
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
            return IMG_ID_CLOG_RECVED_CALL; 
        case SRV_PHB_PBAP_STORAGE_PHONE_CCH:
            return IMG_ID_CLOG_ALL_CALL;
        default:
            break;
	}
    return 0;
}


static U16 mmi_clog_pbapc_lt_get_index_by_storage(srv_phb_pbap_storage_enum lt_storage)
{
    U16 index;
    switch(lt_storage)
	{
		case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
            index = 0;
            break;
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
            index = 1;
            break;
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
            index = 2; 
        case SRV_PHB_PBAP_STORAGE_PHONE_CCH:
            index = 3;
        default:
            break;
	}
    return index;
}


static MMI_IMG_ID mmi_clog_pbapc_lt_get_img_by_call_type(mmi_clog_pbapc_clt_enum call_type)
{
    switch(call_type)
    {
        case MMI_CLOG_PBAPC_CLT_DIALED:
            return IMG_ID_CLOG_DIALED_CALL;
        case  MMI_CLOG_PBAPC_CLT_MISSED:
            return IMG_ID_CLOG_MISSED_CALL;
        case  MMI_CLOG_PBAPC_CLT_RECVED: 
            return IMG_ID_CLOG_RECVED_CALL;
        case MMI_CLOG_PBAPC_CLT_ALL:
            return IMG_ID_CLOG_ALL_CALL;
        default:
            return IMG_ID_CLOG_UNKOWN_CALL;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_get_string
 * DESCRIPTION
 *  
 * PARAMETERS     
 *  log             [IN]     
 *  str_buff        [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_get_string(mmi_clog_pbap_info_struct *call_log, WCHAR *str_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR post[20];
    U32 post_len = 0;   
    const WCHAR *unknown_cid;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (call_log->name[0] == '\0' && call_log->cid[0] == '\0')
    {
        unknown_cid = (const WCHAR*)get_string(STR_ID_CLOG_UNKNOWN_NUMBER);	
		mmi_wcsncpy((WCHAR*) str_buff, unknown_cid, MAX_SUBMENU_CHARACTERS);
    }
    else if (call_log->name[0] == '\0')
    {
        mmi_asc_n_to_wcs((WCHAR*) str_buff, (CHAR*)call_log->cid, (MAX_SUBMENU_CHARACTERS - post_len));
    }
    else
    {
		mmi_wcsncpy((WCHAR*) str_buff, (const WCHAR*)call_log->name, MAX_SUBMENU_CHARACTERS - post_len);
    }

    if (post_len)
        mmi_wcscat((WCHAR*) str_buff, (const WCHAR*)post);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_get_log_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [IN]        
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static pBOOL mmi_clog_pbapc_lt_get_log_item(S32 item_index, UI_string_type str_buff, U8 **img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < 0 || item_index >= (S32) g_mmi_clog_pbapc_lt_inst.total_num)
    {
        MMI_ASSERT(item_index < (S32) g_mmi_clog_pbapc_lt_inst.total_num);
        return MMI_FALSE;
    }
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
    mmi_clog_pbapc_lt_get_string(g_mmi_clog_pbapc_clog_info_cache[item_index].clog_info, str_buff);    
#else /**/
    mmi_clog_pbapc_lt_get_string(&g_mmi_clog_pbapc_clog_info_cache[item_index].clog_info, str_buff);    
#endif /**/

    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_BT_GET_ITEM, g_mmi_clog_pbapc_cntx.path , item_index, g_mmi_clog_pbapc_clog_info_cache[item_index].clog_info->call_type);
    if (g_mmi_clog_pbapc_cntx.path == SRV_PHB_PBAP_STORAGE_PHONE_CCH)
    {
        *img_buff_p =
        (U8*) 
        GetImage(mmi_clog_pbapc_lt_get_img_by_call_type(g_mmi_clog_pbapc_clog_info_cache[item_index].clog_info->call_type));
    }
    else
    {
        *img_buff_p =
        (U8*) GetImage(mmi_clog_pbapc_lt_get_img_by_lt_storage(g_mmi_clog_pbapc_cntx.path));//?
    } 
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_get_multi_log_items
 * DESCRIPTION
 *  Asyncdynamic list item load function
 * PARAMETERS
 *  start_index      :    [IN]     Start index of menu item
 *  menu_data        :    [OUT]    A pointer of parameter to store the menu data
 *  item_count        :    [IN]     The number of load menu items
 * RETURNS
 *  S32
 * RETURN VALUES
 *  Number of items can be retrieved
 *****************************************************************************/
S32 mmi_clog_pbapc_lt_get_multi_log_items(S32 start_index, gui_iconlist_menu_item *menu_data, S32 item_count)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 total_count;
    S32 i, items = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_count = (S32) g_mmi_clog_pbapc_lt_inst.total_num;
    
    for (i = start_index; items < item_count && i < total_count; i++, items++)
    {
        mmi_clog_pbapc_lt_get_log_item(i, 
            menu_data[items].item_list[0], 
            menu_data[items].image_list, 0);
    }
    return items;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_get_log_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_clog_pbapc_lt_get_log_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_pbap_info_struct *call_log;
    applib_time_struct refer_time;
 
    memset((void *)&refer_time, 0x0, sizeof(applib_time_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (item_index < 0 || item_index >= (S32) g_mmi_clog_pbapc_lt_inst.total_num)
    {
        return MMI_FALSE;
    }
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
    call_log = g_mmi_clog_pbapc_clog_info_cache[item_index].clog_info;
#else /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/
    call_log = & g_mmi_clog_pbapc_clog_info_cache[item_index].clog_info;
#endif /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/    
    if (applib_dt_compare_time(&call_log->timestamp[0],&refer_time, NULL)== DT_TIME_EQUAL)
    {
        mmi_wcscat(hint_array[0], (WCHAR *)GetString(STR_ID_CLOG_UNKOWN_CALL));
    }
    else
    {
    date_string((UI_time*) & call_log->timestamp[0], hint_array[0], DT_IDLE_SCREEN);
    mmi_wcscat(hint_array[0], L" ");
    time_string((UI_time*) & call_log->timestamp[0], 
            (UI_string_type) (hint_array[0] + mmi_wcslen((const WCHAR*)hint_array[0])), 
            DT_IDLE_SCREEN);
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_clog_pbapc_op_enter(GRP_ID_CLOG_PBAPC_LT, MMI_CLOG_PBAPC_OP_TYPE_LT_LIST, g_mmi_clog_pbapc_lt_inst.sel_log_idx);//MODIFY
    MMI_TRACE(MMI_CLOG_TRC_INFO,TRC_MMI_CLOG_LSK_HDLR, g_mmi_clog_pbapc_lt_inst.self_gid);
    mmi_clog_pbapc_op_enter(g_mmi_clog_pbapc_lt_inst.self_gid, MMI_CLOG_PBAPC_OP_TYPE_LT_LIST, g_mmi_clog_pbapc_lt_inst.sel_log_idx);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_rsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TAB_BAR_SUPPORT_TAB_PAGE__) || defined (__MMI_PHB_PBAPC_SYNC_CONTACT__) 
    mmi_frm_group_close(GRP_ID_CLOG_LAYOUT);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    mmi_frm_scrn_close_active_id();
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_csk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_pbapc_viewer_enter(g_mmi_clog_pbapc_lt_inst.self_gid, g_mmi_clog_pbapc_lt_inst.sel_log_idx);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_send_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_send_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_pbapc_make_call(GRP_ID_CLOG_PBAPC_LT, g_mmi_clog_pbapc_lt_inst.sel_log_idx, MMI_TRUE);  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_read_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_inst      [IN]        parent inst      
 * RETURNS
 *  
 *****************************************************************************/
void mmi_clog_pbapc_read_cb(S32 result)
{
    S32 fs_ret = -1;
    MMI_BOOL is_active;
    MMI_BOOL is_connect;
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = NULL;
    clog_pbapc_cntx  = mmi_clog_get_pbapc_cntx_ex();
    is_connect = srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, &clog_pbapc_cntx->addr[clog_pbapc_cntx->index]);
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_READ_CB_IS_CONNECT, is_connect);

#ifdef __MTK_TARGET__
    if (is_connect)
    {
        FS_Delete(SRV_PHB_PBAPC_FOLDER_PATH);
    }
#endif
   
    if(result < 0)
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, GRP_ID_CLOG_PBAPC, NULL);
        return;
    }

#ifndef __MMI_CLOG_TAB_SUPPORT__
    is_active = mmi_clog_pbapc_is_btsc_active();

    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_CURR_ACTIVE, is_active , g_exist_flag, 1);
    if (is_active)
    {
        mmi_clog_pbapc_lt_show_list();
    }
    else
    {
        return;
    }
#endif
}


#ifdef __MMI_HF_SUPPORT__
static void mmi_clog_pbap_update_log()
{
    StopTimer(MMI_CLOG_PBAPC_TIMER);
    kal_prompt_trace(MOD_MMI, "[TEST]mmi_clog_pbap_update_log");
    mmi_clog_pbapc_select_hdlr(MENU_ID_CLOG_PBAPC_ALL_CALL, 0);
}


void mmi_clog_update_log_by_end_call(srv_ucm_bt_release_call_ind_struct *para)//NEED NEW API
{
    S32 index;
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = NULL;

    clog_pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();
    index = srv_pbapc_get_btd_index(&(para->dev_addr), SRV_PBAPC_FLAG_CONNECTED);

    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_UPDATE_BY_END_CALL,index, mmi_frm_scrn_get_active_id(), para->dev_addr);
    if (index >= 0)
    {
        //if (mmi_frm_scrn_get_active_id() != SCR_ID_CLOG_LAYOUT && !mmi_frm_group_is_present(GRP_ID_CLOG_LAYOUT))
        {
            clog_pbapc_cntx->addr[index] = para->dev_addr;
            clog_pbapc_cntx->index = index;// only has end call first, then enter ,if enter first , it will not update.
            clog_pbapc_cntx->only_update[index]= MMI_TRUE;// NOW write is 0 first
            StartTimer(MMI_CLOG_PBAPC_TIMER, 1000, mmi_clog_pbap_update_log);
        }
    }
}
#endif

static void mmi_clog_send_key_hdler()
{
    mmi_clog_pbapc_make_bt_call(0, g_mmi_clog_pbapc_lt_inst.sel_log_idx);
}


#ifdef __MMI_CLOG_TAB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_get_title_by_lt_id
 * DESCRIPTION
 *  
 * PARAMETERS        
 *  lt_storage       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U16 mmi_clog_pbapc_lt_get_image_by_storageID(srv_phb_pbap_storage_enum lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(lt_storage)
	{
		case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
            return IMG_ID_CLOG_TAB_DIALED_CALL;
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
            return IMG_ID_CLOG_TAB_MISSED_CALL;
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
            return IMG_ID_CLOG_TAB_RECVED_CALL;  
        default:
            break;
	}
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_storageID_2_scrID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sel_lt_storage        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_clog_pbapc_lt_storageID_2_scrID(srv_phb_pbap_storage_enum sel_lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID Page_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(sel_lt_storage)
    {
	    case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
            Page_ID = SCR_ID_CLOG_PBAPC_LT_DIALED_CALL;
            break;
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
            Page_ID = SCR_ID_CLOG_PBAPC_LT_MISSED_CALL;
            break;
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
            Page_ID = SCR_ID_CLOG_PBAPC_LT_RECVED_CALL;
            break;
        default:
            Page_ID = SCR_ID_CLOG_PBAPC_LT_DIALED_CALL;
            break;
    }
    
    return Page_ID;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_storageID_2_tabID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sel_lt_storage        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
mmi_clog_lt_id_enum mmi_clog_pbapc_lt_storageID_2_tabID(srv_phb_pbap_storage_enum sel_lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_lt_id_enum tab_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(sel_lt_storage)
    {
	    case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
            tab_ID = MMI_CLOG_LT_ID_DIALED_CALL;
            break;
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
            tab_ID = MMI_CLOG_LT_ID_MISSED_CALL;
            break;
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
            tab_ID = MMI_CLOG_LT_ID_RECVED_CALL;
            break;
        default:
            tab_ID = MMI_CLOG_LT_ID_DIALED_CALL;
            break;
    }
    
    return tab_ID;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_tabID_2_storageID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tab_ID        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
srv_phb_pbap_storage_enum mmi_clog_pbapc_lt_tabID_2_storageID(mmi_clog_lt_id_enum tab_ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbap_storage_enum storage_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(tab_ID)
    {
	    case MMI_CLOG_LT_ID_DIALED_CALL:
            storage_ID = SRV_PHB_PBAP_STORAGE_PHONE_OCH;
            break;
        case MMI_CLOG_LT_ID_MISSED_CALL:
            storage_ID = SRV_PHB_PBAP_STORAGE_PHONE_MCH;
            break;
        case MMI_CLOG_LT_ID_RECVED_CALL:
            storage_ID = SRV_PHB_PBAP_STORAGE_PHONE_ICH;
            break;
        default:
            storage_ID = SRV_PHB_PBAP_STORAGE_PHONE_OCH;
            break;
    }
    
    return storage_ID;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_tab_set_page_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  page_info        [IN]     
 *  lt_id        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_lt_tab_set_page_info(mmi_frm_tab_struct *page_info, mmi_clog_lt_id_enum lt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    page_info[lt_id].screen_id = SCR_ID_CLOG_PBAPC_LT_DIALED_CALL + lt_id - MMI_CLOG_LT_ID_DIALED_CALL;
    page_info[lt_id].tab_icon = (U8*) GetImage(IMG_ID_CLOG_TAB_DIALED_CALL + lt_id - MMI_CLOG_LT_ID_DIALED_CALL);
    page_info[lt_id].tab_entry_func = (FuncPtr)mmi_clog_pbapc_lt_tab_enter_page;
    page_info[lt_id].tab_string = NULL;
    page_info[lt_id].user_data = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_tab_exit_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_lt_tab_exit_page(mmi_scrn_essential_struct *scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_frm_general_tab_exit(); */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_tab_enter_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grp_data        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_lt_tab_enter_page(mmi_scrn_essential_struct *grp_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buff;
    S32 category_error_flag;
    U32 has_lsk = MMI_TRUE;
    mmi_clog_lt_id_enum tab_id;
    srv_phb_pbap_storage_enum storage_id;
    MMI_ID page_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tab_id = mmi_frm_scrn_tab_get_active_page_index();
    storage_id = mmi_clog_pbapc_lt_tabID_2_storageID(tab_id);
    page_scr_id = mmi_clog_pbapc_lt_storageID_2_scrID(storage_id);    

    if(!mmi_frm_scrn_tab_page_enter(
            g_mmi_clog_pbapc_lt_inst.self_gid,
            SCR_ID_CLOG_PBAPC_LT,
            page_scr_id,
            (FuncPtr) mmi_clog_pbapc_lt_tab_exit_page,
            (FuncPtr) mmi_clog_pbapc_lt_tab_enter_page,
            MMI_FRM_TAB_PAGE))
    {
        return;
    }

    g_mmi_clog_pbapc_lt_inst.total_num = mmi_clog_pbap_current_num;

    if (g_mmi_clog_pbapc_lt_inst.total_num)
        has_lsk = MMI_TRUE; 
    else /*it also can set other string*/
        wgui_cat_set_list_menu_empty_lable(get_string(STR_GLOBAL_EMPTY));
        
    //gui_buff = mmi_frm_scrn_tab_page_get_active_gui_buf();
    gui_buff = NULL;
    RegisterHighlightHandler(mmi_clog_pbapc_lt_item_hlt_hdlr);
    
    wgui_cat1031_show(
        get_string(mmi_clog_pbapc_lt_get_title_by_storageID(storage_id)),
        (PU8)GetImage(mmi_clog_pbapc_lt_get_image_by_storageID(storage_id)),
        (has_lsk == MMI_FALSE ? NULL : get_string(STR_GLOBAL_OPTIONS)),
        (has_lsk == MMI_FALSE ? NULL : (PU8)GetImage(IMG_GLOBAL_OPTIONS)),
        get_string(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        g_mmi_clog_pbapc_lt_inst.total_num,
        mmi_clog_pbapc_lt_get_multi_log_items,
        mmi_clog_pbapc_lt_get_log_hint,
        g_mmi_clog_pbapc_lt_inst.sel_log_idx,
        tab_id,
        IMG_ID_CLOG_MISSED_CALL,
        0, /* Just to get image demision but not care what it is */
        gui_buff,
        &category_error_flag);

    if (g_mmi_clog_pbapc_lt_inst.total_num)
    {
        SetCenterSoftkeyFunction(mmi_clog_pbapc_lt_csk_hdlr, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_clog_pbapc_lt_lsk_hdlr, KEY_EVENT_UP);
    }

    SetRightSoftkeyFunction(mmi_clog_pbapc_lt_rsk_hdlr, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif 
    
#if defined (__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_clog_pbapc_lt_set_tap_hdlr();
#endif 

    /* Reload log data after change select lt_id */
    if(g_mmi_clog_pbapc_lt_inst.sel_lt_storage != storage_id)
    {
        g_mmi_clog_pbapc_lt_inst.sel_lt_storage = storage_id;
        
        mmi_clog_pbapc_processing_show(g_mmi_clog_pbapc_lt_inst.self_gid, 
                    SCR_ID_CLOG_PBAPC_LT_PROCESSING, 
                    MMI_CLOG_PBAPC_OP_TYPE_LT_LIST, 
                    g_mmi_clog_pbapc_lt_inst.sel_lt_storage);

        mmi_clog_pbapc_deinit();
        mmi_clog_pbapc_init();
        g_mmi_clog_pbapc_cntx.cb = mmi_clog_pbapc_read_cb;
        mmi_clog_pbapc_read_folder(g_mmi_clog_pbapc_lt_inst.sel_lt_storage);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_tab_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_lt_tab_exit(mmi_scrn_essential_struct *scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_frm_general_tab_exit(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_tab_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_lt_tab_enter(mmi_scrn_essential_struct *scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_clog_lt_id_enum tab_id;
    mmi_frm_tab_struct page_info[MMI_CLOG_LT_ID_RECVED_CALL+1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tab_id = mmi_clog_pbapc_lt_storageID_2_tabID(g_mmi_clog_pbapc_lt_inst.sel_lt_storage);

    for (i=MMI_CLOG_LT_ID_DIALED_CALL; i<=MMI_CLOG_LT_ID_RECVED_CALL; i++ )
    {
        mmi_clog_pbapc_lt_tab_set_page_info(page_info, i);
    }

    if(!mmi_frm_scrn_tab_enter(
        g_mmi_clog_pbapc_lt_inst.self_gid,
        SCR_ID_CLOG_PBAPC_LT,
        (FuncPtr) mmi_clog_pbapc_lt_tab_exit,
        (FuncPtr) mmi_clog_pbapc_lt_tab_enter,
        page_info,
        (U8) MMI_CLOG_LT_ID_RECVED_CALL+1,
        (U8) tab_id))
    {
        ASSERT(0);
    }
}
#else

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_show_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_show_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    MMI_ID scrn_id;
    U8 index;
    mmi_clog_pbapc_ex_inst_struct *cntx =  mmi_clog_get_pbapc_cntx_ex(); 
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_clog_pbapc_lt_inst.total_num = mmi_clog_pbap_current_num;

#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    index = cui_tab_get_select_index(SCR_ID_CLOG_LAYOUT);
#else
    index = mmi_frm_scrn_tab_get_active_page_index();
#endif
#ifdef __MMI_TAB_PAGE_SUPPORT_TAB_PAGE__
#if SRV_PBAPC_LINK_NUM >= 2
    if (index == 1)
        gui_buffer = cui_tab_get_screen_gui_buf(MMI_CLOG_LT_ID_BT,GRP_ID_CLOG_SUB_BT_DEVICE);
    else
        gui_buffer = cui_tab_get_screen_gui_buf(MMI_CLOG_LT_ID_BT_V3,SCR_ID_CLOG_SUB_BT_DEVICE_V3);
#else
    gui_buffer = cui_tab_get_screen_gui_buf(MMI_CLOG_LT_ID_BT,GRP_ID_CLOG_SUB_BT_DEVICE);
#endif
#else
    gui_buffer = (U8*)mmi_frm_scrn_get_active_gui_buf();
#endif
    RegisterHighlightHandler(mmi_clog_pbapc_lt_item_hlt_hdlr);
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_CONN_IS_BACKWARD, g_mmi_clog_need_save_hlt_idx.is_need_save_idx);
    if (g_mmi_clog_need_save_hlt_idx.is_need_save_idx)
    {
        mmi_clog_pbap_info_struct *save_info = g_mmi_clog_need_save_hlt_idx.call_info;
        mmi_clog_pbap_info_struct *log_info = g_mmi_clog_pbapc_clog_info_cache[g_mmi_clog_pbapc_lt_inst.sel_log_idx].clog_info;

        MMI_TRACE(MMI_CLOG_TRC_INFO,TRC_MMI_CLOG_BT_DIALER_CONN_SAVE_TIME_STAMP,save_info->timestamp[0].nHour,save_info->timestamp[0].nMin, save_info->timestamp[0].nSec);
        MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_CONN_TIME_STAMP,log_info->timestamp[0].nHour,log_info->timestamp[0].nMin, log_info->timestamp[0].nSec);

        if (applib_dt_compare_time(&log_info->timestamp[0], &save_info->timestamp[0], NULL) != DT_TIME_EQUAL)
        {
            g_mmi_clog_pbapc_lt_inst.sel_log_idx = 0;
            gui_buffer = NULL;
        }
    }
    else 
    {
        gui_buffer  = NULL;
        g_mmi_clog_pbapc_lt_inst.sel_log_idx = 0;      
    }


    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_SHOW_LIST1,cntx->only_update[cntx->index], g_exist_flag);

    if (!cntx->only_update[cntx->index])
    {
        mmi_clog_pbapc_show_category(1, gui_buffer);
    }
       MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_IS_NEED_SEND_REQ,clog_pbapc_cntx->index, clog_pbapc_cntx->is_parse);
#if SRV_PBAPC_LINK_NUM >= 2

    if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, &clog_pbapc_cntx->addr[clog_pbapc_cntx->index]))
    {
        //MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_IS_NEED_SEND_REQ,clog_pbapc_cntx->is_parse);
        if (clog_pbapc_cntx->is_parse == 2)
        {
            mmi_clog_pbapc_select_hdlr(MENU_ID_CLOG_PBAPC_ALL_CALL, 0);

        }
    }
#else
#if defined ( __MMI_TELEPHONY_SUPPORT__ ) || defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)
    if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, &clog_pbapc_cntx->addr[clog_pbapc_cntx->index]))
    {
        //MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_IS_NEED_SEND_REQ,clog_pbapc_cntx->is_parse);
        if (clog_pbapc_cntx->is_parse == 2)
        {
            mmi_clog_pbapc_select_hdlr(MENU_ID_CLOG_PBAPC_ALL_CALL, 0);

        }
    }
#endif /*__MMI_TELEPHONY_SUPPORT__*/
#endif
} 


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 * evt       [IN]     
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static MMI_RET mmi_clog_pbapc_lt_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_clog_pbapc_lt_show_list();
            break;
        default:
            break;
    }  
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_list_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id      [IN]
 *  lt_type_id      [IN]
 * RETURNS
 *  
 *****************************************************************************/
static MMI_ID mmi_clog_pbapc_lt_list_enter(MMI_ID parent_id, srv_phb_pbap_storage_enum sel_lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_mmi_clog_pbapc_lt_inst, 0 , sizeof(mmi_clog_pbapc_lt_inst_struct));
    g_mmi_clog_pbapc_lt_inst.sel_lt_storage = sel_lt_storage;
	
    g_mmi_clog_pbapc_lt_inst.self_gid = mmi_frm_group_create_ex(parent_id,
        GRP_ID_CLOG_PBAPC_LT, mmi_clog_pbapc_lt_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_mmi_clog_pbapc_lt_inst.sel_log_idx = 0;
	    
    mmi_frm_scrn_create(g_mmi_clog_pbapc_lt_inst.self_gid, SCR_ID_CLOG_PBAPC_LT, 
        mmi_clog_pbapc_lt_scrn_proc, NULL);

    return g_mmi_clog_pbapc_lt_inst.self_gid;
}
#endif /* __MMI_CLOG_TAB_SUPPORT__ */

#if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_set_tap_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_set_tap_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_register_tap_callback(mmi_clog_pbapc_lt_tap_action_hdlr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_lt_tap_action_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tap_type        [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_lt_tap_action_hdlr(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {        
       //mmi_clog_pbapc_viewer_enter(GRP_ID_CLOG_PBAPC_LT, g_mmi_clog_pbapc_lt_inst.sel_log_idx);
        mmi_clog_pbapc_viewer_enter(g_mmi_clog_pbapc_lt_inst.self_gid, g_mmi_clog_pbapc_lt_inst.sel_log_idx);
    }
}

#endif /*defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)*/

#define MMI_CLOG_PBAPC_ACT

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_make_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  caller_gid        [IN]  
 *  log_idx            [IN]  
 *  is_send_key       [IN]  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_make_call(U16 caller_gid, U16 log_idx, MMI_BOOL is_send_key)
{
#ifdef __MMI_BT_DIALER_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_dial_option_bt(g_mmi_clog_pbapc_clog_info_cache[log_idx].clog_info->cid);
#endif /*__MMI_BT_DIALER_SUPPORT__*/

}

static void mmi_clog_pbapc_make_bt_call(U16 caller_gid, U16 log_idx)
{
    S32 ret;
    srv_clog_log_struct log;
    mmi_ucm_make_call_para_struct call_para;
    U16 num[41];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* if (MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_ACT_FLAG_CALL_BY_SEND_KEY))
        mmi_ucm_init_call_para_for_sendkey(&call_para);
    else*/ 
        mmi_ucm_init_call_para(&call_para);
    
	/*Voice call init*/
    
   /* if (MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_ACT_FLAG_CALL_VOICE_ONLY))
        call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
    else if (MMI_CLOG_CHECK_BIT(inst->flags, MMI_CLOG_ACT_FLAG_CALL_VIDEO_ONLY))
        call_para.dial_type = SRV_UCM_VIDEO_CALL_TYPE;*/
    
    /* Revise it */
    /*if (log.data.call_log.sub_type == SRV_CLOG_CALL_TYPE_VOIP)
        call_para.dial_type = SRV_UCM_VOIP_CALL_TYPE;*/
        
    //call_para.ucs2_num_uri = (U16*)g_mmi_clog_pbapc_clog_info_cache[log_idx].clog_info->cid;
    mmi_asc_to_ucs2((CHAR*)num, g_mmi_clog_pbapc_clog_info_cache[log_idx].clog_info->cid);
    call_para.ucs2_num_uri = num;

    call_para.adv_para.is_ip_dial = MMI_FALSE;
    call_para.adv_para.after_make_call_callback = mmi_clog_act_make_call_cb;   
    call_para.adv_para.after_callback_user_data = NULL;
    call_para.adv_para.phb_data = g_mmi_clog_pbapc_clog_info_cache[log_idx].clog_info->name;
    mmi_ucm_call_launch(caller_gid, &call_para);
}


static void mmi_clog_act_make_call_cb(mmi_ucm_after_make_call_cb_struct *para)
{ 
    mmi_frm_group_close(g_mmi_clog_pbapc_op_inst.parent_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid         [IN]  
 *  log_idx            [IN]  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_send_sms(mmi_id parent_gid, U16 log_idx)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_write_msg_para_struct para;
    mmi_clog_pbap_info_struct *call_log;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memset(&para, 0 , sizeof(mmi_sms_write_msg_para_struct));

    para.ascii_addr = g_mmi_clog_pbapc_clog_info_cache[log_idx].clog_info->cid;
    mmi_sms_write_msg_lanch(parent_gid,&para);

}


static void mmi_clog_pbapc_save_to_contact(mmi_id parent_gid, U16 log_idx)
{
    S32 ret;
    srv_clog_log_struct log;
    U16 number[42];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ID sub_gid= cui_phb_save_contact_create(parent_gid);
    if (MMI_CLOG_IS_GID_INVALID(sub_gid))
    {
       // mmi_clog_act_handle_srv_error(inst, ret);
        return;
    }

    if ( g_mmi_clog_pbapc_clog_info_cache[log_idx].clog_info->name[0] != '\0')
    {
        cui_phb_save_contact_set_name(sub_gid, g_mmi_clog_pbapc_clog_info_cache[log_idx].clog_info->name, NULL);
    }
    mmi_asc_to_ucs2((CHAR*)number,g_mmi_clog_pbapc_clog_info_cache[log_idx].clog_info->cid);
    cui_phb_save_contact_set_number(sub_gid, number);
    cui_phb_save_contact_run(sub_gid);
}


#define MMI_CLOG_PBAPC_OPTION_UI
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_op_evt_mm_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_clog_pbapc_op_evt_mm_select_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    group_id = mmi_frm_group_create_ex(g_mmi_clog_pbapc_op_inst.parent_gid, GRP_ID_AUTO_GEN, mmi_clog_act_pbap_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    switch(evt->highlighted_menu_id)
    {
        case MENU_ID_CLOG_PBAPC_VIEW:
            //mmi_clog_pbapc_viewer_enter(g_mmi_clog_pbapc_op_inst.parent_gid, g_mmi_clog_pbapc_op_inst.log_idx);
            mmi_clog_pbapc_viewer_enter(group_id, g_mmi_clog_pbapc_op_inst.log_idx);

            break;
        case MENU_ID_CLOG_PBAPC_MAKE_CALL:
            mmi_clog_pbapc_make_bt_call(0, g_mmi_clog_pbapc_op_inst.log_idx);
            //mmi_clog_pbapc_make_call(g_mmi_clog_pbapc_op_inst.parent_gid, g_mmi_clog_pbapc_op_inst.log_idx, MMI_FALSE);
            break;

        case MENU_ID_CLOG_PBAPC_SEND_SMS:
            mmi_clog_pbapc_send_sms(group_id, g_mmi_clog_pbapc_op_inst.log_idx);
            //mmi_clog_pbapc_send_sms(g_mmi_clog_pbapc_op_inst.parent_gid, g_mmi_clog_pbapc_op_inst.log_idx);
            break;
        case MENU_ID_CLOG_SAVE_TO_LOCAL_PHB:
            //mmi_clog_pbapc_save_to_contact(g_mmi_clog_pbapc_op_inst.parent_gid, g_mmi_clog_pbapc_op_inst.log_idx);
            mmi_clog_pbapc_save_to_contact(group_id, g_mmi_clog_pbapc_op_inst.log_idx);
            break;
         default:
            break;
    }   
}


static MMI_RET mmi_clog_act_pbap_group_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
        {
            //cui_phb_save_contact_close(sub_gid);
            mmi_frm_group_close(g_mmi_clog_pbapc_op_inst.parent_gid);
        }
        break;
        default:
            break;
    }

    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_op_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_clog_pbapc_op_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            memset(&g_mmi_clog_pbapc_op_inst, 0x0, sizeof(mmi_clog_pbapc_op_inst_struct));
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_clog_pbapc_op_evt_mm_select_hdlr((cui_menu_event_struct*)evt);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(((cui_menu_event_struct*)evt)->sender_id);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_op_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 *  type            [IN] 
 *  log_idx         [IN] 
 * RETURNS
 *  
 *****************************************************************************/
static MMI_ID mmi_clog_pbapc_op_enter(MMI_ID parent_gid, mmi_clog_pbapc_op_type_enum type, U16 log_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui;
    MMI_ID gid ;
    mmi_clog_pbapc_ex_inst_struct *clog_pbapc_cntx = mmi_clog_get_pbapc_cntx_ex();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parent_gid == GRP_ID_INVALID)
        return GRP_ID_INVALID;

    g_mmi_clog_pbapc_op_inst.log_idx = log_idx;
    g_mmi_clog_pbapc_op_inst.parent_gid = parent_gid;

    if (parent_gid == GRP_ID_CLOG_PBAPC_VIEWER)
    {
        gid = GRP_ID_CLOG_PBAPC_VIEW_OPTION;
    }
    else
    {
        gid = GRP_ID_CLOG_PBAPC_OPTION;

    }
    g_mmi_clog_pbapc_op_inst.parent_gid = mmi_frm_group_create_ex(parent_gid, gid, mmi_clog_pbapc_op_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui = cui_menu_create(
                    gid,
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_OPTION,
                    MENU_ID_CLOG_PBAPC_OPTION,
                    MMI_TRUE,
                    0);
    if (type == MMI_CLOG_PBAPC_OP_TYPE_LIST_VIEWER)               	
        cui_menu_set_item_hidden(cui, MENU_ID_CLOG_PBAPC_VIEW, MMI_TRUE);
    else
        cui_menu_set_item_hidden(cui, MENU_ID_CLOG_PBAPC_VIEW, MMI_FALSE);
     //MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_OP_ENTER, mmi_bt_is_call_supported(), mmi_bt_is_message_access_profile_supported());

    cui_menu_set_item_hidden(cui, MENU_ID_CLOG_PBAPC_MAKE_CALL, MMI_FALSE);
#ifdef __MMI_BTD_BOX_UI_STYLE__
    if(!srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION,&clog_pbapc_cntx->addr[clog_pbapc_cntx->indx])) 
    {
        cui_menu_set_item_disabled(cui, MENU_ID_CLOG_PBAPC_MAKE_CALL, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_disabled(cui, MENU_ID_CLOG_PBAPC_MAKE_CALL, MMI_FALSE);
    }

#endif 

#ifdef __MMI_BTD_BOX_UI_STYLE__
    cui_menu_set_item_hidden(cui, MENU_ID_CLOG_PBAPC_SEND_SMS, MMI_TRUE);
#else /*__MMI_BTD_BOX_UI_STYLE__*/
#if defined(__MMI_WEARABLE_DEVICE__)
    cui_menu_set_item_hidden(cui, MENU_ID_CLOG_PBAPC_SEND_SMS, MMI_TRUE);
#else
    cui_menu_set_item_hidden(cui, MENU_ID_CLOG_PBAPC_SEND_SMS, MMI_FALSE);
#endif
#endif /*__MMI_BTD_BOX_UI_STYLE__*/
#ifndef __MMI_TELEPHONY_SUPPORT__
    cui_menu_set_item_hidden(cui, MENU_ID_CLOG_SAVE_TO_LOCAL_PHB, MMI_TRUE);
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    cui_menu_run(cui);
    return cui;
}

#define MMI_CLOG_PBAPC_VIWER_UI
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt                [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_clog_pbapc_vr_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->evt_id == EVT_ID_GROUP_DEINIT)
    {
        memset(&g_mmi_clog_pbapc_vr_inst, 0x0, sizeof(mmi_clog_pbapc_vr_inst_struct));
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [IN]                
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_clog_pbapc_vr_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
		case EVT_ID_SCRN_INACTIVE:
		{
			mmi_frm_scrmem_free(g_mmi_clog_pbapc_vr_inst.buf);
			g_mmi_clog_pbapc_vr_inst.buf = NULL;
		}
		break;
		case EVT_ID_SCRN_ACTIVE:
			mmi_clog_pbapc_vr_show_text();
		break;
		default:
		 break;
	}
   
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_viewer_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 *  log_idx         [IN]         
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_clog_pbapc_viewer_enter(MMI_ID parent_gid, U16 log_idx)
{
    g_mmi_clog_pbapc_vr_inst.log_idx = log_idx;

    mmi_frm_group_create_ex(parent_gid, GRP_ID_CLOG_PBAPC_VIEWER, mmi_clog_pbapc_vr_group_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
	mmi_frm_scrn_create(GRP_ID_CLOG_PBAPC_VIEWER, SCR_ID_CLOG_PBAPC_VIEWER, mmi_clog_pbapc_vr_scrn_proc, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_vr_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_pbapc_op_enter(GRP_ID_CLOG_PBAPC_VIEWER, MMI_CLOG_PBAPC_OP_TYPE_LIST_VIEWER, g_mmi_clog_pbapc_vr_inst.log_idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_csk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_vr_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_clog_vr_make_call_hdlr(MMI_CLOG_KEY_CSK);
    mmi_clog_pbapc_vr_lsk_hdlr();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_rsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_vr_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_CLOG_PBAPC_VIEWER);
    /* mmi_frm_scrn_close_active_id(); */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_send_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_vr_send_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_pbapc_make_call(GRP_ID_CLOG_PBAPC_VIEWER, g_mmi_clog_pbapc_vr_inst.log_idx, MMI_TRUE);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_format_remove_tail
 * DESCRIPTION
 *  
 * PARAMETERS       
 *  cur_len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_vr_format_remove_tail(U32 cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cur_len >= MMI_CLOG_PBAPC_VR_FORMAT_DATA_LEN);
    g_mmi_clog_pbapc_vr_inst.buf[cur_len - 2] = '\0';
}
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_cp_key_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf             [IN/OUT]         
 *  buf_max_len     [IN]        
 *  cur_len         [IN/OUT]         
 *  key_str_id      [IN]        
 *  value           [IN]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_cp_key_value(WCHAR *buf, U32 buf_max_len, U32 *cur_len, MMI_STR_ID key_str_id, WCHAR *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;
    WCHAR *str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(key_str_id)
	{
		str = get_string(key_str_id);
    	len = mmi_wcslen(str);
    }

	len += (mmi_wcslen(value) + MMI_CLOG_PBAPC_VR_FORMAT_DATA_LEN);
	
    if (*cur_len + len > buf_max_len)
        return MMI_FALSE;
	
	if(key_str_id)
    	kal_wsprintf(buf + *cur_len, "%w%w%w%w", str, L"\n", value, L"\n\n");
	else
		kal_wsprintf(buf + *cur_len, "%w%w", value, L"\n");
    *cur_len = mmi_wcslen(buf);
    return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_format
 * DESCRIPTION
 *  
 * PARAMETERS     
 *  log         [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_format(mmi_clog_pbap_info_struct *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 ret;
    U32 cur_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(g_mmi_clog_pbapc_vr_format_text_tbl) / sizeof(MMI_CLOG_PBAPC_VR_FORMAT_TEXT_PARA_HDLR); i++)
    {
        ret = (g_mmi_clog_pbapc_vr_format_text_tbl[i]) (log, &cur_len);
        if (!ret)
        {
            mmi_clog_pbapc_vr_format_remove_tail(cur_len);
            return ret;
        }
    }
    mmi_clog_pbapc_vr_format_remove_tail( cur_len);
    MMI_ASSERT(ret <= MMI_CLOG_PBAPC_VR_BUF_MAX_LEN);
    return MMI_TRUE;
}

#ifdef __MMI_CLOG_PBAPC_CLOG_TYPE_DETAIL_SHOW__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_get_clt_str_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  clt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_STR_ID mmi_clog_pbapc_vr_get_clt_str_id(mmi_clog_pbapc_clt_enum clt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID str_id = STR_GLOBAL_EMPTY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (clt)
    {
        case MMI_CLOG_PBAPC_CLT_DIALED:
            str_id = STR_ID_CLOG_DIALED_CALL;
            break;

        case MMI_CLOG_PBAPC_CLT_MISSED:
            str_id = STR_ID_CLOG_MISSED_CALL;
            break;

        case MMI_CLOG_PBAPC_CLT_RECVED:
            str_id = STR_ID_CLOG_RECVED_CALL;
            break;
        default:
            break;
    }
    return str_id;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_format_type
 * DESCRIPTION
 *  
 * PARAMETERS    
 *  log         [IN]     
 *  cur_len     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_format_type(mmi_clog_pbap_info_struct *log, U32 *cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = mmi_clog_pbapc_vr_get_clt_str_id((mmi_clog_pbapc_clt_enum)log->call_type);
    return mmi_clog_pbapc_vr_cp_key_value(g_mmi_clog_pbapc_vr_inst.buf, MMI_CLOG_PBAPC_VR_BUF_MAX_LEN, cur_len, STR_ID_CLOG_TYPE, get_string(str_id));
}

#endif /*__MMI_CLOG_PBAPC_CLOG_TYPE_DETAIL_SHOW__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_format_name
 * DESCRIPTION
 *  
 * PARAMETERS   
 *  log         [IN]     
 *  cur_len     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_format_name(mmi_clog_pbap_info_struct *log, U32 *cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* name */
    if (log->name[0] == '\0')
        return MMI_TRUE;
    return mmi_clog_pbapc_vr_cp_key_value(
            g_mmi_clog_pbapc_vr_inst.buf,
            MMI_CLOG_PBAPC_VR_BUF_MAX_LEN,
            cur_len,
            STR_ID_CLOG_NAME,
            log->name);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_format_number
 * DESCRIPTION
 *  
 * PARAMETERS    
 *  log         [IN]     
 *  cur_len     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_format_number(mmi_clog_pbap_info_struct *log, U32 *cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *value;    
    WCHAR w_cid[MMI_CLOG_PBAPC_CID_MAX_LEN + 2];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (log->cid[0] != '\0')
    {
        mmi_asc_n_to_wcs((WCHAR*) w_cid, (CHAR*)log->cid, (MMI_CLOG_PBAPC_CID_MAX_LEN+1)) ;
        value = w_cid;		
    }
    else
    {
        value = get_string(STR_GLOBAL_NO_NUMBER); 
    }
    return mmi_clog_pbapc_vr_cp_key_value(
        g_mmi_clog_pbapc_vr_inst.buf,
        MMI_CLOG_PBAPC_VR_BUF_MAX_LEN,
        cur_len,
        STR_ID_CLOG_NUMBER,
        value);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_get_call_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf                 [IN]     
 *  buf_max_len         [IN]     
 *  key_str_id          [IN] 
 *  value               [IN] 
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_get_call_time(WCHAR *buf, U32 buf_max_len, U32 *cur_len, MMI_STR_ID key_str_id, WCHAR *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    //WCHAR *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //str = get_string(key_str_id);
    len = mmi_wcslen(value) + MMI_CLOG_PBAPC_VR_FORMAT_DATA_LEN;

    if (*cur_len + len > buf_max_len)
        return MMI_FALSE;

    kal_wsprintf(buf + *cur_len, "%w%w",  value, L"\n");
    *cur_len = mmi_wcslen(buf);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_format_time
 * DESCRIPTION
 *  
 * PARAMETERS  
 *  log         [IN]     
 *  cur_len     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_format_time(mmi_clog_pbap_info_struct *log, U32 *cur_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MMI_FALSE;
    U32 len;
    WCHAR *str_buf;
    U32 i = 0;
    WCHAR *str;
    applib_time_struct refer_time;
 
    memset((void *)&refer_time, 0x0, sizeof(applib_time_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 
	for (i=0; i < MMI_CLOG_PBAPC_TIME_DETAIL_MAX_NUM; i++)
	{
            if (applib_dt_compare_time(&log->timestamp[i],&refer_time, NULL)== DT_TIME_EQUAL)
            {
               ret = MMI_TRUE;
		
            }
            else
            {
                str = get_string(STR_ID_CLOG_TIMESTAMP);
                kal_wsprintf(g_mmi_clog_pbapc_vr_inst.buf + *cur_len, "%w%w", str, L"\n");
                *cur_len = mmi_wcslen(g_mmi_clog_pbapc_vr_inst.buf);
                str_buf = OslMalloc(MMI_CLOG_PBAPC_VR_TEMP_BUF_SIZE);

                /*get time*/
                date_string((UI_time*) & log->timestamp[i], (UI_string_type) str_buf, DT_IDLE_SCREEN);
                mmi_wcscat(str_buf, L" ");
                len = mmi_wcslen((const WCHAR*)str_buf);
                time_string((UI_time*) & log->timestamp[i], (UI_string_type) (str_buf + len), DT_IDLE_SCREEN);
		 /*get string*/
		 ret = mmi_clog_pbapc_vr_cp_key_value(g_mmi_clog_pbapc_vr_inst.buf, MMI_CLOG_PBAPC_VR_BUF_MAX_LEN, cur_len, 0, str_buf);
    	        OslMfree(str_buf);
            }

        }
	kal_wsprintf(g_mmi_clog_pbapc_vr_inst.buf + *cur_len, "%w",L"\n");
	*cur_len = mmi_wcslen(g_mmi_clog_pbapc_vr_inst.buf);
	 
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_prepare_text_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_pbapc_vr_prepare_text_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_clog_pbapc_vr_inst.buf = mmi_frm_scrmem_alloc(MMI_CLOG_PBAPC_VR_BUF_MAX_SIZE);
    if(g_mmi_clog_pbapc_vr_inst.buf == NULL)
        return -1;

#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__    
    mmi_clog_pbapc_vr_format(g_mmi_clog_pbapc_clog_info_cache[g_mmi_clog_pbapc_vr_inst.log_idx].clog_info);
#else /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/
    mmi_clog_pbapc_vr_format(&g_mmi_clog_pbapc_clog_info_cache[g_mmi_clog_pbapc_vr_inst.log_idx].clog_info);
#endif /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/      
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_vr_show_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_vr_show_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U8 *gui_buf = NULL;
    S32 has_lsk = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = mmi_clog_pbapc_vr_prepare_text_data();

    if (ret != 0)
    {
        mmi_frm_group_close(GRP_ID_CLOG_PBAPC_VIEWER);
        return;
    }
    ShowCategory74Screen(
        STR_GLOBAL_VIEW,
        GetRootTitleIcon(MAIN_MENU_CALL_LOG),
        (has_lsk == MMI_FALSE ? NULL : STR_GLOBAL_OPTIONS),
        (has_lsk == MMI_FALSE ? NULL : IMG_GLOBAL_OPTIONS),
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) g_mmi_clog_pbapc_vr_inst.buf,
        (S32) (mmi_wcslen(g_mmi_clog_pbapc_vr_inst.buf) + 1),
        gui_buf);
    
    if(has_lsk)
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        SetCenterSoftkeyFunction(mmi_clog_pbapc_vr_csk_hdlr, KEY_EVENT_UP);
        redraw_center_softkey();
        SetLeftSoftkeyFunction(mmi_clog_pbapc_vr_lsk_hdlr, KEY_EVENT_UP);
    }
    SetRightSoftkeyFunction(mmi_clog_pbapc_vr_rsk_hdlr, KEY_EVENT_UP);
    mmi_ucm_handle_sendkeys_for_call(mmi_clog_send_key_hdler, KEY_EVENT_DOWN);
}
#define MMI_CLOG_PBAPC_PROCESSING_UI

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_processing_abort
 * DESCRIPTION
 *  show aborting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_pbapc_processing_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_in;
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_BT_LOAD_ABORT,g_only_update_data,(g_mmi_clog_pbapc_processing_inst.parent_gid));
    is_in = mmi_frm_scrn_is_present(g_mmi_clog_pbapc_processing_inst.parent_gid, SCR_ID_CLOG_PBAPC_LT_PROCESSING, MMI_FRM_NODE_ALL_FLAG);
    kal_prompt_trace(MOD_MMI, "[TEST]mmi_clog_pbapc_processing_abort: is_in = %d", is_in);
    if (g_mmi_clog_pbapc_processing_inst.parent_gid && is_in)
    {
        if (!g_only_update_data)
        {
            g_mmi_clog_pbapc_cntx.is_from_close_pop = MMI_TRUE;
        }
        mmi_frm_scrn_close(g_mmi_clog_pbapc_processing_inst.parent_gid,SCR_ID_CLOG_PBAPC_LT_PROCESSING);
        g_exist_flag = 1;
    }   
}


static MMI_RET mmi_clog_pbapc_close_scrn_by_back(mmi_event_struct *evt)
{
    //kal_prompt_trace(MOD_MMI,"[ClogPbapc]mmi_clog_pbapc_close_scrn:():g_mmi_clog_pbapc_processing_inst.parent_gid",g_mmi_clog_pbapc_processing_inst.parent_gid);
    g_mmi_clog_pbapc_cntx.is_canceled = MMI_TRUE;
    /*if(g_mmi_clog_pbapc_cntx.phapc_op_handle)
    {
        srv_phb_pbapc_destory_handle(g_mmi_clog_pbapc_cntx.phapc_op_handle);
        g_mmi_clog_pbapc_cntx.phapc_op_handle = NULL;
    }*/
    mmi_frm_group_close(g_mmi_clog_pbapc_processing_inst.parent_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_entry_show_processing
 * DESCRIPTION
 *  show processing
 * PARAMETERS
 *  parent_id             [IN]
 *  scrn_id            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_pbapc_entry_show_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_id;
    U8 *gui_buffer;
    MMI_BOOL ret = MMI_FALSE;
    MMI_BOOL is_exist = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if(g_mmi_clog_pbapc_processing_inst.type == MMI_CLOG_PBAPC_OP_TYPE_LT_LIST)
    {
        title_id = mmi_clog_pbapc_lt_get_title_by_storageID(g_mmi_clog_pbapc_processing_inst.sel_lt_storage);
    }
    else if(g_mmi_clog_pbapc_processing_inst.type == MMI_CLOG_PBAPC_OP_TYPE_LIST_VIEWER)
    {
        title_id = STR_GLOBAL_VIEW;
    }
    else
    {
        title_id = STR_ID_CLOG_CALL_LOG;
    }

#ifndef __MMI_PHB_PBAPC_SYNC_CONTACT__    
        if(mmi_frm_scrn_get_active_id() == SCR_ID_CLOG_PBAPC_LT_PROCESSING)
            return;
#endif
    //gui_buffer = mmi_frm_scrn_tab_page_get_active_gui_buf();
    ret = mmi_frm_scrn_enter(g_mmi_clog_pbapc_processing_inst.parent_gid,SCR_ID_CLOG_PBAPC_LT_PROCESSING,NULL,mmi_clog_pbapc_entry_show_processing,MMI_FRM_FULL_SCRN);
    if (!ret)
    return ;
    ShowCategory63Screen(GetString(STR_GLOBAL_LOADING), GetRootTitleIcon(MAIN_MENU_CALL_LOG), NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_processing_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [IN]                
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_clog_pbapc_processing_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
		case EVT_ID_SCRN_ACTIVE:
		//	mmi_clog_pbapc_entry_show_processing();
		break;
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            //loading data cancled 
            g_mmi_clog_pbapc_cntx.is_canceled = MMI_TRUE;
            if(g_mmi_clog_pbapc_cntx.phapc_op_handle)
            {
                srv_phb_pbapc_destory_handle(g_mmi_clog_pbapc_cntx.phapc_op_handle);
                g_mmi_clog_pbapc_cntx.phapc_op_handle = NULL;
            }
           break;
		default:
		 break;
	}
   
    return MMI_RET_OK;
}


void mmi_clog_pbapc_show_category(S32 error_code, U8 *gui_buffer)
{

    S32 category_error_flag;
    S32 has_lsk = MMI_FALSE;
    U8 index;
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_SHOW_CATEGORY, error_code, gui_buffer, g_mmi_clog_pbapc_lt_inst.total_num);
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    index = cui_tab_get_select_index(SCR_ID_CLOG_LAYOUT);
#else
    index = mmi_frm_scrn_tab_get_active_page_index();
#endif

    if(error_code < 0)
    {
        g_mmi_clog_pbapc_lt_inst.total_num = 0 ;        
        g_mmi_clog_pbapc_lt_inst.sel_log_idx = 0;
    }
    if (g_mmi_clog_pbapc_lt_inst.total_num)
        has_lsk = MMI_TRUE;
    else /*it also can set other string*/
        wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
        //wgui_cat_set_list_menu_empty_lable(get_string(STR_GLOBAL_EMPTY));
    wgui_cat1031_show(
            get_string(mmi_clog_pbapc_lt_get_title_by_storageID(g_mmi_clog_pbapc_cntx.path)),
            (PU8)GetImage(GetRootTitleIcon(MAIN_MENU_CALL_LOG)),
            (has_lsk == MMI_FALSE ? NULL : get_string(STR_GLOBAL_OPTIONS)),
            (has_lsk == MMI_FALSE ? NULL : (PU8)GetImage(IMG_GLOBAL_OPTIONS)),
            get_string(STR_GLOBAL_BACK),
            (PU8)GetImage(IMG_GLOBAL_BACK),
            g_mmi_clog_pbapc_lt_inst.total_num,
            mmi_clog_pbapc_lt_get_multi_log_items,
            mmi_clog_pbapc_lt_get_log_hint,
            g_mmi_clog_pbapc_lt_inst.sel_log_idx,
            index,
            IMG_ID_CLOG_MISSED_CALL,
            IMG_GLOBAL_SIM1, /* Just to get image demision but not care what it is */
            gui_buffer,
            &category_error_flag);
        if (g_mmi_clog_pbapc_lt_inst.total_num)
        {
            SetCenterSoftkeyFunction(mmi_clog_pbapc_lt_csk_hdlr, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(mmi_clog_pbapc_lt_lsk_hdlr, KEY_EVENT_UP);
            mmi_ucm_handle_sendkeys_for_call(mmi_clog_send_key_hdler, KEY_EVENT_DOWN);
        }

        SetRightSoftkeyFunction(mmi_clog_pbapc_lt_rsk_hdlr, KEY_EVENT_UP);

#ifdef __MMI_TOUCH_SCREEN__
        wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif 

#if defined ( __MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        mmi_clog_pbapc_lt_set_tap_hdlr();
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_pbapc_entry_show_processing
 * DESCRIPTION
 *  show processing
 * PARAMETERS
 *  parent_id       [IN]
 *  scrn_id         [IN]
 *  type            [IN]
 *  sel_lt_storage  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 #ifdef __MMI_CLOG_TAB_SUPPORT__
static void mmi_clog_pbapc_processing_show(MMI_ID parent_id, MMI_ID scrn_id, mmi_clog_pbapc_op_type_enum type, srv_phb_pbap_storage_enum sel_lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_clog_pbapc_processing_inst.parent_gid = parent_id;
    g_mmi_clog_pbapc_processing_inst.self_scr_id = scrn_id;
    g_mmi_clog_pbapc_processing_inst.type = type;
    g_mmi_clog_pbapc_processing_inst.sel_lt_storage = sel_lt_storage;
    mmi_frm_scrn_create(parent_id, scrn_id, mmi_clog_pbapc_processing_scrn_proc, NULL);
}
#endif


void mmi_clog_pbapc_processing_show_ex(MMI_ID parent_id, mmi_clog_pbapc_op_type_enum type, srv_phb_pbap_storage_enum sel_lt_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_clog_pbapc_processing_inst.parent_gid = parent_id;
    g_mmi_clog_pbapc_processing_inst.type = type;
    g_mmi_clog_pbapc_processing_inst.sel_lt_storage = sel_lt_storage;
    mmi_clog_pbapc_entry_show_processing();
}


void mmi_clog_bt_compare_log_by_timestamp(S32 ret)
{
    U8* number;
    S32 total_count;
    S32 i;
    S32 local;
    applib_time_struct *max_stamp;
    applib_time_struct *curr_stamp;

    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local = 0;
    total_count = (S32) mmi_clog_pbap_current_num;
    
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
    max_stamp = g_mmi_clog_pbapc_clog_info_cache[0].clog_info->timestamp;    
#else
    max_stamp = &g_mmi_clog_pbapc_clog_info_cache[0].clog_info->timestamp;
#endif 
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
        curr_stamp = g_mmi_clog_pbapc_clog_info_cache[total_count-1].clog_info->timestamp;    
#else /**/
        curr_stamp = (&g_mmi_clog_pbapc_clog_info_cache[total_count -1].clog_info->timestamp);    
#endif /**/
    if (applib_dt_compare_time(max_stamp, curr_stamp, NULL) == DT_TIME_LESS)
    {
        max_stamp = curr_stamp;
        local = total_count - 1;
    }
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
            number = g_mmi_clog_pbapc_clog_info_cache[local].clog_info->cid;    
#else /**/
            number = (&g_mmi_clog_pbapc_clog_info_cache[local].clog_info->cid);    
#endif /**/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
/* under construction !*/
#else /**/
/* under construction !*/
#endif /**/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
/* under construction !*/
#else /**/
/* under construction !*/
#endif /**/
#endif
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_BT_BY_STAMP, local, g_mmi_clog_pbapc_clog_info_cache[local].clog_info->cid[0]);
    g_mmi_clog_get_last_info.cb(number,ret);
    g_mmi_clog_get_last_info.is_get_num = MMI_FALSE;

}
#endif /* __MMI_BT_PBAP_CLIENT__ */ 

