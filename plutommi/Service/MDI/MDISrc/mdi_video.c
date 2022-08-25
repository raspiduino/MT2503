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
 *  mdi_video.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access video related functions.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __MTK_TARGET__
   /*
    * - For PC Simulator and MoDis, do not call media's video functions
    * - For Target, call media's video functions.
    */
#define MDI_VIDEO_DRIVER_AVAIALBE
#endif /* __MTK_TARGET__ */

#include "lcd_if.h"             /* lcd interface */
#include "gdi_include.h"        /* include data type */
#include "gdi_lcd.h"  
#include "med_struct.h"
#include "med_api.h"            /* media task */
#include "med_main.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_video.h"
#include "mdi_camera.h"
#include "mdi_video_internal.h"


#ifdef __MMI_VIDEO_STREAM__
#include "stream_api.h"
#ifdef __MMI_STREAM_REC__
#include "FileMgrGprot.h"
#endif
#endif

#ifdef __MMI_BT_AUDIO_VIA_SCO__
#include "BthScoPathSrvGProt.h"
#endif


#include "reg_base.h"
#include "IntrCtrl.h"
#include "drv_comm.h"
#include "visualhisr.h"
#include "visual_comm.h"
#include "fat_fs.h"

#include "img_common_enum.h"
#include "image_effect_struct.h"

#ifdef __DRM_SUPPORT__
#include "Fs_errcode.h"
#include "Drm_gprot.h"
#endif /* __DRM_SUPPORT__ */

#if defined(__BTMTK__)
#include "bluetooth_control.h"
#endif

#if defined(__MMI_OP11_PDL_FROM_SDP__)
#include "sdp_msg_api.h"
#include "med_utility.h"
#endif
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
#include "gui.h"
#endif

#include "Gdi_include.h"

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
#include "subtitleFont.h"
#include "subtitlefont_if.h"
#include "lang_interface.h"
#endif /* __MMI_VIDEO_SUBTITLE_SUPPORT__ */ 

#include "CbmSrvGprot.h"
#include "cbm_api.h"
#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "stack_config.h"
#include "fs_type.h"
#include "kal_general_types.h"
#include "gdi_features.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_mdi_def.h"
#include "mmi_media_app_trc.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "kal_public_api.h"
#include "gdi_const.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "Unicodexdcl.h"
#include "drm_def.h"
#include "drm_errcode.h"
#include "mdi_audio.h"
#include "CustDataRes.h"
#include "gui_resource_type.h"
#include "mmi_frm_queue_gprot.h"
#include "custom_video_enc_if.h"
#include "drv_sw_features_video.h"

#ifdef __MM_DCM_SUPPORT__
#include "dcmgr.h"
#endif

/*****************************************************************************
* Define
*****************************************************************************/
#define MDI_VIDEO_DUMMY_TOTAL_TIME  10000
#define MDI_VIDEO_DRM_INVALID_VALUE 0xFFFFFFFF

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
#ifdef DRV_IDP_OLD_DESIGN
    #define MDI_VIDEO_COLOR_FORMAT_RGB565  IMGDMA_IBW_OUTPUT_RGB565
#else
    #define MDI_VIDEO_COLOR_FORMAT_RGB565  IMG_COLOR_FMT_RGB565
#endif
    #define MDI_VIDEO_COLOR_FORMAT_UYVY422 IMG_COLOR_FMT_PACKET_YUYV422
    #define MDI_VIDEO_COLOR_FORMAT_RGB888  IMG_COLOR_FMT_RGB888
    #define MDI_VIDEO_COLOR_FORMAT_ARGB8888 IMG_COLOR_FMT_ARGB8888
#else
    #define MDI_VIDEO_COLOR_FORMAT_RGB565  0
    #define MDI_VIDEO_COLOR_FORMAT_UYVY422 0
    #define MDI_VIDEO_COLOR_FORMAT_RGB888  0
    #define MDI_VIDEO_COLOR_FORMAT_ARGB8888 0
#endif

/*****************************************************************************
* Typedef
*****************************************************************************/

/*****************************************************************************
* Local Variable
*****************************************************************************/
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
mdi_video_context_struct g_mdi_video_cntx;
mdi_video_context_struct *mdi_video_p = &g_mdi_video_cntx;
#endif

#if defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__) || defined(__MMI_VIDEO_TELEPHONY__)
mdi_video_setting_struct *video_setting_p = &g_mdi_video_cntx.setting;
#endif

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
/* callback function */
void (*mdi_video_ply_open_file_result_callback)(MDI_RESULT, mdi_video_info_struct *, void *) = NULL;
void (*mdi_video_ply_play_finish_callback)(MDI_RESULT, void *) = NULL;
void (*mdi_video_play_seek_result_callback)(MDI_RESULT, void *) = NULL;
void (*mdi_video_get_thumbnail_result_callback)(MDI_RESULT) = NULL;
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
#ifdef __MMI_VIDEO_STREAM__
/* add for stream API */
mdi_video_stream_context_t g_mdi_stream_cntx;
mdi_video_stream_context_t *mdi_stream_p = &g_mdi_stream_cntx;

void (*mdi_video_stream_connect_result_callback)(MDI_RESULT, mdi_video_info_struct *, void *) = NULL;
void (*mdi_video_stream_buffering_result_callback)(MDI_RESULT, mdi_video_info_struct *, void *) = NULL;
void (*mdi_video_stream_play_finish_callback)(MDI_RESULT, void *) = NULL;
#ifdef __MMI_STREAM_REC__
void (*mdi_video_stream_rec_result_callback)(MDI_RESULT) = NULL;
#endif /* __MMI_STREAM_REC__ */
#endif /* __MMI_VIDEO_STREAM__ */

#if defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
extern void mdi_video_rec_save_result_hdlr(void *msg_ptr);
extern void mdi_video_rec_record_result_hdlr(void *msg_ptr);
#endif

#ifdef __MMI_VIDEO_TELEPHONY__
void (*mdi_video_tel_codec_event_callback)(mdi_video_tel_codec_event_enum, S32, void*) = NULL;
void* mdi_video_tel_codec_event_callback_data;
mdi_video_tel_context_struct g_mdi_video_tel_cntx= {FALSE, FALSE, 0, 0, 0, 0, 0, 0};
#endif


/*****************************************************************************
* Local Function
*****************************************************************************/
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
#ifdef __MM_DCM_SUPPORT__
static void mdi_video_ply_dcm_load(void);
static void mdi_video_ply_dcm_unload(void);
#endif

static void mdi_video_ply_play_finish_result_hdlr(void *msgPtr);
static void mdi_video_ply_open_file_result_hdlr(void *msgPtr);
static void mdi_video_ply_non_block_seek_result_hdlr(void *msgPtr);
static MDI_RESULT mdi_video_ply_open_internal(
                const U16 app_id,
                const CHAR *filename,
                const U8 *file_buffer,
                const U32 buffer_len,
                U16 video_id,
                mdi_video_info_struct *info);
static MDI_RESULT mdi_video_med_to_mdi_ret(S32 med_ret, MDI_RESULT *ret);
static void mdi_video_ply_init_video(mdi_video_info_struct *info);
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
static void mdi_video_ply_init_track_info(
    mdi_video_info_struct *info, mpl_player_video_track_info_t *track_p);
#endif
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
static void mdi_video_ply_init_subtitle_info(
    mdi_video_info_struct *info, mpl_player_subtitle_track_info_t *track_p);
#endif
#ifdef __DRM_SUPPORT__
static void mdi_video_ply_drm_consume_callback(S32 result, S32 id);
static void mdi_video_ply_drm_reset_state(void);
static MDI_RESULT mdi_video_ply_drm_validate(const CHAR *filename);

#endif
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

#ifdef __MMI_VIDEO_STREAM__
static void mdi_video_stream_connect_result_hdlr(void *msg_ptr);
static void mdi_video_stream_buffering_result_hdlr(void *msg_ptr);
static void mdi_video_stream_play_result_hdlr(void *msg_ptr);
#endif /* __MMI_VIDEO_STREAM__ */

#ifdef __MMI_VIDEO_TELEPHONY__
static void mdi_video_tel_codec_event_ind_hdlr(void *msg_ptr);
#endif

#ifndef MDI_VIDEO_DRIVER_AVAIALBE
/* drvier not availabe, mdi simulate non-block mechanism */
static void mdi_video_ply_dummy_play_cyclic(void);

#ifdef __MMI_VIDEO_STREAM__
static void mdi_video_stream_dummy_connect_result_hdlr(void);
static void mdi_video_stream_dummy_start_buffering_cyclic(void);
static void mdi_video_stream_dummy_play_result_hdlr(void);
static void mdi_video_stream_dummy_play_cyclic(void);
#endif /* __MMI_VIDEO_STREAM__ */

#ifdef __MMI_VIDEO_PDL__
static void mdi_video_progressive_dummy_loading_cyclic(void);
static void mdi_video_progressive_dummy_open_file_result_hdlr(void);
#endif /* __MMI_VIDEO_PDL__ */

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */


#if defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
/*****************************************************************************
* Extern Variable
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mdi_video_message_dispatcher()
 * DESCRIPTION
 *  Message dispatcher of MDI_VIDEO
 * PARAMETERS
 *  ilm_ptr : [IN]ilm pointer
 * RETURNS
 *  MDI_VIDEO consume the message or not
 * RETURN VALUES
 *  MMI_TRUE        MDI_VIDEO consumes this message
 *  MMI_FALSE       MDI_VIDEO did not consume this message
 *****************************************************************************/
MMI_BOOL mdi_video_message_dispatcher(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_p = ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(ilm_p->msg_id)
    {
    #if defined(__MMI_VIDEO_PLAY_SUPPORT__)
        case MSG_ID_MEDIA_VID_FILE_READY_IND:
            mdi_video_ply_open_file_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;
        case MSG_ID_MEDIA_VID_PLAY_FINISH_IND:
            mdi_video_ply_play_finish_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;
        case MSG_ID_MEDIA_VID_SEEK_DONE_IND:
            mdi_video_ply_non_block_seek_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;
    #endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    #if defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
        case MSG_ID_MEDIA_VID_RECORD_FINISH_IND:
            mdi_video_rec_record_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;
        case MSG_ID_MEDIA_VID_FILE_MERGE_DONE_IND:
            mdi_video_rec_save_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;
    #endif /* defined(__MMI_VIDEO_RECORDER__) */

    #if defined(__MMI_VIDEO_STREAM__)
        case MSG_ID_MEDIA_STREAM_CONNECTED_IND:
            mdi_video_stream_connect_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;
        case MSG_ID_MEDIA_STREAM_SEEK_IND:
            mdi_video_stream_buffering_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;
        case MSG_ID_MEDIA_STREAM_PLAY_IND:
            mdi_video_stream_play_result_hdlr((void*)ilm_p->local_para_ptr);
            return MMI_TRUE;
    #endif /* __MMI_VIDEO_STREAM__ */

        default:
            return MMI_FALSE;

    }

}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_enable_mimic_task
 * DESCRIPTION
 *  Mimic task, will only affect next API. Special function for JAVA use only.
 *  Even the play function is called under MMI task, it will send MOD_J2ME to
 *  driver, so the driver will send the result message to J2ME
 * PARAMETERS
 *  module_id : [IN] module id to be mimic
 * RETURNS
 *  void
 * Example
 * <code>
 *  mdi_video_enable_mimic_task(MOD_J2ME);
 *  mdi_video_ply_play(...);
 *  ...
 *  mdi_video_disable_mimic_task();
 * </code>
 *****************************************************************************/
void mdi_video_enable_mimic_task(module_type module_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->mimic_module_id = module_id;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_disable_mimic_task
 * DESCRIPTION
 *  Disable mimic task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_disable_mimic_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->mimic_module_id = MOD_NIL;
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_get_module_id
 * DESCRIPTION
 *  Get module id
 * PARAMETERS
 *  void
 * RETURNS
 *  module id
 *****************************************************************************/
module_type mdi_video_get_module_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MOD_NIL == mdi_video_p->mimic_module_id)
    {
        return stack_get_active_module_id();
    }
    else
    {
        return mdi_video_p->mimic_module_id;
    }
}
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__) */

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

/****************************************************************************
*
* Video Player
*
****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_error_info
 * DESCRIPTION
 *  To get error string id and popup type enum by error code.
 * PARAMETERS
 * error_code : [IN] Error code got from MDI APIs
 * popup_type : [OUT] Popup_type of this error_code
 * RETURNS
 *  string_id in MMI_ID_TYPE correspounding error enum.
 *****************************************************************************/
MMI_ID_TYPE mdi_video_ply_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type)
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
        case MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED:
            string_id = STR_ID_MDI_COMMON_OPEN_FAIL;
            break;
        case MDI_RES_VDOPLY_ERR_FILE_TOO_LARGE:
            string_id = STR_ID_MDI_VIDEO_PLY_FILE_TOO_LARGE;
            break;
        case MDI_RES_VDOPLY_ERR_SNAPSHOT_FAILED:
            string_id = STR_ID_MDI_VIDEO_PLY_SNAPSHOT_FAILED;
            break;
        case MDI_RES_VDOPLY_ERR_PLAY_FAILED:
            string_id = STR_ID_MDI_COMMON_PLAY_FAIL;
            break;
        case MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL:
            string_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
            break;
        case MDI_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION:
            string_id = STR_ID_MDI_COMMON_WRITE_PROTECTION;
            break;
        case MDI_RES_VDOPLY_ERR_SNAPSHOT_NO_DISK:
            string_id = STR_GLOBAL_NO_MEMORY_CARD;
            break;
            /* from filemanager */
        case MDI_RES_VDOPLY_ERR_SNAPSHOT_ROOT_DIR_FULL:
            string_id = FMGR_FS_ROOT_DIR_FULL_TEXT;
            break;
        case MDI_RES_VDOPLY_ERR_NETWORK_DISCONNECT:
        case MDI_RES_VDOPLY_ERR_NETWORK_FORBIDDEN:
        case MDI_RES_VDOPLY_ERR_STREAM_CONNECT_FAILED:
            string_id = STR_ID_MDI_VIDEO_PLY_NETWORK_CONNECT_FAILED;
            break;
        case MDI_RES_VDOPLY_ERR_STREAM_BUFFER_FAILED:
            string_id = STR_ID_MDI_VIDEO_PLY_NETWORK_BUFFER_FAILED;
            break;
        case MDI_RES_VDOPLY_ERR_INVALID_RESOULTION:
            string_id = STR_ID_MDI_VIDEO_PLY_INVALID_RESOULTION;
            break;
        case MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT:
            string_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
            break;
        case MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT:
            string_id = STR_GLOBAL_INSUFFICIENT_MEMORY;
            break;
        case MDI_RES_VDOPLY_ERR_DRM_PROHIBITED:
        case MDI_RES_VDOPLY_ERR_DRM_DURATION_USED:
            string_id = STR_GLOBAL_DRM_PROHIBITED;
            break;
        case MDI_RES_VDOPLY_ERR_SEEK_FAILED:
        case MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED:
            string_id = STR_ID_MDI_COMMON_INVALID_FILE;
            break;
        case MDI_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH:
            string_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
            break;
        case MDI_RES_VDOPLY_ERR_FAILED:
        default:
            string_id = STR_GLOBAL_ERROR;
            break;
    }
    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_init
 * DESCRIPTION
 *  To initialize mdi video player.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to initialze video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to initialze video player.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->open_seq_num = 0;
    mdi_video_p->play_seq_num = 0;
    mdi_video_p->seek_seq_num = 0;

    mdi_video_p->is_seeking = FALSE;
    mdi_video_p->is_playing = FALSE;
    mdi_video_p->is_enable_partial_display = FALSE;

    mdi_video_p->scenario = MPL_DECODER;
#ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
    mdi_video_p->frame_mode = MDI_VIDEO_FRAME_MODE_FIT_INSIDE;
#else /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */
    mdi_video_p->frame_mode = MDI_VIDEO_FRAME_MODE_STRETCH;
#endif /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */


#ifdef __DRM_SUPPORT__
    mdi_video_ply_drm_reset_state();
#endif

#ifdef __MMI_VIDEO_STREAM__
    mdi_stream_p->play_seq_num = 0;
    mdi_stream_p->connect_seq_num = 0;
    mdi_stream_p->buffering_seq_num = 0;

    mdi_stream_p->is_playing = FALSE;
    mdi_stream_p->is_enable_partial_display = FALSE;
    mdi_stream_p->is_drm_consume_count = TRUE;
    mdi_stream_p->is_drm_consume_time = TRUE;
#ifdef __DRM_SUPPORT__
    mdi_stream_p->drm_streaming_id = MDI_VIDEO_DRM_INVALID_VALUE;
#endif

    mdi_stream_p->prefer_transport = MEDIA_STREAM_RTP_CONNECT_TYPE_TCP;
    mdi_stream_p->prebuffer_time = STREAM_BUFFER_PRE_DL_LEN;

    memset(mdi_stream_p->uaprof_str, 0, MDI_VIDEO_STREAM_UAPROF_BUFF_LEN);
    memset(mdi_stream_p->uaprof_diff_str, 0, MDI_VIDEO_STREAM_UAPROF_BUFF_LEN);
    memset(mdi_stream_p->ua_str , 0, MDI_VIDEO_STREAM_UA_STR_BUFF_LEN);

#endif /* __MMI_VIDEO_STREAM__ */

    /* init shall always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}



#ifdef __DRM_SUPPORT__
static void mdi_video_ply_drm_reset_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset flag */
    mdi_video_p->is_drm_consume_count = TRUE;
    mdi_video_p->is_drm_consume_time = TRUE;
    mdi_video_p->is_drm_time_limit_stop = TRUE;
    mdi_video_p->is_drm_file = FALSE;
    mdi_video_p->drm_file_id = MDI_VIDEO_DRM_INVALID_VALUE;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_EXIT, __LINE__);
    mdi_video_p->drm_file_state = MDI_VIDEO_DRM_EXIT;
}


static void mdi_video_ply_drm_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mdi_video_p->drm_file_state == MDI_VIDEO_DRM_PAUSED)
    {
        ASSERT(mdi_video_p->drm_file_id != MDI_VIDEO_DRM_INVALID_VALUE);
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_STOP_CONSUME, __LINE__);
        DRM_stop_consume(mdi_video_p->drm_file_id);
        mdi_video_p->drm_file_id = MDI_VIDEO_DRM_INVALID_VALUE;

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_EXIT, __LINE__);
        mdi_video_p->drm_file_state = MDI_VIDEO_DRM_EXIT;
    }
    else if (mdi_video_p->drm_file_state == MDI_VIDEO_DRM_PLAY_FINISHED ||
             mdi_video_p->drm_file_state == MDI_VIDEO_DRM_PERMITTED)
    {

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_EXIT, __LINE__);
        mdi_video_p->drm_file_state = MDI_VIDEO_DRM_EXIT;
    }

    /* Reset state */
    mdi_video_ply_drm_reset_state();
}


static void mdi_video_ply_drm_consume_callback(S32 result, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_MEDIA_TRC_G4_MDI,
        MDI_TRC_VIDEO_DRM_CONSUME_CALLBACK,
        mdi_video_p->is_playing,
        mdi_video_p->drm_file_state,
        __LINE__);

    if (!mdi_video_p->is_drm_time_limit_stop)
    {
        /* do not stop when reach time limit */
        return;
    }

    /* video is playing and drm is consuming.. */
    if (mdi_video_p->is_playing &&
        mdi_video_p->drm_file_state == MDI_VIDEO_DRM_CONSUMING)
    {
        /* stop video playing */
        mdi_video_ply_stop();
        mdi_video_p->is_drm_time_limit_stop = TRUE;

        /* notfiy caller */
        if (mdi_video_ply_play_finish_callback != NULL)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_ERR_DRM_DURATION_USED, mdi_video_p->user_data);
        }
    }

}


MDI_RESULT mdi_video_ply_drm_disable_consume_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_DRM_DISABLE_CONSUME_COUNT);

    mdi_video_p->is_drm_consume_count = FALSE;

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

MDI_RESULT mdi_video_ply_drm_disable_consume_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_DRM_DISABLE_CONSUME_TIME);

    mdi_video_p->is_drm_consume_time = FALSE;

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

MDI_RESULT mdi_video_ply_drm_disable_time_limit_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_DRM_DISABLE_CONSUME_COUNT);

    mdi_video_p->is_drm_time_limit_stop = FALSE;

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

static MDI_RESULT mdi_video_ply_drm_validate(const CHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE drm_file_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->is_drm_file = FALSE;
    /* MDI is busy */
    if (mdi_video_p->drm_file_state != MDI_VIDEO_DRM_EXIT)
    {
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_OPEN_FILE, __LINE__);
    drm_file_h = DRM_open_file((PU16)filename, FS_READ_ONLY, DRM_PERMISSION_PLAY);

    if (drm_file_h > FS_NO_ERROR)
    {
        /* check if it is DRM file or not */
        if (DRM_get_object_method(drm_file_h, NULL) != DRM_METHOD_NONE)
        {
            mdi_video_p->is_drm_file = TRUE;
            MMI_TRACE(
                MMI_MEDIA_TRC_G4_MDI,
                MDI_TRC_VIDEO_DRM_CONSUME_FLAG,
                mdi_video_p->is_drm_consume_count,
                mdi_video_p->is_drm_consume_time,
                __LINE__);

            if (mdi_video_p->is_drm_consume_count)
            {
                if (DRM_validate_permission(drm_file_h, NULL, DRM_PERMISSION_PLAY))
                {
                    /* it is DRM file, and has permission */
                    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_PERMITTED, __LINE__);
                    mdi_video_p->drm_file_state = MDI_VIDEO_DRM_PERMITTED;

                    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_CLOSE_FILE, __LINE__);
                    DRM_close_file(drm_file_h);
                }
                else
                {
                    /* it is DRM file, but no rights */
                    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_CLOSE_FILE, __LINE__);
                    DRM_close_file(drm_file_h);
                    mdi_video_p->is_drm_file = FALSE;
                    return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
                }
            }
            else
            {
                MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_PERMITTED, __LINE__);
                mdi_video_p->drm_file_state = MDI_VIDEO_DRM_PERMITTED;

                MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_CLOSE_FILE, __LINE__);
                DRM_close_file(drm_file_h);
            }
        }
        else
        {
            /* not DRM file... close file handle */
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_CLOSE_FILE, __LINE__);
            DRM_close_file(drm_file_h);
        }

    }
    else if (drm_file_h == DRM_RESULT_NO_PERMISSION)
    {
        mdi_video_p->is_drm_consume_count = TRUE;
        mdi_video_p->is_drm_consume_time = TRUE;
        return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
    }
    else
    {
        mdi_video_p->is_drm_consume_count = TRUE;
        mdi_video_p->is_drm_consume_time = TRUE;
        /* open file failed */
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }
    return MDI_RES_VDOPLY_SUCCEED;
}

MDI_RESULT mdi_video_ply_drm_check_permission(const CHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE drm_file_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    drm_file_h = DRM_open_file((PU16)filename, FS_READ_ONLY, DRM_PERMISSION_PLAY);

    if (drm_file_h > FS_NO_ERROR)
    {
        /* DRM file & has no right */
        if (DRM_get_object_method(drm_file_h, NULL) != DRM_METHOD_NONE &&
            !DRM_validate_permission(drm_file_h, NULL, DRM_PERMISSION_PLAY))
        {
            /* it is DRM file, but no rights */
            DRM_close_file(drm_file_h);
            return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
        }

        DRM_close_file(drm_file_h);
    }
    else if (drm_file_h == DRM_RESULT_NO_PERMISSION)
    {
        return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }
    return MDI_RES_VDOPLY_SUCCEED;
}


static MDI_RESULT mdi_video_ply_drm_consume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL consume_drm_count = mdi_video_p->is_drm_consume_count;
    BOOL consume_drm_time = mdi_video_p->is_drm_consume_time;
    module_type module_id = mdi_video_get_module_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* reset flag first, will use local veriable as consume count flag */
    mdi_video_p->is_drm_consume_count = TRUE;
    mdi_video_p->is_drm_consume_time = TRUE;

    /* consume rights */
    if (mdi_video_p->drm_file_state == MDI_VIDEO_DRM_PERMITTED)
    {
        MMI_ASSERT(mdi_video_p->drm_file_handle != NULL);

        /* cant support only consume count right */
        if (!consume_drm_count && consume_drm_time)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_CONSUME_TIME_RIGHT, __LINE__);

            /* will only consume duration rights */
            mdi_video_p->drm_file_id = DRM_consume_timed_rights_with_module(
                                    mdi_video_p->drm_file_handle,
                                    DRM_PERMISSION_PLAY,
                                    mdi_video_ply_drm_consume_callback,
                                    module_id);

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_CONSUMING, __LINE__);
            mdi_video_p->drm_file_state = MDI_VIDEO_DRM_CONSUMING;
        }
        else if (consume_drm_count && consume_drm_time)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_CONSUME_RIGHT, __LINE__);

            /* will consume count rights and timing rights */
            mdi_video_p->drm_file_id = DRM_consume_rights_with_module(
                                    mdi_video_p->drm_file_handle,
                                    DRM_PERMISSION_PLAY,
                                    mdi_video_ply_drm_consume_callback,
                                    module_id);

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_CONSUMING, __LINE__);
            mdi_video_p->drm_file_state = MDI_VIDEO_DRM_CONSUMING;
        }
        else if (!consume_drm_count && !consume_drm_time)
        {
            /* do not consume count or time */
        }
        else
        {
            /* unsupport status */
            MMI_ASSERT(0);
        }

    }
    else if (mdi_video_p->drm_file_state == MDI_VIDEO_DRM_PLAY_FINISHED)
    {
        ASSERT(mdi_video_p->drm_file_handle != NULL);

        if (consume_drm_count || consume_drm_time)
        {
            /* play finished, need validate permission again */
            if (DRM_validate_permission(mdi_video_p->drm_file_handle, NULL, DRM_PERMISSION_PLAY))
            {
                if (!consume_drm_count && consume_drm_time)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_CONSUME_TIME_RIGHT, __LINE__);

                    /* will only consume duration rights */
                    mdi_video_p->drm_file_id = DRM_consume_timed_rights_with_module(
                                            mdi_video_p->drm_file_handle,
                                            DRM_PERMISSION_PLAY,
                                            mdi_video_ply_drm_consume_callback,
                                            module_id);

                    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_CONSUMING, __LINE__);
                    mdi_video_p->drm_file_state = MDI_VIDEO_DRM_CONSUMING;
                }
                else if (consume_drm_count && consume_drm_time)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_CONSUME_RIGHT, __LINE__);

                    /* will consume count rights and timing rights */
                    mdi_video_p->drm_file_id = DRM_consume_rights_with_module(
                                            mdi_video_p->drm_file_handle,
                                            DRM_PERMISSION_PLAY,
                                            mdi_video_ply_drm_consume_callback,
                                            module_id);

                    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_CONSUMING, __LINE__);
                    mdi_video_p->drm_file_state = MDI_VIDEO_DRM_CONSUMING;
                }
                else
                {
                    /* unsupport status */
                    MMI_ASSERT(0);
                }
            }
            else
            {
                /* it is DRM file, but no rights */
                MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_EXIT, __LINE__);
                mdi_video_p->drm_file_state = MDI_VIDEO_DRM_EXIT;
                return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
            }
        }
        else
        {
            /* do not consume anyting, keep in play finished state */
        }

    }
    else if (mdi_video_p->drm_file_state == MDI_VIDEO_DRM_PAUSED)
    {
        ASSERT(mdi_video_p->drm_file_handle != NULL);
        ASSERT(mdi_video_p->drm_file_id != MDI_VIDEO_DRM_INVALID_VALUE);

        if (!consume_drm_count)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_RESUME_CONSUME, __LINE__);
            DRM_resume_consume(mdi_video_p->drm_file_id);
        }
        else
        {
            /* stop and consume again */
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_STOP_CONSUME, __LINE__);
            DRM_stop_consume(mdi_video_p->drm_file_id);

            /* play finished, need validate permission again */
            if (DRM_validate_permission(mdi_video_p->drm_file_handle, NULL, DRM_PERMISSION_PLAY))
            {
                /* has permission, consume rights */

                MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_CONSUME_RIGHT, __LINE__);
                mdi_video_p->drm_file_id = DRM_consume_rights_with_module(
                                        mdi_video_p->drm_file_handle,
                                        DRM_PERMISSION_PLAY,
                                        mdi_video_ply_drm_consume_callback,
                                        module_id);

                MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_CONSUMING, __LINE__);
                mdi_video_p->drm_file_state = MDI_VIDEO_DRM_CONSUMING;
            }
            else
            {
                /* it is DRM file, but no rights */
                MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_EXIT, __LINE__);
                mdi_video_p->drm_file_state = MDI_VIDEO_DRM_EXIT;
                return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
            }
        }

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_CONSUMING, __LINE__);
        mdi_video_p->drm_file_state = MDI_VIDEO_DRM_CONSUMING;
    }
    else if (mdi_video_p->drm_file_state == MDI_VIDEO_DRM_EXIT &&
             mdi_video_p->is_drm_file)
    {
        return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
    }

    return MDI_RES_VDOPLY_SUCCEED;
}

