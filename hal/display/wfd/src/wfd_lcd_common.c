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
 *    wfd_lcd_6236.c
 *
 * Project:
 * --------
 *    MAUI/HAL/WFD
 *
 * Description:
 * ------------
 *    This file is the body of MT6236 LCD HW driver.
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
 * 02 26 2014 chrono.wu
 * removed!
 * fix lcd power ctrl for sleep mode to take effect.
 *
 * 01 21 2014 edwardyc.lin
 * removed!
 *
 * 09 26 2013 chrono.wu
 * removed!
 * fix MM_COLOR clock does not turn off correctly issue.
 *
 * 02 07 2013 hung-wen.hsieh
 * removed!
 * .
 *
 * 02 04 2013 ricky.lin
 * removed!
 * .
 *
 * 01 23 2013 joey.pan
 * removed!
 * Add PQ power control.
 *
 * 01 21 2013 joey.pan
 * removed!
 * Fix pq build errors.
 *
 * 01 21 2013 joey.pan
 * removed!
 * Turn on mdp path PQ setting.
 *
 * 01 21 2013 joey.pan
 * removed!
 * Merge PQv2 modification.
 *
 * 12 27 2012 joey.pan
 * removed!
 * Fix sub_lcd cannot sleep in issue.
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 * 
 * 10 19 2012 chrono.wu
 * removed!
 * .
 * 
 * 09 25 2012 chrono.wu
 * removed!
 * .
 * 
 * 09 07 2012 chrono.wu
 * removed!
 * .
 * 
 * 07 24 2012 haitao.shang
 * removed!
 * .
 * 
 * 07 19 2012 haitao.shang
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
 * 06 19 2012 jody.li
 * removed!
 * .
 *
 * 05 31 2012 haitao.shang
 * removed!
 * .
 *
 * 05 25 2012 jody.li
 * removed!
 * <saved by Perforce>
 *
 * 05 25 2012 haitao.shang
 * removed!
 * .
 *
 * 03 21 2012 xiaoyong.ye
 * removed!
 * Support ARGB6666/PARGB6666 check in.
 *
 * 03 20 2012 xiaoyong.ye
 * removed!
 * MT6250 display driver check in.
 *
 * 03 14 2012 haitao.shang
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
 * 12 22 2011 yinli.liang
 * removed!
 * .
 *
 * 11 29 2011 haitao.shang
 * removed!
 * .
 *
 * 11 08 2011 dong.guo
 * removed!
 * removed unused varible.
 *
 * 11 07 2011 yinli.liang
 * removed!
 * .
 *
 * 11 07 2011 dong.guo
 * removed!
 * .
 *
 * 11 03 2011 xiaoyong.ye
 * removed!
 * Invalidate the write buffer cache by invalidate_wt_cache().
 *
 * 10 27 2011 dong.guo
 * removed!
 * MT6255 DDv2 check in .
 *
 * 10 26 2011 dong.guo
 * removed!
 * MT6235 HW bug workaround check in,  in __wfd_lcd_hisr, polling lcd running bit and read int status twice to clear the wrong interrupt.
 *
 * 10 25 2011 haitao.shang
 * removed!
 * .
 *
 * 10 19 2011 zifeng.qiu
 * removed!
 * if roi_width equals to 0, HW behavior will be abnormal.
 *
 * 10 10 2011 zifeng.qiu
 * removed!
 * .
 *
 * 09 30 2011 haitao.shang
 * removed!
 * .
 *
 * 09 23 2011 dong.guo
 * removed!
 * code review:  in _wfd_lcd_blt disable layer if no overlap with ROI.
 * Exclude Lcd_profiling.h and its reference
 *
 * 09 15 2011 bin.han
 * removed!
 * .
 *
 * 09 08 2011 zifeng.qiu
 * removed!
 * .
 *
 * 09 06 2011 haitao.shang
 * removed!
 * .
 *
 * 09 06 2011 zifeng.qiu
 * removed!
 * .
 *
 * 09 02 2011 bin.han
 * removed!
 * .
 *
 * 09 02 2011 zifeng.qiu
 * removed!
 * .
 *
 * 09 02 2011 bin.han
 * removed!
 * .
 *
 * 09 01 2011 bin.han
 * removed!
 * .
 *
 * 09 01 2011 zifeng.qiu
 * removed!
 * For fast logo feature.
 *
 * 08 31 2011 zifeng.qiu
 * removed!
 * .
 *
 * 08 23 2011 zifeng.qiu
 * removed!
 * .
 *
 * 08 17 2011 zifeng.qiu
 * removed!
 * .
 *
 * 08 17 2011 zifeng.qiu
 * removed!
 * .
 *
 * 08 12 2011 bin.han
 * removed!
 * .
 *
 * 08 12 2011 bin.han
 * removed!
 * .
 *
 * 08 10 2011 bin.han
 * removed!
 * .
 *
 * 08 10 2011 zifeng.qiu
 * removed!
 * Resolve low power issue.
 *
 * 08 10 2011 bin.han
 * removed!
 * .
 *
 * 08 05 2011 zifeng.qiu
 * removed!
 * .
 *
 * 08 04 2011 bin.han
 * removed!
 * .
 *
 * 07 27 2011 zifeng.qiu
 * removed!
 * .
 *
 * 07 27 2011 zifeng.qiu
 * removed!
 * .
 *
 * 07 26 2011 bin.han
 * removed!
 * .
 *
 * 07 21 2011 bin.han
 * removed!
 * .
 *
 * 07 12 2011 zifeng.qiu
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
 * 07 01 2011 bin.han
 * removed!
 * LOW_COST_SUPPORT
 *
 * 06 23 2011 bin.han
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
 * .
 *
 * 06 01 2011 bin.han
 * removed!
 * RAM size reduction
 *
 * 05 18 2011 zifeng.qiu
 * removed!
 * Event Group Slim.
 *
 * 05 18 2011 zifeng.qiu
 * removed!
 * .
 *
 * 05 16 2011 zifeng.qiu
 * removed!
 * 6235 W2M Workaround Check In.
 *
 * 05 13 2011 bin.han
 * removed!
 * MT6236 SLIM driver check in
 *
 * 05 11 2011 zifeng.qiu
 * removed!
 * Resolve lcd_sleep_in & out racing condition.
 *
 * 05 11 2011 zifeng.qiu
 * removed!
 * Revise TE Error Handling.
 *
 * 05 04 2011 bin.han
 * removed!
 * .
 *
 * 04 29 2011 zifeng.qiu
 * removed!
 * .
 *
 * 04 28 2011 zifeng.qiu
 * removed!
 * .
 *
 * 04 26 2011 zifeng.qiu
 * removed!
 * Use ASSERT to handle TE Timeout.
 *
 * 04 26 2011 zifeng.qiu
 * removed!
 * Resolve Build Error.
 *
 * 04 26 2011 zifeng.qiu
 * removed!
 * Handle LCD TE Timeout Mechanism.
 *
 * 04 21 2011 bin.han
 * removed!
 * .
 *
 * 04 14 2011 zifeng.qiu
 * removed!
 * .
 *
 * 04 11 2011 bin.han
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
 * 04 01 2011 zifeng.qiu
 * removed!
 * .
 *
 * 04 01 2011 zifeng.qiu
 * removed!
 * .
 *
 * 03 28 2011 bin.han
 * removed!
 * .
 *
 * 03 28 2011 bin.han
 * removed!
 * Remove WFD image source pool
 *
 * 03 18 2011 bin.han
 * removed!
 * .
 *
 * 03 15 2011 chelun.tsai
 * removed!
 * wfd error code modify.
 *
 * 03 14 2011 ct.fang
 * removed!
 * .
 *
 * 03 14 2011 sophie.chen
 * removed!
 * .
 *
 * 03 11 2011 sophie.chen
 * removed!
 * .
 *
 * 03 11 2011 sophie.chen
 * removed!
 * .
 *
 * 03 11 2011 sophie.chen
 * removed!
 * .
 *
 * 03 08 2011 ct.fang
 * removed!
 * .
 *
 * 03 08 2011 chelun.tsai
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
 * 03 03 2011 bin.han
 * removed!
 * .
 *
 * 03 03 2011 chelun.tsai
 * removed!
 * 6268 use dedicate blt fuction.
 *
 * 03 03 2011 bin.han
 * removed!
 * .Fix sub LCD interface user setting error
 *
 * 02 23 2011 ct.fang
 * removed!
 * .
 *
 * 02 21 2011 chelun.tsai
 * removed!
 * 6268 DC mode.
 *
 * 02 18 2011 chelun.tsai
 * removed!
 * new mt6268 DC mode, LCD trigger MDP.
 *
 * 02 17 2011 sophie.chen
 * removed!
 * .
 *
 * 02 14 2011 marvin.tsai
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
 * 02 09 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 01 28 2011 sophie.chen
 * removed!
 * .
 *
 * 01 27 2011 sophie.chen
 * removed!
 * .
 *
 * 01 26 2011 sophie.chen
 * removed!
 * .
 *
 * 01 21 2011 sophie.chen
 * removed!
 * .
 *
 * 01 20 2011 ct.fang
 * removed!
 * .
 *
 * 01 17 2011 sophie.chen
 * removed!
 * .
 *
 * 01 14 2011 sophie.chen
 * removed!
 * .
 *
 * 12 30 2010 marvin.tsai
 * removed!
 * .
 *
 * 12 27 2010 chelun.tsai
 * removed!
 * .
 *
 * 12 26 2010 sophie.chen
 * removed!
 * .
 *
 * 12 25 2010 ke-ting.chen
 * removed!
 * Merry Christmas!
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
 * 12 22 2010 sophie.chen
 * removed!
 * .
 *
 * 12 20 2010 sophie.chen
 * removed!
 * .
 *
 * 11 23 2010 sophie.chen
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__MTK_TARGET__)

/*****************************************************************************
 *  Local macro definitions
 ****************************************************************************/

// TODO: [m] check why cannot use drv feature options but chip options...
#if defined(MT6236) || defined(MT6253) || defined(MT6252) || defined(MT6252H) || defined(MT6253E) || defined (MT6276) || defined (MT6268) || defined(MT6235) || defined(MT6235B) || defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)

/*****************************************************************************
 *  Include directives
 ****************************************************************************/
#include "drv_comm.h"
#include "drv_hisr.h"
#include "wfd\inc\wfd_hwdevice.h"
#include "wfd\inc\wfd_lcd_chip_select.h"
#include "wfd\inc\wfd.h"
#include "wfd\inc\wfdplatform.h"
#include "mm_power_ctrl.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "kal_release.h"
#include "lcd_if_hw.h"
#include "lcd_if.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "common/owftypes.h"
#include "common/owfimage.h"
#include "wfd\inc\wfd_lcd_internal.h"
#include "wfd\inc\wfd_common.h"
#include "lcd_power_mgr.h"
#include "lcd_if_manager.h"
#include "l1_interface.h"
#include "lcd_tear_manager\inc\lcd_tear_manager.h"
#include "debug\inc\lcd_catcher_log.h"
#include "cache_sw.h"

#include "drv_features_display.h"
#include "drv_sw_features_display.h"
#include "dcl.h"
#include "lcm_if.h"
#include "drv_features_color.h"
#include "color_enum.h"
#include "color_api.h"

#if defined(__FAST_LOGO__)
#include "init.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

static kal_semid _lcd_physical_interface_mutex = KAL_NILSEM_ID;

/*****************************************************************************
 *  Local variables
 ****************************************************************************/
static WFDuint _lcd_if_mgr_port_handle[WFD_ATTACHED_PORT_COUNT] = {0};
LCD_IOCTRL_DEVICE_IF_T _lcd_if_mgr_port_setting[WFD_ATTACHED_PORT_COUNT];

WFD_PORT _wfd_lcd_port[WFD_ATTACHED_PORT_COUNT] = {0};
WFD_PIPELINE _wfd_lcd_pipeline[DRV_LAYER_TOTAL_COUNT] = {0};
extern WFD_DEVICE _wfd_lcd_device;

static WFD_PORT* _wfd_current_processing_port = NULL;
static DCL_HANDLE _wfd_lcd_timer = NULL;
extern kal_eventgrpid _owf_event;
WFDuint wfd_lcd_power_ctrl_handle = 0xFFFFFFFF;

extern volatile LCD_Funcs  *MainLCD;
extern volatile LCD_Funcs  *SubLCD;

extern void init_lcd_interface(void);
extern WFDErrorCode wfd_lcd_hook_internal_utility(WFDHWDeviceInternalUtilityMTK *plcd_utilities);
#ifdef COMBO_LCM_ID_AUTO_DETECT
extern void LCM_ID_Alter(void);
extern kal_bool LCM_ID_Validation(void);
#endif



static WFDLCDInterfacePara _wfd_lcd_if_para[WFD_ATTACHED_PORT_COUNT];
WFDboolean WFD_START_DETECT_TE = WFD_FALSE;

kal_uint32 _HwStartRefreshTime = 0;
WFDboolean _IsFullScreenUpdate = WFD_FALSE;
kal_uint32 _MaxWaitTETime = 0;
#if defined(DDV2_PERFORMANCE_PROFILING_SUPPORT)
kal_uint32 lcd_profiling_start_update_time;
kal_uint32 lcd_profiling_start_flatten_time;
kal_uint32 lcd_profiling_lisr_time_tick;
kal_uint32 lcd_profiling_hisr_time_tick = 0;
kal_uint32 lcd_profiling_period_time_tick = 32768;
kal_uint32 lcd_profiling_period_start_time_tick;
kal_uint32 lcd_profiling_period_update_frame_count;
kal_uint32 lcd_profiling_period_drop_frame_count;
kal_bool lcd_profiling_enable_te_flag = KAL_FALSE;
kal_uint32 lcd_profiling_oneFrame_totalTime = 0;
#endif

//Dong: for 35HW bug see MAUI_03053277
#if defined(MT6235) || defined(MT6235B)
kal_bool last_callback_done_flag = KAL_FALSE; 
static kal_uint32 wrong_hisr_counter = 0;
#endif

/*****************************************************************************
 *  Internal used macros
 ****************************************************************************/
#define CHECK_DEVICE(d, errorcode, retval)
#define CHECK_DEVICE_NR(d, errorcode)


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
#else
#define CHECK_HANDLE(d, h, errorcode, retval)
#define CHECK_HANDLE_NR(d, h, errorcode)
#define CHECK_CONDITION(d, c, errorcode, retval) 
#define CHECK_CONDITION_NR(d, c, errorcode)
#endif

#define DPRINT(x) 


/*****************************************************************************
 *  Local function definitions
 ****************************************************************************/
// TODO: [m] check why this option WFD_LCD_DBG_SUPPORT is not defined/undefined in MT6235 driver header: wfd_lcd_6235.h 
#if defined(WFD_LCD_DBG_SUPPORT)
/**
 *  \def WFD_LCD_DBG_ENTRY_CNT
 *  This number must be 2^N
 */
#if !defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__LOW_COST_SUPPORT_ULC__)
    #define WFD_LCD_DBG_ENTRY_CNT (16)     
#else
    #define WFD_LCD_DBG_ENTRY_CNT (16)  ///Bin: for debug    
#endif

// Chelun : move to wfd_lcd_internal.h
//typedef enum
//{
//  WFDLCD__...
//  
//}WFDLCDDbgIdEnum;

typedef struct
{
  WFDLCDDbgIdEnum id;
  WFDErrorCode    error;
  WFDuint         intStatus;

#if defined(DRV_LCD_MT6268_SERIES)
  WFDuint         dcReg;
#endif  // #if defined(DRV_LCD_MT6268_SERIES)

#if defined(LCD_DEBUG_POWER_CONTROL_AND_WHITE_SCREEN)
  WFDuint         ifReg;
  WFDuint         teReg;
  WFDuint         roiCtrl;
  WFDuint         roiSz;
  WFDuint         HWref;
#endif  // #if defined(LCD_DEBUG_POWER_CONTROL_AND_WHITE_SCREEN)

  WFDuint         time;
} WFDLCDDbgCtrlBlk;


