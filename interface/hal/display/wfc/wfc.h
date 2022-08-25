/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *    wfc.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    MTK extended OpenWF Composition API header file.
 *    
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 07 17 2012 haitao.shang
 * removed!
 * .
 *
 * 02 23 2012 yinli.liang
 * removed!
 * .
 *
 * 02 17 2012 haitao.shang
 * removed!
 * .
 *
 * 02 10 2012 haitao.shang
 * removed!
 * .
 *
 * 10 27 2011 yinli.liang
 * removed!
 * .
 *
 * 06 08 2011 bin.han
 * removed!
 * .
 *
 * 05 20 2011 zifeng.qiu
 * removed!
 * .
 *
 * 04 15 2011 bin.han
 * removed!
 * .
 *
 * 04 15 2011 tianshu.qiu
 * removed!
 * .
 *
 * 04 11 2011 tianshu.qiu
 * removed!
 * .
 *
 * 04 08 2011 bin.han
 * removed!
 * .
 *
 * 03 28 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 14 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 08 2011 ct.fang
 * removed!
 * .
 *
 * 02 18 2011 ct.fang
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================*/
 
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

/*! \defgroup wfc OpenWF Composition SI
 * @{
 */

/*! \file wfc.h
 *
 *  \brief OpenWF Composition public API, type definitions and function prototypes
 *
 *  This is one of the three header files defined by the specification.
 *  This file contains the portable definitions of data types
 *  and function prototypes.

 *  Refer to OpenWF Composition specification for the
 *  additional documentation.
 *
 */

/*! @} */

#ifndef _WFC_H_
#define _WFC_H_

/******************************************************************************
 * include directives
 ******************************************************************************/
#include <wfc/wfcplatform.h>
#include "kal_release.h"

