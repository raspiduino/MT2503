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
 * BGSoundInCall.C
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _MMI_BGSOUNDINCALL_C
#define _MMI_BGSOUNDINCALL_C


#ifdef __MMI_BG_SOUND_EFFECT__
#include "BgSoundSrvGprot.h"
/* RHR */
#include "MMI_features.h"
#include "MMIDataType.h"
//#include "kal_general_types.h"
#include "gui_data_types.h"
//#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "gui.h"
#include "UcmSrvGprot.h"
#include "gui_typedef.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "wgui_inline_edit.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_fixed_menus.h"
#include "stdlib.h"
#include "nvram_common_defs.h"
#include "mmi_media_app_trc.h"
#include "MMI_media_app_trc.h"
#include "kal_trace.h"
#include "mmi_frm_nvram_gprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "CustMenuRes.h"
#include "wgui_categories_list.h"

/* RHR */


/*  Include: MMI header file */
#include "mmi_rp_app_bgsound_def.h"
#include "Menucuigprot.h"
#include "CommonScreens.h"
//#include "SettingProfile.h"
//#include "nvram_user_defs.h"
//#include "CallManagementGprot.h"
//#include "IncomingCallManagementProt.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
//#include "SettingDefs.h"
#include "FileMgrSrvGProt.h"
//#include "FileManagerGProt.h"
#include "IdleAppDef.h"
#include "wgui_touch_screen.h"
//#include "BGSoundResDef.h"

/* ... Add More MMI header */
//#include "SimDetectionGprot.h"

#include "BGSoundDef.h"
#include "BGSoundType.h"
#include "BGSoundProt.h"
#include "BGSoundGProt.h"
#ifdef __CTM_SUPPORT__ 
#include "CallSetSrvGprot.h" /* srv_callset_ctm_get_mode */
#endif

#ifdef __DRM_SUPPORT__
//#include "Drm_gprot.h"  /* DRM support */
//#include "drm_def.h"
//#include "DRM_main.h"
#endif /* __DRM_SUPPORT__ */ 

#include "UCMGProt.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif


#include "mmi_rp_app_callset_def.h"


#include "Mmi_frm_scenario_gprot.h"
#include "Inlinecuigprot.h"
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
static U16 bgsnd_cm_highlight;
static U16 cm_interval_buf;

static U16 bgsnd_common_hilight;
static MMI_BOOL bgsnd_common_select;
static MMI_BOOL bgsnd_cm_state;
static MMI_BOOL bgsnd_common_default;


static S32 bgsnd_cm_repeat;
static UI_character_type bgsnd_cm_interval_buf[BGSND_INTERVAL_LEN];
static UI_character_type bgsnd_cm_volume_buf[BGSND_VOLUME_LEN];
static mmi_ret mmi_bgsnd_in_call_group_proc(mmi_event_struct *evt);
static mmi_ret cui_bgsound_cm_effect_list_proc(mmi_event_struct *evt);

extern S8 *bgsnd_repeat_str[];
mmi_id g_bgs_incall_inline_gid, g_bgs_incall_gid, bgs_menu_id1,g_bgsnd_incall_list_gid;

/* 
 * Local Function
 */
#define APP_CAPTION1             CUI_INLINE_ITEM_ID_BASE+10
#define APP_TEXTEDIT1            CUI_INLINE_ITEM_ID_BASE+11 
#define APP_CAPTION2             CUI_INLINE_ITEM_ID_BASE+12

#define APP_SELECT               CUI_INLINE_ITEM_ID_BASE+13
#define APP_TEXTEDIT2            CUI_INLINE_ITEM_ID_BASE+14

/* 
 * Global Variable
 */

/* 
 * Global Function
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_call_init
 * DESCRIPTION
 *  This function is to initialize background sound effect for call management
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_call_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UCM_SUPPORT__
    bgsnd_common_hilight = 0;
    bgsnd_common_select = MMI_FALSE;
    bgsnd_cm_state = MMI_FALSE;
    bgsnd_common_default = MMI_FALSE;
#else /* __UCM_SUPPORT__ */
    g_bgsnd_cntx.is_mt_call_select = FALSE;
    g_bgsnd_cntx.is_mo_call_select = FALSE;
    g_bgsnd_cntx.is_speech_on = MMI_FALSE;
    g_bgsnd_cntx.is_request_play = MMI_FALSE;
    bgsnd_mo_highlight = 0;
#endif /* __UCM_SUPPORT__ */
}


#define MMI_BGSND_CALL_MANAGE




/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_incall_opt_proc
 * DESCRIPTION
 *  The callback function provided by other applications who provide their own menu items. 
 *  It is used to handle the menu cui event. 
 *
 * PARAMETERS
 *  evt                     [IN]: Menu cui event
 *
 * RETURNS
 *  MMI_RET_OK: handle this event successfully
 *  Others: fail to handle this event
 *****************************************************************************/
mmi_ret mmi_bgsnd_incall_opt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    mmi_ret ret;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    ret = MMI_RET_OK;

    if (MENU_ID_BGSND_CM_OPT_EFFECT == menu_evt->highlighted_menu_id)
    {
        if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
        {
            mmi_bgsnd_pre_entry_call_manage();
        }
        else if (EVT_ID_CUI_MENU_CLOSE_REQUEST == menu_evt->evt_id)
        {
            cui_menu_close(menu_evt->sender_id);
            return ret;
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_call_manage
 * DESCRIPTION
 *  This function is the highlight function for sound effect during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_call_manage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_bgsnd_pre_entry_call_manage, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_pre_entry_call_manage
 * DESCRIPTION
 *  This function is the pre entry function for sound effect during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_pre_entry_call_manage(void)
{
#ifdef __CTM_SUPPORT__
    if(srv_callset_ctm_get_mode() == MMI_TRUE)
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_BGSND_CTM_MODE_ON)), MMI_EVENT_FAILURE, NULL);
    }
    else
#endif /* #ifdef __CTM_SUPPORT__ */
    {
        mmi_bgsnd_entry_call_manage();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_call_manage
 * DESCRIPTION
 *  This function is the entry function for sound effect during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_call_manage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bgs_incall_gid = mmi_frm_group_create(GRP_ID_ROOT,GRP_ID_AUTO_GEN,mmi_bgsnd_in_call_group_proc,(void*) NULL);
    mmi_frm_group_enter(g_bgs_incall_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    bgs_menu_id1 = cui_menu_create(g_bgs_incall_gid,
                                  CUI_MENU_SRC_TYPE_APPCREATE,
                                  CUI_MENU_TYPE_APPMAIN,
                                  MENU_ID_BGSND_CM_OPT_EFFECT,
                                  MMI_FALSE,
                                  (void*)NULL);





    /* Fill external effect list data */
    mmi_bgsnd_util_prepare_ext_file_index();
#ifndef __COSMOS_MMI_PACKAGE__
    cui_menu_set_default_title(bgs_menu_id1,get_string(STR_ID_BGSND_BG_SOUND),
        #ifdef __UCM_SUPPORT__
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING)));
        #else
        (UI_image_type)get_image(GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT)));
        #endif
