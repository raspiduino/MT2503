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
 *   sw_video_decode_custom.h
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "drv_comm.h"
#ifdef __VIDEO_ARCHI_V2__
#include "drv_features_video.h"
#include "video_codec_custom_type.h"
#include "hal_custom_video_if.h"

//#ifdef __MPEG4_DEC_SW_SUPPORT__
#include "MP4SwDecMem.h"
//#endif

//#ifdef __H264_DEC_SW_SUPPORT__
#include "H264SwDecMem.h"
//#endif

#ifdef __RV_DEC_SW_SUPPORT__
#include "RVSwDecMem.h"
#endif

//#ifdef __VP8_DEC_SW_SUPPORT__
#include "VP8SwDecMem.h"
//#endif

#ifdef __MJPEG_DEC_SW_SUPPORT__
#include "jpeg_mjpeg_mem.h"
#endif

#if defined(MT6255)
   #include "custom_emi_release.h"
#endif

#endif //__VIDEO_ARCHI_V2__

#ifndef SW_VIDEO_DECODE_CUSTOM_H
#define SW_VIDEO_DECODE_CUSTOM_H

#ifdef __VIDEO_ARCHI_V2__

#if (!defined(MT6268))
/***********************************************************************
*
*   Custom settings of
*   - The numbers of frame buffer
*   - Maximum resolution supported
*
***********************************************************************/


/******************************************************************************
* [ SP ]
* 1:1 -> MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP
* 1:2 -> MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP
* 1:4 -> MPEG4_SUPPORT_RESOLUTION_SP
* 1:8 -> MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP
*
* [ ASP ]
* 1:1 -> MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP
* 1:2 -> MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP
* 1:4 -> MPEG4_SUPPORT_RESOLUTION_ASP
* 1:8 -> MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP
******************************************************************************/


/******************************************************************************
* Setting for MT6236 series
******************************************************************************/
#if (defined(MT6236) || defined(MT6236B))
    #if defined(MT6921)
        //#ifdef __MPEG4_DEC_SW_SUPPORT__
            #if defined(__OP01__)
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP RESOLUTION_176x144
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP  RESOLUTION_176x144
                #define MPEG4_SUPPORT_RESOLUTION_SP         RESOLUTION_176x144
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP  RESOLUTION_176x144
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP RESOLUTION_352x288
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP  RESOLUTION_352x288
                #define MPEG4_SUPPORT_RESOLUTION_SP         RESOLUTION_352x288
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP  RESOLUTION_352x288
            #endif
            #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_352x288
            //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_352x288
            #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_352x288
            #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_352x288
        //#endif // __MPEG4_DEC_SW_SUPPORT__

        //#ifdef __H264_DEC_SW_SUPPORT__
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_176x144
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_176x144
            #define H264_DECODER_LEVEL_BP                   Level_10
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_176x144
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_176x144
            #define H264_DECODER_LEVEL_MPHP                 Level_10
        //#endif //__H264_DEC_SW_SUPPORT__

        #ifdef __RV_DEC_SW_SUPPORT__
            #ifdef __SW_VIDEO_MAX_RESOLUTION__
                #define RV9_SUPPORT_RESOLUTION              RESOLUTION_352x288
                #define RV9_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_352x288
            #else
                #define RV9_SUPPORT_RESOLUTION              RESOLUTION_176x144
                #define RV9_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_176x144
            #endif
        #endif //__RV_DEC_SW_SUPPORT__

        //#ifdef __VP8_DEC_SW_SUPPORT__
            #ifdef __SW_VIDEO_MAX_RESOLUTION__
                #define VP8_SUPPORT_RESOLUTION               RESOLUTION_1920x1088
                #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_1280x720
                #define VP8_PADDING_SIZE                     64
            #else
                #define VP8_SUPPORT_RESOLUTION               RESOLUTION_1280x720
                #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_640x480
                #define VP8_PADDING_SIZE                     64
            #endif
        //#endif //__VP8_DEC_SW_SUPPORT__

    #else
        //#ifdef __MPEG4_DEC_SW_SUPPORT__
            #ifdef __SW_VIDEO_MAX_RESOLUTION__
                #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_640x480
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_1280x720
                    #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_1920x1088
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1920x1088
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_640x480
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_1280x720
                    #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1920x1088
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1920x1088
                #else
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_1920x1088
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_1920x1088
                    #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_1920x1088
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1920x1088
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_1920x1088
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_1920x1088
                    #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1920x1088
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1920x1088
                #endif
            #else
                #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_640x480
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_720x576
                    #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_1280x720
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1920x1088
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_640x480
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_720x576
                    #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1280x720
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1920x1088
                #else
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_480x320
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                    #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_480x320
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_480x320
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_480x320
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                    #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_480x320
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_480x320
                #endif
            #endif
        //#endif /*__MPEG4_DEC_SW_SUPPORT__*/

        //#ifdef __H264_DEC_SW_SUPPORT__
            #ifdef __H264_DEC_SW_SLIM__
                #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                    #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_480x320
                    #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_480x320
                    #define H264_DECODER_LEVEL_BP                Level_21
                    #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_480x320
                    #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_480x320
                    #define H264_DECODER_LEVEL_MPHP              Level_21
                #else
                    #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_480x320
                    #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_480x320
                    #define H264_DECODER_LEVEL_BP                Level_21
                    #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_480x320
                    #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_480x320
                    #define H264_DECODER_LEVEL_MPHP              Level_21
                #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
            #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
                #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                    #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_1920x1088
                    #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_1920x1088
                    #define H264_DECODER_LEVEL_BP                Level_40
                    #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_1920x1088
                    #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_1920x1088
                    #define H264_DECODER_LEVEL_MPHP              Level_40
                #else
                    #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_1920x1088
                    #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_1920x1088
                    #define H264_DECODER_LEVEL_BP                Level_40
                    #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_1920x1088
                    #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_1920x1088
                    #define H264_DECODER_LEVEL_MPHP              Level_40
                #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
            #else
                #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                    #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_480x320
                    #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_480x320
                    #define H264_DECODER_LEVEL_BP                Level_21
                    #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_864x480
                    #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_480x320
                    #define H264_DECODER_LEVEL_MPHP              Level_21
                #else
                    #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_320x240
                    #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_320x240
                    #define H264_DECODER_LEVEL_BP                Level_20
                    #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_320x240
                    #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_320x240
                    #define H264_DECODER_LEVEL_MPHP              Level_20
                #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
            #endif /* __SW_VIDEO_MAX_RESOLUTION__ */
        //#endif  // __H264_DEC_SW_SUPPORT__

        #ifdef __RV_DEC_SW_SUPPORT__
            #ifdef __SW_VIDEO_MAX_RESOLUTION__
                #define RV9_SUPPORT_RESOLUTION               RESOLUTION_1920x1088
                #define RV9_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_848x480
            #else
                #define RV9_SUPPORT_RESOLUTION               RESOLUTION_848x480
                #define RV9_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_848x480
            #endif
        #endif  // __RV_DEC_SW_SUPPORT__

        #ifdef __MJPEG_DEC_SW_SUPPORT__
            #define MJPEG_SUPPORT_RESOLUTION          RESOLUTION_480x320
            #define MJPEG_MAX_QTY_MODE_RESOLUTION     RESOLUTION_480x320
            #define MJPEG_MAX_NORMAL_MODE_RESOLUTION  RESOLUTION_480x320
        #endif  // __MJPEG_DEC_SW_SUPPORT__

        //#ifdef __VP8_DEC_SW_SUPPORT__
            #ifdef __SW_VIDEO_MAX_RESOLUTION__
                #define VP8_SUPPORT_RESOLUTION               RESOLUTION_1920x1088
                #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_1280x720
                #define VP8_PADDING_SIZE                     64
            #else
                #define VP8_SUPPORT_RESOLUTION               RESOLUTION_1280x720
                #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_640x480
                #define VP8_PADDING_SIZE                     64
            #endif
        //#endif //__VP8_DEC_SW_SUPPORT__

    #endif // defined(MT6921)
#endif  // (defined(MT6236) || defined(MT6236B))


/******************************************************************************
* Setting for MT6253 series
******************************************************************************/
#if (defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6253T) )
    //#ifdef __MPEG4_DEC_SW_SUPPORT__
        #ifdef __MP4_DEC_SW_SLIM__
            #if defined (__MED_VIDEO_ULC__) && defined(__MPEG4_QCIF_TO_CIF__)
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_176x144
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_176x144
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_352x288
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_352x288
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_176x144
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_176x144
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_352x288
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_352x288
            #elif defined (__MED_VIDEO_ULC__)
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_320x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_480x320
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_320x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_480x320
            #else
                #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_352x288
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                    #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_720x480
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_720x576
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_352x288
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                    #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_720x480
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_720x576
                #else
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_352x288
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_352x288
                    #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_352x288
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_352x288
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_352x288
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_352x288
                    #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_352x288
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_352x288
                #endif  // VIDEO_SW_MP4_LOSSY_SUPPORT
            #endif  // defined (__MED_VIDEO_ULC__) && defined(__MPEG4_QCIF_TO_CIF__)
        #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_864x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_864x480
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_864x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_864x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_848x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_848x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_864x480
            #endif
        #else
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_720x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_864x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_720x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_864x480
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_432x240
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_432x240
            #endif
        #endif
    //#endif /*__MPEG4_DEC_SW_SUPPORT__*/

    //#ifdef __H264_DEC_SW_SUPPORT__
        #ifdef __H264_DEC_SW_SLIM__
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_176x144
                #define H264_DECODER_LEVEL_BP                   Level_10
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_176x144
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_176x144
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_176x144
                #define H264_DECODER_LEVEL_MPHP                 Level_10
            #else
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_176x144
                #define H264_DECODER_LEVEL_BP                   Level_10
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_176x144
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_176x144
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_176x144
                #define H264_DECODER_LEVEL_MPHP                 Level_10
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_864x480
                #define H264_DECODER_LEVEL_BP                   Level_21
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_320x240
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_864x480
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_320x240
                #define H264_DECODER_LEVEL_MPHP                 Level_21
            #else
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_864x480
                #define H264_DECODER_LEVEL_BP                   Level_22
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_864x480
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_864x480
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_864x480
                #define H264_DECODER_LEVEL_MPHP                 Level_22
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #else
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_320x240
                #define H264_DECODER_LEVEL_BP                   Level_11
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_320x240
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_320x240
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_320x240
                #define H264_DECODER_LEVEL_MPHP                 Level_11
            #else
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_176x144
                #define H264_DECODER_LEVEL_BP                   Level_10
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_176x144
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_176x144
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_176x144
                #define H264_DECODER_LEVEL_MPHP                 Level_10
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #endif
    //#endif  /*__H264_DEC_SW_SUPPORT__*/

    #ifdef __RV_DEC_SW_SUPPORT__
        #ifdef __RM_DEC_SW_SLIM__
            #define RV9_SUPPORT_RESOLUTION          RESOLUTION_176x144
            #define RV9_MAX_NORMAL_MODE_RESOLUTION  RESOLUTION_176x144
        #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
            #define RV9_SUPPORT_RESOLUTION          RESOLUTION_800x608
            #define RV9_MAX_NORMAL_MODE_RESOLUTION  RESOLUTION_640x368
        #else
            #define RV9_SUPPORT_RESOLUTION          RESOLUTION_848x480
            #define RV9_MAX_NORMAL_MODE_RESOLUTION  RESOLUTION_320x240
        #endif
    #endif  // __RV_DEC_SW_SUPPORT__

    #ifdef __MJPEG_DEC_SW_SUPPORT__
        #define MJPEG_SUPPORT_RESOLUTION          RESOLUTION_352x288
        #define MJPEG_MAX_QTY_MODE_RESOLUTION     RESOLUTION_352x288
        #define MJPEG_MAX_NORMAL_MODE_RESOLUTION  RESOLUTION_352x288
    #endif  // __MJPEG_DEC_SW_SUPPORT__

    //#ifdef __VP8_DEC_SW_SUPPORT__
        #ifdef __SW_VIDEO_MAX_RESOLUTION__
            #define VP8_SUPPORT_RESOLUTION               RESOLUTION_176x144
            #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_176x144
            #define VP8_PADDING_SIZE                     64
        #else
            #define VP8_SUPPORT_RESOLUTION               RESOLUTION_176x144
            #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_176x144
            #define VP8_PADDING_SIZE                     64
        #endif
    //#endif //__VP8_DEC_SW_SUPPORT__
#endif  // (defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6253T) )


/******************************************************************************
* Setting for MT6252 series
******************************************************************************/
#if (defined(MT6252) || defined(MT6252H))
    //#ifdef __MPEG4_DEC_SW_SUPPORT__
        #ifdef __MP4_DEC_SW_SLIM__
            #if defined (__MED_VIDEO_ULC__) && defined(__MPEG4_QCIF_TO_CIF__)
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP         RESOLUTION_176x144
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP          RESOLUTION_176x144
                #define MPEG4_SUPPORT_RESOLUTION_SP                 RESOLUTION_352x288
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP          RESOLUTION_352x288
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP        RESOLUTION_176x144
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP         RESOLUTION_176x144
                #define MPEG4_SUPPORT_RESOLUTION_ASP                RESOLUTION_352x288
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP         RESOLUTION_352x288
            #elif defined (__MED_VIDEO_ULC__)
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP         RESOLUTION_320x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP          RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_SP                 RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP          RESOLUTION_480x320
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP        RESOLUTION_320x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP         RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_ASP                RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP         RESOLUTION_480x320
            #else
                #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_352x288
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                    #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_720x480
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_864x480
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_352x288
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                    #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_720x480
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_864x480
                #else
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_352x288
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_352x288
                    #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_352x288
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_352x288
                    #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_352x288
                    //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_352x288
                    #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_352x288
                    #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_352x288
                #endif  // VIDEO_SW_MP4_LOSSY_SUPPORT
            #endif  // defined (__MED_VIDEO_ULC__) && defined(__MPEG4_QCIF_TO_CIF__)
        #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_864x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_864x480
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_864x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_864x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_864x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_864x480
            #endif  // VIDEO_SW_MP4_LOSSY_SUPPORT
        #else
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_720x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_864x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_720x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_864x480
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_432x240
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_432x240
            #endif  // VIDEO_SW_MP4_LOSSY_SUPPORT
        #endif  // __MP4_DEC_SW_SLIM__
    //#endif /*__MPEG4_DEC_SW_SUPPORT__*/

    //#ifdef __H264_DEC_SW_SUPPORT__
        #ifdef __H264_DEC_SW_SLIM__
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_176x144
                #define H264_DECODER_LEVEL_BP                   Level_10
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_176x144
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_176x144
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_176x144
                #define H264_DECODER_LEVEL_MPHP                 Level_10
            #else
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_176x144
                #define H264_DECODER_LEVEL_BP                   Level_10
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_176x144
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_176x144
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_176x144
                #define H264_DECODER_LEVEL_MPHP                 Level_10
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_864x480
                #define H264_DECODER_LEVEL_BP                   Level_21
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_320x240
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_864x480
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_320x240
                #define H264_DECODER_LEVEL_MPHP                 Level_21
            #else
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_864x480
                #define H264_DECODER_LEVEL_BP                   Level_22
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_864x480
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_864x480
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_864x480
                #define H264_DECODER_LEVEL_MPHP                 Level_22
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #else
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_240x192
                #define H264_DECODER_LEVEL_BP                   Level_11
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_240x192
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_240x192
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_240x192
                #define H264_DECODER_LEVEL_MPHP                 Level_11
            #else
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_176x144
                #define H264_DECODER_LEVEL_BP                   Level_10
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_176x144
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_176x144
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_176x144
                #define H264_DECODER_LEVEL_MPHP                 Level_10
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #endif  // __H264_DEC_SW_SLIM__
    //#endif  /*__H264_DEC_SW_SUPPORT__*/

    #ifdef __RV_DEC_SW_SUPPORT__
        #ifdef __RM_DEC_SW_SLIM__
            #define RV9_SUPPORT_RESOLUTION              RESOLUTION_176x144
            #define RV9_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_176x144
        #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
            #define RV9_SUPPORT_RESOLUTION              RESOLUTION_800x608
            #define RV9_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_640x368
        #else
            #define RV9_SUPPORT_RESOLUTION              RESOLUTION_848x480
            #define RV9_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_320x240
        #endif  // __RM_DEC_SW_SLIM__
    #endif  // __RV_DEC_SW_SUPPORT__

    #ifdef __MJPEG_DEC_SW_SUPPORT__
        #define MJPEG_SUPPORT_RESOLUTION                RESOLUTION_352x288
        #define MJPEG_MAX_QTY_MODE_RESOLUTION           RESOLUTION_352x288
        #define MJPEG_MAX_NORMAL_MODE_RESOLUTION        RESOLUTION_352x288
    #endif  // __MJPEG_DEC_SW_SUPPORT__

    //#ifdef __VP8_DEC_SW_SUPPORT__
        #ifdef __SW_VIDEO_MAX_RESOLUTION__
            #define VP8_SUPPORT_RESOLUTION              RESOLUTION_176x144
            #define VP8_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_176x144
            #define VP8_PADDING_SIZE                    64
        #else
            #define VP8_SUPPORT_RESOLUTION              RESOLUTION_176x144
            #define VP8_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_176x144
            #define VP8_PADDING_SIZE                    64
        #endif  // __SW_VIDEO_MAX_RESOLUTION__
    //#endif //__VP8_DEC_SW_SUPPORT__
