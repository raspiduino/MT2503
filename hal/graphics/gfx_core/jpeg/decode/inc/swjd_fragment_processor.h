/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   swjd_fragment_processor.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Prototypes of SW JPEG fragment processor.
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

#ifndef __SWJD_FRAGMENT_PROCESSOR_H__
#define __SWJD_FRAGMENT_PROCESSOR_H__

#include "kal_general_types.h"
#include "iul_x_math.h"
#include "stdio.h"
#if defined(MTK_TARGET)
#include "SST_sla.h"
#endif

#define __SWJD_Y2R_LUT__

#ifndef MIN
#define MIN(x, y)    (((x) < (y))? (x): (y))
#endif  // MIN

#define FRAG_PROCESSOR_SUPPORT_TRANSFORM           (1)
#define FRAG_PROCESSOR_SUPPORT_PROFILING           (0)

// Forward declaration to make compiler happy
typedef struct SWJD_FRAGMENT_PROCESSOR             SWJD_FRAGMENT_PROCESSOR;


typedef enum FRAG_PROCESSOR_STATUS_ENUM
{
   FRAG_PROCESSOR_STATUS_RETURN_SUCCESS            = 0,
   FRAG_PROCESSOR_STATUS_INVALID_PARAMETER         = -1,
   FRAG_PROCESSOR_STATUS_INTERNAL_ERROR            = -2
} FRAG_PROCESSOR_STATUS_ENUM;


typedef enum FRAG_PROCESSOR_TRANSFORM_ENUM
{
   FRAG_PROCESSOR_TRANSFORM_FLIP_HORIZONTAL_ONLY   = 0,  // Flip horizontal only without rotation
   FRAG_PROCESSOR_TRANSFORM_FLIP_AND_ROTATE_CW_90  = 1,  // Flip and rotate clockwise 90
   FRAG_PROCESSOR_TRANSFORM_FLIP_AND_ROTATE_CW_180 = 2,  // Flip and rotate clockwise 180
   FRAG_PROCESSOR_TRANSFORM_FLIP_AND_ROTATE_CW_270 = 3,  // Flip and rotate clockwise 270
   FRAG_PROCESSOR_TRANSFORM_NO_FLIP_ROTATE_CW_0    = 4,  // No flip and no rotate
   FRAG_PROCESSOR_TRANSFORM_NO_FLIP_ROTATE_CW_90   = 5,  // No flip and rotate clockwise 90
   FRAG_PROCESSOR_TRANSFORM_NO_FLIP_ROTATE_CW_180  = 6,  // No flip and rotate clockwise 180
   FRAG_PROCESSOR_TRANSFORM_NO_FLIP_ROTATE_CW_270  = 7   // No flip and rotate clockwise 270
} FRAG_PROCESSOR_TRANSFORM_ENUM;


typedef enum FRAG_PROCESSOR_COLOR_ENUM
{
   FRAG_PROCESSOR_COLOR_FORMAT_Y_ONLY              = 0,  // Grayscale color format
   FRAG_PROCESSOR_COLOR_FORMAT_YUV444              = 1,  // YUV444 color format
   FRAG_PROCESSOR_COLOR_FORMAT_YUV422              = 2,  // YUV422 color format
   FRAG_PROCESSOR_COLOR_FORMAT_YUV422V             = 3,  // YUV422V color format
   FRAG_PROCESSOR_COLOR_FORMAT_YUV420              = 4,  // YUV420 color format
   FRAG_PROCESSOR_COLOR_FORMAT_YUV411              = 5,  // YUV411 color format
   FRAG_PROCESSOR_COLOR_FORMAT_UYVY422             = 6,  // UYVY422 color format
   FRAG_PROCESSOR_COLOR_FORMAT_RGB565              = 7,  // RGB565 color format
   FRAG_PROCESSOR_COLOR_FORMAT_ARGB8888            = 8,  // ARGB8888 color format
   FRAG_PROCESSOR_COLOR_FORMAT_PARGB8888           = 9,  // PARGB8888 color format
   FRAG_PROCESSOR_COLOR_FORMAT_ARGB6666            = 10, // ARGB6666 color format
   FRAG_PROCESSOR_COLOR_FORMAT_BGR888              = 11, // BGR888 color format
   FRAG_PROCESSOR_COLOR_FORMAT_RGB888              = 12  // RGB888 color format
} FRAG_PROCESSOR_COLOR_ENUM;


/*
 * Fragment resizing algorithm supported
 */
