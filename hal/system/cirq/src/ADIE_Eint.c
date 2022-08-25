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
 *   ADIE_Eint.c
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
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*************************************************************************
 * Included header files
 *************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "Eint.h"
#include "dcl.h"
#include "drv_hisr.h"
#include "us_timer.h"

#if defined(__EINT_DIE2DIE__)

/*************************************************************************
 * Define imported global variables
 *************************************************************************/
extern kal_uint8 ADIE_IRQCode2Line[ADIE_NUM_IRQ_SOURCES];
extern eint_func_t EINT_FUNC[EINT_ALL_NUMBER];
extern EINT_SW_DEBOUNCE_STRUCT eint_sw_debounce[EINT_ALL_NUMBER];
extern kal_uint8 *eint_sw_debounce_time_delay;

/*************************************************************************
 * Define function prototpye
 *************************************************************************/
kal_uint32 LockIRQ(void);
void RestoreIRQ(kal_uint32 irq);
void ADIE_EINT_Mask(kal_uint8 eintno);
void ADIE_EINT_UnMask(kal_uint8 eintno);
void ADIE_EINT_AckInt(kal_uint8 eintno);
void EINT_TIMER_CALLBACK(void *data);
void EINT_Mask(kal_uint8 eintno);
void EINT_AckInt(kal_uint8 eintno);
kal_bool EINT_Internal_LISR_Handler(kal_uint32* status);

/*************************************************************************
* FUNCTION
*  ADIE_EINT_HW_Initialize
*
* DESCRIPTION
*   This function implements HW initialization of A-DIE EINT
*
* CALLS
*
* PARAMETERS
*  eintno            -     External interrupt vector number
*  Dbounce_En        -     Debounce control enable
*  ACT_Polarity      -     Interrupt polarity
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
 *************************************************************************/
void ADIE_EINT_HW_Initialize(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity)
{
    kal_uint32 savedMask;
    kal_uint16 count;

    /* Save and set MCU's I,F bits to disable interrupts */
    savedMask = LockIRQ();

    /* Set external interrupt polarity */
    if (ACT_Polarity) 
        ADIE_EINTaddr(eintno) |= EINT_CON_HIGHLEVEL;
    else
        ADIE_EINTaddr(eintno) &= ~(EINT_CON_HIGHLEVEL);

#if (ADIE_EINT_TOTAL_CHANNEL > 16)
    if (eintno < 16)
        *ADIE_EINT_D0EN0 |= (1 << eintno);
    else
        *ADIE_EINT_D0EN1 |= (1 << (eintno - 16));
#else
    *ADIE_EINT_D0EN |= (1 << eintno);
#endif    

    /* Set external interrupt debounce control enable or not */
    if (Dbounce_En) {
        /* check if debounce is enabled */
        if (ADIE_EINTaddr(eintno) & EINT_CON_DEBOUNCE_EN) {
            /* debounce value is already set; NOP */
        } else {
            ADIE_EINTaddr(eintno) |= (EINT_CON_DEBOUNCE | EINT_CON_DEBOUNCE_EN);
        }
    }
    else
    {
        /*disable debounce */
        ADIE_EINTaddr(eintno) &= ~(EINT_CON_DEBOUNCE_EN);
    }

    /* Restore previous MCU's I,F bits setting */
    RestoreIRQ(savedMask);

    for (count=0; count<250; count++) ;  /*250:52M*/

    savedMask = LockIRQ();

    ADIE_EINT_AckInt(eintno);
    
    ADIE_EINT_UnMask(eintno);

    RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*   ADIE_EINT_GET_HW_Debounce_Enable
*
* DESCRIPTION
*   This function get HW de-bounce enable status of one EINT
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
kal_bool ADIE_EINT_GET_HW_Debounce_Enable(kal_uint8 eintno)
{
    if(ADIE_EINTaddr(eintno) & EINT_CON_DEBOUNCE_EN)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

#if defined(__NEW_EINT_DEBOUNCE_FLOW__)
/*************************************************************************
* FUNCTION
*  ADIE_EINT_Set_HW_Debounce
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
void ADIE_EINT_Set_HW_Debounce(kal_uint8 eintno, kal_uint32 ms)
{
    kal_uint8  prescaler;
    kal_uint32 cnt;
    kal_uint16 count;

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
    ADIE_EINT_Mask(eintno);

    /* disable HW debounce */
    ADIE_EINTaddr(eintno) &= ~(EINT_CON_DEBOUNCE_EN);

    /* clear original prescalar and debounce value */
    ADIE_EINTaddr(eintno) &= ~(EINT_CON_PRESCALER_MASK | EINT_CON_DEBOUNCE);

    /* wait for 3T 32khz */
    ust_busy_wait(100);

    /* set new debounce value and enable debounce control circuit */
    ADIE_EINTaddr(eintno) |= (EINT_CON_DEBOUNCE_EN | (EINT_CON_PRESCALER_MASK & (prescaler << EINT_CON_PRESCALER_OFFSET)) | cnt);

    /* wait for 3T 32khz */
    ust_busy_wait(100);

    /* reset the debounce counter */
#if (ADIE_EINT_TOTAL_CHANNEL > 16)
    if (eintno < 16)
        *ADIE_EINT_DBCRST0 |= (0x1 << (eintno));
    else
        *ADIE_EINT_DBCRST1 |= (0x1 << (eintno - 16));
#else
    *ADIE_EINT_DBCRST |= (0x1 << (eintno));
#endif

    /* wait for 3T 32khz */
    ust_busy_wait(100);

    /* ack spurious interrupt */
    ADIE_EINT_AckInt(eintno);

    /* unmask eint after modifying debounce value */
    ADIE_EINT_UnMask(eintno);
}

#else
/*************************************************************************
* FUNCTION
*  ADIE_EINT_Set_HW_Debounce
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
void ADIE_EINT_Set_HW_Debounce(kal_uint8 eintno, kal_uint32 ms)
{
    kal_uint8  prescaler;
    kal_uint32 cnt;
    kal_uint16 count;

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
    ADIE_EINTaddr(eintno) &= ~EINT_CON_DEBOUNCE;

    /* mask eint before modifying debounce value */
    ADIE_EINT_Mask(eintno);

    /* clear original prescalar */
    ADIE_EINTaddr(eintno) &= ~EINT_CON_PRESCALER_MASK;
 
    /* disable HW debounce */
    ADIE_EINTaddr(eintno) &= ~EINT_CON_DEBOUNCE_EN;

    /* wait for 5T 32khz  */
    for (count=0; count<1250; count++) ;  /*250:52M*/

    /* set new debounce value and enable debounce control circuit */
    ADIE_EINTaddr(eintno) |= (cnt | EINT_CON_DEBOUNCE_EN | (EINT_CON_PRESCALER_MASK&(prescaler<<EINT_CON_PRESCALER_OFFSET)));
   
    /* unmask eint after modifying debounce value */
    ADIE_EINT_UnMask(eintno);
}
#endif


