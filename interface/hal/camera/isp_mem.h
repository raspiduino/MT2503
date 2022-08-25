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
 *	isp_if.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file is intends for ISP driver.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __ISP_MEM_H__
#define __ISP_MEM_H__

#include "sensor_capability.h"
#include "jpeg_mem.h"

#define ISP_MAX_EXT_MEM(A,B)         ( ((A)>(B)) ? (A) : (B))

#if(defined(ISP_SUPPORT))

  #if(defined(MT6268)||defined(MT6268A)||defined(MT6268H)||defined(MT6268T)||defined(MT6236))
  	#define ISP_EXT_WORKING_BUF_SIZE    (0)
	#if(defined(RAW_MAIN_CAMERA)||defined(RAW_BAK1_CAMERA)||defined(RAW_SUB_CAMERA)||defined(RAW_SUB_BAK1_CAMERA))
	  #if(defined(CAM_OFFLINE_CAPTURE)||defined(CAM_STANDARD_CAPTURE))
	    #if(defined(MT6236))
	 	   #define ISP_IMAGE_BUF_SIZE            (((((IMAGE_SENSOR_SOURCE_MAX_WIDTH *IMAGE_SENSOR_SOURCE_MAX_HEIGHT)*14)/10)+31)&0xFFFFFFE0)
	    #else
	    	#define ISP_IMAGE_BUF_SIZE            (((IMAGE_SENSOR_SOURCE_MAX_WIDTH *IMAGE_SENSOR_SOURCE_MAX_HEIGHT)+32)&0xFFFFFFE0)
	    #endif
	  #else//defined(CAM_OTF_CAPTURE)
	  	#define ISP_IMAGE_BUF_SIZE    (0)
	  #endif    
	#else
	  #define ISP_IMAGE_BUF_SIZE    (0)
	#endif

  #else // YUV sensor case    MT6235/53/53EL/58/76
  
//    #ifdef __CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__
    #if 1	
        #define ISP_JPEG_SENSOR_PARSE_BUF_SIZE  ((LCD_WIDTH*LCD_HEIGHT*2 > 640*480*2L) ? (LCD_WIDTH*LCD_HEIGHT*2) : (640 * 480 *2L))
    #else
/* under construction !*/
    #endif

      #if defined(__JPEG_SENSOR_SUPPORT__)
      #ifndef JPEG_SENSOR_WORKING_BUF_SIZE
      #define JPEG_SENSOR_WORKING_BUF_SIZE  (0)
      #endif	  
//      #define ISP_EXT_WORKING_BUF_SIZE           (JPEG_DEC_INT_MIN_MEM_SIZE+JPEG_DEC_EXT_MIN_MEM_SIZE+ ISP_JPEG_SENSOR_PARSE_BUF_SIZE)  //define in  image_sensor_xxxx.h  (((4096)+31)&0xFFFFFFE0)
      #define ISP_EXT_WORKING_BUF_SIZE           (((JPEG_DEC_INT_MIN_MEM_SIZE+ISP_MAX_EXT_MEM(JPEG_SW_DEC_EXT_MIN_MEM_SIZE,JPEG_HW_DEC_EXT_MIN_MEM_SIZE)+ ISP_JPEG_SENSOR_PARSE_BUF_SIZE)+31)&0xffffffe0)  //define in  image_sensor_xxxx.h  (((4096)+31)&0xFFFFFFE0)
      #else
      #define ISP_EXT_WORKING_BUF_SIZE            (0)
      #endif
	  
      #if (defined(MT6276)||defined(MT6256))
      #define ISP_IMAGE_BUF_SIZE            (0)
      #elif defined(MT6255) // the memory is not used by ISP, it used by MDP rotdma for capture memory out. allocate by ISP is used for min. memory
	  #if defined(__JPEG_SENSOR_SUPPORT__)
	  #define ISP_IMAGE_BUF_SIZE            ((IMAGE_SENSOR_SOURCE_MAX_WIDTH * IMAGE_SENSOR_SOURCE_MAX_HEIGHT * 3/2/4+31)&0xFFFFFFE0)
	  #else
	  #define ISP_IMAGE_BUF_SIZE            ((IMAGE_SENSOR_SOURCE_MAX_WIDTH * IMAGE_SENSOR_SOURCE_MAX_HEIGHT * 3/2+31)&0xFFFFFFE0)
	  #endif
      #else  //35/53/53EL/76
	  
            #if (defined(__YUVCAM_INTERPOLATION_SW__))
            #define ISP_IMAGE_BUF_SIZE           ((((IMAGE_SENSOR_SOURCE_MAX_WIDTH * IMAGE_SENSOR_SOURCE_MAX_HEIGHT*3)>>1) +31)&0xFFFFFFE0) // for y,u,v buffer
            #else //hw interpolation   or others use capture target size
            #define ISP_IMAGE_BUF_SIZE           ((((IMAGE_SENSOR_TARGET_MAX_WIDTH * IMAGE_SENSOR_TARGET_MAX_HEIGHT*3)>>1) +31)&0xFFFFFFE0) // for y,u,v buffer
            #endif
      #endif
	  
  #endif

#endif//#if(defined(ISP_SUPPORT))

#endif /* _ISP_MEM_H */
