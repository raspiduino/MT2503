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
 *    gpio_setting.c
 *
 * Project:
 * --------
 *   Dragonfly
 *
 * Description:
 * ------------
 *   This Module defines the GPIO and GPO settings.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __CUST_NEW__
#include "gpio_def.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "gpio_hw.h"
#include "gpio_sw.h"
#include "gpio_drv.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "kal_general_types.h"
#ifdef DRV_GPIO_NEW_SW_ARCHI

/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/******** If DRV_GPIO is not off, we will open to use  GPIO_DRV_TOOL ****************/

#if !defined(DRV_GPIO_OFF)    
       #define __CHIP_SUPP_GPIO_DRV_TOOL__
#endif //#if !defined(DRV_GPIO_OFF)


/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/*****General macro to calculate GPIO word-length variable value with 1 bit unit.****/

#define GPIO_HWORD_REG_VAL(name, port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, port10, \
	                            port11, port12, port13, port14, port15, port16, port17, port18, port19, port20, port21, \
                               port22, port23, port24, port25, port26, port27, port28, port29, port30, port31)      \
((GPIO_PORT##port0##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*0) & 0x1f)) | \
(GPIO_PORT##port1##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*1) & 0x1f)) |	\
(GPIO_PORT##port2##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*2) & 0x1f)) |   \
(GPIO_PORT##port3##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*3) & 0x1f)) |	\
(GPIO_PORT##port4##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*4) & 0x1f)) | \
(GPIO_PORT##port5##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*5) & 0x1f)) | 	\
(GPIO_PORT##port6##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*6) & 0x1f)) | \
(GPIO_PORT##port7##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*7) & 0x1f)) | 	\
(GPIO_PORT##port8##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*8) & 0x1f)) | \
(GPIO_PORT##port9##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*9) & 0x1f)) |	\
(GPIO_PORT##port10##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*10) & 0x1f)) |\
(GPIO_PORT##port11##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*11) & 0x1f)) |	\
(GPIO_PORT##port12##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*12) & 0x1f)) | \
(GPIO_PORT##port13##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*13) & 0x1f)) | 	\
(GPIO_PORT##port14##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*14) & 0x1f)) | \
(GPIO_PORT##port15##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*15) & 0x1f)) | 	\
(GPIO_PORT##port16##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*16) & 0x1f)) | \
(GPIO_PORT##port17##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*17) & 0x1f)) |	\
(GPIO_PORT##port18##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*18) & 0x1f)) |	\
(GPIO_PORT##port19##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*19) & 0x1f)) |	\
(GPIO_PORT##port20##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*20) & 0x1f)) | \
(GPIO_PORT##port21##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*21) & 0x1f)) | 	\
(GPIO_PORT##port22##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*22) & 0x1f)) | \
(GPIO_PORT##port23##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*23) & 0x1f)) | 	\
(GPIO_PORT##port24##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*24) & 0x1f)) | \
(GPIO_PORT##port25##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*25) & 0x1f)) |	\
(GPIO_PORT##port26##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*26) & 0x1f)) |	\
(GPIO_PORT##port27##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*27) & 0x1f)) |	\
(GPIO_PORT##port28##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*28) & 0x1f)) | \
(GPIO_PORT##port29##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*29) & 0x1f)) | 	\
(GPIO_PORT##port30##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*30) & 0x1f)) | \
(GPIO_PORT##port31##_##name<<((GPIO_##name##_##ONE_CONTROL_BITS*31) & 0x1f) ))

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/*********************************__CHIP_SUPP_GPIO_DRV_TOOL__****************************/


#define GPIO_WORD_VAR_FOR_1BIT(name, port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, port10, \
	                            port11, port12, port13, port14, port15, port16, port17, port18, port19, port20, port21, \
                               port22, port23, port24, port25, port26, port27, port28, port29, port30, port31) \
    ((name##_GPIO##port0) | (name##_GPIO##port1<<1) | (name##_GPIO##port2<<2) | (name##_GPIO##port3<<3) | (name##_GPIO##port4<<4) | \
    (name##_GPIO##port5<<5) | (name##_GPIO##port6<<6) | (name##_GPIO##port7<<7) | (name##_GPIO##port8<<8) | (name##_GPIO##port9<<9) | \
    (name##_GPIO##port10<<10) | (name##_GPIO##port11<<11) | (name##_GPIO##port12<<12) | (name##_GPIO##port13<<13) | (name##_GPIO##port14<<14) | \
    (name##_GPIO##port15<<15) | (name##_GPIO##port16<<16) | (name##_GPIO##port17<<17) | (name##_GPIO##port18<<18) | (name##_GPIO##port19<<19) | \
    (name##_GPIO##port20<<20) | (name##_GPIO##port21<<21) | (name##_GPIO##port22<<22) | (name##_GPIO##port23<<23) | (name##_GPIO##port24<<24) | \
    (name##_GPIO##port25<<25) | (name##_GPIO##port26<<26) | (name##_GPIO##port27<<27) | (name##_GPIO##port28<<28) | (name##_GPIO##port29<<29) | \
    (name##_GPIO##port30<<30) | (name##_GPIO##port31<<31))




const kal_uint32   gpio_mode_allowed[][GPIO_HAVE_MAX_MODE+1] = {GPIO_MODE_ALLOWED_ARRAY};
 kal_uint32  gpio_check_for_write[] = {GPIO_CHECK_FOR_WRITE_ARRAY};
 kal_uint32  gpio_check_for_read[] = {GPIO_CHECK_FOR_READ_ARRAY};
 const kal_uint32  gpio_dir_out_allowed[] = {GPIO_DIR_OUT_ALLOWED_ARRAY};
 const kal_uint32  gpio_dir_in_allowed[] = {GPIO_DIR_IN_ALLOWED_ARRAY};



#ifdef __MTK_TARGET__
void DDIE_MODE_Init(void)
{
	kal_uint8 i;

#ifdef GPIO_MODE_REG_MAX_NUM	
	kal_uint32 mode_temp[GPIO_MODE_REG_MAX_NUM+1] = { GPIO_MODE_ALL_VALUE };
	for(i = 0; i <= GPIO_MODE_REG_MAX_NUM; i++)
	{
	#if (GPIO_MODE_REG_BITS == 32)
			DRV_GPIO_WriteReg32(GPIO_MODE(i), mode_temp[i]);
	#elif(GPIO_MODE_REG_BITS == 16) 
			DRV_GPIO_WriteReg(GPIO_MODE(i), mode_temp[i]);
	#else
		#error "The mode register bits error: neither 32bit nor 16bit "
	#endif
	}
#endif
}
void DDIE_DIR_Init(void)
{
	kal_uint8 i;

#ifdef GPIO_DIR_REG_MAX_NUM
	kal_uint32 dir_temp[GPIO_DIR_REG_MAX_NUM+1] = { GPIO_DIR_ALL_VALUE };
	for(i = 0; i <= GPIO_DIR_REG_MAX_NUM; i++)
	{
	#if (GPIO_DIR_REG_BITS == 32)
			DRV_GPIO_WriteReg32(GPIO_DIR(i),dir_temp[i]);
	#elif(GPIO_DIR_REG_BITS == 16)	
			DRV_GPIO_WriteReg(GPIO_DIR(i),dir_temp[i]);
	#else
		#error "The dir register bits error: neither 32bit nor 16bit "
	#endif
	}
#endif
}
void DDIE_PULL_SEL_Init(void)
{
	kal_uint8 i;

#ifdef GPIO_PULL_SEL_REG_MAX_NUM
	kal_uint32 pullsel_temp[GPIO_PULL_SEL_REG_MAX_NUM+1] = { GPIO_PULL_SEL_ALL_VALUE };
	for(i = 0; i <= GPIO_PULL_SEL_REG_MAX_NUM; i++)
	{
	#if (GPIO_PULL_SEL_REG_BITS == 32)
			DRV_GPIO_WriteReg32(GPIO_PULLSEL(i),pullsel_temp[i]);
	#elif(GPIO_PULL_SEL_REG_BITS == 16) 
			DRV_GPIO_WriteReg(GPIO_PULLSEL(i),pullsel_temp[i]);
	#else
		#error "The pull sel register bits error: neither 32bit nor 16bit "
	#endif
	}
	 	#endif
}
void DDIE_PULLEN_Init(void)
{
	kal_uint8 i;

#ifdef GPIO_PULL_REG_MAX_NUM
	kal_uint32 pullen_temp[GPIO_PULL_REG_MAX_NUM+1] = { GPIO_PULL_ALL_VALUE };
	for(i = 0; i <= GPIO_PULL_REG_MAX_NUM; i++)
	{
	#if (GPIO_PULL_REG_BITS == 32)
			DRV_GPIO_WriteReg32(GPIO_PULLEN(i),pullen_temp[i]);
	#elif(GPIO_PULL_REG_BITS == 16) 
			DRV_GPIO_WriteReg(GPIO_PULLEN(i),pullen_temp[i]);
	#else
		#error "The pull register bits error: neither 32bit nor 16bit "
	#endif
	}				
	#endif
}
void DDIE_INV_Init(void)
{
	kal_uint8 i;

#ifdef GPIO_INV_REG_MAX_NUM
kal_uint32 dinv_temp[GPIO_INV_REG_MAX_NUM+1] = { GPIO_INV_ALL_VALUE };
for(i = 0; i <= GPIO_INV_REG_MAX_NUM; i++)
{
	#if (GPIO_INV_REG_BITS == 32)
			DRV_GPIO_WriteReg(GPIO_DINV_ADRS(i),dinv_temp[i]);	
	#elif(GPIO_INV_REG_BITS == 16) 
			DRV_GPIO_WriteReg(GPIO_DINV_ADRS(i),dinv_temp[i]);	
	#else
	#error "The dinv register bits error: neither 32bit nor 16bit " 	
	#endif
	}		
	#endif
}
void DDIE_OUTPUT_Init(void)
{
	kal_uint8 i;

#ifdef GPIO_OUTPUT_LEVEL_REG_MAX_NUM
 kal_uint32 dout_temp[GPIO_OUTPUT_LEVEL_REG_MAX_NUM+1] = { GPIO_OUTPUT_LEVEL_ALL_VALUE };

 for(i = 0; i <= GPIO_OUTPUT_LEVEL_REG_MAX_NUM; i++)
{
	#if (GPIO_OUTPUT_LEVEL_REG_BITS == 32)
			DRV_GPIO_WriteReg32(GPIO_OUTPUT_LEVEL(i),dout_temp[i]);
	#elif(GPIO_OUTPUT_LEVEL_REG_BITS == 16) 
			DRV_GPIO_WriteReg(GPIO_OUTPUT_LEVEL(i),dout_temp[i]);
	#else
		#error "The output level register bits error: neither 32bit nor 16bit " 	
	#endif
}
	#endif
}

void DDIE_PUPD_Init(void)
{
	kal_uint8 i;
		
	#ifdef GPIO_PUPD_REG_MAX_NUM
	 kal_uint32 pupd_temp[GPIO_PUPD_REG_MAX_NUM+1] = { GPIO_PUPD_ALL_VALUE };

	 for(i = 0; i <= GPIO_PUPD_REG_MAX_NUM; i++)
	 {
	#if (GPIO_PUPD_REG_BITS == 32)
				DRV_GPIO_WriteReg32(GPIO_PUPDEN(i),pupd_temp[i]);	 
	#elif(GPIO_PUPD_REG_BITS == 16) 
		DRV_GPIO_WriteReg(GPIO_PUPDEN(i),pupd_temp[i]);	 
	#else
		#error "The PUPD register bits error: neither 32bit nor 16bit " 	
	#endif
	}
	 	#endif
}
void DDIE_R0_Init(void)
{
	kal_uint8 i;

#ifdef GPIO_R0_REG_MAX_NUM
	 kal_uint32 r0_temp[GPIO_R0_REG_MAX_NUM+1] = { GPIO_R0_ALL_VALUE };

	 for(i = 0; i <= GPIO_R0_REG_MAX_NUM; i++)
	 {
	#if (GPIO_R0_REG_BITS == 32)
			DRV_GPIO_WriteReg32(GPIO_RESEN_R0(i),r0_temp[i]);	 
	#elif(GPIO_R0_REG_BITS == 16) 
			DRV_GPIO_WriteReg(GPIO_RESEN_R0(i),r0_temp[i]);	 
	#else
		#error "The R0 register bits error: neither 32bit nor 16bit "		
	#endif
	}
 #endif
}
void DDIE_R1_Init(void)
{
	kal_uint8 i;

#ifdef GPIO_R1_REG_MAX_NUM
	kal_uint32 r1_temp[GPIO_R1_REG_MAX_NUM+1] = { GPIO_R1_ALL_VALUE };

	for(i = 0; i <= GPIO_R1_REG_MAX_NUM; i++)
	 {
	#if (GPIO_R1_REG_BITS == 32)
			DRV_GPIO_WriteReg32(GPIO_RESEN_R1(i),r1_temp[i]);	
	#elif(GPIO_R1_REG_BITS == 16) 
			DRV_GPIO_WriteReg(GPIO_RESEN_R1(i),r1_temp[i]);	
	#else
		#error "The R1 register bits error: neither 32bit nor 16bit "		
	#endif
	}		
	#endif
}

void ADIE_MODE_Init(void)
{
	kal_uint8 i;

#ifdef GPIO_ADIE_MODE_REG_MAX_NUM
	kal_uint32 adie_mode_temp[GPIO_ADIE_MODE_REG_MAX_NUM + 1] = { GPIO_ADIE_MODE_ALL_VALUE };

	for(i = 0; i <= GPIO_ADIE_MODE_REG_MAX_NUM; i++)
	 {
	#if (GPIO_ADIE_MODE_REG_BITS == 32)
			 DRV_GPIO_WriteReg32(GPIO_ADIE_MODE(i),adie_mode_temp[i]);
	#elif(GPIO_ADIE_MODE_REG_BITS == 16) 
		 DRV_GPIO_WriteReg(GPIO_ADIE_MODE(i),adie_mode_temp[i]);
	#else
		#error "The ADIE_MODE register bits error: neither 32bit nor 16bit "		
	#endif
	}					
#endif
}

void ADIE_DIR_Init(void)
{
	kal_uint8 i;

#ifdef GPIO_ADIE_DIR_REG_MAX_NUM
		 kal_uint32 adie_dir_temp[GPIO_ADIE_DIR_REG_MAX_NUM+1] = { GPIO_ADIE_DIR_ALL_VALUE };

		 for(i = 0; i <= GPIO_ADIE_DIR_REG_MAX_NUM; i++)
		{
		#if (GPIO_ADIE_DIR_REG_BITS == 32)
			DRV_GPIO_WriteReg32(GPIO_ADIE_DIR(i),adie_dir_temp[i]);
		#elif(GPIO_ADIE_DIR_REG_BITS == 16) 
			DRV_GPIO_WriteReg(GPIO_ADIE_DIR(i),adie_dir_temp[i]);
		#else
			#error "The ADIE_DIR register bits error: neither 32bit nor 16bit "		
		#endif
		}					
#endif
}
void ADIE_OUTPUT_LEVEL_Init(void)
{
	kal_uint8 i;
#ifdef GPIO_ADIE_OUTPUT_LEVEL_REG_MAX_NUM
		kal_uint32 adie_dout_temp[GPIO_ADIE_OUTPUT_LEVEL_REG_MAX_NUM+1] = { GPIO_ADIE_OUTPUT_LEVEL_ALL_VALUE };

		for(i = 0; i <= GPIO_ADIE_OUTPUT_LEVEL_REG_MAX_NUM; i++)
		{
		#if (GPIO_ADIE_OUTPUT_LEVEL_REG_BITS == 32)
			DRV_GPIO_WriteReg32(GPIO_ADIE_OUTPUT_LEVEL(i),adie_dout_temp[i]);
		#elif(GPIO_ADIE_OUTPUT_LEVEL_REG_BITS == 16) 
			DRV_GPIO_WriteReg(GPIO_ADIE_OUTPUT_LEVEL(i),adie_dout_temp[i]);
		#else
			#error "The ADIE_OUTPUT_LEVEL register bits error: neither 32bit nor 16bit "		
		#endif
		}
#endif
}
void ADIE_PULL_Init(void)
{
	kal_uint8 i;
#ifdef GPIO_ADIE_PULL_REG_MAX_NUM
		kal_uint32 adie_dout_temp[GPIO_ADIE_PULL_REG_MAX_NUM+1] = { GPIO_ADIE_PULL_ALL_VALUE };

		for(i = 0; i <= GPIO_ADIE_PULL_REG_MAX_NUM; i++)
		{
		#if (GPIO_ADIE_PULL_REG_BITS == 32)
			DRV_GPIO_WriteReg32(GPIO_ADIE_PULL(i),adie_dout_temp[i]);
		#elif(GPIO_ADIE_PULL_REG_BITS == 16) 
			DRV_GPIO_WriteReg(GPIO_ADIE_PULL(i),adie_dout_temp[i]);
		#else
			#error "The ADIE_PULL register bits error: neither 32bit nor 16bit "		
		#endif
		}
#endif
}


void ADIE_PULL_SEL_Init(void)
{
	kal_uint8 i;
#ifdef GPIO_ADIE_PULL_SEL_REG_MAX_NUM
		kal_uint32 adie_dout_temp[GPIO_ADIE_PULL_SEL_REG_MAX_NUM+1] = { GPIO_ADIE_PULL_SEL_ALL_VALUE };

		for(i = 0; i <= GPIO_ADIE_PULL_SEL_REG_MAX_NUM; i++)
		{
		#if (GPIO_ADIE_PULL_SEL_REG_BITS == 32)
			DRV_GPIO_WriteReg32(GPIO_ADIE_PULL_SEL(i),adie_dout_temp[i]);
		#elif(GPIO_ADIE_PULL_SEL_REG_BITS == 16) 
			DRV_GPIO_WriteReg(GPIO_ADIE_PULL_SEL(i),adie_dout_temp[i]);
		#else
			#error "The ADIE_PULL_SEL register bits error: neither 32bit nor 16bit "		
		#endif
		}
#endif
}



void ADIE_SPECIAL_CASE_Init(void)
{
	kal_uint8 i;
#ifdef GPIO_ADIE_SPECIAL_CASE_REG_MAX_NUM
	kal_uint32 adie_special_case_all_addr[GPIO_ADIE_SPECIAL_CASE_REG_MAX_NUM+1] = { GPIO_ADIE_SPECIAL_CASE_ALL_ADDR};
	kal_uint32 adie_special_case_all_value[GPIO_ADIE_SPECIAL_CASE_REG_MAX_NUM+1] = { GPIO_ADIE_SPECIAL_CASE_ALL_VALUE };

	for(i = 0; i <= GPIO_ADIE_SPECIAL_CASE_REG_MAX_NUM; i++)
		{
		DRV_GPIO_WriteReg(adie_special_case_all_addr[i],adie_special_case_all_value[i]);
		}
 #endif
}
#endif

void GPIO_setting_init(void)
{
#ifdef __MTK_TARGET__
#ifdef DRV_GPIO_NEW_SW_ARCHI
	DDIE_MODE_Init();
	DDIE_DIR_Init();
	DDIE_PULL_SEL_Init();
	DDIE_PULLEN_Init();
	DDIE_INV_Init();
	DDIE_OUTPUT_Init();	
	DDIE_PUPD_Init();
	DDIE_R0_Init();
	DDIE_R1_Init();
	ADIE_MODE_Init();
	ADIE_DIR_Init();
	ADIE_OUTPUT_LEVEL_Init();
	ADIE_PULL_Init();
	ADIE_PULL_SEL_Init();
	ADIE_SPECIAL_CASE_Init();	
	
	#if defined(MT6260)
	//for GPIO design limitation   ---  die to die
	(*(volatile kal_uint16 *)(0xa0730144)) |= 0x11;  
	(*(volatile kal_uint32 *)(0xa0020c90)) |= 0x11111110;
	
   (*(volatile kal_uint16 *)(0xa0730104)) &= (~(0xf <<3)); 
	
	DRV_GPIO_WriteReg32(0xA0020E00,0x04);//dongming: set clock mode0 to 32K mode. for RF desense

	#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
	DRV_GPIO_WriteReg32(0xA0020C58,0x00700000); //set gpio 45 as MODE0
	DRV_GPIO_WriteReg32(0xA0020014,0x00002000); // set gpio 45 as output
	DRV_GPIO_WriteReg32(0xA0020318,0x00002000); // set gpio 45 as output low
	
	#endif
#endif
#endif// __MTK_TARGET__


}


#else //#ifdef DRV_GPIO_NEW_SW_ARCHI


#if defined(DRV_GPIO_6250_SPECIAL_SET_REG)

#define GPIO_PORTNULL_MODE  1
#else
#define GPIO_PORTNULL_MODE  0
#endif
#define GPO_PORTNULL_MODE  0
#define GPIO_PORTNULL_DIR   0
#define GPIO_PORTNULL_PULL  0
#define GPIO_PORTNULL_INV   0
#define GPIO_PORTNULL_OUTPUT_LEVEL  0
#define GPO_PORTNULL_OUTPUT_LEVEL  0
#define GPIO_PORTNULL_PULL_SEL  0
#define GPIO_PORTNULL_R0    0
#define GPIO_PORTNULL_R1    0
#define GPIO_PORTNULL_PUPD  0
#define GPIO_PORTNULL_DOUT  0
#define GPIO_PORTNULL_OE    0



#define MODE0_GPIONULL     0
#define MODE1_GPIONULL     0
#define MODE2_GPIONULL     0
#define MODE3_GPIONULL     0
#define MODE4_GPIONULL     0
#define MODE5_GPIONULL     0
#define MODE6_GPIONULL     0
#define MODE7_GPIONULL     0
#define MODE8_GPIONULL     0


#define DIR_OUT_GPIONULL   0
#define DIR_IN_GPIONULL   0

/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/******** If DRV_GPIO is not off, we will open to use  GPIO_DRV_TOOL ****************/

#if !defined(DRV_GPIO_OFF)    
    #if defined(DRV_GPIO_REG_AS_6205B) || defined(DRV_GPIO_REG_AS_6218B) || defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_TK6516) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6270A) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6251) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1)|| defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6250)
       #define __CHIP_SUPP_GPIO_DRV_TOOL__
    #else
       #error "No support driver customization tool for this chip."
    #endif
#endif //#if !defined(DRV_GPIO_OFF)

/************************************************************************************/
/***************************MT6250   GPIO SPEC  REG    CONTROL****************************/
/********************for  PULLSEL, PULLEN,PUPD,R0,R1,A-DIE  GPIO  *****************************/
/************************************************************************************/
#if defined(DRV_GPIO_6250_SPECIAL_SET_REG)

#define GPIO_HWORD_SPEC_REG_FOR_1BIT(name, port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, \
                                port10, port11, port12, port13, port14, port15)	\
    ((GPIO_PORT##port0##_##name) | (GPIO_PORT##port1##_##name<<1) | (GPIO_PORT##port2##_##name<<2) |         \
    (GPIO_PORT##port3##_##name<<3) | (GPIO_PORT##port4##_##name<<4) | (GPIO_PORT##port5##_##name<<5) |       \
    (GPIO_PORT##port6##_##name<<6) | (GPIO_PORT##port7##_##name<<7) | (GPIO_PORT##port8##_##name<<8) |       \
    (GPIO_PORT##port9##_##name<<9) | (GPIO_PORT##port10##_##name<<10) | (GPIO_PORT##port11##_##name<<11) |   \
    (GPIO_PORT##port12##_##name<<12) | (GPIO_PORT##port13##_##name<<13) | (GPIO_PORT##port14##_##name<<14) | \
    (GPIO_PORT##port15##_##name<<15))

#define GPIO_HWORD_R0_R1_FOR_1BIT( port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, \
                                port10, port11, port12, port13, port14, port15)	\
    ((GPIO_PORT##port0##_##R0) | (GPIO_PORT##port1##_##R0<<1) | (GPIO_PORT##port2##_##R0<<2) |         \
    (GPIO_PORT##port3##_##R0<<3) | (GPIO_PORT##port4##_##R0<<4) | (GPIO_PORT##port5##_##R0<<5) |       \
    (GPIO_PORT##port6##_##R0<<6) | (GPIO_PORT##port7##_##R1<<7) | (GPIO_PORT##port8##_##R1<<8) |       \
    (GPIO_PORT##port9##_##R1<<9) | (GPIO_PORT##port10##_##R1<<10) | (GPIO_PORT##port11##_##R1<<11) |   \
    (GPIO_PORT##port12##_##R1<<12) | (GPIO_PORT##port13##_##R1<<13) | (GPIO_PORT##port14##_##R1<<14) | \
    (GPIO_PORT##port15##_##R1<<15))
	
#define GPIO_HWORD_ADIE_OE_DOUT_FOR_1BIT( port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, \
									port10, port11, port12, port13, port14, port15) \
		((GPIO_PORT##port0##_##DOUT) | (GPIO_PORT##port1##_##DOUT<<1) | (GPIO_PORT##port2##_##DOUT<<2) |		 \
		(GPIO_PORT##port3##_##DOUT<<3) | (GPIO_PORT##port4##_##DOUT<<4) | (GPIO_PORT##port5##_##DOUT<<5) |		 \
		(GPIO_PORT##port6##_##DOUT<<6) | (GPIO_PORT##port7##_##DOUT<<7) | (GPIO_PORT##port8##_##OE<<8) |		 \
		(GPIO_PORT##port9##_##OE<<9) | (GPIO_PORT##port10##_##OE<<10) | (GPIO_PORT##port11##_##OE<<11) |	 \
		(GPIO_PORT##port12##_##OE<<12) | (GPIO_PORT##port13##_##OE<<13) | (GPIO_PORT##port14##_##OE<<14) | \
		(GPIO_PORT##port15##_##OE<<15))

#define GPIO_MODE_ADIE_4BITS_REG_VAL(port0, port1, port2, port3) 				\
	   ((GPIO_PORT##port0##_MODE) | (GPIO_PORT##port1##_MODE<<4) | (GPIO_PORT##port2##_MODE<<8) |	 \
	   (GPIO_PORT##port3##_MODE<<12))

#endif

/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/***************General macro to calculate GPIO MODE register************************/


#if defined(DRV_GPIO_MODE_4BITS)
   #if defined(GPIO_MODE_32BIT_LENGTH)
      #define GPIO_MODE_4BITS_REG_VAL(port0, port1, port2, port3, port4, port5, port6, port7) \
          ((GPIO_PORT##port0##_MODE) | (GPIO_PORT##port1##_MODE<<4) | (GPIO_PORT##port2##_MODE<<8) |    \
          (GPIO_PORT##port3##_MODE<<12) | (GPIO_PORT##port4##_MODE<<16) | (GPIO_PORT##port5##_MODE<<20) | \
          (GPIO_PORT##port6##_MODE<<24) | (GPIO_PORT##port7##_MODE<<28))
   #else //defined(GPIO_MODE_32BIT_LENGTH)
     /* General macro to calculate GPIO MODE (with 4 bits per mode) register. */
       #define GPIO_MODE_4BITS_REG_VAL(port0, port1, port2, port3)                 \
          ((GPIO_PORT##port0##_MODE) | (GPIO_PORT##port1##_MODE<<4) | (GPIO_PORT##port2##_MODE<<8) |    \
          (GPIO_PORT##port3##_MODE<<12))
   #endif // define(GPIO_MODE_32BIT_LENGTH)
#elif defined(DRV_GPIO_MODE_3BITS)
	#define GPIO_MODE_3BITS_REG_VAL(port0,port1,port2,port3,port4)	\
		((GPIO_PORT##port0##_MODE) | (GPIO_PORT##port1##_MODE<<3) | (GPIO_PORT##port2##_MODE<<6) |	  \
		(GPIO_PORT##port3##_MODE<<9) | (GPIO_PORT##port4##_MODE<<12))
#else //defined(DRV_GPIO_MODE_4BITS)

    #define GPIO_MODE_REG_VAL(port0, port1, port2, port3, port4, port5, port6, port7)                 \
      ((GPIO_PORT##port0##_MODE) | (GPIO_PORT##port1##_MODE<<2) | (GPIO_PORT##port2##_MODE<<4) |    \
      (GPIO_PORT##port3##_MODE<<6) | (GPIO_PORT##port4##_MODE<<8) | (GPIO_PORT##port5##_MODE<<10) | \
      (GPIO_PORT##port6##_MODE<<12) | (GPIO_PORT##port7##_MODE<<14))
#endif //defined(DRV_GPIO_MODE_4BITS)


/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/****************** General macro to calculate GPO MODE register********************/


#define GPO_MODE_REG_VAL(port0, port1, port2, port3, port4, port5, port6, port7)                 \
    ((GPO_PORT##port0##_MODE) | (GPO_PORT##port1##_MODE<<2) | (GPO_PORT##port2##_MODE<<4) |    \
    (GPO_PORT##port3##_MODE<<6) | (GPO_PORT##port4##_MODE<<8) | (GPO_PORT##port5##_MODE<<10) | \
    (GPO_PORT##port6##_MODE<<12) | (GPO_PORT##port7##_MODE<<14))



/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************* General macro to calculate GPIO register with 1 bit unit**************/


#define GPIO_HWORD_REG_FOR_1BIT(name, port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, \
                                port10, port11, port12, port13, port14, port15)	\
    ((GPIO_PORT##port0##_##name) | (GPIO_PORT##port1##_##name<<1) | (GPIO_PORT##port2##_##name<<2) |         \
    (GPIO_PORT##port3##_##name<<3) | (GPIO_PORT##port4##_##name<<4) | (GPIO_PORT##port5##_##name<<5) |       \
    (GPIO_PORT##port6##_##name<<6) | (GPIO_PORT##port7##_##name<<7) | (GPIO_PORT##port8##_##name<<8) |       \
    (GPIO_PORT##port9##_##name<<9) | (GPIO_PORT##port10##_##name<<10) | (GPIO_PORT##port11##_##name<<11) |   \
    (GPIO_PORT##port12##_##name<<12) | (GPIO_PORT##port13##_##name<<13) | (GPIO_PORT##port14##_##name<<14) | \
    (GPIO_PORT##port15##_##name<<15))


/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/***************** General macro to calculate GPO register with 1 bit unit.**********/

#define GPO_HWORD_REG_FOR_1BIT(name, port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, \
                                port10, port11, port12, port13, port14, port15)	\
    ((GPO_PORT##port0##_##name) | (GPO_PORT##port1##_##name<<1) | (GPO_PORT##port2##_##name<<2) |         \
    (GPO_PORT##port3##_##name<<3) | (GPO_PORT##port4##_##name<<4) | (GPO_PORT##port5##_##name<<5) |       \
    (GPO_PORT##port6##_##name<<6) | (GPO_PORT##port7##_##name<<7) | (GPO_PORT##port8##_##name<<8) |       \
    (GPO_PORT##port9##_##name<<9) | (GPO_PORT##port10##_##name<<10) | (GPO_PORT##port11##_##name<<11) |   \
    (GPO_PORT##port12##_##name<<12) | (GPO_PORT##port13##_##name<<13) | (GPO_PORT##port14##_##name<<14) | \
    (GPO_PORT##port15##_##name<<15))


/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/*****General macro to calculate GPIO word-length variable value with 1 bit unit.****/


#define GPIO_WORD_VAR_FOR_1BIT(name, port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, port10, \
	                            port11, port12, port13, port14, port15, port16, port17, port18, port19, port20, port21, \
                               port22, port23, port24, port25, port26, port27, port28, port29, port30, port31) \
    ((name##_GPIO##port0) | (name##_GPIO##port1<<1) | (name##_GPIO##port2<<2) | (name##_GPIO##port3<<3) | (name##_GPIO##port4<<4) | \
    (name##_GPIO##port5<<5) | (name##_GPIO##port6<<6) | (name##_GPIO##port7<<7) | (name##_GPIO##port8<<8) | (name##_GPIO##port9<<9) | \
    (name##_GPIO##port10<<10) | (name##_GPIO##port11<<11) | (name##_GPIO##port12<<12) | (name##_GPIO##port13<<13) | (name##_GPIO##port14<<14) | \
    (name##_GPIO##port15<<15) | (name##_GPIO##port16<<16) | (name##_GPIO##port17<<17) | (name##_GPIO##port18<<18) | (name##_GPIO##port19<<19) | \
    (name##_GPIO##port20<<20) | (name##_GPIO##port21<<21) | (name##_GPIO##port22<<22) | (name##_GPIO##port23<<23) | (name##_GPIO##port24<<24) | \
    (name##_GPIO##port25<<25) | (name##_GPIO##port26<<26) | (name##_GPIO##port27<<27) | (name##_GPIO##port28<<28) | (name##_GPIO##port29<<29) | \
    (name##_GPIO##port30<<30) | (name##_GPIO##port31<<31))



/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/*********************************__CHIP_SUPP_GPIO_DRV_TOOL__****************************/

#if defined(__CHIP_SUPP_GPIO_DRV_TOOL__)

/***************************GPIO MODE IS NEITHER 4 BIT NOR 3 BIT**********START*********/

#if !defined(DRV_GPIO_MODE_4BITS) && !defined(DRV_GPIO_MODE_3BITS)
   /* GPIO mode register values for different platforms. */

  #if defined(DRV_GPIO_REG_AS_TK6516)
      #define GPIO_MODE_REG1  GPIO_MODE_REG_VAL(0, 1, 2, 3, NULL, NULL, NULL, NULL)
  #else /* DRV_GPIO_REG_AS_TK6516 */
     #define GPIO_MODE_REG1  GPIO_MODE_REG_VAL(0, 1, 2, 3, 4, 5, 6, 7)
     #define GPIO_MODE_REG2  GPIO_MODE_REG_VAL(8, 9, 10, 11, 12, 13, 14, 15)
     #if defined(DRV_GPIO_REG_AS_6205B)
         #define GPIO_MODE_REG3  GPIO_MODE_REG_VAL(16, 17, 18, 19, 20, 21, NULL, NULL)
         #define GPO_MODE_REG    GPO_MODE_REG_VAL(0, 1, 2, 3, NULL, NULL, NULL, NULL)
     #elif defined(DRV_GPIO_REG_AS_6270A)
          #define GPIO_MODE_REG3  GPIO_MODE_REG_VAL(16, 17, 18, 19, 20, 21, 22, 23)
          #define GPIO_MODE_REG4  GPIO_MODE_REG_VAL(24, 25, 26, 27, NULL, NULL, NULL, NULL)
     #else /* DRV_GPIO_REG_AS_6270A */
          #define GPIO_MODE_REG3  GPIO_MODE_REG_VAL(16, 17, 18, 19, 20, 21, 22, 23)
          #define GPIO_MODE_REG4  GPIO_MODE_REG_VAL(24, 25, 26, 27, 28, 29, 30, 31)
          #define GPIO_MODE_REG5  GPIO_MODE_REG_VAL(32, 33, 34, 35, 36, 37, 38, 39)
          #define GPIO_MODE_REG6  GPIO_MODE_REG_VAL(40, 41, 42, 43, 44, 45, 46, 47)
         #if defined(DRV_GPIO_REG_AS_6218B)
              #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, NULL, NULL, NULL, NULL, NULL)
         #elif defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6225)
             #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, 53, 54, NULL)
             #if defined(DRV_GPIO_REG_AS_6219)
                 #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, 3, 4, NULL, NULL, NULL)
             #elif defined(DRV_GPIO_REG_AS_6225)
                 #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, 3, NULL, NULL, NULL, NULL)
             #endif
         #elif defined(DRV_GPIO_REG_AS_6227)
             #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, 53, 54, 55)
             #define GPIO_MODE_REG8  GPIO_MODE_REG_VAL(56, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
             #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, 3, 4, NULL, NULL, NULL)
        #elif defined(DRV_GPIO_REG_AS_6228)
            #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, 53, 54, 55)
            #define GPIO_MODE_REG8  GPIO_MODE_REG_VAL(56, 57, 58, 59, 60, 61, 62, 63)
            #define GPIO_MODE_REG9  GPIO_MODE_REG_VAL(64, 65, 66, 67, 68, 69, 70, 71)
            #define GPIO_MODE_REG10  GPIO_MODE_REG_VAL(72, 73, 74, NULL, NULL, NULL, NULL, NULL)
            #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, NULL, NULL, NULL, NULL, NULL)
        #elif defined(DRV_GPIO_REG_AS_6223)
            #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, NULL, NULL, NULL)
        #elif defined(DRV_GPIO_REG_AS_6238)  || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E)
            #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, 53, 54, 55)
            #define GPIO_MODE_REG8  GPIO_MODE_REG_VAL(56, 57, 58, 59, 60, 61, 62, 63)
         #if defined(DRV_GPIO_REG_AS_6236) 
            #define GPIO_MODE_REG9  GPIO_MODE_REG_VAL(64, 65, 66, 67, NULL, NULL, NULL, NULL)
         #else // defined(DRV_GPIO_REG_AS_6236) 
            #define GPIO_MODE_REG9  GPIO_MODE_REG_VAL(64, 65, 66, 67, 68, 69, 70, 71)
            #if defined(DRV_GPIO_REG_AS_6238)
               #define GPIO_MODE_REGA  GPIO_MODE_REG_VAL(72, 73, 74, 75, 76, 77, 78, 79)
               #define GPIO_MODE_REGB  GPIO_MODE_REG_VAL(80, 81, 82, 83, 84, NULL, NULL, NULL)
            #elif defined(DRV_GPIO_REG_AS_6235)
               #define GPIO_MODE_REGA  GPIO_MODE_REG_VAL(72, 73, 74, 75, 76, 77, 78, NULL)
            #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
               #define GPIO_MODE_REGA  GPIO_MODE_REG_VAL(72, 73, 74, 75, 76, 77, 78, 79)
               #define GPIO_MODE_REGB  GPIO_MODE_REG_VAL(80, 81, 82, 83, 84, 85, 86, 87)
               #define GPIO_MODE_REGC  GPIO_MODE_REG_VAL(88, 89, 90, 91, 92, 93, 94, 95)
               #if defined(DRV_GPIO_REG_AS_6268A)
               #define GPIO_MODE_REGD  GPIO_MODE_REG_VAL(96, 97, 98, 99, 100, NULL, NULL, NULL)
               #elif defined(DRV_GPIO_REG_AS_6268)
               #define GPIO_MODE_REGD  GPIO_MODE_REG_VAL(96, 97, 98, 99, NULL, NULL, NULL, NULL)
               #elif defined(DRV_GPIO_REG_AS_6276)
               #define GPIO_MODE_REGD  GPIO_MODE_REG_VAL(96, 97, 98, 99, 100, 101, 102, 103)
               #define GPIO_MODE_REGE  GPIO_MODE_REG_VAL(104, 105, 106, 107, 108, NULL, NULL, NULL)
               #endif
            #elif defined(DRV_GPIO_REG_AS_6253T)
               #define GPIO_MODE_REGA  GPIO_MODE_REG_VAL(72, 73, 74, 75, 76, 77, 78, 79)
               #if defined(DRV_GPIO_6253_MODE11_DEFAULT)
                  #define GPIO_PORT82FOR6253_MODE MODE_1 //GPIO82 for MT6253 should be fixed to mode1
                  #define GPIO_MODE_REGB  GPIO_MODE_REG_VAL(80, 81, 82FOR6253, NULL, NULL, NULL, NULL, NULL)
               #else //defined(DRV_GPIO_6253_MODE11_DEFAULT)
               #define GPIO_MODE_REGB  GPIO_MODE_REG_VAL(80, 81, NULL, NULL, NULL, NULL, NULL, NULL)
               #endif //defined(DRV_GPIO_6253_MODE11_DEFAULT)
            #endif
         #endif // defined(DRV_GPIO_REG_AS_6236) 
      #endif
   #endif /* DRV_GPIO_REG_AS_6205B */
#endif /* DRV_GPIO_REG_AS_TK6516 */


/***************************GPIO MODE IS NEITHER 4 BIT NOR 3 BIT**********END*********/


/***************************GPIO MODE IS 4 BIT ***********************START***********/

#elif defined(DRV_GPIO_MODE_4BITS) // DRV_GPIO_MODE_4BITS is defined
#if defined(DRV_GPIO_REG_AS_6253E_1)
   #define GPIO_MODE_REG1  GPIO_MODE_4BITS_REG_VAL(0, 1, 2, 3, 4, 5, 6, 7)
   #define GPIO_MODE_REG2  GPIO_MODE_4BITS_REG_VAL(8, 9, 10, 11, 12, 13, 14, 15)
   #define GPIO_MODE_REG3  GPIO_MODE_4BITS_REG_VAL(16, 17, 18, 19, 20, 21, 22, 23)
   #define GPIO_MODE_REG4  GPIO_MODE_4BITS_REG_VAL(24, 25, 26, 27, 28, 29, 30, 31)
   #define GPIO_MODE_REG5  GPIO_MODE_4BITS_REG_VAL(32, 33, 34, 35, 36, 37, 38, 39)
   #define GPIO_MODE_REG6  GPIO_MODE_4BITS_REG_VAL(40, 41, 42, 43, 44, 45, 46, 47)
   #define GPIO_MODE_REG7  GPIO_MODE_4BITS_REG_VAL(48, 49, 50, 51, 52, 53, 54, 55)
   #define GPIO_MODE_REG8  GPIO_MODE_4BITS_REG_VAL(56, 57, 58, 59, 60, 61, 62, 63)
   #define GPIO_MODE_REG9  GPIO_MODE_4BITS_REG_VAL(64, 65, 66, 67, 68, 69, 70, NULL)
#endif //defined(DRV_GPIO_REG_AS_6253E_1)
#if defined(DRV_GPIO_REG_AS_6255) 
   #define GPIO_MODE_REG1  GPIO_MODE_4BITS_REG_VAL(0, 1, 2, 3)
   #define GPIO_MODE_REG2  GPIO_MODE_4BITS_REG_VAL(4, 5, 6, 7)
   #define GPIO_MODE_REG3  GPIO_MODE_4BITS_REG_VAL(8, 9, 10, 11)
   #define GPIO_MODE_REG4  GPIO_MODE_4BITS_REG_VAL(12, 13, 14, 15)
   #define GPIO_MODE_REG5  GPIO_MODE_4BITS_REG_VAL(16, 17, 18, 19)
   #define GPIO_MODE_REG6  GPIO_MODE_4BITS_REG_VAL(20, 21, 22, 23)
   #define GPIO_MODE_REG7  GPIO_MODE_4BITS_REG_VAL(24, 25, 26, 27)
   #define GPIO_MODE_REG8  GPIO_MODE_4BITS_REG_VAL(28, 29, 30, 31)
   #define GPIO_MODE_REG9  GPIO_MODE_4BITS_REG_VAL(32, 33, 34, 35)
   #define GPIO_MODE_REG10  GPIO_MODE_4BITS_REG_VAL(36, 37, 38, 39)
   #define GPIO_MODE_REG11  GPIO_MODE_4BITS_REG_VAL(40, 41, 42, 43)
   #define GPIO_MODE_REG12  GPIO_MODE_4BITS_REG_VAL(44, 45, 46, 47)
   #define GPIO_MODE_REG13  GPIO_MODE_4BITS_REG_VAL(48, 49, 50, 51)
   #define GPIO_MODE_REG14  GPIO_MODE_4BITS_REG_VAL(52, 53, 54, 55)
   #define GPIO_MODE_REG15  GPIO_MODE_4BITS_REG_VAL(56, 57, 58, 59)
   #define GPIO_MODE_REG16  GPIO_MODE_4BITS_REG_VAL(60, 61, 62, 63)
   #define GPIO_MODE_REG17  GPIO_MODE_4BITS_REG_VAL(64, 65, 66, 67)
   #define GPIO_MODE_REG18  GPIO_MODE_4BITS_REG_VAL(68, 69, 70, 71)
   #define GPIO_MODE_REG19  GPIO_MODE_4BITS_REG_VAL(72, 73, 74, 75)
   #define GPIO_MODE_REG20  GPIO_MODE_4BITS_REG_VAL(76, 77, 78, 79)
   #define GPIO_MODE_REG21  GPIO_MODE_4BITS_REG_VAL(80, 81, 82, 83)
   #define GPIO_MODE_REG22  GPIO_MODE_4BITS_REG_VAL(84, 85, 86, 87)
#define GPIO_MODE_REG23  GPIO_MODE_4BITS_REG_VAL(88, 89, 90, 91)
#define GPIO_MODE_REG24  GPIO_MODE_4BITS_REG_VAL(92, 93, 94, 95)
#define GPIO_MODE_REG25  GPIO_MODE_4BITS_REG_VAL(96, 97, 98, 99)
#define GPIO_MODE_REG26  GPIO_MODE_4BITS_REG_VAL(100, 101, 102,103)
#define GPIO_MODE_REG27  GPIO_MODE_4BITS_REG_VAL(104, NULL, NULL,NULL)

 #endif 
#if defined(DRV_GPIO_REG_AS_6256)
   #define GPIO_MODE_REG1  GPIO_MODE_4BITS_REG_VAL(0, 1, 2, 3)
   #define GPIO_MODE_REG2  GPIO_MODE_4BITS_REG_VAL(4, 5, 6, 7)
   #define GPIO_MODE_REG3  GPIO_MODE_4BITS_REG_VAL(8, 9, 10, 11)
   #define GPIO_MODE_REG4  GPIO_MODE_4BITS_REG_VAL(12, 13, 14, 15)
   #define GPIO_MODE_REG5  GPIO_MODE_4BITS_REG_VAL(16, 17, 18, 19)
   #define GPIO_MODE_REG6  GPIO_MODE_4BITS_REG_VAL(20, 21, 22, 23)
   #define GPIO_MODE_REG7  GPIO_MODE_4BITS_REG_VAL(24, 25, 26, 27)
   #define GPIO_MODE_REG8  GPIO_MODE_4BITS_REG_VAL(28, 29, 30, 31)
   #define GPIO_MODE_REG9  GPIO_MODE_4BITS_REG_VAL(32, 33, 34, 35)
   #define GPIO_MODE_REG10  GPIO_MODE_4BITS_REG_VAL(36, 37, 38, 39)
   #define GPIO_MODE_REG11  GPIO_MODE_4BITS_REG_VAL(40, 41, 42, 43)
   #define GPIO_MODE_REG12  GPIO_MODE_4BITS_REG_VAL(44, 45, 46, 47)
   #define GPIO_MODE_REG13  GPIO_MODE_4BITS_REG_VAL(48, 49, 50, 51)
   #define GPIO_MODE_REG14  GPIO_MODE_4BITS_REG_VAL(52, 53, 54, 55)
   #define GPIO_MODE_REG15  GPIO_MODE_4BITS_REG_VAL(56, 57, 58, 59)
   #define GPIO_MODE_REG16  GPIO_MODE_4BITS_REG_VAL(60, 61, 62, 63)
   #define GPIO_MODE_REG17  GPIO_MODE_4BITS_REG_VAL(64, 65, 66, 67)
   #define GPIO_MODE_REG18  GPIO_MODE_4BITS_REG_VAL(68, 69, 70, 71)
   #define GPIO_MODE_REG19  GPIO_MODE_4BITS_REG_VAL(72, 73, 74, 75)
   #define GPIO_MODE_REG20  GPIO_MODE_4BITS_REG_VAL(76, 77, 78, 79)
   #define GPIO_MODE_REG21  GPIO_MODE_4BITS_REG_VAL(80, 81, 82, 83)
   #define GPIO_MODE_REG22  GPIO_MODE_4BITS_REG_VAL(84, 85, 86, 87)
   #define GPIO_MODE_REG23  GPIO_MODE_4BITS_REG_VAL(88, 89, 90, 91)
   #define GPIO_MODE_REG24  GPIO_MODE_4BITS_REG_VAL(92, 93, 94, 95)
   #define GPIO_MODE_REG25  GPIO_MODE_4BITS_REG_VAL(96, 97, 98, 99)
   #define GPIO_MODE_REG26  GPIO_MODE_4BITS_REG_VAL(100, 101, 102, 103)
   #define GPIO_MODE_REG27  GPIO_MODE_4BITS_REG_VAL(104, NULL, NULL, NULL)
#endif      
#if defined(DRV_GPIO_REG_AS_6251)
   #define GPIO_MODE_REG1  GPIO_MODE_4BITS_REG_VAL(0, 1, 2, 3)
   #define GPIO_MODE_REG2  GPIO_MODE_4BITS_REG_VAL(4, 5, 6, 7)
   #define GPIO_MODE_REG3  GPIO_MODE_4BITS_REG_VAL(8, 9, 10, 11)
   #define GPIO_MODE_REG4  GPIO_MODE_4BITS_REG_VAL(12, 13, 14, 15)
   #define GPIO_MODE_REG5  GPIO_MODE_4BITS_REG_VAL(16, 17, 18, 19)
   #define GPIO_MODE_REG6  GPIO_MODE_4BITS_REG_VAL(20, 21, 22, 23)
   #define GPIO_MODE_REG7  GPIO_MODE_4BITS_REG_VAL(24, 25, 26, 27)
   #define GPIO_MODE_REG8  GPIO_MODE_4BITS_REG_VAL(28, 29, 30, 31)
#endif // defined(DRV_GPIO_REG_AS_6255)
#if defined(DRV_GPIO_REG_AS_6250)
  #define GPIO_MODE_REG1   GPIO_MODE_4BITS_REG_VAL(0, 1, 2, 3, 4, 5, 6, 7)
  #define GPIO_MODE_REG2  GPIO_MODE_4BITS_REG_VAL(8, 9, 10, 11, 12, 13, 14, 15)
  #define GPIO_MODE_REG3  GPIO_MODE_4BITS_REG_VAL(16, 17, 18, 19, 20, 21, 22, 23)
  #define GPIO_MODE_REG4  GPIO_MODE_4BITS_REG_VAL(24, 25, 26, 27, 28, 29, 30, 31)
  #define GPIO_MODE_REG5  GPIO_MODE_4BITS_REG_VAL(32, 33, 34, 35, 36, 37, 38, 39)
  #define GPIO_MODE_REG6  GPIO_MODE_4BITS_REG_VAL(40, 41, 42, 43, 44, 45, 46, 47)
  #define GPIO_MODE_REG7  GPIO_MODE_4BITS_REG_VAL(48, 49, 50, 51, 52, 53, 54, 55)
  #define GPIO_MODE_REG8  GPIO_MODE_4BITS_REG_VAL(56, 57, 58, 59, 60, 61, 62, 63)
  #define GPIO_MODE_REG9  GPIO_MODE_4BITS_REG_VAL(64, 65, 66, 67, 68, 69, 70, 71)
  #define GPIO_MODE_REG10  GPIO_MODE_4BITS_REG_VAL(72, NULL, 74, NULL, NULL, NULL, NULL,NULL)
  #define GPIO_MODE_REG11  GPIO_MODE_4BITS_REG_VAL(NULL, 81, 82, 83, 84, 85, 86, NULL)

#endif  //defined(DRV_GPIO_REG_AS_6250)


/***************************GPIO MODE IS NEITHER 4 BIT *********END**********/

/***************************GPIO MODE IS 3 BIT******************START********/
#elif defined(DRV_GPIO_MODE_3BITS)
#if defined(DRV_GPIO_REG_AS_6276)
    #define GPIO_MODE_REG0	GPIO_MODE_3BITS_REG_VAL(0, 1, 2, 3, 4)
    #define GPIO_MODE_REG1	GPIO_MODE_3BITS_REG_VAL(5, 6, 7, 8, 9)
    #define GPIO_MODE_REG2	GPIO_MODE_3BITS_REG_VAL(10, 11, 12, 13, 14)
    #define GPIO_MODE_REG3	GPIO_MODE_3BITS_REG_VAL(15, 16, 17, 18, 19)
    #define GPIO_MODE_REG4	GPIO_MODE_3BITS_REG_VAL(20, 21, 22, 23, 24)
    #define GPIO_MODE_REG5	GPIO_MODE_3BITS_REG_VAL(25, 26, 27, 28, 29)	
    #define GPIO_MODE_REG6	GPIO_MODE_3BITS_REG_VAL(30, 31, 32, 33, 34)
    #define GPIO_MODE_REG7	GPIO_MODE_3BITS_REG_VAL(35, 36, 37, 38, 39)
    #define GPIO_MODE_REG8	GPIO_MODE_3BITS_REG_VAL(40, 41, 42, 43, 44)	
    #define GPIO_MODE_REG9	GPIO_MODE_3BITS_REG_VAL(45, 46, 47, 48, 49)
    #define GPIO_MODE_REGA	GPIO_MODE_3BITS_REG_VAL(50, 51, 52, 53, 54)
    #define GPIO_MODE_REGB	GPIO_MODE_3BITS_REG_VAL(55, 56, 57, 58, 59)
    #define GPIO_MODE_REGC	GPIO_MODE_3BITS_REG_VAL(60, 61, 62, 63, 64)
    #define GPIO_MODE_REGD	GPIO_MODE_3BITS_REG_VAL(65, 66, 67, 68, 69)
    #define GPIO_MODE_REGE	GPIO_MODE_3BITS_REG_VAL(70, 71, 72, 73, 74)
    #define GPIO_MODE_REGF	GPIO_MODE_3BITS_REG_VAL(75, 76, 77, 78, 79)
    #define GPIO_MODE_REG10	GPIO_MODE_3BITS_REG_VAL(80, 81, 82, 83, 84)
    #define GPIO_MODE_REG11	GPIO_MODE_3BITS_REG_VAL(85, 86, 87, 88, 89)
    #define GPIO_MODE_REG12	GPIO_MODE_3BITS_REG_VAL(90, 91, 92, 93, 94)	
    #define GPIO_MODE_REG13	GPIO_MODE_3BITS_REG_VAL(95, 96, 97, 98, 99)
    #define GPIO_MODE_REG14	GPIO_MODE_3BITS_REG_VAL(100, 101, 102, 103, 104)
    #define GPIO_MODE_REG15	GPIO_MODE_3BITS_REG_VAL(105, 106, 107, 108, 109)
#endif //defined(DRV_GPIO_REG_AS_6276)

#endif //!defined(DRV_GPIO_MODE_4BITS) && !defined(DRV_GPIO_MODE_3BITS)

/****************************************************************************************/
/*********************************__CHIP_SUPP_GPIO_DRV_TOOL__****************************/
/*********************************************END****************************************/
/****************************************************************************************/




/*********************************************************************************************/
/*********************************************************************************************/
 /* Macros to calulate GPIO related register value of different platforms with 1 bit unit 
   for different settings, like dirction control pull-up/pull-down enable, inversion control. */
/*****************************************START***********************************************/
/*********************************************************************************************/


#if defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_HWORD_REG1(name)  GPIO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#else /* DRV_GPIO_REG_AS_TK6516 */
   #define GPIO_HWORD_REG1(name)  GPIO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
   #if defined(DRV_GPIO_REG_AS_6205B)
      #define GPO_HWORD_REG1(name)  GPO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #define GPIO_HWORD_REG2(name)  GPIO_HWORD_REG_FOR_1BIT(name, 16, 17, 18, 19, 20, 21, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6270A)
      #define GPIO_HWORD_REG2(name)  GPIO_HWORD_REG_FOR_1BIT(name, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6251)
      #define GPIO_HWORD_REG2(name)  GPIO_HWORD_REG_FOR_1BIT(name, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
      #define GPIO_HWORD_REG3(name)  GPIO_HWORD_REG_FOR_1BIT(name, 32, 33, 34, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #define GPIO_HWORD_REG3_TO_38(name)  GPIO_HWORD_REG_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #else /* DRV_GPIO_REG_AS_6270A) */
      #define GPIO_HWORD_REG2(name)  GPIO_HWORD_REG_FOR_1BIT(name, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
      #define GPIO_HWORD_REG3(name)  GPIO_HWORD_REG_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47)
      #if defined(DRV_GPIO_REG_AS_6218B)
         #define GPO_HWORD_REG1(name)  GPO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6225)  
         #if defined(DRV_GPIO_REG_AS_6219)
            #define GPO_HWORD_REG1(name)  GPO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, 4, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
         #elif defined(DRV_GPIO_REG_AS_6225)
            #define GPO_HWORD_REG1(name)  GPO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
         #endif
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6227)
         #define GPO_HWORD_REG1(name)  GPO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, 4, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6228)
         #define GPO_HWORD_REG1(name)  GPO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6223)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6238)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79)
         #define GPIO_HWORD_REG6(name)  GPIO_HWORD_REG_FOR_1BIT(name, 80, 81, 82, 83, 84, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6235)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6236)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79)
         #define GPIO_HWORD_REG6(name)  GPIO_HWORD_REG_FOR_1BIT(name, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95)
         #if defined(DRV_GPIO_REG_AS_6268A)
         #define GPIO_HWORD_REG7(name)  GPIO_HWORD_REG_FOR_1BIT(name, 96, 97, 98, 99, 100, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
         #elif defined(DRV_GPIO_REG_AS_6268)
         #define GPIO_HWORD_REG7(name)  GPIO_HWORD_REG_FOR_1BIT(name, 96, 97, 98, 99, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
         #elif defined(DRV_GPIO_REG_AS_6276)
         #define GPIO_HWORD_REG7(name)  GPIO_HWORD_REG_FOR_1BIT(name, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, NULL, NULL, NULL)
         #endif
      #elif defined(DRV_GPIO_REG_AS_6253T)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79)
         #define GPIO_HWORD_REG6(name)  GPIO_HWORD_REG_FOR_1BIT(name, 80, 81, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6255)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79)
         #define GPIO_HWORD_REG6(name)  GPIO_HWORD_REG_FOR_1BIT(name, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95)
         #define GPIO_HWORD_REG7(name)  GPIO_HWORD_REG_FOR_1BIT(name, 96, 97, 98, 99, 100, 101, 102, 103, 104, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#elif defined(DRV_GPIO_REG_AS_6253E)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
     #elif defined(DRV_GPIO_REG_AS_6253E_1) 
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)     
     #elif defined(DRV_GPIO_REG_AS_6256)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79)
         #define GPIO_HWORD_REG6(name)  GPIO_HWORD_REG_FOR_1BIT(name, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95)
         #define GPIO_HWORD_REG7(name)  GPIO_HWORD_REG_FOR_1BIT(name, 96, 97, 98, 99, 100, 101, 102, 103, 104, NULL, NULL, NULL, NULL, NULL, NULL, NULL)    
     #elif defined(DRV_GPIO_REG_AS_6250)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72,  NULL, 74,  NULL, NULL,  NULL, NULL,  NULL)
         #define GPIO_HWORD_REG6(name)  GPIO_HWORD_REG_FOR_1BIT(name,  NULL, 81, 82, 83, 84, 85, 86, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
 #endif      
   #endif /* DRV_GPIO_REG_AS_6205B */
#endif /* DRV_GPIO_REG_AS_TK6516 */

#if defined(DRV_GPIO_6250_SPECIAL_SET_REG)

/*****************************************PULLSEL , PULLEN   REGISTER******************************************************************/

	#define  GPIO_PULLSEL_EN_HWORD_REG1(name)    GPIO_HWORD_SPEC_REG_FOR_1BIT(name, 73, 75, 76, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL) // PULLSEL,PULLEN    mapping is  same
    #define  GPIO_PULLSEL_EN_HWORD_REG2(name)    GPIO_HWORD_SPEC_REG_FOR_1BIT(name, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 70, 68, 67, 71,72)
	#define  GPIO_PULLSEL_EN_HWORD_REG3(name)    GPIO_HWORD_SPEC_REG_FOR_1BIT(name, 69, 30, 32, 31, NULL, NULL, NULL, NULL, NULL, NULL, 74, 83, 82, 86, 81, 85)
	#define  GPIO_PULLSEL_EN_HWORD_REG4(name)    GPIO_HWORD_SPEC_REG_FOR_1BIT(name, 84, 0, 19, 10, 20, 15, 14, 66, 6, 18, 21, 8, 7, 4, 12, 13)
	#define  GPIO_PULLSEL_EN_HWORD_REG5(name)    GPIO_HWORD_SPEC_REG_FOR_1BIT(name, 5, 3, 16, 11, 17, 22, 45, 2, 9, 29, 42, 46, 1, 37, 44, 36)
	#define  GPIO_PULLSEL_EN_HWORD_REG6(name)    GPIO_HWORD_SPEC_REG_FOR_1BIT(name, 35, 34, 33, 27, 48, 38, 43, 28, 50, 51, 47,40, 49, 41, 39, 54)
	#define  GPIO_PULLSEL_EN_HWORD_REG7(name)    GPIO_HWORD_SPEC_REG_FOR_1BIT(name, 55, 57, 62, 61, 64, 53, 63, 56, 58, 65, 59, 60, 52, 23, 24, 25)
	#define  GPIO_PULLSEL_EN_HWORD_REG8(name)    GPIO_HWORD_SPEC_REG_FOR_1BIT(name, 26, NULL, NULL, NULL, NULL, NULL, NULL, 77, 79, 78, 80,  NULL, NULL, NULL, NULL, NULL)
/****************************************PUPD   Register***********************************************************************/

	 #define  GPIO_PUPD_HWORD_REG1(name)        GPIO_HWORD_SPEC_REG_FOR_1BIT(name, 70, 68, 67, 71, 72, 69, 30, 32,31, 10, 15, 14, 6, 18, 8, 7)
	 #define  GPIO_PUPD_HWORD_REG2(name)        GPIO_HWORD_SPEC_REG_FOR_1BIT(name, 4, 3, 16, 11, 17, 9, 25, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
 /****************************************R0,R1  Rgister*********************************************************************/
     #define  GPIO_RESEN_HWORD_REG1(name)      GPIO_HWORD_SPEC_REG_FOR_1BIT(name, 70, 68, 67, 71, 72, 69, 30, 32,31, 10, 15, 14, 6, 18, 8, 7)  // R0
	 #define  GPIO_RESEN_HWORD_REG2            GPIO_HWORD_R0_R1_FOR_1BIT(4, 3, 16, 11, 17, 9, 25, 70, 68, 67, 71, 72, 69, 30, 32, 31)      //R0, R1 included
	 #define  GPIO_RESEN_HWORD_REG3(name)      GPIO_HWORD_SPEC_REG_FOR_1BIT(name, 10, 15, 14, 6, 18, 8, 7, 4, 3, 16, 17, 9, NULL, NULL, NULL, NULL)   //R1
/******************************************A-DIE  GPIO register********************************************************************/
    #define ADIE_GPIO_OE_DOUT_HWORD_REG  GPIO_HWORD_ADIE_OE_DOUT_FOR_1BIT(105, 106, 107,  NULL, NULL, NULL, NULL, NULL, 105, 106, 107, NULL, NULL, NULL, NULL, NULL)  
	#define ADIE_GPIO_MODE_HWORD_REG     GPIO_MODE_ADIE_4BITS_REG_VAL(NULL,105,106,107)
#endif   //defined(DRV_GPIO_6250_SPECIAL_SET_REG)

/*********************************************************************************************/
/*********************************************************************************************/
 /* Macros to calulate GPIO related register value of different platforms with 1 bit unit 
   for different settings, like dirction control pull-up/pull-down enable, inversion control. */
/*****************************************END***********************************************/
/*********************************************************************************************/

/*********************************************************************************************/
/*********************************************************************************************/ 
/****************** GPIO direction control register value*************************************/
/*************************************START************************************************/ 
/*********************************************************************************************/ 

   #define GPIO_DIR_REG1   GPIO_HWORD_REG1(DIR)
#if !defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_DIR_REG2   GPIO_HWORD_REG2(DIR)
#if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_6270A)
   #define GPIO_DIR_REG3   GPIO_HWORD_REG3(DIR)
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6253E)
      #define GPIO_DIR_REG4   GPIO_HWORD_REG4(DIR)
   #endif
   #if defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_DIR_REG5   GPIO_HWORD_REG5(DIR)
   #endif
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1)
      #define GPIO_DIR_REG4   GPIO_HWORD_REG4(DIR)
      #define GPIO_DIR_REG5   GPIO_HWORD_REG5(DIR)
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) 
         #define GPIO_DIR_REG6   GPIO_HWORD_REG6(DIR)
      #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
         #define GPIO_DIR_REG6   GPIO_HWORD_REG6(DIR)
         #define GPIO_DIR_REG7   GPIO_HWORD_REG7(DIR)
      #endif
  #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255) 
      #define GPIO_DIR_REG4   GPIO_HWORD_REG4(DIR)
      #define GPIO_DIR_REG5   GPIO_HWORD_REG5(DIR)
      #define GPIO_DIR_REG6   GPIO_HWORD_REG6(DIR)
      #define GPIO_DIR_REG7   GPIO_HWORD_REG7(DIR)
  #elif defined(DRV_GPIO_REG_AS_6250)
      #define GPIO_DIR_REG4   GPIO_HWORD_REG4(DIR)
      #define GPIO_DIR_REG5   GPIO_HWORD_REG5(DIR)
      #define GPIO_DIR_REG6   GPIO_HWORD_REG6(DIR)

   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_6270A) */
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */

/*********************************************************************************************/
/*********************************************************************************************/ 
/****************** GPIO direction control register value*************************************/
/*************************************END*****************************************************/ 
/*********************************************************************************************/ 


/*********************************************************************************************/
/*********************************************************************************************/ 
/****************** GPIO Pull-up/Pull-down enable register value******************************/
/*************************************START***************************************************/ 
/*********************************************************************************************/ 
 #if !defined (DRV_GPIO_6250_SPECIAL_SET_REG)

   /* GPIO Pull-up/Pull-down enable register value. */
   #define GPIO_PULL_REG1   GPIO_HWORD_REG1(PULL)
#if !defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_PULL_REG2   GPIO_HWORD_REG2(PULL)
#if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_6270A)
   #if defined(DRV_GPIO_REG_AS_6251)
      #define GPIO_PULL_REG3   GPIO_HWORD_REG3_TO_38(PULL)
   #else
      #define GPIO_PULL_REG3   GPIO_HWORD_REG3(PULL)
   #endif
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223)|| defined(DRV_GPIO_REG_AS_6253E)
      #define GPIO_PULL_REG4   GPIO_HWORD_REG4(PULL)
   #endif
   #if defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_PULL_REG5   GPIO_HWORD_REG5(PULL)
   #endif
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1)
      #define GPIO_PULL_REG4   GPIO_HWORD_REG4(PULL)
      #define GPIO_PULL_REG5   GPIO_HWORD_REG5(PULL)
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) 
         #define GPIO_PULL_REG6   GPIO_HWORD_REG6(PULL)
      #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
         #define GPIO_PULL_REG6   GPIO_HWORD_REG6(PULL)
         #define GPIO_PULL_REG7   GPIO_HWORD_REG7(PULL)
      #endif
  #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255) 
      #define GPIO_PULL_REG4   GPIO_HWORD_REG4(PULL)
      #define GPIO_PULL_REG5   GPIO_HWORD_REG5(PULL)   
      #define GPIO_PULL_REG6   GPIO_HWORD_REG6(PULL)
      #define GPIO_PULL_REG7   GPIO_HWORD_REG7(PULL)
   #endif
#endif /* #if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_6270A) */
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */

#else //!defined (DRV_GPIO_SPECIAL_SET_REG)
        #define GPIO_PULL_REG1_E1   GPIO_PULLSEL_EN_HWORD_REG1(PULL)
	#define GPIO_PULL_REG2_E1   GPIO_PULLSEL_EN_HWORD_REG2(PULL)
	#define GPIO_PULL_REG3_E1   GPIO_PULLSEL_EN_HWORD_REG3(PULL)
	#define GPIO_PULL_REG4_E1   GPIO_PULLSEL_EN_HWORD_REG4(PULL)
	#define GPIO_PULL_REG5_E1   GPIO_PULLSEL_EN_HWORD_REG5(PULL)
	#define GPIO_PULL_REG6_E1   GPIO_PULLSEL_EN_HWORD_REG6(PULL)
	#define GPIO_PULL_REG7_E1   GPIO_PULLSEL_EN_HWORD_REG7(PULL)
	#define GPIO_PULL_REG8_E1   GPIO_PULLSEL_EN_HWORD_REG8(PULL)

	#define GPIO_PULL_REG1_E2   GPIO_HWORD_REG1(PULL)
	#define GPIO_PULL_REG2_E2   GPIO_HWORD_REG2(PULL)
	#define GPIO_PULL_REG3_E2   GPIO_HWORD_REG3(PULL)
	#define GPIO_PULL_REG4_E2   GPIO_HWORD_REG4(PULL)
        #define GPIO_PULL_REG5_E2   GPIO_HWORD_REG5(PULL)   
        #define GPIO_PULL_REG6_E2   GPIO_HWORD_REG6(PULL)		  


#endif

/*********************************************************************************************/
/*********************************************************************************************/ 
/****************** GPIO Pull-up/Pull-down enable register value******************************/
/*************************************END*****************************************************/ 
/*********************************************************************************************/ 

/*********************************************************************************************/
/*********************************************************************************************/ 
/******************GPIO inversion control register value**************************************/
/************************************START*****************************************************/ 
/*********************************************************************************************/ 

   /* GPIO inversion control register value. */
#if !defined(DRV_GPIO_REG_AS_6205B)
   #define GPIO_INV_REG1   GPIO_HWORD_REG1(INV)
#if !defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_INV_REG2   GPIO_HWORD_REG2(INV)
#if !defined(DRV_GPIO_REG_AS_6270A) && !defined(DRV_GPIO_REG_AS_6251)
   #define GPIO_INV_REG3   GPIO_HWORD_REG3(INV)
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6253E)
      #define GPIO_INV_REG4   GPIO_HWORD_REG4(INV)
   #endif
   #if defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_INV_REG5   GPIO_HWORD_REG5(INV)
   #endif
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T)  || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1)
      #define GPIO_INV_REG4   GPIO_HWORD_REG4(INV)
      #define GPIO_INV_REG5   GPIO_HWORD_REG5(INV)
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T)
         #define GPIO_INV_REG6   GPIO_HWORD_REG6(INV)
      #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
         #define GPIO_INV_REG6   GPIO_HWORD_REG6(INV)
         #define GPIO_INV_REG7   GPIO_HWORD_REG7(INV)
      #endif
   #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255)  
      #define GPIO_INV_REG4   GPIO_HWORD_REG4(INV)
      #define GPIO_INV_REG5   GPIO_HWORD_REG5(INV)
      #define GPIO_INV_REG6   GPIO_HWORD_REG6(INV)
      #define GPIO_INV_REG7   GPIO_HWORD_REG7(INV)
    #elif defined(DRV_GPIO_REG_AS_6250) 
      #define GPIO_INV_REG4   GPIO_HWORD_REG4(INV)
      #define GPIO_INV_REG5   GPIO_HWORD_REG5(INV)
      #define GPIO_INV_REG6   GPIO_HWORD_REG6(INV)
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6270A) */
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */


/*********************************************************************************************/
/*********************************************************************************************/ 
/******************GPIO inversion control register value**************************************/
/************************************END******************************************************/ 
/*********************************************************************************************/ 

/*********************************************************************************************/
/*********************************************************************************************/ 
/*****************************GPIO Output register value**************************************/
/************************************START*****************************************************/ 
/*********************************************************************************************/ 

   #define GPIO_OUTPUT_REG1   GPIO_HWORD_REG1(OUTPUT_LEVEL)
#if !defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_OUTPUT_REG2   GPIO_HWORD_REG2(OUTPUT_LEVEL)
#if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_6270A)
   #define GPIO_OUTPUT_REG3   GPIO_HWORD_REG3(OUTPUT_LEVEL)
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6253E)
      #define GPIO_OUTPUT_REG4   GPIO_HWORD_REG4(OUTPUT_LEVEL)
   #endif
   #if defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_OUTPUT_REG5   GPIO_HWORD_REG5(OUTPUT_LEVEL)
   #endif
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T)  || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1)
      #define GPIO_OUTPUT_REG4   GPIO_HWORD_REG4(OUTPUT_LEVEL)
      #define GPIO_OUTPUT_REG5   GPIO_HWORD_REG5(OUTPUT_LEVEL)
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255)
         #define GPIO_OUTPUT_REG6   GPIO_HWORD_REG6(OUTPUT_LEVEL)
      #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
         #define GPIO_OUTPUT_REG6   GPIO_HWORD_REG6(OUTPUT_LEVEL)
         #define GPIO_OUTPUT_REG7   GPIO_HWORD_REG7(OUTPUT_LEVEL)
      #endif
   #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255)
      #define GPIO_OUTPUT_REG4   GPIO_HWORD_REG4(OUTPUT_LEVEL)
      #define GPIO_OUTPUT_REG5   GPIO_HWORD_REG5(OUTPUT_LEVEL)
      #define GPIO_OUTPUT_REG6   GPIO_HWORD_REG6(OUTPUT_LEVEL)
      #define GPIO_OUTPUT_REG7   GPIO_HWORD_REG7(OUTPUT_LEVEL)
  #elif defined(DRV_GPIO_REG_AS_6250) 
      #define GPIO_OUTPUT_REG4   GPIO_HWORD_REG4(OUTPUT_LEVEL)
      #define GPIO_OUTPUT_REG5   GPIO_HWORD_REG5(OUTPUT_LEVEL)
      #define GPIO_OUTPUT_REG6   GPIO_HWORD_REG6(OUTPUT_LEVEL)
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_6270A) */
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */


/*********************************************************************************************/
/*********************************************************************************************/ 
/*****************************GPIO Output register value**************************************/
/************************************END*****************************************************/ 
/*********************************************************************************************/ 

/*********************************************************************************************/
/*********************************************************************************************/ 
/*****************************GPO Output register value**************************************/
/************************************START*****************************************************/ 
/*********************************************************************************************/ 

#if (!defined(DRV_GPIO_WO_GPO))
   #define GPO_OUTPUT_REG1   GPO_HWORD_REG1(OUTPUT_LEVEL)
#endif

/*********************************************************************************************/
/*********************************************************************************************/ 
/*****************************GPO Output register value**************************************/
/************************************END*****************************************************/ 
/*********************************************************************************************/ 
  

/*********************************************************************************************/
/*********************************************************************************************/ 
/****************************GPIO PULL up/down selection register value***********************/
/************************************START*****************************************************/ 
/*********************************************************************************************/ 

#if !defined (DRV_GPIO_6250_SPECIAL_SET_REG)

#if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_TK6516) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6270A) || defined(DRV_GPIO_REG_AS_6253E)  || defined(DRV_GPIO_REG_AS_6276)|| defined(DRV_GPIO_REG_AS_6251) || defined(DRV_GPIO_REG_AS_6253E_1)|| defined(DRV_GPIO_REG_AS_6250)
   #define GPIO_PULLSEL_REG1   GPIO_HWORD_REG1(PULL_SEL)
#if !defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_PULLSEL_REG2   GPIO_HWORD_REG2(PULL_SEL)
#if defined(DRV_GPIO_REG_AS_6251)
   #define GPIO_PULLSEL_REG3   GPIO_HWORD_REG3_TO_38(PULL_SEL)
#elif !defined(DRV_GPIO_REG_AS_6270A)
   #define GPIO_PULLSEL_REG3   GPIO_HWORD_REG3(PULL_SEL)
   #define GPIO_PULLSEL_REG4   GPIO_HWORD_REG4(PULL_SEL)
#if !defined(DRV_GPIO_REG_AS_6253E)
   #define GPIO_PULLSEL_REG5   GPIO_HWORD_REG5(PULL_SEL)
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) 
      #define GPIO_PULLSEL_REG6   GPIO_HWORD_REG6(PULL_SEL)
   #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
      #define GPIO_PULLSEL_REG6   GPIO_HWORD_REG6(PULL_SEL)
      #define GPIO_PULLSEL_REG7   GPIO_HWORD_REG7(PULL_SEL)
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6253E) */
#endif /* !defined(DRV_GPIO_REG_AS_6270A) */
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */
#elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255) 
	#define GPIO_PULLSEL_REG1   GPIO_HWORD_REG1(PULL_SEL)
	#define GPIO_PULLSEL_REG2   GPIO_HWORD_REG2(PULL_SEL)
	#define GPIO_PULLSEL_REG3   GPIO_HWORD_REG3(PULL_SEL)
	#define GPIO_PULLSEL_REG4   GPIO_HWORD_REG4(PULL_SEL)
	#define GPIO_PULLSEL_REG5   GPIO_HWORD_REG5(PULL_SEL)
	#define GPIO_PULLSEL_REG6   GPIO_HWORD_REG6(PULL_SEL)
	#define GPIO_PULLSEL_REG7   GPIO_HWORD_REG7(PULL_SEL)
#endif /* defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) */

#else //!defined (DRV_GPIO_SPECIAL_SET_REG)

       
        #define GPIO_PULLSEL_REG1_E1   GPIO_PULLSEL_EN_HWORD_REG1(PULL_SEL)
	#define GPIO_PULLSEL_REG2_E1   GPIO_PULLSEL_EN_HWORD_REG2(PULL_SEL)
	#define GPIO_PULLSEL_REG3_E1   GPIO_PULLSEL_EN_HWORD_REG3(PULL_SEL)
	#define GPIO_PULLSEL_REG4_E1   GPIO_PULLSEL_EN_HWORD_REG4(PULL_SEL)
	#define GPIO_PULLSEL_REG5_E1   GPIO_PULLSEL_EN_HWORD_REG5(PULL_SEL)
	#define GPIO_PULLSEL_REG6_E1   GPIO_PULLSEL_EN_HWORD_REG6(PULL_SEL)
	#define GPIO_PULLSEL_REG7_E1   GPIO_PULLSEL_EN_HWORD_REG7(PULL_SEL)
	#define GPIO_PULLSEL_REG8_E1   GPIO_PULLSEL_EN_HWORD_REG8(PULL_SEL)

	#define GPIO_PULLSEL_REG1_E2   GPIO_HWORD_REG1(PULL_SEL)
	#define GPIO_PULLSEL_REG2_E2   GPIO_HWORD_REG2(PULL_SEL)
	#define GPIO_PULLSEL_REG3_E2   GPIO_HWORD_REG3(PULL_SEL)
	#define GPIO_PULLSEL_REG4_E2   GPIO_HWORD_REG4(PULL_SEL)
	#define GPIO_PULLSEL_REG5_E2   GPIO_HWORD_REG5(PULL_SEL)
	#define GPIO_PULLSEL_REG6_E2   GPIO_HWORD_REG6(PULL_SEL)
		
	
#endif



/*********************************************************************************************/
/*********************************************************************************************/ 
/****************************GPIO PULL up/down selection register value***********************/
/************************************END*****************************************************/ 
/*********************************************************************************************/ 

/*********************************************************************************************/
/*********************************************************************************************/ 
/****************************GPIO PUPD  R0,R1  Register  value****************************************/
/************************************START*****************************************************/ 
/*********************************************************************************************/ 
#if defined (DRV_GPIO_6250_SPECIAL_SET_REG)
   #define  GPIO_PUPD_REG1       GPIO_PUPD_HWORD_REG1(PUPD)
   #define  GPIO_PUPD_REG2       GPIO_PUPD_HWORD_REG2(PUPD)
   #define  GPIO_RESEN_REG1      GPIO_RESEN_HWORD_REG1(R0)
   #define  GPIO_RESEN_REG2       GPIO_RESEN_HWORD_REG2
   #define  GPIO_RESEN_REG3        GPIO_RESEN_HWORD_REG3(R1)
   #define  ADIE_GPIO_OE_DOUT_REG   ADIE_GPIO_OE_DOUT_HWORD_REG
   #define  ADIE_GPIO_MODE_REG      ADIE_GPIO_MODE_HWORD_REG
  #endif //defined (DRV_GPIO_6250_SPECIAL_SET_REG)
   

#if defined(DRV_GPIO_REG_AS_6253E)
   #define GPIO_SPMODE_REG ((SP_MODE_BIT0) | (SP_MODE_BIT2<<2) | (SP_MODE_BIT4<<4) | (SP_MODE_BIT6<<6) | (SP_MODE_BIT8<<8))
   #define GPIO_BANK_REG ((BANK0) | (BANK1<<1) | (BANK2<<2) | (BANK3<<3) | (BANK4<<4) | (BANK5<<5) | (BANK6<<6) | (BANK7<<7))
#endif //defined(DRV_GPIO_REG_AS_6253E)

//this need to confirm after WS.chen work done!!!!
#if defined(DRV_GPIO_REG_AS_6253E_1)
   #define GPIO_SPMODE0_REG ((SP_MODE0_BIT0) | (SP_MODE0_BIT2<<2) | (SP_MODE0_BIT4<<4) | (SP_MODE0_BIT6<<6) | (SP_MODE0_BIT8<<8) |\
   	   (SP_MODE0_BIT10<<10) | (SP_MODE0_BIT12<<12) | (SP_MODE0_BIT14<<14) | (SP_MODE0_BIT16<<16) | (SP_MODE0_BIT18<<18) |\
   	   (SP_MODE0_BIT20<<20) | (SP_MODE0_BIT22<<22) | (SP_MODE0_BIT24<<24) | (SP_MODE0_BIT26<<26) | (SP_MODE0_BIT28<<28) |\
   	   (SP_MODE0_BIT30<<30))

   #define GPIO_SPMODE1_REG ((SP_MODE1_BIT0) | (SP_MODE1_BIT2<<2) | (SP_MODE1_BIT4<<4) | (SP_MODE1_BIT8<<8) | (SP_MODE1_BIT12<<12) |\
   	   (SP_MODE1_BIT14<<14))
  // #define GPIO_BANK_REG ((BANK0) | (BANK1<<1) | (BANK2<<2) | (BANK3<<3) | (BANK4<<4) | (BANK5<<5) | (BANK6<<6) | (BANK7<<7))
#endif //defined(DRV_GPIO_REG_AS_6253E_1)





/*********************************************************************************************/
/*********************************************************************************************/ 
/**************************** General macros to calulate GPIO word-length variable************/
/**************************value with 1 bit unit for different platform***********************/
/************************************START*****************************************************/ 
/*********************************************************************************************/ 

#if defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_WORD_VAR0(name)  GPIO_WORD_VAR_FOR_1BIT(name, 0, 1, 2, 3, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                    NULL, NULL, NULL, NULL)		
#elif defined(DRV_GPIO_REG_AS_6205B)
   #define GPIO_WORD_VAR0(name)  GPIO_WORD_VAR_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                    20, 21, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)		
#elif defined(DRV_GPIO_REG_AS_6270A)
   #define GPIO_WORD_VAR0(name)  GPIO_WORD_VAR_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                    20, 21, 22, 23, 24, 25, 26, 27, NULL, NULL, NULL, NULL)		
#elif defined(DRV_GPIO_REG_AS_6251)
   #define GPIO_WORD_VAR0(name)  GPIO_WORD_VAR_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                    20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)		
   #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                       NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#else /* defined(DRV_GPIO_REG_AS_6270A) */
   #define GPIO_WORD_VAR0(name)  GPIO_WORD_VAR_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                    20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)		
   #if defined(DRV_GPIO_REG_AS_6218B)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, NULL, \
                                                       NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6225)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                       49, 50, 51, 52, 53, 54, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6227)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                       49, 50, 51, 52, 53, 54, 55, 56, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6223)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                       49, 50, 51, 52, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6238)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, \
                                                  79, 80, 81, 82, 83, 84, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6235)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6236)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, \
                                                  79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95)
      #if defined(DRV_GPIO_REG_AS_6268A)
      #define GPIO_WORD_VAR3(name)  GPIO_WORD_VAR_FOR_1BIT(name, 96, 97, 98, 99, 100, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6268)
      #define GPIO_WORD_VAR3(name)  GPIO_WORD_VAR_FOR_1BIT(name, 96, 97, 98, 99, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6276)
      #define GPIO_WORD_VAR3(name)  GPIO_WORD_VAR_FOR_1BIT(name, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL)
      #endif
   #elif defined(DRV_GPIO_REG_AS_6253T)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, \
                                                  79, 80, 81, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6255)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, \
                                                  79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95)
      #define GPIO_WORD_VAR3(name)  GPIO_WORD_VAR_FOR_1BIT(name, 96, 97, 98, 99, 100, 101, 102, 103, 104, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6253E)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63) 
   #elif defined(DRV_GPIO_REG_AS_6253E_1)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)                                            
#elif defined(DRV_GPIO_REG_AS_6256) 
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, \
                                                  79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95)
      #define GPIO_WORD_VAR3(name)  GPIO_WORD_VAR_FOR_1BIT(name, 96, 97, 98, 99, 100, 101, 102, 103, 104, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL)
 #elif defined(DRV_GPIO_REG_AS_6250)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, NULL, 74, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, 81, 82, 83, 84, 85, 86, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)                                                 
#endif

#endif /* !defined(DRV_GPIO_REG_AS_6205B) */


/*********************************************************************************************/
/*********************************************************************************************/ 
/**************************** General macros to calulate GPIO word-length variable************/
/**************************value with 1 bit unit for different platform***********************/
/************************************END*****************************************************/ 
/*********************************************************************************************/ 


  


/*********************************************************************************************/
/*********************************************************************************************/ 
/**************************** For each GPIO mode, specify if each GPIO pin is allowed to ******/
/****************set to this mode with '1' allowed, '0' on the corresponding bit position******/
/**********  Bit 0 means GPIO0, Bit 1 means GPIO1... etc ****************************************/ 
/**************************************START****************************************************/ 
/************************************************************************************************/ 

   #define GPIO_MODE0_VAR0  GPIO_WORD_VAR0(MODE0)
   #define GPIO_MODE1_VAR0  GPIO_WORD_VAR0(MODE1)
   #define GPIO_MODE2_VAR0  GPIO_WORD_VAR0(MODE2)
   #define GPIO_MODE3_VAR0  GPIO_WORD_VAR0(MODE3)
   #if defined(DRV_GPIO_MODE_3BITS)
   #define GPIO_MODE4_VAR0  GPIO_WORD_VAR0(MODE4)
   #elif defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_MODE4_VAR0  GPIO_WORD_VAR0(MODE4)
   #define GPIO_MODE5_VAR0  GPIO_WORD_VAR0(MODE5)
   #define GPIO_MODE6_VAR0  GPIO_WORD_VAR0(MODE6)
   #define GPIO_MODE7_VAR0  GPIO_WORD_VAR0(MODE7)
   #endif //defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_DIROUT_VAR0  GPIO_WORD_VAR0(DIR_OUT)
   #define GPIO_DIRIN_VAR0  GPIO_WORD_VAR0(DIR_IN)
   
   #if defined(DRV_GPIO_REG_AS_6251)
   #define GPIO_DIROUT_VAR1  GPIO_WORD_VAR1(DIR_OUT)
   #define GPIO_DIRIN_VAR1  GPIO_WORD_VAR1(DIR_IN)
   #elif !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A)
   #define GPIO_MODE0_VAR1  GPIO_WORD_VAR1(MODE0)
   #define GPIO_MODE1_VAR1  GPIO_WORD_VAR1(MODE1)
   #define GPIO_MODE2_VAR1  GPIO_WORD_VAR1(MODE2)
   #define GPIO_MODE3_VAR1  GPIO_WORD_VAR1(MODE3)
   #if defined(DRV_GPIO_MODE_3BITS)
   #define GPIO_MODE4_VAR1  GPIO_WORD_VAR1(MODE4)
   #elif defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_MODE4_VAR1  GPIO_WORD_VAR1(MODE4)
   #define GPIO_MODE5_VAR1  GPIO_WORD_VAR1(MODE5)
   #define GPIO_MODE6_VAR1  GPIO_WORD_VAR1(MODE6)
   #define GPIO_MODE7_VAR1  GPIO_WORD_VAR1(MODE7)
   #endif //defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_DIROUT_VAR1  GPIO_WORD_VAR1(DIR_OUT)
   #define GPIO_DIRIN_VAR1  GPIO_WORD_VAR1(DIR_IN)
   
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1) || defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6250)
   #define GPIO_MODE0_VAR2     GPIO_WORD_VAR2(MODE0)
   #define GPIO_MODE1_VAR2     GPIO_WORD_VAR2(MODE1)
   #define GPIO_MODE2_VAR2     GPIO_WORD_VAR2(MODE2)
   #define GPIO_MODE3_VAR2     GPIO_WORD_VAR2(MODE3)
   #if defined(DRV_GPIO_MODE_3BITS)
   #define GPIO_MODE4_VAR2  GPIO_WORD_VAR2(MODE4)
   #elif defined(DRV_GPIO_MODE_4BITS) 
   #define GPIO_MODE4_VAR2  GPIO_WORD_VAR2(MODE4)
   #define GPIO_MODE5_VAR2  GPIO_WORD_VAR2(MODE5)
   #define GPIO_MODE6_VAR2  GPIO_WORD_VAR2(MODE6)
   #define GPIO_MODE7_VAR2  GPIO_WORD_VAR2(MODE7)
   #endif //defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_DIROUT_VAR2    GPIO_WORD_VAR2(DIR_OUT)
   #define GPIO_DIRIN_VAR2     GPIO_WORD_VAR2(DIR_IN)
   #endif /* DRV_GPIO_REG_AS_6228 */
   
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6256)|| defined(DRV_GPIO_REG_AS_6255)
   #define GPIO_MODE0_VAR3     GPIO_WORD_VAR3(MODE0)
   #define GPIO_MODE1_VAR3     GPIO_WORD_VAR3(MODE1)
   #define GPIO_MODE2_VAR3     GPIO_WORD_VAR3(MODE2)
   #define GPIO_MODE3_VAR3     GPIO_WORD_VAR3(MODE3)
   #if defined(DRV_GPIO_MODE_3BITS)
   #define GPIO_MODE4_VAR3  GPIO_WORD_VAR3(MODE4)   
   #elif defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_MODE4_VAR3  GPIO_WORD_VAR3(MODE4)
   #define GPIO_MODE5_VAR3  GPIO_WORD_VAR3(MODE5)
   #define GPIO_MODE6_VAR3  GPIO_WORD_VAR3(MODE6)
   #define GPIO_MODE7_VAR3  GPIO_WORD_VAR3(MODE7)
   #endif //defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_DIROUT_VAR3    GPIO_WORD_VAR3(DIR_OUT)
   #define GPIO_DIRIN_VAR3     GPIO_WORD_VAR3(DIR_IN)
   #endif /* DRV_GPIO_REG_AS_6228 */
#endif /* !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A) */

/*********************************************************************************************/
/*********************************************************************************************/ 
/**************************** For each GPIO mode, specify if each GPIO pin is allowed to ******/
/****************set to this mode with '1' allowed, '0' on the corresponding bit position******/
/**********  Bit 0 means GPIO0, Bit 1 means GPIO1... etc ****************************************/ 
/**************************************END****************************************************/ 
/************************************************************************************************/ 



/*********************************************************************************************/
/*********************************************************************************************/ 
/**************************** For each GPO mode, specify if each GPO pin is allowed to ******/
/****************set to this mode with '1' allowed, '0' on the corresponding bit position******/
/**********  Bit 0 means GPO0, Bit 1 means GPO1... etc ****************************************/ 
/**************************************START****************************************************/ 
/************************************************************************************************/ 

#if defined(DRV_GPIO_REG_AS_6205B) || defined(DRV_GPIO_REG_AS_6225)
   #define GPO_MODE0_VAR0  (MODE0_GPO0 | (MODE0_GPO1 << 1) | (MODE0_GPO2 << 2) | (MODE0_GPO3 << 3))
   #define GPO_MODE1_VAR0  (MODE1_GPO0 | (MODE1_GPO1 << 1) | (MODE1_GPO2 << 2) | (MODE1_GPO3 << 3))
   #define GPO_MODE2_VAR0  (MODE2_GPO0 | (MODE2_GPO1 << 1) | (MODE2_GPO2 << 2) | (MODE2_GPO3 << 3))
   #define GPO_MODE3_VAR0  (MODE3_GPO0 | (MODE3_GPO1 << 1) | (MODE3_GPO2 << 2) | (MODE3_GPO3 << 3))
#elif defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227)
   #define GPO_MODE0_VAR0  (MODE0_GPO0 | (MODE0_GPO1 << 1) | (MODE0_GPO2 << 2) | (MODE0_GPO3 << 3) | (MODE0_GPO4 << 4))
   #define GPO_MODE1_VAR0  (MODE1_GPO0 | (MODE1_GPO1 << 1) | (MODE1_GPO2 << 2) | (MODE1_GPO3 << 3) | (MODE1_GPO4 << 4))
   #define GPO_MODE2_VAR0  (MODE2_GPO0 | (MODE2_GPO1 << 1) | (MODE2_GPO2 << 2) | (MODE2_GPO3 << 3) | (MODE2_GPO4 << 4))
   #define GPO_MODE3_VAR0  (MODE3_GPO0 | (MODE3_GPO1 << 1) | (MODE3_GPO2 << 2) | (MODE3_GPO3 << 3) | (MODE3_GPO4 << 4))
#elif defined(DRV_GPIO_REG_AS_6218B) || defined(DRV_GPIO_REG_AS_6228)
   #define GPO_MODE0_VAR0  (MODE0_GPO0 | (MODE0_GPO1 << 1) | (MODE0_GPO2 << 2))
   #define GPO_MODE1_VAR0  (MODE1_GPO0 | (MODE1_GPO1 << 1) | (MODE1_GPO2 << 2))
   #define GPO_MODE2_VAR0  (MODE2_GPO0 | (MODE2_GPO1 << 1) | (MODE2_GPO2 << 2))
   #define GPO_MODE3_VAR0  (MODE3_GPO0 | (MODE3_GPO1 << 1) | (MODE3_GPO2 << 2))
#endif

/*********************************************************************************************/
/*********************************************************************************************/ 
/**************************** For each GPO mode, specify if each GPO pin is allowed to ******/
/****************set to this mode with '1' allowed, '0' on the corresponding bit position******/
/**********  Bit 0 means GPO0, Bit 1 means GPO1... etc ****************************************/ 
/**************************************END****************************************************/ 
/************************************************************************************************/ 



/*********************************************************************************************/
/*********************************************************************************************/ 
/*** The '1' of the bit in the variables denotes that the mode is allowed to be set for the **/
/*** corresponding pin.******************gpio_mode_allowed[][4]*******************************/
/**************************************START***************************************************/
/**********************************************************************************************/ 
#if !defined(DRV_GPIO_MODE_4BITS) && !defined(DRV_GPIO_MODE_3BITS)
const kal_uint32  gpio_mode_allowed[][4] = {
   {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0}
   #if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A)
   ,{GPIO_MODE0_VAR1, GPIO_MODE1_VAR1, GPIO_MODE2_VAR1, GPIO_MODE3_VAR1}
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276)
   ,{GPIO_MODE0_VAR2, GPIO_MODE1_VAR2, GPIO_MODE2_VAR2, GPIO_MODE3_VAR2}
   #endif
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   ,{GPIO_MODE0_VAR3, GPIO_MODE1_VAR3, GPIO_MODE2_VAR3, GPIO_MODE3_VAR3}
   #endif
   #endif /* !defined(DRV_GPIO_REG_AS_6205B) */
};
#elif defined(DRV_GPIO_MODE_4BITS)//#if defined(DRV_GPIO_MODE_4BITS)
const kal_uint32  gpio_mode_allowed[][8] = {
#if defined(DRV_GPIO_REG_AS_6255)
   {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0, GPIO_MODE4_VAR0, GPIO_MODE5_VAR0, GPIO_MODE6_VAR0, GPIO_MODE7_VAR0}
   ,{GPIO_MODE0_VAR1, GPIO_MODE1_VAR1, GPIO_MODE2_VAR1, GPIO_MODE3_VAR1, GPIO_MODE4_VAR1, GPIO_MODE5_VAR1, GPIO_MODE6_VAR1, GPIO_MODE7_VAR1}
   ,{GPIO_MODE0_VAR2, GPIO_MODE1_VAR2, GPIO_MODE2_VAR2, GPIO_MODE3_VAR2, GPIO_MODE4_VAR2, GPIO_MODE5_VAR2, GPIO_MODE6_VAR2, GPIO_MODE7_VAR2}
   ,{GPIO_MODE0_VAR3, GPIO_MODE1_VAR3, GPIO_MODE2_VAR3, GPIO_MODE3_VAR3, GPIO_MODE4_VAR3, GPIO_MODE5_VAR3, GPIO_MODE6_VAR3, GPIO_MODE7_VAR3}
#elif defined(DRV_GPIO_REG_AS_6256)
    {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0, GPIO_MODE4_VAR0, GPIO_MODE5_VAR0, GPIO_MODE6_VAR0, GPIO_MODE7_VAR0}
   ,{GPIO_MODE0_VAR1, GPIO_MODE1_VAR1, GPIO_MODE2_VAR1, GPIO_MODE3_VAR1, GPIO_MODE4_VAR1, GPIO_MODE5_VAR1, GPIO_MODE6_VAR1, GPIO_MODE7_VAR1}
   ,{GPIO_MODE0_VAR2, GPIO_MODE1_VAR2, GPIO_MODE2_VAR2, GPIO_MODE3_VAR2, GPIO_MODE4_VAR2, GPIO_MODE5_VAR2, GPIO_MODE6_VAR2, GPIO_MODE7_VAR2}
   ,{GPIO_MODE0_VAR3, GPIO_MODE1_VAR3, GPIO_MODE2_VAR3, GPIO_MODE3_VAR3, GPIO_MODE4_VAR3, GPIO_MODE5_VAR3, GPIO_MODE6_VAR3, GPIO_MODE7_VAR3}
#elif defined(DRV_GPIO_REG_AS_6253E_1)
   {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0, GPIO_MODE4_VAR0, GPIO_MODE5_VAR0, GPIO_MODE6_VAR0, GPIO_MODE7_VAR0}
   ,{GPIO_MODE0_VAR1, GPIO_MODE1_VAR1, GPIO_MODE2_VAR1, GPIO_MODE3_VAR1, GPIO_MODE4_VAR1, GPIO_MODE5_VAR1, GPIO_MODE6_VAR1, GPIO_MODE7_VAR1}
#elif defined(DRV_GPIO_REG_AS_6251)
   {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0, GPIO_MODE4_VAR0, GPIO_MODE5_VAR0, GPIO_MODE6_VAR0, GPIO_MODE7_VAR0}
#elif defined(DRV_GPIO_REG_AS_6250)
    {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0, GPIO_MODE4_VAR0, GPIO_MODE5_VAR0, GPIO_MODE6_VAR0, GPIO_MODE7_VAR0}
   ,{GPIO_MODE0_VAR1, GPIO_MODE1_VAR1, GPIO_MODE2_VAR1, GPIO_MODE3_VAR1, GPIO_MODE4_VAR1, GPIO_MODE5_VAR1, GPIO_MODE6_VAR1, GPIO_MODE7_VAR1}
   ,{GPIO_MODE0_VAR2, GPIO_MODE1_VAR2, GPIO_MODE2_VAR2, GPIO_MODE3_VAR2, GPIO_MODE4_VAR2, GPIO_MODE5_VAR2, GPIO_MODE6_VAR2, GPIO_MODE7_VAR2}
#endif //defined(DRV_GPIO_REG_AS_6250)
};
#elif defined(DRV_GPIO_MODE_3BITS)
const kal_uint32  gpio_mode_allowed[][5] = {
#if defined(DRV_GPIO_REG_AS_6276)
    {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0,GPIO_MODE4_VAR0}
   ,{GPIO_MODE0_VAR1, GPIO_MODE1_VAR1, GPIO_MODE2_VAR1, GPIO_MODE3_VAR1,GPIO_MODE4_VAR1}
   ,{GPIO_MODE0_VAR2, GPIO_MODE1_VAR2, GPIO_MODE2_VAR2, GPIO_MODE3_VAR2,GPIO_MODE4_VAR2}
   ,{GPIO_MODE0_VAR3, GPIO_MODE1_VAR3, GPIO_MODE2_VAR3, GPIO_MODE3_VAR3,GPIO_MODE4_VAR3}
#endif  
};

#endif //#if !defined(DRV_GPIO_MODE_4BITS) && !defined(DRV_GPIO_MODE_3BITS)


/*********************************************************************************************/
/*********************************************************************************************/ 
/*** The '1' of the bit in the variables denotes that the mode is allowed to be set for the **/
/*** corresponding pin.***********************************************************************/
/*************************************START***************************************************/
/**********************************************************************************************/ 

kal_uint32  gpio_check_for_write[] = {
   0xffffffff
   #if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A)
   #if defined(DRV_GPIO_REG_AS_6251)
   ,0x0
   #else //defined(DRV_GPIO_REG_AS_6251)
   ,0xffffffff
   #endif //defined(DRV_GPIO_REG_AS_6251)
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1) || defined(DRV_GPIO_REG_AS_6256)  || defined(DRV_GPIO_REG_AS_6250) 
   ,0xffffffff
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6256)
   ,0xffffffff
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif
   #endif /* !defined(DRV_GPIO_REG_AS_6205B) */
};

kal_uint32  gpio_check_for_read[] = {
   0xffffffff
   #if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A)
   #if defined(DRV_GPIO_REG_AS_6251)
   ,0x0
   #else //defined(DRV_GPIO_REG_AS_6251)
   ,0xffffffff
   #endif //defined(DRV_GPIO_REG_AS_6251)
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1) || defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6250) 
   ,0xffffffff
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6256)
   ,0xffffffff
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif
   #endif /* !defined(DRV_GPIO_REG_AS_6205B) */
};

/* The '1' of the bit in the variables denotes that the direction output is allowed to be 
   set for the corresponding pin. */
const kal_uint32  gpio_dir_out_allowed[] = {
   GPIO_DIROUT_VAR0
   #if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A)
   ,GPIO_DIROUT_VAR1
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1) || defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6250)
   ,GPIO_DIROUT_VAR2
   #endif
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6256)
   ,GPIO_DIROUT_VAR3
   #endif
   #endif /* !defined(DRV_GPIO_REG_AS_6205B) */
};

/* The '1' of the bit in the variables denotes that the direction input is allowed to be 
   set for the corresponding pin. */
const kal_uint32  gpio_dir_in_allowed[] = {
	GPIO_DIRIN_VAR0
   #if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A)
   ,GPIO_DIRIN_VAR1
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1) || defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6250)
   ,GPIO_DIRIN_VAR2
   #endif
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6256)
   ,GPIO_DIRIN_VAR3
   #endif
   #endif /* !defined(DRV_GPIO_REG_AS_6205B) */
};

#if (!defined(DRV_GPIO_WO_GPO))
const kal_uint16  gpo_mode_allowed[] = {
	GPO_MODE0_VAR0, GPO_MODE1_VAR0, GPO_MODE2_VAR0, GPO_MODE3_VAR0
};
kal_uint16  gpo_check_for_write[] = {
	0xffff
};
#endif /*!defined(DRV_GPIO_REG_AS_6223)*/



/*********************************************************************************************/
/*********************************************************************************************/ 
/*** The '1' of the bit in the variables denotes that the mode is allowed to be set for the **/
/*** corresponding pin.***********************************************************************/
/*************************************END*****************************************************/
/**********************************************************************************************/ 

#if defined(MT6276_S01)
#define CLK_MUX_SEL0_VALUE (CLKSEL1 | (CLKSEL2<<4) | (CLKSEL3<<8)| (CLKSEL4<<12) \
														|(CLKSEL5<<16)|(CLKSEL6<<20)|(CLKSEL7<<24)|(CLKSEL8<<28))
														
#define CLK_MUX_SEL1_VALUE (CLKSEL9 | (CLKSEL10<<4) | (CLKSEL11<<8)| (CLKSEL12<<12) \
														|(CLKSEL13<<16))
const kal_uint32 GPIO_CLK_SEL[13]={CLKSEL1,CLKSEL2,CLKSEL3,CLKSEL4,CLKSEL5,CLKSEL6,CLKSEL7, \
                                    CLKSEL8,CLKSEL9,CLKSEL10,CLKSEL11,CLKSEL12,CLKSEL13};
#endif


/*******************************************************************************/


#endif /* __CHIP_SUPP_GPIO_DRV_TOOL__ */


/*********************************************************************************************/
/*********************************************************************************************/ 
/************************************** GPIO_Setting_init*************************************/
/************************************START***************************************************/
/**********************************************************************************************/ 

void GPIO_setting_init(void)
{
#if !defined(DRV_GPIO_OFF)
#if defined(__CHIP_SUPP_GPIO_DRV_TOOL__)

#if !defined(DRV_GPIO_MODE_4BITS) && !defined(DRV_GPIO_MODE_3BITS)
   DRV_GPIO_WriteReg(GPIO_MODE1, GPIO_MODE_REG1);
#if !defined(DRV_GPIO_REG_AS_TK6516)
   DRV_GPIO_WriteReg(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_GPIO_WriteReg(GPIO_MODE3, GPIO_MODE_REG3);
#if defined(DRV_GPIO_REG_AS_6205B)
   /* Note that for MT6205B, GPO mode register is on GPIO_MODE3, not GPO_MODE. */
   DRV_GPIO_WriteReg(GPIO_MODE4, GPO_MODE_REG);
#elif defined(DRV_GPIO_REG_AS_6270A)
   DRV_GPIO_WriteReg(GPIO_MODE4, GPIO_MODE_REG4);
#else /* defined(DRV_GPIO_REG_AS_6270A) */
   DRV_GPIO_WriteReg(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_GPIO_WriteReg(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_GPIO_WriteReg(GPIO_MODE6, GPIO_MODE_REG6);
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E)
   DRV_GPIO_WriteReg(GPIO_MODE7, GPIO_MODE_REG7);
      #if defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6276)
      DRV_GPIO_WriteReg(GPIO_MODE8, GPIO_MODE_REG8);
         #if defined(DRV_GPIO_REG_AS_6228)
         DRV_GPIO_WriteReg(GPIO_MODE9, GPIO_MODE_REG9);
         DRV_GPIO_WriteReg(GPIO_MODE10, GPIO_MODE_REG10);
         #endif
         #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276)
         DRV_GPIO_WriteReg(GPIO_MODE9, GPIO_MODE_REG9);
            #if !defined(DRV_GPIO_REG_AS_6236) 
            DRV_GPIO_WriteReg(GPIO_MODEA, GPIO_MODE_REGA);
               #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T)
               DRV_GPIO_WriteReg(GPIO_MODEB, GPIO_MODE_REGB);
               #endif
               #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
               DRV_GPIO_WriteReg(GPIO_MODEB, GPIO_MODE_REGB);
               DRV_GPIO_WriteReg(GPIO_MODEC, GPIO_MODE_REGC);
               DRV_GPIO_WriteReg(GPIO_MODED, GPIO_MODE_REGD);
                  #if  defined(DRV_GPIO_REG_AS_6276)
                  DRV_GPIO_WriteReg(GPIO_MODEE, GPIO_MODE_REGE);
                  #endif // defined(DRV_GPIO_REG_AS_6276)
               #endif
            #endif //!defined(DRV_GPIO_REG_AS_6236) 
         #endif
      #endif
   #endif
   #if (!defined(DRV_GPIO_WO_GPO))
   DRV_GPIO_WriteReg(GPO_MODE, GPO_MODE_REG);
   #endif
#endif /* defined(DRV_GPIO_REG_AS_6205B) */
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */
#elif defined(DRV_GPIO_MODE_3BITS)
#if defined(DRV_GPIO_REG_AS_6276)
   DRV_GPIO_WriteReg(GPIO_MODE0, GPIO_MODE_REG0);
   DRV_GPIO_WriteReg(GPIO_MODE1, GPIO_MODE_REG1);
   DRV_GPIO_WriteReg(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_GPIO_WriteReg(GPIO_MODE3, GPIO_MODE_REG3);
   DRV_GPIO_WriteReg(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_GPIO_WriteReg(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_GPIO_WriteReg(GPIO_MODE6, GPIO_MODE_REG6);
   DRV_GPIO_WriteReg(GPIO_MODE7, GPIO_MODE_REG7);
   DRV_GPIO_WriteReg(GPIO_MODE8, GPIO_MODE_REG8);
   DRV_GPIO_WriteReg(GPIO_MODE9, GPIO_MODE_REG9);
   DRV_GPIO_WriteReg(GPIO_MODEA, GPIO_MODE_REGA);
   DRV_GPIO_WriteReg(GPIO_MODEB, GPIO_MODE_REGB);
   DRV_GPIO_WriteReg(GPIO_MODEC, GPIO_MODE_REGC);
   DRV_GPIO_WriteReg(GPIO_MODED, GPIO_MODE_REGD);
   DRV_GPIO_WriteReg(GPIO_MODEE, GPIO_MODE_REGE);
   DRV_GPIO_WriteReg(GPIO_MODEF, GPIO_MODE_REGF);
   DRV_GPIO_WriteReg(GPIO_MODE10, GPIO_MODE_REG10);
   DRV_GPIO_WriteReg(GPIO_MODE11, GPIO_MODE_REG11);
   DRV_GPIO_WriteReg(GPIO_MODE12, GPIO_MODE_REG12);
   DRV_GPIO_WriteReg(GPIO_MODE13, GPIO_MODE_REG13);
   DRV_GPIO_WriteReg(GPIO_MODE14, GPIO_MODE_REG14);
   DRV_GPIO_WriteReg(GPIO_MODE15, GPIO_MODE_REG15);	
	//wait after drv_tool check in, there should modify.
  // DRV_GPIO_WriteReg(GPIO_MODE16, GPIO_MODE_REG16);	
#endif   
#else // DRV_GPIO_MODE_4BITS is not defined
#if defined(DRV_GPIO_REG_AS_6253E_1)
   DRV_GPIO_WriteReg32(GPIO_MODE1, GPIO_MODE_REG1);
   DRV_GPIO_WriteReg32(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_GPIO_WriteReg32(GPIO_MODE3, GPIO_MODE_REG3);
   DRV_GPIO_WriteReg32(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_GPIO_WriteReg32(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_GPIO_WriteReg32(GPIO_MODE6, GPIO_MODE_REG6);
   DRV_GPIO_WriteReg32(GPIO_MODE7, GPIO_MODE_REG7);
   DRV_GPIO_WriteReg32(GPIO_MODE8, GPIO_MODE_REG8);
   DRV_GPIO_WriteReg32(GPIO_MODE9, GPIO_MODE_REG9);
#endif

#if defined(DRV_GPIO_REG_AS_6255)
   DRV_GPIO_WriteReg(GPIO_MODE1, GPIO_MODE_REG1);
   DRV_GPIO_WriteReg(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_GPIO_WriteReg(GPIO_MODE3, GPIO_MODE_REG3);
   DRV_GPIO_WriteReg(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_GPIO_WriteReg(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_GPIO_WriteReg(GPIO_MODE6, GPIO_MODE_REG6);
   DRV_GPIO_WriteReg(GPIO_MODE7, GPIO_MODE_REG7);
   DRV_GPIO_WriteReg(GPIO_MODE8, GPIO_MODE_REG8);
   DRV_GPIO_WriteReg(GPIO_MODE9, GPIO_MODE_REG9);
   DRV_GPIO_WriteReg(GPIO_MODE10, GPIO_MODE_REG10);
   DRV_GPIO_WriteReg(GPIO_MODE11, GPIO_MODE_REG11);
   DRV_GPIO_WriteReg(GPIO_MODE12, GPIO_MODE_REG12);
   DRV_GPIO_WriteReg(GPIO_MODE13, GPIO_MODE_REG13);
   DRV_GPIO_WriteReg(GPIO_MODE14, GPIO_MODE_REG14);
   DRV_GPIO_WriteReg(GPIO_MODE15, GPIO_MODE_REG15);
   DRV_GPIO_WriteReg(GPIO_MODE16, GPIO_MODE_REG16);
   DRV_GPIO_WriteReg(GPIO_MODE17, GPIO_MODE_REG17);
   DRV_GPIO_WriteReg(GPIO_MODE18, GPIO_MODE_REG18);
   DRV_GPIO_WriteReg(GPIO_MODE19, GPIO_MODE_REG19);
   DRV_GPIO_WriteReg(GPIO_MODE20, GPIO_MODE_REG20);
   DRV_GPIO_WriteReg(GPIO_MODE21, GPIO_MODE_REG21);
   DRV_GPIO_WriteReg(GPIO_MODE22, GPIO_MODE_REG22);
   DRV_GPIO_WriteReg(GPIO_MODE23, GPIO_MODE_REG23);
   DRV_GPIO_WriteReg(GPIO_MODE24, GPIO_MODE_REG24);
   DRV_GPIO_WriteReg(GPIO_MODE25, GPIO_MODE_REG25);
   DRV_GPIO_WriteReg(GPIO_MODE26, GPIO_MODE_REG26);
   DRV_GPIO_WriteReg(GPIO_MODE27, GPIO_MODE_REG27);
#elif defined(DRV_GPIO_REG_AS_6251)
   DRV_GPIO_WriteReg(GPIO_MODE1, GPIO_MODE_REG1);
   DRV_GPIO_WriteReg(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_GPIO_WriteReg(GPIO_MODE3, GPIO_MODE_REG3);
   DRV_GPIO_WriteReg(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_GPIO_WriteReg(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_GPIO_WriteReg(GPIO_MODE6, GPIO_MODE_REG6);
   DRV_GPIO_WriteReg(GPIO_MODE7, GPIO_MODE_REG7);
   DRV_GPIO_WriteReg(GPIO_MODE8, GPIO_MODE_REG8);
#endif //defined(DRV_GPIO_REG_AS_6255)
#if defined(DRV_GPIO_REG_AS_6256)
   DRV_GPIO_WriteReg(GPIO_MODE1, GPIO_MODE_REG1);
   DRV_GPIO_WriteReg(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_GPIO_WriteReg(GPIO_MODE3, GPIO_MODE_REG3);
   DRV_GPIO_WriteReg(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_GPIO_WriteReg(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_GPIO_WriteReg(GPIO_MODE6, GPIO_MODE_REG6);
   DRV_GPIO_WriteReg(GPIO_MODE7, GPIO_MODE_REG7);
   DRV_GPIO_WriteReg(GPIO_MODE8, GPIO_MODE_REG8);
   DRV_GPIO_WriteReg(GPIO_MODE9, GPIO_MODE_REG9);
   DRV_GPIO_WriteReg(GPIO_MODE10, GPIO_MODE_REG10);
   DRV_GPIO_WriteReg(GPIO_MODE11, GPIO_MODE_REG11);
   DRV_GPIO_WriteReg(GPIO_MODE12, GPIO_MODE_REG12);
   DRV_GPIO_WriteReg(GPIO_MODE13, GPIO_MODE_REG13);
   DRV_GPIO_WriteReg(GPIO_MODE14, GPIO_MODE_REG14);
   DRV_GPIO_WriteReg(GPIO_MODE15, GPIO_MODE_REG15);
   DRV_GPIO_WriteReg(GPIO_MODE16, GPIO_MODE_REG16);
   DRV_GPIO_WriteReg(GPIO_MODE17, GPIO_MODE_REG17);
   DRV_GPIO_WriteReg(GPIO_MODE18, GPIO_MODE_REG18);
   DRV_GPIO_WriteReg(GPIO_MODE19, GPIO_MODE_REG19);
   DRV_GPIO_WriteReg(GPIO_MODE20, GPIO_MODE_REG20);
   DRV_GPIO_WriteReg(GPIO_MODE21, GPIO_MODE_REG21);
   DRV_GPIO_WriteReg(GPIO_MODE22, GPIO_MODE_REG22);
   DRV_GPIO_WriteReg(GPIO_MODE23, GPIO_MODE_REG23);
   DRV_GPIO_WriteReg(GPIO_MODE24, GPIO_MODE_REG24);
   DRV_GPIO_WriteReg(GPIO_MODE25, GPIO_MODE_REG25);
   DRV_GPIO_WriteReg(GPIO_MODE26, GPIO_MODE_REG26);
   DRV_GPIO_WriteReg(GPIO_MODE27, GPIO_MODE_REG27);
#endif //defined(DRV_GPIO_REG_AS_6256)
   #if defined(DRV_GPIO_REG_AS_6250)
   DRV_GPIO_WriteReg32(GPIO_MODE1, GPIO_MODE_REG1);
   DRV_GPIO_WriteReg32(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_GPIO_WriteReg32(GPIO_MODE3, GPIO_MODE_REG3);
   DRV_GPIO_WriteReg32(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_GPIO_WriteReg32(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_GPIO_WriteReg32(GPIO_MODE6, GPIO_MODE_REG6);
   DRV_GPIO_WriteReg32(GPIO_MODE7, GPIO_MODE_REG7);
   DRV_GPIO_WriteReg32(GPIO_MODE8, GPIO_MODE_REG8);
   DRV_GPIO_WriteReg32(GPIO_MODE9, GPIO_MODE_REG9);
   DRV_GPIO_WriteReg32(GPIO_MODE10, GPIO_MODE_REG10);
   DRV_GPIO_WriteReg32(GPIO_MODE11, GPIO_MODE_REG11);
#endif //defined(DRV_GPIO_REG_AS_6250)
#endif //defined(DRV_GPIO_MODE_4BITS)

#if defined(DRV_GPIO_REG_AS_6205B)
   DRV_GPIO_WriteReg(GPIO_DIR, GPIO_DIR_REG1);
   DRV_GPIO_WriteReg(GPIO_DIR2, GPIO_DIR_REG2);
#elif defined(DRV_GPIO_REG_AS_TK6516)
   DRV_GPIO_WriteReg(GPIO_DIR1, GPIO_DIR_REG1);
#elif defined(DRV_GPIO_REG_AS_6270A)
   DRV_GPIO_WriteReg(GPIO_DIR1, GPIO_DIR_REG1);
   DRV_GPIO_WriteReg(GPIO_DIR2, GPIO_DIR_REG2);
#else  /* defined(DRV_GPIO_REG_AS_6270A) */
   DRV_GPIO_WriteReg(GPIO_DIR1, GPIO_DIR_REG1);
   DRV_GPIO_WriteReg(GPIO_DIR2, GPIO_DIR_REG2);
   DRV_GPIO_WriteReg(GPIO_DIR3, GPIO_DIR_REG3);
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E)|| defined(DRV_GPIO_REG_AS_6253E_1)
   DRV_GPIO_WriteReg(GPIO_DIR4, GPIO_DIR_REG4);
      #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6253E_1)
      DRV_GPIO_WriteReg(GPIO_DIR5, GPIO_DIR_REG5);
      #endif
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T)
      DRV_GPIO_WriteReg(GPIO_DIR5, GPIO_DIR_REG5);
      DRV_GPIO_WriteReg(GPIO_DIR6, GPIO_DIR_REG6);
      #endif
      #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
      DRV_GPIO_WriteReg(GPIO_DIR5, GPIO_DIR_REG5);
      DRV_GPIO_WriteReg(GPIO_DIR6, GPIO_DIR_REG6);
      DRV_GPIO_WriteReg(GPIO_DIR7, GPIO_DIR_REG7);
      #endif
   #elif defined(DRV_GPIO_REG_AS_6256)  || defined(DRV_GPIO_REG_AS_6255)
    DRV_GPIO_WriteReg(GPIO_DIR4, GPIO_DIR_REG4);
    DRV_GPIO_WriteReg(GPIO_DIR5, GPIO_DIR_REG5);
    DRV_GPIO_WriteReg(GPIO_DIR6, GPIO_DIR_REG6);
    DRV_GPIO_WriteReg(GPIO_DIR7, GPIO_DIR_REG7); 
#elif defined(DRV_GPIO_REG_AS_6250)
    DRV_GPIO_WriteReg(GPIO_DIR4, GPIO_DIR_REG4);
    DRV_GPIO_WriteReg(GPIO_DIR5, GPIO_DIR_REG5);
    DRV_GPIO_WriteReg(GPIO_DIR6, GPIO_DIR_REG6);
   #endif
#endif

#if !defined(DRV_GPIO_6250_SPECIAL_SET_REG)
#if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_TK6516) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6270A) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6251) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1) || defined(DRV_GPIO_REG_AS_6256)  || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6250)
   DRV_GPIO_WriteReg(GPIO_PULLSEL1, GPIO_PULLSEL_REG1);
#if !defined(DRV_GPIO_REG_AS_TK6516)
   DRV_GPIO_WriteReg(GPIO_PULLSEL2, GPIO_PULLSEL_REG2);
   #if !defined(DRV_GPIO_REG_AS_6270A)
   DRV_GPIO_WriteReg(GPIO_PULLSEL3, GPIO_PULLSEL_REG3);
   #if !defined(DRV_GPIO_REG_AS_6251)
   DRV_GPIO_WriteReg(GPIO_PULLSEL4, GPIO_PULLSEL_REG4);
   #if !defined(DRV_GPIO_REG_AS_6253E)
   DRV_GPIO_WriteReg(GPIO_PULLSEL5, GPIO_PULLSEL_REG5);
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6250) 
   DRV_GPIO_WriteReg(GPIO_PULLSEL6, GPIO_PULLSEL_REG6);
   #endif
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255)
   DRV_GPIO_WriteReg(GPIO_PULLSEL6, GPIO_PULLSEL_REG6);
   DRV_GPIO_WriteReg(GPIO_PULLSEL7, GPIO_PULLSEL_REG7);
   #endif
   #endif //!defined(DRV_GPIO_REG_AS_6253E)
   #endif //!defined(DRV_GPIO_REG_AS_6251)
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */
#endif
#else

   if( INT_SW_SecVersion()==SW_SEC_0)
   {
   DRV_GPIO_WriteReg(GPIO_PULLSEL1, GPIO_PULLSEL_REG1_E1);
   DRV_GPIO_WriteReg(GPIO_PULLSEL2, GPIO_PULLSEL_REG2_E1);
   DRV_GPIO_WriteReg(GPIO_PULLSEL3, GPIO_PULLSEL_REG3_E1);
   DRV_GPIO_WriteReg(GPIO_PULLSEL4, GPIO_PULLSEL_REG4_E1);
   DRV_GPIO_WriteReg(GPIO_PULLSEL5, GPIO_PULLSEL_REG5_E1);
   DRV_GPIO_WriteReg(GPIO_PULLSEL6, GPIO_PULLSEL_REG6_E1);
   DRV_GPIO_WriteReg(GPIO_PULLSEL7, GPIO_PULLSEL_REG7_E1);
   DRV_GPIO_WriteReg(GPIO_PULLSEL8, GPIO_PULLSEL_REG8_E1);
   }
   else

   {
   DRV_GPIO_WriteReg(GPIO_PULLSEL1, GPIO_PULLSEL_REG1_E2);
   DRV_GPIO_WriteReg(GPIO_PULLSEL2, GPIO_PULLSEL_REG2_E2);
   DRV_GPIO_WriteReg(GPIO_PULLSEL3, GPIO_PULLSEL_REG3_E2);
   DRV_GPIO_WriteReg(GPIO_PULLSEL4, GPIO_PULLSEL_REG4_E2);
   DRV_GPIO_WriteReg(GPIO_PULLSEL5, GPIO_PULLSEL_REG5_E2);
   DRV_GPIO_WriteReg(GPIO_PULLSEL6, GPIO_PULLSEL_REG6_E2);
   
   
   
   }

#endif


#if !defined(DRV_GPIO_6250_SPECIAL_SET_REG)
#if defined(DRV_GPIO_REG_AS_6205B)
   DRV_GPIO_WriteReg(GPIO_PULLEN, GPIO_PULL_REG1);
   DRV_GPIO_WriteReg(GPIO_PULLEN2, GPIO_PULL_REG2);
#elif defined(DRV_GPIO_REG_AS_TK6516)
   DRV_GPIO_WriteReg(GPIO_PULLEN1, GPIO_PULL_REG1);
#elif defined(DRV_GPIO_REG_AS_6270A)
   DRV_GPIO_WriteReg(GPIO_PULLEN1, GPIO_PULL_REG1);
   DRV_GPIO_WriteReg(GPIO_PULLEN2, GPIO_PULL_REG2);
#else  /* defined(DRV_GPIO_REG_AS_6270A) */
   DRV_GPIO_WriteReg(GPIO_PULLEN1, GPIO_PULL_REG1);
   DRV_GPIO_WriteReg(GPIO_PULLEN2, GPIO_PULL_REG2);
   DRV_GPIO_WriteReg(GPIO_PULLEN3, GPIO_PULL_REG3);
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1)
   DRV_GPIO_WriteReg(GPIO_PULLEN4, GPIO_PULL_REG4);
      #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6253E_1)
      DRV_GPIO_WriteReg(GPIO_PULLEN5, GPIO_PULL_REG5);
      #endif
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) 
      DRV_GPIO_WriteReg(GPIO_PULLEN5, GPIO_PULL_REG5);
      DRV_GPIO_WriteReg(GPIO_PULLEN6, GPIO_PULL_REG6);
      #endif
      #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
      DRV_GPIO_WriteReg(GPIO_PULLEN5, GPIO_PULL_REG5);
      DRV_GPIO_WriteReg(GPIO_PULLEN6, GPIO_PULL_REG6);
      DRV_GPIO_WriteReg(GPIO_PULLEN7, GPIO_PULL_REG7);
      #endif
   #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255)
      DRV_GPIO_WriteReg(GPIO_PULLEN4, GPIO_PULL_REG4);
      DRV_GPIO_WriteReg(GPIO_PULLEN5, GPIO_PULL_REG5);
      DRV_GPIO_WriteReg(GPIO_PULLEN6, GPIO_PULL_REG6);
      DRV_GPIO_WriteReg(GPIO_PULLEN7, GPIO_PULL_REG7);
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */
#else
  if( INT_SW_SecVersion()==SW_SEC_0)
   {

      DRV_GPIO_WriteReg(GPIO_PULLEN1, GPIO_PULL_REG1_E1);
      DRV_GPIO_WriteReg(GPIO_PULLEN2, GPIO_PULL_REG2_E1);
      DRV_GPIO_WriteReg(GPIO_PULLEN3, GPIO_PULL_REG3_E1);
      DRV_GPIO_WriteReg(GPIO_PULLEN4, GPIO_PULL_REG4_E1);
	  DRV_GPIO_WriteReg(GPIO_PULLEN5, GPIO_PULL_REG5_E1);
      DRV_GPIO_WriteReg(GPIO_PULLEN6, GPIO_PULL_REG6_E1);
      DRV_GPIO_WriteReg(GPIO_PULLEN7, GPIO_PULL_REG7_E1);
	  DRV_GPIO_WriteReg(GPIO_PULLEN8, GPIO_PULL_REG8_E1);
    }
  else
   {
      DRV_GPIO_WriteReg(GPIO_PULLEN1, GPIO_PULL_REG1_E2);
      DRV_GPIO_WriteReg(GPIO_PULLEN2, GPIO_PULL_REG2_E2);
      DRV_GPIO_WriteReg(GPIO_PULLEN3, GPIO_PULL_REG3_E2);
      DRV_GPIO_WriteReg(GPIO_PULLEN4, GPIO_PULL_REG4_E2);
	  DRV_GPIO_WriteReg(GPIO_PULLEN5, GPIO_PULL_REG5_E2);
      DRV_GPIO_WriteReg(GPIO_PULLEN6, GPIO_PULL_REG6_E2);
    }
   #endif

#if !defined(DRV_GPIO_REG_AS_6205B)
   DRV_GPIO_WriteReg(GPIO_DINV1, GPIO_INV_REG1);
#if !defined(DRV_GPIO_REG_AS_TK6516)
   DRV_GPIO_WriteReg(GPIO_DINV2, GPIO_INV_REG2);
   #if !defined(DRV_GPIO_REG_AS_6270A) && !defined(DRV_GPIO_REG_AS_6251)
   DRV_GPIO_WriteReg(GPIO_DINV3, GPIO_INV_REG3);
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228)  || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1)
   DRV_GPIO_WriteReg(GPIO_DINV4, GPIO_INV_REG4);
      #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6253E_1)
      DRV_GPIO_WriteReg(GPIO_DINV5, GPIO_INV_REG5);
      #endif
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) 
      DRV_GPIO_WriteReg(GPIO_DINV5, GPIO_INV_REG5);
      DRV_GPIO_WriteReg(GPIO_DINV6, GPIO_INV_REG6);
      #endif
      #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
      DRV_GPIO_WriteReg(GPIO_DINV5, GPIO_INV_REG5);
      DRV_GPIO_WriteReg(GPIO_DINV6, GPIO_INV_REG6);
      DRV_GPIO_WriteReg(GPIO_DINV7, GPIO_INV_REG7);
      #endif
   #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255)
      DRV_GPIO_WriteReg(GPIO_DINV4, GPIO_INV_REG4); 
      DRV_GPIO_WriteReg(GPIO_DINV5, GPIO_INV_REG5);
      DRV_GPIO_WriteReg(GPIO_DINV6, GPIO_INV_REG6);
      DRV_GPIO_WriteReg(GPIO_DINV7, GPIO_INV_REG7);  
    #elif defined(DRV_GPIO_REG_AS_6250)
      DRV_GPIO_WriteReg(GPIO_DINV4, GPIO_INV_REG4); 
      DRV_GPIO_WriteReg(GPIO_DINV5, GPIO_INV_REG5);
      DRV_GPIO_WriteReg(GPIO_DINV6, GPIO_INV_REG6);
   #endif
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */

#if defined(DRV_GPIO_REG_AS_6205B)
   DRV_GPIO_WriteReg(GPIO_DOUT, GPIO_OUTPUT_REG1);
   DRV_GPIO_WriteReg(GPIO_DOUT2, GPIO_OUTPUT_REG2);
#elif defined(DRV_GPIO_REG_AS_TK6516)
   DRV_GPIO_WriteReg(GPIO_DOUT1, GPIO_OUTPUT_REG1);
#elif defined(DRV_GPIO_REG_AS_6270A)
   DRV_GPIO_WriteReg(GPIO_DOUT1, GPIO_OUTPUT_REG1);
   DRV_GPIO_WriteReg(GPIO_DOUT2, GPIO_OUTPUT_REG2);
#else  /* defined(DRV_GPIO_REG_AS_6270A) */
   DRV_GPIO_WriteReg(GPIO_DOUT1, GPIO_OUTPUT_REG1);
   DRV_GPIO_WriteReg(GPIO_DOUT2, GPIO_OUTPUT_REG2);
   DRV_GPIO_WriteReg(GPIO_DOUT3, GPIO_OUTPUT_REG3);
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) ||  defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1)
   DRV_GPIO_WriteReg(GPIO_DOUT4, GPIO_OUTPUT_REG4);
      #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6253E_1)
      DRV_GPIO_WriteReg(GPIO_DOUT5, GPIO_OUTPUT_REG5);
      #endif
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T)
      DRV_GPIO_WriteReg(GPIO_DOUT5, GPIO_OUTPUT_REG5);
      DRV_GPIO_WriteReg(GPIO_DOUT6, GPIO_OUTPUT_REG6);
      #endif
      #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
      DRV_GPIO_WriteReg(GPIO_DOUT5, GPIO_OUTPUT_REG5);
      DRV_GPIO_WriteReg(GPIO_DOUT6, GPIO_OUTPUT_REG6);
      DRV_GPIO_WriteReg(GPIO_DOUT7, GPIO_OUTPUT_REG7);
      #endif
   #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255)
      DRV_GPIO_WriteReg(GPIO_DOUT4, GPIO_OUTPUT_REG4);
      DRV_GPIO_WriteReg(GPIO_DOUT5, GPIO_OUTPUT_REG5);
      DRV_GPIO_WriteReg(GPIO_DOUT6, GPIO_OUTPUT_REG6);
      DRV_GPIO_WriteReg(GPIO_DOUT7, GPIO_OUTPUT_REG7); 
#elif defined(DRV_GPIO_REG_AS_6250)
      DRV_GPIO_WriteReg(GPIO_DOUT4, GPIO_OUTPUT_REG4);
      DRV_GPIO_WriteReg(GPIO_DOUT5, GPIO_OUTPUT_REG5);
      DRV_GPIO_WriteReg(GPIO_DOUT6, GPIO_OUTPUT_REG6);
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */
#if (!defined(DRV_GPIO_WO_GPO))
   DRV_GPIO_WriteReg(GPO_DOUT, GPO_OUTPUT_REG1);
#endif
#if defined(DRV_GPIO_REG_AS_6253E)
   DRV_GPIO_WriteReg(GPIO_SPMODE, GPIO_SPMODE_REG);
   DRV_GPIO_WriteReg(GPIO_BANK, GPIO_BANK_REG);
#elif defined(DRV_GPIO_REG_AS_6253E_1)
   DRV_GPIO_WriteReg32(GPIO_SPMODE0, GPIO_SPMODE0_REG);
   DRV_GPIO_WriteReg32(GPIO_SPMODE1, GPIO_SPMODE1_REG);
#endif //defined(DRV_GPIO_REG_AS_6253E)
#if defined(MT6276_S01)
   DRV_GPIO_WriteReg32(CLK_MUX_SEL0, CLK_MUX_SEL0_VALUE);
   DRV_GPIO_WriteReg32(CLK_MUX_SEL1, CLK_MUX_SEL1_VALUE);
#endif

#if defined(DRV_GPIO_6250_SPECIAL_SET_REG)
    DRV_GPIO_WriteReg(GPIO_PUPDEN1,GPIO_PUPD_REG1);
    DRV_GPIO_WriteReg(GPIO_PUPDEN2,GPIO_PUPD_REG2);
    DRV_GPIO_WriteReg(GPIO_RESEN1,GPIO_RESEN_REG1);
    DRV_GPIO_WriteReg(GPIO_RESEN2,GPIO_RESEN_REG2);
	DRV_GPIO_WriteReg(GPIO_RESEN3,GPIO_RESEN_REG3);
    DRV_GPIO_WriteReg(ACFG_GPIO_CON1,ADIE_GPIO_OE_DOUT_REG);   //CONFIG  A-DIE  GPIO  OE& OUT
	DRV_GPIO_WriteReg(ACFG_GPIO_MODE,ADIE_GPIO_MODE_REG);
#endif  //defined(DRV_GPIO_6250_SPECIAL_SET_REG) 

#endif /* __CHIP_SUPP_GPIO_DRV_TOOL__*/
#endif /*!defined(DRV_GPIO_OFF)*/
}



#endif

#endif /* __CUST_NEW__ */

/*********************************************************************************************/
/*********************************************************************************************/ 
/************************************** GPIO_Setting_init*************************************/
/************************************END******************************************************/
