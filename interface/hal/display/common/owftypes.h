/* Copyright (c) 2009 The Khronos Group Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and/or associated documentation files (the
 * "Materials"), to deal in the Materials without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Materials, and to
 * permit persons to whom the Materials are furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Materials.
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
 */

#ifndef __OWFTYPES_H__
#define __OWFTYPES_H__

//#define OWF_ON_KHRPLATFORM
#define OWF_ON_KAL

#ifdef OWF_ON_KHRPLATFORM
#include "KHR/khrplatform.h"
#endif

#ifdef OWF_ON_KAL
#include "kal_release.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef OWF_ON_KHRPLATFORM
typedef khronos_int8_t      OWFint8;
typedef khronos_int16_t     OWFint16;
typedef khronos_int32_t     OWFint32;
typedef khronos_int32_t     OWFint;
typedef khronos_uint8_t     OWFuint8;
typedef khronos_uint16_t    OWFuint16;
typedef khronos_uint32_t    OWFuint32;
typedef khronos_uint32_t    OWFuint;
typedef khronos_float_t     OWFfloat;

typedef khronos_utime_nanoseconds_t OWFtime;
#endif /* OWF_ON_KHRPLATFORM */

#ifdef OWF_ON_KAL
typedef kal_int8      OWFint8;
typedef kal_int16     OWFint16;
typedef kal_int32     OWFint32;
typedef kal_int32     OWFint;
typedef kal_uint8     OWFuint8;
typedef kal_uint16    OWFuint16;
typedef kal_uint32    OWFuint32;
typedef kal_uint32    OWFuint;
typedef kal_uint32    OWFfloat; /**< \remark Float type is not supported in MTK implementation. */

typedef kal_uint64    OWFtime;
#endif /* OWF_ON_KHRPLATFORM */


typedef OWFuint32 OWFHandle;

#define OWF_FOREVER (0xFFFFFFFFFFFFFFFFull)
#define OWF_INVALID_HANDLE ((OWFHandle)0)


/* Used for Function Prototypes */
/*! \brief OWF_API_CALL definition can be used to restrict
 *  visibility of symbols
 */

#ifndef OWF_API_CALL
#if defined(__GNUC__)
#define OWF_API_CALL __attribute__ ((visibility("hidden")))
#define OWF_PUBLIC __attribute__ ((visibility("default")))
#else
#define OWF_API_CALL
#define OWF_PUBLIC
#endif
#endif
#ifndef OWF_APIENTRY
#define OWF_APIENTRY
#endif
#ifndef OWF_APIEXIT
#define OWF_APIEXIT
#endif

/**
 * supported external image formats 
 */
typedef enum {
    OWF_IMAGE_NOT_SUPPORTED = 0,
    OWF_IMAGE_ARGB8888      = 0x8888,
    OWF_IMAGE_XRGB8888      = 0xf888,
    OWF_IMAGE_RGB888        = 0x888, /**< \remark <b>[MTK]</b> R in high byte, B in low byte. */
    OWF_IMAGE_BGR888        = 0x1888, /**< <b>[MTK]</b> BGR color format. B in high byte and R in low byte. */
    OWF_IMAGE_RGB565        = 0x565,
    OWF_IMAGE_L32           = 0xA32,
    OWF_IMAGE_L16           = 0xA16,
    OWF_IMAGE_L8            = 0xA8,
    OWF_IMAGE_L1            = 0xA1,
    OWF_IMAGE_UYVY          = 0x422, /**< <b>[MTK]</b> UYVY color format. */
    OWF_IMAGE_ARGB6666      = 0x6666,
    OWF_IMAGE_ARGB_INTERNAL = 0x666 /**< OWFpixel rep */
} OWF_PIXEL_FORMAT;

#ifdef OWF_ON_KHRPLATFORM
typedef enum {
    OWF_FALSE               = KHR_BOOLEAN_FALSE,
    OWF_TRUE                = KHR_BOOLEAN_TRUE
} OWFboolean;
#endif

#ifdef OWF_ON_KAL
typedef enum {
    OWF_FALSE               = KAL_FALSE,
    OWF_TRUE                = KAL_TRUE
} OWFboolean;
#endif

typedef struct {
    OWF_PIXEL_FORMAT        pixelFormat;
    OWFboolean              linear;
    OWFboolean              premultiplied;
    OWFint                  rowPadding; /**< row alignment, in bytes */
} OWF_IMAGE_FORMAT;

typedef struct {
    OWFint                  x;
    OWFint                  y;
    OWFint                  width;
    OWFint                  height;
} OWF_RECTANGLE;

#ifndef MIN
#define MIN(a,b)            ((a)<(b)?(a):(b))
#endif
#ifndef MAX
#define MAX(a,b)            ((a)>(b)?(a):(b))
#endif
#define CLAMP(x,a,b)        MAX(a,MIN(x,b))
#define INRANGE(x,a,b)      ((x) >= (a) && (x) <= (b))

#ifdef OWF_ON_KHRPLATFORM
typedef void*               OWF_MUTEX;
typedef void*               OWF_SEMAPHORE;
#endif

#ifdef OWF_ON_KAL
typedef kal_semid           OWF_MUTEX;
typedef kal_semid           OWF_SEMAPHORE;
#endif

typedef struct OWF_NODE_
{
    void*                   data;
    struct OWF_NODE_*       next;
} OWF_NODE;

typedef OWFint (*NODECMPFUNC)(void*, void*);
typedef OWFint (*NODEITERFUNC)(void*, void*);

typedef OWFHandle           OWFNativeStreamType;
typedef OWFint              OWFNativeStreamBuffer;

/*!
 *  Events emitted by native streams.
 */
typedef enum
{
    OWF_STREAM_UPDATED = 0
} OWFNativeStreamEvent;

#define ALPHA_MASK          0xFF000000
#define RED_MASK            0xFF0000
#define GREEN_MASK          0xFF00
#define BLUE_MASK           0xFF

/*! Native stream callback function type */
typedef void (*OWFStreamCallback)( OWFNativeStreamType,
                                   OWFNativeStreamEvent,
                                   void* );

typedef struct
{
    OWFStreamCallback       callback;
    void*                   data;
} OWFStreamCallbackData;

#define OWF_RESERVED_BAD_SCREEN_NUMBER (-1)  

#ifdef __cplusplus
}
#endif

#endif /* __OWFTYPES_H__ */
