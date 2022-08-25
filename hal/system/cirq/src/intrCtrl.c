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
 *   intrCtrl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the initialization of intrCtrl.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "intrCtrl.h"
#if defined(__CIRQ_DIE2DIE__)
#include "ADIE_intrCtrl.h"
#endif  

/*******************************************************************************
 * Define global data
 *******************************************************************************/

#if !defined(NUM_IRQ_LINES)
#define NUM_IRQ_LINES    NUM_IRQ_SOURCES
#endif

/* install interrupt handler functions */
const kal_uint8 irqLine[NUM_IRQ_LINES] = { IRQ_LINE_MAPPING_TABLE };
kal_uint8 IRQCode2Line[NUM_IRQ_SOURCES];

static IRQ_MASK_VALUE_T SleepModeMask;
static kal_uint8 SleepModeMaskCount=0;
static IRQ_MASK_VALUE_T CTIRQ1_2_MaskValue;

#if defined(MT6226) && defined(__MTK_TARGET__)
/* Gemini26 60Qbit Assert, put IRQCode2Line into Internal RAM*/
#pragma arm section rwdata="INTERNRW", zidata="INTERNZI"
#endif

static kal_uint8 INTMaskCount[NUM_IRQ_LINES];

#if defined(MT6226) && defined(__MTK_TARGET__)
#pragma arm section rwdata, zidata
#endif

#if defined(__ENABLE_SW_TRIGGER_INTERRUPT__)
const kal_uint8 SW_Code_Handle2Code[SW_HANDLE_END-NUM_IRQ_SOURCES] = 
{
#define X_SW_HANDLE_CONST(a, b, c) c,
   #include "intrCtrl_SW_Handle.h"
#undef X_SW_HANDLE_CONST
};

/* F2S early response macro */
#define IRQ_F2S_DUMMY_READ()    do { \
        *IRQ_SEL0; \
    } while(0)

kal_uint32 SW_INT_Counter[SW_HANDLE_END-NUM_IRQ_SOURCES];
#endif /* __ENABLE_SW_TRIGGER_INTERRUPT__ */

kal_uint32 IRQMaskStatus[5];

/* debug code for AST, should be phase-out by W12.26 */
#if defined(MT6255)

kal_uint8  irq_mask_monitor_idx = IRQ_GPT_CODE;
kal_uint8  irq_unmask_monitor_idx = IRQ_GPT_CODE;
kal_uint32 irq_mask_caller;
kal_uint32 irq_unmask_caller;
kal_uint32 irq_mask_caller_ast;
kal_uint32 irq_unmask_caller_ast;
kal_uint32 irq_ctirq1_2_mask[2];

/* debug code for A-DIE Interrupt, should be phase-out by W12.26 */
#elif defined(MT6250) || defined(MT6260)  || defined(__IRQ_MASK_MONITOR_ON__)

kal_uint32 irq_mask_caller;
kal_uint32 irq_unmask_caller;
kal_uint8 irq_mask_monitor_idx = IRQ_DIE2DIE_CODE;
kal_uint8 irq_unmask_monitor_idx = IRQ_DIE2DIE_CODE;

#else    /* MT6255 */

kal_uint32 irq_mask_caller;
kal_uint32 irq_unmask_caller;
kal_uint8 irq_mask_monitor_idx = NUM_IRQ_SOURCES;
kal_uint8 irq_unmask_monitor_idx = NUM_IRQ_SOURCES;

#endif    /* MT6255 */


static kal_uint32 irq_ctirq1_2_mask_status = 0;

/*******************************************************************************
 * Declare import function prototype 
 *******************************************************************************/
extern kal_uint32 LockIRQ(void);
extern void RestoreIRQ(kal_uint32 irq);
extern kal_bool INT_QueryExceptionStatus(void);

/*************************************************************************
* FUNCTION
*  IRQDirectMaskAll
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
void IRQDirectMaskAll(void)
{
   kal_uint32 savedmask;

   /* Lockout all interrupts */
   savedmask = LockIRQ();
// TODO: Fix LockIRQ usage on older chips only

#if defined(MT6228)

   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKH = 0xff;

#elif defined(MT6229) || defined(MT6230)

   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKH = 0x1ff;

#elif defined(MT6238)|| defined(MT6239) || defined(MT6235) || defined(MT6235B)

   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKH = 0x3ffff;

#elif defined(MT6268A) || defined(MT6268)

   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKM= 0xffffffff;
   *IRQ_MASKH = 0xff;

#elif defined(__CIRQ_MASK_REG_NR_2__)

   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKH = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)

   *IRQ_MASK_SET0 = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_SET4 = 0xffffffff;

#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)

   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKH = 0xffffffff;

#else

   *IRQ_MASK = 0xffffffff;
   
#endif

   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. The CIRQ may *
   * not be really masked after return from this function and may   *
   * cause race conidition. The workaround is to read one dummy     *
   * register. The mask operation will take effect after 3T and     *
   * it will complete before the dummy read transaction. Therefore  *
   * the mask operation completes before return from this function. *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    IRQ_F2S_DUMMY_READ();
#endif

   RestoreIRQ(savedmask);
}

/*************************************************************************
* FUNCTION
*  IRQ_SaveMaskStatus
*
* DESCRIPTION
*  Save the current IRQ MASK status when exception
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void IRQ_SaveMaskStatus(void)
{
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
    IRQMaskStatus[0] = *IRQ_MASK0;
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
    IRQMaskStatus[0] = *IRQ_MASK0;
    IRQMaskStatus[1] = *IRQ_MASK1;
#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
    IRQMaskStatus[0] = *IRQ_MASK0;
    IRQMaskStatus[1] = *IRQ_MASK1;
    IRQMaskStatus[2] = *IRQ_MASK2;
#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
    IRQMaskStatus[0] = *IRQ_MASK0;
    IRQMaskStatus[1] = *IRQ_MASK1;
    IRQMaskStatus[2] = *IRQ_MASK2;
    IRQMaskStatus[3] = *IRQ_MASK3;
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
    IRQMaskStatus[0] = *IRQ_MASK0;
    IRQMaskStatus[1] = *IRQ_MASK1;
    IRQMaskStatus[2] = *IRQ_MASK2;
    IRQMaskStatus[3] = *IRQ_MASK3;
    IRQMaskStatus[4] = *IRQ_MASK4;
#elif defined(__CIRQ_MASK_REG_NR_2__)
    IRQMaskStatus[0] = *IRQ_MASKL;
    IRQMaskStatus[1] = *IRQ_MASKH;
#elif defined(__CIRQ_MASK_REG_NR_3__)
    IRQMaskStatus[0] = *IRQ_MASKL;
    IRQMaskStatus[1] = *IRQ_MASKM;
    IRQMaskStatus[2] = *IRQ_MASKH;
#elif defined(MT6228)
    IRQMaskStatus[0] = *IRQ_MASKL;
    IRQMaskStatus[1] = *IRQ_MASKH;
#elif defined(MT6229) || defined(MT6230)
    IRQMaskStatus[0] = *IRQ_MASKL;
    IRQMaskStatus[1] = *IRQ_MASKH;
#elif defined(MT6235) || defined(MT6235B) || defined(MT6238)|| defined(MT6239)
    IRQMaskStatus[0] = *IRQ_MASKL;
    IRQMaskStatus[1] = *IRQ_MASKH;
#elif defined(MT6268) || defined(MT6268A)
    IRQMaskStatus[0] = *IRQ_MASKL;
    IRQMaskStatus[1] = *IRQ_MASKM;
    IRQMaskStatus[2] = *IRQ_MASKH;
#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)
    IRQMaskStatus[0] = *IRQ_MASKL;
    IRQMaskStatus[1] = *IRQ_MASKH;
#elif defined(MT6516) && !defined(__APPLICATION_PROCESSOR__)
    IRQMaskStatus[0] = *IRQ_MASK;
#elif defined(TK6516)
    IRQMaskStatus[0] = *IRQ_MASK;
#else
#endif
    return;
}

/*************************************************************************
* FUNCTION
*  SYS_ClearInt
*
* DESCRIPTION
*  Reserved for system service only!
*  Clear IRQ with plain format interrupt status
*  It is trapped while Interrupt is disabled!
*
* PARAMETERS
*  Plain format interrupt status
*
* RETURNS
*
*************************************************************************/
void SYS_ClearInt(kal_uint8 code)
{
#if defined(__CIRQ_MASK_REG_NR_2__)

   if (code < 32)
      *IRQ_EOIL = (1 << code);
   else
      *IRQ_EOIH = (1 << (code - 32));
      
#elif defined(__CIRQ_MASK_REG_NR_3__)

   ASSERT(code<NUM_IRQ_SOURCES);

   if (code < 32)
      *IRQ_EOIL = (1 << code);
   else if(code < 64)
      *IRQ_EOIM = (1 << (code - 32));
   else
      *IRQ_EOIH = (1 << (code - 64));

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);

  *IRQ_EOIOH0= (1 << code);
      
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);

   if (code < 32)
      *IRQ_EOIOH0= (1 << code);
   else
      *IRQ_EOIOH1 = (1 << (code - 32));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);

   if (code < 32)
      *IRQ_EOIOH0= (1 << code);
   else if(code < 64)
      *IRQ_EOIOH1 = (1 << (code - 32));
   else if (code < 96)
      *IRQ_EOIOH2 = (1 << (code - 64));
   else
      *IRQ_EOIOH3 = (1 << (code - 96));
      
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);

   if (code < 32)
      *IRQ_EOIOH0= (1 << code);
   else if (code < 64)
      *IRQ_EOIOH1 = (1 << (code - 32));
   else if (code < 96)
      *IRQ_EOIOH2 = (1 << (code - 64));
   else if (code < 128)
      *IRQ_EOIOH3 = (1 << (code - 96));
   else
      *IRQ_EOIOH4 = (1 << (code - 128));
      
