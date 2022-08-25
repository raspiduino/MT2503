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

/*******************************************************************************
* Filename:
* ---------
*  Soundset.c
*
* Project:
* --------
*   CMCC TD WB FWT
*
* Description:
* ------------
*   Profiles app.
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_include.h"
#include "MainMenuDef.h"
#include "menucuigprot.h"
#include "FileMgrGProt.h"
#include "Filemgrsrvgprot.h"
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "CommonScreens.h"
#include "inlinecuigprot.h"
#include "fseditorcuigprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "DRM_gprot.h"
#include "bootupsrvgprot.h"
#include "custom_equipment.h"

#include "Gpiosrvgprot.h"

#include "ProfilesSrv.h"
#include "custom_srv_prof_defs.h"

#include "mmi_rp_app_profiles_def.h"
#include "Mmi_rp_srv_prof_def.h"

#include "ToneSelectorCuiGprot.h"
#include "ProfilesAppGprot.h"

#include "wgui_categories_util.h"

// TODO: Should be remove the following include statement?
#include "resource_audio.h"

#ifdef __OP01_FWPBW__

typedef enum
{
    MMI_PROF_ON,
    MMI_PROF_OFF
}mmi_prof_on_off_setting_enum;

#define MMI_PROF_ON_OFF_ITEM_NUM            (2)


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
/*
typedef enum
{
    GRP_ID_PROFILES = PROFILES_BASE + 1
}prof_group_enum;
*/

typedef enum
{
    MMI_PROF_TONE_ID_BEGIN      = AUD_ID_PROF_TONE_BEGIN + 1, 
    MMI_PROF_TONE_ID_END        = AUD_ID_PROF_TONE_END,
    MMI_PROF_TONE_ID_NUM        = MMI_PROF_TONE_ID_END - MMI_PROF_TONE_ID_BEGIN,
    MMI_PROF_RING_ID_BEGIN      = AUD_ID_PROF_RING_BEGIN + 1, 
    MMI_PROF_RING_ID_END        = AUD_ID_PROF_RING_END,
    MMI_PROF_RING_ID_NUM        = MMI_PROF_RING_ID_END - MMI_PROF_RING_ID_BEGIN,
} mmi_prof_audio_id_enum;

typedef enum
{
    SIM1_RING_TONE_CAPTION,
    SIM1_RING_TONE_ITEM,
    RING_VOL_CAPTION,
    RING_VOL_ITEM,  
    SIM1_MSG_TONE_CAPTION,
    SIM1_MSG_TONE_ITEM,
    MSG_VOL_CAPTION,
    MSG_VOL_ITEM,
    KEYPAD_TONE_CAPTION,
    KEYPAD_TONE_ITEM,
    SYSTEM_ALERT_CAPTION,
    SYSTEM_ALERT_ITEM,
    POWER_ON_OFF_TONE_CAPTION,
    POWER_ON_OFF_TONE_ITEM,

    INLINE_ITEM_END,
    PROFILE_INLINE_ITEM_NUM = INLINE_ITEM_END
} profile_app_item_enum;

typedef struct
{
    U16 ring_tone;
    U16 ring_vol;
    U16 msg_tone;
    U16 msg_vol;
    U16 keypad_tone;
    U16 system_alert;
    U16 power_on_off_tone;
} profile_setting_struct;


typedef struct
{
    profile_setting_struct cur_setting;
    U16	    item_id;
    U16     volume;
    U16     playing_audio_id;
    mmi_id  inline_gid;
    MMI_BOOL	is_playing;
} profile_mem_struct;

/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static profile_mem_struct g_prof_mem_p;
static const cui_inline_item_caption_struct prof_item_caption[PROFILE_INLINE_ITEM_NUM / 2] = 
{
    STR_ID_PROF_TDBW_INCOMING_CALL_RING,
    STR_ID_PROF_RING_VOL,
    STR_ID_PROF_TDBW_MSG_RING,
    STR_ID_PROF_MSG_VOL,
    STR_ID_PROF_TDBW_KEYPAD_TONE,
    STR_ID_PROF_TDBW_SYSTEM_TONE,
    STR_ID_PROF_POWER_ON_OFF_TONE,
};

