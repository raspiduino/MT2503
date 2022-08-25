/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *   lcd.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   This Module defines the LCD driver.
 *
 * Author:
 * -------
 *  
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_comm.h"
#include "reg_base.h"
#include "lcd_sw_inc.h"
#include "lcd_sw.h"
#include "lcd_hw.h"
/*Serial interface*/
#include "lcd_if_hw.h"
#include "lcm_if.h"
#include "lcd_if.h"
//#include "eint.h"
#include "dcl.h"

#ifdef LQT_SUPPORT/*Do not remove LQT code segment*/
#include "lcd_lqt.h"
extern kal_uint8 lcd_at_mode;
extern kal_bool lcd_update_permission;
#endif/*LQT_SUPPORT*/
//#endif

//kal_uint16 lcd_display_mode_shadow,lcd_power_ctrl_shadow,lcd_gate_driver_shadow1;
kal_uint16 lcd_entry_mode_shadow=0x9000,lcd_gate_driver_shadow2;
kal_bool  lcd_assert_fail=KAL_FALSE;
//kal_uint16 ST7789S_supported_frame_rate[3]={70,60,50};
kal_uint16 ST7789S_back_porch = 2;

volatile kal_uint32 ranesis_delay;

extern  void lcm_read_from_gram(kal_uint8* buffer);
#ifdef DUAL_LCD
kal_uint16 lcd_power_ctrl_shadow1;
#endif

void LCD_Delay(kal_uint32 delay_count)
{
  volatile kal_uint32 delay;
  for (delay =0;delay <(delay_count*4);delay++) {}
}

extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);

void Delayms(kal_uint16 data)
{
    kal_uint32 time1;
    
    time1 = drv_get_current_time();
    while (drv_get_duration_ms(time1) <= data);
}

void LCD_set_reg_main(kal_uint16 reg_index, kal_uint16 reg_data)
{
    LCD_CtrlWrite_ST7789S(reg_index);
    LCD_DataWrite_ST7789S(reg_data);
}

void spi_ini(void)
{

}

void init_lcd_interface(void)
{
  //Serial Clock:
  SET_LCD_SERIAL_CLOCK(0, LCD_SERIAL_CLOCK_132MHZ);
  //SET_LCD_SERIAL_CLOCK(0, LCD_SERIAL_CLOCK_26MHZ);

/*
  #if defined(SERIAL_LCM_2_DATA_LINE_PROTOCOL)
    ENABLE_LCD_SERIAL0_2PIN;
    #if defined(MAIN_LCD_16BIT_MODE)
      SET_LCD_SERIAL0_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_16);
    #elif defined(MAIN_LCD_18BIT_MODE)
      SET_LCD_SERIAL0_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_18);
    #endif
  #endif
*/

  #if defined(SLCD_FEATURE_SINGLE_A0_MODE)
    ENABLE_LCD_SERIAL0_SINGLE_A0;
  #else
    DISABLE_LCD_SERIAL0_SINGLE_A0;
  #endif

  #if defined(SLCD_FEATURE_CS_STAY_LOW_MODE)
    ENABLE_LCD_SERIAL0_CS_STAY_LOW;
  #else
    DISABLE_LCD_SERIAL0_CS_STAY_LOW;
  #endif


  //Define serial LCM work mode here
  #if (defined(SERIAL_LCM_4WIRE_1_DATA_LANE))
    DISABLE_LCD_SERIAL0_3WIRE;
  #elif (defined(SERIAL_LCM_3WIRE_1_DATA_LANE)||defined(SERIAL_LCM_3WIRE_2_DATA_LANE))
    ENABLE_LCD_SERIAL0_3WIRE;
    DISABLE_LCD_SERIAL0_SDI;
  #endif
    
  ENABLE_LCD_SERIAL_IF_HW_CS;//HW CS

  #if defined(MAIN_LCD_16BIT_MODE)
    SET_LCD_SERIAL0_IF_SIZE(LCD_SCNF_IF_WIDTH_16);
  #elif defined(MAIN_LCD_18BIT_MODE)
    SET_LCD_SERIAL0_IF_SIZE(LCD_SCNF_IF_WIDTH_18);
  #elif defined(MAIN_LCD_8BIT_MODE)
    SET_LCD_SERIAL0_IF_SIZE(LCD_SCNF_IF_WIDTH_8);
  #endif

  //Timing need tuning
  SET_LCD_SERIAL_IF_CSS(0, 0);  //
  SET_LCD_SERIAL_IF_CSH(0, 0);
  
  SET_LCD_SERIAL_IF_WR_1ST(0,0);//
  SET_LCD_SERIAL_IF_WR_2ND(0,0);
  SET_LCD_SERIAL_IF_RD_1ST(0,7);//
  SET_LCD_SERIAL_IF_RD_2ND(0,7);
  SET_LCD_SERIAL0_IF_SIZE(LCD_SCNF_IF_WIDTH_8);//CMD use 8 bit width

  #if defined(MAIN_LCD_16BIT_MODE_RGB888)
    SET_LCD_SEND_RES_MODE(1);
  #endif

  //Set Driving current
  //set_lcd_driving_current_centralize(LCD_DRIVING_12MA);

  set_lcd_driving_current_serial0_1v8(LCD_DRIVING_12MA);
} /* init_lcd_interface() */

