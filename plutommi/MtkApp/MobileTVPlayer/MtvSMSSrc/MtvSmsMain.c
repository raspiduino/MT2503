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
 *  mtvsmsmain.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  mtvsmsmain.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/************************************
 * Header Files Include
 **************************************************************/
#include "MMI_include.h"
#ifdef __ATV_SMS_SUPPORT__
#include "mtvsmsiprot.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "commonscreens.h"
#include "umgprot.h"
#include "Wgui_fixed_menus.h"

/**************************************************************
 * Const define
 **************************************************************/
/* #define _MTV_SMS_SELF_TEST_ */
/**************************************************************
 * Global Variables Declaration
 **************************************************************/
extern const U16 gIndexIconsImageList[];
mmi_mtv_sms_scrn_cntx_struct g_mtv_sms_scrn_cntx;
mmi_mtv_sms_context_struct g_mtv_sms_cntx;
void* video_layer_buffer_ptr = NULL;
void* util_layer_buffer_ptr = NULL;
void* video_layer_buffer_ptr_temp = NULL;
void* util_layer_buffer_ptr_temp = NULL;

KAL_ADM_ID adm_id = 0;
show_video_func mmi_mtv_sms_video_player_callback = NULL;
FuncPtr mmi_mtv_sms_video_player_stop_callback = NULL;

/**************************************************************
 * Static Variables Defination
 **************************************************************/
static WCHAR mmi_mtv_sms_scrn_main_decription [MMI_MTV_SMS_ALLBOX][MAX_SUB_MENU_HINT_SIZE + 1];
#ifdef _MTV_SMS_SELF_TEST_
static U8 video_buffer[MATV_VIDEO_LAYER_BUF_SIZE];
static U8 full_buffer[MATV_UTIL_LAYER_BUF_SIZE];
static void dummy_show(gdi_handle preview_handle, U32 blt_layer_flag, U32 preview_layer_flag, S32 x, S32 y, S32 width, S32 height)
{
}
static U8 mmi_mtv_sms_main_del_cb_test(void* user_data);
#endif
/**************************************************************
 * Static Function Declaration
 **************************************************************/
static void mmi_mtv_sms_entry(void);
static void mmi_mtv_sms_update_msg_nums(void);
extern void mmi_mtv_sms_construct_list_hint(void);
static void mmi_mtv_sms_get_hint_list(U8**hint_list);
static U8 mmi_mtv_sms_main_del_cb(void* user_data);
static void mmi_mtv_sms_get_item_string_list(U8 **names, U16*Ids, U32 num);
static void mmi_mtv_msg_pre_entry_write_new_msg(void);
static void mmi_mtv_sms_entry_inbox_list(void);
static void mmi_mtv_sms_entry_draft_list(void);
static void mmi_mtv_sms_entry_outbox_list(void);
static void mmi_mtv_sms_entry_sentbox_list(void);
static void mmi_mtv_sms_get_item_image_list_for_main(U8 **image_list);
static void mmi_mtv_sms_pre_entry(void);
static mmi_ret mmi_mtv_sms_handle_sms_change(mmi_event_struct *event_data);
static void mmi_mtv_sms_editor_send_call_back(mtv_sms_result_enum result);
static void mmi_mtv_sms_close_screens_till_main(void);
static void mmi_mtv_sms_release_all_ems_buffer(void); 
static mmi_ret mmi_mtv_sms_main_um_entry_handle(mmi_event_struct *event_data);
static void mmi_mtv_sms_for_outer_init_mtv_player(void);

static mmi_ret mmi_mtv_sms_main_sim_evt_handle(mmi_event_struct *event_data);
/**************************************************************
 * Function Definition
 **************************************************************/
/*UT only*/
#ifdef _MTV_SMS_SELF_TEST_
 /*****************************************************************************
  * FUNCTION
  *  mmi_mtv_sms_main_del_cb
  * DESCRIPTION
  *  free memory and set current id = invlid
  *  dereg related events & stop tv palyer and free app mem
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
U8 mmi_mtv_sms_main_del_cb_test(void* user_data)
{
    if(g_mtv_sms_scrn_cntx.number_cntx)
    {
        OslMfree(g_mtv_sms_scrn_cntx.number_cntx);
    }
    g_mtv_sms_scrn_cntx.current_scrn = SCR_ID_INVALID;
    g_mtv_sms_scrn_cntx.current_index = 0;
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_DEL_MSG, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_ADD_MSG, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_UPDATE_MSG, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_MMI_UM_ENTRY_MAIN_MSG, mmi_mtv_sms_main_um_entry_handle, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS, mmi_mtv_sms_handle_sms_change, NULL);

    mmi_frm_cb_dereg_event(EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED, mmi_mtv_sms_main_sim_evt_handle, NULL);
    wgui_cat_matv_stop_video();
    wgui_cat_matv_reset_video_info();
    /* mmi_mtv_sms_release_app_mem(); */
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    gui_ssp_reset_static_layer();
#endif    
    mmi_mtv_sms_video_player_callback = NULL;
    mmi_mtv_sms_video_player_stop_callback = NULL;
    matv_reset_func();
    kal_prompt_trace(MOD_MMI, "Delete of main");
    return MMI_FALSE;
}

