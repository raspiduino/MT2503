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
 *
 *
 * Project:
 * --------
 *    MAUI/HAL/WFD
 *
 * Description:
 * ------------
 *    This file is the INTERNAL used header file of LCD Tearing Manager.
 *    This file is only for target.
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
 * 01 28 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 01 22 2014 edwardyc.lin
 * removed!
 * 	.
 * 
 * 09 05 2012 chrono.wu
 * removed!
 * .
 *
 * 04 25 2012 xiaoyong.ye
 * removed!
 * Add serial LCM teaing manger code.
 *
 * 12 01 2011 haitao.shang
 * removed!
 * .
 *
 * 09 15 2011 bin.han
 * removed!
 * .
 *
 * 08 29 2011 bin.han
 * removed!
 * .
 *
 * 08 26 2011 bin.han
 * removed!
 * Fix LIBRA35 tearing issue due to lcmSyncSignalMode type change
 *
 * 08 17 2011 matthew.chen
 * removed!
 * Review Tearing Manager:
 * -	Don't override the LCM ioctrl result in lcdTear_GetCapabilityAndPara
 * -	Not disable lcmFrameMarkSupport in lcdTear_GetCapabilityAndPara according to unrelated information
 * -	Revise the selection logic within lcdTear_ChooseSuitableSyncMode
 * -	Move lcdSyncModeSupportCap init to chip-dep functions like lcdTear_SetSyncModePriority_6276
 * -	Don't set lcdSyncModeSupportCap within lcdTear_Init
 * -	Simplify lcdTear_SetSyncModeSupportCapability_6276
 *
 * 06 02 2011 matthew.chen
 * removed!
 * Check in slim-ed DDv2 to Maui
 *
 * 05 11 2011 bin.han
 * removed!
 * .
 *
 * 04 21 2011 bin.han
 * removed!
 * .
 *
 * 03 11 2011 sophie.chen
 * removed!
 * .
 *
 * 03 02 2011 sophie.chen
 * removed!
 * .
 *
 * 02 10 2011 sophie.chen
 * removed!
 * .
 *
 * 02 10 2011 chelun.tsai
 * removed!
 * modify drv_features.h include.
 *
 * 01 28 2011 chelun.tsai
 * removed!
 * modify tearing control array size.
 *
 * 12 24 2010 sophie.chen
 * removed!
 * .
 *
 * 12 23 2010 sophie.chen
 * removed!
 * .
 *
 * 12 22 2010 sophie.chen
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __LCD_TEAR_MANAGER_INTERNAL_H__
#define __LCD_TEAR_MANAGER_INTERNAL_H__

#if defined(__MTK_TARGET__)

#include "drv_comm.h"
#include "kal_release.h"
//#include "lcd_if_hw.h"
//#include "lcd_if.h"
//#include "lcd_sw.h"
#include "lcd_if_manager.h"
#include "lcd_tear_manager\inc\lcd_tear_manager.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"

#ifdef DUAL_LCD
#define ATTACHED_LCM_COUNT 2
#else
#define ATTACHED_LCM_COUNT 1
#endif

#if defined (DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT)
#include "lcd_sw.h"

#if defined(__SYNC_LCM_HW_SUPPORT__)
#define SYNC_MAIN_LCM_HW_SUPPORT
#endif
#if defined(__SYNC_LCM_SW_SUPPORT__)
#define SYNC_MAIN_LCM_SW_SUPPORT
#endif
#if defined(__SUBLCD_SYNC_LCM_HW_SUPPORT__)
#define SYNC_SUB_LCM_HW_SUPPORT
#endif
#if defined(__SUBLCD_SYNC_LCM_SW_SUPPORT__)
#define SYNC_SUB_LCM_SW_SUPPORT
#endif

#define LCDTEAR_PORT0_OUTPUT_FORMAT MAIN_LCD_OUTPUT_FORMAT
#ifdef DUAL_LCD
#define LCDTEAR_PORT1_OUTPUT_FORMAT SUB_LCD_OUTPUT_FORMAT
#else
#define LCDTEAR_PORT1_OUTPUT_FORMAT 0xFFFFFFFF
#endif