#endif  // defined(MT6252) || defined(MT6252H))


/******************************************************************************
* Setting for MT6256 series
******************************************************************************/
#if (defined(MT6256))
    //#ifdef __MPEG4_DEC_SW_SUPPORT__
        #ifdef __MP4_DEC_SW_SLIM__
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_800x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1920x1088
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_800x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1920x1088
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_800x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_800x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_800x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_800x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_800x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_800x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_800x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_800x480
            #endif  // VIDEO_SW_MP4_LOSSY_SUPPORT
        #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_864x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1920x1088
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_864x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1920x1088
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_1920x1088
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1920x1088
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_1920x1088
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1920x1088
            #endif  // VIDEO_SW_MP4_LOSSY_SUPPORT
        #else
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_864x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1920x1088
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_864x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1920x1088
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_864x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_864x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_1280x720
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1280x720
            #endif  // VIDEO_SW_MP4_LOSSY_SUPPORT
        #endif  // __MP4_DEC_SW_SLIM__
    //#endif /*__MPEG4_DEC_SW_SUPPORT__*/

    //#ifdef __H264_DEC_SW_SUPPORT__
        #ifdef __H264_DEC_SW_SLIM__
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_480x320
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_480x320
                #define H264_DECODER_LEVEL_BP                   Level_21
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_480x320
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_480x320
                #define H264_DECODER_LEVEL_MPHP                 Level_21
            #else
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_480x320
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_480x320
                #define H264_DECODER_LEVEL_BP                   Level_21
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_480x320
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_480x320
                #define H264_DECODER_LEVEL_MPHP                 Level_21
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_1920x1088
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_864x480
                #define H264_DECODER_LEVEL_BP                   Level_31
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_1920x1088
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_864x480
                #define H264_DECODER_LEVEL_MPHP                 Level_31
            #else
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_1920x1088
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_1920x1088
                #define H264_DECODER_LEVEL_BP                   Level_40
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_1920x1088
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_1920x1088
                #define H264_DECODER_LEVEL_MPHP                 Level_40
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #else
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_1280x720
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_864x480
                #define H264_DECODER_LEVEL_BP                   Level_22
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_864x480
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_640x480
                #define H264_DECODER_LEVEL_MPHP                 Level_22
            #else
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_864x480
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_864x480
                #define H264_DECODER_LEVEL_BP                   Level_22
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_864x480
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_864x480
                #define H264_DECODER_LEVEL_MPHP                 Level_22
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #endif  // __H264_DEC_SW_SLIM__
    //#endif  // __H264_DEC_SW_SUPPORT__

    #ifdef __RV_DEC_SW_SUPPORT__
        #ifdef __SW_VIDEO_MAX_RESOLUTION__
            #define RV9_SUPPORT_RESOLUTION              RESOLUTION_1920x1088
            #define RV9_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_1280x720
        #else
            #define RV9_SUPPORT_RESOLUTION              RESOLUTION_1280x720
            #define RV9_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_1280x720
        #endif  // __SW_VIDEO_MAX_RESOLUTION__
    #endif  // __RV_DEC_SW_SUPPORT__

    #ifdef __MJPEG_DEC_SW_SUPPORT__
        #define MJPEG_SUPPORT_RESOLUTION                RESOLUTION_1280x720
        #define MJPEG_MAX_QTY_MODE_RESOLUTION           RESOLUTION_1280x720
        #define MJPEG_MAX_NORMAL_MODE_RESOLUTION        RESOLUTION_1280x720
    #endif  // __MJPEG_DEC_SW_SUPPORT__

    //#ifdef __VP8_DEC_SW_SUPPORT__
        #ifdef __SW_VIDEO_MAX_RESOLUTION__
            #define VP8_SUPPORT_RESOLUTION              RESOLUTION_1920x1088
            #define VP8_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_1920x1088
            #define VP8_PADDING_SIZE                    64
        #else
            #define VP8_SUPPORT_RESOLUTION              RESOLUTION_1280x720
            #define VP8_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_720x576
            #define VP8_PADDING_SIZE                    64
        #endif  // __SW_VIDEO_MAX_RESOLUTION__
    //#endif //__VP8_DEC_SW_SUPPORT__
#endif  // (defined(MT6256))


/******************************************************************************
* Setting for MT6276 series
******************************************************************************/
#if (defined(MT6276))
    //#ifdef __MPEG4_DEC_SW_SUPPORT__
        #ifdef __MP4_DEC_SW_SLIM__
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_640x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1280x720
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_640x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1280x720
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_480x320
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_480x320
            #endif  // VIDEO_SW_MP4_LOSSY_SUPPORT
        #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_864x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1920x1088
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_864x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1920x1088
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_1920x1088
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1920x1088
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_1920x1088
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1920x1088
            #endif  // VIDEO_SW_MP4_LOSSY_SUPPORT
        #else
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_864x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1920x1088
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_864x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1920x1088
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_864x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_864x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_1280x720
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1280x720
            #endif  // VIDEO_SW_MP4_LOSSY_SUPPORT
        #endif  // __MP4_DEC_SW_SLIM__
    //#endif /*__MPEG4_DEC_SW_SUPPORT__*/

    //#ifdef __H264_DEC_SW_SUPPORT__
        #ifdef __H264_DEC_SW_SLIM__
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_480x320
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_480x320
                #define H264_DECODER_LEVEL_BP                Level_21
                #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_640x480
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_480x320
                #define H264_DECODER_LEVEL_MPHP              Level_21
            #else
                #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_480x320
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_480x320
                #define H264_DECODER_LEVEL_BP                Level_21
                #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_480x320
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_480x320
                #define H264_DECODER_LEVEL_MPHP              Level_21
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_1920x1088
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_864x480
                #define H264_DECODER_LEVEL_BP                Level_31
                #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_1920x1088
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_864x480
                #define H264_DECODER_LEVEL_MPHP              Level_31
            #else
                #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_1920x1088
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_1920x1088
                #define H264_DECODER_LEVEL_BP                Level_40
                #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_1920x1088
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_1920x1088
                #define H264_DECODER_LEVEL_MPHP              Level_40
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #else
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_1280x720
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_864x480
                #define H264_DECODER_LEVEL_BP                Level_22
                #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_864x480
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_640x480
                #define H264_DECODER_LEVEL_MPHP              Level_22
            #else
                #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_864x480
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_864x480
                #define H264_DECODER_LEVEL_BP                Level_22
                #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_864x480
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_864x480
                #define H264_DECODER_LEVEL_MPHP              Level_22
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #endif  // __H264_DEC_SW_SLIM__
    //#endif  // __H264_DEC_SW_SUPPORT__

    #ifdef __RV_DEC_SW_SUPPORT__
        #ifdef __SW_VIDEO_MAX_RESOLUTION__
            #define RV9_SUPPORT_RESOLUTION              RESOLUTION_1920x1088
            #define RV9_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_1280x720
        #else
            #define RV9_SUPPORT_RESOLUTION              RESOLUTION_1280x720
            #define RV9_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_1280x720
        #endif
    #endif  // __RV_DEC_SW_SUPPORT__

    #ifdef __MJPEG_DEC_SW_SUPPORT__
        #ifdef __MJPG_DEC_SW_SLIM__
            #define MJPEG_SUPPORT_RESOLUTION            RESOLUTION_480x320
            #define MJPEG_MAX_QTY_MODE_RESOLUTION       RESOLUTION_480x320
            #define MJPEG_MAX_NORMAL_MODE_RESOLUTION    RESOLUTION_480x320
        #else
            #define MJPEG_SUPPORT_RESOLUTION            RESOLUTION_848x480
            #define MJPEG_MAX_QTY_MODE_RESOLUTION       RESOLUTION_848x480
            #define MJPEG_MAX_NORMAL_MODE_RESOLUTION    RESOLUTION_848x480
        #endif // __MJPG_DEC_SW_SLIM__
    #endif  // __MJPEG_DEC_SW_SUPPORT__

    //#ifdef __VP8_DEC_SW_SUPPORT__
        #ifdef __SW_VIDEO_MAX_RESOLUTION__
            #define VP8_SUPPORT_RESOLUTION               RESOLUTION_1920x1088
            #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_1280x720
            #define VP8_PADDING_SIZE                     64
        #else
            #define VP8_SUPPORT_RESOLUTION               RESOLUTION_1280x720
            #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_1280x720
            #define VP8_PADDING_SIZE                     64
        #endif
    //#endif  // __VP8_DEC_SW_SUPPORT__
#endif  // (defined(MT6276))


/******************************************************************************
* Setting for MT6235 series
******************************************************************************/
#if (defined(MT6235) || defined(MT6235B))
    //#ifdef __MPEG4_DEC_SW_SUPPORT__
        #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP         RESOLUTION_640x480
        //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP          RESOLUTION_864x480
        #define MPEG4_SUPPORT_RESOLUTION_SP                 RESOLUTION_1280x720
        #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP          RESOLUTION_1920x1088
        #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP        RESOLUTION_640x480
        //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP         RESOLUTION_864x480
        #define MPEG4_SUPPORT_RESOLUTION_ASP                RESOLUTION_1280x720
        #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP         RESOLUTION_1920x1088
    //#endif /*__MPEG4_DEC_SW_SUPPORT__*/

    //#ifdef __H264_DEC_SW_SUPPORT__
        #ifdef __H264_DEC_SW_SLIM__
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_480x320
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_480x320
            #define H264_DECODER_LEVEL_BP                   Level_21
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_480x320
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_480x320
            #define H264_DECODER_LEVEL_MPHP                 Level_21
        #else
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_1280x720
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_480x320
            #define H264_DECODER_LEVEL_BP                   Level_21
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_864x480
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_480x320
            #define H264_DECODER_LEVEL_MPHP                 Level_21
        #endif  // __H264_DEC_SW_SLIM__
    //#endif /*__H264_DEC_SW_SUPPORT__*/

    #ifdef __MJPEG_DEC_SW_SUPPORT__
        #ifdef __MMI_MAINLCD_320X480__  // HVGA
            #define MJPEG_SUPPORT_RESOLUTION            RESOLUTION_480x320
            #define MJPEG_MAX_QTY_MODE_RESOLUTION       RESOLUTION_480x320
            #define MJPEG_MAX_NORMAL_MODE_RESOLUTION    RESOLUTION_480x320
        #else
            #define MJPEG_SUPPORT_RESOLUTION            RESOLUTION_352x288
            #define MJPEG_MAX_QTY_MODE_RESOLUTION       RESOLUTION_352x288
            #define MJPEG_MAX_NORMAL_MODE_RESOLUTION    RESOLUTION_352x288
        #endif  // __MMI_MAINLCD_320X480__
    #endif  // __MJPEG_DEC_SW_SUPPORT__

    #ifdef __RV_DEC_SW_SUPPORT__
        #ifdef __SW_VIDEO_MAX_RESOLUTION__
            #define RV9_SUPPORT_RESOLUTION              RESOLUTION_1920x1088
            #define RV9_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_848x480
        #else
            #define RV9_SUPPORT_RESOLUTION              RESOLUTION_848x480
            #define RV9_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_848x480
        #endif
    #endif  // __RV_DEC_SW_SUPPORT__

    //#ifdef __VP8_DEC_SW_SUPPORT__
        #ifdef __SW_VIDEO_MAX_RESOLUTION__
            #define VP8_SUPPORT_RESOLUTION              RESOLUTION_1920x1088
            #define VP8_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_1280x720
            #define VP8_PADDING_SIZE                    64
        #else
            #define VP8_SUPPORT_RESOLUTION              RESOLUTION_480x320
            #define VP8_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_480x320
            #define VP8_PADDING_SIZE                    64
        #endif
    //#endif //__VP8_DEC_SW_SUPPORT__
#endif  // (defined(MT6235) || defined(MT6235B))


