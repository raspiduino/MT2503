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
 *    pwm_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for PWM driver.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef PWM_SW_H
#define PWM_SW_H

#include "drv_features_pwm.h"
#include "rwg_sw.h"
#include "kal_general_types.h"
#include "dcl.h"
#include "drv_comm.h"

#if defined(DRV_PWM_DRV_TOOL_SUPPORT)
#include "pwm_drv.h"
#endif
#if !defined(DRV_PWM_RWG)

//this should move to pwm_sw.h
#if defined(DRV_PWM_PWM2)
#if defined(DRV_PWM_PWM3)
#if defined(DRV_PWM_PWM4)
#define PWM_COUNT 4
#else //defined(DRV_PWM_PWM4)
#define PWM_COUNT 3
#endif//defined(DRV_PWM_PWM4)
#else //defined(DRV_PWM_PWM3)
#define PWM_COUNT 2
#endif //defined(DRV_PWM_PWM3)
#else //defined(DRV_PWM_PWM2)
#define PWM_COUNT 1
#endif//defined(DRV_PWM_PWM2)

#if defined(DRV_PWM2_KPAD_LED_3_DUTY)
  #define  PWM2_KPAD_0_DUTY     0
  #define  PWM2_KPAD_50_DUTY   50
  #define  PWM2_KPAD_100_DUTY  100
#endif
#if defined(DRV_PWM_DRV_TOOL_SUPPORT)

#define PWM_2CH_START_NUM 2
#if defined(DRV_PWM_3CH_ADDRESS)
#define PWM_3CH_START_NUM 4
#endif
#define PWM_CH_1  1
#define MAX_CHANNEL  PWM_MAX_NUM
#define PWM_Min_LEVEL  1
#define PWM_Max_LEVEL  5

typedef kal_uint32 PWM_CHANNEL;

typedef enum 
{
	PWM_CTRL_R=0,
	PWM_COUNT_R,
	PWM_THRES_R,
}PWM_REGISTER;

#if defined(DRV_PWM_3CH_ADDRESS)
#define DRV_PWM_READ_REG(channel,reg_type,retValue_addr)  \
do{ \
	if(channel < PWM_2CH_START_NUM){  \
		*((kal_uint16 *)retValue_addr) = DRV_PWM_Reg((PWM_CTRL + 0x04 * reg_type) + (channel - 1)*0x0c);}  \
	else if(channel >= PWM_3CH_START_NUM){   \
		*((kal_uint16 *)retValue_addr) = DRV_PWM_Reg((PWM_CTRL_3CH + 0x04 * reg_type) + (channel - PWM_3CH_START_NUM)*0x0c);}  \
	else{  \
		*((kal_uint16 *)retValue_addr) = DRV_PWM_Reg((PWM_CTRL_2CH + 0x04 * reg_type) + (channel - PWM_2CH_START_NUM + 1)*0x0c);}  \
}while(0);

#define DRV_PWM_WRITE_REG(channel,reg_type,val)  \
do{ \
	if(channel < PWM_2CH_START_NUM){  \
		DRV_PWM_WriteReg((PWM_CTRL + 0x04 * reg_type) + (channel - 1)*0x0c,val);}  \
	else if(channel >= PWM_3CH_START_NUM){   \
		DRV_PWM_WriteReg((PWM_CTRL_3CH + 0x04 * reg_type) + (channel - PWM_3CH_START_NUM)*0x0c,val);}  \
	else{  \
		DRV_PWM_WriteReg((PWM_CTRL_2CH + 0x04 * reg_type) + (channel - PWM_2CH_START_NUM + 1)*0x0c,val);}  \
}while(0);


#endif

#endif

typedef enum 
{
	pwmclk_1MHZ=0,
	pwmclk_2MHZ,
	pwmclk_4MHZ,
	pwmclk_8MHZ 
}PWMClock_DIV;

typedef enum 
{
	pwmclk_13M=0,
	pwmclk_32k
}PWMClock_SEL;

typedef enum 
{
	PWM1=0,
	PWM2,
	PWM3,
	PWM4
}PWM_TYPE;

#if !defined(DRV_PWM_DRV_TOOL_SUPPORT)
typedef void (*DCL_PWM_INIT)(void);
typedef void (*DCL_PWM_CLK_INIT)(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint32 clk_div);
typedef void (*DCL_PWM_START)(DCL_UINT8 owner, DCL_UINT32 pwm_num);
typedef void (*DCL_PWM_STOP)(DCL_UINT8 owner, DCL_UINT32 pwm_num);
typedef void (*DCL_PWM_CONFIG_OLD)(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint8 duty);
typedef DCL_UINT8 (*DCL_PWM_GETCURRENT_LEVEL)(DCL_UINT8 pwm_num);
typedef DCL_UINT32(*DCL_PWM_GETCURRENT_FREQ)(DCL_UINT8 pwm_num);
typedef DCL_UINT8 (*DCL_PWM_GETCURRENT_DUTY)(DCL_UINT8 pwm_num);

