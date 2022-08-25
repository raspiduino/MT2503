/** 
 *
 *	@file		IGV5Def.h	
 *
 *  @brief		Header file for generic IGV5 definitions
 *
 *	@author		Charles Shih-I Yeh
 *
*/

#ifndef __IGV5DEF_H
#define __IGV5DEF_H



#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------- Global build section ---------------------------*/

/* Uncomment the following define to make release build. Release build doesn't check error return status */
#define IGV5_RELEASE 

/* ---------------------------------- adaptator section ---------------------------------- */

/* Check each platform and include necessary header files */


#if defined(__MTK_TARGET__) || defined(_MODIS_ON_VC9_)

	#define IGV5_MTK_PHONE

    #ifndef __WORDSIZE
		#define __WORDSIZE	32
	#endif

	#include "kal_debug.h"
	 #include "mmi_frm_queue_gprot.h"  /* for MMI_ASSERT() */

#elif defined(_WIN32) || defined(_WIN64) || defined(UNDER_CE) || defined(_WIN32_WCE) || defined(WIN32)

	#define IGV5_WIN

	#ifndef __WORDSIZE
		#define __WORDSIZE	32
	#endif

	/* Make VC C++ generate smaller header information, speedup compilation */
	#ifndef WIN32_LEANANDMEAN
		#define WIN32_LEANANDMEAN
	#endif
	#ifndef VC_EXTRALEAN
		#define VC_EXTRALEAN
	#endif

	/* force type conversion */
	#ifndef STRICT
		#define STRICT
	#endif

	#define NOGDICAPMASKS
	#define NOKANJI
	#define NOMETAFILE
	#define NOPROFILER
	#ifndef _WINDOWS_
		#include <windows.h>
	#endif
	#include <mmsystem.h>
	#include <tchar.h>
	#include <stdio.h>
	#include <stdarg.h>

#elif defined(ANDROID_NDK)

	#define IGV5_ANDROID

	#include <stdint.h>

	/* [CY]
	__WORDSIZE in linux is either 32 or 64 (defined in stdint.h)
	in Win32 it's always 32
	*/

	#ifndef __WORDSIZE
		#define __WORDSIZE	32
	#endif

	#include <stdio.h>
	#include <stdlib.h>

#elif defined(linux) || defined(_linux_) || defined(_linux) || defined(__linux) || defined(__linux__)

	#define IGV5_LINUX

	/* Make sure __linux__ and linux is defined */
	#ifndef linux
	#define linux
	#endif
	#ifndef __linux__
	#define __linux__
	#endif

	/* only support GNU C++ compiler above 2.95 */
	#if (__GNUC__ < 2) || (__GNUC__ == 2 && __GNUC_MINOR__ < 91)
	# error GNU C++ 2.95 or later required.
	#endif

	#include <stdint.h>

	/* [CY]
	__WORDSIZE in linux is either 32 or 64 (defined in stdint.h)
	in Win32 it's always 32
	*/

	#ifndef __WORDSIZE
		#define __WORDSIZE	32
	#endif

	#include <stdio.h>
	#include <stdlib.h>

#else

	#error Platform is not suported by IGV5 at this implemntation

#endif

/* ---------------------------------- IGV5 Feature Switch ---------------------------------- */

// uncomment this define to make IGV5 use only proprietary scene file format.
//#define IGV5FEATURE_PROPRIETARY 


/* ---------------------------------- Platform Independent definition ---------------------------------- */


#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/egl.h>

/* uncomment the following define for debug and more check on OpenGL ES API validation, it's nothing to do with VC++ Debug or Release build */
#define IGV5_DEBUG
/* uncomment the following define for release build */
/* #define IGV5_RELEASE */

/*! @typedef		8-bit integer 

 8-bit integer (Platform independent/ Compiler independent)
*/ 
typedef char CHAR, CHAR8, *PCHAR, *PCHAR8, **PPCHAR, **PPCHAR8;

/*! @typedef		8-bit signed integer
 8-bit signed integer (Platform independent/ Compiler independent)
*/
typedef signed char SCHAR, SCHAR8,  I8, 
	*PSCHAR, *PSCHAR8, *PINT8, *PI8, 
	**PPSCHAR, **PPSCHAR8, **PPINT8, **PPI8;

