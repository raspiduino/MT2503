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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "reg_base.h"
#include "gpio_hw.h"
#include "gpio_sw.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include"init.h"
#include "us_timer.h"
#ifndef BL_ENABLE
//#define __GPIO_CHECK_WARNING__
#define __GPIO_CHECK_ASSERT__
#endif /* BL_ENABLE */
#ifdef __GPIO_CHECK_WARNING__
#include <stdio.h>
static kal_char buff[40];
#endif

#if !defined(__FUE__)
   #define SAVEANDSETIRQMASK()      SaveAndSetIRQMask()
   #define RESTOREIRQMASK(mask)     RestoreIRQMask(mask)
#else /*defined(__FUE__)*/
   #define SAVEANDSETIRQMASK()      0
   #define RESTOREIRQMASK(mask)     {}
#endif /*defined(__FUE__)*/


#ifdef DRV_GPIO_NEW_SW_ARCHI



#ifdef __CUST_NEW__

	 extern const kal_uint32  gpio_mode_allowed[][8];
extern const kal_uint32  gpio_dir_out_allowed[];
extern const kal_uint32  gpio_dir_in_allowed[];
extern const kal_uint16  gpo_mode_allowed[];
extern kal_uint32  gpio_check_for_write[];
extern kal_uint32  gpio_check_for_read[];
extern kal_uint16  gpo_check_for_write[];

 

extern kal_bool   gpio_debug_enable;
#endif /* __CUST_NEW__ */


#if defined(GPIO_PUPD0)
const kal_uint16  gpio_pupd_R_map[]= {  GPIO_PUPD_R_MAP  };
#endif

/**********************************************************/

#if defined(GPIO_ADIE_MODE0)
const GPIO_A_DIE_MAP_Table_T gpio_a_die_map[] = { GPIO_A_DIE_MAP};
#endif





#define GET_GPIO_CONTROL_BIT_MASK(shift,bits)   (((1<<(bits)) -1) << (shift))  // get mask mapping


kal_uint16 Get_A_DIE_index(kal_uint16 pin)
{	  
#if defined(GPIO_ADIE_MODE0)

	kal_uint32 index;	
	for(index = 0; index <= GPIO_ADIE_MAX_GPIO_PIN-GPIO_ADIE_MIN_GPIO_PIN; index++)
	{
	 if(gpio_a_die_map[index].gpio_num == pin)
		return index;
	}
	if(index > GPIO_ADIE_MAX_GPIO_PIN)
	{
		EXT_ASSERT(0,0,0,0); 
	}
#endif
	return 0;
}


   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint32 savedMask;
	  kal_uint32 index;
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
     #endif /* __CUST_NEW__ */
 
#if defined(GPIO_ADIE_MODE0)
	 if(KAL_TRUE==Is_ADIE_GPIO(pin))
	   {
	   index = Get_A_DIE_index(pin);
	   if(gpio_a_die_map[index].mode_reg_addr == 0xffffffff)
	   	{
	   	//ASSERT(0); 
                #if !defined(__UBL__)
	   	tst_sys_trace("MODE fail");
                #endif
		return ;// error check
	   	}
      savedMask = SAVEANDSETIRQMASK();
	  DRV_GPIO_SetData(gpio_a_die_map[index].mode_reg_addr, GET_GPIO_CONTROL_BIT_MASK(gpio_a_die_map[index].mode_bit_shift,GPIO_ADIE_MODE_ONE_CONTROL_BITS), (conf_dada << gpio_a_die_map[index].mode_bit_shift));
      RESTOREIRQMASK(savedMask);	  
	  }
	 else
#endif
	{
	if(pin > GPIO_DDIE_MAX_GPIO_PIN){
	   return;}
      modeno = pin/ GPIO_MODE_ONE_REG_CONTROL_NUM;
      remainder = pin %  GPIO_MODE_ONE_REG_CONTROL_NUM;      
      savedMask = SAVEANDSETIRQMASK();
      DRV_GPIO_SetData32(GPIO_MODE(modeno), GET_GPIO_CONTROL_BIT_MASK(remainder* GPIO_MODE_ONE_CONTROL_BITS, GPIO_MODE_ONE_CONTROL_BITS), (conf_dada << ( GPIO_MODE_ONE_CONTROL_BITS*remainder)));
      RESTOREIRQMASK(savedMask);
	} 
	
#endif /*!defined(DRV_GPIO_OFF)*/
   }
char GPIO_ReturnMode(kal_uint16 port)
{
   #if !defined(DRV_GPIO_OFF)
   kal_uint16 modeno;
   kal_uint16 remainder;
   kal_uint32 data; 
   kal_uint32 index;
   #ifdef __CUST_NEW__
      port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */

#if defined(GPIO_ADIE_MODE0)
   	 if(KAL_TRUE==Is_ADIE_GPIO(port))
	{
		index = Get_A_DIE_index(port);
		if(gpio_a_die_map[index].mode_reg_addr == 0xffffffff)
		{
	   	ASSERT(0);
		return 0;
		}
	  	data = DRV_GPIO_Reg(gpio_a_die_map[index].mode_reg_addr);  // risk   D die mode is 32 bit ,but A die  is 32 bit
	 	data = data & GET_GPIO_CONTROL_BIT_MASK(gpio_a_die_map[index].mode_bit_shift,GPIO_ADIE_MODE_ONE_CONTROL_BITS);
		data =data >> gpio_a_die_map[index].mode_bit_shift;
		return (char)data;
	  }
	 else
#endif
	 {
	 
	 if(port > GPIO_DDIE_MAX_GPIO_PIN){
		return;}
		 modeno = port/ GPIO_MODE_ONE_REG_CONTROL_NUM;
		 remainder = port %  GPIO_MODE_ONE_REG_CONTROL_NUM; 	 
		 data = DRV_GPIO_Reg32(GPIO_MODE(modeno)); 
		 data = data & GET_GPIO_CONTROL_BIT_MASK(remainder* GPIO_MODE_ONE_CONTROL_BITS, GPIO_MODE_ONE_CONTROL_BITS);
		 data =(data >> ( GPIO_MODE_ONE_CONTROL_BITS*remainder));
		 return (char)data;
	}	 
   #else  /*!defined(DRV_GPIO_OFF)*/ 
   return 0;
   #endif /*!defined(DRV_GPIO_OFF)*/
} 
   void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada)
   {
        GPIO_ModeSetup(pin,conf_dada);
   }

   
/*
* FUNCTION                                                            
*	GPIO_PullenSetup
*
* DESCRIPTION                                                           
*   	This function is to enable or disable the pull up/down of the related GPIO pin.
*		You can not decide to pull up or down, it is set inside the chip.
*		And, the setting is different from pin by pin.
*
* PARAMETERS
*	pin : gpio pin number range from 0~54 (MT6219)
*	enable: enable the pull up/down
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*/


   void GPIO_PullenSetup(kal_uint16 pin, kal_bool enable)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
	        kal_uint32 savedMask;
			   kal_uint32 index;
      #ifdef __CUST_NEW__   	
      pin &= (~GPIO_MAGIC_NUM);
      #endif /* __CUST_NEW__ */
	  
	#if defined(GPIO_ADIE_PULL0) // driver have this function ,but drv_tool don't have!!!
	//#error "Now the GPIO driver not support Adie PULLEN,please complete !!!"  
	 if(KAL_TRUE==Is_ADIE_GPIO(pin))
	{
		index = Get_A_DIE_index(pin);
		if(gpio_a_die_map[index].pull_en_reg_addr== 0xffffffff)
		{
		#if !defined(__UBL__)
			tst_sys_trace("Adie Pullen fail");
		#endif
		return;
		}	  
	     savedMask = SAVEANDSETIRQMASK();
	  DRV_GPIO_SetData(gpio_a_die_map[index].pull_en_reg_addr, GET_GPIO_CONTROL_BIT_MASK(gpio_a_die_map[index].pull_en_bit_shift,GPIO_ADIE_MODE_ONE_CONTROL_BITS), (enable << gpio_a_die_map[index].pull_en_bit_shift));
      RESTOREIRQMASK(savedMask);	  
	  }
	 else
	#endif
	 	{
		if(pin > GPIO_DDIE_MAX_GPIO_PIN){
		   return;}
      modeno = pin/ GPIO_PULL_ONE_REG_CONTROL_NUM;
      remainder = pin %  GPIO_PULL_ONE_REG_CONTROL_NUM;
	  #if (GPIO_DIR_REG_BITS > 16)
		if(enable)
      		   DRV_GPIO_WriteReg32(GPIO_PULLEN_SET(modeno), (1 << remainder));
                else
      		   DRV_GPIO_WriteReg32(GPIO_PULLEN_CLR(modeno), (1 << remainder));
	  #else
		if(enable)
      	           DRV_GPIO_WriteReg(GPIO_PULLEN_SET(modeno), (1 << remainder));
                else
      	           DRV_GPIO_WriteReg(GPIO_PULLEN_CLR(modeno), (1 << remainder));
	  #endif
	 	}
#endif /*!defined(DRV_GPIO_OFF)*/
   }
/*
* FUNCTION                                                            
*	GPIO_DinvSetup
*
* DESCRIPTION                                                           
*   	This function is to enable data invert of the related GPIO pin
*
* PARAMETERS
*	pin : gpio pin number range from 0~54 (MT6219)
*	enable: enable the data inversion
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*/


   void GPIO_DinvSetup(kal_uint16 pin, kal_bool enable)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      #ifdef __CUST_NEW__   	
      //ASSERT(pin&GPIO_MAGIC_NUM);
      pin &= (~GPIO_MAGIC_NUM);
      #endif /* __CUST_NEW__ */
	  
	#if defined(GPIO_ADIE_DINV0)
	#error "Now the GPIO driver not support Adie Dinv,please complete !!!"
	#endif
		if(pin > GPIO_DDIE_MAX_GPIO_PIN){
		return;}
      modeno = pin/ GPIO_INV_ONE_REG_CONTROL_NUM;
      remainder = pin %  GPIO_INV_ONE_REG_CONTROL_NUM;

#if (GPIO_DIR_REG_BITS > 16)
		if(enable)
		{
		   DRV_GPIO_SetBits32(GPIO_DINV_ADRS(modeno), (1 << remainder));
		}
		else
		{
		   DRV_GPIO_ClearBits32(GPIO_DINV_ADRS(modeno), (1 << remainder));
		}
#else
	  if(enable)
      {
         DRV_GPIO_SetBits(GPIO_DINV_ADRS(modeno), (1 << remainder));
      }
      else
      {
         DRV_GPIO_ClearBits(GPIO_DINV_ADRS(modeno), (1 << remainder));
      }
#endif
#endif /*!defined(DRV_GPIO_OFF)*/
   }
   

/*
* FUNCTION                                                            
*	GPIO_PullSelSetup
*
* DESCRIPTION                                                           
*   	This function is to select pull up/down of the related GPIO pin.
*
* PARAMETERS
*	pin : gpio pin number range from 0~54 (MT6219)
*	enable: enable the pull up/down
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*/
void GPIO_PullSelSetup(kal_uint16 pin, kal_bool pull_up)
{
#if !defined(DRV_GPIO_OFF)
   kal_uint16 modeno;
   kal_uint16 remainder;
   kal_uint32 savedMask;
   kal_uint32 index;
   kal_uint16 temp_pull;
   pin &= 0x00ff;
   #ifdef __CUST_NEW__   	
   pin &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
#if defined(GPIO_ADIE_PULLSEL0)// driver have this function ,but drv_tool don't have!!!
//#error "Now the GPIO driver not support Adie pull sel,please complete !!!"
    if(KAL_TRUE==Is_ADIE_GPIO(pin))
	{
		index = Get_A_DIE_index(pin);
		if(gpio_a_die_map[index].pull_sel_reg_addr== 0xffffffff)
		{
		#if !defined(__UBL__)
			tst_sys_trace("Adie Pullsel fail");
		#endif
		return;
		}	
		#if defined(ADIE_GPIO_PULLSEL_UP_IS_1)	
		if(pull_up)
			temp_pull = 1;
		else
			temp_pull = 0;
		#else
			if(pull_up)
			temp_pull = 0;
		else
			temp_pull = 1;
#endif
	     savedMask = SAVEANDSETIRQMASK();
	  		DRV_GPIO_SetData(gpio_a_die_map[index].pull_sel_reg_addr, GET_GPIO_CONTROL_BIT_MASK(gpio_a_die_map[index].pull_sel_bit_shift,GPIO_ADIE_MODE_ONE_CONTROL_BITS), (temp_pull << gpio_a_die_map[index].pull_sel_bit_shift));
      		RESTOREIRQMASK(savedMask);	  
	  }
	else
	#endif
	   	{
		if(pin > GPIO_DDIE_MAX_GPIO_PIN){
		   return;}
   modeno = pin/ GPIO_PULL_SEL_ONE_REG_CONTROL_NUM;
   remainder = pin %  GPIO_PULL_SEL_ONE_REG_CONTROL_NUM;

#if (GPIO_DIR_REG_BITS > 16)
	 #if defined(DDIE_GPIO_PULLSEL_UP_IS_1)  
				 if(pull_up)
				   DRV_GPIO_WriteReg32(GPIO_PULLSEL_SET(modeno), 1 << remainder);
				else
				   DRV_GPIO_WriteReg32(GPIO_PULLSEL_CLR(modeno), 1 << remainder);
	 #else
					 if(pull_up)
					 DRV_GPIO_WriteReg32(GPIO_PULLSEL_CLR(modeno), 1 << remainder);
					 else
					 DRV_GPIO_WriteReg32(GPIO_PULLSEL_SET(modeno), 1 << remainder);
	 #endif
#else
	#if defined(DDIE_GPIO_PULLSEL_UP_IS_1)	
	if(pull_up)
      DRV_GPIO_WriteReg(GPIO_PULLSEL_SET(modeno), 1 << remainder);
   else
      DRV_GPIO_WriteReg(GPIO_PULLSEL_CLR(modeno), 1 << remainder);
	#else
		if(pull_up)
      	DRV_GPIO_WriteReg(GPIO_PULLSEL_CLR(modeno), 1 << remainder);
   		else
      	DRV_GPIO_WriteReg(GPIO_PULLSEL_SET(modeno), 1 << remainder);
	#endif
#endif
	
	   	}
#endif /*!defined(DRV_GPIO_OFF)*/
}


