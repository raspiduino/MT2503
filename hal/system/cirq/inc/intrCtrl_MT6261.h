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
 *   intrCtrl_MT6260.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Define CIRQ Registers
 *******************************************************************************/

#define IRQ_MASK0              ((volatile UINT32P)(CIRQ_base+0x0000)) /* IRQ Mask 0x00 to 0x1F */
#define IRQ_MASK1              ((volatile UINT32P)(CIRQ_base+0x0004)) /* IRQ Mask 0x20 to 0x3F */

#define IRQ_MASK_SET0          ((volatile UINT32P)(CIRQ_base+0x0020)) /* IRQ Mask SET 0x00 to 0x1F  */
#define IRQ_MASK_SET1          ((volatile UINT32P)(CIRQ_base+0x0024)) /* IRQ Mask SET 0x20 to 0x3F */

#define IRQ_MASK_CLR0          ((volatile UINT32P)(CIRQ_base+0x0040)) /* IRQ Mask CLR 0x00 to 0x1F  */
#define IRQ_MASK_CLR1          ((volatile UINT32P)(CIRQ_base+0x0044)) /* IRQ Mask CLR 0x20 to 0x3F */

#define IRQ_SENS0              ((volatile UINT32P)(CIRQ_base+0x0060)) /* IRQ sensitive 0x00 to 0x1F  */
#define IRQ_SENS1              ((volatile UINT32P)(CIRQ_base+0x0064)) /* IRQ sensitive 0x20 to 0x3F */

#define IRQ_SENS_SET0          ((volatile UINT32P)(CIRQ_base+0x0080)) /* IRQ sensitive SET 0x00 to 0x1F  */
#define IRQ_SENS_SET1          ((volatile UINT32P)(CIRQ_base+0x0084)) /* IRQ sensitive SET 0x20 to 0x3F */

#define IRQ_SENS_CLR0          ((volatile UINT32P)(CIRQ_base+0x00A0)) /* IRQ sensitive CLR 0x00 to 0x1F  */
#define IRQ_SENS_CLR1          ((volatile UINT32P)(CIRQ_base+0x00A4)) /* IRQ sensitive CLR 0x20 to 0x3F */

#define IRQ_SOFT0              ((volatile UINT32P)(CIRQ_base+0x00C0)) /* IRQ SW interrupt 0x00 to 0x1F  */
#define IRQ_SOFT1              ((volatile UINT32P)(CIRQ_base+0x00C4)) /* IRQ SW interrupt 0x20 to 0x3F */

#define IRQ_SOFT_SET0          ((volatile UINT32P)(CIRQ_base+0x00E0)) /* IRQ SW interrupt SET 0x00 to 0x1F  */
#define IRQ_SOFT_SET1          ((volatile UINT32P)(CIRQ_base+0x00E4)) /* IRQ SW interrupt SET 0x20 to 0x3F */

#define IRQ_SOFT_CLR0          ((volatile UINT32P)(CIRQ_base+0x0100)) /* IRQ SW interrupt CLR 0x00 to 0x1F  */
#define IRQ_SOFT_CLR1          ((volatile UINT32P)(CIRQ_base+0x0104)) /* IRQ SW interrupt CLR 0x20 to 0x3F */

#define IRQ_ASTA0              ((volatile UINT32P)(CIRQ_base+0x0120)) /* All IRQ status 0 */
#define IRQ_ASTA1              ((volatile UINT32P)(CIRQ_base+0x0124)) /* All IRQ status 1 */

#define FIQ_ASTA0              ((volatile UINT32P)(CIRQ_base+0x0140)) /* All FIQ status 0 */
#define FIQ_ASTA1              ((volatile UINT32P)(CIRQ_base+0x0144)) /* All FIQ status 1 */

#define IRQ_EOIOH0             ((volatile UINT32P)(CIRQ_base+0x0160)) /* IRQ end of interrupt 0x00 to 0x1F  */
#define IRQ_EOIOH1             ((volatile UINT32P)(CIRQ_base+0x0164)) /* IRQ end of interrupt 0x20 to 0x3F */

