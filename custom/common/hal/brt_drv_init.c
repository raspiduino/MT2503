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

/*******************************************************************************
 * Filename:
 * ---------
 *  brt_drv_init.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  BRT initial function for driver init
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#if defined(MT6250)
#if !defined (__BTMODULE_MT6250__)
#include "kal_release.h" 
#include "us_timer.h"

/*MT6250*/ #define MCU_TOPSM_SD_base              (0xA0180000) /*TOPSM0                                                             */  
/*MT6250*/ #define CONFIG_SD_base                 (0xA0010000) /*Configuration Registers(Clock, Power Down, Version and Reset)      */

#define     MCU_TOPSM_RM_PWR_CON1_ADDR          (MCU_TOPSM_SD_base + 0x0804)
#define     MCU_TOPSM_PWR_ON                    (0x00000004)
#define     MCU_TOPSM_PWR_REQ_EN                (0x00000040)
#define     MCU_TOPSM_PWR_SETTLE                (0x00000100)

#define     ANA_MASK_ADDR                       (CONFIG_SD_base + 0x0404)
#define     BT_HW_IND1                          (0x00000080)
#define     BT_APB_IND1                         (0x00000040)
#define     D2D_RSV                             (0x00000020)
#define     BT_D2D_RSV                          (0x00000004)
#define     BT_PWR_ON                           (0x00000002)
#define     BT_RF_SW_RSTB                       (0x00000001)
#define DRV_Reg32(addr)               (*(volatile kal_uint32 *)(addr))
#endif //#if !defined (__BTMODULE_MT6250__)
#endif //#if defined(MT6250)

#if defined(MT6260)
#if !defined (__BTMODULE_MT6260__)
#include "kal_release.h" 
#include "us_timer.h"
#define    MCU_TOPSM_SD_base              (0xA0180000)
#define    MCU_TOPSM_RM_PWR_CON1_ADDR     (MCU_TOPSM_SD_base + 0x0804)
#define    MCU_TOPSM_PWR_ON               (0x00000004)
#define    MCU_TOPSM_PWR_REQ_EN           (0x00000040)
#define DRV_Reg32(addr)               (*(volatile kal_uint32 *)(addr))
#define     MCU_TOPSM_PWR_RESET                 (0x00002000)
void    Brt_Wait_ms(kal_uint32 ms_number)
{
    kal_uint32 i = ms_number;

    while ( i-- >0)
    {
        ust_busy_wait(1000);
    }
}
#endif
#endif

#if defined(MT6261)
#if !defined (__BTMODULE_MT6261__)

#include "kal_release.h" 
#include "us_timer.h"

#define MCU_TOPSM_SD_base              (0xA0180000)
#define MCU_TOPSM_RM_PWR_CON1_ADDR     (MCU_TOPSM_SD_base + 0x0804)
#define MCU_TOPSM_PWR_ON               (0x00000004) //2 //2
#define MCU_TOPSM_PWR_REQ_EN           (0x00000040) //6
#define MCU_TOPSM_PWR_RESET            (0x00002000) //13
//#define MCU_TOPSM_PWR_SETTLE           (0x00000100) //8

#define DRV_Reg32(addr)  (*(volatile kal_uint32 *)(addr))

#endif
#endif

#if defined(MT2501)
#if !defined (__BTMODULE_MT2501__)

#include "kal_release.h" 
#include "us_timer.h"

#define MCU_TOPSM_SD_base              (0xA0180000)
#define MCU_TOPSM_RM_PWR_CON1_ADDR     (MCU_TOPSM_SD_base + 0x0804)
#define MCU_TOPSM_PWR_ON               (0x00000004) //2 //2
#define MCU_TOPSM_PWR_REQ_EN           (0x00000040) //6
#define MCU_TOPSM_PWR_RESET            (0x00002000) //13
//#define MCU_TOPSM_PWR_SETTLE           (0x00000100) //8

#define DRV_Reg32(addr)  (*(volatile kal_uint32 *)(addr))

#endif
#endif

#if defined(MT2502)
#if !defined (__BTMODULE_MT2502__)

#include "kal_release.h" 
#include "us_timer.h"

#define MCU_TOPSM_SD_base              (0xA0180000)
#define MCU_TOPSM_RM_PWR_CON1_ADDR     (MCU_TOPSM_SD_base + 0x0804)
#define MCU_TOPSM_PWR_ON               (0x00000004) //2 //2
#define MCU_TOPSM_PWR_REQ_EN           (0x00000040) //6
#define MCU_TOPSM_PWR_RESET            (0x00002000) //13
//#define MCU_TOPSM_PWR_SETTLE           (0x00000100) //8

