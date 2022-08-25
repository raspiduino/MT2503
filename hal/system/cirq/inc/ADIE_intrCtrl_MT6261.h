/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   ADIE_intrCtrl_MT6260.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Definition for chipset interrupt table
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
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Define CIRQ Registers
 *******************************************************************************/

#define ADIE_IRQ_MASK0              ((volatile UINT16P)(ADIE_CIRQ_base+0x0000)) /* IRQ Mask 0x00 to 0x1F */
#define ADIE_IRQ_MASK_SET0          ((volatile UINT16P)(ADIE_CIRQ_base+0x0020)) /* IRQ Mask SET 0x00 to 0x1F  */
#define ADIE_IRQ_MASK_CLR0          ((volatile UINT16P)(ADIE_CIRQ_base+0x0040)) /* IRQ Mask CLR 0x00 to 0x1F  */
#define ADIE_IRQ_SENS0              ((volatile UINT16P)(ADIE_CIRQ_base+0x0060)) /* IRQ sensitive 0x00 to 0x1F  */
#define ADIE_IRQ_SENS_SET0          ((volatile UINT16P)(ADIE_CIRQ_base+0x0080)) /* IRQ sensitive SET 0x00 to 0x1F  */
#define ADIE_IRQ_SENS_CLR0          ((volatile UINT16P)(ADIE_CIRQ_base+0x00A0)) /* IRQ sensitive CLR 0x00 to 0x1F  */
#define ADIE_IRQ_SOFT0              ((volatile UINT16P)(ADIE_CIRQ_base+0x00C0)) /* IRQ SW interrupt 0x00 to 0x1F  */
#define ADIE_IRQ_SOFT_SET0          ((volatile UINT16P)(ADIE_CIRQ_base+0x00E0)) /* IRQ SW interrupt SET 0x00 to 0x1F  */
#define ADIE_IRQ_SOFT_CLR0          ((volatile UINT16P)(ADIE_CIRQ_base+0x0100)) /* IRQ SW interrupt CLR 0x00 to 0x1F  */
#define ADIE_IRQ_ASTA0              ((volatile UINT16P)(ADIE_CIRQ_base+0x0120)) /* All IRQ status 0 */
#define ADIE_FIQ_ASTA0              ((volatile UINT16P)(ADIE_CIRQ_base+0x0140)) /* All IRQ status 0 */
#define ADIE_IRQ_EOIOH0             ((volatile UINT16P)(ADIE_CIRQ_base+0x0160)) /* IRQ end of interrupt 0x00 to 0x1F  */
#define ADIE_IRQ_FSEL0              ((volatile UINT16P)(ADIE_CIRQ_base+0x0180)) /* FIQ Source selection 0x0 to 0x1F*/
#define ADIE_IRQ_STA2               ((volatile UINT16P)(ADIE_CIRQ_base+0x01A0)) /* Binary Code Value of IRQ_STATUS */
#define ADIE_FIQ_STA2               ((volatile UINT16P)(ADIE_CIRQ_base+0x01A4)) /* Binary Code Value of FIQ_STATUS */
#define ADIE_IRQ_EOI2               ((volatile UINT16P)(ADIE_CIRQ_base+0x01A8)) /* Binary Code Value of IRQ_EOI */
#define ADIE_IRQ_PWRCON0             ((volatile UINT16P)(ADIE_CIRQ_base+0x01AC)) /* Binary Code Value of IRQ_EOI */


#define ADIE_IRQ_STV                ((volatile UINT16P)(ADIE_CIRQ_base+0x01BC)) /* CIRQ Starvation Control */

#define ADIE_IRQ_SEL0               ((volatile UINT16P)(ADIE_CIRQ_base+0x0200)) /* Source selection 0 to 1 */
#define ADIE_IRQ_SEL1               ((volatile UINT16P)(ADIE_CIRQ_base+0x0204)) /* Source selection 2 to 3 */

#define ADIE_IRQ_SEL(x)             ((volatile UINT16P)(ADIE_CIRQ_base+0x0200+0x0004*(x)))

#define ADIE_EINT_STATUS           ((volatile UINT16P)(ADIE_CIRQ_base+0x0300)) /*  external interrupt control */
#define ADIE_EINT_INTACK           ((volatile UINT16P)(ADIE_CIRQ_base+0x0308))

#define ADIE_EINT_EEVT              ((volatile UINT16P)(ADIE_CIRQ_base+0x0310))

#define ADIE_EINT_MASK             ((volatile UINT16P)(ADIE_CIRQ_base+0x0318)) /*  external interrupt control */
#define ADIE_EINT_MASK_SET         ((volatile UINT16P)(ADIE_CIRQ_base+0x0320)) /*  external interrupt control */
#define ADIE_EINT_MASK_CLR         ((volatile UINT16P)(ADIE_CIRQ_base+0x0328)) /*  external interrupt control */

