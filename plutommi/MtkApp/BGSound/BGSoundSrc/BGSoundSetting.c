 /*******************************************************************************
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
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
 *******************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * BGSoundSetting.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _MMI_BGSOUNDSETTING_C
#define _MMI_BGSOUNDSETTING_C


#ifdef __MMI_BG_SOUND_EFFECT__
#include "BgSoundSrvGprot.h"
/* RHR */
#include "MMI_features.h"
//#include "kal_general_types.h"
#include "AlertScreen.h"
#include "gui_data_types.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_res_range_def.h"
//#include "kal_public_api.h"
#include "gui.h"
#include "DebugInitDef_Int.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "wgui_inline_edit.h"
#include "wgui_fixed_menus.h"
#include "CommonScreensResDef.h"
#include "stdlib.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "CustMenuRes.h"
#include "mmi_rp_file_type_def.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
/* RHR */

/*  Include: MMI header file */
#include "mmi_rp_app_bgsound_def.h"
#include "Menucuigprot.h"
#include "CommonScreens.h"
//#include "SettingProfile.h"
//#include "nvram_user_defs.h"
#include "FileMgrSrvGProt.h"
//#include "FileManagerDef.h"
//#include "FileManagerGProt.h"
//#include "FileMgr.h"
#include "wgui_touch_screen.h"
#include "ProfilesSrvGprot.h"
/* ... Add More MMI header */

#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "BGSoundDef.h"
#include "BGSoundType.h"
#include "BGSoundProt.h"
//#include "ProfileGProts.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"  /* DRM support */
#include "drm_def.h"
//#include "DRM_main.h"
#endif /* __DRM_SUPPORT__ */ 

#if defined(__MMI_TOUCH_SCREEN__)
#endif
#ifdef __CTM_SUPPORT__ 
#include "CallSetSrvGprot.h" /* srv_callset_ctm_get_mode */
#endif

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif

#include "MMIDataType.h" /*HFP*/

#if defined(__MMI_BACKGROUND_CALL__)
#include "UCMSrvGProt.h"
#endif

#include "mmi_rp_app_callset_def.h"
#include "Mmi_frm_scenario_gprot.h"
#include "Inlinecuigprot.h"
#include "Filemgrcuigprot.h"


/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */

#define APP_CAPTION1             CUI_INLINE_ITEM_ID_BASE+10
#define APP_TEXTEDIT1            CUI_INLINE_ITEM_ID_BASE+11 
#define APP_CAPTION2             CUI_INLINE_ITEM_ID_BASE+12

#define APP_SELECT               CUI_INLINE_ITEM_ID_BASE+13
#define APP_TEXTEDIT2            CUI_INLINE_ITEM_ID_BASE+14

bgsnd_context_struct g_bgsnd_cntx;
#ifdef __MMI_FTE_SUPPORT__
MMI_BOOL g_bgsnd_tap_effect = MMI_FALSE;
#endif
/* 
 * Local Function
 */
static mmi_ret mmi_bgsnd_group_proc(mmi_event_struct *evt);
static mmi_ret cui_bgsound_options_proc(mmi_event_struct *evt);
static mmi_ret cui_bgsound_effect_list_proc(mmi_event_struct *evt);
static mmi_ret mmi_bgsnd_cs_playback_save_confirmCb(mmi_alert_result_evt_struct *evt);
#ifdef __DRM_SUPPORT__
static mmi_ret mmi_bgsnd_DRM_confirmCb(mmi_alert_result_evt_struct *evt);
#endif
static mmi_ret mmi_bgsnd_file_not_exist_confirmCb(mmi_alert_result_evt_struct *evt);
static mmi_ret mmi_bgsnd_cs_ext_effect_delete_confirmcb(mmi_alert_result_evt_struct *evt);
static S32 bgsnd_repeat;
S8 *bgsnd_repeat_str[BGSND_REPEAT_NUM];

static UI_character_type bgsnd_interval_buf[BGSND_INTERVAL_LEN];
static UI_character_type bgsnd_volume_buf[BGSND_VOLUME_LEN];

static U16 bgsnd_curr_highlight;

static U8 bgsnd_ext_effect[BGSND_MAX_EXT_EFFECT / 8 + 1];
static U16 interval_buf;
MMI_ID g_bgsound_id, g_bgsound_inline_gid, bgs_menu_id,g_bgs_option_gid, g_bgs_menu_option_id,g_bgsnd_list_gid;

U16 g_bgsnd_repeat_str_id[BGSND_REPEAT_NUM] = 
{
    STR_ID_BGSND_ONCE,
    STR_ID_BGSND_INTERVAL,
    STR_ID_BGSND_CONTINUE
};
/* 
 * Global Variable
 */

/* 
 * Global Function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_init
 * DESCRIPTION
 *  This function is to initialize MMI background sound related variables.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bgsnd_call_setup_init();

    /* Read NVRAM data */
    if (!g_bgsnd_cntx.is_init)
    {
        mmi_bgsnd_util_read_setup_data();
        g_bgsnd_cntx.is_init = TRUE;
    }

    g_bgsnd_cntx.setup_playing = FALSE;

#ifdef __DRM_SUPPORT__
    g_bgsnd_cntx.current_function_status = BGSND_FUNCTION_NONE;
    g_bgsnd_cntx.drm_permission_state = TRUE;
#endif

    mmi_bgsnd_call_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_call_setup_init
 * DESCRIPTION
 *  This function is to initialize background sound in call setup part
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_call_setup_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}

#define MMI_BGSND_CS_MAIN


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_call_setup
 * DESCRIPTION
 *  This function is the highlight function of background sound setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_call_setup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_bgsnd_pre_entry_call_setup, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_pre_entry_call_setup
 * DESCRIPTION
 *  This function is the pre entry function for sound effect setup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_pre_entry_call_setup(void)
{
#ifdef __CTM_SUPPORT__
    if(srv_callset_ctm_get_mode() == MMI_TRUE)
    {
		 mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_BGSND_CTM_MODE_ON)), MMI_EVENT_FAILURE, NULL);

      
    }
    else
