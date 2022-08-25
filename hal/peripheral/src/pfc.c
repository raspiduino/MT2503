/*******************************************************************************************************************
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
*******************************************************************************************************************/

/*******************************************************************************************************************
 *
 * Filename:
 * ---------
 *   pfc.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  This Module is point-to-point protocol framer coprocessor driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *      HISTORY
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

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ******************************************************************************************************************/
// Include Headers
#include "drv_comm.h"
#include "drvpdn.h"
#include "us_timer.h"               /* For ust_get_current_time() API*/

#include "drv_trc.h"
#include "cache_sw.h"

#if defined(__HW_PFC_SUPPORT__)

#include "pfc_hw.h"
#include "pfc_sw.h"

#if !defined(DRV_PFC_POLLING)
#include "intrCtrl.h"
#include "drv_hisr.h"
kal_eventgrpid PFC_Event;
#endif

#include "sync_data.h"

/*add by RHR suggest Add*/
#include "kal_release.h"
#include "reg_base.h"
#include "kal_trace.h"
#include "l1_interface.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
/*add by RHR suggest Add*/

#if defined(__TST_TRACE_ENABLED__) || defined(__TST_CRITICAL_TRACE_ENABLED__)    
extern kal_bool tst_check_mod_filter(module_type mod_id);
#endif

kal_bool PFC_wait_decode[MAX_LINK_COUNT] = {KAL_FALSE};    
#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
kal_uint8   PFC_decode_saddr[MAX_LINK_COUNT][SADDR_SIZE];
#pragma arm section zidata, rwdata

#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
static kal_uint8 pfc_sm_handle;
#endif // #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)

#define PFC_WAIT_STATE_COUNT_THRESHOLD  1000
PFC_register_struct pfc_debug;