#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)

   if (code < 32)
      *IRQ_EOIL = (1 << code);
   else
      *IRQ_EOIH = (1 << (code - 32));

#else         

   *IRQ_EOI = (1 << code);
   
#endif 
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
void SYS_ClearInt2(kal_uint8 irq_idx)
{
   *IRQ_EOI2 = irq_idx;
}

/*************************************************************************
* FUNCTION
*  IRQClearAllInt
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
void IRQClearAllInt(void)
{
#if defined(__CIRQ_DIE2DIE__)
   ADIE_IRQClearAllInt();
#endif    
    
#if defined(MT6228)

   *IRQ_EOIL = 0xffffffff;
   *IRQ_EOIH = 0xff;

#elif defined(MT6229) || defined(MT6230)

   *IRQ_EOIL = 0xffffffff;
   *IRQ_EOIH = 0x1ff;

#elif defined(MT6238)|| defined(MT6239) || defined(MT6235) || defined(MT6235B)

   *IRQ_EOIL = 0xffffffff;
   *IRQ_EOIH = 0x3ffff;

#elif defined(__CIRQ_MASK_REG_NR_2__)

   *IRQ_EOIL = 0xffffffff;
   *IRQ_EOIH = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_3__)

   *IRQ_EOIL = 0xffffffff;
   *IRQ_EOIM = 0xffffffff;
   *IRQ_EOIH = 0xff;

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)

   *IRQ_EOIOH0= 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   *IRQ_EOIOH0= 0xffffffff;
   *IRQ_EOIOH1= 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   *IRQ_EOIOH0= 0xffffffff;
   *IRQ_EOIOH1= 0xffffffff;
   *IRQ_EOIOH2= 0xffffffff;
   *IRQ_EOIOH3= 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   *IRQ_EOIOH0= 0xffffffff;
   *IRQ_EOIOH1= 0xffffffff;
   *IRQ_EOIOH2= 0xffffffff;
   *IRQ_EOIOH3= 0xffffffff;
   *IRQ_EOIOH4= 0xffffffff;

#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)

   *IRQ_EOIL = 0xffffffff;
   *IRQ_EOIH = 0xffffffff;

#else

   *IRQ_EOI = 0xffffffff;
   
#endif
}

#if !defined(__CIRQ_DESIGN_NEW__)
/*************************************************************************
* FUNCTION
*  FIQSel
*
* DESCRIPTION
*  Reserved for system service only!
*  Selection of FIQ.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void FIQSel(void)
{
   *FIQ_SEL = FIQ_CODE;
}

/*************************************************************************
* FUNCTION
*  FIQMask
*
* DESCRIPTION
*  Reserved for system service only!
*  Mask FIQ
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void FIQMask(void)
{
   *FIQ_CON |= 0x0001; /* different method from masking FIQ!! */
}

/*************************************************************************
* FUNCTION
*  FIQUnmask
*
* DESCRIPTION
*  Reserved for system service only!
*  Unmask FIQ
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void FIQUnmask(void)
{
   *FIQ_CON &= 0xFFFE; /* different method from unmasking FIQ!! */
}

/*************************************************************************
* FUNCTION
*  FIQClearInt
*
* DESCRIPTION
*  Reserved for system service only!
*  Clear FIQ
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void FIQClearInt(void)
{
   *FIQ_EOI = 0x0001;
}

/*************************************************************************
* FUNCTION
*  FIQSensitivity
*
* DESCRIPTION
*  Setting sensitivity of FIQ
*
* PARAMETERS
*  Either edge active low or level active low
*
* RETURNS
*
*************************************************************************/
void FIQSensitivity(kal_bool edge)
{
   /* it is an edge sensitive interrupt */
   if (edge != KAL_FALSE)
      *FIQ_CON &= 0xFFFD;
      
   /* level sensitive interrupt */
   else
      *FIQ_CON |= 0x0002;
}

#endif   /* !defined(__CIRQ_DESIGN_NEW__) */

/*************************************************************************
* FUNCTION
*  IRQClearInt
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
void IRQClearInt(kal_uint8 code)
{
   kal_uint8 line;
   kal_uint32 savedmask;
   
#if defined(__CIRQ_DIE2DIE__)   
   if(IS_ADIE_IRQ_CODE(code))
   {
       ADIE_IRQClearInt(IRQ_CODE_GLB_TO_ADIE(code));
   
       return;
   }
#endif

   line = IRQCode2Line[code];

   /* Lockout all interrupts */
   savedmask = LockIRQ();   

#if defined(__CIRQ_MASK_REG_NR_2__)

   if (line < 32)
      *IRQ_EOIL = (1 << line);
   else
      *IRQ_EOIH = (1 << (line - 32));
      
#elif defined(__CIRQ_MASK_REG_NR_3__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_EOIL = (1 << line);
   else if(line < 64)
      *IRQ_EOIM = (1 << (line - 32));
   else
      *IRQ_EOIH = (1 << (line - 64));

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
  *IRQ_EOIOH0 = (1 << line);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_EOIOH0 = (1 << line);
   else
      *IRQ_EOIOH1 = (1 << (line - 32));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_EOIOH0 = (1 << line);
   else if(line < 64)
      *IRQ_EOIOH1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_EOIOH2 = (1 << (line - 64));
   else
      *IRQ_EOIOH3 = (1 << (line - 96));

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_EOIOH0 = (1 << line);
   else if (line < 64)
      *IRQ_EOIOH1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_EOIOH2 = (1 << (line - 64));
   else if (line < 128)
      *IRQ_EOIOH3 = (1 << (line - 96));
   else
      *IRQ_EOIOH4 = (1 << (line - 128));