#endif /* #ifdef __CTM_SUPPORT__ */
    {
        mmi_bgsnd_entry_call_setup();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_call_setup
 * DESCRIPTION
 *  This function is the entry function of background ground sound setting main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_call_setup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

     

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_bgsound_id = mmi_frm_group_create(GRP_ID_ROOT,GRP_ID_AUTO_GEN,mmi_bgsnd_group_proc,(void*) NULL);
    mmi_frm_group_enter(g_bgsound_id,MMI_FRM_NODE_SMART_CLOSE_FLAG);

    bgs_menu_id = cui_menu_create(g_bgsound_id,
                                  CUI_MENU_SRC_TYPE_APPCREATE,
                                  CUI_MENU_TYPE_APPMAIN,
                                  MENU_ID_BGSND_CALL_SETUP,
                                  MMI_FALSE,
                                  (void*)NULL);

    cui_menu_run(bgs_menu_id);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_group_proc
 * DESCRIPTION
 *  Proc handler 
 * PARAMETERS
 *  event_structure
 * RETURNS
 *  mmi
 *****************************************************************************/
static mmi_ret mmi_bgsnd_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


        switch (evt->evt_id)
        {
    	    case EVT_ID_CUI_MENU_LIST_ENTRY:
                {
                    if (menu_evt->parent_menu_id == MENU_ID_BGSND_CALL_SETUP_STATUS)
                    {

                         if (g_bgsnd_cntx.set.status != 0)
                         {
    			        cui_menu_set_item_hint(menu_evt->sender_id,MENU_ID_BGSND_CALL_SETUP_STATUS,get_string(STR_GLOBAL_ON));
    			        cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_OFF));
                         }
                          else
                         {
    				 cui_menu_set_item_hint(menu_evt->sender_id,MENU_ID_BGSND_CALL_SETUP_STATUS,get_string(STR_GLOBAL_OFF));
    				 cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_ON));
                          }

                    }
                    else
                    {
                        cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_OK));

                    }
                    /* Status ,Inline and effect list*/
                    if (menu_evt->parent_menu_id == MENU_ID_BGSND_CALL_SETUP)
                    {
                        mmi_menu_id root_ids[3] = {MENU_ID_BGSND_CALL_SETUP_STATUS,MENU_ID_BGSND_CALL_SETUP_SETTING,MENU_ID_BGSND_CALL_SETUP_LIST};
                    #ifndef __COSMOS_MMI_PACKAGE__
                        cui_menu_set_currlist_title(menu_evt->sender_id,(WCHAR*)get_string(STR_ID_BGSND_BG_SOUND),
                            (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING)));
                    #endif /* __COSMOS_MMI_PACKAGE__ */
						
                        cui_menu_set_currlist(menu_evt->sender_id,3,(mmi_menu_id*)root_ids);
                        cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_BGSND_CALL_SETUP_STATUS,get_string(STR_ID_BGSND_MO_STATUS));
                        cui_menu_set_item_image(menu_evt->sender_id,MENU_ID_BGSND_CALL_SETUP_STATUS,gIndexIconsImageList[0]);

                        cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_BGSND_CALL_SETUP_SETTING,get_string(STR_ID_BGSND_PLAYBACK_SETUP));
                        cui_menu_set_item_image(menu_evt->sender_id,MENU_ID_BGSND_CALL_SETUP_SETTING,gIndexIconsImageList[1]);

                        cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_BGSND_CALL_SETUP_LIST,get_string(STR_ID_BGSND_EFFECT_LIST));
                        cui_menu_set_item_image(menu_evt->sender_id,MENU_ID_BGSND_CALL_SETUP_LIST,gIndexIconsImageList[2]);

                        cui_menu_set_non_leaf_item(menu_evt->sender_id,MENU_ID_BGSND_CALL_SETUP_LIST,MMI_TRUE);

                    }
                    /*Effect List menu items*/
                   
                }
                break;

    	    case EVT_ID_CUI_MENU_ITEM_SELECT:
                {
                    if (menu_evt->highlighted_menu_id == MENU_ID_BGSND_CALL_SETUP_STATUS)
                    {
                        mmi_bgsnd_cs_status_toggle();
                        if (g_bgsnd_cntx.set.status != 0)
                        {
    			    cui_menu_set_item_hint(menu_evt->sender_id,MENU_ID_BGSND_CALL_SETUP_STATUS,get_string(STR_GLOBAL_ON));
    			    cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_OFF));
                        }
                        else
                        {
                            cui_menu_set_item_hint(menu_evt->sender_id,MENU_ID_BGSND_CALL_SETUP_STATUS,get_string(STR_GLOBAL_OFF));
    			    cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_ON));
                        }
                        break;

                    }

                    if (menu_evt->highlighted_menu_id == MENU_ID_BGSND_CALL_SETUP_SETTING)
                    {                     
                        mmi_bgsnd_cs_playback_prepare_inline_data();
                        break;
                    }

                    if (MENU_ID_BGSND_CALL_SETUP_LIST == menu_evt->highlighted_menu_id)
                    {
			#ifdef __MMI_BACKGROUND_CALL__
			if (srv_ucm_is_background_call())
			{
			    mmi_ucm_app_entry_error_message();
			    return;
			}
                        #endif /* __MMI_BACKGROUND_CALL__ */

						
						
                        mmi_bgsnd_entry_cs_effect_list_group_enter(evt);

			#ifdef __BT_SPK_VOL_CONTROL__
			mdi_audio_bt_register_volume_sync_callback(APP_BGSOUND, MDI_AUD_VOL_LEVEL_NORMAL_MUTE, mmi_bgsnd_hfp_volume_sync_callback);
			#endif /* __BT_SPK_VOL_CONTROL__ */
                    }
                }    
    		    break;

    	    case EVT_ID_CUI_MENU_ITEM_HILITE:
                {
                    /* Status*/
                    if (menu_evt->highlighted_menu_id == MENU_ID_BGSND_CALL_SETUP_STATUS)
                    {
                        if (g_bgsnd_cntx.set.status != 0)
                        {
    			     cui_menu_set_item_hint(menu_evt->sender_id,MENU_ID_BGSND_CALL_SETUP_STATUS,get_string(STR_GLOBAL_ON));
    			     cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_OFF));
                        }
                        else
                        {
    			     cui_menu_set_item_hint(menu_evt->sender_id,MENU_ID_BGSND_CALL_SETUP_STATUS,get_string(STR_GLOBAL_OFF));
    			     cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_ON));
    			 }	

    		     }
                    /* Inline and effect list*/
                    if (menu_evt->highlighted_menu_id == MENU_ID_BGSND_CALL_SETUP_SETTING || 
                        menu_evt->highlighted_menu_id == MENU_ID_BGSND_CALL_SETUP_LIST)
                    {
                        cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_SELECT));

                    }
                   break;
                }


            case EVT_ID_CUI_MENU_LIST_EXIT:
                break;




            case EVT_ID_SCRN_GOBACK :
                 mmi_frm_scrn_close_active_id();
                 break;

            case EVT_ID_GROUP_DELETE_REQ:
                 break;
            case EVT_ID_GROUP_INACTIVE:
                if (mmi_frm_scrn_get_count(g_bgsound_id) == 0)
                {
                    mmi_frm_group_close(g_bgsound_id);
                }
                break;


    	    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
                if (menu_evt->sender_id == bgs_menu_id)
                {
                    //cui_menu_close(menu_evt->sender_id);
                    mmi_frm_group_close(g_bgsound_id);

                }
                else
                {
                    cui_menu_close(menu_evt->sender_id);
                }
                break;

          

            case EVT_ID_CUI_INLINE_ABORT:
               cui_inline_close(g_bgsound_inline_gid);
                break;

            case EVT_ID_CUI_INLINE_SUBMIT:
	    case EVT_ID_CUI_INLINE_CSK_PRESS:
                mmi_bgsnd_cs_playback_setup_done();
                break;

            case EVT_ID_CUI_INLINE_NOTIFY:
                {
                    S32 temp_value = 0;
                    UI_character_type temp_interval_buf[BGSND_INTERVAL_LEN];
                    cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct *)evt;


                    switch(notify_evt->event_type)
                    {
                        case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:

                            if(notify_evt->item_id == (U32)APP_SELECT)
                            {
                                if((S32)notify_evt->param == BGSND_REPEAT_INTERVAL)
                                {
                                    bgsnd_repeat = BGSND_REPEAT_INTERVAL;
                                    kal_wsprintf(temp_interval_buf, "%d", interval_buf);
                                    cui_inline_set_value(g_bgsound_inline_gid, APP_TEXTEDIT2, (void*)temp_interval_buf);
                                    cui_inline_set_item_attributes(g_bgsound_inline_gid, APP_TEXTEDIT2, CUI_INLINE_RESET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
    }
    else
    {
                                    bgsnd_repeat = (S32)notify_evt->param;
                                    kal_wsprintf(temp_interval_buf, "%d", temp_value);
                                    cui_inline_set_value(g_bgsound_inline_gid, APP_TEXTEDIT2, (void*)temp_interval_buf);
                                    cui_inline_set_item_attributes(g_bgsound_inline_gid, APP_TEXTEDIT2, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);

                                }
                                cui_inline_redraw_screen(g_bgsound_inline_gid);
                            }
                            break;

                        case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
						{
							U16 play_style = 0;

                             if(notify_evt->item_id != (U32)APP_TEXTEDIT2 &&  bgsnd_repeat == BGSND_REPEAT_INTERVAL)
                             {
                                 interval_buf = gui_atoi((UI_string_type) bgsnd_interval_buf);
                             }
							   if(notify_evt->item_id == (U32)APP_TEXTEDIT2)
							 {
								 cui_inline_get_value(g_bgsound_inline_gid, APP_SELECT, (void *)&play_style);
							 
							 }
                             break;
						}


                        case CUI_INLINE_NOTIFY_ITEM_CHANGED:
                            cui_inline_get_value(g_bgsound_inline_gid, APP_TEXTEDIT2, (void *)bgsnd_interval_buf);
                            break;



                        default:
                            break;
                    }
                }               
                break;


            case EVT_ID_CUI_INLINE_SET_KEY:
                break;

            case EVT_ID_CUI_INLINE_REDRAW:
                break;

            default:
                break;

    }

        return MMI_RET_OK;
}

  /*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cs_effect_list_group_enter
 * DESCRIPTION
 *  This function is to create a separate group for effect list
 * PARAMETERS
 *  menu_event_strcut
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_bgsnd_entry_cs_effect_list_group_enter(mmi_event_struct *event)
 {
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     MMI_ID menu_id;
     cui_menu_event_struct *menu_event = (cui_menu_event_struct *)event;

  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if (menu_event->highlighted_menu_id == MENU_ID_BGSND_CALL_SETUP_LIST)
     {
         g_bgsnd_list_gid = mmi_frm_group_create(g_bgsound_id,GRP_ID_AUTO_GEN,cui_bgsound_effect_list_proc, (void*)NULL);

         mmi_frm_group_enter(g_bgsnd_list_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
         
         menu_id = cui_menu_create(g_bgsnd_list_gid,
                                     CUI_MENU_SRC_TYPE_APPCREATE,
                                     CUI_MENU_TYPE_APPSUB,
                                     MENU_ID_BGSND_CALL_SETUP_LIST,
                                     MMI_FALSE,
                                     (void*)NULL);
         
         cui_menu_set_default_left_softkey(menu_id,get_string(STR_GLOBAL_OK));
         
         cui_menu_set_default_right_softkey(menu_id,get_string(STR_GLOBAL_BACK));
         
	 cui_menu_set_currlist_highlighted_id(menu_id,(mmi_menu_id)(g_bgsnd_cntx.set.curr_effect + MMI_BGSOUND_EFFECT1));
         
         cui_menu_run(menu_id);
     }
     else
     {
         MMI_ASSERT(0);
     }

     

 }

 /*****************************************************************************
 * FUNCTION
 *  cui_bgsound_effect_list_proc
 *  Proc handler 
 * PARAMETERS
 *  event_structure
 * RETURNS
 *  mmi
 *****************************************************************************/