#define ADIE_EINT_SENS             ((volatile UINT16P)(ADIE_CIRQ_base+0x0330)) /*  external interrupt control */ 
#define ADIE_EINT_SENS_SET         ((volatile UINT16P)(ADIE_CIRQ_base+0x0338)) /*  external interrupt control */ 
#define ADIE_EINT_SENS_CLR         ((volatile UINT16P)(ADIE_CIRQ_base+0x0340)) /*  external interrupt control */ 

#define ADIE_EINT_SOFT             ((volatile UINT16P)(ADIE_CIRQ_base+0x0348)) /*  external interrupt control */   
#define ADIE_EINT_SOFT_SET         ((volatile UINT16P)(ADIE_CIRQ_base+0x0350)) /*  external interrupt control */   
#define ADIE_EINT_SOFT_CLR         ((volatile UINT16P)(ADIE_CIRQ_base+0x0358)) /*  external interrupt control */   

#define ADIE_EINT_D0EN             ((volatile UINT16P)(ADIE_CIRQ_base+0x0360)) /*  external interrupt control */

#define ADIE_EINT0_CON              ((volatile UINT16P)(ADIE_CIRQ_base+0x0380)) /*  external interrupt control */
#define ADIE_EINT1_CON              ((volatile UINT16P)(ADIE_CIRQ_base+0x0384)) /*  external interrupt control */
#define ADIE_EINT2_CON              ((volatile UINT16P)(ADIE_CIRQ_base+0x0388)) /*  external interrupt control */
#define ADIE_EINT3_CON              ((volatile UINT16P)(ADIE_CIRQ_base+0x038C)) /*  external interrupt control */
#define ADIE_EINT4_CON              ((volatile UINT16P)(ADIE_CIRQ_base+0x0390)) /*  external interrupt control */
#define ADIE_EINT5_CON              ((volatile UINT16P)(ADIE_CIRQ_base+0x0394)) /*  external interrupt control */         
#define ADIE_EINT6_CON              ((volatile UINT16P)(ADIE_CIRQ_base+0x0398)) /*  external interrupt control */         
#define ADIE_EINT7_CON              ((volatile UINT16P)(ADIE_CIRQ_base+0x039C)) /*  external interrupt control */         
#define ADIE_EINT8_CON              ((volatile UINT16P)(ADIE_CIRQ_base+0x03A0)) /*  external interrupt control */         
#define ADIE_EINT9_CON              ((volatile UINT16P)(ADIE_CIRQ_base+0x03A4)) /*  external interrupt control */         
#define ADIE_EINT10_CON             ((volatile UINT16P)(ADIE_CIRQ_base+0x03A8)) /*  external interrupt control */
#define ADIE_EINT11_CON             ((volatile UINT16P)(ADIE_CIRQ_base+0x03AC)) /*  external interrupt control */
#define ADIE_EINT12_CON             ((volatile UINT16P)(ADIE_CIRQ_base+0x03B0)) /*  external interrupt control */
#define ADIE_EINT13_CON             ((volatile UINT16P)(ADIE_CIRQ_base+0x03B4)) /*  external interrupt control */
#define ADIE_EINT_CON(i)            ((volatile UINT16P)(ADIE_EINT0_CON+0x4*i))  /*  external interrupt control */

#define ADIE_EINT_DBCRST           ((volatile UINT16P)(ADIE_CIRQ_base+0x0410)) /*  external interrupt control */         

#define ADIE_EINT_WAKE_MASK        ((volatile UINT16P)(ADIE_CIRQ_base+0x0420)) /*  external interrupt control */         
#define ADIE_EINT_WAKE_MASK_SET    ((volatile UINT16P)(ADIE_CIRQ_base+0x0428)) /*  external interrupt control */         
#define ADIE_EINT_WAKE_MASK_CLR    ((volatile UINT16P)(ADIE_CIRQ_base+0x0430)) /*  external interrupt control */         

#define ADIE_EINTaddr(_no)          (*(volatile kal_uint16 *)(ADIE_CIRQ_base + 0x0380 + (_no) * 4))

/* D2D IRQ Macors */
#define IS_ADIE_IRQ_CODE(glb_code)        ((glb_code >= NUM_IRQ_SOURCES) && (glb_code < (NUM_IRQ_SOURCES + ADIE_NUM_IRQ_SOURCES)))
#define IRQ_CODE_GLB_TO_ADIE(glb_code)    (glb_code - NUM_IRQ_SOURCES)    /* map global code to A-DIE CIRQ code */
#define IRQ_CODE_ADIE_TO_GLB(code)        (code + NUM_IRQ_SOURCES)
#define IRQ_LINE_ADIE_TO_GLB(line)        (line + NUM_IRQ_LINES)


/*
 * ADIE CIRQ Interrupt Sources
 */
/* For IRQ user, they may not aware their IRQ is in A-DIE or D-DIE.       */
/* An IRQ code should be unique in both A-DIE and D-Die and IRQ users can */
/* call common IRQ APIs to configure A-DIE IRQ or D-DIE IRQs. We define   */
/* A-DIE IRQs as virtual IRQ code to idenity an IRQ is in A-DIE or D-DIE. */
#define IRQ_ADIE_EIT_CODE        (IRQ_CODE_ADIE_TO_GLB(0))
#define IRQ_RTC_CODE             (IRQ_CODE_ADIE_TO_GLB(1))
#define IRQ_TPC_CODE             (IRQ_CODE_ADIE_TO_GLB(2))  /* Touch Panel */
#define IRQ_ACCDET_CODE          (IRQ_CODE_ADIE_TO_GLB(3))
#define ADIE_NUM_IRQ_SOURCES     (4)


