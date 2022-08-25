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
 * GPSSetting.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   The GPS setting menu file
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"

#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
#include "DataAccountGProt.h"
#include "dataaccountcuigprot.h"



#include "MMIDataType.h"
#include "cbm_api.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_gps_def.h"
#include "custom_data_account.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
#include "mmi_gps_nvram_def.h"
#include "GPSSetting.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "gui_typedef.h"
#include "CommonScreensResDef.h"
#include "MMI_features.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "mmi_frm_nvram_gprot.h"
#include "wgui_categories_list.h"
#include "string.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "kal_public_api.h"
#include "stdlib.h"

#include "Mdi_gps.h"

#include "GPSResDef.h"
#include "GPSGProt.h"
#include "NwUsabSrvGprot.h"
#include "ModeSwitchSrvGprot.h"

#include "MenuCuiGprot.h"
#include "inlinecuigprot.h"

#include "GPSSettingMainScr.h"

static mmi_gps_setting_context_struct g_gps_ctx;

#ifdef __MMI_ENGINEER_MODE__
    extern void em_gps_enter_main_src(void);
#endif

static void mmi_gps_setting_save_settings(void);
static void mmi_gps_enter_setting(void);
static void mmi_gps_setting_draw_screen(void);
static void mmi_gps_setting_save_and_goback(void);
static void mmi_gps_setting_cansel_and_goback(void);

#if defined(__AGPS_USER_PLANE__)
static void mmi_gps_setting_entry_agps_setting_src(void);
static void mmi_gps_setting_save_agps_settings(void);
static MMI_BOOL mmi_gps_setting_save_agps_profile_check_dataaccount(void);
static void mmi_gps_setting_entry_agps_profile_src(void);
static void mmi_gps_setting_agps_profile_src_highlight_hdlr(S32 index);
static void mmi_gps_setting_entey_agps_profile_option_src(void);
static void mmi_gps_setting_activate_agps_profile(void);
static void mmi_gps_setting_entry_agps_profile_edit_src(void);
static void mmi_gps_setting_show_agps_profile_edit_src(void);
static void mmi_gps_edit_agps_profile_data_account(void);
static void mmi_gps_select_agps_profile_data_account_callback(U32 account_id);
static MMI_BOOL mmi_gps_setting_save_agps_profile(void);
static void mmi_gps_setting_save_agps_profile_check_dataaccount_close_grp(void);
static void mmi_gps_setting_save_settings_close_grp(void);
static void mmi_gps_setting_save_agps_settings_close_grp(void);
#endif

    /*Time sync*/
    static const cui_inline_item_caption_struct g_gps_il_time_sync_cap ={STR_ID_GPS_SETTING_TIME_SYNC};

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    static const cui_inline_item_caption_struct g_gps_il_agps_cap ={STR_ID_GPS_SETTING_AGPS};
#endif
    static const U16 g_gps_il_agps_on_off_str[] =
    {
        STR_GLOBAL_OFF,
        STR_GLOBAL_ON
    };
    static const cui_inline_item_select_struct g_gps_il_agps_select =
    {
        2, 0, (U16*)g_gps_il_agps_on_off_str
    };

    /*EM mode*/
    static const cui_inline_item_caption_struct g_gps_il_em_entry_cap ={STR_ID_GPS_SETTING_MINI_GPS};
    static const cui_inline_item_display_only_struct g_gps_il_em_entry_disp =
    {
        STR_ID_GPS_SETTING_MINI_GPS, STR_ID_GPS_SETTING_MINI_GPS
    };

#if defined(__AGPS_USER_PLANE__)
    /* AGPS Profile */
    static const cui_inline_item_caption_struct g_gps_il_sim_card1_cap ={STR_ID_GPS_SETTING_AGPS_PROFILE};
    static const cui_inline_item_display_only_struct g_gps_il_sim_card1_disp =
    {
        STR_ID_GPS, STR_ID_GPS
    };
#endif

    /*query location*/
#if defined(__ALLOW_FORBIDDEN_MY_LOCATION__)
    static const cui_inline_item_caption_struct g_gps_il_query_location_cap ={STR_ID_GPS_SETTING_AGPS_SEND_LOCATION};
#endif     /* __AGPS_CONTROL_PLANE__ */

/*****************************************************************************
 * FUNCTION
 *  InitGPSSetting
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret InitGPSSetting(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__AGPS_USER_PLANE__)
    cbm_app_info_struct info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gps_ctx.app_id = 0;
    info.app_str_id = STR_GLOBAL_DATA_ACCOUNT;
    info.app_icon_id = IMG_ID_GPS_SETTING_MENU_ICON;
    info.app_type = DTCNT_APPTYPE_GPS;
    cbm_register_app_id_with_app_info(&info,&g_gps_ctx.app_id);
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightGPSSetting
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightGPSSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_gps_enter_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_gps_enter_setting, KEY_RIGHT_ARROW, KEY_EVENT_UP);

    SetRightSoftkeyFunction((mmi_void_funcptr_type)mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler((mmi_void_funcptr_type)mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_UP);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_gps_enter_setting, KEY_EVENT_UP);
}


#if defined(__AGPS_USER_PLANE__)
/*****************************************************************************
 * FUNCTION
 *  HighlightGPSSettingAGPSProfileActivate
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightGPSSettingAGPSProfileActivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_gps_setting_activate_agps_profile, KEY_EVENT_UP);
    SetKeyHandler(mmi_gps_setting_activate_agps_profile, KEY_RIGHT_ARROW, KEY_EVENT_UP);

    SetRightSoftkeyFunction((mmi_void_funcptr_type)mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightGPSSettingAGPSProfileEdit
 * DESCRIPTION
 *  initialise GPS Setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightGPSSettingAGPSProfileEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_gps_setting_entry_agps_profile_edit_src, KEY_EVENT_UP);
    SetKeyHandler(mmi_gps_setting_entry_agps_profile_edit_src, KEY_RIGHT_ARROW, KEY_EVENT_UP);

    SetRightSoftkeyFunction((mmi_void_funcptr_type)mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

WCHAR* mmi_gps_profile_get_string(U8 sim_number)
{
    /* [AGPS on/off] - [Profile name] */
#if defined(__AGPS_USER_PLANE__)
    if (g_gps_ctx.settings.gps.agps_on_off)
    {
        mmi_ucs2cpy((CHAR*)g_gps_ctx.buffer[sim_number], (CHAR*) GetString((U16) (STR_GLOBAL_ON)));
    }
    else
    {
        mmi_ucs2cpy((CHAR*)g_gps_ctx.buffer[sim_number], (CHAR*) GetString((U16) (STR_GLOBAL_OFF)));
    }
    mmi_ucs2cat((CHAR*)g_gps_ctx.buffer[sim_number], (CHAR*)L" - ");

    mmi_ucs2cat((CHAR*)g_gps_ctx.buffer[sim_number], (CHAR*)(g_gps_ctx.agps_profile[0].name));

    return (WCHAR*)g_gps_ctx.buffer[sim_number];
#else
    return NULL;
#endif
}

WCHAR* mmi_gps_profile_get_da_string(U8 sim_number)
{
    /* [AGPS on/off] - [Profile name] */
#if defined(__AGPS_USER_PLANE__)
    mmi_ucs2cpy((CHAR*)g_gps_ctx.buffer[sim_number], (CHAR*)(g_gps_ctx.agps_profile[0].name));
    return (WCHAR*)g_gps_ctx.buffer[sim_number];
#else
    return NULL;
#endif
}



/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_save_and_goback
* DESCRIPTION
*  save GPS setting and (mmi_void_funcptr_type)mmi_frm_scrn_close_active_id
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_save_settings_close_grp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_gps_setting_save_settings();
    cui_inline_close(g_gps_ctx.inline_gid);
}


#if defined(__AGPS_USER_PLANE__)
/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_save_agps_settings_close_grp
* DESCRIPTION
*  save GPS setting and (mmi_void_funcptr_type)mmi_frm_scrn_close_active_id
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_save_agps_settings_close_grp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_gps_setting_save_agps_settings();
    cui_inline_close(g_gps_ctx.inline_agps_setting_gid);
}
#endif

static void _mmi_gps_setting_generate_em_item(MMI_BOOL gen)
{
    if (gen == MMI_FALSE)
    {
        cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_EM_ENTRY_CAPTION);
        cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_EM_ENTRY_DISP);
    }
    else
    {
        cui_inline_set_item_struct set_item;

        set_item.item_id = MMI_GPS_SETTING_INLINE_EM_ENTRY_CAPTION;
        set_item.item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY;
        set_item.image_id = IMG_GLOBAL_L4;
        set_item.item_data = (void*)&g_gps_il_em_entry_cap;
        cui_inline_insert_item(g_gps_ctx.inline_gid, CUI_INLINE_INSERT_TAIL, &set_item);

        set_item.item_id = MMI_GPS_SETTING_INLINE_EM_ENTRY_DISP;
        set_item.item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_CENTER_JUSTIFY;
        set_item.image_id = 0;
        set_item.item_data = (void*)&g_gps_il_em_entry_disp;
        cui_inline_insert_item(g_gps_ctx.inline_gid, CUI_INLINE_INSERT_TAIL, &set_item);
    }
}

