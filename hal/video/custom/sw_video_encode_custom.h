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
 *   sw_video_encode_custom_v2.h
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
 *
 ****************************************************************************/

#ifndef SW_VIDEO_ENC0DE_CUSTOM_H
#define SW_VIDEO_ENC0DE_CUSTOM_H

#include "drv_comm.h"
#ifdef __VIDEO_ARCHI_V2__
#include "drv_features.h"
#include "video_codec_custom_type.h"
#include "hal_custom_video_if.h"

#ifdef __MPEG4_ENC_SW_SUPPORT__
    #include "MP4SwEncMem.h"
#endif

#ifdef __MJPEG_ENC_SUPPORT__
    #include "jpeg_mjpeg_mem.h"
#endif	//__MJPEG_ENC_SUPPORT__

#if defined(MT6255)
   #include "custom_emi_release.h"
#endif

/***********************************************************************
*
*   Custom settings of
*   - The numbers of frame buffer
*   - Maximum resolution supported
*   - The size of bitstream buffer
*
***********************************************************************/

/******************************************************************************
* One example to explaing the definitions of the following settings
* 
*    This value defines the extra number of YUV frames at the highest
*    resolution.
*    #define MPEG4_ENC_EXTRA_YUV_FRAME_NUM       2
*
*    This is the size of the bit-stream buffer.
*    Default size: 192 KB
*    #define MPEG4_ENC_BIT_BUFFER_SIZE           196608
*
*    Set the maximum resolution supported by the encoder
*    #define MPEG4_ENC_SUPPORT_RESOLUTION    RESOLUTION_720x480
*
******************************************************************************/

/******************************************************************************
* Setting for MT6236 series
******************************************************************************/
#if (defined(MT6236) || defined(MT6236B))
    #if defined(MT6921)
        #ifdef __MPEG4_ENC_SW_SUPPORT__
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_320x240
        #endif  // __MPEG4_ENC_SW_SUPPORT__
    #else
        #ifdef __MPEG4_ENC_SW_SUPPORT__
            #ifdef __VIDEO_ENC_D1_SUPPORT__
                #define MPEG4_ENC_SUPPORT_RESOLUTION    RESOLUTION_720x480
            #else
                #define MPEG4_ENC_SUPPORT_RESOLUTION    RESOLUTION_480x320
            #endif  // __VIDEO_ENC_D1_SUPPORT__
        #endif  // __MPEG4_ENC_SW_SUPPORT__
    
        #ifdef __MJPEG_ENC_SUPPORT__
            #define MJPEG_ENC_SUPPORT_RESOLUTION        RESOLUTION_480x320
        #endif //__MJPEG_ENC_SUPPORT__
    #endif // defined(MT6921)
#endif  // (defined(MT6236) || defined(MT6236B))


/******************************************************************************
* Setting for MT6255 series
******************************************************************************/
#if defined(MT6255)
    #if defined(MT6922) && !defined(NAND_SUPPORT)
        #ifdef __MPEG4_ENC_SW_SUPPORT__
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_320x240
        #endif  // __MPEG4_ENC_SW_SUPPORT__

        #ifdef __H264_ENC_SW_SUPPORT__
            #define H264_ENC_SUPPORT_RESOLUTION         RESOLUTION_176x144
        #endif  // __H264_ENC_SW_SUPPORT__
    #else
        #ifdef __MPEG4_ENC_SW_SUPPORT__
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_480x320
        #endif  // __MPEG4_ENC_SW_SUPPORT__
        
        #ifdef __H264_ENC_SW_SUPPORT__
            #define H264_ENC_SUPPORT_RESOLUTION         RESOLUTION_176x144
        #endif  // __H264_ENC_SW_SUPPORT__

        #ifdef __MJPEG_ENC_SUPPORT__
            #if defined(__EMI_CLK_200MHZ__)
               #define MJPEG_ENC_SUPPORT_RESOLUTION        RESOLUTION_800x480
            #else
               #define MJPEG_ENC_SUPPORT_RESOLUTION        RESOLUTION_640x480
            #endif
        #endif //__MJPEG_ENC_SUPPORT__
    #endif
