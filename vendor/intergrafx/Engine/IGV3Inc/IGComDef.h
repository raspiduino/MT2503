/**
@file IGComDef.h  
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
#ifndef IG_COMDEF_H
#define IG_COMDEF_H

//platform and compiling definitions
#include "IGExtDef.h"

#ifdef __cplusplus
extern "C"
{
#endif


/**
    * Null pointer value.
    */
#ifndef NULL
#define NULL 0
#endif

/**
    * 8-bit signed quantity.
    */
typedef signed char igint8;

/**
    * 8-bit unsigned quantity.
    */
typedef unsigned char iguint8;

/**
    * 16-bit signed quantity.
    */
typedef signed short igint16;

/**
    * 16-bit unsigned quantity.
    */
typedef unsigned short iguint16;

/**
    * 32-bit signed quantity.
    */
typedef signed long igint32;

/**
    * 32-bit unsigned quantity.
    */
typedef unsigned long iguint32;

/**
    * Real number type.
    * Is either a 32-bit fixed-point or true floating-point point quantity
    * depending on the target platform for which the engine was built.
    */
#if defined(IG_FLOATING)

typedef float igreal;
#else

typedef igint32 igreal;
#endif

/**
    * Primitive type representing one pixel in a platform-dependent color format.
    * Currently only 16-bpp device video buffers are supported.
    */
typedef iguint16 igcolor;

/**
    * Boolean quantity.
    */
typedef enum 
{
    /** Indicates a condition to be untrue. */
    IGBOOL_FALSE,

    /** Indicates a condition to be true. */
    IGBOOL_TRUE

}   igbool;


typedef struct _IGPoint
{
    igint32     x;
    igint32     y;
}
IGPoint;

typedef struct _IGRect
{
    igint32 x1;
    igint32 y1;
    igint32 x2;
    igint32 y2;
}
IGRect;

#define IGSetRect( r, ix1, iy1, ix2, iy2 ) \
    (r)->x1 = (ix1); \
    (r)->y1 = (iy1); \
    (r)->x2 = (ix2); \
    (r)->y2 = (iy2)

// union b and c, put result into a
#define IGUnionRect( a, b, c ) \
    (a)->x1 = ( (b)->x1 <= (c)->x1 ) ? (b)->x1 : (c)->x1; \
    (a)->y1 = ( (b)->y1 <= (c)->y1 ) ? (b)->y1 : (c)->y1; \
    (a)->x2 = ( (b)->x2 >= (c)->x2 ) ? (b)->x2 : (c)->x2; \
    (a)->y2 = ( (b)->y2 >= (c)->y2 ) ? (b)->y2 : (c)->y2


/**
    * Shading mode identifiers.
    * Used to signal to the engine which shader should be used in rendering.
    */
typedef enum 
{
    /** Indicates that all surfaces should be fully illuminated. */
    IGSHADING_NONE,

    /** Indicates that each face on a surface will be illuminated
        based on the lighting and on its normal vector. */
    IGSHADING_FLAT,

    /** Indicates that each vertex on a surface will be illuminated
        based on the lighting and on its normal vector, and that
        illuminations of faces will be interpolated from vertex to vertex. */
    IGSHADING_GOURAUD_PHONG

}   IGShadingMode;

/**
    * Node type identifiers.
    * Used to signal what specific type of object a node in a scene tree is.
    */
typedef enum 
{
    /** Indicates that a node is an IGGroup. */
    IGNODE_GROUP,

    /** Indicates that a node is an IGMesh. */
    IGNODE_MESH,

    /** Indicates that a node is an IGLight. */
    IGNODE_LIGHT,

    /** Indicates that a node is an IGCamera. */
    IGNODE_CAMERA

}   IGNodeType;

/**
    * Blending mode identifiers.
    * Used to signal to the engine which blending effect should be used in rendering.
    */
