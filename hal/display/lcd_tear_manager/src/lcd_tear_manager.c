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
 *    This file is the body of LCD Tearing Control.
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
 * 04 26 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 * 
 * 09 05 2012 chrono.wu
 * removed!
 * .
 *
 * 07 18 2012 haitao.shang
 * removed!
 * .
 *
 * 05 17 2012 dong.guo
 * removed!
 * .
 *
 * 04 25 2012 xiaoyong.ye
 * removed!
 * Add serial LCM teaing manger code.
 *
 * 03 20 2012 xiaoyong.ye
 * removed!
 * MT6250 display driver check in.
 *
 * 02 14 2012 haitao.shang
 * removed!
 * .
 *
 * 02 10 2012 haitao.shang
 * removed!
 * .
 *
 * 02 08 2012 dong.guo
 * removed!
 * .
 *
 * 02 08 2012 dong.guo
 * removed!
 * lcd_tear_manager: correct the calculate method of TransferCntPerPixel.
 *
 * 12 01 2011 haitao.shang
 * removed!
 * .
 *
 * 11 22 2011 dong.guo
 * removed!
 * .
 *
 * 10 27 2011 dong.guo
 * removed!
 * MT6255 DDv2 check in .
 *
 * 10 13 2011 sixian.wang
 * removed!
 * .
 *
 * 09 15 2011 bin.han
 * removed!
 * .
 *
 * 09 07 2011 bin.han
 * removed!
 * .
 *
 * 09 06 2011 bin.han
 * removed!
 * .
 *
 * 08 26 2011 bin.han
 * removed!
 * .
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
 * 08 17 2011 matthew.chen
 * removed!
 * Remove MT6256_S00 for display driver
 *
 * 08 16 2011 matthew.chen
 * removed!
 * Remove ^M in the eol
 *
 * 07 26 2011 bin.han
 * removed!
 * .
 *
 * 07 21 2011 matthew.chen
 * removed!
 * Fix potential bugs
 *
 * 06 27 2011 bin.han
 * removed!
 * Fix build warning
 *
 * 05 31 2011 bin.han
 * removed!
 * MT6252 HW_DELAY mode needs at lease one line delay
 *
 * 05 27 2011 bin.han
 * removed!
 * .
 *
 * 05 24 2011 bin.han
 * removed!
 * .
 *
 * 05 23 2011 bin.han
 * removed!
 * Fix build warning
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
 * 03 08 2011 bin.han
 * removed!
 * .
 *
 * 03 08 2011 sophie.chen
 * removed!
 * .
 *
 * 03 02 2011 sophie.chen
 * removed!
 * .
 *
 * 02 22 2011 sophie.chen
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
 * modify tearing control array size..
 *
 * 01 26 2011 sophie.chen
 * removed!
 * .
 *
 * 01 21 2011 sophie.chen
 * removed!
 * .
 *
 * 01 19 2011 sophie.chen
 * removed!
 * .
 *
 * 01 18 2011 sophie.chen
 * removed!
 * .
 *
 * 01 17 2011 sophie.chen
 * removed!
 * .
 *
 * 01 06 2011 sophie.chen
 * removed!
 * .
 *
 * 12 24 2010 sophie.chen
 * removed!
 * .
 *
 * 12 23 2010 sophie.chen
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
 * 12 16 2010 sophie.chen
 * NULL
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__MTK_TARGET__)

#include "drv_comm.h"
#include "kal_release.h"
#include "eint.h"
#include "lcd_if_hw.h"
#include "lcd_if.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "lcd_if_manager.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"

#if defined (DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT)

#include "lcd_tear_manager\inc\lcd_tear_manager.h"
#include "lcd_tear_manager\inc\lcd_tear_manager_internal.h"

#include "wfd\inc\Wfd_common.h"
#include "wfd\inc\Wfd.h"
#if defined(__SYNC_LCM_SW_SUPPORT__) || defined(__SUBLCD_SYNC_LCM_SW_SUPPORT__)
extern void custom_sync_lcm_eint_setting(kal_bool *sync_signal_polarity);
extern kal_uint8 custom_eint_get_channel(eint_channel_type type);
#else
#define sync_lcm_chann 0
void custom_sync_lcm_eint_setting(kal_bool *sync_signal_polarity){;}
//kal_uint8 custom_eint_get_channel(eint_channel_type type) {return 0;}
#endif



typedef enum
{
  LCDTEAR_HW_VSYNC_SW_DELAY__EXPIRED_EVENT = 0x1, //
}lcdTearSyncEventEnum;


lcdTearCtrlBlk lcdTear_cnxt[ATTACHED_LCM_COUNT]; //ATTACHED_LCM_CNT
extern WFD_PORT _wfd_lcd_port[WFD_ATTACHED_PORT_COUNT];


/******************************************************************
*  Internal Utilities
*******************************************************************/
//#define LCDTEAR_DBG_MSG_SUPPORT

#if defined(LCDTEAR_DBG_MSG_SUPPORT)
#define LCD_TEAR_DBG_ENTRY_CNT 64
typedef enum
{
  LCDTEAR____________________________NONE,
  LCDTEAR_VSYNC_____________________START,
  LCDTEAR_FRAME_MARKER______________START,
  LCDTEAR_VHSYNC____________________START,

  LCDTEAR_HW_DELAYTIME________________BLT,
  LCDTEAR_HW_DELAYTIME______________START,

  LCDTEAR_SW_TIMER_DELAY______________BLT,
  LCDTEAR_SW_TIMER_DELAY____________START,
  LCDTEAR_SW_TIMER_DELAY________VSYNC_ISR,
  LCDTEAR_SW_TIMER_DELAY_______TIMEOUT_CB,
  LCDTEAR_SW_TIMER_DELAY____REENTRY_VSYNC,
  LCDTEAR_SW_TIMER_DELAY__SET_VSYNC_EVENT,
  LCDTEAR_SW_TIMER_DELAY____________ERROR,
  LCDTEAR_SW_TIMER_DELAY_____CANCLE_TIMER,
  LCDTEAR_SW_TIMER_DELAY_____NONBLOCK_REQ,


  LCDTEAR_SCANLINE__________________START,
  LCDTEAR_NOSYNC____________________START,


  LCDTEAR_SW_TIMER_DELAY____SET_TIMER_VAL,
}LCDTearDbgIdEnum;


typedef struct
{
  LCDTearDbgIdEnum id;
  kal_uint32       time;
} LCDTearDbgInfo;


kal_uint32     lcdTearDbgCnt= 0;
LCDTearDbgInfo lcdTearDbgDat[LCD_TEAR_DBG_ENTRY_CNT];
void lcdTear_trace(LCDTearDbgIdEnum id)
{
   kal_uint32 save_irq_mask;
   kal_uint32 index;

   //save_irq_mask=SaveAndSetIRQMask();
   index = lcdTearDbgCnt;
   lcdTearDbgCnt++;
   lcdTearDbgCnt = lcdTearDbgCnt % LCD_TEAR_DBG_ENTRY_CNT;
   //RestoreIRQMask(save_irq_mask);

   lcdTearDbgDat[index].id    = id;
   lcdTearDbgDat[index].time  = drv_get_current_time();
}

