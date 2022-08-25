/****************************************************************************
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
 *    mm_power_ctrl_mt6250.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file manages MMSYS power control and clock gating of all MM engines.
 *    Currently this file is only used in MT6250 project.
 *    Each project should re-write this set of functions according to HW design.
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
 * 02 10 2014 sokonisa.wei
 * removed!
 * .
 *
 * 01 21 2014 chrono.wu
 * removed!
 * 	.
 * 
 * 10 01 2012 peter.wang
 * removed!
 * .
 *
 * 04 27 2012 peter.wang
 * removed!
 * .
 *
 * 04 12 2012 peter.wang
 * removed!
 * .
 *
 * 04 06 2012 peter.wang
 * removed!
 * .
 *
 * 03 27 2012 peter.wang
 * removed!
 * .
 *
 * 03 01 2012 peter.wang
 * removed!
 * .
 *
 * 02 01 2012 peter.wang
 * removed!
 * .
 *
 * 01 03 2012 peter.wang
 * removed!
 * .
 *
 * 10 31 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 24 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 08 2011 hung-wen.hsieh
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*****************************************************************************
 * basic include directives
 *****************************************************************************/
#include "drv_features_mdp.h"
#include "drv_features_mmsysmisc.h"

/*****************************************************************************
 * module dependency check
 *****************************************************************************/
#if defined(__MTK_TARGET__)
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
  #define DRV_FEATURE__MM_POWER_CTRL_MT6250
#endif
#endif
#endif


#if defined(DRV_FEATURE__MM_POWER_CTRL_MT6250)

/*****************************************************************************
 * include directives
 *****************************************************************************/
#include "reg_base.h"
#include "kal_public_api.h"
#include "drv_comm.h"
#include "us_timer.h"
#include "mm_power_ctrl.h"

#if !defined(L1_NOT_PRESENT)
#if defined(MTK_SLEEP_ENABLE)
#include "l1sm_public.h"
#endif
#endif
/*****************************************************************************
 * marco definitions and options
 *****************************************************************************/
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if !defined(L1_NOT_PRESENT)
#if defined(MTK_SLEEP_ENABLE)
  #define MM_POWER_CTRL_MT6250__LOCK_L1SM
#endif
#endif

/*****************************************************************************
 * HW register definitions and macros
 *****************************************************************************/
#define MMSYS_CG_CON                (CONFIG_base + 0x0300) // Clock Gate control 0
#define REG_MMSYS_CG_CON            (*((volatile unsigned int*) MMSYS_CG_CON))

// for power control, see MCU_TOPSM
#define RM_PWR_CON2_REG              (MCU_TOPSM_base + 0x0808) // MMSYS Power control
#define RM_PWR_STA_REG               (MCU_TOPSM_base + 0x0820) // Power status

#define REG_RM_PWR_CON2              (*((volatile unsigned int*) RM_PWR_CON2_REG))
#define REG_RM_PWR_STA               (*((volatile unsigned int*) RM_PWR_STA_REG))

#define MM_PWR_ACK_BIT               (0x4)        // MMSYS

// MMSYS
#define MM_POWER_WAIT_STABLE() \
  while ((REG_RM_PWR_STA & MM_PWR_ACK_BIT) != MM_PWR_ACK_BIT)

#define MM_CLEAR_POWER_ACK() \
  do { REG_RM_PWR_STA = MM_PWR_ACK_BIT; } while(0)  // Write 1 clear
/*****************************************************************************
 * type definitions
 *****************************************************************************/
#if defined(MM_POWER_CTRL_MT6250__DEBUGGING_TRACE)
typedef enum
{
    MM_POWER_ENABLE_MMSYS
  , MM_POWER_ENABLE_ENGINE
  , MM_POWER_ENABLE_ENGINE_DISABLE_L1SM
  , MM_POWER_DISABLE_MMSYS
  , MM_POWER_DISABLE_ENGINE
  , MM_POWER_DISABLE_ENGINE_ENABLE_L1SM
} mm_power_ctrl_traced_id;