typedef enum 
{
    /** Indicates that triangles should be rendered over whatever is already onscreen. */
    IGBLENDING_OVERWRITE,

    /** Indicates that triangles should only paint to pixels for which they are the closest
        surface to the viewer. */
    IGBLENDING_ZBUFFER,

    /** Indicates that triangles should blend their colors with the existing colors based
        on their transparency values. */
    IGBLENDING_TRANSPARENCY

}   IGBlendingMode;

/**
    * Identifiers used to specify parallel or perspective projection rendering.
    */
typedef enum 
{
    /** Indicates that a camera's view volume is an infinite rectangular prism. */
    IGVIEW_PARALLEL,

    /** Indicates that a camera's view volume is an infinite rectangular pyramid. */
    IGVIEW_PERSPECTIVE

}   IGViewMode;

/**
    * Identifiers for the 3 types of IGBackground.
    */
typedef enum
{
    /** Indicates that a background is a solid color. */
    IGBACKGROUND_COLOR,

    /** Indicates that a background is an image. */
    IGBACKGROUND_IMAGE,

}   IGBackgroundType;

/**
    * Identifiers for the 2 supported bitmap types.
    */
typedef enum
{
    /** Indicates that a texture file is an unknown type. */
    IGIMAGE_OTHER,

    /** Indicates that a texture file is BMP. */
    IGIMAGE_BMP,

	IGIMAGE_PNG,

    /** Indicates that a texture file is JPG. */
    IGIMAGE_JPG

}   IGImageType;

/**
    * Light type identifiers.
    * Used to determine how a light will illuminate its surroundings.
    */
typedef enum 
{
    /** Indicates that the light will illuminate all surfaces equally. */
    IGLIGHT_AMBIENT,

    /** Indicates that the light will illuminate surfaces based on their
        normal vectors. */
    IGLIGHT_DIRECTIONAL

}   IGLightType;

/**
    * Vertex property flags.
    * Used to signal whether or not a vertex is storing
    * a given property.
    */
typedef enum 
{
    /** Indicates that the vertex contains texture coordinates. */
    IGVERTEX_TEXTURED = 0x0001,

    /** Indicates that the vertex contains a pointer to its 'bone'. */
    IGVERTEX_SKINNED  = 0x0002,

	IGVERTEX_UVANIM   = 0x0004,

	IGENVIRONMENT_MAPPING  =  0x0008,

	IGMUL_TEXTURE          =  0x0010,

	IGTOPOLOGY_INFO        =  0x0020,

	IGSUPPORT_PHONG        =  0x0040,

}   IGVertexProperty;

/**
    * Identifiers used to signal error conditions in API calls.
    */
