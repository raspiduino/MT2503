#ifndef __BFC_DECODE_ARGB8888_H__
#define __BFC_DECODE_ARGB8888_H__

#include "kal_general_types.h"

#ifdef __cplusplus
extern "C" {
#endif

void setPixelARGB8888NormalNoClip(kal_uint8  *pBuffer,
                                  kal_int32  pitch,
                                  kal_uint32 pattern,
                                  kal_uint32 color,
                                  kal_uint32 unused);

void setPixelARGB8888NormalWithClip(kal_uint8  *pBuffer,
                                    kal_int32  pitch,
                                    kal_uint32 pattern,
                                    kal_uint32 color,
                                    kal_uint32 unused,
                                    kal_int32  left,
                                    kal_int32  top,
                                    kal_int32  width,
                                    kal_int32  height);

void setPixelARGB8888BoldNoClip(kal_uint8    *pBuffer,
                                kal_int32    pitch,
                                kal_uint32   pattern,
                                kal_uint32   color,
                                kal_uint32   unused);

void setPixelARGB8888BoldWithClip(kal_uint8    *pBuffer,
                                  kal_int32    pitch,
                                  kal_uint32   pattern,
                                  kal_uint32   color,
                                  kal_uint32   unused,
                                  kal_int32    left,
                                  kal_int32    top,
                                  kal_int32    width,
                                  kal_int32    height);

void setPixelARGB8888ItalicNoClip(kal_uint8  *pBuffer,
                                  kal_int32  pitch,
                                  kal_uint32 pattern,
                                  kal_uint32 color,
                                  kal_uint32 index);

void setPixelARGB8888ItalicWithClip(kal_uint8  *pBuffer,
                                    kal_int32  pitch,
                                    kal_uint32 pattern,
                                    kal_uint32 color,
                                    kal_uint32 index,
                                    kal_int32  left,
                                    kal_int32  top,
                                    kal_int32  width,
                                    kal_int32  height);

void setPixelARGB8888BoldItalicNoClip(kal_uint8  *pBuffer,
                                      kal_int32  pitch,
                                      kal_uint32 pattern,
                                      kal_uint32 color,
                                      kal_uint32 index);

void setPixelARGB8888BoldItalicWithClip(kal_uint8  *pBuffer,
                                        kal_int32  pitch,
                                        kal_uint32 pattern,
                                        kal_uint32 color,
                                        kal_uint32 index,
                                        kal_int32  left,
                                        kal_int32  top,
                                        kal_int32  width,
                                        kal_int32  height);

void setPixelARGB8888BorderNoClip(kal_uint8  *pBuffer,
                                  kal_int32  pitch,
                                  kal_uint32 pattern,
                                  kal_uint32 color,
                                  kal_uint32 border);

void setPixelARGB8888BorderWithClip(kal_uint8  *pBuffer,
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

#endif  // __BFC_DECODE_ARGB8888_H__
