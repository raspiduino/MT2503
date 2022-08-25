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
 *  BootupAnimation.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Animation control during booting.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMIDataType.h"
#include "MMI_features.h"
#include "kal_general_types.h"
#include "BootupAppProt.h"
#include "CustResDef.h"         /* SSC_FACTORY_MODE */
#include "ProfilesSrvGprot.h"
#include "BootupScrAni.h"

#include "FactoryModeProt.h"
#include "WPSSProtos.h"         /* PhnsetGetDisplayType */
#include "PowerOnChargerProt.h" /* ShowLowPowerShutdownScr */
#include "ProcedureGprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "BootupSrvGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_bootup_def.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories.h"
#include "mmi_frm_history_gprot.h"
#include "BootupScrUtil.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "GlobalConstants.h"
#include "GlobalResDef.h"
#include "mmi_frm_input_gprot.h"
#include "PhoneSetupResList.h"
#include "Unicodexdcl.h"
#include "custom_led_patterns.h"
#include "GpioSrvGprot.h"
#include "gpiosrvgprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "custom_events_notify.h"
#include "ProcedureConfig.h"
#include "mmi_frm_input_event.h"


/****************************************************************************
 * Configuration
 ****************************************************************************/

/*
 * If the animation is a still image, it should display for a period. This
 * value configures the delay time of a still image displaying.
 */
#define MMI_BOOTUP_ANI_STILL_IMAGE_DELAY_IN_MS  1500    /* ms */

/*
 * User may set a long animation and we have to cut it. This value restricts
 * the maximum time of animation playing.
 */
#define MMI_BOOTUP_ANI_DEFAULT_TIMEOUT_IN_MS    20000   /* ms */


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef enum
{
    MMI_BOOTUP_ANI_STATE_INIT       = 0x00,
    MMI_BOOTUP_ANI_STATE_PLAYING    = 0x01,
    MMI_BOOTUP_ANI_STATE_COMPLETED  = 0xff,

    MMI_BOOTUP_ANI_STATE_END_OF_ENUM
} mmi_bootup_animation_state_enum;

typedef struct
{
    CHAR buffer[20];
    S32 buffer_end_index;
} mmi_bootup_ani_factory_mode_struct;

/*
 * The context of animation.
 *
 * Actually we can dynamically allocate the space to reduce the memory
 * usage. However, we reserve the space here for debug assistance.
 */
typedef struct
{
#ifdef __DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__
    mmi_bootup_ani_factory_mode_struct *factory_mode;
#endif
    mmi_bootup_animation_state_enum state;
    mmi_ani_handle ani_handle;
    MMI_BOOL all_other_works_completed;
    mmi_frm_proc_id_info_struct id_info;
} mmi_bootup_ani_cntx_struct;


/****************************************************************************
 * Global variables
 ****************************************************************************/

static mmi_bootup_ani_cntx_struct g_mmi_bootup_ani_cntx =
{
#ifdef __DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__
    NULL,
#endif
    MMI_BOOTUP_ANI_STATE_INIT,
    MMI_ANI_INVALID_HANDLE,
    MMI_FALSE
};


/****************************************************************************
 * Local functions
 ****************************************************************************/

static void mmi_bootup_ani_finalize(mmi_bootup_ani_cntx_struct *cntx);

#ifdef __MMI_FACTORY_MODE__
extern void EntryFMMenu(void);
#endif /* __MMI_FACTORY_MODE__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_update_state
 * DESCRIPTION
 *  Update the state of animation.
 *  It also write the state to animation for recovery if any error during
 *  playing.
 * PARAMETERS
 *  state       [IN] State
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_ani_update_state(mmi_bootup_animation_state_enum state)
{
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 u16_state;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    u16_state = (U16)state;
    WriteValue(NVRAM_POWER_ON_DISPLAY_SUCCESS, &u16_state, DS_SHORT, &error);
#endif

    g_mmi_bootup_ani_cntx.state = state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_check_previous_playing
 * DESCRIPTION
 *  If exceptional booting, check previous playing succeed or not. If not,
 *  we assume it is animation's problem first and reset it.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_ani_check_previous_playing(void)
{
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 state;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bootup_is_exception_mode())
    {
        ReadValue(NVRAM_POWER_ON_DISPLAY_SUCCESS, &state, DS_SHORT, &error);

        if (state != MMI_BOOTUP_ANI_STATE_COMPLETED)
        {
            /*
             * Fatal error or assert fail on previous playing, reset
             * the animation setting to default.
             */
            PhnsetRstPwrOnDisplayDefault();
        }
    }
#endif
}


