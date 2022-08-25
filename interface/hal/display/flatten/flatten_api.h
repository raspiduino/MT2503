/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   flatten_api.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Flatten related function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 01 10 2013 hung-wen.hsieh
 * removed!
 * .
 *
 * 06 08 2012 haitao.shang
 * removed!
 * .
 *
 * 03 21 2012 xiaoyong.ye
 * removed!
 * Support ARGB6666/PARGB6666 check in.
 *
 * 12 08 2011 xiaoyong.ye
 * removed!
 * CodeReview.
 *
 * 10 25 2011 xiaoyong.ye
 * removed!
 * 
 * Remove user_version_code for FlattenGetOwnership().
 *
 * 10 20 2011 xiaoyong.ye
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _FLATTEN_API_H_
#define _FLATTEN_API_H_

/******************************************************************************
 * include directives
 ******************************************************************************/
#include "kal_release.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef kal_int32           FLATTENint;
typedef kal_uint32          FLATTENuint;
typedef kal_uint32          FLATTENbitfield;

typedef enum
{   
    FLATTEN_TRANSPARENCY_NONE                   = 0,
    FLATTEN_TRANSPARENCY_SOURCE_COLOR_KEY       = (1 << 0), //enable source color key
    FLATTEN_TRANSPARENCY_GLOBAL_ALPHA           = (1 << 1), //enable constant alpha blending (layer_control_register->alpha)
    FLATTEN_TRANSPARENCY_SOURCE_ALPHA           = (1 << 2), //enable pixel alpha blending (content's alpha channel)
    FLATTEN_TRANSPARENCY_MASK                   = (1 << 3), //
    FLATTEN_TRANSPARENCY_FORCE_32BIT            = 0x7FFFFFFF
} FLATTENTransparencyType;

typedef enum
{
    /* Clockwise rotation */
    FLATTEN_ROTATION_0                          = 0,  /* default */
    FLATTEN_ROTATION_90                         = 90,
    FLATTEN_ROTATION_180                        = 180,
    FLATTEN_ROTATION_270                        = 270,
    FLATTEN_ROTATION_FORCE_32BIT                = 0x7FFFFFFF
} FLATTENRotationType;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#define FLATTEN_LAYER0 0x80000000
#define FLATTEN_LAYER1 0x40000000
#define FLATTEN_LAYER2 0x20000000
#define FLATTEN_LAYER3 0x10000000
typedef kal_uint32 FlattenLayerType;

typedef enum 
{
    FLATTEN_RESULT_OK                           = 0,
    FLATTEN_RESULT_DEVICE_BUSY,
    FLATTEN_RESULT_ILLEGAL_ARGUMENT,
    FLATTEN_RESULT_UNSUPPORTED,
    FLATTEN_RESULT_FAIL,
    FLATTEN_RESULT_FORCE_32BIT                  = 0x7FFFFFFF
} FlattenResultEnum;

/**
 * image formats 
 */
typedef enum
{
    FLATTEN_IMAGE_NOT_SUPPORTED                 = 0,
    FLATTEN_IMAGE_ARGB8888,
    FLATTEN_IMAGE_XRGB8888,
    FLATTEN_IMAGE_RGB888, /**< \remark <b>[MTK]</b> R in high byte, B in low byte. */
    FLATTEN_IMAGE_BGR888, /**< <b>[MTK]</b> BGR color format. B in high byte and R in low byte. */
    FLATTEN_IMAGE_RGB565,
    FLATTEN_IMAGE_L32,
    FLATTEN_IMAGE_L16,
    FLATTEN_IMAGE_L8,
    FLATTEN_IMAGE_L1,
    FLATTEN_IMAGE_UYVY, /**< <b>[MTK]</b> UYVY color format. */
    FLATTEN_IMAGE_ARGB6666,
    FLATTEN_IMAGE_ARGB_INTERNAL, /**< FLATTENpixel rep */
    FLATTEN_IMAGE_FORCE_32BIT                   = 0x7FFFFFFF
} FLATTEN_PIXEL_FORMAT;

/**
 * FlattenLayerStruct 
 */
