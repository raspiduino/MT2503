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
 *   dcm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides APIs to get device information 
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
 *
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
 * removed!
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

#ifdef __MTK_TARGET__
#include "msdc_def.h"
#include "reg_base.h"
#include "config_hw.h"
#include "init.h"
#include "cp15.h"
#include "us_timer.h"
#include "drv_comm.h"
#include "emi_hw.h"
#include "emi_sw.h"
#include "dma_hw.h"
#include "drvpdn.h"
#include "dcm.h"
#include "pll.h"
#include "us_timer.h"

#include "l1_interface.h"
#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
#include "ostd_public.h"
#endif

#include "stack_config.h"
#include "kal_trace.h"

#include "kal_public_defs.h"

#include "kal_general_types.h"
#include "kal_internal_api.h"
#include "kal_public_api.h"

#include "sst_sla.h"
#include "system_trc.h"
#include "kal_internal_api.h"
#include "intrCtrl.h"
/*
 * NoteXXX: SaveAndSetIRQMask()/RestoreIRQMask() are APIs for appilcations to disable/restore
 *          IRQ. They will restrict the disable duration. But idle task disables IRQ for a 
 *          time due to DCM. Thus LockIRQ()/RestoreIRQ() are used here. Only the idle task
 *          can use them!! Other applications are not allowed to use LockIRQ()/RestoreIRQ().
 */
kal_uint32 LockIRQ(void);
void RestoreIRQ(kal_uint32);
kal_bool switch_to_dcm(void);
kal_bool switch_to_sleep(void);


#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"


#if defined(MT6260_S00)
/**
 * 1. E1 has a defect where protect ready can go through a buffer that lack of power connection 
 * 2. EMI DCM has a too-long recovery time due to requirement of 2 EMI SLOW clock to synch up ARM-to-EMI idle signal.
 **/
#define MT6260_CONDE_GOLDEN_CONF (0x2b1 & ~MT6260_CONDE_EMI_DCM_MASK)
#else //#if defined(MT6260_S00)
#define MT6260_CONDE_GOLDEN_CONF (0x2b5 & ~MT6260_CONDE_EMI_DCM_MASK)
#endif //#if defined(MT6260_S00) 

#if defined(MT6261)
#define MT6261_DCM_EN()         do {*PLL_CLK_CONDE = (*PLL_CLK_CONDE & ~0x03FF) | 0x02B5; } while(0) //0xA001_0110, enable all DCM functions
#define MT6261_DCM_DIS()        do {*PLL_CLK_CONDE &= ~0x03FF; } while(0) //0xA001_0110, disable all DCM functions
#endif


#pragma arm section rwdata , rodata , zidata


#if defined( DCM_ENABLE )

kal_uint32 SaveAndSetIRQMask(void);
void RestoreIRQMask(kal_uint32);

#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
volatile static kal_uint32 dcm_state = -1;
volatile static kal_bool dcm_excuted = KAL_FALSE;


#if defined(__MTK_INTERNAL__)
/* under construction !*/
#if defined(__USE_HW_DCM_CYCLE_COUNTER__)
/* under construction !*/
/* under construction !*/
#endif
#endif //__MTK_INTERNAL__


/* dcm_state = 
   0, 104/52 MHz.
   1, 104/52->13/26 MHz transition.
   2, 13/26 Mhz.
   3, 13/26->104/52 MHz transition. 
*/
static struct 
{
   kal_uint32   dcmForceDisalbe;
   kal_uint8   	dcmHandleCount;
   kal_uint32   dcmDisable;					/* Default not disable DCM */
} dcm = { 0, 0, 0 }; 
 
int custom_DynamicClockSwitch(mcu_clock_enum clock);
int custom_SFIDynamicClockSwitch_Init(void);
int custom_EMIDynamicClockSwitch_Init(void);

extern ECO_VERSION INT_ecoVersion(void);


#pragma arm section rwdata , rodata , zidata


void WFI_Disable( void )
{
    /* do nothing */
}

void WFI_Enable( void )
{
    /* do nothing */
}


kal_bool DCM_Query_Status(void)
{
   kal_bool status = dcm_excuted;
   dcm_excuted = KAL_FALSE;/* Restored to default state */
   return status;
} 
kal_uint8 DCM_GetHandle( void )
{	
   ASSERT(dcm.dcmHandleCount<32);
   return dcm.dcmHandleCount++;   /* Using handle number from 0, not 1 */
}

void Leave_DCM_mode(void);
void Enter_DCM_mode(void);


void DCM_Enable( kal_uint8 handle )
{   
   kal_uint32 _savedMask;
   
   _savedMask = SaveAndSetIRQMask();
   dcm.dcmDisable &= ~(1 << handle);   
   if(0 == dcm.dcmDisable && dcm_state != -1)
   {
           Enter_DCM_mode();
   }
   RestoreIRQMask(_savedMask);
}

