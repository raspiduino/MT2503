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
 *   isrentry.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the IRQ service routines for all IRQ sources
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * Include header files.
 *******************************************************************************/

#include "reg_base.h"
#include "isrentry.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "dcl.h"
#include "drv_hisr.h"
#include "kal_internal_api.h"
#include "tst_lmu_hw.h"

#ifdef __SWDBG_SUPPORT__
#include "swdbg_hw.h"
#endif   /* __SWDBG_SUPPORT__ */
#include "emi_hw.h"
#include "emi_sw.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "us_timer.h"

/*************************************************************************
 * Define function prototypes and data structures.
 *************************************************************************/

void isrCTIRQ1(void);
extern kal_uint32 LockIRQ(void);
extern void RestoreIRQ(kal_uint32 irq);
extern kal_uint32 DisableIRQ(void);
extern void ReEnableIRQ(void);
extern void FIQClearInt(void);
extern void SYS_ClearInt(kal_uint8 code);
extern void SYS_ClearInt2(kal_uint8 irq_idx);

#ifndef L1_NOT_PRESENT
extern void L1I_FrameInterrupt( void );
extern kal_bool  L1I_Querry_Compensate_KAL_Timer( void );
#endif /* !L1_NOT_PRESENT */


extern kal_uint32 SA_LoggingIndex;
extern kal_bool SLA_IsLmuLogging(void);
extern void SLA_LoggingLISR(kal_uint32 ID);
extern void SLA_HookLogging(void);

#if defined(__TP_SUPPORT_TIMING_CHECK__)
extern kal_uint32 Thread_Protect_State;
extern kal_uint32 TP_Exclude_Start_Time;
#endif

/*************************************************************************
 * Define imported global data.
 *************************************************************************/

#if !defined(__NUCLEUS_VERSION_2__)
extern kal_uint32  TCD_Interrupt_Count;
#endif /* !__NUCLEUS_VERSION_2__ */

#if defined(__NUCLEUS_VERSION_2__)
extern void *TCD_Current_Thread;
#endif

extern kal_char *wake_tm_name;

#if defined(__CIRQ_DIE2DIE__)
/* declared for IRQ_Register_LISR() to registe IRQ on A-DIE */
extern kal_uint8 ADIE_IRQCode2Line[ADIE_NUM_IRQ_SOURCES];
#endif


extern const kal_uint8 irqLine[NUM_IRQ_LINES];


/*************************************************************************
 * Define global data.
 *************************************************************************/

static IntErrType FIQErrInfo;

#ifdef  IRQ_GPII_CODE
static kal_bool nIRQ_auto_unmask = KAL_TRUE;
static VOID_FUNC nIRQ_CallBack_Function;
#endif
#ifdef  IRQ_GPI_CODE
static kal_bool nFIQ_auto_unmask = KAL_TRUE;
static VOID_FUNC nFIQ_CallBack_Function;
#endif

#ifdef __MTK_TARGET__
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */


void       *processing_lisr = NULL;
kal_uint16 processing_irqx = IRQ_NOT_LISR_CONTEXT;
kal_uint32 processing_irqlr;
kal_uint32 processing_fiqlr;
kal_uint32 processing_irqCnt=0;

#if defined(MT6250) || defined(MT6260) || defined(__IRQ_LISR_DEBUG__)
/* time debug code. should be phased out by W12.26 */
kal_uint32 irq_dbg_time_leave_from_sleep;
kal_uint32 irq_dbg_time_enter_isr;
kal_uint32 irq_dbg_time_before_dcm_recovery;
kal_uint32 irq_dbg_time_after_dcm_recovery;
kal_uint32 irq_dbg_time_before_flash_ready;
kal_uint32 irq_dbg_time_after_flash_ready;
kal_uint32 irq_dbg_time_after_read_sta;
kal_uint32 irq_dbg_time_before_lisr;
#endif

#ifdef __MTK_TARGET__
#pragma arm section rwdata , rodata , zidata
#endif /* __MTK_TARGET__ */

#if !defined(NUM_IRQ_LINES)
#define NUM_IRQ_LINES     NUM_IRQ_SOURCES
#endif

