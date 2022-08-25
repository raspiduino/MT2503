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
 * 03 08 2012 yinli.liang
 * removed!
 * .
 *
 * 03 01 2012 yinli.liang
 * removed!
 * .
 *
 * 01 05 2012 xiaoyong.ye
 * removed!
 * Cancel the timer and blt the last blt request immediately if has in wfcDeactivate() for fast exit automode.
 *
 * 10 27 2011 yinli.liang
 * removed!
 * .
 *
 * 08 10 2011 zifeng.qiu
 * removed!
 * .
 *
 * 07 06 2011 bin.han
 * removed!
 * .
 *
 * 06 08 2011 bin.han
 * removed!
 * .
 *
 * 06 08 2011 bin.han
 * removed!
 * .
 *
 * 06 02 2011 matthew.chen
 * removed!
 * Check in slim-ed DDv2 to Maui
 *
 * 06 01 2011 bin.han
 * removed!
 * RAM size reduction
 *
 * 05 23 2011 zifeng.qiu
 * removed!
 * Revise timer-insert-mechanism.
 *
 * 05 20 2011 zifeng.qiu
 * removed!
 * .
 *
 * 05 11 2011 tianshu.qiu
 * removed!
 * .
 *
 * 04 22 2011 bin.han
 * removed!
 * .
 *
 * 04 21 2011 bin.han
 * removed!
 * .
 *
 * 04 08 2011 bin.han
 * removed!
 * .
 *
 * 03 12 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 11 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 07 2011 chelun.tsai
 * removed!
 * wfd header move to hal
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

#ifndef __WFC_INTERNAL_H__
#define __WFC_INTERNAL_H__

/******************************************************************************
 * Include directives
 ******************************************************************************/
#include <wfc\wfc.h>
#include <wfc\wfcext.h>

#include "common\owftypes.h"
#include "common\owfnativestream.h"
#include "common\owfimage.h"

#include "wfd\inc\wfd.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"


/******************************************************************************
 * Utilities
 ******************************************************************************/
#define WFC_ASSERT(x)                       

/******************************************************************************
 * Macro definitions
 ******************************************************************************/
#define RGB_NUM_BYTES                       (sizeof(WFCuint8) * 4)

/**
 *  \def WFC_ENGINE_MAX_COUNT
 *  Max count of engines that are managed by this single WFC device.
 */
#define WFC_ENGINE_MAX_COUNT                (2)

/**
 *  \def WFC_CONTEXT_MAX_COUNT
 *  Max count of contexts that can be created on this WFC device.
 */
#ifdef DUAL_LCD
#define WFC_CONTEXT_MAX_COUNT               (3)
#else
#define WFC_CONTEXT_MAX_COUNT               (2)
#endif

#define WFC_MAX_VIDEO_LAYER_COUNT           (2)     ///VT is the worst case

/**
 *  \def WFC_CONTEXT_MAX_CALLBACK_COUNT
 *  Max count of callback functions that can be registered on a single context.
 *  \todo decrease this number when integration for code size shrinking.
 */
// MM need 2 sources in VT. GDI need WFC_CONTEXT_MAX_INSERTED_ELEMENT+1 sources. The additional source for GDI is used for source switching.
//#define WFC_CONTEXT_MAX_SOURCE              (WFC_CONTEXT_MAX_INSERTED_ELEMENT+10)
#define WFC_MAX_SOURCE_NUMBER               ((WFC_CONTEXT_MAX_INSERTED_ELEMENT * WFC_CONTEXT_MAX_COUNT * 2) + WFC_MAX_VIDEO_LAYER_COUNT + 5)   /// +5 for VT worst case, others for GDI


/**
 *  \def WFC_ELEMENT_MAX_COUNT
 *  Max count of elements that can be created on this WFC device.
 */
#define WFC_ELEMENT_MAX_COUNT               ((WFC_CONTEXT_MAX_INSERTED_ELEMENT * WFC_CONTEXT_MAX_COUNT) + WFC_MAX_VIDEO_LAYER_COUNT)  

