/** 
 *
 *	@file		IGV5LoadPODModel.h	
 *
 *  @brief		Header file for POD loader
 *
 *	@author		PowerVR insider example code
 *
*/

#ifndef __IGV5LOADPODWORLD_H
#define __IGV5LOADPODWORLD_H

#include "IGV5Vertex.h"
#include "IGV5Matrix.h"
#include "IGV5BoundingBox.h"
#include "IGV5BoneBatch.h"
#include "IGV5Texture.h"
#include "IGV5Light.h"
#include "IGV5ShaderProgram.h"

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
** Defines
****************************************************************************/

/*! @def POD file version string */
#define PVRTMODELPOD_VERSION	("AB.POD.2.0") 

/*! @def Fixed-point 16.16 data (otherwise float) flag */
#define PVRTMODELPODSF_FIXED	(0x00000001)   

/****************************************************************************
** Enumerations
****************************************************************************/

/*!****************************************************************************
 @Struct      EPODPrimitiveType
 @brief       Enum for the POD format primitive types
******************************************************************************/
typedef enum 
{
	ePODTriangles=0, /*!< Triangles */
	ePODLines		 /*!< Lines*/
} EPODPrimitiveType;

/*!****************************************************************************
 @Struct      EPODAnimationData
 @brief       Enum for the POD format animation types
******************************************************************************/
typedef enum 
{
	ePODHasPositionAni	= 0x01,	/*!< Position animation */
	ePODHasRotationAni	= 0x02, /*!< Rotation animation */
	ePODHasScaleAni		= 0x04, /*!< Scale animation */
	ePODHasMatrixAni	= 0x08  /*!< Matrix animation */
}EPODAnimationData;

/*!****************************************************************************
 @Struct      EPODMaterialFlags
 @brief       Enum for the material flag options
******************************************************************************/
typedef enum 
{
	ePODEnableBlending	= 0x01,	/*!< Enable blending for this material */
}EPODMaterialFlags;

/*!****************************************************************************
 @Struct      EPODBlendFunc
 @brief       Enum for the POD format blend functions
******************************************************************************/
typedef enum 
{
	ePODBlendFunc_ZERO=0,
	ePODBlendFunc_ONE,
	ePODBlendFunc_BLEND_FACTOR,
	ePODBlendFunc_ONE_MINUS_BLEND_FACTOR,

	ePODBlendFunc_SRC_COLOR = 0x0300,
	ePODBlendFunc_ONE_MINUS_SRC_COLOR,
	ePODBlendFunc_SRC_ALPHA,
	ePODBlendFunc_ONE_MINUS_SRC_ALPHA,
	ePODBlendFunc_DST_ALPHA,
	ePODBlendFunc_ONE_MINUS_DST_ALPHA,
	ePODBlendFunc_DST_COLOR,
	ePODBlendFunc_ONE_MINUS_DST_COLOR,
	ePODBlendFunc_SRC_ALPHA_SATURATE,

	ePODBlendFunc_CONSTANT_COLOR = 0x8001,
	ePODBlendFunc_ONE_MINUS_CONSTANT_COLOR,
	ePODBlendFunc_CONSTANT_ALPHA,
	ePODBlendFunc_ONE_MINUS_CONSTANT_ALPHA
} EPODBlendFunc;

/*!****************************************************************************
 @Struct      EPODBlendOp
 @brief       Enum for the POD format blend operation
******************************************************************************/
typedef enum 
{
	ePODBlendOp_ADD = 0x8006,
	ePODBlendOp_MIN,
	ePODBlendOp_MAX,
	ePODBlendOp_SUBTRACT = 0x800A,
	ePODBlendOp_REVERSE_SUBTRACT,
} EPODBlendOp;

/*!****************************************************************************
 @struct      CPODData
 @brief      A structure for representing POD data
******************************************************************************/
typedef struct {

	EPVRTDataType	eType;		/*!< Type of data stored */
	unsigned int	n;			/*!< Number of values per vertex */
	unsigned int	nStride;	/*!< Distance in bytes from one array entry to the next */
	unsigned char	*pData;		/*!< Actual data (array of values); if mesh is interleaved, this is an OFFSET from pInterleaved */

} CPODData ;

	/*!***************************************************************************
	@fn			Reset
	@brief		Resets the POD Data to NULL
	*****************************************************************************/
	void CPODData_Reset(CPODData *pThis);

/*!****************************************************************************
 @Struct      SPODCamera
 @brief       Struct for storing POD camera data
******************************************************************************/
typedef struct {

	int				nIdxTarget;			/*!< Index of the target object */
	IGV5VertexType	fFOV;				/*!< Field of view */
	IGV5VertexType	fFar;				/*!< Far clip plane */
	IGV5VertexType	fNear;				/*!< Near clip plane */
	IGV5VertexType	*pfAnimFOV;			/*!< 1 IGV5VertexType per frame of animation. */ 

}  SPODCamera;

