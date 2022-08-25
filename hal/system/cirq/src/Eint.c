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
 *   Eint.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description: 
 * ------------
 *   This files define external interrupt management
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

/*************************************************************************
 * Included header files
 *************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "eint.h"
#include "dcl.h"
#include "drv_hisr.h"
#include "us_timer.h"

#include "Eint_internal.h"
#include "kal_internal_api.h"
#if defined (__EINT_DIE2DIE__)
#include "ADIE_eint.h"
#endif

/*************************************************************************
 * Define global variables
 *************************************************************************/

/* F2S early response macro */
#define EINT_F2S_DUMMY_READ()    do { \
        *EINT_MASK; \
    } while(0)

#if defined(__EINT_SW_DEBOUNCE_V2__)
/* eint_hisr_activated_mask is mask of EINTs that trigger EINT IRQ and with */
/* SW de-bounce mechanism. Bits of eint_hisr_activated_mask is set in       */
/* EINT_LISR and cleared in EINT_HISR_Entry. It is used for LISR to tell    */
/* HISR which EINT(s) trigger interrupt and need to perform SW debounce      */
/* mechanism. When accessing this variable, be aware of race condition issue. */
static kal_uint32 eint_hisr_activated_mask = 0;

#if (EINT_TOTAL_CHANNEL > 32)
  #error "Mask of EINT exceeds 32 bits. Be sure to extend the eint_hisr_activated_mask."
#endif

#endif /* __EINT_SW_DEBOUNCE_V2__ */

eint_func_t             EINT_FUNC[EINT_ALL_NUMBER];
EINT_SW_DEBOUNCE_STRUCT eint_sw_debounce[EINT_ALL_NUMBER];
kal_uint8 *eint_sw_debounce_time_delay = NULL;

/* Variables to monitor the last mask/unmask function */
kal_uint32 eint_mask_caller;
kal_uint32 eint_unmask_caller;
kal_uint8 eint_mask_monitor_idx = EINT_ALL_NUMBER;
kal_uint8 eint_unmask_monitor_idx = EINT_ALL_NUMBER;

/* Variables to record sources that triggers EINT interrupt */
kal_uint8 eint_trigger_src_log[EINT_TRIGGER_SRC_LOG_MAX];
kal_uint8 eint_trigger_src_ptr = 0;

/*====================================================*/
// added for dcl eint interface
extern volatile kal_uint64 eint_dcl_use_status;      // when call dcl interface, we update this variable.
extern volatile kal_uint64 eint_native_use_status;   // when call EINT_Registration directly(native user),we update this variable.

/*====================================================*/

/*************************************************************************
 * Define function prototpye
 *************************************************************************/
void EINT_HISR_Entry(void);
void EINT_TIMER_CALLBACK(void *data);
extern kal_uint32 DisableIRQ(void);
extern void RestoreIRQ(kal_uint32 irq);
extern kal_uint32 LockIRQ(void);
extern void BTMT_EINT_HANDLER(kal_uint32* status);
extern void ADIE_EINT_Set_HW_Debounce_Ext(kal_uint8 eintno, kal_uint32 ms);


#if !defined(__MD_EINT_PROPOGATED_FROM_AP__)
/*************************************************************************
* FUNCTION
*  Register_EINT
*
* DESCRIPTION
*   This function implements registration of external interrupts
*
* CALLS
*
* PARAMETERS
*  eintno            -     External interrupt vector number
*  Dbounce_En        -     Debounce control enable
*  ACT_Polarity      -     Interrupt polarity
*  reg_hisr          -     Registered hisr
*  auto_umask        -     A flag instruct the systerm to do unmask after
*                          invoking the registered HISR
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
 *************************************************************************/
void EINT_Registration(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, \
                       void (reg_hisr)(void), kal_bool auto_umask)
{
   kal_uint32 savedMask;
   kal_uint16 count;
   kal_uint32 retaddr;
   kal_bool IS_DCL = KAL_FALSE;
/*===============================================================*/
//  below is added for DCL EINT interface
/*===============================================================*/

   if((eintno & DCL_EINT_FLAG_MASK) != 0)
   {
   		IS_DCL = KAL_TRUE;
   }
   eintno = eintno & DCL_VALID_EINT_NUM_MASK;
   /* If EINT Number is out of range, get return address and send it to exception handler */
    if(eintno >= EINT_ALL_NUMBER)
   {
       GET_RETURN_ADDRESS(retaddr);
       kal_fatal_error_handler(KAL_ERROR_DRV_EINT_INVALID_INDEX, retaddr);
   }
	savedMask = LockIRQ();
	if((IS_DCL && CHECK_NATIVE_USE_STA(eintno)) || (!IS_DCL && CHECK_DCL_USE_STA(eintno)))
	{
		RestoreIRQ(savedMask);//there is no need call RestoreIRQ for it will fatal error.
		GET_RETURN_ADDRESS(retaddr);
		kal_fatal_error_handler(KAL_ERROR_DRV_EINT_INVALID_INDEX, retaddr);
	}
	else if(!IS_DCL)
	{
		EINT_SET_NATIVE_USE_STA(eintno);
	}
	RestoreIRQ(savedMask);

/*===============================================================*/

   
#if defined (__EINT_DIE2DIE__)
   if(IS_ADIE_EINT(eintno))
   {
#if !defined(__NEW_ADIE_EINT_LISR__)
      IRQ_Register_LISR(IRQ_ADIE_EIT_CODE, EINT_LISR, "ADIE EINT LISR");
#else
      IRQ_Register_LISR(IRQ_ADIE_EIT_CODE, ADIE_EINT_LISR, "ADIE EINT LISR");
#endif      
       
      savedMask = LockIRQ();

      /* Register external interrupt's HISR */
/*===========================================================*/
// below ,if is added for DCL interface. 
// if  DCL interface call this API, we do not register the callback becuase user should call DclEINT_RegisterCallback to do the same thing.

     if(!IS_DCL) 
     {
         EINT_FUNC[eintno].eint_func = reg_hisr;
     }

/*===========================================================*/
      EINT_FUNC[eintno].eint_active = KAL_FALSE;
      EINT_FUNC[eintno].eint_auto_umask = auto_umask;

      /* register HISR */
      DRV_Register_HISR(DRV_EINT_HISR_ID, EINT_HISR_Entry);

      RestoreIRQ(savedMask);

      /* initialize HW-dependant A-DIE EINT configuration */
      ADIE_EINT_HW_Initialize(EINT_GLB_TO_ADIE(eintno), Dbounce_En, ACT_Polarity);

      IRQSensitivity(IRQ_ADIE_EIT_CODE, KAL_FALSE);

      IRQUnmask(IRQ_ADIE_EIT_CODE);

      return;
   }
#endif
   
   IRQ_Register_LISR(IRQ_EIT_CODE, EINT_LISR, "EINT handler");

   /* Save and set MCU's I,F bits to disable interrupts */
   savedMask = LockIRQ();

   /* Set external interrupt polarity */
   if (ACT_Polarity) 
      EINTaddr(eintno) |= EINT_CON_HIGHLEVEL;
   else
      EINTaddr(eintno) &= ~(EINT_CON_HIGHLEVEL);

#if defined(__CIRQ_DESIGN_NEW__)
#if !defined(__AP_DOMAIN0__) || defined(__APPLICATION_PROCESSOR__)
   /* Set domain as MCU or AP (domain 0) */
/*-------------------------------------------------------*/
// check in for MT6261 eint number exceed 32
#if (EINT_TOTAL_CHANNEL > 32)
    if (eintno < 32)
        *EINT_D0EN0 |= (1 << eintno);
    else
        *EINT_D0EN1 |= (1 << (eintno - 32));
#else
   *EINT_D0EN |= (1 << eintno);

#endif    

/*--------------------------------------------------------*/
#else
   /* Set domain as MD (domain 2) */
   *EINT_D2EN |= (1 << eintno);
#endif
#endif

   /*
    * NoteXXX: Only EINT 0 ~ (EINT_MAX_CHANNLE - 1) support level trigger.
    *          The de-bounce time is only for level trigger EINT.
    */
    //if ( EINT_HW_DEBOUNCE(eintno) ) 
#if defined(EINT_ENABLE_HW_DEBOUNCE)
	if(EINT_ENABLE_HW_DEBOUNCE == KAL_TRUE)
#else
	if(EINT_HW_DEBOUNCE(eintno))
#endif
	{
      /* Set external interrupt debounce control enable or not */
      if (Dbounce_En) {
         /* check if debounce is enabled */
         if (EINTaddr(eintno) & EINT_CON_DEBOUNCE_EN) {
            /* debounce value is already set; NOP */
         } else {
            EINTaddr(eintno) |= (EINT_CON_DEBOUNCE | EINT_CON_DEBOUNCE_EN);
         }
      }
      else
      {
         /*disable debounce */
         EINTaddr(eintno) &= ~(EINT_CON_DEBOUNCE_EN);
      }
   }

   /* Register external interrupt's HISR */
/*===========================================================*/
// below ,if is added for DCL interface. 
// if  DCL interface call this API, we do not register the callback becuase user shoul call DclEINT_RegisterCallback to do the same thing.
   if(!IS_DCL) 
   {
      EINT_FUNC[eintno].eint_func = reg_hisr;
   }

/*===========================================================*/

   EINT_FUNC[eintno].eint_active = KAL_FALSE;
   EINT_FUNC[eintno].eint_auto_umask = auto_umask;

   /* register HISR */
   DRV_Register_HISR(DRV_EINT_HISR_ID, EINT_HISR_Entry);
   
   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. The polarity *
   * takes 4T to be effective. To guarantee the set polarity        *
   * operation before the wait loop, and dummy read is added to     *
   * and the set polarity operation completes befroe the dummy read *
   * operation.                                                     *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    EINT_F2S_DUMMY_READ();
#endif

   /* Restore previous MCU's I,F bits setting */
   RestoreIRQ(savedMask);

   /*
    * XXX!!!. Hardware bug
    *    - must wait for 32khz/1 sec to write mask register, will be
    *    fixed in future.
    */
   for (count=0; count<250; count++) ;  /*250:52M*/

   savedMask = LockIRQ();

   
   /*-------------------------------------------------------*/
   // check in for MT6261 eint number exceed 32
#if (EINT_TOTAL_CHANNEL > 32)
	   if (eintno < 32)
		   *EINT_INTACK0 = EINT_INTACK_EINT(eintno);
	   else
		   *EINT_INTACK1 = EINT_INTACK_EINT(eintno - 32);
#else
   *EINT_INTACK = EINT_INTACK_EINT(eintno);
   
#endif    
   
   /*--------------------------------------------------------*/
   EINT_UnMask(eintno);

   RestoreIRQ(savedMask);

   /* Set external interrupt is level sensitive */
   IRQSensitivity( IRQ_EIT_CODE, LEVEL_SENSITIVE );

   /* Enable external interrupt */
   IRQUnmask( IRQ_EIT_CODE );
}

