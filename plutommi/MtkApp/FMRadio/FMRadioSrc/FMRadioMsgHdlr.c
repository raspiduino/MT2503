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
*  FMRadioMsgHdlr.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio message handling program
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifdef __MMI_BTBOX_NOLCD__
#include "gui_data_types.h"
#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "nvram_common_defs.h"
#include "GlobalResDef.h"

#include "gui_typedef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_softkeys.h"


#include "FMRadioType.h"

#include "mdi_audio.h"
#include "ProfilesSrvGprot.h"
#include "mmi_frm_input_event.h"

mmi_fmradio_struct g_fmradio;   /* all memeber variables are zero initial */
mmi_fmradio_search_one_struct fmradio_search_one;
MMI_BOOL g_is_playing_notify = MMI_FALSE;
void mmi_fmradio_power_on(BOOL turn_on);
mmi_ret mmi_fmradio_proc(mmi_event_struct *event);

/***************************************************************************** 
 * temp dummy to avoid link error 
 *****************************************************************************/

void mmi_fmrdo_dec_volume(void)
{
}

void mmi_fmrdo_inc_volume(void)
{
}

BOOL mmi_fmrdo_is_power_on(void)
{
    return FALSE;
}

void mmi_fmrdo_highlight_menu(void)
{
}

U16 mmi_fmrdo_check_chip_or_hide(U16 n_items, U16 *string_ids, U16 *icon_ids)
{
}

void mmi_fmrdo_skip_highlight_hdlr(S32 index)
{
}

void mmi_fmrdo_switch_bt_output(void)
{
}

void mmi_fmrdo_init_app(void) /* referred from funandgamessrc.obj */
{
}

UI_string_type mmi_fmrdo_get_channel_name_or_freq(void)
{
}

mmi_ret mmi_fmrdo_earphone_notify_hdlr(mmi_event_struct *event)
{
    return 0;
} 

mmi_ret mmi_fmrdo_is_power_on_callback_hdlr(mmi_event_struct *event)
{
    return 0;
} 

mmi_ret mmi_fmrdo_main_scrn_proc(mmi_event_struct *param)
{
}

void mmi_fmrdo_a2dp_connect_callback_hdlr(void)
{
}

void mmi_fmrdo_search_all_channels_stop(void)
{
} 


/*****************************************************************************
 * FUNCTION
 *  mmi_megaphone_is_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_fmradio_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_STATE,g_fmradio.state);
    return (g_fmradio.state == FMRADIO_STATE_PLAYING || g_fmradio.state == FMRADIO_STATE_SEARCH_ONE);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_notify_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_fmradio_delay_callback_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_NOTIFY_CALLBACK, 255,g_fmradio.state);

    if (!mmi_fmradio_is_active() && (mmi_frm_group_get_active_id() == GRP_ID_FMRADIO))
    {
		S16 error;	
	
		ReadValue(NVRAM_FMRADIO_VOL,
				&g_fmradio.volume,
				DS_BYTE,
				&error);
		if(g_fmradio.volume > MDI_FMRADIO_VOL_EX_MAX)
		{
			g_fmradio.volume = DEFAULT_FM_VOL;
			WriteValue(NVRAM_FMRADIO_VOL, &g_fmradio.volume, DS_BYTE, &error);
		}

		ReadValue(NVRAM_FMRADIO_FREQ,
				&g_fmradio.frequency,
				DS_SHORT,
				&error);
		if(g_fmradio.frequency < MIN_FM_FREQUENCY || g_fmradio.frequency > MAX_FM_FREQUENCY)
		{
			g_fmradio.frequency = DEFAULT_FM_FREQUENCY;
			WriteValue(NVRAM_FMRADIO_FREQ, &g_fmradio.frequency, DS_SHORT, &error);
		}
		mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
		mmi_fmradio_power_on(MMI_TRUE);
		mmi_frm_input_event_notify_remove(BTBOX_FMRADIO_ENTER);
    }
    else
    {
        mdi_audio_resume_background_play();
    }
	g_is_playing_notify = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_notify_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static srv_prof_ret mmi_fmradio_notify_callback_hdlr(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_NOTIFY_CALLBACK, result,g_fmradio.state);
    StartTimer(FMRDO_DELAY_CALLBACK_TIMER, 1, mmi_fmradio_delay_callback_hdlr);  
	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_set_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  freq        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmradio_set_frequency(U16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_SET_FREQ,freq,g_fmradio.state);
    g_fmradio.frequency = freq;
	if(g_fmradio.frequency < MIN_FM_FREQUENCY || g_fmradio.frequency > MAX_FM_FREQUENCY)
    {
        g_fmradio.frequency = DEFAULT_FM_FREQUENCY;
    }

	WriteValue(NVRAM_FMRADIO_FREQ, &g_fmradio.frequency, DS_SHORT, &error);
    
    if (mmi_fmradio_is_active())
    {
        mdi_fmr_set_freq(freq);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_search_before
 * DESCRIPTION
 *  
 * PARAMETERS
 *  turn_on     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmradio_search_before(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_SEARCH_BEFORE,g_fmradio.state);
    mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);    
    mdi_fmr_evaluate_threshold();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_search_after
 * DESCRIPTION
 *  
 * PARAMETERS
 *  turn_on     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmradio_search_after(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_SEARCH_AFTER,g_fmradio.state);
    if (mmi_fmradio_is_active())
    {
	    if (g_fmradio.volume == 0)
	    {
	        mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
	    }
	    else
	    {
	        mdi_audio_set_volume(MDI_VOLUME_FMR,MDI_AUD_VOL_EX_MUTE(g_fmradio.volume));
	    }
    }
}


#ifdef __FM_RADIO_HW_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_hw_search_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stop_freq           [IN]        Frequency searched
 *  signal_level        [IN]        signal level for frequency
 *  is_valid            [IN]        valid signal level
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmradio_hw_search_frequency(U16 stop_freq, U8 signal_level, MMI_BOOL is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_HW_SEARCH_END,stop_freq,signal_level,is_valid,g_fmradio.state);
    if (g_fmradio.state != FMRADIO_STATE_SEARCH_ONE)
    {
        return;
    }
	
	g_fmradio.state = FMRADIO_STATE_PLAYING;
	mmi_fmradio_set_frequency(stop_freq);
	mmi_fmradio_search_after();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_hw_search_frequency_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_freq      [IN]        
 *  is_step_up      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmradio_hw_search_frequency_start(U16 start_freq, BOOL is_step_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_HW_SEARCH_START,start_freq,is_step_up,g_fmradio.state);
    /* Do not let voice go out while searching */
	if(!mmi_fmradio_is_active())
		return;
	
    mmi_fmradio_search_before();
	
    fmradio_search_one.freq = start_freq;
	
    if (is_step_up)
    {
        if (start_freq < MIN_FM_FREQUENCY)
        {
            start_freq = MAX_FM_FREQUENCY;
        }
    }
    else
    {
        if (start_freq > MAX_FM_FREQUENCY)
        {
            start_freq = MIN_FM_FREQUENCY;
        }
    }
    fmradio_search_one.stop_freq = start_freq;
    fmradio_search_one.is_step_up = is_step_up;
    
    g_fmradio.state = FMRADIO_STATE_SEARCH_ONE;
    mdi_fmr_freq_seek_start(start_freq, (MMI_BOOL)is_step_up, MMI_FALSE, 100, mmi_fmradio_hw_search_frequency);
}

#else /* FM_RADIO_HW_SEARCH */ 
/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_search_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_valid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmradio_search_frequency(BOOL is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_SEARCH_END,fmradio_search_one.stop_freq,is_valid,g_fmradio.state);
    if (g_fmradio.state != FMRADIO_STATE_SEARCH_ONE)
    {
        return;
    }

    if (!is_valid && fmradio_search_one.freq != fmradio_search_one.stop_freq)
    {
        /* update frequency */
        if (fmradio_search_one.is_step_up)
        {
            if (fmradio_search_one.stop_freq < MAX_FM_FREQUENCY)
            {
                fmradio_search_one.stop_freq++;
            }
            else
            {
                fmradio_search_one.stop_freq = MIN_FM_FREQUENCY;
            }
        }
        else
        {
            if (fmradio_search_one.stop_freq > MIN_FM_FREQUENCY)
            {
                fmradio_search_one.stop_freq--;
            }
            else
            {
                fmradio_search_one.stop_freq = MAX_FM_FREQUENCY;
            }
        }

        /* test valid stop again */
        mdi_fmr_check_is_valid_stop(fmradio_search_one.stop_freq, (MMI_BOOL)fmradio_search_one.is_step_up, mmi_fmradio_search_frequency);
    }
    else
    {
        /* don't move this statement below mmi_fmradio_set_frequency for properly updating subLCD */
        g_fmradio.state = FMRADIO_STATE_PLAYING;
        fmradio_search_one.freq = fmradio_search_one.stop_freq;
        mmi_fmradio_set_frequency(fmradio_search_one.freq);
        mmi_fmradio_search_after();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_search_frequency_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_freq      [IN]        
 *  is_step_up      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmradio_search_frequency_start(U16 start_freq, BOOL is_step_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_SEARCH_START,start_freq,is_step_up,g_fmradio.state);
	if(!mmi_fmradio_is_active())
		return;
	
    mmi_fmradio_search_before();

    fmradio_search_one.freq = start_freq;
    if (!is_step_up)
    {
        if (start_freq > MIN_FM_FREQUENCY)
        {
            fmradio_search_one.stop_freq = start_freq - 1;
        }
        /* case when search is started from 107.9 MHz */

        else if (start_freq == MIN_FM_FREQUENCY)
        {
            fmradio_search_one.stop_freq = MAX_FM_FREQUENCY;
        }
        else
        {
            start_freq = MAX_FM_FREQUENCY;
        }
    }
    else
    {
        if (start_freq < MAX_FM_FREQUENCY)
        {
            fmradio_search_one.stop_freq = start_freq + 1;
        }
        else
        {
            fmradio_search_one.stop_freq = MIN_FM_FREQUENCY;
        }
    }
    fmradio_search_one.freq = start_freq;
    fmradio_search_one.is_step_up = is_step_up;
    g_fmradio.state = FMRADIO_STATE_SEARCH_ONE;

    /* start valid stop test */
    mdi_fmr_check_is_valid_stop(fmradio_search_one.stop_freq, (MMI_BOOL)is_step_up, mmi_fmradio_search_frequency);
}

#endif /* __FM_RADIO_HW_SEARCH__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_search_frequency_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmradio_search_frequency_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_SEARCH_STOP,g_fmradio.state);
    if (g_fmradio.state == FMRADIO_STATE_SEARCH_ONE)
    {
        #ifdef __FM_RADIO_HW_SEARCH__
        mdi_fmr_freq_seek_abort();
        #endif 
        /* mdi_fmr_cancel_checking_is_valid_stop(); */
        /* don't move this statement below mmi_fmradio_set_frequency for properly updating subLCD */
        g_fmradio.state = FMRADIO_STATE_PLAYING;
        mmi_fmradio_set_frequency(fmradio_search_one.freq);
        mmi_fmradio_search_after();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_continued
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_fmradio_continued(S32 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_CONTINUE,g_fmradio.state);
    if (g_fmradio.is_preempted && !mmi_fmradio_is_active())
    {
        mmi_fmradio_power_on(MMI_TRUE);
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_preempted
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmradio_preempted(S32 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_PREEMPTED,g_fmradio.state);
    if (g_fmradio.state == FMRADIO_STATE_IDLE)
    {
        return;
    }

    /* Stop FM Playing */
    mmi_fmradio_search_frequency_stop();
	if (result == MDI_AUDIO_TERMINATED)
	{
		 mdi_fmr_power_off();
	}
	g_fmradio.is_preempted = TRUE;
    g_fmradio.state = FMRADIO_STATE_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_power_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  turn_on     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmradio_power_on(BOOL turn_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_POWER_ON_ENTRY,turn_on,g_fmradio.state);

	if((mmi_frm_group_get_active_id() != GRP_ID_FMRADIO) && turn_on)
		return;

    #ifdef __MMI_HF_SUPPORT__
	if(srv_ucm_bt_is_any_call()&& turn_on)
		return;
    #endif /* __MMI_HF_SUPPORT__ */
	
    if (turn_on)
    {
        if (!mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO))
        {
            mdi_audio_suspend_background_play();
			if (g_fmradio.volume == 0)
            {
                mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
				mmi_frm_input_event_notify(INPUT_EVENT_NOTIFY_FM_VOL_MUTE,NULL);
            }
            else
            {
                mdi_audio_set_volume(MDI_VOLUME_FMR,MDI_AUD_VOL_EX_MUTE(g_fmradio.volume));
            }
            mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER_BOTH, (mdi_ext_callback) mmi_fmradio_preempted, NULL);
            mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
			
            mdi_fmr_set_freq(g_fmradio.frequency);
		    
            if (g_fmradio.volume == 0)
            {
                mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
            }
            else
            {
                mdi_audio_set_volume(MDI_VOLUME_FMR,MDI_AUD_VOL_EX_MUTE(g_fmradio.volume));
            }

        #ifdef __MMI_FM_RADIO_MONO__
            mdi_fmr_set_channel((MMI_BOOL)g_fmradio.mono);
        #endif 
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback) mmi_fmradio_continued, NULL);
            g_fmradio.state = FMRADIO_STATE_PLAYING;
        }
    }
    else
    {
        mdi_audio_stop_fmr();
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_FMR);	
		mdi_audio_resume_background_play();
		g_fmradio.state = FMRADIO_STATE_IDLE;
    }

    g_fmradio.is_preempted = FALSE;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_POWER_ON_EXIT,turn_on,g_fmradio.state);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_launch
 * DESCRIPTION
 *  To lanch megaphone when user press special key
 * PARAMETERS
 *  evt for lanuch meagphone
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_fmradio_launch(mmi_event_struct *evt)// press lanch key to lanch megaphone
{
    //TODO Add Trace 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_LAUNCH_APP,evt->evt_id);
	switch(evt->evt_id)
	{
	case EVT_ID_INPUT_EVENT_LAUNCH_FM:
	{
		kal_bool fmradio_enable=MMI_FALSE;
		MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_LAUNCH, 99);

		ReadValueSlim(NVRAM_FMRADIO_ENABLE, &fmradio_enable, DS_BYTE);
		if(!fmradio_enable)
			return MMI_RET_OK;

	    //Close current group will close current APP
	    mmi_frm_group_close(mmi_frm_group_get_active_id());
		if(g_fmradio.group_id == GRP_ID_INVALID)
		{
			g_fmradio.group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_FMRADIO, mmi_fmradio_proc, NULL, NULL);
			MMI_ASSERT(g_fmradio.group_id != GRP_ID_INVALID);
		}
		else
		{
            if(!mmi_fmradio_is_active())
            {
                mmi_frm_group_enter(g_fmradio.group_id,NULL);
			}
		}
		return MMI_RET_LOCAL_APP_LAUNCHED;
		}
        break;
    default:
       break;
	}

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_switch_app_hdlr
 * DESCRIPTION
 *  To switch on fmradio when user press switch key and switch to megaphone
 * PARAMETERS
 *  evt for switch on meagphone
 * RETURNS
 *  void
 *****************************************************************************/

