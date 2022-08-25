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
 *   video_vt_if_v2.h
 *
 * Project:
 * --------
 *	MAUI
 *
 * Description:
 * ------------
 *   This file defines the video call interface
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
#ifndef VIDEO_VT_API_V2
#define VIDEO_VT_API_V2

#include "mpl_vt.h"

#include "kal_general_types.h"
#include "drv_features_video.h"

#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef  __VE_VIDEO_VT_SUPPORT__

#define _VIDEO_CALL_RESYNC_PROTECTION_
#define _VCALL_VIDEO_ALL_IN_HISR_

#define MAX_MB_PACKET            (99*4)
#define EXTENDED_PAR             0x000f
#define DEC_OK			            0
#define DEC_MEMORY		         1
#define DEC_BAD_FORMAT	         2
#define DEC_INVALID_ARGUMENT     3
#define DEC_NOT_IMPLEMENTED      4

#define I_VOP		               0
#define P_VOP		               1
#define B_VOP		               2
#define S_VOP		               3

#define RECTANGULAR				   0
#define BINARY					      1
#define BINARY_SHAPE_ONLY		   2 
#define GRAY_SCALE				   3

#define NOTUSE_SPRITE			   0
#define STATIC_SPRITE			   1
#define GMC_SPRITE				   2
#define RESERVED_SPRITE			   3

#define RESYNC_MARKER			   1

#define VIDEO_MAX(a,b)                 ( ((a)>(b))? a : b )
#define VIDEO_MIN(a,b)                 ( ((a)<(b))? a : b )
#define ENFORCE_MINMAX(a,b,c)    VIDEO_MAX(a,(VIDEO_MIN(b,c)))
#define VOS_BIT_RATE             (640000/400)
#define VOS_VBV_BUFFER_SIZE      (1835008/16384)
#define VOS_OCCUPANCY            (1376256/64)

// Define from v1 legacy
#define MAX_VOS_LENGTH 100
//

/****************** mp4 structures ************************/
/// Bitstream header information
///
typedef struct  
{
    /// frame rate. for exampe : 15 fps.
    kal_uint32   frame_rate;
    /// encoded frame width
    kal_int32   width;
    /// encoded frame height
    kal_int32   height;
    /// store the intra frame number.
    kal_int32   intra_num;
    /// short header mode(H.263) or not(Mpeg4).
    kal_bool    b_short_header;
    /// I_VOP or P_VOP
    kal_int32   predition_type;
    /// This value represents the absolute vop_time_increment from the
    /// synchronization point marked by the modulo_time_base measured
    /// in the number of clock ticks. It can take a value in the range
    /// of [0,vop_time_increment_resolution)
    kal_int32   vop_time_increment;
    kal_int32   fixed_vop_time_increment;
    /// vop_time_increment_resolution, indicates the number of evenly spaced subintervals,
    /// called ticks, within one modulo time. One modulo time represents the fixed interval
    /// of one second. The value zero is forbidden.
    kal_int32   time_increment;
    kal_uint32 old_time;
    /// quantizer value
    kal_int32   quantizer;
    kal_uint32 intra_threshold;
    /// vop_fcode_forward, values from 1 to 7; the value of zero is forbidden.
    /// It is used in decoding of motion vectors.
    kal_int32   fcode;
    kal_int32   time_base;
    kal_bool  b_resync_marker;
    kal_int32   prev_vop_time_increment;
    kal_int32   prev_old_time;
}m4v_enc_im;



/****************** external structures ************************/

extern VIDEO_CALL_STATUS VideoCall_ParsePacket(kal_uint8 *p_data, kal_uint32 length, Video_Call_Parse_Info *p_info);
extern VIDEO_CALL_STATUS VideoCall_SetDecParseCodec(VIDEO_CALL_CODEC_TYPE type);

#endif /*  __VE_VIDEO_VT_SUPPORT__*/
#endif /* __VE_VIDEO_ARCHI_V2__*/
#endif /*VIDEO_VT_API_V2*/
