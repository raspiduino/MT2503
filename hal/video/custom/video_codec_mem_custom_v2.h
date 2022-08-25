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
 *   video_codec_mem_custom_v2.h
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 ****************************************************************************/

#ifndef VIDEO_CODEC_MEM_CUSTOM_V2_H
#define VIDEO_CODEC_MEM_CUSTOM_V2_H

#include "drv_features_video.h"

#if defined(__VE_VIDEO_ARCHI_V2__)
#include "drv_comm.h"
#include "drv_features_chip_select.h"
#include "video_codec_custom_type.h"
#include "hal_custom_video_if.h"
#include "hw_video_decode_custom.h"
#include "sw_video_decode_custom.h"


/***********************************************************************
*
*   Chips that video v2 supported
*
*   Please note that any modification of this section is prohibited
*
***********************************************************************/
#if defined(MT6236) || defined(MT6236B)
    #define __VIDEO_V2_MT6236_SERIES__
    #if defined(MT6921)
        #define __VIDEO_V2_MT6921_SERIES__
    #endif
#elif defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6253T)
    #define __VIDEO_V2_MT6253_SERIES__
#elif defined(MT6252) || defined(MT6252H)
    #define __VIDEO_V2_MT6252_SERIES__
#elif defined(MT6276)
    #define __VIDEO_V2_MT6276_SERIES__
#elif defined(MT6256)
    #define __VIDEO_V2_MT6256_SERIES__
#elif defined(MT6268) || defined(MT6268T) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
    #define __VIDEO_V2_MT6268_SERIES__
#elif defined(MT6235) || defined(MT6235B)
    #define __VIDEO_V2_MT6235_SERIES__
#elif defined(MT6255)
    #define __VIDEO_V2_MT6255_SERIES__
    #if defined(MT6922) && !defined(NAND_SUPPORT)
        #define __VIDEO_V2_MT6922_SERIES__
    #endif
#elif defined(MT6250)
    #define __VIDEO_V2_MT6250_SERIES__
#elif defined(MT6260)
    #define __VIDEO_V2_MT6260_SERIES__
#elif defined(MT6261)
    #define __VIDEO_V2_MT6261_SERIES__
#endif

/***************************************
*
*   Check resolution setting
*
***************************************/

#if ((RESOLUTION_128x96 != 0) || \
       (RESOLUTION_176x144 != 1) || \
       (RESOLUTION_320x240 != 2) || \
       (RESOLUTION_400x240 != 3) || \
       (RESOLUTION_352x288 != 4) || \
       (RESOLUTION_432x240 != 5) || \
       (RESOLUTION_480x320 != 6) || \
       (RESOLUTION_640x368 != 7) || \
       (RESOLUTION_640x480 != 8) || \
       (RESOLUTION_720x480 != 9) || \
       (RESOLUTION_800x480 != 10) || \
       (RESOLUTION_848x480 != 11) || \
       (RESOLUTION_720x576 != 12) || \
       (RESOLUTION_800x608 != 13) || \
       (RESOLUTION_1024x768 != 14) || \
       (RESOLUTION_1280x720 != 15) || \
       (RESOLUTION_1280x960 != 16) || \
       (RESOLUTION_1280x1024 != 17) || \
       (RESOLUTION_1408x1152 != 18) || \
       (RESOLUTION_1600x1200 != 19) || \
       (RESOLUTION_1920x1088 != 20))
#error "Please do not modify the resolution settings"
#endif

/***********************************************************************
*
*   Custom settings of
*   - The numbers of frame buffer
*   - Maximum resolution supported
*
***********************************************************************/


/******************************************************************************
* Setting for MT6236 series
******************************************************************************/
#if defined(__VIDEO_V2_MT6236_SERIES__)
    #if defined(__VIDEO_V2_MT6921_SERIES__)
        #ifdef __MPEG4_ENC_SW_SUPPORT__
            #if defined(__VE_SLIM_RECORDER_SOURCE__)
                #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       1
            #else
                #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       2
            #endif
            #define MPEG4_ENC_BIT_BUFFER_SIZE           196608
        #endif  // __MPEG4_ENC_SW_SUPPORT__

        #ifdef __MPEG4_DEC_SW_SUPPORT__
            #define MPEG4_EXTRA_BUFFER_NUM_SP  2
            #define MPEG4_EXTRA_BUFFER_NUM_ASP 3
        #endif // __MPEG4_DEC_SW_SUPPORT__

        #ifdef __H264_DEC_SW_SUPPORT__
            #define H264_EXTRA_BUFFER_NUM_BP   4
            #define H264_EXTRA_BUFFER_NUM_MPHP 4
        #endif //__H264_DEC_SW_SUPPORT__

        #ifdef __RV_DEC_SW_SUPPORT__
            #ifdef __SW_VIDEO_MAX_RESOLUTION__
                #define RV9_EXTRA_BUFFER_NUM    10
            #else
                #define RV9_EXTRA_BUFFER_NUM    10
            #endif
        #endif //__RV_DEC_SW_SUPPORT__
    #else //__VIDEO_V2_MT6921_SERIES__
        #ifdef __VE_MPEG4_DEC_SW_SUPPORT__
            #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
                #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                    #define MPEG4_EXTRA_BUFFER_NUM_SP                3
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP               4
                #else
                    #define MPEG4_EXTRA_BUFFER_NUM_SP                3
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP               4
                #endif
            #else
                #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                    #define MPEG4_EXTRA_BUFFER_NUM_SP                3
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP               4
                #else
                    #define MPEG4_EXTRA_BUFFER_NUM_SP                3
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP               4
                #endif
            #endif
        #endif /*__VE_MPEG4_DEC_SW_SUPPORT__*/

        #ifdef __VE_H264_DEC_SW_SUPPORT__
            #ifdef __VE_H264_DEC_SW_SLIM__
                #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                    #define H264_EXTRA_BUFFER_NUM_BP            11
                    #define H264_EXTRA_BUFFER_NUM_MPHP          11
                #else
                    #define H264_EXTRA_BUFFER_NUM_BP            11
                    #define H264_EXTRA_BUFFER_NUM_MPHP          11
                #endif
            #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
                #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                    #define H264_EXTRA_BUFFER_NUM_BP                5
                    #define H264_EXTRA_BUFFER_NUM_MPHP              5
                #else
                    #define H264_EXTRA_BUFFER_NUM_BP                5
                    #define H264_EXTRA_BUFFER_NUM_MPHP              5
                #endif
            #else
                #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                    #define H264_EXTRA_BUFFER_NUM_BP                11
                    #define H264_EXTRA_BUFFER_NUM_MPHP              11
                #else
                    #define H264_EXTRA_BUFFER_NUM_BP                11
                    #define H264_EXTRA_BUFFER_NUM_MPHP              11
                #endif
            #endif /* __VE_H264_DEC_SW_SLIM__ */
        #endif

        #ifdef __VE_RV_DEC_SW_SUPPORT__
            #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
                #define RV9_EXTRA_BUFFER_NUM                 10
            #else
                #define RV9_EXTRA_BUFFER_NUM                 10
            #endif
        #endif

        #ifdef __VE_MJPEG_DEC_SW_SUPPORT__
            #define MJPEG_EXTRA_BUFFER_NUM            1
        #endif

        #ifdef __VE_VP8_DEC_SW_SUPPORT__
            #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
                #define VP8_EXTRA_BUFFER_NUM                 0
            #else
                #define VP8_EXTRA_BUFFER_NUM                 0
            #endif
        #endif

        #ifdef __VE_MPEG4_ENC_SW_SUPPORT__
            #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       2
            #define MPEG4_ENC_BIT_BUFFER_SIZE           196608
        #endif  // __VE_MPEG4_ENC_SW_SUPPORT__

        #ifdef __VE_MJPEG_ENC_SUPPORT__
            #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM       2
            #define MJPEG_ENC_BIT_BUFFER_SIZE           (196608*2 + 32*1024)
        #endif //__VE_MJPEG_ENC_SUPPORT__
    #endif  // __VIDEO_V2_MT6921_SERIES__