#define DRV_Reg32(addr)  (*(volatile kal_uint32 *)(addr))

#endif
#endif


void brt_drv_init(void)
{
#if defined(MT6250)
#if !defined (__BTMODULE_MT6250__)
    //Brt_MT6250_ARM7_Initialize();
    {
        // SW: Enable SW 1 bit control MTCMOS
        DRV_Reg32(MCU_TOPSM_RM_PWR_CON1_ADDR) |= (MCU_TOPSM_PWR_SETTLE | MCU_TOPSM_PWR_REQ_EN | MCU_TOPSM_PWR_ON);
    
        // SW: Wait 150us
        ust_busy_wait(150);
    
        // SW: Trigger hardware state machine control MTCMOS
        DRV_Reg32(MCU_TOPSM_RM_PWR_CON1_ADDR) = (MCU_TOPSM_PWR_SETTLE | MCU_TOPSM_PWR_REQ_EN | MCU_TOPSM_PWR_ON);
    
        // SW: Un-mask BT to D2D_MAS interface
        DRV_Reg32(ANA_MASK_ADDR) &= ~(/*BT_HW_IND1 | BT_APB_IND1 |*/ D2D_RSV | BT_D2D_RSV | BT_PWR_ON | BT_RF_SW_RSTB);
    
        // SW: Trigger state machine to Power off BT
        DRV_Reg32(MCU_TOPSM_RM_PWR_CON1_ADDR) = MCU_TOPSM_PWR_SETTLE;
    }
#endif //#if !defined (__BTMODULE_MT6250__)
#endif //#if defined(MT6250)

#if defined(MT6260)
#if !defined (__BTMODULE_MT6260__)
    {

    DRV_Reg32(MCU_TOPSM_RM_PWR_CON1_ADDR) &= ~(MCU_TOPSM_PWR_ON | MCU_TOPSM_PWR_REQ_EN | MCU_TOPSM_PWR_RESET);

    ust_busy_wait(150);

    //DRV_Reg32(0xA0180820) |= 0x00000020;
    DRV_Reg32(0xA0180820) = 0x00000020;
    
    DRV_Reg32(0xA0010320) |= ((1<<9)|(1<<13));
    DRV_Reg32(0xA0180804) |= (0x1F<<3);
    DRV_Reg32(0xA0180804) &= ~(0x7<<3);

    ust_busy_wait(1);

    DRV_Reg32(0xA0180804) |= (1<<0);

    ust_busy_wait(5);

    DRV_Reg32(0xA3300300) &= ~(1<<3);
    DRV_Reg32(0xA3350080) |= (0x1FFFF);

    ust_busy_wait(500);

    DRV_Reg32(0xA3350070) |= (1<<0);

    Brt_Wait_ms(1);

    DRV_Reg32(0xA0010310) |= ((1<<9)|(1<<13));
    DRV_Reg32(0xA0180804) |= ((1<<5)|(1<<4)|(1<<3)|(1<<1));

   }
#endif
#endif

#if defined(MT6261)
#if !defined (__BTMODULE_MT6261__)
    {
        DRV_Reg32(0xA0010310) |= (1 << 15);

        ust_busy_wait(5);

        DRV_Reg32(0xA0010310) |= ((1 << 13) | (1 << 9));

        DRV_Reg32(MCU_TOPSM_RM_PWR_CON1_ADDR) &= ~(MCU_TOPSM_PWR_ON | MCU_TOPSM_PWR_REQ_EN | MCU_TOPSM_PWR_RESET);

        ust_busy_wait(150);
   }
#endif
#endif

#if defined(MT2501)
#if !defined (__BTMODULE_MT6261__)
    {
        DRV_Reg32(0xA0010310) |= (1 << 15);

        ust_busy_wait(5);

        DRV_Reg32(0xA0010310) |= ((1 << 13) | (1 << 9));

        DRV_Reg32(MCU_TOPSM_RM_PWR_CON1_ADDR) &= ~(MCU_TOPSM_PWR_ON | MCU_TOPSM_PWR_REQ_EN | MCU_TOPSM_PWR_RESET);

        ust_busy_wait(150);
   }
#endif
#endif

#if defined(MT2502)
#if !defined (__BTMODULE_MT6261__)
    {
        DRV_Reg32(0xA0010310) |= (1 << 15);

        ust_busy_wait(5);

        DRV_Reg32(0xA0010310) |= ((1 << 13) | (1 << 9));

        DRV_Reg32(MCU_TOPSM_RM_PWR_CON1_ADDR) &= ~(MCU_TOPSM_PWR_ON | MCU_TOPSM_PWR_REQ_EN | MCU_TOPSM_PWR_RESET);

        ust_busy_wait(150);
   }
#endif
#endif

}
