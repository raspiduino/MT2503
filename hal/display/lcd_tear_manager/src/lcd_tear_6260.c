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
 *    This file is the body of MT6260 LCD Tear Control driver.
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
 * 01 21 2014 edwardyc.lin
 * removed!
 *
 * 11 14 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 * 
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__MTK_TARGET__)

#include "drv_comm.h"
#include "kal_release.h"
#include "lcd_if_hw.h"
//#include "lcd_if.h"
#include "lcd_sw.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"

#if defined(DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT)

#include "lcd_tear_manager\inc\lcd_tear_manager.h"
#include "lcd_tear_manager\inc\lcd_tear_manager_internal.h"
#include "wfd\inc\Wfd_common.h"
#include "wfd\inc\Wfd.h"
#include "custom_EMI_release.h"

//1 Owner Shall Implement/Review The 4 Functions 

#if defined(DRV_LCD_MT6260_SERIES)
extern lcdTearCtrlBlk lcdTear_cnxt[ATTACHED_LCM_COUNT]; //ATTACHED_LCM_CNT
extern WFD_PORT _wfd_lcd_port[WFD_ATTACHED_PORT_COUNT];

static lcdTearErrorCode
lcdTear_SetSyncModePriority_6260(kal_uint32 port_id)
{
  //Implement this function for each chip, if need.
  //The following is an example.
  lcdTearCtrlBlk *pCtrlBlk;

  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];


  if (LCDTEAR_PORT0 == port_id)
  {
  	#if ((defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)) && defined(__EMI_CLK_130MHZ__) && !defined(__AST_TL1_TDD__))//this option is for TKPSRAM and NO TD Project
  	if ( LCM_IOCTRL_OK == pCtrlBlk->ifFuncTable->IOCTRL(LCM_IOCTRL_QUERY_TEAR_CONTROL_FOR_ONE_TE_MODE,NULL))//this is for LCM support one TE mode
   	{	
		_wfd_lcd_port[port_id].config.tearControlMode = WFD_Tear_Control_MODE_1TE_MTK;
  		pCtrlBlk->lcdSyncModePriority[0] = LCDTEAR_HW_VSYNC_MODE; //LCDTEAR_HW_VHSYNC_MODE:NOT SUPPORT
	    pCtrlBlk->lcdSyncModePriority[1] = LCDTEAR_HW_VSYNC_MODE;
	    pCtrlBlk->lcdSyncModePriority[2] = LCDTEAR_HW_VSYNC_MODE;
	    pCtrlBlk->lcdSyncModePriority[3] = LCDTEAR_HW_VSYNC_MODE;
	    pCtrlBlk->lcdSyncModePriority[4] = LCDTEAR_NO_SYNC;
	    pCtrlBlk->lcdSyncModePriority[5] = LCDTEAR_NO_SYNC;
	    pCtrlBlk->lcdSyncModePriority[6] = LCDTEAR_NO_SYNC;
	    pCtrlBlk->lcdSyncModePriority[7] = LCDTEAR_NO_SYNC;
  	}
	else
	#endif
	{
		_wfd_lcd_port[port_id].config.tearControlMode = WFD_Tear_Control_MODE_2TE_MTK;
        pCtrlBlk->lcdSyncModePriority[0] = LCDTEAR_HW_VSYNC_HW_DELAY_TIME_MODE; //LCDTEAR_HW_VHSYNC_MODE:NOT SUPPORT
        pCtrlBlk->lcdSyncModePriority[1] = LCDTEAR_HW_VSYNC_HW_FRAME_MARKER_MODE;
        pCtrlBlk->lcdSyncModePriority[2] = LCDTEAR_HW_VSYNC_MODE;
        pCtrlBlk->lcdSyncModePriority[3] = LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE;
        pCtrlBlk->lcdSyncModePriority[4] = LCDTEAR_NO_SYNC;
        pCtrlBlk->lcdSyncModePriority[5] = LCDTEAR_NO_SYNC;
        pCtrlBlk->lcdSyncModePriority[6] = LCDTEAR_NO_SYNC;
        pCtrlBlk->lcdSyncModePriority[7] = LCDTEAR_NO_SYNC;
    }    
    return LCDTEAR_ERROR_NONE;
  }