/******************************************************************************
* Setting for MT6255 series
******************************************************************************/
#if defined(MT6255)
    #if defined(MT6922) && !defined(NAND_SUPPORT)
        //#ifdef __MPEG4_DEC_SW_SUPPORT__
            #if defined(__OP01__)
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP RESOLUTION_176x144
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP  RESOLUTION_176x144
                #define MPEG4_SUPPORT_RESOLUTION_SP         RESOLUTION_176x144
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP  RESOLUTION_176x144
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP RESOLUTION_352x288
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP  RESOLUTION_352x288
                #define MPEG4_SUPPORT_RESOLUTION_SP         RESOLUTION_352x288
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP  RESOLUTION_352x288
            #endif  // defined(__OP01__)
            #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_352x288
            //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_352x288
            #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_352x288
            #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_352x288
        //#endif // __MPEG4_DEC_SW_SUPPORT__

        //#ifdef __H264_DEC_SW_SUPPORT__
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_176x144
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_176x144
            #define H264_DECODER_LEVEL_BP                   Level_10
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_176x144
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_176x144
            #define H264_DECODER_LEVEL_MPHP                 Level_10
        //#endif //__H264_DEC_SW_SUPPORT__

        #ifdef __RV_DEC_SW_SUPPORT__
            #ifdef __SW_VIDEO_MAX_RESOLUTION__
                #define RV9_SUPPORT_RESOLUTION              RESOLUTION_352x288
                #define RV9_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_352x288
            #else
                #define RV9_SUPPORT_RESOLUTION              RESOLUTION_176x144
                #define RV9_MAX_NORMAL_MODE_RESOLUTION      RESOLUTION_176x144
            #endif
        #endif //__RV_DEC_SW_SUPPORT__

        //#ifdef __VP8_DEC_SW_SUPPORT__
            #ifdef __SW_VIDEO_MAX_RESOLUTION__
                #define VP8_SUPPORT_RESOLUTION               RESOLUTION_1920x1088
                #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_1280x720
                #define VP8_PADDING_SIZE                     64
            #else
                #define VP8_SUPPORT_RESOLUTION               RESOLUTION_1280x720
                #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_640x480
                #define VP8_PADDING_SIZE                     64
            #endif
        //#endif //__VP8_DEC_SW_SUPPORT__

    #else

        // (1) MT6255 or (2) MT6922 with NAND support
        #ifdef __MP4_DEC_SW_SLIM__
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_640x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_720x576
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1280x720
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_640x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_720x576
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1280x720
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_480x320
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_480x320
            #endif
        #elif __SW_VIDEO_MAX_RESOLUTION__
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_720x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1920x1088
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_720x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1920x1088
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_1920x1088
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1920x1088
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_1920x1088
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1920x1088
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1920x1088
            #endif
        #else
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_720x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1920x1088
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_720x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_1280x720
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1920x1088
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_720x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_720x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_720x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_720x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_720x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_720x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_720x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_720x480
            #endif
        #endif  // __MP4_DEC_SW_SLIM__

        #ifdef __H264_DEC_SW_SLIM__
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_480x320
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_480x320
                #define H264_DECODER_LEVEL_BP                Level_21
                #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_480x320
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_480x320
                #define H264_DECODER_LEVEL_MPHP              Level_21
            #else
                #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_480x320
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_480x320
                #define H264_DECODER_LEVEL_BP                Level_21
                #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_480x320
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_480x320
                #define H264_DECODER_LEVEL_MPHP              Level_21
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_1920x1088
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_1920x1088
                #define H264_DECODER_LEVEL_BP                Level_40
                #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_1920x1088
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_1920x1088
                #define H264_DECODER_LEVEL_MPHP              Level_40
            #else
                #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_1920x1088
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_1920x1088
                #define H264_DECODER_LEVEL_BP                Level_40
                #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_1920x1088
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_1920x1088
                #define H264_DECODER_LEVEL_MPHP              Level_40
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #else
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_864x480
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_480x320
                #define H264_DECODER_LEVEL_BP                Level_21
                #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_864x480
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_480x320
                #define H264_DECODER_LEVEL_MPHP              Level_21
            #else
                #define H264_SUPPORT_RESOLUTION_BP           RESOLUTION_320x240
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP   RESOLUTION_320x240
                #define H264_DECODER_LEVEL_BP                Level_20
                #define H264_SUPPORT_RESOLUTION_MPHP         RESOLUTION_320x240
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP RESOLUTION_320x240
                #define H264_DECODER_LEVEL_MPHP              Level_20
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #endif  // __H264_DEC_SW_SLIM__

        #ifdef __RV_DEC_SW_SUPPORT__
            #ifdef __SW_VIDEO_MAX_RESOLUTION__
                #define RV9_SUPPORT_RESOLUTION               RESOLUTION_1920x1088
                #define RV9_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_848x480
            #else
                #define RV9_SUPPORT_RESOLUTION               RESOLUTION_848x480
                #define RV9_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_848x480
            #endif
        #endif  // __RV_DEC_SW_SUPPORT__

        #ifdef __MJPEG_DEC_SW_SUPPORT__
            #if defined(__EMI_CLK_200MHZ__)
                #define MJPEG_SUPPORT_RESOLUTION          RESOLUTION_1920x1088
                #define MJPEG_MAX_QTY_MODE_RESOLUTION     RESOLUTION_1280x720
                #define MJPEG_MAX_NORMAL_MODE_RESOLUTION  RESOLUTION_848x480
            #else
                #define MJPEG_SUPPORT_RESOLUTION          RESOLUTION_1920x1088
                #define MJPEG_MAX_QTY_MODE_RESOLUTION     RESOLUTION_1280x720
                #define MJPEG_MAX_NORMAL_MODE_RESOLUTION  RESOLUTION_640x480
            #endif
        #endif

        //#ifdef __VP8_DEC_SW_SUPPORT__
            #ifdef __SW_VIDEO_MAX_RESOLUTION__
                #define VP8_SUPPORT_RESOLUTION               RESOLUTION_1920x1088
                #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_1920x1088
                #define VP8_PADDING_SIZE                     64
            #else
                #define VP8_SUPPORT_RESOLUTION               RESOLUTION_1280x720
                #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_640x368
                #define VP8_PADDING_SIZE                     64
            #endif
        //#endif  // __VP8_DEC_SW_SUPPORT__
    #endif // defined(MT6922)
#endif  // defined(MT6255)


/******************************************************************************
* Setting for MT6250 series
******************************************************************************/
#if defined(MT6250)
    #ifdef __MP4_DEC_SW_SLIM__
        #ifdef __MED_VIDEO_ULC__
            #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_176x144
            //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_176x144
            #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_352x288
            #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_352x288
            #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_176x144
            //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_176x144
            #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_352x288
            #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_352x288
        #else
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_720x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_864x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_720x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_864x480
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_432x240
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_432x240
            #endif
        #endif
    #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_640x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1280x720
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_640x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_848x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1280x720
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_848x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_848x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_848x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_848x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_848x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_848x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_848x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_848x480
            #endif
    #else
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_640x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1280x720
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_640x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1280x720
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_480x320
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_480x320
            #endif
    #endif  // __MP4_DEC_SW_SLIM__

    #ifdef __H264_DEC_SW_SLIM__
        #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_240x192
            #define H264_DECODER_LEVEL_BP                   Level_11
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_240x192
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_240x192
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_240x192
            #define H264_DECODER_LEVEL_MPHP                 Level_11
        #else
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_176x144
            #define H264_DECODER_LEVEL_BP                   Level_10
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_176x144
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_176x144
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_176x144
            #define H264_DECODER_LEVEL_MPHP                 Level_10
        #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
    #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
        #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_864x480
            #define H264_DECODER_LEVEL_BP                   Level_21
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_320x240
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_864x480
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_320x240
            #define H264_DECODER_LEVEL_MPHP                 Level_21
        #else
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_864x480
            #define H264_DECODER_LEVEL_BP                   Level_22
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_864x480
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_864x480
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_864x480
            #define H264_DECODER_LEVEL_MPHP                 Level_22
        #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
    #else
        #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_320x240
            #define H264_DECODER_LEVEL_BP                   Level_11
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_320x240
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_320x240
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_320x240
            #define H264_DECODER_LEVEL_MPHP                 Level_11
        #else
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_176x144
            #define H264_DECODER_LEVEL_BP                   Level_10
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_176x144
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_176x144
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_176x144
            #define H264_DECODER_LEVEL_MPHP                 Level_10
        #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
    #endif  // __H264_DEC_SW_SLIM__

    #ifdef __MJPEG_DEC_SW_SUPPORT__
        #if defined (__MED_VIDEO_ULC__)
            #define MJPEG_SUPPORT_RESOLUTION                RESOLUTION_352x288
            #define MJPEG_MAX_QTY_MODE_RESOLUTION           RESOLUTION_352x288
            #define MJPEG_MAX_NORMAL_MODE_RESOLUTION        RESOLUTION_176x144
        #else
            #if defined(__MJPG_DEC_SW_SLIM__)
                #define MJPEG_SUPPORT_RESOLUTION            RESOLUTION_352x288
                #define MJPEG_MAX_QTY_MODE_RESOLUTION       RESOLUTION_352x288
                #define MJPEG_MAX_NORMAL_MODE_RESOLUTION    RESOLUTION_352x288
            #else
                #define MJPEG_SUPPORT_RESOLUTION            RESOLUTION_480x320
                #define MJPEG_MAX_QTY_MODE_RESOLUTION       RESOLUTION_480x320
                #define MJPEG_MAX_NORMAL_MODE_RESOLUTION    RESOLUTION_480x320
            #endif
        #endif  // defined (__MED_VIDEO_ULC__)
    #endif  // __MJPEG_DEC_SW_SUPPORT__

    //#ifdef __VP8_DEC_SW_SUPPORT__
        #define VP8_SUPPORT_RESOLUTION               RESOLUTION_240x192
        #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_240x192
        #define VP8_PADDING_SIZE                     64
    //#endif //__VP8_DEC_SW_SUPPORT__
#endif  // defined(MT6250)


/******************************************************************************
* Setting for MT6260, MT6261 series
******************************************************************************/
#if (defined(MT6260) || defined(MT6261))
    #ifdef __MP4_DEC_SW_SLIM__
        #ifdef __MED_VIDEO_ULC__
            #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_176x144
            //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_176x144
            #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_352x288
            #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_352x288
            #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_176x144
            //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_176x144
            #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_352x288
            #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_352x288
        #else
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_720x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_864x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_720x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_864x480
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_432x240
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_432x240
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_432x240
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_432x240
            #endif
        #endif
    #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_640x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1280x720
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_640x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_848x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1280x720
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_848x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_848x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_848x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_848x480
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_848x480
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_848x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_848x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_848x480
            #endif
    #else
            #ifdef VIDEO_SW_MP4_LOSSY_SUPPORT
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_640x480
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_1280x720
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_640x480
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_864x480
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_1280x720
            #else
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP     RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP      RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_SP             RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP      RESOLUTION_480x320
                #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP    RESOLUTION_480x320
                //#define MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP     RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_ASP            RESOLUTION_480x320
                #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP     RESOLUTION_480x320
            #endif
    #endif  // __MP4_DEC_SW_SLIM__

    #ifdef __H264_DEC_SW_SLIM__
        #ifdef __KMV_SUPPORT__
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_320x240
            #define H264_DECODER_LEVEL_BP                   Level_11
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_320x240
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_320x240
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_320x240        
        #else        
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
		#ifdef __MOT_SUPPORT__
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_240x192
                #define H264_DECODER_LEVEL_BP                   Level_11
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_240x192
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_240x192
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_240x192
                #define H264_DECODER_LEVEL_MPHP                 Level_11
                #else
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_176x144
                #define H264_DECODER_LEVEL_BP                   Level_10
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_176x144
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_176x144
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_176x144
                #define H264_DECODER_LEVEL_MPHP                 Level_10
		#endif
            #else
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_176x144
                #define H264_DECODER_LEVEL_BP                   Level_10
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_176x144
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_176x144
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_176x144
                #define H264_DECODER_LEVEL_MPHP                 Level_10
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
       #endif
    #elif defined (__SW_VIDEO_MAX_RESOLUTION__)
        #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_864x480
            #define H264_DECODER_LEVEL_BP                   Level_21
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_320x240
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_864x480
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_320x240
            #define H264_DECODER_LEVEL_MPHP                 Level_21
        #else
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_864x480
            #define H264_DECODER_LEVEL_BP                   Level_22
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_864x480
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_864x480
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_864x480
            #define H264_DECODER_LEVEL_MPHP                 Level_22
        #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
    #else
        #ifdef __KMV_SUPPORT__
            #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_320x240
            #define H264_DECODER_LEVEL_BP                   Level_11
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_320x240
            #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_320x240
            #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_320x240        
        #else
            #ifdef VIDEO_SW_H264_LOSSY_SUPPORT
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_320x240
                #define H264_DECODER_LEVEL_BP                   Level_11
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_320x240
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_320x240
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_320x240
                #define H264_DECODER_LEVEL_MPHP                 Level_11
            #else
                #define H264_SUPPORT_RESOLUTION_BP              RESOLUTION_176x144
                #define H264_DECODER_LEVEL_BP                   Level_10
                #define H264_MAX_NORMAL_MODE_RESOLUTION_BP      RESOLUTION_176x144
                #define H264_SUPPORT_RESOLUTION_MPHP            RESOLUTION_176x144
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP    RESOLUTION_176x144
                #define H264_DECODER_LEVEL_MPHP                 Level_10
            #endif  // VIDEO_SW_H264_LOSSY_SUPPORT
        #endif
    #endif  // __H264_DEC_SW_SLIM__

    #ifdef __MJPEG_DEC_SW_SUPPORT__
        #if defined (__MED_VIDEO_ULC__)
            #define MJPEG_SUPPORT_RESOLUTION                RESOLUTION_352x288
            #define MJPEG_MAX_QTY_MODE_RESOLUTION           RESOLUTION_352x288
            #define MJPEG_MAX_NORMAL_MODE_RESOLUTION        RESOLUTION_176x144
        #else
            #if defined(__MJPG_DEC_SW_SLIM__)
                #define MJPEG_SUPPORT_RESOLUTION            RESOLUTION_352x288
                #define MJPEG_MAX_QTY_MODE_RESOLUTION       RESOLUTION_352x288
                #define MJPEG_MAX_NORMAL_MODE_RESOLUTION    RESOLUTION_352x288
            #else
                #define MJPEG_SUPPORT_RESOLUTION            RESOLUTION_480x320
                #define MJPEG_MAX_QTY_MODE_RESOLUTION       RESOLUTION_480x320
                #define MJPEG_MAX_NORMAL_MODE_RESOLUTION    RESOLUTION_480x320
            #endif
        #endif  // defined (__MED_VIDEO_ULC__)
    #endif  // __MJPEG_DEC_SW_SUPPORT__

    //#ifdef __VP8_DEC_SW_SUPPORT__
        #define VP8_SUPPORT_RESOLUTION               RESOLUTION_240x192
        #define VP8_MAX_NORMAL_MODE_RESOLUTION       RESOLUTION_240x192
        #define VP8_PADDING_SIZE                     64
    //#endif //__VP8_DEC_SW_SUPPORT__
#endif  // defined(MT6260)


/******************************************************************************
* Setting for VT scenario
******************************************************************************/
#ifdef __VIDEO_VT_SUPPORT__
    //#ifdef __MPEG4_DEC_SW_SUPPORT__
        #define MPEG4_VT_DEC_MAX_WIDTH         176
        #define MPEG4_VT_DEC_MAX_HEIGHT        144
        #define MPEG4_VT_SUPPORT_RESOLUTION    RESOLUTION_176x144
        #define MPEG4_VT_DEC_WORKING_MEM       MP4SwDecExtSize_176x144_SP
    //#endif /* __MPEG4_DEC_SW_SUPPORT__ */
#endif /* __VIDEO_VT_SUPPORT__*/