#endif /* __DRM_SUPPORT__ */


static void mdi_video_ply_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->is_enable_aud_only = FALSE;
    mdi_video_p->scenario = MPL_DECODER;
#ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
    mdi_video_p->frame_mode = MDI_VIDEO_FRAME_MODE_FIT_INSIDE;
#else /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */
    mdi_video_p->frame_mode = MDI_VIDEO_FRAME_MODE_STRETCH;
#endif /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */

    mdi_video_p->is_enable_partial_display = FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_file
 * DESCRIPTION
 *  To open video file.
 * PARAMETERS
 *  filename : [IN]Videe clip's full file name
 *  open_result_callback : [IN]Open file result callback function
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to open video file, need to wait callback function when open operation is finished.
 *  MDI_RES_VDOPLY_ERR_DRM_PROHIBITED : Fail to open video file due to drm is prohibited.
 *  MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT : Fail to open video file due to memory is insufficient.
 *  MDI_RES_VDOPLY_ERR_FILE_TOO_LARGE : Fail to open video file due to file is too large.
 *  MDI_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH : Fail to open video file due to framerate is too high.
 *  MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to open video file.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_open_file(
            const U16 app_id,
            const CHAR *filename,
            mdi_open_result_callback open_result_callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_OPEN_FILE);

    mdi_video_ply_open_file_result_callback = open_result_callback;

    SetProtocolEventHandler(mdi_video_ply_open_file_result_hdlr, MSG_ID_MEDIA_VID_FILE_READY_IND);

#ifdef __DRM_SUPPORT__
    ret = mdi_video_ply_drm_validate(filename);
    if (ret != MDI_RES_VDOPLY_SUCCEED)
    {
        mdi_video_ply_reset();
        return ret;
    }
#endif /* __DRM_SUPPORT__ */

#ifdef __MM_DCM_SUPPORT__
    mdi_video_ply_dcm_load();
#endif

    ret = mdi_video_ply_open_internal(app_id, filename, NULL, 0, 0, NULL);
    if (ret == MDI_RES_VDOPLY_SUCCEED)
    {
        mdi_video_p->user_data = user_data;
    }
    else
    {
#ifdef __MM_DCM_SUPPORT__
    mdi_video_ply_dcm_unload();
#endif        
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_clip_file
 * DESCRIPTION
 *  To open video clip, this is a blocking function, will return untill file is opened.
 * PARAMETERS
 *  filename : [IN]Video clip's full file name
 *  info : [OUT]Video clip's info
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to open video file, need to wait callback function when open operation is finished.
 *  MDI_RES_VDOPLY_ERR_DRM_PROHIBITED : Fail to open video file due to drm is prohibited.
 *  MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT : Fail to open video file due to memory is insufficient.
 *  MDI_RES_VDOPLY_ERR_FILE_TOO_LARGE : Fail to open video file due to file is too large.
 *  MDI_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH : Fail to open video file due to framerate is too high.
 *  MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to open video file.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_open_clip_file(
                const U16 app_id,
                const CHAR *filename,
                mdi_video_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_OPEN_CLIP_FILE);

    if (filename == NULL)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

#ifdef __DRM_SUPPORT__
    ret = mdi_video_ply_drm_validate(filename);
    if (ret != MDI_RES_VDOPLY_SUCCEED)
    {
        mdi_video_ply_reset();
        return ret;
    }
#endif /* __DRM_SUPPORT__ */

#ifdef __MM_DCM_SUPPORT__
    mdi_video_ply_dcm_load();
#endif

    ret = mdi_video_ply_open_internal(app_id, filename, NULL, 0, 0, info);

#ifdef __MM_DCM_SUPPORT__
    if (ret != MDI_RES_VDOPLY_SUCCEED)
    {
        mdi_video_ply_dcm_unload();
    }
#endif

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_clip_id
 * DESCRIPTION
 *  To open video clip.
 * PARAMETERS
 *  video_id : [IN]Video clip resource id
 *  info : [OUT]Video clip's info
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to open video id, need to wait callback function when open operation is finished.
 *  MDI_RES_VDOPLY_ERR_DRM_PROHIBITED : Fail to open video id due to drm is prohibited.
 *  MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT : Fail to open video id due to memory is insufficient.
 *  MDI_RES_VDOPLY_ERR_FILE_TOO_LARGE : Fail to open video id due to file is too large.
 *  MDI_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH : Fail to open video id due to framerate is too high.
 *  MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to open video id.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_open_clip_id(
                const U16 app_id,
                U16 video_id,
                mdi_video_info_struct *info)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_OPEN_CLIP_ID);

    /* un-hook open file done hdlr */
    //SetProtocolEventHandler(NULL, MSG_ID_MEDIA_VID_FILE_READY_IND);

#ifdef __MM_DCM_SUPPORT__
    mdi_video_ply_dcm_load();
#endif

    ret = mdi_video_ply_open_internal(app_id, NULL, NULL, 0, video_id, info);
#ifdef __MM_DCM_SUPPORT__
    if (ret != MDI_RES_VDOPLY_SUCCEED)
    {
        mdi_video_ply_dcm_unload();
    }
#endif

    return ret;

#else /* MDI_VIDEO_DRIVER_AVAIALBE */

    info->width = 176;
    info->height = 144;
    info->total_time_duration = 30;
    info->track = MDI_VIDEO_TRACK_AV;
    mdi_video_p->track = MDI_VIDEO_TRACK_AV;

    return MDI_RES_VDOPLY_SUCCEED;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_clip_buffer
 * DESCRIPTION
 *  To open video clip from buffer.
 * PARAMETERS
 *  file_buffer : [IN]Video clip file buffer
 *  buffer_len : [IN]Video clip's buffer size
 *  info : [OUT]Video clip's info
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to open video buffer, need to wait callback function when open operation is finished.
 *  MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT : Fail to open video buffer due to memory is insufficient.
 *  MDI_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH : Fail to open video buffer due to framerate is too high.
 *  MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to open video file.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_open_clip_buffer(
            const U16 app_id,
            const U8 *file_buffer,
            const U32 buffer_len,
            mdi_video_info_struct *info)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_OPEN_CLIP_BUFFER);

    /* un-hook open file done hdlr */
    //SetProtocolEventHandler(NULL, MSG_ID_MEDIA_VID_FILE_READY_IND);
    if (file_buffer == NULL)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

#ifdef __MM_DCM_SUPPORT__
    mdi_video_ply_dcm_load();
#endif

    ret = mdi_video_ply_open_internal(app_id, NULL, file_buffer, buffer_len, 0, info);
#ifdef __MM_DCM_SUPPORT__
    if (ret != MDI_RES_VDOPLY_SUCCEED)
    {
        mdi_video_ply_dcm_unload();
    }
#endif

    return ret;

#else  /* MDI_VIDEO_DRIVER_AVAIALBE */  

    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_enable_aud_only_video_clip
 * DESCRIPTION
 *  To enable playing aud only video file
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to enable playing audio only video clip
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to enable playing audio only video clip
 *****************************************************************************/
MDI_RESULT mdi_video_ply_enable_aud_only_video_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//  MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_ENABLE_PARTIAL_DISPLAY);

    mdi_video_p->is_enable_aud_only = TRUE;

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_scenario_type
 * DESCRIPTION
 *  To set scenario type
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to enable playing audio only video clip
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to enable playing audio only video clip
 *****************************************************************************/
MDI_RESULT mdi_video_ply_set_scenario_type(mdi_video_scenario_type_enum scenario)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_SET_SCENARIO_TYPE, scenario);

    mdi_video_p->scenario = (mpl_scenario_enum)scenario;    

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_enable_partial_display
 * DESCRIPTION
 *  To enable video to play outside lcd region.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to enable partial display (outside lcd region) to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to enable partial display (outside lcd region) to video player.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_enable_partial_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_ENABLE_PARTIAL_DISPLAY);

    mdi_video_p->is_enable_partial_display = TRUE;

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_frame_mode
 * DESCRIPTION
 *  To enable video to play outside lcd region.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to enable partial display (outside lcd region) to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to enable partial display (outside lcd region) to video player.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_set_frame_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL valid = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_SET_FRAME_MODE, mode);

    mdi_video_p->frame_mode = mode;

#ifndef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
    if (mdi_video_p->frame_mode == MDI_VIDEO_FRAME_MODE_FIT_INSIDE)
    {
        valid = MMI_FALSE;
    }
#endif /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */

#ifndef __MDI_DISPLAY_FIT_OUTSIDE_SUPPORT__
    if (mdi_video_p->frame_mode == MDI_VIDEO_FRAME_MODE_FIT_OUTSIDE)
    {
        valid = MMI_FALSE;
    }
#endif /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */

    if (!valid)
    {
        mdi_video_p->frame_mode = MDI_VIDEO_FRAME_MODE_STRETCH;
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, MDI_RES_VDOPLY_ERR_FAILED);
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_is_drm_file
 * DESCRIPTION
 *  Check if it is drm file or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : It is a drm file.
 *  MMI_FALSE : It is not a drm file.
 *****************************************************************************/
MMI_BOOL mdi_video_ply_is_drm_file(void)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)mdi_video_p->is_drm_file;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_check_is_able_to_play
 * DESCRIPTION
 *  Check is able to play or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : This file is able to play.
 *  MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT : This file is not able to play due to memory is not enough.
 *  MDI_RES_VDOPLY_ERR_FAILED : This file is not able to play.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_check_is_able_to_play(CHAR *file_name)
{
#if defined (MDI_VIDEO_DRIVER_AVAIALBE) && !defined(__MED_IN_ASM__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    media_vid_check_med_ready_req_struct data;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = media_vid_check_med_ready(module_id, &data);

    if (ret == MED_RES_MEM_INSUFFICIENT)
    {
        return MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT;
    }
    else if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

}


MDI_RESULT mdi_video_ply_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_CLOSE);

    mdi_video_p->open_seq_num++;

    media_vid_close(module_id);

#ifdef __MM_DCM_SUPPORT__        
    mdi_video_ply_dcm_unload();        
#endif

    /* close file shall always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


MDI_RESULT mdi_video_ply_close_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __DRM_SUPPORT__
    mdi_video_ply_drm_reset();
#endif /* __DRM_SUPPORT__ */

    return mdi_video_ply_close();

}


U32 mdi_video_ply_get_default_frame_color_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MDI_DISPLAY_RGB565_SUPPORT__
    /* Avoid contour. Always use RGB565 to get frame */
    return GDI_COLOR_FORMAT_16;
#else
    return GDI_COLOR_FORMAT_UYVY422;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_open_file_result_hdlr
 * DESCRIPTION
 *  record result message hdlr
 * PARAMETERS
 *  msgPtr          [?]
 *  msg_ptr(?)      [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_ply_open_file_result_hdlr(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_info_struct vdo_clip;
    media_vid_file_ready_ind_struct *ind_p;
    module_type module_id;
    MDI_RESULT ret, mdi_ret, error_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_OPEN_FILE_RESULT_HDLR);

    ind_p = (media_vid_file_ready_ind_struct*) msgPtr;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);

    memset(&vdo_clip, 0, sizeof(mdi_video_info_struct));

    if (ind_p->seq_num != mdi_video_p->open_seq_num)
    {
        /*
         * this case will happened when meida already send out file_ready_ind_msg,
         * but before MDI receive this msg, MDI already ask media to close file.
         * So the seq_num cant match.
         */
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);
        return;
    }

    /* get module id after checking seq num */
    module_id = mdi_video_get_module_id();

    if (ind_p->result == MED_RES_OK ||
        ind_p->result == MED_RES_MP4_NO_VIDEO_TRACK)
    {

        if(ind_p->result == MED_RES_MP4_NO_VIDEO_TRACK)
        {
            vdo_clip.width = 10;
            vdo_clip.height = 10;
            vdo_clip.track = MDI_VIDEO_TRACK_A_ONLY;
            mdi_video_p->track = MDI_VIDEO_TRACK_A_ONLY;
        }
        else
        {
            vdo_clip.width = ind_p->image_width;
            vdo_clip.height = ind_p->image_height;
            vdo_clip.track = MDI_VIDEO_TRACK_AV;
            mdi_video_p->track = MDI_VIDEO_TRACK_AV;
        }
        //vdo_clip.handle = ind_p->handle;
        vdo_clip.is_seekable = ind_p->is_seekable;
    #ifdef __MMI_VIDEO_CLIPPER__
        vdo_clip.is_proprietary = ind_p->is_proprietary;
    #endif
    #ifdef __DRM_SUPPORT__
        vdo_clip.drm_handle = ind_p->file_handle;
        mdi_video_p->drm_file_handle = ind_p->file_handle;
    #endif

        mdi_video_ply_init_video(&vdo_clip);
    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
        vdo_clip.track_num = ind_p->track_num;
        mdi_video_ply_init_track_info(&vdo_clip, ind_p->track_info);
    #endif
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
        vdo_clip.subtitle_num = ind_p->subtitle_num;
        mdi_video_ply_init_subtitle_info(&vdo_clip, ind_p->subtitle_info);
    #endif
        /* get aud profile */
        media_vid_get_audio_profile(module_id, &vdo_clip.aud_channel_no, &vdo_clip.aud_sample_rate);

        vdo_clip.total_time_duration = ind_p->total_time;

        mdi_video_ply_open_file_result_callback(MDI_RES_VDOPLY_SUCCEED, &vdo_clip, mdi_video_p->user_data);
    }
    else
    {
        vdo_clip.width = 0;
        vdo_clip.height = 0;
        vdo_clip.total_time_duration = 0;
        vdo_clip.track = MDI_VIDEO_TRACK_AV;
        vdo_clip.is_seekable = MMI_FALSE;
    #ifdef __MMI_VIDEO_CLIPPER__
        vdo_clip.is_proprietary = MMI_FALSE;
    #endif
        mdi_video_p->track = MDI_VIDEO_TRACK_AV;
    #ifdef __DRM_SUPPORT__
        mdi_video_p->is_drm_consume_count = TRUE;
        mdi_video_p->is_drm_consume_time = TRUE;
    #endif

        mdi_ret = mdi_video_med_to_mdi_ret(ind_p->result, &error_ret);
        if (mdi_ret == MDI_RES_VDOPLY_SUCCEED)
        {
            ret = error_ret;
        }
        else
        {
            ret = MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;  
        }

        mdi_video_ply_open_file_result_callback(ret, &vdo_clip, mdi_video_p->user_data);
    #ifdef __MM_DCM_SUPPORT__
        if (ret != MDI_RES_VDOPLY_SUCCEED)
        {
            mdi_video_ply_dcm_unload();
        }
    #endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_is_playing
 * DESCRIPTION
 *  To check video is currently playing or not
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : Video is playing now.
 *  MMI_FALSE : Video is not playing now.
 *****************************************************************************/
BOOL mdi_video_is_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_STREAM__
    return (mdi_video_p->is_playing || mdi_stream_p->is_playing);
#else
    return mdi_video_p->is_playing;
#endif /* __MMI_VIDEO_STREAM__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_media_type
 * DESCRIPTION
 *  To get media type
 * PARAMETERS
 *  filename : [IN]Videe clip's full file name
 * RETURN VALUES
 *  med_type_enum
 ****************************************************************************/
med_type_enum mdi_video_ply_get_media_type(const CHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *dot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dot = mmi_wcsrchr((WCHAR *)filename, L'.');

    if (dot != NULL)
    {
        if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".3GP") == 0)
        {
            return MED_TYPE_3GP;
        }
        else if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".MP4") == 0)
        {
            return MED_TYPE_MP4;
        }
    #ifdef __RM_DEC_SUPPORT__
        else if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".RMVB") == 0)
        {
            return MED_TYPE_RMVB;
        }
        else if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".RM") == 0)
        {
            return MED_TYPE_RM;
        }
        else if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".RV") == 0)
        {
            return MED_TYPE_RV;
        }
    #endif /* __RM_DEC_SUPPORT__ */
    #ifdef MJPG_DECODE
        else if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".AVI") == 0)
        {
            return MED_TYPE_MJPG;
        }
    #endif /* __RM_DEC_SUPPORT__ */
    #ifdef __FLV_FILE_FORMAT_SUPPORT__
        else if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".flv") == 0)
        {
            return MED_TYPE_FLV;
        }
        else if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".f4v") == 0)
        {
            return MED_TYPE_F4V;
        }
    #endif /* __FLV_FILE_FORMAT_SUPPORT__ */
    #ifdef __MKV_FILE_FORMAT_SUPPORT__
        else if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".mkv") == 0)
        {
            return MED_TYPE_MKV;
        }
        else if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".webm") == 0)
        {
            return MED_TYPE_MKV;
        }
    #ifdef __VIDEO_3D_SIDE_BY_SIDE__
        else if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".mk3d") == 0)
        {
            return MED_TYPE_MKV;
        }
    #endif
    #endif /* __MKV_FILE_FORMAT_SUPPORT__ */
    #ifdef __MOT_SUPPORT__
        else if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".mot") == 0)
        {
            return MED_TYPE_MOT;
        }
    #endif
    #ifdef PGDL_SUPPORT_YOUTUBE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* PGDL_SUPPORT_YOUTUBE */
    #ifdef __KMV_SUPPORT__
        else if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".kmv") == 0)
        {
            return MED_TYPE_KMV;
        }
        else if (mmi_ucs2icmp((CHAR*)dot, (CHAR*)L".qkmv") == 0)
        {
            return MED_TYPE_KMV;
        }
    #endif
    }

    /* Default type */
    return MED_TYPE_3GP;
}


#ifdef __MM_DCM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_
 * DESCRIPTION
 *  This function is to load DCM
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_ply_dcm_load(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DCM_Load(DYNAMIC_CODE_COMPRESS_MDIVID, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_dcm_unload
 * DESCRIPTION
 *  This function is to unload DCM
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_ply_dcm_unload(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DCM_Unload(DYNAMIC_CODE_COMPRESS_MDIVID);
}

#pragma arm section code = "DYNAMIC_CODE_MDIVID_ROCODE", rodata = "DYNAMIC_CODE_MDIVID_RODATA"

#endif



/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_snapshot
 * DESCRIPTION
 *  To snapshot video and save as jpeg file.
 * PARAMETERS
 *  layer_handle : [IN]Video play layer.
 *  file_name : [IN]Filename for jpeg.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to snapshot.
 *  MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL : Fail to snapshot due to disk is full.
 *  MDI_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION : Fail to snapshot due to the disk is in write protection mode.
 *  MDI_RES_VDOPLY_ERR_SNAPSHOT_FAILED : Fail to snapshot.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_snapshot(gdi_handle layer_handle, CHAR *file_name)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT gdi_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_ret = gdi_image_encode_layer_to_jpeg(layer_handle, file_name);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, gdi_ret);

    if (gdi_ret == GDI_SUCCEED)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else if (gdi_ret == GDI_IMAGE_ENCODER_ERR_DISK_FULL)
    {
        return MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL;
    }
    else if (gdi_ret == GDI_IMAGE_ENCODER_ERR_WRITE_PROTECTION)
    {
        return MDI_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_SNAPSHOT_FAILED;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_prepare_param
 * DESCRIPTION
 *
 * PARAMETERS
 *
 *****************************************************************************/
static void mdi_video_ply_reset_hw_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mdi_video_p->is_lcd_update == TRUE &&
        mdi_video_p->track != MDI_VIDEO_TRACK_A_ONLY)
    {
        gdi_lcd_set_hw_update(KAL_FALSE);
        mdi_video_p->is_lcd_update = KAL_FALSE;
    }

#ifdef __MMI_SUBLCD__
    if (mdi_video_p->lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        /* un-freeze sublcd */
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_freeze(FALSE);
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    }
    else if (mdi_video_p->lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        /* un-freeze mainlcd */
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        gdi_lcd_freeze(FALSE);
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    }
#endif /* __MMI_SUBLCD__ */
}


static U8 mdi_video_ply_get_color_format(gdi_color_format color_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (color_format)
    {
        case GDI_COLOR_FORMAT_16:
            return MDI_VIDEO_COLOR_FORMAT_RGB565;
        case GDI_COLOR_FORMAT_UYVY422:
            return MDI_VIDEO_COLOR_FORMAT_UYVY422;
    #ifdef __MDI_DISPLAY_RGB888_SUPPORT__        
        case GDI_COLOR_FORMAT_24:
            return MDI_VIDEO_COLOR_FORMAT_RGB888;
    #endif /* __MDI_DISPLAY_RGB888_SUPPORT__ */ 
        case GDI_COLOR_FORMAT_32:
            return MDI_VIDEO_COLOR_FORMAT_ARGB8888;
        default:
            return MDI_VIDEO_COLOR_FORMAT_RGB565;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_prepare_param
 * DESCRIPTION
 *
 * PARAMETERS
 *
 *****************************************************************************/
static MDI_RESULT mdi_video_ply_prepare_param(
            gdi_handle player_layer_handle,
            gdi_handle subtitle_layer_handle,
            U32 blt_layer_flag,
            U32 play_layer_flag,
            U32 subtitle_layer_flag,
            BOOL is_visual_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    gdi_color_format format;
    U8 *buf_ptr;
    U8 rotate;
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&mdi_video_p->play_data, 0, sizeof(media_vid_play_req_struct));

    /* set display lcd */
    gdi_lcd_get_active(&mdi_video_p->lcd_handle);

    /* call this function before calling mdi_calc_blt_para() */
    mdi_video_p->hw_update_layer_handle = player_layer_handle;
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__    
    mdi_video_p->subtitle_layer_handle = subtitle_layer_handle;
#endif

    if (mdi_video_p->lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        mdi_video_p->play_data.lcd_id = MAIN_LCD;

    #ifdef __MMI_SUBLCD__
        if (is_visual_update)
        {
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_lcd_freeze(TRUE);
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        }
    #endif /* __MMI_SUBLCD__ */
    }
    else if (mdi_video_p->lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        mdi_video_p->play_data.lcd_id = SUB_LCD;

        if (is_visual_update)
        {
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
            gdi_lcd_freeze(TRUE);
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        }
    }
    else
    {
        MMI_ASSERT(0);
    }

    mdi_video_p->is_lcd_update = is_visual_update;
    if (is_visual_update && mdi_video_p->track != MDI_VIDEO_TRACK_A_ONLY)
    {
        mdi_video_p->play_data.display_device = MED_DISPLAY_TO_MAIN_LCD;
    }
    else
    {
        mdi_video_p->play_data.display_device = MED_DISPLAY_NONE;
    }

    if (player_layer_handle == GDI_NULL_HANDLE || mdi_video_p->track == MDI_VIDEO_TRACK_A_ONLY)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }   
    
    
    gdi_layer_push_and_set_active(player_layer_handle);
    gdi_lcd_lock_mutex(); 
    gdi_waiting_blt_finish();
    
    gdi_layer_get_color_format(&format);
    gdi_layer_get_dimension(&width, &height);
    gdi_layer_get_buffer_ptr(&buf_ptr);

#ifdef __MTK_TARGET__

#ifdef __MDI_DISPLAY_YUYV422_SUPPORT__
    if (format == GDI_COLOR_FORMAT_16)
    {
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_UYVY422);
        mdi_util_convert_color_format(
            player_layer_handle, GDI_COLOR_FORMAT_16, GDI_COLOR_FORMAT_UYVY422);
        format = GDI_COLOR_FORMAT_UYVY422;
    }
#endif /* __MDI_DISPLAY_YUYV422_SUPPORT__ */

#else /* __MTK_TARGET__ */

    if (format == GDI_COLOR_FORMAT_UYVY422)
    {
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
        mdi_util_convert_color_format(
            player_layer_handle, GDI_COLOR_FORMAT_UYVY422, GDI_COLOR_FORMAT_16);
        format = GDI_COLOR_FORMAT_16;
    }
    
#endif /* __MTK_TARGET__ */

    mdi_video_p->play_data.display_width = width;
    mdi_video_p->play_data.display_height = height;
    mdi_video_p->play_data.image_buffer_p = (void*)buf_ptr;
    mdi_video_p->play_data.force_lcd_hw_trigger = (kal_bool)mdi_video_p->is_enable_partial_display;

    mdi_video_p->play_data.frame_mode = (med_frame_enum)mdi_video_p->frame_mode;
    mdi_video_p->play_data.image_data_format = mdi_video_ply_get_color_format(format);

    gdi_layer_get_blt_layer_flag(&(mdi_video_p->play_data.update_layer));
    ASSERT(mdi_video_p->play_data.update_layer>0);
    mdi_video_p->play_data.hw_update_layer = play_layer_flag;

    gdi_layer_get_actual_rotate_value(player_layer_handle, &rotate);
    switch (rotate)
    {
        case GDI_LAYER_ROTATE_0:
            mdi_video_p->play_data.idp_rotate = 0;
            break;

        case GDI_LAYER_ROTATE_90:
            mdi_video_p->play_data.idp_rotate = 90;
            break;

        case GDI_LAYER_ROTATE_180:
            mdi_video_p->play_data.idp_rotate = 180;
            break;

        case GDI_LAYER_ROTATE_270:
            mdi_video_p->play_data.idp_rotate = 270;
            break;

        default:
            MMI_ASSERT(0);
    }

    /* set_blt_layer_previous() should put before set_hw_update() */
    gdi_layer_set_blt_layer_previous();

    if (is_visual_update && mdi_video_p->track != MDI_VIDEO_TRACK_A_ONLY)
    {
        gdi_layer_set_hw_update_layer(mdi_video_p->hw_update_layer_handle, KAL_TRUE);
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
        if (mdi_video_p->subtitle_layer_handle)
        {
            gdi_layer_set_hw_update_layer(mdi_video_p->subtitle_layer_handle, KAL_TRUE);
        }
    #endif /*  __MMI_VIDEO_SUBTITLE_SUPPORT__ */
        gdi_lcd_set_hw_update(KAL_TRUE);
    }

    gdi_lcd_unlock_mutex();
    gdi_layer_pop_and_restore_active();

    gdi_layer_get_layer_element(
        play_layer_flag,
        &mdi_video_p->play_data.layer_element,
        &mdi_video_p->play_data.blt_ctx,
        &mdi_video_p->play_data.blt_dev);

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    if (mdi_video_p->subtitle_layer_handle)
    {
        gdi_layer_push_and_set_active(subtitle_layer_handle);        
        gdi_layer_get_color_format(&format);
        gdi_layer_get_dimension(&width, &height);
        gdi_layer_get_buffer_ptr(&buf_ptr);
        gdi_layer_pop_and_restore_active();

        mdi_video_p->play_data.subtitle_width = width;
        mdi_video_p->play_data.subtitle_height = height;
        mdi_video_p->play_data.subtitle_buffer_p = (void*)buf_ptr;        
        mdi_video_p->play_data.subtitle_data_format = mdi_video_ply_get_color_format(format);

        gdi_layer_get_layer_element(
            subtitle_layer_flag,
            &mdi_video_p->play_data.subtitle_layer_element,
            &mdi_video_p->play_data.subtitle_blt_ctx,
            &mdi_video_p->play_data.subtitle_blt_dev);
    }
#endif /* __MMI_VIDEO_SUBTITLE_SUPPORT__ */   

#ifdef __GAIN_TABLE_SUPPORT__
    mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_VIDEO_PLAYBACK, (void*)mdi_video_p->media_type);
#endif /*__GAIN_TABLE_SUPPORT__ */

    return MDI_RES_VDOPLY_SUCCEED;
}


void mdi_video_ply_get_default_play_setting(mdi_video_play_struct *play)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(play, 0, sizeof(mdi_video_play_struct));
}


MDI_RESULT mdi_video_ply_play_ex(mdi_video_play_struct *play)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();
    MMI_BOOL is_hw_layer = MMI_FALSE;
    MMI_BOOL is_lcd_updated;
    MDI_RESULT error_ret, mdi_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_PLAY);

    if (mdi_audio_is_speech_mode() && play->is_play_audio)
    {
        /* in speech mode, and will play audio, return error due to resource conflict */
        return MDI_RES_VDOPLY_ERR_PLAY_FAILED;
    }

    if (!mdi_video_p->is_seek_after_open)
    {
        return MDI_RES_VDOPLY_ERR_PLAY_FAILED;
    }
    ret = MED_RES_FAIL;

#ifdef __DRM_SUPPORT__
    ret = mdi_video_ply_drm_consume();
    if (ret != MDI_RES_VDOPLY_SUCCEED)
    {
        return ret;
    }
