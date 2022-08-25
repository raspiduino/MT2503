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
 *   uscounter.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This function implements uscounter.
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

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_release.h"
#include "reg_base.h"
#include "us_timer.h"
#if !defined(__TINY_SYS_TS__)
#include "l1_interface.h"
#endif
#include "kal_general_types.h"

#if defined(__HW_US_TIMER_SUPPORT__)

#ifdef __MTK_TARGET__
#pragma arm section code = "INTERNCODE", rwdata = "INTERNRW", zidata = "INTERNZI"
#endif

#if defined(__ALIGN_2G_CLOCK__)
static kal_uint32 Pre_USCNTI = 0;
static kal_uint32 FrameCount = 0;
#else
static kal_uint32 Pre_USCNTI = 0;
static kal_uint64 Total_USCNTI = 0;
#endif

#if defined(MT6268_S00)
//AB: the followings are used to fixed us counter bug when waking up
#define US_RTR_Timer       (volatile kal_uint32 *)(RTR_base + 0x00)
static kal_uint32 Wake_USCNTI;
static kal_uint32 Wake_Timer;
static kal_uint32 Wake_TimerCnt;
static kal_uint32 Wake_33us_TimeOut = 1;  //AB: power up, us counter is usable.
static kal_uint32 Wake_US_Updated = 0;

//kal_uint32 Wake_Temp_Dur = 0;
//static kal_uint32 Wake_Timer_Tick[128];
//static kal_uint32 Wake_Timer_Count = 0;

extern kal_int32 TCD_Interrupt_Count;
extern kal_uint32 LockIRQ(void);
extern void RestoreIRQ(kal_uint32 irq);

#endif //MT6268_S00

extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);


/*************************************************************************
* FUNCTION
*  USC_Start
*
* DESCRIPTION
*  This function starts the uscounter.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void USC_Start()
{
   HW_WRITE(USCNT_CON, USCNT_START_CODE);
}

/*************************************************************************
* FUNCTION
*  USC_Stop
*
* DESCRIPTION
*  This function stops the uscounter.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void USC_Stop()
{
   HW_WRITE(USCNT_CON,USCNT_STOP_CODE);
}

/*************************************************************************
* FUNCTION
*  USC_Cal_32KFM
*
* DESCRIPTION
*  This function calibrates the uscounter.
*
* PARAMETERS
*  Cal_32K       -    32K crystal counts
*  Cal_26M       -    counts of 26M clock when 32K crystal count to Cal_32K
*
* RETURNS
*  none
*
*************************************************************************/
void USC_Cal_32KFM( kal_uint32 Cal_32K, kal_uint32 Cal_26M)
{
    double Ratio;
    Ratio = ((double)Cal_26M)* ( ((double)USCNT_FREQ) * ( (double)(1<<18) ) / 26000000 ) / ((double)Cal_32K);
    HW_WRITE(F32K_FM, (kal_uint32)(Ratio)); 
}

/*************************************************************************
* FUNCTION
*  USC_Wake_Up_Init
*
* DESCRIPTION
*  This function is used to initialize the us counter variable during waking up to fixed us HW bug. 
*  ths function is only called by  UL1SM_Interrupt (3G wake-up LISR) and L1SM_TDMAInterrupt (2G wake up LISR)
*
* PARAMETERS
*  Timer       -    0: use TDMA timer, 1: use RTR timer
*
* RETURNS
*  none
*
*************************************************************************/
void USC_Wake_Up_Init( kal_uint32  Timer )
{
#if defined(MT6268_S00)

    kal_uint32 irq;
     irq = LockIRQ();
	 
    if( Wake_US_Updated == 0)
    {
      Wake_USCNTI = HW_READ(USCNTI_VAL);
        Wake_Timer = Timer;
        Wake_33us_TimeOut = 0;	
        if( Timer == 0 )
	       Wake_TimerCnt = HW_READ(US_TD_Timer);
        else
         Wake_TimerCnt = HW_READ(US_RTR_Timer) & 0x7FFF ;
	Wake_US_Updated = 1;
	
	//Wake_Temp_Dur = 0;
	//Wake_Timer_Count = 0;
    }

    RestoreIRQ(irq & 0x000000c0);
	
#endif	
	
}


