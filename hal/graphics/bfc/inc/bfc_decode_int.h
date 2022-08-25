#ifndef __BFC_DECODE_INT_H__
#define __BFC_DECODE_INT_H__

#include "bfc_decode_raster.h"

#ifdef __cplusplus
extern "C"
#endif

SetPixelFuncNoClip getRasterFuncNoClip(BFC_RGB_FORMAT_ENUM format, BFC_STYLE_ENUM style);

SetPixelFuncWithClip getRasterFuncWithClip(BFC_RGB_FORMAT_ENUM format, BFC_STYLE_ENUM style);

#ifdef __cplusplus
}
#endif

#endif  // __BFC_DECODE_INT_H__