/* add  ADIE_EINT_Set_HW_Debounce_Ext for more flexible usage. not unmask eintno at the end */
void ADIE_EINT_Set_HW_Debounce_Ext(kal_uint8 eintno, kal_uint32 ms)
{
	kal_uint8  prescaler;
	kal_uint32 cnt;
	kal_uint16 count;

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
	ADIE_EINT_Mask(eintno);

	/* disable HW debounce */
	ADIE_EINTaddr(eintno) &= ~(EINT_CON_DEBOUNCE_EN);

	/* clear original prescalar and debounce value */
	ADIE_EINTaddr(eintno) &= ~(EINT_CON_PRESCALER_MASK | EINT_CON_DEBOUNCE);

	/* wait for 3T 32khz */
	ust_busy_wait(100);

	/* set new debounce value and enable debounce control circuit */
	ADIE_EINTaddr(eintno) |= (EINT_CON_DEBOUNCE_EN | (EINT_CON_PRESCALER_MASK & (prescaler << EINT_CON_PRESCALER_OFFSET)) | cnt);

	/* wait for 3T 32khz */
	ust_busy_wait(100);

	/* reset the debounce counter */
#if (ADIE_EINT_TOTAL_CHANNEL > 16)
	if (eintno < 16)
		*ADIE_EINT_DBCRST0 |= (0x1 << (eintno));
	else
		*ADIE_EINT_DBCRST1 |= (0x1 << (eintno - 16));
#else
	*ADIE_EINT_DBCRST |= (0x1 << (eintno));
#endif

	/* wait for 3T 32khz */
	ust_busy_wait(100);

	/* ack spurious interrupt */
	ADIE_EINT_AckInt(eintno);

	/* unmask eint after modifying debounce value */
	//ADIE_EINT_UnMask(eintno);
}