#ifdef __CIRQ_DIE2DIE__
#define TOTAL_IRQ_NUM    (NUM_IRQ_LINES + ADIE_NUM_IRQ_LINES)
#else
#define TOTAL_IRQ_NUM    (NUM_IRQ_LINES)
#endif

#if defined(__MTK_TARGET__) && !defined(__LISR_TBL_IN_EXTRAM__)
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

irqlisr_entry lisr_dispatch_tbl[TOTAL_IRQ_NUM]; 

#if defined(__MTK_TARGET__) && !defined(__LISR_TBL_IN_EXTRAM__)
#pragma arm section rwdata , rodata , zidata
#endif /* __MTK_TARGET__ */


#if defined(__WAKEUP_IRQ_DEBUG__)
wkup_intr_log_t wkup_intr_log_buf[WKUP_LOG_BUF_MAX];
kal_uint32 wkup_intr_log_indx = WKUP_LOG_BUF_MAX;
wkup_timer_log_t wkup_timer_log_buf[WKUP_LOG_BUF_MAX];
kal_uint32 wkup_timer_log_indx = WKUP_LOG_BUF_MAX;
#endif  /* __WAKEUP_IRQ_DEBUG__ */

#ifdef __DEMAND_PAGING_PERFORMANCE_PROFILING__
extern void demp_preempt_time_start();
#endif

#ifdef __CIRQ_DIE2DIE__
extern void ADIE_isrC_Main();
#endif

/*************************************************************************
* FUNCTION
*  IRQ_LISR_Init
*
* DESCRIPTION
*   This function implement IRQ's LISR (Low-level Interrupt Service Routine)
*  Table initialization.
*
* CALLS
*
* CALL BY
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
void IRQ_LISR_Init()
{
   kal_uint32 i;

   for (i = TOTAL_IRQ_NUM; i != 0; i--) {
      IRQ_Register_LISR(i - 1, IRQ_Default_LISR, "NULL handler");
   }
      
   /* Set CTIRQ1 handler */
   IRQ_Register_LISR(IRQ_CTIRQ1_CODE, isrCTIRQ1,"CTIRQ1");

#if defined(__CIRQ_DIE2DIE__)
   /* register A-DIE call back function */
   IRQ_Register_LISR(IRQ_DIE2DIE_CODE, ADIE_isrC_Main, "ADIE LISR");
   IRQSensitivity(IRQ_DIE2DIE_CODE, KAL_FALSE);
   IRQUnmask(IRQ_DIE2DIE_CODE);
#endif
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*************************************************************************
* FUNCTION
*  IRQ_Register_LISR
*
* DESCRIPTION
*   This function implement method to register IRQ's LISR.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  irqvector   -  vector number to register
*  reg_lisr    -  register LISR's handler
*  description -  LISR's description pointer to be saved.
*     Remember, the routine won't duplicate the description,
*     therefore, caller shouldn't free the description.
*
* RETURNS
*
*************************************************************************/
void IRQ_Register_LISR(kal_uint32 code, void (*reg_lisr)(void), char* description)
{
   kal_uint32 savedMask;
   kal_uint32 irqvector;

   savedMask = LockIRQ();

#if defined(__CIRQ_DIE2DIE__)
   if(IS_ADIE_IRQ_CODE(code))
   {
      kal_uint32 adie_line;

      /* find the IRQ line on A-DIE side */
      adie_line = ADIE_IRQCode2Line[IRQ_CODE_GLB_TO_ADIE(code)];

      /* map the line to index of lisr_dispatch_tbl[] */
      irqvector = IRQ_LINE_ADIE_TO_GLB(adie_line);
   }
   else
#endif
   {
   irqvector = IRQCode2Line[code];
   }


   lisr_dispatch_tbl[irqvector].vector = irqvector;
   lisr_dispatch_tbl[irqvector].lisr_handler = reg_lisr;
   lisr_dispatch_tbl[irqvector].description = description;

   RestoreIRQ(savedMask);
}