#define IRQ_FSEL0              ((volatile UINT32P)(CIRQ_base+0x0180)) /* FIQ Source selection 0x0 to 0x1F*/
#define IRQ_FSEL1              ((volatile UINT32P)(CIRQ_base+0x0184)) /* FIQ Source selection 0x20 to 0x3F*/

#define IRQ_STA2               ((volatile UINT32P)(CIRQ_base+0x01A0)) /* Binary Code Value of IRQ_STATUS */
#define FIQ_STA2               ((volatile UINT32P)(CIRQ_base+0x01A4)) /* Binary Code Value of FIQ_STATUS */
#define IRQ_EOI2               ((volatile UINT32P)(CIRQ_base+0x01A8)) /* Binary Code Value of IRQ_EOI */

#define IRQ_STV                ((volatile UINT32P)(CIRQ_base+0x01BC)) /* CIRQ Starvation Control */

#define IRQ_SEL0               ((volatile UINT32P)(CIRQ_base+0x0200)) /* Source selection 0 to 3 */
#define IRQ_SEL1               ((volatile UINT32P)(CIRQ_base+0x0204)) /* Source selection 4 to 7 */
#define IRQ_SEL2               ((volatile UINT32P)(CIRQ_base+0x0208)) /* Source selection 8 to 0xB */
#define IRQ_SEL3               ((volatile UINT32P)(CIRQ_base+0x020C)) /* Source selection 0xC to 0xF */
#define IRQ_SEL4               ((volatile UINT32P)(CIRQ_base+0x0210)) /* Source selection 0x10 to 0x13 */

#define IRQ_SEL(x)             ((volatile UINT32P)(CIRQ_base+0x0200+0x0004*(x)))

#define EINT_STATUS0            ((volatile UINT32P)(CIRQ_base+0x0300)) /*  external interrupt control */   
#define EINT_STATUS1            ((volatile UINT32P)(CIRQ_base+0x0304)) /*  external interrupt control */   

#define EINT_INTACK0            ((volatile UINT32P)(CIRQ_base+0x0308))
#define EINT_INTACK1            ((volatile UINT32P)(CIRQ_base+0x030C))

#define EINT_EEVT              ((volatile UINT32P)(CIRQ_base+0x0310))

#define EINT_MASK0              ((volatile UINT32P)(CIRQ_base+0x0318)) /*  external interrupt control */
#define EINT_MASK1              ((volatile UINT32P)(CIRQ_base+0x031C)) /*  external interrupt control */
#define EINT_MASK_SET0          ((volatile UINT32P)(CIRQ_base+0x0320)) /*  external interrupt control */
#define EINT_MASK_SET1          ((volatile UINT32P)(CIRQ_base+0x0324)) /*  external interrupt control */
#define EINT_MASK_CLR0          ((volatile UINT32P)(CIRQ_base+0x0328)) /*  external interrupt control */
#define EINT_MASK_CLR1          ((volatile UINT32P)(CIRQ_base+0x032C)) /*  external interrupt control */

#define EINT_SENS0              ((volatile UINT32P)(CIRQ_base+0x0330)) /*  external interrupt control */ 
#define EINT_SENS1              ((volatile UINT32P)(CIRQ_base+0x0334)) /*  external interrupt control */ 
#define EINT_SENS_SET0          ((volatile UINT32P)(CIRQ_base+0x0338)) /*  external interrupt control */ 
#define EINT_SENS_SET1          ((volatile UINT32P)(CIRQ_base+0x033C)) /*  external interrupt control */ 
#define EINT_SENS_CLR0          ((volatile UINT32P)(CIRQ_base+0x0340)) /*  external interrupt control */ 
#define EINT_SENS_CLR1          ((volatile UINT32P)(CIRQ_base+0x0344)) /*  external interrupt control */ 

