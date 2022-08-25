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
 *	sd_comm_def.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   SD export API .
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
 * removed!
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
#ifndef _SD_COMM_DEF_H_
#define _SD_COMM_DEF_H_

#include "kal_release.h"
#include "lcd_sw_inc.h"
#include "feature_comm_def.h"

/****************************************************************************
 *          SD Process Macro
 ****************************************************************************/
#define CAMERA_SD_MAX_NO (3)
#define SD_IMAGE_XS						(160)
#define SD_IMAGE_YS						(120)

#if(defined(FD_SOURCE_IMAGE_FROM_CRZ)) 	/*MT6235*/
	#if ((LCD_WIDTH*LCD_HEIGHT*2)>(SD_IMAGE_XS*SD_IMAGE_YS*2*3))
		#define SD_BUFFER_SIZE 	 ((((LCD_WIDTH*LCD_HEIGHT*2)+31)>>5)<<5)
	#else
		#define SD_BUFFER_SIZE 	 ((((SD_IMAGE_XS*SD_IMAGE_YS*2*3)+31)>>5)<<5)
	#endif									
#else
#define SD_BUFFER_SIZE			((((SD_IMAGE_XS*SD_IMAGE_YS*2*3)+31)>>5)<<5)
#endif

//#define SD_LOG_DEBUG_INFO
#ifdef SD_LOG_DEBUG_INFO
#define SD_LOG_BUFFER_SIZE      ((((256+SD_IMAGE_XS*SD_IMAGE_YS*2)+31)>>5)<<5) // 64 bytes header + 256 bytes log body + Prz RGB565 (160*120)
#else
#define SD_LOG_BUFFER_SIZE				(0) //BYTES
#endif

typedef struct
{
	/* FD results */
	kal_uint8 face_no;/* detected face no */
	kal_uint16 image_width; /* SD source image width */
	kal_uint16 image_height; /* SD source image height */
	kal_uint16 rect_x0[CAMERA_SD_MAX_NO];	//left top point
	kal_uint16 rect_y0[CAMERA_SD_MAX_NO];
	kal_uint16 rect_x1[CAMERA_SD_MAX_NO];	//right bottom point
	kal_uint16 rect_y1[CAMERA_SD_MAX_NO];
	kal_uint8	rect_lum[CAMERA_SD_MAX_NO]; // face luminance 

	/* SD results */
	kal_bool sd_end_flag;
	kal_bool sd_main_smile_flag;
//	kal_bool sd_detect_flag[CAMERA_SD_MAX_NO];
	kal_uint8 smile_detected_no;
	kal_uint8 smile_required_no;
	kal_uint16 sd_rect_x0[CAMERA_SD_MAX_NO]; 
	kal_uint16 sd_rect_y0[CAMERA_SD_MAX_NO]; 
	kal_uint16 sd_rect_x1[CAMERA_SD_MAX_NO]; 
	kal_uint16 sd_rect_y1[CAMERA_SD_MAX_NO]; 
}SD_RESULT_STRUCT,*P_SD_RESULT_STRUCT;

#endif /* _SD_COMM_DEF_H_ */
