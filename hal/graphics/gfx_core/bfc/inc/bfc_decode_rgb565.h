#ifndef __BFC_DECODE_RGB565_H__
#define __BFC_DECODE_RGB565_H__

#include "kal_general_types.h"

#ifdef __cplusplus
extern "C" {
#endif

void setPixelRGB565NormalNoClip(kal_uint8  *pBuffer,
                                kal_int32  pitch,
                                kal_uint32 pattern,
                                kal_uint32 color,
                                kal_uint32 unused);

void setPixelRGB565NormalWithClip(kal_uint8  *pBuffer,
                                  kal_int32  pitch,
                                  kal_uint32 pattern,
                                  kal_uint32 color,
                                  kal_uint32 unused,
                                  kal_int32  left,
                                  kal_int32  top,
                                  kal_int32  width,
                                  kal_int32  height);

void setPixelRGB565BoldNoClip(kal_uint8    *pBuffer,
                              kal_int32    pitch,
                              kal_uint32   pattern,
                              kal_uint32   color,
                              kal_uint32   unused);

void setPixelRGB565BoldWithClip(kal_uint8    *pBuffer,
                                kal_int32    pitch,
                                kal_uint32   pattern,
                                kal_uint32   color,
                                kal_uint32   unused,
                                kal_int32    left,
                                kal_int32    top,
                                kal_int32    width,
                                kal_int32    height);

void setPixelRGB565ItalicNoClip(kal_uint8  *pBuffer,
                                kal_int32  pitch,
                                kal_uint32 pattern,
                                kal_uint32 color,
                                kal_uint32 index);

void setPixelRGB565ItalicWithClip(kal_uint8  *pBuffer,
                                  kal_int32  pitch,
                                  kal_uint32 pattern,
                                  kal_uint32 color,
                                  kal_uint32 index,
                                  kal_int32  left,
                                  kal_int32  top,
                                  kal_int32  width,
                                  kal_int32  height);

void setPixelRGB565BoldItalicNoClip(kal_uint8  *pBuffer,
                                    kal_int32  pitch,
                                    kal_uint32 pattern,
                                    kal_uint32 color,
                                    kal_uint32 index);

void setPixelRGB565BoldItalicWithClip(kal_uint8  *pBuffer,
                                      kal_int32  pitch,
                                      kal_uint32 pattern,
                                      kal_uint32 color,
                                      kal_uint32 index,
                                      kal_int32  left,
                                      kal_int32  top,
                                      kal_int32  width,
                                      kal_int32  height);

void setPixelRGB565BorderNoClip(kal_uint8  *pBuffer,
                                kal_int32  pitch,
                                kal_uint32 pattern,
                                kal_uint32 color,
                                kal_uint32 border);

void setPixelRGB565BorderWithClip(kal_uint8  *pBuffer,
                                  kal_int32  pitch,
                                  kal_uint32 pattern,
                                  kal_uint32 color,
                                  kal_uint32 border,
                                  kal_int32  left,
                                  kal_int32  top,
                                  kal_int32  width,
                                  kal_int32  height);

#ifdef __cplusplus
}
#endif

#endif  // __BFC_DECODE_RGB565_H__
