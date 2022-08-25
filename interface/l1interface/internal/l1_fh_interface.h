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
 *   l1_fh_interface.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Interface for frequency hopping.
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
 ****************************************************************************/
 
#ifndef  _L1_FH_INTERFACE_H_
#define  _L1_FH_INTERFACE_H_
/* ------------------------------------------------------------------------- */

#include "l1d_cid.h"
#include "kal_general_types.h"

#define  DOWN_HOPPING                  0
#define  UP_HOPPING                    1

#define SPLL_FH_TABLE_MAX_SIZE 10

#if IS_CHIP_MT6253
#define MPLL_FH_TABLE_SIZE 13
#elif IS_CHIP_MT6236
#define MPLL_FH_TABLE_SIZE 9
#elif IS_CHIP_MT6256 || IS_CHIP_MT6255 || IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
#define MPLL_FH_TABLE_SIZE 64
#elif IS_CHIP_MT6251
   #if IS_MPLL_DYNAMIC_FH_SUPPORT
#define MPLL_FH_TABLE_SIZE 140
   #else
#define MPLL_FH_TABLE_SIZE 103
   #endif
#endif

#if IS_CHIP_MT6236
//if FM_CH is N, We will decide the collision happen when MPLL_CLK=N(+/-)FM_Collision_Range
//Multiply FM_Collision_range by 120 to reserve the floating point
#define LCD_CLK_SCALE                   120
#define RATIO_AHB_VALUE                 1
#define MPLL_F_FACTOR                   24 // this is to reserve floating point of MPLL freq
#define LCD_ONE_SCALE                   14
#else // IS_CHIP_MT6253
//Multiply FM_Collision_range by 100 to reserve the floating point, for example, 19 means 0.19MHz
#define LCD_CLK_SCALE                   100
#define RATIO_AHB_VALUE                 2
#define MPLL_F_FACTOR                   2  // this is to reserve floating point of MPLL freq
#define LCD_ONE_SCALE                   14
#endif //IS_CHIP_MT6236

#if IS_CHIP_MT6256 || IS_CHIP_MT6255 || IS_CHIP_MT6250 || IS_CHIP_MT6260 || IS_CHIP_MT6261
#define FHSET_SET_A_EQUAL_B(a,b) \
{ a.fh_set_l = b.fh_set_l;       \
  a.fh_set_h = b.fh_set_h;       \
}
#else
#define FHSET_SET_A_EQUAL_B(a,b) ((a) = (b))
#endif

#if IS_CHIP_MT6256 || IS_CHIP_MT6250 || IS_CHIP_MT6261
typedef  struct
{  unsigned int    fh_set_l;
   unsigned int    fh_set_h;
}  sFHset;
#elif IS_CHIP_MT6255 || IS_CHIP_MT6260
typedef  struct
{  unsigned int    fh_set_l;
   unsigned int    fh_set_h;
   unsigned int    fh_set_l_e;
   unsigned int    fh_set_h_e;
}  sFHset;
#else
typedef unsigned short sFHset;
#endif

#if IS_CHIP_MT6236
extern const int MPLL_F[MPLL_FH_TABLE_SIZE];
#elif IS_CHIP_MT6253
extern const int MPLL_F[2][MPLL_FH_TABLE_SIZE];
#endif

/*----------------------------------------------------------*/
/* interface for FM to update MPLL CLK Setting              */
/*----------------------------------------------------------*/
void       L1D_FH_FM_TurnOn( kal_bool is_on );
void       L1D_FH_FM_Set_FHset( sFHset FM_FHset );
kal_uint8  L1D_FH_GetHoppingType( void );
void       L1D_FH_FM_SetFreq( kal_int16 FM_Freq );
void       L1D_FH_FM_Set_EPLL_FreeRunParams( kal_int16 fr_base, kal_uint16 fr_down_range );
void       L1D_FH_FM_Set_PLL_FreeRunParams( kal_int16 fr_base, kal_uint16 fr_down_range );

/*----------------------------------------------------------*/
/* interface for ATV to update MPLL CLK Setting             */
/*----------------------------------------------------------*/
void       L1D_FH_ATV_TurnOn( kal_bool is_on );
void       L1D_FH_ATV_MPLLCLK_Select( kal_uint32 MPLL_index );
kal_uint16 L1D_FH_ATV_Get_MPLL_Setting( void );
kal_uint32 L1D_FH_ATV_Get_Ori_Setting ( void );
void       L1D_FH_ATV_Set_PLL_FreeRunParams( kal_int16 FM_freq, kal_uint16 fr_down_range );