#else
 #define lcdTear_trace(i)
#endif

static lcdTearErrorCode
lcdTear_GetCapabilityAndPara(kal_uint32 port_id, LCD_Funcs* ifFuncTable, LCD_IOCTRL_DEVICE_IF_T *if_set)
{
  lcdTearCtrlBlk *pCtrlBlk;

  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];

  if ((!ifFuncTable->IOCTRL) || (!if_set))
  {
    return LCDTEAR_BAD_PARAMETER;
  }

  //Get LCD IF setting
  {
    kal_mem_cpy(&pCtrlBlk->lcdIfSetting, if_set, sizeof(LCD_IOCTRL_DEVICE_IF_T));
  }

  //Get LCM capcability & info
  {
    kal_uint32 lcm_height, lcm_width, temp;

    if (LCM_IOCTRL_NOT_SUPPORT == ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__LCM_WIDTH, &(lcm_width)))
    {
      #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__MAIN_LCM_SCANLINE_ROTATION_90__) || defined(__MAIN_LCM_SCANLINE_ROTATION_270__))
          lcm_width = LCD_HEIGHT;
      #else
      lcm_width = LCD_WIDTH;
      #endif
    }
    if (LCM_IOCTRL_NOT_SUPPORT == ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__LCM_HEIGHT, &(lcm_height)))
    {
      #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__MAIN_LCM_SCANLINE_ROTATION_90__) || defined(__MAIN_LCM_SCANLINE_ROTATION_270__))
          lcm_height = LCD_WIDTH;
      #else
      lcm_height = LCD_HEIGHT;
      #endif
    }
    pCtrlBlk->lcmWidth = lcm_width;
    pCtrlBlk->lcmHeight = lcm_height;

    if (LCM_IOCTRL_NOT_SUPPORT == ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__BACK_PORCH, &temp))
    {
      temp = 0;
    }
    pCtrlBlk->lcmBackPorch = temp;

    if (LCM_IOCTRL_NOT_SUPPORT == ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__FRONT_PORCH, &temp))
    {
      temp = 0;
    }
    pCtrlBlk->lcmFrontPorch = temp;

    if (LCM_IOCTRL_NOT_SUPPORT == ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__FRAME_RATE, &temp))
    {
      temp = 70;
    }
    pCtrlBlk->lcmFrameRate = temp;

    temp = pCtrlBlk->lcmBackPorch;
    pCtrlBlk->lcmFrameMarkSupport = KAL_FALSE;
    pCtrlBlk->lcmFrameMarker = pCtrlBlk->lcmBackPorch;
    if (LCM_IOCTRL_OK == ifFuncTable->IOCTRL(LCM_IOCTRL_SET__FRAME_MARKER, &temp))
    {
      pCtrlBlk->lcmFrameMarkSupport = KAL_TRUE;
    }

    if (LCM_IOCTRL_NOT_SUPPORT == ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__TE_EDGE_ATTRIB, &temp))
    {
      temp = LCM_TE_RISING_EDGE;
    }
    pCtrlBlk->lcmVsyncActiveEdge = (LCM_TE_ATTRIB_ENUM)temp;

    {
      if (LCM_IOCTRL_NOT_SUPPORT == ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__SYNC_MODE, &pCtrlBlk->lcmSyncSignalMode))
      {
        #if 0
/* under construction !*/
/* under construction !*/
        #else
        pCtrlBlk->lcmSyncSignalMode = LCM_TE_NONE;
        #endif
      }

      if (LCM_TE_VHSYNC_MODE == pCtrlBlk->lcmSyncSignalMode)
      {
        if (LCM_IOCTRL_OK == ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__SUPPORT_H_V_SIGNAL_FUNC, NULL))  
        {
           kal_uint32 v_sync_width;
           ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY__SUPPORT_V_PULSE_WIDTH, &v_sync_width); //us
           ASSERT(v_sync_width);
           pCtrlBlk->lcmVHSyncSupport = KAL_TRUE;
           pCtrlBlk->lcmVsyncWidth = v_sync_width; //in us
        }
      }

      #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #endif
    }
  }


  //Get LCD HW capcability
  if (LCDTEAR_PORT0 == port_id)
  {
    #if defined(SYNC_MAIN_LCM_HW_SUPPORT)
    pCtrlBlk->hwTESyncSupport = KAL_TRUE;
    #else
    pCtrlBlk->hwTESyncSupport = KAL_FALSE;
    #endif
    #if defined(SYNC_MAIN_LCM_SW_SUPPORT)
    pCtrlBlk->swTESyncSupport = KAL_TRUE;
    #else
    pCtrlBlk->swTESyncSupport = KAL_FALSE;
    #endif
  }
  #ifdef DUAL_LCD
  else
  {
    #if defined(SYNC_SUB_LCM_HW_SUPPORT)
    pCtrlBlk->hwTESyncSupport = KAL_TRUE;
    #else
    pCtrlBlk->hwTESyncSupport = KAL_FALSE;
    #endif
    #if defined(SYNC_SUB_LCM_SW_SUPPORT)
    pCtrlBlk->swTESyncSupport = KAL_TRUE;
    #else
    pCtrlBlk->swTESyncSupport = KAL_FALSE;
    #endif
  }
  #endif//#ifdef DUAL_LCD 

  if (NULL == pCtrlBlk->lcdTEInitPrimitiviesTab.SetLCDHwCapabilityAndPara)
  {
    ASSERT(0);
  }
  pCtrlBlk->lcdTEInitPrimitiviesTab.SetLCDHwCapabilityAndPara(port_id);

  //Calculate
  {
    float ClkWidth,TransferCntPerPixel;
    kal_uint32 IfWidth, lcmFmtBitCnt;
    //kal_uint32 lcdPeriodVal, lcdWriteWaitState, lcdWriteHoldTime;

    if (LCD_IF_TYPE_DBI_PARALLEL == if_set->if_type)
    {
      IfWidth = pCtrlBlk->lcdIfSetting.if_settings.dbi_parallel_if.if_bus_width;

      ClkWidth = 1000000000/(double)pCtrlBlk->lcdIfSetting.if_settings.dbi_parallel_if.if_clk_freq; //ns
      pCtrlBlk->lcdClockWidth = ClkWidth; //ns

      lcmFmtBitCnt = (LCDTEAR_PORT0_OUTPUT_FORMAT & 0x38) >> 3;
      if (LCDTEAR_PORT0 != port_id)
      {
        if (0xFFFFFFFF == LCDTEAR_PORT1_OUTPUT_FORMAT)
        {
          return LCDTEAR_BAD_PARAMETER;
        }
		else
		{
        lcmFmtBitCnt = (LCDTEAR_PORT1_OUTPUT_FORMAT & 0x38) >> 3;
		}
      }

      switch(lcmFmtBitCnt)
      {
        case 0: lcmFmtBitCnt = 3 + 3 + 2; break;//RGB332
        case 1: lcmFmtBitCnt = 4 + 4 + 4; break;//RGB444
        case 2: lcmFmtBitCnt = 5 + 6 + 5; break;//RGB565
        case 3: lcmFmtBitCnt = 6 + 6 + 6; break;//RGB666
        case 4: lcmFmtBitCnt = 8 + 8 + 8; break;//RGB888
        default: ASSERT(0);
      }
      //TransferCntPerPixel = (lcmFmtBitCnt % IfWidth)? (1 + lcmFmtBitCnt/IfWidth): (lcmFmtBitCnt/IfWidth);

      /**Dong: calculate different combination of color fmt and if width
        from the spec, the value should be one of (0.5, 1, 1.5, 2, 3)
    	**/   
      TransferCntPerPixel = (float)lcmFmtBitCnt/(float)IfWidth;	  
    
	    if(TransferCntPerPixel >0.5 && TransferCntPerPixel <= 1) 
	  		TransferCntPerPixel = 1;
	 		else if(TransferCntPerPixel >1 && TransferCntPerPixel <= 1.5)
	  		TransferCntPerPixel = 1.5;
	 		else if(TransferCntPerPixel >1.5 && TransferCntPerPixel <= 2)
	  		TransferCntPerPixel = 2;
	  	else if(TransferCntPerPixel >2 && TransferCntPerPixel <= 3)
	  		TransferCntPerPixel = 3;
	  	else if(TransferCntPerPixel >0 && TransferCntPerPixel <= 0.5)
	  		TransferCntPerPixel = 0.5;
	  	else
	  		ASSERT(0);
	  	
      pCtrlBlk->lcdPixelTransitionTime = TransferCntPerPixel * pCtrlBlk->lcdIfSetting.if_settings.dbi_parallel_if.if_total_write_cycles * ClkWidth; //ns

      pCtrlBlk->lcmScanTimePerLine = (1000000000/(pCtrlBlk->lcmFrameRate * (pCtrlBlk->lcmHeight + pCtrlBlk->lcmBackPorch + pCtrlBlk->lcmFrontPorch))); //ns

      pCtrlBlk->lcmVsyncWidth = (kal_uint32) ((pCtrlBlk->lcmVsyncWidth * 1000) / ClkWidth);  //clock count

    }
    else if (LCD_IF_TYPE_DBI_SERIAL == if_set->if_type)
    {
      // TODO:
      //sht:serial interface calculate for pCtrlBlk arribt
       #if defined(MT6250)
	  lcdTear_TearingControlforSerialLCM_6250(port_id);
       #elif defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
	  lcdTear_TearingControlforSerialLCM_6260(port_id);
	  #endif
    }
  }

  return LCDTEAR_ERROR_NONE;
}

