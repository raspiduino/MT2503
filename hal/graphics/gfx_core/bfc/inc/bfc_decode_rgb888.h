#ifndef __BFC_DECODE_RGB888_H__
#define __BFC_DECODE_RGB888_H__

#include "kal_general_types.h"

#ifdef __cplusplus
extern "C" {
#endif

void setPixelRGB888NormalNoClip(kal_uint8  *pBuffer,
                                kal_int32  pitch,
                                kal_uint32 pattern,
                                kal_uint32 color,
                                kal_uint32 unused);

void setPixelRGB888NormalWithClip(kal_uint8  *pBuffer,
                                  kal_int32  pitch,
                                  kal_uint32 pattern,
                                  kal_uint32 color,
                                  kal_uint32 unused,
                                  kal_int32  left,
                                  kal_int32  top,
                                  kal_int32  width,
                                  kal_int32  height);

void setPixelRGB888BoldNoClip(kal_uint8    *pBuffer,
                              kal_int32    pitch,
                              kal_uint32   pattern,
                              kal_uint32   color,
                              kal_uint32   unused);

void setPixelRGB888BoldWithClip(kal_uint8   *pBuffer,
                                kal_int32   pitch,
                                kal_uint32  pattern,
                                kal_uint32  color,
                                kal_uint32  unused,
                                kal_int32   left,
                                kal_int32   top,
                                kal_int32   width,
                                kal_int32   height);

void setPixelRGB888ItalicNoClip(kal_uint8  *pBuffer,
                                kal_int32  pitch,
                                kal_uint32 pattern,
                                kal_uint32 color,
                                kal_uint32 index);

void setPixelRGB888ItalicWithClip(kal_uint8  *pBuffer,
                                  kal_int32  pitch,
                                  kal_uint32 pattern,
                                  kal_uint32 color,
                                  kal_uint32 index,
                                  kal_int32  left,
                                  kal_int32  top,
                                  kal_int32  width,
                                  kal_int32  height);

void setPixelRGB888BoldItalicNoClip(kal_uint8  *pBuffer,
                                    kal_int32  pitch,
                                    kal_uint32 pattern,
                                    kal_uint32 color,
                                    kal_uint32 index);

void setPixelRGB888BoldItalicWithClip(kal_uint8  *pBuffer,
                                      kal_int32  pitch,
                                      kal_uint32 pattern,
                                      kal_uint32 color,
                                      kal_uint32 index,
                                      kal_int32  left,
                                      kal_int32  top,
                                      kal_int32  width,
                                      kal_int32  height);

void setPixelRGB888BorderNoClip(kal_uint8  *pBuffer,
                                kal_int32  pitch,
                                kal_uint32 pattern,
                                kal_uint32 color,
                                kal_uint32 border);

void setPixelRGB888BorderWithClip(kal_uint8  *pBuffer,
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

#endif  // __BFC_DECODE_RGB888_H__