// The following checks TE pin gpio setting.
#if 0		// Disable TE pin check temporarily
#if defined(SYNC_MAIN_LCM_HW_SUPPORT)
/* under construction !*/
	#if (!defined(GPIO_PORT30_MODE) && !defined(GPIO_PORT50_MODE))
/* under construction !*/
	#else
		#if !((defined(GPIO_PORT30_MODE) && (GPIO_PORT30_MODE == MODE_2)) || (defined(GPIO_PORT50_MODE) && (GPIO_PORT50_MODE == MODE_1)))
/* under construction !*/
		#endif
	#endif
#endif
#endif

//The following is Tearing Mode support define
#if defined(SYNC_MAIN_LCM_HW_SUPPORT) || defined(SYNC_SUB_LCM_HW_SUPPORT)
        #if defined(DRV_LCD_TEARING_VSYNC_MODE_SUPPORT)
        #define LCDTEAR_HW_VSYNC_MODE_SUPPORT
            #define LCDTEAR_HW_VSYNC_HW_FRAME_MARKER_MODE_SUPPORT
    
        #if defined(DRV_LCD_TEARING_VSYNC_HW_DELAY_MODE_SUPPORT)
            #define LCDTEAR_HW_VSYNC_HW_DELAY_TIME_MODE_SUPPORT
        #else
            #define LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE_SUPPORT
        #endif

            #if defined(DRV_LCD_TEARING_VHSYNC_MODE_SUPPORT)
            #define LCDTEAR_HW_VHSYNC_MODE_SUPPORT
        #endif
    #endif
    
        #if defined(DRV_LCD_TEARING_SCANLINE_MODE_SUPPORT)
        #define LCDTEAR_HW_SCAN_LINE_MODE_SUPPORT
    #endif
#elif defined(SYNC_MAIN_LCM_SW_SUPPORT) || defined(SYNC_SUB_LCM_SW_SUPPORT)
    #define LCDTEAR_HW_EINT_VSYNC_SW_DELAY_TIME_MODE_SUPPORT
#else
    #define LCDTEAR_NO_SYNC_SUPPORT
#endif

#endif
#define LCDTEAR_PORT0 0
#define LCDTEAR_PORT1 1

typedef enum
{
  LCDTEAR_HW_VSYNC_MODE = 0, //only V-Sync is available
  LCDTEAR_HW_VSYNC_HW_FRAME_MARKER_MODE, // V-Sync + Frame Marker(for Partial Update)
  LCDTEAR_HW_VSYNC_HW_DELAY_TIME_MODE,   // V-Sync + HW delay time(for Partial Update)
  LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE,   // V-Sync + SW delay time(for Partial Update)

  LCDTEAR_HW_VHSYNC_MODE,                // V-Sync + H-SYnc(for Partial Update)
  LCDTEAR_HW_SCAN_LINE_MODE,             // read LCM scan line register
  LCDTEAR_HW_EINT_VSYNC_SW_DELAY_TIME_MODE, // EINT V-Sync + SW delay time(for Partial Update)

  LCDTEAR_NO_SYNC,

  LCDTEAR_MODE_MAX_CNT,


  LCDTEAR_MODE_RSVD = 0xffffff
}lcdTearSyncModeEnum;

typedef struct{
  kal_bool    swTESyncEnable;
  kal_bool    swTESyncPolarity;
  kal_bool    swTESyncCurrentPolarity;
  kal_bool    swTESyncTimerExpired;
  kal_uint32  swTESyncChannel;

  kal_uint32  swTESyncVsyncTime;
  kal_uint32  swTESyncStartTime;
  kal_uint32  swTESyncDelayTime;//us
  kal_timerid swTESyncTimer;

  kal_bool       swTESyncTimerStart;
  kal_eventgrpid swTESyncEvent;
}lcdTearSwTeSyncCtrlBlk;


