/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  ScrLockerSetting.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the screen locker setting menu.
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

/****************************************************************************
 * include
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_AUTO_KEYPAD_LOCK__)

#include "MenuCuiGprot.h"
#include "mmi_rp_app_mainmenu_def.h" /* MAIN_MENU_TITLE_SETTINGS_ICON */

#ifdef __MMI_TELEPHONY_SUPPORT__
#include "mmi_rp_app_security_setting_def.h" /* MENU_ID_SECSET_MAIN_MENU */
#endif

// auto add by kw_check begin
#include "MMIDataType.h"
#include "mmi_rp_app_scr_locker_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "kal_general_types.h"
#include "AlertScreen.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "gpiosrvgprot.h"
#include "ScrLockerGprot.h"
#include "CommonScreensResDef.h"

#include "BootupSrvGprot.h"
// auto add by kw_check end 

/****************************************************************************
 * Setting enum
 ****************************************************************************/

typedef enum
{
    MMI_SLK_SET_SELECTION_OFF = 0,
    MMI_SLK_SET_SELECTION_15_SEC,
    MMI_SLK_SET_SELECTION_30_SEC,
    MMI_SLK_SET_SELECTION_1_MIN,
    MMI_SLK_SET_SELECTION_5_MIN,

    MMI_SLK_SET_SELECTION_END_OF_ENUM
} mmi_slk_set_selection_enum;

#define MMI_SLK_SET_SELECTION_DEFAULT MMI_SLK_SET_SELECTION_OFF


typedef struct
{
    mmi_menu_id menu_id;
    mmi_slk_set_selection_enum stored_value;
    S32 timeout_value;
} mmi_slk_set_mapping_entry_struct;

static const S32 mmi_slk_set_str[] = 
{
    STR_GLOBAL_OFF,
    STR_ID_SLK_15_SEC,
    STR_ID_SLK_30_SEC,
    STR_ID_SLK_1_MIN,
    STR_ID_SLK_5_MIN,
};

static const mmi_slk_set_mapping_entry_struct mmi_slk_set_mapping[] =
{
    { MENU_ID_SLK_SETTING_OFF,      MMI_SLK_SET_SELECTION_OFF,      0 },
    { MENU_ID_SLK_SETTING_15_SEC,   MMI_SLK_SET_SELECTION_15_SEC,   15 * 1000 },
    { MENU_ID_SLK_SETTING_30_SEC,   MMI_SLK_SET_SELECTION_30_SEC,   30 * 1000 },
    { MENU_ID_SLK_SETTING_1_MIN,    MMI_SLK_SET_SELECTION_1_MIN,    60 * 1000 },
    { MENU_ID_SLK_SETTING_5_MIN,    MMI_SLK_SET_SELECTION_5_MIN,    5 * 60 * 1000 }
};

static const S32 mmi_slk_set_max_mapping_num =
    sizeof(mmi_slk_set_mapping) / sizeof(mmi_slk_set_mapping[0]);


/****************************************************************************
 * Context
 ****************************************************************************/

typedef struct
{
    mmi_id menu_cui;
} mmi_slk_set_cntx_struct;


static mmi_slk_set_cntx_struct g_mmi_slk_set_cntx =
{
    0
};


/****************************************************************************
 * Functions
 ****************************************************************************/

static mmi_slk_set_selection_enum mmi_slk_set_get_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvram_data;
    //S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValueSlim(NVRAM_SETTING_AUTOKEYPADLOCK_TIME, &nvram_data, DS_BYTE);
    if (nvram_data >= MMI_SLK_SET_SELECTION_END_OF_ENUM)
    {
        nvram_data = (U8)MMI_SLK_SET_SELECTION_DEFAULT;
        WriteValueSlim(NVRAM_SETTING_AUTOKEYPADLOCK_TIME, &nvram_data, DS_BYTE);
    }

    return (mmi_slk_set_selection_enum)(nvram_data);
}


/* Old adaptor, to be removed */
U8 GetAutoKeypadLockTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8)mmi_slk_set_get_selection();
}


static MMI_BOOL mmi_slk_set_store_selection_by_menu_id(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 nvram_data;
    //S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < mmi_slk_set_max_mapping_num; i++)
    {
        if (mmi_slk_set_mapping[i].menu_id == menu_id)
        {
            if (mmi_slk_set_get_selection() != mmi_slk_set_mapping[i].stored_value)
            {
                nvram_data = (U8)mmi_slk_set_mapping[i].stored_value;
                WriteValueSlim(NVRAM_SETTING_AUTOKEYPADLOCK_TIME, &nvram_data, DS_BYTE);
            #ifdef __MMI_BACKLIGHT_SUPPORT__
                    if (mmi_slk_set_mapping[i].stored_value == MMI_SLK_SET_SELECTION_OFF)
                    {
                        return srv_gpio_setting_set_bl_time(60);
                    }
                    else
                    {
                    	return srv_gpio_setting_set_bl_time(mmi_slk_set_mapping[i].timeout_value/1000);
                    }
            #endif /* __MMI_BACKLIGHT_SUPPORT__ */
                }
                else
                {
                    return MMI_FALSE;
                }
        }
    }
    
    return MMI_FALSE;
}


