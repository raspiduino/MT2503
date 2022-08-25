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
 *   pll.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#if !defined(bool)
#define bool int
typedef int bool_t;
#define FALSE (1==0)
#define TRUE (!FALSE)
#endif 

#if !defined(U32)
#define U32 unsigned int
typedef int U32_t;
#endif 


////////////////////////////////////////////////////////////////////////////////
// GPT 
////////////////////////////////////////////////////////////////////////////////
#if !defined (GPT_base)
#define GPT_base                    (0xA00C0000) /*General Purpose Timer                                              */
#endif
#define GPT4_CON  ((volatile unsigned int *)(GPT_base + 0x28))
#define GPT4_DAT  ((volatile unsigned int *)(GPT_base + 0x2C))
#define GPT4_EN   (1<<0)
#define GPT4_LOCK (1<<1)

#define GPT4_MAX_TICK_CNT   ((U32)0xFFFFFFFF)

// 26MHz setting 
#define GPT4_MAX_US_TIMEOUT ((U32)164926744)    // 0xFFFFFFFF * 38.4ns / 1000 
#define GPT4_1US_TICK       ((U32)26)           //    1000 / 38.4ns = 26.042
// 26MHz: 1us = 26.042 ticks
#define TIME_TO_TICK_US(us) ((us)*GPT4_1US_TICK + ((us)*42 + (1000-1))/1000)

void gpt4_busy_wait_us(U32 timeout_us);

#define GPT4_STOP() do { *GPT4_CON = 0; } while(0)

#define GPT4_INIT()                                     \
        do {                                               \
                /* default power on GPT  */             \
                                                        \
                /* // clear GPT4 first  */              \
                *GPT4_CON = 0;                          \
                                                        \
                /* // enable GPT4 without lock  */      \
                *GPT4_CON |= (GPT4_EN);                  \
        } while(0)


#define GPT4_GET_CURRENT_TICK() (*GPT4_DAT)

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE"
#endif /* __MTK_TARGET__ */

void gpt4_busy_wait_us(U32 timeout_us)
{
    U32 start_tick, timeout_tick;
    register U32 cur_tick;
    register U32 elapse_tick;

    GPT4_INIT();

    // get timeout tick 
    timeout_tick  = TIME_TO_TICK_US(timeout_us);
    start_tick    = GPT4_GET_CURRENT_TICK();
    
    // wait for timeout 
    do {
            // get current tick 
            cur_tick = GPT4_GET_CURRENT_TICK();

            // check elapse time 
            if( start_tick <= cur_tick ) {
                    elapse_tick = cur_tick - start_tick;
            }
            else {
                    elapse_tick = (GPT4_MAX_TICK_CNT-start_tick) + cur_tick;
            }

            // check if timeout 
    } while ( timeout_tick > elapse_tick );
}

#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */




#if defined (MT6250) || defined (MT6260)
#include "./mt6250_mt6260_pll.c"

#elif defined(MT6261) || defined(MT2502) || defined(MT2501)
#include "./mt6261_pll.c"




#else
#error "pll driver not yet implemented !! \n"
#endif 
