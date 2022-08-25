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
 *   vid_recorder_msg_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes message handle functions of video module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MED_NOT_PRESENT

/***************************************************************************** 
 * Include
 *****************************************************************************/
/* system includes */
#include "kal_trace.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"         /* Task message communiction */

/* global includes */
#include "l1audio.h"

#include "FSAL.h"
#include "visual_comm.h"

// for cmaera HAL video integration by PoChun Huang
#include "val_if.h"
#include "val_recorder_if.h"
#include "custom_video_enc_if.h"
#include "lcd_if.h"

// for cmaera HAL video integration by PoChun Huang

#include "idp_cal.h"

/* local includes */
#include "med_global.h"
#include "med_status.h"
#include "med_main.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"
#include "med_smalloc.h"
#include "cam_main.h"
#include "vid_main.h"
#include "aud_main.h"

#include "med_v_main.h"
#include "med_v_struct.h"

#if defined(__MED_TVO_MOD__)
#include "tv_out.h"
#endif

#if defined(__MED_MJPG_MOD__)
#include "med_v_main.h"
#include "med_v_struct.h"
#endif /* defined(__MED_MJPG_MOD__) */ 

#include "img_common_enum.h"

#ifdef __VID_TRACE_ON__
#include "med_trc.h"
#endif 

#include "Fs_errcode.h"

#ifdef __MED_AT_DEBUG__ 
#include "app_frm_command_gprot.h"
#endif

#if defined(__MED_VID_ENC_MOD__)
#include "vid_if.h"
#include "media_session.h"
#include "media_provider.h"

//tmp for compiler
#include "kal_general_types.h"
#include "mpl_player.h"
#include "video_memory_usage_v2.h"
#include "video_codec_mem_v2.h"
#include "MP4SwEncMem.h"
#include "video_codec_mem_custom_v2.h"
#include "video_comm_component_v2.h"
#include "video_types_v2.h"
#include "video_encoder_component_if_v2.h"
#include "video_recorder_source_component_if_v2.h"
#include "video_recorder_if_v2.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "stack_config.h"
#include "fs_type.h"
#include "fs_func.h"
#include "mp4_common.h"
#include "string.h"


#include "mm_comm_def.h"
#include "cal_mem_def.h"
#include "cal_api.h"
#include "cal_comm_def.h"
#include "isp_comm_def.h"
#include "mpl_recorder.h"

#include "drv_sw_features_mdp.h"
#include "cal_feature_option.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(SENSOR_ON_BODY)
#define VID_MAIN_SENSOR_MIRROR  (0) // 1 : need to mirror
#elif defined(SENSOR_ON_COVER)
#define VID_MAIN_SENSOR_MIRROR  (1) // 1 : need to mirror
#else
#define VID_MAIN_SENSOR_MIRROR  (0)
#endif

#define VID_SUB_SENSOR_MIRROR   (1)


#if defined(__MAIN_LCM_SCANLINE_ROTATION_0__)
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_0)
#elif defined(__MAIN_LCM_SCANLINE_ROTATION_90__)
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_270)
#elif defined(__MAIN_LCM_SCANLINE_ROTATION_180__)
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_180)
#elif defined(__MAIN_LCM_SCANLINE_ROTATION_270__)
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_90)
#else
#define MAIN_LCM_CROSS_SENSOR_ANGLE  (0)
#endif

#if defined(__SUB_LCM_SCANLINE_ROTATION_0__)
#define SUB_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_0)
#elif defined(__SUB_LCM_SCANLINE_ROTATION_90__)
#define SUB_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_270)
#elif defined(__SUB_LCM_SCANLINE_ROTATION_180__)
#define SUB_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_180)
#elif defined(__SUB_LCM_SCANLINE_ROTATION_270__)
#define SUB_LCM_CROSS_SENSOR_ANGLE  (MM_IMAGE_ROTATE_90)
#else
#define SUB_LCM_CROSS_SENSOR_ANGLE  (0)
#endif

#if defined(SENSOR_ROTATE_0)
#define VID_MAIN_SENSOR_ROTATE  (MM_IMAGE_ROTATE_0)
#elif defined(SENSOR_ROTATE_90)
#define VID_MAIN_SENSOR_ROTATE  (MM_IMAGE_ROTATE_90)
#elif defined(SENSOR_ROTATE_180)
#define VID_MAIN_SENSOR_ROTATE  (MM_IMAGE_ROTATE_180)
#elif defined(SENSOR_ROTATE_270)
#define VID_MAIN_SENSOR_ROTATE  (MM_IMAGE_ROTATE_270)
#endif

#if defined(SUB_SENSOR_ROTATE_0)
#define VID_SUB_SENSOR_ROTATE  (MM_IMAGE_ROTATE_0)
#elif defined(SUB_SENSOR_ROTATE_90)
#define VID_SUB_SENSOR_ROTATE  (MM_IMAGE_ROTATE_90)
#elif defined(SUB_SENSOR_ROTATE_180)
#define VID_SUB_SENSOR_ROTATE  (MM_IMAGE_ROTATE_180)
#elif defined(SUB_SENSOR_ROTATE_270)
#define VID_SUB_SENSOR_ROTATE  (MM_IMAGE_ROTATE_270)
#endif


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
#endif

static void vid_recorder_deinit_and_release_memory(void);

#define CHECK_RECORDER_P() ASSERT(recorder_p!=NULL);

#ifdef __LOW_COST_SUPPORT_COMMON__
#define VID_SET_RESULT_EVENT(_result_, _event_, _line_) \
    vid_set_result_and_event(_result_, _event_);    
#else
#define VID_SET_RESULT_EVENT(_result_, _event_, _line_) \
    vid_set_result(_result_, _line_);  \
    vid_set_event(_event_);          
#endif

mpl_recorder_t *recorder_p;
mpl_recorder_client_t mpl_recorder_client;
mpl_recorder_client_t* mpl_recorder_client_p;

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
#define _VID_DEBUG
#if defined(_VID_DEBUG)
#define vid_prompt_trace kal_prompt_trace
#else
#define vid_prompt_trace 1 ? (void) 0 : kal_prompt_trace
#endif


/***************************************************************************** 
 * Variable 
 *****************************************************************************/
#if defined(__MED_VID_DEC_MOD__)
extern void vid_delay_open(void);
#endif /* __MED_VID_DEC_MOD__ */


/***************************************************************************** 
 * Local Functions 
 *****************************************************************************/
#ifdef __MED_AT_DEBUG__
/*****************************************************************************
 * FUNCTION
 *  rtspd_fsm_handle_p
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void vid_recorder_query_sensor_support_info(kal_uint32 item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_sensor_query_capability_req_struct query;
	media_cam_sensor_general_info cap_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    query.camera_mode = CAL_CAMERA_MODE_VIDEO;
    query.item_id = item_id;
    query.struct_p = &cap_info;

    media_cam_sensor_query_capability(MOD_RTSP, &query);
    

}


/*****************************************************************************
 * FUNCTION
 *  rtspd_fsm_handle_p
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static med_at_return_enum med_rtspd_fsm_handle_setup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_power_up_req_struct med_powerup_param;
    media_vid_preview_req_struct med_preview_param;
    med_result_enum ret;
    module_type module_id = MOD_RTSP;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//vid_recorder_query_sensor_support_info(CAL_FEATURE_CAMERA_WB);
	//vid_recorder_query_sensor_support_info(CAL_FEATURE_CAMERA_IMAGE_EFFECT);

   
	//memset(&med_pwrup_param,0,sizeof(med_pwrup_param));
    med_powerup_param.seq_num = 0;
    med_powerup_param.app_id = 0;
    med_powerup_param.cam_id = CAM_MAIN_CAMERA;
    
    ret = media_vid_power_up(module_id, (void*)&med_powerup_param);
	if (ret != MED_RES_OK)
	{
        kal_prompt_trace(MOD_MED,"[VID]ret = %d at line %d",ret,__LINE__);
		return MED_AT_POWERUP_ERROR;
	}

	
	memset(&med_preview_param,0,sizeof(med_preview_param));
    med_preview_param.audio_rtp_handle = 0 ;
    med_preview_param.video_rtp_handle = 0 ;

    // set rtp handle to media_param
    ret = media_vid_preview(module_id,&med_preview_param);
    if (ret != MED_RES_OK)
	{
		kal_prompt_trace(MOD_MED,"[VID]ret = %d at line %d",ret,__LINE__);
		return MED_AT_PREVIEW_ERROR;
	}

    return MED_AT_OK;
   
}

/*****************************************************************************
 * FUNCTION
 *  rtspd_fsm_handle_play 
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static med_at_return_enum med_rtspd_fsm_handle_play(kal_bool is_resume)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_vid_record_req_struct med_record_param;
    kal_int32 ret = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&med_record_param,0,sizeof(med_record_param));
    if (!is_resume)
    {
		med_record_param.media_mode = MED_MODE_FILE;
		med_record_param.record_audio = KAL_TRUE;
			   
		ret = media_vid_record(MOD_RTSP, &med_record_param); 
		if (ret != MED_RES_OK)
    	{
        	kal_prompt_trace(MOD_MED,"[VID]ret = %d at line %d",ret,__LINE__);
			return MED_AT_RECORD_ERROR;
    	}
		
    }
    else 
    {
        ret = media_vid_resume(MOD_RTSP);
        if (ret != MED_RES_OK)
    	{
        	kal_prompt_trace(MOD_MED,"[VID]ret = %d at line %d",ret,__LINE__);
			return MED_AT_RESUME_ERROR;
    	}
        
    }    

    return MED_AT_OK;
    
}


/*****************************************************************************
 * FUNCTION
 *  rtspd_fsm_handle_pause
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static med_at_return_enum med_rtspd_fsm_handle_pause(void)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_vid_pause_req_struct med_pause_param; 
    kal_int32 ret = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(&med_pause_param,0,sizeof(med_pause_param));
    med_pause_param.stop_preview = KAL_FALSE;

    ret = media_vid_pause(MOD_RTSP, &med_pause_param);
	if (ret != MED_RES_OK)
    {
        kal_prompt_trace(MOD_MED,"[VID]ret = %d at line %d",ret,__LINE__);
		return MED_AT_PAUSE_ERROR;
    }
    	
    return MED_AT_OK;
    
    
}


/*****************************************************************************
 * FUNCTION
 *  rtspd_fsm_handle_teardown 
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static med_at_return_enum med_rtspd_fsm_handle_teardown(void)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	med_result_enum ret;
    module_type module_id = MOD_RTSP;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = media_vid_rec_stop(module_id);
	if (ret != MED_RES_OK)
	{
		kal_prompt_trace(MOD_MED,"[VID]ret = %d at line %d",ret,__LINE__);
		return MED_AT_STOP_ERROR;
	}
    
    ret = media_vid_power_down(module_id);
	if (ret != MED_RES_OK)
	{
		kal_prompt_trace(MOD_MED,"[VID]ret = %d at line %d",ret,__LINE__);
		return MED_AT_POWERDOWN_ERROR;
	}
	
    return MED_AT_OK;

}

/*****************************************************************************
 * FUNCTION
 *  rtspd_fsm_handle_teardown 
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void ipcam_med_vid_AT_callback(app_command_struct *param, void *user_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables											   */
	/*----------------------------------------------------------------*/
		
	int i;
	int mark_index;
	char *mark[] = {"RMSETUP",  "RMRECORD", "RMPAUSE","RMRESUME","RMTEARDOWN"};
	char *s = param->command_buf;
    med_at_return_enum ret;
	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/	
	for (i = 0; i < 5; i++)
	{
		if (strncmp(s,mark[i],strlen(mark[i])) == 0)
			mark_index = i;
	}
	
	switch (mark_index)
	{
		case 0://"RMSETUP"
		{
			printf("\nAT commond RMSETUP");	
			ret = med_rtspd_fsm_handle_setup();
			if(ret != MED_AT_OK)
				kal_prompt_trace(MOD_MED,"[VID]ret = %d at line %d",ret,__LINE__);
			break;
		}
		case 1: //"RMRECORD"
		{
			printf("\nAT commond RMRECORD");
			ret = med_rtspd_fsm_handle_play(KAL_FALSE);
			if(ret != MED_AT_OK)
				kal_prompt_trace(MOD_MED,"[VID]ret = %d at line %d",ret,__LINE__);
			break;
		}
		case 2://"RMPAUSE"
		{			
			printf("\nAT commond RMPAUSE");
			ret = med_rtspd_fsm_handle_pause();
			if(ret != MED_AT_OK)
				kal_prompt_trace(MOD_MED,"[VID]ret = %d at line %d",ret,__LINE__);
			
			break;
		}
		case 3://"RMRESUME"
		{
			printf("\nAT commond RMRESUME");
			ret = med_rtspd_fsm_handle_play(KAL_TRUE);
			if(ret != MED_AT_OK)
				kal_prompt_trace(MOD_MED,"[VID]ret = %d at line %d",ret,__LINE__);
			
			break;
		}
		
		case 4://"RMTEARDOWN"
		{
			printf("\nAT commond RMTEARDOWN");
			ret = med_rtspd_fsm_handle_teardown();
			if(ret != MED_AT_OK)
				kal_prompt_trace(MOD_MED,"[VID]ret = %d at line %d",ret,__LINE__);
			
			break;
		}
		default:
			break;
	}

}
#endif
void vid_recorder_recover_preview_buffer(void)
{
#if defined(DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT)
    if (vid_context_p->frame_buffer_address_1!=NULL && vid_context_p->rec_align_buffer_address!= NULL)
    {
        memcpy((void*)vid_context_p->frame_buffer_address_1, (void*)vid_context_p->rec_align_buffer_address, vid_context_p->frame_buffer_size);    
    }
#endif
}