#if defined(IRQ_GPII_CODE) || defined(IRQ_GPI_CODE)
static void nIRQ_GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
{
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPIO,pin);	
	switch(conf_dada)
		{
			case 1:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_1,0);
				break;
			case 2:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_2,0);
				break;
			default:
				{
					DclGPIO_Close(handle);
					ASSERT(0);
				}
		}
	DclGPIO_Close(handle);
}
#endif /* IRQ_GPII_CODE || IRQ_GPI_CODE */

#ifdef  IRQ_GPII_CODE
/************************************************************************
 * FUNCTION
 *  nIRQ_HISR
 *
 * DESCRIPTION
 *  This function implements HISR of nIRQ
 *
 * CALLS
 *
 * PARAMETERS
 *  None
 * 
 * RETURNS
 *  None
 *
 ************************************************************************/
static void nIRQ_HISR(void)
{
   if ( nIRQ_CallBack_Function != NULL )
      nIRQ_CallBack_Function();

   if (nIRQ_auto_unmask == KAL_TRUE ) 
   {
      IRQUnmask(IRQ_GPII_CODE);
   }
}

/************************************************************************
 * FUNCTION
 *  nIRQ_LISR
 *
 * DESCRIPTION
 *  This function implements LISR of nIRQ
 *
 * CALLS
 *
 * PARAMETERS
 *  None
 * 
 * RETURNS
 *  None
 ************************************************************************/
static void nIRQ_LISR(void)
{
   IRQMask(IRQ_GPII_CODE);

   drv_active_hisr(DRV_NIRQ_HISR_ID);
}

/************************************************************************
 * FUNCTION
 *  nIRQ_Registration
 *
 * DESCRIPTION
 *  This function implements registration of nIRQ
 *
 * CALLS
 *
 * PARAMETERS
 *  edge     - flag indicate edge sensitive
 *  reg_hisr - registered HISR
 *  auto_unmask - flag indicate performing unmask automatically after activating HISR
 * 
 * RETURNS
 *  None
 * 
 * GLOBAL AFFECTED
 *  Set values of global variables nIRQ_HISR_ID and nIRQ_auto_unmask
 *
 ************************************************************************/
void nIRQ_Registration(kal_bool edge, void(reg_hisr)(void), kal_bool auto_unmask)
{
   kal_uint32 savedMask;

   /* register HISR */
   DRV_Register_HISR(DRV_NIRQ_HISR_ID, nIRQ_HISR);

   savedMask = LockIRQ();
   
   /* register LISR */
   IRQ_Register_LISR(IRQ_GPII_CODE, nIRQ_LISR, "nIRQ LISR");

   /* set auto-unmask flag */
   nIRQ_auto_unmask = auto_unmask;
   /* register callback function */
   nIRQ_CallBack_Function = reg_hisr;

   /* set sensitive register */
   IRQSensitivity(IRQ_GPII_CODE, edge);

   RestoreIRQ(savedMask);

}

/************************************************************************
 * FUNCTION
 *  nIRQ_Init
 *
 * DESCRIPTION
 *  This function aims to configure a GPIO pin as nIRQ.
 *
 * CALLS
 *
 * PARAMETERS
 * 
 * RETURNS
 * 
 * GLOBAL AFFECTED
 *  This function muse be called after Drv_Init()!
 *
 ************************************************************************/
kal_bool nIRQ_Init(void)
{
#if defined(MT6225) || !defined(__CUST_NEW__)
   nIRQ_GPIO_ModeSetup(12, 0x2);
#endif

   IRQMask(IRQ_GPII_CODE);

#ifndef __CUST_NEW__
   nIRQ_GPIO_ModeSetup(41, 0x01);
#endif

   return KAL_TRUE;
}

#endif /* IRQ_GPII_CODE */

#ifdef  IRQ_GPI_CODE
/************************************************************************
 * FUNCTION
 *  nFIQ_HISR
 *
 * DESCRIPTION
 *  This function implements HISR of nFIQ
 *
 * CALLS
 *
 * PARAMETERS
 *  None
 * 
 * RETURNS
 *
 * REMARK
 *   Available for MT6218B, MT6217 and MT6219 only.
 *
 ************************************************************************/