#endif /* __COSMOS_MMI_PACKAGE__ */
    cui_menu_run(bgs_menu_id1);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_in_call_group_proc
 * DESCRIPTION
 *  Proc handler 
 * PARAMETERS
 *  event_structure
 * RETURNS
 *  mmi
 *****************************************************************************/
static mmi_ret mmi_bgsnd_in_call_group_proc(mmi_event_struct *evt)
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
            if (menu_evt->parent_menu_id == MENU_ID_BGSND_CM_OPT_EFFECT)
    {

                mmi_menu_id root_ids[3] = {MENU_ID_BGSND_CM_OPT_STATUS,MENU_ID_BGSND_CM_OPT_SETTING,MENU_ID_BGSND_CM_OPT_LIST};
            #ifndef __COSMOS_MMI_PACKAGE__
                cui_menu_set_currlist_title(menu_evt->sender_id,(WCHAR*)get_string(STR_ID_BGSND_BG_SOUND),
                    (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING)));
            #endif /* __COSMOS_MMI_PACKAGE__ */

                cui_menu_set_currlist(menu_evt->sender_id,3,(mmi_menu_id*)root_ids);

                cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_BGSND_CM_OPT_STATUS,get_string(STR_ID_BGSND_STATUS));
                cui_menu_set_item_image(menu_evt->sender_id,MENU_ID_BGSND_CM_OPT_STATUS,gIndexIconsImageList[0]);

                cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_BGSND_CM_OPT_SETTING,get_string(STR_ID_BGSND_PLAYBACK_SETUP));
                cui_menu_set_item_image(menu_evt->sender_id,MENU_ID_BGSND_CM_OPT_SETTING,gIndexIconsImageList[1]);

                cui_menu_set_item_string(menu_evt->sender_id,MENU_ID_BGSND_CM_OPT_LIST,get_string(STR_ID_BGSND_EFFECT_LIST));
                cui_menu_set_item_image(menu_evt->sender_id,MENU_ID_BGSND_CM_OPT_LIST,gIndexIconsImageList[2]);

                cui_menu_set_non_leaf_item(menu_evt->sender_id,MENU_ID_BGSND_CM_OPT_LIST,MMI_TRUE);
    }
    break; 

    	case EVT_ID_CUI_MENU_ITEM_SELECT:

            if (menu_evt->highlighted_menu_id == MENU_ID_BGSND_CM_OPT_STATUS)
{
                mmi_bgsnd_cm_status_toggle();

    if (g_bgsnd_cntx.cm.status != 0)
    {
                    cui_menu_set_item_hint(menu_evt->sender_id,MENU_ID_BGSND_CM_OPT_STATUS,get_string(STR_GLOBAL_ON));
    				        cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_OFF));
    }
    else
    {
                    cui_menu_set_item_hint(menu_evt->sender_id,MENU_ID_BGSND_CM_OPT_STATUS,get_string(STR_GLOBAL_OFF));
    				        cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_ON));
    }


            }
            if (menu_evt->highlighted_menu_id == MENU_ID_BGSND_CM_OPT_SETTING)
            {
                mmi_bgsnd_cm_setting_prepare_inline_data();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_BGSND_CM_OPT_LIST)
            {
                mmi_bgsnd_entry_cm_effect_list_group_enter(evt);
            }
            break;


    	case EVT_ID_CUI_MENU_ITEM_HILITE:
            {
                /* Status*/
                if (menu_evt->highlighted_menu_id == MENU_ID_BGSND_CM_OPT_STATUS)
                {

    			     if (g_bgsnd_cntx.cm.status != 0)
    			     {
    				    cui_menu_set_item_hint(menu_evt->sender_id,MENU_ID_BGSND_CM_OPT_STATUS,get_string(STR_GLOBAL_ON));
    				    cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_OFF));
    			     }
    			     else
    			     {
    				    cui_menu_set_item_hint(menu_evt->sender_id,MENU_ID_BGSND_CM_OPT_STATUS,get_string(STR_GLOBAL_OFF));
    				    cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_ON));
    }

    		    }
                else 
                {
                    /* Inline and effect list*/
                                cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_SELECT));
                }
            }
            break;

        case EVT_ID_CUI_MENU_LIST_EXIT:
            if (menu_evt->parent_menu_id == MENU_ID_BGSND_CM_OPT_EFFECT)
            {
               mmi_bgsnd_exit_call_manage();
            }
            break;


        case EVT_ID_SCRN_GOBACK :
             mmi_frm_scrn_close_active_id();
             break;

        case EVT_ID_GROUP_DELETE_REQ:
             break;
        case EVT_ID_GROUP_INACTIVE:
            if (mmi_frm_scrn_get_count(g_bgs_incall_gid) == 0)
            {
                mmi_frm_group_close(g_bgs_incall_gid);
            }
            break;


    	case EVT_ID_CUI_MENU_CLOSE_REQUEST:
             if (menu_evt->sender_id == bgs_menu_id1)
             {
                 mmi_frm_group_close(g_bgs_incall_gid);
             }
             else
             {
                 cui_menu_close(menu_evt->sender_id);
             }
             break;

        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            mmi_frm_group_close(g_bgs_incall_gid);
            break;


        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(g_bgs_incall_inline_gid);
            break;

        case EVT_ID_CUI_INLINE_SUBMIT:
             mmi_bgsnd_cm_setting_done();
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
                                bgsnd_cm_repeat = BGSND_REPEAT_INTERVAL;
                                kal_wsprintf(temp_interval_buf, "%d", cm_interval_buf);
                                cui_inline_set_value(g_bgs_incall_inline_gid, APP_TEXTEDIT2, (void*)temp_interval_buf);
                                cui_inline_set_item_attributes(g_bgs_incall_inline_gid, APP_TEXTEDIT2, CUI_INLINE_RESET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);

                            }
                            else
                            {
                                bgsnd_cm_repeat = (S32)notify_evt->param;
                                kal_wsprintf(temp_interval_buf, "%d", temp_value);
                                cui_inline_set_value(g_bgs_incall_inline_gid, APP_TEXTEDIT2, (void*)temp_interval_buf);
                                cui_inline_set_item_attributes(g_bgs_incall_inline_gid, APP_TEXTEDIT2, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);

                            }
                             cui_inline_redraw_screen(g_bgs_incall_inline_gid);
                        }
                        break;

                    case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
					{
						U16 play_style = 0;

                         if(notify_evt->item_id != (U32)APP_TEXTEDIT2 &&  bgsnd_cm_repeat == BGSND_REPEAT_INTERVAL)
                         {
                             cm_interval_buf = gui_atoi((UI_string_type) bgsnd_cm_interval_buf);
                         }

						 if(notify_evt->item_id == (U32)APP_TEXTEDIT2)
						 {
							 cui_inline_get_value(g_bgs_incall_inline_gid, APP_SELECT, (void *)&play_style);
							 
						 }

					}
                         break;


                    case CUI_INLINE_NOTIFY_ITEM_CHANGED:
                         cui_inline_get_value(g_bgs_incall_inline_gid, APP_TEXTEDIT2, (void *)bgsnd_cm_interval_buf);
                         break;


                    default:
                        break;
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
 *  mmi_bgsnd_exit_call_manage
 * DESCRIPTION
 *  This function is the exit function for sound effect during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_exit_call_manage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (
    #ifdef __MMI_UCM__
    	srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_DATA_CSD, NULL) > 0
    #else
        GetTotalCallCount() > 0
    #endif
    )
    {
    }
}

 /*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cm_effect_list_group_enter
 * DESCRIPTION
 *  This function is to create a separate group for effect list
 * PARAMETERS
 *  menu_event_strcut
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_bgsnd_entry_cm_effect_list_group_enter(mmi_event_struct *event)
 {
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     MMI_ID menu_id;
     cui_menu_event_struct *menu_event = (cui_menu_event_struct *)event;

  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if (menu_event->highlighted_menu_id == MENU_ID_BGSND_CM_OPT_LIST)
     {
         g_bgsnd_incall_list_gid = mmi_frm_group_create(g_bgs_incall_gid,GRP_ID_AUTO_GEN,cui_bgsound_cm_effect_list_proc, (void*)NULL);

         mmi_frm_group_enter(g_bgsnd_incall_list_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
         
         menu_id = cui_menu_create(g_bgsnd_incall_list_gid,
                                     CUI_MENU_SRC_TYPE_APPCREATE,
                                     CUI_MENU_TYPE_APPSUB,
                                     MENU_ID_BGSND_CM_OPT_LIST,
                                     MMI_FALSE,
                                     (void*)NULL);
         
         cui_menu_set_default_left_softkey(menu_id,get_string(STR_GLOBAL_SELECT));
         
         cui_menu_set_default_right_softkey(menu_id,get_string(STR_GLOBAL_BACK));
         
         cui_menu_run(menu_id);
     }
     else
     {
         MMI_ASSERT(0);
     }
 }
/*****************************************************************************
 * FUNCTION
 *  cui_bgsound_cm_effect_list_proc
 *  Proc handler 
 * PARAMETERS
 *  event_structure
 * RETURNS
 *  mmi
 *****************************************************************************/