typedef enum 
{
    /** No errors occurred. */
    IGERR_NONE = 0,

    /** Engine attempted to dereference a null pointer. */
    IGERR_NULLPOINTER = -2,

    /** Engine attempted to access an element in a list via an index that is
        less than 0 or greater than the length of the list. */
    IGERR_INDEXOUTOFBOUNDS = -4,

    /** Engine searched for an object by name and was unable to find it. */
    IGERR_OBJECTNOTFOUND = -5,

    /** Engine attempted to add an object to a table more than once. */
    IGERR_DUPLICATEELEMENT = -6,

    /** Engine failed to open a file for reading or writing. */
    IGERR_CANNOTOPENFILE = -7,

    /** Engine failed to close a file. */
    IGERR_CANNOTCLOSEFILE = -8,

    /** Engine failed to read from file (possibly because end of file was reached). */
    IGERR_CANNOTREADFROMFILE = -9,

    /** Engine failed to write to file. */
    IGERR_CANNOTWRITETOFILE = -10,

    /** Engine failed to seek in file (possibly because end of file was reached). */
    IGERR_CANNOTSEEKINFILE = -11,

    /** Engine attempted to divide by zero. */
    IGERR_DIVISIONBYZERO = -12,

    /** Engine was asked to calculate a number which does not exist (Ie,
        is not real, not finite, etc). */
    IGERR_NOTANUMBER = -13,

    /** Engine attempted to create a keyframe sequence whose key frame
        times are not monotonically increasing. */
    IGERR_INVALIDKEYPATHDURATION = -14,

    /** Engine attempted to interpolate a keyframe sequence to a time
        outside the range of its key frames. */
    IGERR_INVALIDKEYPATHTIME = -15,

    /** Engine attempted to assign a light intensity less than IG_ZERO
        or greater than IG_ONE. */
    IGERR_INVALIDLIGHTINTENSITY = -16,

    /** Engine attempted to interpolate a morph path to a time outside
        the range of its target times. */
    IGERR_INVALIDMORPHPATHTIME = -17,

    /** Engine tried to move a camera to a spot outside the unit sphere. */
    IGERR_INVALIDCAMERAPOSITION = -18,

    /** Engine tried to assign a negative aspect ratio to a camera. */
    IGERR_INVALIDCAMERAASPECTRATIO = -19,

    /** Engine tried to assign a perspective field of view outside the range
        [IG_ZERO, IG_PI] or a parallel field of view outside the range [IG_ZERO, IG_FOUR] */
    IGERR_INVALIDCAMERAFIELDOFVIEW = -20,

    /** Engine tried to move a node to a spot where its bounding sphere would
        not be contained by the bounding sphere of its parent. */
    IGERR_INVALIDNODEPOSITION = -21,

    /** Engine tried to enlarge a node to the point where its bounding sphere would
        not be contained by the bounding sphere of its parent. */
    IGERR_INVALIDNODESCALE = -22,

    /** Engine told a non-morphing mesh to start a morph action. */
    IGERR_MESHNOTMORPHABLE = -23,

    /** Engine tried to draw to a NULL pixel array. */
    IGERR_INVALIDRENDERTARGET = -24,

    /** Engine tried to load a scene from a file or byte array that is not a valid .igf byte sequence. */
    IGERR_INVALIDSCENE = -25,

    /** Engine attempted to allocate more memory than there is available in the system. */
    IGERR_OUTOFMEMORY = -26,

    /** Engine attempted to free a pointer that was either never allocated or already freed. */
    IGERR_CANNOTFREENULLPOINTER = -27,

    /** Engine attempted to play an audio file that could not be found. */
    IGERR_CANNOTCREATEAUDIOHANDLE = -28,

    /** Engine attempted to read an igf file that is either too old or too new. */
    IGERR_FILEVERSIONMISMATCH = -29,

    /** Engine attempted to draw a background image that was not the same size as the frame buffer. */
    IGERR_INVALIDBACKGROUNDSIZE = -30,

    /** Engine searched for an action by name and was unable to find it. */
    IGERR_ACTIONNOTFOUND = -31,

    /** Engine searched for the active camera and was unable to find it. */
    IGERR_ACTIVECAMERANOTFOUND = -32,

    /** Triangle was passed to the rasterizer whose dimensions were too extreme. */
    IGERR_UNDRAWABLETRIANGLE = -33,

    /** Attempt to allocate a cache of negative size. */
    IGERR_INVALIDCACHESIZE = -34,

    /** Attempt to render a texture with an invalid size. */
    IGERR_INVALIDTEXTURESIZE = -35,

    /** Attempt to allocate a render target with an invalid size. */
    IGERR_INVALIDRENDERTARGETSIZE = -36,

    /** Engine using an invalid color format. */
    IGERR_INVALIDCOLORFORMAT = -37,

    /** Object given an invalid name. */
    IGERR_INVALIDNAME = -38,

    /** Texture could not be found. */
    IGERR_MISSINGTEXTURE = -39,

    /** Engine tried to move a vertex to a spot where it would
        not be contained by the bounding sphere of its mesh. */
    IGERR_INVALIDVERTEXXYZPOSITION = -40,

    /** Engine tried to move a vertex's texture coord to a spot
        outside [0,1]. */
    IGERR_INVALIDVERTEXUVPOSITION = -41,

    /** Engine tried to set an attribute of a mesh that the mesh
        does not contain. */
    IGERR_INVALIDMESHATTRIBUTE = -42,

    /** Engine tried to read a texture from a file that is not a
        valid image file.*/
    IGERR_INVALIDTEXTUREFILE = -43,

    /** Engine tried to use a node type other than the ones
        specified in IGNodeType */
    IGERR_INVALIDNODETYPE = -44,

    /** An audio related parameter is out of bounds */
    IGERR_INVALIDAUDIOPARAMETER = -45,

    /** User tried to check bounding box of a node which does not have one. */
    IGERR_INVALIDBOUNDINGBOX = -46,

    /** ZLib returned an error. */
    IGERR_ZLIBINFLATEFAILED = -47,

	/** Bone not found. Incompatible two different skeletons **/ 
	IGERR_DIFFERENTSKELETONS = -48,

	/** SNS API initialization result **/
	IGSNSERR_NONE = 1,

	/** system has no network access **/
	IGSNSERR_NONETWORK = -50,

	/** server is busy, timeout **/
	IGSNSERR_TIMEOUT = -51,


}   IGErr;

