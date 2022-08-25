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
 *	autocap_comm_def.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   AUTOCAP export API .
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _AUTOCAP_COMM_DEF_H_
#define _AUTOCAP_COMM_DEF_H_

#include "kal_release.h"
#include "lcd_sw_inc.h"
#include "feature_comm_def.h"


/****************************************************************************
 *          General Purpose Usage Macro & Variable
 ****************************************************************************/
#define CAMERA_AUTOCAP_IMAGE_BYTES 		(2)
#define AUTOCAP_IMAGE_XS				(160)
#define AUTOCAP_IMAGE_YS				(120)

#if(defined(AUTOCAP_SOURCE_IMAGE_FROM_CRZ)) 	/*MT6235*/
	#if ((LCD_WIDTH*LCD_HEIGHT*2)>(AUTOCAP_IMAGE_XS*AUTOCAP_IMAGE_YS*CAMERA_AUTOCAP_IMAGE_BYTES+AUTOCAP_IMAGE_XS*AUTOCAP_IMAGE_YS))
		#define AUTOCAP_BUFFER_SIZE 	 ((((LCD_WIDTH*LCD_HEIGHT*2)+31)>>5)<<5)
	#else
#define AUTOCAP_BUFFER_SIZE			((((AUTOCAP_IMAGE_XS*AUTOCAP_IMAGE_YS*CAMERA_AUTOCAP_IMAGE_BYTES+AUTOCAP_IMAGE_XS*AUTOCAP_IMAGE_YS)+31)>>5)<<5)
	#endif									
#else
#define AUTOCAP_BUFFER_SIZE			((((AUTOCAP_IMAGE_XS*AUTOCAP_IMAGE_YS*CAMERA_AUTOCAP_IMAGE_BYTES+AUTOCAP_IMAGE_XS*AUTOCAP_IMAGE_YS)+31)>>5)<<5)
#endif

//#define AUTOCAP_LOG_DEBUG_INFO
#ifdef AUTOCAP_LOG_DEBUG_INFO
#define AUTOCAP_LOG_BUFFER_SIZE			((((768+AUTOCAP_IMAGE_XS*AUTOCAP_IMAGE_YS*CAMERA_AUTOCAP_IMAGE_BYTES)+31)>>5)<<5) //Prz + Log	
#else
#define AUTOCAP_LOG_BUFFER_SIZE				(0) //BYTES
#endif
/****************************************************************************
 *          AUTOCAP ENUM
 ****************************************************************************/
typedef enum
{   
    AUTOCAP_DIR_RIGHT=0,
    AUTOCAP_DIR_LEFT,
    AUTOCAP_DIR_UP,
    AUTOCAP_DIR_DOWN,
    AUTOCAP_DIR_NO,
} AUTOCAP_DIRECTION_ENUM;

typedef enum
{   
    AUTOCAP_HINT_DIR_RIGHT=0,
    AUTOCAP_HINT_DIR_RIGHT_DOWN,
    AUTOCAP_HINT_DIR_DOWN,
    AUTOCAP_HINT_DIR_LEFT_DOWN,
    AUTOCAP_HINT_DIR_LEFT,
    AUTOCAP_HINT_DIR_LEFT_UP,
    AUTOCAP_HINT_DIR_UP,
    AUTOCAP_HINT_DIR_RIGHT_UP,
    AUTOCAP_HINT_DIR_NO,
} AUTOCAP_HINT_DIRECTION_ENUM;

typedef struct
{
    kal_uint32 tolerance_x; //x direction tolerance for capture, currently, not be used just for extension in the future
    kal_uint32 tolerance_y; //y direction tolerance for capture, currently, not be used just for extension in the future
}
AUTOCAP_TUNING_PARA_STRUCT, *P_AUTOCAP_TUNING_PARA_STRUCT;

typedef struct 
{
    kal_int16      MV_X;                // accumulated x motion vector 
    kal_int16      MV_Y;                // accumulated y motion vector  
    kal_uint16     ImageWidth;          // processed image width in core algorithm
    kal_uint16     ImageHeight;         // processed image height in core algorithm
    kal_uint32     OverlapRatio;        // overlap ratio (base = 64, OVLP_RATIO = 16=>16/64=1/4, OVLP_RATIO= 32=> 32/64=1/2, OVLP_RATIO = 21=>21/64~=1/3)
    kal_bool       ReadyToShot;         // ready to shot flag
    AUTOCAP_DIRECTION_ENUM Direction;   // detected motion direction
    AUTOCAP_HINT_DIRECTION_ENUM HintDirection; // hint to user direction
}AUTOCAP_RESULT_STRUCT, *P_AUTOCAP_RESULT_STRUCT;


#endif /* _AUTOCAP_COMM_DEF_H_ */

