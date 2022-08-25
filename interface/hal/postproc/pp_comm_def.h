/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	pp_comm_def.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   This file is intends for post process common define.
 *
 * Author:
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __PP_COMM_DEF_H__
#define __PP_COMM_DEF_H__

#include "kal_release.h"
#include "mm_comm_def.h"

/* PP scenario control related definition */
typedef enum
{
	PP_CTRL_CODE_START = 0x00000001,
	PP_CTRL_CODE_STOP = 0x0000002,
	PP_CTRL_CODE_PAUSE = 0x0000004,
	PP_CTRL_CODE_RESUME = 0x0000008,
	PP_CTRL_CODE_RESET = 0x00000010,
	PP_CTRL_CODE_MAX
}PP_SCENARIO_CTRL_ENUM;

typedef enum
{
    PP_SCENARIO_CAMERA_PREVIEW=0,
    PP_SCENARIO_VIDEO_PREVIEW,    
    PP_SCENARIO_CAMERA_STILL_CAPTURE,
    PP_SCENARIO_BG_POSTPROC,
    PP_SCENARIO_POSTPROC,
    PP_SCENARIO_MAX    
} PP_SCENARIO_ENUM;

typedef enum
{
    PP_STATE_IDLE,
    PP_STATE_STANDBY,
    PP_STATE_BUSY,
    PP_STATE_PAUSE,    
    PP_STATE_READY,
    PP_STATE_MAX,
} PP_STATE_ENUM;

/* PP function control related definition */
typedef enum
{
	PP_FUNC_FACE_DETECT,
	PP_FUNC_SMILE_DETECT,
	PP_FUNC_BLINK_DETECT,		
	PP_FUNC_PANORAMA,
	PP_FUNC_AUTOCAP_PANORAMA,
	PP_FUNC_HDR,
        PP_FUNC_ASD,      
        PP_FUNC_MAVCAP,      
        PP_FUNC_MAV,              
	PP_FUNC_MAVCAP_GYRO,
	PP_FUNC_MAVCAP_3D,
	PP_FUNC_ALL,			
	PP_FUNC_MAX	
} PP_FUNC_ENUM;

#define PP_MODE_FACE_DETECT         (1<<PP_FUNC_FACE_DETECT)
#define PP_MODE_SMILE_DETECT        (1<<PP_FUNC_SMILE_DETECT)
#define PP_MODE_BLINK_DETECT        (1<<PP_FUNC_BLINK_DETECT)		
#define PP_MODE_PANORAMA            (1<<PP_FUNC_PANORAMA)
#define PP_MODE_AUTOCAP_PANORAMA    (1<<PP_FUNC_AUTOCAP_PANORAMA)
#define PP_MODE_HDR                 (1<<PP_FUNC_HDR)	
#define PP_MODE_ASD                 (1<<PP_FUNC_ASD)        
#define PP_MODE_MAVCAP           (1<<PP_FUNC_MAVCAP)        
#define PP_MODE_MAV                 (1<<PP_FUNC_MAV)        
#define PP_MODE_MAVCAP_GYRO   		(1<<PP_FUNC_MAVCAP_GYRO)
#define PP_MODE_MAVCAP_3D        	(1<<PP_FUNC_MAVCAP_3D)



/* PP feature control related definition */
typedef enum
{
    PP_FEATURE_SET_ENABLE=0,	
    PP_FEATURE_SET_DISABLE,	    
    PP_FEATURE_GET_STATE,		// run time query status
    PP_FEATURE_SET_ENV_INFO,	// before scenario start    
    PP_FEATURE_GET_ENV_INFO,	// before scenario start
    PP_FEATURE_GET_RESULT,    
    PP_FEATURE_SET_LOG_INFO,    // before scenario start
    PP_FEATURE_GET_OPMODE,
    PP_FEATURE_SET_SENSOR_IDX,  // set sensor index for custom tuning parameter upload
    PP_FEATURE_MAX    
} PP_FEATURE_ENUM;

