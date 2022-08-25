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
 *  mdi_mtv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access mobile tv related functions.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/*****************************************************************************
* Include
*****************************************************************************/

#include "MMI_features.h"
#if defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)

#include "gdi_include.h"        /* include data type */

#include "med_api.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "med_api.h"    /* media task */
#include "mdi_mtv.h"    /* include camera related define */

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"
#endif

#include "lcd_if.h"


#include "med_api.h"
#include "med_main.h"
#include "med_struct.h"


#include "img_common_enum.h"


#ifdef __MMI_BT_AUDIO_VIA_SCO__
#include "BthScoPathSrvGProt.h"
#endif


#include "MMI_media_app_trc.h"
#include "MMIDataType.h"
#include "mdi_enum.h"
#include "kal_general_types.h"
#include "mtv_esg_define.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_srv_mdi_def.h"
#include "GlobalResDef.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "mdi_audio.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "app_datetime.h"
#include "mtv_esg_query_datatype.h"
#include "cmmb_eb.h"
#include "mpl_recorder.h"
#include "custom_video_enc_if.h"
#include "TimerEvents.h"
#include "DtcntSrvGprot.h"

#ifdef __MM_DCM_SUPPORT__
#include "dcmgr.h"
#endif

/*****************************************************************************
* Typedef
*****************************************************************************/
typedef struct
{
    U32 context;
    U32 db_context;
    U32 service_id;
    mdi_mtv_service_type_enum service_type;
    U16 app_id;
    void *user_data;

    U32 service_seq_no;
    U32 player_seq_no;
    U32 recorder_seq_no;
    U32 scanning_seq_no;

    /* video data */
    U16 brightness;
    U16 contrast;
    U16 saturation;
    U16 gamma;
    U8 record_size;
    U32 audio_mode;
    MMI_BOOL is_tvout;
    U16 hw_rotator_rotate;

    /* audio data */
    kal_uint8 play_audio;
    kal_uint8 audio_path;
    kal_bool mute;
    kal_uint32 volume;
    MMI_BOOL block_query;

    /* recorder data */
    pBOOL enable_timeshift;         /**< indicate whether to enable time-shift */
    U32 max_timeshift_delay;        /**< maximum time-shift delay in seconds. set it to 0 if don't care */
    U32 max_timeshift_buffer_kb;    /**< maximum time-shift buffer size. set it to 0 if don't care */
    U8* record_dir;                 /**< the directory to save recorded programs */

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    /* ESG */
    esg_query_type_enum query_type;
#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */
#if defined(__MMI_ATV_SUPPORT__)
    media_mtv_atv_video_mode_enum video_mode;
#endif
    U16 tvout_prev_owner;

    mdi_mtv_service_state_enum service_state;
    mdi_mtv_player_state_enum player_state;
    mdi_mtv_recorder_state_enum recorder_state;
    mdi_mtv_setting_struct setting;
    mdi_mtv_service_config_struct service_config;
#ifndef __MTK_TARGET__
    U8 scan_progress;
#endif
}mdi_mtv_context_struct;

/*****************************************************************************
* Local variable
*****************************************************************************/

mdi_mtv_context_struct mdi_mtv_context;
mdi_mtv_context_struct *mdi_mtv_p = &mdi_mtv_context;

#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
volatile kal_timerid matv_resz_cp_ESD_timeout_timer = NULL;
#endif


/*****************************************************************************
* Local Function
*****************************************************************************/
static void mdi_mtv_service_found_hdlr(void* local_param);
static void mdi_mtv_search_progress_hdlr(void* local_param);
static void mdi_mtv_system_event_hdlr(void* local_param);
static void mdi_mtv_service_event_hdlr(void* local_param);
static void mdi_mtv_complete_recovering_hdlr(void *local_param);
static S32 mdi_mtv_player_med_err_to_mdi_err(U32 med_err);
static void mdi_mtv_player_reset_video_setting(void);
static MDI_RESULT mdi_mtv_player_config_player_setting(U32 mtv_handle, mdi_mtv_player_setting_struct *setting_p);
MDI_RESULT mdi_mtv_open_internal(const U16 app_id,
                        U32 *mtv_handle,
                        mdi_mtv_setting_struct* mtv_setting,
                        mdi_mtv_service_config_struct* mtv_service_config);

#ifdef __MM_DCM_SUPPORT__
static void mdi_mtv_dcm_load(void);
static void mdi_mtv_dcm_unload(void);
#endif

MMI_ID_TYPE mdi_mtv_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *popup_type = MMI_EVENT_FAILURE;
    switch (error_code)
    {
        case MDI_RES_MTV_ERR_DEVICE_BUSY:
            string_id = STR_ID_MDI_MTV_DEVICE_BUSY;
            break;
        case MDI_RES_MTV_ERR_DISC_IO_ERROR:
            string_id = STR_ID_MDI_MTV_STORAGE_IO_ERROR;
            break;
        case MDI_RES_MTV_ERR_VIDEO_ERROR:
            string_id = STR_ID_MDI_MTV_VIDEO_ERROR;
            break;
        case MDI_RES_MTV_ERR_AUDIO_ERROR:
            string_id = STR_ID_MDI_MTV_AUDIO_ERROR;
            break;
        case MDI_RES_MTV_ERR_STORAGE_NOT_READY:
            string_id = STR_ID_MDI_MTV_STORAGE_NOT_READY;
            break;
        case MDI_RES_MTV_ERR_DISC_FULL:
            string_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
            break;
        case MDI_RES_MTV_ERR_PAUSE_FAILED:
            string_id = STR_ID_MDI_MTV_FAILED_TO_PAUSE;
            break;
        case MDI_RES_MTV_ERR_RECORD_FAILED:
        case MDI_RES_MTV_ERR_RECORD_RESUME_FAILED:
            string_id = STR_ID_MDI_COMMON_RECORD_FAIL;
            break;
        case MDI_RES_MTV_ERR_SET_SPEED_FAILED:
            string_id = STR_ID_MDI_MTV_FAILED_TO_SET_SPEED;
            break;
        case MDI_RES_MTV_ERR_SNAPSHOT_FAILED:
            string_id = STR_ID_MDI_MTV_FAILED_TO_SNAPSHOT;
            break;
        case MDI_RES_MTV_ERR_OVER_LIMIT:
            string_id = STR_ID_MDI_MTV_OVER_LIMIT;
            break;
        case MDI_RES_MTV_ERR_SAVE_FAILED:
            string_id = STR_GLOBAL_FAILED_TO_SAVE;
            break;
    #if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
        case MDI_RES_MTV_MBBMS_DEVICE_AUTHENTICATION_FAILED:
            string_id = STR_ID_MDI_MTV_DEVICE_AUTHENTICATION_FAILED;
            break;
        case MDI_RES_MTV_MBBMS_PURCHASE_ITEM_UNKNOWN:
            string_id = STR_ID_MDI_MTV_PURCHASE_ITEM_UNKNOWN;
            break;
        case MDI_RES_MTV_MBBMS_SERVICE_ERROR:
            string_id = STR_ID_MDI_MTV_SERVICE_ERROR;
            break;
        case MDI_RES_MTV_MBBMS_MAL_FORMED_MESSAGE_ERROR:
            string_id = STR_ID_MDI_MTV_MAL_FORMED_MESSAGE_ERROR;
            break;
        case MDI_RES_MTV_MBBMS_NO_SUBSCRIPTION:
            string_id = STR_ID_MDI_MTV_NO_SUBSCRIPTION;
            break;
        case MDI_RES_MTV_MBBMS_OPERATION_NOT_PERMITTED:
            string_id = STR_ID_MDI_MTV_OPERATION_NOT_PERMITTED;
            break;
        case MDI_RES_MTV_MBBMS_REQUESTED_SERVICE_UNAVAILABLE:
            string_id = STR_ID_MDI_MTV_REQUESTED_SERVICE_UNAVAILABLE;
            break;
        case MDI_RES_MTV_MBBMS_REQUESTED_SERVICE_ACCEPTED:
            string_id = STR_ID_MDI_MTV_REQUESTED_SERVICE_ACCEPTED;
            break;
        case MDI_RES_MTV_MBBMS_INVALID_REQUEST:
            string_id = STR_ID_MDI_MTV_INVALID_REQUEST;
            break;
        case MDI_RES_MTV_MBBMS_DELIVERY_OF_WRONG_KEY_INFORMATION:
            string_id = STR_ID_MDI_MTV_DELIVERY_OF_WRONG_KEY_INFORMATION;
            break;
        case MDI_RES_MTV_MBBMS_ALREADY_IN_USE:
            string_id = STR_ID_MDI_MTV_ALREADY_IN_USE;
            break;
        case MDI_RES_MTV_MBBMS_NO_MATCHING_FRAGMENT:
            string_id = STR_ID_MDI_MTV_NO_MATCHING_FRAGMENT;
            break;
        case MDI_RES_MTV_MBBMS_NOW_SUBSCRIBED:
            string_id = STR_ID_MDI_MTV_NOW_SUBSCRIBED;
            break;
        case MDI_RES_MTV_MBBMS_INSUFFICIENT_CHARGE:
            string_id = STR_ID_MDI_MTV_INSUFFICIENT_CHARGE;
            break;
        case MDI_RES_MTV_MBBMS_INVALID_NW_PARAM:
            string_id = STR_ID_MDI_MTV_INVALID_NW_PARAM;
            break;
        case MDI_RES_MTV_MBBMS_NW_TIMEOUT:
            string_id = STR_ID_MDI_MTV_NW_TIMEOUT;
            break;
        case MDI_RES_MTV_ERR_MSK_RETRIEVE_FAIL:
            string_id = STR_ID_MDI_MTV_FAIL_TO_RETRIEVE_MSK;
            break;
        case MDI_RES_MTV_ERR_ACCOUNT_INQUIRY_FAIL:
            string_id = STR_ID_MDI_MTV_FAIL_TO_ACCOUNT_INQUIRY;
            break;
        case MDI_RES_MTV_ERR_SUBSCRIBE_FAIL:
            string_id = STR_ID_MDI_MTV_FAIL_TO_SUBSCRIBE;
            break;
        case MDI_RES_MTV_ERR_UNSUBSCRIBE_FAIL:
            string_id = STR_ID_MDI_MTV_FAIL_TO_UNSUBSCRIBE;
            break;
        case MDI_RES_MTV_ERR_AREA_RETRIEVE_FAIL:
            string_id = STR_ID_MDI_MTV_FAIL_TO_RETRIEVE_AREA; 
            break;
        case MDI_RES_MTV_ERR_INTERACTIVITY_RETRIEVE_FAIL:

            string_id = STR_ID_MDI_MTV_FAIL_TO_RETRIEVE_INTERACTIVITY;
            break;
    #endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */
        default:
            string_id = STR_GLOBAL_ERROR;
            break;
    }
    return string_id;
}

#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
void mdi_mtv_msg_restart(U32 mtv_handle)
{
    media_mtv_player_restart_chip(MOD_MMI, mtv_handle,mdi_mtv_p->service_id,mdi_mtv_p->player_seq_no);
}
#endif


void mdi_mtv_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
    //  timer for esd
    matv_resz_cp_ESD_timeout_timer = kal_create_timer("MDP_ESD_CP_CRZ_TIMEOUT");
#endif

    mdi_mtv_p->player_state = MDI_MTV_PLAYER_STATE_STOPPED;
    mdi_mtv_p->recorder_state = MDI_MTV_RECORDER_STATE_STOPPED;
    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_CLOSED;
}


MMI_BOOL mdi_mtv_is_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_mtv_p->player_state == MDI_MTV_PLAYER_STATE_PLAYING)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


MMI_BOOL mdi_mtv_is_opened(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_mtv_p->service_state == MDI_MTV_SERVICE_STATE_CLOSED)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


MDI_RESULT mdi_mtv_open(const U16 app_id,
                        U32 *mtv_handle,
                        mdi_mtv_setting_struct* mtv_setting,
                        mdi_mtv_service_config_struct* mtv_service_config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MM_DCM_SUPPORT__
    mdi_mtv_dcm_load();
#endif

    ret = mdi_mtv_open_internal(
            app_id, mtv_handle, mtv_setting, mtv_service_config);

#ifdef __MM_DCM_SUPPORT__
    if (ret == MDI_RES_MTV_FAILED)
    {
        mdi_mtv_dcm_unload();
    }
#endif    
    return ret;
}


static void mdi_mtv_system_event_hdlr(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_system_event_ind_struct* ind = (media_mtv_system_event_ind_struct*) local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_SYSTEM_EVENT_HDLR, ind->event, ind->parameter);

    /* EB_MSG and ESG_UPDATED is invalide */
    if (mdi_mtv_p->service_state == MDI_MTV_SERVICE_STATE_CLOSED)
    {
        return;
    }

    switch (ind->event)
    {
        case MEDIA_MTV_SYSTEM_CLOSED:
            /* Change state to closed first before callback */
            mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_CLOSED;
            mdi_mtv_p->service_config.system_event_hdlr(MDI_MTV_SYSTEM_CLOSED, MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
        #ifdef __MM_DCM_SUPPORT__    
            mdi_mtv_dcm_unload();   
        #endif 
            break;
        case MEDIA_MTV_SYSTEM_UNSAVED_RECORDING_DISCARDED:
            mdi_mtv_p->service_config.system_event_hdlr(MDI_MTV_SYSTEM_UNSAVED_RECORDING_DISCARDED, MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
            break;
        default:
            break;
    }
}

MDI_RESULT mdi_mtv_rename_channel(U32 mtv_handle, U32 service_id, CHAR* service_name)
{
#if defined(__MTK_TARGET__)      
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_RENAME_CHANNEL, service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_set_param(MOD_MMI, mtv_handle, service_id, MEDIA_MTV_SERVICE_PARAM_NAME, (kal_uint32) service_name);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }
#endif    
    return MDI_RES_MTV_SUCCEED;
}

MDI_RESULT mdi_mtv_pause_engine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_PAUSE_ENGINE, mdi_mtv_p->service_state);

    if (mdi_mtv_p->service_state == MDI_MTV_SERVICE_STATE_CLOSED ||
        mdi_mtv_p->service_state == MDI_MTV_SERVICE_STATE_CLOSING)
    {
        return MDI_RES_MTV_SUCCEED;
    }
