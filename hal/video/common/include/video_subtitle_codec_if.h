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
 *   video_subtitle_codec_if.h
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
 *
 ****************************************************************************/
#ifndef VIDEO_SUBTITLE_CODEC_IF_H
#define VIDEO_SUBTITLE_CODEC_IF_H


#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__

#include "mpl_omx_core.h"
#include "video_types_v2.h"
#include "video_buffer_management_v2.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"                // for ilm_struct


typedef enum
{
    VSD_CODEC_UNKNOWN,
    VSD_CODEC_UTF8,
    VSD_CODEC_SRT,                  // A stand-alone STR file is not supported for now.
    VSD_CODEC_SSA_ASS,
    VSD_CODEC_VOBSUB,               // Not supported for now.
    VSD_CODEC_MAX
} VSD_CODEC_T;


typedef struct
{
    kal_uint32 u4Reserved;
} VSD_CODEC_INIT_T;


typedef enum
{
    VSD_CODEC_OP_NONE,
    VSD_CODEC_OP_FONT_ENGINE_API,
    VSD_CODEC_OP_RESOLUTION,
    VSD_CODEC_OP_FONT_ENCODING,
    VSD_CODEC_OP_FONT_SIZE,
    VSD_CODEC_OP_FONT_STYLES,        /* bold, italic, underline, strikeout, outline, shadow */
    VSD_CODEC_OP_COLORS,             /* primary color, background color, alpha level */
    VSD_CODEC_OP_ALIGNMENT,          /* horizontal, vertical */
    // VSD_CODEC_OP_MARGINS,            /* left, right, vertical */  /* Display location is set to Render by MPL. */
    VSD_CODEC_OP_UNKNOWN
} VSD_CODEC_OP_T;


typedef VIDEO_ERROR_TYPE_T (*PFN_VSD_OPEN_T)(void);
typedef VIDEO_ERROR_TYPE_T (*PFN_VSD_INIT_T)(VSD_CODEC_INIT_T *prInitStruct);
typedef VIDEO_ERROR_TYPE_T (*PFN_VSD_GET_PARAM_T)(VSD_CODEC_OP_T eOp, void *pvParam);
typedef VIDEO_ERROR_TYPE_T (*PFN_VSD_SET_PARAM_T)(VSD_CODEC_OP_T eOp, void *pvParam);
typedef VIDEO_ERROR_TYPE_T (*PFN_VSD_PROCESS_DATA_T)(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader, VIDEO_BUFFERHEADER_TYPE_T *prYuvBuffHeader);
typedef VIDEO_ERROR_TYPE_T (*PFN_VSD_DEINIT_T)(void);
typedef VIDEO_ERROR_TYPE_T (*PFN_VSD_CLOSE_T)(void);


typedef struct
{
    PFN_VSD_OPEN_T          pfnOpen;
    PFN_VSD_INIT_T          pfnInit;
    PFN_VSD_GET_PARAM_T     pfnGetParam;
    PFN_VSD_SET_PARAM_T     pfnSetParam;
    PFN_VSD_PROCESS_DATA_T  pfnProcessData;  // Process one unit of data.
    PFN_VSD_DEINIT_T        pfnDeInit;
    PFN_VSD_CLOSE_T         pfnClose;
} VSD_CODEC_API_T;


typedef enum
{
    VSD_HORIZONTAL_ALIGNMENT_CENTER     = 0,    // default after memset()
    VSD_HORIZONTAL_ALIGNMENT_LEFT       = 1,
    VSD_HORIZONTAL_ALIGNMENT_RIGHT      = 2
} VSD_HORIZONTAL_ALIGNMENT_T;


typedef enum
{
    VSD_VERTICAL_ALIGNMENT_BOTTOM       = 0,    // default after memset()
    VSD_VERTICAL_ALIGNMENT_TOP          = 1,
    VSD_VERTICAL_ALIGNMENT_MID          = 2,
} VSD_VERTICAL_ALIGNMENT_T;


typedef struct
{
    kal_uint32 u4Width;
    kal_uint32 u4Height;
} VSD_RESOLUTION_T;


typedef enum
{
    VSD_ENCODING_UNKNOWN,
    VSD_ENCODING_UTF8,
    VSD_ENCODING_MAX
} VSD_ENCODING_T;


typedef struct
{
    kal_bool fgBold;
    kal_bool fgItalic;
    kal_bool fgUnderline;
    kal_bool fgStrikeOut;
    kal_bool fgOutline;
    kal_bool fgShadow;
} VSD_FONT_STYLES_T;


typedef struct
{
    kal_uint32 u4PriColor;              // Primary color: AABBGGRR
    kal_uint32 u4BackColor;             // Background color: AABBGGRR
    // kal_uint32 u4AlphaLevel;            // Alpha level: redundant
} VSD_COLORS_T;


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0


typedef struct
{
    VSD_VERTICAL_ALIGNMENT_T eVerticalAlignment;
    VSD_HORIZONTAL_ALIGNMENT_T eHorizontalAlignment;
} VSD_ALIGNMENT_T;


VSD_CODEC_API_T* GetVsdCodecApi(VSD_CODEC_T eVsdCodec);
VIDEO_ERROR_TYPE_T ReleaseVsdCodecApi(VSD_CODEC_T eVsdCodec, VSD_CODEC_API_T *prHandle);


#endif  // __VE_VIDEO_ARCHI_V2__


#endif  // VIDEO_SUBTITLE_CODEC_IF_H

