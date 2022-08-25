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
 *   swjd_dequant_idct_unit.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Prototypes of SW JPEG Dequant-IDCT unit.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SWJD_DEQUANT_IDCT_UNIT_H__
#define __SWJD_DEQUANT_IDCT_UNIT_H__

#include "kal_general_types.h"
#include "iul_x_math.h"

#ifndef MIN
#define MIN(x, y) (((x) < (y))? (x): (y))
#endif  // MIN

/******************************************************************************************************************
 * The IDCT processing unit processes the coefficient data from Huffman decoder from JPEG decoding scenario.
 * In order to support rotation, we do need the Huffman decoder to transpose the coefficients accordingly.
 * For rotating 90 and 270 degrees, the input coefficients should be dezigazged and transposed. Also, the
 * output buffer get from the IDCT unit is the address store the rotated pixel at coorinate (0, 0) instead of 
 * the lowest buffer address.
 *
 *     Rotation angle: 0 degree
 *     Coordinate (0, 0) == Lowest buffer address  ***********
 *                                                 *    *    *
 *                                                 *   * *   *
 *                                                 *  *   *  *
 *                                                 * * * * * *
 *                                                 **       **
 *                                                 ***********
 *
 *    Rotation angle: 180 degree
 *                           Lowest buffer address ***********
 *                                                 **       **
 *                                                 * * * * * *
 *                                                 *  *   *  *
 *                                                 *   * *   *
 *                                                 *    *    *
 *                                                 *********** Coorinate (0, 0)
 *
 ******************************************************************************************************************/


#define DEQUANT_IDCT_SUPPORT_TRANSFORM             (1)   // 1 for supporting flipping and rotation transform
#define DEQUANT_IDCT_PRE_CALCUX_OFFSET             (1)   // 1 for calculate output offset before processing

/*
 * The following define the minimum output buffer size for IDCT unit
 * 10 represents the maximum DU count of the JPEG images
 * sizeof(kal_uint8) represents the output type of the pixel data
 * 64 means the pixel count of the 8x8 block for JPEG images
 */
#define DEQUANT_IDCT_MIN_OUTPUT_BUFFER             (10 * sizeof(kal_uint8) * 64)

#define DEQUANT_IDCT_LOD_FOR_IDCT_1x1              (0)   // LOD value when resizing 8x8 blocks to 1x1
#define DEQUANT_IDCT_LOD_FOR_IDCT_2x2              (2)   // LOD value when resizing 8x8 blocks to 2x2
#define DEQUANT_IDCT_LOD_FOR_IDCT_3x3              (8)   // LOD value when resizing 8x8 blocks to 3x3
#define DEQUANT_IDCT_LOD_FOR_IDCT_4x4              (13)  // LOD value when resizing 8x8 blocks to 4x4
#define DEQUANT_IDCT_LOD_FOR_IDCT_5x5              (25)  // LOD value when resizing 8x8 blocks to 5x5
#define DEQUANT_IDCT_LOD_FOR_IDCT_6x6              (33)  // LOD value when resizing 8x8 blocks to 6x6
#define DEQUANT_IDCT_LOD_FOR_IDCT_7x7              (47)  // LOD value when resizing 8x8 blocks to 7x7
#define DEQUANT_IDCT_LOD_FOR_IDCT_8x8              (63)  // LOD value when docoding the 8x8 blocks 

typedef enum DEQUANT_IDCT_TRANSFORM_ENUM
{
   DEQUANT_IDCT_TRANSFORM_FLIP_HORIZONTAL_ONLY     = 0,  // Flipping image horizontally without rotation.
   DEQUANT_IDCT_TRANSFORM_FLIP_AND_ROTATE_CW_180   = 1,  // Flipping image and rotate clockwise 180 degree.
   DEQUANT_IDCT_TRANSFORM_FLIP_AND_ROTATE_CW_90    = 2,  // Flipping image and rotate clockwise 90 degree.
   DEQUANT_IDCT_TRANSFORM_FLIP_AND_ROTATE_CW_270   = 3,  // Flipping image and rotate clockwise 270 degree.
   DEQUANT_IDCT_TRANSFORM_NO_FLIP_ROTATE_CW_0      = 4,  // Decode the image without flipping and rotation.
   DEQUANT_IDCT_TRANSFORM_NO_FLIP_ROTATE_CW_90     = 5,  // Rotate clockwise 90 degree without flipping.
   DEQUANT_IDCT_TRANSFORM_NO_FLIP_ROTATE_CW_180    = 6,  // Rotate clockwise 180 degree without flipping.
   DEQUANT_IDCT_TRANSFORM_NO_FLIP_ROTATE_CW_270    = 7   // Rotate clockwise 270 degree without flipping.
} DEQUANT_IDCT_TRANSFORM_ENUM;