#pragma arm section code = "DYNAMIC_CODE_MWREC_ROCODE", rodata = "DYNAMIC_CODE_MWREC_RODATA"
static void vid_recorder_client_cb(mpl_recorder_client_t *client, mpl_recorder_event_enum_t event_id, media_error_t result)
{
    switch(event_id)
    {
        case MPL_RECORDER_EVENT_GENERAL:
            vid_send_event_ind(VID_EVT_MPL_EVENT, (kal_int32)result);
            break;
        case MPL_RECORDER_EVENT_STOP:
            vid_send_event_ind(VID_EVT_MPL_STOP, (kal_int32)result);
            break;
        case MPL_RECORDER_EVENT_SAVE:
            vid_send_event_ind(VID_EVT_MPL_SAVE, (kal_int32)result);
            break;        
    }
}


static void vid_recorder_mpl_event_hdlr(media_error_t result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_VISUAL_RECORD_FINISH_IND_HDLR);    
    vid_debug_print_cur_state(__LINE__);
    
#ifdef __VID_ENC_DEBUG__
    {
        kal_wchar drive[4] = L" :\\";
        kal_uint32 cluster_size;
        FS_DiskInfo disc_info;
        
        /* Log the disc info for debugging */
        drive[0] = vid_context_p->storing_path[0];
        FS_GetDiskInfo(drive, &disc_info, FS_DI_BASIC_INFO| FS_DI_FREE_SPACE);
        cluster_size = disc_info.BytesPerSector * disc_info.SectorsPerCluster;

        kal_trace(                                                      
            TRACE_GROUP_4,                                              
            VID_TRC_DISC_FREE_SPACE,                                    
            disc_info.FreeClusters,                                     
            cluster_size,     
            cluster_size * disc_info.FreeClusters,                                                      
            __LINE__); 
    }
#endif /* __VID_ENC_DEBUG__ */

    if (VID_IN_STATE(VID_RECORD) || VID_IN_STATE(VID_RECORD_UPDATE_BLT_PAUSED) || VID_IN_STATE(VID_RECORD_FINISH))
    {
        if (VID_IN_STATE(VID_RECORD))
        {
            /* for saving the final recording time */
            vid_recorder_get_current_record_time(&vid_context_p->current_time);            
            kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, vid_context_p->current_time, __LINE__);
            if(vid_context_p->src_mod != MOD_RTSP)
    		{
            	vid_recorder_get_current_record_size(&vid_context_p->recorded_size);  
            }
            vid_cal_stop_preview();
        }
        else if (VID_IN_STATE(VID_RECORD_FINISH))
        {
            if (vid_context_p->is_preview_stopped == KAL_FALSE)
            {
                /* stop camera */
                vid_cal_stop_preview();
            
                vid_context_p->is_preview_stopped = KAL_TRUE;
            }
        }
        
        vid_recorder_deinit_and_release_memory();
        
        VID_ENTER_STATE(VID_IDLE);

        /* visual's status */
        vid_send_record_finish_ind((kal_int16)med_error_to_result_enum(result));
    }

}


static void vid_recorder_mpl_stop_hdlr(media_error_t result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 cluster_size;
    FS_DiskInfo disc_info;
    kal_wchar drive[4] = L" :\\";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_VISUAL_STOP_CNF_HDLR);          
    vid_debug_print_cur_state(__LINE__);

    if (VID_IN_STATE(VID_RECORD))
    {
        ASSERT(0);
    }
    else if (VID_IN_STATE(VID_RECORD_STOP_VISUAL))
    {
        vid_recorder_get_current_record_time(&vid_context_p->current_time);
        kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, vid_context_p->current_time, __LINE__);
        vid_recorder_deinit_and_release_memory();
        VID_ENTER_STATE(VID_IDLE);
        vid_set_event(VID_EVT_STOP);
    }
    else if (VID_IN_STATE(VID_RECORD_PAUSED))
    {
        /* for debugging */
        vid_recorder_get_current_record_time(&vid_context_p->current_time);
        kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, vid_context_p->current_time, __LINE__);

        if (result != MED_S_OK)
        {
            vid_cal_stop_preview();

            vid_recorder_deinit_and_release_memory();

            VID_ENTER_STATE(VID_IDLE);
            vid_set_result(result, __LINE__);
        }
        else
        {
            vid_set_result(result, __LINE__);
        }
       
        vid_set_event(VID_EVT_PAUSE);
    }
    
    /* Log the disc info for debugging */
    drive[0] = vid_context_p->storing_path[0];
    FS_GetDiskInfo(drive, &disc_info, FS_DI_BASIC_INFO| FS_DI_FREE_SPACE);
    cluster_size = disc_info.BytesPerSector * disc_info.SectorsPerCluster;

    kal_trace(                                                      
        TRACE_GROUP_4,                                              
        VID_TRC_DISC_FREE_SPACE,                                    
        disc_info.FreeClusters,                                     
        cluster_size,     
        cluster_size * disc_info.FreeClusters,                                                      
        __LINE__); 

}

static void vid_recorder_mpl_save_hdlr(media_error_t result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_VISUAL_FILE_MERGE_CNF_HDLR);    
    vid_debug_print_cur_state(__LINE__);

    if (VID_IN_STATE(VID_FILE_MERGE_STOPPING))
    {
        VID_ENTER_STATE(VID_IDLE);

        if(vid_context_p->is_recorder_existed == KAL_FALSE)
        {
            if (recorder_p != NULL)
            {
                recorder_p->destroy(recorder_p);
                recorder_p = NULL;
            }
        }
        vid_set_event(VID_EVT_STOP);
        return;        
    }
#if defined(__MED_VID_DEC_MOD__)
    else if (VID_IN_STATE(VID_DELAY_OPEN))
    {
        /* the file merge process finished, send indication to notify MMI */
        VID_ENTER_STATE(VID_IDLE);
        vid_send_file_merge_done_ind((kal_int32)med_error_to_result_enum(result));

        if(vid_context_p->is_recorder_existed == KAL_FALSE)
        {
            vid_recorder_deinit();
        }

        vid_delay_open();
        return;
    }
#endif /* __MED_VID_DEC_MOD__ */
    else
    {
        VID_ENTER_STATE(VID_IDLE);
        vid_send_file_merge_done_ind((kal_int32)med_error_to_result_enum(result));

        if(vid_context_p->is_recorder_existed == KAL_FALSE)
        {
            if (recorder_p != NULL)
            {
                recorder_p->destroy(recorder_p);
                recorder_p = NULL;
            }
        }
        
        return;        
    }
}



static void* vid_alloc_ext_mem_impl(mpl_recorder_client_t *client, kal_int32 size, med_mem_type_enum type, char* file_p, long line_p)
{
    void* mem_p = NULL;

    switch(type)
    {
    #ifndef __VIDEO_STANDALONE_MEMORY__
        case MED_MEM_NONCACHE:
            mem_p = (void*) med_alloc_mem(vid_context_p->rec_app_id, size, file_p, line_p);
            break;
        case MED_MEM_CACHE:
            mem_p = (void*) med_alloc_mem_cacheable(vid_context_p->rec_app_id, size, file_p, line_p);
            break;
    #else
        case MED_MEM_NONCACHE:
            mem_p = (void*) med_alloc_vid_mem(size);
            break;
        case MED_MEM_CACHE:
            mem_p = (void*) med_alloc_vid_mem_cacheable(size);
            break;
    #endif
        case MED_MEM_AUD_RINGBUFF:
            aud_util_alloc_ring_buffer_w_log(file_p,line_p,size,(kal_uint16**)&mem_p);
            break;
        default:
            break;
    }

    return (mem_p);
}

static void vid_free_ext_mem_impl(mpl_recorder_client_t *client, void** p, med_mem_type_enum type, char* file_p, long line_p)
{
    if (*p)
    {
        switch(type)
        {
            case MED_MEM_NONCACHE:
            case MED_MEM_CACHE:
                #ifndef __VIDEO_STANDALONE_MEMORY__
                med_free_mem(vid_context_p->rec_app_id,p,file_p,line_p);
                #else
                med_free_vid_mem(p);
                #endif
                break;
            case MED_MEM_AUD_RINGBUFF:
                aud_util_free_ring_buffer_w_log(file_p,line_p,(kal_uint16**)p);
                break;
            default:
                break;
        }

        *p = NULL;
    }
}


med_result_enum vid_construct_recorder(kal_uint8 bit_stream_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_result_enum ret = MED_RES_MEM_INSUFFICIENT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(recorder_p==NULL);

    mpl_recorder_client.mpl_mem_alloc_func_t = vid_alloc_ext_mem_impl;
    mpl_recorder_client.mpl_mem_free_func_t = vid_free_ext_mem_impl;
    mpl_recorder_client.on_event_callback = vid_recorder_client_cb;

    
    switch(bit_stream_type)
    {
#if defined(MP4_ENCODE) || defined(H264_ENCODE)
        case MPL_RECORDER_FORMAT_MPEG4:
        case MPL_RECORDER_FORMAT_H263:
        case MPL_RECORDER_FORMAT_H264:
        #ifdef __STREAM_SERVER_SUPPORT__
        if(vid_context_p->src_mod == MOD_RTSP)
    	{
        	recorder_p = construct_rtp_recorder(&mpl_recorder_client);
        }
        else
        {
        	recorder_p = construct_mp4_recorder(&mpl_recorder_client);
        }
        	
        #else
        recorder_p = construct_mp4_recorder(&mpl_recorder_client);
        #endif
            break;
#endif /* MP4_ENCODE || H264_ENCODE */
#if defined(MJPG_ENCODE)
        case MPL_RECORDER_FORMAT_MJPEG:
        recorder_p = construct_avi_recorder(&mpl_recorder_client);
            break;
#endif /* MJPG_ENCODE*/
        default:
            ret = MED_RES_UNSUPPORTED_TYPE;
            break;

    }

        if (recorder_p!=NULL)
        {
            ret = MED_RES_OK;
        }

    return ret;
}
#pragma arm section code, rodata

CAL_ISP_VIDEO_STRUCT cal_isp_video_data;
CAL_MDP_VIDEO_STRUCT cal_mdp_video_data;
CAL_LCD_STRUCT cal_lcd_data;
CAL_CAMERA_VIDEO_RECORD_STRUCT cal_video_recorder_data;
CAL_SCENARIO_CTRL_STRUCT cal_video_scenario_para;

#pragma arm section code = "DYNAMIC_CODE_MWREC_ROCODE", rodata = "DYNAMIC_CODE_MWREC_RODATA"
static med_result_enum vid_get_result_from_cal_error_enum(MM_ERROR_CODE_ENUM mm_error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_result_enum ret = MED_RES_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mm_error_code)
    {
        case MM_ERROR_NONE:
            ret = MED_RES_OK;
            break;
        default:
            ret = MED_RES_FAIL;
            break;
    }
    return ret;
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  vid_focus_callback
 * DESCRIPTION
 *  This function is to handle camera focus callback.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAM_AUTO_FOCUS__)
static void vid_focus_callback(void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    P_CAL_CAMERA_AF_RESULT_STRUCT pAfResult;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pAfResult = (P_CAL_CAMERA_AF_RESULT_STRUCT)pCallbackPara;

    kal_mem_cpy((void*)&vid_context_p->af_result, (void*)pAfResult, sizeof(CAL_CAMERA_AF_RESULT_STRUCT));
    
    vid_send_event_ind(VID_EVT_AUTOFOCUS, (kal_int32)pAfResult->AfSearchResult);
}
#endif    