#endif  // __VIDEO_V2_MT6236_SERIES__


/******************************************************************************
* Setting for MT6253 series
******************************************************************************/
#if defined(__VIDEO_V2_MT6253_SERIES__)
    #ifdef __VE_MPEG4_DEC_SW_SUPPORT__
        #ifdef __VE_MP4_DEC_SW_SLIM__
            #if defined (__VE_MED_VIDEO_ULC__) && defined(__MPEG4_QCIF_TO_CIF__)
                #define MPEG4_EXTRA_BUFFER_NUM_SP                0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP               1
            #elif defined (__VE_MED_VIDEO_ULC__)
                #define MPEG4_EXTRA_BUFFER_NUM_SP                0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP               1
            #else
                #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                    #define MPEG4_EXTRA_BUFFER_NUM_SP                0
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP               1
                #else
                    #define MPEG4_EXTRA_BUFFER_NUM_SP                0
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP               1
                #endif
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP                1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP               2
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP                1
            #endif
        #else
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP                1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP               2
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP                1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP               2
            #endif
        #endif
    #endif /*__VE_MPEG4_DEC_SW_SUPPORT__*/

    #ifdef __VE_H264_DEC_SW_SUPPORT__
        #ifdef __VE_H264_DEC_SW_SLIM__
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                4
                #define H264_EXTRA_BUFFER_NUM_MPHP              4
            #else
                #define H264_EXTRA_BUFFER_NUM_BP                4
                #define H264_EXTRA_BUFFER_NUM_MPHP              4
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                12
                #define H264_EXTRA_BUFFER_NUM_MPHP              12
            #else
                #define H264_EXTRA_BUFFER_NUM_BP                6
                #define H264_EXTRA_BUFFER_NUM_MPHP              6
            #endif
        #else
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                3
                #define H264_EXTRA_BUFFER_NUM_MPHP              3
            #else
                #define H264_EXTRA_BUFFER_NUM_BP                4
                #define H264_EXTRA_BUFFER_NUM_MPHP              4
            #endif
        #endif
    #endif  /*__VE_H264_DEC_SW_SUPPORT__*/

    #ifdef __VE_RV_DEC_SW_SUPPORT__
        #ifdef __VE_RM_DEC_SW_SLIM__
            #define RV9_EXTRA_BUFFER_NUM            0
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #define RV9_EXTRA_BUFFER_NUM            0
        #else
            #define RV9_EXTRA_BUFFER_NUM            0
        #endif
    #endif  // __VE_RV_DEC_SW_SUPPORT__

    #ifdef __VE_MJPEG_DEC_SW_SUPPORT__
        #define MJPEG_EXTRA_BUFFER_NUM            0
    #endif  // __VE_MJPEG_DEC_SW_SUPPORT__

    #ifdef __VE_VP8_DEC_SW_SUPPORT__
        #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
            #define VP8_EXTRA_BUFFER_NUM                 0
        #else
            #define VP8_EXTRA_BUFFER_NUM                 0
        #endif
    #endif  // __VE_VP8_DEC_SW_SUPPORT__

    #ifdef __VE_MPEG4_ENC_SW_SUPPORT__
        #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       1
        #define MPEG4_ENC_BIT_BUFFER_SIZE           131072
    #endif  // __VE_MPEG4_ENC_SW_SUPPORT__

    #ifdef __VE_MJPEG_ENC_SUPPORT__
        #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM       (0)
        #define MJPEG_ENC_BIT_BUFFER_SIZE           (85*1024)
    #endif //__VE_MJPEG_ENC_SUPPORT__
#endif  // __VIDEO_V2_MT6253_SERIES__


/******************************************************************************
* Setting for MT6252 series
******************************************************************************/
#if defined(__VIDEO_V2_MT6252_SERIES__)
    #ifdef __VE_MPEG4_DEC_SW_SUPPORT__
        #ifdef __VE_MP4_DEC_SW_SLIM__
            #if defined (__VE_MED_VIDEO_ULC__) && defined(__MPEG4_QCIF_TO_CIF__)
                #define MPEG4_EXTRA_BUFFER_NUM_SP                0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP               1
            #elif defined (__VE_MED_VIDEO_ULC__)
                #define MPEG4_EXTRA_BUFFER_NUM_SP                0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP               1
            #else
                #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                    #define MPEG4_EXTRA_BUFFER_NUM_SP                0
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP               1
                #else
                    #define MPEG4_EXTRA_BUFFER_NUM_SP                0
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP               1
                #endif
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP                1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP               2
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP                1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP               2
            #endif
        #else
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP                1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP               2
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP                1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP               2
            #endif
        #endif
    #endif /*__VE_MPEG4_DEC_SW_SUPPORT__*/

    #ifdef __VE_H264_DEC_SW_SUPPORT__
        #ifdef __VE_H264_DEC_SW_SLIM__
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                4
                #define H264_EXTRA_BUFFER_NUM_MPHP              4
            #else
                #define H264_EXTRA_BUFFER_NUM_BP                4
                #define H264_EXTRA_BUFFER_NUM_MPHP              4
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                12
                #define H264_EXTRA_BUFFER_NUM_MPHP              12
            #else
                #define H264_EXTRA_BUFFER_NUM_BP                6
                #define H264_EXTRA_BUFFER_NUM_MPHP              6
            #endif
        #else
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                5
                #define H264_EXTRA_BUFFER_NUM_MPHP              5
            #else
                #define H264_EXTRA_BUFFER_NUM_BP                4
                #define H264_EXTRA_BUFFER_NUM_MPHP              4
            #endif
        #endif
    #endif  /*__VE_H264_DEC_SW_SUPPORT__*/

    #ifdef __VE_RV_DEC_SW_SUPPORT__
        #ifdef __VE_RM_DEC_SW_SLIM__
            #define RV9_EXTRA_BUFFER_NUM            0
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #define RV9_EXTRA_BUFFER_NUM            0
        #else
            #define RV9_EXTRA_BUFFER_NUM            0
        #endif
    #endif  // __VE_RV_DEC_SW_SUPPORT__

    #ifdef __VE_MJPEG_DEC_SW_SUPPORT__
        #define MJPEG_EXTRA_BUFFER_NUM            0
    #endif  // __VE_MJPEG_DEC_SW_SUPPORT__

    #ifdef __VE_VP8_DEC_SW_SUPPORT__
        #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
            #define VP8_EXTRA_BUFFER_NUM                 0
        #else
            #define VP8_EXTRA_BUFFER_NUM                 0
        #endif
    #endif  // __VE_VP8_DEC_SW_SUPPORT__

    #ifdef __VE_MPEG4_ENC_SW_SUPPORT__
        #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       1
        #define MPEG4_ENC_BIT_BUFFER_SIZE           131072
    #endif  // __VE_MPEG4_ENC_SW_SUPPORT__

    #ifdef __VE_MJPEG_ENC_SUPPORT__
        #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM       (0)
        #define MJPEG_ENC_BIT_BUFFER_SIZE           (85*1024)
    #endif //__VE_MJPEG_ENC_SUPPORT__
#endif  // __VIDEO_V2_MT6252_SERIES__