/* PP callback related definition */
typedef enum
{
    PP_CBID_BEGIN=0,                   	// for PP callback
    PP_CBID_POSTPROC_START,
    PP_CBID_POSTPROC_STOP,
    PP_CBID_FACE_DETECT_BEGIN=1000,     // TBD, callback when FD result is ready
    PP_CBID_FD_RESULT,
    PP_CBID_SMILE_DETECT_BEGIN=2000,    // TBD, callback when SD result is ready
    PP_CBID_SD_RESULT,	
    PP_CBID_PANORAMA_BEGIN=3000,    // TBD, callback when PANO result is ready
    PP_CBID_PANO_BG_STITCH_READY,
    PP_CBID_PANO_RESULT,
    PP_CBID_AUTOCAP_PANORAMA_BEGIN=4000,    // TBD, callback when PANO result is ready
    PP_CBID_AUTOCAP_RESULT,
    PP_CBID_HDR_BEGIN=5000,    // TBD, callback when HDR result is ready
    PP_CBID_HDR_RESULT,
    PP_CBID_ASD_BEGIN=6000,    // TBD, callback when ASD result is ready  
    PP_CBID_ASD_RESULT,
    PP_CBID_MAV_BEGIN=7000,    // TBD, callback when MAV result is ready  
    PP_CBID_MAVCAP_RESULT,
    PP_CBID_MAV_RESULT,
} PP_CALLBACK_ID_ENUM;