typedef struct
{
   DCL_PWM_INIT                  pwmInit;
   DCL_PWM_CLK_INIT              pwmClkInit;
   DCL_PWM_START                 pwmStart;
   DCL_PWM_STOP                  pwmStop;
   DCL_PWM_GETCURRENT_LEVEL      pwmGetCurrent_level;
   DCL_PWM_GETCURRENT_FREQ       pwmGetCurrent_Freq;
   DCL_PWM_GETCURRENT_DUTY       pwmGetCurrent_Duty;
   DCL_PWM_CONFIG_OLD            pwmConfigOld;
}PWMDriver_t;

extern void DCL_PWM_Init(void);
extern void DCL_PWM_SetClock(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint32 clk_div);
extern void DCL_PWM_Start(kal_uint8 owner, kal_uint32 pwm_num);
extern void DCL_PWM_Stop(kal_uint8 owner, kal_uint32 pwm_num);
extern void DCL_PWM_ConfigOld(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint8 duty);
extern kal_uint8 DCL_PWM_GetCurrent_Level(kal_uint8 pwm_num);
extern kal_uint8 DCL_PWM_GetCurrentDuty(kal_uint8 pwm_num);
extern kal_uint32 DCL_PWM_GetCurrentFreq(kal_uint8 pwm_num);

//added for 6250 RF-Desense
#if defined(DRV_PWM_AFFECT_RF) && defined(__MTK_TARGET__) && !defined(__UBL__)
	extern void Set_Level_of_backlight(kal_uint32 (*dstArray)[2]);
#endif

extern void PWM_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div);
extern void PWM1_Configure(kal_uint32 freq, kal_uint8 duty);
extern void PWM1_Start(void);
extern void PWM1_Stop(void);
extern kal_uint8  PWM1_GetCurrentLevel(void);
extern kal_uint8  PMW1_GetCurrentDuty(void);
extern kal_uint32 PMW1_GetCurrentFreq(void);
#if defined(DRV_PWM_PWM2)
   extern void PWM2_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div);
   extern void PWM2_Configure(kal_uint32 freq, kal_uint8 duty);
   extern void PWM2_Start(void);
   extern void PWM2_Stop(void);
   extern kal_uint8  PWM2_GetCurrentLevel(void);
   extern kal_uint8  PMW2_GetCurrentDuty(void);
   extern kal_uint32 PMW2_GetCurrentFreq(void);
#if defined(DRV_PWM_PWM3)
   extern void PWM3_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div);
   extern void PWM3_Configure(kal_uint32 freq, kal_uint8 duty);
   extern void PWM3_Start(void);
   extern void PWM3_Stop(void);
   extern kal_uint8  PWM3_GetCurrentLevel(void);
   extern kal_uint8  PMW3_GetCurrentDuty(void);
   extern kal_uint32 PMW3_GetCurrentFreq(void);
#if defined(__DRV_PMU53_SPEC_V2__)
extern void PWM3_Output_High(void);
#endif //#if defined(__DRV_PMU53_SPEC_V2__)
#if defined(DRV_PWM_PWM4)
   extern void PWM4_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div);
   extern void PWM4_Configure(kal_uint32 freq, kal_uint8 duty);
   extern void PWM4_Start(void);
   extern void PWM4_Stop(void);
   extern kal_uint8  PWM4_GetCurrentLevel(void);
   extern kal_uint8  PMW4_GetCurrentDuty(void);
   extern kal_uint32 PMW4_GetCurrentFreq(void);
#endif   /* DRV_PWM_PWM4 */