/******************************************************************************
* Setting for MT6256 series
******************************************************************************/
#if defined(__VIDEO_V2_MT6256_SERIES__)
    #ifdef __VE_MPEG4_DEC_SW_SUPPORT__
        #ifdef __VE_MP4_DEC_SW_SLIM__
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP  0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP 1
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP  0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP 1
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP  1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP 2
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP  1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP 2
            #endif
        #else
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP  0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP 1
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP  0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP 1
            #endif
        #endif
    #endif /*__VE_MPEG4_DEC_SW_SUPPORT__*/

    #ifdef __VE_H264_DEC_SW_SUPPORT__
        #ifdef __VE_H264_DEC_SW_SLIM__
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP    8
                #define H264_EXTRA_BUFFER_NUM_MPHP  9
            #else
                #define H264_EXTRA_BUFFER_NUM_BP    8
                #define H264_EXTRA_BUFFER_NUM_MPHP  9
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP    9
                #define H264_EXTRA_BUFFER_NUM_MPHP  5
            #endif
        #else
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP    6
                #define H264_EXTRA_BUFFER_NUM_MPHP  9
            #else
                #define H264_EXTRA_BUFFER_NUM_BP    6
                #define H264_EXTRA_BUFFER_NUM_MPHP  9
            #endif
        #endif
    #endif  // __VE_H264_DEC_SW_SUPPORT__

    #ifdef __VE_RV_DEC_SW_SUPPORT__
        #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
            #define RV9_EXTRA_BUFFER_NUM            0
        #else
            #define RV9_EXTRA_BUFFER_NUM            0
        #endif
    #endif  // __VE_RV_DEC_SW_SUPPORT__

    #ifdef __VE_MJPEG_DEC_SW_SUPPORT__
        #ifdef __VE_MJPG_DEC_SW_SLIM__
            #define MJPEG_EXTRA_BUFFER_NUM            0
        #else
            #define MJPEG_EXTRA_BUFFER_NUM            1
        #endif
    #endif  // __VE_MJPEG_DEC_SW_SUPPORT__

    #ifdef __VE_VP8_DEC_SW_SUPPORT__
        #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
            #define VP8_EXTRA_BUFFER_NUM                 0
        #else
            #define VP8_EXTRA_BUFFER_NUM                 0
        #endif
    #endif  // __VE_VP8_DEC_SW_SUPPORT__

    #ifdef __VE_MPEG4_ENC_SW_SUPPORT__
        #if defined(__VE_MPEG4_ENC_SW_SLIM__)
        #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       2
        #define MPEG4_ENC_BIT_BUFFER_SIZE           262144
        #else
        #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       2
            #define MPEG4_ENC_BIT_BUFFER_SIZE           393216
        #endif
    #endif  // __VE_MPEG4_ENC_SW_SUPPORT__

    #ifdef __VE_H264_ENC_SW_SUPPORT__
        #define H264_ENC_EXTRA_YUV_FRAME_NUM       4
        #define H264_ENC_BIT_BUFFER_SIZE           (256*1024)
    #endif //__VE_H264_ENC_SW_SUPPORT__
#endif  // __VIDEO_V2_MT6256_SERIES__


/******************************************************************************
* Setting for MT6276 series
******************************************************************************/
#if defined(__VIDEO_V2_MT6276_SERIES__)
    #ifdef __VE_MPEG4_DEC_SW_SUPPORT__
        #ifdef __VE_MP4_DEC_SW_SLIM__
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP  0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP 1
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP  0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP 1
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP  1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP 2
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP  1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP 2
            #endif
        #else
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP  0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP 1
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP  0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP 1
            #endif
        #endif
    #endif /*__VE_MPEG4_DEC_SW_SUPPORT__*/

    #ifdef __VE_H264_DEC_SW_SUPPORT__
        #ifdef __VE_H264_DEC_SW_SLIM__
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP  8
                #define H264_EXTRA_BUFFER_NUM_MPHP  9
            #else
                #define H264_EXTRA_BUFFER_NUM_BP  8
                #define H264_EXTRA_BUFFER_NUM_MPHP  9
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP  9
                #define H264_EXTRA_BUFFER_NUM_MPHP  5
            #endif
        #else
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP  6
                #define H264_EXTRA_BUFFER_NUM_MPHP  9
            #else
                #define H264_EXTRA_BUFFER_NUM_BP  6
                #define H264_EXTRA_BUFFER_NUM_MPHP  9
            #endif
        #endif
    #endif  // __VE_H264_DEC_SW_SUPPORT__

    #ifdef __VE_RV_DEC_SW_SUPPORT__
        #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
            #define RV9_EXTRA_BUFFER_NUM                 0
        #else
            #define RV9_EXTRA_BUFFER_NUM                 0
        #endif
    #endif  // __VE_RV_DEC_SW_SUPPORT__

    #ifdef __VE_MJPEG_DEC_SW_SUPPORT__
        #ifdef __VE_MJPG_DEC_SW_SLIM__
            #define MJPEG_EXTRA_BUFFER_NUM            0
        #else
            #define MJPEG_EXTRA_BUFFER_NUM            1
        #endif
    #endif  // __VE_MJPEG_DEC_SW_SUPPORT__

    #ifdef __VE_VP8_DEC_SW_SUPPORT__
        #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
            #define VP8_EXTRA_BUFFER_NUM                 0
        #else
            #define VP8_EXTRA_BUFFER_NUM                 0
        #endif
    #endif  // __VE_VP8_DEC_SW_SUPPORT__

    #ifdef __VE_MPEG4_ENC_SW_SUPPORT__
        #if defined(__VE_MPEG4_ENC_SW_SLIM__)
            #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       2
            #define MPEG4_ENC_BIT_BUFFER_SIZE           262144
        #else
            #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       2
            #define MPEG4_ENC_BIT_BUFFER_SIZE           393216
        #endif
    #endif  // __VE_MPEG4_ENC_SW_SUPPORT__

    #ifdef __VE_H264_ENC_SW_SUPPORT__
        #define H264_ENC_EXTRA_YUV_FRAME_NUM       4
        #define H264_ENC_BIT_BUFFER_SIZE           (256*1024)
    #endif //__VE_H264_ENC_SW_SUPPORT__
#endif  // __VIDEO_V2_MT6276_SERIES__


/******************************************************************************
* Setting for MT6268 series
******************************************************************************/
#if defined(__VIDEO_V2_MT6268_SERIES__)
    #ifdef __VE_MPEG4_DEC_HW_SUPPORT__
        #define MPEG4_EXTRA_BUFFER_NUM_SP                3
        #define MPEG4_EXTRA_BUFFER_NUM_ASP               4
    #endif  // __VE_MPEG4_DEC_HW_SUPPORT__

    #ifdef __VE_H264_DEC_HW_SUPPORT__
        #define H264_EXTRA_BUFFER_NUM_BP            5
    #endif

    #ifdef __VE_MPEG4_ENC_HW_SUPPORT__
        #define MPEG4_HW_ENC_EXTRA_YUV_FRAME_NUM       0
        #define MPEG4_HW_ENC_BIT_BUFFER_SIZE           2621440
    #endif
#endif  // __VIDEO_V2_MT6268_SERIES__


/******************************************************************************
* Setting for MT6235 series
******************************************************************************/
#if defined(__VIDEO_V2_MT6235_SERIES__)
    #ifdef __VE_MPEG4_DEC_SW_SUPPORT__
        #define MPEG4_EXTRA_BUFFER_NUM_SP                3
        #define MPEG4_EXTRA_BUFFER_NUM_ASP               4
    #endif /*__VE_MPEG4_DEC_SW_SUPPORT__*/

    #ifdef __VE_H264_DEC_SW_SUPPORT__
        //#define H264_EXTRA_BUFFER_NUM_BP            17
        #ifdef __VE_H264_DEC_SW_SLIM__
            #define H264_EXTRA_BUFFER_NUM_BP            11
            #define H264_EXTRA_BUFFER_NUM_MPHP          11
        #else
            #define H264_EXTRA_BUFFER_NUM_BP            11
            #define H264_EXTRA_BUFFER_NUM_MPHP          11
        #endif
    #endif /*__VE_H264_DEC_SW_SUPPORT__*/

    #ifdef __VE_MJPEG_DEC_SW_SUPPORT__
        #define MJPEG_EXTRA_BUFFER_NUM              1
    #endif

    #ifdef __VE_MPEG4_ENC_SW_SUPPORT__
        #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       2
        #define MPEG4_ENC_BIT_BUFFER_SIZE           262144
    #endif  // __VE_MPEG4_ENC_SW_SUPPORT__

    #ifdef __VE_MJPEG_ENC_SUPPORT__
        #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM       2
        #define MJPEG_ENC_BIT_BUFFER_SIZE           (196608*2 + 32*1024)
    #endif //__VE_MJPEG_ENC_SUPPORT__

    #ifdef __VE_RV_DEC_SW_SUPPORT__
        #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
            #define RV9_EXTRA_BUFFER_NUM                 0
        #else
            #define RV9_EXTRA_BUFFER_NUM                 0
        #endif
    #endif  // __VE_RV_DEC_SW_SUPPORT__

    #ifdef __VE_VP8_DEC_SW_SUPPORT__
        #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
            #define VP8_EXTRA_BUFFER_NUM                 0
        #else
            #define VP8_EXTRA_BUFFER_NUM                 0
        #endif
    #endif  // __VE_VP8_DEC_SW_SUPPORT__