mmi_ret mmi_fmradio_switch_app_hdlr(mmi_event_struct *evt)
{
    //TODO Add Trace
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_SWITCH_APP,evt->evt_id);
	switch(evt->evt_id)
	{
	case EVT_ID_INPUT_EVENT_APP_SWITCH:
		if(mmi_frm_input_event_is_app_switch_to(GRP_ID_FMRADIO))
		{ 
		    kal_bool fmradio_enable=MMI_FALSE;
			MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_LAUNCH, 100);

			ReadValueSlim(NVRAM_FMRADIO_ENABLE, &fmradio_enable, DS_BYTE);
			if(!fmradio_enable)
				return MMI_RET_OK;
		    //Close current group will close current APP
		    mmi_frm_group_close(mmi_frm_group_get_active_id());
			if(g_fmradio.group_id == GRP_ID_INVALID)
			{
				g_fmradio.group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_FMRADIO, mmi_fmradio_proc, NULL, NULL);
				MMI_ASSERT(g_fmradio.group_id != GRP_ID_INVALID);
			}
			else
			{
	            if(!mmi_fmradio_is_active())
	            {
	                mmi_frm_group_enter(g_fmradio.group_id,NULL);
				}
			}
			return MMI_RET_LOCAL_APP_LAUNCHED;
		}     ///notify can't switch¡­..
	    break;
		
	default:
	    break;
	}

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmradio_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_fmradio_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 error;	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_PROC, event->evt_id);
	
    switch (event->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            if(mmi_fmradio_is_active())
                mmi_fmradio_power_on(MMI_FALSE); 
			mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_FMR);
			g_fmradio.group_id = GRP_ID_INVALID;
			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_FM_VOL_DOWN);
			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_FM_VOL_UP);
			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_FM_VOL_MUTE);
			mmi_frm_input_event_notify_remove(BTBOX_FMRADIO_ENTER);
			mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
            break;
			
		case EVT_ID_GROUP_ACTIVE:
			{
				mmi_input_event_notify_param param = {0};
	            //Add Notify Here
			    mdi_audio_suspend_background_play();
				param.aud_cb = mmi_fmradio_notify_callback_hdlr;
			    mmi_frm_input_event_notify(BTBOX_FMRADIO_ENTER, &param);
				g_is_playing_notify = MMI_TRUE;
			    //mmi_frm_input_event_disable_notify();
			}
            break;
		case EVT_ID_GROUP_INACTIVE:
            if(mmi_fmradio_is_active())
                mmi_fmradio_power_on(MMI_FALSE); 
			mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_FMR);

			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_FM_VOL_DOWN);
			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_FM_VOL_UP);
			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_FM_VOL_MUTE);
			mmi_frm_input_event_notify_remove(BTBOX_FMRADIO_ENTER);
			mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
            break;
			
		case BTBOX_NOLCD_FM_ON_OFF: 
			if(g_is_playing_notify)
				return;
			
		    if(mmi_fmradio_is_active())
				mmi_fmradio_power_on(MMI_FALSE);
			else
				mmi_fmradio_power_on(MMI_TRUE); 
			
		    break;
		
		case BTBOX_NOLCD_FM_VOL_UP: 
		{
		    if(mmi_frm_group_get_active_id() != GRP_ID_FMRADIO)
		        return;
		    if(g_fmradio.volume >= MDI_FMRADIO_VOL_EX_MIN 
				&& g_fmradio.volume < MDI_FMRADIO_VOL_EX_MAX)
			{	
				ReadValue(NVRAM_FMRADIO_VOL,
					&g_fmradio.volume,
					DS_BYTE,
					&error);
				g_fmradio.volume++;
				mmi_frm_input_event_notify(INPUT_EVENT_NOTIFY_FM_VOL_UP,NULL);
				if(g_fmradio.volume <= MDI_FMRADIO_VOL_EX_MAX)
				{
					WriteValue(NVRAM_FMRADIO_VOL,&g_fmradio.volume, DS_BYTE, &error);
					if(mmi_fmradio_is_active())
					    mdi_audio_set_volume(MDI_VOLUME_FMR,MDI_AUD_VOL_EX_MUTE(g_fmradio.volume));
				}
			}
			mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_FM_VOL_MUTE);
		}
		    break;
		
		case BTBOX_NOLCD_FM_VOL_DOWN: 
		{
			if(mmi_frm_group_get_active_id() != GRP_ID_FMRADIO)
		        return;
		    if( g_fmradio.volume > MDI_FMRADIO_VOL_EX_MIN && 
				g_fmradio.volume <=MDI_FMRADIO_VOL_EX_MAX )
			{	
				ReadValue(NVRAM_FMRADIO_VOL,
					&g_fmradio.volume,
					DS_BYTE,
					&error);
				g_fmradio.volume--;
				mmi_frm_input_event_notify(INPUT_EVENT_NOTIFY_FM_VOL_DOWN,NULL);
				WriteValue(NVRAM_FMRADIO_VOL,&g_fmradio.volume,DS_BYTE, &error);
				if(mmi_fmradio_is_active())
				    mdi_audio_set_volume(MDI_VOLUME_FMR, MDI_AUD_VOL_EX_MUTE(g_fmradio.volume));
				if(g_fmradio.volume == MDI_FMRADIO_VOL_EX_MIN)
					mmi_frm_input_event_notify(INPUT_EVENT_NOTIFY_FM_VOL_MUTE,NULL);
				else
					mmi_frm_input_event_notify_remove(INPUT_EVENT_NOTIFY_FM_VOL_MUTE);
			}
		}
		    break;
		case BTBOX_NOLCD_FM_FREQ_UP: 
			{
			    U16 freq;
				
			    if((g_fmradio.frequency >= MIN_FM_FREQUENCY)&&(g_fmradio.frequency < MAX_FM_FREQUENCY))
					freq = g_fmradio.frequency;
				else
					freq = MIN_FM_FREQUENCY;
				
			    #ifdef __FM_RADIO_HW_SEARCH__
 				mmi_fmradio_hw_search_frequency_start(freq,MMI_TRUE);
				#else
				mmi_fmradio_search_frequency_start(freq,MMI_TRUE);
				#endif
			}
			break;
		
		case BTBOX_NOLCD_FM_FREQ_DOWN: 
			{
			    U16 freq;

				if(mmi_frm_group_get_active_id() != GRP_ID_FMRADIO)
	                return;
 				if((g_fmradio.frequency >= MIN_FM_FREQUENCY)&&(g_fmradio.frequency < MAX_FM_FREQUENCY))
					freq = g_fmradio.frequency;
				else
					freq = MAX_FM_FREQUENCY;
				
				#ifdef __FM_RADIO_HW_SEARCH__
 				mmi_fmradio_hw_search_frequency_start(freq,MMI_FALSE);
				#else
				mmi_fmradio_search_frequency_start(freq,MMI_FALSE);
				#endif
			}
			break;
    }
    return MMI_RET_OK;
}

#else //__MMI_BTBOX_NOLCD__

#ifdef __MMI_FM_RADIO__

#include "aud_defs.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_include.h"
#include "GlobalResDef.h"
#include "FMRadioDef.h"
#include "FMRadioType.h"
#include "FMRadioProt.h"
#include "FMRadioMainScreen.h"
#include "GpiosrvGprot.h"
#include "IdleGprot.h"
#include "MMIDataType.h"
#include "nvram_common_defs.h"
#include "kal_non_specific_general_types.h"
#include "mmi_res_range_def.h"
#include "gui_typedef.h"
#include "string.h"
#include "mmi_rp_app_fmrdo_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "gui_data_types.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "mmi_frm_input_gprot.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "gui.h"
#include "Unicodexdcl.h"
#ifndef __MMI_FM_PLUTO_SLIM__
#include "ScrLockerGprot.h"
#endif

#ifdef __MMI_FM_RADIO_ANIMATION__
#ifdef __RF_DESENSE_TEST__
#include "rf_desense_test.h"
#endif /*__RF_DESENSE_TEST__*/
#endif /*__MMI_FM_RADIO_ANIMATION__*/

#if defined(__MERCURY_MASTER__)
#include "MTPNP_AD_master_header.h"
#endif 

#ifdef __MMI_BACKGROUND_CALL__
#include "UcmSrvGprot.h"
#endif 

#ifdef __MMI_NCENTER_SUPPORT__
#include "vsrv_ncenter.h"
#endif

#ifdef __MMI_FM_VIA_A2DP__
#include "av_bt.h"
#include "BTMMIA2DPScr.h"
#include "A2dpSrvGprot.h"
#endif

#ifdef __MMI_AVRCP_SUPPORT__
#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"
#endif

#ifdef __MMI_BT_FM_VIA_SCO__
#include "BthScoPathSrvGProt.h"
#endif

#ifdef __MMI_FM_VIA_A2DP__
mmi_fmrdo_a2dp_struct a2dp_info;
MMI_BOOL bt_success_during_inquiry = MMI_FALSE;
MMI_BOOL fm_a2dp_connected = MMI_FALSE;
#endif

#ifdef __MMI_AVRCP_SUPPORT__
extern U8 mmi_fmrdo_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events key_events);
#endif

#ifdef __FM_RADIO_HW_SCAN__
extern void mdi_fmr_hw_scan_start(U16 start_freq, MMI_BOOL is_step_up, U8 *scan_table, S16 space, void (*callback_func) (void));
extern void mdi_fmr_hw_scan_abort(void);
#endif /* __FM_RADIO_HW_SCAN__ */

static void (*search_all_channels_callback_func) (U8 *signal_band);
#ifndef __MMI_FM_PLUTO_SLIM__
static void mmi_fmrdo_set_locked_key_callback(mmi_frm_key_evt_struct *evt);
#endif
#ifdef __MMI_NCENTER_SUPPORT__
vsrv_ngroup_handle ncenter_fmrdo_ghandle = NULL;
vsrv_notification_handle ncenter_fmrdo_nhandle = NULL;

void mmi_fmrdo_ncenter_add_fm(void);
void mmi_fmrdo_ncenter_callback_handler(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize);
void mmi_fmrdo_ncenter_update_channel(void);
void mmi_fmrdo_ncenter_clear_fm(void);	
#endif

#ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
void(*mmi_fmrdo_preempted_cb_fptr)(void*, U32);
void* mmi_fmrdo_widget_userdata;
#endif 

#ifdef __MMI_BACKGROUND_CALL__
	void mmi_ucm_entry_error_message(void);
#endif

#ifdef __MMI_FM_RADIO_RECORD__
static U64 mmi_fmrdo_get_remain_time(void);
#endif

typedef struct
{
    U16 freq;
    U16 stop_freq;
    MMI_BOOL is_step_up;
} mmi_fmrdo_search_one_struct;

typedef struct
{
    U16 get_signal_count;
    U8 select_count;
    U8 signal_band[FM_BANDWIDTH + 1];
} mmi_fmrdo_search_all_struct;

static mmi_fmrdo_search_all_struct fmrdo_search_all;
static mmi_fmrdo_search_one_struct fmrdo_search_one;
static U16 g_fmrdo_search_cancel_count;
U16 g_fmrdo_entry_from_search_one = MMI_FALSE;
#ifdef __TC01__
/* under construction !*/
#endif/*__TC01__*/
extern mmi_fmrdo_struct g_fmrdo;    /* defined in FMRadioSrc.c */
extern U8 g_fmschd_stop_channel;

#ifdef __MMI_FM_RADIO_RDS__
extern MMI_BOOL g_temp_rds_freq_switch_off;
extern MMI_BOOL g_temp_rds_off;
U16 g_fmrdo_rds_freq_buffer = 0;
#define MAX_RDS_NCENTER_TEXT_SIZE MAX_NAME_INPUT_LEN + 10
extern S32 g_setting_rds_status;
extern S32 g_setting_af_status;
extern S32 g_setting_tp_status;
UI_character_type rds_str_idle[MMI_FMRDO_RDS_PS_NAME_SIZE + MMI_FMRDO_RDS_RT_SIZE + 2];
static void mmi_fmrdo_trim_rds_string_right( UI_character_type * rds_text);
#endif /* __MMI_FM_RADIO_RDS__ */
#ifdef __MMI_FTE_SUPPORT__
extern MMI_BOOL g_fmrdo_search_freq_changed;
#endif
#ifdef __FM_RADIO_HW_SEARCH__
U16 g_temp_start_freq = 0;
#endif/*__FM_RADIO_HW_SEARCH__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_continued
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_continued(S32 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __BT_SPK_VOL_CONTROL__
    /* when FM background hdlr is cleared by other module */
    if (result == MDI_AUDIO_TERMINATED)
    {
        mdi_audio_bt_clear_volume_sync_callback(APP_FMRDO);
    }
#endif /* __BT_SPK_VOL_CONTROL__ */ 
    if (result != MDI_AUDIO_RESUME)
    {
    #ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
        if (mmi_fmrdo_preempted_cb_fptr)
        {
            mmi_fmrdo_preempted_cb_fptr(mmi_fmrdo_widget_userdata, result);
        }
    #endif /* __MMI_VUI_HOMESCREEN_FM_RADIO__ */
    #ifdef __MMI_VUI_LAUNCHER_KEY__
        if (g_fmrdo_srv_preempted_cb)
        {
            g_fmrdo_srv_preempted_cb(g_fmrdo_srv_userdata, result);
        }
    #endif /* __MMI_VUI_LAUNCHER_KEY__ */
        return MMI_FALSE;
    }
    if (g_fmrdo.is_preempted)
    {
        mmi_fmrdo_power_on_check(MMI_TRUE);
		#ifndef __MMI_MAINLCD_96X64__
        if (g_fmrdo.in_main_screen)
        {
            mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_POWER, MMI_FALSE, g_fmrdo.is_power_on, MMI_TRUE);
            if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_POWER)
            {
                g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
                g_fmrdo.is_button_down = MMI_FALSE;
            }
			#ifndef __MMI_FM_PLUTO_SLIM__
            else if (mmi_fmrdo_is_stepping_up() || mmi_fmrdo_is_stepping_down())
            {
                //mdi_fmr_mute(1);
                mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);    /* mute in the begining of step down/up */
            }
			#endif
        }
		#endif /*__MMI_MAINLCD_96X64__*/

        mmi_idle_update_service_area();

    #ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
        if (mmi_fmrdo_preempted_cb_fptr)
        {
            /* result should be MDI_AUDIO_RESUME, this indicates FM Radio is resumed */
            mmi_fmrdo_preempted_cb_fptr(mmi_fmrdo_widget_userdata, result);
        }
    #endif /* __MMI_VUI_HOMESCREEN_FM_RADIO__ */
    #ifdef __MMI_VUI_LAUNCHER_KEY__
        if (g_fmrdo_srv_preempted_cb)
        {
            g_fmrdo_srv_preempted_cb(g_fmrdo_srv_userdata, result);
        }
    #endif /* __MMI_VUI_LAUNCHER_KEY__ */
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_preempted
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_preempted(S32 result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_NOT_READY)
    {
        return;
    }