typedef struct
{
    mm_power_ctrl_traced_id traced_id;
    kal_uint32              module;
    kal_uint32              drv_time;
    kal_uint32              mmcg_con0;
    kal_taskid              thread_id;
} mm_power_ctrl_debugging_trace_entry;
#endif

/*****************************************************************************
 * global variables
 *****************************************************************************/
/**
 * _mm_pwr_ctrl__n_cg_con
 * This variable is the bit mask to mark which MM module is currently
 * using MM SUBSYS and GMC. When it is 0x0, it means no MM HW module is
 * currently using only MM SUBSYS and GMC, which means mm_power_ctrl driver should
 * power off MM SUBSYS.
 */
static kal_uint32 _mm_pwr_ctrl__n_cg_con = 0;

/*
 * _mm_pwr_ctrl__power_on_timestamp
 * Time stamp of power on to wait for 60us...
 * This is needed in MT6250 design.
 */
static volatile kal_uint32 _mm_pwr_ctrl__power_on_timestamp = 0;

#if defined(MM_POWER_CTRL_MT6250__LOCK_L1SM)
/**
 *  _mm_pwr_ctrl__l1sm_handle
 */
static kal_uint8 _mm_pwr_ctrl__l1sm_handle = 0;
extern kal_bool L1SM_Check_SM_Init(void);
#endif

#if defined(MM_POWER_CTRL_MT6250__DEBUGGING_TRACE)
static kal_uint32 _mm_pwr_ctrl__dbg_trace_curr_idx = 0;
static volatile mm_power_ctrl_debugging_trace_entry _mm_pwr_ctrl__dbg_trace[MM_POWER_CTRL_MT6250__DEBUGGING_TRACE_SIZE];
#endif


/*****************************************************************************
 * external symbols
 *****************************************************************************/
//extern kal_taskid kal_get_current_thread_ID(void);

/*****************************************************************************
 * static function definitions
 *****************************************************************************/
static kal_uint32 _get_mm_power_module_bit(kal_uint32 module)
{
    return MMPWRMGR_REG_BIT_TABLE[module];
}

#if defined(MM_POWER_CTRL_MT6250__DEBUGGING_TRACE)
static void
_mm_power_add_trace(
    mm_power_ctrl_traced_id traced_id,
    kal_uint32 module)
{
    kal_uint32 saved_mask = SaveAndSetIRQMask();
    kal_uint32 curr_idx = _mm_pwr_ctrl__dbg_trace_curr_idx;

    _mm_pwr_ctrl__dbg_trace[curr_idx].traced_id = traced_id;
    _mm_pwr_ctrl__dbg_trace[curr_idx].module = module;
    _mm_pwr_ctrl__dbg_trace[curr_idx].drv_time = drv_get_current_time();
    _mm_pwr_ctrl__dbg_trace[curr_idx].mmcg_con0 = REG_MMSYS_CG_CON;
    _mm_pwr_ctrl__dbg_trace[curr_idx].thread_id = (kal_taskid) kal_get_current_thread_ID();

    ++_mm_pwr_ctrl__dbg_trace_curr_idx;
    _mm_pwr_ctrl__dbg_trace_curr_idx &= (MM_POWER_CTRL_MT6250__DEBUGGING_TRACE_SIZE - 1);

    RestoreIRQMask(saved_mask);
}
#endif


#if defined(MT6250)
void
_mmsys_power_init(void)
{
    REG_RM_PWR_CON2 |= 0x00000144;

    // 40us for 32k signal sync
    MM_POWER_WAIT_STABLE();
}

void
_mmsys_power_on(void)
{
    REG_RM_PWR_CON2 = 0x00000144;

    // 60us wait for power switch on
    MM_POWER_WAIT_STABLE();
}