/******************************************************************************
* Setting for QVGA scenario
******************************************************************************/
//#ifdef __MPEG4_DEC_SW_SUPPORT__
    #define MPEG4_QVGA_DEC_MAX_WIDTH            320
    #define MPEG4_QVGA_DEC_MAX_HEIGHT           240
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #define MPEG4_QVGA_DEC_WORKING_MEM      MP4SwDecExtSize_320x240_ASP
    #else
        #define MPEG4_QVGA_DEC_WORKING_MEM      MP4SwDecExtSize_320x240_SP
    #endif
//#endif /* __MPEG4_DEC_SW_SUPPORT__ */

//#ifdef __H264_DEC_SW_SUPPORT__
    #define H264_QVGA_DEC_MAX_WIDTH             320
    #define H264_QVGA_DEC_MAX_HEIGHT            240
    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        #define H264_QVGA_DEC_WORKING_MEM       H264SwDecExtSize_320x240_MPHP
    #else
        #define H264_QVGA_DEC_WORKING_MEM       H264SwDecExtSize_320x240_BP
    #endif
    #define H264_QVGA_DECODER_LEVEL             Level_12  // Level_11
    #define H264_QVGA_DEC_DPB_SIZE              H264SwDecLevel12  // H264SwDecLevel11
//#endif /* __H264_DEC_SW_SUPPORT__ */

#ifdef __RV_DEC_SW_SUPPORT__
    #define RV9_QVGA_DEC_MAX_WIDTH              320
    #define RV9_QVGA_DEC_MAX_HEIGHT             240
    #define RV9_QVGA_DEC_WORKING_MEM            RVSwDecExtSize_320x240
#endif /* __RV_DEC_SW_SUPPORT__ */

#ifdef __MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_QVGA_DEC_MAX_WIDTH            320
    #define MJPEG_QVGA_DEC_MAX_HEIGHT           240
    #define MJPEG_QVGA_DEC_WORKING_MEM          JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE
#endif /* __MJPEG_DEC_SW_SUPPORT__ */

//#ifdef __VP8_DEC_SW_SUPPORT__
    #define VP8_QVGA_DEC_MAX_WIDTH              320
    #define VP8_QVGA_DEC_MAX_HEIGHT             240
    #define VP8_QVGA_DEC_WORKING_MEM            VP8SwDecExtSize_320x240
//#endif /* __VP8_DEC_SW_SUPPORT__ */


/******************************************************************************
* Setting for QVGAMPEG4SP scenario
******************************************************************************/
//#ifdef __MPEG4_DEC_SW_SUPPORT__
    #define MPEG4_QVGAMPEG4SP_DEC_MAX_WIDTH        320
    #define MPEG4_QVGAMPEG4SP_DEC_MAX_HEIGHT       240
    #define MPEG4_QVGAMPEG4SP_DEC_WORKING_MEM      MP4SwDecExtSize_320x240_SP
//#endif /* __MPEG4_DEC_SW_SUPPORT__ */


/******************************************************************************
* Setting for QCIF scenario
******************************************************************************/
//#ifdef __MPEG4_DEC_SW_SUPPORT__
    #define MPEG4_QCIF_DEC_MAX_WIDTH            176
    #define MPEG4_QCIF_DEC_MAX_HEIGHT           144
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #define MPEG4_QCIF_DEC_WORKING_MEM      MP4SwDecExtSize_176x144_ASP
    #else
        #define MPEG4_QCIF_DEC_WORKING_MEM      MP4SwDecExtSize_176x144_SP
    #endif
//#endif /* __MPEG4_DEC_SW_SUPPORT__ */

//#ifdef __H264_DEC_SW_SUPPORT__
    #define H264_QCIF_DEC_MAX_WIDTH             176
    #define H264_QCIF_DEC_MAX_HEIGHT            144
    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        #define H264_QCIF_DEC_WORKING_MEM       H264SwDecExtSize_176x144_MPHP
    #else
        #define H264_QCIF_DEC_WORKING_MEM       H264SwDecExtSize_176x144_BP
    #endif
    #define H264_QCIF_DECODER_LEVEL             Level_10
    #define H264_QCIF_DEC_DPB_SIZE              H264SwDecLevel10
//#endif /* __H264_DEC_SW_SUPPORT__ */

#ifdef __RV_DEC_SW_SUPPORT__
    #define RV9_QCIF_DEC_MAX_WIDTH              176
    #define RV9_QCIF_DEC_MAX_HEIGHT             144
    #define RV9_QCIF_DEC_WORKING_MEM            RVSwDecExtSize_176x144
#endif /* __RV_DEC_SW_SUPPORT__ */

#ifdef __MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_QCIF_DEC_MAX_WIDTH            176
    #define MJPEG_QCIF_DEC_MAX_HEIGHT           144
    #define MJPEG_QCIF_DEC_WORKING_MEM          JPEG_DEC_MJPEG_EXT_MAX_MEM_SIZE
#endif /* __MJPEG_DEC_SW_SUPPORT__ */

//#ifdef __VP8_DEC_SW_SUPPORT__
    #define VP8_QCIF_DEC_MAX_WIDTH              176
    #define VP8_QCIF_DEC_MAX_HEIGHT             144
    #define VP8_QCIF_DEC_WORKING_MEM            VP8SwDecExtSize_176x144
//#endif /* __VP8_DEC_SW_SUPPORT__ */


/******************************************************************************
* Setting for VGA scenario
******************************************************************************/
//#ifdef __MPEG4_DEC_SW_SUPPORT__
    #define MPEG4_VGA_DEC_MAX_WIDTH             640
    #define MPEG4_VGA_DEC_MAX_HEIGHT            480
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #define MPEG4_VGA_DEC_WORKING_MEM       MP4SwDecExtSize_640x480_ASP
    #else
        #define MPEG4_VGA_DEC_WORKING_MEM       MP4SwDecExtSize_640x480_SP
    #endif
//#endif /* __MPEG4_DEC_SW_SUPPORT__ */

//#ifdef __H264_DEC_SW_SUPPORT__
    #define H264_VGA_DEC_MAX_WIDTH              640
    #define H264_VGA_DEC_MAX_HEIGHT             480
    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        #define H264_VGA_DEC_WORKING_MEM        H264SwDecExtSize_640x480_MPHP
    #else
        #define H264_VGA_DEC_WORKING_MEM        H264SwDecExtSize_640x480_BP
    #endif
    #define H264_VGA_DECODER_LEVEL              Level_22
    #define H264_VGA_DEC_DPB_SIZE               H264SwDecLevel22
//#endif /* __H264_DEC_SW_SUPPORT__ */

#ifdef __RV_DEC_SW_SUPPORT__
    #define RV9_VGA_DEC_MAX_WIDTH               640
    #define RV9_VGA_DEC_MAX_HEIGHT              480
    #define RV9_VGA_DEC_WORKING_MEM             RVSwDecExtSize_640x480
#endif /* __RV_DEC_SW_SUPPORT__ */

#ifdef __MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_VGA_DEC_MAX_WIDTH             640
    #define MJPEG_VGA_DEC_MAX_HEIGHT            480
    #define MJPEG_VGA_DEC_WORKING_MEM           JPEG_DEC_MJPEG_EXT_MAX_MEM_SIZE
#endif /* __MJPEG_DEC_SW_SUPPORT__ */

//#ifdef __VP8_DEC_SW_SUPPORT__
    #define VP8_VGA_DEC_MAX_WIDTH               640
    #define VP8_VGA_DEC_MAX_HEIGHT              480
    #define VP8_VGA_DEC_WORKING_MEM             VP8SwDecExtSize_640x480
//#endif /* __VP8_DEC_SW_SUPPORT__ */


/******************************************************************************
* Setting for CIF scenario
******************************************************************************/
//#ifdef __MPEG4_DEC_SW_SUPPORT__
    #define MPEG4_CIF_DEC_MAX_WIDTH             352
    #define MPEG4_CIF_DEC_MAX_HEIGHT            288
    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #define MPEG4_CIF_DEC_WORKING_MEM       MP4SwDecExtSize_352x288_ASP
    #else
        #define MPEG4_CIF_DEC_WORKING_MEM       MP4SwDecExtSize_352x288_SP
    #endif
//#endif /* __MPEG4_DEC_SW_SUPPORT__ */

//#ifdef __H264_DEC_SW_SUPPORT__
    #define H264_CIF_DEC_MAX_WIDTH              352
    #define H264_CIF_DEC_MAX_HEIGHT             288
    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        #define H264_CIF_DEC_WORKING_MEM        H264SwDecExtSize_352x288_MPHP
    #else
        #define H264_CIF_DEC_WORKING_MEM        H264SwDecExtSize_352x288_BP
    #endif
    #define H264_CIF_DECODER_LEVEL              Level_11
    #define H264_CIF_DEC_DPB_SIZE               H264SwDecLevel11
//#endif /* __H264_DEC_SW_SUPPORT__ */

#ifdef __RV_DEC_SW_SUPPORT__
    #define RV9_CIF_DEC_MAX_WIDTH               352
    #define RV9_CIF_DEC_MAX_HEIGHT              288
    #define RV9_CIF_DEC_WORKING_MEM             RVSwDecExtSize_352x288
#endif /* __RV_DEC_SW_SUPPORT__ */

#ifdef __MJPEG_DEC_SW_SUPPORT__
    #define MJPEG_CIF_DEC_MAX_WIDTH             352
    #define MJPEG_CIF_DEC_MAX_HEIGHT            288
    #define MJPEG_CIF_DEC_WORKING_MEM           JPEG_DEC_MJPEG_EXT_MAX_MEM_SIZE
#endif /* __MJPEG_DEC_SW_SUPPORT__ */

//#ifdef __VP8_DEC_SW_SUPPORT__
    #define VP8_CIF_DEC_MAX_WIDTH               352
    #define VP8_CIF_DEC_MAX_HEIGHT              288
    #define VP8_CIF_DEC_WORKING_MEM             VP8SwDecExtSize_352x288
//#endif /* __VP8_DEC_SW_SUPPORT__ */


/******************************************************************************
* Replace with custom setting
******************************************************************************/
// MPEG4 decode
//#if defined(__MPEG4_DEC_SW_SUPPORT__)
    #ifdef MPEG4_DEC_CUSTOM_FRAME_SETTING_ENABLE
        /* SP */
        // 1:1
        #ifdef MPEG4_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_SP
            #undef MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP
            #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP (MPEG4_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_SP)
        #endif
        #if 0
/* under construction !*/
        #ifdef MPEG4_CUSTOM_SUPPORT_RESOLUTION_1_TO_2_SP
/* under construction !*/
/* under construction !*/
        #endif
        #endif  // 0
        // 1:4
        #ifdef MPEG4_CUSTOM_SUPPORT_RESOLUTION_SP
            #undef MPEG4_SUPPORT_RESOLUTION_SP
            #define MPEG4_SUPPORT_RESOLUTION_SP (MPEG4_CUSTOM_SUPPORT_RESOLUTION_SP)
        #endif
        // 1:8
        #ifdef MPEG4_CUSTOM_SUPPORT_RESOLUTION_1_TO_8_SP
            #undef MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP
            #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP (MPEG4_CUSTOM_SUPPORT_RESOLUTION_1_TO_8_SP)
        #endif
        /* ASP */
        // 1:1
        #ifdef MPEG4_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_ASP
            #undef MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP
            #define MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP (MPEG4_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_ASP)
        #endif
        #if 0
/* under construction !*/
        #ifdef MPEG4_CUSTOM_SUPPORT_RESOLUTION_1_TO_2_ASP
/* under construction !*/
/* under construction !*/
        #endif
        #endif  // 0
        // 1:4
        #ifdef MPEG4_CUSTOM_SUPPORT_RESOLUTION_ASP
            #undef MPEG4_SUPPORT_RESOLUTION_ASP
            #define MPEG4_SUPPORT_RESOLUTION_ASP (MPEG4_CUSTOM_SUPPORT_RESOLUTION_ASP)
        #endif
        // 1:8
        #ifdef MPEG4_CUSTOM_SUPPORT_RESOLUTION_1_TO_8_ASP
            #undef MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP
            #define MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP (MPEG4_CUSTOM_SUPPORT_RESOLUTION_1_TO_8_ASP)
        #endif
    #endif /* MPEG4_DEC_CUSTOM_FRAME_SETTING_ENABLE */
//#endif /* __MPEG4_DEC_SW_SUPPORT__ */


// H264 decode
//#if defined(__H264_DEC_SW_SUPPORT__)
    #ifdef H264_DEC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef H264_CUSTOM_SUPPORT_RESOLUTION_BP
            #undef H264_SUPPORT_RESOLUTION_BP
            #define H264_SUPPORT_RESOLUTION_BP (H264_CUSTOM_SUPPORT_RESOLUTION_BP)
        #endif
        #ifdef H264_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_BP
            #undef H264_MAX_NORMAL_MODE_RESOLUTION_BP
            #define H264_MAX_NORMAL_MODE_RESOLUTION_BP (H264_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_BP)
        #endif
        #ifdef H264_CUSTOM_DECODER_LEVEL_BP
            #undef H264_DECODER_LEVEL_BP
            #define H264_DECODER_LEVEL_BP (H264_CUSTOM_DECODER_LEVEL_BP)
        #endif

        #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
            #ifdef H264_CUSTOM_SUPPORT_RESOLUTION_MPHP
                #undef H264_SUPPORT_RESOLUTION_MPHP
                #define H264_SUPPORT_RESOLUTION_MPHP (H264_CUSTOM_SUPPORT_RESOLUTION_MPHP)
            #endif
            #ifdef H264_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_MPHP
                #undef H264_MAX_NORMAL_MODE_RESOLUTION_MPHP
                #define H264_MAX_NORMAL_MODE_RESOLUTION_MPHP (H264_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_MPHP)
            #endif
            #ifdef H264_CUSTOM_DECODER_LEVEL_MPHP
                #undef H264_DECODER_LEVEL_MPHP
                #define H264_DECODER_LEVEL_MPHP (H264_CUSTOM_DECODER_LEVEL_MPHP)
            #endif
        #endif
    #endif /* H264_DEC_CUSTOM_FRAME_SETTING_ENABLE */
//#endif /* __H264_DEC_SW_SUPPORT__ */


// RM decode
#ifdef __RV_DEC_SW_SUPPORT__
    #ifdef RV_DEC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef RV_CUSTOM_SUPPORT_RESOLUTION
            #undef RV9_SUPPORT_RESOLUTION
            #define RV9_SUPPORT_RESOLUTION (RV_CUSTOM_SUPPORT_RESOLUTION)
        #endif
        #ifdef RV_CUSTOM_MAX_NORMAL_MODE_RESOLUTION
            #undef RV9_MAX_NORMAL_MODE_RESOLUTION
            #define RV9_MAX_NORMAL_MODE_RESOLUTION (RV_CUSTOM_MAX_NORMAL_MODE_RESOLUTION)
        #endif
    #endif /* RV_DEC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /* __RV_DEC_SW_SUPPORT__ */