#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)

   if (line < 32)
      *IRQ_EOIL = (1 << line);
   else
      *IRQ_EOIH = (1 << (line - 32));

#else

   *IRQ_EOI = (1 << line);

#endif 

   RestoreIRQ(savedmask);
}

/*************************************************************************
* FUNCTION
*  IRQMask
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
void IRQMask(kal_uint8 code)
{
   kal_uint8 line;
   kal_uint32 savedMask;

   /* get the return address */
   if (code == irq_mask_monitor_idx)
   {
      GET_RETURN_ADDRESS(irq_mask_caller);
   }
#if defined(MT6255)    /* Debug code for AST and AST. Should be phased out by W12.26 */
   else if(code == IRQ_AST_DATAIN_CODE)
   {
       GET_RETURN_ADDRESS(irq_mask_caller_ast);
   }
#endif   
   
#if defined(__CIRQ_DIE2DIE__)   
   if(IS_ADIE_IRQ_CODE(code))
   {
       ADIE_IRQMask(IRQ_CODE_GLB_TO_ADIE(code));
   
       return;
   }
#endif

   line = IRQCode2Line[code];

   /*
    * [Important]
    * IRQ mask will be valid around 2T ~ 3T after register is written. 
    * To ensure IRQ is turned off thoroughly, I bit must be disabled in 
    * advanced; otherwise, IRQ may be triggered unexpectedly.
    */
   savedMask = LockIRQ();
   
   ASSERT(INTMaskCount[line]==0 || INTMaskCount[line]==255);
   
   INTMaskCount[line] = 255;
    
#if defined(__CIRQ_MASK_REG_NR_2__)

   if (line < 32)
      *IRQ_MASK_SETL = (1 << line);
   else
      *IRQ_MASK_SETH = (1 << (line - 32));
   
#elif defined(__CIRQ_MASK_REG_NR_3__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SETL = (1 << line);
   else if(line < 64)
      *IRQ_MASK_SETM = (1 << (line - 32));
   else
      *IRQ_MASK_SETH = (1 << (line - 64));

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)
    
   ASSERT(code<NUM_IRQ_SOURCES);
  *IRQ_MASK_SET0= (1 << line);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
    
   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0= (1 << line);
   else
      *IRQ_MASK_SET1 = (1 << (line - 32));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
    
   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0= (1 << line);
   else if(line < 64)
      *IRQ_MASK_SET1 = (1 << (line - 32));
   else if(line < 96)
      *IRQ_MASK_SET2 = (1 << (line - 64));
   else
      *IRQ_MASK_SET3 = (1 << (line - 96));

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
    
   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0= (1 << line);
   else if (line < 64)
      *IRQ_MASK_SET1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_SET2 = (1 << (line - 64));
   else if (line < 128)
      *IRQ_MASK_SET3 = (1 << (line - 96));
   else
      *IRQ_MASK_SET4 = (1 << (line - 128));

#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)

   if (line < 32)
      *IRQ_MASK_SETL = (1 << line);
   else
      *IRQ_MASK_SETH = (1 << (line - 32));
   
#else

   *IRQ_MASK_SET = (1 << line);
   
#endif

   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. The CIRQ may *
   * not be really masked after return from this function and may   *
   * cause race conidition. The work around is to read one dummy    *
   * register. The mask operation will take effect after 3T and     *
   * it will complete before the dummy read transaction. Therefore  *
   * the mask operation completes before return from this function. *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    IRQ_F2S_DUMMY_READ();
#endif

   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  IRQMaskAll
*
* DESCRIPTION
*  Mask all of the interrupts
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void IRQMaskAll(void)
{
   kal_uint8 idx;

   for (idx=0;idx<NUM_IRQ_LINES;idx++) 
      IRQMask(idx);
}

/*************************************************************************
* FUNCTION
*  IRQMask_Status
*
* DESCRIPTION
*  query the interrupt code status
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 IRQMask_Status(kal_uint8 code)
{
   kal_uint8 line;
   line = IRQCode2Line[code];

#if defined(__CIRQ_DIE2DIE__)
   if(IS_ADIE_IRQ_CODE(code))
   {
       return ADIE_IRQMask_Status(IRQ_CODE_GLB_TO_ADIE(code));
   }
#endif

#if defined(TK6516)
   return (*IRQ_MASK & (1<<code));
#elif defined(MT6516) && !defined(__APPLICATION_PROCESSOR__)
   return (*IRQ_MASK & (1<<code));
#elif defined(__CIRQ_MASK_REG_NR_2__)
   if (line < 32)
      return (*IRQ_MASKL & (1<<line));
   else
      return (*IRQ_MASKH & (1<<(line - 32)));
#elif defined(__CIRQ_MASK_REG_NR_3__)
   if (line < 32)
      return (*IRQ_MASKL & (1<<line));
   else if (line < 64)
      return (*IRQ_MASKH & (1<<(line - 32)));
   else
      return (*IRQ_MASKH & (1<<(line - 64)));
#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)
   return (*IRQ_MASK0 & (1<<line));
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   if (line < 32)
      return (*IRQ_MASK0 & (1<<line));
   else
      return (*IRQ_MASK1 & (1<<(line - 32)));
#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   if (line < 32)
      return (*IRQ_MASK0 & (1<<line));
   else if (line < 64)
      return (*IRQ_MASK1 & (1<<(line - 32)));
   else if (line < 96)
      return (*IRQ_MASK2 & (1<<(line - 64)));
   else
      return (*IRQ_MASK3 & (1<<(line - 96)));
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   if (line < 32)
      return (*IRQ_MASK0 & (1<<line));
   else if (line < 64)
      return (*IRQ_MASK1 & (1<<(line - 32)));
   else if (line < 96)
      return (*IRQ_MASK2 & (1<<(line - 64)));
   else if (line < 128)
      return (*IRQ_MASK3 & (1<<(line - 96)));
   else
      return (*IRQ_MASK4 & (1<<(line - 128)));
#else
   return 0;
#endif
}

/*************************************************************************
* FUNCTION
*  IRQUnmask
*
* DESCRIPTION
*  Unmask certain interrupt source.
*
* PARAMETERS
*  Interrupt source to be unmasked, it is indexed via IRQCode2Line.
*
* RETURNS
*
*************************************************************************/
void IRQUnmask(kal_uint8 code)
{
   kal_uint8 line;
   kal_uint32 savedMask;

   // No IRQ unmasking allowed if exception handler is running
   if(INT_QueryExceptionStatus()==KAL_TRUE)
   {
      return;
   }

   /* get the return address */
   if (code == irq_unmask_monitor_idx)
   {
      GET_RETURN_ADDRESS(irq_unmask_caller);
   }
#if defined(MT6255)    /* Debug code for AST. Should be phased out by W12.26 */   
   else if (code == IRQ_AST_DATAIN_CODE)
   {
       GET_RETURN_ADDRESS(irq_unmask_caller_ast);
   }
#endif   

#if defined(__CIRQ_DIE2DIE__)
   if(IS_ADIE_IRQ_CODE(code))
   {
       ADIE_IRQUnmask(IRQ_CODE_GLB_TO_ADIE(code));
       
      return;
   }
#endif

   line = IRQCode2Line[code];
   
   savedMask = LockIRQ();
   
   ASSERT(INTMaskCount[line]==0 || INTMaskCount[line]==255);
   
   INTMaskCount[line]= 0;

#if defined(__CIRQ_MASK_REG_NR_2__)

   if (line < 32)
      *IRQ_MASK_CLRL = (1 << line);
   else
      *IRQ_MASK_CLRH = (1 << (line - 32));
	
#elif defined(__CIRQ_MASK_REG_NR_3__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLRL = (1 << line);
   else if(line < 64)
      *IRQ_MASK_CLRM = (1 << (line - 32));
   else
      *IRQ_MASK_CLRH = (1 << (line - 64));

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
  *IRQ_MASK_CLR0 = (1 << line);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else
      *IRQ_MASK_CLR1 = (1 << (line - 32));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else if(line < 64)
      *IRQ_MASK_CLR1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_CLR2 = (1 << (line - 64));
   else
	*IRQ_MASK_CLR3 = (1 << (line - 96));

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else if (line < 64)
      *IRQ_MASK_CLR1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_CLR2 = (1 << (line - 64));
   else if (line < 128)
      *IRQ_MASK_CLR3 = (1 << (line - 96));
   else
      *IRQ_MASK_CLR4 = (1 << (line - 128));

#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)

   if (line < 32)
      *IRQ_MASK_CLRL = (1 << line);
   else
      *IRQ_MASK_CLRH = (1 << (line - 32));
	
#else

      *IRQ_MASK_CLR = (1 << line);
	
#endif

   RestoreIRQ(savedMask);
}

