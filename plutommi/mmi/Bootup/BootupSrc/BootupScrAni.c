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
 *  BootupScrAni.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Animation common UI for bootup and shutdown.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "BootupScrAni.h"
#include "FileMgrGProt.h"
#include "FileMgrSrvGProt.h"
#include "drm_gprot.h"
#include "ProfilesSrvGprot.h"
#include "MMI_common_app_trc.h"
#include "MMIDataType.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrType.h"
#include "kal_general_types.h"
#include "mmi_phnset_dispchar.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "fs_type.h"
#include "drm_def.h"
#include "wgui_categories_multimedia.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_rp_app_bootup_def.h"
#include "mdi_datatype.h"
#include "mmi_frm_scenario_gprot.h"
#include "gui.h"
#include "GpioSrvGprot.h"
#include "GlobalResDef.h"
#include "mmi_frm_input_gprot.h"
#include "string.h"
#include "GlobalConstants.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories.h"
#include "mdi_audio.h"
#include "gdi_include.h"
#include "mmi_frm_mem_gprot.h"


#define MMI_ANI_TRC_GROUP   MMI_COMMON_TRC_G3_BOOTUP


/****************************************************************************
 * Configuration
 ****************************************************************************/

/*
 * If the animation is a still image, it should display for a period. This
 * value configures the delay time of a still image displaying.
 */
#define MMI_ANI_STILL_IMAGE_DELAY_IN_MS  1500    /* ms */


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    U16 disp_id;
    fmgr_file_group_enum res_type;
    WCHAR *filepath;
#if defined(__MMI_POWER_ON_OFF_DISPLAY__)
    WCHAR filepath_buffer[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
#endif
} mmi_ani_resource_struct;

/*
 * The context of animation.
 */
typedef struct
{
    mmi_ani_param_struct param;
    mmi_ani_resource_struct ani_res;
    MMI_BOOL play_audio;
    MMI_BOOL is_playing_audio;
    MMI_BOOL is_playing_animation;
    U32 start_ticks;
    S32 drm_consumer;
    MMI_BOOL is_in_show_context;
} mmi_ani_cntx_struct;

typedef enum
{
    MMI_ANI_DISP_ID_FROM_FILE = 0x00,
    MMI_ANI_DISP_ID_FROM_FILE_SHORT_FILENAME = 0x01,
    /* Valid display IDs */
    MMI_ANI_DISP_ID_INVALID = 0xff,

    MMI_ANI_DISP_ID_END_OF_ENUM
} mmi_ani_disp_id_enum;


/****************************************************************************
 * Global variables
 ****************************************************************************/

static mmi_ani_cntx_struct *g_mmi_ani_cntx = NULL;


/****************************************************************************
 * Functions
 ****************************************************************************/

static void mmi_ani_finalize(void);
static void mmi_ani_check_and_callback(mmi_ani_cntx_struct *cntx);
static mmi_ret mmi_ani_callback_proc(mmi_event_struct *evt);


#ifdef __MMI_POWER_ON_OFF_DISPLAY__

typedef enum
{
    MMI_ANI_RESET_CAUSE_INVALID_DISP_ID = 1,
    MMI_ANI_RESET_CAUSE_LIMIT_CHECK_FAIL,
    MMI_ANI_RESET_CAUSE_INVALID_FILEPATH,
    MMI_ANI_RESET_CAUSE_NO_RIGHTS,

    MMI_ANI_RESET_CAUSE_END_OF_ENUM
} mmi_ani_reset_cause_enum;


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_get_res_type
 * DESCRIPTION
 *  Get resource type of the disp_id from phone setup.
 * PARAMETERS
 *  disp_id     [IN] The ID from phone setup
 * RETURNS
 *  fmgr_file_group_enum
 *****************************************************************************/