/*************************************************************************
* FUNCTION
*  EXTRA_EINT_Registration
*
* DESCRIPTION
*   This function implements registration of external interrupts
*
* CALLS
*
* PARAMETERS
*  eintno            -     External interrupt vector number
*  ACT_Polarity      -     Interrupt polarity
*  reg_hisr          -     Registered hisr
*  auto_umask        -     A flag instruct the systerm to do unmask after
*                          invoking the registered HISR
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EXTRA_EINT_Registration(kal_uint8 eintno, kal_bool ACT_Polarity, void (reg_hisr)(void), \
                             kal_bool auto_umask)
{
   ASSERT((eintno < EINT_ALL_NUMBER) && EINT_CheckNotHWDebounce(eintno) );

   EINT_Registration(eintno, KAL_FALSE, ACT_Polarity, reg_hisr, auto_umask);
}

#if defined (__EINT_SW_DEBOUNCE_V2__)
/*************************************************************************
* FUNCTION
*  EINT_HISR_Entry
*
* DESCRIPTION
*  This function implements main external interrupt HISR registered in
*  global ISR jump table, eint_hisr_func.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_HISR_Entry(void)
{
   kal_uint8 index;
   kal_uint32 savedMask;
   kal_uint32 activatedMask;
   kal_uint32 cpsr_bak;

   /* Disable interrupt before accessing eint_hisr_activated_mask */
   savedMask = LockIRQ();
   activatedMask = eint_hisr_activated_mask;
   eint_hisr_activated_mask = 0;
   RestoreIRQ(savedMask);
   
   /* First part, check whether any EINT SW debounce flag is set in LISR */
   for(index = 0; index < EINT_ALL_NUMBER; index++)
   {
       /* if an EINT with SW-Debounce triggered interrupt */
       if(activatedMask & (1 << index))
       {
           if(eint_sw_debounce[index].eint_sw_debounce_handle != 0x7f)
           {
               DclSGPT_Control(eint_sw_debounce[index].eint_sw_debounce_handle,SGPT_CMD_STOP,0);
               DclSGPT_Close(&(eint_sw_debounce[index].eint_sw_debounce_handle));
           }

           /* Start a period of SW De-Bounce */
           if(KAL_FALSE == eint_sw_debounce[index].eint_intr_allow)
           {
               SGPT_CTRL_START_T start;

               eint_sw_debounce[index].eint_sw_debounce_handle=DclSGPT_Open(DCL_GPT_CB,0);

               start.u2Tick=eint_sw_debounce_time_delay[index];
               start.pfCallback=EINT_TIMER_CALLBACK;
               start.vPara=&eint_sw_debounce[index];
               DclSGPT_Control(eint_sw_debounce[index].eint_sw_debounce_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
           }
           /* A period of SW De-Bounce times out. Enable HISR */
           else
           {
               eint_sw_debounce[index].eint_intr_allow = KAL_FALSE;
               EINT_FUNC[index].eint_active = KAL_TRUE;
           }
       }
   }    

   for(index=0;index<EINT_TOTAL_CHANNEL;index++)
   {
      if ( (EINT_FUNC[index].eint_active == KAL_TRUE) && (EINT_FUNC[index].eint_func) ) 
      {
         /* eint_sw_debounce[index].eint_intr_allow may be modified in LISR */
         /* disable interrupt to protect this variable */
         cpsr_bak = LockIRQ();
         EINT_FUNC[index].eint_active = KAL_FALSE;
         RestoreIRQ(cpsr_bak);

         eint_trigger_src_log[eint_trigger_src_ptr] = index;
         eint_trigger_src_ptr = (eint_trigger_src_ptr + 1) % EINT_TRIGGER_SRC_LOG_MAX;
         
         EINT_FUNC[index].eint_func();

         if (EINT_FUNC[index].eint_auto_umask == KAL_TRUE) 
         {
            EINT_UnMask(index);
         }
      }
   }

#if defined(IRQ_EOI2)
	*IRQ_EOI2 = IRQCode2Line[IRQ_EIT_CODE];
#else
	*IRQ_EOI = (1 << IRQCode2Line[IRQ_EIT_CODE]);
#endif	

}

#else /* __EINT_SW_DEBOUNCE_V2__ */

/*************************************************************************
* FUNCTION
*  EINT_HISR_Entry
*
* DESCRIPTION
*  This function implements main external interrupt HISR registered in
*  global ISR jump table, eint_hisr_func.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_HISR_Entry(void)
{
   kal_uint8 index;

   for(index=0;index<EINT_ALL_NUMBER;index++)
   {
      if ( (EINT_FUNC[index].eint_active == KAL_TRUE) && (EINT_FUNC[index].eint_func) ) 
      {

         EINT_FUNC[index].eint_active = KAL_FALSE;

         eint_trigger_src_log[eint_trigger_src_ptr] = index;
         eint_trigger_src_ptr = (eint_trigger_src_ptr + 1) % EINT_TRIGGER_SRC_LOG_MAX;

         EINT_FUNC[index].eint_func(index);

         if (EINT_FUNC[index].eint_auto_umask == KAL_TRUE) 
         {
            EINT_UnMask(index);
         }
      }
   }

#if 0
#if defined(IRQ_EOI2)
/* under construction !*/
#else
/* under construction !*/
#endif	
#endif

}


#endif /* __EINT_SW_DEBOUNCE_V2__ */

/*************************************************************************
* FUNCTION
*  EINT_Internal_LISR_Handler
*
* DESCRIPTION
*   Internal function of External Interrupt Service Routine
*
* CALLS
*
* PARAMETERS
*  The value of EINT_STA
*
* RETURNS
*  If the original LISR flow should be bypassed
*
*************************************************************************/
kal_bool EINT_Internal_LISR_Handler(kal_uint32* status)
{
    kal_bool retval = KAL_FALSE;

#if defined(__AST_EINT__) && defined(__AST_TL1_TDD__)
    AST_EINT_HANDLER(status);
#endif

#if defined(IC_BURNIN_TEST) || defined(IC_MODULE_TEST)
    BTMT_EINT_HANDLER(status);
#endif

    return retval;
}

/*************************************************************************
* FUNCTION
*   EINT_Get_Status
*
* DESCRIPTION
*   Entry function of External Interrupt Service Routine
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  Mask of triggered EINTs.
*
* GLOBALS AFFECTE
*
*************************************************************************/
#if (EINT_TOTAL_CHANNEL > 32)
kal_uint64 EINT_Get_Status()
{
	kal_uint64 status;

#if defined(__CIRQ_DESIGN_NEW__)
#if !defined(__AP_DOMAIN0__) || defined(__APPLICATION_PROCESSOR__)
   /* Only take the EINT from MCU or AP (domain 0) */
   /*-------------------------------------------------------*/
   // check in for MT6261 eint number exceed 32
	status = (*EINT_STATUS0) & (*EINT_D0EN0);
	status |= (((kal_uint64)((*EINT_STATUS1) & (*EINT_D0EN1))) << 32);
   
   /*--------------------------------------------------------*/
#else
   /* Only take the EINT from MD (domain 2) */
   status = (*EINT_STATUS) & (*EINT_D2EN);
#endif


#else  //__CIRQ_DESIGN_NEW__
   status = *EINT_STATUS;
#endif  ////__CIRQ_DESIGN_NEW__

#if defined(__EINT_DIE2DIE__) && !defined(__NEW_ADIE_EINT_LISR__)
   {
       kal_uint32 adie_status;
   
       adie_status = ADIE_EINT_Get_Status();
       status |= EINT_MASK_ADIE_TO_GLB(adie_status);
   }
#endif
   
   return status;
}
#else
kal_uint32 EINT_Get_Status()
{
   kal_uint32 status;

#if defined(__CIRQ_DESIGN_NEW__)
#if !defined(__AP_DOMAIN0__) || defined(__APPLICATION_PROCESSOR__)
   /* Only take the EINT from MCU or AP (domain 0) */
   status = (*EINT_STATUS) & (*EINT_D0EN);
#else
   /* Only take the EINT from MD (domain 2) */
   status = (*EINT_STATUS) & (*EINT_D2EN);
#endif
#else
   status = *EINT_STATUS;
#endif

#if defined(__EINT_DIE2DIE__) && !defined(__NEW_ADIE_EINT_LISR__)
   {
       kal_uint32 adie_status;
   
       adie_status = ADIE_EINT_Get_Status();
       status |= EINT_MASK_ADIE_TO_GLB(adie_status);
   }
#endif
   
   return status;
}
#endif