static kal_uint32
lcdTear_CalculateHsyncDelayLineCount(
  lcdTearCtrlBlk *pCtrlBlk,
  kal_uint32 roiWidth,
  kal_uint32 roiHeight)
{
  static kal_uint32 debug_more_delay_count = 0;
  kal_uint32 lcmWidth = pCtrlBlk->lcmWidth;
  kal_uint32 final_hsync_cnt = 0;

  if (0 == lcmWidth) ASSERT(0);
  if (lcmWidth >= roiWidth)
  {
    //final_hsync_cnt += (height - ((height * width) / lcm_width)); when we have done calculate suitable period value
    kal_uint32 temp = (kal_uint32)((roiHeight * roiWidth * pCtrlBlk->lcdPixelTransitionTime) / pCtrlBlk->lcmScanTimePerLine);
    kal_uint32  delay_line_count = 0;

    delay_line_count = (temp <= roiHeight)? (roiHeight - temp): pCtrlBlk->lcmVsyncActiveEdge;/*roiHeight*/ // for the FALSE case, tearing might happen...
    //if false , (roiWidth * pCtrlBlk->lcdPixelTransitionTime) > pCtrlBlk->lcmScanTimePerLine, lcd update speed is faster than LCM scan speed 
    final_hsync_cnt += delay_line_count;
  }

  final_hsync_cnt += (pCtrlBlk->lcmBackPorch + debug_more_delay_count);
  return final_hsync_cnt;
}

static lcdTearErrorCode
lcdTear_ChooseSuitableSyncMode(void)
{
  kal_uint32 i, idx;
  lcdTearCtrlBlk *pCtrlBlk;
  kal_bool beenUsed[LCDTEAR_AVAILABLE_SYNC_MODE_COUNT];

  kal_mem_set(&beenUsed, 0, sizeof(beenUsed));
  for (i = 0; i < ATTACHED_LCM_COUNT; i++)
  {
    pCtrlBlk = &lcdTear_cnxt[i];
    if (LCDTEAR_MODE_RSVD != lcdTear_cnxt[i].usedLcdSyncMode)
    {
      beenUsed[lcdTear_cnxt[i].usedLcdSyncMode] = KAL_TRUE;
    }
  }

  for (i = 0; i < ATTACHED_LCM_COUNT; i++)
  {
    pCtrlBlk = &lcdTear_cnxt[i];
    pCtrlBlk->usedLcdSyncMode = LCDTEAR_NO_SYNC;
    for (idx = 0; idx < LCDTEAR_AVAILABLE_SYNC_MODE_COUNT; idx++)
    {
      lcdTearSyncModeEnum tgtMode;

      tgtMode = pCtrlBlk->lcdSyncModePriority[idx];  //read chip-dep sync_mode priority settings
      if (pCtrlBlk->lcdSyncModeSupportCap[tgtMode] == KAL_FALSE)
      {
         continue;
      }
      if(LCDTEAR_HW_VHSYNC_MODE >= tgtMode)
      {
        if( (beenUsed[LCDTEAR_HW_VSYNC_MODE])                 || 
            (beenUsed[LCDTEAR_HW_VSYNC_HW_FRAME_MARKER_MODE]) ||
            (beenUsed[LCDTEAR_HW_VSYNC_HW_DELAY_TIME_MODE])   || 
            (beenUsed[LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE])   ||
            (beenUsed[LCDTEAR_HW_VHSYNC_MODE])
          )
        {
          //HW can only support 1 TE pin, if any of TE-based method was chosen, 
          //can't concurrently support TE-based methods.
          continue;
        }
      }
      if (pCtrlBlk->lcdSyncModeSupportCap[tgtMode])
      {
        pCtrlBlk->usedLcdSyncMode = tgtMode;
        beenUsed[tgtMode] = KAL_TRUE;
        break;
      }
    }
  }
  return LCDTEAR_ERROR_NONE;
}

