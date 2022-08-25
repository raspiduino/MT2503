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
 *    keypad_bl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the keypad task
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
 ****************************************************************************
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
 *    kbdmain.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the keypad task
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include 	"kal_release.h"

#include 	"drv_comm.h"
#include    "reg_base.h"
#include    "keypad_hw.h"
//#include    "keypad_sw.h"
//#include    "kbd_table.h"   
//#include    "drv_hisr.h"
//#include    "gpio_sw.h"
//#include   "eint.h"
//#include    "drv_trc.h"
//#include "kal_non_specific_general_types.h"
    #include "keypad.h"
    #include "kal_general_types.h"

#ifdef DRV_KBD_SW_KBD
#include "drv_features_kbd.h"
#include "sw_keypad.h"
#include "us_timer.h"
#endif

#ifdef __MTK_TARGET__
extern kal_uint32 INT_GetCurrentTime(void);
#endif /* __MTK_TARGET__ */
    
#if !defined(DRV_KBD_NOT_EXIST)

const keypad_customize_function_struct *keypadCustomFunc;
const keypad_struct *keypad_comm_def;
extern const keypad_customize_function_struct *keypad_GetFunc(void);

extern kal_uint8 usbdlkey_position;

extern kal_bool USBDLKey_Pressed(void);
kal_bool kbd_IsKeyPressed(kal_uint8 key);
//define in bl_Init.c
extern kal_bool isGPTTImer3Started(void);
extern void startGPTTImer3(void);
extern kal_uint16 getGPTTImer3Value(void);

void keypad_customize_init(void)
{
  if(keypad_comm_def == NULL)
  {
   keypadCustomFunc=keypad_GetFunc();
   keypad_comm_def = keypadCustomFunc->keypad_Get_Data();
  }
}   
#ifdef DRV_KBD_PWRKEY_FROM_EINT
void PWRKEY_EINT_HISR(void);
#endif
/*triple keypad*/
#if defined(DRV_KBD_TRIPLE_KEYPAD)
#define KEY_TYPE     3
/*double keypad*/
#elif defined(__COLUMN_EXTEND_KEYPAD__)
#define KEY_TYPE     2
/*single keypad*/
#else
#define KEY_TYPE     1
#endif
/*from MT6261,keypad hw re-orignize key status matrix*/
#if defined(DRV_KBD_STATUS_REG_REORG) && !defined(DRV_KBD_SW_KBD)
#ifdef __COLUMN_EXTEND_KEYPAD__
#define HW_KBD_PWR_POS 11
#else
#define HW_KBD_PWR_POS 16
#endif
void kbd_key_status_reorg(HKBD_CTRL_STA_MAP_T *key_status)
{
	kal_uint32 row,col,i,j, tmp;
	HKBD_CTRL_STA_MAP_T key_status_tmp;
	key_status_tmp.kbdmap_reg = key_status->kbdmap_reg;
	key_status_tmp.kbdmap_reg1 = key_status->kbdmap_reg1;
	key_status_tmp.kbdmap_reg2 = key_status->kbdmap_reg2;

	key_status->kbdmap_reg =0;
	key_status->kbdmap_reg1 =0;
	key_status->kbdmap_reg2 =0;
	j=0;	
	 for(i= 0; i<75; i++)
	 {	
	 #ifdef __COLUMN_EXTEND_KEYPAD__
	 	if((i+1)%3 == 0)
			continue;
	 #endif	
		if((j+1)%HW_KBD_PWR_POS == 0)
		{	
			((kal_uint32*)key_status)[j/32] |= 1<<(j%32);
			j++;  // power key position			
				
		}
		tmp = 0x1&((kal_uint32*)&key_status_tmp)[i/32]>>(i%32);
		
		((kal_uint32*)key_status)[j/32] |= tmp<<(j%32);
		j++;

	 }
	 ((kal_uint32*)key_status)[j/32] |= 1<<(j%32); 
 
}
#endif 
// internal api
static void kbd_get_status_reg(HKBD_CTRL_STA_MAP_T *pkeypad_status)
 {
	kal_uint32 initstatus = 0xFFFFFFFF;
	pkeypad_status->kbdmap_reg = initstatus;
	pkeypad_status->kbdmap_reg1= initstatus;
	pkeypad_status->kbdmap_reg2= initstatus;
  
#if defined(DRV_KBD_32KEYS_EQ_BELOW) || defined(FPGA) 
      pkeypad_status->kbdmap_reg = ( ((kal_uint32)(DRV_Reg(KP_HI_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_LOW_KEY))) );
#elif defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE) 
      pkeypad_status->kbdmap_reg = ( ((kal_uint32)(DRV_Reg(KP_MID_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_LOW_KEY))) );
#if defined(DRV_KBD_32KEYS_ABOVE) 
      pkeypad_status->kbdmap_reg1 = (kal_uint32)(DRV_Reg(KP_HI_KEY)); 
#elif defined(DRV_KBD_48KEYS_ABOVE) 
      pkeypad_status->kbdmap_reg1 = ( ((kal_uint32)(DRV_Reg(KP_HI_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_MID1_KEY))) ); 
#elif defined(DRV_KBD_64KEYS_ABOVE) 
      pkeypad_status->kbdmap_reg1 = ( ((kal_uint32)(DRV_Reg(KP_MID2_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_MID1_KEY))) ); 
      pkeypad_status->kbdmap_reg2 = (kal_uint32)(DRV_Reg(KP_HI_KEY)); 
#endif 
#endif

/*from MT6261,keypad hw re-orignize key status matrix*/
#if defined(DRV_KBD_STATUS_REG_REORG) && !defined(DRV_KBD_SW_KBD)
   kbd_key_status_reorg(pkeypad_status);
#endif

   }