static fmgr_file_group_enum mmi_ani_get_res_type(U16 disp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PHNSET_TYPE_DISP phnset_disp_id;
    fmgr_file_group_enum res_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_type = FMGR_GROUP_IMAGE;

    phnset_disp_id = PhnsetGetDisplayType(disp_id);
    switch (phnset_disp_id)
    {
        case PHNSET_TYPE_DISP_IMAGE:
            res_type = FMGR_GROUP_IMAGE;
            break;

        case PHNSET_TYPE_DISP_VIDEO:
            res_type = FMGR_GROUP_VIDEO;
            break;

        default:
            MMI_ASSERT(MMI_FALSE);
            break;
    }

    return res_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_reset_to_default
 * DESCRIPTION
 *  Reset the animation to default one. Note the setting in phone will also be
 *  reset.
 * PARAMETERS
 *  ani_res     [OUT] Resource
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ani_reset_to_default(mmi_ani_cntx_struct *cntx, mmi_ani_reset_cause_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_RESET_TO_DEFAULT, (U32)cntx, cause);
    
    if (cntx->param.reset_to_default != NULL)
    {
        cntx->param.reset_to_default();
        cntx->ani_res.disp_id = cntx->param.get_disp_id();
        cntx->ani_res.res_type = mmi_ani_get_res_type(cntx->ani_res.disp_id);
        cntx->ani_res.filepath = NULL;
        cntx->ani_res.filepath_buffer[0] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_DRM_stop_consume
 * DESCRIPTION
 *  Call DRM_stop_consume for g_mmi_ani_cntx.drm_consumer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ani_DRM_stop_consume(void)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = g_mmi_ani_cntx;
    
    if (cntx != NULL && cntx->drm_consumer > 0)
    {
        DRM_stop_consume(cntx->drm_consumer);
        cntx->drm_consumer = 0;
    }
#endif
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ani_DRM_rights_consume_callback
 * DESCRIPTION
 *  The callback of DRM_consume_rights(). Stop consuming.
 * PARAMETERS
 *  result      [IN]
 *  id          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ani_DRM_rights_consume_callback(S32 result, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ani_DRM_stop_consume();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_consume_DRM_rights
 * DESCRIPTION
 *  Consume DRM rights.
 * PARAMETERS
 *  ani_res     [IN] Resource
 * RETURN VALUES
 *  MMI_TRUE  : if consumed successfully
 *  MMI_FALSE : if no rights or invalid DRM file
 *****************************************************************************/
static MMI_BOOL mmi_ani_consume_DRM_rights(mmi_ani_cntx_struct *cntx)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_permitted;
    U8 permission;
    FS_HANDLE fs_handle;
    mmi_ani_resource_struct *ani_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ani_res = &(cntx->ani_res);

    if (ani_res->filepath == NULL)
    {
        return MMI_TRUE;
    }

    is_permitted = MMI_FALSE;
    permission = 0;

    switch (ani_res->res_type)
    {
        case FMGR_GROUP_IMAGE:
            permission = DRM_PERMISSION_DISPLAY;
            break;

        case FMGR_GROUP_VIDEO:
            permission = DRM_PERMISSION_PLAY;
            break;

        default:
            return MMI_FALSE;
    }

    fs_handle = DRM_open_file(ani_res->filepath, FS_READ_ONLY, permission);
    
    /* DRM permission check */
    if (fs_handle > 0)
    {
        if (DRM_validate_forward_rule(fs_handle, permission))
        {
            is_permitted = MMI_TRUE;
            
        #ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
            if (ani_res->res_type == FMGR_GROUP_VIDEO)
            {
                wgui_catvdo_set_drm_flag(WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME_LIMIT_STOP);
            }
            else
        #endif /* __MMI_POWER_ON_OFF_DISPLAY_VIDEO__ */
            {
                cntx->drm_consumer = DRM_consume_rights(
                    fs_handle,
                    permission,
                    mmi_ani_DRM_rights_consume_callback);
            }
        }
        else
        {
            is_permitted = MMI_FALSE;
        }

        DRM_close_file(fs_handle);
    }
    else
    {
        is_permitted = MMI_FALSE;
    }

    MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_CONSUME_DRM_RIGHTS,
        (U32)cntx, is_permitted, permission, (U32)fs_handle);

    return is_permitted;
    
#else /* __DRM_SUPPORT__ */

    return MMI_TRUE;
    
#endif /* __DRM_SUPPORT__ */
}


#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_get_resource
 * DESCRIPTION
 *  Get the resource of power-on animation
 * PARAMETERS
 *  ani_res     [OUT] Resource
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ani_get_resource(mmi_ani_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ani_resource_struct *ani_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ani_res = &(cntx->ani_res);
    
#if defined(__MMI_POWER_ON_OFF_DISPLAY__)

    ani_res->disp_id = MMI_ANI_DISP_ID_INVALID;
    ani_res->res_type = FMGR_GROUP_UNKNOWN;
    ani_res->filepath = NULL;

    ani_res->disp_id = cntx->param.get_disp_id();
    MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_GET_DISP_ID, ani_res->disp_id);

    if (ani_res->disp_id == MMI_ANI_DISP_ID_INVALID)
    {
        mmi_ani_reset_to_default(cntx, MMI_ANI_RESET_CAUSE_INVALID_DISP_ID);
        return;
    }
    else if (ani_res->disp_id == MMI_ANI_DISP_ID_FROM_FILE ||
             ani_res->disp_id == MMI_ANI_DISP_ID_FROM_FILE_SHORT_FILENAME)
    {
        CHAR *error_str;

        ani_res->disp_id = MMI_ANI_DISP_ID_FROM_FILE;

        if (cntx->param.get_res_filepath(
            ani_res->filepath_buffer,
            sizeof(ani_res->filepath_buffer)))
        {
            if (mmi_fmgr_util_file_limit_check(
                FMGR_LIMIT_POWER_ON_OFF_DSPL,
                (CHAR*)ani_res->filepath_buffer,
                &error_str))
            {
                ani_res->filepath = ani_res->filepath_buffer;
            }
            else
            {
                mmi_ani_reset_to_default(cntx, MMI_ANI_RESET_CAUSE_LIMIT_CHECK_FAIL);
                return;
            }
        }
        else
        {
            mmi_ani_reset_to_default(cntx, MMI_ANI_RESET_CAUSE_INVALID_FILEPATH);
            return;
        }
    }

    /* Get resource type*/
    if (ani_res->filepath == NULL)
    {
        ani_res->res_type = mmi_ani_get_res_type(ani_res->disp_id);
    }
    else
    {
        ani_res->res_type = srv_fmgr_types_find_group_by_filename_str((WCHAR*)ani_res->filepath);
    }

#else

    MMI_ASSERT(cntx->param.get_disp_id != NULL);
    ani_res->disp_id = cntx->param.get_disp_id();
    ani_res->res_type = FMGR_GROUP_IMAGE;
    ani_res->filepath = NULL;

#endif /* defined(__MMI_POWER_ON_OFF_DISPLAY__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_gdi_callback
 * DESCRIPTION
 *  Category callback of GDI_RESULT parameter
 * PARAMETERS
 *  result      [IN] Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ani_gdi_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_GDI_CALLBACK, result);
    
    cntx = g_mmi_ani_cntx;

    if (cntx == NULL)
    {
        return;
    }