/******************************************************************
*******************************************************************/
static lcdTearErrorCode
lcdTear_VsyncModeInit(kal_uint32 port_id)
{
  lcdTearCtrlBlk *pCtrlBlk;

  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];

  if (pCtrlBlk->usedLcdSyncMode == LCDTEAR_HW_VHSYNC_MODE)
  {    
    if((KAL_TRUE == pCtrlBlk->lcmVHSyncSupport) && (KAL_TRUE == pCtrlBlk->lcdVHSyncSupport))
    {
      SET_TE_DIV(0x2);  // means: 32
      SET_TE_VS_WIDTH_LIMIT((pCtrlBlk->lcmVsyncWidth / 32));
      SET_TE_VH_SYNC_MODE;
      GET_TE_CTRL_REG_VAL(pCtrlBlk->_rsvdTEReg0);
    }
  }
  else  if(pCtrlBlk->usedLcdSyncMode == LCDTEAR_HW_VSYNC_HW_DELAY_TIME_MODE)
  {
    if (KAL_TRUE == pCtrlBlk->lcdDelayTimeSupport)
    {
      kal_uint32 line_interval = 0;

      #if defined(MT6236)
      {
        kal_uint32 div = 8;
        kal_uint32 te_div = 0;      
        kal_uint32 lcmScanTimePerLineTmp;
        	
        lcmScanTimePerLineTmp = pCtrlBlk->lcmScanTimePerLine / pCtrlBlk->lcdClockWidth; //clock count
      
        line_interval = lcmScanTimePerLineTmp;
        do
        {
          div *= 2;
          te_div++;
          line_interval /= div;
        }while (line_interval > 0xfff);
        if (line_interval % div)
        {
          line_interval++ ;
        }
        
        SET_TE_DIV(te_div);
      }
      #elif defined(MT6276) || defined(MT6256) || defined(MT6252) || defined(MT6252H) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      {
        kal_uint32 lcmScanTimePerLineTmp;
                
        lcmScanTimePerLineTmp = pCtrlBlk->lcmScanTimePerLine / pCtrlBlk->lcdClockWidth; //clock count
      
        line_interval = lcmScanTimePerLineTmp >> 4;   /// divide 16
        if (lcmScanTimePerLineTmp & (16-1))
        {
          line_interval++ ;
        }
      }
      #endif
    
      SET_TE_DELAYTIME_MODE_HSYNC_WIDTH(line_interval);
      SET_TE_DELAYTIME_SYNC_MODE;
      GET_TE_CTRL_REG_VAL(pCtrlBlk->_rsvdTEReg0);
    
      #if defined(MT6276) || defined(MT6256) || defined(MT6252) || defined(MT6252H) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      //GET_TE_CALC_HTT_REG_VAL(pCtrlBlk->_rsvdTEReg1);
      GET_TE_SYNC_LCM_SIZE_REG_VAL(pCtrlBlk->_rsvdTEReg2);
      //GET_TE_SYNC_COUNTER_REG_VAL(pCtrlBlk->_rsvdTEReg3); //will be set in config function
      #endif
    }
  }

  return LCDTEAR_ERROR_NONE;
}

static lcdTearErrorCode
lcdTear_VsyncModeConfig(
  kal_uint32 port_id,
  kal_uint32 lcm_startY,
  kal_uint32 roiWidth,
  kal_uint32 roiHeight)
{

  lcdTearCtrlBlk *pCtrlBlk;
  kal_uint32 final_hsync_cnt = lcm_startY;

  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];

  if(pCtrlBlk->usedLcdSyncMode == LCDTEAR_HW_VSYNC_HW_FRAME_MARKER_MODE)
  {
  	if (NULL == pCtrlBlk->ifFuncTable->IOCTRL)
  	{
         return LCDTEAR_NOT_SUPPORT;
  	}

  	/// set frame marker here.
    final_hsync_cnt += lcdTear_CalculateHsyncDelayLineCount(pCtrlBlk, roiWidth, roiHeight);
    while(LCD_IS_RUNNING);    ///wait until the LCD is not busy
    if(pCtrlBlk->lcmFrameMarker != final_hsync_cnt)
    {
        pCtrlBlk->ifFuncTable->IOCTRL(LCM_IOCTRL_SET__FRAME_MARKER, &final_hsync_cnt);
        pCtrlBlk->lcmFrameMarker = final_hsync_cnt;
    }
  }
  else if(pCtrlBlk->usedLcdSyncMode == LCDTEAR_HW_VHSYNC_MODE)
  {
    if ((KAL_TRUE == pCtrlBlk->lcmVHSyncSupport) && 
        (KAL_TRUE == pCtrlBlk->lcdVHSyncSupport))
    {
      final_hsync_cnt += lcdTear_CalculateHsyncDelayLineCount(pCtrlBlk, roiWidth, roiHeight);
      SET_TE_CTRL_REG_VAL(pCtrlBlk->_rsvdTEReg0);//re-init
      SET_TE_HS_CNT((final_hsync_cnt));
    }
  }
  else if(pCtrlBlk->usedLcdSyncMode == LCDTEAR_HW_VSYNC_HW_DELAY_TIME_MODE)
  {
    if (KAL_TRUE == pCtrlBlk->lcdDelayTimeSupport)
    {
      final_hsync_cnt += lcdTear_CalculateHsyncDelayLineCount(pCtrlBlk, roiWidth, roiHeight);
      if(final_hsync_cnt == 0)
      	final_hsync_cnt = 1;	///Bin: at lease one line delay, or else some chips will work abnormal, such as MT6252
      	
      SET_TE_CTRL_REG_VAL(pCtrlBlk->_rsvdTEReg0);
      #if defined(MT6276) || defined(MT6256) || defined(MT6252) || defined(MT6252H) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      SET_TE_SYNC_LCM_SIZE_REG_VAL(pCtrlBlk->_rsvdTEReg2);
      #endif
      SET_TE_HS_CNT(final_hsync_cnt);
    }
  }

  return LCDTEAR_ERROR_NONE;
}

//We register this function to WFD in order to wakeup TearManager when LCD TE interrupt is invoked (if need).
static void
lcdTear_VsyncModeVsyncIntCallback(kal_uint32 port_id)
{
  //Do nothing for this mode.
  return;
}

static void
lcdTear_VsyncModeStart(kal_uint32 port_id, kal_bool waiting)
{
  lcdTearCtrlBlk *pCtrlBlk;
  kal_uint32 save_irq_mask;

  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];

  if (pCtrlBlk->_busy) ASSERT(0); //WFC shall make sure the next request will not be submited to WFD if the current req is processing

  if ((kal_query_systemInit() == KAL_TRUE) || 
      (LCDTEAR_NO_SYNC == pCtrlBlk->usedLcdSyncMode))
  {
    //Scheduler is not ready... update to LCM ASAP
    if (pCtrlBlk->lcdTearCallback)
    {
      pCtrlBlk->lcdTearCallback((void*)pCtrlBlk->lcdTearCallbackPara[0], (void*)pCtrlBlk->lcdTearCallbackPara[1], (kal_uint32)pCtrlBlk->lcdTearCallbackPara[2]);
    }
    return;
  }
  
  pCtrlBlk->_busy = KAL_TRUE;
  pCtrlBlk->lcdTESyncBlockingReq = waiting;
  if(pCtrlBlk->usedLcdSyncMode == LCDTEAR_NO_SYNC)
  {
    save_irq_mask = SaveAndSetIRQMask();
    DISABLE_LCD_TE_DETECT();
    RestoreIRQMask(save_irq_mask);
  }
  else
  {
    save_irq_mask = SaveAndSetIRQMask();
    ENABLE_LCD_TE_DETECT();
    RestoreIRQMask(save_irq_mask);
  }

  if (pCtrlBlk->lcdTearCallback)
  {
    pCtrlBlk->lcdTearCallback((void*)pCtrlBlk->lcdTearCallbackPara[0], (void*)pCtrlBlk->lcdTearCallbackPara[1], (kal_uint32)pCtrlBlk->lcdTearCallbackPara[2]);
  }
  pCtrlBlk->_busy = KAL_FALSE;
}

