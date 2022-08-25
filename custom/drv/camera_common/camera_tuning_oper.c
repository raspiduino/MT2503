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
 *   camera_tuning_oper.c
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   Camera Operation Parameter
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 ****************************************************************************/
#include "kal_release.h"
#include "drv_features.h"

#include "drv_comm.h"
#include "sensor_comm_def.h"
#include "fd_comm_def.h"
#include "hdr_comm_def.h"
#include "asd_comm_def.h"

#if ( defined(DRV_ISP_6238_SERIES) && defined(ISP_SUPPORT) )
#include "aaa_awb.h"
#include "aaa_flash.h"
#include "aaa_ae.h"
#include "isp_comm_if.h"


void AwbInitOperationPara(IMAGE_SENSOR_INDEX_ENUM SensorIdx, AWB_OPERATION_PARA_STRUCT *oper_data)
{
    if (IMAGE_SENSOR_MAIN == SensorIdx)
	{
	    oper_data->AwbStartSmFrameNum = 15;
	    oper_data->AwbMixedToDEn = KAL_FALSE;
	    oper_data->AwbMixedToDType = WB_BOX_FULL_D;
	    oper_data->AwbFastToIndoorMaxEvThr = 100;
	    oper_data->AwbSlowToIndoorMaxEvThr = 100;
	    oper_data->AwbLimitMaxGainEn = KAL_FALSE;
	    oper_data->AwbAuxiliaryLockDayEvThr = 70;
	    oper_data->AwbAuxiliaryLockDayFrameThr = 5;
	    oper_data->AwbDayPreferenceEvThr = 100;
	  }
    else if (IMAGE_SENSOR_SUB == SensorIdx)
    {
	    oper_data->AwbStartSmFrameNum = 15;
	    oper_data->AwbMixedToDEn = KAL_FALSE;
	    oper_data->AwbMixedToDType = WB_BOX_FULL_D;
	    oper_data->AwbFastToIndoorMaxEvThr = 100;
	    oper_data->AwbSlowToIndoorMaxEvThr = 100;
	    oper_data->AwbLimitMaxGainEn = KAL_FALSE;
	    oper_data->AwbAuxiliaryLockDayEvThr = 70;
	    oper_data->AwbAuxiliaryLockDayFrameThr = 5;
	    oper_data->AwbDayPreferenceEvThr = 100;
	  }
    else if (IMAGE_SENSOR_BAK1 == SensorIdx)
    {
	    oper_data->AwbStartSmFrameNum = 15;
	    oper_data->AwbMixedToDEn = KAL_FALSE;
	    oper_data->AwbMixedToDType = WB_BOX_FULL_D;
	    oper_data->AwbFastToIndoorMaxEvThr = 100;
	    oper_data->AwbSlowToIndoorMaxEvThr = 100;
	    oper_data->AwbLimitMaxGainEn = KAL_FALSE;
	    oper_data->AwbAuxiliaryLockDayEvThr = 70;
	    oper_data->AwbAuxiliaryLockDayFrameThr = 5;
	    oper_data->AwbDayPreferenceEvThr = 100;
	  }
    else if (IMAGE_SENSOR_SUB_BAK1 == SensorIdx)
    {
	    oper_data->AwbStartSmFrameNum = 15;
	    oper_data->AwbMixedToDEn = KAL_FALSE;
	    oper_data->AwbMixedToDType = WB_BOX_FULL_D;
	    oper_data->AwbFastToIndoorMaxEvThr = 100;
	    oper_data->AwbSlowToIndoorMaxEvThr = 100;
	    oper_data->AwbLimitMaxGainEn = KAL_FALSE;
	    oper_data->AwbAuxiliaryLockDayEvThr = 70;
	    oper_data->AwbAuxiliaryLockDayFrameThr = 5;
	    oper_data->AwbDayPreferenceEvThr = 100;
	  }
}