#define EINT_SOFT0              ((volatile UINT32P)(CIRQ_base+0x0348)) /*  external interrupt control */   
#define EINT_SOFT1              ((volatile UINT32P)(CIRQ_base+0x034C)) /*  external interrupt control */   
#define EINT_SOFT_SET0          ((volatile UINT32P)(CIRQ_base+0x0350)) /*  external interrupt control */   
#define EINT_SOFT_SET1          ((volatile UINT32P)(CIRQ_base+0x0354)) /*  external interrupt control */   
#define EINT_SOFT_CLR0          ((volatile UINT32P)(CIRQ_base+0x0358)) /*  external interrupt control */   
#define EINT_SOFT_CLR1          ((volatile UINT32P)(CIRQ_base+0x035C)) /*  external interrupt control */   

#define EINT_D0EN0              ((volatile UINT32P)(CIRQ_base+0x0360)) /*  external interrupt control */
#define EINT_D0EN1              ((volatile UINT32P)(CIRQ_base+0x0364)) /*  external interrupt control */

#define EINT0_CON              ((volatile UINT32P)(CIRQ_base+0x0380)) /*  external interrupt control */
#define EINT1_CON              ((volatile UINT32P)(CIRQ_base+0x0384)) /*  external interrupt control */
#define EINT2_CON              ((volatile UINT32P)(CIRQ_base+0x0388)) /*  external interrupt control */
#define EINT3_CON              ((volatile UINT32P)(CIRQ_base+0x038C)) /*  external interrupt control */
#define EINT4_CON              ((volatile UINT32P)(CIRQ_base+0x0390)) /*  external interrupt control */
#define EINT5_CON              ((volatile UINT32P)(CIRQ_base+0x0394)) /*  external interrupt control */         
#define EINT6_CON              ((volatile UINT32P)(CIRQ_base+0x0398)) /*  external interrupt control */         
#define EINT7_CON              ((volatile UINT32P)(CIRQ_base+0x039C)) /*  external interrupt control */         
#define EINT8_CON              ((volatile UINT32P)(CIRQ_base+0x03A0)) /*  external interrupt control */         
#define EINT9_CON              ((volatile UINT32P)(CIRQ_base+0x03A4)) /*  external interrupt control */         
#define EINT10_CON             ((volatile UINT32P)(CIRQ_base+0x03A8)) /*  external interrupt control */         
#define EINT11_CON             ((volatile UINT32P)(CIRQ_base+0x03AC)) /*  external interrupt control */         
#define EINT12_CON             ((volatile UINT32P)(CIRQ_base+0x03B0)) /*  external interrupt control */         
#define EINT13_CON             ((volatile UINT32P)(CIRQ_base+0x03B4)) /*  external interrupt control */         
#define EINT14_CON             ((volatile UINT32P)(CIRQ_base+0x03B8)) /*  external interrupt control */         
#define EINT15_CON             ((volatile UINT32P)(CIRQ_base+0x03BC)) /*  external interrupt control */  
#define EINT16_CON             ((volatile UINT32P)(CIRQ_base+0x03C0)) /*  external interrupt control */         
#define EINT17_CON             ((volatile UINT32P)(CIRQ_base+0x03C4)) /*  external interrupt control */         
#define EINT18_CON             ((volatile UINT32P)(CIRQ_base+0x03C8)) /*  external interrupt control */         
#define EINT19_CON             ((volatile UINT32P)(CIRQ_base+0x03CC)) /*  external interrupt control */ 
#define EINT20_CON             ((volatile UINT32P)(CIRQ_base+0x03D0)) /*  external interrupt control */         
#define EINT21_CON             ((volatile UINT32P)(CIRQ_base+0x03D4)) /*  external interrupt control */         
#define EINT22_CON             ((volatile UINT32P)(CIRQ_base+0x03D8)) /*  external interrupt control */  
#define EINT23_CON             ((volatile UINT32P)(CIRQ_base+0x03DC)) /*  external interrupt control */         
#define EINT24_CON             ((volatile UINT32P)(CIRQ_base+0x03E0)) /*  external interrupt control */         
#define EINT25_CON             ((volatile UINT32P)(CIRQ_base+0x03E4)) /*  external interrupt control */         
#define EINT26_CON             ((volatile UINT32P)(CIRQ_base+0x03E8)) /*  external interrupt control */ 
#define EINT27_CON             ((volatile UINT32P)(CIRQ_base+0x03EC)) /*  external interrupt control */         
#define EINT28_CON             ((volatile UINT32P)(CIRQ_base+0x03F0)) /*  external interrupt control */  
#define EINT29_CON             ((volatile UINT32P)(CIRQ_base+0x03F4)) /*  external interrupt control */         
#define EINT30_CON             ((volatile UINT32P)(CIRQ_base+0x03F8)) /*  external interrupt control */         
#define EINT31_CON             ((volatile UINT32P)(CIRQ_base+0x03FC)) /*  external interrupt control */         
#define EINT32_CON             ((volatile UINT32P)(CIRQ_base+0x0400)) /*  external interrupt control */ 