/******************************************************************
*******************************************************************/

/******************************************************************
* When timer time out, start the blt request.
*******************************************************************/
#if defined(LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE_SUPPORT) || defined(LCDTEAR_HW_EINT_VSYNC_SW_DELAY_TIME_MODE_SUPPORT) 
static void
lcdTear_SwTimerDelayTimeOutCallback(void* para)
{
  kal_uint32 delayed_tick;
  kal_uint32 save_irq_mask;
  lcdTearCtrlBlk *pCtrlBlk;
  lcdTearSwTeSyncCtrlBlk *pswSyncCtrlBlk;

  //Before swTESyncTimerExpired setting to TRUE, we hope no ISR is invoked.
  save_irq_mask = SaveAndSetIRQMask();
  pCtrlBlk = (lcdTearCtrlBlk *) para;
  if (NULL == pCtrlBlk) ASSERT(0);

  pswSyncCtrlBlk = &pCtrlBlk->swTESyncCtrlBlk;
  pswSyncCtrlBlk->swTESyncTimerExpired = KAL_TRUE;
  RestoreIRQMask(save_irq_mask);

  if (KAL_TRUE == pswSyncCtrlBlk->swTESyncEnable)
  {
    delayed_tick = drv_get_duration_tick(pswSyncCtrlBlk->swTESyncVsyncTime, drv_get_current_time());
    if ((delayed_tick * 30) >= pswSyncCtrlBlk->swTESyncDelayTime)//us,30=1000/32.768
    {
      lcdTear_trace(LCDTEAR_SW_TIMER_DELAY_______TIMEOUT_CB);

      save_irq_mask = SaveAndSetIRQMask();
      pswSyncCtrlBlk->swTESyncTimerStart = KAL_FALSE;
      //if(pswSyncCtrlBlk->swTESyncStartTrigger)
      {
        //pswSyncCtrlBlk->swTESyncStartTrigger = KAL_FALSE;
        RestoreIRQMask(save_irq_mask);

        DISABLE_LCD_TE_DETECT();
        STOP_LCD_TRANSFER;    ///Bin: we stop LCD transfer here

        if ((KAL_FALSE == pCtrlBlk->lcdTESyncBlockingReq))
        {
          if (pCtrlBlk->lcdTearCallback)
          {
            lcdTear_trace(LCDTEAR_SW_TIMER_DELAY______________BLT);

            /*
            ** For non-blocking request:
            ** do blt here because we has no other context to run blt,
            */
            pCtrlBlk->lcdTearCallback((void*)pCtrlBlk->lcdTearCallbackPara[0], (void*)pCtrlBlk->lcdTearCallbackPara[1], (kal_uint32)pCtrlBlk->lcdTearCallbackPara[2]);
          }
        }
        else //if (KAL_TRUE == pCtrlBlk->lcdTESyncBlockingReq)
        {
          lcdTear_trace(LCDTEAR_SW_TIMER_DELAY__SET_VSYNC_EVENT);
          RestoreIRQMask(save_irq_mask);

          /*
          ** For blocking request:
          ** Because ISR can't use any sync-object or busy waiting,
          ** (blocking req shall wait until blt finish)
          ** we will wakeup caller, and do blt in caller' task.
          ** lcdTear_SwTimerDelayModeStart will continue to handle blt.
          */
          kal_set_eg_events(pCtrlBlk->swTESyncCtrlBlk.swTESyncEvent, LCDTEAR_HW_VSYNC_SW_DELAY__EXPIRED_EVENT, KAL_OR);
        }

        pCtrlBlk->_busy = KAL_FALSE;
      }
      //else
      //{
      //  RestoreIRQMask(save_irq_mask);  //shall not happen...
      //}
    }
    else
    {
      //delaytime interval is not expired
      //each kal tick(4.615ms) to check if lcd controller can update GRAM or not
      kal_cancel_timer(pswSyncCtrlBlk->swTESyncTimer);
      kal_set_timer(pswSyncCtrlBlk->swTESyncTimer, (kal_timer_func_ptr)lcdTear_SwTimerDelayTimeOutCallback, pCtrlBlk, 1, 0);
    }
  }

}


static void
_lcdTear_SwTimerDelayVsyncISR(lcdTearCtrlBlk *pCtrlBlk)
{
  kal_uint32 save_irq_mask;
  kal_uint32 sync_lcm_hisr_time;
  lcdTearSwTeSyncCtrlBlk *pswSyncCtrlBlk;

  pswSyncCtrlBlk = &pCtrlBlk->swTESyncCtrlBlk;
  lcdTear_trace(LCDTEAR_SW_TIMER_DELAY________VSYNC_ISR);

  pswSyncCtrlBlk->swTESyncVsyncTime = drv_get_current_time();
  if (KAL_TRUE == pswSyncCtrlBlk->swTESyncEnable)
  {
    save_irq_mask = SaveAndSetIRQMask();
    pswSyncCtrlBlk->swTESyncTimerExpired = KAL_FALSE;
    RestoreIRQMask(save_irq_mask);
	 
    /*
    ** For EINT_VSYNC_SW_TIMER_DELAYT_TIME_MODE, after receive TE signal,  
    ** disable Eint to reduce system overhead of invoking this Eint ISR handler...
    */
    if (LCDTEAR_HW_EINT_VSYNC_SW_DELAY_TIME_MODE == pCtrlBlk->usedLcdSyncMode)
    {
      EINT_Mask(pswSyncCtrlBlk->swTESyncChannel);
    }

    //assume 70 fps lcm refresh rate  (14.3ms per frame)
    if(pswSyncCtrlBlk->swTESyncDelayTime == 0)
    {
      lcdTear_SwTimerDelayTimeOutCallback(pCtrlBlk);
    }
    else
    {
      /*
      ** each kal tick(4.615ms) to check if lcd controller can update GRAM or not
      */
      kal_cancel_timer(pswSyncCtrlBlk->swTESyncTimer);
      lcdTear_trace(LCDTEAR_SW_TIMER_DELAY_____CANCLE_TIMER);
      if(pswSyncCtrlBlk->swTESyncTimerStart)
      {
        lcdTear_trace(LCDTEAR_SW_TIMER_DELAY____REENTRY_VSYNC);
        //lcd_sw_sync_lcm_partial_kal_timer_start_but_no_toggle_hw_count++;

        /*
        ** swTESyncTimerStart shall be set to FALSE in
        ** lcdTear_EintSyncSwTimerDelayCallback.
        ** If swTESyncTimerStart is TRUE here, it means the next V-sync 
        ** is received. Due to the inaccurace of KAL_TIMER, timer callback
        ** is not be executed yet before V-Sync's Eint ISR handler.
        ** This is a sutiable place to submit this req here to avoid 
        ** other tearing problem.
        */
        pswSyncCtrlBlk->swTESyncDelayTime = 0;
        lcdTear_SwTimerDelayTimeOutCallback(pCtrlBlk);
        return;
      }

      pswSyncCtrlBlk->swTESyncTimerStart = KAL_TRUE;
      {
        kal_uint32 delay = (pswSyncCtrlBlk->swTESyncDelayTime % 4615) ? (1 + pswSyncCtrlBlk->swTESyncDelayTime/4615): (pswSyncCtrlBlk->swTESyncDelayTime/4615);
        lcdTear_trace(LCDTEAR_SW_TIMER_DELAY____SET_TIMER_VAL);
        /*
        ** Set and start the timer.
        */
        kal_set_timer(pswSyncCtrlBlk->swTESyncTimer, (kal_timer_func_ptr)lcdTear_SwTimerDelayTimeOutCallback, pCtrlBlk, delay, 0);
      }
    }
  }
  else
  {
    //lcd_sw_sync_lcm_partial_kal_timer_start_but_no_toggle_hw_count = 0;
  }
}