#if defined (__EINT_SW_DEBOUNCE_V2__)

/*************************************************************************
* FUNCTION
*   EINT_LISR
*
* DESCRIPTION
*   Entry function of External Interrupt Service Routine
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
void EINT_LISR(void)
{
   kal_uint32 status;
   kal_uint8  index;
   kal_uint8  enable_hisr = KAL_FALSE;

   status = EINT_Get_Status();

   if (EINT_Internal_LISR_Handler(&status))
   {
      return;
   }

   // for conventional external interrupt!
   for(index=0;index<EINT_ALL_NUMBER;index++)
   {
      if(EINT_HW_DEBOUNCE(index))
      {      
         if (status & EINT_STATUS_EINT(index)) 
         {
            EINT_Mask(index);			
            EINT_AckInt(index);

            /* Activate HISR to handle SW de-bounce */
            if (eint_sw_debounce_time_delay[index] > 0) 
            {
                /* Error condition: one EINT is triggered, and it is triggered agagin before it is processed in HISR */
                /* Because this EINT is masked in LISR, and unmasked in HISR. It shouldn't be triggered agagin before it is unmask */
                /* Possible condition that causes this assertion: EINT is unmasked abnormally. */
                ASSERT((eint_hisr_activated_mask & (1 << index)) == 0);
                eint_hisr_activated_mask |= (1 << index);
            }
            else
            {
                EINT_FUNC[index].eint_active = KAL_TRUE;
            }
            /* ENT_HISR_Entry should be enabled, no matter to process HW de-boucne, or call call back function */
            enable_hisr = KAL_TRUE;         
         }
      }
      else
      {
         if (status & EINT_STATUS_EINT(index)) 
         {
             EINT_Mask(index);			 
             EINT_AckInt(index);

             EINT_FUNC[index].eint_active = KAL_TRUE;         
             enable_hisr = KAL_TRUE;		 
         }
      }
   }
   
   if (KAL_TRUE == enable_hisr)
   {
       drv_active_hisr(DRV_EINT_HISR_ID);
   }
}

#else /* __EINT_SW_DEBOUNCE_V2__ */

/*************************************************************************
* FUNCTION
*   EINT_LISR
*
* DESCRIPTION
*   Entry function of External Interrupt Service Routine
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
void EINT_LISR(void)
{
   kal_uint8 index;
   kal_uint64 status; //for MT6261, change this to 64bit
   kal_uint8 enable_hisr = KAL_FALSE;
   #if defined(__TINY_SYS__)
   kal_uint32 tp_sw_reg_status;
   kal_uint8 tp_eint_indx;
   #endif

   kal_uint32 tmp_status;

   status = EINT_Get_Status();

	tmp_status = (kal_uint32)status;
   if (EINT_Internal_LISR_Handler(&tmp_status))
   {
      return;
   }

   // for conventional external interrupt!
#if !defined(__NEW_ADIE_EINT_LISR__)
   for(index=0;index<EINT_ALL_NUMBER;index++)
#else
   for(index=0;index<EINT_TOTAL_CHANNEL;index++)
#endif
   {
   	  #if defined(EINT_ENABLE_HW_DEBOUNCE)
	  if(EINT_ENABLE_HW_DEBOUNCE == KAL_TRUE)
	  #else
      if(EINT_HW_DEBOUNCE(index))
	  #endif
      {
         if (status & EINT_STATUS_EINT(index)) 
         {
            if(eint_sw_debounce[index].eint_sw_debounce_handle != 0x7f)
            {
               DclSGPT_Control(eint_sw_debounce[index].eint_sw_debounce_handle,SGPT_CMD_STOP,0);
               DclSGPT_Close(&(eint_sw_debounce[index].eint_sw_debounce_handle));
            }
            if ( (eint_sw_debounce[index].eint_intr_allow == KAL_FALSE) && 
                 (eint_sw_debounce_time_delay[index] > 0) 
               )
            {
               SGPT_CTRL_START_T start;

               eint_sw_debounce[index].eint_sw_debounce_handle=DclSGPT_Open(DCL_GPT_CB,0);

               start.u2Tick=eint_sw_debounce_time_delay[index];
               start.pfCallback=EINT_TIMER_CALLBACK;
               start.vPara=&eint_sw_debounce[index];
               DclSGPT_Control(eint_sw_debounce[index].eint_sw_debounce_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);

               EINT_Mask(index);
            }
            else
            {
               eint_sw_debounce[index].eint_intr_allow = KAL_FALSE;
               // disable interrupt
               EINT_Mask(index);
               ASSERT(EINT_FUNC[index].eint_func!=NULL);
               if ( EINT_FUNC[index].eint_func )
               {
                  EINT_FUNC[index].eint_active = KAL_TRUE;

                  enable_hisr = KAL_TRUE;
               }
			/*--------dongming add for tiny system-------------*/
			#if defined(__TINY_SYS__)
				tp_eint_indx = index;
			#if (EINT_TOTAL_CHANNEL > 32)
				if (tp_eint_indx < 32){
					tp_sw_reg_status = *EINT_SOFT0;}
				else
				{
					tp_sw_reg_status = *EINT_SOFT1;
					tp_eint_indx = tp_eint_indx - 32;
				}
			#else //(EINT_TOTAL_CHANNEL > 32)
				tp_sw_reg_status = *EINT_SOFT;
			#endif	  
			
			if(0 != (tp_sw_reg_status & (1 << tp_eint_indx)))
			{
				EINT_ResetSWRegister(index);
			}
			#endif

			/*----------------------------------------------*/
			
			   
            }
			
            EINT_AckInt(index);
         }
      }
      else
      {
         if (status & EINT_STATUS_EINT(index)) 
         {
            EINT_Mask(index);
            ASSERT(EINT_FUNC[index].eint_func!=NULL);
            if ( EINT_FUNC[index].eint_func )
            { 
               EINT_FUNC[index].eint_active = KAL_TRUE;

               enable_hisr = KAL_TRUE;
            }
			/*--------dongming add for tiny system-------------*/
			#if defined(__TINY_SYS__)
				tp_eint_indx = index;
			#if (EINT_TOTAL_CHANNEL > 32)
				if (tp_eint_indx < 32){
					tp_sw_reg_status = *EINT_SOFT0;}
				else
				{
					tp_sw_reg_status = *EINT_SOFT1;
					tp_eint_indx = tp_eint_indx - 32;
				}
			#else //(EINT_TOTAL_CHANNEL > 32)
				tp_sw_reg_status = *EINT_SOFT;
			#endif    
			
			if(0 != (tp_sw_reg_status & (1 << tp_eint_indx)))
			{
				EINT_ResetSWRegister(index);
			}
			#endif

			/*----------------------------------------------*/
            EINT_AckInt(index);
         }
      }
   }

   if (enable_hisr == KAL_TRUE)
   {
       drv_active_hisr(DRV_EINT_HISR_ID);
   }

}

#endif /* __EINT_SW_DEBOUNCE_V2__ */

#else /* !__MD_EINT_PROPOGATED_FROM_AP__ */
void (*eint_handler[EINT_TOTAL_CHANNEL]) (void);

void SWWAR_EINT_Registration(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity)
{
   kal_uint32 savedMask;
   kal_uint16 count;


   EXT_ASSERT(eintno < EINT_TOTAL_CHANNEL, eintno, Dbounce_En, ACT_Polarity);
   
   /* Save and set MCU's I,F bits to disable interrupts */
   savedMask = LockIRQ();

   /* Set external interrupt polarity */
   if (ACT_Polarity) 
      EINTaddr(eintno) |= EINT_CON_HIGHLEVEL;
   else
      EINTaddr(eintno) &= ~(EINT_CON_HIGHLEVEL);

   /*
    * NoteXXX: Only EINT 0 ~ (EINT_MAX_CHANNLE - 1) support level trigger.
    *          The de-bounce time is only for level trigger EINT.
    */
    if ( EINT_HW_DEBOUNCE(eintno) ) {
      /* Set external interrupt debounce control enable or not */
      if (Dbounce_En) {
         /* check if debounce is enabled */
         if (EINTaddr(eintno) & EINT_CON_DEBOUNCE_EN) {
            /* debounce value is already set; NOP */
         } else {
            EINTaddr(eintno) |= (EINT_CON_DEBOUNCE | EINT_CON_DEBOUNCE_EN);
         }
      }
      else
      {
         /*disable debounce */
         EINTaddr(eintno) &= ~(EINT_CON_DEBOUNCE_EN);
      }
   }

   
   /* Restore previous MCU's I,F bits setting */
   RestoreIRQ(savedMask);

   /*
    * XXX!!!. Hardware bug
    *    - must wait for 32khz/1 sec to write mask register, will be
    *    fixed in future.
    */
   for (count=0; count<250; count++) ;  /*250:52M*/

   *EINT_MASK_SET = (0x0001 << eintno);

}