/*! @typedef		8-bit unsigned integer
  8-bit unsigned integer (Platform independent/ Compiler independent)
*/
typedef unsigned char UCHAR, BYTE, BYTE8, UCHAR8, UINT8, U8, 
	*PUCHAR, *PBYTE, *PBYTE8, *PUCHAR8, *PUINT8, *PU8, 
	**PPUCHAR, **PPBYTE, **PPBYTE8, **PPUCHAR8, **PPUINT8, **PPU8;

/*! @typedef		16-bit signed integer
 16-bit signed integer (Platform independent/ Compiler independent)
*/
typedef short SHORT16, SHORT, CHAR16, INT16, I16, 
	*PSHORT16, *PSHORT, *PCHAR16, *PINT16, *PI16, 
	**PPSHORT16, **PPSHORT, **PPCHAR16, **PPINT16, **PPI16;

/*! @typedef		16-bit unsigned integer
 16-bit unsigned integer (Platform independent/ Compiler independent)
*/
typedef unsigned short WORD16, WORD, USHORT, USHORT16,
	WCHAR16, UCHAR16, UINT16, U16, 
	*PWORD16, *PWORD, *PUSHORT, *PUSHORT16, 
	*PWCHAR16, *PUCHAR16, *PUINT16, *PU16, 
	**PPWORD16, **PPWORD, **PPUSHORT, **PPUSHORT16, 
	**PPWCHAR16, **PPUCHAR16, **PPUINT16, **PPU16;

/* Borland C++ defines WCHAR in winnt.h , this is special case -> typedef uchar_t WCHAR, *PWCHAR; */
/*#ifndef __BCPLUSPLUS__
typedef unsigned short WCHAR, *PWCHAR;
#endif
typedef PWCHAR *PPWCHAR; */

/*! @typedef		32-bit signed integer
  32-bit signed integer (Platform independent/ Compiler independent)
  for not conflicting with previous section, we divide this into two parts.
*/
#if __WORDSIZE == 32
typedef long LONG, I32,	*PLONG, *PI32, **PPLONG, **PPI32;
#else
typedef int  LONG, I32,	*PLONG, *PI32, **PPLONG, **PPI32;
#endif
typedef int  LONG32, *PINT32, *PLONG32, **PPINT32, **PPLONG32;

/*! @typedef		32-bit unsgined integer
  32-bit unsgined integer (Platform independent/ Compiler independent)
  for not conflicting with previous section, we divide this into two parts 
*/
#if __WORDSIZE == 32
typedef unsigned long
	ULONG, WORD32, DWORD,
	*PULONG, *PWORD32, *PDWORD,
	**PPULONG, **PPWORD32, **PPDWORD, **PPU32;
#else
typedef unsigned int
	ULONG, WORD32, DWORD, U32,
	*PULONG, *PWORD32, *PDWORD, *PU32,
	**PPULONG, **PPWORD32, **PPDWORD, **PPU32;
#endif

/* ---------------------------------- Platform dependent definition ---------------------------------- */





/*
// VC++ defines __int64 as 64-bit integer
// GNU C++ use long long 
*/
#if defined(IGV5_WIN) && (defined(_WIN32) || defined(_WIN64))
#define __INT64 __int64
#else
#define __INT64 long long
#endif

/*
// 64-bit signed integer
// (Platform independent/ Compiler independent)
*/
typedef __INT64
	LONGLONG, INT64, LONG64, I64,
	*PLONGLONG, *PINT64, *PLONG64, *PI64,
	**PPLONGLONG, **PPINT64, **PPLONG64, **PPI64;

/*
// 64-bit unsigned integer
// (Platform independent/ Compiler independent)
*/
typedef unsigned __INT64 
	ULONGLONG, UINT64, ULONG64, WORD64, DWORD64, U64,
	*PULONGLONG, *PUINT64, *PULONG64, *PWORD64, *PDWORD64, *PU64,
	**PPULONGLONG, **PPUINT64, **PPULONG64, **PPWORD64, 
	**PPDWORD64, **PPU64;

/*
// Platform dependent 32-bit or 64-bit integer
// ¥]¬A¡GINT_PTR, LONG_PTR, UINT_PTR, ULONG_PTR, DWORD_PTR
// The (sizeof) of these types are platform dependent, however, it's same size as pointer size of the platform
// 
*/
#if defined(IGV5_WIN)
/* windows.h automatically include basetsd.h
 It has defined INT_PTR, UINT_PTR, PINT_PTR, PUINT_PTR */