/* 
 * ADIE EINT Sources
 */
/*************************************************************************************
 * In ADIE design, EINT wakeup design is different from former chips: interrupt mask *
 * and wakeup mask are not binded together. For EINT that only needs to wakeup sleep *
 * mode but not trigger interrupt, the registration is not needed, but unmask wakeup *
 * API should be called. Following definition is for API that unmask sleep mode.     *
 *********************************************************************************** */
#define ADIE_EINT_PWRKEY_INDEX        (0)    /* power key */
#define ADIE_EINT_CHRDET_INDEX        (1)    /* charger detection */
#define ADIE_EINT_PMUOC_INDEX         (2)    /* PMU OC status */
#define ADIE_EINT_VBAT_INDEX          (3)    /* VBAT Over Voltage */
#define ADIE_EINT_CHRLDO_INDEX        (4)    /* charger LDO detection */
#define ADIE_EINT_PMU_STATUS_0_INDEX  (5)    /* PMU Thermal Status 0 */
#define ADIE_EINT_PMU_STATUS_1_INDEX  (6)    /* PMU Thermal Status 1 */
#define ADIE_EINT_PMU_STATUS_2_INDEX  (7)    /* PMU Thermal Status 2 */
#define ADIE_EINT_PMU_STATUS_3_INDEX  (8)    /* PMU Thermal Status 3 */
#define ADIE_EINT_PMU_STATUS_4_INDEX  (9)    /* PMU Thermal Status 4 */
#define ADIE_EINT_BAT_REMOVEDET_INDEX (10)    /* BAT Removal Detection */
#define ADIE_EINT_RTC_INDEX           (11)    /* RTC */
#define ADIE_EINT_TP_INDEX            (12)   /* TP */
#define ADIE_EINT_ACCDET_INDEX        (13)   /* ACCDET */

/*
 * IRQ Selection Register mapping
 */
/* map to physical IRQ code */
#define ADIE_IRQ0_CODE           (IRQ_CODE_GLB_TO_ADIE(IRQ_ADIE_EIT_CODE))
#define ADIE_IRQ1_CODE           (IRQ_CODE_GLB_TO_ADIE(IRQ_RTC_CODE))
#define ADIE_IRQ2_CODE           (IRQ_CODE_GLB_TO_ADIE(IRQ_TPC_CODE))
#define ADIE_IRQ3_CODE           (IRQ_CODE_GLB_TO_ADIE(IRQ_ACCDET_CODE))
#define ADIE_NUM_IRQ_LINES       (0x4)

/*
 * IRQ code value in Selection Register
 */
#define ADIE_IRQ0_SEL0             (ADIE_IRQ0_CODE << 0)
#define ADIE_IRQ1_SEL0             (ADIE_IRQ1_CODE << 8)
#define ADIE_IRQ2_SEL1             (ADIE_IRQ2_CODE << 0)
#define ADIE_IRQ3_SEL1             (ADIE_IRQ3_CODE << 8)

/*
 * Define IRQ line mapping table
 */
#define ADIE_IRQ_LINE_MAPPING_TABLE \
	ADIE_IRQ0_CODE,  ADIE_IRQ1_CODE,  ADIE_IRQ2_CODE,  ADIE_IRQ3_CODE

/*
 * Define IRQ selection register assignment
 */
#define ADIE_IRQSel()     do { \
   *ADIE_IRQ_SEL0 = ADIE_IRQ0_SEL0  | ADIE_IRQ1_SEL0; \
   *ADIE_IRQ_SEL1 = ADIE_IRQ2_SEL1  | ADIE_IRQ3_SEL1; \
   } while(0)

/*************************************************************************
 * EINT Configuration
 *************************************************************************/
#define  ADIE_EINT_START_INDEX          EINT_TOTAL_CHANNEL
#define  ADIE_EINT_MAX_CHANNEL          14
#define  ADIE_EINT_TOTAL_CHANNEL        14
#define  ADIE_EINT_HARDWARE_DEBOUNCE    0x3FFF
#define  ADIE_EINT_TOTAL_MASK           0x3FFF

#define IS_ADIE_EINT(eintno)             (((eintno) >= ADIE_EINT_START_INDEX) && ((eintno) < (ADIE_EINT_START_INDEX + ADIE_EINT_TOTAL_CHANNEL)))
#define EINT_GLB_TO_ADIE(eintno)         ((eintno) - ADIE_EINT_START_INDEX)    /* map global EINT to A-DIE EINT */

#define EINT_MASK_GLB_TO_ADIE(mask)      ((mask) >> ADIE_EINT_START_INDEX)
#define EINT_MASK_ADIE_TO_GLB(mask)      ((mask) << ADIE_EINT_START_INDEX)