static void _mmi_gps_setting_generate_agps_item(MMI_BOOL gen)
{
    if (gen == MMI_FALSE)
    {
        #if defined(__AGPS_USER_PLANE__)
            cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_SIM1_CAPTION);
            cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_SIM1_DISP);
        #endif

        #if defined(__ALLOW_FORBIDDEN_MY_LOCATION__)
            cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_AGPS_INLINE_QUERY_LOC_CAPTION);
            cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_AGPS_INLINE_QUERY_LOC_SELECT);
        #endif
    }
    else
    {
        #if defined(__AGPS_USER_PLANE__) || defined(__ALLOW_FORBIDDEN_MY_LOCATION__)
            cui_inline_set_item_struct set_item;
        #endif

        #if defined(__AGPS_USER_PLANE__)
            set_item.item_id = MMI_GPS_SETTING_INLINE_SIM1_CAPTION;
            set_item.item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY;
            set_item.image_id = IMG_GLOBAL_L4;
            set_item.item_data = (void*)&g_gps_il_sim_card1_cap;
            cui_inline_insert_item(g_gps_ctx.inline_gid, CUI_INLINE_INSERT_TAIL, &set_item);

            set_item.item_id = MMI_GPS_SETTING_INLINE_SIM1_DISP;
            set_item.item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_CENTER_JUSTIFY;
            set_item.image_id = 0;
            set_item.item_data = (void*)&g_gps_il_sim_card1_disp;
            cui_inline_insert_item(g_gps_ctx.inline_gid, CUI_INLINE_INSERT_TAIL, &set_item);
        #endif

        #if defined(__ALLOW_FORBIDDEN_MY_LOCATION__)
            set_item.item_id = MMI_GPS_SETTING_AGPS_INLINE_QUERY_LOC_CAPTION;
            set_item.item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY;
            set_item.image_id = IMG_GLOBAL_L3;
            set_item.item_data = (void*)&g_gps_il_query_location_cap;
            cui_inline_insert_item(g_gps_ctx.inline_gid, CUI_INLINE_INSERT_TAIL, &set_item);

            set_item.item_id = MMI_GPS_SETTING_AGPS_INLINE_QUERY_LOC_SELECT;
            set_item.item_flag = CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY;
            set_item.image_id = 0;
            set_item.item_data = (void*)&g_gps_il_agps_select;
            cui_inline_insert_item(g_gps_ctx.inline_gid, CUI_INLINE_INSERT_TAIL, &set_item);

            cui_inline_set_value(g_gps_ctx.inline_gid, MMI_GPS_SETTING_AGPS_INLINE_QUERY_LOC_SELECT, (void*)g_gps_ctx.settings.gps.send_location);
        #endif
    }
}

