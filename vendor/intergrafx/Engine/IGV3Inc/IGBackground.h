/**
@file IGBackground.h 
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
#ifndef IG_BACKGROUND_H
#define IG_BACKGROUND_H

#include "IGTexture.h"

#ifdef __cplusplus
extern "C"
{
#endif
    /**
    * Generalized background environment of a scene.
    * Functions in 3 modes: 2D background color, 2D background image, or 3D
    * skybox. A user selects the background mode upon creation.
    */
typedef struct _IGBackgroundRec
{
    IGBackgroundType    m_type;
    char                m_name[ IG_NAMELEN +1 ];
    igcolor             m_bgndColor;
    IGTexture*          m_bgndImage;
} IGBackground;

/*--------------------------------------------------------------------*\
|   IGBackground public interface
\*--------------------------------------------------------------------*/

/**
IGBackground color field constructor.
Allocates a new IGBackground consisting of a 2D color field.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iName
  Initial name of IGBackground; will be internally unique up to only
  @a MAXNAMELEN characters
@param iColor
  Device-dependent color for the IGBackground
@param pErr
  Stores error code raised by this function
@return
  Handle to newly created IGBackground; NULL if creation failed
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hTex references a previously allocated IGTexture.
  // Get device representation of blue.
  igcolor devColor = IGTexture_getDeviceColor(pMemPool, hTex, 0x0000FF, pErr);

  // Create a background blue color field.
  IGBackground* hBack = IGBackground_newFromColor(pMemPool, "myColorField", devColor, pErr);

  if (hBack) {
    ...
  }
@endcode
@see IGBackground_newFromTexture
@see IGBackground_newFromSkyTexture
*/
IGBackground*   IGBackground_newFromColor       ( IGMemoryPool* pMemPool, 
                                                  const char*   iName, 
                                                  igcolor       iColor,
                                                  IGErr*        pErr );

/**
IGBackground image constructor.
Allocates a new IGBackground consisting of a 2D image.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iTex
  Handle to IGTexture with desired image
@param pErr
  Stores error code raised by this function
@return
  Handle to newly created IGBackground; NULL if creation failed
@note
  The IGBackground inherits the name of the underlying IGTexture.
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // Create a background image from a bitmap.
  IGTexture* hBackTex = IGTexture_newFromFile(pMemPool, "BackTex.bmp", pErr);
  IGBackground* hBack = IGBackground_newFromTexture(pMemPool, hBackTex, pErr);

  IGBackground_setName(pMemPool, hBack, "myBackground", pErr);

  // hScene references a previously allocated IGScene.
  IGScene_setActiveBackground(pMemPool, hScene, "myBackground", pErr);
@endcode
@see IGBackground_newFromImage
@see IGBackground_newFromSkyTexture
*/

IGBackground*   IGBackground_newFromTexture     ( IGMemoryPool* pMemPool, 
                                                  IGTexture*    iTex, 
                                                  IGErr*        pErr );
/**
IGBackground destructor.
Deallocates an IGBackground.
@param pMemPool
Pointer to the memory pool where engine data is stored
@param pBgnd
Handle to the IGBackground
@param pErr
Stores error code raised by this function
@return
void
@par Example:
@code
// pMemPool points to a previously allocated IGMemoryPool.
// hBack references a previously allocated IGBackground.
if (hBack) {
IGBackground_destroy(pMemPool, hBack, pErr);
}
@endcode
@see IGBackground_newFromColor
@see IGBackground_newFromTexture
@see IGBackground_newFromSkyTexture
*/
void            IGBackground_destroy            ( IGMemoryPool* pMemPool, 
                                                  IGBackground* pBgnd, 
                                                  IGErr*        pErr );

/**
IGBackground destructor (bare version).
Deallocates an IGBackground, but not include the texture within it.
@param pMemPool
Pointer to the memory pool where engine data is stored
@param pBgnd
Handle to the IGBackground
@param pErr
Stores error code raised by this function
@return
void
@see IGBackground_destroy
*/
void            IGBackground_destroyBare        ( IGMemoryPool* pMemPool, 
                                                  IGBackground* pBgnd, 
                                                  IGErr*        pErr );


/**
Get the height of the background.
@param pMemPool
Pointer to the memory pool where engine data is stored
@param pBgnd
Handle to the IGBackground
@param pErr
Stores error code raised by this function
@return
The height of the background.
*/
iguint32   IGBackground_getHeight          ( IGMemoryPool* pMemPool, 
                                                  IGBackground* pBgnd, 
                                                  IGErr*        pErr );
/**
Get the width of the background.
@param pMemPool
Pointer to the memory pool where engine data is stored
@param pBgnd
Handle to the IGBackground
@param pErr
Stores error code raised by this function
@return
The width of the background.
*/
iguint32   IGBackground_getWidth           ( IGMemoryPool* pMemPool, 
                                                  IGBackground* pBgnd, 
                                                  IGErr*        pErr );
/**
Gets an IGBackground's name.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pBgnd
  Handle to the IGBackground
@param oName
  The IGBackground's name is written to this buffer; must have a capacity of
  at least @a MAXNAMELEN + 1 characters (to accommodate the null terminator)
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  char aNameDest[MAXNAMELEN + 1];

  // pMemPool points to a previously allocated IGMemoryPool.
  // hBack references a previously allocated IGBackground.
  IGBackground_getName(pMemPool, hBack, aNameDest, pErr);

  // aNameDest now contains the IGBackground's name.
@endcode
@see IGBackground_setName
@see MAXNAMELEN
*/
void            IGBackground_getName            ( IGMemoryPool* pMemPool, 
                                                  IGBackground* pBgnd, 
                                                  char*         oName, 
                                                  IGErr*        pErr );
/**
Sets an IGBackground's name.
@param pMemPool
Pointer to the memory pool where engine data is stored
@param pBgnd
Pointer to the IGBackground
@param iName
Name to set; will only be internally unique up to @a MAXNAMELEN characters
@param pErr
Stores error code raised by this function
@return
void
@par Example:
@code
// pMemPool points to a previously allocated IGMemoryPool.
// hBack references a previously allocated IGBackground.
IGBackground_setName(pMemPool, hBack, "myBackground", pErr);
@endcode
@see IGBackground_getName
@see MAXNAMELEN
*/
void            IGBackground_setName            ( IGMemoryPool* pMemPool, 
                                                  IGBackground* pBgnd, 
                                                  const char*   iName, 
                                                  IGErr*        pErr );


#ifdef __cplusplus
}
#endif

#endif//IG_BACKGROUND_H