// Motion Jpeg Decode
#ifdef __MJPEG_DEC_SW_SUPPORT__
    #ifdef MJPEG_DEC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef MJPEG_CUSTOM_SUPPORT_RESOLUTION
            #undef MJPEG_SUPPORT_RESOLUTION
            #define MJPEG_SUPPORT_RESOLUTION (MJPEG_CUSTOM_SUPPORT_RESOLUTION)
        #endif
        #ifdef MJPEG_CUSTOM_MAX_QTY_MODE_RESOLUTION
            #undef MJPEG_MAX_QTY_MODE_RESOLUTION
            #define MJPEG_MAX_QTY_MODE_RESOLUTION (MJPEG_CUSTOM_MAX_QTY_MODE_RESOLUTION)
        #endif
        #ifdef MJPEG_CUSTOM_MAX_NORMAL_MODE_RESOLUTION
            #undef MJPEG_MAX_NORMAL_MODE_RESOLUTION
            #define MJPEG_MAX_NORMAL_MODE_RESOLUTION (MJPEG_CUSTOM_MAX_NORMAL_MODE_RESOLUTION)
        #endif
    #endif /* MJPEG_DEC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /* __MJPEG_DEC_SW_SUPPORT__ */


// VP8 decode
//#ifdef __VP8_DEC_SW_SUPPORT__
    #ifdef VP8_DEC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef VP8_CUSTOM_SUPPORT_RESOLUTION
            #undef VP8_SUPPORT_RESOLUTION
            #define VP8_SUPPORT_RESOLUTION (VP8_CUSTOM_SUPPORT_RESOLUTION)
        #endif
        #ifdef VP8_CUSTOM_MAX_NORMAL_MODE_RESOLUTION
            #undef VP8_MAX_NORMAL_MODE_RESOLUTION
            #define VP8_MAX_NORMAL_MODE_RESOLUTION (VP8_CUSTOM_MAX_NORMAL_MODE_RESOLUTION)
        #endif
    #endif /* VP8_DEC_CUSTOM_FRAME_SETTING_ENABLE */
//#endif /* __VP8_DEC_SW_SUPPORT__ */

/******************************************************************************
* translate custom setting
******************************************************************************/
//#ifdef __MPEG4_DEC_SW_SUPPORT__
    #if 0
/* under construction !*/
    #if (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_128x96)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_176x144)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_320x240)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_400x240)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_352x288)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_432x240)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_480x320)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_640x368)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_640x480)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_720x480)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_800x480)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_848x480)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_864x480)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_720x576)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_800x608)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_1024x768)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_1280x720)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_1280x960)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_1280x1024)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_1408x1152)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_1600x1200)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_SP == RESOLUTION_1920x1088)
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
    #endif
    #endif  // 0

    // 1:4
    #if (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_128x96)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       128
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      96
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_176x144)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       176
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      144
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_320x240)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       320
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      240
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_400x240)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       400
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      240
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_352x288)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       352
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      288
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_432x240)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       432
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      240
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_480x320)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       480
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      320
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_640x368)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       640
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      368
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_640x480)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       640
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      480
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_720x480)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       720
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      480
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_800x480)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       800
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      480
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_848x480)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       848
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      480
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_864x480)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       864
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      480
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_720x576)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       720
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      576
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_800x608)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       800
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      608
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_1024x768)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       1024
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      768
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_1280x720)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       1280
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      720
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_1280x960)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       1280
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      960
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_1280x1024)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       1280
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      1024
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_1408x1152)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       1408
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      1152
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_1600x1200)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       1600
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      1200
    #elif (MPEG4_SUPPORT_RESOLUTION_SP == RESOLUTION_1920x1088)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_SP       1920
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP      1088
    #else
        #error "This 1:4 resolution is not support by mpeg4 decoder SP."
    #endif

    // 1:8
    #if (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_128x96)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_128x96_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              128
        #define MPEG4_DEC_MAX_HEIGHT_SP             96
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_128x96_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_176x144)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_176x144_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              176
        #define MPEG4_DEC_MAX_HEIGHT_SP             144
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_176x144_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_320x240)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_320x240_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              320
        #define MPEG4_DEC_MAX_HEIGHT_SP             240
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_320x240_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_400x240)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_400x240_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              400
        #define MPEG4_DEC_MAX_HEIGHT_SP             240
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_400x240_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_352x288)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_352x288_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              352
        #define MPEG4_DEC_MAX_HEIGHT_SP             288
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_352x288_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_432x240)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_432x240_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              432
        #define MPEG4_DEC_MAX_HEIGHT_SP             240
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_432x240_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_480x320)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_480x320_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              480
        #define MPEG4_DEC_MAX_HEIGHT_SP             320
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_480x320_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_640x368)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_640x368_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              640
        #define MPEG4_DEC_MAX_HEIGHT_SP             368
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_640x368_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_640x480)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_640x480_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              640
        #define MPEG4_DEC_MAX_HEIGHT_SP             480
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_640x480_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_720x480)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_720x480_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              720
        #define MPEG4_DEC_MAX_HEIGHT_SP             480
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_720x480_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_800x480)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_800x480_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              800
        #define MPEG4_DEC_MAX_HEIGHT_SP             480
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_800x480_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_848x480)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_848x480_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              848
        #define MPEG4_DEC_MAX_HEIGHT_SP             480
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_848x480_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_864x480)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_864x480_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              864
        #define MPEG4_DEC_MAX_HEIGHT_SP             480
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_864x480_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_720x576)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_720x576_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              720
        #define MPEG4_DEC_MAX_HEIGHT_SP             576
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_720x576_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_800x608)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_800x608_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              800
        #define MPEG4_DEC_MAX_HEIGHT_SP             608
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_800x608_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_1024x768)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_1024x768_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              1024
        #define MPEG4_DEC_MAX_HEIGHT_SP             768
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_1024x768_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_1280x720)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_1280x720_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              1280
        #define MPEG4_DEC_MAX_HEIGHT_SP             720
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_1280x720_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_1280x960)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_1280x960_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              1280
        #define MPEG4_DEC_MAX_HEIGHT_SP             960
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_1280x960_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_1280x1024)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_1280x1024_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              1280
        #define MPEG4_DEC_MAX_HEIGHT_SP             1024
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_1280x1024_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_1408x1152)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_1408x1152_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              1408
        #define MPEG4_DEC_MAX_HEIGHT_SP             1152
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_1408x1152_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_1600x1200)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_1600x1200_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              1600
        #define MPEG4_DEC_MAX_HEIGHT_SP             1200
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_1600x1200_SP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP == RESOLUTION_1920x1088)
        #define MPEG4_DEC_WORKING_MEM_SP            MP4SwDecExtSize_1920x1088_SP
        #define MPEG4_DEC_MAX_WIDTH_SP              1920
        #define MPEG4_DEC_MAX_HEIGHT_SP             1088
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_SP    MP4SwDecIntraModeExtSize_1920x1088_SP
    #else
        #error "This 1:8 resolution is not support by mpeg4 decoder SP."
    #endif

    #if (MPEG4_DEC_WORKING_MEM_SP == -1)
        #error "This resolution is not support by mpeg4 decoder SP."
    #endif

    // 1:1
    #if (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_128x96)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         128
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        96
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_176x144)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         176
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        144
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_320x240)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         320
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        240
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_400x240)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         400
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        240
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_352x288)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         352
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        288
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_432x240)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         432
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        240
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_480x320)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         480
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        320
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_640x368)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         640
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        368
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_640x480)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         640
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        480
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_720x480)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         720
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        480
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_800x480)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         800
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        480
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_848x480)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         848
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        480
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_864x480)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         864
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        480
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_720x576)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         720
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        576
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_800x608)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         800
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        608
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_1024x768)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         1024
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        768
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_1280x720)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         1280
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        720
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_1280x960)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         1280
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        960
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_1280x1024)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         1280
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        1024
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_1408x1152)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         1408
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        1152
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_1600x1200)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         1600
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        1200
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP == RESOLUTION_1920x1088)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_SP         1920
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_SP        1088
    #else
        #error "This 1:1 resolution is not support by mpeg4 decoder SP (Normal mode)."
    #endif

    // Check the range of SP width and height.
    #if 0
/* under construction !*/
    #if ((MPEG4_DEC_MAX_NORMAL_WIDTH_SP * MPEG4_DEC_MAX_NORMAL_HEIGHT_SP) > (MPEG4_DEC_MAX_WIDTH_1_TO_2_SP * MPEG4_DEC_MAX_HEIGHT_1_TO_2_SP))
/* under construction !*/
    #endif
    #endif  // 0
    // 1:1 vs 1:4
    #if ((MPEG4_DEC_MAX_NORMAL_WIDTH_SP * MPEG4_DEC_MAX_NORMAL_HEIGHT_SP) > (MPEG4_DEC_MAX_WIDTH_1_TO_4_SP * MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP))
        #error "Please make sure MPEG4_SUPPORT_RESOLUTION_SP >= MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP."
    #endif
    // 1:1 vs 1:8
    #if ((MPEG4_DEC_MAX_NORMAL_WIDTH_SP * MPEG4_DEC_MAX_NORMAL_HEIGHT_SP) > (MPEG4_DEC_MAX_WIDTH_SP * MPEG4_DEC_MAX_HEIGHT_SP))
        #error "Please make sure MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP >= MPEG4_MAX_NORMAL_MODE_RESOLUTION_SP."
    #endif
    #if 0
/* under construction !*/
    #if ((MPEG4_DEC_MAX_WIDTH_1_TO_2_SP * MPEG4_DEC_MAX_HEIGHT_1_TO_2_SP) > (MPEG4_DEC_MAX_WIDTH_1_TO_4_SP * MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP))
/* under construction !*/
    #endif
/* under construction !*/
    #if ((MPEG4_DEC_MAX_WIDTH_1_TO_2_SP * MPEG4_DEC_MAX_HEIGHT_1_TO_2_SP) > (MPEG4_DEC_MAX_WIDTH_SP * MPEG4_DEC_MAX_HEIGHT_SP))
/* under construction !*/
    #endif
    #endif  // 0
    // 1:4 vs 1:8
    #if ((MPEG4_DEC_MAX_WIDTH_1_TO_4_SP * MPEG4_DEC_MAX_HEIGHT_1_TO_4_SP) > (MPEG4_DEC_MAX_WIDTH_SP * MPEG4_DEC_MAX_HEIGHT_SP))
        #error "Please make sure MPEG4_SUPPORT_RESOLUTION_1_TO_8_SP >= MPEG4_SUPPORT_RESOLUTION_SP."
    #endif

    // MPEG4_ASP
    #if 0
/* under construction !*/
    #if (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_128x96)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_176x144)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_320x240)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_400x240)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_352x288)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_432x240)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_480x320)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_640x368)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_640x480)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_720x480)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_800x480)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_848x480)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_864x480)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_720x576)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_800x608)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_1024x768)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_1280x720)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_1280x960)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_1280x1024)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_1408x1152)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_1600x1200)
/* under construction !*/
/* under construction !*/
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_2_ASP == RESOLUTION_1920x1088)
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
    #endif
    #endif  // 0

    // 1:4
    #if (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_128x96)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      128
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     96
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_176x144)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      176
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     144
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_320x240)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      320
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     240
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_400x240)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      400
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     240
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_352x288)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      352
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     288
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_432x240)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      432
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     240
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_480x320)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      480
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     320
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_640x368)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      640
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     368
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_640x480)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      640
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     480
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_720x480)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      720
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     480
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_800x480)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      800
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     480
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_848x480)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      848
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     480
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_864x480)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      864
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     480
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_720x576)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      720
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     576
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_800x608)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      800
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     608
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_1024x768)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      1024
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     768
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_1280x720)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      1280
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     720
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_1280x960)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      1280
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     960
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_1280x1024)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      1280
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     1024
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_1408x1152)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      1408
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     1152
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_1600x1200)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      1600
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     1200
    #elif (MPEG4_SUPPORT_RESOLUTION_ASP == RESOLUTION_1920x1088)
        #define MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP      1920
        #define MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP     1088
    #else
        #error "This 1:4 resolution is not support by mpeg4 decoder ASP."
    #endif

    // 1:8
    #if (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_128x96)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_128x96_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             128
        #define MPEG4_DEC_MAX_HEIGHT_ASP            96
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_128x96_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_176x144)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_176x144_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             176
        #define MPEG4_DEC_MAX_HEIGHT_ASP            144
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_176x144_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_320x240)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_320x240_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             320
        #define MPEG4_DEC_MAX_HEIGHT_ASP            240
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_320x240_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_400x240)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_400x240_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             400
        #define MPEG4_DEC_MAX_HEIGHT_ASP            240
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_400x240_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_352x288)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_352x288_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             352
        #define MPEG4_DEC_MAX_HEIGHT_ASP            288
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_352x288_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_432x240)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_432x240_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             432
        #define MPEG4_DEC_MAX_HEIGHT_ASP            240
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_432x240_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_480x320)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_480x320_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             480
        #define MPEG4_DEC_MAX_HEIGHT_ASP            320
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_480x320_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_640x368)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_640x368_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             640
        #define MPEG4_DEC_MAX_HEIGHT_ASP            368
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_640x368_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_640x480)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_640x480_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             640
        #define MPEG4_DEC_MAX_HEIGHT_ASP            480
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_640x480_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_720x480)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_720x480_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             720
        #define MPEG4_DEC_MAX_HEIGHT_ASP            480
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_720x480_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_800x480)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_800x480_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             800
        #define MPEG4_DEC_MAX_HEIGHT_ASP            480
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_800x480_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_848x480)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_848x480_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             848
        #define MPEG4_DEC_MAX_HEIGHT_ASP            480
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_848x480_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_864x480)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_864x480_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             864
        #define MPEG4_DEC_MAX_HEIGHT_ASP            480
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_864x480_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_720x576)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_720x576_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             720
        #define MPEG4_DEC_MAX_HEIGHT_ASP            576
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_720x576_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_800x608)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_800x608_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             800
        #define MPEG4_DEC_MAX_HEIGHT_ASP            608
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_800x608_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_1024x768)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_1024x768_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             1024
        #define MPEG4_DEC_MAX_HEIGHT_ASP            768
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_1024x768_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_1280x720)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_1280x720_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             1280
        #define MPEG4_DEC_MAX_HEIGHT_ASP            720
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_1280x720_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_1280x960)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_1280x960_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             1280
        #define MPEG4_DEC_MAX_HEIGHT_ASP            960
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_1280x960_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_1280x1024)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_1280x1024_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             1280
        #define MPEG4_DEC_MAX_HEIGHT_ASP            1024
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_1280x1024_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_1408x1152)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_1408x1152_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             1408
        #define MPEG4_DEC_MAX_HEIGHT_ASP            1152
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_1408x1152_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_1600x1200)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_1600x1200_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             1600
        #define MPEG4_DEC_MAX_HEIGHT_ASP            1200
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_1600x1200_ASP
    #elif (MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP == RESOLUTION_1920x1088)
        #define MPEG4_DEC_WORKING_MEM_ASP           MP4SwDecExtSize_1920x1088_ASP
        #define MPEG4_DEC_MAX_WIDTH_ASP             1920
        #define MPEG4_DEC_MAX_HEIGHT_ASP            1088
        #define MPEG4_PREVIEW_DEC_WORKING_MEM_ASP   MP4SwDecIntraModeExtSize_1920x1088_ASP
    #else
        #error "This 1:8 resolution is not support by mpeg4 decoder ASP."
    #endif

    #if (MPEG4_DEC_WORKING_MEM_ASP == -1)
        #error "This resolution is not support by mpeg4 decoder ASP."
    #endif

    #if (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_128x96)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         128
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        96
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_176x144)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         176
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        144
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_320x240)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         320
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        240
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_400x240)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         400
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        240
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_352x288)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         352
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        288
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_432x240)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         432
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        240
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_480x320)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         480
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        320
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_640x368)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         640
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        368
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_640x480)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         640
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        480
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_720x480)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         720
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        480
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_800x480)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         800
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        480
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_848x480)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         848
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        480
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_864x480)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         864
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        480
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_720x576)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         720
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        576
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_800x608)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         800
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        608
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_1024x768)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         1024
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        768
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_1280x720)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         1280
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        720
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_1280x960)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         1280
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        960
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_1280x1024)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         1280
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        1024
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_1408x1152)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         1408
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        1152
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_1600x1200)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         1600
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        1200
    #elif (MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP == RESOLUTION_1920x1088)
        #define MPEG4_DEC_MAX_NORMAL_WIDTH_ASP         1920
        #define MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP        1088
    #else
        #error "This 1:1 resolution is not support by mpeg4 decoder ASP(Normal mode)."
    #endif

    // Check the range of ASP width and height.
    #if 0
