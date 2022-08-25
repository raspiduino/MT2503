/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	pp_mem_def.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PP_MEM_DEF_H__
#define __PP_MEM_DEF_H__

#include "feature_comm_def.h"
#include "fd_comm_def.h"
#include "sd_comm_def.h"
#include "hdr_comm_def.h"
#include "asd_comm_def.h"           
#include "lcd_sw_inc.h"
#include "pano_comm_def.h"
#include "autocap_comm_def.h"
#include "mavcap_comm_def.h"
#include "mav_comm_def.h"
#if defined(__PANORAMA_VIEW_SUPPORT__)
#include "jaia_mem.h"
#endif

/* HDR */
#define PP_MAX_EXT_MEM(A,B)         ( ((A)>(B)) ? (A) : (B))

/* Preview Scenario */
#if defined(__FACE_DETECTION_SUPPORT__)
    #if(defined(FD_SOURCE_IMAGE_FROM_CRZ)) 	/*MT6235*/
        #define PP_PREVIEW_FD_EXT_MEM_SIZE 		((((LCD_WIDTH*LCD_HEIGHT*2*2)+FD_BUFFER_SIZE+31)>>5)<<5)
    #else
        #define PP_PREVIEW_FD_EXT_MEM_SIZE 		((((160*120*2*3)+FD_BUFFER_SIZE+31)>>5)<<5)	//Fixed size
    #endif
#else
    #define PP_PREVIEW_FD_EXT_MEM_SIZE 	(0)			
#endif

#if defined(__SMILE_SHUTTER_SUPPORT__)
    #if(defined(FD_SOURCE_IMAGE_FROM_CRZ)) 	/*MT6235*/
        #define PP_PREVIEW_SD_EXT_MEM_SIZE 		((((LCD_WIDTH*LCD_HEIGHT*2*2)+SD_BUFFER_SIZE+31)>>5)<<5)	
    #else
        #define PP_PREVIEW_SD_EXT_MEM_SIZE 		((((160*120*2*3)+SD_BUFFER_SIZE+31)>>5)<<5)	//Fixed size
    #endif
#else
    #define PP_PREVIEW_SD_EXT_MEM_SIZE 	(0)			
#endif

#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
    #if(defined(AUTOCAP_SOURCE_IMAGE_FROM_CRZ)) 	/*MT6235*/
        #define PP_PREVIEW_AUTOCAP_EXT_MEM_SIZE 		((((LCD_WIDTH*LCD_HEIGHT*2*2)+AUTOCAP_BUFFER_SIZE+31)>>5)<<5)
    #else
        #define PP_PREVIEW_AUTOCAP_EXT_MEM_SIZE 		((((160*120*2*3)+AUTOCAP_BUFFER_SIZE+31)>>5)<<5)	//Fixed size
    #endif
#else
    #define PP_PREVIEW_AUTOCAP_EXT_MEM_SIZE 	(0)			
#endif

/* Still Capture Scenario */


/* Background Post-Process Scenario */
#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
    #if defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_1M)
        #define PP_BG_POSTPROC_PANO_EXT_MEM_SIZE (((1024*768*2)+31)&0xffffffe0)
    #elif defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_VGA)
    #define PP_BG_POSTPROC_PANO_EXT_MEM_SIZE (((640*480*2)+31)&0xffffffe0)
    #endif
#elif defined(__PANORAMA_VIEW_SUPPORT__)
    #if defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_2M)
        #define PP_BG_POSTPROC_PANO_EXT_MEM_SIZE (((((1600/4)*1200*4 + (1600/4-40)*1200 + (1600/4-40)*2*4) + JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE)+31)&0xffffffe0)
    #elif defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_1M)
        #define PP_BG_POSTPROC_PANO_EXT_MEM_SIZE (((((1024/4)*768*4 + (1024/4-40)*768 + (1024/4-40)*2*4) + JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE)+31)&0xffffffe0)
    #elif defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_VGA)
        #define PP_BG_POSTPROC_PANO_EXT_MEM_SIZE (((((640/4)*480*4 + (640/4-40)*480 + (640/4-40)*2*4) + JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE)+31)&0xffffffe0)
    #endif						