#endif  // defined(MT6255)

/******************************************************************************
* Setting for MT6253 series
******************************************************************************/
#if (defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6253T) || defined(MT6252) || defined(MT6252H))
    #ifdef __MPEG4_ENC_SW_SUPPORT__
        #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_320x240
    #endif  // __MPEG4_ENC_SW_SUPPORT__

    #ifdef __MJPEG_ENC_SUPPORT__
        #if defined(__LOW_COST_SUPPORT_ULC__)
           #define MJPEG_ENC_SUPPORT_RESOLUTION        RESOLUTION_176x144
        #else
           #define MJPEG_ENC_SUPPORT_RESOLUTION        RESOLUTION_320x240
        #endif
    #endif //__MJPEG_ENC_SUPPORT__
#endif  // (defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6253T) || defined(MT6252) || defined(MT6252H))


/******************************************************************************
* Setting for MT6256 series
******************************************************************************/
#if defined(MT6256)
    #ifdef __MPEG4_ENC_SW_SUPPORT__
        #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_864x480
    #endif  // __MPEG4_ENC_SW_SUPPORT__
    #ifdef __H264_ENC_SW_SUPPORT__
        #define H264_ENC_SUPPORT_RESOLUTION         RESOLUTION_320x240
    #endif  // __H264_ENC_SW_SUPPORT__

    #ifdef __MJPEG_ENC_SUPPORT__
        #define MJPEG_ENC_SUPPORT_RESOLUTION        RESOLUTION_1280x720
    #endif //__MJPEG_ENC_SW_SUPPORT__
#endif  // defined(MT6256)


/******************************************************************************
* Setting for MT6276 series
******************************************************************************/
#if (defined(MT6276))
    #ifdef __MPEG4_ENC_SW_SUPPORT__
        #if defined(__MPEG4_ENC_SW_SLIM__)
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_480x320
        #else
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_800x480
        #endif
    #endif  // __MPEG4_ENC_SW_SUPPORT__
    #ifdef __H264_ENC_SW_SUPPORT__
        #define H264_ENC_SUPPORT_RESOLUTION             RESOLUTION_480x320
    #endif  // __H264_ENC_SW_SUPPORT__
#endif  // (defined(MT6276))

/******************************************************************************
* Setting for MT6235 series
******************************************************************************/
#if (defined(MT6235) || defined(MT6235B))
    #ifdef __MPEG4_ENC_SW_SUPPORT__
        #ifdef __VIDEO_MP4_RECORD_SUPPORT_HVGA_6235__
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_480x320
        #else
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_352x288
        #endif
    #endif  // __MPEG4_ENC_SW_SUPPORT__

    #ifdef __MJPEG_ENC_SUPPORT__
        #define MJPEG_ENC_SUPPORT_RESOLUTION        RESOLUTION_352x288
    #endif //__MJPEG_ENC_SUPPORT__    
#endif  // (defined(MT6235) || defined(MT6235B))

/******************************************************************************
* Setting for MT6250 series
******************************************************************************/
#if (defined(MT6250))
    #ifdef __MPEG4_ENC_SW_SUPPORT__
        #if defined(__MED_VIDEO_ULC__)
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_176x144
        #elif defined(__MPEG4_ENC_SW_SLIM__)
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_320x240
        #else
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_480x320
        #endif
    #endif  // __MPEG4_ENC_SW_SUPPORT__

    #ifdef __MJPEG_ENC_SUPPORT__
        #if defined(__MED_VIDEO_ULC__)
            #define MJPEG_ENC_SUPPORT_RESOLUTION           RESOLUTION_176x144
        #else
            #if defined(__MJPEG_ENC_SW_SLIM__)
               #define MJPEG_ENC_SUPPORT_RESOLUTION        RESOLUTION_320x240
            #else
               #define MJPEG_ENC_SUPPORT_RESOLUTION        RESOLUTION_480x320
            #endif
        #endif
    #endif //__MJPEG_ENC_SUPPORT__
