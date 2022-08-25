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
 *    drvpdn.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the power down management header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"

#ifndef __DRVPDN_H__
#define __DRVPDN_H__

/*
 * NoteXXX: Fot chip without PDN SET/CLR register, SET/CLR is set to following value 
 *          to inform SW.
 */
#define DUMMY_PDN_SET_REGISTER  (0xFFFFFFF0)
#define DUMMY_PDN_CLR_REGISTER  (0x0FFFFFFF)

/*******************************************************************************
 * Define HW registers
 *******************************************************************************/

#include "reg_base.h"

#if defined(__TINY_SYS_TS__)
#include "ts_intrCtrl.h"
#else //#if defined(__TINY_SYS_TS__)
#include "intrCtrl.h"
#endif //#if defined(__TINY_SYS_TS__)

#include "pdn_hw_series.h"

/*******************************************************************************
 * Define constants
 *******************************************************************************/

/** MT6250/MT6255 will support LPWR continously..
 * 1. Here, we should include lpwr.h to reference __DRV_SUPPORT_LPWR__,
 *    however, its owner did not resolve the dependency conflict between lpwr.h and drvpdn.h, ....
 * 2. this macro to help transfer X_PDN_USER to X_PDN_CONST within PDN_DEVICE enum definition.
 **/
#if defined(MT6250) || defined (MT6255) 
#define __DRVPDN_SUPPORT_LPWR__
#endif

enum { PDN_OPT_32BIT_REG = 0x01, PDN_OPT_16BIT_REG = 0x02, PDN_OPT_NEVER_OFF = 0x04, PDN_OPT_INVERSED_POLARITY = 0x08};

/*
 * NoteXXX: MAUI Codegen doesn't support C99. It is not allowed to use (kal_int32)
 *          cast when defining enum value.
 *          But ADS linker will produce compile warning if not cast.
 *          Use GEN_FOR_PC option to solve the problem.
 */

/* PDN device ID */
typedef enum {
#if defined (__DRVPDN_SUPPORT_LPWR__)
#define X_PDN_USER(a, b, c, d, e, f) PDN_##a,
#else //#if defined (__DRVPDN_SUPPORT_LPWR__)
#define X_PDN_USER(a, b, c, d, e, f) 
#endif //#if defined (__DRVPDN_SUPPORT_LPWR__)
#define X_PDN_CONST(a, b, c, d, e, f)
#include "pdn_def.h"
#undef X_PDN_USER
#undef X_PDN_CONST
    PDN_MAX_DEV
} PDN_DEVICE;

typedef enum {
#ifdef GEN_FOR_PC
#define X_PDN_USER(a, b, c, d, e, f) PDN_##a##_CON_REG = b,
#define X_PDN_CONST(a, b, c, d, e, f) PDN_##a##_CON_REG = b,
#else
#define X_PDN_USER(a, b, c, d, e, f) PDN_##a##_CON_REG = (kal_int32)b,
#define X_PDN_CONST(a, b, c, d, e, f) PDN_##a##_CON_REG = (kal_int32)b,
#endif
#include "pdn_def.h"
#undef X_PDN_USER
#undef X_PDN_CONST
    PDN_MAX_CON_REG
} PDN_CON_REG;

typedef enum {
#ifdef GEN_FOR_PC
#define X_PDN_USER(a, b, c, d, e, f) PDN_##a##_SET_REG = c,
#define X_PDN_CONST(a, b, c, d, e, f) PDN_##a##_SET_REG = c,
#else
#define X_PDN_USER(a, b, c, d, e, f) PDN_##a##_SET_REG = (kal_int32)c,
#define X_PDN_CONST(a, b, c, d, e, f) PDN_##a##_SET_REG = (kal_int32)c,
#endif
#include "pdn_def.h"
#undef X_PDN_USER
#undef X_PDN_CONST
    PDN_MAX_SET_REG
} PDN_SET_REG;

typedef enum {
#ifdef GEN_FOR_PC
#define X_PDN_USER(a, b, c, d, e, f) PDN_##a##_CLR_REG = d,
#define X_PDN_CONST(a, b, c, d, e, f) PDN_##a##_CLR_REG = d,
#else
#define X_PDN_USER(a, b, c, d, e, f) PDN_##a##_CLR_REG = (kal_int32)d,
#define X_PDN_CONST(a, b, c, d, e, f) PDN_##a##_CLR_REG = (kal_int32)d,
#endif
#include "pdn_def.h"
#undef X_PDN_USER
#undef X_PDN_CONST
    PDN_MAX_CLR_REG
} PDN_CLR_REG;