void DCM_Disable( kal_uint8 handle )
{
   kal_uint32 _savedMask;
   
   _savedMask = SaveAndSetIRQMask();
   dcm.dcmDisable |= (1 << handle);
   Leave_DCM_mode();
   RestoreIRQMask(_savedMask);
}

void DCM_Enable2( kal_uint8 handle )
{   
   kal_uint32 _savedMask;
   
   _savedMask = LockIRQ();
   dcm.dcmDisable &= ~(1 << handle);   
   if(0 == dcm.dcmDisable && dcm_state != -1)
   {
           Enter_DCM_mode();
   }
   RestoreIRQ(_savedMask);
}

void DCM_Disable2( kal_uint8 handle )
{
   kal_uint32 _savedMask;
   
   _savedMask = LockIRQ();
   dcm.dcmDisable |= (1 << handle);
   Leave_DCM_mode();
   RestoreIRQ(_savedMask);
}

#if !(defined(__MTK_INTERNAL__) && defined (__USE_HW_DCM_CYCLE_COUNTER__))
void LPM_init(void) {}
#else
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
#endif //#if !defined(__MTK_INTERNAL__) || !defined (__USE_HW_DCM_CYCLE_COUNTER__) 



#pragma arm section code = "INTSRAM_ROCODE"
 
void DCM_Recovery(void)
{  
#if !defined(__HW_DCM__)
      
   if( dcm_state == 2 ) 
   {
           //ASSERT( *MCUCLK_CON == 0x0000 ); //13MHz

           dcm_state = 3; /* DCM @ 13/26->104/52MHz */
      
           /* I_Bit is disabled and Wait until EMI access is complete.
              Otherwise, some external(Burst/Async/Sync RAM), some will get problems. */
           EMI_Dummy_Read();
   
      
           dcm_state = 0; /* DCM @ 104/52MHz */
           dcm_excuted = KAL_TRUE;/* Record the execution of DCM and print in L1SM_FrameTick */
   }
#else

   if(dcm_state == 2)
   {
           dcm_state = 3;


           dcm_state = 0;
           dcm_excuted = KAL_TRUE;/* Record the execution of DCM and print in L1SM_FrameTick */
   }
#endif //!_HW_DCM__   
}


void Enter_DCM_mode(void)
{
        kal_uint32 _savedMask;

        _savedMask = LockIRQ();

#if defined (__HW_DCM__)
       #if defined(MT6250)
       *PLL_CLK_CONDE = (*PLL_CLK_CONDE & (1<<10)) | 0x02B5;
       #endif //#if defined(MT6250)
       #if defined (MT6260)
       *PLL_CLK_CONDE = (*PLL_CLK_CONDE & ((3<<14) | (1<<10))) | MT6260_CONDE_GOLDEN_CONF;  //reserve bit 14, 15, 10, that is not DCM switch.
       #endif //#if defined (MT6260)
       #if defined (MT6261)
       MT6261_DCM_EN(); 
       #endif //#if defined (MT6261)
#endif //#if defined (__HW_DCM__)


       RestoreIRQ(_savedMask);
}

void Leave_DCM_mode(void)
{
    kal_uint32 _savedMask;

    _savedMask = LockIRQ();

   #if defined(__HW_DCM__)
   #if defined(MT6250)
   /**
    * 1. originally to disable bus DCM(0x70) only and bit[2,7,9] for SWLA.
    * 2. however finally, decide to set all DCM off.
    * 3. reserver bit10 for SFI owner.
    **/
   *PLL_CLK_CONDE = (*PLL_CLK_CONDE & (1<<10));  
#endif //#if defined(MT6250)

#if defined (MT6260)
   *PLL_CLK_CONDE = (*PLL_CLK_CONDE & ((3<<14) | (1<<10)));  
#endif //#if defined (MT6260)

#if defined (MT6261)
   MT6261_DCM_DIS(); 
#endif //#if defined (MT6261)

   #else //#if defined(__HW_DCM__)
   #endif //#if defined (__HW_DCM__)

    RestoreIRQ(_savedMask);
}

void MT6261_DCM_init(void)
{
        dcm_state = 0;
        Enter_DCM_mode();

}


#pragma arm section code


#else /* DCM_ENABLE */
volatile static kal_uint32 dcm_state = 0;

kal_bool DCM_Query_Status(void) 
{
	return KAL_FALSE;
}
kal_uint8 DCM_GetHandle( void ) 
{
	return 0;
}
void DCM_Enable( kal_uint8 handle ) {}
void DCM_Disable( kal_uint8 handle ) {}

void DCM_Enable2( kal_uint8 handle ) {}
void DCM_Disable2( kal_uint8 handle ) {}



void MT6261_DCM_init(void)
{
        //donothing.
}

#endif /* DCM_ENABLE */