static mmi_ret cui_bgsound_effect_list_proc(mmi_event_struct *evt)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (menu_evt->parent_menu_id == MENU_ID_BGSND_CALL_SETUP_LIST)
            {
		mdi_audio_suspend_background_play();
		cui_menu_enable_tap_to_highlight(menu_evt->sender_id);
                mmi_bgsnd_entry_cs_effect_list(menu_evt);

		cui_menu_override_center_softkey(
                    menu_evt->sender_id, 
                    (WCHAR *)NULL, 
                    (UI_image_type) GetImage(IMG_GLOBAL_COMMON_CSK));
                break;
            }

		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
		case EVT_ID_CUI_MENU_ITEM_TAP:
            {
                if (menu_evt->highlighted_menu_id >= MMI_BGSOUND_EFFECT1 && menu_evt->highlighted_menu_id <= MMI_BGSOUND_EFFECT10)
                {
                    mmi_bgsnd_cs_effect_select_item();
                    mmi_frm_group_close(g_bgsnd_list_gid);
                    
                }
                else if (menu_evt->highlighted_menu_id >= MMI_BGSOUND_EFFECT11 && menu_evt->highlighted_menu_id <= MMI_BGSOUND_EFFECT20)
                {
                    mmi_bgsnd_cs_ext_pre_entry_option(evt);
                }
                break;
            }
                          
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            {
                S16 index = 0;

                if (menu_evt->highlighted_menu_id >= MMI_BGSOUND_EFFECT1 && menu_evt->highlighted_menu_id <= MMI_BGSOUND_EFFECT20)
                {
                    index = cui_menu_get_index_in_currlist_from_menu_id(menu_evt->sender_id,menu_evt->highlighted_menu_id);
                    
                    mmi_bgsnd_cs_effect_highlight_hdlr(index);
                    
                    if (index < BGSND_MAX_EFFECT)
                    {
                        cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_SELECT));
                    }
                    else
                    {
                        if (!mmi_bgsnd_util_get_ext_effect_status((U16) (bgsnd_curr_highlight - BGSND_MAX_EFFECT)))
                        {
                            cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_ADD));
                        }
                        else
                        {
                            cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_OPTIONS));
                        }
                    }
                }
                break;
            }
        case EVT_ID_CUI_MENU_LIST_EXIT:
            {
                if (menu_evt->parent_menu_id == MENU_ID_BGSND_CALL_SETUP_LIST)
                {
                    mmi_bgsnd_exit_cs_effect_list();
                }
                break;
            }

        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
            {
                cui_file_selector_result_event_struct * evt_bg = (cui_file_selector_result_event_struct *)evt;
                if (evt_bg->result > 0)
                {
                    /*user selected a file*/
                    mmi_bgsnd_cs_ext_effect_select_file_done(evt_bg->sender_id);
                                         
                    
                }
                 /*user cancel or FS error*/
                 cui_file_selector_close(evt_bg->sender_id);
                              
                break;
            }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        case EVT_ID_SCRN_GOBACK:
            mmi_frm_scrn_close_active_id();
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}




#define MMI_BGSND_CS_STATUS
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_status_toggle
 * DESCRIPTION
 *  This function is to toggle the on/off status of background sound
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_status_toggle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bgsnd_cntx.set.status != 0)
    {
        g_bgsnd_cntx.set.status = 0;
    }
    else
    {
    #ifdef __CTM_SUPPORT__
        if(srv_callset_ctm_get_mode() == MMI_TRUE)
        {
            mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_BGSND_CTM_MODE_ON)), MMI_EVENT_FAILURE, NULL);
                

       
            return;
        }
    #endif /* #ifdef __CTM_SUPPORT__ */
        g_bgsnd_cntx.set.status = 1;
    }

    /* Write result to NVRAM */
    mmi_bgsnd_util_write_setup_data();
}

#define MMI_BGSND_CS_PLAYBACK_SETUP


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_playback_prepare_inline_data
 * DESCRIPTION
 *  This function is to prepare the inline data for playback setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_prepare_inline_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* repeat type */
    if (g_bgsnd_cntx.set.play_type < BGSND_REPEAT_NUM)
    {
        bgsnd_repeat = g_bgsnd_cntx.set.play_type;
    }
    else
    {
        bgsnd_repeat = 0;
    }

    /* Interval */
    if (g_bgsnd_cntx.set.interval_sec <= BGSND_MAX_INTERVAL)
    {
        kal_wsprintf(bgsnd_interval_buf, "%d", g_bgsnd_cntx.set.interval_sec);
    }
    else
    {
        memset(bgsnd_interval_buf, 0, 2);
    }

    /* volume */
    if (g_bgsnd_cntx.set.volume <= BGSND_MAX_VOLUME)
    {
        kal_wsprintf(bgsnd_volume_buf, "%d", g_bgsnd_cntx.set.volume);
    }
    else
    {
        memset(bgsnd_volume_buf, 0, 2);
    }

    /* Enter inline editor screen */
    mmi_bgsnd_entry_cs_playback_setup();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cs_playback_setup_done
 * DESCRIPTION
 *  This function is the entry function of playback setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_setup_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    cui_inline_get_value(g_bgsound_inline_gid, APP_TEXTEDIT1, (void *)bgsnd_volume_buf);
    

    cui_inline_get_value(g_bgsound_inline_gid, APP_TEXTEDIT2, (void *)bgsnd_interval_buf);

    if(mmi_ucs2strlen((S8*)bgsnd_volume_buf) == 0 ||
      ((bgsnd_repeat == BGSND_REPEAT_INTERVAL)&& (mmi_ucs2strlen((S8*)bgsnd_interval_buf) == 0)))
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_EMPTY)), MMI_EVENT_FAILURE, NULL);
            
      
    }
    else
    {
        mmi_bgsnd_cs_playback_save_confirm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_playback_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler for playback settings
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_highlight_hdlr(S32 index)
{
    if (index != BGSND_SETUP_INTERVAL && bgsnd_repeat == BGSND_REPEAT_INTERVAL)
    {
        interval_buf = gui_atoi((UI_string_type) bgsnd_interval_buf);
    }
}



/*Volume Caption*/
cui_inline_item_caption_struct caption1 = {STR_GLOBAL_VOLUME};

/* Volume*/
cui_inline_item_text_edit_struct textedit_bg_vol = {0, NULL, BGSND_VOLUME_LEN, IMM_INPUT_TYPE_NUMERIC, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, NULL};

/*PLay Mode Caption*/
const cui_inline_item_caption_struct caption2 = {STR_ID_BGSND_PLAY_MODE_CAP};

/*Repeat type*/
const cui_inline_item_select_struct select ={BGSND_REPEAT_NUM, 0,/*bgsnd_repeat,*/ g_bgsnd_repeat_str_id};       
 
/*Interval*/
const cui_inline_item_text_edit_struct textedit_bg_interval = {0, NULL, BGSND_INTERVAL_LEN, IMM_INPUT_TYPE_NUMERIC, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, NULL};

const cui_inline_set_item_struct bgsnd_inline[] = 
{
    /*Volume Caption*/
    {APP_CAPTION1,      CUI_INLINE_ITEM_TYPE_CAPTION  , 0, (void *)&caption1},
    
    /* Volume*/
    {APP_TEXTEDIT1,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void *)&textedit_bg_vol},

    /*PLay Mode*/
    {APP_CAPTION2,      CUI_INLINE_ITEM_TYPE_CAPTION  , 0, (void *)&caption2},

    /*Repeat type*/
    {APP_SELECT,        CUI_INLINE_ITEM_TYPE_SELECT,  0, &select},
     
    /*Interval*/
    {APP_TEXTEDIT2,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void *)&textedit_bg_interval},

   
};