#endif /* __DRM_SUPPORT__ */


    /* after open, need seek before start play */

    mdi_video_ply_play_finish_callback = play->play_finish_callback;

    SetProtocolEventHandler(mdi_video_ply_play_finish_result_hdlr, MSG_ID_MEDIA_VID_PLAY_FINISH_IND);

    gdi_layer_is_hw_update_layer(play->player_layer_handle, &is_hw_layer);

    mdi_video_ply_prepare_param(
            play->player_layer_handle,
            play->subtitle_layer_handle,
            play->blt_layer_flag,
            play->play_layer_flag,
            play->subtitle_layer_flag,
            play->is_visual_update);

    mdi_video_p->play_data.play_audio = play->is_play_audio;
    mdi_video_p->play_data.play_speed = play->play_speed;
    mdi_video_p->play_data.audio_path = play->audio_path;
    mdi_video_p->play_data.seq_num = mdi_video_p->play_seq_num;

    /* speed */
    /*
     * driver only support audio time stretch at speed
     * 50, 80, 125, 160
     * We will do remapping
     * 50  -> 50
     * 75  -> 80
     * 125 -> 125
     * 150 -> 160
     */
    if (mdi_video_p->play_data.play_speed == 75)
    {
        mdi_video_p->play_data.play_speed = 80;
    }

    if (mdi_video_p->play_data.play_speed == 150)
    {
        mdi_video_p->play_data.play_speed = 160;
    }

    if (play->repeat_count == 0)
    {
        /* inifinte */
        mdi_video_p->repeat_count = 0xFFFF;
    }
    else
    {
        mdi_video_p->repeat_count = play->repeat_count - 1;
    }

    /* driver only play once, repeat will done in MDI */
    mdi_video_p->play_data.repeats = 1;

    if (play->is_play_audio)
    {
    #if defined(__MDI_VIDEO_DISABLE_AUDIO_VIA_SCO__)
        srv_btsco_disable_sco_connection((U8)SRV_BT_SCO_INT_VIDEO);
    #elif  defined(__MMI_BT_AUDIO_VIA_SCO__)
        /* Connect SCO to output audio to BT earpone */
        srv_btsco_connect_audio_via_sco();
    #endif
    }

    ret = media_vid_play(module_id, &mdi_video_p->play_data);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    if (ret != MED_RES_OK)
    {   

        mdi_video_ply_reset_hw_update();

        /* render doesn't run */
        is_lcd_updated = media_vid_get_is_lcd_updated();

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_UPDATE_INFO, is_hw_layer, is_lcd_updated);
        if (!is_hw_layer && !is_lcd_updated)
        {
            gdi_layer_set_hw_update_layer(play->player_layer_handle, KAL_FALSE);
        #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
            if (play->subtitle_layer_handle)
            {    
                gdi_layer_set_hw_update_layer(play->subtitle_layer_handle, KAL_FALSE);
            } 
        #endif /* __MMI_VIDEO_SUBTITLE_SUPPORT__ */  
        }
        
    #ifdef __DRM_SUPPORT__
        /* pause consume */
        if (mdi_video_p->drm_file_state == MDI_VIDEO_DRM_CONSUMING)
        {
            ASSERT(mdi_video_p->drm_file_id != MDI_VIDEO_DRM_INVALID_VALUE);

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_PAUSE_CONSUME, __LINE__);
            DRM_pause_consume(mdi_video_p->drm_file_id);

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_PAUSED, __LINE__);
            mdi_video_p->drm_file_state = MDI_VIDEO_DRM_PAUSED;
        }
    #endif /* __DRM_SUPPORT__ */

    #if defined(__MDI_VIDEO_DISABLE_AUDIO_VIA_SCO__)
        srv_btsco_enable_sco_connection((U8)SRV_BT_SCO_INT_VIDEO);
    #endif

        mdi_video_p->hw_update_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
        mdi_video_p->subtitle_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    #endif
        mdi_ret = mdi_video_med_to_mdi_ret(ret, &error_ret);
        if (mdi_ret == MDI_RES_VDOPLY_SUCCEED)
        {
            return error_ret;
        }
        else
        {
            return MDI_RES_VDOPLY_ERR_PLAY_FAILED;
        }
    }
    mdi_video_p->user_data = play->user_data;
    mdi_video_p->is_playing = TRUE;
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
    gui_start_timer(100, mdi_video_ply_dummy_play_cyclic);
#endif

    return MDI_RES_VDOPLY_SUCCEED;

}

MDI_RESULT mdi_video_ply_play(
            gdi_handle player_layer_handle,
            U32 blt_layer_flag,
            U32 play_layer_flag,
            U16 repeat_count,
            BOOL is_visual_update,
            BOOL is_play_audio,
            U8 audio_path,
            U16 rotate,
            S16 play_speed,
            mdi_play_finish_callback play_finish_callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_play_struct play = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mdi_video_ply_get_default_play_setting(&play);
    
    play.player_layer_handle = player_layer_handle;
    play.subtitle_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    play.blt_layer_flag = blt_layer_flag;
    play.play_layer_flag = play_layer_flag;
    play.subtitle_layer_flag = 0;
    play.repeat_count = repeat_count;
    play.is_visual_update = (MMI_BOOL)is_visual_update;
    play.is_play_audio = (MMI_BOOL)is_play_audio;
    play.audio_path = audio_path;
    play.rotate = rotate;
    play.play_speed = play_speed;
    play.play_finish_callback = play_finish_callback;
    play.user_data = user_data;
    
    return mdi_video_ply_play_ex(&play);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_stop
 * DESCRIPTION
 *  To stop video playing.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to stop player.
 *  MDI_RES_VDOPLY_ALREADY_FINISHED : Fail to stop player due to it is already stopped.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    S32 ret = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_STOP);

    if (mdi_video_p->is_playing == TRUE)
    {
        mdi_video_p->is_playing = FALSE;
        mdi_video_p->play_seq_num++;

        ret = media_vid_stop(module_id);
    }

    mdi_video_ply_reset_hw_update();

#ifndef MDI_VIDEO_DRIVER_AVAIALBE
    gui_cancel_timer(mdi_video_ply_dummy_play_cyclic);
#endif

#ifdef __DRM_SUPPORT__
    /* pause consume */
    if (mdi_video_p->drm_file_state == MDI_VIDEO_DRM_CONSUMING)
    {
        ASSERT(mdi_video_p->drm_file_id != MDI_VIDEO_DRM_INVALID_VALUE);

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_PAUSE_CONSUME, __LINE__);
        DRM_pause_consume(mdi_video_p->drm_file_id);

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_PAUSED, __LINE__);
        mdi_video_p->drm_file_state = MDI_VIDEO_DRM_PAUSED;

        mdi_video_p->is_drm_time_limit_stop = TRUE;
    }
#endif /* __DRM_SUPPORT__ */

#if defined(__MDI_VIDEO_DISABLE_AUDIO_VIA_SCO__)
    srv_btsco_enable_sco_connection((U8)SRV_BT_SCO_INT_VIDEO);
#endif

    mdi_video_p->hw_update_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    mdi_video_p->subtitle_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#endif

    if (ret == MED_RES_VIDEO_ALREADY_STOPPED)
    {
        return MDI_RES_VDOPLY_ALREADY_FINISHED;
    }
    else
    {
        /* stop always return succeed */
        return MDI_RES_VDOPLY_SUCCEED;
    }
}


MDI_RESULT mdi_video_ply_get_frame_ex(mdi_video_get_frame_struct *frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_width;
    S32 layer_height;
    U8 *buf_ptr;
    S32 ret;
    U8 rotate;
    media_vid_get_frame_req_struct frame_data = {0};
    module_type module_id = mdi_video_get_module_id();
    gdi_color_format color_format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_GET_FRAME);
    if (mdi_video_p->track == MDI_VIDEO_TRACK_A_ONLY)
    {
        return MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED;
    }
    
    mdi_video_p->hw_update_layer_handle = frame->player_layer_handle;
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__    
    mdi_video_p->subtitle_layer_handle = frame->subtitle_layer_handle;
#endif
    gdi_layer_push_and_set_active(frame->player_layer_handle);
    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_pop_and_restore_active();

    frame_data.display_width = layer_width;
    frame_data.display_height = layer_height;
    frame_data.image_buffer_p = (void*)buf_ptr;
    frame_data.frame_mode = (med_frame_enum)mdi_video_p->frame_mode;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_LAYER_INFO,
        buf_ptr, layer_width, layer_height, 0);
    
    gdi_layer_get_actual_rotate_value(frame->player_layer_handle, &rotate);
    switch (rotate)
    {
        case GDI_LAYER_ROTATE_0:
            frame_data.idp_rotate = 0;
            break;

        case GDI_LAYER_ROTATE_90:
            frame_data.idp_rotate = 90;
            break;

        case GDI_LAYER_ROTATE_180:
            frame_data.idp_rotate = 180;
            break;

        case GDI_LAYER_ROTATE_270:
            frame_data.idp_rotate = 270;
            break;

        default:
            MMI_ASSERT(0);
    }

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__ 
    if (frame->subtitle_layer_handle)
    {        
        gdi_layer_push_and_set_active(frame->subtitle_layer_handle);
        gdi_layer_get_buffer_ptr(&buf_ptr);
        gdi_layer_get_dimension(&layer_width, &layer_height);
        gdi_layer_get_color_format(&color_format);        
        gdi_layer_pop_and_restore_active();
        
        frame_data.subtitle_width = layer_width;
        frame_data.subtitle_height = layer_height;
        frame_data.subtitle_buffer_p = (void*)buf_ptr;
        frame_data.image_data_format = mdi_video_ply_get_color_format(color_format);
            
        gdi_layer_set_hw_update_layer(frame->subtitle_layer_handle, KAL_FALSE);        
    }
#endif /* __MMI_VIDEO_SUBTITLE_SUPPORT__ */ 

    gdi_layer_push_and_set_active(frame->player_layer_handle);
    gdi_lcd_lock_mutex();
    gdi_waiting_blt_finish();

    gdi_layer_set_hw_update_layer(frame->player_layer_handle, KAL_FALSE);
    gdi_layer_set_blt_layer_previous();

    /* Avoid contour. Always use RGB565 to get frame */
#ifdef __MDI_DISPLAY_RGB565_SUPPORT__
    gdi_layer_get_color_format(&color_format);
    if (color_format == GDI_COLOR_FORMAT_UYVY422)
    {
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_16);
    }
#endif
    gdi_layer_clear(GDI_COLOR_BLACK);

    gdi_layer_get_color_format(&color_format);
    frame_data.image_data_format = mdi_video_ply_get_color_format(color_format);
    
    ret = media_vid_get_frame(module_id, &frame_data);

    gdi_lcd_unlock_mutex();
    gdi_layer_pop_and_restore_active();
    

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    mdi_video_p->hw_update_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__    
    mdi_video_p->subtitle_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#endif
       
    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED;
    }

    return MDI_RES_VDOPLY_SUCCEED;
}

void mdi_video_ply_get_default_get_frame_setting(mdi_video_get_frame_struct *frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(frame, 0, sizeof(mdi_video_get_frame_struct));
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_frame
 * DESCRIPTION
 *  get seek frame.
 * PARAMETERS
 *  time : [IN]Seek time stamp.
 *  player_layer_handle : [IN]Get frame on this layer.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to seek.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_get_frame(gdi_handle player_layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_get_frame_struct frame;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mdi_video_ply_get_default_get_frame_setting(&frame);
    frame.player_layer_handle = player_layer_handle;
    
    return mdi_video_ply_get_frame_ex(&frame);
}

MDI_RESULT mdi_video_ply_seek_ex(mdi_video_seek_struct *seek)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_seek_req_struct seek_data;
    S32 ret;
    module_type module_id = mdi_video_get_module_id();
    MDI_RESULT error_ret, mdi_ret;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_SEEK);
    
    SetProtocolEventHandler(mdi_video_ply_non_block_seek_result_hdlr, MSG_ID_MEDIA_VID_SEEK_DONE_IND);

    seek_data.time = seek->time;    
    seek_data.get_frame = MMI_FALSE;    
    seek_data.blocking = seek->blocking;
    seek_data.force_seek = MMI_FALSE;
    seek_data.seq_num = mdi_video_p->seek_seq_num;
    
    /* set width/height 0 as default value */
    seek_data.display_width = 0;
    seek_data.display_height = 0;
    seek_data.seek_track = MED_VID_BOTH;
    seek_data.image_data_format = MDI_VIDEO_COLOR_FORMAT_RGB565;
    seek_data.idp_rotate = 0;
    
    mdi_video_p->is_seek_after_open = FALSE;

    ret = media_vid_seek(module_id, &seek_data);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);
    
    if (ret != MED_RES_OK)
    {
        mdi_ret = mdi_video_med_to_mdi_ret(ret, &error_ret);
        if (mdi_ret == MDI_RES_VDOPLY_SUCCEED)
        {
            return error_ret;
        }
        else
        {
            return MDI_RES_VDOPLY_ERR_SEEK_FAILED;
        }
    }
    else
    {
        if (seek->blocking)
        {
            mdi_video_p->is_seek_after_open = MMI_TRUE;

            /* If get frame */
            if (seek->get_frame && mdi_video_p->track != MDI_VIDEO_TRACK_A_ONLY)
            {            
                error_ret = mdi_video_ply_get_frame_ex(&seek->frame);
                return error_ret;
            }
            return MDI_RES_VDOPLY_SUCCEED;
        }
        else
        {
            mdi_video_p->is_seeking = TRUE;
            mdi_video_p->user_data = seek->user_data; 
            mdi_video_play_seek_result_callback = seek->seek_result_callback;
            
         
            mdi_video_p->is_get_frame = seek->get_frame;        
            mdi_video_p->hw_update_layer_handle = seek->frame.player_layer_handle;
        #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
            mdi_video_p->subtitle_layer_handle = seek->frame.subtitle_layer_handle;
        #endif
        }
    }

    return MDI_RES_VDOPLY_SUCCEED;
}


void mdi_video_ply_get_default_seek_setting(mdi_video_seek_struct *seek)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(seek, 0, sizeof(mdi_video_seek_struct));
}

MDI_RESULT mdi_video_ply_seek(U64 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_seek_struct seek;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mdi_video_ply_get_default_seek_setting(&seek);
    seek.time = time;
    seek.blocking = MMI_TRUE;
    seek.get_frame = MMI_FALSE;
    
    return mdi_video_ply_seek_ex(&seek);
}


MDI_RESULT mdi_video_ply_seek_and_get_frame(U64 time, gdi_handle player_layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_seek_struct seek;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mdi_video_ply_get_default_seek_setting(&seek);
    seek.time = time;
    seek.blocking = MMI_TRUE;
    seek.get_frame = MMI_TRUE;
    seek.frame.player_layer_handle = player_layer_handle;    
    
    return mdi_video_ply_seek_ex(&seek);
}


MDI_RESULT mdi_video_ply_non_block_seek(U64 time, mdi_seek_result_callback seek_result_callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_seek_struct seek;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mdi_video_ply_get_default_seek_setting(&seek);
    seek.time = time;
    seek.blocking = MMI_FALSE;
    seek.seek_result_callback = seek_result_callback;
    seek.user_data = user_data;

    seek.get_frame = MMI_FALSE;
    
    return mdi_video_ply_seek_ex(&seek);
}


MDI_RESULT mdi_video_ply_non_block_seek_and_get_frame(
            U64 time,
            gdi_handle player_layer_handle,
            mdi_seek_result_callback seek_result_callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_seek_struct seek;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mdi_video_ply_get_default_seek_setting(&seek);
    seek.time = time;
    seek.blocking = MMI_FALSE;
    seek.seek_result_callback = seek_result_callback;
    seek.user_data = user_data;

    seek.get_frame = MMI_TRUE;
    seek.frame.player_layer_handle = player_layer_handle;
    
    return mdi_video_ply_seek_ex(&seek);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_stop_non_block_seek
 * DESCRIPTION
 *  To stop non block seeking.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to stop non-blocking seek.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to stop non-blocking seek.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_stop_non_block_seek(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_STOP_NON_BLOCK_SEEK);

    mdi_video_p->seek_seq_num++;

    if (mdi_video_p->is_seeking == TRUE)
    {
        media_vid_stop(module_id);
        mdi_video_p->is_seeking = FALSE;

        mdi_video_p->hw_update_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
        mdi_video_p->subtitle_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    #endif
    }

    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_non_block_seek_result_hdlr
 * DESCRIPTION
 *  seek result message hdlr
 * PARAMETERS
 *  msgPtr          [?]
 *  msg_ptr(?)      [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_ply_non_block_seek_result_hdlr(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_seek_done_ind_struct *ind_p;
    mdi_video_get_frame_struct frame = {0};
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_STOP_NON_BLOCK_SEEK_RESULT_HDLR);

    ind_p = (media_vid_seek_done_ind_struct*) msgPtr;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);

    if (ind_p->seq_num != mdi_video_p->seek_seq_num)
    {
        /*
         * this case will happened when meida already send out file_ready_ind_msg,
         * but before MDI receive this msg, MDI already ask media to stop seeking.
         * So the seq_num cant match.
         */
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);
        return;
    }

    mdi_video_p->is_seeking = FALSE;

    ret = MDI_RES_VDOPLY_SUCCEED;
    if (ind_p->result == MED_RES_OK &&
        mdi_video_p->is_get_frame &&
        mdi_video_p->hw_update_layer_handle != GDI_LAYER_EMPTY_HANDLE &&
        mdi_video_p->track != MDI_VIDEO_TRACK_A_ONLY)
    {
        frame.player_layer_handle = mdi_video_p->hw_update_layer_handle;
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
        frame.subtitle_layer_handle = mdi_video_p->subtitle_layer_handle;
    #endif
        ret = mdi_video_ply_get_frame_ex(&frame);
    }

    mdi_video_p->hw_update_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    mdi_video_p->subtitle_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#endif

    if (mdi_video_play_seek_result_callback != NULL)
    {
        if (ind_p->result == MED_RES_OK)
        {
            mdi_video_p->is_seek_after_open = TRUE;
            mdi_video_play_seek_result_callback(ret, mdi_video_p->user_data);
        }
        else if (ind_p->result == MED_RES_VIDEO_TRACK_ERROR)
        {
            mdi_video_p->is_seek_after_open = TRUE;
            mdi_video_play_seek_result_callback(MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR, mdi_video_p->user_data);
        }
        else if (ind_p->result == MED_RES_AUDIO_TRACK_ERROR)
        {
            mdi_video_p->is_seek_after_open = TRUE;
            mdi_video_play_seek_result_callback(MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR, mdi_video_p->user_data);
        }        
        else if (ind_p->result == MED_RES_VIDEO_UNSUPPORT_DECODE_SIZE)
        {
            mdi_video_play_seek_result_callback(MDI_RES_VDOPLY_ERR_INVALID_RESOULTION, mdi_video_p->user_data);
        }
        else if (ind_p->result == MED_RES_DECODER_NOT_SUPPORT)
        {
            mdi_video_play_seek_result_callback(MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT, mdi_video_p->user_data);
        }
        else
        {
            mdi_video_play_seek_result_callback(MDI_RES_VDOPLY_ERR_SEEK_FAILED, mdi_video_p->user_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_update_layer_pause
 * DESCRIPTION
 *  Pause for update blt parameters, special function for Java & WAP use only;
 *  This function should be pariled with mdi_video_ply_update_layer_resume().
 * EXAMPLE
 *  mdi_video_ply_update_layer_pause();
 *  ....
 *  update related GDI layer configuration
 *  ....
 *  mdi_video_ply_update_layer_resume();
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to pause to update blt layers.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to pause.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_update_layer_pause(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_pause_visual_update_req_struct pause_data;
    MDI_RESULT ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_UPDATE_LAYER_PAUSE);
    ret = media_vid_pause_visual_update(module_id, &pause_data);


    mdi_video_ply_reset_hw_update();

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

    return MDI_RES_VDOPLY_SUCCEED;
}

MDI_RESULT mdi_video_ply_update_layer_resume_ex(mdi_video_update_layer_resume_struct *resume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_UPDATE_LAYER_RESUME);

    mdi_video_ply_prepare_param(
            resume->player_layer_handle,
            resume->subtitle_layer_handle,
            resume->blt_layer_flag,
            resume->play_layer_flag,
            resume->subtitle_layer_flag,
            resume->is_visual_update);

    ret = media_vid_resume_visual_update(module_id, &mdi_video_p->play_data);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    if (ret != MED_RES_OK)
    {
        mdi_video_ply_reset_hw_update();

        return MDI_RES_VDOPLY_ERR_PLAY_FAILED;
    }

    return MDI_RES_VDOPLY_SUCCEED;
}

void mdi_video_ply_get_default_resume_setting(mdi_video_update_layer_resume_struct *resume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(resume, 0, sizeof(mdi_video_update_layer_resume_struct));
}


MDI_RESULT mdi_video_ply_update_layer_resume(
            gdi_handle player_layer_handle,
            U32 blt_layer_flag,
            U32 play_layer_flag,
            BOOL is_visual_update,
            U16 rotate) /* Remove */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_update_layer_resume_struct resume = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    mdi_video_ply_get_default_resume_setting(&resume);

    resume.player_layer_handle = player_layer_handle;
    resume.blt_layer_flag = blt_layer_flag;
    resume.play_layer_flag = play_layer_flag;
    resume.is_visual_update = is_visual_update;
    resume.rotate = rotate;

    return mdi_video_ply_update_layer_resume_ex(&resume);
    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_cur_play_time
 * DESCRIPTION
 *  To get current play time.
 * PARAMETERS
 *  cur_play_time : [OUT]Current play time.
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_ply_get_cur_play_time(U64 *cur_play_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_GET_CUR_PLAY_TIME);

    media_vid_get_current_play_time(module_id, cur_play_time);

    {
        U32 cur_time = (U32)*cur_play_time;
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_CUR_TIME, (U32)cur_time);
    }
#else
    w32_Video_GetCurrentPosition(cur_play_time);

    *cur_play_time /= 10000;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_play_handle_play_finish
 * DESCRIPTION
 *  play finish result message handler
 * PARAMETERS
 *  msgPtr      [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mdi_video_ply_play_handle_play_finish(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_play_finish_ind_struct *ind_p;
    media_vid_seek_req_struct seek_data;
    module_type module_id = mdi_video_get_module_id();
    U32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ind_p = (media_vid_play_finish_ind_struct*) msgPtr;

    
    if (mdi_video_p->repeat_count > 0 && ind_p->result == MED_RES_OK)
    {
        /*
         * For H.264, it always need to seek before play, so we move repeat from MED to MDI
         */
        mdi_video_ply_reset_hw_update();
        
        mdi_video_p->repeat_count--;

        memset((void*)&seek_data, 0, sizeof(media_vid_seek_req_struct));

        seek_data.time = 0;
        seek_data.get_frame = FALSE;
        seek_data.blocking = TRUE;
        seek_data.seq_num = 0;
        seek_data.force_seek = KAL_FALSE;
        seek_data.seek_track = MED_VID_BOTH;

        ret = media_vid_seek(module_id, &seek_data);
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

        if (ret == MED_RES_OK)
        {
            if (mdi_video_p->track != MDI_VIDEO_TRACK_A_ONLY)
            {
                gdi_lcd_set_hw_update(KAL_TRUE);
                mdi_video_p->is_lcd_update = MMI_TRUE;
            }
            
            ret = media_vid_play(module_id, &mdi_video_p->play_data);
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

            if (ret == MED_RES_OK)
            {
                return MMI_FALSE;
            }
        }
        else
        {
            mdi_video_p->is_seek_after_open = FALSE;
        }

    }

    mdi_video_ply_reset_hw_update();

    mdi_video_p->is_playing = FALSE;

#ifndef MDI_VIDEO_DRIVER_AVAIALBE
    gui_cancel_timer(mdi_video_ply_dummy_play_cyclic);
#endif


#ifdef __DRM_SUPPORT__
    ASSERT(mdi_video_p->drm_file_state == MDI_VIDEO_DRM_CONSUMING ||
           mdi_video_p->drm_file_state == MDI_VIDEO_DRM_EXIT ||
           mdi_video_p->drm_file_state == MDI_VIDEO_DRM_PLAY_FINISHED ||
           mdi_video_p->drm_file_state == MDI_VIDEO_DRM_PERMITTED);

    /* stop consume */
    if (mdi_video_p->drm_file_state == MDI_VIDEO_DRM_CONSUMING)
    {
        ASSERT(mdi_video_p->drm_file_id != MDI_VIDEO_DRM_INVALID_VALUE);
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_STOP_CONSUME, __LINE__);
        DRM_stop_consume(mdi_video_p->drm_file_id);
        mdi_video_p->drm_file_id = MDI_VIDEO_DRM_INVALID_VALUE;

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_PLAY_FINISHED, __LINE__);
        mdi_video_p->drm_file_state = MDI_VIDEO_DRM_PLAY_FINISHED;

        mdi_video_p->is_drm_time_limit_stop = TRUE;
    }
#endif /* __DRM_SUPPORT__ */


#if defined(__MDI_VIDEO_DISABLE_AUDIO_VIA_SCO__)
    srv_btsco_enable_sco_connection((U8)SRV_BT_SCO_INT_VIDEO);
#endif

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_play_finish_result_hdlr
 * DESCRIPTION
 *  play finish result message handler
 * PARAMETERS
 *  msgPtr      [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_ply_play_finish_result_hdlr(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_play_finish_ind_struct *ind_p;
    module_type module_id = mdi_video_get_module_id();
    MMI_BOOL handle_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_PLAY_FINISH_RESULT_HDLR);

    ind_p = (media_vid_play_finish_ind_struct*) msgPtr;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);

    /* seq number not match, measn it is already stopped, ignore this message */
    if (mdi_video_p->play_seq_num != ind_p->seq_num)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);
        return;
    }

    /* Player is still playing */
    if (ind_p->result != MED_RES_VIDEO_TRACK_ERROR && 
        ind_p->result != MED_RES_AUDIO_TRACK_ERROR)
    {
        handle_ret = mdi_video_ply_play_handle_play_finish(msgPtr);    
        if (!handle_ret)
        {
            return;
        }
    }

    if (mdi_video_ply_play_finish_callback != NULL)
    {
        if (ind_p->result == MED_RES_OK)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_SUCCEED, mdi_video_p->user_data);
        }
        else if (ind_p->result == MED_RES_VIDEO_TRACK_ERROR)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR, mdi_video_p->user_data);
        }
        else if (ind_p->result == MED_RES_AUDIO_TRACK_ERROR)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR, mdi_video_p->user_data);
        }
        else if (ind_p->result == MED_RES_STOP_TIME_REACHED)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_REACH_STOP_TIME, mdi_video_p->user_data);
        }
        else if (ind_p->result == MED_RES_PDL_AUDIO_UNDERFLOW ||
                 ind_p->result == MED_RES_PDL_VIDEO_UNDERFLOW)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH, mdi_video_p->user_data);
        }
        else if  (ind_p->result == MED_RES_VIDEO_UNSUPPORT_DECODE_SIZE)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_ERR_INVALID_RESOULTION, mdi_video_p->user_data);
        }
        else if (ind_p->result == MED_RES_DECODER_NOT_SUPPORT)
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT, mdi_video_p->user_data);
        }
        else
        {
            mdi_video_ply_play_finish_callback(MDI_RES_VDOPLY_ERR_PLAY_FAILED, mdi_video_p->user_data);
        }

        /* MDI_RES_VDOPLY_ERR_PDL_FILE_NOT_ENOUGH */
    }
}


MDI_RESULT mdi_video_ply_set_brightness(U16 brightness)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
#if defined(VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_set_param_req_struct data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_SET_BRIGHTNESS, brightness);

    data.param_id = VID_PARAM_BRIGHTNESS;

    switch (brightness)
    {
        case MDI_VIDEO_BRIGHTNESS_N5:
            data.value = (void *)8; /* -120 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N4:
            data.value = (void *)38;    /* -90 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N3:
            data.value = (void *)68;    /* -60 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N2:
            data.value = (void *)98;    /* -30 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N1:
            data.value = (void *)118;   /* -10 */
            break;

        case MDI_VIDEO_BRIGHTNESS_0:
            data.value = (void *)128;   /* 0 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P1:
            data.value = (void *)138;   /* +10 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P2:
            data.value = (void *)158;   /* +30 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P3:
            data.value = (void *)188;   /* +60 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P4:
            data.value = (void *)218;   /* +90 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P5:
            data.value = (void *)248;   /* +120 */
            break;

        default:
            MMI_ASSERT(0);
            break;

    }

    media_vid_set_param(module_id, &data);
#endif /* VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED */
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOPLY_SUCCEED;
}


MDI_RESULT mdi_video_ply_set_contrast(U16 contrast)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
#if defined(VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_set_param_req_struct data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_SET_CONTRAST, contrast);

    data.param_id = VID_PARAM_CONTRAST;

    switch (contrast)
    {
        case MDI_VIDEO_CONTRAST_N5:
            data.value = (void *)8; /* -120 */
            break;

        case MDI_VIDEO_CONTRAST_N4:
            data.value = (void *)38;    /* -90 */
            break;

        case MDI_VIDEO_CONTRAST_N3:
            data.value = (void *)68;    /* -60 */
            break;

        case MDI_VIDEO_CONTRAST_N2:
            data.value = (void *)98;    /* -30 */
            break;

        case MDI_VIDEO_CONTRAST_N1:
            data.value = (void *)118;   /* -10 */
            break;

        case MDI_VIDEO_CONTRAST_0:
            data.value = (void *)128;   /* 0 */
            break;

        case MDI_VIDEO_CONTRAST_P1:
            data.value = (void *)138;   /* +10 */
            break;

        case MDI_VIDEO_CONTRAST_P2:
            data.value = (void *)158;   /* +30 */
            break;

        case MDI_VIDEO_CONTRAST_P3:
            data.value = (void *)188;   /* +60 */
            break;

        case MDI_VIDEO_CONTRAST_P4:
            data.value = (void *)218;   /* +90 */
            break;

        case MDI_VIDEO_CONTRAST_P5:
            data.value = (void *)248;   /* +120 */
            break;

        default:
            MMI_ASSERT(0);
            break;

    }

    media_vid_set_param(module_id, &data);