typedef enum FRAG_PROCESSOR_FILTER_ENUM
{
   FRAG_PROCESSOR_FILTER_NO_RESIZE,
   FRAG_PROCESSOR_FILTER_BILINEAR
} FRAG_PROCESSOR_FILTER_ENUM;


/**
 * Prototype for fragment processing function
 */
typedef FRAG_PROCESSOR_STATUS_ENUM  (*FRAG_PROC_FUNC)(SWJD_FRAGMENT_PROCESSOR *pProcessor,
                                                      kal_int32               outputWidth,
                                                      kal_int32               outputHeight);

/**
 * Prototype for post interpolation function
 */
typedef FRAG_PROCESSOR_STATUS_ENUM  (*POST_ITPL_FUNC)(SWJD_FRAGMENT_PROCESSOR *pProcessor,
                                                      kal_int32               outputWidth,
                                                      kal_int32               outphtHeight);


typedef struct SWJD_FRAGMENT_PROCESSOR
{
   FRAG_PROCESSOR_COLOR_ENUM     fragFormat;       // Source color format to be processed by the processor
   kal_uint8                     *pFragBuf[3];     // Source buffer base address for Y, U anv V components

                                                   // The processor will calculate the X and Y offset relative
                                                   // to the fragment buffer base each time when the fron tier
                                                   // calls fragProcessorGetFragWindow.
                                                   // The member with frag in prefix means that the corrdinate
                                                   // used is rotated. (i.e. For rotating 90 or 270 degree,
                                                   // the X and Y coordinate are switched.)
   IUL_FIXED                     fragOffsetX;      // X coordinate offset relative to the buffer base address
   IUL_FIXED                     fragOffsetY;      // Y coordinate offset relative to the buffer base address

   kal_int32                     fragBufWidth;     // The fragment buffer width set by the front tier.
   kal_int32                     fragBufHeight;    // The fragment buffer height set by the font tier.
   kal_int32                     fragBufPitch;     // The fragment buffer pitch set by the front tier.

   IUL_FIXED                     fragStepX;        // Source step of X direction when target advances one pixel
   IUL_FIXED                     fragStepY;        // Source step of Y direction when target advances on pixel
   IUL_FIXED                     fragScaleX;       // This is the replica of fragStepX for 
   IUL_FIXED                     fragScaleY;       // This is the replica of fragStepY for 

                                                   // The member with src in prefix means that the coordinate
                                                   // used in source coordinate. (i.e. without rotation)

   IUL_FIXED                     srcLeft;
   IUL_FIXED                     srcRight;
   IUL_FIXED                     srcTop;
   IUL_FIXED                     srcBottom;
   kal_int32                     srcBlocksW;       // Maxmum source blocks width needed for resizing operation
   kal_int32                     srcBlocksH;       // Maxmum source block height needed for resizing operation
   kal_bool                      goToNextRow;      // Should be advance to next source row after current resizing

   kal_int32                     srcWidth;
   kal_int32                     srcHeight;

                                                   // This is for solving potential issue from 09A, 09B and 10A.
                                                   // The source coordinate may be calculated in JPEG decoder or
                                                   // fragment processor. But the calculated coordinated are different.
   kal_int32                     srcShiftH;        // Horizontal shift for trnsferring X coordinate into blocks
   kal_int32                     srcShiftV;        // Vertical shift for transferring Y coordinate into blocks

   FRAG_PROCESSOR_FILTER_ENUM    filterType;       // Scaling algorithm used for scaling source data into canvas

                                                   
   kal_int32                     fragSrcWidth;     // The rotated width of the fragment data according to the angle.
   kal_int32                     fragSrcHeight;    // The rotated height of the fragment data according to the angle.

   FRAG_PROCESSOR_TRANSFORM_ENUM rotation;         // The specified rotation angle required by the fornt tier.

   FRAG_PROCESSOR_COLOR_ENUM     canvasFormat;     // The canvas color format for output processed pixels
   void                          *pCanvasBuf[3];   // Canvas buffer base address for Y, U and V components
                                                   // For RGB related format, we only use canvas buffer 0
   kal_int32                     canvasWidth;      // The canvas buffer width of Y component in pixel unit
   kal_int32                     canvasHeight;     // The canvas buffer width of Y component in pixel unit
   kal_int32                     canvasPitch;      // The canvas buffer pitch of Y component in pixel unit
   kal_int32                     canvasBPP;        // The bytes per pixel value of the canvas buffer

   kal_int32                     XOutputBase;      // X output offset relative to canvas buffer base address
   kal_int32                     YOutputBase;      // Y output offset relative to canvas buffer base address

   kal_uint32                    UVShiftBitH;      // Horizontal shift for calculating the U and V positions
   kal_uint32                    UVShiftBitV;      // Vertical shift for calculating the U and V postions

   kal_int32                     targetLeft;       // The target clip window left coordinate value
   kal_int32                     targetRight;      // The target clip window right coordinate value
   kal_int32                     targetTop;        // The target clip window top coordinate value
   kal_int32                     targetBottom;     // The target clip window bootom coordinate value

   FRAG_PROC_FUNC                pFragFunc;        // Internal fragment processing function
   POST_ITPL_FUNC                pPostITPLH;       // The horizontal post interpolation function
   POST_ITPL_FUNC                pPostITPLV;       // The vertical post interpolation function
   kal_uint32                    postITPLX;        // The post interpolation count of the X direction
   kal_uint32                    postITPLY;        // The post interpolation count of the Y direction

   kal_int32                     outputXPos;       // X output offet for current fragment processing
   kal_int32                     outputYPos;       // Y output offset for current fragment processing
   void                          *pOutputBuf[3];   // 

                                                   // Because the pixel data we received may be rotated,
                                                   // we may put the output from (left, top), (right, right)
                                                   // (left, bottom) or (right, bottom).
   kal_int32                     signOfXDir;       // Advance in X direction after outputing a pixel
   kal_int32                     signOfYDir;       // Advance in Y direction after outputing a pixel
   kal_bool                      switchXYVal;      // The source X and Y coordinates should be sitched.
                                                   // We have got rotated piexls with 90 or 270 degree.

   IUL_FIXED                     weightingH;       // Horizontal weighting value for bilinear interpolation
   IUL_FIXED                     weightingV;       // Vertical weighting value for bilinear interpolation
} SWJD_FRAGMENT_PROCESSOR;


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Reset the fragment processor to default state
 * @param pProcessor The specified fragment processor
 */