#ifdef DUAL_LCD
  else if (LCDTEAR_PORT1 == port_id)
  {
      pCtrlBlk->lcdSyncModePriority[0] = LCDTEAR_HW_EINT_VSYNC_SW_DELAY_TIME_MODE;
      pCtrlBlk->lcdSyncModePriority[1] = LCDTEAR_NO_SYNC;
      pCtrlBlk->lcdSyncModePriority[2] = LCDTEAR_NO_SYNC;
      pCtrlBlk->lcdSyncModePriority[3] = LCDTEAR_NO_SYNC;
      pCtrlBlk->lcdSyncModePriority[4] = LCDTEAR_NO_SYNC;
      pCtrlBlk->lcdSyncModePriority[5] = LCDTEAR_NO_SYNC;
      pCtrlBlk->lcdSyncModePriority[6] = LCDTEAR_NO_SYNC;
      pCtrlBlk->lcdSyncModePriority[7] = LCDTEAR_NO_SYNC;
    return LCDTEAR_ERROR_NONE;
  }
#endif
  return LCDTEAR_ERROR_NONE;
}


static lcdTearErrorCode
lcdTear_SetSyncModeSupportCapability_6260(kal_uint32 port_id)
{
  //Implement this function for each chip, if need.
  //The following is an example.
  lcdTearCtrlBlk *pCtrlBlk;

  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];

  kal_mem_set(pCtrlBlk->lcdSyncModeSupportCap, 0, sizeof(pCtrlBlk->lcdSyncModeSupportCap));
  
  if (LCDTEAR_PORT0 == port_id)
  {
    if ((pCtrlBlk->hwTESyncSupport) && (LCM_TE_NONE != pCtrlBlk->lcmSyncSignalMode))
    {
      pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_VSYNC_MODE] = KAL_TRUE;
      pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_VHSYNC_MODE] = KAL_FALSE;
      pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_VSYNC_HW_DELAY_TIME_MODE] = KAL_TRUE;
      if (pCtrlBlk->lcmFrameMarkSupport)
      {
        pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_VSYNC_HW_FRAME_MARKER_MODE] = KAL_TRUE;
      }
      pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE] = KAL_TRUE;

    }
    if ((pCtrlBlk->swTESyncSupport) && (!pCtrlBlk->hwTESyncSupport))
    {
      pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_EINT_VSYNC_SW_DELAY_TIME_MODE] = KAL_TRUE;
    }
    pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_SCAN_LINE_MODE] = KAL_TRUE;
    pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_NO_SYNC] = KAL_TRUE;
    return LCDTEAR_ERROR_NONE;
  }
#ifdef DUAL_LCD
  else if (LCDTEAR_PORT1 == port_id)
  {
    if ((pCtrlBlk->hwTESyncSupport) && (LCM_TE_NONE != pCtrlBlk->lcmSyncSignalMode))
    {
      pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_VSYNC_MODE] = KAL_TRUE;
      pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_VHSYNC_MODE] = KAL_FALSE;
      pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_VSYNC_HW_DELAY_TIME_MODE] = KAL_FALSE;
      if (pCtrlBlk->lcmFrameMarkSupport)
      {
        pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_VSYNC_HW_FRAME_MARKER_MODE] = KAL_TRUE;
      }      
      pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_VSYNC_SW_DELAY_TIME_MODE] = KAL_TRUE;

    }
    if ((pCtrlBlk->swTESyncSupport) && (!pCtrlBlk->hwTESyncSupport))
    {
      pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_EINT_VSYNC_SW_DELAY_TIME_MODE] = KAL_TRUE;
    }
    pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_HW_SCAN_LINE_MODE] = KAL_FALSE;
    pCtrlBlk->lcdSyncModeSupportCap[LCDTEAR_NO_SYNC] = KAL_TRUE;
    return LCDTEAR_ERROR_NONE;
  }
#endif //#ifdef DUAL_LCD
  return LCDTEAR_ERROR_NONE;
}