#ifdef __MM_DCM_SUPPORT__    
    mdi_mtv_dcm_unload();
#endif

    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_PAUSE, 0);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }
    return MDI_RES_MTV_SUCCEED;
}

MDI_RESULT mdi_mtv_resume_engine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_RESUME_ENGINE, mdi_mtv_p->service_state);

    if (mdi_mtv_p->service_state == MDI_MTV_SERVICE_STATE_CLOSED ||
        mdi_mtv_p->service_state == MDI_MTV_SERVICE_STATE_CLOSING)
    {
        return MDI_RES_MTV_SUCCEED;
    }
#ifdef __MM_DCM_SUPPORT__       
    mdi_mtv_dcm_load();
#endif

    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_RESUME, 0);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }
    return MDI_RES_MTV_SUCCEED;
}


#ifdef __MM_DCM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_dcm_load
 * DESCRIPTION
 *  This function is to load DCM
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_mtv_dcm_load(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DCM_Load(DYNAMIC_CODE_COMPRESS_MDIMTV, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_dcm_unload
 * DESCRIPTION
 *  This function is to unload DCM
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_mtv_dcm_unload(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DCM_Unload(DYNAMIC_CODE_COMPRESS_MDIMTV);
}

#pragma arm section code = "DYNAMIC_CODE_MDIMTV_ROCODE", rodata = "DYNAMIC_CODE_MDIMTV_RODATA"

#endif


static S32 mdi_mtv_player_med_err_to_mdi_err(U32 med_err)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (med_err)
    {
        case MED_RES_OK:
            return MDI_RES_MTV_SUCCEED;
        case MED_RES_UPGRADE_NONE:
            return MDI_RES_MTV_UPGRADE_NONE;
        case MED_RES_UPGRADE_NEED:
            return MDI_RES_MTV_UPGRADE_NEED;
        case MED_RES_UPGRADE_MANDATORY:
            return MDI_RES_MTV_UPGRADE_MANDATORY;
        case MED_RES_DISC_FULL:
            return MDI_RES_MTV_ERR_DISC_FULL;
        case MED_RES_DISK_IO_ERROR:
            return MDI_RES_MTV_ERR_DISC_IO_ERROR;
        case MED_RES_BUSY:
            return MDI_RES_MTV_ERR_DEVICE_BUSY;
        case MED_RES_VIDEO_ERROR:
            return MDI_RES_MTV_ERR_VIDEO_ERROR;
        case MED_RES_AUDIO_ERROR:
            return MDI_RES_MTV_ERR_AUDIO_ERROR;
        case MED_RES_NO_DISC:
            return MDI_RES_MTV_ERR_STORAGE_NOT_READY;

    }

    return MDI_RES_MTV_FAILED;
}

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
static S32 mdi_mtv_mbbms_status_to_mdi_err(U32 evt, S32 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status)
    {
        case MDI_MTV_MBBMS_OK:
            return MDI_RES_MTV_SUCCEED;
            break;
        case MDI_MTV_MBBMS_DEVICE_AUTHENTICATION_FAILED:
            return MDI_RES_MTV_MBBMS_DEVICE_AUTHENTICATION_FAILED;
            break;
        case MDI_MTV_MBBMS_PURCHASE_ITEM_UNKNOWN:
            return MDI_RES_MTV_MBBMS_PURCHASE_ITEM_UNKNOWN;
            break;
        case MDI_MTV_MBBMS_SERVICE_ERROR:
            return MDI_RES_MTV_MBBMS_SERVICE_ERROR;
            break;
        case MDI_MTV_MBBMS_MAL_FORMED_MESSAGE_ERROR:
            return MDI_RES_MTV_MBBMS_MAL_FORMED_MESSAGE_ERROR;
            break;
        case MDI_MTV_MBBMS_NO_SUBSCRIPTION:
            return MDI_RES_MTV_MBBMS_NO_SUBSCRIPTION;
            break;
        case MDI_MTV_MBBMS_OPERATION_NOT_PERMITTED:
            return MDI_RES_MTV_MBBMS_OPERATION_NOT_PERMITTED;
            break;
        case MDI_MTV_MBBMS_REQUESTED_SERVICE_UNAVAILABLE:
            return MDI_RES_MTV_MBBMS_REQUESTED_SERVICE_UNAVAILABLE;
            break;
        case MDI_MTV_MBBMS_REQUESTED_SERVICE_ACCEPTED:
            return MDI_RES_MTV_MBBMS_REQUESTED_SERVICE_ACCEPTED;
            break;
        case MDI_MTV_MBBMS_INVALID_REQUEST:
            return MDI_RES_MTV_MBBMS_INVALID_REQUEST;
            break;
        case MDI_MTV_MBBMS_DELIVERY_OF_WRONG_KEY_INFORMATION:
            return MDI_RES_MTV_MBBMS_DELIVERY_OF_WRONG_KEY_INFORMATION;
            break;
        case MDI_MTV_MBBMS_ALREADY_IN_USE:
            return MDI_RES_MTV_MBBMS_ALREADY_IN_USE;
            break;
        case MDI_MTV_MBBMS_NO_MATCHING_FRAGMENT:
            return MDI_RES_MTV_MBBMS_NO_MATCHING_FRAGMENT;
            break;
        case MDI_MTV_MBBMS_NOW_SUBSCRIBED:
            return MDI_RES_MTV_MBBMS_NOW_SUBSCRIBED;
            break;
        case MDI_MTV_MBBMS_INSUFFICIENT_CHARGE:
            return MDI_RES_MTV_MBBMS_INSUFFICIENT_CHARGE;
            break;

        case MDI_MTV_MBBMS_LOCATION_DETECT_FAIL:
            return MDI_RES_MTV_MBBMS_LOCATION_DETECT_FAIL;
            break;

        /* Internal error */
        case MDI_MTV_MBBMS_SET_CHANNEL_FAIL:
            return MDI_RES_MTV_MBBMS_INVALID_NW_PARAM;
            break;
        case MDI_MTV_MBBMS_NW_TIMEOUT:
            return MDI_RES_MTV_MBBMS_NW_TIMEOUT;
            break;
    }

    switch (evt)
    {
        /*
        case MEDIA_MTV_SERVICE_SG_UPDATE_RET:
            break;
        case MEDIA_MTV_SERVICE_SUBSCRIPTION_UPDATE_RET:
            break;
        case MEDIA_MTV_SERVICE_GBA_RET:
            break;
        */
        case MEDIA_MTV_SERVICE_MSK_RETRIEVE_DONE:
            return MDI_RES_MTV_ERR_MSK_RETRIEVE_FAIL;
            break;
        case MEDIA_MTV_SERVICE_ACCOUNT_INQUIRY_DONE:
            return MDI_RES_MTV_ERR_ACCOUNT_INQUIRY_FAIL;
            break;
        case MEDIA_MTV_SERVICE_SUBSCRIBE_DONE:
            return MDI_RES_MTV_ERR_SUBSCRIBE_FAIL;
            break;
        case MEDIA_MTV_SERVICE_UNSUBSCRIBE_DONE:
            return MDI_RES_MTV_ERR_UNSUBSCRIBE_FAIL;
            break;
        case MEDIA_MTV_SERVICE_AREA_RETRIEVE_RET:
            return MDI_RES_MTV_ERR_AREA_RETRIEVE_FAIL;
            break;
        case MEDIA_MTV_SERVICE_INTERACTIVITY_RETRIEVE_RET:
            return MDI_RES_MTV_ERR_INTERACTIVITY_RETRIEVE_FAIL;
            break;
    }
    return MDI_RES_MTV_FAILED;
}


static void mdi_mtv_account_inquiry_hdlr(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_account_inquiry_ind_struct* ind = (media_mtv_account_inquiry_ind_struct*) local_param;
    mdi_mtv_account_inquiry_struct account;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_ACCOUNT_INQUIRY_HDLR);

    /* TODO */
    //if (ind->seq_no != mdi_mtv_p->scanning_seq_no)
    //    return;

    account.purchase_count = ind->purchase_count;
    for (i = 0; i < ind->purchase_count; i++)
    {
        account.purchase_info[i].fragment_id = ind->purchase_info[i].fragment_id;
        account.purchase_info[i].purchaseitem_id = ind->purchase_info[i].purchaseitem_id;
        account.purchase_info[i].purchaseitem_name = ind->purchase_info[i].purchaseitem_name;
        account.purchase_info[i].purchaseitem_desc = ind->purchase_info[i].purchaseitem_desc;
        account.purchase_info[i].type = ind->purchase_info[i].type;
        account.purchase_info[i].period = ind->purchase_info[i].period;
        account.purchase_info[i].price = ind->purchase_info[i].price;
    }
    /* we need to copy the name because it may change later */
    mdi_mtv_p->service_config.account_inquiry_hdlr(&account, mdi_mtv_p->service_config.user_data);
}

static void mdi_mtv_city_found_hdlr(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_city_found_ind_struct* ind = (media_mtv_city_found_ind_struct*) local_param;
    mdi_mtv_city_info_struct city;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_CITY_FOUND_HDLR);

    /* TODO */
    //if (ind->seq_no != mdi_mtv_p->scanning_seq_no)
    //    return;

    city.city_count = ind->city_count;
    for (i = 0; i < ind->city_count; i++)
    {
        city.city_info[i].city_name = ind->city_info[i].city_name;
    }
    /* we need to copy the name because it may change later */
    mdi_mtv_p->service_config.city_found_hdlr(&city, mdi_mtv_p->service_config.user_data);
}
#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */

static void mdi_mtv_service_found_hdlr(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_service_found_ind_struct* ind = (media_mtv_service_found_ind_struct*) local_param;
    mdi_mtv_service_info_struct  service_info;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_SERVICE_FOUND_HDLR, mdi_mtv_p->scanning_seq_no, ind->seq_no);
    if (ind->seq_no != mdi_mtv_p->scanning_seq_no)
        return;

    for (i = 0; i < ind->service_count; i++)
    {
        media_mtv_service_info_struct* info = &ind->service_info[i];
        MMI_TRACE(
            MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_SERVICE_INFO,
            info->service_id,
            info->service_number,
            info->service_type,
            info->service_flags,
            info->audio_mode,
            info->supported_audio_mode);

        service_info.service_id = info->service_id;
        service_info.service_name = (CHAR *)info->service_name;
        service_info.service_number = info->service_number;
        service_info.service_type = info->service_type;
        service_info.service_flags = info->service_flags;

        /* we need to copy the name because it may change later */
        mdi_mtv_p->service_config.service_found_hdlr(&service_info, mdi_mtv_p->service_config.user_data);
    }
}


static void mdi_mtv_search_progress_hdlr(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_search_progress_ind_struct* ind = (media_mtv_search_progress_ind_struct*) local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_SEARCH_PROGRESS_HDLR, mdi_mtv_p->scanning_seq_no, ind->seq_no, ind->percentage);

    if (ind->seq_no != mdi_mtv_p->scanning_seq_no)
    {
        return;
    }

    mdi_mtv_p->service_config.search_progress_hdlr(ind->percentage, mdi_mtv_p->service_config.user_data);
}