typedef struct
{
  lcdTearErrorCode (*SetSyncModePriority)(kal_uint32 port_id);
  lcdTearErrorCode (*SetSyncModeSupportCapability)(kal_uint32 port_id);
  lcdTearErrorCode (*SetLCDHwCapabilityAndPara)(kal_uint32 port_id);
}LCDTearInitPrimitieves;


#define LCDTEAR_AVAILABLE_SYNC_MODE_COUNT LCDTEAR_MODE_MAX_CNT
#define  LCDTEAR_CALLBACK_PARA_COUNT 3
typedef struct
{
  //LCM info
  kal_uint32 lcmFrameRate;
  kal_uint32 lcmVsyncWidth; //uint: lcd clock count
  kal_uint32 lcmWidth;      //uint: pixel
  kal_uint32 lcmHeight;     //uint: pixel
  kal_uint32 lcmBackPorch;  //uint: line
  kal_uint32 lcmFrontPorch;  //uint: line
  LCM_TE_SYNC_MODE lcmSyncSignalMode;
  LCM_TE_ATTRIB_ENUM lcmVsyncActiveEdge;
  kal_uint32 lcmFrameMarker;    ///unit: line

  //LCM capability
  kal_bool lcmFrameMarkSupport;
  kal_bool lcmVHSyncSupport;
  kal_bool lcmScanLineSupport;

  //LCD info
  float lcdClockWidth;
  //(wst + 1 + c2wh + 1 + period + 2) * transfer_cnt_per_pixel (ns)
  float lcdPixelTransitionTime; 
  float lcmScanTimePerLine; //(ns)
  LCD_Funcs* ifFuncTable;
  LCD_IOCTRL_DEVICE_IF_T lcdIfSetting;

  //LCD capability
  kal_bool lcdVHSyncSupport;
  kal_bool lcdScanLineSupport;
  kal_bool lcdDelayTimeSupport;

  //Dedicate TE pin or EINT
  kal_bool hwTESyncSupport;
  kal_bool swTESyncSupport;

  /*EINT TE signal control info*/
  lcdTearSwTeSyncCtrlBlk swTESyncCtrlBlk;
  kal_timerid swDelayTimer; //SW delay timer
  kal_uint32  swDelayTimeInterval; //SW delay time value

  /*Control HW info*/
  LCDTearInitPrimitieves  lcdTEInitPrimitiviesTab;

  /*SyncMode info*/
  lcdTearSyncModeEnum lcdSyncModePriority[LCDTEAR_AVAILABLE_SYNC_MODE_COUNT];
  kal_bool lcdSyncModeSupportCap[LCDTEAR_AVAILABLE_SYNC_MODE_COUNT];
  lcdTearSyncModeEnum usedLcdSyncMode;

  /*TearManager Control info*/
  //block caller until getting V/H sync?
  kal_bool          lcdTESyncBlockingReq;
  LCDTEAR_CALLBACK  lcdTearCallback;
  kal_uint32        lcdTearCallbackPara[LCDTEAR_CALLBACK_PARA_COUNT];

  kal_uint32        _rsvdTEReg0; //teControl register
  kal_uint32        _rsvdTEReg1;
  kal_uint32        _rsvdTEReg2;
  kal_uint32        _rsvdTEReg3;


  kal_bool _busy; //
}lcdTearCtrlBlk;


#define LCDTEAR_USE_DEFAULT_INIT_PRIMITIVIES NULL
void
lcdTear_HookInitPrimitives(
  kal_uint32 port_id,
  LCDTearInitPrimitieves *pInitPrimitieves);

void lcdTear_TearingControlforSerialLCM_6255(kal_uint32 port_id);
void lcdTear_TearingControlforSerialLCM_6250(kal_uint32 port_id);
#endif //defined(__MTK_TARGET__)

#endif //__LCD_TEAR_MANAGER_INTERNAL_H__