static void _mmi_gps_setting_generate_gps_item(MMI_BOOL gen)
{
    if (gen == MMI_FALSE)
    {
        cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_TIME_SYNC_CAPTION);
        cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_TIME_SYNC_SELECT);

        #if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
            cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_AGPS_INLINE_AGPS_CAPTION);
            cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_AGPS_INLINE_AGPS_SELECT);
        #endif

        _mmi_gps_setting_generate_agps_item(MMI_FALSE);

        cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_EM_ENTRY_CAPTION);
        cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_EM_ENTRY_DISP);
    }
    else
    {
        cui_inline_set_item_struct set_item;
        MMI_BOOL is_em_on;

        set_item.item_id = MMI_GPS_SETTING_INLINE_TIME_SYNC_CAPTION;
        set_item.item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY;
        set_item.image_id = IMG_GLOBAL_L2;
        set_item.item_data = (void*)&g_gps_il_time_sync_cap;
        cui_inline_insert_item(g_gps_ctx.inline_gid, CUI_INLINE_INSERT_TAIL, &set_item);

        set_item.item_id = MMI_GPS_SETTING_INLINE_TIME_SYNC_SELECT;
        set_item.item_flag = CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY;
        set_item.image_id = 0;
        set_item.item_data = (void*)&g_gps_il_agps_select;
        cui_inline_insert_item(g_gps_ctx.inline_gid, CUI_INLINE_INSERT_TAIL, &set_item);

        cui_inline_set_value(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_TIME_SYNC_SELECT, (void*)g_gps_ctx.settings.gps.time_sync);

        #if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
            set_item.item_id = MMI_GPS_SETTING_AGPS_INLINE_AGPS_CAPTION;
            set_item.item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY;
            set_item.image_id = IMG_GLOBAL_L3;
            set_item.item_data = (void*)&g_gps_il_agps_cap;
            cui_inline_insert_item(g_gps_ctx.inline_gid, CUI_INLINE_INSERT_TAIL, &set_item);

            set_item.item_id = MMI_GPS_SETTING_AGPS_INLINE_AGPS_SELECT;
            set_item.item_flag = CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY;
            set_item.image_id = 0;
            set_item.item_data = (void*)&g_gps_il_agps_select;
            cui_inline_insert_item(g_gps_ctx.inline_gid, CUI_INLINE_INSERT_TAIL, &set_item);

            cui_inline_set_value(g_gps_ctx.inline_gid, MMI_GPS_SETTING_AGPS_INLINE_AGPS_SELECT, (void*)g_gps_ctx.settings.gps.agps_on_off);
        #endif

        is_em_on = mmi_gps_setting_get_em_on_off();

        if (is_em_on == MMI_TRUE)
        {
            /* remove it for AGPS menu */
            _mmi_gps_setting_generate_em_item(MMI_FALSE);
        }

        _mmi_gps_setting_generate_agps_item((MMI_BOOL)g_gps_ctx.settings.gps.agps_on_off);

        if (is_em_on == MMI_TRUE)
        {
            /* add EM */
            _mmi_gps_setting_generate_em_item(MMI_TRUE);
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_agps_inline_proc
* DESCRIPTION
*  agps screen process function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_gps_setting_agps_inline_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
#if defined(__AGPS_USER_PLANE__)
    {
        cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*)evt;
        if (submit_evt->item_id == MMI_GPS_SETTING_AGPS_INLINE_PROFILE_DISP)
        {
            mmi_gps_setting_entry_agps_profile_src();
        }
        else
        {
            mmi_gps_setting_save_agps_settings();
            cui_inline_close(submit_evt->sender_id);
        }
    }
        break;
    case EVT_ID_CUI_INLINE_SET_KEY:
    {
         cui_event_inline_set_key_struct *set_key_evt = (cui_event_inline_set_key_struct*)evt;
         if(set_key_evt->item_id == MMI_GPS_SETTING_AGPS_INLINE_PROFILE_DISP)
         {
             #ifdef __MMI_INLINE_SLIM__
                 SetLeftSoftkeyFunction(mmi_gps_setting_entry_agps_profile_src, KEY_EVENT_UP);
             #else
                 SetCenterSoftkeyFunction(mmi_gps_setting_entry_agps_profile_src, KEY_EVENT_UP);
             #endif
         }
         else
         {
            SetCenterSoftkeyFunction(mmi_gps_setting_save_agps_settings_close_grp, KEY_EVENT_UP);
         }
    }
         break;
#endif
    case EVT_ID_CUI_INLINE_ABORT:
    {
        cui_event_inline_abort_struct *abort_evt = (cui_event_inline_abort_struct*)evt;
        cui_inline_close(abort_evt->sender_id);
    }
        break;

    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            cui_event_inline_common_struct *active_evt = (cui_event_inline_common_struct*)evt;
            cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*)evt;
            if (active_evt->sender_id == g_gps_ctx.inline_agps_setting_gid)
            {
        #if defined(__AGPS_USER_PLANE__)
                g_gps_ctx.curr_sim = mmi_gps_setting_get_sim();
                g_gps_ctx.current_sim_p = &g_gps_ctx.settings.sim[g_gps_ctx.curr_sim];
                mmi_ucs2cpy((CHAR*)g_gps_ctx.data_account_name, (CHAR*) GetString((U16) (STR_GLOBAL_NONE)));

                g_gps_ctx.settings.sim[g_gps_ctx.curr_sim].settings.data_account = mmi_gps_setting_get_data_account(g_gps_ctx.curr_sim);
                /* encode with current cbm app_id */
                g_gps_ctx.settings.sim[g_gps_ctx.curr_sim].settings.data_account = cbm_encode_data_account_id(g_gps_ctx.settings.sim[g_gps_ctx.curr_sim].settings.data_account, (cbm_sim_id_enum)g_gps_ctx.curr_sim, g_gps_ctx.app_id, MMI_FALSE);
                mmi_dtcnt_get_full_account_name(g_gps_ctx.settings.sim[g_gps_ctx.curr_sim].settings.data_account, (CHAR *)g_gps_ctx.data_account_name, sizeof(g_gps_ctx.data_account_name), MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
                cui_inline_set_value(g_gps_ctx.inline_agps_setting_gid, MMI_GPS_SETTING_AGPS_INLINE_PROFILE_DISP, (void*)g_gps_ctx.data_account_name);
        #endif
                cui_inline_redraw_screen(notify_evt->sender_id);
            }
        }
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_agps_inline_proc
* DESCRIPTION
*  agps screen process function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_gps_receiver_menu_inline_proc(mmi_event_struct *evt)
{
    cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*)evt;
    cui_menu_event_struct* menu_event = (cui_menu_event_struct*)evt;
    cui_event_inline_set_key_struct *set_key_evt = (cui_event_inline_set_key_struct*)evt;
    U8 m_gps_receiver;

    switch (evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_NOTIFY:
        if (notify_evt->event_type == CUI_INLINE_NOTIFY_ITEM_CHANGED)
        {
            /* GPS receiver */
            if (menu_event->highlighted_menu_id == MMI_GPS_SETTING_INLINE_GPS_SELECT)
            {
                cui_inline_get_value(notify_evt->sender_id, MMI_GPS_SETTING_INLINE_GPS_SELECT, (void *)&m_gps_receiver);
                if (m_gps_receiver == MMI_GPS_RECEIVER_OFF)
                {
                    _mmi_gps_setting_generate_gps_item(MMI_FALSE);
                }
                else
                {
                    _mmi_gps_setting_generate_gps_item(MMI_TRUE);
                }
            }
            /* AGPS */
            else if (menu_event->highlighted_menu_id == MMI_GPS_SETTING_AGPS_INLINE_AGPS_SELECT)
            {
                MMI_BOOL is_em_on;

                cui_inline_get_value(notify_evt->sender_id, MMI_GPS_SETTING_AGPS_INLINE_AGPS_SELECT, (void *)&m_gps_receiver);
                g_gps_ctx.settings.gps.agps_on_off = m_gps_receiver;

                is_em_on = mmi_gps_setting_get_em_on_off();

                if (is_em_on == MMI_TRUE)
                {
                    /* remove it for AGPS menu */
                    _mmi_gps_setting_generate_em_item(MMI_FALSE);
                }

                _mmi_gps_setting_generate_agps_item((MMI_BOOL)g_gps_ctx.settings.gps.agps_on_off);

                if (is_em_on == MMI_TRUE)
                {
                    _mmi_gps_setting_generate_em_item(MMI_TRUE);
                }
            }
            else if (menu_event->highlighted_menu_id == MMI_GPS_SETTING_INLINE_TIME_SYNC_SELECT)
            {
                cui_inline_get_value(notify_evt->sender_id, MMI_GPS_SETTING_INLINE_TIME_SYNC_SELECT, (void *)&m_gps_receiver);
                g_gps_ctx.settings.gps.time_sync = m_gps_receiver;
            }
            else if (menu_event->highlighted_menu_id == MMI_GPS_SETTING_AGPS_INLINE_QUERY_LOC_SELECT)
            {
                cui_inline_get_value(notify_evt->sender_id, MMI_GPS_SETTING_AGPS_INLINE_QUERY_LOC_SELECT, (void *)&m_gps_receiver);
                g_gps_ctx.settings.gps.send_location = m_gps_receiver;
            }
        }
        break;

    case EVT_ID_CUI_INLINE_SET_KEY:
        if (set_key_evt->sender_id == g_gps_ctx.inline_gid)
        {
        #if defined(__AGPS_USER_PLANE__)
            if(set_key_evt->item_id == MMI_GPS_SETTING_INLINE_SIM1_DISP ||
                set_key_evt->item_id == MMI_GPS_SETTING_INLINE_SIM2_DISP)
            {
                #ifdef __MMI_INLINE_SLIM__
                    SetLeftSoftkeyFunction(mmi_gps_setting_entry_agps_profile_edit_src, KEY_EVENT_UP);
                #else
                    SetCenterSoftkeyFunction(mmi_gps_setting_entry_agps_profile_edit_src, KEY_EVENT_UP);
                #endif
            }
            else
        #endif
            SetCenterSoftkeyFunction(mmi_gps_setting_save_settings_close_grp, KEY_EVENT_UP);
            //SetCenterSoftkeyFunction(mmi_gps_setting_save_settings_close_grp, KEY_EVENT_UP);
        }
        if (set_key_evt->item_id == MMI_GPS_SETTING_INLINE_EM_ENTRY_DISP)
        {
            #ifdef __MMI_ENGINEER_MODE__
                #ifdef __MMI_INLINE_SLIM__
                    SetLeftSoftkeyFunction(em_gps_enter_main_src, KEY_EVENT_UP);
                #else
                    SetCenterSoftkeyFunction(em_gps_enter_main_src, KEY_EVENT_UP);
                #endif
            #endif
        }
        break;

    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        #if defined(__AGPS_USER_PLANE__)
        {
            cui_event_inline_common_struct *active_evt = (cui_event_inline_common_struct*)evt;

            if (active_evt->sender_id == g_gps_ctx.inline_gid)
            {
                //mmi_gps_profile_get_string(0);
                g_gps_ctx.curr_sim = mmi_gps_setting_get_sim();
                g_gps_ctx.current_sim_p = &g_gps_ctx.settings.sim[g_gps_ctx.curr_sim];
                mmi_ucs2cpy((CHAR*)g_gps_ctx.data_account_name, (CHAR*) GetString((U16) (STR_GLOBAL_NONE)));

                g_gps_ctx.settings.sim[g_gps_ctx.curr_sim].settings.data_account = mmi_gps_setting_get_data_account(g_gps_ctx.curr_sim);
                /* encode with current cbm app_id */
                g_gps_ctx.settings.sim[g_gps_ctx.curr_sim].settings.data_account = cbm_encode_data_account_id(g_gps_ctx.settings.sim[g_gps_ctx.curr_sim].settings.data_account, (cbm_sim_id_enum)g_gps_ctx.curr_sim, g_gps_ctx.app_id, MMI_FALSE);
                mmi_dtcnt_get_full_account_name(g_gps_ctx.settings.sim[g_gps_ctx.curr_sim].settings.data_account, (CHAR *)g_gps_ctx.data_account_name, sizeof(g_gps_ctx.data_account_name), MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
                cui_inline_set_value(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_SIM1_DISP, (void*)g_gps_ctx.data_account_name);
                if (MMI_FALSE == mmi_gps_setting_get_em_on_off())
                {
                    cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_EM_ENTRY_CAPTION);
                    cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_EM_ENTRY_DISP);
                }
                cui_inline_redraw_screen(notify_evt->sender_id);
            }
        }
        #endif
        break;

    case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*)evt;

            #if !defined(__MMI_INLINE_SLIM__)   // we do this by left-softkey in  __MMI_INLINE_SLIM__
                if (submit_evt->item_id == MMI_GPS_SETTING_INLINE_EM_ENTRY_DISP)
                {
                    #ifdef __MMI_ENGINEER_MODE__
                        em_gps_enter_main_src();
                    #endif
                }
                #if defined(__AGPS_USER_PLANE__)
                else if (submit_evt->item_id == MMI_GPS_SETTING_INLINE_SIM1_DISP ||
                    submit_evt->item_id == MMI_GPS_SETTING_INLINE_SIM2_DISP ||
                    submit_evt->item_id == MMI_GPS_SETTING_INLINE_SIM3_DISP ||
                    submit_evt->item_id == MMI_GPS_SETTING_INLINE_SIM4_DISP)
                {
                    g_gps_ctx.curr_sim = mmi_gps_setting_get_sim();
                    g_gps_ctx.current_sim_p = &g_gps_ctx.settings.sim[g_gps_ctx.curr_sim];
                    //mmi_gps_setting_entry_agps_setting_src();
                    mmi_gps_setting_entry_agps_profile_edit_src();
                }
                #endif
                else
            #endif
            {
                mmi_gps_setting_save_settings();
                cui_inline_close(submit_evt->sender_id);
            }
        }
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *abort_evt = (cui_event_inline_abort_struct*)evt;
            cui_inline_close(abort_evt->sender_id);
            g_gps_ctx.inline_gid = 0;
        }
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_group_proc
* DESCRIPTION
*  the proc function of gps setting menu
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_gps_setting_group_proc(mmi_event_struct *evt)
{
//    cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*)evt;
    cui_event_inline_common_struct *inline_common_evt = (cui_event_inline_common_struct*)evt;
    #if defined(__AGPS_USER_PLANE__)
        cui_menu_event_struct* menu_event = (cui_menu_event_struct*)evt;
        cui_dtcnt_select_event_any_sim_selected_struct* dt_event = (cui_dtcnt_select_event_any_sim_selected_struct*)evt;
    #endif

    if (inline_common_evt->sender_id == g_gps_ctx.inline_gid)
    {
        mmi_gps_receiver_menu_inline_proc(evt);
        return MMI_RET_OK;
    }
    if (inline_common_evt->sender_id == g_gps_ctx.inline_agps_setting_gid)
    {
        mmi_gps_setting_agps_inline_proc(evt);
        return MMI_RET_OK;
    }

    /* check temp data account again when SCREEN ACTIVE */
    if (inline_common_evt->sender_id == g_gps_ctx.inline_profile_gid &&
        evt->evt_id == EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE)
    {
        #if defined(__AGPS_USER_PLANE__)
            if (mmi_dtcnt_acct_is_valid(g_gps_ctx.data_account_temp) == MMI_DTCNT_ACCT_VALID_NONE)
            {
                /* not valid(maybe deleted or ooxx...), so encode with default data account */
                g_gps_ctx.data_account_temp = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, (cbm_sim_id_enum)mmi_gps_setting_get_sim(), g_gps_ctx.app_id, MMI_FALSE);
                mmi_dtcnt_get_full_account_name(g_gps_ctx.data_account_temp, (CHAR *)g_gps_ctx.data_account_name, sizeof(g_gps_ctx.data_account_name), MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);

                cui_inline_set_value(g_gps_ctx.inline_profile_gid, MMI_GPS_EDIT_PROFILE_INLINE_DA_SELECT, (void*)g_gps_ctx.data_account_name);
                cui_inline_redraw_screen(g_gps_ctx.inline_profile_gid);
            }
        #endif

        return MMI_RET_OK;
    }

    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:
        break;

    case EVT_ID_POPUP_QUIT:
        //mmi_frm_group_close(g_gps_ctx.cur_gid);
        break;

    #if defined(__AGPS_USER_PLANE__)
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        switch (menu_event->highlighted_menu_id)
        {
        case MENU_ID_GPS_AGPS_PROFILE_ACTIVATE:
            mmi_gps_setting_activate_agps_profile();
            break;
        case MENU_ID_GPS_AGPS_PROFILE_EDIT:
            mmi_gps_setting_entry_agps_profile_edit_src();
            break;
        default:
            break;
        }
        break;
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_event->sender_id);
        break;
    #endif /*defined(__AGPS_USER_PLANE__)*/

    case EVT_ID_CUI_INLINE_SET_KEY:
        {
        #if defined(__AGPS_USER_PLANE__)
            cui_event_inline_set_key_struct *set_key_evt = (cui_event_inline_set_key_struct*)evt;

            if (g_gps_ctx.is_profile_modified == MMI_TRUE && g_gps_ctx.inline_profile_gid != 0)
            {
                if(set_key_evt->item_id != MMI_GPS_EDIT_PROFILE_INLINE_PORT_TEXT)
                {
                    cui_inline_set_softkey_text(g_gps_ctx.inline_profile_gid, set_key_evt->item_id, MMI_RIGHT_SOFTKEY, STR_GLOBAL_DONE);
                    SetRightSoftkeyFunction(mmi_gps_setting_save_agps_profile_check_dataaccount_close_grp, KEY_EVENT_UP);
                }
            }
            if (set_key_evt->item_id == MMI_GPS_EDIT_PROFILE_INLINE_DA_SELECT)
            {
                SetLeftSoftkeyFunction(mmi_gps_edit_agps_profile_data_account, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(mmi_gps_edit_agps_profile_data_account, KEY_EVENT_UP);
            }
        #endif /*__AGPS_USER_PLANE__*/
        }
        break;
    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *abort_evt = (cui_event_inline_abort_struct*)evt;
            cui_inline_close(abort_evt->sender_id);
            if (g_gps_ctx.inline_profile_gid == abort_evt->sender_id)
            {
                g_gps_ctx.inline_profile_gid = 0;
            }
            break;
        }
    case EVT_ID_CUI_INLINE_SUBMIT:
    #if defined(__AGPS_USER_PLANE__)
        {
            cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*)evt;
            if (submit_evt->item_id == MMI_GPS_SETTING_INLINE_PROFILE_SELECT)
            {
                mmi_gps_setting_entry_agps_setting_src();
            }
            else if (submit_evt->item_id == MMI_GPS_SETTING_INLINE_EM_ENTRY_DISP)
            {
            #ifdef __MMI_ENGINEER_MODE__
                em_gps_enter_main_src();
            #endif
            }
            else if (submit_evt->sender_id == g_gps_ctx.inline_profile_gid)
            {
                if (mmi_dtcnt_acct_is_valid(g_gps_ctx.data_account_temp) != MMI_DTCNT_ACCT_VALID_NONE)
                {
                    MMI_BOOL ret;

                    ret = mmi_gps_setting_save_agps_profile_check_dataaccount();
                    if (ret == MMI_TRUE)
                    {
                        /* profile checked and saved, close this group */
                        cui_inline_close(submit_evt->sender_id);
                        g_gps_ctx.inline_profile_gid = 0;
                    }
                }
                else
                {
                    mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_GPS_SETTING_AGPS_PROFILE_INVALID_DATA_ACCOUNT)), MMI_EVENT_FAILURE, NULL);
                }
            }
            else
            {
                mmi_gps_setting_save_settings();
                cui_inline_close(submit_evt->sender_id);
            }
        }
    #endif /*__AGPS_USER_PLANE__*/
        break;
        /*Data account related*/