/* PP custom tuning */
typedef struct
{
    /* fd */
    kal_uint8   fd_box_vibration_tolerance; /* 0 - 6 */
    kal_uint8   fd_min_detect_face_size_index_00; /* 0 - 9 */
    kal_uint8   fd_min_detect_face_size_index_30; /* 0 - 9 */
    kal_uint8   fd_frame_detect_division; /* 1 - 20 */
    kal_uint8   fd_max_tracking_face_num; /* 1 - 7 */
    kal_uint8   fd_error_box_closing_time; /* 15 - 110 */
    kal_uint8   fd_phone_rotation_mode; /* H_CR_CCR_MODE or H_CCR_CR_MODE */
    kal_uint8   fd_support_direction_num; /* 1 - 4 */
    kal_uint8   fd_support_rip_num; /* RIP_00 or RIP_00_30 */
    kal_uint8   fd_color_check_threshold;	 /* 30 - 60 */
    kal_uint8   fd_priority_mode; /* PRIOR_TO_SIZE, PRIOR_TO_CENTER, PRIOR_TO_BOTH_WEIGHT */
    kal_uint16  fd_priority_weight; /* 0 - 256, the value is for size*/
    kal_uint8   fd_hori_top_det_cycle; /* 1- 10, detection cycles in top direction */
    kal_uint8   fd_hori_bot_det_cycle; /* 1- 10, detection cycles in bottom direction */
    kal_uint8   fd_hori_lft_det_cycle; /* 1- 10, detection cycles in left direction */
    kal_uint8   fd_hori_rgt_det_cycle; /* 1- 10, detection cycles in right direction */
    kal_uint8   fd_direction_offset_horizontal ; /* FACE_DIR_OFST_0, FACE_DIR_OFST_270, FACE_DIR_OFST_180, FACE_DIR_OFST_90*/
    kal_uint8   fd_direction_offset_vertical ; /* FACE_DIR_OFST_0, FACE_DIR_OFST_270, FACE_DIR_OFST_180, FACE_DIR_OFST_90*/
    /* sd */
    kal_uint8   sd_max_detect_smile_per_round; /* 1-9, max smiles for detecting in a fd process */
    kal_uint8   sd_tolerance_count;
    kal_uint8   sd_smile_required_num;
    kal_bool    sd_main_face_must_flag;
    /* panorama */
    kal_int32   pano_blend_scale; /* pixel-based blending scale */
    kal_int32   pano_upper_margin;	/* work around for worse lens shading based on 2M size (< 2M*1/10) */
    kal_int32   pano_lower_margin;
    kal_int32   pano_left_margin; /* work around for worse lens shading based on 2M size (< 2M*1/10) */
    kal_int32   pano_right_margin;
    kal_bool    pano_fix_ae; /* whether to fix ae after first capture */
    kal_bool    pano_fix_awb;    /* whether to fix awb after first capture */
    /* autorama */
    kal_uint32  pano_focal_length;  	/* determine the curvature of cylindrical warping */
    kal_uint32  pano_tolerance_x; 	/* x direction tolerance for capture */
    kal_uint32  pano_tolerance_y;	/* y direction tolerance for capture */
    /* hdr */
    kal_uint32  hdr_level;     /* hdr strength level  ( 0:HDR_LEVEL_LOW, 1:HDR_LEVEL_MEDIUM, 2:HDR_LEVEL_STRONG)*/
    kal_uint32  hdr_min_ba;    /* hdr black keeping area */
    kal_uint32  hdr_sat_level; /* hdr color saturation level (no use currently) */
    kal_bool hdr_qvi_dithering_flag;  /* add sw dithering for HDR qvi */   
    /* asd */
    kal_uint8 asd_num_of_ort; /* 0 - 4 */
    kal_uint8 asd_fd_frame_period; /* 1~3 */
    kal_uint32 asd_decider_time_weight_type; /*0:ASD_TIME_WEIGHT_AVERAGE, 1:ASD_TIME_WEIGHT_LATER_HIGHER*/
    kal_uint32 asd_decider_time_weight_range; /*1~10, ASD_TIME_WEIGHT_RANGE_1CYCLE ~ ASD_TIME_WEIGHT_RANGE_10CYCLE*/
    kal_int16 asd_idx_weight_bl_ae; /*1~10 */
    kal_int16 asd_idx_weight_bl_scd; /*1~10 */
    kal_int16 asd_idx_weight_ls_ae; /*1~10 */
    kal_int16 asd_idx_weight_ls_awb; /*1~10 */
    kal_int16 asd_idx_weight_ls_af;  /*1~10 */
    kal_int16 asd_idx_weight_ls_scd;  /*1~10 */
    kal_int16 asd_ev_lo_thr_night; /* 50 -> Lv=5 */
    kal_int16 asd_ev_hi_thr_night; /* 80 -> Lv=8 */
    kal_int16 asd_ev_lo_thr_outdoor;  /*90 -> Lv=9 */
    kal_int16 asd_ev_hi_thr_outdoor; /*130 -> Lv=13 */
    kal_uint8 asd_score_thr_night; /* 40~100 */
    kal_uint8 asd_score_thr_backlit; /* 40~100 */
    kal_uint8 asd_score_thr_portrait; /* 40~100 */
    kal_uint8 asd_score_thr_landscape; /* 40~100 */
    kal_bool asd_backlit_lock_enable; /* whether to enable backlit condition */
    kal_int16 asd_backlit_lock_ev_diff; /* -50~0 */
    /* mav */
    kal_uint32 mavcap_tolerance_x; //(default: 8) 7~9 ; x direction tolerance for capture, currently, not be used just for extension in the future
    kal_uint32 mavcap_tolerance_y; //(default: 8) 7~9 ; y direction tolerance for capture, currently, not be used just for extension in the future    
    kal_int32 mavcap_MaxMV; //maximum motion vertor
    kal_int32 mavcap_StepLB; //lower bound of frame step
    kal_int32 mavcap_StepUB; //upper bound of frame step
    kal_int32 mav_RCWinBound; //(default: 30) 20~40 ; RC Window Bound to select points
    kal_int32 mav_SearchRange; //(default: 15) 13~18 should larger than 1.5x MaxMV ; Search Range to find the matching pair
    kal_int32 mav_MatchRate; //(default: 48) 45~51 ; Error rate between minimum error and second minimum error
    kal_int32 mav_RectErrThre; //(default: 8) 7~9 ; Pixel error threshold for self image rectification
    kal_int32 mav_IterNum; //(default: 5) 3~7 ; Iteration number of LM method
    kal_int32 mav_MaxAngle; //(default: 10) 7~13 ; Maximum angle for self image recitification
    kal_int32 mav_ClipRatio; //(default: 154) 140~165 ; Image clip ratio after alignment (real value*256)
    kal_uint32 mavcap_GyroMvBound;//(default: 10 ) 1~20 ; MV bound (uint:pixel) for gyro action start
} CAMERA_POST_PROCESS_PARA_STRUCT, *P_CAMERA_POST_PROCESS_PARA_STRUCT;
    
#endif /* __PP_COMM_DEF_H__ */
