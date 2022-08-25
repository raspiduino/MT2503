/*!****************************************************************************

 @File         IGV5RuntimeContext.h 

 @Title        IGV5RuntimeContext

 @Version      

 @brief			header file for IGV5 global variables

******************************************************************************/

#ifndef __IGV5RUNTIMECONTEXT_H
#define __IGV5RUNTIMECONTEXT_H

#include "IGV5Def.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef IGV5_MTK_PHONE
#define WINDOW_RED_SIZE		8
#define WINDOW_GREEN_SIZE	8
#define WINDOW_BLUE_SIZE	8
#define WINDOW_BUFFER_SIZE	24
#else
#define WINDOW_RED_SIZE		5
#define WINDOW_GREEN_SIZE	6
#define WINDOW_BLUE_SIZE		5
#define WINDOW_BUFFER_SIZE	16
#endif

#ifndef IGV5_MTK_PHONE
#define EGL_CHECK(x) \
	x; \
	{ \
		EGLint eglError = eglGetError(); \
		if(eglError != EGL_SUCCESS) { \
			fIGV5System_Printf(stderr, "eglGetError() = %i (0x%.8x) at %s:%i\n", eglError, eglError, __FILE__, __LINE__); \
			exit(1); \
		} \
	}
#else
#define EGL_CHECK(x) \
	x; \
	{ \
		EGLint eglError = eglGetError(); \
		if(eglError != EGL_SUCCESS) { \
			MMI_ASSERT(0); \
		} \
	}
#endif

#ifdef IGV5_DEBUG

	#if defined (IGV5_WIN)

		#define GL_CHECK(x) \
		x; \
		{ \
			char tmp[256]; \
			GLenum glError = glGetError(); \
			if (glError != GL_NO_ERROR) \
			{ \
				sprintf(tmp, "glGetError() = %i (0x%.8x) at %s:%i\n", glError, glError, __FILE__, __LINE__); \
				OutputDebugStringA(tmp);  \
				DebugBreak();  \
			} \
		}

	#elif defined (IGV5_LINUX)

		#define GL_CHECK(x) \
		x; 
		/*{ \
			char tmp[256]; \
			GLenum glError = glGetError(); \
			if(glError != GL_NO_ERROR) { \
				fIGV5System_Printf(stderr, "glGetError() = %i (0x%.8x) at %s:%i\n", glError, glError, __FILE__, __LINE__); \			
				exit(-1); \
			} \
		}*/

	#elif defined (IGV5_LINUX) || defined (IGV5_ANDROID)

		#define GL_CHECK(x) \
		x; 
		/*{ \
			char tmp[256]; \
			GLenum glError = glGetError(); \
			if(glError != GL_NO_ERROR) { \
				fIGV5System_Printf(stderr, "glGetError() = %i (0x%.8x) at %s:%i\n", glError, glError, __FILE__, __LINE__); \			
				exit(-1); \
			} \
		}*/

	#elif defined (IGV5_MTK_PHONE)

		#define GL_CHECK(x) \
        x; 
		
	#endif

#else

	#define GL_CHECK(x) x;

#endif

typedef struct
{
    EGLDisplay sEGLDisplay;
	EGLContext sEGLContext;
	EGLSurface sEGLSurface;
	unsigned m_uFlags;
	unsigned m_uWidth;
	unsigned m_uHeight;
	int m_bUseDepthBuffer;
	int m_bUseStencilBuffer;

} EGLInfo;

typedef struct {
	unsigned m_uTetxureID;
	int m_iActiveUnit;
	int m_iProgramID;
} IGV5CachedRenderStates;


typedef struct {

	unsigned m_uFrames;
	float m_fFPS;

} FrameStatics;

typedef struct {

	unsigned dwVersionRequired;
	EGLInfo m_EGL;
	void *m_pPoolPtr;
	unsigned uSize;

} IGV5InitInfoVer0101;

/*!***************************************************************************
@enum		IGV5S3DType
@brief		type of stereo3D
*****************************************************************************/
typedef enum {

	IGV5S3D_NORMAL,
	IGV5S3D_RED_BLUE,
	IGV5S3D_RED_BLUEGREEN,
	IGV5S3D_SIDE_SIDE,
	IGV5S3D_TOP_BOTTOM

} IGV5S3DType;

typedef struct {

	unsigned m_uAppStartTime;
	EGLInfo m_sEGLInfo;
	FrameStatics m_sPerformanceInfo;

	void *m_pMemPool, *m_pPoolActualPtr;
	unsigned m_uPoolSize;

	/* runtime parameters */
	float m_fDepthSeperation;
	IGV5S3DType m_eS3DType;

} IGV5RC;

#define IGV5VERTEXTYPE_PNCT 0x0000001
#define IGV5VERTEXTYPE_PNT 0x00000002
#define IGV5VERTEXTYPE_SKINDOT3 0x00000003

typedef struct 
{
	Vec3	p;	/*position*/
	Vec3	n;	/*normal*/
	Vec2	t;	/*texture0 coordinate*/
} IGV5VertexPNTType;

typedef struct 
{
	Vec3	p;	/*position*/
	Vec3	n;	/*normal*/
	Vec4	c;	/*color*/
	Vec2	t;	/*texture0 coordinate*/
} IGV5VertexPNCTType;

typedef struct 
{
	Vec3	pos;	/*position*/
	Vec3	normal;	/*normal*/
	Vec3    tangent;  /* tangent */
	Vec3 	binormal;	/*bi-normal*/
	Vec2	t;	/*texture0 coordinate*/
	BYTE    bw[4];   /* bone weight */
	BYTE    bi[4];   /* bone index */
} IGV5VertexSkinDot3Type;

extern IGV5CachedRenderStates g_IGV5CachedRenderStates;

IGV5Err IGV5Engine_InitForOwnerDraw(IGV5RC *pThisRC, unsigned uSizeParams, void *pInit);
IGV5Err IGV5Engine_InitForOwnerDraw_Without_CreatingWindow(IGV5RC *pThisRC, unsigned uSizeParams, void *pInit);
IGV5Err IGV5Engine_Init(IGV5RC *pThisRC, unsigned uSizeParams, void *pInit);

void IGV5Engine_ShutdownForOwnerDraw(IGV5RC *pThisRC);
void IGV5Engine_ShutdownForOwnerDraw_Without_CreatedWindow(IGV5RC *pThisRC);
void IGV5Engine_Shutdown(IGV5RC *pThisRC);


int IGV5InitEGL(IGV5RC *pRC);
#ifdef IGV5_WIN
int IGV5InitEGL_With_Window(IGV5RC *pRC, HWND HWND, HDC DC);
#endif
int IGV5ShutdownEGL(IGV5RC *pRC);


#ifdef __cplusplus
}
#endif

#endif /* __IGV5RUNTIMECONTEXT_H */

