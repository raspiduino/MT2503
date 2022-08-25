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
 *    mmsys_pwrmgr.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 09 09 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 09 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 08 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 02 10 2011 ct.fang
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmsys_pwrmgr.h"
#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
/*******************************************************************************
 * MMSYSPMG CON REG
 *******************************************************************************/
#define X_MMPWRMGR_DUMMY(a, b, c, d, e, f)
#ifdef GEN_FOR_PC
#define X_MMPWRMGR_USER(a, b, c, d, e, f) b,
#else
#define X_MMPWRMGR_USER(a, b, c, d, e, f) (kal_uint32)b,
#endif
kal_uint32 MMPWRMGR_CON_REG_TABLE[MMPMG_MAP_TABLE_ENTRY_NUM] = {
#include "mmsys_pwrmgr_def.h"
};
#undef X_MMPWRMGR_USER

/*******************************************************************************
 * MMSYSPMG SET REG
 *******************************************************************************/
#ifdef GEN_FOR_PC
#define X_MMPWRMGR_USER(a, b, c, d, e, f) c,
#else
#define X_MMPWRMGR_USER(a, b, c, d, e, f) (kal_uint32)c,
#endif
kal_uint32 MMPWRMGR_SET_REG_TABLE[MMPMG_MAP_TABLE_ENTRY_NUM] = {
#include "mmsys_pwrmgr_def.h"
};
#undef X_MMPWRMGR_USER


/*******************************************************************************
 * MMSYSPMG CLR REG
 *******************************************************************************/
#ifdef GEN_FOR_PC
#define X_MMPWRMGR_USER(a, b, c, d, e, f) d,
#else
#define X_MMPWRMGR_USER(a, b, c, d, e, f) (kal_uint32)d,
#endif
kal_uint32 MMPWRMGR_CLR_REG_TABLE[MMPMG_MAP_TABLE_ENTRY_NUM] = {
#include "mmsys_pwrmgr_def.h"
};
#undef X_MMPWRMGR_USER

/*******************************************************************************
 * MMSYSPMG  REG Width
 *******************************************************************************/
#ifdef GEN_FOR_PC
#define X_MMPWRMGR_USER(a, b, c, d, e, f) f,
#else
#define X_MMPWRMGR_USER(a, b, c, d, e, f) (kal_uint32)f,
#endif
kal_uint32 MMPWRMGR_REG_WIDTH_TABLE[MMPMG_MAP_TABLE_ENTRY_NUM] = {
#include "mmsys_pwrmgr_def.h"
};
#undef X_MMPWRMGR_USER

/*******************************************************************************
 * MMSYSPMG  REG BIT
 *******************************************************************************/
#ifdef GEN_FOR_PC
#define X_MMPWRMGR_USER(a, b, c, d, e, f) e,
#else
#define X_MMPWRMGR_USER(a, b, c, d, e, f) (kal_uint32)e,
#endif
kal_uint32 MMPWRMGR_REG_BIT_TABLE[MMPMG_MAP_TABLE_ENTRY_NUM] = {
#include "mmsys_pwrmgr_def.h"
};
#undef X_MMPWRMGR_USER
#undef X_MMPWRMGR_DUMMY
#endif //#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)


