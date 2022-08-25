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
 *	fd_comm_def.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   FD export API .
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#ifndef _FD_COMM_DEF_H_
#define _FD_COMM_DEF_H_

#include "kal_release.h"
#include "lcd_sw_inc.h"
#include "feature_comm_def.h"

/****************************************************************************
 *          General Purpose Usage Macro & Variable
 ****************************************************************************/

#define CAMERA_FD_MAX_NO 				(9)
#define CAMERA_FD_IMAGE_BYTES 		(2)
#define FD_IMAGE_XS						(160)
#define FD_IMAGE_YS						(120)
#define MAX_TRACKING_FACE_NUM 		(CAMERA_FD_MAX_NO)
#define MAX_FACE_SEL_NUM				(CAMERA_FD_MAX_NO+2)

#if(defined(FD_SOURCE_IMAGE_FROM_CRZ)) 	/*MT6235*/
	#if ((LCD_WIDTH*LCD_HEIGHT*2)>(FD_IMAGE_XS*FD_IMAGE_YS*CAMERA_FD_IMAGE_BYTES*3))
		#define FD_BUFFER_SIZE 	 ((((LCD_WIDTH*LCD_HEIGHT*2)+31)>>5)<<5)
	#else
		#define FD_BUFFER_SIZE 	 ((((FD_IMAGE_XS*FD_IMAGE_YS*CAMERA_FD_IMAGE_BYTES*3)+31)>>5)<<5)
	#endif									
#else
#define FD_BUFFER_SIZE			((((FD_IMAGE_XS*FD_IMAGE_YS*CAMERA_FD_IMAGE_BYTES*3)+31)>>5)<<5)
#endif

//#define FD_LOG_DEBUG_INFO
#ifdef FD_LOG_DEBUG_INFO
#define FD_LOG_BUFFER_SIZE			((((768+FD_IMAGE_XS*FD_IMAGE_YS*CAMERA_FD_IMAGE_BYTES)+31)>>5)<<5) //Prz + Log	
#else
#define FD_LOG_BUFFER_SIZE				(0) //BYTES
#endif
/****************************************************************************
 *          FD ENUM
 ****************************************************************************/

// face rotation angle
enum
{
    	FACE_DIR_OFST_0=0,
	FACE_DIR_OFST_270,
	FACE_DIR_OFST_180,
	FACE_DIR_OFST_90,
    	FACE_DIR_OFST_NUM
};

// phone rotation mode
enum
{
    	H_CCR_CR_MODE=0,
	H_CR_CCR_MODE,
    	ROTATE_MODE_NUM
};

// face focus priority mode
enum
{
	PRIOR_TO_SIZE,
	PRIOR_TO_CENTER,
	PRIOR_TO_BOTH_WEIGHT,
	PRIOR_NUM
};

// face rip support mode
enum
{
	RIP_00=1,
	RIP_00_30=3,
	RIP_SUPPORT_NUM
};

typedef struct
{
	/* FD results */
	kal_uint8 face_no;/* detected face no */
	kal_uint16 rect_x0[CAMERA_FD_MAX_NO];	//left top point
	kal_uint16 rect_y0[CAMERA_FD_MAX_NO];
	kal_uint16 rect_x1[CAMERA_FD_MAX_NO];	//right bottom point
	kal_uint16 rect_y1[CAMERA_FD_MAX_NO];
	kal_uint16 image_width; /* FD source image width */
	kal_uint16 image_height; /* FD source image height */
	
//	kal_bool detect_rate_log; /* flag for detection rate measurement. If true, log results so far */

	/*for facial continuous AE usage */
	kal_uint8	rect_lum[CAMERA_FD_MAX_NO]; // face luminance 
	
	/* for facial continuous AF usage */
	kal_uint8 result_counter;
	kal_uint16 detect_x0[CAMERA_FD_MAX_NO];
	kal_uint16 detect_y0[CAMERA_FD_MAX_NO];
	kal_uint16 detect_x1[CAMERA_FD_MAX_NO];
	kal_uint16 detect_y1[CAMERA_FD_MAX_NO];

	/* for SD usage */
	kal_uint8 detected_face_size_label[CAMERA_FD_MAX_NO];		// Record face size label for each face bin
	kal_uint8 face_feature_set_index[CAMERA_FD_MAX_NO];			// Record used feature set index for each face bin	
        
	/*for ASD usage*/
	kal_uint32  fd_start_time;
	kal_uint32  fd_end_time;	
}FD_RESULT_STRUCT,*P_FD_RESULT_STRUCT;

#endif /* _FD_COMM_DEF_H_ */