static void
lcdTear_SwTimerDelayISR_MainPort(void)
{
  _lcdTear_SwTimerDelayVsyncISR(&lcdTear_cnxt[0]);
}

static void
lcdTear_SwTimerDelayISR_SubPort(void)
{
  _lcdTear_SwTimerDelayVsyncISR(&lcdTear_cnxt[1]);
}

static lcdTearErrorCode
lcdTear_SwTimerDelayModeInit(kal_uint32 port_id)
{
  lcdTearCtrlBlk *pCtrlBlk;
  void (*SwTimerDelayISR)(void);

  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];

  if (NULL == pCtrlBlk->swTESyncCtrlBlk.swTESyncTimer)
  {
    pCtrlBlk->swTESyncCtrlBlk.swTESyncTimer = kal_create_timer("LCDSyncLCMTimer");
  }

  if (NULL == pCtrlBlk->swTESyncCtrlBlk.swTESyncEvent)
  {
    pCtrlBlk->swTESyncCtrlBlk.swTESyncEvent = kal_create_event_group("LCDSyncLCMEvent");
  }

  pCtrlBlk->swTESyncCtrlBlk.swTESyncEnable = KAL_TRUE;

  if (LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE == pCtrlBlk->usedLcdSyncMode)
  {
    return LCDTEAR_ERROR_NONE;
  }

  //custom_sync_lcm_eint_setting(&pCtrlBlk->swTESyncCtrlBlk.swTESyncPolarity);
  if(pCtrlBlk->lcmVsyncActiveEdge == LCM_TE_RISING_EDGE)
  {
    pCtrlBlk->swTESyncCtrlBlk.swTESyncPolarity = KAL_TRUE;
  }
  else
  {
    pCtrlBlk->swTESyncCtrlBlk.swTESyncPolarity = KAL_FALSE;
  }

  pCtrlBlk->swTESyncCtrlBlk.swTESyncCurrentPolarity = pCtrlBlk->swTESyncCtrlBlk.swTESyncPolarity;

  pCtrlBlk->swTESyncCtrlBlk.swTESyncChannel = custom_eint_get_channel(sync_lcm_chann);

  SwTimerDelayISR = lcdTear_SwTimerDelayISR_MainPort;
  if (LCDTEAR_PORT1 == port_id)
  {
    SwTimerDelayISR = lcdTear_SwTimerDelayISR_SubPort;
  }

  if (EINT_CheckHWDebounce(pCtrlBlk->swTESyncCtrlBlk.swTESyncChannel))
  {
    EINT_Registration(pCtrlBlk->swTESyncCtrlBlk.swTESyncChannel,
                      KAL_FALSE,
                      pCtrlBlk->swTESyncCtrlBlk.swTESyncPolarity,
                      SwTimerDelayISR,
                      KAL_FALSE);
  }
  else
  {
    EXTRA_EINT_Registration(pCtrlBlk->swTESyncCtrlBlk.swTESyncChannel,
                            pCtrlBlk->swTESyncCtrlBlk.swTESyncPolarity,
                            SwTimerDelayISR,
                            KAL_FALSE);
  }

  EINT_Set_Sensitivity(pCtrlBlk->swTESyncCtrlBlk.swTESyncChannel, EDGE_SENSITIVE);
  EINT_Mask(pCtrlBlk->swTESyncCtrlBlk.swTESyncChannel);

  pCtrlBlk->_rsvdTEReg0 = 0;
  GET_TE_CTRL_REG_VAL(pCtrlBlk->_rsvdTEReg0);

  return LCDTEAR_ERROR_NONE;
}


static lcdTearErrorCode
lcdTear_SwTimerDelayModeConfig(
  kal_uint32 port_id,
  kal_uint32 lcm_startY,
  kal_uint32 roiWidth,
  kal_uint32 roiHeight)
{
  kal_uint32 final_hsync_cnt = lcm_startY;
  lcdTearCtrlBlk *pCtrlBlk;
  lcdTearSwTeSyncCtrlBlk *pswSyncCtrlBlk;

  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];
  pswSyncCtrlBlk = &pCtrlBlk->swTESyncCtrlBlk;

  final_hsync_cnt += lcdTear_CalculateHsyncDelayLineCount(pCtrlBlk, roiWidth, roiHeight);
  {
    float delay;
    kal_uint32 temp = (kal_uint32) (final_hsync_cnt * pCtrlBlk->lcmScanTimePerLine);
    delay = (temp % 1000)? (1 + temp/1000) : (temp/1000); //change to us uint
    pswSyncCtrlBlk->swTESyncDelayTime = (kal_uint32) delay; //us
  }
  //kal_set_eg_events(pCtrlBlk->swTESyncCtrlBlk.swTESyncEvent, 0, KAL_AND); //reset event

  return LCDTEAR_ERROR_NONE;
}


//We register this function to WFD in order to wakeup 
//TearManager when LCD TE interrupt is invoked (if need).
static void
lcdTear_SwTimerDelayModeVsyncIntCallback(kal_uint32 port_id)
{
  lcdTearCtrlBlk *pCtrlBlk;

  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];

  //After received Vsync signal, do sw delay to avoid partial update tearing.
  _lcdTear_SwTimerDelayVsyncISR(pCtrlBlk);

  return;
}