#pragma arm section code = "DYNAMIC_CODE_MWREC_ROCODE", rodata = "DYNAMIC_CODE_MWREC_RODATA"
static MM_ERROR_CODE_ENUM vid_cal_callback(CAL_CALLBACK_ID_ENUM cbid, void *pCallbackPara, kal_uint16 CallbackParaLen)
{
    kal_trace(TRACE_GROUP_4,VID_TRC_CAL_CALLBACK,cbid);
#if defined(__CAM_AUTO_FOCUS__)
    if (cbid == CAL_CBID_AF_RESULT)
    {
        vid_focus_callback(pCallbackPara, CallbackParaLen);
    }
#endif
    return MM_ERROR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  vid_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle camera event indication.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_event_ind_hdlr(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_event_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_event_ind_struct*) ilm_ptr->local_para_ptr;
    if (ind_p->event == VID_EVT_MPL_EVENT)
    {
        vid_recorder_mpl_event_hdlr((media_error_t)ind_p->cause);
    }
    else if (ind_p->event == VID_EVT_MPL_STOP)
    {
        vid_recorder_mpl_stop_hdlr((media_error_t)ind_p->cause);
    }
    else if (ind_p->event == VID_EVT_MPL_SAVE)
    {
        vid_recorder_mpl_save_hdlr((media_error_t)ind_p->cause);
    }
#if defined(__CAM_AUTO_FOCUS__)
    else if ((ind_p->event == VID_EVT_AUTOFOCUS))
    {
        vid_send_autofocus_process_done_ind(ind_p->cause, vid_context_p->af_result.AfSuccessZone);
    }
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  vid_recorder_set_param_req_hdlr
 * DESCRIPTION
 *  This function is to handle video set parameter request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_recorder_set_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_rec_set_param_req_struct *req_p;
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    MM_ERROR_CODE_ENUM ret;
    med_result_enum result = MED_RES_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_rec_set_param_req_struct*) ilm_ptr->local_para_ptr;

    if (vid_context_p->is_power_on)
    {
        /* CAL param only for now */
        CalInPara.FeatureId = req_p->param_id;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalInPara.FeatureSetValue = req_p->value;
        ret = CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL); 

        vid_set_result(ret,__LINE__);
    }
    else
    {
        vid_set_result(result,__LINE__);
    }
        
    vid_set_event(VID_EVT_SET_PARAM);
}
        

static void vid_recorder_query_sw_rotator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_FEATURE_CTRL_STRUCT FeatureIn;
    CAL_FEATURE_CTRL_STRUCT FeatureOut;
    CAL_FEATURE_CAMERA_QUERY_SW_ROTATE_IN_STRUCT SwRotIn;
    CAL_FEATURE_CAMERA_QUERY_SW_ROTATE_OUT_STRUCT SwRotOut;
    kal_uint32 FeatureOutLen;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    SwRotIn.ScenarioId=CAL_SCENARIO_VIDEO;                                         
    SwRotIn.DisplayImageRotAngle=vid_context_p->preview_rotate;   
    SwRotIn.TargetImageRotAngle=vid_context_p->encode_rotate;
    FeatureIn.FeatureInfo.FeatureStructured.pCamSwRotInPara=&SwRotIn;
    FeatureIn.FeatureId=CAL_FEATURE_CAMERA_QUERY_SW_ROTATE;
    FeatureIn.FeatureCtrlCode=CAL_FEATURE_QUERY_OPERATION;
    FeatureOut.FeatureInfo.FeatureStructured.pCamSwRotOutPara=&SwRotOut;
    CalCtrl(CAL_FEATURE_CTRL, &FeatureIn, &FeatureOut, sizeof(FeatureOut), &FeatureOutLen);

    vid_context_p->is_using_sw_rotator = SwRotOut.RequireSwRotate;

}

        
/*****************************************************************************
 * FUNCTION
 *  vid_recorder_init
 * DESCRIPTION
 *  deinit recorder 
 * PARAMETERS
 *  arg       [IN]        NOT USED
 * RETURNS
 *  void
 *****************************************************************************/
static med_result_enum vid_recorder_init(media_vid_preview_req_struct* preview_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mpl_recorder_open_param_t open_param;
    media_error_t ret = MED_S_OK;
    med_result_enum result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
        
    ASSERT(recorder_p==NULL);

    result = vid_construct_recorder(preview_data_p->bit_stream_type);

    if (result != MED_RES_OK)
    {
        return result;
    }

    recorder_p->get_default(recorder_p,MPL_RECORDER_PARAM_TYPE_OPEN, &open_param, sizeof(open_param));

    open_param.image_width = preview_data_p->image_width;
    open_param.image_height = preview_data_p->image_height;
    open_param.format = (mpl_recorder_format_enum_t)preview_data_p->bit_stream_type;
    open_param.quality = (mpl_recorder_quality_enum_t)preview_data_p->encode_quality;
    open_param.storage = (mpl_recorder_storage_enum_t)preview_data_p->storage;
    open_param.fgRecordYuv = vid_context_p->is_rec_yuv;

    if (vid_context_p->is_using_sw_rotator == KAL_TRUE)
    {
        open_param.eSoftwareRotator = MPL_RECORDER_SOFTWARE_ROTATOR_ENABLED;
    }
    else
    {
        open_param.eSoftwareRotator = MPL_RECORDER_SOFTWARE_ROTATOR_DISABLED;
    }

    // modified Vincent
    switch(preview_data_p->bit_stream_type)
    {
#if defined(MP4_ENCODE) || defined(H264_ENCODE)
        case MPL_RECORDER_FORMAT_MPEG4:
        case MPL_RECORDER_FORMAT_H263:
            open_param.user = MPL_RECORDER_USER_RECORDER;
            break;
        case MPL_RECORDER_FORMAT_H264:
            open_param.user = MPL_RECORDER_USER_RECORDER_H264;
            break;
#endif /* MP4_ENCODE || H264_ENCODE */
#if defined(MJPG_ENCODE)
        case MPL_RECORDER_FORMAT_MJPEG:
            open_param.user = MPL_RECORDER_USER_RECORDER;
            break;
#endif            
      }

    #if defined(__TIME_LAPSE_VIDEO_RECORDER__)
    recorder_p->set_param(recorder_p,MPL_RECORDER_PARAM_TIME_LAPSE_ENCODE_ONE_OF_N_SEC,(void*)preview_data_p->encode_one_frame_duration,sizeof(preview_data_p->encode_one_frame_duration));    
    vid_context_p->encode_one_frame_duration = preview_data_p->encode_one_frame_duration;
    #else
    vid_context_p->encode_one_frame_duration = 0;
    #endif
    #ifdef __STREAM_SERVER_SUPPORT__
    if(vid_context_p->src_mod == MOD_RTSP)
    {
    	recorder_p->set_param(recorder_p,MPL_RECORDER_PARAM_SET_VIDEO_RTP_HANDLE,(void*)preview_data_p->video_rtp_handle,sizeof(preview_data_p->video_rtp_handle));
		recorder_p->set_param(recorder_p,MPL_RECORDER_PARAM_SET_AUDIO_RTP_HANDLE,(void*)preview_data_p->audio_rtp_handle,sizeof(preview_data_p->audio_rtp_handle));    
	}
    #endif
    ret = recorder_p->open(recorder_p,&open_param);

    vid_context_p->bit_stream_type = preview_data_p->bit_stream_type;
       
    return med_error_to_result_enum(ret);

}

/*****************************************************************************
 * FUNCTION
 *  vid_recorder_deinit
 * DESCRIPTION
 *  deinit recorder 
 * PARAMETERS
 *  arg       [IN]        NOT USED
 * RETURNS
 *  void
 *****************************************************************************/
med_result_enum vid_recorder_deinit(void)
{
    if (recorder_p != NULL)
    {
        recorder_p->close(recorder_p);
        recorder_p->destroy(recorder_p);
        recorder_p = NULL;
    }
    return MED_RES_OK;
}

static void vid_recorder_deinit_and_release_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_recorder_deinit(); // close record fil, deinit MPL recorder
    vid_release_memory();  // release CAL working memory
}


med_result_enum vid_recorder_get_current_record_time(kal_uint64 *current_record_time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_error_t ret = MED_S_OK;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (recorder_p == NULL)
    {
        *current_record_time_p = 0;
    }
    else
    {
        ret = recorder_p->get_param(recorder_p,MPL_RECORDER_PARAM_RECORDED_TIME,current_record_time_p,sizeof(current_record_time_p));
    }
    
    return med_error_to_result_enum(ret);
}


med_result_enum vid_recorder_get_current_record_frame_num(kal_uint64 *current_record_frame_num_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_error_t ret = MED_S_OK;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (recorder_p == NULL)
    {
        *current_record_frame_num_p = 0;
    }
    else
    {
        #if defined(__TIME_LAPSE_VIDEO_RECORDER__)
        ret = recorder_p->get_param(recorder_p,MPL_RECORDER_PARAM_TIME_LAPSE_GET_ENCODED_FRAME_NUM,current_record_frame_num_p,sizeof(current_record_frame_num_p));
        #else
        *current_record_frame_num_p = 0;
        #endif
    }



    return med_error_to_result_enum(ret);
}


static med_result_enum vid_recorder_get_current_record_size(kal_uint64 *current_record_size_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_error_t ret = MED_S_OK;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (recorder_p == NULL)
    {
        *current_record_size_p= 0;
    }
    else
    {
        ret = recorder_p->get_param(recorder_p,MPL_RECORDER_PARAM_RECORDED_SIZE,current_record_size_p,sizeof(current_record_size_p));
    }
    
    return med_error_to_result_enum(ret);
}