void DCM_Init( void )
{
    kal_uint32 _savedMask;

    #if defined( DCM_ENABLE )

    #if defined(__COMBO_MEMORY_SUPPORT__)
    custom_EMIDynamicClockSwitch_Init();
    #endif /* __COMBO_MEMORY_SUPPORT__ */
    #if defined(__SERIAL_FLASH_EN__)
    custom_SFIDynamicClockSwitch_Init();
    #endif /* __SERIAL_FLASH_EN__ */


    #if defined(MT6250) || defined (MT6260)

    *PLL_CLK_CONDB &= (~0x08000); /** 0xA001_0104, clear bit 15, the HW 26Mhz to PLL switching assistance enable bit
                                   * because to switch to ARM 87Mhz needs it be disabled
                                   **/
    *PLL_CLK_CONDB; //read back for assureence of write down

    #if !defined(__MEUT__) && defined (__HW_DCM__)
    //start DCM 
    _savedMask = LockIRQ();
#if defined (MT6250)
    *PLL_CLK_CONDE = (*PLL_CLK_CONDE & (1<<10)) | 0x02B5;
#else //#if defined (MT6250)
    *PLL_CLK_CONDE = (*PLL_CLK_CONDE & ((3<<14) | (1<<10))) | MT6260_CONDE_GOLDEN_CONF;  //reserve bit 14, 15, 10, that is not DCM switch.
#endif //#if defined (MT6250)
    RestoreIRQ(_savedMask);

    #endif //#if defined (__HW_DCM__)

    #endif //    #if defined(MT6250) || defined (MT6260)


#if defined (MT6261)
    MT6261_DCM_init();
#endif //#if defined (MT6250)

    LPM_init();

	
    #endif // DCM_ENABLE	

}


#if defined(L1D_TEST)
extern kal_int8 L1DTest_L1SM_Is_Slept(void);
#define L1SM_IS_SLEPT() L1DTest_L1SM_Is_Slept()
#else
extern kal_bool L1SM_Is_Slept(void);
#define L1SM_IS_SLEPT() L1SM_Is_Slept()
#endif  /* L1D_TEST */


//#pragma arm section code = "INTERNCODE"
#pragma arm section code = "INTSRAM_ROCODE"

#if defined (DCM_ENABLE)
#define regular_idle()                          \
        do {                                    \
                arm_enter_standby_mode(0);      \
        } while(0)
#else
/* if no DCM, thus regular idle is also ignored. 
 * ex: for case to bring-up.
 */
#define regular_idle()  do{} while(0) 
#endif

void idle_iteration(void)
{
        if (switch_to_sleep() == KAL_TRUE)
                return;

        if (switch_to_dcm() == KAL_TRUE)
                return;

        regular_idle();
}


kal_bool switch_to_dcm(void)
{
#if defined( DCM_ENABLE )

        if ( DCM_ENABLE_CHECK &&
             dcm.dcmDisable == 0 &&
             dcm.dcmForceDisalbe == 0 )
        {
                kal_uint32 _savedMask;
                register kal_uint32 start, end, duration;

                _savedMask = LockIRQ();

                start = ust_get_current_time();

                LPM_init();
                /*To access an address not in existance will ensure that EMI access is complete.*/
                EMI_Dummy_Read();

                dcm_state = 1; /* DCM @ 104/52->13/26Mhz */ 
#if !defined(__HW_DCM__)
                //custom_DynamicClockSwitch( MCU_13MHZ );  
#endif         

                dcm_state = 2; /* DCM @ 13/26MHz */
         
                /* check if IRQ is disabled for more than 60 qbits */
                end = ust_get_current_time();
                duration = ust_get_duration(start, end);
		 
#if defined(__MTK_INTERNAL__) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
		 
#if defined(MT6250) || defined (MT6260)
#if defined (MT6260)
                //enable EMI HW DCM, 
                /** 1. arm-to-emi idle has too-long recovery time, thus only enable EMI DCM while ARM entering idle.
                 *  2. MMSYS idle signal has poor timing constrain, thus only enable EMI DCM while all MMSYSs entering idle.
                 */
                if ((*DCM_PDN_COND0 & (0x3f)) == 0x3f) {                 
                        MT6260_EMI_DCM_ENABLE();
                }
#endif //#if defined (MT6260)
#endif
                
                arm_enter_standby_mode(0);
                
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif //__MTK_INTERNAL__

                DCM_Recovery();

                RestoreIRQ(_savedMask);
                return KAL_TRUE;
        } 

#endif /* defined(DCM_ENABLE)*/       
        
        return KAL_FALSE;
}

#pragma arm section code


/* 
 * PLL save mode - implementation 
 */


#pragma arm section code = "INTSRAM_ROCODE"



#pragma arm section code


#else  /* __MTK_TARGET__ */
   
#endif //#ifdef __MTK_TARGET__