static void
lcdTear_SwTimerDelayModeStart(kal_uint32 port_id, kal_bool waiting)
{
  lcdTearCtrlBlk *pCtrlBlk;
  lcdTearSwTeSyncCtrlBlk *pswSyncCtrlBlk;
  kal_uint32 save_irq_mask;

  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];
  pswSyncCtrlBlk = &pCtrlBlk->swTESyncCtrlBlk;


  pswSyncCtrlBlk->swTESyncEnable = KAL_TRUE;
  pCtrlBlk->lcdTESyncBlockingReq = waiting;

  if ((kal_query_systemInit() == KAL_TRUE) || 
      (LCDTEAR_NO_SYNC == pCtrlBlk->usedLcdSyncMode))
  {
    //Scheduler is not ready... update to LCM ASAP
    if (pCtrlBlk->lcdTearCallback)
    {
      pCtrlBlk->lcdTearCallback((void*)pCtrlBlk->lcdTearCallbackPara[0], (void*)pCtrlBlk->lcdTearCallbackPara[1], (kal_uint32)pCtrlBlk->lcdTearCallbackPara[2]);
    }
    return;
  }


  if (pCtrlBlk->_busy) ASSERT(0); //WFC shall make sure the next request will not be submited to WFD if the current req is processing
  pCtrlBlk->_busy = KAL_TRUE;

  lcdTear_trace(LCDTEAR_SW_TIMER_DELAY____________START);

  SET_TE_CTRL_REG_VAL(pCtrlBlk->_rsvdTEReg0);//config TE control registers
  {
    {
      save_irq_mask = SaveAndSetIRQMask();
      pswSyncCtrlBlk->swTESyncEnable = KAL_TRUE;
      //pswSyncCtrlBlk->swTESyncStartTrigger = KAL_TRUE;
      RestoreIRQMask(save_irq_mask);
      kal_set_eg_events(pswSyncCtrlBlk->swTESyncEvent, 0, KAL_AND); //reset event.

      if(LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE == pCtrlBlk->usedLcdSyncMode)
      {
       /*
            ** We will start a timer in TE_INT handler. Thus
            ** we have to enable TE sync, and open TE_INT mask.
            ** Set ROI size to (0, 0) and start LCD, then LCD HW
            ** will send a INT when receive Vsync signal.        
    		  */
        ENABLE_LCD_TE_DETECT();
        ENABLE_LCD_SYNC_COMPLETE_INT;
        DISABLE_LCD_TRANSFER_COMPLETE_INT;
        DISABLE_LCD_ROI_CTRL_CMD_FIRST;
        LCD_SET_ROI_SIZE(0,0);
        START_LCD_TRANSFER;
      }
      else //if (LCDTEAR_HW_EINT_VSYNC_SW_DELAY_TIME_MODE == pCtrlBlk->usedLcdSyncMode)
      {

        /*
        ** We will use EINT to receive VSync signal.
        ** LCD HW TE function shall be disabled at this case.
        ** And open EINT mask for this EINT pin.
        */
        DISABLE_LCD_TE_DETECT();
        EINT_AckInt(pCtrlBlk->swTESyncCtrlBlk.swTESyncChannel);
        EINT_UnMask(pCtrlBlk->swTESyncCtrlBlk.swTESyncChannel);
      }
    }

    if (KAL_TRUE == waiting) //Blocking request
    {
      kal_uint32 event_group = 0;

      /*
      ** Block caller here.
      ** Until timer timeout, we can start blt this request to LCD.
      ** Due to this request has sync Vsyn done, we need to disable TE sycn here.
      ** The LCDTEAR_HW_VSYNC_SW_DELAY__EXPIRED_EVENT is triggered in
      ** SWDelayTimer's timeout callback function.
      */
      kal_retrieve_eg_events(pswSyncCtrlBlk->swTESyncEvent,
                             LCDTEAR_HW_VSYNC_SW_DELAY__EXPIRED_EVENT,
                             KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

      DISABLE_LCD_TE_DETECT();
      if (pCtrlBlk->lcdTearCallback) //Start LCD to update
      {
        lcdTear_trace(LCDTEAR_SW_TIMER_DELAY______________BLT);
        pCtrlBlk->lcdTearCallback((void*)pCtrlBlk->lcdTearCallbackPara[0], (void*)pCtrlBlk->lcdTearCallbackPara[1], (kal_uint32)pCtrlBlk->lcdTearCallbackPara[2]);
      }
    }
    else //if (KAL_FALSE == waiting)
    {
      lcdTear_trace(LCDTEAR_SW_TIMER_DELAY_____NONBLOCK_REQ);
    }
  }
}
#endif // defined(LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE_SUPPORT) || defined(LCDTEAR_HW_EINT_VSYNC_SW_DELAY_TIME_MODE_SUPPORT) 
/******************************************************************
*******************************************************************/
#if defined(LCDTEAR_HW_SCAN_LINE_MODE_SUPPORT) 
static lcdTearErrorCode
lcdTear_ScanLineModeInit(kal_uint32 port_id)
{
  return LCDTEAR_ERROR_NONE;
}

static lcdTearErrorCode
lcdTear_ScanLineModeConfig(
  kal_uint32 port_id,
  kal_uint32 lcm_startY,
  kal_uint32 roiWidth,
  kal_uint32 roiHeight)
{
  return LCDTEAR_ERROR_NONE;
}

//We register this function to WFD in order to wakeup TearManager when LCD TE interrupt is invoked (if need).
static void
lcdTear_ScanLineModeVsyncIntCallback(kal_uint32 port_id)
{
  return;
}

