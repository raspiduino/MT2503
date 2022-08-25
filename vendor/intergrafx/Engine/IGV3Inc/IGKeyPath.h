/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
\*--------------------------------------------------------------------*/
#ifndef IG_KEY_PATH_I_H
#define IG_KEY_PATH_I_H

#include "IGMemoryPool.h"
#include "IGByteStream.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct IGKeyPath
{
    iguint32    m_numPosKeys;
    igint32*    m_posTimes;
    igreal*     m_posKeys;
    
    iguint32    m_numRotKeys;
    igint32*    m_rotTimes;
    igreal*     m_rotKeys;
    
    iguint32    m_numSclKeys;
    igint32*    m_sclTimes;
    igreal*     m_sclKeys;
    
    iguint32    m_numSorKeys;
    igint32*    m_sorTimes;
    igreal*     m_sorKeys;

}   IGKeyPath;

IGKeyPath*  IGKeyPath_i_new         ( IGMemoryPool*     pMemPool,
                                      iguint32          iNumPosKeys, 
                                      const igint32*    iPosTimes, 
                                      const igreal*     iPosKeys,
                                      iguint32          iNumRotKeys, 
                                      const igint32*    iRotTimes, 
                                      const igreal*     iRotKeys,
                                      iguint32          iNumSclKeys, 
                                      const igint32*    iSclTimes, 
                                      const igreal*     iSclKeys,
                                      iguint32          iNumSorKeys, 
                                      const igint32*    iSorTimes, 
                                      const igreal*     iSorKeys,
                                      IGErr*            pErr );

void        IGKeyPath_i_destroy     ( IGMemoryPool*     pMemPool, 
                                      IGKeyPath*        iPath, 
                                      IGErr*            pErr );

IGKeyPath*  IGKeyPath_i_deserialize ( IGMemoryPool*     pMemPool, 
                                      IGInputStream*    iInStream, 
                                      IGErr*            pErr );

void        IGKeyPath_i_serialize   ( IGMemoryPool*     pMemPool, 
                                      const IGKeyPath*  iPath, 
                                      IGOutputStream*   iOutStream, 
                                      IGErr*            pErr );

int         IGKeyPath_i_getDuration ( IGMemoryPool*     pMemPool, 
                                      const IGKeyPath*  iPath, 
                                      IGErr*            pErr );

IGKeyPath *       IGKeyPath_i_copy(   IGMemoryPool*   pMemPool,
                                      IGKeyPath*      pKey, 
                                      IGErr*          pErr );

IGKeyPath* IGKeyPath_i_copy_exscale	(   IGMemoryPool*   pMemPool,
										IGKeyPath*      pKey, 
										IGKeyPath*      pOldKey, 
										IGErr*          pErr );

IGKeyPath* IGKeyPath_i_rewrite_exscale( IGMemoryPool*   pMemPool,
										IGKeyPath*      pKey, 
										IGKeyPath*      pOldKey, 
										IGErr*          pErr );

IGKeyPath* IGKeyPath_i_rewrite_exscale2(   IGMemoryPool*   pMemPool,
										IGKeyPath*      pKey, 
										IGKeyPath*      pOldKey, 
										IGErr*          pErr );


#ifdef __cplusplus
}
#endif

#endif//IG_KEY_PATH_I_H