static mmi_ret cui_bgsound_cm_effect_list_proc(mmi_event_struct *evt)
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
	{
            if (menu_evt->parent_menu_id == MENU_ID_BGSND_CM_OPT_LIST)
            {
                mmi_bgsnd_entry_cm_effect_list(menu_evt);
	    }
                break;
         }

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                 if (menu_evt->highlighted_menu_id >= MMI_BGSOUND_EFFECT1 && menu_evt->highlighted_menu_id <= MMI_BGSOUND_EFFECT20)
                {
                    mmi_bgsnd_cm_effect_apply_change();
                    mmi_frm_group_close(g_bgsnd_incall_list_gid);
                }

                break;
            }
                          
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            {
                S32 index = 0;
                if (menu_evt->highlighted_menu_id >= MMI_BGSOUND_EFFECT1 && menu_evt->highlighted_menu_id <= MMI_BGSOUND_EFFECT20 )
                {
                    index = cui_menu_get_index_in_currlist_from_menu_id(menu_evt->sender_id,menu_evt->highlighted_menu_id);
                    bgsnd_cm_highlight = index;
                    
                    if (index >=BGSND_MAX_EFFECT && index <BGSND_TOTAL_EFFECT)
                    {
                        if (!mmi_bgsnd_util_get_ext_effect_status((U16) (index - BGSND_MAX_EFFECT)))
                        {
                            cui_menu_change_left_softkey_string(menu_evt->sender_id,NULL);
			    cui_menu_change_center_softkey_content(menu_evt->sender_id,(WCHAR *)NULL,(UI_image_type)NULL);

                        }
                        #ifdef __DRM_SUPPORT__
                        mmi_bgsnd_util_ext_effect_check_forward_rule(bgsnd_cm_highlight, FALSE);
                        #endif
                    }
                    else
                    {
                        cui_menu_change_left_softkey_string(menu_evt->sender_id,get_string(STR_GLOBAL_SELECT));
			cui_menu_change_center_softkey_content(menu_evt->sender_id,(WCHAR *)NULL,(UI_image_type)GetImage(IMG_GLOBAL_COMMON_CSK));
                    }
                }
                break;
            }
        case EVT_ID_CUI_MENU_LIST_EXIT:
            {
                if (menu_evt->parent_menu_id == MENU_ID_BGSND_CM_OPT_LIST)
                {
                    mmi_bgsnd_exit_cm_effect_list();
                }
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


#define MMI_BGSND_CALL_MANAGE_STATUS
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_status_toggle
 * DESCRIPTION
 *  This function is to toggle sound effect status during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_status_toggle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UCM_SUPPORT__
    bgsnd_cm_state = MMI_TRUE;
#endif
    
    if (g_bgsnd_cntx.cm.status != 0)
    {
    #ifdef __UCM_SUPPORT__
        bgsnd_common_select = MMI_FALSE;
        mmi_bgsnd_common_cm_stop_play_sound();
    #else
        mmi_bgsnd_util_stop_play_sound_in_call();
    #endif
    }
    else
    {
        /* Check the correctness of external file content */
        if ((g_bgsnd_cntx.cm.curr_effect >= BGSND_MAX_EFFECT) && (g_bgsnd_cntx.cm.curr_effect < BGSND_TOTAL_EFFECT))
        {
            if (!mmi_bgsnd_util_check_ext_file_format((U16) (g_bgsnd_cntx.cm.curr_effect - BGSND_MAX_EFFECT)))
            {
                return;
            }
        }

    #ifdef __UCM_SUPPORT__
        /*for the common play api running correctly,now it is just  a flag*/
        bgsnd_common_hilight = 1;
        
        bgsnd_common_select = MMI_TRUE;
        mmi_bgsnd_common_mtmo_play_sound();
    #else
        mmi_bgsnd_util_play_sound_in_call();
    #endif
    }

    RedrawCategoryFunction();

}

#define MMI_BGSND_CALL_MANAGE_SETTING



