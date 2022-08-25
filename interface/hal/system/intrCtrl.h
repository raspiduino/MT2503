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
 *   intrCtrl.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Common type and structure definition for MediaTek GSM/GPRS software
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#ifndef _INTRCTRL_H
#define _INTRCTRL_H

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_release.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Single Core Platforms
 *******************************************************************************/
#if defined(MT6205B) || defined(MT6208)
   #include "intrCtrl_MT6205B.h"
#endif

#if defined(MT6219)
   #include "intrCtrl_MT6219.h"
#endif

#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
   #include "intrCtrl_MT6226.h"
#endif
                                 
#if defined(MT6228)
   #include "intrCtrl_MT6228.h"
#endif
                                 
#if defined(MT6229) || defined(MT6230)
   #include "intrCtrl_MT6229.h"
#endif

#if defined(MT6225)
   #include "intrCtrl_MT6225.h"
#endif

#if defined(MT6223) || defined(MT6223P)
   #include "intrCtrl_MT6223.h"
#endif

#if defined(MT6238) || defined(MT6239)
   #include "intrCtrl_MT6238.h"
#endif

#if defined(MT6235) || defined(MT6235B)
   #include "intrCtrl_MT6235.h"
#endif

#if defined(MT6268T)
   #include "intrCtrl_MT6268T.h"
#endif

#if defined(TK6516)
   #include "intrCtrl_TK6516.h"
#endif

#if defined(MT6268A)
   #include "intrCtrl_MT6268A.h"
#endif

#if defined(MT6253T)
   #include "intrCtrl_MT6253T.h"
#endif

#if defined(MT6253)
   #include "intrCtrl_MT6253.h"
#endif

#if defined(MT6253E) || defined(MT6253L)
   #include "intrCtrl_MT6253EL.h"
#endif

#if defined(MT6252) || defined(MT6252H)
   #include "intrCtrl_MT6252.h"
#endif

#if defined(MT6268)
   #include "intrCtrl_MT6268.h"
#endif

#if defined(MT6268H)
   #include "intrCtrl_MT6268H.h"
#endif

#if defined(MT6236) || defined(MT6236B)
   #include "intrCtrl_MT6236.h"
#endif

#if defined(MT6270A)
   #include "intrCtrl_MT6270A.h"
#endif

#if defined(MT6276)
   #include "intrCtrl_MT6276.h"
#endif

#if defined(MT6256)
   #include "intrCtrl_MT6256.h"
#endif

#if defined(MT6251)
   #include "intrCtrl_MT6251.h"
#endif

#if defined(MT6573)
   #include "intrCtrl_MT6573.h" /* AP and MD share the same intrCtrl header file in MT6573 */
#endif

#if defined(MT6255)
   #include "intrCtrl_MT6255.h"
#endif

#if defined(MT6250)
    /* do not change the inclusion sequence because ADIE_intrCtrl_MT6250.h relies on definition in intrCtrl_MT6250.h */
    #include "intrCtrl_MT6250.h"
    #include "ADIE_intrCtrl_MT6250.h"
#endif    

#if defined(MT6260)
    /* do not change the inclusion sequence because ADIE_intrCtrl_MT6260.h relies on definition in intrCtrl_MT6260.h */
    #include "intrCtrl_MT6260.h"
    #include "ADIE_intrCtrl_MT6260.h"
#endif    

#if defined(MT6261) || defined(MT2501) || defined(MT2502)
    /* do not change the inclusion sequence because ADIE_intrCtrl_MT6260.h relies on definition in intrCtrl_MT6260.h */
    #include "intrCtrl_MT6261.h"
    #include "ADIE_intrCtrl_MT6261.h"
#endif    

#include "cirq_internal.h"

/*******************************************************************************
 * Dual Core Platforms
 *******************************************************************************/
#if defined(__APPLICATION_PROCESSOR__)
   #if defined(MT6516)
      #include "intrCtrl_MT6516_app_processor.h"
   #endif

#else
   #if defined(MT6516)
      #include "intrCtrl_MT6516.h"
   #endif
   
#endif

/*******************************************************************************
 * Declarations and Definitions
 *******************************************************************************/
 
#define EDGE_SENSITIVE           KAL_TRUE
#define LEVEL_SENSITIVE          KAL_FALSE

#define IRQ_NOT_LISR_CONTEXT     (0xFFFF)

#if defined(__CIRQ_MASK_REG_NR_1_NEW__) || defined(__CIRQ_MASK_REG_NR_2_NEW__) || defined(__CIRQ_MASK_REG_NR_4_NEW__) || defined(__CIRQ_MASK_REG_NR_5_NEW__)
#define __CIRQ_DESIGN_NEW__
#endif