#define EINT_CON(i)            ((volatile UINT32P)(EINT0_CON+i))   /*  external interrupt control */

/*
 * CIRQ Interrupt Sources
 */
#define IRQ_TDMA_CODE               (0)
#define IRQ_CTIRQ1_CODE             (1)
#define IRQ_CTIRQ2_CODE             (2)
#define IRQ_RESERVED_3_CODE         (3)
#define IRQ_RESERVED_4_CODE         (4)
#define IRQ_RESERVED_5_CODE         (5)
#define IRQ_SW_LISR1_CODE           (6)
#define IRQ_SW_LISR2_CODE           (7)
#define IRQ_MD_SLEEP_CODE           (8)
#define IRQ_RESERVED_9_CODE         (9)
#define IRQ_DIE2DIE_CODE            (10)  //WHAT IS THIS?
#define IRQ_OSTIMER_ARM_CODE        (11)
#define IRQ_TOPSM_CODE            	(12)
#define IRQ_SIM_CODE                (13)
#define IRQ_DMA_CODE                (14)
#define IRQ_UART1_CODE              (15)
#define IRQ_KPAD_CODE               (16)
#define IRQ_UART2_CODE              (17)
#define IRQ_GPT_CODE                (18)
#define IRQ_EIT_CODE                (19)
#define IRQ_USB_CODE                (20)
#define IRQ_MSDC_CODE               (21)
#define IRQ_SFI_CODE                (22)
#define IRQ_LCD_CODE                (23)
#define IRQ_UART3_CODE              (24)
#define IRQ_WDT_CODE                (25)
#define IRQ_DSP2CPU_CODE            (26)
#define IRQ_RESZ_CODE               (27)
#define IRQ_G2D_CODE                (28)
#define IRQ_MSDC_CD_CODE            (29)
#define IRQ_SPI_CODE                (30)
#define IRQ_I2C_CODE                (31)
#define IRQ_IRDEBUG_CODE            (32)
#define IRQ_SIM2_CODE               (33)
#define IRQ_CAMERA_CODE             (34)
#define IRQ_TIMCON_CODE             (35)
#define IRQ_ROT_DMA_CODE            (36)
#define IRQ_PAD2CAM_CODE            (37)
#define IRQ_BTIF_CODE               (38)
#define IRQ_RESERVED_39_CODE        (39)
#define IRQ_RESERVED_40_CODE        (40)
#define IRQ_RESERVED_41_CODE        (41)
#define IRQ_FM_CODE                 (42) 
#define IRQ_MSDC2_CODE              (43)  
#define IRQ_MSDC2_CD_CODE           (44)  
#define IRQ_SPISLV_CODE             (45)  
#define IRQ_I2C_18V_CODE            (46)  
#define IRQ_RESERVED_47_CODE        (47)  
#define NUM_IRQ_SOURCES             (48) 