/*
* FUNCTION                                                            
*	GPIO_InitIO
*
* DESCRIPTION                                                           
*   	This function is to initialize one GPIO pin as INPUT or OUTPUT
*
* CALLS  
*	Initialize one GPIO pin as INPUT or OUTPUT
*
* PARAMETERS
*	direction: INPUT or OUTPUT
*	port: pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_InitIO(char direction, kal_uint16 port)
{
#if !defined(DRV_GPIO_OFF)

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint32 savedMask; 
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_InitIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   if (gpio_debug_enable == KAL_TRUE)
   {
      if (direction == 0)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO: Direction Input is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO: Direction Output is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
	  gpio_check_for_write[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
	  gpio_check_for_read[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
   }
   #endif /* __CUST_NEW__ */
#if defined(GPIO_ADIE_MODE0)
   if(KAL_TRUE==Is_ADIE_GPIO(port))
	{
		 	kal_uint16 index;
			index = Get_A_DIE_index(port);
			if(gpio_a_die_map[index].output_enable_reg_addr == 0xffffffff)
				{
	   			//ASSERT(0);
                                #if !defined(__UBL__)
	   	                 tst_sys_trace("INIT fail");
                                #endif
				return;
				}
			 savedMask = SAVEANDSETIRQMASK();
	  		DRV_GPIO_SetData(gpio_a_die_map[index].output_enable_reg_addr, GET_GPIO_CONTROL_BIT_MASK(gpio_a_die_map[index].output_enable_bit_shift,GPIO_ADIE_DIR_ONE_CONTROL_BITS), (direction << gpio_a_die_map[index].output_enable_bit_shift));
      		RESTOREIRQMASK(savedMask);	 
   	 }			
   else
#endif
   	{
	if(port > GPIO_DDIE_MAX_GPIO_PIN){
	   return;}
   		no = port/ GPIO_DIR_ONE_REG_CONTROL_NUM;
   		remainder = port %  GPIO_DIR_ONE_REG_CONTROL_NUM;
#if (GPIO_DIR_REG_BITS > 16)
	 	if (direction == OUTPUT)
	  		DRV_GPIO_WriteReg32(GPIO_DIR_SET(no),(1 << remainder));
	 	else
	  		DRV_GPIO_WriteReg32(GPIO_DIR_CLR(no),(1 << remainder));
#else
   		if (direction == OUTPUT)
     	 DRV_GPIO_WriteReg(GPIO_DIR_SET(no),(1 << remainder));
		else
     	 DRV_GPIO_WriteReg(GPIO_DIR_CLR(no),(1 << remainder));
#endif
		
   	 }
#endif   /*DRV_GPIO_FULL_FUNC*/

#endif /*!defined(DRV_GPIO_OFF)*/
}


