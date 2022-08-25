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
 *   l1_interface.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements layer1 inteface function for system initialization usage
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

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "l1d_cid.h"
#include "l1d_reg.h"
#include "l1d_data.h"
#include "l1_interface.h"

#include "reg_base.h"
#include "kal_general_types.h"
#if IS_CHIP_MT6276
#include "init.h"
#endif
#if IS_UDVT_FH_SUPPORT
#include "l1_fh_interface.h"
#endif
/*************************************************************************
 * Function and variable declaration
 *************************************************************************/

/*************************************************************************
 * Global constant and data definition
 *************************************************************************/

/*************************************************************************
 * FUNCTION
 *    HW_TDMA_Start
 *
 * DESCRIPTION
 *    This function powers on TDMA module.
 *
 * PARAMETERS
 *
 * RETURNS
 *    None
 *
 * GLOBALS AFFECTED
 *
 *************************************************************************/
void HW_TDMA_Start(void)
{
   HW_WRITE(PDN_CLR2, PDN_CON_TDMA); /*power on TDMA*/
}

/*************************************************************************
 * FUNCTION
 *    HW_TDMA_Enable_CTIRQ1
 *
 * DESCRIPTION
 *    This function enable TDMA module CTIRQ1.
 *
 * PARAMETERS
 *
 * RETURNS
 *    None
 *
 * GLOBALS AFFECTED
 *
 *************************************************************************/
void HW_TDMA_Enable_CTIRQ1(void)
{
   uintX dX;

   HW_TDMA_Start();
   HW_WRITE(TDMA_CTIRQ1, TQ_CTIRQ1);
   HW_WRITE(TDMA_WRAP,   TQ_WRAP_COUNT-1);
   HW_WRITE(TDMA_EVTVAL, TQ_VALIDATE_COUNT);
   dX  = HW_READ(TDMA_EVTENA(0));
   dX |= 0x2;
   HW_WRITE(TDMA_EVTENA(0), dX);
}

/*************************************************************************
 * FUNCTION
 *    HW_wait_32k_start
 *
 * DESCRIPTION                                                           
 *    This function use 13M to calibrate 32k clock
 *
 * PARAMETERS
 *    None
 *
 * RETURNS
 *    None
 *
 * GLOBALS AFFECTED
 *    None
 *
 * NOTES
 *    IS_FM_ON_26M_CHIP is defiend in l1d_cid.h, we should request L1D to update them
 *
 *************************************************************************/
#if IS_FM_ON_26M_CHIP
#define FM_RESULT_UPPER_BOUND    1900
#define FM_RESULT_LOWER_BOUND    1300
#else     // 13M
#define FM_RESULT_UPPER_BOUND    950
#define FM_RESULT_LOWER_BOUND    650
#endif

