/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
\*--------------------------------------------------------------------*/
#ifndef IG_MORPH_PATH_I_H
#define IG_MORPH_PATH_I_H

#include "IGByteStream.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct
{
    iguint32    m_numKeys;
    iguint32    m_numVerts;
    igint32*    m_keyTimes;
    igreal*     m_keyVerts;

}   IGMorphPath;


typedef struct
{
    iguint32    m_numVertIndex;
	iguint16*   m_keyVertIndex;//[1]
	igreal*		m_startUVPos;//[2]
	
	iguint32    m_numKeys;
	igint32*    m_keyTimes;//[1]
	igreal*		m_keyDeltaUVPos;//[2]

}   IGUVAnimGroup;

/*--------------------------------------------------------------------*\
|   IGMorphPath private interface
\*--------------------------------------------------------------------*/

IGMorphPath*    IGMorphPath_i_new           ( IGMemoryPool*         iMemPool,  
											  iguint32              iNumKeys,
                                              iguint32              iNumVerts,
                                              igint32*              ikeyTimes,
                                              igreal*               iKeyVerts,
											  IGErr*                iErr);


void            IGMorphPath_i_destroy       ( IGMemoryPool*         pMemPool, 
                                              IGMorphPath*          pPath, 
                                              IGErr*                pErr );

IGMorphPath*    IGMorphPath_i_deserialize   ( IGMemoryPool*         pMemPool, 
                                               IGInputStream*       pInStream, 
                                               IGErr*               pErr );

void            IGMorphPath_i_serialize     ( IGMemoryPool*         pMemPool, 
                                              const IGMorphPath*    pPath, 
                                              IGOutputStream*       pOutStream, 
                                              IGErr*                pErr );


/*--------------------------------------------------------------------*\
|   IGVAnimGroup private interface
\*--------------------------------------------------------------------*/
void            IGVAnimGroup_i_destroy       ( IGMemoryPool*         pMemPool, 
                                              IGUVAnimGroup*          pUVAnimGroup, 
                                              IGErr*                pErr );

IGUVAnimGroup*    IGVAnimGroup_i_deserialize   ( IGMemoryPool*         pMemPool, 
                                               IGInputStream*       pInStream, 
											   iguint16		uvTile,
                                               IGErr*               pErr );

void            IGVAnimGroup_i_serialize     ( IGMemoryPool*         pMemPool, 
                                              const IGUVAnimGroup*    pUVAnimGroup, 
                                              IGOutputStream*       pOutStream, 
											  iguint16 uvTile,
                                              IGErr*                pErr );


typedef struct
{
    iguint32    m_numGroup;
    IGUVAnimGroup**    m_pUVAnimArray;

}   IGUVAnimCollection;

/*--------------------------------------------------------------------*\
|   IGUVAnimCollection private interface
\*--------------------------------------------------------------------*/

IGUVAnimCollection* IGUVAnimCollection_i_new(   IGMemoryPool*   pMemPool, 
											 int GroupNum,
											 IGErr*          pErr );

void            IGUVAnimCollection_i_destroy       ( IGMemoryPool*         pMemPool, 
                                              IGUVAnimCollection*          pCollection, 
                                              IGErr*                pErr );

IGUVAnimCollection*    IGUVAnimCollection_i_deserialize   ( IGMemoryPool*         pMemPool, 
                                               IGInputStream*       pInStream, 
											   iguint16		uvTile,
                                               IGErr*               pErr );

void            IGUVAnimCollection_i_serialize     ( IGMemoryPool*         pMemPool, 
                                              const IGUVAnimCollection*    pCollection, 
                                              IGOutputStream*       pOutStream, 
											  iguint16 uvTile,
                                              IGErr*                pErr );

#ifdef __cplusplus
}
#endif

#endif//IG_MORPH_PATH_I_H
