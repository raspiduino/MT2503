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

/*******************************************************************************
*
 * Filename:
 * ---------
 *   i2s_input_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   I2S input mode GPIO pin definition and switch
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
#if defined( __I2S_INPUT_MODE_SUPPORT__ )

#include "l1audio_def.h"
#include "dcl.h"

extern const char gpio_i2s_clk_pin;
extern const char gpio_i2s_data_pin;
extern const char gpio_i2s_ws_pin;

extern const char gpio_i2s_clk_pin_M_EDICK;
extern const char gpio_i2s_data_pin_M_EDIDAT;
extern const char gpio_i2s_ws_pin_M_EDIWS;

extern const char gpio_i2s_clk_pin_M_EDI0CK;
extern const char gpio_i2s_data_pin_M_EDI0DAT;
extern const char gpio_i2s_ws_pin_M_EDI0WS;

extern const char gpio_i2s_clk_pin_M_EDI1CK;
extern const char gpio_i2s_data_pin_M_EDI1DAT;
extern const char gpio_i2s_ws_pin_M_EDI1WS;

#if defined(__CUST_NEW__)
   
#define BCLK        gpio_i2s_clk_pin       
#define DOUT        gpio_i2s_data_pin      
#define LRCLK       gpio_i2s_ws_pin     

#if defined(MT6276)
 
#define BCLK_MODE   gpio_i2s_clk_pin_M_EDI0CK      
#define DOUT_MODE   gpio_i2s_data_pin_M_EDI0DAT      
#define LRCLK_MODE  gpio_i2s_ws_pin_M_EDI0WS        

#else

#define BCLK_MODE   gpio_i2s_clk_pin_M_EDICK      
#define DOUT_MODE   gpio_i2s_data_pin_M_EDIDAT      
#define LRCLK_MODE  gpio_i2s_ws_pin_M_EDIWS             

#endif

#else

#define BCLK   44       // DAI clock output
#define DOUT   46       // DAI PCM data output (input of WM8976: DIN)
#define LRCLK  45       // DAI sync signal input

#define BCLK_MODE  1
#define DOUT_MODE  1
#define LRCLK_MODE 1

#endif

const unsigned char  L1SP_I2S_INPUT_SCALE = 32;// 64 or 32 only : means BCLK = 64fs or 32fs

static void I2S_GPIO_ModeSetup(DCL_UINT32 Pin, DCL_UINT32 Mode)
{
   const DCL_HANDLE Handle = DclGPIO_Open(DCL_GPIO, Pin);
   DclGPIO_Control(Handle, Mode, 0);
   DclGPIO_Close(Handle);
}

void I2S_Input_GPIO_TurnOn()
{
   I2S_GPIO_ModeSetup(BCLK, BCLK_MODE);
   I2S_GPIO_ModeSetup(DOUT, DOUT_MODE);
   I2S_GPIO_ModeSetup(LRCLK, LRCLK_MODE);
}

void I2S_Input_GPIO_TurnOff()
{
   I2S_GPIO_ModeSetup(BCLK, GPIO_CMD_SET_MODE_0);
   I2S_GPIO_ModeSetup(DOUT, GPIO_CMD_SET_MODE_0);
   I2S_GPIO_ModeSetup(LRCLK, GPIO_CMD_SET_MODE_0);
}

#endif