void SWWAR_EINT_First_UnMask(kal_uint8 eintno)
{
   kal_uint32 savedMask;
   
   savedMask = LockIRQ();

   *EINT_INTACK = EINT_INTACK_EINT(eintno);
   
   EINT_UnMask(eintno);

   RestoreIRQ(savedMask);
}

void SWWAR_EINT_LISR_DEFAULT(void)
{
   EXT_ASSERT(0,0,0,0);
}

void SWWAR_EINT_LISR_Init(void)
{
   kal_int32 i;
   for(i=0;i<EINT_TOTAL_CHANNEL;i++)
      eint_handler[i] = SWWAR_EINT_LISR_DEFAULT;
   IRQ_Register_LISR(IRQ_EIT_CODE, SWWAR_EINT_LISR,"L1SM EINT_handler");
   IRQSensitivity( IRQ_EIT_CODE, LEVEL_SENSITIVE );
   IRQUnmask(IRQ_EIT_CODE);
}

void SWWAR_EINT_LISR_Registration(kal_uint8 eintno, void (*reg_lisr)(void))
{
   EXT_ASSERT(eintno < EINT_TOTAL_CHANNEL, (kal_uint32)*reg_lisr, 0, 0);
   eint_handler[eintno] = reg_lisr;
}

void SWWAR_EINT_LISR(void)
{
   kal_uint8 index;
   kal_uint32 status;

   status = *EINT_STATUS;

   // for conventional external interrupt!
   for(index=0;index<EINT_TOTAL_CHANNEL;index++)
   {
   	  if (status & EINT_STATUS_EINT(index)) 
   	  {
         eint_handler[index]();
         *EINT_INTACK = EINT_INTACK_EINT(index);
      }
   }
}
#endif /* !__MD_EINT_PROPOGATED_FROM_AP__ */

/*************************************************************************
* FUNCTION
*  EINT_Get_HW_Debounce_Enable
*
* DESCRIPTION
*   This function is used to query whether HW de-bounce is enabled in EINT_CON registers
*   System Service internal use.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*   The hardware debounce disabled indicator bitmask
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool EINT_Get_HW_Debounce_Enable(kal_uint32 eintno)
{
#if defined(__EINT_DIE2DIE__)
   if(IS_ADIE_EINT(eintno))
   {
      return ADIE_EINT_GET_HW_Debounce_Enable(EINT_GLB_TO_ADIE(eintno));   
   }
#endif

    if(EINTaddr(eintno) & EINT_CON_DEBOUNCE_EN)
        return KAL_TRUE;
    else
        return KAL_FALSE;
}

#if !defined(__TOTAL_EINT_EXCEED_INT32__)
/*************************************************************************
* FUNCTION
*  EINT_Query_HW_Debounce
*
* DESCRIPTION
*   This function dedicates to query the hardware debounce status
*   interrupts.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*   The hardware debounce disabled indicator bitmask
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 EINT_Query_HW_Debounce(void)
{
   kal_uint8 index;
   kal_uint32 status = 0x0;

   for (index = 0; index < EINT_ALL_NUMBER; index++)
   {
      if ( (EINT_FUNC[index].eint_func) && 
            ((EINT_CheckNotHWDebounce(index)) || !EINT_Get_HW_Debounce_Enable(index)) )
      {
         status |= (0x1 << index);;
      }
   }

   return status;
}
#endif

/*************************************************************************
* FUNCTION
*  EINT64_Query_HW_Debounce
*
* DESCRIPTION
*   This function dedicates to query the hardware debounce status
*   interrupts.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*   The hardware debounce disabled indicator bitmask
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint64 EINT64_Query_HW_Debounce(void)
{
   kal_uint8 index;
   kal_uint64 status = 0x0;
   kal_uint64 bitset = 0x1;

   for (index = 0; index < EINT_ALL_NUMBER; index++)
   {
      if ( (EINT_FUNC[index].eint_func) && 
            ((EINT_CheckNotHWDebounce(index)) || !EINT_Get_HW_Debounce_Enable(index)) )
      {
         status |= (bitset << index);;
      }
   }

   return status;
}

#if defined(__NEW_EINT_DEBOUNCE_FLOW__)
/*************************************************************************
* FUNCTION
*  EINT_Set_HW_Debounce
*
* DESCRIPTION
*   This function dedicates to set the hardware debounce time of external 
*   interrupts.
*
* CALLS
*
* PARAMETERS
*   eintno   -   External interrupt vector number
*   ms       -   hardware debounce time (in milli second)
*
* RETURNS
*   No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_Set_HW_Debounce(kal_uint8 eintno, kal_uint32 ms)
{
   kal_uint8  prescaler;
   kal_uint32 cnt;
   kal_uint16 count;

#if defined (__EINT_DIE2DIE__)
   if(IS_ADIE_EINT(eintno))
   {
      ADIE_EINT_Set_HW_Debounce(EINT_GLB_TO_ADIE(eintno), ms);
      
      return;
   }
#endif

   if(ms == 0)
   {
       /* set to one 32KHz clock cycle */
       prescaler = EINT_CON_PRESCALER_32KHZ;
       cnt = 1;
   }
   else if(ms <= 62)
   {
       prescaler = EINT_CON_PRESCALER_32KHZ;
       cnt = (ms << 5) + ms;
   }
   else if(ms <= 125)
   {
       prescaler = EINT_CON_PRESCALER_16KHZ;
       cnt = (ms << 4) + (ms >> 1);
   }
   else if(ms <= 250)
   {
       prescaler = EINT_CON_PRESCALER_8KHZ;
       cnt = (ms << 3) + (ms >> 2);
   }
   else if(ms <= 500)
   {
       prescaler = EINT_CON_PRESCALER_4KHZ;
       cnt = (ms << 2) + (ms >> 3);
   }
   else if(ms <= 1000)
   {
       prescaler = EINT_CON_PRESCALER_2KHZ;
       cnt = (ms << 1) + (ms >> 4);
   }
   else if(ms <= 2000)
   {
       prescaler = EINT_CON_PRESCALER_1KHZ;
       cnt = ms + (ms >> 5);
   }
   else if(ms <= 4000)
   {
       prescaler = EINT_CON_PRESCALER_512HZ;
       cnt = (ms >> 1) + (ms >> 6);
   }
   else if(ms <= 8000)
   {
       prescaler = EINT_CON_PRESCALER_256HZ;
       cnt = (ms >> 2) + (ms >> 7);
   }
   else
   {
      /* set to maximum prescaler/count */
       prescaler = EINT_CON_PRESCALER_256HZ;
       cnt = EINT_CON_DEBOUNCE;
   }

   if( cnt > EINT_CON_DEBOUNCE)
   {
       cnt = EINT_CON_DEBOUNCE;
   }
   
   /* mask eint before modifying debounce value */
   EINT_Mask(eintno);

   /* disable HW debounce */
   EINTaddr(eintno) &= ~(EINT_CON_DEBOUNCE_EN);

   /* clear original prescalar and debounce value */
   EINTaddr(eintno) &= ~(EINT_CON_PRESCALER_MASK | EINT_CON_DEBOUNCE);

   /* wait for 3T 32khz */
   ust_busy_wait(100);

   /* set new debounce value and enable debounce control circuit */
   EINTaddr(eintno) |= (EINT_CON_DEBOUNCE_EN | (EINT_CON_PRESCALER_MASK & (prescaler << EINT_CON_PRESCALER_OFFSET)) | cnt);

   /* wait for 3T 32khz */
   ust_busy_wait(100);

   /* reset the debounce counter */
   EINTaddr(eintno) |= EINT_CON_DEBOUNCE_RST;

   /* wait for 3T 32khz */
   ust_busy_wait(100);

   /* ack spurious interrupt */
   EINT_AckInt(eintno);
   
   /* unmask eint after modifying debounce value */
   EINT_UnMask(eintno);
}