static const cui_inline_item_display_only_struct display_null = 
{
    STR_GLOBAL_NONE
};

static const cui_inline_item_progress_bar_struct vol_item_struct = 
{
    0, MDI_MAX_VOLUME_LEVEL, 1 
};

static cui_inline_item_softkey_struct prof_inline_softkey = 
{
    {
        {STR_GLOBAL_OPTIONS, 0},
        {STR_GLOBAL_BACK, 0},
        {0, 0}
    }
};

static const cui_inline_set_item_struct prof_inline_item[] = 
{
    {CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION, 0,  (void*)&prof_item_caption[SIM1_RING_TONE_CAPTION / 2]},
    {CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_ITEM,      CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (void*)&display_null},

    {CUI_INLINE_ITEM_ID_BASE + RING_VOL_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION, 0,       (void*)&prof_item_caption[RING_VOL_CAPTION / 2]},
    {CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM,       CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,  (void*)&vol_item_struct},
 
    {CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION, 0,       (void*)&prof_item_caption[SIM1_MSG_TONE_CAPTION / 2]},
    {CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_ITEM,       CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,  (void*)&display_null},

    {CUI_INLINE_ITEM_ID_BASE + MSG_VOL_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[MSG_VOL_CAPTION / 2]},
    {CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM,        CUI_INLINE_ITEM_TYPE_PROGRESS_BAR, 0,   (void*)&vol_item_struct},

    {CUI_INLINE_ITEM_ID_BASE + KEYPAD_TONE_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[KEYPAD_TONE_CAPTION / 2]},
    {CUI_INLINE_ITEM_ID_BASE + KEYPAD_TONE_ITEM,        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},

    {CUI_INLINE_ITEM_ID_BASE + SYSTEM_ALERT_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[SYSTEM_ALERT_CAPTION / 2]},
    {CUI_INLINE_ITEM_ID_BASE + SYSTEM_ALERT_ITEM,        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},

    {CUI_INLINE_ITEM_ID_BASE + POWER_ON_OFF_TONE_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION, 0,        (void*)&prof_item_caption[POWER_ON_OFF_TONE_CAPTION / 2]},
    {CUI_INLINE_ITEM_ID_BASE + POWER_ON_OFF_TONE_ITEM,        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0,   (void*)&display_null},
};

static const cui_inline_struct prof_inline_screen = 
{
    PROFILE_INLINE_ITEM_NUM,
    NULL,
    NULL,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE, 
    &prof_inline_softkey, 
    prof_inline_item 
};

