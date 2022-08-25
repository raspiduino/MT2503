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
 *   swjd_huffman_decoder.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Prototypes of SW JPEG Huffman decoder.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SWJD_HUFFMAN_DECODER_H__
#define __SWJD_HUFFMAN_DECODER_H__

#include "kal_general_types.h"
#include "FSAL.h"

#ifndef MIN
#define MIN(x, y) (((x) < (y))? (x): (y))
#endif  // MIN

#ifndef MAX
#define MAX(x, y) (((x) < (y))? (y): (x))
#endif  // MIN

#ifndef ROUND
#define ROUND(x, y)     (((x) + (y) - 1) / (y))
#endif  // ROUND

#define HUFFMAN_DEC_BYPASS_WITH_RST_MARKER      (1)   // Bypassing Huffman encoded bitstream via restart marker
                                                      // This option is for partial decode with huge JPEGs
#define HUFFMAN_DEC_SUPPORT_TRANSPOSED_OUT      (1)   // Transpose the output when rotating 90 or 270 degrees
#define HUFFMAN_DEC_PRE_DEQUANTIZE_DC_VAL       (1)   // 
//#define HUFFMAN_DEC_PRE_DEQUANTIZE_AC_VAL     (0)    // 

#define HUFFMAN_DEC_RECORD_MCU_OFFSET_INFO      (0)

#define HUFFMAN_DEC_MAX_MCU_COUNT_PER_ROW       (22)  // Maximum output MCU per row, keep the output memory to ~32KB
#define HUFFMAN_DEC_MIN_MCU_OUTPUT_BUFFER       (10 * sizeof(HuffmanDecBlock))
#define HUFFMAN_DEC_LOOK_AHEAD_DC_BIT_COUNT     (8)   // Maximum Huffman encoded DC bitstream lookahead bits
#define HUFFMAN_DEC_LOOK_AHEAD_AC_BIT_COUNT     (8)   // Maximum Huffman encoded AC bitstream lookahead bits

#if (HUFFMAN_DEC_LOOK_AHEAD_AC_BIT_COUNT == 14)
   #define HUFFMAN_DEC_MAX_AC_COEFF_VAL_COUNT   (5)   // Maximum AC coefficients count in the 14-bit lookahead table
#elif (HUFFMAN_DEC_LOOK_AHEAD_AC_BIT_COUNT == 12)
   #define HUFFMAN_DEC_MAX_AC_COEFF_VAL_COUNT   (4)   // Maximum AC coefficients count in the 12-bit lookahead table
#elif (HUFFMAN_DEC_LOOK_AHEAD_AC_BIT_COUNT == 10)
   #define HUFFMAN_DEC_MAX_AC_COEFF_VAL_COUNT   (4)   // Maximum AC coefficients count in the 10-bit lookahead table
#elif (HUFFMAN_DEC_LOOK_AHEAD_AC_BIT_COUNT == 8)
   #define HUFFMAN_DEC_MAX_AC_COEFF_VAL_COUNT   (2)   // Maximum AC coefficients count in the 8-bit lookahead table
#else
   #error "Unsupported look ahead bit count!"
#endif

#define HUFFMAN_DEC_ADVANCE_TO_NEXT_DU_ROW()                                           \
   pScanInfo->curDURow++;                                                              \
   if (pScanInfo->curDURow < pScanInfo->VSampling)                                     \
   {                                                                                   \
      pCoeff = pScanInfo->pCoeffBase +                                                 \
               pScanInfo->curMCURow *                                                  \
               pScanInfo->MCURowSize +                                                 \
               pScanInfo->curDURow *                                                   \
               pScanInfo->DUOffset;                                                    \
   }                                                                                   \
   else                                                                                \
   {                                                                                   \
      pScanInfo->curDURow = 0;                                                         \
      pScanInfo->curMCURow++;                                                          \
      pCoeff = pScanInfo->pCoeffBase +                                                 \
               pScanInfo->curMCURow *                                                  \
               pScanInfo->MCURowSize;                                                  \
   }                                                                                   \
   pScanInfo->HRemainDU  = pScanInfo->HTotalDU;