/*----------------------------------------------------------*/
/* interface for LCD_Driver to update MPLL FH Table         */
/*----------------------------------------------------------*/
void       L1D_LCD_Cycle_Calculate( void );
void       FM_LCD_Cycle_Calculate( void );
/*----------------------------------------------------------*/
/* interface for RD to set MPLL CLK circular_ramp           */
/*----------------------------------------------------------*/
void       L1D_MPLL_CLK_Circular_Ramp( void );

/* ------------------------------------------------------------------------- */

/*-------------------------------------------------------------*/
/* Interface to enable the frequency hopping for the UDVT load */
/*-------------------------------------------------------------*/
#if defined(__UDVT__)
   #if  IS_CHIP_MT6261
#define  FREE_RUN_BASE              0
   
/* FHCON0 */
#define  TDMA_FHCON0_MASK           0xFCFF
/* -------------------------------------------------------------------------------------------------------- */
   
/* FHCON2 */
#define  UPSRAM_BUSY                0  /* Freq-hopping SRAM operation busy indicator                        */
#define  UPSRAM_CS                  1  /* Freq-hopping SRAM chip-select                                     */
#define  UPSRAM_ATRIG               0  /* Freq-hopping SRAM R/W address initialization indicator            */
#define  UPSRAM_RW_ADDR             0  /* Freq-hopping SRAM read/write initial address setting              */
#define  UPSRAM_DELSEL              1  /* Freq-hopping SRAM delay select setting                            */
#define  TDMA_FHCON2_DEFAULT        ((UPSRAM_BUSY << 15) | (UPSRAM_CS << 10) | (UPSRAM_DELSEL<< 8) | (UPSRAM_ATRIG << 7) | (UPSRAM_RW_ADDR))
/* -------------------------------------------------------------------------------------------------------- */
   
/* FHCON3 */
#define  TDMA_FHCON3_DEFAULT_INT    (2<<10)
/* -------------------------------------------------------------------------------------------------------- */
   
/* FHCON4 */
#define  MPLL_FSM_EN                1  /* MPLL fsm enable control                                           */
/* frequency hopping free run parameter */
#define  MNPLL_FRDDS_EN             1  /* FH_FREE_RUN_EN                                                    */
#define  MNPLL_FRDDS_DTS            1  /* FH_FREE_RUN_Time_STEP                                             */
#define  MNPLL_FRDDS_DYS            3  /* FH_FREE_RUN_Freq_STEP                                             */
/* frequency hopping soft start parameter */
#define  MNPLL_FHCTL_GSMEN          0  /* Enable the receiving of TDMA strobes for triggering soft start FH */
#define  MNPLL_SFSTR_EN             1  /* FH_SOFT_START_EN                                                  */
#define  MNPLL_SFSTR_DTS            1  /* FH_SOFT_START_Time_STEP                                           */
#define  MNPLL_SFSTR_DYS            2  /* FH_SOFT_START_Freq_STEP                                           */
#define  TDMA_FHCON4_DEFAULT        ((0x3)                    | (MNPLL_SFSTR_EN  <<  2) | (MNPLL_FRDDS_EN  << 3) | \
                                        (MNPLL_SFSTR_DTS  <<  4) | (MNPLL_SFSTR_DYS <<  6) | (MNPLL_FRDDS_DTS << 8) | \
                                        (MNPLL_FRDDS_DYS  << 12) | (MPLL_FSM_EN     << 15))
#define  L1D_SET_MNPLL_FH_TYPE()    HW_WRITE( TDMA_FHCON(4), TDMA_FHCON4_DEFAULT );
/* -------------------------------------------------------------------------------------------------------- */
   
/* FHCON5 */
#define  TDMA_FHCON5_FREE_RUN_RANGE      0x8500  /* 0 ~ -8%                                                 */
#define  L1D_SET_MNPLL_FREE_RUN_RANGE()  HW_WRITE( TDMA_FHCON(5), TDMA_FHCON5_FREE_RUN_RANGE );
/* -------------------------------------------------------------------------------------------------------- */

/* FHCON6 */
/* There is no EFPLL in MT6261 */
#define  L1D_SET_EFPLL_FH_TYPE()    
/* -------------------------------------------------------------------------------------------------------- */

/* FHCON7 */
/* There is no EFPLL in MT6261 */
#define  L1D_SET_EFPLL_FREE_RUN_RANGE()  
/* -------------------------------------------------------------------------------------------------------- */

   typedef struct
   {
      sFHset FHset_Modem;
   } L1DFHParamUDVT;
/* -------------------------------------------------------------------------------------------------------- */

   #elif  IS_CHIP_MT6260
#define  FREE_RUN_BASE              0