#ifdef __DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_post_finalize_after_fm
 * DESCRIPTION
 *  Call mmi_bootup_ani_finalize().
 * PARAMETERS
 *  evt     [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_ani_post_finalize_after_fm(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_bootup_ani_cntx_struct*)evt->user_data;

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_BOOTUP,
        SCR_ID_BOOTUP_DETECT_FACTORY_MODE_END,
        NULL);
    
    mmi_bootup_ani_finalize(cntx);

    mmi_frm_scrn_close(GRP_ID_BOOTUP, SCR_ID_BOOTUP_DETECT_FACTORY_MODE_END);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_entry_finalize
 * DESCRIPTION
 *  Entry function to detect the end of factory mode.
 * PARAMETERS
 *  evt     [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_ani_entry_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_ani_cntx_struct *cntx;
    mmi_event_struct dummy_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_mmi_bootup_ani_cntx);
    
    if (!mmi_frm_scrn_enter(
        GRP_ID_BOOTUP,
        SCR_ID_BOOTUP_DETECT_FACTORY_MODE_END,
        NULL,
        mmi_bootup_ani_entry_finalize,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    ShowCategoryDummyScreen();

    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }
    
    mmi_frm_scrn_set_key_proc(
        GRP_ID_BOOTUP,
        SCR_ID_BOOTUP_DETECT_FACTORY_MODE_END,
        mmi_bootup_block_all_keys);
    
    MMI_FRM_INIT_EVENT(&dummy_evt, 0);
    MMI_FRM_POST_EVENT(&dummy_evt, mmi_bootup_ani_post_finalize_after_fm, cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_enter_factory_mode
 * DESCRIPTION
 *  Enter factory mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_ani_enter_factory_mode(mmi_bootup_ani_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_is_ultra_low_power())
    {
        ShowLowPowerShutdownScr();
        mmi_ani_close(cntx->ani_handle);
        cntx->ani_handle = MMI_ANI_INVALID_HANDLE;
        return;
    }

    // gui_hide_animations();

    /* Put a dummy screen to detect the end of factory mode menu */
    mmi_frm_scrn_enter(
        GRP_ID_BOOTUP,
        SCR_ID_BOOTUP_DETECT_FACTORY_MODE_END,
        NULL,
        mmi_bootup_ani_entry_finalize,
        MMI_FRM_FULL_SCRN);

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_BOOTUP,
        SCR_ID_BOOTUP_DETECT_FACTORY_MODE_END,
        mmi_bootup_block_scr_deleting);

    ShowCategoryDummyScreen();
        
    EntryFMMenu();

    mmi_ani_close(cntx->ani_handle);
    cntx->ani_handle = MMI_ANI_INVALID_HANDLE;

    if (cntx->factory_mode != NULL)
    {
        OslMfree(cntx->factory_mode);
        cntx->factory_mode = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_factory_mode_detect
 * DESCRIPTION
 *  Digit key handler on animation screen. To detect factory mode command.
 * PARAMETERS
 *  key_code    [IN] Key code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_ani_factory_mode_detect(U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	// slim_static_var
	//static const CHAR *pattern_str = SSC_FACTORY_MODE;
    mmi_bootup_ani_factory_mode_struct *fm_cntx;

    mmi_bootup_ani_cntx_struct *cntx;
    S32 pattern_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_mmi_bootup_ani_cntx);
    
    if (cntx->factory_mode == NULL)
    {
        cntx->factory_mode =
            (mmi_bootup_ani_factory_mode_struct*)OslMalloc(sizeof(mmi_bootup_ani_factory_mode_struct));
        fm_cntx = cntx->factory_mode;
        fm_cntx->buffer[0] = '\0';
        fm_cntx->buffer_end_index = 0;
    }
    else
    {
        fm_cntx = cntx->factory_mode;
    }
    
    if (fm_cntx->buffer_end_index >= sizeof(fm_cntx->buffer) - 2)
    {
        return;
    }

    if (key_code == KEY_0 || (KEY_1 <= key_code && key_code <= KEY_9))
    {
        fm_cntx->buffer[fm_cntx->buffer_end_index++] = ('0' + (key_code - KEY_0));
    }
    else if (key_code == KEY_STAR)
    {
        fm_cntx->buffer[fm_cntx->buffer_end_index++] = '*';
    }
    else if (key_code == KEY_POUND)
    {
        fm_cntx->buffer[fm_cntx->buffer_end_index++] = '#';
    }

    fm_cntx->buffer[fm_cntx->buffer_end_index] = '\0';

    /* Check if the key matches the pattern */
	// slim_static_var
    //pattern_len = strlen(pattern_str);
	pattern_len = strlen(SSC_FACTORY_MODE);
    if (fm_cntx->buffer_end_index >= pattern_len)
    {
        if (strncmp(fm_cntx->buffer + (fm_cntx->buffer_end_index - pattern_len),
                    //pattern_str,
                    SSC_FACTORY_MODE,	// slim_static_var
                    pattern_len) == 0)
        {
            mmi_bootup_ani_enter_factory_mode(cntx);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_set_factory_mode_key_handler
 * DESCRIPTION
 *  Set key handler for factory mode.
 * PARAMETERS
 *  evt     [IN] mmi_frm_key_evt_struct*
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bootup_ani_set_factory_mode_key_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ON_KEY)
    {
        mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct*)evt;
        U16 key_code = key_evt->key_code;

        if (key_evt->key_type == KEY_EVENT_DOWN)
        {
            if ((key_code == KEY_0) ||
                (KEY_1 <= key_code && key_code <= KEY_9) ||
                (key_code == KEY_STAR) ||
                (key_code == KEY_POUND))
            {
                mmi_bootup_ani_factory_mode_detect(key_evt->key_code);
                
                return MMI_RET_KEY_HANDLED;
            }
        }
    }

    return MMI_RET_OK;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_get_disp_id
 * DESCRIPTION
 *  Get animation display ID from phone setup.
 * PARAMETERS
 *  void
 * RETURNS
 *  Display ID from phone setup
 *****************************************************************************/
static U16 mmi_bootup_ani_get_disp_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 disp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    PhnsetGetPwrOnDisp(&disp_id);
#else
    disp_id = IMG_ID_PHNSET_ON_ANIMATION_DEFAULT;
#endif
    
    return disp_id;
}


#ifdef __MMI_POWER_ON_OFF_DISPLAY__
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_get_res_filepath
 * DESCRIPTION
 *  Get the filepath of resource of bootup animation.
 * PARAMETERS
 *  out_filepath    [OUT] Filepath
 *  buffer_size     [IN] Buffer size of filepath
 * RETURNS
 *  MMI_TRUE if output is valid
 *****************************************************************************/
static MMI_BOOL mmi_bootup_ani_get_res_filepath(WCHAR *out_filepath, U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const CHAR *phn_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    out_filepath[0] = L'\0';
    
    phn_path = (const CHAR*)PhnsetGetPwrOnFileName();

    if (phn_path != NULL && phn_path[0] != '\0')
    {
        mmi_ucs2ncpy((CHAR*)out_filepath, phn_path, (buffer_size / sizeof(WCHAR)) - 1);
        return MMI_TRUE;
    }

    return MMI_TRUE;
}
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */


#if !defined(__MMI_BOOTUP_SLIM__)
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_led_control
 * DESCRIPTION
 *  Control callback of power-on led
 * PARAMETERS
 *  command     [IN] Control command
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_ani_led_control(mmi_ani_led_command command)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (command)
    {
        case MMI_ANI_LED_COMMAND_START:
            srv_gpio_play_pattern(SRV_GPIO_PATN_LED_PWRON, SRV_GPIO_PATN_PLAY_START);
            break;

        case MMI_ANI_LED_COMMAND_STOP:
            srv_gpio_play_pattern(SRV_GPIO_PATN_LED_PWRON, SRV_GPIO_PATN_PLAY_STOP);
            break;

        default:
            break;
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_completed
 * DESCRIPTION
 *  Animation completed callback
 * PARAMETERS
 *  user_data   [IN] mmi_bootup_ani_cntx_struct*
 *  handle      [IN] Animation handle
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_ani_completed(void *user_data, mmi_ani_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_bootup_ani_cntx_struct*)user_data;
    
    mmi_bootup_ani_finalize(cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_finalize
 * DESCRIPTION
 *  Finalize animation playing of bootup phase
 * PARAMETERS
 *  user_data   [IN] mmi_bootup_ani_cntx_struct*
 *  handle      [IN] Animation handle
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_ani_finalize(mmi_bootup_ani_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_ANI_FINALIZE,
        cntx->all_other_works_completed);
    
#ifdef __DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__
    if (cntx->factory_mode != NULL)
    {
        OslMfree(cntx->factory_mode);
        cntx->factory_mode = NULL;
    }
#endif

    mmi_bootup_ani_update_state(MMI_BOOTUP_ANI_STATE_COMPLETED);

    if (mmi_bootup_is_ultra_low_power())
    {
        ShowLowPowerShutdownScr();
        return;
    }

    if (!cntx->all_other_works_completed)
    {
        mmi_bootup_waiting_screen_show(
            GRP_ID_BOOTUP,
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            STR_ID_BOOTUP_WAIT_FOR_SIM);
    }
    else
    {
        /*
         * Put a dummy to avoid flicker when we close the animation by follows.
         */
        mmi_bootup_put_dummy_screen(GRP_ID_BOOTUP);
    }

    mmi_ani_close(cntx->ani_handle);
    cntx->ani_handle = MMI_ANI_INVALID_HANDLE;

    mmi_frm_proc_notify_completed(cntx->id_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_play_animation
 * DESCRIPTION
 *  Playing booting animation.
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] To be passed into mmi_frm_proc_notify_completed()
 * RETURNS
 *  mmi_frm_proc_result_enum
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_bootup_play_animation(
                            void *arg,
                            const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_ani_cntx_struct *cntx;
    mmi_ani_param_struct param;
    srv_prof_audio_id audio_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_mmi_bootup_ani_cntx);

    if (srv_bootup_is_exception_mode())
    {
        mmi_bootup_ani_check_previous_playing();

        /* We don't play animation in exception mode */
        mmi_bootup_ani_update_state(MMI_BOOTUP_ANI_STATE_COMPLETED);
        
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }

    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_PLAY_ANIMATION);

    cntx->id_info = id_info;
    cntx->all_other_works_completed = MMI_FALSE;

    mmi_bootup_ani_update_state(MMI_BOOTUP_ANI_STATE_PLAYING);

	// slim_memset
    //memset(&param, 0, sizeof(mmi_ani_param_struct));
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    param.reset_to_default = PhnsetRstPwrOnDisplayDefault; 
    param.get_res_filepath = mmi_bootup_ani_get_res_filepath;
#endif
#if !defined(__MMI_BOOTUP_SLIM__)
    param.led_control = mmi_bootup_ani_led_control;
    param.end_key_to_exit = MMI_TRUE;
#endif /* !defined(__MMI_BOOTUP_SLIM__) */
#ifdef __DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__
    param.key_proc = mmi_bootup_ani_set_factory_mode_key_handler;
#endif
#ifdef __MMI_POWER_ON_OFF_MUTE__
    param.play_audio = MMI_FALSE;
#else
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_POWER_ON_TONE, &audio_id);
    if (audio_id != SRV_PROF_TONE_NONE)
		param.play_audio = MMI_TRUE;
	else
		param.play_audio = MMI_FALSE;
#endif
    param.get_disp_id = mmi_bootup_ani_get_disp_id;
    param.audio = SRV_PROF_TONE_POWER_ON;
    param.wait_for_audio = MMI_FALSE;
    param.timeout = MMI_BOOTUP_ANI_DEFAULT_TIMEOUT_IN_MS;
    param.grp_id = GRP_ID_BOOTUP;
    param.scr_id = SCR_ID_BOOTUP_ANIMATION;
    param.completed_callback = mmi_bootup_ani_completed;
    param.user_data = (void*)cntx;
    
    cntx->ani_handle = mmi_ani_create(&param);
    mmi_ani_show(cntx->ani_handle);

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


#ifdef __MMI_BTBOX_NOLCD__

static srv_prof_ret mmi_audio_completed_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_bootup_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cntx = &(g_mmi_bootup_ani_cntx);
    //MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_AUDIO_COMPLETED);
	mmi_frm_proc_notify_completed(cntx->id_info);

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_play_tone
 * DESCRIPTION
 *  Playing booting tone. only for bt box no lcd
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] To be passed into mmi_frm_proc_notify_completed()
 * RETURNS
 *  mmi_frm_proc_result_enum
 *****************************************************************************/