cui_inline_item_softkey_struct bgsnd_softkey = {{{STR_GLOBAL_OK, 0}, {STR_GLOBAL_BACK, 0}, {0, 0XFFFF}}};

const cui_inline_struct g_initial_data = 
{
    5,///
    STR_GLOBAL_EDIT,
    0, 
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    bgsnd_inline
};


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cs_playback_setup
 * DESCRIPTION
 *  This function is the entry function of playback setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_cs_playback_setup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_bgsound_inline_gid = cui_inline_create(g_bgsound_id, &g_initial_data);


    cui_inline_set_screen_attributes(g_bgsound_inline_gid, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_DEFAULT_TEXT);

	
	if (bgsnd_repeat == BGSND_REPEAT_INTERVAL)
	{
	  cui_inline_set_item_attributes(g_bgsound_inline_gid, APP_TEXTEDIT2, CUI_INLINE_RESET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
	}
	else
	{
	  cui_inline_set_item_attributes(g_bgsound_inline_gid, APP_TEXTEDIT2, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
	  
	}

#ifndef __COSMOS_MMI_PACKAGE__
    cui_inline_set_title(g_bgsound_inline_gid, STR_ID_BGSND_PLAYBACK_SETUP,GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING));
#endif /* __COSMOS_MMI_PACKAGE__ */

    cui_inline_set_value(g_bgsound_inline_gid, APP_TEXTEDIT2, (void*)bgsnd_interval_buf);
    cui_inline_set_value(g_bgsound_inline_gid, APP_TEXTEDIT1,(void*)bgsnd_volume_buf);
    cui_inline_set_value(g_bgsound_inline_gid, APP_SELECT,(void*)bgsnd_repeat);


    cui_inline_run(g_bgsound_inline_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_exit_cs_playback_setup
 * DESCRIPTION
 *  This function is the exit function of playback setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_exit_cs_playback_setup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  GenericExitInlineScreen(SCR_ID_BGSND_CS_PLAYBACK, mmi_bgsnd_entry_cs_playback_setup);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_playback_repeat_hdlr
 * DESCRIPTION
 *  This function is the inline selection handler for repeat type
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_repeat_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == BGSND_REPEAT_INTERVAL)
    {
        gui_itoa(interval_buf, (U16*) wgui_inline_items[BGSND_SETUP_INTERVAL].text_p, 10);
        EnableInlineItem(&wgui_inline_items[BGSND_SETUP_INTERVAL], BGSND_SETUP_INTERVAL);
        show_fixed_list_specified_item(BGSND_SETUP_INTERVAL);
    }
    else
    {
        kal_wsprintf(bgsnd_interval_buf, "%d", 0);
        show_fixed_list_specified_item(BGSND_SETUP_INTERVAL);
        DisableInlineItem(&wgui_inline_items[BGSND_SETUP_INTERVAL], BGSND_SETUP_INTERVAL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_playback_fill_inline_item
 * DESCRIPTION
 *  This function is to fill the inline item for the playback setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_fill_inline_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get string each time because the language may change */
    bgsnd_repeat_str[BGSND_REPEAT_ONCE] = GetString(STR_ID_BGSND_ONCE);
    bgsnd_repeat_str[BGSND_REPEAT_INTERVAL] = GetString(STR_ID_BGSND_INTERVAL);
    bgsnd_repeat_str[BGSND_REPEAT_CONTINUE] = GetString(STR_ID_BGSND_CONTINUE);

   /*-- Volume Caption --*/
    SetInlineItemActivation(&(wgui_inline_items[BGSND_SETUP_VOLUME_CAP]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
//#if defined(__MMI_MAINLCD_128X128__)
    SetInlineItemCaption(&(wgui_inline_items[BGSND_SETUP_VOLUME_CAP]), (U8*) GetString(STR_GLOBAL_VOLUME));
//#else 
   // SetInlineItemCaption(&(wgui_inline_items[BGSND_SETUP_VOLUME_CAP]), (U8*) GetString(STR_ID_BGSND_VOLUME_CAP));
//#endif 

   /*-- Volume --*/
    SetInlineItemActivation(&wgui_inline_items[BGSND_SETUP_VOLUME], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[BGSND_SETUP_VOLUME],
        (U8*) bgsnd_volume_buf,
        BGSND_VOLUME_LEN,
        IMM_INPUT_TYPE_NUMERIC);
    DisableInlineItemHighlight(&wgui_inline_items[BGSND_SETUP_VOLUME]);

    /*-- Play Mode Cap --*/ 
    SetInlineItemActivation(&(wgui_inline_items[BGSND_SETUP_PLAY_MODE_CAP]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[BGSND_SETUP_PLAY_MODE_CAP]), (U8*) GetString(STR_ID_BGSND_PLAY_MODE_CAP));

   /*-- Repeat Type --*/
    SetInlineItemActivation(&(wgui_inline_items[BGSND_SETUP_REPEAT]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &(wgui_inline_items[BGSND_SETUP_REPEAT]),
        BGSND_REPEAT_NUM,
        (U8 **) bgsnd_repeat_str,
        &bgsnd_repeat);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[BGSND_SETUP_REPEAT], mmi_bgsnd_cs_playback_repeat_hdlr);

   /*-- Interval --*/
    SetInlineItemActivation(&wgui_inline_items[BGSND_SETUP_INTERVAL], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[BGSND_SETUP_INTERVAL],
        (U8*) bgsnd_interval_buf,
        BGSND_INTERVAL_LEN,
        IMM_INPUT_TYPE_NUMERIC);
    DisableInlineItemHighlight(&wgui_inline_items[BGSND_SETUP_INTERVAL]);

    if (bgsnd_repeat != BGSND_REPEAT_INTERVAL)  /* not Days */
    {
        DisableInlineItem(&wgui_inline_items[BGSND_SETUP_INTERVAL], BGSND_SETUP_INTERVAL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_playback_save_confirm
 * DESCRIPTION
 *  This function is to confirm save before saving playback setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
      
    do {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.callback = (mmi_proc_func)mmi_bgsnd_cs_playback_save_confirmCb;
	arg.parent_id = g_bgsound_id;
	mmi_confirm_display((WCHAR *)((U16*)get_string(STR_GLOBAL_SAVE_ASK)), MMI_EVENT_QUERY, &arg);

        } while(0);
}  
 
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_playback_save_confirmCb
 * DESCRIPTION
 *  This function is callback to confirm popup
 * PARAMETERS
 *  event_structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/


static mmi_ret mmi_bgsnd_cs_playback_save_confirmCb(mmi_alert_result_evt_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_1:
        case MMI_ALERT_CNFM_2:
        case MMI_ALERT_CNFM_3:
             break;
        case MMI_ALERT_CNFM_OK:
            break;
        case MMI_ALERT_CNFM_YES:
            mmi_bgsnd_cs_playback_save();
            break; 
        case MMI_ALERT_CNFM_NO:
            mmi_bgsnd_cs_playback_abort();
            break;
            
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_playback_save
 * DESCRIPTION
 *  This function is to save the playback setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_interval[BGSND_INTERVAL_LEN];
    S8 ascii_volume[BGSND_VOLUME_LEN];
    U16 interval_value = 0;
    U16 volume_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check volume */

    
    cui_inline_get_value(g_bgsound_inline_gid, APP_SELECT, (void *)&(bgsnd_repeat));
    

    mmi_ucs2_to_asc(ascii_volume, (S8*) bgsnd_volume_buf);
    volume_value = atoi(ascii_volume);

    if ((volume_value > BGSND_MAX_VOLUME) || (volume_value == 0))
    {
         mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_BGSND_INVALID_VOLUME)), MMI_EVENT_FAILURE, NULL);
        return;
    }

    /* check interval */
    if (bgsnd_repeat == BGSND_REPEAT_INTERVAL)
    {
        mmi_ucs2_to_asc(ascii_interval, (S8*) bgsnd_interval_buf);
        interval_value = (U16) atoi(ascii_interval);

        if ((interval_value < BGSND_MIN_INTERVAL) || (interval_value > BGSND_MAX_INTERVAL))
        {
            mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_BGSND_INVALID_INTERVAL)), MMI_EVENT_FAILURE, NULL);
                        
          
            return;
        }
    }
	else
	{
	  interval_buf = 0;
	 
	}

    /* Inline CUI*/
    
    /* Assign vaule and save */
    g_bgsnd_cntx.set.play_type = (U8) bgsnd_repeat;
    g_bgsnd_cntx.set.interval_sec = interval_value;
    g_bgsnd_cntx.set.volume = (U8) volume_value;

    mmi_bgsnd_util_write_setup_data();


    mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_EVENT_SUCCESS, NULL);

    cui_inline_close(g_bgsound_inline_gid);
  
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_playback_abort
 * DESCRIPTION
 *  This function is to abort setting and go back history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
   cui_inline_close(g_bgsound_inline_gid);
    
}

