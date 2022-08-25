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
 *    wfcapi.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    MTK implemented OpenWF Composition.
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
 * 01 23 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 *
 * 11 07 2012 chrono.wu
 * removed!
 * .
 * 
 * 07 24 2012 haitao.shang
 * removed!
 * .
 *
 * 07 18 2012 haitao.shang
 * removed!
 * .
 *
 * 07 18 2012 haitao.shang
 * removed!
 * .
 *
 * 07 17 2012 haitao.shang
 * removed!
 * .
 *
 * 05 28 2012 jody.li
 * removed!
 * .
 *
 * 05 25 2012 jody.li
 * removed!
 * .
 *
 * 04 12 2012 xiaoyong.ye
 * removed!
 * Support ARGB6666 transform from DDv2 to LWF.
 *
 * 04 11 2012 xiaoyong.ye
 * removed!
 * Fix build error.
 *
 * 04 11 2012 xiaoyong.ye
 * removed!
 * Support ARGB6666 transform from DDv2 to LWF.
 *
 * 03 08 2012 yinli.liang
 * removed!
 * .
 *
 * 02 23 2012 yinli.liang
 * removed!
 * .
 *
 * 02 10 2012 haitao.shang
 * removed!
 * .
 *
 * 01 05 2012 xiaoyong.ye
 * removed!
 * Cancel the timer and blt the last blt request immediately if has in wfcDeactivate() for fast exit automode.
 *
 * 12 25 2011 xiaoyong.ye
 * removed!
 * Add pPort .
 *
 * 12 25 2011 xiaoyong.ye
 * removed!
 * BW adjust for MT6256 more than one layer in 3D MMI scenario.
 *
 * 12 08 2011 yinli.liang
 * removed!
 * .
 *
 * 11 10 2011 yinli.liang
 * removed!
 * .
 *
 * 11 03 2011 yinli.liang
 * removed!
 * .
 *
 * 10 27 2011 yinli.liang
 * removed!
 * Remove not used temp variable: source and sourceCfg
 *
 * 10 27 2011 yinli.liang
 * removed!
 * .
 *
 * 10 25 2011 xiaoyong.ye
 * removed!
 * Remove user_version_code for FlattenGetOwnership().
 *
 * 10 24 2011 xiaoyong.ye
 * removed!
 * To mask flatten_api.h with #if defined(__MTK_TARGET__) when building MoDIS, to avoid building error.
 *
 * 10 20 2011 xiaoyong.ye
 * removed!
 * .
 *
 * 10 14 2011 bin.han
 * removed!
 * .
 *
 * 10 12 2011 dong.guo
 * removed!
 * .
 *
 * 10 12 2011 dong.guo
 * removed!
 * .
 *
 * 09 06 2011 haitao.shang
 * removed!
 * .
 *
 * 09 02 2011 zifeng.qiu
 * removed!
 * .
 *
 * 08 10 2011 zifeng.qiu
 * removed!
 * .
 *
 * 08 04 2011 bin.han
 * removed!
 * .
 *
 * 07 26 2011 zifeng.qiu
 * removed!
 *   DDv2 On Modis Check In.
 *
 * 07 21 2011 bin.han
 * removed!
 * .
 *
 * 07 13 2011 bin.han
 * removed!
 * .
 *
 * 07 08 2011 bin.han
 * removed!
 * Fix LOW_COST
 *
 * 07 06 2011 bin.han
 * removed!
 * .
 *
 * 07 05 2011 zifeng.qiu
 * removed!
 * .
 *
 * 07 04 2011 bin.han
 * removed!
 * .
 *
 * 07 01 2011 bin.han
 * removed!
 * LOW_COST_SUPPORT
 *
 * 06 28 2011 tianshu.qiu
 * removed!
 * .
 *
 * 06 23 2011 bin.han
 * removed!
 * .
 *
 * 06 22 2011 bin.han
 * removed!
 * .
 *
 * 06 15 2011 bin.han
 * removed!
 * cleanup code and add comment
 *
 * 06 09 2011 zifeng.qiu
 * removed!
 * Add error handling for DDv2.
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
 * .
 *
 * 05 23 2011 zifeng.qiu
 * removed!
 * Revise timer-insert-mechanism.
 *
 * 05 20 2011 zifeng.qiu
 * removed!
 * .
 *
 * 05 18 2011 zifeng.qiu
 * removed!
 * Event Group Slim.
 *
 * 05 18 2011 zifeng.qiu
 * removed!
 * Event Group Slim.
 *
 * 05 13 2011 zifeng.qiu
 * removed!
 * .
 *
 * 05 13 2011 bin.han
 * removed!
 * .
 *
 * 05 12 2011 zifeng.qiu
 * removed!
 * .
 *
 * 05 11 2011 zifeng.qiu
 * removed!
 * Resolve lcd_sleep_in & out racing condition.
 *
 * 05 11 2011 tianshu.qiu
 * removed!
 * .
 *
 * 05 11 2011 tianshu.qiu
 * removed!
 * .
 *
 * 04 24 2011 tianshu.qiu
 * removed!
 * .
 *
 * 04 22 2011 tianshu.qiu
 * removed!
 * .
 *
 * 04 21 2011 bin.han
 * removed!
 * .
 *
 * 04 21 2011 bin.han
 * removed!
 * .
 *
 * 04 19 2011 matthew.chen
 * removed!
 * .
 *
 * 04 18 2011 tianshu.qiu
 * removed!
 * .
 *
 * 04 18 2011 matthew.chen
 * removed!
 * Fix potential racing issue for 1112MP by adding WFC API semaphore in WFC_Lock & WFC_Unlock.
 *
 * 04 15 2011 tianshu.qiu
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
 * 04 14 2011 zifeng.qiu
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
 * 04 07 2011 tianshu.qiu
 * removed!
 * .
 *
 * 04 01 2011 zifeng.qiu
 * removed!
 * .
 *
 * 03 18 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 15 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 14 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 14 2011 tianshu.qiu
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
 * 03 09 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 08 2011 ct.fang
 * removed!
 * .
 *
 * 03 07 2011 chelun.tsai
 * removed!
 * wfd header move to hal.
 *
 * 03 05 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 04 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 03 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 02 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 02 2011 tianshu.qiu
 * removed!
 * .
 *
 * 02 23 2011 bin.han
 * removed!
 * .
 *
 * 02 18 2011 tianshu.qiu
 * removed!
 * .
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

/*! \ingroup wfc
 *  \file wfcapi.c
 *  \brief OpenWF Composition SI, API implementation.
 *
 *  For function documentations, see OpenWF Composition specification 1.0
 *
 *  The general layout of an API function is:
 *  - grab API mutex (lock API)
 *  - check parameter validity
 *  - invoke implementation function (WFD_...)
 *  - unlock API
 *  - return
 *
 */
/******************************************************************************
 * Include directives
 ******************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <wfc\wfc.h>
#include <wfc\wfcext.h>

#include "common\owftypes.h"
#include "common\owfnativestream.h"
#include "common\owfimage.h"

#include "drv_features_display.h"
#include "drv_sw_features_display.h"

#include "drv_hisr.h"

#include "rgb_rotator_api.h"
#include "yuv_rotator_api.h"
#include "lcd_sw_inc.h"

#include "egl\eglext.h"
#include "wfd\inc\wfd.h"

#include "wfc\inc\wfc_internal.h"
#include "wfc\inc\wfc_mm_api.h"
#include "wfc\inc\wfc_internal_debug.h"

#include "debug\inc\lcd_catcher_log.h"

#include "wfd\inc\wfd_common.h"

#include "kal_release.h"

#if defined(__RF_DESENSE_TEST__)
#include "rf_desense_test.h"
#endif

#if defined(__MTK_TARGET__)
#include "flatten_api.h"
#endif

#if defined(__MTK_TARGET__) && defined(MT6256)
#include "emi_sw.h"
#endif

#define wfdGetError(x) WFD_ERROR_NONE

/******************************************************************************
 * Utilities
 ******************************************************************************/

#define GET_CONTEXT(c, h, x) \
    do { \
    c = (WFCContextConfig*)(h); \
    if (_wfc_check_handle((WFCHandle)(c)) == KAL_FALSE) \
        return (x); \
    } while (0)

#define GET_CONTEXT_NR(c, h) \
    do { \
    c = (WFCContextConfig*)(h); \
    if (_wfc_check_handle((WFCHandle)(c)) == KAL_FALSE) \
        return; \
    } while (0)

#define GET_ELEMENT(e, h, x) \
    do { \
    e = (WFCElementConfig*)(h); \
    if (_wfc_check_handle((WFCHandle)(e)) == KAL_FALSE) \
        return (x); \
    } while (0)

#define GET_ELEMENT_NR(e, h) \
    do { \
    e = (WFCElementConfig*)(h); \
    if (_wfc_check_handle((WFCHandle)(e)) == KAL_FALSE) \
        return; \
    } while (0)

/******************************************************************************
 * Macro definitions
 ******************************************************************************/


/******************************************************************************
 * Local type definitions
 ******************************************************************************/
typedef enum
{
    _WFC_FRAME_DONE_EVENT_CONTEXT_NONE  = 0,
    _WFC_FRAME_DONE_EVENT_CONTEXT_LCD_0 = 0x8000000,
    _WFC_FRAME_DONE_EVENT_CONTEXT_LCD_1 = 0x4000000,
    _WFC_FRAME_DONE_EVENT_CONTEXT_FRAME_BUFFER = 0x2000000,
    _WFC_FRAME_DONE_EVENT_CONTEXT_TVOUT = 0x1000000,
    _WFC_FRAME_DONE_EVENT_CONTEXT_ALL = 0xF000000
} _WFC_FRAME_DONE_EVENT_ENUM;


/******************************************************************************
 * Local variables
 ******************************************************************************/
//static OWF_MUTEX           mutex;

static volatile kal_bool _global_data_init = KAL_FALSE;

static volatile WFCDeviceConfig _wfc_device_cfg = {0};

static volatile WFCContextConfig _wfc_context_cfg_lcd_0;
#ifdef DUAL_LCD
static volatile WFCContextConfig _wfc_context_cfg_lcd_1;
#endif
static volatile WFCContextConfig _wfc_context_cfg_frame_buffer;

static volatile WFCSourceConfig _wfc_sources[WFC_MAX_SOURCE_NUMBER];
static volatile WFCElementConfig _wfc_elements[WFC_ELEMENT_MAX_COUNT];

static volatile WFCContextConfig_* _wfc_dbg_context_lcd0;
#ifdef DUAL_LCD
static volatile WFCContextConfig_* _wfc_dbg_context_lcd1;
#endif
//static volatile WFCContextConfig_* _wfc_dbg_context_frame_buffer;

static volatile WFCDbgStructure wfc_dbg_structure;

// TODO: [o] check if we can change to use a mutex or a enh mutex.
static kal_semid _wfc_commit_mutex = KAL_NILSEM_ID;
static kal_semid _wfc_source_mutex = KAL_NILSEM_ID;
volatile WFCboolean _wfc_committed_flag = WFC_FALSE; //Xiaoyong: flag to record the blt request in auto mode
// KeTing: The frame done event groups of every context
kal_eventgrpid _owf_event = KAL_NILEVENTGRP_ID;
extern kal_bool _timer_run_status;
/******************************************************************************
 * Local functions
 ******************************************************************************/
#if defined(WFC_DBG_SUPPORT)

#if !defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__LOW_COST_SUPPORT_ULC__)
    #define WFC_DBG_ENTRY_CNT 32     
#else
    #define WFC_DBG_ENTRY_CNT 32      //Bin extend to debug
#endif

typedef struct
{
    WFCDbgIdEnum id;
    WFCuint      time;
    kal_taskid   taskid;
    WFCErrorCode wfcError;
    WFCuint      value0;
    WFCuint      value1;
    WFCuint      value2;
} WFCDbgCtrlBlk;

volatile static WFDuint _WFCDbgCnt = 0;
volatile static WFCDbgCtrlBlk _WFCDbgDat[WFC_DBG_ENTRY_CNT];

void wfcTrace(WFCDbgIdEnum id)
{
    kal_uint32 index;

    kal_uint32 mask = SaveAndSetIRQMask();
    index = _WFCDbgCnt;
    _WFCDbgCnt++;
    _WFCDbgCnt &= (WFC_DBG_ENTRY_CNT-1);
    RestoreIRQMask(mask);

    _WFCDbgDat[index].taskid = kal_get_task_self_id();
    _WFCDbgDat[index].id = id;
    _WFCDbgDat[index].wfcError = _wfc_device_cfg._lastErrorCode;
    _WFCDbgDat[index].time = drv_get_current_time();
    _WFCDbgDat[index].value0 = 0;
    _WFCDbgDat[index].value1 = 0;
    _WFCDbgDat[index].value2 = 0;
}

void wfcTrace3(WFCDbgIdEnum id, WFCuint value0, WFCuint value1, WFCuint value2)
{
  kal_uint32 index;

  kal_uint32 mask = SaveAndSetIRQMask();
  index = _WFCDbgCnt;
  _WFCDbgCnt++;
  _WFCDbgCnt &= (WFC_DBG_ENTRY_CNT-1);
  RestoreIRQMask(mask);

  _WFCDbgDat[index].id    = id;
  _WFCDbgDat[index].wfcError = _wfc_device_cfg._lastErrorCode;
  _WFCDbgDat[index].time  = drv_get_current_time();
  _WFCDbgDat[index].taskid  = kal_get_task_self_id();
  _WFCDbgDat[index].value0 = value0;
  _WFCDbgDat[index].value1 = value1;
  _WFCDbgDat[index].value2 = value2;
}
#endif


static void 
WFC_Commit_Lock(void)
{
    if (kal_query_systemInit() == KAL_TRUE)
    {
        return;
    }
    if (NULL  == _wfc_commit_mutex)
    {
        _wfc_commit_mutex = kal_create_sem("WFC_COMMIT", 1);
    }
    kal_take_sem(_wfc_commit_mutex, KAL_INFINITE_WAIT);
}

static void 
WFC_Commit_Unlock()
{
    if (kal_query_systemInit() == KAL_TRUE)
    {
        return;
    }
    if (NULL != _wfc_commit_mutex)
    {
        kal_give_sem(_wfc_commit_mutex);
    }
}

static void 
WFC_Source_Lock(void)
{
    if (kal_query_systemInit() == KAL_TRUE)
    {
        return;
    }

    if (NULL  == _wfc_source_mutex)
    {
        _wfc_source_mutex = kal_create_sem("WFC_SOURCE", 1);
    }

    kal_take_sem(_wfc_source_mutex, KAL_INFINITE_WAIT);
}

static void 
WFC_Source_Unlock()
{
    if (kal_query_systemInit() == KAL_TRUE)
    {
        //wfcTrace(WFCDBG____SEMA__UNLOCK_IN_EXCEPTION);
        return;
    }

    if (NULL != _wfc_source_mutex)
    {
        kal_give_sem(_wfc_source_mutex);
    }
}


static kal_bool _wfc_check_handle(WFCHandle handle)
{
    if (NULL == handle)
    {
        _wfc_set_error(WFC_ERROR_BAD_HANDLE);
        return KAL_FALSE;
    }
    return KAL_TRUE;
}

/**
 *  \status OK
 *  the return value is integer rotation angle (clockwise)
 */
static WFDint 
_wfc_convert_rotation_angle_to_int(WFCRotation rotation_angle)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return ((rotation_angle - WFC_ROTATION_0) * 90);
}

/**
 *  \status OK
 * The return value is TRANSPARENCY typedef for WFD
 */
static WFDbitfield 
_wfc_convert_transparency(WFCbitfield transparency)
{
    WFDbitfield ret = 0x0;

    //if (!(transparency & (~WFC_TRANSPARENCY_ELEMENT_GLOBAL_ALPHA)))
    if (transparency & WFC_TRANSPARENCY_ELEMENT_GLOBAL_ALPHA)
    {
        ret |= WFD_TRANSPARENCY_GLOBAL_ALPHA;
    }

    //if (!(transparency & (~WFC_TRANSPARENCY_SOURCE)))
    if (transparency & WFC_TRANSPARENCY_SOURCE)
    {
        ret |= WFD_TRANSPARENCY_SOURCE_ALPHA;
    }

    //if (!(transparency & (~WFC_TRANSPARENCY_SOURCE_COLOR_KEY_MTK)))
    if (transparency & WFC_TRANSPARENCY_SOURCE_COLOR_KEY_MTK)
    {
        ret |= WFD_TRANSPARENCY_SOURCE_COLOR;
    }

    return ret;
}



// KeTing: Change the context handle to wfc frame done event enum
static _WFC_FRAME_DONE_EVENT_ENUM
_wfc_convert_context_handle_to_frame_done_enum (WFCContextConfig *pContext)
{
    if (pContext == &_wfc_context_cfg_lcd_0)
    {
        return _WFC_FRAME_DONE_EVENT_CONTEXT_LCD_0;
    }
#ifdef DUAL_LCD
    else if (pContext == &_wfc_context_cfg_lcd_1)
    {
        return _WFC_FRAME_DONE_EVENT_CONTEXT_LCD_1;
    }
#endif
    else if (pContext == &_wfc_context_cfg_frame_buffer)
    {
        return _WFC_FRAME_DONE_EVENT_CONTEXT_FRAME_BUFFER;
    }
    else
    {
        return _WFC_FRAME_DONE_EVENT_CONTEXT_NONE;
    }
}


WFCboolean _wfc_check_element_inserted(WFCContextConfig* pContext, WFCElement element)
{
    kal_uint32 i = 0;
   if(pContext == NULL || element == NULL)
      return WFC_FALSE;
    
    for(i=0;i<WFC_CONTEXT_MAX_INSERTED_ELEMENT;i++)
    {
	    if (pContext->capturedRWAttrib->_insertedElements[i] == element)
	    {
			return WFC_TRUE;
	    }
	}

	 return WFC_FALSE;
}


void _wfc_rectangle_and(OWF_RECTANGLE* pRect1, OWF_RECTANGLE* pRect2, OWF_RECTANGLE* pRectResult)
{
    WFCint left, right, top, bottom, width, height;
    if ((pRect1->width == 0) || (pRect1->height == 0) || (pRect2->width == 0) || (pRect2->height == 0))
    {
        memset(pRectResult, 0, sizeof(OWF_RECTANGLE));
        return;
    }
    if (pRect1->x < pRect2->x)
        left = pRect2->x;
    else
        left = pRect1->x;
    if ((pRect1->x + pRect1->width) < (pRect2->x + pRect2->width))
        right = pRect1->x + pRect1->width;
    else
        right = pRect2->x + pRect2->width;
    if (left < right)
        width = right - left;
    else
        width = 0;
    if (pRect1->y < pRect2->y)
        top = pRect2->y;
    else
        top = pRect1->y;
    if ((pRect1->y + pRect1->height) < (pRect2->y + pRect2->height))
        bottom = pRect1->y + pRect1->height;
    else
        bottom = pRect2->y + pRect2->height;
    if (top < bottom)
        height = bottom - top;
    else
        height = 0;
    if ((width == 0) || (height == 0))
        pRectResult->x = pRectResult->y = pRectResult->width = pRectResult->height = 0;
    else
    {
        pRectResult->x = left;
        pRectResult->y = top;
        pRectResult->width = width;
        pRectResult->height = height;
    }
}


void _wfc_rectangle_or(OWF_RECTANGLE* pRect1, OWF_RECTANGLE* pRect2, OWF_RECTANGLE* pRectResult)
{
    WFCint left, right, top, bottom;
    if ((pRect1->width == 0) || (pRect1->height == 0))
    {
        memcpy(pRectResult, pRect2, sizeof(OWF_RECTANGLE));
        return;
    }
    if ((pRect2->width == 0) || (pRect2->height == 0))
    {
        memcpy(pRectResult, pRect1, sizeof(OWF_RECTANGLE));
        return;
    }
    if (pRect1->x < pRect2->x)
        left = pRect1->x;
    else
        left = pRect2->x;
    if ((pRect1->x + pRect1->width) < (pRect2->x + pRect2->width))
        right = pRect2->x + pRect2->width;
    else
        right = pRect1->x + pRect1->width;
    if (pRect1->y < pRect2->y)
        top = pRect1->y;
    else
        top = pRect2->y;
    if ((pRect1->y + pRect1->height) < (pRect2->y + pRect2->height))
        bottom = pRect2->y + pRect2->height;
    else
        bottom = pRect1->y + pRect1->height;
    pRectResult->x = left;
    pRectResult->y = top;
    pRectResult->width = right - left;
    pRectResult->height = bottom - top;
}

static void _wfc_invoke_callback(WFCContextConfig *pContext, WFCContextEventTypeMTK event)
{
    kal_uint32 i;

    // TODO: [o] set event here... 
    for (i = WFC_CONTEXT_GDI_CALLBACK_COUNT; i-- != 0; )
    {
        WFCCallbackType *pCallback = &(pContext->capturedRWAttrib->gdiCallbacks[i]);
        if ((event == pCallback->event) && 
            (NULL != pCallback->cbfunc))
        {
            pCallback->cbfunc(event, pCallback->cbparam);
        }
    }
    for (i = WFC_CONTEXT_MM_CALLBACK_COUNT; i-- != 0; )
    {
        WFCCallbackType *pCallback = &(pContext->capturedRWAttrib->mmCallbacks[i]);
        if ((event == pCallback->event) && 
            (NULL != pCallback->cbfunc))
        {
            pCallback->cbfunc(event, pCallback->cbparam);
        }
    }
}

/**
 *  \status OK
 * This function is as callback registed to WFD
 */
static void _wfc_engine_event_hdlr(WFDEventType event, void* param)
{
    kal_uint32 savedMask;
    WFCContextConfig* pContext = param;
	#if (!(defined (MT6250) || defined (MT6260) || defined (MT6261) || defined (MT2501) || defined (MT2502))) 
    kal_uint32 bCallback = 0;
	#endif
    WFC_ASSERT(NULL != param);
    
    wfcTrace(WFCDBG____CALLBACK___________ENGINE);


    // callback to user (GDI or MM)
    _wfc_invoke_callback(pContext, WFC_CONTEXT_EVENT_COMPOSITION_FINISH_ALWAYS_CALLBACK_MTK);
    if (WFC_AUTONOMOUS_STATE_ON == pContext->_autonomousMode)
    {
        // after previous commit setting is latched,  the ROI can be restored and callback can be invoked
        if (pContext->_autoModeCommitLatched == WFC_TRUE)
        {
            pContext->capturedRWAttrib->destinationRect.x += pContext->_autoModeRoiRect.x - pContext->capturedRWAttrib->roiRect.x;
            pContext->capturedRWAttrib->destinationRect.y += pContext->_autoModeRoiRect.y - pContext->capturedRWAttrib->roiRect.y;
            pContext->capturedRWAttrib->destinationRect.width = pContext->_autoModeRoiRect.width;
            pContext->capturedRWAttrib->destinationRect.height = pContext->_autoModeRoiRect.height;
            pContext->capturedRWAttrib->roiRect = pContext->_autoModeRoiRect;
            _wfc_invoke_callback(pContext, WFC_CONTEXT_EVENT_COMPOSITION_FINISH_MTK);
					#if (!(defined (MT6250) || defined (MT6260) || defined (MT6261) || defined (MT2501) || defined (MT2502))) 
                    bCallback = 1;
					#endif
			_wfc_committed_flag = WFC_FALSE; //Xiaoyong:clear the blt request in auto mode
        }
    }
    else
            {
                _wfc_invoke_callback(pContext, WFC_CONTEXT_EVENT_COMPOSITION_FINISH_MTK);
				#if (!(defined (MT6250) || defined (MT6260) || defined (MT6261) || defined (MT2501) || defined (MT2502))) 
                bCallback = 1;
				#endif
            }

    // KeTing: Set to non-busy after all resources are free
    savedMask = SaveAndSetIRQMask();
    pContext->_busy = WFC_FALSE;
    RestoreIRQMask(savedMask);

    // KeTing: In fact, it donesn't matter to put before or after setting the busy flag
    // KeTing: Because the function is always called in drv_hisr and has the highest priority
    _wfc_set_context_frame_done_event(pContext, WFC_TRUE);

    if (WFC_AUTONOMOUS_STATE_ON == pContext->_autonomousMode)
    {
        // KeTing: Please invoke this function after de-assert busy flag
        _wfc_autonomous_frame_done_callback(pContext);
    }
	#if (!(defined (MT6250) || defined (MT6260) || defined (MT6261) || defined (MT2501) || defined (MT2502))) 
    DDV2CatcherLogL3D4(TRACE_DDV2_RENDERING, DDV2_TRC_WFCENGINEEVENTHANDLER,
                                             drv_get_current_time(),
                                             (kal_uint32)kal_get_current_thread_ID(),
                                             (kal_uint32)(param),
                                             bCallback);
	#endif


}