/*!****************************************************************************
 @Struct      SPODLight
 @brief       Struct for storing POD light data
******************************************************************************/
typedef struct {
	int				nIdxTarget;		/*!< Index of the target object */
	IGV5VertexType	pfColour[3];	/*!< Light colour (0.0f -> 1.0f for each channel) */
	EPODLight		eType;			/*!< Light type (point, directional, spot etc.) */
	float			fConstantAttenuation;	/*!< Constant attenuation */
	float			fLinearAttenuation;		/*!< Linear atternuation */
	float			fQuadraticAttenuation;	/*!< Quadratic attenuation */
	float			fFalloffAngle;			/*!< Falloff angle (in radians) */
	float			fFalloffExponent;		/*!< Falloff exponent */
}SPODLight ;

/*!****************************************************************************
 @Struct      SPODMesh
 @brief       Struct for storing POD mesh data
******************************************************************************/
typedef struct {
	unsigned int		nNumVertex;		/*!< Number of vertices in the mesh */
	unsigned int		nNumFaces;		/*!< Number of triangles in the mesh */
	unsigned int		nNumUVW;		/*!< Number of texture coordinate channels per vertex */
	CPODData			sFaces;			/*!< List of triangle indices */
	unsigned int		*pnStripLength;	/*!< If mesh is stripped: number of tris per strip. */
	unsigned int		nNumStrips;		/*!< If mesh is stripped: number of strips, length of pnStripLength array. */
	CPODData			sVertex;		/*!< List of vertices (x0, y0, z0, x1, y1, z1, x2, etc...) */
	CPODData			sNormals;		/*!< List of vertex normals (Nx0, Ny0, Nz0, Nx1, Ny1, Nz1, Nx2, etc...) */
	CPODData			sTangents;		/*!< List of vertex tangents (Tx0, Ty0, Tz0, Tx1, Ty1, Tz1, Tx2, etc...) */
	CPODData			sBinormals;		/*!< List of vertex binormals (Bx0, By0, Bz0, Bx1, By1, Bz1, Bx2, etc...) */
	CPODData			*psUVW;			/*!< List of UVW coordinate sets; size of array given by 'nNumUVW' */
	CPODData			sVtxColours;	/*!< A colour per vertex */
	CPODData			sBoneIdx;		/*!< nNumBones*nNumVertex ints (Vtx0Idx0, Vtx0Idx1, ... Vtx1Idx0, Vtx1Idx1, ...) */
	CPODData			sBoneWeight;	/*!< nNumBones*nNumVertex floats (Vtx0Wt0, Vtx0Wt1, ... Vtx1Wt0, Vtx1Wt1, ...) */

	unsigned char		*pInterleaved;	/*!< Interleaved vertex data */
	unsigned int		m_uInterleavedLen;   /*!< length of interleaved vertex data in bytes */

	int                 m_bSkinnedMesh;  /*!< IGV5_TRUE if this is skinned mesh */

	int                 m_uPassID;  /*!< 0-maximum pass ID */

	IGV5BoneBatches	sBoneBatches;	/*!< Bone tables */

	EPODPrimitiveType	ePrimitiveType;	/*!< Primitive type used by this mesh */

	IGV5Matrix			mUnpackMatrix;	/*!< A matrix used for unscaling scaled vertex data created with PVRTModelPODScaleAndConvertVtxData*/

	IGV5BoundingBox  m_BoundBox;   /*!< An axis-aligned bounding box for this mesh in model space */

}  SPODMesh ;

#define IGV5NODE_ANIMATION 0x000000001
#define IGV5NODE_VISIBILE  0x000000002

#define IGV5NODE_LOCAL_POS 0x000000004
#define IGV5NODE_LOCAL_ROT 0x000000008
#define IGV5NODE_LOCAL_SCALE 0x00000010
/*! define this flag to enable local transform alternation */
#define IGV5NODE_ENABLE_LOCAL 0x00000020
/*! define this flag if node is read from memory (ROM) instead of read from file */
#define IGV5NODE_DATA_FROM_MEMORY 0x00000040
#define IGV5NODE_DATA_FROM_MEMORY_SCALE 0x00000080
#define IGV5NODE_DATA_FROM_MEMORY_ROT 0x00000100
#define IGV5NODE_DATA_FROM_MEMORY_POS 0x00000200


/*!****************************************************************************
 @Struct      SPODNode
 @brief       Struct for storing POD node data
******************************************************************************/
typedef struct {
	int			 nIdx;				/*!< Index into mesh, light or camera array, depending on which object list contains this Node */
	char		 *pszName;			/*!< Name of object */
	int			 nIdxMaterial;		/*!< Index of material used on this mesh */

	int			 nIdxParent;		/*!< Index into MeshInstance array; recursively apply ancestor's transforms after this instance's. */

	unsigned int nAnimFlags;		/*!< Stores which animation arrays the POD Node contains */

	unsigned int* pnAnimPositionIdx;
	IGV5VertexType	*pfAnimPosition;	/*!< 3 floats per frame of animation. */

	unsigned int* pnAnimRotationIdx;
	IGV5VertexType	*pfAnimRotation;	/*!< 4 floats per frame of animation. */

	unsigned int* pnAnimScaleIdx;
	IGV5VertexType	*pfAnimScale;		/*!< 7 floats per frame of animation. */

	unsigned int* pnAnimMatrixIdx;
	IGV5VertexType	*pfAnimMatrix;		/*!< 16 floats per frame of animation. */

	//////////////////////////

	float m_fSpeedFactor;				/*!< local animation speed factor. 1.0 = original speed */
	float m_fNodeAnimBlend;				/*!< local animation frame blending factor in floating point type */
	unsigned m_uNodeAnimFrame;			/*!< local animation frame */
	int m_iAnimStatus;					/*!< 0-stop, 1-playing */

	Vec3 m_vScale;						/*!< relative scale value, 1.0 = no scale, 0.0 = disappear */
	Vec3 m_vXYZAngle;					/*!< relative rotation angle of X, Y, Z */
	Vec3 m_vPosition;					/*!< relative related position */
	unsigned m_uFlags;					/*!< node update flags used internally */

	IGV5Matrix m_ScaleCache, m_RotateCache, m_PosCache;
	IGV5Matrix m_Local;					/*!< local transform matrix */

	ShaderProgram* shaderProgram;

}  SPODNode;

