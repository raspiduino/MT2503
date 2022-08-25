/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
\*--------------------------------------------------------------------*/
#ifndef IG_OBJ_TABLE_I_H
#define IG_OBJ_TABLE_I_H

#include "IGComDef.h"
#include "IGMemoryPool.h"
#include "IGObjCache.h"
#include "IGNameCache.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct
{
    IGObjCache  m_objects;
    IGNameCache m_names;

}   IGObjTable;

void    IGObjTable_i_initialize     ( IGMemoryPool*     pMemPool, 
                                      IGObjTable*       iTable, 
                                      iguint32          iCapacity, 
                                      IGErr*            pErr );

void    IGObjTable_i_destroyData    ( IGMemoryPool*     pMemPool, 
                                      IGObjTable*       iTable, 
                                      IGErr*            pErr );

void    IGObjTable_i_clear          ( IGMemoryPool*     pMemPool, 
                                      IGObjTable*       iTable, 
                                      IGErr*            pErr );

void*   IGObjTable_i_getByIndex     ( IGMemoryPool*     pMemPool, 
                                      const IGObjTable* iTable, 
                                      int               iIndex, 
                                      IGErr*            pErr );

void*   IGObjTable_i_getByName      ( IGMemoryPool*     pMemPool, 
                                      const IGObjTable* iTable, 
                                      const char*       iName, 
                                      IGErr*            pErr );

void    IGObjTable_i_getNameByIndex ( IGMemoryPool*     pMemPool, 
                                      const IGObjTable* iTable, 
                                      int               iIndex, 
                                      char              iName[ IG_NAMELEN+1 ], 
                                      IGErr*            pErr );

void*   IGObjTable_i_getObjByIndex  ( IGMemoryPool*     pMemPool, 
                                      const IGObjTable* iTable, 
                                      int               iIndex, 
                                      IGErr*            pErr );

int     IGObjTable_i_getSize        ( IGMemoryPool*     pMemPool, 
                                      const IGObjTable* iTable, 
                                      IGErr*            pErr );

void    IGObjTable_i_put            ( IGMemoryPool*     pMemPool, 
                                      IGObjTable*       iTable, 
                                      const char*       iName, 
                                      const void*       iObject, 
                                      IGErr*            pErr );

void    IGObjTable_i_remove         ( IGMemoryPool*     pMemPool, 
                                      IGObjTable*       iTable, 
                                      const char*       iName, 
                                      IGErr*            pErr );

#ifdef __cplusplus
}
#endif

#endif//IG_OBJ_TABLE_I_H