/*
* FUNCTION                                                            
*	GPIO_ReadIO
*
* DESCRIPTION                                                           
*   	This function is to read data from one GPIO pin
*
* CALLS  
*	Read data from one GPIO pin
*
* PARAMETERS
*	port: pin number
*	
* RETURNS
*	1 or 0
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReadIO(kal_uint16 port)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint32 data;   
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_read[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
   #if defined(DRV_GPIO_REG_AS_6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
   #endif /* DRV_GPIO_REG_AS_6228 */
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         char dir;
         dir = GPIO_ReturnDir(port);
         if (dir != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: direction is not correct.");
          ret = sprintf(buff, "pin=%d, direction=%d", port, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnDir(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_read[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __CUST_NEW__ */
#if defined(GPIO_ADIE_MODE0)
   		if(KAL_TRUE==Is_ADIE_GPIO(port))
		{
		 	kal_uint16 index;
			index = Get_A_DIE_index(port);
			if(gpio_a_die_map[index].data_in_reg_addr== 0xffffffff)
			{
	   			ASSERT(0);
				return 0;// error check
			}
			data=DRV_GPIO_Reg(gpio_a_die_map[index].data_in_reg_addr);   
   			data=data&(1 << gpio_a_die_map[index].data_in_bit_shift);
   			data=(data >> gpio_a_die_map[index].data_in_bit_shift);
   			return (char)data;
   	 	}
	 	else
#endif
	 	{
	 		 if(port > GPIO_DDIE_MAX_GPIO_PIN){
				return;}
   			no = port/ GPIO_DIN_ONE_REG_CONTROL_NUM;
   			remainder = port %  GPIO_DIN_ONE_REG_CONTROL_NUM;
         		
	#if (GPIO_DIR_REG_BITS > 16)
					data=DRV_GPIO_Reg32(GPIO_DIN(no));	 
	#else
			data=DRV_GPIO_Reg(GPIO_DIN(no));   
	#endif
   			data=data&(1 << remainder);
   			data=(data >> remainder);
   			return (char)data;
	 	}
#else /* DRV_GPIO_FULL_FUNC */
   return 0;
#endif /* DRV_GPIO_FULL_FUNC */
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_WriteIO
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPIO port
*
* CALLS  
*	Write data to one GPIO port
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	port: gpio pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/
void GPIO_WriteIO(char data, kal_uint16 port)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint32   savedMask;
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_write[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
      
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         char dir;
         dir = GPIO_ReturnDir(port);
         if (dir != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: direction is not correct.");
          ret = sprintf(buff, "pin=%d, direction=%d", port, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnDir(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_write[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __CUST_NEW__ */
#if defined(GPIO_ADIE_MODE0)
   if(KAL_TRUE==Is_ADIE_GPIO(port))
	{
	  kal_uint16 index;
	  index = Get_A_DIE_index(port);
	  if(gpio_a_die_map[index].data_out_reg_addr== 0xffffffff)
	  	{
	   	//ASSERT(0);
                #if !defined(__UBL__)
	   	tst_sys_trace("WriteIO fail");
                #endif
		return;
	  	}
      savedMask = SAVEANDSETIRQMASK();
	  DRV_GPIO_SetData(gpio_a_die_map[index].data_out_reg_addr, GET_GPIO_CONTROL_BIT_MASK(gpio_a_die_map[index].data_out_bit_shift,1), (data << gpio_a_die_map[index].data_out_bit_shift));
      RESTOREIRQMASK(savedMask);	  
   	 }
   else
#endif
   	{
   		if(port > GPIO_DDIE_MAX_GPIO_PIN){
			return;}
   		no = port/ GPIO_OUTPUT_LEVEL_ONE_REG_CONTROL_NUM;
   		remainder = port %  GPIO_OUTPUT_LEVEL_ONE_REG_CONTROL_NUM;
		#if (GPIO_DIR_REG_BITS > 16)
						if (data == 1)
							DRV_GPIO_WriteReg32(GPIO_OUTPUT_LEVEL_SET(no),(1 << remainder));
						else
							DRV_GPIO_WriteReg32(GPIO_OUTPUT_LEVEL_CLR(no),(1 << remainder));
		#else
   		if (data == 1)
      		DRV_GPIO_WriteReg(GPIO_OUTPUT_LEVEL_SET(no),(1 << remainder));
		else
      	DRV_GPIO_WriteReg(GPIO_OUTPUT_LEVEL_CLR(no),(1 << remainder));
		#endif
   	}
#endif   /*DRV_GPIO_FULL_FUNC*/
#endif /*!defined(DRV_GPIO_OFF)*/
}




/*
* FUNCTION                                                            
*	GPIO_ReturnDout
*
* DESCRIPTION                                                           
*   	This function is to report GPIO output value
*
* CALLS  
*	Report GPIO output value accoding to input pin
*
* PARAMETERS
*	GPIO pin 
*	
* RETURNS
*	GPIO output value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReturnDout(kal_uint16 port)
{
#if !defined(DRV_GPIO_OFF)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint32 data=0;
   #ifdef __CUST_NEW__
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
#if defined(GPIO_ADIE_MODE0)
    if(KAL_TRUE==Is_ADIE_GPIO(port))
	{
		kal_uint16 index;
		index = Get_A_DIE_index(port);
		if(gpio_a_die_map[index].data_out_reg_addr== 0xffffffff)
			{
	   		ASSERT(0);	
			return 0;
			}
		 data=DRV_GPIO_Reg(gpio_a_die_map[index].data_out_reg_addr); 
		 remainder = gpio_a_die_map[index].data_out_bit_shift;
   	 }			
   else
 #endif
   	{
	 if(port > GPIO_DDIE_MAX_GPIO_PIN){
			return;}
  		 no = port/ GPIO_OUTPUT_LEVEL_ONE_REG_CONTROL_NUM;
  	 	remainder = port %  GPIO_OUTPUT_LEVEL_ONE_REG_CONTROL_NUM;
		#if (GPIO_DIR_REG_BITS > 16)
			data=DRV_GPIO_Reg32(GPIO_OUTPUT_LEVEL(no)); 
		#else
  		 data=DRV_GPIO_Reg(GPIO_OUTPUT_LEVEL(no)); 
		#endif
   	}
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (char)data;
#else  /*!defined(DRV_GPIO_OFF)*/
   return 0;
#endif /*!defined(DRV_GPIO_OFF)*/
}


/*
* FUNCTION                                                            
*	GPIO_ReturnDir
*
* DESCRIPTION                                                           
*   	This function is to report GPIO direction value
*
* CALLS  
*	Report GPIO direction value accoding to input pin
*
* PARAMETERS
*	GPIO pin 
*	
* RETURNS
*	GPIO direction value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReturnDir(kal_uint16 port)
{
#if !defined(DRV_GPIO_OFF)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint32 data=0;   
   #ifdef __CUST_NEW__
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
#if defined(GPIO_ADIE_MODE0)
    if(KAL_TRUE==Is_ADIE_GPIO(port))
	{
		kal_uint16 index;
		index = Get_A_DIE_index(port);
		if(gpio_a_die_map[index].output_enable_reg_addr== 0xffffffff)
			{
	   		ASSERT(0);	
			return;
			}
		 data=DRV_GPIO_Reg(gpio_a_die_map[index].output_enable_reg_addr); 
		 remainder = gpio_a_die_map[index].output_enable_bit_shift;
   	 }			
   else
 #endif
   	{
   		 if(port > GPIO_DDIE_MAX_GPIO_PIN){
		return;}
   		no = port/ GPIO_DIR_ONE_REG_CONTROL_NUM;
   		remainder = port %  GPIO_DIR_ONE_REG_CONTROL_NUM;
#if (GPIO_DIR_REG_BITS > 16)
		data=DRV_GPIO_Reg32(GPIO_DIR(no)); 
#else
   		data=DRV_GPIO_Reg(GPIO_DIR(no)); 
#endif
   	}
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (char)data;

#else  /*!defined(DRV_GPIO_OFF)*/
   return 0;
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_SetDebugMode
*
* DESCRIPTION                                                           
*  This function is to set GPIO HW debug mode
*
* CALLS  
*	set GPIO HW debug mode
*
* PARAMETERS
*	enable   - KAL_TRUE: turn on the debug mode
*             KAL_FALSE: turn off the debug mode
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_SetDebugMode(kal_bool enable)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_DEBUG_MODE)
   if (enable == KAL_TRUE)
   {
      DRV_GPIO_WriteReg(GPIO_BANK,0);
   }
   else
   {
      DRV_GPIO_WriteReg(GPIO_BANK,1);
   }
#endif /* DRV_GPIO_DEBUG_MODE */
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_SetClkOut
*
* DESCRIPTION                                                           
*  This function is to set GPIO Clock output mode
*
* CALLS  
*	set GPIO Clock output mode
*
* PARAMETERS
*	clk_num   - 0~5; When clk_num is 0, it represents CLK ouput 1
*  mode      - enum value for clock output source mode
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_SetClkOut(char clk_num, gpio_clk_mode mode)
{
#if !defined(DRV_GPIO_OFF)
#if defined ( CLKO_MODE0)
kal_uint16 modeno;
kal_uint16 remainder;
kal_uint32 savedMask;
if ((clk_num > GPIO_CLK_MODE_REG_MAX_NUM) || (mode >= mode_max_num))
	 return;

#if defined(GPIO_ADIE_CLK0)
#error "Now the GPIO driver not support Adie clk ,please complete !!!"
#endif

  modeno = clk_num/ GPIO_CLOCK_SEL_ONE_REG_CONTROL_NUM;
  remainder = clk_num %  GPIO_CLOCK_SEL_ONE_REG_CONTROL_NUM;

  savedMask = SAVEANDSETIRQMASK();
#if (GPIO_DIR_REG_BITS > 16)
		  DRV_GPIO_SetData32(CLK_MODE(modeno), GET_GPIO_CONTROL_BIT_MASK(remainder* GPIO_CLOCK_SEL_ONE_CONTROL_BITS, GPIO_CLOCK_SEL_ONE_CONTROL_BITS), (mode << ( GPIO_CLOCK_SEL_ONE_CONTROL_BITS*remainder)));
#else
                  DRV_GPIO_SetData(CLK_MODE(modeno), GET_GPIO_CONTROL_BIT_MASK(remainder* GPIO_CLOCK_SEL_ONE_CONTROL_BITS, GPIO_CLOCK_SEL_ONE_CONTROL_BITS), (mode << ( GPIO_CLOCK_SEL_ONE_CONTROL_BITS*remainder)));
#endif
  RESTOREIRQMASK(savedMask);
 #else
	ASSERT(0);
#endif 
#endif /*!defined(DRV_GPIO_OFF)*/
}
                                              

void GPIO_SetClkDiv(char clk_num, gpio_clk_div div)
{
#if !defined(DRV_GPIO_OFF)

//error check 
	#if defined(ADIE_CLKO_DIV0)
	#error "Now the GPIO driver not support Adie clk DIV ,please complete !!!"
	#endif

	#if defined (CLKO_DIV0)
	kal_uint32 savedMask;
	if ((clk_num > GPIO_CLK_MODE_REG_MAX_NUM) || (mode >= mode_max_num))
		 return;
	  savedMask = SAVEANDSETIRQMASK();
#if (GPIO_DIR_REG_BITS > 16)
	DRV_GPIO_SetData32(CLK_DIV(modeno), GET_GPIO_CONTROL_BIT_MASK(remainder* GPIO_CLOCK_DIV_ONE_CONTROL_BITS, GPIO_CLOCK_DIV_ONE_CONTROL_BITS), (mode << ( GPIO_CLOCK_DIV_ONE_CONTROL_BITS*remainder)));
#else
	  DRV_GPIO_SetData(CLK_DIV(modeno), GET_GPIO_CONTROL_BIT_MASK(remainder* GPIO_CLOCK_DIV_ONE_CONTROL_BITS, GPIO_CLOCK_DIV_ONE_CONTROL_BITS), (mode << ( GPIO_CLOCK_DIV_ONE_CONTROL_BITS*remainder)));
#endif
	  RESTOREIRQMASK(savedMask);
	#else
		ASSERT(0);
	#endif
#endif /*!defined(DRV_GPIO_OFF)*/
}


#ifdef __CUST_NEW__

/*
* FUNCTION                                                            
*	GPIO_InitIO_FAST
*
* DESCRIPTION                                                           
*   	This function is to initialize one GPIO pin as INPUT or OUTPUT. 
*  Note that it's for fast access without debug checking and only exists
*  when __CUST_NEW__ is defined.
*
* CALLS  
*	Initialize one GPIO pin as INPUT or OUTPUT
*
* PARAMETERS
*	direction: INPUT or OUTPUT
*	port: pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_InitIO_FAST(char direction, kal_uint16 port)
{
#if !defined(DRV_GPIO_OFF)
	GPIO_InitIO(direction,port);
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_ReadIO_FAST
*
* DESCRIPTION                                                           
*   	This function is to read data from one GPIO pin.
*  Note that it's for fast access without debug checking and only exists
*  when __CUST_NEW__ is defined.
*
* CALLS  
*	Read data from one GPIO pin
*
* PARAMETERS
*	port: pin number
*	
* RETURNS
*	1 or 0
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReadIO_FAST(kal_uint16 port)
{
#if !defined(DRV_GPIO_OFF)
return GPIO_ReadIO(port);
#else
return 0;
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_WriteIO_FAST
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPIO port
*  Note that it's for fast access without debug checking and only exists
*  when __CUST_NEW__ is defined.
*
* CALLS  
*	Write data to one GPIO port
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	port: gpio pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/
void GPIO_WriteIO_FAST(char data, kal_uint16 port)
{
#if !defined(DRV_GPIO_OFF)
GPO_WriteIO(data,port);
#endif /*!defined(DRV_GPIO_OFF)*/
}

#endif /* __CUST_NEW__ */


/*
* FUNCTION                                                            
*	GPIO_Check_MultiPins
*
* DESCRIPTION                                                           
*   	This function is to check the validity of GPIO mode and direction
*  for multiple GPIO ports.
*
* CALLS  
*	check the validity of GPIO mode and direction for multiple GPIO ports.
*
* PARAMETERS
*	check_ptr: pointer to an array of GPIOCheckStruct with element number 
*             by pin_cnt.
*	pin_cnt: gpio pin count that will be checked for validity
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/

#pragma arm section code = "INTERNCODE"
/*
* FUNCTION                                                            
*	GPIO_WriteIO_FAST2
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPIO port
*  Note that it's for faster access without debug checking.
*
* CALLS  
*	Write data to one GPIO port
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	no: no = port/16; port: GPIO port number
*	remainder_shift: remainder_shift = 1<<(port%16);
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/
void GPIO_WriteIO_FAST2(char data, kal_uint16 no, kal_uint16 remainder_shift)
{
#if !defined(DRV_GPIO_OFF)
kal_uint16 port;
kal_uint16 index;
for (index = 0; index < 16; index++)
	{
	   if (remainder_shift & (1 << index))
		  break;
	}
	port = (char)((no<<4)+(index&0x000f));
	GPIO_WriteIO(data,port);
 #endif /*!defined(DRV_GPIO_OFF)*/
} 
#pragma arm section code
 
void GPIO_set_pupd_R(kal_uint16 pin, kal_bool pupd_en,kal_bool r0,kal_bool r1)
   {
   #if !defined(DRV_GPIO_OFF)
 #if defined(GPIO_PUPD0)
    kal_uint16 modeno1;
      kal_uint16 remainder1;
	   kal_uint16 modeno2;
      kal_uint16 remainder2;
	   kal_uint16 modeno3;
      kal_uint16 remainder3;
	  kal_uint16  gpio_pupd_r_index_temp;
      #ifdef __CUST_NEW__   	
      pin &= (~GPIO_MAGIC_NUM);
      #endif /* __CUST_NEW__ */
       gpio_pupd_r_index_temp=get_pupd_R_index(pin);


      modeno1 = gpio_pupd_r_index_temp/ GPIO_PUPD_ONE_REG_CONTROL_NUM;
      remainder1 = gpio_pupd_r_index_temp %  GPIO_PUPD_ONE_REG_CONTROL_NUM; 
      modeno2 = gpio_pupd_r_index_temp/ GPIO_R0_ONE_REG_CONTROL_NUM;
      remainder2 = gpio_pupd_r_index_temp %  GPIO_R0_ONE_REG_CONTROL_NUM; 
	  modeno3 = gpio_pupd_r_index_temp/ GPIO_R1_ONE_REG_CONTROL_NUM;
      remainder3 = gpio_pupd_r_index_temp %  GPIO_R1_ONE_REG_CONTROL_NUM; 

#if (GPIO_DIR_REG_BITS > 16)
		   if(r0)
			  DRV_GPIO_WriteReg32(GPIO_R0_SET(modeno2), 1 << remainder2);
		   else
			  DRV_GPIO_WriteReg32(GPIO_R0_CLR(modeno2), 1 << remainder2);
		   if(r1)
			  DRV_GPIO_WriteReg32(GPIO_R1_SET(modeno3), 1 << remainder3);
		   else
			  DRV_GPIO_WriteReg32(GPIO_R1_CLR(modeno3), 1 << remainder3);
		   
 		#if defined(DDIE_GPIO_PUPD_UP_IS_1)	   
		   if(pupd_en)
			  DRV_GPIO_WriteReg32(GPIO_PUPDEN_SET(modeno1), 1 << remainder1);
		   else
			  DRV_GPIO_WriteReg32(GPIO_PUPDEN_CLR(modeno1), 1 << remainder1);	 
		#else
			 if(pupd_en)
				  DRV_GPIO_WriteReg32(GPIO_PUPDEN_CLR(modeno1), 1 << remainder1);
			 else
				 DRV_GPIO_WriteReg32(GPIO_PUPDEN_SET(modeno1), 1 << remainder1);
   		#endif
#else  //(GPIO_DIR_REG_BITS > 16)
      if(r0)
      	 DRV_GPIO_WriteReg(GPIO_R0_SET(modeno2), 1 << remainder2);
      else
      	 DRV_GPIO_WriteReg(GPIO_R0_CLR(modeno2), 1 << remainder2);
	  if(r1)
      	 DRV_GPIO_WriteReg(GPIO_R1_SET(modeno3), 1 << remainder3);
      else
      	 DRV_GPIO_WriteReg(GPIO_R1_CLR(modeno3), 1 << remainder3);
	  
	  #if defined(DDIE_GPIO_PUPD_UP_IS_1) 	  	
	  if(pupd_en)
         DRV_GPIO_WriteReg(GPIO_PUPDEN_SET(modeno1), 1 << remainder1);
      else
         DRV_GPIO_WriteReg(GPIO_PUPDEN_CLR(modeno1), 1 << remainder1);	
	 #else
		if(pupd_en)
        	 DRV_GPIO_WriteReg(GPIO_PUPDEN_CLR(modeno1), 1 << remainder1);
      	else
         	DRV_GPIO_WriteReg(GPIO_PUPDEN_SET(modeno1), 1 << remainder1);
		#endif
#endif
		
		
	#else  // GPIO_PUPD0
	 ASSERT(0);
	 #endif
#endif
   } 

 kal_uint16  get_pupd_R_index( kal_uint16	pin_num)
 	{   
 	#if !defined(DRV_GPIO_OFF)
	 #if defined(GPIO_PUPD0)
	static kal_uint16  u2cnt1;
	for (u2cnt1= 0;u2cnt1<sizeof(gpio_pupd_R_map)/sizeof(*gpio_pupd_R_map);u2cnt1++)
	{
		if(gpio_pupd_R_map[u2cnt1] ==pin_num)
		return  u2cnt1;
	}
	#endif
	ASSERT(0); // the GPIO not support PUPD
	return  KAL_FALSE;
	#else
	return  KAL_FALSE;
	#endif
 }  	 
  kal_bool  Is_ADIE_GPIO( kal_uint16 pin)
 	{
 	#if !defined(DRV_GPIO_OFF)
    #if defined(GPIO_ADIE_MODE0)
     if(pin < GPIO_ADIE_MIN_GPIO_PIN  || pin > GPIO_ADIE_MAX_GPIO_PIN)
	 	return  KAL_FALSE;
      else
	  	return  KAL_TRUE;
	#else  //GPIO_ADIE_MODE0
	    return  KAL_FALSE;	
	#endif //GPIO_ADIE_MODE0
	#endif 
     }



void GPO_WriteIO(char data,kal_uint16 port)
{
}


#if defined(__MTK_TARGET__)
#pragma push
#pragma arm section code = "INTSRAM_ROCODE" , rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif
/*====================================================================*/
/*=========================GPIO strapping pin workaround start====================*/
/*******************************************************
* dongming: for saving power, when enter sleep mode, 
* we should set the strapping pin according to the PCB 
* layout. [2014.3.26]
* maybe next chip,we could change this code to custom folder
********************************************************/

/* 
* 5 pins should be set in 6261/2501/2502 as belows:
* LSCK(GPIO47),LSRSTB(45),LSA0(49),BPI_BUS1(23),
* BPI_BUS2(22)
*/



#if defined(MT6261) || defined(MT2501) || defined(MT2502)
#include "gpio_drv.h"
#if defined(GPIO_STRAPPING_PIN_ARRAY)
typedef struct
{
	//kal_uint8 gpio_num;
	kal_uint8 mode;
	kal_uint8 dir;
	kal_uint8 dout;
}gpio_strapping_pin_backup_t;

#define GPIO_SPECIAL_OUTPUT_STRAPPING_PIN 49
kal_uint8 strapping_pin_gpio_array[GPIO_STRAPPING_PIN_NUMBER] = {GPIO_STRAPPING_PIN_ARRAY};
gpio_strapping_pin_backup_t gpio_strapping_pin_backup[GPIO_STRAPPING_PIN_NUMBER] = {0};

#endif   //defined(GPIO_STRAPPING_PIN_ARRAY)
#endif  //defined(MT6261) || defined(MT2501) || defined(MT2502)

void gpio_strapping_pin_lowpower_set(void)
{
#if (defined(MT6261) || defined(MT2501) || defined(MT2502)) && (defined(GPIO_STRAPPING_PIN_ARRAY))

	kal_uint8 i;
	for(i = 0; i < GPIO_STRAPPING_PIN_NUMBER; i++)
	{
		gpio_strapping_pin_backup[i].mode = GPIO_ReturnMode(strapping_pin_gpio_array[i]);
		gpio_strapping_pin_backup[i].dir = GPIO_ReturnDir(strapping_pin_gpio_array[i]);
		gpio_strapping_pin_backup[i].dout = GPIO_ReturnDout(strapping_pin_gpio_array[i]);
	}
	// set mode to gpio mode,and dir as output,and output 0
	for(i = 0; i < GPIO_STRAPPING_PIN_NUMBER; i++)
	{
		GPIO_ModeSetup(strapping_pin_gpio_array[i],0);
		GPIO_InitIO(1,strapping_pin_gpio_array[i]);
		if(GPIO_SPECIAL_OUTPUT_STRAPPING_PIN != strapping_pin_gpio_array[i]){
			GPIO_WriteIO(0,strapping_pin_gpio_array[i]);}
		else
		{
			if(0 != (DRV_Reg32(0xA0010224) & 0x00010000) ){
				GPIO_WriteIO(1,strapping_pin_gpio_array[i]);}
			else{
				GPIO_WriteIO(0,strapping_pin_gpio_array[i]);}
		}
		
	}

#endif
}

void gpio_strapping_pin_lowpower_restore(void)
{
#if (defined(MT6261) || defined(MT2501) || defined(MT2502)) && (defined(GPIO_STRAPPING_PIN_ARRAY))

	kal_uint8 i;
	for(i = 0; i < GPIO_STRAPPING_PIN_NUMBER; i++)
	{
		GPIO_ModeSetup(strapping_pin_gpio_array[i],gpio_strapping_pin_backup[i].mode);
		GPIO_InitIO(gpio_strapping_pin_backup[i].dir,strapping_pin_gpio_array[i]);
		GPIO_WriteIO(gpio_strapping_pin_backup[i].dout,strapping_pin_gpio_array[i]);
	}
#endif
}





/*=========================GPIO strapping pin workaround end====================*/
/*====================================================================*/
/*====================================================================*/


/*=========================GPIO external buck workaround start====================*/
/*******************************************************
* dongming: for saving power, when enter sleep mode, 
* we should set the external buck. [2014.4.10]
********************************************************/
#if defined(__EXT_BUCK__)

extern const char gpio_external_buck_pin;

void gpio_external_buck_init(void)
{
	// set gpio to output
	if(0xFF != gpio_external_buck_pin)
	{
		GPIO_ModeSetup((gpio_external_buck_pin & 0x7F),0);//set mode0, &0x7F because drv tool gen (25 | 0x80)
		GPIO_InitIO(1,(gpio_external_buck_pin & 0x7F));//output 
	}
}
void gpio_external_buck_turn_on(void)
{
	
	if(0xFF != gpio_external_buck_pin)
	{
		GPIO_WriteIO(1,(gpio_external_buck_pin & 0x7F));//write high to turn on external buck
		ust_busy_wait(1000);// wait for 1ms for hw request
	}
}
void gpio_external_buck_turn_off(void)
{
	if(0xFF != gpio_external_buck_pin)
	{
		GPIO_WriteIO(0,(gpio_external_buck_pin & 0x7F));//write low to turn off external buck
	}

}

void gpio_external_buck_set_in_normal_mode(void)
{
	gpio_external_buck_init();
	gpio_external_buck_turn_on();
}



#endif
/*=========================GPIO external buck workaround end====================*/
/*====================================================================*/
#if defined(__MTK_TARGET__)

#pragma arm section code ,rwdata, rodata , zidata
#pragma pop

#endif



#else //#ifdef DRV_GPIO_NEW_SW_ARCHI



#ifdef __CUST_NEW__
   #if defined(DRV_GPIO_8_MODES) || defined(DRV_GPIO_MODE_4BITS)
   extern const kal_uint32  gpio_mode_allowed[][8];
   #else //defined(DRV_GPIO_8_MODES) || defined(DRV_GPIO_MODE_4BITS)
extern const kal_uint32  gpio_mode_allowed[][4];
   #endif //defined(DRV_GPIO_8_MODES) || defined(DRV_GPIO_MODE_4BITS)
extern const kal_uint32  gpio_dir_out_allowed[];
extern const kal_uint32  gpio_dir_in_allowed[];
extern const kal_uint16  gpo_mode_allowed[];
extern kal_uint32  gpio_check_for_write[];
extern kal_uint32  gpio_check_for_read[];
extern kal_uint16  gpo_check_for_write[];
extern kal_bool   gpio_debug_enable;
#endif /* __CUST_NEW__ */


/******************************************************************************/
/****************MT6250   MAPPING    TABLE    definition********************************/

#if defined (DRV_GPIO_6250_SPECIAL_SET_REG)

const MT6250_GPIO_PULL_EN_SELL_MAP_Table_T  gpio_6250_pull_en_sel_map[]={
//	#if defined(__MTK_INTERNAL__)
	{3,1},      //GPIO_0
	{4,12},      //GPIO_1
	{4,7},     //GPIO_2
	{4,1},    //GPIO_3
	{3,13},    //GPIO_4
	{4,0},    //GPIO_5
	{3,8},    //GPIO_6
	{3,12},    //GPIO_7
	{3,11},    //GPIO_8
	{4,8},   //GPIO_9
	{3,3},  //GPIO_10
	{4,3},   //GPIO_11
	{3,14},   //GPIO_12
	{3,15},    //GPIO_13
	{3,6},    //GPIO_14
	{3,5},    //GPIO_15
	{4,2},    //GPIO_16
	{4,4},    //GPIO_17
	{3,9},    //GPIO_18
	{3,2},    //GPIO_19
	{3,4},     //GPIO_20
	{3,10},     //GPIO_21
	{4,5},    //GPIO_22
	{6,13},    //GPIO_23
	{6,14},   //GPIO_24
	{6,15},    //GPIO_25
	{7,0},    //GPIO_26
	{5,3},    //GPIO_27
	{5,7},    //GPIO_28
	{4,9},    //GPIO_29
    {2,1},     //GPIO_30
	{2,3},     //GPIO_31
	{2,2},    //GPIO_32
	{5,2},    //GPIO_33
	{5,1},    //GPIO_34
	{5,0},    //GPIO_35
	{4,15},    //GPIO_36
	{4,13},    //GPIO_37
	{5,5},     //GPIO_38
	{5,14},    //GPIO_39
	{5,11},   //GPIO_40
	{5,13},    //GPIO_41
	{4,10},    //GPIO_42
	{5,6},    //GPIO_43
	{4,14},   //GPIO_44
	{4,6},   //GPIO_45
	{4,11},      //GPIO_46
	{5,10},      //GPIO_47
	{5,4},     //GPIO_48
	{5,12},    //GPIO_49
	{5,8},    //GPIO_50
	{5,9},    //GPIO_51
	{6,12},    //GPIO_52
	{6,5},    //GPIO_53
	{5,15},    //GPIO_54
	{6,0},   //GPIO_55
	{6,7},  //GPIO_56
	{6,1},   //GPIO_57
	{6,8},   //GPIO_58
	{6,10},    //GPIO_59
	{6,11},    //GPIO_60
	{6,3},    //GPIO_61
	{6,2},    //GPIO_62
	{6,6},    //GPIO_63
	{6,4},    //GPIO_64
	{6,9},    //GPIO_65
	{3,7},     //GPIO_66
	{1,13},     //GPIO_67
	{1,12},    //GPIO_68
	{2,0},    //GPIO_69
	{1,11},   //GPIO_70
	{1,14},    //GPIO_71
	{1,15},    //GPIO_72
	{0,0},    //GPIO_73
	{2,10},    //GPIO_74
	{0,1},    //GPIO_75
    {0,2},     //GPIO_76
	{7,7},     //GPIO_77
	{7,9},    //GPIO_78
	{7,8},    //GPIO_79
	{7,10},    //GPIO_80
	{2,14},    //GPIO_81
	{2,12},    //GPIO_82
	{2,11},    //GPIO_83
	{3,0},     //GPIO_84
	{2,15},    //GPIO_85
	{2,13},    //GPIO_86
//#else
//	{0,0},
 //#endif	
};

 const kal_uint16  gpio_6250_pupd_r0_r1_index[]={70,68,67,71,72,69,30,32,31,10,15,14,6,18,8,7,4,3,16,11,17,9,25};

const MT6250_GPIO_PUPD_R0_R1_MAP_Table_T  gpio_6250_pupd_R0_R1_map[]={
	{ 0,0,0,0,1,7},   //GPIO_70,
	{ 0,1,0,1,1,8},   //GPIO_68,
	{ 0,2,0,2,1,9},   //GPIO_67,
	{ 0,3,0,3,1,10},  //GPIO_71,
	{ 0,4,0,4,1,11},  //GPIO_72,
	{ 0,5,0,5,1,12},  //GPIO_69,
	{ 0,6,0,6,1,13},  //GPIO_30,
	{ 0,7,0,7,1,14},  //GPIO_32,
	{ 0,8,0,8,1,15},  //GPIO_31,
	{ 0,9,0,9,2,0},  //GPIO_10,
	{ 0,10,0,10,2,1}, //GPIO_15,
	{ 0,11,0,11,2,2},  //GPIO_14,
	{ 0,12,0,12,2,3},  //GPIO_6,
	{ 0,13,0,13,2,4},  //GPIO_18,
	{ 0,14,0,14,2,5},  //GPIO_8,
	{ 0,15,0,15,2,6},  //GPIO_7,
	{ 1,0,1,0,2,7},   //GPIO_4,
	{ 1,1,1,1,2,8},   //GPIO_3,
	{ 1,2,1,2,2,9},   //GPIO_16,
	{ 1,3,1,3,2,10},  //GPIO_11,
	{ 1,4,1,4,2,11},  //GPIO_17,
	{ 1,5,1,5,2,12},  //GPIO_9,
    { 1,6,1,6,2,13},  //GPIO_25,

};


#endif
/**********************************************************/

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   /*conf_data = 0~3*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;
      kal_uint32 savedMask;

      pin &= 0x00ff;
      modeno = pin/8;
      remainder = pin % 8;
      savedMask = SAVEANDSETIRQMASK();
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
      DRV_GPIO_WriteReg(GPIO_MODE(modeno),data);
      RESTOREIRQMASK(savedMask);
#endif /*!defined(DRV_GPIO_OFF)*/
   }
   
   void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;

      pin &= 0x00ff;
      modeno = pin/8;
      remainder = pin % 8;
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
      DRV_GPIO_WriteReg(GPIO_MODE(modeno),data);
#endif /*!defined(DRV_GPIO_OFF)*/
   }
 
   
   /*conf_data = 0~3*/
   void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 mode; 
      kal_uint32 savedMask;
      
      pin &= 0x00ff;
      savedMask = SAVEANDSETIRQMASK();
      mode = DRV_GPIO_Reg(GPI_O_MODE);
      mode &= ~(0x0003 << (pin*2));
      mode |= (conf_dada << (pin*2));
      DRV_GPIO_WriteReg(GPI_O_MODE,mode);
      RESTOREIRQMASK(savedMask);
#endif /*!defined(DRV_GPIO_OFF)*/
   }
#endif   /*DRV_GPIO_6208_FUNC, FPGA*/

#if defined(DRV_GPIO_6205_FUNC)
   /*conf_data = 0~3*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint32 savedMask;
      
      pin &= 0x00ff;
      modeno = pin/8;
      remainder = pin % 8;
      
      savedMask = SAVEANDSETIRQMASK();
      *(GPIO_MODE(modeno)) &= ~(0x0003 << (remainder*2));
      *(GPIO_MODE(modeno)) |= (conf_dada << (remainder*2));
      RESTOREIRQMASK(savedMask);
#endif /*!defined(DRV_GPIO_OFF)*/
   }
   
   
   void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      
      pin &= 0x00ff;
      modeno = pin/8;
      remainder = pin % 8;
      
      *(GPIO_MODE(modeno)) &= ~(0x0003 << (remainder*2));
      *(GPIO_MODE(modeno)) |= (conf_dada << (remainder*2));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
   
   
   /*conf_data = 0~3*/
   void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 mode; 
      kal_uint32 savedMask;
      
      pin &= 0x00ff;
      savedMask = SAVEANDSETIRQMASK();
      mode = DRV_GPIO_Reg(GPIO_MODE4);
      mode &= ~(0x0003 << (pin*2));
      mode |= (conf_dada << (pin*2));
      DRV_GPIO_WriteReg(GPIO_MODE4,mode);
      RESTOREIRQMASK(savedMask);
