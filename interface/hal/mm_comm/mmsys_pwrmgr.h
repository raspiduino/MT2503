/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    mmsys_pwrmgr.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Header file for mm_power_ctrl
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __DRV_MMSYS_H__
#define __DRV_MMSYS_H__

#include "kal_public_api.h"
#include "reg_base.h"
#include "Drvpdn.h"

#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
enum { MMPWRMGR_OPT_32BIT_REG = 0x01, MMPWRMGR_OPT_16BIT_REG = 0x02, MMPWRMGR_OPT_NEVER_OFF = 0x04 };
//#define MMPWRMGR_MAX_DEV 32

/*
 * NoteXXX: MAUI Codegen doesn't support C99. It is not allowed to use (kal_int32)
 *          cast when defining enum value.
 *          But ADS linker will produce compile warning if not cast.
 *          Use GEN_FOR_PC option to solve the problem.
 */


/*******************************************************************************
 * MMSYSPMG device ID 
 *******************************************************************************/
typedef enum {
#define X_MMPWRMGR_USER(a, b, c, d, e, f) MMPWRMGR_##a,
#define X_MMPWRMGR_DUMMY(a, b, c, d, e, f) MMPWRMGR_##a,
#include "mmsys_pwrmgr_def.h"
#undef X_MMPWRMGR_USER
#undef X_MMPWRMGR_DUMMY
    MMPWRMGR_MAX_DEV_END
} MMPWRMGR_DEVICE;

#define MMPMG_MAP_TABLE_ENTRY_NUM MMPWRMGR_MAX_DEV

extern kal_uint32 MMPWRMGR_CON_REG_TABLE[MMPMG_MAP_TABLE_ENTRY_NUM];
extern kal_uint32 MMPWRMGR_SET_REG_TABLE[MMPMG_MAP_TABLE_ENTRY_NUM];
extern kal_uint32 MMPWRMGR_CLR_REG_TABLE[MMPMG_MAP_TABLE_ENTRY_NUM];
extern kal_uint32 MMPWRMGR_REG_WIDTH_TABLE[MMPMG_MAP_TABLE_ENTRY_NUM];
extern kal_uint32 MMPWRMGR_REG_BIT_TABLE[MMPMG_MAP_TABLE_ENTRY_NUM];

#if 0
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
#endif 

/*******************************************************************************
 * Define macros
 *******************************************************************************/

/*
 * MMPWRMGR_SET(kal_uint32 dev): power down device
 * @dev: device ID (EX: MMPWRMGR_UART1)
 */
#define MMPWRMGR_SET(dev)    \
        do {    \
            if (MMPWRMGR_REG_WIDTH_TABLE[dev] & MMPWRMGR_OPT_32BIT_REG) {  \
                *(volatile kal_uint32 *)(MMPWRMGR_SET_REG_TABLE[dev]) = (kal_uint32)(MMPWRMGR_REG_BIT_TABLE[dev]);    \
            } else {    \
                *(volatile kal_uint16 *)(MMPWRMGR_SET_REG_TABLE[dev]) = (kal_uint16)(MMPWRMGR_REG_BIT_TABLE[dev]);    \
            }   \
        } while (0)

/*
 * MMSYSPMG_CLR(kal_uint32 dev): power up device
 * @dev: device ID (EX: MMSYSPMG_UART1)
 */
#define MMPWRMGR_CLR(dev)    \
        do {    \
            if (MMPWRMGR_REG_WIDTH_TABLE[dev] & MMPWRMGR_OPT_32BIT_REG) {  \
                *(volatile kal_uint32 *)(MMPWRMGR_CLR_REG_TABLE[dev]) = (kal_uint32)(MMPWRMGR_REG_BIT_TABLE[dev]);    \
            } else {    \
                *(volatile kal_uint16 *)(MMPWRMGR_CLR_REG_TABLE[dev]) = (kal_uint16)(MMPWRMGR_REG_BIT_TABLE[dev]);    \
            }   \
        } while (0)

/*
 * MMSYSPMG_STATUS(kal_uint32 dev, type s, type): get device power down status
 * @dev: device ID (EX: MMSYSPMG_UART1)
 * @s: returned power down status
 * @t: type of s
 */
#define MMPWRMGR_STATUS(dev, s, t)    \
        do {    \
            if (MMPWRMGR_REG_WIDTH_TABLE[dev]& MMPWRMGR_OPT_32BIT_REG) {  \
                (s) = (t)(*(volatile kal_uint32 *)(MMPWRMGR_CON_REG_TABLE[dev]) & MMPWRMGR_REG_BIT_TABLE[dev]);    \
            } else {    \
                (s) = (t)(*(volatile kal_uint16 *)(MMPWRMGR_CON_REG_TABLE[dev]) & MMPWRMGR_REG_BIT_TABLE[dev]);    \
            }   \
        } while (0)

#endif //#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)

#endif //__DRV_MMSYS_H__

