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
 *    avk_graphics3d_egl_test.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __MAUI_SDK_TEST__

#include "drv_features_opengles.h"
#if defined(__DRV_MALI400MP_OPENGLES_SUPPORT__)

#ifdef __cplusplus
extern "C"
{
#endif

#include "app_mem_med.h"
#include <EGL/egl.h>
#include <stdlib.h>
#include "gpu_memory_if.h"

#define TEST_DEFAULT_EGL_WIDTH  16
#define TEST_DEFAULT_EGL_HEIGHT 16

#define INVALID_NATIVE_DPY_VALUE ((EGLNativeDisplayType)-1)
#define BAD_NATIVE_DPY_VALUE     ((EGLNativeDisplayType)-2)

#define AVK_CACHED_BUFFER_SIZE            (256*1024)
#define AVK_NONCACHED_BUFFER_SIZE         (1*768*1024)
#define AVK_EGL3D_TEST_CACHED_BUFFER_SIZE (1*1024)

#define MALLOC _avk_gfx3d_test_malloc
#define FREE   _avk_gfx3d_test_free

#if defined(__USE_DEDICATE_MEMORY__)

#pragma arm section zidata = "DYNAMICCACHEABLEZI_C"
__align(4) kal_uint8 avk_gl_working_buffer[AVK_CACHED_BUFFER_SIZE + AVK_NONCACHED_BUFFER_SIZE];
__align(4) kal_uint8 avk_test_working_buffer[AVK_EGL3D_TEST_CACHED_BUFFER_SIZE];
#pragma arm section zidata, rwdata

#else
__align(4) kal_uint8 *avk_gl_working_buffer   = NULL;
__align(4) kal_uint8 *avk_test_working_buffer = NULL;
#endif

int avk_egl_memory_initialize(void);
int avk_egl_memory_deinitialize(void);


#define ASSERT_EGL_EQUAL(input, expected, str)     do{                         \
                                                       if(input != expected)   \
                                                       {                       \
                                                         ASSERT(0);            \
                                                       }                       \
                                                   } while(0)

#define ASSERT_EGL_NOT_EQUAL(input, expected, str) do{                         \
                                                       if(input == expected)   \
                                                       {                       \
                                                         ASSERT(0);            \
                                                       }                       \
                                                   } while(0)

#define ASSERT_EGL_ERROR(input, expected, str)                                 \
                                                   do{                         \
                                                       if(input != expected)   \
                                                       {                       \
                                                         ASSERT(0);            \
                                                       }                       \
                                                   } while(0)
typedef enum egl_helper_dpy_flags
{
   EGL_HELPER_DPY_FLAG_INVALID_DPY = 0x1 /**< Return an invalid native display */
} egl_helper_dpy_flags;


KAL_ADM_ID avk_egl_test_adm_id; /// adm id for driver allocation
KAL_ADM_ID avk_gfx3d_test_adm_id; /// adm id for test case allocation

void *_avk_egl_test_malloc(unsigned int size, MEM_CACHED_TYPE_ENUM m_type, int alignment)
{
   void *buffer = NULL;

   if (CACHEABLE_MEM == m_type)
   {
       buffer = kal_adm_alloc_cacheable(avk_egl_test_adm_id, size, 0);
   }
   else
   {
       buffer = kal_adm_alloc_noncacheable(avk_egl_test_adm_id, size, 0);
   }

   if (NULL == buffer)
   {
      ASSERT(0);
   }
   return buffer;
}



void *_avk_egl_test_realloc(void *ptr, unsigned int size, MEM_CACHED_TYPE_ENUM m_type)
{
   void *buffer = NULL;

   buffer = kal_adm_realloc(avk_egl_test_adm_id, ptr, size);

   if (NULL == buffer)
   {
      ASSERT(0);
   }
   return buffer;
}



void _avk_egl_test_free(void *address, MEM_CACHED_TYPE_ENUM m_type)
{
   kal_adm_free(avk_egl_test_adm_id, address);
}


void avk_memory_allocator_init(void *mem, unsigned int size)
{
   avk_egl_test_adm_id = kal_adm_create(mem, size, NULL, KAL_FALSE);
}


void avk_test_memory_allocator_deinit(void)
{
   kal_status ret;
   ret = kal_adm_delete(avk_egl_test_adm_id);
   
   if (KAL_SUCCESS != ret)
   {
      AVK_LOG_FUN(kal_adm_delete, AVK_FAIL);
   }      
      
   avk_egl_test_adm_id = 0;
   if (NULL != avk_gl_working_buffer)
   {               
      applib_asm_free_anonymous(avk_gl_working_buffer);
      avk_gl_working_buffer = NULL;
   }
}


int avk_egl_memory_initialize(void)
{
    /// request memory source
    avk_gl_working_buffer = (kal_uint8 *)applib_asm_alloc_anonymous_nc((kal_uint32)(AVK_CACHED_BUFFER_SIZE + AVK_NONCACHED_BUFFER_SIZE));

    if (NULL == avk_gl_working_buffer)
    {
       return NULL;
    }

    avk_memory_allocator_init((void *)avk_gl_working_buffer, (AVK_CACHED_BUFFER_SIZE + AVK_NONCACHED_BUFFER_SIZE));
    glHookAllocatorFunctions(_avk_egl_test_malloc, _avk_egl_test_realloc, _avk_egl_test_free);
}


int avk_egl_memory_deinitialize(void)
{
   avk_test_memory_allocator_deinit();
}