#endif  // (defined(MT6250))


/******************************************************************************
* Setting for MT6260 series
******************************************************************************/
#if (defined(MT6260))
    #ifdef __MPEG4_ENC_SW_SUPPORT__
        #if defined(__MED_VIDEO_ULC__)
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_176x144
        #elif defined(__MPEG4_ENC_SW_SLIM__)
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_320x240
        #else
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_480x320
        #endif
    #endif  // __MPEG4_ENC_SW_SUPPORT__

    #ifdef __MJPEG_ENC_SUPPORT__
        #if defined(__MED_VIDEO_ULC__)
            #define MJPEG_ENC_SUPPORT_RESOLUTION           RESOLUTION_176x144
        #else
            #if defined(__MJPEG_ENC_SW_SLIM__)
               #define MJPEG_ENC_SUPPORT_RESOLUTION        RESOLUTION_320x240
            #else
               #define MJPEG_ENC_SUPPORT_RESOLUTION        RESOLUTION_480x320
            #endif
        #endif
    #endif //__MJPEG_ENC_SUPPORT__

	#ifdef __H264_ENC_SW_SUPPORT__
		#define H264_ENC_SUPPORT_RESOLUTION 		RESOLUTION_176x144
	#endif	// __H264_ENC_SW_SUPPORT__
#endif  // (defined(MT6260))

/******************************************************************************
* Setting for MT6261 series
******************************************************************************/
#if (defined(MT6261))
    #ifdef __MPEG4_ENC_SW_SUPPORT__
        #if defined(__MED_VIDEO_ULC__)
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_176x144
        #elif defined(__MPEG4_ENC_SW_SLIM__)
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_320x240
        #else
            #define MPEG4_ENC_SUPPORT_RESOLUTION        RESOLUTION_320x240
        #endif
    #endif  // __MPEG4_ENC_SW_SUPPORT__

    #ifdef __MJPEG_ENC_SUPPORT__
        #if defined(__MED_VIDEO_ULC__)
            #define MJPEG_ENC_SUPPORT_RESOLUTION           RESOLUTION_176x144
        #else
            #if defined(__MJPEG_ENC_SW_SLIM__)
               #define MJPEG_ENC_SUPPORT_RESOLUTION        RESOLUTION_320x240
            #else
               #define MJPEG_ENC_SUPPORT_RESOLUTION        RESOLUTION_320x240
            #endif
        #endif
    #endif //__MJPEG_ENC_SUPPORT__
#endif  // (defined(MT6261))


/******************************************************************************
* Replace with custom setting
******************************************************************************/
// MPEG4 encode
#ifdef __MPEG4_ENC_SW_SUPPORT__
    #ifdef MPEG4_ENC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef MPEG4_ENC_CUSTOM_SUPPORT_RESOLUTION
            #undef MPEG4_ENC_SUPPORT_RESOLUTION
            #define MPEG4_ENC_SUPPORT_RESOLUTION (MPEG4_ENC_CUSTOM_SUPPORT_RESOLUTION)
        #endif
    #endif /* MPEG4_ENC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /*__MPEG4_ENC_SW_SUPPORT__*/

// MJPEG encode
#ifdef __MJPEG_ENC_SUPPORT__
    #ifdef MJPEG_ENC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef MJPEG_ENC_CUSTOM_SUPPORT_RESOLUTION
            #undef MJPEG_ENC_SUPPORT_RESOLUTION
            #define MJPEG_ENC_SUPPORT_RESOLUTION (MJPEG_ENC_CUSTOM_SUPPORT_RESOLUTION)
        #endif
    #endif /* MJPEG_ENC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /*__MJPEG_ENC_SUPPORT__*/