#endif /*!defined(DRV_GPIO_OFF)*/
   }
#endif   /*DRV_GPIO_6205_FUNC*/

#if defined(DRV_GPIO_6205B_FUNC)
   /*conf_data = 0~3*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;
      kal_uint32 savedMask;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_ModeSetup: GPIO Mode Not allowed");
             ret = sprintf(buff, "pin=%d, mode=%d", pin, conf_dada);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/8;
      remainder = pin % 8;
      
      savedMask = SAVEANDSETIRQMASK();
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
      DRV_GPIO_WriteReg(GPIO_MODE(modeno),data);
      RESTOREIRQMASK(savedMask);

      //DRV_GPIO_WriteReg(GPIO_MODE_CLR(modeno),(0x0003 << (remainder*2)));
      //DRV_GPIO_WriteReg(GPIO_MODE_SET(modeno),(conf_dada << (remainder*2)));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
   
   void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_ModeSetup_FAST: GPIO Mode Not allowed");
             ret = sprintf(buff, "pin=%d, mode=%d", pin, conf_dada);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/8;
      remainder = pin % 8;
      
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
      DRV_GPIO_WriteReg(GPIO_MODE(modeno),data);

      //DRV_GPIO_WriteReg(GPIO_MODE_CLR(modeno),(0x0003 << (remainder*2)));
      //DRV_GPIO_WriteReg(GPIO_MODE_SET(modeno),(conf_dada << (remainder*2)));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
 
   
   
   /*conf_data = 0~3*/
   void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 mode; 
      kal_uint32 savedMask;

      pin &= 0x00ff;
      #ifdef __CUST_NEW__   	
      pin &= (~GPO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpo_mode_allowed[conf_dada & 3]) & (1<<(pin & 0x0f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPO_ModeSetup: GPO Mode Not allowed");
             ret = sprintf(buff, "pin=%d, mode=%d", pin, conf_dada);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpo_mode_allowed[conf_dada & 3]) & (1<<(pin & 0x0f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
	     gpo_check_for_write[pin>>4] |= (1 << (pin & 0x0f));
      }
      #endif /* __CUST_NEW__ */
      savedMask = SAVEANDSETIRQMASK();
      mode = DRV_GPIO_Reg(GPIO_MODE4);
      mode &= ~(0x0003 << (pin*2));
      mode |= (conf_dada << (pin*2));
      DRV_GPIO_WriteReg(GPIO_MODE4,mode);
      RESTOREIRQMASK(savedMask);

      //DRV_GPIO_WriteReg(GPIO_MODE4_CLR,(0x0003 << (pin*2)));
      //DRV_GPIO_WriteReg(GPIO_MODE4_SET,(conf_dada << (pin*2)));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_FULL_FUNC)
   #if defined(DRV_GPIO_MODE_4BITS)
   /*conf_data = 0~7*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint32 savedMask;
	  #if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
      volatile kal_uint16 data_will_not_use;//modified by dongming for 6255 BUS latency problem
	  #endif
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
     #endif /* __CUST_NEW__ */
 
 #if !defined(DRV_GPIO_6250_SPECIAL_SET_REG)  
      if (gpio_debug_enable == KAL_TRUE)
      {
      #if defined(__GPIO_CHECK_ASSERT__)
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 7]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }

   #if defined(GPIO_MODE_32BIT_LENGTH)
      modeno = pin/8;
      remainder = pin % 8;      
      savedMask = SAVEANDSETIRQMASK();
      DRV_GPIO_SetData32(GPIO_MODE(modeno), (0x7 << (4*remainder)), (conf_dada << (4*remainder)));
      RESTOREIRQMASK(savedMask);
   #else //defined(GPIO_MODE_32BIT_LENGTH)
      modeno = pin/4;
      remainder = pin % 4;      
      savedMask = SAVEANDSETIRQMASK();
      DRV_GPIO_SetData(GPIO_MODE(modeno), (0x7 << (4*remainder)), (conf_dada << (4*remainder)));
      RESTOREIRQMASK(savedMask);
	  #endif
	  #else
         if(pin==FORBID_SET_GPIO_PIN_A  || ( pin>FORBID_SET_GPIO_PIN_B  && pin<FORBID_SET_GPIO_PIN_C))  // SW  could not set these pins
               ASSERT(0);

	  if(KAL_TRUE==Is_6250_ADIE_GPIO(pin))
		{
         // modeno=get_6250_adie_gpio_index(pin);
		 // if(ADIE_GPIO_ALLOWED[modeno][conf_dada]==0)
		  	//ASSERT(0);
		  	remainder = pin % 4; 
		savedMask = SAVEANDSETIRQMASK();
      DRV_GPIO_SetData(ACFG_GPIO_MODE, (0x7 << (4*remainder)), (conf_dada << (4*remainder)));
      RESTOREIRQMASK(savedMask);
	  }
	 if(KAL_FALSE==Is_6250_ADIE_GPIO(pin))
		 {
         modeno = pin/8;
      remainder = pin % 8;      
      savedMask = SAVEANDSETIRQMASK();
      DRV_GPIO_SetData32(GPIO_MODE(modeno), (0x7 << (4*remainder)), (conf_dada << (4*remainder)));
      RESTOREIRQMASK(savedMask);
		 }
	  
#endif  //!defined(DRV_GPIO_6250_SPECIAL_SET_REG)

#endif /*!defined(DRV_GPIO_OFF)*/
   }