#ifndef __INTSRAM_SHRINKING__
#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE"
#endif /* __MTK_TARGET__ */
#endif

/*************************************************************************
* FUNCTION
*  IRQ_Status
*
* DESCRIPTION
*  query the value of interrupt status register
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 IRQ_Status(void)
{
   kal_uint32 irqx;

#ifdef __CIRQ_DESIGN_NEW__      
   irqx = *IRQ_STA2;               
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6268H)
   /* To temporarily avoid the problem on AHB. */
   *SLEEP_CON &= 0xfffc;  
   
   irqx = *IRQ_STS2;

#elif defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B)|| defined(MT6268A) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6270A)
   irqx = *IRQ_STS2;

#elif defined(MT6219) || defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6225) || defined(MT6223) || defined(MT6227D) || defined(MT6226D) || defined(MT6223P)
   /* To temporarily avoid the problem on AHB. */
   *SLEEP_CON &= 0xfffc;     
   
   irqx = *IRQ_STS2 & 0x11f;
   if ( irqx & 0x100 )
      return (kal_uint32)(-1);
      
   irqx &= 0x1f;

#elif defined(MT6253T)
   irqx = *IRQ_STS2 & 0x11f;
   if ( irqx & 0x100 )
      return (kal_uint32)(-1);
   
   irqx &= 0x1f;

#elif defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
   irqx = *IRQ_STS2 & 0x13f;
   if ( irqx & 0x100 )
      return (kal_uint32)(-1);
	
   irqx &= 0x3f;

#elif defined(TK6516)   
   irqx = *IRQ_STS2; //do nothing so far

#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)
   irqx = *IRQ_STS2;

#elif defined(MT6516) && !defined(__APPLICATION_PROCESSOR__)
   irqx = *IRQ_STS2; //do nothing so far

#else
   irqx = *IRQ_STS2 & 0xf;
   
#endif

   if ( (irqx&0x100) == 0x100 )
      return (kal_uint32)(-1);
   else 
      return (kal_uint32)(irqx&0xff);

}

#ifndef __INTSRAM_SHRINKING__
#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */
#endif

/*************************************************************************
* FUNCTION
*  FIQ_isValid
*
* DESCRIPTION
*  query if the FIQ is valide
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 FIQ_isValid(void)
{
   kal_uint32 fiqx;

#ifdef __CIRQ_DESIGN_NEW__      
   fiqx = *FIQ_STA2;

   if ( (fiqx&0x100) == 0x100 )
      return NULL;
   else 
      return (fiqx&0xff);

#else
   fiqx = *FIQ_SEL;
   return (fiqx&0x3f);

#endif

}

/*************************************************************************
* FUNCTION
*  CTIRQ1_2_Mask_Status
*
* DESCRIPTION
*  Get status of whether IRQs other than CTIRQ1/2 are all masked.
*
* IMPORTANT NOTICE
*
* PARAMETERS
*
* RETURNS
*  Current interrupt status of whether IRQs other than CTIRQ1/2 are all masked.
*
*************************************************************************/
kal_uint32 CTIRQ1_2_Mask_Status(void)
{
   kal_uint32 savedMask, irq_ctirq1_2_mask_status_ret;

   savedMask = LockIRQ();
   irq_ctirq1_2_mask_status_ret = irq_ctirq1_2_mask_status;
   RestoreIRQ(savedMask);

   return irq_ctirq1_2_mask_status_ret;
}

/*************************************************************************
* FUNCTION
*  CTIRQ1_2_MaskAll
*
* DESCRIPTION
*  Mask all of the interrupts except CTIRQ1 and CTIRQ2.

* IMPORTANT NOTICE
*  This is specific for L1, and must be used in paired with 
*  CTIRQ1_2_MaskAll().
*
* PARAMETERS
*
* RETURNS
*  Current interrupt mask value.
*
*************************************************************************/
void CTIRQ1_2_MaskAll(IRQ_MASK_VALUE_T *val)
{
     kal_uint32 savedMask;

   if (val == NULL)
      ASSERT(0);
      
   savedMask = LockIRQ();

   irq_ctirq1_2_mask_status++;

#if defined(MT6270A)
   val->irq_maskl = *IRQ_MASKL;
   val->irq_maskh = *IRQ_MASKH;
   *IRQ_MASKL = val->irq_maskl | CTIRQ1_2_MaskValue.irq_maskl;
   *IRQ_MASKH = val->irq_maskh | CTIRQ1_2_MaskValue.irq_maskh;

#elif defined(__CIRQ_MASK_REG_NR_2__)
   val->irq_maskl = *IRQ_MASKL;
   val->irq_maskh = *IRQ_MASKH;
   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKL &= ~(1 << IRQCode2Line[IRQ_CTIRQ1_CODE]);
   *IRQ_MASKL &= ~(1 << IRQCode2Line[IRQ_CTIRQ2_CODE]);

#elif defined(__CIRQ_MASK_REG_NR_3__)
   val->irq_maskl = *IRQ_MASKL;
   val->irq_maskm = *IRQ_MASKM; 
   val->irq_maskh = *IRQ_MASKH;
   *IRQ_MASKL = val->irq_maskl | CTIRQ1_2_MaskValue.irq_maskl;
   *IRQ_MASKM = val->irq_maskm | CTIRQ1_2_MaskValue.irq_maskm;
   *IRQ_MASKH = val->irq_maskh | CTIRQ1_2_MaskValue.irq_maskh;      

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | CTIRQ1_2_MaskValue.irq_mask0);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | CTIRQ1_2_MaskValue.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | CTIRQ1_2_MaskValue.irq_mask1);

#if defined(MT6255)    /* debug code for AST. should be phased-out by W12.26 */
    if(irq_ctirq1_2_mask_status - 1 == 0)
    {
        irq_ctirq1_2_mask[0] = val->irq_mask0;
        irq_ctirq1_2_mask[1] = val->irq_mask1;
    }
#endif

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   val->irq_mask2 = *IRQ_MASK2;
   val->irq_mask3 = *IRQ_MASK3;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | CTIRQ1_2_MaskValue.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | CTIRQ1_2_MaskValue.irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2 | CTIRQ1_2_MaskValue.irq_mask2);
   *IRQ_MASK_CLR3 = ~(val->irq_mask3 | CTIRQ1_2_MaskValue.irq_mask3);

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   val->irq_mask2 = *IRQ_MASK2;
   val->irq_mask3 = *IRQ_MASK3;
   val->irq_mask4 = *IRQ_MASK4;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_SET4 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | CTIRQ1_2_MaskValue.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | CTIRQ1_2_MaskValue.irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2 | CTIRQ1_2_MaskValue.irq_mask2);
   *IRQ_MASK_CLR3 = ~(val->irq_mask3 | CTIRQ1_2_MaskValue.irq_mask3);
   *IRQ_MASK_CLR4 = ~(val->irq_mask4 | CTIRQ1_2_MaskValue.irq_mask4);