#define MMI_BGSND_CS_EFFECT_LIST




/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_effect_highlight_callback
 * DESCRIPTION
 *  This function is the time out callback function for playing sound in effect list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_effect_highlight_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 index;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bgsnd_curr_highlight < BGSND_MAX_EFFECT)
    {
    #ifdef __MMI_SILENT_MEETING_PROFILE__
        if ((srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE))== SRV_PROF_RET_PROFILE_NOT_ACTIVATED &&
			    (srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE)) == SRV_PROF_RET_PROFILE_NOT_ACTIVATED)
    #else 
        if ((srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE))== SRV_PROF_RET_PROFILE_NOT_ACTIVATED)
    #endif 
        {
            mmi_bgsnd_util_play_by_highlight_index(bgsnd_curr_highlight);
        }
    }
    /* external file */
    else if (bgsnd_curr_highlight < BGSND_TOTAL_EFFECT)
    {
        index = bgsnd_curr_highlight - BGSND_MAX_EFFECT + 1;
        ReadRecord(NVRAM_EF_BGSND_FILEPATH_LID, index, (void*)read_buff, NVRAM_EF_BGSND_FILEPATH_SIZE, &pError);

        if (!(read_buff[0] == '\0' && read_buff[1] == '\0'))
        {
        #ifdef __MMI_SILENT_MEETING_PROFILE__
        if ((srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE))== SRV_PROF_RET_PROFILE_NOT_ACTIVATED &&
			    (srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE)) == SRV_PROF_RET_PROFILE_NOT_ACTIVATED)
        #else 
        if ((srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE))== SRV_PROF_RET_PROFILE_NOT_ACTIVATED)
        #endif 
            {
                mmi_bgsnd_util_play_file((U16*) read_buff);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_effect_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler for effect list
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_effect_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bgsnd_curr_highlight = index;
    mmi_bgsnd_util_stop_setup_play_sound();

#ifdef __DRM_SUPPORT__
    mmi_bgsnd_util_ext_effect_check_forward_rule(bgsnd_curr_highlight, FALSE);
#else
    #if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        return;
    }
    #endif
    StartTimer(BGSND_HIGHLIGHT_TIMER, BGSND_HIGHLIGHT_TIMER_DUR, mmi_bgsnd_cs_effect_highlight_callback);
#endif/*__DRM_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cs_effect_list
 * DESCRIPTION
 *  This function is the entry function for the effect list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_cs_effect_list(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     S32 i =0;
     mmi_menu_id root_ids[BGSND_TOTAL_EFFECT] =
     {
        MMI_BGSOUND_EFFECT1,
        MMI_BGSOUND_EFFECT2,
        MMI_BGSOUND_EFFECT3,
        MMI_BGSOUND_EFFECT4,
        MMI_BGSOUND_EFFECT5,
        MMI_BGSOUND_EFFECT6,
        MMI_BGSOUND_EFFECT7,
        MMI_BGSOUND_EFFECT8,
        MMI_BGSOUND_EFFECT9,
        MMI_BGSOUND_EFFECT10,
        MMI_BGSOUND_EFFECT11,
        MMI_BGSOUND_EFFECT12,
        MMI_BGSOUND_EFFECT13,
        MMI_BGSOUND_EFFECT14,
        MMI_BGSOUND_EFFECT15,
        MMI_BGSOUND_EFFECT16,
        MMI_BGSOUND_EFFECT17,
        MMI_BGSOUND_EFFECT18,
        MMI_BGSOUND_EFFECT19,
        MMI_BGSOUND_EFFECT20
     };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
                   
    if (g_bgsnd_cntx.set.curr_effect < BGSND_TOTAL_EFFECT)
    {
        bgsnd_curr_highlight = g_bgsnd_cntx.set.curr_effect;
    }

    /* fill effect list data */
    mmi_bgsnd_util_prepare_effect_list(FALSE);

	#ifdef __DRM_SUPPORT__
	g_bgsnd_cntx.current_function_status = BGSND_FUNCTION_SETTING;
	#endif /*  __DRM_SUPPORT__ */

#ifndef __COSMOS_MMI_PACKAGE__
    cui_menu_set_currlist_title(menu_evt->sender_id,(WCHAR*)get_string(STR_ID_BGSND_EFFECT_LIST),
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING)));
#endif /* __COSMOS_MMI_PACKAGE__ */
    
    cui_menu_set_currlist(menu_evt->sender_id,BGSND_TOTAL_EFFECT,(mmi_menu_id*)root_ids);
    
    for( i =0; i<BGSND_TOTAL_EFFECT; i++)
    {
        cui_menu_set_item_string(menu_evt->sender_id,root_ids[i],(WCHAR*)subMenuDataPtrs[i]);
        cui_menu_set_item_image(menu_evt->sender_id,root_ids[i],gIndexIconsImageList[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_exit_cs_effect_list
 * DESCRIPTION
 *  This function is the exit function of effect list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_exit_cs_effect_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bgsnd_util_stop_setup_play_sound();

    /* it is out of effect list under setting */
#ifdef __DRM_SUPPORT__
    g_bgsnd_cntx.current_function_status = BGSND_FUNCTION_NONE;
#endif /* __DRM_SUPPORT__ */

    /* resume background play */
    mdi_audio_resume_background_play();

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_clear_volume_sync_callback(APP_BGSOUND);
#endif /* __BT_SPK_VOL_CONTROL__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_effect_stop_and_back
 * DESCRIPTION
 *  This function is to stop playing background sound and go back history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_effect_stop_and_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bgsnd_util_stop_setup_play_sound();

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_effect_select_item
 * DESCRIPTION
 *  This function is to save the effect list selection
 * PARAMETERS
 *  Pointer to menu_event_struct
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_effect_select_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bgsnd_cntx.set.curr_effect = (U8) bgsnd_curr_highlight;
    mmi_bgsnd_util_write_setup_data();

    mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, NULL);


}



/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_ext_pre_entry_option
 * DESCRIPTION
 *  This function is check the external file state before operate on external sound effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_ext_pre_entry_option(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    U16 str_id = 0;
    S16 pError;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];
    U16 curr_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_index = bgsnd_curr_highlight - BGSND_MAX_EFFECT;
    g_bgsnd_cntx.file_exist = TRUE;

    if (mmi_bgsnd_check_usb_mode())
    {
        return;
    }

    /* If external file exists, check its correctness. */
    if (mmi_bgsnd_util_get_ext_effect_status(curr_index))
    {
        ReadRecord(
            NVRAM_EF_BGSND_FILEPATH_LID,
            (U16) (curr_index + 1),
            (void*)read_buff,
            NVRAM_EF_BGSND_FILEPATH_SIZE,
            &pError);
    #ifdef __DRM_SUPPORT__
        if (!g_bgsnd_cntx.drm_permission_state)
        {
		
            do {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
	arg.softkey[0].str = (WCHAR *)(get_string(STR_GLOBAL_OK));
	arg.softkey[2].str = (WCHAR *)(get_string(0));
        arg.f_auto_map_empty_softkey = MMI_FALSE;
	arg.callback = (mmi_proc_func)mmi_bgsnd_DRM_confirmCb;
	mmi_confirm_display((WCHAR *)((U16*)get_string(STR_GLOBAL_DRM_PROHIBITED)), MMI_EVENT_FAILURE, &arg);
              } while(0);
	    		

            return;
        }
        else
    #endif
        {
            result = mdi_audio_snd_check_file_format((void*)read_buff);
        }
    }
    else    /* Not select yet. */
    {
        result = MDI_AUDIO_SUCCESS;
    }

    /* Check file success */
    if (result == MDI_AUDIO_SUCCESS)
    {
#ifdef __MMI_FTE_SUPPORT__
	if (!g_bgsnd_tap_effect)
#endif	
	{	
	    if (!mmi_bgsnd_util_get_ext_effect_status((U16) (bgsnd_curr_highlight - BGSND_MAX_EFFECT)))
	   {
            mmi_bgsnd_cs_ext_effect_select_from_fmgr(g_bgsnd_list_gid);
		return;
	    }
	    
             if (evt->evt_id == EVT_ID_CUI_MENU_ITEM_CSK_SELECT)
	    {
		mmi_bgsnd_cs_ext_effect_select_item();
                mmi_frm_group_close(g_bgsnd_list_gid);
	     }
	     else
	     {
        mmi_bgsnd_entry_cs_ext_effect_option();

	 }
        return;
    }
  }
    else if (result == MDI_AUDIO_OPEN_FILE_FAIL)
    {
        str_id = STR_ID_BGSND_OPEN_FILE_FAIL;
    }
    else if (result == MDI_AUDIO_BAD_FORMAT)
    {
        str_id = STR_ID_BGSND_INVALID_FILE;
    }
    else
    {
        str_id = STR_ID_BGSND_PLAY_FAIL;
    }
    g_bgsnd_cntx.file_exist = FALSE;

    /* Check file fail, prompt user */
    do {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
	arg.softkey[0].str = (WCHAR *)(get_string(STR_GLOBAL_OK));
	arg.softkey[2].str = (WCHAR *)(get_string(0));
	arg.callback = (mmi_proc_func)mmi_bgsnd_file_not_exist_confirmCb;
	arg.parent_id = g_bgsnd_list_gid;
	mmi_confirm_display((WCHAR *)((U16*)get_string(str_id)), MMI_EVENT_FAILURE, &arg);

	} while(0);
   


}
#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_DRM_confirmCb
 * DESCRIPTION
 *  This function is the cb for DRM error
 * PARAMETERS
 *  event_structure
 * RETURNS
 *  mmi_ret_
 *****************************************************************************/