#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    if (result < 0)
    {
        cntx->param.reset_to_default();
    }
    else
#endif
    if (result == GDI_IMAGE_IS_STILL_IMAGE &&
                MMI_ANI_STILL_IMAGE_DELAY_IN_MS > 0)
    {
        U32 end_ticks;
        U32 past_secs;

        kal_get_time(&end_ticks);
        past_secs = kal_ticks_to_milli_secs(end_ticks - cntx->start_ticks);

        if (past_secs < MMI_ANI_STILL_IMAGE_DELAY_IN_MS)
        {
            StartTimer(
                BOOTUP_ANIMATION_TIMER,
                MMI_ANI_STILL_IMAGE_DELAY_IN_MS - past_secs,
                mmi_ani_finalize);
            return;
        }
    }

    mmi_ani_finalize();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_audio_completed_callback
 * DESCRIPTION
 *  Callback for audio playing completed.
 * PARAMETERS
 *  interrupt_evnet     [IN]
 * RETURNS
 *  MMI_FALSE
 *****************************************************************************/
static srv_prof_ret mmi_ani_audio_completed_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_AUDIO_COMPLETED);
    
    if (g_mmi_ani_cntx != NULL)
    {
        g_mmi_ani_cntx->is_playing_audio = MMI_FALSE;
        mmi_ani_check_and_callback(g_mmi_ani_cntx);
    }

    return 0;
}