/***********************ST7789S********************************/

void LCD_EnterSleep_ST7789S(void)
{
  #if defined(LQT_SUPPORT)/*Do not remove LQT code segment*/
    if(!(lcd_at_mode==LCD_AT_RELEASE_MODE))
    {
      return;
    }
  #endif /*defined(LQT_SUPPORT))*/	

    LCD_CtrlWrite_ST7789S(0x10);
    Delayms(120); 
}

void LCD_ExitSleep_ST7789S(void)
{
  #if defined(LQT_SUPPORT)/*Do not remove LQT code segment*/
    if(!(lcd_at_mode==LCD_AT_RELEASE_MODE))
    {
      return;
    }
  #endif /*defined(LQT_SUPPORT))*/  

    LCD_CtrlWrite_ST7789S(0x11);
    Delayms(10); // delay time
    LCD_CtrlWrite_ST7789S(0x29);
    Delayms(120); 
}

void LCD_Partial_On_ST7789S(kal_uint16 start_page,kal_uint16 end_page)
{

}

void LCD_Partial_Off_ST7789S(void)
{

}

kal_uint8 LCD_Partial_line_ST7789S(void)
{
  return 1;   /* partial display in 1 line alignment */
}

void LCD_Set_Y_Addr_ST7789S(kal_uint16 start_row, kal_uint16 end_row)
{

}

void LCD_Set_X_Addr_ST7789S(kal_uint16 start_column, kal_uint16 end_column)
{

}

void LCD_blockClear_ST7789S(kal_uint16 x1,kal_uint16 y1,kal_uint16 x2,kal_uint16 y2,kal_uint16 data)
{
  kal_uint16 LCD_x;
  kal_uint16 LCD_y;
  kal_uint8 r_color,g_color,b_color;
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
#endif

  #if (defined(MAIN_LCD_9BIT_MODE)) 
  r_color=((data>>11)&0x1F)<<1; 
  g_color=(data>>5)&0x3F;
  b_color=((data)&0x1F)<<1;
  #else
  
  r_color=((data&0xF800)>>10)|(data>>15); /* transfer to RGB666 */
  g_color=((data>>5)&0x3F);
  b_color=((data&0x1F)<<1)|((data>>4)&0x1);
  #endif
  
  
  LCD_CtrlWrite_ST7789S(0x2A);
  LCD_DataWrite_ST7789S((x1&0xFF00)>>8);
  LCD_DataWrite_ST7789S(x1&0xFF);
  LCD_DataWrite_ST7789S((x2&0xFF00)>>8);
  LCD_DataWrite_ST7789S(x2&0xFF);
  
  LCD_CtrlWrite_ST7789S(0x2B);
  LCD_DataWrite_ST7789S((y1&0xFF00)>>8);
  LCD_DataWrite_ST7789S(y1&0xFF);
  LCD_DataWrite_ST7789S((y2&0xFF00)>>8);
  LCD_DataWrite_ST7789S(y2&0xFF);
  
  LCD_CtrlWrite_ST7789S(0x2C);

#if defined(SERIAL_LCM_2_DATA_LINE_PROTOCOL)		// 2-data lane, should change to 1-data lane to do block clear
	for(LCD_y=y1;LCD_y<=y2;LCD_y++)
	{
	  for(LCD_x=x1;LCD_x<=x2;LCD_x++)
	  {
		*((volatile unsigned char *) MAIN_LCD_DATA_ADDR)=(kal_uint8)((data&0xFF00)>>8);
		*((volatile unsigned char *) MAIN_LCD_DATA_ADDR)=(kal_uint8)(data&0xFF);	  
	  }
	}


#else  
  for(LCD_y=y1;LCD_y<=y2;LCD_y++)
  {
    for(LCD_x=x1;LCD_x<=x2;LCD_x++)
    {
    #if (defined(MAIN_LCD_8BIT_MODE))
      *((volatile unsigned char *) MAIN_LCD_DATA_ADDR)=(kal_uint8)((data&0xFF00)>>8);
      *((volatile unsigned char *) MAIN_LCD_DATA_ADDR)=(kal_uint8)(data&0xFF);      
    #elif (defined(MAIN_LCD_9BIT_MODE))
      *((volatile unsigned short *) MAIN_LCD_DATA_ADDR)=((r_color<<3)|(g_color>>3));
      *((volatile unsigned short *) MAIN_LCD_DATA_ADDR)=((g_color&0x38)<<6)|b_color ;
    #elif (defined(MAIN_LCD_16BIT_MODE) || defined(MAIN_LCD_18BIT_MODE))
      *((volatile unsigned int *) MAIN_LCD_DATA_ADDR)=(r_color<<12)|(g_color<<6)|b_color;
    #endif
    }
  }
#endif  
}