#elif defined(__CIRQ_DESIGN_NEW__) || defined(__CIRQ_HW_V3__)
/*************************************************************************
* FUNCTION
*  EINT_Set_HW_Debounce
*
* DESCRIPTION
*   This function dedicates to set the hardware debounce time of external 
*   interrupts.
*
* CALLS
*
* PARAMETERS
*   eintno   -   External interrupt vector number
*   ms       -   hardware debounce time (in milli second)
*
* RETURNS
*   No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
// MTK02782 add 20110316 {
void EINT_Set_HW_Debounce(kal_uint8 eintno, kal_uint32 ms)
{
   kal_uint8  prescaler;
   kal_uint32 cnt;
   kal_uint16 count;

#if defined (__EINT_DIE2DIE__)
   if(IS_ADIE_EINT(eintno))
   {
      ADIE_EINT_Set_HW_Debounce(EINT_GLB_TO_ADIE(eintno), ms);
      
      return;
   }
#endif

   if(ms == 0)
   {
       /* set to one 32KHz clock cycle */
       prescaler = EINT_CON_PRESCALER_32KHZ;
       cnt = 1;
   }
   else if(ms <= 62)
   {
       prescaler = EINT_CON_PRESCALER_32KHZ;
       cnt = (ms << 5) + ms;
   }
   else if(ms <= 125)
   {
       prescaler = EINT_CON_PRESCALER_16KHZ;
       cnt = (ms << 4) + (ms >> 1);
   }
   else if(ms <= 250)
   {
       prescaler = EINT_CON_PRESCALER_8KHZ;
       cnt = (ms << 3) + (ms >> 2);
   }
   else if(ms <= 500)
   {
       prescaler = EINT_CON_PRESCALER_4KHZ;
       cnt = (ms << 2) + (ms >> 3);
   }
   else if(ms <= 1000)
   {
       prescaler = EINT_CON_PRESCALER_2KHZ;
       cnt = (ms << 1) + (ms >> 4);
   }
   else if(ms <= 2000)
   {
       prescaler = EINT_CON_PRESCALER_1KHZ;
       cnt = ms + (ms >> 5);
   }
   else if(ms <= 4000)
   {
       prescaler = EINT_CON_PRESCALER_512HZ;
       cnt = (ms >> 1) + (ms >> 6);
   }
   else if(ms <= 8000)
   {
       prescaler = EINT_CON_PRESCALER_256HZ;
       cnt = (ms >> 2) + (ms >> 7);
   }
   else
   {
      /* set to maximum prescaler/count */
       prescaler = EINT_CON_PRESCALER_256HZ;
       cnt = EINT_CON_DEBOUNCE;
   }

   if( cnt > EINT_CON_DEBOUNCE)
   {
       cnt = EINT_CON_DEBOUNCE;
   }
   
   /* clear original debounce value */
   EINTaddr(eintno) &= ~EINT_CON_DEBOUNCE;

   /* mask eint before modifying debounce value */
   EINT_Mask(eintno);

   /* clear original prescalar */
   EINTaddr(eintno) &= ~EINT_CON_PRESCALER_MASK;

   /* disable HW debounce */
   EINTaddr(eintno) &= ~EINT_CON_DEBOUNCE_EN;

   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. To make sure *
   * the de-bounce is disabled before the wait loop, a dummy read   *
   * operation is added. The operation to disable de-bounce takes   *
   * 4T APB cycle, and this will complete before the dummy read     *
   * operation.                                                     *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    EINT_F2S_DUMMY_READ();
#endif

   /* wait for 5T 32khz  */
   for (count=0; count<1250; count++) ;  /*250:52M*/

   /* set new debounce value and enable debounce control circuit */
   EINTaddr(eintno) |= (cnt | EINT_CON_DEBOUNCE_EN | (EINT_CON_PRESCALER_MASK&(prescaler<<EINT_CON_PRESCALER_OFFSET)));
   
   /* unmask eint after modifying debounce value */
   EINT_UnMask(eintno);
}
// } MTK02782 add 20110316 

#else
/*************************************************************************
* FUNCTION
*  EINT_Set_HW_Debounce
*
* DESCRIPTION
*   This function dedicates to set the hardware debounce time of external 
*   interrupts.
*
* CALLS
*
* PARAMETERS
*   eintno   -   External interrupt vector number
*   ms       -   hardware debounce time (in milli second)
*
* RETURNS
*   No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_Set_HW_Debounce(kal_uint8 eintno, kal_uint32 ms)
{
   kal_uint32 cnt;

#if defined (__EINT_DIE2DIE__)
   if(IS_ADIE_EINT(eintno))
   {
      ADIE_EINT_Set_HW_Debounce(EINT_GLB_TO_ADIE(eintno), ms);
         
      return;
   }
#endif

   if(ms == 0)
   {
      /* set to one 32KHz clock cycle */
      cnt = 1;
   }
   else if(ms <= 62)
   {
      /* calculate cnt value based on 32KHz clock cycles */
      cnt = ms << 5;
   }
   else
   {
      /* set to maximum count */
       cnt = EINT_CON_DEBOUNCE;
   }

   /* clear original debounce value */
   EINTaddr(eintno) &= ~EINT_CON_DEBOUNCE;

   /* set new debounce value */
   EINTaddr(eintno) |= (cnt | EINT_CON_DEBOUNCE_EN);
}
#endif


/* add  ADIE_EINT_Set_HW_Debounce_Ext for more flexible usage. not unmask eintno at the end */
/* This function can optimize with  EINT_Set_HW_Debounce, because most of the code are same */

void EINT_Set_HW_Debounce_Ext(kal_uint8 eintno, kal_uint32 ms)
{
   kal_uint8  prescaler;
   kal_uint32 cnt;
   kal_uint16 count;

#if defined (__EINT_DIE2DIE__)
   if(IS_ADIE_EINT(eintno))
   {
      ADIE_EINT_Set_HW_Debounce_Ext(EINT_GLB_TO_ADIE(eintno), ms);
      
      return;
   }
#endif

   if(ms == 0)
   {
       /* set to one 32KHz clock cycle */
       prescaler = EINT_CON_PRESCALER_32KHZ;
       cnt = 1;
   }
   else if(ms <= 62)
   {
       prescaler = EINT_CON_PRESCALER_32KHZ;
       cnt = (ms << 5) + ms;
   }
   else if(ms <= 125)
   {
       prescaler = EINT_CON_PRESCALER_16KHZ;
       cnt = (ms << 4) + (ms >> 1);
   }
   else if(ms <= 250)
   {
       prescaler = EINT_CON_PRESCALER_8KHZ;
       cnt = (ms << 3) + (ms >> 2);
   }
   else if(ms <= 500)
   {
       prescaler = EINT_CON_PRESCALER_4KHZ;
       cnt = (ms << 2) + (ms >> 3);
   }
   else if(ms <= 1000)
   {
       prescaler = EINT_CON_PRESCALER_2KHZ;
       cnt = (ms << 1) + (ms >> 4);
   }
   else if(ms <= 2000)
   {
       prescaler = EINT_CON_PRESCALER_1KHZ;
       cnt = ms + (ms >> 5);
   }
   else if(ms <= 4000)
   {
       prescaler = EINT_CON_PRESCALER_512HZ;
       cnt = (ms >> 1) + (ms >> 6);
   }
   else if(ms <= 8000)
   {
       prescaler = EINT_CON_PRESCALER_256HZ;
       cnt = (ms >> 2) + (ms >> 7);
   }
   else
   {
      /* set to maximum prescaler/count */
       prescaler = EINT_CON_PRESCALER_256HZ;
       cnt = EINT_CON_DEBOUNCE;
   }

   if( cnt > EINT_CON_DEBOUNCE)
   {
       cnt = EINT_CON_DEBOUNCE;
   }
   
   /* mask eint before modifying debounce value */
   EINT_Mask(eintno);

   /* disable HW debounce */
   EINTaddr(eintno) &= ~(EINT_CON_DEBOUNCE_EN);

   /* clear original prescalar and debounce value */
   EINTaddr(eintno) &= ~(EINT_CON_PRESCALER_MASK | EINT_CON_DEBOUNCE);

   /* wait for 3T 32khz */
   ust_busy_wait(100);

   /* set new debounce value and enable debounce control circuit */
   EINTaddr(eintno) |= (EINT_CON_DEBOUNCE_EN | (EINT_CON_PRESCALER_MASK & (prescaler << EINT_CON_PRESCALER_OFFSET)) | cnt);

   /* wait for 3T 32khz */
   ust_busy_wait(100);

   /* reset the debounce counter */
   EINTaddr(eintno) |= EINT_CON_DEBOUNCE_RST;

   /* wait for 3T 32khz */
   ust_busy_wait(100);

   /* ack spurious interrupt */
   EINT_AckInt(eintno);
   
   /* unmask eint after modifying debounce value */
   //EINT_UnMask(eintno);
}


/*************************************************************************
* FUNCTION
*  EINT_Set_Polarity
*
* DESCRIPTION
*   This function sets the polarity of external interrupts
*
* CALLS
*
* PARAMETERS
*  eintno            -     External interrupt vector number
*  ACT_Polarity      -     Interrupt polarity
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_Set_Polarity(kal_uint8 eintno, kal_bool ACT_Polarity)
{
   kal_uint32 savedMask;
   kal_uint32 count;

#if defined (__EINT_DIE2DIE__)
   if(IS_ADIE_EINT(eintno))
   {
      ADIE_EINT_Set_Polarity(EINT_GLB_TO_ADIE(eintno), ACT_Polarity);
         
      return;
   }
#endif

   /* Save and set MCU's I,F bits to disable interrupts */
   savedMask = LockIRQ();

   /* Set external interrupt polarity */
   if (ACT_Polarity) 
      EINTaddr(eintno) |= EINT_CON_HIGHLEVEL;
   else
      EINTaddr(eintno) &= ~(EINT_CON_HIGHLEVEL);

   for (count=0; count<250; count++) ;  /*250:52M*/