#ifdef __MMI_POWER_ON_OFF_DISPLAY__
/*****************************************************************************
 * FUNCTION
 *  mmi_ani_mdi_callback
 * DESCRIPTION
 *  Category callback of MDI_RESULT parameter
 * PARAMETERS
 *  result      [IN] Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ani_mdi_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_MDI_CALLBACK, result);
    
    cntx = g_mmi_ani_cntx;

    if (cntx == NULL)
    {
        return;
    }
    
    if (result < 0)
    {
        cntx->param.reset_to_default();
    }

    mmi_ani_finalize();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_exit_animation
 * DESCRIPTION
 *  Exit function of animation screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ani_exit_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_ani_cntx_struct*)mmi_frm_scrn_get_user_data(
        mmi_frm_group_get_active_id(),
        mmi_frm_scrn_get_active_id());

    if (cntx->param.grp_id != mmi_frm_group_get_active_id() ||
        cntx->param.scr_id != mmi_frm_scrn_get_active_id())
    {
        return;
    }
    
    gui_cancel_timer(mmi_ani_finalize);

    srv_backlight_turn_off(); /* To start backlight timer */
#if !defined(__MMI_BOOTUP_SLIM__)
    if (cntx->param.led_control != NULL)
    {
        cntx->param.led_control(MMI_ANI_LED_COMMAND_STOP);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_leave_proc
 * DESCRIPTION
 *  Leave proc to prevent the animation from being deleted.
 * PARAMETERS
 *  evt     [IN] 
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_ani_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SCRN_GOBACK ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY)
    {
        return -1;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_key_proc
 * DESCRIPTION
 *  Key proc to block End key and Power key.
 * PARAMETERS
 *  evt     [IN] 
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_ani_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__) || !defined(__MMI_BOOTUP_SLIM__)
    mmi_ani_cntx_struct *cntx;
    mmi_frm_key_evt_struct *key_evt;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__) || !defined(__MMI_BOOTUP_SLIM__)
    cntx = (mmi_ani_cntx_struct*)evt->user_data;
    key_evt = (mmi_frm_key_evt_struct*)evt;
#endif

#ifdef __DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__
    if (cntx->param.key_proc != NULL)
    {
        mmi_frm_key_evt_struct pass_key_evt;

        memcpy(&pass_key_evt, key_evt, sizeof(mmi_frm_key_evt_struct));
        pass_key_evt.user_data = cntx->param.user_data;
    
        if (cntx->param.key_proc(evt) == MMI_RET_KEY_HANDLED)
        {
            return MMI_RET_KEY_HANDLED;
        }
    }
#endif /* __DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__ */