#if defined(__AGPS_USER_PLANE__)
    case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
        mmi_gps_select_agps_profile_data_account_callback(dt_event->accountId);
        break;
    case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
    case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
    case CUI_DTCNT_SELECT_EVENT_CLOSE:
        cui_dtcnt_select_close(dt_event->sender_id);
        break;
    case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
         break;
#endif
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_gis_gps_enter_setting
* DESCRIPTION
*  the enter function of setting menu
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_enter_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
        U8 i;
        U8 prefer_sim;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(g_gps_ctx.cur_gid))
    {
        mmi_frm_group_close(g_gps_ctx.cur_gid);
    }
    g_gps_ctx.cur_gid = mmi_frm_group_create (GRP_ID_ROOT,  GRP_ID_AUTO_GEN, mmi_gps_setting_group_proc, NULL);
    mmi_frm_group_enter(g_gps_ctx.cur_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_gps_setting_get_mmi_setting(&g_gps_ctx.settings.gps);

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    prefer_sim = mmi_gps_setting_get_sim();
    g_gps_ctx.current_sim_p = &g_gps_ctx.settings.sim[prefer_sim];
    for (i=0 ; i < MMI_GPS_SIM_CARD_NUMBER ; i++)
    {
        mmi_gps_setting_get_sim_setting(i, &g_gps_ctx.settings.sim[i].settings);
    }
#endif

#if defined(__AGPS_USER_PLANE__)
    for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        mmi_gps_setting_get_profile(&g_gps_ctx.agps_profile[i]);
    }
