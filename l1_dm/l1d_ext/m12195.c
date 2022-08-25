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
 *   m12195.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Setup RF Ramp
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *******************************************************************************/

#include "l1d_cid.h"
#include "l1d_reg.h"
#include "l1d_custom_rf.h"
#include "l1d_rf.h"
#include "l1d_data.h"
#include "m12190.h"

/*---------------------------------------------------------------------------*/

#if IS_BSI_SX0_SUPPORT
#define  SETUP_SR0()                                                          \
   int  event_idx;                                                            \
   int  data_idx;                                                             \
   event_idx = l1d_rf.cwin_idx*CWIN_BSI_EVENT_COUNT+0;                        \
   data_idx  = l1d_rf.cwin_idx*(SX0_DATA_COUNT+SX1_DATA_COUNT+SX3_DATA_COUNT)+BSI_DATA_OFFSET;
#endif

#define  SETUP_SR1()                                                          \
   int  event_idx;                                                            \
   int  data_idx;                                                             \
   event_idx = l1d_rf.cwin_idx*CWIN_BSI_EVENT_COUNT+SR1_EVENT_OFFSET;         \
   data_idx  = l1d_rf.cwin_idx*(SX0_DATA_COUNT+SX1_DATA_COUNT+SX3_DATA_COUNT)+SX0_DATA_COUNT+BSI_DATA_OFFSET;

#define  SETUP_SR3()                                                          \
   int  event_idx;                                                            \
   int  data_idx;                                                             \
   event_idx = l1d_rf.cwin_idx*CWIN_BSI_EVENT_COUNT+SR1_EVENT_OFFSET+1;       \
   data_idx  = l1d_rf.cwin_idx*(SX0_DATA_COUNT+SX1_DATA_COUNT+SX3_DATA_COUNT)+SX0_DATA_COUNT+SX1_DATA_COUNT+BSI_DATA_OFFSET;

#define  SETUP_SR2()                                                          \
   int  event_idx;                                                            \
   int  data_idx;                                                             \
   event_idx = AGCIDX( l1d_rf.rtxwin_idx );                                   \
   data_idx  = AGCDTIDX( l1d_rf.rtxwin_idx );

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_BSI_V2_SUPPORT
#define  SETUP_ST2B_ST2M()  SETUP_SR2()
   #else
#define  SETUP_ST2B_ST2M()                                                    \
   int  event_idx;                                                            \
   int  data_idx;                                                             \
   event_idx = l1d_rf.rtxwin_idx+ST2B_ST2M_EV0;                               \
   data_idx  = ST2B_ST2M_IDX( l1d_rf.rtxwin_idx );
   #endif
#endif

#define  SETUP_ST0()  SETUP_SR0()
#define  SETUP_ST1()  SETUP_SR1()
#define  SETUP_ST2()  SETUP_SR2()
#define  SETUP_ST3()  SETUP_SR3()

#define  HWRITE_1_SDATA( ctrl1, data1 )                                       \
{  HW_WRITE_BSI_DATA_1( data_idx, ((ctrl1)|event_idx), (data1) );             \
}

#define  HWRITE_2_SDATA( ctrl1, data1, ctrl2, data2 )                         \
{  HW_WRITE_BSI_DATA_2( data_idx, ((ctrl1)|event_idx), (data1),               \
                                  ((ctrl2)|event_idx), (data2) );             \
}

#define  HWRITE_3_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3 )           \
{  HW_WRITE_BSI_DATA_3( data_idx, ((ctrl1)|event_idx), (data1),               \
                                  ((ctrl2)|event_idx), (data2),               \
                                  ((ctrl3)|event_idx), (data3) );             \
}

#define  HWRITE_4_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4 )  \
{  HW_WRITE_BSI_DATA_4( data_idx, ((ctrl1)|event_idx), (data1),               \
                                  ((ctrl2)|event_idx), (data2),               \
                                  ((ctrl3)|event_idx), (data3),               \
                                  ((ctrl4)|event_idx), (data4) );             \
}

#define  HWRITE_5_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5 )  \
{  HW_WRITE_BSI_DATA_5( data_idx, ((ctrl1)|event_idx), (data1),               \
                                  ((ctrl2)|event_idx), (data2),               \
                                  ((ctrl3)|event_idx), (data3),               \
                                  ((ctrl4)|event_idx), (data4),               \
                                  ((ctrl5)|event_idx), (data5) );             \
}

/*---------------------------------------------------------------------------*/

#if SX3_DATA_COUNT > SX2_DATA_COUNT
#error "Suspected insufficient BSI SX2 data resource to run SR3 at FSIWinOff scenario"
#endif

void  L1D_RF_ResetSData_StopFSIWinOff( int idx )
{  int i, n=AGCDTIDX(FS_RXWIN_IDX+idx);

   for( i=0; i<SX2_DATA_COUNT; i++, n++ )
      HW_WRITE( BSI_Dn_CON(n), SCTRL_RESERVED );
}

void L1D_RF_SetSData_FSIWinOff( int idx )
{
#if IS_RF_MT6162
   /* For two SR3 CW setup */
   /* For setting control-part (BSI event) of the additional 2nd BSI data */
   HW_WRITE( BSI_Dn_CON(AGCDTIDX(FS_RXWIN_IDX+idx)+1), (signed short)SCTRL_IDLE|AGCIDX(FS_RXWIN_IDX+idx) );

   HW_WRITE_BSI_DATA( FSWIN_STOP_BSI_REG_TABLE[idx  ], FSWIN_STOP_BSI_DATA_TABLE[0] );
   HW_WRITE_BSI_DATA( FSWIN_STOP_BSI_REG_TABLE[idx+2], FSWIN_STOP_BSI_DATA_TABLE[1] );
#elif IS_RF_MT6140D || IS_RF_AD6548 || IS_RF_AD6546 || IS_RF_MT6252RF || IS_RF_MT6256RF || IS_RF_MT6255RF || IS_RF_MT6250RF || IS_RF_MT6251RF || IS_RF_MT6260RF || IS_RF_MT6261RF
   /* For one SR3 CW setup */
   HW_WRITE_BSI_DATA( FSWIN_STOP_BSI_REG_TABLE[idx], FSWIN_STOP_BSI_DATA_TABLE[0] );
#else
#error "Please confirm the number of RF SR3 data for FSIWinOff"
#endif
}

void  L1D_RF_SetPData_PR( void )
{  APBADDR      _reg;
   const short *_d16p;

   _reg  = PDATA_REG_TABLE[ l1d_rf.cwin_idx ];
#if IS_DCS_NB_WB_SWITCH_SUPPORT
   if( L1D_RF_IS_DCS_Change_to_NB() )
   {  _d16p = PDATA_TABLE[ 0 ][ RF_RX ];            }
   else
#endif
   {  _d16p = PDATA_TABLE[ l1d_rf.band ][ RF_RX ];  }
   HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
   HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
   HW_WRITE( _reg, *_d16p );
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   _reg+=2;   _d16p++;
   HW_WRITE( _reg, *_d16p );
   _d16p++;
   _reg = PDATA_REG_TABLE2[ l1d_rf.cwin_idx ];
   HW_WRITE( _reg, *_d16p );
#endif
}

void  L1D_RF_SetPData_PT( void )
#if !IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
{  APBADDR      _reg;
   const short *_d16p;

   _reg  = PDATA_REG_TABLE[ l1d_rf.cwin_idx ];
   _d16p = PDATA_TABLE[ l1d_rf.band ][ RF_TX ];
   HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
   HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
   HW_WRITE( _reg, *_d16p );
   #if IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/ {  int idx = l1d_rf.rx_slots<=11 ? 0 : 1;
/*MT6218~*/    _reg  = PDATA_PT2B_REG_TABLE[idx][ l1d_rf.cwin_idx ];
/*MT6218~*/    _d16p = PDATA_TABLE2[ l1d_rf.band ][ RF_TX ];
/*MT6218~*/    HW_WRITE( _reg, *_d16p );
/*MT6218~*/ }
   #endif
}
#else
{  APBADDR      _reg;
   const short *_d16p;
   #if IS_DCS_TX_NOTCH_SWITCH_SUPPORT
   if( L1D_RF_IS_DCS_Change_to_TX_Notch() ) 
      PDATA_TABLE = PDATA_TABLE_DCS_TX_NOTCH;
   else
      PDATA_TABLE = PDATA_TABLE_DEFAULT;
   #endif

   _reg  = PDATA_REG_TABLE[ l1d_rf.cwin_idx ];
   _d16p = PDATA_TABLE[ l1d_rf.band ][ RF_TX ];
   if ( (l1d_rf.tx_mod_type) & (1<<l1d_rf.modidx) )
   {
      HW_WRITE( _reg, ((*_d16p)|(pdata_8psk)) );   _reg+=2;   _d16p++;
      HW_WRITE( _reg, ((*_d16p)|(pdata_8psk)) );   _reg+=2;   _d16p++;
      HW_WRITE( _reg, ((*_d16p)|(pdata_8psk)) );   _reg+=2;   _d16p++;
      HW_WRITE( _reg, (*_d16p) );//PT3 is end, doesn't need to | PDATA_8PSK
      /* PT3A */
      _d16p++;
      _reg = PDATA_REG_TABLE2[ l1d_rf.cwin_idx ];
      HW_WRITE( _reg, (*_d16p) );
   }
   else
   {
      HW_WRITE( _reg, ((*_d16p)|(pdata_gmsk)) );   _reg+=2;   _d16p++;
      HW_WRITE( _reg, ((*_d16p)|(pdata_gmsk)) );   _reg+=2;   _d16p++;
      HW_WRITE( _reg, ((*_d16p)|(pdata_gmsk)) );   _reg+=2;   _d16p++;
      HW_WRITE( _reg, (*_d16p) );//PT3 is end, doesn't need to | PDATA_GMSK
      /* PT3A */
      _d16p++;
      _reg = PDATA_REG_TABLE2[ l1d_rf.cwin_idx ];
      HW_WRITE( _reg, (*_d16p) );
   }
}
#endif

void  L1D_RF_SetPData_PR2M( void )
{
#if IS_BPI_V2_SUPPORT
/*BPI v2 */ /* PR2M is not supported on BPI v2.0. */
#elif IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/ APBADDR      _reg;
/*MT6218~*/ const short *_d16p;
/*MT6218~*/
/*MT6218~*/ _reg  = PDATA_PR2M_REG_TABLE[ l1d_rf.rtxwin_idx ];
/*MT6218~*/ _d16p = PDATA_TABLE2[ l1d_rf.band ][ RF_RX ];
/*MT6218~*/ HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
/*MT6218~*/ HW_WRITE( _reg, *_d16p );
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6229~*/ APBADDR      _reg;
/*MT6229~*/ const short *_d16p;
/*MT6229~*/
/*MT6229~*/ _reg  = PDATA_PR2M_REG_TABLE[ l1d_rf.rtxwin_idx ];
/*MT6229~*/ _d16p = PDATA_TABLE3[ l1d_rf.band ][ RF_RX ];
/*MT6229~*/ HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
/*MT6229~*/ HW_WRITE( _reg, *_d16p );
#endif
}

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if IS_EPSK_TX_SUPPORT
/*MT6229~*//*EGPRS*/ void  L1D_RF_SetPData_PT2M( void )
/*MT6229~*//*EGPRS*/ {
/*MT6229~*//*EGPRS*/    APBADDR      _reg;
/*MT6229~*//*EGPRS*/    const short *_d16p;
/*MT6229~*//*EGPRS*/    short _d16p2;
      #if IS_DCS_TX_NOTCH_SWITCH_SUPPORT
/*MT6229~*//*EGPRS*/   if( L1D_RF_IS_DCS_Change_to_TX_Notch() ) 
/*MT6229~*//*EGPRS*/      PDATA_TABLE = PDATA_TABLE_DCS_TX_NOTCH;
/*MT6229~*//*EGPRS*/   else
/*MT6229~*//*EGPRS*/      PDATA_TABLE = PDATA_TABLE_DEFAULT;
      #endif
/*MT6229~*//*EGPRS*/
/*MT6229~*//*EGPRS*/    _reg  = PDATA_PT2M_REG_TABLE[ l1d_rf.rtxwin_idx ];
/*MT6229~*//*EGPRS*/    _d16p = PDATA_TABLE3[ l1d_rf.band ][ RF_TX ];
/*MT6229~*//*EGPRS*/    _d16p2 = PDATA_TABLE[ l1d_rf.band ][ RF_TX ][2]; //PDATA of PT2B, so PT2B must later than PT2
/*MT6229~*//*EGPRS*/    //now 8PSK
/*MT6229~*//*EGPRS*/    if ((l1d_rf.tx_mod_type)&(1<<l1d_rf.rtxwin_idx))
/*MT6229~*//*EGPRS*/    {  //change, g-->8
/*MT6229~*//*EGPRS*/       if ((l1d_rf.change)&(1<<l1d_rf.rtxwin_idx))
/*MT6229~*//*EGPRS*/       {
/*MT6229~*//*EGPRS*/          /*Set M1*/ HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
/*MT6229~*//*EGPRS*/          /*Set M2*/ HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
/*MT6229~*//*EGPRS*/          /*Set M3*/ HW_WRITE( _reg, *_d16p );
/*MT6229~*//*EGPRS*/       }
/*MT6229~*//*EGPRS*/       //no change
/*MT6229~*//*EGPRS*/       else
/*MT6229~*//*EGPRS*/       {  HW_WRITE( _reg, ((_d16p2)|(pdata_8psk)) );   _reg+=2;
/*MT6229~*//*EGPRS*/          HW_WRITE( _reg, ((_d16p2)|(pdata_8psk)) );   _reg+=2;
/*MT6229~*//*EGPRS*/          HW_WRITE( _reg, ((_d16p2)|(pdata_8psk)) );
/*MT6229~*//*EGPRS*/       }
/*MT6229~*//*EGPRS*/    }
/*MT6229~*//*EGPRS*/    //now GMSK
/*MT6229~*//*EGPRS*/    else
/*MT6229~*//*EGPRS*/    {  //change, 8-->g
/*MT6229~*//*EGPRS*/       _d16p = PDATA_TABLE3[ l1d_rf.band ][ RF_TX_8G];
/*MT6229~*//*EGPRS*/       if ((l1d_rf.change)&(1<<l1d_rf.rtxwin_idx))
/*MT6229~*//*EGPRS*/       {
/*MT6229~*//*EGPRS*/          /*Set M1*/ HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
/*MT6229~*//*EGPRS*/          /*Set M2*/ HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
/*MT6229~*//*EGPRS*/          /*Set M3*/ HW_WRITE( _reg, *_d16p );
/*MT6229~*//*EGPRS*/       }
/*MT6229~*//*EGPRS*/       //no change
/*MT6229~*//*EGPRS*/       else
/*MT6229~*//*EGPRS*/       {  HW_WRITE( _reg, ((_d16p2)|(pdata_gmsk)) );   _reg+=2;
/*MT6229~*//*EGPRS*/          HW_WRITE( _reg, ((_d16p2)|(pdata_gmsk)) );   _reg+=2;
/*MT6229~*//*EGPRS*/          HW_WRITE( _reg, ((_d16p2)|(pdata_gmsk)) );
/*MT6229~*//*EGPRS*/       }
/*MT6229~*//*EGPRS*/    }
/*MT6229~*//*EGPRS*/
/*MT6229~*//*EGPRS*/ }
   #else
/*MT6229~*/ void  L1D_RF_SetPData_PT2M( void )
/*MT6229~*/ {
/*MT6229~*/ }
   #endif /*End of IS_EPSK_TX_SUPPORT*/
#else
/*mt6218~*/ void  L1D_RF_SetPData_PT2M( void )
/*mt6218~*/ {
/*mt6218~*/ }
#endif

#if IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT2*/ #if IS_FPGA_TARGET
/* under construction !*/
/* under construction !*/
/*BRIGHT2*/ #endif
/*BRIGHT2*/ #if IS_CHIP_TARGET
/* under construction !*/
/* under construction !*/
/*BRIGHT2*/ #endif
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

#if IS_RF_BRIGHT4
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

#if IS_RF_BRIGHT5P
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

#if IS_RF_AERO
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

#if IS_RF_AERO1PLUS
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

#if IS_RF_POLARIS1
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

#if IS_RF_SKY74117
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

#if IS_RF_SKY74400
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

#if IS_RF_MT6119
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

#if IS_RF_MT6119C
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

#if IS_RF_MT6129A
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

#if IS_RF_MT6129B
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

#if IS_RF_MT6129C
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