/*!****************************************************************************
 @Struct      SPODTexture
 @brief       Struct for storing POD texture data
******************************************************************************/
typedef struct  {
	char	*pszName;			/*!< File-name of texture */
} SPODTexture;

/*!****************************************************************************
 @Struct      SPODMaterial
 @brief       Struct for storing POD material data
******************************************************************************/
typedef struct {
	char		*pszName;				/*!< Name of material */
	int			nIdxTexDiffuse;			/*!< Idx into pTexture for the diffuse texture */
	int			nIdxTexAmbient;			/*!< Idx into pTexture for the ambient texture */
	int			nIdxTexSpecularColour;	/*!< Idx into pTexture for the specular colour texture */
	int			nIdxTexSpecularLevel;	/*!< Idx into pTexture for the specular level texture */
	int			nIdxTexBump;			/*!< Idx into pTexture for the bump map */
	int			nIdxTexEmissive;		/*!< Idx into pTexture for the emissive texture */
	int			nIdxTexGlossiness;		/*!< Idx into pTexture for the glossiness texture */
	int			nIdxTexOpacity;			/*!< Idx into pTexture for the opacity texture */
	int			nIdxTexReflection;		/*!< Idx into pTexture for the reflection texture */
	int			nIdxTexRefraction;		/*!< Idx into pTexture for the refraction texture */
	IGV5VertexType	fMatOpacity;			/*!< Material opacity (used with vertex alpha ?) */
	IGV5VertexType	pfMatAmbient[3];		/*!< Ambient RGB value */
	IGV5VertexType	pfMatDiffuse[3];		/*!< Diffuse RGB value */
	IGV5VertexType	pfMatSpecular[3];		/*!< Specular RGB value */
	IGV5VertexType	fMatShininess;			/*!< Material shininess */
	char		*pszEffectFile;			/*!< Name of effect file */
	char		*pszEffectName;			/*!< Name of effect in the effect file */

	EPODBlendFunc	eBlendSrcRGB;		/*!< Blending RGB source value */
	EPODBlendFunc	eBlendSrcA;			/*!< Blending alpha source value */
	EPODBlendFunc	eBlendDstRGB;		/*!< Blending RGB destination value */
	EPODBlendFunc	eBlendDstA;			/*!< Blending alpha destination value */
	EPODBlendOp		eBlendOpRGB;		/*!< Blending RGB operation */
	EPODBlendOp		eBlendOpA;			/*!< Blending alpha operation */
	IGV5VertexType		pfBlendColour[4];	/*!< A RGBA colour to be used in blending */
	IGV5VertexType		pfBlendFactor[4];	/*!< An array of blend factors, one for each RGBA component */

	unsigned int	nFlags;				/*!< Stores information about the material e.g. Enable blending */

} SPODMaterial ;


/*!****************************************************************************
 @Struct      SPODScene
 @brief       Struct for storing POD scene data
******************************************************************************/
typedef struct {

	IGV5VertexType	pfColourBackground[3];		/*!< Background colour */
	IGV5VertexType	pfColourAmbient[3];			/*!< Ambient colour */

	unsigned int	nNumCamera;				/*!< The length of the array pCamera */
	SPODCamera		*pCamera;				/*!< Camera nodes array */

	unsigned int	nNumLight;				/*!< The length of the array pLight */
	SPODLight		*pLight;				/*!< Light nodes array */

	unsigned int	nNumMesh;				/*!< The length of the array pMesh */
	SPODMesh		*pMesh;					/*!< Mesh array. Meshes may be instanced several times in a scene; i.e. multiple Nodes may reference any given mesh. */

	unsigned int	nNumNode;		/*!< Number of items in the array pNode */
	unsigned int	nNumMeshNode;	/*!< Number of items in the array pNode which are objects */
	SPODNode		*pNode;			/*!< Node array. Sorted as such: objects, lights, cameras, Everything Else (bones, helpers etc) */

	unsigned int	nNumTexture;	/*!< Number of textures in the array pTexture */
	SPODTexture		*pTexture;		/*!< Texture array */

	unsigned int	nNumMaterial;	/*!< Number of materials in the array pMaterial */
	SPODMaterial	*pMaterial;		/*!< Material array */

	unsigned int	nNumFrame;		/*!< Number of frames of animation */
	unsigned int	nFPS;			/*!< The frames per second the animation should be played at */

	unsigned int	nFlags;			/*!< PVRTMODELPODSF_* bit-flags */

} IGV5PODFile;