typedef enum {
#ifdef GEN_FOR_PC
#define X_PDN_USER(a, b, c, d, e, f) PDN_##a##_REG_BIT = e,
#define X_PDN_CONST(a, b, c, d, e, f) PDN_##a##_REG_BIT = e,
#else
#define X_PDN_USER(a, b, c, d, e, f) PDN_##a##_REG_BIT = (kal_int32)e,
#define X_PDN_CONST(a, b, c, d, e, f) PDN_##a##_REG_BIT = (kal_int32)e,
#endif
#include "pdn_def.h"
#undef X_PDN_USER
#undef X_PDN_CONST
    PDN_MAX_REG_BIT
} PDN_REG_BIT;

typedef enum {
#ifdef GEN_FOR_PC
#define X_PDN_USER(a, b, c, d, e, f) PDN_##a##_REG_WIDTH = f,
#define X_PDN_CONST(a, b, c, d, e, f) PDN_##a##_REG_WIDTH = f,
#else
#define X_PDN_USER(a, b, c, d, e, f) PDN_##a##_REG_WIDTH = (kal_int32)f,
#define X_PDN_CONST(a, b, c, d, e, f) PDN_##a##_REG_WIDTH = (kal_int32)f,
#endif
#include "pdn_def.h"
#undef X_PDN_USER
#undef X_PDN_CONST
    PDN_MAX_REG_WIDTH
} PDN_REG_WIDTH;

#define DRVPDN_NOT_INITIALIZED    (0xFFFFFFFF)
#define DRVPDN_INITIALIZING       (0xFFFF4743)
#define DRVPDN_INITIALIZED        (0x4B4F4743)

/*******************************************************************************
 * Define data structures
 *******************************************************************************/

typedef struct
{
    kal_uint32 addr;
    kal_uint32 code;
    kal_uint32 ctrl;
    kal_uint8 options;
    kal_uint8 pad[3];
} PDN_INPUT;


/*******************************************************************************
 * Define macros
 *******************************************************************************/
#if defined(__PDN_F2S_POST_WRITE_WORKAROUND__)
/* For certain F2S bridge, write access would be queued first and return response to MCU
 * before write access realy reaches destination. 
 * Such behavior would violate SW assumption that the write would take effect before MCU 
 * has chances to proceed next intruction.
 * Therefore, a dummy read is added to ensure that previous operations have arrived to destination
 * to avoid the potential side effects caused by F2S post write issue.
 */
#define DRVPDN_32BIT_APB_DUMMY_READ(dev)   (*(volatile kal_uint32 *)((dev##_CON_REG)))
#define DRVPDN_16BIT_APB_DUMMY_READ(dev)   (*(volatile kal_uint16 *)((dev##_CON_REG)))
/* According to DE's comment, the worst case of PDN write operation latency between APB write complete 
 * and setting takes effect is 3T in 52Mhz. Therefore, one dummy APB read is enough.
 */
#else
#define DRVPDN_32BIT_APB_DUMMY_READ(dev)   
#define DRVPDN_16BIT_APB_DUMMY_READ(dev)   
#endif /* __PDN_F2S_POST_WRITE_WORKAROUND__ */

/*
 * PDN_SET(kal_uint32 dev): power down device
 * @dev: device ID (EX: PDN_UART1)
 */
