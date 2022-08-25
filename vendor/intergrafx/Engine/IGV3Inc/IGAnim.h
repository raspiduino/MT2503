/**
@file IGAnim.h 
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
#ifndef IG_ANIM_H
#define IG_ANIM_H

#include "IGMemoryPool.h"
#include "IGScene.h"
#include "IGObjTable.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _IGAnimRec
{
	iguint16        m_pathAnimNum;
	iguint16        m_morphAnimNum;
	//iguint16        m_UVAnimNum;
	IGObjTable      m_animPath;
	IGObjTable      m_animMorph;
	//IGObjTable      m_animUV;
}   IGAnim;


/**
Get anim from a scene.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pScene
  Pointer to the scene.
@param iCopyData
  when iCopyData==true,the function will copy the anim from scene,otherwise it will set the pointer to the scene anim data. 
@param pErr
  Stores error code raised by this function
@return
  The generated IGAnim pointer will return.   
   
 */
IGAnim*         IGAnim_fromScene        ( IGMemoryPool*      pMemPool,
										 IGScene*            pScene,
										 igbool              iCopyData, 
										 IGErr*              pErr);
/**
Load the anim from bytes array.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iByteArray
  Pointer to the bytes array.
@param pErr
  Stores error code raised by this function
@return
  The generated IGAnim pointer will return.   

*/
IGAnim*         IGAnim_fromByteArray    ( IGMemoryPool*        pMemPool, 
										 const unsigned char*  iByteArray, 
										 IGErr*                pErr );
/**
Load the anim from file.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iFilename
  File name.
@param pErr
  Stores error code raised by this function
@return
  The generated IGAnim pointer will return.   

*/
IGAnim*         IGAnim_fromFile         ( IGMemoryPool*        pMemPool, 
										 const char*           iFilename,
										 IGErr*                pErr );
/**
Destroy the generated anim data.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iAnim
  Pointer to the anim to destroy. 
@param pErr
  Stores error code raised by this function
@return
  void
*/
void            IGAnim_destroy          ( IGMemoryPool*       pMemPool, 
										 IGAnim*              iAnim, 
										 IGErr*               pErr );
/**
Get the path anim number.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iAnim
  Pointer to the anim.
@param pErr
  Stores error code raised by this function
@return
  number
*/
iguint16        IGAnim_getPathAnimNum   (IGMemoryPool*          pMemPool,
										 IGAnim*                iAnim,
										 IGErr*                 pErr);    

/**
Get the morph anim number.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iAnim
  Pointer to the anim.
@param pErr
  Stores error code raised by this function
@return
  number
*/
iguint16        IGAnim_getMorphAnimNum   (IGMemoryPool*          pMemPool,
										  IGAnim*                iAnim,
	  									  IGErr*                 pErr);    
/**
Get the anim number.
@param pMemPool
Pointer to the memory pool where engine data is stored
@param iAnim
Pointer to the anim.
@param pErr
Stores error code raised by this function
@return
number
*/
iguint16        IGAnim_getAnimNum		 (IGMemoryPool*          pMemPool,
										  IGAnim*                iAnim,
										  IGErr*                 pErr);    
/**
Store the anim to file.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iAnim
  Pointer to the anim
@param iFileName
  File name.
@param pErr
  Stores error code raised by this function
@return
  void
*/
void            IGAnim_toFile            (IGMemoryPool*         pMemPool, 
									      IGAnim *              iAnim,
									      const char*           iFilename,
									      IGErr*                pErr );

/**
Attach the anim to the scene.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iScene
  Pointer to the scene.
@param iAnim
  Pointer to the anim
@param iCopyData
  when iCopyData==true,the function will copy the anim from iAnim,otherwise it will set the pointer to the iAnim anim data. 
@param oAnimName
  Pointer to the animName[count][128],the count = iAnimCount
@param iAnimCount
  Animation count, you can get it from IGAnim_getAnimNum
@param pErr
  Stores error code raised by this function
@return
  void
*/
void            IGScene_attachAnim       (IGMemoryPool*        pMemPool,
								          IGScene *            iScene,
									      IGAnim*              iAnim,
										  igbool               iCopyData,
										  char*				 oAnimName,
										  iguint16			 iAnimCount,
									      IGErr*               pErr);

/**
Detach the anim from the scene.
@param pMemPool
Pointer to the memory pool where engine data is stored
@param iScene
Pointer to the scene.
@param iAnimName
Pointer to the anim name
@param pErr
Stores error code raised by this function
@return
void
*/
void            IGScene_detachAnim       (IGMemoryPool*        pMemPool,
										  IGScene *            iScene,
										  char *			   pAnimName,	
										  IGErr*               pErr);
#ifdef __cplusplus
}
#endif

#endif