typedef struct
{
	IGV5VertexType	fFrame;		/*!< Frame number */
	IGV5VertexType	fBlend;		/*!< Frame blend	(AKA fractional part of animation frame number) */
	int			nFrame;		/*!< Frame number (AKA integer part of animation frame number) */

	IGV5VertexType	*pfCache;		/*!< Cache indicating the frames at which the matrix cache was filled */
	IGV5Matrix	*pWmCache;		/*!< Cache of world matrices */
	IGV5Matrix *pWmZeroCache;	/*!< Pre-calculated frame 0 matrices */

	int		bFromMemory;	/*!< Was the mesh data loaded from memory? */

#ifdef _DEBUG
	INT64 nWmTotal, nWmCacheHit, nWmZeroCacheHit;
	float	fHitPerc, fHitPercZero;
#endif
}  SPVRTPODImpl;

typedef struct {

	IGV5PODFile m_POD;

	SPVRTPODImpl *m_pImpl;

	unsigned char cacheClear;

	unsigned m_uMaxLayer;		/*!< maximum layers ID */

} IGV5PODModel;


/*!***************************************************************************
 @fn			IGV5PODModel_GetCameraPos
 @brief			vFrom			Position of the camera
 @brief			vTo				Target of the camera
 @param				nIdx			Camera number
 @Return			Camera horizontal FOV
 @brief		Calculate the position of the camera and its target. Uses
					animation data.
					If the queried camera does not have a target, *pvTo is
					not changed.
*****************************************************************************/
IGV5VertexType IGV5PODModel_GetCameraPos(IGV5PODModel *pThis, Vec3 *vFrom, Vec3 *vTo, unsigned nIdx);

/*!***************************************************************************
 @fn			GetCameraPosEx
 @brief			vFrom			Position of the camera
 @brief			vTo				Target of the camera
 @brief			vUp				Up direction of the camera
 @param				nIdx			Camera number
 @Return			Camera horizontal FOV
 @brief		Calculate the From, To and Up vectors for the given
					camera. Uses animation data.
					Note that even if the camera has a target, *pvTo is not
					the position of that target. *pvTo is a position in the
					correct direction of the target, one unit away from the
					camera.
*****************************************************************************/
IGV5VertexType IGV5PODModel_GetCameraPosEx(IGV5PODModel *pThis, Vec3 *vFrom, Vec3 *vTo, Vec3 *vUp, unsigned nIdx);

/*!***************************************************************************
 @fn			IGV5PODModel_GetLightDirection
 @param			pThis			pointer to IGV5PODModel
 @param			u32Idx			Light number
 @Return		Vec4			direction of light with w set correctly
 @brief			Calculate the direction of the given Light. Uses animation data.
*****************************************************************************/
IGV5Err IGV5PODModel_GetLightDirection(IGV5PODModel *pThis, unsigned u32Idx, Vec4 *pReturn);

/*!***************************************************************************
 @fn			IGV5PODModel_GetLight
 @param			pThis			pointer to IGV5PODModel
 @param			vPos			Position of the light
 @param			vDir			Direction of the light
 @param			nIdx			Light number
 @brief			Calculate the position and direction of the given Light. Uses animation data.
*****************************************************************************/
void IGV5PODModel_GetLight(IGV5PODModel *pThis, Vec3 *vPos, Vec3 *vDir, unsigned nIdx);

void IGV5PODModel_SetFrame(IGV5PODModel *pThis, IGV5VertexType fFrame);

/*!***************************************************************************
 @fn		IGV5PODModel_SetPassID
 @param			pThis		Model pointer
				mesh		Mesh
 @Return		Number of indices used by mesh
 @brief	Assign rednering pass ID of this mesh. Rendering pass control
				order of mesh to be rendered
*****************************************************************************/
void IGV5PODModel_SetPassID(IGV5PODModel *pThis,SPODMesh *mesh, unsigned uID);


void IGV5PODModel_GetWorldMatrix(IGV5PODModel *pThis, IGV5Matrix *mOut, SPODNode *node);
void IGV5PODModel_GetWorldMatrixNoCache(IGV5PODModel *pThis, IGV5Matrix *mOut, SPODNode	*node);
IGV5Err IGV5PODModel_ReadFromFile(IGV5PODModel *pThis, char* pszFileName, char	* pszExpOpt, size_t	count, char	* pszHistory, size_t historyCount);
IGV5Err IGV5PODModel_ReadFromMemory(IGV5PODModel *pThis, void *pData, unsigned usize, char	* pszExpOpt, size_t	count, char	* pszHistory, size_t historyCount);
void IGV5PODModel_Release(IGV5PODModel* pS);

/*!***************************************************************************
 @fn			IGV5PODModel_GetBoneWorldMatrix
 @brief			mOut			Bone world matrix
 @param				NodeMesh		Mesh to take the bone matrix from
 @param				NodeBone		Bone to take the matrix from
 @brief		Generates the world matrix for the given bone.
*****************************************************************************/
void IGV5PODModel_GetBoneWorldMatrix(IGV5PODModel *pThis, IGV5Matrix *mOut, SPODNode *NodeMesh, SPODNode *NodeBone);

