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
/*! \ingroup wfc
 *  \file wfcplatform.h
 *
 *  \brief Platform specific type definitions
 */
#ifndef _WFCPLATFORM_H_
#define _WFCPLATFORM_H_

/******************************************************************************
 * local option definitions
 ******************************************************************************/
/**
 *  \def WFC_ON_KHRPLATFORM
 *  If WFC_ON_KHRPLATFORM is defined, WFC definitions are defined based on 
 *  khrplatform.h. This is mutual exclusive to WFC_ON_KAL.
 */
//#define WFC_ON_KHRPLATFORM

/**
 *  \def WFC_ON_KAL
 *  If WFC_ON_KAL is defined, WFC definitions are defined based on MTK KAL. 
 *  This is mutual exclusive to WFC_ON_KHRPLATFORM.
 */
#define WFC_ON_KAL

/******************************************************************************
 * include directives
 ******************************************************************************/
#ifdef WFC_ON_KHRPLATFORM
#include <KHR/khrplatform.h>
#endif

#include <egl.h>

/*
 * Directly replace khrplatform.h with kal_release.h
 */
#ifdef WFC_ON_KAL
#include "kal_release.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * macro definitions
 ******************************************************************************/
#ifdef WFC_ON_KHRPLATFORM
#ifndef WFC_API_CALL
#define WFC_API_CALL KHRONOS_APICALL
#endif
#ifndef WFC_APIENTRY
#define WFC_APIENTRY KHRONOS_APIENTRY
#endif
#ifndef WFC_APIEXIT
#define WFC_APIEXIT KHRONOS_APIATTRIBUTES
#endif
#endif /* WFC_ON_KHRPLATFORM */

#ifdef WFC_ON_KAL
#ifndef WFC_API_CALL
#define WFC_API_CALL 
#endif
#ifndef WFC_APIENTRY
#define WFC_APIENTRY 
#endif
#ifndef WFC_APIEXIT
#define WFC_APIEXIT 
#endif
#endif /* WFC_ON_KAL */

/**
 *  \todo Screen number mapping needs to be customizable and moved to custom 
 *        folder. This is only a temp solution.
 */
#define WFC_SCREEN_LCD_0          (0)
#define WFC_SCREEN_LCD_1          (1)
#ifndef WFC_DEFAULT_SCREEN_NUMBER
#define WFC_DEFAULT_SCREEN_NUMBER WFC_SCREEN_LCD_0
#endif

#ifdef WFC_ON_KHRPLATFORM
typedef khronos_int32_t     WFCint;
typedef khronos_float_t     WFCfloat;
typedef khronos_uint32_t    WFCbitfield;
typedef khronos_uint32_t    WFCHandle;
#endif /* WFC_ON_KHRPLATFORM */

#ifdef WFC_ON_KAL
typedef kal_int32           WFCint;
typedef kal_uint32          WFCuint;
typedef kal_uint32          WFCfloat; /**< WFCfloat is undefined in MTK platform. */
typedef kal_uint32          WFCbitfield;
typedef kal_uint32          WFCHandle;
#endif /* WFC_ON_KAL */

typedef EGLDisplay          WFCEGLDisplay;
typedef void*               WFCEGLSync;   /* An opaque handle to an EGLSyncKHR */
typedef WFCHandle           WFCNativeStreamType;

#ifdef __cplusplus
}
#endif

#endif /* _WFCPLATFORM_H_ */