/* IRQ_INVALIDE_CODE is used to map to IRQ line which map to fix IRQ code    */
/* when this IRQ code is switched to patch priority (13 ~ 17). When one IRQ  */
/* source map to fix priority needs to be changed to patch priority, be sure */
/* to change the corresponding IRQ code to IRQ_INVALID_CODE. One physical    */
/* IRQ source can only map to one priority. The last IRQ source is used to   */
/* map unused patch priority.                                                */
#define IRQ_INVALID_CODE            (NUM_IRQ_SOURCES - 1)
   
/*
 * IRQ Selection Register mapping
 */
#define IRQ0_CODE           IRQ_TDMA_CODE
#define IRQ1_CODE           IRQ_CTIRQ1_CODE
#define IRQ2_CODE           IRQ_CTIRQ2_CODE
#define IRQ3_CODE           IRQ_RESERVED_3_CODE
#define IRQ4_CODE           IRQ_RESERVED_4_CODE
#define IRQ5_CODE           IRQ_RESERVED_5_CODE
#define IRQ6_CODE           IRQ_SW_LISR1_CODE
#define IRQ7_CODE           IRQ_SW_LISR2_CODE
#define IRQ8_CODE           IRQ_MD_SLEEP_CODE
#define IRQ9_CODE           IRQ_RESERVED_9_CODE  //IRQ_HIF_1_CODE
#define IRQA_CODE           IRQ_DIE2DIE_CODE
#define IRQB_CODE           IRQ_OSTIMER_ARM_CODE
#define IRQC_CODE           IRQ_TOPSM_CODE
/* IRQ0xD ~ IRQ0x11 is designed for patch purpose.                        */
/* Low priority IRQ can be assigned with one of these priorities to raise */
#define IRQD_CODE           IRQ_INVALID_CODE    /* Patch priority. It is not used currently.  */
#define IRQE_CODE           IRQ_INVALID_CODE    /* Patch priority. It is not used currently.  */
#define IRQF_CODE           IRQ_INVALID_CODE    /* Patch priority. It is not used currently.  */
#define IRQ10_CODE          IRQ_INVALID_CODE    /* Patch priority. It is not used currently.  */
#define IRQ11_CODE          IRQ_INVALID_CODE    /* Patch priority. It is not used currently.  */
/* IRQ0x12 ~ IRQ0x34  can not selct source */
#define IRQ12_CODE          IRQ_SIM_CODE
#define IRQ13_CODE          IRQ_DMA_CODE
#define IRQ14_CODE          IRQ_UART1_CODE
#define IRQ15_CODE          IRQ_KPAD_CODE
#define IRQ16_CODE          IRQ_UART2_CODE
#define IRQ17_CODE          IRQ_GPT_CODE
#define IRQ18_CODE          IRQ_EIT_CODE
#define IRQ19_CODE          IRQ_USB_CODE
#define IRQ1A_CODE          IRQ_MSDC_CODE
#define IRQ1B_CODE          IRQ_SFI_CODE
#define IRQ1C_CODE          IRQ_LCD_CODE
#define IRQ1D_CODE          IRQ_UART3_CODE  //IRQ_UART3_CODE
#define IRQ1E_CODE          IRQ_WDT_CODE
#define IRQ1F_CODE          IRQ_DSP2CPU_CODE
#define IRQ20_CODE          IRQ_RESZ_CODE
#define IRQ21_CODE          IRQ_G2D_CODE 
#define IRQ22_CODE          IRQ_MSDC_CD_CODE
#define IRQ23_CODE          IRQ_SPI_CODE
#define IRQ24_CODE          IRQ_I2C_CODE
#define IRQ25_CODE          IRQ_IRDEBUG_CODE
#define IRQ26_CODE          IRQ_SIM2_CODE
#define IRQ27_CODE          IRQ_CAMERA_CODE
#define IRQ28_CODE          IRQ_TIMCON_CODE
#define IRQ29_CODE          IRQ_ROT_DMA_CODE
#define IRQ2A_CODE          IRQ_PAD2CAM_CODE
#define IRQ2B_CODE          IRQ_BTIF_CODE
#define IRQ2C_CODE          IRQ_RESERVED_39_CODE  //IRQ_LZMA_CODE
#define IRQ2D_CODE          IRQ_RESERVED_40_CODE  //IRQ_RESERVED_40_CODE
#define IRQ2E_CODE          IRQ_RESERVED_41_CODE
#define IRQ2F_CODE          IRQ_FM_CODE  //IRQ_RESERVED_42_CODE
#define IRQ30_CODE          IRQ_MSDC2_CODE  //IRQ_RESERVED_43_CODE
#define IRQ31_CODE          IRQ_MSDC2_CD_CODE  //IRQ_RESERVED_44_CODE
#define IRQ32_CODE          IRQ_SPISLV_CODE
#define IRQ33_CODE          IRQ_I2C_18V_CODE
#define IRQ34_CODE          IRQ_RESERVED_47_CODE
#define NUM_IRQ_LINES       (0x35)