typedef PINT_PTR *PPINT_PTR;
typedef PUINT_PTR *PPUINT_PTR;
/* DirectX and Visual C++ both has its own basetsd.h, they are a bit different, 
// DirectX version is better.
// If you include basetsd.h from VC, LONG_PTR, ULONG_PTR, DWORD_PTR are not available.
// Newer Visual C++ will use better basetsd.h */

#if _MSC_VER > 1200		/* Visual C++ > 6.0 */
typedef PLONG_PTR *PPLONG_PTR;
typedef PULONG_PTR *PPULONG_PTR;
typedef PDWORD_PTR *PPDWORD_PTR;
#endif
#else
/* None Win32/Win64 platform */
#if __WORDSIZE == 64		/* 64-bit integer */
typedef __INT64 INT_PTR, LONG_PTR, *PINT_PTR, *PLONG_PTR, 
	**PPINT_PTR, **PPLONG_PTR;
typedef unsigned __INT64 UINT_PTR, ULONG_PTR, DWORD_PTR, 
	*PUINT_PTR, *PULONG_PTR, *PDWORD_PTR,
	**PPUINT_PTR, **PPULONG_PTR, **PPDWORD_PTR;
#else						/* 32-bit integer */
typedef int INT_PTR, *PINT_PTR, **PPINT_PTR;
typedef long LONG_PTR, *PLONG_PTR, **PPLONG_PTR;
typedef unsigned int UINT_PTR, *PUINT_PTR, **PPUINT_PTR;
typedef unsigned long ULONG_PTR, DWORD_PTR, *PULONG_PTR, *PDWORD_PTR,
	**PPULONG_PTR, **PPDWORD_PTR;
#endif

#endif
#undef __INT64

/*
// 32-bit float
// (Platform independent/ Compiler independent)
*/
typedef float FLOAT, FLOAT32, 
	*PFLOAT, *PFLOAT32, 
	**PPFLOAT, **PPFLOAT32;

/*
// 64-bit float
// (Platform independent/ Compiler independent)
*/
typedef double
	DOUBLE, FLOAT64,
	*PDOUBLE, *PFLOAT64,
	**PPDOUBLE, **PPFLOAT64;

/*
// Boolean constant
// (Provide 8-bit, 16-bit, 32-bit )
*/
/* 8-bit bool */
typedef signed char BOOL8, BYTEBOOL, 
	*PBOOL8, *PBYTEBOOL, **PPBOOL8, **PPBYTEBOOL;
/* 16-bit bool */
typedef INT16 BOOL16, WORDBOOL,
	*PBOOL16, *PWORDBOOL, **PPBOOL16, **PPWORDBOOL;
/* 32-bit bool */
typedef int	 BOOL32, 
	*PBOOL, *PBOOL32, **PPBOOL, **PPBOOL32;
/* Constant(s) */
#ifndef FALSE
#define FALSE	(0)
#define TRUE	(!(FALSE))
#endif

/*
// OpenGL family specific data types
// GFLOAT  : Equal to D3D float/FLOAT in Direct3D and  GLfloat in OpenGL
// GDOUBLE : Equal to GLdouble of OpenGL 
*/
typedef float GFLOAT, *PGFLOAT, **PPGFLOAT;
typedef double GDOUBLE, *PGDOUBLE, **PPGDOUBLE;

/* ---------------------------------- Global defines ---------------------------------- */

#ifdef IGV5_WIN
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#endif

/* This define avoid compiler complain unreferenced local variable */
#define IGV5_UNREF(x) ((void) x)

typedef enum {

	IGV5ERR_NONE = 0,			/*!< The function worked correctly */
	IGV5ERR_FAIL = -1,			/*!< The function failed, reason is either unknown or too complicated to describe as error code */
	IGV5ERR_INVALID_PARAMS,		/*!< The function failed due to invalid parameters passed to the function */
	IGV5ERR_UNSOPPORTED,   		/*!< The function failed due to valid but not supported parameters settings */
	IGV5ERR_INVALID_DATA,		/*!< The function failed due to invalid data format */
	IGV5ERR_DUPLICATED,			/*!< The function failed due to passed argument is duplicated */
	IGV5ERR_NOMEMORY,			/*!< The function failed due to out of memory */
	IGV5ERR_FAILED_CREATIGNG_LOGFILE	/*!< Creating log file failed.  */
} IGV5Err;

/* ---------------------------------- Global 3D defines ---------------------------------- */