void LCD_ClearAll_ST7789S(kal_uint16 data)
{
   LCD_blockClear_ST7789S(0,0,LCD_WIDTH-1,LCD_HEIGHT-1,data);
}

kal_uint32 device_code;

void LCD_Init_ST7789S(kal_uint32 bkground, void **buf_addr)
{  
  // Do HW Reset
	GPIO_ModeSetup(45,1);		// restore LRSTB mode
  SET_LCD_CTRL_RESET_PIN;
  Delayms(200);		// keep 200ms high
 
  CLEAR_LCD_CTRL_RESET_PIN;
  Delayms(10);
  SET_LCD_CTRL_RESET_PIN;
  Delayms(120);

  // sleep out
  LCD_CtrlWrite_ST7789S(0x11);
  Delayms(10);

  LCD_CtrlWrite_ST7789S(0xD0);
  LCD_DataWrite_ST7789S(0xA4);
  LCD_DataWrite_ST7789S(0xA1);

  LCD_CtrlWrite_ST7789S(0xE8);
  LCD_DataWrite_ST7789S(0x93);

  // VCOM setting
  LCD_CtrlWrite_ST7789S(0xBB);
  LCD_DataWrite_ST7789S(0x27);

  //interface pixel format
  LCD_CtrlWrite_ST7789S(0x3A);
#if defined(MAIN_LCD_16BIT_MODE_RGB565)
  LCD_DataWrite_ST7789S(0x55);
#elif defined(MAIN_LCD_18BIT_MODE_RGB666)
  LCD_DataWrite_ST7789S(0x66);
  //0x66=18bit/pixel,262k pixle format;(240X320)
  //0x55=16bit/pixel,65k pixle format(240X320)
#endif

  // Gamma setting for Tainma 2.4 panel
  LCD_CtrlWrite_ST7789S(0xE0);
  LCD_DataWrite_ST7789S(0xD0);
  LCD_DataWrite_ST7789S(0x00);
  LCD_DataWrite_ST7789S(0x03);
  LCD_DataWrite_ST7789S(0x08);
  LCD_DataWrite_ST7789S(0x0D);
  LCD_DataWrite_ST7789S(0x18);
  LCD_DataWrite_ST7789S(0x2E);
  LCD_DataWrite_ST7789S(0x54);
  LCD_DataWrite_ST7789S(0x3F);
  LCD_DataWrite_ST7789S(0x0C);
  LCD_DataWrite_ST7789S(0x18);
  LCD_DataWrite_ST7789S(0x14);
  LCD_DataWrite_ST7789S(0x14);
  LCD_DataWrite_ST7789S(0x18);

  LCD_CtrlWrite_ST7789S(0xE1);
  LCD_DataWrite_ST7789S(0xD0);
  LCD_DataWrite_ST7789S(0x00);
  LCD_DataWrite_ST7789S(0x03);
  LCD_DataWrite_ST7789S(0x08);
  LCD_DataWrite_ST7789S(0x06);
  LCD_DataWrite_ST7789S(0x25);
  LCD_DataWrite_ST7789S(0x2B);
  LCD_DataWrite_ST7789S(0x44);
  LCD_DataWrite_ST7789S(0x41);
  LCD_DataWrite_ST7789S(0x0C);
  LCD_DataWrite_ST7789S(0x17);
  LCD_DataWrite_ST7789S(0x18);
  LCD_DataWrite_ST7789S(0x13);
  LCD_DataWrite_ST7789S(0x17);

/*
#if defined(SERIAL_LCM_2_DATA_LINE_PROTOCOL)
  // 2 data lane
  LCD_CtrlWrite_ST7789S(0xE7);
  LCD_DataWrite_ST7789S(0x10);
#else
  // 1 data lane
  LCD_CtrlWrite_ST7789S(0xE7);
  LCD_DataWrite_ST7789S(0x00);
#endif
*/
/*
	FRCTRL2 (C6h): Frame Rate Control in Normal Mode
	1. Frame rate=10MHz/(320+FPA[6:0]+BPA[6:0])*(250+RTNA[4:0]*16).
	2. FPA[6:0] and BPA[6:0] are in command B2h
	3. In this frame rate table, FPA[6:0]=0Ch, BPA[6:0]=0Ch


	FRCTRL1 (B3h): Frame Rate Control 1 (In partial mode/ idle colors)
	1. If FRSEN=1, Frame rate in idle mode=10MHz/(320+(FPB[3:0]+BPB[3:0])*4)*(250+RTNB[4:0]*16).
	2. FPB[6:0] and BPB[6:0] are in command B2h
	3. In this frame rate table, FPB[3:0]=03h, BPB[3:0]=03h

	PORCTRL (B2h): Porch Setting

	1st parameter 1 ＃ 1 - 0 BPA6 BPA5 BPA4 BPA3 BPA2 BPA1 BPA0
	2nd parameter 1 ＃ 1 - 0 FPA6 FPA5 FPA4 FPA3 FPA2 FPA1 FPA0
	3rd parameter 1 ＃ 1 - 0 0 0 0 0 0 0 PSEN
	4th parameter 1 ＃ 1 - BPB3 BPB2 BPB1 BPB0 FPB3 FPB2 FPB1 FPB0
	5th parameter 1 ＃ 1 - BPC3 BPC2 BPC1 BPC0 FPC3 FPC2 FPC1 FPC0
*/
	// Porch setting
	LCD_CtrlWrite_ST7789S(0xB2); // Porch setting
	LCD_DataWrite_ST7789S(0x0C);		// FPA
	LCD_DataWrite_ST7789S(0x0C);		// BPA
	LCD_DataWrite_ST7789S(0x0);		// PSEN
	LCD_DataWrite_ST7789S(0x33);		// BPB FPB
	LCD_DataWrite_ST7789S(0x33);		// BPC FPC

  //set TE on
  LCD_CtrlWrite_ST7789S(0x35);//0x35 turn on TE signal,0x34 turn off TE signal
  LCD_DataWrite_ST7789S(0x00); // Set TE Mode = Vsync Only

  //set LCM frame rate
  //ST7789S,
  LCD_CtrlWrite_ST7789S(0xB3);
  LCD_DataWrite_ST7789S(0x00);
  LCD_DataWrite_ST7789S(0x09); // FR for idle mode, 75Hz
  LCD_DataWrite_ST7789S(0x09); // FR for partial mode, 75Hz

  LCD_CtrlWrite_ST7789S(0xC6);
  LCD_DataWrite_ST7789S(0x09); // FR for normal mode, 75Hz

  // clear the screen with black color
  LCD_CtrlWrite_ST7789S(0x2C);
  LCD_ClearAll_ST7789S(0x00);
  
#if defined(SERIAL_LCM_2_DATA_LINE_PROTOCOL)
	ENABLE_LCD_SERIAL0_2PIN;
  #if defined(MAIN_LCD_16BIT_MODE)
	SET_LCD_SERIAL0_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_16);
  #elif defined(MAIN_LCD_18BIT_MODE)
	SET_LCD_SERIAL0_IF_2PIN_SIZE(LCD_SCNF_IF_2PIN_WIDTH_18);
  #endif
	// 2 data lane
	LCD_CtrlWrite_ST7789S(0xE7);
	LCD_DataWrite_ST7789S(0x10);