/* under construction !*/
    #if ((MPEG4_DEC_MAX_NORMAL_WIDTH_ASP * MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP) > (MPEG4_DEC_MAX_WIDTH_1_TO_2_ASP * MPEG4_DEC_MAX_HEIGHT_1_TO_2_ASP))
/* under construction !*/
    #endif
    #endif  // 0
    // 1:1 vs 1:4
    #if ((MPEG4_DEC_MAX_NORMAL_WIDTH_ASP * MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP) > (MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP * MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP))
        #error "Please make sure MPEG4_SUPPORT_RESOLUTION_ASP >= MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP"
    #endif
    // 1:1 vs 1:8
    #if ((MPEG4_DEC_MAX_NORMAL_WIDTH_ASP * MPEG4_DEC_MAX_NORMAL_HEIGHT_ASP) > (MPEG4_DEC_MAX_WIDTH_ASP * MPEG4_DEC_MAX_HEIGHT_ASP))
        #error "Please make sure MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP >= MPEG4_MAX_NORMAL_MODE_RESOLUTION_ASP"
    #endif
    #if 0
/* under construction !*/
    #if ((MPEG4_DEC_MAX_WIDTH_1_TO_2_ASP * MPEG4_DEC_MAX_HEIGHT_1_TO_2_ASP) > (MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP * MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP))
/* under construction !*/
    #endif
/* under construction !*/
    #if ((MPEG4_DEC_MAX_WIDTH_1_TO_2_ASP * MPEG4_DEC_MAX_HEIGHT_1_TO_2_ASP) > (MPEG4_DEC_MAX_WIDTH_ASP * MPEG4_DEC_MAX_HEIGHT_ASP))
/* under construction !*/
    #endif
    #endif  // 0
    // 1:4 vs 1:8
    #if ((MPEG4_DEC_MAX_WIDTH_1_TO_4_ASP * MPEG4_DEC_MAX_HEIGHT_1_TO_4_ASP) > (MPEG4_DEC_MAX_WIDTH_ASP * MPEG4_DEC_MAX_HEIGHT_ASP))
        #error "Please make sure MPEG4_SUPPORT_RESOLUTION_1_TO_8_ASP >= MPEG4_SUPPORT_RESOLUTION_ASP"
    #endif
//#endif /* __MPEG4_DEC_SW_SUPPORT__ */


//#ifdef __H264_DEC_SW_SUPPORT__
    #if (H264_DECODER_LEVEL_BP == Level_10)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel10
    #elif (H264_DECODER_LEVEL_BP == Level_1b)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel1b
    #elif (H264_DECODER_LEVEL_BP == Level_11)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel11
    #elif (H264_DECODER_LEVEL_BP == Level_12)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel12
    #elif (H264_DECODER_LEVEL_BP == Level_13)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel13
    #elif (H264_DECODER_LEVEL_BP == Level_20)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel20
    #elif (H264_DECODER_LEVEL_BP == Level_21)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel21
    #elif (H264_DECODER_LEVEL_BP == Level_22)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel22
    #elif (H264_DECODER_LEVEL_BP == Level_30)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel30
    #elif (H264_DECODER_LEVEL_BP == Level_31)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel31
    #elif (H264_DECODER_LEVEL_BP == Level_32)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel32
    #elif (H264_DECODER_LEVEL_BP == Level_40)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel40
    #elif (H264_DECODER_LEVEL_BP == Level_41)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel41
    #elif (H264_DECODER_LEVEL_BP == Level_42)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel42
    #elif (H264_DECODER_LEVEL_BP == Level_50)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel50
    #elif (H264_DECODER_LEVEL_BP == Level_51)
        #define H264_DEC_DPB_SIZE_BP  H264SwDecLevel51
    #else
        #error "The level assigned does not exist."
    #endif

    #if (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_128x96)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_128x96_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_128x96_BP
        #define H264_DEC_MAX_WIDTH_BP     128
        #define H264_DEC_MAX_HEIGHT_BP    96
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_176x144)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_176x144_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_176x144_BP
        #define H264_DEC_MAX_WIDTH_BP     176
        #define H264_DEC_MAX_HEIGHT_BP    144
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_240x192)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_240x192_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_240x192_BP
        #define H264_DEC_MAX_WIDTH_BP     240
        #define H264_DEC_MAX_HEIGHT_BP    192
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_320x240)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_320x240_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_320x240_BP
        #define H264_DEC_MAX_WIDTH_BP     320
        #define H264_DEC_MAX_HEIGHT_BP    240
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_400x240)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_400x240_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_400x240_BP
        #define H264_DEC_MAX_WIDTH_BP     400
        #define H264_DEC_MAX_HEIGHT_BP    240
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_352x288)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_352x288_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_352x288_BP
        #define H264_DEC_MAX_WIDTH_BP     352
        #define H264_DEC_MAX_HEIGHT_BP    288
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_432x240)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_432x240_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_432x240_BP
        #define H264_DEC_MAX_WIDTH_BP     432
        #define H264_DEC_MAX_HEIGHT_BP    240
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_480x320)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_480x320_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_480x320_BP
        #define H264_DEC_MAX_WIDTH_BP     480
        #define H264_DEC_MAX_HEIGHT_BP    320
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_640x368)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_640x368_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_640x368_BP
        #define H264_DEC_MAX_WIDTH_BP     640
        #define H264_DEC_MAX_HEIGHT_BP    368
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_640x480)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_640x480_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_640x480_BP
        #define H264_DEC_MAX_WIDTH_BP     640
        #define H264_DEC_MAX_HEIGHT_BP    480
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_720x480)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_720x480_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_720x480_BP
        #define H264_DEC_MAX_WIDTH_BP     720
        #define H264_DEC_MAX_HEIGHT_BP    480
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_800x480)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_800x480_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_800x480_BP
        #define H264_DEC_MAX_WIDTH_BP     800
        #define H264_DEC_MAX_HEIGHT_BP    480
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_848x480)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_848x480_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_848x480_BP
        #define H264_DEC_MAX_WIDTH_BP     848
        #define H264_DEC_MAX_HEIGHT_BP    480
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_864x480)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_864x480_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_864x480_BP
        #define H264_DEC_MAX_WIDTH_BP     864
        #define H264_DEC_MAX_HEIGHT_BP    480
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_720x576)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_720x576_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_720x576_BP
        #define H264_DEC_MAX_WIDTH_BP     720
        #define H264_DEC_MAX_HEIGHT_BP    576
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_800x608)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_800x608_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_800x608_BP
        #define H264_DEC_MAX_WIDTH_BP     800
        #define H264_DEC_MAX_HEIGHT_BP    608
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_1024x768)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_1024x768_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1024x768_BP
        #define H264_DEC_MAX_WIDTH_BP         1024
        #define H264_DEC_MAX_HEIGHT_BP        768
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_1280x720)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_1280x720_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1280x720_BP
        #define H264_DEC_MAX_WIDTH_BP         1280
        #define H264_DEC_MAX_HEIGHT_BP        720
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_1280x960)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_1280x960_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1280x960_BP
        #define H264_DEC_MAX_WIDTH_BP         1280
        #define H264_DEC_MAX_HEIGHT_BP        960
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_1280x1024)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_1280x1024_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1280x1024_BP
        #define H264_DEC_MAX_WIDTH_BP         1280
        #define H264_DEC_MAX_HEIGHT_BP        1024
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_1408x1152)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_1408x1152_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1408x1152_BP
        #define H264_DEC_MAX_WIDTH_BP         1408
        #define H264_DEC_MAX_HEIGHT_BP        1152
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_1600x1200)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_1600x1200_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1600x1200_BP
        #define H264_DEC_MAX_WIDTH_BP         1600
        #define H264_DEC_MAX_HEIGHT_BP        1200
    #elif (H264_SUPPORT_RESOLUTION_BP == RESOLUTION_1920x1088)
        #define H264_DEC_MAX_WORKING_MEM_BP       H264SwDecExtSize_1920x1088_BP
        #define H264_DEC_MAX_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1920x1088_BP
        #define H264_DEC_MAX_WIDTH_BP         1920
        #define H264_DEC_MAX_HEIGHT_BP        1088
    #else
        #error "This resolution is not support by H264 decoder (BP , Normal mode)."
    #endif

    #if (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_128x96)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_128x96_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_128x96_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     128
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    96
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_176x144)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_176x144_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_176x144_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     176
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    144
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_240x192)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_240x192_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_240x192_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     240
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    192
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_320x240)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_320x240_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_320x240_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     320
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    240
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_400x240)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_400x240_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_400x240_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     400
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    240
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_352x288)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_352x288_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_352x288_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     352
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    288
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_432x240)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_432x240_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_432x240_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     432
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    240
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_480x320)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_480x320_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_480x320_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     480
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    320
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_640x368)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_640x368_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_640x368_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     640
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    368
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_640x480)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_640x480_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_640x480_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     640
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    480
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_720x480)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_720x480_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_720x480_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     720
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    480
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_800x480)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_800x480_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_800x480_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     800
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    480
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_848x480)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_848x480_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_848x480_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     848
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    480
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_864x480)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_864x480_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_864x480_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     864
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    480
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_720x576)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_720x576_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_720x576_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     720
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    576
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_800x608)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_800x608_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_800x608_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP     800
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP    608
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_1024x768)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_1024x768_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1024x768_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP         1024
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP        768
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_1280x720)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_1280x720_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1280x720_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP         1280
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP        720
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_1280x960)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_1280x960_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1280x960_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP         1280
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP        960
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_1280x1024)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_1280x1024_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1280x1024_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP         1280
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP        1024
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_1408x1152)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_1408x1152_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1408x1152_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP         1408
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP        1152
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_1600x1200)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_1600x1200_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1600x1200_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP         1600
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP        1200
    #elif (H264_MAX_NORMAL_MODE_RESOLUTION_BP == RESOLUTION_1920x1088)
        #define H264_DEC_MAX_NORAL_WORKING_MEM_BP       H264SwDecExtSize_1920x1088_BP
        #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_BP   H264SwDecIntraModeExtSize_1920x1088_BP
        #define H264_DEC_MAX_NORMAL_WIDTH_BP         1920
        #define H264_DEC_MAX_NORMAL_HEIGHT_BP        1088
    #else
        #error "This resolution is not support by H264 decoder (BP , Normal mode)."
    #endif

    //#if (H264_MAX_NORMAL_MODE_RESOLUTION_BP > H264_SUPPORT_RESOLUTION_BP)
    #if ((H264_DEC_MAX_NORMAL_WIDTH_BP * H264_DEC_MAX_NORMAL_HEIGHT_BP) > (H264_DEC_MAX_WIDTH_BP * H264_DEC_MAX_HEIGHT_BP))
        #error "Please make sure H264_SUPPORT_RESOLUTION_BP is higher than H264_MAX_NORMAL_MODE_RESOLUTION_BP."
    #endif

    //#ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
     #if 1
        #if (H264_DECODER_LEVEL_MPHP == Level_10)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel10
        #elif (H264_DECODER_LEVEL_MPHP == Level_1b)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel1b
        #elif (H264_DECODER_LEVEL_MPHP == Level_11)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel11
        #elif (H264_DECODER_LEVEL_MPHP == Level_12)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel12
        #elif (H264_DECODER_LEVEL_MPHP == Level_13)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel13
        #elif (H264_DECODER_LEVEL_MPHP == Level_20)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel20
        #elif (H264_DECODER_LEVEL_MPHP == Level_21)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel21
        #elif (H264_DECODER_LEVEL_MPHP == Level_22)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel22
        #elif (H264_DECODER_LEVEL_MPHP == Level_30)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel30
        #elif (H264_DECODER_LEVEL_MPHP == Level_31)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel31
        #elif (H264_DECODER_LEVEL_MPHP == Level_32)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel32
        #elif (H264_DECODER_LEVEL_MPHP == Level_40)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel40
        #elif (H264_DECODER_LEVEL_MPHP == Level_41)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel41
        #elif (H264_DECODER_LEVEL_MPHP == Level_42)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel42
        #elif (H264_DECODER_LEVEL_MPHP == Level_50)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel50
        #elif (H264_DECODER_LEVEL_MPHP == Level_51)
            #define H264_DEC_DPB_SIZE_MPHP  H264SwDecLevel51
        #else
            #error "The level assigned does not exist."
        #endif

        #if (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_128x96)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_128x96_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_128x96_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             128
            #define H264_DEC_MAX_HEIGHT_MPHP            96
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_176x144)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_176x144_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_176x144_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             176
            #define H264_DEC_MAX_HEIGHT_MPHP            144
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_240x192)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_240x192_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_240x192_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             240
            #define H264_DEC_MAX_HEIGHT_MPHP            192
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_320x240)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_320x240_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_320x240_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             320
            #define H264_DEC_MAX_HEIGHT_MPHP            240
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_400x240)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_400x240_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_400x240_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             400
            #define H264_DEC_MAX_HEIGHT_MPHP            240
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_352x288)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_352x288_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_352x288_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             352
            #define H264_DEC_MAX_HEIGHT_MPHP            288
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_432x240)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_432x240_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_432x240_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             432
            #define H264_DEC_MAX_HEIGHT_MPHP            240
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_480x320)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_480x320_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_480x320_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             480
            #define H264_DEC_MAX_HEIGHT_MPHP            320
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_640x368)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_640x368_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_640x368_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             640
            #define H264_DEC_MAX_HEIGHT_MPHP            368
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_640x480)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_640x480_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_640x480_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             640
            #define H264_DEC_MAX_HEIGHT_MPHP            480
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_720x480)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_720x480_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_720x480_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             720
            #define H264_DEC_MAX_HEIGHT_MPHP            480
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_800x480)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_800x480_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_800x480_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             800
            #define H264_DEC_MAX_HEIGHT_MPHP            480
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_848x480)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_848x480_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_848x480_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             848
            #define H264_DEC_MAX_HEIGHT_MPHP            480
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_864x480)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_864x480_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_864x480_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             864
            #define H264_DEC_MAX_HEIGHT_MPHP            480
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_720x576)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_720x576_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_720x576_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             720
            #define H264_DEC_MAX_HEIGHT_MPHP            576
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_800x608)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_800x608_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_800x608_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             800
            #define H264_DEC_MAX_HEIGHT_MPHP            608
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_1024x768)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_1024x768_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_1024x768_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             1024
            #define H264_DEC_MAX_HEIGHT_MPHP            768
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_1280x720)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_1280x720_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_1280x720_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             1280
            #define H264_DEC_MAX_HEIGHT_MPHP            720
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_1280x960)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_1280x960_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_1280x960_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             1280
            #define H264_DEC_MAX_HEIGHT_MPHP            960
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_1280x1024)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_1280x1024_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_1280x1024_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             1280
            #define H264_DEC_MAX_HEIGHT_MPHP            1024
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_1408x1152)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_1408x1152_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_1408x1152_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             1408
            #define H264_DEC_MAX_HEIGHT_MPHP            1152
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_1600x1200)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_1600x1200_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_1600x1200_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             1600
            #define H264_DEC_MAX_HEIGHT_MPHP            1200
        #elif (H264_SUPPORT_RESOLUTION_MPHP == RESOLUTION_1920x1088)
            #define H264_DEC_MAX_WORKING_MEM_MPHP       H264SwDecExtSize_1920x1088_MPHP
            #define H264_DEC_MAX_WORKING_PREVMEM_MPHP   H264SwDecIntraModeExtSize_1920x1088_MPHP
            #define H264_DEC_MAX_WIDTH_MPHP             1920
            #define H264_DEC_MAX_HEIGHT_MPHP            1088
        #else
            #error "This resolution is not support by H264 decoder (MPHP , Normal mode)"
        #endif

        #if (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_128x96)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_128x96_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_128x96_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          128
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         96
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_176x144)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_176x144_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_176x144_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          176
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         144
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_240x192)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_240x192_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_240x192_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          240
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         192
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_320x240)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_320x240_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_320x240_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          320
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         240
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_400x240)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_400x240_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_400x240_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          400
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         240
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_352x288)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_352x288_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_352x288_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          352
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         288
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_432x240)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_432x240_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_432x240_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          432
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         240
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_480x320)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_480x320_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_480x320_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          480
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         320
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_640x368)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_640x368_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_640x368_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          640
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         368
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_640x480)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_640x480_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_640x480_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          640
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         480
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_720x480)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_720x480_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_720x480_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          720
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         480
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_800x480)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_800x480_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_800x480_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          800
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         480
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_848x480)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_848x480_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_848x480_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          848
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         480
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_864x480)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_864x480_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_864x480_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          864
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         480
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_720x576)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_720x576_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_720x576_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          720
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         576
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_800x608)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_800x608_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_800x608_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          800
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         608
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_1024x768)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_1024x768_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_1024x768_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          1024
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         768
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_1280x720)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_1280x720_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_1280x720_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          1280
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         720
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_1280x960)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_1280x960_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_1280x960_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          1280
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         960
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_1280x1024)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_1280x1024_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_1280x1024_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          1280
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         1024
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_1408x1152)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_1408x1152_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_1408x1152_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          1408
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         1152
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_1600x1200)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_1600x1200_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_1600x1200_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          1600
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         1200
        #elif (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP == RESOLUTION_1920x1088)
            #define H264_DEC_MAX_NORAL_WORKING_MEM_MPHP     H264SwDecExtSize_1920x1088_MPHP
            #define H264_DEC_MAX_NORAL_WORKING_PREVMEM_MPHP H264SwDecIntraModeExtSize_1920x1088_MPHP
            #define H264_DEC_MAX_NORMAL_WIDTH_MPHP          1920
            #define H264_DEC_MAX_NORMAL_HEIGHT_MPHP         1088
        #else
            #error "This resolution is not support by H264 decoder (MPHP , Normal mode)"
        #endif

        //#if (H264_MAX_NORMAL_MODE_RESOLUTION_MPHP > H264_SUPPORT_RESOLUTION_MPHP)
        #if ((H264_DEC_MAX_NORMAL_WIDTH_MPHP * H264_DEC_MAX_NORMAL_HEIGHT_MPHP) > (H264_DEC_MAX_WIDTH_MPHP * H264_DEC_MAX_HEIGHT_MPHP))
            #error "Please make sure H264_SUPPORT_RESOLUTION_MPHP is higher than H264_MAX_NORMAL_MODE_RESOLUTION_MPHP"
        #endif
    #endif //#ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