static void nFIQ_HISR(void)
{
   if ( nFIQ_CallBack_Function != NULL )
      nFIQ_CallBack_Function();

   if (nFIQ_auto_unmask == KAL_TRUE ) 
      IRQUnmask(IRQ_GPI_CODE);
}

/************************************************************************
 * FUNCTION
 *  nFIQ_LISR
 *
 * DESCRIPTION
 *  This function implements LISR of nFIQ
 *
 * CALLS
 *
 * PARAMETERS
 *  None
 * 
 * RETURNS
 *
 * REMARK
 *   Available for MT6218B, MT6217 and MT6219 only.
 *
 ************************************************************************/
static void nFIQ_LISR(void)
{
   IRQMask(IRQ_GPI_CODE);
   drv_active_hisr(DRV_NFIQ_HISR_ID);
}

/************************************************************************
 * FUNCTION
 *  nFIQ_Init
 *
 * DESCRIPTION
 *  This function aims to configure a GPIO pin as nFIQ.
 *
 * CALLS
 *
 * PARAMETERS
 * 
 * RETURNS
 * 
 * GLOBAL AFFECTED
 *  This function muse be called after Drv_Init()!
 *
 ************************************************************************/
kal_bool nFIQ_Init(void (hisr_callback)(void), kal_bool enable, kal_bool auto_unmask, kal_bool sensitivity)
{
   kal_uint32 savedMask;
   
   /* register HISR */
   DRV_Register_HISR(DRV_NFIQ_HISR_ID, nFIQ_HISR);
   
   savedMask = LockIRQ();
   
   IRQMask(IRQ_GPI_CODE);
   
#if defined(MT6228) || defined(MT6229) || defined(MT6230)
   nIRQ_GPIO_ModeSetup(63, 0x01);
#elif defined(MT6225)
   nIRQ_GPIO_ModeSetup(13, 0x02);
#elif defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6223) || defined(MT6223P) || defined(MT6219)
   nIRQ_GPIO_ModeSetup(42, 0x01);
#endif   

   IRQ_Register_LISR(IRQ_GPI_CODE, nFIQ_LISR, "nFIQ_LISR");
   
   /* KAL_FALSE: LEVEL_SENSITIVE, KAL_TRUE: EDGE_SENSITIVE */
   IRQSensitivity(IRQ_GPI_CODE,sensitivity);
   
   /* set auto-unmask flag */
   nFIQ_auto_unmask = auto_unmask;
   
   /* register callback function */
   nFIQ_CallBack_Function = hisr_callback;
   
   if ( enable )
      IRQUnmask(IRQ_GPI_CODE);
      
   RestoreIRQ(savedMask);
   
   return KAL_TRUE;

}

#endif /* IRQ_GPI_CODE */

/*************************************************************************
* FUNCTION
*  IRQ_Retrieve_LISR
*
* DESCRIPTION
*   This function implement to retrieve register LISR handler
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void* IRQ_Retrieve_LISR(kal_uint32 vector)
{
   return(void*)(lisr_dispatch_tbl[vector].lisr_handler);
}

/*************************************************************************
* FUNCTION
*  IRQ_Default_LISR
*
* DESCRIPTION
*   This function implement default IRQ' LISR
*
* CALLS
*
* CALL BY
*  IRQ_LISR_Init()
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void IRQ_Default_LISR(void)
{
   kal_fatal_error_handler(KAL_ERROR_NON_REGISTERED_LISR, (kal_uint32)processing_irqx);
}

/*************************************************************************
* FUNCTION
*  INT_FIQ_Lisr
*
* DESCRIPTION
*   This function implement FIQ handler
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void INT_FIQ_Lisr(void)
{
   kal_uint8  FIQ_Enter=1;
   
   if (KAL_FALSE == SLA_IsLmuLogging())
   {
      LMU_Write_ISR_CSM(0xaaaa0fff);
   }
   if (SA_LoggingIndex != 0)
   {
      SLA_LoggingLISR(0xaaaa0fff);
   }

     FIQErrInfo.fiqSelect = FIQ_isValid();
     FIQErrInfo.irqReturnAddr = processing_irqlr;
     FIQErrInfo.fiqReturnAddr = processing_fiqlr;

   if (KAL_FALSE == SLA_IsLmuLogging())
   {
      LMU_Write_ISR_END_CSM(0xaaaaaaaa);
   }
   if (SA_LoggingIndex != 0)
   {
      SLA_LoggingLISR(0xaaaaaaaa);
   }
     
   EXT_ASSERT(FIQ_Enter==0, FIQErrInfo.fiqSelect, FIQErrInfo.fiqReturnAddr, FIQErrInfo.irqReturnAddr);
}

void INT_Timer_Interrupt(void)
{
    Kal_Timer_Interrupt();
}

#ifndef __INTSRAM_SHRINKING__
#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE"
#endif /* __MTK_TARGET__ */
#endif