#endif

  // display on
  LCD_CtrlWrite_ST7789S(0x29);
  Delayms(120);
}

void LCD_PWRON_ST7789S(kal_bool on)
{
   if(on)
   {
      LCD_ExitSleep_ST7789S();
   }
   else
   {
      LCD_EnterSleep_ST7789S();
   }
}

void LCD_SetContrast_ST7789S(kal_uint8 level)
{
}

void LCD_ON_ST7789S(kal_bool on)
{
   if (on)
   {
      LCD_ExitSleep_ST7789S();
   }
   else
   {
      LCD_EnterSleep_ST7789S();
   }
}

void LCD_BlockWrite_ST7789S(kal_uint16 startx,kal_uint16 starty,kal_uint16 endx,kal_uint16 endy)
{
  //__wfd_lcd_RollbackPortIFSetting(0);
  DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
  DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);

  ASSERT(lcd_assert_fail==KAL_FALSE);
  lcd_assert_fail = KAL_TRUE;
  #ifdef LQT_SUPPORT/*Do not remove LQT code segment*/
    if(!lcd_update_permission&&!(lcd_at_mode==LCD_AT_RELEASE_MODE))
    {
      lcd_assert_fail = KAL_FALSE;
      return;//in LQT mode but not update permitted
    }
    if(lcd_update_permission&&!(lcd_at_mode==LCD_AT_RELEASE_MODE))
    {
      startx = 0;
      starty = 0;
      endx = LCD_WIDTH -1;
      endy = LCD_HEIGHT -1; //in LQT mode and update permitted
    }
  #endif /*LQT_SUPPORT*/
  #if defined(MAIN_LCD_16BIT_MODE_RGB888)
    SET_LCD_SEND_RES_MODE(1);
  #endif
  
  LCD_CtrlWrite_ST7789S(0x2A);
  LCD_DataWrite_ST7789S((startx&0xFF00)>>8);
  LCD_DataWrite_ST7789S(startx&0xFF);
  LCD_DataWrite_ST7789S((endx&0xFF00)>>8);
  LCD_DataWrite_ST7789S(endx&0xFF);
  
  LCD_CtrlWrite_ST7789S(0x2B);
  LCD_DataWrite_ST7789S((starty&0xFF00)>>8);
  LCD_DataWrite_ST7789S(starty&0xFF);
  LCD_DataWrite_ST7789S((endy&0xFF00)>>8);
  LCD_DataWrite_ST7789S(endy&0xFF);
  
  LCD_CtrlWrite_ST7789S(0x2C);
  
  ENABLE_LCD_TRANSFER_COMPLETE_INT;
  DISABLE_LCD_ROI_CTRL_CMD_FIRST;
  START_LCD_TRANSFER;
  
  lcd_assert_fail = KAL_FALSE;

}