WFDuint _wfdLcdDbgCnt = 0;
WFDLCDDbgCtrlBlk _wfdLcdDbgDat[WFD_LCD_DBG_ENTRY_CNT];
static volatile WFDboolean _wfdDbgInit = WFD_FALSE;
void __wfd_lcd_trace(WFDLCDDbgIdEnum id)
{
  kal_uint32 index;
  if(_wfdDbgInit == WFD_FALSE)
  {
  	kal_mem_set((void *)(&_wfdLcdDbgDat[0]),0,sizeof(WFDLCDDbgCtrlBlk)*WFD_LCD_DBG_ENTRY_CNT);
	_wfdDbgInit = WFD_TRUE;
  }
  if (KAL_TRUE == INT_QueryExceptionStatus())
  {
    index = _wfdLcdDbgCnt;
    _wfdLcdDbgCnt++;
    _wfdLcdDbgCnt &= (WFD_LCD_DBG_ENTRY_CNT-1);
  }
  else
  {
    kal_uint32 mask = SaveAndSetIRQMask();
    index = _wfdLcdDbgCnt;
    _wfdLcdDbgCnt++;
    _wfdLcdDbgCnt &= (WFD_LCD_DBG_ENTRY_CNT-1);
    RestoreIRQMask(mask);
  }

  _wfdLcdDbgDat[index].id = id;
  _wfdLcdDbgDat[index].error = _wfd_lcd_device.lastUnreadError;
  _wfdLcdDbgDat[index].time = drv_get_current_time();

#if defined(DRV_LCD_MT6268_SERIES)
	_wfdLcdDbgDat[index].dcReg= *(volatile unsigned int*)(0x91000068);
#endif  // #if defined(DRV_LCD_MT6268_SERIES)
  
#if defined(LCD_DEBUG_POWER_CONTROL_AND_WHITE_SCREEN)
  _wfdLcdDbgDat[index].ifReg = REG_LCD_PARALLEL0_CONFIG;
  _wfdLcdDbgDat[index].teReg = REG_LCD_TECON;
  _wfdLcdDbgDat[index].roiCtrl = REG_LCD_ROI_CTRL;
  _wfdLcdDbgDat[index].roiSz = REG_LCD_ROI_SIZE;
  _wfdLcdDbgDat[index].HWref = REG_LCD_ROI_HW_CTRL;
#endif  // #if defined(LCD_DEBUG_POWER_CONTROL_AND_WHITE_SCREEN)
	
}
#else   // #if defined(WFD_LCD_DBG_SUPPORT)
#define __wfd_lcd_trace(i)
#endif  // #if defined(WFD_LCD_DBG_SUPPORT)

/**
 *  \def WFD_CATCHLOG_TEAR_DBGMSG_SUPPORT
 *  If this is defined, WFD uses MOD_MED to log traces for tearing information.
 */
//#define WFD_CATCHLOG_TEAR_DBGMSG_SUPPORT
//extern kal_uint32 DEBUG__HSYNC_COUNT;
//extern kal_uint32 DEBUG__LCM_STARTY;

#if defined(WFD_CATCHLOG_TEAR_DBGMSG_SUPPORT)
//Profiling
static WFDuint _wfd_port_start_busy_timestamp = 0;
static WFDuint _wfd_port_update_duration = 0;
#define pf_entry (32)
typedef struct
{
  kal_uint32 en_layer;
  kal_uint32 w;
  kal_uint32 h;
  kal_uint32 t;
  kal_uint32 layer_ctrl[4];
  kal_uint32 nli_arb_cs;
  kal_uint32 ultra_ctrl;
  kal_uint32 hsync;
  kal_uint32 lcmSY; //startY
} performance;
static performance pf[pf_entry];
static kal_uint32 pf_idx = 0;

// TODO: [o] modify this to use function instead if needed 
// TODO: [m] Use drv trace but use MOD_MED
#define WFD_CATCHLOG(msg) kal_prompt_trace(MOD_MED, msg)
#define WFD_CATCHLOG_PROFILE_START()\
{\
  kal_uint32 index;\
  if (KAL_TRUE == INT_QueryExceptionStatus())\
  {\
    index = pf_idx;\
  }\
  else\
  {\
  kal_uint32 mask = SaveAndSetIRQMask();\
  index = pf_idx;\
  RestoreIRQMask(mask);\
  }\
  pf[index].w = (REG_LCD_ROI_SIZE) & 0xFFFF;\
  pf[index].h = ((REG_LCD_ROI_SIZE) >> 16) & 0xFFFF;\
  pf[index].en_layer = (((REG_LCD_ROI_CTRL) >> 28) & 0xF);\
  pf[index].layer_ctrl[0] = REG_LCD_LAYER0_CTRL;\
  pf[index].layer_ctrl[1] = REG_LCD_LAYER1_CTRL;\
  _wfd_port_start_busy_timestamp = drv_get_current_time();\
}
//  pf[index].layer_ctrl[2] = REG_LCD_LAYER2_CTRL;\
//  pf[index].layer_ctrl[3] = REG_LCD_LAYER3_CTRL;\
//  pf[index].nli_arb_cs = REG_NLI_ARB_CS;\
//  pf[index].ultra_ctrl = REG_LCD_ULTRA_CON;\
//  pf[index].hsync = DEBUG__HSYNC_COUNT;\
//  pf[index].lcmSY = DEBUG__LCM_STARTY;\
//  kal_prompt_trace(MOD_MED, "[LCD] Start update.\n");\

#define WFD_CATCHLOG_PROFILE_END() \
{\
  kal_uint32 index;\
  if (KAL_TRUE == INT_QueryExceptionStatus())\
  {\
    index = pf_idx;\
    pf_idx = (++pf_idx) & (pf_entry-1);\
  }\
  else\
  {\
  kal_uint32 mask = SaveAndSetIRQMask();\
  index = pf_idx;\
  pf_idx = (++pf_idx) & (pf_entry-1);\
  RestoreIRQMask(mask);\
  }\
  _wfd_port_update_duration = drv_get_duration_ms(_wfd_port_start_busy_timestamp);\
  pf[index].t = _wfd_port_update_duration;\
}
//  kal_prompt_trace(MOD_MED, "[LCD] End update. Busy Interval: %d\n", _wfd_port_update_duration);\

#else   // #if defined(WFD_CATCHLOG_TEAR_DBGMSG_SUPPORT)
#define WFD_CATCHLOG(msg)
#define WFD_CATCHLOG_PROFILE_START()
#define WFD_CATCHLOG_PROFILE_END()
#endif  // #if defined(WFD_CATCHLOG_TEAR_DBGMSG_SUPPORT)

kal_bool
LCD_Physical_Interface_Lock(void)
{
    if ((kal_query_systemInit() == KAL_TRUE) || (INT_QueryExceptionStatus()))
    {
        return KAL_TRUE;
    }
    
    if (KAL_NILSEM_ID == _lcd_physical_interface_mutex)
    {
        _lcd_physical_interface_mutex = kal_create_sem("LCD_Physical_Interface", 1);
    }
    
    if ((!kal_if_hisr()) && (!kal_if_lisr())) //Task Level
    {
        kal_take_sem(_lcd_physical_interface_mutex, KAL_INFINITE_WAIT);
        return KAL_TRUE;    			
    }
    else //HISR Level
    {
    	if (KAL_SUCCESS == kal_take_sem(_lcd_physical_interface_mutex, KAL_NO_WAIT))
            return KAL_TRUE;
    	else
            return KAL_FALSE;
    }
}

kal_bool
LCD_Physical_Interface_Unlock(void)
{
    if ((kal_query_systemInit() == KAL_TRUE) || (INT_QueryExceptionStatus()))
    {
        return KAL_TRUE;
    }
    
    if (KAL_NILSEM_ID != _lcd_physical_interface_mutex)
    {
        kal_give_sem(_lcd_physical_interface_mutex);
    }
    return KAL_TRUE;
}


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
#endif

/*!
 *  enable/disable port sync mechanism.
 *
 *  \param enable           WFD_TRUE to enable. WFD_FALSE to disable.
 *
 *  \return                 NA
 *                          
 */
static void __wfd_lcd_EnablePortSync(WFDboolean enable)
{
    if(WFD_TRUE == enable)
    {
      ENABLE_LCD_TE_DETECT();
    }
    else
    {
      DISABLE_LCD_TE_DETECT();
    }
}

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
#if defined(__SYNC_LCM_HW_SUPPORT__)
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
/* under construction !*/
#endif

WFDboolean __wfd_lcd_IsWaitHwVsync(void)
{
// TODO: [m] Check if SUB LCD uses different compile option. This will make SUB LCD fail!
#if defined(__SYNC_LCM_HW_SUPPORT__)
    return (WFDboolean)((REG_LCD_TECON & LCD_TE_ENABLE_BIT) && (LCD_WAIT_TE));
#else
    return WFD_FALSE;
#endif
}


/*!
 *  Convert WFD format definition to LCD HW register definition.
 *
 *  \param format           OWF image color format
 *                          Handle to newly created stream, or OWF_INVALID_HANDLE if no
 *                          stream could be created.\n
 *  \notice                 This function may not achieve all chips' LCD requirement.
 *                          If need, please overwrite this function _wfd_lcd_utilities 
 *                          in your wfd_lcd_hook_internal_utility(~).\n
 */
WFDuint
__wfd_lcd_CnvtImgFormatToHwDef(OWF_IMAGE_FORMAT *format)
{
    switch (format->pixelFormat)
    {
        case OWF_IMAGE_L8:      { return WFD_LCD_LAYER_FORMAT_8BPP_INDEX; }

        case OWF_IMAGE_RGB565:  { return WFD_LCD_LAYER_FORMAT_RGB565; }

        case OWF_IMAGE_UYVY:    { return WFD_LCD_LAYER_FORMAT_UYVY422; }

        case OWF_IMAGE_RGB888:  { return WFD_LCD_LAYER_FORMAT_RGB888; }

        case OWF_IMAGE_ARGB8888:
        {
            if (format->premultiplied) { return WFD_LCD_LAYER_FORMAT_PARGB8888; }
            return WFD_LCD_LAYER_FORMAT_ARGB8888;
        }

        default:
        { 
            ASSERT(0);
            return WFD_LCD_LAYER_FORMAT_RSD; 
        }
    }

    //return WFD_LCD_LAYER_FORMAT_RSD;
}



/*!
 *  Convert Clockwise 0/90/180/270 degree to HW rotation/flip definition value.
 *
 *                          0xFFFFFFFF: means the passed paramrters are wrong\n
 *
 *  \notice                 This function may not achieve all chips' LCD requirement.
 *                          If need, please overwrite this function _wfd_lcd_utilities 
 *                          in your wfd_lcd_hook_internal_utility(~).\n
 */
WFDuint
__wfd_lcd_CnvtAngleToHwDef(WFD_DEVICE* device, WFDint angle, WFDboolean flip)
{
    switch (angle)
    {
        case 0:
        {
            return ((WFD_FALSE == flip) ? WFD_LCD_LAYER_ROTATE_NORMAL: WFD_LCD_LAYER_FLIP);
        }

        case 90:
        {
            return ((WFD_FALSE == flip) ? WFD_LCD_LAYER_ROTATE_270: WFD_LCD_LAYER_FLIP_ROTATE_270);
        }

        case 180:
        {
            return ((WFD_FALSE == flip) ? WFD_LCD_LAYER_ROTATE_180: WFD_LCD_LAYER_FLIP_ROTATE_180);
        }

        case 270:
        {
            return ((WFD_FALSE == flip) ? WFD_LCD_LAYER_ROTATE_90: WFD_LCD_LAYER_FLIP_ROTATE_90);
        }

        default:
        {
            WFD_ASSERT_CHECK(device, 0, WFD_ERROR_ILLEGAL_ARGUMENT, 0xffffff);
            return 0xffffff;
        }
    }

    //return WFD_LCD_LAYER_ROTATE_NORMAL;
}



/*!
 *  Convert WFD format definition to LCD HW register definition.
 *
 *                          WFD_LCD_HW_EVENT_UNKNOWN means the input event_type is wrong.
 *
 *  \notice                 This function may not achieve all chips' LCD requirement.
 *                          If need, please overwrite this function _wfd_lcd_utilities 
 *                          in your wfd_lcd_hook_internal_utility(~).\n
 */
WFDuint 
__wfd_lcd_CnvtEventToHWDef(WFDEventType event_type)
{
    switch (event_type)
    {
        case WFD_EVENT_VSYNC_MTK:
        { 
            return WFD_LCD_HW_EVENT_VSYNC_MTK; 
        }

        case WFD_EVENT_TE_SIGNAL_RECEIVED_MTK:
        {
            return WFD_LCD_HW_EVENT_TE_SIGNAL_RECEIVED_MTK;
        }

        case WFD_EVENT_COMMAND_TRANSFER_COMPLETE_MTK:
        {
            return WFD_LCD_HW_EVENT_COMMAND_TRANSFER_COMPLETE_MTK;
        }

        case WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK:
        {
            return WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK;
        }

        default:
        { 
            //WFD_ASSERT_CHECK(&_wfd_lcd_primitives, 0, WFD_ERROR_ILLEGAL_ARGUMENT, LCD_LAYER_MONO);
            //ASSERT(0);
            return WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK;
    }
}

    //return WFD_LCD_HW_EVENT_UNKNOWN;
}



/*!
 *  Convert WFD Color Format to W2MWM Format HW definition.\n
 *
 *                          WFD_LCD_WMEM_COLOR_RSVD means the input format is wrong.
 *
 *  \notice                 This function may not achieve all chips' LCD requirement.
 *                          If need, please overwrite this function _wfd_lcd_utilities 
 *                          in your wfd_lcd_hook_internal_utility(~).\n
 */
WFDuint
__wfd_lcd_CnvtW2memFormatToHwDef(OWF_IMAGE_FORMAT *format)
{
    switch (format->pixelFormat)
    {
        case OWF_IMAGE_RGB565:  
            return WFD_LCD_WMEM_COLOR_RGB565; 

        case OWF_IMAGE_RGB888:  
            return WFD_LCD_WMEM_COLOR_RGB888; 

        case OWF_IMAGE_ARGB8888:
            if (format->premultiplied) 
                return WFD_LCD_WMEM_COLOR_ARGB8888_PIXEL_ALPHA; 
            else
                return WFD_LCD_WMEM_COLOR_ARGB8888_CONSTANT_ALPHA;

        default:
            ASSERT(0);	  	
            return WFD_LCD_WMEM_COLOR_RSVD; 
    }
}


/*!
 *  Get Interface Period value. [LCD Only]
 *
 *  \param Port              Port struct
 *  \return                  Period value\n
 *
 *  \notice                  
 */
WFDuint
__wfd_lcd_GetDevicePeriodVal(WFD_PORT* port)
{
    switch(_lcd_if_mgr_port_setting[port->config.id].if_type)
    {
        case LCD_IF_TYPE_DBI_PARALLEL:
        {
            return _lcd_if_mgr_port_setting[port->config.id].if_settings.dbi_parallel_if.if_period;
        }

        case LCD_IF_TYPE_DBI_SERIAL:
        {
            return _lcd_if_mgr_port_setting[port->config.id].if_settings.dbi_serial_if.if_period;
        }
    }

    return 0;
}



/*!
 *  Rollback Port's Interface setting after power on LCD.
 *
 *                           and then powered on, we will continue to turn on LCD clock. At this
 *                           situation, we need to reconfigure all LCD interface related HW registers.
 *                           This function will call LCD Interface Manager to perform the port'interface
 *                           setting. Caller shall make sure to call this function before ask LCD to 
 *                           do any transfer.
 */
WFDboolean
__wfd_lcd_RollbackPortIFSetting(WFDint portId)
{
    //LCD_IOCTRL_RESULT_E err;
    WFDuint roi_ctrl;	 
    WFD_PORT* pPort = &_wfd_lcd_port[portId];
    // re-configure modified settings 

    //if (_lcd_if_mgr_port_setting[portId].if_settings.dbi_parallel_if.if_period != 3) 
    //  ASSERT(0);
	 
    lcd_ioctrl_device_if_settings(_lcd_if_mgr_port_handle[portId], 
                                        LCD_IOCTRL_CONFIG_DEVICE_IF, 
                                        &_lcd_if_mgr_port_setting[portId], 
                                        sizeof(LCD_IOCTRL_DEVICE_IF_T)); 

    //do the following reset for LCM sleep in/out.
    //for blt, these information will be reconfigure in __wfd_lcd_blt(~)

    roi_ctrl = REG_LCD_ROI_CTRL;
    roi_ctrl &= (~0xF000DFFF); //clear: Layer_enable & cmd_enable & command_cnt & format
    roi_ctrl |= (pPort->portOutputFormat & 0xff);
    roi_ctrl &= (~LCD_ROI_CTRL_CMDQ_SEL_BIT);
    if (1 == pPort->cmdQueueIdx)
    {
       roi_ctrl |= LCD_ROI_CTRL_CMDQ_SEL_BIT;
    }
    REG_LCD_ROI_CTRL = roi_ctrl;

    return WFD_TRUE;
}



/*!
 *  Backup Port's Interface setting after power on LCD.
 *
 *
 *  \notice                  See the notice of function: __wfd_lcd_RollbackPortIFSetting(~) first.
 *                           Due to the need of rollbacking register settings, sometimes we might 
 *                           want to keep curren HW register settings. At such situation, call this
 *                           function to backup the port's interface setting.
 */
/*static WFDboolean
__wfd_lcd_BackupPortIFSetting(WFDint portId)
{
    //LCD_IOCTRL_RESULT_E err;

    // re-configure modified settings 
    lcd_ioctrl_device_if_settings(_lcd_if_mgr_port_handle[portId], 
                                        LCD_IOCTRL_QUERY_DEVICE_IF, 
                                        &_lcd_if_mgr_port_setting[portId], 
                                        sizeof(LCD_IOCTRL_DEVICE_IF_T));

    return WFD_TRUE;
}*/


