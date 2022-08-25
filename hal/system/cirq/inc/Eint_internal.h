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
 *   Eint_internal.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Definition for EINT internal usage
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __EINT_INTERNAL_H__
#define __EINT_INTERNAL_H__

#include "intrCtrl.h"
#include "drv_features_gpt.h"    /* include this header for "__ENABLE_GPT_PROTECTION__" option */


/*============================================================*/
//  Below is added for DCL EINT layer. Macro define.
/*============================================================*/
/* status check/set/clr macro definition. */
#define CHECK_DCL_USE_STA(eint_no)      (eint_dcl_use_status & (0x1 << eint_no))
#define CHECK_NATIVE_USE_STA(eint_no)   (eint_native_use_status & (0x1 << eint_no))

#define EINT_SET_DCL_USE_STA(eint_no)   eint_dcl_use_status |= (0x1 << eint_no)
#define EINT_CLR_DCL_USE_STA(eint_no)   eint_dcl_use_status &= ~(0x1 << eint_no)
#define EINT_SET_NATIVE_USE_STA(eint_no)   eint_native_use_status |= (0x1 << eint_no)
#define EINT_CLR_NATIVE_USE_STA(eint_no)   eint_native_use_status &= ~(0x1 << eint_no)


/*  Bit mask definition.  */
#define DCL_VALID_EINT_NUM_MASK    0x7F
#define DCL_EINT_FLAG_MASK         0x80


/*============================================================*/



/*************************************************************************
 * Define function prototpye
 *************************************************************************/

/*************************************************************************
 * Internal definition
 *************************************************************************/
#define  EINT_MASK_EINT0      0x00000001
#define  EINT_INTACK_EINT0     0x00000001
#define  EINT_STATUS_EINT0      0x00000001

#if defined(__ENABLE_GPT_PROTECTION__)
  #define  __EINT_SW_DEBOUNCE_V2__
#else
  #undef  __EINT_SW_DEBOUNCE_V2__
#endif

#ifndef EINT_NO_HARDWARE_DEBOUNCE
   #define  EINT_NO_HARDWARE_DEBOUNCE  0x00000000
#endif

#define  EINT_CheckHWDebounce(_no) ((1<<_no) & EINT_HARDWARE_DEBOUNCE)
#define  EINT_CheckNotHWDebounce(_no) ((1<<_no) & EINT_NO_HARDWARE_DEBOUNCE)

// MTK02782 add 20110316 {
#define  EINT_CON_CNT_MASK			0x07ff
#define  EINT_CON_CNT_OFFSET		0

#define  EINT_CON_PRESCALER_MASK	0x7000

#define  EINT_CON_DEBOUNCE_RST      0x80000000

#define  EINT_CON_PRESCALER_32KHZ	0x00000000
#define  EINT_CON_PRESCALER_16KHZ	0x00000001
#define  EINT_CON_PRESCALER_8KHZ	0x00000002
#define  EINT_CON_PRESCALER_4KHZ	0x00000003
#define  EINT_CON_PRESCALER_2KHZ	0x00000004
#define  EINT_CON_PRESCALER_1KHZ	0x00000005
#define  EINT_CON_PRESCALER_512HZ	0x00000006
#define  EINT_CON_PRESCALER_256HZ	0x00000007
#define  EINT_CON_PRESCALER_OFFSET	12
// } MTK02782 add 20110316 

/* Array size for debug log of sources that trigger EINTs */
#define EINT_TRIGGER_SRC_LOG_MAX    16

/* private API */
extern void EINT_AckInt(kal_uint8 eintno);
extern void ADIE_EINT_Enable_Wakeup(kal_uint32 eintno);

/*************************************************************************
 * Define internal data structure                                                                             *
 *************************************************************************/
typedef struct 
{
 	void (*eint_func)(kal_uint8);
  	kal_bool eint_active;
	kal_bool eint_auto_umask;
} eint_func_t;

/*************************************************************************
 * Define EINT definition                                                                            *
 *************************************************************************/
#if defined(__EINT_DIE2DIE__)
#define EINT_ALL_NUMBER    (EINT_TOTAL_CHANNEL + ADIE_EINT_TOTAL_CHANNEL)
#define EINT_HW_DEBOUNCE(index)    (EINT_CheckHWDebounce(index) || (IS_ADIE_EINT(index)))    /* All EINT on A-DIE has HW de-bounce ability */
#else
#define EINT_ALL_NUMBER    EINT_TOTAL_CHANNEL
#define EINT_HW_DEBOUNCE(index)    (EINT_CheckHWDebounce(index))
#endif

/*************************************************************************
 * Define internal MARCO for EINT_Internal_LISR_Handler()
 *************************************************************************/
#if defined(__AST_EINT__) && defined(__AST_TL1_TDD__)

#if defined(MT6236) || defined(MT6236B)
#define ASTRO36_LOCK_value    0x00003fe0
#define ASTRO36_DATA_EINT_NO 4
#define ASTRO36_WAKEUP_EINT_NO 5

#define AST_LOCK(MASK_value)     do{\
                            kal_uint32 ast_savedMask;\
                            ast_savedMask = LockIRQ();\
                            MASK_value = *IRQ_MASKL;\
                            *IRQ_MASK_SETL = ASTRO36_LOCK_value;\
                            RestoreIRQ(ast_savedMask);\
                          }while(0)

