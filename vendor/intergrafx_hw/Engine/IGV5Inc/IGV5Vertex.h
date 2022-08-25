/******************************************************************************



******************************************************************************/
#ifndef _IGV5VERTEX_H_
#define _IGV5VERTEX_H_

#include "IGV5Matrix.h"

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
** Enumerations
****************************************************************************/
typedef enum  {
	EPODDataNone,
	EPODDataFloat,
	EPODDataInt,
	EPODDataUnsignedShort,
	EPODDataRGBA,
	EPODDataARGB,
	EPODDataD3DCOLOR,
	EPODDataUBYTE4,
	EPODDataDEC3N,
	EPODDataFixed16_16,
	EPODDataUnsignedByte,
	EPODDataShort,
	EPODDataShortNorm,
	EPODDataByte,
	EPODDataByteNorm,
	EPODDataUnsignedByteNorm,
	EPODDataUnsignedShortNorm,
	EPODDataUnsignedInt
} EPVRTDataType;

/*****************************************************************************
** Functions
*****************************************************************************/

/*!***************************************************************************
 @fn			IGV5PODVertex_ReadVec
 @brief			pV
 @param				pData
 @param				eType
 @param				nCnt
 @brief		Read a vector
*****************************************************************************/
void IGV5PODVertex_ReadVec(Vec4 *pV, void* pData, EPVRTDataType eType, int	nCnt);

/*!***************************************************************************
 @fn			IGV5PODVertex_ReadInt
 @brief			pV
 @param				pData
 @param				eType
 @brief		Read an int
*****************************************************************************/
void IGV5PODVertex_ReadInt(unsigned int	* pV, void* pData, EPVRTDataType eType);


/*!***************************************************************************
 @fn			PVRTVertexWrite
 @brief			pOut
 @param				eType
 @param				nCnt
 @param				pV
 @brief		Write a vector
*****************************************************************************/
void IGV5VertexWriteVec(
	void				* pOut,
	EPVRTDataType	eType,
	int			nCnt,
	Vec4	* pV);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __cplusplus
}
#endif

#endif /* _PVRTVERTEX_H_ */

/*****************************************************************************
 End of file (IGV5Vertex.h)
*****************************************************************************/