typedef struct HuffmanDecoder    HuffmanDecoder;
typedef struct HuffmanScanInfo   HuffmanScanInfo;


typedef enum HUFFMAN_DEC_SOURCE_ENUM
{
   HUFFMAN_DEC_SOURCE_BASELINE,
   HUFFMAN_DEC_SOURCE_PROGRESSIVE
} HUFFMAN_DEC_SOURCE_ENUM;


typedef enum HUFFMAN_DEC_TRANSFORM_ENUM
{
   HUFFMAN_DEC_TRANSFORM_FLIP_HORIZONTAL_ONLY   = 0,  // Flipping image horizontally without rotation.
   HUFFMAN_DEC_TRANSFORM_FLIP_AND_ROTATE_CW_180 = 1,  // Flipping image and rotate clockwise 180 degree.
   HUFFMAN_DEC_TRANSFORM_FLIP_AND_ROTATE_CW_90  = 2,  // Flipping image and rotate clockwise 90 degree.
   HUFFMAN_DEC_TRANSFORM_FLIP_AND_ROTATE_CW_270 = 3,  // Flipping image and rotate clockwise 270 degree.
   HUFFMAN_DEC_TRANSFORM_NO_FLIP_ROTATE_CW_0    = 4,  // Decode the image without flipping and rotation.
   HUFFMAN_DEC_TRANSFORM_NO_FLIP_ROTATE_CW_90   = 5,  // Rotate clockwise 90 degree without flipping.
   HUFFMAN_DEC_TRANSFORM_NO_FLIP_ROTATE_CW_180  = 6,  // Rotate clockwise 180 degree without flipping.
   HUFFMAN_DEC_TRANSFORM_NO_FLIP_ROTATE_CW_270  = 7   // Rotate clockwise 270 degree without flipping.
} HUFFMAN_DEC_TRANSFORM_ENUM;


typedef enum HUFFMAN_DEC_STATUS_ENUM
{
   HUFFMAN_DEC_STATUS_RETURN_SUCCESS            =  0, // The specified operation performed successfully
   HUFFMAN_DEC_STATUS_INVALID_PARAMETER         = -1, // Invalid parameter for the specified operation
   HUFFMAN_DEC_STATUS_SEEK_FILE_FAILED          = -2, // Set the position of the source file failed
   HUFFMAN_DEC_STATUS_READ_FILE_FAILED          = -3, // Read the Huffman encoded source image file failed
   HUFFMAN_DEC_STATUS_BAD_HUFFMAN_TABLE         = -4, // The specified Huffman table is corrupted
   HUFFMAN_DEC_STATUS_SOURCE_CORRUPT            = -5, // The Huffman encoded bitstream is corrupted
   HUFFMAN_DEC_STATUS_INTERNAL_ERROR            = -6
} HUFFMAN_DEC_STATUS_ENUM;


typedef enum HUFFMAN_DEC_STATE_ENUM
{
   HUFFMAN_DEC_STATE_NEED_EXTRA_BITS            = 0,  // Huffman decoder needs more bits to decode the symbol
   HUFFMAN_DEC_STATE_ONE_SYMBOL_VAL             = 1,  // One symbol contained in the lookahead table entry
   HUFFMAN_DEC_STATE_EXTRA_COEFF_VAL            = 2   // One or more coefficients contained in the entry
} HUFFMAN_DEC_STATE_ENUM;


typedef struct HuffmanDecDCLookAhead
{
   HUFFMAN_DEC_STATE_ENUM  state;                     // Used to tell the content of the lookahead entry
   kal_int8                bits;                      // The bit length of the Huffman encoded symbol
   kal_int16               value;                     // The decoded symbol of IDCT coefficients
} HuffmanDecDCLookAhead;


