/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 * Filename:
 * ---------
 *  fm_trc.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  trace map definition of FMR task.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/*****************************************************************************
 * Include
 *****************************************************************************/
#ifndef __FMR_TRC_H__
#define __FMR_TRC_H__

#include "stack_config.h"
#include "kal_trace.h"
#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before tst_config.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */


#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before tst_trace.h"
#endif

/* MOD_FMR trace definition */
#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "fmr_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_FMR)
    /* ----------------- TRACE_INFO trace class ------------------- */
    TRC_MSG( FM_INFO_FM_COMMON_POWER_ON, "FM Common Power On")
    TRC_MSG( FM_INFO_FM_POWER_ON_RST, "FM Power On reset")
    TRC_MSG( FM_INFO_FM_POWER_OFF, "FM Power Off")
    TRC_MSG( FM_INFO_FM_CHIP_ID, "FM Chip ID: %x\n")
    TRC_MSG( FM_INFO_FM_SET_FREQ, "FM set Freq: %d\n")
    TRC_MSG( FM_INFO_FM_IS_VALID_STOP, "FM is valid stop (freq: %d, signal lvl: %x, is_step_up: %x)\n")    
    TRC_MSG( FM_INFO_FM_HW_SEARCH_S, "FM HW Search start (Init Freq: %d, is_step_up: %x, space: %x, is_preset: %x)\n")    
    TRC_MSG( FM_INFO_FM_HW_SEARCH_E, "FM HW Search end(stay Freq: %d)\n")
    TRC_MSG( FM_INFO_FM_PAMD_LVL, "FM get PAMD (Freq: %d, PAMD LVL: %d)\n")
    TRC_MSG( FM_INFO_FM_RSSI_LVL, "FM get RSSI (Freq: %d, RSSI LVL: %d)\n")
    TRC_MSG( FM_INFO_FM_MR, "FM get MR: %d\n")
    TRC_MSG( FM_INFO_FM_ITEM_INFO, "FM EE Mode cmd (group: %x, item: %x, item_value: %x)\n")   
    TRC_MSG( FM_INFO_SeekEliminate, "seek eliminate freq=%d,Eliminate=%d,index=%d\n")   
    TRC_MSG( FM_INFO_SortTuneRssi, "sort tune channel=%d rssi=%d\n")   
    TRC_MSG( FM_INFO_EMPTY_NO, "Empty channel no=%d\n")   
    TRC_MSG( FM_INFO_READ_DATA, "Register [%x] =%x\n")  
    TRC_MSG( FM_INFO_TuneTimes, "setfreq: poll many times!\n")  
    TRC_MSG( FM_INFO_GetSoundTrack, "Get Sound Track=%d\n")  
    TRC_MSG( FM_INFO_GetRSSITH, "[%d]rssi threshold=%x\n")  
    TRC_MSG( FM_INFO_HEX2DB, "HEX=%x,DB=%d\n")  
    TRC_MSG( FM_INFO_DB2HEX, "DB=%d,HEX=%x\n")  
    TRC_MSG( FM_INFO_FM_CQI, "Freq: %d, CQI[%d],value: %d\n")
    TRC_MSG( FM_INFO_ROM_VERSION, "Rom_Reset_Version=%x,DSP_Code_Version=%x\n")  
    TRC_MSG( FM_INFO_PATCH_VERSION, "Download DSP patch Version=%x\n")  
    TRC_MSG( FM_INFO_SCAN_CQI, "Scan CQI:Para1=%d.Para2=%d,Para3=%x\n")
    TRC_MSG( FM_INFO_SOFT_MUTE_TUNE_CQI, "Freq:%d,RSSI=%d,PAMD=%d,ATDC=%d,MR=%d,PRX=%d,softmuteGain=%d,ATDEV:%d,Valid=%d\n")
    TRC_MSG( FM_INFO_DENSENSE_CHANNEL, "desense channel[%d] Severe=[%d]\n")
    TRC_MSG( FM_INFO_NOISE_FLOOR, "noise detected:Pacc[%d] Nacc[%d]\n")
    TRC_MSG( FM_INFO_NOISE_FLOOR_DETECT, "noise channel[%d]NF=[%d]\n")
    TRC_MSG( FM_INFO_SCAN_CHANNEL_NUM, "Channel[%d]=[%d]\n")
    TRC_MSG( FM_I2SIN_CheckDataValid_TIMEOUT, "I2SIN_CheckDataValid time out\n")  
    TRC_MSG( FM_I2SIN_CheckDataValid_ERROR, "I2SIN_CheckDataValid result: error\n")
    TRC_MSG( FM_INFO_SFI_VOLTAGE_UNKNOWN, "SFI voltage is not 1.8V or 3.0V\n")    
    TRC_MSG( FM_INFO_SFI_CLK_NOT104Mor78M, "SFI working frequency is not 78MHz or 104MHz\n")
    /* ----------------- TRACE_ERROR trace class ------------------ */
    /* ----------------- MENU entrance/exit class ------------------ */
	TRC_MSG(FM_API_ENTRANCE,"ENTRANCE:%d\n")
	TRC_MSG(FM_API_EXIT,"EXIT:%d\n")
	TRC_MSG(FMDRV_API_ENTRANCE,"ENTRANCE:%x\n")
	TRC_MSG(FMDRV_API_EXIT,"EXIT:%x\n")
	TRC_MSG(FM_ON_SEQUENCE_CMD,"power on cmd:%d\n")
	TRC_MSG(FM_OFF_SEQUENCE_CMD,"power off cmd:%d\n")
	TRC_MSG(FM_ON_POLLING_TIMES,"power on polling 1000 times==%d\n")
	TRC_MSG(FM_READ_DATA,"--read reg[%x]=[%x]--\n")
	TRC_MSG(FM_WRITE_DATA,"--write reg[%x]-- [%x]--\n")
	TRC_MSG(FM_SET_OutputDevice,"Output devide:[%d]\n")
	TRC_MSG(FM_SET_OutputVolume,"Output volume:[%d] digital gain:[%d]\n")
	TRC_MSG(FM_SET_ANTENNAY_TYPE,"set antenna type =[%x]\n")
	TRC_MSG(FM_GET_ANTENNAY_TYPE,"Get antenna type =[%x]\n")
	TRC_MSG(FM_RDS_INTR_ONOFF,"RDS INTR on_off:[%d]\n")
	TRC_MSG(FM_INTR_VALUE,"FM interrupt value=[%x]\n")
	TRC_MSG(FM_MUTE_ONOFF,"FM mute:[%d]\n")
	TRC_MSG(FM_SOFTE_MUTE_ONOFF,"FM softer mute:[%d]\n")
	TRC_MSG(FM_DELAYMS,"FM delay [%d]ms\n")
	
	/* ----------------- TRACE_RDS trace class ------------------ */
    TRC_MSG( FM_INFO_FM_RDS_EINT, "FM RDS Interrupt is coming!\n")
    TRC_MSG( FM_INFO_FM_RDS_CLR, "FM RDS EINT unmask and clear Intr\n")
    TRC_MSG( FM_INFO_FM_RDS_EVENT, "FM RDS EVNT (event:%x, flag:%x)\n")
    TRC_MSG( FM_INFO_FM_RDS_BLER_ERR, "FM RDS BLER (total cnt:%d, bad bler ratio:%d)\n")
    TRC_MSG( FM_INFO_FM_RDS_BLK_RST, "FM RDS BLOCK RST (reset cnt:%x)\n")
    TRC_MSG( FM_INFO_FM_RDS_BLOCK_DATA, "FM RDS BLOCK (%04x, %04x, %04x, %04x, %04x)\n")
    TRC_MSG( FM_INFO_FM_RDS_GROUP, "FM RDS GROUP (group: %x, subtype:%x)\n")
    TRC_MSG( FM_INFO_FM_RDS_PS_TBL, "FM RDS PS Table Num: %x\n")
    TRC_MSG( FM_INFO_FM_RDS_PS_DATA, "FM RDS PS Data (Num: %x, PS:%x)\n")
    TRC_MSG( FM_INFO_FM_RDS_PS_BUFF0, "FM RDS PS Data update to buff0\n")    
    TRC_MSG( FM_INFO_FM_RDS_PS_BUFF1, "FM RDS PS Data update to buff1\n")
    TRC_MSG( FM_INFO_FM_RDS_PS_BUFF_FULL, "FM RDS PS buff%x data (%x, %x, %x, %x, %x, %x, %x, %x)\n")
    TRC_MSG( FM_INFO_FM_RDS_PS_CANNCEL, "FM RDS PS data NULL, event is cannceled\n")
    TRC_MSG( FM_INFO_FM_RDS_RT_TBL, "FM RDS RT Table Num: %x\n")
    TRC_MSG( FM_INFO_FM_RDS_RT_DATA, "FM RDS RT Data (Num: %x, RT0:%x, RT1:%x)\n")
    TRC_MSG( FM_INFO_FM_RDS_RT_BUFF1, "FM RDS RT Data update to buff1[%x]\n")
    TRC_MSG( FM_INFO_FM_RDS_RT_BUFF2, "FM RDS RT Data update to buff2[%x]\n")
    TRC_MSG( FM_INFO_FM_RDS_RT_LEN, "FM RDS RT LEN: Cnt:%x Length:%x Mask:%x\n")
    TRC_MSG( FM_INFO_FM_RDS_AF_SET, "FM RDS AF scan(method:%x, freq:%x\n")
    TRC_MSG( FM_INFO_FM_RDS_AF_PAMD, "FM RDS AF PAMD(Freq:%x, Index:%x, PAMD_LVL:%x\n")
    TRC_MSG( FM_INFO_FM_RDS_AF_SWITCH, "FM RDS AF channel switch:%x\n")    
    TRC_MSG( FM_INFO_FM_RDS_AF_BUFF_FULL, "FM RDS AF buff%x data (%x, %x, %x, %x, %x, %x, %x, %x)\n") 
    TRC_MSG( FM_INFO_FM_RDS_PS_STATUS, "event_status=%x, PS_Num=%x, Addr_Cnt=%x\n")
    TRC_MSG( FM_INFO_FM_RDS_PS1_STATUS, "PS[0][%x-%x-%x-%x-%x-%x-%x-%x] \n")
    TRC_MSG( FM_INFO_FM_RDS_PS2_STATUS, "PS[1][%x-%x-%x-%x-%x-%x-%x-%x]\n")
    TRC_MSG( FM_INFO_FM_RDS_GET_PS_NAME, "get PS name: %x-%x-%x-%x-%x-%x-%x-%x\n")
    TRC_MSG( FM_INFO_FM_RDS_BLOCK_CNT, "[%d]blcok cnt = [%d]\n")
    TRC_MSG( FM_INFO_FM_RDS_EVENT_STATUS, "Event 1: flag=[%x] buffer= [%x]\n")
    TRC_MSG( FM_INFO_FM_RDS_EVENT_INFO, "RDS get info[%d]\n")
    
END_TRACE_MAP(MOD_FMR)
#endif /* __WMT_TRC_H__*/