/***************************** Take Notice *******************************
*************************************************************************/

void LCD_Size_ST7789S(kal_uint16 *out_LCD_width,kal_uint16 *out_LCD_height)
{
   *out_LCD_width = LCD_WIDTH;
   *out_LCD_height = LCD_HEIGHT;
}


void LCD_SetBias_ST7789S(kal_uint8 *bias)
{
}

void LCD_Contrast_ST7789S(kal_uint8 *contrast)
{
}

void LCD_LineRate_ST7789S(kal_uint8 *linerate)
{
}

void LCD_Temp_Compensate_ST7789S(kal_uint8 *compensate)
{
}

void LCD_Set_Scan_Direction_ST7789S(kal_uint8 rotate_value)
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
} /* LCD_Set_Scan_Direction_ST7789S() */


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
#endif

#if 1

void lcm_read_from_gram(kal_uint8* buffer)
{
    kal_uint32 i=0;
    kal_uint8 *buffer2 = (kal_uint8 *)buffer;
    kal_uint32 temp_data;
    //kal_uint8 x1_high,x1_low,y1_high,y1_low,x2_high,x2_low,y2_high,y2_low;
    kal_uint16 start_x,start_y,end_x,end_y;

    *(volatile unsigned int *)0xA0010320 = 0xFF;  ///for MT6250
    
    LCD_set_reg_main(0x0003,lcd_entry_mode_shadow);
    
    //LCD_CtrlWrite_ST7789S(0x0023);
    LCD_set_reg_main(0x0046,99);
    LCD_set_reg_main(0x0047,0);
    LCD_set_reg_main(0x0048,99);
    LCD_set_reg_main(0x0049,0);

    LCD_CtrlWrite_ST7789S(0x0022);    
    i = LCD_DataRead_ST7789S;    
    
    for(i=0;i<100*100;i++)
    {
         temp_data = LCD_DataRead_ST7789S;
         *buffer2 = temp_data & 0x3F;  //B
         buffer2++;
         *buffer2 = ((temp_data & (0x3F << 6))>>6)&0x3F;  //G
         buffer2++;    
         *buffer2 = ((temp_data & (0x3F << 12))>>12)&0x3F;  //R
         buffer2++;     
         *buffer2 = 0;  //A
         buffer2++;    
    }

//    LCD_CtrlWrite_ST7789S(0x0005);    
//    device_code = LCD_DataRead_ST7789S;   /* device code should be 0x01 << 9 || 0x70 <<1 */

    return;

}
#endif