typedef struct HuffmanDecDCTable
{
   HuffmanDecDCLookAhead   lookAhead[1 << HUFFMAN_DEC_LOOK_AHEAD_DC_BIT_COUNT];
   kal_uint8               symbol[256];               // Array to encoded the symbol value for decoding
   kal_int32               offset[17];                // Offset to the first symbol of specified length
   kal_int32               maxCode[18];               // Storing maximum Huffman codes for specified length
   kal_int32               minBits;                   // Field to store the minimum bits of the symbol value
   kal_bool                inited;                    // Field to check if the Huffman table has been inited
} HuffmanDecDCTable;


typedef struct HuffmanDecACLookAhead
{
   kal_int32               coeffInfo[HUFFMAN_DEC_MAX_AC_COEFF_VAL_COUNT];
   kal_int8                symbolBits;                // Field to store bit length of the symbol
   kal_int8                symbolRun;                 // Field to store the run value for the decoding
   kal_int16               symbolVal;                 // Field to store the symbol value for decoding
} HuffmanDecACLookAhead;


typedef struct HuffmanDecACTable
{
   HuffmanDecACLookAhead   lookAhead[1 << HUFFMAN_DEC_LOOK_AHEAD_AC_BIT_COUNT];
   kal_uint8               symbol[256];               // Array to encoded the symbol value for decoding
   kal_int32               offset[17];                // Offset to the first symbol of specified length
   kal_int32               maxCode[18];               // Storing maximum Huffman codes for specified length
} HuffmanDecACTable;


typedef struct HuffmanDecQuantTable
{
   kal_int16               quantVal[64];              // Quantization value for de-quantization
   kal_bool                initialized;               // Check if the quantization is initialized
} HuffmanDecQuantTable;


typedef struct HuffmanDecBlock
{
   kal_int16               coeffVal[64];              // Array for storing 8x8 block coefficients
} HuffmanDecBlock;


// Function pointer of the Huffman decoding function
typedef HUFFMAN_DEC_STATUS_ENUM (*HUFFMAN_DEC_FUNC)(HuffmanScanInfo      *pScanInfo,
                                                    kal_int32            LODValue,
                                                    kal_int32            blockSize,
                                                    kal_uint8            *pDeZigZag,
                                                    HuffmanDecQuantTable **pQuantTable);