char GPIO_ReturnMode(char port)
{
   #if !defined(DRV_GPIO_OFF)
   kal_uint16 modeno;
   kal_uint16 remainder;
   kal_uint32 data;   
   #ifdef __CUST_NEW__
      port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
    #if defined(GPIO_MODE_32BIT_LENGTH)
      modeno = port/8;
      remainder = port % 8;      
      data=DRV_GPIO_Reg32(GPIO_MODE(modeno)); 
      data=data&(0x7 << (4*remainder));
      data=(data >> (4*remainder));
      return (char)data;
   #else //defined(GPIO_MODE_32BIT_LENGTH)
      modeno = port/4;
      remainder = port % 4;      
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data=data&(0x7 << (4*remainder));
      data=(data >> (4*remainder));
      return (char)data;
   #endif //defined(GPIO_MODE_32BIT_LENGTH)   
   #else  /*!defined(DRV_GPIO_OFF)*/   
   return 0;
   #endif /*!defined(DRV_GPIO_OFF)*/
} 
   void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
	  #if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
     volatile kal_uint16 data_will_not_use;//modified by dongming for 6255 BUS latency problem
	  #endif
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #if defined(__GPIO_CHECK_ASSERT__)
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 7]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
   #if defined(GPIO_MODE_32BIT_LENGTH)
      modeno = pin/8;
      remainder = pin % 8;      
      DRV_GPIO_SetData32(GPIO_MODE(modeno), (0x7 << (4*remainder)), (conf_dada << (4*remainder)));
   #else //defined(GPIO_MODE_32BIT_LENGTH)
      modeno = pin/4;
      remainder = pin % 4;      
      DRV_GPIO_SetData(GPIO_MODE(modeno), (0x7 << (4*remainder)), (conf_dada << (4*remainder)));
	  #if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
	  data_will_not_use = DRV_GPIO_Reg(GPIO_MODE(modeno));//modified by dongming for 6255 BUS latency problem
	  #endif
   #endif //defined(GPIO_MODE_32BIT_LENGTH)

#endif /*!defined(DRV_GPIO_OFF)*/
   }
 #elif defined(DRV_GPIO_MODE_3BITS)   
void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
{
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint32 savedMask;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #if defined(__GPIO_CHECK_ASSERT__)
	  //there is a bug.
	  //is conf_data is big the 5, than access a address large than gpio_mode_allowed . -->may cause fatal error 
	  	  if(conf_dada>=5)
		  	{ASSERT(0);}
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 7]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/5;
      remainder = pin % 5;      
      savedMask = SAVEANDSETIRQMASK();
      DRV_GPIO_SetData(GPIO_MODE(modeno), (0x7 << (3*remainder)), (conf_dada << (3*remainder)));
      RESTOREIRQMASK(savedMask);
#endif /*!defined(DRV_GPIO_OFF)*/
}

void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #if defined(__GPIO_CHECK_ASSERT__)
	  	  if(conf_dada>=5)
		  	{ASSERT(0);}
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 7]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/5;
      remainder = pin % 5;      
      DRV_GPIO_SetData(GPIO_MODE(modeno), (0x7 << (3*remainder)), (conf_dada << (3*remainder)));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
 char GPIO_ReturnMode(char port)
{
   #if !defined(DRV_GPIO_OFF)
   kal_uint16 modeno;
   kal_uint16 remainder;
   kal_uint32 data;   
   #ifdef __CUST_NEW__
      port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   modeno = port/5;
   remainder = port % 5;      
   data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
   data=data&(0x7 << (3*remainder));
   data=(data >> (3*remainder));
   return (char)data;
   #else  /*!defined(DRV_GPIO_OFF)*/   
   return 0;
   #endif /*!defined(DRV_GPIO_OFF)*/  
}     
#else //defined(DRV_GPIO_MODE_4BITS)
   /*conf_data = 0~3*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;
      kal_uint32 savedMask;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f))))
            {
			    kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_ModeSetup: GPIO Mode Not allowed");
             ret = sprintf(buff, "pin=%d, mode=%d", pin, conf_dada);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/8;
      remainder = pin % 8;
      #if defined(DRV_GPIO_MODE8_SPECIAL_POS)
      if(pin>=56)/*special case  */
      {
         kal_uint16 mode; 

         savedMask = SAVEANDSETIRQMASK();
         mode = DRV_GPIO_Reg(GPIO_MODE8);
         mode &= ~(0x0003 << (remainder*2));
         mode |= (conf_dada << (remainder*2));
         DRV_GPIO_WriteReg(GPIO_MODE8,mode);
         RESTOREIRQMASK(savedMask);
         //DRV_GPIO_WriteReg(GPIO_MODE8_CLR,(0x0003 << (remainder*2)));
         //DRV_GPIO_WriteReg(GPIO_MODE8_SET,(conf_dada << (remainder*2)));
         return;
      }
      #endif                  
      
      savedMask = SAVEANDSETIRQMASK();
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
#ifdef DRV_GPIO_REG_AS_6223
      if ((modeno == 5) && (pin != 44))
         data ^= 0x0100; //mode44 LSB: set and clear are inversed in MT6223.
      else if ((modeno == 6) && (pin != 50))
         data ^= 0x0010; //mode50 LSB: set and clear are inversed in MT6223.
#endif
      DRV_GPIO_WriteReg(GPIO_MODE(modeno),data);
      RESTOREIRQMASK(savedMask);

      //DRV_GPIO_WriteReg(GPIO_MODE_CLR(modeno),(0x0003 << (remainder*2)));
      //DRV_GPIO_WriteReg(GPIO_MODE_SET(modeno),(conf_dada << (remainder*2)));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
   
   void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_ModeSetup_FAST: GPIO Mode Not allowed");
             ret = sprintf(buff, "pin=%d, mode=%d", pin, conf_dada);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/8;
      remainder = pin % 8;
      #if defined(DRV_GPIO_MODE8_SPECIAL_POS)
      if(pin>=56)/*special case  */
      {
         kal_uint16 mode; 

         mode = DRV_GPIO_Reg(GPIO_MODE8);
         mode &= ~(0x0003 << (remainder*2));
         mode |= (conf_dada << (remainder*2));
         DRV_GPIO_WriteReg(GPIO_MODE8,mode);

         //DRV_GPIO_WriteReg(GPIO_MODE8_CLR,(0x0003 << (remainder*2)));
         //DRV_GPIO_WriteReg(GPIO_MODE8_SET,(conf_dada << (remainder*2)));
         return;
      }
      #endif                  
      
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
#ifdef DRV_GPIO_REG_AS_6223
      if ((modeno == 5) && (pin != 44))
         data ^= 0x0100; //mode44 LSB: set and clear are inversed in MT6223.
      else if ((modeno == 6) && (pin != 50))
         data ^= 0x0010; //mode50 LSB: set and clear are inversed in MT6223.
#endif
      DRV_GPIO_WriteReg(GPIO_MODE(modeno),data);

      //DRV_GPIO_WriteReg(GPIO_MODE_CLR(modeno),(0x0003 << (remainder*2)));
      //DRV_GPIO_WriteReg(GPIO_MODE_SET(modeno),(conf_dada << (remainder*2)));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
char GPIO_ReturnMode(char port)
{
   #if !defined(DRV_GPIO_OFF)
   kal_uint16 modeno;
   kal_uint16 remainder;
   kal_uint32 data;   
   #ifdef __CUST_NEW__
      port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   
   #if defined(GPIO_MODE_32BIT_LENGTH)
      modeno = port/16;
      remainder = port % 16;      
      data=DRV_GPIO_Reg32(GPIO_MODE(modeno)); 
      data=data&(0x3 << (2*remainder));
      data=(data >> (2*remainder));
      return (char)data;
   #else //defined(GPIO_MODE_32BIT_LENGTH)
      modeno = port/8;
      remainder = port % 8;      
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data=data&(0x3 << (2*remainder));
      data=(data >> (2*remainder));
      return (char)data;
   #endif //defined(GPIO_MODE_32BIT_LENGTH)  
   #else  /*!defined(DRV_GPIO_OFF)*/   
   return 0;
   #endif /*!defined(DRV_GPIO_OFF)*/  
}    
   #endif //defined(DRV_GPIO_MODE_4BITS)
   
   /*conf_data = 0~3*/
   void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
   #if !defined(DRV_GPIO_WO_GPO)
      kal_uint16 mode; 
      kal_uint32 savedMask;

      pin &= 0x00ff;
      #ifdef __CUST_NEW__   	
      pin &= (~GPO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpo_mode_allowed[conf_dada & 3]) & (1<<(pin & 0x0f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPO_ModeSetup: GPO Mode Not allowed");
             ret = sprintf(buff, "pin=%d, mode=%d", pin, conf_dada);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpo_mode_allowed[conf_dada & 3]) & (1<<(pin & 0x0f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
	     gpo_check_for_write[pin>>4] |= (1 << (pin & 0x0f));
      }
      #endif /* __CUST_NEW__ */
      savedMask = SAVEANDSETIRQMASK();
      mode = DRV_GPIO_Reg(GPO_MODE);
      mode &= ~(0x0003 << (pin*2));
      mode |= (conf_dada << (pin*2));
      DRV_GPIO_WriteReg(GPO_MODE,mode);
      RESTOREIRQMASK(savedMask);

      //DRV_GPIO_WriteReg(GPO_MODE_CLR,(0x0003 << (pin*2)));
      //DRV_GPIO_WriteReg(GPO_MODE_SET,(conf_dada << (pin*2)));
   #endif /* !defined(DRV_GPIO_WO_GPO) */
#endif /*!defined(DRV_GPIO_OFF)*/
   }
/*
* FUNCTION                                                            
*	GPIO_PullenSetup
*
* DESCRIPTION                                                           
*   	This function is to enable or disable the pull up/down of the related GPIO pin.
*		You can not decide to pull up or down, it is set inside the chip.
*		And, the setting is different from pin by pin.
*
* PARAMETERS
*	pin : gpio pin number range from 0~54 (MT6219)
*	enable: enable the pull up/down
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*/
   void GPIO_PullenSetup(kal_uint16 pin, kal_bool enable)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
	  #if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
	 volatile kal_uint16 data_will_not_use;//modified by dongming for 6255 BUS latency problem
      #endif
      pin &= 0x00ff;
      #ifdef __CUST_NEW__   	
      pin &= (~GPIO_MAGIC_NUM);
      #endif /* __CUST_NEW__ */
#if !defined (DRV_GPIO_6250_SPECIAL_SET_REG)
      modeno = pin/16;
      remainder = pin % 16;
#else  // 6250 chip E1 ,E2 difference
    if(SW_SEC_0==INT_SW_SecVersion())   //for E1 
    	{
    modeno=gpio_6250_pull_en_sel_map[pin].reg_num;
    remainder=gpio_6250_pull_en_sel_map[pin].remainder;
     }
  else     // for E2
  	{
  	      modeno = pin/16;
      remainder = pin % 16;
      	}
#endif
		if(enable)
      	DRV_GPIO_WriteReg(GPIO_PULLEN_SET(modeno), 1 << remainder);
      else
      	DRV_GPIO_WriteReg(GPIO_PULLEN_CLR(modeno), 1 << remainder);
	  #if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
	  data_will_not_use = DRV_GPIO_Reg(GPIO_PULLEN_CLR(modeno));//modified by dongming for 6255 BUS latency problem
	  #endif
#endif /*!defined(DRV_GPIO_OFF)*/
   }
/*
* FUNCTION                                                            
*	GPIO_DinvSetup
*
* DESCRIPTION                                                           
*   	This function is to enable data invert of the related GPIO pin
*
* PARAMETERS
*	pin : gpio pin number range from 0~54 (MT6219)
*	enable: enable the data inversion
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*/
   void GPIO_DinvSetup(kal_uint16 pin, kal_bool enable)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
	  #if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
      volatile kal_uint16 data_will_not_use;//modified by dongming for 6255 BUS latency problem
	  #endif
      pin &= 0x00ff;
      #ifdef __CUST_NEW__   	
      //ASSERT(pin&GPIO_MAGIC_NUM);
      pin &= (~GPIO_MAGIC_NUM);
      #endif /* __CUST_NEW__ */
      modeno = pin/16;
      remainder = pin % 16;

		if(enable)
      {
         DRV_GPIO_SetBits(GPIO_DINV_ADRS(modeno), (1 << remainder));
      }
      else
      {
         DRV_GPIO_ClearBits(GPIO_DINV_ADRS(modeno), (1 << remainder));
      }
	  #if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
	  data_will_not_use = DRV_GPIO_Reg(GPIO_DINV_ADRS(modeno));//modified by dongming for 6255 BUS latency problem
	  #endif
#endif /*!defined(DRV_GPIO_OFF)*/
   }
   
#endif   /*DRV_GPIO_FULL_FUNC*/