static void mdi_mtv_service_event_hdlr(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_service_event_ind_struct* ind = (media_mtv_service_event_ind_struct*) local_param;
    mdi_mtv_service_info_struct service_info;
    mdi_mtv_purchase_desc_struct purchase = {0};
    mdi_mtv_ca_info_struct ca_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_SERVICE_EVENT_HDLR, mdi_mtv_p->service_seq_no, ind->seq_no, ind->service_id, ind->event, ind->parameter);

    /* EB_MSG and ESG_UPDATED is invalide */
    if (mdi_mtv_p->service_state == MDI_MTV_SERVICE_STATE_CLOSED)
    {
        return;
    }

    /* Event which is always valid */
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    switch (ind->event)
    {
        case MEDIA_MTV_SERVICE_EMERGENCY_MSG:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_EMERGENCY_MSG, MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
            return; /* Not break */
        case MEDIA_MTV_SERVICE_ESG_NEW_AVAILABLE:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_ESG_NEW_AVAILABLE, MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
            return; /* Not break */
        case MEDIA_MTV_SERVICE_ESG_DOWNLOADED:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_ESG_DOWNLOADED, MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
            return; /* Not break */
        case MEDIA_MTV_SERVICE_ESG_UPDATED:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_ESG_UPDATED, MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
            return; /* Not break */
         case MEDIA_MTV_SERVICE_UPGRADE_RET:
            if (ind->parameter == MED_RES_UPGRADE_NONE ||
                ind->parameter == MED_RES_UPGRADE_NEED ||
                ind->parameter == MED_RES_UPGRADE_MANDATORY)
            {
                mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_UPGRADE_RET, mdi_mtv_player_med_err_to_mdi_err(ind->parameter), mdi_mtv_p->service_config.user_data);
            }
            else
            {
                mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_UPGRADE_RET, mdi_mtv_mbbms_status_to_mdi_err(ind->event, ind->parameter), mdi_mtv_p->service_config.user_data);
            }
            return; /* Not break */
        case MEDIA_MTV_SERVICE_INTERACTIVITY_RETRIEVE_RET:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_INTERACTIVITY_RETRIEVE_RET, mdi_mtv_mbbms_status_to_mdi_err(ind->event, ind->parameter), mdi_mtv_p->service_config.user_data);
            return; /* Not break */
        case MEDIA_MTV_SERVICE_IMD_READY:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_IMD_READY, mdi_mtv_mbbms_status_to_mdi_err(ind->event, ind->parameter), mdi_mtv_p->service_config.user_data);
            return; /* Not break */ 
        case MEDIA_MTV_SERVICE_AREA_RETRIEVE_RET:
            mdi_mtv_p->block_query = MMI_FALSE;
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_AREA_RETRIEVE_RET, mdi_mtv_mbbms_status_to_mdi_err(ind->event, ind->parameter), mdi_mtv_p->service_config.user_data);
            return; /* Not break */
        case MEDIA_MTV_SERVICE_SG_UPDATE_RET:
            if (ind->parameter != MDI_MTV_MBBMS_OK)
            {
                mdi_mtv_p->block_query = MMI_FALSE;
            }
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_SG_UPDATE_RET, mdi_mtv_mbbms_status_to_mdi_err(ind->event, ind->parameter), mdi_mtv_p->service_config.user_data);

            return; /* Not break */
        case MEDIA_MTV_SERVICE_SUBSCRIPTION_UPDATE_RET:
            if (mdi_mtv_p->service_state == MDI_MTV_SERVICE_STATE_SUBSCRIPTION_UPDATE &&
                ind->seq_no != mdi_mtv_p->service_seq_no)
            {
                return; /* Not Break */
            }

            mdi_mtv_p->block_query = MMI_FALSE;
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_SUBSCRIPTION_RET, mdi_mtv_mbbms_status_to_mdi_err(ind->event, ind->parameter), mdi_mtv_p->service_config.user_data);
            return; /* Not break */
        case MEDIA_MTV_SERVICE_GBA_RET:
            if (ind->parameter != MDI_MTV_MBBMS_OK)
            {
                mdi_mtv_p->block_query = MMI_FALSE;
            }
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_GBA_RET, mdi_mtv_mbbms_status_to_mdi_err(ind->event, ind->parameter), mdi_mtv_p->service_config.user_data);
            return; /* Not break */
        case MEDIA_MTV_SERVICE_ACCOUNT_INQUIRY_DONE:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_ACCOUNT_INQUIRY_DONE, mdi_mtv_mbbms_status_to_mdi_err(ind->event, ind->parameter), mdi_mtv_p->service_config.user_data);
            return; /* Not break */
        case MEDIA_MTV_SERVICE_SUBSCRIBE_DONE:
            purchase.ret = mdi_mtv_mbbms_status_to_mdi_err(ind->event, ind->parameter);
            mmi_ucs2ncpy((CHAR *)purchase.desc, (CHAR *)ind->append_data, MDI_MTV_MBBMS_DESC_LENGTH - 1);

            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_SUBSCRIBE_DONE, (kal_int32) &purchase, mdi_mtv_p->service_config.user_data);

            return; /* Not break */
        case MEDIA_MTV_SERVICE_UNSUBSCRIBE_DONE:
            purchase.ret = mdi_mtv_mbbms_status_to_mdi_err(ind->event, ind->parameter);
            mmi_ucs2ncpy((CHAR *)purchase.desc, (CHAR *)ind->append_data, MDI_MTV_MBBMS_DESC_LENGTH - 1);

            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_UNSUBSCRIBE_DONE, (kal_int32) &purchase, mdi_mtv_p->service_config.user_data);
            return; /* Not break */
        case MEDIA_MTV_SERVICE_MSK_RETRIEVE_DONE:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_MSK_RETRIEVE_DONE, mdi_mtv_mbbms_status_to_mdi_err(ind->event, ind->parameter), mdi_mtv_p->service_config.user_data);
            return; /* Not break */

        case MEDIA_MTV_SERVICE_SET_EMM_DONE:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_SET_EMM_DONE, ind->parameter, mdi_mtv_p->service_config.user_data);
            return;

        case MEDIA_MTV_SERVICE_GET_CA_DONE:
            kal_mem_cpy(&ca_info, (void*)ind->append_data, sizeof(mdi_mtv_ca_info_struct));
            kal_prompt_trace(MOD_MMI_MEDIA_APP,"[lry]mdi get ca info 2. [0x%x|0x%x],", 
                             ca_info.randvalue[0], ca_info.randvalue[1]);
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_GET_CA_DONE, (kal_int32)&ca_info, mdi_mtv_p->service_config.user_data);
            return;
    }
#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */

    /* ignore not-matched service id ind */
    if (ind->service_id != mdi_mtv_p->service_id)
    {
        return;
    }

    /* Event (Don't need to check sequence number) */
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    switch (ind->event)
    {
        case MEDIA_MTV_SERVICE_PROGRAM_INFO:
        {
            media_mtv_program_info_struct *med_prog_info = (media_mtv_program_info_struct*) ind->parameter;
            mdi_mtv_program_info_struct prog_info;
            S32 i;

            ASSERT(med_prog_info->record_count <= 2);

            prog_info.record_num = med_prog_info->record_count;
            for (i = 0; i < prog_info.record_num; i++)
            {
                prog_info.records[i].date = med_prog_info->records[i].date;
                prog_info.records[i].time = med_prog_info->records[i].time;
                prog_info.records[i].duration = med_prog_info->records[i].duration;
                prog_info.records[i].title = med_prog_info->records[i].title;
            }
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_PROGRAM_INFO,(S32)&prog_info, mdi_mtv_p->service_config.user_data);

            return; /* Not break */
        }
    }
#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */


    /* ignore sequence id which does not match */
    if (ind->seq_no != mdi_mtv_p->service_seq_no)
    {
        return;
    }

    switch (ind->event)
    {
        case MEDIA_MTV_SERVICE_READY:
        case MEDIA_MTV_SERVICE_UPDATED:
        {
            media_mtv_service_info_struct* info = (media_mtv_service_info_struct*) ind->parameter;
            MMI_TRACE(
                MMI_MEDIA_TRC_G4_MDI,
                MDI_TRC_MTV_SERVICE_INFO,
                info->service_id,
                info->service_number,
                info->service_type,
                info->service_flags,
                info->audio_mode,
                info->supported_audio_mode);

            service_info.service_id = info->service_id;
            service_info.service_name = (CHAR *)info->service_name;
            service_info.service_number = info->service_number;
            service_info.service_type = info->service_type;
            service_info.service_flags = info->service_flags;
            service_info.audio_mode = info->audio_mode;
            service_info.supported_audio_mode = info->supported_audio_mode;

            /* Update service type to mdi structure */

            if (mdi_mtv_p->service_type != info->service_type)
            {
                mdi_mtv_p->service_type = info->service_type;

                if (mdi_mtv_p->player_state == MDI_MTV_PLAYER_STATE_PLAYING)
                {
                    mdi_mtv_player_reset_video_setting();
                    mdi_mtv_p->player_state = MDI_MTV_PLAYER_STATE_STOPPED;
                }
            }

            if (ind->event == MEDIA_MTV_SERVICE_READY)
            {
                mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_READY, (S32)&service_info, mdi_mtv_p->service_config.user_data);
            }
            else
            {
                mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_UPDATED, (S32)&service_info, mdi_mtv_p->service_config.user_data);
            }
            break;
        }
        case MEDIA_MTV_SERVICE_ABORTED:
            if (mdi_mtv_p->player_state == MDI_MTV_PLAYER_STATE_PLAYING)
            {
                mdi_mtv_player_reset_video_setting();
                mdi_mtv_p->player_state = MDI_MTV_PLAYER_STATE_STOPPED;
            }
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_ABORTED,MDI_RES_MTV_FAILED, mdi_mtv_p->service_config.user_data);
            break;
        case MEDIA_MTV_SERVICE_STARTED:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_STARTED,MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
            break;
        case MEDIA_MTV_SERVICE_ADDED:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_ADDED,MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
            break;
        case MEDIA_MTV_SERVICE_REMOVED:
            if (mdi_mtv_p->player_state == MDI_MTV_PLAYER_STATE_PLAYING)
            {
                mdi_mtv_player_reset_video_setting();
                mdi_mtv_p->player_state = MDI_MTV_PLAYER_STATE_STOPPED;
            }
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_REMOVED,MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
            break;
        case MEDIA_MTV_SERVICE_BAD_RECEPTION:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_BAD_RECEPTION,MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
            break;
        case MEDIA_MTV_SERVICE_GOOD_RECEPTION:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_GOOD_RECEPTION,MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
            break;
    #if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
        case MEDIA_MTV_SERVICE_ACCESS_GRANTED:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_ACCESS_GRANTED,MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
            break;
        case MEDIA_MTV_SERVICE_ACCESS_DENIED:
            mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_ACCESS_DENIED,MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
            break;
    #endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */
    }
}


#ifdef __MTV_REC_SUPPORT__
static void mdi_mtv_complete_recovering_hdlr(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_complete_recovering_ind_struct* ind = (media_mtv_complete_recovering_ind_struct*) local_param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_COMPLETE_RECOVERING_HDLR, mdi_mtv_p->service_seq_no, ind->seq_no, ind->error);

    if (ind->seq_no != mdi_mtv_p->service_seq_no)
    {
        return;
    }

    switch (ind->error)
    {
        case MED_RES_OK:
            mdi_mtv_p->service_config.complete_recovering_hdlr(MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
            break;
        case MED_RES_DISC_FULL:
            mdi_mtv_p->service_config.complete_recovering_hdlr(mdi_mtv_player_med_err_to_mdi_err(ind->error), mdi_mtv_p->service_config.user_data);
            break;
        default:
            mdi_mtv_p->service_config.complete_recovering_hdlr(MDI_RES_MTV_FAILED, mdi_mtv_p->service_config.user_data);
            break;
    }
}

static void mdi_mtv_recorder_event_hdlr(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_recorder_event_ind_struct* ind = (media_mtv_recorder_event_ind_struct*) local_param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_RECORDER_EVENT_HDLR, mdi_mtv_p->recorder_seq_no, ind->seq_no, ind->service_id, ind->event, ind->parameter);

    if (ind->seq_no != mdi_mtv_p->recorder_seq_no)
        return;

    switch (ind->event)
    {
    case MEDIA_MTV_RECORDER_STARTED:
        break;
    case MEDIA_MTV_RECORDER_STOPPED:
        break;
    case MEDIA_MTV_RECORDER_SAVING:
        mdi_mtv_p->recorder_state = MDI_MTV_RECORDER_STATE_SAVING;
        break;
    case MEDIA_MTV_RECORDER_RECORDING_DISCARDED:
        mdi_mtv_p->service_config.recorder_event_hdlr(MDI_MTV_RECORDER_RECORDING_DISCARDED, MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
        mdi_mtv_p->recorder_state = MDI_MTV_RECORDER_STATE_STOPPED;
        break;
    case MEDIA_MTV_RECORDER_ERROR:
        mdi_mtv_p->service_config.recorder_event_hdlr(MDI_MTV_RECORDER_ERROR,mdi_mtv_player_med_err_to_mdi_err(ind->parameter), mdi_mtv_p->service_config.user_data);
        mdi_mtv_p->recorder_state = MDI_MTV_RECORDER_STATE_STOPPED;
        break;
    case MEDIA_MTV_RECORDER_SAVING_FAILED:
        if (ind->parameter == MED_RES_FAIL)
        {
            mdi_mtv_p->service_config.recorder_event_hdlr(
                MDI_MTV_RECORDER_SAVING_FAILED,
                MDI_RES_MTV_ERR_SAVE_FAILED, 
                mdi_mtv_p->service_config.user_data);
        }
        else
        {
            mdi_mtv_p->service_config.recorder_event_hdlr(
                MDI_MTV_RECORDER_SAVING_FAILED,
                mdi_mtv_player_med_err_to_mdi_err(ind->parameter), 
                mdi_mtv_p->service_config.user_data);
        }
        mdi_mtv_p->recorder_state = MDI_MTV_RECORDER_STATE_STOPPED;
        break;
    case MEDIA_MTV_RECORDER_SAVING_SUCCEEDED:
        mdi_mtv_p->service_config.recorder_event_hdlr(MDI_MTV_RECORDER_SAVING_SUCCEEDED, MDI_RES_MTV_COMPLETE_SAVING, mdi_mtv_p->service_config.user_data);
        mdi_mtv_p->recorder_state = MDI_MTV_RECORDER_STATE_STOPPED;
        break;
    }
}
#endif /* __MTV_REC_SUPPORT__ */

static void mdi_mtv_player_event_hdlr(void* local_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_player_event_ind_struct* ind = (media_mtv_player_event_ind_struct*) local_param;
    U32 event_id = 0;
    S32 param_id = ind->parameter;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_PLAYER_EVENT_HDLR, mdi_mtv_p->player_seq_no, ind->seq_no, ind->service_id, ind->event, ind->parameter);


    if (ind->event == MEDIA_MTV_PLAYER_BEGINNING_OF_CONTENT ||
        ind->event == MEDIA_MTV_PLAYER_END_OF_CONTENT ||
        ind->event == MEDIA_MTV_PLAYER_RATE_CHANGE)
    {
        /* Don't need to check sequence number. Always valid. */
    }
    else if (ind->event == MEDIA_MTV_PLAYER_DYNAMIC_LABEL)
    {
        /* Don't need to check sequence number, but need to check service id */
        if (mdi_mtv_p->service_id != ind->service_id)
        {
            return;
        }
    }
    else if (ind->seq_no != mdi_mtv_p->player_seq_no)
    {
        return;
    }

    /* The indication event is out of date */
    if (ind->event == MEDIA_MTV_PLAYER_END_OF_CONTENT &&
        mdi_mtv_p->player_state != MDI_MTV_PLAYER_STATE_PLAYING)
    {
        return;
    }

    switch (ind->event)
    {
        case MEDIA_MTV_PLAYER_STARTED:
            event_id = MDI_MTV_PLAYER_STARTED;
            break;
        case MEDIA_MTV_PLAYER_STOPPED:
            event_id = MDI_MTV_PLAYER_STOPPED;
            param_id = mdi_mtv_player_med_err_to_mdi_err(ind->parameter);
            break;
        case MEDIA_MTV_PLAYER_TIMESHIFT_PAUSED:
            event_id = MDI_MTV_PLAYER_TIMESHIFT_PAUSED;
            break;
        case MEDIA_MTV_PLAYER_TIMESHIFT_DELAYED:
            event_id = MDI_MTV_PLAYER_TIMESHIFT_DELAYED;
            break;
        case MEDIA_MTV_PLAYER_TIMESHIFT_LIVE:
            event_id = MDI_MTV_PLAYER_TIMESHIFT_LIVE;
            break;
        case MEDIA_MTV_PLAYER_TIMESHIFT_ERROR:
            event_id = MDI_MTV_PLAYER_TIMESHIFT_ERROR;
            break;
        case MEDIA_MTV_PLAYER_BEGINNING_OF_CONTENT:
            event_id = MDI_MTV_PLAYER_BEGINNING_OF_CONTENT;
            break;
        case MEDIA_MTV_PLAYER_END_OF_CONTENT:
            event_id = MDI_MTV_PLAYER_END_OF_CONTENT;
            break;
        case MEDIA_MTV_PLAYER_SNAPSHOT_TAKEN:
            event_id = MDI_MTV_PLAYER_SNAPSHOT_TAKEN;
            break;
        case MEDIA_MTV_PLAYER_DYNAMIC_LABEL:
            event_id = MDI_MTV_PLAYER_DYNAMIC_LABEL;
            break;
        case MEDIA_MTV_PLAYER_RATE_CHANGE:
            event_id = MDI_MTV_PLAYER_RATE_CHANGE;
            break;
        case MEDIA_MTV_PLAYER_ERROR:
        {
            mdi_mtv_player_reset_video_setting();
            mdi_mtv_p->player_state = MDI_MTV_PLAYER_STATE_STOPPED;

            event_id = MDI_MTV_PLAYER_ERROR;
            param_id = mdi_mtv_player_med_err_to_mdi_err(ind->parameter);
            break;
        }
    }

    mdi_mtv_p->service_config.player_event_hdlr(event_id,param_id, mdi_mtv_p->service_config.user_data);
}