/**
    * Internal storage size of strings in the engine.
    * Names of objects are internally unique up to IG_MAXNAMELEN characters.
    */

/* this is defined by original and can not be changed since exporter actually use this length */
#define IG_MAXNAMELEN 127

/* IGV3 3.5.1 Build 008 and later will use only 31 bytes maximum for any literal name in runtime */
#define IG_NAMELEN  31


/**
    * The number of fractional bits in most fixed-point numbers (coordinates, angles, etc.).
    * All products of multiplications should have results <= @a IG_ONE.
    */
#define IG_UNIT_FB 15

/**
    * The maximum allowed width in pixels of a render target.
    */
#define IG_MAX_SCREEN_WIDTH 1024

/**
    * The maximum allowed height in pixels of a render target.
    */
#define IG_MAX_SCREEN_HEIGHT 1024

#ifdef __cplusplus
}
#endif

///////////////////////////////////////////


/**
 * @file IGComDef_i.h
 * Internal common definitions header.
 */

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(WIN32)
 #pragma warning(disable:4311)
 #pragma warning(disable:4312)
#endif

#define NAMEOF(X) ((X) ? (X)->m_name : "")

#define NULLCHECK(X,Y) \
{ \
    if (!X) \
    { \
        ASSIGNERROR(Y, IGERR_NULLPOINTER); \
    return; \
} \
}

#define NULLCHECKRETURN(X,Y,Z) \
{ \
    if (!X) \
    { \
        ASSIGNERROR(Y, IGERR_NULLPOINTER); \
        return Z; \
    } \
}

#define NAMECHECK(X,Y) \
{ \
    if (!X || !IGMemoryPool_i_strcmp(X, "")) \
    { \
        ASSIGNERROR(Y, IGERR_INVALIDNAME); \
        return; \
    } \
}

#define NAMECHECKRETURN(X,Y,Z) \
{ \
    if (!X || !IGMemoryPool_i_strcmp(X, "")) \
    { \
        ASSIGNERROR(Y, IGERR_INVALIDNAME); \
        return Z; \
    } \
}

#define INDEXCHECK(X,A,B,Y) \
{ \
    if ((X) < (A) || (X) > (B)) \
    { \
        ASSIGNERROR(Y, IGERR_INDEXOUTOFBOUNDS); \
        return; \
    } \
}

#define INDEXCHECKRETURN(X,A,B,Y,Z) \
{ \
    if ((X) < (A) || (X) > (B)) \
    { \
        ASSIGNERROR(Y, IGERR_INDEXOUTOFBOUNDS); \
        return Z; \
    } \
}

