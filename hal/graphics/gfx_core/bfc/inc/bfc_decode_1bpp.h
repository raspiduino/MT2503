#ifndef __BFC_DECODE_1BPP_H__
#define __BFC_DECODE_1BPP_H__

#include "kal_general_types.h"

#ifdef __cplusplus
extern "C" {
#endif

void setPixel1BPPNormalNoClip(kal_uint8  *pBuffer,
                              kal_int32  pitch,
                              kal_uint32 pattern,
                              kal_uint32 select,
                              kal_uint32 unused);

void setPixel1BPPNormalWithClip(kal_uint8  *pBuffer,
                                kal_int32  pitch,
                                kal_uint32 pattern,
                                kal_uint32 select,
                                kal_uint32 unused,
                                kal_int32  left,
                                kal_int32  top,
                                kal_int32  width,
                                kal_int32  height);

void setPixel1BPPBoldNoClip(kal_uint8    *pBuffer,
                            kal_int32    pitch,
                            kal_uint32   pattern,
                            kal_uint32   select,
                            kal_uint32   unused);

void setPixel1BPPBoldWithClip(kal_uint8    *pBuffer,
                              kal_int32    pitch,
                              kal_uint32   pattern,
                              kal_uint32   select,
                              kal_uint32   unused,
                              kal_int32    left,
                              kal_int32    top,
                              kal_int32    width,
                              kal_int32    height);

void setPixel1BPPItalicNoClip(kal_uint8  *pBuffer,
                              kal_int32  pitch,
                              kal_uint32 pattern,
                              kal_uint32 select,
                              kal_uint32 index);

void setPixel1BPPItalicWithClip(kal_uint8  *pBuffer,
                                kal_int32  pitch,
                                kal_uint32 pattern,
                                kal_uint32 select,
                                kal_uint32 index,
                                kal_int32  left,
                                kal_int32  top,
                                kal_int32  width,
                                kal_int32  height);

void setPixel1BPPBoldItalicNoClip(kal_uint8  *pBuffer,
                                  kal_int32  pitch,
                                  kal_uint32 pattern,
                                  kal_uint32 select,
                                  kal_uint32 index);

void setPixel1BPPBoldItalicWithClip(kal_uint8  *pBuffer,
                                    kal_int32  pitch,
                                    kal_uint32 pattern,
                                    kal_uint32 select,
                                    kal_uint32 index,
                                    kal_int32  left,
                                    kal_int32  top,
                                    kal_int32  width,
                                    kal_int32  height);

void setPixel1BPPBorderNoClip(kal_uint8  *pBuffer,
                              kal_int32  pitch,
                              kal_uint32 pattern,
                              kal_uint32 color,
                              kal_uint32 border);

void setPixel1BPPBorderWithClip(kal_uint8  *pBuffer,
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

#endif  // __BFC_DECODE_1BPP_H__