/*!***************************************************************************
 @fn		IGV5PODModel_CountIndices
 @param			mesh		Mesh
 @Return		Number of indices used by mesh
 @brief	Counts the number of indices of a mesh
*****************************************************************************/
unsigned int IGV5PODModel_CountIndices(SPODMesh *mesh);

/*/////////////////////////////////////////////////////////// */

	typedef enum 
	{
		MGLPT_ARGB_4444 = 0x00,
		MGLPT_ARGB_1555,
		MGLPT_RGB_565,
		MGLPT_RGB_555,
		MGLPT_RGB_888,
		MGLPT_ARGB_8888,
		MGLPT_ARGB_8332,
		MGLPT_I_8,
		MGLPT_AI_88,
		MGLPT_1_BPP,
		MGLPT_VY1UY0,
		MGLPT_Y1VY0U,
		MGLPT_PVRTC2,
		MGLPT_PVRTC4,

		/* OpenGL version of pixel types */
		OGL_RGBA_4444= 0x10,
		OGL_RGBA_5551,
		OGL_RGBA_8888,
		OGL_RGB_565,
		OGL_RGB_555,
		OGL_RGB_888,
		OGL_I_8,
		OGL_AI_88,
		OGL_PVRTC2,
		OGL_PVRTC4,
		OGL_BGRA_8888,
		OGL_A_8,
		OGL_PVRTCII4,	//Not in use
		OGL_PVRTCII2,	//Not in use

#ifdef IGV5_WIN
		// S3TC Encoding
		D3D_DXT1 = 0x20,
		D3D_DXT2,
		D3D_DXT3,
		D3D_DXT4,
		D3D_DXT5,
#endif

		/* RGB Formats */
		D3D_RGB_332 
#ifndef IGV5_WIN
		= 0x25
#endif
		,
		D3D_AL_44,
		D3D_LVU_655,
		D3D_XLVU_8888,
		D3D_QWVU_8888,
		
		//10 bit integer - 2 bit alpha
		D3D_ABGR_2101010,
		D3D_ARGB_2101010,
		D3D_AWVU_2101010,

		//16 bit integers
		D3D_GR_1616,
		D3D_VU_1616,
		D3D_ABGR_16161616,

		//Float Formats
		D3D_R16F,
		D3D_GR_1616F,
		D3D_ABGR_16161616F,

		//32 bits per channel
		D3D_R32F,
		D3D_GR_3232F,
		D3D_ABGR_32323232F,
		
		// Ericsson
		ETC_RGB_4BPP,
		ETC_RGBA_EXPLICIT,				// unimplemented
		ETC_RGBA_INTERPOLATED,			// unimplemented
		
		D3D_A8 = 0x40,
		D3D_V8U8,
		D3D_L16,
				
		D3D_L8,
		D3D_AL_88,

		//Y'UV Colourspace
		D3D_UYVY,
		D3D_YUY2,
		
		// DX10
		DX10_R32G32B32A32_FLOAT= 0x50,
		DX10_R32G32B32A32_UINT , 
		DX10_R32G32B32A32_SINT,

		DX10_R32G32B32_FLOAT,
		DX10_R32G32B32_UINT,
		DX10_R32G32B32_SINT,

		DX10_R16G16B16A16_FLOAT ,
		DX10_R16G16B16A16_UNORM,
		DX10_R16G16B16A16_UINT ,
		DX10_R16G16B16A16_SNORM ,
		DX10_R16G16B16A16_SINT ,

		DX10_R32G32_FLOAT ,
		DX10_R32G32_UINT ,
		DX10_R32G32_SINT ,

		DX10_R10G10B10A2_UNORM ,
		DX10_R10G10B10A2_UINT ,

		DX10_R11G11B10_FLOAT ,				// unimplemented

		DX10_R8G8B8A8_UNORM , 
		DX10_R8G8B8A8_UNORM_SRGB ,
		DX10_R8G8B8A8_UINT ,
		DX10_R8G8B8A8_SNORM ,
		DX10_R8G8B8A8_SINT ,

		DX10_R16G16_FLOAT , 
		DX10_R16G16_UNORM , 
		DX10_R16G16_UINT , 
		DX10_R16G16_SNORM ,
		DX10_R16G16_SINT ,

		DX10_R32_FLOAT ,
		DX10_R32_UINT ,
		DX10_R32_SINT ,

		DX10_R8G8_UNORM ,
		DX10_R8G8_UINT ,
		DX10_R8G8_SNORM , 
		DX10_R8G8_SINT ,

		DX10_R16_FLOAT ,
		DX10_R16_UNORM ,
		DX10_R16_UINT ,
		DX10_R16_SNORM ,
		DX10_R16_SINT ,

		DX10_R8_UNORM, 
		DX10_R8_UINT,
		DX10_R8_SNORM,
		DX10_R8_SINT,

		DX10_A8_UNORM, 
		DX10_R1_UNORM, 
		DX10_R9G9B9E5_SHAREDEXP,	// unimplemented
		DX10_R8G8_B8G8_UNORM,		// unimplemented
		DX10_G8R8_G8B8_UNORM,		// unimplemented

#ifdef IGV5_WIN
		DX10_BC1_UNORM,	
		DX10_BC1_UNORM_SRGB,

		DX10_BC2_UNORM,	
		DX10_BC2_UNORM_SRGB,

		DX10_BC3_UNORM,	
		DX10_BC3_UNORM_SRGB,

		DX10_BC4_UNORM,				// unimplemented
		DX10_BC4_SNORM,				// unimplemented

		DX10_BC5_UNORM,				// unimplemented
		DX10_BC5_SNORM,				// unimplemented
#endif
		// OpenVG

		/* RGB{A,X} channel ordering */
		ePT_VG_sRGBX_8888  = 0x90,
		ePT_VG_sRGBA_8888,
		ePT_VG_sRGBA_8888_PRE,
		ePT_VG_sRGB_565,
		ePT_VG_sRGBA_5551,
		ePT_VG_sRGBA_4444,
		ePT_VG_sL_8,
		ePT_VG_lRGBX_8888,
		ePT_VG_lRGBA_8888,
		ePT_VG_lRGBA_8888_PRE,
		ePT_VG_lL_8,
		ePT_VG_A_8,
		ePT_VG_BW_1,

		/* {A,X}RGB channel ordering */
		ePT_VG_sXRGB_8888,
		ePT_VG_sARGB_8888,
		ePT_VG_sARGB_8888_PRE,
		ePT_VG_sARGB_1555,
		ePT_VG_sARGB_4444,
		ePT_VG_lXRGB_8888,
		ePT_VG_lARGB_8888,
		ePT_VG_lARGB_8888_PRE,

		/* BGR{A,X} channel ordering */
		ePT_VG_sBGRX_8888,
		ePT_VG_sBGRA_8888,
		ePT_VG_sBGRA_8888_PRE,
		ePT_VG_sBGR_565,
		ePT_VG_sBGRA_5551,
		ePT_VG_sBGRA_4444,
		ePT_VG_lBGRX_8888,
		ePT_VG_lBGRA_8888,
		ePT_VG_lBGRA_8888_PRE,

		/* {A,X}BGR channel ordering */
		ePT_VG_sXBGR_8888,
		ePT_VG_sABGR_8888 ,
		ePT_VG_sABGR_8888_PRE,
		ePT_VG_sABGR_1555,
		ePT_VG_sABGR_4444,
		ePT_VG_lXBGR_8888,
		ePT_VG_lABGR_8888,
		ePT_VG_lABGR_8888_PRE,

		// max cap for iterating
		END_OF_PIXEL_TYPES,

		MGLPT_NOTYPE = -1

	} PixelType;