//H264 encode
#ifdef __H264_ENC_SW_SUPPORT__
    #ifdef H264_ENC_CUSTOM_FRAME_SETTING_ENABLE
        #ifdef H264_ENC_CUSTOM_SUPPORT_RESOLUTION
            #undef H264_ENC_SUPPORT_RESOLUTION
            #define H264_ENC_SUPPORT_RESOLUTION (H264_ENC_CUSTOM_SUPPORT_RESOLUTION)
        #endif
    #endif /* MPEG4_ENC_CUSTOM_FRAME_SETTING_ENABLE */
#endif /*__H264_ENC_SW_SUPPORT__*/
/******************************************************************************
* Settings of video call
******************************************************************************/
#ifdef __VIDEO_VT_SUPPORT__
    #ifdef __MPEG4_ENC_SW_SUPPORT__
        #define MPEG4_ENC_VT_MAX_WIDTH         176
        #define MPEG4_ENC_VT_MAX_HEIGHT        144
        #define MPEG4_ENC_VT_WORKING_MEM_SIZE  MP4SwEncExtSize_176x144
    #endif
#endif //__VIDEO_VT_SUPPORT__


/******************************************************************************
* Translate the settings 
******************************************************************************/

//MPEG4 encode
// If a particular resolution (such as MP4SwEncExtSize_720x576) is not
// supported, then the memory requirement needs to be defined as -1.
#ifdef __MPEG4_ENC_SW_SUPPORT__
    #define CODEC_MAX_MEM_176x144 MP4SwEncExtSize_176x144
    #if (MP4SwEncExtSize_320x240 > CODEC_MAX_MEM_176x144)
        #define CODEC_MAX_MEM_320x240 MP4SwEncExtSize_320x240
    #else
        #define CODEC_MAX_MEM_320x240 CODEC_MAX_MEM_176x144
    #endif
    #if (MP4SwEncExtSize_400x240 > CODEC_MAX_MEM_320x240)
        #define CODEC_MAX_MEM_400x240 MP4SwEncExtSize_400x240
    #else
        #define CODEC_MAX_MEM_400x240 CODEC_MAX_MEM_320x240
    #endif
    #if (MP4SwEncExtSize_352x288 > CODEC_MAX_MEM_400x240)
        #define CODEC_MAX_MEM_352x288 MP4SwEncExtSize_352x288
    #else
        #define CODEC_MAX_MEM_352x288 CODEC_MAX_MEM_400x240
    #endif
    #if (MP4SwEncExtSize_480x320 > CODEC_MAX_MEM_352x288)
        #define CODEC_MAX_MEM_480x320 MP4SwEncExtSize_480x320
    #else
        #define CODEC_MAX_MEM_480x320 CODEC_MAX_MEM_352x288
    #endif
    #if (MP4SwEncExtSize_640x480 > CODEC_MAX_MEM_480x320)
        #define CODEC_MAX_MEM_640x480 MP4SwEncExtSize_640x480
    #else
        #define CODEC_MAX_MEM_640x480 CODEC_MAX_MEM_480x320
    #endif
    #if (MP4SwEncExtSize_720x480 > CODEC_MAX_MEM_640x480)
        #define CODEC_MAX_MEM_720x480 MP4SwEncExtSize_720x480
    #else
        #define CODEC_MAX_MEM_720x480 CODEC_MAX_MEM_640x480
    #endif
    #if (MP4SwEncExtSize_704x576 > CODEC_MAX_MEM_720x480)
        #define CODEC_MAX_MEM_704x576 MP4SwEncExtSize_704x576
    #else
        #define CODEC_MAX_MEM_704x576 CODEC_MAX_MEM_720x480
    #endif    
    #if (MP4SwEncExtSize_720x576 > CODEC_MAX_MEM_704x576)
        #define CODEC_MAX_MEM_720x576 MP4SwEncExtSize_720x576
    #else
        #define CODEC_MAX_MEM_720x576 CODEC_MAX_MEM_704x576
    #endif
    #if (MP4SwEncExtSize_800x480 > CODEC_MAX_MEM_720x576)
        #define CODEC_MAX_MEM_800x480 MP4SwEncExtSize_800x480
    #else
        #define CODEC_MAX_MEM_800x480 CODEC_MAX_MEM_720x576
    #endif

    #if (MP4SwEncExtSize_848x480 > CODEC_MAX_MEM_800x480)
        #define CODEC_MAX_MEM_848x480 MP4SwEncExtSize_848x480
    #else
        #define CODEC_MAX_MEM_848x480 CODEC_MAX_MEM_800x480
    #endif    

    #if (MP4SwEncExtSize_864x480 > CODEC_MAX_MEM_848x480)
        #define CODEC_MAX_MEM_864x480 MP4SwEncExtSize_864x480
    #else
        #define CODEC_MAX_MEM_864x480 CODEC_MAX_MEM_848x480
    #endif    
        
    #if (MP4SwEncExtSize_800x608 > CODEC_MAX_MEM_864x480)
        #define CODEC_MAX_MEM_800x608 MP4SwEncExtSize_800x608
    #else
        #define CODEC_MAX_MEM_800x608 CODEC_MAX_MEM_864x480
    #endif    
        
    #if (MP4SwEncExtSize_1024x768 > CODEC_MAX_MEM_800x608)
        #define CODEC_MAX_MEM_1024x768 MP4SwEncExtSize_1024x768
    #else
        #define CODEC_MAX_MEM_1024x768 CODEC_MAX_MEM_800x608
    #endif    
            
    #if (MP4SwEncExtSize_1280x720 > CODEC_MAX_MEM_800x480)
        #define CODEC_MAX_MEM_1280x720 MP4SwEncExtSize_1280x720
    #else
        #define CODEC_MAX_MEM_1280x720 CODEC_MAX_MEM_800x480
    #endif

    #if (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_176x144)
        #if (MP4SwEncExtSize_176x144 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_176x144
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_176x144
        #endif
        #define MPEG4_ENC_MAX_WIDTH         176
        #define MPEG4_ENC_MAX_HEIGHT        144
    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_320x240)
        #if (MP4SwEncExtSize_320x240 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_320x240
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_320x240
        #endif
        #define MPEG4_ENC_MAX_WIDTH         320
        #define MPEG4_ENC_MAX_HEIGHT        240
    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_400x240)
        #if (MP4SwEncExtSize_400x240 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_400x240
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_400x240
        #endif
        #define MPEG4_ENC_MAX_WIDTH         400
        #define MPEG4_ENC_MAX_HEIGHT        240
    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_352x288)
        #if (MP4SwEncExtSize_352x288 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_352x288
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_352x288
        #endif
        #define MPEG4_ENC_MAX_WIDTH         352
        #define MPEG4_ENC_MAX_HEIGHT        288
    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_480x320)
        #if (MP4SwEncExtSize_480x320 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_480x320
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_480x320
        #endif
        #define MPEG4_ENC_MAX_WIDTH         480
        #define MPEG4_ENC_MAX_HEIGHT        320
    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_640x480)
        #if (MP4SwEncExtSize_640x480 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_640x480
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_640x480
        #endif
        #define MPEG4_ENC_MAX_WIDTH         640
        #define MPEG4_ENC_MAX_HEIGHT        480
    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_720x480)
        #if (MP4SwEncExtSize_720x480 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_720x480
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_720x480
        #endif
        #define MPEG4_ENC_MAX_WIDTH         720
        #define MPEG4_ENC_MAX_HEIGHT        480
    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_720x576)
        #if (MP4SwEncExtSize_720x576 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_720x576
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_720x576
        #endif
        #define MPEG4_ENC_MAX_WIDTH         720
        #define MPEG4_ENC_MAX_HEIGHT        576
    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_800x480)
        #if (MP4SwEncExtSize_800x480 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_800x480
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_800x480
        #endif
        #define MPEG4_ENC_MAX_WIDTH         800
        #define MPEG4_ENC_MAX_HEIGHT        480
        
    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_848x480)
        #if (MP4SwEncExtSize_848x480 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_840x480
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_848x480
        #endif
        #define MPEG4_ENC_MAX_WIDTH         848
        #define MPEG4_ENC_MAX_HEIGHT        480  
              
    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_800x608)
        #if (MP4SwEncExtSize_800x608 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_800x608
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_800x608
        #endif
        #define MPEG4_ENC_MAX_WIDTH         800
        #define MPEG4_ENC_MAX_HEIGHT        608  
        
    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_1024x768)
        #if (MP4SwEncExtSize_1024x768 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_1024x768
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_1024x768
        #endif
        #define MPEG4_ENC_MAX_WIDTH         1024
        #define MPEG4_ENC_MAX_HEIGHT        768  
                
    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_1280x720)
        #if (MP4SwEncExtSize_1280x720 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_1280x720
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_1280x720
        #endif
        #define MPEG4_ENC_MAX_WIDTH         1280
        #define MPEG4_ENC_MAX_HEIGHT        720

    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_704x576)
        #if (MP4SwEncExtSize_704x576 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_704x576
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_704x576
        #endif
        #define MPEG4_ENC_MAX_WIDTH         704
        #define MPEG4_ENC_MAX_HEIGHT        576
        
    #elif (MPEG4_ENC_SUPPORT_RESOLUTION == RESOLUTION_864x480)
        #if (MP4SwEncExtSize_864x480 == -1)
            #define MPEG4_ENC_WORKING_MEM_SIZE  MP4SwEncExtSize_864x480
        #else
            #define MPEG4_ENC_WORKING_MEM_SIZE  CODEC_MAX_MEM_864x480
        #endif        
        #define MPEG4_ENC_MAX_WIDTH         864
        #define MPEG4_ENC_MAX_HEIGHT        480

    #else
        #error "The specified resolution is not supported by MPEG-4 encoder."
    #endif