/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_setting_prepare_inline_data
 * DESCRIPTION
 *  This function is to prepare data for sound effect playback setting during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_setting_prepare_inline_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* repeat type */
    if (g_bgsnd_cntx.cm.play_type < BGSND_REPEAT_NUM)
    {
        bgsnd_cm_repeat = g_bgsnd_cntx.cm.play_type;
    }
    else
    {
        bgsnd_cm_repeat = 0;
    }

    /* Interval */
    if (g_bgsnd_cntx.cm.interval_sec <= BGSND_MAX_INTERVAL)
    {
        kal_wsprintf(bgsnd_cm_interval_buf, "%d", g_bgsnd_cntx.cm.interval_sec);
    }
    else
    {
        memset(bgsnd_cm_interval_buf, 0, 2);
    }

    /* volume */
    if (g_bgsnd_cntx.cm.volume <= BGSND_MAX_VOLUME)
    {
        kal_wsprintf(bgsnd_cm_volume_buf, "%d", g_bgsnd_cntx.cm.volume);
    }
    else
    {
        memset(bgsnd_cm_volume_buf, 0, 2);
    }

    /* Enter inline editor screen */
    mmi_bgsnd_entry_cm_setting();
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
void mmi_bgsnd_cm_setting_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    cui_inline_get_value(g_bgs_incall_inline_gid, APP_TEXTEDIT1, (void *)bgsnd_cm_volume_buf);
    cui_inline_get_value(g_bgs_incall_inline_gid, APP_TEXTEDIT2, (void *)bgsnd_cm_interval_buf);
    
    
    if(mmi_ucs2strlen((S8*)bgsnd_cm_volume_buf) == 0 ||
      ((bgsnd_cm_repeat == BGSND_REPEAT_INTERVAL)&& (mmi_ucs2strlen((S8*)bgsnd_cm_interval_buf) == 0)))
    {
         mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_EMPTY)), MMI_EVENT_FAILURE, NULL);
            
    }
    else
    {
        mmi_bgsnd_cm_setting_apply_change();
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
void mmi_bgsnd_cm_playback_highlight_hdlr(S32 index)
{
    if (index != BGSND_SETUP_INTERVAL && bgsnd_cm_repeat == BGSND_REPEAT_INTERVAL)
    {
        cm_interval_buf = gui_atoi((UI_string_type) bgsnd_cm_interval_buf);
    }
}

U16 g_bgsnd_repeat_str_id1[BGSND_REPEAT_NUM] = 
{
    STR_ID_BGSND_ONCE,
    STR_ID_BGSND_INTERVAL,
    STR_ID_BGSND_CONTINUE
};

/*Volume Caption*/
cui_inline_item_caption_struct caption1_incall = {STR_GLOBAL_VOLUME};

/* Volume*/
cui_inline_item_text_edit_struct textedit_bg_vol_incall = {0, NULL, BGSND_VOLUME_LEN, IMM_INPUT_TYPE_NUMERIC, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, NULL};

/*PLay Mode Caption*/
const cui_inline_item_caption_struct caption2_incall = {STR_ID_BGSND_PLAY_MODE_CAP};

/*Repeat type*/
const cui_inline_item_select_struct select_incall ={BGSND_REPEAT_NUM, 0, g_bgsnd_repeat_str_id1};       
 
/*Interval*/
const cui_inline_item_text_edit_struct textedit_bg_interval_incall = {0, NULL, BGSND_INTERVAL_LEN, IMM_INPUT_TYPE_NUMERIC, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, NULL};


const cui_inline_set_item_struct bgsnd_inline_in_call[] = 
{
    /*Volume Caption*/
    {APP_CAPTION1,      CUI_INLINE_ITEM_TYPE_CAPTION  , 0, (void *)&caption1_incall},
    
    /* Volume*/
    {APP_TEXTEDIT1,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void *)&textedit_bg_vol_incall},

    /*PLay Mode*/
    {APP_CAPTION2,      CUI_INLINE_ITEM_TYPE_CAPTION  , 0, (void *)&caption2_incall},

    /*Repeat type*/
    {APP_SELECT,        CUI_INLINE_ITEM_TYPE_SELECT,  0, &select_incall},
     
    /*Interval*/
    {APP_TEXTEDIT2,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void *)&textedit_bg_interval_incall},

   
};

const cui_inline_struct g_initial_data1 = 
{
    5,
    STR_GLOBAL_EDIT,
    0, 
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    bgsnd_inline_in_call
};

/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cm_setting
 * DESCRIPTION
 *  This function is the entry function of sound effect playback setting during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_cm_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bgs_incall_inline_gid = cui_inline_create(g_bgs_incall_gid, &g_initial_data1);


    cui_inline_set_screen_attributes(g_bgs_incall_inline_gid, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_DEFAULT_TEXT);

	if (bgsnd_cm_repeat == BGSND_REPEAT_INTERVAL)
	{
	  cui_inline_set_item_attributes(g_bgs_incall_inline_gid, APP_TEXTEDIT2, CUI_INLINE_RESET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
	}
	else
	{
	  cui_inline_set_item_attributes(g_bgs_incall_inline_gid, APP_TEXTEDIT2, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
	  
	}

#ifndef __COSMOS_MMI_PACKAGE__
    cui_inline_set_title(g_bgs_incall_inline_gid, STR_ID_BGSND_PLAYBACK_SETUP,GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING));
#endif /* __COSMOS_MMI_PACKAGE__ */

    cui_inline_set_value(g_bgs_incall_inline_gid, APP_TEXTEDIT2, (void*)bgsnd_cm_interval_buf);
    cui_inline_set_value(g_bgs_incall_inline_gid, APP_TEXTEDIT1,(void*)bgsnd_cm_volume_buf);
    cui_inline_set_value(g_bgs_incall_inline_gid, APP_SELECT,(void*) bgsnd_cm_repeat);


    cui_inline_run(g_bgs_incall_inline_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_exit_cm_setting
 * DESCRIPTION
 *  This function is the exit function of sound effect playback setting during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_exit_cm_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (
    #ifdef __MMI_UCM__
    	srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_DATA_CSD, NULL) > 0
    #else
        GetTotalCallCount() > 0
    #endif
    )
    {
       
    }
    else
    {
        
        /* Also delete previous screen if not in GSM call */
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_setting_repeat_hdlr
 * DESCRIPTION
 *  This function is the repeat inline selection for playback setting during call
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_setting_repeat_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == BGSND_REPEAT_INTERVAL)
    {
        gui_itoa(cm_interval_buf, (U16*) wgui_inline_items[BGSND_SETUP_INTERVAL].text_p, 10);
        EnableInlineItem(&wgui_inline_items[BGSND_SETUP_INTERVAL], BGSND_SETUP_INTERVAL);
        show_fixed_list_specified_item(BGSND_SETUP_INTERVAL);
    }
    else
    {
        kal_wsprintf(bgsnd_cm_interval_buf, "%d", 0);
        show_fixed_list_specified_item(BGSND_SETUP_INTERVAL);
        DisableInlineItem(&wgui_inline_items[BGSND_SETUP_INTERVAL], BGSND_SETUP_INTERVAL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_setting_fill_inline_item
 * DESCRIPTION
 *  This function is to fill the inline item of sound effect playback setting during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_setting_fill_inline_item(void)
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
    //SetInlineItemCaption(&(wgui_inline_items[BGSND_SETUP_VOLUME_CAP]), (U8*) GetString(STR_ID_BGSND_VOLUME_CAP));
//#endif 

   /*-- Volume --*/
    SetInlineItemActivation(&wgui_inline_items[BGSND_SETUP_VOLUME], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[BGSND_SETUP_VOLUME],
        (U8*) bgsnd_cm_volume_buf,
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
        &bgsnd_cm_repeat);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[BGSND_SETUP_REPEAT], mmi_bgsnd_cm_setting_repeat_hdlr);

   /*-- Interval --*/
    SetInlineItemActivation(&wgui_inline_items[BGSND_SETUP_INTERVAL], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[BGSND_SETUP_INTERVAL],
        (U8*) bgsnd_cm_interval_buf,
        BGSND_INTERVAL_LEN,
        IMM_INPUT_TYPE_NUMERIC);
    DisableInlineItemHighlight(&wgui_inline_items[BGSND_SETUP_INTERVAL]);

    if (bgsnd_cm_repeat != BGSND_REPEAT_INTERVAL)   /* not Days */
    {
        DisableInlineItem(&wgui_inline_items[BGSND_SETUP_INTERVAL], BGSND_SETUP_INTERVAL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_setting_apply_change
 * DESCRIPTION
 *  This function is to apply the change right away for the playback setting during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_setting_apply_change(void)
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
    
    cui_inline_get_value(g_bgs_incall_inline_gid, APP_SELECT, (void *)&(bgsnd_cm_repeat));
    /* check volume */

    mmi_ucs2_to_asc(ascii_volume, (S8*) bgsnd_cm_volume_buf);
    volume_value = atoi(ascii_volume);

    if ((volume_value > BGSND_MAX_VOLUME) || (volume_value == 0))
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_BGSND_INVALID_VOLUME)), MMI_EVENT_FAILURE, NULL);
            

       
        return;
    }

    /* check interval */
    if (bgsnd_cm_repeat == BGSND_REPEAT_INTERVAL)
    {
        mmi_ucs2_to_asc(ascii_interval, (S8*) bgsnd_cm_interval_buf);
        interval_value = (U16) atoi(ascii_interval);

        if ((interval_value < BGSND_MIN_INTERVAL) || (interval_value > BGSND_MAX_INTERVAL))
        {
             mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_BGSND_INVALID_INTERVAL)), MMI_EVENT_FAILURE, NULL);
           
            return;
        }
    }
	else
	{
	  cm_interval_buf  = 0;
	}

    /* Assign vaule and save */
    g_bgsnd_cntx.cm.play_type = (U8) bgsnd_cm_repeat;
    g_bgsnd_cntx.cm.interval_sec = interval_value;
    g_bgsnd_cntx.cm.volume = (U8) volume_value;