/*************************************************************************
* FUNCTION
*  ADIE_EINT_Set_Polarity
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
void ADIE_EINT_Set_Polarity(kal_uint8 eintno, kal_bool ACT_Polarity)
{
    kal_uint32 savedMask;
    kal_uint32 count;

    /* Save and set MCU's I,F bits to disable interrupts */
    savedMask = LockIRQ();

    /* Set external interrupt polarity */
    if (ACT_Polarity) 
        ADIE_EINTaddr(eintno) |= EINT_CON_HIGHLEVEL;
    else
        ADIE_EINTaddr(eintno) &= ~(EINT_CON_HIGHLEVEL);

    for (count=0; count<250; count++) ;  /*250:52M*/

    ADIE_EINT_AckInt(eintno);

    *ADIE_IRQ_EOI2 = ADIE_IRQCode2Line[IRQ_CODE_GLB_TO_ADIE(IRQ_ADIE_EIT_CODE)];
   
    /* Restore previous MCU's I,F bits setting */
    RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  ADIE_EINT_Set_Sensitivity
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
kal_uint32 ADIE_EINT_Set_Sensitivity(kal_uint8 eintno, kal_bool sens)
{
   kal_uint32 savedMask;

   /* Save and set MCU's I,F bits to disable interrupts */
   savedMask = LockIRQ();

#if (ADIE_EINT_TOTAL_CHANNEL > 16)
   if (sens == EDGE_SENSITIVE) {
      if (eintno < 16)
         *ADIE_EINT_SENS_CLR0 = (1 << eintno);
      else
         *ADIE_EINT_SENS_CLR1 = (1 << (eintno - 16));
   } else if (sens == LEVEL_SENSITIVE) {
      if (eintno < 16)
         *ADIE_EINT_SENS_SET0 = (1 << eintno);
      else
         *ADIE_EINT_SENS_SET1 = (1 << (eintno - 16));
   }
#else
   if (sens == EDGE_SENSITIVE) {
      *ADIE_EINT_SENS_CLR = (1 << eintno);
   } else if (sens == LEVEL_SENSITIVE) {
      *ADIE_EINT_SENS_SET = (1 << eintno);
   }
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
void ADIE_EINT_Mask(kal_uint8 eintno)
{
    /* disable wakeup sleep mode */
#if (ADIE_EINT_TOTAL_CHANNEL > 16)
    if (eintno < 16)
    {
        *ADIE_EINT_WAKE_MASK_SET0 = (0x0001 << eintno); 
        *ADIE_EINT_MASK_SET0      = (0x0001 << eintno);
    }
    else
    {
        *ADIE_EINT_WAKE_MASK_SET1 = (0x0001 << (eintno - 16)); 
        *ADIE_EINT_MASK_SET1      = (0x0001 << (eintno - 16));
    }
#else
    *ADIE_EINT_WAKE_MASK_SET = (0x0001 << eintno);
    *ADIE_EINT_MASK_SET      = (0x0001 << eintno);
#endif
}

/*************************************************************************
* FUNCTION
*  ADIE_EINT_UnMask
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
void ADIE_EINT_UnMask(kal_uint8 eintno)
{
    /* enable wakeup sleep mode */
#if (ADIE_EINT_TOTAL_CHANNEL > 16)
    if (eintno < 16)
    {
        *ADIE_EINT_WAKE_MASK_CLR0 = (0x0001 << eintno);
        *ADIE_EINT_MASK_CLR0 = (0x0001 << eintno);
    }
    else
    {
        *ADIE_EINT_WAKE_MASK_CLR1 = (0x0001 << (eintno - 16));
        *ADIE_EINT_MASK_CLR1 = (0x0001 << (eintno - 16));
    }
#else
    *ADIE_EINT_WAKE_MASK_CLR = (0x0001 << eintno);
    *ADIE_EINT_MASK_CLR = (0x0001 << eintno);
#endif
}