static U16 mdi_mtv_get_brightness_value(void)
{
    U16 value = 0;
    switch (mdi_mtv_p->brightness)
    {
        case MDI_MTV_BRIGHTNESS_N5:
            value = 8; /* -120 */
            break;

        case MDI_MTV_BRIGHTNESS_N4:
            value = 38;    /* -90 */
            break;

        case MDI_MTV_BRIGHTNESS_N3:
            value = 68;    /* -60 */
            break;

        case MDI_MTV_BRIGHTNESS_N2:
            value = 98;    /* -30 */
            break;

        case MDI_MTV_BRIGHTNESS_N1:
            value = 118;   /* -10 */
            break;

        case MDI_MTV_BRIGHTNESS_0:
            value = 128;   /* 0 */
            break;

        case MDI_MTV_BRIGHTNESS_P1:
            value = 138;   /* +10 */
            break;

        case MDI_MTV_BRIGHTNESS_P2:
            value = 158;   /* +30 */
            break;

        case MDI_MTV_BRIGHTNESS_P3:
            value = 188;   /* +60 */
            break;

        case MDI_MTV_BRIGHTNESS_P4:
            value = 218;   /* +90 */
            break;

        case MDI_MTV_BRIGHTNESS_P5:
            value = 248;   /* +120 */
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    return value;

}


static U16 mdi_mtv_get_contrast_value(void)
{
    U16 value = 0;
    switch (mdi_mtv_p->contrast)
    {
        case MDI_MTV_CONTRAST_N5:
            value = 8; /* -120 */
            break;

        case MDI_MTV_CONTRAST_N4:
            value = 38;    /* -90 */
            break;

        case MDI_MTV_CONTRAST_N3:
            value = 68;    /* -60 */
            break;

        case MDI_MTV_CONTRAST_N2:
            value = 98;    /* -30 */
            break;

        case MDI_MTV_CONTRAST_N1:
            value = 118;   /* -10 */
            break;

        case MDI_MTV_CONTRAST_0:
            value = 128;   /* 0 */
            break;

        case MDI_MTV_CONTRAST_P1:
            value = 138;   /* +10 */
            break;

        case MDI_MTV_CONTRAST_P2:
            value = 158;   /* +30 */
            break;

        case MDI_MTV_CONTRAST_P3:
            value = 188;   /* +60 */
            break;

        case MDI_MTV_CONTRAST_P4:
            value = 218;   /* +90 */
            break;

        case MDI_MTV_CONTRAST_P5:
            value = 248;   /* +120 */
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    return value;
}


static U16 mdi_mtv_get_saturation_value(void)
{
    U16 value = 0;
    switch (mdi_mtv_p->saturation)
    {
        case MDI_MTV_SATURATION_N5:
            value = 8; /* -120 */
            break;

        case MDI_MTV_SATURATION_N4:
            value = 38;    /* -90 */
            break;

        case MDI_MTV_SATURATION_N3:
            value = 68;    /* -60 */
            break;

        case MDI_MTV_SATURATION_N2:
            value = 98;    /* -30 */
            break;

        case MDI_MTV_SATURATION_N1:
            value = 118;   /* -10 */
            break;

        case MDI_MTV_SATURATION_0:
            value = 128;   /* 0 */
            break;

        case MDI_MTV_SATURATION_P1:
            value = 138;   /* +10 */
            break;

        case MDI_MTV_SATURATION_P2:
            value = 158;   /* +30 */
            break;

        case MDI_MTV_SATURATION_P3:
            value = 188;   /* +60 */
            break;

        case MDI_MTV_SATURATION_P4:
            value = 218;   /* +90 */
            break;

        case MDI_MTV_SATURATION_P5:
            value = 248;   /* +120 */
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    return value;
}



void mdi_mtv_set_brightness(U16 brightness)
{
    kal_int32 ret;
    mdi_mtv_p->brightness = brightness;

    if (mdi_mtv_p->player_state == MDI_MTV_PLAYER_STATE_PLAYING)
    {
        ret = media_mtv_set_param(
                MOD_MMI,
                mdi_mtv_p->context,
                mdi_mtv_p->service_id,
                MEDIA_MTV_SERVICE_PARAM_BRIGHTNESS,
                (kal_uint32) mdi_mtv_get_brightness_value());
        if (ret != MED_RES_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        }
    }
}


void mdi_mtv_set_contrast(U16 contrast)
{
    kal_int32 ret;
    mdi_mtv_p->contrast = contrast;
    if (mdi_mtv_p->player_state == MDI_MTV_PLAYER_STATE_PLAYING)
    {
        ret = media_mtv_set_param(
                MOD_MMI,
                mdi_mtv_p->context,
                mdi_mtv_p->service_id,
                MEDIA_MTV_SERVICE_PARAM_CONTRAST,
                (kal_uint32) mdi_mtv_get_contrast_value());
        if (ret != MED_RES_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        }
    }
}

void mdi_mtv_set_saturation(U16 saturation)
{
    kal_int32 ret;
    mdi_mtv_p->saturation = saturation;

    if (mdi_mtv_p->player_state == MDI_MTV_PLAYER_STATE_PLAYING)
    {
        ret = media_mtv_set_param(
                MOD_MMI,
                mdi_mtv_p->context,
                mdi_mtv_p->service_id,
                MEDIA_MTV_SERVICE_PARAM_SATURATION,
                (kal_uint32) mdi_mtv_get_saturation_value());
        if (ret != MED_RES_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_dummy_loading_cyclic
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MTK_TARGET__
static void mdi_mtv_scan_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 service_num = 6;
    S32 idx;
    mdi_mtv_service_info_struct service_info;
    WCHAR name[20];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mdi_mtv_p->scan_progress += 20;

    if (mdi_mtv_p->scan_progress < 100)
    {
        StartTimer(MTV_PLAYER_UT_TIMER, 500, mdi_mtv_scan_cyclic);
    }
    else
    {
        for (idx = 0; idx < service_num; idx ++)
        {
            /* Finish scanning */
            service_info.service_id = idx;
            kal_wsprintf(name, "service %d", idx);
            service_info.service_name = name;
            service_info.service_number = idx + 1;
            service_info.service_type = MEDIA_MTV_SERVICE_ANALOG_TV;
            service_info.audio_mode = MDI_ATV_MONO;
            service_info.supported_audio_mode = (MDI_ATV_MONO | MDI_ATV_MTS_STEREO);
            service_info.service_flags = 0;
            mdi_mtv_p->service_config.service_found_hdlr(&service_info, mdi_mtv_p->service_config.user_data);
        }
    }

    mdi_mtv_p->service_config.search_progress_hdlr(mdi_mtv_p->scan_progress, mdi_mtv_p->service_config.user_data);

}

static void mdi_mtv_start_service_wait_ready(void)
{
    mdi_mtv_service_info_struct service_info;

    service_info.service_type = MEDIA_MTV_SERVICE_ANALOG_TV;
    service_info.audio_mode = MDI_ATV_MONO;
    service_info.supported_audio_mode = (MDI_ATV_MONO | MDI_ATV_MTS_STEREO);

    mdi_mtv_p->service_config.service_event_hdlr(MDI_MTV_SERVICE_READY, (S32)&service_info, mdi_mtv_p->service_config.user_data);
}

static void mdi_mtv_send_close_ind(void)
{
    mdi_mtv_p->service_config.system_event_hdlr(
        MDI_MTV_SYSTEM_CLOSED, MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
}

static void mdi_mtv_send_record_saved_ind(void)
{
    mdi_mtv_p->service_config.recorder_event_hdlr(
        MDI_MTV_RECORDER_SAVING_SUCCEEDED, MDI_RES_MTV_COMPLETE_SAVING, mdi_mtv_p->service_config.user_data);
}

static void mdi_mtv_send_record_deleted_ind(void)
{
    mdi_mtv_p->service_config.recorder_event_hdlr(
        MDI_MTV_RECORDER_RECORDING_DISCARDED, MDI_RES_MTV_SUCCEED, mdi_mtv_p->service_config.user_data);
}


#endif /* __MTK_TARGET__ */
MDI_RESULT mdi_mtv_open_internal(const U16 app_id,
                        U32 *mtv_handle,
                        mdi_mtv_setting_struct* mtv_setting,
                        mdi_mtv_service_config_struct* mtv_service_config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool unsaved_recording_found;
    S32 ret;
    media_config_video_struct video;
    media_config_audio_struct audio;
    media_mtv_config_record_struct record;
    media_mtv_mode_enum mode;
    media_mtv_cas_sim_struct param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(mdi_mtv_p->service_state == MDI_MTV_SERVICE_STATE_CLOSED);

    mdi_mtv_p->service_seq_no = 0;
    mdi_mtv_p->player_seq_no = 0;
    mdi_mtv_p->recorder_seq_no = 0;
    mdi_mtv_p->scanning_seq_no = 0;
    mdi_mtv_p->block_query = MMI_FALSE;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_OPEN);
    mdi_mtv_p->service_config.search_progress_hdlr = mtv_service_config->search_progress_hdlr;
    mdi_mtv_p->service_config.service_found_hdlr = mtv_service_config->service_found_hdlr;
    mdi_mtv_p->service_config.system_event_hdlr = mtv_service_config->system_event_hdlr;
    mdi_mtv_p->service_config.service_event_hdlr = mtv_service_config->service_event_hdlr;
    mdi_mtv_p->service_config.player_event_hdlr = mtv_service_config->player_event_hdlr;
#ifdef __MTV_REC_SUPPORT__
    mdi_mtv_p->service_config.complete_recovering_hdlr = mtv_service_config->complete_recovering_hdlr;
    mdi_mtv_p->service_config.recorder_event_hdlr = mtv_service_config->recorder_event_hdlr;
#endif
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    mdi_mtv_p->service_config.account_inquiry_hdlr = mtv_service_config->account_inquiry_hdlr;
    mdi_mtv_p->service_config.city_found_hdlr = mtv_service_config->city_found_hdlr;
#endif
    mdi_mtv_p->service_config.user_data = mtv_service_config->user_data;

#if defined(__MTK_TARGET__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)

    SetProtocolEventHandler(mdi_mtv_service_found_hdlr, MSG_ID_MEDIA_MTV_SERVICE_FOUND_IND);
    SetProtocolEventHandler(mdi_mtv_search_progress_hdlr, MSG_ID_MEDIA_MTV_SEARCH_PROGRESS_IND);
    SetProtocolEventHandler(mdi_mtv_system_event_hdlr, MSG_ID_MEDIA_MTV_SYSTEM_EVENT_IND);
    SetProtocolEventHandler(mdi_mtv_service_event_hdlr, MSG_ID_MEDIA_MTV_SERVICE_EVENT_IND);
    SetProtocolEventHandler(mdi_mtv_player_event_hdlr, MSG_ID_MEDIA_MTV_PLAYER_EVENT_IND);

#ifdef __MTV_REC_SUPPORT__
    SetProtocolEventHandler(mdi_mtv_complete_recovering_hdlr, MSG_ID_MEDIA_MTV_COMPLETE_RECOVERING_IND);
    SetProtocolEventHandler(mdi_mtv_recorder_event_hdlr, MSG_ID_MEDIA_MTV_RECORDER_EVENT_IND);
#endif
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    SetProtocolEventHandler(mdi_mtv_account_inquiry_hdlr, MSG_ID_MEDIA_MTV_ACCOUNT_INQUIRY_IND);
#endif

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    mode = MEDIA_MTV_OPEN_MODE_CMMB;
#elif defined(__MMI_MOBILE_TV_TDMB_SUPPORT__)
    mode = MEDIA_MTV_OPEN_MODE_TDMB;
#elif defined(__MMI_ATV_SUPPORT__)
    mode = MEDIA_MTV_OPEN_MODE_ATV;
#endif

    if (mtv_setting->sim == NULL)
    {
        ret = media_mtv_open(MOD_MMI, &mdi_mtv_p->context, mode, app_id, NULL);
    }
    else
    {
        param.is_usim = mtv_setting->sim->is_usim;
        param.same_imsi = mtv_setting->sim->same_imsi;
        param.sim_id = mtv_setting->sim->sim_id;
        kal_mem_cpy(param.imsi, mtv_setting->sim->imsi, 16);
        kal_mem_cpy(param.bdscell_id, mtv_setting->sim->bdscell_id, 17);

        ret = media_mtv_open(MOD_MMI, &mdi_mtv_p->context, mode, app_id, &param);
    }

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }
    else
    {
        mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_OPENED;
    }

    *mtv_handle = mdi_mtv_p->context;
    mdi_mtv_p->app_id = app_id;

    /* video setting */
    mdi_mtv_p->brightness = mtv_setting->brightness;
    mdi_mtv_p->contrast = mtv_setting->contrast;
    mdi_mtv_p->saturation = mtv_setting->saturation;
    mdi_mtv_p->record_size = mtv_setting->record_size;
    mdi_mtv_p->hw_rotator_rotate = MDI_MTV_LCD_ROTATE_0;

    /* audio setting */
    mdi_mtv_p->audio_path = audio.audio_path = MDI_DEVICE_SPEAKER2;
    mdi_mtv_p->audio_mode = audio.audio_mode = MDI_ATV_DEFAULT;
    audio.play_audio = KAL_TRUE;

    /* recorder setting */
    mdi_mtv_p->enable_timeshift = record.enable_timeshift = mtv_setting->is_timeshift_enabled;
    mdi_mtv_p->max_timeshift_delay = record.max_timeshift_delay = 0; /* NO USE */
    mdi_mtv_p->max_timeshift_buffer_kb = record.max_timeshift_buffer_kb = 16 * 1024;
    mdi_mtv_p->record_dir = mtv_setting->record_dir;

    record.record_dir = (kal_wchar*)mtv_setting->record_dir;
    ret = media_mtv_config(MOD_MMI, *mtv_handle, &video, &audio, &record);

    ASSERT(ret == MED_RES_OK);

    if (ret!=MED_RES_OK)
    {
        return MDI_RES_MTV_FAILED;
    }

#ifdef __MTV_REC_SUPPORT__

    ret = media_mtv_find_unsaved_recording(MOD_MMI, *mtv_handle, &unsaved_recording_found);
    ASSERT(ret == MED_RES_OK);

    if (ret!=MED_RES_OK)
    {
        return MDI_RES_MTV_FIND_UNSAVED_RECORDING_FAIL;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, unsaved_recording_found);
    if (unsaved_recording_found == KAL_TRUE)
        return MDI_RES_MTV_UNSAVE_RECORDING_IND;
    else
        media_mtv_discard_unsaved_recording(MOD_MMI, *mtv_handle);
#endif /* __MTV_REC_SUPPORT__ */
    return MDI_RES_MTV_SUCCEED;
#else /* __MTK_TARGET__ || (__MMI_MOBILE_TV_CMMB_SUPPORT__) */
    return MDI_RES_MTV_SUCCEED;
#endif  /* __MTK_TARGET__ */
}


MDI_RESULT mdi_mtv_close(U32 mtv_handle)
{
#if defined(__MTK_TARGET__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_CLOSE);
    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_close(MOD_MMI, mtv_handle);

    ASSERT(ret == MED_RES_OK);

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_CLOSING;

    return MDI_RES_MTV_SUCCEED;
#else /* __MTK_TARGET__ || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) */
    StartTimer(MTV_PLAYER_UT_TIMER, 200, mdi_mtv_send_close_ind);
    return MDI_RES_MTV_SUCCEED;
#endif  /* __MTK_TARGET__ || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) */
}

#ifdef __MTV_REC_SUPPORT__
void mdi_mtv_set_record_size(U8 size)
{
    mdi_mtv_p->record_size = size;
}

static void mdi_mtv_get_image_size(U16 *image_width, U16 *image_height, mpl_recorder_quality_enum_t *encode_quality)
{
    switch (mdi_mtv_p->record_size)
    {
        case MDI_MTV_RECORDER_SIZE_QCIF:
            *image_width = 176;
            *image_height = 144;
            *encode_quality = MPL_RECORDER_QUALITY_HIGH;
            break;
        case MDI_MTV_RECORDER_SIZE_QVGA:
            *image_width = 320;
            *image_height = 240;
            *encode_quality = MPL_RECORDER_QUALITY_HIGH;
            break;
        case MDI_MTV_RECORDER_SIZE_HVGA:
            *image_width = 480;
            *image_height = 320;
            *encode_quality = MPL_RECORDER_QUALITY_HIGH;
            break;
        default:
            *image_width = 176;
            *image_height = 144;
            *encode_quality = MPL_RECORDER_QUALITY_HIGH;
            break;
    }
}


MDI_RESULT mdi_mtv_recover_recording(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_mtv_p->service_seq_no++;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_RECOVER_RECORDING, mdi_mtv_p->service_seq_no);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_recover_recording(MOD_MMI, mtv_handle,mdi_mtv_p->service_seq_no);
    ASSERT(ret == MED_RES_OK);

    if (ret!=MED_RES_OK)
    {
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_discard_unsaved_recording(U32 mtv_handle)
{
#if defined(__MTK_TARGET__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_DISCARD_UNSAVED_RECORDING);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_discard_unsaved_recording(MOD_MMI, mtv_handle);
    ASSERT(ret == MED_RES_OK);

    if (ret!=MED_RES_OK)
    {
        return MDI_RES_MTV_FAILED;
    }
#endif /* __MTK_TARGET__ || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) */
    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_abort_recovering(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_ABORT_RECOVERING);

    ret = media_mtv_abort_recovering(MOD_MMI,mtv_handle);
    mdi_mtv_p->service_seq_no++;

    return ret;
}
#endif /* __MTV_REC_SUPPORT__ */

MDI_RESULT mdi_mtv_scan_services(U32 mtv_handle, mdi_mtv_service_source_enum source, U32 band, void *param)
{
#if defined(__MTK_TARGET__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 from = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_mtv_p->scanning_seq_no++;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_SCAN_SERVICE, mdi_mtv_p->scanning_seq_no, source, band, param);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    switch (source)
    {
        case MDI_MTV_SOURCE_LIVE_SIGNAL:
            from = MEDIA_MTV_SERVICES_FROM_LIVE_SIGNAL;
            break;
        case MDI_MTV_SOURCE_LOCAL_DATABASE:
            from = MEDIA_MTV_SERVICES_FROM_LOCAL_DATABASE;
            break;
            break;
        default:
            ASSERT(0);
            break;
    }
    ret = media_mtv_search_services(MOD_MMI, mtv_handle, from, band, param, mdi_mtv_p->scanning_seq_no);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_SCANNING;

    return ret;
#else /* __MTK_TARGET__  || (__MMI_MOBILE_TV_CMMB_SUPPORT__) */

    mdi_mtv_p->scan_progress = 0;
    StartTimer(MTV_PLAYER_UT_TIMER, 500, mdi_mtv_scan_cyclic);
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* __MTK_TARGET__  || (__MMI_MOBILE_TV_CMMB_SUPPORT__) */
}


MDI_RESULT mdi_mtv_abort_scan_services(U32 mtv_handle)
{
#if defined(__MTK_TARGET__)  || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_mtv_p->scanning_seq_no++;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_ABORT_SCAN_SERVICE, mdi_mtv_p->scanning_seq_no);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_abort_searching(MOD_MMI, mtv_handle);
    ASSERT(ret == MED_RES_OK);

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_OPENED;


    if (ret!=MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;

#else /* __MTK_TARGET__  || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) */
    StopTimer(MTV_PLAYER_UT_TIMER);
    return MDI_RES_MTV_SUCCEED;

#endif /* __MTK_TARGET__  || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) */
}


MDI_RESULT mdi_mtv_start_service(
                U32 mtv_handle,
                U32 service_id,
                mdi_mtv_service_type_enum service_type,
                MMI_BOOL auto_play,
                mdi_mtv_player_setting_struct *setting_p)
{
#if defined(__MTK_TARGET__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    /* Sync seq no: use the larger one */
    if (mdi_mtv_p->service_seq_no > mdi_mtv_p->player_seq_no)
    {
        mdi_mtv_p->service_seq_no ++;
        mdi_mtv_p->player_seq_no = mdi_mtv_p->service_seq_no;
    }
    else
    {
        mdi_mtv_p->player_seq_no ++;
        mdi_mtv_p->service_seq_no = mdi_mtv_p->player_seq_no;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_START_SERVICE, mdi_mtv_p->service_seq_no, service_id, service_type);

    mdi_mtv_p->service_type = service_type;
    /* reset parameter */
    mdi_mtv_p->audio_mode = MDI_ATV_DEFAULT;

    /* MoDIS doesn't support DTV player */
#if (!defined(__MTK_TARGET__)) && defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    auto_play = MMI_FALSE;
#endif
    if (auto_play)
    {
        if (mdi_audio_is_speech_mode() && setting_p->play_audio == MMI_TRUE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MDI_RET, MDI_RES_MTV_FAILED);
            return MDI_RES_MTV_FAILED;
        }

        ASSERT(setting_p != NULL);
        mdi_mtv_player_config_player_setting(mtv_handle, setting_p);

        ret = media_mtv_start_service(
                MOD_MMI,
                mtv_handle,
                service_id,
                MEDIA_MTV_SERVICE_ACTIVITY_PLAY,
                mdi_mtv_p->service_seq_no);
    }
    else
    {
        ret = media_mtv_start_service(
                MOD_MMI,
                mtv_handle,
                service_id,
                0, /* Do not Auto play */
                mdi_mtv_p->service_seq_no);
    }


    if (ret != MED_RES_OK)
    {
        if (auto_play)
        {
            mdi_mtv_player_reset_video_setting();
        }

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->service_id = service_id;

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_INIT;
    if (auto_play)
    {
        mdi_mtv_p->player_state = MDI_MTV_PLAYER_STATE_PLAYING;
    }

    return MDI_RES_MTV_SUCCEED;
#else
    StartTimer(MTV_PLAYER_UT_TIMER, 1000, mdi_mtv_start_service_wait_ready);
    return MDI_RES_MTV_SUCCEED;
#endif
}


MDI_RESULT mdi_mtv_stop_service(U32 mtv_handle, U32 service_id)
{
#if defined(__MTK_TARGET__)  || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_STOP_SERVICE, mdi_mtv_p->service_seq_no, service_id);

    ASSERT(mdi_mtv_p->context == mtv_handle);
    ASSERT(mdi_mtv_p->service_id == service_id);

    ret = media_mtv_stop_service(MOD_MMI, mtv_handle, service_id);
    mdi_mtv_p->service_seq_no ++;

    ASSERT(ret == MED_RES_OK);

    if (ret != MED_RES_OK)
    {
        return MDI_RES_MTV_FAILED;
    }

    if (mdi_mtv_p->player_state == MDI_MTV_PLAYER_STATE_PLAYING)
    {
        mdi_mtv_player_reset_video_setting();
        mdi_mtv_p->player_state = MDI_MTV_PLAYER_STATE_STOPPED;
    }

    /* Reset service id as a invalid number */
    mdi_mtv_p->service_id = (U32) -1;

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_OPENED;

    return MDI_RES_MTV_SUCCEED;

#else
    StopTimer(MTV_PLAYER_UT_TIMER);
    return MDI_RES_MTV_SUCCEED;
#endif
}


MDI_RESULT mdi_mtv_service_get_status(U32 mtv_handle, mdi_mtv_service_status_struct *status)
{
#if defined (__MTK_TARGET__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    media_mtv_service_status_struct mtv_s;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_service_get_status(MOD_MMI, mtv_handle, mdi_mtv_p->service_id, &mtv_s);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_SERVICE_GET_STATUS, mdi_mtv_p->service_seq_no, mtv_s.signal_strength, mtv_s.timeshift_available, mtv_s.state);
    ASSERT(ret == MED_RES_OK);

    status->signal_strength = mtv_s.signal_strength;
    status->state = mtv_s.state;
    status->timeshift_available = mtv_s.timeshift_available;

    if (ret!=MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }
#else
    status->signal_strength = 100;
#endif
    return MDI_RES_MTV_SUCCEED;
}


static void mdi_mtv_player_reset_video_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TVOUT__
    /* restore TV owner */
    if (mdi_mtv_p->is_tvout)
    {
        if (mdi_mtv_p->tvout_prev_owner != MDI_TV_OWNER_VIDEO)
        {
            mdi_tvout_set_owner(mdi_mtv_p->tvout_prev_owner);
        }
    }
#endif /* __MMI_TVOUT__ */

    /* un-freeze sublcd */
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_freeze(MMI_FALSE);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* __MMI_SUBLCD__ */

    gdi_lcd_set_hw_update(MMI_FALSE);
}


MDI_RESULT mdi_mtv_player_set_hw_rotator(U16 rotate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MDI_MTV_HW_ROTATOR_SUPPORT__
    mdi_mtv_p->hw_rotator_rotate = rotate;
#endif /* __MDI_MTV_HW_ROTATOR_SUPPORT__ */

    return MDI_RES_MTV_SUCCEED;
}


static MDI_RESULT mdi_mtv_player_config_player_setting(U32 mtv_handle, mdi_mtv_player_setting_struct *setting_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    media_config_video_struct video = {0};
    media_config_audio_struct audio;
    mdi_blt_para_struct blt_data;
    U8 rotate;
    S32 layer_width, layer_height;
    gdi_color_format format;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


#ifdef __MMI_BT_AUDIO_VIA_SCO__
    /* Connect SCO to output audio to BT earpone */
    srv_btsco_connect_audio_via_sco();
#endif

    /* audio setting */
    audio.audio_path = MDI_DEVICE_SPEAKER2;
    audio.audio_mode = mdi_mtv_p->audio_mode;
    audio.play_audio = setting_p->play_audio;
    
#ifdef __MTV_REC_SUPPORT__
    mdi_mtv_get_image_size(
        &video.image_width, &video.image_height, &video.encode_quality);

#if 1 //def __ATV_RECORD_MPEG4_SUPPORT__
    video.encode_format = MPL_RECORDER_FORMAT_MPEG4;
#else
/* under construction !*/
#endif

#endif /* __MTV_REC_SUPPORT__ */

    if (setting_p->storage == MDI_MTV_RECORDER_STORAGE_PHONE)
    {
        video.storage = MPL_RECORDER_STORAGE_PHONE;
    }
    else
    {
        video.storage = MPL_RECORDER_STORAGE_CARD;
    }

    /* Video display setting */
    if (setting_p->is_visual_update && setting_p->play_layer_handle)
    {
    #ifdef __MMI_SUBLCD__
        /* Freeze sublcd */        
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_freeze(MMI_TRUE);
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);        
    #endif /* __MMI_SUBLCD__ */

        gdi_layer_get_actual_rotate_value(setting_p->play_layer_handle, &rotate);
        switch (rotate)
        {
            case GDI_LAYER_ROTATE_0:
                video.idp_rotate = 0;
                break;

            case GDI_LAYER_ROTATE_90:
                video.idp_rotate = 90;
                break;

            case GDI_LAYER_ROTATE_180:
                video.idp_rotate = 180;
                break;

            case GDI_LAYER_ROTATE_270:
                video.idp_rotate = 270;
                break;

            default:
                MMI_ASSERT(0);
        }

        gdi_layer_push_and_set_active(setting_p->play_layer_handle);
        gdi_lcd_lock_mutex(); 
        gdi_waiting_blt_finish();
    
        gdi_layer_get_color_format(&format);
        gdi_layer_get_dimension(&layer_width, &layer_height);
        gdi_layer_get_buffer_ptr(&video.image_buffer_p);        

        video.display_width = layer_width;
        video.display_height = layer_height;
        video.image_buffer_size = (layer_width * layer_height * GDI_LAYER.act_bit_per_pixel) >> 3;

        if (format == GDI_COLOR_FORMAT_UYVY422)
        {
            video.image_data_format = IMG_COLOR_FMT_PACKET_YUYV422;
        }
        else
        {
            video.image_data_format = IMG_COLOR_FMT_RGB565;
        }

        video.play_speed = 100;
        video.display_device = MED_DISPLAY_TO_MAIN_LCD;

        video.repeats = 0xffff;

    #if defined(__MMI_ATV_SUPPORT__)
        video.force_lcd_hw_trigger = KAL_TRUE;
    #else
        video.force_lcd_hw_trigger = KAL_FALSE;
    #endif

    #ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
        video.frame_mode = MED_VID_FRAME_FIT_INSIDE;
    #else /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */
        video.frame_mode = MED_VID_FRAME_STRETCH;
    #endif /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */

        /* default MAIN_LCD */
        video.lcd_id = MAIN_LCD;
        video.update_layer = setting_p->blt_layer_flag;
        video.hw_update_layer = setting_p->play_layer_flag;

        video.visible = setting_p->is_visual_update;
        video.brightness = mdi_mtv_get_brightness_value();
        video.contrast = mdi_mtv_get_contrast_value();
        video.saturation = mdi_mtv_get_saturation_value();
        video.gamma = 0;

    #if defined(__MMI_ATV_SUPPORT__)
        video.video_mode = mdi_mtv_p->video_mode;
    #endif /* __MMI_ATV_SUPPORT__ */

        gdi_layer_set_blt_layer_previous();
        gdi_layer_set_hw_update_layer(setting_p->play_layer_handle, MMI_TRUE);

    	gdi_lcd_set_hw_update(TRUE);

        gdi_lcd_unlock_mutex();
        gdi_layer_pop_and_restore_active();
    
        /* Invoke after set_blt_layer_previous() */
        gdi_layer_get_layer_element(
            setting_p->play_layer_flag,
            &video.layer_element,
            &video.blt_ctx,
            &video.blt_dev);    
    }
    
    ret = media_mtv_config(MOD_MMI, mtv_handle, &video, &audio, NULL);
    ASSERT(ret == MED_RES_OK);

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_player_play(U32 mtv_handle, mdi_mtv_player_setting_struct *setting_p)
{
#if defined(__MTK_TARGET__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_PLAYER_PLAY, mdi_mtv_p->player_seq_no,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    if (mdi_audio_is_speech_mode() && setting_p->play_audio == MMI_TRUE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MDI_RET, MDI_RES_MTV_START_PLAY_FAIL);
        return MDI_RES_MTV_START_PLAY_FAIL;
    }

    mdi_mtv_player_config_player_setting(mtv_handle, setting_p);

    ret = media_mtv_player_play(MOD_MMI,mtv_handle,mdi_mtv_p->service_id, mdi_mtv_p->player_seq_no);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);

        /* Reset some parameter */
        mdi_mtv_player_reset_video_setting();
        result = MDI_RES_MTV_START_PLAY_FAIL;
    }
    else
    {
        mdi_mtv_p->player_state = MDI_MTV_PLAYER_STATE_PLAYING;
        result = MDI_RES_MTV_SUCCEED;
    }

    return result;
#else  /* __MTK_TARGET__ || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) */
    return MDI_RES_MTV_SUCCEED;
#endif  /* __MTK_TARGET__ || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) */

}


MDI_RESULT mdi_mtv_player_stop(U32 mtv_handle)
{
#if defined(__MTK_TARGET__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_PLAYER_STOP, mdi_mtv_p->player_seq_no, mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_player_stop(MOD_MMI, mtv_handle, mdi_mtv_p->service_id);
    mdi_mtv_p->player_seq_no ++;

    mdi_mtv_player_reset_video_setting();

    ASSERT(ret == MED_RES_OK);
    if (ret!=MED_RES_OK)
    {
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->player_state = MDI_MTV_PLAYER_STATE_STOPPED;

    return MDI_RES_MTV_SUCCEED;
#else
    return MDI_RES_MTV_SUCCEED;
#endif
}

#ifdef __MTV_TS_SUPPORT__

MDI_RESULT mdi_mtv_start_timeshift(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_START_TIMESHIFT, mdi_mtv_p->player_seq_no, mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_start_timeshift(MOD_MMI, mtv_handle, mdi_mtv_p->service_id, mdi_mtv_p->player_seq_no);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;

}


MDI_RESULT mdi_mtv_player_pause(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_PLAYER_PAUSE,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_player_pause(MOD_MMI, mtv_handle, mdi_mtv_p->service_id);
    mdi_mtv_p->player_seq_no ++;

    mdi_mtv_player_reset_video_setting();

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_ERR_PAUSE_FAILED;
    }

    mdi_mtv_p->player_state = MDI_MTV_PLAYER_STATE_PAUSED;

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_player_seek(U32 mtv_handle, U32 play_delay)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_PLAYER_SEEK, mdi_mtv_p->recorder_seq_no,play_delay);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_player_seek(MOD_MMI, mtv_handle, mdi_mtv_p->service_id,play_delay);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_ERR_DISC_IO_ERROR;
    }

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_player_set_speed(U32 mtv_handle, S32 speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_PLAYER_SET_SPEED, speed);

    ret = media_mtv_player_set_rate(MOD_MMI, mtv_handle, mdi_mtv_p->service_id, speed);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_ERR_SET_SPEED_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_player_get_status(U32 mtv_handle, mdi_mtv_player_status_struct *status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    media_mtv_player_status_struct mtv_s;
    kal_int32 idx = 0, buf = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_player_get_status(MOD_MMI, mtv_handle, mdi_mtv_p->service_id, &mtv_s);

    if (mtv_s.buffer_duration != 0)
    {
        idx = 100 * (mtv_s.max_delay - mtv_s.play_delay) / mtv_s.buffer_duration;
        buf = 100 * mtv_s.max_delay / mtv_s.buffer_duration;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_PLAYER_GET_STATUS,
                mtv_s.play_delay,
                idx,
                mtv_s.max_delay,
                buf,
                mtv_s.buffer_duration,
                mtv_s.play_rate,
                mtv_s.state);

    ASSERT(ret == MED_RES_OK);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    status->max_delay = mtv_s.max_delay;
    status->play_delay = mtv_s.play_delay;
    status->play_rate = mtv_s.play_rate;
    status->buffer_duration = mtv_s.buffer_duration;
    status->state = mtv_s.state;

    return MDI_RES_MTV_SUCCEED;
}

MDI_RESULT mdi_mtv_enable_timeshift(U32 mtv_handle,PU8 record_dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_config_record_struct record;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_mtv_p->enable_timeshift = record.enable_timeshift = MMI_TRUE;
    mdi_mtv_p->max_timeshift_delay = record.max_timeshift_delay = 0; /* NO USE */
    mdi_mtv_p->max_timeshift_buffer_kb = record.max_timeshift_buffer_kb = 16 * 1024;
    mdi_mtv_p->record_dir = record_dir;

    record.record_dir = (kal_wchar*)mdi_mtv_p->record_dir;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_ENABLE_TIMESHIFT);

    ret = media_mtv_config(MOD_MMI, mtv_handle, NULL, NULL, &record);

    ASSERT(ret == MED_RES_OK);
    return ret;
}