///////////////////////////////////////////////////
int avk_gfx3d_memory_allocator_init()
{
   avk_test_working_buffer = (kal_uint8 *)applib_asm_alloc_anonymous((kal_uint32)AVK_EGL3D_TEST_CACHED_BUFFER_SIZE);

   if (NULL == avk_test_working_buffer)
   {
      return NULL;
   }

   avk_gfx3d_test_adm_id = kal_adm_create(avk_test_working_buffer, AVK_EGL3D_TEST_CACHED_BUFFER_SIZE, NULL, KAL_FALSE);
}


void avk_gfx3d_memory_allocator_deinit(void)
{
   kal_status ret;
   ret = kal_adm_delete(avk_gfx3d_test_adm_id);
   if (KAL_SUCCESS != ret)
   {
      AVK_LOG_FUN(kal_adm_delete, AVK_FAIL);
   }      
   
   avk_gfx3d_test_adm_id = 0;
   if (NULL != avk_test_working_buffer)
   {                  
      applib_asm_free_anonymous(avk_test_working_buffer);
      avk_test_working_buffer = NULL;
   }
}



void *_avk_gfx3d_test_malloc(unsigned int size)
{
   void *buffer = NULL;

   buffer = kal_adm_alloc_cacheable(avk_gfx3d_test_adm_id, size, 0);

   if (NULL == buffer)
   {
      ASSERT(0);
   }
   return buffer;
}


void _avk_gfx3d_test_free(void *address)
{
   kal_adm_free(avk_gfx3d_test_adm_id, address);
}
///////////////////////////////////////////


EGLBoolean egl_helper_create_window(unsigned int width, unsigned int height, EGLNativeWindowType *win )
{
   EGLBoolean success = EGL_FALSE;
   fbdev_window *fbwin;
   fbwin = (fbdev_window*)MALLOC(sizeof( fbdev_window ));

   if ( NULL != fbwin )
   {
      fbwin->width = width;
      fbwin->height = height;
      success = EGL_TRUE;
   }

   *win = fbwin;
   return success;
}


EGLBoolean egl_helper_invalidate_window( EGLNativeWindowType win )
{
   win->width = 0;
   win->height = 0;

   return EGL_TRUE;
}


EGLBoolean egl_helper_destroy_window( EGLNativeWindowType win )
{
   if ( NULL != win )
   {
      FREE( win);
   }

   return EGL_TRUE;
}


EGLBoolean egl_helper_get_native_display(EGLNativeDisplayType *ret_native_dpy, egl_helper_dpy_flags flags )
{
   EGLNativeDisplayType nativedpy;
   ASSERT( ret_native_dpy );

   if ( 0 != (flags & EGL_HELPER_DPY_FLAG_INVALID_DPY) )
   {
      nativedpy = INVALID_NATIVE_DPY_VALUE;
   }
   else
   {
      nativedpy = 1;
   }

   *ret_native_dpy = nativedpy;

   return EGL_TRUE;
}


void egl_helper_release_native_display(EGLNativeDisplayType *inout_native_dpy )
{
   *inout_native_dpy = (EGLNativeDisplayType)BAD_NATIVE_DPY_VALUE;
}


EGLBoolean egl_helper_prepare_display(EGLDisplay *display, EGLBoolean initialize, EGLNativeDisplayType *retNativeDpy )
{
   EGLBoolean status;
   EGLNativeDisplayType nativedpy;
   EGLDisplay egl_display;
   EGLenum i;

   *display = EGL_NO_DISPLAY;

   status = egl_helper_get_native_display( &nativedpy, (egl_helper_dpy_flags)0 );
   if ( EGL_FALSE == status )
   {
      ASSERT_EGL_EQUAL( status, EGL_TRUE, "egl_helper_get_native_display failed" );
      return status;
   }

   egl_display = eglGetDisplay( nativedpy );

   i = eglGetError();

   if (i != EGL_SUCCESS )
   {
      AVK_LOG_FUN(eglGetDisplay, AVK_FAIL);
      ASSERT_EGL_ERROR( i, EGL_SUCCESS, "eglGetDisplay set an error" );
      egl_helper_release_native_display(&nativedpy );
      return EGL_FALSE;
   }

   AVK_LOG_FUN(eglGetDisplay, AVK_PASS);

   if ( EGL_NO_DISPLAY == egl_display )
   {
      ASSERT_EGL_NOT_EQUAL( egl_display, EGL_NO_DISPLAY, "eglGetDisplay returned EGL_NO_DISPLAY" );

      egl_helper_release_native_display(&nativedpy );
      return EGL_FALSE;
   }

   if ( EGL_TRUE == initialize )
   {
      status = eglInitialize( egl_display, NULL, NULL );

      if (status == EGL_TRUE)
      {
         AVK_LOG_FUN(eglInitialize, AVK_PASS);
      }
      else
      {
         AVK_LOG_FUN(eglInitialize, AVK_FAIL);
      }
      AVK_LOG_EX(EGL_SUCCESS == eglGetError());

      /// ASSERT_EGL_EQUAL( status, EGL_TRUE, "eglInitialize failed" );
      /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglInitialize sat an error" );

      if ( EGL_FALSE == status )
      {
         eglTerminate( egl_display );
         AVK_LOG_FUN(eglTerminate, AVK_PASS);
         egl_helper_release_native_display(&nativedpy );
         return EGL_FALSE;
      }
   }

   *display = egl_display;
    *retNativeDpy = nativedpy;

   return EGL_TRUE;
}