/*************************************************************************
* FUNCTION
*  ADIE_EINT_SetSWRegister
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
void ADIE_EINT_SetSWRegister(kal_uint8 eintno)
{
#if (ADIE_EINT_TOTAL_CHANNEL > 16)
    if (eintno < 16)
        *ADIE_EINT_SOFT_SET0 = (1 << eintno);
    else
        *ADIE_EINT_SOFT_SET1 = (1 << (eintno - 16));
#else
    *ADIE_EINT_SOFT_SET = (1 << eintno);
#endif
}

/*************************************************************************
* FUNCTION
*  ADIE_EINT_ResetSWRegister
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
void ADIE_EINT_ResetSWRegister(kal_uint8 eintno)
{
#if (ADIE_EINT_TOTAL_CHANNEL > 16)
    if (eintno < 16)
        *ADIE_EINT_SOFT_CLR0 = (1 << eintno);
    else
        *ADIE_EINT_SOFT_CLR1 = (1 << (eintno - 16));
#else
    *ADIE_EINT_SOFT_CLR = (1 << eintno);
#endif
}

/*************************************************************************
* FUNCTION
*  ADIE_EINT_AckInt
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
void ADIE_EINT_AckInt(kal_uint8 eintno)
{
#if (ADIE_EINT_TOTAL_CHANNEL > 16)
    if (eintno < 16)
        *ADIE_EINT_INTACK0 = EINT_INTACK_EINT(eintno);
    else
        *ADIE_EINT_INTACK1 = EINT_INTACK_EINT(eintno - 16);
#else
    *ADIE_EINT_INTACK = EINT_INTACK_EINT(eintno);
#endif
}


/*************************************************************************
* FUNCTION
*  ADIE_EINT_Get_Mask
*
* DESCRIPTION
*  This function returns mask of masked EINTs.
*  System Service Internal Use
*
* PARAMETERS
*
* RETURNS
*  none
*
*************************************************************************/
kal_uint32 ADIE_EINT_Get_Mask()
{
    kal_uint32 adie_mask;

#if (ADIE_EINT_TOTAL_CHANNEL > 16)
    adie_mask = *ADIE_EINT_MASK0;
    adie_mask |= (((kal_uint32)(*ADIE_EINT_MASK1)) << 16);
#else
    adie_mask = *ADIE_EINT_MASK;
#endif
    
    return adie_mask;
}

/*************************************************************************
* FUNCTION
*  ADIE_EINT_SaveAndMaskAll
*
* DESCRIPTION
*  This function saves and masks the specified external interrupt
*
* PARAMETERS
*
* RETURNS
*  original mask
*
*************************************************************************/
kal_uint32 ADIE_EINT_SaveAndMaskAll(void)
{
    kal_uint32 savedMask, eint_mask, eint_new_mask;

#if (ADIE_EINT_TOTAL_CHANNEL < 32)
    eint_new_mask = (1<<ADIE_EINT_TOTAL_CHANNEL)-1;
#else
    eint_new_mask = 0xffffffff;
#endif
    
    /* lockout interrupt */
    savedMask = LockIRQ();
    
    /* save EINT mask */
    eint_mask = ADIE_EINT_Get_Mask();
    
    /* mask EINT */
    /* disable wakeup cleep mode of this EINTs */
#if (ADIE_EINT_TOTAL_CHANNEL > 16)    
    *ADIE_EINT_MASK_SET0 = (eint_new_mask & 0xFFFF);
    *ADIE_EINT_MASK_SET1 = (eint_new_mask >> 16);

    *ADIE_EINT_WAKE_MASK_SET0 = (eint_new_mask & 0xFFFF);    
    *ADIE_EINT_WAKE_MASK_SET1 = (eint_new_mask >> 16);
#else
    *ADIE_EINT_MASK_SET = eint_new_mask;
    
    *ADIE_EINT_WAKE_MASK_SET = eint_new_mask;
#endif
    
    /* un-lockout interrupt */
    RestoreIRQ(savedMask);
    
    return eint_mask;
}

/*************************************************************************
* FUNCTION
*  ADIE_EINT_RestoreMaskAll
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
void ADIE_EINT_RestoreMaskAll(kal_uint32 val)
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
#if (ADIE_EINT_TOTAL_CHANNEL > 16)   
    *ADIE_EINT_MASK_SET0 = (ADIE_EINT_TOTAL_MASK & 0xFFFF);
    *ADIE_EINT_MASK_CLR0 = ~(val & 0xFFFF);
    *ADIE_EINT_MASK_SET1 = (ADIE_EINT_TOTAL_MASK >> 16);
    *ADIE_EINT_MASK_CLR1 = ~(val >> 16);

    *ADIE_EINT_WAKE_MASK_SET0 = (ADIE_EINT_TOTAL_MASK & 0xFFFF);
    *ADIE_EINT_WAKE_MASK_CLR0 = ~(val & 0xFFFF);
    *ADIE_EINT_WAKE_MASK_SET1 = (ADIE_EINT_TOTAL_MASK >> 16);
    *ADIE_EINT_WAKE_MASK_CLR1 = ~(val >> 16);
#else
    *ADIE_EINT_MASK_SET = ADIE_EINT_TOTAL_MASK;
    *ADIE_EINT_MASK_CLR = ~(val);
    
    *ADIE_EINT_WAKE_MASK_SET = ADIE_EINT_TOTAL_MASK;
    *ADIE_EINT_WAKE_MASK_CLR = ~(val);
#endif

    /* un-lockout interrupt */
    RestoreIRQ(savedMask);
    
}