/*-------------------------------------------------------*/
	  // check in for MT6261 eint number exceed 32
#if (EINT_TOTAL_CHANNEL > 32)
		  if (eintno < 32)
			  *EINT_INTACK0 = EINT_INTACK_EINT(eintno);
		  else
			  *EINT_INTACK1 = EINT_INTACK_EINT(eintno - 32);
#else
   *EINT_INTACK = EINT_INTACK_EINT(eintno);

#endif    
	  
/*--------------------------------------------------------*/
#if defined(IRQ_EOI2)
   *IRQ_EOI2 = IRQCode2Line[IRQ_EIT_CODE];
#else   
   *IRQ_EOI = (1 << IRQCode2Line[IRQ_EIT_CODE]);
#endif
   
   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. The EINT ACK *
   * may not complete after return from this function and this will *
   * cause  unexpected EINT being triggered. The workaround is to   *
   * read one dummy register. The ACK operation will take effect    *
   * after 4T and it will complete before the dummy read            *
   * transaction. Therefore, the mask operation completes before    *
   * return from  this function.                                    *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    EINT_F2S_DUMMY_READ();
#endif

   /* Restore previous MCU's I,F bits setting */
   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  EINT_Set_Sensitivity
*
* DESCRIPTION
*   This function dedicates to set the sensitivity of external 
*   interrupts.
*
* CALLS
*
* PARAMETERS
*   eintno   -   External interrupt vector number
*   sens     -   EDGE_SENSITIVE or LEVEL_SENSITIVE
*
* RETURNS
*   0 for success; 1 for failure
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 EINT_Set_Sensitivity(kal_uint8 eintno, kal_bool sens)
{
   kal_uint32 savedMask;

#if defined (__EINT_DIE2DIE__)
   if(IS_ADIE_EINT(eintno))
   {
      return ADIE_EINT_Set_Sensitivity(EINT_GLB_TO_ADIE(eintno), sens);
   }
#endif
   
   if ( EINT_CheckNotHWDebounce(eintno) ){
      /* not support level trigger */
      return 1;
   }
   /* Save and set MCU's I,F bits to disable interrupts */
   savedMask = LockIRQ();

#if defined(__CIRQ_DESIGN_NEW__)
/*-------------------------------------------------------*/
		 // check in for MT6261 eint number exceed 32
#if (EINT_TOTAL_CHANNEL > 32)
		 if (sens == EDGE_SENSITIVE)
		 {
			if (eintno < 32)
			   *EINT_SENS_CLR0 = (1 << eintno);
			else
			   *EINT_SENS_CLR1 = (1 << (eintno - 32));
		 } 
		 else if (sens == LEVEL_SENSITIVE) 
		 {
			if (eintno < 32)
			   *EINT_SENS_SET0 = (1 << eintno);
			else
			   *EINT_SENS_SET1 = (1 << (eintno - 32));
		 }
#else //(EINT_TOTAL_CHANNEL > 32)
   if (sens == EDGE_SENSITIVE) {
      *EINT_SENS_CLR = (1 << eintno);
   } else if (sens == LEVEL_SENSITIVE) {
      *EINT_SENS_SET = (1 << eintno);
   }
#endif    
		 
/*--------------------------------------------------------*/

   
#else  //__CIRQ_DESIGN_NEW__
   if (sens == EDGE_SENSITIVE) {
      *EINT_SENS &= ~(1 << eintno);
   } else if (sens == LEVEL_SENSITIVE) {
      *EINT_SENS |= (1 << eintno);
   }
#endif

   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. The EINT     *
   * sensitivity may not complete after return from this function   *
   * and this may cause unexpected EINT being triggered. The        *
   * workaround is to read one dummy register. The set polarity     *
   * operation will take effect after 4T and it will complete       *
   * before the dummy read transaction. Therefore, the set polarity *
   * operation completes before return from this function.          *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    EINT_F2S_DUMMY_READ();
#endif

   /* Restore previous MCU's I,F bits setting */
   RestoreIRQ(savedMask);

   return 0;
}


/*************************************************************************
* FUNCTION
*  EINT_Mask
*
* DESCRIPTION
*   This function implements mask of dedicated external interrupt source
*
* CALLS
*
* PARAMETERS
*  eintno         - external interrupt vector number
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_Mask(kal_uint8 eintno)
{
   /* get the return address */
   if (eintno == eint_mask_monitor_idx)
   {
      GET_RETURN_ADDRESS(eint_mask_caller);
   }

#if defined (__EINT_DIE2DIE__)
   if(IS_ADIE_EINT(eintno))
   {
      ADIE_EINT_Mask(EINT_GLB_TO_ADIE(eintno));
         
      return;
   }
#endif

/*-------------------------------------------------------*/
			// check in for MT6261 eint number exceed 32
#if (EINT_TOTAL_CHANNEL > 32)
		if (eintno < 32){
			*EINT_MASK_SET0	  = (0x0001 << eintno);}
		else{
			*EINT_MASK_SET1	  = (0x0001 << (eintno - 32));}
#else //(EINT_TOTAL_CHANNEL > 32)
   *EINT_MASK_SET = (0x0001 << eintno);
#endif    

/*--------------------------------------------------------*/
   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. The eint may *
   * not be really masked after return from this function and may   *
   * cause race conidition. The work around is to read one register *
   * to force write complete.                                       *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    EINT_F2S_DUMMY_READ();
#endif
}

/*************************************************************************
* FUNCTION
*  EINT_UnMask
*
* DESCRIPTION
*   This function implements Unmask of dedicated external interrupt source
*
* CALLS
*
* PARAMETERS
*  eintno         - external interrupt vector number
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_UnMask(kal_uint8 eintno)
{
   /* get the return address */
   if (eintno == eint_unmask_monitor_idx)
   {
      GET_RETURN_ADDRESS(eint_unmask_caller);
   }

#if defined (__EINT_DIE2DIE__)
      if(IS_ADIE_EINT(eintno))
      {
         ADIE_EINT_UnMask(EINT_GLB_TO_ADIE(eintno));
            
         return;
      }
#endif
   
/*-------------------------------------------------------*/
			// check in for MT6261 eint number exceed 32
#if (EINT_TOTAL_CHANNEL > 32)
		if (eintno < 32){
			*EINT_MASK_CLR0	  = (0x0001 << eintno);}
		else{
			*EINT_MASK_CLR1	  = (0x0001 << (eintno - 32));}
#else //(EINT_TOTAL_CHANNEL > 32)
   *EINT_MASK_CLR = (0x0001 << eintno);
#endif    

/*--------------------------------------------------------*/
}


/*************************************************************************
* FUNCTION
*  EINT_SaveAndMask
*
* DESCRIPTION
*  This function saves and masks the specified external interrupt
*
* PARAMETERS
*  eintno   -   external interrupt vector number
*
* RETURNS
*  original mask
*
*************************************************************************/
kal_uint32 EINT_SaveAndMask(kal_uint8 eintno)
{
   kal_uint32 savedMask, eint_mask;

   /* lockout interrupt */
   savedMask = LockIRQ();

#if defined (__EINT_DIE2DIE__)
   if(IS_ADIE_EINT(eintno))
   {
   /* save EINT mask */
      eint_mask = ADIE_EINT_Get_Mask();

      /* clear unnecessary bits */
      eint_mask = ((eint_mask >> EINT_GLB_TO_ADIE(eintno)) & 0x1) ;
   }
   else
#endif
   {
      /* save EINT mask */      

#if (EINT_TOTAL_CHANNEL > 32)
			  if (eintno < 32){
				  eint_mask = (*EINT_MASK0 >> eintno) & 0x1;}
			  else{
				  eint_mask = (*EINT_MASK1 >> (eintno - 32)) & 0x1;}
#else //(EINT_TOTAL_CHANNEL > 32)
		 eint_mask = (*EINT_MASK >> eintno) & 0x1;
#endif
      
      /* clear unnecessary bits */
   }

   /* mask EINT */
   EINT_Mask(eintno);

   /* un-lockout interrupt */
   RestoreIRQ(savedMask);

   return eint_mask;
}

/*************************************************************************
* FUNCTION
*  EINT_RestoreMask
*
* DESCRIPTION
*  This function restores the MASK of the specified external interrupt
*
* PARAMETERS
*  val   -   value to restore
*
* RETURNS
*  No return
*
*************************************************************************/
void EINT_RestoreMask(kal_uint8 eintno, kal_uint32 val)
{
   kal_uint32 savedMask;


   /* lockout interrupt */   
   savedMask = LockIRQ();

   /*
    * NoteXXX: The external interrup should already be masked here (via the
    *          EINT_SaveAndMask() call). Only need to change the EINT_MASK 
    *          when the external interrupt is originally un-masked.
    */
   if (val == 0) {
       EINT_UnMask(eintno);
   }
   
   /* un-lockout interrupt */
   RestoreIRQ(savedMask);
}