void CameraTuningInitOperationPara(IMAGE_SENSOR_INDEX_ENUM SensorIdx, CameraTuningOperationParaStruct *p_oper_data)
{

    if (IMAGE_SENSOR_MAIN == SensorIdx)
    {
			p_oper_data->enable_cap_shutter_compensate = KAL_TRUE;		/* KAL_TRUE, KAL_FALSE */
			p_oper_data->shutter_compensate_pregain_max = 2*BASEGAIN;	/* For Capture Mode, comp max pregain */
			p_oper_data->bracket_expo_ev_step = 5;       		 		/* bracketing 0.1 Ev step */
			p_oper_data->preview_defect_table_enable = KAL_FALSE;		/* KAL_TRUE or KAL_FALSE */
			p_oper_data->capture_defect_table_enable = KAL_FALSE;		/* KAL_TRUE or KAL_FALSE */
			p_oper_data->preview_shading_comp_enable = KAL_TRUE;		/* KAL_TRUE or KAL_FALSE */
			p_oper_data->capture_shading_comp_enable = KAL_TRUE;		/* KAL_TRUE or KAL_FALSE */
                        #if defined(DRV_ISP_PCA_SUPPORT)
                        p_oper_data->pca_table_enable= KAL_TRUE;		                    /* KAL_TRUE or KAL_FALSE */
                        #endif
			p_oper_data->exif_iso_report_standard_enable = KAL_FALSE;		/* ISO priority EXIF with report real ISO gain enable flag */
			p_oper_data->video_metering_mode = CAM_AE_METER_AVERAGE;	/* CAM_AE_METER_AUTO or CAM_AE_METER_AVERAGE */
		}
    else if (IMAGE_SENSOR_SUB == SensorIdx)
    {
			p_oper_data->enable_cap_shutter_compensate = KAL_TRUE;		/* KAL_TRUE, KAL_FALSE */
			p_oper_data->shutter_compensate_pregain_max = 2*BASEGAIN;	/* For Capture Mode, comp max pregain */
			p_oper_data->bracket_expo_ev_step = 5;       		 		/* bracketing 0.1 Ev step */
			p_oper_data->preview_defect_table_enable = KAL_FALSE;		/* KAL_TRUE or KAL_FALSE */
			p_oper_data->capture_defect_table_enable = KAL_FALSE;		/* KAL_TRUE or KAL_FALSE */
			p_oper_data->preview_shading_comp_enable = KAL_TRUE;		/* KAL_TRUE or KAL_FALSE */
			p_oper_data->capture_shading_comp_enable = KAL_TRUE;		/* KAL_TRUE or KAL_FALSE */
                        #if defined(DRV_ISP_PCA_SUPPORT)
                        p_oper_data->pca_table_enable= KAL_TRUE;		                    /* KAL_TRUE or KAL_FALSE */
                        #endif
			p_oper_data->exif_iso_report_standard_enable = KAL_FALSE;		/* ISO priority EXIF with report real ISO gain enable flag */
			p_oper_data->video_metering_mode = CAM_AE_METER_AVERAGE;	/* CAM_AE_METER_AUTO or CAM_AE_METER_AVERAGE */
	  }
    else if (IMAGE_SENSOR_BAK1 == SensorIdx)
    {
			p_oper_data->enable_cap_shutter_compensate = KAL_TRUE;		/* KAL_TRUE, KAL_FALSE */
			p_oper_data->shutter_compensate_pregain_max = 2*BASEGAIN;	/* For Capture Mode, comp max pregain */
			p_oper_data->bracket_expo_ev_step = 5;       		 		/* bracketing 0.1 Ev step */
			p_oper_data->preview_defect_table_enable = KAL_FALSE;		/* KAL_TRUE or KAL_FALSE */
			p_oper_data->capture_defect_table_enable = KAL_FALSE;		/* KAL_TRUE or KAL_FALSE */
			p_oper_data->preview_shading_comp_enable = KAL_TRUE;		/* KAL_TRUE or KAL_FALSE */
			p_oper_data->capture_shading_comp_enable = KAL_TRUE;		/* KAL_TRUE or KAL_FALSE */
                        #if defined(DRV_ISP_PCA_SUPPORT)
                        p_oper_data->pca_table_enable= KAL_TRUE;		                    /* KAL_TRUE or KAL_FALSE */
                        #endif
			p_oper_data->exif_iso_report_standard_enable = KAL_FALSE;		/* ISO priority EXIF with report real ISO gain enable flag */
			p_oper_data->video_metering_mode = CAM_AE_METER_AVERAGE;	/* CAM_AE_METER_AUTO or CAM_AE_METER_AVERAGE */
	  }
    else if (IMAGE_SENSOR_SUB_BAK1 == SensorIdx)
    {
			p_oper_data->enable_cap_shutter_compensate = KAL_TRUE;		/* KAL_TRUE, KAL_FALSE */
			p_oper_data->shutter_compensate_pregain_max = 2*BASEGAIN;	/* For Capture Mode, comp max pregain */
			p_oper_data->bracket_expo_ev_step = 5;       		 		/* bracketing 0.1 Ev step */
			p_oper_data->preview_defect_table_enable = KAL_FALSE;		/* KAL_TRUE or KAL_FALSE */
			p_oper_data->capture_defect_table_enable = KAL_FALSE;		/* KAL_TRUE or KAL_FALSE */
			p_oper_data->preview_shading_comp_enable = KAL_TRUE;		/* KAL_TRUE or KAL_FALSE */
			p_oper_data->capture_shading_comp_enable = KAL_TRUE;		/* KAL_TRUE or KAL_FALSE */
                        #if defined(DRV_ISP_PCA_SUPPORT)
                        p_oper_data->pca_table_enable= KAL_TRUE;		                    /* KAL_TRUE or KAL_FALSE */
                        #endif
			p_oper_data->exif_iso_report_standard_enable = KAL_FALSE;		/* ISO priority EXIF with report real ISO gain enable flag */
			p_oper_data->video_metering_mode = CAM_AE_METER_AVERAGE;	/* CAM_AE_METER_AUTO or CAM_AE_METER_AVERAGE */
	  }
}

