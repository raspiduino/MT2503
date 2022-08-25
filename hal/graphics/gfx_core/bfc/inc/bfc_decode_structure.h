#ifndef __BFC_DECODE_STRUCTURE_H__
#define __BFC_DECODE_STRUCTURE_H__

#include "kal_general_types.h"
#include "bfc_enum.h"

typedef struct BFC_LEVEL1_TABLE_STRUCT
{
   kal_uint8            entry[15];              ///< Level1 table pattern data
} BFC_LEVEL1_TABLE_STRUCT;

typedef struct BFC_LEVEL2_TABLE_STRUCT
{
   kal_uint8            entry[256][15];         ///< Level2 table pattern data
} BFC_LEVEL2_TABLE_STRUCT;

typedef struct BFC_DECODE_STRUCT_T
{
   BFC_LEVEL1_TABLE_STRUCT *pLV1Table;          ///< Level1 dictionary table
   BFC_LEVEL2_TABLE_STRUCT *pLV2Table;          ///< Level2 dictionary table

   kal_int32                  fontWidth;        ///< Original font width
   kal_int32                  fontHeight;       ///< Original font height
   BFC_STYLE_ENUM             fontStyle;        ///< Desired font style
   kal_uint32                 fontColor;        ///< Desired font color
   kal_uint32                 borderColor;      ///< Desired border color

   kal_uint8*                 pCanvasBase;      ///< Canvas buffer address
   kal_int32                  canvasWidth;      ///< Canvas buffer width
   kal_int32                  canvasPitch;      ///< canvas buffer pitch
   kal_int32                  canvasHeight;     ///< Canvas buffer height
   BFC_RGB_FORMAT_ENUM        canvasFormat;     ///< Canvas buffer format
   kal_int32                  canvasBPPVal;     ///< Cnavas bits per pixel

   void                       *drawNoClip;      ///< Draw pixel without clip
   void                       *drawWithClip;    ///< Draw pixel with clip

   kal_int32                  clipWidth;        ///< Clipping window width
   kal_int32                  clipHeight;       ///< Clipping window height
   kal_int32                  clipLeft;         ///< Clipping window left
   kal_int32                  clipRight;        ///< Clipping window right
   kal_int32                  clipTop;          ///< Clipping window top
   kal_int32                  clipBottom;       ///< Clipping window bottom

   kal_uint32                 working[4];       ///< Temporary working buffer
} BFC_DECODE_STRUCT;

typedef struct BFC_DECODE_STRUCT_T* BFC_DECODER_HANDLE;

#endif  // __BFC_DECODE_STRUCTURE_H__