#ifdef __UCM_SUPPORT__
    bgsnd_cm_state = MMI_TRUE;
#endif

    /* Apply change and play */
    if (g_bgsnd_cntx.cm.status)
    {
    #ifndef __UCM_SUPPORT__
        mmi_bgsnd_util_stop_play_sound_in_call();
        mmi_bgsnd_util_play_sound_in_call();
    #else
        /*for the common play api running correctly,now it is just  a flag*/
        bgsnd_common_hilight = 1;
    
        mmi_bgsnd_common_cm_stop_play_sound();
        mmi_bgsnd_common_mtmo_play_sound();
    #endif
    }

     mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_EVENT_SUCCESS, NULL);


   cui_inline_close(g_bgs_incall_inline_gid);


}

#define MMI_BGSND_CALL_MANAGE_EFFECT_LIST




/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_effect_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler of sound effect list during call
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_effect_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
#ifdef __DRM_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
}


#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_tap_callback
 * DESCRIPTION
 *  This function is the tap callback for call setup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM || tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_bgsnd_cm_effect_apply_change();
    }

    /*if (wgui_category_if_pop_option_menu())
        mmi_bgsnd_cm_effect_apply_change();
    */
    
    return;
}
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cm_effect_list
 * DESCRIPTION
 *  This function is the entry function of sound effect list during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_cm_effect_list(cui_menu_event_struct *menu_evt)
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
     if (menu_evt->parent_menu_id == MENU_ID_BGSND_CM_OPT_LIST)
     {
         
         mmi_bgsnd_util_prepare_effect_list(FALSE);
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
     
         bgsnd_cm_highlight = g_bgsnd_cntx.cm.curr_effect;

         cui_menu_set_currlist_highlighted_id(menu_evt->sender_id,root_ids[bgsnd_cm_highlight]);
     }
     else
    {
         MMI_ASSERT(0);
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_exit_cm_effect_list
 * DESCRIPTION
 *  This function is the exit function of sound effect list during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_exit_cm_effect_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (
    #ifdef __MMI_UCM__
         srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_DATA_CSD, NULL) > 0
    #else
        GetTotalCallCount() > 0
    #endif
    )
    {
      
    }
    else
    {
        /* Also delete previous screen if not in GSM call */
      
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_effect_apply_change
 * DESCRIPTION
 *  This function is to apply the change right away for sound effect list during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_effect_apply_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check the correctness of external file content */
    if ((bgsnd_cm_highlight >= BGSND_MAX_EFFECT) && (bgsnd_cm_highlight < BGSND_TOTAL_EFFECT))
    {
        if (!mmi_bgsnd_util_check_ext_file_format((U16) (bgsnd_cm_highlight - BGSND_MAX_EFFECT)))
        {
            bgsnd_cm_highlight = g_bgsnd_cntx.cm.curr_effect;
            return;
        }
    }

    /* Check file OK, begin to assign and playback */
    g_bgsnd_cntx.cm.curr_effect = (U8) bgsnd_cm_highlight;

#ifdef __UCM_SUPPORT__
    bgsnd_cm_state = MMI_TRUE;
#endif

    mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, NULL);

    


    /* Play new music */
    if (g_bgsnd_cntx.cm.status)
    {
    #ifndef __UCM_SUPPORT__
        mmi_bgsnd_util_stop_play_sound_in_call();
        mmi_bgsnd_util_play_sound_in_call();
    #else
        /*for the common play api running correctly,now it is just  a flag*/
        bgsnd_common_hilight = 1;
    
        mmi_bgsnd_common_cm_stop_play_sound();
        mmi_bgsnd_common_mtmo_play_sound();
    #endif
    }
}