#if IS_RF_MT6129D
/*MT6129D*/
/*MT6129D*/ /*..........................................................*/
/*MT6129D*/ /*  Define Alias and Table                                  */
/*MT6129D*/ /*..........................................................*/
/*MT6129D*/
/*MT6129D*/ #define  SCTRL_WARM                   SCTRL_WORD(0,24)
/*MT6129D*/ #define  SCTRL_PLL                    SCTRL_WORD(0,24)
/*MT6129D*/ #define  SCTRL_AGC                    SCTRL_WORD(0,24)
/*MT6129D*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,24)
/*MT6129D*/ #define  SCTRL_TXIAC                  SCTRL_WORD(0,24) /* CW4 */
/*MT6129D*/
/*MT6129D*/ const unsigned long SDATA_TXBAND_TABLE[5][2] =
/*MT6129D*/ {
/*MT6129D*/    {       0L,       0L },  /* FrequencyBand400 (not support)  */
/*MT6129D*/    {0x128182L,0x138182L },  /* FrequencyBand850                */
/*MT6129D*/    {0x128982L,0x138982L },  /* FrequencyBand900                */
/*MT6129D*/    {0x129182L,0x139182L },  /* FrequencyBand1800               */
/*MT6129D*/    {0x129982L,0x139982L },  /* FrequencyBand1900               */
/*MT6129D*/ };
/*MT6129D*/
/*MT6129D*/ // For case of GSM850 in GSM900 path
/*MT6129D*/ const unsigned long SDATA_WARM_TABLE_RX_GSM850in900[5]=
/*MT6129D*/ {
/*MT6129D*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129D*/      0x122982,  /* FrequencyBand850 (Get GSM850 signal from GSM900 input pins) */
/*MT6129D*/      0x122182,  /* FrequencyBand900 (Get GSM900 signal from GSM850 input pins, just avoid to camp on GSM900 network, not swap*/
/*MT6129D*/      0x123182,  /* FrequencyBand1800               */
/*MT6129D*/      0x123982   /* FrequencyBand1900               */
/*MT6129D*/ };
/*MT6129D*/
/*MT6129D*/ const unsigned long SDATA_WARM_TABLE[5]=
/*MT6129D*/ {
/*MT6129D*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129D*/      0x122182,  /* FrequencyBand850                */
/*MT6129D*/      0x122982,  /* FrequencyBand900                */
/*MT6129D*/      0x123182,  /* FrequencyBand1800               */
/*MT6129D*/      0x123982   /* FrequencyBand1900               */
/*MT6129D*/ };
/*MT6129D*/
/*MT6129D*/ const unsigned long SDATA_TXIAC_TABLE[5]=
/*MT6129D*/ {
/*MT6129D*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129D*/      0x342854,  /* FrequencyBand850                */
/*MT6129D*/      0x342854,  /* FrequencyBand900                */
/*MT6129D*/      0x14A854,  /* FrequencyBand1800               */
/*MT6129D*/      0x14A854   /* FrequencyBand1900               */
/*MT6129D*/ };
/*MT6129D*/
/*MT6129D*/ /*..........................................................*/
/*MT6129D*/ /* Serial Interface Implement                               */
/*MT6129D*/ /*..........................................................*/
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_SR1( void )
/*MT6129D*/ {  unsigned long sdata_warm;
/*MT6129D*/
/*MT6129D*/    SETUP_SR1();
/*MT6129D*/
/*MT6129D*/    if( BBTXParameters.bbrx_gsm850_gsm900_swap )
/*MT6129D*/    {  sdata_warm = SDATA_WARM_TABLE_RX_GSM850in900[l1d_rf.band];
/*MT6129D*/    }
/*MT6129D*/    else
/*MT6129D*/    {  sdata_warm = SDATA_WARM_TABLE[l1d_rf.band];
/*MT6129D*/    }
/*MT6129D*/
/*MT6129D*/    HWRITE_3_SDATA( SCTRL_WARM,     sdata_warm,
/*MT6129D*/                    SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6129D*/                    SCTRL_RESERVED, 0 );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_SR2( void )
/*MT6129D*/ {
/*MT6129D*/    SETUP_SR2();
/*MT6129D*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_SR3( void )
/*MT6129D*/ {
/*MT6129D*/    SETUP_SR3();
/*MT6129D*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_ST1( void )
/*MT6129D*/ {
/*MT6129D*/    SETUP_ST1();
/*MT6129D*/    HWRITE_3_SDATA( SCTRL_WARM,      SDATA_WARM_TABLE[l1d_rf.band],  /*Band information for TXVCO*/
/*MT6129D*/                    SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6129D*/                    SCTRL_TXIAC,     SDATA_TXIAC_TABLE[l1d_rf.band]);
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_ST2( void )
/*MT6129D*/ {  extern char mt6119_d_flag;
/*MT6129D*/    SETUP_ST2();
/*MT6129D*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band][mt6119_d_flag] );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_ST3( void )
/*MT6129D*/ {
/*MT6129D*/    SETUP_ST3();
/*MT6129D*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129D*/ }
/*MT6129D*/
#endif

#if IS_RF_MT6139B
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

#if IS_RF_MT6139C
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

#if IS_RF_MT6139E
/*MT6139E*/
/*MT6139E*/ /*..........................................................*/
/*MT6139E*/ /*  Define Alias and Table                                  */
/*MT6139E*/ /*..........................................................*/
/*MT6139E*/
/*MT6139E*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6139E*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6139E*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6139E*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6139E*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6139E*/ #define  SCTRL_TXDIV_GC               SCTRL_WORD(0,26) /* CW11 */
/*MT6139E*/
/*MT6139E*/ const unsigned long SDATA_WARM   = 0x0000402L;
/*MT6139E*/ const unsigned long SDATA_TXMODE = 0x0003002L;
/*MT6139E*/ unsigned long CW11_RF[5]={0x0000000,     //450   not support
/*MT6139E*/                           0x1B4C7FB,     //850   Low current DIV_GC=00 TXMODGAIN=000
/*MT6139E*/                           0x1B4C7FB,     //900   Low current DIV_GC=00 TXMODGAIN=000
/*MT6139E*/                           0x1B4E7FB,     //1800  Default DIV_GC=01 TXMODGAIN=100
/*MT6139E*/                           0x1B4E7FB };   //1900  Default DIV_GC=01 TXMODGAIN=100
/*MT6139E*/ unsigned long auto_cal  = 0x0002000; //turn on auto calibrate
/*MT6139E*/
/*MT6139E*/ /*..........................................................*/
/*MT6139E*/ /* Serial Interface Implement                               */
/*MT6139E*/ /*..........................................................*/
/*MT6139E*/
   #if IS_BSI_SX0_SUPPORT
/*MT6139E*/ void  L1D_RF_SetSData_SR0( void )
/*MT6139E*/ {
/*MT6139E*/ }
   #endif
/*MT6139E*/ void  L1D_RF_SetSData_SR1( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_SR1();
/*MT6139E*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6139E*/                   SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6139E*/                   SCTRL_RESERVED, 0);
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_SR2( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_SR2();
/*MT6139E*/    HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data|auto_cal);
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_SR3( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_SR3();
/*MT6139E*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6139E*/ }
/*MT6139E*/
   #if IS_BSI_SX0_SUPPORT
/*MT6139E*/ void  L1D_RF_SetSData_ST0( void )
/*MT6139E*/ {
/*MT6139E*/ }
   #endif
/*MT6139E*/ void  L1D_RF_SetSData_ST1( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_ST1();
/*MT6139E*/    HWRITE_3_SDATA(SCTRL_WARM,      SDATA_WARM,
/*MT6139E*/                   SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6139E*/                   SCTRL_TXDIV_GC,  CW11_RF[l1d_rf.band]  );
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_ST2( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_ST2();
/*MT6139E*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_ST3( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_ST3();
/*MT6139E*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6139E*/ {
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6139E*/ {
/*MT6139E*/ }
/*MT6139E*/
#endif

#if IS_RF_MT6140A
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

#if IS_RF_MT6140B
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
/*MT6140B*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140B*/ #endif
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

#if IS_RF_MT6140C
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
/*MT6140C*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140C*/ #endif
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

#if IS_RF_MT6140D
/*MT6140D*/
/*MT6140D*/ /*..........................................................*/
/*MT6140D*/ /*  Define Alias and Table                                  */
/*MT6140D*/ /*..........................................................*/
/*MT6140D*/
/*MT6140D*/ #define  SCTRL_STANDBY                SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6140D*/ #define  SCTRL_TXCW                   SCTRL_WORD(0,26) /* CW11 */
/*MT6140D*/
/*MT6140D*/ const unsigned long SDATA_SLEEP   = 0x0000002L; // Sleep mode
/*MT6140D*/ const unsigned long SDATA_WARM    = 0x20827E2L; // Warm up mode
/*MT6140D*/ const unsigned long SDATA_TXMODE  = 0x0003002L; // GMSK 0x0003002L;
/*MT6140D*/ const unsigned long SDATA_RXMODE  = 0x0000C02L; // RX mode
/*MT6140D*/ unsigned long auto_cal  = 0x0002000L; //turn on auto calibrate
/*MT6140D*/ unsigned short LB_CW_High_Idx  = (19-12);  //PCL12 =Idx(19-12)
/*MT6140D*/ unsigned short HB_CW_High_Idx  = (15- 6);  //PCL 6 =Idx(15- 6)
/*MT6140D*/
/*MT6140D*/ /*..........................................................*/
/*MT6140D*/ /* Serial Interface Implement                               */
/*MT6140D*/ /*..........................................................*/
/*MT6140D*/
   #if IS_BSI_SX0_SUPPORT
/*MT6140D*/ void  L1D_RF_SetSData_SR0( void )
/*MT6140D*/ {
/*MT6140D*/ }
   #endif
/*MT6140D*/ void  L1D_RF_SetSData_SR1( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_SR1();
/*MT6140D*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6140D*/                   SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6140D*/                   SCTRL_RESERVED, 0 );
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_SR2( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_SR2();
/*MT6140D*/    HWRITE_1_SDATA( SCTRL_AGC,    SDATA_RXMODE|l1d_rf.AGC_data|auto_cal);
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_SR3( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_SR3();
/*MT6140D*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP);
/*MT6140D*/ }
/*MT6140D*/
   #if IS_BSI_SX0_SUPPORT
/*MT6140D*/ void  L1D_RF_SetSData_ST0( void )
/*MT6140D*/ {
/*MT6140D*/ }
   #endif
/*MT6140D*/ void  L1D_RF_SetSData_ST1( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST1();
/*MT6140D*/    HWRITE_3_SDATA(
/*MT6140D*/                   SCTRL_WARM,         SDATA_WARM,
/*MT6140D*/                   SCTRL_PLL,          l1d_rf.RFN_data,
/*MT6140D*/                   SCTRL_RESERVED,         0);
/*MT6140D*/
/*MT6140D*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140D*/    if(l1d_rf.d2c_txiqconfig==0)
/*MT6140D*/    {
/*MT6140D*/       L1D_BFE_SetTxIQ_Config();
/*MT6140D*/    }
/*MT6140D*/ #endif
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_ST2( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST2();
/*MT6140D*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_ST3( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST3();
/*MT6140D*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST2B_ST2M();
/*MT6140D*/    {
/*MT6140D*/    #if IS_EPSK_TX_SUPPORT
/*MT6140D*/       if((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)
/*MT6140D*/       {
/*MT6140D*/          unsigned short   cw_idx;
/*MT6140D*/          cw_idx=L1D_RF_GetTxPAVBias_TxITC(LB_CW_High_Idx, HB_CW_High_Idx);
/*MT6140D*/          HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[(cw_idx>>4)&0x1][1][l1d_rf.band]|((cw_idx&0x7)<<8));
/*MT6140D*/       }
/*MT6140D*/       else
/*MT6140D*/    #endif
/*MT6140D*/       {
/*MT6140D*/          HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[0][0][l1d_rf.band]);
/*MT6140D*/       }
/*MT6140D*/    }
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST2B_ST2M();
/*MT6140D*/    {
/*MT6140D*/ #if IS_EPSK_TX_SUPPORT
/*MT6140D*/       if((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)
/*MT6140D*/       {
/*MT6140D*/          unsigned short   cw_idx;
/*MT6140D*/          cw_idx=L1D_RF_GetTxPAVBias_TxITC(LB_CW_High_Idx, HB_CW_High_Idx);
/*MT6140D*/          HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[(cw_idx>>4)&0x1][1][l1d_rf.band]|((cw_idx&0x7)<<8));
/*MT6140D*/       }
/*MT6140D*/       else
/*MT6140D*/ #endif
/*MT6140D*/       {
/*MT6140D*/          HWRITE_1_SDATA( SCTRL_TXBAND, TXCW[0][0][l1d_rf.band]);
/*MT6140D*/       }
/*MT6140D*/    }
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ #endif
/*MT6140D*/
#endif

#if IS_RF_CMOSEDGE
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
/*CMOSEDGE*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/ #if IS_EPSK_TX_SUPPORT
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
/*CMOSEDGE*/ #endif
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
/*CMOSEDGE*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    #if IS_EPSK_TX_SUPPORT
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
/*CMOSEDGE*/    #endif
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
/*CMOSEDGE*/ #if IS_EPSK_TX_SUPPORT
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
/*CMOSEDGE*/ #endif
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
/*CMOSEDGE*/ #endif
/* under construction !*/
#endif

#if IS_RF_MTKSOC1T
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
/*MTKSOC1T*/#if MTKSOC1_SX_CALSBA
/* under construction !*/
/*MTKSOC1T*/#else
/* under construction !*/
/*MTKSOC1T*/#endif
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
/*MTKSOC1T*/#if IS_RF_MTKSOC1_A5
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MTKSOC1T*/#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MTKSOC1T*/#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MTKSOC1T*/#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MTKSOC1T*/#endif
/* under construction !*/
#endif

#if IS_RF_MTKSOC1
/*MTKSOC1*/
/*MTKSOC1*/ /*..........................................................*/
/*MTKSOC1*/ /*  Define Alias and Table                                  */
/*MTKSOC1*/ /*..........................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ #define  SCTRL_WARM                    SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_PLL                     SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_DCXO                    SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_AGC                     SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_TXBAND                  SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_TXCW                    SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_TXDCOC                  SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_CAPID                   SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SCTRL_RFVCO_K                 SCTRL_WORD(0,26)
/*MTKSOC1*/ #define  SDATA_SLEEP                   0x0200000L
/*MTKSOC1*/ #define  SCTRL_CW23                    SCTRL_RESERVED
/*MTKSOC1*/ #define  SCTRL_CW27                    SCTRL_RESERVED
/*MTKSOC1*/
/*MTKSOC1*/ /*..........................................................*/
/*MTKSOC1*/ /* Serial Interface Implement                               */
/*MTKSOC1*/ /*..........................................................*/
/*MTKSOC1*/
/*MTKSOC1*/ extern int L1D_Get_MT6253_SDATA_Index( void );
/*MTKSOC1*/
/*MTKSOC1*/ static unsigned long ST2_DATA_TABLE[2][3]=
/*MTKSOC1*/ {
/*MTKSOC1*/    {
/*MTKSOC1*/       (0x0E19EAB & ~(0x1FF<<9)) | (0x0EC<<9),
/*MTKSOC1*/       (0x0E19EAB & ~(0x1FF<<9)) | (0x08F<<9),
/*MTKSOC1*/       (0x0E19EAB & ~(0x1FF<<9)) | (0x07F<<9),
/*MTKSOC1*/    },
/*MTKSOC1*/    {
/*MTKSOC1*/       0x0E1CEB3,
/*MTKSOC1*/       0x0E12EB3,
/*MTKSOC1*/       0x0E10EB3,
/*MTKSOC1*/    },
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_SR1( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    long cw23;
/*MTKSOC1*/    SETUP_SR1();
/*MTKSOC1*/
/*MTKSOC1*/    if(  (l1d_rf.band == FrequencyBand1900) || (l1d_rf.band == FrequencyBand900) )
/*MTKSOC1*/    {
/*MTKSOC1*/       cw23 = 0x1784201L;
/*MTKSOC1*/    }
/*MTKSOC1*/    else
/*MTKSOC1*/    {
/*MTKSOC1*/       cw23 = 0x1784200L;
/*MTKSOC1*/    }
/*MTKSOC1*/    HWRITE_5_SDATA(
/*MTKSOC1*/       SCTRL_DCXO,    (l1d_rf.AFC_data&0x1FFF)|0x0300000,
/*MTKSOC1*/       SCTRL_CW27, ( ( (l1d_rf.RFN_data>>25)& 0x3F)<<7 ) | ( (l1d_rf.IFN_data>>25)& 0x7F) | 0x1b00000L,/*cw27*/
/*MTKSOC1*/       SCTRL_WARM,         (l1d_rf.IFN_data & 0x1FFFFFF),
/*MTKSOC1*/       SCTRL_PLL,          (l1d_rf.RFN_data & 0x1FFFFFF),
/*MTKSOC1*/       SCTRL_CW23, cw23);
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_SR2( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    SETUP_SR2();
/*MTKSOC1*/    HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data);  //CW4
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_SR3( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    SETUP_SR3();
/*MTKSOC1*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP);
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_ST1( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    SETUP_ST1();
/*MTKSOC1*/
/*MTKSOC1*/    HWRITE_5_SDATA(
/*MTKSOC1*/       SCTRL_DCXO,    (l1d_rf.AFC_data&0x1FFF)|0x0300000,
/*MTKSOC1*/       SCTRL_CW27, ( ( (l1d_rf.RFN_data>>25)& 0x3F)<<7 ) | ( (l1d_rf.IFN_data>>25)& 0x7F) | 0x1b00000L,/*cw27*/
/*MTKSOC1*/       SCTRL_WARM,         (l1d_rf.IFN_data & 0x1FFFFFF),
/*MTKSOC1*/       SCTRL_PLL,          (l1d_rf.RFN_data & 0x1FFFFFF),
/*MTKSOC1*/       SCTRL_RESERVED, 0 );
/*MTKSOC1*/
/*MTKSOC1*/    L1D_SetTxIQSwap_NO_PCS1900();
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_ST2( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    unsigned long *ST2_DATA = L1D_Get_MT6253_SDATA_Index() ? ST2_DATA_TABLE[1] : ST2_DATA_TABLE[0];
/*MTKSOC1*/    SETUP_ST2();
/*MTKSOC1*/    if( l1d_rf.band <= FrequencyBand900 )
/*MTKSOC1*/    {  HWRITE_1_SDATA( SCTRL_TXCW, ST2_DATA[0] );  } //CW14
/*MTKSOC1*/    else
/*MTKSOC1*/    {
/*MTKSOC1*/       //CW14 : OPLL_LP[4:0]=00111 and APD_GC[3:0] = 1111 in DCS and PCS bands when OPLL_DIV4O5_DIV4 = 0.
/*MTKSOC1*/       //CW14 : OPLL_LP[4:0]=01000 and APD_GC[3:0] = 1111 in DCS and PCS bands when OPLL_DIV4O5_DIV4 = 1.
/*MTKSOC1*/       if(l1d_rf.IFN_data & 0x0080000) // in DCS and PCS bands when OPLL_DIV4O5_DIV4 = 1.
/*MTKSOC1*/       {  HWRITE_1_SDATA( SCTRL_TXCW, ST2_DATA[1] );  } //CW14
/*MTKSOC1*/       else                           //in DCS and PCS bands when OPLL_DIV4O5_DIV4 = 0
/*MTKSOC1*/       {  HWRITE_1_SDATA( SCTRL_TXCW, ST2_DATA[2] );  } //CW14
/*MTKSOC1*/    }
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_ST3( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    SETUP_ST3();
/*MTKSOC1*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP);
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_ST2B( void )
/*MTKSOC1*/ {
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_SetSData_ST2M( void )
/*MTKSOC1*/ {
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ #endif
/*MTKSOC1*/
#endif

#if IS_RF_MT6252RF
/*MT6252RF*/
/*MT6252RF*/ /*..........................................................*/
/*MT6252RF*/ /*  Define Alias                                            */
/*MT6252RF*/ /*..........................................................*/
/*MT6252RF*/
/*MT6252RF*/ #define  SCTRL_STANDBY                 SCTRL_WORD(0,29)
/*MT6252RF*/ #define  SCTRL_PLL                     SCTRL_WORD(0,29)
/*MT6252RF*/ #define  SCTRL_DCXO                    SCTRL_WORD(0,29)
/*MT6252RF*/ #define  SCTRL_AGC                     SCTRL_WORD(0,29)
/*MT6252RF*/ #define  SCTRL_TXCW                    SCTRL_WORD(0,29)
/*MT6252RF*/ #define  SCTRL_CW4                     SCTRL_WORD(0,29)
/*MT6252RF*/ #define  SDATA_SLEEP                   0x0200000L
/*MT6252RF*/ #define  SDATA_STANDBY                 0x0244000L
/*MT6252RF*/ #define  SDATA_TXSLEEP                 0x0280000L
/*MT6252RF*/ #define  SDATA_CW96                    0x6072800L                            /* RX Gain (from 0x6013200L to 0x6072800L) */
/*MT6252RF*/
/*MT6252RF*/ /*..........................................................*/
/*MT6252RF*/ /* Serial Interface Implement                               */
/*MT6252RF*/ /*..........................................................*/
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_SR0( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_SR0();
/*MT6252RF*/    HWRITE_3_SDATA( SCTRL_DCXO,    (l1d_rf.AFC_data & 0x1FFF) | (0x3900000L), /* CW57 : set AFC DAC */
/*MT6252RF*/                    SCTRL_STANDBY,  l1d_rf.IFN_data                         , /* CW2  : set mode = standby */
/*MT6252RF*/                    SCTRL_RESERVED, 0 );                                      /* to prevent from missending */
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_SR1( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_SR1();
/*MT6252RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data  );                       /* CW1  : set PLL, RF will enter warmup state */
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_SR2( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_SR2();
/*MT6252RF*/    HWRITE_1_SDATA( SCTRL_AGC,      l1d_rf.AGC_data | (SDATA_CW96) );         /* CW96 : set gain */
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_SR3( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_SR3();
/*MT6252RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF
/*MT6252RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6252RF*/    {
/*MT6252RF*/       #if IS_RF_TX_SLEEP_MODE_SUPPORT
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_TXSLEEP );                           /* CW2: set mode = TX sleep mode */
/*MT6252RF*/       #else
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );         /* CW2: set mode = stand-by mode */
/*MT6252RF*/       #endif
/*MT6252RF*/    }
/*MT6252RF*/    else
/*MT6252RF*/    #endif
/*MT6252RF*/    {
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP);                              /* CW2: set mode = sleep mode */
/*MT6252RF*/    }
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_ST0( void )
/*MT6252RF*/ {
/*MT6252RF*/    unsigned long CW4 = (l1d_rf.band & 0x0001) ? 0x04156A8 : 0x04155A8;
/*MT6252RF*/    SETUP_ST0();
/*MT6252RF*/    HWRITE_3_SDATA( SCTRL_STANDBY,  l1d_rf.IFN_data                         , /* CW2  : set mode = standby */
/*MT6252RF*/                    SCTRL_DCXO,    (l1d_rf.AFC_data & 0x1FFF) | (0x3900000L), /* CW57 : set AFC DAC */
/*MT6252RF*/                    SCTRL_CW4,      CW4 );                                    /* CW4  : optimize performance by band */
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_ST1( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_ST1();
/*MT6252RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data );                        /* CW1  : set PLL, RF will enter warmup state */
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_ST2( void )
/*MT6252RF*/ {
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_ST3( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_ST3();
/*MT6252RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6252RF*/    if( l1d_rf2.dedicated_flag & SC_DEDICATED_2TX )
/*MT6252RF*/    {
/*MT6252RF*/       #if IS_RF_TX_SLEEP_MODE_SUPPORT
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_TXSLEEP );                           /* CW2: set mode = TX sleep mode */
/*MT6252RF*/       #else
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );         /* CW2: set mode = stand-by mode */
/*MT6252RF*/       #endif
/*MT6252RF*/    }
/*MT6252RF*/    else
/*MT6252RF*/    #elif IS_RF_VCO_DOO_OFF
/*MT6252RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6252RF*/    {
/*MT6252RF*/       #if IS_RF_TX_SLEEP_MODE_SUPPORT
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_TXSLEEP );                           /* CW2: set mode = TX sleep mode */
/*MT6252RF*/       #else
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );         /* CW2: set mode = stand-by mode */
/*MT6252RF*/       #endif
/*MT6252RF*/    }
/*MT6252RF*/    else
/*MT6252RF*/    #endif
/*MT6252RF*/    {
/*MT6252RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );                             /* CW2: set mode = sleep mode */
/*MT6252RF*/    }
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_ST2B_ST2M();
/*MT6252RF*/    HWRITE_1_SDATA( SCTRL_TXCW,     0x8500000L );                             /* CW133: to enter TX mode */
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6252RF*/ {
/*MT6252RF*/    SETUP_ST2B_ST2M();
/*MT6252RF*/    HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6252RF*/ }
/*MT6252RF*/
#endif

#if IS_RF_MT6261RF
/*MT6261RF*/
/*MT6261RF*/ /*..........................................................*/
/*MT6261RF*/ /*  Define Alias                                            */
/*MT6261RF*/ /*..........................................................*/
/*MT6261RF*/
/*MT6261RF*/ #define  HW_VERSION_CODE               ((APBADDR)(VERSION_base+0x0000)) /* HW Version Code */     
/*MT6261RF*/ #define  FACTORY_CODE_TSMC             (0xA)
/*MT6261RF*/ #define  FACTORY_CODE_HLMC             (0xB)
/*MT6261RF*/
/*MT6261RF*/ #define  SCTRL_SLEEP                   SCTRL_WORD(0,30)
/*MT6261RF*/ #define  SCTRL_STANDBY                 SCTRL_WORD(0,30)
/*MT6261RF*/ #define  SCTRL_PLL                     SCTRL_WORD(0,30)
/*MT6261RF*/ #define  SCTRL_AFC                     SCTRL_WORD(0,30)
/*MT6261RF*/ #define  SCTRL_AGC                     SCTRL_WORD(0,30)
/*MT6261RF*/ #define  SCTRL_AGC_VCOM_BIAS           SCTRL_WORD(0,30)
/*MT6261RF*/ #define  SCTRL_AGC_RXDIV               SCTRL_WORD(0,30)
/*MT6261RF*/ #define  SCTRL_RXDIVOBBMODE            SCTRL_WORD(0,30)
/*MT6261RF*/ #define  SCTRL_DFM_FLT_RST             SCTRL_WORD(0,30)
/*MT6261RF*/ #define  SDATA_TXSLEEP                 BSI_CW(   2, 0x08000)            /* CW2  : MODE: Idle  , TRX: TX mode  */
/*MT6261RF*/ #define  SDATA_RFBIST                  BSI_CW(   2, 0x10000)            /* CW2  : MODE: Idle  , TRX: RF BIST  */
/*MT6261RF*/ #define  SDATA_RX2IDLE                 BSI_CW(   2, 0x00000)            /* CW2  : MODE: Idle  , TRX: RX mode  */
/*MT6261RF*/ #define  SDATA_TX2IDLE                 BSI_CW(   2, 0x00000)            /* CW2  : MODE: Idle  , TRX: RX mode  */
/*MT6261RF*/ #define  SDATA_AFC                     BSI_CW(  57, POR_CW57 & 0xFE000) /* CW57 : POR value w/o DFM_XO_CAFC[12:0]  */
/*MT6261RF*/ #define  SDATA_DFM_FLT_RST             BSI_CW( 133, POR_CW133& 0x80000) /* CW133: DFM_FILTER_RESET                 */
/*MT6261RF*/
/*MT6261RF*/ #define  CW2_TRX_MODE_LSB              (15)
/*MT6261RF*/ #define  CW2_TRX_MODE_MASK             (0x3<<CW2_TRX_MODE_LSB)
/*MT6261RF*/ #define  KEEP_CW2_TRXMODE(cw)           (cw&CW2_TRX_MODE_MASK)
/*MT6261RF*/
/*MT6261RF*/ #define SDATA_CW2_BAND_LSB 13
/*MT6261RF*/ const unsigned long  SDATA_BAND_SEL[5] =
/*MT6261RF*/ {  /* TX Band Selection */
/*MT6261RF*/    0                      ,  /* GSM  450 no support */
/*MT6261RF*/    0x0<<SDATA_CW2_BAND_LSB,  /* GSM  850 */
/*MT6261RF*/    0x1<<SDATA_CW2_BAND_LSB,  /* GSM  900 */
/*MT6261RF*/    0x2<<SDATA_CW2_BAND_LSB,  /* DCS 1800 */
/*MT6261RF*/    0x3<<SDATA_CW2_BAND_LSB,  /* PCS 1900 */
/*MT6261RF*/ };
/*MT6261RF*/
/*MT6261RF*/ /* This function is used for SW to query the factory code. */
/*MT6261RF*/ unsigned short L1D_Query_HW_Factory_Code ( void )
/*MT6261RF*/ {
/*MT6261RF*/    unsigned short factory_code;
/*MT6261RF*/    factory_code = (HW_READ(HW_VERSION_CODE)&0x0F00)>>8;
/*MT6261RF*/
/*MT6261RF*/    return factory_code;
/*MT6261RF*/ }
/*MT6261RF*/
/*MT6261RF*/ /*..........................................................*/
/*MT6261RF*/ /* Serial Interface Implement                               */
/*MT6261RF*/ /*..........................................................*/
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_SetSData_SR0( void )
/*MT6261RF*/ {
/*MT6261RF*/    unsigned long cw57;
/*MT6261RF*/    SETUP_SR0();
/*MT6261RF*/
/*MT6261RF*/    /* CW57 : Set AFC , others using POR */
/*MT6261RF*/    cw57 = SDATA_AFC | (L1D_RF_Check_DCXO_LPM()&0x1FFF);
/*MT6261RF*/
/*MT6261RF*/    HWRITE_3_SDATA( SCTRL_SLEEP     , BSI_CW(2,POR_CW2|KEEP_CW2_TRXMODE(l1d_rf.IFN_data)),    /* CW2  : set mode = setting TRX MODE at sleep mode   */
/*MT6261RF*/                    SCTRL_STANDBY   , l1d_rf.IFN_data,                              /* CW2  : set mode = standby    */
/*MT6261RF*/                    SCTRL_AFC       , cw57);                                        /* CW57 : set AFC DAC           */
/*MT6261RF*/ }
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_SetSData_SR1( void )
/*MT6261RF*/ {
/*MT6261RF*/    SETUP_SR1();
/*MT6261RF*/    HWRITE_1_SDATA( SCTRL_PLL,        l1d_rf.RFN_data );  /* CW1  : set PLL, RF will enter warmup state */
/*MT6261RF*/ }
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_SetSData_SR2( void )
/*MT6261RF*/ {
/*MT6261RF*/    unsigned long cw_set[SX2_DATA_COUNT];
/*MT6261RF*/    SETUP_SR2();
/*MT6261RF*/    L1D_RF_SR2_GetGainSetting(l1d_rf.AGC_data ,cw_set);
/*MT6261RF*/    HWRITE_2_SDATA( SCTRL_AGC          ,cw_set[1]  ,                   /* CW98 : set gain          */
/*MT6261RF*/                    SCTRL_AGC_RXDIV    ,cw_set[0] );                   /* CW96 : set gain          */
/*MT6261RF*/ }
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_SetSData_SR3( void )
/*MT6261RF*/ {
/*MT6261RF*/    SETUP_SR3();
/*MT6261RF*/    /* Set CW2:TRX[1:0] as RF BIST mode in the following scenarios. */
/*MT6261RF*/    if( L1D_CheckIfMetaMode() || (L1D_Query_HW_Factory_Code()!=FACTORY_CODE_HLMC) )
/*MT6261RF*/    {  /* RF desinger suggest to keep band setting at Idle mode , to avoid OBB detection issue */
/*MT6261RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_RFBIST  | SDATA_BAND_SEL[l1d_rf.band] );   /* CW2: MODE = idle mode, TRX = RF BIST. */
/*MT6261RF*/    }
/*MT6261RF*/    else
/*MT6261RF*/    {  /* RF desinger suggest to keep band setting at Idle mode , to avoid OBB detection issue */
/*MT6261RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_RX2IDLE | SDATA_BAND_SEL[l1d_rf.band] );   /* CW2: MODE = idle mode, TRX = RX mode. */
/*MT6261RF*/    }
/*MT6261RF*/ }
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_SetSData_ST0( void )
/*MT6261RF*/ {  
/*MT6261RF*/    unsigned long cw57     = SDATA_AFC | (l1d_rf.AFC_data&0x1FFF);
/*MT6261RF*/
/*MT6261RF*/    SETUP_ST0();
/*MT6261RF*/    HWRITE_3_SDATA( SCTRL_SLEEP     , BSI_CW(2,POR_CW2|KEEP_CW2_TRXMODE(l1d_rf.IFN_data)),    /* CW2  : set mode = setting TRX MODE at sleep mode   */
/*MT6261RF*/                    SCTRL_STANDBY   , l1d_rf.IFN_data,                              /* CW2  : set mode = standby    */
/*MT6261RF*/                    SCTRL_AFC       , cw57);                                        /* CW57 : set AFC DAC           */
/*MT6261RF*/ }
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_SetSData_ST1( void )
/*MT6261RF*/ {
/*MT6261RF*/    SETUP_ST1();
/*MT6261RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data );      /* CW1: set PLL, RF will enter warmup state */
/*MT6261RF*/ }
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_SetSData_ST2( void )
/*MT6261RF*/ {
/*MT6261RF*/ }
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_SetSData_ST3( void )
/*MT6261RF*/ {
/*MT6261RF*/    SETUP_ST3();
/*MT6261RF*/    /* Set CW2:TRX[1:0] as RF BIST mode in the following scenarios. */
/*MT6261RF*/    if( L1D_CheckIfMetaMode() || (L1D_Query_HW_Factory_Code()!=FACTORY_CODE_HLMC) )
/*MT6261RF*/    {  /* RF desinger suggest to keep band setting at Idle mode , to avoid OBB detection issue */
/*MT6261RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_RFBIST  | SDATA_BAND_SEL[l1d_rf.band] );  /* CW2: MODE = idle mode, TRX = RF BIST. */
/*MT6261RF*/    }
/*MT6261RF*/    else
/*MT6261RF*/    {  /* RF desinger suggest to keep band setting at Idle mode , to avoid OBB detection issue */
/*MT6261RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_TX2IDLE | SDATA_BAND_SEL[l1d_rf.band] );  /* CW2: MODE = idle mode, TRX = RX mode. */
/*MT6261RF*/    }
/*MT6261RF*/ }
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6261RF*/ {
/*MT6261RF*/    SETUP_ST2B_ST2M();
/*MT6261RF*/    HWRITE_2_SDATA( SCTRL_DFM_FLT_RST  ,   SDATA_DFM_FLT_RST,       /* CW133: enter TX mode and             */
/*MT6261RF*/                    SCTRL_RESERVED     ,   0                   );   /*        DFM compensation filter reset */
/*MT6261RF*/ }
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6261RF*/ {
/*MT6261RF*/ }
/*MT6261RF*/
#endif


#if IS_RF_MT6260RF
/*MT6260RF*/
/*MT6260RF*/ /*..........................................................*/
/*MT6260RF*/ /*  Define Alias                                            */
/*MT6260RF*/ /*..........................................................*/
/*MT6260RF*/
/*MT6260RF*/ #define  SCTRL_STANDBY                 SCTRL_WORD(0,30)
/*MT6260RF*/ #define  SCTRL_PLL                     SCTRL_WORD(0,30)
/*MT6260RF*/ #define  SCTRL_HWTC_DCXO               SCTRL_WORD(0,30)
/*MT6260RF*/ #define  SCTRL_AGC                     SCTRL_WORD(0,30)
/*MT6260RF*/ #define  SCTRL_AGC_LNA_CUR             SCTRL_WORD(0,30)
/*MT6260RF*/ #define  SCTRL_TXCW                    SCTRL_WORD(0,30)
/*MT6260RF*/ #define  SCTRL_OPTIMIZE_HWTC           SCTRL_WORD(0,30)
/*MT6260RF*/ #define  SCTRL_RXDIVOBBMODE            SCTRL_WORD(0,30)
/*MT6260RF*/ #define  SDATA_TXSLEEP                 BSI_CW(0x02, 0x10000)            /* CW2: MODE: sleep , TRX: TX sleep mode    */
/*MT6260RF*/ #define  SDATA_RX2IDLE                 BSI_CW(0x02, 0x00000)            /* CW2: MODE: Idle  , TRX: RX idle mode     */
/*MT6260RF*/ #define  SDATA_TX2IDLE                 BSI_CW(0x02, 0x00000)            /* CW2: MODE: Idle  , TRX: RX idle mode     */
/*MT6260RF*/ #define  SDATA_CW106_OBB_FLAG_ON       BSI_CW(0x6A, 0xF706A)            /* CW106 : RXHBLO_LDO_OBB[3:0]= E RXLBLO_LDO_OBB[3:0]= E */
/*MT6260RF*/ #define  SDATA_CW106_OBB_FLAG_OFF      BSI_CW(0x6A, 0x3A86A)            /* CW106 : RXHBLO_LDO_OBB[3:0]= 7 RXLBLO_LDO_OBB[3:0]= 5 */
/*MT6260RF*/
/*MT6260RF*/ #if IS_BAND_COMP_TC_GAIN_SUPPORT
/*MT6260RF*/ #define  SDATA_RX_HWTC                 BSI_CW(0x39, POR_CW57 & 0xFE000) /* CW57: POR value w/o DFM_XO_CAFC[12:0] */
/*MT6260RF*/ #define  SDATA_TX_HWTC                 L1D_RF_Get_TC_Gain_CW()
/*MT6260RF*/ #else
/*MT6260RF*/ #define  SDATA_RX_HWTC                 BSI_CW(0x39, POR_CW57 & 0xFE000) /* CW57: POR value w/o DFM_XO_CAFC[12:0] */
/*MT6260RF*/ #define  SDATA_TX_HWTC                 (0x1C)                           /* VCO TC Gain defualt value             */
/*MT6260RF*/ #endif
/*MT6260RF*/
/*MT6260RF*/ #define SDATA_CW2_BAND_LSB 13
/*MT6260RF*/ const unsigned long  SDATA_BAND_SEL[5] =
/*MT6260RF*/ {  /* TX Band Selection */
/*MT6260RF*/    0                      ,  /* GSM  450 no support */
/*MT6260RF*/    0x0<<SDATA_CW2_BAND_LSB,  /* GSM  850 */
/*MT6260RF*/    0x1<<SDATA_CW2_BAND_LSB,  /* GSM  900 */
/*MT6260RF*/    0x2<<SDATA_CW2_BAND_LSB,  /* DCS 1800 */
/*MT6260RF*/    0x3<<SDATA_CW2_BAND_LSB,  /* PCS 1900 */
/*MT6260RF*/ };
/*MT6260RF*/ 
/*MT6260RF*/ /*..........................................................*/
/*MT6260RF*/ /* Serial Interface Implement                               */
/*MT6260RF*/ /*..........................................................*/
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_SetSData_SR0( void )
/*MT6260RF*/ {
/*MT6260RF*/    int           l1_obb_flag = 0;
/*MT6260RF*/    unsigned long cw57,cw106;
/*MT6260RF*/    SETUP_SR0();
/*MT6260RF*/
/*MT6260RF*/ #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6260RF*/    if( l1d_rf.band < FrequencyBand1800 )
/*MT6260RF*/    {  l1_obb_flag = (l1d_rf.blk_flag & LB_OBB_FOUND) ? 1 : 0; }
/*MT6260RF*/    else
/*MT6260RF*/    {  l1_obb_flag = (l1d_rf.blk_flag & HB_OBB_FOUND) ? 1 : 0; }
/*MT6260RF*/ #endif
/*MT6260RF*/    /* CW57 : Set AFC and L1_OBB_FLAG , RX mode HWTC not work just use POR vaule*/
/*MT6260RF*/    cw57 = (l1_obb_flag<<19) | SDATA_RX_HWTC | (L1D_RF_Check_DCXO_LPM()&0x1FFF);
/*MT6260RF*/    cw106= (l1_obb_flag == 1)? SDATA_CW106_OBB_FLAG_ON : SDATA_CW106_OBB_FLAG_OFF;
/*MT6260RF*/
/*MT6260RF*/    HWRITE_3_SDATA( SCTRL_STANDBY     , l1d_rf.IFN_data,    /* CW2  : set mode = standby    */
/*MT6260RF*/                    SCTRL_HWTC_DCXO   , cw57,               /* CW57 : set AFC DAC           */
/*MT6260RF*/                    SCTRL_RXDIVOBBMODE, cw106 );            /* CW106: set RX DIV OBB MODE   */
/*MT6260RF*/ }
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_SetSData_SR1( void )
/*MT6260RF*/ {
/*MT6260RF*/    SETUP_SR1();
/*MT6260RF*/    HWRITE_1_SDATA( SCTRL_PLL,        l1d_rf.RFN_data );  /* CW1  : set PLL, RF will enter warmup state */
/*MT6260RF*/ }
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_SetSData_SR2( void )
/*MT6260RF*/ {
/*MT6260RF*/    unsigned long cw96 = (l1d_rf.AGC_data & 0xFFFFFFCL);    /*Exclude 2 LSB, used to be indicator   */ 
/*MT6260RF*/    unsigned long cw101= (l1d_rf.AGC_data & 0x00000FCL);    /*Note, It has been shift 2bits         */
/*MT6260RF*/    SETUP_SR2();
/*MT6260RF*/	cw101 = BSI_CW(0x65,(cw101<<12)|(cw101<<6)|(cw101));	/*Copy current value to all current reg */
/*MT6260RF*/
/*MT6260RF*/    HWRITE_2_SDATA( SCTRL_AGC        ,cw96  ,               /* CW96 : set gain          */
/*MT6260RF*/                    SCTRL_AGC_LNA_CUR,cw101 );              /* CW101: set lna current   */
/*MT6260RF*/ }
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_SetSData_SR3( void )
/*MT6260RF*/ {
/*MT6260RF*/    SETUP_SR3();
/*MT6260RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF 
/*MT6260RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6260RF*/    {  /* RF desinger suggest to keep band setting at Idle mode , to avoid OBB detection issue */
/*MT6260RF*/       HWRITE_1_SDATA( SCTRL_STANDBY, (l1d_rf.IFN_data&0x7FFF) | SDATA_BAND_SEL[l1d_rf.band] | SDATA_TXSLEEP ); /* CW2: set mode = TX sleep mode */
/*MT6260RF*/    }
/*MT6260RF*/    else
/*MT6260RF*/    #endif
/*MT6260RF*/    {  /* RF desinger suggest to keep band setting at Idle mode , to avoid OBB detection issue */
/*MT6260RF*/       HWRITE_1_SDATA( SCTRL_IDLE,    SDATA_RX2IDLE | SDATA_BAND_SEL[l1d_rf.band]);       /* CW2: set mode = sleep mode */
/*MT6260RF*/    }
/*MT6260RF*/ }
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_SetSData_ST0( void )
/*MT6260RF*/ {  
/*MT6260RF*/    unsigned long tc_gain  = SDATA_TX_HWTC;
/*MT6260RF*/    unsigned long cw4      = BSI_CW(0x04, POR_CW4 ) | (( tc_gain & 0x40) >> 6 );
/*MT6260RF*/    unsigned long cw57     = BSI_CW(0x39, (POR_CW57&0x80000)) | ((tc_gain&0x3F)<<13) | (l1d_rf.AFC_data&0x1FFF);
/*MT6260RF*/
/*MT6260RF*/    SETUP_ST0();
/*MT6260RF*/    HWRITE_3_SDATA( SCTRL_STANDBY,        l1d_rf.IFN_data,   /* CW2  : set mode = standby */
/*MT6260RF*/                    SCTRL_HWTC_DCXO,      cw57,              /* CW57 : set VCO TC gain and AFC DAC */
/*MT6260RF*/                    SCTRL_OPTIMIZE_HWTC,  cw4 );             /* CW4  : optimize performance by band and VCO TC*/
/*MT6260RF*/ }
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_SetSData_ST1( void )
/*MT6260RF*/ {
/*MT6260RF*/    SETUP_ST1();
/*MT6260RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data ); /* CW1: set PLL, RF will enter warmup state */
/*MT6260RF*/ }
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_SetSData_ST2( void )
/*MT6260RF*/ {
/*MT6260RF*/ }
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_SetSData_ST3( void )
/*MT6260RF*/ {
/*MT6260RF*/    SETUP_ST3();
/*MT6260RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6260RF*/    if( l1d_rf2.dedicated_flag & SC_DEDICATED_2TX )
/*MT6260RF*/    {  /* RF desinger suggest to keep band setting at Idle mode , to avoid OBB detection issue */
/*MT6260RF*/       HWRITE_1_SDATA( SCTRL_STANDBY, (l1d_rf.IFN_data&0x7FFF) | SDATA_BAND_SEL[l1d_rf.band] | SDATA_TXSLEEP ); /* CW2: set mode = TX leep mode */
/*MT6260RF*/    }
/*MT6260RF*/    else
/*MT6260RF*/    #elif IS_RF_VCO_DOO_OFF
/*MT6260RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6260RF*/    {  /* RF desinger suggest to keep band setting at Idle mode , to avoid OBB detection issue */
/*MT6260RF*/       HWRITE_1_SDATA( SCTRL_STANDBY, (l1d_rf.IFN_data&0x7FFF) | SDATA_BAND_SEL[l1d_rf.band] | SDATA_TXSLEEP ); /* CW2: set mode = TX sleep mode */
/*MT6260RF*/    }
/*MT6260RF*/    else
/*MT6260RF*/    #endif
/*MT6260RF*/    {  /* RF desinger suggest to keep band setting at Idle mode , to avoid OBB detection issue */
/*MT6260RF*/       HWRITE_1_SDATA( SCTRL_IDLE,    SDATA_TX2IDLE | SDATA_BAND_SEL[l1d_rf.band] );            /* CW2: set mode = sleep mode */
/*MT6260RF*/    }
/*MT6260RF*/ }
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6260RF*/ {
/*MT6260RF*/    SETUP_ST2B_ST2M();
/*MT6260RF*/    HWRITE_2_SDATA( SCTRL_TXCW,       BSI_CW(0x85, POR_CW133), /* CW133: enter TX mode and             */
/*MT6260RF*/                    SCTRL_RESERVED,   0 );                     /*        DFM compensation filter reset */
/*MT6260RF*/ }
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6260RF*/ {
/*MT6260RF*/ }
/*MT6260RF*/
#endif

#if IS_RF_MT6250RF
/*MT6250RF*/
/*MT6250RF*/ /*..........................................................*/
/*MT6250RF*/ /*  Define Alias                                            */
/*MT6250RF*/ /*..........................................................*/
/*MT6250RF*/
/*MT6250RF*/ #define  SCTRL_STANDBY                 SCTRL_WORD(0,30)
/*MT6250RF*/ #define  SCTRL_PLL                     SCTRL_WORD(0,30)
/*MT6250RF*/ #define  SCTRL_HWTC_DCXO               SCTRL_WORD(0,30)
/*MT6250RF*/ #define  SCTRL_AGC                     SCTRL_WORD(0,30)
/*MT6250RF*/ #define  SCTRL_TXCW                    SCTRL_WORD(0,30)
/*MT6250RF*/ #define  SCTRL_CW4                     SCTRL_WORD(0,30)
/*MT6250RF*/ #define  SDATA_TXSLEEP                 BSI_CW(0x02, 0x10000)            /* CW2: MODE: sleep, TRX: TX sleep mode */
/*MT6250RF*/
/*MT6250RF*/ #if IS_BAND_COMP_TC_GAIN_SUPPORT
/*MT6250RF*/ #define  SDATA_RX_HWTC                 BSI_CW(0x39, POR_CW57 & 0xFE000) /* CW57: POR value w/o DFM_XO_CAFC[12:0] */
/*MT6250RF*/ #define  SDATA_TX_HWTC                 L1D_RF_Get_TC_Gain_CW()
/*MT6250RF*/ #else
/*MT6250RF*/ #define  SDATA_RX_HWTC                 BSI_CW(0x39, POR_CW57 & 0xFE000) /* CW57: POR value w/o DFM_XO_CAFC[12:0] */
/*MT6250RF*/ #define  SDATA_TX_HWTC                 SDATA_RX_HWTC
/*MT6250RF*/ #endif
/*MT6250RF*/
/*MT6250RF*/ /*..........................................................*/
/*MT6250RF*/ /* Serial Interface Implement                               */
/*MT6250RF*/ /*..........................................................*/
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_SetSData_SR0( void )
/*MT6250RF*/ {
/*MT6250RF*/    int           l1_obb_flag = 0;
/*MT6250RF*/    unsigned long cw57;
/*MT6250RF*/    SETUP_SR0();
/*MT6250RF*/
/*MT6250RF*/ #if IS_OUTBAND_BLOCKER_DETECTION_SUPPORT
/*MT6250RF*/    if( l1d_rf.band < FrequencyBand1800 )
/*MT6250RF*/    {  l1_obb_flag = (l1d_rf.blk_flag & LB_OBB_FOUND) ? 1 : 0; }
/*MT6250RF*/    else
/*MT6250RF*/    {  l1_obb_flag = (l1d_rf.blk_flag & HB_OBB_FOUND) ? 1 : 0; }
/*MT6250RF*/ #endif
/*MT6250RF*/
/*MT6250RF*/    cw57 = (l1_obb_flag<<19) | SDATA_RX_HWTC | (L1D_RF_Check_DCXO_LPM()&0x1FFF);
/*MT6250RF*/
/*MT6250RF*/    HWRITE_3_SDATA( SCTRL_STANDBY,    l1d_rf.IFN_data,    /* CW2: set mode = standby */
/*MT6250RF*/                    SCTRL_HWTC_DCXO,  cw57,               /* CW57: set AFC DAC */ 
/*MT6250RF*/                    SCTRL_RESERVED,   0 );                /* to prevent from missending */
/*MT6250RF*/ }
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_SetSData_SR1( void )
/*MT6250RF*/ {
/*MT6250RF*/    SETUP_SR1();
/*MT6250RF*/    HWRITE_1_SDATA( SCTRL_PLL,        l1d_rf.RFN_data );  /* CW1: set PLL, RF will enter warmup state */
/*MT6250RF*/ }
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_SetSData_SR2( void )
/*MT6250RF*/ {
/*MT6250RF*/    unsigned long cw96 = (l1d_rf.AGC_data & 0xFFFFFFFL);
/*MT6250RF*/    SETUP_SR2();
/*MT6250RF*/    HWRITE_2_SDATA( SCTRL_AGC,        cw96,               /* CW96: set gain */
/*MT6250RF*/                    SCTRL_RESERVED,   0 );
/*MT6250RF*/ }
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_SetSData_SR3( void )
/*MT6250RF*/ {
/*MT6250RF*/    SETUP_SR3();
/*MT6250RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF
/*MT6250RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6250RF*/    {
/*MT6250RF*/       HWRITE_1_SDATA( SCTRL_STANDBY, (l1d_rf.IFN_data&0x7FFF) | SDATA_TXSLEEP ); /* CW2: set mode = TX sleep mode */
/*MT6250RF*/    }
/*MT6250RF*/    else
/*MT6250RF*/    #endif
/*MT6250RF*/    {
/*MT6250RF*/       HWRITE_1_SDATA( SCTRL_IDLE,    SDATA_IDLE);       /* CW2: set mode = sleep mode */
/*MT6250RF*/    }
/*MT6250RF*/ }
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_SetSData_ST0( void )
/*MT6250RF*/ {
/*MT6250RF*/    unsigned long cw4  = BSI_CW(0x04, POR_CW4 );
/*MT6250RF*/    unsigned long cw57 = SDATA_TX_HWTC | (l1d_rf.AFC_data&0x1FFF);
/*MT6250RF*/    SETUP_ST0();
/*MT6250RF*/    HWRITE_3_SDATA( SCTRL_STANDBY,    l1d_rf.IFN_data,   /* CW2  : set mode = standby */
/*MT6250RF*/                    SCTRL_HWTC_DCXO,  cw57,              /* CW57 : set VCO TC gain and AFC DAC */
/*MT6250RF*/                    SCTRL_CW4,        cw4 );             /* CW4  : optimize performance by band */
/*MT6250RF*/ }
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_SetSData_ST1( void )
/*MT6250RF*/ {
/*MT6250RF*/    SETUP_ST1();
/*MT6250RF*/    HWRITE_1_SDATA( SCTRL_PLL,        l1d_rf.RFN_data ); /* CW1: set PLL, RF will enter warmup state */
/*MT6250RF*/ }
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_SetSData_ST2( void )
/*MT6250RF*/ {
/*MT6250RF*/ }
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_SetSData_ST3( void )
/*MT6250RF*/ {
/*MT6250RF*/    SETUP_ST3();
/*MT6250RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6250RF*/    if( l1d_rf2.dedicated_flag & SC_DEDICATED_2TX )
/*MT6250RF*/    {
/*MT6250RF*/       HWRITE_1_SDATA( SCTRL_STANDBY, (l1d_rf.IFN_data&0x7FFF) | SDATA_TXSLEEP ); /* CW2: set mode = TX leep mode */
/*MT6250RF*/    }
/*MT6250RF*/    else
/*MT6250RF*/    #elif IS_RF_VCO_DOO_OFF
/*MT6250RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6250RF*/    {
/*MT6250RF*/       HWRITE_1_SDATA( SCTRL_STANDBY, (l1d_rf.IFN_data&0x7FFF) | SDATA_TXSLEEP ); /* CW2: set mode = TX sleep mode */
/*MT6250RF*/    }
/*MT6250RF*/    else
/*MT6250RF*/    #endif
/*MT6250RF*/    {
/*MT6250RF*/       HWRITE_1_SDATA( SCTRL_IDLE,    SDATA_IDLE );            /* CW2: set mode = sleep mode */
/*MT6250RF*/    }
/*MT6250RF*/ }
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6250RF*/ {
/*MT6250RF*/    SETUP_ST2B_ST2M();
/*MT6250RF*/    HWRITE_2_SDATA( SCTRL_TXCW,       BSI_CW(0x85, POR_CW133), /* CW133: enter TX mode and             */
/*MT6250RF*/                    SCTRL_RESERVED,   0 );                     /*        DFM compensation filter reset */
/*MT6250RF*/ }
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6250RF*/ {
/*MT6250RF*/ }
/*MT6250RF*/
#endif

#if IS_RF_MT6256RF
/*MT6256RF*/
/*MT6256RF*/ /*..........................................................*/
/*MT6256RF*/ /*  Define Alias and Table                                  */
/*MT6256RF*/ /*..........................................................*/
/*MT6256RF*/
/*MT6256RF*/ #define  SCTRL_STANDBY                 SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SCTRL_WARM                    SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SCTRL_PLL                     SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SCTRL_DCXO                    SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SCTRL_AGC                     SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SCTRL_TXCW                    SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SCTRL_RXCW                    SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SDATA_SLEEP                   BSI_CW(0x02, 0x10000)
/*MT6256RF*/ #define  SDATA_STANDBY                 BSI_CW(0x02, 0x44000)
/*MT6256RF*/
/*MT6256RF*/    #if IS_BAND_COMP_TC_GAIN_SUPPORT
/*MT6256RF*/ #define  SCTRL_HWTC                    SCTRL_WORD(0,29)
/*MT6256RF*/ #define  SDATA_HWTC                    L1D_RF_Get_TC_Gain_CW()
/*MT6256RF*/    #else
/*MT6256RF*/ #define  SCTRL_HWTC                    SCTRL_RESERVED
/*MT6256RF*/ #define  SDATA_HWTC                    0
/*MT6256RF*/    #endif
/*MT6256RF*/
/*MT6256RF*/ /*..........................................................*/
/*MT6256RF*/ /* Serial Interface Implement                               */
/*MT6256RF*/ /*..........................................................*/
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_SR0( void )
/*MT6256RF*/ {
/*MT6256RF*/    unsigned long cw98;
/*MT6256RF*/    SETUP_SR0();
/*MT6256RF*/    #if IS_CHIP_MT6256_S00
/*MT6256RF*/    cw98 = l1d_rf.band < FrequencyBand1800 ? BSI_CW(0x62, 0xF6E4A) : BSI_CW(0x62, 0x1165A);
/*MT6256RF*/    #else
/*MT6256RF*/    cw98 = l1d_rf.band < FrequencyBand1800 ? BSI_CW(0x62, 0x11852) : BSI_CW(0x62, 0x11452);
/*MT6256RF*/    #endif
/*MT6256RF*/    HWRITE_3_SDATA( SCTRL_STANDBY,  l1d_rf.IFN_data,                       /* CW2: set mode = standby */
/*MT6256RF*/                    SCTRL_DCXO,     BSI_CW(0x39, l1d_rf.AFC_data&0x1FFF),  /* CW57: set AFC DAC */
/*MT6256RF*/                    SCTRL_RXCW,     cw98            );                     /* CW98: for RX LNA bias current */
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_SR1( void )
/*MT6256RF*/ {
/*MT6256RF*/    SETUP_SR1();
/*MT6256RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data );  /* CW1: set PLL, RF will enter warmup state */
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_SR2( void )
/*MT6256RF*/ {
/*MT6256RF*/    SETUP_SR2();
/*MT6256RF*/    #if IS_CHIP_MT6256_S00
/*MT6256RF*/    HWRITE_1_SDATA( SCTRL_AGC,      l1d_rf.AGC_data );  /* CW96: set gain */
/*MT6256RF*/    #else
/*MT6256RF*/    HWRITE_2_SDATA( SCTRL_AGC,      l1d_rf.AGC_data,    /* CW96: set gain */
/*MT6256RF*/                    SCTRL_RESERVED, 0               );
/*MT6256RF*/    #endif
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_SR3( void )
/*MT6256RF*/ {
/*MT6256RF*/    SETUP_SR3();
/*MT6256RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF
/*MT6256RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6256RF*/    {
/*MT6256RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );  /* CW2: set mode = stand-by mode */
/*MT6256RF*/    }
/*MT6256RF*/    else
/*MT6256RF*/    #endif
/*MT6256RF*/    {
/*MT6256RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );                      /* CW2: set mode = sleep mode */
/*MT6256RF*/    }
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_ST0( void )
/*MT6256RF*/ {
/*MT6256RF*/    #if IS_CHIP_MT6256_S00
/*MT6256RF*/    SETUP_ST0();
/*MT6256RF*/
/*MT6256RF*/    HWRITE_3_SDATA( SCTRL_STANDBY,  l1d_rf.IFN_data,                         /* CW2: set mode = standby */
/*MT6256RF*/                    SCTRL_DCXO,     BSI_CW(0x39, l1d_rf.AFC_data&0x1FFF),    /* CW57: set AFC DAC */
/*MT6256RF*/                    SCTRL_RESERVED, 0                                     );
/*MT6256RF*/    #else
/*MT6256RF*/    unsigned long cw2  = l1d_rf.IFN_data;
/*MT6256RF*/    SETUP_ST0();
/*MT6256RF*/
/*MT6256RF*/    if( (l1d_rf.RFN_data&0x3FF) || (l1d_rf.IFN_data&0x1FFF) )
/*MT6256RF*/    { /*Do nothing*/ }
/*MT6256RF*/    else
/*MT6256RF*/    {  cw2 |= (0x1<<6);  }
/*MT6256RF*/    
/*MT6256RF*/    HWRITE_3_SDATA( SCTRL_HWTC,    SDATA_HWTC,                             /* CW63: set TC gain for freq. error compensation */
/*MT6256RF*/                    SCTRL_STANDBY, cw2,                                    /* CW2: set mode = standby */
/*MT6256RF*/                    SCTRL_DCXO,    BSI_CW(0x39, l1d_rf.AFC_data&0x1FFF) ); /* CW57: set AFC DAC */
/*MT6256RF*/    #endif
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_ST1( void )
/*MT6256RF*/ {
/*MT6256RF*/    SETUP_ST1();
/*MT6256RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data );  /* CW1: set PLL, RF will enter warmup state */
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_ST2( void )
/*MT6256RF*/ {
/*MT6256RF*/    SETUP_ST2();
/*MT6256RF*/    #if IS_CHIP_MT6256_S00
/*MT6256RF*/    HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6256RF*/    #else
/*MT6256RF*/    HWRITE_2_SDATA( SCTRL_RESERVED, 0,
/*MT6256RF*/                    SCTRL_RESERVED, 0 );
/*MT6256RF*/    #endif
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_ST3( void )
/*MT6256RF*/ {
/*MT6256RF*/    SETUP_ST3();
/*MT6256RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6256RF*/    if( l1d_rf2.dedicated_flag & SC_DEDICATED_2TX )
/*MT6256RF*/    {
/*MT6256RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );  /* CW2: set mode = stand-by mode */
/*MT6256RF*/    }
/*MT6256RF*/    else
/*MT6256RF*/    #elif IS_RF_VCO_DOO_OFF
/*MT6256RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6256RF*/    {
/*MT6256RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );  /* CW2: set mode = stand-by mode */
/*MT6256RF*/    }
/*MT6256RF*/    else
/*MT6256RF*/    #endif
/*MT6256RF*/    {
/*MT6256RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );                      /* CW2: set mode = sleep mode */
/*MT6256RF*/    }
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6256RF*/ {
/*MT6256RF*/    #if IS_CHIP_MT6256_S00
/*MT6256RF*/    unsigned long cw133;
/*MT6256RF*/    SETUP_ST2B_ST2M();
/*MT6256RF*/    cw133 = L1D_RF_GetSData_ST2();
/*MT6256RF*/    HWRITE_1_SDATA( SCTRL_TXCW,  cw133 );  /* CW133: set TX gain */
/*MT6256RF*/    #else
/*MT6256RF*/    unsigned long cw133;
/*MT6256RF*/    SETUP_ST2B_ST2M();
/*MT6256RF*/    cw133 = L1D_RF_GetSData_ST2();
/*MT6256RF*/    if( (l1d_rf.RFN_data&0x3FF) || (l1d_rf.IFN_data&0x1FFF) )
/*MT6256RF*/    {  HWRITE_2_SDATA( SCTRL_TXCW,     cw133,    /* CW133: set TX gain */
/*MT6256RF*/                       SCTRL_RESERVED, 0     );
/*MT6256RF*/    }
/*MT6256RF*/    else
/*MT6256RF*/    {  HWRITE_2_SDATA( SCTRL_TXCW, cw133,                                         /* CW133: set TX gain */
/*MT6256RF*/                       SCTRL_WARM, (l1d_rf.IFN_data & ~(0x7<<13)) | (0x4<<13) );  /* CW2: Restore NFrac, set mode = warm-up mode for int channel */
/*MT6256RF*/    }
/*MT6256RF*/    #endif
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6256RF*/ {
/*MT6256RF*/    #if IS_CHIP_MT6256_S00
/*MT6256RF*/    unsigned long cw133;
/*MT6256RF*/    SETUP_ST2B_ST2M();
/*MT6256RF*/    cw133 = L1D_RF_GetSData_ST2();
/*MT6256RF*/    HWRITE_1_SDATA( SCTRL_TXCW,  cw133 );  /* CW133: set TX gain */
/*MT6256RF*/    #else
/*MT6256RF*/    unsigned long cw133;
/*MT6256RF*/    SETUP_ST2B_ST2M();
/*MT6256RF*/    cw133 = L1D_RF_GetSData_ST2();
/*MT6256RF*/    HWRITE_2_SDATA( SCTRL_TXCW,     cw133,   /* CW133: set TX gain */
/*MT6256RF*/                    SCTRL_RESERVED, 0     );
/*MT6256RF*/    #endif
/*MT6256RF*/ }
/*MT6256RF*/
#endif

#if IS_RF_MT6255RF
/*MT6255RF*/
/*MT6255RF*/ /*..........................................................*/
/*MT6255RF*/ /*  Define Alias and Table                                  */
/*MT6255RF*/ /*..........................................................*/
/*MT6255RF*/
/*MT6255RF*/ #define  SCTRL_STANDBY                 SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SCTRL_WARM                    SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SCTRL_PLL                     SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SCTRL_DCXO                    SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SCTRL_AGC                     SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SCTRL_TXCW                    SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SCTRL_RXCW                    SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SDATA_SLEEP                   BSI_CW(0x02, 0x10000)
/*MT6255RF*/ #define  SDATA_STANDBY                 BSI_CW(0x02, 0x44000)
/*MT6255RF*/
/*MT6255RF*/ #if IS_BAND_COMP_TC_GAIN_SUPPORT
/*MT6255RF*/ #define  SCTRL_HWTC                    SCTRL_WORD(0,29)
/*MT6255RF*/ #define  SDATA_HWTC                    L1D_RF_Get_TC_Gain_CW()
/*MT6255RF*/ #else
/*MT6255RF*/ #define  SCTRL_HWTC                    SCTRL_RESERVED
/*MT6255RF*/ #define  SDATA_HWTC                    0
/*MT6255RF*/ #endif
/*MT6255RF*/
/*MT6255RF*/ /*..........................................................*/
/*MT6255RF*/ /* Serial Interface Implement                               */
/*MT6255RF*/ /*..........................................................*/
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_SR0( void )
/*MT6255RF*/ {
/*MT6255RF*/    unsigned long cw57, cw98;
/*MT6255RF*/    SETUP_SR0();
/*MT6255RF*/    cw57 = BSI_CW( 0x39, (L1D_RF_Check_DCXO_LPM()&0x1FFF) );
/*MT6255RF*/    cw98 = l1d_rf.band < FrequencyBand1800 ? BSI_CW(0x62, 0x5067A) : BSI_CW(0x62, 0x50662);
/*MT6255RF*/
/*MT6255RF*/    HWRITE_3_SDATA( SCTRL_RXCW,     cw98,                 /* CW98: for RX LNA bias current */
/*MT6255RF*/                    SCTRL_STANDBY,  l1d_rf.IFN_data,      /* CW2:  set mode = standby */
/*MT6255RF*/                    SCTRL_DCXO,     cw57 );               /* CW57: set AFC DAC */
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_SR1( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_SR1();
/*MT6255RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data );  /* CW1: set PLL, RF will enter warmup state */
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_SR2( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_SR2();
/*MT6255RF*/    HWRITE_2_SDATA( SCTRL_AGC,      l1d_rf.AGC_data,    /* CW96: set gain */
/*MT6255RF*/                    SCTRL_RESERVED, 0               );
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_SR3( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_SR3();
/*MT6255RF*/
/*MT6255RF*/ #if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF
/*MT6255RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6255RF*/    {
/*MT6255RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );  /* CW2: set mode = stand-by mode */
/*MT6255RF*/    }
/*MT6255RF*/    else
/*MT6255RF*/ #endif
/*MT6255RF*/    {
/*MT6255RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );                      /* CW2: set mode = sleep mode */
/*MT6255RF*/    }
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_ST0( void )
/*MT6255RF*/ {
/*MT6255RF*/    unsigned long cw2  = l1d_rf.IFN_data;
/*MT6255RF*/
/*MT6255RF*/    SETUP_ST0();
/*MT6255RF*/
/*MT6255RF*/    if( (l1d_rf.RFN_data&0x3FF) || (l1d_rf.IFN_data&0x1FFF) )
/*MT6255RF*/    {  /*Do nothing*/  }
/*MT6255RF*/    else
/*MT6255RF*/    {  cw2 |= (0x1<<7);  }
/*MT6255RF*/
/*MT6255RF*/    HWRITE_3_SDATA( SCTRL_HWTC,    SDATA_HWTC,                             /* CW63: set TC gain for freq. error compensation */
/*MT6255RF*/                    SCTRL_STANDBY, cw2,                                    /* CW2:  set mode = standby */
/*MT6255RF*/                    SCTRL_DCXO,    BSI_CW(0x39, l1d_rf.AFC_data&0x1FFF) ); /* CW57: set AFC DAC */
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_ST1( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_ST1();
/*MT6255RF*/    HWRITE_1_SDATA( SCTRL_PLL,     l1d_rf.RFN_data );                      /* CW1: set PLL, RF will enter warmup state */
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_ST2( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_ST2();
/*MT6255RF*/    HWRITE_2_SDATA( SCTRL_RESERVED, 0,
/*MT6255RF*/                    SCTRL_RESERVED, 0 );
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_ST3( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_ST3();
/*MT6255RF*/
/*MT6255RF*/ #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6255RF*/    if( l1d_rf2.dedicated_flag & SC_DEDICATED_2TX )
/*MT6255RF*/    {
/*MT6255RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );      /* CW2: set mode = stand-by mode */
/*MT6255RF*/    }
/*MT6255RF*/    else
/*MT6255RF*/ #elif IS_RF_VCO_DOO_OFF
/*MT6255RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6255RF*/    {
/*MT6255RF*/       HWRITE_1_SDATA( SCTRL_IDLE, l1d_rf.IFN_data | SDATA_STANDBY );      /* CW2: set mode = stand-by mode */
/*MT6255RF*/    }
/*MT6255RF*/    else
/*MT6255RF*/ #endif
/*MT6255RF*/    {
/*MT6255RF*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );                          /* CW2: set mode = sleep mode */
/*MT6255RF*/    }
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6255RF*/ {
/*MT6255RF*/    SETUP_ST2B_ST2M();
/*MT6255RF*/
/*MT6255RF*/    if( (l1d_rf.RFN_data&0x3FF) || (l1d_rf.IFN_data&0x1FFF) )
/*MT6255RF*/    {  HWRITE_2_SDATA( SCTRL_TXCW,     BSI_CW(0x85, 0x00003),              /* CW133: Trigger RF to enter TX mode */
/*MT6255RF*/                       SCTRL_RESERVED, 0     );
/*MT6255RF*/    }
/*MT6255RF*/    else
/*MT6255RF*/    {  HWRITE_2_SDATA( SCTRL_TXCW,     BSI_CW(0x85, 0x00003),              /* CW133: Trigger RF to enter TX mode */
/*MT6255RF*/                       SCTRL_WARM,     (l1d_rf.IFN_data & ~(0x7<<13)) | (0x4<<13) );  /* CW2: Restore NFrac, set mode = Tx mode for int channel */
/*MT6255RF*/    }
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6255RF*/ {
/*MT6255RF*/ }
/*MT6255RF*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

#if IS_RF_MT6251RF
/*MT6251RF*/
/*MT6251RF*/ /*..........................................................*/
/*MT6251RF*/ /*  Define Alias and Table                                  */
/*MT6251RF*/ /*..........................................................*/
/*MT6251RF*/
/*MT6251RF*/ #define  SCTRL_STANDBY                 SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_WARM                    SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_PLL                     SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_DCXO                    SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_AGC                     SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_TXBAND                  SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_TXCW                    SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_TXDCOC                  SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_CAPID                   SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_RFVCO_K                 SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SDATA_SLEEP                   0x0210000L
/*MT6251RF*/ #define  SDATA_STANDBY                 0x0244000L
/*MT6251RF*/ #define  SDATA_SLIGHT_STANDBY          0x0284000L
/*MT6251RF*/
/*MT6251RF*/ #if IS_RF_TX_SLEEP_MODE_SUPPORT
/*MT6251RF*/ #undef   SDATA_STANDBY
/*MT6251RF*/ #define  SDATA_STANDBY                 SDATA_SLIGHT_STANDBY
/*MT6251RF*/ #endif
/*MT6251RF*/
/*MT6251RF*/ #define  SCTRL_CW66                    SCTRL_WORD(0,29)
/*MT6251RF*/ #define  SCTRL_CW27                    SCTRL_RESERVED
/*MT6251RF*/
/*MT6251RF*/ /*..........................................................*/
/*MT6251RF*/ /* Serial Interface Implement                               */
/*MT6251RF*/ /*..........................................................*/
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_SR0( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_SR0();
/*MT6251RF*/    HWRITE_2_SDATA( SCTRL_STANDBY,  l1d_rf.IFN_data,                             /* CW2:  set mode = stan*/
/*MT6251RF*/                    SCTRL_DCXO,    (l1d_rf.AFC_data & 0x1FFF) | (0x3900000L) );  /* CW57: set AFC DAC */
/*MT6251RF*/
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_SR1( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_SR1();
/*MT6251RF*/    HWRITE_1_SDATA( SCTRL_PLL,      l1d_rf.RFN_data );  /* CW1: set PLL, RF will enter warmup state */
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_SR2( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_SR2();
/*MT6251RF*/    HWRITE_1_SDATA( SCTRL_AGC,      l1d_rf.AGC_data );  /* CW96: set gain and enter RX mode */
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_SR3( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_SR3();
/*MT6251RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON || IS_RF_VCO_DOO_OFF
/*MT6251RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6251RF*/    {
/*MT6251RF*/       HWRITE_2_SDATA( SCTRL_IDLE, SDATA_SLEEP, 
/*MT6251RF*/                       SCTRL_IDLE, ( l1d_rf.IFN_data & ~(0x00CE000L) ) | SDATA_STANDBY );   /* CW2: set mode = stand-by mode */
/*MT6251RF*/    }
/*MT6251RF*/    else
/*MT6251RF*/    #endif
/*MT6251RF*/    {
/*MT6251RF*/       HWRITE_2_SDATA( SCTRL_IDLE, SDATA_SLEEP,
/*MT6251RF*/                       SCTRL_RESERVED, 0 );   /* CW2: set mode = sleep mode */
/*MT6251RF*/    }
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_ST0( void )
/*MT6251RF*/ {
/*MT6251RF*/    unsigned long cw2 = l1d_rf.IFN_data;
/*MT6251RF*/
/*MT6251RF*/    SETUP_ST0();
/*MT6251RF*/
/*MT6251RF*/    if( (l1d_rf.RFN_data&0x3FF) || (l1d_rf.IFN_data&0xFFF) )
/*MT6251RF*/    {  /*None*/   }  /* The same as in SDATA_TABLE2 */
/*MT6251RF*/    else
/*MT6251RF*/    {  cw2 |= (1<<6);   }  /* If Nfrac[22:0]==0 */
/*MT6251RF*/
/*MT6251RF*/    HWRITE_2_SDATA( SCTRL_STANDBY, cw2,                                        /* CW2:  set mode = standby */
/*MT6251RF*/                    SCTRL_DCXO, (l1d_rf.AFC_data & 0x1FFF) | (0x3900000L) );   /* CW57: set AFC DAC */
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_ST1( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_ST1();
/*MT6251RF*/    HWRITE_1_SDATA( SCTRL_PLL, l1d_rf.RFN_data );  /* CW1: set PLL, RF will enter warmup state */
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_ST2( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_ST2();
   #if IS_CHIP_MT6251_S00
/*MT6251RF*/    HWRITE_1_SDATA( SCTRL_TXCW, 0x8500000L );
   #else
/*MT6251RF*/    HWRITE_1_SDATA( SCTRL_TXCW, 0x8580000L );   /*send CW133 to enter TX mode,[101231] 0x8580000*/
   #endif
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_ST3( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_ST3();
/*MT6251RF*/    #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6251RF*/    if( l1d_rf2.dedicated_flag & SC_DEDICATED_2TX )
/*MT6251RF*/    {
/*MT6251RF*/       HWRITE_2_SDATA( SCTRL_IDLE, ( l1d_rf.IFN_data & ~(0x00CE000L) ) | SDATA_STANDBY,
/*MT6251RF*/                       SCTRL_RESERVED, 0 );   /* CW2: set mode = stand-by mode */
/*MT6251RF*/    }
/*MT6251RF*/    else
/*MT6251RF*/    #elif IS_RF_VCO_DOO_OFF
/*MT6251RF*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6251RF*/    {
/*MT6251RF*/       HWRITE_2_SDATA( SCTRL_IDLE, ( l1d_rf.IFN_data & ~(0x00CE000L) ) | SDATA_STANDBY,
/*MT6251RF*/                       SCTRL_RESERVED, 0 );   /* CW2: set mode = stand-by mode */
/*MT6251RF*/    }
/*MT6251RF*/    else
/*MT6251RF*/    #endif
/*MT6251RF*/    {
/*MT6251RF*/       HWRITE_2_SDATA( SCTRL_IDLE, SDATA_SLEEP,
/*MT6251RF*/                       SCTRL_RESERVED, 0 );   /* CW2: set mode = sleep mode */
/*MT6251RF*/    }
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6251RF*/ {
/*MT6251RF*/    SETUP_ST2B_ST2M();
/*MT6251RF*/    if( (l1d_rf.RFN_data&0x3FF) || (l1d_rf.IFN_data&0xFFF) )
/*MT6251RF*/    {  HWRITE_1_SDATA( SCTRL_RESERVED, 0 );  }
/*MT6251RF*/    else
/*MT6251RF*/    {  HWRITE_1_SDATA( SCTRL_TXCW, (l1d_rf.IFN_data & ~(0x7<<13)) | (0x4<<13) );  }  /* If Nfrac[22:0]==0 */
/*MT6251RF*/
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6251RF*/ {
/*MT6251RF*/ }
/*MT6251RF*/
#endif

#if IS_RF_SKY74045
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
/*SKY74045*/ #if IS_BSI_SX0_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74045*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74045*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74045*/ #else
/* under construction !*/
/* under construction !*/
/*SKY74045*/ #endif
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
/*SKY74045*/ #if IS_BSI_SX0_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74045*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74045*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74045*/ #else
/* under construction !*/
/* under construction !*/
/*SKY74045*/ #endif
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

#if IS_RF_AERO2
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
/*AERO2*/ #ifdef RF_AERO2_4209
/* under construction !*/
/* under construction !*/
/*AERO2*/ #else
/* under construction !*/
/* under construction !*/
/*AERO2*/ #endif
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

#if IS_RF_SKY74137
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

#if IS_RF_GRF6201
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

#if IS_RF_IRFS3001
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

#if IS_RF_AD6548
/*AD6548*/
/*AD6548*/ /*..........................................................*/
/*AD6548*/ /*  Define Alias and Table                                  */
/*AD6548*/ /*..........................................................*/
/*AD6548*/
/*AD6548*/ #define  SCTRL_WARM        SCTRL_WORD(0,24)
/*AD6548*/ #define  SCTRL_PLL         SCTRL_WORD(0,24)
/*AD6548*/ #define  SCTRL_AGC         SCTRL_WORD(0,24)
/*AD6548*/ #define  SCTRL_RXON        SCTRL_WORD(0,24)
/*AD6548*/ #define  SCTRL_TXON        SCTRL_WORD(0,24)
/*AD6548*/
/*AD6548*/ #define  SDATA_PLLTX_MASK  0x008000L
/*AD6548*/ #define  SDATA_RXON_MASK   0x000200L
/*AD6548*/ #define  SDATA_TXON_MASK   0x008400L
/*AD6548*/
/*AD6548*/ #define  LNA_SET_IDX       (((BBTXParameters.bbrx_dcs1800_pcs1900_swap&0x1)<<1)|(BBTXParameters.bbrx_gsm850_gsm900_swap&0x1))
/*AD6548*/
/*AD6548*/ const unsigned long  SDATA_WARM_BSEL[5]=
/*AD6548*/ { /*Warm*/  /*Band sel*/
/*AD6548*/    0x000184,            /*GSM 450 no support*/
/*AD6548*/    0x006184 | 0x001800, /*GSM 850*/
/*AD6548*/    0x006184 | 0x000000, /*GSM 900*/
/*AD6548*/    0x006184 | 0x000800, /*DCS 1800*/
/*AD6548*/    0x006184 | 0x001000, /*PCS 1900*/
/*AD6548*/ };
/*AD6548*/
/*AD6548*/ const unsigned short LNA_SWAP_INDEX[4][5]=
/*AD6548*/ {
/*AD6548*/    { 0, 1, 2, 3, 4 }, /*No Swap*/
/*AD6548*/    { 0, 2, 1, 3, 4 }, /*Low Band Swap*/
/*AD6548*/    { 0, 1, 2, 4, 3 }, /*High Band Swap*/
/*AD6548*/    { 0, 2, 1, 4, 3 }, /*High&Low Band Swap*/
/*AD6548*/ };
/*AD6548*/
/*AD6548*/ /*..........................................................*/
/*AD6548*/ /* Serial Interface Implement                               */
/*AD6548*/ /*..........................................................*/
/*AD6548*/
   #if IS_BSI_SX0_SUPPORT
/*AD6548*/ void  L1D_RF_SetSData_SR0( void )
/*AD6548*/ {
/*AD6548*/ }
   #endif
/*AD6548*/ void  L1D_RF_SetSData_SR1( void )
/*AD6548*/ {
/*AD6548*/    unsigned short CW_WARM_IDX = LNA_SWAP_INDEX[LNA_SET_IDX][l1d_rf.band];
/*AD6548*/    SETUP_SR1();
/*AD6548*/
/*AD6548*/    HWRITE_2_SDATA(SCTRL_WARM, SDATA_WARM_BSEL[ CW_WARM_IDX ],
/*AD6548*/                   SCTRL_PLL,  l1d_rf.RFN_data);
/*AD6548*/ }
/*AD6548*/
/*AD6548*/ void  L1D_RF_SetSData_SR2( void )
/*AD6548*/ {
/*AD6548*/    SETUP_SR2();
/*AD6548*/
/*AD6548*/    if(IS_CONTINUOUS_RX_SLOT())
/*AD6548*/    {
/*AD6548*/       HWRITE_2_SDATA( SCTRL_AGC,      l1d_rf.AGC_data,
/*AD6548*/                       SCTRL_RESERVED, 0 );
/*AD6548*/    }
/*AD6548*/    else
/*AD6548*/    {
/*AD6548*/       unsigned short CW_WARM_IDX = LNA_SWAP_INDEX[LNA_SET_IDX][l1d_rf.band];
/*AD6548*/       HWRITE_2_SDATA( SCTRL_AGC,  l1d_rf.AGC_data,
/*AD6548*/                       SCTRL_RXON, SDATA_WARM_BSEL[CW_WARM_IDX]|SDATA_RXON_MASK );
/*AD6548*/    }
/*AD6548*/ }
/*AD6548*/
/*AD6548*/ void  L1D_RF_SetSData_SR3( void )
/*AD6548*/ {
/*AD6548*/    SETUP_SR3();
/*AD6548*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*AD6548*/ }
/*AD6548*/
   #if IS_BSI_SX0_SUPPORT
/*AD6548*/ void  L1D_RF_SetSData_ST0( void )
/*AD6548*/ {
/*AD6548*/ }
   #endif
/*AD6548*/ void  L1D_RF_SetSData_ST1( void )
/*AD6548*/ {
/*AD6548*/    unsigned short CW_WARM_IDX = LNA_SWAP_INDEX[LNA_SET_IDX][l1d_rf.band];
/*AD6548*/    SETUP_ST1();
/*AD6548*/
/*AD6548*/    HWRITE_2_SDATA(SCTRL_WARM, SDATA_WARM_BSEL[CW_WARM_IDX]|SDATA_PLLTX_MASK,
/*AD6548*/                   SCTRL_PLL,  l1d_rf.RFN_data);
/*AD6548*/
/*AD6548*/    if( l1d_rf.d2c_txiqswap==0 )
/*AD6548*/    {  BFETXSET  bfetxset;
/*AD6548*/       HW_READ_BFETXSET( bfetxset );
/*AD6548*/       bfetxset.field.iqswap = (l1d_rf.band >2 ? 0 : 1)& 0x1;
/*AD6548*/       HW_WRITE_BFETXSET( bfetxset );
/*AD6548*/    }
/*AD6548*/ }
/*AD6548*/
/*AD6548*/ void  L1D_RF_SetSData_ST2( void )
/*AD6548*/ {
/*AD6548*/    unsigned short CW_WARM_IDX = LNA_SWAP_INDEX[LNA_SET_IDX][l1d_rf.band];
/*AD6548*/    SETUP_ST2();
/*AD6548*/
/*AD6548*/    HWRITE_2_SDATA( SCTRL_TXON,    SDATA_WARM_BSEL[CW_WARM_IDX]|SDATA_TXON_MASK,
/*AD6548*/                    SCTRL_RESERVED,   0 );
/*AD6548*/ }
/*AD6548*/
/*AD6548*/ void  L1D_RF_SetSData_ST3( void )
/*AD6548*/ {
/*AD6548*/    SETUP_ST3();
/*AD6548*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*AD6548*/ }
/*AD6548*/
/*AD6548*/ void  L1D_RF_SetSData_ST2B( void )
/*AD6548*/ {
/*AD6548*/ }
/*AD6548*/
/*AD6548*/ void  L1D_RF_SetSData_ST2M( void )
/*AD6548*/ {
/*AD6548*/ }
/*AD6548*/
#endif

#if IS_RF_AD6546
/*AD6546*/
/*AD6546*/ /*..........................................................*/
/*AD6546*/ /*  Define Alias and Table                                  */
/*AD6546*/ /*..........................................................*/
/*AD6546*/
/*AD6546*/ #define  SCTRL_WARM              SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_PLL               SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_AGC               SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_RXON              SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_TXON              SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_TESTREG           SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_AMLOOP            SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_START_PCL_CAL     SCTRL_WORD(0,24)
/*AD6546*/ #define  SCTRL_MOD_CHANGE        SCTRL_WORD(0,24)
/*AD6546*/
/*AD6546*/ #define  SDATA_PLLTX_MASK        0x008000L
/*AD6546*/ #define  SDATA_RXON_MASK         0x000200L
/*AD6546*/ #define  SDATA_TXON_MASK         0x008400L  //(((l1d_rf.tx_mod_type)&(1<<l1d_rf.rtxwin_idx))<<16))
/*AD6546*/ #define  SDATA_START_PCL_CAL    (0x020024L|(((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)<<16))  // PCL_CAL + MOD_MODE 3 wire control
/*AD6546*/ #define  SDATA_MOD8              0x010024L
/*AD6546*/ #define  SDATA_MODG              0x010044L
/*AD6546*/ #define  SDATA_AMLOOP            0x800008L //Support GMSK TX only
/*AD6546*/ //#define  SDATA_WAIT5QB           0x000024L  replaced by sending register 8 because of there maybe different gama level between slots  Vito
/*AD6546*/ //#define  SDATA_AMLOOP_CAL_DATA ((RFSpecialCoef.tx.ad6546tx.RegData[l1d_rf.band-1])<<16)
/*AD6546*/ //         AM_FB_DAC + REFDET_SLOPE_SKEW
/*AD6546*/ //#define  SDATA_AMLOOP_CAL_DATA (((RFSpecialCoef.tx.ad6546tx.CalData[l1d_rf.band-1].REFDET_SLOPE_SKEW & 0x0F)|((RFSpecialCoef.tx.ad6546tx.CalData[l1d_rf.band-1].AM_FB_DAC<<4) & 0xF0))<<16)
/*AD6546*/
/*AD6546*/ const unsigned long  SDATA_WARM_BSEL[5]=
/*AD6546*/ { /*Warm*/ /*Band sel*/
/*AD6546*/    0x000184,            /*GSM 450 no support*/
/*AD6546*/    0x006184 | 0x001800, /*GSM 850*/
/*AD6546*/    0x006184 | 0x000000, /*GSM 900*/
/*AD6546*/    0x006184 | 0x000800, /*DCS 1800*/
/*AD6546*/    0x006184 | 0x001000, /*PCS 1900*/
/*AD6546*/ };
/*AD6546*/
/*AD6546*/ //const unsigned long  SDATA_AMLOOP[5]=    // Vito, this table for default reg8 value had been writen in RF_PowerOn
/*AD6546*/ //{ /*TX AM Loop Setting*/
/*AD6546*/ //   0x000008, /*GSM 450 no support*/
/*AD6546*/ //   0x009a08, //TriQ /*GSM 850*/   /* VGA setting 9,APC cap 36.63 pF*///0x009808 SKY
/*AD6546*/ //   0x009a08, //TriQ /*GSM 900*/   /* VGA setting 9,APC cap 36.63 pF*///0x009788 SKY
/*AD6546*/ //   0x009608, //TriQ /*DCS 1800*/  /* VGA setting 9,APC cap 23.3  pF*///0x009308 SKY
/*AD6546*/ //   0x009608, //TriQ /*PCS 1900*/  /* VGA setting 9,APC cap 23.3  pF*///0x009488 SKY
/*AD6546*/ //};
/*AD6546*/
/*AD6546*/ /*const*/unsigned long  SDATA_TESTREG1[4]=
/*AD6546*/ { /*Can be used to improve phase loop TX blocker immunity at low PCL*/
/*AD6546*/    0x080F9E,//0x080c9e, /*Used in CS service*/
/*AD6546*/    0x0C1F9E,//0x081c9e//0x080c1e  /*Used in PS service*/// 1st Reg30 for Internal PM loop locking
/*AD6546*/    0x081F9E,//0x081c9e//0x080c1e  /*Used in PS service*/
/*AD6546*/    0x84001E,//Support GMSK only
/*AD6546*/ };
/*AD6546*/
/*AD6546*/ unsigned int AM_Loop_Calculate( void );
/*AD6546*/
/*AD6546*/ /*..........................................................*/
/*AD6546*/ /* Serial Interface Implement                               */
/*AD6546*/ /*..........................................................*/
/*AD6546*/
   #if IS_BSI_SX0_SUPPORT
/*AD6546*/ void  L1D_RF_SetSData_SR0( void )
/*AD6546*/ {
/*AD6546*/ }
   #endif
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_SR1( void )
/*AD6546*/ {
/*AD6546*/    SETUP_SR1();
/*AD6546*/    HWRITE_2_SDATA( SCTRL_WARM,    SDATA_WARM_BSEL[l1d_rf.band],
/*AD6546*/                    SCTRL_PLL,     l1d_rf.RFN_data);
/*AD6546*/ }
/*AD6546*/
   #if IS_BSI_V2_SUPPORT
/*AD6546*/ void  L1D_RF_SetSData_SR2( void )
/*AD6546*/ {
/*AD6546*/    SETUP_SR2();
/*AD6546*/
/*AD6546*/    if(IS_CONTINUOUS_RX_SLOT())
/*AD6546*/    {
/*AD6546*/       HWRITE_3_SDATA( SCTRL_AGC,    l1d_rf.AGC_data,
/*AD6546*/                       SCTRL_RESERVED,   0,
/*AD6546*/                       SCTRL_RESERVED,   0 );
/*AD6546*/    }
/*AD6546*/    else
/*AD6546*/    {
/*AD6546*/       HWRITE_3_SDATA( SCTRL_AGC,    l1d_rf.AGC_data,
/*AD6546*/                       SCTRL_RXON,    SDATA_WARM_BSEL[l1d_rf.band]|SDATA_RXON_MASK,
/*AD6546*/                       SCTRL_RESERVED,   0 );
/*AD6546*/    }
/*AD6546*/ }
   #else
/*AD6546*/ void  L1D_RF_SetSData_SR2( void )
/*AD6546*/ {
/*AD6546*/    SETUP_SR2();
/*AD6546*/
/*AD6546*/    if(IS_CONTINUOUS_RX_SLOT())
/*AD6546*/    {
/*AD6546*/       HWRITE_2_SDATA( SCTRL_AGC,    l1d_rf.AGC_data,
/*AD6546*/                       SCTRL_RESERVED,   0 );
/*AD6546*/    }
/*AD6546*/    else
/*AD6546*/    {
/*AD6546*/       HWRITE_2_SDATA( SCTRL_AGC,    l1d_rf.AGC_data,
/*AD6546*/                       SCTRL_RXON,    SDATA_WARM_BSEL[l1d_rf.band]|SDATA_RXON_MASK );
/*AD6546*/    }
/*AD6546*/ }
   #endif
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_SR3( void )
/*AD6546*/ {
/*AD6546*/    SETUP_SR3();
/*AD6546*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*AD6546*/ }
/*AD6546*/
   #if IS_BSI_SX0_SUPPORT
/*AD6546*/ void  L1D_RF_SetSData_ST0( void )
/*AD6546*/ {
/*AD6546*/ }
   #endif
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_ST1( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST1();
/*AD6546*/    HWRITE_2_SDATA( SCTRL_WARM,    SDATA_WARM_BSEL[l1d_rf.band]|SDATA_PLLTX_MASK,
/*AD6546*/                    SCTRL_PLL,     l1d_rf.RFN_data);
/*AD6546*/
/*AD6546*/    if( l1d_rf.d2c_txiqswap==0 )
/*AD6546*/    {
/*AD6546*/       L1D_BFE_SET_TxIQSwapRegister( l1d_rf.band <= FrequencyBand900 );
/*AD6546*/    }
/*AD6546*/ }
/*AD6546*/
   #if IS_BSI_V2_SUPPORT
/*AD6546*/ void  L1D_RF_SetSData_ST2( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST2();
/*AD6546*/    HWRITE_3_SDATA( SCTRL_TXON,    SDATA_WARM_BSEL[l1d_rf.band]|SDATA_TXON_MASK,
/*AD6546*/                    SCTRL_RESERVED,   0,
/*AD6546*/                    SCTRL_RESERVED,   0 );
/*AD6546*/ }
   #else
/*AD6546*/ void  L1D_RF_SetSData_ST2( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST2();
/*AD6546*/    HWRITE_2_SDATA( SCTRL_TXON,    SDATA_WARM_BSEL[l1d_rf.band]|SDATA_TXON_MASK,
/*AD6546*/                    SCTRL_RESERVED,   0 );
/*AD6546*/ }
   #endif
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_ST3( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST3();
/*AD6546*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*AD6546*/ }
/*AD6546*/
   #if IS_HW_DISABLE_EPSK_TX_SUPPORT
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_ST2B( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST2B_ST2M();
/*AD6546*/    HWRITE_3_SDATA( SCTRL_TESTREG,        SDATA_TESTREG1[3],
/*AD6546*/                    SCTRL_AMLOOP,         SDATA_AMLOOP,
/*AD6546*/                    SCTRL_START_PCL_CAL,  SDATA_START_PCL_CAL );
/*AD6546*/ }
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_ST2M( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST2B_ST2M();
/*AD6546*/    HWRITE_3_SDATA( SCTRL_TESTREG,        SDATA_TESTREG1[3],
/*AD6546*/                    SCTRL_AMLOOP,         SDATA_AMLOOP,
/*AD6546*/                    SCTRL_MOD_CHANGE,     SDATA_MODG );
/*AD6546*/ }
/*AD6546*/
   #else
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_ST2B( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST2B_ST2M();
/*AD6546*/ // AM_Loop_Calculate();   //calculate register 8 value for different PCL (gama) level
/*AD6546*/
/*AD6546*/    if((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)  // 8PSK
/*AD6546*/    {
/*AD6546*/       HWRITE_3_SDATA( SCTRL_TESTREG,        SDATA_TESTREG1[2], /*Temporary Set PS service now*/
/*AD6546*/                       SCTRL_AMLOOP,         AM_Loop_Calculate(),
/*AD6546*/                       SCTRL_START_PCL_CAL,  SDATA_START_PCL_CAL );
/*AD6546*/    }
/*AD6546*/    else  // GMSK
/*AD6546*/    {
/*AD6546*/       HWRITE_3_SDATA( SCTRL_TESTREG,        SDATA_TESTREG1[1], /*Temporary Set PS service now*/
/*AD6546*/                       SCTRL_AMLOOP,         AM_Loop_Calculate(),
/*AD6546*/                       SCTRL_START_PCL_CAL,  SDATA_START_PCL_CAL );
/*AD6546*/    }
/*AD6546*/ }
/*AD6546*/
/*AD6546*/ void  L1D_RF_SetSData_ST2M( void )
/*AD6546*/ {
/*AD6546*/    SETUP_ST2B_ST2M();
/*AD6546*/ // AM_Loop_Calculate();  //calculate register 8 value for different PCL (gama) level
/*AD6546*/
/*AD6546*/    if((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)
/*AD6546*/    {
/*AD6546*/       HWRITE_3_SDATA( SCTRL_TESTREG,      SDATA_TESTREG1[2],
/*AD6546*/                       SCTRL_AMLOOP,       AM_Loop_Calculate(),//SCTRL_MOD_CHANGE,   SDATA_WAIT5QB,
/*AD6546*/                       SCTRL_MOD_CHANGE,   SDATA_MOD8     );
/*AD6546*/    }
/*AD6546*/    else
/*AD6546*/    {
/*AD6546*/       HWRITE_3_SDATA( SCTRL_TESTREG,      SDATA_TESTREG1[1],
/*AD6546*/                       SCTRL_AMLOOP,       AM_Loop_Calculate(),//SCTRL_MOD_CHANGE,   SDATA_WAIT5QB,
/*AD6546*/                       SCTRL_MOD_CHANGE,   SDATA_MODG     );
/*AD6546*/    }
/*AD6546*/ }
/*AD6546*/
   #endif
#endif

#if IS_RF_MT6162
/*MT6162*/
/*MT6162*/ /*..........................................................*/
/*MT6162*/ /* Serial Interface Implement                               */
/*MT6162*/ /*..........................................................*/
/*MT6162*/
/*MT6162*/ #define  SCTRL_DDC_RXEN               SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_RX_BAND                SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_RX_MODE_SRX            SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_SRX_FREQ               SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_RX_MODE_RXEN           SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_RX_OFFSET              SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_RX_GAIN                SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_RX_MODE_OFF            SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_DDC_RXOFF              SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_TX_BB_FILT_2G          SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_TX_CONFIG              SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_DDC_TXEN               SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_CW02_DFM_PLL           SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_TX_BAND_BSEL           SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_CW01_DFM_PLL           SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_CW43_DFM               SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_TXMODE_CTRL            SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_TX_GAINWRITE           SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_CW02_DFM_PLL_OFF       SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_TXMODE_CTRL_OFF        SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_DDC_TXOff              SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_INIT_DET_SETUP         SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_INIT_TIME              SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_INIT_GAINRF            SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_DCXO_CAFC_CTRL         SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_CW06                   SCTRL_WORD(0,30)
/*MT6162*/ #define  SCTRL_CW00                   SCTRL_WORD(0,30) /* for OH E2 */
/*MT6162*/ #define  SCTRL_CW10                   SCTRL_WORD(0,30) /* for OH E2 */
/*MT6162*/
/*MT6162*/ #define  SDATA_DDC_RXEN               0x0D177F01L
/*MT6162*/ #define  SDATA_DDC_RXEN_TXVCO_ON      0x0D177F07L
/*MT6162*/ #define  SDATA_RX_MODE_SRX            0x08100100L
/*MT6162*/ #define  SDATA_SRX_FREQ_MASK          0x06100000L
/*MT6162*/ #define  SDATA_RX_MODE_RXEN           0x081001E0L
/*MT6162*/ #define  SDATA_RX_Offset_MASK         0x08200000L
/*MT6162*/ #define  SDATA_RX_Gain_MASK           0x08300000L
/*MT6162*/ #define  SDATA_RX_MODE_OFF            0x08100000L
/*MT6162*/ #define  SDATA_DDC_RXOff              0x0D120001L
/*MT6162*/ #define  SDATA_DDC_RXOff_TXVCO_ON     0x0D120007L
/*MT6162*/ #define  SDATA_TX_BB_FILT_2G          0x0AC20948L
/*MT6162*/ #define  SDATA_TX_CONFIG_LB           0x0A900335L
/*MT6162*/ #define  SDATA_TX_CONFIG_HB           0x0A900365L
/*MT6162*/ #define  SDATA_DDC_TXEN               0x0D1B007FL
/*MT6162*/ #define  SDATA_CW01_DFM_PLL_MASK      0x00140000L
/*MT6162*/ #define  SDATA_CW43_DFM_GSM_E1        0x02B9C005L /* bit[19]=1, reset the compensation filter */
/*MT6162*/ #define  SDATA_CW43_DFM_EDGE_E1       0x02BDC005L /* bit[19]=1, reset the compensation filter */
/*MT6162*/ #define  SDATA_CW43_DFM_GSM_E2        0x02B9C00CL /* bit[4:0]=12, increase the SX bandgap fast-charge OFF delay time on E2 */
/*MT6162*/ #define  SDATA_CW43_DFM_EDGE_E2       0x02BDC00CL /* bit[4:0]=12, increase the SX bandgap fast-charge OFF delay time on E2 */
/*MT6162*/ #define  SDATA_TXMODE_CTRL_GSM        0x0A1000FCL
/*MT6162*/ #define  SDATA_TXMODE_CTRL_EDGE       0x0A1000FDL
/*MT6162*/ #define  SDATA_TXMODE_CTRL_2G         0x0A100000L
/*MT6162*/ #define  SDATA_TX_GAINWRITE_MASK      0x0A400001L
/*MT6162*/ #define  SDATA_TX_MEASURE_TRIGGER     0x0A400001L /* as long as MEAS_SEL[1:0] is not 0, a measurement will be triggered */
/*MT6162*/ #define  SDATA_TXMODE_CTRL_OFF        0x0A100000L
/*MT6162*/ #define  SDATA_DDC_TXOff              0x0D120001L
/*MT6162*/ #define  SDATA_DDC_TXOff_TXVCO_ON     0x0D120007L
/*MT6162*/ #define  SDATA_DDC_EN_TXCAL           0x0D1F7F7FL
/*MT6162*/ #define  SDATA_RX_MODE_SRX_TXCAL      0x08130102L /* RXVCO_CALBUF_EN[17]=1, TXCAL_BBPATH[16]=1, set to 3G RX_MODE (increase BW) */
/*MT6162*/ #define  SDATA_RX_MODE_RXEN_TXCAL     0x081301E2L /* RXVCO_CALBUF_EN[17]=1, TXCAL_BBPATH[16]=1, set to 3G RX_MODE (increase BW) */
/*MT6162*/ #define  SDATA_RX_DC_OFFSET_TXCAL     0x08200000L
/*MT6162*/ #define  SDATA_RX_GAIN_TXCAL          0x0830030CL
/*MT6162*/ #define  SDATA_TXMODE_CTRL_MASK_TXCAL 0x000BFF00L
/*MT6162*/ #define  SDATA_CW02_Standby_MASK      0x00040000L
/*MT6162*/ #define  SDATA_CW02_2G_MASK           0x00080000L
/*MT6162*/ #define  SDATA_INIT_DET_SETUP         0x0A200064L /* these three register values are different in 2G and 3G modes */
/*MT6162*/ #define  SDATA_INIT_TIME              0x0A301FC0L
/*MT6162*/ #define  SDATA_INIT_GAINRF            0x0C04A864L
/*MT6162*/ #define  SDATA_GAINRF_TXIQMMCAL       0x0C04A730L
/*MT6162*/ #define  SDATA_DCXO_CAFC_CTL_MASK     0x0E100000L
/*MT6162*/ #define  SDATA_CW00_2G                0x000402A8L /* set CP current to 40d to increase Loop BW for freq error */
/*MT6162*/ #define  SDATA_CW10_INIT              0x00A41150L /* LG_MODE[1:0]=0 */
/*MT6162*/ #define  SDATA_CW10_ISOTPOL_1         0x00A40116L /* set LG_DCI_TSEL[12:11]=0, LG_LCAL_TSEL[9:6]=4, DFM_LGCP_ISOTPOL[2]=1, LG_MODE[1:0]=2(2-step LG cal) */
/*MT6162*/ #define  SDATA_CW10_ISOTPOL_0         0x00A40112L /* set LG_DCI_TSEL[12:11]=0, LG_LCAL_TSEL[9:6]=4, DFM_LGCP_ISOTPOL[2]=0, LG_MODE[1:0]=2(2-step LG cal) */
/*MT6162*/ #define  SDATA_CW02_D7_PLUS           0x00000080L /* set N_FRAC[12:0]=0000010000000b, (D[7]=1), for +TRX offset */
/*MT6162*/ #define  SDATA_CW02_D7_MINUS          0x00001F80L /* set N_FRAC[12:0]=1111110000000b,           for -TRX offset */
/*MT6162*/ #define  SDATA_CW02_TXMODE_MASK       0x00080000L /* set MODE[19:17]=100b */
/*MT6162*/
/*MT6162*/ CONST unsigned long  SDATA_RX_BAND[5] =
/*MT6162*/ {  /* BAND[2:0] */
/*MT6162*/    0x08002800,                       /* GSM  450 no support */
/*MT6162*/    0x08002800|(GSM850_PATH_SEL&0xF), /* GSM  850, LNA8 */
/*MT6162*/    0x08002800|(   GSM_PATH_SEL&0xF), /* GSM  900, LNA7 */
/*MT6162*/    0x08002800|(   DCS_PATH_SEL&0xF), /* DCS 1800, LNA6 */
/*MT6162*/    0x08002800|(   PCS_PATH_SEL&0xF), /* PCS 1900, LNA5 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_CW02_DFM_PLL_MASK[5] =
/*MT6162*/ {
/*MT6162*/    0x00208000, /* GSM  450 no support */
/*MT6162*/    0x00208000, /* GSM  850 */
/*MT6162*/    0x0020A000, /* GSM  900 */
/*MT6162*/    0x0020C000, /* DCS 1800 */
/*MT6162*/    0x0020E000, /* PCS 1900 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_TX_BAND_BSEL[5] =
/*MT6162*/ {
/*MT6162*/    0x0A000001, /* GSM  450 no support */
/*MT6162*/    0x0A000001, /* GSM  850 */
/*MT6162*/    0x0A000001, /* GSM  900 */
/*MT6162*/    0x0A000044, /* DCS 1800, set TX_DRV_TUNE[7:6] to 1 */
/*MT6162*/    0x0A000004, /* PCS 1900 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_CW02_DFM_PLL_OFF[5] =
/*MT6162*/ {
/*MT6162*/    0x00208000, /* GSM  450 no support */
/*MT6162*/    0x00208000, /* GSM  850 */
/*MT6162*/    0x0020A000, /* GSM  900 */
/*MT6162*/    0x0020C000, /* DCS 1800 */
/*MT6162*/    0x0020E000, /* PCS 1900 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ #if IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/ const unsigned long  SDATA_SRX_FREQ_RXCAL[5] =
/*MT6162*/ {
/*MT6162*/    0x06100000, /* GSM 450 no support */
/*MT6162*/    /* rfN = (N_FRAC&0xFFF) | ((N_INT&0x7F)<<12) */
/*MT6162*/    ( (1696&0xFFF)|((67&0x7F)<<12) ), /* GSM  850, ARFCN=190, f= 881.6MHz */
/*MT6162*/    ( (1056&0xFFF)|((72&0x7F)<<12) ), /* GSM  900, ARFCN= 38, f= 942.6MHz */
/*MT6162*/    ( (1808&0xFFF)|((70&0x7F)<<12) ), /* DCS 1800, ARFCN=699, f=1842.6MHz */
/*MT6162*/    ( ( 800&0xFFF)|((75&0x7F)<<12) ), /* PCS 1900, ARFCN=661, f=1960.0MHz */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_RX_GAIN_TABLE_RXCAL[4] =
/*MT6162*/ {
/*MT6162*/    /* RXGAIN_OW_EN[8], PGAGAIN_OW[6:4], BQGAIN_OW[1:0] */
/*MT6162*/    0x09031140,//0x09000140, /* [PGAGAIN_OW, BQGAIN_OW]=[4(5dB), 0( 0dB)], for the 1st slot */
/*MT6162*/    0x09031141,//0x09000141, /* [PGAGAIN_OW, BQGAIN_OW]=[4(5dB), 1( 6dB)], for the 2nd slot */
/*MT6162*/    0x09031142,//0x09000142, /* [PGAGAIN_OW, BQGAIN_OW]=[4(5dB), 2(12dB)], for the 3rd slot */
/*MT6162*/    0x09031143,//0x09000143, /* [PGAGAIN_OW, BQGAIN_OW]=[4(5dB), 3(18dB)], for the 4th slot */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_RX_DCOFFSET_RXCAL[2] =
/*MT6162*/ {
/*MT6162*/    0x08200000, /* [DC_Offset_i, DC_Offset_q]=[0, 0], for the 1st slot */
/*MT6162*/    0x08200808, /* [DC_Offset_i, DC_Offset_q]=[8, 8], for the 2nd slot */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_TX_BAND_TXCAL[5] =
/*MT6162*/ {
/*MT6162*/    0x0A000000, /* GSM  450 no support */
/*MT6162*/    /* TX_PDETVCO_SEL[5]=1, TX_CAL_EN[4]=1, and TX_FB_EN[3]=1 */
/*MT6162*/    0x0A000039, /* GSM  850 */
/*MT6162*/    0x0A000039, /* GSM  900 */
/*MT6162*/    0x0A00003C, /* DCS 1800 */
/*MT6162*/    0x0A00003C, /* PCS 1900 */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_SRX_FREQ_TXCAL[5] =
/*MT6162*/ {
/*MT6162*/    0x06100000, /* GSM 450 no support */
/*MT6162*/    /* rfN = (N_FRAC&0xFFF) | ((N_INT&0x7F)<<12) */
/*MT6162*/    ( ( 736&0xFFF)|((64&0x7F)<<12) ), /* GSM  850, ARFCN=190, f= 836.6MHz */
/*MT6162*/    ( ( 960&0xFFF)|((69&0x7F)<<12) ), /* GSM  900, ARFCN= 65, f= 903.0MHz */
/*MT6162*/    ( (1616&0xFFF)|((65&0x7F)<<12) ), /* DCS 1800, ARFCN=512, f=1710.2MHz */
/*MT6162*/    ( ( 336&0xFFF)|((71&0x7F)<<12) ), /* PCS 1900, ARFCN=512, f=1850.2MHz */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_CW01_DFM_PLL_TXCAL[5] =
/*MT6162*/ {
/*MT6162*/    0x00100000, /* GSM 450 no support */
/*MT6162*/    /* rfN = (N_FRAC&0x3FF) | ((N_INT&0xFF)<<10) */
/*MT6162*/    ( (6023923&0x3FF)|((128&0xFF)<<10) ), /* GSM  850, ARFCN=190, f= 836.6MHz+67.7kHz */
/*MT6162*/    ( (7830701&0x3FF)|((138&0xFF)<<10) ), /* GSM  900, ARFCN= 65, f= 903.0MHz+67.7kHz */
/*MT6162*/    ( (4689683&0x3FF)|((131&0xFF)<<10) ), /* DCS 1800, ARFCN=512, f=1710.2MHz+67.7kHz */
/*MT6162*/    ( (2753850&0x3FF)|((142&0xFF)<<10) ), /* PCS 1900, ARFCN=512, f=1850.2MHz+67.7kHz */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ const unsigned long  SDATA_CW02_DFM_PLL_TXCAL[5] =
/*MT6162*/ {
/*MT6162*/    0x00200000, /* GSM 450 no support */
/*MT6162*/    /* ifN = (N_FRAC>>10)&0x1FFF */
/*MT6162*/    ( (6023923>>10)&0x1FFF ), /* GSM  850, ARFCN=190, f= 836.6MHz+67.7kHz */
/*MT6162*/    ( (7830701>>10)&0x1FFF ), /* GSM  900, ARFCN= 65, f= 903.0MHz+67.7kHz */
/*MT6162*/    ( (4689683>>10)&0x1FFF ), /* DCS 1800, ARFCN=512, f=1710.2MHz+67.7kHz */
/*MT6162*/    ( (2753850>>10)&0x1FFF ), /* PCS 1900, ARFCN=512, f=1850.2MHz+67.7kHz */
/*MT6162*/ };
/*MT6162*/
/*MT6162*/ unsigned long SDATA_TX_GAIN_CAL_TABLE[5] =
/*MT6162*/ {
/*MT6162*/    /* gainDET[19:16], gainRF[15:12], gainBB[11:2] */
/*MT6162*/    ( 0<<16)|(3<<12)|( 300<<2), /* [gainDET, gainRF, gainBB]=[ 0,3, 300], for GCM_SETUP_BURST5 */
/*MT6162*/    ( 7<<16)|(3<<12)|(1000<<2), /* [gainDET, gainRF, gainBB]=[ 7,3,1000], for GCM_SETUP_BURST6 */
/*MT6162*/    ( 8<<16)|(4<<12)|(1000<<2), /* [gainDET, gainRF, gainBB]=[ 8,4,1000], for GCM_SETUP_BURST7 */
/*MT6162*/    ( 9<<16)|(5<<12)|(1000<<2), /* [gainDET, gainRF, gainBB]=[ 9,5,1000], for GCM_SETUP_BURST8 */
/*MT6162*/    (10<<16)|(6<<12)|(1000<<2)  /* [gainDET, gainRF, gainBB]=[10,6,1000], for GCM_SETUP_BURST9 */
/*MT6162*/ };
/*MT6162*/ #endif /* IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT */
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_SR0( void )
/*MT6162*/ {
/*MT6162*/    unsigned long data_ddc_en;
/*MT6162*/
/*MT6162*/    SETUP_SR0();
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )                                      /* TXIQMM Calibration is on-going */
/*MT6162*/    {  data_ddc_en   = SDATA_DDC_EN_TXCAL;  }                         /* enable all LDOs for RX and TX circuits when TXIQMM is on-going */
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  /* normal RX */
/*MT6162*/ #if IS_RF_VCO_DOO_OFF || IS_RF_VCO_PARTIAL_DOO_ON
/*MT6162*/       if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6162*/       {  data_ddc_en = SDATA_DDC_RXEN_TXVCO_ON;  }                   /* enable all LDOs for RX and SRX circuits, and keep TXVCO on */
/*MT6162*/       else
/*MT6162*/ #endif
/*MT6162*/       {  data_ddc_en = SDATA_DDC_RXEN;           }                   /* enable all LDOs for RX and SRX circuits */
/*MT6162*/    }
/*MT6162*/
/*MT6162*/ #if IS_MT6162_DCXO_SUPPORT
/*MT6162*/    HWRITE_5_SDATA( SCTRL_DDC_RXEN, data_ddc_en,
/*MT6162*/                    SCTRL_TX_BB_FILT_2G, SDATA_TX_BB_FILT_2G,
/*MT6162*/                    SCTRL_DCXO_CAFC_CTRL, (l1d_rf.AFC_data&0x1FFF)|SDATA_DCXO_CAFC_CTL_MASK, /* set DCXO */
/*MT6162*/                    SCTRL_RESERVED, 0,                                /* reserved */
/*MT6162*/                    SCTRL_RESERVED, 0 );                              /* reserved */
/*MT6162*/ #else
/*MT6162*/    HWRITE_4_SDATA( SCTRL_DDC_RXEN, data_ddc_en,
/*MT6162*/                    SCTRL_TX_BB_FILT_2G, SDATA_TX_BB_FILT_2G,
/*MT6162*/                    SCTRL_RESERVED, 0,                                /* reserved */
/*MT6162*/                    SCTRL_RESERVED, 0 );                              /* reserved */
/*MT6162*/ #endif
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_SR1( void )
/*MT6162*/ {
/*MT6162*/    unsigned long data_rx_mode = SDATA_RX_MODE_SRX;
/*MT6162*/    unsigned long rfn_data;
/*MT6162*/
/*MT6162*/    SETUP_SR1();
/*MT6162*/ #if IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_rx_cal )                                         /* RXDCOC is on-going */
/*MT6162*/    {  rfn_data = SDATA_SRX_FREQ_RXCAL[l1d_rf.band];  }
/*MT6162*/    else if( l1d_rf2.is_tx_cal&0x10 )                               /* TXIQMM calibration is on-going*/
/*MT6162*/    {
/*MT6162*/       data_rx_mode = SDATA_RX_MODE_SRX_TXCAL;
/*MT6162*/       rfn_data = SDATA_SRX_FREQ_TXCAL[l1d_rf.band];
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  rfn_data = l1d_rf.RFN_data;  }                               /* normal RX */
/*MT6162*/
/*MT6162*/    HWRITE_3_SDATA( SCTRL_RX_BAND, SDATA_RX_BAND[l1d_rf.band],      /* select correct LNA input */
/*MT6162*/                    SCTRL_RX_MODE_SRX, data_rx_mode,                /* enable SRX and select RX mode */
/*MT6162*/                    SCTRL_SRX_FREQ, rfn_data|SDATA_SRX_FREQ_MASK ); /* set synthesizer frequency */
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_SR2( void )
/*MT6162*/ {
/*MT6162*/    unsigned long ctrl_rx_dc_offset = SCTRL_RX_OFFSET;
/*MT6162*/    unsigned long ctrl_rx_agc = SCTRL_RX_GAIN;
/*MT6162*/    unsigned long data_rx_mode = SDATA_RX_MODE_RXEN;
/*MT6162*/    unsigned long data_rx_dc_offset;
/*MT6162*/    unsigned long data_rx_agc;
/*MT6162*/
/*MT6162*/    SETUP_SR2();
/*MT6162*/ #if IS_RF_RX_DCOC_SUPPORT || IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_rx_cal )
/*MT6162*/    {  /* RXDCOC is on-going*/
/*MT6162*/       if( l1d_rf.rx_slots==0x3 )
/*MT6162*/       {  /* calibrate the compensation voltage value per DAC */
/*MT6162*/          data_rx_dc_offset = SDATA_RX_DCOFFSET_RXCAL[l1d_rf.cur_slot];
/*MT6162*/          data_rx_agc = SDATA_RX_GAIN_TABLE_RXCAL[0];
/*MT6162*/       }
/*MT6162*/       else
/*MT6162*/       {
/*MT6162*/          data_rx_dc_offset = SDATA_RX_Offset_MASK;
/*MT6162*/          data_rx_agc = SDATA_RX_GAIN_TABLE_RXCAL[l1d_rf.cur_slot];
/*MT6162*/       }
/*MT6162*/    }
/*MT6162*/    else if( l1d_rf2.is_tx_cal&0x10 )
/*MT6162*/    {  /* TXIQMM calibration is on-going */
/*MT6162*/       ctrl_rx_dc_offset = SCTRL_RESERVED;
/*MT6162*/       ctrl_rx_agc = SCTRL_RESERVED;
/*MT6162*/       data_rx_mode = SDATA_RX_MODE_RXEN_TXCAL;
/*MT6162*/       data_rx_dc_offset = 0;
/*MT6162*/       data_rx_agc = 0;
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  /* normal RX */
/*MT6162*/       data_rx_dc_offset = l1d_rf2.rx_dc_offset|SDATA_RX_Offset_MASK;
/*MT6162*/       data_rx_agc = l1d_rf.AGC_data|SDATA_RX_Gain_MASK;
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    if( IS_CONTINUOUS_RX_SLOT() )
/*MT6162*/    {
/*MT6162*/       HWRITE_4_SDATA( ctrl_rx_dc_offset, data_rx_dc_offset, /* set RX DC offset */
/*MT6162*/                       ctrl_rx_agc, data_rx_agc,             /* set RX gain */
/*MT6162*/                       SCTRL_RESERVED, 0,                    /* reserved */
/*MT6162*/                       SCTRL_RESERVED, 0 );                  /* reserved */
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/    {
/*MT6162*/       HWRITE_4_SDATA( SCTRL_RX_MODE_RXEN, data_rx_mode,     /* enable RX circuits */
/*MT6162*/                       ctrl_rx_dc_offset, data_rx_dc_offset, /* set RX DC offset */
/*MT6162*/                       ctrl_rx_agc, data_rx_agc,             /* set RX gain */
/*MT6162*/                       SCTRL_RESERVED, 0 );                  /* reserved */
/*MT6162*/    }
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_SR3( void )
/*MT6162*/ {
/*MT6162*/    unsigned long ctrl_cw02 = SCTRL_RESERVED;
/*MT6162*/    unsigned long data_ddc_off = SDATA_DDC_RXOff;         /* set LDOs to the idle+dig state */
/*MT6162*/    unsigned long data_cw02 = 0;
/*MT6162*/
/*MT6162*/    SETUP_SR3();
/*MT6162*/ #if IS_RF_VCO_DOO_OFF || IS_RF_VCO_PARTIAL_DOO_ON 
/*MT6162*/    if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6162*/    {
/*MT6162*/       data_ddc_off = SDATA_DDC_RXOff_TXVCO_ON;           /* keep TXVCO on */
/*MT6162*/       ctrl_cw02    = SCTRL_CW02_DFM_PLL;
/*MT6162*/       data_cw02    = (l1d_rf.IFN_data&0x1FFF)|SDATA_CW02_DFM_PLL_MASK[l1d_rf.band]|SDATA_CW02_Standby_MASK;
/*MT6162*/    }
/*MT6162*/ #endif
/*MT6162*/
/*MT6162*/    HWRITE_3_SDATA( SCTRL_RX_MODE_OFF, SDATA_RX_MODE_OFF, /* turn off RX circuits */
/*MT6162*/                    SCTRL_DDC_RXOFF, data_ddc_off,        /* set LDOs */
/*MT6162*/                    ctrl_cw02, data_cw02 );               /* set CW02 to the stand-by mode */
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_ST0( void )
/*MT6162*/ {
/*MT6162*/    unsigned long data_tx_config = (l1d_rf.band<=FrequencyBand900) ? (SDATA_TX_CONFIG_LB) : (SDATA_TX_CONFIG_HB);
/*MT6162*/    unsigned long data_ddc_en = SDATA_DDC_TXEN;      /* enable bandgap reference to DFM and enable LDOs for TX VCO and LO buffers */
/*MT6162*/
/*MT6162*/    unsigned long ctrl_cw00 = SCTRL_RESERVED;        /* for OH E2 */
/*MT6162*/    unsigned long ctrl_cw10 = SCTRL_RESERVED;
/*MT6162*/    unsigned long data_cw00 = 0;
/*MT6162*/    unsigned long data_cw10 = 0;
/*MT6162*/
/*MT6162*/    SETUP_ST0();
/*MT6162*/    if( L1D_RF_Get6162Version()==1 )
/*MT6162*/    {  /* for OH E1, do nothing */  }
/*MT6162*/    else
/*MT6162*/    {  /* for OH E2 */
/*MT6162*/       ctrl_cw00 = SCTRL_CW00;
/*MT6162*/       ctrl_cw10 = SCTRL_CW10;
/*MT6162*/       data_cw00 = SDATA_CW00_2G;
/*MT6162*/       data_cw10 = (l1d_rf2.is_isotpol==1) ? SDATA_CW10_ISOTPOL_1 : SDATA_CW10_ISOTPOL_0;
/*MT6162*/       l1d_rf2.is_isotpol = 0;
/*MT6162*/    }
/*MT6162*/
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )                     /* TXIQMM Calibration is on-going*/
/*MT6162*/    {  data_ddc_en = SDATA_DDC_EN_TXCAL;  }          /* enable all LDOs for RX and TX circuits when TXIQMM is on-going */
/*MT6162*/ #endif
/*MT6162*/
/*MT6162*/ #if IS_MT6162_DCXO_SUPPORT
/*MT6162*/    HWRITE_5_SDATA( SCTRL_TX_CONFIG, data_tx_config, /* set TX configuration register for the high and low bands */
/*MT6162*/                    SCTRL_DDC_TXEN, data_ddc_en,                                             /* set LDOs */
/*MT6162*/                    SCTRL_DCXO_CAFC_CTRL, (l1d_rf.AFC_data&0x1FFF)|SDATA_DCXO_CAFC_CTL_MASK, /* set DCXO */
/*MT6162*/                    ctrl_cw00, data_cw00,           /* we need to set CW0 to the 2G value in OH E2 */
/*MT6162*/                    ctrl_cw10, data_cw10 );
/*MT6162*/ #else
/*MT6162*/    HWRITE_4_SDATA( SCTRL_TX_CONFIG, data_tx_config, /* set TX configuration register for the high and low bands */
/*MT6162*/                    SCTRL_DDC_TXEN, data_ddc_en,     /* set LDOs */
/*MT6162*/                    ctrl_cw00, data_cw00,            /* we need to set CW0 to the 2G value in OH E2 */
/*MT6162*/                    ctrl_cw10, data_cw10 );
/*MT6162*/ #endif
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_ST1( void )
/*MT6162*/ {
/*MT6162*/    unsigned long tx_band;
/*MT6162*/    unsigned long rfn_data;
/*MT6162*/
/*MT6162*/    SETUP_ST1();
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )
/*MT6162*/    {  /* TXIQMM Calibration is on-going */
/*MT6162*/       tx_band  = SDATA_TX_BAND_TXCAL[l1d_rf.band];
/*MT6162*/       rfn_data = SDATA_CW01_DFM_PLL_TXCAL[l1d_rf.band];
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  /* normal TX */
/*MT6162*/       tx_band  = SDATA_TX_BAND_BSEL[l1d_rf.band];
/*MT6162*/       rfn_data = l1d_rf.RFN_data;
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    HWRITE_3_SDATA( SCTRL_TX_BAND_BSEL, tx_band,                            /* set TX band */
/*MT6162*/                    SCTRL_CW01_DFM_PLL, rfn_data|SDATA_CW01_DFM_PLL_MASK,   /* set the synthesizer frequency */
/*MT6162*/                    SCTRL_INIT_DET_SETUP, SDATA_INIT_DET_SETUP );           /* set the GAINRAMP_T time, 50us */
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_ST2B( void )
/*MT6162*/ {
/*MT6162*/    unsigned long  ctrl_cw02             = (l1d_rf2.is_integer==1) ? SCTRL_CW02_DFM_PLL : SCTRL_RESERVED;
/*MT6162*/    unsigned long  data_tx_gain_set;
/*MT6162*/    unsigned long  data_txmode_ctrl_gsm  = SDATA_TXMODE_CTRL_GSM;
/*MT6162*/    unsigned long  data_txmode_ctrl_edge = SDATA_TXMODE_CTRL_EDGE;
/*MT6162*/    unsigned long  data_cw43_dfm_edge    = (L1D_RF_Get6162Version() == 1) ? (SDATA_CW43_DFM_EDGE_E1) : (SDATA_CW43_DFM_EDGE_E2);
/*MT6162*/    unsigned long  data_cw43_dfm_gsm     = (L1D_RF_Get6162Version() == 1) ? (SDATA_CW43_DFM_GSM_E1)  : (SDATA_CW43_DFM_GSM_E2);
/*MT6162*/    unsigned long  data_cw02             = (l1d_rf2.is_integer==1) ? ((l1d_rf.IFN_data&0x1FFF)|SDATA_CW02_DFM_PLL_MASK[l1d_rf.band]|SDATA_CW02_TXMODE_MASK) : 0;
/*MT6162*/
/*MT6162*/    SETUP_ST2B_ST2M();
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )
/*MT6162*/    {  /* TXIQMM Calibration is on-going */
/*MT6162*/       data_tx_gain_set  = SDATA_TX_GAIN_CAL_TABLE[(l1d_rf2.is_tx_cal&0x0F)];
/*MT6162*/       data_tx_gain_set |= SDATA_TX_GAINWRITE_MASK;
/*MT6162*/       data_txmode_ctrl_gsm |= SDATA_TXMODE_CTRL_MASK_TXCAL;
/*MT6162*/       data_txmode_ctrl_edge |= SDATA_TXMODE_CTRL_MASK_TXCAL;
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  /* normal TX */
/*MT6162*/       data_tx_gain_set  = L1D_RF_SetTxGainWrite( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band );
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 ) /* compensate TXIQ only in the EPSK mode */
/*MT6162*/       L1D_RF_SetEPSKTxIQ( (signed short)l1d_rf.cur_slot, data_tx_gain_set );
/*MT6162*/ #endif
/*MT6162*/       data_tx_gain_set |= SDATA_TX_MEASURE_TRIGGER; /* trigger the TX measurement in normal TX */
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6162*/    {  /* 8PSK */
/*MT6162*/       HWRITE_4_SDATA( SCTRL_CW43_DFM, data_cw43_dfm_edge,         /* set DFM to the EDGE mode */
/*MT6162*/                       SCTRL_TXMODE_CTRL, data_txmode_ctrl_edge,   /* set the TX mode to EDGE */
/*MT6162*/                       SCTRL_TX_GAINWRITE, data_tx_gain_set,       /* set the TX gain */
/*MT6162*/                       ctrl_cw02, data_cw02 );
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/    {  /* GMSK */
/*MT6162*/       HWRITE_4_SDATA( SCTRL_CW43_DFM, data_cw43_dfm_gsm,          /* set DFM to the GSM mode */
/*MT6162*/                       SCTRL_TXMODE_CTRL, data_txmode_ctrl_gsm,    /* set the TX mode to GSM */
/*MT6162*/                       SCTRL_TX_GAINWRITE, data_tx_gain_set,       /* set the TX gain */
/*MT6162*/                       ctrl_cw02, data_cw02 );
/*MT6162*/    }
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_ST3( void )
/*MT6162*/ {
/*MT6162*/    unsigned long  data_ddc_off;
/*MT6162*/    unsigned long  data_cw02;
/*MT6162*/
/*MT6162*/    SETUP_ST3();
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )
/*MT6162*/    {  /* TXIQMM Calibration is on-going */
/*MT6162*/       data_ddc_off = SDATA_DDC_EN_TXCAL; /* keep LDOs on until RX windows are off */
/*MT6162*/       data_cw02 = SDATA_CW02_DFM_PLL_TXCAL[l1d_rf.band]|SDATA_CW02_DFM_PLL_OFF[l1d_rf.band];
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  /* normal TX */
/*MT6162*/       data_cw02 = (l1d_rf.IFN_data&0x1FFF)|SDATA_CW02_DFM_PLL_OFF[l1d_rf.band];
/*MT6162*/ #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6162*/       if( l1d_rf2.dedicated_flag & SC_DEDICATED_2TX )
/*MT6162*/       {  /* set TXVCO to stand-by in the end of the 1st TX */
/*MT6162*/          data_ddc_off = SDATA_DDC_TXOff_TXVCO_ON;
/*MT6162*/          data_cw02 |= SDATA_CW02_Standby_MASK;
/*MT6162*/       }
/*MT6162*/       else
/*MT6162*/ #elif IS_RF_VCO_DOO_OFF
/*MT6162*/       if( l1d_rf2.dedicated_flag & SC_NON_IDLE )
/*MT6162*/       {  /* set TXVCO to stand-by in the end of TX */
/*MT6162*/          data_ddc_off = SDATA_DDC_TXOff_TXVCO_ON;
/*MT6162*/          data_cw02 |= SDATA_CW02_Standby_MASK;
/*MT6162*/       }
/*MT6162*/       else
/*MT6162*/ #endif
/*MT6162*/       {
/*MT6162*/          data_ddc_off = SDATA_DDC_TXOff;
/*MT6162*/       }
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    HWRITE_3_SDATA( SCTRL_CW02_DFM_PLL_OFF, data_cw02,            /* power down DFM */
/*MT6162*/                    SCTRL_TXMODE_CTRL_OFF, SDATA_TXMODE_CTRL_OFF, /* power down TX */
/*MT6162*/                    SCTRL_DDC_TXOff, data_ddc_off );              /* set LDOs  */
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_ST2( void )
/*MT6162*/ {
/*MT6162*/    unsigned long ctrl_cw02 = SCTRL_CW02_DFM_PLL;
/*MT6162*/    unsigned long data_cw02;
/*MT6162*/    unsigned long data_gainrf;
/*MT6162*/
/*MT6162*/    SETUP_ST2();
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )
/*MT6162*/    {  /* TXIQMM Calibration is on-going */
/*MT6162*/       data_cw02 = SDATA_CW02_DFM_PLL_TXCAL[l1d_rf.band]|SDATA_CW02_DFM_PLL_MASK[l1d_rf.band]|SDATA_CW02_Standby_MASK;
/*MT6162*/       data_gainrf = SDATA_GAINRF_TXIQMMCAL;
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {  /* normal TX */
/*MT6162*/       if( l1d_rf2.is_integer==1 )
/*MT6162*/       {
/*MT6162*/          data_cw02  = ((l1d_rf.IFN_data&0x1FFF)==0) ? SDATA_CW02_D7_PLUS : SDATA_CW02_D7_MINUS;
/*MT6162*/          data_cw02 |= (SDATA_CW02_DFM_PLL_MASK[l1d_rf.band]|SDATA_CW02_Standby_MASK);
/*MT6162*/       }
/*MT6162*/       else
/*MT6162*/       {  data_cw02  = (l1d_rf.IFN_data&0x1FFF)|SDATA_CW02_DFM_PLL_MASK[l1d_rf.band]|SDATA_CW02_Standby_MASK;  }
/*MT6162*/       data_gainrf = SDATA_INIT_GAINRF;
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    HWRITE_4_SDATA( SCTRL_TXMODE_CTRL, SDATA_TXMODE_CTRL_2G, /* set the TX mode to 2G */
/*MT6162*/                    ctrl_cw02, data_cw02,                    /* set CW02 to the stand-by mode */
/*MT6162*/                    SCTRL_INIT_TIME, SDATA_INIT_TIME,        /* set the DETMEAS_T1 time, 63.5us */
/*MT6162*/                    SCTRL_INIT_GAINRF, data_gainrf );
/*MT6162*/ }
/*MT6162*/
/*MT6162*/ void  L1D_RF_SetSData_ST2M( void )
/*MT6162*/ {
/*MT6162*/    unsigned long  data_tx_gain_set;
/*MT6162*/    unsigned long  data_txmode_ctrl_gsm  = SDATA_TXMODE_CTRL_GSM;
/*MT6162*/    unsigned long  data_txmode_ctrl_edge = SDATA_TXMODE_CTRL_EDGE;
/*MT6162*/    unsigned long  data_cw43_dfm_edge    = (L1D_RF_Get6162Version() == 1) ? (SDATA_CW43_DFM_EDGE_E1) : (SDATA_CW43_DFM_EDGE_E2);
/*MT6162*/    unsigned long  data_cw43_dfm_gsm     = (L1D_RF_Get6162Version() == 1) ? (SDATA_CW43_DFM_GSM_E1)  : (SDATA_CW43_DFM_GSM_E2);
/*MT6162*/
/*MT6162*/    SETUP_ST2B_ST2M();
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( l1d_rf2.is_tx_cal&0x10 )
/*MT6162*/    {  /* TXIQMM Calibration is on-going*/
/*MT6162*/       data_tx_gain_set  = SDATA_TX_GAIN_CAL_TABLE[(l1d_rf2.is_tx_cal&0x0F)];
/*MT6162*/       data_tx_gain_set |= SDATA_TX_GAINWRITE_MASK; /* do not trigger the TX measurement in the calibration */
/*MT6162*/       data_txmode_ctrl_gsm |= SDATA_TXMODE_CTRL_MASK_TXCAL;
/*MT6162*/       data_txmode_ctrl_edge |= SDATA_TXMODE_CTRL_MASK_TXCAL;
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/ #endif
/*MT6162*/    {
/*MT6162*/       data_tx_gain_set = L1D_RF_SetTxGainWrite( l1d_rf.tx_mod_type2, l1d_rf.cur_slot, l1d_rf2.tx_power[l1d_rf.cur_slot], (FrequencyBand)l1d_rf.band );
/*MT6162*/ #if IS_RF_TX_CALIBRATION_SUPPORT
/*MT6162*/    if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 ) /* compensate TXIQ only in the EPSK mode */
/*MT6162*/       L1D_RF_SetEPSKTxIQ( (signed short)l1d_rf.cur_slot, data_tx_gain_set );
/*MT6162*/ #endif
/*MT6162*/       data_tx_gain_set |= SDATA_TX_MEASURE_TRIGGER; /* trigger the TX measurement in normal TX */
/*MT6162*/    }
/*MT6162*/
/*MT6162*/    /* now change */
/*MT6162*/    if( (l1d_rf.change)&(1<<l1d_rf.cur_slot) )
/*MT6162*/    {  /* change g->8 */
/*MT6162*/       if( (l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1 )
/*MT6162*/       {
/*MT6162*/          HWRITE_4_SDATA( SCTRL_CW43_DFM, data_cw43_dfm_edge,       /* set DFM to the EDGE mode */
/*MT6162*/                          SCTRL_TXMODE_CTRL, data_txmode_ctrl_edge, /* set the TX mode to EDGE */
/*MT6162*/                          SCTRL_TX_GAINWRITE, data_tx_gain_set,     /* set the TX gain */
/*MT6162*/                          SCTRL_RESERVED, 0 );                      /* reserved */
/*MT6162*/       }
/*MT6162*/       /* change 8->g */
/*MT6162*/       else
/*MT6162*/       {
/*MT6162*/          HWRITE_4_SDATA( SCTRL_CW43_DFM, data_cw43_dfm_gsm,        /* set DFM to the GSM mode */
/*MT6162*/                          SCTRL_TXMODE_CTRL, data_txmode_ctrl_gsm,  /* set the TX mode to GSM */
/*MT6162*/                          SCTRL_TX_GAINWRITE, data_tx_gain_set,     /* set the TX gain */
/*MT6162*/                          SCTRL_RESERVED, 0 );                      /* reserved */
/*MT6162*/       }
/*MT6162*/    }
/*MT6162*/    else
/*MT6162*/    {
/*MT6162*/       HWRITE_4_SDATA( SCTRL_TX_GAINWRITE, data_tx_gain_set,        /* set the TX gain */
/*MT6162*/                       SCTRL_RESERVED, 0,                           /* reserved */
/*MT6162*/                       SCTRL_RESERVED, 0,                           /* reserved */
/*MT6162*/                       SCTRL_RESERVED, 0 );                         /* reserved */
/*MT6162*/    }
/*MT6162*/ }
/*MT6162*/
#endif

