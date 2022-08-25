/**
@file IGCamera.h 
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

#ifndef IG_CAMERA_H
#define IG_CAMERA_H

#include "IGNode.h"

#ifdef __cplusplus
extern "C"
{
#endif


typedef struct _IGCameraRec
{
    IGNode      m_super;

    IGViewMode  m_viewMode;

    igreal      m_viewAngle;
    igreal      m_XOverY;       // Aspect ratio
    igreal      m_YOverX;
    igreal      m_YOverZ;       // Top plane of view frustum
    igreal      m_ZOverY;
    igreal      m_XOverZ;       // Left plane of view frustum
    igreal      m_ZOverX;
    igreal      m_YOverOne;     // Top/bottom plane of view prism
    igreal      m_OneOverY;
    igreal      m_XOverOne;     // Left/right plane of view prism
    igreal      m_OneOverX;

}  IGCamera;

/*--------------------------------------------------------------------*\
|   IGCamera public interface
\*--------------------------------------------------------------------*/

/**
IGCamera constructor.
Allocates a new IGCamera.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iName
  Initial name of IGCamera; will be internally unique up to only 
  @a MAXNAMELEN characters
@param pErr
  Stores error code raised by this function
@return
  Handle to newly created IGCamera; NULL if creation failed
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  IGCamera* hCam = IGCamera_new(pMemPool, "myCamera", pErr);

  if (hCam) {
    ...
  }
@endcode
@see IGCamera_destroy
@see MAXNAMELEN
*/
IGCamera*   IGCamera_new            ( IGMemoryPool* pMemPool, 
                                      const char*   iName, 
                                      IGErr*        pErr );
/**
* IGCamera destructor.
* Deallocates an IGCamera.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pCam
*   Handle to the IGCamera
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hCam references a previously allocated IGCamera.
*   if (hCam) {
*     IGCamera_destroy(pMemPool, hCam, pErr);
*   }
* @endcode
* @see IGCamera_new
*/
void        IGCamera_destroy        ( IGMemoryPool* pMemPool, 
                                      IGCamera*     pCam, 
                                      IGErr*        pErr );
/**
Gets an IGCamera's aspect ratio
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pCam
  Handle to the IGCamera
@param pErr
  Stores error code raised by this function
@return
  IGCamera's aspect ratio in 16.15 format
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hCam references a previously allocated IGCamera.
  igreal aspect = IGCamera_getAspectRatio(pMemPool, hCam, pErr);
@endcode
@see IGCamera_setAspectRatio
*/
igreal      IGCamera_getAspectRatio ( IGMemoryPool* pMemPool, 
                                      IGCamera*     pCam, 
                                      IGErr*        pErr );
/**
Sets an IGCamera's aspect ratio
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pCam
  Handle to the IGCamera
@param iAspect
  Ratio of the x dimension of the view volume to the y dimension in 16.15
  format; to get a true square image, the view volume should have the same
  dimensions as a pixel on the display
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hCam references a previously allocated IGCamera.
  IGCamera_setAspectRatio(pMemPool, hCam, IG_ONE, pErr);
@endcode
@see IGCamera_getAspectRatio
*/
void        IGCamera_setAspectRatio ( IGMemoryPool* pMemPool, 
                                      IGCamera*     pCam, 
                                      igreal        iAspect, 
                                      IGErr*        pErr );
/**
Gets an IGCamera's field of view for parallel mode.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pCam
  Handle to the IGCamera
@param pErr
  Stores error code raised by this function
@return
  IGCamera's field of view as distance from IGCamera to edge of view volume
  in [@a IG_ZERO, @a IG_TWO]
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hCam references a previously allocated IGCamera.
  igreal fov = IGCamera_getParallelFieldOfView(pMemPool, hCam, pErr);
@endcode
@see IGCamera_setParallelFieldOfView
*/
igreal      IGCamera_getParallelFieldOfView
                                    ( IGMemoryPool* pMemPool, 
                                      IGCamera*     pCam, 
                                      IGErr*        pErr );