static med_result_enum vid_cal_start_preview(media_vid_preview_req_struct* preview_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
    med_result_enum ret_value = MED_RES_OK ;
    mpl_get_buffer_pfn_t pfVideoGetBuff;
    mpl_return_buffer_pfn_t pfVideoRetBuff;
    kal_uint32 fps,bitrate;
    kal_uint32 frame_rate = 0;
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    if (vid_context_p->included_angle == MM_IMAGE_ROTATE_90 || vid_context_p->included_angle == MM_IMAGE_ROTATE_270)
    {
        vid_context_p->display_width = preview_struct->preview_height;
        vid_context_p->display_height = preview_struct->preview_width;            
        vid_context_p->image_width = preview_struct->image_height;
        vid_context_p->image_height = preview_struct->image_width;
    }
    else
    {
        vid_context_p->display_width = preview_struct->preview_width;
        vid_context_p->display_height = preview_struct->preview_height;
        vid_context_p->image_width = preview_struct->image_width;
        vid_context_p->image_height = preview_struct->image_height;
    }

    recorder_p->get_param(recorder_p,MPL_RECORDER_PARAM_GET_BUFFER_PFN,(void*)&pfVideoGetBuff,sizeof(mpl_get_buffer_pfn_t));    
    recorder_p->get_param(recorder_p,MPL_RECORDER_PARAM_RETURN_BUFFER_PFN,(void*)&pfVideoRetBuff,sizeof(mpl_return_buffer_pfn_t));


    cal_mdp_video_data.pfGetVideoBuff=pfVideoGetBuff;
    cal_mdp_video_data.pfRetVideoBuff=pfVideoRetBuff;
    cal_mdp_video_data.DisplayImageRotAngle= vid_context_p->preview_rotate;
    cal_mdp_video_data.DisplayImageDataFormat=(MM_IMAGE_FORMAT_ENUM)preview_struct->image_data_format;
    cal_mdp_video_data.DisplayImageWidth=vid_context_p->display_width;
    cal_mdp_video_data.DisplayImageHeight=vid_context_p->display_height;

    cal_mdp_video_data.FrameBuffAddr1=vid_context_p->frame_buffer_address_1=preview_struct->frame_buffer_addr1;
    cal_mdp_video_data.FrameBuffSize=vid_context_p->frame_buffer_size = preview_struct->frame_buffer_size;

#if defined(DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT)
    if (preview_struct->frame_buffer_size%32 != 0 || ((preview_struct->frame_buffer_addr1 & 0x0000001f)!=0 ) )
    {
        vid_context_p->rec_align_buffer_size = ((preview_struct->frame_buffer_size+31) >> 5) << 5;
        vid_context_p->rec_align_buffer_address = (kal_uint32)med_alloc_asm_mem_framebuffer(vid_context_p->rec_app_id,vid_context_p->rec_align_buffer_size);
        if (vid_context_p->rec_align_buffer_address == NULL)
            return MED_RES_MEM_INSUFFICIENT;

        cal_mdp_video_data.FrameBuffAddr1 = vid_context_p->rec_align_buffer_address;
        preview_struct->frame_buffer_size = vid_context_p->rec_align_buffer_size;
    }
    else
    {
        vid_context_p->rec_align_buffer_size = 0;
        vid_context_p->rec_align_buffer_address = NULL;
    }
#endif

    if (preview_struct->frame_buffer_size > 0)
    {
        vid_context_p->frame_buffer_address_2 = (kal_uint32)med_alloc_asm_mem_framebuffer(vid_context_p->rec_app_id,preview_struct->frame_buffer_size);

        if (vid_context_p->frame_buffer_address_2 == NULL)
        return MED_RES_MEM_INSUFFICIENT;

    #ifdef MDP_SUPPORT_VR_TRIPLE_DISPLAY_BUFFER
        vid_context_p->frame_buffer_address_3 = (kal_uint32)med_alloc_asm_mem_framebuffer(vid_context_p->rec_app_id,preview_struct->frame_buffer_size);
    #endif
    #if defined(MT6260)
    #if (LCD_HEIGHT > 480) || (LCD_WIDTH > 480)
        {
            CAL_FEATURE_CTRL_STRUCT CalFeaturePara;
            CAL_CAMERA_GET_PREVIEW_IMAGE_STRUCT CamGetPreviewImageInPara;
            
            CalFeaturePara.FeatureId=CAL_FEATURE_CAMERA_PREVIEW_SIZE;
            CalFeaturePara.FeatureCtrlCode=CAL_FEATURE_QUERY_OPERATION;
            CalFeaturePara.FeatureInfo.FeatureStructured.pCamGetPreviewImageInPara=&CamGetPreviewImageInPara;
            CalCtrl(CAL_FEATURE_CTRL, &CalFeaturePara, &CalFeaturePara, sizeof(CalFeaturePara), NULL);
        
            vid_context_p->frame_buffer_address_temp = (kal_uint32) med_alloc_asm_mem_framebuffer(vid_context_p->rec_app_id, (CamGetPreviewImageInPara.ImageWidth*CamGetPreviewImageInPara.ImageHeight)<<1);
        }
    #endif
    #endif
    }
    cal_mdp_video_data.FrameBuffAddr2=vid_context_p->frame_buffer_address_2;
    cal_mdp_video_data.FrameBuffAddr3=vid_context_p->frame_buffer_address_3;
    cal_mdp_video_data.FrameBuffAddrTemp=vid_context_p->frame_buffer_address_temp;

    cal_mdp_video_data.VideoEncodeEnable=KAL_TRUE;
#ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_TAG__
    cal_mdp_video_data.VideoImageRotAngle = MM_IMAGE_ROTATE_0;
#else
    cal_mdp_video_data.VideoImageRotAngle = vid_context_p->encode_rotate;
#endif
    cal_mdp_video_data.VideoImageWidth=vid_context_p->image_width;
    cal_mdp_video_data.VideoImageHeight=vid_context_p->image_height;
    cal_mdp_video_data.LcdUpdateEnable=preview_struct->lcd_update;
    cal_mdp_video_data.ForceLcdHwTrigger=preview_struct->force_lcd_hw_trigger;
    cal_mdp_video_data.VideoImageQuality = preview_struct->encode_quality;

#ifdef __CAL_VIDEO_MJPEG_DIRECT_COUPLE_SUPPORT__     
    if (preview_struct->bit_stream_type==MPL_RECORDER_FORMAT_MJPEG)
        cal_mdp_video_data.VideoImageDataFormat=MM_IMAGE_FORMAT_JPEG;
    else
#endif
    {  
        cal_mdp_video_data.VideoImageDataFormat=MM_IMAGE_FORMAT_YUV420;
    }

    if (preview_struct->scene_mode == CAM_VIDEO_NIGHT)
    {
        CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_SENSOR_NIGHT_FRAME_RATE, NULL,0,&fps, sizeof(fps));
        cal_isp_video_data.MaxVideoFrameRate = vid_context_p->sensor_frame_rate = fps;        

        CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_ENCODER_NIGHT_FRAME_RATE, NULL,0,&fps, sizeof(fps));
        cal_mdp_video_data.VtEncodeFrameRate = vid_context_p->encode_frame_rate = fps;

        kal_trace(TRACE_GROUP_4,VID_TRC_NIGHT_MODE_FRAMERATE,cal_mdp_video_data.VtEncodeFrameRate,cal_isp_video_data.MaxVideoFrameRate);
    }
    else
    {
        CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_SENSOR_FRAME_RATE, NULL,0,&fps, sizeof(fps));
        cal_isp_video_data.MaxVideoFrameRate = vid_context_p->sensor_frame_rate = fps;

        CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_ENCODER_FRAME_RATE, NULL,0,&fps, sizeof(fps));
        cal_mdp_video_data.VtEncodeFrameRate = vid_context_p->encode_frame_rate = fps;
        kal_trace(TRACE_GROUP_4,VID_TRC_NORMAL_MODE_FRAMERATE,cal_mdp_video_data.VtEncodeFrameRate,cal_isp_video_data.MaxVideoFrameRate);
    }

    CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_BIT_RATE, NULL, 0, &bitrate, sizeof(bitrate));
    
    vid_context_p->bitrate = bitrate;       
    
    recorder_p->set_param(recorder_p,MPL_RECORDER_PARAM_SET_FRAME_RATE,(void*)vid_context_p->encode_frame_rate,sizeof(vid_context_p->encode_frame_rate));
    #if defined(__TIME_LAPSE_VIDEO_RECORDER__)
    if (vid_context_p->encode_one_frame_duration > 0)
    {
        CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_ENCODER_FRAME_RATE, NULL,0,&frame_rate, sizeof(frame_rate));
    }
    
    recorder_p->set_param(recorder_p,MPL_RECORDER_PARAM_TIME_LAPSE_SET_PLAYBACK_FPS,(void*)frame_rate,sizeof(frame_rate));
    #endif
    
    cal_isp_video_data.ZoomStep = preview_struct->zoom_step;
    cal_isp_video_data.ContrastLevel=(CAL_CAMERA_CONTRAST_ENUM)preview_struct->contrast;
    cal_isp_video_data.BrightnessLevel=(kal_uint8)preview_struct->brightness; // for YUV only
    cal_isp_video_data.SaturationLevel=(CAL_CAMERA_SATURATION_ENUM)preview_struct->saturation;
    cal_isp_video_data.SharpnessLevel=(CAL_CAMERA_SHARPNESS_ENUM)preview_struct->sharpness;
    cal_isp_video_data.WbMode=(CAL_CAMERA_WB_ENUM)preview_struct->WB;
    cal_isp_video_data.EvValue=(CAL_CAMERA_EV_ENUM)preview_struct->exposure;
    cal_isp_video_data.BandingFreq=(CAL_CAMERA_BANDING_FREQ_ENUM)preview_struct->banding_freq;
    cal_isp_video_data.ImageEffect=(CAL_CAMERA_IMAGE_EFFECT_ENUM)preview_struct->effect;
    cal_isp_video_data.VideoSceneMode=(CAL_CAMERA_VIDEO_SCENE_MODE_ENUM)preview_struct->scene_mode;
    cal_isp_video_data.AfOperationMode=(CAL_CAMERA_AF_OPERATION_MODE_ENUM)preview_struct->af_operation_mode;
    cal_isp_video_data.AfRange=(CAL_CAMERA_AF_RANGE_ENUM)preview_struct->af_range;
    cal_isp_video_data.HueValue=preview_struct->hue; // for YUV only

    if ((CAL_VIDEO_EXT_MEMORY_SIZE)>0)
    {
        vid_context_p->extmem_start_address = (kal_uint32)med_alloc_asm_mem(vid_context_p->rec_app_id,CAL_VIDEO_EXT_MEMORY_SIZE);   

        if (vid_context_p->extmem_start_address == NULL)
        return MED_RES_MEM_INSUFFICIENT;
    }

    cal_video_recorder_data.ExtmemStartAddress=vid_context_p->extmem_start_address;
    cal_video_recorder_data.ExtmemSize=vid_context_p->extmem_size=CAL_VIDEO_EXT_MEMORY_SIZE;

    cal_lcd_data.WfcElementHandle = preview_struct->layer_element;
    cal_lcd_data.WfcContextHandle = preview_struct->blt_ctx;
    cal_lcd_data.WfcDeviceHandle = preview_struct->blt_dev;

    cal_video_recorder_data.pLcdPara=&cal_lcd_data;
    cal_video_recorder_data.pMdpPara=&cal_mdp_video_data;
    cal_video_recorder_data.pIspPara=&cal_isp_video_data;

    cal_video_scenario_para.ScenarioId=CAL_SCENARIO_VIDEO;
    cal_video_scenario_para.ScenarioCtrlCode=CAL_CTRL_CODE_START;
    cal_video_scenario_para.ScenarioCtrlParaLen=sizeof(CAL_CAMERA_VIDEO_RECORD_STRUCT);
    cal_video_scenario_para.pScenarioCtrlPara=&cal_video_recorder_data;


    ret = CalCtrl(CAL_SCENARIO_CTRL, (void *) &cal_video_scenario_para, NULL, 0, NULL);

//    ASSERT(ret == MM_ERROR_NONE);
    ret_value = vid_get_result_from_cal_error_enum(ret);

    return ret_value;
}

med_result_enum vid_cal_stop_fast_zoom(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_FEATURE_CTRL_STRUCT fast_zoom_ctrl;
    CAL_CAMERA_FAST_ZOOM_STRUCT fast_zoom_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(vid_context_p->is_fast_zoom == KAL_TRUE)
    {
        fast_zoom_data.ZoomStart = KAL_FALSE;
        
        fast_zoom_ctrl.FeatureId =  CAL_FEATURE_CAMERA_FAST_ZOOM;
        fast_zoom_ctrl.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        fast_zoom_ctrl.FeatureModeSupport = CAL_FEATURE_VIDEO_SUPPORT;
        fast_zoom_ctrl.FeatureType = CAL_FEATURE_TYPE_STRUCTURED;
        fast_zoom_ctrl.FeatureInfo.FeatureStructured.pCamFastZoom = &fast_zoom_data; 
        CalCtrl(CAL_FEATURE_CTRL,(void*)&fast_zoom_ctrl,NULL,0,NULL);
        //ASSERT(ret == MM_ERROR_NONE);
        vid_context_p->is_fast_zoom = KAL_FALSE;
    }

    return MED_RES_OK;
}



med_result_enum vid_cal_stop_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CAL_SCENARIO_CTRL_STRUCT stopPreviewCtrl;
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
    med_result_enum ret_value = MED_RES_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_cal_stop_fast_zoom();

    stopPreviewCtrl.ScenarioId=CAL_SCENARIO_VIDEO;
    stopPreviewCtrl.ScenarioCtrlCode=CAL_CTRL_CODE_STOP;
    stopPreviewCtrl.ScenarioCtrlParaLen=0;
    stopPreviewCtrl.pScenarioCtrlPara=NULL;

    ret = CalCtrl(CAL_SCENARIO_CTRL, (void *) &stopPreviewCtrl, NULL, 0, NULL);

    ASSERT(ret == MM_ERROR_NONE);
    ret_value = vid_get_result_from_cal_error_enum(ret);

    vid_recorder_recover_preview_buffer();

    return ret_value;    
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  vid_get_focus_zone_req_hdlr
 * DESCRIPTION
 *  This function is to get af zone from drv and return the values to MMI
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_get_focus_zone_req_hdlr(ilm_struct* ilm_ptr)
{
#ifdef __CAM_AUTO_FOCUS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_af_get_zone_struct *req_p;
    media_vid_af_zone_para_struct *zone_para_p;
    CAL_FEATURE_CTRL_STRUCT CalInPara, CalOutPara;
    P_CAL_CAMERA_GET_AF_ZONE_STRUCT pAFInfo;
    kal_uint8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_af_get_zone_struct*) ilm_ptr->local_para_ptr;
    zone_para_p = req_p->zone_para_p;

    if (VID_IN_STATE(VID_PREVIEW))
    {
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_GET_AF_ZONE;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;

        CalCtrl(CAL_FEATURE_CTRL, &CalInPara, &CalOutPara, sizeof(CalOutPara), NULL);
        
        pAFInfo = CalOutPara.FeatureInfo.FeatureStructured.pCamGetAfZoneOutPara;
        zone_para_p->af_active_zone = pAFInfo->AfActiveZone;
        kal_mem_cpy((void*)&(zone_para_p->af_zone), (void*)&(pAFInfo->AfZoneLcd), sizeof(pAFInfo->AfZoneLcd));

        if (vid_context_p->included_angle == MM_IMAGE_ROTATE_90 || vid_context_p->included_angle == MM_IMAGE_ROTATE_270)
        {
            for (i = 0; i < MEDIA_CAM_AF_ZONE_MAX_NO; i++)
            {
                zone_para_p->af_zone[i].af_zone_w = pAFInfo->AfZoneLcd[i].H;
                zone_para_p->af_zone[i].af_zone_h = pAFInfo->AfZoneLcd[i].W;

                zone_para_p->af_zone[i].af_zone_x = pAFInfo->AfZoneLcd[i].Y;
                zone_para_p->af_zone[i].af_zone_y = pAFInfo->AfZoneLcd[i].X;

                kal_trace(TRACE_GROUP_4,VID_TRC_AF_ZONE_INFO,i,zone_para_p->af_zone[i].af_zone_x,zone_para_p->af_zone[i].af_zone_y,zone_para_p->af_zone[i].af_zone_w,zone_para_p->af_zone[i].af_zone_h);
            }
        }        
        
    }
    else
    {
        ASSERT(0);
    }   
    vid_set_event(VID_EVT_BLOCK);
#else
    ASSERT(0);
#endif

}