#else
   val->irq_maskl = *IRQ_MASK;
   val->irq_maskh = 0;
   *IRQ_MASK = 0xffffffff;
   *IRQ_MASK &= ~(1 << IRQCode2Line[IRQ_CTIRQ1_CODE]);
   *IRQ_MASK &= ~(1 << IRQCode2Line[IRQ_CTIRQ2_CODE]);

#endif
      
#if defined(MT6228)
   *IRQ_MASKH = 0xff;      

#elif defined(MT6229) || defined(MT6230) 
   *IRQ_MASKH = 0x1ff;      

#elif defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B)
   *IRQ_MASKH = 0x3ffff;      

#elif defined(MT6268T) || defined(MT6268H)  || defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6236) || defined(MT6236B)
   *IRQ_MASKH = 0xffffffff;      

#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)
   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKH = 0xffffffff;   

#endif

   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. The CIRQ may *
   * not be really masked after return from this function and may   *
   * cause race conidition. The workaround is to read one dummy     *
   * register. The mask operation will take effect after 3T and     *
   * it will complete before the dummy read transaction. Therefore  *
   * the mask operation completes before return from this function. *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    IRQ_F2S_DUMMY_READ();
#endif

   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  CTIRQ1_2_Restore
*
* DESCRIPTION
*  Restore interrupt mask saved by CTIRQ1_2_MaskAll().

* IMPORTANT NOTICE
*  This is specific for L1, and must be used in paired with 
*  CTIRQ1_2_MaskAll().
*
* PARAMETERS
*  Interrupt mask to be restored
*
* RETURNS
*
*************************************************************************/
void CTIRQ1_2_Restore(IRQ_MASK_VALUE_T *val)
{
   kal_uint32 savedMask;

   savedMask = LockIRQ();

   irq_ctirq1_2_mask_status--;

#if defined(__CIRQ_MASK_REG_NR_2__)
   *IRQ_MASKH = val->irq_maskh;
   *IRQ_MASKL = val->irq_maskl;

#elif defined(__CIRQ_MASK_REG_NR_3__)
   *IRQ_MASKH = val->irq_maskh;
   *IRQ_MASKM = val->irq_maskm;
   *IRQ_MASKL = val->irq_maskl;

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1);

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2);
   *IRQ_MASK_CLR3 = ~(val->irq_mask3);

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_SET4 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2);
   *IRQ_MASK_CLR3 = ~(val->irq_mask3);
   *IRQ_MASK_CLR4 = ~(val->irq_mask4);

#else
   *IRQ_MASK = val->irq_maskl;

#endif
      
   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  SleepMode_MaskAll
*
* DESCRIPTION
*  This function is used to mask all interrupt source except the wakeup interrupts

* IMPORTANT NOTICE
*  This is specific for L1, and must be used in paired with 
*  SleepMode_RestoreAll().
*
* PARAMETERS
*  A space for saving previous interrupt mask
*
* RETURNS
*
*************************************************************************/
void SleepMode_MaskAll(IRQ_MASK_VALUE_T *val)
{
   kal_uint32 savedMask;

   savedMask = LockIRQ();

#if defined(__CIRQ_MASK_REG_NR_2__)
   val->irq_maskl = *IRQ_MASKL;
   val->irq_maskh = *IRQ_MASKH;
   *IRQ_MASKL = SleepModeMask.irq_maskl;
   *IRQ_MASKH = SleepModeMask.irq_maskh;

#elif defined(__CIRQ_MASK_REG_NR_3__)
   val->irq_maskl = *IRQ_MASKL;
   val->irq_maskm = *IRQ_MASKM; 
   val->irq_maskh = *IRQ_MASKH;
   *IRQ_MASKL = SleepModeMask.irq_maskl;
   *IRQ_MASKM = SleepModeMask.irq_maskm;
   *IRQ_MASKH = SleepModeMask.irq_maskh;

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | SleepModeMask.irq_mask0);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | SleepModeMask.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | SleepModeMask.irq_mask1);

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   val->irq_mask2 = *IRQ_MASK2;
   val->irq_mask3 = *IRQ_MASK3;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | SleepModeMask.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | SleepModeMask.irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2 | SleepModeMask.irq_mask2);
   *IRQ_MASK_CLR3 = ~(val->irq_mask3 | SleepModeMask.irq_mask3);

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   val->irq_mask2 = *IRQ_MASK2;
   val->irq_mask3 = *IRQ_MASK3;
   val->irq_mask4 = *IRQ_MASK4;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_SET4 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | SleepModeMask.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | SleepModeMask.irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2 | SleepModeMask.irq_mask2);
   *IRQ_MASK_CLR3 = ~(val->irq_mask3 | SleepModeMask.irq_mask3);
   *IRQ_MASK_CLR4 = ~(val->irq_mask4 | SleepModeMask.irq_mask4);

#elif (defined(MT6516) && !defined(__APPLICATION_PROCESSOR__)) || defined(MT6253T)
   val->irq_maskl = *IRQ_MASK;
   val->irq_maskh = 0;
   *IRQ_MASK = SleepModeMask.irq_maskl;

#else
   val->irq_maskl = *IRQ_MASK;
   val->irq_maskh = 0;
   *IRQ_MASK = SleepModeMask.irq_maskl;

#endif
   
#ifdef IRQ_RTR_SLT_CODE
   ASSERT(SleepModeMaskCount==0 || SleepModeMaskCount==2 || SleepModeMaskCount==3);
#else   
   ASSERT(SleepModeMaskCount==0 || SleepModeMaskCount==2 );
#endif

   SleepModeMaskCount = 1;
   
   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. The CIRQ may *
   * not be really masked after return from this function and may   *
   * cause race conidition. The workaround is to read one dummy     *
   * register. The mask operation will take effect after 3T and     *
   * it will complete before the dummy read transaction. Therefore  *
   * the mask operation completes before return from this function. *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    IRQ_F2S_DUMMY_READ();
#endif
   
   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  SleepMode_RestoreAll
*
* DESCRIPTION
*  This function is used to restore the previous interrupt 
*  mask according the input parameter
*
* IMPORTANT NOTICE
*  This is specific for L1, and must be used in paired with 
*  SleepMode_MaskAll().
*
* PARAMETERS
*  A space for saving previous interrupt mask
*
* RETURNS
*
*************************************************************************/
void SleepMode_RestoreAll(IRQ_MASK_VALUE_T *val)
{
   kal_uint32 savedMask;

   savedMask = LockIRQ();

   if(SleepModeMaskCount == 1)
   {
#if defined(__CIRQ_MASK_REG_NR_2__)
      *IRQ_MASKH = val->irq_maskh;
      *IRQ_MASKL = val->irq_maskl;

#elif defined(__CIRQ_MASK_REG_NR_3__)
      *IRQ_MASKH = val->irq_maskh;
      *IRQ_MASKM = val->irq_maskm;
      *IRQ_MASKL = val->irq_maskl;

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)
      *IRQ_MASK_SET0 = 0xffffffff;
      *IRQ_MASK_CLR0 = ~(val->irq_mask0);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
      *IRQ_MASK_SET0 = 0xffffffff;
      *IRQ_MASK_SET1 = 0xffffffff;
      *IRQ_MASK_CLR0 = ~(val->irq_mask0);
      *IRQ_MASK_CLR1 = ~(val->irq_mask1);

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
      *IRQ_MASK_SET0 = 0xffffffff;
      *IRQ_MASK_SET1 = 0xffffffff;
      *IRQ_MASK_SET2 = 0xffffffff;
      *IRQ_MASK_SET3 = 0xffffffff;
      *IRQ_MASK_CLR0 = ~(val->irq_mask0);
      *IRQ_MASK_CLR1 = ~(val->irq_mask1);
      *IRQ_MASK_CLR2 = ~(val->irq_mask2);
      *IRQ_MASK_CLR3 = ~(val->irq_mask3);

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
      *IRQ_MASK_SET0 = 0xffffffff;
      *IRQ_MASK_SET1 = 0xffffffff;
      *IRQ_MASK_SET2 = 0xffffffff;
      *IRQ_MASK_SET3 = 0xffffffff;
      *IRQ_MASK_SET4 = 0xffffffff;
      *IRQ_MASK_CLR0 = ~(val->irq_mask0);
      *IRQ_MASK_CLR1 = ~(val->irq_mask1);
      *IRQ_MASK_CLR2 = ~(val->irq_mask2);
      *IRQ_MASK_CLR3 = ~(val->irq_mask3);
      *IRQ_MASK_CLR4 = ~(val->irq_mask4);

#elif (defined(MT6516) && !defined(__APPLICATION_PROCESSOR__)) || defined(MT6253T)
   *IRQ_MASK = val->irq_maskl;

#else
   *IRQ_MASK = val->irq_maskl;

#endif
   }