#define MMI_BGSND_CALLING_UTIL


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_sound
 * DESCRIPTION
 *  This function is to play sound effect
 * PARAMETERS
 *  highlight_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_sound(U16 highlight_index)
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
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BGSND_UTIL_PLAY_SOUND, highlight_index);

    /* Prevent other APP call it repeatly*/
    if (!mdi_audio_snd_is_idle())
        return;
        

    if (highlight_index < BGSND_MAX_EFFECT)
    {
        mmi_bgsnd_util_play_by_highlight_index_in_call(highlight_index);
    }
    /* external file */
    else if (highlight_index >= BGSND_MAX_EFFECT && highlight_index < BGSND_TOTAL_EFFECT)
    {
        index = highlight_index - BGSND_MAX_EFFECT + 1;
        ReadRecord(NVRAM_EF_BGSND_FILEPATH_LID, index, (void*)read_buff, NVRAM_EF_BGSND_FILEPATH_SIZE, &pError);

        if (!(read_buff[0] == '\0' && read_buff[1] == '\0'))
        {
            mmi_bgsnd_util_play_file_in_call((U16*) read_buff);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_in_call_callback
 * DESCRIPTION
 *  This function is the callback function when play backgrund sound during call
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_in_call_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 play_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BGSND_UTIL_PLAY_IN_CALL_CALLBACK, result);

#ifdef __DRM_SUPPORT__
    if ((result == MDI_AUDIO_DRM_TIMEOUT) || (result == MDI_AUDIO_DRM_PROHIBIT))
    {
        mdi_audio_drm_disable_consume_all();
    }
    else
#endif
    {
        mmi_bgsnd_util_calling_change_state(FALSE);
    }

    /* Play finish */
    if (result == MDI_AUDIO_END_OF_FILE || result == MDI_AUDIO_DRM_PROHIBIT)
    {
        /* Play again after an interval */
        if (g_bgsnd_cntx.cm.play_type == BGSND_REPEAT_INTERVAL && g_bgsnd_cntx.cm.interval_sec > 0)
        {
            play_time = g_bgsnd_cntx.cm.interval_sec * 1000;
        #ifndef __UCM_SUPPORT__
            StartTimer(BGSND_INTERVAL_TIMER, play_time, mmi_bgsnd_util_play_sound_in_call);
        #else
            StartTimer(BGSND_INTERVAL_TIMER, play_time, mmi_bgsnd_common_mtmo_play_sound);
        #endif
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_by_highlight_index_in_call
 * DESCRIPTION
 *  This function is to play sound string data according to the highlight during call
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_by_highlight_index_in_call(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 repeat = 1; /* Play once */
    U8 audio_type;
    U32 audio_len;
    U8 *audio_data;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bgsnd_cntx.cm.play_type == BGSND_REPEAT_CONTINUE)
    {
        repeat = 0; /* Play infinite */
    }

    audio_data = get_audio((U16) (AUD_ID_BGSND_EFFECT1 + index), &audio_type, &audio_len);

    if (audio_data != NULL)
    {
        result = mdi_audio_snd_play_string_with_vol_path_type(
                    (void*)audio_data,
                    audio_len,
                    repeat,
                    audio_type,
                    mmi_bgsnd_util_play_in_call_callback,
                    NULL,
                    g_bgsnd_cntx.cm.volume - 1,
                    MDI_DEVICE_SPEAKER2);

        if (result == MDI_AUDIO_SUCCESS)
        {
            mmi_bgsnd_util_calling_change_state(TRUE);
        }
        else
        {
            mmi_bgsnd_util_calling_change_state(FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_file_in_call
 * DESCRIPTION
 *  This function is to play sound file during call
 * PARAMETERS
 *  full_path       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_file_in_call(U16 *full_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 repeat = 1; /* Play once */
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bgsnd_cntx.cm.play_type == BGSND_REPEAT_CONTINUE)
    {
        repeat = 0; /* Play infinite */
    }

    result = mdi_audio_snd_play_file_with_vol_path(
                (void*)full_path,
                repeat,
                mmi_bgsnd_util_play_in_call_callback,
                NULL,
                g_bgsnd_cntx.cm.volume - 1,
                MDI_DEVICE_SPEAKER2);

    if (result == MDI_AUDIO_SUCCESS)
    {
        mmi_bgsnd_util_calling_change_state(TRUE);
    }
    else
    {
        mmi_bgsnd_util_calling_change_state(FALSE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_stop_play_sound
 * DESCRIPTION
 *  This function is to stop play sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_stop_play_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BGSND_UTIL_STOP_PLAY_SOUND, g_bgsnd_cntx.cm.status);

    mmi_bgsnd_common_cm_stop_play_sound();

#ifdef __UCM_SUPPORT__
    mmi_bgsnd_util_delete_cm_setting_screen();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_delete_cm_setting_screen
 * DESCRIPTION
 *  This function is to delete the setting screen during call when need.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_delete_cm_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    mmi_frm_group_close(g_bgs_incall_gid);
    /* DeleteScreenIfPresent(SCR_ID_BGSND_CALL_MANAGE);
    DeleteScreenIfPresent(SCR_ID_BGSND_CM_SETTING);
    DeleteScreenIfPresent(SCR_ID_BGSND_CM_EFFECT);
    */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_delete_end_call_screen
 * DESCRIPTION
 *  This function is to stop play sound effect when call finish
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_delete_end_call_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BGSND_UTIL_DELETE_END_CALL_SCREEN);
#ifdef __UCM_SUPPORT__
    bgsnd_common_select = MMI_FALSE;
    bgsnd_common_default = MMI_FALSE;
    
    /*call management has not to change setting*/
    bgsnd_cm_state = MMI_FALSE;
    mmi_bgsnd_util_stop_play_sound();
#else
    mmi_bgsnd_util_delete_cm_setting_screen();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_check_ext_file_format
 * DESCRIPTION
 *  This function is to check if the external file valid for playing.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bgsnd_util_check_ext_file_format(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    U16 str_id = 0;
    S16 pError;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* File not exists */
    if (!mmi_bgsnd_util_get_ext_effect_status(index))
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_BGSND_NO_EFFECT)), MMI_EVENT_FAILURE, NULL);

        mmi_frm_scrn_close_active_id();

        return FALSE;
    }
    else    /* File exists, check its format */
    {
        if (mmi_bgsnd_check_usb_mode())
        {
            return FALSE;
        }
    #ifdef __DRM_SUPPORT__
        if (!g_bgsnd_cntx.drm_permission_state)
        {
            mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DRM_PROHIBITED)), MMI_EVENT_FAILURE, NULL);
            mmi_frm_scrn_close_active_id();
            return FALSE;
        }
        else
    #endif
        {
        ReadRecord(
            NVRAM_EF_BGSND_FILEPATH_LID,
            (U16) (index + 1),
            (void*)read_buff,
            NVRAM_EF_BGSND_FILEPATH_SIZE,
            &pError);
        result = mdi_audio_snd_check_file_format((void*)read_buff);
        }
    }

    /* Check file success */
    if (result == MDI_AUDIO_SUCCESS)
    {
        return TRUE;
    }
    else if (result == MDI_AUDIO_OPEN_FILE_FAIL)
    {
        str_id = STR_ID_BGSND_OPEN_FILE_FAIL;
    }
    else if (result == MDI_AUDIO_BAD_FORMAT)
    {
        str_id = STR_ID_BGSND_INVALID_FILE;
    }
    else if (result == MDI_AUDIO_DRM_PROHIBIT)/*this is useful for time exhausted */
    {
        str_id = STR_GLOBAL_DRM_PROHIBITED;   	
    }
    else
    {
        str_id = STR_ID_BGSND_PLAY_FAIL;
    }

    mmi_popup_display((WCHAR*)((UI_string_type) GetString(str_id)), MMI_EVENT_FAILURE, NULL);

    mmi_frm_scrn_close_active_id();
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_calling_change_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_on       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_calling_change_state(BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    U16 str_id = STR_GLOBAL_OFF;
    U16 lsk_id = STR_GLOBAL_ON;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BGSND_UTIL_CALLING_CHANGE_STATE, is_on);
    if (is_on)
    {
        wgui_status_icon_bar_show_icon(STATUS_ICON_BG_SOUND);
        g_bgsnd_cntx.cm.status = 1;

        str_id = STR_GLOBAL_ON;
        lsk_id = STR_GLOBAL_OFF;
    }
    else
    {
        wgui_status_icon_bar_hide_icon(STATUS_ICON_BG_SOUND);
        g_bgsnd_cntx.cm.status = 0;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BGSND_UTIL_CM_STATUS, g_bgsnd_cntx.cm.status);
    /* Chage play state if in the setting menu */
    if (GetActiveScreenId() == SCR_ID_BGSND_CALL_MANAGE)
    {
        index = GetIndexOfStringId(MENU_ID_BGSND_CALL_SETUP, STR_ID_BGSND_STATUS);
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(str_id));
        Category52ChangeItemDescription(index, (U8*) GetString(str_id));

        if(index == GetHighlightedItem())
        {
            ChangeLeftSoftkey(lsk_id, 0);
            RedrawCategoryFunction();
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_calling_sd_plug_out_hdlr
 * DESCRIPTION
 *  handle CARD plug-out event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_calling_sd_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Playing during the call */
    if ((g_bgsnd_cntx.cm.status == 1) && (g_bgsnd_cntx.cm.curr_effect >= BGSND_MAX_EFFECT))
    {
    #ifndef __UCM_SUPPORT__
        mmi_bgsnd_util_stop_play_sound_in_call();
    #else
        mmi_bgsnd_util_stop_play_sound();
    #endif
    }
}