/*****************************************************************************
 * FUNCTION
 *  vid_power_up_req_hdlr
 * DESCRIPTION
 *  This function is to handle power up request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_MWREC_ROCODE", rodata = "DYNAMIC_CODE_MWREC_RODATA"
void vid_power_up_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_power_up_req_struct *req_p;
    CAL_FEATURE_CTRL_STRUCT sourceSelectCtrl;
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
    kal_int32 result = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_power_up_req_struct*) ilm_ptr->local_para_ptr;

    vid_context_p->seq_num = req_p->seq_num;
    vid_context_p->cam_id = req_p->cam_id;
    vid_context_p->rec_app_id = req_p->app_id;
    vid_context_p->bitrate = 0;
    if (vid_context_p->is_power_on == KAL_FALSE)
    {
        sourceSelectCtrl.FeatureId =  CAL_FEATURE_CAMERA_SOURCE_SELECT;
        sourceSelectCtrl.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        sourceSelectCtrl.FeatureSetValue = vid_context_p->cam_id;
        sourceSelectCtrl.FeatureModeSupport = CAL_FEATURE_VIDEO_SUPPORT;

        CalCtrl(CAL_FEATURE_CTRL,(void*)&sourceSelectCtrl,NULL,0,NULL);

        ret = CalOpen(&vid_cal_callback);

        if (ret == MM_ERROR_NONE)
        {
            vid_context_p->is_power_on = KAL_TRUE;            
        }
        else
        {
            result = MED_RES_FAIL;
        }
    }
    VID_SET_RESULT_EVENT(result, VID_EVT_POWER_ON, __LINE__);
}

/*****************************************************************************
 * FUNCTION
 *  vid_power_down_req_hdlr
 * DESCRIPTION
 *  This function is to handle power down request.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_power_down_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (!VID_IN_STATE(VID_IDLE))
    {
        ASSERT((!VID_IN_STATE(VID_RECORD)) && (!VID_IN_STATE(VID_RECORD_PAUSED)));

        if (VID_IN_STATE(VID_PREVIEW))
        {
            vid_cal_stop_preview();
            vid_release_memory();
        }        

        if (!VID_IN_STATE(VID_FILE_MERGE)&&!VID_IN_STATE(VID_FILE_MERGE_STOPPING))
        {
            VID_ENTER_STATE(VID_IDLE);            
        }
    }

    if (vid_context_p->is_power_on == KAL_TRUE)
    {
        CalClose();    
        vid_context_p->is_power_on = KAL_FALSE;
    }

    vid_set_event(VID_EVT_POWER_ON);    
    
}


static void vid_calc_rotation_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MM_IMAGE_ROTATE_ENUM PreviewRotate = MM_IMAGE_ROTATE_0;
    MM_IMAGE_ROTATE_ENUM EncodeRotate = MM_IMAGE_ROTATE_0;
    MM_IMAGE_ROTATE_ENUM IncludedAngle = MM_IMAGE_ROTATE_0; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #define VID_ABS(val) (((val) < 0) ? -(val) : (val))
    
    if (vid_context_p->lcd_id == MAIN_LCD) // MainLCD
    {           
        if (vid_context_p->cam_id == CAL_CAMERA_SOURCE_MAIN)
        {
            PreviewRotate = VID_MAIN_SENSOR_ROTATE;
        #if defined(SENSOR_INSIDE_CLAM)
            PreviewRotate += MM_IMAGE_ROTATE_180;
        #endif
            IncludedAngle = (MM_IMAGE_ROTATE_ENUM)VID_ABS(vid_context_p->ui_rot_angle - VID_MAIN_SENSOR_ROTATE);

            PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((PreviewRotate + MAIN_LCM_CROSS_SENSOR_ANGLE) % 4);
            EncodeRotate = (MM_IMAGE_ROTATE_ENUM)((VID_MAIN_SENSOR_ROTATE + (((MM_IMAGE_ROTATE_180 + MM_IMAGE_ROTATE_180) - vid_context_p->ui_rot_angle )%4))%4);

            if (VID_MAIN_SENSOR_MIRROR)
            {
                if ((MM_IMAGE_ROTATE_90==IncludedAngle) || (MM_IMAGE_ROTATE_270==IncludedAngle))
                {
                    EncodeRotate = (MM_IMAGE_ROTATE_ENUM)((VID_MAIN_SENSOR_ROTATE + MM_IMAGE_ROTATE_180 + (((MM_IMAGE_ROTATE_180 + MM_IMAGE_ROTATE_180) - vid_context_p->ui_rot_angle )%4))%4);
                }

                if ((MM_IMAGE_ROTATE_90==PreviewRotate) || (MM_IMAGE_ROTATE_270==PreviewRotate))
                    PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((PreviewRotate+MM_IMAGE_ROTATE_180)%4);

                PreviewRotate += MM_IMAGE_H_MIRROR;
                EncodeRotate += MM_IMAGE_H_MIRROR;
            }
        }
    #ifdef DUAL_CAMERA_SUPPORT
        else
        {
            PreviewRotate = VID_SUB_SENSOR_ROTATE;
            IncludedAngle = (MM_IMAGE_ROTATE_ENUM)VID_ABS(vid_context_p->ui_rot_angle - VID_SUB_SENSOR_ROTATE);

            PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((PreviewRotate + MAIN_LCM_CROSS_SENSOR_ANGLE) % 4);
            EncodeRotate = (MM_IMAGE_ROTATE_ENUM)((VID_SUB_SENSOR_ROTATE + (((MM_IMAGE_ROTATE_180 + MM_IMAGE_ROTATE_180) - vid_context_p->ui_rot_angle )%4))%4);

            if (VID_SUB_SENSOR_MIRROR)
            {
                if ((MM_IMAGE_ROTATE_90==IncludedAngle) || (MM_IMAGE_ROTATE_270==IncludedAngle))
                {
                    EncodeRotate = (MM_IMAGE_ROTATE_ENUM)((VID_SUB_SENSOR_ROTATE + MM_IMAGE_ROTATE_180 + (((MM_IMAGE_ROTATE_180 + MM_IMAGE_ROTATE_180) - vid_context_p->ui_rot_angle )%4))%4);
                }

                if ((MM_IMAGE_ROTATE_90==PreviewRotate) || (MM_IMAGE_ROTATE_270==PreviewRotate))
                    PreviewRotate = (PreviewRotate+MM_IMAGE_ROTATE_180)%4;

                PreviewRotate += MM_IMAGE_H_MIRROR;
                EncodeRotate += MM_IMAGE_H_MIRROR;
            }
        }
    #endif /* DUAL_CAMERA_SUPPORT */        
    }
#ifdef DUAL_LCD    
    else // SubLCD
    {
        if (vid_context_p->cam_id == CAL_CAMERA_SOURCE_MAIN)
        {
            PreviewRotate = VID_MAIN_SENSOR_ROTATE;
            IncludedAngle = (MM_IMAGE_ROTATE_ENUM)VID_ABS(vid_context_p->ui_rot_angle- VID_MAIN_SENSOR_ROTATE);

            PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((PreviewRotate + SUB_LCM_CROSS_SENSOR_ANGLE) % 4);
            EncodeRotate = (MM_IMAGE_ROTATE_ENUM)((VID_MAIN_SENSOR_ROTATE + (((MM_IMAGE_ROTATE_180 + MM_IMAGE_ROTATE_180) - vid_context_p->ui_rot_angle )%4))%4);

            if (VID_MAIN_SENSOR_MIRROR)
            {
                if ((MM_IMAGE_ROTATE_90==IncludedAngle) || (MM_IMAGE_ROTATE_270==IncludedAngle))
                {
                    EncodeRotate = (MM_IMAGE_ROTATE_ENUM)((VID_MAIN_SENSOR_ROTATE + MM_IMAGE_ROTATE_180+ (((MM_IMAGE_ROTATE_180 + MM_IMAGE_ROTATE_180) - vid_context_p->ui_rot_angle )%4))%4);                    
                }

                if ((MM_IMAGE_ROTATE_90==PreviewRotate) || (MM_IMAGE_ROTATE_270==PreviewRotate))
                    PreviewRotate = (PreviewRotate+MM_IMAGE_ROTATE_180)%4;

                PreviewRotate += MM_IMAGE_H_MIRROR;
                EncodeRotate += MM_IMAGE_H_MIRROR;
            }
        }
    #ifdef DUAL_CAMERA_SUPPORT        
        else
        {
            PreviewRotate = VID_SUB_SENSOR_ROTATE;
            IncludedAngle = (MM_IMAGE_ROTATE_ENUM)(MM_IMAGE_ROTATE_ENUM)VID_ABS(vid_context_p->ui_rot_angle - VID_SUB_SENSOR_ROTATE);

            PreviewRotate = (MM_IMAGE_ROTATE_ENUM)((PreviewRotate + SUB_LCM_CROSS_SENSOR_ANGLE) % 4);
            EncodeRotate = (MM_IMAGE_ROTATE_ENUM)((VID_SUB_SENSOR_ROTATE + (((MM_IMAGE_ROTATE_180 + MM_IMAGE_ROTATE_180) - vid_context_p->ui_rot_angle )%4))%4);

            if (VID_SUB_SENSOR_MIRROR)
            {
                if ((MM_IMAGE_ROTATE_90==IncludedAngle) || (MM_IMAGE_ROTATE_270==IncludedAngle))
                {
                    EncodeRotate = (MM_IMAGE_ROTATE_ENUM)((VID_SUB_SENSOR_ROTATE + MM_IMAGE_ROTATE_180 + (((MM_IMAGE_ROTATE_180 + MM_IMAGE_ROTATE_180) - vid_context_p->ui_rot_angle )%4))%4);
                }

                if ((MM_IMAGE_ROTATE_90==PreviewRotate) || (MM_IMAGE_ROTATE_270==PreviewRotate))
                    PreviewRotate = (PreviewRotate+MM_IMAGE_ROTATE_180)%4;

                PreviewRotate += MM_IMAGE_H_MIRROR;
                EncodeRotate += MM_IMAGE_H_MIRROR;
            }
        }
    #endif /* DUAL_CAMERA_SUPPORT */        
    }
#endif /* DUAL_LCD */
    vid_context_p->included_angle = IncludedAngle;
    vid_context_p->preview_rotate = PreviewRotate;
    vid_context_p->encode_rotate = EncodeRotate;
    kal_prompt_trace(MOD_MED,"[VID]IncludedAngle=%d,PreviewRotate=%d,EncodeRotate=%d",IncludedAngle,PreviewRotate,EncodeRotate);
}
#ifdef __STREAM_SERVER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  vid_rtsp_init_preview_setting
 * DESCRIPTION
 *  Initialize default setting value for video preview/record structure.
 * PARAMETERS
 *  setting_p : [OUT]Setting data (All member data in its default values).
 * RETURNS
 *  void
 *****************************************************************************/
void vid_rtsp_init_preview_setting(media_vid_preview_req_struct *setting_p)
{
	
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	void * fb_ptr;
	kal_uint32 buffer_size;
	kal_uint16 width,height;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	width = LCD_WIDTH;//292;
	height = LCD_HEIGHT;//240;	
	buffer_size = width*height*2;
	//fb_ptr = med_alloc_asm_mem(vid_context_p->rec_app_id,buffer_size);
	fb_ptr = med_alloc_asm_mem_framebuffer(vid_context_p->rec_app_id,buffer_size);
    
	/* lcd */
	setting_p->layer_element = 0;//(kal_uint32)gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_MAIN_LCD].elm[0];
	setting_p->blt_ctx = 0;//(kal_uint32)gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_MAIN_LCD].ctx_handle;
	setting_p->blt_dev = 0;//(kal_uint32)gdi_lcd_v2_dev;
	setting_p->preview_offset_x = 0;
	setting_p->preview_offset_y = 0;
	setting_p->ui_rot_angle = VID_MAIN_SENSOR_ROTATE;
	setting_p->image_data_format = MM_IMAGE_FORMAT_PACKET_UYVY422;
	setting_p->preview_width = width;
	setting_p->preview_height = height;
	setting_p->frame_buffer_addr1 = (kal_uint32)fb_ptr;
	setting_p->frame_buffer_addr2 = (kal_uint32)fb_ptr;
	setting_p->frame_buffer_size = setting_p->preview_width * setting_p->preview_height * 2;
	setting_p->lcd_update = KAL_FALSE;//KAL_TRUE;
	setting_p->force_lcd_hw_trigger = KAL_FALSE;
	setting_p->lcd_id = MAIN_LCD;
		
	/* cal */
	setting_p->zoom_step = 0;
	setting_p->contrast = 128;
	setting_p->brightness = 128;
	setting_p->saturation = 128;
	setting_p->WB = CAM_WB_AUTO;
	setting_p->exposure = CAM_EV_ZERO;
	setting_p->effect = CAM_EFFECT_ENC_NORMAL;
	setting_p->sharpness = CAM_ADJUST_LOW_LEVEL;
	setting_p->banding_freq = CAM_BANDING_60HZ;
	setting_p->af_operation_mode = CAM_AF_OFF;
	setting_p->af_range = CAM_AF_RANGE_AUTO;
	setting_p->scene_mode = 0 ;//CAM_VIDEO_AUTO;
		
	setting_p->hue = 0;
	setting_p->gamma = 0; 
	setting_p->zoom_factor = 0;
	setting_p->flash_mode = CAM_FLASH_OFF;
	setting_p->night_mode = KAL_FALSE;
	
	setting_p->overlay_frame_mode = KAL_FALSE;
	setting_p->overlay_color_depth = 0;
	setting_p->overlay_frame_source_key = 0;
	setting_p->overlay_frame_width = 0;
	setting_p->overlay_frame_height = 0;
	setting_p->overlay_frame_buffer_address=0;
		
	/* mpl */
	setting_p->encode_one_frame_duration = 0; 
	//setting_p->image_width = 176;
	//setting_p->image_height = 144;
	setting_p->storage = MPL_RECORDER_STORAGE_CARD;
	//setting_p->encode_quality = MPL_RECORDER_QUALITY_NORMAL;
	//setting_p->bit_stream_type= MPL_RECORDER_FORMAT_MPEG4;
	
	setting_p->gray_mode = 0;
	setting_p->seq_num= 0;		
	
	//setting_p->audio_rtp_handle = 0;
	//setting_p->video_rtp_handle = 0; 
	
	kal_prompt_trace(MOD_MED,"[VID]preview_width %d,preview_height %d,frame_buffer_size %d",setting_p->preview_width,setting_p->preview_height,setting_p->frame_buffer_size);	
	kal_prompt_trace(MOD_MED,"[VID]image_width %d,image_height %d,bit_stream_type %d",setting_p->image_width,setting_p->image_height,setting_p->bit_stream_type);	

	
}