MDI_RESULT mdi_mtv_disable_timeshift(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_config_record_struct record;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_mtv_p->enable_timeshift = record.enable_timeshift = MMI_FALSE;
    mdi_mtv_p->max_timeshift_delay = record.max_timeshift_delay = 0; /* NO USE */
    mdi_mtv_p->max_timeshift_buffer_kb = record.max_timeshift_buffer_kb = 0;
    mdi_mtv_p->record_dir = NULL;

    record.record_dir = (kal_wchar*)mdi_mtv_p->record_dir;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_DISABLE_TIMESHIFT);

    ret = media_mtv_config(MOD_MMI, mtv_handle, NULL, NULL, &record);

    ASSERT(ret == MED_RES_OK);
    return ret;
}

#endif /* __MTV_TS_SUPPORT__ */
#ifdef __MTV_REC_SUPPORT__
MDI_RESULT mdi_mtv_recorder_start(U32 mtv_handle, CHAR *file_name)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_mtv_p->recorder_seq_no++;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_RECORDER_START, mdi_mtv_p->recorder_seq_no,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_recorder_start(MOD_MMI, mtv_handle, mdi_mtv_p->service_id, (WCHAR*)file_name, mdi_mtv_p->recorder_seq_no);

    if (ret == MED_RES_DISC_FULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_ERR_DISC_FULL;
    }
    else if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_ERR_RECORD_FAILED;
    }

    mdi_mtv_p->recorder_state = MDI_MTV_RECORDER_STATE_STARTED;