#endif //__MPEG4_ENC_SW_SUPPORT__

// MJPEG encode
#ifdef __MJPEG_ENC_SUPPORT__
    #define MJPEG_ENC_WORKING_MEM_SIZE  JPEG_ENC_MJPEG_EXT_MIN_MEM_SIZE
    #if (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_176x144)
        #define MJPEG_ENC_MAX_WIDTH         176
        #define MJPEG_ENC_MAX_HEIGHT        144
    #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_320x240)
        #define MJPEG_ENC_MAX_WIDTH         320
        #define MJPEG_ENC_MAX_HEIGHT        240
    #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_400x240)
        #define MJPEG_ENC_MAX_WIDTH         400
        #define MJPEG_ENC_MAX_HEIGHT        240
    #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_352x288)
        #define MJPEG_ENC_MAX_WIDTH         352
        #define MJPEG_ENC_MAX_HEIGHT        288
    #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_480x320)
        #define MJPEG_ENC_MAX_WIDTH         480
        #define MJPEG_ENC_MAX_HEIGHT        320
    #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_640x480)
        #define MJPEG_ENC_MAX_WIDTH         640
        #define MJPEG_ENC_MAX_HEIGHT        480
    #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_720x480)
        #define MJPEG_ENC_MAX_WIDTH         720
        #define MJPEG_ENC_MAX_HEIGHT        480
    #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_720x576)
        #define MJPEG_ENC_MAX_WIDTH         720
        #define MJPEG_ENC_MAX_HEIGHT        576
    #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_800x480)
        #define MJPEG_ENC_MAX_WIDTH         800
        #define MJPEG_ENC_MAX_HEIGHT        480
    #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_848x480)
        #define MJPEG_ENC_MAX_WIDTH         848
        #define MJPEG_ENC_MAX_HEIGHT        480
    #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_800x608)
        #define MJPEG_ENC_MAX_WIDTH         800
        #define MJPEG_ENC_MAX_HEIGHT        608
    #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_1024x768)
        #define MJPEG_ENC_MAX_WIDTH         1024
        #define MJPEG_ENC_MAX_HEIGHT        768
    #elif (MJPEG_ENC_SUPPORT_RESOLUTION == RESOLUTION_1280x720)
        #define MJPEG_ENC_MAX_WIDTH         1280
        #define MJPEG_ENC_MAX_HEIGHT        720
    #endif