/*
 * IRQ code value in Selection Register
 */
#define IRQ0_SEL0             (IRQ0_CODE << 0)
#define IRQ1_SEL0             (IRQ1_CODE << 8)
#define IRQ2_SEL0             (IRQ2_CODE << 16)
#define IRQ3_SEL0             (IRQ3_CODE << 24)

#define IRQ4_SEL1             (IRQ4_CODE << 0)
#define IRQ5_SEL1             (IRQ5_CODE << 8)
#define IRQ6_SEL1             (IRQ6_CODE << 16)
#define IRQ7_SEL1             (IRQ7_CODE << 24)

#define IRQ8_SEL2             (IRQ8_CODE << 0)
#define IRQ9_SEL2             (IRQ9_CODE << 8)
#define IRQA_SEL2             (IRQA_CODE << 16)
#define IRQB_SEL2             (IRQB_CODE << 24)

#define IRQC_SEL3             (IRQC_CODE << 0)
#define IRQD_SEL3             (IRQD_CODE << 8)
#define IRQE_SEL3             (IRQE_CODE << 16)
#define IRQF_SEL3             (IRQF_CODE << 24)

#define IRQ10_SEL4            (IRQ10_CODE << 0)
#define IRQ11_SEL4            (IRQ11_CODE << 8)


/*
 * Define IRQ line mapping table
 */
#define IRQ_LINE_MAPPING_TABLE \
	IRQ0_CODE,  IRQ1_CODE,  IRQ2_CODE,  IRQ3_CODE, \
	IRQ4_CODE,  IRQ5_CODE,  IRQ6_CODE,  IRQ7_CODE, \
	IRQ8_CODE,  IRQ9_CODE,  IRQA_CODE,  IRQB_CODE, \
	IRQC_CODE,  IRQD_CODE,  IRQE_CODE,  IRQF_CODE, \
	IRQ10_CODE, IRQ11_CODE, IRQ12_CODE, IRQ13_CODE, \
	IRQ14_CODE, IRQ15_CODE, IRQ16_CODE, IRQ17_CODE, \
	IRQ18_CODE, IRQ19_CODE, IRQ1A_CODE, IRQ1B_CODE, \
	IRQ1C_CODE, IRQ1D_CODE, IRQ1E_CODE, IRQ1F_CODE, \
	IRQ20_CODE, IRQ21_CODE, IRQ22_CODE, IRQ23_CODE, \
	IRQ24_CODE, IRQ25_CODE, IRQ26_CODE, IRQ27_CODE, \
	IRQ28_CODE, IRQ29_CODE, IRQ2A_CODE, IRQ2B_CODE, \
	IRQ2C_CODE, IRQ2D_CODE, IRQ2E_CODE, IRQ2F_CODE, \
	IRQ30_CODE, IRQ31_CODE, IRQ32_CODE, IRQ33_CODE, \
	IRQ34_CODE

