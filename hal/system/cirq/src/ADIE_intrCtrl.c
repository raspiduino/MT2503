/***********************************************************************
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
 *   ADIE_intrCtrl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the initialization of ADIE CIRQ.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "ADIE_intrCtrl.h"
#include "isrentry.h"

#if defined(__CIRQ_DIE2DIE__)

/*******************************************************************************
 * Define global data
 *******************************************************************************/
const kal_uint8  ADIE_irqLine[ADIE_NUM_IRQ_LINES] = { ADIE_IRQ_LINE_MAPPING_TABLE };
kal_uint8        ADIE_IRQCode2Line[ADIE_NUM_IRQ_SOURCES];
static kal_uint8 ADIE_INTMaskCount[ADIE_NUM_IRQ_LINES];

static void      *ADIE_processing_lisr = NULL;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*******************************************************************************
 * Declare import global data
 *******************************************************************************/
extern irqlisr_entry lisr_dispatch_tbl[];

/*************************************************************************
 * Define function prototpye
 *************************************************************************/
kal_uint32 LockIRQ(void);
void RestoreIRQ(kal_uint32 irq);

/* MT6250 D2D bus clock may miss 1T after wakeup from sleep mode, 
   which causes reading back wrong A-DIE IRQ_STA value and issuing EOI to wrong IRQ line, 
   so we activate a timer to issue EOI to all A-DIE IRQ */
void ADIE_SYS_ClearInt2(kal_uint8);
extern kal_bool kal_set_aligned_timer(TM_TCB *timer, kal_uint8 max_delay);
kal_timerid ADIE_IRQ_Timer;

void ADIE_IRQ_TimerCallback(void *arg)
{
    kal_uint8 idx;
    for( idx = 0; idx < ADIE_NUM_IRQ_SOURCES; ++idx ){
        ADIE_SYS_ClearInt2(idx);
    }
}

#ifdef __MTK_TARGET__
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

void ADIE_SetRefreshTimer(void)
{
#if defined(MT6250)
   TM_TCB *tm_ptr;
   kal_internal_timerid kal_timer;

   ADIE_IRQ_Timer = kal_create_timer("ADIE_IRQ");
   kal_timer = (kal_internal_timerid)ADIE_IRQ_Timer;
   tm_ptr = &(((TM_APP_TCB *)&(kal_timer->timer_id))->tm_actual_timer);
   kal_set_aligned_timer(tm_ptr, ALIGNED_TIMER_MAX_DELAY);
   kal_set_timer(ADIE_IRQ_Timer, (kal_timer_func_ptr)ADIE_IRQ_TimerCallback, NULL, KAL_TICKS_100_MSEC, KAL_TICKS_100_MSEC);
#endif
}
/* ==================== */


#ifdef __MTK_TARGET__
#pragma arm section rwdata , rodata , zidata
#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  ADIE_IRQDirectMaskAll
*
* DESCRIPTION
*  Mask all of the interrupts with direct indexing.
*
* IMPORTANT NOTICE
*  Reserved for system service only!
*  used while system error
*  such as fatal error, assertion failure and CPU triggered excetpion.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void ADIE_IRQDirectMaskAll(void)
{
#if 0
/* under construction !*/
/* under construction !*/
#endif
    
    *ADIE_IRQ_MASK_SET0 = 0xFFFF;
}

/*************************************************************************
* FUNCTION
*  ADIE_IRQClearAllInt
*
* DESCRIPTION
*  Clear all of the interrupts with direct indexing.
*
* IMPORTANT NOTICE
*  Reserved for system service only!
*  This is special API for system service only; used on system 
*  initialization stage!
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void ADIE_IRQClearAllInt(void)
{
    *ADIE_IRQ_EOIOH0= 0xffff;
}

/*************************************************************************
* FUNCTION
*  ADIE_IRQClearInt
*
* DESCRIPTION
*  Clear IRQ with plain format interrupt status
*
* PARAMETERS
*  Plain format interrupt status
*
* RETURNS
*
*************************************************************************/
void ADIE_IRQClearInt(kal_uint8 code)
{
    kal_uint8 line;

    ASSERT(code<ADIE_NUM_IRQ_SOURCES);

    line = ADIE_IRQCode2Line[code];
    
    *ADIE_IRQ_EOIOH0 = (1 << line);
}

