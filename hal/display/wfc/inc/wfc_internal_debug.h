/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010-2011
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
 *    wfc_internal.h
 *
 * Project:
 * --------
 *    MAUI/HAL/WFC
 *
 * Description:
 * ------------
 *    This file is the internal header file for WFC implementation.
 *
 * Author:
 * -------
 * -------
 *    
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 07 17 2012 haitao.shang
 * removed!
 * .
 *
 * 10 27 2011 yinli.liang
 * removed!
 * .
 *
 * 07 06 2011 bin.han
 * removed!
 * .
 *
 * 06 30 2011 zifeng.qiu
 * removed!
 * .
 *
 * 06 01 2011 bin.han
 * removed!
 * RAM size reduction
 *
 * 05 30 2011 zifeng.qiu
 * removed!
 * .
 *
 * 05 23 2011 zifeng.qiu
 * removed!
 * Revise timer-insert-mechanism.
 *
 * 04 11 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 18 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 18 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 07 2011 chelun.tsai
 * removed!
 * wfd header move to hal.
 *
 * 03 04 2011 tianshu.qiu
 * removed!
 * .
 *
 * 02 23 2011 bin.han
 * removed!
 * .
 *
 * 02 15 2011 tianshu.qiu
 * removed!
 * .
 *
 * 01 17 2011 ke-ting.chen
 * removed!
 * Improve commit process.
 *
 * 01 07 2011 ke-ting.chen
 * removed!
 * Check-in VT support and timer frame insertion mechanism.
 *
 * 12 28 2010 ke-ting.chen
 * removed!
 * Check-in fast rotator mechanism for MT6253 and fix autonomous mode behavior for VT.
 *
 * 12 25 2010 ke-ting.chen
 * removed!
 * Resolve MT6253 60Qbit assert fail in wfcCommit.
 *
 * 12 22 2010 sophie.chen
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WFC_INTERNAL_DEBUG_H__
#define __WFC_INTERNAL_DEBUG_H__

/******************************************************************************
 * Include directives
 ******************************************************************************/

#include "wfc\inc\wfc_internal.h"

typedef struct 
{
  WFCbitfield     transparencyType;
  WFCint          globalAlpha;
  WFCuint         sourceColorKey;
  WFCboolean      enableSpatialDithering;
    OWF_RECTANGLE   destinationRect;
    WFCSourceConfig* source;
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
    WFCboolean      isDCLayer;
} WFCElementRWAttrib_;

typedef struct
{
    /* User read-write attrib */
    WFCElementRWAttrib_ *cachedRWAttrib;
    WFCElementRWAttrib_ *capturedRWAttrib;
    WFCElementRWAttrib_  __RWAttrib[2]; /**< The RW attribute pool */

    /* private section */
    WFCContext          _context;
} WFCElementConfig_;

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
    WFCElementConfig_* _insertedElements[WFC_CONTEXT_MAX_INSERTED_ELEMENT]; /**< The handle array of WFCElements which are inserted into this context. */

    // KeTing: For autonomous mode
    WFCboolean        enableVsync;
    WFCuint           paletteTable;

  WFCCallbackType   gdiCallbacks[WFC_CONTEXT_GDI_CALLBACK_COUNT];


  //WFCAutonomousSync autonomousSync;  
  WFCAutonomousSyncTriggerMTK syncTrigger;
  WFCuint           period; /*real frame period*/
  WFCElement        sync_element;
  WFCint            currRefreshRate;
  WFCCallbackType   mmCallbacks[WFC_CONTEXT_MM_CALLBACK_COUNT];
} WFCCtxtRWAttrib_;

typedef struct 
{
    /* User read-only attrib */
    WFCContextType      type;

    /* User read-write attrib */
    WFCCtxtRWAttrib_    *cachedRWAttrib;
    WFCCtxtRWAttrib_    *capturedRWAttrib;
    WFCCtxtRWAttrib_     __RWAttrib[2]; /**< The RW attribute pool */

    /* private section */
    WFCHandle           _engine; /**< The handle to a WFDDevice this context is mapped. */
    WFCHandle           _port; /**< The handle to a WFDPort this context is mapped. */

    // KeTing: Autonomous mode related fields
    kal_timerid         _timer; /**< The timer used to self trigger. */
    WFCAutonomousState  _autonomousMode;
    OWF_RECTANGLE       _autoModeRoiRect;
    WFCboolean          _autoModeCommitLatched;
    //WFCboolean          _syncToProvider; // KeTing: move this to context attribute for more customization flexibility

    WFCboolean          _busy;
} WFCContextConfig_;

typedef struct
{
    WFCDeviceConfig*   Device;
    WFCContextConfig_* ContextLCD0;
    WFCContextConfig_* ContextLCD1;
    WFCContextConfig_* ContextMem;
} WFCDbgStructure;


#endif /* __WFC_INTERNAL_H__ */