static mmi_ret mmi_bgsnd_DRM_confirmCb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
          case MMI_ALERT_CNFM_1:
            mmi_bgsnd_entry_cs_ext_effect_option();
            break;
          default:
            break; 
        }
}
    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_DRM_confirmCb
 * DESCRIPTION
 *  This function is the cb for DRM error
 * PARAMETERS
 *  event_structure
 * RETURNS
 *  mmi_ret_
 *****************************************************************************/
static mmi_ret mmi_bgsnd_file_not_exist_confirmCb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
          case MMI_ALERT_CNFM_1:
	  case MMI_ALERT_CNFM_2:
            mmi_bgsnd_entry_cs_ext_effect_option();
            break;
          default:
            break; 
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_exit_cs_ext_effect_option
 * DESCRIPTION
 *  This function is the exit function for the external file option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_exit_cs_ext_effect_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __DRM_SUPPORT__
    if (!g_bgsnd_cntx.drm_permission_state)
    {
        mmi_frm_unhide_menu_item(MENU_ID_BGSND_EXT_EFFECT_SELECT);
    }
    #endif
    if (!g_bgsnd_cntx.file_exist)
    {
        mmi_frm_unhide_menu_item(MENU_ID_BGSND_EXT_EFFECT_SELECT);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_back_cs_ext_effect_option
 * DESCRIPTION
 *  This function is the exit function for the external file option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_back_cs_ext_effect_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_close_active_id();
#if 0
#ifdef __MMI_BACKGROUND_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_BACKGROUND_CALL__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cs_ext_effect_option
 * DESCRIPTION
 *  This function is the entry function for the external file option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_cs_ext_effect_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    
    g_bgs_option_gid = mmi_frm_group_create(
        g_bgsnd_list_gid,GRP_ID_AUTO_GEN,cui_bgsound_options_proc, (void*)NULL); 
    mmi_frm_group_enter(g_bgs_option_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
      g_bgs_menu_option_id = cui_menu_create(
          g_bgs_option_gid,
          CUI_MENU_SRC_TYPE_RESOURCE,
          CUI_MENU_TYPE_OPTION,
          MENU_ID_BGSND_EXT_EFFECT_OPTION,
          MMI_TRUE,
          NULL);

#ifndef __COSMOS_MMI_PACKAGE__
      cui_menu_set_default_title(
          g_bgs_menu_option_id,
          get_string(STR_GLOBAL_OPTIONS),
          #ifdef __UCM_SUPPORT__
          get_image(GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING))
          #else
          get_image(GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT))
          #endif
          );
#endif /* __COSMOS_MMI_PACKAGE__ */     
      
      cui_menu_set_default_left_softkey(
          g_bgs_menu_option_id,
          get_string(STR_GLOBAL_SELECT));
      
      cui_menu_set_default_right_softkey(
          g_bgs_menu_option_id,
          get_string(STR_GLOBAL_BACK));

   /* if (!g_bgsnd_cntx.file_exist)
    {
          cui_menu_set_item_hidden(g_bgs_menu_option_id,MENU_ID_BGSND_EXT_EFFECT_SELECT,MMI_TRUE);
    }*/
      
      cui_menu_run(g_bgs_menu_option_id);
    }

/*****************************************************************************
 * FUNCTION
 *  cui_bgsound_options_proc
 * DESCRIPTION
 *  Proc handler 
 * PARAMETERS
 *  event_structure
 * RETURNS
 *  mmi
 *****************************************************************************/