#if !defined(__TOTAL_EINT_EXCEED_INT32__)
/*************************************************************************
* FUNCTION
*  EINT_SaveAndMaskAll
*
* DESCRIPTION
*  This function saves and masks the specified external interrupt
*
* PARAMETERS
*  eintno   -   external interrupt vector number
*
* RETURNS
*  original mask
*
*************************************************************************/
kal_uint32 EINT_SaveAndMaskAll(void)
{
   kal_uint32 savedMask, eint_mask, eint_new_mask;

#if (EINT_TOTAL_CHANNEL < 32)
      eint_new_mask = (1<<EINT_TOTAL_CHANNEL)-1;
#else
      eint_new_mask = 0xffffffff;
#endif

   /* lockout interrupt */
   savedMask = LockIRQ();

   /* save EINT mask */
   eint_mask = *EINT_MASK;

   /* mask EINT */
   *EINT_MASK_SET = eint_new_mask;

   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. The eint may *
   * not be really masked after return from this function and may   *
   * cause race conidition. The workaround is to read one register  *
   * to force write complete.                                       *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    EINT_F2S_DUMMY_READ();
#endif

#if defined(__EINT_DIE2DIE__)
   {
      kal_uint32 adie_mask;

      adie_mask = ADIE_EINT_SaveAndMaskAll();
      
      eint_mask |= EINT_MASK_ADIE_TO_GLB(adie_mask);
   }
#endif
   /* un-lockout interrupt */
   RestoreIRQ(savedMask);

   return eint_mask;
}

/*************************************************************************
* FUNCTION
*  EINT_RestoreMaskAll
*
* DESCRIPTION
*  This function restores the MASK of the specified external interrupt
*
* PARAMETERS
*  val   -   value to restore
*
* RETURNS
*  No return
*
*************************************************************************/
void EINT_RestoreMaskAll(kal_uint32 val)
{
   kal_uint32 savedMask;
   kal_uint32 RTC_Count1, RTC_Count2;
   
#if !defined(__HW_US_TIMER_SUPPORT__)   
   RTC_Count1 = *(volatile kal_uint32 *)(TDMA_base + 0x230);
   do{
      RTC_Count2 = *(volatile kal_uint32 *)(TDMA_base + 0x230);
   }while( (RTC_Count2 - RTC_Count1) < 2);
#endif

   /* lockout interrupt */   
   savedMask = LockIRQ();

   /*
    * NoteXXX: The external interrupt should already be masked here (via the
    *          EINT_SaveAndMask() call). Only need to change the EINT_MASK 
    *          when the external interrupt is originally un-masked.
    */
   *EINT_MASK_SET = 0xffffffff;
   *EINT_MASK_CLR = ~(val);
   
   /* un-lockout interrupt */
   RestoreIRQ(savedMask);

#if defined(__EINT_DIE2DIE__)
   ADIE_EINT_RestoreMaskAll(EINT_MASK_GLB_TO_ADIE(val));
#endif   
}
#endif

/*************************************************************************
* FUNCTION
*  EINT64_SaveAndMaskAll
*
* DESCRIPTION
*  This function saves and masks the specified external interrupt
*
* PARAMETERS
*  eintno   -   external interrupt vector number
*
* RETURNS
*  original mask
*
*************************************************************************/
kal_uint64 EINT64_SaveAndMaskAll(void)
{
   kal_uint32 savedMask, eint_new_mask;
   kal_uint64 eint_mask;

#if (EINT_TOTAL_CHANNEL < 32)
      eint_new_mask = (1<<EINT_TOTAL_CHANNEL)-1;
#else
      eint_new_mask = (1 << (EINT_TOTAL_CHANNEL-32)) - 1;//used in EINT_MASK_SET1
#endif

   /* lockout interrupt */
   savedMask = LockIRQ();

   /* save EINT mask */
/*-------------------------------------------------------*/
// check in for MT6261 eint number exceed 32
#if (EINT_TOTAL_CHANNEL > 32)
	   eint_mask = *EINT_MASK_SET0;
	   eint_mask |= (((kal_uint64)(*EINT_MASK_SET1)) << 32);
#else
   eint_mask = *EINT_MASK;
#endif
/*-------------------------------------------------------*/
   /* mask EINT */
/*-------------------------------------------------------*/
// check in for MT6261 eint number exceed 32
#if (EINT_TOTAL_CHANNEL > 32)
			   *EINT_MASK_SET0	 = 0xffffffff;
			   *EINT_MASK_SET1	 = eint_new_mask;
#else //(EINT_TOTAL_CHANNEL > 32)
   *EINT_MASK_SET = eint_new_mask;
#endif    
			   
/*--------------------------------------------------------*/

   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. The eint may *
   * not be really masked after return from this function and may   *
   * cause race conidition. The workaround is to read one register  *
   * to force write complete.                                       *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    EINT_F2S_DUMMY_READ();
#endif

#if defined(__EINT_DIE2DIE__)
   {
      kal_uint64 adie_mask;

      adie_mask = ADIE_EINT_SaveAndMaskAll();
      
      eint_mask |= EINT_MASK_ADIE_TO_GLB(adie_mask);
   }
#endif
   /* un-lockout interrupt */
   RestoreIRQ(savedMask);

   return eint_mask;
}

/*************************************************************************
* FUNCTION
*  EINT64_RestoreMaskAll
*
* DESCRIPTION
*  This function restores the MASK of the specified external interrupt
*
* PARAMETERS
*  val   -   value to restore
*
* RETURNS
*  No return
*
*************************************************************************/
void EINT64_RestoreMaskAll(kal_uint64 val)
{
   kal_uint32 savedMask;
   kal_uint32 RTC_Count1, RTC_Count2;
   
#if !defined(__HW_US_TIMER_SUPPORT__)   
   RTC_Count1 = *(volatile kal_uint32 *)(TDMA_base + 0x230);
   do{
      RTC_Count2 = *(volatile kal_uint32 *)(TDMA_base + 0x230);
   }while( (RTC_Count2 - RTC_Count1) < 2);
#endif

   /* lockout interrupt */   
   savedMask = LockIRQ();

   /*
    * NoteXXX: The external interrupt should already be masked here (via the
    *          EINT_SaveAndMask() call). Only need to change the EINT_MASK 
    *          when the external interrupt is originally un-masked.
    */

   /*-------------------------------------------------------*/
   // check in for MT6261 eint number exceed 32
#if (EINT_TOTAL_CHANNEL > 32)
				  *EINT_MASK_SET0 = 0xffffffff;
				  *EINT_MASK_SET1 = 0xffffffff;
				  *EINT_MASK_CLR0 = ~((kal_uint32)val);
				  *EINT_MASK_CLR1 = ~((kal_uint32)((val >> 32) & ((1 << (EINT_TOTAL_CHANNEL-32)) - 1)));
#else //(EINT_TOTAL_CHANNEL > 32)
   *EINT_MASK_SET = 0xffffffff;
   *EINT_MASK_CLR = ~((kal_uint32)val);
#endif    
   
   /*--------------------------------------------------------*/
   /* un-lockout interrupt */
   RestoreIRQ(savedMask);

#if defined(__EINT_DIE2DIE__)
   ADIE_EINT_RestoreMaskAll((kal_uint32)EINT_MASK_GLB_TO_ADIE(val));
#endif   
}

#if defined(__EINT_SW_DEBOUNCE_V2__)
/*************************************************************************
* FUNCTION
*  EINT_TIMER_CALLBACK
*
* DESCRIPTION
*   This function implements main external interrupt LISR registered in
*  global ISR jump table.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_TIMER_CALLBACK(void *data)
{
   EINT_SW_DEBOUNCE_STRUCT *sw_debounce = (EINT_SW_DEBOUNCE_STRUCT *)data;

   /* IRQ need not be masked since EINT_TIMER_CALLBACK has no race condition problem with EINT_HISRY_Entry and EINT_LISR */
   //IRQMask(IRQ_EIT_CODE);

   if(sw_debounce->eint_sw_debounce_handle != 0x7f)
   {
      DclSGPT_Control(sw_debounce->eint_sw_debounce_handle,SGPT_CMD_STOP,0);
      DclSGPT_Close(&(sw_debounce->eint_sw_debounce_handle));
   }

   sw_debounce->eint_intr_allow = (sw_debounce->eint_intr_allow == KAL_TRUE)? KAL_FALSE: KAL_TRUE;

   /*
    * This timer is to avoid if interrupt status is changed but 
    * sw_debounce->eint_intr_allow is still in KAL_TRUE state
    * because of no interrupt
    */
   if (sw_debounce->eint_intr_allow) 
   {
      SGPT_CTRL_START_T start;

      start.u2Tick= eint_sw_debounce_time_delay[sw_debounce->eint_no];

      start.pfCallback=EINT_TIMER_CALLBACK;
      start.vPara=data;
      sw_debounce->eint_sw_debounce_handle=DclSGPT_Open(DCL_GPT_CB,0);
      DclSGPT_Control(sw_debounce->eint_sw_debounce_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
   }
   //IRQUnmask(IRQ_EIT_CODE);
   EINT_UnMask(sw_debounce->eint_no);
}

