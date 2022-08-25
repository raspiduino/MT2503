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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   l1_interface.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   Interface for system service.
 *
 * Author:
 * -------
 * -------
 *
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
 *******************************************************************************/

#ifndef  _L1_INTERFACE_H_
#define  _L1_INTERFACE_H_
/* ------------------------------------------------------------------------- */

#include "reg_base.h"
#include "l1d_cid.h"
#include "l1_fh_interface.h"
#include "kal_general_types.h"

#if defined(L1_SIM) || IS_CHIP_MT6268T || IS_CHIP_MT6268T_DMAC
#include "tool.h"
#else
#define  HW_WRITE(ptr,data)         (*(ptr) = (data))
#define  HW_READ(ptr)               (*(ptr))
#endif

extern kal_uint16 L1_ASSERT_BYPASS;
extern kal_uint16 L1D_MD2G_SLEEP_STATUS( void );
void L1D_INFORM_DSP_WAKEUP( void );
void L1D_INFORM_DSP_REENTER_SLEEP( void );
void L1D_INFORM_DCXO_WAKEUP( void );
unsigned char L1D_IS_MT6162_DCXO( void );
void L1D_PMU_FIX_VRF1828SETTING( unsigned char is_fixed ); /* workaround for BT EVM performace due to VRF18/28 change */
extern kal_bool L1D_REPORT_CALDATA_DOWNLOAD_STATUS( void );
extern char L1D_INFORM_WIFI_DEGRADE_POWER( void ); /* workaround for low GSM RX performace due to large wifi TX power. */

#if defined(L1_NOT_PRESENT)
#define  L1_CHECK_ASSERT_BYPASS()           (0)
#define  MD2G_SLEEP_STATUS()                (1)
#define  INFORM_DSP_WAKEUP()                {}
#define  INFORM_DSP_REENTER_SLEEP()         {}
#define  L1D_DCXO_WAKEUP()                  {}
#define  L1D_FIX_VRF1828SETTING( is_fixed ) {}
#define  INFORM_WIFI_DEGRADE_POWER()        (0)
#else
#define  L1_CHECK_ASSERT_BYPASS()           (L1_ASSERT_BYPASS & 0x3)
#define  MD2G_SLEEP_STATUS()                L1D_MD2G_SLEEP_STATUS()
#define  INFORM_DSP_WAKEUP()                L1D_INFORM_DSP_WAKEUP()
#define  INFORM_DSP_REENTER_SLEEP()         L1D_INFORM_DSP_REENTER_SLEEP()
#define  L1D_DCXO_WAKEUP()                  L1D_INFORM_DCXO_WAKEUP()
#define  L1D_FIX_VRF1828SETTING( is_fixed ) L1D_PMU_FIX_VRF1828SETTING( is_fixed )
#define  INFORM_WIFI_DEGRADE_POWER()        L1D_INFORM_WIFI_DEGRADE_POWER()
#endif

void  HW_TDMA_Start(void);         /* power on TDMA module               */
void  HW_TDMA_Enable_CTIRQ1(void); /* enable TDMA module CTIRQ1          */
void  HW_wait_32k_start(void);     /* use 13M/26M to calibrate 32k clock */

/*--------------------------------------------*/
/* MACRO to set AUXADC event0 & event1        */
/*--------------------------------------------*/
typedef  volatile unsigned short*   APBADDR;
typedef  volatile unsigned long*    APBADDR32;
#if IS_NEW_TDMA_CHIP
typedef  APBADDR32                  APBADDX;
#else
typedef  APBADDR                    APBADDX;
#endif

#if IS_CHIP_MT6276
#define  CMD_MAGIC_VALUE            0x62760000
#elif IS_CHIP_MT6573
#define  CMD_MAGIC_VALUE            0x65730000
#elif IS_CHIP_MT6575
#define  CMD_MAGIC_VALUE            0x65750000
#elif IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
#define  CMD_MAGIC_VALUE            0x11530000
#endif

#if IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
#define __TDMA_HW_US_TIMER_SUPPORT__
#endif

#define  EVENT_ENA(n)               ((APBADDX)(TDMA_base+0x0150+((n)*4)))
#define  TQ_CURRENT_COUNT           ((APBADDR)(TDMA_base+0x0000))
#define  TQ_WRAP                    ((APBADDR)(TDMA_base+0x0004))
#if IS_CHIP_MT6270A || IS_CENTRALIZED_SMM_CHIP
   #if IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
#define  RTC_COUNT                  ((APBADDR32)(MCU_TOPSM_base+0x104))
   #else
#define  RTC_COUNT                  ((APBADDR32)(TOPSM_base+0x104))
   #endif
#define  RTC_MAX_32K_CNT            0xFFFFFFFF
#elif IS_CHIP_MT6219 || IS_CHIP_MT6228
#define  RTC_COUNT                  ((APBADDR32)(TDMA_base +0x230))
#define  RTC_MAX_32K_CNT            0x0007FFFF
#else
#define  RTC_COUNT                  ((APBADDR32)(TDMA_base +0x230))
#define  RTC_MAX_32K_CNT            0x00FFFFFF
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define  TDMA_AUXEV0                ((APBADDR)(TDMA_base+0x0400))
#define  TDMA_AUXEV1                ((APBADDR)(TDMA_base+0x0404))
#define  TDMA_AUXEVENA              EVENT_ENA(7)
#elif IS_CHIP_MT6227 || IS_CHIP_MT6225_AND_LATTER_VERSION
#define  TDMA_AUXEV0                ((APBADDR)(TDMA_base+0x01C0))
#define  TDMA_AUXEV1                ((APBADDR)(TDMA_base+0x01C4))
#define  TDMA_AUXEVENA              EVENT_ENA(5)
#else
#define  TDMA_AUXEV0                ((APBADDR)(TDMA_base+0x01B0))
#define  TDMA_AUXEV1                ((APBADDR)(TDMA_base+0x01B4))
#define  TDMA_AUXEVENA              EVENT_ENA(5)
#endif

#define  HW_tdma_auxev_time_setup(event0,event1)         \
{  kal_uint16 d16 = (kal_uint16)HW_READ(TDMA_AUXEVENA);  \
   HW_WRITE(TDMA_AUXEV0, event0);                        \
   HW_WRITE(TDMA_AUXEV1, event1);                        \
   HW_WRITE(TDMA_AUXEVENA, (d16|0x3));                   \
}

#define  HW_TDMA_GET_TQCNT()        HW_READ(TQ_CURRENT_COUNT)
#define  HW_TDMA_GET_TQWRAP()       HW_READ(TQ_WRAP)
#define  HW_TDMA_GET_32KCNT()       HW_READ(RTC_COUNT)
#ifdef __TDMA_HW_US_TIMER_SUPPORT__
#define  HW_TDMA_GET_REF_TIME()  HW_READ(((APBADDR32)(MCU_TOPSM_base+0x88))) //FRC
#else
#define  HW_TDMA_GET_REF_TIME()  HW_READ(RTC_COUNT)
#endif

/* APIs for audio */
extern kal_bool   L1D_Get_Speech_Re_Sync_Flag( void );

/* ------------------------------------------------------------------------- */

#if IS_CHIP_MT6261
#define L1D_WAKEUP_MARGIN                   (1050)
#define L1C_WAKEUP_MARGIN                   (990)
#endif
/* ------------------------------------------------------------------------- */
#endif