#endif  // __VIDEO_V2_MT6235_SERIES__


/******************************************************************************
* Setting for MT6255 series
******************************************************************************/
#if defined(__VIDEO_V2_MT6255_SERIES__)
    #if defined(__VIDEO_V2_MT6922_SERIES__)
        #ifdef __MPEG4_ENC_SW_SUPPORT__
            #if defined(__VE_SLIM_RECORDER_SOURCE__)
                #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       1
            #else
                #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       2
            #endif
            #define MPEG4_ENC_BIT_BUFFER_SIZE           196608
        #endif  // __MPEG4_ENC_SW_SUPPORT__

        #ifdef __MPEG4_DEC_SW_SUPPORT__
            #define MPEG4_EXTRA_BUFFER_NUM_SP  2
            #define MPEG4_EXTRA_BUFFER_NUM_ASP 3
        #endif // __MPEG4_DEC_SW_SUPPORT__

        #ifdef __H264_DEC_SW_SUPPORT__
            #define H264_EXTRA_BUFFER_NUM_BP   4
            #define H264_EXTRA_BUFFER_NUM_MPHP 4
        #endif //__H264_DEC_SW_SUPPORT__

        #ifdef __RV_DEC_SW_SUPPORT__
            #ifdef __SW_VIDEO_MAX_RESOLUTION__
                #define RV9_EXTRA_BUFFER_NUM    10
            #else
                #define RV9_EXTRA_BUFFER_NUM    10
            #endif
        #endif //__RV_DEC_SW_SUPPORT__
    #else //__VIDEO_V2_MT6922_SERIES__
        #ifdef __VE_MPEG4_DEC_SW_SUPPORT__
            #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
                #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                    #define MPEG4_EXTRA_BUFFER_NUM_SP                3
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP               4
                #else
                    #define MPEG4_EXTRA_BUFFER_NUM_SP                3
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP               4
                #endif
            #else
                #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                    #define MPEG4_EXTRA_BUFFER_NUM_SP                3
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP               4
                #else
                    #define MPEG4_EXTRA_BUFFER_NUM_SP                3
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP               4
                #endif
            #endif
        #endif /*__VE_MPEG4_DEC_SW_SUPPORT__*/

        #ifdef __VE_H264_DEC_SW_SUPPORT__
            #ifdef __VE_H264_DEC_SW_SLIM__
                #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                    #define H264_EXTRA_BUFFER_NUM_BP                9
                    #define H264_EXTRA_BUFFER_NUM_MPHP              9
                #else
                    #define H264_EXTRA_BUFFER_NUM_BP                9
                    #define H264_EXTRA_BUFFER_NUM_MPHP              9
                #endif
            #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
                #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                    #define H264_EXTRA_BUFFER_NUM_BP                5
                    #define H264_EXTRA_BUFFER_NUM_MPHP              5
                #else
                    #define H264_EXTRA_BUFFER_NUM_BP                5
                    #define H264_EXTRA_BUFFER_NUM_MPHP              5
                #endif
            #else
                #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                    #define H264_EXTRA_BUFFER_NUM_BP                9
                    #define H264_EXTRA_BUFFER_NUM_MPHP              9
                #else
                    #define H264_EXTRA_BUFFER_NUM_BP                9
                    #define H264_EXTRA_BUFFER_NUM_MPHP              9
                #endif
            #endif /* __VE_H264_DEC_SW_SLIM__ */
        #endif

        #ifdef __VE_RV_DEC_SW_SUPPORT__
            #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
                #define RV9_EXTRA_BUFFER_NUM                 10
            #else
                #define RV9_EXTRA_BUFFER_NUM                 10
            #endif
        #endif

        #ifdef __VE_MJPEG_DEC_SW_SUPPORT__
            #define MJPEG_EXTRA_BUFFER_NUM            1
        #endif

        #ifdef __VE_VP8_DEC_SW_SUPPORT__
            #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
                #define VP8_EXTRA_BUFFER_NUM                 0
            #else
                #define VP8_EXTRA_BUFFER_NUM                 0
            #endif
        #endif

        #ifdef __VE_MPEG4_ENC_SW_SUPPORT__
            #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       2
            #define MPEG4_ENC_BIT_BUFFER_SIZE           (786432) // (196608) -> (786432)
        #endif  // __VE_MPEG4_ENC_SW_SUPPORT__

        #ifdef __VE_MJPEG_ENC_SUPPORT__
            #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM       2
            #define MJPEG_ENC_BIT_BUFFER_SIZE           (1675904) //(196608*2 + 32*1024) -> (1675904)
        #endif //__VE_MJPEG_ENC_SUPPORT__

        #ifdef __VE_H264_ENC_SW_SUPPORT__
            #define H264_ENC_EXTRA_YUV_FRAME_NUM       4
            #define H264_ENC_BIT_BUFFER_SIZE           (786432) // (256*1024) -> (786432)
        #endif //__VE_H264_ENC_SW_SUPPORT__
    #endif // defined(__VIDEO_V2_MT6922_SERIES__)
#endif  // __VIDEO_V2_MT6255_SERIES__