void HW_wait_32k_start(void)
{
#if IS_CHIP_MT6268T || IS_CHIP_MT6268T_DMAC || IS_CHIP_MT6270A
   // no need 32k
#elif IS_CENTRALIZED_SMM_CHIP
   /*CSMM use 26M to calibrate 32K at TOPSM HW module*/
   kal_uint32 result;
   int count = 0, delay_count;
   int waiting_32k_count = 80000;
   kal_uint32 tmp_T0 = 0, tmp_T1 = 0, tmp_D0 = 0, tmp_D1 = 0;

   /* Enable FRC for FM. */
   HW_WRITE( FRC_CON, (CMD_MAGIC_VALUE+0x00000001) );
   HW_WRITE( FM_CAL, 2 ); /*calibrate 2T 32K, ideal got 1586.9T 26M*/

   while(count < waiting_32k_count)
   {
      /* Enable FM and no need to Unmask FM INT. */
      HW_WRITE(FM_CON, 0x11);

      delay_count = 0;
      /* Polling until FM_EN bit is cleared. */
      while((HW_READ(FM_CON) & 0x1))
      #if IS_CHIP_MT6276
      {
          kal_uint16 wait_count;

          if (delay_count < 0x500)
          {
              delay_count++;
              continue;
          }

          if (INT_ChipName() == CHIP_MT6276 && INT_ecoVersion() == ECO_E2 )
          {
              //kal_uint16 reg_val;
              HW_WRITE((volatile unsigned short *)(RTC_base+0x004C), 0x1a57); // write 0x1a57 to RTC_XOSCCAL
              wait_count = 0;
              while(wait_count < 0x2000)
              {
                 wait_count++;
              }

              HW_WRITE((volatile unsigned short *)(RTC_base+0x004C), 0x2b68); // write 0x2b64 to RTC_XOSCCAL
              wait_count = 0;
              while(wait_count < 0x2000)
              {
                 wait_count++;
              }

              HW_WRITE((volatile unsigned short *)(RTC_base+0x004C), 0x9);  // write 0x9 to XOSCCALI
              wait_count = 0;
              while(wait_count < 0x2000)
              {
                 wait_count++;
              }
          }
          delay_count = 0;
      }
      #else
      ;  (void)delay_count;  // to avoid build warning
      #endif

      tmp_T0 = (HW_READ(FM_T0)) & 0xFFFFFF;
      tmp_D0 = (HW_READ(FM_T0)) >> 24;
      tmp_T1 = (HW_READ(FM_T1)) & 0xFFFFFF;
      tmp_D1 = (HW_READ(FM_T1)) >> 24;
      if( tmp_T1 > tmp_T0 )
      {
         result = (tmp_T1*26+tmp_D1) - (tmp_T0*26+tmp_D0);
      }
      else /* 1MHz FRC wrap case: */
      {
         result = ((tmp_T1+0x1000000)*26+tmp_D1) - (tmp_T0*26+tmp_D0);
      }
      if( FM_RESULT_LOWER_BOUND < result && result < FM_RESULT_UPPER_BOUND )
      {
         /* Clear INT of FM. Need to set bit[4] to mask it. */
         HW_WRITE(FM_CON, 0x110);
         break;
      }
      count++;
   }
#else
   int result;
   int count = 0;
   int waiting_32k_count = 80000;
   unsigned short sm_cnf = HW_READ(SM_CNF);

   HW_WRITE(SM_FM_DURATION, 0x0);
   HW_WRITE(SM_CNF, sm_cnf&(~0x1));

   while(count < waiting_32k_count)
   {
      HW_WRITE(SM_CONTROL,0x1);

      while(!(HW_READ(SM_STATUS) & 0x2)) ;

      result = ((HW_READ(SM_FM_RESULT_M) & 0x03FF) << 16) | HW_READ(SM_FM_RESULT_L);
      if( FM_RESULT_LOWER_BOUND < result && result < FM_RESULT_UPPER_BOUND )
      {
         HW_WRITE(SM_STATUS, 0x07F3);   //write one clear this register
         break;
      }
      count++;
   }

   HW_WRITE(SM_CNF, sm_cnf);
#endif
}

/*************************************************************************
 *    Interface to enable the frequency for the UDVT load
 *************************************************************************/
#if IS_UDVT_FH_SUPPORT
extern const unsigned int FH_table_UDVT[]; /*Freqency hopping table*/
unsigned int MPLL_FH_idx = 0 ;
static L1DFHParamUDVT l1dfh_udvt;

static void FH_init_FHtable( void );
void ReSet_MPLLFH_FHSTR( void );
void FH_set_fhset( unsigned short win_idx, sFHset* _fhset );

const unsigned int FH_table_UDVT[] =
{
   0,    5,    7,    10,   12,   14,   17,   20,    //0~7
   25,   29,   32,   33,   36,   39,   42,   44,    //8~15
   47,   50,   52,   56,   60,   62,   63,   65,    //16~23
   68,   71,   76,   80,   81,   83,   84,   92,    //24~31
   125,  134,  137,  142,  144,  159,  209,  243,   //32~39
   252,  259,  262,  277,  284,  291,  294,  298,   //40~47
   301,  323,  328,  337,  345,  354,  361,  367,   //48~55
   370,  375,  379,  386,  393,  404,  415,  423,   //56~63
};
#define FH_table_UDVT_SIZE  (sizeof(FH_table_UDVT)/sizeof(int))

void WAIT_TIME_QB( short time_qb )
{
   unsigned short  last_qb, cur_qb;
   short  qb_diff, qb_remain;

   qb_remain = time_qb;
   last_qb = HW_READ( TDMA_TQCNT );
   while( qb_remain>0 )
   {  cur_qb = HW_READ( TDMA_TQCNT );
      qb_diff = cur_qb-last_qb;
      qb_remain -= (qb_diff<0) ? 1 : qb_diff;
      last_qb = cur_qb;
   }
}