/*************************************************************************
* FUNCTION
*  isrCTIRQ1, isrCTIRQ1_USBPowerOn
*
* DESCRIPTION
*   This function implement CTIRQ1 LISR
*
* CALLS
*
* CALL BY
*  IRQ_LISR_Init()
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void isrCTIRQ1(void)
{
   /* set EMI arbitrator to hard mode for GMC before running the hard real-time app */
#if defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
   EMI_Set_GMCBW_HardMode();
#endif  /* __DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__ */

#ifndef L1_NOT_PRESENT
   L1I_FrameInterrupt();
#endif /* !L1_NOT_PRESENT */

   /* restore EMI arbitrator to soft mode for GMC before running the hard real-time app */
#if defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
   EMI_Set_GMCBW_SoftMode();
#endif  /* __DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__ */

/* For MT6268 2G/3G or 2G Single project: timer interrupt is moved to l1csm.c for Dual/Single OS Tick mechanism  */
#if !defined(__NEW_OS_TICK__) && !defined(__CENTRALIZED_SLEEP_MANAGER__)
   Kal_Timer_Interrupt();

/* RTOS tick compensation by L1 */
#ifndef L1_NOT_PRESENT
   if (L1I_Querry_Compensate_KAL_Timer()==KAL_TRUE)
   Kal_Timer_Interrupt();
#endif /* !L1_NOT_PRESENT */

#elif defined(__MAUI_BASIC__) && !defined(__CENTRALIZED_SLEEP_MANAGER__)

   Kal_Timer_Interrupt();

#endif   /* !__NEW_OS_TICK__ */

   /*KTEST: start timer tick in target full load if not event based timer!*/
#if defined(__KTEST__) && !defined(__MAUI_BASIC__) && !defined(__CENTRALIZED_SLEEP_MANAGER__)
   Kal_Timer_Interrupt();
#endif/*__KTEST__*/

#ifdef FIQ
   FIQClearInt();
#endif
}

/* isrCTIRQ1 would not be trapped because L1 task is disabled in USB boot mode; */
/* This is specific for USB boot mode, would be registered in initialize(). */
#ifdef __USB_ENABLE__
void isrCTIRQ1_USBPowerOn(void)
{
   Kal_Timer_Interrupt();
}
#endif   /*__USB_ENABLE__*/

#ifndef __INTSRAM_SHRINKING__
#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */
#endif


/* should be expanded to all project */
#if defined(MT6250) || defined(MT6260) || defined(__IRQ_CODE_TO_SRAM__)
#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE"
#endif /* __MTK_TARGET__ */
#endif /* MT6250 || MT6260 */

/*************************************************************************
* FUNCTION
*  isrC_Main
*
* DESCRIPTION
*   This function implement IRQ's LISR main dispatch routine
*
* CALLS
*
* CALL BY
*  INT_IRQ_Parse()
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void isrC_Main(void)
{
   kal_uint32 irqx;
   void       *processing_lisr_backup;
   kal_uint16 processing_irqx_backup;
#if defined(__TINY_SYS__) /* dongming add for tiny sys */
   kal_uint32 tp_sw_reg_status;
   kal_uint8 tp_irq_code;
#endif 
   irqx = IRQ_Status();
   if(irqx==(kal_uint32)(-1))
      return;