typedef struct HuffmanScanInfo
{
   kal_uint32              bitBuffer;                 // 32-bit cache buffer for Huffman encoded bitstream
   kal_uint32              bitCount;                  // How many bits are available in the bit buffer

   kal_uint8               *pNextInput;               // Pointer to next input byte address of read buffer
   kal_int32               dataLeft;                  // How many bytes are available in the read buffer

   kal_uint32              EOBCount;                  // End of block count value for progressive decoding

   kal_int16               *pCoeffData;               // The coefficient output buffer for decoding

   kal_int16               *pHistoryBuf;              // The history buffer (coeff > LOD) for AC refine

   kal_uint8               *pReadBuffer;              // The read buffer base address for caching bitstream
   kal_int32               bufferSize;                // Field to store the user specified read buffer size

   STFSAL                  *pSourceFile;              // File handle of the Huffman encoded bitstream
   kal_int32               dataOffset;

   HUFFMAN_DEC_FUNC        pFunction;                 // Function pointer to the Huffman decoding function

   HuffmanDecDCTable       *pDCTable[3];              // Array to store the Huffman DC table for each component
   HuffmanDecACTable       *pACTable[3];              // Array to store the Huffman AC table for each component

   kal_int16               *pCoeffBase;               // The coefficient output buffer base address

   kal_int32               HTotalDU;                  // The max DU count of each MCU row for this scan
   kal_int32               HRemainDU;                 // The ramain DU count of current decoding DU row
   kal_int32               VRemainDU;                 // The remain vertical DU rows for current image

   kal_int32               *pDUMapping;               // DU to component mapping for accelerating decode
   kal_int32               DUPerMCU;                  // How many DUs are contained in one MCU unit

   kal_int32               compCount;                 // Component count of the Huffman encoded scan
   kal_int32               compIndex[3];              // Array to store the component ID of the frame

   kal_int16               lastDCVal[3];              // The last DC value for the DPCM encoded DC stream
   kal_int8                nextMarker;                // Field to store the marker encountered during decoding

   kal_int8                precisionLow;              // The low precision bit of the coefficients for this scan
   kal_int8                precisionHigh;             // The high precision bit of the coefficients for this scan

   kal_int8                spectralStart;             // Spectral start value for the coefficients of this scan
   kal_int8                spectralEnd;               // Spectral end value for the coefficients of this scan

   kal_int8                curDURow;                  // The variable for calculating output buffer address
                                                      // Because the decoding MCU data is interleaved,
                                                      // we may need the variable to calculate output address
                                                      // It's only used by the progressive JPEG image

   kal_int32               DUOffset;                  // The DU offset value realtive to the MCU

   kal_int32               curMCURow;                 // Current MCU row for progressive JPEG decoding
   kal_int32               MCURowSize;                // How many bytes are contained in one MCU row

   kal_int16               HSampling;                 // Horizontal sampling for non-interleaved scan
   kal_int16               VSampling;                 // Vertical sampling for non-interleaved scan
                                                      // The above 2 variable are used by progressive JPEG
                                                      // For the baseline image, we don't need the info

#if HUFFMAN_DEC_RECORD_MCU_OFFSET_INFO
   kal_int32               bitBufferPos[4];
   kal_int32               bitBufferNum;
   kal_int32               bitBufferAlgin;
#endif  // HUFFMAN_DEC_RECORD_MCU_OFFSET_INFO
} HuffmanScanInfo;


typedef struct HuffmanDecoder
{
   HuffmanScanInfo         scanInfo[15];              // The scan info for the decoding JPEG image
   HuffmanDecQuantTable    *pQuantTable[3];           // The quantization table for each component
   kal_int32               scanCount;                 // Total scan count of the decoding JPEG image

   kal_int16               *pOutputBuf;               // The coefficient buffer output base address

   kal_int16               *pHistoryBuf;              // The history buffer (coeff > LOD) for AC refine
   
   kal_int32               blockSize;                 // The block size of the coefficient buffer.
                                                      // It may be 64, 16, 8 or 1 depends on LOD value.
   kal_int32               outputSize;                // The max coefficient buffer output size

   HUFFMAN_DEC_SOURCE_ENUM frameType;                 // Baseline or progressive source image
   kal_int16               frameWidth;                // The decoding source image frame width
   kal_int16               frameHeight;               // The decoding source image frame height
   kal_int32               LODValue;                  // LOD needed for decoding the image frame
   kal_uint8               *pDeZigZag;

   kal_int32               RSTInterval;               // The frame restart interval value
   kal_int32               RSTCounter;                // Remaining restart value count

   kal_int32               DUMapping[10];             //
   kal_int32               DUPerMCU;                  //
   kal_int32               maxMCUOut;                 // Maximum MCU count can be buffered

   kal_int32               MCUOffset;                 // The offset of the first valid MCU coefficients
   kal_int32               MCUPerRow;                 // The maximum MCU count needed per MCU row
   kal_int32               MCUPerCol;                 // The maximum MCU count needed per MCU col
   kal_int32               MCUOutput;                 // Current MCU count in the output buffer

   kal_int32               compCount;                 // Component count of the source JPEG image
   kal_int32               DUOffset[3];               // The DU offset relative to the whole MCU.
                                                      // Because the MCU coefficients are interleaved,
                                                      // we may need to calculate DU offset for decoding.

   kal_int32               HSampling[3];              // Horizontal sampling factor of each component
   kal_int32               HMaxFactor;                // Horizontal max sampling factor of the image
   kal_int32               VSampling[3];              // Vertical sampling factor of each component
   kal_int32               VMaxFactor;                // Vertical max sampling factor of the image

#if HUFFMAN_DEC_SUPPORT_TRANSPOSED_OUT
   HUFFMAN_DEC_TRANSFORM_ENUM transform;
#endif  // HUFFMAN_DEC_SUPPORT_TRANSPOSED_OUT

   kal_bool                useHybridIDCTEnhance;
} HuffmanDecoder;

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Query the output buffer info for the specified setting
 * @param DUPerMCU   How man DUs contained in one MCU
 * @param MCUPerRow  How many MCUs existed per MCU row
 * @param pMCUSaved  Maximum MCUs coefficients can be output
 * @param pOutputBuf Output coefficient buffer size
 * @param pAlignment Output coefficient buffer alignment
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecQueryOutputBuffer(HUFFMAN_DEC_SOURCE_ENUM   sourceType,
                                                    kal_int32                 DUPerMCU,
                                                    kal_int32                 MCUPerRow,
                                                    kal_int32                 *pMCUSaved,
                                                    kal_int32                 *pOutputBuf,
                                                    kal_int32                 *pAlignment);