#ifdef IRQ_RTR_SLT_CODE
   ASSERT( SleepModeMaskCount == 1 || SleepModeMaskCount == 2);
#else
   ASSERT( SleepModeMaskCount == 1);
#endif

   SleepModeMaskCount++;
   RestoreIRQ(savedMask);

}


/*************************************************************************
* FUNCTION
*  IRQSensitivity
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
void IRQSensitivity(kal_uint8 code, kal_bool edge)
{
   kal_uint8 line;

#if defined(__CIRQ_DIE2DIE__)
   if(IS_ADIE_IRQ_CODE(code))
   {
       ADIE_IRQSensitivity(IRQ_CODE_GLB_TO_ADIE(code), edge);
   
       return;
   }
#endif

   line = IRQCode2Line[code];

#if defined(__CIRQ_MASK_REG_NR_2__)

   if (edge != KAL_FALSE) 
   {
      /* it is an edge sensitive interrupt */
      if (line < 32)
         *IRQ_SENSL &= (~(1 << line));
      else
         *IRQ_SENSH &= (~(1 << (line - 32)));
   } 
   else 
   {
      /* level sensitive interrupt */
      if (line < 32)
         *IRQ_SENSL |= (1 << line);
      else
         *IRQ_SENSH |= (1 << (line - 32));
   }
         
#elif defined(__CIRQ_MASK_REG_NR_3__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (edge != KAL_FALSE) 
   {
      /* it is an edge sensitive interrupt */
      if (line < 32)
         *IRQ_SENSL &= (~(1 << line));
      else if(line < 64)
         *IRQ_SENSM &= (~(1 << (line - 32)));
      else
         *IRQ_SENSH &= (~(1 << (line - 64)));
   } 
   else 
   {
      /* level sensitive interrupt */
      if (line < 32)
         *IRQ_SENSL |= (1 << line);
      else if(line < 64)
         *IRQ_SENSM |= (1 << (line - 32));
      else
         *IRQ_SENSH |= (1 << (line - 64));
   }

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (edge != KAL_FALSE) 
   {
      /* it is an edge sensitive interrupt */
     *IRQ_SENS_CLR0 = (1 << line);
   } 
   else 
   {
      /* level sensitive interrupt */
     *IRQ_SENS_SET0 = (1 << line);
   }

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (edge != KAL_FALSE) 
   {
      /* it is an edge sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_CLR0 = (1 << line);
      else
         *IRQ_SENS_CLR1 = (1 << (line - 32));
   } 
   else 
   {
      /* level sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_SET0 = (1 << line);
      else
         *IRQ_SENS_SET1 = (1 << (line - 32));
   }

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (edge != KAL_FALSE) 
   {
      /* it is an edge sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_CLR0 = (1 << line);
      else if(line < 64)
         *IRQ_SENS_CLR1 = (1 << (line - 32));
      else if (line < 96)
         *IRQ_SENS_CLR2 = (1 << (line - 64));
      else
         *IRQ_SENS_CLR3 = (1 << (line - 96));
   } 
   else 
   {
      /* level sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_SET0 = (1 << line);
      else if(line < 64)
         *IRQ_SENS_SET1 = (1 << (line - 32));
      else if (line < 96)
         *IRQ_SENS_SET2 = (1 << (line - 64));
      else
         *IRQ_SENS_SET3 = (1 << (line - 96));
   }

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (edge != KAL_FALSE) 
   {
      /* it is an edge sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_CLR0 = (1 << line);
      else if (line < 64)
         *IRQ_SENS_CLR1 = (1 << (line - 32));
      else if (line < 96)
         *IRQ_SENS_CLR2 = (1 << (line - 64));
      else if (line < 128)
         *IRQ_SENS_CLR3 = (1 << (line - 96));
      else
         *IRQ_SENS_CLR4 = (1 << (line - 128));
   } 
   else 
   {
      /* level sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_SET0 = (1 << line);
      else if(line < 64)
         *IRQ_SENS_SET1 = (1 << (line - 32));
      else if (line < 96)
         *IRQ_SENS_SET2 = (1 << (line - 64));
      else if (line < 128)
         *IRQ_SENS_SET3 = (1 << (line - 96));
      else
         *IRQ_SENS_SET4 = (1 << (line - 128));
   }

#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)

   if (edge != KAL_FALSE) 
   {
      /* it is an edge sensitive interrupt */
      if (line < 32)
         *IRQ_SENSL &= (~(1 << line));
      else
         *IRQ_SENSH &= (~(1 << (line - 32)));
   } 
   else 
   {
      /* level sensitive interrupt */
      if (line < 32)
         *IRQ_SENSL |= (1 << line);
      else
         *IRQ_SENSH |= (1 << (line - 32));
   }
   
#else
   
   if (edge != KAL_FALSE) 
   {   /* it is an edge sensitive interrupt */
      *IRQ_SENS &= (~(1 << line));
   } 
   else 
   {   /* level sensitive interrupt */
      *IRQ_SENS |= (1 << line);
   }
   
#endif 
}

/*************************************************************************
* FUNCTION
*  SetMaskValue
*
* DESCRIPTION
*  Use internally, setting data structure of IRQ_MASK_VALUE
*
* PARAMETERS
*  
*
* RETURNS
*
*************************************************************************/
void SetMaskValue(IRQ_MASK_VALUE_T *val, kal_uint8 code)
{
   kal_uint8 line;

   line = IRQCode2Line[code];
   ASSERT(code<NUM_IRQ_SOURCES);

#if defined(__CIRQ_MASK_REG_NR_2__)
   if (line < 32)
      val->irq_maskl &= ~(1 << line);
   else
      val->irq_maskh &= ~(1 << (line - 32));

#elif defined(__CIRQ_MASK_REG_NR_3__)
   if (line < 32)
      val->irq_maskl &= ~(1 << line);
   else if(line < 64)
      val->irq_maskm &= ~(1 << (line - 32));
   else
      val->irq_maskh &= ~(1 << (line - 64));

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)
   val->irq_mask0 &= ~(1 << line);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   if (line < 32)
      val->irq_mask0 &= ~(1 << line);
   else
      val->irq_mask1 &= ~(1 << (line - 32));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   if (line < 32)
      val->irq_mask0 &= ~(1 << line);
   else if (line < 64)
      val->irq_mask1 &= ~(1 << (line - 32));
   else if (line < 96)
      val->irq_mask2 &= ~(1 << (line - 64));
   else
      val->irq_mask3 &= ~(1 << (line - 96));

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   if (line < 32)
      val->irq_mask0 &= ~(1 << line);
   else if (line < 64)
      val->irq_mask1 &= ~(1 << (line - 32));
   else if (line < 96)
      val->irq_mask2 &= ~(1 << (line - 64));
   else if (line < 128)
      val->irq_mask3 &= ~(1 << (line - 96));
   else
      val->irq_mask4 &= ~(1 << (line - 128));