/*************************************************************************
* FUNCTION
*  ADIE_EINT_Get_Status()
*
* DESCRIPTION
*  Get triggered status of all A-DIE EINT. The status is expressed in mask.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 ADIE_EINT_Get_Status()
{
    kal_uint32 adie_status;

#if (ADIE_EINT_TOTAL_CHANNEL > 16)
    adie_status = (*ADIE_EINT_STATUS0) & (*ADIE_EINT_D0EN0);
    adie_status |= (((kal_uint32)((*ADIE_EINT_STATUS1) & (*ADIE_EINT_D0EN1))) << 16);
#else
    adie_status = (*ADIE_EINT_STATUS) & (*ADIE_EINT_D0EN);
#endif
    
    return adie_status;
}

/*************************************************************************
* FUNCTION
*  ADIE_EINT_Enable_Wakeup()
*
* DESCRIPTION
*  Enable wakeup when corresponding is triggered.
*
* PARAMETERS
*  eintno  -  EINT number of A-DIE
*
* RETURNS
*
*************************************************************************/
void ADIE_EINT_Enable_Wakeup(kal_uint32 eintno)
{
#if (ADIE_EINT_TOTAL_CHANNEL > 16)
    if (eintno < 16)
        *ADIE_EINT_WAKE_MASK_CLR0 = (0x0001 << eintno);
    else
        *ADIE_EINT_WAKE_MASK_CLR1 = (0x0001 << (eintno - 16));
#else
    *ADIE_EINT_WAKE_MASK_CLR = (0x0001 << eintno);
#endif
}

/*************************************************************************
* FUNCTION
*   ADIE_EINT_LISR
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
void ADIE_EINT_LISR(void)
{
   kal_uint8 index;
   kal_uint32 status;
   kal_uint8 enable_hisr = KAL_FALSE;
#if defined(__TINY_SYS__)
   kal_uint32 tp_sw_reg_status;
   kal_uint8 tp_eint_indx;
#endif

   status = ADIE_EINT_Get_Status();

   if (EINT_Internal_LISR_Handler(&status))
   {
      return;
   }

   // for conventional external interrupt!
   for(index=ADIE_EINT_START_INDEX;index<EINT_ALL_NUMBER;index++)
   {
      if(EINT_HW_DEBOUNCE(index))
      {
         if (status & EINT_STATUS_EINT(EINT_GLB_TO_ADIE(index))) 
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
				tp_eint_indx = EINT_GLB_TO_ADIE(index);
			#if (ADIE_EINT_TOTAL_CHANNEL > 16)
				if (tp_eint_indx < 16){
					tp_sw_reg_status = *ADIE_EINT_SOFT0;}
				else
				{
					tp_sw_reg_status = *ADIE_EINT_SOFT1;
					tp_eint_indx = tp_eint_indx - 16;
				}
			#else
				tp_sw_reg_status = *ADIE_EINT_SOFT;
			#endif
			
			if(0 != (tp_sw_reg_status & (1 << tp_eint_indx)))
			{
				ADIE_EINT_ResetSWRegister(EINT_GLB_TO_ADIE(index));
			}
			#endif

			/*----------------------------------------------*/
				  
               
            }

            EINT_AckInt(index);
         }
      }
      else
      {
         if (status & EINT_STATUS_EINT(EINT_GLB_TO_ADIE(index))) 
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
				tp_eint_indx = EINT_GLB_TO_ADIE(index);
			#if (ADIE_EINT_TOTAL_CHANNEL > 16)
				if (tp_eint_indx < 16){
					tp_sw_reg_status = *ADIE_EINT_SOFT0;}
				else
				{
					tp_sw_reg_status = *ADIE_EINT_SOFT1;
					tp_eint_indx = tp_eint_indx - 16;
				}
			#else
				tp_sw_reg_status = *ADIE_EINT_SOFT;
			#endif
			
			if(0 != (tp_sw_reg_status & (1 << tp_eint_indx)))
			{
				ADIE_EINT_ResetSWRegister(EINT_GLB_TO_ADIE(index));
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

#endif
