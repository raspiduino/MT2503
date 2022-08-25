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
 *  ShutdownAni.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Shutdown animation
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

#include "MMI_features.h"
#include "mmi_rp_app_shutdown_def.h"
#include "BootupScrAni.h"
#include "ProcedureGprot.h"
#include "ProfilesSrvGprot.h"
#include "WPSSProtos.h"         /* PhnsetGetPwrOffDisp */
#include "GpioSrvGprot.h"
#include "ShutdownProt.h"
#include "MMIDataType.h"
#include "PhoneSetupResList.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "custom_led_patterns.h"
#include "gpiosrvgprot.h"
#include "string.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"

/* Force to stop the animation if timeout */
#define MMI_SHUTDOWN_ANI_DEFAULT_TIMEOUT_IN_MS 15000 /* ms */


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    mmi_frm_proc_id_info_struct id_info;
    mmi_ani_handle ani_handle;
} mmi_shutdown_ani_cntx_struct;

static mmi_shutdown_ani_cntx_struct g_mmi_shutdown_ani_cntx;


/****************************************************************************
 * Functions
 ****************************************************************************/

static void mmi_shutdown_ani_completed(void *user_data, mmi_ani_handle handle);

/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_ani_get_disp_id
 * DESCRIPTION
 *  Get animation display ID from phone setup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_shutdown_ani_get_disp_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 disp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    PhnsetGetPwrOffDisp(&disp_id);
#else
    disp_id = IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT;
#endif

    return disp_id;
}


#ifdef __MMI_POWER_ON_OFF_DISPLAY__
/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_ani_get_res_filepath
 * DESCRIPTION
 *  Get the filepath of resource of shutdown animation.
 * PARAMETERS
 *  out_filepath    [OUT] Filepath
 *  buffer_size     [IN] Buffer size of filepath
 * RETURNS
 *  MMI_TRUE if output is valid
 *****************************************************************************/
static MMI_BOOL mmi_shutdown_ani_get_res_filepath(WCHAR *out_filepath, U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const CHAR *phn_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    out_filepath[0] = L'\0';
    
    phn_path = (const CHAR*)PhnsetGetPwrOffFileName();

    if (phn_path != NULL && phn_path[0] != '\0')
    {
        mmi_ucs2ncpy((CHAR*)out_filepath, phn_path, (buffer_size / sizeof(WCHAR)) - 1);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}
#endif


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
static void mmi_shutdown_led_control(mmi_ani_led_command command)
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
            srv_gpio_play_pattern(SRV_GPIO_PATN_LED_PWROFF, SRV_GPIO_PATN_PLAY_START);
            break;

        case MMI_ANI_LED_COMMAND_STOP:
            srv_gpio_play_pattern(SRV_GPIO_PATN_LED_PWROFF, SRV_GPIO_PATN_PLAY_STOP);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_play_animation
 * DESCRIPTION
 *  Play animation procedure for shutdown flow.
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] To be passed into mmi_frm_proc_notify_completed()
 * RETURNS
 *  mmi_frm_proc_result_enum
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_shutdown_play_animation(
                            void *arg,
                            const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_shutdown_ani_cntx_struct *cntx;
    mmi_ani_param_struct param;
    srv_prof_audio_id audio_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_mmi_shutdown_ani_cntx);
    
    cntx->id_info = id_info;

	// slim_memset
    //memset(&param, 0, sizeof(param));
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    param.reset_to_default = PhnsetRstPwrOffDisplayDefault;
    param.get_res_filepath = mmi_shutdown_ani_get_res_filepath;
#endif
#if !defined(__MMI_BOOTUP_SLIM__)
    param.led_control = mmi_shutdown_led_control;
    param.end_key_to_exit = MMI_FALSE;
#endif
#ifdef __DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__
    param.key_proc = NULL;
#endif
#ifdef __MMI_POWER_ON_OFF_MUTE__
    param.play_audio = MMI_FALSE;
#else
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_POWER_OFF_TONE, &audio_id);
    if (audio_id != SRV_PROF_TONE_NONE)
		param.play_audio = MMI_TRUE;
	else
		param.play_audio = MMI_FALSE;
#endif
    param.get_disp_id = mmi_shutdown_ani_get_disp_id;
    param.audio = SRV_PROF_TONE_POWER_OFF;
    param.wait_for_audio = MMI_TRUE;
    param.timeout = MMI_SHUTDOWN_ANI_DEFAULT_TIMEOUT_IN_MS;
    param.grp_id = GRP_ID_SHUTDOWN;
    param.scr_id = SCR_ID_SHUTDOWN_ANIMATION;
    param.completed_callback = mmi_shutdown_ani_completed;
    param.user_data = (void*)cntx;
    
    cntx->ani_handle = mmi_ani_create(&param);
    mmi_ani_show(cntx->ani_handle);

    /* Display the shutdown animation on the sub-LCD. */
    ForceSubLCDScreen(mmi_shutdown_sublcd_entry);

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_ani_completed
 * DESCRIPTION
 *  Callback for animation completed.
 *  Notfiy shutdown flow that animation is completed.
 * PARAMETERS
 *  user_data   [IN] mmi_shutdown_ani_cntx_struct*
 *  handle      [IN] Animation handle
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_shutdown_ani_completed(void *user_data, mmi_ani_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_shutdown_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_shutdown_ani_cntx_struct*)user_data;

    MMI_ASSERT(cntx->ani_handle == handle);
    mmi_ani_close(cntx->ani_handle);
    cntx->ani_handle = MMI_ANI_INVALID_HANDLE;

    mmi_frm_proc_notify_completed(cntx->id_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_ani_stop
 * DESCRIPTION
 *  Force to stop animation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_shutdown_ani_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_shutdown_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &g_mmi_shutdown_ani_cntx;
    if (cntx->ani_handle != MMI_ANI_INVALID_HANDLE)
    {
        mmi_ani_close(cntx->ani_handle);
        cntx->ani_handle = MMI_ANI_INVALID_HANDLE;
    }
}


#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_pause_video
 * DESCRIPTION
 *  This function is for TV-out. During the power-off period, if TV-out is 
 *  turned on/off, the popup cannot be shown. In this situation, this function 
 *  is used to pause the video such that its display can be re-configured.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_shutdown_pause_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
    if (g_mmi_shutdown_ani_cntx.ani_handle != MMI_ANI_INVALID_HANDLE)
    {
        mmi_ani_pause_video(g_mmi_shutdown_ani_cntx.ani_handle);
    }
#endif /* #ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_resume_video
 * DESCRIPTION
 *  This function is for TV-out. During the power-off period, if TV-out is 
 *  turned on/off, the popup cannot be shown. In this situation, this function 
 *  is used to resume the video after its display is re-configured.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_shutdown_resume_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
    if (g_mmi_shutdown_ani_cntx.ani_handle != MMI_ANI_INVALID_HANDLE)
    {
        mmi_ani_resume_video(g_mmi_shutdown_ani_cntx.ani_handle);
    }
#endif /* #ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__ */
}
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