static lcdTearErrorCode
lcdTear_SetLCDHwCapabilityAndPara_6260(kal_uint32 port_id)
{
  //Implement this function for each chip, if need.
  //The following is an example.
  lcdTearCtrlBlk *pCtrlBlk;

  if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  pCtrlBlk = &lcdTear_cnxt[port_id];

  pCtrlBlk->lcdVHSyncSupport = KAL_FALSE;
  pCtrlBlk->lcdScanLineSupport = KAL_TRUE;
  pCtrlBlk->lcdDelayTimeSupport = KAL_TRUE;
  return LCDTEAR_ERROR_NONE;  
}

void lcdTear_HookInitPrimitives(kal_uint32 port_id, LCDTearInitPrimitieves *pInitPrimitieves)
{
  if (LCDTEAR_PORT0 == port_id)
  {
   //It is enough for MT6260 to use default primitivies to init LCDTearManager...
   pInitPrimitieves->SetLCDHwCapabilityAndPara = lcdTear_SetLCDHwCapabilityAndPara_6260;
   pInitPrimitieves->SetSyncModePriority = lcdTear_SetSyncModePriority_6260;
   pInitPrimitieves->SetSyncModeSupportCapability = lcdTear_SetSyncModeSupportCapability_6260;
  }
#ifdef DUAL_LCD
  else
  {
   //It is enough for MT6260 to use default primitivies to init LCDTearManager...
   pInitPrimitieves->SetLCDHwCapabilityAndPara = lcdTear_SetLCDHwCapabilityAndPara_6260;
   pInitPrimitieves->SetSyncModePriority = lcdTear_SetSyncModePriority_6260;
   pInitPrimitieves->SetSyncModeSupportCapability = lcdTear_SetSyncModeSupportCapability_6260;
  }
#endif //#ifdef DUAL_LCD
}