#if defined(__MMI_FM_RADIO_RECORD__)
    /* Stop FM radio recording, but do not stop playing */
    if ((g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE) &&
        result == MDI_AUDIO_STOP_FM_RECORD)
    {
       
        g_fmrdo.state = FMRDO_STATE_READY;
		/* Display enter file name screen */
        mmi_fmrdo_record_stopped_hdlr();

        return;
    }
    /* Stop FM radio recording, then stop FM radio */
    else if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
        g_fmrdo.state = FMRDO_STATE_READY;
        /* Save file using default name */

    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        if (result == MDI_AUDIO_TERMINATED)
        {
            mmi_fmrdo_entry_save();
        }
        else
    #endif
        mmi_fmrdo_entry_restore_main_screen();
    #if defined (__MMI_FTE_SUPPORT__)
    //    mmi_fmrdo_redraw_disabled_buttons();
    #endif 

        /* record not finish correctly, show the error, and remain FM radio playing */
        if (result != MDI_AUDIO_TERMINATED)
        {
            mmi_fmrdo_record_error_hdlr(result);
            return;
        }
    }
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

    g_fmrdo.is_power_on = MMI_FALSE; /* change state, in order to avoid power off noise */ 

    /* Stop FM Playing */
    mmi_fmrdo_search_frequency_stop();
    mmi_fmrdo_search_all_channels_stop();
#ifdef __MMI_FM_RADIO_RDS__
    if(mmi_fmrdo_rds_is_on())
    {
        mmi_fmrdo_rds_clear();
        mmi_fmrdo_rds_disable();
    }
#endif/*__MMI_FM_RADIO_RDS__*/
    g_fmrdo.is_preempted = MMI_TRUE;
    g_fmrdo.state = FMRDO_STATE_NOT_READY;
	#ifndef __MMI_FM_PLUTO_SLIM__
	mmi_scr_locker_clear_locked_key_callback();
	#endif
	if (result == MDI_AUDIO_TERMINATED)
	{
		 mdi_fmr_power_off();
	}
#ifdef __MMI_FM_VIA_A2DP__
	mmi_fmrdo_bt_stop(MMI_FALSE);
#endif
#ifdef __MMI_AVRCP_SUPPORT__
	mmi_fmrdo_avrcp_clear_cmd_hdlr();
#endif
#ifdef __MMI_BT_FM_VIA_SCO__
	srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
#endif

#ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
    if (mmi_fmrdo_preempted_cb_fptr)
    {
        mmi_fmrdo_preempted_cb_fptr(mmi_fmrdo_widget_userdata, result);
    }
#endif /* #ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__ */ 
    if (g_fmrdo.in_main_screen)
    {
    /* update freqency text color */
    #ifdef __MMI_FM_RADIO_ANIMATION__
    #ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
        if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
    #endif /*__RF_DESENSE_TEST__*/
        {
            mmi_fmrdo_animation_stop();
        }
    #endif /*__MMI_FM_RADIO_ANIMATION__*/ 
	#ifndef __MMI_FM_PLUTO_SLIM__
        if (g_fmrdo.normal_repeat_step_count != 0)
        {
            mmi_fmrdo_redraw_main_frequency(g_fmrdo.step_freq, MMI_TRUE);
        }
        else
	#endif
        {
            mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, MMI_TRUE);
        }
	#ifndef __MMI_MAINLCD_96X64__
        mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_POWER, MMI_FALSE, MMI_FALSE, MMI_TRUE);
	#endif
     #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    #ifndef __MMI_SLIM_IMG_RES__
        mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_SEARCH, MMI_FALSE, MMI_FALSE, MMI_TRUE);
    #endif /* __MMI_SLIM_IMG_RES_ */
    #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

        if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_POWER)
        {
            g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
            g_fmrdo.is_button_down = MMI_FALSE;
        }
    }
    mmi_idle_update_service_area();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_goto_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  channel_index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_goto_channel(U16 channel_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq = g_fmrdo.channel_list.freq[channel_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_VIA_A2DP__
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_GOTO_CHANNEL_ENTRY,freq,fm_a2dp_connected);
#endif
    g_fmrdo.frequency = freq;
    g_fmrdo.channel_index = channel_index;
#ifdef __MMI_FM_RADIO_RDS__
    mmi_fmrdo_rds_clear();
#endif
    if (g_fmrdo.in_main_screen)
    {
        mmi_fmrdo_redraw_main_frequency(freq, MMI_TRUE);
        mmi_fmrdo_redraw_main_channel_tuner(freq);
        mmi_fmrdo_redraw_main_channel_name(0);
    }
    else
    {
        mmi_idle_update_service_area();
    }

    if (g_fmrdo.is_power_on)
    {
        //mdi_fmr_mute(1);
        mdi_fmr_set_freq(freq);
		if (g_fmrdo.mute)
        {
			mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
        }
	#ifdef __MMI_FM_VIA_A2DP__
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
	if (!g_fmrdo.loud_speaker_on)
	{
#endif
    srv_a2dp_set_app_callback(mmi_fmrdo_bt_open_callback);
	if(mmi_a2dp_is_output_to_bt() && !fm_a2dp_connected)
	{
		mmi_fmrdo_change_state_a2dp_connect();
//		av_bt_open_ex((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(),a2dp_info.sample_rate,a2dp_info.is_stereo,
//                            mmi_fmrdo_bt_open_callback,KAL_TRUE);
        srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);
	}
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
	}
#endif
#endif
#ifdef __MMI_FM_VIA_A2DP__
#ifdef __MMI_VUI_LAUNCHER_KEY__
	if (g_fmrdo_srv_search_cb)
	{
		g_fmrdo_srv_search_cb(g_fmrdo_srv_userdata, freq);
	}
#endif 
#endif
	#ifdef __MMI_NCENTER_SUPPORT__
            mmi_fmrdo_ncenter_update_channel();
        #endif
    }
#ifdef __MMI_FM_VIA_A2DP__
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_GOTO_CHANNEL_EXIT,freq,fm_a2dp_connected);
#endif
}

void mmi_fmrdo_goto_next_closest_channel(U16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 freq_diff = -1;
    S32 index = 0;
    S32 smallest = FM_BANDWIDTH;
    S32 smallest_index = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while( index < FM_RADIO_CHANNEL_NUM)
    {
        U16 check_freq = g_fmrdo.channel_list.freq[index];
        if (!check_freq)
        {
            index++;
            continue;
        }
        freq_diff = check_freq - freq;
        if(freq_diff < 0 )
        {
            freq_diff += FM_BANDWIDTH;
        }
        if (freq_diff < smallest)
        {
            smallest = freq_diff;
            smallest_index = index;
        }
        index++;
    }
    
    //MMI_ASSERT(smallest_index != -1);
    if (smallest_index != -1)
    {
        mmi_fmrdo_goto_channel(smallest_index);
    }
}

void mmi_fmrdo_goto_previous_closest_channel(U16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 freq_diff = -1;
    S32 index = 0;
    S32 smallest = FM_BANDWIDTH;
    S32 smallest_index = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while( index < FM_RADIO_CHANNEL_NUM)
    {
        U16 check_freq = g_fmrdo.channel_list.freq[index];
        if (!check_freq)
        {
            index++;
            continue;
        }
        freq_diff = freq - check_freq;
        if(freq_diff < 0 )
        {
            freq_diff += FM_BANDWIDTH;
        }
        if (freq_diff < smallest)
        {
            smallest = freq_diff;
            smallest_index = index;
        }
        index++;
    }
    
    //MMI_ASSERT(smallest_index != -1);
    if (smallest_index != -1)
    {
        mmi_fmrdo_goto_channel(smallest_index);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_set_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  freq        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_set_frequency(U16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 channel_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_VIA_A2DP__
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_SET_FREQUENCY_ENTRY,freq,fm_a2dp_connected);
#endif
#ifdef __MMI_FM_RADIO_RDS__
    if(g_fmrdo.is_power_on && g_fmrdo.rds.rds_setting.is_rds_on && (g_fmrdo.state != FMRDO_STATE_SEARCH_ONE || g_fmrdo.state !=FMRDO_STATE_SEARCH_ALL))
    {
        mmi_fmrdo_rds_clear();
    }
#endif/*__MMI_FM_RADIO_RDS__*/
    g_fmrdo.frequency = freq;
    if ((channel_index = mmi_fmrdo_match_channel_list(freq)) >= 0)
    {
        g_fmrdo.channel_index = channel_index;
    }
    else
    {
        g_fmrdo.channel_index = -1;
    }

    if (g_fmrdo.in_main_screen)
    {
        gdi_layer_lock_frame_buffer();
        mmi_fmrdo_redraw_main_frequency(freq, MMI_TRUE);
        mmi_fmrdo_redraw_main_channel_tuner(freq);
        mmi_fmrdo_redraw_main_channel_name(0);
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    }
    
    if (g_fmrdo.is_power_on)
    {
        mdi_fmr_set_freq(freq);
	#ifdef __MMI_FM_VIA_A2DP__
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
	if (!g_fmrdo.loud_speaker_on)
	{
#endif
        srv_a2dp_set_app_callback(mmi_fmrdo_bt_open_callback);

        if(mmi_a2dp_is_output_to_bt() && !fm_a2dp_connected)
        {
            if(!(g_fmrdo.selected_button == FMRDO_BUTTON_POWER && g_fmrdo.is_power_on))
            {
                mmi_fmrdo_change_state_a2dp_connect();
                srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);
//                av_bt_open_ex((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(),a2dp_info.sample_rate,a2dp_info.is_stereo,
//                            mmi_fmrdo_bt_open_callback,KAL_TRUE);
            }
        }
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
    }
#endif
#endif /*__MMI_FM_VIA_A2DP__*/

#ifdef __MMI_FM_VIA_A2DP__
#ifdef __MMI_VUI_LAUNCHER_KEY__
	if (g_fmrdo_srv_search_cb)
	{
		g_fmrdo_srv_search_cb(g_fmrdo_srv_userdata, freq);
	}
#endif
#endif

        #ifdef __MMI_NCENTER_SUPPORT__
            mmi_fmrdo_ncenter_update_channel();
        #endif
    }
#ifdef __MMI_FM_VIA_A2DP__
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_SET_FREQUENCY_EXIT,freq,fm_a2dp_connected);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_power_on_before_preset_auto_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_power_on_before_preset_auto_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        g_fmrdo.is_power_on = MMI_FALSE;
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */ 
    g_fmrdo.is_preempted = MMI_FALSE;

    /* mute it before searching */
    mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
    if (g_fmrdo.loud_speaker_on)
    {
    #ifdef __MMI_BT_FM_VIA_SCO__
		srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
	#endif
	#ifdef	__MMI_FM_VIA_A2DP__
	mmi_fmrdo_bt_stop(MMI_FALSE);
	#endif
        mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER_BOTH, (mdi_ext_callback) mmi_fmrdo_preempted, NULL);
    }
    else
#endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */ 
    {
        mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER2, (mdi_ext_callback) mmi_fmrdo_preempted, NULL);
    }
    mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback) mmi_fmrdo_continued, NULL);
    g_fmrdo.is_power_on = MMI_TRUE;
    g_fmrdo.state = FMRDO_STATE_READY;
 #ifdef __MMI_FM_RADIO_RDS__
	 if(g_fmrdo.rds.rds_setting.is_rds_on)
     {
     	mmi_fmrdo_rds_enable(g_fmrdo.rds.rds_setting.is_tp_on, g_fmrdo.rds.rds_setting.is_af_on);
	 }
 #endif/*__MMI_FM_RADIO_RDS__*/
	#ifdef __MMI_NCENTER_SUPPORT__
		mmi_fmrdo_ncenter_add_fm();
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_power_on_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  turn_on     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_power_on_check(MMI_BOOL turn_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_VIA_A2DP__
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_POWER_ON_CHECK_ENTRY,turn_on,g_fmrdo.state,mmi_a2dp_is_output_to_bt());
    if (turn_on)
    {
        srv_a2dp_set_app_callback(mmi_fmrdo_bt_open_callback);
    }
    else
    {
        srv_a2dp_delete_app_callback();
    }
#endif
/* If Loud Spekaer ON, Fm will route through Speaker and not through BT. */
	#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
	if (g_fmrdo.loud_speaker_on)
	{
		#ifdef __MMI_BT_FM_VIA_SCO__
        if(turn_on)
        {
			srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
        }
        else
        {
            srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
        }
	#endif
		#ifdef	__MMI_FM_VIA_A2DP__
        mmi_fmrdo_bt_stop(MMI_FALSE);
		#endif
		mmi_fmrdo_power_on(turn_on);
		return;
	}
#endif
#ifdef __MMI_FM_VIA_A2DP__
    if(mmi_a2dp_is_output_to_bt() && turn_on == MMI_TRUE && !fm_a2dp_connected)
    {
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback) mmi_fmrdo_continued, NULL);
        mdi_fmr_get_audio_info((mdi_fmr_audio_info_struct *)&a2dp_info);

        mmi_fmrdo_change_state_a2dp_connect();
        srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);
//		av_bt_open_ex((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(),a2dp_info.sample_rate,a2dp_info.is_stereo,
//						mmi_fmrdo_bt_open_callback,KAL_TRUE);
	}
	else
#endif /*__MMI_FM_VIA_A2DP__*/
	{
		mmi_fmrdo_power_on(turn_on);
	}