/*
* FUNCTION                                                            
*	GPIO_PullSelSetup
*
* DESCRIPTION                                                           
*   	This function is to select pull up/down of the related GPIO pin.
*
* PARAMETERS
*	pin : gpio pin number range from 0~54 (MT6219)
*	enable: enable the pull up/down
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*/
void GPIO_PullSelSetup(kal_uint16 pin, kal_bool pull_up)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_PULL_SEL)
   kal_uint16 modeno;
   kal_uint16 remainder;
   #if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
   volatile kal_uint16 data_will_not_use;//modified by dongming for 6255 BUS latency problem
   #endif
   pin &= 0x00ff;
   #ifdef __CUST_NEW__   	
   pin &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */

#if !defined (DRV_GPIO_6250_SPECIAL_SET_REG)
   modeno = pin/16;
   remainder = pin % 16;
#else  // 6250 chip E1 ,E2 difference
    if( SW_SEC_0==INT_SW_SecVersion())
    	{
	  modeno=gpio_6250_pull_en_sel_map[pin].reg_num;
	  remainder=gpio_6250_pull_en_sel_map[pin].remainder;
  }
  else
  	{
  	      modeno = pin/16;
      remainder = pin % 16;
      	}
#endif

	if(pull_up)
      DRV_GPIO_WriteReg(GPIO_PULLSEL_SET(modeno), 1 << remainder);
   else
      DRV_GPIO_WriteReg(GPIO_PULLSEL_CLR(modeno), 1 << remainder);
   #if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
   data_will_not_use = DRV_GPIO_Reg(GPIO_PULLSEL_CLR(modeno));//modified by dongming for 6255 BUS latency problem
   #endif
#endif /*defined(DRV_GPIO_PULL_SEL)*/
#endif /*!defined(DRV_GPIO_OFF)*/
}


/*
* FUNCTION                                                            
*	GPIO_InitIO
*
* DESCRIPTION                                                           
*   	This function is to initialize one GPIO pin as INPUT or OUTPUT
*
* CALLS  
*	Initialize one GPIO pin as INPUT or OUTPUT
*
* PARAMETERS
*	direction: INPUT or OUTPUT
*	port: pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_InitIO(char direction, char port)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_6205_FUNC)
   if (direction == OUTPUT)
	{
	   if (port < 16)
      {
         DRV_GPIO_SetBits(GPIO_DIR, (1 << port));
      }
      else
      {
         DRV_GPIO_SetBits(GPIO_DIR2, (1 << (port-16)));
      }
	}
	else
	{
	   if (port < 16)
      {
         DRV_GPIO_ClearBits(GPIO_DIR, (1 << port));
      }
		else
      {
         DRV_GPIO_ClearBits(GPIO_DIR2, (1 << (port-16));
      }
	}
#endif /*DRV_GPIO_6205_FUNC*/