#ifndef __UCM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_switch_speech
 * DESCRIPTION
 *  Turn on/off background according to speech mode.
 * PARAMETERS
 *  speech_on       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_switch_speech(MMI_BOOL speech_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BGSND_UTIL_SWITCH_SPEECH, speech_on, g_bgsnd_cntx.is_request_play);

    if (speech_on)
    {
        g_bgsnd_cntx.is_speech_on = MMI_TRUE;

        if (g_bgsnd_cntx.is_request_play)
        {
            if ((!CheckValidEmergencyNo1(bgsnd_call_buffer)) && (!is_emergency_call))
            {
                mmi_bgsnd_util_play_sound(g_bgsnd_cntx.cm.curr_effect);
            }
            else
            {
                memset(bgsnd_call_buffer, 0, sizeof(bgsnd_call_buffer));
                is_emergency_call = FALSE;
            }
        }
    }
    else
    {
        is_emergency_call = FALSE;
        g_bgsnd_cntx.is_speech_on = MMI_FALSE;
        mmi_bgsnd_util_stop_play_sound();
    }
}
#endif /* __UCM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_cm_stop_play_sound
 * DESCRIPTION
 *  This function is to stop play sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_common_cm_stop_play_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BGSND_COMMON_CM_STOP_PLAY_SOUND);
    StopTimer(BGSND_INTERVAL_TIMER);

    if (g_bgsnd_cntx.cm.status)
    {
        mdi_audio_snd_stop();

        /* Hide Title Indication Icon */
        wgui_status_icon_bar_hide_icon(STATUS_ICON_BG_SOUND);
        g_bgsnd_cntx.cm.status = 0;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BGSND_UTIL_CM_STATUS, g_bgsnd_cntx.cm.status);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_set_open_bgs_permit_state
 * DESCRIPTION
 *  This function is to set the background sound control state and default value
 *  before the first call (include MO and MT).
 * PARAMETERS
 *  void  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_common_set_open_bgs_permit_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get default play type for in call usage, if this function is invoked, it must be the first call */
    g_bgsnd_cntx.cm.play_type = g_bgsnd_cntx.set.play_type;
    g_bgsnd_cntx.cm.interval_sec = g_bgsnd_cntx.set.interval_sec;
    g_bgsnd_cntx.cm.volume = g_bgsnd_cntx.set.volume;
    
    g_bgsnd_cntx.cm.curr_effect = g_bgsnd_cntx.set.curr_effect;


    g_bgsnd_cntx.cm.status = 0;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BGSND_UTIL_CM_STATUS, g_bgsnd_cntx.cm.status);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_get_mtmo_bgs_curr_effect
 * DESCRIPTION
 *  This function is to get default selected effect index.
 * PARAMETERS
 *  void  [IN]
 * RETURNS
 *  U8
 *  Return default selected effect index.
 *****************************************************************************/