#define AST_UNLOCK(MASK_value)     do{\
                            kal_uint32 ast_savedMask;\
                            ast_savedMask = LockIRQ();\
                            *IRQ_MASK_CLRL = (ASTRO36_LOCK_value & ~MASK_value);\
                            RestoreIRQ(ast_savedMask);\
                          }while(0)

#define AST_EINT_HANDLER(status)     do{\
                            kal_uint32 MASK_value;\
                            if (*status & EINT_STATUS_EINT(ASTRO36_WAKEUP_EINT_NO))\
                            {\
                                EINT_Mask(ASTRO36_WAKEUP_EINT_NO);\
                                if (EINT_FUNC[ASTRO36_WAKEUP_EINT_NO].eint_func)\
                                {\
                                    AST_LOCK(MASK_value);\
                                    EINT_FUNC[ASTRO36_WAKEUP_EINT_NO].eint_func();\
                                    AST_UNLOCK(MASK_value);\
                                }\
                                *EINT_INTACK = EINT_INTACK_EINT(ASTRO36_WAKEUP_EINT_NO);\
                                *status &= ~EINT_INTACK_EINT(ASTRO36_WAKEUP_EINT_NO);\
                                EINT_UnMask(ASTRO36_WAKEUP_EINT_NO);\
                            }\
                            if (*status & EINT_STATUS_EINT(ASTRO36_DATA_EINT_NO))\
                            {\
                                EINT_Mask(ASTRO36_DATA_EINT_NO);\
                                if (EINT_FUNC[ASTRO36_DATA_EINT_NO].eint_func)\
                                {\
                                    AST_LOCK(MASK_value);\
                                    EINT_FUNC[ASTRO36_DATA_EINT_NO].eint_func();\
                                    AST_UNLOCK(MASK_value);\
                                }\
                                *EINT_INTACK = EINT_INTACK_EINT(ASTRO36_DATA_EINT_NO);\
                                *status &= ~EINT_INTACK_EINT(ASTRO36_DATA_EINT_NO);\
                                EINT_UnMask(ASTRO36_DATA_EINT_NO);\
                            }\
                          }while(0)
#endif /* MT6236 || MT6236B */

#if defined(MT6573_S00)
#define ARMSTRONG_LOCK_value    0x00ffc000
#define ARMSTRONG_DATA_EINT_NO 7
#define ARMSTRONG_WAKEUP_EINT_NO 1

#define AST_LOCK(MASK_value)     do{\
                            kal_uint32 ast_savedMask;\
                            ast_savedMask = LockIRQ();\
                            MASK_value = *IRQ_MASK0;\
                            *IRQ_MASK_SET0 = ARMSTRONG_LOCK_value;\
                            RestoreIRQ(ast_savedMask);\
                          }while(0)

#define AST_UNLOCK(MASK_value)     do{\
                            kal_uint32 ast_savedMask;\
                            ast_savedMask = LockIRQ();\
                            *IRQ_MASK_CLR0 = (ARMSTRONG_LOCK_value & ~MASK_value);\
                            RestoreIRQ(ast_savedMask);\
                          }while(0)

#define AST_EINT_HANDLER(status)     do{\
                            kal_uint32 MASK_value;\
                            if (*status & EINT_STATUS_EINT(ARMSTRONG_WAKEUP_EINT_NO))\
                            {\
                                EINT_Mask(ARMSTRONG_WAKEUP_EINT_NO);\
                                if (EINT_FUNC[ARMSTRONG_WAKEUP_EINT_NO].eint_func)\
                                {\
                                    AST_LOCK(MASK_value);\
                                    EINT_FUNC[ARMSTRONG_WAKEUP_EINT_NO].eint_func();\
                                    AST_UNLOCK(MASK_value);\
                                }\
                                *EINT_INTACK = EINT_INTACK_EINT(ARMSTRONG_WAKEUP_EINT_NO);\
                                *status &= ~EINT_INTACK_EINT(ARMSTRONG_WAKEUP_EINT_NO);\
                                EINT_UnMask(ARMSTRONG_WAKEUP_EINT_NO);\
                            }\
                            if (*status & EINT_STATUS_EINT(ARMSTRONG_DATA_EINT_NO))\
                            {\
                                EINT_Mask(ARMSTRONG_DATA_EINT_NO);\
                                if (EINT_FUNC[ARMSTRONG_DATA_EINT_NO].eint_func)\
                                {\
                                    AST_LOCK(MASK_value);\
                                    EINT_FUNC[ARMSTRONG_DATA_EINT_NO].eint_func();\
                                    AST_UNLOCK(MASK_value);\
                                }\
                                *EINT_INTACK = EINT_INTACK_EINT(ARMSTRONG_DATA_EINT_NO);\
                                *status &= ~EINT_INTACK_EINT(ARMSTRONG_DATA_EINT_NO);\
                                EINT_UnMask(ARMSTRONG_DATA_EINT_NO);\
                            }\
                          }while(0)
#endif /* MT6573_S00 */

#endif /* __AST_EINT__ && __AST_TL1_TDD__ */

#endif /* __EINT_INTERNAL_H__ */

