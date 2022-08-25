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

/*! \ingroup wfd
 *  \file wfdplatform.h
 *
 *  \brief Platform specific type definitions
 */


#ifndef _WFDPLATFORM_H_
#define _WFDPLATFORM_H_

/******************************************************************************
 * local option definitions
 ******************************************************************************/
/**
 *  \def WFD_ON_KHRPLATFORM
 *  If WFD_ON_KHRPLATFORM is defined, WFD definitions are defined based on 
 *  khrplatform.h. This is mutual exclusive to WFD_ON_KAL.
 */
//#define WFD_ON_KHRPLATFORM

/**
 *  \def WFD_ON_KAL
 *  If WFD_ON_KAL is defined, WFD definitions are defined based on MTK KAL. 
 *  This is mutual exclusive to WFD_ON_KHRPLATFORM.
 */
#define WFD_ON_KAL

/******************************************************************************
 * include directives
 ******************************************************************************/
#ifdef WFD_ON_KHRPLATFORM
#include <KHR/khrplatform.h>
#endif

#ifdef WFD_ON_KAL
#include "kal_release.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef WFD_ON_KHRPLATFORM
#ifndef WFD_API_CALL
#define WFD_API_CALL KHRONOS_APICALL
#endif

#ifndef WFD_APIENTRY
#define WFD_APIENTRY KHRONOS_APIENTRY
#endif

#ifndef WFD_APIEXIT
#define WFD_APIEXIT KHRONOS_APIATTRIBUTES
#endif

typedef khronos_uint8_t             WFDuint8;
typedef khronos_int32_t             WFDint;
typedef khronos_uint32_t            WFDuint;
typedef khronos_float_t             WFDfloat;
typedef khronos_uint32_t            WFDbitfield;
typedef khronos_uint32_t            WFDHandle;
typedef khronos_utime_nanoseconds_t WFDtime;
#endif /* WFD_ON_KHRPLATFORM */

#ifdef WFD_ON_KAL
#ifndef WFD_API_CALL
#define WFD_API_CALL 
#endif

#ifndef WFD_APIENTRY
#define WFD_APIENTRY 
#endif

#ifndef WFD_APIEXIT
#define WFD_APIEXIT 
#endif

typedef kal_uint8     WFDuint8;
typedef kal_int32     WFDint;
typedef kal_uint32    WFDuint;
typedef kal_uint32    WFDfloat; /**< WFDfloat is undefined and not supported in MTK implementation. */
typedef kal_uint32    WFDbitfield;
typedef kal_uint32    WFDHandle;
typedef kal_uint64    WFDtime; /**< \todo Check if we really need 64-bit time stamp. */
#endif /* WFD_ON_KAL */


#define WFD_FOREVER (0xFFFFFFFFFFFFFFFF)

typedef void*         WFDEGLDisplay; /* An opaque handle to an EGLDisplay */
typedef void*         WFDEGLSync; /* An opaque handle to an EGLSyncKHR */
typedef void*         WFDEGLImage; /* An opaque handle to an EGLImage */
typedef WFDHandle     WFDNativeStreamType;

#define WFD_INVALID_SYNC ((WFDEGLSync)0)

/**
 *  \todo Screen number mapping needs to be customizable and moved to custom 
 *        folder. This is only a temp solution.
 */
#define WFD_SCREEN_LCD_0          (0)
#define WFD_SCREEN_LCD_1          (1)
#ifndef WFD_DEFAULT_SCREEN_NUMBER
#define WFD_DEFAULT_SCREEN_NUMBER WFD_SCREEN_LCD_0
#endif

#ifdef __cplusplus
}
#endif
#endif /* _WFDPLATFORM_H_ */

