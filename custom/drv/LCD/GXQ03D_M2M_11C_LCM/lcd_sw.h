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
 *   lcd_sw.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "lcd_if_hw.h"
#include "lcm_if.h"
#include "lcd_if.h"
#include "reg_base.h"

#ifndef _LCD_SW_H
#define _LCD_SW_H
//MT6250 serial LCM driver

#define SERIAL_LCM_3WIRE_2_DATA_LANE
//#define SERIAL_LCM_3WIRE_1_DATA_LANE
//#define SERIAL_LCM_4WIRE_1_DATA_LANE

//#define SLCD_FEATURE_CS_STAY_LOW_MODE

//**2-data-lane 3 wire test case match
#if (defined(SERIAL_LCM_3WIRE_2_DATA_LANE))

#define SERIAL_LCM_2_DATA_LINE_PROTOCOL
//#define MAIN_LCD_16BIT_MODE  //Himax protocol match
//#define MAIN_LCD_16BIT_MODE_RGB444
//#define MAIN_LCD_16BIT_MODE_RGB565
//#define MAIN_LCD_16BIT_MODE_RGB888

//#define MAIN_LCD_16BIT_MODE_RGB666 //this can not match with Hixmax, abandon
//#define MAIN_LCD_16BIT_MODE_RGB888 //this can match with Himax 16bit RGB666 protocol
#endif

#define MAIN_LCD_16BIT_MODE  //Himax protocol match
#define MAIN_LCD_16BIT_MODE_RGB565

//#endif

//#define LCD_CMD_DMA_MODE     
#define __SERIAL_LCM__
#define __SERIAL_LCM_CS0__

#ifdef DUAL_LCD
#define SUB_LCD_8BIT_MODE  
#endif

#define MAIN_LCD_CMD_ADDR               LCD_SERIAL0_A0_LOW_ADDR //LOW_ADDR is CMD ADDR
#define MAIN_LCD_DATA_ADDR              LCD_SERIAL0_A0_HIGH_ADDR//HIGH_ADDR is DATA ADDR

#ifdef DUAL_LCD
#define SUB_LCD_CMD_ADDR               LCD_SERIAL1_A0_LOW_ADDR //LOW_ADDR is CMD ADDR
#define SUB_LCD_DATA_ADDR              LCD_SERIAL1_A0_HIGH_ADDR//HIGH_ADDR is DATA ADDR
#endif

#if 0
	#if !defined(FPGA)
	#if (defined(MMI_MAIN_LCD_DEFAULT_FORMAT) && (MMI_MAIN_LCD_DEFAULT_FORMAT == 24))
	    #if (defined(MAIN_LCD_8BIT_MODE))
/* under construction !*/
	    #elif (defined(MAIN_LCD_9BIT_MODE))
/* under construction !*/
		#elif (defined(MAIN_LCD_16BIT_MODE))
/* under construction !*/
		#elif (defined(MAIN_LCD_18BIT_MODE))
/* under construction !*/
		#endif	
	#else   // if MMI_MAIN_LCD_DEFAULT_FORMAT == DEFAULT
	    #if (defined(MAIN_LCD_8BIT_MODE))
/* under construction !*/
	    #elif (defined(MAIN_LCD_9BIT_MODE))
/* under construction !*/
		#elif (defined(MAIN_LCD_16BIT_MODE))
/* under construction !*/
		#elif (defined(MAIN_LCD_18BIT_MODE))
/* under construction !*/
		#endif
	#endif //(defined(MMI_MAIN_LCD_DEFAULT_FORMAT) && (MMI_MAIN_LCD_DEFAULT_FORMAT == 24))
	#endif
#else
  #if (defined(MAIN_LCD_8BIT_MODE_RGB444))
  #define MAIN_LCD_OUTPUT_FORMAT	LCM_8BIT_12_BPP_RGB444_1
  #elif (defined(MAIN_LCD_8BIT_MODE_RGB565))
  #define MAIN_LCD_OUTPUT_FORMAT	LCM_8BIT_16_BPP_RGB565_1
  #elif (defined(MAIN_LCD_8BIT_MODE_RGB666))
  #define MAIN_LCD_OUTPUT_FORMAT	LCM_8BIT_18_BPP_RGB666_1
  #elif (defined(MAIN_LCD_16BIT_MODE_RGB444))
  #define MAIN_LCD_OUTPUT_FORMAT	LCM_16BIT_12_BPP_RGB444_3
  #elif (defined(MAIN_LCD_16BIT_MODE_RGB565))
  #define MAIN_LCD_OUTPUT_FORMAT	LCM_16BIT_16_BPP_RGB565_1
  #elif (defined(MAIN_LCD_16BIT_MODE_RGB666))
  #define MAIN_LCD_OUTPUT_FORMAT	LCM_16BIT_18_BPP_RGB666_3
  #elif (defined(MAIN_LCD_16BIT_MODE_RGB888))
  #define MAIN_LCD_OUTPUT_FORMAT	LCM_16BIT_24_BPP_RGB888_1
  #elif (defined(MAIN_LCD_18BIT_MODE_RGB666))
  #define MAIN_LCD_OUTPUT_FORMAT LCM_18BIT_18_BPP_RGB666_1
  #else
  #error please check LCD TestCase define_error!!! 
  #endif
#endif
/***********************ST7789S********************************/
/*Himax, Color LCD, Serial Interface,*/