#endif /* defined(__MTK_TARGET__) */
    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_recorder_stop(U32 mtv_handle)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_RECORDER_STOP,mdi_mtv_p->recorder_seq_no,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_recorder_stop(MOD_MMI, mtv_handle, mdi_mtv_p->service_id);
    mdi_mtv_p->recorder_seq_no++;

    ASSERT(ret == MED_RES_OK);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->recorder_state = MDI_MTV_RECORDER_STATE_STOPPED;
#endif /* defined(__MTK_TARGET__) */
    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_recorder_pause(U32 mtv_handle)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_RECORDER_PAUSE,mdi_mtv_p->recorder_seq_no,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_recorder_pause(MOD_MMI, mtv_handle, mdi_mtv_p->service_id);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);

        mdi_mtv_p->recorder_state = MDI_MTV_RECORDER_STATE_STOPPED;
        mdi_mtv_p->recorder_seq_no++;
        
        if (ret == MED_RES_DISC_FULL)
        {
            return MDI_RES_MTV_ERR_DISC_FULL;
        }
        else
        {
            return MDI_RES_MTV_FAILED;
        }
    }
    else
    {
        mdi_mtv_p->recorder_state = MDI_MTV_RECORDER_STATE_PAUSED;
        return MDI_RES_MTV_SUCCEED;
    }


#else /* (__MTK_TARGET__) */ 
    return MDI_RES_MTV_SUCCEED;
#endif /* (__MTK_TARGET__) */
}


MDI_RESULT mdi_mtv_recorder_resume(U32 mtv_handle)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_RECORDER_RESUME,mdi_mtv_p->recorder_seq_no,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    if (mdi_mtv_p->recorder_state != MDI_MTV_RECORDER_STATE_PAUSED)
    {
        return MDI_RES_MTV_ERR_RECORD_RESUME_FAILED;
    }

    ret = media_mtv_recorder_resume(MOD_MMI, mtv_handle, mdi_mtv_p->service_id);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_ERR_RECORD_RESUME_FAILED;
    }

    mdi_mtv_p->recorder_state = MDI_MTV_RECORDER_STATE_STARTED;
#endif /* defined(__MTK_TARGET__) */
    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_recorder_save(U32 mtv_handle, WCHAR *file_path)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_mtv_p->recorder_seq_no++;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_RECORDER_SAVE, mdi_mtv_p->recorder_seq_no,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_recorder_save(MOD_MMI, mtv_handle, mdi_mtv_p->service_id, (WCHAR*)file_path, mdi_mtv_p->recorder_seq_no);

    ASSERT(ret == MED_RES_OK);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_ERR_SAVE_FAILED;
    }
#else /* (__MTK_TARGET__) */
    StartTimer(MTV_PLAYER_UT_TIMER, 2000, mdi_mtv_send_record_saved_ind);
#endif /* (__MTK_TARGET__) */
    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_recorder_discard_recording(U32 mtv_handle)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_RECORDER_DISCARD_RECORDING, mdi_mtv_p->recorder_seq_no,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_recorder_discard_recording(MOD_MMI, mtv_handle, mdi_mtv_p->service_id, mdi_mtv_p->recorder_seq_no);
    ASSERT(ret == MED_RES_OK);

    if (ret!=MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }
#else /* (__MTK_TARGET__) */
    StartTimer(MTV_PLAYER_UT_TIMER, 2000, mdi_mtv_send_record_deleted_ind);
#endif /* (__MTK_TARGET__) */

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_recorder_abort_saving(U32 mtv_handle)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_RECORDER_ABORT_SAVING, mdi_mtv_p->recorder_seq_no,mdi_mtv_p->service_id);

    ret = media_mtv_recorder_abort_saving(MOD_MMI,mtv_handle,mdi_mtv_p->service_id);

    mdi_mtv_p->recorder_seq_no++;

    return ret;
#else   /* defined(__MTK_TARGET__) */
    return MDI_RES_MTV_SUCCEED;
#endif  /* defined(__MTK_TARGET__) */

}


MDI_RESULT mdi_mtv_set_storage(U32 mtv_handle,PU8 record_dir)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_config_record_struct record;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_mtv_p->enable_timeshift = record.enable_timeshift = MMI_FALSE;
    mdi_mtv_p->max_timeshift_delay = record.max_timeshift_delay = 0; /* NO USE */
    mdi_mtv_p->max_timeshift_buffer_kb = record.max_timeshift_buffer_kb = 0;
    mdi_mtv_p->record_dir = record_dir;

    record.record_dir = (kal_wchar*)mdi_mtv_p->record_dir;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_SET_STORAGE);

    ret = media_mtv_config(MOD_MMI, mtv_handle, NULL, NULL, &record);

    ASSERT(ret == MED_RES_OK);
    return ret;
#else
    return MDI_RES_MTV_SUCCEED;
#endif
}

#endif /* __MTV_REC_SUPPORT__ */