mmi_frm_proc_result_enum mmi_bootup_play_tone(
	                        void *arg,
                            const mmi_frm_proc_id_info_struct id_info)
{

/*----------------------------------------------------------------*/
/* Local Variables												  */
/*----------------------------------------------------------------*/
	mmi_bootup_ani_cntx_struct *cntx;
	//mmi_ani_param_struct param;
	srv_prof_audio_id audio_id;
	mmi_input_event_notify_param param;
/*----------------------------------------------------------------*/
/* Code Body													  */
/*----------------------------------------------------------------*/
    if (srv_bootup_is_exception_mode())
    {        
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }
	cntx = &(g_mmi_bootup_ani_cntx);
	cntx->id_info = id_info;
	param.aud_cb = mmi_audio_completed_callback;
    //MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_PLAY_ANIMATION);
	mmi_frm_input_event_notify(INPUT_EVENT_NOTIFY_AUDPLY, (void *)&param);
	return MMI_FRM_PROC_RESULT_NOTIFY_LATER;

}
#endif  //__MMI_BTBOX_NOLCD__



/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_is_playing
 * DESCRIPTION
 *  To query whether power-on animation is playing or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if animation is playing
 *****************************************************************************/
MMI_BOOL mmi_bootup_ani_is_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bootup_ani_cntx.state == MMI_BOOTUP_ANI_STATE_PLAYING)
		return MMI_TRUE;
	else
		return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_ani_notify_completion_info
 * DESCRIPTION
 *  The callback to update completion information of the procedures during
 *  animation.
 * PARAMETERS
 *  user_data   [IN] Unused
 *  info        [IN] Completion information
 * RETURNS
 *  mmi_frm_proc_ctrl_enum
 *****************************************************************************/