#endif

    mmi_gps_setting_draw_screen();
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_draw_screen
* DESCRIPTION
*  draw the setting screen, according to the ctx data
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_draw_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*GPS*/
    static const cui_inline_item_caption_struct g_gps_il_gps_cap ={STR_ID_GPS_SETTING_RECEIVER};
    static const U16 g_gps_il_gps_select_str[] =
        {
            STR_GLOBAL_OFF,
            STR_GLOBAL_ON
        };
    static const cui_inline_item_select_struct g_gps_il_gps_select =
    {
        MMI_GPS_SELECT_ITEM_MAX, 0, (U16*)g_gps_il_gps_select_str
    };

    static const cui_inline_set_item_struct g_mmi_gps_setting_inline_item[] =
    {
        {MMI_GPS_SETTING_INLINE_GPS_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    IMG_GLOBAL_L1,  (void*)&g_gps_il_gps_cap},
        {MMI_GPS_SETTING_INLINE_GPS_SELECT,         CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,   0,  (void*)&g_gps_il_gps_select},

        {MMI_GPS_SETTING_INLINE_TIME_SYNC_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    IMG_GLOBAL_L2,  (void*)&g_gps_il_time_sync_cap},
        {MMI_GPS_SETTING_INLINE_TIME_SYNC_SELECT,   CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,   0,  (void*)&g_gps_il_agps_select},

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
        {MMI_GPS_SETTING_AGPS_INLINE_AGPS_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    IMG_GLOBAL_L1,  (void*)&g_gps_il_agps_cap},
        {MMI_GPS_SETTING_AGPS_INLINE_AGPS_SELECT,         CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,   0,  (void*)&g_gps_il_agps_select},
#endif

#if defined(__AGPS_USER_PLANE__)
        {MMI_GPS_SETTING_INLINE_SIM1_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    IMG_GLOBAL_L4,  (void*)&g_gps_il_sim_card1_cap},
        {MMI_GPS_SETTING_INLINE_SIM1_DISP,      CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_CENTER_JUSTIFY,   0,  (void*)&g_gps_il_sim_card1_disp},
#endif

#if defined(__ALLOW_FORBIDDEN_MY_LOCATION__)
        {MMI_GPS_SETTING_AGPS_INLINE_QUERY_LOC_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    IMG_GLOBAL_L3,  (void*)&g_gps_il_query_location_cap},
        {MMI_GPS_SETTING_AGPS_INLINE_QUERY_LOC_SELECT,   CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,   0,  (void*)&g_gps_il_agps_select},
#endif /* __ALLOW_FORBIDDEN_MY_LOCATION__ */


        {MMI_GPS_SETTING_INLINE_EM_ENTRY_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    IMG_GLOBAL_L4 + MMI_GPS_SIM_CARD_NUMBER,  (void*)&g_gps_il_em_entry_cap},
        {MMI_GPS_SETTING_INLINE_EM_ENTRY_DISP,      CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_CENTER_JUSTIFY,   0,  (void*)&g_gps_il_em_entry_disp}
    };

    static const cui_inline_struct g_mmi_gps_setting_image_em_inline_screen =
    {
        2 * (3
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
        + 1 // AGPS select
#endif
#if defined(__AGPS_USER_PLANE__)
        + 1
#endif
#if defined(__ALLOW_FORBIDDEN_MY_LOCATION__)
		+ 1 // Query Loc
#endif
        ),
        STR_GLOBAL_SETTINGS,
        0,
    #ifdef __MMI_INLINE_SLIM__
        CUI_INLINE_SCREEN_DEFAULT_TEXT,
    #else
        CUI_INLINE_SCREEN_DISABLE_DONE | CUI_INLINE_SCREEN_DEFAULT_TEXT,
    #endif
        0,
        g_mmi_gps_setting_inline_item
    };

/*#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    MMI_BOOL can_use_agps = MMI_TRUE;
#endif*/

    g_gps_ctx.inline_gid = cui_inline_create(g_gps_ctx.cur_gid, &g_mmi_gps_setting_image_em_inline_screen);

    cui_inline_set_value(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_GPS_SELECT, (void*)g_gps_ctx.settings.gps.receiver);
    cui_inline_set_value(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_TIME_SYNC_SELECT, (void*)g_gps_ctx.settings.gps.time_sync);

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    g_gps_ctx.settings.gps.agps_on_off = mmi_gps_setting_get_is_agps_on();
    cui_inline_set_value(g_gps_ctx.inline_gid, MMI_GPS_SETTING_AGPS_INLINE_AGPS_SELECT, (void*)g_gps_ctx.settings.gps.agps_on_off);
#endif

#if defined(__AGPS_USER_PLANE__)
{
    U8 sim_id;

    mmi_ucs2cpy((CHAR*)g_gps_ctx.data_account_name, (CHAR*) GetString((U16) (STR_GLOBAL_NONE)));

    sim_id = mmi_gps_setting_get_sim();
    g_gps_ctx.settings.sim[sim_id].settings.data_account = mmi_gps_setting_get_data_account(sim_id);
    /* encode with current cbm app_id */
    g_gps_ctx.settings.sim[sim_id].settings.data_account = cbm_encode_data_account_id(g_gps_ctx.settings.sim[sim_id].settings.data_account, (cbm_sim_id_enum)sim_id, g_gps_ctx.app_id, MMI_FALSE);
    mmi_dtcnt_get_full_account_name(g_gps_ctx.settings.sim[sim_id].settings.data_account, (CHAR *)g_gps_ctx.data_account_name, sizeof(g_gps_ctx.data_account_name), MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
    cui_inline_set_value(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_SIM1_DISP, (void*)g_gps_ctx.data_account_name);
    cui_inline_set_softkey_text(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_SIM1_DISP, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
}
#endif

#if defined(__ALLOW_FORBIDDEN_MY_LOCATION__)
    g_gps_ctx.settings.gps.send_location = mmi_gps_setting_get_send_location();
    cui_inline_set_value(g_gps_ctx.inline_gid, MMI_GPS_SETTING_AGPS_INLINE_QUERY_LOC_SELECT, (void*)g_gps_ctx.settings.gps.send_location);
#endif

    #ifdef __MMI_INLINE_SLIM__
        cui_inline_set_softkey_text(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_EM_ENTRY_DISP, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
    #endif

    if (g_gps_ctx.settings.gps.receiver == MMI_GPS_RECEIVER_OFF)
    {
        _mmi_gps_setting_generate_gps_item(MMI_FALSE);
    }
    else
    {
        #if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
            if (g_gps_ctx.settings.gps.agps_on_off == MMI_FALSE)
            {
                _mmi_gps_setting_generate_agps_item(MMI_FALSE);
            }
        #endif

        if (MMI_FALSE == mmi_gps_setting_get_em_on_off())
        {
            cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_EM_ENTRY_CAPTION);
            cui_inline_delete_item(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_EM_ENTRY_DISP);
        }
    }

    cui_inline_set_title(g_gps_ctx.inline_gid, STR_ID_GPS_SETTING_MAIN, GetRootTitleIcon(MENU_ID_GPS_SETTING));    /* title text and icon */
    cui_inline_run(g_gps_ctx.inline_gid);
}


mmi_ret mmi_gps_setting_save_confirmCb(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_gps_setting_save_and_goback();
            break;
        case MMI_ALERT_CNFM_NO:
            // handle softkey event here
            mmi_gps_setting_cansel_and_goback();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_save_and_goback
* DESCRIPTION
*  save GPS setting and (mmi_void_funcptr_type)mmi_frm_scrn_close_active_id
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_save_and_goback(void)
{
    U16 scrn_id = 0;

    g_gps_ctx.time_sync_nvram = g_gps_ctx.time_sync_selected_item;

#if defined(__AGPS_USER_PLANE__)
    mmi_gps_setting_set_profile(&g_gps_ctx.agps_profile[0]);
#endif

    g_gps_ctx.is_modified = MMI_FALSE;
    scrn_id = mmi_frm_scrn_get_active_id();
    mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_SAVED)), MMI_EVENT_SUCCESS, NULL);
    mmi_frm_scrn_close (g_gps_ctx.cur_gid, scrn_id);

}

#if defined(__AGPS_USER_PLANE__)
/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_save_and_goback
* DESCRIPTION
*  save GPS setting and (mmi_void_funcptr_type)mmi_frm_scrn_close_active_id
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_save_agps_settings(void)
{
    mmi_gps_setting_set_sim_setting(g_gps_ctx.curr_sim, &g_gps_ctx.current_sim_p->settings);

    mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, g_gps_ctx.cur_gid, NULL);
}
#endif // #if defined(__AGPS_USER_PLANE__)

/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_save_and_goback
* DESCRIPTION
*  save GPS setting and (mmi_void_funcptr_type)mmi_frm_scrn_close_active_id
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_save_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  data = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_GPS_SELECT, (void*)&data);
    g_gps_ctx.settings.gps.receiver = data;
    //cui_inline_get_value(g_gps_ctx.inline_gid, MMI_GPS_SETTING_INLINE_TIME_SYNC_SELECT, (void*)&data);
    //g_gps_ctx.settings.gps.time_sync = data;

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    //cui_inline_get_value(g_gps_ctx.inline_gid, MMI_GPS_SETTING_AGPS_INLINE_AGPS_SELECT, (void*)&data);
    //g_gps_ctx.settings.gps.agps_on_off = data;
#endif // #if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)

#if defined(__ALLOW_FORBIDDEN_MY_LOCATION__)
    //cui_inline_get_value(g_gps_ctx.inline_gid, MMI_GPS_SETTING_AGPS_INLINE_QUERY_LOC_SELECT, (void*)&data);
    //g_gps_ctx.settings.gps.send_location = data;
    mmi_gps_setting_set_send_location(g_gps_ctx.settings.gps.send_location);