/*************************************************************************
* FUNCTION
*  USC_Get_Int
*
* DESCRIPTION
* This function is used to get the integer value of us counter to fix the us counter hw bug.
*
* PARAMETERS
*  none
*
* RETURNS
*  compensated us counter value.
*
*************************************************************************/
kal_uint32 USC_Get_Int(void)
{
#if defined(MT6268_S00)

    kal_uint32 ret_val,irq,duration;

     irq = LockIRQ();
    
    if(  Wake_33us_TimeOut == 0 )
    {
        if ( Wake_Timer == 1 )
        {
            //Wake_Timer_Tick[Wake_Timer_Count] = (*US_RTR_Timer & 0x7FFF ) ;
          if( (HW_READ(US_RTR_Timer) & 0x7FFF ) >=  Wake_TimerCnt )
            {
                //duration = ( (*US_RTR_Timer & 0x7FFF )  - Wake_TimerCnt )*325/3072 ;
                 duration = (( (*US_RTR_Timer & 0x7FFF )  - Wake_TimerCnt )*6933)>>16;
            }
	     else
	     {
	         //duration = ( 0x7FFF - Wake_TimerCnt + (*US_RTR_Timer & 0x7FFF ) )*325/3072;
              duration = (( 0x7FFF - Wake_TimerCnt + (HW_READ(US_RTR_Timer) & 0x7FFF ) )*6933)>>16;
	     }
        }
	 else
	 {
	     //Wake_Timer_Tick[Wake_Timer_Count] =  ( *US_TD_Timer  );
	        if( (HW_READ(US_TD_Timer)) >= Wake_TimerCnt )
	     {
	             duration = ( ( HW_READ(US_TD_Timer) ) - Wake_TimerCnt )*3;
	     }
	     else
	     {
	             duration = ((HW_READ(US_TD_Wrape)) - Wake_TimerCnt + (HW_READ(US_TD_Timer)) )*3;
	     }
	 }

	 
	 //Wake_Timer_Count ++;
	 //Wake_Temp_Dur = duration;
	 
        if ( duration <  100 )  //100 -> 33us 
        {
            ret_val = Wake_USCNTI + duration - 1;
	     if( ret_val > 0x0FFFFFFF )
	         ret_val -= 0x0FFFFFFF;

        }
  	 else
	 {
	     Wake_33us_TimeOut = 1;
	     Wake_US_Updated = 0;
         ret_val = HW_READ(USCNTI_VAL);
	 }
    }
    else
    {
        Wake_33us_TimeOut = 1;
      ret_val = HW_READ(USCNTI_VAL);
    }
	
    RestoreIRQ(irq & 0x000000c0);
	
    return ret_val;
	
#else
   return 0;
#endif	
}




/*************************************************************************
* FUNCTION
*  USC_Get_TimeStamp
*
* DESCRIPTION
*  This function calculate the frame number.
*
* PARAMETERS
*  none
*
* RETURNS
*  Frame number since system power up
*
*************************************************************************/
kal_uint32 USC_Get_TimeStamp( void )
{
#if defined(__ALIGN_2G_CLOCK__)

    kal_uint32 uscnti,curFrame,_savedMask;
    
    _savedMask = SaveAndSetIRQMask();
    
    uscnti= ust_get_current_time();
    if (uscnti >= Pre_USCNTI) {
        curFrame = USCNT_TO_FRAME( uscnti - Pre_USCNTI ); // dur/3250/(120/26)
    } else {
        curFrame = USCNT_TO_FRAME((USCNT_WRAP - Pre_USCNTI) + uscnti);
    }
    FrameCount += curFrame;
    
    Pre_USCNTI += 	FRAME_TO_USCNT(curFrame);

    if( Pre_USCNTI > USCNT_WRAP )
    {
        Pre_USCNTI -= USCNT_WRAP;
    }
    
    RestoreIRQMask(_savedMask);
    
    return FrameCount;
	
#else

    kal_uint32 uscnti,curFrame,_savedMask;

    _savedMask = SaveAndSetIRQMask();

    uscnti= ust_get_current_time();

    if (uscnti >= Pre_USCNTI) {
        Total_USCNTI += (uscnti - Pre_USCNTI);		
    } else {
        Total_USCNTI += ((USCNT_WRAP - Pre_USCNTI) + uscnti);
    }    

    Pre_USCNTI = uscnti;

    curFrame = USCNT_TO_FRAME(Total_USCNTI);

    RestoreIRQMask(_savedMask);
	

	return curFrame;
	

#endif
}
#ifdef __MTK_TARGET__
#pragma arm section
#endif

kal_uint32 USC_Get_TimeStamp_CNT( void )
{
    return Pre_USCNTI;
}

#if defined(__TINY_SYS__)
#include "csci.h"
typedef struct uscounter_backup_info_s{
	kal_uint32 bk_Pre_USCNTI;
	kal_uint64 bk_Total_USCNTI;
}uscounter_backup_info_t;

CSCI_DEFINE_VAR(uscounter_backup_info_t,uscounter_backup_info);

#if defined(__TINY_SYS_AP__)
void USCOUNTER_Backup(void)
{
	uscounter_backup_info.bk_Pre_USCNTI = Pre_USCNTI;
	uscounter_backup_info.bk_Total_USCNTI = Total_USCNTI;
}
#endif /* __TINY_SYS_AP__ */

#if defined(__TINY_SYS_TS__)
void Restore_Uscounter(void)
{
	/* restore usconter global structure */
	Pre_USCNTI = uscounter_backup_info.bk_Pre_USCNTI;
	Total_USCNTI = uscounter_backup_info.bk_Total_USCNTI;
}
#endif /* __TINY_SYS_TS__ */

#endif /* __TINY_SYS__ */

#endif //__HW_US_TIMER_SUPPORT__