#endif /* (VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED) */
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOPLY_SUCCEED;
}

MDI_RESULT mdi_video_ply_set_track_index(U32 index)
{
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    media_vid_set_param_req_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_SET_TRACK_INDEX, index);

    data.param_id = VID_PARAM_TRACK_INDEX;
    data.value = (void *)index;
    media_vid_set_param(module_id, &data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
#endif /* __MMI_VIDEO_3D_ANAGLYPH__ */
    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


MDI_RESULT mdi_video_ply_set_subtitle_track_index(U32 index)
{
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    media_vid_set_param_req_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_SET_SUBTITLE_TRACK_INDEX, index);

    data.param_id = VID_PARAM_SUBTITLE_TRACK;
    data.value = (void *)index;
    media_vid_set_param(module_id, &data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
#endif /* __MMI_VIDEO_SUBTITLE_SUPPORT__ */
    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

extern MDI_RESULT mdi_video_ply_set_subtitle_font_size(U8 size)
{
#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    media_vid_set_param_req_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    data.param_id = VID_PARAM_SUBTITLE_FONT_SIZE;
    data.value = (void *)size;
    media_vid_set_param(module_id, &data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
#endif /* __MMI_VIDEO_SUBTITLE_SUPPORT__ */
    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;   
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_key_frame_time
 * DESCRIPTION
 *  Get key frame time
 * PARAMETERS
 *  time : [IN] input time
 *  key_frame_time: [OUT] the largest key frame time less than input time
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get key frame time
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to get key frame time
 *****************************************************************************/
MDI_RESULT mdi_video_ply_get_key_frame_time(U64 time, mdi_video_search_dir_enum dir, U64 *key_frame_time)
{
#if defined (MDI_VIDEO_DRIVER_AVAIALBE) && defined(__MMI_VIDEO_CLIPPER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    media_vid_get_param_req_struct data;
    mpl_player_param_query_keyframe_time_t key_frame;
    S32 ret; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_GET_KEY_FRAME_TIME, (U32)time);

    key_frame.u8Time_IN = time;
    
    data.param_id = VID_PARAM_KEY_FRAME_TIME;
    data.value = (void *)&key_frame;

    ret = media_vid_get_param(module_id, &data);

    *key_frame_time = key_frame.u8KeyFrameTime_OUT;

    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

#else

    return MDI_RES_VDOPLY_ERR_FAILED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE && __MMI_VIDEO_CLIPPER__ */

    
}


static void mdi_video_ply_init_video(mdi_video_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    mpl_player_get_meta_t meta;
    media_vid_get_param_req_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED)
    if (mdi_video_p->scenario != MPL_INFO)
    {
        /* init brightness/contrast */
        mdi_video_ply_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
        mdi_video_ply_set_contrast(MDI_VIDEO_CONTRAST_0);
    }
#endif /* VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED */

    /* NOTICE: med's API use wchar */
    meta.title_desc_ptr = (kal_wchar*)info->title_desc;
    meta.title_desc_len = MDI_VIDEO_MAX_CONTENT_INFO_LEN;

    meta.artist_desc_ptr = (kal_wchar*)info->artist_desc;
    meta.artist_desc_len = MDI_VIDEO_MAX_CONTENT_INFO_LEN;

    meta.album_desc_ptr = (kal_wchar*)info->album_desc;
    meta.album_desc_len = MDI_VIDEO_MAX_CONTENT_INFO_LEN;

    meta.author_desc_ptr = (kal_wchar*)info->author_desc;
    meta.author_desc_len = MDI_VIDEO_MAX_CONTENT_INFO_LEN;

    meta.copyright_desc_ptr = (kal_wchar*)info->copyright_desc;
    meta.copyright_desc_len = MDI_VIDEO_MAX_CONTENT_INFO_LEN;

    meta.date_desc_ptr = (kal_wchar*)info->date_desc;
    meta.date_desc_len = MDI_VIDEO_MAX_CONTENT_INFO_LEN;

    data.param_id = VID_PARAM_CONTENT_DESC;
    data.value = (void *)&meta;
   
    media_vid_get_param(module_id, &data);
}
#ifdef __MMI_VIDEO_3D_ANAGLYPH__

static void mdi_video_ply_init_track_info(
    mdi_video_info_struct *info, mpl_player_video_track_info_t *track_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (track_p != NULL)
    {
        /* Assign track info */
        for (idx = 0; idx < info->track_num; idx ++)
        {
            info->track_info[idx].track_index = track_p[idx].u4TrackIndex;
            info->track_info[idx].track_type = (mdi_video_track_type_enum)track_p[idx].eVidTrackType;
        } 
    }
}
#endif /* __MMI_VIDEO_3D_ANAGLYPH__ */    

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
static void mdi_video_ply_init_subtitle_info(
    mdi_video_info_struct *info, mpl_player_subtitle_track_info_t *track_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (track_p != NULL)
    {
        /* Assign subtitle info */
        for (idx = 0; idx < info->subtitle_num; idx ++)
        {
            info->subtitle_info[idx].track_index = track_p[idx].u4TrackIndex;
            info->subtitle_info[idx].language = track_p[idx].u4Language;
        } 
    }
}
#endif /* __MMI_VIDEO_SUBTITLE_SUPPORT__ */   

static MDI_RESULT mdi_video_med_to_mdi_ret(S32 med_ret, MDI_RESULT *ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (med_ret)
    {
        case MED_RES_OK:
            *ret = MDI_RES_VDOPLY_SUCCEED;
            break;
        case MED_RES_PDL_AUDIO_UNDERFLOW:
        case MED_RES_PDL_VIDEO_UNDERFLOW:
            *ret = MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH;
            break;
        case MED_RES_MEM_INSUFFICIENT:
            *ret = MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT;
            break;
        case MED_RES_VIDEO_FRAME_RATE_TOO_HIGH:
            *ret = MDI_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH;
            break;
        case MED_RES_VIDEO_UNSUPPORT_DECODE_SIZE:
            *ret = MDI_RES_VDOPLY_ERR_INVALID_RESOULTION;
            break;
        case MED_RES_DECODER_NOT_SUPPORT:
            *ret = MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT;
            break;
        case MED_RES_STOP_TIME_REACHED:
            *ret = MDI_RES_VDOPLY_REACH_STOP_TIME;
            break;
        case MED_RES_VIDEO_TRACK_ERROR:
            *ret = MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR;
            break; 
        case MED_RES_AUDIO_TRACK_ERROR:
            *ret = MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR;
            break;     
        default:
            return MDI_RES_VDOPLY_ERR_FAILED;
    }
    return MDI_RES_VDOPLY_SUCCEED;
}

static MDI_RESULT mdi_video_ply_open_internal(
                const U16 app_id,
                const CHAR *filename,
                const U8 *file_buffer,
                const U32 buffer_len,
                U16 video_id,
                mdi_video_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    MDI_RESULT mdi_ret, error_ret;
    media_vid_open_req_struct open_data = {0};
    module_type module_id = mdi_video_get_module_id();
    PS8 vdo_ptr;
    S32 vdo_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    open_data.scenario = mdi_video_p->scenario;
    open_data.open_track = MED_VID_BOTH;

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    if (open_data.scenario == MPL_DECODER_N_SUBTITLE)
    {
        open_data.open_track |= MED_VID_SUBTITLE;
        open_data.extern_api.prFontEngineApi = subtitle_fontengine_get_table();
        open_data.extern_api.pfnIsLCCSupported = mmi_li_is_lcc_supported;
    }
#endif /* __MMI_VIDEO_SUBTITLE_SUPPORT__ */   
    open_data.seq_num = mdi_video_p->open_seq_num;

    /* synchronous */
    if (info)
    {
        memset(info, 0, sizeof(mdi_video_info_struct));
        open_data.image_width = &info->width;
        open_data.image_height = &info->height;
        open_data.total_time = &info->total_time_duration;
        open_data.is_seekable = &info->is_seekable;
    #ifdef __MMI_VIDEO_CLIPPER__
        open_data.is_proprietary = &info->is_proprietary;
    #endif
        open_data.enable_aud_only = (kal_bool)mdi_video_p->is_enable_aud_only;
        open_data.blocking = TRUE;
    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
        open_data.track_num = &info->track_num;
    #endif 
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
        open_data.subtitle_num = &info->subtitle_num;
    #endif 
    }
    /* asynchronous */
    else
    {
        open_data.enable_aud_only = MMI_TRUE;
        open_data.blocking = FALSE;
    }

    // init parameter
    mdi_video_ply_reset();

    mdi_video_p->is_seek_after_open = FALSE;

    open_data.app_id = app_id;

    /* File */
    if (filename != NULL)
    {
        open_data.media_mode = MED_MODE_FILE;
        open_data.media_type = mdi_video_ply_get_media_type(filename);
        open_data.data = (void*)filename;
    #ifdef __DRM_SUPPORT__
        open_data.file_handle = &mdi_video_p->drm_file_handle;
    #endif
    }
    /* Buffer */
    else if (file_buffer != NULL)
    {
        open_data.media_mode = MED_MODE_ARRAY;
        open_data.media_type = MED_TYPE_3GP;
        open_data.data = (void*)file_buffer;
        open_data.data_size = buffer_len;
    }
    /* ID */
    else
    {
        /* get raw data by ID */
        vdo_ptr = GetMedia(video_id);

        switch (*vdo_ptr)
        {
            case IMAGE_TYPE_AVI:
                open_data.media_type = MED_TYPE_MJPG;
                break;

            case IMAGE_TYPE_3GP:
                open_data.media_type = MED_TYPE_3GP;
                break;

            case IMAGE_TYPE_MP4:
                open_data.media_type = MED_TYPE_MP4;
                break;

            default:
                return MDI_RES_VDOPLY_ERR_FAILED;
        }

        /* get video data length size */
        vdo_len = (S32) (vdo_ptr[2]);
        vdo_len |= (S32) ((S32) vdo_ptr[3] << 8);
        vdo_len |= (S32) ((S32) vdo_ptr[4] << 16);
        vdo_len |= (S32) ((S32) vdo_ptr[5] << 24);

        open_data.media_mode = MED_MODE_ARRAY;
        open_data.data = (void*)(vdo_ptr + 8);
        open_data.data_size = vdo_len;
    }
#ifdef __GAIN_TABLE_SUPPORT__
    mdi_video_p->media_type = open_data.media_type;
#endif

    ret = media_vid_open(module_id, &open_data);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);


    if (ret == MED_RES_OK || ret == MED_RES_MP4_NO_VIDEO_TRACK)
    {
        /* asynchronous */
        if (!info)
        {
            return MDI_RES_VDOPLY_SUCCEED;
        }

        if (ret == MED_RES_MP4_NO_VIDEO_TRACK)
        {
        #ifdef __DRM_SUPPORT__
            info->drm_handle = mdi_video_p->drm_file_handle;
        #endif
            info->track = MDI_VIDEO_TRACK_A_ONLY;
            mdi_video_p->track = MDI_VIDEO_TRACK_A_ONLY;
        }
        else
        {
        #ifdef __DRM_SUPPORT__
            info->drm_handle = mdi_video_p->drm_file_handle;
        #endif
            info->track = MDI_VIDEO_TRACK_AV;
            mdi_video_p->track = MDI_VIDEO_TRACK_AV;
        }

        if(open_data.enable_aud_only && (info->width == 0 || info->height == 0))
        {
            /* open success, but it is audio only and width or height = 0, remove the visual track */
            info->track = MDI_VIDEO_TRACK_A_ONLY;
            mdi_video_p->track = MDI_VIDEO_TRACK_A_ONLY;
        }

        mdi_video_ply_init_video(info);
    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
        mdi_video_ply_init_track_info(info, open_data.track_info);
    #endif
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
        mdi_video_ply_init_subtitle_info(info, open_data.subtitle_info);
    #endif
    
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else
    {
    #ifdef __DRM_SUPPORT__
        mdi_video_ply_drm_reset_state();
    #endif /* __DRM_SUPPORT__ */

        mdi_ret = mdi_video_med_to_mdi_ret(ret, &error_ret);
        if (mdi_ret == MDI_RES_VDOPLY_SUCCEED)
        {
            return error_ret;
        }
        else
        {
            return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
        }
    }    
}


/****************************************************************************
*
* VIDEO CLIP
*
*****************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_stop_time
 * DESCRIPTION
 *  Set stop time, currently for Java use only.
 * PARAMETERS
 *  stop_time : [IN]Stop time
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set stop time to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set stop time to video player.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_set_stop_time(U64 stop_time)
{
#if defined(MDI_VIDEO_DRIVER_AVAIALBE) && defined (SUPPORT_MMAPI)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    media_vid_stop_time_struct stop_data;
    media_vid_set_param_req_struct data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_SET_STOP_TIME);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STOP_TIME, (U32)stop_time);

    stop_data.stop_time = stop_time;

    data.param_id = VID_PARAM_STOP_TIME;
    data.value = (void *)&stop_data;

    media_vid_set_param(module_id, &data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE && SUPPORT_MMAPI */

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_sleep_time
 * DESCRIPTION
 *  Set sleep time, currently for Java use only.
 * PARAMETERS
 *  stop_time : [IN]Stop time
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set stop time to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set stop time to video player.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_set_sleep_time(U8 elapse_ticks, U8 sleep_ticks)
{
#if defined(MDI_VIDEO_DRIVER_AVAIALBE) && defined (SUPPORT_MMAPI)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    mpl_player_param_sleep_time_t sleep_data;
    media_vid_set_param_req_struct data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_SET_SLEEP_TIME);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_SLEEP_TIME, elapse_ticks, sleep_ticks);

    sleep_data.elapse_ticks = elapse_ticks;
    sleep_data.sleep_ticks = sleep_ticks;

    data.param_id = VID_PARAM_SLEEP_TIME;
    data.value = (void *)&sleep_data;


    media_vid_set_param(module_id, &data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE && SUPPORT_MMAPI */

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_time_to_frame
 * DESCRIPTION
 *  This function is to map given time to the frame number.
 * PARAMETERS
 *  time        [IN]
 *  frame       [?]
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_get_time_to_frame(U64 time, U32 *frame)
{
#if defined (MDI_VIDEO_DRIVER_AVAIALBE) && defined(SUPPORT_MMAPI)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    mpl_player_param_time_and_frame_mapping_t info;
    media_vid_get_param_req_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info.time = time;

    data.param_id = VID_PARAM_TIME_TO_FRAME;
    data.value = (void *)&info;

    media_vid_get_param(module_id, &data);

    *frame = info.frame;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE && SUPPORT_MMAPI */

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_frame_to_time
 * DESCRIPTION
 *  This function is to map given frame to the frame timestamp.
 * PARAMETERS
 *  frame        [IN]
 *  time       [?]
 * RETURNS
 *  The result of this action.
 *****************************************************************************/
MDI_RESULT mdi_video_ply_get_frame_to_time(U32 frame, U64 *time)
{
#if defined (MDI_VIDEO_DRIVER_AVAIALBE) && defined(SUPPORT_MMAPI)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    mpl_player_param_time_and_frame_mapping_t info;
    media_vid_get_param_req_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info.frame = frame;

    data.param_id = VID_PARAM_FRAME_TO_TIME;
    data.value = (void *)&info;

    media_vid_get_param(module_id, &data);

    *time = info.time;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE && SUPPORT_MMAPI */

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_get_mot_meta
 * DESCRIPTION
 *  To get MOT meta
 * PARAMETERS
 *  meta : [IN] MOT meta.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get mot meta
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to get mot meta
 *****************************************************************************/
MDI_RESULT mdi_video_ply_get_mot_meta(mdi_video_mot_meta_struct *info)
{
#if defined (MDI_VIDEO_DRIVER_AVAIALBE) && defined(__MMI_MOT_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    mpl_player_get_mot_meta_t meta;
    media_vid_get_param_req_struct data;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* NOTICE: med's API use wchar */
    meta.title_desc_ptr = info->title_desc_ptr;
    meta.title_desc_len = info->title_desc_len;

    meta.artist_desc_ptr = info->artist_desc_ptr;
    meta.artist_desc_len = info->artist_desc_len;

    meta.date_desc_ptr = info->date_desc_ptr;
    meta.date_desc_len = info->date_desc_len;

    meta.annotation_desc_ptr = info->annotation_desc_ptr;
    meta.annotation_desc_len = info->annotation_desc_len;

    meta.type_desc_ptr = info->type_desc_ptr;
    meta.type_desc_len = info->type_desc_len;

    meta.thumbnail_data_ptr = info->thumb_ptr;
    meta.thumbnail_data_allocated_len = info->thumb_allocated_len;

    data.param_id = VID_PARAM_MOT_META;
    data.value = (void *)&meta;

    ret = media_vid_get_param(module_id, &data);

    // fill output value
    info->thumb_usaged_len = meta.thumbnail_data_usaged_len;
    info->thumb_type = (mdi_video_thumb_type_enum)meta.thumbnail_type;

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE && __MMI_MOT_SUPPORT__ */

    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_set_audio_level
 * DESCRIPTION
 *  To set audio level, used by Java only
 * PARAMETERS
 *  aud_level : [IN]Audio level.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set audio level to video player.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to set audio level to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_ply_set_audio_level(U16 aud_level)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(aud_level <= 100);
    media_vid_set_volume_level(module_id, aud_level);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_check_proc_func
 * DESCRIPTION
 *  To check video is currently playing or not
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : Video is playing now.
 *  MMI_FALSE : Video is not playing now.
 *****************************************************************************/
mmi_ret mdi_video_check_proc_func(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mdi_video_is_playing())
    {
        return MMI_RET_ERR;
    }
    else
    {
        return MMI_RET_OK;
    }
}

#ifndef MDI_VIDEO_DRIVER_AVAIALBE
/*****************************************************************************
 * FUNCTION
 *  mdi_video_ply_dummy_play_cyclic
 * DESCRIPTION
 *  dummy play cyclic function which updates lcd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_ply_dummy_play_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mdi_video_p->play_data.idp_rotate == 0 || mdi_video_p->play_data.idp_rotate == 180)
    {
        gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH - 1, UI_DEVICE_HEIGHT - 1);
    }
    else
    {
        gdi_layer_blt_previous(0, 0, UI_DEVICE_HEIGHT - 1, UI_DEVICE_WIDTH - 1);
    }
    gui_start_timer(100, mdi_video_ply_dummy_play_cyclic);
}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif


#endif /* defined(__MMI_VIDEO_PLAYER__) */

/*****************************************************************************
 *
 * Streaming
 *
 *****************************************************************************/
#ifdef __MMI_VIDEO_STREAM__


#ifdef __MM_DCM_SUPPORT__
static void mdi_stream_dcm_load(void)
{
    DCM_Load(DYNAMIC_CODE_COMPRESS_MDISTREAM, NULL, NULL);
}

static void mdi_stream_dcm_unload(void)
{
    DCM_Unload(DYNAMIC_CODE_COMPRESS_MDISTREAM);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_init
 * DESCRIPTION
 *  To initialize video streaming module.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to initialize video streaming module.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to initialize video streaming module.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_init(const U16 app_id)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_INIT);

#ifdef __MM_DCM_SUPPORT__
    mdi_stream_dcm_load();
#endif

    if (mdi_stream_p->uaprof_str[0])
    {
        media_stream_set_uaprof_str(module_id, mdi_stream_p->stream_session_id, mdi_stream_p->uaprof_str);
    }
    if (mdi_stream_p->ua_str[0])
    {
        media_stream_set_user_agent_str(module_id, mdi_stream_p->stream_session_id, mdi_stream_p->ua_str);
    }
    if (mdi_stream_p->uaprof_diff_str[0])
    {
        media_stream_set_user_profile_diff_str(module_id, mdi_stream_p->stream_session_id, mdi_stream_p->uaprof_diff_str);
    }
    mdi_stream_p->is_enable_partial_display = FALSE;
    mdi_stream_p->play_style = MDI_VIDEO_TRACK_NONE;
    mdi_stream_p->scenario = MPL_DECODER;

#ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
    mdi_stream_p->frame_mode = MDI_VIDEO_FRAME_MODE_FIT_INSIDE;
#else /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */
    mdi_stream_p->frame_mode = MDI_VIDEO_FRAME_MODE_STRETCH;
#endif /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */

    mdi_stream_p->mode_3d = MDI_VIDEO_3D_MODE_NONE;

    ret = media_stream_init(module_id, &mdi_stream_p->stream_session_id, app_id);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    if (ret == MED_RES_OK)
    {
        mdi_stream_p->is_stream_init = TRUE;
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else
    {
        mdi_stream_p->is_stream_init = FALSE;

        #ifdef __MM_DCM_SUPPORT__
            mdi_stream_dcm_unload();
        #endif

        return MDI_RES_VDOPLY_ERR_FAILED;
    }
#else
    return MDI_RES_VDOPLY_SUCCEED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_deinit
 * DESCRIPTION
 *  To de-initialze video streaming module.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to de-initialize video streaming module.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to de-initialize video streaming module.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_deinit(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_DEINIT);

    ret = media_stream_deinit(module_id, mdi_stream_p->stream_session_id);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    mdi_stream_p->is_stream_init = FALSE;

    #ifdef __MM_DCM_SUPPORT__
        mdi_stream_dcm_unload();
    #endif


    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
#else
    return MDI_RES_VDOPLY_SUCCEED;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_prebuffer_time
 * DESCRIPTION
 *  To set the pre-buffer time that application want.
 * PARAMETERS
 *  U32 time: [IN] the pre-buffer time in millisecond. (min. 3000 ms)
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set pre-buffer time of video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set pre-buffer time of video player.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_prebuffer_time(U32 time)
{
    mdi_stream_p->prebuffer_time = time;

    if (mdi_stream_p->prebuffer_time < STREAM_BUFFER_MIN_PRE_DL_LEN)
    {
        mdi_stream_p->prebuffer_time = STREAM_BUFFER_MIN_PRE_DL_LEN;
    }

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_prefer_transport
 * DESCRIPTION
 *  To get prefer RTP transport
 * PARAMETERS
 *  mdi_video_stream_transport_type_enum *type
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get prefer RTP transport
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to get prefer RTP transport
 *****************************************************************************/
MDI_RESULT mdi_video_stream_get_prefer_transport(mdi_video_stream_transport_type_enum *type)
{
    switch(mdi_stream_p->prefer_transport)
    {
        case MEDIA_STREAM_RTP_CONNECT_TYPE_UDP:
            *type = MDI_VIDEO_STREAM_TRANSPORT_UDP;
            break;
        case MEDIA_STREAM_RTP_CONNECT_TYPE_TCP:
            *type = MDI_VIDEO_STREAM_TRANSPORT_TCP;
            break;
        default:
            ASSERT(0);
    }

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_prefer_transport
 * DESCRIPTION
 *  To set prefer RTP transport
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set prefer RTP transport
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set prefer RTP transport
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_prefer_transport(mdi_video_stream_transport_type_enum type)
{
    switch(type)
    {
        case MDI_VIDEO_STREAM_TRANSPORT_UDP:
            mdi_stream_p->prefer_transport = MEDIA_STREAM_RTP_CONNECT_TYPE_UDP;
            break;
        case MDI_VIDEO_STREAM_TRANSPORT_TCP:
            mdi_stream_p->prefer_transport = MEDIA_STREAM_RTP_CONNECT_TYPE_TCP;
            break;
        default:
            ASSERT(0);
    }

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_user_agent_str
 * DESCRIPTION
 *  set the user agent strin
 * PARAMETERS
 *  uaprof_p    [IN]  the UserAgnt string
 * RETURNS
 *  MDI_RES_VDOPLY_SUCCEED if success, otherwise MDI_RES_VDOPLY_ERR_FAILED
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_user_agent_str(CHAR* ua_str_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ua_str_p != NULL)
    {
        len = strlen(ua_str_p);
    }

    kal_mem_set(mdi_stream_p->ua_str, 0, MDI_VIDEO_STREAM_UA_STR_BUFF_LEN);
    if (len < MDI_VIDEO_STREAM_UA_STR_BUFF_LEN)
    {
        strncpy((kal_char *)mdi_stream_p->ua_str, (kal_char *)ua_str_p, MDI_VIDEO_STREAM_UA_STR_BUFF_LEN - 1);
    }

    return MDI_RES_VDOPLY_SUCCEED;
}


#ifdef __MM_DCM_SUPPORT__
#pragma arm section code = "DYNAMIC_CODE_MDISTREAM_ROCODE", rodata = "DYNAMIC_CODE_MDISTREAM_RODATA"
#endif


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_drm_consume_callback
 * DESCRIPTION
 *  drm callback
 * PARAMETERS
 *  result      [IN]        result, currently, it means time consumed.
 *  id          [IN]        id
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_stream_drm_consume_callback(S32 result, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_MEDIA_TRC_G4_MDI,
        MDI_TRC_VIDEO_DRM_CONSUME_CALLBACK,
        mdi_stream_p->is_playing,
        mdi_stream_p->drm_streaming_state,
        __LINE__);

    /* video is playing and drm is consuming.. */
    if (mdi_stream_p->is_playing &&
        mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_CONSUMING)
    {
        /* stop stream playing */
        mdi_video_stream_stop();

        /* notfiy caller */
        if (mdi_video_stream_play_finish_callback != NULL)
        {
            mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_ERR_DRM_DURATION_USED, mdi_stream_p->user_data);
        }
    }

}
#endif

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_drm_disable_consume_count
 * DESCRIPTION
 *  Do not consume drm count when play.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to disable consume drm count for next playing.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to disable consume drm count for next playing.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_drm_disable_consume_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STERAM_DRM_DISABLE_CONSUME_COUNT);

#ifdef __DRM_SUPPORT__
    mdi_stream_p->is_drm_consume_count = FALSE;
#endif

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_drm_disable_consume_time
 * DESCRIPTION
 *  Do not consume drm count when play
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to disable consume drm time limitation for next playing.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to disable consume drm time limitation for next playing.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_drm_disable_consume_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STERAM_DRM_DISABLE_CONSUME_TIME);

#ifdef __DRM_SUPPORT__
    mdi_stream_p->is_drm_consume_time = FALSE;
#endif

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_scenario
 * DESCRIPTION
 *  To set scenario type
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to enable playing audio only video clip
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to enable playing audio only video clip
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_scenario(mdi_video_scenario_type_enum scenario)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//  MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_ENABLE_PARTIAL_DISPLAY);

    switch(scenario)
    {
        case MDI_VIDEO_SCENARIO_DEFAULT:
            mdi_stream_p->scenario = MPL_DECODER;
            break;
        case MDI_VIDEO_SCENARIO_QVGA:
            mdi_stream_p->scenario = MPL_UPTO_QVGA;
            break;
        case MDI_VIDEO_SCENARIO_CIF:
            mdi_stream_p->scenario = MPL_UPTO_CIF;
            break;
        default:
            ASSERT(0);
    }

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_connect
 * DESCRIPTION
 *  blah
 * PARAMETERS
 *  blah
 * RETURNS
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to connect to server.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to connect to server.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_connect(
            U32 data_account,
            mdi_video_stream_type_enum stream_type,
            CHAR *data_path,
            MMI_BOOL use_proxy,
            CHAR *proxy,
            U16 port,
            MMI_BOOL use_udp_port,
            U16 highest_udp_port,
            U16 lowest_udp_port,
            mdi_connect_result_callback connect_result_callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U8 type = 0;
    module_type module_id = mdi_video_get_module_id();
    media_stream_connect_req_struct connect_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_CONNECT);

    mdi_video_stream_connect_result_callback = connect_result_callback;
    mdi_stream_p->user_data = user_data;

    SetProtocolEventHandler(mdi_video_stream_connect_result_hdlr, MSG_ID_MEDIA_STREAM_CONNECTED_IND);

    if (stream_type == MDI_VIDEO_STREAM_RTSP_URL)
    {
        type = MEDIA_STREAM_CONN_TYPE_RTSP_URL;
    }
    else if(stream_type == MDI_VIDEO_STREAM_SDP_FILE)
    {
        type = MEDIA_STREAM_CONN_TYPE_SDP_FILE;
    }
    else
    {
        MMI_ASSERT(0);
    }

    mdi_stream_p->is_stream_connected = FALSE;

    if (!use_udp_port)
    {
        /* application didnt assign udp port, use default */
        highest_udp_port = 65535;
        lowest_udp_port = 6000;
    }

    connect_param.session_id = (kal_uint8)mdi_stream_p->stream_session_id;
    connect_param.request_id = (kal_uint16)mdi_stream_p->connect_seq_num;
    connect_param.net_id = (kal_uint32)data_account;
    connect_param.type = (kal_uint8)type;
    connect_param.link_path = (kal_wchar*)data_path;
    connect_param.use_proxy = (kal_bool)use_proxy;
    if (connect_param.use_proxy)
    {
        kal_mem_cpy(connect_param.proxy_addr, proxy, sizeof(connect_param.proxy_addr));
    }
    connect_param.proxy_port = (kal_uint16)port;
    connect_param.lowest_udp_port = (kal_uint16)lowest_udp_port;
    connect_param.highest_udp_port = (kal_uint16)highest_udp_port;
    connect_param.scenario = mdi_stream_p->scenario;
    connect_param.prefer_transport = mdi_stream_p->prefer_transport;

    ret = media_stream_connect(module_id, &connect_param);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    mdi_stream_p->dummy_counter = 0;

    mdi_video_stream_connect_result_callback = connect_result_callback;
    mdi_stream_p->user_data = user_data;
    gui_start_timer(3000, mdi_video_stream_dummy_connect_result_hdlr);
    return MDI_RES_VDOPLY_SUCCEED;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_connect_result_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_stream_connect_result_hdlr(void *msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_connected_ind_struct *ind_p;
    mdi_video_info_struct *video_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_CONNECT_RESULT_HDLR);
    MMI_ASSERT(mdi_video_stream_connect_result_callback != NULL);

    ind_p = (media_stream_connected_ind_struct*)msg_ptr;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);


    /* seq number not match, measn it is already disconnected, ignore this message */
    if (mdi_stream_p->connect_seq_num != ind_p->request_id)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);
        return;
    }

    mdi_stream_p->is_drm_streaming = FALSE;
    video_info = get_ctrl_buffer(sizeof(mdi_video_info_struct));
    ASSERT(video_info);

    if (ind_p->result == MED_RES_OK)
    {
        /*
         * in connect result, we can get
         * (1) track type
         * (2) total time (media len)
         * (3) seekable or not,
         * other info will get from seek(buffering) result
         */

        if ((ind_p->type_mask & MEDIA_STREAM_MEDIA_TYPE_AUDIO) &&
            (ind_p->type_mask & MEDIA_STREAM_MEDIA_TYPE_VIDEO))
        {
            /* A/V */
            mdi_stream_p->video_info.track = MDI_VIDEO_TRACK_AV;
            mdi_stream_p->play_style = MDI_VIDEO_TRACK_AV;
        }
        else if (ind_p->type_mask & MEDIA_STREAM_MEDIA_TYPE_AUDIO)
        {
            /* A only */
            mdi_stream_p->video_info.track = MDI_VIDEO_TRACK_A_ONLY;
            mdi_stream_p->play_style = MDI_VIDEO_TRACK_A_ONLY;
        }
        else if (ind_p->type_mask & MEDIA_STREAM_MEDIA_TYPE_VIDEO)
        {
            /* V only */
            mdi_stream_p->video_info.track = MDI_VIDEO_TRACK_V_ONLY;
            mdi_stream_p->play_style = MDI_VIDEO_TRACK_V_ONLY;
        }
        else
        {
            MMI_ASSERT(0);
        }

        mdi_stream_p->video_info.total_time_duration = ind_p->media_len;
        mdi_stream_p->video_info.is_seekable = (MMI_BOOL)ind_p->seekable;
        mdi_stream_p->video_info.is_rec_allowed = (MMI_BOOL)ind_p->rec_allowed;

        strcpy((kal_char*)&mdi_stream_p->video_info.title_desc, (kal_char*)&ind_p->title);

        memset(video_info, 0, sizeof(mdi_video_info_struct));
        video_info->total_time_duration = mdi_stream_p->video_info.total_time_duration;
        video_info->is_seekable = mdi_stream_p->video_info.is_seekable;
        video_info->track = mdi_stream_p->video_info.track;
        video_info->drm_handle = ind_p->pdcf_handle;
        video_info->is_drm_streaming = (MMI_BOOL)ind_p->is_DRM_pdcf;
        video_info->is_rec_allowed = mdi_stream_p->video_info.is_rec_allowed;

        strcpy((kal_char*)&video_info->title_desc, (kal_char*)&mdi_stream_p->video_info.title_desc);

        /* init brightness and contrast */
        mdi_video_stream_set_brightness(MDI_VIDEO_BRIGHTNESS_0);
        mdi_video_stream_set_contrast(MDI_VIDEO_CONTRAST_0);


    #ifdef __DRM_SUPPORT__
        ASSERT(mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_EXIT);

        MMI_TRACE(
            MMI_MEDIA_TRC_G4_MDI,
            MDI_TRC_VIDEO_STERAM_DRM_CONNECT_RESULT,
            ind_p->is_DRM_pdcf,
            ind_p->pdcf_handle,
            __LINE__);

        if (ind_p->is_DRM_pdcf)
        {
            mdi_stream_p->is_drm_streaming = TRUE;
            mdi_stream_p->drm_streaming_handle = ind_p->pdcf_handle;
        }

        if (mdi_stream_p->is_drm_streaming)
        {
            /* make sure handle is correct when is drm streaming */
            MMI_ASSERT(mdi_stream_p->drm_streaming_handle >= FS_NO_ERROR);

            /* check if it is DRM source or not */
            if (DRM_get_object_method(mdi_stream_p->drm_streaming_handle, NULL) != DRM_METHOD_NONE)
            {

                MMI_TRACE(
                    MMI_MEDIA_TRC_G4_MDI,
                    MDI_TRC_VIDEO_DRM_CONSUME_FLAG,
                    mdi_stream_p->is_drm_consume_count,
                    mdi_stream_p->is_drm_consume_time,
                    __LINE__);

                if (mdi_stream_p->is_drm_consume_count)
                {
                    if (DRM_validate_permission(mdi_stream_p->drm_streaming_handle, NULL, DRM_PERMISSION_PLAY))
                    {
                        /* it is DRM source, and has permission */
                        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_PERMITTED, __LINE__);
                        mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_PERMITTED;
                    }
                    else
                    {
                        /* it is DRM source, but no rights */
                        video_info->drm_handle = ind_p->pdcf_handle;
                        video_info->is_drm_streaming = (MMI_BOOL)ind_p->is_DRM_pdcf;

                        /* change state to play finied, so it will validate next time */
                        mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_PLAY_FINISHED;
                        mdi_stream_p->drm_streaming_id = MDI_VIDEO_DRM_INVALID_VALUE;
                        mdi_video_stream_connect_result_callback(MDI_RES_VDOPLY_STREAM_DRM_NEED_RIGHT, video_info, mdi_stream_p->user_data);
                        free_ctrl_buffer(video_info);
                        return;
                    }
                }
                else
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_PERMITTED, __LINE__);
                    mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_PERMITTED;
                }
            }

        }
    #endif /* __DRM_SUPPORT__ */

        mdi_stream_p->is_stream_connected = TRUE;
        mdi_video_stream_connect_result_callback(MDI_RES_VDOPLY_SUCCEED, video_info, mdi_stream_p->user_data);
    }
    else
    {
   #ifdef __DRM_SUPPORT__
        /* reset flag */
        mdi_stream_p->is_drm_consume_count = TRUE;
        mdi_stream_p->is_drm_consume_time = TRUE;
        mdi_stream_p->is_drm_streaming = FALSE;

        if (mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_PAUSED)
        {
            ASSERT(mdi_stream_p->drm_streaming_id != MDI_VIDEO_DRM_INVALID_VALUE);
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_STOP_CONSUME, __LINE__);
            DRM_stop_consume(mdi_stream_p->drm_streaming_id);
            mdi_stream_p->drm_streaming_id = MDI_VIDEO_DRM_INVALID_VALUE;

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_EXIT, __LINE__);
            mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_EXIT;
        }
        else if (mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_PLAY_FINISHED ||
                 mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_PERMITTED)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_EXIT, __LINE__);
            mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_EXIT;
        }
    #endif /* __DRM_SUPPORT__ */

        mdi_stream_p->is_playing = FALSE;
        mdi_stream_p->connect_seq_num++;
        if (mdi_stream_p->is_lcd_update == TRUE)
        {
            if ((mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_AV ||
                 mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_V_ONLY) &&
                (mdi_stream_p->play_style == MDI_VIDEO_TRACK_AV ||
                 mdi_stream_p->play_style == MDI_VIDEO_TRACK_V_ONLY ||
                 mdi_stream_p->play_style == MDI_VIDEO_TRACK_NONE))
            {
                gdi_lcd_set_hw_update(KAL_FALSE);
            }
        }

        switch (ind_p->result)
        {
            case MED_RES_STREAM_BEARER_DISCONNECTED:
            case MED_RES_STREAM_RTSP_REQUEST_FAIL:
                mdi_video_stream_connect_result_callback(MDI_RES_VDOPLY_ERR_NETWORK_DISCONNECT, video_info, mdi_stream_p->user_data);
                break;
            case MED_RES_STREAM_RTSP_REQUEST_FORBIDDEN:
                mdi_video_stream_connect_result_callback(MDI_RES_VDOPLY_ERR_NETWORK_FORBIDDEN, video_info, mdi_stream_p->user_data);
                break;
            case MED_RES_STREAM_UNSUPPORTED_BANDWIDTH:
            case MED_RES_STREAM_UNSUPPORTED_CODEC:
                mdi_video_stream_connect_result_callback(MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT, video_info, mdi_stream_p->user_data);
                break;
            default:
                mdi_video_stream_connect_result_callback(MDI_RES_VDOPLY_ERR_STREAM_CONNECT_FAILED, video_info, mdi_stream_p->user_data);
                break;
        }
    }

    free_ctrl_buffer(video_info);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_dummy_connect_result_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_stream_dummy_connect_result_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_info_struct *video_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_info = get_ctrl_buffer(sizeof(mdi_video_info_struct));
    ASSERT(video_info);

    video_info->total_time_duration = 0;
    video_info->is_seekable = FALSE;
    video_info->track = MDI_VIDEO_TRACK_AV;

    strcpy((kal_char*)&video_info->title_desc, (kal_char*)"test streaming");

    mdi_video_stream_connect_result_callback(MDI_RES_VDOPLY_SUCCEED, video_info, mdi_stream_p->user_data);

    free_ctrl_buffer(video_info);
}
#endif /* !defined(MDI_VIDEO_DRIVER_AVAIALBE) */



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_disconnect
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to disconnect to server.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to disconnect to server.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_disconnect(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_DISCONNECT);
    mdi_stream_p->connect_seq_num++;

    if (mdi_stream_p->is_stream_connected)
    {
        ret = media_stream_disconnect(module_id, mdi_stream_p->stream_session_id);
    }
    else
    {
        ret = media_stream_abort(module_id, mdi_stream_p->stream_session_id, MED_STREAM_ABORT_TYPE_DISCONNECT);
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    mdi_stream_p->is_stream_connected = FALSE;


#ifdef __DRM_SUPPORT__
    /* reset flag */
    mdi_stream_p->is_drm_consume_count = TRUE;
    mdi_stream_p->is_drm_consume_time = TRUE;
    mdi_stream_p->is_drm_streaming = FALSE;

    if (mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_PAUSED)
    {
        ASSERT(mdi_stream_p->drm_streaming_id != MDI_VIDEO_DRM_INVALID_VALUE);
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_STOP_CONSUME, __LINE__);
        DRM_stop_consume(mdi_stream_p->drm_streaming_id);
        mdi_stream_p->drm_streaming_id = MDI_VIDEO_DRM_INVALID_VALUE;

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_EXIT, __LINE__);
        mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_EXIT;
    }
    else if (mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_PLAY_FINISHED ||
             mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_PERMITTED)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_EXIT, __LINE__);
        mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_EXIT;
    }