#endif

    mmi_gps_setting_set_mmi_setting(&g_gps_ctx.settings.gps);
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    mmi_gps_setting_set_sim_setting(g_gps_ctx.curr_sim, &g_gps_ctx.current_sim_p->settings);
#endif

    g_gps_ctx.is_modified = MMI_FALSE;
    mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, g_gps_ctx.cur_gid, NULL);
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_cansel_and_goback
* DESCRIPTION
*  cancel the change of setting, then go back history
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_cansel_and_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gps_ctx.is_modified = MMI_FALSE;
    mmi_frm_scrn_close_active_id();
}


#if defined(__AGPS_USER_PLANE__)
/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_entry_agps_setting_src
* DESCRIPTION
*  the receiver high light hdlr of setting sub menu
* PARAMETERS
*  index        [IN]        the item index
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_entry_agps_setting_src(void)
{
    /*GPS Profile*/
    static const cui_inline_item_caption_struct g_gps_il_profile_cap ={STR_ID_GPS_SETTING_AGPS_PROFILE};
    static const cui_inline_item_display_only_struct g_gps_il_profile_txt = {0, 0};

    static const cui_inline_set_item_struct g_mmi_gps_setting_inline_item[] =
    {
        {MMI_GPS_SETTING_AGPS_INLINE_PROFILE_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    IMG_GLOBAL_L2,  (void*)&g_gps_il_profile_cap},
        {MMI_GPS_SETTING_AGPS_INLINE_PROFILE_DISP,   CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_CENTER_JUSTIFY,   0,  (void*)&g_gps_il_profile_txt},
    };

    static const cui_inline_struct g_mmi_gps_setting_image_inline_screen =
    {
        1 * 2,
        STR_GLOBAL_SETTINGS,
        0,
    #ifdef __MMI_INLINE_SLIM__
        CUI_INLINE_SCREEN_DEFAULT_TEXT,
    #else
        CUI_INLINE_SCREEN_DISABLE_DONE | CUI_INLINE_SCREEN_DEFAULT_TEXT,
    #endif
        0,
        g_mmi_gps_setting_inline_item
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gps_ctx.inline_agps_setting_gid = cui_inline_create(g_gps_ctx.cur_gid, &g_mmi_gps_setting_image_inline_screen);
    //cui_inline_set_value(g_gps_ctx.inline_agps_setting_gid, MMI_GPS_SETTING_AGPS_INLINE_AGPS_SELECT, (void*)g_gps_ctx.current_sim_p->settings.on_off);

    mmi_gps_profile_get_da_string(g_gps_ctx.curr_sim);
    cui_inline_set_value(g_gps_ctx.inline_agps_setting_gid, MMI_GPS_SETTING_AGPS_INLINE_PROFILE_DISP, (void*)g_gps_ctx.buffer[g_gps_ctx.curr_sim]);
    cui_inline_set_softkey_text(g_gps_ctx.inline_agps_setting_gid, MMI_GPS_SETTING_AGPS_INLINE_PROFILE_DISP, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);

    cui_inline_set_title(g_gps_ctx.inline_agps_setting_gid, STR_GLOBAL_SETTINGS, GetRootTitleIcon(MENU_ID_GPS_SETTING));
    cui_inline_run(g_gps_ctx.inline_agps_setting_gid);
}

#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_tap_callback
* DESCRIPTION
*  tap callback function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_gps_setting_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ENUM_TAP_ON_HIGHLIGHTED_ITEM == tap_type)
    {
        g_gps_ctx.is_modified = MMI_TRUE;
        mmi_gps_setting_activate_agps_profile();
        //mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_ACTIVATED)), MMI_EVENT_SUCCESS, NULL);
    }
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_agps_file
* DESCRIPTION
*  cancel the change of setting, then go back history
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_entry_agps_profile_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 i;
    U8 *itemlist[NVRAM_EF_AGPS_PROFILE_TOTAL];
    U16 IndexIconsImageList[NVRAM_EF_AGPS_PROFILE_TOTAL];
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter (g_gps_ctx.cur_gid, SCR_ID_GPS_SETTING_AGPS_PROFILE, NULL, mmi_gps_setting_entry_agps_profile_src, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_gps_ctx.cur_gid, SCR_ID_GPS_SETTING_AGPS_PROFILE);

    for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        itemlist[i] = (U8*)&g_gps_ctx.agps_profile[i].name[0];
        IndexIconsImageList[i] = 0;
    }
    IndexIconsImageList[0] = IMG_STATUS;
    RegisterHighlightHandler(mmi_gps_setting_agps_profile_src_highlight_hdlr);

    EnableCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);

    ShowCategory353Screen(
        (U8*)GetString(STR_ID_GPS_SETTING_AGPS_PROFILE),
        GetRootTitleIcon(MENU_ID_GPS_SETTING),     /* title text and icon */
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,                 /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NVRAM_EF_AGPS_PROFILE_TOTAL,
        itemlist,
        (U16*) IndexIconsImageList,
        0,
        0,
        (S32) (0),
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_gps_setting_entey_agps_profile_option_src, KEY_EVENT_UP);
    SetKeyHandler(mmi_gps_setting_entey_agps_profile_option_src, KEY_RIGHT_ARROW, KEY_EVENT_UP);
#if defined(__MMI_TOUCH_SCREEN__)
    wgui_register_list_tap_callback(mmi_gps_setting_tap_callback);
#endif

    EnableCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_gps_setting_activate_agps_profile, KEY_EVENT_UP);

    SetRightSoftkeyFunction((mmi_void_funcptr_type)mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_agps_profile_src_highlight_hdlr
* DESCRIPTION
*  cancel the change of setting, then go back history
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_agps_profile_src_highlight_hdlr(S32 index)
{
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_agps_profile_src_highlight_hdlr
* DESCRIPTION
*  cancel the change of setting, then go back history
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_entey_agps_profile_option_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    g_gps_ctx.menu_agps_profile_gid = cui_menu_create(
                                            g_gps_ctx.cur_gid,
                                            CUI_MENU_SRC_TYPE_RESOURCE,
                                            CUI_MENU_TYPE_FROM_RESOURCE,
                                            MENU_ID_GPS_AGPS_PROFILE_OPTION,
                                            MMI_TRUE,
                                            NULL);
    cui_menu_set_default_title_image(g_gps_ctx.menu_agps_profile_gid,(UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_GPS_SETTING)));
    cui_menu_run(g_gps_ctx.menu_agps_profile_gid);
}