/******************************************************************************
* Setting for MT6250 series
******************************************************************************/
#if defined(__VIDEO_V2_MT6250_SERIES__)
    #ifdef __VE_MPEG4_DEC_SW_SUPPORT__
        #ifdef __VE_MP4_DEC_SW_SLIM__
            #ifdef __VE_MED_VIDEO_ULC__
                #define MPEG4_EXTRA_BUFFER_NUM_SP             0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #else
                #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                    #define MPEG4_EXTRA_BUFFER_NUM_SP         0
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP        1
                #else
                    #define MPEG4_EXTRA_BUFFER_NUM_SP         0
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP        1
                #endif
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP             1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP             1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #endif
        #else
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP             0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP             0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #endif
        #endif
    #endif /*__VE_MPEG4_DEC_SW_SUPPORT__*/

    #ifdef __VE_H264_DEC_SW_SUPPORT__
        #ifdef __VE_H264_DEC_SW_SLIM__
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                5
                #define H264_EXTRA_BUFFER_NUM_MPHP              5
            #else
                #define H264_EXTRA_BUFFER_NUM_BP                4
                #define H264_EXTRA_BUFFER_NUM_MPHP              4
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                12
                #define H264_EXTRA_BUFFER_NUM_MPHP              12
            #else
                #define H264_EXTRA_BUFFER_NUM_BP                6
                #define H264_EXTRA_BUFFER_NUM_MPHP              6
            #endif
        #else
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                3
                #define H264_EXTRA_BUFFER_NUM_MPHP              3
            #else
                #define H264_EXTRA_BUFFER_NUM_BP                4
                #define H264_EXTRA_BUFFER_NUM_MPHP              4
            #endif
        #endif
    #endif  /*__VE_H264_DEC_SW_SUPPORT__*/

    #ifdef __VE_RV_DEC_SW_SUPPORT__
        #ifdef __VE_RM_DEC_SW_SLIM__
            #define RV9_EXTRA_BUFFER_NUM            0
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #define RV9_EXTRA_BUFFER_NUM            0
        #else
            #define RV9_EXTRA_BUFFER_NUM            0
        #endif
    #endif  // __VE_RV_DEC_SW_SUPPORT__

    #ifdef __VE_MJPEG_DEC_SW_SUPPORT__
        #define MJPEG_EXTRA_BUFFER_NUM            0
    #endif

    #ifdef __VE_VP8_DEC_SW_SUPPORT__
        #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
            #define VP8_EXTRA_BUFFER_NUM                 0
        #else
            #define VP8_EXTRA_BUFFER_NUM                 0
        #endif
    #endif  // __VE_VP8_DEC_SW_SUPPORT__

    #ifdef __VE_MPEG4_ENC_SW_SUPPORT__
        #ifdef __VE_MED_VIDEO_ULC__
            #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       1
            #define MPEG4_ENC_BIT_BUFFER_SIZE           (131072)
        #else
            #ifdef __VE_MPEG4_ENC_SW_SLIM__
                #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       1
                #define MPEG4_ENC_BIT_BUFFER_SIZE           (163840)
            #else
                #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       1
                #define MPEG4_ENC_BIT_BUFFER_SIZE           (327680)
            #endif
        #endif
    #endif  // __VE_MPEG4_ENC_SW_SUPPORT__

    #ifdef __VE_MJPEG_ENC_SUPPORT__
        #ifdef __VE_MED_VIDEO_ULC__
            #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM       (0)
            #define MJPEG_ENC_BIT_BUFFER_SIZE           (79200)
        #else
            #ifdef __VE_MJPEG_ENC_SW_SLIM__
                #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM       (0)
                #define MJPEG_ENC_BIT_BUFFER_SIZE           (171360) //(79200 + 92160)
            #else
                #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM       (0)
                #define MJPEG_ENC_BIT_BUFFER_SIZE           (465600) //(158400 + 307200)
            #endif
        #endif
    #endif //__VE_MJPEG_ENC_SUPPORT__
#endif  // __VIDEO_V2_MT6250_SERIES__

/******************************************************************************
* Setting for MT6260 series
******************************************************************************/
#if defined(__VIDEO_V2_MT6260_SERIES__)
    #ifdef __VE_MPEG4_DEC_SW_SUPPORT__
        #ifdef __VE_MP4_DEC_SW_SLIM__
            #ifdef __VE_MED_VIDEO_ULC__
                #define MPEG4_EXTRA_BUFFER_NUM_SP             0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #else
                #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                    #define MPEG4_EXTRA_BUFFER_NUM_SP         0
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP        1
                #else
                    #define MPEG4_EXTRA_BUFFER_NUM_SP         0
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP        1
                #endif
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP             1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP             1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #endif
        #else
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP             0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP             0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #endif
        #endif
    #endif /*__VE_MPEG4_DEC_SW_SUPPORT__*/

    #ifdef __VE_H264_DEC_SW_SUPPORT__
        #ifdef __VE_H264_DEC_SW_SLIM__
            #ifdef __VE_KMV_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                3
                #define H264_EXTRA_BUFFER_NUM_MPHP              3
            #else
                #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
		    #ifdef __MOT_SUPPORT__
                    #define H264_EXTRA_BUFFER_NUM_BP                3//5->3: MOT SLIM
                    #define H264_EXTRA_BUFFER_NUM_MPHP              3//5->3: MOT SLIM
                    #else
                    #define H264_EXTRA_BUFFER_NUM_BP                4
                    #define H264_EXTRA_BUFFER_NUM_MPHP              4
                    #endif
                #else
                    #define H264_EXTRA_BUFFER_NUM_BP                4
                    #define H264_EXTRA_BUFFER_NUM_MPHP              4
                #endif
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                12
                #define H264_EXTRA_BUFFER_NUM_MPHP              12
            #else
                #define H264_EXTRA_BUFFER_NUM_BP                6
                #define H264_EXTRA_BUFFER_NUM_MPHP              6
            #endif
        #else
            #ifdef __VE_KMV_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                3
                #define H264_EXTRA_BUFFER_NUM_MPHP              3            
            #else
                #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                    #define H264_EXTRA_BUFFER_NUM_BP                3
                    #define H264_EXTRA_BUFFER_NUM_MPHP              3
                #else
                    #define H264_EXTRA_BUFFER_NUM_BP                4
                    #define H264_EXTRA_BUFFER_NUM_MPHP              4
                #endif
            #endif
        #endif
    #endif  /*__VE_H264_DEC_SW_SUPPORT__*/

    #ifdef __VE_RV_DEC_SW_SUPPORT__
        #ifdef __VE_RM_DEC_SW_SLIM__
            #define RV9_EXTRA_BUFFER_NUM            0
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #define RV9_EXTRA_BUFFER_NUM            0
        #else
            #define RV9_EXTRA_BUFFER_NUM            0
        #endif
    #endif  // __VE_RV_DEC_SW_SUPPORT__

    #ifdef __VE_MJPEG_DEC_SW_SUPPORT__
        #define MJPEG_EXTRA_BUFFER_NUM            0
    #endif

    #ifdef __VE_VP8_DEC_SW_SUPPORT__
        #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
            #define VP8_EXTRA_BUFFER_NUM                 0
        #else
            #define VP8_EXTRA_BUFFER_NUM                 0
        #endif
    #endif  // __VE_VP8_DEC_SW_SUPPORT__

    #ifdef __VE_MPEG4_ENC_SW_SUPPORT__
        #ifdef __VE_MED_VIDEO_ULC__
            #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM           1
            #define MPEG4_ENC_BIT_BUFFER_SIZE               (131072)
        #else
            #ifdef __VE_MPEG4_ENC_SW_SLIM__
                #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       1
                #define MPEG4_ENC_BIT_BUFFER_SIZE           (163840)
            #else
                #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       1
                #define MPEG4_ENC_BIT_BUFFER_SIZE           (327680)
            #endif
        #endif
    #endif  // __VE_MPEG4_ENC_SW_SUPPORT__

    #ifdef __VE_MJPEG_ENC_SUPPORT__
        #ifdef __VE_MED_VIDEO_ULC__
            #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM           (0)
            #define MJPEG_ENC_BIT_BUFFER_SIZE               (79200)
        #else
            #ifdef __VE_MJPEG_ENC_SW_SLIM__
                #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM       (0)
                #define MJPEG_ENC_BIT_BUFFER_SIZE           (171360) //(79200 + 92160)
            #else
                #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM       (0)
                #define MJPEG_ENC_BIT_BUFFER_SIZE           (465600) //(158400 + 307200)
            #endif
        #endif
    #endif //__VE_MJPEG_ENC_SUPPORT__

	#ifdef __VE_H264_ENC_SW_SUPPORT__
		#define H264_ENC_EXTRA_YUV_FRAME_NUM	   0
		#define H264_ENC_BIT_BUFFER_SIZE		   (131072/4)
	#endif //__VE_H264_ENC_SW_SUPPORT__	
#endif  // __VIDEO_V2_MT6260_SERIES__

