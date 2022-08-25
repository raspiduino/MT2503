/*****************************************************************************
 * Filename:
 * ---------
 * hal_custom_video_codec.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for customization of video codec
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __HAL_CUSTOM_VIDEO_CODEC_H__
#define __HAL_CUSTOM_VIDEO_CODEC_H__
#include "drv_features_vcodec.h"
//#include "video_codec_custom_type.h"

/******************************************************************************
*
*  Note that the definitions in this interface file should NOT be removed
*
******************************************************************************/

/******************************************************************************
* Setting of custom array table, for lossy setting
******************************************************************************/
/* MP4 custom table */
//#define MP4_CODEC_CUSTOM_TABLE_SETTING_ENABLE
#ifdef MP4_CODEC_CUSTOM_TABLE_SETTING_ENABLE
    //TABLE_SETTING_0   : dynamic switch threshold for quality mode
    //TABLE_SETTING_1   : initial quality mode (0:lossless, ..., n: sub-sample, n+1: default)
    //TABLE_SETTING_2   : dynamic switch flag
    //TABLE_SETTING_3   : bit0~7   - drop B (0: always not drop, 1: adaptive drop non-ref B ,2: always drop non-ref B)
    //                  : bit8~15  - drop B threshold , range from 0~128
    //                  : bit16~31 - observe time difference duration , default value 250
    //TABLE_SETTING_4   : skip P threshold
    //TABLE_SETTING_6   : A/V async tolerance
    #define MP4_CODEC_CUSTOM_TABLE_SETTING_0       (0x706060)
    #define MP4_CODEC_CUSTOM_TABLE_SETTING_1       (4)
    #define MP4_CODEC_CUSTOM_TABLE_SETTING_2       (1)
    #define MP4_CODEC_CUSTOM_TABLE_SETTING_3       (0x00FA7001)
    #define MP4_CODEC_CUSTOM_TABLE_SETTING_4       (151)
    #define MP4_CODEC_CUSTOM_TABLE_SETTING_6       (250)

#endif /* MP4_CODEC_CUSTOM_TABLE_SETTING_ENABLE */    

/* H264 custom table */
//#define H264_CODEC_CUSTOM_TABLE_SETTING_ENABLE
#ifdef H264_CODEC_CUSTOM_TABLE_SETTING_ENABLE
    //TABLE_SETTING_0   : dynamic switch threshold for quality mode
    //TABLE_SETTING_1   : initial quality mode (0:lossless, ..., n: sub-sample, n+1: default)
    //TABLE_SETTING_2   : dynamic switch flag
    //TABLE_SETTING_3   : bit0~7   - drop B (0: always not drop, 1: adaptive drop non-ref B ,2: always drop non-ref B)
    //                  : bit8~15  - drop B threshold , range from 0~128
    //                  : bit16~31 - observe time difference duration , default value 250
    //TABLE_SETTING_6   : A/V async tolerance
    #define H264_CODEC_CUSTOM_TABLE_SETTING_0       (0x706060)
    #define H264_CODEC_CUSTOM_TABLE_SETTING_1       (4)
    #define H264_CODEC_CUSTOM_TABLE_SETTING_2       (1)
    #define H264_CODEC_CUSTOM_TABLE_SETTING_3       (0x00FA7001)
    #define H264_CODEC_CUSTOM_TABLE_SETTING_6       (250)

#endif /* H264_CODEC_CUSTOM_TABLE_SETTING_ENABLE */    

/* RM custom table */
//#define RM_CODEC_CUSTOM_TABLE_SETTING_ENABLE
#ifdef RM_CODEC_CUSTOM_TABLE_SETTING_ENABLE
    //TABLE_SETTING_0   : dynamic switch threshold for quality mode
    //TABLE_SETTING_1   : initial quality mode (0:lossless, ..., n: sub-sample, n+1: default)
    //TABLE_SETTING_2   : dynamic switch flag
    //TABLE_SETTING_3   : drop B (0: always not drop, 1: always drop non-ref B, 2: default)
    #define RM_CODEC_CUSTOM_TABLE_SETTING_0       (0)
    #define RM_CODEC_CUSTOM_TABLE_SETTING_1       (16)
    #define RM_CODEC_CUSTOM_TABLE_SETTING_2       (1)
    #define RM_CODEC_CUSTOM_TABLE_SETTING_3       (2)
    
#endif /* RM_CODEC_CUSTOM_TABLE_SETTING_ENABLE */   

//////////////////////////////////////////////////////////////////////////////////////////////////
//#define SW_MP4_SPEEDY_CUSTOM_ENABLE
#ifdef SW_MP4_SPEEDY_CUSTOM_ENABLE
#define SW_MP4_SPEEDY_BOUND_RES_3_CUSTOM        (864*480)
#define SW_MP4_SPEEDY_BOUND_RES_2_CUSTOM        (640*480)
#define SW_MP4_SPEEDY_BOUND_RES_1_CUSTOM        (480*320)
#define SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_2_CUSTOM (640*480)
#define SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_1_CUSTOM (320*240)
#endif //SW_MP4_SPEEDY_CUSTOM_ENABLE

//#define SW_H264_SPEEDY_CUSTOM_ENABLE
#ifdef SW_H264_SPEEDY_CUSTOM_ENABLE
#define SW_H264_SPEEDY_BOUND_RES_1_BP_CUSTOM              (320*240)
#define SW_H264_SPEEDY_BOUND_RES_1_MPHP_CUSTOM            (320*240) 
#define SW_H264_SPEEDY_BOUND_RES_2_BP_CUSTOM              (640*480)
#define SW_H264_SPEEDY_BOUND_RES_2_MPHP_CUSTOM            (640*480)
#define SW_H264_CONCEAL_MODE_SETTING_CUSTOM 1
#endif //SW_H264_SPEEDY_CUSTOM_ENABLE

//#define SW_RM_SPEEDY_CUSTOM_ENABLE
#ifdef SW_RM_SPEEDY_CUSTOM_ENABLE
#define SW_RM_SPEEDY_BOUND_RES_0_CUSTOM 0
#define SW_RM_SPEEDY_BOUND_RES_1_CUSTOM 0
#define SW_RM_SPEEDY_BOUND_RES_2_CUSTOM (848*480)
#define SW_RM_SPEEDY_BOUND_RES_3_CUSTOM 0
#define SW_RM_SPEEDY_BOUND_RES_4_CUSTOM 0
#endif //SW_RM_SPEEDY_CUSTOM_ENABLE


#endif // __HAL_CUSTOM_VIDEO_CODEC_H__

