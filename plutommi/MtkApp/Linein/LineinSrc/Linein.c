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
*  FMRadioSrc.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio main program
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"
#include "LineinGprot.h"

#ifdef __MMI_LINE_IN__
#include "globalresdef.h"
#include "gui_typedef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_softkeys.h"
#include "wgui_draw_manager.h"
#include "gpiosrvgprot.h"
#include "mdi_audio.h"
#include "BootupSrvGprot.h"

#include "Linein.h"
#include "mmi_rp_app_linein_def.h"
#include "wgui_categories_btbox.h"


static mmi_linein_context_struct g_linein_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_linein_is_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_linein_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_get_active_id() == GRP_ID_LINEIN && mmi_frm_scrn_get_active_id() == SCR_ID_LINEIN_MAIN)
        return MMI_TRUE;

    return MMI_FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_linein_is_plug_in
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_linein_is_plug_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_linein_cntx.is_plug_in)
        return MMI_TRUE;

    return MMI_FALSE;    
}


#ifdef __MMI_BTBOX_NOLCD__

#include "ProfilesSrvGprot.h"
#include "mmi_frm_input_event.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_linein_notify_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static srv_prof_ret mmi_linein_notify_callback_hdlr(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_LINEIN_NOTIFY_CALLBACK, result);

    if (mmi_linein_is_active() && mmi_linein_is_plug_in())
    {
        ReadValueSlim(NVRAM_LINEIN_VOLUME, &g_linein_cntx.volume, DS_BYTE);
        mdi_audio_enable_bt_box_linein(KAL_TRUE);
        g_linein_cntx.in_line_in = MMI_TRUE;
        if (g_linein_cntx.volume < MDI_LINEIN_VOL_MUTE_MIN || g_linein_cntx.volume > MDI_LINEIN_VOL_MUTE_MAX - 1)
        {
            g_linein_cntx.volume = MDI_LINEIN_DEFAULT_VOL;
            WriteValueSlim(NVRAM_LINEIN_VOLUME, &g_linein_cntx.volume, DS_BYTE);
        }
        mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_MUTE(g_linein_cntx.volume)));
    }
    else
    {
        mdi_audio_resume_background_play();
    }
    
    return 0;    
}

#endif  //__MMI_BTBOX_NOLCD__


