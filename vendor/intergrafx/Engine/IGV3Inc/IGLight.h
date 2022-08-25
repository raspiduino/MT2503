/**
@file IGLight.h  
@brief 

@par Last updated:


@par Copyright (c) 2005 InterGrafx, Inc. All rights reserved.
InterGrafx CONFIDENTIAL AND PROPRIETARY
@par
This source is the sole property of InterGrafx Inc. Reproduction or
Utilization of this source in whole or in part is forbidden without
The written consent of InterGrafx Inc.

@par History:


@par Description:
more description here.
*/
#ifndef IG_LIGHT_H
#define IG_LIGHT_H

#include "IGMesh.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _IGLightRec
{
    IGNode          m_super;
    IGLightType     m_type;
    igreal          m_illum[ 3 ];

} IGLight;

/*--------------------------------------------------------------------*\
|   IGLight public interface
\*--------------------------------------------------------------------*/
/**
IGLight constructor.
Allocates a new IGLight with the maximum intensity pointing in the
negative z direction of its parent's space.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iName
  Initial name of IGLight; will be internally unique up to only @a MAXNAMELEN
  characters
@param iType
  What type of light this will be
@param pErr
  Stores error code raised by this function
@return
  Handle to newly created IGLight; NULL if creation failed
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
   IGLight* hLight = IGLight_new(pMemPool, "myLight", IGLIGHT_DIRECTIONAL, pErr);

   if (hLight) {
     ...
   }
@endcode
@see IGLight_destroy
*/
IGLight*    IGLight_new             ( IGMemoryPool* pMemPool, 
                                      const char*   iName, 
                                      IGLightType   iType,
                                      IGErr*        pErr );
/**
IGLight destructor.
Deallocates an IGLight.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iLight
  Handle to the IGLight
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hLight references a previously allocated IGLight.
  if (hLight) {
    IGLight_destroy(pMemPool, hLight, pErr);
  }
@endcode
@see IGLight_new
*/
void        IGLight_destroy         ( IGMemoryPool* pMemPool, 
                                      IGLight*      iLight, 
                                      IGErr*        pErr );
/**
Gets an IGLight's intensity.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iLight
  Handle to the IGLight
@param oIntens
  Pointer to buffer where the R,G, and B intensities are written
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hLight references a previously allocated IGLight.
  igreal lightColor[3];
  IGLight_getIntensity(pMemPool, hLight, lightColor, pErr);
@endcode
@see IGLight_setIntensity
*/
void        IGLight_getIntensity    ( IGMemoryPool* pMemPool, 
                                      IGLight*      iLight,
                                      igreal        oIntens[ 3 ], 
                                      IGErr*        pErr );
/**
Sets an IGLight's intensity.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iLight
  Handle to the IGLight
@param iIntens
  Array of intensities for R,G, and B components
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hLight references a previously allocated IGLight.
  // Set an IGLight to an orangish color
  igreal lightColor = {IG_ONE, IG_ONE_HALF, IG_ZERO};
  IGLight_setIntensity(pMemPool, hLight, lightColor, pErr);
@endcode
@see IGLight_getIntensity
*/
void        IGLight_setIntensity    ( IGMemoryPool* pMemPool, 
                                      IGLight*      iLight, 
                                      const igreal  iIntens[ 3 ], 
                                      IGErr*        pErr );

#ifdef __cplusplus
}
#endif

#endif//IG_LIGHT_H