void egl_helper_terminate_display( EGLDisplay dpy, EGLNativeDisplayType *inoutNativeDpy )
{
   EGLBoolean status;

   status = eglTerminate( dpy );

   if (status == EGL_TRUE)
   {
      AVK_LOG_FUN(eglTerminate, AVK_PASS);
   }
   else
   {
      AVK_LOG_FUN(eglTerminate, AVK_FAIL);
   }
   AVK_LOG_EX(EGL_SUCCESS == eglGetError());

   /// ASSERT_EGL_EQUAL( status, EGL_TRUE, "eglTerminate failed" );
   /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglTerminate sat an error" );

   egl_helper_release_native_display(inoutNativeDpy );
}


EGLConfig egl_helper_get_config_exact(EGLDisplay dpy, EGLint renderable_type, EGLint surface_type, EGLint red_size, EGLint green_size, EGLint blue_size, EGLint alpha_size, EGLNativePixmapType* pixmap_match )
{
   EGLint num_config = 0;
   EGLint max_config = 30;
   EGLConfig *configs = NULL;
   EGLConfig match_config = (EGLConfig)NULL;
   EGLint parameter[7*2+1];
   EGLint i = 0, j = 0;
   EGLBoolean status;

   configs = (EGLConfig *)MALLOC(sizeof( EGLConfig ) * max_config);
   ASSERT( configs );

   if ( NULL == configs ) return match_config;

   if ( EGL_DONT_CARE != renderable_type )
   {
      parameter[i++] = EGL_RENDERABLE_TYPE;
      parameter[i++] = renderable_type;
   }

   if ( EGL_DONT_CARE != surface_type )
   {
      parameter[i++] = EGL_SURFACE_TYPE;
      parameter[i++] = surface_type;
   }

   if ( EGL_DONT_CARE != red_size )
   {
      parameter[i++] = EGL_RED_SIZE;
      parameter[i++] = red_size;
   }

   if ( EGL_DONT_CARE != green_size )
   {
      parameter[i++] = EGL_GREEN_SIZE;
      parameter[i++] = green_size;
   }

   if ( EGL_DONT_CARE != blue_size )
   {
      parameter[i++] = EGL_BLUE_SIZE;
      parameter[i++] = blue_size;
   }

   if ( EGL_DONT_CARE != alpha_size )
   {
      parameter[i++] = EGL_ALPHA_SIZE;
      parameter[i++] = alpha_size;
   }

   if ( NULL != pixmap_match )
   {
      parameter[i++] = EGL_MATCH_NATIVE_PIXMAP;
      parameter[i++] = (EGLint)*pixmap_match;
   }

   parameter[i++] = EGL_NONE;

   status = eglChooseConfig( dpy, parameter, configs, max_config, &num_config );
   ASSERT_EGL_EQUAL( status, EGL_TRUE, "eglChooseConfig failed" );
   ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglChooseConfig set an error" );

   /* find a config matching exactly */
   for ( j=0; j<num_config; j++ )
   {
      EGLint value;
      EGLConfig config;
      config = configs[j];

      if ( EGL_DONT_CARE != red_size )
      {
         status = eglGetConfigAttrib( dpy, config, EGL_RED_SIZE, &value);
         ASSERT_EGL_EQUAL( status, EGL_TRUE, "eglGetConfigAttrib failed" );
         ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglGetConfigAttrib set an error" );
         if ( value != red_size ) continue;
      }

      if ( EGL_DONT_CARE != green_size )
      {
         status = eglGetConfigAttrib( dpy, config, EGL_GREEN_SIZE, &value );
         ASSERT_EGL_EQUAL( status, EGL_TRUE, "eglGetConfigAttrib failed" );
         ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglGetConfigAttrib set an error" );
         if ( value != green_size ) continue;
      }

      if ( EGL_DONT_CARE != blue_size )
      {
         status = eglGetConfigAttrib( dpy, config, EGL_BLUE_SIZE, &value );
         ASSERT_EGL_EQUAL( status, EGL_TRUE, "eglGetConfigAttrib failed" );
         ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglGetConfigAttrib set an error" );

         if ( value != blue_size ) continue;
      }

      if ( EGL_DONT_CARE != alpha_size )
      {
         status = eglGetConfigAttrib( dpy, config, EGL_ALPHA_SIZE, &value );
         ASSERT_EGL_EQUAL( status, EGL_TRUE, "eglGetConfigAttrib failed" );
         ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglGetConfigAttrib set an error" );
         if ( value != alpha_size ) continue;
      }
      match_config = config;
      break;
   }

   FREE( configs);
   return match_config;
}


EGLBoolean egl_test_get_window_config(EGLDisplay dpy, EGLint renderable_type, EGLConfig* out_config )
{
   EGLConfig config;

   config = egl_helper_get_config_exact(
               dpy,
               renderable_type,
               EGL_WINDOW_BIT,
               (EGLint)5,
               (EGLint)6,
               (EGLint)5,
               (EGLint)0,
               NULL /* no pixmap matching */
   );

   if ( (EGLConfig)NULL == config )
      return EGL_FALSE;

   *out_config = config;
   return EGL_TRUE;
}



static void _avk_eglGetError001( void )
{

   /* Case 1: error state should be EGL_SUCCESS to start with */
   /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglGetError returned wrong error" );
   AVK_LOG_EX(EGL_SUCCESS == eglGetError());
}