#endif /* __DRM_SUPPORT__ */

    if (mdi_stream_p->is_lcd_update == TRUE)
    {
        if ((mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_V_ONLY) &&
            (mdi_stream_p->play_style == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_V_ONLY ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_NONE))
        {
            gdi_lcd_set_hw_update(KAL_FALSE);
            mdi_stream_p->is_lcd_update = FALSE;
        }
    }

    ClearProtocolEventHandler(MSG_ID_MEDIA_STREAM_CONNECTED_IND);

    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_STREAM_CONNECT_FAILED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    gui_cancel_timer(mdi_video_stream_dummy_connect_result_hdlr);

    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */



}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_is_connected
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : It is connected with stream server.
 *  MMI_FALSE : It is not connected with stream server.
 *****************************************************************************/
MMI_BOOL mdi_video_stream_is_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_IS_CONNECTED);

    /* not implement yet */
    MMI_ASSERT(0);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_start_buffering
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to start buffering.
 *  MDI_RES_VDOPLY_ERR_DRM_PROHIBITED : Fail to start buffering due to drm check is prohibited.
 *  MDI_RES_VDOPLY_REACH_STOP_TIME : Fail to start buffering due to it is stopped due to stop time is reached.
 *  MDI_RES_VDOPLY_ERR_PLAY_FAILED : Fail to start buffering.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_start_buffering(
            U64 time,
            mdi_buffering_result_callback buffering_result_callback,
            void *user_data)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();
    media_stream_seek_req_struct seek_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_START_BUFFERING);

    mdi_video_stream_buffering_result_callback = buffering_result_callback;
    mdi_stream_p->user_data = user_data;
    SetProtocolEventHandler(mdi_video_stream_buffering_result_hdlr, MSG_ID_MEDIA_STREAM_SEEK_IND);

#ifdef __DRM_SUPPORT__
    if (mdi_stream_p->drm_streaming_state != MDI_VIDEO_DRM_EXIT)
    {
        ASSERT(mdi_stream_p->drm_streaming_handle != NULL);

        if (!DRM_validate_permission(mdi_stream_p->drm_streaming_handle, NULL, DRM_PERMISSION_PLAY))
        {
            /* no permission */
            return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
        }
    }
    else
    {
        /* do nothing */
    }


#endif /* __DRM_SUPPORT__ */

    seek_struct.session_id = mdi_stream_p->stream_session_id;
    seek_struct.request_id = mdi_stream_p->buffering_seq_num;
    seek_struct.start_time = time;
    seek_struct.prebuffer_time = mdi_stream_p->prebuffer_time;
    if (seek_struct.prebuffer_time < STREAM_BUFFER_MIN_PRE_DL_LEN)
    {
        seek_struct.prebuffer_time = STREAM_BUFFER_MIN_PRE_DL_LEN;
    }

    ret = media_stream_seek(module_id, &seek_struct);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else if (ret == MED_RES_STREAM_STOP_TIMEOUT)
    {
        return MDI_RES_VDOPLY_REACH_STOP_TIME;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_STREAM_BUFFER_FAILED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    mdi_stream_p->dummy_cur_time = time;
    mdi_stream_p->dummy_loading_percentage = 0;
    mdi_video_stream_buffering_result_callback = buffering_result_callback;
    mdi_stream_p->user_data = user_data;

    mdi_video_stream_dummy_start_buffering_cyclic();

    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_buffering_result_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_stream_buffering_result_hdlr(void *msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_seek_ind_struct *ind_p;
    mdi_video_info_struct *video_info;
    media_stream_get_info_struct stream_info;
    S32 ret;
    module_type module_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_BUFFERING_RESULT_HDLR);
    MMI_ASSERT(mdi_video_stream_buffering_result_callback != NULL);

    ind_p = (media_stream_seek_ind_struct*)msg_ptr;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);

    /* seq number not match, measn it is already disconnected, ignore this message */
    if (mdi_stream_p->buffering_seq_num != ind_p->request_id)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);
        return;
    }

    video_info = get_ctrl_buffer(sizeof(mdi_video_info_struct));
    ASSERT(video_info);

    /* increase, due to driver may send multiple buffering result ind, we may only accepet 1 */
    mdi_stream_p->buffering_seq_num++;

    /* get module id after seq check */
    module_id = mdi_video_get_module_id();

    if (ind_p->result == MED_RES_OK)
    {
        memset(video_info, 0, sizeof(mdi_video_info_struct));

        ret = media_stream_get_info(module_id, mdi_stream_p->stream_session_id, &stream_info);
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

        if (ret == MED_RES_OK)
        {
            mdi_stream_p->video_info.aud_channel_no = stream_info.channel_num;
            mdi_stream_p->video_info.aud_sample_rate = stream_info.sampleing_freq;

            video_info->width = stream_info.image_width;
            video_info->height = stream_info.image_height;
            video_info->total_time_duration = mdi_stream_p->video_info.total_time_duration;
            video_info->track = mdi_stream_p->video_info.track;
            video_info->is_seekable = mdi_stream_p->video_info.is_seekable;
            //video_info->handle = 0;  /* not used in this case */
            video_info->aud_channel_no = stream_info.channel_num;
            video_info->aud_sample_rate = stream_info.sampleing_freq;

            mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_SUCCEED, video_info, mdi_stream_p->user_data);
        }
        else if (ret == MED_RES_STREAM_INVALID_RESOLUTION)
        {
            mdi_video_stream_stop_buffering();
            mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_ERR_INVALID_RESOULTION, video_info, mdi_stream_p->user_data);
        }
        else if (ret == MED_RES_STREAM_UNSUPPORTED_CODEC)
        {
            mdi_video_stream_stop_buffering();
            mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT, video_info, mdi_stream_p->user_data);
        }
        else
        {
            mdi_video_stream_stop_buffering();
            mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_ERR_STREAM_BUFFER_FAILED, video_info, mdi_stream_p->user_data);
        }
    }
    else
    {
        switch(ind_p->result)
        {
            case MED_RES_STREAM_STOP_TIMEOUT:
                mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_REACH_STOP_TIME, video_info, mdi_stream_p->user_data);
                break;
            case MED_RES_STREAM_INVALID_RESOLUTION:
                mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_ERR_INVALID_RESOULTION, video_info, mdi_stream_p->user_data);
                break;
            case MED_RES_STREAM_UNSUPPORTED_CODEC:
                mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT, video_info, mdi_stream_p->user_data);
                break;
            case MED_RES_STREAM_BUFFER_OVERFLOW:
                mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_STREAM_BUFFER_OVERFLOW, video_info, mdi_stream_p->user_data);
                break;
            case MED_RES_AUDIO_TRACK_ERROR:
                mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR, video_info, mdi_stream_p->user_data);
                break;
            case MED_RES_VIDEO_TRACK_ERROR:
                mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR, video_info, mdi_stream_p->user_data);
                break;
            default:
                mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_ERR_STREAM_BUFFER_FAILED, video_info, mdi_stream_p->user_data);
                break;
        }
    }

    free_ctrl_buffer(video_info);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_stop_buffering
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to stop buffering.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to stop buffering.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_stop_buffering(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_STOP_BUFFERING);

    mdi_stream_p->buffering_seq_num++;

    ret = media_stream_abort(module_id, mdi_stream_p->stream_session_id, MED_STREAM_ABORT_TYPE_STOP);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    gui_cancel_timer(mdi_video_stream_dummy_start_buffering_cyclic);
    return MDI_RES_VDOPLY_SUCCEED;
#endif


}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_dummy_start_buffering_cyclic
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_stream_dummy_start_buffering_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_info_struct* vdo_clip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vdo_clip = get_ctrl_buffer(sizeof(mdi_video_info_struct));
    ASSERT(vdo_clip);

    if (mdi_stream_p->dummy_loading_percentage < 100)
    {
        mdi_stream_p->dummy_loading_percentage += 10;
        gui_start_timer(300, mdi_video_stream_dummy_start_buffering_cyclic);
    }
    else
    {
        vdo_clip->width = 176;
        vdo_clip->height = 144;
        vdo_clip->total_time_duration = MDI_VIDEO_DUMMY_TOTAL_TIME;
        vdo_clip->is_seekable = MMI_FALSE;
        vdo_clip->track = MDI_VIDEO_TRACK_AV;
        mdi_video_stream_buffering_result_callback(MDI_RES_VDOPLY_SUCCEED, vdo_clip, mdi_stream_p->user_data);
    }

    free_ctrl_buffer(vdo_clip);
}
#endif /* !defined(MDI_VIDEO_DRIVER_AVAIALBE) */


static MDI_RESULT mdi_video_stream_prepare_video_param(
            media_stream_set_info_struct *set_info_data,
            gdi_handle player_layer_handle,
            U32 blt_layer_flag,
            U32 play_layer_flag,
            BOOL is_visual_update)
{
    gdi_color_format format;
    U8 *buf_ptr;
    S32 width, height;
    U8 rotate;

    gdi_lcd_get_active(&mdi_stream_p->lcd_handle);
    if (mdi_stream_p->lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        set_info_data->lcd_id = MAIN_LCD;
    }
    else if (mdi_stream_p->lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        set_info_data->lcd_id = SUB_LCD;
    }
    else
    {
        MMI_ASSERT(0);
    }

    /* check if invalid handle? */
    if (player_layer_handle == GDI_NULL_HANDLE || mdi_stream_p->play_style == MDI_VIDEO_TRACK_A_ONLY)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }

    /* call this function before calling mdi_calc_blt_para() */
    mdi_stream_p->hw_update_layer_handle = player_layer_handle;

    gdi_layer_push_and_set_active(player_layer_handle);
    gdi_layer_get_color_format(&format);
    gdi_layer_get_dimension(&width, &height);
    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_pop_and_restore_active();

    set_info_data->display_width = width;
    set_info_data->display_height = height;
    set_info_data->image_buffer_p = (void*)buf_ptr;
    set_info_data->force_lcd_hw_trigger = (kal_bool)mdi_stream_p->is_enable_partial_display;

    if (format == GDI_COLOR_FORMAT_UYVY422)
    {
        set_info_data->image_data_format = MDI_VIDEO_COLOR_FORMAT_UYVY422;
    }
    else
    {
        set_info_data->image_data_format = MDI_VIDEO_COLOR_FORMAT_RGB565;
    }

    //set_info_data->update_layer = blt_layer_flag;
    gdi_layer_get_blt_layer_flag(&(set_info_data->update_layer));
    ASSERT(set_info_data->update_layer>0);
    set_info_data->hw_update_layer = play_layer_flag;

    gdi_layer_get_actual_rotate_value(player_layer_handle, &rotate);
    switch (rotate)
    {
        case GDI_LAYER_ROTATE_0:
            set_info_data->idp_rotate = 0;
            break;

        case GDI_LAYER_ROTATE_90:
            set_info_data->idp_rotate = 90;
            break;

        case GDI_LAYER_ROTATE_180:
            set_info_data->idp_rotate = 180;
            break;

        case GDI_LAYER_ROTATE_270:
            set_info_data->idp_rotate = 270;
            break;

        default:
            MMI_ASSERT(0);
    }

    set_info_data->frame_mode = (med_frame_enum)mdi_stream_p->frame_mode;
    set_info_data->mode_3d = (mpl_renderer_3d_mode_enum)mdi_stream_p->mode_3d;

    gdi_layer_set_blt_layer_previous();

    gdi_layer_get_layer_element(
        play_layer_flag,
        &set_info_data->layer_element,
        &set_info_data->blt_ctx,
        &set_info_data->blt_dev);


    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_play
 * DESCRIPTION
 *  To start play streaming video.
 * PARAMETERS
 *  player_layer_handle : [IN]Layer handle of playback layer.
 *  blt_layer_flag : [IN]Layers to blt to LCM
 *  play_layer_flag : [IN]Layer for HW to draw
 *  is_visual_update : [IN]To update to LCM or not.
 *  audio_path : [IN]Audio output path.
 *  rotate : [IN]Rotate.
 *  play_finish_callback : [IN]Callback function.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to start play.
 *  MDI_RES_VDOPLY_ERR_DRM_PROHIBITED : Fail to start play due to drm check is prohibited.
 *  MDI_RES_VDOPLY_REACH_STOP_TIME : Fail to start play due to it is stopped due to stop time is reached.
 *  MDI_RES_VDOPLY_ERR_PLAY_FAILED : Fail to start play.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_play(
            gdi_handle player_layer_handle,
            U32 blt_layer_flag,
            U32 play_layer_flag,
            MMI_BOOL is_visual_update,
            U8 audio_path,
            U16 rotate,
            mdi_play_finish_callback play_finish_callback,
            void *user_data)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_set_info_struct set_info_data;
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

#ifdef __DRM_SUPPORT__
    BOOL consume_drm_count = mdi_stream_p->is_drm_consume_count;
    BOOL consume_drm_time = mdi_stream_p->is_drm_consume_time;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_PLAY);
    memset(&set_info_data, 0, sizeof(set_info_data));

#ifdef __DRM_SUPPORT__
    /* reset flag first, will use local veriable as consume count flag */
    mdi_stream_p->is_drm_consume_count = TRUE;
    mdi_stream_p->is_drm_consume_time = TRUE;

    /* consume rights */
    if (mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_PERMITTED)
    {
        MMI_ASSERT(mdi_stream_p->drm_streaming_handle >= FS_NO_ERROR);

        if (!consume_drm_count && consume_drm_time)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_CONSUME_TIME_RIGHT, __LINE__);

            /* will only consume duration rights */
            mdi_stream_p->drm_streaming_id = DRM_consume_timed_rights_with_module(
                                                mdi_stream_p->drm_streaming_handle,
                                                DRM_PERMISSION_PLAY,
                                                mdi_video_stream_drm_consume_callback,
                                                module_id);

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_CONSUMING, __LINE__);
            mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_CONSUMING;
        }
        else if (consume_drm_count && consume_drm_time)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_CONSUME_RIGHT, __LINE__);

            /* will consume count rights and timing rights */
            mdi_stream_p->drm_streaming_id = DRM_consume_rights_with_module(
                                                mdi_stream_p->drm_streaming_handle,
                                                DRM_PERMISSION_PLAY,
                                                mdi_video_stream_drm_consume_callback,
                                                module_id);

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_CONSUMING, __LINE__);
            mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_CONSUMING;
        }
        else if (!consume_drm_count && !consume_drm_time)
        {
            /* do not consume count and time */
        }
        else
        {
            /* cant consume count but not consume time */
            MMI_ASSERT(0);
        }

    }
    else if (mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_PLAY_FINISHED)
    {
        MMI_ASSERT(mdi_stream_p->drm_streaming_handle >= FS_NO_ERROR);

        /* play finished, need validate permission again */
        if (DRM_validate_permission(mdi_stream_p->drm_streaming_handle, NULL, DRM_PERMISSION_PLAY))
        {
            /* has permission, consume rights */
            MMI_ASSERT(mdi_stream_p->drm_streaming_id == MDI_VIDEO_DRM_INVALID_VALUE);
            mdi_stream_p->drm_streaming_id = DRM_consume_rights_with_module(
                                                mdi_stream_p->drm_streaming_handle,
                                                DRM_PERMISSION_PLAY,
                                                mdi_video_stream_drm_consume_callback,
                                                module_id);

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_CONSUMING, __LINE__);
            mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_CONSUMING;
        }
        else
        {
            /* it is DRM file, but no rights */
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_EXIT, __LINE__);
            mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_EXIT;

            /* stop driver's buffering */
            mdi_video_stream_stop_buffering();
            return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
        }
    }
    else if (mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_PAUSED)
    {
        MMI_ASSERT(mdi_stream_p->drm_streaming_handle >= FS_NO_ERROR);
        MMI_ASSERT(mdi_stream_p->drm_streaming_id != MDI_VIDEO_DRM_INVALID_VALUE);

        if (!consume_drm_count)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_RESUME_CONSUME, __LINE__);
            DRM_resume_consume(mdi_stream_p->drm_streaming_id);
        }
        else
        {
            /* stop and consume again */
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_STOP_CONSUME, __LINE__);
            DRM_stop_consume(mdi_stream_p->drm_streaming_id);

            /* play finished, need validate permission again */
            if (DRM_validate_permission(mdi_stream_p->drm_streaming_handle, NULL, DRM_PERMISSION_PLAY))
            {
                /* has permission, consume rights */
                MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_CONSUME_RIGHT, __LINE__);
                mdi_stream_p->drm_streaming_id = DRM_consume_rights_with_module(
                                                    mdi_stream_p->drm_streaming_handle,
                                                    DRM_PERMISSION_PLAY,
                                                    mdi_video_stream_drm_consume_callback,
                                                    module_id);

                MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_CONSUMING, __LINE__);
                mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_CONSUMING;
            }
            else
            {
                /* it is DRM file, but no rights */
                MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_EXIT, __LINE__);
                mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_EXIT;

                /* stop driver's buffering */
                mdi_video_stream_stop_buffering();

                return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
            }
        }

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_CONSUMING, __LINE__);
        mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_CONSUMING;
    }
    else if (mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_EXIT &&
             mdi_stream_p->is_drm_streaming)
    {
        /* stop driver's buffering */
        mdi_video_stream_stop_buffering();

        return MDI_RES_VDOPLY_ERR_DRM_PROHIBITED;
    }
#endif /* __DRM_SUPPORT__ */


#ifdef __MMI_BT_AUDIO_VIA_SCO__
    /* Connect SCO to output audio to BT earpone */
    srv_btsco_connect_audio_via_sco();