/**
 *  \def WFC_DEVICE_ID_DEFAULT
 *  The Device ID of this single WFC Device.
 */
#define WFC_DEVICE_ID_DEFAULT               (0x2454)



/******************************************************************************
 * Type definitions
 ******************************************************************************/
typedef struct
{
  WFCboolean            useStream; /**< WFC_TRUE to use a stream... */
  //union 
  //{
    OWF_IMAGE           image;
    OWFNativeStreamType stream; /**< This is only a handle. */ // KeTing feels sorry...
  //}                     source;

  WFCContext            ctxt; /**< To keep where this source is created from. */
  WFCElement            element; /**< To keep which element is using this source. */

  // KeTing: For stream source only
  OWFNativeStreamBuffer _streamBuffer; /**< To keep what buffer is now acquried by WFC */
  WFCboolean            _isChangingBuffer; /**< If this source is changing buffer */
  WFCboolean            _needChangeBuffer; /**< Indicate if the stream buffer need change */
  WFCboolean            _isCreated;
} WFCSourceConfig;

typedef enum
{
  WFC_DEVICE_STATE_DESTROYED    = 0x0, 
  WFC_DEVICE_STATE_CREATED      = 0x1, 
} WFCDeviceState;

typedef struct 
{
  /* private section */
  WFCHandle       _engines[WFC_CONTEXT_MAX_COUNT]; /**< Here we record context -> engine mapping. They are supposed to be WFDDevices... */
  WFCContext      _createdContexts[WFC_CONTEXT_MAX_COUNT]; /**< Created Contexts are put here... */
  WFCDeviceState  _state;
  WFCErrorCode    _lastErrorCode;
} WFCDeviceConfig;

typedef struct 
{
  WFCAutonomousSyncTriggerMTK syncTrigger;
  WFCuint         period;
  WFCElement      element;
} WFCAutonomousSync;

typedef enum
{
    WFC_AUTONOMOUS_STATE_OFF             = 0x0, 
    WFC_AUTONOMOUS_STATE_TURNING_OFF     = 0x1, 
    WFC_AUTONOMOUS_STATE_ON              = 0x2, 
}WFCAutonomousState;



typedef struct 
{
  /* User read-only attrib */
  WFCContextType      type;

  /* User read-write attrib */
  WFCCtxtRWAttrib    *cachedRWAttrib;
  WFCCtxtRWAttrib    *capturedRWAttrib;
  WFCCtxtRWAttrib     __RWAttrib[2]; /**< The RW attribute pool */

  /* private section */
  WFCHandle           _engine; /**< The handle to a WFDDevice this context is mapped. */
  WFCHandle           _port; /**< The handle to a WFDPort this context is mapped. */

  // KeTing: Autonomous mode related fields
  kal_timerid         _timer; /**< The timer used to self trigger. */
  WFCAutonomousState  _autonomousMode;
  OWF_RECTANGLE       _autoModeRoiRect;
  WFCboolean          _autoModeCommitLatched;
  
  WFCboolean          _busy;
} WFCContextConfig;



typedef struct
{
  /* User read-write attrib */
  WFCElementRWAttrib *cachedRWAttrib;
  WFCElementRWAttrib *capturedRWAttrib;
  WFCElementRWAttrib  __RWAttrib[2]; /**< The RW attribute pool */
  
  /* private section */
  WFCContext          _context;
} WFCElementConfig;