#else
    #define PP_BG_POSTPROC_PANO_EXT_MEM_SIZE 	(0)	
#endif

/* Post-Process Scenario */
#if defined(__PANORAMA_VIEW_SUPPORT__)
    #if defined(PANORAMA_JPEG_ENCODE_SOURCE_FORMAT_RGB565)
        #if defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_2M)
            #define PP_POSTPROC_PANO_EXT_MEM_SIZE ((((PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH*1200*2) + JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE)+31)&0xffffffe0)
        #elif defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_1M)
            #define PP_POSTPROC_PANO_EXT_MEM_SIZE ((((PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH*768*2) + JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE)+31)&0xffffffe0)
        #elif defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_VGA)
            #define PP_POSTPROC_PANO_EXT_MEM_SIZE ((((PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH*480*2) + JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE)+31)&0xffffffe0)
        #endif	
    #elif defined(PANORAMA_JPEG_ENCODE_SOURCE_FORMAT_YUV420)
        #if defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_2M)
            #define PP_POSTPROC_PANO_EXT_MEM_SIZE (((((((PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH*1200*3+1)/2)+31)&0xffffffe0) + JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE)+31)&0xffffffe0)
        #elif defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_1M)
            #define PP_POSTPROC_PANO_EXT_MEM_SIZE (((((((PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH*768*3+1)/2)+31)&0xffffffe0) + JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE)+31)&0xffffffe0)
        #elif defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_VGA)
            #define PP_POSTPROC_PANO_EXT_MEM_SIZE (((((((PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH*480*3+1)/2)+31)&0xffffffe0) + JAIA_WORKING_BUF_SIZE_FOR_PANORAMA_ENCODE)+31)&0xffffffe0)
        #endif	
    #endif
#else
    #define PP_POSTPROC_PANO_EXT_MEM_SIZE 		(0)	
#endif

#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
    #if defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_1M)
        #define PP_POSTPROC_PANO_EXT_IMAGE_MEM_SIZE (((PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH*768*3/2)+31)&0xffffffe0)
    #elif defined(PANORAMA_MAX_INPUT_IMAGE_SIZE_VGA)
    #define PP_POSTPROC_PANO_EXT_IMAGE_MEM_SIZE (((PANORAMA_JPEG_ENCODE_SOURCE_MAX_WIDTH*480*3/2)+31)&0xffffffe0)
    #endif
#define PP_POSTPROC_PANO_EXT_WORKING_MEM_SIZE (0)
#else
#define PP_POSTPROC_PANO_EXT_IMAGE_MEM_SIZE (0)
    #define PP_POSTPROC_PANO_EXT_WORKING_MEM_SIZE (0)
#endif

#if (defined(__HIGH_DYNAMIC_RANGE_SUPPORT__))
    #define PP_POSTPROC_HDR_EXT_WORKING_MEM_SIZE (((((64*48 + 64*IMAGE_SENSOR_SOURCE_MAX_HEIGHT + 1024)+ 0)+31)>>5)<<5)
    #define PP_POSTPROC_HDR_EXT_IMAGE_MEM_SIZE      ((IMAGE_SENSOR_SOURCE_MAX_WIDTH*IMAGE_SENSOR_SOURCE_MAX_HEIGHT*3+1)/2)
#else        
    #define PP_POSTPROC_HDR_EXT_WORKING_MEM_SIZE (0)
    #define PP_POSTPROC_HDR_EXT_IMAGE_MEM_SIZE      (0)
#endif

#if (defined(__AUTO_SCENE_DETECT_SUPPORT__))
    #define PP_PREVIEW_ASD_EXT_MEM_SIZE 	(((PP_PREVIEW_FD_EXT_MEM_SIZE + ASD_BUFFER_SIZE + 31)>>5)<<5)