/**************************************************************
Local Functions
**************************************************************/
static mmi_ret mmi_prof_group_proc(mmi_event_struct* evt);
static void mmi_prof_entry_customize_scrn(void);
static void mmi_prof_get_cur_settings(void);
static void mmi_prof_preview_play_tone(void);
static void mmi_prof_preview_stop_tone(void);
static mmi_id mmi_prof_run_tone_selector(mmi_id parent_gid, U16 tone_filter, mmi_id str_id, mmi_id curr_audio_id);
static void mmi_prof_preview_tone_callback(mdi_result result, void *user_data);
static void mmi_prof_show_alert_status_icon(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_prof_app_mem_stop_callback
 * DESCRIPTION
 *  Entry function for main profile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_PROFILES);
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_USER_PROF, KAL_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_app_init
 * DESCRIPTION
 * app init function 
 * PARAMETERS
 *  mmi_event_struct *evt
 * RETURNS
 * mmi_ret
 *****************************************************************************/
 mmi_ret mmi_prof_app_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_register(APPLIB_MEM_AP_ID_USER_PROF,
        STR_ID_PROF_CAPTION, 
        GetRootTitleIcon(MAIN_MENU_PROFILES_MENUID),
        mmi_prof_app_mem_stop_callback);

    mmi_prof_show_alert_status_icon();

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_entry_main_screen
 * DESCRIPTION
 *  Entry function for main profile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_entry_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_TRC_ENTRY_PROFILE);
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_PROFILES, mmi_prof_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_PROFILES, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (srv_prof_get_activated_profile() == MMI_PROFILE_SILENT)
    {
        mmi_popup_display_simple((UI_string_type)GetString(STR_ID_PROF_SOUND_SET_SILENT), MMI_EVENT_FAILURE, GRP_ID_PROFILES, NULL);
        return;
    }
    
    mmi_prof_entry_customize_scrn();
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_set_inline_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_profiles_set_inline_item(mmi_id inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon_list[PROFILE_INLINE_ITEM_NUM];
    U16 i = 0;
    U16 string_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*********************SIM1_RING_TONE_ITEM*************************/
    cui_inline_set_value(inline_id, 
                             CUI_INLINE_ITEM_ID_BASE + SIM1_RING_TONE_ITEM, 
                             (void *)GetString(srv_prof_get_string_id_from_srv_audio_id((U16)g_prof_mem_p.cur_setting.ring_tone)));
    
    
    /*********************RING_VOL_ITEM*************************/
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM, (void*)g_prof_mem_p.cur_setting.ring_vol);
        
    /*********************SIM1_MSG_TONE_ITEM*************************/ 
    cui_inline_set_value(inline_id, 
                         CUI_INLINE_ITEM_ID_BASE + SIM1_MSG_TONE_ITEM, 
                         (void*)GetString(srv_prof_get_string_id_from_srv_audio_id((U16)g_prof_mem_p.cur_setting.msg_tone)));
    
    /*********************MSG_VOL_ITEM*************************/
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM, (void*)g_prof_mem_p.cur_setting.msg_vol);
  
    /*********************KEYPAD_TONE_ITEM*************************/
    if (g_prof_mem_p.cur_setting.keypad_tone == MMI_PROF_ON)
    {
        string_id = STR_GLOBAL_ON;
    }
    else
    {
        string_id = STR_GLOBAL_OFF;
    }
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + KEYPAD_TONE_ITEM, (void*)GetString(string_id));
   
    /*********************SYSTEM_ALERT_ITEM*************************/
    if (g_prof_mem_p.cur_setting.system_alert == MMI_PROF_ON)
    {
        string_id = STR_GLOBAL_ON;
    }
    else
    {
        string_id = STR_GLOBAL_OFF;
    }
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + SYSTEM_ALERT_ITEM, (void*)GetString(string_id));

    /*********************POWER_ON_OFF_TONE_ITEM*************************/
    if (g_prof_mem_p.cur_setting.power_on_off_tone == MMI_PROF_ON)
    {
        string_id = STR_GLOBAL_ON;
    }
    else
    {
        string_id = STR_GLOBAL_OFF;
    }
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + POWER_ON_OFF_TONE_ITEM, (void*)GetString(string_id));
   
    for (i = 0; i < PROFILE_INLINE_ITEM_NUM; i++)
    {
        icon_list[i] = IMG_GLOBAL_L1 + i;
        icon_list[++i] = 0;
    }

    cui_inline_set_icon_list(inline_id, &icon_list[0]);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_entry_customize_scrn
 * DESCRIPTION
 *  Entry function for personalise screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_prof_entry_customize_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_prof_get_cur_settings();

    g_prof_mem_p.is_playing = MMI_FALSE;
    
    inline_id = cui_inline_create(GRP_ID_PROFILES, &prof_inline_screen);
    if (inline_id == GRP_ID_INVALID)
        return;
    
    g_prof_mem_p.inline_gid = inline_id;
              
    cui_inline_set_item_attributes(inline_id,  
                                   CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM, 
                                   CUI_INLINE_SET_EXT_ATTRIBUTE,
                                   INLINE_PBAR_DIVIDED | INLINE_PBAR_FILL_GRADIENT);
    cui_inline_set_item_attributes(inline_id, 
                                   CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM, 
                                   CUI_INLINE_SET_EXT_ATTRIBUTE, 
                                   INLINE_PBAR_DIVIDED | INLINE_PBAR_FILL_GRADIENT);
    cui_inline_run(inline_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_get_cur_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_get_cur_settings(void)
{
    srv_prof_setting_struct settings;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    srv_prof_get_profile_values((srv_prof_internal_profile_enum)MMI_PROFILE_GENERAL, &settings);

    g_prof_mem_p.cur_setting.ring_tone= settings.mt_call_tone[0];
    g_prof_mem_p.cur_setting.ring_vol = settings.ring_vol;
    g_prof_mem_p.cur_setting.msg_tone = settings.sms_tone[0];
    g_prof_mem_p.cur_setting.msg_vol = settings.msg_vol;

    if (settings.keypad_vol == 0x40)
        g_prof_mem_p.cur_setting.keypad_tone = MMI_PROF_OFF;
    else
        g_prof_mem_p.cur_setting.keypad_tone = MMI_PROF_ON;
    
    if (settings.system_alert)
    {
        g_prof_mem_p.cur_setting.system_alert = MMI_PROF_ON;
    }
    else
    {
        g_prof_mem_p.cur_setting.system_alert = MMI_PROF_OFF;
    }

    if (settings.power_on_off_tone)
    {
        g_prof_mem_p.cur_setting.power_on_off_tone = MMI_PROF_ON;
    }
    else
    {
        g_prof_mem_p.cur_setting.power_on_off_tone = MMI_PROF_OFF;
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_save_cur_settings
 * DESCRIPTION
 *  Save settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_save_cur_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_setting_struct settings;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /*get old settings, if some old settings have not changed, save it as original*/
    srv_prof_get_profile_values((srv_prof_internal_profile_enum)MMI_PROFILE_GENERAL, &settings);

    settings.mt_call_tone[0] = g_prof_mem_p.cur_setting.ring_tone;
    settings.ring_vol = g_prof_mem_p.cur_setting.ring_vol;
    settings.sms_tone[0] = g_prof_mem_p.cur_setting.msg_tone;
    settings.msg_vol = g_prof_mem_p.cur_setting.msg_vol;

    if (g_prof_mem_p.cur_setting.keypad_tone ==  MMI_PROF_OFF)
        settings.keypad_vol = (srv_prof_volume_level)0x40;
    else
		settings.keypad_vol = (srv_prof_volume_level)0x42;

    if (g_prof_mem_p.cur_setting.system_alert == MMI_PROF_ON)
    {
        settings.system_alert = MMI_TRUE;
    }
    else
    {
        settings.system_alert = MMI_FALSE;
    }

    if (g_prof_mem_p.cur_setting.power_on_off_tone == MMI_PROF_ON)
    {
        settings.power_on_off_tone = MMI_TRUE;
    }
    else
    {
        settings.power_on_off_tone = MMI_FALSE;
    }

    srv_prof_set_profile_values((srv_prof_internal_profile_enum)MMI_PROFILE_GENERAL, &settings);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_entry_customize_option_scrn
 * DESCRIPTION
 *  Activates the Highlighted profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_entry_customize_option_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_id menu_gid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_gid = cui_menu_create(
                    GRP_ID_PROFILES, 
                    CUI_MENU_SRC_TYPE_RESOURCE, 
                    CUI_MENU_TYPE_OPTION, 
                    MENU_ID_PROF_CUSTOMIZE_OPTIONS, 
                    MMI_TRUE, 
                    NULL);
    if (menu_gid != GRP_ID_INVALID)
    {
        if (g_prof_mem_p.item_id == CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM ||
            g_prof_mem_p.item_id == CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_CHANGE, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PROF_CHANGE, MMI_FALSE);
        }

        cui_menu_run(menu_gid);
    }    

}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_option_scrn_change_hdlr
 * DESCRIPTION
 *  when click change item in options screen, this function will be run.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_option_scrn_change_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32	    item_index;
    mmi_id  menu_gid;
    U16     filter = 0;
    mmi_id str_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_prof_mem_p.item_id >= CUI_INLINE_ITEM_ID_BASE);
    item_index = g_prof_mem_p.item_id - CUI_INLINE_ITEM_ID_BASE;
    switch(item_index)
    {
        case SIM1_RING_TONE_ITEM:
        {
            str_id = STR_ID_PROF_SIM1_RING_TONE;
            CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_RING);
            mmi_prof_run_tone_selector(GRP_ID_PROFILES, filter, str_id, (U16)g_prof_mem_p.cur_setting.ring_tone);
            break;
        }    

        case SIM1_MSG_TONE_ITEM:
        {
            str_id = STR_ID_PROF_SIM1_MSG_TONE;
            CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_TONE);
            mmi_prof_run_tone_selector(GRP_ID_PROFILES, filter, str_id, (U16)g_prof_mem_p.cur_setting.msg_tone);
            break;
        }

        case KEYPAD_TONE_ITEM:
        {
            menu_gid = cui_menu_create(
                            GRP_ID_PROFILES, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_APPSUB, 
                            MENU_ID_PROF_KEYPAD_TONE, 
                            MMI_TRUE, 
                            NULL);
            if (menu_gid != GRP_ID_INVALID)
            {
                cui_menu_set_currlist_highlighted_id(menu_gid, g_prof_mem_p.cur_setting.keypad_tone+ MENU_ID_PROF_KEYPAD_TONE_ON);
                cui_menu_run(menu_gid);
            }    
            break;
        }

        case SYSTEM_ALERT_ITEM:
        {
            menu_gid = cui_menu_create(
                            GRP_ID_PROFILES, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_APPSUB, 
                            MENU_ID_PROF_SYSTEM_ALERT, 
                            MMI_TRUE, 
                            NULL);
            if (menu_gid != GRP_ID_INVALID)
            {
                cui_menu_set_currlist_highlighted_id(menu_gid, g_prof_mem_p.cur_setting.system_alert+ MENU_ID_PROF_SYSTEM_ALERT_ON);
                cui_menu_run(menu_gid);
            }    
            break;
        }
        
        case POWER_ON_OFF_TONE_ITEM:
        {
            menu_gid = cui_menu_create(
                            GRP_ID_PROFILES, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_APPSUB, 
                            MENU_ID_PROF_POWER_ONOFF, 
                            MMI_TRUE, 
                            NULL);
            if (menu_gid != GRP_ID_INVALID)
            {
                cui_menu_set_currlist_highlighted_id(menu_gid, g_prof_mem_p.cur_setting.power_on_off_tone+ MENU_ID_PROF_POWER_ONOFF_ON);
                cui_menu_run(menu_gid);
            }    
            break;
        }
        default:
            break;
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_menu_item_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_menu_item_select(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_MENU_ITEM_SELECTED, menu_evt->highlighted_menu_id);
    switch(menu_evt->highlighted_menu_id)
    {
        case MENU_ID_PROF_CHANGE:
        {
            mmi_prof_option_scrn_change_hdlr();
            break;
        }
        case MENU_ID_PROF_SAVE:            
        {
            mmi_prof_save_cur_settings();
            mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, GRP_ID_PROFILES, NULL);
            cui_inline_close(g_prof_mem_p.inline_gid);
            break;
        }
        case MENU_ID_PROF_KEYPAD_TONE_ON:
        {
            g_prof_mem_p.cur_setting.keypad_tone = MMI_PROF_ON;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        case MENU_ID_PROF_KEYPAD_TONE_OFF:
        {
            g_prof_mem_p.cur_setting.keypad_tone = MMI_PROF_OFF;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        case MENU_ID_PROF_SYSTEM_ALERT_ON:
        {
            g_prof_mem_p.cur_setting.system_alert = MMI_PROF_ON;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        case MENU_ID_PROF_SYSTEM_ALERT_OFF:
        {
            g_prof_mem_p.cur_setting.system_alert = MMI_PROF_OFF;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        case MENU_ID_PROF_POWER_ONOFF_ON:
        {
            g_prof_mem_p.cur_setting.power_on_off_tone= MMI_PROF_ON;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        case MENU_ID_PROF_POWER_ONOFF_OFF:
        {
            g_prof_mem_p.cur_setting.power_on_off_tone = MMI_PROF_OFF;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_update_tone_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_update_tone_setting(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tone_selector_evt_struct * evt_cui = (cui_tone_selector_evt_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_prof_mem_p.item_id - CUI_INLINE_ITEM_ID_BASE)
    {
        case SIM1_RING_TONE_ITEM:
        {
            g_prof_mem_p.cur_setting.ring_tone = evt_cui->selected_tone;
            break;     
        }
        case SIM1_MSG_TONE_ITEM:
        {
            g_prof_mem_p.cur_setting.msg_tone = evt_cui->selected_tone;
            break;     
        }   
        default:
            break;
        
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_progress_bar_value_change_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_progress_bar_value_change_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_index;
    U16 vol;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_index = g_prof_mem_p.item_id - CUI_INLINE_ITEM_ID_BASE;
    cui_inline_get_value(g_prof_mem_p.inline_gid, g_prof_mem_p.item_id, &vol);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_PROGRESSBAR_CHANGE, item_index, g_prof_mem_p.volume);

    if (vol == g_prof_mem_p.volume)
    {
        return;
    }
    g_prof_mem_p.volume = vol;
    
    switch(item_index)
    {
        case RING_VOL_ITEM:
        {
            g_prof_mem_p.cur_setting.ring_vol = g_prof_mem_p.volume;
            
            if (g_prof_mem_p.is_playing == MMI_FALSE)
            {
                StartTimer(TIMER_PROFILES_TONE_PLAY, 1000, mmi_prof_preview_play_tone);
            }
            
            break;
        }
        case MSG_VOL_ITEM:
        {
            g_prof_mem_p.cur_setting.msg_vol = g_prof_mem_p.volume;
            
            if (g_prof_mem_p.is_playing == MMI_FALSE)
            {
                StartTimer(TIMER_PROFILES_TONE_PLAY, 1000, mmi_prof_preview_play_tone);
            }
            break;
        }
        default:
        {
            break;
        }

    }

    if (g_prof_mem_p.is_playing == MMI_TRUE)
    {
        mdi_audio_set_volume(VOL_TYPE_MEDIA, MDI_AUD_VOL_MUTE((U8)g_prof_mem_p.volume));
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_inline_item_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_inline_item_highlight_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    item_index = g_prof_mem_p.item_id - CUI_INLINE_ITEM_ID_BASE;
    switch(item_index)
    {
        case RING_VOL_ITEM:
        case MSG_VOL_ITEM:
        {   
            cui_inline_set_softkey_text(g_prof_mem_p.inline_gid, g_prof_mem_p.item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_SAVE);
            cui_inline_get_value(g_prof_mem_p.inline_gid, g_prof_mem_p.item_id, &g_prof_mem_p.volume);
            StartTimer(TIMER_PROFILES_TONE_PLAY, 1000, mmi_prof_preview_play_tone);
        
            break;
        }
        default:
        {
            mmi_prof_preview_stop_tone();
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_prof_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_tone_selector_evt_struct * evt_cui;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt; 
            switch(menu_evt->parent_menu_id)
            {
                case MENU_ID_PROF_POWER_ONOFF:
                case MENU_ID_PROF_KEYPAD_TONE:
                case MENU_ID_PROF_SYSTEM_ALERT:
                {
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    break;
                }
                default:
                    break;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_prof_menu_item_select(evt);
            break;
        }    

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
     
        /**********************Inline CUI event*************************/
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct *)evt;
            if (inline_evt->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
            {
                if (g_prof_mem_p.item_id != inline_evt->item_id)
                {
                    mmi_prof_preview_stop_tone();
                }
                g_prof_mem_p.item_id = inline_evt->item_id;
                mmi_prof_inline_item_highlight_hdlr(evt);
            }
            else if (inline_evt->event_type == CUI_INLINE_NOTIFY_PROGRESS_BAR_VALUE_CHANGED)
            {
                mmi_prof_progress_bar_value_change_hdlr();
            }
           break;
        }
        
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*)evt;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_INLINE_SUBMIT);
                        
            if(submit_evt->item_id == CUI_INLINE_ITEM_ID_BASE + RING_VOL_ITEM ||
               submit_evt->item_id == CUI_INLINE_ITEM_ID_BASE + MSG_VOL_ITEM)
            {
                mmi_prof_save_cur_settings();
                mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, GRP_ID_PROFILES, NULL);
                cui_inline_close(g_prof_mem_p.inline_gid);
            }
            else
            {
                mmi_prof_entry_customize_option_scrn();
            }
            break;
        }        
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_submit_struct *inline_evt = (cui_event_inline_submit_struct *)evt;
            cui_inline_close(inline_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            cui_event_inline_submit_struct *inline_evt = (cui_event_inline_submit_struct *)evt;
            mmi_profiles_set_inline_item(inline_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
        {
            mmi_prof_preview_stop_tone();      
            break;
        }
        /**********************Tone selector event*************************/
        case EVT_ID_CUI_TONE_SELECTOR_CLOSE_REQUEST:
        {
            evt_cui = (cui_tone_selector_evt_struct *)evt;        
            cui_tone_selector_close(evt_cui->sender_id);
            break;
        }
        case EVT_ID_CUI_TONE_SELECTOR_RESULT:
        {
            mmi_prof_update_tone_setting(evt);
            break;
        }
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_run_tone_selector
 * DESCRIPTION
 *  run tone selector CUI
 * PARAMETERS
 *  
 * RETURNS
 *  tone selector CUI group id
 *****************************************************************************/
static mmi_id mmi_prof_run_tone_selector(mmi_id parent_gid, U16 tone_filter, mmi_id str_id, mmi_id curr_audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id ts_gid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ts_gid = cui_tone_selector_create(parent_gid)) == GRP_ID_INVALID)
        return GRP_ID_INVALID;
    
    cui_tone_selector_set_filter(ts_gid, tone_filter);
    cui_tone_selector_set_title_id(ts_gid, str_id, GetRootTitleIcon(MAIN_MENU_PROFILES_MENUID));
    cui_tone_selector_set_highlight_tone(ts_gid, curr_audio_id);
    cui_tone_selector_run(ts_gid);
    
    return ts_gid;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_preview_play_tone
 * DESCRIPTION
 *  preview tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_preview_play_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_FAIL;
    U16 audio_id;
    U16 item_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_PREVIEW_PLAY_TONE, g_prof_mem_p.volume);

    StopTimer(TIMER_PROFILES_TONE_PLAY);
    item_index = g_prof_mem_p.item_id - CUI_INLINE_ITEM_ID_BASE;
    switch(item_index)
    {
        case RING_VOL_ITEM:
        {
            audio_id = g_prof_mem_p.cur_setting.ring_tone;            
            break;
        }
        case MSG_VOL_ITEM:
        {
            audio_id = g_prof_mem_p.cur_setting.msg_tone;        
            break;
        }
        default:
            return;
    }

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) <= 0)
    {
        U8 audio_type;
        U32 audio_len;
        U8 *audio_data;
           
        audio_data = get_audio(audio_id, &audio_type, &audio_len);
		
        if (audio_data != NULL)
        {
            result = mdi_audio_play_string_with_vol_path(
                        (void*)audio_data,
                        audio_len,
                        audio_type,
                        DEVICE_AUDIO_PLAY_INFINITE,
                        mmi_prof_preview_tone_callback,
                        NULL,
                        MDI_AUD_VOL_MUTE((U8)g_prof_mem_p.volume),
                        MDI_DEVICE_SPEAKER2);
        }
        
        if (result == MDI_AUDIO_SUCCESS)
        {
            g_prof_mem_p.is_playing = MMI_TRUE;
            g_prof_mem_p.playing_audio_id = audio_id;
        }   
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_preview_stop_tone
 * DESCRIPTION
 *  stop preview tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_preview_stop_tone(void)
{
    StopTimer(TIMER_PROFILES_TONE_PLAY);
    
    if (g_prof_mem_p.is_playing)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_PREVIEW_STOP_TONE);
        mdi_audio_stop_string();
        g_prof_mem_p.is_playing = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_preview_tone_callback
 * DESCRIPTION
 *  play default tone callback
 * PARAMETERS
 *  MDI result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_preview_tone_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_PLAY_CALLBACK, result);
    if (result == MDI_AUDIO_TERMINATED)
    {
        g_prof_mem_p.is_playing = MMI_FALSE;
    }
}

/************************************************************
next function is used for other app
************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_get_profile_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR * mmi_prof_get_profile_name(mmi_prof_id_enum profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (profile_id >= MMI_PROFILE_GENERAL && profile_id <= MMI_PROFILE_OUTDOOR)
    {
        return (WCHAR*)GetString(profile_id - MMI_PROFILE_GENERAL + STR_ID_PROF_GENERAL); 
    }
    else
    {
        return NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_activate_profile
 * DESCRIPTION
 *  Activate profile
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: Successed
 *  MMI_FALSE: Failed
 *****************************************************************************/
MMI_BOOL mmi_prof_activate_profile(mmi_prof_id_enum profile_id, MMI_BOOL need_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret result = SRV_PROF_RET_SUCCESS;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (profile_id >= MMI_PROF_PROF_ID_BEGIN && profile_id <= MMI_PROF_PROF_ID_END)
    {
        result =  srv_prof_activate_profile((srv_prof_internal_profile_enum)profile_id);
        if (result == SRV_PROF_RET_SUCCESS && need_popup)
        {
            mmi_popup_display_simple((WCHAR*)GetString(profile_id - MMI_PROFILE_GENERAL + STR_ID_PROF_GENERAL_ACTIVATED), 
                                 MMI_EVENT_SUCCESS, 
                                 GRP_ID_ROOT, 
                                 NULL);
        }
	mmi_prof_show_alert_status_icon();
        return (MMI_BOOL)result;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_deactivate_silent_profile
 * DESCRIPTION
 *  Deactivate silent profile
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: Successed
 *  MMI_FALSE: Failed
 *****************************************************************************/
MMI_BOOL mmi_prof_deactivate_silent_profile(MMI_BOOL need_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret result;
    U16 profile_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_prof_deactivate_profile_by_external_module(SRV_PROF_SILENT_MODE);
    if (result != SRV_PROF_RET_SUCCESS)
        return MMI_FALSE;

    if (need_popup)
    {
        profile_id = srv_prof_get_activated_profile();
        mmi_popup_display_simple((WCHAR*)GetString(profile_id - MMI_PROFILE_GENERAL + STR_ID_PROF_GENERAL_ACTIVATED), 
                                 MMI_EVENT_SUCCESS, 
                                 GRP_ID_ROOT, 
                                 NULL);
    }
	mmi_prof_show_alert_status_icon();
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_show_alert_status_icon
 * DESCRIPTION
 *  show/switch alert status icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_prof_show_alert_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_alert_type_enum alert_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_NORMAL && !srv_bootup_is_exception_mode())
    {
        return;
    }

    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_ALERT_TYPE, (void*)&alert_type);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PROF_TRC_GET_ALERT_TYPE, alert_type);
    if (alert_type == SRV_PROF_ALERT_TYPE_SILENT)
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_SILENT);        
    }
    else
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SILENT);
    }
        
    wgui_status_icon_bar_update();
}
#endif/*#ifdef __OP01_FWPBW__*/