void mmi_mtv_sms_test_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U16 num_items = 0;
    U16 n_str_item_id_list[MAX_SUB_MENUS];
    U8 *n_str_item_name_list[MAX_SUB_MENUS];
    U8 *pop_up_list[MAX_SUB_MENUS];
    U8 *image_list[MAX_SUB_MENUS];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* AlmEnableSPOF(); */
    
    EntryNewScreen(SCR_ID_MTV_SMS_MAIN_MENU, mmi_mtv_sms_common_screen_exit, mmi_mtv_sms_test_launch, NULL);
    video_layer_buffer_ptr = video_buffer;
    util_layer_buffer_ptr = full_buffer;
    mmi_mtv_sms_video_player_callback = dummy_show;
    mmi_mtv_sms_video_player_stop_callback = UI_dummy_function;
    
    wgui_cat_matv_init_video_info(
                    (U8 *)video_layer_buffer_ptr, 
                    MATV_VIDEO_LAYER_BUF_SIZE, 
                    (U8 *)util_layer_buffer_ptr, 
                    MATV_UTIL_LAYER_BUF_SIZE, 
                    mmi_mtv_sms_video_player_callback, 
                    mmi_mtv_sms_video_player_stop_callback);
    matv_set_func(mmi_mtv_sms_for_outer_init_mtv_player, mmi_mtv_sms_common_screen_exit);               
    g_mtv_sms_scrn_cntx.number_cntx = (mmi_mtv_sms_msg_num_struct*)OslMalloc(sizeof(mmi_mtv_sms_msg_num_struct));

    /* Prevent reentry of sms screens */
    g_mtv_sms_scrn_cntx.current_scrn = SCR_ID_MTV_SMS_MAIN_MENU;
    
    MMI_ASSERT(g_mtv_sms_scrn_cntx.number_cntx);
    mmi_mtv_sms_update_msg_nums();
    mmi_mtv_sms_construct_list_hint();
    mmi_mtv_sms_get_hint_list((U8**)pop_up_list);
    
    SetDelScrnIDCallbackHandler(g_mtv_sms_scrn_cntx.current_scrn, mmi_mtv_sms_main_del_cb_test);
    
    gui_buffer = GetCurrGuiBuffer(g_mtv_sms_scrn_cntx.current_scrn);
    num_items = GetNumOfChild_Ext(MENU_ID_MTV_SMS_MAIN_ROOT);
    
    GetSequenceStringIds_Ext(MENU_ID_MTV_SMS_MAIN_ROOT, (U16*)n_str_item_id_list);
    mmi_mtv_sms_get_item_string_list((U8**)n_str_item_name_list, n_str_item_id_list, num_items);
    mmi_mtv_sms_get_item_image_list_for_main((U8**)image_list);
    SetParentHandler(MENU_ID_MTV_SMS_MAIN_ROOT);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);


    wgui_cat1010_show(
        (WCHAR*)(GetString(STR_ID_MTV_SMS_MAIN_TITLE)),
        get_image(0),
        (WCHAR*)(GetString(STR_GLOBAL_OK)),
        get_image(IMG_GLOBAL_OK),
        (WCHAR*)(GetString(STR_GLOBAL_BACK)),
        get_image(IMG_GLOBAL_BACK),
        num_items,
        (WCHAR **)n_str_item_name_list,
        (PU8*)image_list,
        (WCHAR **)pop_up_list,
        0,
        g_mtv_sms_scrn_cntx.current_index,
        gui_buffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_DEL_MSG, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_ADD_MSG, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_UPDATE_MSG, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_reg_event(EVT_ID_MMI_UM_ENTRY_MAIN_MSG, mmi_mtv_sms_main_um_entry_handle, NULL);

    mmi_frm_cb_reg_event(EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED, mmi_mtv_sms_main_sim_evt_handle, NULL);
    {
        U16 *num = g_mtv_sms_scrn_cntx.number_cntx->total_number;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
            TRC_MMI_MTV_SMS_MAIN_ENTRY, 
            num[MMI_MTV_SMS_INBOX],
            num[MMI_MTV_SMS_OUTBOX], 
            num[MMI_MTV_SMS_DARFTBOX], 
            num[MMI_MTV_SMS_SENTBOX]);
    }
}

#endif