typedef enum DEQUANT_IDCT_OUTPUT_FORMAT_ENUM
{
   DEQUANT_IDCT_OUTPUT_FORMAT_DEFAULT              = 0,  // Output the format according to the source sampling factor 
   DEQUANT_IDCT_OUTPUT_FORMAT_YUV420               = 1,  // Output YUV420 color format for the YUV420 coefficients
   DEQUANT_IDCT_OUTPUT_FORMAT_YUV422               = 2   // Output YUV422 color format for the YUV422 coefficients
} DEQUANT_IDCT_OUTPUT_FORMAT_ENUM;                       // Actually, we don't support upsampling or downsampling
                                                         // in the IDCT unit. In order to use the YUV420 or YUV422
                                                         // formats, the input sampling factor must also be in YUV420
                                                         // or YUV422.

typedef enum DEQUANT_IDCT_STATUS_ENUM
{
   DEQUANT_IDCT_STATUS_RETURN_SUCCESS              =  0, // The function is called and returned successfully
   DEQUANT_IDCT_STATUS_INVALID_PARAMETER           = -1, // The input parameter is invalid or not correct
   DEQUANT_IDCT_STATUS_INTERNAL_ERROR              = -2  // Internal setting error during the initialization
} DEQUANT_IDCT_STATUS_ENUM;


/*
 * Function pointer to process IDCT 1x1 block
 */
typedef void (*IDCT1x1)(kal_int16  *pCoeff,              // Base address of the specified coefficient input buffer
                        kal_int32  advanceH,             // Horizontal input buffer advance after processing one DU
                        kal_int32  advanceV,             // Vertical input buffer advance after processing one DU
                        kal_uint8  *pYOutput,            // Base address of the specified Y channel output buffer
                        kal_uint8  *pUOutput,            // Base address of the specified U channel output buffer
                        kal_uint8  *pVOutput);           // Base address of the specified V channel output buffer


/*
 * Function pointer to process IDCT NxN block
 * Where N is less than 8 and greater than 1
 */
typedef void (*IDCTNxN)(kal_int16  *pCoeff,
                        kal_uint8  *pOutput,
                        kal_int32  pitch);

typedef enum DEQUANT_IDCT_COEFF_ENUM
{
   DEQUANT_IDCT_COEFF_TYPE_YUV444                  = 0,
   DEQUANT_IDCT_COEFF_TYPE_YUV422                  = 1,
   DEQUANT_IDCT_COEFF_TYPE_YUV422V                 = 2,
   DEQUANT_IDCT_COEFF_TYPE_YUV420                  = 3,
   DEQUANT_IDCT_COEFF_TYPE_YUV411                  = 4,
   DEQUANT_IDCT_COEFF_TYPE_Y_ONLY                  = 5
} DEQUANT_IDCT_COEFF_ENUM;