static void _wfc_wait_until_wfd_not_busy(WFCContextConfig* pContext)
{
    kal_uint32 event_group;

    while(WFC_TRUE == _wfc_is_wfd_busy(pContext))
    {
        // KeTing: Note here is not only retrieve the target context frame done event
        // KeTing: This is because there may be other context occupy the same wfd device
        kal_retrieve_eg_events(_owf_event,
            (kal_uint32)(_WFC_FRAME_DONE_EVENT_CONTEXT_ALL),
            KAL_OR, &event_group, KAL_SUSPEND);

    }
}

// KeTing: Check if this wfd ening is used by some context in autonomous mode
static WFCboolean _wfc_is_engine_in_autonomous_mode(WFDDevice engine)
{
    // KeTing: Do not use "else" since lcd_0, lcd_1, and tvout may use the same engine
    // KeTing: We have to check all the contexts with the same engine
    if (engine == _wfc_context_cfg_lcd_0._engine && WFC_AUTONOMOUS_STATE_ON == _wfc_context_cfg_lcd_0._autonomousMode)
    {
        return WFC_TRUE;
    }
#ifdef DUAL_LCD
    if (engine == _wfc_context_cfg_lcd_1._engine && WFC_AUTONOMOUS_STATE_ON == _wfc_context_cfg_lcd_1._autonomousMode)
    {
        return WFC_TRUE;
    }
#endif
    // KeTing: None of the context with the same engine is in autonomous mode
    return WFC_FALSE;
}

// KeTing: Check if this wfd ening is used by some context in autonomous mode
static WFCboolean _wfc_is_context_in_autonomous_mode(WFCContext ctx)
{
    if ((WFCuint)ctx == (WFCuint)&_wfc_context_cfg_lcd_0 && WFC_AUTONOMOUS_STATE_ON == _wfc_context_cfg_lcd_0._autonomousMode)
    {
        return WFC_TRUE;
    }
#ifdef DUAL_LCD
    if ((WFCuint)ctx == (WFCuint)&_wfc_context_cfg_lcd_1 && WFC_AUTONOMOUS_STATE_ON == _wfc_context_cfg_lcd_1._autonomousMode)
    {
        return WFC_TRUE;
    }
#endif
    // KeTing: None of the context with the same engine is in autonomous mode
    return WFC_FALSE;
}


/******************************************************************************
 * WFC internal functions
 ******************************************************************************/

/**
 *  Record the first unread error code.
 *  \status OK
 */
void _wfc_set_error(WFCErrorCode error)
{
    if (WFC_ERROR_NONE == _wfc_device_cfg._lastErrorCode)
    {
        _wfc_device_cfg._lastErrorCode = error;
    }
    wfcTrace(WFCDBG_________________ERROR_HAPPEN);
}

// KeTing: Check if any context using the same wfd engine is busy
WFCboolean _wfc_is_wfd_busy(WFCContextConfig* pContext)
{
    WFD_DEVICE* pEngine = (WFD_DEVICE*)pContext->_engine;
    if (WFD_TRUE == pContext->_busy || WFD_TRUE == pEngine->busyFlag)
    {
        return WFC_TRUE;
    }
    else
    {
        kal_uint32 i;
        for (i = 0; i < WFC_CONTEXT_MAX_COUNT; i++)
        {
            WFCContextConfig *pOtherContext = (WFCContextConfig *)(_wfc_device_cfg._createdContexts[i]);
            if (WFC_TRUE == pOtherContext->_busy && pOtherContext->_engine == (WFCHandle)pEngine)
            {
                return WFC_TRUE;
            }
        }
        return WFC_FALSE;
    }
}

// KeTing: To set or clear the target context WFC frame done event
// KeTing: If setEvent == true, set the frame done event
// KeTing: Else clear the event
void _wfc_set_context_frame_done_event(WFCContextConfig *pContext, WFCboolean setEvent)
{
    kal_uint32 frm_done_event_bit_id;

    frm_done_event_bit_id = (kal_uint32)(_wfc_convert_context_handle_to_frame_done_enum(pContext));

    if (WFC_TRUE == setEvent)
    {
        kal_set_eg_events(_owf_event,
            frm_done_event_bit_id,
            KAL_OR);
    }
    else
    {
        kal_set_eg_events(_owf_event,
            ~frm_done_event_bit_id,
            KAL_AND);
    }
}

#if defined (__GOVL_SUPPORT__)
static kal_uint32 gdi_handle = 0;
static void flatten_api_cb(void *flatten_api_cb_para)
{ 
    _wfc_engine_event_hdlr(WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK,  flatten_api_cb_para);
    if (FLATTEN_RESULT_OK != FlattenReleaseOwnership(gdi_handle))
    {
        ASSERT(0);
    }
}
#endif
/** 
 *  To config the WFD for compose and activate
 *  Please note this function provides no protection and assumes the caller will lock
 *  the needed informtion. Also the parameter checking should be the resposibility of
 *  the caller.
 *  \status XX
 */
void _wfc_config_wfd_and_commit(WFCContextConfig* pContext, WFCboolean wait)
{
    int i;
    WFD_DEVICE* pEngine = NULL;
    WFD_PORT* pPort = NULL;
    OWF_RECTANGLE Rect;

    pEngine = (WFD_DEVICE*) pContext->_engine;
    pPort = (WFD_PORT*) pContext->_port;

    DDV2CatcherLogL3D8(TRACE_DDV2_RENDERING, DDV2_TRC_WFCCONFIGWFDANDCOMMIT,
                                             drv_get_current_time(),
                                             (kal_uint32)kal_get_current_thread_ID(),
                                             (kal_uint32)(pContext),
                                             (kal_uint32)(pEngine),
                                             (kal_uint32)(pPort),
                                             pContext->type,
                                             wait, 0);
    
    // The following section is used for RF-Desense test. 
    // When the return value of rf_desense_get_curr_mode() is NO_LCD_UPDATE, we bypass blt and flatten and call callback function directly.
    // When the return value of rf_desense_get_curr_mode() is NO_LCM_UPDATE, we only bypass blt operations.
#if defined(__RF_DESENSE_TEST__)
    if (RF_DESENSE_MODE_NO_LCD_UPDATE == rf_desense_get_curr_mode())
    {
        pContext->_autoModeCommitLatched = WFC_TRUE;
        _wfc_engine_event_hdlr(WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK, (void*)(pContext));
        kal_prompt_trace(MOD_MED, "[RF Desense] [RF Desense No LCD Update] Pass!\n");
        return;
    }
    
    if (RF_DESENSE_MODE_NO_LCM_UPDATE == rf_desense_get_curr_mode())
    {
        if (WFC_CONTEXT_TYPE_ON_SCREEN == pContext->type)
        {
            pContext->_autoModeCommitLatched = WFC_TRUE;
            _wfc_engine_event_hdlr(WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK, (void*)(pContext));
            kal_prompt_trace(MOD_MED, "[RF Desense] [RF Desense No LCM Update] Pass!\n");
            return;
        }
    }
#endif //#if defined(__RF_DESENSE_TEST__)

#if defined (__GOVL_SUPPORT__)
if (WFC_CONTEXT_TYPE_OFF_SCREEN == pContext->type)
{
    FlattenResultEnum flatten_result;
    FlattenCtrlStruct flatten_ctrl_config = {0};

    //Get User Handle
    if (0 == gdi_handle) 
    {
        gdi_handle = FlattenGetUserHandle();
    }

    // Get Flatten API's Ownership
    {
        flatten_result = FlattenGetOwnership(gdi_handle, KAL_TRUE, KAL_FALSE);
        if (FLATTEN_RESULT_OK != flatten_result)
        {
            ASSERT(0);
        }
    } 
   
    // Config Flatten Ctrl...
    {
        //OWF_RECTANGLE TargetRect;
        // background color
        //pPort->config.backgroundColor[0] = (pContext->capturedRWAttrib->bgColor&0xFF000000)>>24;   // A
        //pPort->config.backgroundColor[1] = (pContext->capturedRWAttrib->bgColor&0x00FF0000)>>16;   // R
        //pPort->config.backgroundColor[2] = (pContext->capturedRWAttrib->bgColor&0x0000FF00)>>8;    // G
        //pPort->config.backgroundColor[3] = (pContext->capturedRWAttrib->bgColor&0x000000FF);       // B
        flatten_ctrl_config.bgColor = pContext->capturedRWAttrib->bgColor;

        Rect = pContext->capturedRWAttrib->roiRect;

        //memcpy(pPort->config.roiDestRectangle, &Rect, sizeof(WFDint)*4);
        flatten_ctrl_config.roiRect_x = Rect.x;
        flatten_ctrl_config.roiRect_y = Rect.y;
        flatten_ctrl_config.roiRect_width = Rect.width;
        flatten_ctrl_config.roiRect_height = Rect.height;

        Rect.x = (WFDint) pContext->capturedRWAttrib->destinationRect.x + Rect.x - pContext->capturedRWAttrib->roiRect.x;
        Rect.y = (WFDint) pContext->capturedRWAttrib->destinationRect.y + Rect.y - pContext->capturedRWAttrib->roiRect.y;

        //memcpy(pPort->config.partialRefreshRectangle, &Rect, sizeof(WFDint)*4);
        flatten_ctrl_config.destinationRect_x = Rect.x;
        flatten_ctrl_config.destinationRect_y = Rect.y;
        flatten_ctrl_config.destinationRect_width = Rect.width;
        flatten_ctrl_config.destinationRect_height = Rect.height;

        //pPort->config.syncEnable = (WFDboolean)(pContext->capturedRWAttrib->enableVsync);
        //pPort->config.blockModeReq = (WFDboolean)(wait);
        flatten_ctrl_config.blocking_req = (kal_bool)(wait);

        // config memout's output image
        {
            OWF_IMAGE target_image = (pContext->capturedRWAttrib->memOutTarget.image);
            FLATTEN_PIXEL_FORMAT flatten_ctrl_format;
            //pPort->config.targetImage = &(pContext->capturedRWAttrib->memOutTarget.image);
            flatten_ctrl_config.memOut_image_width = target_image.width;
            flatten_ctrl_config.memOut_image_height = target_image.height;
            flatten_ctrl_config.memOut_image_stride = target_image.stride;
            flatten_ctrl_config.memOut_image_pixelSize = target_image.pixelSize;
            switch(target_image.format.pixelFormat)
            {
                case OWF_IMAGE_ARGB8888: flatten_ctrl_format = FLATTEN_IMAGE_ARGB8888; break; 
                case OWF_IMAGE_XRGB8888: flatten_ctrl_format = FLATTEN_IMAGE_XRGB8888; break; 
                case OWF_IMAGE_RGB888: flatten_ctrl_format = FLATTEN_IMAGE_RGB888; break; 
                case OWF_IMAGE_BGR888: flatten_ctrl_format = FLATTEN_IMAGE_BGR888; break; 
                case OWF_IMAGE_RGB565: flatten_ctrl_format = FLATTEN_IMAGE_RGB565; break; 
                case OWF_IMAGE_L32: flatten_ctrl_format = FLATTEN_IMAGE_L32; break; 
                case OWF_IMAGE_L16: flatten_ctrl_format = FLATTEN_IMAGE_L16; break; 
                case OWF_IMAGE_L8: flatten_ctrl_format = FLATTEN_IMAGE_L8; break; 
                case OWF_IMAGE_L1: flatten_ctrl_format = FLATTEN_IMAGE_L1; break; 
                case OWF_IMAGE_UYVY: flatten_ctrl_format = FLATTEN_IMAGE_UYVY; break; 
                case OWF_IMAGE_ARGB6666: flatten_ctrl_format = FLATTEN_IMAGE_ARGB6666; break; 
                default: flatten_ctrl_format = FLATTEN_IMAGE_NOT_SUPPORTED; break; 
            }
            flatten_ctrl_config.memOut_image_format_pixelFormat = flatten_ctrl_format;
            flatten_ctrl_config.memOut_image_format_linear = (kal_bool)(target_image.format.linear);
            flatten_ctrl_config.memOut_image_format_premultiplied = (kal_bool)(target_image.format.premultiplied);
            flatten_ctrl_config.memOut_image_format_rowPadding = target_image.format.rowPadding;
            flatten_ctrl_config.memOut_image_datamax = target_image.dataMax;
            flatten_ctrl_config.memOut_image_alpha = target_image.alpha;
            flatten_ctrl_config.memOut_image_data = target_image.data;
        }

        // callback functions...
        //pPort->config.updateDoneCallback[0] = (WFDuint) _wfc_engine_event_hdlr;
        //pPort->config.updateDoneCallback[1] = (WFDuint) pContext;
        if (KAL_FALSE == (kal_bool)wait)
        {
            flatten_ctrl_config.flatten_nonblocking_callback = flatten_api_cb;
            flatten_ctrl_config.cbparam = (void *)pContext;
        } 
        // palette table address
        //pPort->config.paletteTable = (WFDuint) pContext->capturedRWAttrib->paletteTable;
        flatten_ctrl_config.paletteTable = (kal_uint32)pContext->capturedRWAttrib->paletteTable;

    } 

    // Config Flatten Layer...
    {
        kal_uint32 i;

        // Clear WFD port setting
        //memset(pPort->config.bindedPipelines, 0, sizeof(pPort->config.bindedPipelines));
        for (i = 0; i < WFC_CONTEXT_MAX_INSERTED_ELEMENT; i++)
        {
            /// Only apply inserted elements
            if (WFC_INVALID_HANDLE != pContext->capturedRWAttrib->_insertedElements[i])
            {
                //WFDSource source;
                WFCElementConfig* pElement = (WFCElementConfig*) pContext->capturedRWAttrib->_insertedElements[i];
                //WFCSourceConfig*  sourceCfg;
                //WFD_PIPELINE* pPipeline = &(pEngine->pipelines[i]);

                FlattenLayerStruct flatten_layer_config = {0};
                FLATTEN_PIXEL_FORMAT flatten_layer_format;
                OWF_IMAGE source_image;

                //if (i >= pEngine->pipelineCount)
                if (i >= 4)
                {
                    // Error!
                    continue;
                }

                /// if the inserted element without source, bypass this layer
                if (WFC_INVALID_HANDLE == pElement->capturedRWAttrib->source)
                {
                    DDV2CatcherLogL1D2(TRACE_DDV2_WARNING, DDV2_TRC_WARNING_CONFIGWFD_NOSOURCE,
                                                           drv_get_current_time(),
                                                           (kal_uint32)kal_get_current_thread_ID());
                    _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
                    continue;
                }
                
                // KeTing: If the image is not ready, don't blt this element
                // KeTing: This will happen if multiple streams are existed, the sync element changes buffer prior than other streams
                // KeTing: In this situation, we will not yet wrap the stream as image if the stream has not changed buffer yet
                if (OWF_INVALID_HANDLE == ((WFCSourceConfig*)pElement->capturedRWAttrib->source)->image.data)
                {
                    DDV2CatcherLogL1D2(TRACE_DDV2_WARNING, DDV2_TRC_WARNING_CONFIGWFD_NOBUFFER,
                                                           drv_get_current_time(),
                                                           (kal_uint32)kal_get_current_thread_ID());
                    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
                    continue;
                }

                // Set Pipeline attributes
                // Set flatten_layer_config
                //pPipeline->config.flip = (WFDboolean)(pElement->capturedRWAttrib->flip);
                flatten_layer_config.flip = (kal_bool)(pElement->capturedRWAttrib->flip);
                //pPipeline->config.mirror = WFD_FALSE;
                //pPipeline->config.rotation = _wfc_convert_rotation_angle_to_int(pElement->capturedRWAttrib->rotationAngle);
                flatten_layer_config.rotationAngle = (FLATTENRotationType)_wfc_convert_rotation_angle_to_int(pElement->capturedRWAttrib->rotationAngle);
                //pPipeline->config.transparencyEnable = (WFDuint)(_wfc_convert_transparency(pElement->capturedRWAttrib->transparencyType));
                flatten_layer_config.transparencyType = (FLATTENbitfield)(_wfc_convert_transparency(pElement->capturedRWAttrib->transparencyType));
                //pPipeline->config.globalAlpha = pElement->capturedRWAttrib->globalAlpha;
                flatten_layer_config.globalAlpha = pElement->capturedRWAttrib->globalAlpha;
                //pPipeline->config.ditherEnable = pElement->capturedRWAttrib->enableSpatialDithering;
                flatten_layer_config.enableSpatialDithering = (kal_bool)(pElement->capturedRWAttrib->enableSpatialDithering); 
                //pPipeline->config.transparencyColor = pElement->capturedRWAttrib->sourceColorKey;
                flatten_layer_config.sourceColorKey = pElement->capturedRWAttrib->sourceColorKey;
                //pPipeline->config.dcEnable = pElement->capturedRWAttrib->isDCLayer;
		
                //memcpy(pPipeline->config.sourceRectangle, &(pElement->capturedRWAttrib->sourceRect), sizeof(WFDint)*4);
                flatten_layer_config.sourceRect_x = pElement->capturedRWAttrib->sourceRect.x;
                flatten_layer_config.sourceRect_y = pElement->capturedRWAttrib->sourceRect.y;
                flatten_layer_config.sourceRect_width = pElement->capturedRWAttrib->sourceRect.width;
                flatten_layer_config.sourceRect_height = pElement->capturedRWAttrib->sourceRect.height;

                //memcpy(pPipeline->config.destinationRectangle, &(pElement->capturedRWAttrib->destinationRect), sizeof(WFDint)*4);
                flatten_layer_config.destinationRect_x = pElement->capturedRWAttrib->destinationRect.x;
                flatten_layer_config.destinationRect_y = pElement->capturedRWAttrib->destinationRect.y;
                flatten_layer_config.destinationRect_width = pElement->capturedRWAttrib->destinationRect.width;
                flatten_layer_config.destinationRect_height = pElement->capturedRWAttrib->destinationRect.height;

                //pPipeline->config.image_source = &(((WFCSourceConfig*)pElement->capturedRWAttrib->source)->image);
                source_image = (((WFCSourceConfig*)pElement->capturedRWAttrib->source)->image);
                flatten_layer_config.image_source_width = source_image.width;
                flatten_layer_config.image_source_height = source_image.height;
                flatten_layer_config.image_source_stride = source_image.stride;
                flatten_layer_config.image_source_pixelSize = source_image.pixelSize;
                switch(source_image.format.pixelFormat)
                {
                    case OWF_IMAGE_ARGB8888: flatten_layer_format = FLATTEN_IMAGE_ARGB8888; break; 
                    case OWF_IMAGE_XRGB8888: flatten_layer_format = FLATTEN_IMAGE_XRGB8888; break; 
                    case OWF_IMAGE_RGB888: flatten_layer_format = FLATTEN_IMAGE_RGB888; break; 
                    case OWF_IMAGE_BGR888: flatten_layer_format = FLATTEN_IMAGE_BGR888; break; 
                    case OWF_IMAGE_RGB565: flatten_layer_format = FLATTEN_IMAGE_RGB565; break; 
                    case OWF_IMAGE_L32: flatten_layer_format = FLATTEN_IMAGE_L32; break; 
                    case OWF_IMAGE_L16: flatten_layer_format = FLATTEN_IMAGE_L16; break; 
                    case OWF_IMAGE_L8: flatten_layer_format = FLATTEN_IMAGE_L8; break; 
                    case OWF_IMAGE_L1: flatten_layer_format = FLATTEN_IMAGE_L1; break; 
                    case OWF_IMAGE_ARGB6666: flatten_layer_format = FLATTEN_IMAGE_ARGB6666; break; 	
                    case OWF_IMAGE_UYVY: flatten_layer_format = FLATTEN_IMAGE_UYVY; break; 
                    default: flatten_layer_format = FLATTEN_IMAGE_NOT_SUPPORTED; break; 
                }
                flatten_layer_config.image_source_format_pixelFormat = flatten_layer_format;
                flatten_layer_config.image_source_format_premultiplied = (kal_bool)(source_image.format.premultiplied);
                flatten_layer_config.image_source_format_linear = (kal_bool)(source_image.format.linear);
                flatten_layer_config.image_source_format_rowPadding = source_image.format.rowPadding;
                flatten_layer_config.image_source_datamax = source_image.dataMax;
                flatten_layer_config.image_source_alpha = source_image.alpha;
                flatten_layer_config.image_source_data = source_image.data;
                
                flatten_layer_config.isConstantValue = KAL_FALSE;

                switch(i)
                {
                    case 0:
                    flatten_result = FlattenConfigLayer(gdi_handle, FLATTEN_LAYER0, &flatten_layer_config);
                    break;
                    case 1:
                    flatten_result = FlattenConfigLayer(gdi_handle, FLATTEN_LAYER1, &flatten_layer_config);
                    break;
                    case 2:
                    flatten_result = FlattenConfigLayer(gdi_handle, FLATTEN_LAYER2, &flatten_layer_config);
                    break;
                    case 3:
                    flatten_result = FlattenConfigLayer(gdi_handle, FLATTEN_LAYER3, &flatten_layer_config);
                    break;
                } 
                if (FLATTEN_RESULT_OK != flatten_result)
                    ASSERT(0);
                //pPipeline->config.portId = (WFDPort)(pPort);
                //pPort->config.bindedPipelines[i] = WFD_TRUE;
                switch(i)
                {
                    case 0: flatten_ctrl_config.flatten_enable_layer |= FLATTEN_LAYER0; break;
                    case 1: flatten_ctrl_config.flatten_enable_layer |= FLATTEN_LAYER1; break;
                    case 2: flatten_ctrl_config.flatten_enable_layer |= FLATTEN_LAYER2; break;
                    case 3: flatten_ctrl_config.flatten_enable_layer |= FLATTEN_LAYER3; break;
                    default: ASSERT(0); break;
                }
                
            }
        }
    }

    // Moved here to control blocking or non-blocking mode...
    // pPort->config.doBlt = WFD_TRUE;

    wfcTrace(WFCDBG____CONFIG_______________PORT);

    //wfdDeviceCommit((WFDDevice)pEngine, WFD_COMMIT_ENTIRE_PORT, (WFDHandle)pPort);
    flatten_result = FlattenStart(gdi_handle, &flatten_ctrl_config);
    if (FLATTEN_RESULT_OK != flatten_result)
        ASSERT(0);


    if (KAL_TRUE == (kal_bool)wait)
    {
        flatten_api_cb((void *)pContext);
    }
    
    // KeTing: WFD error handling
    
}
else
#endif //#if defined (__GOVL_SUPPORT__)
{
    // Config WFDPort accordingly...
    {
        OWF_RECTANGLE TargetRect;
        // background color
        pPort->config.backgroundColor[0] = (pContext->capturedRWAttrib->bgColor&0xFF000000)>>24;   // A
        pPort->config.backgroundColor[1] = (pContext->capturedRWAttrib->bgColor&0x00FF0000)>>16;   // R
        pPort->config.backgroundColor[2] = (pContext->capturedRWAttrib->bgColor&0x0000FF00)>>8;    // G
        pPort->config.backgroundColor[3] = (pContext->capturedRWAttrib->bgColor&0x000000FF);       // B

        Rect = pContext->capturedRWAttrib->roiRect;
        // Merge video rectangle with ROI. Only for on screen context in auto mode.
        if (WFC_CONTEXT_TYPE_ON_SCREEN == pContext->type)
        {
            if (WFC_AUTONOMOUS_STATE_ON == pContext->_autonomousMode)
            {
                // Calculate video region. Saved in pContext->_autoModeRoiRect.
                memset(&(pContext->_autoModeRoiRect), 0, sizeof(OWF_RECTANGLE));
                for (i = WFC_CONTEXT_MAX_INSERTED_ELEMENT; i-- != 0; )
                {
                    WFCElementConfig* pElement = (WFCElementConfig*)pContext->capturedRWAttrib->_insertedElements[i];
                    if (WFC_INVALID_HANDLE != pElement && WFC_TRUE == pElement->capturedRWAttrib->isVideoLayer)
                    {
                        OWF_RECTANGLE videoElementRect = pElement->capturedRWAttrib->destinationRect;
                        if (_wfc_convert_rotation_angle_to_int(pElement->capturedRWAttrib->rotationAngle)/90%2)
                        {
                            videoElementRect.width = pElement->capturedRWAttrib->sourceRect.height;
                            videoElementRect.height = pElement->capturedRWAttrib->sourceRect.width;
                        }
                        else
                        {
                            videoElementRect.width = pElement->capturedRWAttrib->sourceRect.width;
                            videoElementRect.height = pElement->capturedRWAttrib->sourceRect.height;
                        }
                        _wfc_rectangle_or(&videoElementRect, &(pContext->_autoModeRoiRect), &(pContext->_autoModeRoiRect));
                    }
                }
                _wfc_rectangle_or(&(pContext->_autoModeRoiRect), &Rect, &Rect);
            }
            // The ROI should be in screen rectangle.
            TargetRect.x = TargetRect.y = 0;
            TargetRect.width = ((WFD_PORT*)(pContext->_port))->config.portWidth;
            TargetRect.height = ((WFD_PORT*)(pContext->_port))->config.portHeight;
            _wfc_rectangle_and(&TargetRect, &Rect, &Rect);
        }

        memcpy(pPort->config.roiDestRectangle, &Rect, sizeof(WFDint)*4);

        Rect.x = (WFDint) pContext->capturedRWAttrib->destinationRect.x + Rect.x - pContext->capturedRWAttrib->roiRect.x;
        Rect.y = (WFDint) pContext->capturedRWAttrib->destinationRect.y + Rect.y - pContext->capturedRWAttrib->roiRect.y;

        memcpy(pPort->config.partialRefreshRectangle, &Rect, sizeof(WFDint)*4);

        if (WFC_CONTEXT_TYPE_ON_SCREEN == pContext->type)
            pContext->_autoModeCommitLatched = WFC_TRUE;

        pPort->config.syncEnable = (WFDboolean)(pContext->capturedRWAttrib->enableVsync);
        pPort->config.blockModeReq = (WFDboolean)(wait);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        // config memout's output image
        if ((WFC_CONTEXT_TYPE_OFF_SCREEN == pContext->type) || 
            (WFC_TRUE == pContext->capturedRWAttrib->enableConcurrentMemOut))
        {
            pPort->config.targetImage = &(pContext->capturedRWAttrib->memOutTarget.image);
        }

        // callback functions...
        pPort->config.updateDoneCallback[0] = (WFDuint) _wfc_engine_event_hdlr;
        pPort->config.updateDoneCallback[1] = (WFDuint) pContext;
        
        // palette table address
        pPort->config.paletteTable = (WFDuint) pContext->capturedRWAttrib->paletteTable;
    }

    // Config WFDPipelines accordingly...
    {
        kal_uint32 i;

        // Clear WFD port setting
        memset(pPort->config.bindedPipelines, 0, sizeof(pPort->config.bindedPipelines));
        for (i = 0; i < WFC_CONTEXT_MAX_INSERTED_ELEMENT; i++)
        {
            /// Only apply inserted elements
            if (WFC_INVALID_HANDLE != pContext->capturedRWAttrib->_insertedElements[i])
            {
                //WFDSource source;
                WFCElementConfig* pElement = (WFCElementConfig*) pContext->capturedRWAttrib->_insertedElements[i];
                //WFCSourceConfig*  sourceCfg;
                WFD_PIPELINE* pPipeline = &(pEngine->pipelines[i]);

                if (i >= pEngine->pipelineCount)
                {
                    // Error!
                    continue;
                }

                /// if the inserted element without source, bypass this layer
                if (WFC_INVALID_HANDLE == pElement->capturedRWAttrib->source)
                {
                    DDV2CatcherLogL1D2(TRACE_DDV2_WARNING, DDV2_TRC_WARNING_CONFIGWFD_NOSOURCE,
                                                           drv_get_current_time(),
                                                           (kal_uint32)kal_get_current_thread_ID());
                    _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
                    continue;
                }
                
                // KeTing: If the image is not ready, don't blt this element
                // KeTing: This will happen if multiple streams are existed, the sync element changes buffer prior than other streams
                // KeTing: In this situation, we will not yet wrap the stream as image if the stream has not changed buffer yet
                if (OWF_INVALID_HANDLE == ((WFCSourceConfig*)pElement->capturedRWAttrib->source)->image.data)
                {
                    DDV2CatcherLogL1D2(TRACE_DDV2_WARNING, DDV2_TRC_WARNING_CONFIGWFD_NOBUFFER,
                                                           drv_get_current_time(),
                                                           (kal_uint32)kal_get_current_thread_ID());
                    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
                    continue;
                }

                // Set Pipeline attributes
                pPipeline->config.flip = (WFDboolean)(pElement->capturedRWAttrib->flip);
                pPipeline->config.mirror = WFD_FALSE;
                pPipeline->config.rotation = _wfc_convert_rotation_angle_to_int(pElement->capturedRWAttrib->rotationAngle);
                pPipeline->config.transparencyEnable = (WFDuint)(_wfc_convert_transparency(pElement->capturedRWAttrib->transparencyType));
                pPipeline->config.globalAlpha = pElement->capturedRWAttrib->globalAlpha;
                pPipeline->config.ditherEnable = (WFDboolean)pElement->capturedRWAttrib->enableSpatialDithering;
                pPipeline->config.transparencyColor = pElement->capturedRWAttrib->sourceColorKey;
                pPipeline->config.dcEnable = (WFDboolean)pElement->capturedRWAttrib->isDCLayer;
				//this is for MT6255 or later chip support 3D feature.
				#ifdef DRV_LCD_3D_MODE_SUPPORT
				pPipeline->config._3DEnable = (WFDboolean)pElement->capturedRWAttrib->is3DLayer;
				if(WFD_TRUE == pPipeline->config._3DEnable)
				{
					if( WFC_3D_IMAGE_PORTRAIT_MODE == pElement->capturedRWAttrib->_3DimageViewMode)
						pPipeline->config._3DPortraitMode = WFD_TRUE;
					else if( WFC_3D_IMAGE_LANDSCAPE_MODE == pElement->capturedRWAttrib->_3DimageViewMode)
						pPipeline->config._3DPortraitMode = WFD_FALSE;
					else
						ASSERT(0);//error
					
					if( WFC_3D_IMAGE_LEFT_EYE_FIRST_MODE == pElement->capturedRWAttrib->_3DimageFirstEyeMode)
						pPipeline->config._3DLeftEyeFirst = WFD_TRUE;
					else if( WFC_3D_IMAGE_RIGHT_EYE_FIRST_MODE == pElement->capturedRWAttrib->_3DimageFirstEyeMode)
						pPipeline->config._3DLeftEyeFirst = WFD_FALSE;
					else
						ASSERT(0);//error
					/*
					if( WFC_3D_START_ADDR_FOR_LEFT_MODE == pElement->capturedRWAttrib->_3DimageStartAddrMode)
						pPipeline->config._3DStartAddrForLeft = WFD_TRUE;
					else ( WFC_3D_START_ADDR_FOR_RIGHT_MODE == pElement->capturedRWAttrib->_3DimageStartAddrMode)
						pPipeline->config._3DStartAddrForLeft = WFD_FALSE;
					else
						//error*/
				}
				#endif
								
                /// Bin: this is only for MT6253, enable fast rotator for video layer in auto mode
                ///        but fast rotator is available only one layer, we did not handle more than one layer case
                if (pContext->_autonomousMode == WFC_AUTONOMOUS_STATE_ON)
                    pPipeline->config.FastRotatorEnable = (WFDboolean)(pElement->capturedRWAttrib->isVideoLayer);
                else
                {
                    pPipeline->config.FastRotatorEnable = (WFDboolean)(0);
                    pPipeline->config.dcEnable = (WFDboolean)(0);
                } 
                memcpy(pPipeline->config.sourceRectangle, &(pElement->capturedRWAttrib->sourceRect), sizeof(WFDint)*4);
                memcpy(pPipeline->config.destinationRectangle, &(pElement->capturedRWAttrib->destinationRect), sizeof(WFDint)*4);

                pPipeline->config.image_source = &(((WFCSourceConfig*)pElement->capturedRWAttrib->source)->image);

                pPipeline->config.portId = (WFDPort)(pPort);
                pPort->config.bindedPipelines[i] = WFD_TRUE;
				//handler for the second pipeline for the 3D image base on the first pipeline.
				//the first pipeline config from wfc element[0],the user of the wfc just only config element[0] for 3D image.
				#ifdef DRV_LCD_3D_MODE_SUPPORT
				if(WFD_TRUE == pPipeline->config._3DEnable)
				{
					WFD_PIPELINE* pPipeline2 = &(pEngine->pipelines[i+1]);
					if(0 != i)//for 6255 now(2012.6.26),,only element[0]can config as 3D feature.
						ASSERT(0);
					if(WFC_INVALID_HANDLE != pContext->capturedRWAttrib->_insertedElements[i+1])
						ASSERT(0);//3D layer just config element[0],element[1] should be NULL 
					//
					memcpy(pPipeline2,pPipeline,sizeof(WFD_PIPELINE));
					
					pPipeline2->config.id = i+1;
					
					if( WFC_3D_IMAGE_PORTRAIT_MODE == pElement->capturedRWAttrib->_3DimageViewMode)
					{	
						pPipeline2->config.sourceRectangle[0] = pPipeline->config.sourceRectangle[0] + pPipeline->config.sourceRectangle[2]/2;
						//lcd layer size is half of SW layer size,so adjust pPipeline->config.sourceRectangle.width for PORTRAIT_MODE.
						pPipeline->config.sourceRectangle[2] = pPipeline->config.sourceRectangle[2]/2;
						pPipeline2->config.sourceRectangle[2] = pPipeline->config.sourceRectangle[2];
					}
					else if( WFC_3D_IMAGE_LANDSCAPE_MODE == pElement->capturedRWAttrib->_3DimageViewMode)
					{
						pPipeline2->config.sourceRectangle[1] = pPipeline->config.sourceRectangle[1] + pPipeline->config.sourceRectangle[3]/2;
						//lcd layer size is half of SW layer size,so adjust pPipeline->config.sourceRectangle.height for LANDSCAPE_MODE.
						pPipeline->config.sourceRectangle[3] = pPipeline->config.sourceRectangle[3]/2;
						pPipeline2->config.sourceRectangle[3] = pPipeline->config.sourceRectangle[3];
					}
					else
					{
						ASSERT(0);
					}
					//todo:
					//handle attribute pElement->capturedRWAttrib->_3DimageStartAddrMode
					//this for rotation to MDP use in the future.
					//default:layer0 for left eye usage,layer1 for right eye usage
					//when rotate 90/270,layer0 will for right eye usage
					pPort->config.bindedPipelines[i+1] = WFD_TRUE;
					
				}
				#endif
            }
        }
    }

    // Moved here to control blocking or non-blocking mode...
    pPort->config.doBlt = WFD_TRUE;

    wfcTrace(WFCDBG____CONFIG_______________PORT);

    wfdDeviceCommit((WFDDevice)pEngine, WFD_COMMIT_ENTIRE_PORT, (WFDHandle)pPort);
    // KeTing: All resources will be destroyed in event handler
    
    // KeTing: WFD error handling
    {
        WFDErrorCode error = wfdGetError(pEngine);
        if (WFD_ERROR_NONE != error && WFD_ERROR_NOT_SUPPORTED != error)
        {
            _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        }
    }
} 
}