FRAG_PROCESSOR_STATUS_ENUM fragProcessorResetProc(SWJD_FRAGMENT_PROCESSOR *pProcessor);

/**
 * @brief Set the rotated angle of the source input data
 * @param pProcessor The specified fragment processor
 * @param rotation   The rotated angle of the input data
 * @return  
 */
FRAG_PROCESSOR_STATUS_ENUM fragProcessorSetRotation(SWJD_FRAGMENT_PROCESSOR         *pProcessor,
                                                    FRAG_PROCESSOR_TRANSFORM_ENUM   rotation);


/**
 * @brief Set the sampling factor of the source input data
 * @param pProcessor The specified fragment processor
 * @param compCount  Component count of the source input data
 * @param pHSampling Horizontal sampling factor of the input
 * @param pVSampling Vertical sampling factor of the input
 * @return  
 */
FRAG_PROCESSOR_STATUS_ENUM fragProcessorSetComponentInfo(SWJD_FRAGMENT_PROCESSOR *pProcessor,
                                                         kal_int32               compCount,
                                                         kal_int32               *pHSampling,
                                                         kal_int32               *pVSampling);


/**
 * @brief Set the desired scale ratio for processing
 * @param pProcessor The specified fragment processor
 * @param srcShiftH  Horizontal shift sed to calculate the horizontal block index
 * @param srcShiftV  Vertical shift used to calculate the vertical block index
 * @param srcWidth   Source image width for scaling into destination width
 * @param srcHeight  Source image height for scaling into destination height
 * @param dstWidth   The desired target width for scaling the source into
 * @param dstHeight  The desired target height for scaling the source into
 * @return
 */
FRAG_PROCESSOR_STATUS_ENUM fragProcessorSetScaleInfo(SWJD_FRAGMENT_PROCESSOR  *pProcessor,
                                                     kal_int32                srcShiftH,
                                                     kal_int32                srcShiftV,
                                                     kal_int32                srcWidth,
                                                     kal_int32                srcHeight,
                                                     kal_int32                dstWidth,
                                                     kal_int32                dstHeight);


/**
 * @brief Set the source fragment buffer for processing
 * @param pProcessor The specified fragment processor
 * @param pFragBuf0  Fragment buffer base address for Y channel
 * @param pFragBuf1  Fragment buffer base address for U channel
 * @param pFragBuf2  Fragment buffer base address for V channel
 * @param fragWidth  Fragment buffer width for Y channel
 * @param fragHeight Fragment buffer height for Y channel
 * @param fragPitch  Fragment buffer pitch for Y channel
 * @return
 */