/* FHCON0 */
#define  TDMA_FHCON0_MASK           0xFCFF
/* -------------------------------------------------------------------------------------------------------- */

/* FHCON2 */
#define  UPSRAM_BUSY                0  /* Freq-hopping SRAM operation busy indicator                        */
#define  UPSRAM_CS                  1  /* Freq-hopping SRAM chip-select                                     */
#define  UPSRAM_ATRIG               0  /* Freq-hopping SRAM R/W address initialization indicator            */
#define  UPSRAM_RW_ADDR             0  /* Freq-hopping SRAM read/write initial address setting              */
#define  UPSRAM_DELSEL              1  /* Freq-hopping SRAM delay select setting                            */
#define  TDMA_FHCON2_DEFAULT        ((UPSRAM_BUSY << 15) | (UPSRAM_CS << 10) | (UPSRAM_DELSEL<< 8) | (UPSRAM_ATRIG << 7) | (UPSRAM_RW_ADDR))
/* -------------------------------------------------------------------------------------------------------- */

/* FHCON3 */
#define  TDMA_FHCON3_DEFAULT_INT    (2<<10)
/* -------------------------------------------------------------------------------------------------------- */

/* FHCON4 */
#define  MPLL_FSM_EN                1  /* MPLL fsm enable control                                           */
/* frequency hopping free run parameter */
#define  MNPLL_FRDDS_EN             1  /* FH_FREE_RUN_EN                                                    */
#define  MNPLL_FRDDS_DTS            2  /* FH_FREE_RUN_Time_STEP                                             */
#define  MNPLL_FRDDS_DYS            3  /* FH_FREE_RUN_Freq_STEP                                             */
/* frequency hopping soft start parameter */
#define  MNPLL_FHCTL_GSMEN          0  /* Enable the receiving of TDMA strobes for triggering soft start FH */
#define  MNPLL_SFSTR_EN             1  /* FH_SOFT_START_EN                                                  */
#define  MNPLL_SFSTR_DTS            2  /* FH_SOFT_START_Time_STEP                                           */
#define  MNPLL_SFSTR_DYS            2  /* FH_SOFT_START_Freq_STEP                                           */
#define  TDMA_FHCON4_DEFAULT        ((0x3)                    | (MNPLL_SFSTR_EN  <<  2) | (MNPLL_FRDDS_EN  << 3) | \
                                     (MNPLL_SFSTR_DTS  <<  4) | (MNPLL_SFSTR_DYS <<  6) | (MNPLL_FRDDS_DTS << 8) | \
                                     (MNPLL_FRDDS_DYS  << 12) | (MPLL_FSM_EN     << 15))
#define  L1D_SET_MNPLL_FH_TYPE()    HW_WRITE( TDMA_FHCON(4), TDMA_FHCON4_DEFAULT );
/* -------------------------------------------------------------------------------------------------------- */

/* FHCON5 */
#define  TDMA_FHCON5_FREE_RUN_RANGE      0x8500  /* 0 ~ -8%                                                 */
#define  L1D_SET_MNPLL_FREE_RUN_RANGE()  HW_WRITE( TDMA_FHCON(5), TDMA_FHCON5_FREE_RUN_RANGE );
/* -------------------------------------------------------------------------------------------------------- */

/* FHCON6 */
#define  EPLL_FSM_EN                1  /* MPLL fsm enable control                                           */
/* frequency hopping free run parameter */
#define  EPLL_FRDDS_EN              1  /* FH_FREE_RUN_EN                                                    */
#define  EPLL_FRDDS_DTS             2  /* FH_FREE_RUN_Time_STEP                                             */
#define  EPLL_FRDDS_DYS             3  /* FH_FREE_RUN_Freq_STEP                                             */
/* frequency hopping soft start parameter */
#define  EPLL_FHCTL_GSMEN           0  /* Enable the receiving of TDMA strobes for triggering soft start FH */
#define  EPLL_SFSTR_EN              1  /* FH_SOFT_START_EN                                                  */
#define  EPLL_SFSTR_DTS             2  /* FH_SOFT_START_Time_STEP                                           */
#define  EPLL_SFSTR_DYS             2  /* FH_SOFT_START_Freq_STEP                                           */
#define  TDMA_FHCON6_DEFAULT        ((0x3)                   | (EPLL_SFSTR_EN  <<  2) | (EPLL_FRDDS_EN  << 3) | \
                                     (EPLL_SFSTR_DTS  <<  4) | (EPLL_SFSTR_DYS <<  6) | (EPLL_FRDDS_DTS << 8) | \
                                     (EPLL_FRDDS_DYS  << 12) | (EPLL_FSM_EN     << 15))