static void
__wfd_device_PowerCtrl(WFD_DEVICE* device, WFDuint handle, WFDboolean enable)
{
   if (enable)
   {
      WFDuint i;
      lcd_power_ctrl__enable(handle);
      for (i = 0; i < ATTACHED_LCM_CNT; i++)
      {
        __wfd_lcd_RollbackPortIFSetting(i);
      }
      
#if defined(__DRV_COLOR_HW_SUPPORT__)
      // turn on color power
      colorPowerEnable(KAL_TRUE);
#endif
   }
   else
   {
      lcd_power_ctrl__disable(handle);

#if defined(__DRV_COLOR_HW_SUPPORT__)
      // turn off color power
      colorPowerEnable(KAL_FALSE);
#endif
   }
}


/** DESCRIPTION :
 *    Create a timer to check if the request is finish or not.\n
 *  @param[in] NA
 *  @return NA
 *  @remark 
 */
extern void 
__wfd_lcd_TimerCb(void *parameter);
 
static void
__wfd_lcd_StartWatchDog(void)
{
  if (NULL == _wfd_lcd_timer)
      ASSERT(0);//return WFD_FALSE;

  __wfd_lcd_trace(WFDLCD________WATCHDOG_START0);

  if((kal_query_systemInit() == KAL_FALSE) && (!INT_QueryExceptionStatus()))
  {
     SGPT_CTRL_START_T start;
     __wfd_lcd_trace(WFDLCD________WATCHDOG_START1);

     start.u2Tick = 300;//WFD_LCD_TIMEOUT_INTERVAL;
     start.pfCallback = __wfd_lcd_TimerCb;
     start.vPara = NULL;
     DclSGPT_Control(_wfd_lcd_timer,SGPT_CMD_STOP,0);
     DclSGPT_Control(_wfd_lcd_timer,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
  }
}


/** DESCRIPTION :
 *    Stop watchdog => cancle the timer.\n
 *  @param[in] NA
 *  @return NA
 *  @remark 
 */
static void
__wfd_lcd_StopWatchDog(void)
{
  if (NULL == _wfd_lcd_timer)
      ASSERT(0);//return WFD_FALSE;

  __wfd_lcd_trace(WFDLCD________WATCHDOG___END0);

  if((kal_query_systemInit() == KAL_FALSE) && (!INT_QueryExceptionStatus()))
  {
    __wfd_lcd_trace(WFDLCD________WATCHDOG___END1);
    DclSGPT_Control(_wfd_lcd_timer, SGPT_CMD_STOP, 0);
  }
}


/** DESCRIPTION :
 *    LCD's TimeOur Callback Funciton. Used for driver to detect unexpected behavior.\n
 *  @param[in] parameter:
 *  @return NA
 *  @remark 
 */
static void 
__wfd_lcd_TimerCb(void *parameter)
{
  __wfd_lcd_StopWatchDog();
  if (__wfd_lcd_IsWaitHwVsync())
  {
    __wfd_lcd_trace(WFDLCD___TIMEOUT_CB________TE);

    {
        //Zifeng: From Designer, Only disable TE Cannot make LCD stop and LCD will continue to  wait for TE
        //Only stop -> disable TE -> start can work.
        STOP_LCD_TRANSFER;
        DISABLE_LCD_TE_DETECT();
        if(WFD_START_DETECT_TE == WFD_TRUE)
        {
            _wfd_current_processing_port->TEDetectionFail = WFD_TRUE;
			_wfd_current_processing_port->isTEsyncMode = WFD_FALSE;
        }
        __wfd_lcd_StartWatchDog();
        START_LCD_TRANSFER;
    }	 
  }
  else
  {
    __wfd_lcd_trace(WFDLCD___TIMEOUT_CB____OTHERS);

    ASSERT(0); // for development stage debug
  }
}


/*!
 *  Execute all active event callbacks.
 *
 *  \param pPort             Port structure.\n
 *  \param interruptStatus   The interrupt status\n
 *  \return                  NA\n
 *
 *  \notice                  This fucntion is called in HISR and Blt function now to 
 *                           execute WFC's all registered callback functions.
 */
void
__wfd_lcd_ExecActiveEventsCb(WFD_PORT* pPort, WFDuint interruptStatus)
{
    WFD_PORT_CONFIG* pPortCfg;
    //WFD_DEVICE* pDevice = &_wfd_lcd_device;

    pPortCfg = &(pPort->config);
    __wfd_lcd_trace(WFDLCD_____CB__EXEC_ACTIVE_CB);

    if (interruptStatus & WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK)
    {
        void (*cb_func)(WFDEventType, void*) = (void (*)(WFDEventType, void*)) (pPortCfg->updateDoneCallback[CB_FUNC_PTR]);

        __wfd_lcd_StopWatchDog();

        if(WFD_START_DETECT_TE == WFD_TRUE)
        {
            WFD_START_DETECT_TE = WFD_FALSE;
            pPort->needToDetectTE = WFD_FALSE;
        }
        
        kal_set_eg_events(_owf_event, WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK, KAL_OR);
        //kal_set_eg_events(_owf_event, LCD_INT_STATUS_COMPLETE_BIT, KAL_OR);

        if(cb_func != NULL)
            cb_func(WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK, (void*)pPortCfg->updateDoneCallback[CB_PARA]);

       __wfd_lcd_trace(WFDLCD_____CB_________CMP_EVT);
    }

    if (interruptStatus & WFD_LCD_HW_EVENT_VSYNC_MTK)
    {
        
    }

    if (interruptStatus & WFD_LCD_HW_EVENT_TE_SIGNAL_RECEIVED_MTK)
    {
       __wfd_lcd_trace(WFDLCD_____CB__________TE_EVT);    

#if defined(DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT)
        //do Tearing Control...when receive TE signal (=>partial update delay...)
        if ((WFD_PORT_TYPE_INTERNAL == pPortCfg->type) && 
            (WFD_TRUE == pPortCfg->syncEnable) && 
            (lcdTear_IsEnableVsyncIntMask(pPortCfg->id)))
        {
           //Exec tearManager's Vsync_INT callback function
           pPort->portSyncPrimitives.VsyncIntCallback(pPortCfg->id);
        }
#endif //DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT
    }

    if (interruptStatus & WFD_LCD_HW_EVENT_COMMAND_TRANSFER_COMPLETE_MTK)
    {
       kal_set_eg_events(_owf_event, LCD_INT_ENABLE_CMD_COMPLETE_BIT, KAL_OR);
    }    
}


/** DESCRIPTION :
 *    Call this function to wait specific event.\n
 *  @param[in] NA
 *  @return NA
 *  @remark 
 */
WFDboolean
__wfd_lcd_WaitEvent(WFDEventType event_type)
{
    WFDboolean c;
    WFDuint event_group;
    //WFDuint save_irq_mask;
    WFDuint event;
    WFD_DEVICE* pDevice = &_wfd_lcd_device;

    c = (WFDboolean)(IS_LCD_SUPPORTED_EVENT(event_type));
    if (!c)	 ASSERT(0);


    // Convert WFDEventType to HW event definition here...
    if(kal_query_systemInit() == KAL_FALSE)
    {
        //kal_status status = KAL_SUCCESS;
        event = (pDevice->utilityTable._wfd_CnvtEventToHWDef(event_type)); 

        ///Bin: TE error handling here
        kal_retrieve_eg_events(_owf_event, event,
                               KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
    else
    {
        //WFD_PORT_CONFIG* pPortCfg;
        kal_uint32 time1;

        IRQMask(IRQ_LCD_CODE);      
        
        time1 = drv_get_current_time();
        ///TE error handling here
            //read DBI ULTRA HIGH REG to delay 4T for MT6255/56 F2S bus early return potential risk.
     #if defined(MT6255) || defined(MT6256)
   	 DRV_Reg(LCD_DBI_ULTRA_TH_REG);
     #endif
        while(__wfd_lcd_IsWaitHwVsync()) //Zifeng: Cannot use LCD_IS_RUNNIG, because when LCD is waiting for TE, Run bit is 0;
        {
            if(drv_get_duration_ms(time1) > (WFD_LCD_TIMEOUT_INTERVAL * 9 / 2))
            {
               __wfd_lcd_trace(WFDLCD___TIMEOUT_CB________TE);

               {
                   //Zifeng: From Designer, Only disable TE Cannot make LCD stop and LCD will continue to  wait for TE
                   //Only stop -> disable TE -> start can work.
                   STOP_LCD_TRANSFER;
                   DISABLE_LCD_TE_DETECT();

                   if(WFD_START_DETECT_TE == WFD_TRUE)
                   {
                       _wfd_current_processing_port->TEDetectionFail = WFD_TRUE;
					   _wfd_current_processing_port->isTEsyncMode = WFD_FALSE;
                   }
                   START_LCD_TRANSFER;
                   time1 = drv_get_current_time();     ///reset time1
               }
            }
        }
		  //read DBI ULTRA HIGH REG to delay 4T for MT6255/56 F2S bus early return potential risk.
     #if defined(MT6255) || defined(MT6256)
   	 DRV_Reg(LCD_DBI_ULTRA_TH_REG);
     #endif
        while(LCD_IS_RUNNING) ;

        //pPortCfg = &(_wfd_current_processing_port->config); //fix build warning:Warning:  #550-D: variable "pPortCfg" was set but never used   

        //Turn off power before reset busyFlag to avoid race condition.
        STOP_LCD_TRANSFER;
        //Sanity fail of MAUI_03006155, read this register to clear LCD Interrupt.
        DRV_Reg(LCD_INT_STATUS_REG);

		//Serial interface callback for CS control
		#if defined(__SERIAL_LCM__)
		{
		LCD_IF_ENUM current_port_if_cs_number;
		if(WFD_PORT_TYPE_INTERNAL ==_wfd_current_processing_port->config.type)
		{
			if(LCM_IOCTRL_OK == _wfd_current_processing_port->portFuncTable->IOCTRL(LCM_IOCTRL_QUERY_DATA_TRANSFER_COMPLETE_CALLBACK, NULL))
			 {
				 if(LCM_IOCTRL_OK != _wfd_current_processing_port->portFuncTable->IOCTRL(LCM_IOCTRL_QUERY__IF_CS_NUMBER, &current_port_if_cs_number))
					 ASSERT(0);
				 _wfd_current_processing_port->portFuncTable->IOCTRL(LCM_IOCTRL_EXECUTE_DATA_TRANSFER_COMPLETE_CALLBACK,  &current_port_if_cs_number);
			 }
		}
		}
		#endif
        pDevice->utilityTable._wfd_PowerCtrl(pDevice, wfd_lcd_power_ctrl_handle, WFD_FALSE);
        //Clear BusyFlag before exec callback.
        _wfd_lcd_device.busyFlag = WFD_FALSE;

        __wfd_lcd_ExecActiveEventsCb(_wfd_current_processing_port, WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK);		  
        IRQUnmask(IRQ_LCD_CODE);
		  
    }

    return WFD_TRUE;
}



/*!
 *  Get desired interrupt mask setting based on active event callbacks.
 *
 *  \param pCfgCached        Port's cached config structure.\n
 *  \return                  NA\n
 *
 *  \notice                  
 *                           
 */
WFDuint
__wfd_lcd_SetInterruptMask(WFD_DEVICE* device, WFD_PORT_CONFIG* pPortCfg)
{
    //WFDboolean c;
    //WFDint i;
    WFDuint intMask;

    // at lease, DATA_TRANSFER_INT mask shall be enabled.
    // because we need this interrupt isr handler to wakeup caller
    // in __wfd_lcd_WaitEvent(~).
    intMask = WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK;

#if defined(DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT)
    //Tearing Control...
    if ((WFD_PORT_TYPE_INTERNAL == pPortCfg->type) && 
        (WFD_TRUE == pPortCfg->syncEnable) && 
        (lcdTear_IsEnableVsyncIntMask(pPortCfg->id)))
    {
       //we need to enable Vsync Interrupt Mask; register it's callback
       //Zifeng: It should be TE Signal Received Interrupt, not V-sync Interrupt
       //intMask |= (device->utilityTable._wfd_CnvtEventToHWDef(WFD_EVENT_VSYNC_MTK));
       intMask |= (device->utilityTable._wfd_CnvtEventToHWDef(WFD_EVENT_TE_SIGNAL_RECEIVED_MTK));
    }
#endif //DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT

    REG_LCD_INT_ENABLE = intMask;
    IRQUnmask(IRQ_LCD_CODE);
    return intMask; 
}


/** DESCRIPTION :
 *    LCD's LISR Handler\n
 *  @param[in] NA
 *  @return NA
 *  @remark 
 */
static void
__wfd_lcd_Lisr(void)
{
    IRQMask(IRQ_LCD_CODE);
    drv_active_hisr(DRV_LCD_HISR_ID);
    
    #if defined(DDV2_PERFORMANCE_PROFILING_SUPPORT)
    lcd_profiling_lisr_time_tick = drv_get_current_time();
    #endif
    
    return;
}


/** DESCRIPTION :
 *    LCD's HISR Handler\n
 *  @param[in] NA
 *  @return NA
 *  @remark 
 */
static void
__wfd_lcd_Hisr(void)
{
    WFDuint save_irq_mask, interrupt_status, checked_int_status;
    //WFD_PORT_CONFIG* pPortCfg;
    WFD_DEVICE* pDevice = &_wfd_lcd_device;
  #if defined(DDV2_PERFORMANCE_PROFILING_SUPPORT)
    lcd_profiling_hisr_time_tick = drv_get_current_time();
  #endif
       
    // KeTing: Open power here because for a blocking call in ISR or exception, we will close power in __wfd_lcd_WaitEvent
    // KeTing: And when entering this HISR, the power will be off. So we just turn it on again here...
    //pDevice->utilityTable._wfd_PowerCtrl(pDevice, wfd_lcd_power_ctrl_handle, WFD_TRUE);
    // Bin: here we do not need to do interface timing restore

    //Sanity fail of MAUI_03006155, must open power to read INT_STATUS Register to clear LCD Interrupt.
    //lcd_power_ctrl__enable(wfd_lcd_power_ctrl_handle); 

    //Dong: workaround for 35 HW bug, see MAUI_03053277
    //if this is a wrong HISR, read register, shut power, then return.
    #if defined(MT6235) || defined(MT6235B)
    //if((kal_query_systemInit() == KAL_FALSE) && (!INT_QueryExceptionStatus()))
    {
      if(last_callback_done_flag == KAL_TRUE)
      {
        lcd_power_ctrl__enable(wfd_lcd_power_ctrl_handle);
        wrong_hisr_counter++; 
        interrupt_status = DRV_Reg(LCD_INT_STATUS_REG);
        pDevice->utilityTable._wfd_PowerCtrl(pDevice, wfd_lcd_power_ctrl_handle, WFD_FALSE);   
        IRQUnmask(IRQ_LCD_CODE);
        return;
      }
    } 
    #endif

    interrupt_status = DRV_Reg(LCD_INT_STATUS_REG);

    __wfd_lcd_trace(WFDLCD___________________HISR);

    //pPortCfg = &(_wfd_current_processing_port->config);//fix build Warning:  #550-D: variable "pPortCfg" was set but never used
    checked_int_status = interrupt_status & REG_LCD_INT_ENABLE;
    if (WFD_LCD_HW_EVENT_TE_SIGNAL_RECEIVED_MTK & checked_int_status)
    {
        //Yinli: used to calculate hw update time in automode sync to element timer_insertion mechanism   
        if(_IsFullScreenUpdate)
            _HwStartRefreshTime = drv_get_current_time();
      #if defined(DDV2_PERFORMANCE_PROFILING_SUPPORT)
        lcd_profiling_oneFrame_totalTime = drv_get_duration_tick(lcd_profiling_start_update_time, lcd_profiling_lisr_time_tick);
        if(_IsFullScreenUpdate)
        {
            // keep the maxima full screen update TE wait time
            if (_MaxWaitTETime < lcd_profiling_oneFrame_totalTime)
              _MaxWaitTETime = lcd_profiling_oneFrame_totalTime;
        }
      #if (DDV2_CATCHERLOG_LEVEL == 3)
        DDV2CatcherLogL3D1(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_TE_LISRTOHISR_TIME,
                                                 drv_get_duration_tick(lcd_profiling_lisr_time_tick, lcd_profiling_hisr_time_tick));
        DDV2CatcherLogL3D4(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_WAIT_TE_TIME,
                                                 _wfd_current_processing_port->portOutputFormat,    ///port format
                                                 _wfd_current_processing_port->config.roiDestRectangle[RECT_WIDTH],    ///width
                                                 _wfd_current_processing_port->config.roiDestRectangle[RECT_HEIGHT],   ///height
                                                 drv_get_duration_tick(lcd_profiling_start_update_time, lcd_profiling_lisr_time_tick));
      #elif (DDV2_CATCHERLOG_LEVEL == 2)
         DDV2CatcherLogL2D1(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_TE_LISRTOHISR_TIME,
         drv_get_duration_tick(lcd_profiling_lisr_time_tick, lcd_profiling_hisr_time_tick));

		  DDV2CatcherLogL2D4(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_WAIT_TE_TIME,
                                                 _wfd_current_processing_port->portOutputFormat,    ///port format
                                                 _wfd_current_processing_port->config.roiDestRectangle[RECT_WIDTH],    ///width
                                                 _wfd_current_processing_port->config.roiDestRectangle[RECT_HEIGHT],   ///height
                                                 drv_get_duration_tick(lcd_profiling_start_update_time, lcd_profiling_lisr_time_tick));	
      #endif
        lcd_profiling_start_update_time = lcd_profiling_lisr_time_tick;     ///update time for update time measure
        if(lcd_profiling_enable_te_flag == KAL_TRUE)
        {
            lcd_profiling_enable_te_flag = KAL_FALSE;
            REG_LCD_INT_ENABLE &= (~WFD_LCD_HW_EVENT_TE_SIGNAL_RECEIVED_MTK);
            checked_int_status &= (~WFD_LCD_HW_EVENT_TE_SIGNAL_RECEIVED_MTK);
        }
      #endif
      /**
        *  sht:workaroud for HW bug.
        *  \def LCD_TE_INTERRUPT_CLEAR_FRAME_TRANSFER_COMPLETE_INTERRUPT_ISSUE_WORKAROUND
        *  This option is effective for platform:MT6235,MT6236,MT6253,MT6268
        *  This option is defined for HW bug:small ROI update,TE INT and FRAME complete INT arrive very close,
        *  read TE INT will clear FRAME complete INT,so LCD driver will hang for waiting FRAME complete INT.
        *  workaround:when receive TE INT,read lcd status register,if lcd status is idle,means LCD finish this frame trans,
        *  so do TE INT handle and Frame trans complete INT handle in one HISR.
        **/
      #if defined(LCD_TE_INTERRUPT_CLEAR_FRAME_TRANSFER_COMPLETE_INTERRUPT_ISSUE_WORKAROUND)
        //handle LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE case and ROI(0,0) case
        WFDuint roiwidth,roiheight,lcd_status;
        roiwidth = (REG_LCD_ROI_SIZE & 0xFFFF);
        roiheight = ((REG_LCD_ROI_SIZE & 0xFFFF0000)>>16);
        if(0 != roiwidth && 0 != roiheight)
        {
            // be care to  HW delay case
            lcd_status = DRV_Reg(LCD_STA_REG);
            if(lcd_status == 0)
            {
                ///sht:read LCD_INT_STATUS_REG again to clear the INT bit 0(frame trans complete INT bit),
                ///to avoid the case:frame trans complete during DRV_Reg(LCD_INT_STATUS_REG) and lcd_status = DRV_Reg(LCD_STA_REG);  
                checked_int_status |= DRV_Reg(LCD_INT_STATUS_REG);
                checked_int_status |= WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK;	
            }
        }
      #endif
    }

    if (WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK & checked_int_status)
    {
       /**Dong: Workaround for MT6235 HW bug, see MAUI_03053277 **/
       #if defined(MT6235) || defined(MT6235B)
       //if((kal_query_systemInit() == KAL_FALSE) && (!INT_QueryExceptionStatus()))
       {
        last_callback_done_flag = KAL_TRUE;
       } 
       #endif      
       
       //Turn off power before reset busyFlag to avoid race condition.
       STOP_LCD_TRANSFER;
       REG_LCD_INT_ENABLE = 0; //disable all INT mask.		 
       WFD_CATCHLOG_PROFILE_END();
       //__wfd_lcd_StopWatchDog();
       //Yinli: used to calculate hw update time in automode sync to element timer_insertion mechanism   
       if(_IsFullScreenUpdate && _wfd_current_processing_port->config.type == WFD_PORT_TYPE_INTERNAL)
       {
           WFDuint currentTime = drv_get_current_time();
           _wfd_current_processing_port->hwRefreshTime = drv_get_duration_tick(_HwStartRefreshTime,currentTime);
       }
       else
           _wfd_current_processing_port->hwRefreshTime = 0;
     #if defined(DDV2_PERFORMANCE_PROFILING_SUPPORT)
       {
         if((WFD_TRUE == _wfd_current_processing_port->config.syncEnable) && (REG_LCD_TECON & LCD_TE_ENABLE_BIT))
           lcd_profiling_oneFrame_totalTime += drv_get_duration_tick(lcd_profiling_start_update_time, lcd_profiling_lisr_time_tick);
         else
           lcd_profiling_oneFrame_totalTime = drv_get_duration_tick(lcd_profiling_start_update_time, lcd_profiling_lisr_time_tick);
 
         if(_wfd_current_processing_port->config.type != WFD_PORT_TYPE_MEMORY_OUTPUT_MTK)
         {
       #if (DDV2_CATCHERLOG_LEVEL == 3)   
         DDV2CatcherLogL3D2(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_FRAME_FINISH_LISRTOHISR_TIME,
         drv_get_duration_tick(lcd_profiling_lisr_time_tick, lcd_profiling_hisr_time_tick),
                                                  _wfd_current_processing_port->portOutputFormat	///port format	
                                                  );
         DDV2CatcherLogL3D8(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_TOTAL_TIME,
                                                  _wfd_current_processing_port->config.roiDestRectangle[RECT_OFFSETX],	///offsetX	  
                                                  _wfd_current_processing_port->config.roiDestRectangle[RECT_OFFSETY],	///offsetY
                                                  _wfd_current_processing_port->config.roiDestRectangle[RECT_WIDTH], 	///width
                                                  _wfd_current_processing_port->config.roiDestRectangle[RECT_HEIGHT],	///height
                                                  _wfd_current_processing_port->config.syncEnable,						///syncEnable
                                                  drv_get_duration_tick(lcd_profiling_start_update_time, lcd_profiling_lisr_time_tick),
                                                  lcd_profiling_oneFrame_totalTime,
                                                  0
                                                  ); 
       #elif (DDV2_CATCHERLOG_LEVEL == 2)
         
         DDV2CatcherLogL2D2(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_FRAME_FINISH_LISRTOHISR_TIME,
         drv_get_duration_tick(lcd_profiling_lisr_time_tick, lcd_profiling_hisr_time_tick),
                                                  _wfd_current_processing_port->portOutputFormat	///port format	
                                                  );
         DDV2CatcherLogL2D8(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_TOTAL_TIME,
                                                  _wfd_current_processing_port->config.roiDestRectangle[RECT_OFFSETX],	///offsetX	  
                                                  _wfd_current_processing_port->config.roiDestRectangle[RECT_OFFSETY],	///offsetY
                                                  _wfd_current_processing_port->config.roiDestRectangle[RECT_WIDTH], 	///width
                                                  _wfd_current_processing_port->config.roiDestRectangle[RECT_HEIGHT],	///height
                                                  _wfd_current_processing_port->config.syncEnable,						///syncEnable
                                                  drv_get_duration_tick(lcd_profiling_start_update_time, lcd_profiling_lisr_time_tick),
                                                  lcd_profiling_oneFrame_totalTime,
                                                  0
                                                  );
       #endif
         }
         else
         {
           #if (DDV2_CATCHERLOG_LEVEL == 3) 
             DDV2CatcherLogL3D4(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_FLATTEN_TIME,
                                                      _wfd_current_processing_port->config.targetImage->format.pixelFormat,   ///output format
                                                      _wfd_current_processing_port->config.roiDestRectangle[RECT_WIDTH],    ///width
                                                      _wfd_current_processing_port->config.roiDestRectangle[RECT_HEIGHT],   ///height
                                                      drv_get_duration_tick(lcd_profiling_start_flatten_time, lcd_profiling_lisr_time_tick));
           #elif (DDV2_CATCHERLOG_LEVEL == 2)
             DDV2CatcherLogL2D4(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_FLATTEN_TIME,
                                                      _wfd_current_processing_port->config.targetImage->format.pixelFormat,   ///output format
                                                      _wfd_current_processing_port->config.roiDestRectangle[RECT_WIDTH],    ///width
                                                      _wfd_current_processing_port->config.roiDestRectangle[RECT_HEIGHT],   ///height
                                                      drv_get_duration_tick(lcd_profiling_start_flatten_time, lcd_profiling_lisr_time_tick));	
           #endif
         }
   
         lcd_profiling_oneFrame_totalTime = 0;
         lcd_profiling_period_update_frame_count++;
         if(drv_get_duration_tick(lcd_profiling_period_start_time_tick, lcd_profiling_lisr_time_tick) >= lcd_profiling_period_time_tick)
         {
           #if (DDV2_CATCHERLOG_LEVEL == 3)
             DDV2CatcherLogL3D4(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_PERIODICAL_MEASUREMENT,
                                                      lcd_profiling_lisr_time_tick,        ///current time
                                                      drv_get_duration_tick(lcd_profiling_period_start_time_tick, lcd_profiling_lisr_time_tick),    ///duration
                                                      lcd_profiling_period_update_frame_count,   ///update frame count
                                                      lcd_profiling_period_drop_frame_count);    ///drop frame count
           #elif (DDV2_CATCHERLOG_LEVEL == 2)
             DDV2CatcherLogL2D4(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_PERIODICAL_MEASUREMENT,
                                                      lcd_profiling_lisr_time_tick,		  ///current time
                                                      drv_get_duration_tick(lcd_profiling_period_start_time_tick, lcd_profiling_lisr_time_tick),    ///duration
                                                      lcd_profiling_period_update_frame_count,	///update frame count
                                                      lcd_profiling_period_drop_frame_count);	///drop frame count
           #endif

             ///reset the record
             lcd_profiling_period_start_time_tick = lcd_profiling_lisr_time_tick;
             lcd_profiling_period_update_frame_count = 0;
             lcd_profiling_period_drop_frame_count = 0;
         }
       }
     #endif

       //Serial interface callback for CS control
     #if defined(__SERIAL_LCM__)
       {
           LCD_IF_ENUM current_port_if_cs_number;
           if(WFD_PORT_TYPE_INTERNAL ==_wfd_current_processing_port->config.type)
           {
               if(LCM_IOCTRL_OK == _wfd_current_processing_port->portFuncTable->IOCTRL(LCM_IOCTRL_QUERY_DATA_TRANSFER_COMPLETE_CALLBACK, NULL))
               {
                   if(LCM_IOCTRL_OK != _wfd_current_processing_port->portFuncTable->IOCTRL(LCM_IOCTRL_QUERY__IF_CS_NUMBER, &current_port_if_cs_number))
                       ASSERT(0);
                   _wfd_current_processing_port->portFuncTable->IOCTRL(LCM_IOCTRL_EXECUTE_DATA_TRANSFER_COMPLETE_CALLBACK,	&current_port_if_cs_number);
               }
	   }
       }
     #endif
       pDevice->utilityTable._wfd_PowerCtrl(pDevice, wfd_lcd_power_ctrl_handle, WFD_FALSE);
    
       //Clear BusyFlag before exec callback.
       save_irq_mask = SaveAndSetIRQMask();
       _wfd_lcd_device.busyFlag = WFD_FALSE;
       RestoreIRQMask(save_irq_mask);
       
       LCD_Physical_Interface_Unlock();

    }

    __wfd_lcd_ExecActiveEventsCb(_wfd_current_processing_port, checked_int_status);
    IRQUnmask(IRQ_LCD_CODE);
    //__wfd_lcd_trace(WFDLCD_______________HISR_END);
    return;
}


/** DESCRIPTION :
 *    Initialize LCD's Port Config Structure.\n
 *  @param[in] pPortCfg
 *  @param[in] portID
 *  @param[in] pPortFunc: Can be NULL for GOVL. This field is not uesd for GOVL.
 *  @return NA
 *  @remark 
 */
static void 
__wfd_lcd_InitPortConfig(
   WFD_PORT_CONFIG *pPortCfg, WFDint portID, WFDLCDInterfacePara *ifPara)
{
    WFDuint i;
    //Flatten PortConfig

    //specify each port mode's specific feature here
    pPortCfg->id = portID;

    //pPortCfg->partialRefreshSupport = WFD_TRUE;
    //pPortCfg->partialRefreshMaximum[0] = LCD_WIDTH;
    //pPortCfg->partialRefreshMaximum[1] = LCD_HEIGHT;
    //pPortCfg->partialRefreshEnable = WFD_TRUE;
    for (i = 0; i < 4; i++)    { pPortCfg->partialRefreshRectangle[i] = 0; }

    pPortCfg->powerMode = WFD_POWER_MODE_ON;
    pPortCfg->powerModeBackup = WFD_POWER_MODE_ON;
    pPortCfg->syncEnable = WFD_FALSE;
    pPortCfg->syncMode= WFD_SYNC_MODE_NONE_MTK;
    pPortCfg->refreshRate = 30;

    pPortCfg->updateDoneCallback[CB_FUNC_PTR] = NULL;
    if (WFD_FALSE == ifPara->_ifOnScreen)
    {
        pPortCfg->portWidth = WFD_LCD_ROI_MAX_WIDTH;
        pPortCfg->portHeight = WFD_LCD_ROI_MAX_HEIGHT;
        pPortCfg->type = WFD_PORT_TYPE_MEMORY_OUTPUT_MTK;
        pPortCfg->nativeResolution[0] = WFD_LCD_ROI_MAX_WIDTH;
        pPortCfg->nativeResolution[1] = WFD_LCD_ROI_MAX_HEIGHT;
        pPortCfg->ppi = 0;
        return;
    }

    //Blt PortConfig
    {
        //WFDuint i;
        WFDuint temp[2] = {0};

		pPortCfg->tearControlMode = WFD_Tear_Control_MODE_2TE_MTK;
		pPortCfg->portTearFreeRefreshRate = 30;
        if (NULL == ifPara->_ifFuncTable->IOCTRL)
        {
            ASSERT(0);
        }

        //specify each port mode's specific feature here
        pPortCfg->type = WFD_PORT_TYPE_INTERNAL;
        if (LCM_IOCTRL_NOT_SUPPORT == ifPara->_ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__LCM_WIDTH, &(temp[0])))
        {
          if(portID == WFD_SCREEN_LCD_0)
          {
              #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__MAIN_LCM_SCANLINE_ROTATION_90__) || defined(__MAIN_LCM_SCANLINE_ROTATION_270__))
                  temp[0] = LCD_HEIGHT;   
              #else
                  temp[0] = LCD_WIDTH;   
              #endif 
          }
          #ifdef DUAL_LCD
          else  if(portID == WFD_SCREEN_LCD_1) //sub LCD
          {
              #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__SUB_LCM_SCANLINE_ROTATION_90__) || defined(__SUB_LCM_SCANLINE_ROTATION_270__))
                temp[0] = SUBLCD_HEIGHT;   
              #else
                temp[0] = SUBLCD_WIDTH;   
              #endif 
          }
          #endif
        }

        if (LCM_IOCTRL_NOT_SUPPORT == ifPara->_ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__LCM_HEIGHT, &(temp[1])))
        {
            if(portID == WFD_SCREEN_LCD_0)
            {
              #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__MAIN_LCM_SCANLINE_ROTATION_90__) || defined(__MAIN_LCM_SCANLINE_ROTATION_270__))
                    temp[1] = LCD_WIDTH;   
              #else
                    temp[1] = LCD_HEIGHT;   
              #endif 
            }
            #ifdef DUAL_LCD
            else  if(portID == WFD_SCREEN_LCD_1) //sub LCD
            {
              #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__SUB_LCM_SCANLINE_ROTATION_90__) || defined(__SUB_LCM_SCANLINE_ROTATION_270__))
                  temp[1] = SUBLCD_WIDTH;   
              #else
                  temp[1] = SUBLCD_HEIGHT;   
              #endif 
            }
            #endif
        }

        pPortCfg->nativeResolution[0] = temp[0];
        pPortCfg->nativeResolution[1] = temp[1];

      
        // Query LCM refresh rate
        if (LCM_IOCTRL_NOT_SUPPORT == ifPara->_ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__FRAME_RATE, &(temp[0])))
        {
            temp[0] = 75;
        }
        pPortCfg->refreshRate = temp[0];

        // Query LCM ppi
        if (LCM_IOCTRL_NOT_SUPPORT == ifPara->_ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__LCD_PPI, &(temp[0])))
        {
            temp[0] = 0;
        }
        pPortCfg->ppi = temp[0];


        if(portID == WFD_SCREEN_LCD_0)
        {
            #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__MAIN_LCM_SCANLINE_ROTATION_90__) || defined(__MAIN_LCM_SCANLINE_ROTATION_270__))
            pPortCfg->portWidth = LCD_HEIGHT;
            pPortCfg->portHeight = LCD_WIDTH;
            #else
            pPortCfg->portWidth = LCD_WIDTH;
            pPortCfg->portHeight = LCD_HEIGHT;
            #endif 
        }
        #ifdef DUAL_LCD
        else  if(portID == WFD_SCREEN_LCD_1) //sub LCD
        {
            #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__SUB_LCM_SCANLINE_ROTATION_90__) || defined(__SUB_LCM_SCANLINE_ROTATION_270__))
            pPortCfg->portWidth = SUBLCD_HEIGHT;
            pPortCfg->portHeight = SUBLCD_WIDTH;
            #else
            pPortCfg->portWidth = SUBLCD_WIDTH;
            pPortCfg->portHeight = SUBLCD_HEIGHT;
            #endif 
        }
        #endif
    }
}