#endif   /* DRV_PWM_PWM3 */
#endif   /* DRV_PWM_PWM2 */
#else   //#if !defined(DRV_PWM_DRV_TOOL_SUPPORT)
typedef void (*DCL_PWM_INIT)(void);
typedef void (*DCL_PWM_CLK_INIT)(PWM_CHANNEL channel,PWMClock_SEL clk_sel,PWMClock_DIV Clock_div);
typedef void (*DCL_PWM_START)(PWM_CHANNEL channel);
typedef void (*DCL_PWM_STOP)(PWM_CHANNEL channel);
typedef void (*DCL_PWM_CONFIG_OLD)(kal_uint32 freq, kal_uint8 duty,PWM_CHANNEL channel);
typedef DCL_UINT8 (*DCL_PWM_GETCURRENT_LEVEL)(PWM_CHANNEL channel);
typedef DCL_UINT32(*DCL_PWM_GET_FREQ_BY_LEVEL)(PWM_CHANNEL channel,DCL_UINT8 pwm_level);
typedef DCL_UINT8 (*DCL_PWM_GET_DUTY_BY_LEVEL)(PWM_CHANNEL channel,DCL_UINT8 pwm_level);
typedef void (*DCL_PWM_SET_LEVEL)(PWM_CHANNEL channel,DCL_UINT8 pwm_level);
typedef void (*DCL_PWM_SET_DUTY_BY_LEVEL)(PWM_CHANNEL channel,DCL_UINT8 pwm_level,DCL_UINT8 duty);
typedef void (*DCL_PWM_SET_FREQ_BY_LEVEL)(PWM_CHANNEL channel,DCL_UINT8 pwm_level,DCL_UINT32 freq);
typedef void (*DCL_PWM_SET_ARRAY)(PWM_CHANNEL channel,kal_uint32 (*array)[2]);



typedef struct
{
   DCL_PWM_INIT                         pwmInit;
   DCL_PWM_CLK_INIT                     pwmClkInit;
   DCL_PWM_START                        pwmStart;
   DCL_PWM_STOP                         pwmStop;
   DCL_PWM_GETCURRENT_LEVEL             pwmGetCurrent_level;
   DCL_PWM_GET_FREQ_BY_LEVEL            pwmGet_Freq_by_level;
   DCL_PWM_GET_DUTY_BY_LEVEL            pwmGet_Duty_by_level;
   DCL_PWM_CONFIG_OLD                   pwmConfigOld;
   DCL_PWM_SET_LEVEL                    pwmSet_level;
   DCL_PWM_SET_DUTY_BY_LEVEL            pwmSet_duty_by_level;
   DCL_PWM_SET_FREQ_BY_LEVEL            pwmSet_freq_by_level;
   DCL_PWM_SET_ARRAY                    pwmSet_array;
}PWMDriver_t;
void DCL_PWM_Init();
kal_uint8 DCL_PWM_GetCurrent_Level(PWM_CHANNEL channel);
extern kal_uint8 DCL_PWM_GetCurrentDuty(PWM_CHANNEL channel);
extern kal_uint32 DCL_PWM_GetCurrentFreq(PWM_CHANNEL channel);
kal_uint32 DCL_PWM_GetFreq_by_level(PWM_CHANNEL channel,DCL_UINT8 pwm_level);
kal_uint8 DCL_PWM_GetDuty_by_level(PWM_CHANNEL channel,DCL_UINT8 pwm_level);
void PWM_Init(PWM_CHANNEL channel,PWMClock_SEL clk_sel,PWMClock_DIV Clock_div);
kal_uint16 PWM_read_register_by_channel(PWM_REGISTER register_addr,PWM_CHANNEL channel );
void PWM_write_register_by_channel(PWM_REGISTER register_addr,PWM_CHANNEL channel ,kal_uint16 value);
void PWM_Configure(kal_uint32 freq, kal_uint8 duty,PWM_CHANNEL channel);
void PWM_Start(PWM_CHANNEL channel);
void PWM_Stop(PWM_CHANNEL channel);
kal_uint32 Get_pwm_channel_by_device_index(kal_uint32 device_index);
void DCL_PWM_SetLevel(PWM_CHANNEL channel,DCL_UINT8 pwm_level);
void DCL_PWM_Setduty_by_level(PWM_CHANNEL channel,DCL_UINT8 pwm_level,DCL_UINT8 duty);
void DCL_PWM_SetArray(PWM_CHANNEL channel,kal_uint32 (*array)[2]);
void DCL_PWM_Setfreq_by_level(PWM_CHANNEL channel,DCL_UINT8 pwm_level,DCL_UINT32 freq);
#endif
#endif  /* !defined(DRV_PWM_RWG) */


#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_PWM_REG_DBG__)
#define DRV_PWM_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_PWM_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_PWM_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_PWM_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_PWM_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_PWM_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_PWM_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_PWM_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_PWM_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_PWM_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_PWM_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_PWM_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_PWM_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_PWM_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_PWM_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_PWM_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_PWM_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_PWM_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_PWM_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_PWM_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_PWM_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_PWM_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_PWM_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_PWM_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_PWM_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_PWM_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_PWM_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_PWM_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_PWM_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_PWM_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_PWM_REG_DBG__)
#endif