#define PDN_SET(dev)    \
        do {    \
            if(DUMMY_PDN_SET_REGISTER == (kal_uint32)dev##_SET_REG)    \
            {    \
                register kal_uint32 mask; \
                mask = SaveAndSetIRQMask(); \
                if (dev##_REG_WIDTH & PDN_OPT_32BIT_REG) {  \
                    register kal_uint32 reg_val;    \
                    reg_val = *(volatile kal_uint32 *)(dev##_CON_REG);    \
                    if(dev##_REG_WIDTH & PDN_OPT_INVERSED_POLARITY) { \
                        reg_val &= ~(kal_uint32)(dev##_REG_BIT);    \
                    } \
                    else { \
                    reg_val |= (kal_uint32)(dev##_REG_BIT);    \
                    } \
                    *(volatile kal_uint32 *)(dev##_CON_REG) = reg_val;    \
                    DRVPDN_32BIT_APB_DUMMY_READ(dev); \
                }    \
                else {    \
                    register kal_uint16 reg_val;    \
                    reg_val = *(volatile kal_uint16 *)(dev##_CON_REG);    \
                    if(dev##_REG_WIDTH & PDN_OPT_INVERSED_POLARITY) { \
                        reg_val &= ~(kal_uint16)(dev##_REG_BIT);    \
                    } \
                    else { \
                    reg_val |= (kal_uint16)(dev##_REG_BIT);    \
                    } \
                    *(volatile kal_uint16 *)(dev##_CON_REG) = reg_val;    \
                    DRVPDN_16BIT_APB_DUMMY_READ(dev);   \
                }    \
                RestoreIRQMask(mask); \
            }    \
            else {    \
                if (dev##_REG_WIDTH & PDN_OPT_32BIT_REG) {  \
                    *(volatile kal_uint32 *)(dev##_SET_REG) = (kal_uint32)(dev##_REG_BIT);    \
                    DRVPDN_32BIT_APB_DUMMY_READ(dev); \
                } else {    \
                    *(volatile kal_uint16 *)(dev##_SET_REG) = (kal_uint16)(dev##_REG_BIT);    \
                    DRVPDN_16BIT_APB_DUMMY_READ(dev); \
                }   \
            }    \
        } while (0)

/*
 * PDN_CLR(kal_uint32 dev): power up device
 * @dev: device ID (EX: PDN_UART1)
 */
#define PDN_CLR(dev)    \
        do {    \
            if(DUMMY_PDN_CLR_REGISTER == (kal_uint32)dev##_CLR_REG)    \
            {    \
                register kal_uint32 mask; \
                mask = SaveAndSetIRQMask(); \
                if (dev##_REG_WIDTH & PDN_OPT_32BIT_REG) {  \
                    register kal_uint32 reg_val;    \
                    reg_val = *(volatile kal_uint32 *)(dev##_CON_REG);    \
                    if(dev##_REG_WIDTH & PDN_OPT_INVERSED_POLARITY) { \
                        reg_val |= (kal_uint32)(dev##_REG_BIT);    \
                    } \
                    else { \
                    reg_val &= ~(kal_uint32)(dev##_REG_BIT);    \
                    } \
                    *(volatile kal_uint32 *)(dev##_CON_REG) = reg_val;    \
                    DRVPDN_32BIT_APB_DUMMY_READ(dev); \
                }    \
                else {    \
                    register kal_uint16 reg_val;    \
                    reg_val = *(volatile kal_uint16 *)(dev##_CON_REG);    \
                    if(dev##_REG_WIDTH & PDN_OPT_INVERSED_POLARITY) { \
                        reg_val |= (kal_uint16)(dev##_REG_BIT);    \
                    } \
                    else { \
                    reg_val &= ~(kal_uint16)(dev##_REG_BIT);    \
                    } \
                    *(volatile kal_uint16 *)(dev##_CON_REG) = reg_val;    \
                    DRVPDN_16BIT_APB_DUMMY_READ(dev); \
                }    \
                RestoreIRQMask(mask); \
            }    \
            else {    \
                if (dev##_REG_WIDTH & PDN_OPT_32BIT_REG) {  \
                    *(volatile kal_uint32 *)(dev##_CLR_REG) = (kal_uint32)(dev##_REG_BIT);    \
                    DRVPDN_32BIT_APB_DUMMY_READ(dev); \
                } else {    \
                    *(volatile kal_uint16 *)(dev##_CLR_REG) = (kal_uint16)(dev##_REG_BIT);    \
                    DRVPDN_16BIT_APB_DUMMY_READ(dev); \
                }   \
            }    \
        } while (0)

/*
 * PDN_STATUS(kal_uint32 dev, type s, type): get device power down status
 * @dev: device ID (EX: PDN_UART1)
 * @s: returned power down status
 * @t: type of s
 */
#define PDN_STATUS(dev, s, t)    \
        do {    \
            if (dev##_REG_WIDTH & PDN_OPT_32BIT_REG) {  \
                (s) = (t)(*(volatile kal_uint32 *)(dev##_CON_REG) & dev##_REG_BIT);    \
            } else {    \
                (s) = (t)(*(volatile kal_uint16 *)(dev##_CON_REG) & dev##_REG_BIT);    \
            }   \
        } while (0)


/*******************************************************************************
 * Define function prototypes
 *******************************************************************************/

extern void DRVPDN_Enable(PDN_DEVICE handle);
extern void DRVPDN_Disable(PDN_DEVICE hanlde);

#if 0 // unit test
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if 0 // unit test



#endif /* !__DRVPDN_H__ */