//#endif /*__H264_DEC_SW_SUPPORT__*/


#ifdef __RV_DEC_SW_SUPPORT__
    #if (RV9_SUPPORT_RESOLUTION == RESOLUTION_128x96)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_128x96
        #define RV9_DEC_MAX_WIDTH               128
        #define RV9_DEC_MAX_HEIGHT              96
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_128x96
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_176x144)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_176x144
        #define RV9_DEC_MAX_WIDTH               176
        #define RV9_DEC_MAX_HEIGHT              144
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_176x144
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_320x240)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_320x240
        #define RV9_DEC_MAX_WIDTH               320
        #define RV9_DEC_MAX_HEIGHT              240
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_320x240
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_400x240)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_400x240
        #define RV9_DEC_MAX_WIDTH               400
        #define RV9_DEC_MAX_HEIGHT              240
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_400x240
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_352x288)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_352x288
        #define RV9_DEC_MAX_WIDTH               352
        #define RV9_DEC_MAX_HEIGHT              288
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_352x288
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_432x240)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_432x240
        #define RV9_DEC_MAX_WIDTH               432
        #define RV9_DEC_MAX_HEIGHT              240
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_432x240
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_480x320)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_480x320
        #define RV9_DEC_MAX_WIDTH               480
        #define RV9_DEC_MAX_HEIGHT              320
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_480x320
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_640x368)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_640x368
        #define RV9_DEC_MAX_WIDTH               640
        #define RV9_DEC_MAX_HEIGHT              368
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_640x368
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_640x480)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_640x480
        #define RV9_DEC_MAX_WIDTH               640
        #define RV9_DEC_MAX_HEIGHT              480
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_640x480
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_720x480)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_720x480
        #define RV9_DEC_MAX_WIDTH               720
        #define RV9_DEC_MAX_HEIGHT              480
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_720x480
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_800x480)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_800x480
        #define RV9_DEC_MAX_WIDTH               800
        #define RV9_DEC_MAX_HEIGHT              480
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_800x480
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_848x480)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_848x480
        #define RV9_DEC_MAX_WIDTH               848
        #define RV9_DEC_MAX_HEIGHT              480
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_848x480
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_720x576)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_720x576
        #define RV9_DEC_MAX_WIDTH               720
        #define RV9_DEC_MAX_HEIGHT              576
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_720x576
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_800x608)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_800x608
        #define RV9_DEC_MAX_WIDTH               800
        #define RV9_DEC_MAX_HEIGHT              608
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_800x608
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_1024x768)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_1024x768
        #define RV9_DEC_MAX_WIDTH               1024
        #define RV9_DEC_MAX_HEIGHT              768
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_1024x768
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_1280x720)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_1280x720
        #define RV9_DEC_MAX_WIDTH               1280
        #define RV9_DEC_MAX_HEIGHT              720
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_1280x720
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_1280x960)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_1280x960
        #define RV9_DEC_MAX_WIDTH               1280
        #define RV9_DEC_MAX_HEIGHT              960
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_1280x960
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_1280x1024)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_1280x1024
        #define RV9_DEC_MAX_WIDTH               1280
        #define RV9_DEC_MAX_HEIGHT              1024
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_1280x1024
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_1408x1152)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_1408x1152
        #define RV9_DEC_MAX_WIDTH               1408
        #define RV9_DEC_MAX_HEIGHT              1152
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_1408x1152
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_1600x1200)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_1600x1200
        #define RV9_DEC_MAX_WIDTH               1600
        #define RV9_DEC_MAX_HEIGHT              1200
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_1600x1200
    #elif (RV9_SUPPORT_RESOLUTION == RESOLUTION_1920x1088)
        #define RV9_DEC_WORKING_MEM             RVSwDecExtSize_1920x1088
        #define RV9_DEC_MAX_WIDTH               1920
        #define RV9_DEC_MAX_HEIGHT              1088
        #define RV9_PREVIEW_DEC_WORKING_MEM     RVSwDecIntraModeExtSize_1920x1088
    #else
        #error "This resolution is not support by RV9 decoder"
    #endif

    #if (RV9_DEC_WORKING_MEM == -1)
        #error "This resolution is not support by RV9 decoder"
    #endif

    #if (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_128x96)
        #define RV9_DEC_MAX_NORMAL_WIDTH         128
        #define RV9_DEC_MAX_NORMAL_HEIGHT        96
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_176x144)
        #define RV9_DEC_MAX_NORMAL_WIDTH         176
        #define RV9_DEC_MAX_NORMAL_HEIGHT        144
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_320x240)
        #define RV9_DEC_MAX_NORMAL_WIDTH         320
        #define RV9_DEC_MAX_NORMAL_HEIGHT        240
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_400x240)
        #define RV9_DEC_MAX_NORMAL_WIDTH         400
        #define RV9_DEC_MAX_NORMAL_HEIGHT        240
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_352x288)
        #define RV9_DEC_MAX_NORMAL_WIDTH         352
        #define RV9_DEC_MAX_NORMAL_HEIGHT        288
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_432x240)
        #define RV9_DEC_MAX_NORMAL_WIDTH         432
        #define RV9_DEC_MAX_NORMAL_HEIGHT        240
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_480x320)
        #define RV9_DEC_MAX_NORMAL_WIDTH         480
        #define RV9_DEC_MAX_NORMAL_HEIGHT        320
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_640x368)
        #define RV9_DEC_MAX_NORMAL_WIDTH         640
        #define RV9_DEC_MAX_NORMAL_HEIGHT        368
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_640x480)
        #define RV9_DEC_MAX_NORMAL_WIDTH         640
        #define RV9_DEC_MAX_NORMAL_HEIGHT        480
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_720x480)
        #define RV9_DEC_MAX_NORMAL_WIDTH         720
        #define RV9_DEC_MAX_NORMAL_HEIGHT        480
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_800x480)
        #define RV9_DEC_MAX_NORMAL_WIDTH         800
        #define RV9_DEC_MAX_NORMAL_HEIGHT        480
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_848x480)
        #define RV9_DEC_MAX_NORMAL_WIDTH         848
        #define RV9_DEC_MAX_NORMAL_HEIGHT        480
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_720x576)
        #define RV9_DEC_MAX_NORMAL_WIDTH         720
        #define RV9_DEC_MAX_NORMAL_HEIGHT        576
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_800x608)
        #define RV9_DEC_MAX_NORMAL_WIDTH         800
        #define RV9_DEC_MAX_NORMAL_HEIGHT        608
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1024x768)
        #define RV9_DEC_MAX_NORMAL_WIDTH         1024
        #define RV9_DEC_MAX_NORMAL_HEIGHT        768
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1280x720)
        #define RV9_DEC_MAX_NORMAL_WIDTH         1280
        #define RV9_DEC_MAX_NORMAL_HEIGHT        720
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1280x960)
        #define RV9_DEC_MAX_NORMAL_WIDTH         1280
        #define RV9_DEC_MAX_NORMAL_HEIGHT        960
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1280x1024)
        #define RV9_DEC_MAX_NORMAL_WIDTH         1280
        #define RV9_DEC_MAX_NORMAL_HEIGHT        1024
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1408x1152)
        #define RV9_DEC_MAX_NORMAL_WIDTH         1408
        #define RV9_DEC_MAX_NORMAL_HEIGHT        1152
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1600x1200)
        #define RV9_DEC_MAX_NORMAL_WIDTH         1600
        #define RV9_DEC_MAX_NORMAL_HEIGHT        1200
    #elif (RV9_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1920x1088)
        #define RV9_DEC_MAX_NORMAL_WIDTH         1920
        #define RV9_DEC_MAX_NORMAL_HEIGHT        1088
    #else
        #error "This resolution is not support by RV9 decoder (Normal mode)"
    #endif

    //#if (RV9_MAX_NORMAL_MODE_RESOLUTION > RV9_SUPPORT_RESOLUTION)
    #if ((RV9_DEC_MAX_NORMAL_WIDTH * RV9_DEC_MAX_NORMAL_HEIGHT) > (RV9_DEC_MAX_WIDTH * RV9_DEC_MAX_HEIGHT))
        #error "Please make sure RV9_MAX_NORMAL_MODE_RESOLUTION is higher than RV9_SUPPORT_RESOLUTION"
    #endif
#endif /*__RV_DEC_SW_SUPPORT__*/