#ifdef __MMI_FM_VIA_A2DP__
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_POWER_ON_CHECK_EXIT,turn_on,g_fmrdo.state,mmi_a2dp_is_output_to_bt());
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_power_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  turn_on     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_power_on(MMI_BOOL turn_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_POWER_ON_ENTRY,turn_on,g_fmrdo.state);
    if (!g_fmrdo.is_ready)
    {
        return;
    }

    if ((g_fmrdo.state == FMRDO_STATE_NOT_READY && !turn_on) || ((g_fmrdo.state != FMRDO_STATE_NOT_READY && g_fmrdo.state != FMRDO_STATE_BT_CONNECTING) && turn_on))
    {
        if (!srv_earphone_is_plug_in() && !turn_on)
        {
            mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_FMR);
        }
        g_fmrdo.is_preempted = MMI_FALSE;
        return;
    }

    if (turn_on)
    {
    #ifdef __MMI_BACKGROUND_CALL__
        if (srv_ucm_is_background_call())
        {
            g_fmrdo.is_power_on = MMI_FALSE;
	    mmi_ucm_entry_error_message();
            return;
        }
    #endif /* __MMI_BACKGROUND_CALL__ */ 
        if (mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO))
        {
            g_fmrdo.is_power_on = MMI_FALSE;
        }
        else
        {
        #if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
            if (g_fmrdo.loud_speaker_on)
            {
            #ifdef __MMI_BT_FM_VIA_SCO__
				srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
			#endif
			#ifdef	__MMI_FM_VIA_A2DP__
				mmi_fmrdo_bt_stop(MMI_FALSE);
			#endif
                mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER_BOTH, (mdi_ext_callback) mmi_fmrdo_preempted, NULL);
            }
            else
        #endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */ 
            {
                mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER2, (mdi_ext_callback) mmi_fmrdo_preempted, NULL);
            }
        mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
        g_fmrdo.is_power_on = MMI_TRUE;
		
		#ifdef __MMI_AVRCP_SUPPORT__
			mmi_fmrdo_avrcp_set_cmd_hdlr();
		#endif 

         #ifdef __MMI_NCENTER_SUPPORT__
		if ( !mmi_frm_scrn_is_present(GRP_ID_FMRDO, SCR_ID_FMRDO_MAIN, MMI_FRM_NODE_ALL_FLAG))
        {
	        mmi_fmrdo_ncenter_add_fm();
		}
	 #endif

        if (g_fmrdo.in_main_screen)
        {
            mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, MMI_TRUE);
 #ifndef __MMI_MAINLCD_96X64__
     #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        #ifndef __MMI_SLIM_IMG_RES__
            mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_SEARCH, MMI_FALSE, g_fmrdo.is_search_on, MMI_TRUE);
        #endif /* __MMI_SLIM_IMG_RES_ */
        #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */ 
            mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_POWER, MMI_FALSE, g_fmrdo.is_power_on, MMI_TRUE);
#endif 
        #ifdef __MMI_FM_RADIO_ANIMATION__
        #ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
            if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
        #endif /*__RF_DESENSE_TEST__*/
            {
                mmi_fmrdo_animation_start();
            }
        #endif /* __MMI_FM_RADIO_ANIMATION__ */
        }
        
            mdi_fmr_set_freq(g_fmrdo.frequency);
		    if (g_fmrdo.volume == 0)
		    {
			     g_fmrdo.mute = 1;
			     WriteValueSlim(NVRAM_FMRDO_MUTE, &g_fmrdo.mute, DS_BYTE);
			     g_fmrdo.prev_volume = 0;
		    }
            if (g_fmrdo.mute)
            {
                mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
            }
            else
            {
                mmi_fmrdo_set_volume(g_fmrdo.volume);
            }

        #ifdef __MMI_FM_RADIO_MONO__
            mdi_fmr_set_channel((MMI_BOOL)g_fmrdo.mono);
        #endif 
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback) mmi_fmrdo_continued, NULL);
#ifndef __MMI_FM_PLUTO_SLIM__
            mmi_scr_locker_set_locked_key_callback(mmi_fmrdo_set_locked_key_callback);
#endif
            g_fmrdo.state = FMRDO_STATE_READY;
        #ifdef __MMI_FM_RADIO_RDS__
            if(g_fmrdo.rds.rds_setting.is_rds_on)
            {
               // mmi_fmrdo_rds_clear();
                mmi_fmrdo_rds_enable(g_fmrdo.rds.rds_setting.is_tp_on, g_fmrdo.rds.rds_setting.is_af_on);
            }
        #endif/*__MMI_FM_RADIO_RDS__*/
        }
    }
    else
    {
    #ifdef __MMI_FM_RADIO_RDS__
        /* Konark: Need to ne called before FM power off */
        if(mmi_fmrdo_rds_is_on())
        {
            mmi_fmrdo_rds_clear();
            mmi_fmrdo_rds_disable();
        }
    #endif/*__MMI_FM_RADIO_RDS__*/
        //mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
        mdi_audio_stop_fmr();
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_FMR);	
	#ifdef __MMI_FM_VIA_A2DP__
		mmi_fmrdo_bt_stop(MMI_FALSE);
	#endif
	#ifdef __MMI_AVRCP_SUPPORT__
		mmi_fmrdo_avrcp_clear_cmd_hdlr();
	#endif
	if(g_fmrdo.in_main_screen)
	{
		if(!g_fmrdo.is_power_on)
		{
			mdi_audio_suspend_background_play();
		}
	}

    #ifdef __MMI_FM_RADIO_ANIMATION__
    #ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
        if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
    #endif /*__RF_DESENSE_TEST__*/
        {
            mmi_fmrdo_animation_stop();
        }
    #endif /* __MMI_FM_RADIO_ANIMATION__ */
    #ifdef __MMI_NCENTER_SUPPORT__
	mmi_fmrdo_ncenter_clear_fm();
	#endif
    }
#ifndef __MMI_MAINLCD_96X64__
#if (defined(__MMI_SLIM_IMG_RES__) && !defined(__MMI_FTE_SUPPORT__))
    if (g_fmrdo.in_main_screen)
    {
        mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_STEP_DOWN, MMI_FALSE);
        mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_STEP_UP,MMI_FALSE);
        mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_SEARCH_DOWN, MMI_FALSE);
        mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_SEARCH_UP,MMI_FALSE);
    }
#endif /* __MMI_SLIM_IMG_RES__ */    
#else
	if (g_fmrdo.in_main_screen)
    {
    	mmi_fmrdo_show_main(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK, g_fmrdo.skin_index);
    }
#endif
#ifdef __MMI_FM_VIA_A2DP__
#ifdef __MMI_VUI_LAUNCHER_KEY__
	if(g_fmrdo_srv_preempted_cb)
	{
		g_fmrdo_srv_preempted_cb(g_fmrdo_srv_userdata, g_fmrdo.is_power_on);
	}
#endif /* __MMI_VUI_LAUNCHER_KEY__ */
#endif /* __MMI_FM_VIA_A2DP__ */
    g_fmrdo.is_preempted = MMI_FALSE;
	mmi_fmrdo_update_center_key_status();
    mmi_idle_update_service_area();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_POWER_ON_EXIT,turn_on,g_fmrdo.state);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_before
 * DESCRIPTION
 *  
 * PARAMETERS
 *  turn_on     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_before(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);

#if defined(__MMI_BT_FM_VIA_SCO__)
    mdi_audio_bt_hfp_turn_off();
#endif 

#ifdef __MMI_FM_VIA_A2DP__
	mmi_fmrdo_bt_stop(MMI_FALSE);
#endif

#ifdef __MMI_AVRCP_SUPPORT__
	mmi_bt_avrcp_clear_cmd_hdlr(mmi_fmrdo_bt_avrcp_cmd_hdlr);
#endif

#ifdef __MMI_FM_RADIO_RDS__
    if(mmi_fmrdo_rds_is_on())
    {
        mmi_fmrdo_rds_clear();
        mmi_fmrdo_rds_disable();
        g_temp_rds_off = MMI_TRUE;
    }
#endif/* __MMI_FM_RADIO_RDS__ */
    
    mdi_fmr_evaluate_threshold();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_after
 * DESCRIPTION
 *  
 * PARAMETERS
 *  turn_on     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_after(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_FM_VIA_A2DP__
if(!mmi_a2dp_is_output_to_bt())
{
#endif /*__MMI_FM_VIA_A2DP__*/
    
    if (g_fmrdo.is_power_on != MMI_FALSE)
    {
    if (g_fmrdo.mute)
    {
        mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
    }
    else
    {
        mmi_fmrdo_set_volume(g_fmrdo.volume);
    }
    }
    
    #if defined(__MMI_BT_FM_VIA_SCO__)
        mdi_audio_bt_hfp_turn_on();
    #endif /*__MMI_BT_FM_VIA_SCO__*/

#ifdef __MMI_FM_VIA_A2DP__
}
#endif /*__MMI_FM_VIA_A2DP__*/

#ifdef __MMI_AVRCP_SUPPORT__
	mmi_fmrdo_avrcp_set_cmd_hdlr();
#endif 
#ifdef __MMI_FM_VIA_A2DP__
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
	if (!g_fmrdo.loud_speaker_on)
	{
#endif
    srv_a2dp_set_app_callback(mmi_fmrdo_bt_open_callback);

	if(mmi_a2dp_is_output_to_bt() && !fm_a2dp_connected)
	{
        g_fmrdo.state = FMRDO_STATE_BT_CONNECTING;
        srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);
//		av_bt_open_ex((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(),a2dp_info.sample_rate,a2dp_info.is_stereo,
//                            mmi_fmrdo_bt_open_callback,KAL_TRUE);
	}
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
	}
	else
	{
		if (g_fmrdo.is_power_on != MMI_FALSE)
    	{
		    if (g_fmrdo.mute)
		    {
		        mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
		    }
		    else
		    {
		        mmi_fmrdo_set_volume(g_fmrdo.volume);
		    }
    	}
	}
#endif
#endif /*__MMI_FM_VIA_A2DP__*/

#ifdef __MMI_FM_RADIO_RDS__
    if(g_temp_rds_off)
    {
        if(g_fmrdo.is_power_on)
        {
            mmi_fmrdo_rds_clear();
            mmi_fmrdo_rds_enable(g_fmrdo.rds.rds_setting.is_tp_on, g_fmrdo.rds.rds_setting.is_af_on);
            g_temp_rds_off = MMI_FALSE;
        }
    }
	
#endif/*__MMI_FM_RADIO_RDS__*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_all_before
 * DESCRIPTION
 *  
 * PARAMETERS
 *  turn_on     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_all_before(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_search_before();
    memset(&fmrdo_search_all, 0, sizeof(mmi_fmrdo_search_all_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_all_after
 * DESCRIPTION
 *  
 * PARAMETERS
 *  turn_on     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_all_after(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_fmrdo_search_all_struct *search_p = &fmrdo_search_all;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (search_all_channels_callback_func != NULL)
    {
        /* Stops at the first auto search channel after search */
    #if defined(__MMI_FM_RADIO_FIRST_CHANNEL__)
        MMI_BOOL is_channel_found = MMI_FALSE;

        for (i = 0; i < FM_BANDWIDTH; i++)
        {
            if (FM_SIG_MARK(search_p->signal_band[i]))
            {
                /* Set first channel to play after search */
                mdi_fmr_set_freq((U16) (i + MIN_FM_FREQUENCY));
                g_fmrdo.frequency = i + MIN_FM_FREQUENCY;
                is_channel_found = MMI_TRUE;
                break;
            }
        }

        if (!is_channel_found)
    #endif /* defined(__MMI_FM_RADIO_FIRST_CHANNEL__) */ 
        {
            mdi_fmr_set_freq(g_fmrdo.frequency);
        }

        mmi_idle_update_service_area();

    #ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
        if (mmi_fmrdo_preempted_cb_fptr)
        {
            mmi_fmrdo_preempted_cb_fptr(mmi_fmrdo_widget_userdata, 0);
        }
   #endif /* __MMI_VUI_HOMESCREEN_FM_RADIO__ */

        mmi_fmrdo_search_after();

        search_all_channels_callback_func(search_p->signal_band);
        search_all_channels_callback_func = NULL;
    }
}

#ifdef __FM_RADIO_HW_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_hw_search_frequency_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_freq      [IN]        
 *  is_step_up      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_hw_search_frequency_start(U16 start_freq, MMI_BOOL is_step_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do not let voice go out while searching */
    //mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
    mmi_fmrdo_search_before();
    
    if (g_fmrdo_search_cancel_count > 0)
    {
        g_fmrdo_search_cancel_count--;
    }

    fmrdo_search_one.freq = start_freq;
	#ifndef __MMI_FM_PLUTO_SLIM__
    g_fmrdo.normal_repeat_step_count = 0;
	#endif
    if (is_step_up)
    {
        if (start_freq < MIN_FM_FREQUENCY)
        {
            start_freq = MAX_FM_FREQUENCY;
        }
    }
    else
    {
        if (start_freq > MAX_FM_FREQUENCY)
        {
            start_freq = MIN_FM_FREQUENCY;
        }
    }
    fmrdo_search_one.stop_freq = start_freq;
    fmrdo_search_one.is_step_up = is_step_up;
    #ifdef __TC01__
/* under construction !*/
    #endif
    
    g_fmrdo.state = FMRDO_STATE_SEARCH_ONE;
    mdi_fmr_freq_seek_start(start_freq, (MMI_BOOL)is_step_up, MMI_FALSE, 100, mmi_fmrdo_hw_search_frequency);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_hw_search_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stop_freq           [IN]        Frequency searched
 *  signal_level        [IN]        signal level for frequency
 *  is_valid            [IN]        valid signal level
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_hw_search_frequency(U16 stop_freq, U8 signal_level, MMI_BOOL is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo_search_cancel_count > 0)
    {
        g_fmrdo_search_cancel_count--;
        return;
    }

    if (g_fmrdo.state != FMRDO_STATE_SEARCH_ONE)
    {
        return;
    }
#if 0
#ifdef __MMI_FTE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
    if (g_fmrdo.in_main_screen && g_fmrdo.is_power_on)
    {
        /* don't move this statement below mmi_fmrdo_set_frequency for properly updating subLCD */
        g_fmrdo.state = FMRDO_STATE_READY;
        mmi_fmrdo_set_frequency(stop_freq);
		if (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP || g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN ))
    	{
	    	g_fmrdo_entry_from_search_one = MMI_TRUE;
		}
#ifndef __MMI_MAINLCD_96X64__
#ifdef __MMI_FTE_SUPPORT__
        mmi_fmrdo_redraw_main_push_button(
            FMRDO_BUTTON_STEP_DOWN,MMI_FALSE);
        mmi_fmrdo_redraw_main_push_button(
            FMRDO_BUTTON_STEP_UP,MMI_FALSE);
#endif
#endif
        mmi_fmrdo_exit_hw_seaching_screen(stop_freq);
    #ifdef __MMI_FTE_SUPPORT__
        g_fmrdo_search_freq_changed = MMI_TRUE;
    #endif /* __MMI_FTE_SUPPORT__ */

        mmi_fmrdo_search_after();
	    return;
    }
	
#ifdef __MMI_VUI_LAUNCHER_KEY__
    g_fmrdo.state = FMRDO_STATE_READY;
	kal_prompt_trace(MOD_MMI_MEDIA_APP, "[mtk81132]mmi_fmrdo_hw_search_frequency, line = %d, g_fmrdo.state=%d", __LINE__,g_fmrdo.state);

    if (g_fmrdo_srv_search_cb)
    {
        mmi_fmrdo_set_frequency(stop_freq);
        g_fmrdo_srv_search_cb(g_fmrdo_srv_userdata, stop_freq);
    }
    else
    {
        mmi_fmrdo_set_frequency(fmrdo_search_one.freq);
    }

    mmi_fmrdo_search_after();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_hw_search_all_channels_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_hw_search_all_channels_start(void (*callback_func) (U8 *signal_band))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_search_all_before();


    search_all_channels_callback_func = callback_func;
    g_fmrdo.state = FMRDO_STATE_SEARCH_ALL;

#ifdef __FM_RADIO_HW_SCAN__
    mdi_fmr_hw_scan_start((U16)MIN_FM_FREQUENCY, MMI_TRUE, (U8*)&fmrdo_search_all.signal_band, 100, mmi_fmrdo_hw_scan_finish);
#else 
    /* populate signal band */
    mdi_fmr_freq_seek_start(MIN_FM_FREQUENCY, MMI_TRUE, MMI_TRUE, 100, mmi_fmrdo_hw_search_all_channels);
#endif 
}


#ifdef __FM_RADIO_HW_SCAN__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_hw_scan_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_hw_scan_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 counter;
    mmi_fmrdo_search_all_struct *search_p = &fmrdo_search_all;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.state = FMRDO_STATE_READY;
    
    for (counter = 0; counter < FM_BANDWIDTH; counter++)
    {
        if (search_p->signal_band[counter])
        {
            FM_MARK_SIG(search_p->signal_band[counter]);
        }
    }
    
    mmi_fmrdo_search_all_after();
}


#else /* __FM_RADIO_HW_SCAN__ */ 
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_hw_search_all_channels
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stop_freq           [IN]        Frequency searched
 *  signal_level        [IN]        signal level for frequency
 *  is_valid            [IN]        valid signal level
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_hw_search_all_channels(U16 stop_freq, U8 signal_level, MMI_BOOL is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_search_all_struct *search_p = &fmrdo_search_all;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state != FMRDO_STATE_SEARCH_ALL)
    {
        return;
    }

    if (MMI_TRUE == is_valid)
    {
        search_p->signal_band[stop_freq - MIN_FM_FREQUENCY] = signal_level;
    }

    if (stop_freq == MAX_FM_FREQUENCY || stop_freq <= g_temp_start_freq)
    {
        g_fmrdo.state = FMRDO_STATE_READY;
        mmi_fmrdo_hw_search_all_finish();
        g_temp_start_freq = 0;
    }
    else
    {
        g_temp_start_freq = stop_freq + 1;
        mdi_fmr_freq_seek_start(g_temp_start_freq, (MMI_BOOL)1, MMI_TRUE, 100, mmi_fmrdo_hw_search_all_channels);
    }
}
#endif /* __FM_RADIO_HW_SCAN__ */ 