/*************************************************************************
* FUNCTION                                                            
*	kbd_IsKeyPressed
*
* DESCRIPTION                                                           
*	
*	This function queries if a specific key is Pressed
*
* PARAMETERS
*  key        - Key ID to query
*
* RETURNS
*  KAL_TRUE   - The specific key is pressed
*  KAL_FALSE  - The specific key is NOT pressed or NOT supported
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef DRV_KBD_PWRKEY_FROM_EINT //For the chip that powerkey is seperate form keypad hw module
	kal_bool PowerKey_Press(void)
	{
	 if(DRV_KBD_Reg(PWRKEY_STATUS_REG)&0x0001)	//status 0:press 1 release
	 return KAL_FALSE;
	else
	  return KAL_TRUE;	 
	}	
 #endif  		
kal_bool kbd_IsKeyPressed(kal_uint8 key)
{
	 kal_uint32 num_key, i;
   kal_uint16 u4KeyReg = 0;
   kal_bool fgKeyPressed = KAL_FALSE;
	   const keypad_customize_function_struct *keypadCustomFunc = NULL;
	   const keypad_struct *keypad_comm_def = NULL;
#if defined(__EXTEND_QWERTY_KEYPAD__) //assume it only support fot 32 key above
   kal_bool btmp = KAL_TRUE;
   kal_uint32 j, k;
   kal_uint16 reg, checkRow, bit;
   kal_uint8    key_bit_map[kbd_allkeys+KBD_COLUMN*2] = {0};
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__) //assume it only support fot 32 key above
   
#ifdef DRV_KBD_SW_KBD /*SW keypad*/
	KEY_STATUS	key_status ;
	key_status.reg1 = 0xFFFFFFFF;
	key_status.reg2 = 0xFFFFFFFF;
	key_status.reg3 = 0xFFFFFFFF;
#else   /*HW keypad*/
#ifdef DRV_KBD_STATUS_REG_REORG
		 HKBD_CTRL_STA_MAP_T pkeypad_status;