#else
    #define PP_PREVIEW_ASD_EXT_MEM_SIZE 	(0)
#endif

#if (defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__3D_IMAGE_SUPPORT__))
    #define PP_POSTPROC_MAV_EXT_WORKING_MEM_SIZE (MAV_WORKING_BUFFER_SIZE) //(2340*1024) // Jason to do
    #define PP_POSTPROC_MAV_EXT_IMAGE_MEM_SIZE      (0) // allocated in working memory
#else        
    #define PP_POSTPROC_MAV_EXT_WORKING_MEM_SIZE (0)                
    #define PP_POSTPROC_MAV_EXT_IMAGE_MEM_SIZE      (0)
#endif

#if (defined(__CAMERA_GYRO_SUPPORT__))
	#define PP_PREVIEW_CAMERA_GYRO_EXT_WORKING_MEM_SIZE (MAVCAP_WORKING_BUFFER_SIZE) // tmp
#else
	#define PP_PREVIEW_CAMERA_GYRO_EXT_WORKING_MEM_SIZE (0)
#endif


/*****************************Log memory definition ****************************************/
/* Preview Scenario */
#define PP_PREVIEW_LOG_EXT_MEM_SIZE 	 (FD_LOG_BUFFER_SIZE + SD_LOG_BUFFER_SIZE + ASD_LOG_BUFFER_SIZE + MAVCAP_LOG_BUFFER_SIZE)       

/* Capture Scenario*/
#define PP_CAPTURE_LOG_EXT_MEM_SIZE 	(0)		

/* Background Post-Process Scenario */
#define PP_BG_POSTPROC_LOG_EXT_MEM_SIZE (0)		

/* Post-Process Scenario */
#define PP_POSTPROC_LOG_EXT_MEM_SIZE 	 (PANO_LOG_BUFFER_SIZE)


/*****************************working memory definition *************************************/
/* Preview Scenario */
#define PP_PREVIEW_EXT_MEM_SIZE ( PP_MAX_EXT_MEM(PP_MAX_EXT_MEM(PP_PREVIEW_ASD_EXT_MEM_SIZE, PP_PREVIEW_FD_EXT_MEM_SIZE),  \
                                                                                             PP_MAX_EXT_MEM(PP_PREVIEW_AUTOCAP_EXT_MEM_SIZE, PP_PREVIEW_SD_EXT_MEM_SIZE))  \
                                                              + PP_PREVIEW_LOG_EXT_MEM_SIZE )

/* Capture Scenario*/
#define PP_CAPTURE_EXT_MEM_SIZE (0)

/* Background Post-Process Scenario */
#define PP_BG_POSTPROC_EXT_MEM_SIZE (PP_BG_POSTPROC_PANO_EXT_MEM_SIZE + PP_BG_POSTPROC_LOG_EXT_MEM_SIZE)		

/* Post-Process Scenario */
#define PP_POSTPROC_EXT_WORKING_MEM_SIZE    ( PP_MAX_EXT_MEM(PP_POSTPROC_PANO_EXT_WORKING_MEM_SIZE, PP_POSTPROC_HDR_EXT_WORKING_MEM_SIZE) )
#define PP_POSTPROC_EXT_IMAGE_MEM_SIZE 	 ( PP_POSTPROC_LOG_EXT_MEM_SIZE+PP_MAX_EXT_MEM(PP_POSTPROC_PANO_EXT_IMAGE_MEM_SIZE, PP_POSTPROC_HDR_EXT_IMAGE_MEM_SIZE) )

// remove after autorama ready
#define PP_POSTPROC_EXT_MEM_SIZE 	 (PP_POSTPROC_PANO_EXT_MEM_SIZE + PP_POSTPROC_LOG_EXT_MEM_SIZE)


#endif /* __PP_MEM_DEF_H__ */