#ifdef __LCD_ESD_RECOVERY__
void LCD_CheckESD_ST7789S(void)
{

}

kal_bool LCD_Read_ESD_ST7789S(void)
{
	kal_bool ret = KAL_FALSE;	
	kal_uint8 data1, data2, data3, data4;
	DCL_HANDLE cs_handle;

	cs_handle = DclGPIO_Open(DCL_GPIO, 47);

	// Read
	DISABLE_LCD_SERIAL_IF_HW_CS;
	ENABLE_LCD_SERIAL0_CS;
	LCD_CtrlWrite_ST7789S(0x09);  // read id

	DclGPIO_Control(cs_handle, GPIO_CMD_SET_MODE_0, NULL);	
	DclGPIO_Control(cs_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(cs_handle, GPIO_CMD_WRITE_LOW, NULL);
	DclGPIO_Control(cs_handle, GPIO_CMD_WRITE_HIGH, NULL);
	DclGPIO_Control(cs_handle, GPIO_CMD_SET_MODE_1, NULL);	

	data1 = LCD_DataRead_ST7789S;
	data2 = LCD_DataRead_ST7789S;
	data3 = LCD_DataRead_ST7789S;
	data4 = LCD_DataRead_ST7789S;
	DISABLE_LCD_SERIAL0_CS; 
	ENABLE_LCD_SERIAL_IF_HW_CS;

	Delayms(1);

	if((data1 >> 7 )== 0)		// BSTON = 0 in reset
		ret = KAL_TRUE;
	
	return ret;
	
}
#endif

LCM_IOCTRL_STATUS_ENUM
LCD_IOCTRL_ST7789S(LCM_IOCTRL_ID_ENUM ID, void* Parameters)
{
   switch (ID)
   {
       case LCM_IOCTRL_SET__FRAME_RATE:
            return LCM_IOCTRL_NOT_SUPPORT;
            
       case LCM_IOCTRL_QUERY__FRAME_MARKER:
            return LCM_IOCTRL_NOT_SUPPORT;
       
       case LCM_IOCTRL_SET__FRAME_MARKER:
            return LCM_IOCTRL_NOT_SUPPORT;

       case LCM_IOCTRL_QUERY__SUPPORT_H_V_SIGNAL_FUNC:
       case LCM_IOCTRL_QUERY__SUPPORT_V_PULSE_WIDTH:
       case LCM_IOCTRL_QUERY__SUPPORT_H_PULSE_WIDTH:
            return LCM_IOCTRL_NOT_SUPPORT;
            
       case LCM_IOCTRL_QUERY__BACK_PORCH:
            *(kal_uint32 *)(Parameters) = 12;
            return LCM_IOCTRL_OK;
            
       case LCM_IOCTRL_QUERY__FRONT_PORCH:
            *(kal_uint32 *)(Parameters) = 12;
            return LCM_IOCTRL_OK;

       case LCM_IOCTRL_SET__BACK_PORCH:
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
            return LCM_IOCTRL_NOT_SUPPORT;
        #endif
       
       case LCM_IOCTRL_SET__FRONT_PORCH:
            return LCM_IOCTRL_NOT_SUPPORT;
   
       case LCM_IOCTRL_QUERY__TE_EDGE_ATTRIB:
            //*(kal_uint32 *)(Parameters) = 0;
            return LCM_IOCTRL_NOT_SUPPORT;
            
       case LCM_IOCTRL_QUERY__SUPPORT_READBACK_FUNC:
       case LCM_IOCTRL_QUERY__SCANLINE_REG:
            return LCM_IOCTRL_NOT_SUPPORT;
            
       case LCM_IOCTRL_QUERY__IF_CS_NUMBER:
            *(kal_uint32 *)(Parameters) = LCD_IF_SERIAL_0;
            return LCM_IOCTRL_OK;

       case LCM_IOCTRL_QUERY__FRAME_RATE:
            *((unsigned long*)(Parameters)) = 75; // 90
            return LCM_IOCTRL_OK;
            
       case LCM_IOCTRL_QUERY__LCM_WIDTH: 
            *((unsigned long*)(Parameters)) = 240;// physical, not use app's LCD_WIDTH
            return LCM_IOCTRL_OK;

       case LCM_IOCTRL_QUERY__LCM_HEIGHT: 
            *((unsigned long*)(Parameters)) = 320;//320;// physical, not use app's LCD_HEIGHT
            return LCM_IOCTRL_OK;
    
       case LCM_IOCTRL_QUERY__SYNC_MODE: 
            *(kal_uint32 *)(Parameters) = LCM_TE_VSYNC_MODE;
            return LCM_IOCTRL_OK;
			
#ifdef __LCD_ESD_RECOVERY__
	  /** LCM ESD feature control, Check LCD ESD is happend or not **/
	  case LCM_IOCTL_ESD_CHECK:
	   {
		LCM_ESD_INFO_STRUCT* pESDInfo = (LCM_ESD_INFO_STRUCT *)Parameters;
		kal_bool lcm_esd_test = KAL_FALSE;

		lcm_esd_test = LCD_Read_ESD_ST7789S();
	
		if(pESDInfo)
		{
		 //TODO: add ESD real check function here
		 // If happend, must take lcm_esd_test = KAL_TURE;
		 if(lcm_esd_test)
		 {
		  lcm_esd_test = KAL_FALSE;
		  pESDInfo->bEsdHappened = KAL_TRUE;
		 }
		 else
		  pESDInfo->bEsdHappened = KAL_FALSE;
		}
		
		return LCM_IOCTRL_OK;
		break;
	   }
			   
	  /** LCM ESD feature control, If LCD ESD is happend, We should do something here like resetLCM. **/
	  case LCM_IOCTL_ESD_RESET:
	   //TODO: add LCM reset function here
	   //Example
	   LCD_Init_ST7789S(0,0);
	   return LCM_IOCTRL_OK;
	
	   break;  
#endif

       default:
            return LCM_IOCTRL_NOT_SUPPORT;
   }
}

void LCD_gamma_test(kal_uint8 level, kal_uint8 color)
{
}

void LCD_flicker_test(kal_uint8 level)
{
}


LCD_Funcs LCD_func_ST7789S = {
   LCD_Init_ST7789S,
   LCD_PWRON_ST7789S,
   LCD_SetContrast_ST7789S,
   LCD_ON_ST7789S,
   LCD_BlockWrite_ST7789S,
   LCD_Size_ST7789S,
   LCD_EnterSleep_ST7789S,
   LCD_ExitSleep_ST7789S,
   LCD_Partial_On_ST7789S,
   LCD_Partial_Off_ST7789S,
   LCD_Partial_line_ST7789S,
   /*Engineering mode*/
   0,
   LCD_SetBias_ST7789S,
   LCD_Contrast_ST7789S,
   LCD_LineRate_ST7789S,
   LCD_Temp_Compensate_ST7789S
#ifdef __LCD_ESD_RECOVERY__
   ,LCD_CheckESD_ST7789S
#endif
#ifdef LCM_ROTATE_SUPPORT
   ,LCD_Set_Scan_Direction_ST7789S
#endif
#if defined(__DIRECT_SENSOR_SUPPORT__)
   ,LCD_BlockWrite_ST7789S_IssueUpdateCMD
#endif  // #if defined(__DIRECT_SENSOR_SUPPORT__)
#ifdef LQT_SUPPORT/*Do not remove LQT code segment*/
   ,LCD_gamma_test
   ,LCD_flicker_test 
#endif
   ,0 //SetFrameMarker
   ,LCD_IOCTRL_ST7789S
};


void LCD_FunConfig(void)
{
  MainLCD = &LCD_func_ST7789S;
}