static mmi_ret cui_bgsound_options_proc(mmi_event_struct *evt)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

     switch (menu_evt->evt_id)
    {
	case EVT_ID_CUI_MENU_LIST_ENTRY:
	{
	   if (!g_bgsnd_cntx.file_exist)
	   {
		 cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_BGSND_EXT_EFFECT_SELECT,MMI_TRUE);
	   }
	   else
	   {
		 cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_BGSND_EXT_EFFECT_SELECT,MMI_FALSE);
           }

	}
	break;



        case EVT_ID_CUI_MENU_ITEM_SELECT:
	{

            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_BGSND_EXT_EFFECT_SELECT:
                    mmi_bgsnd_cs_ext_effect_select_item();
                    mmi_frm_group_close(g_bgsnd_list_gid);
                    break;

                case MENU_ID_BGSND_EXT_EFFECT_EDIT:
                    mmi_bgsnd_cs_ext_effect_select_from_fmgr(g_bgs_option_gid);
                    break;

                case MENU_ID_BGSND_EXT_EFFECT_DELETE:
                    mmi_bgsnd_cs_ext_effect_delete_confirm();
                    break;

                default:
                    break;
            }
	}
            break;


         case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;


        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;

        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
    {
                cui_file_selector_result_event_struct * evt_bg = (cui_file_selector_result_event_struct *)evt;
                if (evt_bg->result > 0)
    {
                    /*user selected a file*/
                    mmi_bgsnd_cs_ext_effect_select_file_done(evt_bg->sender_id);


    }
                 /*user cancel or FS error*/
                 cui_file_selector_close(evt_bg->sender_id);

                break;
            }



        
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_ext_effect_select_item
 * DESCRIPTION
 *  This function is to save the external effect list selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_ext_effect_select_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bgsnd_cntx.set.curr_effect = (U8) bgsnd_curr_highlight;
    mmi_bgsnd_util_write_setup_data();

    mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, NULL);

    
    //mmi_frm_group_close(g_bgs_option_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_ext_effect_select_from_fmgr
 * DESCRIPTION
 *  This function is to enter file manager to select an external file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_ext_effect_select_from_fmgr(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* UI_character_type path[MAX_FMSR_PATH_LEN]; */
    mmi_id bgsound_fmgr_gid;
    FMGR_FILTER filter;

    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_fmsr_util_get_storage_path((UI_string_type)path, (U8)g_fmsr_cntx.setting.storage); */

    if (!mmi_frm_group_is_present(grp_id))
    {
        mmi_frm_group_enter(grp_id,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }


    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WAV);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_AMR); //[Lanus add]
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    bgsound_fmgr_gid = cui_file_selector_create(grp_id, 
                                      (WCHAR*) L"root", 
                                      &filter, 
                                      CUI_FILE_SELECTOR_STYLE_FILE_ONLY, 
                                      CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL | CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);

    if (bgsound_fmgr_gid != GRP_ID_INVALID)
    {  
        cui_file_selector_run(bgsound_fmgr_gid);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_ext_effect_select_file_done
 * DESCRIPTION
 *  This function is the callback function when select from file manager done.
 * PARAMETERS
 *  fullname        [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_ext_effect_select_file_done(mmi_id bgsnd_fmgr_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 index;
    S8 filepath[SRV_FMGR_PATH_BUFFER_SIZE];
    S8 read_buff[SRV_FMGR_PATH_BUFFER_SIZE];
    srv_fmgr_fileinfo_struct file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_file_selector_get_selected_filepath(bgsnd_fmgr_gid, &file_info, (WCHAR*)&filepath, SRV_FMGR_PATH_BUFFER_SIZE);



    if (((U16*)filepath)[0] == 0)
    {
    
        //cui_file_selector_close(bgsnd_fmgr_gid);
        //mmi_frm_group_close(bgsnd_fmgr_gid);
        return ;
    }
    else if (!mmi_bgsnd_util_check_file_format(filepath))
    {
        mmi_popup_display((WCHAR*)((UI_string_type)get_string(STR_ID_BGSND_INVALID_FILE)), MMI_EVENT_FAILURE, NULL);
                    
    }
    else
    {
        /* Check if file name duplicated */
        for (index = 0; index < BGSND_MAX_EXT_EFFECT; index++)
        {
            ReadRecord(
                NVRAM_EF_BGSND_FILEPATH_LID,
                (U16) (index + 1),
                (void*)read_buff,
                NVRAM_EF_BGSND_FILEPATH_SIZE,
                &pError);

            if (!(read_buff[0] == '\0' && read_buff[1] == '\0'))
            {
                if (mmi_ucs2cmp((S8*) filepath, (S8*) read_buff) == 0)
                {

                    mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_BGSND_FILE_DUPLICATED)), MMI_EVENT_FAILURE, NULL);
                    return;
                }
            }
        }

        /* Update filepath data */
        if ((bgsnd_curr_highlight >= BGSND_MAX_EFFECT) && (bgsnd_curr_highlight < BGSND_TOTAL_EFFECT))
        {
            index = bgsnd_curr_highlight - BGSND_MAX_EFFECT + 1;
            WriteRecord(NVRAM_EF_BGSND_FILEPATH_LID, index, (void*)filepath, NVRAM_EF_BGSND_FILEPATH_SIZE, &pError);
        }

       // fmgr_reset_app_select();    /* Use select_repeat, so clear by application itself. */
        
        mmi_popup_display((WCHAR*)((UI_string_type)get_string(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, NULL);
           
        
       
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_ext_effect_delete_confirm
 * DESCRIPTION
 *  This function is to confirm deleting external file link
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_ext_effect_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        arg.f_auto_map_empty_softkey = MMI_FALSE;
	arg.callback = (mmi_proc_func)mmi_bgsnd_cs_ext_effect_delete_confirmcb;
	mmi_confirm_display((WCHAR *)((U16*)get_string(STR_ID_BGSND_DEL_FILE_CONFIRM)), MMI_EVENT_QUERY, &arg);
	} while(0);
    
      
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_ext_effect_delete_confirmcb
 * DESCRIPTION
 *  This function is the cb for DRM error
 * PARAMETERS
 *  event_structure
 * RETURNS
 *  mmi_ret_
 *****************************************************************************/
static mmi_ret mmi_bgsnd_cs_ext_effect_delete_confirmcb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
           case MMI_ALERT_CNFM_YES:
              mmi_bgsnd_cs_ext_effect_delete();
              break; 
           case MMI_ALERT_CNFM_NO:
              mmi_bgsnd_back_cs_ext_effect_option();
              break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_ext_effect_delete
 * DESCRIPTION
 *  This function is to delete external file link
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_ext_effect_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 index;
    S8 buff[NVRAM_EF_BGSND_FILEPATH_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((bgsnd_curr_highlight >= BGSND_MAX_EFFECT) && (bgsnd_curr_highlight < BGSND_TOTAL_EFFECT))
    {
        index = bgsnd_curr_highlight - BGSND_MAX_EFFECT + 1;

        memset(buff, 0, 2);
        WriteRecord(NVRAM_EF_BGSND_FILEPATH_LID, index, (void*)buff, NVRAM_EF_BGSND_FILEPATH_SIZE, &pError);

        /* Set highlight to first effect */
        if (g_bgsnd_cntx.set.curr_effect == (U8) bgsnd_curr_highlight)
        {
            g_bgsnd_cntx.set.curr_effect = 0;
            mmi_bgsnd_util_write_setup_data();
        }
    }

    mmi_popup_display((WCHAR*)((UI_string_type)get_string(STR_GLOBAL_DELETED)), MMI_EVENT_SUCCESS, NULL);
            

}

#define MMI_BGSND_FROM_FMGR


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_fmgr_from_file_mgr
 * DESCRIPTION
 *  This function is to save file path forward from file manager
 * PARAMETERS
 *  path            [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_fmgr_from_file_mgr(S8 *path, BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0xFFFF, i;
    S16 pError;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {

        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_EMPTY)), MMI_EVENT_FAILURE, NULL);
            

      
        return;
    }
    else if (!mmi_bgsnd_util_check_file_format(path))
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_BGSND_INVALID_FILE)), MMI_EVENT_FAILURE, NULL);
            

       
        return;
    }

    /* Check if file name duplicated */
    for (i = 0; i < BGSND_MAX_EXT_EFFECT; i++)
    {
        ReadRecord(
            NVRAM_EF_BGSND_FILEPATH_LID,
            (U16) (i + 1),
            (void*)read_buff,
            NVRAM_EF_BGSND_FILEPATH_SIZE,
            &pError);

        if (!(read_buff[0] == '\0' && read_buff[1] == '\0'))
        {
            if (mmi_ucs2cmp((S8*) path, (S8*) read_buff) == 0)
            {
         
		mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_BGSND_FILE_DUPLICATED)), MMI_EVENT_FAILURE, NULL);

              
                return;
            }
        }
    }

    /* Find First Empty slot */
    for (index = 0; index < BGSND_MAX_EXT_EFFECT; index++)
    {
        ReadRecord(
            NVRAM_EF_BGSND_FILEPATH_LID,
            (U16) (index + 1),
            (void*)read_buff,
            NVRAM_EF_BGSND_FILEPATH_SIZE,
            &pError);

        if (read_buff[0] == '\0' && read_buff[1] == '\0')
        {
            break;
        }
    }

    if (index < BGSND_MAX_EXT_EFFECT)
    {
        WriteRecord(
            NVRAM_EF_BGSND_FILEPATH_LID,
            (U16) (index + 1),
            (void*)path,
            NVRAM_EF_BGSND_FILEPATH_SIZE,
            &pError);

        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, NULL);
                
        
      
    }
    else
    {

        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_BGSND_LIST_FULL)), MMI_EVENT_FAILURE, NULL);
         

    }
}