#elif (defined(MT6516) && !defined(__APPLICATION_PROCESSOR__)) || defined(MT6253T)
   val->irq_maskl &= ~(1 << line);

#else
   if (line < 32)
      val->irq_maskl &= ~(1 << line);
   else
      val->irq_maskh &= ~(1 << (line - 32));

#endif
   
}

/*************************************************************************
* FUNCTION
*  MaskValueInit
*
* DESCRIPTION
*  Initialize Global data
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*************************************************************************/
void MaskValueInit()
{
#if defined(MT6270A)
   SleepModeMask.irq_maskl = 0xffffffff;
   SleepModeMask.irq_maskh = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_maskl = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_maskh = 0xffffffff;

#elif defined(MT6238) || defined(MT6239)
   SleepModeMask.irq_maskl = 0xffffffff;
   SleepModeMask.irq_maskh = 0x3ffff;

#elif defined(__CIRQ_MASK_REG_NR_2__)
   SleepModeMask.irq_maskl = 0xffffffff;
   SleepModeMask.irq_maskh = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_3__)
   SleepModeMask.irq_maskl = 0xffffffff;
   SleepModeMask.irq_maskm = 0xffffffff;
   SleepModeMask.irq_maskh = 0xff;
   CTIRQ1_2_MaskValue.irq_maskl = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_maskm = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_maskh = 0xff;

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)
   SleepModeMask.irq_mask0 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask0 = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   SleepModeMask.irq_mask0 = 0xffffffff;
   SleepModeMask.irq_mask1 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask0 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask1 = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   SleepModeMask.irq_mask0 = 0xffffffff;
   SleepModeMask.irq_mask1 = 0xffffffff;
   SleepModeMask.irq_mask2 = 0xffffffff;
   SleepModeMask.irq_mask3 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask0 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask1 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask2 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask3 = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   SleepModeMask.irq_mask0 = 0xffffffff;
   SleepModeMask.irq_mask1 = 0xffffffff;
   SleepModeMask.irq_mask2 = 0xffffffff;
   SleepModeMask.irq_mask3 = 0xffffffff;
   SleepModeMask.irq_mask4 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask0 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask1 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask2 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask3 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask4 = 0xffffffff;

#elif (defined(MT6516) && !defined(__APPLICATION_PROCESSOR__)) || defined(MT6253T)
   SleepModeMask.irq_maskl = 0xffffffff;

#else
   SleepModeMask.irq_maskl = 0xffffffff;
   SleepModeMask.irq_maskh = 0;

#endif

#ifdef IRQ_RTR_SLT_CODE
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_RTR_SLT_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_AI_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_PI_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_SEARCHER_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_TFCI_0_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_TFCI_1_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_RXBRP_CC0_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_RXBRP_CC1_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_RXBRP_CCB_CODE);
#endif

#ifdef IRQ_WTIMER_CODE
   SetMaskValue(&SleepModeMask,IRQ_WTIMER_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_WTIMER_CODE);
#endif

#ifdef IRQ_OSTIMER_ARM_CODE
   SetMaskValue(&SleepModeMask,IRQ_OSTIMER_ARM_CODE);
#endif

   SetMaskValue(&SleepModeMask,IRQ_TDMA_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_CTIRQ1_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_CTIRQ2_CODE);
}

/*************************************************************************
* FUNCTION
*  initINTR
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
void initINTR(void)
{
   kal_uint8 idx;

   /* determine the mapping between interrupt code and line */
   for (idx=0;idx<NUM_IRQ_LINES;idx++)
      IRQCode2Line[irqLine[idx]] = idx;

   MaskValueInit();

   kal_mem_set(INTMaskCount, 0, sizeof(INTMaskCount));

   /* mask all interrupt events */
   IRQDirectMaskAll();

   /* assign IRQ Selection Registers */
   IRQSel();
   
   /* clear all pending interrupts */
   IRQClearAllInt();

#if defined(__ENABLE_SW_TRIGGER_INTERRUPT__)
   /* Initialize SW Interrupt Counter*/
   for(idx=0;idx<SW_HANDLE_END- NUM_IRQ_SOURCES;idx++)
   {
      SW_INT_Counter[idx]=0;
   }
#endif

#if defined(__CIRQ_DIE2DIE__)
    ADIE_initINTR();
#endif
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
/*************************************************************************
* FUNCTION
*  SetINTMask
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
void SetINTMask(kal_uint8 code)
{
   kal_uint8 line;
   kal_uint32 savedMask;

#if defined(__CIRQ_DIE2DIE__)
   if(IS_ADIE_IRQ_CODE(code))
   {
       ADIE_SetINTMask(IRQ_CODE_GLB_TO_ADIE(code));
   
       return;
   }
#endif   

   line = IRQCode2Line[code];

   /*
    * [Important]
    * IRQ mask will be valid around 2T ~ 3T after register is written. 
    * To ensure IRQ is turned off thoroughly, I bit must be disabled in 
    * advanced; otherwise, IRQ may be triggered unexpectedly.
    */
   
   savedMask = LockIRQ();
   
   ASSERT(INTMaskCount[line]<254); 
    
   if(++INTMaskCount[line]==1)
   {
#if defined(__CIRQ_MASK_REG_NR_2__)

   if (line < 32)
      *IRQ_MASK_SETL = (1 << line);
   else
      *IRQ_MASK_SETH = (1 << (line - 32));
   
#elif defined(__CIRQ_MASK_REG_NR_3__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SETL = (1 << line);
   else if(line < 64)
      *IRQ_MASK_SETM = (1 << (line - 32));
   else
      *IRQ_MASK_SETH = (1 << (line - 64));

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   *IRQ_MASK_SET0 = (1 << line);
   
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0 = (1 << line);
   else
      *IRQ_MASK_SET1 = (1 << (line - 32));
   
#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0 = (1 << line);
   else if(line < 64)
      *IRQ_MASK_SET1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_SET2 = (1 << (line - 64));
   else
      *IRQ_MASK_SET3 = (1 << (line - 96));
   
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0 = (1 << line);
   else if (line < 64)
      *IRQ_MASK_SET1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_SET2 = (1 << (line - 64));
   else if (line < 128)
      *IRQ_MASK_SET3 = (1 << (line - 96));
   else
      *IRQ_MASK_SET4 = (1 << (line - 128));
   
#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)

   if (line < 32)
      *IRQ_MASK_SETL = (1 << line);
   else
      *IRQ_MASK_SETH = (1 << (line - 32));
   
#else

   *IRQ_MASK_SET = (1 << line);
   
#endif
   }

   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. The CIRQ may *
   * not be really masked after return from this function and may   *
   * cause race conidition. The workaround is to read one dummy     *
   * register. The mask operation will take effect after 3T and     *
   * it will complete before the dummy read transaction. Therefore  *
   * the mask operation completes before return from this function. *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    IRQ_F2S_DUMMY_READ();
