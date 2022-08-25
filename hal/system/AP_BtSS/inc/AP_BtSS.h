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
 *   AP_BtSS.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines Big-Tiny System Switch Stuffs
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __AP_BTSS_H__
#define __AP_BTSS_H__

#include "intrCtrl.h" /* for disable/enable IRQ */




#define DSP_MEM_RW_EN_ADDR 0xA00500E0
#define DSP_MEN_RW_EN_BIT_MAP  (1<<31)



#ifndef BIT
#define BIT(i)		(1U << i)
#endif

typedef int AP_BtSS_mode;
#define AP_BTSS_SUSPEND			0xcafebabe
#define	AP_BTSS_HIBERNATION 	0xfee1dead
#define AP_BTSS_INVALID_MODE	0xDEADBEEF

enum AP_BtSS_blocker
{
	/**
	  * Apply a blocker here if you want to block tiny modes
	  */
	AP_BTSS_MODE_BLOCKER_AUDIO = BIT(0),
	AP_BTSS_MODE_BLOCKER_SPEECH = BIT(1),

	AP_BTSS_MODE_BLOCKER_CUST = BIT(30),
};

#ifdef __AP_BTSS_C__
#define EXTERN
#else
#define EXTERN extern
#endif

EXTERN AP_BtSS_mode __AP_local_BtSS_mode;
EXTERN kal_uint32 AP_BtSS_blocker_AP_SUSPEND;
EXTERN kal_uint32 AP_BtSS_blocker_AP_HIBERNATION;

#if defined(__TINY_SYS__)

#define AP_BtSS_mode_block(mode, who) \
	do { \
		kal_uint32 _savedMask = SaveAndSetIRQMask(); \
		AP_BtSS_blocker_AP_ ## mode |= who; \
		RestoreIRQMask(_savedMask); \
	} while (0)

#define AP_BtSS_mode_unblock(mode, who) \
	do { \
		kal_uint32 _savedMask = SaveAndSetIRQMask(); \
		AP_BtSS_blocker_AP_ ## mode &= ~who; \
		RestoreIRQMask(_savedMask); \
	} while (0)

#define AP_BtSS_get_mode()		(__AP_local_BtSS_mode)
#define AP_BtSS_set_mode(m)		do {__BtSS_mode_in_csci = (m);} while (0)

#else /* !defined(__TINY_SYS__) */
	#define AP_BtSS_mode_block(mode, who)
	#define AP_BtSS_mode_unblock(mode, who)
	#define AP_BtSS_get_mode()		AP_BTSS_INVALID_MODE
	#define AP_BtSS_set_mode(m)
#endif


EXTERN void AP_BtSS_init(void);
EXTERN kal_int32 AP_BtSS_idle_handler(void);

#undef EXTERN

#endif /* __AP_BTSS_H__ */