typedef struct SWJD_DEQUANT_IDCT_UNIT
{
   kal_int32                        compCount;           // The component count of the input coefficients
   DEQUANT_IDCT_COEFF_ENUM          coeffFormat;

   kal_uint32                       VSampling[3];        // Vertical sampling factor of the input coefficients
   kal_uint32                       HSampling[3];        // Horizontal sampling factor of the input coefficients

   kal_uint8                        *pOutputBuf[3];      // The output buffer for Y, U and V pixel data
   kal_uint8                        *pOutputBase[3];     // Address to the coorinate (0, 0) of the output pixel
   kal_int32                        outputBias[3];       // Output bias to the first pixel output offset
   DEQUANT_IDCT_OUTPUT_FORMAT_ENUM  outputFormat;        // This is the user specified output color format
   kal_int32                        outputWidth;         // The specified output buffer width for Y channel
   kal_int32                        outputHeight;        // The specified output buffer height for Y channel
   kal_int32                        outputPitch[3];      // The specified output buffer pitch for Y, U and V channels

   void                             *pIDCTNxN;           // Function pointer to the IDCT transform function

   kal_int16                        *pCoeffBuf;          // The base address of the input coefficient buffer
   kal_int32                        blockSize;           // Block size of the input coefficient buffer
                                                         // The block size may be one of the following:
                                                         // 1x1, 2x2, 4x4 or 8x8 depends on scaling ratio
   kal_int32                        maxMCUInput;         // The maximum input coefficients in MCU unit
   kal_int32                        scaleShift;          // Value to represent 1/2^scaleShift scaling ratio
                                                         // i.e. For 1/2 resizing, the value should be
                                                         // And the input block size should be set to 4x4

   DEQUANT_IDCT_TRANSFORM_ENUM      transform;           // The user specified output pixel arragement order

   kal_int32                        DUPerMCU;            // Total data unit count of one MCU (i.e. should be <= 10)
   kal_int32                        maxMCUPerRow;        // The user specified maximum frame width in MCU unit
   kal_int32                        maxMCUPerCol;        // The user specified maximum frame height in MCU unit

   kal_int32                        advanceH[3];         // Horizontal advance the output buffer to next DU
   kal_int32                        advanceV[3];         // Vertical advance the output buffer to next DU row
   kal_int32                        MCUOffset[3];        // Horizontal advance the output buffer to next MCU
   kal_int32                        MCURowSize[3];       // The buffer size of one MCU row for calculating offsets

#if DEQUANT_IDCT_PRE_CALCUX_OFFSET
   kal_int32                        nextOffset[16];      // Precalculate the offsets when advancing DU, MCU hroizontally,
                                                         // and vertically.
#endif  // DEQUANT_IDCT_PRE_CALCUX_OFFSET

   kal_int32                        MCUProcessedH;       // How many MCU are processed in the hroizontal direction
   kal_int32                        MCUProcessedV;       // How many MCU are processed in the vertical direction 
} SWJD_DEQUANT_IDCT_UNIT;


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Query the scale shift depends on the source and target dimension
 * @param sourceWidth   The specified source image width
 * @param sourceHeight  The specified source image height
 * @param targetWidth   The specified target image width
 * @param targetHeight  The specified target image height
 * @param pScaleShift   Scale shift depends on the scaling ratio
 * @param pLODValue     LOD value depends on the scaling ratio
 * @return
 * @remarks 
 */
DEQUANT_IDCT_STATUS_ENUM dequantIDCTQueryScaleShift(kal_int32  sourceWidth,
                                                    kal_int32  sourceHeight,
                                                    kal_int32  targetWidth,
                                                    kal_int32  targetHeight,
                                                    kal_int32  *pScaleShift,
                                                    kal_int32  *pLODValue);


/**
 * @brief Query the required output buffer size depends on the input data
 * @param DUPerMCU      Total block count for one MCU of the input coefficients
 * @param MCUPerRow     Maximum MCU count per MCU row of the input coefficients
 * @param scaleShift    Specified 1/2, 1/4, 1/8 scaling ratio or no resize
 * @param *pOutputBuf   The output buffer size depends on the input parameters
 * @param *pAlignment   The alignment requirement of the output buffer address
 * @return
 * @remarks
 */
DEQUANT_IDCT_STATUS_ENUM dequantIDCTQueryOutputBuffer(kal_int32 DUPerMCU,
                                                      kal_int32 MCUPerRow,
                                                      kal_int32 scaleShift,
                                                      kal_int32 *pOutputBuf,
                                                      kal_int32 *pAlignment);


/**
 * @brief Reset dequant IDCT unit to default state
 * @param pDequantIDCT   The specified IDCT processing unit
 */
DEQUANT_IDCT_STATUS_ENUM dequantIDCTResetUnit(SWJD_DEQUANT_IDCT_UNIT  *pDequantIDCT);


/**
 * @brief Set the input coefficient buffer base address
 * @param   pDequantIDCT   The specified IDCT processing unit
 * @param   pCoeffBuf      The input coefficient buffer base address
 * @param   blockSize      1x1, 2x2, 4x4 or 8x8 depends on the scaling ratio
 * @param   maxMCUInput    Maximum input MCU count for each processing
 * @return
 * @remarks
 */
DEQUANT_IDCT_STATUS_ENUM dequantIDCTSetCoeffBuffer(SWJD_DEQUANT_IDCT_UNIT  *pDequantIDCT,
                                                   void                    *pCoeffBuf,
                                                   kal_int32               blockSize,
                                                   kal_int32               maxMCUInput);


/**
 * @brief Set the output frame width and height in MCU unit
 * @param pDequantIDCT  The specified IDCT processing unit
 * @param maxMCUPerRow  The output frame width in MCU unit
 * @param maxMCUPercol  The output frame height in MCU unit
 * @return
 * @remarks
 */