MDI_RESULT mdi_mtv_get_audio_sample_rate(U32 mtv_handle, U32 service_id, U32 *sample_rate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 sr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_get_param(MOD_MMI,mtv_handle,service_id, MEDIA_MTV_SERVICE_PARAM_AUDIO_SAMPLE_RATE, &sr);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_GET_AUDIO_SAMPLE_RATE,mdi_mtv_p->service_seq_no,sr);
    ASSERT(ret == MED_RES_OK);

    *sample_rate = sr;
    return ret;
}


MDI_RESULT mdi_mtv_get_audio_channel_number(U32 mtv_handle, U32 service_id, U32 *aud_channel_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 acn;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_get_param(MOD_MMI,mtv_handle,service_id, MEDIA_MTV_SERVICE_PARAM_AUDIO_CHANNEL_NUMBER, &acn);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_GET_AUDIO_CHANNEL_NUMBER,mdi_mtv_p->service_seq_no,acn);
    ASSERT(ret == MED_RES_OK);

    *aud_channel_num = acn;
    return ret;
}

MDI_RESULT mdi_mtv_get_hw_layer_buffer_content(gdi_handle layer_handle, U8 *dst_buff_p, U32 dst_buff_size)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_buf_content_struct buf_content;
    gdi_color_format format;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_GET_HW_LAYER_BUFFER_CONTENT, layer_handle);
    buf_content.buffer_size = dst_buff_size;
    buf_content.frame_mode = MED_VID_FRAME_STRETCH;

    gdi_layer_push_and_set_active(layer_handle);
    gdi_layer_get_dimension(&buf_content.buffer_width, &buf_content.buffer_height);
    gdi_layer_get_buffer_ptr(&buf_content.buffer_address);
    gdi_layer_get_color_format(&format);
    gdi_layer_pop_and_restore_active();

    ASSERT(buf_content.buffer_address == dst_buff_p);
    if (format == GDI_COLOR_FORMAT_UYVY422)
    {
        buf_content.image_data_format = IMG_COLOR_FMT_PACKET_YUYV422;
    }
    else
    {
        buf_content.image_data_format = IMG_COLOR_FMT_RGB565;
    }


    ret = media_mtv_player_snapshot(
            MOD_MMI, mdi_mtv_p->context, mdi_mtv_p->service_id, NULL, &buf_content);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }
#endif /* __MTK_TARGET__) */
    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_get_snapshot(U32 mtv_handle,gdi_handle layer_handle, WCHAR *file_path)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_GET_SNAPSHOT, mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);

#ifdef __DIRECT_SENSOR_SUPPORT__
    ret = media_mtv_player_snapshot(MOD_MMI, mtv_handle, mdi_mtv_p->service_id, file_path);

    if (ret == MED_RES_DISC_FULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_ERR_DISC_FULL;
    }
    else if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_ERR_SNAPSHOT_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
#else

    ret = gdi_image_encode_layer_to_jpeg(
                    layer_handle,
                    (CHAR *)file_path);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
    if (ret == GDI_IMAGE_ENCODER_ERR_DISK_FULL)
    {
         MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_ERR_DISC_FULL;
    }
    else if (ret != GDI_SUCCEED)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_ERR_SNAPSHOT_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
#endif
}

#if defined(__MMI_ATV_SUPPORT__)
#ifdef __ATV_RECORD_SUPPORT__
MDI_RESULT mdi_mtv_get_supported_record_size(U32 mtv_handle, S32 *record_size_num, mdi_mtv_recorder_size_enum *record_size_list)
{
#if defined(__MTK_TARGET__)


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CUSTOM_VENC_ERROR_T error;
    CUSTOM_VENC_USER_T user;
    CUSTOM_VENC_UPPER_TABLE_T table;
    U32 entry_num = 0, video_mode;
    S32 idx, suported_idx, ret;
    MMI_BOOL supported[MDI_MTV_RECORDER_SIZE_COUNT] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_get_param(
            MOD_MMI,mtv_handle, 0, MEDIA_MTV_SERVICE_PARAM_VIDEO_MODE, &video_mode);
    ASSERT(ret == MED_RES_OK);

    mdi_mtv_p->video_mode = video_mode;

    switch (mdi_mtv_p->video_mode)
    {
    #if 1 //def __ATV_RECORD_MPEG4_SUPPORT__
        case ATV_VIDEO_NTSC:
            user = CUSTOM_VENC_USER_MATV_MPEG4_NTSC;
            break;
        case ATV_VIDEO_PAL:
            user = CUSTOM_VENC_USER_MATV_MPEG4_PAL;
            break;        
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif 
        defatult:
            ASSERT(0);
            user = CUSTOM_VENC_USER_MATV_MPEG4_PAL;
            break;        
    }


    error = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_USER,&user, sizeof(user), NULL, 0);
    error = CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_NUM_OF_ENTRIES, NULL, 0, &entry_num, sizeof(entry_num));
    ASSERT(error == CUSTOM_VENC_ERROR_NONE);

    suported_idx = 0;
    for (idx = 0; idx < entry_num && suported_idx < MDI_MTV_RECORDER_SIZE_COUNT; idx ++)
    {
        error = CustomVenc_Ctrl(
                    CUSTOM_VENC_OP_GET_ONE_ENTRY,
                    &idx, sizeof(idx), &table, sizeof(table));
        ASSERT(error == CUSTOM_VENC_ERROR_NONE);

        if (!supported[MDI_MTV_RECORDER_SIZE_QCIF] &&
            table.eResolution == CUSTOM_VENC_RESOLUTION_176x144)
        {
            supported[MDI_MTV_RECORDER_SIZE_QCIF] = MMI_TRUE;
            record_size_list[suported_idx++] = MDI_MTV_RECORDER_SIZE_QCIF;
        }
        else if (!supported[MDI_MTV_RECORDER_SIZE_QVGA] &&
                 table.eResolution == CUSTOM_VENC_RESOLUTION_320x240)
        {
            supported[MDI_MTV_RECORDER_SIZE_QVGA] = MMI_TRUE;
            record_size_list[suported_idx++] = MDI_MTV_RECORDER_SIZE_QVGA;
        }
        else if (!supported[MDI_MTV_RECORDER_SIZE_HVGA] &&
                 table.eResolution == CUSTOM_VENC_RESOLUTION_480x320)
        {
            supported[MDI_MTV_RECORDER_SIZE_HVGA] = MMI_TRUE;
            record_size_list[suported_idx++] = MDI_MTV_RECORDER_SIZE_HVGA;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_GET_SUPPORTED_RECORD_SIZE,
        video_mode, suported_idx, supported[0], supported[1], supported[2]);

    *record_size_num = suported_idx;
    return MDI_RES_MTV_SUCCEED;
#else
    record_size_list[0] = MDI_MTV_RECORDER_SIZE_QCIF;
    record_size_list[1] = MDI_MTV_RECORDER_SIZE_QVGA;
    record_size_list[2] = MDI_MTV_RECORDER_SIZE_HVGA;
    *record_size_num = 3;
    return MDI_RES_MTV_SUCCEED;
#endif
}
#endif /* __ATV_RECORD_SUPPORT__ */


MDI_RESULT mdi_mtv_delete_channel(U32 mtv_handle, U32 service_id)
{
#if defined(__MTK_TARGET__)    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_DELETE_CHANNEL, service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_set_param(MOD_MMI, mtv_handle, service_id, MEDIA_MTV_SERVICE_PARAM_DISABLE, 0);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }
#endif    
    return MDI_RES_MTV_SUCCEED;
}



MDI_RESULT mdi_mtv_set_audio_mode(U32 mtv_handle, U32 service_id, U32 mode)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_SET_AUDIO_MODE, service_id, mode);

    mdi_mtv_p->audio_mode = mode;

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_set_param(MOD_MMI, mtv_handle, service_id, MEDIA_MTV_SERVICE_PARAM_AUDIO_MODE, (kal_uint32) mode);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }
#endif /* __MTK_TARGET__ */
    return MDI_RES_MTV_SUCCEED;

}


MDI_RESULT mdi_mtv_get_service_by_index(U32 mtv_handle, S32 index, mdi_mtv_service_info_struct *service_info)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_service_info_struct info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_GET_SERVICE_BY_INDEX, index);


    ret = media_mtv_get_param(MOD_MMI,mtv_handle, index, MEDIA_MTV_SERVICE_PARAM_SERVICE_INFO_BY_INDEX, (kal_uint32*)&info);

    MMI_TRACE(
        MMI_MEDIA_TRC_G4_MDI,
        MDI_TRC_MTV_SERVICE_INFO,
        info.service_id,
        info.service_number,
        info.service_type,
        info.service_flags,
        info.audio_mode,
        info.supported_audio_mode);

    if (ret == MED_RES_OK)
    {
        service_info->service_id = info.service_id;
        service_info->service_name = (CHAR *)info.service_name;
        service_info->service_number = info.service_number;
        service_info->service_type = info.service_type;
        service_info->service_flags = info.service_flags;
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
#else
    return MDI_RES_MTV_FAILED;
#endif
}

#endif /* __MMI_ATV_SUPPORT__ */

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
MDI_RESULT mdi_mtv_player_pause_visual_update(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_PLAYER_PAUSE_VISUAL_UPDATE, mdi_mtv_p->player_seq_no, mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ASSERT(mdi_mtv_p->player_state == MDI_MTV_PLAYER_STATE_PLAYING);

    ret = media_mtv_player_pause_visual_update(
            MOD_MMI, mtv_handle, mdi_mtv_p->service_id);

    mdi_mtv_player_reset_video_setting();

    if (ret!=MED_RES_OK)
    {
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_player_resume_visual_update(U32 mtv_handle, mdi_mtv_player_setting_struct *setting_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_PLAYER_RESUME_VISUAL_UPDATE, mdi_mtv_p->player_seq_no,mdi_mtv_p->service_id);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ASSERT(mdi_mtv_p->player_state == MDI_MTV_PLAYER_STATE_PLAYING);

    if (mdi_audio_is_speech_mode() && setting_p->play_audio == MMI_TRUE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MDI_RET, MDI_RES_MTV_START_PLAY_FAIL);
        return MDI_RES_MTV_START_PLAY_FAIL;
    }

    mdi_mtv_player_config_player_setting(mtv_handle, setting_p);

    ret = media_mtv_player_resume_visual_update(MOD_MMI,mtv_handle,mdi_mtv_p->service_id);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);

        /* Reset some parameter */
        mdi_mtv_player_reset_video_setting();
        result = MDI_RES_MTV_START_PLAY_FAIL;
    }
    else
    {
        result = MDI_RES_MTV_SUCCEED;
    }

    return result;
}


MDI_RESULT mdi_mtv_set_sleep_time(U8 elapse_ticks, U8 sleep_ticks)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mtv_player_sleep_time_struct sleep_struct;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sleep_struct.elapse_ticks = elapse_ticks;
    sleep_struct.sleep_ticks = sleep_ticks;

    ret = media_mtv_set_param(
            MOD_MMI,
            mdi_mtv_p->context,
            mdi_mtv_p->service_id,
            MEDIA_MTV_SERVICE_PARAM_PLAYER_SET_SLEEP_TIME,
            (kal_uint32) &sleep_struct);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    /* always succeed */
    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_esg_query(
                U32 mtv_handle,
                media_mtv_esg_source_enum source,
                esg_query_type_enum query_type,
                mdi_mtv_query_struct *query_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    applib_time_struct *t;
    media_mtv_esg_query_struct esg_query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_ESG_QUERY,
        query_type, query_param->id);

    if (mdi_mtv_p->block_query)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, MDI_RES_MTV_ERR_DEVICE_BUSY);
        return MDI_RES_MTV_ERR_DEVICE_BUSY;
    }

    if (query_param->time != NULL)
    {
        t = query_param->time;
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_ESG_TIME,
            t->nYear, t->nMonth, t->nDay, t->nHour, t->nMin, t->nSec);
    }

    mdi_mtv_p->query_type = query_type;

    esg_query.ref_id = query_param->id;
    esg_query.rid = query_param->rid;
    esg_query.lang_type = query_param->lang_type;
    esg_query.applib_time = query_param->time;
    esg_query.keyword = query_param->keyword;
    esg_query.start_idx = query_param->start_idx;
    esg_query.query_num = query_param->query_num;

    ret = media_mtv_esg_query(
            MOD_MMI, mtv_handle, source, query_type, &esg_query);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_esg_get_result(
                U32 mtv_handle,
                media_mtv_esg_source_enum source,
                esg_query_type_enum query_type,
                void **buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_ESG_GET_RESULT, query_type);

    if (mdi_mtv_p->block_query)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, MDI_RES_MTV_ERR_DEVICE_BUSY);
        return MDI_RES_MTV_ERR_DEVICE_BUSY;
    }

    ASSERT(*buf_ptr == NULL);
    ASSERT(mdi_mtv_p->query_type == query_type);

    ret = media_mtv_esg_get_results(
            MOD_MMI,
            mtv_handle,
            source,
            mdi_mtv_p->query_type,
            (void **)buf_ptr);

    if (*buf_ptr == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_BUFFER_PTR, *buf_ptr);
    }

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_add_favorite(
                U32 mtv_handle,
                mdi_mtv_favorite_type_enum type,
                U32 id,
                CHAR *rid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_favorite_type_enum favo_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_ADD_FAVORITE, type, id);

    if (type == MDI_MTV_FAVO_CHANNEL)
    {
        favo_type = MEDIA_MTV_FAVO_CHANNEL;
    }
    else if (type == MDI_MTV_FAVO_CONTENT)
    {
        favo_type = MEDIA_MTV_FAVO_CONTENT;
    }
    else if (type == MDI_MTV_FAVO_LOCAL_PURCHASE_ITEM)
    {
        favo_type = MEDIA_MTV_FAVO_LOCAL_PURCHASE_ITEM;
    }

    ret = media_mtv_esg_add_favorite(MOD_MMI, mtv_handle, favo_type, id, rid);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);

        if (ret == MED_RES_OVER_LIMIT)
        {
            return MDI_RES_MTV_ERR_OVER_LIMIT;
        }
        else
        {
        return MDI_RES_MTV_FAILED;
    }
    }

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_delete_favorite(
                U32 mtv_handle,
                mdi_mtv_favorite_type_enum type,
                U32 id,
                CHAR *rid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_favorite_type_enum favo_type = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_DELETE_FAVORITE, type, id);

    if (type == MDI_MTV_FAVO_CHANNEL)
    {
        favo_type = MEDIA_MTV_FAVO_CHANNEL;
    }
    else if (type == MDI_MTV_FAVO_CONTENT)
    {
        favo_type = MEDIA_MTV_FAVO_CONTENT;
    }
    else if (type == MDI_MTV_FAVO_EB)
    {
        favo_type = MEDIA_MTV_FAVO_EB;
    }
    ret = media_mtv_esg_del_favorite(MOD_MMI, mtv_handle, favo_type, id, rid);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_purify_program_reminder(U32 mtv_handle, applib_time_struct *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_favorite_type_enum favo_type = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_PURIFY_PROG_REMINDER);

    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_PURIFY_PROG_REMINDER, (kal_uint32)time);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_set_preview_data_downloaded(U32 mtv_handle, WCHAR *file_path, MMI_BOOL downloaded)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_esg_update_struct update;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_SET_PREVIEW_DATA_DOWNLOADED, downloaded);

    update.rid = (CHAR *)file_path;
    update.value = &downloaded;
    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_PREVIEW_DATA_DOWNLOADED, (kal_uint32)&update);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_start_esg_download(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_mtv_p->service_seq_no ++;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_START_ESG_DOWNLOAD, mdi_mtv_p->service_seq_no);

    // add seq num
    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_media_mtv_esg_download(MOD_MMI, mtv_handle);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_ESG_DOWNLOADING;

    return MDI_RES_MTV_SUCCEED;
}

