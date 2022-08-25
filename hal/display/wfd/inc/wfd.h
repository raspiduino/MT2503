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
 *    wfd.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    MTK extended OpenWF Display API header file.
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
 * 02 23 2012 yinli.liang
 * removed!
 * .
 *
 * 02 10 2012 haitao.shang
 * removed!
 * .
 *
 * 06 02 2011 matthew.chen
 * removed!
 * Check in slim-ed DDv2 to Maui
 *
 * 04 26 2011 peter.wang
 * removed!
 * .
 *
 * 04 21 2011 bin.han
 * removed!
 * .
 *
 * 04 21 2011 bin.han
 * removed!
 * .6268 SLIM code check in
 *
 * 03 08 2011 ct.fang
 * removed!
 * .
 *
 * 03 07 2011 chelun.tsai
 * removed!
 * remove redundent functions.
 *
 * 03 07 2011 chelun.tsai
 * removed!
 * wfd header move to hal.
 *
 * 03 07 2011 chelun.tsai
 * removed!
 * .wfd header move to hal
 *
 * 02 18 2011 ct.fang
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 * Copyright (c) 2009 The Khronos Group Inc.
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

/*! \defgroup wfd OpenWF Display SI
 * @{
 */

/*! \file wfd.h
 *
 *  \brief OpenWF Display public API, type definitions and function prototypes
 *
 *  This is one of the three header files defined by the specification.
 *  This file contains the portable definitions of data types
 *  and function prototypes.

 *  Refer to OpenWF Display specification for the
 *  additional documentation.
 *
 */

/*! @} */

#ifndef _WFD_H_
#define _WFD_H_

/******************************************************************************
 * include directives
 ******************************************************************************/
#include <wfd/inc/wfdplatform.h>
#include "kal_release.h"
// TODO: consider to port KHR platform.h to KAL...