#ifdef __MJPEG_DEC_SW_SUPPORT__
    #if (MJPEG_SUPPORT_RESOLUTION == RESOLUTION_128x96)
        #define MJPEG_DEC_WORKING_MEM           JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE
        #define MJPEG_DEC_MAX_WIDTH             128
        #define MJPEG_DEC_MAX_HEIGHT            96
        #define MJPEG_PREVIEW_DEC_WORKING_MEM   MJPEG_DEC_WORKING_MEM
    #elif (MJPEG_SUPPORT_RESOLUTION == RESOLUTION_176x144)
        #define MJPEG_DEC_WORKING_MEM           JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE
        #define MJPEG_DEC_MAX_WIDTH             176
        #define MJPEG_DEC_MAX_HEIGHT            144
        #define MJPEG_PREVIEW_DEC_WORKING_MEM   MJPEG_DEC_WORKING_MEM
    #elif (MJPEG_SUPPORT_RESOLUTION == RESOLUTION_320x240)
        #define MJPEG_DEC_WORKING_MEM           JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE
        #define MJPEG_DEC_MAX_WIDTH             320
        #define MJPEG_DEC_MAX_HEIGHT            240
        #define MJPEG_PREVIEW_DEC_WORKING_MEM   MJPEG_DEC_WORKING_MEM
    #elif (MJPEG_SUPPORT_RESOLUTION == RESOLUTION_352x288)
        #define MJPEG_DEC_WORKING_MEM           JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE
        #define MJPEG_DEC_MAX_WIDTH             352
        #define MJPEG_DEC_MAX_HEIGHT            288
        #define MJPEG_PREVIEW_DEC_WORKING_MEM   MJPEG_DEC_WORKING_MEM
    #elif (MJPEG_SUPPORT_RESOLUTION == RESOLUTION_480x320)
        #define MJPEG_DEC_WORKING_MEM           JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE
        #define MJPEG_DEC_MAX_WIDTH             480
        #define MJPEG_DEC_MAX_HEIGHT            320
        #define MJPEG_PREVIEW_DEC_WORKING_MEM   MJPEG_DEC_WORKING_MEM
    #elif (MJPEG_SUPPORT_RESOLUTION == RESOLUTION_640x480)
        #define MJPEG_DEC_WORKING_MEM           JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE
        #define MJPEG_DEC_MAX_WIDTH             640
        #define MJPEG_DEC_MAX_HEIGHT            480
        #define MJPEG_PREVIEW_DEC_WORKING_MEM   MJPEG_DEC_WORKING_MEM
    #elif (MJPEG_SUPPORT_RESOLUTION == RESOLUTION_848x480)
        #define MJPEG_DEC_WORKING_MEM           JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE
        #define MJPEG_DEC_MAX_WIDTH             848
        #define MJPEG_DEC_MAX_HEIGHT            480
        #define MJPEG_PREVIEW_DEC_WORKING_MEM   MJPEG_DEC_WORKING_MEM
    #elif (MJPEG_SUPPORT_RESOLUTION == RESOLUTION_1280x720)
        #define MJPEG_DEC_WORKING_MEM           JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE
        #define MJPEG_DEC_MAX_WIDTH             1280
        #define MJPEG_DEC_MAX_HEIGHT            720
        #define MJPEG_PREVIEW_DEC_WORKING_MEM   MJPEG_DEC_WORKING_MEM
    #elif (MJPEG_SUPPORT_RESOLUTION == RESOLUTION_1920x1088)
        #define MJPEG_DEC_WORKING_MEM           JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE
        #define MJPEG_DEC_MAX_WIDTH             1920
        #define MJPEG_DEC_MAX_HEIGHT            1088
        #define MJPEG_PREVIEW_DEC_WORKING_MEM   MJPEG_DEC_WORKING_MEM
    #else
        #error "This resolution is not support by MJPEG decoder (SW decoder)"
    #endif

    #if (MJPEG_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_128x96)
        #define MJPEG_DEC_MAX_NORMAL_WIDTH         128
        #define MJPEG_DEC_MAX_NORMAL_HEIGHT        96
    #elif (MJPEG_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_176x144)
        #define MJPEG_DEC_MAX_NORMAL_WIDTH         176
        #define MJPEG_DEC_MAX_NORMAL_HEIGHT        144
    #elif (MJPEG_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_320x240)
        #define MJPEG_DEC_MAX_NORMAL_WIDTH         320
        #define MJPEG_DEC_MAX_NORMAL_HEIGHT        240
    #elif (MJPEG_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_352x288)
        #define MJPEG_DEC_MAX_NORMAL_WIDTH         352
        #define MJPEG_DEC_MAX_NORMAL_HEIGHT        288
    #elif (MJPEG_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_480x320)
        #define MJPEG_DEC_MAX_NORMAL_WIDTH         480
        #define MJPEG_DEC_MAX_NORMAL_HEIGHT        320
    #elif (MJPEG_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_640x480)
        #define MJPEG_DEC_MAX_NORMAL_WIDTH         640
        #define MJPEG_DEC_MAX_NORMAL_HEIGHT        480
    #elif (MJPEG_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_848x480)
        #define MJPEG_DEC_MAX_NORMAL_WIDTH         848
        #define MJPEG_DEC_MAX_NORMAL_HEIGHT        480
    #elif (MJPEG_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1280x720)
        #define MJPEG_DEC_MAX_NORMAL_WIDTH         1280
        #define MJPEG_DEC_MAX_NORMAL_HEIGHT        720
    #elif (MJPEG_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1920x1088)
        #define MJPEG_DEC_MAX_NORMAL_WIDTH         1920
        #define MJPEG_DEC_MAX_NORMAL_HEIGHT        1088
    #else
        #error "This resolution is not support by MJPEG decoder (SW decoder)"
    #endif

    #if (MJPEG_MAX_QTY_MODE_RESOLUTION == RESOLUTION_128x96)
        #define MJPEG_DEC_MAX_QTY_WIDTH         128
        #define MJPEG_DEC_MAX_QTY_HEIGHT        96
    #elif (MJPEG_MAX_QTY_MODE_RESOLUTION == RESOLUTION_176x144)
        #define MJPEG_DEC_MAX_QTY_WIDTH         176
        #define MJPEG_DEC_MAX_QTY_HEIGHT        144
    #elif (MJPEG_MAX_QTY_MODE_RESOLUTION == RESOLUTION_320x240)
        #define MJPEG_DEC_MAX_QTY_WIDTH         320
        #define MJPEG_DEC_MAX_QTY_HEIGHT        240
    #elif (MJPEG_MAX_QTY_MODE_RESOLUTION == RESOLUTION_352x288)
        #define MJPEG_DEC_MAX_QTY_WIDTH         352
        #define MJPEG_DEC_MAX_QTY_HEIGHT        288
    #elif (MJPEG_MAX_QTY_MODE_RESOLUTION == RESOLUTION_480x320)
        #define MJPEG_DEC_MAX_QTY_WIDTH         480
        #define MJPEG_DEC_MAX_QTY_HEIGHT        320
    #elif (MJPEG_MAX_QTY_MODE_RESOLUTION == RESOLUTION_640x480)
        #define MJPEG_DEC_MAX_QTY_WIDTH         640
        #define MJPEG_DEC_MAX_QTY_HEIGHT        480
    #elif (MJPEG_MAX_QTY_MODE_RESOLUTION == RESOLUTION_848x480)
        #define MJPEG_DEC_MAX_QTY_WIDTH         848
        #define MJPEG_DEC_MAX_QTY_HEIGHT        480
    #elif (MJPEG_MAX_QTY_MODE_RESOLUTION == RESOLUTION_1280x720)
        #define MJPEG_DEC_MAX_QTY_WIDTH         1280
        #define MJPEG_DEC_MAX_QTY_HEIGHT        720
    #elif (MJPEG_MAX_QTY_MODE_RESOLUTION == RESOLUTION_1920x1088)
        #define MJPEG_DEC_MAX_QTY_WIDTH         1920
        #define MJPEG_DEC_MAX_QTY_HEIGHT        1088
    #else
        #error "This resolution is not support by MJPEG decoder (SW decoder)"
    #endif
#endif /*__MJPEG_DEC_SW_SUPPORT__*/


//#ifdef __VP8_DEC_SW_SUPPORT__
    #if (VP8_SUPPORT_RESOLUTION == RESOLUTION_128x96)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_128x96
        #define VP8_DEC_MAX_WIDTH               128
        #define VP8_DEC_MAX_HEIGHT              96
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_128x96
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_176x144)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_176x144
        #define VP8_DEC_MAX_WIDTH               176
        #define VP8_DEC_MAX_HEIGHT              144
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_176x144
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_240x192)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_240x192
        #define VP8_DEC_MAX_WIDTH               240
        #define VP8_DEC_MAX_HEIGHT              192
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_240x192
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_320x240)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_320x240
        #define VP8_DEC_MAX_WIDTH               320
        #define VP8_DEC_MAX_HEIGHT              240
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_320x240
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_400x240)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_400x240
        #define VP8_DEC_MAX_WIDTH               400
        #define VP8_DEC_MAX_HEIGHT              240
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_400x240
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_352x288)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_352x288
        #define VP8_DEC_MAX_WIDTH               352
        #define VP8_DEC_MAX_HEIGHT              288
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_352x288
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_432x240)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_432x240
        #define VP8_DEC_MAX_WIDTH               432
        #define VP8_DEC_MAX_HEIGHT              240
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_432x240
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_480x320)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_480x320
        #define VP8_DEC_MAX_WIDTH               480
        #define VP8_DEC_MAX_HEIGHT              320
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_480x320
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_640x368)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_640x368
        #define VP8_DEC_MAX_WIDTH               640
        #define VP8_DEC_MAX_HEIGHT              368
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_640x368
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_640x480)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_640x480
        #define VP8_DEC_MAX_WIDTH               640
        #define VP8_DEC_MAX_HEIGHT              480
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_640x480
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_720x480)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_720x480
        #define VP8_DEC_MAX_WIDTH               720
        #define VP8_DEC_MAX_HEIGHT              480
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_720x480
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_800x480)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_800x480
        #define VP8_DEC_MAX_WIDTH               800
        #define VP8_DEC_MAX_HEIGHT              480
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_800x480
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_848x480)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_848x480
        #define VP8_DEC_MAX_WIDTH               848
        #define VP8_DEC_MAX_HEIGHT              480
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_848x480
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_720x576)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_720x576
        #define VP8_DEC_MAX_WIDTH               720
        #define VP8_DEC_MAX_HEIGHT              576
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_720x576
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_800x608)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_800x608
        #define VP8_DEC_MAX_WIDTH               800
        #define VP8_DEC_MAX_HEIGHT              608
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_800x608
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_1024x768)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_1024x768
        #define VP8_DEC_MAX_WIDTH               1024
        #define VP8_DEC_MAX_HEIGHT              768
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_1024x768
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_1280x720)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_1280x720
        #define VP8_DEC_MAX_WIDTH               1280
        #define VP8_DEC_MAX_HEIGHT              720
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_1280x720
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_1280x960)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_1280x960
        #define VP8_DEC_MAX_WIDTH               1280
        #define VP8_DEC_MAX_HEIGHT              960
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_1280x960
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_1280x1024)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_1280x1024
        #define VP8_DEC_MAX_WIDTH               1280
        #define VP8_DEC_MAX_HEIGHT              1024
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_1280x1024
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_1408x1152)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_1408x1152
        #define VP8_DEC_MAX_WIDTH               1408
        #define VP8_DEC_MAX_HEIGHT              1152
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_1408x1152
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_1600x1200)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_1600x1200
        #define VP8_DEC_MAX_WIDTH               1600
        #define VP8_DEC_MAX_HEIGHT              1200
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_1600x1200
    #elif (VP8_SUPPORT_RESOLUTION == RESOLUTION_1920x1088)
        #define VP8_DEC_WORKING_MEM             VP8SwDecExtSize_1920x1088
        #define VP8_DEC_MAX_WIDTH               1920
        #define VP8_DEC_MAX_HEIGHT              1088
        #define VP8_PREVIEW_DEC_WORKING_MEM     VP8SwDecIntraModeExtSize_1920x1088
    #else
        #error "This resolution is not support by VP8 decoder"
    #endif

    #if (VP8_DEC_WORKING_MEM == -1)
        #error "This resolution is not support by VP8 decoder"
    #endif

    #if (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_128x96)
        #define VP8_DEC_MAX_NORMAL_WIDTH         128
        #define VP8_DEC_MAX_NORMAL_HEIGHT        96
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_176x144)
        #define VP8_DEC_MAX_NORMAL_WIDTH         176
        #define VP8_DEC_MAX_NORMAL_HEIGHT        144
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_240x192)
        #define VP8_DEC_MAX_NORMAL_WIDTH         240
        #define VP8_DEC_MAX_NORMAL_HEIGHT        192
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_320x240)
        #define VP8_DEC_MAX_NORMAL_WIDTH         320
        #define VP8_DEC_MAX_NORMAL_HEIGHT        240
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_400x240)
        #define VP8_DEC_MAX_NORMAL_WIDTH         400
        #define VP8_DEC_MAX_NORMAL_HEIGHT        240
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_352x288)
        #define VP8_DEC_MAX_NORMAL_WIDTH         352
        #define VP8_DEC_MAX_NORMAL_HEIGHT        288
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_432x240)
        #define VP8_DEC_MAX_NORMAL_WIDTH         432
        #define VP8_DEC_MAX_NORMAL_HEIGHT        240
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_480x320)
        #define VP8_DEC_MAX_NORMAL_WIDTH         480
        #define VP8_DEC_MAX_NORMAL_HEIGHT        320
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_640x368)
        #define VP8_DEC_MAX_NORMAL_WIDTH         640
        #define VP8_DEC_MAX_NORMAL_HEIGHT        368
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_640x480)
        #define VP8_DEC_MAX_NORMAL_WIDTH         640
        #define VP8_DEC_MAX_NORMAL_HEIGHT        480
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_720x480)
        #define VP8_DEC_MAX_NORMAL_WIDTH         720
        #define VP8_DEC_MAX_NORMAL_HEIGHT        480
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_800x480)
        #define VP8_DEC_MAX_NORMAL_WIDTH         800
        #define VP8_DEC_MAX_NORMAL_HEIGHT        480
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_848x480)
        #define VP8_DEC_MAX_NORMAL_WIDTH         848
        #define VP8_DEC_MAX_NORMAL_HEIGHT        480
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_720x576)
        #define VP8_DEC_MAX_NORMAL_WIDTH         720
        #define VP8_DEC_MAX_NORMAL_HEIGHT        576
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_800x608)
        #define VP8_DEC_MAX_NORMAL_WIDTH         800
        #define VP8_DEC_MAX_NORMAL_HEIGHT        608
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1024x768)
        #define VP8_DEC_MAX_NORMAL_WIDTH         1024
        #define VP8_DEC_MAX_NORMAL_HEIGHT        768
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1280x720)
        #define VP8_DEC_MAX_NORMAL_WIDTH         1280
        #define VP8_DEC_MAX_NORMAL_HEIGHT        720
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1280x960)
        #define VP8_DEC_MAX_NORMAL_WIDTH         1280
        #define VP8_DEC_MAX_NORMAL_HEIGHT        960
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1280x1024)
        #define VP8_DEC_MAX_NORMAL_WIDTH         1280
        #define VP8_DEC_MAX_NORMAL_HEIGHT        1024
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1408x1152)
        #define VP8_DEC_MAX_NORMAL_WIDTH         1408
        #define VP8_DEC_MAX_NORMAL_HEIGHT        1152
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1600x1200)
        #define VP8_DEC_MAX_NORMAL_WIDTH         1600
        #define VP8_DEC_MAX_NORMAL_HEIGHT        1200
    #elif (VP8_MAX_NORMAL_MODE_RESOLUTION == RESOLUTION_1920x1088)
        #define VP8_DEC_MAX_NORMAL_WIDTH         1920
        #define VP8_DEC_MAX_NORMAL_HEIGHT        1088
    #else
        #error "This resolution is not support by VP8 decoder (Normal mode)"
    #endif

    //#if (VP8_MAX_NORMAL_MODE_RESOLUTION > VP8_SUPPORT_RESOLUTION)
    #if ((VP8_DEC_MAX_NORMAL_WIDTH * VP8_DEC_MAX_NORMAL_HEIGHT) > (VP8_DEC_MAX_WIDTH * VP8_DEC_MAX_HEIGHT))
        #error "Please make sure VP8_MAX_NORMAL_MODE_RESOLUTION is higher than VP8_SUPPORT_RESOLUTION"
    #endif
//#endif /*__VP8_DEC_SW_SUPPORT__*/

#endif /* !MT6268 */
#endif /* __VIDEO_ARCHI_V2__ */
#endif /* VIDEO_CODEC_MEM_CUSTOM_V2_H */