#endif

    mdi_stream_p->is_tvout_owner = MMI_FALSE;

    mdi_video_stream_play_finish_callback = play_finish_callback;
    mdi_stream_p->user_data = user_data;
    SetProtocolEventHandler(mdi_video_stream_play_result_hdlr, MSG_ID_MEDIA_STREAM_PLAY_IND);

    if (mdi_stream_p->play_style == MDI_VIDEO_TRACK_AV ||
        mdi_stream_p->play_style == MDI_VIDEO_TRACK_V_ONLY ||
         mdi_stream_p->play_style == MDI_VIDEO_TRACK_NONE)
    {
        mdi_video_stream_prepare_video_param(&set_info_data, player_layer_handle, blt_layer_flag, play_layer_flag, is_visual_update);
        set_info_data.display_device = MED_DISPLAY_TO_MAIN_LCD;
        set_info_data.seq_num = mdi_stream_p->play_seq_num;
        set_info_data.repeats = 1;
        set_info_data.play_audio = (U8)(mdi_stream_p->play_style == MDI_VIDEO_TRACK_V_ONLY ? FALSE : TRUE);
    }
    else
    {
        /* audio only */
        set_info_data.play_audio = (U8)TRUE;
    }

    set_info_data.play_speed = 100;
    set_info_data.audio_path = audio_path;

    /* app want see video or not. */
    mdi_stream_p->is_lcd_update = is_visual_update;

    if (is_visual_update)
    {

        if ((mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_V_ONLY) &&
            (mdi_stream_p->play_style == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_V_ONLY ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_NONE))
        {
            gdi_layer_set_hw_update_layer(mdi_stream_p->hw_update_layer_handle, KAL_TRUE);
            gdi_lcd_set_hw_update(KAL_TRUE);
        }

        set_info_data.display_device = MED_DISPLAY_TO_MAIN_LCD;

    #ifdef __MMI_SUBLCD__
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_freeze(TRUE);
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    #endif /* __MMI_SUBLCD__ */

    }
    else
    {
        set_info_data.display_device = MED_DISPLAY_NONE;
    }

    media_stream_set_info(
        module_id,
        mdi_stream_p->stream_session_id,
        &set_info_data);

    ret = media_stream_play(
            module_id,
            mdi_stream_p->stream_session_id,
            mdi_stream_p->play_seq_num);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    if (ret == MED_RES_OK)
    {
        mdi_stream_p->is_playing = TRUE;
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else
    {

    #ifdef __MMI_SUBLCD__
        /* un-freeze sublcd */
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_freeze(FALSE);
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    #endif /* __MMI_SUBLCD__ */

    #ifdef __DRM_SUPPORT__
        /* pause consume */
        if (mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_CONSUMING)
        {
            ASSERT(mdi_stream_p->drm_streaming_id != MDI_VIDEO_DRM_INVALID_VALUE);

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_PAUSE_CONSUME, __LINE__);
            DRM_pause_consume(mdi_stream_p->drm_streaming_id);

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_PAUSED, __LINE__);
            mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_PAUSED;
        }
    #endif /* __DRM_SUPPORT__ */

        if (mdi_stream_p->is_lcd_update == TRUE)
        {
            if (mdi_stream_p->play_style == MDI_VIDEO_TRACK_AV ||
                 mdi_stream_p->play_style == MDI_VIDEO_TRACK_V_ONLY ||
                 mdi_stream_p->play_style == MDI_VIDEO_TRACK_NONE)
            {
                gdi_lcd_set_hw_update(KAL_FALSE);
            }
        }

        if (ret == MED_RES_STREAM_STOP_TIMEOUT)
        {
            return MDI_RES_VDOPLY_REACH_STOP_TIME;
        }
        else
        {
            return MDI_RES_VDOPLY_ERR_FAILED;
        }
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */

    mdi_stream_p->dummy_counter++;
    mdi_stream_p->dummy_loading_percentage = 0;
    mdi_video_stream_play_finish_callback = play_finish_callback;
    mdi_stream_p->user_data = user_data;

	mdi_video_stream_dummy_play_cyclic();
    gui_start_timer(3000, mdi_video_stream_dummy_play_result_hdlr);

    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */


}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_pause
 * DESCRIPTION
 *  To pause play stream video.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to pause stream play.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to pause stream play.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_pause(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_PAUSE);

    media_stream_switch_screen_videostop(module_id, mdi_stream_p->stream_session_id);

    if (mdi_stream_p->is_lcd_update == TRUE)
    {
        if ((mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_V_ONLY) &&
            (mdi_stream_p->play_style == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_V_ONLY ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_NONE))
        {
            gdi_lcd_set_hw_update(KAL_FALSE);
        }
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_resume
 * DESCRIPTION
 *  To resume playing streaming video
 * PARAMETERS
 *  player_layer_handle : [IN]Layer handle of playback layer.
 *  blt_layer_flag : [IN]Layers to blt to LCM
 *  play_layer_flag : [IN]Layer for HW to draw
 *  is_visual_update : [IN]To update to LCM or not.
 *  audio_path : [IN]Audio output path.
 *  rotate : [IN]Rotate.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to resume stream play.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to resume stream play.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_resume(
            gdi_handle player_layer_handle,
            U32 blt_layer_flag,
            U32 play_layer_flag,
            MMI_BOOL is_visual_update,
            U8 audio_path,
            U16 rotate)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_stream_set_info_struct set_info_data;
    module_type module_id = mdi_video_get_module_id();

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_RESUME);

    mdi_stream_p->is_tvout_owner = MMI_FALSE;

    memset(&set_info_data, 0, sizeof(set_info_data));

    mdi_video_stream_prepare_video_param(&set_info_data, player_layer_handle, blt_layer_flag, play_layer_flag, is_visual_update);

#ifdef __MMI_SUBLCD__
    /* Freeze sublcd */
    if (is_visual_update)
    {
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_freeze(TRUE);
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    }
#endif /* __MMI_SUBLCD__ */

    set_info_data.play_audio = (U8)(mdi_stream_p->play_style == MDI_VIDEO_TRACK_V_ONLY ? FALSE : TRUE);
    set_info_data.play_speed = 100;
    set_info_data.audio_path = audio_path;
    set_info_data.display_device = MED_DISPLAY_TO_MAIN_LCD;
    set_info_data.seq_num = mdi_stream_p->play_seq_num;
    set_info_data.repeats = 1;
    /*
     * Set this to true will force driver to use hw trigger instead of direct couple.
     * Direct couple has better frame rate but cant draw out side of lcd region.
     */
    set_info_data.force_lcd_hw_trigger = (kal_bool)mdi_stream_p->is_enable_partial_display;

    mdi_stream_p->is_lcd_update = is_visual_update;

    if (is_visual_update)
    {
        set_info_data.display_device = MED_DISPLAY_TO_MAIN_LCD;

        if ((mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_V_ONLY) &&
            (mdi_stream_p->play_style == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_V_ONLY ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_NONE))
        {
            gdi_layer_set_hw_update_layer(mdi_stream_p->hw_update_layer_handle, KAL_TRUE);
            gdi_lcd_set_hw_update(KAL_TRUE);
        }

    }
    else
    {
        set_info_data.display_device = MED_DISPLAY_NONE;
    }

    media_stream_set_info(
            module_id,
            mdi_stream_p->stream_session_id,
            &set_info_data);

    media_stream_switch_screen_videostart(module_id, mdi_stream_p->stream_session_id);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOPLY_SUCCEED;

}




/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_play_result_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_stream_play_result_hdlr(void *msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_play_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_PLAY_RESULT_HDLR);
    MMI_ASSERT(mdi_video_stream_play_finish_callback != NULL);

    ind_p = (media_stream_play_ind_struct*)msg_ptr;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ind_p->result);

    /* seq number not match, measn it is already disconnected, ignore this message */
    if (mdi_stream_p->play_seq_num != ind_p->request_id)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);
        return;
    }

    /* not a error, just inform APP */
    if (ind_p->result == MED_RES_AUDIO_TRACK_ERROR)
    {
        mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR, mdi_stream_p->user_data);
        return;
    }
    else if (ind_p->result == MED_RES_VIDEO_TRACK_ERROR)
    {
        mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR, mdi_stream_p->user_data);
        return;
    }

#ifdef __DRM_SUPPORT__
    ASSERT(mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_CONSUMING ||
           mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_EXIT);

    /* stop consume */
    if (mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_CONSUMING)
    {

        if (ind_p->result == MED_RES_STREAM_BUFFER_UNDERFLOW ||
            ind_p->result == MDI_RES_VDOPLY_STREAM_BUFFER_OVERFLOW )
        {
            ASSERT(mdi_stream_p->drm_streaming_id != MDI_VIDEO_DRM_INVALID_VALUE);

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_PAUSE_CONSUME, __LINE__);
            DRM_pause_consume(mdi_stream_p->drm_streaming_id);

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_PAUSED, __LINE__);
            mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_PAUSED;
        }
        else
        {
            ASSERT(mdi_stream_p->drm_streaming_id != MDI_VIDEO_DRM_INVALID_VALUE);
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_STOP_CONSUME, __LINE__);
            DRM_stop_consume(mdi_stream_p->drm_streaming_id);
            mdi_stream_p->drm_streaming_id = MDI_VIDEO_DRM_INVALID_VALUE;

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_PLAY_FINISHED, __LINE__);
            mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_PLAY_FINISHED;
        }

    }
#endif /* __DRM_SUPPORT__ */

    mdi_stream_p->is_playing = FALSE;

    /* un-freeze sublcd */
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_freeze(FALSE);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* __MMI_SUBLCD__ */

    if (mdi_stream_p->is_lcd_update == TRUE)
    {
        if ((mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_V_ONLY) &&
            (mdi_stream_p->play_style == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_V_ONLY ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_NONE))
        {
            gdi_lcd_set_hw_update(KAL_FALSE);
        }
    }

    if (ind_p->result == MED_RES_OK)
    {
        mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_SUCCEED, mdi_stream_p->user_data);
    }
    else
    {
        if (ind_p->result == MED_RES_STREAM_BUFFER_UNDERFLOW)
        {
            mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW, mdi_stream_p->user_data);
        }
        else if (ind_p->result == MED_RES_STREAM_BUFFER_OVERFLOW)
        {
            mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_STREAM_BUFFER_OVERFLOW, mdi_stream_p->user_data);
        }
        else if (ind_p->result == MED_RES_STREAM_STOP_TIMEOUT)
        {
            mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_REACH_STOP_TIME, mdi_stream_p->user_data);
        }
        else if (ind_p->result == MED_RES_STREAM_INVALID_MEDIA)
        {
            mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_ERR_PLAY_FAILED, mdi_stream_p->user_data);
        }
        else if (ind_p->result == MED_RES_STREAM_INVALID_RESOLUTION)
        {
            mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_ERR_INVALID_RESOULTION, mdi_stream_p->user_data);
        }
        else
        {
            mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_ERR_PLAY_FAILED, mdi_stream_p->user_data);
        }
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to stop play.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to stop play.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_stop(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_STOP);
    mdi_stream_p->play_seq_num++;
    mdi_stream_p->is_playing = FALSE;

    ret = media_stream_stop(module_id, mdi_stream_p->stream_session_id);

    if (mdi_stream_p->is_lcd_update == TRUE)
    {
        if ((mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_V_ONLY) &&
            (mdi_stream_p->play_style == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_V_ONLY ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_NONE))
        {
            gdi_lcd_set_hw_update(KAL_FALSE);
        }
    }

    /* un-freeze sublcd */
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_freeze(FALSE);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* __MMI_SUBLCD__ */

#ifdef __DRM_SUPPORT__
    /* pause consume */
    if (mdi_stream_p->drm_streaming_state == MDI_VIDEO_DRM_CONSUMING)
    {
        ASSERT(mdi_stream_p->drm_streaming_id != MDI_VIDEO_DRM_INVALID_VALUE);

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_CALLING_DRM_PAUSE_CONSUME, __LINE__);
        DRM_pause_consume(mdi_stream_p->drm_streaming_id);

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_DRM_ENTER_STATE_PAUSED, __LINE__);
        mdi_stream_p->drm_streaming_state = MDI_VIDEO_DRM_PAUSED;
    }
#endif /* __DRM_SUPPORT__ */

    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    gui_cancel_timer(mdi_video_stream_dummy_play_cyclic);
    gui_cancel_timer(mdi_video_stream_dummy_play_result_hdlr);
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */


}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_buf_percentage
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get buffer percentage of the stream downloaded data.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to get buffer percentage of the stream downloaded data.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_get_buf_percentage(S32 *percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_GET_BUF_PERCENTAGE);

    (*percentage) = (S32)media_stream_get_dl_percentage(
                            module_id,
                            mdi_stream_p->stream_session_id);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PERCENTAGE, *percentage);

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    *percentage = mdi_stream_p->dummy_loading_percentage;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOPLY_SUCCEED;
}

MDI_RESULT mdi_video_stream_get_buf_status(U64 *buffered_time, U32 *buffer_percentage)
{
    module_type module_id = mdi_video_get_module_id();
    media_stream_param_buf_status_struct buf_status;

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_GET_BUF_PERCENTAGE);

    media_stream_get_buf_status(module_id, mdi_stream_p->stream_session_id, &buf_status);

    *buffered_time = buf_status.buffered_time;
    *buffer_percentage = buf_status.buffer_percentage;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PERCENTAGE, *buffered_time);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PERCENTAGE, *buffer_percentage);

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    *buffered_time = 0;
    *buffer_percentage = 0;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_cur_play_time
 * DESCRIPTION
 *
 * PARAMETERS
 *  cur_play_time : [OUT]Current play time.
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_stream_get_cur_play_time(U64 *cur_play_time)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 cur_time;
    kal_int32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_GET_CUR_PLAY_TIME);

    ret = media_stream_get_playing_time(
             module_id,
             mdi_stream_p->stream_session_id,
             &cur_time);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    if (ret == MED_RES_OK)
    {
        *cur_play_time = cur_time;
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_CUR_TIME, (kal_uint32)cur_time);
    }


#else  /* MDI_VIDEO_DRIVER_AVAIALBE */
    *cur_play_time = 0;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_dummy_play_cyclic
 * DESCRIPTION
 *  dummy play result handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_stream_dummy_play_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_stream_p->dummy_cur_time += 100;

    if (mdi_stream_p->dummy_cur_time >= MDI_VIDEO_DUMMY_TOTAL_TIME)
    {
        mdi_stream_p->dummy_cur_time = 0;
        mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_SUCCEED, mdi_stream_p->user_data);
        return;
    }

    gui_start_timer(100, mdi_video_stream_dummy_play_cyclic);

}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */




/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_dummy_play_result_hdlr
 * DESCRIPTION
 *  dummy play result handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_stream_dummy_play_result_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mdi_stream_p->dummy_counter < 3)
    {
        gui_cancel_timer(mdi_video_stream_dummy_play_cyclic);
        mdi_video_stream_play_finish_callback(MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW, mdi_stream_p->user_data);
    }
}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_brightness
 * DESCRIPTION
 *  To set brightness parameter for video player.
 * PARAMETERS
 *  brightness : [IN]Brightness value
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set brightness parameter to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set brightness parameter to video player.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_brightness(U16 brightness)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_set_param_struct data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_SET_BRIGHTNESS, brightness);

    data.param_id = VID_PARAM_BRIGHTNESS;

    switch (brightness)
    {
        case MDI_VIDEO_BRIGHTNESS_N5:
            data.value = 8; /* -120 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N4:
            data.value = 38;    /* -90 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N3:
            data.value = 68;    /* -60 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N2:
            data.value = 98;    /* -30 */
            break;

        case MDI_VIDEO_BRIGHTNESS_N1:
            data.value = 118;   /* -10 */
            break;

        case MDI_VIDEO_BRIGHTNESS_0:
            data.value = 128;   /* 0 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P1:
            data.value = 138;   /* +10 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P2:
            data.value = 158;   /* +30 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P3:
            data.value = 188;   /* +60 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P4:
            data.value = 218;   /* +90 */
            break;

        case MDI_VIDEO_BRIGHTNESS_P5:
            data.value = 248;   /* +120 */
            break;

        default:
            MMI_ASSERT(0);
            break;

    }

    media_stream_set_param(module_id, mdi_stream_p->stream_session_id, &data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_contrast
 * DESCRIPTION
 *  To set contrast parameter to video player.
 * PARAMETERS
 *  contrast : [IN]Contrast value
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set EV parameter to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set EV parameter to video player.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_contrast(U16 contrast)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_set_param_struct data;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_SET_CONTRAST, contrast);

    data.param_id = VID_PARAM_CONTRAST;

    switch (contrast)
    {
        case MDI_VIDEO_CONTRAST_N5:
            data.value = 8; /* -120 */
            break;

        case MDI_VIDEO_CONTRAST_N4:
            data.value = 38;    /* -90 */
            break;

        case MDI_VIDEO_CONTRAST_N3:
            data.value = 68;    /* -60 */
            break;

        case MDI_VIDEO_CONTRAST_N2:
            data.value = 98;    /* -30 */
            break;

        case MDI_VIDEO_CONTRAST_N1:
            data.value = 118;   /* -10 */
            break;

        case MDI_VIDEO_CONTRAST_0:
            data.value = 128;   /* 0 */
            break;

        case MDI_VIDEO_CONTRAST_P1:
            data.value = 138;   /* +10 */
            break;

        case MDI_VIDEO_CONTRAST_P2:
            data.value = 158;   /* +30 */
            break;

        case MDI_VIDEO_CONTRAST_P3:
            data.value = 188;   /* +60 */
            break;

        case MDI_VIDEO_CONTRAST_P4:
            data.value = 218;   /* +90 */
            break;

        case MDI_VIDEO_CONTRAST_P5:
            data.value = 248;   /* +120 */
            break;

        default:
            MMI_ASSERT(0);
            break;

    }

    media_stream_set_param(module_id, mdi_stream_p->stream_session_id, &data);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_dimension
 * DESCRIPTION
 *  Get stream source dimension, this function may only be called after
 *  calling mdi_video_stream_start_buffering, and buf percentage > 0
 * PARAMETERS
 *  video_width : [OUT]video width ptr
 *  video_height : [OUT]video height ptr
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get dimension.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to get dimension.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_get_dimension(S32 *video_width, S32 *video_height)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_stream_get_info_struct stream_info;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = media_stream_get_info(module_id, mdi_stream_p->stream_session_id, &stream_info);

    if (ret == MED_RES_OK)
    {
        *video_width = stream_info.image_width;
        *video_height = stream_info.image_height;
    }
    else
    {
        *video_width = 0;
        *video_height = 0;
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOPLY_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_enable_partial_display
 * DESCRIPTION
 *  To enable video to play outside lcd region.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to enable partial display (outside lcd region) to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to enable partial display (outside lcd region) to video player.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_enable_partial_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_ENABLE_PARTIAL_DISPLAY);

    mdi_stream_p->is_enable_partial_display = TRUE;

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_frame_mode
 * DESCRIPTION
 *  To set stretch mode of video player before playback.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set stretch mode of video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set stretch mode of video player.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_frame_mode(U8 mode)
{
    mdi_stream_p->frame_mode = mode;

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_3d_mode
 * DESCRIPTION
 *  Set 3D mode
 * PARAMETERS
 *  mode : [IN] 3D mode
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set stop time to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set stop time to video player.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_3d_mode(mdi_video_3d_mode_enum mode)
{
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_SET_3D_MODE, mode);

    mdi_stream_p->mode_3d = (U8)mode;

    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_stop_time
 * DESCRIPTION
 *  Set stop time for stream playback, currently for Java use only.
 * PARAMETERS
 *  stop_time : [IN]Stop time
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set stop time to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set stop time to video player.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_stop_time(U64 stop_time)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_SET_STOP_TIME);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STOP_TIME, (U32)stop_time);

    media_stream_set_stop_time(
        module_id,
        mdi_stream_p->stream_session_id,
        stop_time);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_sleep_time
 * DESCRIPTION
 *  Set sleep time, currently for Java use only.
 * PARAMETERS
 *  elapse_ticks : [IN] elapse time to make one sleep operation.
 *  sleep_ticks  : [IN] time duration per sleep.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set sleep time to video player.
 *  MDI_RES_VDOREC_ERR_FAILED : Fail to set sleep time to video player.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_sleep_time(U8 elapse_ticks, U8 sleep_ticks)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_SET_SLEEP_TIME);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_SLEEP_TIME, elapse_ticks, sleep_ticks);

    if (mdi_stream_p->is_stream_init)
    {
        media_stream_set_sleep_time(module_id, mdi_stream_p->stream_session_id, elapse_ticks, sleep_ticks);
        mdi_stream_p->sleep_value.sleep_ticks = sleep_ticks;
        mdi_stream_p->sleep_value.elapse_ticks = elapse_ticks;
    }

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_audio_level
 * DESCRIPTION
 *  To set audio level, used by Java only
 * PARAMETERS
 *  aud_level : [IN]Audio level.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set audio level to video player.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to set audio level to video player.
 *****************************************************************************/
extern MDI_RESULT mdi_video_stream_set_audio_level(U16 aud_level)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(aud_level <= 100);
    media_stream_set_audio_level(module_id, mdi_stream_p->stream_session_id, aud_level);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_is_drm_streaming
 * DESCRIPTION
 *  Check if it is drm stream or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : It is a drm file.
 *  MMI_FALSE : It is not a drm file.
 *****************************************************************************/
MMI_BOOL mdi_video_stream_is_drm_streaming(void)
{
    return (mdi_stream_p->is_drm_streaming == TRUE) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_get_info
 * DESCRIPTION
 *  To get stream audio info.
 * PARAMETERS
 *
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get audio info.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to get audio info.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_get_audio_info(PU8 aud_channel_no, PU16 aud_sample_rate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_stream_get_info_struct stream_info;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mdi_audio_is_speech_mode() && mdi_audio_is_idle())
    {
        /* if not in speech mode and audio is not playing */
        ret = media_stream_get_info(module_id, mdi_stream_p->stream_session_id, &stream_info);
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

        if (ret == MED_RES_OK || ret == MED_RES_STREAM_INVALID_RESOLUTION)
        {
            *aud_channel_no = stream_info.channel_num;
            *aud_sample_rate = stream_info.sampleing_freq;
            return MDI_RES_VDOPLY_SUCCEED;
        }
        else
        {
            return MDI_RES_VDOPLY_ERR_FAILED;
        }
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_stop_visual_update()
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to stop visual update.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to stop visual update.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_stop_visual_update(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_STREAM_PAUSE);

    ret = media_stream_bgplay_videostop(module_id, g_mdi_stream_cntx.stream_session_id);

    if (mdi_stream_p->is_lcd_update == TRUE)
    {
        if ((mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->video_info.track == MDI_VIDEO_TRACK_V_ONLY) &&
            (mdi_stream_p->play_style == MDI_VIDEO_TRACK_AV ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_V_ONLY ||
             mdi_stream_p->play_style == MDI_VIDEO_TRACK_NONE))
        {
            gdi_lcd_set_hw_update(KAL_FALSE);
            mdi_stream_p->is_lcd_update = FALSE;
        }
    }

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

    return MDI_RES_VDOPLY_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_track
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to set track.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to set track.
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_track(kal_uint8 type)
{

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    module_type module_id = mdi_video_get_module_id();
    media_stream_set_track_req_struct track;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {

        case MDI_VIDEO_TRACK_AV:
            track.play_style = MEDIA_STREAM_PLAY_TYPE_BOTH;
            break;

        case MDI_VIDEO_TRACK_A_ONLY:
            track.play_style = MEDIA_STREAM_PLAY_TYPE_AUDIO_ONLY;
            break;

        case MDI_VIDEO_TRACK_V_ONLY:
            track.play_style = MEDIA_STREAM_PLAY_TYPE_VIDEO_ONLY;
            break;

        case MDI_VIDEO_TRACK_NONE:
        default:
            return MDI_RES_VDOPLY_ERR_FAILED;
    }

    ret = media_stream_set_track(module_id, mdi_stream_p->stream_session_id, track);
    if (ret == MED_RES_OK)
    {
        mdi_stream_p->play_style = (mdi_video_track_enum)type;
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
#else
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_stream_set_uaprof
 * DESCRIPTION
 *  set the uaprofile string.
 * PARAMETERS
 *  uaprof_p    [IN]  the profile url string pointer(char)
 * RETURNS
 *  MDI_RES_VDOPLY_SUCCEED if success, otherwise MDI_RES_VDOPLY_ERR_FAILED
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_uaprof(CHAR* uaprof_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (uaprof_p != NULL)
    {
        len = strlen(uaprof_p);
    }

    kal_mem_set(mdi_stream_p->uaprof_str, 0, MDI_VIDEO_STREAM_UAPROF_BUFF_LEN);
    if (len < MDI_VIDEO_STREAM_UAPROF_BUFF_LEN)
    {
        strncpy((kal_char *)mdi_stream_p->uaprof_str, (kal_char *)uaprof_p, MDI_VIDEO_STREAM_UAPROF_BUFF_LEN - 1);
    }

    return MDI_RES_VDOPLY_SUCCEED;
}




/*****************************************************************************
 * FUNCTION
 * mdi_video_stream_set_uaprof_diff
 * DESCRIPTION
 * set the x-wap-profile-diff url string
 * PARAMETERS
 * diff_p       [IN] pointer to the profile diff url string (char)
 * RETURNS
 * MEI_RES_VDOPLY_SUCEED if success, otherwise MDI_RES_VDOPLY_ERR_FAILED
 *****************************************************************************/
MDI_RESULT mdi_video_stream_set_uaprof_diff(CHAR* diff_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (diff_p != NULL)
    {
        len = strlen(diff_p);
    }

    kal_mem_set(mdi_stream_p->uaprof_diff_str, 0, MDI_VIDEO_STREAM_UAPROF_BUFF_LEN);
    if (len < MDI_VIDEO_STREAM_UAPROF_BUFF_LEN)
    {
        strncpy((kal_char *)mdi_stream_p->uaprof_diff_str, (kal_char *)diff_p, MDI_VIDEO_STREAM_UAPROF_BUFF_LEN - 1);
    }

    return MDI_RES_VDOPLY_SUCCEED;
}


#ifdef __MMI_STREAM_REC__
/*****************************************************************************
 *
 * Streaming + record
 *
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 * mdi_video_stream_rec_open
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_stream_rec_open(CHAR* p_file_path)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    module_type module_id = mdi_video_get_module_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = media_stream_rec_open(module_id, mdi_stream_p->stream_session_id, (kal_wchar *)p_file_path);

    switch (ret)
    {
        case MED_RES_DISC_FULL:
            return MDI_RES_STREAM_REC_ERR_DISK_FULL;
            break;

        case MED_RES_OK:
            return MDI_RES_STREAM_REC_SUCCEED;
            break;

        case MED_RES_STREAM_INVALID_SDP:
        case MED_RES_STREAM_UNSUPPORTED_CODEC:
            return MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT;
            break;

        default:
            return MDI_RES_STREAM_REC_ERR_FAILED;
            break;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 * mdi_video_stream_rec_close
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_stream_rec_close(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    module_type module_id = mdi_video_get_module_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = media_stream_rec_close(module_id, mdi_stream_p->stream_session_id);

    switch(ret)
    {
        default:
            return ret;
            break;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 * mdi_vdieo_stream_rec_save_result_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
static void mdi_video_stream_rec_save_result_hdlr(void * msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stream_rec_save_ind_struct *local = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local = (media_stream_rec_save_ind_struct *) msg_ptr;

    if (local->session_id != mdi_stream_p->stream_session_id)
    {
        /* ignore, print message */
        return;
    }
    switch (local->result)
    {
        case MED_RES_OK:
            mdi_video_stream_rec_result_callback(MDI_RES_STREAM_REC_SUCCEED);
            break;

        case MED_RES_DISC_FULL:
            mdi_video_stream_rec_result_callback(MDI_RES_STREAM_REC_ERR_DISK_FULL);
            break;

        case MED_RES_STREAM_REC_DUR_TOO_SHORT:
            mdi_video_stream_rec_result_callback(MDI_RES_STREAM_REC_ERR_DURATION_TOO_SHORT);
            break;

        default:
    #ifdef __DRM_SUPPORT__
            if(local->result < DRM_RESULT_BEGIN && local->result > DRM_RESULT_INVALID)
            {
                mdi_video_stream_rec_result_callback(local->result);
                return;
            }
    #endif /* __DRM_SUPPORT__ */
            mdi_video_stream_rec_result_callback(MDI_RES_STREAM_REC_ERR_FAILED);
            break;
    }
#else
    mdi_video_stream_rec_result_callback(MDI_RES_VDOPLY_SUCCEED);
#endif
}


/*****************************************************************************
 * FUNCTION
 * mdi_video_stream_rec_save
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_stream_rec_save(CHAR* p_file_path, void(* save_result_callback)(MDI_RESULT))
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    module_type module_id = mdi_video_get_module_id();
    CHAR* p_filename;
    CHAR* filename_ext;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_filename = OslMalloc(SRV_FMGR_PATH_BUFFER_SIZE);
    /* generate a file name */
    mdi_get_ucs2_filename(p_filename, SRV_FMGR_PATH_MAX_LEN, p_file_path, MDI_NAMING_TYPE_DDMMYY_HHMM,FMGR_TYPE_MP4);
    filename_ext = srv_fmgr_path_get_extension_ptr(p_filename);
    /* Hide all extension */
    filename_ext -= 2;
    filename_ext[0] = filename_ext[1] = 0;
    ret = media_stream_rec_save(module_id, mdi_stream_p->stream_session_id, (kal_wchar *)srv_fmgr_path_get_filename_ptr(p_filename));
    OslMfree(p_filename);

    SetProtocolEventHandler(mdi_video_stream_rec_save_result_hdlr, MSG_ID_MEDIA_STREAM_REC_SAVE_IND);

    switch(ret)
    {
        default:
            mdi_video_stream_rec_result_callback = save_result_callback;
            return ret;
            break;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    mdi_video_stream_rec_result_callback = save_result_callback;
    gui_start_timer_ex(2000, mdi_video_stream_rec_result_callback, MDI_RES_VDOPLY_SUCCEED);

    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 * mdi_video_stream_rec_save_abort
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_video_stream_rec_save_abort(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    module_type module_id = mdi_video_get_module_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = media_stream_rec_save_abort(module_id, mdi_stream_p->stream_session_id);
    ClearProtocolEventHandler(MSG_ID_MEDIA_STREAM_REC_SAVE_IND);
    switch(ret)
    {
        default:
            return ret;
            break;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 * mdi_video_stream_rec_have_unsaved_file
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mdi_video_stream_rec_have_unsaved_file(CHAR* dir)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (media_stream_rec_check_unsave_file((kal_wchar *) dir) == MED_RES_OK)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MMI_FALSE;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 * mdi_video_stream_rec_delete_unsaved_file
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
void mdi_video_stream_rec_delete_unsaved_file(CHAR* dir)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_stream_rec_delete_unsaved_file((kal_char *) dir);

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}
#endif /* __MMI_STREAM_REC__ */

#ifdef __MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

#endif /* __MMI_VIDEO_STREAM__ */


/*****************************************************************************
 *
 * Progressive Download
 *
 *****************************************************************************/
 #ifdef __MMI_VIDEO_PDL__
 /*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_open_file
 * DESCRIPTION
 *  To open progressive vidoe file.
 * PARAMETERS
 *  filename : [IN]Filename of the video.
 *  progressive_result_callback : [IN]Callback function of this open operation.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to open video file, need to wait callback function when open operation is finished.
 *  MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT : Fail to open video file due to memory is insufficient.
 *  MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to open video file.
 *****************************************************************************/
MDI_RESULT mdi_video_progressive_open_file(
            const U16 app_id,
            const CHAR *filename,
            mdi_progressive_result_callback progressive_result_callback,
            void *user_data)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    media_vid_open_req_struct open_data = {0};
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PROGRESSIVE_OPEN_FILE);

    ret = MED_RES_FAIL;
#ifdef __DRM_SUPPORT__
    /* set need seek flag */
    mdi_video_p->is_drm_file = FALSE;
#endif
    mdi_video_ply_open_file_result_callback = progressive_result_callback;

    SetProtocolEventHandler(mdi_video_ply_open_file_result_hdlr, MSG_ID_MEDIA_VID_FILE_READY_IND);

    open_data.media_mode = MED_MODE_PDL_FILE;
    open_data.media_type = mdi_video_ply_get_media_type(filename);
    open_data.enable_aud_only = KAL_TRUE;
    open_data.data = (void*)filename;

    open_data.scenario = mdi_video_p->scenario;
    mdi_video_p->scenario = MPL_DECODER;
#ifdef __GAIN_TABLE_SUPPORT__
    mdi_video_p->media_type = open_data.media_type;
#endif
#ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
    mdi_video_p->frame_mode = MDI_VIDEO_FRAME_MODE_FIT_INSIDE;
#else /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */
    mdi_video_p->frame_mode = MDI_VIDEO_FRAME_MODE_STRETCH;
#endif /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */

    mdi_video_p->is_seek_after_open = FALSE;

    open_data.open_track = MED_VID_BOTH;
    open_data.seq_num = mdi_video_p->open_seq_num;
    open_data.blocking = FALSE; /* no blocking */

    /* following 6 parameters are used for blocking function */
    open_data.image_width = NULL;
    open_data.image_height = NULL;
    open_data.total_time = NULL;
    open_data.handle = NULL;
    open_data.file_handle = NULL;
    open_data.is_seekable = NULL;
#ifdef __MMI_VIDEO_CLIPPER__
    open_data.is_proprietary = NULL;
#endif
    open_data.app_id = app_id;

    ret = media_vid_open(module_id, &open_data);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    if (ret != MED_RES_OK)
    {
        if (ret == MED_RES_MEM_INSUFFICIENT)
        {
            return MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT;
        }
        else
        {
            return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
        }
    }
    else
    {
        mdi_video_p->user_data = user_data;

    #ifdef __MM_DCM_SUPPORT__
        mdi_video_ply_dcm_load();
    #endif    
        return MDI_RES_VDOPLY_SUCCEED;
    }
#else /* MDI_VIDEO_DRIVER_AVAIALBE */

    mdi_video_ply_open_file_result_callback = progressive_result_callback;
    gui_start_timer(6000, mdi_video_progressive_dummy_open_file_result_hdlr);

    mdi_video_p->dummy_cur_time = 0;
    mdi_video_p->dummy_max_play_time = MDI_VIDEO_DUMMY_TOTAL_TIME;
    mdi_video_p->dummy_loading_percentage = 0;
    mdi_video_p->user_data = user_data;
    mdi_video_progressive_dummy_loading_cyclic();

    return MDI_RES_VDOPLY_SUCCEED;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_close_file
 * DESCRIPTION
 *  To close the progressive video file.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to close progressive download file.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to close progressive download file.
 *****************************************************************************/
MDI_RESULT mdi_video_progressive_close_file(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PROGRESSIVE_CLOSE_FILE);

    mdi_video_p->open_seq_num++;
    media_vid_close(module_id);

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    gui_cancel_timer(mdi_video_progressive_dummy_loading_cyclic);
    gui_cancel_timer(mdi_video_progressive_dummy_open_file_result_hdlr);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

#ifdef __MM_DCM_SUPPORT__
    mdi_video_ply_dcm_unload();
#endif 

    /* close file shall always succeed */
    return MDI_RES_VDOPLY_SUCCEED;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_get_max_play_time
 * DESCRIPTION
 *  To get the max play time of this progressive downloading file.
 * PARAMETERS
 *  max_play_time : [OUT]Max play time of this progressive downloading file.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get max play time.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to get max play time.
 *****************************************************************************/
MDI_RESULT mdi_video_progressive_get_max_play_time(U64 *max_play_time)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_pdl_max_time_req_struct time_data;
    U64 max_time;
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PROGRESSIVE_GET_MAX_PLAY_TIME);

    time_data.max_time_p = &max_time;
    ret = media_vid_get_pdl_max_time(module_id, &time_data);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    *max_play_time = max_time;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MAX_TIME, max_time);

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    *max_play_time = mdi_video_p->dummy_max_play_time;
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */


}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_get_buf_percentage
 * DESCRIPTION
 *  To get current downloaded buffer percentage.
 * PARAMETERS
 *  buf_percentage : [OUT]Current buffer percentage.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to get buffer percentage.
 *  MDI_RES_VDORLY_ERR_FAILED : Fail to get buffer percentage.
 *****************************************************************************/