#ifdef __cplusplus
extern "C" {
#endif

#define OPENWFD_VERSION_1_0         (1)

#define WFD_NONE                    (0)

#define WFD_INVALID_PORT_ID         (0)
#define WFD_INVALID_PIPELINE_ID     (0)
#define WFD_INVALID_PIPELINE_LAYER  (0)

#define WFD_DEFAULT_DEVICE_ID       (0)

#ifdef WFD_ON_KHRPLATFORM
typedef enum
{ WFD_FALSE = KHR_BOOLEAN_FALSE,
  WFD_TRUE  = KHR_BOOLEAN_TRUE
} WFDboolean;
#endif

#ifdef WFD_ON_KAL
typedef enum
{ WFD_FALSE = KAL_FALSE,
  WFD_TRUE  = KAL_TRUE
} WFDboolean;
#endif

#define WFD_MAX_INT   ((WFDint)16777216)
#define WFD_MAX_FLOAT ((WFDfloat)16777216)

#define WFD_INVALID_HANDLE ((WFDHandle)0)

typedef WFDHandle WFDDevice;
typedef WFDHandle WFDEvent;
typedef WFDHandle WFDPort;
typedef WFDHandle WFDPortMode;
typedef WFDHandle WFDPipeline;
typedef WFDHandle WFDSource;
typedef WFDHandle WFDMask;

/**
 *  Device    --> BB internal HW block, e.g. LCD, GOVL, TVOUT
 *  Port      --> The output of a Device, e.g. the Main LCD/Sub LCD/Memory out of LCD
 *  Pipeline  --> Layer
 */

typedef enum
{ WFD_VENDOR                                = 0x7500,
  WFD_RENDERER                              = 0x7501,
  WFD_VERSION                               = 0x7502,
  WFD_EXTENSIONS                            = 0x7503,
  WFD_STRING_ID_FORCE_32BIT                 = 0x7FFFFFFF
} WFDStringID;

typedef enum
{ WFD_ERROR_NONE                            = 0,
  WFD_ERROR_OUT_OF_MEMORY                   = 0x7510,
  WFD_ERROR_ILLEGAL_ARGUMENT                = 0x7511,
  WFD_ERROR_NOT_SUPPORTED                   = 0x7512,
  WFD_ERROR_BAD_ATTRIBUTE                   = 0x7513,
  WFD_ERROR_IN_USE                          = 0x7514,
  WFD_ERROR_BUSY                            = 0x7515,
  WFD_ERROR_BAD_DEVICE                      = 0x7516,
  WFD_ERROR_BAD_HANDLE                      = 0x7517,
  WFD_ERROR_INCONSISTENCY                   = 0x7518,
  WFD_ERROR_FORCE_32BIT                     = 0x7FFFFFFF
} WFDErrorCode;

typedef enum
{ WFD_DEVICE_FILTER_PORT_ID                 = 0x7530,
  WFD_DEVICE_FILTER_FORCE_32BIT             = 0x7FFFFFFF
} WFDDeviceFilter;

typedef enum
{ WFD_COMMIT_ENTIRE_DEVICE                  = 0x7550,
  WFD_COMMIT_ENTIRE_PORT                    = 0x7551,
  WFD_COMMIT_PIPELINE                       = 0x7552,
  WFD_COMMIT_FORCE_32BIT                    = 0x7FFFFFFF
} WFDCommitType;

typedef enum
{ 
  /* read-only */
  WFD_DEVICE_ID                             = 0x7560, 

  /* read-write */
  WFD_DEVICE_ENABLE_NATIVE_DEBUG_TRACE_MTK  = 0x7561, /**< <b>[MTK]</b> WFD device attrib to enable/disable native debug trace.\n
                                                           Type: WFDboolean, default: WFD_FALSE \n
                                                           WFD_TRUE: to enable native debug trace; WFD_FALSE: o.w. \n
                                                           \remark: Enable debug trace may degrade SW performance.
                                                       */

  // KeTing: Add this to prevent from commit to LCM and commit to memory at the same time
  WFD_DEVICE_BUSY                           = 0x7562,

  WFD_DEVICE_ENABLE_FAST_ROTATOR_MEM_MTK    = 0x7563,/**< <b>[MTK]</b> WFD device attrib to enable/disable fast rotator memmory.\n
                                                           Type: WFDboolean, default: WFD_FALSE \n
                                                           WFD_TRUE: to enable fast rotator memmory; WFD_FALSE: o.w. \n
                                                       */
  

  WFD_DEVICE_ATTRIB_FORCE_32BIT             = 0x7FFFFFFF
} WFDDeviceAttrib;

/**
 *  This enum is used to specify the synchronization mode used 
 *  between LCD and external LCM.
 */
typedef enum
{ WFD_SYNC_MODE_HW_MTK,                                   /**< LCM VSync is connected to BB LPTE. \todo Check if we need to explicit different HW sync mechanisms. */
  WFD_SYNC_MODE_SW_MTK,                                   /**< LCM VSync is connected to BB EINT. */
  WFD_SYNC_MODE_NONE_MTK,                                 /**< LCM VSync is not connected. */
  WFD_SYNC_MODE_FORCE_32BIT                 = 0x7FFFFFFF
} WFDSyncModeMTK;

/**
 *  This enum is used to specify the tearing control mode used 
 *  for 1 TE mode or 1TE ~ 2TE mode.
 */
typedef enum
{ WFD_Tear_Control_MODE_1TE_MTK,                                   /**< LCD tear control use 1TE mode */
  WFD_Tear_Control_MODE_2TE_MTK,                                   /**< LCD tear control use 1TE~2TE mode . */
  WFD_Tear_Control_MODE_NONE_MTK,                                 /**< */
  WFD_Tear_Control_MODE_FORCE_32BIT                 = 0x7FFFFFFF
} WFDTearControlModeMTK;


typedef enum
{ WFD_EVENT_INVALID                         = 0x7580,
  WFD_EVENT_NONE                            = 0x7581,
  WFD_EVENT_DESTROYED                       = 0x7582,
  WFD_EVENT_PORT_ATTACH_DETACH              = 0x7583,
  WFD_EVENT_PORT_PROTECTION_FAILURE         = 0x7584,
  WFD_EVENT_PIPELINE_BIND_SOURCE_COMPLETE   = 0x7585,
  WFD_EVENT_PIPELINE_BIND_MASK_COMPLETE     = 0x7586,

  WFD_EVENT_VSYNC_MTK                       = 0x758A, // TODO: TBD
  WFD_EVENT_TE_SIGNAL_RECEIVED_MTK          = 0x758B, /**< <b>[MTK]</b> This event indicates sync signal is received from external device. */
  WFD_EVENT_COMMAND_TRANSFER_COMPLETE_MTK   = 0x758C, /**< <b>[MTK]</b> This event indicates command for an external device is transferred complete. */ 
  //WFD_EVENT_REGISTER_LATCH_COMPLETE_MTK     = 0x758D, /**< <b>[MTK]</b> This event indicates that a data transmission is started. */
  WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK      = 0x758E, /**< <b>[MTK]</b> This event indicates that a data transmission is completed. */

  WFD_EVENT_RSVD_MTK                        = 0x758F, /**< <b>[MTK]</b> This event indicates that a data transmission is completed. */
  WFD_EVENT_FORCE_32BIT                     = 0x7FFFFFFF
} WFDEventType;

typedef enum
{ /* Configuration Attributes */
  WFD_EVENT_PIPELINE_BIND_QUEUE_SIZE        = 0x75C0,

  /* Generic Event Attributes */
  WFD_EVENT_TYPE                            = 0x75C1,

  /* Port Attach Event Attributes */
  WFD_EVENT_PORT_ATTACH_PORT_ID             = 0x75C2,
  WFD_EVENT_PORT_ATTACH_STATE               = 0x75C3,

  /* Port Protection Event Attributes */
  WFD_EVENT_PORT_PROTECTION_PORT_ID         = 0x75C4,

  /* Pipeline Bind Complete Event Attributes */
  WFD_EVENT_PIPELINE_BIND_PIPELINE_ID       = 0x75C5,
  WFD_EVENT_PIPELINE_BIND_SOURCE            = 0x75C6,
  WFD_EVENT_PIPELINE_BIND_MASK              = 0x75C7,
  WFD_EVENT_PIPELINE_BIND_QUEUE_OVERFLOW    = 0x75C8,

  WFD_EVENT_ATTRIB_FORCE_32BIT              = 0x7FFFFFFF
} WFDEventAttrib;

typedef enum
{ WFD_PORT_MODE_WIDTH                       = 0x7600, /**< Storage type: WFDint */
  WFD_PORT_MODE_HEIGHT                      = 0x7601, /**< Storage type: WFDint */
  WFD_PORT_MODE_REFRESH_RATE                = 0x7602, /**< Storage type: WFDint
                                                           \remark Its storage type is originally WFDfloat in spec but we changed it for MTK implementation. 
                                                           */
  WFD_PORT_MODE_FLIP_MIRROR_SUPPORT         = 0x7603, /**< Storage type: WFDboolean */
  WFD_PORT_MODE_ROTATION_SUPPORT            = 0x7604, /**< Storage type: WFDRotationSupport */
  WFD_PORT_MODE_INTERLACED                  = 0x7605, /**< Storage type: WFDboolean */
  WFD_PORT_MODE_SYNC_MODE_MTK               = 0x7606, /**< <b>[MTK]</b> Storage type: WFDSyncModeMTK \n
                                                           This attribute is used to indicate which sync mode is in use for this port. \n */
  WFD_PORT_MODE_ATTRIB_FORCE_32BIT          = 0x7FFFFFFF
} WFDPortModeAttrib;

typedef enum
{ WFD_PORT_ID                               = 0x7620, /**< Storage type: WFDint, Read only */
  WFD_PORT_TYPE                             = 0x7621, /**< Storage type: WFDPortType, Read only */
  WFD_PORT_DETACHABLE                       = 0x7622, /**< Storage type: WFDboolean, Read only */
  WFD_PORT_ATTACHED                         = 0x7623, /**< Storage type: WFDboolean, Read only */
  WFD_PORT_NATIVE_RESOLUTION                = 0x7624, /**< Storage type: WFDint[2], Read only */
  WFD_PORT_PHYSICAL_SIZE                    = 0x7625, /**< Storage type: WFDint[2], Read only 
                                                           \remark Original storage type is WFDfloat[2]. 
                                                           */
  WFD_PORT_FILL_PORT_AREA                   = 0x7626, /**< Storage type: WFDboolean, Read only 
                                                           \remark When this attribute is WFD_TRUE, the entire port displayable 
                                                                   area must be filled with by the combined pipeline output image 
                                                                   or it will result in undefined behaviors.
                                                           */
  WFD_PORT_BACKGROUND_COLOR                 = 0x7627, /**< Storage type: WFDint[3], Read-write, default (0, 0, 0). \n
                                                           The format is (red, green, blue). \n
                                                           \remark Original storage type is WFDfloat[3]
                                                           */
  WFD_PORT_FLIP                             = 0x7628, /**< Storage type: WFDboolean, Read-write, default WFD_FALSE. */
  WFD_PORT_MIRROR                           = 0x7629, /**< Storage type: WFDboolean, Read-write, default WFD_FALSE. */
  WFD_PORT_ROTATION                         = 0x762A, /**< Storage type: WFDint, Read only, default 0. */
  WFD_PORT_POWER_MODE                       = 0x762B, /**< Storage type: WFDPowerMode, Read-write, default WFD_POWER_MODE_OFF. */
  WFD_PORT_GAMMA_RANGE                      = 0x762C, /**< Storage type: WFDfloat[2], Read only */
  WFD_PORT_GAMMA                            = 0x762D, /**< Storage type: WFDfloat, Read-write, default 1.0. */
  WFD_PORT_PARTIAL_REFRESH_SUPPORT          = 0x762E, /**< Storage type: WFDPartialRefresh, Read only */
  WFD_PORT_PARTIAL_REFRESH_MAXIMUM          = 0x762F, /**< Storage type: WFDint[2], Read only */
  WFD_PORT_PARTIAL_REFRESH_ENABLE           = 0x7630, /**< Storage type: WFDPartialRefresh, Read-write */
  WFD_PORT_PARTIAL_REFRESH_RECTANGLE        = 0x7631, /**< Storage type: WFDint[4], Read-write 
                                                           Destination rectangle (for LCM or Mem) */
  WFD_PORT_PIPELINE_ID_COUNT                = 0x7632, /**< Storage type: WFDint, Read only */
  WFD_PORT_BINDABLE_PIPELINE_IDS            = 0x7633, /**< Storage type: WFDint[], Read only */
  WFD_PORT_PROTECTION_ENABLE                = 0x7634, /**< Storage type: WFDboolean, Read-write
                                                           \remark This attribute is current not supported by MTK implementation. 
                                                           */
  WFD_PORT_SYNC_ENABLE_MTK                  = 0x7635, /**< <b>[MTK]</b> Storage type: WFDboolean, Read-write. Default: WFD_FALSE. \n
                                                           WFD_TRUE to enable, o.w to disable.  
                                                           */
  WFD_PORT_ASYNC_COMMIT_MTK                 = 0x7636, /**< <b>[MTK]</b> Storage type: WFDboolean, Read-write. Default: WFD_FALSE. \n
                                                           WFD_TRUE, to enable async call behaviors when invoking wfdDeviceCommit(). wfdDeviceCommit() does not block 
                                                                     the calling thread but calls back if callback function is registered. \n
                                                           WFD_FALSE, to enable blocking call behaviors when invoking wfdDDeviceCommit(). The calling 
                                                                      thread will be blocked (not busy looping) til wfdDeviceCommit() is finished what needs to be done.\n
                                                           */
  WFD_PORT_CALLBACK_MTK                     = 0x7637, /**< <b>[MTK]</b> Storage type: WFDint[4], Read-write. The 4-tuple is (event, cb_func, cb_param, enable). \n
                                                           event is of type WFDEventType, which means the registered cb_func is invoked when this event happens. \n
                                                           cb_func is of type void (*cb_func)(WFDEventType, void*).\n
                                                           cb_param is of type void* and is passed back to cb_func as the single parameter.\n
                                                           enable is of type WFDboolean. WFD_TRUE to enable this callback function, WFD_FALSE to disable this callback function.\n
                                                           */

  WFD_PORT_SUPPORTED_CALLBACK_COUNT_MTK     = 0x7638, /**< <b>[MTK]</b> Storage type: WFDint, Read-only.\n
                                                           */

  WFD_PORT_CONCURRENT_MEMOUT_DEST_RECTANGLE_MTK  = 0x7639, /**< <b>[MTK]</b> Storage type: WFDint[4], Read-write 
                                                           used for Blt+Flatten to set the mem-out destination rectangle */
                                                           
  WFD_PORT_ROI_RECTANGLE_MTK                     = 0x763A, /**< <b>[MTK]</b> Storage type: WFDint[4], Read-write 
                                                           Set the ROI on the ROI coordinate*/

  WFD_PORT_DO_BLT_MTK                            = 0x763B, /**< <b>[MTK]</b> Storage type: WFDboolean, Read-write. Set True to request blt result to output device, ex LCM or Memory. */
  WFD_PORT_CONCURRENTLY_MEMORY_OUT_MTK           = 0x763C, /**< <b>[MTK]</b> Storage type: WFDboolean, Read-write. Set True to request blt and memory out at the same time */

  WFD_PORT_TARGET_IMAGE                          = 0x763D, /**< <b>[MTK]</b> Storage type: WFDEGLImage, Read-write */

  WFD_PORT_ABORT_ACT                             = 0x763E, /**< <b>[MTK]</b> Storage type: WFDboolean, Write only. Call this to abort current wfd port action */

  WFD_PORT_DEVICE_PPI_MTK                        = 0x763F, /**< <b>[MTK]</b> Storage type: WFDint, Read-only. */
                                                                

  WFD_PORT_ATTRIB_FORCE_32BIT                    = 0x7FFFFFFF
} WFDPortConfigAttrib;

typedef enum
{ WFD_PORT_TYPE_INTERNAL                    = 0x7660,
  WFD_PORT_TYPE_COMPOSITE                   = 0x7661,
  WFD_PORT_TYPE_SVIDEO                      = 0x7662,
  WFD_PORT_TYPE_COMPONENT_YPbPr             = 0x7663,
  WFD_PORT_TYPE_COMPONENT_RGB               = 0x7664,
  WFD_PORT_TYPE_COMPONENT_RGBHV             = 0x7665,
  WFD_PORT_TYPE_DVI                         = 0x7666,
  WFD_PORT_TYPE_HDMI                        = 0x7667,
  WFD_PORT_TYPE_DISPLAYPORT                 = 0x7668,
  WFD_PORT_TYPE_OTHER                       = 0x7669,

  WFD_PORT_TYPE_MEMORY_OUTPUT_MTK           = 0x766A, /**< <b>[MTK]</b> For output to memory only device, we added this port type. */

  WFD_PORT_TYPE_FORCE_32BIT                 = 0x7FFFFFFF
} WFDPortType;

typedef enum
{ WFD_POWER_MODE_OFF                        = 0x7680,
  WFD_POWER_MODE_SUSPEND                    = 0x7681,
  WFD_POWER_MODE_LIMITED_USE                = 0x7682,
  WFD_POWER_MODE_ON                         = 0x7683,
  WFD_POWER_MODE_FORCE_32BIT                = 0x7FFFFFFF
} WFDPowerMode;

typedef enum
{ WFD_PARTIAL_REFRESH_NONE                  = 0x7690,
  WFD_PARTIAL_REFRESH_VERTICAL              = 0x7691,
  WFD_PARTIAL_REFRESH_HORIZONTAL            = 0x7692,
  WFD_PARTIAL_REFRESH_BOTH                  = 0x7693,
  WFD_PARTIAL_REFRESH_FORCE_32BIT           = 0x7FFFFFFF
} WFDPartialRefresh;

typedef enum
{ WFD_DISPLAY_DATA_FORMAT_NONE              = 0x76A0,
  WFD_DISPLAY_DATA_FORMAT_EDID_V1           = 0x76A1,
  WFD_DISPLAY_DATA_FORMAT_EDID_V2           = 0x76A2,
  WFD_DISPLAY_DATA_FORMAT_DISPLAYID         = 0x76A3,
  WFD_DISPLAY_DATA_FORMAT_FORCE_32BIT       = 0x7FFFFFFF
} WFDDisplayDataFormat;

typedef enum
{ WFD_ROTATION_SUPPORT_NONE                 = 0x76D0,
  WFD_ROTATION_SUPPORT_LIMITED              = 0x76D1,
  WFD_ROTATION_SUPPORT_FORMAT_FORCE_32BIT   = 0x7FFFFFFF
} WFDRotationSupport;

typedef enum
{ WFD_PIPELINE_ID                           = 0x7720, /**< storage type: WFDint, read-only, default: */
  WFD_PIPELINE_PORTID                       = 0x7721, /**< storage type: WFDint, read-only, default: */
  WFD_PIPELINE_LAYER                        = 0x7722, /**< storage type: WFDint, read-only, default: */
  WFD_PIPELINE_SHAREABLE                    = 0x7723, /**< storage type: WFDBoolean, read-only, default: */
  WFD_PIPELINE_DIRECT_REFRESH               = 0x7724, /**< storage type: WFDBoolean, read-only, default: */
  WFD_PIPELINE_MAX_SOURCE_SIZE              = 0x7725, /**< storage type: WFDint[2], read-only, default: */
  WFD_PIPELINE_SOURCE_RECTANGLE             = 0x7726, /**< storage type: WFDint[4], read-write, default: (0,0,0,0). */
  WFD_PIPELINE_FLIP                         = 0x7727, /**< storage type: WFDBoolean, read-write, default: WFD_FALSE. */
  WFD_PIPELINE_MIRROR                       = 0x7728, /**< storage type: WFDBoolean, read-write, default: WFD_FALSE. */
  WFD_PIPELINE_ROTATION_SUPPORT             = 0x7729, /**< storage type: WFDRotationSupport, read-only, default: */
  WFD_PIPELINE_ROTATION                     = 0x772A, /**< storage type: WFDint, read-write, default: 0. */
  WFD_PIPELINE_SCALE_RANGE                  = 0x772B, /**< storage type: WFDfloat[2], read-only, default: */
  WFD_PIPELINE_SCALE_FILTER                 = 0x772C, /**< storage type: WFDScaleFilter, read-write, default: NONE. 
                                                           \remark This attrib is not supported in MTK implementation. So the destination rectangle must 
                                                                   be of the same size as source rectangle (before rotation). */
  WFD_PIPELINE_DESTINATION_RECTANGLE        = 0x772D, /**< storage type: WFDint[4], read-write, default: (0,0,0,0). */
  WFD_PIPELINE_TRANSPARENCY_ENABLE          = 0x772E, /**< storage type: WFDTransparency, read-write, default: NONE. */
  WFD_PIPELINE_GLOBAL_ALPHA                 = 0x772F, /**< storage type: WFDint, read-write, default: 0xFF. 
                                                           \remark The original storage type is WFDfloat but it is not supported by MTK implementation. 
                                                           */
  WFD_PIPELINE_DITHERING_ENABLE_MTK         = 0x7730, /**< <b>[MTK]</b> storage type: WFDBoolean, read-write, default: WFD_FALSE. \n
                                                           WFD_TRUE, to enable spatial dithering when in color conversion stage. 
                                                           */
  WFD_PIPELINE_SOURCE_COLOR_KEY_MTK         = 0x7731, /**< <b>[MTK]</b> storage type: WFDint, read-write, default: 0x0. \n
                                                           Though WFD have wfdSetPipelineTSColor() API function to set TS color, we provide another approach.
                                                           Caller shall make sure the format of color key  is the same as layer frame buffer.
                                                           */
  WFD_PIPELINE_DC_ENABLE_MTK                = 0x7732, /**< <b>[MTK]</b> storage type: WFDBoolean, read-write, default: WFD_FALSE. \n
															              WFD_TRUE, to enable direct couple to MDP. For MT6268.
															              */
  WFD_PIPELINE_FAST_ROTATOR_ENABLE_MTK      = 0x7733, /**< <b>[MTK]</b> storage type: WFDBoolean, read-write, default: WFD_FALSE. \n
															              WFD_TRUE, to enable fast rotator. For MT6253.
															              */
  // TODO: RGB BGR byte swap
  WFD_PIPELINE_ATTRIB_FORCE_32BIT           = 0x7FFFFFFF
} WFDPipelineConfigAttrib;

typedef enum
{ WFD_SCALE_FILTER_NONE                     = 0x7760,
  WFD_SCALE_FILTER_FASTER                   = 0x7761,
  WFD_SCALE_FILTER_BETTER                   = 0x7762,
  WFD_SCALE_FILTER_FORCE_32BIT              = 0x7FFFFFFF
} WFDScaleFilter;

typedef enum
{ WFD_TRANSPARENCY_NONE                     = 0,
  WFD_TRANSPARENCY_SOURCE_COLOR             = (1 << 0), //enable source color key
  WFD_TRANSPARENCY_GLOBAL_ALPHA             = (1 << 1), //enable constan alpha blending (layer_control_register->alpha)
  WFD_TRANSPARENCY_SOURCE_ALPHA             = (1 << 2), //enable pixel alpha blending (content's alpha channel)
  WFD_TRANSPARENCY_MASK                     = (1 << 3),
  WFD_TRANSPARENCY_FORCE_32BIT              = 0x7FFFFFFF
} WFDTransparency;

typedef enum
{ WFD_TSC_FORMAT_UINT8_RGB_8_8_8_LINEAR     = 0x7790,
  WFD_TSC_FORMAT_UINT8_RGB_5_6_5_LINEAR     = 0x7791,
  WFD_TSC_FORMAT_FORCE_32BIT                = 0x7FFFFFFF
} WFDTSColorFormat;

typedef enum
{ WFD_TRANSITION_INVALID                    = 0x77E0,
  WFD_TRANSITION_IMMEDIATE                  = 0x77E1,
  WFD_TRANSITION_AT_VSYNC                   = 0x77E2,
  WFD_TRANSITION_FORCE_32BIT                = 0x7FFFFFFF
} WFDTransition;

typedef struct
{ WFDint offsetX;
  WFDint offsetY;
  WFDint width;
  WFDint height;
} WFDRect;


/* Device */

WFD_API_CALL WFDint WFD_APIENTRY
    wfdEnumerateDevices(WFDint *deviceIds,
                        WFDint deviceIdsCount,
                        const WFDint *filterList) WFD_APIEXIT;

WFD_API_CALL WFDDevice WFD_APIENTRY
    wfdCreateDevice(WFDint deviceId,
                    const WFDint *attribList) WFD_APIEXIT;

WFD_API_CALL WFDErrorCode WFD_APIENTRY
    wfdDestroyDevice(WFDDevice device) WFD_APIEXIT;

WFD_API_CALL void WFD_APIENTRY
    wfdDeviceCommit(WFDDevice device,
                    WFDCommitType type,
                    WFDHandle handle) WFD_APIEXIT;


#ifdef __cplusplus
}
#endif

#endif /* _WFD_H_ */