#else /* FM_RADIO_HW_SEARCH */ 
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_frequency_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_freq      [IN]        
 *  is_step_up      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_frequency_start(U16 start_freq, MMI_BOOL is_step_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_search_before();

    fmrdo_search_one.freq = start_freq;
    if (!is_step_up)
    {
        if (start_freq > MIN_FM_FREQUENCY)
        {
            fmrdo_search_one.stop_freq = start_freq - 1;
        }
        /* case when search is started from 107.9 MHz */

        else if (start_freq == MIN_FM_FREQUENCY)
        {
            fmrdo_search_one.stop_freq = MAX_FM_FREQUENCY;
        }
        else
        {
            start_freq = MAX_FM_FREQUENCY;
        }
    }
    else
    {
        if (start_freq < MAX_FM_FREQUENCY)
        {
            fmrdo_search_one.stop_freq = start_freq + 1;
        }
        else
        {
            fmrdo_search_one.stop_freq = MIN_FM_FREQUENCY;
        }
    }
    fmrdo_search_one.freq = start_freq;
    fmrdo_search_one.is_step_up = is_step_up;
#ifdef __TC01__
/* under construction !*/
#endif
    g_fmrdo.state = FMRDO_STATE_SEARCH_ONE;

    /* start valid stop test */
    mdi_fmr_check_is_valid_stop(fmrdo_search_one.stop_freq, (MMI_BOOL)is_step_up, mmi_fmrdo_search_frequency);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_valid        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_frequency(MMI_BOOL is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo_search_cancel_count > 0)
    {
        g_fmrdo_search_cancel_count--;
        return;
    }
    if (g_fmrdo.state != FMRDO_STATE_SEARCH_ONE)
    {
        return;
    }

    if (!is_valid && fmrdo_search_one.freq != fmrdo_search_one.stop_freq)
    {
        /* update frequency */
        if (fmrdo_search_one.is_step_up)
        {
            if (fmrdo_search_one.stop_freq < MAX_FM_FREQUENCY)
            {
                fmrdo_search_one.stop_freq++;
            }
            else
            {
                fmrdo_search_one.stop_freq = MIN_FM_FREQUENCY;
            }
        }
        else
        {
            if (fmrdo_search_one.stop_freq > MIN_FM_FREQUENCY)
            {
                fmrdo_search_one.stop_freq--;
            }
            else
            {
                fmrdo_search_one.stop_freq = MAX_FM_FREQUENCY;
            }
        }

        /* update display */
        if (g_fmrdo.in_main_screen)
        {
            mmi_fmrdo_redraw_main_frequency(fmrdo_search_one.stop_freq, MMI_TRUE);
            mmi_fmrdo_redraw_main_channel_tuner(fmrdo_search_one.stop_freq);
        }

        /* test valid stop again */
        mdi_fmr_check_is_valid_stop(fmrdo_search_one.stop_freq, (MMI_BOOL)fmrdo_search_one.is_step_up, mmi_fmrdo_search_frequency);
    }
    else
    {
        /* don't move this statement below mmi_fmrdo_set_frequency for properly updating subLCD */
        g_fmrdo.state = FMRDO_STATE_READY;
        fmrdo_search_one.freq = fmrdo_search_one.stop_freq;
        mmi_fmrdo_set_frequency(fmrdo_search_one.freq);
        if (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP || g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN ))
    	{
	        g_fmrdo_entry_from_search_one = MMI_TRUE;
	    }
		#ifndef __MMI_FM_PLUTO_SLIM__
        g_fmrdo.normal_repeat_step_count = 0;
		#endif
    if (g_fmrdo.in_main_screen)
    {
    #ifdef __MMI_FM_RADIO_ANIMATION__
    #ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
        if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
    #endif /*__RF_DESENSE_TEST__*/
        {
            mmi_fmrdo_animation_start();
        }
    #endif /*__MMI_FM_RADIO_ANIMATION__*/
    } 
    #ifdef __MMI_FTE_SUPPORT__
        /*if(g_fmrdo.is_button_down)
        {
            g_fmrdo.is_button_down = MMI_FALSE;
        }*/
        g_fmrdo_search_freq_changed = MMI_TRUE;
        if (g_fmrdo.in_main_screen)
        {
            if(fmrdo_search_one.is_step_up)
            {
                mmi_fmrdo_redraw_main_push_button(
                        FMRDO_BUTTON_STEP_UP,
                        (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP)));
                        mmi_fmrdo_redraw_main_push_button(
                        FMRDO_BUTTON_STEP_DOWN,
                        (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN)));
            }
            else
            {
                mmi_fmrdo_redraw_main_push_button(
                        FMRDO_BUTTON_STEP_DOWN,
                        (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN)));
                        mmi_fmrdo_redraw_main_push_button(
                        FMRDO_BUTTON_STEP_UP,
                        (MMI_BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP)));
            }

        }
    #endif /* __MMI_FTE_SUPPORT__ */
        mmi_fmrdo_search_after();
#ifdef __MMI_VUI_LAUNCHER_KEY__
    if (g_fmrdo_srv_search_cb)
    {
        g_fmrdo_srv_search_cb(g_fmrdo_srv_userdata, fmrdo_search_one.freq);
    }
#endif
}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_all_channels_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_all_channels_start(void (*callback_func) (U8 *signal_band))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_search_all_before();

    search_all_channels_callback_func = callback_func;
    g_fmrdo.state = FMRDO_STATE_SEARCH_ALL;

    /* init search_p */
    memset(&fmrdo_search_all, 0, sizeof(mmi_fmrdo_search_all_struct));

    /* populate signal band */
    mdi_fmr_get_signal_level(MIN_FM_FREQUENCY, MMI_TRUE, mmi_fmrdo_search_all_channels);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_all_channels
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signal_level        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_all_channels(U8 signal_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_search_all_struct *search_p = &fmrdo_search_all;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state != FMRDO_STATE_SEARCH_ALL)
    {
        return;
    }

    search_p->signal_band[search_p->get_signal_count++] = signal_level;
    if (search_p->get_signal_count < FM_BANDWIDTH)
    {
        mdi_fmr_get_signal_level((U16) (MIN_FM_FREQUENCY + search_p->get_signal_count), MMI_TRUE, mmi_fmrdo_search_all_channels); /* populate signal band */
    }
    else
    {
        g_fmrdo.state = FMRDO_STATE_READY;
        mmi_fmrdo_hw_search_all_finish();
    }
}

#endif /* __FM_RADIO_HW_SEARCH__ */ 
#ifndef __MMI_FM_RADIO_PRESET_TOP_N__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_find_best_frequency_in_sub_band
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sub_band        [IN]     First channel in sub band
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_fmrdo_find_best_frequency_in_sub_band(U8 *sub_band, U16 sub_band_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 signal_level;
    U8 max_signal_level = 1;
    S16 i;
    S16 index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sub_band_width; i++)
    {
        if (!FM_SIG_MARK(sub_band[i]))
        {
            signal_level = FM_SIG_LVL(sub_band[i]);
            if (signal_level >= max_signal_level)
            {
                index = i;
                max_signal_level = signal_level;
            }
        }
    }

    return index;
}
#endif/*__MMI_FM_RADIO_PRESET_TOP_N__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_hw_search_all_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_hw_search_all_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;

#if defined(__MMI_FM_RADIO_PRESET_TOP_N__)
    S16 index;
    U8  level, max_signal_level;
#else /* defined(__MMI_FM_RADIO_PRESET_TOP_N__) */ 
    U16 offset, avaliable_sub_band_count;
    U8  sub_band_mask[(FM_SUB_BAND_NUM + 7) / 8 ];
#endif /* defined(__MMI_FM_RADIO_PRESET_TOP_N__) */ 
    mmi_fmrdo_search_all_struct *search_p = &fmrdo_search_all;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Find out the Top-N strongest signal channel */
#if defined(__MMI_FM_RADIO_PRESET_TOP_N__)
    for (i = 0; i < FM_RADIO_CHANNEL_NUM; i++)
    {
        max_signal_level = 0;
        index = -1;

        for (j = 0; j < FM_BANDWIDTH; j++)
        {
            if (!FM_SIG_MARK(search_p->signal_band[j]))
            {
                level = FM_SIG_LVL(search_p->signal_band[j]);
                if (level > max_signal_level)
                {
                    index = j;
                    max_signal_level = level;
                }
            }
        }

        if (index >= 0)
        {
            FM_MARK_SIG(search_p->signal_band[index]);
        }
        else
        {
            goto finished;
        }
    }

#else /* defined(__MMI_FM_RADIO_PRESET_TOP_N__) */ 
    /* search until no available frequency or FM_SUB_BAND_NUM frequencies are found */
    avaliable_sub_band_count = FM_SUB_BAND_NUM;
    memset(sub_band_mask, 0, sizeof(sub_band_mask));
    do
    {
        S16 index;

        for (offset = i = 0; i < FM_SUB_BAND_NUM; i++)
        {
            if (!FM_SUB_MARK(sub_band_mask[i / 8], (i % 8)))
            {
            	   if((offset+FM_SUB_BANDWIDTH)>MAX_FM_FREQUENCY)
            	   {
                	index = mmi_fmrdo_find_best_frequency_in_sub_band(&search_p->signal_band[offset], 
						MAX_FM_FREQUENCY-offset+1);
            	   }
		   else
		   {
		   	index = mmi_fmrdo_find_best_frequency_in_sub_band(&search_p->signal_band[offset], FM_SUB_BANDWIDTH);
		   }
		   
                if (index >= 0)
                {
                    j = offset + index;
                    FM_MARK_SIG(search_p->signal_band[j]);
                    search_p->select_count++;
                    if (search_p->select_count == FM_SUB_BAND_NUM)
                    {
                        goto finished;
                    }
                }
                else
                {
                    FM_MARK_SUB(sub_band_mask[i / 8], (i % 8));
                    avaliable_sub_band_count--;
                }
            }
            offset += FM_SUB_BANDWIDTH;
        }
    } while (avaliable_sub_band_count > 0);
#endif /* defined(__MMI_FM_RADIO_PRESET_TOP_N__) */ 

  finished:
    mmi_fmrdo_search_all_after();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_frequency_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_frequency_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_ready && g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
    {
        g_fmrdo_search_cancel_count++;
#ifdef __FM_RADIO_HW_SEARCH__
        mdi_fmr_freq_seek_abort();
#endif 
        /* mdi_fmr_cancel_checking_is_valid_stop(); */
        /* don't move this statement below mmi_fmrdo_set_frequency for properly updating subLCD */
        g_fmrdo.state = FMRDO_STATE_READY;
        mmi_fmrdo_set_frequency(fmrdo_search_one.freq);
        mmi_fmrdo_search_after();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_all_channels_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_search_all_channels_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_ready && g_fmrdo.state == FMRDO_STATE_SEARCH_ALL)
    {
    #ifdef __FM_RADIO_HW_SEARCH__
    #ifdef __FM_RADIO_HW_SCAN__
        mdi_fmr_hw_scan_abort();
    #else 
        mdi_fmr_freq_seek_abort();
    #endif /* __FM_RADIO_HW_SCAN__ */
                g_temp_start_freq = 0;
    #else /* FM_RADIO_HW_SEARCH */ 
        mdi_fmr_cancel_getting_signal_level();
    #endif /* __FM_RADIO_HW_SEARCH__ */ 
    
        mdi_fmr_set_freq(g_fmrdo.frequency);

        search_all_channels_callback_func = NULL;
        g_fmrdo.state = FMRDO_STATE_READY;
        mmi_frm_scrn_close(GRP_ID_FMRDO, SCR_ID_FMRDO_SEARCHING);
        mmi_fmrdo_search_after();
    }
}