/******************************************************************************
* Setting for MT6261 series
******************************************************************************/
#if defined(__VIDEO_V2_MT6261_SERIES__)
    #ifdef __VE_MPEG4_DEC_SW_SUPPORT__
        #ifdef __VE_MP4_DEC_SW_SLIM__
            #ifdef __VE_MED_VIDEO_ULC__
                #define MPEG4_EXTRA_BUFFER_NUM_SP             0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #else
                #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                    #define MPEG4_EXTRA_BUFFER_NUM_SP         0
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP        1
                #else
                    #define MPEG4_EXTRA_BUFFER_NUM_SP         0
                    #define MPEG4_EXTRA_BUFFER_NUM_ASP        1
                #endif
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP             1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP             1
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #endif
        #else
            #ifdef __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
                #define MPEG4_EXTRA_BUFFER_NUM_SP             0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #else
                #define MPEG4_EXTRA_BUFFER_NUM_SP             0
                #define MPEG4_EXTRA_BUFFER_NUM_ASP            1
            #endif
        #endif
    #endif /*__VE_MPEG4_DEC_SW_SUPPORT__*/

    #ifdef __VE_H264_DEC_SW_SUPPORT__
        #ifdef __VE_H264_DEC_SW_SLIM__
            #ifdef __VE_KMV_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                4
                #define H264_EXTRA_BUFFER_NUM_MPHP              4
            #else
                #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
		            #ifdef __MOT_SUPPORT__
                    #define H264_EXTRA_BUFFER_NUM_BP                3//5->3: MOT SLIM
                    #define H264_EXTRA_BUFFER_NUM_MPHP              3//5->3: MOT SLIM
                    #else
                    #define H264_EXTRA_BUFFER_NUM_BP                4
                    #define H264_EXTRA_BUFFER_NUM_MPHP              4
                    #endif
                #else
                    #define H264_EXTRA_BUFFER_NUM_BP                4
                    #define H264_EXTRA_BUFFER_NUM_MPHP              4
                #endif
            #endif
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                12
                #define H264_EXTRA_BUFFER_NUM_MPHP              12
            #else
                #define H264_EXTRA_BUFFER_NUM_BP                6
                #define H264_EXTRA_BUFFER_NUM_MPHP              6
            #endif
        #else
            #ifdef __VE_KMV_SUPPORT__
                #define H264_EXTRA_BUFFER_NUM_BP                4
                #define H264_EXTRA_BUFFER_NUM_MPHP              4            
            #else
                #ifdef __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
                    #define H264_EXTRA_BUFFER_NUM_BP                3
                    #define H264_EXTRA_BUFFER_NUM_MPHP              3
                #else
                    #define H264_EXTRA_BUFFER_NUM_BP                4
                    #define H264_EXTRA_BUFFER_NUM_MPHP              4
                #endif
            #endif
        #endif
    #endif  /*__VE_H264_DEC_SW_SUPPORT__*/

    #ifdef __VE_RV_DEC_SW_SUPPORT__
        #ifdef __VE_RM_DEC_SW_SLIM__
            #define RV9_EXTRA_BUFFER_NUM            0
        #elif defined (__VE_SW_VIDEO_MAX_RESOLUTION__)
            #define RV9_EXTRA_BUFFER_NUM            0
        #else
            #define RV9_EXTRA_BUFFER_NUM            0
        #endif
    #endif  // __VE_RV_DEC_SW_SUPPORT__

    #ifdef __VE_MJPEG_DEC_SW_SUPPORT__
        #define MJPEG_EXTRA_BUFFER_NUM            0
    #endif

    #ifdef __VE_VP8_DEC_SW_SUPPORT__
        #ifdef __VE_SW_VIDEO_MAX_RESOLUTION__
            #define VP8_EXTRA_BUFFER_NUM                 0
        #else
            #define VP8_EXTRA_BUFFER_NUM                 0
        #endif
    #endif  // __VE_VP8_DEC_SW_SUPPORT__

    #ifdef __VE_MPEG4_ENC_SW_SUPPORT__
        #ifdef __VE_MED_VIDEO_ULC__
            #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM           1
            #define MPEG4_ENC_BIT_BUFFER_SIZE               (131072)
        #else
            #ifdef __VE_MPEG4_ENC_SW_SLIM__
                #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       1
                #define MPEG4_ENC_BIT_BUFFER_SIZE           (163840)
            #else
                #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       1
                #define MPEG4_ENC_BIT_BUFFER_SIZE           (163840)
            #endif
        #endif
    #endif  // __VE_MPEG4_ENC_SW_SUPPORT__

    #ifdef __VE_MJPEG_ENC_SUPPORT__
        #ifdef __VE_MED_VIDEO_ULC__
            #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM           (0)
            #define MJPEG_ENC_BIT_BUFFER_SIZE               (79200)
        #else
            #ifdef __VE_MJPEG_ENC_SW_SLIM__
                #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM       (0)
                #define MJPEG_ENC_BIT_BUFFER_SIZE           (171360) //(79200 + 92160)
            #else
                #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM       (0)
                #define MJPEG_ENC_BIT_BUFFER_SIZE           (171360) //(79200 + 92160)
            #endif
        #endif
    #endif //__VE_MJPEG_ENC_SUPPORT__
#endif  // __VIDEO_V2_MT6261_SERIES__

/******************************************************************************
* Setting for VT scenario
******************************************************************************/
#ifdef __VE_VIDEO_VT_SUPPORT__
    //decoder
    #define MPEG4_VT_BUFFER_NUM            6

    //encoder
    #define MPEG4_ENC_VT_EXTRA_YUV_BUFFER_NUM            2
#endif //__VE_VIDEO_VT_SUPPORT__

/******************************************************************************
* Setting for QVGA scenario
******************************************************************************/
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #define MPEG4_QVGA_EXTRA_BUFFER_NUM 1
    #else
        #define MPEG4_QVGA_EXTRA_BUFFER_NUM 0
    #endif
#endif /* __VE_MPEG4_DEC_SW_SUPPORT__ */

#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #define H264_QVGA_EXTRA_BUFFER_NUM 8 // 3-->8 for compatibility of CMMB and QVGA (level 1.1 to 1.2)
#endif /* __VE_H264_DEC_SW_SUPPORT__ */

#ifdef __VE_RV_DEC_SW_SUPPORT__
    #define RV9_QVGA_EXTRA_BUFFER_NUM 0
#endif /* __VE_RV_DEC_SW_SUPPORT__ */

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_QVGA_EXTRA_BUFFER_NUM 0
#endif /* __VE_MJPEG_DEC_SW_SUPPORT__ */

#ifdef __VE_VP8_DEC_SW_SUPPORT__
    #define VP8_QVGA_EXTRA_BUFFER_NUM 0
#endif /* __VE_VP8_DEC_SW_SUPPORT__ */


/******************************************************************************
* Setting for QVGAMPEG4SP scenario
******************************************************************************/
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #define MPEG4_QVGAMPEG4SP_EXTRA_BUFFER_NUM 0
#endif /* __VE_MPEG4_DEC_SW_SUPPORT__ */


/******************************************************************************
* Setting for UPTO-QVGA scenario
******************************************************************************/
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #define MPEG4_UPTOQVGA_EXTRA_BUFFER_NUM 1
    #else
        #define MPEG4_UPTOQVGA_EXTRA_BUFFER_NUM 0
    #endif
#endif /* __VE_MPEG4_DEC_SW_SUPPORT__ */