typedef struct 
{
  FLATTENbitfield              transparencyType;  /**< FLATTENTransparencyType bit ored to enable or disable the source color key,
  													gloal alpha or source alpha*/
  kal_int32                    globalAlpha;
  kal_uint32                   sourceColorKey;
  kal_bool                     enableSpatialDithering;	/* Reserved */
  //DestinationRectangle
  kal_int32                    destinationRect_x;   	/* Before rotation,if use layer rotate*/
  kal_int32                    destinationRect_y;		/* Before rotation,if use layer rotate*/
  kal_int32                    destinationRect_width;	/* Before rotation,if use layer rotate*/
  kal_int32                    destinationRect_height;	/* Before rotation,if use layer rotate*/
  //ImageSource
  kal_int32                    image_source_width;
  kal_int32                    image_source_height;
  kal_int32                    image_source_stride; /**< number of bytes per line */
  kal_int32                    image_source_pixelSize; /**< pixel size in bytes */
  FLATTEN_PIXEL_FORMAT         image_source_format_pixelFormat; /**< FLATTEN_PIXEL_FORMAT */
  kal_bool                     image_source_format_premultiplied;
  kal_bool                     image_source_format_linear;	/* Reserved */
  kal_int32                    image_source_format_rowPadding;	/* Reserved */
  kal_int32                    image_source_datamax; 	/* Reserved */
  kal_int32                    image_source_alpha; 		/* Reserved */
  void *                       image_source_data;
  //SourceRectangle
  kal_int32                    sourceRect_x;	/* Before rotation,if use layer rotate*/
  kal_int32                    sourceRect_y;	/* Before rotation,if use layer rotate*/
  kal_int32                    sourceRect_width;	/* Before rotation,if use layer rotate*/
  kal_int32                    sourceRect_height;	/* Before rotation,if use layer rotate*/

  kal_bool                     flip;
  FLATTENRotationType          rotationAngle;
  kal_bool                     isConstantValue; //if enable, use sourceColorKey to be layer constant value
} FlattenLayerStruct;

/**
 * FlattenCtrlStruct 
 */
typedef struct 
{
  FLATTENbitfield              flatten_enable_layer;  /**< FlattenLayerType bit ored to enable or disable each layer*/
  FLATTENRotationType          rotationAngle;
  kal_uint32                   bgColor; // for [31-24]A/[23-16]R/[15-8]G/[7-0]B channel; 
  //Memout_image
  kal_int32                    memOut_image_width;
  kal_int32                    memOut_image_height;
  kal_int32                    memOut_image_stride; /**< number of bytes per line */
  kal_int32                    memOut_image_pixelSize; /**< pixel size in bytes */
  FLATTEN_PIXEL_FORMAT         memOut_image_format_pixelFormat; /**< FLATTEN_PIXEL_FORMAT */
  kal_bool                     memOut_image_format_premultiplied;
  kal_bool                     memOut_image_format_linear;      /* Reserved */
  kal_int32                    memOut_image_format_rowPadding;  /* Reserved */
  kal_int32                    memOut_image_datamax; 	/* Reserved */
  kal_int32                    memOut_image_alpha;
  void *                       memOut_image_data;
  //dithering
  kal_bool					   				 enableDithering;
  //RoiRectangle
  kal_int32                    roiRect_x;
  kal_int32                    roiRect_y;
  kal_int32                    roiRect_width;
  kal_int32                    roiRect_height;
  //DestinationRectangle
  kal_int32                    destinationRect_x;	/* Before rotation, if use rotation*/
  kal_int32                    destinationRect_y;	/* Before rotation, if use rotation*/
  kal_int32                    destinationRect_width;	/* Before rotation, if use rotation*/
  kal_int32                    destinationRect_height;	/* Before rotation, if use rotation*/
  //global palette table buffer address
  kal_uint32                   paletteTable;	/* Reserved */
  //blocking or non-blocking related
  kal_bool                     blocking_req;
  void                         (* flatten_nonblocking_callback)(void *);
  void*                        cbparam;
} FlattenCtrlStruct;

/* Function Prototypes */

kal_uint32 FlattenGetUserHandle(void); //value 0 is invalid handle

FlattenResultEnum FlattenGetOwnership(kal_uint32 handle, kal_bool wait, kal_bool use_sw_flatten); // use_sw_flatten: if use SW to do flatten

FlattenResultEnum FlattenReleaseOwnership(kal_uint32 handle);

FlattenResultEnum FlattenConfigLayer(kal_uint32 handle, FlattenLayerType flatten_layer, FlattenLayerStruct *flatten_layer_config);

FlattenResultEnum FlattenStart(kal_uint32 handle, FlattenCtrlStruct *flatten_ctrl_config);

#ifdef __cplusplus
}
#endif

#endif //#ifndef _FLATTEN_API_H_