void CameraFlashTuningInitOperationPara(IMAGE_SENSOR_INDEX_ENUM SensorIdx, CameraFlashTuningOperationParaStruct *p_oper_data)
{
		if ( IMAGE_SENSOR_MAIN== SensorIdx)
		{
			p_oper_data->enable_shutter_compensate = KAL_FALSE;		/* KAL_TRUE, KAL_FALSE */
			p_oper_data->flash_max_sensor_gain = 8*ISP_AE_ISP_GAIN_BASE;
			p_oper_data->flash_max_isp_gain = 2*ISP_AE_ISP_GAIN_BASE;
			p_oper_data->flash_ae_gamma_no = 1;
			p_oper_data->flash_ae_flare_offset_ratio = 20;
			p_oper_data->flash_ae_flare_offset_min = 8;
			p_oper_data->flash_ae_target_mean = 90;
			p_oper_data->flash_ae_min_mean = 45;
			p_oper_data->af_check_flag = FLASH_AF_CHECK_DISBALE;		/* KAL_TRUE, KAL_FALSE */
			p_oper_data->af_check_macro_step = 200;
			p_oper_data->af_check_inf_step = 10;
			p_oper_data->flash_ev_comp_enable = KAL_FALSE;
		}
	  else if ( IMAGE_SENSOR_SUB== SensorIdx) {
			p_oper_data->enable_shutter_compensate = KAL_FALSE;		/* KAL_TRUE, KAL_FALSE */
			p_oper_data->flash_max_sensor_gain = 8*ISP_AE_ISP_GAIN_BASE;
			p_oper_data->flash_max_isp_gain = 2*ISP_AE_ISP_GAIN_BASE;
			p_oper_data->flash_ae_gamma_no = 1;
			p_oper_data->flash_ae_flare_offset_ratio = 20;
			p_oper_data->flash_ae_flare_offset_min = 8;
			p_oper_data->flash_ae_target_mean = 90;
			p_oper_data->flash_ae_min_mean = 45;
			p_oper_data->af_check_flag = FLASH_AF_CHECK_DISBALE;		/* KAL_TRUE, KAL_FALSE */
			p_oper_data->af_check_macro_step = 200;
			p_oper_data->af_check_inf_step = 10;
			p_oper_data->flash_ev_comp_enable = KAL_FALSE;
	  }
	  else if (IMAGE_SENSOR_BAK1 == SensorIdx) {
			p_oper_data->enable_shutter_compensate = KAL_FALSE;		/* KAL_TRUE, KAL_FALSE */
			p_oper_data->flash_max_sensor_gain = 8*ISP_AE_ISP_GAIN_BASE;
			p_oper_data->flash_max_isp_gain = 2*ISP_AE_ISP_GAIN_BASE;
			p_oper_data->flash_ae_gamma_no = 1;
			p_oper_data->flash_ae_flare_offset_ratio = 20;
			p_oper_data->flash_ae_flare_offset_min = 8;
			p_oper_data->flash_ae_target_mean = 90;
			p_oper_data->flash_ae_min_mean = 45;
			p_oper_data->af_check_flag = FLASH_AF_CHECK_DISBALE;		/* KAL_TRUE, KAL_FALSE */
			p_oper_data->af_check_macro_step = 200;
			p_oper_data->af_check_inf_step = 10;
			p_oper_data->flash_ev_comp_enable = KAL_FALSE;
	  }
	  else if ( IMAGE_SENSOR_SUB_BAK1== SensorIdx) {
			p_oper_data->enable_shutter_compensate = KAL_FALSE;		/* KAL_TRUE, KAL_FALSE */
			p_oper_data->flash_max_sensor_gain = 8*ISP_AE_ISP_GAIN_BASE;
			p_oper_data->flash_max_isp_gain = 2*ISP_AE_ISP_GAIN_BASE;
			p_oper_data->flash_ae_gamma_no = 1;
			p_oper_data->flash_ae_flare_offset_ratio = 20;
			p_oper_data->flash_ae_flare_offset_min = 8;
			p_oper_data->flash_ae_target_mean = 90;
			p_oper_data->flash_ae_min_mean = 45;
			p_oper_data->af_check_flag = FLASH_AF_CHECK_DISBALE;		/* KAL_TRUE, KAL_FALSE */
			p_oper_data->af_check_macro_step = 200;
			p_oper_data->af_check_inf_step = 10;
			p_oper_data->flash_ev_comp_enable = KAL_FALSE;
	  }
}