void SetupMPLLFH( void )
{
   ReSet_MPLLFH_FHSTR();

   if( MPLL_FH_idx%FH_table_UDVT_SIZE < 32)
   {  l1dfh_udvt.FHset_Modem.fh_set_l = 1 << (MPLL_FH_idx%FH_table_UDVT_SIZE);
      l1dfh_udvt.FHset_Modem.fh_set_h = 0;
   }
   else
   {  l1dfh_udvt.FHset_Modem.fh_set_l = 0;
      l1dfh_udvt.FHset_Modem.fh_set_h = 1 << ((MPLL_FH_idx%FH_table_UDVT_SIZE)-32);
   }
   MPLL_FH_idx++;

   FH_set_fhset( 0 , &l1dfh_udvt.FHset_Modem );

   HW_WRITE( TDMA_REGBIAS, 0 );
   HW_WRITE( TDMA_FHSTR(0), 256 );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void FH_init_FHtable(void)
{
   int i;
   unsigned int d16;

   /*Indicate write FH table at addr 0*/
   HW_WRITE( TDMA_FHCON(2), TDMA_FHCON2_DEFAULT );

   /*Write FH table*/
   for( i = 0 ; i < FH_table_UDVT_SIZE; i++ )
   {  d16 = TDMA_FHCON3_DEFAULT_INT | FH_table_UDVT[i];
      HW_WRITE( TDMA_FHCON(3), d16 );
      WAIT_TIME_QB(1);
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void ReSet_MPLLFH_FHSTR( void )
{
   int i;

   for( i = 0; i < 6; i++ )
   {  HW_WRITE(TDMA_FHSTR(i), TQ_MAXIMUM);  }

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void FH_set_fhset( unsigned short win_idx, sFHset* _fhset )
{
   /*MNPLL*/
   HW_WRITE( MNPLL_FHSET(win_idx,0), (  _fhset->fh_set_l      & 0xFFFF) );
   HW_WRITE( MNPLL_FHSET(win_idx,1), ( (_fhset->fh_set_l>>16) & 0xFFFF) );
   HW_WRITE( MNPLL_FHSET(win_idx,2), (  _fhset->fh_set_h      & 0xFFFF) );
   HW_WRITE( MNPLL_FHSET(win_idx,3), ( (_fhset->fh_set_h>>16) & 0xFFFF) );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif // IS_UDVT_FH_SUPPORT

void Frequency_hopping_enable( void )
{
#if IS_UDVT_FH_SUPPORT
   int d16;
   sFHset FHset = { (1 << FREE_RUN_BASE), 0 }; // -1%

   /*Enable DDS. Let RG_MDDS_EN[0] = 1*/
   /*It is done in INT_SetPLL()*/

   /*Power on TDMA*/
   HW_WRITE( PDN_CLR2, PDN_CON_TDMA );

   /*Init TQ_WRAP and Event validate*/
   HW_WRITE( TQ_WRAP,   TQ_WRAP_COUNT-1 );
   HW_WRITE( TQ_EVENT_VALID, TQ_VALIDATE_COUNT );

   /*Low index of FH_table_UDVT first*/
   d16 = HW_READ(TDMA_FHCON(0));
   d16 &= TDMA_FHCON0_MASK;
   HW_WRITE( TDMA_FHCON(0), d16 );

   /*MNPLL free run range*/
   L1D_SET_MNPLL_FREE_RUN_RANGE();

   /*EFPLL free run range*/
   L1D_SET_EFPLL_FREE_RUN_RANGE();

   /*MNPLL FH type*/
   L1D_SET_MNPLL_FH_TYPE();

   /*EFPLL FH type*/
   L1D_SET_EFPLL_FH_TYPE();

   /*Reset FH TDMA timer*/
   ReSet_MPLLFH_FHSTR();

   /*init frequency hopping table*/
   FH_init_FHtable();

   FH_set_fhset( 0, &FHset );
   HW_WRITE( TDMA_REGBIAS, 0 );
   HW_WRITE( TDMA_FHSTR(0), 0 );

#endif // IS_UDVT_FH_SUPPORT
}

