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
 *    gpio.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the GPIO driver.
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "reg_base.h"
#include "gpio_hw.h"
#include "gpio_sw.h"


#ifdef __USB_DOWNLOAD__
extern kal_bool USBDL_Is_USB_Download_Mode(void);
#endif

#ifdef __CUST_NEW__
extern void GPIO_setting_init(void);

kal_bool   gpio_debug_enable = KAL_FALSE;

#if 0
/* under construction !*/
/* under construction !*/
#endif
#endif /*__CUST_NEW__*/


/*
* FUNCTION                                                            
*	GPIO_init
*
* DESCRIPTION                                                           
*   	This function is to initialize the GPIO pins as all GPIO,
*	and configure them as output.
*
* CALLS  
*	None
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_init(void)
{
#ifdef __CUST_NEW__
   GPIO_setting_init();

   //#ifdef  __BTMODULE_RFMD3500__ //add by shine, 2006/06/17
   /* Note that in tool GPIO8,21,37,38,39,40,51 should set as GPO mode, and set as LOW. */
   /* Also the pull-up/pull-down of GPIO21,37,38,39,40,51 should be disable. */
   //GPIO_WriteIO(0,gpio_bt_power_pin); // GPIO8
   //GPIO_WriteIO(0,gpio_bt_wakeup_pin); // GPIO21
   //#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#else /* __CUST_NEW__ */
	
   DRV_WriteReg(GPIO_MODE1,0x5555);
   DRV_WriteReg(GPIO_MODE2,0x5555);
   DRV_WriteReg(GPIO_MODE3,0x4500);
   DRV_WriteReg(GPIO_MODE4,0x5555);
   DRV_WriteReg(GPIO_MODE5,0x5555);
   //DRV_WriteReg(GPIO_MODE5,0x5655);
   DRV_WriteReg(GPIO_MODE6,0x5555);
   DRV_WriteReg(GPIO_MODE7,0x0155);

   DRV_Reg(GPIO_DIR1) |= 0x1fff;
   DRV_Reg(GPIO_DIR2) |= 0x80A0;
   DRV_Reg(GPIO_DIR3) |= 0x0481;

   DRV_Reg(GPIO_PULLEN3) = 0xffef;


   #ifdef __USB_ENABLE__
      #ifdef __USB_DOWNLOAD__
   if(USBDL_Is_USB_Download_Mode() == KAL_FALSE)
      GPIO_WriteIO(0, 6);
      #else
   GPIO_WriteIO(0, 6);
      #endif
   #endif	/*__USB_ENABLE__*/


#ifdef  __BTMODULE_RFMD3500__ //add by shine, 2006/06/17
   GPIO_WriteIO(0,8);
   GPIO_WriteIO(0,9);
#endif
#endif /* __CUST_NEW__ */   
}