/*
    function : CameraImageDynamicSetting
    return : KAL_TURE if dynamic setting has to be set right now
             KAL_FALSE if dynamic setting does not need to set right now
*/
/*
#if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
extern kal_bool CalHdrEnabled;
#endif
*/
kal_bool CameraImageDynamicSetting(ISP_OPERATION_STATE_ENUM CameraState, kal_uint32 AeTotalGain,
                                   nvram_camera_para_struct *pCameraPara)
{
    switch (CameraState)
    {
		case ISP_PREVIEW_STATE:
		case ISP_MPEG4_ENCODE_STATE:
            if(AeTotalGain>ISP_AE_ISP_GAIN_BASE*8)
            {
            	pCameraPara->ISPTUNING.idx.nr1=2;	/* NOTE : Please modify index directly */
            	pCameraPara->ISPTUNING.idx.nr2=2;
            	pCameraPara->ISPTUNING.idx.saturation=1;
            	pCameraPara->ISPTUNING.idx.edge=1;
            	pCameraPara->ISPTUNING.idx.autodefect=2;
            }
            else if (AeTotalGain>ISP_AE_ISP_GAIN_BASE*4)
            {

            	pCameraPara->ISPTUNING.idx.nr1=1;	/* NOTE : Please modify index directly */
            	pCameraPara->ISPTUNING.idx.nr2=1;
            	pCameraPara->ISPTUNING.idx.saturation=2;
            	pCameraPara->ISPTUNING.idx.edge=1;
            	pCameraPara->ISPTUNING.idx.autodefect=1;

            }
            else
            {
            	pCameraPara->ISPTUNING.idx.nr1=0;	/* NOTE : Please modify index directly */
            	pCameraPara->ISPTUNING.idx.nr2=0;
            	pCameraPara->ISPTUNING.idx.saturation=2;
            	pCameraPara->ISPTUNING.idx.edge=1;
            	pCameraPara->ISPTUNING.idx.autodefect=0;
            }
            /*
            #if defined(__HIGH_DYNAMIC_RANGE_SUPPORT__)
            if(CalHdrEnabled)
            {
                pCameraPara->ISPTUNING.idx.nr1=2;  // for example
                pCameraPara->ISPTUNING.idx.nr2=2;  // for example
            }
            #endif
            */
        break;
    }
    return KAL_TRUE;
}   /* CameraImageDynamicSetting() */

#elif ( defined(MT6235) && defined(ISP_SUPPORT) )
#include "drv_comm.h"
#include "stdio.h"
//#include "isp_if.h"
#include "isp_comm_if.h"