#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #if !defined(H264_DEC_MAX_WIDTH_BP) || !defined(H264_DEC_MAX_HEIGHT_BP)
    #error "H264_DEC_MAX_WIDTH_BP and/or H264_DEC_MAX_HEIGHT_BP are not defined"
    #endif  // !defined(H264_DEC_MAX_WIDTH_BP) || !defined(H264_DEC_MAX_HEIGHT_BP)
    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        #if !defined(H264_DEC_MAX_WIDTH_MPHP) || !defined(H264_DEC_MAX_HEIGHT_MPHP)
        #error "H264_DEC_MAX_WIDTH_MPHP and/or H264_DEC_MAX_HEIGHT_MPHP are not defined"
        #endif  // !defined(H264_DEC_MAX_WIDTH_MPHP) || !defined(H264_DEC_MAX_HEIGHT_MPHP)
        #if (H264_DEC_MAX_WIDTH_BP * H264_DEC_MAX_HEIGHT_BP > H264_DEC_MAX_WIDTH_MPHP * H264_DEC_MAX_HEIGHT_MPHP)
            #if (320 * 240 > H264_DEC_MAX_WIDTH_BP * H264_DEC_MAX_HEIGHT_BP)
                #define H264_UPTOQVGA_EXTRA_BUFFER_NUM (H264_EXTRA_BUFFER_NUM_BP)
            #else
                #define H264_UPTOQVGA_EXTRA_BUFFER_NUM 3
            #endif
        #else // (H264_DEC_MAX_WIDTH_BP*H264_DEC_MAX_HEIGHT_BP > H264_DEC_MAX_WIDTH_MPHP*H264_DEC_MAX_HEIGHT_MPHP)
            #if (320 * 240 > H264_DEC_MAX_WIDTH_MPHP * H264_DEC_MAX_HEIGHT_MPHP)
                #define H264_UPTOQVGA_EXTRA_BUFFER_NUM (H264_EXTRA_BUFFER_NUM_MPHP)
            #else
                #define H264_UPTOQVGA_EXTRA_BUFFER_NUM 3
            #endif
        #endif
    #else // __H264_DEC_SW_SUPPORT_MAINHIGH__
        #if (320 * 240 > H264_DEC_MAX_WIDTH_BP * H264_DEC_MAX_HEIGHT_BP)
                #define H264_UPTOQVGA_EXTRA_BUFFER_NUM (H264_EXTRA_BUFFER_NUM_BP)
            #else
                #define H264_UPTOQVGA_EXTRA_BUFFER_NUM 3
        #endif
    #endif
#endif /* __VE_H264_DEC_SW_SUPPORT__ */

#ifdef __VE_RV_DEC_SW_SUPPORT__
    #define RV9_UPTOQVGA_EXTRA_BUFFER_NUM 0
#endif /* __VE_RV_DEC_SW_SUPPORT__ */

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_UPTOQVGA_EXTRA_BUFFER_NUM 0
#endif /* __VE_MJPEG_DEC_SW_SUPPORT__ */

#ifdef __VE_VP8_DEC_SW_SUPPORT__
    #define VP8_UPTOQVGA_EXTRA_BUFFER_NUM 0
#endif /* __VE_VP8_DEC_SW_SUPPORT__ */



/******************************************************************************
* Setting for QCIF scenario
******************************************************************************/
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #define MPEG4_QCIF_EXTRA_BUFFER_NUM 1
    #else
        #define MPEG4_QCIF_EXTRA_BUFFER_NUM 0
    #endif
#endif /* __VE_MPEG4_DEC_SW_SUPPORT__ */

#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #define H264_QCIF_EXTRA_BUFFER_NUM 4
#endif /* __VE_H264_DEC_SW_SUPPORT__ */

#ifdef __VE_RV_DEC_SW_SUPPORT__
    #define RV9_QCIF_EXTRA_BUFFER_NUM 0
#endif /* __VE_RV_DEC_SW_SUPPORT__ */

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_QCIF_EXTRA_BUFFER_NUM 0
#endif /* __VE_MJPEG_DEC_SW_SUPPORT__ */

#ifdef __VE_VP8_DEC_SW_SUPPORT__
    #define VP8_QCIF_EXTRA_BUFFER_NUM 0
#endif /* __VE_VP8_DEC_SW_SUPPORT__ */

/******************************************************************************
* Setting for VGA scenario
******************************************************************************/
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #define MPEG4_VGA_EXTRA_BUFFER_NUM 1
    #else
        #define MPEG4_VGA_EXTRA_BUFFER_NUM 0
    #endif
#endif /* __VE_MPEG4_DEC_SW_SUPPORT__ */

#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #define H264_VGA_EXTRA_BUFFER_NUM 7
#endif /* __VE_H264_DEC_SW_SUPPORT__ */

#ifdef __VE_RV_DEC_SW_SUPPORT__
    #define RV9_VGA_EXTRA_BUFFER_NUM 0
#endif /* __VE_RV_DEC_SW_SUPPORT__ */

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_VGA_EXTRA_BUFFER_NUM 0
#endif /* __VE_MJPEG_DEC_SW_SUPPORT__ */

#ifdef __VE_VP8_DEC_SW_SUPPORT__
    #define VP8_VGA_EXTRA_BUFFER_NUM 0
#endif /* __VE_VP8_DEC_SW_SUPPORT__ */

/******************************************************************************
* Setting for CIF scenario
******************************************************************************/
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #define MPEG4_CIF_EXTRA_BUFFER_NUM 1
    #else
        #define MPEG4_CIF_EXTRA_BUFFER_NUM 0
    #endif
#endif /* __VE_MPEG4_DEC_SW_SUPPORT__ */

#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #define H264_CIF_EXTRA_BUFFER_NUM 3
#endif /* __VE_H264_DEC_SW_SUPPORT__ */

#ifdef __VE_RV_DEC_SW_SUPPORT__
    #define RV9_CIF_EXTRA_BUFFER_NUM 0
#endif /* __VE_RV_DEC_SW_SUPPORT__ */

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_CIF_EXTRA_BUFFER_NUM 0
#endif /* __VE_MJPEG_DEC_SW_SUPPORT__ */

#ifdef __VE_VP8_DEC_SW_SUPPORT__
    #define VP8_CIF_EXTRA_BUFFER_NUM 0
#endif /* __VE_VP8_DEC_SW_SUPPORT__ */

/******************************************************************************
* Setting for UPTOCIF scenario
******************************************************************************/
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #define MPEG4_UPTOCIF_EXTRA_BUFFER_NUM 1
    #else
        #define MPEG4_UPTOCIF_EXTRA_BUFFER_NUM 0
    #endif
#endif /* __VE_MPEG4_DEC_SW_SUPPORT__ */

#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #if !defined(H264_DEC_MAX_WIDTH_BP) || !defined(H264_DEC_MAX_HEIGHT_BP)
    #error "H264_DEC_MAX_WIDTH_BP and/or H264_DEC_MAX_HEIGHT_BP are not defined"
    #endif  // !defined(H264_DEC_MAX_WIDTH_BP) || !defined(H264_DEC_MAX_HEIGHT_BP)
    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        #if !defined(H264_DEC_MAX_WIDTH_MPHP) || !defined(H264_DEC_MAX_HEIGHT_MPHP)
        #error "H264_DEC_MAX_WIDTH_MPHP and/or H264_DEC_MAX_HEIGHT_MPHP are not defined"
        #endif  // !defined(H264_DEC_MAX_WIDTH_MPHP) || !defined(H264_DEC_MAX_HEIGHT_MPHP)
        #if (H264_DEC_MAX_WIDTH_BP * H264_DEC_MAX_HEIGHT_BP > H264_DEC_MAX_WIDTH_MPHP * H264_DEC_MAX_HEIGHT_MPHP)
            #if (352 * 288 > H264_DEC_MAX_WIDTH_BP * H264_DEC_MAX_HEIGHT_BP)
                #define H264_UPTOCIF_EXTRA_BUFFER_NUM (H264_EXTRA_BUFFER_NUM_BP)
            #else
                #define H264_UPTOCIF_EXTRA_BUFFER_NUM 3
            #endif
        #else // (H264_DEC_MAX_WIDTH_BP*H264_DEC_MAX_HEIGHT_BP > H264_DEC_MAX_WIDTH_MPHP*H264_DEC_MAX_HEIGHT_MPHP)
            #if (352 * 288 > H264_DEC_MAX_WIDTH_MPHP * H264_DEC_MAX_HEIGHT_MPHP)
                #define H264_UPTOCIF_EXTRA_BUFFER_NUM (H264_EXTRA_BUFFER_NUM_MPHP)
            #else
                #define H264_UPTOCIF_EXTRA_BUFFER_NUM 3
            #endif
        #endif
    #else // __H264_DEC_SW_SUPPORT_MAINHIGH__
        #if (352 * 288 > H264_DEC_MAX_WIDTH_BP * H264_DEC_MAX_HEIGHT_BP)
                #define H264_UPTOCIF_EXTRA_BUFFER_NUM (H264_EXTRA_BUFFER_NUM_BP)
            #else
                #define H264_UPTOCIF_EXTRA_BUFFER_NUM 3
        #endif
    #endif