#define  L1D_SET_EFPLL_FH_TYPE()    HW_WRITE( TDMA_FHCON(4), TDMA_FHCON6_DEFAULT );
/* -------------------------------------------------------------------------------------------------------- */

/* FHCON7 */
#define  TDMA_FHCON7_FREE_RUN_RANGE      0x8500  /* 0 ~ -8%                                                 */
#define  L1D_SET_EFPLL_FREE_RUN_RANGE()  HW_WRITE( TDMA_FHCON(5), TDMA_FHCON7_FREE_RUN_RANGE );
/* -------------------------------------------------------------------------------------------------------- */

typedef struct
{
   sFHset FHset_Modem;
} L1DFHParamUDVT;
/* -------------------------------------------------------------------------------------------------------- */

   #elif IS_CHIP_MT6250
#define  FREE_RUN_BASE              0

/* FHCON0 */
#define  TDMA_FHCON0_MASK           0xFCFF
/* -------------------------------------------------------------------------------------------------------- */

/* FHCON2 */
#define  UPSRAM_BUSY                0  /* Freq-hopping SRAM operation busy indicator                        */
#define  UPSRAM_CS                  1  /* Freq-hopping SRAM chip-select                                     */
#define  UPSRAM_ATRIG               0  /* Freq-hopping SRAM R/W address initialization indicator            */
#define  UPSRAM_RW_ADDR             0  /* Freq-hopping SRAM read/write initial address setting              */
#define  UPSRAM_DELSEL              1  /* Freq-hopping SRAM delay select setting                            */
#define  TDMA_FHCON2_DEFAULT        ((UPSRAM_BUSY << 15) | (UPSRAM_CS << 10) | (UPSRAM_DELSEL<< 8) | (UPSRAM_ATRIG << 7) | (UPSRAM_RW_ADDR))
/* -------------------------------------------------------------------------------------------------------- */

/* FHCON3 */
#define  TDMA_FHCON3_DEFAULT_INT    (2<<10)
/* -------------------------------------------------------------------------------------------------------- */

/* FHCON4 */
#define  MPLL_FSM_EN                1  /* MPLL fsm enable control                                           */
/* frequency hopping free run parameter */
#define  MNPLL_FRDDS_EN             1  /* FH_FREE_RUN_EN                                                    */
#define  MNPLL_FRDDS_DTS            1  /* FH_FREE_RUN_Time_STEP                                             */
#define  MNPLL_FRDDS_DYS            3  /* FH_FREE_RUN_Freq_STEP                                             */
/* frequency hopping soft start parameter */
#define  MNPLL_FHCTL_GSMEN          0  /* Enable the receiving of TDMA strobes for triggering soft start FH */
#define  MNPLL_SFSTR_EN             1  /* FH_SOFT_START_EN                                                  */
#define  MNPLL_SFSTR_DTS            1  /* FH_SOFT_START_Time_STEP                                           */
#define  MNPLL_SFSTR_DYS            2  /* FH_SOFT_START_Freq_STEP                                           */
#define  TDMA_FHCON4_DEFAULT        ((0x3)                    | (MNPLL_SFSTR_EN  <<  2) | (MNPLL_FRDDS_EN  << 3) | \
                                     (MNPLL_SFSTR_DTS  <<  4) | (MNPLL_SFSTR_DYS <<  6) | (MNPLL_FRDDS_DTS << 8) | \
                                     (MNPLL_FRDDS_DYS  << 12) | (MPLL_FSM_EN     << 15))
#define  L1D_SET_MNPLL_FH_TYPE()    HW_WRITE( TDMA_FHCON(4), TDMA_FHCON4_DEFAULT );
/* There is no EFPLL in MT6250 */
#define  L1D_SET_EFPLL_FH_TYPE()
/* -------------------------------------------------------------------------------------------------------- */

/* FHCON5 */
#define  TDMA_FHCON5_FREE_RUN_RANGE      0x1D00  /* 0 ~ -1.85% (97.5 * 0.98147 = 95.693MHz > 104 * 0.92 = 95.68MHz) */
#define  L1D_SET_MNPLL_FREE_RUN_RANGE()  HW_WRITE( TDMA_FHCON(5), TDMA_FHCON5_FREE_RUN_RANGE );
/* There is no EFPLL in MT6250 */
#define  L1D_SET_EFPLL_FREE_RUN_RANGE()
/* -------------------------------------------------------------------------------------------------------- */

typedef struct
{
   sFHset FHset_Modem;
} L1DFHParamUDVT;
/* -------------------------------------------------------------------------------------------------------- */
   #endif
#endif // IS_UDVT_FH_SUPPORT

#endif