#if defined(DRV_GPIO_6205B_FUNC)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_InitIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   if (gpio_debug_enable == KAL_TRUE)
   {
      if (direction == 0)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO: Direction Input is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO: Direction Output is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
	  gpio_check_for_write[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
	  gpio_check_for_read[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
   }
   #endif /* __CUST_NEW__ */
   if (direction == OUTPUT)
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DIR_SET,(1 << port));
      else
         DRV_GPIO_WriteReg(GPIO_DIR2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
		   DRV_GPIO_WriteReg(GPIO_DIR_CLR,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DIR2_CLR,(1 << (port-16)));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
      
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_InitIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   if (gpio_debug_enable == KAL_TRUE)
   {
      if (direction == 0)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO: Direction Input is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO: Direction Output is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
	  gpio_check_for_write[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
	  gpio_check_for_read[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
   }
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
   if (direction == OUTPUT)
      DRV_GPIO_WriteReg(GPIO_DIR_SET(no),(1 << remainder));
	else
      DRV_GPIO_WriteReg(GPIO_DIR_CLR(no),(1 << remainder));
#endif   /*DRV_GPIO_FULL_FUNC*/

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
	if (direction == OUTPUT)
	{
      DRV_GPIO_SetBits(GPIO_DIR, (1 << port));
	}
	else
	{
      DRV_GPIO_ClearBits(GPIO_DIR, (1 << port));
	}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_ReadIO
*
* DESCRIPTION                                                           
*   	This function is to read data from one GPIO pin
*
* CALLS  
*	Read data from one GPIO pin
*
* PARAMETERS
*	port: pin number
*	
* RETURNS
*	1 or 0
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReadIO(char port)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_read[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         char dir;
         mode = GPIO_ReturnMode(port);
         dir = GPIO_ReturnDir(port);
         if ((mode != 0) || (dir != 0))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: mode or direction is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d, direction=%d", port, mode, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_read[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __CUST_NEW__ */
   if (port < 16)
	   return((DRV_GPIO_Reg(GPIO_DIN) >> port) & 1);
	else
	   return((DRV_GPIO_Reg(GPIO_DIN2) >> (port-16)) & 1);
#endif /*DRV_GPIO_6205_FUNC, DRV_GPIO_6205B_FUNC*/
#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   return((DRV_GPIO_Reg(GPIO_DIN) >> port) & 1);
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/
#if defined(DRV_GPIO_FULL_FUNC)
#if defined(DRV_GPIO_DIN_DISCONT)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_read[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         char dir;
         mode = GPIO_ReturnMode(port);
         dir = GPIO_ReturnDir(port);
         if ((mode != 0) || (dir != 0))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: mode or direction is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d, direction=%d", port, mode, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_read[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __CUST_NEW__ */
   if (port < 16)
	   return((DRV_GPIO_Reg(GPIO_DIN1) >> port) & 1);
	else if (port < 32)
	   return((DRV_GPIO_Reg(GPIO_DIN2) >> (port-16)) & 1);
	else if (port < 48)
	   return((DRV_GPIO_Reg(GPIO_DIN3) >> (port-32)) & 1);
	#if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6225)
	else if (port < 64)
	   return((DRV_GPIO_Reg(GPIO_DIN4) >> (port-48)) & 1);
	#endif
   else
   {
      ASSERT(0);
      return 0;
   }
#endif /* DRV_GPIO_DIN_DISCONT*/
#if defined(DRV_GPIO_DIN_CONTI)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data;   
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_read[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
   #if defined(DRV_GPIO_REG_AS_6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
   #endif /* DRV_GPIO_REG_AS_6228 */
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         char dir;
         dir = GPIO_ReturnDir(port);
         if (dir != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: direction is not correct.");
          ret = sprintf(buff, "pin=%d, direction=%d", port, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnDir(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_read[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
         		
   data=DRV_GPIO_Reg(GPIO_DIN(no));   
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (char)data;
   
#endif   /*DRV_GPIO_DIN_CONTI*/
#else /* DRV_GPIO_FULL_FUNC */
   return 0;
#endif /* DRV_GPIO_FULL_FUNC */
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_WriteIO
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPIO port
*
* CALLS  
*	Write data to one GPIO port
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	port: gpio pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/
void GPIO_WriteIO(char data, char port)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_6205_FUNC)
	if (data == 1)
	{
	   if (port < 16)
      {
         DRV_GPIO_SetBits(GPIO_DOUT, (1 << port));
      }
		else
      {
         DRV_GPIO_SetBits(GPIO_DOUT2, (1 << (port-16)));
      }
	}
	else
	{
	   if (port < 16)
      {
         DRV_GPIO_ClearBits(GPIO_DOUT, (1 << port));
      }
		else
      {
         DRV_GPIO_ClearBits(GPIO_DOUT2, (1 << (port-16))));
      }
	}
#endif /*(DRV_GPIO_6205_FUNC)*/

#if defined(DRV_GPIO_6205B_FUNC)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_write[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         char dir;
         mode = GPIO_ReturnMode(port);
         dir = GPIO_ReturnDir(port);
         if ((mode != 0) || (dir != 1))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: mode or direction is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d, direction=%d", port, mode, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_write[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __CUST_NEW__ */
	if (data == 1)
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DOUT_SET,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DOUT2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DOUT_CLR,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DOUT2_CLR,(1 << (port-16)));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
	if (data == 1)
	{
      DRV_GPIO_SetBits(GPIO_DOUT, (1 << port));
	}
	else
	{
      DRV_GPIO_ClearBits(GPIO_DOUT, (1 << port));
	}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
      
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_write[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
   #if defined(DRV_GPIO_REG_AS_6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
   #endif /*DRV_GPIO_REG_AS_6228*/
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         char dir;
         dir = GPIO_ReturnDir(port);
         if (dir != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: direction is not correct.");
          ret = sprintf(buff, "pin=%d, direction=%d", port, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnDir(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_write[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
   if (data == 1)
      DRV_GPIO_WriteReg(GPIO_DOUT_SET(no),(1 << remainder));
	else
      DRV_GPIO_WriteReg(GPIO_DOUT_CLR(no),(1 << remainder));
#endif   /*DRV_GPIO_FULL_FUNC*/
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPI_O_ReadIO
*
* DESCRIPTION                                                           
*   	This function is to read data from one GPI pin
*
* CALLS  
*	Read data from one GPI pin
*
* PARAMETERS
*	None
*	
* RETURNS
*	1 or 0
*
* GLOBALS AFFECTED
*   external_global
*/
#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
char GPI_ReadIO_(void)
{
#if !defined(DRV_GPIO_OFF)
	return((DRV_GPIO_Reg(GPI_O_DIO) >> 15) & 1);
#endif /*!defined(DRV_GPIO_OFF)*/
}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/
/*
* FUNCTION                                                            
*	GPI_O_WriteIO
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPO pin
*
* CALLS  
*	Write data to one GPO pin
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	port: gpo pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/

void GPO_WriteIO(char data,char port)
{
#if !defined(DRV_GPIO_OFF)
#if !defined(DRV_GPIO_WO_GPO)
#if defined(DRV_GPIO_6205_FUNC)
	if (data == 1)
	{
      DRV_GPIO_SetBits(GPO_DOUT, (1 << port));
	}
	else
	{
      DRV_GPIO_ClearBits(GPO_DOUT, (1 << port));
	}
#endif   /*(DRV_GPIO_6205_FUNC*/

#if defined(DRV_GPIO_6205B_FUNC)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPO_WriteIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(port & GPO_MAGIC_NUM);
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPO_MAGIC_NUM);
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpo_check_for_write[(kal_uint8)port>>4] & (1 << (port & 0x0f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPO_WriteIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPO_ReturnMode(port)== 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpo_check_for_write[(kal_uint8)port>>4] &= (~(1 << (port & 0x0f)));
   }
   #endif /* __CUST_NEW__ */
	if (data == 1)
	{
	   DRV_GPIO_WriteReg(GPO_DOUT_SET,(1 << port));
	}
	else
	{
	   DRV_GPIO_WriteReg(GPO_DOUT_CLR,(1 << port));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_FULL_FUNC)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPO_WriteIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(port & GPO_MAGIC_NUM);
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPO_MAGIC_NUM);
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpo_check_for_write[(kal_uint8)port>>4] & (1 << (port & 0x0f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPO_WriteIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPO_ReturnMode(port)== 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpo_check_for_write[(kal_uint8)port>>4] &= (~(1 << (port & 0x0f)));
   }
   #endif /* __CUST_NEW__ */
	if (data == 1)
	{
	   DRV_GPIO_WriteReg(GPO_DOUT_SET,(1 << port));
	}
	else
	{
	   DRV_GPIO_WriteReg(GPO_DOUT_CLR,(1 << port));
	}
#endif   /*DRV_GPIO_FULL_FUNC*/

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
	if (data == 1)
	{
      DRV_GPIO_SetBits(GPI_O_DIO, (1 << port));
	}
	else
	{
      DRV_GPIO_ClearBits(GPI_O_DIO, (1 << port));
	}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/
#endif /*!defined(DRV_GPIO_WO_GPO)*/
#endif /*!defined(DRV_GPIO_OFF)*/

}

/*
* FUNCTION                                                            
*	GPO_WriteAll
*
* DESCRIPTION                                                           
*   	This function is to write data to all GPO pins
*
* CALLS  
*	Write data to all GPO pins
*
* PARAMETERS
*	write_data: expected GPO data to all pins
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPO_WriteAll(kal_uint16 write_data)
{
#if !defined(DRV_GPIO_OFF)
#if !defined(DRV_GPIO_WO_GPO)
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
   DRV_GPIO_WriteReg(GPO_DOUT,write_data);
#endif   /*(DRV_GPIO_6205_FUNC,DRV_GPIO_6205B_FUNC)*/
#if defined(DRV_GPIO_FULL_FUNC)
   DRV_GPIO_WriteReg(GPO_DOUT,write_data);
#endif   /*DRV_GPIO_FULL_FUNC*/
#if ( (defined(DRV_GPIO_6208_FUNC)) || (defined(FPGA)) )
   DRV_GPIO_WriteReg(GPI_O_DIO,write_data);
#endif   /*(MT6208,FPGA)*/
#endif /*!defined(DRV_GPIO_WO_GPO)*/
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_ReturnDout
*
* DESCRIPTION                                                           
*   	This function is to report GPIO output value
*
* CALLS  
*	Report GPIO output value accoding to input pin
*
* PARAMETERS
*	GPIO pin 
*	
* RETURNS
*	GPIO output value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReturnDout(char port)
{
#if !defined(DRV_GPIO_OFF)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data=0;
   #ifdef __CUST_NEW__
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;

#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
   if(0==no)
      data=DRV_GPIO_Reg(GPIO_DOUT); 
   else if(1==no)
      data=DRV_GPIO_Reg(GPIO_DOUT2); 
#endif

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   data=DRV_GPIO_Reg(GPIO_DOUT); 	
#endif

#if defined(DRV_GPIO_FULL_FUNC)
   data=DRV_GPIO_Reg(GPIO_DOUT(no)); 
#endif   
   
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (char)data;
#else  /*!defined(DRV_GPIO_OFF)*/
   return 0;
#endif /*!defined(DRV_GPIO_OFF)*/
}
/*
* FUNCTION                                                            
*	GPO_ReturnDout
*
* DESCRIPTION                                                           
*   	This function is to report GPO output value
*
* CALLS  
*	Report GPO output value accoding to input pin
*
* PARAMETERS
*	GPO pin 
*	
* RETURNS
*	GPO output value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPO_ReturnDout(char port)
{
#if !defined(DRV_GPIO_OFF)
#if !defined(DRV_GPIO_WO_GPO)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data;   
   #ifdef __CUST_NEW__
   port &= (~GPO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;


#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   data=DRV_GPIO_Reg(GPI_O_DIO); 	
#endif

#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)||defined(DRV_GPIO_FULL_FUNC)
   data=DRV_GPIO_Reg(GPO_DOUT); 
#endif   

   data=data&(1 << remainder);
   data=(data >> remainder);
   return (char)data;
#else /* !defined(DRV_GPIO_WO_GPO) */   
   return 0;
#endif /* !defined(DRV_GPIO_WO_GPO) */   
#else /*!defined(DRV_GPIO_OFF)*/
   return 0;
#endif /*!defined(DRV_GPIO_OFF)*/
}
/*
* FUNCTION                                                            
*	GPIO_ReturnDir
*
* DESCRIPTION                                                           
*   	This function is to report GPIO direction value
*
* CALLS  
*	Report GPIO direction value accoding to input pin
*
* PARAMETERS
*	GPIO pin 
*	
* RETURNS
*	GPIO direction value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReturnDir(char port)
{
#if !defined(DRV_GPIO_OFF)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data=0;   
   #ifdef __CUST_NEW__
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
   if(0==no)
      data=DRV_GPIO_Reg(GPIO_DIR); 
   else if(1==no)
      data=DRV_GPIO_Reg(GPIO_DIR2); 
#endif
#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   data=DRV_GPIO_Reg(GPIO_DIR); 	
#endif
#if defined(DRV_GPIO_FULL_FUNC)
   data=DRV_GPIO_Reg(GPIO_DIR(no)); 
#endif   
   
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (char)data;

#else  /*!defined(DRV_GPIO_OFF)*/
   return 0;
#endif /*!defined(DRV_GPIO_OFF)*/
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
/* under construction !*/
#if !defined(DRV_GPIO_OFF)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #ifdef __CUST_NEW__
/* under construction !*/
   #endif /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else  /*!defined(DRV_GPIO_OFF)*/   
/* under construction !*/
#endif /*!defined(DRV_GPIO_OFF)*/
/* under construction !*/
#endif
/*
* FUNCTION                                                            
*	GPO_ReturnMode
*
* DESCRIPTION                                                           
*   	This function is to report GPO mode value
*
* CALLS  
*	Report GPO mode value accoding to input pin
*
* PARAMETERS
*	GPO pin 
*	
* RETURNS
*	GPO mode value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPO_ReturnMode(char port)
{
#if !defined(DRV_GPIO_OFF)
#if !defined(DRV_GPIO_WO_GPO)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint32 data;   
   #ifdef __CUST_NEW__
      port &= (~GPO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/8;
   remainder = port % 8;

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
    data=DRV_GPIO_Reg(GPIO_MODE2); 
#endif      
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
    data=DRV_GPIO_Reg(GPIO_MODE4); 
#endif   
#if defined(DRV_GPIO_FULL_FUNC)
   data=DRV_GPIO_Reg(GPO_MODE); 
#endif   
   data=data&(0x3 << (2*remainder));
   data=(data >> (2*remainder));
   return (char)data;
#else /* !defined(DRV_GPIO_WO_GPO) */   
   return 0;
#endif /* !defined(DRV_GPIO_WO_GPO) */   
#else /*!defined(DRV_GPIO_OFF)*/
   return 0;
#endif /*!defined(DRV_GPIO_OFF)*/
}   

/*
* FUNCTION                                                            
*	GPIO_SetDebugMode
*
* DESCRIPTION                                                           
*  This function is to set GPIO HW debug mode
*
* CALLS  
*	set GPIO HW debug mode
*
* PARAMETERS
*	enable   - KAL_TRUE: turn on the debug mode
*             KAL_FALSE: turn off the debug mode
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_SetDebugMode(kal_bool enable)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_DEBUG_MODE)
   if (enable == KAL_TRUE)
   {
      DRV_GPIO_WriteReg(GPIO_BANK,0);
   }
   else
   {
      DRV_GPIO_WriteReg(GPIO_BANK,1);
   }
#endif /* DRV_GPIO_DEBUG_MODE */
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_SetClkOut
*
* DESCRIPTION                                                           
*  This function is to set GPIO Clock output mode
*
* CALLS  
*	set GPIO Clock output mode
*
* PARAMETERS
*	clk_num   - 0~5; When clk_num is 0, it represents CLK ouput 1
*  mode      - enum value for clock output source mode
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_SetClkOut(char clk_num, gpio_clk_mode mode)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_CLK_OUT)
	#if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
	volatile kal_uint16 data_will_not_use;//modified by dongming for 6255 BUS latency problem
	#endif
   #if defined(DRV_GPIO_CLK_FROM_1)
   if ((clk_num > CLKO_NUM) || (clk_num < 1) || (mode >= mode_max_num))
      return;
   clk_num--;
   #else //DRV_GPIO_CLK_FROM_1
   if ((clk_num >= CLKO_NUM) || (mode >= mode_max_num))
 //  if ((clk_num >= CLKO_NUM) || (clk_num < 0) || (mode >= mode_max_num))
      return;
   #endif //DRV_GPIO_CLK_FROM_1
   DRV_GPIO_WriteReg(CLKO_MODE(clk_num), mode);
	#if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
   data_will_not_use = DRV_GPIO_Reg(CLKO_MODE(clk_num));//modified by dongming for 6255 BUS latency problem
	#endif
#elif defined(DRV_GPIO_CLK_OUT2)
   kal_uint32 savedMask;
	#if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
   volatile kal_uint16 data_will_not_use;
	#endif
   #if defined(DRV_GPIO_CLK_FROM_1)
   if ((clk_num > CLKO_NUM) || (clk_num < 1) || (mode >= mode_max_num))
      return;
   clk_num--;
   #else //DRV_GPIO_CLK_FROM_1
   if ((clk_num >= CLKO_NUM)  || (mode >= mode_max_num))
      return;
   #endif //DRV_GPIO_CLK_FROM_1
   savedMask = SAVEANDSETIRQMASK();
   #if defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6256) ||defined(DRV_GPIO_REG_AS_6250)
   DRV_GPIO_SetData(CLKO_MODE(clk_num), 0x000f, mode);
   #if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
   data_will_not_use = DRV_GPIO_Reg(CLKO_MODE(clk_num));//modified by dongming for 6255 BUS latency problem
	#endif
   #elif defined(DRV_GPIO_REG_AS_6276)
   DRV_GPIO_SetData(CLKO_MODE(clk_num), (0x000f<<4), (mode<<4));
   #endif //defined(DRV_GPIO_REG_AS_6255)
   RESTOREIRQMASK(savedMask);
#endif /* DRV_GPIO_CLK_OUT */
#endif /*!defined(DRV_GPIO_OFF)*/
}

void GPIO_SetClkDiv(char clk_num, gpio_clk_div div)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_CLK_OUT2)
   kal_uint32 savedMask;
	#if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
  volatile kal_uint16 data_will_not_use;//modified by dongming for 6255 BUS latency problem
	#endif
   #if defined(DRV_GPIO_CLK_FROM_1)
   if ((clk_num > CLKO_NUM) || (clk_num < 1) || (div >= div_max_num))
      return;
   clk_num--;
   #else //DRV_GPIO_CLK_FROM_1
   if ((clk_num >= CLKO_NUM) || (div >= div_max_num))
      return;
   #endif //DRV_GPIO_CLK_FROM_1
   savedMask = SAVEANDSETIRQMASK();
   #if defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6256)
   DRV_GPIO_SetData(CLKO_MODE(clk_num), (7<<4), (div<<4));
	#if defined(DRV_GPIO_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
   data_will_not_use = DRV_GPIO_Reg(CLKO_MODE(clk_num));//modified by dongming for 6255 BUS latency problem
	#endif
   #elif defined(DRV_GPIO_REG_AS_6276)
   DRV_GPIO_SetData(CLKO_MODE(clk_num), 0x000f, div);
   #endif //defined(DRV_GPIO_REG_AS_6255)
   RESTOREIRQMASK(savedMask);
#endif /* DRV_GPIO_CLK_OUT */
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_TMDir
*
* DESCRIPTION                                                           
*  This function is to set GPIO Test Mode direction
*
* CALLS  
*	set GPIO Test Mode direction
*
* PARAMETERS
*	pad_oe   - KAL_TRUE: Real pad OE
*             KAL_FALSE: MCU-configured
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_TMDir(kal_bool pad_oe)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_TM_DIR)
   if (pad_oe == KAL_TRUE)
      DRV_GPIO_WriteReg(GPIO_TM,1);
   else
      DRV_GPIO_WriteReg(GPIO_TM,0);
#endif /* DRV_GPIO_CLK_OUT */
#endif /*!defined(DRV_GPIO_OFF)*/
}


#ifdef __CUST_NEW__

/*
* FUNCTION                                                            
*	GPIO_InitIO_FAST
*
* DESCRIPTION                                                           
*   	This function is to initialize one GPIO pin as INPUT or OUTPUT. 
*  Note that it's for fast access without debug checking and only exists
*  when __CUST_NEW__ is defined.
*
* CALLS  
*	Initialize one GPIO pin as INPUT or OUTPUT
*
* PARAMETERS
*	direction: INPUT or OUTPUT
*	port: pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_InitIO_FAST(char direction, char port)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_6205B_FUNC)
   #ifdef __GPIO_FAST_DEBUB__
   if (gpio_debug_enable == KAL_TRUE)
   {
      if (direction == 0)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO_FAST: Direction Input is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO_FAST: Direction Output is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
	  gpio_check_for_write[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
	  gpio_check_for_read[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
   }
   #endif /* __GPIO_FAST_DEBUB__ */
   if (direction == OUTPUT)
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DIR_SET,(1 << port));
      else
         DRV_GPIO_WriteReg(GPIO_DIR2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
		   DRV_GPIO_WriteReg(GPIO_DIR_CLR,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DIR2_CLR,(1 << (port-16)));
	}
#endif   /*(DRV_GPIO_6205B_FUNC)*/

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
      
   #ifdef __GPIO_FAST_DEBUB__
   if (gpio_debug_enable == KAL_TRUE)
   {
      if (direction == 0)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO_FAST: Direction Input is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO_FAST: Direction Output is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
	  gpio_check_for_write[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
	  gpio_check_for_read[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
   }
   #endif /* __GPIO_FAST_DEBUB__ */
   #ifdef __CUST_NEW__   	
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
   if (direction == OUTPUT)
      DRV_GPIO_WriteReg(GPIO_DIR_SET(no),(1 << remainder));
	else
      DRV_GPIO_WriteReg(GPIO_DIR_CLR(no),(1 << remainder));
#endif   /*MT6218, MT6218B, MT6219, MT6217, MT6228, MT6229*/

#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_ReadIO_FAST
*
* DESCRIPTION                                                           
*   	This function is to read data from one GPIO pin.
*  Note that it's for fast access without debug checking and only exists
*  when __CUST_NEW__ is defined.
*
* CALLS  
*	Read data from one GPIO pin
*
* PARAMETERS
*	port: pin number
*	
* RETURNS
*	1 or 0
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReadIO_FAST(char port)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
   #ifdef __GPIO_FAST_DEBUB__
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_read[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         char dir;
         mode = GPIO_ReturnMode(port);
         dir = GPIO_ReturnDir(port);
         if ((mode != 0) || (dir != 0))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO_FAST: mode or direction is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d, direction=%d", port, mode, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_read[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __GPIO_FAST_DEBUB__ */
   if (port < 16)
	   return((DRV_GPIO_Reg(GPIO_DIN) >> port) & 1);
	else
	   return((DRV_GPIO_Reg(GPIO_DIN2) >> (port-16)) & 1);
#endif /*(DRV_GPIO_6205_FUNC,DRV_GPIO_6205B_FUNC)*/
#if defined(DRV_GPIO_FULL_FUNC)
#if defined(DRV_GPIO_DIN_DISCONT)
   #ifdef __GPIO_FAST_DEBUB__
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_read[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         char dir;
         mode = GPIO_ReturnMode(port);
         dir = GPIO_ReturnDir(port);
         if ((mode != 0) || (dir != 0))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO_FAST: mode or direction is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d, direction=%d", port, mode, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_read[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __GPIO_FAST_DEBUB__ */
   if (port < 16)
	   return((DRV_GPIO_Reg(GPIO_DIN1) >> port) & 1);
	else if (port < 32)
	   return((DRV_GPIO_Reg(GPIO_DIN2) >> (port-16)) & 1);
	else if (port < 48)
	   return((DRV_GPIO_Reg(GPIO_DIN3) >> (port-32)) & 1);
	#if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6225)
	else if (port < 64)
	   return((DRV_GPIO_Reg(GPIO_DIN4) >> (port-48)) & 1);
	#endif
   else
   {
      ASSERT(0);
      return 0;
   }
#endif
#if defined(DRV_GPIO_DIN_CONTI)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data;   
   #ifdef __GPIO_FAST_DEBUB__
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_read[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
   #if defined(DRV_GPIO_REG_AS_6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO_FAST: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
   #endif /* (defined(MT6228))*/
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO_FAST: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         char dir;
         dir = GPIO_ReturnDir(port);
         if (dir != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO_FAST: direction is not correct.");
          ret = sprintf(buff, "pin=%d, direction=%d", port, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnDir(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_read[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __GPIO_FAST_DEBUB__ */
   #ifdef __CUST_NEW__   	
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
         		
   data=DRV_GPIO_Reg(GPIO_DIN(no));   
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (char)data;
   
#endif   /*DRV_GPIO_DIN_CONTI*/
#else /* DRV_GPIO_FULL_FUNC */
   return 0;
#endif /* DRV_GPIO_FULL_FUNC */
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_WriteIO_FAST
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPIO port
*  Note that it's for fast access without debug checking and only exists
*  when __CUST_NEW__ is defined.
*
* CALLS  
*	Write data to one GPIO port
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	port: gpio pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/
void GPIO_WriteIO_FAST(char data, char port)
{
#if !defined(DRV_GPIO_OFF)
#ifdef DRV_GPIO_6205B_FUNC
   #ifdef __GPIO_FAST_DEBUB__
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_write[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         char dir;
         mode = GPIO_ReturnMode(port);
         dir = GPIO_ReturnDir(port);
         if ((mode != 0) || (dir != 1))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: mode or direction is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d, direction=%d", port, mode, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_write[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __GPIO_FAST_DEBUB__ */
	if (data == 1)
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DOUT_SET,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DOUT2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DOUT_CLR,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DOUT2_CLR,(1 << (port-16)));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
      
   #ifdef __GPIO_FAST_DEBUB__
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_write[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
   #if defined(DRV_GPIO_REG_AS_6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
   #endif /*DRV_GPIO_REG_AS_6228*/
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         char dir;
         dir = GPIO_ReturnDir(port);
         if (dir != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: direction is not correct.");
          ret = sprintf(buff, "pin=%d, direction=%d", port, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnDir(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_write[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __GPIO_FAST_DEBUB__ */
   #ifdef __CUST_NEW__   	
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
   if (data == 1)
      DRV_GPIO_WriteReg(GPIO_DOUT_SET(no),(1 << remainder));
	else
      DRV_GPIO_WriteReg(GPIO_DOUT_CLR(no),(1 << remainder));
#endif   /*MT6218, MT6218B, MT6219, MT6217, MT6228, MT6229*/
#endif /*!defined(DRV_GPIO_OFF)*/
}

#endif /* __CUST_NEW__ */

/*
* FUNCTION                                                            
*	GPIO_WriteIO_Force
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPIO port.
*  Note that when __CUST_NEW__ is defined and debug mode is enable,
*  this write action is still valid even if this port is not GPIO mode or not
*  set as output mode.
*
* CALLS  
*	Write data to one GPIO port
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	port: gpio pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/
void GPIO_WriteIO_Force(char data, char port)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_6205_FUNC)
	if (data == 1)
	{
	   if (port < 16)
      {
         DRV_GPIO_SetBits(GPIO_DOUT, (1 << port));
      }
		else
      {
         DRV_GPIO_SetBits(GPIO_DOUT2, (1 << (port-16)));
      }
	}
	else
	{
	   if (port < 16)
      {
         DRV_GPIO_ClearBits(GPIO_DOUT, (1 << port));
      }
		else
      {
         DRV_GPIO_ClearBits(GPIO_DOUT2, (1 << (port-16)));
      }
	}
#endif /*(DRV_GPIO_6205_FUNC)*/

#if defined(DRV_GPIO_6205B_FUNC)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_Force: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #else /* __GPIO_CHECK_WARNING__ */
      ASSERT((port & GPIO_MAGIC_NUM));
	  #endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
	if (data == 1)
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DOUT_SET,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DOUT2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DOUT_CLR,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DOUT2_CLR,(1 << (port-16)));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
	if (data == 1)
	{
      DRV_GPIO_SetBits(GPIO_DOUT, (1 << port));
	}
	else
	{
      DRV_GPIO_ClearBits(GPIO_DOUT, (1 << port));
	}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
      
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #else /* __GPIO_CHECK_WARNING__ */
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
   if (data == 1)
      DRV_GPIO_WriteReg(GPIO_DOUT_SET(no),(1 << remainder));
	else
      DRV_GPIO_WriteReg(GPIO_DOUT_CLR(no),(1 << remainder));
#endif   /*DRV_GPIO_FULL_FUNC*/
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_Check_MultiPins
*
* DESCRIPTION                                                           
*   	This function is to check the validity of GPIO mode and direction
*  for multiple GPIO ports.
*
* CALLS  
*	check the validity of GPIO mode and direction for multiple GPIO ports.
*
* PARAMETERS
*	check_ptr: pointer to an array of GPIOCheckStruct with element number 
*             by pin_cnt.
*	pin_cnt: gpio pin count that will be checked for validity
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/
void GPIO_Check_MultiPins(GPIOCheckStruct *check_ptr, kal_uint32 pin_cnt)
{
#if !defined(DRV_GPIO_OFF)
#ifdef __CUST_NEW__
   kal_uint32 index;
   kal_uint16 mode;
   char dir;

   for (index = 0; index < pin_cnt; index++, check_ptr++)
   {
	   kal_uint8	pin;

	   #if defined(DRV_GPIO_6205B_FUNC)
	      pin = check_ptr->pin_num & (~GPIO_MAGIC_NUM);
	      mode = GPIO_ReturnMode(pin);
         dir = GPIO_ReturnDir(pin);
         #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
          if ((mode != 0) || 
             ((check_ptr->dir!=GPIO_DIR_BOTH)&&(dir != check_ptr->dir)))
          {
            kal_int32 ret;
           system_print("GPIO WARNING!! GPIO_Check_MultiPins: NOT GPIO mode or Dir. Wrong.");
           ret = sprintf(buff, "pin=%d, mode=%d", pin, mode, dir);
           system_print(buff);
          }
         }
         #else /* __GPIO_CHECK_WARNING__ */
         ASSERT(mode==0);
         ASSERT((check_ptr->dir==GPIO_DIR_BOTH) || (dir == check_ptr->dir));
         #endif  /* __GPIO_CHECK_WARNING__ */
	   #endif   /*DRV_GPIO_6205B_FUNC*/
	   #if defined(DRV_GPIO_FULL_FUNC)
      #ifdef __GPIO_CHECK_WARNING__
      kal_bool gpio_mode = KAL_TRUE;
      #endif  /* __GPIO_CHECK_WARNING__ */
	   pin = check_ptr->pin_num & (~GPIO_MAGIC_NUM);
	   mode = GPIO_ReturnMode((char)pin);
      dir = GPIO_ReturnDir((char)pin);
	   #if defined(DRV_GPIO_REG_AS_6228)
      if(((pin > 25)&&(pin < 32)) || 
       ((pin > 43)&&(pin < 48)) || 
       ((pin > 53)&&(pin < 63)) || 
       ((pin > 67)&&(pin < 75)))
      {
        #ifdef __GPIO_CHECK_WARNING__
        if (mode != 1)
	        gpio_mode = KAL_FALSE;
        #else /* __GPIO_CHECK_WARNING__ */
        ASSERT(mode==1);
        ASSERT((check_ptr->dir==GPIO_DIR_BOTH) || (dir == check_ptr->dir));
        #endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
	   #endif /*DRV_GPIO_REG_AS_6228*/
      {
         #ifdef __GPIO_CHECK_WARNING__
         if (mode != 0)
           gpio_mode = KAL_FALSE;
         #else /* __GPIO_CHECK_WARNING__ */
         ASSERT(mode==0);
         ASSERT((check_ptr->dir==GPIO_DIR_BOTH) || (dir == check_ptr->dir));
         #endif  /* __GPIO_CHECK_WARNING__ */
      }
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if ((gpio_mode == KAL_FALSE) ||
             ((check_ptr->dir!=GPIO_DIR_BOTH)&&(dir != check_ptr->dir)))
         {
            kal_int32 ret;
            system_print("GPIO WARNING!! GPIO_Check_MultiPins: NOT GPIO mode or Dir. Wrong.");
            ret = sprintf(buff, "pin=%d, mode=%d, dir=%d", pin, mode, dir);
            system_print(buff);
         }
      }
      #endif  /* __GPIO_CHECK_WARNING__ */
	   #endif   /*DRV_GPIO_FULL_FUNC*/
   }
#endif /* __CUST_NEW__ */
#endif /*!defined(DRV_GPIO_OFF)*/
}
#pragma arm section code = "INTERNCODE"
/*
* FUNCTION                                                            
*	GPIO_WriteIO_FAST2
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPIO port
*  Note that it's for faster access without debug checking.
*
* CALLS  
*	Write data to one GPIO port
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	no: no = port/16; port: GPIO port number
*	remainder_shift: remainder_shift = 1<<(port%16);
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/
void GPIO_WriteIO_FAST2(char data, kal_uint16 no, kal_uint16 remainder_shift)
{
#if !defined(DRV_GPIO_OFF)
#ifdef DRV_GPIO_6205B_FUNC
   #if defined(__CUST_NEW__)&&defined(__GPIO_FAST_DEBUB__)
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_write[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
      char port;
      kal_uint16 index;

      for (index = 0; index < 16; index++)
      {
         if (remainder_shift & (1 << index))
            break;
      }
      port = (char)((no<<4)+(index&0x000f));
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         char dir;
         mode = GPIO_ReturnMode(port);
         dir = GPIO_ReturnDir(port);
         if ((mode != 0) || (dir != 1))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: mode or direction is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d, direction=%d", port, mode, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_write[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __GPIO_FAST_DEBUB__ */
   DRV_GPIO_WriteReg(GPIO_DOUT_CLR+(no<<2)-(data<<6),remainder_shift);
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_FULL_FUNC)
   #if defined(__CUST_NEW__)&&defined(__GPIO_FAST_DEBUB__)
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_write[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
      char port;
      kal_uint16 index;

      for (index = 0; index < 16; index++)
      {
         if (remainder_shift & (1 << index))
            break;
      }
      port = (char)((no<<4)+(index&0x000f));
   #if defined(DRV_GPIO_REG_AS_6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
   #endif /*DRV_GPIO_REG_AS_6228*/
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         char dir;
         dir = GPIO_ReturnDir(port);
         if (dir != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: direction is not correct.");
          ret = sprintf(buff, "pin=%d, direction=%d", port, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnDir(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_write[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __GPIO_FAST_DEBUB__ */
	DRV_GPIO_WriteReg(GPIO_DOUT_CLR(no) - (data*4), remainder_shift);
#endif   /*MT6218, MT6218B, MT6219, MT6217, MT6228, MT6229*/
#endif /*!defined(DRV_GPIO_OFF)*/
}

//#if defined (DRV_GPIO_6250_SPECIAL_SET_REG)

void GPIO_6250_set_pupd_R0_R1(kal_uint16 pin, kal_bool pupd_en,kal_bool r0,kal_bool r1)
   {
   #if !defined(DRV_GPIO_OFF)
   #if defined(DRV_GPIO_6250_SPECIAL_SET_REG)

    kal_uint16 modeno1;
      kal_uint16 remainder1;
	   kal_uint16 modeno2;
      kal_uint16 remainder2;
	   kal_uint16 modeno3;
      kal_uint16 remainder3;
	  kal_uint16  gpio_pupd_r0_r1_index;
      pin &= 0x00ff;
      #ifdef __CUST_NEW__   	
      pin &= (~GPIO_MAGIC_NUM);
      #endif /* __CUST_NEW__ */
       gpio_pupd_r0_r1_index=get_6250_pupd_R0_R1_index(pin);
	  if(INVALID_PUPD_R0_R1_INDEX==gpio_pupd_r0_r1_index)
	  	ASSERT(0);
	   modeno1=gpio_6250_pupd_R0_R1_map[gpio_pupd_r0_r1_index].pupd_reg_num;
	   remainder1=gpio_6250_pupd_R0_R1_map[gpio_pupd_r0_r1_index].pupd_remainder;
	   modeno2=gpio_6250_pupd_R0_R1_map[gpio_pupd_r0_r1_index].R0_reg_num;
	   remainder2=gpio_6250_pupd_R0_R1_map[gpio_pupd_r0_r1_index].R0_remainder;
	   modeno3=gpio_6250_pupd_R0_R1_map[gpio_pupd_r0_r1_index].R1_reg_num;
	   remainder3=gpio_6250_pupd_R0_R1_map[gpio_pupd_r0_r1_index].R1_remainder;
	   
      if(r0)
      	 DRV_GPIO_WriteReg(GPIO_RESEN_SET(modeno2), 1 << remainder2);
      else
      	 DRV_GPIO_WriteReg(GPIO_RESEN_CLR(modeno2), 1 << remainder2);

	  if(r1)
      	 DRV_GPIO_WriteReg(GPIO_RESEN_SET(modeno3), 1 << remainder3);
      else
      	 DRV_GPIO_WriteReg(GPIO_RESEN_CLR(modeno3), 1 << remainder3);
	  if(pupd_en)
         DRV_GPIO_WriteReg(GPIO_PUPDEN_SET(modeno1), 1 << remainder1);
      else
         DRV_GPIO_WriteReg(GPIO_PUPDEN_CLR(modeno1), 1 << remainder1);	
	  
#endif /*!defined(DRV_GPIO_OFF)*/
#endif
   }

 kal_uint16  get_6250_pupd_R0_R1_index( kal_uint16	pin_num)
 	{   
 	#if !defined(DRV_GPIO_OFF)
	#if defined(DRV_GPIO_6250_SPECIAL_SET_REG)
	static kal_uint16  u2cnt1;

	for (u2cnt1= 0;
	u2cnt1<sizeof(gpio_6250_pupd_r0_r1_index)/sizeof(*gpio_6250_pupd_r0_r1_index);
	u2cnt1++)
	{
		if(gpio_6250_pupd_r0_r1_index[u2cnt1]==pin_num)

		return  u2cnt1;
		
	}
	return  INVALID_PUPD_R0_R1_INDEX;
	#else
	return  KAL_FALSE;
    #endif 
	#endif
 }
 kal_bool  Is_6250_ADIE_GPIO( kal_uint16 pin)
 	{
 	#if !defined(DRV_GPIO_OFF)
	#if defined(DRV_GPIO_6250_SPECIAL_SET_REG)
     if(pin< ADIE_MIN_GPIO_PIN  || pin> ADIE_MAX_GPIO_PIN)
        return  KAL_FALSE;
      else
	  	return  KAL_TRUE;
	#else
	return KAL_FALSE;
	#endif 
	#endif
     }

//#endif  //defined (DRV_GPIO_6250_SPECIAL_SET_REG)
#pragma arm section code


#endif //DRV_GPIO_NEW_SW_ARCHI