static void
lcdTear_ScanLineModeStart(kal_uint32 port_id, kal_bool waiting)
{

}
#endif  //    defined(LCDTEAR_HW_SCAN_LINE_MODE_SUPPORT) 
/******************************************************************
* Export APIs
*******************************************************************/
lcdTearErrorCode
lcdTear_Init(
  kal_uint32 port_id,
  LCD_Funcs* ifFuncTable,
  LCD_IOCTRL_DEVICE_IF_T *if_set)
{
  //kal_uint32 i;
  lcdTearCtrlBlk *pCtrlBlk;
  LCDTearInitPrimitieves* pinitPrimitieves;

  if (!ifFuncTable) ASSERT(0);
  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];

  //reset HW
  RESET_TE_SYNC_CONTROL_REG();
  ENABLE_LCD_TE_DETECT();
  pCtrlBlk->lcmVsyncActiveEdge = LCM_TE_FALLING_EDGE;
  pCtrlBlk->usedLcdSyncMode = LCDTEAR_MODE_RSVD;

  pinitPrimitieves = &pCtrlBlk->lcdTEInitPrimitiviesTab;
  lcdTear_HookInitPrimitives(port_id, pinitPrimitieves);

  pCtrlBlk->ifFuncTable = ifFuncTable;
  lcdTear_GetCapabilityAndPara(port_id, ifFuncTable, if_set);

  //The 2 functions must be called after lcdTear_GetCapabilityAndPara(~)
  pCtrlBlk->lcdTEInitPrimitiviesTab.SetSyncModePriority(port_id);
  pCtrlBlk->lcdTEInitPrimitiviesTab.SetSyncModeSupportCapability(port_id);

  {
	  if(_wfd_lcd_port[port_id].config.tearControlMode == WFD_Tear_Control_MODE_1TE_MTK) //1te mode
		_wfd_lcd_port[port_id].config.portTearFreeRefreshRate = _wfd_lcd_port[port_id].config.refreshRate; 
	  else //2te mode
	  {
	  	  float hwTheoryRefreshTime; 
		  hwTheoryRefreshTime = LCD_WIDTH * LCD_HEIGHT * pCtrlBlk->lcdPixelTransitionTime / 1000000; //ms  
		  _wfd_lcd_port[port_id].config.portTearFreeRefreshRate = 1000 / ((kal_int32)hwTheoryRefreshTime + 1000/_wfd_lcd_port[port_id].config.refreshRate); //uint: fps
	  }
  }
  // Bin: for serial LCM, tearing mode does not support  delay mechanism or frame marker or VH sync
  /*if(if_set->if_type == LCD_IF_TYPE_DBI_SERIAL)
  {
      for (i = 0; i < LCDTEAR_AVAILABLE_SYNC_MODE_COUNT; i++)
      {
        if(pCtrlBlk->lcdSyncModePriority[i] == LCDTEAR_HW_VSYNC_HW_DELAY_TIME_MODE ||
           pCtrlBlk->lcdSyncModePriority[i] == LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE ||
           pCtrlBlk->lcdSyncModePriority[i] == LCDTEAR_HW_VHSYNC_MODE ||
           pCtrlBlk->lcdSyncModePriority[i] == LCDTEAR_HW_EINT_VSYNC_SW_DELAY_TIME_MODE ||
           pCtrlBlk->lcdSyncModePriority[i] == LCDTEAR_HW_VSYNC_HW_FRAME_MARKER_MODE 
           )
        {
           pCtrlBlk->lcdSyncModePriority[i] = LCDTEAR_HW_VSYNC_MODE;
        }
      }
  }*/
  
  #if defined(LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE_SUPPORT) || defined(LCDTEAR_HW_EINT_VSYNC_SW_DELAY_TIME_MODE_SUPPORT) 
  if (NULL == pCtrlBlk->swTESyncCtrlBlk.swTESyncTimer)
  {
    if (0 == port_id) //MAIN_LCD
    {
      pCtrlBlk->swTESyncCtrlBlk.swTESyncTimer = kal_create_timer("LCDSyncLCMTimer0");
    }
    else
    {
      pCtrlBlk->swTESyncCtrlBlk.swTESyncTimer = kal_create_timer("LCDSyncLCMTimer1");
    }
  }
  #endif

  #if 0 //Matt: shouldn't cheat here to disable chip's LCD sync_mode capability according to LCM's capability
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

  lcdTear_ChooseSuitableSyncMode();
  ///apply TE edge setting
  if (LCM_TE_FALLING_EDGE == pCtrlBlk->lcmVsyncActiveEdge)
  {
     SET_TE_FALLING_DETECT();
  }
  else
  {
     SET_TE_RISING_DETECT();
  }

  return LCDTEAR_ERROR_NONE;
}

lcdTearErrorCode
lcdTear_GetSyncPrimitives(kal_uint32 port_id, LCDTearSyncModePrimitives *pSyncPrimitives)
{
  lcdTearCtrlBlk *pCtrlBlk;

  if (NULL == pSyncPrimitives) ASSERT(0);
  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];

  switch (pCtrlBlk->usedLcdSyncMode)
  {
    #if defined(LCDTEAR_HW_SCAN_LINE_MODE_SUPPORT) 
    case LCDTEAR_HW_SCAN_LINE_MODE:
    {
      pSyncPrimitives->Init = lcdTear_ScanLineModeInit;
      pSyncPrimitives->Config = lcdTear_ScanLineModeConfig;
      pSyncPrimitives->Start = lcdTear_ScanLineModeStart;
      pSyncPrimitives->VsyncIntCallback = lcdTear_ScanLineModeVsyncIntCallback;
      break;
    }
    #endif

    #if defined(LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE_SUPPORT) || defined(LCDTEAR_HW_EINT_VSYNC_SW_DELAY_TIME_MODE_SUPPORT) 
    case LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE:
    case LCDTEAR_HW_EINT_VSYNC_SW_DELAY_TIME_MODE:
    {
      pSyncPrimitives->Init = lcdTear_SwTimerDelayModeInit;
      pSyncPrimitives->Config = lcdTear_SwTimerDelayModeConfig;
      pSyncPrimitives->Start = lcdTear_SwTimerDelayModeStart;
      pSyncPrimitives->VsyncIntCallback = lcdTear_SwTimerDelayModeVsyncIntCallback;
      break;
    }
    #endif

    case LCDTEAR_HW_VSYNC_MODE:
    case LCDTEAR_HW_VSYNC_HW_FRAME_MARKER_MODE:
    case LCDTEAR_HW_VSYNC_HW_DELAY_TIME_MODE:
    case LCDTEAR_HW_VHSYNC_MODE:
    default:  /// LCDTEAR_NO_SYNC
    {
      pSyncPrimitives->Init = lcdTear_VsyncModeInit;
      pSyncPrimitives->Config = lcdTear_VsyncModeConfig;
      pSyncPrimitives->Start = lcdTear_VsyncModeStart;
      pSyncPrimitives->VsyncIntCallback = lcdTear_VsyncModeVsyncIntCallback;
      break;
    }
  }

  return LCDTEAR_ERROR_NONE;
}

//WFD register the callback fuction which will be executed when VHsync is receive/timer expired.
//This function shall be called for each update to LCM.
lcdTearErrorCode
lcdTear_UserRegisterCallback(
  kal_uint32 port_id,
  LCDTEAR_CALLBACK  lcdTearCallback,
  kal_uint32 *lcdTearCallbackPara,
  kal_uint32 lcdTearCallbackParaCnt)
{
  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  if (lcdTearCallbackParaCnt > LCDTEAR_CALLBACK_PARA_COUNT) ASSERT(0);

  lcdTear_cnxt[port_id].lcdTearCallback = lcdTearCallback;
  kal_mem_cpy(lcdTear_cnxt[port_id].lcdTearCallbackPara, lcdTearCallbackPara, sizeof(lcdTear_cnxt[port_id].lcdTearCallbackPara));
  return LCDTEAR_ERROR_NONE;
}

kal_bool
lcdTear_IsEnableVsyncIntMask(kal_uint32 port_id)
{
  lcdTearCtrlBlk *pCtrlBlk;

  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];

  if (LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE == pCtrlBlk->usedLcdSyncMode)
  {
    return KAL_TRUE;
  }

  return KAL_FALSE;
}


#endif //DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT

#endif //#if defined(__MTK_TARGET__)