// TODO: [m] KeTing: Move this to debug paradise
typedef enum
{
   WFCDBG_________________ERROR_HAPPEN = 1,
   WFCDBG____CREATE_________ONSRN_CNXT,
   WFCDBG____CREATE________OFFSRN_CNXT,
   WFCDBG____DESTROY______________CNXT,
   WFCDBG____CREATE_IMG____________SRC,
   WFCDBG____CREATE_IMG________SRC_END,
   WFCDBG____DESTROY_______________SRC,
   WFCDBG____DESTROY__________SRC_DONE,
   WFCDBG____CREATE____________ELEMENT,
   WFCDBG____INSERT____________ELEMENT,
   WFCDBG____DESTROY___________ELEMENT,
   
   WFCDBG____REMOVE____________ELEMENT,
     
   WFCDBG_______________________COMMIT,
   WFCDBG____AUTO_MODE__________COMMIT,
   WFCDBG______________________COMPOSE,
   WFCDBG____COMPOSE____________DEVICE,
   WFCDBG____COMPOSE______________PORT,
   WFCDBG____COMPOSE___CREATE_PIPELINE,
   WFCDBG____COMPOSE_____BIND_PIPELINE,

   // KeTing: For _wcf_config_wfd
   WFCDBG____CONFIG_____________DEVICE,
   WFCDBG____CONFIG_______________PORT,
   WFCDBG____CONFIG____CREATE_PIPELINE,
   WFCDBG____CONFIG______BIND_PIPELINE,

   // KeTing: For semophore
   WFCDBG____SEMA_________LOCK_NO_WAIT,
   WFCDBG____SEMA________LOCK_INFINITE,
   WFCDBG____SEMA____LOCK_IN_EXCEPTION,
   WFCDBG____SEMA__UNLOCK_IN_EXCEPTION,
   WFCDBG____SEMA_______________UNLOCK,

   // KeTing: Callbacks
   WFCDBG____CALLBACK___________ENGINE,

   // KeTing: Autonomous mode
   WFCDBG____AUTO_____________ACTIVATE,
   WFCDBG____AUTO___________DEACTIVATE,
   WFCDBG____AUTO_BLT_____________HISR,
   WFCDBG____AUTO_REASELE_DONE____HISR,
   WFCDBG____AUTO__ACT__HISR__IN_DEACT,//Xiaoyong: added for activate auto mode hisr in wfcDeactivate for fast exit auto mode
   WFCDBG____AUTO______HISR_DROP_FRAME,
   WFCDBG____AUTO________CHANGE_BUFFER,
   WFCDBG____AUTO__CONFIG_AUTO_TRIGGER
}WFCDbgIdEnum;



/******************************************************************************
 * Function prototypes
 ******************************************************************************/
// Functions from wfcapi.c
void _wfc_set_error(WFCErrorCode error);
void _wfc_config_wfd_and_commit(WFCContextConfig *pContext, WFCboolean wait);
WFCboolean _wfc_is_wfd_busy(WFCContextConfig *pContext);
void _wfc_set_context_frame_done_event(WFCContextConfig *pContext, WFCboolean setEvent);
kal_bool _wfc_check_device(WFCDevice hDevice);
kal_bool _wfc_check_handle(WFCHandle handle);
//void _wfc_retrieve_context_frame_done_event(WFCContextConfig *pContext);
//void _wfc_retrieve_any_frame_done_event();


#define WFC_DBG_SUPPORT
#if defined(WFC_DBG_SUPPORT)
// TODO: [m] KeTing: Move this to debug paradise
 void wfcTrace(WFCDbgIdEnum id);
 void wfcTrace3(WFCDbgIdEnum id, WFCuint value0, WFCuint value1, WFCuint value2);
#else
#define wfcTrace(id)
#define wfcTrace3(id, value0, value1, value2);
#endif


// Functions from wfc_autonomous.c
void _wfc_autonomous_mode_blt_hisr(void);
void _wfc_autonomous_release_done_hisr(void);
WFCboolean _wfc_regist_autonomous_mode(WFCContextConfig *pContext);
WFCboolean _wfc_deregist_autonomous_mode(WFCContextConfig *pContext);
WFCboolean _wfc_clear_autonomous_sync_trigger(WFCContextConfig* pContext);
void _wfc_stream_event_hdlr(OWFNativeStreamType stream, OWFNativeStreamEvent event, void *param);
void _wfc_autonomous_frame_done_callback(WFCContextConfig *pContext);
WFCboolean _wfc_autonomous_commit_callback(WFCContextConfig *pContext);
void _wfc_autonomous_activate_hisr_in_deactivate(WFCContextConfig *pContext);

#endif /* __WFC_INTERNAL_H__ */

