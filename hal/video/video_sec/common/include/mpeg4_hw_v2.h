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
 *   mpeg4_hw_v2.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file declares the common declaration for MPEG4 HW V2
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MPEG4_HW_V2_H
#define MPEG4_HW_V2_H

#include "kal_general_types.h"
#include "drv_features_video.h"

#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_MP4_ENC_HW_SUPPORT__

typedef enum
{
   VIDEO_MPEG4HW_NONE = 0x00,
   VIDEO_MPEG4HW_DEC = 0x01,
   VIDEO_MPEG4HW_ENC = 0x02,
   VIDEO_MPEG4HW_MAX = 0x0F
} VIDEO_MPEG4HW_USER_T;

kal_bool MPEG4HWHwResourceGet(VIDEO_MPEG4HW_USER_T eMPEG4HWUser);
void MPEG4HWHwResourceFree(VIDEO_MPEG4HW_USER_T eMPEG4HWUser);

kal_bool MPEG4HWOpen(VIDEO_MPEG4HW_USER_T eMPEG4HWUser);
kal_bool MPEG4HWClose(VIDEO_MPEG4HW_USER_T eMPEG4HWUser);

kal_bool MPEG4HWHwResourceFreeIfOccupy(VIDEO_MPEG4HW_USER_T eMPEG4HWUser);

#define VO_START_CODE           0x8
#define VO_START_CODE_MIN       0x100
#define VO_START_CODE_MAX       0x11f

#define VOL_START_CODE          0x12
#define VOL_START_CODE_MIN      0x120
#define VOL_START_CODE_MAX      0x12f

#define VOS_START_CODE          0x1b0
#define VOS_END_CODE            0x1b1
#define USR_START_CODE          0x1b2
#define GOP_START_CODE          0x1b3
#define VSO_START_CODE          0x1b5
#define VOP_START_CODE          0x1b6
#define STF_START_CODE          0x1c3 // stuffing_start_code
#define SHV_START_CODE          0x020
#define SHV_END_MARKER          0x03f

#define I_VOP		            0
#define P_VOP		            1
#define B_VOP		            2
#define S_VOP		            3

#define RECTANGULAR				0
#define BINARY					1
#define BINARY_SHAPE_ONLY		2 
#define GRAY_SCALE				3

#define NOTUSE_SPRITE			0
#define STATIC_SPRITE			1
#define GMC_SPRITE				2
#define RESERVED_SPRITE			3

#define RESYNC_MARKER			1

#define VIDEO_MAX(a,b)          ( ((a)>(b))? a : b )
#define VIDEO_MIN(a,b)          ( ((a)<(b))? a : b )
#define ENFORCE_MINMAX(a,b,c)   VIDEO_MAX(a,(VIDEO_MIN(b,c)))

#define VOS_BIT_RATE            (640000/400)
#define VOS_VBV_BUFFER_SIZE     (1835008/16384)
#define VOS_OCCUPANCY           (1376256/64)

#endif /* __VE_MP4_ENC_HW_SUPPORT__*/
#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* MPEG4_HW_ENCORE_V2_H */