/*****************************************************************************
 * FUNCTION
 *  mmi_linein_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_linein_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_LINEIN_LAUNCH, 100);
    if (srv_bootup_is_completed() && !mmi_linein_is_active()
    #ifdef __MTK_TARGET__
        && mmi_linein_is_plug_in()
    #endif
        )
    {
        g_linein_cntx.group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_LINEIN, mmi_linein_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        MMI_ASSERT(g_linein_cntx.group_id != GRP_ID_INVALID);
        mmi_frm_scrn_create(g_linein_cntx.group_id, SCR_ID_LINEIN_MAIN, mmi_linein_proc, NULL);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_linein_entry_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_linein_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BTBOX_NOLCD__
    mmi_input_event_notify_param param = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_linein_cntx.in_line_in = MMI_FALSE;
    param.aud_cb = mmi_linein_notify_callback_hdlr;
    mdi_audio_suspend_background_play();
    mmi_frm_input_event_notify(BTBOX_LINE_IN_ENTER, &param);
    mmi_frm_input_event_disable_notify();
#else  //__MMI_BTBOX_NOLCD__
    ReadValueSlim(NVRAM_LINEIN_VOLUME, &g_linein_cntx.volume, DS_BYTE);
    mdi_audio_enable_bt_box_linein(KAL_TRUE);
    if (g_linein_cntx.volume < MDI_LINEIN_VOL_MUTE_MIN || g_linein_cntx.volume > MDI_LINEIN_VOL_MUTE_MAX - 1)
    {
        g_linein_cntx.volume = MDI_LINEIN_DEFAULT_VOL;
        WriteValueSlim(NVRAM_LINEIN_VOLUME, &g_linein_cntx.volume, DS_BYTE);
    }
    mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_MUTE(g_linein_cntx.volume)));
    
    ShowCategory8001Screen(
        STR_ID_LINEIN_TITLE,
        (g_linein_cntx.is_mute ? STR_ID_LINEIN_MUTE_ON : STR_ID_LINEIN_MUTE_OFF),
        STR_GLOBAL_BACK,
        IMG_ID_LINEIN_PLAY_ANIMATION,
        !(g_linein_cntx.is_mute));
    
    SetLeftSoftkeyFunction(mmi_linein_set_mute, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#endif  //__MMI_BTBOX_NOLCD__
}


/*****************************************************************************
 * FUNCTION
 *  mmi_linein_exit_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_linein_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BTBOX_NOLCD__
    if (g_linein_cntx.in_line_in)
    {
        mdi_audio_enable_bt_box_linein(KAL_FALSE);
    }
    mmi_frm_input_event_enable_notify();
    mmi_frm_input_event_notify_remove(BTBOX_LINE_IN_VOL_CHANGE);
    mmi_frm_input_event_notify_remove(BTBOX_LINE_IN_MUTE);
    mmi_frm_input_event_notify_remove(BTBOX_LINE_IN_ENTER);
    mdi_audio_resume_background_play();
    if (g_linein_cntx.is_first_launch)
    {
        memset(&g_linein_cntx, 0, sizeof(mmi_linein_context_struct));
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_LINEIN_TEST, 3, 1);
        mmi_frm_input_event_goto_first_local_app();
    }
#else  //__MMI_BTBOX_NOLCD__
    mdi_audio_enable_bt_box_linein(KAL_FALSE);
#endif  //__MMI_BTBOX_NOLCD__
    memset(&g_linein_cntx, 0, sizeof(mmi_linein_context_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_linein_inc_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_linein_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_linein_cntx.is_mute
        #ifdef __MMI_BTBOX_NOLCD__
        || !g_linein_cntx.in_line_in
        #endif  //__MMI_BTBOX_NOLCD__
        )
        return;
    
    if (g_linein_cntx.volume < MDI_LINEIN_VOL_MUTE_MAX - 1)
    {
        g_linein_cntx.volume++;
        WriteValueSlim(NVRAM_LINEIN_VOLUME, &g_linein_cntx.volume, DS_BYTE);
        mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_MUTE(g_linein_cntx.volume)));
        #ifdef __MMI_BTBOX_NOLCD__
        mmi_frm_input_event_notify(BTBOX_LINE_IN_VOL_CHANGE, NULL);
        //mmi_frm_input_event_notify_remove(BTBOX_LINE_IN_VOL_CHANGE);
        #endif  //__MMI_BTBOX_NOLCD__
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_LINEIN_TEST, 1, g_linein_cntx.volume);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_linein_dec_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_linein_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_linein_cntx.is_mute
        #ifdef __MMI_BTBOX_NOLCD__
        || !g_linein_cntx.in_line_in
        #endif  //__MMI_BTBOX_NOLCD__
        )
        return;
    
    if (g_linein_cntx.volume > MDI_LINEIN_VOL_MUTE_MIN + 1)
    {
        g_linein_cntx.volume--;
        WriteValueSlim(NVRAM_LINEIN_VOLUME, &g_linein_cntx.volume, DS_BYTE);
        mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_MUTE(g_linein_cntx.volume)));
        #ifdef __MMI_BTBOX_NOLCD__
        mmi_frm_input_event_notify(BTBOX_LINE_IN_VOL_CHANGE, NULL);
        //mmi_frm_input_event_notify_remove(BTBOX_LINE_IN_VOL_CHANGE);
        #endif  //__MMI_BTBOX_NOLCD__
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_LINEIN_TEST, 2, g_linein_cntx.volume);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_linein_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_linein_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_LINEIN_PROC, event->evt_id, g_linein_cntx.is_mute, g_linein_cntx.is_plug_in, mmi_linein_is_active(), g_linein_cntx.is_first_launch, g_linein_cntx.volume);
    switch (event->evt_id)
    {
    #ifdef __MMI_BTBOX_NOLCD__
        case EVT_ID_SRV_BOOTUP_COMPLETED:
            if (mmi_linein_is_plug_in() && !mmi_frm_group_is_present(GRP_ID_LINEIN))
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_LINEIN_TEST, 0, 0);
                g_linein_cntx.is_first_launch = MMI_TRUE;
                mmi_linein_launch();
            }
            break;
        case EVT_ID_BTBOX_LINE_IN_MUTE_UNMUTE:
            mmi_linein_set_mute();
            break;
        case EVT_ID_BTBOX_LINE_IN_VOL_UP:
            mmi_linein_inc_volume();
            break;
        case EVT_ID_BTBOX_LINE_IN_VOL_DOWN:
            mmi_linein_dec_volume();
            break;
    #endif  //__MMI_BTBOX_NOLCD__
        case EVT_ID_GPIO_LINEIN_PLUG_IN:
            {
        #ifdef __MMI_BTBOX_NOLCD__
            U8 is_enabled = 0;
            ReadValueSlim(NVRAM_LINEIN_ENABLE, &is_enabled, DS_BYTE);
            if (!is_enabled)
                break;
        #endif  //__MMI_BTBOX_NOLCD__
            g_linein_cntx.is_plug_in = MMI_TRUE;
        #ifdef __MMI_BTBOX_NOLCD__
            mmi_linein_launch();
        #endif  //__MMI_BTBOX_NOLCD__
            }
            break;
        case EVT_ID_GPIO_LINEIN_PLUG_OUT:
            g_linein_cntx.is_plug_in = MMI_FALSE;
            mmi_frm_group_close(GRP_ID_LINEIN);
            break;
        case EVT_ID_SCRN_ACTIVE:
            mmi_linein_entry_screen();
            break;
        case EVT_ID_SCRN_INACTIVE:
            mmi_linein_exit_screen();
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_linein_set_mute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_linein_set_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_BTBOX_NOLCD__
    if (!g_linein_cntx.in_line_in)
    {
        return;
    }
    #endif  //__MMI_BTBOX_NOLCD__
    g_linein_cntx.is_mute = !(g_linein_cntx.is_mute);
    if (g_linein_cntx.is_mute)
    {
        #ifdef __MMI_BTBOX_NOLCD__
        mmi_frm_input_event_notify(BTBOX_LINE_IN_MUTE, NULL);
        #endif  //__MMI_BTBOX_NOLCD__
        mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_MUTE(0)));
    }
    else
    {
        #ifdef __MMI_BTBOX_NOLCD__
        mmi_frm_input_event_notify_remove(BTBOX_LINE_IN_MUTE);
        #endif  //__MMI_BTBOX_NOLCD__
        mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8)(MDI_AUD_VOL_MUTE(g_linein_cntx.volume)));
    }
#if !defined(__MMI_BTBOX_NOLCD__)
    wgui_cat8001_set_animation(!g_linein_cntx.is_mute);
    set_left_softkey_label((UI_string_type)GetString(g_linein_cntx.is_mute ? STR_ID_LINEIN_MUTE_ON : STR_ID_LINEIN_MUTE_OFF));
    dm_redraw_category_screen();
#endif  //!defined(__MMI_BTBOX_NOLCD__)
}


/*****************************************************************************
 * FUNCTION
 *  mmi_linein_check_plug_in_or_hide
 * DESCRIPTION
 *  Check whether line-in had plug in or hide line-in menu item
 * PARAMETERS
 *  n_items         [IN]        Number of string IDs
 *  string_ids      [IN]        String ID's
 *  icon_ids        [IN]        Icon ID's
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_linein_check_plug_in_or_hide(U16 n_items, U16 *string_ids, U16 *icon_ids)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__) && !defined(__MMI_BTBOX_NOLCD__)
    if (!mmi_linein_is_plug_in())
    {
        /* hide Line-in application menu item */
        S16 i, j;

        for (i = n_items - 1; i >= 0; i--)
        {
            if (string_ids[i] == STR_ID_LINEIN_TITLE)    /* look for Line-in application string id */
            {
                break;
            }
        }
        if (i >= 0) /* found Line-in application string id */
        {
            n_items--;
            for (j = i; j < n_items; j++)   /* move rest application string & image ids up */
            {
                string_ids[j] = string_ids[j + 1];
                icon_ids[j] = icon_ids[j + 1];
            }
        }
    }
#endif  //defined(__MTK_TARGET__) && !defined(__MMI_BTBOX_NOLCD__)

    return n_items;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_linein_highlight_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_linein_highlight_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_BTBOX_NOLCD__)
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_linein_launch, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_linein_launch, KEY_EVENT_UP);
#endif  //!defined(__MMI_BTBOX_NOLCD__)
}

#endif  //__MMI_LINE_IN__