void init_camera_postprocess_para(IMAGE_SENSOR_INDEX_ENUM SensorIdx, P_CAMERA_POST_PROCESS_PARA_STRUCT pp_data)
{

    if ( ( IMAGE_SENSOR_MAIN== SensorIdx) || ( IMAGE_SENSOR_BAK1== SensorIdx) )
    {
    #if (defined(__FACE_DETECTION_SUPPORT__))
        /*----face detection----*/
        pp_data->fd_box_vibration_tolerance = 4;                      /* 0 - 6 */
        pp_data->fd_min_detect_face_size_index_00 = 1;           /* 0 - 8 */
        pp_data->fd_min_detect_face_size_index_30 = 1;           /* 0 - 8 */
        pp_data->fd_error_box_closing_time = 30;                     /* 15 - 110 */
        pp_data->fd_phone_rotation_mode = H_CR_CCR_MODE; /* H_CR_CCR_MODE or H_CCR_CR_MODE */
        pp_data->fd_support_direction_num = 3;                        /* 1 - 4 */
        pp_data->fd_priority_mode = PRIOR_TO_CENTER;          /* PRIOR_TO_SIZE, PRIOR_TO_CENTER, PRIOR_TO_BOTH_WEIGHT */
        pp_data->fd_priority_weight = 128;                                /* 0 - 256, the value is for size*/
        pp_data->fd_hori_top_det_cycle = 5;		                    /* 1- 10, detection cycles in top direction */
        pp_data->fd_hori_bot_det_cycle = 1;		                    /* 1- 10, detection cycles in bottom direction */
        pp_data->fd_hori_lft_det_cycle = 1;		                    /* 1- 10, detection cycles in left direction */
        pp_data->fd_hori_rgt_det_cycle = 1;		                    /* 1- 10, detection cycles in right direction */
    #endif
    #if (defined(__SMILE_SHUTTER_SUPPORT__))
        /*----smile shutter----*/
        pp_data->sd_main_face_must_flag = KAL_TRUE;
        pp_data->sd_smile_required_num = 1;
    #endif
    #if (defined(__PANORAMA_VIEW_SUPPORT__))
        /*----panorama----*/
        pp_data->pano_blend_scale = 8;
        pp_data->pano_upper_margin = 0;	                             /* work around for worse lens shading (upper + lower < height) */
        pp_data->pano_lower_margin = 0;
        pp_data->pano_left_margin = 0;	                                    /* work around for worse lens shading (left + right < overlap width) */
        pp_data->pano_right_margin = 0;
    #endif
    #if (defined(__HIGH_DYNAMIC_RANGE_SUPPORT__))
        /*----hdr----*/    
        pp_data->hdr_level = HDR_LEVEL_4;
        pp_data->hdr_min_ba = 8;               
        pp_data->hdr_qvi_dithering_flag = KAL_FALSE;       
    #endif
    #if (defined(__AUTO_SCENE_DETECT_SUPPORT__))
        /*----asd----*/
        pp_data->asd_fd_frame_period = 2; /* 1~3 */
        pp_data->asd_idx_weight_bl_ae = 1; /*1~10 */
        pp_data->asd_idx_weight_bl_scd= 8; /*1~10 */
        pp_data->asd_idx_weight_ls_ae = 1; /*1~10 */
        pp_data->asd_idx_weight_ls_awb= 1; /*1~10 */
        pp_data->asd_idx_weight_ls_af = 1; /*1~10 */
        pp_data->asd_idx_weight_ls_scd= 2; /*1~10 */
        pp_data->asd_decider_time_weight_type = ASD_TIME_WEIGHT_LATER_HIGHER; /*0:ASD_TIME_WEIGHT_AVERAGE, 1:ASD_TIME_WEIGHT_LATER_HIGHER*/
        pp_data->asd_decider_time_weight_range = ASD_TIME_WEIGHT_RANGE_10CYCLE; /*1~10, ASD_TIME_WEIGHT_RANGE_1CYCLE ~ ASD_TIME_WEIGHT_RANGE_10CYCLE*/
        pp_data->asd_ev_lo_thr_night = 50; /* 50 -> Lv=5 */
        pp_data->asd_ev_hi_thr_night = 80; /* 80 -> Lv=8 */
        pp_data->asd_ev_lo_thr_outdoor= 90; /*90 -> Lv=9 */
        pp_data->asd_ev_hi_thr_outdoor= 130; /*130 -> Lv=13 */
        pp_data->asd_score_thr_night = 60; /* 40~100 */
        pp_data->asd_score_thr_backlit = 40; /* 40~100 */
        pp_data->asd_score_thr_portrait= 45; /* 40~100 */
        pp_data->asd_score_thr_landscape = 55; /* 40~100 */
        pp_data->asd_backlit_lock_enable = KAL_TRUE;
        pp_data->asd_backlit_lock_ev_diff= -10; /* -50~0 */    
    #endif
    }
    else if ( (SensorIdx == IMAGE_SENSOR_SUB) || (SensorIdx == IMAGE_SENSOR_SUB_BAK1) )
    {
    #if (defined(__FACE_DETECTION_SUPPORT__))
        /*----face detection----*/
        pp_data->fd_box_vibration_tolerance = 4;                      /* 0 - 6 */
        pp_data->fd_min_detect_face_size_index_00 = 1;           /* 0 - 8 */
        pp_data->fd_min_detect_face_size_index_30 = 1;           /* 0 - 8 */
        pp_data->fd_error_box_closing_time = 30;                     /* 15 - 110 */
        pp_data->fd_phone_rotation_mode = H_CR_CCR_MODE; /* H_CR_CCR_MODE or H_CCR_CR_MODE */
        pp_data->fd_support_direction_num = 3;                        /* 1 - 4 */
        pp_data->fd_priority_mode = PRIOR_TO_CENTER;          /* PRIOR_TO_SIZE, PRIOR_TO_CENTER, PRIOR_TO_BOTH_WEIGHT */
        pp_data->fd_priority_weight = 128;                                /* 0 - 256, the value is for size*/
        pp_data->fd_hori_top_det_cycle = 5;		                    /* 1- 10, detection cycles in top direction */
        pp_data->fd_hori_bot_det_cycle = 1;		                    /* 1- 10, detection cycles in bottom direction */
        pp_data->fd_hori_lft_det_cycle = 1;		                    /* 1- 10, detection cycles in left direction */
        pp_data->fd_hori_rgt_det_cycle = 1;		                    /* 1- 10, detection cycles in right direction */
    #endif
    #if (defined(__SMILE_SHUTTER_SUPPORT__))
        /*----smile shutter----*/
        pp_data->sd_main_face_must_flag = KAL_TRUE;
        pp_data->sd_smile_required_num = 1;
    #endif
    #if (defined(__PANORAMA_VIEW_SUPPORT__))
        /*----panorama----*/
        pp_data->pano_blend_scale = 8;
        pp_data->pano_upper_margin = 0;	                             /* work around for worse lens shading (upper + lower < height) */
        pp_data->pano_lower_margin = 0;
        pp_data->pano_left_margin = 0;	                                    /* work around for worse lens shading (left + right < overlap width) */
        pp_data->pano_right_margin = 0;
    #endif
    #if (defined(__HIGH_DYNAMIC_RANGE_SUPPORT__))
        /*----hdr----*/    
        pp_data->hdr_level = HDR_LEVEL_4;
        pp_data->hdr_min_ba = 8;               
        pp_data->hdr_qvi_dithering_flag = KAL_FALSE;     
    #endif
    }

}