#if !defined(__MMI_BOOTUP_SLIM__)
    if (evt->evt_id == EVT_ID_PRE_KEY)
    {
        if (key_evt->key_code == KEY_END &&
            key_evt->key_type == KEY_EVENT_DOWN)
        {
            if (!cntx->param.end_key_to_exit)
            {
                /* Avoid end key to delete screen */
                return MMI_RET_KEY_HANDLED;
            }
        }
    }
    else if (evt->evt_id == EVT_ID_ON_KEY)
    {
        if (key_evt->key_code == KEY_END &&
            key_evt->key_type == KEY_EVENT_DOWN &&
            cntx->param.end_key_to_exit)
        {
            mmi_ani_finalize();
            return MMI_RET_KEY_HANDLED;
        }
    }
#endif

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_entry_animation
 * DESCRIPTION
 *  Entry function of animation
 * PARAMETERS
 *  es_data     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
// slim_static
static void mmi_ani_entry_animation(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ani_cntx_struct *cntx;
    mmi_ani_resource_struct *ani_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(es_data != NULL && es_data->user_data != NULL);

    cntx = (mmi_ani_cntx_struct*)es_data->user_data;
        
    if (!mmi_frm_scrn_enter(
            cntx->param.grp_id,
            cntx->param.scr_id,
            mmi_ani_exit_animation,
            (FuncPtr)mmi_ani_entry_animation,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ani_res = &(cntx->ani_res);

    MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_ENTRY_ANIMATION_ENTERED,
        cntx->is_playing_animation, cntx->param.play_audio);
    MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_ENTRY_ANIMATION_RESOURCE,
        ani_res->disp_id, ani_res->res_type, (U32)ani_res->filepath);

    if (cntx->param.timeout > 0)
    {
        gui_start_timer(cntx->param.timeout, mmi_ani_finalize);
    }

#if !defined(__MMI_BOOTUP_SLIM__)
    if (cntx->param.led_control != NULL)
    {
        cntx->param.led_control(MMI_ANI_LED_COMMAND_START);
    }
#endif
    
    cntx->is_playing_animation = MMI_TRUE;

    switch (ani_res->res_type)
    {
        case FMGR_GROUP_IMAGE:

        #ifndef __MMI_POWER_ON_OFF_MUTE__
            /*
             * Play power-on sound on the first time of show animation.
             */
            if (cntx->play_audio)
            {
                if (srv_prof_play_tone(cntx->param.audio, mmi_ani_audio_completed_callback) ==
                    SRV_PROF_RET_SUCCESS)
                {
                    cntx->is_playing_audio = MMI_TRUE;
                }
                cntx->play_audio = MMI_FALSE;
            }
        #endif

            mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
            
            ShowCategory166Screen(
                ani_res->disp_id,
                (CHAR*)ani_res->filepath,
                mmi_ani_gdi_callback);
                
            break;

#ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
        case FMGR_GROUP_VIDEO:
        {
            srv_prof_volume_level volume_level;
            U8 *gui_buffer;

            srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, &volume_level);
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8)volume_level);

            mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);

            gui_buffer = mmi_frm_scrn_get_active_gui_buf();
            ShowCategory224Screen(
                ani_res->disp_id,               /* video id */
                (CHAR*)ani_res->filepath,         /* filename */
                1,                              /* repeat_count; 0 means infinite */
                (BOOL)MMI_TRUE,                 /* is_visaul_update */
                (BOOL)cntx->play_audio,         /* is_play_audio */
                (BOOL)MMI_FALSE,                /* is_lcd_sleep *//* already in non-sleep mode */
                GDI_COLOR_BLACK,                /* bg_color */
                mmi_ani_mdi_callback,           /* (*play_finish_callback)(S16) */
                (void*)gui_buffer);             /* gui_buffer */
            
            break;
        }
