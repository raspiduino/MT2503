/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    egladapt_int.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   EGL adaption layer (for consistent EGL interface of MoDIS and TARGET)
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __EGLADAPT_INT_H__
#define __EGLADAPT_INT_H__

/// #include <EGL/eglplatform.h>
#include "egldefinition.h"
#include "eglprototypes.h"

#ifdef __cplusplus
extern "C" {
#endif

EGLint eglGetError_imp();

EGLDisplay eglGetDisplay_imp(EGLNativeDisplayType display_id);

EGLBoolean eglInitialize_imp(EGLDisplay dpy, EGLint *major, EGLint *minor);

EGLBoolean eglTerminate_imp(EGLDisplay dpy);

const char *eglQueryString_imp(EGLDisplay dpy, EGLint name);

EGLBoolean eglGetConfigs_imp(EGLDisplay dpy, EGLConfig *configs,
                             EGLint config_size, EGLint *num_config);

EGLBoolean eglChooseConfig_imp(EGLDisplay dpy, const EGLint *attrib_list,
                               EGLConfig *configs, EGLint config_size, EGLint *num_config);

EGLBoolean eglGetConfigAttrib_imp(EGLDisplay dpy, EGLConfig config,
                                  EGLint attribute, EGLint *value);

EGLSurface eglCreateWindowSurface_imp(EGLDisplay dpy, EGLConfig config,
                                      EGLNativeWindowType win, const EGLint *attrib_list);

EGLSurface eglCreatePbufferSurface_imp(EGLDisplay dpy, EGLConfig config,
                                       const EGLint *attrib_list);

EGLSurface eglCreatePixmapSurface_imp(EGLDisplay dpy, EGLConfig config,
                                      EGLNativePixmapType pixmap,
                                      const EGLint *attrib_list);

EGLBoolean eglDestroySurface_imp(EGLDisplay dpy, EGLSurface surface);

EGLBoolean eglQuerySurface_imp(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value);

EGLBoolean eglBindAPI_imp(EGLenum api);

EGLenum eglQueryAPI_imp(void);

EGLBoolean eglWaitClient_imp(void);

EGLBoolean eglReleaseThread_imp(void);

EGLSurface eglCreatePbufferFromClientBuffer_imp(EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer,
                                                EGLConfig config, const EGLint *attrib_list);

EGLBoolean eglSurfaceAttrib_imp(EGLDisplay dpy, EGLSurface surface,
                                EGLint attribute, EGLint value);

EGLBoolean eglBindTexImage_imp(EGLDisplay dpy, EGLSurface surface, EGLint buffer);

EGLBoolean eglReleaseTexImage_imp(EGLDisplay dpy, EGLSurface surface, EGLint buffer);

EGLBoolean eglSwapInterval_imp(EGLDisplay dpy, EGLint interval);

EGLContext eglCreateContext_imp(EGLDisplay dpy, EGLConfig config,
                                EGLContext share_context, const EGLint *attrib_list);

EGLBoolean eglDestroyContext_imp(EGLDisplay dpy, EGLContext ctx);

EGLBoolean eglMakeCurrent_imp(EGLDisplay dpy, EGLSurface draw,
                              EGLSurface read, EGLContext ctx);

EGLContext eglGetCurrentContext_imp(void);

EGLSurface eglGetCurrentSurface_imp(EGLint readdraw);

EGLDisplay eglGetCurrentDisplay_imp(void);

EGLBoolean eglQueryContext_imp(EGLDisplay dpy, EGLContext ctx,
                               EGLint attribute, EGLint *value);

EGLBoolean eglWaitGL_imp(void);

EGLBoolean eglWaitNative_imp(EGLint engine);

EGLBoolean eglSwapBuffers_imp(EGLDisplay dpy, EGLSurface surface);

EGLBoolean eglCopyBuffers_imp(EGLDisplay dpy, EGLSurface surface,
                              EGLNativePixmapType target);

void *eglGetFrameBuffer_imp(EGLDisplay dpy, EGLSurface surface, 
                            unsigned int *width, unsigned int *height, 
                            unsigned int *size);

void eglHookFrameCompleteCallBack_imp(EGLDisplay dpy, EGLSurface surface,
                            frame_complete_callback cb_func, void *param);
              
void eglEnableFrameSynchronization_imp(EGLDisplay display, EGLSurface surface);
              
/// macro redefinition for EGL APIs for MoDis environment
#define eglGetError() \
        eglGetError_imp()

#define eglGetDisplay(display_id)  \
        eglGetDisplay_imp(display_id)

#define eglInitialize(dpy, major, minor) \
        eglInitialize_imp(dpy, major, minor)

#define eglTerminate(dpy)   \
        eglTerminate_imp(dpy)

#define eglQueryString(dpy, name) \
        eglQueryString_imp(dpy, name)

#define eglGetConfigs(dpy, configs, config_size, num_config)  \
        eglGetConfigs_imp(dpy, configs, config_size, num_config)

#define eglChooseConfig(dpy, attrib_list, configs, config_size, num_config) \
        eglChooseConfig_imp(dpy, attrib_list, configs, config_size, num_config)

#define eglGetConfigAttrib(dpy, config, attribute, value) \
        eglGetConfigAttrib_imp(dpy, config, attribute, value)

#define eglCreateWindowSurface(dpy, config, win, attrib_list)     \
        eglCreateWindowSurface_imp(dpy, config, win, attrib_list)

#define eglCreatePbufferSurface(dpy, config, attrib_list) \
        eglCreatePbufferSurface_imp(dpy, config, attrib_list)

#define eglCreatePixmapSurface(dpy, config, pixmap, attrib_list) \
        eglCreatePixmapSurface_imp(dpy, config, pixmap, attrib_list)

#define eglDestroySurface(dpy, surface) \
        eglDestroySurface_imp(dpy, surface)

#define eglQuerySurface(dpy, surface, attribute, value) \
        eglQuerySurface_imp(dpy, surface, attribute, value)

#define eglBindAPI(api)   \
        eglBindAPI_imp(api)

#define eglWaitClient(void)    \
        eglWaitClient_imp(void)

#define eglReleaseThread(void)  \
        eglReleaseThread_imp(void)

#define eglCreatePbufferFromClientBuffer(dpy, buftype, buffer, config, attrib_list) \
        eglCreatePbufferFromClientBuffer_imp(dpy, buftype, buffer, config, attrib_list)

#define eglSurfaceAttrib(dpy, surface, attribute, value) \
        eglSurfaceAttrib_imp(dpy, surface, attribute, value)

#define eglBindTexImage(dpy, surface, buffer) \
        eglBindTexImage_imp(dpy, surface, buffer)

#define eglReleaseTexImage(dpy, surface, buffer)\
        eglReleaseTexImage_imp(dpy, surface, buffer)

#define eglSwapInterval(dpy, interval) \
        eglSwapInterval_imp(dpy, interval)

#define eglCreateContext(dpy, config, share_context, attrib_list) \
        eglCreateContext_imp(dpy, config, share_context, attrib_list)

#define eglDestroyContext(dpy, ctx)\
        eglDestroyContext_imp(dpy, ctx)

#define eglMakeCurrent(dpy, draw, read, ctx) \
        eglMakeCurrent_imp(dpy, draw, read, ctx)

#define eglGetCurrentContext(void)  \
        eglGetCurrentContext_imp(void)

#define eglGetCurrentSurface(readdraw)\
        eglGetCurrentSurface_imp(readdraw)

#define eglGetCurrentDisplay(void)\
        eglGetCurrentDisplay_imp(void)

#define eglQueryContext(dpy, ctx, attribute, value)\
        eglQueryContext_imp(dpy, ctx, attribute, value)

#define eglWaitGL(void)\
        eglWaitGL_imp(void)

#define eglWaitNative(engine)\
        eglWaitNative_imp(engine)

#define eglSwapBuffers(dpy, surface)\
        eglSwapBuffers_imp(dpy, surface)

#define eglCopyBuffers(dpy, surface, target)\
        eglCopyBuffers_imp(dpy, surface, target)


#define eglGetFrameBuffer(dpy, surface, width, height, size)\
        eglGetFrameBuffer_imp(dpy, surface, width, height, size)

#define eglQueryFrameBufferInfo(dpy, surface, width, height, size, index)\
        eglQueryFrameBufferInfo_imp(dpy, surface, width, height, size, index)
        
#define eglHookFrameCompleteCallBack(dpy, surface, cb_func, param)      \
        eglHookFrameCompleteCallBack_imp(dpy, surface, cb_func, param)

#define eglEnableFrameSynchronization(display, surface) \
        eglEnableFrameSynchronization_imp(display, surface)

#ifdef __cplusplus
}
#endif


#endif /*__EGLADAPT_INT_H__*/