U8 mmi_bgsnd_common_get_mtmo_bgs_curr_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*provide the default selected effect in the first call*/
    if (g_bgsnd_cntx.set.curr_effect < BGSND_TOTAL_EFFECT)
    {
        return g_bgsnd_cntx.set.curr_effect + 1;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_mtmo_set_highlight_index
 * DESCRIPTION
 *  This function notifies the background sound which sound effect is selected to be played.
 * PARAMETERS
 *  U16  [IN]
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_bgsnd_common_mtmo_set_highlight_index(U16 highlight_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (highlight_index > BGSND_TOTAL_EFFECT)
    {
        return FALSE;
    }
    else
    {
        bgsnd_common_hilight = highlight_index;
        
        /*call management has not to change setting*/
        bgsnd_cm_state = MMI_FALSE;

        //mmi_bgsnd_common_set_open_bgs_permit_state();
        //bgsnd_common_default = MMI_TRUE;
    #ifdef __DRM_SUPPORT__
        mmi_bgsnd_util_ext_effect_check_forward_rule(bgsnd_common_hilight, TRUE);
    #endif
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_prepare_effect_list
 * DESCRIPTION
 *  This function is to prepare the effect list. (Including default and external)
 * PARAMETERS
 *  PS8       [IN] ==> Pointer array to store the effects names in effect list
 *  S32       [IN] ==> Numbers of pointers in array, it is 21
 *  S32       [IN] ==> The buffer size of per pointer in array, it is 41*ENCODING_LENGTH + ENCODING_LENGTH, This is MAX_SUB_MENU_SIZE
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bgsnd_common_mtmo_prepare_effect_list(PS8 subMenuListDataPtrs[], S32 numofptrs, S32 one_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 index;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];
    S8 *file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((numofptrs >= 21) && (one_buffer_size >= MAX_SUB_MENU_SIZE));
    mmi_ucs2ncpy(subMenuListDataPtrs[0], GetString(STR_ID_BGSND_NO_EFFECT), MAX_SUBMENU_CHARACTERS);

    /* default effect */
    for (index = 0; index < BGSND_MAX_EFFECT; index++)
    {
        mmi_ucs2ncpy(
            subMenuListDataPtrs[index + 1],
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
            mmi_ucs2cpy((PS8) subMenuListDataPtrs[index + BGSND_MAX_EFFECT + 1], GetString(STR_GLOBAL_EMPTY_LIST));
            mmi_bgsnd_util_set_ext_effect_status(index, FALSE);
        }
        else    /* Truncate file name */
        {
            file_name = (S8*)srv_fmgr_path_get_filename_ptr((WCHAR*)read_buff);
            mmi_ucs2ncpy(
                (S8*) subMenuListDataPtrs[index + BGSND_MAX_EFFECT + 1],
                (S8*) file_name,
                MAX_SUBMENU_CHARACTERS);
            mmi_bgsnd_util_set_ext_effect_status(index, TRUE);
        }
    }
    return BGSND_TOTAL_EFFECT + 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_mtmo_check_ext_file_format
 * DESCRIPTION
 *  This function is to check if the file format is right.
 * PARAMETERS
 *  void  [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bgsnd_common_mtmo_check_ext_file_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    mdi_result result;
    S16 pError;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_MO_CALL_MAKE_CALL, bgsnd_mo_highlight);
    MMI_ASSERT(bgsnd_common_hilight < (BGSND_TOTAL_EFFECT + 1));
    if ((bgsnd_common_hilight >= (BGSND_MAX_EFFECT + 1)) && (bgsnd_common_hilight < (BGSND_TOTAL_EFFECT + 1)))
    {
        index = bgsnd_common_hilight - BGSND_MAX_EFFECT - 1;
        /* File not exists */
        if (!mmi_bgsnd_util_get_ext_effect_status(index))
        {
            return BGSND_NO_EFFECT;//no effect
        }
        else    /* File exists, check its format */
        {
        #ifdef __USB_IN_NORMAL_MODE__
        /* check is in mass storage mode */
            if (srv_usb_is_in_mass_storage_mode())
            { 
                 return BGSND_USB_NOT_ALLOWED;
            }
        #endif /* __USB_IN_NORMAL_MODE__ */
            
        #ifdef __DRM_SUPPORT__////// it will cause error
            if (!g_bgsnd_cntx.drm_permission_state)
            {
                return BGSND_DRM_PROHIBIT;//drm prohibit
            }
            else
        #endif
            {
            ReadRecord(
                NVRAM_EF_BGSND_FILEPATH_LID,
                (U16) (index + 1),
                (void*)read_buff,
                NVRAM_EF_BGSND_FILEPATH_SIZE,
                &pError);
            result = mdi_audio_snd_check_file_format((void*)read_buff);
          }
        }

        /* Check file success */
        if (result == MDI_AUDIO_SUCCESS)
        {
            //bgsnd_common_select = MMI_TRUE;
            return BGSND_AUDIO_SUCCESS;//format is right
        }
        else if (result == MDI_AUDIO_OPEN_FILE_FAIL)
        {
            return BGSND_AUDIO_OPEN_FILE_FAIL;// open fail
        }
        else if (result == MDI_AUDIO_BAD_FORMAT)
        {
            return BGSND_AUDIO_BAD_FORMAT;//bad format
        }
        else if (result == MDI_AUDIO_DRM_PROHIBIT)
        {
            return BGSND_DRM_PROHIBIT;//this is useful for time exhausted.
        }
        else
        {
            return BGSND_PLAY_FAIL;//other fail
        }
    }
    else
    {
        //bgsnd_common_select = MMI_TRUE;
        return BGSND_AUDIO_SUCCESS;
     }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_get_uniform_popup_string_id
 * DESCRIPTION
 *  This function is used to get the corresponding string id.
 * PARAMETERS
 *  U8        error codename value
 * RETURNS
 *  U16      the corresponding string id.
 *****************************************************************************/
U16 mmi_bgsnd_common_get_uniform_popup_string_id(U8 error_index)//invoked when the call change into activing state
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error_index == BGSND_NO_EFFECT)
    {
        return STR_ID_BGSND_NO_EFFECT;
    }
    else if (error_index == BGSND_DRM_PROHIBIT)
    {
        return STR_GLOBAL_DRM_PROHIBITED;
    }
    else if (error_index == BGSND_AUDIO_OPEN_FILE_FAIL)
    {
        return STR_ID_BGSND_OPEN_FILE_FAIL;
    }
    else if (error_index == BGSND_AUDIO_BAD_FORMAT)
    {
        return STR_ID_BGSND_INVALID_FILE;
    }
    else// if(error_index == BGSND_PLAY_FAIL)
    {
        return STR_ID_BGSND_PLAY_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_mo_play_sound
 * DESCRIPTION
 *  This function is to play background sound effect when after mo call connected.
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
void mmi_bgsnd_common_mtmo_play_sound(void)//invoked when the call change into activing state
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_MO_PLAY_SOUND);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BGSND_COMMON_MTMO_PLAY_SOUND);
    if (!bgsnd_common_default)
    {
        mmi_bgsnd_common_set_open_bgs_permit_state();
        bgsnd_common_default = MMI_TRUE;
    }
    
    if (g_bgsnd_cntx.cm.status != 0)
        return;
    
    if ((bgsnd_common_hilight > 0) && bgsnd_common_select)
    {
        if (!bgsnd_cm_state)
        {
            g_bgsnd_cntx.cm.curr_effect = bgsnd_common_hilight - 1;
        }
        mmi_bgsnd_util_play_sound(g_bgsnd_cntx.cm.curr_effect);
    }
    else    /* No effect selected */
    {
        /*set the default setting value if not change the setting state during call*/
        if (!bgsnd_cm_state)
        {
            g_bgsnd_cntx.cm.curr_effect = g_bgsnd_cntx.set.curr_effect;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_mtmo_reset_state
 * DESCRIPTION
 *  This function is to reset state that if to play background sound effect when call connected.
 * PARAMETERS
 *  MMI_BOOL   allow_play
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_common_mtmo_reset_state(MMI_BOOL allow_play)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*allow_play is the flag deciding if to play BGS*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_BGSND_COMMON_MTMO_RESET_STATE, allow_play);
    if (allow_play)
    {
        bgsnd_common_select = MMI_TRUE;
    }
    else
    {
        bgsnd_common_select = MMI_FALSE;
    }
}

 mmi_ret mmi_bgsound_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  if (event->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT) /* MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT */
    {
            mmi_bgsnd_util_setup_sd_plug_out_hdlr();
			mmi_bgsnd_util_calling_sd_plug_out_hdlr();
            
           
    }    
    
    return MMI_RET_OK;
    
}





#endif /* __MMI_BG_SOUND_EFFECT__ */ /* _MMI_BGSOUNDINCALL_C */
#endif /* _MMI_BGSOUNDINCALL_C */ /* _MMI_BGSOUNDSETTING_C */