#endif /* __MMI_POWER_ON_OFF_DISPLAY_VIDEO__ */

        default:
            /* Unsupported type */
            mmi_ani_finalize();
            return;
    }

    /*
     * [MAUI_02338970]
     * Turn on backlight after show category, otherwise user will see the mass
     * data before animation screen for phone-reset case.
     */
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

    mmi_frm_scrn_set_key_proc(cntx->param.grp_id, cntx->param.scr_id, mmi_ani_key_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_finalize
 * DESCRIPTION
 *  To finalize animation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ani_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ani_cntx_struct *cntx;
    mmi_ani_resource_struct *ani_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = g_mmi_ani_cntx;

    if (cntx == NULL || !cntx->is_playing_animation)
    {
        /* Ignore */
        return;
    }

    MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_FINALIZE,
        cntx->start_ticks, cntx->is_in_show_context);

    cntx->is_playing_animation = MMI_FALSE;
    gui_cancel_timer(mmi_ani_finalize);
    
    ani_res = &(cntx->ani_res);
    
    if (mmi_frm_group_get_active_id() == cntx->param.grp_id &&
        mmi_frm_scrn_get_active_id() == cntx->param.scr_id)
    {
        switch (ani_res->res_type)
        {
            case FMGR_GROUP_IMAGE:
                StopCategory166Animation();
                break;

#ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
            case FMGR_GROUP_VIDEO:
                StopCategory224Video();
                break;
#endif /* __MMI_POWER_ON_OFF_DISPLAY_VIDEO__ */

            default:
                break;
        }
    }
    
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    mmi_ani_DRM_stop_consume();
#endif /* __DRM_SUPPORT__ */

    mmi_ani_check_and_callback(cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_check_and_callback
 * DESCRIPTION
 *  Check whether the animation can complete or not. If yes, call the callback.
 * PARAMETERS
 *  cntx        [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ani_check_and_callback(mmi_ani_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->param.wait_for_audio && cntx->is_playing_audio)
    {
        return;
    }

    if (cntx->is_playing_animation)
    {
        return;
    }

    if (cntx->param.completed_callback != NULL)
    {
        if (cntx->is_in_show_context)
        {
            mmi_event_struct evt;
            
            /*
             * We should not call callback in the context of mmi_ani_show(),
             * postpone callback.
             */
            MMI_FRM_INIT_EVENT(&evt, 0);
            MMI_FRM_POST_EVENT(&evt, mmi_ani_callback_proc, cntx);
        }
        else
        {
            void (*completed_callback)(void *user_data, mmi_ani_handle handle);
        
            MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_CALLBACK, 0, (U32)cntx->param.completed_callback);
            completed_callback = cntx->param.completed_callback;
            cntx->param.completed_callback = NULL;
            completed_callback(cntx->param.user_data, cntx);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_callback_proc
 * DESCRIPTION
 *  Proc for postponed callback. This proc will invoke the callback function.
 * PARAMETERS
 *  evt     [IN] Event
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_ani_callback_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_ani_cntx_struct*)evt->user_data;
    
    if (cntx->param.completed_callback != NULL)
    {
        void (*completed_callback)(void *user_data, mmi_ani_handle handle);
        
        MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_CALLBACK, 1, (U32)cntx->param.completed_callback);
        completed_callback = cntx->param.completed_callback;
        cntx->param.completed_callback = NULL;
        completed_callback(cntx->param.user_data, cntx);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_create
 * DESCRIPTION
 *  Create an animation instance.
 * PARAMETERS
 *  param   [IN] Parameter to create instance
 * RETURNS
 *  Handle of the instance
 *****************************************************************************/
mmi_ani_handle mmi_ani_create(const mmi_ani_param_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_ani_cntx_struct*)OslMalloc(sizeof(mmi_ani_cntx_struct));
    
    cntx->param = *param;
    mmi_ani_get_resource(cntx);
    cntx->play_audio = MMI_FALSE;
    cntx->is_playing_audio = MMI_FALSE;
    cntx->is_playing_animation = MMI_FALSE;
    cntx->start_ticks = 0;
    cntx->drm_consumer = 0;

    return cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_show
 * DESCRIPTION
 *  Show animation screen of the given instance.
 * PARAMETERS
 *  handle  [IN] Instance handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ani_show(mmi_ani_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_ani_cntx_struct*)handle;

    if (g_mmi_ani_cntx != NULL)
    {
        /* Callback to previous app, so that previos instance can be closed */
        MMI_ASSERT(!g_mmi_ani_cntx->is_in_show_context);
        mmi_ani_finalize();
    }

    /* No present instance */
    MMI_ASSERT(g_mmi_ani_cntx == NULL);
    
    g_mmi_ani_cntx = cntx;
    cntx->is_in_show_context = MMI_TRUE;
    
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    if (!mmi_ani_consume_DRM_rights(cntx))
    {
        mmi_ani_reset_to_default(cntx, MMI_ANI_RESET_CAUSE_NO_RIGHTS);
    }
#endif
    
    cntx->play_audio = cntx->param.play_audio;

    kal_get_time(&(cntx->start_ticks));

    MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_SHOW, (U32)cntx, cntx->start_ticks);

    mmi_frm_scrn_first_enter(
        cntx->param.grp_id,
        cntx->param.scr_id,
        (FuncPtr)mmi_ani_entry_animation,
        cntx);

    mmi_frm_scrn_set_leave_proc(
        cntx->param.grp_id,
        cntx->param.scr_id,
        mmi_ani_leave_proc);

    cntx->is_in_show_context = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ani_close
 * DESCRIPTION
 *  Close the screen and release instance.
 * PARAMETERS
 *  handle  [IN] Instance handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ani_close(mmi_ani_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle == MMI_ANI_INVALID_HANDLE)
    {
        return;
    }

    MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_CLOSE, (U32)handle);
    
    cntx = (mmi_ani_cntx_struct*)handle;
    MMI_ASSERT(cntx == g_mmi_ani_cntx);
    g_mmi_ani_cntx = NULL;

    cntx->param.completed_callback = NULL; /* Avoid callback by finalize() */
    mmi_ani_finalize();

    mmi_frm_scrn_set_leave_proc(cntx->param.grp_id, cntx->param.scr_id, NULL);
    mmi_frm_scrn_close(cntx->param.grp_id, cntx->param.scr_id);

    OslMfree(cntx);
}

#ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
/*****************************************************************************
 * FUNCTION
 *  mmi_ani_pause_video
 * DESCRIPTION
 *  Pause video playing of the instance.
 * PARAMETERS
 *  handle  [IN] Instance handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ani_pause_video(mmi_ani_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_ani_cntx_struct*)handle;
    MMI_ASSERT(cntx == g_mmi_ani_cntx);

    MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_PAUSE_RESUME,
        'P', (U32)cntx, cntx->is_playing_animation);

    if (cntx->is_playing_animation &&
        cntx->ani_res.res_type == FMGR_GROUP_VIDEO &&
        cntx->param.grp_id == mmi_frm_group_get_active_id() &&
        cntx->param.scr_id == mmi_frm_scrn_get_active_id())
    {
        PauseCategory224Video();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ani_resume_video
 * DESCRIPTION
 *  Resume video playing of the instance.
 * PARAMETERS
 *  handle  [IN] Instance handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ani_resume_video(mmi_ani_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ani_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_ani_cntx_struct*)handle;
    MMI_ASSERT(cntx == g_mmi_ani_cntx);

    MMI_TRACE(MMI_ANI_TRC_GROUP, TRC_MMI_ANI_PAUSE_RESUME,
        'R', (U32)cntx, cntx->is_playing_animation);

    if (cntx->is_playing_animation &&
        cntx->ani_res.res_type == FMGR_GROUP_VIDEO &&
        cntx->param.grp_id == mmi_frm_group_get_active_id() &&
        cntx->param.scr_id == mmi_frm_scrn_get_active_id())
    {
        ResumeCategory224Video();
    }
}
#endif /* #ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__ */