MDI_RESULT mdi_video_progressive_get_buf_percentage(S32 *buf_percentage)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_pdl_percent_req_struct percent_data;
    U32 precent;
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PROGRESSIVE_GET_BUF_PERCENTAGE);

    percent_data.percent_p = &precent;
    ret = media_vid_get_pdl_percent(module_id, &percent_data);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    *buf_percentage = (S32)precent;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PERCENTAGE, precent);

    if (ret != MED_RES_OK)
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    *buf_percentage = mdi_video_p->dummy_loading_percentage;
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */


}



/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_is_pdl_format
 * DESCRIPTION
 *  To check if this video file is in progresssive download support format.
 * PARAMETERS
 *  file_buffer : [IN]Filepath of the specific video file.
 *  buf_size : [IN]Buffer size of the file buffer.
 *  is_pdl : [OUT]Is this file is progressive download format.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to check this file.
 *  MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED : Fail to check this file due to fail to open it.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to check this file.
 *****************************************************************************/
MDI_RESULT mdi_video_progressive_is_pdl_format(U8 *file_buffer, S32 buf_size, MMI_BOOL *is_pdl)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_check_is_pdl_req_struct check_data;
    S32 ret;
    module_type module_id = mdi_video_get_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PROGRESSIVE_IS_PDL_FORMAT);

    *is_pdl = MMI_FALSE;
    check_data.file_buf_p = (kal_uint8*)file_buffer;
    check_data.buf_size = (kal_uint32)buf_size;
    ret = media_vid_check_is_pdl_file(module_id, &check_data);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret);

    if (ret == MED_RES_OK)
    {
        *is_pdl = MMI_TRUE;
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else if (ret == MED_RES_OPEN_FILE_FAIL)
    {
        return MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    *is_pdl = MMI_TRUE;
    return MDI_RES_VDOPLY_SUCCEED;
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_scramble_buffer
 * DESCRIPTION
 *  To scramble buffer
 * PARAMETERS
 *  file_buffer : [IN]Filepath of the specific video file.
 *  buf_size : [IN]Buffer size of the file buffer.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to check this file.
 *  MDI_RES_VDOPLY_ERR_FAILED : Fail to check this file.
 *****************************************************************************/
MDI_RESULT mdi_video_progressive_scramble_buffer(U8 *file_buffer, S32 buf_size)
{
#ifdef __MMI_VIDEO_PDL_YOUTUBE__
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = mdi_video_get_module_id();
    media_vid_set_param_req_struct data;
    media_vid_param_scramble_buffer_struct param;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_PLY_SET_SUBTITLE_TRACK_INDEX, index);

    param.buf_ptr = file_buffer;
    param.buf_size = buf_size;
    
    data.param_id = VID_PARAM_SCRAMBLE_BUFFER;
    data.value = (void *)&param;
    ret = media_vid_set_param(module_id, &data);

    if (ret == MED_RES_OK)
    {
        return MDI_RES_VDOPLY_SUCCEED;
    }
    else
    {
        return MDI_RES_VDOPLY_ERR_FAILED;
    }
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
#endif /* __MMI_VIDEO_PDL_YOUTUBE__ */
    /* always succeed */
    return MDI_RES_VDOPLY_SUCCEED;


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
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_progressive_dummy_loading_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_video_p->dummy_loading_percentage < 100)
    {
        mdi_video_p->dummy_loading_percentage += 10;
        gui_start_timer(300, mdi_video_progressive_dummy_loading_cyclic);
    }

    if (mdi_video_p->dummy_max_play_time < MDI_VIDEO_DUMMY_TOTAL_TIME)
    {
        mdi_video_p->dummy_max_play_time += 100;
        gui_start_timer(300, mdi_video_progressive_dummy_loading_cyclic);
    }
}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */


/*****************************************************************************
 * FUNCTION
 *  mdi_video_progressive_dummy_open_file_result_hdlr
 * DESCRIPTION
 *  dummy open file result handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef MDI_VIDEO_DRIVER_AVAIALBE
static void mdi_video_progressive_dummy_open_file_result_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_info_struct vdo_clip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vdo_clip.width = 176;
    vdo_clip.height = 144;
    vdo_clip.total_time_duration = MDI_VIDEO_DUMMY_TOTAL_TIME;
    mdi_video_p->dummy_is_pdl = TRUE;

    mdi_video_ply_open_file_result_callback(MDI_RES_VDOPLY_SUCCEED, &vdo_clip, 0);
}
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */


#ifdef __MMI_OP11_PDL_FROM_SDP__
/*****************************************************************************
 * FUNCTION
 *  mdi_sdp_get_ext_mem
 * DESCRIPTION
 *  get memory
 * PARAMETERS
 *  size                [IN]        size
 * RETURNS
 *  void
 *****************************************************************************/