void
_mmsys_power_off(void)
{
    REG_RM_PWR_CON2 = 0x00000100;

    MM_CLEAR_POWER_ACK();

    // 30us wait for power switch on 
    _mm_pwr_ctrl__power_on_timestamp = ust_get_current_time();
    while ((30 > ust_get_duration(_mm_pwr_ctrl__power_on_timestamp, ust_get_current_time())))
    {
    }
}

#else // MT6260, MT6261 & further chip , no cmos to turn off power

void
_mmsys_power_init(void)
{
}

void
_mmsys_power_on(void)
{
}

void
_mmsys_power_off(void)
{
}


#endif

/*****************************************************************************
 * external function definitions
 *****************************************************************************/
void _mm_disable_clock(kal_uint32 module)
{

}


void _mm_enable_clock(kal_uint32 module)
{

}


void _mm_disable_power(kal_uint32 module)
{
    kal_uint32 saved_mask;

    saved_mask = SaveAndSetIRQMask();

    MMPWRMGR_SET(module);

    _mm_pwr_ctrl__n_cg_con &= ~(_get_mm_power_module_bit(module));

    // turn off mm power if there is no more MM module is on...
    if (0x0 == _mm_pwr_ctrl__n_cg_con)
    {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif

        #if defined(MM_POWER_CTRL_MT6250__LOCK_L1SM)
        // After MMSYS is powered down, allow L1SM to go to sleep...
        if (0 != _mm_pwr_ctrl__l1sm_handle)
        {
            L1SM_SleepEnable(_mm_pwr_ctrl__l1sm_handle);
        }
        #endif
    }

    RestoreIRQMask(saved_mask);

    #if defined(MM_POWER_CTRL_MT6250__DEBUGGING_TRACE)
    _mm_power_add_trace(MM_POWER_DISABLE_ENGINE, module);
    #endif
}


void _mm_enable_power(kal_uint32 module)
{
    kal_uint32 saved_mask;
    static kal_bool power_init = KAL_FALSE;

    saved_mask = SaveAndSetIRQMask();

    #if defined(MM_POWER_CTRL_MT6250__LOCK_L1SM)
    // when first enter this function after power on, get handle!!
    if (0 == _mm_pwr_ctrl__l1sm_handle)
    {
        if (L1SM_Check_SM_Init())
        {
            _mm_pwr_ctrl__l1sm_handle = L1SM_GetHandle();
            L1SM_SleepDisable(_mm_pwr_ctrl__l1sm_handle);
            ASSERT(0 != _mm_pwr_ctrl__l1sm_handle);
        }
    }
    #endif

    // If currently no MM engine is powered on and MMSYS is in off state.
    if (0x0 == _mm_pwr_ctrl__n_cg_con)
    {
        #if defined(MM_POWER_CTRL_MT6250__LOCK_L1SM)
        // each time before MMSYS being powered on, lock L1SM sleep mode...
        L1SM_SleepDisable(_mm_pwr_ctrl__l1sm_handle);
        #endif
        // necessary to turn on MMSYS power if entered
        // so turn on mm power
        if (power_init == KAL_FALSE)
        {
            RestoreIRQMask(saved_mask);
            _mmsys_power_init();
            power_init = KAL_TRUE;
            saved_mask = SaveAndSetIRQMask();
        }
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    }

    // turn on module clock
    MMPWRMGR_CLR(module);
    _mm_pwr_ctrl__n_cg_con |= _get_mm_power_module_bit(module);

    RestoreIRQMask(saved_mask);

    #if defined(MM_POWER_CTRL_MT6250__DEBUGGING_TRACE)
    _mm_power_add_trace(MM_POWER_ENABLE_ENGINE, module);
    #endif
}


/*
 * mm_query_power_status
 * This function is used to query mm power is turn on or off
 *
 * @param module -- module enum
 * @return value -- TRUE:  module is clock gated.
 */
kal_bool _mm_query_clock_status(kal_uint32 module)
{
    kal_uint32 status;
    MMPWRMGR_STATUS(module, status, kal_uint32);

    if (status == 0)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}


#endif // #if defined(DRV_FEATURE__MM_POWER_CTRL_MT6250)