/*
 * Define IRQ selection register assignment
 */
#define IRQSel()     do { \
   *IRQ_SEL0 = IRQ0_SEL0  | IRQ1_SEL0  | IRQ2_SEL0  | IRQ3_SEL0; \
   *IRQ_SEL1 = IRQ4_SEL1  | IRQ5_SEL1  | IRQ6_SEL1  | IRQ7_SEL1; \
   *IRQ_SEL2 = IRQ8_SEL2  | IRQ9_SEL2  | IRQA_SEL2  | IRQB_SEL2; \
   *IRQ_SEL3 = IRQC_SEL3  | IRQD_SEL3  | IRQE_SEL3  | IRQF_SEL3; \
   *IRQ_SEL4 = IRQ10_SEL4  | IRQ11_SEL4; \
   } while(0)

/*************************************************************************
 * EINT Configuration
 *************************************************************************/
#define  EINT_MAX_CHANNEL          (33)
#define  EINT_TOTAL_CHANNEL        (33)
#define  EINT_HARDWARE_DEBOUNCE    (0xFFFFFFFF) //OOO: need think
#define  EINT_ENABLE_HW_DEBOUNCE KAL_TRUE   //this is defined from MT6261,for eint number exceed 32

/*******************************************************************************
 * Special for display on SWDBG - MCU profiling
 *******************************************************************************/

#define __CIRQ_MASK_REG_NR_2_NEW__
#define __ENABLE_SW_TRIGGER_INTERRUPT__
#define __CIRQ_DIE2DIE__
#define __EINT_DIE2DIE__
#define __NEW_ADIE_EINT_LISR__        /* seperate D-DIE and A-DIE EINT LISR */
#define __NEW_EINT_DEBOUNCE_FLOW__    /* new flow to set hw de-bounce */
#define __TOTAL_EINT_EXCEED_INT32__   /* replace original 32bit API with 64bit */
#define __LISR_TBL_IN_EXTRAM__        /* declare LISR table in external RAM */
#define __IRQ_LISR_DEBUG__            /* for record lisr runtime option */
#define __IRQ_CODE_TO_SRAM__         /* for put isr code into internal sram */
#define __IRQ_MASK_MONITOR_ON__      /* for monitor mask function caller option */
typedef enum
{
    LISR_GPI = IRQ_INVALID_CODE,
    LISR_CTIRQ1 = IRQ_CTIRQ1_CODE,
    LISR_CTIRQ2 = IRQ_CTIRQ2_CODE,
    LISR_DSP12CPU = IRQ_DSP2CPU_CODE,
    LISR_SIM = IRQ_SIM_CODE,
    LISR_DMA = IRQ_DMA_CODE,
    LISR_TDMA = IRQ_TDMA_CODE,
    LISR_UART1 = IRQ_UART1_CODE,
    LISR_KP = IRQ_KPAD_CODE,
    LISR_UART2 = IRQ_UART2_CODE,
    LISR_GPTimer = IRQ_GPT_CODE,
    LISR_EINT = IRQ_EIT_CODE,
    LISR_USB = IRQ_USB_CODE,
    LISR_MSDC = IRQ_MSDC_CODE,
    LISR_LCD = IRQ_LCD_CODE,
    //LISR_UART3 = IRQ_UART3_CODE,
    LISR_GPII = IRQ_INVALID_CODE,
    LISR_WDT = IRQ_WDT_CODE,
    LISR_RESIZER = IRQ_RESZ_CODE,
    LISR_IRDBG1 = IRQ_IRDEBUG_CODE,
    LISR_MSDC_CD = IRQ_MSDC_CD_CODE,
    LISR_I2C = IRQ_I2C_CODE,
    LISR_SIM2 = IRQ_SIM2_CODE,
}LISR_IRQ_NO;

enum Irq_Code_Def_Enum
{
    Enum_IRQ_CTIRQ1_CODE=0x1,
    Enum_IRQ_Code_End
};