#define MMI_BGSND_CS_UTIL


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_prepare_effect_list
 * DESCRIPTION
 *  This function is to prepare the effect list. (Including default and external)
 * PARAMETERS
 *  add_no_effect       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_prepare_effect_list(BOOL add_no_effect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 index, base = 0;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];
    S8 *file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (add_no_effect)
    {
        mmi_ucs2ncpy((PS8) subMenuDataPtrs[0], GetString(STR_ID_BGSND_NO_EFFECT), MAX_SUBMENU_CHARACTERS);
        base = 1;
    }

    /* default effect */
    for (index = 0; index < BGSND_MAX_EFFECT; index++)
    {
        mmi_ucs2ncpy(
            (PS8) subMenuDataPtrs[index + base],
            GetString((U16) (STR_ID_BGSND_EFFECT_1 + index)),
            MAX_SUBMENU_CHARACTERS);
    }

    /* external effect */
    for (index = 0; index < BGSND_MAX_EXT_EFFECT; index++)
    {
        ReadRecord(
            NVRAM_EF_BGSND_FILEPATH_LID,
            (U16) (index + 1),
            (void*)read_buff,
            NVRAM_EF_BGSND_FILEPATH_SIZE,
            &pError);

        if (read_buff[0] == '\0' && read_buff[1] == '\0')
        {
            mmi_ucs2cpy((PS8) subMenuDataPtrs[index + BGSND_MAX_EFFECT + base], GetString(STR_GLOBAL_EMPTY_LIST));
            mmi_bgsnd_util_set_ext_effect_status(index, FALSE);
        }
        else    /* Truncate file name */
        {
            file_name =(S8*) srv_fmgr_path_get_filename_ptr((WCHAR*) read_buff);
            mmi_ucs2ncpy(
                (S8*) subMenuDataPtrs[index + BGSND_MAX_EFFECT + base],
                (S8*) file_name,
                MAX_SUBMENU_CHARACTERS);
            mmi_bgsnd_util_set_ext_effect_status(index, TRUE);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_prepare_ext_file_index
 * DESCRIPTION
 *  This function is to prepare external file index. This is to check
 *  if external file exists for later usage.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_prepare_ext_file_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 index;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* external effect */
    for (index = 0; index < BGSND_MAX_EXT_EFFECT; index++)
    {
        ReadRecord(
            NVRAM_EF_BGSND_FILEPATH_LID,
            (U16) (index + 1),
            (void*)read_buff,
            NVRAM_EF_BGSND_FILEPATH_SIZE,
            &pError);

        if (read_buff[0] == '\0' && read_buff[1] == '\0')
        {
            mmi_bgsnd_util_set_ext_effect_status(index, FALSE);
        }
        else
        {
            mmi_bgsnd_util_set_ext_effect_status(index, TRUE);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_callback
 * DESCRIPTION
 *  This function is the callback function when play finish
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bgsnd_cntx.setup_playing = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_by_highlight_index
 * DESCRIPTION
 *  This function is to play a audio string as background sound
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_by_highlight_index(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 audio_len;
    U8 *audio_data;
    U8 audio_type;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audio_data = get_audio((U16) (AUD_ID_BGSND_EFFECT1 + index), &audio_type, &audio_len);

    if (audio_data != NULL)
    {
        result = mdi_audio_play_string_with_vol_path(
                    (void*)audio_data,
                    audio_len,
                    audio_type,
                    DEVICE_AUDIO_PLAY_ONCE,                    
                    mmi_bgsnd_util_play_callback,
                    NULL,
                    g_bgsnd_cntx.set.volume - 1,
                    MDI_DEVICE_SPEAKER2);

        if (result == MDI_AUDIO_SUCCESS)
        {
            g_bgsnd_cntx.setup_playing = TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_file
 * DESCRIPTION
 *  This function is to play an external file as background sound
 * PARAMETERS
 *  full_path       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_file(U16 *full_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    if (!g_bgsnd_cntx.drm_permission_state)
    {
        mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DRM_PROHIBITED)), MMI_EVENT_FAILURE, g_bgsound_id, NULL);
        /*
        mmi_popup_display((WCHAR*)(get_string(STR_GLOBAL_DRM_PROHIBITED)), MMI_EVENT_FAILURE, NULL);*/
        return;
    }
    mdi_audio_drm_disable_consume_all();//preview no consume, this is useful for time permitted file
#endif /* __DRM_SUPPORT__ */
    result = mdi_audio_play_file_with_vol_path(
                (void*)full_path,
                DEVICE_AUDIO_PLAY_ONCE,
                NULL,
                mmi_bgsnd_util_play_callback,
                NULL,
                g_bgsnd_cntx.set.volume - 1,
                MDI_DEVICE_SPEAKER2);


    if (result == MDI_AUDIO_SUCCESS)
    {
        g_bgsnd_cntx.setup_playing = TRUE;
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_read_setup_data
 * DESCRIPTION
 *  This function is to read setup data in NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_read_setup_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 read_buff[NVRAM_EF_BGSND_SETTING_SIZE];
    bgsnd_cs_nvram_struct *read_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_BGSND_SETTING_LID, 1, (void*)read_buff, NVRAM_EF_BGSND_SETTING_SIZE, &pError);

    read_ptr = (bgsnd_cs_nvram_struct*) read_buff;

    /* Set default NVRAM 0xff value to default system value. */
    if (read_ptr->status == 255)
    {
        read_ptr->status = 0;
        read_ptr->play_type = BGSND_REPEAT_CONTINUE;
        read_ptr->interval_sec = 0;
        read_ptr->volume = BGSND_DEFAULT_VOLUME;
        read_ptr->curr_effect = 0;
    }

    memcpy(&g_bgsnd_cntx.set, read_buff, sizeof(bgsnd_cs_nvram_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_write_setup_data
 * DESCRIPTION
 *  This function is to write setup data back to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_write_setup_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 write_buff[NVRAM_EF_BGSND_SETTING_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(write_buff, &g_bgsnd_cntx.set, sizeof(bgsnd_cs_nvram_struct));

    WriteRecord(NVRAM_EF_BGSND_SETTING_LID, 1, (void*)write_buff, NVRAM_EF_BGSND_SETTING_SIZE, &pError);
    
    srv_bgsnd_common_set_mo_bgs_permit_state(g_bgsnd_cntx.set.status);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_check_file_format
 * DESCRIPTION
 *  This function is to check the data format for audio file
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bgsnd_util_check_file_format(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_snd_check_file_format(file_name) == MDI_AUDIO_SUCCESS)
    {
        return TRUE;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_set_ext_effect_status
 * DESCRIPTION
 *  This function is to store the external file exist/not-exist state in a bit-wise array
 * PARAMETERS
 *  index       [IN]        
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_set_ext_effect_status(U16 index, BOOL state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 arr_id;
    U8 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    arr_id = index / 8;
    pos = index - arr_id * 8;

    if (state)
    {
        bgsnd_ext_effect[arr_id] |= 1 << pos;
    }
    else
    {
        bgsnd_ext_effect[arr_id] &= (~(1 << pos));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_get_ext_effect_status
 * DESCRIPTION
 *  This function is to get the external file exist/not-exist state in a bit-wise array
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bgsnd_util_get_ext_effect_status(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 arr_id;
    U8 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    arr_id = index / 8;
    pos = index - arr_id * 8;

    return bgsnd_ext_effect[arr_id] & (1 << pos);
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_ext_effect_check_forward_rule
 * DESCRIPTION
 *  This function is to check the external file can be forwarded or not
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_ext_effect_check_forward_rule(U16 index, BOOL add_no_effect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL drm_ret = TRUE;
    FS_HANDLE fh;
    S16 pError;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];
    U16 curr_index;
    U16 base;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (add_no_effect)
    {
        base = 1;
    }
    else
    {
        base = 0;
    }
    g_bgsnd_cntx.drm_permission_state = TRUE;
    if ((index >= (BGSND_MAX_EFFECT + base))
        && (index < (BGSND_TOTAL_EFFECT + base)))
    {
        curr_index = index - BGSND_MAX_EFFECT - base;
        
        if ( mmi_bgsnd_util_get_ext_effect_status(curr_index))
        {
            ReadRecord(
                NVRAM_EF_BGSND_FILEPATH_LID,
                (U16) (curr_index + 1),
                (void*) read_buff,
                NVRAM_EF_BGSND_FILEPATH_SIZE,
                &pError);
            if (!(read_buff[0] == '\0' && read_buff[1] == '\0'))
            {
                fh = DRM_open_file((kal_wchar *)read_buff, FS_READ_ONLY, DRM_PERMISSION_PLAY);

                if (fh >= FS_NO_ERROR)
                {
                    if (DRM_get_object_method(fh, NULL) != DRM_METHOD_NONE)
                    {
                        drm_ret = DRM_validate_forward_rule(fh, DRM_PERMISSION_PLAY);
                    }
                    else
                    {
                        drm_ret = TRUE;
                    }
                    DRM_close_file(fh);
                }
                /* if file not opened, it is processed in play api,
                important: in highlight handler api, in general not allowed popup, 
                otherwise will be traped in infinite loop */
            }
            if (drm_ret == FALSE)
            {
                g_bgsnd_cntx.drm_permission_state = FALSE;
            }
            else
            {
                g_bgsnd_cntx.drm_permission_state = TRUE;
            }
        }
    }
    if (g_bgsnd_cntx.current_function_status == BGSND_FUNCTION_SETTING)
    {
        #if defined(__MMI_BACKGROUND_CALL__)
        if (srv_ucm_is_background_call())
        {
            return;
        }
        #endif
        StartTimer(BGSND_HIGHLIGHT_TIMER, BGSND_HIGHLIGHT_TIMER_DUR, mmi_bgsnd_cs_effect_highlight_callback);
    }
}
#endif/* __DRM_SUPPORT__  */


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_stop_setup_play_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_stop_setup_play_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BGSND_HIGHLIGHT_TIMER);
    mdi_audio_stop_all();
    g_bgsnd_cntx.setup_playing = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_setup_sd_plug_out_hdlr
 * DESCRIPTION
 *  handle CARD plug-out event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_setup_sd_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Playing in the setup menu */
    if (g_bgsnd_cntx.setup_playing && (bgsnd_curr_highlight >= BGSND_MAX_EFFECT))
    {
        mmi_bgsnd_util_stop_setup_play_sound();
    }
    /* On the options item */	
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_go_back_2_history
 * DESCRIPTION
 *  This function is to go back 2 level of history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_go_back_2_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_check_usb_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bgsnd_check_usb_mode(void)
{
#ifdef __USB_IN_NORMAL_MODE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return TRUE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    return FALSE;
}

#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_hfp_volume_sync_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume      IN  volume want to set to BGSound by HFP
 *  is_mute     IN  BGSound not support mute
 * RETURNS
 *  MMI_TRUE    Set volume to BGSound OK
 *  MMI_FALSE   BGSound not handle the action
 *****************************************************************************/
 MMI_BOOL mmi_bgsnd_hfp_volume_sync_callback(U8 volume, MMI_BOOL is_mute)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((volume <= BGSND_MAX_VOLUME) && (volume > 0) && (is_mute == MMI_FALSE))
    {
       
        g_bgsnd_cntx.set.volume = volume;
	 volume--;	
        mdi_audio_snd_set_volume(volume);
        mmi_bgsnd_util_write_setup_data();
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif /*__BT_SPK_VOL_CONTROL__*/

#endif /* __MMI_BG_SOUND_EFFECT__ */ 
#endif /* _MMI_BGSOUNDSETTING_C */ 