#if defined(MT6250) || defined(MT6260)|| defined(__IRQ_LISR_DEBUG__)
/* time debug code. should be phased out by W12.26 */
    irq_dbg_time_after_read_sta = ust_get_current_time();
#endif

   processing_lisr_backup = processing_lisr;
   processing_irqx_backup = processing_irqx;
   processing_irqx = irqx;
   processing_lisr = (void*)lisr_dispatch_tbl[irqx].lisr_handler;
   processing_irqCnt++;
   
   if (KAL_FALSE == SLA_IsLmuLogging())
   {
      LMU_Write_ISR_CSM(0xaaaa0000 | ((kal_uint32)processing_irqx));
   }
   if (SA_LoggingIndex != 0)
   {
      SLA_LoggingLISR(0xaaaa0000 | ((kal_uint32)processing_irqx));
   }

#ifdef __SWDBG_SUPPORT__
   *SWDBG_MPCON = ((irqx + 0x100) << 16) | 0x8000;
#endif   /* __SWDBG_SUPPORT__ */

#ifdef __WAKEUP_IRQ_DEBUG__
   if (wkup_intr_log_indx != WKUP_LOG_BUF_MAX) {
      wkup_intr_log_buf[wkup_intr_log_indx].irq = processing_irqx;
      wkup_intr_log_indx++;
      if (wkup_intr_log_indx == WKUP_LOG_BUF_MAX) {
         wkup_intr_log_indx = 0;
      }
   }
   if (wkup_timer_log_indx != WKUP_LOG_BUF_MAX) {
      if (wake_tm_name != NULL) {
         wkup_timer_log_buf[wkup_timer_log_indx].timer_name = wake_tm_name;
         wake_tm_name = NULL;
         wkup_timer_log_indx++;
         if (wkup_timer_log_indx == WKUP_LOG_BUF_MAX) {
            wkup_timer_log_indx = 0;
         }
      }
   }
#endif  /* __WAKEUP_IRQ_DEBUG__ */

#if defined(__TP_SUPPORT_TIMING_CHECK__)
   if(Thread_Protect_State==1)
   {
       Thread_Protect_State=2;
       TP_Exclude_Start_Time = ust_get_current_time();
   }
#endif

#ifdef __DEMAND_PAGING_PERFORMANCE_PROFILING__   
   demp_preempt_time_start();
#endif
   
#if defined(MT6250) || defined(MT6260) || defined(__IRQ_LISR_DEBUG__)
/* time debug code. should be phased out by W12.26 */
    irq_dbg_time_before_lisr = ust_get_current_time();
#endif
   
   ReEnableIRQ();
#if defined(__TINY_SYS__)
   tp_irq_code = irqLine[irqx];
   if (tp_irq_code < 32)
   {
      tp_sw_reg_status = *IRQ_SOFT0;
   }
   else if(tp_irq_code < 64)
   {
      tp_sw_reg_status = *IRQ_SOFT1;
	  tp_irq_code = tp_irq_code - 32;// when irq code exceed 32, we need subtract 32 for the register is only 32bit long
   }

   if(0 != (tp_sw_reg_status & (1 << tp_irq_code)))
   {
   
  	    tp_irq_code = irqLine[irqx];
   		//dbg_print("OOO: here is AP mode, we got tiny unknown irq.\r\n");
   		//dbg_print("OOO: the irq is %d.\r\n",tp_irq_code);
   		IRQ_ResetSWRegister(tp_irq_code);
   }
#endif
   lisr_dispatch_tbl[irqx].lisr_handler();
   DisableIRQ();
   
   /* restore global variable processing_lisr and processing_irqx to value of preempted IRQ */
   processing_irqx = processing_irqx_backup;
   processing_lisr = processing_lisr_backup;   
   
   if (KAL_FALSE == SLA_IsLmuLogging())
   {
      LMU_Write_ISR_END_CSM(0xaaaaaaaa);
   }
   if (SA_LoggingIndex != 0)
   {
      SLA_LoggingLISR(0xaaaaaaaa);
   }
   
   /* Binary-coded IRQ idx */
   SYS_ClearInt2((kal_uint8)irqx);

}
/* should be expanded to all project */
#if defined(MT6250) || defined(MT6260) || defined(__IRQ_CODE_TO_SRAM__)
#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */
#endif /* MT6250 || MT6260 */