void lcdTear_TearingControlforSerialLCM_6260(kal_uint32 port_id)
{
    float ClkWidth, TransferCntPerPixel;
    kal_uint32 IfWidth, lcmFmtBitCnt, transactionCycle,
		       css,csh,wr_1st,wr_2nd,if_period;
	kal_uint32  div2=0;
	kal_uint32 config_reg;
	kal_uint8 if_cs_no;
	kal_bool b3wire,single_a0_mode,start_byte_mode,cs_stay_low_mode,b2_data_lane_mode;
	lcdTearCtrlBlk *pCtrlBlk;

	if (port_id > ATTACHED_LCM_COUNT) ASSERT(0);
  	pCtrlBlk = &lcdTear_cnxt[port_id];


		
		b3wire = pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.if_3wire_mode;
		single_a0_mode = pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.if_single_a0_mode;
		start_byte_mode = pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.if_start_byte_mode;
		cs_stay_low_mode = pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.if_cs_stay_low_mode;
		b2_data_lane_mode = pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.if_2data_lane_mode;
		if_cs_no = pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.if_cs_no;
		//now there is not div2 member var in LCD_IOCTRL_DBI_SERIAL_IF_T
		config_reg = GET_LCD_SERIAL_IF_REG(if_cs_no);
		if(0 == if_cs_no)
		  div2 = (config_reg & LCD_SERIAL_CONFIG_SIF0_CLK_DIV2_BIT)? 1: 0;
		else if(1 == if_cs_no)
		  div2 = (config_reg & LCD_SERIAL_CONFIG_SIF1_CLK_DIV2_BIT)? 1: 0;
		else
		  ASSERT(0);//total 2 serial interface
		//CSHW = 2 cycles when transfer pixel data;CSHW = 4 cycles when transfer commands
		//unit:LCD working cycle:1/104MHz
		//tearing control for pixle data transfer,so if_period=2.
		//CS Stay low mode, will still has 2 cycles between 2 transaction, only saved the CSS and CSH time
		if_period = 2;
	
		css = (pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.if_css_time)*(div2+1)+1;
		csh = (pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.if_csh_time)*(div2+1)+1;
		wr_1st = (pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.scl_wr_1st_count)*(div2+1)+1;
		wr_2nd = (pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.scl_wr_2nd_count)*(div2+1)+1;
		if (b3wire) // for 3wire mode, there may be more type mode mix, so the ifWidht may be different
		{
			if (b2_data_lane_mode)
			{
				IfWidth = pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.if_2data_lane_each_trans_length;
				if (single_a0_mode && !cs_stay_low_mode)//when in single A0 mode, ignore the 1bit in fisrt byte tranfer
				{
					transactionCycle = css+(wr_1st+wr_2nd)*(IfWidth/2)+csh+if_period;
				}
				else if (!single_a0_mode && cs_stay_low_mode)
				{
					transactionCycle = (wr_1st+wr_2nd)*(IfWidth/2+1)+if_period;//the css and csh action only one time, so ignore
				}
				else if (single_a0_mode && cs_stay_low_mode)
				{
					transactionCycle = (wr_1st+wr_2nd)*(IfWidth/2)+if_period;//the css and csh action only one time, so ignore
				}
				else if (!single_a0_mode && !cs_stay_low_mode)
				{
					transactionCycle = css+(wr_1st+wr_2nd)*(IfWidth/2+1)+csh+if_period;
				}
				else
				{
					ASSERT(0); //unknown mode combination
				}
			}
			else
			{
				IfWidth = pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.if_each_trans_length;
				if (single_a0_mode && !cs_stay_low_mode)
				{
					transactionCycle = css+(wr_1st+wr_2nd)*(IfWidth)+csh+if_period;
				}
				else if (!single_a0_mode && cs_stay_low_mode)
				{
					transactionCycle = (wr_1st+wr_2nd)*(IfWidth+1)+if_period;//the css and csh action only one time, so ignore
				}
				else if (single_a0_mode && cs_stay_low_mode)
				{
					transactionCycle = (wr_1st+wr_2nd)*(IfWidth)+if_period;//the css and csh action only one time, so ignore
				}
				else if (!single_a0_mode && !cs_stay_low_mode)
				{
					transactionCycle = css+(wr_1st+wr_2nd)*(IfWidth+1)+csh+if_period;
				}
				else
				{
					ASSERT(0); //unknown mode combination
				}
			}
		}
		else //maybe start byte mode or normal 4wire mode
		{
			if (start_byte_mode)
			{
				IfWidth = pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.if_str_byte_each_trans_length;
				if (cs_stay_low_mode)
				{
					transactionCycle = css+(wr_1st+wr_2nd)*(IfWidth)+csh;//ignore the first start byte 8 bit
				}
				else
				{
					transactionCycle = css+(wr_1st+wr_2nd)*(IfWidth)+csh+if_period+8;
				}
			}
			else
			{
				IfWidth = pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.if_each_trans_length;
				if (cs_stay_low_mode)
				{
					transactionCycle = (wr_1st+wr_2nd)*(IfWidth)+if_period;//the css and csh action only one time, so ignore
				}
				else
				{
					transactionCycle = css+(wr_1st+wr_2nd)*(IfWidth)+csh+if_period;
				}	
			//TODO: for pixel trasfer pixel data IfWidth=8/9/16/18bits,note 24/32bits case
			}
		}
	
		ClkWidth = 1000000000/(double)pCtrlBlk->lcdIfSetting.if_settings.dbi_serial_if.if_clk_freq; //ns
		pCtrlBlk->lcdClockWidth = ClkWidth; //ns
	
		lcmFmtBitCnt = (LCDTEAR_PORT0_OUTPUT_FORMAT & 0x38) >> 3;
		if (LCDTEAR_PORT0 != port_id)
		{
		  if (0xFFFFFFFF == LCDTEAR_PORT1_OUTPUT_FORMAT)
		  {
			ASSERT(0);//return LCDTEAR_BAD_PARAMETER;
		  }
		  lcmFmtBitCnt = (LCDTEAR_PORT1_OUTPUT_FORMAT & 0x38) >> 3;
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
		pCtrlBlk->lcdPixelTransitionTime = TransferCntPerPixel * transactionCycle * ClkWidth;
		pCtrlBlk->lcmScanTimePerLine = (1000000000/(pCtrlBlk->lcmFrameRate * (pCtrlBlk->lcmHeight + pCtrlBlk->lcmBackPorch + pCtrlBlk->lcmFrontPorch))); //ns
		//lcmVsyncWidth for VH sync mode,but MT6255 not support VH sync tear mode.
		pCtrlBlk->lcmVsyncWidth = (kal_uint32) ((pCtrlBlk->lcmVsyncWidth * 1000) / ClkWidth);  //clock counts

}


#endif //MT6260


#endif //DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT

#endif //#if defined(__MTK_TARGET__)