#if defined(__MMI_FM_RADIO_RECORD__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_start_record
 * DESCRIPTION
 *  Start to record FM radio
 * PARAMETERS
 *  filename        [IN]        Name of file to record
 *  format          [IN]        Format for recording
 *  quality         [IN]        Quality of recording
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_start_record(UI_string_type filename, U8 format, U8 quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_audio_rec_param_struct rec_param;
    MDI_AUDIO_REC_QUALITY_ENUM mdi_quality;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FM_QUALITY_LOW == quality)
    {
        mdi_quality = MDI_AUDIO_REC_QUALITY_LOW;
    }
    else
    {
        mdi_quality = MDI_AUDIO_REC_QUALITY_HIGH;
    }
    mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_FMR, mdi_quality, &rec_param);
	if (mmi_fmrdo_get_remain_time() == 0)
	{
	   result = MDI_AUDIO_DISC_FULL;
	}
	else
	{
    	result = mdi_fmr_start_record(filename, rec_param.format, MDI_AUDIO_REC_QUALITY_AUTO);
	}
    if (result == MDI_AUDIO_SUCCESS)
    {
        g_fmrdo.state = FMRDO_STATE_RECORD;
		#ifdef __MMI_FM_RADIO_RDS__
			if(mmi_fmrdo_rds_is_on())
			{
				mmi_fmrdo_rds_clear_before_entry_record();
			}
		#endif/* __MMI_FM_RADIO_RDS__ */
        mmi_fmrdo_entry_main_record_screen();
        mmi_fmrdo_util_init_duration();
        mmi_fmrdo_util_start_duration();
    }
    else
    {
        mmi_fmrdo_record_error_hdlr(result);
        mmi_fmrdo_util_fs_check_file((U16 *)filename);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_remain_time
 * DESCRIPTION
 *  This function will return remain time (For checking before sending record request)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U64 mmi_fmrdo_get_remain_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  quality;
    U64 remain_time, remain_size;
    S32 rate = 0;
    U8 drive[32];
    FS_DiskInfo diskinfo;
    S16 ret;
    mdi_audio_rec_param_struct rec_param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* Get the quality */
    quality = g_fmrdo.rec.quality;

	/* Get record bit rate */
    mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_FMR, (MDI_AUDIO_REC_QUALITY_ENUM)quality, &rec_param);
	rate = rec_param.byte_rate;

    /* Get disk size */
    kal_wsprintf((U16*) drive, "%c:\\", g_fmrdo.rec.drive);
    ret = FS_GetDevStatus(g_fmrdo.rec.drive, FS_FEATURE_STATE_ENUM);
    if (ret < FS_NO_ERROR)
    {
        remain_size = 0;
    }
    else
    {
        ret = FS_GetDiskInfo((U16*) drive, &diskinfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        if (ret >= FS_NO_ERROR)
        {
            remain_size =
                diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
        }
        else
        {
            remain_size = 0;
        }
    }

    /* Caculate remain time (in seconds) */
    remain_time = (U64) (remain_size / rate);

    return remain_time;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_fs_check_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_util_fs_check_file(U16 *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    U32 file_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = FS_Open(file, FS_READ_ONLY);
    if (handle >= FS_NO_ERROR)
    {
        FS_GetFileSize(handle, &file_size);
        FS_Close(handle);
    #if defined (__MTK_TARGET__)     
        if (file_size == 0)
        {
            FS_Delete((const WCHAR*)file);
            return MMI_FALSE;
        }
        else
    #endif
        {
            return MMI_TRUE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_stop_record
 * DESCRIPTION
 *  Stop record FM radio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_stop_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* State will update in mmi_fmrdo_preempted() when call back */
    if ((result = mdi_fmr_stop_record()) != MDI_AUDIO_SUCCESS)
    {
        /* No reason not stop, error Handling Here. */
        g_fmrdo.state = FMRDO_STATE_READY;
        mmi_fmrdo_entry_restore_main_screen();
        mmi_fmrdo_record_error_hdlr(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_stop_record_on_exit
 * DESCRIPTION
 *  Always stop FM radio record when exit the main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_stop_record_on_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {
        if ((result = mdi_fmr_stop_record()) != MDI_AUDIO_SUCCESS)
        {
            /* No reason not stop, error Handling Here. */
            g_fmrdo.state = FMRDO_STATE_READY;
            mmi_fmrdo_record_error_hdlr(result);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_pause_record
 * DESCRIPTION
 *  Pause record FM radio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_pause_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_RECORD)
    {
        result = mdi_fmr_pause_record();

        mmi_fmrdo_util_stop_duration();
        if (result == MDI_AUDIO_SUCCESS)
        {
            g_fmrdo.state = FMRDO_STATE_RECORD_PAUSE;
            mmi_fmrdo_entry_main_pause_screen();
        }
        else
        {
            g_fmrdo.state = FMRDO_STATE_READY;

            mmi_fmrdo_entry_restore_main_screen();
            mmi_fmrdo_record_error_hdlr(result);
        }

        /* clear key events to prevent external queue overflow */
        ClearKeyEvents();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_resume_record
 * DESCRIPTION
 *  Resume record FM radio from pause state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_resume_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
    {

        result = mdi_fmr_resume_record();
        if (result == MDI_AUDIO_SUCCESS)
        {
            g_fmrdo.state = FMRDO_STATE_RECORD;

            mmi_fmrdo_util_start_duration();
            
            // TODO: han shu ming, function name?
            #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
                mmi_fmrdo_entry_main_record_screen();
            #endif
    
        #ifndef __MMI_FTE_SUPPORT__
            mmi_fmrdo_entry_main_record_screen();
        #endif 
        }
        else
        {
            g_fmrdo.state = FMRDO_STATE_READY;

            mmi_fmrdo_entry_restore_main_screen();
            mmi_fmrdo_record_error_hdlr(result);
        }

        /* clear key events to prevent external queue overflow */
        ClearKeyEvents();
    }
}
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#ifdef __MMI_FM_RADIO_RDS__

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_rds_enable
 * DESCRIPTION
 *  Set Callback handler to get interrupt indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rds_enable(MMI_BOOL tp_status,MMI_BOOL af_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_fmrdo.state==FMRDO_STATE_SEARCH_ONE || g_fmrdo.state == FMRDO_STATE_SEARCH_ALL)
    {
        return;
    }
    if(g_fmrdo.rds.rds_setting.is_rds_on && g_fmrdo.is_power_on && !mmi_fmrdo_rds_is_on())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_ENABLE,af_status,tp_status);    
        mdi_fmr_rds_enable(mmi_fmrdo_rds_callback, af_status, tp_status, NULL);
        mdi_fmr_rds_set_buffer((U16*) g_fmrdo.rds.radio_text, (U16*) g_fmrdo.rds.prog_name,&g_fmrdo_rds_freq_buffer, &g_fmrdo_rds_freq_buffer );
        g_fmrdo.rds.status_mask = g_fmrdo.rds.status_mask | FMRDO_RDS_ON;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_rds_disable
 * DESCRIPTION
 *  Set Callback handler to get interrupt indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_fmrdo_rds_disable(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(g_fmrdo.is_power_on);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_DISABLE);
    mdi_fmr_rds_disable();
    mdi_fmr_rds_reset_buffer();
    g_fmrdo.rds.status_mask = g_fmrdo.rds.status_mask & RESET_ALL;
    if(g_fmrdo.in_main_screen)
    {
        mmi_fmrdo_rds_redraw_main_text();
        mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
        mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_TP);
        mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_AF);
		mmi_fmrdo_redraw_main_channel_name(0);
    }
	#ifdef __MMI_NCENTER_SUPPORT__
		mmi_fmrdo_ncenter_update_channel();
	#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_is_fmrdo_rds_on
 * DESCRIPTION
 *  Set Callback handler to get interrupt indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

MMI_BOOL mmi_fmrdo_rds_is_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_fmrdo.rds.status_mask & FMRDO_RDS_ON)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_IS_ON_TRUE);
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_IS_ON_FALSE);
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_rds_set_af_and_tp_setting
 * DESCRIPTION
 *  Set Callback handler to get interrupt indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rds_set_tp_and_af_setting(MMI_BOOL tp_status , MMI_BOOL af_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*reset tp and af flag*/
    /* Konark: use ~ instead of ! */
	if(g_fmrdo.rds.rds_setting.is_tp_on != g_setting_tp_status)
	{
		g_fmrdo.rds.status_mask &= ~(TP_RECIEVE);
	}
	else if(g_fmrdo.rds.rds_setting.is_af_on != g_setting_af_status)
	{
		g_fmrdo.rds.status_mask &= ~(AF_RECIEVE);
	}
	else
    {
        g_fmrdo.rds.status_mask &= ~(TP_RECIEVE|AF_RECIEVE);
	}
    if(mmi_fmrdo_rds_is_on())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_SET_TP_AF_SETTING,af_status,tp_status);
        mdi_fmr_rds_af_tp_setting(af_status, tp_status);
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_start_polling_RDS_log
 * DESCRIPTION
 *  Need to poll for RDS events
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_start_polling_RDS_log(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_fmr_rds_poll_rds_event_rds() == MDI_AUDIO_SUCCESS)
    {
        gui_start_timer(200, mmi_fmrdo_start_polling_RDS_log);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_rds_update_idle_check
 * DESCRIPTION
 *  Check current RDS text with incoming text for updating idle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rds_update_idle_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	UI_string_type str;
	const S32 cntx_size = sizeof(rds_str_idle);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if((mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") == 0) && (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") == 0))
	{
		memset(rds_str_idle, 0, cntx_size);
	}
    if(mmi_fmrdo_rds_is_on() && g_fmrdo.is_power_on)
    {
        str = mmi_fmrdo_rds_get_rds_text();
	}
	if(mmi_ucs2cmp((CHAR *)rds_str_idle, (CHAR *)str) != 0)
	{
		mmi_ucs2cpy((CHAR *)rds_str_idle, (CHAR *)str);
	}
	else
	{
		if(mmi_ucs2cmp((CHAR *)str, (CHAR *)"") != 0)
		{
			MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_REDRAW_MAIN_TEXT_BOTH_STRINGS_SAME);
			return;
		}
	}
	mmi_idle_update_service_area();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_set_preempted_callback
 * DESCRIPTION
 *  Set Callback handler to get interrupt indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rds_callback(mdi_rds_event_struct *buffer, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.frequency != buffer->freq)
    {
        return;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_CALLBACK_ENTRY);
    if(mmi_fmrdo_rds_is_on())
    {
        switch(buffer->event)
        {
        case MDI_RDS_EVENT_FLAGS:
            switch(buffer->flag)
            {
            case MDI_RDS_FLAG_IS_TP:
                if(g_fmrdo.rds.rds_setting.is_tp_on && g_fmrdo.state!= FMRDO_STATE_SEARCH_ONE && (g_fmrdo.state!= FMRDO_STATE_RECORD || g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE))
                {
                /*update flag for tp info recieved bit should be one*/
                   if(buffer->data[0] == 1)
                    {
               		g_fmrdo.rds.status_mask = g_fmrdo.rds.status_mask | TP_RECIEVE;
               		if(g_fmrdo.in_main_screen  && !g_fmrdo.normal_repeat_step_count)
                		{
				    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_TP);
               		        mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);    
               		}
               		}
                    else
                    {
                        g_fmrdo.rds.status_mask &= (~TP_RECIEVE);
               		    if(g_fmrdo.in_main_screen  && !g_fmrdo.normal_repeat_step_count)
                		{
				            mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_TP);
               		        mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);    
                        }

                    }
                }
				 		MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_CALLBACK_FLAG_TP_RECEIVED);
               
				break;
			case MDI_RDS_FLAG_TEXT_AB:
                if (g_fmrdo.rds.rds_setting.is_rds_on && g_fmrdo.state != FMRDO_STATE_SEARCH_ONE)
                {
                    if(mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") != 0)
                    {
                        mmi_ucs2cpy((CHAR *) g_fmrdo.rds.radio_text, (CHAR *) L"");
                        /*g_fmrdo.rds.radio_text = NULL;*/
                        /*update flag for RT not recieved*/
                        g_fmrdo.rds.status_mask = g_fmrdo.rds.status_mask & (~RT_RECIEVE);
                        if(g_fmrdo.in_main_screen  && !g_fmrdo.normal_repeat_step_count)
                        {
                            mmi_fmrdo_rds_redraw_main_text();
                            mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
                        }
                    }
				#ifdef __MMI_NCENTER_SUPPORT__
					mmi_fmrdo_ncenter_update_channel();
				#endif
				    mmi_fmrdo_rds_update_idle_check();
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_CALLBACK_FLAG_RDO_TXT_RECEIVED);
                }
				break;
				
			default:
				break;
			}
			break;

		case MDI_RDS_EVENT_PROGRAMNAME:
			if (g_fmrdo.rds.rds_setting.is_rds_on && g_fmrdo.state !=FMRDO_STATE_SEARCH_ONE)
            {
                g_fmrdo.rds.prog_name[MMI_FMRDO_RDS_PS_NAME_SIZE - 1] = '\0';
                mmi_fmrdo_trim_rds_string_right(g_fmrdo.rds.prog_name);
				
				/*g_fmrdo.rds.prog_name = buffer->data;*/
				/*update flag for programme name recieved*/
                g_fmrdo.rds.status_mask = g_fmrdo.rds.status_mask | PS_RECIEVE;
		    	if(g_fmrdo.in_main_screen  && !g_fmrdo.normal_repeat_step_count)
                {
                    mmi_fmrdo_rds_redraw_main_text();
                    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
                }
			#ifdef __MMI_NCENTER_SUPPORT__
				mmi_fmrdo_ncenter_update_channel();
			#endif
				mmi_fmrdo_rds_update_idle_check();
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_CALLBACK_FLAG_PRG_NAME_RECEIVED);
			}
			break;
	
		case MDI_RDS_EVENT_LAST_RADIOTEXT:
			if (g_fmrdo.rds.rds_setting.is_rds_on && g_fmrdo.state != FMRDO_STATE_SEARCH_ONE)
            {
                g_fmrdo.rds.radio_text[MMI_FMRDO_RDS_RT_SIZE] = '\0';
                mmi_fmrdo_trim_rds_string_right(g_fmrdo.rds.radio_text);
				/*g_fmrdo.rds.radio_text=buffer->data;*/
				/*update flag for radio_text recieved recieved*/
                g_fmrdo.rds.status_mask = g_fmrdo.rds.status_mask | RT_RECIEVE;
                if(g_fmrdo.in_main_screen  && !g_fmrdo.normal_repeat_step_count)
                {
                    mmi_fmrdo_rds_redraw_main_text();
                    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
                }
			#ifdef __MMI_NCENTER_SUPPORT__
				mmi_fmrdo_ncenter_update_channel();
			#endif
				mmi_fmrdo_rds_update_idle_check();
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_CALLBACK_FLAG_FULL_RDO_TXT_RECEIVED);
            }
			break;
	
		case MDI_RDS_EVENT_AF:
             if (g_fmrdo.rds.rds_setting.is_af_on && g_fmrdo.state!= FMRDO_STATE_SEARCH_ONE && (g_fmrdo.state!= FMRDO_STATE_RECORD || g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE))
             {
		        /*update flag for af recieved*/
                if(g_fmrdo.frequency != g_fmrdo_rds_freq_buffer)
                {
                    g_fmrdo.frequency = g_fmrdo_rds_freq_buffer;
                    mmi_fmrdo_set_frequency(g_fmrdo.frequency);
                    /* Konark: Update main frequency and channel name only if frequency changed 
                     * in that case RDS text and prog name will be overwritten */
                    mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, MMI_TRUE);
                    mmi_fmrdo_redraw_main_channel_name(0);
                }
		        g_fmrdo.rds.status_mask = g_fmrdo.rds.status_mask | AF_RECIEVE;
                if(g_fmrdo.in_main_screen  && !g_fmrdo.normal_repeat_step_count)
                {
                    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
                    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_AF);
                }
            }
            #ifdef __MMI_NCENTER_SUPPORT__
				mmi_fmrdo_ncenter_update_channel();
			#endif
            mmi_fmrdo_rds_update_idle_check();
			MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_CALLBACK_FLAG_AF_EVENT_RECEIVED);
			break;
	
      case MDI_RDS_EVENT_AF_LIST:
      if (g_fmrdo.rds.rds_setting.is_af_on && g_fmrdo.state!= FMRDO_STATE_SEARCH_ONE && (g_fmrdo.state!= FMRDO_STATE_RECORD || g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE))
      {
			/*update flag for af recieved*/
           g_fmrdo.rds.status_mask = g_fmrdo.rds.status_mask | AF_RECIEVE;
           if(g_fmrdo.in_main_screen  && !g_fmrdo.normal_repeat_step_count)
           {
               mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
               mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_AF);
           }
      }
       
			MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_CALLBACK_FLAG_AF_EVENT_RECEIVED);
			break;	

            
		case MDI_RDS_EVENT_TAON:
            /*update flag for freq_switch on*/
            if (g_fmrdo.rds.rds_setting.is_tp_on && g_fmrdo.state!= FMRDO_STATE_SEARCH_ONE && (g_fmrdo.state!= FMRDO_STATE_RECORD || g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE))
            {
                g_fmrdo.rds.status_mask = g_fmrdo.rds.status_mask | FREQ_SWITCH;
                /*extract freq and update g_fmrdo.frequency */
                g_fmrdo.frequency = g_fmrdo_rds_freq_buffer;
                if(g_fmrdo.in_main_screen  && !g_fmrdo.normal_repeat_step_count)
           		{
                    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
                    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_TP);
                    if (!(g_fmrdo.rds.status_mask & (RT_RECIEVE | PS_RECIEVE)))
                    {
                    mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, MMI_TRUE);
                    mmi_fmrdo_redraw_main_channel_name(0);
                    }
                }
            }
            #ifdef __MMI_NCENTER_SUPPORT__
				mmi_fmrdo_ncenter_update_channel();
			#endif
            mmi_fmrdo_rds_update_idle_check();
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_CALLBACK_FLAG_TA_ON_EVENT_RECEIVED);
            break;
	
		case MDI_RDS_EVENT_TAON_OFF:
            if(g_fmrdo.rds.rds_setting.is_tp_on && g_fmrdo.state!= FMRDO_STATE_SEARCH_ONE && (g_fmrdo.state!= FMRDO_STATE_RECORD || g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE))
            {           		
                g_fmrdo.rds.status_mask = g_fmrdo.rds.status_mask & (~FREQ_SWITCH);
                /*update flag for freq_switch off and update g_fmrdo.frequency.*/
                g_fmrdo.frequency = *(buffer->data);
                if(g_fmrdo.in_main_screen  && !g_fmrdo.normal_repeat_step_count)
                {
                    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
                    mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_TP);
                    mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, MMI_TRUE);
                }
            }
            #ifdef __MMI_NCENTER_SUPPORT__
				mmi_fmrdo_ncenter_update_channel();
			#endif
            mmi_fmrdo_rds_update_idle_check();
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_CALLBACK_FLAG_TA_OFF_EVENT_RECEIVED);
			break;
			
		case MDI_RDS_EVENT_RDS:
		    gui_start_timer(200, mmi_fmrdo_start_polling_RDS_log);
		    break;
		case MDI_RDS_EVENT_NO_RDS:
		    mmi_fmrdo_rds_clear();
		    break;
		default:
		    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_FMRDO_RDS_CALLBACK_FLAG_NO_EVENT_RECEIVED);
	    break;
		}
	}
	else
	{
		MMI_ASSERT(0);
	}