/******************************************************************************
 * API definitions
 ******************************************************************************/

/*=========================================================================*/
/*  4. DEVICE                                                              */
/*=========================================================================*/
/***
 *  1. Multiple WFC device in a system? For what? 
 *      Does user really want to learn that we have a LCD and a GOVL?
 *    
 *  2. What about TV OUT? it cannot overlay, so it should be a WFD device only. 
 *      How we use it?
 *  3. If only one WFC device, can it be general enough to cover the case of three HW 
 *      devices? (LCD/GOVL/TVOUT) Single device with three or four context...
 *  4. How about Landscape UI on Portrait LCM? First of all, what compile options are 
 *      available for LCM scan-line directions.
 *      WFC do this for UI...? Map the Landscape mode as one context? Not efficient in terms of HW...
 *  5. If we need to implement sync to provider mode...as current FW trigger...
 *      Pros: if provider frame rate is stable and WFC performance is good, the behavior is predictable...
 *      Cons: Vulnerable to unstable frame rate issues...
 */

/**
 *  There is only one device.
 *  \status OK
 */
WFC_API_CALL WFCint WFC_APIENTRY
wfcEnumerateDevices(WFCint *deviceIds,
                    WFCint deviceIdsCount,
                    const WFCint *filterList)
{
    //WFCint ret = 0;

    // check arguments
    if ((NULL == deviceIds) || (1 > deviceIdsCount))
    {
        // only query for no of WFC devices.
        return 1;
    }

    deviceIds[0] = WFC_DEVICE_ID_DEFAULT;

    return 1;
}

static void _wfc_global_data_init(void)
{
	if(KAL_TRUE == _global_data_init)
		return;
	_global_data_init = KAL_TRUE;//init phase is single thread running,so no need to protect _global_data_init
	
	//init global data before using
	kal_mem_set((void *)(&_wfc_context_cfg_lcd_0),0,sizeof(WFCContextConfig));
	#ifdef DUAL_LCD
	kal_mem_set((void *)(&_wfc_context_cfg_lcd_1),0,sizeof(WFCContextConfig));
	#endif
	kal_mem_set((void *)(&_wfc_context_cfg_frame_buffer),0,sizeof(WFCContextConfig));
	kal_mem_set((void *)(&_wfc_sources[0]),0,sizeof(WFCSourceConfig)*WFC_MAX_SOURCE_NUMBER);
	kal_mem_set((void *)(&_wfc_elements[0]),0,sizeof(WFCElementConfig)*WFC_ELEMENT_MAX_COUNT);
	#if defined(WFC_DBG_SUPPORT)
	kal_mem_set((void *)(&_WFCDbgDat[0]),0,sizeof(WFCDbgCtrlBlk)*WFC_DBG_ENTRY_CNT);
	#endif
}
/**
 *  \status OK
 */
WFC_API_CALL WFCDevice WFC_APIENTRY
wfcCreateDevice(WFCint deviceId, const WFCint *attribList)
{
    WFDint i;
    WFCContextConfig* pContext;
    kal_uint32 memory_out_engine_index = 0;
	//init global data
	_wfc_global_data_init();

    _wfc_dbg_context_lcd0 = (WFCContextConfig_*) (&_wfc_context_cfg_lcd_0);
#ifdef DUAL_LCD
    _wfc_dbg_context_lcd1 = (WFCContextConfig_*) (&_wfc_context_cfg_lcd_1);
#endif
    //_wfc_dbg_context_frame_buffer = (WFCContextConfig_*) (&_wfc_context_cfg_frame_buffer);

    wfc_dbg_structure.ContextLCD0 = (WFCContextConfig_*)(_wfc_dbg_context_lcd0);
#ifdef DUAL_LCD
    wfc_dbg_structure.ContextLCD1 = (WFCContextConfig_*)(_wfc_dbg_context_lcd1);
#endif
    wfc_dbg_structure.ContextMem = (WFCContextConfig_*) (&_wfc_context_cfg_frame_buffer);
    wfc_dbg_structure.Device = (WFCDeviceConfig*)(&_wfc_device_cfg);

    if (WFC_DEVICE_ID_DEFAULT != deviceId)
    {
        return WFC_INVALID_HANDLE;
    }

    // check if already created
    if (WFC_DEVICE_STATE_DESTROYED != _wfc_device_cfg._state)
    {
        return WFC_INVALID_HANDLE;
    }

    // Common Initialization
    _owf_event = kal_create_event_group("_owf_event");
#if defined(__MTK_TARGET__)
    DRV_Register_HISR(DRV_LCD_WFC_HISR_ID,_wfc_autonomous_mode_blt_hisr);
	DRV_Register_HISR(DRV_LCD_RELEASE_DONE_HISR_ID,_wfc_autonomous_release_done_hisr);
#endif
    // Enumerate WFD devices, create them, and map them to contexts of WFC device.
    {
        WFDint deviceIds[WFC_ENGINE_MAX_COUNT] = {-1, -1};
        WFDint deviceIdsCount;

        // After this call, deviceIdsCount should be no bigger than WFC_ENGINE_MAX_COUNT.
        deviceIdsCount = wfdEnumerateDevices(deviceIds, WFC_ENGINE_MAX_COUNT, NULL);

        /**
        * 1. enumerate devices
        * 2. for each device, enumerate ports
        * 3. If found one internal port, place it at _engines[0]
        * 4. If found the second internal port, place it at _engines[1]
        * 5. If found one memory output port, place it at _engines[2]
        * 6. If found one device with only memory output port, replace it at _engines[2]
        * 7. If found one device with TV port, place it at _engines[3]
        */
        for (i = 0; i < deviceIdsCount; i++)
        {
            WFD_DEVICE* pEngine;
            //WFDint portIds[WFC_CONTEXT_MAX_COUNT] = {0};
            WFDint portCount;
            WFDint j;

            pEngine = (WFD_DEVICE*)wfdCreateDevice(deviceIds[i], NULL);

            portCount = pEngine->portCount;

            for (j = 0; j < portCount; j++)
            {
                WFDPortType portType;
                WFD_PORT* pPort = &(pEngine->ports[j]);
                
                portType = pPort->config.type;

                if (WFD_PORT_TYPE_INTERNAL == portType)
                {
                    if (WFC_INVALID_HANDLE == _wfc_device_cfg._engines[0])
                    {
                        // Use the first device and first port found
                        _wfc_device_cfg._engines[0] = (WFCHandle) pEngine;
                        kal_mem_set((void *)(&_wfc_context_cfg_lcd_0), 0x0, sizeof(WFCContextConfig));
                        _wfc_context_cfg_lcd_0._port = (WFCHandle) pPort;
                        _wfc_context_cfg_lcd_0._engine = (WFCHandle) pEngine;
                    }
#ifdef DUAL_LCD
                    else if (WFC_INVALID_HANDLE == _wfc_device_cfg._engines[1])
                    {
                        // Use the first device and first port found
                        _wfc_device_cfg._engines[1] = (WFCHandle) pEngine;
                        kal_mem_set((void *)(&_wfc_context_cfg_lcd_1), 0x0, sizeof(WFCContextConfig));
                        _wfc_context_cfg_lcd_1._port = (WFCHandle) pPort;
                        _wfc_context_cfg_lcd_1._engine = (WFCHandle) pEngine;
                    }
#endif
                    memory_out_engine_index++;
                }

                if (WFD_PORT_TYPE_MEMORY_OUTPUT_MTK == portType)
                {
                    // Directly replace with new device.
                    _wfc_device_cfg._engines[memory_out_engine_index] = (WFCHandle) pEngine;
                    kal_mem_set((void *)(&_wfc_context_cfg_frame_buffer), 0x0, sizeof(WFCContextConfig));
                    _wfc_context_cfg_frame_buffer._port = (WFCHandle) pPort;
                    _wfc_context_cfg_frame_buffer._engine = (WFCHandle) pEngine;
                }

            }
        }
    }

    i=0;
    _wfc_device_cfg._state = WFC_DEVICE_STATE_CREATED;
    _wfc_device_cfg._createdContexts[i++] = (WFCContext)(&_wfc_context_cfg_lcd_0);
#ifdef DUAL_LCD
    _wfc_device_cfg._createdContexts[i++] = (WFCContext)(&_wfc_context_cfg_lcd_1);
#endif
    _wfc_device_cfg._createdContexts[i++] = (WFCContext)(&_wfc_context_cfg_frame_buffer);
    for (i--; i>=0; i--)
    {
        pContext = (WFCContextConfig*)(_wfc_device_cfg._createdContexts[i]);
        pContext->cachedRWAttrib = &(pContext->__RWAttrib[0]);
        pContext->capturedRWAttrib = &(pContext->__RWAttrib[1]);

        pContext->_busy = WFC_FALSE;
        pContext->_autonomousMode = WFC_AUTONOMOUS_STATE_OFF;
    }

    return (WFCDevice) &_wfc_device_cfg;

}

/**
 *  \status OK
 */
WFC_API_CALL WFCErrorCode WFC_APIENTRY
wfcDestroyDevice(WFCDevice dev)
{
    //WFCDeviceConfig* pDevice = NULL;
    //kal_uint32 i;
    // This function should never be called
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return WFC_ERROR_NONE;
}

/**
 *  \status OK
 */