/*************************************************************************
* FUNCTION
*  ADIE_IRQ_Status
*
* DESCRIPTION
*  query the value of interrupt status register
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 ADIE_IRQ_Status(void)
{
    kal_uint16 irqx;
    
    irqx = *ADIE_IRQ_STA2;
    
    if ( (irqx&0x100) == 0x100 )
        return (kal_uint32)(-1);
    else 
        return (kal_uint32)(irqx&0xff);
}

/*************************************************************************
* FUNCTION
*  SYS_ClearInt2
*
* DESCRIPTION
*  Reserved for system service only!
*  Clear IRQ with binary coded interrupt status
*  It is trapped while Interrupt is disabled!
*
* PARAMETERS
*  Binary coded interrupt status
*
* RETURNS
*
*************************************************************************/
void ADIE_SYS_ClearInt2(kal_uint8 irq_idx)
{
   *ADIE_IRQ_EOI2 = irq_idx;
}

/*************************************************************************
* FUNCTION
*  ADIE_isrC_Main
*
* DESCRIPTION
*  Entry function of ADIE interrupt
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void ADIE_isrC_Main(void)
{
    kal_uint32 irqx, activated_mask, i;
#if defined(__TINY_SYS__) /* dongming add for tiny sys */
	   kal_uint32 tp_sw_reg_status;
	   kal_uint8 tp_irq_code;
#endif 

    /* read STA2 to refresh ASTA2 */ 
    irqx = ADIE_IRQ_Status();
    if(irqx == (kal_uint32)(-1))
        return;

#if defined(__TINY_SYS__) /* dongming add for tiny system */
	   tp_irq_code = ADIE_irqLine[irqx];
	   if (tp_irq_code < 32)
	   {
		  tp_sw_reg_status = *ADIE_IRQ_SOFT0;
	   }	
	   if(0 != (tp_sw_reg_status & (1 << tp_irq_code)))
	   {
		   tp_irq_code = ADIE_irqLine[irqx];
			ADIE_IRQ_ResetSWRegister(tp_irq_code);
	   }
#endif

    ADIE_processing_lisr = (void*)lisr_dispatch_tbl[IRQ_LINE_ADIE_TO_GLB(irqx)].lisr_handler;
    lisr_dispatch_tbl[IRQ_LINE_ADIE_TO_GLB(irqx)].lisr_handler();           
    ADIE_processing_lisr = NULL;

    ADIE_SYS_ClearInt2((kal_uint8)irqx);
}

/*************************************************************************
* FUNCTION
*  ADIE_initINTR
*
* DESCRIPTION
*  Interrupt initialization
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void ADIE_initINTR(void)
{
    kal_uint8 idx;
    
    /* determine the mapping between interrupt code and line          */
    for (idx=0;idx<ADIE_NUM_IRQ_SOURCES;idx++) 
        ADIE_IRQCode2Line[ADIE_irqLine[idx]] = idx;

    kal_mem_set(ADIE_INTMaskCount, 0, sizeof(ADIE_INTMaskCount));
    
    /* mask all interrupt events */
    ADIE_IRQDirectMaskAll();
    
    /* assign IRQ Selection Registers */
    ADIE_IRQSel();
    
    /* clear all pending interrupts */
    ADIE_IRQClearAllInt();
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*************************************************************************
* FUNCTION
*  ADIE_IRQSensitivity
*
* DESCRIPTION
*  Setting sensitivity of IRQ
*
* PARAMETERS
*  code: IRQ number to be set
*  edge: either edge active low or level active low
*
* RETURNS
*
*************************************************************************/
void ADIE_IRQSensitivity(kal_uint8 code, kal_bool edge)
{
    kal_uint8 line;

    ASSERT(code<ADIE_NUM_IRQ_SOURCES);
    
    line = ADIE_IRQCode2Line[code];
    if (edge != KAL_FALSE) 
    {
        *ADIE_IRQ_SENS_CLR0 = (1 << line);
    }  
    else 
    {
        *ADIE_IRQ_SENS_SET0 = (1 << line);
    }
}

/*************************************************************************
* FUNCTION
*  ADIE_IRQMask
*
* DESCRIPTION
*  Mask certain interrupt source.
*
* PARAMETERS
*  Interrupt source to be masked, it is indexed via IRQCode2Line.
*
* RETURNS
*
*************************************************************************/
void ADIE_IRQMask(kal_uint8 code)
{
    kal_uint32 savedMask;
    kal_uint8  line;   
    
    ASSERT(code < ADIE_NUM_IRQ_SOURCES);
    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    line = ADIE_IRQCode2Line[code];

    /*
     * [Important]
     * IRQ mask will be valid around 2T ~ 3T after register is written. 
     * To ensure IRQ is turned off thoroughly, I bit must be disabled in 
     * advanced; otherwise, IRQ may be triggered unexpectedly.
     */
    savedMask = LockIRQ();
    
    ASSERT(ADIE_INTMaskCount[line]==0 || ADIE_INTMaskCount[line]==255);
    
    ADIE_INTMaskCount[line] = 255;
    
    *ADIE_IRQ_MASK_SET0= (1 << line);

    RestoreIRQ(savedMask);
}  

