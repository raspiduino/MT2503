/** 
 *
 *	@file		IGV5BoneBatch.h 
 *
 *  @brief		Handles a batch of bones. Most time application programmer don't use this directly
 *
 *	@author		Charles Shih-I Yeh
 *
*/

#ifndef _IGV5BONEBATCH_H_
#define _IGV5BONEBATCH_H_

#include "IGV5Vertex.h"

#ifdef __cplusplus
extern "C" {
#endif


/*!***************************************************************************
@struct		IGV5BoneBatches
@brief		A structure for processing vertices into bone batches
*****************************************************************************/
typedef struct
{

	int	*pnBatches;			/*!< Space for nBatchBoneMax bone indices, per batch */
	int	*pnBatchBoneCnt;	/*!< Actual number of bone indices, per batch */
	int	*pnBatchOffset;		/*!< Offset into triangle array, per batch */
	int nBatchBoneMax;		/*!< Stored value as was passed into Create() */
	int	nBatchCnt;			/*!< Number of batches to render */

}  IGV5BoneBatches;


/*!***********************************************************************
 @fn		IGV5BoneBatches_Create
 @param		pnVtxNumOut		vertex count
 @param		pVtxOut			Output vertices (program must free() this)
 @param		pui32Idx		index array for triangle list
 @param		nVtxNum			vertex count
 @param		pVtx			vertices
 @param		nStride			Size of a vertex (in bytes)
 @param		nOffsetWeight	Offset in bytes to the vertex bone-weights
 @param		eTypeWeight		Data type of the vertex bone-weights
 @param		nOffsetIdx		Offset in bytes to the vertex bone-indices
 @param		eTypeIdx		Data type of the vertex bone-indices
 @param		nTriNum			Number of triangles
 @param		nBatchBoneMax	Number of bones a batch can reference
 @param		nVertexBones	Number of bones affecting each vertex
 @return	IGV5ERR_NONE if successful
 @brief	Fills the bone batch structure
*************************************************************************/
IGV5Err IGV5BoneBatches_Create(
	IGV5BoneBatches *pThis, 
	int					* pnVtxNumOut,
	char				**  pVtxOut,
	unsigned int		* pui32Idx,
	int			nVtxNum,
	char			*  pVtx,
	int			nStride,
	int			nOffsetWeight,
	EPVRTDataType	eTypeWeight,
	int			nOffsetIdx,
	EPVRTDataType	eTypeIdx,
	int			nTriNum,
	int			nBatchBoneMax,
	int			nVertexBones);

/*!***********************************************************************
 @fn		IGV5BoneBatches_Release
 @brief		Destroy the bone batch structure
*************************************************************************/
void IGV5BoneBatches_Release(IGV5BoneBatches *pThis);

#ifdef __cplusplus
}
#endif

#endif


