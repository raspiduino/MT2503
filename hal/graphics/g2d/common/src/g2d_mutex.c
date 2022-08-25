/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   g2d_common_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   G2D Driver
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
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "g2d_mutex.h"
#include "string.h"

#include "drv_comm.h"


#define WAIT_HW_G2D_FINISH 0x01
g2d_mutex_struct g2d_mutex = { 0 };
kal_eventgrpid g2d_event_group;


void g2d_mutex_init(g2d_mutex_struct *pMutex)
{
   pMutex->state = G2D_MUTEX_STATE_GIVEN;
   pMutex->priority = G2D_PRIORITY_NONE;
   if (g2d_event_group == NULL)
   {
       g2d_event_group = kal_create_event_group("g2d_evt");
   }
}

void g2d_mutex_lock(g2d_mutex_struct *pMutex)
{
#ifdef __MTK_TARGET__
    static const int locked = G2D_MUTEX_STATE_TAKEN;

    volatile int *addr = &pMutex->state;
    int state;
//#ifdef __CPU_ARM1176JZ_S__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    __asm
    {
        MOV   state, locked
    try_spin_lock:
        SWP   state, state, [addr]
        CMP   state, locked
        BNE   end_spin_lock
        BL    kal_sleep_task, { r0 = 1 }
        B     try_spin_lock
    end_spin_lock:
    }
#endif

#else
    kal_uint32 save_irq_mask;
    while (1)
    {
        save_irq_mask = SaveAndSetIRQMask();
        if (pMutex->state == G2D_MUTEX_STATE_GIVEN)
        {
            pMutex->state = G2D_MUTEX_STATE_TAKEN;
            RestoreIRQMask(save_irq_mask);
            break;
        }
        RestoreIRQMask(save_irq_mask);
        kal_sleep_task(1);
    }
#endif

}


void g2d_mutex_unlock(g2d_mutex_struct *pMutex)
{
#ifdef __MTK_TARGET__

//#ifdef __CPU_ARM1176JZ_S__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    pMutex->state = G2D_MUTEX_STATE_GIVEN;
#endif

#else
    kal_uint32 save_irq_mask;
    save_irq_mask = SaveAndSetIRQMask();
    pMutex->state = G2D_MUTEX_STATE_GIVEN;
    RestoreIRQMask(save_irq_mask);
#endif

}


kal_bool g2d_mutex_lock_fast(g2d_mutex_struct *pMutex)
{
#ifdef __MTK_TARGET__
    static const int locked = G2D_MUTEX_STATE_TAKEN;

    volatile int *addr = &pMutex->state;
    int state;
    int result = 0;
//#ifdef __CPU_ARM1176JZ_S__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    __asm
    {
        MOV   state, locked
        SWP   state, state, [addr]
        CMP   state, locked
        MOVNE   result, 0x01;
    }
#endif
    if (result > 0)
    {
       return KAL_TRUE;
    }
    else
    {
       return KAL_FALSE;
    }

#else
    kal_uint32 save_irq_mask;
    save_irq_mask = SaveAndSetIRQMask();
    if (pMutex->state == G2D_MUTEX_STATE_GIVEN)
    {
       pMutex->state = G2D_MUTEX_STATE_TAKEN;
       RestoreIRQMask(save_irq_mask);
       return KAL_TRUE;
    }
    RestoreIRQMask(save_irq_mask);
    return KAL_FALSE;
#endif

}

kal_bool g2d_mutex_check_given_status_only(void)
{
    kal_bool G2D_CheckStatus = KAL_TRUE;
    g2d_mutex_struct *pMutex = &g2d_mutex;
    {
       kal_uint32 const save_irq_mask = SaveAndSetIRQMask();
       if (G2D_MUTEX_STATE_TAKEN == pMutex->state)
       {
         G2D_CheckStatus = KAL_FALSE;
       }
       RestoreIRQMask(save_irq_mask);
    }
    return G2D_CheckStatus;
}

kal_bool g2d_mutex_check_given_status(void)
{
    kal_bool G2D_CheckStatus = KAL_TRUE;
    g2d_mutex_struct *pMutex = &g2d_mutex;
    {
       kal_uint32 const save_irq_mask = SaveAndSetIRQMask();
       if (G2D_MUTEX_STATE_TAKEN == pMutex->state)
       {
         g2d_mutex.priority = G2D_PRIORITY_HIGH;
         G2D_CheckStatus = KAL_FALSE;
       }
       RestoreIRQMask(save_irq_mask);
    }
    return G2D_CheckStatus;
}

void g2d_mutex_wait_hwg2d_release(void)
{
   kal_uint32 event;
   kal_retrieve_eg_events(g2d_event_group, WAIT_HW_G2D_FINISH, KAL_AND_CONSUME, &event, KAL_SUSPEND);
   g2d_mutex.priority = G2D_PRIORITY_NONE;
}

void g2d_mutex_wakeup_wait_task(void)
{
  if (G2D_PRIORITY_HIGH == g2d_mutex.priority)
  {
    kal_set_eg_events(g2d_event_group, WAIT_HW_G2D_FINISH, KAL_OR);
  }
}

#if 0
/* under construction !*/
/* under construction !*/
#if defined(G2D_CODEC_STANDALONE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #ifndef ASSERT
/* under construction !*/
   #endif
#elif defined(G2D_FPGA)
/* under construction !*/
   #ifndef ASSERT
/* under construction !*/
   #endif
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)   
/* under construction !*/
   #endif
/* under construction !*/
   #if defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
#endif
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
#if !defined(__MTK_TARGET__) && !defined(G2D_FPGA)
/* under construction !*/
#endif
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