#endif
   
   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  RestoreINTMask
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
void RestoreINTMask(kal_uint8 code)
{
   kal_uint8 line;
   kal_uint32 savedMask;

#if defined(__CIRQ_DIE2DIE__)
   if(IS_ADIE_IRQ_CODE(code))
   {
       ADIE_RestoreINTMask(IRQ_CODE_GLB_TO_ADIE(code));
   
       return;
   }
#endif   

   line = IRQCode2Line[code];
   
   savedMask = LockIRQ();
   
   ASSERT(INTMaskCount[line]>0 && INTMaskCount[line]<255); 

   if(--INTMaskCount[line] == 0)
   {
#if defined(__CIRQ_MASK_REG_NR_2__)

   if (line < 32)
      *IRQ_MASK_CLRL = (1 << line);
   else
      *IRQ_MASK_CLRH = (1 << (line - 32));
	
#elif defined(__CIRQ_MASK_REG_NR_3__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLRL = (1 << line);
   else if(line < 64)
      *IRQ_MASK_CLRM = (1 << (line - 32));
   else
      *IRQ_MASK_CLRH = (1 << (line - 64));

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   *IRQ_MASK_CLR0 = (1 << line);
	
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else
      *IRQ_MASK_CLR1 = (1 << (line - 32));
	
#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else if (line < 64)
      *IRQ_MASK_CLR1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_CLR2 = (1 << (line - 64));
   else
      *IRQ_MASK_CLR3 = (1 << (line - 96));
	
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else if (line < 64)
      *IRQ_MASK_CLR1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_CLR2 = (1 << (line - 64));
   else if (line < 128)
      *IRQ_MASK_CLR3 = (1 << (line - 96));
   else
      *IRQ_MASK_CLR4 = (1 << (line - 128));
	
#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)

   if (line < 32)
      *IRQ_MASK_CLRL = (1 << line);
   else
      *IRQ_MASK_CLRH = (1 << (line - 32));
	
#else

      *IRQ_MASK_CLR = (1 << line);
	
#endif
   }
   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  IRQ_SetSWRegister
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
void IRQ_SetSWRegister(kal_uint8 code)
{
   kal_uint32 savedMask;
   
#if defined(__CIRQ_DIE2DIE__)
   if(IS_ADIE_IRQ_CODE(code))
   {
      ADIE_IRQ_SetSWRegister(IRQ_CODE_GLB_TO_ADIE(code));

      return;
   }
#endif   
   
   savedMask = LockIRQ();

   ASSERT(code<NUM_IRQ_SOURCES);
   
#if defined(__CIRQ_MASK_REG_NR_2__)
   if (code < 32)
      *IRQ_SOFTL |= (1 << code);
   else
      *IRQ_SOFTH |= (1 << (code - 32));

#elif defined(__CIRQ_MASK_REG_NR_3__)
   if (code < 32)
      *IRQ_SOFTL |= (1 << code);
   else if(code < 64)
      *IRQ_SOFTM |= (1 << (code - 32));
   else
      *IRQ_SOFTH |= (1 << (code - 64));

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)
   *IRQ_SOFT_SET0 = (1 << code);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   if (code < 32)
      *IRQ_SOFT_SET0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_SET1 = (1 << (code - 32));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   if (code < 32)
      *IRQ_SOFT_SET0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_SET1 = (1 << (code - 32));
   else if (code < 96)
      *IRQ_SOFT_SET2 = (1 << (code - 64));
   else
     *IRQ_SOFT_SET3 = (1 << (code - 96));

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   if (code < 32)
      *IRQ_SOFT_SET0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_SET1 = (1 << (code - 32));
   else if (code < 96)
      *IRQ_SOFT_SET2 = (1 << (code - 64));
   else if (code < 128)
     *IRQ_SOFT_SET3 = (1 << (code - 96));
   else
     *IRQ_SOFT_SET4 = (1 << (code - 128));

#endif

   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  IRQ_ResetSWRegister
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
void IRQ_ResetSWRegister(kal_uint8 code)
{
   kal_uint32 savedMask;
   
#if defined(__CIRQ_DIE2DIE__)
   if(IS_ADIE_IRQ_CODE(code))
   {
      ADIE_IRQ_ResetSWRegister(IRQ_CODE_GLB_TO_ADIE(code));
            
      return;
   }
#endif   
   
   savedMask = LockIRQ();

   ASSERT(code<NUM_IRQ_SOURCES);

#if defined(__CIRQ_MASK_REG_NR_2__)
   if (code < 32)
      *IRQ_SOFTL &= ~(1 << code);
   else
      *IRQ_SOFTH &= ~(1 << (code - 32));

#elif defined(__CIRQ_MASK_REG_NR_3__)
   if (code < 32)
      *IRQ_SOFTL &= ~(1 << code);
   else if(code < 64)
      *IRQ_SOFTM &= ~(1 << (code - 32));
   else
      *IRQ_SOFTH &= ~(1 << (code - 64));

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)
   *IRQ_SOFT_CLR0 = (1 << code);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   if (code < 32)
      *IRQ_SOFT_CLR0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_CLR1 = (1 << (code - 32));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   if (code < 32)
      *IRQ_SOFT_CLR0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_CLR1 = (1 << (code - 32));
   else if (code < 96)
      *IRQ_SOFT_CLR2 = (1 << (code - 64));
   else
     *IRQ_SOFT_CLR3 = (1 << (code - 96));

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   if (code < 32)
      *IRQ_SOFT_CLR0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_CLR1 = (1 << (code - 32));
   else if (code < 96)
      *IRQ_SOFT_CLR2 = (1 << (code - 64));
   else if (code < 128)
     *IRQ_SOFT_CLR3 = (1 << (code - 96));
   else
     *IRQ_SOFT_CLR4 = (1 << (code - 128));

#endif
      
   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. The CIRQ may *
   * not be de-asserted after return from this function and may     *
   * cause race conidition. The workaround is to read one dummy     *
   * register. The de-assert operation will take effect after 3T    *
   * and it will complete before the dummy read transaction.        *
   * Therefore, the de-assert operation completes before return     *
   * from this function.                                            *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    IRQ_F2S_DUMMY_READ();
#endif
      
   RestoreIRQ(savedMask);
}

#if defined(__ENABLE_SW_TRIGGER_INTERRUPT__)

/*************************************************************************
* FUNCTION
*  Activate_LISR
*
* DESCRIPTION
*  This function activate SW interrupt lisr
*
* PARAMETERS
*  handle : handler of software trigger interrupt 
*
* RETURNS
*  none
*  
*************************************************************************/
void Activate_LISR(SW_CODE_HANDLE handle)
{
   kal_uint32 savedMask;
   kal_uint32 sw_int_i;
   
   ASSERT(handle >= NUM_IRQ_SOURCES);
   sw_int_i = (kal_uint32)handle - NUM_IRQ_SOURCES;
   ASSERT(sw_int_i < (SW_HANDLE_END - NUM_IRQ_SOURCES));

   savedMask = LockIRQ();
   
   SW_INT_Counter[sw_int_i]++;
   if(SW_INT_Counter[sw_int_i]==1)
      IRQ_SetSWRegister(SW_Code_Handle2Code[sw_int_i]);
   
   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  Deactivate_LISR
*
* DESCRIPTION
*  This function deactivate SW interrupt lisr
*
* PARAMETERS
*  handle : handler of software trigger interrupt 
*
* RETURNS
*  none
*  
*************************************************************************/
void Deactivate_LISR(SW_CODE_HANDLE handle)
{
   kal_uint32 savedMask;
   kal_uint32 sw_int_i;

   ASSERT(handle >= NUM_IRQ_SOURCES);
   sw_int_i = (kal_uint32)handle - NUM_IRQ_SOURCES;
   ASSERT(sw_int_i < (SW_HANDLE_END - NUM_IRQ_SOURCES));

   savedMask = LockIRQ();

   SW_INT_Counter[sw_int_i]--;
   if(SW_INT_Counter[sw_int_i]==0)
      IRQ_ResetSWRegister(SW_Code_Handle2Code[sw_int_i]);
   
   RestoreIRQ(savedMask);

}

#endif /* __ENABLE_SW_TRIGGER_INTERRUPT__ */