static void mmi_mtv_sms_for_outer_init_mtv_player(void)
{
    wgui_cat_matv_init_video_info(
                    (U8 *)video_layer_buffer_ptr, 
                    MATV_VIDEO_LAYER_BUF_SIZE, 
                    (U8 *)util_layer_buffer_ptr, 
                    MATV_UTIL_LAYER_BUF_SIZE, 
                    mmi_mtv_sms_video_player_callback, 
                    mmi_mtv_sms_video_player_stop_callback);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_launch
 * DESCRIPTION
 *  entry sms msg with check and paremeters from mtv player
 * PARAMETERS
 *  pool_id     [IN}: ADM pool id
 *  video_player_callback [IN]: callback function to play video
 *  video_player_stop_callback: callback function to stop vedio
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_launch(KAL_ADM_ID pool_id, show_video_func video_player_callback, FuncPtr video_player_stop_callback)
{
    adm_id = pool_id;
    video_layer_buffer_ptr = MMI_FRM_ADM_ALLOC_FRAMEBUFFER(pool_id, MATV_VIDEO_LAYER_BUF_SIZE);
    util_layer_buffer_ptr = MMI_FRM_ADM_ALLOC_FRAMEBUFFER(pool_id, MATV_UTIL_LAYER_BUF_SIZE);
    
    mmi_mtv_sms_video_player_callback = video_player_callback;
    mmi_mtv_sms_video_player_stop_callback = video_player_stop_callback;
    video_layer_buffer_ptr_temp = video_layer_buffer_ptr;
    util_layer_buffer_ptr_temp = util_layer_buffer_ptr;
    kal_prompt_trace(MOD_MMI, "mtv sms -- video_layer_buffer_ptr = %d, util_layer_buffer_ptr = %d", 
                                video_layer_buffer_ptr, util_layer_buffer_ptr);
    if (video_layer_buffer_ptr && util_layer_buffer_ptr)
    {    
        if(srv_sms_is_sms_ready())
        {
            mmi_mtv_sms_pre_entry();
        }
        else
        {
            mmi_mtv_sms_release_app_mem();
            mmi_display_popup(get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        }
    }
    else
    {
        mmi_mtv_sms_release_app_mem();
        mmi_display_popup(get_string(STR_GLOBAL_NOT_ENOUGH_MEMORY), MMI_EVENT_FAILURE);
    }
}


 /*****************************************************************************
  * FUNCTION
  *  mmi_mtv_sms_release_app_mem
  * DESCRIPTION
  *  release app memory
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
 void mmi_mtv_sms_release_app_mem(void)
 {
    if (video_layer_buffer_ptr)
    {
        kal_adm_free(adm_id, video_layer_buffer_ptr);
        video_layer_buffer_ptr = NULL;
    }
    if (util_layer_buffer_ptr)
    {
        kal_adm_free(adm_id, util_layer_buffer_ptr);
        util_layer_buffer_ptr = NULL;
    }
 }

 
 /*****************************************************************************
  * FUNCTION
  *  mmi_mtv_sms_close_screens_till_main()
  * DESCRIPTION
  *  close all screens of mtv sms app except main menu
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
void mmi_mtv_sms_close_screens_till_main(void)
{
    U32 active_scrn_id = 0;
    active_scrn_id = mmi_frm_scrn_get_active_id();
    if (g_mtv_sms_scrn_cntx.current_scrn != SCR_ID_INVALID)
    {
        U32 i = SCR_ID_MTV_SMS_MAIN_MENU + 1;
        for( ; i < MMI_RP_APP_MTV_SMS_SCR_MAX; ++i)
        {
            mmi_mtv_sms_scrn_close(i); 
        }
        if ((active_scrn_id < MMI_RP_APP_MTV_SMS_SCR_MAX) && 
            (active_scrn_id > SCR_ID_MTV_SMS_MAIN_MENU))
        {
            mmi_mtv_sms_scrn_back();
        }
        mmi_matv_sms_phb_list_close();
    }
}

 /*****************************************************************************
  * FUNCTION
  *  mmi_mtv_sms_release_all_ems_buffer()
  * DESCRIPTION
  *  release ems buffers
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
void mmi_mtv_sms_release_all_ems_buffer(void)
{
   MTVReleaseEMSEditBuffer();
   MTVReleaseEMSViewBuffer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_pre_entry
 * DESCRIPTION
 *  entry sms msg and prevent reentry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_sms_pre_entry(void)
 {
 
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_MAIN_MENU); 
    mmi_mtv_sms_close_screens_till_main();
    mmi_mtv_sms_entry();
 }

 /*****************************************************************************
  * FUNCTION
  *  mmi_mtv_sms_entry
  * DESCRIPTION
  *  entry sms msg main screen
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
 void mmi_mtv_sms_entry(void)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U16 num_items = 0;
    U16 n_str_item_id_list[MAX_SUB_MENUS];
    U8 *n_str_item_name_list[MAX_SUB_MENUS];
    U8 *pop_up_list[MAX_SUB_MENUS];
    U8 *image_list[MAX_SUB_MENUS];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTV_SMS_MAIN_MENU, mmi_mtv_sms_common_screen_exit, mmi_mtv_sms_entry, NULL);
    wgui_cat_matv_init_video_info(
                    (U8 *)video_layer_buffer_ptr, 
                    MATV_VIDEO_LAYER_BUF_SIZE, 
                    (U8 *)util_layer_buffer_ptr, 
                    MATV_UTIL_LAYER_BUF_SIZE, 
                    mmi_mtv_sms_video_player_callback, 
                    mmi_mtv_sms_video_player_stop_callback);
    matv_set_func(mmi_mtv_sms_for_outer_init_mtv_player, mmi_mtv_sms_common_screen_exit);            
    g_mtv_sms_scrn_cntx.number_cntx = (mmi_mtv_sms_msg_num_struct*)OslMalloc(sizeof(mmi_mtv_sms_msg_num_struct));
    g_mtv_sms_scrn_cntx.current_scrn = SCR_ID_MTV_SMS_MAIN_MENU;
    
    MMI_ASSERT(g_mtv_sms_scrn_cntx.number_cntx);
    mmi_mtv_sms_update_msg_nums();
    mmi_mtv_sms_construct_list_hint();
    mmi_mtv_sms_get_hint_list((U8**)pop_up_list);
    
    SetDelScrnIDCallbackHandler(g_mtv_sms_scrn_cntx.current_scrn, mmi_mtv_sms_main_del_cb);
    
    gui_buffer = GetCurrGuiBuffer(g_mtv_sms_scrn_cntx.current_scrn);
    num_items = GetNumOfChild_Ext(MENU_ID_MTV_SMS_MAIN_ROOT);
    
    GetSequenceStringIds_Ext(MENU_ID_MTV_SMS_MAIN_ROOT, (U16*)n_str_item_id_list);
    mmi_mtv_sms_get_item_string_list((U8**)n_str_item_name_list, n_str_item_id_list, num_items);
    mmi_mtv_sms_get_item_image_list_for_main((U8**)image_list);
    SetParentHandler(MENU_ID_MTV_SMS_MAIN_ROOT);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    wgui_list_menu_enable_access_by_shortcut();
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    wgui_cat1010_show(
        (WCHAR*)(GetString(STR_ID_MTV_SMS_MAIN_TITLE)),
        get_image(0),
        (WCHAR*)(GetString(STR_GLOBAL_OK)),
        get_image(IMG_GLOBAL_OK),
        (WCHAR*)(GetString(STR_GLOBAL_BACK)),
        get_image(IMG_GLOBAL_BACK),
        num_items,
        (WCHAR **)n_str_item_name_list,
        (PU8*)image_list,
        (WCHAR **)pop_up_list,
        0,
        g_mtv_sms_scrn_cntx.current_index,
        gui_buffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
    mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_DEL_MSG, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_ADD_MSG, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_UPDATE_MSG, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_reg_event(EVT_ID_MMI_UM_ENTRY_MAIN_MSG, mmi_mtv_sms_main_um_entry_handle, NULL);

    mmi_frm_cb_reg_event(EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED, mmi_mtv_sms_main_sim_evt_handle, NULL);
    {
    U16 *num = g_mtv_sms_scrn_cntx.number_cntx->total_number;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
        TRC_MMI_MTV_SMS_MAIN_ENTRY, 
        num[MMI_MTV_SMS_INBOX],
        num[MMI_MTV_SMS_OUTBOX], 
        num[MMI_MTV_SMS_DARFTBOX], 
        num[MMI_MTV_SMS_SENTBOX]);
    }
 }

/*****************************************************************************
 * FUNCTION
 *  video_player_stop_callback
 * DESCRIPTION
 *  get msg box numbers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_update_msg_nums(void)
{
    g_mtv_sms_scrn_cntx.number_cntx->total_number[MMI_MTV_SMS_INBOX]= srv_sms_get_list_size(SRV_SMS_BOX_INBOX);
    g_mtv_sms_scrn_cntx.number_cntx->total_number[MMI_MTV_SMS_DARFTBOX] = srv_sms_get_list_size(SRV_SMS_BOX_DRAFTS);
    g_mtv_sms_scrn_cntx.number_cntx->total_number[MMI_MTV_SMS_OUTBOX]= srv_sms_get_list_size(SRV_SMS_BOX_UNSENT) ;
    g_mtv_sms_scrn_cntx.number_cntx->total_number[MMI_MTV_SMS_SENTBOX]= srv_sms_get_list_size(SRV_SMS_BOX_OUTBOX);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_construct_list_hint
 * DESCRIPTION
 *  construct list hint descriptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_construct_list_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    CHAR temp[MAX_SUB_MENU_HINT_SIZE + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for ( i = MMI_MTV_SMS_INBOX; i < MMI_MTV_SMS_ALLBOX; ++i)
    {   
        MMI_ID str_hint = STR_ID_MTV_SMS_LIST_HINT;
        if (g_mtv_sms_scrn_cntx.number_cntx->total_number[i] > 1)
        {
            str_hint = STR_ID_MTV_SMS_LIST_HINTS;
        }
        sprintf(temp, "%d ", g_mtv_sms_scrn_cntx.number_cntx->total_number[i]);
        mmi_asc_n_to_ucs2((CHAR *)mmi_mtv_sms_scrn_main_decription[i], (CHAR *)temp, MAX_SUB_MENU_HINT_SIZE);
        mmi_ucs2cat((S8 *)mmi_mtv_sms_scrn_main_decription[i], (const S8 *)GetString((U16)str_hint));
    }
}

 /*****************************************************************************
  * FUNCTION
  *  mmi_mtv_sms_get_hint_list
  * DESCRIPTION
  *  pass hint list to description
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
 void mmi_mtv_sms_get_hint_list(U8** hint_list)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     hint_list[0] = NULL;

    for (i = MMI_MTV_SMS_INBOX; i < MMI_MTV_SMS_ALLBOX; ++i)
    {
        hint_list[i + 1] = (U8*)mmi_mtv_sms_scrn_main_decription[i];
    }
 }
 
 /*****************************************************************************
  * FUNCTION
  *  mmi_mtv_sms_main_del_cb
  * DESCRIPTION
  *  free memory and set current id = invlid
  *  dereg related events & stop tv palyer and free app mem
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
U8 mmi_mtv_sms_main_del_cb(void* user_data)
{
    if(g_mtv_sms_scrn_cntx.number_cntx)
    {
        OslMfree(g_mtv_sms_scrn_cntx.number_cntx);
    }
    g_mtv_sms_scrn_cntx.current_scrn = SCR_ID_INVALID;
    g_mtv_sms_scrn_cntx.current_index = 0;
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_DEL_MSG, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_ADD_MSG, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_UPDATE_MSG, mmi_mtv_sms_handle_sms_change, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_MMI_UM_ENTRY_MAIN_MSG, mmi_mtv_sms_main_um_entry_handle, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS, mmi_mtv_sms_handle_sms_change, NULL);

    mmi_frm_cb_dereg_event(EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED, mmi_mtv_sms_main_sim_evt_handle, NULL);
    wgui_cat_matv_stop_video();
    wgui_cat_matv_reset_video_info();
    mmi_mtv_sms_release_app_mem();
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    gui_ssp_reset_static_layer();
#endif    
    mmi_mtv_sms_video_player_callback = NULL;
    mmi_mtv_sms_video_player_stop_callback = NULL;
    matv_reset_func();
    kal_prompt_trace(MOD_MMI, "Delete of main");
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_main_um_entry_handle
 * DESCRIPTION
 *  close screens and free ems buffers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_mtv_sms_main_um_entry_handle(mmi_event_struct *event_data)
{
    if (IsScreenPresent(SCR_ID_MTV_SMS_EDITOR))
    {
        mmi_ime_delete_editor_common_scr(SCR_ID_MTV_SMS_EDITOR);
    }
    mmi_mtv_sms_close_screens_till_main();
    mmi_mtv_sms_release_all_ems_buffer(); 
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_main_sim_evt_handle
 * DESCRIPTION
 *  close screens and free ems buffers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_mtv_sms_main_sim_evt_handle(mmi_event_struct *event_data)
{
    srv_sim_ctrl_event_detected_evt_struct *sim_evt = (srv_sim_ctrl_event_detected_evt_struct *)event_data;
    if (SRV_SIM_CTRL_EVENT_DET_INSERTED != sim_evt->type)
    {       
        U32 active_scrn_id = 0;
        active_scrn_id = mmi_frm_scrn_get_active_id();
 
        if (IsScreenPresent(SCR_ID_MTV_SMS_EDITOR))
        {
            mmi_ime_delete_editor_common_scr(SCR_ID_MTV_SMS_EDITOR);
        }
        mmi_mtv_sms_close_screens_till_main();
        mmi_mtv_sms_release_all_ems_buffer(); 
        
        if (SCR_ID_MTV_SMS_MAIN_MENU == active_scrn_id)
        {
            mmi_mtv_sms_scrn_back();
        }
        else
        {
            mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_MAIN_MENU);
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_get_item_string_list
 * DESCRIPTION
 *  map strings to ui_string type
 * PARAMETERS
 *  names       [OUT]: string buffers
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_get_item_string_list(U8 **names, U16*Ids, U32 num)
{
    U32 i;
    for(i = 0; i < num; i++)
    {
        names[i] = (U8*)GetString(Ids[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_get_item_image_list_for_main
 * DESCRIPTION
 *  map image to main menu screen
 * PARAMETERS
 *  names       [OUT]: string buffers
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_get_item_image_list_for_main(U8 **image_list)
{
 #ifndef   __LOW_COST_SUPPORT_COMMON__
    image_list[0] = (U8*)get_image(IMG_UM_WRITE_MSG_ID);
    image_list[1] = (U8*)get_image(IMG_UM_INBOX_ID);
    image_list[2] = (U8*)get_image(IMG_UM_DRAFT_ID);
    image_list[3] = (U8*)get_image(IMG_UM_UNSENT_ID);
    image_list[4] = (U8*)get_image(IMG_UM_SENT_ID);
 #else
    image_list[0] = (U8*)get_image(IMG_GLOBAL_L1);
    image_list[1] = (U8*)get_image(IMG_GLOBAL_L2);
    image_list[2] = (U8*)get_image(IMG_GLOBAL_L3);
    image_list[3] = (U8*)get_image(IMG_GLOBAL_L4);
    image_list[4] = (U8*)get_image(IMG_GLOBAL_L5);
 #endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_write_msg_hilite_handler
 * DESCRIPTION
 *  Highlight write message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_write_msg_hilite_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mtv_sms_scrn_cntx.current_index = 0;
    SetLeftSoftkeyFunction(mmi_mtv_msg_pre_entry_write_new_msg, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_msg_pre_entry_write_new_msg, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 * mmi_mtv_sms_editor_send_call_back(mtv_sms_result_enum result); 
 * DESCRIPTION
 *  pre-entry write new sms 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_editor_send_call_back(mtv_sms_result_enum result)
{
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_EDITOR);
}


/*****************************************************************************
 * FUNCTION
 *  mtv_mmi_msg_pre_entry_write_new_msg
 * DESCRIPTION
 *  pre-entry write new sms 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_msg_pre_entry_write_new_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready() == MMI_FALSE)
    {
        mmi_mtv_sms_display_popup(
            (STR_ID_MTV_SMS_NOT_AVAIABLE),
            MMI_MTV_SMS_NOTIFY_FAILURE);
    }
    else
    {
        mmi_mtv_sms_set_send_msg_case(MTV_SMS_SEND_CASE_WRITE_NEW_MSG);
        mmi_mtv_sms_send_register_call_back(mmi_mtv_sms_editor_send_call_back);
        mmi_mtv_sms_start_send_msg_get_sendcase();
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_MAIN_SELECT, 0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_hilite_inbox
 * DESCRIPTION
 *  Highlight inbox handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_hilite_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mtv_sms_scrn_cntx.current_index = 1;
    SetLeftSoftkeyFunction(mmi_mtv_sms_entry_inbox_list, KEY_EVENT_UP); 
    SetCenterSoftkeyFunction(mmi_mtv_sms_entry_inbox_list, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_hilite_draftbox
 * DESCRIPTION
 *  Highlight draftbox handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_hilite_draftbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mtv_sms_scrn_cntx.current_index = 2;
    SetLeftSoftkeyFunction(mmi_mtv_sms_entry_draft_list, KEY_EVENT_UP); 
    SetCenterSoftkeyFunction(mmi_mtv_sms_entry_draft_list, KEY_EVENT_UP); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_hilite_outbox
 * DESCRIPTION
 *  Highlight outbox handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_hilite_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mtv_sms_scrn_cntx.current_index = 4;
    SetLeftSoftkeyFunction(mmi_mtv_sms_entry_outbox_list, KEY_EVENT_UP); 
    SetCenterSoftkeyFunction(mmi_mtv_sms_entry_outbox_list, KEY_EVENT_UP); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_hilite_sentbox
 * DESCRIPTION
 *  Highlight sentbox handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_hilite_sentbox(void)
{
    g_mtv_sms_scrn_cntx.current_index = 5;
    SetLeftSoftkeyFunction(mmi_mtv_sms_entry_sentbox_list, KEY_EVENT_UP); 
    SetCenterSoftkeyFunction(mmi_mtv_sms_entry_sentbox_list, KEY_EVENT_UP); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_inbox_list
 * DESCRIPTION
 *  Entry the inbox list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_inbox_list(void)
{
    mmi_mtv_sms_pre_entry_msgbox_list(SRV_SMS_BOX_INBOX);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_MAIN_SELECT, 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_draft_list
 * DESCRIPTION
 *  Entry the draft list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_draft_list(void)
{
    mmi_mtv_sms_pre_entry_msgbox_list(SRV_SMS_BOX_DRAFTS);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_MAIN_SELECT, 2);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_outbox_list
 * DESCRIPTION
 *  Entry the outbox list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_outbox_list(void)
{
    mmi_mtv_sms_pre_entry_msgbox_list(SRV_SMS_BOX_UNSENT);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_MAIN_SELECT, 3);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_sentbox_list
 * DESCRIPTION
 *  Entry the sentbox list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_sentbox_list(void)
{
    mmi_mtv_sms_pre_entry_msgbox_list(SRV_SMS_BOX_OUTBOX);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_MAIN_SELECT, 4);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_sentbox_list
 * DESCRIPTION
 *  Entry the inbox list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_mtv_sms_handle_sms_change(mmi_event_struct *event_data)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id;
    srv_sms_event_struct *sms_event_data = (srv_sms_event_struct *) event_data;
    srv_sms_msg_info_struct *des_info;
    srv_sms_msg_info_struct *src_info;
    srv_sms_folder_enum folder_id;
    srv_sms_box_enum msg_box;

    mmi_mtv_sms_update_msg_nums();
    mmi_mtv_sms_construct_list_hint();

    {
    U16 *num = g_mtv_sms_scrn_cntx.number_cntx->total_number;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, 
        TRC_MMI_MTV_SMS_MAIN_REFRESH, 
        num[MMI_MTV_SMS_INBOX],
        num[MMI_MTV_SMS_OUTBOX], 
        num[MMI_MTV_SMS_DARFTBOX], 
        num[MMI_MTV_SMS_SENTBOX]);
    }
    if (GetActiveScreenId() == SCR_ID_MTV_SMS_MAIN_MENU)
    {
        U32 i;
        for (i = MMI_MTV_SMS_INBOX; i < MMI_MTV_SMS_ALLBOX; ++i)
        {
            wgui_cat1010_change_item_description(i + 1, (WCHAR*)mmi_mtv_sms_scrn_main_decription[i]);
        }
        RedrawCategoryFunction();
        return MMI_RET_OK;
    }
    else if ((GetActiveScreenId() == SCR_ID_MTV_SMS_LIST))
    {
        switch (sms_event_data->evt_id)
        {
            case EVT_ID_SRV_SMS_DEL_MSG:
            {
                srv_sms_event_delete_struct * del_data = (srv_sms_event_delete_struct*)(sms_event_data->event_info);
                msg_id = del_data->msg_id;
                des_info = &del_data->msg_info;
                folder_id = des_info->folder_id;
                msg_box = srv_sms_get_list_type(
                                                        srv_sms_get_msg_status(msg_id),
                                                        srv_sms_get_msg_storage_type(msg_id),
                                                        folder_id);
                if (g_mtv_sms_cntx.curr_box_type & msg_box)
                {
                    mmi_mtv_sms_display_popup((STR_GLOBAL_LOADING), MMI_MTV_SMS_LOADING);
                }
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_LIST_REFRESH, msg_box, 0, g_mtv_sms_cntx.curr_box_type,msg_id, sms_event_data->evt_id);
            }
            break;
            
            case EVT_ID_SRV_SMS_ADD_MSG:
            {
                srv_sms_event_add_struct * add_data = (srv_sms_event_add_struct*)(sms_event_data->event_info);
                msg_id = add_data->msg_id;
                des_info = &add_data->msg_info;
                folder_id = des_info->folder_id;
                msg_box = srv_sms_get_list_type(
                                                        srv_sms_get_msg_status(msg_id),
                                                        srv_sms_get_msg_storage_type(msg_id),
                                                        folder_id);
                if (g_mtv_sms_cntx.curr_box_type == msg_box)
                {
                    mmi_mtv_sms_display_popup((STR_GLOBAL_LOADING), MMI_MTV_SMS_LOADING);
                }
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_LIST_REFRESH, msg_box, 0,g_mtv_sms_cntx.curr_box_type, msg_id, sms_event_data->evt_id);
            }
            break;
                
            case EVT_ID_SRV_SMS_UPDATE_MSG:
            {
                srv_sms_event_update_struct * update_data = (srv_sms_event_update_struct*)(sms_event_data->event_info);
                msg_id = update_data->msg_id;
                des_info = &(update_data->new_msg_info);
                folder_id = des_info->folder_id;
                msg_box = srv_sms_get_list_type(
                                                        srv_sms_get_msg_status(msg_id),
                                                        srv_sms_get_msg_storage_type(msg_id),
                                                        folder_id);
                if (g_mtv_sms_cntx.curr_box_type == msg_box)
                {
                    mmi_mtv_sms_display_popup((STR_GLOBAL_LOADING), MMI_MTV_SMS_LOADING);
                    break;
                }
                else
                {
                    src_info = &update_data->old_msg_info;
                    folder_id = src_info->folder_id;
                    if (g_mtv_sms_cntx.curr_box_type == srv_sms_get_list_type(
                                                            srv_sms_get_msg_status(msg_id),
                                                            srv_sms_get_msg_storage_type(msg_id),
                                                            folder_id))
                    {
                        mmi_mtv_sms_display_popup((STR_GLOBAL_LOADING), MMI_MTV_SMS_LOADING);
                        break;
                    }
                }
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_LIST_REFRESH, msg_box, 0, g_mtv_sms_cntx.curr_box_type, msg_id, sms_event_data->evt_id);
            }
            break;

        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            case EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS:
            {
                srv_sms_event_struct* evt = (srv_sms_event_struct*)event_data;
                srv_sms_event_update_unsent_msg_status_struct *event_info;
                srv_um_msg_box_enum refresh_box_type = 0;
                U16 unsent_msg_id;

                event_info = (srv_sms_event_update_unsent_msg_status_struct*)evt->event_info;
                unsent_msg_id = event_info->msg_id;

            	switch (event_info->status)
            	{
            		case SRV_SMS_SEND_SUCCESS:
        			{
                        if ((g_mtv_sms_cntx.curr_box_type == SRV_SMS_BOX_UNSENT) ||
                            (g_mtv_sms_cntx.curr_box_type == SRV_SMS_BOX_OUTBOX))
                        {
                            mmi_mtv_sms_display_popup((STR_GLOBAL_LOADING), MMI_MTV_SMS_LOADING);
                        }

        			}
            			break;
                }
            }
        #endif
        return MMI_RET_OK;
        }
    }
    else if ((GetActiveScreenId() == SCR_ID_MTV_SMS_VIEWER) || 
            (GetActiveScreenId() == SCR_ID_MTV_SMS_VIEWER_OPTIONS) ||
            (GetActiveScreenId() == SCR_ID_MTV_SMS_CONFIRM_DELETE_VIEWER))
    {
        switch (sms_event_data->evt_id)
        {
            case EVT_ID_SRV_SMS_DEL_MSG:
                msg_id = ((srv_sms_event_delete_struct*)sms_event_data->event_info)->msg_id;
                if (msg_id == g_mtv_sms_cntx.curr_msg_id) 
                {
                    mmi_mtv_sms_display_popup(STR_ID_MTV_SMS_UPDATING_MSG, MMI_MTV_SMS_LOADING);
                    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_VIEWER);
                }
                break;
                
            case EVT_ID_SRV_SMS_ADD_MSG:
            case EVT_ID_SRV_SMS_UPDATE_MSG:
                break;
        }
    }
    else if ((GetActiveScreenId() == SCR_ID_MTV_SMS_LIST_OPTIONS)|| 
             (GetActiveScreenId() == SCR_ID_MTV_SMS_CONFIRM_REMOVE) ||
             (GetActiveScreenId() == SCR_ID_MTV_SMS_CONFIRM_DELETE))
    {
        switch (sms_event_data->evt_id)
        {
            case EVT_ID_SRV_SMS_DEL_MSG:
                msg_id = ((srv_sms_event_delete_struct*)sms_event_data->event_info)->msg_id;
                if (msg_id == g_mtv_sms_cntx.curr_msg_id) 
                {
                    mmi_mtv_sms_display_popup(STR_GLOBAL_UPDATE, MMI_MTV_SMS_NOTIFY_INFO);
                    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_VIEWER);
                }
                break;
                
            case EVT_ID_SRV_SMS_ADD_MSG:
            case EVT_ID_SRV_SMS_UPDATE_MSG:
                break;
        }
    }
    else if (GetActiveScreenId() == SCR_ID_MTV_SMS_CONFIRM_DELETE_ALL )
    {
        switch (sms_event_data->evt_id)
        {
            case EVT_ID_SRV_SMS_ADD_MSG:
            case EVT_ID_SRV_SMS_DEL_MSG:
                mmi_mtv_sms_display_popup(STR_GLOBAL_UPDATE, MMI_MTV_SMS_NOTIFY_INFO);
                break;
                
            case EVT_ID_SRV_SMS_UPDATE_MSG:
                break;
        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            case EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS:
            {
                srv_sms_event_struct* evt = (srv_sms_event_struct*)event_data;
                srv_sms_event_update_unsent_msg_status_struct *event_info;
                srv_um_msg_box_enum refresh_box_type = 0;
                U16 unsent_msg_id;

                event_info = (srv_sms_event_update_unsent_msg_status_struct*)evt->event_info;
                unsent_msg_id = event_info->msg_id;

            	switch (event_info->status)
            	{
                    if ((g_mtv_sms_cntx.curr_box_type == SRV_SMS_BOX_UNSENT) ||
                        (g_mtv_sms_cntx.curr_box_type == SRV_SMS_BOX_OUTBOX))
                    {
                        mmi_mtv_sms_display_popup((STR_GLOBAL_UPDATE), MMI_MTV_SMS_NOTIFY_INFO);
                    }
                }
            }
        #endif
        }
    }
    else
    {       
        switch (sms_event_data->evt_id)
        {
            case EVT_ID_SRV_SMS_DEL_MSG:
                msg_id = ((srv_sms_event_delete_struct*)sms_event_data->event_info)->msg_id;
                if (msg_id == g_mtv_sms_cntx.curr_msg_id) 
                {
                    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_VIEWER);
                }
        }
    }
    return MMI_RET_OK;
}

#endif /* __MMI_ATV_SMS_SUPPORT__ */
 