mmi_frm_proc_ctrl_enum mmi_bootup_ani_notify_completion_info(
            void *user_data,
            const mmi_frm_proc_set_status_struct *set_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (set_status->n_completed == set_status->n_total_procs - 1 &&
        !mmi_frm_proc_con_is_completed(set_status->instance, MMI_FRM_PROC_ID_BOOTUP_ANIMATION))
    {
        g_mmi_bootup_ani_cntx.all_other_works_completed = MMI_TRUE;
    }
    else if (set_status->n_completed == set_status->n_total_procs)
    {
        g_mmi_bootup_ani_cntx.all_other_works_completed = MMI_TRUE;
    }

    return ((set_status->n_completed == set_status->n_total_procs) ?
                MMI_FRM_PROC_CTRL_STOP : MMI_FRM_PROC_CTRL_CONTINUE);
}


#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_pwron_pause_video
 * DESCRIPTION
 *  pause video, this funcion will be used by TV-Out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pwron_pause_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
    if (g_mmi_bootup_ani_cntx.ani_handle != MMI_ANI_INVALID_HANDLE)
    {
        mmi_ani_pause_video(g_mmi_bootup_ani_cntx.ani_handle);
    }
#endif /* #ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pwron_resume_video
 * DESCRIPTION
 *  resume video, this funcion will be used by TV-Out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pwron_resume_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
    if (g_mmi_bootup_ani_cntx.ani_handle != MMI_ANI_INVALID_HANDLE)
    {
        mmi_ani_resume_video(g_mmi_bootup_ani_cntx.ani_handle);
    }
#endif /* #ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__ */
}
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) */ 