#endif
#endif
 
	   if(keypad_comm_def == NULL)
		{
			keypadCustomFunc=keypad_GetFunc();
			keypad_comm_def = keypadCustomFunc->keypad_Get_Data();
		}	   
   num_key = sizeof(keypad_comm_def->keypad)/sizeof(kal_uint8);
		    
   #ifdef DRV_KBD_PWRKEY_FROM_EINT //For the chip that powerkey is seperate form keypad hw module
	   
		  if(key==keypad_comm_def->powerkey_position)
		  {
			  return PowerKey_Press();
		  }
   #endif     	
   for (i=0;i<num_key;i++){
	   if ( key == keypad_comm_def->keypad[i] )
		 {
#ifdef DRV_KBD_SW_KBD
			 sw_kbd_paremeter_init();
		 SW_KBD_GET_KEY_STATUS(&key_status);
		 if(i<32)
		 {
			 if((key_status.reg1 & (1<<i)) == 0)
				 fgKeyPressed = KAL_TRUE;
 
		 }
		 else if(i<64)
		 {
			 if((key_status.reg2 & (1<<(i-32)))==0)
				 fgKeyPressed = KAL_TRUE;
 
		 }
		 else if(i<96)
		 {
			 if((key_status.reg3 & (1<<(i-64)))==0)
				 fgKeyPressed = KAL_TRUE;
		 }
 
 
#else
#ifdef DRV_KBD_STATUS_REG_REORG
			 kbd_get_status_reg(&pkeypad_status);
			 if(i<32)
			 {
				 if((pkeypad_status.kbdmap_reg & (1<<i)) == 0)
					 fgKeyPressed = KAL_TRUE;
	 
			 }
			 else if(i<64)
			 {
				 if((pkeypad_status.kbdmap_reg1 & (1<<(i-32)))==0)
					 fgKeyPressed = KAL_TRUE;
	 
			 }
			 else if(i<96)
			 {
				 if((pkeypad_status.kbdmap_reg2 & (1<<(i-64)))==0)
					 fgKeyPressed = KAL_TRUE;
			 }
#else
#if defined(__EXTEND_QWERTY_KEYPAD__) //assume it only support fot 32 key above
         if(i >= kbd_allkeys) //GPO or GND
         {
            for(k=0; k<kbd_allkeys; ) //i already ++ in inner loop
            {
               // base on key register offset = 4 sequentially
               reg = DRV_KBD_Reg(KP_LOW_KEY + ((k>>4) <<2) );//  i/16 --> n-th register,  *4 --> register offset.
               for(j=0; j<16 && k<kbd_allkeys; j++, k++)
               {
                  bit = (reg >> (k&0xF) ) & 0x1; // select (i&0xF)-th bit in this register
                  if(key_bit_map[k] != bit)
                  {
                     key_bit_map[k] = bit; // put this bit into array
                  }
               }
            }
            // check which column is all low
            for(checkRow=0; checkRow<KBD_ROW; checkRow++)
            {
				   btmp = (kal_bool)(btmp & ((key_bit_map[checkRow*KBD_COLUMN + (i%KBD_COLUMN) ] == 1) ? KAL_FALSE : KAL_TRUE)); //if one key not press, we know this column not all low.
            }
            if(btmp == KAL_TRUE)
            {
               fgKeyPressed = KAL_TRUE; 
            }
				return fgKeyPressed;
         }
#endif
         // don't need to take care of key number define, num_key has information in it.
         if(i < 16) // key pressed
         {
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY);
         }
         else if(i < 32)
         {
            i -= 16;
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY + 0x4);
         }
         else if(i < 48)
         {
            i -= 32;
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY + 0x8);
         }
         else if(i < 64)
         {
            i -= 48;
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY + 0xC);
         }
         else
         {
            i -= 64;
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY + 0x10);
         }
         
         if( (u4KeyReg & (1 << i)) == 0)
         {
            fgKeyPressed = KAL_TRUE;
         }
#endif 
#endif 
         if(fgKeyPressed)
         {
            return KAL_TRUE;
         }
         else
         {
            break;
         }
      }
   }
   return KAL_FALSE;	
}

kal_bool BL_kbd_IsKeyPressed(kal_uint8 key)
{
   static kal_bool first = KAL_TRUE;
   kal_uint32 n;
   kal_uint32 key_press_delay_start=0;
   kal_uint32 elapsed;
   kal_uint16 key_press_delay=6554;//   26/128Hz=200ms
  /*sw keypad need not config kp_sel*/
#ifndef DRV_KBD_SW_KBD
  #if  defined(__COLUMN_EXTEND_KEYPAD__)
  DRV_KBD_SetBits(KP_SEL, COL_EXTEND_MASK);
  #endif
	#ifdef DRV_KBD_COL_ROW_SEL
  DRV_KBD_SetBits(KP_SEL, (DRV_KBD_COL_ROW_SEL<<6));
  #endif
#endif
   if(first)
   {
      first = KAL_FALSE;
      keypad_customize_init();

   
      key_press_delay_start=INT_GetCurrentTime();
      for(n=0; n<6000000; n++)
      {
         elapsed=INT_GetCurrentTime()-key_press_delay_start;
         if(elapsed>=key_press_delay)
	           break;
      }
   }
   return kbd_IsKeyPressed(key);
   
}

kal_bool BL_PowerKey_Press(void)
{
   keypad_customize_init();
   return BL_kbd_IsKeyPressed(keypad_comm_def->powerkey_position);	
}

    
kal_bool USBDLKey_Pressed(void)
{
   return BL_kbd_IsKeyPressed(usbdlkey_position);
}

#else
void keypad_customize_init(void){;}
kal_bool USBDLKey_Pressed(void){return KAL_FALSE;}
#endif