/*****************************************************************************
 * FUNCTION
 *  vid_rtsp_init_record_setting
 * DESCRIPTION
 *  Initialize default setting value for video preview/record structure.
 * PARAMETERS
 *  setting_p : [OUT]Setting data (All member data in its default values).
 * RETURNS
 *  void
 *****************************************************************************/
void vid_rtsp_init_record_setting(media_vid_record_req_struct *setting_p)
{
	
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	//setting_p->media_mode= MED_MODE_FILE;
	//setting_p->media_type= ;
	//setting_p->record_audio = KAL_TRUE;
	//setting_p->encode_quality= MPL_RECORDER_QUALITY_NORMAL;
	setting_p->encode_rotate = VID_MAIN_SENSOR_ROTATE;
	//setting_p->image_width= 176;
	//setting_p->image_height= 144;
	setting_p->file_size_limit= 0;
	setting_p->time_limit= 0;	
	
	kal_prompt_trace(MOD_MED,"[VID]codec:%d,quality:%d,resolution=%d x %d",vid_context_p->bit_stream_type,setting_p->encode_quality,setting_p->image_width,setting_p->image_height);
}

#endif 

/*****************************************************************************
 * FUNCTION
 *  vid_preview_req_hdlr
 * DESCRIPTION
 *  Handle video preview request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_preview_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_preview_req_struct *req_p;
    med_result_enum ret = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(TRACE_GROUP_4, VID_TRC_PREVIEW_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (VID_IN_STATE(VID_IDLE))
    {
        req_p = (media_vid_preview_req_struct*) ilm_ptr->local_para_ptr;

        //modify here to set param
        #ifdef __STREAM_SERVER_SUPPORT__
        vid_rtsp_init_preview_setting(req_p);
        #endif
        vid_context_p->lcd_id = req_p->lcd_id;
        vid_context_p->ui_rot_angle = req_p->ui_rot_angle;
        
        vid_calc_rotation_info();
        vid_recorder_query_sw_rotator();

        ret = vid_recorder_init(req_p);
        
        if (ret!= MED_S_OK)
        {
            goto preview_error_handler;
        }

        /* start CAL preview */
        ret = vid_cal_start_preview(req_p);

preview_error_handler:

        if (ret != MED_RES_OK)
        {
            vid_recorder_deinit_and_release_memory();
            VID_ENTER_STATE(VID_IDLE);
            VID_SET_RESULT_EVENT(ret, VID_EVT_PREVIEW, __LINE__);
            return;
        }
        else
        {
            VID_ENTER_STATE(VID_PREVIEW);
            VID_SET_RESULT_EVENT(MED_RES_OK, VID_EVT_PREVIEW, __LINE__);
            return;
        }
    }
    else
    {
        VID_ENTER_STATE(VID_PREVIEW);        
        VID_SET_RESULT_EVENT(MED_RES_BUSY, VID_EVT_PREVIEW, __LINE__);
        return;        
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_rec_stop_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_rec_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_error_t ret = MED_S_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_REC_STOP_REQ_HDLR);
    vid_debug_print_cur_state(__LINE__);

    vid_context_p->src_mod = ilm_ptr->src_mod_id;
    if (VID_IN_STATE(VID_PREVIEW))
    {
        /* stop camera */
        vid_cal_stop_preview();
        vid_recorder_deinit_and_release_memory();
        VID_ENTER_STATE(VID_IDLE);
        vid_set_event(VID_EVT_STOP);
        return;
    }
    else if (VID_IN_STATE(VID_RECORD) || VID_IN_STATE(VID_RECORD_PAUSED))
    {
        if (VID_IN_STATE(VID_RECORD))
        {
            vid_recorder_get_current_record_time(&vid_context_p->current_time);
            kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, vid_context_p->current_time, __LINE__);            
        }

        /* stop recorder */
        CHECK_RECORDER_P();
        ret = recorder_p->stop(recorder_p);

        /* stop camera */
        vid_cal_stop_preview();

        if(ret == MED_S_ASYNC)
        {
            VID_ENTER_STATE(VID_RECORD_STOP_VISUAL);
        }
        else
        {
            if (VID_IN_STATE(VID_RECORD))
            {
                vid_recorder_get_current_record_time(&vid_context_p->current_time);
                kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, vid_context_p->current_time, __LINE__);            
            }
            vid_recorder_deinit_and_release_memory();
            /* release MMI first */
            VID_ENTER_STATE(VID_IDLE);
            VID_SET_RESULT_EVENT((kal_int32)med_error_to_result_enum(ret), VID_EVT_STOP, __LINE__);
        }        
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
#endif
    else if (VID_IN_STATE(VID_FILE_MERGE))
    {
        ret = recorder_p->abort_saving(recorder_p);
        VID_ENTER_STATE(VID_FILE_MERGE_STOPPING);

        if (ret != MED_S_ASYNC)
        {
            vid_set_result(ret, __LINE__);
        }
        return;
    }
    else
    {
        /**
         * When doing nothing in stop request handler, we set result as ALREADY_STOPPED,
         * In other case, we use default MED_RES_OK in vid_api.c.
         */
        VID_SET_RESULT_EVENT(MED_RES_VIDEO_ALREADY_STOPPED, VID_EVT_STOP, __LINE__);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_record_req_hdlr
 * DESCRIPTION
 *  Handle video record request
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_record_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_record_req_struct *req_p;
    mpl_recorder_record_param_t record_param;
    media_error_t ret = MED_S_OK;
#ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
    CAL_FEATURE_CTRL_STRUCT CalInPara;
    MM_ERROR_CODE_ENUM result;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_RECORD_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_record_req_struct*) ilm_ptr->local_para_ptr;

    //modify here to set param
    #ifdef __STREAM_SERVER_SUPPORT__
    vid_rtsp_init_record_setting(req_p);
    #endif
    aud_stop_unfinished_audio();

    vid_context_p->seq_num = req_p->seq_num;
    vid_context_p->ui_rot_angle = req_p->encode_rotate;

    vid_calc_rotation_info();

    if (VID_IN_STATE(VID_PREVIEW))
    {
    #ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_SET_VIDEO_ROT_ANGLE;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalInPara.FeatureSetValue = vid_context_p->encode_rotate;
        result = CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);
    #endif

        vid_context_p->error_code = MED_RES_OK;
        vid_context_p->recorded_size = 0;
        vid_context_p->media_mode = req_p->media_mode;

        /* stop unfinished audio task */
        aud_stop_unfinished_process();

        if (req_p->media_mode == MED_MODE_FILE)
        {
            kal_mem_cpy(vid_context_p->storing_path, req_p->data, MAX_FILE_NAME_LEN * ENCODE_BYTE);

            recorder_p->get_default(recorder_p,MPL_RECORDER_PARAM_TYPE_START, &record_param, sizeof(record_param));

            /* do not support now record time limit now. */
            record_param.record_time_limit = req_p->time_limit;           
            record_param.record_file_size_limit = req_p->file_size_limit;
            record_param.working_path = &vid_context_p->storing_path[0];
               
            if (vid_context_p->encode_one_frame_duration == 0)
                record_param.record_audio = (req_p->record_audio==0)?KAL_FALSE:KAL_TRUE;
            else
                record_param.record_audio = KAL_FALSE;
            
        #if defined(__RECORDER_MOTION_SENSOR_SUPPORT_BY_TAG__)
            record_param.u4ImageWidth = vid_context_p->image_width;
            record_param.u4ImageHeight = vid_context_p->image_height;  
            record_param.ePlaybackRotationAngle = (MPL_RECORDER_ROTATION_ANGLE_T)vid_context_p->encode_rotate;
        #else    
            record_param.u4ImageWidth = req_p->image_width;
            record_param.u4ImageHeight = req_p->image_height;
            record_param.ePlaybackRotationAngle = MPL_RECORDER_ROTATION_ANGLE_CW_0;   
        #endif
            
            ret = recorder_p->start(recorder_p,&record_param);

            if (ret != MED_S_OK)
            {
                goto record_error;
            }

            /* no error */
            VID_ENTER_STATE(VID_RECORD);
            VID_SET_RESULT_EVENT(MED_RES_OK, VID_EVT_RECORD, __LINE__);
            return;


        record_error:
           
            /* stop camera */
            vid_cal_stop_preview();               
            vid_recorder_deinit_and_release_memory();
            VID_ENTER_STATE(VID_IDLE);
            VID_SET_RESULT_EVENT((kal_int32)med_error_to_result_enum(ret), VID_EVT_RECORD, __LINE__);
            return;
                
        }
        else
        {
            VID_SET_RESULT_EVENT(MED_RES_INVALID_FORMAT, VID_EVT_RECORD, __LINE__);
            return;            
        }
    }
    else
    {
        VID_SET_RESULT_EVENT(MED_RES_BUSY, VID_EVT_RECORD, __LINE__);
        return;        
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_file_merge_req_hdlr
 * DESCRIPTION
 *  Handle video file merge request.
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_file_merge_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mpl_recorder_save_param_t save_param;
    media_error_t result = MED_S_OK;
    med_result_enum ret = MED_RES_OK;
    media_vid_file_merge_req_struct* req_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_FILE_MERGE_REQ_HDLR);      
    vid_debug_print_cur_state(__LINE__);
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;    

    if (VID_IN_STATE(VID_IDLE))
    {
        req_p = (media_vid_file_merge_req_struct*) ilm_ptr->local_para_ptr;
    
        if (vid_context_p->bit_stream_type == MPL_RECORDER_FORMAT_MAX)
        {
            /* it means that recorder is never constructed before */
            VID_SET_RESULT_EVENT(MED_RES_ERROR, VID_EVT_FILE_MERGE, __LINE__);
        }

        if (recorder_p==NULL)
        {
            vid_context_p->is_recorder_existed = KAL_FALSE;
            ret = vid_construct_recorder(vid_context_p->bit_stream_type);

            if (ret!= MED_RES_OK)
            {
                ASSERT(0);
            }
        }
        else
        {
            vid_context_p->is_recorder_existed = KAL_TRUE;
        }

        recorder_p->get_default(recorder_p,MPL_RECORDER_PARAM_TYPE_SAVE, &save_param, sizeof(save_param));
        // use the new path.
        kal_mem_cpy(vid_context_p->storing_path, req_p->file_path, MAX_FILE_NAME_LEN * ENCODE_BYTE);

        save_param.file_path = &vid_context_p->storing_path[0];
        save_param.working_path = &vid_context_p->storing_path[0];
        result = recorder_p->save(recorder_p, &save_param);

        if (result == MED_S_ASYNC)
        {
            VID_ENTER_STATE(VID_FILE_MERGE);
            vid_set_result(MED_RES_OK, __LINE__);
        }
        else
        {
            vid_set_result((kal_int32)med_error_to_result_enum(result), __LINE__);

            if(vid_context_p->is_recorder_existed == KAL_FALSE)
            {
                if (recorder_p != NULL)
                {
                    recorder_p->destroy(recorder_p);
                    recorder_p = NULL;
                }
            }
        }

        vid_set_event(VID_EVT_FILE_MERGE);
        return;
    }
    else
    {
        ASSERT(vid_context_p->state == VID_IDLE);
    }

}