mmi_ret mmi_gps_setting_active_agps_profile_confirmCb(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_gps_setting_entry_agps_profile_edit_src();
            break;
        case MMI_ALERT_CNFM_NO:
            // handle softkey event here
            mmi_frm_scrn_close_active_id();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_activate_agps_profile
* DESCRIPTION
*  cancel the change of setting, then go back history
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_activate_agps_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_gps_nvram_single_sim_settings_struct *sim_p = g_gps_ctx.current_sim_p;
    U16 scrn_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_dtcnt_acct_is_valid(sim_p->settings.data_account) == MMI_DTCNT_ACCT_VALID_NONE)
    {
        mmi_confirm_property_struct arg;
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        arg.softkey[0].str = (WCHAR *)((UI_string_type) get_string(STR_GLOBAL_YES));
        arg.softkey[2].str = (WCHAR *)((UI_string_type) get_string(STR_GLOBAL_NO));
        arg.callback = (mmi_proc_func)mmi_gps_setting_active_agps_profile_confirmCb;
        arg.parent_id = g_gps_ctx.cur_gid;
        mmi_confirm_display((WCHAR *)((UI_string_type) get_string(STR_GLOBAL_INVALID_DATA_ACCOUNT)), MMI_EVENT_QUERY, &arg);
    }
    else
    {
        g_gps_ctx.is_modified = MMI_TRUE;
        scrn_id = mmi_frm_scrn_get_active_id();
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_ACTIVATED)), MMI_EVENT_SUCCESS, NULL);

        mmi_gps_setting_set_sim_setting(g_gps_ctx.curr_sim, &sim_p->settings);

        if(g_gps_ctx.menu_agps_profile_gid == mmi_frm_scrn_get_active_id())
        {
             mmi_frm_scrn_close (g_gps_ctx.cur_gid, scrn_id);
        }
     }
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_activate_agps_profile
* DESCRIPTION
*  cancel the change of setting, then go back history
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_entry_agps_profile_edit_src(void)
{
    mmi_gps_nvram_single_sim_settings_struct *sim_p = g_gps_ctx.current_sim_p;

    sim_p->settings.data_account = mmi_gps_setting_get_data_account(g_gps_ctx.curr_sim);
    mmi_gps_setting_get_profile(&g_gps_ctx.agps_profile[0]);

    /* use temp profile untill SAVED */
    memcpy(&g_gps_ctx.agps_profile_temp,
           &g_gps_ctx.agps_profile[0],
           sizeof(nvram_ef_agps_profile_struct));
    g_gps_ctx.data_account_temp = sim_p->settings.data_account;
    g_gps_ctx.data_account_temp = cbm_encode_data_account_id(g_gps_ctx.data_account_temp, (cbm_sim_id_enum)g_gps_ctx.curr_sim, g_gps_ctx.app_id, MMI_FALSE);

    mmi_gps_setting_show_agps_profile_edit_src();
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_activate_agps_profile
* DESCRIPTION
*  cancel the change of setting, then go back history
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_setting_show_agps_profile_edit_src(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*Profile*/
    static const cui_inline_item_caption_struct g_gps_il_profileadd_cap ={STR_GLOBAL_ADDRESS};
    static const cui_inline_item_fullscreen_edit_struct g_gps_il_profileadd_txt =
    {
        0,
        0,
        STR_GLOBAL_EDIT,
        MENU_ID_GPS_INPUT_EDITOR_OPTION,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        IMM_INPUT_TYPE_SENTENCE,
        AGPS_MAX_PROFILE_ADDR_LEN,
        NULL
    };



    static const cui_inline_item_caption_struct g_gps_il_profileda_cap ={STR_GLOBAL_DATA_ACCOUNT};
    static const cui_inline_item_display_only_struct g_gps_il_profileda_txt = {0, 0};

    static const cui_inline_item_caption_struct g_gps_il_profileport_cap ={STR_ID_GPS_SETTING_AGPS_PROFILE_PORT};
    static const cui_inline_item_text_edit_struct g_gps_il_profileport_txt =
        {
            0,
            STR_GLOBAL_EDIT,
            MMI_GPS_MAX_PORT_BUFFER_LEN,
            IMM_INPUT_TYPE_NUMERIC,
            INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
            NULL
        };

    static const cui_inline_set_item_struct g_mmi_gps_setting_inline_item4[] =
    {
        {MMI_GPS_EDIT_PROFILE_INLINE_ADDR_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    IMG_GLOBAL_L2,  (void*)&g_gps_il_profileadd_cap},
        {MMI_GPS_EDIT_PROFILE_INLINE_ADDR_TEXT,     CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT | CUI_INLINE_ITEM_CENTER_JUSTIFY,   0,  (void*)&g_gps_il_profileadd_txt},

        {MMI_GPS_EDIT_PROFILE_INLINE_PORT_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    IMG_GLOBAL_L4,  (void*)&g_gps_il_profileport_cap},
        {MMI_GPS_EDIT_PROFILE_INLINE_PORT_TEXT,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_CENTER_JUSTIFY,   0,  (void*)&g_gps_il_profileport_txt},

        {MMI_GPS_EDIT_PROFILE_INLINE_DA_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    IMG_GLOBAL_L3,  (void*)&g_gps_il_profileda_cap},
        {MMI_GPS_EDIT_PROFILE_INLINE_DA_SELECT,     CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_CENTER_JUSTIFY,   0,  (void*)&g_gps_il_profileda_txt},
    };

    static const cui_inline_struct g_mmi_gps_setting_image_inline_screen4 =
    {
        3 * 2,
        STR_GLOBAL_SETTINGS,
        0,
        CUI_INLINE_SCREEN_DEFAULT_TEXT,
        0,
        g_mmi_gps_setting_inline_item4
    };
    /*
    static const cui_inline_struct g_mmi_gps_setting_image_inline_screen2 =
    {
        2 * 2,
        STR_GLOBAL_SETTINGS,
        0,
        CUI_INLINE_SCREEN_DEFAULT_TEXT,
        0,
        g_mmi_gps_setting_inline_item2
    };*/

    cui_dtcnt_select_run_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gps_ctx.is_profile_modified = MMI_FALSE;
    /*if (MMI_TRUE == mmi_gps_setting_get_em_on_off())
    {
        g_gps_ctx.inline_profile_gid = cui_inline_create(g_gps_ctx.cur_gid, &g_mmi_gps_setting_image_inline_screen4);
    }
    else
    {
        g_gps_ctx.inline_profile_gid = cui_inline_create(g_gps_ctx.cur_gid, &g_mmi_gps_setting_image_inline_screen2);
    }*/
    g_gps_ctx.inline_profile_gid = cui_inline_create(g_gps_ctx.cur_gid, &g_mmi_gps_setting_image_inline_screen4);
    //cui_inline_set_value(g_gps_ctx.inline_profile_gid, MMI_GPS_EDIT_PROFILE_INLINE_GPS_TEXT, (void*)g_gps_ctx.agps_profile_temp.name);
    cui_inline_set_value(g_gps_ctx.inline_profile_gid, MMI_GPS_EDIT_PROFILE_INLINE_ADDR_TEXT, (void*)g_gps_ctx.agps_profile_temp.addr);
    /* [Profile name] */
#if defined(__AGPS_USER_PLANE__)
    mmi_ucs2cpy((CHAR*)g_gps_ctx.data_account_name, (CHAR*) GetString((U16) (STR_GLOBAL_NONE)));
    mmi_dtcnt_get_full_account_name(g_gps_ctx.data_account_temp, (CHAR *)g_gps_ctx.data_account_name, sizeof(g_gps_ctx.data_account_name),MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
#endif
    cui_inline_set_value(g_gps_ctx.inline_profile_gid, MMI_GPS_EDIT_PROFILE_INLINE_DA_SELECT, (void*)g_gps_ctx.data_account_name);

    if ((g_gps_ctx.curr_sim == MMI_GPS_SETTING_PREFER_SIM_NO1 && srv_nw_usab_is_usable(MMI_SIM1) == MMI_FALSE) ||
        (g_gps_ctx.curr_sim == MMI_GPS_SETTING_PREFER_SIM_NO2 && srv_nw_usab_is_usable(MMI_SIM2) == MMI_FALSE) ||
        (g_gps_ctx.curr_sim == MMI_GPS_SETTING_PREFER_SIM_NO3 && srv_nw_usab_is_usable(MMI_SIM3) == MMI_FALSE) ||
        (g_gps_ctx.curr_sim == MMI_GPS_SETTING_PREFER_SIM_NO4 && srv_nw_usab_is_usable(MMI_SIM4) == MMI_FALSE) ||
        srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        cui_inline_set_item_attributes(g_gps_ctx.inline_profile_gid, MMI_GPS_EDIT_PROFILE_INLINE_DA_SELECT, CUI_INLINE_SET_ATTRIBUTE,CUI_INLINE_ITEM_DISABLE);
    }

    kal_wsprintf((WCHAR *)g_gps_ctx.agps_profile_port_buffer, "%d", g_gps_ctx.agps_profile_temp.port);
    cui_inline_set_value(g_gps_ctx.inline_profile_gid, MMI_GPS_EDIT_PROFILE_INLINE_PORT_TEXT, (void*)g_gps_ctx.agps_profile_port_buffer);

    cui_inline_set_softkey_text(g_gps_ctx.inline_profile_gid, MMI_GPS_EDIT_PROFILE_INLINE_DA_SELECT, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
    cui_inline_set_softkey_icon(g_gps_ctx.inline_profile_gid, MMI_GPS_EDIT_PROFILE_INLINE_DA_SELECT, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);

    cui_inline_set_title(g_gps_ctx.inline_profile_gid, STR_ID_GPS_SETTING_AGPS_PROFILE, GetRootTitleIcon(MENU_ID_GPS_SETTING));    /* title text and icon */

    /* set Data Account */
    memset(&para, 0, sizeof(cui_dtcnt_select_run_struct));
    para.app_id  = 0;
    para.icon_id = 0;
    para.str_id = STR_GLOBAL_DATA_ACCOUNT;
    para.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
    para.bearers = DATA_ACCOUNT_BEARER_CSD | DATA_ACCOUNT_BEARER_GPRS;
    para.option = CUI_DTCNT_SELECT_SIM;

    {
        if (g_gps_ctx.curr_sim == 0)
        {
            para.sim_selection = CUI_DTCNT_SELECT_SIM1;
            para.sim_account_id[0] = g_gps_ctx.data_account_temp;
        }
    #if MMI_SIM_TOTAL > 1
        else if (g_gps_ctx.curr_sim == 1)
        {
            para.sim_selection = CUI_DTCNT_SELECT_SIM2;
            para.sim_account_id[1] = g_gps_ctx.data_account_temp;
        }
    #endif
    #if MMI_SIM_TOTAL > 2
        else if (g_gps_ctx.curr_sim == 2)
        {
            para.sim_selection = CUI_DTCNT_SELECT_SIM3;
            para.sim_account_id[2] = g_gps_ctx.data_account_temp;
        }
    #endif
    #if MMI_SIM_TOTAL > 3
        else if (g_gps_ctx.curr_sim == 3)
        {
            para.sim_selection = CUI_DTCNT_SELECT_SIM4;
            para.sim_account_id[3] = g_gps_ctx.data_account_temp;
        }
    #endif
    }

    cui_dtcnt_select_set_param(g_gps_ctx.inline_profile_gid, &para);

    cui_inline_run(g_gps_ctx.inline_profile_gid);
}


mmi_ret mmi_gps_setting_profile_ask_confirmCb(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_1:
        case MMI_ALERT_CNFM_2:
        case MMI_ALERT_CNFM_3:
            // handle softkey event here
            break;
        case MMI_ALERT_CNFM_OK:
            // handle softkey event here
            break;
        case MMI_ALERT_CNFM_YES:
            mmi_gps_setting_save_agps_profile_check_dataaccount();
            break;
        case MMI_ALERT_CNFM_NO:
            // handle softkey event here
            mmi_gps_setting_cansel_and_goback();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_edit_agps_profile_data_account
 * DESCRIPTION
 *  input editor entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_edit_agps_profile_data_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id da_gid;
    cui_dtcnt_select_run_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&para, 0, sizeof(cui_dtcnt_select_run_struct));
    para.app_id  = g_gps_ctx.app_id;
    para.account_id  = g_gps_ctx.data_account_temp;
    para.AppMenuID = 0;
    para.icon_id = GetRootTitleIcon(MENU_ID_GPS_SETTING);
    para.str_id = STR_GLOBAL_DATA_ACCOUNT;
    para.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
    para.bearers = DATA_ACCOUNT_BEARER_CSD | DATA_ACCOUNT_BEARER_GPRS;
    para.option = CUI_DTCNT_SELECT_SIM;
    {
        if (g_gps_ctx.curr_sim == 0)
        {
            para.sim_selection = CUI_DTCNT_SELECT_SIM1;
            para.sim_account_id[0] = g_gps_ctx.data_account_temp;
        }
    #if MMI_SIM_TOTAL > 1
        else if (g_gps_ctx.curr_sim == 1)
        {
            para.sim_selection = CUI_DTCNT_SELECT_SIM2;
            para.sim_account_id[1] = g_gps_ctx.data_account_temp;
        }
    #endif
    #if MMI_SIM_TOTAL > 2
        else if (g_gps_ctx.curr_sim == 2)
        {
            para.sim_selection = CUI_DTCNT_SELECT_SIM3;
            para.sim_account_id[2] = g_gps_ctx.data_account_temp;
        }
    #endif
    #if MMI_SIM_TOTAL > 3
        else if (g_gps_ctx.curr_sim == 3)
        {
            para.sim_selection = CUI_DTCNT_SELECT_SIM4;
            para.sim_account_id[3] = g_gps_ctx.data_account_temp;
        }
    #endif
    }

    da_gid = cui_dtcnt_select_create(g_gps_ctx.cur_gid);

    cui_dtcnt_select_set_param(da_gid, &para);
    cui_dtcnt_select_run(da_gid);
}


/*****************************************************************************
* FUNCTION
*  mmi_dmui_info_cs_data_account_cb
* DESCRIPTION
*  call back function of data account select screen
* PARAMETERS
*  account_id       [IN]        return account id from data account
* RETURNS
*  void
*****************************************************************************/
static void mmi_gps_select_agps_profile_data_account_callback(U32 account_id)
{
    /*----------------------------------------------------------*/
    /* Local Variables                                          */
    /*----------------------------------------------------------*/

    /*----------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------*/
    g_gps_ctx.data_account_temp = account_id;
#if defined(__AGPS_USER_PLANE__)
    mmi_ucs2cpy((CHAR*)g_gps_ctx.data_account_name, (CHAR*) GetString((U16) (STR_GLOBAL_NONE)));
    mmi_dtcnt_get_full_account_name(g_gps_ctx.data_account_temp, (CHAR *)g_gps_ctx.data_account_name, sizeof(g_gps_ctx.data_account_name),MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
#endif
    if (g_gps_ctx.inline_profile_gid != 0)
    {
        cui_inline_set_value(g_gps_ctx.inline_profile_gid, MMI_GPS_EDIT_PROFILE_INLINE_DA_SELECT, (void*)g_gps_ctx.data_account_name);
    }
    g_gps_ctx.is_profile_modified = MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_setting_save_agps_profile
 * DESCRIPTION
 *  input editor entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_gps_setting_save_agps_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id = 0;
    CHAR  temp[MMI_GPS_MAX_PORT_BUFFER_LEN];
    U16 ucs2_temp[MMI_GPS_MAX_PORT_BUFFER_LEN];
    S32 port;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if (mmi_ucs2cmp((CHAR*)g_gps_ctx.agps_profile_temp.name, (CHAR*)g_gps_ctx.agps_profile[0].name))
    {
        kal_mem_set(g_gps_ctx.agps_profile_temp.provurl, 0, sizeof(g_gps_ctx.agps_profile_temp.provurl));
        kal_mem_set(g_gps_ctx.agps_profile_temp.nap_id, 0, sizeof(g_gps_ctx.agps_profile_temp.nap_id));
    }
#endif
    memcpy(&g_gps_ctx.agps_profile[0],
           &g_gps_ctx.agps_profile_temp,
           sizeof(nvram_ef_agps_profile_struct));

    g_gps_ctx.settings.sim[g_gps_ctx.curr_sim].settings.data_account = g_gps_ctx.data_account_temp;

    cui_inline_get_value(g_gps_ctx.inline_profile_gid, MMI_GPS_EDIT_PROFILE_INLINE_ADDR_TEXT, (void*)g_gps_ctx.agps_profile[0].addr);
    memset(ucs2_temp,0,MMI_GPS_MAX_PORT_BUFFER_LEN*2);
    kal_wsprintf((WCHAR *)ucs2_temp, "%d", g_gps_ctx.agps_profile_temp.port);
    cui_inline_get_value(g_gps_ctx.inline_profile_gid, MMI_GPS_EDIT_PROFILE_INLINE_PORT_TEXT, (void*)ucs2_temp);
    mmi_ucs2_to_asc((CHAR*)temp, (CHAR*)ucs2_temp);
    port = atoi((CHAR *)temp);
    if (port<=0 || port > 65535)
    {
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_GPS_SETTING_AGPS_PROFILE_INVALID_PORT)), MMI_EVENT_FAILURE, NULL);

        return MMI_FALSE;
    }
    g_gps_ctx.agps_profile[0].port = port;

    if (g_gps_ctx.agps_profile[0].name[0] == 0)
    {
        kal_wsprintf(g_gps_ctx.agps_profile[0].name, "Profile %d", 1);
    }

    mmi_gps_setting_set_profile(&g_gps_ctx.agps_profile[0]);
    mmi_gps_setting_set_data_account(g_gps_ctx.curr_sim, g_gps_ctx.data_account_temp);

    scrn_id = mmi_frm_scrn_get_active_id();
    mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_SAVED)), MMI_EVENT_SUCCESS, NULL);
    mmi_frm_scrn_close (g_gps_ctx.cur_gid, scrn_id);
    g_gps_ctx.is_profile_modified = MMI_FALSE;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_setting_save_agps_profile_check_dataaccount
 * DESCRIPTION
 *  input editor entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_gps_setting_save_agps_profile_check_dataaccount(void)
{
    MMI_BOOL ret = MMI_TRUE;

    if (mmi_dtcnt_acct_is_valid(g_gps_ctx.data_account_temp) != MMI_DTCNT_ACCT_VALID_NONE)
    {
        ret = mmi_gps_setting_save_agps_profile();
    }
    else
    {
        ret = MMI_FALSE;
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_GPS_SETTING_AGPS_PROFILE_INVALID_DATA_ACCOUNT)), MMI_EVENT_FAILURE, NULL);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gps_setting_save_agps_profile_check_dataaccount
 * DESCRIPTION
 *  input editor entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_gps_setting_save_agps_profile_check_dataaccount_close_grp(void)
{
    if (mmi_dtcnt_acct_is_valid(g_gps_ctx.data_account_temp) != MMI_DTCNT_ACCT_VALID_NONE)
    {
        mmi_gps_setting_save_agps_profile();
        cui_inline_close(g_gps_ctx.inline_profile_gid);
        g_gps_ctx.inline_profile_gid = 0;
    }
    else
    {
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_GPS_SETTING_AGPS_PROFILE_INVALID_DATA_ACCOUNT)), MMI_EVENT_FAILURE, NULL);
    }
}
#endif /* defined(__AGPS_USER_PLANE__) */
#endif /* __GPS_SUPPORT__ || __BT_GPS_SUPPORT__ */