return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_trim_rds_string_right
 * DESCRIPTION
 *  removes the trailing white spaces from the RDS text
 * PARAMETERS
 *  rds_text 
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_fmrdo_trim_rds_string_right( UI_character_type * rds_text)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    S32 length;
    U16 i = 0;
    U16 *p = rds_text;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Get the length of the string */
    length = mmi_ucs2strlen((CHAR *)rds_text);

    /* move the pointer to the end of the string */
    while( i < length )
    {
        p++;
        i++;
    }
    
    p--;

    /* if encounter white space, replace it with NULL*/
    while( length > 0 )
    {
        if( *p == 32)   /* compare with the ASCII of blank */
        {
            *p = '\0';
             p--;
             length--;
        }

        else
        {
            break;
        }
    }
}

#endif/*__MMI_FM_RADIO_RDS__*/

#ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_set_preempted_callback
 * DESCRIPTION
 *  Set Callback handler to get interrupt indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_set_preempted_callback(void* userdata, void(*callback)(void*, U32))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_preempted_cb_fptr = callback;
    mmi_fmrdo_widget_userdata = userdata;
}
#endif /* __MMI_VUI_HOMESCREEN_FM_RADIO__ */ 

#ifndef __MMI_FM_PLUTO_SLIM__

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_set_locked_key_callback
 * DESCRIPTION
 *  Set Callback handler to handle volume key event when screen is locked
 * PARAMETERS
 *  mmi_frm_key_evt_struct
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_set_locked_key_callback(mmi_frm_key_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    U8 key_code = key_evt->key_code;
    U8 key_type = key_evt->key_type;
	if ((g_fmrdo.state == FMRDO_STATE_READY) || (g_fmrdo.state == FMRDO_STATE_RECORD) ||(g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE) )
	{
		if (key_code == KEY_VOL_UP && key_type == KEY_EVENT_UP)
		{
			mmi_fmrdo_inc_volume();
		}
		else if (key_code == KEY_VOL_DOWN && key_type == KEY_EVENT_UP) 
		{
			mmi_fmrdo_dec_volume();
		}
	}
}

#endif
#ifdef __MMI_NCENTER_SUPPORT__
void mmi_fmrdo_ncenter_add_fm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vsrv_ngroup_handle ghandle;
	vsrv_notification_handle nhandle;
#ifdef __MMI_FM_RADIO_RDS__
	WCHAR str[MMI_FMRDO_RDS_PS_NAME_SIZE + MMI_FMRDO_RDS_RT_SIZE + 3];
#else
    WCHAR str[MAX_NAME_INPUT_LEN + 10];
#endif
    mmi_image_src_struct fm_nc_icon;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_FMRDO);
	nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_ONGOING, ghandle, 0);
    ncenter_fmrdo_ghandle = ghandle;
	ncenter_fmrdo_nhandle = nhandle;	                        
	if(ncenter_fmrdo_nhandle == NULL || ncenter_fmrdo_nhandle == NULL)
	{
		return;
	}  
	vsrv_ncenter_set_ngroup_title_id(ghandle, (S32)STR_ID_FMRDO_TITLE);
    memset(str, 0, sizeof(str));
	#ifdef __MMI_FM_RADIO_RDS__
		if(g_fmrdo.rds.rds_setting.is_rds_on)
		{
			if (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") != 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") != 0)
        	{
				mmi_ucs2ncpy((CHAR*)str, (CHAR*)g_fmrdo.rds.prog_name, MMI_FMRDO_RDS_PS_NAME_SIZE - 1);
				mmi_ucs2cat((CHAR *) str,(char *) L". ");
				mmi_ucs2ncat((CHAR*)str, (CHAR *)g_fmrdo.rds.radio_text, MMI_FMRDO_RDS_RT_SIZE );
				
            	vsrv_ncenter_set_notification_maintext_str(ncenter_fmrdo_nhandle, str);    
        	}
            else if (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") != 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") == 0)
		    {
		        mmi_ucs2ncpy((CHAR*)str, (CHAR*)g_fmrdo.rds.prog_name, MMI_FMRDO_RDS_PS_NAME_SIZE - 1);				
                 vsrv_ncenter_set_notification_maintext_str(ncenter_fmrdo_nhandle, str);    
		    }
		    else if(mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") == 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") != 0)
		    {
		         mmi_ucs2ncpy((CHAR*)str, (CHAR *)g_fmrdo.rds.radio_text, MMI_FMRDO_RDS_RT_SIZE);
                 vsrv_ncenter_set_notification_maintext_str(ncenter_fmrdo_nhandle, str);    
		    }
			else if(g_fmrdo.channel_index >= 0)
	    	{
	        	kal_wsprintf(str, "%d. %w", g_fmrdo.channel_index + 1, g_fmrdo.channel_list.name[g_fmrdo.channel_index]);
				vsrv_ncenter_set_notification_maintext_str(ncenter_fmrdo_nhandle, str);
	    	}
			else
			{
				vsrv_ncenter_set_notification_maintext_id(ncenter_fmrdo_nhandle,(S32)STR_ID_FMRDO_TITLE);
	    	}
		}
		else 
	#endif
    if (g_fmrdo.channel_index >= 0)
    {
        kal_wsprintf(str, "%d. %w", g_fmrdo.channel_index + 1, g_fmrdo.channel_list.name[g_fmrdo.channel_index]);
		vsrv_ncenter_set_notification_maintext_str(ncenter_fmrdo_nhandle, str);
    }
    else
    {
		vsrv_ncenter_set_notification_maintext_id(ncenter_fmrdo_nhandle,(S32)STR_ID_FMRDO_TITLE);
    }
    vsrv_ncenter_set_notification_questiontext_id(ncenter_fmrdo_nhandle, (S32)STR_ID_FMRDO_CLOSE_NOTIFICATION);
	
	vsrv_ncenter_set_notification_intent_callback(ncenter_fmrdo_nhandle, mmi_fmrdo_ncenter_callback_handler, NULL, 0);
	                        
	vsrv_ncenter_notify_notification(ncenter_fmrdo_nhandle); 
}

void mmi_fmrdo_ncenter_callback_handler(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
     if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
     {
		mmi_fmrdo_run_app();
     }
     else if (intent.type == VSRV_NINTENT_TYPE_TERMINATE)
     {
         mmi_fmrdo_power_on_check(MMI_FALSE);
         mmi_frm_group_close(GRP_ID_FMRDO);
     }
    
}

void mmi_fmrdo_ncenter_update_channel(void)
{
#ifdef __MMI_FM_RADIO_RDS__
	WCHAR str[MMI_FMRDO_RDS_PS_NAME_SIZE + MMI_FMRDO_RDS_RT_SIZE + 3];
#else
    WCHAR str[MAX_NAME_INPUT_LEN + 10];
#endif
    if(ncenter_fmrdo_nhandle != NULL)
    {
    memset(str, 0, sizeof(str));

    #ifdef __MMI_FM_RADIO_RDS__
		if(g_fmrdo.rds.rds_setting.is_rds_on)
		{
			if (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") != 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") != 0)
        	{
		        mmi_ucs2ncpy((CHAR*)str, (CHAR*)g_fmrdo.rds.prog_name, MMI_FMRDO_RDS_PS_NAME_SIZE - 1);
				mmi_ucs2cat((CHAR *) str,(char *) L". ");
				mmi_ucs2ncat((CHAR*)str, (CHAR *)g_fmrdo.rds.radio_text, MMI_FMRDO_RDS_RT_SIZE);
            	vsrv_ncenter_set_notification_maintext_str(ncenter_fmrdo_nhandle, str);    
        	}
            else if (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") != 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") == 0)
		    {
		         mmi_ucs2ncpy((CHAR*)str, (CHAR*)g_fmrdo.rds.prog_name, MMI_FMRDO_RDS_PS_NAME_SIZE - 1);
                 vsrv_ncenter_set_notification_maintext_str(ncenter_fmrdo_nhandle, str);    
		    }
		    else if(mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") == 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") != 0)
		    {
		         mmi_ucs2ncpy((CHAR*)str, (CHAR *)g_fmrdo.rds.radio_text, MMI_FMRDO_RDS_RT_SIZE);
                 vsrv_ncenter_set_notification_maintext_str(ncenter_fmrdo_nhandle, str);    
		    }
			else if(g_fmrdo.channel_index >= 0)
	    	{
	        	kal_wsprintf(str, "%d. %w", g_fmrdo.channel_index + 1, g_fmrdo.channel_list.name[g_fmrdo.channel_index]);
				vsrv_ncenter_set_notification_maintext_str(ncenter_fmrdo_nhandle, str);
	    	}
			else
			{
				vsrv_ncenter_set_notification_maintext_id(ncenter_fmrdo_nhandle,(S32)STR_ID_FMRDO_TITLE);
	    	}
		}
		else 
	#endif
    if (g_fmrdo.channel_index >= 0)
    {
        kal_wsprintf(str, "%d. %w", g_fmrdo.channel_index + 1, g_fmrdo.channel_list.name[g_fmrdo.channel_index]);
		vsrv_ncenter_set_notification_maintext_str(ncenter_fmrdo_nhandle, str);
    }
    else
    {
		vsrv_ncenter_set_notification_maintext_id(ncenter_fmrdo_nhandle,(S32)STR_ID_FMRDO_TITLE);
    }
	vsrv_ncenter_notify_notification(ncenter_fmrdo_nhandle);
}
}