/**
 * @brief Set the output buffer for the Huffman decoder
 * @param pDecoder   The specified Huffman decoder
 * @param pBuffer    Coefficient output buffer base
 * @param bufferSize Coefficient output buffer size
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecSetOutputBuffer(HuffmanDecoder  *pDecoder,
                                                  void            *pBuffer,
                                                  kal_int32       bufferSize);


/**
 * @brief Reset the specified Huffman decoder to default state
 * @param pDecoder The specified Huffman decoder
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecResetDecoder(HuffmanDecoder *pDecoder);


/**
 * @brief Set the frame info for Huffman decoding
 * @param pDecoder      The specified Huffman decoder
 * @param frameType     Baseline or progressive image
 * @param frameWidth    The frame width in pixel unit
 * @param frameHeight   The frame height in pixel unit
 * @param MCUPerRow     Maximum MCU needed per MCU row
 * @param MCUPerCol     Maximum MCU needed per MCU col
 * @param LODValue      LOD value needed for decoding
 * @param RSTCounter    DC coefficient restart counter
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecSetFrameInfo(HuffmanDecoder           *pDecoder,
                                               HUFFMAN_DEC_SOURCE_ENUM  frameType,
                                               kal_int32                frameWidth,
                                               kal_int32                frameHeight,
                                               kal_int32                MCUPerRow,
                                               kal_int32                MCUPerCol,
                                               kal_int32                LODValue,
                                               kal_int32                RSTCounter);


/**
 * @brief Set frame sampling factors for each component
 * @param pDecoder   The specified Huffman decoder
 * @param compCount  How many components are included in the encoded frame
 * @param pHsampling Horizontal sampling factors for each component
 * @param pVSampling Vertical sampling factors for each component
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecSetComponentInfo(HuffmanDecoder *pDecoder,
                                                   kal_int32      compCount,
                                                   kal_int32      *pHSampling,
                                                   kal_int32      *pVSampling);


/**
 * @brief Transpose the coefficients according to the transform type
 * @param pDecoder   The specified Huffman decoder
 * @param transform  The desired transform type
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecSetTransform(HuffmanDecoder              *pDecoder,
                                               HUFFMAN_DEC_TRANSFORM_ENUM  transform);


/**
 * @brief Get the coefficient output buffer for IDCT processing
 * @param pDecoder   The specified Huffman decoder
 * @param ppBuffer   Pointer to get the coefficient output buffer
 * @param pBlockSize The block size of the coefficient output buffer
 * @param pMaxMCUOut Maximum MCU count can be saved in output buffer
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecGetOutputBuffer(HuffmanDecoder  *pDecoder,
                                                  void            **ppBuffer,
                                                  kal_int32       *pBlockSize,
                                                  kal_int32       *pMaxMCUOut);


/**
 * @brief Query the output coefficient count in MCU unit
 * @param pDecoder   The specified Huffman decoder
 * @param pMCUOffset Offset to the first MCU relative to the buffer base
 * @param pMCUCount  How many MCUs are saved in the coefficient buffer
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecQueryOutputData(HuffmanDecoder  *pDecoder,
                                                  kal_int32       *pMCUOffset,
                                                  kal_int32       *pMCUCount);


/**
 * @brief Reset the output buffer to default value
 * @param pDecoder the specified Huffman decoder
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecResetOutputBuffer(HuffmanDecoder  *pDecoder);


/**
 * @brief Function to construct quantization table
 * @param pRawData   Contains the raw data of quantization table
 * @param pQuanTable Pointer to the constructed quantization table
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecConstructQuantTable(kal_uint8            *pRawData,
                                                      HuffmanDecQuantTable *pQuantTable);


/**
 * @brief Function to construct Huffman DC table
 * @param pHuffBits  Array sotring the length info the Huffman codes
 * @param pHuffValue Array storing the Huffman encoded symbol value
 * @param pDCTable   Pointer to the constructed Huffman DC table
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecConstructDCTable(kal_uint8            *pHuffBits,
                                                   kal_uint8            *pHuffValue,
                                                   HuffmanDecDCTable    *pDCTable);


/**
 * @brief Function to construct the Huffman AC table
 * @param pHuffBits  Array sotring the length info the Huffman codes
 * @param pHuffValue Array storing the Huffman encoded symbol value
 * @param pACTable   Pointer to the constructed Huffman AC table
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecConstructACTable(kal_uint8            *pHuffBits,
                                                   kal_uint8            *pHuffValue,
                                                   HuffmanDecACTable    *pACTable);


/**
 * @brief Set the quantization table for the specified component
 * @param pDecoder      The specified Huffman decoder
 * @param compIndex     Specified component index value
 * @param pQuantTable   Pointer to the quantization table
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecSetQuantTable(HuffmanDecoder       *pDecoder,
                                                kal_int32            compIndex,
                                                HuffmanDecQuantTable *pQuantTable);


/**
 * @brief Add one sca for the Huffman decoder
 * @param pDecoder   The specified Huffman decoder
 * @param pScanIndex Pointer to get the scan index
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecAddScanInfo(HuffmanDecoder   *pDecoder,
                                              kal_int32        *pScanIndex);


/**
 * @brief Add one component to the sepcified scan
 * @param pDecoder   The specified Huffman decoder
 * @param scanIndex  The specified scan index value
 * @param compIndex  The specified component index value
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecAddComponentInfo(HuffmanDecoder *pDecoder,
                                                   kal_int32      scanIndex,
                                                   kal_int32      compIndex);


/**
 * @brief Seth the Huffman table for the component
 * @param pDecoder   The specified Huffman decoder
 * @param scanIndex  The specified scan index value
 * @param compIndex  The specified component index value
 * @param pDCTable   Pointer to the Huffman DC table
 * @param pACTable   Pointer to the Huffman AC table
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecSetHuffmanTable(HuffmanDecoder     *pDecoder,
                                                  kal_int32          scanIndex,
                                                  kal_int32          compIndex,
                                                  HuffmanDecDCTable  *pDCTable,
                                                  HuffmanDecACTable  *pACTable);


/**
 * @brief Set the precision value of the specified scan
 * @param pDecoder      The specified Huffman decoder
 * @param scanIndex     The specified scan index value
 * @param precisionLow  Low precision of the coefficients
 * @param precisionHigh High precision of the coefficients
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecSetPrecision(HuffmanDecoder *pDecoder,
                                               kal_int32      scanIndex,
                                               kal_int32      precisionLow,
                                               kal_int32      precisionHigh);


/**
 * @brief Set the spectral value of the specified scan
 * @param pDecoder      The specified Huffman decoder
 * @param scanIndex     The specified scan index value
 * @param spectralStart Spectral start of the coefficients
 * @param spectralEnd   Spectral end of the coefficients
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecSetSepctral(HuffmanDecoder   *pDecoder,
                                              kal_int32        scanIndex,
                                              kal_int32        spectalStart,
                                              kal_int32        spectralEnd);


/**
 * @brief Set the source file for the specified scan
 * @param pDecoder      The specified Huffman decoder
 * @param scanIndex     The specified scan index value
 * @param pSource       The source image file handle
 * @param ECSOffset     Huffman encoded stream start offset
 * @param pReadBuffer   Cache buffer for Huffman decoding
 * @param bufferSize    The size of the cache buffer
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecSetSourceFile(HuffmanDecoder  *pDecoder,
                                                kal_int32       scanIndex,
                                                STFSAL          *pSource,
                                                kal_int32       ECSOffset,
                                                kal_uint8       *pReadBuffer,
                                                kal_int32       bufferSize);


/**
 * @brief Function to query the minimum bits for one MCU
 * @param pDecoder   The specified Huffman decoder
 * @param scanIndex  The specified scan index value
 * @param pMinBits   The minimum bits of one MCU
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecQueryMinMCUBits(HuffmanDecoder *pDecoder,
                                                  kal_int32      scanIndex,
                                                  kal_int32      *pMinBits);


HUFFMAN_DEC_STATUS_ENUM huffmanDecDecodeOneMCU(HuffmanScanInfo      *pScanInfo,
                                               kal_int32            LODValue,
                                               kal_int32            blockSize,
                                               kal_uint8            *pDeZigZag,
                                               HuffmanDecQuantTable **pQuantTable);


HUFFMAN_DEC_STATUS_ENUM huffmanDecDecodeACFirst(HuffmanScanInfo      *pScanInfo,
                                                kal_int32            LODValue,
                                                kal_int32            blockSize,
                                                kal_uint8            *pDeZigZag,
                                                HuffmanDecQuantTable **pQuantTable);


HUFFMAN_DEC_STATUS_ENUM huffmanDecDecodeDCRefine(HuffmanScanInfo      *pScanInfo,
                                                 kal_int32            LODValue,
                                                 kal_int32            blockSize,
                                                 kal_uint8            *pDeZigZag,
                                                 HuffmanDecQuantTable **pQuantTable);


HUFFMAN_DEC_STATUS_ENUM huffmanDecDecodeACRefine(HuffmanScanInfo      *pScanInfo,
                                                 kal_int32            LODValue,
                                                 kal_int32            blockSize,
                                                 kal_uint8            *pDeZigZag,
                                                 HuffmanDecQuantTable **pQuantTable);


/**
 * @brief Function to bypass N MCU count data
 * @param pDecoder   The specified Huffman decoder
 * @param MCUCount   How many MCUs should be bypassed
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecBypassECSData(HuffmanDecoder *pDecoder,
                                                kal_int32      MCUCount);


/**
 * @brief Function to decode one MCU count data
 * @param pDecoder   The specified Huffman decoder
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecDecodeECSData(HuffmanDecoder   *pDecoder);
HUFFMAN_DEC_STATUS_ENUM huffmanDecDecodeECSDataToHW(HuffmanDecoder *pDecoder);


/**
 * @brief Function to pass information about using HybridHW in Huffman Dec or not.
 * @param pDecoder   The specified Huffman decoder
 * @param useHybridIDCTEnhance   variable that indicate using HybridHW in Huffman Dec or not to enhance performance
 */
HUFFMAN_DEC_STATUS_ENUM huffmanDecSetHybridIDCTEnable(
   HuffmanDecoder       *pDecoder,
   kal_bool              useHybridIDCTEnhance);

#ifdef __cplusplus
}
#endif

#endif  // __SWJD_HUFFMAN_DECODER_H__