void No_Context_Switch()
{
   if (KAL_FALSE == SLA_IsLmuLogging())
   {
      LMU_Write_ISR_END_RESUME_CSM(0xbbbbbbbb);
   }
   if (SA_LoggingIndex != 0)
   {
      SLA_LoggingLISR(0xbbbbbbbb);
   }
        
#if defined(__NUCLEUS_VERSION_2__)
    if( SA_LoggingIndex != 0 ) 
    {
	    SLA_HookLogging();
    }
    LMU_Write_Task_CSM((unsigned int)TCD_Current_Thread);
#endif   
}

/*************************************************************************
* FUNCTION
*  get_wkup_intr_log_buf
*
* DESCRIPTION
*  This function gets the wakeup logging buffer's address, current index, 
*  and max count.
*  NoteXXX: An IRQ may wake up the system and break the sleep mode.
*           When the debugging option is enabled, all interrupts are
*           logged. User can check all IRQ numbers in the logging 
*           buffer to see which IRQ wakes up the system.
*
* PARAMETERS
*  buf    -   pointer to buffer address
*  indx   -   pointer to buffer index
*  max    -   pointer to buffer max count
*
* RETURNS
*  0 if the IRQ logging buffer exists; otherwise, -1
*
*************************************************************************/
kal_int32 get_wkup_intr_log_buf(wkup_intr_log_t **buf, kal_uint32 *indx, kal_uint32 *max)
{
#if defined(__WAKEUP_IRQ_DEBUG__)

   *buf = (wkup_intr_log_t *)wkup_intr_log_buf;
   *indx = wkup_intr_log_indx;
   *max = WKUP_LOG_BUF_MAX;
    
   return 0;

#endif  /* __WAKEUP_IRQ_DEBUG__ */

   return -1;
}

/*************************************************************************
* FUNCTION
*  get_wkup_timer_log_buf
*
* DESCRIPTION
*  This function gets the wakeup logging buffer's address, current index, 
*  and max count.
*
* PARAMETERS
*  buf    -   pointer to buffer address
*  indx   -   pointer to buffer index
*  max    -   pointer to buffer max count
*
* RETURNS
*  0 if the IRQ logging buffer exists; otherwise, -1
*
*************************************************************************/
kal_int32 get_wkup_timer_log_buf(wkup_timer_log_t **buf, kal_uint32 *indx, kal_uint32 *max)
{
#if defined(__WAKEUP_IRQ_DEBUG__)

   /* 
    * NonteXXX: No need to disable IRQ before accessing wake_tm_name.
    *           get_wkup_timer_log_buf is called by L1 LISR.
    *           wake_tm_name is also updated in L1 LISR.
    */
   if (wake_tm_name != NULL) {
      wkup_timer_log_buf[wkup_timer_log_indx].timer_name = wake_tm_name;
      wake_tm_name = NULL;
      wkup_timer_log_indx++;
      if (wkup_timer_log_indx == WKUP_LOG_BUF_MAX) {
         wkup_timer_log_indx = 0;
      }
   }

   *buf = (wkup_timer_log_t *)wkup_timer_log_buf;
   *indx = wkup_timer_log_indx;
   *max = WKUP_LOG_BUF_MAX;
    
   return 0;

#endif  /* __WAKEUP_IRQ_DEBUG__ */

   return -1;
}

/*************************************************************************
* FUNCTION
*  enable_wkup_log
*
* DESCRIPTION
*  This function enables wakeup logging.
*
* PARAMETERS
*  None
*
* RETURNS
*  0 if the IRQ logging buffer exists; otherwise, -1
*
*************************************************************************/
kal_int32 enable_wkup_log(void)
{
#if defined(__WAKEUP_IRQ_DEBUG__)

   wkup_intr_log_indx = 0;
   wkup_timer_log_indx = 0;

   return 0;

#endif  /* __WAKEUP_IRQ_DEBUG__ */

   return -1;
}
