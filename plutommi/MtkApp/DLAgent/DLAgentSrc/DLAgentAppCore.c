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
 *
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *   
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
 
 
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"
#if defined (__MMI_DOWNLOAD_AGENT__)

#include "DLAgentAppScr.h"
#include "DLAgentSrvProt.h"
#include "DLAgentSrvIProt.h"
#include "mmi_rp_app_downloadagent_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "app_mine.h"
#ifdef __MMI_DOWNLOAD_AGENT__
#include "mmi_rp_srv_downloadagent_def.h"
#endif

const static mmi_da_mime_type_str_struct mmi_da_mime_type_string_tbl[] =
{
    {MIME_SUBTYPE_JPEG,		     STR_DA_IMAGE_FILE},   /*      image/jpeg */
    {MIME_SUBTYPE_VCARD,         STR_DA_VCARD_FILE},
    {MIME_SUBTYPE_XVCARD,        STR_DA_VCARD_FILE},
    {MIME_SUBTYPE_CALENDAR,      STR_DA_VCALENDAR_FILE},
    {MIME_SUBTYPE_XVCALENDAR,    STR_DA_VCALENDAR_FILE},
    {MIME_SUBTYPE_XIMELODY,      STR_DA_AUDIO_FILE},   /*      text/x-imelody */
    {MIME_SUBTYPE_THEME,         STR_DA_APP_FILE},
#ifdef M3D_MMI_SUPPORT
    {MIME_SUBTYPE_M3D,           STR_DA_IMAGE_FILE},
#endif
#if defined(MP4_DECODE)
    {MIME_SUBTYPE_3GPP_AUDIO,    STR_DA_VIDEO_FILE},
#endif
    {MIME_SUBTYPE_UNRECOGNIZED,  STR_DA_UNKNOWN_FILE} /*      Un-recognized file type */

};
const static S32 mmi_da_mime_type_string_num = sizeof(mmi_da_mime_type_string_tbl) / sizeof(mmi_da_mime_type_str_struct);


/*****************************************************************************
* FUNCTION
*  srv_da_search_mime_type_string
* DESCRIPTION
*  Search the mime type string in table by mime_subtype
* PARAMETERS
*  mime_subtype    IN  Which mime_subtype you want to search.
* RETURNS
*  The string id
*****************************************************************************/
UI_string_ID_type mmi_da_search_mime_type_string(const applib_mime_type_struct * type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(type == NULL)
    {
        return STR_DA_UNKNOWN_FILE;
    }
    for (i = mmi_da_mime_type_string_num - 1; i >= 0; i--)
    {
        if (type->mime_subtype == mmi_da_mime_type_string_tbl[i].mime_subtype)
        {
            return mmi_da_mime_type_string_tbl[i].string_id;
        }
    }

    switch (type->mime_type)
    {
        case MIME_TYPE_TEXT:
            return STR_DA_TEXT_FILE;
        case MIME_TYPE_IMAGE:
            return STR_DA_IMAGE_FILE;
        case MIME_TYPE_AUDIO:
            return STR_DA_AUDIO_FILE;
        case MIME_TYPE_VIDEO:
            return STR_DA_VIDEO_FILE;
        case MIME_TYPE_APPLICATION:
            return STR_DA_APP_FILE;
        case MIME_TYPE_MESSAGE:
            return STR_DA_MSG_FILE;
        case MIME_TYPE_MULTIPART:
            return STR_DA_MULTI_FILE;
        default:
            return STR_DA_UNKNOWN_FILE;
    }

    
}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_ICON_BAR_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_da_toolbar_get_details_config
 * DESCRIPTION
 *  Get the toolbar configuration of Details.
 * PARAMETERS
 *  job     [IN]
 *  config  [OUT] Config
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_toolbar_get_details_config(
    const srv_da_job_struct *job,
    mmi_da_toolbar_config_struct *config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    config->is_enabled = MMI_TRUE;
    config->enabled_img_id = IMG_GLOBAL_TOOLBAR_DETAIL;
    config->disabled_img_id = IMG_GLOBAL_TOOLBAR_DETAIL_DISABLED;
    config->prompt_str_id = STR_GLOBAL_DETAILS;
    config->handler = mmi_da_app_job_on_details_selected;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_toolbar_get_play_use_config
 * DESCRIPTION
 *  Get the toolbar configuration of Play/Use.
 * PARAMETERS
 *  job     [IN]
 *  config  [OUT] Config
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_toolbar_get_play_use_config(
    const srv_da_job_struct *job,
    mmi_da_toolbar_config_struct *config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job->state == SRV_DA_JOB_STATE_DOWNLOADING &&
        job->setting_info.filepath_hdlr != NULL &&
        job->setting_info.report_hdlr != NULL)
    {
        if (!job->reporting)
        {
            config->is_enabled = MMI_TRUE;
        }
        else
        {
            config->is_enabled = MMI_FALSE;
        }
        config->enabled_img_id = IMG_ID_DA_TOOLBAR_PLAY;
        config->disabled_img_id = IMG_ID_DA_TOOLBAR_PLAY_DISABLED;
        config->prompt_str_id = STR_GLOBAL_PLAY;
        config->handler = mmi_da_job_on_play_selected;
    }
    else if (job->state == SRV_DA_JOB_STATE_COMPLETED)
    {
        if (!job->setting_info.do_dispatch || job->type_handler->dispatch_hdlr == NULL)
        {
            config->is_enabled = MMI_FALSE;
        }
        else if (job->type_handler->dispatch_hdlr == srv_da_get_default_mime_type_handler()->dispatch_hdlr &&
            !srv_da_util_is_supported_by_fmgr(job->op->get_filepath(job)))
        {
            config->is_enabled = MMI_FALSE;
        }
        else
        {
            config->is_enabled = MMI_TRUE;
        }
        config->enabled_img_id = IMG_GLOBAL_TOOLBAR_OPEN;
        config->disabled_img_id = IMG_GLOBAL_TOOLBAR_OPEN_DISABLED;
        config->prompt_str_id = STR_ID_DA_JOB_USE;
        config->handler = mmi_da_job_on_use_file_selected;
    }
    else
    {
        config->is_enabled = MMI_FALSE;
        config->enabled_img_id = IMG_GLOBAL_TOOLBAR_OPEN;
        config->disabled_img_id = IMG_GLOBAL_TOOLBAR_OPEN_DISABLED;
        config->prompt_str_id = STR_ID_DA_JOB_USE;
        config->handler = NULL;
    }
}