/** DESCRIPTION :
 *  Initialize Port Structure.\n
 *  @param[in] pPort
 *  @param[in] portID
 *  @param[in] pPortFunc: Can be NULL for GOVL. This field is not uesd for GOVL.
 *  @return NA
 *  @remark 
*/
static void 
__wfd_lcd_InitPort(
    WFD_PORT *pPort, 
    WFDint portID, 
    WFDLCDInterfacePara *ifPara)
{
    //WFDuint i;

    pPort->device = &_wfd_lcd_device;
    pPort->screenNumber = portID;
    
    pPort->portOutputFormat = ifPara->_ifOutFormat;
    pPort->portFuncTable = ifPara->_ifFuncTable;
    pPort->portCmdAddr = ifPara->_ifCmdPort;
    pPort->portDataAddr = ifPara->_ifDataPort;	
    pPort->cmdQueueIdx = ifPara->_ifCmdQueueIdx;

	pPort->hwRefreshTime = 0;
    pPort->TEDetectionFail = WFD_FALSE;   ///only valid for LCM port
    pPort->needToDetectTE = WFD_TRUE;     ///only valid for LCM port, should init to WFD_TRUE to make detect happen when first blt with TE enable
    pPort->isTEsyncMode = WFD_FALSE;	  ///only valid for LCM port, init to WFD_FALSE
}



