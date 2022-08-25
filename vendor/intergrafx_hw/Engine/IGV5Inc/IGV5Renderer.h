/*!****************************************************************************

 @File         IGV5Renderer.h

 @Title        IGV5Renderer

 @Version      

 @brief			header file for renderer stuff

******************************************************************************/

#ifndef __IGV5RENDERER
#define __IGV5RENDERER

#include "IGV5RuntimeContext.h"
#include "IGV5Camera.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------- VERTEX AND INDEX BUFFERS ---------------------------------- */

#define IGV5VS_POSITION 0x00000001
#define IGV5VS_NORMAL 0x00000002
#define IGV5VS_DIFFUSE 0x00000003
#define IGV5VS_TEXTURE0 0x00000004
#define IGV5VS_TABGENT 0x0000005
#define IGV5VS_BINORMAL  0x00000006
#define IGV5VS_BONEINDEX 0x00000007
#define IGV5VS_BONEWEIGHT 0x00000008

typedef struct {

	char m_sAttribName[16];
	unsigned m_uSemantic;
	unsigned m_uNumElem;
	unsigned m_uElemType;
	unsigned m_uOffset;

} IGV5VertexAttributeType;

typedef struct {

	unsigned m_uVertexType;

	unsigned m_uDeviceID;  

	unsigned m_uNumAttributes;
	IGV5VertexAttributeType m_Attr[16];
	
	unsigned m_uStride;
	unsigned m_uNumVertices;

	void *m_pSrcVertice;

} IGV5VertexBuffer;

typedef struct {

	unsigned m_uDeviceID; 
	unsigned m_uNumIndices;
	unsigned m_uStride;

	void *m_pSrcIndice;

} IGV5IndexBuffer;


/* ---------------------------------- SHADERS ---------------------------------- */

/*! Group shader programs and their uniform locations together */
typedef struct
{
	unsigned m_uDefShaderID;
	GLuint uiId;
	GLuint uiMVPMatrixLoc;
	GLuint uiLightDirLoc;
	GLuint uiLightColor;
	GLuint uiGlobalAlpha;
} IGV5ShaderProgram;

/*extern EGLint g_aEGLAttributes[]; */

static const EGLint aEGLContextAttributes[] =
{
	EGL_CONTEXT_CLIENT_VERSION, 2,
	EGL_NONE
};

#define IGV5_EGLINIT_USE_DISPLAY 1
#define IGV5_EGLINIT_USE_CONTEXT 2
#define IGV5_EGLINIT_USE_SURFACE 4
#define IGV5_EGLINIT_USE_ALL  (1|2|4)

#define IGV5EFFECT_ID_STANDARD 0x00000001
#define IGV5EFFECT_ID_PNT 0x00000002


/* ---------------------------------- CULLING ---------------------------------- */

#define IGV5RS_CULL_NONE 0x00000000
#define IGV5RS_CULL_BACK 0x00000001
#define IGV5RS_CULL_FRONT 0x00000002
#define IGV5RS_CULL_ALL 0x00000003

void IGV5Renderer_SetBackFaceCulling(unsigned uCullMode);

/* ---------------------------------- BLENDING ---------------------------------- */

#define IGV5RS_ALPHA_NONE 0x00000000
#define IGV5RS_ALPHA_COMPLEMENT 0x00000001
#define IGV5RS_ALPHA_ADD 0x00000002
#define IGV5RS_ALPHA_ONE 0x00000003

/*!***************************************************************************
 @fn			IGV5Renderer_SetAlphaBlendMode
 @param			uMode			one of alpha blending functions:
                                IGV5RS_ALPHA_NONE - no alpha blending
								IGV5RS_ALPHA_COMPLEMENT - source + dest alpha = 1.0f
								IGV5RS_ALPHA_ADD - source alpha + dest (1.0)
								IGV5RS_ALPHA_ONE - source alpha 1.0 + dest alpha 1.0
 @brief			Control alpha blending function
*****************************************************************************/
unsigned IGV5Renderer_SetAlphaBlendMode(unsigned uMode);

/* ---------------------------------- DEPTH FUNCTION ---------------------------------- */

#define IGV5RS_ZTEST_NEVER 0x00000000
#define IGV5RS_ZTEST_LESS  0x00000001
#define IGV5RS_ZTEST_EQUAL 0x00000002
#define IGV5RS_ZTEST_LEQUAL 0x00000003
#define IGV5RS_ZTEST_GREATER 0x00000004
#define IGV5RS_ZTEST_NOTEQUAL 0x00000005
#define IGV5RS_ZTEST_GEQUAL 0x00000006
#define IGV5RS_ZTEST_ALWAYS 0x00000007

void IGV5Renderer_SetZTestFunc(unsigned uFunc);

#define IGV5Render_SetZTestFunc IGV5Renderer_SetZTestFunc

IGV5Err IGV5VertexBuffer_CreateDefault(IGV5VertexBuffer *pVB,int iType, unsigned uNumVertices, void *pSrcVerts);

void IGV5VertexBuffer_Release(IGV5VertexBuffer *pVB);

IGV5Err IGV5IndexBuffer_Create(IGV5IndexBuffer *pIB, unsigned uNumIndices, void *pIndices);

void IGV5IndexBuffer_Release(IGV5IndexBuffer*pIB);

IGV5Err IGV5ShaderProgram_Create(IGV5ShaderProgram *pSP, unsigned uID);

IGV5Err IGV5VertexBuffer_Enable(IGV5VertexBuffer *pVB, unsigned uEnableFlags);

void IGV5VertexBuffer_Disable(IGV5VertexBuffer *pVB, unsigned uEnableFlag);