/**
Sets an IGCamera's field of view for parallel mode.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pCam
  Handle to the IGCamera
@param iFOV
  Field of view as distance from IGCamera to edge of view volume
  (acceptable values are IG_ZERO to IG_TWO)
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hCam references a previously allocated IGCamera.
  IGCamera_setParallelFieldOfView(pMemPool, hCam, IG_ONE, pErr);
@endcode
@see IGCamera_getParallelFieldOfView
*/
void        IGCamera_setParallelFieldOfView
                                    ( IGMemoryPool* pMemPool, 
                                      IGCamera*     pCam, 
                                      igreal        iFOV, 
                                      IGErr*        pErr );
/**
Gets an IGCamera's field of view for perspective mode.
@param pMemPool
Pointer to the memory pool where engine data is stored
@param pCam
Handle to the IGCamera
@param pErr
Stores error code raised by this function
@return
Field of view as an angle in radians
in [@a IG_ZERO, @a IG_TWO]
@par Example:
@code
// pMemPool points to a previously allocated IGMemoryPool.
// hCam references a previously allocated IGCamera.
igreal fov = IGCamera_getParallelFieldOfView(pMemPool, hCam, pErr);
@endcode
@see IGCamera_setParallelFieldOfView
*/
igreal      IGCamera_getPerspectiveFieldOfView
                                    ( IGMemoryPool* pMemPool, 
                                      IGCamera*     pCam, 
                                      IGErr*        pErr );
/**
Sets an IGCamera's field of view for perspective mode.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pCam
  Handle to the IGCamera
@param iFOV
  Field of view as an angle in radians (from IG_ZERO to IG_PI)
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hCam references a previously allocated IGCamera.
  IGCamera_setPerspectiveFieldOfView(pMemPool, hCam, IG_HALF_PI, pErr);
@endcode
@see IGCamera_getPerspectiveFieldOfView
*/
void        IGCamera_setPerspectiveFieldOfView
                                    ( IGMemoryPool* pMemPool, 
                                      IGCamera*     pCam, 
                                      igreal        iFOV, 
                                      IGErr*        pErr );
/**
Gets the projection type used by an IGCamera to render 3D into 2D.
@param pMemPool
  Handle to the memory pool where engine data is stored
@param pCam
  Pointer to the IGCamera
@param pErr
  Stores error code raised by this function
@return
  Either parallel or perspective projection mode
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hCam references a previously allocated IGCamera.
  IGViewMode mode = IGCamera_getViewMode(pMemPool, hCam, pErr);
@endcode
@see IGViewMode
*/
IGViewMode  IGCamera_getViewMode    ( IGMemoryPool* pMemPool, 
                                      IGCamera*     pCam, 
                                      IGErr*        pErr );
/**
Sets the projection type used by an IGCamera to render 3D into 2D.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pCam
  Handle to the IGCamera
@param iMode
  Specifies whether to use parallel or perspective projection
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  // Set an IGCamera to use perspective projection.

  // pMemPool points to a previously allocated IGMemoryPool.
  // hCam references a previously allocated IGCamera.
  IGCamera_setViewMode(pMemPool, hCam, IGVIEW_PERSPECTIVE, pErr);
@endcode
@see IGViewMode
*/
void        IGCamera_setViewMode    ( IGMemoryPool* pMemPool, 
                                      IGCamera*     pCam,
                                      IGViewMode    iMode, 
                                      IGErr*        pErr );

void		IGCamera_project		( IGMemoryPool*		pMemPool,
									  IGCamera*			pCam,
									  igreal			iPos[3],
									  igreal			oPos[2],
									  igint32			iScreenW,
									  igint32			iScreenH,
									  IGErr*			pErr );

void IGCamera_lookAt(IGMemoryPool*	pMemPool,
					IGCamera *pCamera,
					igreal iTargetPos[3],
					IGErr* pErr);


#ifdef __cplusplus
}
#endif

#endif//IG_CAMERA_H