WFDboolean
__wfd_lcd_PortPowerCtrl(WFD_DEVICE* device, WFD_PORT* port)
{
    if ((NULL == device) || (NULL == port))  { return WFD_FALSE; }

    if (WFD_PORT_TYPE_MEMORY_OUTPUT_MTK == port->config.type)
    {
        return WFD_TRUE;
    }

    if(port->config.powerModeBackup != port->config.powerMode)
    {
        //Handle Power Off LCM
        device->utilityTable._wfd_PowerCtrl(device, wfd_lcd_power_ctrl_handle, WFD_TRUE);
        STOP_LCD_TRANSFER;
        DISABLE_LCD_TE_DETECT();
        DISABLE_LCD_ROI_CTRL_W2MEM;
        LCD_SET_ROI_SIZE(0, 0);
        LCD_SET_ROI_CMD_ADDR(port->portCmdAddr);
        LCD_SET_ROI_DATA_ADDR(port->portDataAddr);

        if (WFD_POWER_MODE_OFF == port->config.powerMode)
        {
            __wfd_lcd_trace(WFDLCD__________LCM_SLEEP__IN);
            port->portFuncTable->EnterSleepMode();
        }
        else
        {
            //Handle Power On LCM
            __wfd_lcd_trace(WFDLCD__________LCM_SLEEP_OUT);
            port->portFuncTable->ExitSleepMode();
        }
        device->utilityTable._wfd_PowerCtrl(device, wfd_lcd_power_ctrl_handle, WFD_FALSE);
        port->config.powerModeBackup = port->config.powerMode;

        //Reset Port config here... to end this request.
        STOP_LCD_TRANSFER;
    }
    return WFD_TRUE;

}


/*!
 *   [LCD Only]
 *
 *  \param 
 *  \return
 *
 *  \notice
 *         
 */
static WFDboolean
__wfd_lcd_ConfigMemOut(WFD_DEVICE* device, WFD_PORT* port)
{
    WFD_PORT_CONFIG* pPortCfg;
    WFD_LCD_WMEM_COLOR_FORMAT_ENUM w2mem_fmt;

    pPortCfg = &(port->config);

    if (WFD_PORT_TYPE_MEMORY_OUTPUT_MTK == pPortCfg->type)
    {
        //Always disable CMD_Transfer for MEMORY_OUT Port.
        //Otherwise HW will hang.
        DISABLE_LCD_ROI_CTRL_CMD_FIRST;
    }
    else
    {
        /// we do not support BLT+FLATTEN here
        ASSERT(0);
    }

    w2mem_fmt = (WFD_LCD_WMEM_COLOR_FORMAT_ENUM)device->utilityTable._wfd_CnvtW2memFormatToHwDef(&pPortCfg->targetImage->format);

    //set W2MEM Ctrl Reg
    {
        LCD_SET_ROI_WMEM_CTRL_CLEAR;

        LCD_SET_ROI_WMEM_CTRL_MEM_ONLY;

        LCD_SET_ROI_WMEM_CTRL_FMT(w2mem_fmt);
        LCD_SET_ROI_WMEM_CTRL_ALPHA(pPortCfg->targetImage->alpha);

        /* some chips can write to mem regardless pitch */
        LCD_SET_ROI_WMEM_CTRL_PITCH_EN;

        SET_LCD_W2MEM_PITCH(pPortCfg->targetImage->stride, pPortCfg->targetImage->pixelSize);
    }

    //set W2MEM offset
    LCD_SET_ROI_WMEM_OFFSET(pPortCfg->partialRefreshRectangle[RECT_OFFSETX],
                                   pPortCfg->partialRefreshRectangle[RECT_OFFSETY]);

    LCD_SET_ROI_WMEM_ADDR_LEGACY((WFDuint)pPortCfg->targetImage->data,
                                        ((pPortCfg->partialRefreshRectangle[RECT_OFFSETY] * pPortCfg->targetImage->stride) + (pPortCfg->partialRefreshRectangle[RECT_OFFSETX] * pPortCfg->targetImage->pixelSize)));
	
	#if defined(__WRITE_THROUGH_CACHEABLE__)	
/* under construction !*/
	#endif

    LCD_SET_ROI_WMEM_ADDR((WFDuint)pPortCfg->targetImage->data);
	return WFD_TRUE;
}


static void
__wfd_lcd_ConfigPerformancePara(WFD_PORT* port, LCD_IOCTRL_DEVICE_IF_T* if_mgr_setting)
{

}


/*!
 *   Handle Blt to LCM/Memory/both. [LCD Only]
 *
 *  \param 
 *  \return
 *
 *  \notice
 *         
 */
 
#if defined(DRV_LCD_SW_MEMORY_OUTPUT_OFFSET_SUPPORT)
#pragma arm section rwdata = "DYNAMICCACHEABLERW_NC", zidata = "DYNAMICCACHEABLEZI_NC"
static __align(4) kal_uint8 wfd_lcd_w2m_temp_buffer[4608] = {0}; //4.5K Temp Buffer
#pragma arm section rwdata, zidata
#endif

#if (defined(__MTK_INTERNAL__)&&defined(__FLAVOR_1632_PLUTO_BW__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static WFDboolean
__wfd_lcd_Blt(WFD_DEVICE* device, WFD_PORT* port, WFDEventType event)
{
    WFD_PORT_CONFIG* pPortCfg;
    //WFDint port_index = port->config.id;
    //WFDboolean status = WFD_TRUE;
    WFDboolean result = WFD_TRUE;
    //kal_uint32 save_irq_mask;

    if ((NULL == device) || (NULL == port))
    {
        result = WFD_FALSE;
        goto exit;
    }

    pPortCfg = &(port->config);

    // Check if port is slept. If port is slept, only flatten is allowed.
    // Drop this blt operation and callback
    if (WFD_POWER_MODE_OFF == port->config.powerMode)
    {  
        if (WFD_PORT_TYPE_MEMORY_OUTPUT_MTK != pPortCfg->type)
        {
            device->busyFlag = WFD_FALSE;
            device->utilityTable._wfd_PowerCtrl(device, wfd_lcd_power_ctrl_handle, WFD_FALSE);
            __wfd_lcd_ExecActiveEventsCb(port, (0x27));
            result = WFD_FALSE;
            LCD_Physical_Interface_Unlock();
            goto exit;
        }
    }
    
     //Dong: workaround for 35 HW bug, see MAUI_03053277
    #if defined(MT6235) || defined(MT6235B)
    //if((kal_query_systemInit() == KAL_FALSE) && (!INT_QueryExceptionStatus()))
    {
      last_callback_done_flag = KAL_FALSE;
    } 
    #endif
    
    __wfd_lcd_trace(WFDLCD____RESET_WFD_LCD_EVENT);
    kal_set_eg_events(_owf_event, ~WFD_LCD_HW_EVENT_HW_ENGIN_ALL, KAL_AND); //reset event.

    //Config HW registers for blt.
    {
        WFDuint i;
        //WFDuint period = 0;
        WFDuint roi_background = 0;

        // Configure HW registers... 
        device->utilityTable._wfd_PowerCtrl(device, wfd_lcd_power_ctrl_handle, WFD_TRUE);

        //period = __wfd_lcd_GetDevicePeriodVal(port);

        LCD_SET_ROI_CTRL_CLEAR;
        LCD_SET_ROI_CTRL_CMD_EN;
        LCD_SET_ROI_CTRL_FMT(port->portOutputFormat);
        LCD_SET_ROI_CTRL_PERIOD(__wfd_lcd_GetDevicePeriodVal(port));
        LCD_SET_ROI_CTRL_FLATTEN_EN((WFD_PORT_TYPE_MEMORY_OUTPUT_MTK == pPortCfg->type));
		
        for (i = 0; i < DRV_LAYER_TOTAL_COUNT; i++)
        {
            if (pPortCfg->bindedPipelines[i])
            {
                LCD_SET_ROI_CTRL_LAYER_EN(i);
            }
        }

        roi_background = CONVERT_TO_LCD_HW_BK_COLOR(pPortCfg->backgroundColor[0], //A
                                                    pPortCfg->backgroundColor[1], //R 
                                                    pPortCfg->backgroundColor[2], //G
                                                    pPortCfg->backgroundColor[3]);//B

        // Moved to above since MMSYS needs to be powered on before setting LCD registers.
        // Configure HW registers...
        //lcd_power_ctrl__enable(wfd_lcd_power_ctrl_handle);
        //__wfd_lcd_RollbackPortIFSetting(port);


#if (defined(__MTK_INTERNAL__)&&defined(__FLAVOR_1632_PLUTO_BW__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        LCD_SET_ROI_OFFSET((pPortCfg->roiDestRectangle[RECT_OFFSETX] + WFD_LCD_ROI_ORIGIN_X),
                           (pPortCfg->roiDestRectangle[RECT_OFFSETY] + WFD_LCD_ROI_ORIGIN_Y));
        LCD_SET_ROI_SIZE((pPortCfg->roiDestRectangle[RECT_WIDTH]),
                         (pPortCfg->roiDestRectangle[RECT_HEIGHT]));
        LCD_SET_ROI_BG_COLOR(roi_background);
        LCD_SET_ROI_CMD_ADDR(port->portCmdAddr);
        LCD_SET_ROI_DATA_ADDR(port->portDataAddr);
    }

#if defined(__DRV_COLOR_HW_SUPPORT__)
    // config mm_color
    colorUpdateConfig(COLOR_PATH_LCD, LCD_GET_ROI_WIDTH);