void vid_get_record_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_record_time_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_p = (media_vid_get_record_time_req_struct*) ilm_ptr->local_para_ptr;

    if (VID_IN_STATE(VID_RECORD))
    {
        vid_recorder_get_current_record_time(&vid_context_p->current_time);        
    }
    (*req_p->cur_time_p) = vid_context_p->current_time;
    vid_set_event(VID_EVT_GET_INFO);
}


void vid_get_record_frame_num_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_record_frame_num_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_p = (media_vid_get_record_frame_num_req_struct*) ilm_ptr->local_para_ptr;

    if (VID_IN_STATE(VID_RECORD))
    {
        vid_recorder_get_current_record_frame_num(&vid_context_p->current_frame_num);        
    }
    (*req_p->cur_frame_num_p) = vid_context_p->current_frame_num;
    vid_set_event(VID_EVT_GET_INFO);
}


void vid_get_record_size_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_record_size_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_p = (media_vid_get_record_size_req_struct*) ilm_ptr->local_para_ptr;

    if (VID_IN_STATE(VID_RECORD))
    {
        vid_recorder_get_current_record_size(&vid_context_p->recorded_size);        
    }
    (*req_p->cur_size_p) = vid_context_p->recorded_size;
    vid_set_event(VID_EVT_GET_INFO);
}


void vid_clean_file_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_result_enum result = MED_RES_OK;
    kal_bool is_recorder_existed = KAL_TRUE;
    mpl_recorder_discard_param_t discard_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CLEAN_TMP_FILES);    
    
    if (vid_context_p->bit_stream_type == MPL_RECORDER_FORMAT_MAX)
    {
        /* it means that recorder is never constructed before */
        vid_set_event(VID_EVT_BLOCK);
        return ;
    }
    
    if (recorder_p==NULL)
    {
        is_recorder_existed = KAL_FALSE;
        result = vid_construct_recorder(vid_context_p->bit_stream_type);

        if (result!= MED_RES_OK)
        {
            vid_set_event(VID_EVT_BLOCK);
            return;
        }
    }   

    recorder_p->get_default(recorder_p,MPL_RECORDER_PARAM_TYPE_DISCARD, &discard_param, sizeof(discard_param));

    discard_param.working_path = &vid_context_p->storing_path[0];
    recorder_p->discard(recorder_p, &discard_param);

    if(is_recorder_existed == KAL_FALSE)
    {
        vid_recorder_deinit();
    }
        
    vid_set_event(VID_EVT_BLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  vid_pause_req_hdlr
 * DESCRIPTION
 *  Handle video pause request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_pause_req_struct *req_p;
    media_error_t ret = MED_S_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PAUSE_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);

    req_p = (media_vid_pause_req_struct*) ilm_ptr->local_para_ptr;

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (VID_IN_STATE(VID_RECORD))
    {
        if (req_p->stop_preview)
        {
            /* stop camera */
            vid_cal_stop_preview();
        
            vid_context_p->is_preview_stopped = KAL_TRUE;
        }
        else
        {   
            // TODO: it seems do not need to call pause.
            vid_context_p->is_preview_stopped = KAL_FALSE;            
        }
        CHECK_RECORDER_P();
        ret = recorder_p->pause(recorder_p);

        VID_ENTER_STATE(VID_RECORD_PAUSED);                            

        vid_recorder_get_current_record_time(&vid_context_p->current_time);
        kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, vid_context_p->current_time, __LINE__);

        if(ret == MED_S_OK)
        {
            vid_set_event(VID_EVT_PAUSE);
        }
        else if (ret == MED_E_TERMINATING)
        {
            VID_ENTER_STATE(VID_RECORD_FINISH);
            vid_set_event(VID_EVT_PAUSE);
        }
        else if (ret!= MED_S_ASYNC)
        {
            /* stop CAL */
            vid_cal_stop_preview();

            /* deinit MPL recorder */
            vid_recorder_deinit_and_release_memory();
            VID_ENTER_STATE(VID_IDLE);
            VID_SET_RESULT_EVENT((kal_int32)med_error_to_result_enum(ret), VID_EVT_PAUSE, __LINE__);
        }
        else
        {
            // ASYNC, current we did not handle this.
            ASSERT(0);
        }
    }
    else
    {
        /* 
         * return OK in case that the record finish ind is still in MMI's 
         * queue,There will be a unexpected error popup screen 
         */
        VID_SET_RESULT_EVENT(MED_RES_OK, VID_EVT_PAUSE, __LINE__);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_resume_req_hdlr
 * DESCRIPTION
 *  Handle video resume request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_error_t result;
#ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__    
    CAL_FEATURE_CTRL_STRUCT CalInPara;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_RESUME_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (VID_IN_STATE(VID_RECORD_PAUSED))
    {
        if (vid_context_p->media_mode == MED_MODE_FILE)
        {            
            /* Start video encoding */
            if (vid_context_p->is_preview_stopped)
            {
                MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
                /* 
                 * preview is stopped when pause - need restart camera,
                 * and do not inin memory 
                 */
                ret = CalCtrl(CAL_SCENARIO_CTRL, (void *) &cal_video_scenario_para, NULL, 0, NULL);

                ASSERT(ret == MM_ERROR_NONE);

        #ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
            CalInPara.FeatureId = CAL_FEATURE_CAMERA_SET_VIDEO_ROT_ANGLE;
            CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
            CalInPara.FeatureSetValue = vid_context_p->encode_rotate;
            CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);
        #endif
            }

            CHECK_RECORDER_P();
            result = recorder_p->resume(recorder_p);
            
            if (result != MED_S_OK)
            {
                /* stop camera */
                vid_cal_stop_preview();  
                vid_recorder_deinit_and_release_memory();
                VID_ENTER_STATE(VID_IDLE);
                VID_SET_RESULT_EVENT((kal_int32)med_error_to_result_enum(result), VID_EVT_RESUME, __LINE__);
                return;
            }
            else
            {
                VID_ENTER_STATE(VID_RECORD);
                VID_SET_RESULT_EVENT(MED_RES_OK, VID_EVT_RESUME, __LINE__);
                return;                
            }

        }
        else
        {
            VID_SET_RESULT_EVENT(MED_RES_INVALID_FORMAT, VID_EVT_RESUME, __LINE__);
            return;
        }
    }
    else
    {
        VID_SET_RESULT_EVENT(MED_RES_BUSY, VID_EVT_RESUME, __LINE__);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_update_blt_pause_req_hdlr
 * DESCRIPTION
 *  Pause for update video blt parameter for video recroding
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_update_blt_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_error_t ret = MED_S_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_UPDATE_BLT_PAUSE_REQ_HDLR);     
    
    if (VID_IN_STATE(VID_RECORD))
    {
        CHECK_RECORDER_P();
        ret = recorder_p->pause_video_encode(recorder_p);

        /* stop camera */
        vid_cal_stop_preview();
        
        if (ret == MED_S_OK)
        {        
            VID_ENTER_STATE(VID_RECORD_UPDATE_BLT_PAUSED);
            VID_SET_RESULT_EVENT(MED_RES_OK, VID_EVT_BLOCK, __LINE__);
        }
        else if (ret == MED_S_ASYNC)
        {
            // wait for callback
            VID_ENTER_STATE(VID_RECORD_UPDATE_BLT_PAUSED_ASYNC);
        }
        else
        {
            vid_recorder_deinit_and_release_memory();
            VID_ENTER_STATE(VID_IDLE);                          
            VID_SET_RESULT_EVENT(MED_RES_ERROR, VID_EVT_BLOCK, __LINE__);
            return;            
        }
        return;
        
    }
    else if (VID_IN_STATE(VID_RECORD_PAUSED)||VID_IN_STATE(VID_PREVIEW))
    {
        /* stop camera */
        vid_cal_stop_preview();
        VID_SET_RESULT_EVENT(MED_RES_OK, VID_EVT_BLOCK, __LINE__);
        return;
    }
    else
    {
        /* calling in wrong state */
        VID_SET_RESULT_EVENT(MED_RES_BUSY, VID_EVT_BLOCK, __LINE__);
    }    

}



/*****************************************************************************
 * FUNCTION
 *  vid_update_blt_resume_req_hdlr
 * DESCRIPTION
 *  Resume for update video blt parameter for video recroding
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_update_blt_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_update_blt_resume_req_struct *resume_struct;
    MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
    med_result_enum ret_value = MED_RES_OK ;
    media_error_t result = MED_S_OK;
#ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__    
    CAL_FEATURE_CTRL_STRUCT CalInPara;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_UPDATE_BLT_RESUME_REQ_HDLR);     

    resume_struct = (media_vid_update_blt_resume_req_struct*)ilm_ptr->local_para_ptr;
    vid_context_p->ui_rot_angle = resume_struct->ui_rot_angle;

    vid_calc_rotation_info();

    if (vid_context_p->included_angle == MM_IMAGE_ROTATE_90 || vid_context_p->included_angle == MM_IMAGE_ROTATE_270)
    {
        vid_context_p->display_width = resume_struct->preview_height;
        vid_context_p->display_height = resume_struct->preview_width;            
    }
    else
    {
        vid_context_p->display_width = resume_struct->preview_width;
        vid_context_p->display_height = resume_struct->preview_height;
    }

    cal_mdp_video_data.DisplayImageRotAngle= vid_context_p->preview_rotate;
    cal_mdp_video_data.DisplayImageDataFormat=(MM_IMAGE_FORMAT_ENUM)resume_struct->image_data_format;
    cal_mdp_video_data.DisplayImageWidth=vid_context_p->display_width;
    cal_mdp_video_data.DisplayImageHeight=vid_context_p->display_height;
    cal_mdp_video_data.FrameBuffAddr1=vid_context_p->frame_buffer_address_1 = resume_struct->frame_buffer_addr1;
    cal_mdp_video_data.FrameBuffSize=vid_context_p->frame_buffer_size = resume_struct->frame_buffer_size;

    if (vid_context_p->frame_buffer_address_2!= NULL)
    {
        med_free_asm_mem(vid_context_p->rec_app_id,(void**)&vid_context_p->frame_buffer_address_2);
        vid_context_p->frame_buffer_address_2 = NULL;
    }

    if (vid_context_p->frame_buffer_address_3!= NULL)
    {
        med_free_asm_mem(vid_context_p->rec_app_id,(void**)&vid_context_p->frame_buffer_address_3);
        vid_context_p->frame_buffer_address_3 = NULL;
    }
    
#if defined(DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT)
    if (vid_context_p->rec_align_buffer_address!= NULL)
    {
        med_free_asm_mem(vid_context_p->rec_app_id,(void**)&vid_context_p->rec_align_buffer_address);
        vid_context_p->rec_align_buffer_address = NULL;
    }
    if (resume_struct->frame_buffer_size%32 != 0 || ((resume_struct->frame_buffer_addr1 & 0x0000001f)!=0 ))
    {
        vid_context_p->rec_align_buffer_size = ((resume_struct->frame_buffer_size+31) >> 5) << 5;
        vid_context_p->rec_align_buffer_address = (kal_uint32)med_alloc_asm_mem_framebuffer(vid_context_p->rec_app_id,vid_context_p->rec_align_buffer_size);

        cal_mdp_video_data.FrameBuffAddr1 = vid_context_p->rec_align_buffer_address;
        resume_struct->frame_buffer_size = vid_context_p->rec_align_buffer_size;
    }
    else
    {
        vid_context_p->rec_align_buffer_size = 0;
        vid_context_p->rec_align_buffer_address = NULL;
    }
#endif

    if (resume_struct->frame_buffer_size > 0)
    {
        vid_context_p->frame_buffer_address_2 = (kal_uint32)med_alloc_asm_mem_framebuffer(vid_context_p->rec_app_id,resume_struct->frame_buffer_size);
        #ifdef MDP_SUPPORT_VR_TRIPLE_DISPLAY_BUFFER        
        vid_context_p->frame_buffer_address_3 = (kal_uint32)med_alloc_asm_mem_framebuffer(vid_context_p->rec_app_id,resume_struct->frame_buffer_size);
        #endif
        
        if (vid_context_p->frame_buffer_address_2 == NULL)
        {            
            if (VID_IN_STATE(VID_RECORD_UPDATE_BLT_PAUSED))
            {
                /* resume encode */
                result = recorder_p->stop(recorder_p);                
            }
        
            vid_recorder_deinit_and_release_memory();
            VID_ENTER_STATE(VID_IDLE); 
            /* no error happened */
            VID_SET_RESULT_EVENT(MED_RES_MEM_INSUFFICIENT, VID_EVT_BLOCK, __LINE__);
            return;
        }
    }
    
    cal_mdp_video_data.FrameBuffAddr2=vid_context_p->frame_buffer_address_2;
    cal_mdp_video_data.FrameBuffAddr3=vid_context_p->frame_buffer_address_3;
    cal_mdp_video_data.VideoEncodeEnable=KAL_TRUE;
#ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_TAG__
    cal_mdp_video_data.VideoImageRotAngle = MM_IMAGE_ROTATE_0;
#else
    cal_mdp_video_data.VideoImageRotAngle = vid_context_p->encode_rotate;
#endif
    cal_mdp_video_data.VideoImageWidth=vid_context_p->image_width;
    cal_mdp_video_data.VideoImageHeight=vid_context_p->image_height;
    cal_mdp_video_data.LcdUpdateEnable=resume_struct->lcd_update;

    cal_lcd_data.WfcElementHandle = resume_struct->layer_element;
    cal_lcd_data.WfcContextHandle = resume_struct->blt_ctx;
    cal_lcd_data.WfcDeviceHandle = resume_struct->blt_dev;
   
    cal_video_recorder_data.pLcdPara=&cal_lcd_data;
    cal_video_recorder_data.pMdpPara=&cal_mdp_video_data;
    cal_video_recorder_data.pIspPara=&cal_isp_video_data;

    cal_video_scenario_para.ScenarioId=CAL_SCENARIO_VIDEO;
    cal_video_scenario_para.ScenarioCtrlCode=CAL_CTRL_CODE_START;
    cal_video_scenario_para.ScenarioCtrlParaLen=sizeof(CAL_CAMERA_VIDEO_RECORD_STRUCT);
    cal_video_scenario_para.pScenarioCtrlPara=&cal_video_recorder_data;

    if (VID_IN_STATE(VID_RECORD_UPDATE_BLT_PAUSED))
    {
        /* re-start camera and video encoder, and do not init driver's buffer */
        ret = CalCtrl(CAL_SCENARIO_CTRL, (void *) &cal_video_scenario_para, NULL, 0, NULL);        
        
        if (ret != MM_ERROR_NONE)
        {
            ret_value = vid_get_result_from_cal_error_enum(ret);
        }      

        /* start camera failed */
        if (ret_value != MED_RES_OK)
        {
            vid_recorder_deinit_and_release_memory();
            VID_ENTER_STATE(VID_IDLE);
            VID_SET_RESULT_EVENT(ret_value, VID_EVT_BLOCK, __LINE__);
            return;
        }

        CHECK_RECORDER_P();
        
    #ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_SET_VIDEO_ROT_ANGLE;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        CalInPara.FeatureSetValue = vid_context_p->encode_rotate;
        result = CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);
    #endif

        /* resume encode */
        result = recorder_p->resume_video_encode(recorder_p);

        /* resume failed */
        if (result != MED_S_OK)
        {
            /* stop camera */
            vid_cal_stop_preview();
            vid_recorder_deinit_and_release_memory();          
            VID_ENTER_STATE(VID_IDLE);
            VID_SET_RESULT_EVENT((kal_int32)med_error_to_result_enum(result), VID_EVT_BLOCK, __LINE__);
            return;
        }

        /* no error happened */        
        VID_ENTER_STATE(VID_RECORD);        
        VID_SET_RESULT_EVENT(MED_RES_OK, VID_EVT_BLOCK, __LINE__);
        return;
        
    }
    else if (VID_IN_STATE(VID_RECORD_PAUSED)||VID_IN_STATE(VID_PREVIEW))
    {   
       
        /* re-start camera and video encoder, and do not init driver's buffer */
        ret = CalCtrl(CAL_SCENARIO_CTRL, (void *) &cal_video_scenario_para, NULL, 0, NULL);        
        
        if (ret != MM_ERROR_NONE)
        {
            ret_value = vid_get_result_from_cal_error_enum(ret);
        }      

        /* start camera failed */
        if (ret_value != MED_RES_OK)
        {
            vid_recorder_deinit_and_release_memory();
            VID_ENTER_STATE(VID_IDLE);  
            VID_SET_RESULT_EVENT(ret_value, VID_EVT_BLOCK, __LINE__);
            return;
        }

        /* no error happened */
        VID_SET_RESULT_EVENT(MED_RES_OK, VID_EVT_BLOCK, __LINE__);
        return;
    }
    else
    {
        /* calling in wrong state */
        VID_SET_RESULT_EVENT(MED_RES_BUSY, VID_EVT_BLOCK, __LINE__);
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_check_unfinished_file
 * DESCRIPTION
 *  Check unfinished video recording file.
 * PARAMETERS
 *  void
 * RETURNS
 *  Has unfinished file or not
 *****************************************************************************/
kal_bool vid_check_unfinished_file(kal_wchar* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_result_enum ret = MED_RES_OK;
    kal_bool is_recorder_existed = KAL_TRUE;
    mpl_recorder_is_unsaved_file_param_t is_unsaved_file_param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CHECK_UNFINISHED_FILE);    
    
    if (vid_context_p->bit_stream_type == MPL_RECORDER_FORMAT_MAX)
    {
        /* it means that recorder is never constructed before */
        return KAL_FALSE;
    }
    
    if (recorder_p==NULL)
    {
        is_recorder_existed = KAL_FALSE;
        ret = vid_construct_recorder(vid_context_p->bit_stream_type);

        if (ret!= MED_RES_OK)
        {
            return KAL_FALSE;
        }
    }   

    kal_mem_cpy(vid_context_p->storing_path, filepath, MAX_FILE_NAME_LEN * ENCODE_BYTE);    

    is_unsaved_file_param.working_path = &vid_context_p->storing_path[0];
    recorder_p->get_param(recorder_p,MPL_RECORDER_PARAM_IS_UNFINISHED_FILE,&is_unsaved_file_param, sizeof(is_unsaved_file_param));

    if(is_recorder_existed == KAL_FALSE)
    {
        vid_recorder_deinit();
    }
        
    return is_unsaved_file_param.is_unsaved_file ;

}


void vid_get_reserved_disc_size_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_result_enum ret = MED_RES_OK;
    kal_bool is_recorder_existed = KAL_TRUE;
    media_vid_get_reserved_disc_size_struct *req_p;
    kal_uint32 reservedSize = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_p = (media_vid_get_reserved_disc_size_struct*) ilm_ptr->local_para_ptr;

    if (vid_context_p->bit_stream_type == MPL_RECORDER_FORMAT_MAX)
    {
        /* it means that recorder is never constructed before */
        (*req_p->size) = 0;
    }
    else
    {
        if (recorder_p==NULL)
        {
            is_recorder_existed = KAL_FALSE;
            ret = vid_construct_recorder(vid_context_p->bit_stream_type);

            if (ret!= MED_S_OK)
            {
                return;
            }
        }

        recorder_p->get_param(recorder_p,MPL_RECORDER_PARAM_GET_RESERVED_DISK_SIZE,&reservedSize, sizeof(reservedSize));

        (*req_p->size) = reservedSize;

        if(is_recorder_existed == KAL_FALSE)
        {
            vid_recorder_deinit();
        }
    }
    vid_set_event(VID_EVT_BLOCK);
}

/*****************************************************************************
 * FUNCTION
 *  vid_start_fast_zoom_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request of starting the camera fast zoom.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_start_fast_zoom_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_start_fast_zoom_req_struct *req_p;
    CAL_FEATURE_CTRL_STRUCT fast_zoom_ctrl;
    CAL_CAMERA_FAST_ZOOM_STRUCT fast_zoom_data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (VID_IN_STATE(VID_PREVIEW) || VID_IN_STATE(VID_RECORD) || VID_IN_STATE(VID_RECORD_PAUSED))
    {
        req_p = (media_vid_start_fast_zoom_req_struct*) ilm_ptr->local_para_ptr;

        fast_zoom_data.ZoomIn = req_p->zoom_in;
        fast_zoom_data.ZoomLimit = req_p->zoom_limit;
        fast_zoom_data.ZoomSpeed = req_p->zoom_speed;
        fast_zoom_data.ZoomStep = req_p->zoom_step;
        fast_zoom_data.ZoomStart = KAL_TRUE;
        
        fast_zoom_ctrl.FeatureId =  CAL_FEATURE_CAMERA_FAST_ZOOM;
        fast_zoom_ctrl.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
        fast_zoom_ctrl.FeatureModeSupport = CAL_FEATURE_VIDEO_SUPPORT;
        fast_zoom_ctrl.FeatureType = CAL_FEATURE_TYPE_STRUCTURED;
        fast_zoom_ctrl.FeatureInfo.FeatureStructured.pCamFastZoom = &fast_zoom_data; 
        CalCtrl(CAL_FEATURE_CTRL,(void*)&fast_zoom_ctrl,NULL,0,NULL);

        //ASSERT(ret == MM_ERROR_NONE);

        vid_context_p->is_fast_zoom = KAL_TRUE;
    }
    vid_set_event(VID_EVT_FAST_ZOOM);
}

            
/*****************************************************************************
 * FUNCTION
 *  vid_stop_fast_zoom_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request of stopping the camera fast zoom.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_fast_zoom_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (VID_IN_STATE(VID_PREVIEW) || VID_IN_STATE(VID_RECORD) || VID_IN_STATE(VID_RECORD_PAUSED))
    {
        vid_cal_stop_fast_zoom();
    }
 
    vid_set_event(VID_EVT_FAST_ZOOM);
}
/*****************************************************************************
 * FUNCTION
 *  vid_get_fast_zoom_factor_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request of getting the camera fast zoom factor.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_get_fast_zoom_factor_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_fast_zoom_factor_req_struct *req_p;
    CAL_FEATURE_CTRL_STRUCT CalInPara, CalOutPara;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* isp_fast_zoom_struct zoom_data; */

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_get_fast_zoom_factor_req_struct*) ilm_ptr->local_para_ptr;

    if (req_p->factor)
    {
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_CURRENT_ZOOM_FACTOR;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, (void*)&CalOutPara, sizeof(CalOutPara), NULL);
        *req_p->factor = CalOutPara.FeatureCurrentValue;

        if( *req_p->factor <=  100 )
        {
            *req_p->factor = 100;
        }
    }

    if (req_p->step)
    {
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_CURRENT_ZOOM_STEP;
        CalInPara.FeatureCtrlCode = CAL_FEATURE_GET_OPERATION;
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, (void*)&CalOutPara, sizeof(CalOutPara), NULL);        
        *req_p->step = CalOutPara.FeatureCurrentValue;
    }

    vid_set_event(VID_EVT_GET_FAST_ZOOM_FACTOR);
}


/*****************************************************************************
 * FUNCTION
 *  vid_release_memory
 * DESCRIPTION
 *  Release internal/external memory used in video module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_release_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __STREAM_SERVER_SUPPORT__
	if(vid_context_p->frame_buffer_address_1!= NULL)
	{
		med_free_asm_mem(vid_context_p->rec_app_id,(void **)&vid_context_p->frame_buffer_address_1);
		vid_context_p->frame_buffer_address_1 = NULL;
	}
    #endif

    if (vid_context_p->extmem_start_address)
    {
        med_free_asm_mem(vid_context_p->rec_app_id,(void **)&vid_context_p->extmem_start_address);
        vid_context_p->extmem_start_address = NULL;
    }

    if (vid_context_p->frame_buffer_address_2!= NULL)
    {
        med_free_asm_mem(vid_context_p->rec_app_id,(void**)&vid_context_p->frame_buffer_address_2);
        vid_context_p->frame_buffer_address_2 = NULL;
    }

    if (vid_context_p->frame_buffer_address_3!= NULL)
    {
        med_free_asm_mem(vid_context_p->rec_app_id,(void**)&vid_context_p->frame_buffer_address_3);
        vid_context_p->frame_buffer_address_3 = NULL;
    }
    
#if defined(MT6260)
#if (LCD_HEIGHT > 480) || (LCD_WIDTH > 480)
    {
	    if (vid_context_p->frame_buffer_address_temp!= NULL)
	    {
	        med_free_asm_mem(vid_context_p->rec_app_id,(void**)&vid_context_p->frame_buffer_address_temp);
	        vid_context_p->frame_buffer_address_temp = NULL;
	    }
	}
#endif
#endif
#if defined(DRV_MDP_LIMIT_CACHE_LINE_32BYTE_ALIGNMENT)
    if (vid_context_p->rec_align_buffer_address != NULL)
    {
        med_free_asm_mem(vid_context_p->rec_app_id,(void **)&vid_context_p->rec_align_buffer_address);
        vid_context_p->rec_align_buffer_address = NULL;
    }
#endif
}
#pragma arm section code, rodata

/*****************************************************************************
 * FUNCTION
 *  vid_release_memory
 * DESCRIPTION
 *  Release internal/external memory used in video module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_rec_set_record_yuv_req(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_record_yuv_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_vid_record_yuv_req_struct*) ilm_ptr->local_para_ptr;
    vid_context_p->is_rec_yuv = req_p->is_yuv;
    vid_set_event(VID_EVT_BLOCK);
}
#endif /* defined(__MED_VID_ENC_MOD__) */



#endif /* MED_NOT_PRESENT */ 