#endif

void InitCameraPostProcessPara(IMAGE_SENSOR_INDEX_ENUM SensorIdx, P_CAMERA_POST_PROCESS_PARA_STRUCT pData)
{
    if ((IMAGE_SENSOR_MAIN == SensorIdx)||(IMAGE_SENSOR_BAK1 == SensorIdx))
    {
        #if (defined(__FACE_DETECTION_SUPPORT__))
        /*----face detection----*/
        pData->fd_box_vibration_tolerance = 4; /* 0 - 6 */
        pData->fd_min_detect_face_size_index_00 = 1; /* 0 - 8 */
        pData->fd_min_detect_face_size_index_30 = 1; /* 0 - 8 */
        pData->fd_error_box_closing_time = 30; /* 15 - 110 */
        pData->fd_phone_rotation_mode = H_CR_CCR_MODE; /* H_CR_CCR_MODE or H_CCR_CR_MODE */
        #if (defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__)||defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__))
        pData->fd_support_direction_num = 4; /* 1 - 4 */
        #else
        pData->fd_support_direction_num = 3; /* 1 - 4 */
        #endif
        pData->fd_priority_mode = PRIOR_TO_CENTER; /* PRIOR_TO_SIZE, PRIOR_TO_CENTER, PRIOR_TO_BOTH_WEIGHT */
        pData->fd_priority_weight = 128; /* 0 - 256, the value is for size*/
        pData->fd_hori_top_det_cycle = 5; /* 1- 10, detection cycles in top direction */
        pData->fd_hori_bot_det_cycle = 1; /* 1- 10, detection cycles in bottom direction */
        pData->fd_hori_lft_det_cycle = 1; /* 1- 10, detection cycles in left direction */
        pData->fd_hori_rgt_det_cycle = 1; /* 1- 10, detection cycles in right direction */
        #endif
        #if (defined(__SMILE_SHUTTER_SUPPORT__))
        /*----smile shutter----*/
        pData->sd_main_face_must_flag = KAL_TRUE;
        pData->sd_smile_required_num = 1;
        #endif
        #if (defined(__PANORAMA_VIEW_SUPPORT__))
        /*----panorama----*/
        pData->pano_blend_scale = 8;
        pData->pano_upper_margin = 0; /* work around for worse lens shading (upper + lower < height) */
        pData->pano_lower_margin = 0;
        pData->pano_left_margin = 0; /* work around for worse lens shading (left + right < overlap width) */
        pData->pano_right_margin = 0;
        #endif
        #if (defined(__HIGH_DYNAMIC_RANGE_SUPPORT__))
        /*----hdr----*/    
        pData->hdr_level = HDR_LEVEL_4;
        pData->hdr_min_ba = 8;               
        pData->hdr_qvi_dithering_flag = KAL_FALSE;     
        #endif
        #if (defined(__AUTO_SCENE_DETECT_SUPPORT__))
        /*----asd----*/
        pData->asd_fd_frame_period = 2; /* 1~3 */
        pData->asd_idx_weight_bl_ae = 1; /*1~10 */
        pData->asd_idx_weight_bl_scd= 8; /*1~10 */
        pData->asd_idx_weight_ls_ae = 1; /*1~10 */
        pData->asd_idx_weight_ls_awb= 1; /*1~10 */
        pData->asd_idx_weight_ls_af = 1; /*1~10 */
        pData->asd_idx_weight_ls_scd= 2; /*1~10 */
        pData->asd_decider_time_weight_type = ASD_TIME_WEIGHT_LATER_HIGHER; /*0:ASD_TIME_WEIGHT_AVERAGE, 1:ASD_TIME_WEIGHT_LATER_HIGHER*/
        pData->asd_decider_time_weight_range = ASD_TIME_WEIGHT_RANGE_10CYCLE; /*1~10, ASD_TIME_WEIGHT_RANGE_1CYCLE ~ ASD_TIME_WEIGHT_RANGE_10CYCLE*/
        pData->asd_ev_lo_thr_night = 50; /* 50 -> Lv=5 */
        pData->asd_ev_hi_thr_night = 80; /* 80 -> Lv=8 */
        pData->asd_ev_lo_thr_outdoor= 90; /*90 -> Lv=9 */
        pData->asd_ev_hi_thr_outdoor= 130; /*130 -> Lv=13 */
        pData->asd_score_thr_night = 60; /* 40~100 */
        pData->asd_score_thr_backlit = 40; /* 40~100 */
        pData->asd_score_thr_portrait= 45; /* 40~100 */
        pData->asd_score_thr_landscape = 55; /* 40~100 */
        pData->asd_backlit_lock_enable = KAL_TRUE;
        pData->asd_backlit_lock_ev_diff= -10; /* -50~0 */            
        #endif
        #if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__)||defined(__CAMERA_GYRO_SUPPORT__)
        /*----mav----*/
        pData->mavcap_tolerance_x = 8; /* 7~9 */
        pData->mavcap_tolerance_y = 8; /* 7~9 */
        pData->mavcap_MaxMV = 7; /* 7~15 */
        pData->mavcap_StepLB = 8; /* 2~10 */
        pData->mavcap_StepUB = 15; /* 7~15 */
#if defined(MT6250)||defined(MT6260)
        pData->mavcap_StepLB >>= 1;  // preview in 50 is 15fps
        pData->mavcap_StepUB >>= 1;  // preview in 50 is 15fps
#endif
        pData->mav_RCWinBound = 30; /* 20~40 */
        pData->mav_SearchRange = 15; /* 13~18 */
        pData->mav_MatchRate = 48; /* 45~51 */
        pData->mav_RectErrThre = 8; /* 7~9 */
        pData->mav_IterNum = 5; /* 3~7 */
        pData->mav_MaxAngle = 10; /* 7~13 */
        pData->mav_ClipRatio = 154; /* 140~165 */
#ifdef __CAMERA_GYRO_SUPPORT__
	pData->mavcap_GyroMvBound = 432; 
#endif		
        #endif   
    }
    else if ((IMAGE_SENSOR_SUB == SensorIdx) || (IMAGE_SENSOR_SUB_BAK1 == SensorIdx))
    {
        #if (defined(__FACE_DETECTION_SUPPORT__))
        /*----face detection----*/
        pData->fd_box_vibration_tolerance = 4; /* 0 - 6 */
        pData->fd_min_detect_face_size_index_00 = 1; /* 0 - 8 */
        pData->fd_min_detect_face_size_index_30 = 1; /* 0 - 8 */
        pData->fd_error_box_closing_time = 30; /* 15 - 110 */
        pData->fd_phone_rotation_mode = H_CR_CCR_MODE; /* H_CR_CCR_MODE or H_CCR_CR_MODE */
        #if (defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__)||defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_ENCODE__))
        pData->fd_support_direction_num = 4; /* 1 - 4 */
        #else
        pData->fd_support_direction_num = 3; /* 1 - 4 */
        #endif
        pData->fd_priority_mode = PRIOR_TO_CENTER; /* PRIOR_TO_SIZE, PRIOR_TO_CENTER, PRIOR_TO_BOTH_WEIGHT */
        pData->fd_priority_weight = 128; /* 0 - 256, the value is for size*/
        pData->fd_hori_top_det_cycle = 5; /* 1- 10, detection cycles in top direction */
        pData->fd_hori_bot_det_cycle = 1; /* 1- 10, detection cycles in bottom direction */
        pData->fd_hori_lft_det_cycle = 1; /* 1- 10, detection cycles in left direction */
        pData->fd_hori_rgt_det_cycle = 1; /* 1- 10, detection cycles in right direction */
        #endif
        #if (defined(__SMILE_SHUTTER_SUPPORT__))
        /*----smile shutter----*/
        pData->sd_main_face_must_flag = KAL_TRUE;
        pData->sd_smile_required_num = 1;
        #endif
        #if (defined(__PANORAMA_VIEW_SUPPORT__))
        /*----panorama----*/
        pData->pano_blend_scale = 8;
        pData->pano_upper_margin = 0; /* work around for worse lens shading (upper + lower < height) */
        pData->pano_lower_margin = 0;
        pData->pano_left_margin = 0; /* work around for worse lens shading (left + right < overlap width) */
        pData->pano_right_margin = 0;
        #endif
        #if (defined(__HIGH_DYNAMIC_RANGE_SUPPORT__))
        /*----hdr----*/    
        pData->hdr_level = HDR_LEVEL_4;
        pData->hdr_min_ba = 8;                  
        pData->hdr_qvi_dithering_flag = KAL_FALSE;    
        #endif
        #if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__)||defined(__CAMERA_GYRO_SUPPORT__)
        /*----mav----*/
        pData->mavcap_tolerance_x = 8; /* 7~9 */
        pData->mavcap_tolerance_y = 8; /* 7~9 */
        pData->mavcap_MaxMV = 7; /* 7~15 */
        pData->mavcap_StepLB = 8; /* 2~10 */
        pData->mavcap_StepUB = 15; /* 7~15 */
        #if defined(MT6250)||defined(MT6260)
        pData->mavcap_StepLB >>= 1;  // preview in 50 is 15fps
        pData->mavcap_StepUB >>= 1;  // preview in 50 is 15fps
        #endif
        pData->mav_RCWinBound = 30; /* 20~40 */
        pData->mav_SearchRange = 15; /* 13~18 */
        pData->mav_MatchRate = 48; /* 45~51 */
        pData->mav_RectErrThre = 8; /* 7~9 */
        pData->mav_IterNum = 5; /* 3~7 */
        pData->mav_MaxAngle = 10; /* 7~13 */
        pData->mav_ClipRatio = 154; /* 140~165 */
        #ifdef __CAMERA_GYRO_SUPPORT__
	pData->mavcap_GyroMvBound = 432; 
        #endif		
        #endif   
    }
}