#include "common\owfimage.h"
#include "drv_sw_features_display.h"
#include "drv_features_display.h"
#ifdef __cplusplus
extern "C" {
#endif

#define OPENWFC_VERSION_1_0       (1)

#define WFC_NONE                  (0)

#define WFC_INVALID_HANDLE        ((WFCHandle)0)

#define WFC_DEFAULT_DEVICE_ID     (0)

#ifdef WFC_ON_KHRPLATFORM
typedef enum {
    WFC_FALSE                               = KHR_BOOLEAN_FALSE,
    WFC_TRUE                                = KHR_BOOLEAN_TRUE,
    WFC_BOOLEAN_FORCE_32BIT                 = 0x7FFFFFFF
} WFCboolean;
#endif /* WFC_ON_KHRPLATFORM */

#ifdef WFC_ON_KAL
typedef enum {
    WFC_FALSE                               = KAL_FALSE,
    WFC_TRUE                                = KAL_TRUE,
    WFC_BOOLEAN_FORCE_32BIT                 = 0x7FFFFFFF
} WFCboolean;
#endif /* WFC_ON_KAL */

typedef WFCHandle WFCDevice;
typedef WFCHandle WFCContext;
typedef WFCHandle WFCSource;
typedef WFCHandle WFCMask;
typedef WFCHandle WFCElement;

/**
 *  For detailed info of each enum ID, please refer to the official OpenWF 
 *  Composition specification V1.0.
 */
typedef enum {
    WFC_ERROR_NONE                          = 0,
    WFC_ERROR_OUT_OF_MEMORY                 = 0x7001,
    WFC_ERROR_ILLEGAL_ARGUMENT              = 0x7002,
    WFC_ERROR_UNSUPPORTED                   = 0x7003,
    WFC_ERROR_BAD_ATTRIBUTE                 = 0x7004,
    WFC_ERROR_IN_USE                        = 0x7005,
    WFC_ERROR_BUSY                          = 0x7006,
    WFC_ERROR_BAD_DEVICE                    = 0x7007,
    WFC_ERROR_BAD_HANDLE                    = 0x7008,
    WFC_ERROR_INCONSISTENCY                 = 0x7009,
    WFC_ERROR_MM_SET_ATTR_MTK               = 0x700A,
    WFC_ERROR_FORCE_32BIT                   = 0x7FFFFFFF
} WFCErrorCode;

typedef enum {
    WFC_DEVICE_FILTER_SCREEN_NUMBER         = 0x7020,
    WFC_DEVICE_FILTER_FORCE_32BIT           = 0x7FFFFFFF
} WFCDeviceFilter;

typedef enum {
    /* Read-only */
    WFC_DEVICE_CLASS                        = 0x7030,
    WFC_DEVICE_ID                           = 0x7031,

    /* Read-write */
    WFC_DEVICE_NATIVE_DEBUG_TRACE_MTK       = 0x7032, /**< <b>[MTK]</b> 
                                                           Storage type: WFCboolean. Default: WFC_FALSE. \n
                                                           WFC_TRUE, to enable MAUI catcher log debug trace. \n
                                                           WFC_FALSE, to disable.
                                                       */

    WFC_DEVICE_FORCE_32BIT                  = 0x7FFFFFFF
} WFCDeviceAttrib;

typedef enum {
    WFC_DEVICE_CLASS_FULLY_CAPABLE          = 0x7040, /**< The class of devices which can output to both memory and external devices. */
    WFC_DEVICE_CLASS_OFF_SCREEN_ONLY        = 0x7041, /**< The class of devices which can only output to memory. */
    WFC_DEVICE_CLASS_FORCE_32BIT            = 0x7FFFFFFF
} WFCDeviceClass;

/**
 *  <b>[MTK]</b> The bit fields to specify memory type and characteristics. 
 *  
 *  \remark This is extended for MTK MAUI. Something to be noted: \n
 *          1. The three bits of cacheability is not-applicable when it internal memory is specified. \n
 *          2. If WFC_MEMORY_TYPE_SWITCHABLE_MTK is set, cacheable and noncacheable bits indicate the current settings of this memory. \n
 */
typedef enum { 
    WFC_MEMORY_TYPE_NONE_MTK                = 0,        /**< 0x0000_0000 */
    WFC_MEMORY_TYPE_INTERNAL_MEMORY_MTK     = (1 << 0), /**< 0x0000_0001, internal memory such as MMSYS SRAM or D-TCM. */
    WFC_MEMORY_TYPE_EXTERNAL_MEMORY_MTK     = (1 << 1), /**< 0x0000_0002, external memory. */
    WFC_MEMORY_TYPE_CACHEABLE_MTK           = (1 << 2), /**< 0x0000_0004, external and cacheable memory. */
    WFC_MEMORY_TYPE_NONCACHEABLE_MTK        = (1 << 3), /**< 0x0000_0008, external and non-cacheable memory. */
    WFC_MEMORY_TYPE_SWITCHABLE_MTK          = (1 << 4), /**< 0x0000_0010, external and switchable memory. It can be switched between cacheable and non-cacheable. */
    
    WFC_MEMORY_TYPE_FORCE_32BIT_MTK         = 0x7FFFFFFF  
} WFCMemoryTypeMTK;

/**
 *  <b>[MTK]</b> The event types of WFCContext.
 *  \remark This is extended for MTK MAUI.
 */
typedef enum {
    WFC_CONTEXT_EVENT_COMPOSITION_START_MTK   = 0x7301, /**< This event indicates a composition is started. */
    WFC_CONTEXT_EVENT_COMPOSITION_FINISH_MTK  = 0x7302, /**< This event indicates a composition is finished. */
    WFC_CONTEXT_EVENT_VSYNC_MTK               = 0x7303, /**< This event indicates a valid vsync is received. */
    WFC_CONTEXT_EVENT_COMPOSITION_FINISH_ALWAYS_CALLBACK_MTK = 0x7304, /**< This event indicates a display update operation has finished. This callback is invoked each time when display HW finishes update. No matter if the committed configuration is applied or not. */
	WFC_CONTEXT_EVENT_REALSE_READ_BUFFER_DONE_CALLBACK_MTK = 0X7305,/**< This event indicates LCD already release read buffer, and MDP can get the buffer. This callback only be used when camera preview triple buffer currently.*/
    WFC_CONTEXT_EVENT_FORCE_32BIT_MTK         = 0x7FFFFFFF
} WFCContextEventTypeMTK;

typedef void (*WFCCallbackFunctionPtrMTK)(WFCContextEventTypeMTK event, void* param);

typedef enum {
    /* Read-only */                                           /* Types */
    WFC_CONTEXT_TYPE                              = 0x7051,
    WFC_CONTEXT_TARGET_HEIGHT                     = 0x7052,   /**< LCM Number of Rows. */
    WFC_CONTEXT_TARGET_WIDTH                      = 0x7053,   /**< LCM Number of Columns. */
    WFC_CONTEXT_LOWEST_ELEMENT                    = 0x7054,   
    WFC_CONTEXT_WORKING_BUFFER_REQ_MTK            = 0x7055,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCint[4N], 
                                                                   a WFCint array of size 4N, N is a natural number.\n
                                                                   The 4-tuple is (type, size, start address alignment, size alignment) \n
                                                                   type is a bitmask of WFCMemoryTypeMTK. \n
                                                                   size is the minimum size required in byte. \n
                                                                   start address alignment X means the buffer start address should be X-byte aligned. \n
                                                                   size alignment Y means the buffer size should be a Y-byte multiple. \n
                                                                   \remark Please get this attribute to know the memory requirements of this context before invoking wfcCompose().
                                                               */
                                                              // TODO: Consider if this is decided after some parameters are set discuss with Viki later..

    WFC_CONTEXT_REFRESH_RATES_MTK                 = 0x7056,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCint[N], 
                                                                   an array for available refresh rates of associated WFCContext. \n
                                                                   Unavailable for offscreen type context. \n
                                                                   A user should first query this attribute and choose one among them by setting WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK.
                                                               */
                                                              // TODO: Need a programming guide here.

    // KeTing: GDI's request to provide such an attribute
    WFC_CONTEXT_IS_FLATTEN_READY_MTK              = 0x7057,   /**< <b>[MTK]</b>
                                                                   Storage type: WFCboolean,
                                                                   The attribute will return whether this context can do flatten at the moment of query
                                                               */

    WFC_CONTEXT_PPI_MTK                           = 0x7058,   /**< <b>[MTK]</b>
                                                                   Storage type: WFCint, \n
                                                                   Accessor: wfcGetContextAttribi only. \n
                                                                   This will return the PPI of device, 0 means the return value is invalid.
                                                               */  

    /* Read-write */
    WFC_CONTEXT_ROTATION                          = 0x7061,
    WFC_CONTEXT_BG_COLOR                          = 0x7062,   /**< \remark <b>[MTK]</b> This is changed to use WFCint[4] integer type instead of float type. */
    WFC_CONTEXT_WORKING_BUFFER_MTK                = 0x7063,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCint[3N], 
                                                                   a WFCint array of size 3N, N is a natural number. \n
                                                                   The 3-tuple is (type, start address, size). \n
                                                                   type is a bitmask of WFCMemoryTypeMTK. \n
                                                                   start address is the start address of allocated buffer.\n
                                                                   size is the buffer size.\n
                                                                   \remark Once a memory is set, it will be used by WFC for good unless the memory block is 
                                                                           removed by the user. To remove one memory block, set the size to 0 with original type and start address. \n
                                                               */

    WFC_CONTEXT_CALLBACK_MTK                      = 0x7064,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCint[4N], 
                                                                   a WFCint array of size 4N. 
                                                                   The 4-tuple is (event type, function pointer, param, enable). \n
                                                                   event type is one of WFCContextEventTypeMTK.\n
                                                                   function pointer type is WFCCallbackFunctionPtrMTK. \n
                                                                   param is an opaque handle type will be passed back through WFCCallbackFunctionPtrMTK. \n
                                                                   enable is a WFCboolean, WFC_TRUE to enable callback, WFC_FALSE to remove this callback from the context. \n
                                                                   \remark Once a callback function is set, WFC keeps calling it when registered event happens. To change event to listen, 
                                                                           the user needs to set the 4-tuple again with enable WFC_FALSE. Then set the 4-tuple for the new event.
                                                               */

    WFC_CONTEXT_CONCURRENT_MEMORY_OUT_MTK         = 0x7065,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCboolean. Default: WFC_FALSE. \n
                                                                   WFC_TRUE, will enable the OnScreen context to output to target specified by 
                                                                             WFC_CONTEXT_CONCURRENT_MEMORY_OUT_TARGET_MTK at the same time when composing.\n
                                                                   WFC_FALSE, will disable the OnScreen context to output to the stream target at the same time.\n
                                                               */

    WFC_CONTEXT_CONCURRENT_MEMORY_OUT_STREAM_MTK  = 0x7066,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCint, should be a OWFNativeStreamType. 
                                                                   \remark See WFC_CONTEXT_CONCURRENT_MEMORY_OUT_IMAGE_MTK.
                                                               */

    WFC_CONTEXT_CONCURRENT_MEMORY_OUT_IMAGE_MTK   = 0x7067,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCint, should be a OWF_IMAGE*. 
                                                                   \remark For ease-of-use, we added this attribute to specify WFC output image. 
                                                                           This attribut has higher priority over WFC_CONTEXT_CONCURRENT_MEMORY_OUT_STREAM_MTK. 
                                                                           If this is set, WFC_CONTEXT_CONCURRENT_MEMORY_OUT_STREAM_MTK is ignored.
                                                               */

    WFC_CONTEXT_TOTAL_VSYNC_COUNT_MTK             = 0x7068,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCint, The total VSync count after the context is created. \n
                                                                   It will wrap after overflow. It can be reset by just set this attribute with a new value. \n
                                                               */

    WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK          = 0x7069,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCint.\n 
                                                                   Current OnScreen context refresh rate selected. This is not applicable when 
                                                                   the context is a off-screen context. 
                                                               */

    WFC_CONTEXT_DESTINATION_RECTANGLE_MTK         = 0x706A,   /**< <b>[MTK]</b> LCM Retangle
                                                                   Storage type: WFCint[4], 
                                                                   (offsetX, offsetY, width, height) \n
                                                                   This specifies the LCM update region offset and size for output. \n
                                                               */

    WFC_CONTEXT_ROI_RECTANGLE_MTK                 = 0x706B,   /**< <b>[MTK]</b> ROI rectangle
                                                                   Storage type: WFCint[4], 
                                                                   (offsetX, offsetY, width, height) \n
                                                                   This specifies the ROI offset and size for output. \n
                                                               */

    WFC_CONTEXT_CONCURRENT_MEMORY_OUT_RECT_MTK    = 0x706C,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCint[4], 
                                                                   (offsetX, offsetY, width, height) \n
                                                                   This secifies destination pitch for concurrent memory out...
                                                               */

    WFC_CONTEXT_TARGET_IMAGE_MTK                  = 0x706D,   /**< <b>[MTK]</b> 
                                                                   Storage type: OWF_IMAGE* 
                                                                   This attribute is only used for off screen context.
                                                               */

    // KeTing: For autonomous mode
    WFC_CONTEXT_AUTONOMOUS_SYNC_TRIGGER_MTK       = 0x706E,   /**< <b>[MTK]</b>
                                                                   Storage type: WFCint[3],
                                                                   (sync_trigger, frame_period, element_handle) \n
                                                                   This specifies the sync source in autonomous mode. frame_period is in milli-second
                                                                   The last argument <code>element_handle</code> is used only for <code>WFC_AUTONOMOUS_SYNC_TO_ELEMENT</code>
                                                               */

    WFC_CONTEXT_VSYNC_ENABLE_MTK                  = 0x7070,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCboolean. Default: WFC_TRUE. \n
                                                                   WFC_TRUE, will enable VSync mechanism to avoid tearing.
                                                                   WFC_FALSE, will disable VSync mechanism.\n
                                                               */

    WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK          = 0x7071,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCAutonomousSyncTriggerMTK.  \n
                                                                   This specifies which mode is used in AUTONOMOUS Mode .\n
                                                               */

    WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK             = 0x7072,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCuint.  \n
                                                                   This specifies the frame_period when WFC is in Sync_To_Element Mode.
                                                                   frame_period is in milli-second. \n
                                                               */

    WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK       = 0x7073,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCElement.  \n
                                                                   element_handle is used only for <code>WFC_AUTONOMOUS_SYNC_TO_ELEMENT</code> .\n
                                                               */

                                                               
    WFC_CONTEXT_PALETTE_TABLE_MTK                 = 0x7074,   /**< <b>[MTK]</b> 
                                                                   Storage type: WFCuint.  \n
                                                                   palette table buffer address is used when element color format is 8-bpp indexed. \n
                                                               */
    WFC_CONTEXT_ALL_ATTRIBUTES_MTK                 = 0x7075,   /**< <b>[MTK]</b> 
                                                                       Storage type: WFCCtxtRWAttrib *.  \n
                                                                       used for set or get all context attribute by WFCCtxtRWAttrib. \n
                                                               */
	WFC_CONTEXT_BLT_MAX_REFRESH_RATE_MTK 		    = 0x7076,/**< <b>[MTK]</b> 
                                                                    Storage type: WFCint.\n                                                                    
									current Onscreen context max refresh rate, it means the context update speed under consideration of EMI BW,LCD controller capability, LCM timing and so on,									
									rather than simply refers to the LCM refresh rate. Its value is based on LCD tearing-control mode, and have a default value.									
									If using 1TE-mode, it equals to LCM refresh rate; if using 2TE-mode, it equals to wait TE(worst case: 1TE time) plus HW refresh time(theory estimation value under full screen update). 
									This is not applicable when the context is a off-screen context.								                                                                  
									*/

    WFC_CONTEXT_FORCE_32BIT                       = 0x7FFFFFFF
} WFCContextAttrib;

typedef enum {
    WFC_CONTEXT_TYPE_ON_SCREEN              = 0x7071,
    WFC_CONTEXT_TYPE_OFF_SCREEN             = 0x7072,
    WFC_CONTEXT_TYPE_FORCE_32BIT            = 0x7FFFFFFF
} WFCContextType;

typedef enum {
    /* Clockwise rotation */
    WFC_ROTATION_0                          = 0x7081,  /* default */
    WFC_ROTATION_90                         = 0x7082,
    WFC_ROTATION_180                        = 0x7083,
    WFC_ROTATION_270                        = 0x7084,
    WFC_ROTATION_FORCE_32BIT                = 0x7FFFFFFF
} WFCRotation;

// KeTing: For automous mode
// TODO: [o] The number of the enum??
typedef enum {
    WFC_AUTONOMOUS_SYNC_TO_NONE             = 0x7A00,
    WFC_AUTONOMOUS_SYNC_TO_ELEMENT          = 0x7A01,
    WFC_AUTONOMOUS_SYNC_TO_VSYNC            = 0x7A02,
    WFC_AUTONOMOUS_SYNC_TO_TIMER            = 0x7A03,
    WFC_AUTONOMOUS_SYNC_FORCE_32BIT         = 0x7FFFFFFF   
} WFCAutonomousSyncTriggerMTK;

typedef enum {
                                                          /* Types            */
    WFC_ELEMENT_DESTINATION_RECTANGLE       = 0x7101,     /**< WFCint[4]    (offsetX, offsetY, width, height) The rectangle after flip, rotation, and scaling. */
    WFC_ELEMENT_SOURCE                      = 0x7102,     /**< WFCSource        */
    WFC_ELEMENT_SOURCE_RECTANGLE            = 0x7103,     /**< WFCint[4]    (offsetX, offsetY, width, height) */
    WFC_ELEMENT_SOURCE_FLIP                 = 0x7104,     /**< WFCboolean       */
    WFC_ELEMENT_SOURCE_ROTATION             = 0x7105,     /**< WFCRotation      */
    WFC_ELEMENT_SOURCE_SCALE_FILTER         = 0x7106,     /**< N/A
                                                               \remark <b>[MTK]</b> This attribute is currently not supported by MTK implementation. 
                                                                       If this attribute is set, WFC will report WFC_ERROR_UNSUPPORTED. 
                                                           */
    WFC_ELEMENT_TRANSPARENCY_TYPES          = 0x7107,     /**< WFCbitfield  WFCTransparencyType */
    WFC_ELEMENT_GLOBAL_ALPHA                = 0x7108,     /**< WFCint           */
    WFC_ELEMENT_MASK                        = 0x7109,     /**< N/A
                                                               \remark <b>[MTK]</b> This attribute is currently not supported by MTK implementation. 
                                                                       If this attribute is set, WFC will report WFC_ERROR_UNSUPPORTED. 
                                                           */
    WFC_ELEMENT_SOURCE_COLOR_KEY_MTK        = 0x710A,     /**< <b>[MTK]</b>
                                                               Storage type: WFCint. Default: 0x0. \n
                                                               The element attribute to specify source color key. 
                                                           */

    WFC_ELEMENT_DITHERING_MTK               = 0x710B,     /**< <b>[MTK]</b> 
                                                               Storage type: WFCboolean. Default: WFC_FALSE. \n
                                                               WFC_TRUE, to enable dithering before color conversion stage. \n
                                                               WFC_FALSE, to disable dithering function. \n
                                                               This is used to alleviate contour effects. \n
                                                               \remark If LCM I/F is 16bit or less, we suggest to turn this on for natural images to reduce contour effects. 
                                                                       But performance might degrade if this is turned on.
                                                           */

    WFC_ELEMENT_VIDEO_LAYER_MTK             = 0x710C,     /**< <b>[MTK]</b> 
                                                               Storage type: WFCboolean. Default: WFC_FALSE. \n
                                                               WFC_TRUE, this is a element for video layer\n
                                                               WFC_FALSE, not a video layer. \n
                                                           */
    WFC_ELEMENT_DC_LAYER_MTK                = 0x710D,     /**< <b>[MTK]</b> 
                                                               Storage type: WFCboolean. Default: WFC_FALSE. \n
                                                               WFC_TRUE, this is a element for direct couple layer\n
                                                               WFC_FALSE, not a direct couple layer. \n
                                                           */
    WFC_ELEMENT_ALL_ATTRIBUTES_MTK          = 0x710E,   /**< <b>[MTK]</b> 
                                                                       Storage type: WFCElementRWAttrib *.  \n
                                                                       used for set or get all element attribute by WFCElementRWAttrib. \n
                                                           */
#ifdef DRV_LCD_3D_MODE_SUPPORT
    WFC_ELEMENT_3D_VIEW_MODE_MTK                = 0x710F,     /**< <b>[MTK]</b> 
                                                               Storage type: WFC3DViewMode. \n
                                                               Only valid when this element is 3D layer 
                                                           */
    WFC_ELEMENT_3D_FIRST_EYE_MODE_MTK                = 0x7110,     /**< <b>[MTK]</b> 
                                                               Storage type: WFC3DFirstEyeMode. \n
                                                               Only valid when this element is 3D layer 
                                                           */
    WFC_ELEMENT_3D_START_ADDR_MODE_MTK                = 0x7111,     /**< <b>[MTK]</b> 
                                                               Storage type: WFC3DStartAddrMode. \n
                                                               Only valid when this element is 3D layer 
                                                           */                                                           
    WFC_ELEMENT_3D_LAYER_MTK                = 0x7112,     /**< <b>[MTK]</b> 
                                                               Storage type: WFCboolean. Default: WFC_FALSE. \n
                                                               WFC_TRUE, this is a element for 3D layer\n
                                                               WFC_FALSE, not a 3D layer. \n
                                                           */    
#endif                                                           

    WFC_ELEMENT_FORCE_32BIT                 = 0x7FFFFFFF  
} WFCElementAttrib;

typedef enum {
    WFC_SCALE_FILTER_NONE                   = 0x7151,  /**< default */
    WFC_SCALE_FILTER_FASTER                 = 0x7152,
    WFC_SCALE_FILTER_BETTER                 = 0x7153,
    WFC_SCALE_FILTER_FORCE_32BIT            = 0x7FFFFFFF
} WFCScaleFilter;

typedef enum {
    WFC_TRANSPARENCY_NONE                   = 0,       /**< default */
    WFC_TRANSPARENCY_ELEMENT_GLOBAL_ALPHA   = (1 << 0), /**< If WFC_TRANSPARENCY_ELEMENT_GLOBAL_ALPHA is enabled, this Element's
                                                             global alpha (specified by WFC_ELEMENT_GLOBAL_ALPHA) will be used when
                                                             blending this Element¡¦s content with the destination.
                                                         */
    WFC_TRANSPARENCY_SOURCE                 = (1 << 1), /**< If WFC_TRANSPARENCY_SOURCE is enabled, any alpha channel inherent in this
                                                             Element's Source (specified by WFC_ELEMENT_SOURCE) will be considered when
                                                             filtering and when blending this Element¡¦s content with the destination. 
                                                         */
    WFC_TRANSPARENCY_MASK                   = (1 << 2), /**< <b>[MTK]</b> Unsupported. */
    WFC_TRANSPARENCY_SOURCE_COLOR_KEY_MTK   = (1 << 3), /**< <b>[MTK]</b> Source key. */
    WFC_TRANSPARENCY_FORCE_32BIT            = 0x7FFFFFFF
} WFCTransparencyType;

typedef enum {
    WFC_VENDOR                              = 0x7200,
    WFC_RENDERER                            = 0x7201,
    WFC_VERSION                             = 0x7202,
    WFC_EXTENSIONS                          = 0x7203,
    WFC_STRINGID_FORCE_32BIT                = 0x7FFFFFFF
} WFCStringID;
#ifdef DRV_LCD_3D_MODE_SUPPORT
typedef enum {
    WFC_3D_IMAGE_PORTRAIT_MODE              = 0x7210,
    WFC_3D_IMAGE_LANDSCAPE_MODE             = 0x7211,
    WFC_3D_MODE_FORCE_32BIT                 = 0x7FFFFFFF
} WFC3DViewMode;

typedef enum {
    WFC_3D_IMAGE_LEFT_EYE_FIRST_MODE        = 0x7220,//means the first line show left eye image
    WFC_3D_IMAGE_RIGHT_EYE_FIRST_MODE       = 0x7221,//means the first line show right eye image
    WFC_3D_EYE_MODE_FORCE_32BIT             = 0x7FFFFFFF
} WFC3DFirstEyeMode;

typedef enum {
    WFC_3D_START_ADDR_FOR_LEFT_MODE        = 0x7230,//means the left or top part of 3D buffer is  for left eye
    WFC_3D_START_ADDR_FOR_RIGHT_MODE       = 0x7231,//means the left or top part of 3D buffer is  for right eye
    WFC_3D_ADDR_FORCE_32BIT                = 0x7FFFFFFF
} WFC3DStartAddrMode;
#endif
/////////////////////
// WFC structure prototype define
#define WFC_CONTEXT_MAX_WORKING_BUF_COUNT   (3)
/**
 *  \def WFC_CONTEXT_MAX_INSERTED_ELEMENT
 *  Max count of elements that can be inserted to a single context.
 */
#define WFC_CONTEXT_MAX_INSERTED_ELEMENT    (DRV_LAYER_TOTAL_COUNT)

/**
 *  \def WFC_CONTEXT_XXX_CALLBACK_COUNT
 *  Max count of callback functions that can be registered on a single context.
 */
#define WFC_CONTEXT_GDI_CALLBACK_COUNT      (4)
#define WFC_CONTEXT_MM_CALLBACK_COUNT       (2) //in VTC scenario, 2-video layer, so need at least 2 MM callback

typedef struct 
{
  WFCbitfield     type;
  WFCuint         startAddress;
  WFCint          size;
} WFCWorkingBuffer;
typedef struct
{
  WFCContextEventTypeMTK    event;
  WFCCallbackFunctionPtrMTK cbfunc;
  void*                     cbparam;
} WFCCallbackType;



typedef struct 
{
    WFCRotation       rotationAngle;
    WFCuint           bgColor;
    WFCWorkingBuffer  workingBuffer[WFC_CONTEXT_MAX_WORKING_BUF_COUNT];
    WFCboolean        enableConcurrentMemOut;
    WFCboolean        memOutUseStream;
    union 
    {
      OWF_IMAGE       image;
      WFCHandle       stream;
    }                 memOutTarget;
    OWF_RECTANGLE     roiRect;
    OWF_RECTANGLE     destinationRect;
    OWF_RECTANGLE     concurrentMemOutRect;
    WFCElement        _insertedElements[WFC_CONTEXT_MAX_INSERTED_ELEMENT]; /**< The handle array of WFCElements which are inserted into this context. */

	//Yinli: When use DDV2 extension(config all attribute once), GDI cannot  config this attribute
	//        but GDI can set this attribute alone by calling wfcSetContextAttribi
    WFCboolean        enableVsync;
    WFCuint           paletteTable;


  WFCCallbackType   gdiCallbacks[WFC_CONTEXT_GDI_CALLBACK_COUNT];

  
  // Bin: Please be payed attentation  !!!
  //        For MM config attributes only (wfcMMCommit), please put after syncTrigger !!!
  //        For GDI config attributes (wfcCommit), please put before the syncTrigger !!!
  WFCAutonomousSyncTriggerMTK syncTrigger;
  WFCuint           period; /*real frame period*/
  WFCElement        sync_element;
  WFCint            currRefreshRate;
  WFCCallbackType   mmCallbacks[WFC_CONTEXT_MM_CALLBACK_COUNT];
} WFCCtxtRWAttrib;



typedef struct 
{ /// 1st segment start,  only for GDI
  WFCbitfield     transparencyType;
  WFCint          globalAlpha;
  WFCuint         sourceColorKey;
  WFCboolean      enableSpatialDithering;
  OWF_RECTANGLE   destinationRect; 
  /// 1st segment end 
  
  
  ///Bin: please must be payed attentation  !!! 
  //  if you want to add an attribute which is set by GDI (wfcCommit), please add before source  !!!
  //  if you want to add an attribute which is set by MM (wfcMMCommit), please add after source  !!!
  
  /// 2nd segment start,  for both GDI and MM
  /// if video layer for MM. if non-video layer for GDI.
  WFCSource       source;
  OWF_RECTANGLE   sourceRect;
  WFCboolean      flip;
  WFCRotation     rotationAngle;
#ifdef DRV_LCD_3D_MODE_SUPPORT
  WFCboolean      is3DLayer;
  WFC3DViewMode   _3DimageViewMode;
  WFC3DFirstEyeMode  _3DimageFirstEyeMode;
  WFC3DStartAddrMode _3DimageStartAddrMode;  
#endif
  WFCboolean      isVideoLayer;
  /// 2nd segment end 
  
  
  ///Bin: please must be payed attentation ||| The following attribute is only for MM 
  /// 3rd segment start,  only for MM
  WFCboolean      isDCLayer;
  /// 3rd segment end 
} WFCElementRWAttrib;

/* Function Prototypes */

/* Device */
WFC_API_CALL WFCint WFC_APIENTRY
    wfcEnumerateDevices(WFCint *deviceIds, WFCint deviceIdsCount,
        const WFCint *filterList) WFC_APIEXIT;
WFC_API_CALL WFCDevice WFC_APIENTRY
    wfcCreateDevice(WFCint deviceId, const WFCint *attribList) WFC_APIEXIT;
WFC_API_CALL WFCErrorCode WFC_APIENTRY
    wfcGetError(WFCDevice dev) WFC_APIEXIT;
WFC_API_CALL WFCint WFC_APIENTRY
    wfcGetDeviceAttribi(WFCDevice dev, WFCDeviceAttrib attrib) WFC_APIEXIT;

/**
 *  \remark <b>[MTK]</b> This is not a standard OpenWF Composition API function. 
 */
WFC_API_CALL void WFC_APIENTRY
    wfcSetDeviceAttribi(WFCDevice dev,
                        WFCDeviceAttrib attrib, 
                        WFCint value);
WFC_API_CALL WFCErrorCode WFC_APIENTRY
    wfcDestroyDevice(WFCDevice dev) WFC_APIEXIT;

/* Context */
WFC_API_CALL WFCContext WFC_APIENTRY
    wfcCreateOnScreenContext(WFCDevice dev,
        WFCint screenNumber,
        const WFCint *attribList) WFC_APIEXIT;
WFC_API_CALL WFCContext WFC_APIENTRY
    wfcCreateOffScreenContext(WFCDevice dev,
        WFCNativeStreamType stream,
        const WFCint *attribList) WFC_APIEXIT;
/**
 *  <b> [MTK] </b> Instead of using a stream as target, this API call uses an image.
 *  \param dev        Handle to device.
 *  \param image      OWF_IMAGE* type, the user needs to keep OWF_IMAGE in heap or static memory.
 *  \param attribList Unnecessary.
 */
WFC_API_CALL WFCContext WFC_APIENTRY
    wfcCreateOffScreenContextMTK(WFCDevice dev,
                                 WFCHandle image,
                                 const WFCint *attribList) WFC_APIEXIT;

/**
 *  \param dev  Handle to device
 *  \param ctx  Handle to context
 *  \param wait This parameter is not applicable on MTK implementation 
                since WFC implementation does not have a task, so wfcCommit() is 
                always blocking.
 */
WFC_API_CALL void WFC_APIENTRY
    wfcCommit(WFCDevice dev, WFCContext ctx, WFCboolean wait) WFC_APIEXIT;
WFC_API_CALL WFCint WFC_APIENTRY
    wfcGetContextAttribi(WFCDevice dev, WFCContext ctx,
        WFCContextAttrib attrib) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
    wfcGetContextAttribiv(WFCDevice dev, WFCContext ctx,
        WFCContextAttrib attrib, WFCint count, WFCint *values) WFC_APIEXIT;
/**
 *  \remark This API function is not supported by MTK implementation.
 */
WFC_API_CALL void WFC_APIENTRY
    wfcGetContextAttribfv(WFCDevice dev, WFCContext ctx,
        WFCContextAttrib attrib, WFCint count, WFCfloat *values) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
    wfcSetContextAttribi(WFCDevice dev, WFCContext ctx,
        WFCContextAttrib attrib, WFCint value) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
    wfcSetContextAttribiv(WFCDevice dev, WFCContext ctx,
        WFCContextAttrib attrib,
        WFCint count, const WFCint *values) WFC_APIEXIT;
/**
 *  \remark This API function is not supported by MTK implementation.
 */
WFC_API_CALL void WFC_APIENTRY
    wfcSetContextAttribfv(WFCDevice dev, WFCContext ctx,
        WFCContextAttrib attrib,
        WFCint count, const WFCfloat *values) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
    wfcDestroyContext(WFCDevice dev, WFCContext ctx) WFC_APIEXIT;

/* Source */
WFC_API_CALL WFCSource WFC_APIENTRY
    wfcCreateSourceFromStream(WFCDevice dev, WFCContext ctx,
        WFCNativeStreamType stream,
        const WFCint *attribList) WFC_APIEXIT;
/**
 *  \param WFCHandle image please use OWF_IMAGE* type. 
 *  \remark This API function is created for MTK's WFC implementation.
 */
WFC_API_CALL WFCSource WFC_APIENTRY
    wfcCreateSourceFromImage(WFCDevice dev, WFCContext ctx,
        WFCHandle image,
        const WFCint *attribList) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
    wfcDestroySource(WFCDevice dev, WFCSource src) WFC_APIEXIT;

/* Mask */
/**
 *  \remark This API function is not supported by MTK implementation.
 */
WFC_API_CALL WFCMask WFC_APIENTRY
    wfcCreateMaskFromStream(WFCDevice dev, WFCContext ctx,
        WFCNativeStreamType stream,
        const WFCint *attribList) WFC_APIEXIT;
/**
 *  \remark This API function is not supported by MTK implementation.
 */
WFC_API_CALL void WFC_APIENTRY
    wfcDestroyMask(WFCDevice dev, WFCMask mask) WFC_APIEXIT;

/* Element */
WFC_API_CALL WFCElement WFC_APIENTRY
    wfcCreateElement(WFCDevice dev, WFCContext ctx,
        const WFCint *attribList) WFC_APIEXIT;
WFC_API_CALL WFCint WFC_APIENTRY
    wfcGetElementAttribi(WFCDevice dev, WFCElement element,
        WFCElementAttrib attrib) WFC_APIEXIT;
/**
 *  \remark This API function is not supported by MTK implementation.
 */
WFC_API_CALL WFCfloat WFC_APIENTRY
    wfcGetElementAttribf(WFCDevice dev, WFCElement element,
        WFCElementAttrib attrib) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
    wfcGetElementAttribiv(WFCDevice dev, WFCElement element,
        WFCElementAttrib attrib, WFCint count, WFCint *values) WFC_APIEXIT;
/**
 *  \remark This API function is not supported by MTK implementation.
 */
WFC_API_CALL void WFC_APIENTRY
    wfcGetElementAttribfv(WFCDevice dev, WFCElement element,
        WFCElementAttrib attrib, WFCint count, WFCfloat *values) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
    wfcSetElementAttribi(WFCDevice dev, WFCElement element,
        WFCElementAttrib attrib, WFCint value) WFC_APIEXIT;
/**
 *  \remark This API function is not supported by MTK implementation.
 */
WFC_API_CALL void WFC_APIENTRY
    wfcSetElementAttribf(WFCDevice dev, WFCElement element,
        WFCElementAttrib attrib, WFCfloat value) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
    wfcSetElementAttribiv(WFCDevice dev, WFCElement element,
        WFCElementAttrib attrib,
        WFCint count, const WFCint *values) WFC_APIEXIT;
/**
 *  \remark This API function is not supported by MTK implementation.
 */
WFC_API_CALL void WFC_APIENTRY
    wfcSetElementAttribfv(WFCDevice dev, WFCElement element,
        WFCElementAttrib attrib,
        WFCint count, const WFCfloat *values) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
    wfcInsertElement(WFCDevice dev, WFCElement element,
        WFCElement subordinate) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
    wfcRemoveElement(WFCDevice dev, WFCElement element) WFC_APIEXIT;
WFC_API_CALL WFCElement WFC_APIENTRY
    wfcGetElementAbove(WFCDevice dev, WFCElement element) WFC_APIEXIT;
WFC_API_CALL WFCElement WFC_APIENTRY
    wfcGetElementBelow(WFCDevice dev, WFCElement element) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
    wfcDestroyElement(WFCDevice dev, WFCElement element) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
    wfcCloneElementAttribute(WFCDevice dev, WFCElement SourceElement, WFCElement DestElement) WFC_APIEXIT;

/* Rendering */
WFC_API_CALL void WFC_APIENTRY
    wfcActivate(WFCDevice dev, WFCContext ctx) WFC_APIEXIT;
WFC_API_CALL void WFC_APIENTRY
    wfcDeactivate(WFCDevice dev, WFCContext ctx) WFC_APIEXIT;

/**
 *  \param dev  a handle of a WFCDevice.
 *  \param ctx  a handle of a WFCContext.
 *  \param wait WFC_TRUE, (blocking) this API returns after this compose completes...
 *                        if already someone is waiting, this API call fails.\n
 *              WFC_FALSE, this API direct returns (non-blocking), 
 *                         if last composition is not finished, this API call fails.\n
 */
WFC_API_CALL void WFC_APIENTRY
    wfcCompose(WFCDevice dev, WFCContext ctx, WFCboolean wait) WFC_APIEXIT;
/**
 *  \remark Since this API is troubling to use, 
 *          this API function is not supported by MTK implementation.
 */
WFC_API_CALL void WFC_APIENTRY
    wfcFence(WFCDevice dev, WFCContext ctx, WFCEGLDisplay dpy,
        WFCEGLSync sync) WFC_APIEXIT;

/* Renderer and extension information */
WFC_API_CALL WFCint WFC_APIENTRY
    wfcGetStrings(WFCDevice dev,
        WFCStringID name,
        const char **strings,
        WFCint stringsCount) WFC_APIEXIT;
WFC_API_CALL WFCboolean WFC_APIENTRY
    wfcIsExtensionSupported(WFCDevice dev, const char *string) WFC_APIEXIT;


#ifdef __cplusplus
}
#endif


#endif /* _WFC_H_ */

