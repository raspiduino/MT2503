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

#ifndef __BMP_FONT_ENCODE_H__
#define __BMP_FONT_ENCODE_H__

typedef unsigned int kal_uint32;
typedef int kal_int32;
typedef unsigned char kal_uint8;
typedef char kal_int8;


//#include "kal_release.h"

#define BF_ENC_MAX_KEY_LENGTH       8
#define BF_ENC_MAX_PRED_COUNT       (1 << BF_ENC_MAX_KEY_LENGTH)
#define BF_ENC_MAX_SUB_BLOCKS       256
#define BF_ENC_MAX_GLYPH_SUB_BLOCKS 256*2

#define BF_ENC_SET_BITS(count, bits)                                                    \
{                                                                                       \
    bitBuffer = ((bitBuffer << count) | (bits & (1 << (count)) - 1));                   \
    bitCount += count;                                                                  \
    while (bitCount >= 8)                                                               \
    {                                                                                   \
        pDstData[codedLen] = (kal_uint8)(bitBuffer >> (bitCount - 8));                  \
        bitCount  -= 8;                                                                 \
        codedLen ++;                                                                    \
    }                                                                                   \
}

#define BF_ENC_FLUSH_BITS()                                                             \
{                                                                                       \
    kal_uint8 tempVal;                                                                  \
                                                                                        \
    if (bitCount)                                                                       \
    {                                                                                   \
        tempVal = (kal_uint8)((bitBuffer & ((1 << (bitCount)) - 1)) << (8 - bitCount)); \
        pDstData[codedLen] = tempVal;                                                   \
        bitBuffer = 0;                                                                  \
        bitCount  = 0;                                                                  \
        codedLen++;                                                                     \
    }                                                                                   \
}

typedef enum BF_ENC_STATUS_ENUM
{
    BF_ENC_STATUS_RETURN_SUCCESS    =  0,                       ///< No error, everything is normal
    BF_ENC_STATUS_OUT_OF_MEMORY     = -1,                       ///< The encoder can't alloc more memory
    BF_ENC_STATUS_INVALID_ENCODER   = -2,                       ///< The encoder context is invalid
    BF_ENC_STATUS_INVALID_WIDTH     = -3,                       ///< The glyph width is invalid  
    BF_ENC_STATUS_INVALID_HEIGHT    = -4                        ///< The glyph height is invalid
} BF_ENC_STATUS_ENUM;

typedef enum BF_ENC_STATE_ENUM
{
    BF_ENC_STATE_INITIALIZED        = 0,                        ///< The encoder is in initialized state
    BF_ENC_STATE_GEN_PROFILE        = 1,                        ///< The encoder is generating statistic info
    BF_ENC_STATE_START_ENCODE       = 2                         ///< The encoder is encoding the font glyphs
} BF_ENC_STATE_ENUM;

typedef struct BF_ENC_BLOCK_STRUCT
{
	kal_uint32		keyVal;                                     ///< The key value of the block
	kal_uint32      pattern;                                    ///< The pattern value of the block
} BF_ENC_BLOCK_STRUCT;

typedef struct BF_ENC_GLYPH_STRUCT
{
    kal_int32           blockCnt;                               ///< Sub-block count of the glyph
	BF_ENC_BLOCK_STRUCT subBlock[BF_ENC_MAX_GLYPH_SUB_BLOCKS];        ///< The sub-block info of the glyph
} BF_ENC_GLYPH_STRUCT;

typedef struct BF_ENC_PROFILE_STRUCT
{
    kal_uint32      pattern;                                    ///< The pattern of the block
    kal_uint32      count;                                      ///< Total count of the pattern
	kal_uint32      bitLen;                                     ///< The compressd code length
	kal_uint32      codeVal;                                    ///< The pattern compress code
} BF_ENC_PROFILE_STRUCT;