/*****************************************************************************
* constants
*****************************************************************************/

// has mip map levels
#define  PVRTEX_MIPMAP		 (1<<8)	
// is twiddled
#define  PVRTEX_TWIDDLE		 (1<<9)	
// has normals encoded for a bump map
#define  PVRTEX_BUMPMAP		 (1<<10)	
// is bordered for tiled pvr
#define  PVRTEX_TILING		 (1<<11)
// is a cubemap/skybox
#define  PVRTEX_CUBEMAP		 (1<<12)	
// are there false coloured MIP levels
#define  PVRTEX_FALSEMIPCOL	 (1<<13)
// is this a volume texture
#define  PVRTEX_VOLUME		 (1<<14)
// v2.1 is there transparency info in the texture
#define  PVRTEX_ALPHA			 (1<<15)	
// v2.1 is the texture vertically flipped
#define  PVRTEX_VERTICAL_FLIP	 (1<<16)		

// pixel type is always in the last 16bits of the flags
#define  PVRTEX_PIXELTYPE		 0xff	

// the pvr identifier is the characters 'P','V','R'
#define  PVRTEX_IDENTIFIER	 0x21525650	

// old header size was 44 for identification purposes
#define  PVRTEX_V1_HEADER_SIZE  44		

#define  PVRTC2_MIN_TEXWIDTH		 16
#define  PVRTC2_MIN_TEXHEIGHT		 8
#define  PVRTC4_MIN_TEXWIDTH		 8
#define  PVRTC4_MIN_TEXHEIGHT		 8
#define  ETC_MIN_TEXWIDTH			 4
#define  ETC_MIN_TEXHEIGHT		 4
#define  DXT_MIN_TEXWIDTH			 4
#define  DXT_MIN_TEXHEIGHT		 4


/*!***************************************************************************
@Struct PVR_Texture_Header
@brief  Describes the header of a PVR header-texture
*****************************************************************************/
typedef struct 
{
	DWORD dwHeaderSize;			/*!< size of the structure */
	DWORD dwHeight;				/*!< height of surface to be created */
	DWORD dwWidth;				/*!< width of input surface */
	DWORD dwMipMapCount;			/*!< number of mip-map levels requested */
	DWORD dwpfFlags;				/*!< pixel format flags */
	DWORD dwTextureDataSize;		/*!< Total size in bytes */
	DWORD dwBitCount;			/*!< number of bits per pixel  */
	DWORD dwRBitMask;			/*!< mask for red bit */
	DWORD dwGBitMask;			/*!< mask for green bits */
	DWORD dwBBitMask;			/*!< mask for blue bits */
	DWORD dwAlphaBitMask;		/*!< mask for alpha channel */
	DWORD dwPVR;					/*!< magic number identifying pvr file */
	DWORD dwNumSurfs;			/*!< the number of surfaces present in the pvr */
} PVR_Texture_Header;