#define NODETYPECHECK(X,Y) \
{ \
    if (X != IGNODE_GROUP && X != IGNODE_MESH && X != IGNODE_LIGHT && X != IGNODE_CAMERA) \
    { \
        ASSIGNERROR(Y, IGERR_INVALIDNODETYPE); \
        return; \
    } \
}

#define NODETYPECHECKRETURN(X,Y,Z) \
{ \
    if (X != IGNODE_GROUP && X != IGNODE_MESH && X != IGNODE_LIGHT && X != IGNODE_CAMERA) \
    { \
        ASSIGNERROR(Y, IGERR_INVALIDNODETYPE); \
        return Z; \
    } \
}

#define ERRORCHECK(X) \
{ \
    if (*X != IGERR_NONE) \
    { \
        return; \
    } \
}

#define ERRORCHECKRETURN(X,Y) \
{ \
    if (*X != IGERR_NONE) \
    { \
        return Y; \
    } \
}

#define ASSIGNERROR(X,Y) *(X) = (Y)

#define DROPERROR(X,Y) if (*(X) == (Y)) *(X) = IGERR_NONE

#define INTERPRETERROR(X,Y) if (*(X) != IGERR_NONE) *(X) = (Y)

/**
    * Value which invalid or uninitialized pointers should be assigned.
    */
#ifndef NULL
#define NULL 0
#endif

/**
    * @def REAL2FIX
    * If the engine is running in floating-point, this converts a
    * number to fixed-point format.
    *
    * @param X
    *   Number in floating-point format
    * @return
    *   Resulting number in fixed-point format
    */
#if defined(IG_FLOATING)
#define REAL2FIX(X) ((igint32) ((X) * (float)(1L << IG_UNIT_FB)))
#else
#define REAL2FIX(X) (X)
#endif

/**
    * @def FIX2REAL
    * If the engine is running in floating-point, this converts a
    * number to floating-point format.
    *
    * @param X
    *   Number in fixed-point format
    * @return
    *   Resulting number in floating-point format
    */
#if defined(IG_FLOATING)
#define FIX2REAL(X) (((float) (X)) / ((float) (1 << IG_UNIT_FB)))
#else
#define FIX2REAL(X) (X)
#endif

/**
    * Specifies which file format version this engine is compatible with.
    * (Last format change: March 31, 2004)
    */
#if defined(IG_SDK_1_1)
#define IG_FILE_VERSION 31124
#else
#define IG_FILE_VERSION 40331
#endif

#define IG_VERSION_MASK 0x0000FFFF
#define IG_UNCOMPRESSED 0x10000

// maximum texture size in memory allowed
#define IG_MAX_TEXTURE_SIZE (256*256)

// Debugging flag
// uncomment the following define to enable dump of memory usage of each newXXX API
//#define IGDEBUG_MEMORYUSAGE
// uncomment the following define to enable dump of memory pool health message 
//#define IGDEBUG_MEMORYPOOL
// uncomment the following define to enable dump of 3D rendering status
//#define IGDEBUG_3DDATA
// uncomment the following define to enable pixel fillrate stastics
//#define IGDEBUG_PIXEL
// uncomment the following define to enable rendering timing
//#define IGDEBUG_FPS

extern unsigned g_uIGTotalMemUsed;
extern unsigned g_IGNumSceneTriangles;
extern unsigned g_IGNumTriRasterized;
extern unsigned g_IGNumScnenMeshes;

extern unsigned g_IGRender2DTime;
extern unsigned g_IGRender3DTime;
extern unsigned g_IGRasterizeTime;
extern unsigned g_IGRenderUITime;

// Get millisecond ticks count
unsigned IGTimerGetTime(void);
// Get millisecond ticks count from last call to  IGTimerGetInterval(), call this function won't cause real HW timer intreval update
unsigned IGTimerGetInterval(void);

#ifdef __cplusplus
}
#endif


#endif//IG_COMDEF_H