DEQUANT_IDCT_STATUS_ENUM dequantIDCTSetFrameInfo(SWJD_DEQUANT_IDCT_UNIT *pDequantIDCT,
                                                 kal_int32              maxMCUPerRow,
                                                 kal_int32              maxMCUPerCol);


/**
 * @brief Set the Y, U and V output buffer related info
 * @param pDequantIDCT  The specified IDCT processing unit
 * @param outputFormat  The specified output color format
 * @param pOutputBuf0   Y channel buffer base address
 * @param pOutputBuf1   U channel buffer base address
 * @param pOutputBuf2   V channel buffer base address
 * @param outputWidth   Y channel buffer output width
 * @param outputHeight  Y channel buffer output height
 * @param outputPitch   Y channel buffer output pitch
 * @param scalShift     The desired scaling ratio
 */
DEQUANT_IDCT_STATUS_ENUM dequantIDCTSetOutputBuffer(SWJD_DEQUANT_IDCT_UNIT          *pDequantIDCT,
                                                    DEQUANT_IDCT_OUTPUT_FORMAT_ENUM outputFormat,
                                                    kal_uint8                       *pOutputBuf0,
                                                    kal_uint8                       *pOutputBuf1,
                                                    kal_uint8                       *pOutputBuf2,
                                                    kal_int32                       outputWidth,
                                                    kal_int32                       outputHeight,
                                                    kal_int32                       outputPitch,
                                                    kal_uint32                      scaleShift);


/**
 * @brief Set the sampling factor of the input coefficients
 * @param pDequantIDCT  The specified IDCT processing unit
 * @param compCount     Component count of the input coefficients
 * @param pHSampling    Coefficient's horizontal sampling factor
 * @param pVSampling    Coefficient's vertical sampling factor
 */
DEQUANT_IDCT_STATUS_ENUM dequantIDCTSetComponentInfo(SWJD_DEQUANT_IDCT_UNIT   *pDequantIDCT,
                                                     kal_int32                compCount,
                                                     kal_int32                *pHSampling,
                                                     kal_int32                *pVSampling);


/**
 * @brief Set the desired transform operation
 * @param pDequantIDCT  The specified IDCT processing unit
 * @param transform     The specified transform operation
 */
DEQUANT_IDCT_STATUS_ENUM dequantIDCTSetTransform(SWJD_DEQUANT_IDCT_UNIT       *pDequantIDCT,
                                                 DEQUANT_IDCT_TRANSFORM_ENUM  transform);


/**
 * @brief Get the Y, U and V output buffer info
 * @param pDequantIDCT  The specified IDCT processing unit
 * @param ppOutputBuf0  Pointer of pointer to get Y channel buffer
 * @param ppOutputBuf1  Pointer of pointer to get U channel buffer
 * @param ppOutputBuf2  Pointer of pointer to get V channel buffer
 * @param pOutputWidth  Pointer to get Y channel buffer width
 * @param pOutputHeight Pointer to get Y channel buffer height
 * @param pOutputPitch  Pointer to get Y channel buffer pitch
 */
DEQUANT_IDCT_STATUS_ENUM dequantIDCTGetOutputBuffer(SWJD_DEQUANT_IDCT_UNIT *pDequantIDCT,
                                                    void                   **ppOutputBuf0,
                                                    void                   **ppOutputBuf1,
                                                    void                   **ppOutputBuf2,
                                                    kal_uint32             *pOutputWidth,
                                                    kal_uint32             *pOutputHeight,
                                                    kal_uint32             *pOutputPitch);


/**
 * @brief Process the Y, U and V coefficients
 * @param pDequantIDCT  The specified IDCT processing unit
 * @param MCUOffset     Offset to the input buffer of first MCU
 * @param MCUCount      Total coefficient count in MCU unit
 */
DEQUANT_IDCT_STATUS_ENUM dequantIDCTProcessDUData(SWJD_DEQUANT_IDCT_UNIT   *pDequantIDCT,
                                                  kal_int32                MCUOffset,
                                                  kal_int32                MCUCount);


/**
 * @brief Reset the IDCT unit output buffer
 * @param PDequantIDCT  The specified IDCT processing unit
 */
DEQUANT_IDCT_STATUS_ENUM dequantIDCTResetOutputBuffer(SWJD_DEQUANT_IDCT_UNIT *pDequantIDCT);



DEQUANT_IDCT_STATUS_ENUM dequantIDCTGetHwOutputToDstBuf(SWJD_DEQUANT_IDCT_UNIT *pDequantIDCT);


#ifdef __cplusplus
}
#endif

#endif  // __SWJD_DEQUANT_IDCT_UNIT_H__