#ifdef LCD_CMD_DMA_MODE

#define LCD_delay_ST7789S()
#define LCD_SEND_DMA_CMD(n) \
    {\
    volatile kal_int32 i;\
    while (LCD_IS_RUNNING) {};\
    DISABLE_LCD_TRANSFER_COMPLETE_INT;\
    DISABLE_ALL_LCD_LAYER_WINDOW;\
    SET_LCD_ROI_CTRL_NUMBER_OF_CMD(n);\
    ENABLE_LCD_ROI_CTRL_CMD_FIRST;\
    SET_LCD_ROI_WINDOW_SIZE(0,0);\
    START_LCD_TRANSFER;\
    for(i=0;i<50;i++){};\
    while (LCD_IS_RUNNING) {};\
    }
#if (defined(MAIN_LCD_8BIT_MODE))
    #define LCD_CtrlWrite_ST7789S(_data) \
    {\
    SET_LCD_CMD_PARAMETER(0,LCD_CMD,((_data & 0xFF00)>>8));\
    SET_LCD_CMD_PARAMETER(1,LCD_CMD,(_data & 0xFF));\
    LCD_SEND_DMA_CMD(2);\
    }\
    
    #define LCD_DataWrite_ST7789S(_data) \
    {\
    SET_LCD_CMD_PARAMETER(0,LCD_DATA,((_data&0xFF00)>>8));\
    SET_LCD_CMD_PARAMETER(1,LCD_DATA,(_data&0xFF));\
    LCD_SEND_DMA_CMD(2);\
    }
#elif (defined(MAIN_LCD_9BIT_MODE))
    #define LCD_CtrlWrite_ST7789S(_data) \
    {\
    SET_LCD_CMD_PARAMETER(0,LCD_CMD,((_data & 0xFF00)>>7));\
    SET_LCD_CMD_PARAMETER(1,LCD_CMD,((_data & 0xFF)<<1));\
    LCD_SEND_DMA_CMD(2);\
    }\
    
    #define LCD_DataWrite_ST7789S(_data) \
    {\
    SET_LCD_CMD_PARAMETER(0,LCD_DATA,((_data & 0xFF00)>>7));\
    SET_LCD_CMD_PARAMETER(1,LCD_DATA,((_data & 0xFF)<<1));\
    LCD_SEND_DMA_CMD(2);\
    }
#elif (defined(MAIN_LCD_16BIT_MODE))
    #define LCD_CtrlWrite_ST7789S(_data) \
    {\
    SET_LCD_CMD_PARAMETER(0,LCD_CMD,(((_data & 0xFF00)<<0)|(_data&0xFF)<<0));\
    LCD_SEND_DMA_CMD(1);\
    }\
    
    #define LCD_DataWrite_ST7789S(_data) \
    {\
    SET_LCD_CMD_PARAMETER(0,LCD_DATA,(((_data & 0xFF00)<<0)|(_data&0xFF)<<0));\
    LCD_SEND_DMA_CMD(1);\
    }
#elif (defined(MAIN_LCD_18BIT_MODE))
    #define LCD_CtrlWrite_ST7789S(_data) \
    {\
    SET_LCD_CMD_PARAMETER(0,LCD_CMD,(((_data & 0xFF00)<<2)|(_data&0xFF)<<1));\
    LCD_SEND_DMA_CMD(1);\
    }\
    
    #define LCD_DataWrite_ST7789S(_data) \
    {\
    SET_LCD_CMD_PARAMETER(0,LCD_DATA,(((_data & 0xFF00)<<2)|(_data&0xFF)<<1));\
    LCD_SEND_DMA_CMD(1);\
    }
#endif
    #define LCD_RAMWrite_ST7789S(_data)
#else//#ifdef LCD_CMD_DMA_MODE
    //MCU mode
    // be check CS control and delay
    #define LCD_CtrlWrite_ST7789S(_data) \
    {\
    SET_LCD_SERIAL0_IF_SIZE(LCD_SCNF_IF_WIDTH_8);\
    *((volatile kal_uint16 *)MAIN_LCD_CMD_ADDR) = (_data&0x00FF);\
    for(ranesis_delay = 20; ranesis_delay > 0; ranesis_delay--);\
    }
    
    #define LCD_DataWrite_ST7789S(_data) \
    {\
    SET_LCD_SERIAL0_IF_SIZE(LCD_SCNF_IF_WIDTH_8);\
    *((volatile kal_uint16 *)MAIN_LCD_DATA_ADDR) = (_data&0x00FF);\
    for(ranesis_delay = 20; ranesis_delay > 0; ranesis_delay--);\
    }
#endif /* LCD_CMD_DMA_MODE */

//For LCD read data
#if (defined(MAIN_LCD_8BIT_MODE))
#define LCD_DataRead_ST7789S    (*(volatile kal_uint8 *)MAIN_LCD_DATA_ADDR);
#elif (defined(MAIN_LCD_16BIT_MODE))
#define LCD_DataRead_ST7789S    (*(volatile kal_uint16 *)MAIN_LCD_DATA_ADDR);
#elif (defined(MAIN_LCD_18BIT_MODE))
#define LCD_DataRead_ST7789S    (*(volatile kal_uint32 *)MAIN_LCD_DATA_ADDR);
#endif

#endif  /*_LCD_SW_H*/