/*************************************************************************
* FUNCTION
*  ADIE_IRQUnmask
*
* DESCRIPTION
*  Mask certain interrupt source.
*
* PARAMETERS
*  Interrupt source to be masked, it is indexed via IRQCode2Line.
*
* RETURNS
*
*************************************************************************/
void ADIE_IRQUnmask(kal_uint8 code)
{
    kal_uint32 savedMask;
    kal_uint8  line;   
    
    ASSERT(code < ADIE_NUM_IRQ_SOURCES);

    /* Debug code for DIE2DIE IRQ, shouldbe phased out by W12.28 */    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    line = ADIE_IRQCode2Line[code];

    savedMask = LockIRQ();

    ASSERT(ADIE_INTMaskCount[line]==0 || ADIE_INTMaskCount[line]==255);

    ADIE_INTMaskCount[line]= 0;
    
    *ADIE_IRQ_MASK_CLR0= (1 << line);

    RestoreIRQ(savedMask);
}  

/*************************************************************************
* FUNCTION
*  ADIE_IRQMask_Status
*
* DESCRIPTION
*  Mask certain interrupt source.
*
* PARAMETERS
*  Interrupt source to be masked, it is indexed via IRQCode2Line.
*
* RETURNS
*
*************************************************************************/
kal_uint32 ADIE_IRQMask_Status(kal_uint8 code)
{
    kal_uint32 line;

    ASSERT(code < ADIE_NUM_IRQ_SOURCES);

    line = ADIE_IRQCode2Line[code];

    return (*ADIE_IRQ_MASK0 & (1<<line));
}  

/*************************************************************************
* FUNCTION
*  ADIE_SetINTMask
*
* DESCRIPTION
*  This function mask interrupt line and returned special pattern.
*
* PARAMETERS
*  code : Interrupt source of interrupt controller
*
* RETURNS
*  
*  
*************************************************************************/
void ADIE_SetINTMask(kal_uint8 code)
{
    kal_uint32 savedMask;
    kal_uint8  line;   

    ASSERT(code < ADIE_NUM_IRQ_SOURCES);

    line = ADIE_IRQCode2Line[code];
    
    /*
     * [Important]
     * IRQ mask will be valid around 2T ~ 3T after register is written. 
     * To ensure IRQ is turned off thoroughly, I bit must be disabled in 
     * advanced; otherwise, IRQ may be triggered unexpectedly.
     */
    
    savedMask = LockIRQ();
    
    ASSERT(ADIE_INTMaskCount[line]<254); 
     
    if(++ADIE_INTMaskCount[line]==1)
    {
        *ADIE_IRQ_MASK_SET0 = (1 << line);
    }
    
    RestoreIRQ(savedMask);    
}

/*************************************************************************
* FUNCTION
*  ADIE_RestoreINTMask
*
* DESCRIPTION
*  This function unmask interrupt line and .
*
* PARAMETERS
*  code : Interrupt source of interrupt controller
*
* RETURNS
*  none
*  
*************************************************************************/
void ADIE_RestoreINTMask(kal_uint8 code)
{
    kal_uint32 savedMask;
    kal_uint8  line;   

    ASSERT(code < ADIE_NUM_IRQ_SOURCES);

    line = ADIE_IRQCode2Line[code];
    
    savedMask = LockIRQ();
    
    ASSERT(ADIE_INTMaskCount[line]<254); 
     
    if(--ADIE_INTMaskCount[line]==1)
    {
        *ADIE_IRQ_MASK_CLR0 = (1 << line);
    }
    RestoreIRQ(savedMask);    
}

/*************************************************************************
* FUNCTION
*  ADIE_IRQ_SetSWRegister
*
* DESCRIPTION
*  This function set SW interrupt register
*
* PARAMETERS
*  code : Interrupt source of interrupt controller
*
* RETURNS
*  none
*  
*************************************************************************/
void ADIE_IRQ_SetSWRegister(kal_uint8 code)
{
    ASSERT(code<ADIE_NUM_IRQ_SOURCES);

    *ADIE_IRQ_SOFT_SET0 = (1 << code);
}

/*************************************************************************
* FUNCTION
*  ADIE_IRQ_ResetSWRegister
*
* DESCRIPTION
*  This function reset SW interrupt register
*
* PARAMETERS
*  code : Interrupt source of interrupt controller
*
* RETURNS
*  none
*  
*************************************************************************/
void ADIE_IRQ_ResetSWRegister(kal_uint8 code)
{
    ASSERT(code<ADIE_NUM_IRQ_SOURCES);

    *ADIE_IRQ_SOFT_CLR0 = (1 << code);
}

#endif