void IGV5VertexBuffer_Set(IGV5VertexBuffer *pVB);

void IGV5VertexBuffer_ResetVBIB(void);

void IGV5IndexBuffer_Set(IGV5IndexBuffer *pIB);

void IGV5ShaderProgram_Release(IGV5ShaderProgram *pSP);

void IGV5ShaderProgram_Apply(IGV5ShaderProgram *pSP);

void IGV5Renderer_Draw(IGV5ShaderProgram *pSP, unsigned uNumIndices);

void IGV5Skybox_Create(float scale, int adjustUV, int textureSize, IGV5VertexType** Vertices, IGV5VertexType** UVs);

/*!***************************************************************************
 @fn			IGV5Renderer_SetGlobalAlpha
 @param			alpha			alpha value (0 - totally transparent 1.0 - fully opaque)
 @brief			Control global alpha blending factor, all shaders are rendered along with this "tGlobalAlpha" value
*****************************************************************************/
float IGV5Renderer_SetGlobalAlpha(float alpha);

/*!***************************************************************************
 @fn			IGV5Renderer_SetZWrite
 @param			bWritable		IGV5_TRUE if Z write is enabled, IGV5_FALSE if Z write is disabled
 @brief			Control global alpha blending factor, all shaders are rendered along with this "tGlobalAlpha" value
*****************************************************************************/
void IGV5Renderer_SetZWrite(int bWritable);

#define IGV5Render_SetZWrite IGV5Renderer_SetZWrite

/*!***************************************************************************
 @fn			IGV5Renderer_EnableSpecular
 @param			bEnable		IGV5_TRUE if specular calculation is is enabled, otherwise is disabled
 @brief			Control specular calculation 
*****************************************************************************/
void IGV5Renderer_EnableSpecular(int bEnable);

/*!***************************************************************************
 @fn			IGV5Renderer_SetAlphaTestCmpValue
 @param			fCmpValue		alpha comparision value
 @brief			If pixel alpha value is less than this value, the pixle is discard. The range of value is 0.0 ~ 1.0. 
*****************************************************************************/
void IGV5Renderer_SetAlphaTestCmpValue(float fCmpValue);

/*!***************************************************************************
 @fn			IGV5RenderState_Reset
 @param			pRC			pointer to render context
 @brief			Reset cached render states 
*****************************************************************************/
void IGV5RenderState_Reset(IGV5RC *pThisRC);
void IGV5RenderState_Bind(unsigned uBindType, unsigned uBindID);
void IGV5RenderState_ActiveTexture(unsigned stage);
void IGV5RenderState_UseProgram(unsigned programid);

/*!***************************************************************************
 @fn			IGV5Renderer_Present
 @param			pRC			pointer to render context
 @brief			Push the content of current framebuffer to display hardware. In double buffer implementation, frame buffer is switched after this function call. 
*****************************************************************************/
void IGV5Renderer_Present(IGV5RC *pRC);


/*!***************************************************************************
 @fn			IGV5Renderer_EnableStereo3D
 @param			pRC			pointer to render context
 @param			eS3DType	type of stereo 3D supported.
 @param			fInitDepth	initial depth seperation
 @brief			Enable display stereo rendering
*****************************************************************************/
int IGV5Renderer_EnableStereo3D(IGV5RC *pThisRC, IGV5S3DType eS3DType, float fInitDepth);

/*!***************************************************************************
 @fn			IGV5Renderer_PrepareLeft
 @param			pThisRC		pointer to rendering context
 @param			pCam		pointer to IGV5Camera object.
 @brief			Enable display stereo rendering
*****************************************************************************/
void IGV5Renderer_PrepareLeft(IGV5RC *pThisRC, IGV5Camera *pCam);

/*!***************************************************************************
 @fn			IGV5Renderer_PrepareRight
 @param			pThisRC		pointer to rendering context
 @param			pCam		pointer to IGV5Camera object.
 @brief			Enable display stereo rendering
*****************************************************************************/
void IGV5Renderer_PrepareRight(IGV5RC *pThisRC, IGV5Camera *pCam);

/*!***************************************************************************
 @fn			IGV5Renderer_FinishStereo3D
 @param			pRC			pointer to render context
 @brief			This function needs to be called every frame when you render all stereo object out.
*****************************************************************************/
void IGV5Renderer_FinishStereo3D(IGV5RC *pThisRC, IGV5Camera *pCam);

/*!***************************************************************************
 @fn			IGV5Renderer_SetDepthSeperation
 @param			pRC			pointer to render context
 @param			fDepth		new depth seperation
 @brief			set new depth seperation parameters
*****************************************************************************/
void IGV5Renderer_SetDepthSeperation(IGV5RC *pThisRC, float fDepth);

/*!***************************************************************************
 @fn			IGV5Renderer_SetDepthSeperation
 @param			pRC			pointer to render context
 @param			fDepth		new depth seperation
 @brief			Release and stop display stereo rendering image
*****************************************************************************/
void IGV5Renderer_DisableStereo3D(IGV5RC *pThisRC);

/*!***************************************************************************
 @fn			IGV5Sky_NewVertices
 @param			scale			length of skybox 
 @param			adjustUV		This is for PVRT texture compression to allow UV shift
 @param			textureSize		dimension of SkyBox texture. 
 @param			Vertices		pointer to hold newly allocated and created vertice data
 @param			UVs				pointer to hold newly allocated and created UV data.
 @brief			Create new Skybox structure, allocate and initialize vertice and UV data.
*****************************************************************************/
void IGV5Sky_NewVertices(float scale, int adjustUV, int textureSize, IGV5VertexType** Vertices, IGV5VertexType** UVs);


#ifdef __cplusplus
}
#endif

#endif