/*!***************************************************************************
 @fn		IGV5Texture_LoadPVRFromMem
 @param		IGV5Texture *pTex		Pointer to IGV5Texture
 @param		pointer					Pointer to header-texture's structure
 @param		psTextureHeader			Pointer to a PVR_Texture_Header struct. Modified to
										contain the header data of the returned texture Ignored if NULL.
 @param			bAllowDecompress		Allow decompression if PVRTC is not supported in hardware.
 @param			nLoadFromLevel			Which mipmap level to start loading from (0=all)
 @param			texPtr					If null, texture follows header, else texture is here.
 @Return		IGV5ERR_NONE on success
 @brief	Allows textures to be stored in memory and loaded in. Can load parts of a
				mipmaped texture (ie skipping the highest detailed levels).In OpenGL Cube Map, each
				texture's up direction is defined as next (view direction, up direction),
				(+x,-y)(-x,-y)(+y,+z)(-y,-z)(+z,-y)(-z,-y).
				Sets the texture MIN/MAG filter to GL_LINEAR_MIPMAP_NEAREST/GL_LINEAR
				if mipmaps are present, GL_LINEAR/GL_LINEAR otherwise.
*****************************************************************************/
IGV5Err IGV5Texture_LoadPVRFromMem(IGV5Texture *pTex, void* pointer, void *psTextureHeader, int bAllowDecompress, unsigned int nLoadFromLevel, void *texPtr);

IGV5Err IGV5Texture_LoadKTXFromMem(IGV5Texture *pTex, void* pointer, void *psTextureHeader, int bAllowDecompress, unsigned int nLoadFromLevel, void *texPtr);

IGV5Err IGV5Texture_LoadKTXFromFile(IGV5Texture *pTex, char * filename, void *psTextureHeader, int bAllowDecompress, unsigned int nLoadFromLevel);


/*!***************************************************************************
 @fn		IGV5Texture_LoadPVRFromFile
 @param		filename			Filename of the .PVR file to load the texture from
 @param		texName				the OpenGL ES texture name as returned by glBindTexture
 @param		psTextureHeader		Pointer to a PVR_Texture_Header struct. Modified to
									contain the header data of the returned texture Ignored if NULL.
 @param			bAllowDecompress	Allow decompression if PVRTC is not supported in hardware.
 @param			nLoadFromLevel		Which mipmap level to start loading from (0=all)
 @Return		PVR_SUCCESS on success
 @brief	Allows textures to be stored in binary PVR files and loaded in. Can load parts of a
				mipmaped texture (ie skipping the highest detailed levels).
				Sets the texture MIN/MAG filter to GL_LINEAR_MIPMAP_NEAREST/GL_LINEAR
				if mipmaps are present, GL_LINEAR/GL_LINEAR otherwise.
*****************************************************************************/
IGV5Err IGV5Texture_LoadPVRFromFile(IGV5Texture *pTex, char * filename, void *psTextureHeader, int bAllowDecompress, unsigned int nLoadFromLevel);

/*!***************************************************************************
 @fn			IGV5PODModel_FindNodeIdxByName
 @param			pThis			Model pointer
				pNodeName		name of node to look for
 @Return		Number of indices used by mesh
 @brief			Return node index. Return -1 if not found.
*****************************************************************************/
int IGV5PODModel_FindNodeIdxByName(IGV5PODModel *pThis, char *pNodeName);

/*!***************************************************************************
 @fn			IGV5PODModel_FindNodeByName
 @param			pThis			Model pointer
				pNodeName		name of node to look for
 @Return		Number of indices used by mesh
 @brief			Return node pointer 
*****************************************************************************/
SPODNode *IGV5PODModel_FindNodeByName(IGV5PODModel *pThis, char *pNodeName);

/*!***************************************************************************
 @fn			IGV5PODModel_EnableNodeRendering
 @param			pThis		Model pointer
				NodeIdx		Node index
				bEnable		IGV5_TRUE to render this node, IGV5_FALSE to skip this node for rendering actions
 @Return		old visibility status 
 @brief			Enable or disable rendering actions. However, even this node is set to "not render", it will keep update itself.
				So next time the node is rendered again, it will appear to it's antocipated location. If you want the node continue
				animated from where it was disabled to rendering, also call IGV5PODModel_EnableNodeAnimation() to stop animation
*****************************************************************************/
int IGV5PODModel_EnableNodeRendering(IGV5PODModel *pThis, unsigned NodeIdx, int bEnable);

int IGV5PODModel_EnableNodeRenderingByName(IGV5PODModel *pThis, char *pNodeName, int bEnable);

/*!***************************************************************************
 @fn			IGV5PODModel_EnableNodeAnimationByName
 @param			pThis		Model pointer
				NodeIdx		Node index
				bEnable		IGV5_TRUE to enable animation, IGV5_FALSE to disable
 @Return		old animation status 
 @brief			Enable or disable animation
*****************************************************************************/
int IGV5PODModel_EnableNodeAnimation(IGV5PODModel *pThis, unsigned NodeIdx, int bEnable);

