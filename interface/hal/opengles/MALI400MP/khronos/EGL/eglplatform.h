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
 *    eglplatform.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/  
 
/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 * (C) COPYRIGHT 2008-2010 ARM Limited
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 */

#ifndef __EGLPLATFORM_H__
#define __EGLPLATFORM_H__

#ifdef __cplusplus
extern "C" {
#endif


/* 
 * Macros used in EGL function prototype declarations.
 *
 * EGLAPI return-type EGLAPIENTRY eglFunction(arguments);
 * typedef return-type (EXPAPIENTRYP PFNEGLFUNCTIONPROC) (arguments);
 *
 * On Windows (MODIS environment), EGLAPIENTRY can be defined like APIENTRY.
 * On real target, it should be empty.
 */
/// for MODIS environment, the EGL API must import from external library(libEGL.lib)     
#if !defined(GEN_FOR_PC) && !defined(__MTK_TARGET__)      
    #include <sys/types.h>    
    
    #ifndef EGLAPIENTRY    
        #define EGLAPIENTRY __stdcall
    #endif
    
    #ifndef EGLAPIENTRYP
        #define EGLAPIENTRYP EGLAPIENTRY*
    #endif            
    
    #ifndef EGLAPI    
        #define EGLAPI __declspec(dllimport)        
    #endif         
#else 
    #ifndef EGLAPIENTRY
        #define EGLAPIENTRY
    #endif
    
    #ifndef EGLAPIENTRYP
        #define EGLAPIENTRYP EGLAPIENTRY*
    #endif
    
    #ifndef EGLAPI
        #define EGLAPI extern
    #endif
#endif


#include <khrplatform.h>

#if !defined(__MAUI_BASIC__)
    /// EGL data type definitions for MTK platform (target/Modis)    

    #include "fbdev_window.h"
    #include "kal_public_defs.h"
    /// #include "gdi_datatype.h"
    /// #include "gdi_include.h"
    
    typedef kal_uint32  NativeDisplayType;  /// ID of LCD
    typedef fbdev_window  *NativeWindowType;   /// Native system frame buffer             
    typedef fbdev_window  *NativePixmapType;   /// Native system window buffer       
   
#elif defined(__MAUI_BASIC__)
  
   /// EGL data type definitions for MTK MAUI basic load
   #include "kal_non_specific_general_types.h"
   #include "EGL/fbdev_window.h"       
   
   typedef kal_uint32  NativeDisplayType;    
   typedef fbdev_window*  NativeWindowType;
   typedef fbdev_window*  NativePixmapType;   

/// #elif defined(WIN32) /// For Modis platform
///   
///    #include <windows.h>   
///    /// EGL data type definitions for MoDIS
///    
///    typedef HDC     NativeDisplayType;
///    typedef HBITMAP NativePixmapType;
///    typedef HWND    NativeWindowType;     
#else
     #error "Platform not recognized"
#endif

/// Robin, the following macro defintion should query through LCD API 
#define NATIVE_DIPSLAY_FORMAT_RED_CHANNEL_LENGTH   5
#define NATIVE_DIPSLAY_FORMAT_RED_OFFSET           11

#define NATIVE_DIPSLAY_FORMAT_GREEN_CHANNEL_LENGTH 6
#define NATIVE_DIPSLAY_FORMAT_GREEN_OFFSET         5

#define NATIVE_DIPSLAY_FORMAT_BLUE_CHANNEL_LENGTH  5
#define NATIVE_DIPSLAY_FORMAT_BLUE_OFFSET          0


#ifdef __cplusplus
}
#endif

/* EGL 1.2 types, renamed for consistency in EGL 1.3 */
typedef NativeDisplayType EGLNativeDisplayType;
typedef NativePixmapType  EGLNativePixmapType;
typedef NativeWindowType  EGLNativeWindowType;

/* Define EGLint. This must be an integral type large enough to contain
 * all legal attribute names and values passed into and out of EGL,
 * whether their type is boolean, bitmask, enumerant (symbolic
 * constant), integer, handle, or other.
 * While in general a 32-bit integer will suffice, if handles are
 * represented as pointers, then EGLint should be defined as a 64-bit
 * integer type.
 */
typedef int EGLint;

#endif /* __EGLPLATFORM_H__ */