typedef struct BF_ENC_KEY_INFO_STRUCT
{
    BF_ENC_PROFILE_STRUCT   subBlock[BF_ENC_MAX_SUB_BLOCKS];    ///< Block info for each pattern
} BF_ENC_KEY_INFO_STRUCT;

typedef struct BF_LEVEL1_TABLE_STRUCT
{
    kal_uint8               entry[15];                          ///< Level1 table pattern data
} BF_LEVEL1_TABLE_STRUCT;

typedef struct BF_LEVEL2_TABLE_STRUCT
{
    kal_uint8               entry[256][15];                     ///< Level2 table pattern data
} BF_LEVEL2_TABLE_STRUCT;

typedef struct BF_ENC_STRUCT
{
    BF_ENC_STATE_ENUM       encState;                           ///< Current encoder state
    BF_ENC_KEY_INFO_STRUCT  *pKeyEntry1;                        ///< The statistic profile(KeyVal = 0)
    BF_ENC_KEY_INFO_STRUCT  *pKeyEntry2;                        ///< The statistic profile(General) 
    BF_LEVEL1_TABLE_STRUCT  LV1Table;                           ///< The level1 dictionary table
    BF_LEVEL2_TABLE_STRUCT  LV2Table;                           ///< The level2 dictionary table
    kal_uint8               dstData[256];
} BF_ENC_STRUCT;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Function to initialize the font encoder object
 */
BF_ENC_STATUS_ENUM bfEncInitEncoder(BF_ENC_STRUCT *pEncoder);


/**
 * @brief   Function to generate the profile info of the glyph
 * @param   pSrcData    The glyph source data for statistic
 * @param   glyphWidth  The width of the source glyph data
 * @param   glyphHeight The height of the source glyph data
 * @return  If the function succeeds, it will return BF_ENC_STATUS_RETURN_SUCCESS
 */
BF_ENC_STATUS_ENUM bfEncGenProfileInfo(BF_ENC_STRUCT    *pEncoder,
                                       const kal_uint8  *pSrcData,
                                       kal_int32        glyphWidth,
                                       kal_int32        glyphHeight);

/**
 * @brief   Function to start encoding the glyph data.
 * @param   pEncoder    The bitmap font encoder object
 * @param   pSrcData    The glyph source data for compression
 * @param   glyphWidth  The width of the source glyph data
 * @param   glyphHeight The height of the source glyph data
 * @param   pDstData    The compressed destination glyph data
 * @param   dstLength   The destination buffer length
 * @param   pOutLength  The compressed glyph length
 * @return  If the function succeeds, it will return BF_ENC_STATUS_RETURN_SUCCESS
 */
BF_ENC_STATUS_ENUM bfEncEncodeGlyph(BF_ENC_STRUCT   *pEncoder,
                                    const kal_uint8 *pSrcData,
                                    kal_int32       glyphWidth,
                                    kal_int32       glyphHeight,
                                    kal_uint8       *pDstData,
                                    kal_int32       DstLength,
                                    kal_int32       *pOutLength);

/**
 * @brief   pEncoder    The bitmap font encoder object
 * @param   pLV1Table   The level1 dictionary table
 * @param   pLength1    The level1 table length
 * @param   pLV2Table   The level2 dictionary table
 * @param   pLength2    The level2 table length
 * @return  If the function succeeds, it will return BF_ENC_STATUS_RETURN_SUCCESS
 */
BF_ENC_STATUS_ENUM bfEncGetDictionary(BF_ENC_STRUCT  *pEncoder,
                                      void           *pLV1Table,
                                      kal_int32      *pLength1,
                                      void           *pLV2Table,
                                      kal_int32      *pLength2);

/**
 * @brief   Function to deinitalize the font encoder object
 * @param   pEncoder    The bitmap font encoder object
 */
void bfEncDeInitEncoder(BF_ENC_STRUCT  *pEncoder);

#ifdef __cplusplus
}
#endif

#endif  // __BMP_FONT_ENCODE_H__