FRAG_PROCESSOR_STATUS_ENUM fragProcessorSetFragBuffer(SWJD_FRAGMENT_PROCESSOR *pProcessor,
                                                      kal_uint8               *pFragBuf0,
                                                      kal_uint8               *pFragBuf1,
                                                      kal_uint8               *pFragBuf2,
                                                      kal_int32               fragWidth,
                                                      kal_int32               fragHeight,
                                                      kal_int32               fragPitch);


/**
 * @brief Set the canvas buffer for output pixels
 * @param pProcessor    The specified fragment processor
 * @param canvasFormat  Color format of the canvas buffer
 * @param pCanvasBuf0   Canvas buffer base address for Y channel
 * @param pCanvasBuf1   Canvas buffer base address for U channel
 * @param pCanvasBuf2   Canvas buffer base address for V channel
 * @param canvasWidth   Canvas buffer width for Y channel
 * @param canvasHeight  Canvas buffer height for Y channel
 * @param canvasPitch   Canvas buffer pitch for Y channel
 * @return
 */
FRAG_PROCESSOR_STATUS_ENUM fragProcessorSetCanvasBuffer(SWJD_FRAGMENT_PROCESSOR     *pProcessor,
                                                        FRAG_PROCESSOR_COLOR_ENUM   canvasFormat,
                                                        kal_uint8                   *pCanvasBuf0,
                                                        kal_uint8                   *pCanvasBuf1,
                                                        kal_uint8                   *pCanvasBuf2,
                                                        kal_int32                   canvasWidth,
                                                        kal_int32                   canvasHeight,
                                                        kal_int32                   canvasPitch);


/**
 * @brief Set the output offset relate to canvas origin
 * @param pProcessor    The specified fragment processor
 * @param XOutputBase   X output base coordinate relate to left
 * @param YOutputBase   Y output base coordinate relate to top
 * @return
 */
FRAG_PROCESSOR_STATUS_ENUM fragProcessorSetOutputOffset(SWJD_FRAGMENT_PROCESSOR  *pProcessor,
                                                        kal_int32                XOutputBase,
                                                        kal_int32                YOutputBase);


/**
 * @brief Set the traget clip clip window for output
 * @param pProcessor    The specified fragment processor
 * @param XClipOffset   Target clip window X coordinate
 * @param YClipOffset   Target clip window Y coordinate
 * @param clipWidth     Target clip window width in pixels
 * @param clipHeight    Target clip window height in pixels
 * @return
 */
FRAG_PROCESSOR_STATUS_ENUM fragProcessorSetTargetWindow(SWJD_FRAGMENT_PROCESSOR *pProcessor,
                                                        kal_int32               XClipOffset,
                                                        kal_int32               YClipOffset,
                                                        kal_int32               clipWidth,
                                                        kal_int32               clipHeight);


/**
 * @brief Query the desired fragment window for processing
 * @param pProcessor    The specified fragment processor
 * @param pSrcBlockX    Source X coordinate in block unit
 * @param pSrcBlockY    Source Y coordinate in block unit
 * @param pSrcBlockW    Source width in block unit
 * @param pSrcBlockH    Source height in block unit
 * @param pIgnoreTrail  The remain blocks of current row is not needed
 * @return
 */
FRAG_PROCESSOR_STATUS_ENUM fragProcessorGetFragWindow(SWJD_FRAGMENT_PROCESSOR *pProcessor,
                                                      kal_int32               *pSrcBlockX,
                                                      kal_int32               *pSrcBlockY,
                                                      kal_int32               *pSrcBlockW,
                                                      kal_int32               *pSrcBlockH,
                                                      kal_bool                *pIgnoreTrail);


/**
 * @brief Process the input fragment blocks
 * @param srcBlockW  Source width in blocks for processing
 * @param srcBlockH  Source height in blocks for processing
 */
FRAG_PROCESSOR_STATUS_ENUM fragProcessorProcessData(SWJD_FRAGMENT_PROCESSOR   *pProcessor,
                                                    kal_int32                 srcOffset,
                                                    kal_int32                 srcBlockW,
                                                    kal_int32                 srcBlockH);

#ifdef __cplusplus
}
#endif

#endif  // __SWJD_FRAGMENT_PROCESSOR_H__