S32 mmi_slk_set_get_timeout_value_in_msec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_slk_set_selection_enum stored_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stored_value = mmi_slk_set_get_selection();
    for (i = 0; i < mmi_slk_set_max_mapping_num; i++)
    {
        if (mmi_slk_set_mapping[i].stored_value == stored_value)
        {
            return mmi_slk_set_mapping[i].timeout_value;
        }
    }

    return 0;
}

S32 mmi_slk_set_get_timeout_value_str(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_slk_set_selection_enum stored_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stored_value = mmi_slk_set_get_selection();
    for (i = 0; i < mmi_slk_set_max_mapping_num; i++)
    {
        if (mmi_slk_set_mapping[i].stored_value == stored_value)
        {
            return mmi_slk_set_str[i];
        }
    }

    return STR_GLOBAL_OFF;
}

static mmi_menu_id mmi_slk_set_get_menu_item_selected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_slk_set_selection_enum stored_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stored_value = mmi_slk_set_get_selection();
    for (i = 0; i < mmi_slk_set_max_mapping_num; i++)
    {
        if (mmi_slk_set_mapping[i].stored_value == stored_value)
        {
            return mmi_slk_set_mapping[i].menu_id;
        }
    }

    return MENU_ID_SLK_SETTING_OFF;
}


static mmi_ret mmi_slk_set_menu_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_set_cntx_struct *cntx;
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_slk_set_cntx_struct*)evt->user_data;
    menu_evt = (cui_menu_event_struct*)evt;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            /* [MAUI_02442161] We don't reset radio item if go back history */
            if (!(menu_evt->cui_menu_event_flags & CUI_MENU_LIST_FROM_HISTORY))
            {
                cui_menu_set_radio_list_item(menu_evt->sender_id, mmi_slk_set_get_menu_item_selected());
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            // [MAUI_MAUI_02445036] always show the done popup even select the same item
            mmi_slk_set_store_selection_by_menu_id(menu_evt->highlighted_menu_id);
            mmi_popup_display_simple(
                get_string(STR_GLOBAL_DONE),
                MMI_EVENT_SUCCESS,
                GRP_ID_SLK_SETTING,
                cntx);
            cntx->menu_cui = 0;
            cui_menu_close(menu_evt->sender_id);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cntx->menu_cui = 0;
            cui_menu_close(menu_evt->sender_id);
            break;

        case EVT_ID_POPUP_QUIT:
            mmi_scr_locker_restart_timer();
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            break;
        
    }

    return MMI_RET_OK;
}

void mmi_scr_locker_screen_auto_lock_entry(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_set_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cntx = &g_mmi_slk_set_cntx;

    mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_SLK_SETTING,
        mmi_slk_set_menu_grp_proc,
        cntx,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cntx->menu_cui = cui_menu_create(
        GRP_ID_SLK_SETTING,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_FROM_RESOURCE,
        MENU_ID_SLK_TIME_SETTING_MENU,
        MMI_TRUE,
        cntx);

    cui_menu_set_default_title_image(cntx->menu_cui, get_image(MAIN_MENU_TITLE_SETTINGS_ICON));
    cui_menu_set_access_by_shortcut(cntx->menu_cui, MMI_FALSE);
    cui_menu_run(cntx->menu_cui);
}

#ifndef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
void mmi_scr_locker_screen_auto_lock_set_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_STR_ID hint_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 1    
    cui_menu_set_item_hint(
        mmi_frm_group_get_active_id(),
        MENU_ID_SLK_TIME_SETTING_MENU,
        get_string(mmi_slk_set_get_timeout_value_str()));
#else   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
#endif


#ifdef __MMI_BACKLIGHT_SUPPORT__
mmi_ret mmi_slk_set_default_backlight_timer()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvram_data;
    //S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        nvram_data = (U8)MMI_SLK_SET_SELECTION_DEFAULT;
        ReadValueSlim(NVRAM_SETTING_AUTOKEYPADLOCK_TIME, &nvram_data, DS_BYTE);
	
	if (nvram_data == MMI_SLK_SET_SELECTION_OFF)
	{
		srv_gpio_setting_set_bl_time(60);
	}
	else
	{
		srv_gpio_setting_set_bl_time(mmi_slk_set_mapping[nvram_data].timeout_value/1000);
	}

	return MMI_RET_OK;
}
#endif /* __MMI_BACKLIGHT_SUPPORT__ */


mmi_ret mmi_slk_set_main_evt_hdlr(mmi_event_struct *event)
{
    mmi_ret ret;

    MMI_ASSERT(event);

    switch (event->evt_id)
    {
    #ifdef __MMI_BACKLIGHT_SUPPORT__
        case EVT_ID_SRV_BOOTUP_COMPLETED:
            ret = mmi_slk_set_default_backlight_timer();
            break;
    #endif /* __MMI_BACKLIGHT_SUPPORT__ */
        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
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
#endif

#endif /* defined(__MMI_AUTO_KEYPAD_LOCK__) */