#endif /*__MJPEG_ENC_SUPPORT__*/

#ifdef __H264_ENC_SW_SUPPORT__
#if 1
//#ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
//#if 1
    #if (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_176x144)
        #define H264_ENC_MAX_WIDTH         176
        #define H264_ENC_MAX_HEIGHT        144
        #define H264_ENC_WORKING_MEM_SIZE  547296
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_320x240)
        #define H264_ENC_MAX_WIDTH         320
        #define H264_ENC_MAX_HEIGHT        240
        #define H264_ENC_WORKING_MEM_SIZE  1098208
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_400x240)
        #define H264_ENC_MAX_WIDTH         400
        #define H264_ENC_MAX_HEIGHT        240
        #define H264_ENC_WORKING_MEM_SIZE  1299872
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_352x288)
        #define H264_ENC_MAX_WIDTH         352
        #define H264_ENC_MAX_HEIGHT        288
        #define H264_ENC_WORKING_MEM_SIZE  1334752
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_480x320)
        #define H264_ENC_MAX_WIDTH         480
        #define H264_ENC_MAX_HEIGHT        320
        #define H264_ENC_WORKING_MEM_SIZE  1971712
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_640x480)
        #define H264_ENC_MAX_WIDTH         640
        #define H264_ENC_MAX_HEIGHT        480
        #define H264_ENC_WORKING_MEM_SIZE  3427072
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_720x480)
        #define H264_ENC_MAX_WIDTH         720
        #define H264_ENC_MAX_HEIGHT        480
        #define H264_ENC_WORKING_MEM_SIZE  3804736
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_720x576)
        #define H264_ENC_MAX_WIDTH         720
        #define H264_ENC_MAX_HEIGHT        576
        #define H264_ENC_WORKING_MEM_SIZE  4440128
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_800x480)
        #define H264_ENC_MAX_WIDTH         800
        #define H264_ENC_MAX_HEIGHT        480
        #define H264_ENC_WORKING_MEM_SIZE  4155264
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_848x480)
        #define H264_ENC_MAX_WIDTH         848
        #define H264_ENC_MAX_HEIGHT        480
        #define H264_ENC_WORKING_MEM_SIZE  4387328
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_800x608)
        #define H264_ENC_MAX_WIDTH         800
        #define H264_ENC_MAX_HEIGHT        608
        #define H264_ENC_WORKING_MEM_SIZE  5324096
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_1024x768)
        #define H264_ENC_MAX_WIDTH         1024
        #define H264_ENC_MAX_HEIGHT        768
        #define H264_ENC_WORKING_MEM_SIZE  8058240
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_1280x720)
        #define H264_ENC_MAX_WIDTH         1280
        #define H264_ENC_MAX_HEIGHT        720
        #define H264_ENC_WORKING_MEM_SIZE  9336128
    #endif
#else
    #if (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_176x144)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_320x240)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_400x240)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_352x288)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_480x320)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_640x480)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_720x480)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_720x576)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_800x480)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_848x480)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_800x608)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_1024x768)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif (H264_ENC_SUPPORT_RESOLUTION == RESOLUTION_1280x720)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
#endif
#endif /*__H264_ENC_SW_SUPPORT__*/

#endif /* __VIDEO_ARCHI_V2__ */
#endif /* SW_VIDEO_ENC0DE_CUSTOM_H */