#endif /* __VE_H264_DEC_SW_SUPPORT__ */

#ifdef __VE_RV_DEC_SW_SUPPORT__
    #define RV9_UPTOCIF_EXTRA_BUFFER_NUM 0
#endif /* __VE_RV_DEC_SW_SUPPORT__ */

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_UPTOCIF_EXTRA_BUFFER_NUM 0
#endif /* __VE_MJPEG_DEC_SW_SUPPORT__ */

#ifdef __VE_VP8_DEC_SW_SUPPORT__
    #define VP8_UPTOCIF_EXTRA_BUFFER_NUM 0
#endif /* __VE_VP8_DEC_SW_SUPPORT__ */


// preview
/******************************************************************************
* Setting for PREVIEW scenario
******************************************************************************/
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #define MPEG4_PREVIEW_EXTRA_BUFFER_NUM 0
#endif /* __VE_MPEG4_DEC_SW_SUPPORT__ */

#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #define H264_PREVIEW_EXTRA_BUFFER_NUM 0
#endif /* __VE_H264_DEC_SW_SUPPORT__ */

#ifdef __VE_RV_DEC_SW_SUPPORT__
    #define RV9_PREVIEW_EXTRA_BUFFER_NUM 0
#endif /* __VE_RV_DEC_SW_SUPPORT__ */

#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_PREVIEW_EXTRA_BUFFER_NUM 0
#endif /* __VE_MJPEG_DEC_SW_SUPPORT__ */

#ifdef __VE_VP8_DEC_SW_SUPPORT__
    #define VP8_PREVIEW_EXTRA_BUFFER_NUM 0
#endif /* __VE_VP8_DEC_SW_SUPPORT__ */


/******************************************************************************
* Replace with custom setting
******************************************************************************/
// MPEG4 decode
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
    #ifdef MPEG4_DEC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef MPEG4_CUSTOM_EXTRA_BUFFER_NUM_SP
            #undef MPEG4_EXTRA_BUFFER_NUM_SP
            #define MPEG4_EXTRA_BUFFER_NUM_SP (MPEG4_CUSTOM_EXTRA_BUFFER_NUM_SP)
        #endif
        #ifdef MPEG4_CUSTOM_EXTRA_BUFFER_NUM_ASP
            #undef MPEG4_EXTRA_BUFFER_NUM_ASP
            #define MPEG4_EXTRA_BUFFER_NUM_ASP (MPEG4_CUSTOM_EXTRA_BUFFER_NUM_ASP)
        #endif
    #endif /* MPEG4_DEC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /* __VE_MPEG4_DEC_SW_SUPPORT__ */

// H264 decode
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
    #ifdef H264_DEC_CUSTOM_FRAME_SETTING_ENABLE
        #if defined(H264_CUSTOM_EXTRA_BUFFER_NUM_BP)
            #undef H264_EXTRA_BUFFER_NUM_BP
            #define H264_EXTRA_BUFFER_NUM_BP (H264_CUSTOM_EXTRA_BUFFER_NUM_BP)
        #endif
        #if defined(H264_CUSTOM_EXTRA_BUFFER_NUM_MPHP)
            #undef H264_EXTRA_BUFFER_NUM_MPHP
            #define H264_EXTRA_BUFFER_NUM_MPHP (H264_CUSTOM_EXTRA_BUFFER_NUM_MPHP)
        #endif
    #endif /* H264_DEC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /* __VE_H264_DEC_SW_SUPPORT__ */

// RM decode
#ifdef __VE_RV_DEC_SW_SUPPORT__
    #ifdef RV_DEC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef RV_CUSTOM_EXTRA_BUFFER_NUM
            #undef RV9_EXTRA_BUFFER_NUM
            #define RV9_EXTRA_BUFFER_NUM (RV_CUSTOM_EXTRA_BUFFER_NUM)
        #endif
    #endif /* RV_DEC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /* __VE_RV_DEC_SW_SUPPORT__ */

// Motion Jpeg Decode
#ifdef __VE_MJPEG_DEC_SW_SUPPORT__
    #ifdef MJPEG_DEC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef MJPEG_CUSTOM_EXTRA_BUFFER_NUM
            #undef MJPEG_EXTRA_BUFFER_NUM
            #define MJPEG_EXTRA_BUFFER_NUM (MJPEG_CUSTOM_EXTRA_BUFFER_NUM)
        #endif
    #endif /* MJPEG_DEC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /* __VE_MJPEG_DEC_SW_SUPPORT__ */


// VP8 decode
#ifdef __VE_VP8_DEC_SW_SUPPORT__
    #ifdef VP8_DEC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef VP8_CUSTOM_EXTRA_BUFFER_NUM
            #undef VP8_EXTRA_BUFFER_NUM
            #define VP8_EXTRA_BUFFER_NUM (VP8_CUSTOM_EXTRA_BUFFER_NUM)
        #endif
    #endif /* VP8_DEC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /* __VE_VP8_DEC_SW_SUPPORT__ */


// MPEG4 HW encode
#ifdef __VE_MPEG4_ENC_HW_SUPPORT__
    #ifdef MPEG4_HW_ENC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef MPEG4_HW_ENC_CUSTOM_EXTRA_YUV_FRAME_NUM
            #undef MPEG4_HW_ENC_EXTRA_YUV_FRAME_NUM
            #define MPEG4_HW_ENC_EXTRA_YUV_FRAME_NUM (MPEG4_HW_ENC_CUSTOM_EXTRA_YUV_FRAME_NUM)
        #endif
        #ifdef MPEG4_HW_ENC_CUSTOM_BIT_BUFFER_SIZE
            #undef MPEG4_HW_ENC_BIT_BUFFER_SIZE
            #define MPEG4_HW_ENC_BIT_BUFFER_SIZE (MPEG4_HW_ENC_CUSTOM_BIT_BUFFER_SIZE)
        #endif
    #endif /* MPEG4_HW_ENC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /*__VE_MPEG4_ENC_HW_SUPPORT__*/


// MPEG4 SW encode
#ifdef __VE_MPEG4_ENC_SW_SUPPORT__
    #ifdef MPEG4_ENC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef MPEG4_ENC_CUSTOM_EXTRA_YUV_FRAME_NUM
            #undef MPEG4_ENC_EXTRA_YUV_FRAME_NUM
            #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM (MPEG4_ENC_CUSTOM_EXTRA_YUV_FRAME_NUM)
        #endif
        #ifdef MPEG4_ENC_CUSTOM_BIT_BUFFER_SIZE
            #undef MPEG4_ENC_BIT_BUFFER_SIZE
            #define MPEG4_ENC_BIT_BUFFER_SIZE (MPEG4_ENC_CUSTOM_BIT_BUFFER_SIZE)
        #endif
    #endif /* MPEG4_ENC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /*__VE_MPEG4_ENC_SW_SUPPORT__*/

// MJPEG encode
#ifdef __VE_MJPEG_ENC_SUPPORT__
    #ifdef MJPEG_ENC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef MJPEG_ENC_CUSTOM_EXTRA_YUV_FRAME_NUM
            #undef MJPEG_ENC_EXTRA_YUV_FRAME_NUM
            #define MJPEG_ENC_EXTRA_YUV_FRAME_NUM (MJPEG_ENC_CUSTOM_EXTRA_YUV_FRAME_NUM)
        #endif
        #ifdef MJPEG_ENC_CUSTOM_BIT_BUFFER_SIZE
            #undef MJPEG_ENC_BIT_BUFFER_SIZE
            #define MJPEG_ENC_BIT_BUFFER_SIZE (MJPEG_ENC_CUSTOM_BIT_BUFFER_SIZE)
        #endif
    #endif /* MJPEG_ENC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /*__VE_MJPEG_ENC_SUPPORT__*/

#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* VIDEO_CODEC_MEM_CUSTOM_V2_H */

