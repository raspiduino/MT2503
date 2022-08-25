/** 
 *
 *	@file		IGV5Camera.h 
 *
 *  @brief		Camera related API
 *
 *	@author		Charles Shih-I Yeh
 *
*/

#ifndef __IGV5CAMERA_H
#define __IGV5CAMERA_H

#include "IGV5Matrix.h"


#ifdef __cplusplus
extern "C" {
#endif

/*!***************************************************************************
@enum		IGV5CameraTypeEnum
@brief		Enumeration of camera type
*****************************************************************************/
typedef enum {

	eCameraType_Perspective,
	eCameraType_Orthogonal,
	eCameraType_UserDef

} IGV5CameraTypeEnum;

#define IGV5CAMERA_VIEW_DIRTY

/*!***************************************************************************
@struct		IGV5Camera
@brief		A structure for Camera related information
*****************************************************************************/
typedef struct {

	IGV5CameraTypeEnum m_eCameraType;			/*!< projection type of camera: either eCameraType_Perspective or eCameraType_Orthogonal */
	Vec3 m_vPosEye;								/*!< eye position */
	Vec3 m_vPosLookAt;							/*!< look-at position */
	Vec3 m_vVecUp;								/*!< upward position */

	float m_fFOV;								/*!< filed of view in radian */
	float m_fNear;								/*!< near distance in camera space */
	float m_fFar;								/*!< far distance in camera space */
	float m_fAspect;							/*!< aspect ratio of width / height */

	IGV5Matrix m_mView;							/*!< view matrix */
	IGV5Matrix m_mProjection;					/*!< projection matrix */
	IGV5Matrix m_mModelView;					/*!< modelview matrix */

} IGV5Camera;

/*!***********************************************************************
 @fn		IGV5Camera_Create
 @param		pCam			pointer to camera object
 @param		eType			desired camera projection type					
 @return	IGV5ERR_NONE if succeed
 @brief		Initialize a camera object		
*************************************************************************/
IGV5Err IGV5Camera_Create(IGV5Camera *pCam, IGV5CameraTypeEnum eType);

/*!***********************************************************************
 @fn		IGV5Camera_LookAt
 @param		pCam			pointer to camera object
 @param		pPosEye			pointer to eye position object	
 @param		pPosLookAt		pointer 
 @return	IGV5ERR_NONE if succeed
 @brief		build internal view matrix	
*************************************************************************/
void IGV5Camera_LookAt(IGV5Camera *pCam, Vec3 *pPosEye, Vec3 *pPosLookAt, Vec3 *pVecUp);

/*!***********************************************************************
 @fn		IGV5Camera_Project
 @param		pCam			pointer to camera object
 @param		fFovY			field of view. in radian (0..2 pi)	
 @param		fAspectRatio	ratio of width / height
 @param		fNear			near value in camera space, the nearest position user can see
 @
 @brief		build internal projection matrix		
*************************************************************************/
void IGV5Camera_Project(IGV5Camera *pCam, float fFovY, float fAspectRatio, float fNear, float fFar);

/*!***********************************************************************
 @fn		IGV5Camera_BuildMVPMatrix
 @param		pCam			pointer to camera object
 @param		fFovY			field of view. in radian (0..2 pi)	
 @param		fAspectRatio	ratio of width / height
 @param		fNear			near value in camera space, the nearest distance user can see
 @param		fFar			far value in camera space, the farest distance user can see
 @brief		Build intrnal model-view-projection matrix, it can be later used by shader
*************************************************************************/
IGV5Matrix *IGV5Camera_BuildMVPMatrix(IGV5Camera *pCam, IGV5Matrix *pDstMatrix, IGV5Matrix *pSrcMatrix);

void IGV5Camera_GetFrustumVerticesInObjectSpace(IGV5Camera *pCam, Vec3* aryVertices);

/*!***********************************************************************
 @fn		IGV5Camera_Release
 @param		pCam			pointer to camera object
 @brief		Destruct camera object
*************************************************************************/
void IGV5Camera_Release(IGV5Camera *pCam);

#ifdef __cplusplus
}
#endif


#endif