#if defined(MT6236) || defined(MT6236B) || defined(MT6252) || defined(MT6252H) || defined(MT6253E) || defined(MT6253L) || defined(MT6253) || defined(MT6268)
#define __CIRQ_HW_V3__
#endif
 
typedef struct IRQ_MASK_VALUE_STRUCT
{
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
   kal_uint32 irq_mask0;
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   kal_uint32 irq_mask0;
   kal_uint32 irq_mask1;
#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   kal_uint32 irq_mask0;
   kal_uint32 irq_mask1;
   kal_uint32 irq_mask2;
   kal_uint32 irq_mask3;
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   kal_uint32 irq_mask0;
   kal_uint32 irq_mask1;
   kal_uint32 irq_mask2;
   kal_uint32 irq_mask3;
   kal_uint32 irq_mask4;
#elif defined(__CIRQ_MASK_REG_NR_2__)
   kal_uint32 irq_maskl;
   kal_uint32 irq_maskh;
#elif defined(__CIRQ_MASK_REG_NR_3__)
   kal_uint32 irq_maskl;
   kal_uint32 irq_maskm;
   kal_uint32 irq_maskh;
#else
   kal_uint32 irq_maskl;
   kal_uint32 irq_maskh;
#endif
} IRQ_MASK_VALUE_T;

/* To enable SW Trigger Interrupt for new BB chips
   Need to modify 3 files
   1. add a file intrCtrl_MTxxxx_SW_Handler.h
   2. add an entry on intrCtrl_SW_Handler.h 
   3. modify IRQ_SetSWRegister & IRQ_ResetSWRegister to support BB Chips on intrCtrl.c  */
#if defined(__ENABLE_SW_TRIGGER_INTERRUPT__)
typedef enum 
{
#define X_SW_HANDLE_CONST(a, b, c) a=(b),
   #include "intrCtrl_SW_Handle.h"
#undef X_SW_HANDLE_CONST
   SW_HANDLE_END
}SW_CODE_HANDLE;

extern void Activate_LISR(SW_CODE_HANDLE code);
extern void Deactivate_LISR(SW_CODE_HANDLE code);
extern const kal_uint8 SW_Code_Handle2Code[SW_HANDLE_END-NUM_IRQ_SOURCES];

/* Use to translate the mapping between software handler to hardware interrupt code */
#define SW_code_handle2code(a)  (SW_Code_Handle2Code[(a)-NUM_IRQ_SOURCES])

extern kal_uint32 SW_INT_Counter[SW_HANDLE_END-NUM_IRQ_SOURCES];

#endif /* __ENABLE_SW_TRIGGER_INTERRUPT__ */

extern const kal_uint8 irqLine[NUM_IRQ_LINES];
extern kal_uint8 IRQCode2Line[NUM_IRQ_SOURCES];

extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);

extern void IRQClearInt(kal_uint8);
extern void IRQMask(kal_uint8);
extern void IRQMaskAll(void);
extern void IRQUnmask(kal_uint8);
extern void CTIRQ1_2_MaskAll(IRQ_MASK_VALUE_T *val);
extern void CTIRQ1_2_Restore(IRQ_MASK_VALUE_T *val);
extern void IRQSensitivity(kal_uint8, kal_bool);
extern void FIQSensitivity(kal_bool);
extern void initINTR(void);
extern kal_uint16 INT_BootMode(void);
extern kal_uint32 IRQMask_Status(kal_uint8 code);
extern kal_uint32 IRQ_Status(void);
extern kal_uint32 FIQ_isValid(void);

extern void IRQ_Register_LISR(kal_uint32 code, void (*reg_lisr)(void), char* description);
extern kal_uint32 CheckIRQLock(void);

extern void SetINTMask(kal_uint8 code);
extern void RestoreINTMask(kal_uint8 code);

/* Hardware register write during interrupts disabled */
#define REG_WRITE(reg_addr, value)  { \
   kal_uint32 _savedMask; \
   _savedMask = SaveAndSetIRQMask(); \
   *(volatile kal_uint16*)(reg_addr) = (kal_uint16)(value); \
   RestoreIRQMask(_savedMask); \
}

/* Hardware register read during interrupts disabled */
#define REG_READ(reg_addr, value) { \
   kal_uint32 _savedMask; \
   _savedMask = SaveAndSetIRQMask(); \
   (kal_uint16)(value) = *(volatile kal_uint16*)(reg_addr); \
   RestoreIRQMask(_savedMask); \
}

#if defined(__RVCT__)
#define GET_RETURN_ADDRESS(a) a=__return_address()
#else /* __RVCT__ */
#define GET_RETURN_ADDRESS(a) __asm { MOV a,lr}
#endif /* __RVCT__ */

#ifdef __cplusplus
}
#endif

#endif /* _INTRCTRL_H */