static void _avk_eglGetError002( void )
{
   EGLBoolean status;
   EGLDisplay dpy;

   /* Case 2: error state should be EGL_SUCCESS after releasing a thread */
   /// ASSERT_EGL_EQUAL( eglReleaseThread(), EGL_TRUE, "Thread could not be released" );
   /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglGetError returned wrong error" );
   AVK_LOG_EX(EGL_TRUE == eglReleaseThread());
   AVK_LOG_EX(EGL_SUCCESS == eglGetError());
}


static void _avk_eglMakeCurrent(void)
{
   EGLDisplay dpy_valid, dpy_invalid = (EGLDisplay)-1;
   EGLSurface surface = EGL_NO_SURFACE;
   EGLSurface surface_draw = EGL_NO_SURFACE;
   EGLint config_attribute_gles[] = { EGL_CONFORMANT, 0, EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT|EGL_OPENGL_ES_BIT, EGL_SURFACE_TYPE, EGL_WINDOW_BIT, EGL_NONE };
   EGLint context_attribute_gles[] = { EGL_CONTEXT_CLIENT_VERSION, MALI_EGL_GLES_MAJOR_VERSION, EGL_NONE };

   EGLConfig config_gles = (EGLConfig)NULL;
   EGLConfig conf1 = (EGLConfig)NULL, conf2 = (EGLConfig)NULL; /* uncompatible configs */
   EGLConfig curr_config = (EGLConfig)NULL;
   EGLConfig *configs_gles = NULL;
   EGLContext context = EGL_NO_CONTEXT;
   EGLContext context_gles = EGL_NO_CONTEXT;

   EGLBoolean status;
   EGLint num_config_gles = 0;
   EGLint i, j;
   EGLint depth_size, stencil_size;
   EGLNativeWindowType win, win2;
   EGLNativeDisplayType native_dpy;

   if (!avk_gfx3d_memory_allocator_init())
   {
      AVK_LOG_FUN(avk_gfx3d_memory_allocator_init, AVK_FAIL);
      return;
   }

   if (!avk_egl_memory_initialize())
   {
      AVK_LOG_FUN(avk_egl_memory_initialize, AVK_FAIL);
      return;
   }

   configs_gles = (EGLConfig *)MALLOC( sizeof( EGLConfig )*10);
   ASSERT( configs_gles );

   if (NULL == configs_gles)
   {
      if ( NULL != configs_gles )
      {
         FREE( configs_gles);
      }
      return;
   }

   status = egl_helper_create_window(TEST_DEFAULT_EGL_WIDTH, TEST_DEFAULT_EGL_HEIGHT, &win );

   ASSERT_EGL_EQUAL( status, EGL_TRUE, "egl_helper_create_window failed" );
   if ( EGL_TRUE != status )
   {
      FREE( configs_gles);
      status = egl_helper_destroy_window( win );
      ASSERT_EGL_EQUAL( status, EGL_TRUE, "egl_helper_destroy_window failed" );
      return;
   }

   status = egl_helper_create_window(TEST_DEFAULT_EGL_WIDTH, TEST_DEFAULT_EGL_HEIGHT, &win2 );
   ASSERT_EGL_EQUAL( status, EGL_TRUE, "egl_helper_create_window failed" );
   if ( EGL_TRUE != status )
   {
      FREE( configs_gles);
      status = egl_helper_destroy_window( win );
      ASSERT_EGL_EQUAL( status, EGL_TRUE, "egl_helper_destroy_window failed" );
      status = egl_helper_destroy_window( win2 );
      ASSERT_EGL_EQUAL( status, EGL_TRUE, "egl_helper_destroy_window2 failed" );
      return;
   }

   ///-----------------------------------------------------------------------------------------
   /* Case 1: Call eglMakeCurrent with invalid display */
   status = eglMakeCurrent( dpy_invalid, surface, surface, context );

   if (status == EGL_FALSE)
   {
      AVK_LOG_FUN(eglMakeCurrent, AVK_PASS);
   }
   else
   {
      AVK_LOG_FUN(eglMakeCurrent, AVK_FAIL);
   }
   AVK_LOG_EX(EGL_BAD_DISPLAY == eglGetError());

   AVK_LOG_FUN(_avk_eglMakeCurrent_CASE001_BAD_DISPLAY, AVK_PASS);
   /// ASSERT_EGL_EQUAL( status, EGL_FALSE, "eglMakeCurrent succeeded for invalid display" );
   /// ASSERT_EGL_ERROR( eglGetError(), EGL_BAD_DISPLAY, "eglMakeCurrent did not set EGL_BAD_DISPLAY" );

   /* Case 2: Call eglMakeCurrent with invalid draw surface */
   status = egl_helper_prepare_display( &dpy_valid, EGL_TRUE, &native_dpy );
   if ( EGL_FALSE == status )
   {
      FREE( configs_gles);
      status = egl_helper_destroy_window( win );
      ASSERT_EGL_EQUAL( status, EGL_TRUE, "egl_helper_destroy_window win1 failed" );
      status = egl_helper_destroy_window( win2 );
      ASSERT_EGL_EQUAL( status, EGL_TRUE, "egl_helper_destroy_window win2 failed" );
      return;
   }

   status = eglMakeCurrent( dpy_valid, (EGLSurface)-1, (EGLSurface)-1, context );

   if (status == EGL_FALSE)
   {
      AVK_LOG_FUN(eglMakeCurrent, AVK_PASS);
   }
   else
   {
      AVK_LOG_FUN(eglMakeCurrent, AVK_FAIL);
   }
   AVK_LOG_EX(EGL_BAD_SURFACE == eglGetError());
   AVK_LOG_FUN(_avk_eglMakeCurrent_CASE002_BAD_SURFACE, AVK_PASS);
   /// ASSERT_EGL_EQUAL( status, EGL_FALSE, "eglMakeCurrent succeeded for invalid draw surface" );
   /// ASSERT_EGL_ERROR( eglGetError(), EGL_BAD_SURFACE, "eglMakeCurrent did not set EGL_BAD_SURFACE" );

   /* Case 3: Call eglMakeCurrent with invalid read surface */
   /* create a valid draw surface */
   status = egl_test_get_window_config( dpy_valid, EGL_OPENGL_ES2_BIT|EGL_OPENGL_ES_BIT, &config_gles );

   if ( (EGLConfig)NULL != config_gles )
   {
      eglBindAPI( EGL_OPENGL_ES_API );
      AVK_LOG_FUN(eglBindAPI, AVK_PASS);

      surface_draw = eglCreateWindowSurface( dpy_valid, config_gles, win, NULL );

      if (surface_draw != EGL_NO_SURFACE)
      {
         AVK_LOG_FUN(eglMakeCurrent, AVK_PASS);
      }
      else
      {
         AVK_LOG_FUN(eglMakeCurrent, AVK_FAIL);
      }
      AVK_LOG_EX(EGL_SUCCESS == eglGetError());
      AVK_LOG_FUN(_avk_eglMakeCurrent_CASE003_1_VALID_SURFACE_DISPLAY, AVK_PASS);

      /// ASSERT_EGL_NOT_EQUAL( EGL_NO_SURFACE, surface_draw, "eglCreateWindowSurface failed" );
      /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglCreateWindowSurface sat an error" );

      if ( EGL_NO_SURFACE != surface_draw )
      {
         status = eglMakeCurrent( dpy_valid, surface_draw, (EGLSurface)-1, context );

         if (status == EGL_FALSE)
         {
            AVK_LOG_FUN(eglMakeCurrent, AVK_PASS);
         }
         else
         {
            AVK_LOG_FUN(eglMakeCurrent, AVK_FAIL);
         }
         AVK_LOG_EX(EGL_BAD_SURFACE == eglGetError());
         AVK_LOG_FUN(_avk_eglMakeCurrent_CASE003_2_BAD_SURFACE, AVK_PASS);
         /// ASSERT_EGL_EQUAL( status, EGL_FALSE, "eglMakeCurrent succeeded for invalid read surface" );
         /// ASSERT_EGL_ERROR( eglGetError(), EGL_BAD_SURFACE, "eglMakeCurrent did not set EGL_BAD_SURFACE" );
      }
   }
   AVK_LOG_FUN(_avk_eglMakeCurrent_CASE003_3_INVALID_READ_SURFACE, AVK_PASS);

   /* Case 4: Call eglMakeCurrent with invalid context */
   if ( ((EGLConfig)NULL != config_gles) && (EGL_NO_SURFACE !=  surface_draw) )
   {
      status = eglMakeCurrent( dpy_valid, surface_draw, surface_draw, (EGLContext)-1 );

      if (status == EGL_FALSE)
      {
         AVK_LOG_FUN(eglMakeCurrent, AVK_PASS);
      }
      else
      {
         AVK_LOG_FUN(eglMakeCurrent, AVK_FAIL);
      }
      AVK_LOG_EX(EGL_BAD_CONTEXT == eglGetError());
      AVK_LOG_FUN(_avk_eglMakeCurrent_BAD_CONTEXT, AVK_PASS);
      /// ASSERT_EGL_EQUAL( status, EGL_FALSE, "eglMakeCurrent succeeded for invalid context" );
      /// ASSERT_EGL_ERROR( eglGetError(), EGL_BAD_CONTEXT, "eglMakeCurrent did not set EGL_BAD_CONTEXT" );
   }
   AVK_LOG_FUN(_avk_eglMakeCurrent_CASE004_INVALID_CONTEXT, AVK_PASS);

   /* Case 5: Call eglMakeCurrent with ctx=EGL_NO_CONTEXT and draw=read=EGL_NO_SURFACE */
   /* make a valid context and surface current */
   /* set it not be current any longer */
   status = eglMakeCurrent( dpy_valid, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT );

   if (status == EGL_TRUE)
   {
      AVK_LOG_FUN(eglMakeCurrent, AVK_PASS);
   }
   else
   {
      AVK_LOG_FUN(eglMakeCurrent, AVK_FAIL);
   }
   AVK_LOG_EX(EGL_SUCCESS == eglGetError());

   ASSERT_EGL_EQUAL( status, EGL_TRUE, "eglMakeCurrent failed setting context noncurrent" );
   ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglMakeCurrent sat an error" );

   if ( EGL_NO_SURFACE != surface_draw )
   {
      status = eglDestroySurface( dpy_valid, surface_draw );

      if (status == EGL_TRUE)
      {
         AVK_LOG_FUN(eglDestroySurface, AVK_PASS);
      }
      else
      {
         AVK_LOG_FUN(eglDestroySurface, AVK_FAIL);
      }
      AVK_LOG_EX(EGL_SUCCESS == eglGetError());

      ASSERT_EGL_EQUAL( EGL_TRUE, status, "eglDestroySurface failed deleting draw surface" );
      ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglDestroySurface sat an error" );
      surface_draw = EGL_NO_SURFACE;
   }
   AVK_LOG_FUN(_avk_eglMakeCurrent_CASE005_NO_CONTEXT_NO_SURFACE, AVK_PASS);

   /* Case 6: Surface config not compatible with context config (depth, stencil, api) */

   /* look up all GLES configs, look for two configs not having the same depth size */
   eglChooseConfig( dpy_valid, config_attribute_gles, configs_gles, 10, &num_config_gles );
   if ( num_config_gles > 0 ) eglGetConfigAttrib( dpy_valid, configs_gles[0], EGL_DEPTH_SIZE, &depth_size );

   AVK_LOG_FUN(eglChooseConfig, AVK_PASS);
   AVK_LOG_FUN(eglGetConfigAttrib, AVK_PASS);

   for ( i=0; i<num_config_gles; i++ )
   {
      EGLint value;
      eglGetConfigAttrib( dpy_valid, configs_gles[i], EGL_DEPTH_SIZE, &value );
      if ( value != depth_size )
      {
         conf1 = configs_gles[0];
         conf2 = configs_gles[i];
         break;
      }
   }

   if ( ((EGLConfig)NULL != conf1) && ((EGLConfig)NULL != conf2) )
   {
      eglBindAPI( EGL_OPENGL_ES_API );

      /* Create the context with conf1 */
      context = eglCreateContext( dpy_valid, conf1, EGL_NO_CONTEXT, context_attribute_gles );

      if (context == EGL_NO_CONTEXT)
      {
         AVK_LOG_FUN(eglCreateContext, AVK_FAIL);
      }
      else
      {
         AVK_LOG_FUN(eglCreateContext, AVK_PASS);
      }
      AVK_LOG_EX(EGL_SUCCESS == eglGetError());

      /// ASSERT_EGL_NOT_EQUAL( EGL_NO_CONTEXT, context, "eglCreateContext failed creating a context" );
      /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglCreateContext sat an error" );

      /* Create the surface with conf2 */
      surface = eglCreateWindowSurface( dpy_valid, conf2, win, NULL );

      if (surface == EGL_NO_SURFACE)
      {
         AVK_LOG_FUN(eglCreateWindowSurface, AVK_FAIL);
      }
      else
      {
         AVK_LOG_FUN(eglCreateWindowSurface, AVK_PASS);
      }
      AVK_LOG_EX(EGL_SUCCESS == eglGetError());

      /// ASSERT_EGL_NOT_EQUAL( EGL_NO_SURFACE, surface, "eglCreateWindowSurface failed" );
      /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglCreateWindowSurface sat an error" );

      if ( (EGL_NO_CONTEXT != context) && (EGL_NO_SURFACE != surface) )
      {
         status = eglMakeCurrent( dpy_valid, surface, surface, context );

         if (status == EGL_FALSE)
         {
            AVK_LOG_FUN(eglMakeCurrent, AVK_PASS);
         }
         else
         {
            AVK_LOG_FUN(eglMakeCurrent, AVK_FAIL);
         }

         AVK_LOG_EX(EGL_SUCCESS == eglGetError());
         /// ASSERT_EGL_EQUAL( status, EGL_FALSE, "eglMakeCurrent succeeded for mismatching configs" );
         /// ASSERT_EGL_ERROR( eglGetError(), EGL_BAD_MATCH, "eglMakeCurrent did not set EGL_BAD_MATCH" );
      }

      if ( EGL_NO_SURFACE != surface )
      {
         status = eglDestroySurface( dpy_valid, surface );

         if (status == EGL_TRUE)
         {
            AVK_LOG_FUN(eglDestroySurface, AVK_PASS);
         }
         else
         {
            AVK_LOG_FUN(eglDestroySurface, AVK_FAIL);
         }

         AVK_LOG_EX(EGL_SUCCESS == eglGetError());

         /// ASSERT_EGL_EQUAL( EGL_TRUE, status, "eglDestroySurface failed" );
         /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglDestroySurface sat an error" );
         surface = EGL_NO_SURFACE;
      }

      if ( EGL_NO_CONTEXT != context )
      {
         status = eglDestroyContext( dpy_valid, context );

         if (status == EGL_TRUE)
         {
            AVK_LOG_FUN(eglDestroyContext, AVK_PASS);
         }
         else
         {
            AVK_LOG_FUN(eglDestroyContext, AVK_FAIL);
         }

         AVK_LOG_EX(EGL_SUCCESS == eglGetError());

         /// ASSERT_EGL_EQUAL( EGL_TRUE, status, "eglDestroyContext failed" );
         /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglDestroyContext sat an error" );
         context = EGL_NO_CONTEXT;
      }
   }
   conf1 = (EGLConfig)NULL;
   conf2 = (EGLConfig)NULL;

   /* look for two configs not having the same stencil size */
   if ( num_config_gles > 0 ) eglGetConfigAttrib( dpy_valid, configs_gles[0], EGL_STENCIL_SIZE, &stencil_size );

   for ( i=0; i<num_config_gles; i++ )
   {
      EGLint value;
      eglGetConfigAttrib( dpy_valid, configs_gles[i], EGL_STENCIL_SIZE, &value );
      if ( value != stencil_size )
      {
         EGLint depth1, depth2;
         eglGetConfigAttrib( dpy_valid, configs_gles[i], EGL_DEPTH_SIZE, &depth1 );
         eglGetConfigAttrib( dpy_valid, configs_gles[0], EGL_DEPTH_SIZE, &depth2);
         if ( depth1 == depth2 )
         {
            conf1 = configs_gles[0];
            conf2 = configs_gles[i];
            break;
         }
      }
   }

   if ( ((EGLConfig)NULL != conf1) && ((EGLConfig)NULL != conf2) )
   {
      eglBindAPI( EGL_OPENGL_ES_API );

      /* Create the context with conf1 */
      context = eglCreateContext( dpy_valid, conf1, EGL_NO_CONTEXT, context_attribute_gles );

      if (context == EGL_NO_CONTEXT)
      {
         AVK_LOG_FUN(eglCreateContext, AVK_FAIL);
      }
      else
      {
         AVK_LOG_FUN(eglCreateContext, AVK_PASS);
      }

      AVK_LOG_EX(EGL_SUCCESS == eglGetError());

      /// ASSERT_EGL_NOT_EQUAL( EGL_NO_CONTEXT, context, "eglCreateContext failed creating a context" );
      /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglCreateContext sat an error" );

      /* Create the surface with conf2 */
      surface = eglCreateWindowSurface( dpy_valid, conf2, win, NULL );

      if (context == EGL_NO_CONTEXT)
      {
         AVK_LOG_FUN(eglCreateWindowSurface, AVK_FAIL);
      }
      else
      {
         AVK_LOG_FUN(eglCreateWindowSurface, AVK_PASS);
      }

      AVK_LOG_EX(EGL_SUCCESS == eglGetError());

      /// ASSERT_EGL_NOT_EQUAL( EGL_NO_SURFACE, surface, "eglCreateWindowSurface failed" );
      /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglCreateWindowSurface sat an error" );

      if ( (EGL_NO_CONTEXT != context) && (EGL_NO_SURFACE != surface) )
      {
         status = eglMakeCurrent( dpy_valid, surface, surface, context );

         if (status == EGL_FALSE)
         {
            AVK_LOG_FUN(eglMakeCurrent, AVK_PASS);
         }
         else
         {
            AVK_LOG_FUN(eglMakeCurrent, AVK_FAIL);
         }

         AVK_LOG_EX(EGL_BAD_MATCH == eglGetError());

         /// ASSERT_EGL_EQUAL( status, EGL_FALSE, "eglMakeCurrent succeeded for mismatching configs" );
         /// ASSERT_EGL_ERROR( eglGetError(), EGL_BAD_MATCH, "eglMakeCurrent did not set EGL_BAD_MATCH" );
      }

      if ( EGL_NO_SURFACE != surface )
      {
         status = eglDestroySurface( dpy_valid, surface );

         if (status == EGL_TRUE)
         {
            AVK_LOG_FUN(eglDestroySurface, AVK_PASS);
         }
         else
         {
            AVK_LOG_FUN(eglDestroySurface, AVK_FAIL);
         }

         AVK_LOG_EX(EGL_SUCCESS == eglGetError());

         /// ASSERT_EGL_EQUAL( EGL_TRUE, status, "eglDestroySurface failed" );
         /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglDestroySurface sat an error" );
         surface = EGL_NO_SURFACE;
      }

      if ( EGL_NO_CONTEXT != context )
      {
         status = eglDestroyContext( dpy_valid, context );

         if (status == EGL_TRUE)
         {
            AVK_LOG_FUN(eglDestroyContext, AVK_PASS);
         }
         else
         {
            AVK_LOG_FUN(eglDestroyContext, AVK_FAIL);
         }

         AVK_LOG_EX(EGL_SUCCESS == eglGetError());

         /// ASSERT_EGL_EQUAL( EGL_TRUE, status, "eglDestroyContext failed" );
         /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglDestroyContext sat an error" );
         context = EGL_NO_CONTEXT;
      }
   }
   AVK_LOG_FUN(_avk_eglMakeCurrent_CASE006_ALL_VALID_PARAM, AVK_PASS);

   /* look for two configs with same alpha, but different client API */
   /* grab all gles configs */
   status = eglChooseConfig( dpy_valid, config_attribute_gles, configs_gles, 10, &num_config_gles );

   if (status == EGL_TRUE)
   {
      AVK_LOG_FUN(eglChooseConfig, AVK_PASS);
   }
   else
   {
      AVK_LOG_FUN(eglChooseConfig, AVK_FAIL);
   }

   AVK_LOG_EX(EGL_SUCCESS == eglGetError());

   /// ASSERT_EGL_EQUAL( EGL_TRUE, status, "eglChooseConfig failed" );
   /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglChooseConfig sat an error" );


   /* Case 13: making a surface current when window has been invalidated */
   curr_config = (EGLConfig)NULL;
   if ( (EGLConfig)NULL != config_gles )
   {
      curr_config = config_gles;
      eglBindAPI( EGL_OPENGL_ES_API );
      context = eglCreateContext( dpy_valid, curr_config, EGL_NO_CONTEXT, context_attribute_gles );
   }

   if (context == EGL_NO_CONTEXT)
   {
      AVK_LOG_FUN(eglCreateContext, AVK_FAIL);
   }
   else
   {
      AVK_LOG_FUN(eglCreateContext, AVK_PASS);
   }

   AVK_LOG_EX(EGL_SUCCESS == eglGetError());

   /// ASSERT_EGL_NOT_EQUAL( EGL_NO_CONTEXT, context, "eglCreateContext failed creating a context" );
   /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglCreateContext sat an error" );

   surface = eglCreateWindowSurface( dpy_valid, curr_config, win, NULL );

   if (surface == EGL_NO_SURFACE)
   {
      AVK_LOG_FUN(eglCreateWindowSurface, AVK_FAIL);
   }
   else
   {
      AVK_LOG_FUN(eglCreateWindowSurface, AVK_PASS);
   }

   AVK_LOG_EX(EGL_SUCCESS == eglGetError());

   /// ASSERT_EGL_NOT_EQUAL( EGL_NO_SURFACE, surface, "eglCreateWindowSurface failed with valid attributes" );
   /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglCreateWindowSurface sat an error" );

   if ( (EGL_NO_CONTEXT != context) && (EGL_NO_SURFACE != surface) )
   {
      /* invalidate the window. The window can no longer be used after this. */
      status = egl_helper_invalidate_window( win );

      status = eglMakeCurrent( dpy_valid, surface, surface, context );

      if (status == EGL_FALSE)
      {
         AVK_LOG_FUN(eglCreateWindowSurface, AVK_PASS);
      }
      else
      {
         AVK_LOG_FUN(eglCreateWindowSurface, AVK_FAIL);
      }

      AVK_LOG_EX(EGL_BAD_NATIVE_WINDOW == eglGetError());

      /// ASSERT_EGL_EQUAL( status, EGL_FALSE, "eglMakeCurrent sat surface with invalid native window current" );
      /// ASSERT_EGL_ERROR( eglGetError(), EGL_BAD_NATIVE_WINDOW, "eglMakeCurrent did not set EGL_BAD_NATIVE_WINDOW" );

      if ( EGL_TRUE == status )
      {
         /// status = eglMakeCurrent( dpy_valid, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT );

         if (status == EGL_TRUE)
         {
            AVK_LOG_FUN(eglMakeCurrent, AVK_PASS);
         }
         else
         {
            AVK_LOG_FUN(eglMakeCurrent, AVK_FAIL);
         }

         AVK_LOG_EX(EGL_SUCCESS == eglGetError());

         /// ASSERT_EGL_EQUAL( status, EGL_TRUE, "eglMakeCurrent failed" );
         /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglMakeCurrent sat an error" );
      }
   }

   if ( EGL_NO_SURFACE != surface )
   {
      status = eglDestroySurface( dpy_valid, surface );
      ///AVK_LOG_EX(eglDestroySurface( dpy_valid, surface );

      if (status == EGL_TRUE)
      {
         AVK_LOG_FUN(eglDestroySurface, AVK_PASS);
      }
      else
      {
         AVK_LOG_FUN(eglDestroySurface, AVK_FAIL);
      }

      AVK_LOG_EX(EGL_SUCCESS == eglGetError());

      /// ASSERT_EGL_EQUAL( EGL_TRUE, status, "eglDestroySurface failed" );
      /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglDestroySurface sat an error" );
   }

   if ( EGL_NO_CONTEXT != context )
   {
      status = eglDestroyContext( dpy_valid, context );

      if (status == EGL_TRUE)
      {
         AVK_LOG_FUN(eglDestroyContext, AVK_PASS);
      }
      else
      {
         AVK_LOG_FUN(eglDestroyContext, AVK_FAIL);
      }

      AVK_LOG_EX(EGL_SUCCESS == eglGetError());

      /// ASSERT_EGL_EQUAL( EGL_TRUE, status, "eglDestroyContext failed" );
      /// ASSERT_EGL_ERROR( eglGetError(), EGL_SUCCESS, "eglDestroyContext sat an error" );
   }

   egl_helper_terminate_display( dpy_valid, &native_dpy );

   FREE( configs_gles);

   ///-----------------------------------------------------------------------------------------
   status = egl_helper_destroy_window( win );
   ASSERT_EGL_EQUAL( status, EGL_TRUE, "egl_helper_destroy_window failed" );
   status = egl_helper_destroy_window( win2 );
   ASSERT_EGL_EQUAL( status, EGL_TRUE, "egl_helper_destroy_window2 failed" );

   avk_egl_memory_deinitialize();
   avk_gfx3d_memory_allocator_deinit();
}



int avk_egl_api_test_entry(void)
{
    /// request memory source
    _avk_eglGetError001();
    AVK_LOG_FUN(_avk_eglGetError001_Test_SUMMARY, AVK_PASS);

    _avk_eglGetError002();
    AVK_LOG_FUN(_avk_eglGetError002_Test_SUMMARY, AVK_PASS);

    _avk_eglMakeCurrent();
    AVK_LOG_FUN(_avk_eglMakeCurrent_Test_SUMMARY, AVK_PASS);
}

AVK_ADD_ITEM(AVK_FW_GRAPHIC3D_AUTO,L"Auto case",AVK_FW_GRAPHIC3D);


AVK_CASE(AVK_FW_GRAPHIC3D_CASE_AUTO,AVK_FW_GRAPHIC3D_AUTO)
{
   avk_egl_api_test_entry();
}

#ifdef __cplusplus
}
#endif

#endif /*__DRV_MALI400MP_OPENGLES_SUPPORT__*/

#endif /*__MAUI_SDK_TEST__*/