WFC_API_CALL WFCint WFC_APIENTRY
wfcGetDeviceAttribi(WFCDevice dev,
                    WFCDeviceAttrib attrib) 
{
    WFCint result = 0;

    switch (attrib)
    {
    case WFC_DEVICE_CLASS: 
        result = (WFCint) WFC_DEVICE_CLASS_FULLY_CAPABLE;
        break;
    case WFC_DEVICE_ID: 
        result = (WFCint) WFC_DEVICE_ID_DEFAULT;
        break;
    case WFC_DEVICE_NATIVE_DEBUG_TRACE_MTK: 
        result = 0;
        break;

    default: 
        _wfc_set_error(WFC_ERROR_BAD_ATTRIBUTE);
        break;
    }

    return result;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcSetDeviceAttribi(WFCDevice dev,
                    WFCDeviceAttrib attrib, 
                    WFCint value)
{
    return;
}

/**
 *  \status OK
 */
WFC_API_CALL WFCErrorCode WFC_APIENTRY
wfcGetError(WFCDevice dev)
{
    WFCErrorCode ret;

    ret = _wfc_device_cfg._lastErrorCode;
    _wfc_device_cfg._lastErrorCode = WFC_ERROR_NONE;

    return ret;
}


/**
 *  \status OK
 *  this funtion is used for MM to check WFC busy state
 */
WFC_API_CALL WFCboolean WFC_APIENTRY
wfcMMCheckBusy() WFC_APIEXIT
{
    return (_wfc_context_cfg_lcd_0._busy);
}

WFC_API_CALL WFCint WFC_APIENTRY
wfcMMGetContextAttribi(WFCDevice dev,
                     WFCContext ctx,
                     WFCContextAttrib attrib)
{
    WFCContextConfig* pContext = NULL;
    WFCint ret = 0;

    GET_CONTEXT(pContext, ctx, ret);

    switch (attrib)
    {
    case WFC_CONTEXT_CALLBACK_MTK: 
        ret = WFC_CONTEXT_MM_CALLBACK_COUNT*3;
        break;
        
    default: 
        ret = wfcGetContextAttribi(dev, ctx, attrib);
        break;
    }

    return ret;
}
/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcMMGetContextAttribiv(WFCDevice dev, 
                      WFCContext ctx, 
                      WFCContextAttrib attrib, 
                      WFCint count, 
                      WFCint *values)
{
    WFCContextConfig* pContext = NULL;

    GET_CONTEXT_NR(pContext, ctx);

    if ((1 > count) || (NULL == values))
    {
        _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        return;
    }
    // clear the values
    kal_mem_set((void*) values, 0x0, sizeof(WFCint)*count);

    switch (attrib)
    {
    case WFC_CONTEXT_CALLBACK_MTK: 
        {
            //kal_uint32 i = 0;
            WFC_ASSERT(count >= 4);
            // TODO: [o] later, there is no need to query this attrib
            break;
        }
    default:
        {
            wfcGetContextAttribiv(dev, ctx, attrib, count, values);
            break;
        }
    }

    return;
}
/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcMMSetContextAttribi(WFCDevice dev,
                     WFCContext ctx,
                     WFCContextAttrib attrib,
                     WFCint value) WFC_APIEXIT
{
    WFCContextConfig* pContext = NULL;

    DDV2CatcherLogL3(TRACE_DDV2_CONTEXTATTRIB, DDV2_TRC_WFCMMSETCONTEXTATTRIBI,
                                     drv_get_current_time(),
                                     (kal_uint32)kal_get_current_thread_ID(),
                                     ctx,
                                     attrib,
                                     value);
    GET_CONTEXT_NR(pContext, ctx);
    if(_wfc_is_context_in_autonomous_mode(ctx) == WFC_FALSE)
    {
        ///route to Non-mm set 
        DDV2CatcherLogL3(TRACE_DDV2_ERROR, DDV2_TRC_ERROR_AUTOMODE_STATEERROR,
                                         drv_get_current_time(),
                                         (kal_uint32)kal_get_current_thread_ID(),
                                         WFC_MMSetContextAttribi,
                                         pContext->_autonomousMode);
                                         
        wfcSetContextAttribi(dev, ctx, attrib, value);
        return;
    }
    
    switch (attrib)
    {
        case WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK: 
            pContext->cachedRWAttrib->currRefreshRate = (WFCint) value;
            break;

        case WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK: 
            {
                pContext->cachedRWAttrib->syncTrigger = (WFCAutonomousSyncTriggerMTK) value;
                break;
            }
            
        case WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK: 
            {
                pContext->cachedRWAttrib->period = (WFCuint) value;
                break;
            }
            
        case WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK: 
            {
                pContext->cachedRWAttrib->sync_element = (WFCElement) value;
                break;
            }

        ///From here, all illlegal attributes
        case WFC_CONTEXT_ROTATION: 
            DDV2CatcherLogL3(TRACE_DDV2_ERROR, DDV2_TRC_ERROR_ILLEGAL_WFCMMSETCONTEXTATTRIBI,
                                             drv_get_current_time(),
                                             (kal_uint32)kal_get_current_thread_ID(),
                                             ctx,
                                             attrib,
                                             value);
            _wfc_set_error(WFC_ERROR_MM_SET_ATTR_MTK);
            break;

            
        default: 
            _wfc_set_error(WFC_ERROR_BAD_ATTRIBUTE);
            break;
    }

    return;
}


WFC_API_CALL void WFC_APIENTRY
wfcMMSetContextAttribiv(WFCDevice dev, 
                      WFCContext ctx, 
                      WFCContextAttrib attrib, 
                      WFCint count, 
                      const WFCint *values) WFC_APIEXIT
{
    WFCContextConfig* pContext = NULL;

    if ((count >= 3) && (values != NULL))
    {
        if (attrib==WFC_CONTEXT_AUTONOMOUS_SYNC_TRIGGER_MTK)
            DDV2CatcherLogL3(TRACE_DDV2_CONTEXTATTRIB, DDV2_TRC_WFCMMSETCONTEXTATTRIBIV2,
                                            drv_get_current_time(),
                                            (kal_uint32)kal_get_current_thread_ID(),
                                            ctx,
                                            attrib,
                                            values[0], values[1], values[2], 0);
        else
            DDV2CatcherLogL3(TRACE_DDV2_CONTEXTATTRIB, DDV2_TRC_WFCMMSETCONTEXTATTRIBIV1,
                                            drv_get_current_time(),
                                            (kal_uint32)kal_get_current_thread_ID(),
                                            ctx,
                                            attrib,
                                            values[0], values[1], values[2], (count==4)?values[3]:0);
    }
                                     
    GET_CONTEXT_NR(pContext, ctx);
    if(_wfc_is_context_in_autonomous_mode(ctx) == WFC_FALSE)
    {
        ///route to Non-mm set 
        DDV2CatcherLogL3(TRACE_DDV2_ERROR, DDV2_TRC_ERROR_AUTOMODE_STATEERROR,
                                         drv_get_current_time(),
                                         (kal_uint32)kal_get_current_thread_ID(),
                                         WFC_MMSetContextAttribiv,
                                         pContext->_autonomousMode);
        wfcSetContextAttribiv(dev, ctx, attrib, count, values);
        return;
    }
    
    if ((count < 1) || (NULL == values))
    {
        _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        return;
    }

    switch (attrib)
    {
    case WFC_CONTEXT_CALLBACK_MTK: 
        {
            kal_uint32 i,j, firstEmpty;
            kal_bool found;
            WFC_ASSERT(count >= 4); // TODO: [o] Magical number...

            for (i = 0; i+4 <= count; i+=4) // For each callback set...
            {
                if (WFC_TRUE == (WFCboolean) values[i+3]) // add one callback function...
                {
                    firstEmpty = WFC_CONTEXT_MM_CALLBACK_COUNT;
                    found = KAL_FALSE;
                    for (j = WFC_CONTEXT_MM_CALLBACK_COUNT; j-- != 0; )
                    {
                        // Find an empty slot...
                        if (pContext->cachedRWAttrib->mmCallbacks[j].cbfunc == NULL)
                        {
                            firstEmpty = j;
                        }

                        // Find if already inserted. If found, break
                        if ((pContext->cachedRWAttrib->mmCallbacks[j].event == (WFCContextEventTypeMTK) values[i+0]) && 
                            (pContext->cachedRWAttrib->mmCallbacks[j].cbfunc == (WFCCallbackFunctionPtrMTK) values[i+1]) && 
                            (pContext->cachedRWAttrib->mmCallbacks[j].cbparam == (void*) values[i+2]))
                        {
                            found = KAL_TRUE;
                            break;
                        }
                    }
                    // There is an empty slot also the callback is never inserted before...
                    if ((firstEmpty != WFC_CONTEXT_MM_CALLBACK_COUNT) && (KAL_FALSE == found))
                    {
                        pContext->cachedRWAttrib->mmCallbacks[firstEmpty].event = (WFCContextEventTypeMTK) values[i];
                        pContext->cachedRWAttrib->mmCallbacks[firstEmpty].cbfunc = (WFCCallbackFunctionPtrMTK) values[(i+1)];
                        pContext->cachedRWAttrib->mmCallbacks[firstEmpty].cbparam = (void*) values[(i+2)];
                    }
                }
                else // remove one callback function...
                {
                    for (j = WFC_CONTEXT_MM_CALLBACK_COUNT; j-- != 0; )
                    {
                        if ((pContext->cachedRWAttrib->mmCallbacks[j].event == (WFCContextEventTypeMTK) values[i+0]) && 
                            (pContext->cachedRWAttrib->mmCallbacks[j].cbfunc == (WFCCallbackFunctionPtrMTK) values[i+1]) && 
                            (pContext->cachedRWAttrib->mmCallbacks[j].cbparam == (void*) values[i+2]))
                        {
                            pContext->cachedRWAttrib->mmCallbacks[j].event = (WFCContextEventTypeMTK) 0x0;
                            pContext->cachedRWAttrib->mmCallbacks[j].cbfunc = NULL;
                            pContext->cachedRWAttrib->mmCallbacks[j].cbparam = NULL;
                            break;
                        }
                    }
                }
            }

            break;
        }

        // KeTing: For autonomous mode, set sync source
    case WFC_CONTEXT_AUTONOMOUS_SYNC_TRIGGER_MTK:
        {
            //WFC_ASSERT(count >= 3);
            //pContext->cachedRWAttrib->autonomousSync.syncTrigger = (WFCAutonomousSyncTriggerMTK) values[0];
            //pContext->cachedRWAttrib->autonomousSync.period = (WFCuint) values[1];
            //pContext->cachedRWAttrib->autonomousSync.element = (WFCElement) values[2];
            
            //pContext->cachedRWAttrib->syncTrigger = (WFCAutonomousSyncTriggerMTK) values[0];
            //pContext->cachedRWAttrib->period = (WFCuint) values[1];
            //pContext->cachedRWAttrib->sync_element = (WFCElement) values[2];

            _wfc_set_error(WFC_ERROR_UNSUPPORTED);

            break;
        }


        ///Bin: From here, the attribute setting is illegal for MM
    case WFC_CONTEXT_BG_COLOR: 
    case WFC_CONTEXT_WORKING_BUFFER_MTK: 
    case WFC_CONTEXT_DESTINATION_RECTANGLE_MTK: 
    case WFC_CONTEXT_ROI_RECTANGLE_MTK: 
    case WFC_CONTEXT_CONCURRENT_MEMORY_OUT_RECT_MTK: 
            DDV2CatcherLogL3(TRACE_DDV2_ERROR, DDV2_TRC_ERROR_ILLEGAL_WFCMMSETCONTEXTATTRIBIV,
                                             drv_get_current_time(),
                                             (kal_uint32)kal_get_current_thread_ID(),
                                             ctx,
                                             attrib);
        _wfc_set_error(WFC_ERROR_MM_SET_ATTR_MTK);
        break;

    case WFC_CONTEXT_ALL_ATTRIBUTES_MTK:
        kal_mem_cpy((void*)pContext->cachedRWAttrib->syncTrigger, (void*)values, (sizeof(WFCCtxtRWAttrib) - ((kal_uint32)&(pContext->cachedRWAttrib->syncTrigger) - (kal_uint32)(pContext->cachedRWAttrib))));
    default: 
        _wfc_set_error(WFC_ERROR_BAD_ATTRIBUTE);
        break;
    }
	

    return;
}
/**
 *  \status OK
 */
WFC_API_CALL WFCint WFC_APIENTRY
wfcMMGetElementAttribi(WFCDevice dev,
                     WFCElement element,
                     WFCElementAttrib attrib) WFC_APIEXIT
{
    return wfcGetElementAttribi(dev,element,attrib);
}


/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcMMGetElementAttribiv(WFCDevice dev,
                      WFCElement element,
                      WFCElementAttrib attrib,
                      WFCint count,
                      WFCint *values) WFC_APIEXIT
{
    wfcGetElementAttribiv(dev, element,attrib,count,values);
    return;
}

WFC_API_CALL void WFC_APIENTRY
wfcMMSetElementAttribi(WFCDevice dev,
                     WFCElement element,
                     WFCElementAttrib attrib,
                     WFCint value) WFC_APIEXIT
{
    WFCElementConfig* pElement = NULL;
    WFCContextConfig* pContext = NULL;

    DDV2CatcherLogL3(TRACE_DDV2_ELEMENTATTRIB, DDV2_TRC_WFCMMSETELEMENTATTRIBI,
                                     drv_get_current_time(),
                                     (kal_uint32)kal_get_current_thread_ID(),
                                     element,
                                     attrib,
                                     value);
    GET_ELEMENT_NR(pElement, element);
    GET_CONTEXT_NR(pContext, pElement->_context);
    if(_wfc_is_context_in_autonomous_mode(pElement->_context) == WFC_FALSE)
    {
        ///route to Non-mm set 
        DDV2CatcherLogL3(TRACE_DDV2_ERROR, DDV2_TRC_ERROR_AUTOMODE_STATEERROR,
                                         drv_get_current_time(),
                                         (kal_uint32)kal_get_current_thread_ID(),
                                         WFC_MMSetElementAttribi,
                                         pContext->_autonomousMode);

        wfcSetElementAttribi(dev,element,attrib,value);     
        return;
    }

    switch (attrib)
    {
    case WFC_ELEMENT_SOURCE: 
        {
            WFCSourceConfig* pSource = (WFCSourceConfig*) value;
            // If the input source handle is NULL, it means user wants to remove the connection between the source and element.
            WFCSourceConfig* pOriSource;
            pOriSource = (WFCSourceConfig*)(pElement->cachedRWAttrib->source);
            if (pOriSource)
                pOriSource->element = WFC_INVALID_HANDLE;
            pElement->cachedRWAttrib->source = (WFCSource) value;
            // If the input source handle is NULL, it means user wants to remove the connection between the source and element.
            if (pSource)
            {
                pSource->element = element;
            }

            break;
        }  
    case WFC_ELEMENT_SOURCE_FLIP: 
        pElement->cachedRWAttrib->flip = (WFCboolean) value;
        break;
    case WFC_ELEMENT_SOURCE_ROTATION: 
        pElement->cachedRWAttrib->rotationAngle = (WFCRotation) value;
        break;

    case WFC_ELEMENT_VIDEO_LAYER_MTK: 
        pElement->cachedRWAttrib->isVideoLayer = (WFCboolean) value;
        break;
    case WFC_ELEMENT_DC_LAYER_MTK: 
        pElement->cachedRWAttrib->isDCLayer = (WFCboolean) value;
        break;


        ///Bin: From here, the attribute setting is illegal for MM
    case WFC_ELEMENT_SOURCE_COLOR_KEY_MTK: 
    case WFC_ELEMENT_DITHERING_MTK: 
    case WFC_ELEMENT_TRANSPARENCY_TYPES: 
    case WFC_ELEMENT_GLOBAL_ALPHA: 
          DDV2CatcherLogL3(TRACE_DDV2_ERROR, DDV2_TRC_ERROR_ILLEGAL_WFCMMSETELEMENTATTRIBI,
                                             drv_get_current_time(),
                                             (kal_uint32)kal_get_current_thread_ID(),
                                             element,
                                             attrib,
                                             value);   
        _wfc_set_error(WFC_ERROR_MM_SET_ATTR_MTK);
        break;

#ifdef DRV_LCD_3D_MODE_SUPPORT
		//currently,MDP can only set attribute:WFC_ELEMENT_3D_LAYER_MTK,but can expand here if need other attribute.
		case WFC_ELEMENT_3D_LAYER_MTK: 
          pElement->cachedRWAttrib->is3DLayer = (WFCboolean) value;
          break;	  
#endif
    default: 
        _wfc_set_error(WFC_ERROR_BAD_ATTRIBUTE);
        break;
    }

    return;
}


WFC_API_CALL void WFC_APIENTRY
wfcMMSetElementAttribiv(WFCDevice dev,
                      WFCElement element,
                      WFCElementAttrib attrib,
                      WFCint count,
                      const WFCint *values) WFC_APIEXIT
{
    WFCElementConfig* pElement = NULL;
    WFCContextConfig* pContext = NULL;

    if ((count >= 3) && (values != NULL))
       DDV2CatcherLogL3(TRACE_DDV2_ELEMENTATTRIB, DDV2_TRC_WFCMMSETELEMENTATTRIBIV,
                                            drv_get_current_time(),
                                            (kal_uint32)kal_get_current_thread_ID(),
                                            element,
                                            attrib,
                                            values[0], values[1], values[2], (count==4)?values[3]:0);
                                     
    GET_ELEMENT_NR(pElement, element);
    GET_CONTEXT_NR(pContext, pElement->_context);
    if(_wfc_is_context_in_autonomous_mode(pElement->_context) == WFC_FALSE)
    {
        ///route to Non-mm set 
        DDV2CatcherLogL3(TRACE_DDV2_ERROR, DDV2_TRC_ERROR_AUTOMODE_STATEERROR,
                                         drv_get_current_time(),
                                         (kal_uint32)kal_get_current_thread_ID(),
                                         WFC_MMSetElementAttribiv,
                                         pContext->_autonomousMode);

        wfcSetElementAttribiv(dev,element,attrib,count, values);                                 
        return;
    }

    if ((0 >= count) || (NULL == values))
    {
        _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        return;
    }

    switch (attrib)
    {
    case WFC_ELEMENT_SOURCE_RECTANGLE: /* WFCint[4] ==> (offsetX, offsetY, width, height) */
        WFC_ASSERT(4 == count);
        if (4 != count)
        {
            _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
            break;
        }
        pElement->cachedRWAttrib->sourceRect.x = (OWFint) values[0];
        pElement->cachedRWAttrib->sourceRect.y = (OWFint) values[1];
        pElement->cachedRWAttrib->sourceRect.width = (OWFint) values[2];
        pElement->cachedRWAttrib->sourceRect.height = (OWFint) values[3];
        break;
    case WFC_ELEMENT_ALL_ATTRIBUTES_MTK:
        kal_mem_cpy((void *)pElement->cachedRWAttrib->source, (void *)values, (sizeof(WFCElementRWAttrib) - ((kal_uint32)&(pElement->cachedRWAttrib->source) - (kal_uint32)(pElement->cachedRWAttrib))));
        break;
    default:
        _wfc_set_error(WFC_ERROR_BAD_ATTRIBUTE); 
        break;
    }

    return;
}


/**
 *  \status XX
 *  this commit function is only for MM auto mode commit
 *  the commited configurations are limitited
 *  for context: only the attributes after syncTrigger(include syncTrigger) in WFCCtxtRWAttrib will be commited and shared attributes (Callback)
 *  for element only the attributes after source(include source) in WFCElementRWAttrib will be commited
 */
WFC_API_CALL void WFC_APIENTRY
wfcMMCommit(WFCDevice dev, WFCContext ctx, WFCElement element, WFCMMCommitType commitType)
{
    WFCContextConfig* pContext = NULL;
    kal_uint32 savedMask;
    kal_bool sync_mode_change = KAL_FALSE;
    WFCboolean needResourceChecking = WFC_FALSE; // KeTing: To see if the commit need to check resource
    WFCSourceConfig* newSource = WFC_INVALID_HANDLE;
    WFCSourceConfig* oldSource = WFC_INVALID_HANDLE;
    WFCElementConfig* pElement = NULL; 
                                     
    wfcTrace(WFCDBG____AUTO_MODE__________COMMIT);
    
    GET_CONTEXT_NR(pContext, ctx);
    GET_ELEMENT_NR(pElement, element);

    //  This is workaround for MED and MDI design
    //  Bin: MDI may Deactivate before make CAL stop, therefore CAL will call wfcMMCommit in none-auto mode 
    //  please refer to mdi_camera_capture_with_quickview()  
    //  1 deactivate  --- MDI
    //  2 exit preview --- MED
    //  3 start capture --- MED
    if(_wfc_is_context_in_autonomous_mode(ctx) == WFC_FALSE)
    {
        DDV2CatcherLogL3(TRACE_DDV2_ERROR, DDV2_TRC_ERROR_AUTOMODE_STATEERROR,
                                         drv_get_current_time(),
                                         (kal_uint32)kal_get_current_thread_ID(),
                                         WFC_MMCommit,
                                         pContext->_autonomousMode);

        ///route to Non-mm commit 
        wfcCommit(dev, ctx, WFC_TRUE);
        return;
    }
    
    // Parameter checking
    if((element == WFC_INVALID_HANDLE) && ((commitType & WFC_COMMIT_ELEMENT) == 0))
    {
        WFC_ASSERT(0);
    }
    
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
    if (!(kal_if_lisr() || kal_if_hisr()))
#endif
        WFC_Commit_Lock();
        
    DDV2CatcherLogL3(TRACE_DDV2_RENDERING, DDV2_TRC_WFCMMCOMMIT,
                                     drv_get_current_time(),
                                     (kal_uint32)kal_get_current_thread_ID(),
                                     ctx,
                                     element,
                                     commitType);
                                     
    //Zifeng: Check if sync_mode has changed
    if(commitType & WFC_COMMIT_CONTEXT)
    {    
        if ((pContext->cachedRWAttrib->syncTrigger) != (pContext->capturedRWAttrib->syncTrigger))
        {
            sync_mode_change = KAL_TRUE;
            _wfc_clear_autonomous_sync_trigger(pContext);
        }
    }                                     

    {
        /// Mask IRQ here to protect racing of any blt behavior triggered from Timer HISR or MDP callback HISR
        #if defined(MT6253)
            savedMask = kal_take_thread_protect();
        #else
            savedMask = SaveAndSetIRQMask();
        #endif

        // Bin: update context attributes here
        if(commitType & WFC_COMMIT_CONTEXT)
        {
            ///Commit attributes belonged to MM
            kal_mem_cpy((void*)(&pContext->capturedRWAttrib->syncTrigger),
                        (void*)(&pContext->cachedRWAttrib->syncTrigger),
                        (sizeof(WFCCtxtRWAttrib) - ((kal_uint32)&(pContext->capturedRWAttrib->syncTrigger) - (kal_uint32)(pContext->capturedRWAttrib))));
        }                

        // Bin: commit video layer attributes here
        if(commitType & WFC_COMMIT_ELEMENT)
        {
            newSource = (WFCSourceConfig*) pElement->capturedRWAttrib->source;
            oldSource = (WFCSourceConfig*) pElement->cachedRWAttrib->source;

            pElement->_context = (WFCContext)pContext;
            // Bin: update MM owned attributes to captured here
            kal_mem_cpy((void *)&(pElement->capturedRWAttrib->source),
                        (void *)&(pElement->cachedRWAttrib->source),
                        (sizeof(WFCElementRWAttrib) - ((kal_uint32)&(pElement->capturedRWAttrib->source) - (kal_uint32)(pElement->capturedRWAttrib))));

            // KeTing: If the context is busy here, the current rendering must have used the old settings
            // KeTing: Thus have to check whether the resouce is going to be removed
            if (WFC_TRUE == pContext->_busy)
            {
                needResourceChecking = WFC_TRUE;
            }
        }

        #if defined(MT6253)
            kal_give_thread_protect(savedMask);
        #else
            RestoreIRQMask(savedMask);
        #endif
    }

    // KeTing: Block here if some of the resource being changed is under using
    if ((WFC_TRUE == needResourceChecking) && (commitType & WFC_COMMIT_ELEMENT))
    {
        WFCboolean needBlocking = WFC_FALSE;

        // KeTIng: Check if the source of this element is changed
        {
          if (newSource != oldSource)
          {
              needBlocking = WFC_TRUE;
          }
          else if ((WFC_INVALID_HANDLE != newSource) && (WFC_INVALID_HANDLE != oldSource))
          {
            if (newSource->image.data != oldSource->image.data)
            {
              needBlocking = WFC_TRUE;
            }
          }
        }

        if (WFC_TRUE == needBlocking)
        {
            if (WFC_TRUE == pContext->_busy)
            {
                kal_uint32 event_group;
                kal_retrieve_eg_events(_owf_event,
                    (kal_uint32)(_wfc_convert_context_handle_to_frame_done_enum(pContext)),
                    KAL_OR, &event_group, KAL_SUSPEND);
            }
        }
    }

    // KeTing: Attached the stream callback function to each inserted elements
    // KeTing: The callback function will be removed when element is being destroyed
    if(commitType & WFC_COMMIT_ELEMENT)
    {
        WFCSourceConfig* pSource = (WFCSourceConfig*) pElement->capturedRWAttrib->source;
        if ((NULL != pSource) && pSource->useStream && (NULL != pSource->stream))
        {
            owfNativeStreamAddObserver(pSource->stream, _wfc_stream_event_hdlr, (void *)pElement);
        DDV2CatcherLogL3(TRACE_DDV2_AUTOMODE, DDV2_TRC_ADDOBSERVER,
                                         drv_get_current_time(),
                                         (kal_uint32)kal_get_current_thread_ID(),
                                         (kal_uint32)pElement,
                                         (kal_uint32)pSource,
                                         (kal_uint32)pSource->stream);
                                     
        }
    }

    // KeTing: Invoke the autonomous commit callback
    if(commitType & WFC_COMMIT_CONTEXT)
    {    
        if (sync_mode_change)
        {
            if (WFC_FALSE == _wfc_autonomous_commit_callback(pContext))
            {
                _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
            }
        }
    }
    
    DDV2CatcherLogL3(TRACE_DDV2_RENDERING, DDV2_TRC_WFCMMCOMMITEND,
                                     drv_get_current_time(),
                                     (kal_uint32)kal_get_current_thread_ID());
#if defined(__CAMERA_MATV_ESD_RECOVERY_SUPPORT__)
    if (!(kal_if_lisr() || kal_if_hisr()))
#endif
        WFC_Commit_Unlock();
        
    return;
}


/**
 *  \status XX
 *  this commit function is only for GDI commit cached setting 
 *  the commited configurations are limitited in auto mode
 *  for context: only the attributes before syncTrigger in WFCCtxtRWAttrib will be commited and shared attributes (Callback) in auto mode
 *  for video element only the attributes before source in WFCElementRWAttrib will be commited in auto mode
 */
WFC_API_CALL void WFC_APIENTRY
wfcCommit(WFCDevice dev, WFCContext ctx, WFCboolean wait)
{
    WFCContextConfig* pContext = NULL;
    kal_uint32 i, j;
    kal_uint32 savedMask;
    WFCboolean needResourceChecking = WFC_FALSE; // KeTing: To see if the commit need to check resource
    WFCboolean inAutoMode = WFC_FALSE;
    
    ///Bin: for auto mode , context commit used
    kal_uint32 mmOwnedContextSize;
    kal_uint8 tempBuffer[sizeof(WFCCtxtRWAttrib)];

    wfcTrace(WFCDBG_______________________COMMIT);

    GET_CONTEXT_NR(pContext, ctx);

    mmOwnedContextSize = sizeof(WFCCtxtRWAttrib) - ((kal_uint32)&(pContext->capturedRWAttrib->syncTrigger) - (kal_uint32)(pContext->capturedRWAttrib));

    WFC_Commit_Lock();
    DDV2CatcherLogL3(TRACE_DDV2_RENDERING, DDV2_TRC_WFCCOMMIT,
                                     drv_get_current_time(),
                                     (kal_uint32)kal_get_current_thread_ID(),
                                     ctx,
                                     pContext->cachedRWAttrib->roiRect.x,
                                     pContext->cachedRWAttrib->roiRect.y,
                                     pContext->cachedRWAttrib->roiRect.width,
                                     pContext->cachedRWAttrib->roiRect.height,
                                     wait);

    ///Bin: Get to know if WFC is in autonomous mode currently, 
    ///       since Commit behavior will be different depends on auto mode
    inAutoMode = _wfc_is_context_in_autonomous_mode(ctx);

    // This code segment is to ignore the width/height of destination Rectangle.
    for (i = WFC_CONTEXT_MAX_INSERTED_ELEMENT; i-- != 0; )
    {
        WFCElementConfig* pElement = (WFCElementConfig*)pContext->cachedRWAttrib->_insertedElements[i];
        if (WFC_INVALID_HANDLE != pElement)
        {
            if((inAutoMode == WFC_TRUE) && (pElement->cachedRWAttrib->isVideoLayer == WFC_TRUE))
            {
                continue;
            }
            else
            {
                OWF_RECTANGLE *srcRect = &(pElement->cachedRWAttrib->sourceRect);
                OWF_RECTANGLE *dstRect = &(pElement->cachedRWAttrib->destinationRect);
                if ((pElement->cachedRWAttrib->rotationAngle == WFC_ROTATION_90) || 
                    (pElement->cachedRWAttrib->rotationAngle == WFC_ROTATION_270))
                {
                    dstRect->width = srcRect->height;
                    dstRect->height = srcRect->width;
                }
                else
                {
                    dstRect->width = srcRect->width;
                    dstRect->height = srcRect->height;
                }
            }
        }
    }


    {
        /// Mask IRQ here to protect racing of any blt behavior triggered from Timer HISR or MDP callback HISR
        #if defined(MT6253)
            savedMask = kal_take_thread_protect();
        #else
            savedMask = SaveAndSetIRQMask();
        #endif
        // Bin: Commit the element attributes here
        for (i = WFC_CONTEXT_MAX_INSERTED_ELEMENT; i-- != 0; )
        {
            if (WFC_INVALID_HANDLE != pContext->cachedRWAttrib->_insertedElements[i])
            {
                WFCElementConfig* pElement = (WFCElementConfig*) pContext->cachedRWAttrib->_insertedElements[i];
                WFCElementRWAttrib *tempElementAttrib = pElement->cachedRWAttrib;

                if((inAutoMode == WFC_TRUE) && (pElement->cachedRWAttrib->isVideoLayer == WFC_TRUE))
                {
                    ///Bin: If video layer and in auto mode, 
                    ///       only update GDI own attribute (the attributes before source in WFCElementRWAttrib) for Video layer ,
                    ///       therefore uusing memory copy here rather than  swap the pointers
                    kal_mem_cpy(((void *)pElement->capturedRWAttrib),
                        ((void *)pElement->cachedRWAttrib),
                        ((kal_uint32)&(pElement->capturedRWAttrib->source) - (kal_uint32)(pElement->capturedRWAttrib)));
                }   
                else
                {
                    ///Bin: Swap the element attributes pointers for None-video layer
                    pElement->cachedRWAttrib = pElement->capturedRWAttrib;
                    pElement->capturedRWAttrib = tempElementAttrib;

                    pElement->_context = (WFCContext)pContext;
                }
            }
        }

        // Bin: Commit the context attributes here          
        {
            // Bin: Swap the context attributes pointers
            WFCCtxtRWAttrib *tempContextAttrib = pContext->cachedRWAttrib;
            pContext->cachedRWAttrib = pContext->capturedRWAttrib;
            pContext->capturedRWAttrib = tempContextAttrib;

            ///Bin: in auto mode, wfcCommit is only allowed to commit the context attributes before syncTrigger in WFCCtxtRWAttrib
            ///       Because we swap pointer before, therefore we need to restore the commited setting owned by MM here
            if(inAutoMode == WFC_TRUE)
            {            
                // restore MM owned attributes
                kal_mem_cpy((void*)tempBuffer,
                            (void*)(&pContext->cachedRWAttrib->syncTrigger),
                            mmOwnedContextSize);

                kal_mem_cpy((void*)(&pContext->cachedRWAttrib->syncTrigger),
                            (void*)(&pContext->capturedRWAttrib->syncTrigger),
                            mmOwnedContextSize);

                kal_mem_cpy((void*)(&pContext->capturedRWAttrib->syncTrigger),
                            (void*)tempBuffer,
                            mmOwnedContextSize);
            }
        }

        // Bin: _autoModeCommitLatched flag is used to make sure when invoke callback function,
        //          this time attribute config setting is applied (this flag if set before trigger WFD)
        //          if this is false, current blting callback function will not invoke callback
        if (&_wfc_context_cfg_frame_buffer != pContext && (inAutoMode == WFC_TRUE))
            pContext->_autoModeCommitLatched = WFC_FALSE;


        // KeTing: If the context is busy here, the current rendering must have used the old settings
        // KeTing: Thus have to check whether the resouce is going to be removed
        if (WFC_TRUE == pContext->_busy)
        {
            needResourceChecking = WFC_TRUE;
        }
        else
        {
        	if (inAutoMode == WFC_TRUE)
        	{
        		_wfc_committed_flag = WFC_TRUE; //Xiaoyong:WFC not busy, the commit indicates the blt request is valid in auto mode
         	}
        }

        #if defined(MT6253)
            kal_give_thread_protect(savedMask);
        #else
            RestoreIRQMask(savedMask);
        #endif


    }

    // KeTing: Block here if some of the resource being changed is under using,
    ///           in case GDI will corrupt the source buffer after return this function
    if (WFC_TRUE == needResourceChecking)
    {
        WFCboolean needBlocking = WFC_FALSE;

        // KeTing: To minimize the waiting time, we have to check the changed items are resources under using or not
        // KeTing: The resources we should protect are wfc sources and wfc elements
        // KeTing: Target for flt didn't be considered here because we do not allow flt in auto mode
        // KeTing: Since wfcCommit should only be called in task level, we will not use I-bit protection here
        for (i = 0; i < WFC_CONTEXT_MAX_INSERTED_ELEMENT; i++)
        {
            WFCElementConfig* pElement = (WFCElementConfig*)pContext->cachedRWAttrib->_insertedElements[i];
            if (WFC_INVALID_HANDLE != pElement)
            {
                // KeTing: Check if the element is removed or not
                {
                    for (j = 0; j < WFC_CONTEXT_MAX_INSERTED_ELEMENT; j++)
                    {
                        if ((WFCElement)pElement == pContext->capturedRWAttrib->_insertedElements[j])
                        {
                            break;
                        }
                    }

                    // Bin: if can not find the element , it means this element is removed...
                    //        need blocking to wait for current blt finish
                    if ( WFC_CONTEXT_MAX_INSERTED_ELEMENT == j)
                    {
                        needBlocking = WFC_TRUE;
                        break;
                    }
                }
                // KeTIng: Check if the source of this element is changed
                {
                    WFCSourceConfig* newSource = (WFCSourceConfig*) pElement->capturedRWAttrib->source;
                    WFCSourceConfig* oldSource = (WFCSourceConfig*) pElement->cachedRWAttrib->source;
                    if (WFC_INVALID_HANDLE != newSource && WFC_INVALID_HANDLE != oldSource)
                    {
                        if (newSource->image.data != oldSource->image.data)
                        {
                            needBlocking = WFC_TRUE;
                            break;
                        }
                    }
                }
            }
        }

        // Bin: if need blocking, wait for current blt done here
        if (WFC_TRUE == needBlocking)
        {
            if (WFC_TRUE == pContext->_busy)
            {
                kal_uint32 event_group;
                kal_retrieve_eg_events(_owf_event,
                    (kal_uint32)(_wfc_convert_context_handle_to_frame_done_enum(pContext)),
                    KAL_OR, &event_group, KAL_SUSPEND);
            }
        }
        if (inAutoMode == WFC_TRUE)
        {
        	_wfc_committed_flag = WFC_TRUE;//Xiaoyong:WFC busy,after the blocking check,the commit indicates the blt request is valid in auto mode
       }
		
    }

    {
        // Bin: 1. for Non-video layer, memcpy captured setting to cached setting to make they are same (since previously , we only swap the pointers...)
        //        2. for video layer in auto mode,  do nothing 
        for (i = WFC_CONTEXT_MAX_INSERTED_ELEMENT; i-- != 0; )
        {
            if (WFC_INVALID_HANDLE != pContext->capturedRWAttrib->_insertedElements[i])
            {
                WFCElementConfig* pElement = (WFCElementConfig*) pContext->capturedRWAttrib->_insertedElements[i];

                if((inAutoMode == WFC_TRUE) && (pElement->capturedRWAttrib->isVideoLayer == WFC_TRUE))
                {
                    continue;
                }
                else
                {
                    // Copy captured attributes to cached attributes
                    kal_mem_cpy((void*) (pElement->cachedRWAttrib), 
                        (void*) (pElement->capturedRWAttrib), 
                        sizeof(WFCElementRWAttrib));
                }
            }
        }

        // Bin: Copy context captured attributes to cached attributes if not in auto mode
        if(inAutoMode == WFC_FALSE)
        {
            kal_mem_cpy((void*) (pContext->cachedRWAttrib), 
                (void*) (pContext->capturedRWAttrib), 
                sizeof(WFCCtxtRWAttrib));
        }
        else    
        {   
            // Bin: If in auto mode, only copy the context attributes owned by GDI to cached attributes
            kal_mem_cpy((void*)(pContext->cachedRWAttrib),
                        (void*)(pContext->capturedRWAttrib),
                        ((kal_uint32)&(pContext->capturedRWAttrib->syncTrigger) - (kal_uint32)(pContext->capturedRWAttrib)));
        }
    }


    // KeTing: Attached the stream callback function to each inserted elements
    // KeTing: The callback function will be removed when element is being destroyed
    for (i = WFC_CONTEXT_MAX_INSERTED_ELEMENT; i-- != 0; )
    {
        if (WFC_INVALID_HANDLE != pContext->capturedRWAttrib->_insertedElements[i])
        {
            WFCElementConfig* pElement = (WFCElementConfig*) pContext->capturedRWAttrib->_insertedElements[i];
            WFCSourceConfig* pSource = (WFCSourceConfig*) pElement->capturedRWAttrib->source;

            
            if((inAutoMode == WFC_TRUE) && (pElement->cachedRWAttrib->isVideoLayer == WFC_TRUE))
            {
                ///Bin: For video layer in automode, the sttribute is belonged to MM, will done in wfcMMCommit()
                continue;
            }
            else
            {
                ///Bin: if the element using stream as source, add callback function for this stream
                if ((NULL != pSource) && pSource->useStream && (NULL != pSource->stream))
                {
                    owfNativeStreamAddObserver(pSource->stream, _wfc_stream_event_hdlr, (void *)pElement);
                    DDV2CatcherLogL3(TRACE_DDV2_AUTOMODE, DDV2_TRC_ADDOBSERVER,
                                                 drv_get_current_time(),
                                                 (kal_uint32)kal_get_current_thread_ID(),
                                                 (kal_uint32)pElement,
                                                 (kal_uint32)pSource,
                                                 (kal_uint32)pSource->stream);
                }
            }
        }
    }

    DDV2CatcherLogL3(TRACE_DDV2_RENDERING, DDV2_TRC_WFCCOMMITEND,
                                           drv_get_current_time(),
                                           (kal_uint32)kal_get_current_thread_ID());
    WFC_Commit_Unlock();
    return;
}

/*=========================================================================*/
/* 5. CONTEXT                                                              */
/*=========================================================================*/
/**
 *  \status OK
 */
WFC_API_CALL WFCContext WFC_APIENTRY
wfcCreateOnScreenContext(WFCDevice dev,
                         WFCint screenNumber,
                         const WFCint* attribList)
{
    volatile WFCContextConfig* pContext = NULL;
    //kal_uint32 i = WFC_CONTEXT_MAX_WORKING_BUF_COUNT;

    wfcTrace(WFCDBG____CREATE_________ONSRN_CNXT);

    if (WFC_SCREEN_LCD_0 == screenNumber)
    {
        pContext = &_wfc_context_cfg_lcd_0;
    }
#ifdef DUAL_LCD
    else if (WFC_SCREEN_LCD_1 == screenNumber)
    {
        pContext = &_wfc_context_cfg_lcd_1;
    }
#endif
    else
    {
        _wfc_set_error(WFC_ERROR_UNSUPPORTED);
        return WFC_INVALID_HANDLE;
    }

    pContext->type = WFC_CONTEXT_TYPE_ON_SCREEN;
    pContext->cachedRWAttrib->syncTrigger = WFC_AUTONOMOUS_SYNC_TO_TIMER;
    pContext->cachedRWAttrib->currRefreshRate = 15;
    pContext->capturedRWAttrib->currRefreshRate = 15;
    pContext->cachedRWAttrib->enableVsync = WFC_TRUE;

    if (WFC_SCREEN_LCD_0 == screenNumber)
        pContext->_timer = kal_create_timer("LCD_WFC_AUTO_0");
    else
        pContext->_timer = kal_create_timer("LCD_WFC_AUTO_1");

    return (WFCContext) pContext;
}

/**
 *  \status OK
 */
WFC_API_CALL WFCContext WFC_APIENTRY
wfcCreateOffScreenContext(WFCDevice dev,
                          WFCNativeStreamType stream,
                          const WFCint *attribList)
{
    WFCContextConfig* pContext = NULL;
    //WFCint portId = 0;

    return (WFCContext) pContext;
}

WFC_API_CALL WFCContext WFC_APIENTRY
wfcCreateOffScreenContextMTK(WFCDevice dev,
                             WFCHandle image,
                             const WFCint *attribList)
{
    volatile WFCContextConfig* pContext = NULL;

    wfcTrace(WFCDBG____CREATE________OFFSRN_CNXT);

    pContext = &_wfc_context_cfg_frame_buffer;
    
    pContext->type = WFC_CONTEXT_TYPE_OFF_SCREEN;
    pContext->cachedRWAttrib->syncTrigger = WFC_AUTONOMOUS_SYNC_TO_NONE;
    // Set target image
    kal_mem_cpy((void*) &(pContext->cachedRWAttrib->memOutTarget.image), 
        (void*) image, sizeof(OWF_IMAGE));
    kal_mem_cpy((void*) &(pContext->capturedRWAttrib->memOutTarget.image), 
        (void*) image, sizeof(OWF_IMAGE));

    pContext->_timer = KAL_NILTIMER_ID;

    return (WFCContext) pContext;
}


/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcDestroyContext(WFCDevice dev,
                  WFCContext ctx)
{

}

/**
 *  \status OK
 */
WFC_API_CALL WFCint WFC_APIENTRY
wfcGetContextAttribi(WFCDevice dev,
                     WFCContext ctx,
                     WFCContextAttrib attrib)
{
    WFCContextConfig* pContext = NULL;
    WFCint ret = 0;

    GET_CONTEXT(pContext, ctx, ret);

    switch (attrib)
    {
    case WFC_CONTEXT_TYPE: 
        ret = (WFCint) pContext->type;
        break;
    case WFC_CONTEXT_TARGET_HEIGHT: 
        ret = (WFCint) ((WFD_PORT*)(pContext->_port))->config.portHeight;
        break;
    case WFC_CONTEXT_TARGET_WIDTH: 
        ret = (WFCint) ((WFD_PORT*)(pContext->_port))->config.portWidth;
        break;
    case WFC_CONTEXT_LOWEST_ELEMENT: 
        ret = (WFCint) 0;
        break;
    case WFC_CONTEXT_WORKING_BUFFER_REQ_MTK: 
        ret = (WFCint) 0;
        break;
    case WFC_CONTEXT_REFRESH_RATES_MTK: 
        ret = (WFCint) 1;
        break;
	case WFC_CONTEXT_BLT_MAX_REFRESH_RATE_MTK:
		ret = (WFCint) ((WFD_PORT*)(pContext->_port))->config.portTearFreeRefreshRate;
        break;
    case WFC_CONTEXT_ROTATION: 
        ret = (WFCint) pContext->cachedRWAttrib->rotationAngle;
        break;
    case WFC_CONTEXT_BG_COLOR: 
        ret = (WFCint) pContext->cachedRWAttrib->bgColor;
        break;
    case WFC_CONTEXT_WORKING_BUFFER_MTK: 
        ret = WFC_CONTEXT_MAX_WORKING_BUF_COUNT*4;
        break;
    case WFC_CONTEXT_CALLBACK_MTK: 
        ret = WFC_CONTEXT_GDI_CALLBACK_COUNT*3;
        break;
    case WFC_CONTEXT_CONCURRENT_MEMORY_OUT_MTK: 
        ret = (WFCint) pContext->cachedRWAttrib->enableConcurrentMemOut;
        break;
    case WFC_CONTEXT_CONCURRENT_MEMORY_OUT_STREAM_MTK: 
        ret = (WFCint) pContext->cachedRWAttrib->memOutTarget.stream;
        break;
    case WFC_CONTEXT_CONCURRENT_MEMORY_OUT_IMAGE_MTK: 
    case WFC_CONTEXT_TARGET_IMAGE_MTK: 
        ret = (WFCint) &(pContext->cachedRWAttrib->memOutTarget.image);
        break;
    case WFC_CONTEXT_TOTAL_VSYNC_COUNT_MTK: 
        // TODO: [r] be careful with this one! since we pass back the captured attrib value.
        //ret = (WFCint) pContext->capturedRWAttrib->totalVsyncCount;
        ret = 0;
        break;
    case WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK: 
        ret = (WFCint) pContext->cachedRWAttrib->currRefreshRate;
        break;
    case WFC_CONTEXT_DESTINATION_RECTANGLE_MTK: 
        ret = 4; // array size...but it is fixed...
        break;
    case WFC_CONTEXT_VSYNC_ENABLE_MTK: 
        ret = (WFCboolean) pContext->cachedRWAttrib->enableVsync;
        break;
    case WFC_CONTEXT_IS_FLATTEN_READY_MTK:
        {
            // KeTing: Only off-screen context support flatten
            if (pContext != &_wfc_context_cfg_frame_buffer)
            {
                ret = (WFCint)WFC_FALSE;
                _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
                break;
            }

            if (WFC_TRUE == _wfc_is_engine_in_autonomous_mode(pContext->_engine))
            {
                ret = (WFCint)WFC_FALSE;
            }
            else
            {
                ret = (WFCint)WFC_TRUE;
            }
            break;
        }
    case WFC_CONTEXT_PPI_MTK: 
        {
            ret = ((WFD_PORT*)(pContext->_port))->config.ppi;
            if (0 == ret)
            {
                _wfc_set_error(WFC_ERROR_UNSUPPORTED);
            }
            break;
        }
    case WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK: 
        {
            ret = (WFCint)(pContext->cachedRWAttrib->syncTrigger);
            break;
        }
        
    case WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK: 
        {
            ret = (WFCint)(pContext->cachedRWAttrib->period);
            break;
        }
        
    case WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK: 
        {
            ret = (WFCint)(pContext->cachedRWAttrib->sync_element);
            break;
        }
    case WFC_CONTEXT_PALETTE_TABLE_MTK:
        {
            ret = (WFCuint)(pContext->cachedRWAttrib->paletteTable);
            break;
        }
        
    default: 
        _wfc_set_error(WFC_ERROR_BAD_ATTRIBUTE);
        break;
    }

    return ret;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcSetContextAttribi(WFCDevice dev,
                     WFCContext ctx,
                     WFCContextAttrib attrib,
                     WFCint value)
{
    WFCContextConfig* pContext = NULL;
    WFCboolean inAutoMode = WFC_FALSE;
    WFCboolean is_illegal_context_attribi = WFC_FALSE;

    DDV2CatcherLogL3(TRACE_DDV2_CONTEXTATTRIB, DDV2_TRC_WFCSETCONTEXTATTRIBI,
                                     drv_get_current_time(),
                                     (kal_uint32)kal_get_current_thread_ID(),
                                     ctx,
                                     attrib,
                                     value);
    GET_CONTEXT_NR(pContext, ctx);
    inAutoMode = _wfc_is_context_in_autonomous_mode(ctx);

    switch (attrib)
    {
    case WFC_CONTEXT_ROTATION: 
        pContext->cachedRWAttrib->rotationAngle = (WFCRotation) value;
        break;
    case WFC_CONTEXT_BG_COLOR: 
        pContext->cachedRWAttrib->bgColor = (WFCuint) value;
        break;
    case WFC_CONTEXT_CONCURRENT_MEMORY_OUT_MTK: 
        pContext->cachedRWAttrib->enableConcurrentMemOut = (WFCboolean) value;
        break;
    case WFC_CONTEXT_CONCURRENT_MEMORY_OUT_STREAM_MTK: 
        pContext->cachedRWAttrib->memOutTarget.stream = (WFCHandle) value;
        break;
    case WFC_CONTEXT_CONCURRENT_MEMORY_OUT_IMAGE_MTK: 
    case WFC_CONTEXT_TARGET_IMAGE_MTK: 
        kal_mem_cpy((void*) &(pContext->cachedRWAttrib->memOutTarget.image), 
            (void*) value, sizeof(OWF_IMAGE)); 
        break;
    case WFC_CONTEXT_TOTAL_VSYNC_COUNT_MTK: 
        //pContext->cachedRWAttrib->totalVsyncCount = (WFCint) value;
        break;
    case WFC_CONTEXT_VSYNC_ENABLE_MTK:
        pContext->cachedRWAttrib->enableVsync = (WFCboolean) value;
        break;
    case WFC_CONTEXT_PALETTE_TABLE_MTK:
        pContext->cachedRWAttrib->paletteTable = (WFCuint) value;
        break;

        ///Bin: The following are illegal for GDI in Auto mode
    case WFC_CONTEXT_CURRENT_REFRESH_RATE_MTK: 
    {
        if(inAutoMode == WFC_TRUE)
        {
            is_illegal_context_attribi = WFC_TRUE;
        }
        else
        {
            pContext->cachedRWAttrib->currRefreshRate = (WFCint) value;
        }
        break;
    }

    case WFC_CONTEXT_AUTONOMOUS_SYNC_MODE_MTK: 
    {
        if(inAutoMode == WFC_TRUE)
        {
            is_illegal_context_attribi = WFC_TRUE;
        }
        else
        {
            pContext->cachedRWAttrib->syncTrigger = (WFCAutonomousSyncTriggerMTK) value;
        }
        break;
    }
            
    case WFC_CONTEXT_AUTONOMOUS_PERIOD_MTK: 
    {
        if(inAutoMode == WFC_TRUE)
        {
            is_illegal_context_attribi = WFC_TRUE;
        }
        else
        {
            pContext->cachedRWAttrib->period = (WFCuint) value;
        }
        break;
    }
            
    case WFC_CONTEXT_AUTONOMOUS_SYNC_ELEMENT_MTK: 
    {
        if(inAutoMode == WFC_TRUE)
        {
            is_illegal_context_attribi = WFC_TRUE;
        }
        else
        {
            pContext->cachedRWAttrib->sync_element = (WFCElement) value;
        }
        break;
    }

    default: 
        _wfc_set_error(WFC_ERROR_BAD_ATTRIBUTE);
        break;
    }

    if (WFC_TRUE == is_illegal_context_attribi)
    {
        _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        DDV2CatcherLogL3(TRACE_DDV2_ERROR, DDV2_TRC_ERROR_ILLEGAL_WFCSETCONTEXTATTRIBI,
                                         drv_get_current_time(),
                                         (kal_uint32)kal_get_current_thread_ID(),
                                         ctx,
                                         attrib,
                                         value);
    }
    return;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcGetContextAttribiv(WFCDevice dev, 
                      WFCContext ctx, 
                      WFCContextAttrib attrib, 
                      WFCint count, 
                      WFCint *values)
{
    WFCContextConfig* pContext = NULL;

    GET_CONTEXT_NR(pContext, ctx);

    if ((1 > count) || (NULL == values))
    {
        _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        return;
    }

    // clear the values
    kal_mem_set((void*) values, 0x0, sizeof(WFCint)*count);

    switch (attrib)
    {
    case WFC_CONTEXT_WORKING_BUFFER_REQ_MTK:
        {
            break;
        }
    case WFC_CONTEXT_REFRESH_RATES_MTK: 
        {
            values[0] = 30;   ///???
            break;
        }
    case WFC_CONTEXT_BG_COLOR: 
        {
            WFC_ASSERT(count >= 4);
            values[0] = (WFCint) ((pContext->cachedRWAttrib->bgColor >> 16) & 0xFF); // R
            values[1] = (WFCint) ((pContext->cachedRWAttrib->bgColor >>  8) & 0xFF); // G
            values[2] = (WFCint) ((pContext->cachedRWAttrib->bgColor >>  0) & 0xFF); // B
            values[3] = (WFCint) ((pContext->cachedRWAttrib->bgColor >> 24) & 0xFF); // A
            break;
        }
    case WFC_CONTEXT_WORKING_BUFFER_MTK: 
        {
            //kal_uint32 i = 0;
            WFC_ASSERT(count >= 3);
            // TODO: [o] later, there is no need to query this attrib
            break;
        }
    case WFC_CONTEXT_CALLBACK_MTK: 
        {
            //kal_uint32 i = 0;
            WFC_ASSERT(count >= 4);
            // TODO: [o] later, there is no need to query this attrib
            break;
        }
    case WFC_CONTEXT_DESTINATION_RECTANGLE_MTK: 
        {
            WFC_ASSERT(count >= 4);
            values[0] = (WFCint) pContext->cachedRWAttrib->destinationRect.x;
            values[1] = (WFCint) pContext->cachedRWAttrib->destinationRect.y;
            values[2] = (WFCint) pContext->cachedRWAttrib->destinationRect.width;
            values[3] = (WFCint) pContext->cachedRWAttrib->destinationRect.height;
            break;
        }
    case WFC_CONTEXT_ROI_RECTANGLE_MTK: 
        {
            WFC_ASSERT(count >= 4);
            values[0] = (WFCint) pContext->cachedRWAttrib->roiRect.x;
            values[1] = (WFCint) pContext->cachedRWAttrib->roiRect.y;
            values[2] = (WFCint) pContext->cachedRWAttrib->roiRect.width;
            values[3] = (WFCint) pContext->cachedRWAttrib->roiRect.height;
            break;
        }
    case WFC_CONTEXT_CONCURRENT_MEMORY_OUT_RECT_MTK: 
        {
            WFC_ASSERT(count >= 4);
            values[0] = (WFCint) pContext->cachedRWAttrib->concurrentMemOutRect.x;
            values[1] = (WFCint) pContext->cachedRWAttrib->concurrentMemOutRect.y;
            values[2] = (WFCint) pContext->cachedRWAttrib->concurrentMemOutRect.width;
            values[3] = (WFCint) pContext->cachedRWAttrib->concurrentMemOutRect.height;
            break;
        }
        // KeTing: For autonomous sync source
    case WFC_CONTEXT_AUTONOMOUS_SYNC_TRIGGER_MTK:
        {
            //WFC_ASSERT(count >= 3);
            //values[0] = (WFCint) pContext->capturedRWAttrib->autonomousSync.syncTrigger;
            //values[1] = (WFCint) pContext->capturedRWAttrib->autonomousSync.period;
            //values[2] = (WFCint) pContext->capturedRWAttrib->autonomousSync.element;
            
            //values[0] = (WFCint) (pContext->cachedRWAttrib->syncTrigger);
            //values[1] = (WFCint) (pContext->cachedRWAttrib->period);
            //values[2] = (WFCint) (pContext->cachedRWAttrib->sync_element);

            _wfc_set_error(WFC_ERROR_UNSUPPORTED);

            break;
        }
    case WFC_CONTEXT_ALL_ATTRIBUTES_MTK: 
        kal_mem_cpy((void*)values, (void*)pContext->cachedRWAttrib, sizeof(WFCCtxtRWAttrib));
        break;

    default:
        {
            _wfc_set_error(WFC_ERROR_BAD_ATTRIBUTE);
            break;
        }
    }

    return;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcSetContextAttribiv(WFCDevice dev, 
                      WFCContext ctx, 
                      WFCContextAttrib attrib, 
                      WFCint count, 
                      const WFCint *values)
{
    WFCContextConfig* pContext = NULL;
    //WFCboolean inAutoMode = WFC_FALSE;

    if ((count >= 3) && (values != NULL))
    {
        if (attrib==WFC_CONTEXT_AUTONOMOUS_SYNC_TRIGGER_MTK)
            DDV2CatcherLogL3(TRACE_DDV2_CONTEXTATTRIB, DDV2_TRC_WFCSETCONTEXTATTRIBIV2,
                                            drv_get_current_time(),
                                            (kal_uint32)kal_get_current_thread_ID(),
                                            ctx,
                                            attrib,
                                            values[0], values[1], values[2], 0);
        else
            DDV2CatcherLogL3(TRACE_DDV2_CONTEXTATTRIB, DDV2_TRC_WFCSETCONTEXTATTRIBIV1,
                                            drv_get_current_time(),
                                            (kal_uint32)kal_get_current_thread_ID(),
                                            ctx,
                                            attrib,
                                            values[0], values[1], values[2], (count==4)?values[3]:0);
    }

    GET_CONTEXT_NR(pContext, ctx);
    //inAutoMode = _wfc_is_context_in_autonomous_mode(ctx);

    if ((count < 1) || (NULL == values))
    {
        _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        return;
    }

    switch (attrib)
    {
    case WFC_CONTEXT_BG_COLOR: 
        {
            if (count < 4)
            {
                _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
                break;
            }
            pContext->cachedRWAttrib->bgColor = ((((kal_uint32) values[0] & 0xFF) << 16) | 
                (((kal_uint32) values[1] & 0xFF) <<  8) | 
                (((kal_uint32) values[2] & 0xFF) <<  0) | 
                (((kal_uint32) values[3] & 0xFF) << 24));
            break;
        }
    case WFC_CONTEXT_WORKING_BUFFER_MTK: 
        {
            kal_uint32 i = 0;
            kal_uint32 size;
            if (count < 3)
            {
                _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
                break;
            }

            size = (3*3) < count ? (3*3) : count;

            for (; (i*3)<size; i++)
            {
                pContext->cachedRWAttrib->workingBuffer[i].type = values[(i*3)+0];
                pContext->cachedRWAttrib->workingBuffer[i].startAddress = values[(i*3)+1];
                pContext->cachedRWAttrib->workingBuffer[i].size = values[(i*3)+2];
            }
            break;
        }
    case WFC_CONTEXT_CALLBACK_MTK: 
        {
            kal_uint32 i,j, firstEmpty;
            kal_bool found;
            WFC_ASSERT(count >= 4); // TODO: [o] Magical number...

            for (i = 0; i+4 <= count; i+=4) // For each callback set...
            {
                if (WFC_TRUE == (WFCboolean) values[i+3]) // add one callback function...
                {
                    firstEmpty = WFC_CONTEXT_GDI_CALLBACK_COUNT;
                    found = KAL_FALSE;
                    for (j = WFC_CONTEXT_GDI_CALLBACK_COUNT; j-- != 0; )
                    {
                        // Find an empty slot...
                        if (pContext->cachedRWAttrib->gdiCallbacks[j].cbfunc == NULL)
                        {
                            firstEmpty = j;
                        }

                        // Find if already inserted. If found, break
                        if ((pContext->cachedRWAttrib->gdiCallbacks[j].event == (WFCContextEventTypeMTK) values[i+0]) && 
                            (pContext->cachedRWAttrib->gdiCallbacks[j].cbfunc == (WFCCallbackFunctionPtrMTK) values[i+1]) && 
                            (pContext->cachedRWAttrib->gdiCallbacks[j].cbparam == (void*) values[i+2]))
                        {
                            found = KAL_TRUE;
                            break;
                        }
                    }
                    // There is an empty slot also the callback is never inserted before...
                    if ((firstEmpty != WFC_CONTEXT_GDI_CALLBACK_COUNT) && (KAL_FALSE == found))
                    {
                        pContext->cachedRWAttrib->gdiCallbacks[firstEmpty].event = (WFCContextEventTypeMTK) values[i];
                        pContext->cachedRWAttrib->gdiCallbacks[firstEmpty].cbfunc = (WFCCallbackFunctionPtrMTK) values[(i+1)];
                        pContext->cachedRWAttrib->gdiCallbacks[firstEmpty].cbparam = (void*) values[(i+2)];
                    }
                }
                else // remove one callback function...
                {
                    for (j = WFC_CONTEXT_GDI_CALLBACK_COUNT; j-- != 0; )
                    {
                        if ((pContext->cachedRWAttrib->gdiCallbacks[j].event == (WFCContextEventTypeMTK) values[i+0]) && 
                            (pContext->cachedRWAttrib->gdiCallbacks[j].cbfunc == (WFCCallbackFunctionPtrMTK) values[i+1]) && 
                            (pContext->cachedRWAttrib->gdiCallbacks[j].cbparam == (void*) values[i+2]))
                        {
                            pContext->cachedRWAttrib->gdiCallbacks[j].event = (WFCContextEventTypeMTK)0x0;
                            pContext->cachedRWAttrib->gdiCallbacks[j].cbfunc = NULL;
                            pContext->cachedRWAttrib->gdiCallbacks[j].cbparam = NULL;
                            break;
                        }
                    }
                }
            }

            break;
        }
    case WFC_CONTEXT_DESTINATION_RECTANGLE_MTK: 
        {
            WFC_ASSERT(count >= 4);
            pContext->cachedRWAttrib->destinationRect.x = (OWFint) values[0];
            pContext->cachedRWAttrib->destinationRect.y = (OWFint) values[1];
            pContext->cachedRWAttrib->destinationRect.width = (OWFint) values[2];
            pContext->cachedRWAttrib->destinationRect.height = (OWFint) values[3];
            break;
        }
    case WFC_CONTEXT_ROI_RECTANGLE_MTK: 
        {
            WFC_ASSERT(count >= 4);
            pContext->cachedRWAttrib->roiRect.x = (OWFint) values[0];
            pContext->cachedRWAttrib->roiRect.y = (OWFint) values[1];
            pContext->cachedRWAttrib->roiRect.width = (OWFint) values[2];
            pContext->cachedRWAttrib->roiRect.height = (OWFint) values[3];
            break;
        }
    case WFC_CONTEXT_CONCURRENT_MEMORY_OUT_RECT_MTK: 
        {
            WFC_ASSERT(count >= 4);
            pContext->cachedRWAttrib->concurrentMemOutRect.x = (OWFint) values[0];
            pContext->cachedRWAttrib->concurrentMemOutRect.y = (OWFint) values[1];
            pContext->cachedRWAttrib->concurrentMemOutRect.width = (OWFint) values[2];
            pContext->cachedRWAttrib->concurrentMemOutRect.height = (OWFint) values[3];
            break;
        }


        // KeTing: For autonomous mode, set sync source
        ///Bin: The following are illegal for GDI in Auto mode
    case WFC_CONTEXT_AUTONOMOUS_SYNC_TRIGGER_MTK:
    {
        //if(inAutoMode == WFC_TRUE)
        //{
        //    DDV2CatcherLogL3(TRACE_DDV2_ERROR, DDV2_TRC_ERROR_ILLEGAL_WFCSETCONTEXTATTRIBIV,
        //                                     drv_get_current_time(),
        //                                     (kal_uint32)kal_get_current_thread_ID(),
        //                                     ctx,
        //                                     attrib);
        //}
  
    
            //WFC_ASSERT(count >= 3);
            //pContext->cachedRWAttrib->autonomousSync.syncTrigger = (WFCAutonomousSyncTriggerMTK) values[0];
            //pContext->cachedRWAttrib->autonomousSync.period = (WFCuint) values[1];
            //pContext->cachedRWAttrib->autonomousSync.element = (WFCElement) values[2];
            
            //pContext->cachedRWAttrib->syncTrigger = (WFCAutonomousSyncTriggerMTK) values[0];
            //pContext->cachedRWAttrib->period = (WFCuint) values[1];
            //pContext->cachedRWAttrib->sync_element = (WFCElement) values[2];

            _wfc_set_error(WFC_ERROR_UNSUPPORTED);

            break;
        }
    case WFC_CONTEXT_ALL_ATTRIBUTES_MTK: 
	{
		WFCboolean te_enable = WFC_TRUE;
		///Yinli: GDI will not config enableVsync, so need to backup this attribute.
		te_enable = pContext->cachedRWAttrib->enableVsync;
		
		///bin: only memcpy the attributes gdi will set
		kal_mem_cpy((void*)pContext->cachedRWAttrib, (void*)values, ((kal_uint32)&(pContext->cachedRWAttrib->syncTrigger) - (kal_uint32)(pContext->cachedRWAttrib)));

		///Yinli: Rollback enableVsync
		pContext->cachedRWAttrib->enableVsync = te_enable;
	}

        break;
    default: 
        _wfc_set_error(WFC_ERROR_BAD_ATTRIBUTE);
        break;
    }

    return;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcGetContextAttribfv(WFCDevice dev,
                      WFCContext ctx,
                      WFCContextAttrib attrib,
                      WFCint count,
                      WFCfloat *values) WFC_APIEXIT
{
    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcSetContextAttribfv(WFCDevice dev,
                      WFCContext ctx,
                      WFCContextAttrib attrib,
                      WFCint count,
                      const WFCfloat *values) WFC_APIEXIT
{
    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
}

/*=========================================================================*/
/* 6. IMAGE PROVIDERS (SOURCES & MASKS)                                    */
/*=========================================================================*/
/**
 *  \status OK
 */
WFC_API_CALL WFCSource WFC_APIENTRY
wfcCreateSourceFromStream(WFCDevice dev,
                          WFCContext ctx,
                          WFCNativeStreamType stream,
                          const WFCint *attribList)
{
    WFCContextConfig* pContext = NULL;
    OWFNativeStreamType nativeStream;
    WFCint i;

    WFC_Source_Lock();
    GET_CONTEXT(pContext, ctx, WFC_INVALID_HANDLE);

    nativeStream = (OWFNativeStreamType) stream;
    if (OWF_INVALID_HANDLE == nativeStream)
    {
        _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        WFC_Source_Unlock();
        return WFC_INVALID_HANDLE;
    }

    // find if any empty slot to put this new source
    for (i = WFC_CONTEXT_MAX_INSERTED_ELEMENT; i-- != 0; )
    {
        if (WFC_FALSE == _wfc_sources[i]._isCreated)
        {
            // 2011/01/16 Added by CT
            _wfc_sources[i].ctxt = ctx;
            _wfc_sources[i].useStream = WFC_TRUE;
            _wfc_sources[i].stream = nativeStream;
            _wfc_sources[i]._streamBuffer = OWF_INVALID_HANDLE;
            _wfc_sources[i]._needChangeBuffer = WFC_FALSE;
            _wfc_sources[i]._isChangingBuffer = WFC_FALSE;
            _wfc_sources[i]._isCreated = WFC_TRUE;

            // KeTing: This is a magic
            // KeTing: We will use this field to see if the stream source is ready to blt or not
            // KeTing: If the stream source is ready, it will be wrapped as an image source and thus this field will be set
            _wfc_sources[i].image.data = OWF_INVALID_HANDLE;
            // check stream parameters

            WFC_Source_Unlock();
            DDV2CatcherLogL3(TRACE_DDV2_RESOURCEALLOCATION, DDV2_TRC_WFCCREATESOURCEFROMSTREAM,
                                               drv_get_current_time(),
                                               (kal_uint32)kal_get_current_thread_ID(),
                                               ctx,
                                               &(_wfc_sources[i]));
            return (WFCSource) &(_wfc_sources[i]);
        }
    }

    _wfc_set_error(WFC_ERROR_OUT_OF_MEMORY);
    WFC_Source_Unlock();
    DDV2CatcherLogL3(TRACE_DDV2_RESOURCEALLOCATION, DDV2_TRC_ERROR_CREATESOURCEFAIL,
                                               drv_get_current_time(),
                                               (kal_uint32)kal_get_current_thread_ID(),
                                               WFC_CreateSourceFromStream);
    return WFC_INVALID_HANDLE;
}

// TODO: [m] GDI requested that the struct of the image should be stored by WFC rather than GDI...
/**
 *  \status OK
 */
WFC_API_CALL WFCSource WFC_APIENTRY
wfcCreateSourceFromImage(WFCDevice dev, 
                         WFCContext ctx,
                         WFCHandle image,
                         const WFCint *attribList)
{
    WFCContextConfig* pContext = NULL;
    OWF_IMAGE* pImage = NULL;
    WFCint i;

    wfcTrace3(WFCDBG____CREATE_IMG____________SRC, (WFCint)image, 0, 0);
    WFC_Source_Lock();
    GET_CONTEXT(pContext, ctx, WFC_INVALID_HANDLE);

    pImage = (OWF_IMAGE*) image;
    if (NULL == pImage)
    {
        _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        WFC_Source_Unlock();
        return WFC_INVALID_HANDLE;
    }

    // find if any empty slot to put this new source
    for (i = WFC_MAX_SOURCE_NUMBER; i-- != 0; )
    {
        if (WFC_FALSE == _wfc_sources[i]._isCreated)
        {
            _wfc_sources[i].ctxt = ctx;
            _wfc_sources[i].useStream = WFC_FALSE;
            kal_mem_cpy((void*) &(_wfc_sources[i].image), 
                (void*) pImage, sizeof(OWF_IMAGE));
            _wfc_sources[i]._isCreated = WFC_TRUE;
            // check stream parameters

            WFC_Source_Unlock();
            DDV2CatcherLogL3(TRACE_DDV2_RESOURCEALLOCATION, DDV2_TRC_WFCCREATESOURCEFROMIMAGE,
                                               drv_get_current_time(),
                                               (kal_uint32)kal_get_current_thread_ID(),
                                               ctx,
                                               image,
                                               &(_wfc_sources[i]));
            return (WFCSource) &(_wfc_sources[i]);
        }
    }

    _wfc_set_error(WFC_ERROR_OUT_OF_MEMORY);
    WFC_Source_Unlock();
    wfcTrace(WFCDBG____CREATE_IMG________SRC_END);
    DDV2CatcherLogL3(TRACE_DDV2_RESOURCEALLOCATION, DDV2_TRC_ERROR_CREATESOURCEFAIL,
                                               drv_get_current_time(),
                                               (kal_uint32)kal_get_current_thread_ID(),
                                               WFC_CreateSourceFromImage);
    return WFC_INVALID_HANDLE;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcDestroySource(WFCDevice dev,
                 WFCSource src)
{
    WFCSourceConfig* pSource;
    WFCElementConfig* pElement;

    DDV2CatcherLogL3(TRACE_DDV2_RESOURCEALLOCATION, DDV2_TRC_WFCDESTROYSOURCE,
                                     drv_get_current_time(),
                                     (kal_uint32)kal_get_current_thread_ID(),
                                     src);
    wfcTrace3(WFCDBG____DESTROY_______________SRC, (WFCuint)src, 0, 0);
    WFC_Source_Lock();
    pSource = (WFCSourceConfig*) src;
    if (NULL == pSource)
    {
        WFC_Source_Unlock();
        return;
    }

    pElement = (WFCElementConfig*) pSource->element;
    // unbind the connection between source and element
    if ((WFC_INVALID_HANDLE != pElement) && ((WFCSource)pSource == pElement->capturedRWAttrib->source))
        pElement->capturedRWAttrib->source = WFC_INVALID_HANDLE;
    kal_mem_set((void*) (pSource), 0x0, sizeof(WFCSourceConfig));

    WFC_Source_Unlock();
    return;

}

WFC_API_CALL WFCSource WFC_APIENTRY
wfcDestroyAndCreateSourceFromImage(WFCDevice dev,
					WFCContext ctx,
					WFCSource oldSrc,
					WFCHandle image,
					const WFCint *attribList)
{
	WFCSourceConfig* pOldSource;
	WFCElementConfig* pElement;
	WFCContextConfig* pContext;
	OWF_IMAGE* pImage;
	
    wfcTrace3(WFCDBG____CREATE_IMG____________SRC, (WFCint)image, 0, 0);
	// check attribute
	GET_CONTEXT(pContext, ctx, WFC_INVALID_HANDLE);

	if(NULL == oldSrc)
	{
		return wfcCreateSourceFromImage(dev, ctx, image, attribList);
	}
	
	pOldSource = (WFCSourceConfig*)oldSrc;
	pImage = (OWF_IMAGE*)image;
	pElement = (WFCElementConfig*)pOldSource->element;
	
	if(	NULL == pImage || WFC_FALSE == pOldSource->_isCreated)
	{
		_wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
		
		return WFC_INVALID_HANDLE;
	}

    if ((WFC_INVALID_HANDLE != pElement) && ((WFCSource)pOldSource == pElement->capturedRWAttrib->source))
		//unbind the connection between old source and element
		pElement->capturedRWAttrib->source = WFC_INVALID_HANDLE;
	//create new source
	pOldSource->ctxt = ctx;
	pOldSource->useStream = WFC_FALSE;
	pOldSource->element = WFC_INVALID_HANDLE;
	kal_mem_cpy((void*)&(pOldSource->image),(void*) pImage, sizeof(OWF_IMAGE));
	wfcTrace(WFCDBG____CREATE_IMG________SRC_END);
	
	return (WFCSource)pOldSource;

}
/**
 *  \status OK
 */
WFC_API_CALL WFCMask WFC_APIENTRY
wfcCreateMaskFromStream(WFCDevice dev,
                        WFCContext ctx,
                        WFCNativeStreamType stream,
                        const WFCint *attribList) WFC_APIEXIT
{
    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
    return WFC_INVALID_HANDLE;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcDestroyMask(WFCDevice dev,
               WFCMask mask) WFC_APIEXIT
{
    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
    return;
}

/*=========================================================================*/
/* 7. COMPOSITION ELEMENTS                                                 */
/*=========================================================================*/
/**
 *  \status OK
 */
WFC_API_CALL WFCElement WFC_APIENTRY
wfcCreateElement(WFCDevice dev,
                 WFCContext ctx,
                 const WFCint* attribList) WFC_APIEXIT
{
    WFCContextConfig* pContext = NULL;
    WFCElementConfig* pElement = NULL;
    
    wfcTrace(WFCDBG____CREATE____________ELEMENT);

    GET_CONTEXT(pContext, ctx, WFC_INVALID_HANDLE);

    // Find an empty slot in _wfc_elements[]
    {
        WFCint i = WFC_ELEMENT_MAX_COUNT - 1;
        for (; i >= 0; i--)
        {
            if (WFC_INVALID_HANDLE == _wfc_elements[i]._context)
            {
                pElement = (WFCElementConfig*)(&(_wfc_elements[i]));

                // Initialize it
                {
                    pElement->_context = (WFCContext) pContext;
                    pElement->cachedRWAttrib = &(pElement->__RWAttrib[0]);
                    pElement->capturedRWAttrib = &(pElement->__RWAttrib[1]);
                    pElement->cachedRWAttrib->isDCLayer = WFC_FALSE;
                    //pElement->_pipeline = WFC_INVALID_HANDLE;
                }
                break;		  
            }
        }
    }

    if (NULL == pElement)
    {
        _wfc_set_error(WFC_ERROR_OUT_OF_MEMORY);
    }

    DDV2CatcherLogL3(TRACE_DDV2_RESOURCEALLOCATION, DDV2_TRC_WFCCREATEELEMENT,
                                        drv_get_current_time(),
                                        (kal_uint32)kal_get_current_thread_ID(),
                                        ctx,
                                        pElement);
    return (WFCElement) pElement;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcDestroyElement(WFCDevice dev,
                  WFCElement element) WFC_APIEXIT
{
    WFCElementConfig* pElement = NULL;
    WFCSourceConfig* pSource = NULL;
    WFCContextConfig* pContext = NULL;

    wfcTrace3(WFCDBG____DESTROY___________ELEMENT, (WFCuint)element, 0, 0);
    GET_ELEMENT_NR(pElement, element);

    // If the source is a stream, de-register the observer...
    pSource = (WFCSourceConfig*) pElement->capturedRWAttrib->source;
    if ((NULL != pSource) && pSource->useStream && pSource->stream)
    {
        owfNativeStreamRemoveObserver((OWFNativeStreamType) pSource->stream, 
                                  _wfc_stream_event_hdlr, 
                                  (void*) pElement);
    }

    // Destroy pipelines and sources...
    {
        pContext = (WFCContextConfig*) pElement->_context;
        WFC_ASSERT(NULL != pContext);

        if (WFC_INVALID_HANDLE != pElement->capturedRWAttrib->source)
        {
            WFCuint i;
            // destory wfcSourceHandle    

            for (i = 0; i < WFC_MAX_SOURCE_NUMBER; i++)
            {
                if (((WFCSource) (&_wfc_sources[i])) == pElement->capturedRWAttrib->source)
                {
                    // clear source
                    //pContext->_sources[i].source.image = WFC_INVALID_HANDLE;
                    WFCSourceConfig* pSource = (WFCSourceConfig*)(&_wfc_sources[i]);

                    kal_mem_set((void*) (&pSource->image), 0x0, sizeof(OWF_IMAGE));				  
                    kal_mem_set((void*) &(_wfc_sources[i]), 0x0, sizeof(WFCSourceConfig));
                    pElement->capturedRWAttrib->source = WFC_INVALID_HANDLE;				  
                    break;
                }
            }
        }

        //Remove elements from _insertedElements...
        {
            kal_uint32 i = 4;
            for (; i-- > 0; )
            {
                if (pContext->cachedRWAttrib->_insertedElements[i] == element)
                {
                    pContext->cachedRWAttrib->_insertedElements[i] = WFC_INVALID_HANDLE;

                    // Move valid entry up...
                    for (; i++ != (4-1); )
                    {
                        pContext->cachedRWAttrib->_insertedElements[i] ^= pContext->cachedRWAttrib->_insertedElements[i-1];
                        pContext->cachedRWAttrib->_insertedElements[i-1] ^= pContext->cachedRWAttrib->_insertedElements[i];
                        pContext->cachedRWAttrib->_insertedElements[i] ^= pContext->cachedRWAttrib->_insertedElements[i-1];
                    }
                    break;
                }
            }
        }
    }

    // deinitialize self.
    kal_mem_set((void*) pElement, 0x0, sizeof(WFCElementConfig));

    DDV2CatcherLogL3(TRACE_DDV2_RESOURCEALLOCATION, DDV2_TRC_WFCDESTROYELEMENT,
                                        drv_get_current_time(),
                                        (kal_uint32)kal_get_current_thread_ID(),
                                        element);
    return;
}

/**
 *  \status OK
 */
WFC_API_CALL WFCint WFC_APIENTRY
wfcGetElementAttribi(WFCDevice dev,
                     WFCElement element,
                     WFCElementAttrib attrib) WFC_APIEXIT
{
    WFCElementConfig* pElement = NULL;
    WFCint ret = 0;
    GET_ELEMENT(pElement, element, ret);

    switch (attrib)
    {
        case WFC_ELEMENT_SOURCE: 
            ret = (WFCint) pElement->cachedRWAttrib->source;
            break;
        case WFC_ELEMENT_SOURCE_FLIP: 
            ret = (WFCint) pElement->cachedRWAttrib->flip;
            break;
        case WFC_ELEMENT_SOURCE_ROTATION: 
            ret = (WFCint) pElement->cachedRWAttrib->rotationAngle;
            break;
        case WFC_ELEMENT_TRANSPARENCY_TYPES: 
            ret = (WFCint) pElement->cachedRWAttrib->transparencyType;
            break;
        case WFC_ELEMENT_GLOBAL_ALPHA: 
            ret = (WFCint) pElement->cachedRWAttrib->globalAlpha;
            break;
        case WFC_ELEMENT_SOURCE_COLOR_KEY_MTK: 
            ret = (WFCint) pElement->cachedRWAttrib->sourceColorKey;
            break;
        case WFC_ELEMENT_DITHERING_MTK: 
            ret = (WFCint) pElement->cachedRWAttrib->enableSpatialDithering;
            break;
        case WFC_ELEMENT_VIDEO_LAYER_MTK: 
            ret = (WFCint) pElement->cachedRWAttrib->isVideoLayer;
            break;
	#ifdef DRV_LCD_3D_MODE_SUPPORT
        case WFC_ELEMENT_3D_LAYER_MTK: 
            ret = (WFCint) pElement->cachedRWAttrib->is3DLayer;
            break;	
        case WFC_ELEMENT_3D_VIEW_MODE_MTK: 
            ret = (WFCint) pElement->cachedRWAttrib->_3DimageViewMode;
            break;	
	    case WFC_ELEMENT_3D_FIRST_EYE_MODE_MTK: 
            ret = (WFCint) pElement->cachedRWAttrib->_3DimageFirstEyeMode;
            break;	
        case WFC_ELEMENT_3D_START_ADDR_MODE_MTK: 
            ret = (WFCint) pElement->cachedRWAttrib->_3DimageStartAddrMode;
            break;	
	#endif
        default: 
            _wfc_set_error(WFC_ERROR_BAD_ATTRIBUTE);
            break;
    }

    return ret;
}

/**
 *  \status OK
 */
WFC_API_CALL WFCfloat WFC_APIENTRY
wfcGetElementAttribf(WFCDevice dev,
                     WFCElement element,
                     WFCElementAttrib attrib) WFC_APIEXIT
{
    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
    return 0x0;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcGetElementAttribiv(WFCDevice dev,
                      WFCElement element,
                      WFCElementAttrib attrib,
                      WFCint count,
                      WFCint *values) WFC_APIEXIT
{
    WFCElementConfig* pElement = NULL;

    GET_ELEMENT_NR(pElement, element);

    if ((0 >= count) || (NULL == values))
    {
        _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        return;
    }

    switch (attrib)
    {
    case WFC_ELEMENT_DESTINATION_RECTANGLE: /* WFCint[4]    (offsetX, offsetY, width, height) */
        WFC_ASSERT(4 <= count);
        if (4 > count)
        {
            _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT); 
            break;
        }
        values[0] = (WFCint) pElement->cachedRWAttrib->destinationRect.x;
        values[1] = (WFCint) pElement->cachedRWAttrib->destinationRect.y;
        values[2] = (WFCint) pElement->cachedRWAttrib->destinationRect.width;
        values[3] = (WFCint) pElement->cachedRWAttrib->destinationRect.height;
        break;
    case WFC_ELEMENT_SOURCE_RECTANGLE: /* WFCint[4]    (offsetX, offsetY, width, height) */
        WFC_ASSERT(4 <= count);
        if (4 > count)
        {
            _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
            break;
        }
        values[0] = (WFCint) pElement->cachedRWAttrib->sourceRect.x;
        values[1] = (WFCint) pElement->cachedRWAttrib->sourceRect.y;
        values[2] = (WFCint) pElement->cachedRWAttrib->sourceRect.width;
        values[3] = (WFCint) pElement->cachedRWAttrib->sourceRect.height;
        break;
    case WFC_ELEMENT_ALL_ATTRIBUTES_MTK:
        kal_mem_cpy((void *)values, (void *)pElement->cachedRWAttrib, sizeof(WFCElementRWAttrib));
        break;
    default:
        _wfc_set_error(WFC_ERROR_BAD_ATTRIBUTE); 
        break;
    }

    return;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcGetElementAttribfv(WFCDevice dev,
                      WFCElement element,
                      WFCElementAttrib attrib,
                      WFCint count,
                      WFCfloat *values) WFC_APIEXIT
{
    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
    return;
}


/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcSetElementAttribi(WFCDevice dev,
                     WFCElement element,
                     WFCElementAttrib attrib,
                     WFCint value) WFC_APIEXIT
{
    WFCElementConfig* pElement = NULL;
    WFCContextConfig* pContext = NULL;
    WFCboolean inAutoMode = WFC_FALSE;
    WFCboolean is_AutoMode_VideoElement = WFC_FALSE;
    WFCboolean is_illegal_element_attribi = WFC_FALSE;

    DDV2CatcherLogL3(TRACE_DDV2_ELEMENTATTRIB, DDV2_TRC_WFCSETELEMENTATTRIBI,
                                     drv_get_current_time(),
                                     (kal_uint32)kal_get_current_thread_ID(),
                                     element,
                                     attrib,
                                     value);
    GET_ELEMENT_NR(pElement, element);
    GET_CONTEXT_NR(pContext, pElement->_context);
    inAutoMode = _wfc_is_context_in_autonomous_mode(pElement->_context);

    if(inAutoMode == WFC_TRUE && pElement->cachedRWAttrib->isVideoLayer == WFC_TRUE)
    {
        is_AutoMode_VideoElement = WFC_TRUE;
    }

    switch (attrib)
    {
        case WFC_ELEMENT_TRANSPARENCY_TYPES: 
          pElement->cachedRWAttrib->transparencyType = (WFCbitfield) value;
          break;
        case WFC_ELEMENT_GLOBAL_ALPHA: 
          pElement->cachedRWAttrib->globalAlpha = (WFCint) value;
          break;
        case WFC_ELEMENT_SOURCE_COLOR_KEY_MTK: 
          pElement->cachedRWAttrib->sourceColorKey = (WFCuint) value;
          break;
        case WFC_ELEMENT_DITHERING_MTK: 
          pElement->cachedRWAttrib->enableSpatialDithering = (WFCboolean) value;
          break;
        case WFC_ELEMENT_VIDEO_LAYER_MTK: 
		{
          pElement->cachedRWAttrib->isVideoLayer = (WFCboolean) value;
			  //Yinli:   if GDI modify video-layer flag in auto-mode, will print a log.
			  if(is_AutoMode_VideoElement == WFC_TRUE
			  	&& _wfc_check_element_inserted(pContext, element) == WFC_TRUE
			  	&& (WFCboolean)value == WFC_FALSE)
			  {
				DDV2CatcherLogL3(TRACE_DDV2_ELEMENTATTRIB, DDV2_TRC_WFCSETELEMENTVIDEOFLAGINAUTOMODE,
												 drv_get_current_time(),
												 (kal_uint32)kal_get_current_thread_ID(),
												 element,
												 attrib,
												 (WFCboolean)value);
			  }
          break;
        }

        ///Bin: The following are illegal for GDI in Auto mode
        case WFC_ELEMENT_SOURCE: 
        {
            if (WFC_FALSE == is_AutoMode_VideoElement)
            {
                WFCSourceConfig* pSource = (WFCSourceConfig*) value;
                WFCSourceConfig* pOriSource;
                pOriSource = (WFCSourceConfig*)(pElement->cachedRWAttrib->source);
                if (pOriSource)
                    pOriSource->element = WFC_INVALID_HANDLE;
                pElement->cachedRWAttrib->source = (WFCSource) value;
                // If the input source handle is NULL, it means user wants to remove the connection between the source and element.
                if (pSource)
                {
                    pSource->element = element;
                }                
            } //if (is_AutoMode_VideoElement == WFC_FALSE)
            else
            {
                is_illegal_element_attribi = WFC_TRUE;
            }

            break;
        }  
        case WFC_ELEMENT_SOURCE_FLIP: 
        {
            if (WFC_FALSE == is_AutoMode_VideoElement)
            {
                pElement->cachedRWAttrib->flip = (WFCboolean) value;
            } //if (is_AutoMode_VideoElement == WFC_FALSE)
            else
            {
                is_illegal_element_attribi = WFC_TRUE;
            }
       
            break;
        }  
        case WFC_ELEMENT_SOURCE_ROTATION: 
        {
            if (WFC_FALSE == is_AutoMode_VideoElement)
            {
                pElement->cachedRWAttrib->rotationAngle = (WFCRotation) value;
            } //if (is_AutoMode_VideoElement == WFC_FALSE)
            else
            {
                is_illegal_element_attribi = WFC_TRUE;
            }

            break;
        }  

        case WFC_ELEMENT_DC_LAYER_MTK: 
        {
            if (WFC_FALSE == is_AutoMode_VideoElement)
            {
                pElement->cachedRWAttrib->isDCLayer = (WFCboolean) value;
            } //if (is_AutoMode_VideoElement == WFC_FALSE)
            else
            {
                is_illegal_element_attribi = WFC_TRUE;
            }

            break;
        }  
	#ifdef DRV_LCD_3D_MODE_SUPPORT
		case WFC_ELEMENT_3D_LAYER_MTK: 
          pElement->cachedRWAttrib->is3DLayer = (WFCboolean) value;
          break;
		case WFC_ELEMENT_3D_VIEW_MODE_MTK: 
          pElement->cachedRWAttrib->_3DimageViewMode = (WFC3DViewMode) value;
          break;
		case WFC_ELEMENT_3D_FIRST_EYE_MODE_MTK: 
          pElement->cachedRWAttrib->_3DimageFirstEyeMode = (WFC3DFirstEyeMode) value;
          break;
		case WFC_ELEMENT_3D_START_ADDR_MODE_MTK: 
          pElement->cachedRWAttrib->_3DimageStartAddrMode = (WFC3DStartAddrMode) value;
          break;		  
	#endif
        default: 
            _wfc_set_error(WFC_ERROR_BAD_ATTRIBUTE);
            break;
    }

    if (is_illegal_element_attribi)
    {
        _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        DDV2CatcherLogL3(TRACE_DDV2_ERROR, DDV2_TRC_ERROR_ILLEGAL_WFCSETELEMENTATTRIBI,
                                         drv_get_current_time(),
                                         (kal_uint32)kal_get_current_thread_ID(),
                                         element,
                                         attrib,
                                         value);
    }

    return;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcSetElementAttribf(WFCDevice dev,
                     WFCElement element,
                     WFCElementAttrib attrib,
                     WFCfloat value) WFC_APIEXIT
{
    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
    return;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcSetElementAttribiv(WFCDevice dev,
                      WFCElement element,
                      WFCElementAttrib attrib,
                      WFCint count,
                      const WFCint *values) WFC_APIEXIT
{
    WFCElementConfig* pElement = NULL;
    WFCContextConfig* pContext = NULL;
    WFCboolean inAutoMode = WFC_FALSE;
    WFCboolean is_AutoMode_VideoElement = WFC_FALSE;
    WFCboolean is_illegal_element_attribiv = WFC_FALSE;

    if ((count >= 3) && (values != NULL))
        DDV2CatcherLogL3(TRACE_DDV2_ELEMENTATTRIB, DDV2_TRC_WFCSETELEMENTATTRIBIV,
                                            drv_get_current_time(),
                                            (kal_uint32)kal_get_current_thread_ID(),
                                            element,
                                            attrib,
                                            values[0], values[1], values[2], (count==4)?values[3]:0);
    GET_ELEMENT_NR(pElement, element);
    GET_CONTEXT_NR(pContext, pElement->_context);

    inAutoMode = _wfc_is_context_in_autonomous_mode(pElement->_context);

    if(inAutoMode == WFC_TRUE && pElement->cachedRWAttrib->isVideoLayer == WFC_TRUE)
    {
        is_AutoMode_VideoElement = WFC_TRUE;
    }

    if ((0 >= count) || (NULL == values))
    {
        _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        return;
    }

    switch (attrib)
    {
    case WFC_ELEMENT_DESTINATION_RECTANGLE: /* WFCint[4] ==> (offsetX, offsetY, width, height) */
        WFC_ASSERT(4 == count);
        if (4 != count)
        {
            _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT); 
            break;
        }
        pElement->cachedRWAttrib->destinationRect.x = (OWFint) values[0];
        pElement->cachedRWAttrib->destinationRect.y = (OWFint) values[1];
        pElement->cachedRWAttrib->destinationRect.width = (OWFint) values[2];
        pElement->cachedRWAttrib->destinationRect.height = (OWFint) values[3];
        break;

        
    ///Zifeng: The following are illegal for GDI in Auto mode
    case WFC_ELEMENT_SOURCE_RECTANGLE: /* WFCint[4] ==> (offsetX, offsetY, width, height) */
    {
        if (WFC_FALSE == is_AutoMode_VideoElement)
        {
            WFC_ASSERT(4 == count);
            if (4 != count)
            {
                is_illegal_element_attribiv = WFC_TRUE;
                break;
            }
            pElement->cachedRWAttrib->sourceRect.x = (OWFint) values[0];
            pElement->cachedRWAttrib->sourceRect.y = (OWFint) values[1];
            pElement->cachedRWAttrib->sourceRect.width = (OWFint) values[2];
            pElement->cachedRWAttrib->sourceRect.height = (OWFint) values[3];
        }
        else
        {
            is_illegal_element_attribiv = WFC_TRUE;
        }
        break;
    }
    case WFC_ELEMENT_ALL_ATTRIBUTES_MTK:
		{
			{
				//Yinli:   if GDI modify video-layer flag, will print a log.
				if(((WFCElementRWAttrib*)values)->isVideoLayer != pElement->cachedRWAttrib->isVideoLayer)
			  {
			    #if (DDV2_CATCHERLOG_LEVEL == 3)
			      DDV2CatcherLogL3(TRACE_DDV2_ELEMENTATTRIB, DDV2_TRC_WFCSETELEMENTATTRIBI_VIDEO_FLAG,
													 drv_get_current_time(),
													 (kal_uint32)kal_get_current_thread_ID(),
													 element,
													 attrib,
													 ((WFCElementRWAttrib*)values)->isVideoLayer);
				#elif (DDV2_CATCHERLOG_LEVEL == 2)
				  DDV2CatcherLogL2(TRACE_DDV2_ELEMENTATTRIB, DDV2_TRC_WFCSETELEMENTATTRIBI_VIDEO_FLAG,
													 drv_get_current_time(),
													 (kal_uint32)kal_get_current_thread_ID(),
													 element,
													 attrib,
													 ((WFCElementRWAttrib*)values)->isVideoLayer);
				#endif
			 }
			}
    	///Yinli: if in auto mode but this layer is not inserted, gdi request to consider it as non-video layer
    	///Yinli: so video layer must meet below points concurrently: [1] in auto-mode, [2]the flag of isVideolayer(cachedRWAttribi)  must be true, [3]the elemnt must be inserted in context
		if(is_AutoMode_VideoElement == WFC_TRUE && _wfc_check_element_inserted(pContext, element) == WFC_TRUE)	 
			{
			kal_mem_cpy((void *)pElement->cachedRWAttrib, (void *)values, ((kal_uint32)&(pElement->cachedRWAttrib->source) - (kal_uint32)(pElement->cachedRWAttrib)));
				//Yinli: if the video layer is used by MDP, but AP try to config it as a OSD layer when hw-update mode will assert
				 if(((WFCElementRWAttrib*)values)->isVideoLayer == WFC_FALSE)
					 ASSERT(0);
			}
     	else
        {
			/// clear old source element binding
			if (pElement->cachedRWAttrib->source)
				((WFCSourceConfig*)pElement->cachedRWAttrib->source)->element = WFC_INVALID_HANDLE;

			/// apply new setting except isDCLayer
            kal_mem_cpy((void *)pElement->cachedRWAttrib, (void *)values, ((kal_uint32)&(pElement->cachedRWAttrib->isDCLayer) - (kal_uint32)(pElement->cachedRWAttrib)));

			/// binding new source to this element
			if (pElement->cachedRWAttrib->source)
				((WFCSourceConfig*)pElement->cachedRWAttrib->source)->element = element;
		}
		break;
    	}	
    default:
        _wfc_set_error(WFC_ERROR_BAD_ATTRIBUTE); 
        break;
    }
  
    if (is_illegal_element_attribiv)
    {
        _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        DDV2CatcherLogL3(TRACE_DDV2_ERROR, DDV2_TRC_ERROR_ILLEGAL_WFCSETELEMENTATTRIBIV,
                                         drv_get_current_time(),
                                         (kal_uint32)kal_get_current_thread_ID(),
                                         element,
                                         attrib);
    }

    return;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcSetElementAttribfv(WFCDevice dev,
                      WFCElement element,
                      WFCElementAttrib attrib,
                      WFCint count,
                      const WFCfloat *values) WFC_APIEXIT
{
    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
    return;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcInsertElement(WFCDevice dev,
                 WFCElement element,
                 WFCElement subordinate) WFC_APIEXIT
{
    WFCContextConfig* pContext = NULL;
    WFCElementConfig* pElementUpper = NULL;
    WFCElementConfig* pElementLower = NULL;
	#if (!(defined (MT6250) || defined (MT6260) || defined (MT6261) || defined (MT2501) || defined (MT2502))) 
    WFCint ElementOrder = -1;
    WFCint SubordinateOrder = -1;
    WFCboolean bElementVideo = WFC_FALSE;
    WFCboolean bSubordinateVideo = WFC_FALSE;
	#endif

    wfcTrace3(WFCDBG____INSERT____________ELEMENT, (WFCuint)element, (WFCuint)subordinate, 0);
    GET_ELEMENT_NR(pElementUpper, element);


    if (WFC_INVALID_HANDLE != subordinate)
    {
        GET_ELEMENT_NR(pElementLower, subordinate);
        WFC_ASSERT(pElementUpper->_context == pElementLower->_context);
    }
    else
    {
        pElementLower = NULL;
    }

    pContext = (WFCContextConfig*) pElementUpper->_context;

    {
        kal_uint32 i = WFC_CONTEXT_MAX_INSERTED_ELEMENT;
        for (; i-- > 0; )
        {
            if (pContext->cachedRWAttrib->_insertedElements[i] == element)
            {
            	#if (!(defined (MT6250) || defined (MT6260) || defined (MT6261) || defined (MT2501) || defined (MT2502))) 
                ElementOrder = i;
                bElementVideo = ((WFCElementConfig*)(pContext->cachedRWAttrib->_insertedElements[i]))->cachedRWAttrib->isVideoLayer;
                pContext->cachedRWAttrib->_insertedElements[i] = WFC_INVALID_HANDLE;
				#endif
                // Move valid entry down...
                for (; i++ != (WFC_CONTEXT_MAX_INSERTED_ELEMENT-1); )
                {
                    pContext->cachedRWAttrib->_insertedElements[i] ^= pContext->cachedRWAttrib->_insertedElements[i-1];
                    pContext->cachedRWAttrib->_insertedElements[i-1] ^= pContext->cachedRWAttrib->_insertedElements[i];
                    pContext->cachedRWAttrib->_insertedElements[i] ^= pContext->cachedRWAttrib->_insertedElements[i-1];
                }
                break;
            }
        }
    }


    // Insert at the top first then move downward if subordinate is not found...
    {
        WFCint i;
        if (WFC_INVALID_HANDLE != pContext->cachedRWAttrib->_insertedElements[WFC_CONTEXT_MAX_INSERTED_ELEMENT-1])
        {
            _wfc_set_error(WFC_ERROR_OUT_OF_MEMORY);
            return;
        }

        pContext->cachedRWAttrib->_insertedElements[WFC_CONTEXT_MAX_INSERTED_ELEMENT-1] = (WFCElement)pElementUpper;

        for (i = WFC_CONTEXT_MAX_INSERTED_ELEMENT - 1; i > 0; i--)
        {
            if ((pContext->cachedRWAttrib->_insertedElements[(i-1)] == subordinate) &&  
                (pContext->cachedRWAttrib->_insertedElements[(i-1)] != WFC_INVALID_HANDLE))
            {
            	#if (!(defined (MT6250) || defined (MT6260) || defined (MT6261) || defined (MT2501) || defined (MT2502))) 
                SubordinateOrder = i-1;
                bSubordinateVideo = ((WFCElementConfig*)(pContext->cachedRWAttrib->_insertedElements[(i-1)]))->cachedRWAttrib->isVideoLayer;
				#endif
                break;
            }
            else
            {
                // swap
                pContext->cachedRWAttrib->_insertedElements[(i-1)] ^= pContext->cachedRWAttrib->_insertedElements[i];
                pContext->cachedRWAttrib->_insertedElements[i] ^= pContext->cachedRWAttrib->_insertedElements[(i-1)];
                pContext->cachedRWAttrib->_insertedElements[(i-1)] ^= pContext->cachedRWAttrib->_insertedElements[i];
            }
        }
    }
	#if (!(defined (MT6250) || defined (MT6260) || defined (MT6261) || defined (MT2501) || defined (MT2502))) 
    DDV2CatcherLogL3(TRACE_DDV2_ELEMENTINSERTION, DDV2_TRC_WFCINSERTELEMENT,
                                        drv_get_current_time(),
                                        (kal_uint32)kal_get_current_thread_ID(),
                                        pContext,
                                        element,
                                        subordinate,
                                        ElementOrder,
                                        SubordinateOrder,
                                        bElementVideo,
                                        bSubordinateVideo);
	#endif
    return;
}

/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcRemoveElement(WFCDevice dev,
                 WFCElement element) WFC_APIEXIT
{
    WFCContextConfig* pContext = NULL;
    WFCElementConfig* pElement = NULL;
	#if (!(defined (MT6250) || defined (MT6260) || defined (MT6261) || defined (MT2501) || defined (MT2502))) 
    WFCint ElementOrder = -1;
    WFCboolean bElementVideo = WFC_FALSE;
	#endif
    wfcTrace3(WFCDBG____REMOVE____________ELEMENT, (WFCuint)element, 0, 0);

    GET_ELEMENT_NR(pElement, element);

    pContext = (WFCContextConfig*) pElement->_context;

    {
        kal_uint32 i = WFC_CONTEXT_MAX_INSERTED_ELEMENT;
        for (; i-- > 0; )
        {
            if (pContext->cachedRWAttrib->_insertedElements[i] == element)
            {
            	#if (!(defined (MT6250) || defined (MT6260) || defined (MT6261) || defined (MT2501) || defined (MT2502))) 
                ElementOrder = i;
                bElementVideo = ((WFCElementConfig*)(pContext->cachedRWAttrib->_insertedElements[i]))->cachedRWAttrib->isVideoLayer;
				#endif
                pContext->cachedRWAttrib->_insertedElements[i] = WFC_INVALID_HANDLE;

                // Move valid entry down...
                for (; i++ != (WFC_CONTEXT_MAX_INSERTED_ELEMENT - 1); )
                {
                    pContext->cachedRWAttrib->_insertedElements[i] ^= pContext->cachedRWAttrib->_insertedElements[i-1];
                    pContext->cachedRWAttrib->_insertedElements[i-1] ^= pContext->cachedRWAttrib->_insertedElements[i];
                    pContext->cachedRWAttrib->_insertedElements[i] ^= pContext->cachedRWAttrib->_insertedElements[i-1];
                }
                break;
            }
        }
    }
	#if (!(defined (MT6250) || defined (MT6260) || defined (MT6261) || defined (MT2501) || defined (MT2502))) 
    DDV2CatcherLogL3(TRACE_DDV2_ELEMENTINSERTION, DDV2_TRC_WFCREMOVEELEMENT,
                                        drv_get_current_time(),
                                        (kal_uint32)kal_get_current_thread_ID(),
                                        pContext,
                                        element,
                                        ElementOrder,
                                        bElementVideo);
	#endif
    return;
  
}

/**
 *  \status OK
 * to let user know which element is inserted above the element
 */
WFC_API_CALL WFCElement WFC_APIENTRY
wfcGetElementAbove(WFCDevice dev, WFCElement element) WFC_APIEXIT
{
    WFCContextConfig* pContext = NULL;
    WFCElementConfig* pElement = NULL;
    WFCElement ret = WFC_INVALID_HANDLE;

    GET_ELEMENT(pElement, element, ret);
    GET_CONTEXT(pContext, pElement->_context, ret);

    {
        kal_uint32 i = WFC_CONTEXT_MAX_INSERTED_ELEMENT;
        for (; i-- != 0; )
        {
            if ((pContext->cachedRWAttrib->_insertedElements[i] == element) && 
                ((WFC_CONTEXT_MAX_INSERTED_ELEMENT-1) > i))
            {
                ret = (WFCElement) pContext->cachedRWAttrib->_insertedElements[(i+1)];
                break;
            }
        }
    }

    return ret;
}

/**
 *  \status OK
 * to let user know which element is inserted under the element
 */
WFC_API_CALL WFCElement WFC_APIENTRY
wfcGetElementBelow(WFCDevice dev, WFCElement element) WFC_APIEXIT
{
    WFCContextConfig* pContext = NULL;
    WFCElementConfig* pElement = NULL;
    WFCElement ret = WFC_INVALID_HANDLE;

    GET_ELEMENT(pElement, element, ret);
    GET_CONTEXT(pContext, pElement->_context, ret);

    {
        kal_uint32 i = WFC_CONTEXT_MAX_INSERTED_ELEMENT;
        for (; i-- > 0; )
        {
            if ((pContext->cachedRWAttrib->_insertedElements[i] == element) && 
                (0 != i))
            {
                ret = (WFCElement) pContext->cachedRWAttrib->_insertedElements[(i-1)];
                break;
            }
        }
    }

    return ret;
}


/**
 *  \status OK
 *  This funtion is used to clone one element include its all setting and binded-source setting
 */
WFC_API_CALL void WFC_APIENTRY
wfcCloneElementAttribute(WFCDevice dev, WFCElement SourceElement, WFCElement DestElement) WFC_APIEXIT
{
    WFCElementConfig* pSrcElement = NULL;
    WFCElementConfig* pDstElement = NULL;
    WFCSourceConfig*  pSrcSource = NULL;
    WFCSourceConfig*  pDstSource = NULL;
    DDV2CatcherLogL3(TRACE_DDV2_RENDERING, DDV2_TRC_WFCCLONEELEMENT,
                                     drv_get_current_time(),
                                     (kal_uint32)kal_get_current_thread_ID(),
                                     SourceElement,
                                     DestElement);

    pSrcElement = (WFCElementConfig*)SourceElement;
    pDstElement = (WFCElementConfig*)DestElement;
    if (pSrcElement == NULL || pDstElement == NULL)
    {
        _wfc_set_error(WFC_ERROR_BAD_HANDLE);
        return;
    }
    pSrcSource = (WFCSourceConfig*) (pSrcElement->cachedRWAttrib->source);
    pDstSource = (WFCSourceConfig*) (pDstElement->cachedRWAttrib->source);
    memcpy(pDstElement->cachedRWAttrib, pSrcElement->cachedRWAttrib, sizeof(WFCElementRWAttrib));
    
    pDstElement->cachedRWAttrib->source = (WFCSource) pDstSource;
    if (pSrcSource == NULL || pDstSource == NULL)
    {
        return;
    }
    memcpy(&(pDstSource->image), &(pSrcSource->image), sizeof(OWF_IMAGE));
}


/*=========================================================================*/
/* 8. RENDERING                                                            */
/*=========================================================================*/

// KeTing: The behaivor of this function is defined as follow
// KeTing: 1. If context is not in autonomous mode, enter autonomous mode
// KeTing: 2. If context is already in autonomous mode, refresh the sync trigger config
WFC_API_CALL void WFC_APIENTRY
wfcActivate(WFCDevice dev,
            WFCContext ctx) WFC_APIEXIT
{
    WFCContextConfig* pContext = NULL;
    WFCCtxtRWAttrib* pContextCatchedAttrib = NULL;
    WFCCtxtRWAttrib* pContextCapturedAttrib = NULL;

    DDV2CatcherLogL3(TRACE_DDV2_RENDERING, DDV2_TRC_WFCACTIVATE,
                                          drv_get_current_time(),
                                          (kal_uint32)kal_get_current_thread_ID(),
                                          ctx);
    wfcTrace(WFCDBG____AUTO_____________ACTIVATE);
    GET_CONTEXT_NR(pContext, ctx);

    pContextCatchedAttrib = pContext->cachedRWAttrib;
    pContextCapturedAttrib = pContext->capturedRWAttrib;
    
    // Bin: Auto mode is not valid for off screen context
    if (&_wfc_context_cfg_frame_buffer == pContext)
    {
        _wfc_set_error(WFC_ERROR_BAD_HANDLE);
        goto Exit;
    }

    if (WFC_AUTONOMOUS_STATE_TURNING_OFF == pContext->_autonomousMode)
    {
        // Bin: this case should not happened in current implementation, therefore using ASSERT(0) to check here
        WFC_ASSERT(0);
        _wfc_set_error(WFC_ERROR_BUSY);
        goto Exit;
    }


    if (WFC_AUTONOMOUS_STATE_OFF == pContext->_autonomousMode)
    {
        //int i;

        // KeTing: Regist the device and context as autonomous mode
        if (WFC_FALSE == _wfc_regist_autonomous_mode(pContext))
        {
            _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
            goto Exit;
        }

        // KeTing: Make sure this context is get rid of previous blt
        // KeTing: Do not remove this or we may commit to wfd while it is busy
        _wfc_wait_until_wfd_not_busy(pContext);
        memset(&(pContext->_autoModeRoiRect), 0, sizeof(OWF_RECTANGLE));
    
        // KeTing: This is only for MT6253
        // KeTing: Once it is phased out, the following code segement can also be removed
        ((WFD_DEVICE*)(pContext->_engine))->config.enableFastRotatorMem = WFD_TRUE;
        wfdDeviceCommit(pContext->_engine, WFD_COMMIT_ENTIRE_DEVICE, pContext->_engine);
        
        {
            // When enter Hw_update, AP do not want to consider ROI
            // in Auto mode, the ROI rectangle will be updated in _wfc_wait_until_wfd_not_busy()
            // Here set to zero, is just for easy to merge in _wfc_wait_until_wfd_not_busy()
            pContextCatchedAttrib->roiRect.x = 0;
            pContextCatchedAttrib->roiRect.y = 0;
            pContextCatchedAttrib->destinationRect.x = 0;
            pContextCatchedAttrib->destinationRect.y = 0;
            pContextCatchedAttrib->roiRect.width = pContextCatchedAttrib->destinationRect.width = 0;
            pContextCatchedAttrib->roiRect.height = pContextCatchedAttrib->destinationRect.height = 0;

            kal_mem_cpy((void*) (&(pContextCapturedAttrib->roiRect)), 
                        (void*) (&(pContextCatchedAttrib->roiRect)), 
                        sizeof(OWF_RECTANGLE));
            kal_mem_cpy((void*) &(pContextCapturedAttrib->destinationRect), 
                        (void*) &(pContextCatchedAttrib->destinationRect), 
                        sizeof(OWF_RECTANGLE));
        }
    }

    pContext->_autonomousMode = WFC_AUTONOMOUS_STATE_ON;

Exit:
  
  return;
}



// KeTing: The behaivor of this function is defined as follow
// KeTing: 1. If context is in autonomous mode, leave the autonomous mode
// KeTing: 2. If context is not in autonomous mode, do nothing
WFC_API_CALL void WFC_APIENTRY
wfcDeactivate(WFCDevice dev,
              WFCContext ctx) WFC_APIEXIT
{
    WFCContextConfig* pContext = NULL;

    DDV2CatcherLogL3(TRACE_DDV2_RENDERING, DDV2_TRC_WFCDEACTIVATE,
                                          drv_get_current_time(),
                                          (kal_uint32)kal_get_current_thread_ID(),
                                          ctx);
    wfcTrace(WFCDBG____AUTO___________DEACTIVATE);
    GET_CONTEXT_NR(pContext, ctx);

    // KeTing: If off screen context
    if (&_wfc_context_cfg_frame_buffer == pContext)
    {
        _wfc_set_error(WFC_ERROR_BAD_HANDLE);
        goto Exit;
    }

    // KeTing: If not in autonomous mode...
    if (WFC_AUTONOMOUS_STATE_OFF == pContext->_autonomousMode || WFC_AUTONOMOUS_STATE_TURNING_OFF == pContext->_autonomousMode)
    {
        goto Exit;
    }

    _wfc_wait_until_wfd_not_busy(pContext);//Xiaoyong:wait the previous blt to finish, the GDI will not wait before call wfcDeactivate, for fast exit auto mode
	if (_timer_run_status == KAL_TRUE)
	{ 
		kal_cancel_timer(pContext->_timer);//Xiaoyong:cancel the auto mode timer for fast exit auto mode
		_timer_run_status = KAL_FALSE;
	}
    // KeTing: Make sure this context is get rid of auto mode completely
    // KeTing: Do not remove this or we may commit to wfd while it is busy
	if (_wfc_committed_flag == WFC_TRUE)  //Xiaoyong:If there is valid commit and blt request in audo mode, blt it before exit auto mode, because timer is cancelled
	{
		_wfc_autonomous_activate_hisr_in_deactivate(pContext);
    	kal_sleep_task(1);//make sure hisr will be excuted, !!!FIX ME, is this need???
	}
	_wfc_wait_until_wfd_not_busy(pContext);//Xiaoyong:To wait the last blt if has before exit auto mode	

    // KeTing: De-regist the device and context as autonomous mode
    if (WFC_FALSE == _wfc_deregist_autonomous_mode(pContext))
    {
        goto Exit;
    }

    /// Bin: turning off auto mode to make sure _wfc_autonomous_timer_handler() and _wfc_stream_event_hdlr() stop handle auto mode event
    pContext->_autonomousMode = WFC_AUTONOMOUS_STATE_TURNING_OFF;

    // KeTing: Make sure this context is get rid of auto mode completely
    // KeTing: Do not remove this or we may commit to wfd while it is busy
    _wfc_wait_until_wfd_not_busy(pContext);

    // KeTing: This is only for MT6253
    // KeTing: Once it is phased out, the following code segement can also be removed
    ((WFD_DEVICE*)(pContext->_engine))->config.enableFastRotatorMem = WFD_FALSE;
    wfdDeviceCommit(pContext->_engine, WFD_COMMIT_ENTIRE_DEVICE, pContext->_engine);
    
    /// Finally, exit the autp mode
    pContext->_autonomousMode = WFC_AUTONOMOUS_STATE_OFF;

Exit:
    return;
}


/**
 *  \status OK
 *  This funtion is used for GDI to do blt or flatten in non-auto mode
 *  Notice: this funtion will not commit cached setting, must use wfcCommit funtion to commit the cached setting
 */
WFC_API_CALL void WFC_APIENTRY
wfcCompose(WFCDevice dev,
           WFCContext ctx,
           WFCboolean wait) WFC_APIEXIT
{
    WFCContextConfig* pContext = NULL;
    WFDDevice pEngine = WFD_INVALID_HANDLE;
    #if defined(DDV2_PERFORMANCE_PROFILING_SUPPORT)
    kal_uint32 wfcComposeStartTimeTick = drv_get_current_time();
    #endif

    // KeTing: This is for GDI's request that always invoke callback function even blt fail...
    // KeTing: Set to TRUE by default, only set to FALSE if blt success
    WFCboolean composeFail = WFC_TRUE;

    wfcTrace(WFCDBG______________________COMPOSE);

    GET_CONTEXT_NR(pContext, ctx);

    pEngine = (WFDDevice) pContext->_engine;

    DDV2CatcherLogL3(TRACE_DDV2_RENDERING, DDV2_TRC_WFCCOMPOSE,
                                     drv_get_current_time(),
                                     (kal_uint32)kal_get_current_thread_ID(),
                                     ctx,
                                     pContext->capturedRWAttrib->roiRect.x,
                                     pContext->capturedRWAttrib->roiRect.y,
                                     pContext->capturedRWAttrib->roiRect.width,
                                     pContext->capturedRWAttrib->roiRect.height, wait);

    // KeTing: Not allow compose while in auto mode.
    if (WFC_TRUE == _wfc_is_engine_in_autonomous_mode(pEngine))
    {
        _wfc_set_error(WFC_ERROR_UNSUPPORTED);
        goto Exit;
    }

    // KeTing: If this is a blocking call, wait until context not busy
    if (WFC_TRUE == wait)
    {
        _wfc_wait_until_wfd_not_busy(pContext);
    }
    else
    {
        // KeTing: If this is not a blocking call and context is busy, set error and return
        if (WFC_TRUE == _wfc_is_wfd_busy(pContext))
        {
            _wfc_set_error(WFC_ERROR_BUSY);
            goto Exit;
        }
    }

    // Bin: clear the frame done event flag and set busy flag
    _wfc_set_context_frame_done_event(pContext, WFC_FALSE);
    pContext->_busy = WFC_TRUE;

#if defined(__MTK_TARGET__) && defined(MT6256)	
	// Xiaoyong: For MT6256 3D MMI 2 Layers BW adjust before trigger LCD Blt, see MAUI_03095322
	{
		WFCuint layer_count=0;
		WFCuint i=0;
		WFDPort pPort = WFD_INVALID_HANDLE;
		pPort = (WFDPort) pContext->_port;
		if (((WFD_PORT*)pPort)->config.type == WFD_PORT_TYPE_INTERNAL)// Only for Blt
		{
			for (i = 0; i<WFC_CONTEXT_MAX_INSERTED_ELEMENT; i++)
			{
				if (WFC_INVALID_HANDLE != pContext->capturedRWAttrib->_insertedElements[i])		 
            	{        		
                	if (i >= ((WFD_DEVICE*)pEngine)->pipelineCount)
                	{
                    	// Error!
                    	continue;
                	}
					if(layer_count++ > 1) 
						break;
				}
			}
			if (layer_count >= 2) //if layer count >1, will switch BW to 3D_2_LCD_Layer
			{
				 EMI_SetScenarioBW(MM_SCE_MMI_3D_2_LCD_LAYER);
			}
			else
			{
				 EMI_SetScenarioBW(MM_SCE_MMI_3D_1_LCD_LAYER);
			}
		}
	}
#endif	
    // KeTing: Configure WFD accordingly and then blt 
    //             If blocking-call, it will not return until the current frame is blt done .
    _wfc_config_wfd_and_commit(pContext, wait);


    if (WFD_ERROR_NONE != wfdGetError(pEngine))
    {
        _wfc_set_error(WFC_ERROR_ILLEGAL_ARGUMENT);
        goto Exit;
    }
    else
    {
        composeFail = WFC_FALSE;
    }

Exit:

    #if defined(DDV2_PERFORMANCE_PROFILING_SUPPORT)
    {
        DDV2CatcherLogL3D1(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_WFC_COMPOSE_TOTAL_TIME,
                                                 drv_get_duration_tick(wfcComposeStartTimeTick, drv_get_current_time()));
    }
    #endif

    if (WFC_TRUE == composeFail)
    {
        _wfc_invoke_callback(pContext, WFC_CONTEXT_EVENT_COMPOSITION_FINISH_MTK);
    }

    return;
}


/*=========================================================================*/
/* 9. SYNCHRONIZATION                                                      */
/*=========================================================================*/
/**
 *  \status OK
 */
WFC_API_CALL void WFC_APIENTRY
wfcFence(WFCDevice dev,
         WFCContext ctx,
         WFCEGLDisplay dpy,
         WFCEGLSync sync)
{
    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
    return;
}

/*=========================================================================*/
/* 10. EXTENSION SUPPORT                                                   */
/*=========================================================================*/
/**
 *  \status OK
 */
WFC_API_CALL WFCint WFC_APIENTRY
wfcGetStrings(WFCDevice dev,
              WFCStringID name,
              const char **strings,
              WFCint stringsCount) WFC_APIEXIT
{
    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
    return 0;
}

/**
 *  \status OK
 */
WFC_API_CALL WFCboolean WFC_APIENTRY
wfcIsExtensionSupported(WFCDevice dev,
                        const char *string) WFC_APIEXIT
{
    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
    return WFC_FALSE;
}

/*=========================================================================*/
/* 11. TEST ONLY API FOR ON SCREEN IMAGE EXPORTING                         */
/*=========================================================================*/
/**
 *  \status OK
 */
WFC_API_CALL WFCNativeStreamType WFC_APIENTRY
wfcGetOnScreenStream(WFCDevice dev, WFCContext ctx) WFC_APIEXIT
{
    _wfc_set_error(WFC_ERROR_UNSUPPORTED);
    return WFC_INVALID_HANDLE;
}