/* These data types are frequently used in our program and hence we put them here for convenience */

/*! @typedef	2D vector */
typedef struct
{
	float x, y;
} Vec2;

/*! @typedef	3D vector */
typedef struct
{
	float x, y, z;
} Vec3;

/*! @typedef	4D vector */
typedef struct
{
	float x, y, z, w;
} Vec4;

/*! @typedef	rectangle structure */
typedef struct 
{
	int m_iLeft, m_iTop, m_iRight, m_iBottom;
} IGV5Rect;

/*! @typedef	rectangle structure with floating point coordinate */
typedef struct 
{
	int m_fLeft, m_fTop, m_fRight, m_fBottom;
} IGV5RectF;

#define IGV5_TRUE  1
#define IGV5_FALSE  0

#if !defined(IGV5_MTK_PHONE) && defined(IGV5_WIN)
    #define  IGV5_MAXPATH_LEN 128
#else
    #define IGV5_MAXPATH_LEN 64
#endif

/* ----------------------------------  Assert and Debug ---------------------------------- */

#ifndef _ASSERT
	#ifdef IGV5_WIN
		#ifdef _DEBUG
			#define _ASSERT(X) { (X) ? 0 : DebugBreak(); }
		#else
			#define _ASSERT(X)
		#endif
	#else
		#define _ASSERT(X)
	#endif
#endif

/* ---------------------------------- Basic Mathematical Define ---------------------------------- */

#ifndef M_PI
#define M_PI 3.14159265359f
#endif

#define IGV5_PI					(3.1415926535f)
#define IGV5_TWO_PI				(IGV5_PI * 2.0f)				// (6.28318530718f)
#define IGV5_PI_OVER_TWO		(IGV5_PI / 2.0f)
#define IGV5_PI_OVER_FOUR			(IGV5_PI / 4.0f)
#define IGV5_PI_OVER_SIX			(IGV5_PI / 6.0f)
#define IGV5_PI_OVER_TEN			(IGV5_PI / 10.0f)
#define IGV5_PI_OVER_HUNDRED		(IGV5_PI / 100.0f)
#define IGV5_PI_OVER_THOUSANDTH	(IGV5_PI / 1000.0f)

#define IGV5_ONE				(1.0f)

#define IG_SQRTROOT_TWO		1.414213562373095f    //sqrt(2)
#define IG_SQRTROOT_THREE	1.732050807568773f    //sqrt(3)

/*! @def	convert degree to radian */
#define DEG2RAD(a) (M_PI * a / 180.0f)

/*! @def	convert radians to degrees  */
#define RAD2DEG(a) (a * 180.0f / M_PI)
/*! @def	macro to find minimum number from value a, b */
#define IGV5_MIN(a,b)            (((a) < (b)) ? (a) : (b))

/*! @def	macro to find maximum number from value a, b */
#define IGV5_MAX(a,b)            (((a) > (b)) ? (a) : (b))

/*! @def	macro to keep value x within l and h */
#define IGV5_CLAMP(x, l, h)      (IGV5_MIN((h), IGV5_MAX((x), (l))))

/*! @def	macro to find absolute value of a */
#define IGV5ABS(a)		((a) <= 0 ? -(a) : (a) )
#define IGV5_ABS(a)		((a) <= 0 ? -(a) : (a) )

/*! @def	vertex type 
  IGV5 natively support ES 2.0 so the vertex type is always float.
*/
#define IGV5VertexType float

#define VERTTYPEMUL(a,b)			( (IGV5VertexType)((a)*(b)) )
	#define VERTTYPEDIV(a,b)			( (IGV5VertexType)((a)/(b)) )
	#define VERTTYPEABS(a)				( (IGV5VertexType)(fabs(a)) )

#define f2vt(x)   (x)
#define vt2f(x)   (x)

#define  IGV5_SHININESS_SCALE 256

#define  IGV5_ALPHATESTVALUE 0.5f

/* ---------------------------------- HINT ---------------------------------- */


/* ----------------------------------  Global Utility Function Define ---------------------------------- */

/*! @fn		IGV5IsLittleEndian
 @retun		IGV5_TRUE if system is little endian.
*/
int IGV5IsLittleEndian(void);

int IGV5System_Printf(char *fmt, ...);

void IGAssert(void);

#ifdef __cplusplus
}
#endif

#endif

/* end of IGV5Def.h */

