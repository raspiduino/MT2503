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
 *    accdet_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for accessory detector driver and adaption.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
  * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef ACCDET_SW_H
#define ACCDET_SW_H

#include "drv_comm.h"
#include "kal_general_types.h"
#include "drvsignals.h"

typedef enum {
	accdet_plugged = 0,
	accdet_not_plugged,
	accdet_mic,
	accdet_switched,
	accdet_check_tv,
	accdet_tv_out
} accdet_status;

typedef enum {
	accdet_cmp,
	accdet_vth,
	accdet_mbias
} accdet_pwm_set;

typedef enum {
	accdet_state00,
	accdet_state01,
	accdet_state10,
	accdet_state11
} accdet_pwm_debs;

typedef struct {
   kal_uint32 hook_debounce;
   kal_uint32 mic_debounce;  // switch to mic (plug-in) state
   kal_uint32 plugOut_debounce;
   kal_uint32 pwm_delay;
   kal_uint32 cmp_width;
   kal_uint32 cmp_threshold;
   kal_uint32 vth_width;
   kal_uint32 vth_threshold;
   kal_uint32 mbias_width;
   kal_uint32 mbias_threshold;
} AccDet_config_data_struct;

typedef struct {
	accdet_status nextState;
	AUX_ID msg;
	kal_uint8 regValue;
	kal_uint8 debounceIdx;
} AccDet_Actions;

typedef enum {
	SWITCHED_EAR,
	SWITCHED_KEY,
	MIC_EAR,
	MIC_NULL,
	//TVOUT_NULL,
	NOTPLUGGED_PLUGOUT,
	NOACT
} AccDet_ActionIdxs;


typedef enum 
{
   AUX_STATUS_ORG=0,
   AUX_STATUS_TIMER1_TIMEOUT,
   AUX_STATUS_TIMER0_TIMEOUT,
   AUX_STATUS_MAX
}AUX_POLLING_STATUS;

void ACCDET_read_write_test(void);
void ACCDET_register_test(kal_uint32 reg, kal_uint32 max);
void ACCDET_init(void);
void ACCDET_reset(void);

void ACCDET_SetPWM(kal_uint16 pwmSet, kal_uint16 width, kal_uint16 thresh);
void ACCDET_SetDebounce(accdet_pwm_debs state, kal_uint16 debounce);
void ACCDET_LISR(void);
extern kal_bool ACCDET_Is_Earphone_With_MIC(void);


#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_ACCDET_REG_DBG__)
#define DRV_ACCDET_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_ACCDET_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_ACCDET_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_ACCDET_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_ACCDET_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_ACCDET_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_ACCDET_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_ACCDET_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_ACCDET_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_ACCDET_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_ACCDET_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_ACCDET_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_ACCDET_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_ACCDET_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_ACCDET_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_ACCDET_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_ACCDET_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_ACCDET_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_ACCDET_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_ACCDET_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_ACCDET_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_ACCDET_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_ACCDET_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_ACCDET_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_ACCDET_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_ACCDET_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_ACCDET_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_ACCDET_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_ACCDET_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_ACCDET_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_ACCDET_REG_DBG__)

#endif//#define ACCDET_SW_H