#endif

    //Config MemOut
    {      
        if (WFD_PORT_TYPE_MEMORY_OUTPUT_MTK == pPortCfg->type)
        {
            //Call this function after seeting ROI register
            device->utilityTable._wfd_ConfigMemOut(device, port);
        }
    }

    //Handle INT Mask Here.....	
    {
        __wfd_lcd_SetInterruptMask(device, pPortCfg);
    }

    //performance config registers information
    {
       device->utilityTable._wfd_ConfigPerformancePara(port, &_lcd_if_mgr_port_setting[port->config.id]);
    }

    //If layer doesn't have intersection with ROI, will disable this layer.
    {
    	WFDuint i = 0;		
        for (i = 0; i < DRV_LAYER_TOTAL_COUNT; i++)
        {
            if (pPortCfg->bindedPipelines[i]) //if this pipeline is enabled?
            {
                kal_int32 wfd_fr_layer_start_x, wfd_fr_layer_end_x, wfd_fr_layer_start_y, wfd_fr_layer_end_y,wfd_fr_layer_rotate_angle;
                kal_int32 wfd_roi_start_x, wfd_roi_end_x, wfd_roi_start_y, wfd_roi_end_y;

				wfd_fr_layer_rotate_angle = GET_LCD_LAYER_CTRL_ROTATE(i);
	               if ( (WFD_LCD_LAYER_ROTATE_90 == wfd_fr_layer_rotate_angle) ||
	                	 (WFD_LCD_LAYER_ROTATE_270 == wfd_fr_layer_rotate_angle) ||
	                	 (WFD_LCD_LAYER_FLIP_ROTATE_90 == wfd_fr_layer_rotate_angle) ||
	                	 (WFD_LCD_LAYER_FLIP_ROTATE_270 == wfd_fr_layer_rotate_angle) ||
	                	 (KAL_FALSE)
	                   )
	                {
	                    _wfd_lcd_pipeline[i].config.destinationRectangle[2] = GET_LCD_LAYER_WINDOW_HEIGHT(i);
	                    _wfd_lcd_pipeline[i].config.destinationRectangle[3] = GET_LCD_LAYER_WINDOW_WIDTH(i);
	                }
	                else
	                {
	                    _wfd_lcd_pipeline[i].config.destinationRectangle[2] = GET_LCD_LAYER_WINDOW_WIDTH(i);
	                    _wfd_lcd_pipeline[i].config.destinationRectangle[3] = GET_LCD_LAYER_WINDOW_HEIGHT(i);
	                }
	                wfd_fr_layer_start_x = GET_LCD_LAYER_WINDOW_OFFSET_X(i) - WFD_LCD_ROI_ORIGIN_X;
	                wfd_fr_layer_end_x = wfd_fr_layer_start_x + _wfd_lcd_pipeline[i].config.destinationRectangle[2];
	                wfd_fr_layer_start_y = GET_LCD_LAYER_WINDOW_OFFSET_Y(i) - WFD_LCD_ROI_ORIGIN_Y;
	                wfd_fr_layer_end_y = wfd_fr_layer_start_y + _wfd_lcd_pipeline[i].config.destinationRectangle[3];
                        
                wfd_roi_start_x = pPortCfg->roiDestRectangle[0];
                wfd_roi_end_x = wfd_roi_start_x + pPortCfg->roiDestRectangle[2];
                wfd_roi_start_y = pPortCfg->roiDestRectangle[1];
                wfd_roi_end_y = wfd_roi_start_y + pPortCfg->roiDestRectangle[3];
                        
                if ( (wfd_fr_layer_end_x < wfd_roi_start_x) ||
                     (wfd_fr_layer_end_y < wfd_roi_start_y) ||
                     (wfd_fr_layer_start_x > wfd_roi_end_x) ||
                     (wfd_fr_layer_start_y > wfd_roi_end_y) ||
                     (KAL_FALSE)
                   )
                {
                    pPortCfg->bindedPipelines[i] = WFD_FALSE;
                    REG_LCD_ROI_CTRL    &= ~(LCD_LAYER_ENABLE_BIT(i));
					#if (DDV2_CATCHERLOG_LEVEL == 3)
			          DDV2CatcherLogL3D8(TRACE_DDV2_PROFILING, LCD_TRC_DISABLE_LAYER_INFO,
																 i,          ///layer ID.
					                                             _wfd_lcd_pipeline[i].config.destinationRectangle[RECT_OFFSETX],
								  								 _wfd_lcd_pipeline[i].config.destinationRectangle[RECT_OFFSETY],
					                                             _wfd_lcd_pipeline[i].config.sourceRectangle[RECT_WIDTH],
					                                             _wfd_lcd_pipeline[i].config.sourceRectangle[RECT_HEIGHT],0,0,0);
					#elif (DDV2_CATCHERLOG_LEVEL == 2)
					  DDV2CatcherLogL2D8(TRACE_DDV2_PROFILING, LCD_TRC_DISABLE_LAYER_INFO,
																 i,          ///layer ID.
					                                             _wfd_lcd_pipeline[i].config.destinationRectangle[RECT_OFFSETX],
								  								 _wfd_lcd_pipeline[i].config.destinationRectangle[RECT_OFFSETY],
					                                             _wfd_lcd_pipeline[i].config.sourceRectangle[RECT_WIDTH],
					                                             _wfd_lcd_pipeline[i].config.sourceRectangle[RECT_HEIGHT],0,0,0);
					#endif
                }                
            }
        }
    }

    {
       #if defined(DDV2_PERFORMANCE_PROFILING_SUPPORT)
       kal_uint32 ii;
       
       if((WFD_PORT_TYPE_INTERNAL == pPortCfg->type) &&
          (_lcd_if_mgr_port_setting[port->config.id].if_type == LCD_IF_TYPE_DBI_PARALLEL))
       {
         #if (DDV2_CATCHERLOG_LEVEL == 3)
           DDV2CatcherLogL3D8(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_SYS_INFO,
                                                    _wfd_current_processing_port->screenNumber, ///scrren ID
                                                    _wfd_current_processing_port->config.nativeResolution[0],   ///LCM physical width and height
                                                    _wfd_current_processing_port->config.nativeResolution[1],
                                                    _wfd_current_processing_port->portOutputFormat,          ///port format
                                                    _lcd_if_mgr_port_setting[port->config.id].if_settings.dbi_parallel_if.if_c2ws,
                                                    _lcd_if_mgr_port_setting[port->config.id].if_settings.dbi_parallel_if.if_c2wh,
                                                    _lcd_if_mgr_port_setting[port->config.id].if_settings.dbi_parallel_if.if_wst,
                                                    _lcd_if_mgr_port_setting[port->config.id].if_settings.dbi_parallel_if.if_period
                                                    );
		 #elif (DDV2_CATCHERLOG_LEVEL == 2)
		   DDV2CatcherLogL2D8(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_SYS_INFO,
												  _wfd_current_processing_port->screenNumber, ///scrren ID
												  _wfd_current_processing_port->config.nativeResolution[0],   ///LCM physical width and height
												  _wfd_current_processing_port->config.nativeResolution[1],
												  _wfd_current_processing_port->portOutputFormat,		   ///port format
												  _lcd_if_mgr_port_setting[port->config.id].if_settings.dbi_parallel_if.if_c2ws,
												  _lcd_if_mgr_port_setting[port->config.id].if_settings.dbi_parallel_if.if_c2wh,
												  _lcd_if_mgr_port_setting[port->config.id].if_settings.dbi_parallel_if.if_wst,
												  _lcd_if_mgr_port_setting[port->config.id].if_settings.dbi_parallel_if.if_period
												  );
		 #endif
       }
       else
       {
            ///TODO: serial LCM
       }


       for (ii = 0; ii < DRV_LAYER_TOTAL_COUNT; ii++)
       {
           if (pPortCfg->bindedPipelines[ii])
           {
             #if (DDV2_CATCHERLOG_LEVEL == 3)
               DDV2CatcherLogL3D8(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_LAYER_INFO_0,
			                                            ii,          ///layer ID.
			                                            _wfd_lcd_pipeline[ii].config.destinationRectangle[RECT_OFFSETX],
						  								_wfd_lcd_pipeline[ii].config.destinationRectangle[RECT_OFFSETY],
			                                            _wfd_lcd_pipeline[ii].config.sourceRectangle[RECT_WIDTH],
			                                            _wfd_lcd_pipeline[ii].config.sourceRectangle[RECT_HEIGHT],0,0,0);
														
               DDV2CatcherLogL3D8(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_LAYER_INFO_1,
                                                        ii,          ///layer ID.
                                                        _wfd_lcd_pipeline[ii].config.image_source->format.pixelFormat,
                                                        _wfd_lcd_pipeline[ii].config.flip,
                                                        _wfd_lcd_pipeline[ii].config.rotation,
                                                        _wfd_lcd_pipeline[ii].config.ditherEnable,
                                                        _wfd_lcd_pipeline[ii].config.transparencyEnable,
                                                        _wfd_lcd_pipeline[ii].config.globalAlpha,0);

			 #elif (DDV2_CATCHERLOG_LEVEL == 2)
			   DDV2CatcherLogL2D8(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_LAYER_INFO_0,
													  ii,		   ///layer ID.
													  _wfd_lcd_pipeline[ii].config.destinationRectangle[RECT_OFFSETX],
													  _wfd_lcd_pipeline[ii].config.destinationRectangle[RECT_OFFSETY],
													  _wfd_lcd_pipeline[ii].config.sourceRectangle[RECT_WIDTH],
													  _wfd_lcd_pipeline[ii].config.sourceRectangle[RECT_HEIGHT],0,0,0);
													  
			   DDV2CatcherLogL2D8(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_LAYER_INFO_1,
													  ii,		   ///layer ID.
													  _wfd_lcd_pipeline[ii].config.image_source->format.pixelFormat,
													  _wfd_lcd_pipeline[ii].config.flip,
													  _wfd_lcd_pipeline[ii].config.rotation,
													  _wfd_lcd_pipeline[ii].config.ditherEnable,
													  _wfd_lcd_pipeline[ii].config.transparencyEnable,
													  _wfd_lcd_pipeline[ii].config.globalAlpha,0);
			 #endif
           }
       }
       #endif
    }

    //Handle BlockWrite
    {

        ENABLE_LCD_SERIAL_IF_CS(1,0);
        WFD_CATCHLOG_PROFILE_START();
        if (WFD_PORT_TYPE_INTERNAL == pPortCfg->type)
        {
            __wfd_lcd_trace(WFDLCD______________BEING_BLT);
			//Yinli: used to calculate hw update time in automode sync to element timer_insertion mechanism
			//Yinli: use full screen update time to evaluate HW refresh time
			_IsFullScreenUpdate = WFD_FALSE;
			if(LCD_WIDTH == _wfd_current_processing_port->config.roiDestRectangle[RECT_WIDTH]
			&& LCD_HEIGHT == _wfd_current_processing_port->config.roiDestRectangle[RECT_HEIGHT])
			{
				_IsFullScreenUpdate = WFD_TRUE;
				_HwStartRefreshTime = drv_get_current_time();
			}
            #if defined(DDV2_PERFORMANCE_PROFILING_SUPPORT)
            lcd_profiling_start_update_time = drv_get_current_time();
            ///only when TE enable case, we need to log TE interrupt time
            lcd_profiling_enable_te_flag = KAL_FALSE;
            if((WFD_TRUE == pPortCfg->syncEnable) && (REG_LCD_TECON & LCD_TE_ENABLE_BIT))
            {
                //enable  TE interrupt here,  this should not be used when VSYNC_SW_DELAY
                if((REG_LCD_INT_ENABLE & WFD_LCD_HW_EVENT_TE_SIGNAL_RECEIVED_MTK) == 0)
                {
                    REG_LCD_INT_ENABLE |= WFD_LCD_HW_EVENT_TE_SIGNAL_RECEIVED_MTK;
                    lcd_profiling_enable_te_flag = KAL_TRUE;
                }
            }
            #endif

#if (defined(__MTK_INTERNAL__)&&defined(__FLAVOR_1632_PLUTO_BW__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            port->portFuncTable->BlockWrite(
               pPortCfg->partialRefreshRectangle[RECT_OFFSETX],
               pPortCfg->partialRefreshRectangle[RECT_OFFSETY],
               pPortCfg->partialRefreshRectangle[RECT_OFFSETX] + pPortCfg->partialRefreshRectangle[RECT_WIDTH] - 1,
               pPortCfg->partialRefreshRectangle[RECT_OFFSETY] + pPortCfg->partialRefreshRectangle[RECT_HEIGHT] - 1);

        }
        else
        {
#if defined(DRV_LCD_SW_MEMORY_OUTPUT_OFFSET_SUPPORT)
             WFDuint wroi_w2madd = (WFDuint)(REG_LCD_ROI_WMEM_ADDR);
#endif
            __wfd_lcd_trace(WFDLCD______________BEING_FLT);
            #if defined(DDV2_PERFORMANCE_PROFILING_SUPPORT)
            lcd_profiling_start_flatten_time = drv_get_current_time();
            #endif
#if !defined(DRV_LCD_SW_MEMORY_OUTPUT_OFFSET_SUPPORT)
            WFD_START_LCD_TRANSFER;
#else
            if ((wroi_w2madd & 0x3) == 0)
            {
                WFD_START_LCD_TRANSFER;
            }
            else
            {
                WFDint bpp = pPortCfg->targetImage->pixelSize;
                WFDuint sw_update_pixel = 1;
                kal_uint8 *src_ptr, *des_ptr;
                kal_uint32 i,j;
                //Backup Registers
                WFDuint lcd_inten = REG_LCD_INT_ENABLE;
                WFDuint wroi_w2mcon = REG_LCD_ROI_WMEM_CTRL;

                //Re-config to cont. mode
                REG_LCD_INT_ENABLE = 0; // disable interrupt
                REG_LCD_ROI_WMEM_CTRL &= ~LCD_ROI_WMEM_CONT_BIT; // Use cont. W2M mode
                REG_LCD_ROI_WMEM_ADDR = (WFDuint)(&wfd_lcd_w2m_temp_buffer[0]); // Temp buffer
                if (2 == bpp) // sw_update_pixel = 1
                {
                    
                }
                else if (3 == bpp)
                {
                    sw_update_pixel = (((pPortCfg->partialRefreshRectangle[RECT_OFFSETY] * pPortCfg->targetImage->stride) + (pPortCfg->partialRefreshRectangle[RECT_OFFSETX] * pPortCfg->targetImage->pixelSize)) % 12)/3;
                }
                else
                {
                    ASSERT(0);
                }
                if (sw_update_pixel > (pPortCfg->roiDestRectangle[RECT_WIDTH]))
                {
                    sw_update_pixel = (pPortCfg->roiDestRectangle[RECT_WIDTH]);
                }
                LCD_SET_ROI_SIZE((sw_update_pixel),
                                 (pPortCfg->roiDestRectangle[RECT_HEIGHT]));
                WFD_START_LCD_TRANSFER;
                for(i=0; i<100; i++) {}
				//read DBI ULTRA HIGH REG to delay 4T for MT6255/56 F2S bus early return potential risk.
     			#if defined(MT6255) || defined(MT6256)
   	 				DRV_Reg(LCD_DBI_ULTRA_TH_REG);
    			#endif
                while(LCD_IS_RUNNING) {}
                STOP_LCD_TRANSFER;
                DRV_Reg(LCD_INT_STATUS_REG);

                //Memory Copy
                src_ptr = (kal_uint8 *)(&wfd_lcd_w2m_temp_buffer[0]);
                des_ptr = (kal_uint8 *)wroi_w2madd;
                for(i = (pPortCfg->roiDestRectangle[RECT_HEIGHT]); i > 0; i--)
                {
                    for(j = (sw_update_pixel*bpp); j > 0; j--)
                    {
                        *des_ptr = *src_ptr;
                        src_ptr++;
                        des_ptr++;
                    }
                    des_ptr += (pPortCfg->targetImage->stride - (sw_update_pixel*bpp));
                }
                
                //if roi_width equals to 0, HW behavior will be abnormal
                if (sw_update_pixel == pPortCfg->roiDestRectangle[RECT_WIDTH])
                {

                    device->busyFlag = WFD_FALSE;
                    device->utilityTable._wfd_PowerCtrl(device, wfd_lcd_power_ctrl_handle, WFD_FALSE);
                    __wfd_lcd_ExecActiveEventsCb(port, (0x27));
                    LCD_Physical_Interface_Unlock();
                    goto exit;
                } 
                else
                { 
                    //Re-config to previous mode
                    LCD_SET_ROI_SIZE(((pPortCfg->roiDestRectangle[RECT_WIDTH]) - sw_update_pixel),
                                    (pPortCfg->roiDestRectangle[RECT_HEIGHT]));
                    LCD_SET_ROI_OFFSET((pPortCfg->roiDestRectangle[RECT_OFFSETX] + WFD_LCD_ROI_ORIGIN_X + sw_update_pixel),
                                       (pPortCfg->roiDestRectangle[RECT_OFFSETY] + WFD_LCD_ROI_ORIGIN_Y));
                    REG_LCD_INT_ENABLE = lcd_inten; // interrupt
                    REG_LCD_ROI_WMEM_CTRL = wroi_w2mcon; // Use block W2M mode
                    REG_LCD_ROI_WMEM_ADDR = wroi_w2madd + sw_update_pixel*bpp; // buffer
                    WFD_START_LCD_TRANSFER;
                } 
            }
#endif //#if !defined(DRV_LCD_SW_MEMORY_OUTPUT_OFFSET_SUPPORT)
        }

        pPortCfg->doBlt = WFD_FALSE;
    }

    if (WFD_TRUE == pPortCfg->blockModeReq)
    {
        __wfd_lcd_WaitEvent(event);      
    }

exit:
    return result;
}



static WFDboolean
__wfd_lcd_ConfigDitherCtrl(void)
{
    kal_uint32 dither_bit_r, dither_bit_g, dither_bit_b;
    kal_uint32 lcd_to_lcm_fmt;

    lcd_to_lcm_fmt = (GET_LCD_ROI_CTRL_OUTPUT_FORMAT & 0x38) >> 3;

    // Currently ROI color format in HW LCD register are at the same location.
    switch (lcd_to_lcm_fmt)
    {

        case 2: // RGB888 -> RGB565
            dither_bit_r = 2;
            dither_bit_g = 1;
            dither_bit_b = 2;
            break;
        case 3: // RGB888 -> RGB666
        default:
            dither_bit_r = 1;
            dither_bit_g = 1;
            dither_bit_b = 1;
            break;
    }

    SET_LCD_DITHER_BIT(dither_bit_r, dither_bit_g, dither_bit_b);
    SET_LCD_DITHER_SEED(1, 1, 1);

    return WFD_TRUE;
}



