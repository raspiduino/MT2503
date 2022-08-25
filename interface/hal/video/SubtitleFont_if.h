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
 *   SubtitleFont_if.h
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
 *
 ****************************************************************************/

#ifndef __SUBTITLE_FONT_IF_H__

#define __SUBTITLE_FONT_IF_H__

//define operate flags
typedef enum
{
    SUBTITLE_OP_UNKNOWN,
    SUBTITLE_OP_ENCODING,
    SUBTITLE_OP_HORIZONTAL_ALIGNMENT,
    SUBTITLE_OP_VERTICAL_ALIGNMENT,
    SUBTITLE_OP_FONT_COLOR,
    SUBTITLE_OP_FONT_SIZE,
    SUBTITLE_OP_FONT_STYLE,
    SUBTITLE_OP_FONT_EFFECT,
    SUBTITLE_OP_STRING,
    SUBTITLE_OP_BOUNDARY_RECT,
    SUBTITLE_OP_MAX = 0x1FFFFFFF
} SUBTITLE_OP_T ;


typedef enum
{
    SUBTITLE_ENCODNIG_UNKNOWN,
    SUBTITLE_ENCODING_UTF8
} SUBTITLE_ENCODING_T;


typedef enum
{
    SUBTITLE_HORIZONTAL_ALIGNMENT_CENTER = 1,
    SUBTITLE_HORIZONTAL_ALIGNMENT_LEFT,
    SUBTITLE_HORIZONTAL_ALIGNMENT_RIGHT
} SUBTITLE_HORIZONTAL_ALIGNMENT_T;

typedef enum
{
    SUBTITLE_VERTICAL_ALIGNMENT_CENTER =1,
    SUBTITLE_VERTICAL_ALIGNMENT_TOP,
    SUBTITLE_VERTICAL_ALIGNMENT_BOTTOM
} SUBTITLE_VERTICAL_ALIGNMENT_T;

//Subtitle Decoder uses this OP code to pass the buffer address where a subtitle string shall be drawn to.

//#define SUBTITLE_OP_GDI_LAYER   //(This may not be a good name.)

//font attribution
typedef enum
{
    SUBTITLE_STYLE_NORMAL = 0x01,
    SUBTITLE_STYLE_BORDER = 0x02,          /* anti-aliased string */
    SUBTITLE_STYLE_BOLD   = 0x04,
    SUBTITLE_STYLE_ITALIC = 0x08,
    SUBTITLE_STYLE_UNDERLINE = 0x10
} SUBTITLE_STYLE_T;

typedef enum
{
    SUBTITLE_EFFECT_NONE         = 0,
    SUBTITLE_EFFECT_SHADOW_1,
    SUBTITLE_EFFECT_SHADOW_2,
    SUBTITLE_EFFECT_SHADOW_3,
    SUBTITLE_EFFECT_SHADOW_4,
    SUBTITLE_EFFECT_SHADOW_5,
    SUBTITLE_EFFECT_SHADOW_6,
    SUBTITLE_EFFECT_SHADOW_7,
    SUBTITLE_EFFECT_SHADOW_8,
    SUBTITLE_EFFECT_SHADOW_9,
	/* Add new shadow effects enum hare */

	/* Outer Glow */
    SUBTITLE_EFFECT_OUTER_GLOW_1 = 301,
	/* Add new outer glow effects enum hare */

	/* Enhanced Engraved */
    SUBTITLE_EFFECT_ENGRAVED_1   = 601,
	/* Add new engraved effects enum hare */

	/* Gradient */
    SUBTITLE_EFFECT_GRADIENT_1   = 901,
	/* Add new gradient effects enum hare */

	/* Bordered */
    SUBTITLE_EFFECT_BORDERED_1   = 1201,

    SUBTITLE_EFFECT_MAX = 0x1FFFF
} SUBTITLE_FONT_EFFECT_T;

//Drawing (or boundary) rectangle (or area)
typedef struct
{
    kal_uint32 u4Width;
    kal_uint32 u4Height;
	kal_uint8 *pu1Buffer;         /* address of subtitle buffer */
    kal_uint32 u4BufferSize;
} SUBTITLE_BOUNDARY_RECT_T;

typedef void (*PFN_FES_OPEN_T)(void **pprHandle);
typedef void (*PFN_FES_CLOSE_T)(void **pprHandle);
typedef void (*PFN_FES_DRAW_T)(void *prHandle);
typedef void (*PFN_FES_INIT_T)(void *prHandle,void *pvParam, kal_uint32 u4SizeOfParam);
typedef void (*PFN_FES_DEINIT_T)(void *prHandle,void *pvParam, kal_uint32 u4SizeOfParam);
typedef void (*PFN_FES_SET_PROPERTY_T)(void *prHandle,SUBTITLE_OP_T eOP,void *pvParam, kal_uint32 u4SizeOfParam);
typedef void (*PFN_FES_GET_PROPERTY_T)(void *prHandle,SUBTITLE_OP_T eOP,void *pvParam, kal_uint32 u4SizeOfParam);

typedef struct
{
	PFN_FES_OPEN_T pfnOpen; 
	PFN_FES_CLOSE_T pfnClose;
	PFN_FES_DRAW_T pfnDraw;
	PFN_FES_INIT_T pfnInit;
	PFN_FES_DEINIT_T pfnDeinit;
	PFN_FES_SET_PROPERTY_T pfnSetProp;
	PFN_FES_GET_PROPERTY_T pfnGetProp;	
} subtitle_fontengine_struct;

#endif  // __SUBTITLE_FONT_IF_H__