#else /* #if defined(__EINT_SW_DEBOUNCE_V2__) */

/*************************************************************************
* FUNCTION
*  EINT_TIMER_CALLBACK
*
* DESCRIPTION
*   This function implements main external interrupt LISR registered in
*  global ISR jump table.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_TIMER_CALLBACK(void *data)
{
   EINT_SW_DEBOUNCE_STRUCT *sw_debounce = (EINT_SW_DEBOUNCE_STRUCT *)data;

   IRQMask(IRQ_EIT_CODE);
#if defined(__EINT_DIE2DIE__)
   IRQMask(IRQ_ADIE_EIT_CODE);
#endif

   if(sw_debounce->eint_sw_debounce_handle != 0x7f)
   {
      DclSGPT_Control(sw_debounce->eint_sw_debounce_handle,SGPT_CMD_STOP,0);
      DclSGPT_Close(&(sw_debounce->eint_sw_debounce_handle));
   }

   sw_debounce->eint_intr_allow = (sw_debounce->eint_intr_allow == KAL_TRUE)? KAL_FALSE: KAL_TRUE;

   /*
    * This timer is to avoid if interrupt status is changed but 
    * sw_debounce->eint_intr_allow is still in KAL_TRUE state
    * because of no interrupt
    */
   if (sw_debounce->eint_intr_allow) 
   {
      SGPT_CTRL_START_T start;

      start.u2Tick= eint_sw_debounce_time_delay[sw_debounce->eint_no];

      start.pfCallback=EINT_TIMER_CALLBACK;
      start.vPara=data;
      sw_debounce->eint_sw_debounce_handle=DclSGPT_Open(DCL_GPT_CB,0);
      DclSGPT_Control(sw_debounce->eint_sw_debounce_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
   }
   IRQUnmask(IRQ_EIT_CODE);
#if defined(__EINT_DIE2DIE__)   
   IRQUnmask(IRQ_ADIE_EIT_CODE);
#endif
   EINT_UnMask(sw_debounce->eint_no);
}

#endif    /* __EINT_SW_DEBOUNCE_V2__ */

/*************************************************************************
* FUNCTION
*   EINT_SW_Debounce_Init
*
* DESCRIPTION
*   Initialize debounce time
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void EINT_SW_Debounce_Init(void)
{
   kal_uint8 index;

   for (index = 0; index < EINT_ALL_NUMBER; index++)
   {
      eint_sw_debounce[index].eint_sw_debounce_handle = 0x7f;

      if( EINT_HW_DEBOUNCE(index) )
      {
         eint_sw_debounce[index].eint_intr_allow = KAL_FALSE;
         eint_sw_debounce[index].eint_no = index;
      }
   }

   eint_sw_debounce_time_delay = custom_config_eint_sw_debounce_time_delay();
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


/*************************************************************************
* FUNCTION
*   EINT_SW_Debounce_Modify
*
* DESCRIPTION
*   Setting debounce time
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
kal_int32 EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time)
{
   kal_uint32 savedMask;
   
   if ( EINT_CheckNotHWDebounce(eintno))
      return -1;

   if(NULL == eint_sw_debounce_time_delay)
   {
       eint_sw_debounce_time_delay = custom_config_eint_sw_debounce_time_delay();
   }
   
   savedMask = DisableIRQ();      
   eint_sw_debounce_time_delay[eintno] = debounce_time;
   RestoreIRQ(savedMask);
   
   return 1;
}

/*************************************************************************
* FUNCTION
*  EINT_SetSWRegister
*
* DESCRIPTION
*  This function set EINT SW interrupt register
*
* PARAMETERS
*
* RETURNS
*  none
*  
*************************************************************************/
void EINT_SetSWRegister(kal_uint8 eintno)
{
#if defined(__EINT_DIE2DIE__)
    if(IS_ADIE_EINT(eintno))
    {
        ADIE_EINT_SetSWRegister(EINT_GLB_TO_ADIE(eintno));
        return;
    }
#endif    
    
#ifdef __CIRQ_DESIGN_NEW__
/*-------------------------------------------------------*/
// check in for MT6261 eint number exceed 32
#if (EINT_TOTAL_CHANNEL > 32)
	   if (eintno < 32){
		   *EINT_SOFT_SET0	 = (0x0001 << eintno);}
	   else{
		   *EINT_SOFT_SET1	 = (0x0001 << (eintno - 32));}
#else
    *EINT_SOFT_SET = (1 << eintno);
#endif
/*-------------------------------------------------------*/

#elif defined(EINT_SOFT)
    kal_uint32 savedMask = LockIRQ();
    *EINT_SOFT |= (1<<eintno);
    RestoreIRQ(savedMask);
#endif
}

/*************************************************************************
* FUNCTION
*  EINT_ResetSWRegister
*
* DESCRIPTION
*  This function set EINT SW interrupt register
*
* PARAMETERS
*
* RETURNS
*  none
*  
*************************************************************************/
void EINT_ResetSWRegister(kal_uint8 eintno)
{
#if defined(__EINT_DIE2DIE__)
    if(IS_ADIE_EINT(eintno))
    {
        ADIE_EINT_ResetSWRegister(EINT_GLB_TO_ADIE(eintno));
        return;
    }
#endif    
    
#ifdef __CIRQ_DESIGN_NEW__
/*-------------------------------------------------------*/
// check in for MT6261 eint number exceed 32
#if (EINT_TOTAL_CHANNEL > 32)
	   if (eintno < 32){
		   *EINT_SOFT_CLR0	= (0x0001 << eintno);}
	   else{
		   *EINT_SOFT_CLR1	= (0x0001 << (eintno - 32));}
#else
    *EINT_SOFT_CLR = (1 << eintno);
#endif
/*-------------------------------------------------------*/

#elif defined(EINT_SOFT)
    kal_uint32 savedMask = LockIRQ();
    *EINT_SOFT &= ~(1<<eintno);
    RestoreIRQ(savedMask);
#endif
}

/*************************************************************************
* FUNCTION
*  EINT_AckInt
*
* DESCRIPTION
*  This function acks interrupt and clears status bit.
*
* PARAMETERS
*
* RETURNS
*  none
*
*************************************************************************/
void EINT_AckInt(kal_uint8 eintno)
{
#if defined(__EINT_DIE2DIE__)
    if(IS_ADIE_EINT(eintno))
    {
        ADIE_EINT_AckInt(EINT_GLB_TO_ADIE(eintno));
        return;
    }
#endif
    
   /*-------------------------------------------------------*/
   // check in for MT6261 eint number exceed 32
#if (EINT_TOTAL_CHANNEL > 32)
		  if (eintno < 32){
			  *EINT_INTACK0  = EINT_INTACK_EINT(eintno);}
		  else{
			  *EINT_INTACK1  = EINT_INTACK_EINT(eintno - 32);}
#else
    *EINT_INTACK = EINT_INTACK_EINT(eintno);
#endif
   /*-------------------------------------------------------*/
   /*****************************************************************
   * In fast-to-slow bus architecture, bus will response write ack  *
   * before the value is really written into register. The eint may *
   * not be really acknowlege dafter return from this function and  *
   * may cause unexpected interrupt. The workaround is to read one  *
   * register to force write complete.                              *
   *                                                                *
   * This work around should be removed after following chips       *
   * phased out: MT6255.                                            *
   *****************************************************************/
#if defined(__F2S_REGISTER_WRITE_ACK__)
    /* read a dummy register common to all platform */
    EINT_F2S_DUMMY_READ();
#endif
}

#if defined(__AST_TL1_TDD__) && defined(__CIRQ_DESIGN_NEW__)    /* EINT_D0EN is only designed in __CIRQ_DESIGN_NEW__ */
/*************************************************************************
* FUNCTION
*  EINT_Set_Domain
*
* DESCRIPTION
*  This function set EINT Domain 0 Register
*
* PARAMETERS
*
* RETURNS
*  none
*  
* GLOBALS AFFECTE
*
*************************************************************************/
void EINT_Set_Domain_Disable(kal_uint8 eintno)
{
    /*********************************************************************
      * This function is only used under MT6256E2 with AST configuration. The reason is
      * AST is connected to CINT originally, but there is a bug in MT6256E2 that interrupt 
      * from CINT cannot resume chip from sleep mode, and only EINT can do this.
      * Therefore, interrupt from AST will be connected to CIRQ (via CINT) and EINT to
      * resume chip from sleep mode when an interrupt is triggered. In this case, EINT
      * will triggered interrupt to CIRQ by EINT, which means there will be two sources
      * trigger interrut to CIRQ for the same event. To avoid this, we provide this API
      * to prevent EINT which is connected to AST from issuing interrupt to CIRQ and only 
      * CINT will trigger interrupt to CIRQ in this case.
      *******************************************************************/
    kal_uint32 savedMask, eint_en_mask;
	
    ASSERT(eintno < EINT_TOTAL_CHANNEL);

    savedMask = LockIRQ();

    eint_en_mask = *EINT_D0EN;
    eint_en_mask &= ~(1 << eintno);
    *EINT_D0EN = eint_en_mask;

    RestoreIRQ(savedMask);
}
#endif