static WFDboolean
__wfd_lcd_PipelineCommit(WFD_DEVICE* device, WFD_PIPELINE* pipeline)
{
    WFD_PIPELINE *cap_pPipeline;
    WFDint id = pipeline->config.id;
  #if defined(__MTK_INTERNAL__)&&defined(__FLAVOR_1632_PLUTO_BW__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
  #endif

    if ((NULL == device) || (NULL == pipeline))  { return WFD_FALSE; }

    id = pipeline->config.id;
    cap_pPipeline = &_wfd_lcd_pipeline[id];

    //configure pipeline setting to HW
    {
        WFD_PIPELINE_CONFIG*  config = &(cap_pPipeline->config);
        WFDuint angle;

        // Move to the front since MMSYS must be enabled before setting LCD registers.
        device->utilityTable._wfd_PowerCtrl(device, wfd_lcd_power_ctrl_handle, WFD_TRUE);

        ///Bin: clear all this layer setting
        LCD_CLEAR_LAYER_REG(id);

        //Bin: can not remove now!!!!  until LCD_CLEAR_LAYER_REG(id) is implemented for all platforms
        LCD_SET_LAYER_CTRL_CLEAR(id);
        
        if (config->transparencyEnable & WFD_TRANSPARENCY_SOURCE_COLOR)
        {
            LCD_SET_LAYER_CTRL_SOURCE_KEY_EN(id);
        }

        if (config->transparencyEnable & WFD_TRANSPARENCY_GLOBAL_ALPHA)
        {
            LCD_SET_LAYER_CTRL_OPACITY_EN(id);
        }

        if (config->transparencyEnable & WFD_TRANSPARENCY_SOURCE_ALPHA)
        {
            LCD_SET_LAYER_CTRL_OPACITY_EN(id);
            if ((OWF_IMAGE_ARGB8888 != config->image_source->format.pixelFormat) || (OWF_IMAGE_ARGB6666 != config->image_source->format.pixelFormat))
            {
                ASSERT(0);
            }
        }

        if (config->transparencyEnable & WFD_TRANSPARENCY_GLOBAL_ALPHA)
        {
            LCD_SET_LAYER_CTRL_OPACITY(id, config->globalAlpha);
        }
        else if (config->transparencyEnable & WFD_TRANSPARENCY_SOURCE_ALPHA)
        {
            LCD_SET_LAYER_CTRL_OPACITY(id, 0xFF);
        }        

        //Rotation Angle
        {
            angle = device->utilityTable._wfd_CnvtAngleToHwDef(device, config->rotation, config->flip);
            LCD_SET_LAYER_CTRL_ROTATE(id, angle);
        }

        // Byte Swap Enable?
        if (config->swapEnable)
        {
            LCD_SET_LAYER_CTRL_DATA_SWAP_EN(id);
        }

        //Dither Enable?
        if (config->ditherEnable)
        {
            LCD_SET_LAYER_CTRL_DITHER_EN(id);
            __wfd_lcd_ConfigDitherCtrl();
        }
		//3D mode Enable?
		#ifdef DRV_LCD_3D_MODE_SUPPORT
		if (WFD_TRUE == config->_3DEnable)
		{	WFDuint temp;
			LCD_SET_LAYER_CTRL_3D_EN(id);
			if(WFD_TRUE == config->_3DPortraitMode)
				temp =0;
			else
				temp =1;
			LCD_SET_LAYER_CTRL_3D_MODE(id,temp);
			if(WFD_TRUE == config->_3DLeftEyeFirst)
				temp =0;
			else
				temp =1;
			LCD_SET_LAYER_CTRL_3D_FIRST_EYE(id,temp);
		}
		#endif
        //Color Format
        {
            WFD_LCD_LAYER_SOURCE_COLOR_FORMAT_ENUM color_format;
            color_format = (WFD_LCD_LAYER_SOURCE_COLOR_FORMAT_ENUM)device->utilityTable._wfd_CnvtImgFormatToHwDef(&config->image_source->format);

            if (WFD_LCD_LAYER_FORMAT_RSD == color_format)	
            {
                //continue to finish this request?
                //or return?
            }
            else if (WFD_LCD_LAYER_FORMAT_8BPP_INDEX == color_format)
            {
                #if defined(MT6252) || defined(MT6252H)
                SET_LUT0_PALETTE_BUFF_ADDRESS((_wfd_current_processing_port->config.paletteTable));
                #endif
            }
            
            LCD_SET_LAYER_CTRL_FMT(id, color_format);
        }

        // Move to the front since MMSYS must be enabled before setting LCD registers.
        //lcd_power_ctrl__enable(wfd_lcd_power_ctrl_handle);
        //__wfd_lcd_RollbackPortIFSetting((WFD_PORT*)config->portId);
        //__wfd_lcd_trace(WFDLCD__PIPELINE______COMMMIT);		  

        LCD_SET_LAYER_COLOR_KEY(id, config->transparencyColor);
        
#if (defined(__MTK_INTERNAL__)&&defined(__FLAVOR_1632_PLUTO_BW__))
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
        
        LCD_SET_LAYER_BUFF_ADDR(id, (WFDuint)(config->image_source->data));
        

#ifndef DRV_LAYER_PITCH_NOT_SUPPORT
        //roi offset x, y
        LCD_SET_LAYER_OFFSET(id,
                             (config->destinationRectangle[RECT_OFFSETX] + WFD_LCD_ROI_ORIGIN_X),
                             (config->destinationRectangle[RECT_OFFSETY] + WFD_LCD_ROI_ORIGIN_Y));

        //layer size x, y
        LCD_SET_LAYER_SIZE(id, 
                           config->sourceRectangle[RECT_WIDTH],//config->destinationRectangle[RECT_WIDTH],
                           config->sourceRectangle[RECT_HEIGHT]);//config->destinationRectangle[RECT_HEIGHT]);
        
        //memory offset x, y
        LCD_SET_LAYER_MEM_OFFSET(id, config->sourceRectangle[RECT_OFFSETX], config->sourceRectangle[RECT_OFFSETY]);/*
                                 config->sourceRectangle[RECT_OFFSETX],
                                 config->sourceRectangle[RECT_OFFSETY]);*/

        SET_LCD_LAYER_MEM_PITCH(id, (config->image_source->stride), (config->image_source->pixelSize));         
#else //#ifndef DRV_LAYER_PITCH_NOT_SUPPORT
{
        WFDint layer_offset_x, layer_offset_y;
        WFDint layer_size_width, layer_size_height;
        
        layer_size_width = config->image_source->width;
        layer_size_height = config->image_source->height;
        if (WFD_LCD_LAYER_ROTATE_NORMAL == angle)
        {
            layer_offset_x = config->destinationRectangle[RECT_OFFSETX] - config->sourceRectangle[RECT_OFFSETX];
            layer_offset_y = config->destinationRectangle[RECT_OFFSETY] - config->sourceRectangle[RECT_OFFSETY];
        }
        else if (WFD_LCD_LAYER_ROTATE_270 == angle)
        {
            layer_offset_x = config->destinationRectangle[RECT_OFFSETX] + config->sourceRectangle[RECT_OFFSETY]
                             + config->sourceRectangle[RECT_HEIGHT] - layer_size_height;
            layer_offset_y = config->destinationRectangle[RECT_OFFSETY] - config->sourceRectangle[RECT_OFFSETX];
        }
        else if (WFD_LCD_LAYER_ROTATE_180 == angle)
        {
            layer_offset_x = config->destinationRectangle[RECT_OFFSETX] + config->sourceRectangle[RECT_OFFSETX]
                             + config->sourceRectangle[RECT_WIDTH] - layer_size_width;
            layer_offset_y = config->destinationRectangle[RECT_OFFSETY] + config->sourceRectangle[RECT_OFFSETY]
                             + config->sourceRectangle[RECT_HEIGHT] - layer_size_height;
        }
        else if (WFD_LCD_LAYER_ROTATE_90 == angle)
        {
            layer_offset_x = config->destinationRectangle[RECT_OFFSETX] - config->sourceRectangle[RECT_OFFSETY];
            layer_offset_y = config->destinationRectangle[RECT_OFFSETY] + config->sourceRectangle[RECT_OFFSETX]
                             + config->sourceRectangle[RECT_WIDTH] - layer_size_width;
        }
        else if (WFD_LCD_LAYER_FLIP == angle)
        {
            layer_offset_x = config->destinationRectangle[RECT_OFFSETX] + config->sourceRectangle[RECT_OFFSETX]
                             + config->sourceRectangle[RECT_WIDTH] - layer_size_width;
            layer_offset_y = config->destinationRectangle[RECT_OFFSETY] - config->sourceRectangle[RECT_OFFSETY];
        }
        else if (WFD_LCD_LAYER_FLIP_ROTATE_90 == angle)
        {
            layer_offset_x = config->destinationRectangle[RECT_OFFSETX] - config->sourceRectangle[RECT_OFFSETY];
            layer_offset_y = config->destinationRectangle[RECT_OFFSETY] - config->sourceRectangle[RECT_OFFSETX];
        }
        else if (WFD_LCD_LAYER_FLIP_ROTATE_180 == angle)
        {
            layer_offset_x = config->destinationRectangle[RECT_OFFSETX] - config->sourceRectangle[RECT_OFFSETX];
            layer_offset_y = config->destinationRectangle[RECT_OFFSETY] + config->sourceRectangle[RECT_OFFSETY]
                             + config->sourceRectangle[RECT_HEIGHT] - layer_size_height;
        }
        else// if (WFD_LCD_LAYER_FLIP_ROTATE_270 == angle)
        {
            layer_offset_x = config->destinationRectangle[RECT_OFFSETX] + config->sourceRectangle[RECT_OFFSETY]
                             + config->sourceRectangle[RECT_HEIGHT] - layer_size_height;
            layer_offset_y = config->destinationRectangle[RECT_OFFSETY] + config->sourceRectangle[RECT_OFFSETX]
                             + config->sourceRectangle[RECT_WIDTH] - layer_size_width;
        }
        //roi offset x, y
        LCD_SET_LAYER_OFFSET(id,
                             (layer_offset_x + WFD_LCD_ROI_ORIGIN_X),
                             (layer_offset_y + WFD_LCD_ROI_ORIGIN_Y));

        //layer size x, y
        LCD_SET_LAYER_SIZE(id, 
                           layer_size_width,
                           layer_size_height);
        
        //memory offset x, y
        LCD_SET_LAYER_MEM_OFFSET(id, 0, 0);/*
                                 config->sourceRectangle[RECT_OFFSETX],
                                 config->sourceRectangle[RECT_OFFSETY]);*/

        SET_LCD_LAYER_MEM_PITCH(id, 0, 0);
}
#endif //#ifndef DRV_LAYER_PITCH_NOT_SUPPORT
    }
	return WFD_TRUE;
}


static WFDboolean
__wfd_lcd_FastRotatorMemEnable(WFDboolean enable)
{
    return WFD_TRUE;
}



static void
_wfd_lcd_init_internal(void)
{
    // Init port for each LCM and memory out.
    {
        WFDuint i;

        for (i = 0; i < WFD_ATTACHED_PORT_COUNT; i++)
        {		 
            //  Init port
            __wfd_lcd_InitPort(&_wfd_lcd_port[WFD_SCREEN_LCD_0+i],
                               WFD_SCREEN_LCD_0+i, &_wfd_lcd_if_para[i]);
        
            // Init port config
            __wfd_lcd_InitPortConfig(&_wfd_lcd_port[WFD_SCREEN_LCD_0+i].config,
                                     WFD_SCREEN_LCD_0+i, &_wfd_lcd_if_para[i]);
        }
    }

    // Init pipelines.
    {
        kal_uint32 i;

        _wfd_lcd_pipeline[0].config.maxSourceSize[0] = WFD_LCD_LAYER_MAX_WIDTH;
        _wfd_lcd_pipeline[0].config.maxSourceSize[1] = WFD_LCD_LAYER_MAX_HEIGHT;

        for (i = 1; i < DRV_LAYER_TOTAL_COUNT; i++)
        {
            kal_mem_cpy((void*) &_wfd_lcd_pipeline[i].config,
                        (void*) &_wfd_lcd_pipeline[0].config,
                        sizeof(WFD_PIPELINE_CONFIG));

            _wfd_lcd_pipeline[i].config.id = i;
        }

        for (i = 0; i < DRV_LAYER_TOTAL_COUNT; i++)
        {
            _wfd_lcd_pipeline[i].device = &_wfd_lcd_device;
        }
    }

}



static WFDDevice
_wfd_lcd_CreateDevice(WFDint deviceId, const WFDint *attribList)
{
    // TODO: parameter checking...
    _wfd_lcd_device.inUse = &_wfd_lcd_device;
    _wfd_lcd_device.id = deviceId;
    return (WFDDevice) &_wfd_lcd_device;
}



static WFDErrorCode
_wfd_lcd_DestroyDevice(WFDDevice device)
{
    CHECK_DEVICE(device, WFD_ERROR_BAD_DEVICE, WFD_ERROR_BAD_DEVICE);

    // TODO: check if LCD is still busy...
    while (_wfd_lcd_device.busyFlag == WFD_TRUE)
    {
       kal_sleep_task(1);
    }

    _wfd_lcd_device.inUse = WFD_INVALID_HANDLE;

    return WFD_ERROR_NONE;
}


static void
_wfd_lcd_DeviceCommit(WFDDevice device, WFDCommitType type, WFDHandle handle)
{
    WFD_DEVICE* pDevice;
    WFD_PORT* pPort;

    CHECK_DEVICE_NR(device, WFD_ERROR_BAD_DEVICE);
    CHECK_HANDLE_NR(device, handle, WFD_ERROR_BAD_HANDLE);

    pDevice = &_wfd_lcd_device;
    ASSERT(pDevice->busyFlag == WFD_FALSE);
    pDevice->busyFlag = WFD_TRUE; 

    switch (type)
    {
        case WFD_COMMIT_ENTIRE_DEVICE:
        {
            pDevice->busyFlag = WFD_FALSE;
                        
            // get/free fast rotator memory
            pDevice->utilityTable._wfd_FastRotatorMemEnable(pDevice->config.enableFastRotatorMem);

            break;
        }
		  
        case WFD_COMMIT_ENTIRE_PORT:
        {
            WFDint i;			
            WFD_PORT_CONFIG* pPortCfg;

             
            pPort = (WFD_PORT*) handle;
            pPortCfg = &(pPort->config);

            _wfd_current_processing_port = pPort;

            if ((KAL_TRUE == kal_query_systemInit()) || (INT_QueryExceptionStatus()))
            {
               pPortCfg->blockModeReq = WFD_TRUE;
               pPortCfg->syncEnable = WFD_FALSE;
            }
				
            if (pPortCfg->doBlt)
            {
                if (KAL_TRUE != LCD_Physical_Interface_Lock())
                {
                    pDevice->busyFlag = WFD_FALSE;
                    __wfd_lcd_ExecActiveEventsCb(pPort, (0x27));
                    return;
                }
   
                ///Bin: blt or flatten can not be executed in blocking mode + ISR context
                if((pPortCfg->blockModeReq == WFD_TRUE) && (kal_if_lisr() || kal_if_hisr()))
                {
                    ASSERT(0);
                }

            #ifdef DUAL_LCD
                // for dual lcd, we need to set lcd cmd/data address before blt
                if (2 == ATTACHED_LCM_CNT && WFD_PORT_TYPE_INTERNAL == pPort->config.type)
                {
                    if (0 == pPort->config.id)
                    {
                        DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
                        DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
                    }
                    else
                    {
                        DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
                        DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
                    }
                }
            #endif
                
                for (i = 0; i < DRV_LAYER_TOTAL_COUNT; i++)
                {
                    if (pPortCfg->bindedPipelines[i]) //if this pipeline is enabled?
                    {
                       pDevice->utilityTable._wfd_PipelineCommit(pDevice, &_wfd_lcd_pipeline[i]);
                    }
                }
					 
               __wfd_lcd_EnablePortSync(WFD_FALSE);
#if defined(DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT)
               //__wfd_lcd_CheckRotationTearing(pPort, _wfd_lcd_pipeline_captured);
               if (FACTORY_BOOT == stack_query_boot_mode())
               {
                  //MAUI_02386759: when at factory mode, custom might not attach 
                  //LCM module to our baseband, causing no TE signal sends to LCD. 
                  //Thus we will disable sync_te mechanism under FACTORY_BOOT
                  pPortCfg->syncEnable = WFD_FALSE;
               }

               if ((WFD_PORT_TYPE_INTERNAL == pPortCfg->type) && 
                   (WFD_TRUE == pPortCfg->syncEnable) &&
                   (pPort->TEDetectionFail == WFD_FALSE))
               {
                   WFDuint lcm_startY, roiWidth, roiHeight;
                   //WFDuint callbackPara[3];
                   //LCDTEAR_CALLBACK  lcdTearCallback = (LCDTEAR_CALLBACK)pDevice->utilityTable._wfd_Blt;

                   if(pPort->needToDetectTE == WFD_TRUE)
                   {
                        WFD_START_DETECT_TE = WFD_TRUE;
                   }
                   
				   pPort->isTEsyncMode = WFD_TRUE;
                   __wfd_lcd_StartWatchDog();
                   /*//Jody Li:It was called in wfd_lcd_initialize(), so there was no need to call again.
                   callbackPara[0] = (WFDuint)&_wfd_lcd_device;
                   callbackPara[1] = (WFDuint)pPort;
                   callbackPara[2] = (WFDuint)WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK;
                   lcdTear_UserRegisterCallback(pPortCfg->id, lcdTearCallback, callbackPara, 3);
                  */
                   lcm_startY = pPortCfg->partialRefreshRectangle[RECT_OFFSETY];
                   roiWidth = pPortCfg->partialRefreshRectangle[RECT_WIDTH];
                   roiHeight = pPortCfg->partialRefreshRectangle[RECT_HEIGHT];

                   pPort->portSyncPrimitives.Config(pPortCfg->id, lcm_startY, roiWidth, roiHeight);
                   pPort->portSyncPrimitives.Start(pPortCfg->id, (kal_bool)pPortCfg->blockModeReq);
                }
                else
#endif //DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT					
                {
                   pDevice->utilityTable._wfd_Blt(pDevice, pPort, WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK);
                }                
            }
            break;
        }
   }
}


#if defined(MT6268) || defined(MT6268T) || defined(MT6268H) || defined(MT6268A)

WFD_DEVICE _wfd_lcd_device =
{  
    //  Member:  WFDHWDevicePrimitivesMTK      primitivesTable;
    {   ///Must be payed attention to the following order is correct
        NULL,                            ///wfdCreateDevice, NULL is a flag to init LCD !!!!!!!!!!!!
        _wfd_lcd_DestroyDevice,          ///wfdDestroyDevice
        _wfd_lcd_DeviceCommit,           ///wfdDeviceCommit
    },
    //Member: WFDHWDeviceInternalUtilityMTK utilityTable;
    {    ///Must be payed attention to the following order is correct                               
        __wfd_device_PowerCtrl,            ///_wfd_PowerCtrl
        WFD_INVALID_HANDLE,                ///_wfd_CnvtImgFormatToHwDef
        WFD_INVALID_HANDLE,                ///_wfd_CnvtEventToHWDef
        WFD_INVALID_HANDLE,                ///_wfd_CnvtW2memFormatToHwDef
        __wfd_lcd_CnvtAngleToHwDef,        ///_wfd_CnvtAngleToHwDef
        WFD_INVALID_HANDLE,                ///   _wfd_GetIFPara is not used
        WFD_INVALID_HANDLE,                ///_wfd_Blt
        __wfd_lcd_PipelineCommit,          ///_wfd_PipelineCommit
        __wfd_lcd_ConfigMemOut,            ///_wfd_ConfigMemOut
        __wfd_lcd_FastRotatorMemEnable,    ///_wfd_FastRotatorMemEnable
        __wfd_lcd_ConfigPerformancePara,   ///_wfd_ConfigPerformancePara
    },
    WFD_ERROR_NONE,                         //Member: WFDErrorCode          lastUnreadError;
    WFD_FALSE,                              //Member: WFDboolean            busyFlag;
    WFD_FALSE,                              //Member: WFD_DEVICE*           inUse;
    0,                                      //Member: WFDint                id;
    {                                       //Member: Config
        WFD_FALSE,                          //               enableFastRotatorMem
    },
    _wfd_lcd_port,                          //Member: WFD_PORT              *ports
    WFD_ATTACHED_PORT_COUNT,                //Member: WFDuint               portCount
    _wfd_lcd_pipeline,                      //Member: WFD_PIPELINE          *pipelines
    DRV_LAYER_TOTAL_COUNT                   //Member: WFDuint               pipelineCount
};