#ifdef __MMI_DA_RESUME__
/*****************************************************************************
 * FUNCTION
 *  mmi_da_toolbar_get_suspend_resume_config
 * DESCRIPTION
 *  Get the toolbar configuration of Suspend/Resume.
 * PARAMETERS
 *  job     [IN]
 *  config  [OUT] Config
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_toolbar_get_suspend_resume_config(
    const srv_da_job_struct *job,
    mmi_da_toolbar_config_struct *config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job->state == SRV_DA_JOB_STATE_DOWNLOADING && job->op->resume != NULL)
    {
        config->is_enabled = MMI_TRUE;
        config->enabled_img_id = IMG_ID_DA_TOOLBAR_SUSPEND;
        config->disabled_img_id = IMG_ID_DA_TOOLBAR_SUSPEND_DISABLED;
        config->prompt_str_id = STR_GLOBAL_PAUSE;
        config->handler = mmi_da_job_on_suspend_selected;
    }
    else if (job->state == SRV_DA_JOB_STATE_PAUSED && job->op->resume != NULL)
    {
        config->is_enabled = MMI_TRUE;
        config->enabled_img_id = IMG_ID_DA_TOOLBAR_RESUME;
        config->disabled_img_id = IMG_ID_DA_TOOLBAR_SUSPEND_DISABLED;
        config->prompt_str_id = STR_ID_DA_JOB_RESUME;
        config->handler = mmi_da_job_on_resume_selected;
    }
    else
    {
        config->is_enabled = MMI_FALSE;
        config->enabled_img_id = IMG_ID_DA_TOOLBAR_SUSPEND;
        config->disabled_img_id = IMG_ID_DA_TOOLBAR_SUSPEND_DISABLED;
        config->prompt_str_id = STR_GLOBAL_PAUSE;
        config->handler = NULL;
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_da_toolbar_get_cancel_remove_config
 * DESCRIPTION
 *  Get the toolbar configuration of Cancel/Remove.
 * PARAMETERS
 *  job     [IN]
 *  config  [OUT] Config
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_da_toolbar_get_cancel_remove_config(
    const srv_da_job_struct *job,
    mmi_da_toolbar_config_struct *config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job->state == SRV_DA_JOB_STATE_DOWNLOADING ||
        job->state == SRV_DA_JOB_STATE_PROCESSING ||
        job->state == SRV_DA_JOB_STATE_PAUSED)
    {
        config->is_enabled = MMI_TRUE;
        config->enabled_img_id = IMG_ID_DA_TOOLBAR_CANCEL;
        config->disabled_img_id = IMG_ID_DA_TOOLBAR_CANCEL_DISABLED;
        config->prompt_str_id = STR_GLOBAL_CANCEL;
        config->handler = mmi_da_job_on_cancel_selected;
    }
    else if (job->state == SRV_DA_JOB_STATE_COMPLETED)
    {
        config->is_enabled = MMI_TRUE;
        config->enabled_img_id = IMG_ID_DA_TOOLBAR_REMOVE;
        config->disabled_img_id = IMG_ID_DA_TOOLBAR_CANCEL_DISABLED;
        config->prompt_str_id = STR_GLOBAL_REMOVE;
        config->handler = mmi_da_job_on_remove_selected;
    }
    else
    {
        config->is_enabled = MMI_FALSE;
        config->enabled_img_id = IMG_ID_DA_TOOLBAR_CANCEL;
        config->disabled_img_id = IMG_ID_DA_TOOLBAR_CANCEL_DISABLED;
        config->prompt_str_id = STR_GLOBAL_CANCEL;
        config->handler = NULL;
    }
}
#endif 
#endif /*__MMI_DOWNLOAD_AGENT__ */