/*!***************************************************************************
 @fn			IGV5PODModel_EnableNodeAnimationByName
 @param			pThis			pointer to IGV5PODModel object
 @param			pNodeName		specify name of the node to enable/disable animation 
 @param			bEnable			IGV5_TRUE to enable animation, IGV5_FALSE to disable
 @brief			Enable or disable an IGV5Model sub-node animation, when disable 
				an ongoing animation and re-enable it, it will resume from the 
				frame it has been stopped.
*****************************************************************************/
int IGV5PODModel_EnableNodeAnimationByName(IGV5PODModel *pThis, char *pNodeName, int bEnable);

/*!***************************************************************************
 @fn			IGV5PODModel_SetNodeAnimationFrameByName
 @param			pThis		Model pointer
				pNodeName	Node name to look for
				bEnable		IGV5_TRUE to enable animation, IGV5_FALSE to disable
 @Return		old animation status 
 @brief			Directly set node animation frames by specifying node name
*****************************************************************************/
void IGV5PODModel_SetNodeAnimationFrameByName(IGV5PODModel *pThis, char *pNodeName, float fNodeFrame);

void IGV5PODModel_SetMeshNodeBoneAnimationFrameByName(IGV5PODModel* model, char* nodeName, float frame);

/*!***************************************************************************
 @fn			IGV5PODModel_SetNodeAnimationFrameByName
 @param			pThis		Model pointer
				s			Node pointer
 @brief			Reset any local node transform
*****************************************************************************/
void IGV5PODModel_ResetNodeTransform(SPODNode *s);

/*!***********************************************************************
 @fn		IGV5PODModel_SetPosition
 @param		pModel		pointer to IGV5PODModel
 @param		idx			node index
 @param		x			related distance of x
 @param		y			related distance of y
 @param		z			related distance of z
 @brief		Update node position related to parent node
*************************************************************************/
void IGV5PODModel_SetNodePosition(IGV5PODModel *pThis, unsigned idx, float x, float y, float z);

/*!***********************************************************************
 @fn		IGV5PODModel_SetNodeRotation
 @param		pThis		pointer to IGV5PODModel
 @param		idx			node index
 @param		x			related rotation angle of x
 @param		y			related rotation angle  of y
 @param		z			related rotation angle  of z
 @brief		Update node rotation
*************************************************************************/
void IGV5PODModel_SetNodeRotation(IGV5PODModel *pThis, unsigned idx, float x, float y, float z);

/*!***********************************************************************
 @fn		IGV5PODModel_SetNodeScale
 @param		pThis		pointer to IGV5PODModel
 @param		idx			node index
 @param		x			related scale factor of x
 @param		y			related scale factor of y
 @param		z			related scale factor  of z
 @brief		Update node scale factor
*************************************************************************/
void IGV5PODModel_SetNodeScale(IGV5PODModel *pThis, unsigned idx, float x, float y, float z);

/*!***************************************************************************
 @fn			IGV5BoundingBox_ComputeInterleaved
 @param			pBoundingBox
 @param			pV
 @param			nNumberOfVertices
 @param			i32Offset
 @param			i32Stride
 @brief			Calculate the eight vertices that surround an object.
				This "bounding box" is used later to determine whether
				the object is visible or not.
					
This function should only be called once to determine the object's bounding box.
Takes interleaved data using the first vertex's offset and the stride to the 
next vertex thereafter
*****************************************************************************/
void IGV5BoundingBox_ComputeInterleaved(IGV5BoundingBox	* pBoundingBox,unsigned char* pV,int nNumberOfVertices,	int	i32Offset, int	i32Stride);

void IGV5PODModel_SetNodeMatrix(IGV5PODModel *pThis, unsigned idx, IGV5Matrix *pLocalMatrix);

/*!******************************************************************************
 @gn				IGV5BoundingBox_IsVisibleFromZAxis
 @param				pNeedsZClipping  - *bNeedsZClipping is TRUE if Z clipping is required.
 @param				pBoundingBox  - *pBoundingBox is a pointer to the bounding box structure.
 @param				pMatrix - *pMatrix is the World, View & Projection matrices combined.
 @Return			TRUE if the object is visible, FALSE if not.
 @brief				Determine if a bounding box is "visible" or not along the
					Z axis.
					
If the function returns TRUE, the object is visible and should be displayed (check 
bNeedsZClipping to know if Z Clipping needs to be done).
					
If the function returns FALSE, the object is not visible and thus does not require to be displayed.
bNeedsZClipping indicates whether the object needs Z Clipping (i.e. the object is partially visible).
	
*****************************************************************************/
int IGV5BoundingBox_IsVisibleFromZAxis(IGV5BoundingBox	* pBoundingBox,IGV5Matrix *pMatrix,	int* pNeedsZClipping);

void IGV5PODModel_GetNodePlaneNormal(IGV5PODModel *pThis, unsigned int idx, Vec3* normal);

void IGV5PODModel_GetNodePlanePoint(IGV5PODModel *pThis, unsigned int idx, Vec3* point);


#ifdef __cplusplus
}
#endif

#endif