#else //#if defined(MT6268) || defined(MT6268T) || defined(MT6268H) || defined(MT6268A)

WFD_DEVICE _wfd_lcd_device =
{
    //  Member:  WFDHWDevicePrimitivesMTK      primitivesTable;
    {   ///Must be payed attention to the following order is correct
        NULL,                               ///NULL is a flag to init LCD !!!!!!!!!!!!
        _wfd_lcd_DestroyDevice,
        _wfd_lcd_DeviceCommit,
    },
    //Member: WFDHWDeviceInternalUtilityMTK utilityTable;
    {    ///Must be payed attention to the following order is correct          
        __wfd_device_PowerCtrl,
        __wfd_lcd_CnvtImgFormatToHwDef,
        __wfd_lcd_CnvtEventToHWDef,
        __wfd_lcd_CnvtW2memFormatToHwDef,
        __wfd_lcd_CnvtAngleToHwDef,
        WFD_INVALID_HANDLE,                ///   _wfd_GetIFPara is not used
        __wfd_lcd_Blt,
        __wfd_lcd_PipelineCommit,
        __wfd_lcd_ConfigMemOut,
        __wfd_lcd_FastRotatorMemEnable,
        __wfd_lcd_ConfigPerformancePara,
    },
    WFD_ERROR_NONE,                         //Member: WFDErrorCode          lastUnreadError;
    WFD_FALSE,                              //Member: WFDboolean            busyFlag;
    WFD_FALSE,                              //Member: WFD_DEVICE*           inUse;
    0,                                      //Member: WFDint                id;
    {                                       //Member: Config
        WFD_FALSE,
    },
    _wfd_lcd_port,
    WFD_ATTACHED_PORT_COUNT,
    _wfd_lcd_pipeline,
    DRV_LAYER_TOTAL_COUNT
};

#endif //#if defined(MT6268) || defined(MT6268T) || defined(MT6268H) || defined(MT6268A)

WFDLCDInterfacePara _wfd_lcd_if_para[WFD_ATTACHED_PORT_COUNT] = 
{   
    {
        WFD_TRUE,
        LCD_IF_USER_MAIN_LCD,
        LCD_IF_TYPE_DBI_PARALLEL,
        0,
        MAIN_LCD_CMD_ADDR,
        MAIN_LCD_DATA_ADDR,
#ifdef COMBO_LCM_ID_AUTO_DETECT
        DEFAULT_MAIN_LCD_OUTPUT_FORMAT,
#else
        MAIN_LCD_OUTPUT_FORMAT,
#endif
        NULL,   ///
        0,
    },    
    #if (2 == ATTACHED_LCM_CNT)
    {
        WFD_TRUE,
        LCD_IF_USER_SUB_LCD,
        LCD_IF_TYPE_DBI_PARALLEL,
        1,
        SUB_LCD_CMD_ADDR,
        SUB_LCD_DATA_ADDR,
        SUB_LCD_OUTPUT_FORMAT,
        NULL,
        0,
    },
    #endif
    #if defined(LCD_FLATTEN_SUPPORT)
    {
        WFD_FALSE,
        LCD_IF_USER_MAIN_LCD,
        LCD_IF_TYPE_DBI_PARALLEL,
        0,
        MAIN_LCD_CMD_ADDR,
        MAIN_LCD_DATA_ADDR,
        WFD_LCD_WMEM_COLOR_RGB565,
        NULL,
        0,
    },
    #endif	 	
};
/*****************************************************************************
 *  API function definitions
 ****************************************************************************/
WFDErrorCode 
wfd_lcd_initialize(WFDHWDevicePrimitivesMTK **pDevicePrimitives)
{
    WFDuint i;
    WFD_DEVICE *device = &_wfd_lcd_device;
    if (NULL == pDevicePrimitives) { return WFD_ERROR_ILLEGAL_ARGUMENT; }

    // check if ever init'ed
    if (NULL != device->primitivesTable.wfdCreateDevice)
    {
        *pDevicePrimitives = &(device->primitivesTable);
        return WFD_ERROR_NONE;
    }

    /*
     * data structure init...
     */
    if (NULL == device->primitivesTable.wfdCreateDevice)
    {
        device->primitivesTable.wfdCreateDevice = _wfd_lcd_CreateDevice;
    }

    *pDevicePrimitives = &(device->primitivesTable);

    /*
     * Init internal used utilities functions...
     */
    wfd_lcd_hook_internal_utility(&device->utilityTable);

    /*
     * Do what is done in DDv1::lcd_system_init()
     */
    // 1. Get L1 SM handle.
#ifdef COMBO_LCM_ID_AUTO_DETECT
    for (i = 0; i < MAIN_LCM_MAX_NUM; i++)
#endif
    {
      // 2. Initialize LCM driver(s)
      LCD_FunConfig();
      _wfd_lcd_if_para[0]._ifFuncTable = (LCD_Funcs *)MainLCD;
      #if (2 == ATTACHED_LCM_CNT)
      _wfd_lcd_if_para[1]._ifFuncTable = (LCD_Funcs *)SubLCD;
      #endif

#ifdef COMBO_LCM_ID_AUTO_DETECT
      //get power control handle
      if (0 == i)
#endif
      {
        wfd_lcd_power_ctrl_handle =  lcd_power_ctrl__register_module();
        lcd_power_ctrl__enable(wfd_lcd_power_ctrl_handle);
      }

      // 3. call _wfd_lcd_init_internal after LCD_FunConfig
      // because we need to call LCM function to get information
      _wfd_lcd_if_para[0]._ifOutFormat = MAIN_LCD_OUTPUT_FORMAT;
      _wfd_lcd_init_internal();
	 
      // 4. Reset LCD HW registers
      SET_LCD_ROI_WMEM_OFFSET(0, 0);
      SET_LCD_WMEM_PITCH(0);
      SET_LCD_CMD_QUEUE1;
      DISABLE_LCD_ROI_CTRL_W2MEM;
      LCD_SET_GMCCON_BURST_SIZE(LCD_GMCCON_BURST_64_BYTE);

#if defined(__DRV_COLOR_HW_SUPPORT__)
      // initialize and config mm_color
      colorInit();
      //colorUpdateConfig(COLOR_PATH_LCD, LCD_GET_ROI_WIDTH);
#endif

      // 5. Initialize LCD interface settings, such as setup GPIO, LCM timing, reset LCM
      // TODO: Declare this function in a common header file as a std. API of a LCM driver.
      init_lcd_interface();

#ifdef COMBO_LCM_ID_AUTO_DETECT
      // check current used LCM
      if (LCM_ID_Validation())
        break;
      else
        LCM_ID_Alter();  // change to next LCM for trying
#endif
    }
    
    // 6. Initialize LCM HW module
    for (i = 0; i < ATTACHED_LCM_CNT; i++)
    {      
        LCD_SET_ROI_CMD_ADDR(_wfd_lcd_port[i].portCmdAddr);
        LCD_SET_ROI_DATA_ADDR(_wfd_lcd_port[i].portDataAddr);
        SET_LCD_ROI_CTRL_OUTPUT_FORMAT((_wfd_lcd_port[i].portOutputFormat));
#if defined(__FAST_LOGO__)
        if ( 0 == INT_GetSysStaByCmd(SYS_CMD_BL_LOGO_DISPLAYED, NULL) )
#endif
            _wfd_lcd_port[i].portFuncTable->Init(0, 0);
    }

    // 7. Register LCD I/F manager... after LCM init.
    {
        //LCD_IOCTRL_RESULT_E err;    	         
		  
    for (i = 0; i < ATTACHED_LCM_CNT; i++)
    {   
        LCD_IOCTRL_LCD_SETTING_T lcd_temp_if;
        // get handle
        _lcd_if_mgr_port_handle[i] = lcd_get_ioctrl_device_if_handle((LCD_IF_USER_ENUM)(_wfd_lcd_if_para[i]._ifUser)); 

        if (0 == i) //for MAIN LCD
        {
            lcd_ioctrl_device_if_settings(_lcd_if_mgr_port_handle[i],
                                                LCD_IOCTRL_QUERY_MAIN_LCD_IF,
                                                &lcd_temp_if,
                                                sizeof(LCD_IOCTRL_LCD_SETTING_T));
        }
        else if(1 == i) //for SUB LCD
        {
            lcd_ioctrl_device_if_settings(_lcd_if_mgr_port_handle[i],
                                                LCD_IOCTRL_QUERY_SUB_LCD_IF,
                                                &lcd_temp_if,
                                                sizeof(LCD_IOCTRL_LCD_SETTING_T));
        }
        _wfd_lcd_if_para[i]._ifType = lcd_temp_if.lcd_if_setting.if_type;
        _wfd_lcd_if_para[i]._ifCs = lcd_temp_if.lcd_if_setting.if_cs_no;

        _lcd_if_mgr_port_setting[i].if_type = (LCD_IF_TYPE_ENUM)(_wfd_lcd_if_para[i]._ifType);
        _lcd_if_mgr_port_setting[i].if_cs_no = _wfd_lcd_if_para[i]._ifCs;
        lcd_ioctrl_device_if_settings(_lcd_if_mgr_port_handle[i], 
                                            LCD_IOCTRL_QUERY_DEVICE_IF, 
                                            &_lcd_if_mgr_port_setting[i], 
                                            sizeof(LCD_IOCTRL_DEVICE_IF_T));

        //Zifeng: Modify Timing if data & cmd is different
        if (((LCD_IF_TYPE_DBI_PARALLEL == _lcd_if_mgr_port_setting[i].if_type) ||
             (LCD_IF_TYPE_DBI_SERIAL == _lcd_if_mgr_port_setting[i].if_type)
            ) &&
            (_wfd_lcd_port[i].portFuncTable) &&
            (_wfd_lcd_port[i].portFuncTable->IOCTRL) &&
            KAL_TRUE
           )
        {
            LCD_Funcs* ifFuncTable;
            LCD_IF_TIME_PARA_T lcd_if_data_timing;
            lcd_if_data_timing.if_cs_no = _lcd_if_mgr_port_setting[i].if_cs_no;
            if (LCD_IF_TYPE_DBI_PARALLEL == _lcd_if_mgr_port_setting[i].if_type)
                lcd_if_data_timing.parallel_if = KAL_TRUE;
            else
                lcd_if_data_timing.parallel_if = KAL_FALSE;
            ifFuncTable = _wfd_lcd_port[i].portFuncTable;
            if (LCM_IOCTRL_OK == ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__DATA_TIMEING_SETTING, &(lcd_if_data_timing)))
            {
                if (KAL_TRUE == lcd_if_data_timing.parallel_if)
                {
                    LCD_PARALLEL_IF_TIME_PARA_T* lcd_parallel_if = &(lcd_if_data_timing.u.dbi_parallel_if);
                    LCD_IOCTRL_DBI_PARALLEL_IF_T* lcd_if_mgr_parallel_if = &(_lcd_if_mgr_port_setting[i].if_settings.dbi_parallel_if);
                    lcd_if_mgr_parallel_if->if_set_common_period = KAL_TRUE;
                    lcd_if_mgr_parallel_if->if_period = lcd_parallel_if->if_period;
                    lcd_if_mgr_parallel_if->if_c2rh = lcd_parallel_if->rd_hold_time;
                    lcd_if_mgr_parallel_if->if_c2rs = lcd_parallel_if->rd_setup_time;
                    lcd_if_mgr_parallel_if->if_rlt= lcd_parallel_if->rd_latency_time;
                    lcd_if_mgr_parallel_if->if_c2wh= lcd_parallel_if->wt_hold_time;
                    lcd_if_mgr_parallel_if->if_c2ws = lcd_parallel_if->wt_setup_time;
                    lcd_if_mgr_parallel_if->if_wst = lcd_parallel_if->wt_wait_time;
                    lcd_if_mgr_parallel_if->__if_reg_fast_mode = KAL_FALSE;
                }
                else
                {
                    LCD_SERIAL_IF_TIME_PARA_T* lcd_serial_if = &(lcd_if_data_timing.u.dbi_serial_if);
                    LCD_IOCTRL_DBI_SERIAL_IF_T* lcd_if_mgr_serial_if = &(_lcd_if_mgr_port_setting[i].if_settings.dbi_serial_if);
                    lcd_if_mgr_serial_if->if_period = lcd_serial_if->if_period;
                    lcd_if_mgr_serial_if->scl_rd_low_count = lcd_serial_if->rd_low;
                    lcd_if_mgr_serial_if->scl_rd_high_count = lcd_serial_if->rd_high;
                    lcd_if_mgr_serial_if->scl_wt_low_count= lcd_serial_if->wt_low;
                    lcd_if_mgr_serial_if->scl_wt_high_count = lcd_serial_if->wt_high;
                    lcd_if_mgr_serial_if->__if_reg_fast_mode = KAL_FALSE;
                }
                lcd_ioctrl_device_if_settings(_lcd_if_mgr_port_handle[i], 
                                              LCD_IOCTRL_CONFIG_DEVICE_IF, 
                                              &_lcd_if_mgr_port_setting[i], 
                                              sizeof(LCD_IOCTRL_DEVICE_IF_T));
                lcd_ioctrl_device_if_settings(_lcd_if_mgr_port_handle[i], 
                                              LCD_IOCTRL_QUERY_DEVICE_IF, 
                                              &_lcd_if_mgr_port_setting[i], 
                                              sizeof(LCD_IOCTRL_DEVICE_IF_T));
            }
        }
    }
  
#if defined(LCD_FLATTEN_SUPPORT)
    //For MemOut	 
    _lcd_if_mgr_port_handle[i] = _lcd_if_mgr_port_handle[0]; 
    kal_mem_cpy(&_lcd_if_mgr_port_setting[i],
                &_lcd_if_mgr_port_setting[0],
                sizeof(LCD_IOCTRL_DEVICE_IF_T));
#endif
    }


    // 8. Calculate hopping to avoid RF-desense
#if !defined(__MAUI_BASIC__)
    L1D_LCD_Cycle_Calculate();
#endif

    // 7. register interrupt LISR/HISR
    IRQ_Register_LISR(IRQ_LCD_CODE, __wfd_lcd_Lisr, "LCD_LISR");
    IRQSensitivity(IRQ_LCD_CODE, LEVEL_SENSITIVE);
    DRV_Register_HISR(DRV_LCD_HISR_ID, __wfd_lcd_Hisr);
    IRQUnmask(IRQ_LCD_CODE);
	 
    // 8. create timer if required
    if (NULL == _wfd_lcd_timer)
    {
        _wfd_lcd_timer = DclSGPT_Open(DCL_GPT_CB, 0);
    }

    //if (NULL == _owf_event)
    //{
    //    _owf_event = kal_create_event_group("wfd_lcd_event");
    //}

#if defined(DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT)
    // 10. Init Tear_Manager...
    {
        lcdTearErrorCode error;
        LCDTEAR_CALLBACK  lcdTearCallback = (LCDTEAR_CALLBACK)(device->utilityTable._wfd_Blt);
        WFDuint callbackPara[3];
		  
        for (i = 0; i < ATTACHED_LCM_CNT; i++)
        {   
           error = lcdTear_Init(i, _wfd_lcd_port[i].portFuncTable, &_lcd_if_mgr_port_setting[i]); 
           if (LCDTEAR_ERROR_NONE != error)
           {
              ASSERT(0);// do error handling
           }
           callbackPara[0] = (WFDuint) &_wfd_lcd_device;
           callbackPara[1] = (WFDuint) &_wfd_lcd_port[i];
           callbackPara[2] = (WFDuint) WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK;
			  
           lcdTear_GetSyncPrimitives(i, &_wfd_lcd_port[i].portSyncPrimitives);
           lcdTear_UserRegisterCallback(i, lcdTearCallback, callbackPara, 3);
           if (LCDTEAR_NOT_SUPPORT == _wfd_lcd_port[i].portSyncPrimitives.Init(i))
           {
             ASSERT(0);
           }
        }
    }
#endif //DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT

    #if defined(DDV2_PERFORMANCE_PROFILING_SUPPORT)
    ///reset the profiling record
    lcd_profiling_period_start_time_tick = drv_get_current_time();
    lcd_profiling_period_update_frame_count = 0;
    lcd_profiling_period_drop_frame_count = 0;
    #endif

	 
    return WFD_ERROR_NONE;
}


#ifdef __cplusplus
}
#endif


#endif  //#if defined(MT6253)....etc

#endif  // #if defined(__MTK_TARGET__)