void *mdi_sdp_get_ext_mem(kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(size > 0);

    ptr = (void*) med_alloc_ext_mem(size);

    ASSERT(ptr != NULL);
    return(ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_sdp_free_ext_mem
 * DESCRIPTION
 *  free memory
 * PARAMETERS
 *  buffer              [IN]        buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_sdp_free_ext_mem(void *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_free_ext_mem((void * *)&buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_sdp_fill_pdl_info
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
mdi_result mdi_sdp_fill_pdl_info(sdp_message_struct *sdp_p, mdi_sdp_pdl_info *pdl_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *attrib_p;
    kal_bool is_present;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check scheme */
    memset(pdl_info_p->url, 0, MDI_SDP_MAX_URL_LEN);
    is_present = sdp_msg_get_attribute(&sdp_p->a, "control", &attrib_p, 0);
    if (is_present)
    {
        strncpy((kal_char *)pdl_info_p->url, attrib_p, MDI_SDP_MAX_URL_LEN);
    }
    else
    {
        return MDI_RES_SDP_INVALID_FORMAT;
    }

    /* check parameters */
    /* size */
    pdl_info_p->byte_fsize = 0;
    is_present = sdp_msg_get_attribute(&sdp_p->a, MDI_SDP_ATTRIB_FSIZE, &attrib_p, 0);
    if (is_present)
    {
        pdl_info_p->byte_fsize = atoi(attrib_p);
    }

    /* forwardable */
    pdl_info_p->x_forward_allowed = sdp_msg_get_attribute(&sdp_p->a, MDI_SDP_ATTRIB_FWALLOW, &attrib_p, 0);

    /* saveable */
    pdl_info_p->x_purge = sdp_msg_get_attribute(&sdp_p->a, MDI_SDP_ATTRIB_PURGE, &attrib_p, 0);

    return MDI_RES_SDP_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  stream_parse_sdp_file
 * DESCRIPTION
 *  parse SDP file
 * PARAMETERS
 *  session_id          [IN]        session id
 * RETURNS
 *  stream handle / failure
 *****************************************************************************/
mdi_result mdi_sdp_open_pdl_sdp_file(kal_wchar *fp_p, mdi_sdp_pdl_info *pdl_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sdp_message_struct *sdp;
    kal_char *fbuffer_p;
    FS_HANDLE fh, fs_ret;
    kal_uint32 byte_fsize;
    kal_uint32 ret;
    kal_char *scheme_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fh = FS_Open(fp_p, FS_READ_ONLY);
    if (fh < FS_NO_ERROR)
    {
        return MDI_RES_SDP_ERR_OPEN_FILE_FAILED;
    }

    fs_ret = FS_GetFileSize(fh, &byte_fsize);
    if ((byte_fsize == 0) || (byte_fsize > MDI_SDP_MAX_FILE_SIZE) || (fs_ret < 0) )
    {
        FS_Close(fh);
        return MDI_RES_SDP_ERR_FILE_TOO_LARGE;
    }

    sdp = (sdp_message_struct *)mdi_sdp_get_ext_mem(sizeof(sdp_message_struct));
    if (sdp == NULL)
    {
        FS_Close(fh);
        return MDI_RES_SDP_MEMORY_NOT_ENOUGH;
    }

    fbuffer_p = mdi_sdp_get_ext_mem(byte_fsize + 2);
    if (fbuffer_p == NULL)
    {
        FS_Close(fh);
        mdi_sdp_free_ext_mem((void *) sdp);
        return MDI_RES_SDP_MEMORY_NOT_ENOUGH;
    }

    fs_ret = FS_Read(fh, fbuffer_p, byte_fsize, &ret);
    FS_Close(fh);

    ret = sdp_msg_initialize(sdp, mdi_sdp_get_ext_mem, mdi_sdp_free_ext_mem);
    if (ret != SDP_OK)
    {
        med_free_ext_mem((void * *)&fbuffer_p);
        med_free_ext_mem((void * *)&sdp);
        return(MDI_RES_SDP_INVALID_FORMAT);
    }

    ret = sdp_msg_unpack(sdp, fbuffer_p, byte_fsize, NULL);
    if (ret != SDP_OK)
    {
        sdp_msg_deinitialize(sdp);
        med_free_ext_mem((void * *)&fbuffer_p);
        med_free_ext_mem((void * *)&sdp);
        return(MDI_RES_SDP_NON_PDL_FORMAT);
    }

    ret = mdi_sdp_fill_pdl_info(sdp, pdl_info);

    /* match url scheme */
    scheme_p = strstr((kal_char *)pdl_info->url, (kal_char *)"http://");
    if (scheme_p != pdl_info->url)
    {
        sdp_msg_deinitialize(sdp);
        med_free_ext_mem((void * *)&fbuffer_p);
        med_free_ext_mem((void * *)&sdp);
        return(MDI_RES_SDP_NON_PDL_FORMAT);
    }

    sdp_msg_deinitialize(sdp);
    med_free_ext_mem((void * *)&fbuffer_p);
    med_free_ext_mem((void * *)&sdp);

    return MDI_RES_SDP_SUCCEED;
}
#endif /* __MMI_OP11_PDL_FROM_SDP__ */


#endif /* __MMI_VIDEO_PDL__ */




/****************************************************************************
*
* VIDEO TELEPHONY
*
*****************************************************************************/
#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_load_default_setting
 * DESCRIPTION
 *  Initialize default setting value for video preview/record structure.
 * PARAMETERS
 *  setting_p : [OUT]Setting data (All member data in its default values).
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_tel_load_default_setting(mdi_video_setting_struct *setting_p)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CUSTOM_VENC_USER_T eUser;
    kal_uint32 num_of_entry = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    eUser = CUSTOM_VENC_USER_VT_MPEG4;
    CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_USER,&eUser, sizeof(eUser), NULL, 0);
    CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_NUM_OF_ENTRIES, NULL, 0, &num_of_entry, sizeof(num_of_entry));

    setting_p->wb = MDI_VIDEO_WB_AUTO;
    setting_p->ev = MDI_VIDEO_EV_0;
    setting_p->banding = MDI_VIDEO_BANDING_60HZ; /* TW: 60, CN: 50 */
    setting_p->effect = MDI_VIDEO_EFFECT_NOMRAL;
    setting_p->zoom = 0;
    setting_p->brightness = MDI_VIDEO_IE_LEVEL_MEDIUM;
    setting_p->contrast = MDI_VIDEO_IE_LEVEL_MEDIUM;
    setting_p->saturation = MDI_VIDEO_IE_LEVEL_MEDIUM;
    setting_p->hue = 0;
    setting_p->preview_rotate = MDI_VIDEO_PREVIEW_ROTATE_0;
    setting_p->lcm_rotate = MDI_LCD_ROTATE_0;

    setting_p->night = 0;

    setting_p->video_size = MDI_VIDEO_REC_RESOLUTION_176x144;
    setting_p->video_qty = MDI_VIDEO_REC_QTY_NORMAL;
    setting_p->size_limit = 0;
    setting_p->time_limit = 0;
    setting_p->record_aud = 1; /* TRUE */
    setting_p->video_format = MDI_VIDEO_VIDEO_FORMAT_3GP;
    setting_p->user_def_width = 0;
    setting_p->user_def_height = 0;

    setting_p->overlay_frame_mode = FALSE;
    setting_p->overlay_frame_depth = 0;
    setting_p->overlay_frame_source_key = 0;
    setting_p->overlay_frame_width = 0;
    setting_p->overlay_frame_height = 0;
    setting_p->overlay_frame_buffer_address = 0;

    setting_p->dsc_mode = MDI_VIDEO_SCENE_MODE_AUTO;
    setting_p->af_operation_mode = MDI_VIDEO_AF_OPERATION_MODE_SINGLE_ZONE;
    setting_p->af_range = MDI_VIDEO_AF_RANGE_AUTO;
    setting_p->sharpness = MDI_VIDEO_IE_LEVEL_MEDIUM;
    setting_p->storage = MDI_VIDEO_REC_STORAGE_PHONE;
    
    setting_p->notify_peer_on_camera_off = FALSE;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_start
 * DESCRIPTION
 *  To start video telephony preview / decode
 * PARAMETERS
 *  peer_layer_handle           [IN]        peer display layer handle
 *  local_layer_handle          [IN]        local display layer handle
 *  peer_disp_type              [IN]        peer display type
 *  local_disp_type             [IN]        local display type
 *  blt_laye_flag               [IN]        which layers will be blt to lcd by driver
 *  peer_layer_flag             [IN]        which layer is for peer display
 *  local_layer_flag            [IN]        which layer is for local display
 *  local_preview_p             [IN]        local preview video settings
 *  event_callback              [IN]        call back function
 * RETURN VALUES
 *  MDI_RES_VDOTEL_SUCCEED : Succeed to start video telephony service.
 *  MDI_RES_VDOTEL_ERR_FAILED : Fail to start video telephony service.
 *****************************************************************************/
MDI_RESULT mdi_video_tel_start(
            gdi_handle peer_layer_handle,
            gdi_handle local_layer_handle,
            mdi_video_tel_disp_type_enum peer_disp_type,
            mdi_video_tel_disp_type_enum local_disp_type,
            U32 blt_layer_flag,
            U32 peer_layer_flag,
            U32 local_layer_flag,
            mdi_video_setting_struct *local_preview_setting_p,
            const U16 app_id,
            mdi_video_tel_event_callback event_callback,
            void* callback_userdata)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_record_struct local_data;
    media_vcall_playback_struct peer_data;
    media_vcall_view_type_enum local_type = VCALL_VIEW_HIDE;
    media_vcall_view_type_enum peer_type = VCALL_VIEW_HIDE;
    mdi_blt_para_struct blt_data;
    S32 ret;
    mdi_camera_zoom_info zoom_info;
    U8 physical_rotate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_tel_codec_event_callback = event_callback;
    mdi_video_tel_codec_event_callback_data = callback_userdata;

    /* use sw jpeg for prevent from HW resource conflict */
    gdi_image_jpeg_set_force_use_swjpeg(KAL_TRUE);
    
    SetProtocolEventHandler(
        mdi_video_tel_codec_event_ind_hdlr,
        MSG_ID_MEDIA_VCALL_VIDEO_CODEC_REPORT_IND);

    /* store video's parameters */
    memcpy(video_setting_p, local_preview_setting_p, sizeof(mdi_video_setting_struct));

    memset((void*)&local_data, 0, sizeof(media_vcall_record_struct));
    memset((void*)&peer_data, 0, sizeof(media_vcall_playback_struct));

    local_data.memory_allocator = peer_data.memory_allocator = app_id;

    gdi_lcd_get_active(&mdi_video_p->lcd_handle);


    ret = mdi_video_detect_sensor_id(mdi_video_p->cam_id);

    if (ret != MDI_RES_VDOREC_SUCCEED)
    {
        mdi_video_p->cam_id = MDI_VIDEO_MAIN_SENSOR;
        return MDI_RES_VDOTEL_ERR_FAILED;
    }

    g_mdi_video_tel_cntx.local_layer_handle = local_layer_handle;
    g_mdi_video_tel_cntx.peer_layer_handle = peer_layer_handle;

    /*******************************
     *        LOCAL DISPLAY        *
     *******************************/
    gdi_layer_get_layer_element(
        local_layer_flag,
        &local_data.layer_element,
        &local_data.blt_ctx,
        &local_data.blt_dev);

    gdi_layer_get_actual_rotate_value(local_layer_handle, &physical_rotate);
    local_data.ui_rotate = mdi_util_remapping_layer_rotate_to_cal_rotate(physical_rotate);

    if (MDI_VIDEO_TEL_DISPLAY_VIDEO == local_disp_type ||
        MDI_VIDEO_TEL_DISPLAY_IMAGE == local_disp_type)
    {
        /* common data */
        mdi_calc_blt_para(
            local_layer_handle,
            MDI_LCD_ROTATE_0,
            mdi_video_p->lcd_handle,
            MMI_FALSE,
            &blt_data);

    #if defined(ISP_SUPPORT)
        switch (video_setting_p->video_size)
        {
            case MDI_VIDEO_VIDEO_SIZE_SQCIF:
                local_data.encode_width = 128;
                local_data.encode_height = 96;
                break;

            case MDI_VIDEO_VIDEO_SIZE_QQVGA:
                MMI_ASSERT(0); /* currently not support */
                local_data.encode_width = 160;
                local_data.encode_height = 120;
                break;

            case MDI_VIDEO_VIDEO_SIZE_QCIF:
                local_data.encode_width = 176;
                local_data.encode_height = 144;
                break;

            case MDI_VIDEO_VIDEO_SIZE_CIF:
                MMI_ASSERT(0); /* currently not support */
                local_data.encode_width = 352;
                local_data.encode_height = 288;
                break;

            case MDI_VIDEO_VIDEO_SIZE_USER_DEFINE:
                MMI_ASSERT(0); /* currently not support */
                local_data.encode_width = video_setting_p->user_def_width;
                local_data.encode_height = video_setting_p->user_def_height;
                break;
            default:
                ASSERT(0);
        }

    #endif /* ISP_SUPPORT */

        local_data.preview_width = blt_data.display_width;
        local_data.preview_height = blt_data.display_height;
        local_data.preview_buffer_p = blt_data.image_buffer_p;
        local_data.preview_buffer_size = blt_data.image_buffer_size;
        local_data.cam_id = mdi_video_p->cam_id;
    }


    if (MDI_VIDEO_TEL_DISPLAY_VIDEO == local_disp_type)
    {
        local_type = VCALL_VIEW_SHOW_VIDEO;

        /* NOTE!! currently do not support lcd rotation */
        MMI_ASSERT(video_setting_p->lcm_rotate == MDI_LCD_ROTATE_0);
        mdi_video_tel_query_zoom_info(&zoom_info);

        local_data.zoom_step = video_setting_p->zoom;
        local_data.exposure = video_setting_p->ev;
        local_data.contrast = video_setting_p->contrast;
        local_data.saturation = video_setting_p->saturation;
        local_data.sharpness = video_setting_p->sharpness;
        local_data.hue = video_setting_p->hue;
        local_data.WB = video_setting_p->wb;
        local_data.effect = video_setting_p->effect;
        local_data.dsc_mode = MDI_VIDEO_SCENE_MODE_AUTO;
        local_data.af_operation_mode = MDI_VIDEO_AF_OPERATION_MODE_SINGLE_ZONE;
        local_data.af_range = MDI_VIDEO_AF_RANGE_AUTO;

        local_data.banding_freq = (U8)video_setting_p->banding;
        local_data.encode_quality = (U8)video_setting_p->video_qty;
        local_data.seq_num = mdi_video_p->vt_seq_num;

        local_data.lcd_id = MAIN_LCD;

        local_data.notify_peer = video_setting_p->notify_peer_on_camera_off;
        
        if(video_setting_p->night == 1)
        {
            local_data.night_mode = KAL_TRUE;
        }
        else
        {
            local_data.night_mode = KAL_FALSE;
        }


        /* update to lcd or not */
        if (local_layer_flag == 0)
        {
            local_data.lcd_update = KAL_FALSE;
        }
        else
        {
            local_data.lcd_update = KAL_TRUE;
        }

        if (blt_data.image_color_format == GDI_COLOR_FORMAT_UYVY422)
        {
            local_data.image_data_format = MM_IMAGE_FORMAT_PACKET_UYVY422;
        }
        else
        {
            local_data.image_data_format = MM_IMAGE_FORMAT_RGB565;
        }

    }
    else if (MDI_VIDEO_TEL_DISPLAY_IMAGE == local_disp_type)
    {
        local_type = VCALL_VIEW_SHOW_IMAGE;

        /* encoder qty */
        local_data.encode_quality = (U8)video_setting_p->video_qty;
        local_data.seq_num = mdi_video_p->vt_seq_num;

        local_data.notify_peer = video_setting_p->notify_peer_on_camera_off;
        
        /* update to lcd or not */
        if (local_layer_flag == 0)
        {
            local_data.lcd_update = KAL_FALSE;
        }
        else
        {
            local_data.lcd_update = KAL_TRUE;
        }

    }
    else if(MDI_VIDEO_TEL_DISPLAY_HIDE == local_disp_type)
    {
        local_type = VCALL_VIEW_HIDE;

        local_data.notify_peer = video_setting_p->notify_peer_on_camera_off;
        
        /* encoder qty */
        local_data.encode_quality = (U8)video_setting_p->video_qty;
        local_data.seq_num = mdi_video_p->vt_seq_num;
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }

    g_mdi_video_tel_cntx.local_layer_w = local_data.preview_width;
    g_mdi_video_tel_cntx.local_layer_h = local_data.preview_height;


    /*******************************
     *         PEER DISPLAY        *
     *******************************/
    gdi_layer_get_layer_element(
        peer_layer_flag,
        &peer_data.layer_element,
        &peer_data.blt_ctx,
        &peer_data.blt_dev);

    gdi_layer_get_actual_rotate_value(peer_layer_handle, &physical_rotate);
    peer_data.ui_rotate = mdi_util_remapping_layer_rotate_to_cal_rotate(physical_rotate);

    if (MDI_VIDEO_TEL_DISPLAY_VIDEO == peer_disp_type ||
        MDI_VIDEO_TEL_DISPLAY_IMAGE == peer_disp_type)
    {
        /* calc blt paramters */
        mdi_calc_blt_para(
            peer_layer_handle,
            MDI_LCD_ROTATE_0,
            mdi_video_p->lcd_handle,
            MMI_FALSE,
            &blt_data);

        if (MDI_VIDEO_TEL_DISPLAY_VIDEO == peer_disp_type)
        {
            peer_type = VCALL_VIEW_SHOW_VIDEO;
        }
        else if (MDI_VIDEO_TEL_DISPLAY_IMAGE == peer_disp_type)
        {
            peer_type = VCALL_VIEW_SHOW_IMAGE;
        }
        else
        {
            MMI_ASSERT(0);
        }

        peer_data.display_width = blt_data.display_width;
        peer_data.display_height = blt_data.display_height;
        peer_data.display_buffer_p = (void*)blt_data.image_buffer_p;
        peer_data.display_buffer_size = blt_data.image_buffer_size;
        peer_data.seq_num = mdi_video_p->vt_seq_num;

        peer_data.lcd_id = MAIN_LCD;
        peer_data.lcd_start_x = blt_data.lcd_start_x;
        peer_data.lcd_start_y = blt_data.lcd_start_y;
        peer_data.lcd_end_x = blt_data.lcd_end_x;
        peer_data.lcd_end_y = blt_data.lcd_end_y;
        peer_data.roi_offset_x = blt_data.roi_offset_x;
        peer_data.roi_offset_y = blt_data.roi_offset_y;
        gdi_layer_get_blt_layer_flag(&(peer_data.update_layer ));
        ASSERT(peer_data.update_layer >0);
        peer_data.hw_update_layer = peer_layer_flag;
        if (blt_data.image_color_format == GDI_COLOR_FORMAT_UYVY422)
        {
            peer_data.image_data_format = MM_IMAGE_FORMAT_PACKET_UYVY422;
        }
        else
        {
            peer_data.image_data_format = MM_IMAGE_FORMAT_RGB565;
        }
        peer_data.peer_enc_qty = video_setting_p->peer_enc_qty;
        peer_data.roi_background_color = GDI_COLOR_BLACK;

    }
    else if(MDI_VIDEO_TEL_DISPLAY_HIDE == peer_disp_type)
    {
        peer_data.peer_enc_qty = video_setting_p->peer_enc_qty;
        peer_type = VCALL_VIEW_HIDE;
    }
    else
    {
        MMI_ASSERT(0);
    }

    g_mdi_video_tel_cntx.peer_layer_w = peer_data.display_width;
    g_mdi_video_tel_cntx.peer_layer_h = peer_data.display_height;

    if(MDI_VIDEO_TEL_DISPLAY_VIDEO == peer_disp_type || MDI_VIDEO_TEL_DISPLAY_VIDEO == local_disp_type )
    {
      if(MDI_VIDEO_TEL_DISPLAY_VIDEO == local_disp_type)
          gdi_layer_set_hw_update_layer(local_layer_handle,KAL_TRUE);
      if(MDI_VIDEO_TEL_DISPLAY_VIDEO == peer_disp_type)
          gdi_layer_set_hw_update_layer(peer_layer_handle,KAL_TRUE);

      gdi_lcd_set_hw_update(KAL_TRUE);
      g_mdi_video_tel_cntx.is_hw_layer_enable = TRUE;
    }

    ret = media_vcall_open_video_codec(
            MOD_MMI,
            local_type,     /* outgoing data */
            &local_data,    /* outgoing data */
            peer_type,      /* incoming data */
            &peer_data);    /* incoming data */

    /* reset flag */
    mdi_video_p->is_bypass_3a_stable = MMI_FALSE;

    if (ret != MED_RES_OK)
    {
        mdi_video_p->cam_id = MDI_VIDEO_MAIN_SENSOR;
        return MDI_RES_VDOTEL_ERR_FAILED;
    }
    else
    {
        g_mdi_video_tel_cntx.is_during_vcall = TRUE;
        return MDI_RES_VDOTEL_SUCCEED;
    }


#else /* MDI_VIDEO_DRIVER_AVAIALBE */

    g_mdi_video_tel_cntx.local_layer_handle = local_layer_handle;
    g_mdi_video_tel_cntx.peer_layer_handle = peer_layer_handle;

    g_mdi_video_tel_cntx.is_during_vcall = FALSE;

    return MDI_RES_VDOTEL_SUCCEED;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_resume
 * DESCRIPTION
 *  To start video telephony preview / decode
 * PARAMETERS
 *  peer_layer_handle           [IN]        peer display layer handle
 *  local_layer_handle          [IN]        local display layer handle
 *  peer_disp_type              [IN]        peer display type
 *  local_disp_type             [IN]        local display type
 *  blt_laye_flag               [IN]        which layers will be blt to lcd by driver
 *  peer_layer_flag             [IN]        which layer is for peer display
 *  local_layer_flag            [IN]        which layer is for local display
 *  local_preview_p             [IN]        local preview video settings
 *  event_callback              [IN]        call back function
 * RETURN VALUES
 *  MDI_RES_VDOTEL_SUCCEED : Succeed to start video telephony service.
 *  MDI_RES_VDOTEL_ERR_FAILED : Fail to start video telephony service.
 *****************************************************************************/
MDI_RESULT mdi_video_tel_resume(
            gdi_handle peer_layer_handle,
            gdi_handle local_layer_handle,
            mdi_video_tel_disp_type_enum peer_disp_type,
            mdi_video_tel_disp_type_enum local_disp_type,
            U32 blt_layer_flag,
            U32 peer_layer_flag,
            U32 local_layer_flag,
            mdi_video_setting_struct *local_preview_setting_p,
            mdi_video_tel_event_callback event_callback,
            void* callback_userdata)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_record_struct local_data;
    media_vcall_playback_struct peer_data;
    media_vcall_view_type_enum local_type = VCALL_VIEW_HIDE;
    media_vcall_view_type_enum peer_type = VCALL_VIEW_HIDE;
    mdi_blt_para_struct blt_data;
    S32 ret;
    mdi_camera_zoom_info zoom_info;
    U8 physical_rotate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_tel_codec_event_callback = event_callback;
    mdi_video_tel_codec_event_callback_data = callback_userdata;

    SetProtocolEventHandler(
        mdi_video_tel_codec_event_ind_hdlr,
        MSG_ID_MEDIA_VCALL_VIDEO_CODEC_REPORT_IND);

    /* store video's parameters */
    memcpy(video_setting_p, local_preview_setting_p, sizeof(mdi_video_setting_struct));

    memset((void*)&local_data, 0, sizeof(media_vcall_record_struct));
    memset((void*)&peer_data, 0, sizeof(media_vcall_playback_struct));

    gdi_lcd_get_active(&mdi_video_p->lcd_handle);


    ret = mdi_video_detect_sensor_id(mdi_video_p->cam_id);

    if (ret != MDI_RES_VDOREC_SUCCEED)
    {
        mdi_video_p->cam_id = MDI_VIDEO_MAIN_SENSOR;
        return MDI_RES_VDOTEL_ERR_FAILED;
    }

    /*******************************
     *        LOCAL DISPLAY        *
     *******************************/
    if(local_layer_flag != 0)
    {
        gdi_layer_get_layer_element(
            local_layer_flag,
            &local_data.layer_element,
            &local_data.blt_ctx,
            &local_data.blt_dev);
    }

    if(local_layer_handle != 0)
    {
        gdi_layer_get_actual_rotate_value(local_layer_handle, &physical_rotate);
        local_data.ui_rotate = mdi_util_remapping_layer_rotate_to_cal_rotate(physical_rotate);
    }
    else
    {
        physical_rotate = 0;
    }

    if (MDI_VIDEO_TEL_DISPLAY_VIDEO == local_disp_type ||
        MDI_VIDEO_TEL_DISPLAY_IMAGE == local_disp_type)
    {
        /* common data */
        mdi_calc_blt_para(
            local_layer_handle,
            MDI_LCD_ROTATE_0,
            mdi_video_p->lcd_handle,
            MMI_FALSE,
            &blt_data);

    #if defined(ISP_SUPPORT)
        switch (video_setting_p->video_size)
        {
            case MDI_VIDEO_VIDEO_SIZE_SQCIF:
                local_data.encode_width = 128;
                local_data.encode_height = 96;
                break;

            case MDI_VIDEO_VIDEO_SIZE_QQVGA:
                MMI_ASSERT(0); /* currently not support */
                local_data.encode_width = 160;
                local_data.encode_height = 120;
                break;

            case MDI_VIDEO_VIDEO_SIZE_QCIF:
                local_data.encode_width = 176;
                local_data.encode_height = 144;
                break;

            case MDI_VIDEO_VIDEO_SIZE_CIF:
                MMI_ASSERT(0); /* currently not support */
                local_data.encode_width = 352;
                local_data.encode_height = 288;
                break;

            case MDI_VIDEO_VIDEO_SIZE_USER_DEFINE:
                MMI_ASSERT(0); /* currently not support */
                local_data.encode_width = video_setting_p->user_def_width;
                local_data.encode_height = video_setting_p->user_def_height;
                break;
            default:
                ASSERT(0);
        }

    #endif /* ISP_SUPPORT */

        local_data.preview_width = blt_data.display_width;
        local_data.preview_height = blt_data.display_height;
        local_data.preview_buffer_p = blt_data.image_buffer_p;
        local_data.preview_buffer_size = blt_data.image_buffer_size;
        local_data.cam_id = mdi_video_p->cam_id;
    }


    if (MDI_VIDEO_TEL_DISPLAY_VIDEO == local_disp_type)
    {
        local_type = VCALL_VIEW_SHOW_VIDEO;

        /* NOTE!! currently do not support lcd rotation */
        MMI_ASSERT(video_setting_p->lcm_rotate == MDI_LCD_ROTATE_0);
        mdi_video_tel_query_zoom_info(&zoom_info);

        local_data.zoom_step = video_setting_p->zoom;
        local_data.exposure = video_setting_p->ev;
        local_data.contrast = video_setting_p->contrast;
        local_data.saturation = video_setting_p->saturation;
        local_data.sharpness = video_setting_p->sharpness;
        local_data.hue = video_setting_p->hue;
        local_data.WB = video_setting_p->wb;
        local_data.effect = video_setting_p->effect;
        local_data.dsc_mode = MDI_VIDEO_SCENE_MODE_AUTO;
        local_data.af_operation_mode = MDI_VIDEO_AF_OPERATION_MODE_SINGLE_ZONE;
        local_data.af_range = MDI_VIDEO_AF_RANGE_AUTO;

        local_data.banding_freq = (U8)video_setting_p->banding;
        local_data.encode_quality = (U8)video_setting_p->video_qty;
        local_data.seq_num = mdi_video_p->vt_seq_num;

        local_data.lcd_id = MAIN_LCD;

        local_data.notify_peer = video_setting_p->notify_peer_on_camera_off;
        
        if(video_setting_p->night == 1)
        {
            local_data.night_mode = KAL_TRUE;
        }
        else
        {
            local_data.night_mode = KAL_FALSE;
        }

        /* update to lcd or not */
        if (local_layer_flag == 0)
        {
            local_data.lcd_update = KAL_FALSE;
        }
        else
        {
            local_data.lcd_update = KAL_TRUE;
        }

        if (blt_data.image_color_format == GDI_COLOR_FORMAT_UYVY422)
        {
            local_data.image_data_format = MM_IMAGE_FORMAT_PACKET_UYVY422;
        }
        else
        {
            local_data.image_data_format = MM_IMAGE_FORMAT_RGB565;
        }

    }
    else if (MDI_VIDEO_TEL_DISPLAY_IMAGE == local_disp_type)
    {
        local_type = VCALL_VIEW_SHOW_IMAGE;

        /* encoder qty */
        local_data.encode_quality = (U8)video_setting_p->video_qty;
        local_data.seq_num = mdi_video_p->vt_seq_num;

        local_data.notify_peer = video_setting_p->notify_peer_on_camera_off;
        
        /* update to lcd or not */
        if (local_layer_flag == 0)
        {
            local_data.lcd_update = KAL_FALSE;
        }
        else
        {
            local_data.lcd_update = KAL_TRUE;
        }

    }
    else if(MDI_VIDEO_TEL_DISPLAY_HIDE == local_disp_type)
    {
        local_type = VCALL_VIEW_HIDE;

        local_data.notify_peer = video_setting_p->notify_peer_on_camera_off;
        
        /* encoder qty */
        local_data.encode_quality = (U8)video_setting_p->video_qty;
        local_data.seq_num = mdi_video_p->vt_seq_num;
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }

    g_mdi_video_tel_cntx.local_layer_w = local_data.preview_width;
    g_mdi_video_tel_cntx.local_layer_h = local_data.preview_height;

    /*******************************
     *         PEER DISPLAY        *
     *******************************/
    if(peer_layer_flag != 0)
    {
        gdi_layer_get_layer_element(
            peer_layer_flag,
            &peer_data.layer_element,
            &peer_data.blt_ctx,
            &peer_data.blt_dev);
    }

    if(peer_layer_handle != 0)
    {
        gdi_layer_get_actual_rotate_value(peer_layer_handle, &physical_rotate);
        peer_data.ui_rotate = mdi_util_remapping_layer_rotate_to_cal_rotate(physical_rotate);
    }
    else
    {
        physical_rotate = 0;
    }

    if (MDI_VIDEO_TEL_DISPLAY_VIDEO == peer_disp_type ||
        MDI_VIDEO_TEL_DISPLAY_IMAGE == peer_disp_type)
    {
        /* calc blt paramters */
        mdi_calc_blt_para(
            peer_layer_handle,
            MDI_LCD_ROTATE_0,
            mdi_video_p->lcd_handle,
            MMI_FALSE,
            &blt_data);

        if (MDI_VIDEO_TEL_DISPLAY_VIDEO == peer_disp_type)
        {
            peer_type = VCALL_VIEW_SHOW_VIDEO;
        }
        else if (MDI_VIDEO_TEL_DISPLAY_IMAGE == peer_disp_type)
        {
            peer_type = VCALL_VIEW_SHOW_IMAGE;
        }
        else
        {
            MMI_ASSERT(0);
        }

        peer_data.display_width = blt_data.display_width;
        peer_data.display_height = blt_data.display_height;
        peer_data.display_buffer_p = (void*)blt_data.image_buffer_p;
        peer_data.display_buffer_size = blt_data.image_buffer_size;
        peer_data.seq_num = mdi_video_p->vt_seq_num;

        peer_data.lcd_id = MAIN_LCD;
        peer_data.lcd_start_x = blt_data.lcd_start_x;
        peer_data.lcd_start_y = blt_data.lcd_start_y;
        peer_data.lcd_end_x = blt_data.lcd_end_x;
        peer_data.lcd_end_y = blt_data.lcd_end_y;
        peer_data.roi_offset_x = blt_data.roi_offset_x;
        peer_data.roi_offset_y = blt_data.roi_offset_y;
        gdi_layer_get_blt_layer_flag(&(peer_data.update_layer));
        ASSERT(peer_data.update_layer>0);
        peer_data.hw_update_layer = peer_layer_flag;
        if (blt_data.image_color_format == GDI_COLOR_FORMAT_UYVY422)
        {
            peer_data.image_data_format = MM_IMAGE_FORMAT_PACKET_UYVY422;
        }
        else
        {
            peer_data.image_data_format = MM_IMAGE_FORMAT_RGB565;
        }
        peer_data.peer_enc_qty = video_setting_p->peer_enc_qty;
        peer_data.roi_background_color = GDI_COLOR_BLACK;


    }
    else if(MDI_VIDEO_TEL_DISPLAY_HIDE == peer_disp_type)
    {
        peer_data.peer_enc_qty = video_setting_p->peer_enc_qty;    
        peer_type = VCALL_VIEW_HIDE;
    }
    else
    {
        MMI_ASSERT(0);
    }

    g_mdi_video_tel_cntx.peer_layer_w = peer_data.display_width;
    g_mdi_video_tel_cntx.peer_layer_h = peer_data.display_height;

    if(peer_layer_flag != 0 &&  local_layer_flag != 0 && !g_mdi_video_tel_cntx.is_hw_layer_enable &&
        (MDI_VIDEO_TEL_DISPLAY_VIDEO == peer_disp_type || MDI_VIDEO_TEL_DISPLAY_VIDEO == local_disp_type))
    {
        if(MDI_VIDEO_TEL_DISPLAY_VIDEO == local_disp_type)
        {
            gdi_layer_set_hw_update_layer(local_layer_handle, KAL_FALSE);

            gdi_layer_push_and_set_active(local_layer_handle);
            //gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();

            gdi_layer_set_blt_layer_previous(); // Flush layer setting which is modified by app

            gdi_layer_set_hw_update_layer(local_layer_handle,KAL_TRUE);
        }
        if(MDI_VIDEO_TEL_DISPLAY_VIDEO == peer_disp_type)
        {
            gdi_layer_set_hw_update_layer(peer_layer_handle, KAL_FALSE);

            gdi_layer_push_and_set_active(peer_layer_handle);
            //gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();

            gdi_layer_set_blt_layer_previous(); // Flush layer setting which is modified by app

            gdi_layer_set_hw_update_layer(peer_layer_handle,KAL_TRUE);
        }
        gdi_lcd_set_hw_update(KAL_TRUE);
        g_mdi_video_tel_cntx.is_hw_layer_enable = TRUE;
    }

    ret = media_vcall_resume_video_codec(
            MOD_MMI,
            local_type,     /* outgoing data */
            &local_data,    /* outgoing data */
            peer_type,      /* incoming data */
            &peer_data);    /* incoming data */

    /* reset flag */
    mdi_video_p->is_bypass_3a_stable = MMI_FALSE;

    if (ret != MED_RES_OK)
    {
        mdi_video_p->cam_id = MDI_VIDEO_MAIN_SENSOR;
        return MDI_RES_VDOTEL_ERR_FAILED;
    }
    else
    {
        return MDI_RES_VDOTEL_SUCCEED;
    }


#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOTEL_SUCCEED;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_stop
 * DESCRIPTION
 *  To stop video telephony preview / decode
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOTEL_SUCCEED : Succeed to stop video telephony service.
 *  MDI_RES_VDOTEL_ERR_FAILED : Fail to stop video telephony service.
 *****************************************************************************/
MDI_RESULT mdi_video_tel_stop(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->vt_seq_num++;

    /* reset camera id to main */
    mdi_video_p->cam_id = MDI_VIDEO_MAIN_SENSOR;

    media_vcall_close_video_codec(MOD_MMI);

    gdi_lcd_set_hw_update(KAL_FALSE);
    g_mdi_video_tel_cntx.is_hw_layer_enable = FALSE;

    g_mdi_video_tel_cntx.is_during_vcall = FALSE;

    /* reset the jpeg flag to use jpeg by HW */
    gdi_image_jpeg_set_force_use_swjpeg(KAL_FALSE);
    
    return MDI_RES_VDOTEL_SUCCEED;

#else /* MDI_VIDEO_DRIVER_AVAIALBE */

    g_mdi_video_tel_cntx.is_during_vcall = FALSE;

    return MDI_RES_VDOTEL_SUCCEED;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_pause
 * DESCRIPTION
 *  To stop video telephony preview / decode
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOTEL_SUCCEED : Succeed to stop video telephony service.
 *  MDI_RES_VDOTEL_ERR_FAILED : Fail to stop video telephony service.
 *****************************************************************************/
MDI_RESULT mdi_video_tel_pause(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->vt_seq_num++;

    /* reset camera id to main */
    mdi_video_p->cam_id = MDI_VIDEO_MAIN_SENSOR;

    media_vcall_pause_video_codec(MOD_MMI);

    gdi_lcd_set_hw_update(KAL_FALSE);
    g_mdi_video_tel_cntx.is_hw_layer_enable = FALSE;

    return MDI_RES_VDOTEL_SUCCEED;

#else /* MDI_VIDEO_DRIVER_AVAIALBE */
    return MDI_RES_VDOTEL_SUCCEED;

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_codec_event_ind_hdlr
 * DESCRIPTION
 *  video tel event handler
 * PARAMETERS
 *  msg_ptr     [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_video_tel_codec_event_ind_hdlr(void *msg_ptr)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_video_codec_report_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_TEL_CODEC_EVENT_IND_HDLR);
    ind_p = (media_vcall_video_codec_report_ind_struct*) msg_ptr;

    if (mdi_video_p->vt_seq_num != ind_p->seq_no)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_SEQ_NOT_MATCHED);
        return;
    }

    /* mapping driver's event to MDI */
    switch (ind_p->codec_event)
    {
        case VCALL_EVENT_CHANGE_ENCODE_SIZE:
            if (ind_p->para == VCALL_VIDEO_SIZE_SQCIF)
            {
                mdi_video_tel_codec_event_callback(
                    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_SIZE,
                    MDI_VIDEO_VIDEO_SIZE_SQCIF,
                    mdi_video_tel_codec_event_callback_data);
            }
            else if (ind_p->para == VCALL_VIDEO_SIZE_QCIF)
            {
                mdi_video_tel_codec_event_callback(
                    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_SIZE,
                    MDI_VIDEO_VIDEO_SIZE_QCIF,
                    mdi_video_tel_codec_event_callback_data);
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;

        case VCALL_EVENT_CHANGE_ENCODE_QUALITY:
            if (ind_p->para == VCALL_ENC_QTY_FINE)
            {
                mdi_video_tel_codec_event_callback(
                    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_QUALITY,
                    MDI_VIDEO_TEL_ENC_QTY_FINE,
                    mdi_video_tel_codec_event_callback_data);
            }
            else if (ind_p->para == VCALL_ENC_QTY_NORMAL)
            {
                mdi_video_tel_codec_event_callback(
                    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_QUALITY,
                    MDI_VIDEO_TEL_ENC_QTY_NORMAL,
                    mdi_video_tel_codec_event_callback_data);
            }
            else if (ind_p->para == VCALL_ENC_QTY_LOW)
            {
                mdi_video_tel_codec_event_callback(
                    MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_QUALITY,
                    MDI_VIDEO_TEL_ENC_QTY_LOW,
                    mdi_video_tel_codec_event_callback_data);
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;

        case VCALL_EVENT_UPDATE_LCD:
            mdi_video_tel_codec_event_callback(
                MDI_VIDEO_TEL_EVENT_UPDATE_LCD,
                0,
                mdi_video_tel_codec_event_callback_data);
            break;

        case VCALL_EVENT_ENC_PATH_BUILT:
            mdi_video_tel_codec_event_callback(
                MDI_VIDEO_TEL_EVENT_ENC_PATH_BUILT,
                ind_p->para,
                mdi_video_tel_codec_event_callback_data);
            break;

        case VCALL_EVENT_DEC_CH_CHANGE:
            mdi_video_tel_codec_event_callback(MDI_VIDEO_TEL_EVENT_DEC_CH_CHANGE, ind_p->para, mdi_video_tel_codec_event_callback_data);
            break;

        default:
            ASSERT(0);
    }

#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_set_camera_id
 * DESCRIPTION
 *  To set sensor id for preview
 * PARAMETERS
 *  U16 sensor id
 * RETURN VALUES
 *  MDI_RES_VDOTEL_SUCCEED : Succeed to set id.
 *  MDI_RES_VDOTEL_ERR_FAILED : Fail to set id.
 *****************************************************************************/
MDI_RESULT mdi_video_tel_set_camera_id(U16 camera_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->cam_id = camera_id;
    mdi_camera_set_camera_id(camera_id);
    return MDI_RES_VDOTEL_SUCCEED;

}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_set_memory_param
 * DESCRIPTION
 *  set max window size for config memory usage
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failure
 *****************************************************************************/
MDI_RESULT mdi_video_tel_set_memory_param(
    kal_bool is_set, 
    kal_uint32 main_wnd_width, 
    kal_uint32 main_wnd_height, 
    kal_uint32 sub_wnd_width, 
    kal_uint32 sub_wnd_height)
{

    return media_vcall_set_memory_param(stack_get_active_module_id(), is_set, main_wnd_width, main_wnd_height, sub_wnd_width, sub_wnd_height);
}

/*****************************************************************************
 * FUNCTION
 *  mdi_camera_hw_layer_get_content
 * DESCRIPTION
 *  Get preview buffer content.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_CAMERA_SUCCEED      : Success
 *  MDI_RES_CAMERA_ERR_FAILED   : Failure
 *****************************************************************************/
MDI_RESULT mdi_video_tel_get_hw_layer_buffer_content(gdi_handle layer_handle, U8 *dst_buff_p, U32 dst_buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vcall_get_buf_content_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mdi_video_tel_cntx.is_during_vcall &&
        (layer_handle == g_mdi_video_tel_cntx.local_layer_handle || layer_handle == g_mdi_video_tel_cntx.peer_layer_handle) )
    {

        if(layer_handle == g_mdi_video_tel_cntx.local_layer_handle)
        {
            req.is_peer_view = KAL_FALSE;
            req.buffer_width = g_mdi_video_tel_cntx.local_layer_w;
            req.buffer_height = g_mdi_video_tel_cntx.local_layer_h;
        }
        else
        {
            req.is_peer_view = KAL_TRUE;
            req.buffer_width = g_mdi_video_tel_cntx.peer_layer_w;
            req.buffer_height = g_mdi_video_tel_cntx.peer_layer_h;
        }

        req.buffer_address = (kal_uint32)dst_buff_p;
        req.buffer_size = dst_buff_size;

        media_vcall_get_buffer_content(stack_get_active_module_id(), (void*)&req);
    }
    else
    {
        return MDI_RES_VDOTEL_ERR_FAILED;
    }
}


MDI_RESULT mdi_video_tel_get_peer_content(U8 *dst_buff_p, U32 dst_buff_size)
{
    return mdi_video_tel_get_hw_layer_buffer_content(g_mdi_video_tel_cntx.peer_layer_handle, dst_buff_p, dst_buff_size);
}

MDI_RESULT mdi_video_tel_get_local_content(U8 *dst_buff_p, U32 dst_buff_size)
{
    return MDI_RES_VDOTEL_ERR_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_query_support_info
 * DESCRIPTION
 *  To query sensor info
 * PARAMETERS
 *  U32     info type
 *  void*   return info
 * RETURN VALUES
 *  void
 *****************************************************************************/
void mdi_video_tel_query_support_info(U32 mdi_setting_type, void *p_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_sensor_query_capability_req_struct query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    query.camera_mode = CAL_CAMERA_MODE_VIDEO;
    query.item_id = mdi_setting_type;
    query.struct_p = p_info;

    media_cam_sensor_query_capability(stack_get_active_module_id(), &query);

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_query_zoom_info
 * DESCRIPTION
 *  To query zoom info
 * PARAMETERS
 *  mdi_camera_zoom_info*  return zoom info
 * RETURN VALUES
 *  void
 *****************************************************************************/
void mdi_video_tel_query_zoom_info(mdi_camera_zoom_info *p_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_zoom_capability_req_struct zoom;
    media_cam_zoom_capability_info_struct result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    zoom.camera_mode = CAL_CAMERA_MODE_VIDEO;
    zoom.image_size = MDI_VIDEO_VIDEO_SIZE_QCIF;
    zoom.result_p = &result;

    media_cam_sensor_query_zoom_info(stack_get_active_module_id(), &zoom);

    p_info->zoom_support_type = result.DzType;
    p_info->max_zoom_factor = result.MaxZoomFactor;
    p_info->zoom_steps = result.TotalZoomSteps;

}

/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_update_para_ev
 * DESCRIPTION
 *  update ev setting value
 * PARAMETERS
 *  para        [IN]        ev setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_tel_update_para_ev(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_TEL_UPDATE_PARA_EV, para);
    ASSERT(para < MDI_VIDEO_EV_COUNT);

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_vcall_set_param(MOD_MMI, CAL_FEATURE_CAMERA_EV_VALUE, para);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_update_para_contrast
 * DESCRIPTION
 *  update contrast setting value
 * PARAMETERS
 *  para        [IN]        contrast setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_tel_update_para_contrast(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_vcall_set_param(MOD_MMI, CAL_FEATURE_CAMERA_CONTRAST, para);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_update_para_zoom
 * DESCRIPTION
 *  To update zoom setting value.
 * PARAMETERS
 *  para : [IN] zoom setting parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_tel_update_para_zoom(U16 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_TEL_UPDATE_PARA_ZOOM, para);

    mdi_video_p->setting.zoom = para;

#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    media_vcall_set_param(MOD_MMI, CAL_FEATURE_CAMERA_DIGITAL_ZOOM, para);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_bypass_3a_stable
 * DESCRIPTION
 *  Bypass 3a stable when start preview
 * PARAMETERS
 *  none
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_tel_bypass_3a_stable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_p->is_bypass_3a_stable = MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_enable_vt_loopback
 * DESCRIPTION
 *  Enable VT task start loopback, this function is for UT use only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_tel_enable_vt_loopback(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_vt_loopback_active_req_struct *msg_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data_ptr = OslConstructDataPtr(sizeof(mdi_vt_loopback_active_req_struct));

    mmi_frm_send_ilm(MOD_VT, MSG_ID_MDI_VT_LOOPBACK_ACTIVATE_REQ, (oslParaType*)msg_data_ptr, NULL);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_tel_disable_vt_loopback
 * DESCRIPTION
 *  Disable VT task start loopback, this function is for UT use only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_video_tel_disable_vt_loopback(void)
{
#ifdef MDI_VIDEO_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_vt_loopback_deactive_req_struct *msg_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data_ptr = OslConstructDataPtr(sizeof(mdi_vt_loopback_deactive_req_struct));

    mmi_frm_send_ilm(MOD_VT, MSG_ID_MDI_VT_LOOPBACK_DEACTIVATE_REQ, (oslParaType*)msg_data_ptr, NULL);
#endif /* MDI_VIDEO_DRIVER_AVAIALBE */
}

#endif /* __MMI_VIDEO_TELEPHONY__ */