//==================================================================================================================
/*
* FUNCTION                 
* PFC_SetSDRate
*
* DESCRIPTION                  
*    PFC set slow down rate
*
* CALLS  
* This function is called when setting slow down rate
*
* PARAMETERS
* value -- 4 times cycles delay for each bus access (read/write),
*   range from 0-255
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_SetSDRate(kal_uint16 value)
{
    DRV_PFC_WriteReg32(PFC_SDRAT, value);
    drv_trace2(TRACE_GROUP_10, PPP_SDRAT_MSG, PFC_SDRAT, value);
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_ReadStat
*
* DESCRIPTION                  
*    PFC read back current status
*
* CALLS  
* This function is called when want to know current status of PFC
*
* PARAMETERS
* enable -- enable or disable interrupt
*   
* RETURNS
* PFC current status value
*
* GLOBALS AFFECTED
* external_global
*/
kal_uint16 PFC_ReadStatus()
{
    kal_uint16 stat;
    
    stat = DRV_PFC_Reg32(PFC_STAT);
    drv_trace2(TRACE_GROUP_10, PPP_STAT_MSG, PFC_STAT, stat);
    return stat;
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_SetIntEn
*
* DESCRIPTION                  
*    PFC set interrupt enable/disable
*
* CALLS  
* This function is called when enable/disable interrupt
*
* PARAMETERS
* enable -- enable or disable interrupt
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_SetIntEn(kal_uint16 enable)
{
    DRV_PFC_WriteReg32(PFC_INTEN, enable);
    drv_trace2(TRACE_GROUP_10, PPP_INTEN_MSG, PFC_INTEN, enable);
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_SetDESTaddr
*
* DESCRIPTION                  
*    PFC set destination buffer address
*
* CALLS  
* This function is called when set destination buffer address for PFC
*
* PARAMETERS
* addr -- destination buffer address
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_SetDESTaddr(kal_uint32 addr)
{
    DRV_PFC_WriteReg32(PFC_DES, addr);
    drv_trace2(TRACE_GROUP_10, PPP_DES_MSG, PFC_DES, addr);
}


//==================================================================================================================
/*
* FUNCTION                 
* PFC_SetSRCaddr
*
* DESCRIPTION                  
*    PFC set source buffer address
*
* CALLS  
* This function is called when set source buffer address for PFC
*
* PARAMETERS
* addr -- source buffer address
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_SetSRCaddr(kal_uint32 addr)
{
    DRV_PFC_WriteReg32(PFC_SRC, addr);
    drv_trace2(TRACE_GROUP_10, PPP_SRC_MSG, PFC_SRC, addr);
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_ReadDESTaddr
*
* DESCRIPTION                  
*    PFC Read destination buffer address
*
* CALLS  
* This function is called when Read destination address for PFC
*
* PARAMETERS
* None
*   
* RETURNS
* destination buffer address
*
* GLOBALS AFFECTED
* external_global
*/
kal_uint32 PFC_ReadDESTaddr(void)
{
    kal_uint32 addr;
    
    addr = DRV_PFC_Reg32(PFC_DES);
    drv_trace2(TRACE_GROUP_10, PPP_DES_MSG, PFC_DES, addr);
    return addr;
}


//==================================================================================================================
/*
* FUNCTION                 
* PFC_ReadSRCaddr
*
* DESCRIPTION                  
*    PFC Read source buffer address
*
* CALLS  
* This function is called when Read source buffer address for PFC
*
* PARAMETERS
* None
*   
* RETURNS
* source buffer address
*
* GLOBALS AFFECTED
* external_global
*/
kal_uint32 PFC_ReadSRCaddr(void)
{
    kal_uint32 addr;
    
    addr = DRV_PFC_Reg32(PFC_SRC);
    drv_trace2(TRACE_GROUP_10, PPP_SRC_MSG, PFC_SRC, addr);
    return addr;
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_SetDESTlen
*
* DESCRIPTION                  
*    PFC set destination buffer length
*
* CALLS  
* This function is called when set destination buffer length for PFC
*
* PARAMETERS
* len -- destination buffer length
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_SetDESTlen(kal_uint16 len)
{
    DRV_PFC_WriteReg32(PFC_UDLEN, len);
    drv_trace2(TRACE_GROUP_10, PPP_UDLEN_MSG, PFC_UDLEN, len);
}


//==================================================================================================================
/*
* FUNCTION                 
* PFC_SetSRClen
*
* DESCRIPTION                  
*    PFC set source buffer length
*
* CALLS  
* This function is called when set source buffer length for PFC
*
* PARAMETERS
* len -- source buffer length
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_SetSRClen(kal_uint16 len)
{
    DRV_PFC_WriteReg32(PFC_USLEN, len);
    drv_trace2(TRACE_GROUP_10, PPP_USLEN_MSG, PFC_USLEN, len);
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_UnuseDESTlen
*
* DESCRIPTION                  
*    PFC Read destination buffer length
*
* CALLS  
* This function is called when Read destination buffer length for PFC
*
* PARAMETERS
* None
*   
* RETURNS
* destination buffer length
*
* GLOBALS AFFECTED
* external_global
*/
kal_uint16 PFC_UnuseDESTlen(void)
{
    kal_uint16 len;
    
    len = DRV_PFC_Reg32(PFC_UDLEN);
    drv_trace2(TRACE_GROUP_10, PPP_UDLEN_MSG, PFC_UDLEN, len);
    return len;
}


//==================================================================================================================
/*
* FUNCTION                 
* PFC_UnreadSRClen
*
* DESCRIPTION                  
*    PFC Read source buffer length
*
* CALLS  
* This function is called when Read source buffer length for PFC
*
* PARAMETERS
* None
*   
* RETURNS
* source buffer length
*
* GLOBALS AFFECTED
* external_global
*/
kal_uint16 PFC_UnreadSRClen(void)
{
    kal_uint16 len;
    
    len = DRV_PFC_Reg32(PFC_USLEN);
    drv_trace2(TRACE_GROUP_10, PPP_USLEN_MSG, PFC_USLEN, len);
    return len;
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_SetBufferInfo
*
* DESCRIPTION                  
*    PFC set src/dest buffer information
*
* CALLS  
* This function is called when set src/dest buffer information for PFC
*
* PARAMETERS
* buffer information
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
kal_bool PFC_SetBufferInfo( PFC_buffer_struct * buf)
{
    kal_uint16 stat;
    
    stat = DRV_PFC_Reg32(PFC_STAT);
    if( stat == PFC_OK)
    {
        DRV_PFC_WriteReg32(PFC_SRC, buf->src_adrs);
        DRV_PFC_WriteReg32(PFC_USLEN, buf->src_len);
        DRV_PFC_WriteReg32(PFC_DES, buf->dest_adrs);
        DRV_PFC_WriteReg32(PFC_UDLEN, buf->dest_len);
        drv_trace2(TRACE_GROUP_10, PPP_SRC_MSG, PFC_SRC, (kal_uint32)buf->src_adrs);
        drv_trace2(TRACE_GROUP_10, PPP_USLEN_MSG, PFC_USLEN, buf->src_len);
        drv_trace2(TRACE_GROUP_10, PPP_DES_MSG, PFC_DES, (kal_uint32)buf->dest_adrs);
        drv_trace2(TRACE_GROUP_10, PPP_UDLEN_MSG, PFC_UDLEN, buf->dest_len);
    }
    return KAL_TRUE;
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_ReadBufferInfo
*
* DESCRIPTION                  
*    PFC Read src/dest buffer information
*
* CALLS  
* This function is called when Read src/dest buffer information for PFC
*
* PARAMETERS
* None
*   
* RETURNS
* buffer information
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_ReadBufferInfo( PFC_buffer_struct * buf)
{
    buf->src_adrs  = (kal_uint32 *)DRV_PFC_Reg32(PFC_SRC);
    buf->src_len   = DRV_PFC_Reg32(PFC_USLEN);
    buf->dest_adrs = (kal_uint32 *)DRV_PFC_Reg32(PFC_DES);
    buf->dest_len  = DRV_PFC_Reg32(PFC_UDLEN);
    drv_trace2(TRACE_GROUP_10, PPP_SRC_MSG, PFC_SRC, (kal_uint32)buf->src_adrs);
    drv_trace2(TRACE_GROUP_10, PPP_USLEN_MSG, PFC_USLEN, buf->src_len);
    drv_trace2(TRACE_GROUP_10, PPP_DES_MSG, PFC_DES, (kal_uint32)buf->dest_adrs);
    drv_trace2(TRACE_GROUP_10, PPP_UDLEN_MSG, PFC_UDLEN, buf->dest_len);
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_ReadAllRegister
*
* DESCRIPTION                  
*    PFC Read all registers
*
* CALLS  
* This function is called when Read all registers
*
* PARAMETERS
* None
*   
* RETURNS
* buffer information
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_ReadAllRegister( PFC_register_struct * reg)
{
    reg->start = (kal_uint32)DRV_PFC_Reg32(PFC_START);
    reg->control = (kal_uint32)DRV_PFC_Reg32(PFC_CON);
    reg->protocol = (kal_uint32)DRV_PFC_Reg32(PFC_PTC);
    reg->stateAddress = (kal_uint32)DRV_PFC_Reg32(PFC_SADDR);
    reg->src_adrs = (kal_uint32)DRV_PFC_Reg32(PFC_SRC);
    reg->src_len = (kal_uint32)DRV_PFC_Reg32(PFC_USLEN);
    reg->dest_adrs = (kal_uint32)DRV_PFC_Reg32(PFC_DES);
    reg->dest_len = (kal_uint32)DRV_PFC_Reg32(PFC_UDLEN);
    reg->interruptEn = (kal_uint32)DRV_PFC_Reg32(PFC_INTEN);
    reg->status = (kal_uint32)DRV_PFC_Reg32(PFC_STAT);
    reg->slowDownRate = (kal_uint32)DRV_PFC_Reg32(PFC_SDRAT);
    reg->accm0 = (kal_uint32)DRV_PFC_Reg32(PFC_ACCM0);
    reg->accm1 = (kal_uint32)DRV_PFC_Reg32(PFC_ACCM1);
    reg->accm2 = (kal_uint32)DRV_PFC_Reg32(PFC_ACCM2);
    reg->accm3 = (kal_uint32)DRV_PFC_Reg32(PFC_ACCM3);
    reg->accm4 = (kal_uint32)DRV_PFC_Reg32(PFC_ACCM4);
    reg->accm5 = (kal_uint32)DRV_PFC_Reg32(PFC_ACCM5);
    reg->accm6 = (kal_uint32)DRV_PFC_Reg32(PFC_ACCM6);
    drv_trace2(TRACE_GROUP_10, PPP_START_MSG, PFC_START, reg->start);
    drv_trace2(TRACE_GROUP_10, PPP_CON_MSG, PFC_CON, reg->control);
    drv_trace2(TRACE_GROUP_10, PPP_PTC_MSG, PFC_PTC, reg->protocol);
    drv_trace2(TRACE_GROUP_10, PPP_SADDR_MSG, PFC_SADDR, reg->stateAddress);
    drv_trace2(TRACE_GROUP_10, PPP_SRC_MSG, PFC_SRC, reg->src_adrs);
    drv_trace2(TRACE_GROUP_10, PPP_USLEN_MSG, PFC_USLEN, reg->src_len);
    drv_trace2(TRACE_GROUP_10, PPP_DES_MSG, PFC_DES, reg->dest_adrs);
    drv_trace2(TRACE_GROUP_10, PPP_UDLEN_MSG, PFC_UDLEN, reg->dest_len);
    drv_trace2(TRACE_GROUP_10, PPP_INTEN_MSG, PFC_INTEN, reg->interruptEn);
    drv_trace2(TRACE_GROUP_10, PPP_STAT_MSG, PFC_STAT, reg->status);
    drv_trace2(TRACE_GROUP_10, PPP_SDRAT_MSG, PFC_SDRAT, reg->slowDownRate);
    drv_trace2(TRACE_GROUP_10, PPP_ACCM0_MSG, PFC_ACCM0, reg->accm0);
    drv_trace2(TRACE_GROUP_10, PPP_ACCM1_MSG, PFC_ACCM1, reg->accm1);
    drv_trace2(TRACE_GROUP_10, PPP_ACCM2_MSG, PFC_ACCM2, reg->accm2);
    drv_trace2(TRACE_GROUP_10, PPP_ACCM3_MSG, PFC_ACCM3, reg->accm3);
    drv_trace2(TRACE_GROUP_10, PPP_ACCM4_MSG, PFC_ACCM4, reg->accm4);
    drv_trace2(TRACE_GROUP_10, PPP_ACCM5_MSG, PFC_ACCM5, reg->accm5);
    drv_trace2(TRACE_GROUP_10, PPP_ACCM6_MSG, PFC_ACCM6, reg->accm6);
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_ReadACCM
*
* DESCRIPTION                  
*    PFC Read ACCM
*
* CALLS  
* This function is called when want to read back accm value
*
* PARAMETERS
* part -- value from 0 to 6, indicate want to read which ACCM *  
*   
* RETURNS
* kal_uint32 ACCM value
*
* GLOBALS AFFECTED
* external_global
*/
kal_uint32 PFC_ReadACCM(kal_uint16 part)
{
    kal_uint32 value;
    
    value = DRV_PFC_Reg32(PFC_ACCM0 + 0x4 * part);
    drv_trace2(TRACE_GROUP_10, PPP_ACCM_MSG, PFC_ACCM0 + 0x4 * part, value);
    return value;
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_WriteACCM
*
* DESCRIPTION                  
*    PFC Write ACCM
*
* CALLS  
* This function is called when want to write accm value
*
* PARAMETERS
* part -- value from 0 to 6, indicate want to write which ACCM 
*  value - ACCM value.
*   
* RETURNS
* void
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_WriteACCM(kal_uint16 part, kal_uint32 value)
{
    DRV_PFC_WriteReg32(PFC_ACCM0 + 0x4 * part, value);
    drv_trace2(TRACE_GROUP_10, PPP_ACCM_MSG, PFC_ACCM0 + 0x4 * part, value);
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_SetSAddr
*
* DESCRIPTION                  
*    PFC set state address
*
* CALLS  
* This function is called when setting state address
*
* PARAMETERS
* saddr -- state address
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_SetSAddr(kal_uint16 saddr)
{
    DRV_PFC_WriteReg32(PFC_SADDR, saddr);
    drv_trace2(TRACE_GROUP_10, PPP_SADDR_MSG, PFC_SADDR, saddr);
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_SetProtocol
*
* DESCRIPTION                  
*    PFC set protocol field
*
* CALLS  
* This function is called when setting protocol field
*
* PARAMETERS
* protocol -- protocol value
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_SetProtocol(kal_uint16 protocol)
{
    DRV_PFC_WriteReg32(PFC_PTC, protocol);
    drv_trace2(TRACE_GROUP_10, PPP_PTC_MSG, PFC_PTC, protocol);
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_Control
*
* DESCRIPTION                  
*    PFC set control value
*
* CALLS  
* This function is called when set control register
*
* PARAMETERS
* control -- which control item need to be set
*  enable  -- enable/disable the control item
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_Control( PFC_ControlItem  ctrl, kal_bool  enable)
{
    kal_uint32 value;
    
    value = DRV_PFC_Reg32(PFC_CON);
    
    if( enable)
    {
        DRV_PFC_WriteReg32(PFC_CON, value | ( 1<<ctrl));
        drv_trace2(TRACE_GROUP_10, PPP_CON_MSG, PFC_CON, value | ( 1<<ctrl));
    }
    else
    {
        DRV_PFC_WriteReg32(PFC_CON, value & ( ~( 1<<ctrl)));
        drv_trace2(TRACE_GROUP_10, PPP_CON_MSG, PFC_CON, value & ( ~( 1<<ctrl)));
    }
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_ReadState
*
* DESCRIPTION                  
*    PFC read out the state within PFC module
*
* CALLS  
* This function is called when read the state during change decode/encode
*
* PARAMETERS
* None
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_ReadState(kal_uint8 * state)
{

}
//==================================================================================================================
/*
* FUNCTION                 
* PFC_WriteState
*
* DESCRIPTION                  
*    PFC write saved state into PFC module
*
* CALLS  
* This function is called when write the state during change decode/encode
*
* PARAMETERS
* None
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_WriteState(kal_uint8 * state)
{
}

#ifdef __PPP_HW_TESTING_BY_SW__ // not turn on this option on all project, only use this option when DVT?
void pfc_print_destination_buffer(kal_uint8 * buff_ptr, kal_uint16 buff_size, kal_uint16 how_many_bytes_print_in_one_run)
{
    ASSERT(buff_size < 20000); // just make sure nothing goes wrong, in normal case, the variable should be several thousands 

    kal_trace(TRACE_WARNING, PPP_PFC_PRINTED_BUFFER_ADDRESS, buff_ptr);

    while(buff_size > 0)
    {
        kal_uint16 print_how_many_bytes_in_this_run;
        if(buff_size >= how_many_bytes_print_in_one_run)
        {
            print_how_many_bytes_in_this_run = how_many_bytes_print_in_one_run;
            buff_size -= how_many_bytes_print_in_one_run;
        }
        else
        {
            print_how_many_bytes_in_this_run = buff_size;
            buff_size = 0;
        }

        kal_buffer_trace(TRACE_WARNING, PPP_KAL_BUFF_TRACE_PFC_DESTINATION_BUFF_PRINT, print_how_many_bytes_in_this_run, buff_ptr);
        buff_ptr += print_how_many_bytes_in_this_run;
    }

}
#endif // ~ ifdef __PPP_HW_TESTING_BY_SW__ // not turn on this option on all project, only use this option when DVT?
//==================================================================================================================
/*
* FUNCTION                 
* PFC_Decode
*
* DESCRIPTION                  
*    PFC ppp framer decode 
*
* CALLS  
* This function is called when use PFC to decode ppp framer
*
* PARAMETERS
* None
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
/************
在做simulation時  我們發現SW decode會output FCS到dest buffer上  但hw則不會
需要請你注意在design Driver code時
在decode成功一個frame之後  要無條件把decode dest buffer length +2 (不需要真的算出FCS填上去)
這樣才能保持PPP SW處理的一致性
************/
kal_uint32 PFC_wait_stat_count = 0;

kal_bool PFC_Decode( 
	pfc_buff_head_struct * dest, 
	pfc_buff_head_struct * src, 
    pfc_ahdlc_state_struct * state, 
	pfc_error_cause_enum * rcv_AT_CMD_OR_ESCAPE)
{
	kal_bool ret_val = KAL_FALSE;
	kal_bool is_log_enabled;
	volatile kal_uint16 stat;
	kal_uint32 decodeAPITick = 0, decodeAPIDuration = 0, decodeHWTick = 0, decodeHWDuration = 0;
	kal_uint32 decodeAPIUst = 0, decodeAPIUst2 = 0, decodeHWUst = 0, decodeHWUst2 = 0; //ust_get_current_time

#if !defined(DRV_PFC_POLLING)
   	kal_uint32 event_group;
#endif
 
   	kal_bool PFC_decode_fail = KAL_FALSE;

    kal_uint16 * o_len = (kal_uint16 *)& (dest->used);  /* < output length >         */
    kal_uint16 i_len = src->end_ptr - src->cur_ptr;        /* < input length >         */
    
    kal_uint8  * scp;
    kal_uint8  * op;
    kal_uint8  * ecp;
    kal_uint8  * scp_temp;

    /* Check if log is enabled. */
#if defined(__TST_TRACE_ENABLED__) || defined(__TST_CRITICAL_TRACE_ENABLED__)    
    is_log_enabled = tst_check_mod_filter (MOD_PPP);
#else
    is_log_enabled = KAL_FALSE;
#endif

    if (is_log_enabled)
    {
    	decodeAPITick = drv_get_current_time();
    	decodeAPIUst = ust_get_current_time();
	}

    scp = (kal_uint8 *)src->cur_ptr;
    ecp   = (kal_uint8 *)src->end_ptr;
    op = (kal_uint8 *)dest->end_ptr;

    if (INT_QueryIsCachedRAM(src->cur_ptr, (kal_uint32)(i_len*sizeof(kal_uint8))) ||
	    INT_QueryIsCachedRAM(dest->data_ptr, (kal_uint32)((dest->size)*sizeof(kal_uint8)))) 
    {
		EXT_ASSERT((kal_uint32)src->cur_ptr, i_len, (kal_uint32)dest->data_ptr, dest->size);
    }

    if( NULL != rcv_AT_CMD_OR_ESCAPE)
    {
    	*rcv_AT_CMD_OR_ESCAPE = PFC_PPPE_NONE;      /*   [MONZA00008185]         */
    }
  
    if(i_len == 0)
    {
        drv_trace4(TRACE_GROUP_2, PPP_DECODE_PARA_ERROR_MSG, (kal_uint32)scp, (kal_uint32)i_len, (kal_uint32)op, dest->used);
        src->cur_ptr = src->end_ptr = src->data_ptr;
        src->used = 0;
        /* The destination will be used next time */
        // dest->end_ptr = op; 
        // dest->used = *o_len;
        return KAL_FALSE;
    }
    
    if(( scp == NULL) || ( op == NULL))
    {
        drv_trace4(TRACE_GROUP_2, PPP_DECODE_PARA_ERROR_MSG, (kal_uint32)scp, (kal_uint32)i_len, (kal_uint32)op, dest->used);
        return KAL_FALSE;
    }

    if (is_log_enabled)
    {
        drv_trace4(TRACE_GROUP_2, PPP_DECODE_PARA_MSG, (kal_uint32)scp, (kal_uint32)ecp, (kal_uint32)op, dest->used);
        drv_trace4(TRACE_GROUP_2, PPP_DECODE_PARA_MSG, 0,0, (kal_uint32)dest->data_ptr, 0);
        drv_trace2(TRACE_GROUP_10, PPP_START_MSG, PFC_START, PFC_CLR);
	}

   	PDN_CLR(PDN_PFC);
    DRV_PFC_WriteReg32(PFC_START, PFC_CLR); /*   reset PFC states and        */

#if defined(MTK_SLEEP_ENABLE )  &&  ! defined(__FUE__ )
   	L1SM_UnIRQSleepDisable(pfc_sm_handle);
#endif

    /* This is add for ATH. detection */
    if(*o_len == 0) 
    {
        scp_temp = scp;
        
        if( ( i_len < 5) && ( i_len > 1))
        {
            // [MONZA00008185] change begin
            for (;scp_temp < ecp; scp_temp++) 
            {
            	if( NULL != rcv_AT_CMD_OR_ESCAPE)
            	{
            		if( ( scp_temp[ 0 ] == 'A') && ( scp_temp[ 1 ] == 'T'))
            		{
            			*rcv_AT_CMD_OR_ESCAPE = PFC_PPPE_PPP_DETECT_AT_CMD_DURING_DIALUP;
            			drv_trace0(TRACE_GROUP_2, PPP_DECODE_AT_ERROR_MSG);
            		}

            		if( ( scp_temp[ 0 ] == '+') && ( scp_temp[ 1 ] == '+'))
            		{
            			*rcv_AT_CMD_OR_ESCAPE = PFC_PPPE_PPP_DETECT_ESCAPE_DURING_DIALUP;
            			drv_trace0(TRACE_GROUP_2, PPP_DECODE_ESC_ERROR_MSG);
            		}
            	}//if( NULL != rcv_AT_CMD_OR_ESCAPE) 
         	}//for (;scp < ecp; scp++) 
      	}//if( i_len < 5)
   	}//if(*o_len == 0) 

    DRV_PFC_WriteReg32(PFC_START, PFC_CLR); // clear
    DRV_PFC_WriteReg32(PFC_SRC, scp);
    DRV_PFC_WriteReg32(PFC_USLEN, i_len);
    DRV_PFC_WriteReg32(PFC_DES, op);
    DRV_PFC_WriteReg32(PFC_UDLEN, dest->size - dest->used);
    DRV_PFC_WriteReg32(PFC_PTC, src->protocol);
    DRV_PFC_WriteReg32(PFC_SADDR, PFC_decode_saddr[state->context_id]);
    PFC_WriteACCM(0, state->raccm);

    if (is_log_enabled)
    {
        drv_trace2(TRACE_GROUP_10, PPP_START_MSG, PFC_START, PFC_CLR);
        drv_trace2(TRACE_GROUP_10, PPP_SRC_MSG, PFC_SRC, (kal_uint32)scp);
        drv_trace2(TRACE_GROUP_10, PPP_USLEN_MSG, PFC_USLEN, i_len);
        drv_trace2(TRACE_GROUP_10, PPP_DES_MSG, PFC_DES, (kal_uint32)op);
        drv_trace2(TRACE_GROUP_10, PPP_UDLEN_MSG, PFC_UDLEN, dest->size - dest->used);
        drv_trace2(TRACE_GROUP_10, PPP_PTC_MSG, PFC_PTC, src->protocol);
        drv_trace2(TRACE_GROUP_10, PPP_SADDR_MSG, PFC_SADDR, (kal_uint32)PFC_decode_saddr[state->context_id]);
        drv_trace2(TRACE_GROUP_10, PPP_ACCM_MSG, PFC_ACCM0, state->raccm);
	}

	Data_Sync_Barrier(); // For ARM11

    if(PFC_wait_decode[state->context_id])
    {
        PFC_wait_decode[state->context_id] = KAL_FALSE;

        if (is_log_enabled)
        { 
        	drv_trace2(
				TRACE_GROUP_10, 
				PPP_START_MSG, 
				PFC_START, 
				PFC_M_SRC | PFC_M_SL |PFC_M_DES | PFC_M_DL | PFC_RSTAT |  PFC_WSTAT | PFC_DSET7E | PFC_START_BIT);

            decodeHWTick = drv_get_current_time();
            decodeHWUst = ust_get_current_time();
   	 	}

        DRV_PFC_WriteReg32(
			PFC_START, 
			PFC_M_SRC | PFC_M_SL |PFC_M_DES | PFC_M_DL | PFC_RSTAT | PFC_WSTAT | PFC_DSET7E | PFC_START_BIT);
	}
   	else 
   	{  
        // Default start setting
        kal_mem_set(&PFC_decode_saddr[state->context_id], 0, SADDR_SIZE*sizeof(kal_uint8));

		if (is_log_enabled)
        {
            drv_trace2(TRACE_GROUP_10, PPP_START_MSG, PFC_START, PFC_START_BIT | PFC_DSET7E | PFC_WSTAT);
	        decodeHWTick = drv_get_current_time();
	        decodeHWUst = ust_get_current_time();
		}

        DRV_PFC_WriteReg32(PFC_START, PFC_START_BIT | PFC_DSET7E | PFC_WSTAT);
  	}
#if defined(DRV_PFC_POLLING)
   	do
	{
      	stat = DRV_PFC_Reg(PFC_STAT);
   	} while(stat == PFC_BUSY);

	if (is_log_enabled)
    {
   		decodeHWDuration = drv_get_duration_tick(decodeHWTick, drv_get_current_time());
   		decodeHWUst2 = ust_get_current_time();
	}
#else
 
   	kal_retrieve_eg_events(PFC_Event, 1, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);

	if (is_log_enabled)
    {
   		decodeHWDuration = drv_get_duration_tick(decodeHWTick, drv_get_current_time());
   		decodeHWUst2 = ust_get_current_time();
	}

  	ASSERT( event_group & 1);

    PFC_wait_stat_count = 0;
   	do
	{
      	stat = DRV_PFC_Reg(PFC_STAT);
        if(stat == PFC_BUSY)
        {
            PFC_ReadAllRegister(&pfc_debug);
        	ASSERT(0);
      	    PFC_wait_stat_count++;
        }
        if(PFC_wait_stat_count > PFC_WAIT_STATE_COUNT_THRESHOLD)
        {
            stat = PFC_PROTOCOL_ERROR;
            PFC_wait_stat_count = 0;
            drv_trace0(TRACE_GROUP_2, PPP_BUSY_MSG);
            break;
        }
   	}while(stat == PFC_BUSY);

   	IRQUnmask(IRQ_PFC_CODE);
#endif

   	//drv_trace4(TRACE_GROUP_2, PPP_DECODE_STATE_MSG, stat, (DRV_PFC_Reg32(PFC_SRC) - (kal_uint32)scp), DRV_PFC_Reg32(PFC_DES) - (kal_uint32)(op), decodeHWDuration);
    if (is_log_enabled)
    {
   		if(decodeHWDuration==0)
		{
      		drv_trace4(
				TRACE_GROUP_2, 
				PPP_DECODE_STATE_MSG, 
				stat, 
				(DRV_PFC_Reg32(PFC_SRC) - (kal_uint32)scp), 
				DRV_PFC_Reg32(PFC_DES) - (kal_uint32)(op), 
				decodeHWUst2 - decodeHWUst);
		}

		drv_trace4(TRACE_GROUP_10, PPP_DECODE_PARA_MSG, 0,0, (kal_uint32)dest->data_ptr, 0);
	}
   
   	switch(stat)
   	{
   		case PFC_OK:
/************
在做simulation時  我們發現SW decode會output FCS到dest buffer上  但hw則不會
需要請你注意在design Driver code時
在decode成功一個frame之後  要無條件把decode dest buffer length +2 (不需要真的算出FCS填上去)
這樣才能保持PPP SW處理的一致性
************/
            src->cur_ptr  = (kal_uint8 *)((kal_uint32)src->cur_ptr + src->used-DRV_PFC_Reg32(PFC_USLEN));
            src->used     = DRV_PFC_Reg32(PFC_USLEN);
            dest->used    = dest->size - DRV_PFC_Reg32(PFC_UDLEN) + 2;
            dest->end_ptr = (kal_uint8 *)((kal_uint32)dest->data_ptr + dest->used);
            state->rfcs   = AHDLC_FCS_FINAL;
            ret_val = KAL_TRUE;
            break;
  	 	case PFC_BUSY:
            PFC_decode_fail = KAL_TRUE;
            drv_trace0(TRACE_GROUP_2, PPP_BUSY_MSG);
            break;
   		case PFC_WRITE_FULL:
      		//Error case, /* Drop frame until 7E is received */
      		PFC_decode_fail = KAL_TRUE;
      		drv_trace0(TRACE_GROUP_2, PPP_WEITE_BUFFER_FULL_MSG);
      		break;
   		case PFC_ZERO_LENGTH:
            PFC_decode_fail = KAL_TRUE;
            drv_trace0(TRACE_GROUP_2, PPP_ZERO_LENGTH_MSG);
      		break;
   		case PFC_FCS_ERROR:
            PFC_decode_fail = KAL_TRUE;
            drv_trace0(TRACE_GROUP_2, PPP_FCS_ERROR_MSG);
            break;
   		case PFC_NOT_0X7E:
            PFC_decode_fail = KAL_TRUE;
            drv_trace0(TRACE_GROUP_2, PPP_NOT_0X7E_MSG);
            break;
   		case PFC_ADR_CON_ERROR:
            PFC_decode_fail = KAL_TRUE;
            drv_trace0(TRACE_GROUP_2, PPP_ADR_CON_ERROR_MSG);
            break;
   		case PFC_INVALID:
            PFC_decode_fail = KAL_TRUE;
            drv_trace0(TRACE_GROUP_2, PPP_INVALID_MSG);
            break;
   		case PFC_RESUME:
            PFC_wait_decode[state->context_id] = KAL_TRUE;
            drv_trace0(TRACE_GROUP_2, PPP_RESUME_MSG);
            break;
        case PFC_PROTOCOL_ERROR:
            PFC_decode_fail = KAL_TRUE;
            drv_trace0(TRACE_GROUP_2, PPP_PROTOCOL_ERROR_DECODING_MSG);
            break;
   		default:
            PFC_decode_fail = KAL_TRUE;
            drv_trace0(TRACE_GROUP_2, PPP_UNKNOWN_ERROR_MSG);
            break;
   	}

   	if(PFC_wait_decode[state->context_id] == KAL_TRUE)
   	{
        // PPP will wait UART_READY_TO_READY_MSG for part2 decode.
        src->cur_ptr += i_len - DRV_PFC_Reg32(PFC_USLEN);
        src->used = DRV_PFC_Reg32(PFC_USLEN);
        /* The destination will be used next time */
        dest->used    =  dest->size -  DRV_PFC_Reg32(PFC_UDLEN);
        dest->end_ptr = (kal_uint8 *)((kal_uint32)dest->data_ptr + dest->used);      
   	}
   	else if(PFC_decode_fail == KAL_TRUE)
   	{
        src->cur_ptr  = (kal_uint8 *)((kal_uint32)src->cur_ptr + (src->used - DRV_PFC_Reg32(PFC_USLEN)));
        src->used     = DRV_PFC_Reg32(PFC_USLEN);
        for (;src->cur_ptr < src->end_ptr; src->cur_ptr++, src->used--) 
        {
            if (AHDLC_FLAG == *src->cur_ptr)/* The new frame comes */
            {
            	break;
            }
        }
        state->rflags &= ~(MARK_DISCARD|MARK_ESCAPED);    
        *o_len = dest->used = 0;
        kal_mem_set(dest->data_ptr,0,dest->size);
        /* Reset the out buff pointer to begin */
        dest->end_ptr = dest->cur_ptr = dest->data_ptr;  
        op = dest->data_ptr;
        PFC_wait_decode[state->context_id] = KAL_FALSE;
   	}

#if defined(MTK_SLEEP_ENABLE )  &&  ! defined(__FUE__ )
   	L1SM_UnIRQSleepEnable  (  pfc_sm_handle);
#endif

	PDN_SET(PDN_PFC);

    /* Used only for logging */
    if (is_log_enabled)
    {
        decodeAPIDuration = drv_get_duration_tick(decodeAPITick, drv_get_current_time());
        decodeAPIUst2 = ust_get_current_time();

        //drv_trace1(TRACE_GROUP_2, PPP_DECODE_FINISH_MSG, decodeAPIDuration);
        if(decodeAPIDuration==0)
		{
        	drv_trace1(TRACE_GROUP_2, PPP_DECODE_FINISH_MSG, decodeAPIUst2 - decodeAPIUst);
		}

   		drv_trace4(TRACE_GROUP_10, PPP_DECODE_PARA_MSG, 0,0, (kal_uint32)dest->data_ptr, 0);
	}
   
	return ret_val;
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_Encode
*
* DESCRIPTION                  
*    PFC ppp framer encode 
*
* CALLS  
* This function is called when use PFC to encode ppp framer
*
* PARAMETERS
* None
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
kal_bool PFC_Encode( 
	pfc_buff_head_struct * dest, 
	pfc_buff_head_struct * src, 
    pfc_ahdlc_state_struct * state)
{
    kal_bool ret_value = KAL_FALSE;
	kal_bool is_log_enabled;
    kal_uint16 stat;

    kal_uint32 encodeAPITick = 0, encodeAPIDuration = 0, encodeHWTick = 0, encodeHWDuration = 0;
    kal_uint32 encodeAPIUst = 0, encodeAPIUst2 = 0, encodeHWUst = 0, encodeHWUst2 = 0; //ust_get_current_time();

#if !defined(DRV_PFC_POLLING)
   	kal_uint32 event_group;
#endif 

   	kal_uint8  * scp;
   	kal_uint8  * op;
	kal_uint16 i_len = src->end_ptr - src->cur_ptr;        /* < input length >         */

   	scp = (kal_uint8 *)src->cur_ptr;
   	op = (kal_uint8 *)dest->data_ptr;

#if defined(__TST_TRACE_ENABLED__) || defined(__TST_CRITICAL_TRACE_ENABLED__)
    is_log_enabled = tst_check_mod_filter (MOD_PPP);
#else
    is_log_enabled = KAL_FALSE;
#endif

   	if (INT_QueryIsCachedRAM(src->cur_ptr, (kal_uint32)(i_len*sizeof(kal_uint8))) || 
		INT_QueryIsCachedRAM(dest->data_ptr, (kal_uint32)((dest->size)*sizeof(kal_uint8)))) 
	{
      	EXT_ASSERT((kal_uint32)src->cur_ptr, (kal_uint32)src->end_ptr, (kal_uint32)dest->data_ptr, dest->size);
   	}

    //drv_trace0(TRACE_GROUP_1, PPP_ENCODE_MSG);
    if ((scp == NULL) || (op == NULL) || (dest->size == 0) )
    {
    	drv_trace4(TRACE_GROUP_1, PPP_ENCODE_PARA_ERROR_MSG, (kal_uint32)scp, (kal_uint32)0, (kal_uint32)op, dest->size);
    	return KAL_FALSE;
    }

    if (is_log_enabled)
    {
   		encodeAPITick = drv_get_current_time();
   		encodeAPIUst = ust_get_current_time();
	}
    
    PDN_CLR(PDN_PFC);
    DRV_WriteReg32(PFC_START, PFC_CLR);     /*   reset PFC states and        */

/* Attache PPP standard header */
   	if((KAL_TRUE == state->is_acfc_tx) && (src->protocol != PPP_PROTOCOL_LCP))
   	{
      	DRV_SetBits(PFC_CON, PFC_ACFC); // Enable ACFC bit	  
		
		if (is_log_enabled)
        { 
      		drv_trace0(TRACE_GROUP_10, PPP_ACFC_MSG);
      		drv_trace2(TRACE_GROUP_10, PPP_CON_MSG, PFC_CON, DRV_Reg(PFC_CON));
		}
   	}

   	if ((KAL_TRUE == state->is_pfc_tx) && (src->protocol <= 0x00FF))
   	{
		DRV_SetBits(PFC_CON, PFC_PFC); //Enable PFC bit

        if (is_log_enabled)
        {
      		drv_trace0(TRACE_GROUP_10, PPP_PFC_MSG);
      		drv_trace2(TRACE_GROUP_10, PPP_CON_MSG, PFC_CON, DRV_Reg(PFC_CON));
		}
   	}
 
    DRV_SetBits(PFC_CON, PFC_ENC); //Ensable ENC bit for Encode
    drv_trace2(TRACE_GROUP_10, PPP_CON_MSG, PFC_CON, DRV_PFC_Reg(PFC_CON));

#if defined(MTK_SLEEP_ENABLE )  &&  ! defined(__FUE__)
#if !defined (DRV_PFC_POLLING)
   	L1SM_UnIRQSleepDisable (pfc_sm_handle);
#endif
#endif

    DRV_PFC_WriteReg32(PFC_SRC, scp);
    DRV_PFC_WriteReg32(PFC_USLEN, src->end_ptr - src->cur_ptr);
    DRV_PFC_WriteReg32(PFC_DES, op);
    DRV_PFC_WriteReg32(PFC_UDLEN, dest->size);
    DRV_PFC_WriteReg32(PFC_PTC, src->protocol);
    PFC_WriteACCM(0, state->xaccm);

    if (is_log_enabled)
    {
        drv_trace2(TRACE_GROUP_10, PPP_SRC_MSG, PFC_SRC, (kal_uint32)scp);
        drv_trace2(TRACE_GROUP_10, PPP_USLEN_MSG, PFC_USLEN, src->end_ptr - src->cur_ptr);
        drv_trace2(TRACE_GROUP_10, PPP_DES_MSG, PFC_DES, (kal_uint32)op);
        drv_trace2(TRACE_GROUP_10, PPP_UDLEN_MSG, PFC_UDLEN, dest->size);
        drv_trace2(TRACE_GROUP_10, PPP_PTC_MSG, PFC_PTC, src->protocol);
        drv_trace2(TRACE_GROUP_10, PPP_ACCM_MSG, PFC_ACCM0, state->xaccm);

        encodeHWTick = drv_get_current_time();
        encodeHWUst = ust_get_current_time();
	}

   	//drv_trace4(TRACE_GROUP_1, PPP_ENCODE_PARA_MSG, (kal_uint32)scp, (kal_uint32)0, (kal_uint32)op, dest->size);
   	Data_Sync_Barrier(); // For ARM11
 	//default start setting

   	DRV_PFC_WriteReg32(PFC_START, PFC_START_BIT | PFC_ELASTS); //encode start
   
#if defined(DRV_PFC_POLLING)
   	do
	{
      	stat = DRV_PFC_Reg32(PFC_STAT);
   	}
	while(stat == PFC_BUSY);

    if (is_log_enabled)
    {	
   		encodeHWDuration = drv_get_duration_tick(encodeHWTick, drv_get_current_time());
   		encodeHWUst2 = ust_get_current_time();
	}
#else
   	kal_retrieve_eg_events( PFC_Event, 1, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    if (is_log_enabled)
    {
   		encodeHWDuration = drv_get_duration_tick(encodeHWTick, drv_get_current_time());
   		encodeHWUst2 = ust_get_current_time();
	}

   	ASSERT(event_group & 1);

    PFC_wait_stat_count = 0;        
   	do
	{
      	stat = DRV_PFC_Reg(PFC_STAT);
        if(stat == PFC_BUSY)
        {
            PFC_ReadAllRegister(&pfc_debug);
            ASSERT(0);
      	    PFC_wait_stat_count++;
        }        
        if(PFC_wait_stat_count > PFC_WAIT_STATE_COUNT_THRESHOLD)
        {
            stat = PFC_PROTOCOL_ERROR;
            PFC_wait_stat_count = 0;            
            drv_trace0(TRACE_GROUP_2, PPP_BUSY_MSG);
            break;
        }        
   	}
	while(stat == PFC_BUSY);

   	IRQUnmask(IRQ_PFC_CODE);
#endif      

   //drv_trace4(TRACE_GROUP_1, PPP_ENCODE_STATE_MSG, stat, DRV_PFC_Reg32(PFC_SRC) - (kal_uint32)scp, DRV_PFC_Reg32(PFC_DES) - (kal_uint32)(op), encodeHWDuration);
   	if (is_log_enabled)
   	{
		if(encodeHWDuration==0)
		{
   			drv_trace4(
				TRACE_GROUP_1, 
				PPP_ENCODE_STATE_MSG, 
				stat, 
				DRV_PFC_Reg32(PFC_SRC) - (kal_uint32)scp, 
				DRV_PFC_Reg32(PFC_DES) - (kal_uint32)(op), 
				encodeHWUst2 - encodeHWUst);
		}
	}

   	switch( stat)
   	{
   		case PFC_OK:
		{
      		dest->used    = dest->used + dest->size - DRV_PFC_Reg32(PFC_UDLEN);//DRV_PFC_Reg32(PFC_DES) - (kal_uint32)dest->data_ptr + 2;//*o_len;
      		dest->end_ptr = (kal_uint8 *)((kal_uint32)dest->data_ptr + dest->used);
      		/* A Good Frame comes */
      		ret_value =  KAL_TRUE;
		}
      	break;

   		case PFC_WRITE_FULL:
		{
      		drv_trace0(TRACE_GROUP_1, PPP_WEITE_BUFFER_FULL_MSG);
		}
      	break;

   		case PFC_ZERO_LENGTH:
		{
      		drv_trace0(TRACE_GROUP_1, PPP_BUSY_MSG);
		}
      	break;

 	  	case PFC_FCS_ERROR:
      	// recover scheme?
		{
      		drv_trace0(TRACE_GROUP_1, PPP_FCS_ERROR_MSG);
		}
      	break;

   		case PFC_NOT_0X7E:
		{
      		drv_trace0(TRACE_GROUP_1, PPP_NOT_0X7E_MSG);
		}
      	break;

   		case PFC_ADR_CON_ERROR:
		{
      		drv_trace0(TRACE_GROUP_1, PPP_ADR_CON_ERROR_MSG);
		}
      	break;

   		case PFC_INVALID:
		{
      		drv_trace0(TRACE_GROUP_1, PPP_INVALID_MSG);
		}
     	break;

   		case PFC_RESUME:
		{
      		drv_trace0(TRACE_GROUP_1, PPP_RESUME_MSG);
		}
      	break;

   		case PFC_PROTOCOL_ERROR:
		{
      		drv_trace0(TRACE_GROUP_1, PPP_PROTOCOL_ERROR_DECODING_MSG);
		}
      	break;

   		default:
		{
      		drv_trace0(TRACE_GROUP_1, PPP_UNKNOWN_ERROR_MSG);
		}
      	break;
   	}

#if defined(MTK_SLEEP_ENABLE )  &&  ! defined(__FUE__ )
   	L1SM_UnIRQSleepEnable  (  pfc_sm_handle);
#endif

   	PDN_SET(PDN_PFC);

    if (is_log_enabled)
    {
   		encodeAPIDuration = drv_get_duration_tick(encodeAPITick, drv_get_current_time());
   		encodeAPIUst2 = ust_get_current_time();
   
   		//drv_trace1(TRACE_GROUP_1, PPP_ENCODE_FINISH_MSG, encodeAPIDuration);
   		if(encodeAPIDuration==0)
		{
   			drv_trace1(TRACE_GROUP_1, PPP_ENCODE_FINISH_MSG, encodeAPIUst2 - encodeAPIUst);
		}
	}

   	return ret_value;
 	//DRV_PFC_WriteReg32(PFC_RSTB, 0x0); // reset PFC enable signal
}


//==================================================================================================================
/*
* FUNCTION                 
* PFC_init
*
* DESCRIPTION                  
*    PFC initial
*
* CALLS  
* This function is called when PFC first initial
*
* PARAMETERS
* None
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_init(void)
{
#if !defined(DRV_PFC_POLLING)

   if( PFC_Event == NULL)
      PFC_Event = kal_create_event_group("PFCEVT");

#if defined(MTK_SLEEP_ENABLE)  &&  ! defined(__FUE__)
   pfc_sm_handle = L1SM_GetHandle();
#endif    /*#if defined(MTK_SLEEP_ENABLE) && */ /* !defined(__FUE__) */
   //follow up
   //also register HISR here.
   //DRV_PFC_Reg32ister_HISR((kal_uint8)DRV_PFC_HISR_ID, PFC_HISR);
   DRV_Register_HISR(DRV_PFC_HISR_ID,PFC_HISR);

   DRV_PFC_WriteReg32(PFC_INTEN, PFC_INTEN_BIT);
   
#if defined(DRV_PFC_PFGA)
   DRV_PFC_WriteReg32(0xC0110010, 0xFd7F0000);  //Turn off F4 one IRQ for F1 UPA L2 Copro IRQ
#endif 
   
   IRQ_Register_LISR(IRQ_PFC_CODE, PFC_LISR, "PFC handler");
   IRQSensitivity(IRQ_PFC_CODE, LEVEL_SENSITIVE);
   IRQUnmask(IRQ_PFC_CODE);
#endif //#if defined(DRV_PFC_POLLING)
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_reset
*
* DESCRIPTION                  
*    PFC reset
*
* CALLS  
* This function is called when PFC reset
*
* PARAMETERS
* None
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_reset(kal_uint32 context_id)
{
   PFC_wait_decode[context_id] = KAL_FALSE;
   DRV_PFC_WriteReg(CONFIG_base+0x32C, 0x40);
   DRV_PFC_WriteReg32(PFC_START, PFC_CLR);     /*   reset PFC states and        */
   DRV_PFC_WriteReg(CONFIG_base+0x31C, 0x40);
   kal_mem_set( &PFC_decode_saddr[context_id], 0, SADDR_SIZE*sizeof(kal_uint8));
}


#if !defined(DRV_PFC_POLLING)
//==================================================================================================================
/*
* FUNCTION                 
* PFC_HISR
*
* DESCRIPTION                  
*    PFC HISR handler
*
* CALLS  
* This function is called when PFC LISR active HISR
*
* PARAMETERS
* None
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_HISR(void)
{
   //dbg_print( "----------------------------------------------------------------\n\r");
   //dbg_print( "PFC HISR %d\n\r");
   
   //clear interrupt here.
   //set different event for diff different interrupt.
 
   /*lint -e(534)*/kal_set_eg_events(PFC_Event,1,KAL_OR);

   IRQClearInt(IRQ_PFC_CODE);
   //IRQUnmask(IRQ_PFC_CODE);
}

//==================================================================================================================
/*
* FUNCTION                 
* PFC_LISR
*
* DESCRIPTION                  
*    PFC interrupt handler
*
* CALLS  
* This function is called when PFC intr. is coming
*
* PARAMETERS
* None
*   
* RETURNS
* None
*
* GLOBALS AFFECTED
* external_global
*/
void PFC_LISR(void)
{
   IRQMask(IRQ_PFC_CODE);
   drv_active_hisr((kal_uint32)DRV_PFC_HISR_ID);
}

#endif //#if defined(DRV_PFC_POLLING)

void PFC_register_test(kal_uint32 reg, kal_uint32 max)
{
   kal_uint32 i = 0;
   kal_uint16 readOut;

   for( i = 0; i <= max; i++)
   {
      DRV_PFC_WriteReg32(reg, i);
      readOut = DRV_PFC_Reg32(reg);
      if( i != readOut)
      {
         while(1);
      }
   }
}

void PFC_read_write_test()
{
   PFC_register_test(PFC_START, 0x1FFF);
   PFC_register_test(PFC_CON, 0xF);
   PFC_register_test(PFC_PTC, 0xFFFF);
   PFC_register_test(PFC_SADDR, 0xFFFFFFFF);
   PFC_register_test(PFC_SRC, 0xFFFFFFFF);
   PFC_register_test(PFC_USLEN, 0xFFFF);
   PFC_register_test(PFC_DES, 0xFFFFFFFF);
   PFC_register_test(PFC_UDLEN, 0xFFFF);
   PFC_register_test(PFC_INTEN, 0x1);
   PFC_register_test(PFC_SDRAT, 0xFF);

   PFC_register_test(PFC_ACCM0, 0xFFFFFFFF);
   PFC_register_test(PFC_ACCM1, 0xFFFFFFFF);
   PFC_register_test(PFC_ACCM2, 0xFFFFFFFF);
   PFC_register_test(PFC_ACCM3, 0xFFFFFFFF);
   PFC_register_test(PFC_ACCM4, 0xFFFFFFFF);
   PFC_register_test(PFC_ACCM5, 0xFFFFFFFF);
   PFC_register_test(PFC_ACCM6, 0xFFFFFFFF);
}

#endif //#if defined(__HW_PFC_SUPPORT__)