MDI_RESULT mdi_mtv_set_emm(U32 mtv_handle, U32 emm_len, U8* emm_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    media_mtv_emm_info_struct emm_struct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_MEDIA_APP,"mdi_mtv_set_emm. len:%d", emm_len);
    
    ASSERT(mtv_handle == mdi_mtv_p->context);

    emm_struct.emm_len  = emm_len;
    emm_struct.emm_data = emm_data;
    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_SET_EMM, (kal_uint32)&emm_struct);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_EMM;
    return MDI_RES_MTV_SUCCEED;
}
    
MDI_RESULT mdi_mtv_ca_query(U32 mtv_handle, U32 block_len , U32* block_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_ca_info_struct ca_struct = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_MEDIA_APP,"mdi_mtv_ca_query. [0x%x|0x%x], len:%d", 
                     block_data[0], block_data[1], block_len);
    
    ASSERT(mtv_handle == mdi_mtv_p->context);
    ca_struct.block_len  = block_len;
    ca_struct.block_data = block_data;

    ret = media_mtv_set_param(
            MOD_MMI,mtv_handle, 0, MEDIA_MTV_SERVICE_PARAM_CA_QUERY, (kal_uint32)&ca_struct);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_CA;
    return MDI_RES_MTV_SUCCEED;
}

MDI_RESULT mdi_mtv_get_nit_time(U32 mtv_handle, mdi_mtv_nit_time_struct *nit_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_nit_time_struct time_struct = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_get_param(MOD_MMI, mtv_handle, 0, MEDIA_MTV_SERVICE_PARAM_NIT_TIME, (kal_uint32 *)&time_struct);
    ASSERT(ret == MED_RES_OK);
    nit_time->nYear     = time_struct.nYear;
    nit_time->nMonth    = time_struct.nMonth;
    nit_time->nDay      = time_struct.nDay;
    nit_time->nHour     = time_struct.nHour;
    nit_time->nMin      = time_struct.nMin;
    nit_time->nSec      = time_struct.nSec;
    nit_time->week      = time_struct.week;

    return MDI_RES_MTV_SUCCEED;
}

MDI_RESULT mdi_mtv_get_nit_area_code(U32 mtv_handle, U8* net_mode, U16* area_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_nit_area_struct area_struct = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_get_param(MOD_MMI, mtv_handle, 0, MEDIA_MTV_SERVICE_PARAM_NIT_AREA, (kal_uint32 *)&area_struct);
    ASSERT(ret == MED_RES_OK);

    *net_mode = area_struct.net_mode;
    *area_code = area_struct.area_code;
        
    return MDI_RES_MTV_SUCCEED;    
}


MDI_RESULT mdi_mtv_abort_esg_download(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_mtv_p->service_seq_no ++;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_ABORT_ESG_DOWNLOAD, mdi_mtv_p->service_seq_no);

    ASSERT(mtv_handle == mdi_mtv_p->context);
    ret = media_mtv_media_mtv_esg_abort_downloading(MOD_MMI, mtv_handle);
    ASSERT(ret == MED_RES_OK);

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_OPENED;

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_subscribe_purchase_item(U32 mtv_handle, CHAR *id, CHAR *gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    media_mtv_purchase_id_struct id_struct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_SUBSCRIBE_PURCHASE_ITEM, mdi_mtv_p->service_state);

    id_struct.id = id;
    id_struct.gid = gid;
    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_SUBSCRIBE, (kal_uint32)&id_struct);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_SUBSCRIBING;
    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_unsubscribe_purchase_item(U32 mtv_handle, CHAR *id, CHAR *gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    media_mtv_purchase_id_struct id_struct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_UNSUBSCRIBE_PURCHASE_ITEM, mdi_mtv_p->service_state);

    id_struct.id = id;
    id_struct.gid = gid;
    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_UNSUBSCRIBE, (kal_uint32)&id_struct);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_UNSUBSCRIBING;
    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_account_inquiry(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_ACCOUNT_INQUIRY, mdi_mtv_p->service_state);

    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_ACCOUNT_INQUIRY, 0);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_ACCOUNT_INQUIRY;
    return MDI_RES_MTV_SUCCEED;
}

MDI_RESULT mdi_mtv_upgrade_query(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_UPGRADE_QUERY, mdi_mtv_p->service_state);

    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_UPGRADE_QUERY, 0);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_UPGRADE_QUERY;
    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_area_set_retrieve(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_AREA_SET_RETRIEVE, mdi_mtv_p->service_state);

    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_AREA_SET_RETRIEVE, 0);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_AREA_SET_RETRIEVE;
    return MDI_RES_MTV_SUCCEED;
}

MDI_RESULT mdi_mtv_interactivity_retrieve(U32 mtv_handle, CHAR *content_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_INTERACTIVITY_RETRIEVE, mdi_mtv_p->service_state);

    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_INTERACTIVITY_RETRIEVE, (kal_uint32)content_id);
    
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);

        if (ret == MED_RES_FILE_EXIST)
        {
            return MDI_RES_MTV_FILE_EXISTED;
        }
        else
        {
            return MDI_RES_MTV_FAILED;
        }
    }

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_INTERACTIVITY_RETRIEVE;
    return MDI_RES_MTV_SUCCEED;
}

MDI_RESULT mdi_mtv_subscription_update(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_SUBSCRIPTOIN_UPDATE, mdi_mtv_p->service_state);

    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_SUBSCRIPTOIN_UPDATE, mdi_mtv_p->service_seq_no);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->service_state = MDI_MTV_SERVICE_STATE_SUBSCRIPTION_UPDATE;
    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_cancel_subscription_update(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_CANCEL_SUBSCRIPTOIN_UPDATE, mdi_mtv_p->service_state);

    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_CANCEL_SUBSCRIPTOIN_UPDATE, 0);
    ASSERT (ret == MED_RES_OK);

    mdi_mtv_p->service_seq_no ++;
    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_get_mbbms_description(U32 mtv_handle, U32 service_id, WCHAR *desc, S32 desc_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    media_mtv_subscribe_update_desc_struct info = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mtv_handle == mdi_mtv_p->context);

    info.desc_len = desc_len;
    info.desc = desc;

    ret = media_mtv_get_param(
            MOD_MMI, mtv_handle, service_id, MEDIA_MTV_SERVICE_PARAM_SUBSCRIBE_UPDATE_DESC, (kal_uint32 *)&info);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
}

MDI_RESULT mdi_mtv_get_services_ca(U32 mtv_handle, U32 service_id, U32 *flag, CHAR *purchase_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_service_ca_struct ca = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_get_param(MOD_MMI,mtv_handle,service_id, MEDIA_MTV_SERVICE_PARAM_SERVICE_CA, (kal_uint32 *)&ca);
    ASSERT(ret == MED_RES_OK);

    if (flag)
    {
        *flag = ca.flag;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_GET_SERVICE_CA, ca.flag);


    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_get_imd_count(U32 mtv_handle, U32 service_id, U32 *count, U32 *unread_count, U32 *first_unread_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_imd_count_struct count_struct = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_get_param(MOD_MMI,mtv_handle,service_id, MEDIA_MTV_SERVICE_PARAM_IMD_COUNT, (kal_uint32 *)&count_struct);
    ASSERT(ret == MED_RES_OK);

    *count = count_struct.count;
    *unread_count = count_struct.unread_count;
    *first_unread_idx = count_struct.first_unread_idx;

    return MDI_RES_MTV_SUCCEED;
}

MDI_RESULT mdi_mtv_get_imd_desc(
                U32 mtv_handle, 
                U32 service_id, 
                mdi_mtv_imd_desc_struct *imd_desc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_imd_desc_struct desc_struct = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mtv_handle == mdi_mtv_p->context);

    desc_struct.imd_index = imd_desc->imd_index;
    desc_struct.desc_len = imd_desc->desc_len;
    desc_struct.if_read = imd_desc->if_read;
    desc_struct.desc = imd_desc->desc;

    ret = media_mtv_get_param(MOD_MMI,mtv_handle,service_id, MEDIA_MTV_SERVICE_PARAM_IMD_DESC, (kal_uint32 *)&desc_struct);
    ASSERT(ret == MED_RES_OK);

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_get_imd_detail(
                U32 mtv_handle, 
                U32 service_id, 
                mdi_mtv_imd_detail_struct *imd_detail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_imd_detail_struct detail_struct = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mtv_handle == mdi_mtv_p->context);

    detail_struct.imd_type = imd_detail->imd_type;
    detail_struct.path_len = imd_detail->path_len;
    detail_struct.imd_index = imd_detail->imd_index;
    detail_struct.cid = imd_detail->content_id;
    detail_struct.path = imd_detail->path;

    ret = media_mtv_get_param(MOD_MMI, mtv_handle, service_id, MEDIA_MTV_SERVICE_PARAM_IMD_DETAIL, (kal_uint32 *)&detail_struct);
    ASSERT(ret == MED_RES_OK);

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_download_service_guide(U32 mtv_handle, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    media_mtv_purchase_id_struct id_struct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_DOWNLOAD_SG, mdi_mtv_p->service_state);

    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_DOWNLOAD_SG, (kal_uint32)param);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    mdi_mtv_p->block_query = MMI_TRUE;

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_update_service_guide(U32 mtv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    media_mtv_purchase_id_struct id_struct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI,MDI_TRC_MTV_UPDATE_SG, mdi_mtv_p->service_state);

    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, 0, MEDIA_MTV_SERVICE_PARAM_UPDATE_SG, 0);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
}


MDI_RESULT mdi_mtv_set_sim_info(U32 mtv_handle, mdi_mtv_cas_sim_struct *sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_cas_sim_struct param;
    U32 value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (sim)
    {
        param.is_usim = sim->is_usim;
        param.same_imsi = sim->same_imsi;
        kal_mem_cpy(param.imsi, sim->imsi, 16);
        kal_mem_cpy(param.bdscell_id, sim->bdscell_id, 17);

        value = (kal_uint32) &param;
    }
    else
    {
        value = 0;
    }

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_set_param(MOD_MMI, mtv_handle, 0, MEDIA_MTV_SERVICE_PARAM_SIM_INFO, value);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }
    return MDI_RES_MTV_SUCCEED;

}


MDI_RESULT mdi_mtv_set_net_info(U32 mtv_handle, mdi_mtv_cas_net_struct *net)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_mtv_cas_net_struct param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    param.app_id = net->app_id;
    param.net_id = net->net_id;
    param.use_proxy = net->use_proxy;
    param.prx_port = net->prx_port;
    kal_mem_cpy(param.prx_ip, net->prx_ip, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN);

    param.sg_port = net->sg_port;
    kal_mem_cpy(param.sg_url, net->sg_url, 30);

    ASSERT(mtv_handle == mdi_mtv_p->context);

    ret = media_mtv_set_param(MOD_MMI, mtv_handle, 0, MEDIA_MTV_SERVICE_PARAM_NET_INFO, (kal_uint32) &param);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }
    return MDI_RES_MTV_SUCCEED;

}


MDI_RESULT mdi_mtv_mts_test(U32 mtv_handle, mdi_mtv_mts_type_enum type, S32 service_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 param = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MDI_MTV_MTS_TYPE_GBA:
            param = MEDIA_MTV_SERVICE_PARAM_GBA;
            break;
        case MDI_MTV_MTS_TYPE_MSK_RETRIEVE:
            param = MEDIA_MTV_SERVICE_PARAM_MSK_RETRIEVE;
            break;
        default:
            ASSERT(0);
            break;
    }

    ret = media_mtv_set_param(
            MOD_MMI, mdi_mtv_p->context, service_id, param, 0);
    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }

    return MDI_RES_MTV_SUCCEED;
}

MDI_RESULT mdi_mtv_open_stand_alone_db(const U16 app_id, U32 *db_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mdi_mtv_p->block_query)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, MDI_RES_MTV_ERR_DEVICE_BUSY);
        return MDI_RES_MTV_ERR_DEVICE_BUSY;
    }

    ret = media_mtv_esg_open(
            MOD_MMI, &mdi_mtv_p->db_context, MEDIA_MTV_ESG_SOURCE_MBBMS, app_id);

    if (ret != MED_RES_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_MTV_MEDIA_RET, ret);
        return MDI_RES_MTV_FAILED;
    }


    *db_handle = mdi_mtv_p->db_context;

    return MDI_RES_MTV_SUCCEED;
}

MDI_RESULT mdi_mtv_close_stand_alone_db(U32 db_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(db_handle == mdi_mtv_p->db_context);
    ret = media_mtv_esg_close(
                MOD_MMI, mdi_mtv_p->db_context, MEDIA_MTV_ESG_SOURCE_MBBMS);
    ASSERT(ret == MED_RES_OK);

    return MDI_RES_MTV_SUCCEED;
}

#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */

#endif /* #if defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) */

