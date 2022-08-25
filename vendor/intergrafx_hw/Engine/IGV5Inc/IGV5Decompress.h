/******************************************************************************

@file   IGV5Decompress.h

@brief  texture compression related stuff

******************************************************************************/

#ifndef __IGV5DECOMPRESS_H
#define __IGV5DECOMPRESS_H

#include "IGV5Def.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ETC_MIN_TEXWIDTH  4
#define ETC_MIN_TEXHEIGHT  4

/*!***********************************************************************
 @fn		IGV5DecompressPVRTC
 @param			pCompressedData The PVRTC texture data to decompress
 @param			Do2bitMode Signifies whether the data is PVRTC2 or PVRTC4
 @param			XDim X dimension of the texture
 @param			YDim Y dimension of the texture
 @param		pResultImage The decompressed texture data
 @brief	Decompresses PVRTC to RGBA 8888
*************************************************************************/
void IGV5DecompressPVRTC(void *pCompressedData, int Do2bitMode, int XDim, int YDim, unsigned char* pResultImage);

/*!***********************************************************************
@fn		IGV5DecompressETC
@param			pSrcData The ETC texture data to decompress
@param			x X dimension of the texture
@param			y Y dimension of the texture
@param		pDestData The decompressed texture data
@param			nMode The format of the data
@return		The number of bytes of ETC data decompressed
@brief	Decompresses ETC to RGBA 8888
*************************************************************************/
IGV5Err IGV5DecompressETC(void * const pSrcData, unsigned int x, unsigned int y, void *pDestData, int nMode);

#ifdef __cplusplus
}
#endif

#endif 