void mmi_fmrdo_ncenter_clear_fm(void)
{
    vsrv_ncenter_close_notification(ncenter_fmrdo_nhandle);
    vsrv_ncenter_close_ngroup(ncenter_fmrdo_ghandle);

	ncenter_fmrdo_nhandle = NULL;
	ncenter_fmrdo_ghandle = NULL;
}
#endif

#ifdef __MMI_FM_VIA_A2DP__

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_bt_open_callback
 * DESCRIPTION
 *  a callback function invoked by av_bt_open apis
 * PARAMETERS
 *  result  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_bt_open_callback(srv_bt_cm_bt_addr *address, kal_int32 result)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_BT_OPEN_CALLBACK_ENTRY,result,g_fmrdo.state,fm_a2dp_connected);
    switch( result )
    {
        case AV_BT_CALLBACK_EVENT_OPEN_OK:
        {
            switch(g_fmrdo.state)
            {
                case FMRDO_STATE_READY:
                    if(mmi_fmrdo_is_power_on() && !g_fmrdo.loud_speaker_on)
                    {
                        //srv_a2dp_start_stream(mmi_a2dp_get_bt_headset());

                        srv_a2dp_reconfig_start_streaming(
                                    mmi_a2dp_get_bt_headset(), 
                                    NULL, 
                                    a2dp_info.sample_rate,
                                    a2dp_info.is_stereo, 
                                    MMI_TRUE);
                        //srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);
                        //av_bt_open_codec(KAL_TRUE);
                        //g_fmrdo.state = FMRDO_STATE_READY;
                        if (g_fmrdo.mute)
                        {
                            mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
                        }
                        else
                        {
                            mmi_fmrdo_set_volume(g_fmrdo.volume);
                        }
                    }

                    break;
                case FMRDO_STATE_BT_CONNECTING:                
                    /*while inquirying, postpone until inquiry action is over */
                    if(!av_bt_is_inquiry())
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_BT_CALLBACK_OK,mmi_fmrdo_is_power_on(),fm_a2dp_connected);
                        
                        if(mmi_fmrdo_is_power_on() && !g_fmrdo.loud_speaker_on)
                        {
                            //srv_a2dp_start_stream(mmi_a2dp_get_bt_headset());

                            srv_a2dp_reconfig_start_streaming(
                                        mmi_a2dp_get_bt_headset(), 
                                        NULL, 
                                        a2dp_info.sample_rate,
                                        a2dp_info.is_stereo, 
                                        MMI_TRUE);
                            //srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);
//                            av_bt_open_codec(KAL_TRUE);
                            g_fmrdo.state = FMRDO_STATE_READY;
                            if (g_fmrdo.mute)
                            {
                                mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
                            }
                            else
                            {
                                mmi_fmrdo_set_volume(g_fmrdo.volume);
                            }
                        }
                        else
                        {
//                            av_bt_open_codec(KAL_FALSE);
                        	//srv_a2dp_start_stream(mmi_a2dp_get_bt_headset());
                            mmi_fmrdo_power_on(MMI_TRUE);
                        srv_a2dp_reconfig_start_streaming(
                                    mmi_a2dp_get_bt_headset(), 
                                    NULL, 
                                    a2dp_info.sample_rate,
                                    a2dp_info.is_stereo, 
                                    MMI_TRUE);

                        }
                        fm_a2dp_connected = MMI_TRUE;
                    }
                    else
                    {
                        bt_success_during_inquiry = MMI_TRUE;
                    }
                     break;
            }
            break;
        }
        case AV_BT_CALLBACK_EVENT_OPEN_FAILED:
        case AV_BT_CALLBACK_EVENT_OPEN_STOPPED:
        {
            switch(g_fmrdo.state)
            {
                case FMRDO_STATE_BT_CONNECTING:
                {	
					if(mmi_fmrdo_is_power_on())
					{
						g_fmrdo.state = FMRDO_STATE_READY;
					}
					else
					{
						mmi_fmrdo_power_on(MMI_TRUE);
					}
                    break;
                }
                case FMRDO_STATE_READY:
                {
                    srv_a2dp_pause_stream();                    
                    break;
                }
            }
			fm_a2dp_connected = MMI_FALSE;
            break;
        }
	#ifdef __MMI_BT_AUDIO_VIA_SCO__
        case AV_BT_CALLBACK_EVENT_OPEN_SCO:
        {
            switch(g_fmrdo.state)
            {
                case FMRDO_STATE_BT_CONNECTING:
                {	
					if(mmi_fmrdo_is_power_on())
					{
						g_fmrdo.state = FMRDO_STATE_READY;
					}
					else
					{
						mmi_fmrdo_power_on(MMI_TRUE);
					}
                    break;
                }
                case FMRDO_STATE_READY:
                {
                    srv_a2dp_pause_stream();                    
                    break;
                }
            }
			fm_a2dp_connected = MMI_FALSE;
			mdi_audio_bt_hfp_turn_on();
			if (g_fmrdo.is_power_on != MMI_FALSE)
    		{
			    if (g_fmrdo.mute)
			    {
			        mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
			    }
			    else
			    {
			        mdi_audio_set_volume(AUD_VOLUME_FMR, g_fmrdo.volume);
			    }
			}
            break;
        }
	#endif
        /*this result means someone else is using mdi audio thus current playing is canceled*/
        case AV_BT_CALLBACK_EVENT_OPEN_CANCELED:
        {
            /*play state with bt connecting shall let mdi interrupt callback to handle
              and goes to interrupted state*/
            switch(g_fmrdo.state)
            {
                case FMRDO_STATE_BT_CONNECTING:
                case FMRDO_STATE_READY:
                {
					mmi_fmrdo_bt_stop(KAL_FALSE);
                    //mmi_medply_audio_interrupted();
                    break;
                }
            }
			fm_a2dp_connected = MMI_FALSE;
            break;
        }
        case AV_BT_CALLBACK_EVENT_STREAM_ABORT_IND:
        case AV_BT_CALLBACK_EVENT_STREAM_CLOSE_IND:
        case AV_BT_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
        {
            switch(g_fmrdo.state)
            {
            
                case FMRDO_STATE_BT_CONNECTING:
                {
                   	if(mmi_fmrdo_is_power_on())
					{
						g_fmrdo.state = FMRDO_STATE_READY;
					}
					else
					{
						mmi_fmrdo_power_on(MMI_TRUE);
					}
                    break;
                }
                case FMRDO_STATE_READY:
                {
                    mmi_fmrdo_bt_stop(MMI_FALSE);
                    break;
                }
            }
			fm_a2dp_connected = MMI_FALSE;
            break;
        }

        case AV_BT_CALLBACK_EVENT_STREAM_PAUSE_IND:
        {
            if (mmi_fmrdo_is_power_on() && (g_fmrdo.state == FMRDO_STATE_READY) && mmi_a2dp_is_output_to_bt())
            {
                //No need to set app callback here as FM power on case so already registered.
                //srv_a2dp_start_stream(mmi_a2dp_get_bt_headset());
                
                srv_a2dp_reconfig_start_streaming(
                            mmi_a2dp_get_bt_headset(), 
                            NULL, 
                            a2dp_info.sample_rate,
                            a2dp_info.is_stereo, 
                            MMI_TRUE);
            }
            break;
        }
        
        case AV_BT_CALLBACK_EVENT_STREAM_START_IND:
        {
            switch(g_fmrdo.state)
            {
                case FMRDO_STATE_READY:
                {
                    /*change state first since av_bt might callback success immediately*/
					mmi_fmrdo_change_state_a2dp_connect();
                    
//                    av_bt_open_ex((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(),a2dp_info.sample_rate,a2dp_info.is_stereo,
//                            mmi_fmrdo_bt_open_callback,KAL_TRUE);
                    break;  
                }
                /* some earphone will send start ind right after avrcp play command, if we av_bt_close the start id
                   the bt_connecting will never have chance to go to next state for no bt callback*/
                case FMRDO_STATE_BT_CONNECTING:
                {
                    break;
                }
                default:
                {
                    srv_a2dp_pause_stream();
                    break;
                }
            }
            break;
        }

        case AV_BT_CALLBACK_EVENT_INQUIRY_START_IND:
        {
            /*since this flag only works for inquiry period, reset it while receive inquiry ind*/
            bt_success_during_inquiry = MMI_FALSE;

            switch(g_fmrdo.state)
            {
                case FMRDO_STATE_READY:
                {
                    if(mmi_a2dp_is_output_to_bt() && av_bt_is_streaming())
                    {
                        //mmi_medply_audio_seek_stop();
                        //mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
                        //inquiry_paused = MMI_TRUE;
                    }
                    break;
                }
            }
            break;
        }

        case AV_BT_CALLBACK_EVENT_INQUIRY_STOP_IND:
        {
            switch(g_fmrdo.state)
            {
                case FMRDO_STATE_BT_CONNECTING:
                {
                    if(bt_success_during_inquiry)
                    {
                        bt_success_during_inquiry = MMI_FALSE;
                        if(mmi_fmrdo_is_power_on())
						{
                            av_bt_open_codec(KAL_TRUE);
							g_fmrdo.state = FMRDO_STATE_READY;
						}
						else
						{
							av_bt_open_codec(KAL_FALSE);
                        	mmi_fmrdo_power_on(MMI_TRUE);
						}
						fm_a2dp_connected = MMI_TRUE;
                    }
                    break;
                }
            }
            break;
        }
    }
	mmi_fmrdo_a2dp_connect_stop_animation();
	mmi_fmrdo_update_center_key_status();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_BT_OPEN_CALLBACK_OUT,result,g_fmrdo.state,fm_a2dp_connected);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_switch_bt_output
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_switch_bt_output(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                						   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      						   */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_SWITCH_BT_OUTPUT_IN, g_fmrdo.state,fm_a2dp_connected);
    if (mmi_a2dp_is_output_to_bt())
    {
        /* switch output: OFF -> ON */
        if (g_fmrdo.state == FMRDO_STATE_READY && !fm_a2dp_connected)
        {
            mmi_fmrdo_change_state_a2dp_connect();
            srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);
//            av_bt_open_ex((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(),a2dp_info.sample_rate,a2dp_info.is_stereo,
//                            mmi_fmrdo_bt_open_callback,KAL_TRUE);
        }
    }
    else
    {
        /* switch output: ON -> OFF */
        if (g_fmrdo.state == FMRDO_STATE_READY)
        {
            srv_a2dp_pause_stream();
        }
//        av_bt_close(KAL_TRUE);
		fm_a2dp_connected = MMI_FALSE;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_SWITCH_BT_OUTPUT_OUT, g_fmrdo.state,fm_a2dp_connected);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_turn_off_bt_output
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_turn_off_bt_output(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                						   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      						   */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_TURN_OFF_BT_OUTPUT_IN, g_fmrdo.state,fm_a2dp_connected);
    /* switch output: ON -> OFF */
	switch(g_fmrdo.state)
	{
		case FMRDO_STATE_BT_CONNECTING:
		{
			av_bt_close(KAL_TRUE);
			break;
		}
	    case FMRDO_STATE_READY:
		{
			srv_a2dp_pause_stream();
			av_bt_close(KAL_TRUE);
			break;
	    }   
	}
	fm_a2dp_connected = MMI_FALSE;
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_TURN_OFF_BT_OUTPUT_OUT, g_fmrdo.state,fm_a2dp_connected);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sync_bt_output
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sync_bt_output(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                						   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      						   */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_SYNC_BT_OUTPUT_IN, g_fmrdo.state,fm_a2dp_connected);
    ASSERT(mmi_a2dp_is_output_to_bt());
    switch(g_fmrdo.state)
    {
		case FMRDO_STATE_READY:
		{
			mmi_fmrdo_power_on_check(MMI_FALSE);
		   	mmi_fmrdo_power_on_check(MMI_TRUE);          
			break;
		}
		case FMRDO_STATE_BT_CONNECTING: 
    	{
//			mmi_fmrdo_bt_stop(MMI_FALSE);
            srv_a2dp_pause_stream();
			if(mmi_a2dp_is_output_to_bt() && !fm_a2dp_connected)
			{
                mmi_fmrdo_change_state_a2dp_connect();
                srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);
//     		    av_bt_open_ex((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(),a2dp_info.sample_rate,a2dp_info.is_stereo,
//                            mmi_fmrdo_bt_open_callback,KAL_TRUE);
			}
			break;
    	}
         
    }
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_SYNC_BT_OUTPUT_OUT, g_fmrdo.state,fm_a2dp_connected);
}

/*****************************************************************************
 * FUNCTION
 * mmi_fmrdo_bt_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  notify_opener   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_bt_stop(MMI_BOOL notify_opener)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                               					          */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      						   */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_BT_STOP_IN, g_fmrdo.state,notify_opener,fm_a2dp_connected);
    /* always stop codec*/
	mmi_fmrdo_a2dp_connect_stop_animation();
    if( mmi_a2dp_is_output_to_bt())
    {
        srv_a2dp_pause_stream();
//        av_bt_close_codec();
//		av_bt_close(notify_opener);
    }
	fm_a2dp_connected = MMI_FALSE;
	mmi_fmrdo_update_center_key_status();
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_BT_STOP_OUT, g_fmrdo.state,notify_opener,fm_a2dp_connected);
}

#endif /* __MMI_FM_VIA_A2DP__ */

/*****************************************************************************
 * FUNCTION
 * mmi_fmrdo_change_centerkey_status
 * DESCRIPTION
 * To disable or enable center key in case of NON FTE,NON SLIM  builds.
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_update_center_key_status(void)
{
	#if (defined(__MMI_FM_RADIO_RECORD__) && (!defined(__MMI_SLIM_IMG_RES__)))
		#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
			if(!mdi_audio_is_resource_available(MDI_AUDIO_RECORD_FM_RADIO , NULL))
			{		
				ClearKeyHandler(KEY_ENTER, KEY_EVENT_UP); 
			}
			else
			{
				SetKeyHandler(mmi_fmrdo_release_record_button, KEY_ENTER, KEY_EVENT_UP);
					
			}
		#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
	#endif
}

#endif /* __MMI_FM_RADIO__ */ 
#endif /*__MMI_BTBOX_NOLCD__*/


