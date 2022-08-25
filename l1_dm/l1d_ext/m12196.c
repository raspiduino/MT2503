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
 *   m12196.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Turn on/off RF components
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *  HISTORY
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
 *==============================================================================
 *******************************************************************************/

#include "l1d_cid.h"
#include "l1d_reg.h"
#include "l1d_custom_rf.h"
#include "l1d_rf.h"
#include "m12190.h"

/*---------------------------------------------------------------------------*/

#if IS_RF_BRIGHT2
/*BRIGHT2*/ #if IS_FPGA_TARGET
/* under construction !*/
/*BRIGHT2*/ #else
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
/*BRIGHT4*/ #ifndef  L1D_SIM
/* under construction !*/
/*BRIGHT4*/    #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*BRIGHT4*/    #else
/* under construction !*/
/*BRIGHT4*/    #endif
/*BRIGHT4*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT4*/ #ifndef  L1D_SIM
/* under construction !*/
/*BRIGHT4*/    #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*BRIGHT4*/    #else
/* under construction !*/
/*BRIGHT4*/    #endif
/*BRIGHT4*/ #endif
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
/*AERO*/ #ifdef  EXT_26M
/* under construction !*/
/*AERO*/ #else
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #ifdef  EXT_26M
/* under construction !*/
/*AERO*/ #else
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*AERO*/ #else
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*AERO1+*/ #ifdef  EXT_26M
/* under construction !*/
/*AERO1+*/ #else
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #ifdef  EXT_26M
/* under construction !*/
/*AERO1+*/ #else
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/*AERO1+*/ #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*AERO1+*/ #else
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*RFMD*/ #ifndef  L1D_SIM
/*RFMD*/    #ifndef RFVCO_SW_CONTROL /* HW control */
/*RFMD*/       #if IS_CHIP_MT6205
/* under construction !*/
/*RFMD*/       /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*RFMD*/       /*MT6205*/       #else
/* under construction !*/
/*RFMD*/       /*MT6205*/       #endif
/* under construction !*/
/*RFMD*/       #endif
/*RFMD*/       #if IS_CHIP_MT6218A
/* under construction !*/
/*RFMD*/       /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*RFMD*/       /*MT6218A*/      #else
/* under construction !*/
/*RFMD*/       /*MT6218A*/      #endif
/* under construction !*/
/*RFMD*/       #endif
/*RFMD*/       #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*RFMD*/       /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*RFMD*/       /*MT6218B~*/     #else
/* under construction !*/
/*RFMD*/       /*MT6218B~*/     #endif
/* under construction !*/
/*RFMD*/       #endif
/*RFMD*/    #endif
/*RFMD*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*RFMD*/ #ifndef  L1D_SIM
/*RFMD*/    #ifndef RFVCO_SW_CONTROL /* HW control */
/*RFMD*/       #if IS_CHIP_MT6205
/* under construction !*/
/*RFMD*/       /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*RFMD*/       /*MT6205*/       #else
/* under construction !*/
/*RFMD*/       /*MT6205*/       #endif
/* under construction !*/
/*RFMD*/       #endif
/*RFMD*/       #if IS_CHIP_MT6218A
/* under construction !*/
/*RFMD*/       /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*RFMD*/       /*MT6218A*/      #else
/* under construction !*/
/*RFMD*/       /*MT6218A*/      #endif
/* under construction !*/
/*RFMD*/       #endif
/*RFMD*/       #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*RFMD*/       /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*RFMD*/       /*MT6218B~*/     #else
/* under construction !*/
/*RFMD*/       /*MT6218B~*/     #endif
/* under construction !*/
/*RFMD*/       #endif
/*RFMD*/    #endif
/*RFMD*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*SKY74117*/ #if IS_CHIP_MT6218B_AND_LATTER_VERSION
/* under construction !*/
/*SKY74117*/ /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*SKY74117*/ /*MT6218B~*/     #else
/* under construction !*/
/*SKY74117*/ /*MT6218B~*/     #endif
/* under construction !*/
/*SKY74117*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74117*/ #if IS_CHIP_MT6218B_AND_LATTER_VERSION
/* under construction !*/
/*SKY74117*/ /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*SKY74117*/ /*MT6218B~*/     #else
/* under construction !*/
/*SKY74117*/ /*MT6218B~*/     #endif
/* under construction !*/
/*SKY74117*/ #endif
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
#endif

#if IS_RF_MT6119C
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6119C*/ #ifdef RFVCO_SW_CONTROL
/* under construction !*/
/*MT6119C*/ #else
/* under construction !*/
/*MT6119C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6119C*/    #ifndef L1D_SIM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6119C*/    #endif
/* under construction !*/
/* under construction !*/
/*MT6119C*/ #ifndef  L1D_SIM
/*MT6119C*/    #ifndef RFVCO_SW_CONTROL /* HW control */
/*MT6119C*/       #if IS_CHIP_MT6205
/* under construction !*/
/*MT6119C*/       /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6119C*/       /*MT6205*/       #else
/* under construction !*/
/*MT6119C*/       /*MT6205*/       #endif
/* under construction !*/
/*MT6119C*/       #endif
/*MT6119C*/       #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6119C*/       /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6119C*/       /*MT6218A*/      #else
/* under construction !*/
/*MT6119C*/       /*MT6218A*/      #endif
/* under construction !*/
/*MT6119C*/       #endif
/*MT6119C*/       #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6119C*/       /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6119C*/       /*MT6218B~*/     #else
/* under construction !*/
/*MT6119C*/       /*MT6218B~*/     #endif
/* under construction !*/
/*MT6119C*/       #endif
/*MT6119C*/    #endif
/*MT6119C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6119C*/ #ifndef  L1D_SIM
/*MT6119C*/    #ifndef RFVCO_SW_CONTROL /* HW control */
/*MT6119C*/       #if IS_CHIP_MT6205
/* under construction !*/
/*MT6119C*/       /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6119C*/       /*MT6205*/       #else
/* under construction !*/
/*MT6119C*/       /*MT6205*/       #endif
/* under construction !*/
/*MT6119C*/       #endif
/*MT6119C*/       #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6119C*/       /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6119C*/       /*MT6218A*/      #else
/* under construction !*/
/*MT6119C*/       /*MT6218A*/      #endif
/* under construction !*/
/*MT6119C*/       #endif
/*MT6119C*/       #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6119C*/       /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6119C*/       /*MT6218B~*/     #else
/* under construction !*/
/*MT6119C*/       /*MT6218B~*/     #endif
/* under construction !*/
/*MT6119C*/       #endif
/*MT6119C*/    #endif
/*MT6119C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*MT6129A*/ #ifdef RFVCO_SW_CONTROL
/* under construction !*/
/*MT6129A*/ #else
/* under construction !*/
/*MT6129A*/ #endif
/* under construction !*/
/* under construction !*/
/*MT6129A*/ #ifndef L1D_SIM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6129A*/ #endif
/* under construction !*/
/* under construction !*/
/*MT6129A*/ #ifndef  L1D_SIM
/*MT6129A*/  #ifndef RFVCO_SW_CONTROL
/*MT6129A*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6129A*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129A*/    /*MT6205*/       #else
/* under construction !*/
/*MT6129A*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6129A*/    #endif
/*MT6129A*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6129A*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129A*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6129A*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6129A*/    #endif
/*MT6129A*/    #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6129A*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129A*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6129A*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6129A*/    #endif
/*MT6129A*/  #endif
/*MT6129A*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6129A*/ #ifndef  L1D_SIM
/*MT6129A*/  #ifndef RFVCO_SW_CONTROL
/*MT6129A*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6129A*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129A*/    /*MT6205*/       #else
/* under construction !*/
/*MT6129A*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6129A*/    #endif
/*MT6129A*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6129A*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129A*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6129A*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6129A*/    #endif
/*MT6129A*/    #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6129A*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129A*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6129A*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6129A*/    #endif
/*MT6129A*/  #endif
/*MT6129A*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*MT6129B*/ #ifdef RFVCO_SW_CONTROL
/* under construction !*/
/*MT6129B*/ #else
/* under construction !*/
/*MT6129B*/ #endif
/* under construction !*/
/* under construction !*/
/*MT6129B*/ #ifndef L1D_SIM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6129B*/ #endif
/* under construction !*/
/* under construction !*/
/*MT6129B*/ #ifndef  L1D_SIM
/*MT6129B*/  #ifndef RFVCO_SW_CONTROL
/*MT6129B*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6129B*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129B*/    /*MT6205*/       #else
/* under construction !*/
/*MT6129B*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6129B*/    #endif
/*MT6129B*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6129B*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129B*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6129B*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6129B*/    #endif
/*MT6129B*/    #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6129B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129B*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6129B*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6129B*/    #endif
/*MT6129B*/  #endif
/*MT6129B*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6129B*/ #ifndef  L1D_SIM
/*MT6129B*/  #ifndef RFVCO_SW_CONTROL
/*MT6129B*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6129B*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129B*/    /*MT6205*/       #else
/* under construction !*/
/*MT6129B*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6129B*/    #endif
/*MT6129B*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6129B*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129B*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6129B*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6129B*/    #endif
/*MT6129B*/    #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6129B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129B*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6129B*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6129B*/    #endif
/*MT6129B*/  #endif
/*MT6129B*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*MT6129C*/ #ifdef RFVCO_SW_CONTROL
/* under construction !*/
/*MT6129C*/ #else
/* under construction !*/
/*MT6129C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6129C*/ #ifndef L1D_SIM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6129C*/ #endif
/* under construction !*/
/* under construction !*/
/*MT6129C*/ #ifndef  L1D_SIM
/*MT6129C*/  #ifndef RFVCO_SW_CONTROL
/*MT6129C*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6129C*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129C*/    /*MT6205*/       #else
/* under construction !*/
/*MT6129C*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6129C*/    #endif
/*MT6129C*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6129C*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129C*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6129C*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6129C*/    #endif
/*MT6129C*/    #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6129C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129C*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6129C*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6129C*/    #endif
/*MT6129C*/  #endif
/*MT6129C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6129C*/ #ifndef  L1D_SIM
/*MT6129C*/  #ifndef RFVCO_SW_CONTROL
/*MT6129C*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6129C*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129C*/    /*MT6205*/       #else
/* under construction !*/
/*MT6129C*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6129C*/    #endif
/*MT6129C*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6129C*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129C*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6129C*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6129C*/    #endif
/*MT6129C*/    #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6129C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6129C*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6129C*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6129C*/    #endif
/*MT6129C*/  #endif
/*MT6129C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*MT6129D*/ void  L1D_RF_PowerOn( void )
/*MT6129D*/ {
/*MT6129D*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6129D*/    IMM_SEND_BPI( 0x0000 );
/*MT6129D*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x200000 );
/*MT6129D*/ #ifdef RFVCO_SW_CONTROL
/*MT6129D*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1A8080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6129D*/ #else
/*MT6129D*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x188080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6129D*/ #endif
/*MT6129D*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x0002C6 );
/*MT6129D*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x124982 );
/*MT6129D*/ #ifndef L1D_SIM
/*MT6129D*/    if(l1d_rf.is_init)
/*MT6129D*/    {  /* for power on tx calibration, we program mt6119 to TX mode */
/*MT6129D*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x128982L );
/*MT6129D*/    }
/*MT6129D*/ #endif
/*MT6129D*/    IMM_MODE_END(  );
/*MT6129D*/
/*MT6129D*/ #ifndef  L1D_SIM
/*MT6129D*/  #ifndef RFVCO_SW_CONTROL
/*MT6129D*/    #if IS_CHIP_MT6205
/*MT6129D*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6205*/       #else
/*MT6129D*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6129D*/    /*MT6205*/       #endif
/*MT6129D*/    /*MT6205*/    }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6218A
/*MT6129D*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6218A*/      #else
/*MT6129D*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,10);
/*MT6129D*/    /*MT6218A*/      #endif
/*MT6129D*/    /*MT6218A*/   }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219 || IS_CHIP_MT6227
/*MT6129D*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6218B~*/     #else
/*MT6129D*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,13);
/*MT6129D*/    /*MT6218B~*/     #endif
/*MT6129D*/    /*MT6218B~*/  }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6228 || IS_CHIP_MT6229
/*MT6129D*/    /*MT6228B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6228B~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6228B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6228B~*/     #else
/*MT6129D*/    /*MT6228B~*/     L1D_GPIO_WriteIO(1,19);
/*MT6129D*/    /*MT6228B~*/     #endif
/*MT6129D*/    /*MT6228B~*/  }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6225_AND_LATTER_VERSION
/*MT6129D*/    /*MT6225~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6225~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6225~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6225~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6225~*/     #else
/*MT6129D*/    /*MT6225~*/     L1D_GPIO_WriteIO(1,28);
/*MT6129D*/    /*MT6225~*/     #endif
/*MT6129D*/    /*MT6225~*/  }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
/*MT6129D*/    /*MT6223~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6223~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6223~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6223~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6223~*/     #else
/*MT6129D*/    /*MT6223~*/     L1D_GPIO_WriteIO(1,23);
/*MT6129D*/    /*MT6223~*/     #endif
/*MT6129D*/    /*MT6223~*/  }
/*MT6129D*/    #endif
/*MT6129D*/  #endif
/*MT6129D*/ #endif
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_PowerOff( void )
/*MT6129D*/ {
/*MT6129D*/ #ifndef  L1D_SIM
/*MT6129D*/  #ifndef RFVCO_SW_CONTROL
/*MT6129D*/    #if IS_CHIP_MT6205
/*MT6129D*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6205*/    #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6205*/    extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6205*/    #else
/*MT6129D*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6129D*/    /*MT6205*/    #endif
/*MT6129D*/    /*MT6205*/    }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6218A
/*MT6129D*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6218A*/      #else
/*MT6129D*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,10);
/*MT6129D*/    /*MT6218A*/      #endif
/*MT6129D*/    /*MT6218A*/   }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219 || IS_CHIP_MT6227
/*MT6129D*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6218B~*/     #else
/*MT6129D*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,13);
/*MT6129D*/    /*MT6218B~*/     #endif
/*MT6129D*/    /*MT6218B~*/  }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6228 || IS_CHIP_MT6229
/*MT6129D*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6218B~*/     #else
/*MT6129D*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,19);
/*MT6129D*/    /*MT6218B~*/     #endif
/*MT6129D*/    /*MT6218B~*/  }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6225_AND_LATTER_VERSION
/*MT6129D*/    /*MT6225~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6225~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6225~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6225~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6225~*/     #else
/*MT6129D*/    /*MT6225~*/     L1D_GPIO_WriteIO(0,28);
/*MT6129D*/    /*MT6225~*/     #endif
/*MT6129D*/    /*MT6225~*/  }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
/*MT6129D*/    /*MT6223~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6223~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6223~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6223~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6223~*/     #else
/*MT6129D*/    /*MT6223~*/     L1D_GPIO_WriteIO(0,23);
/*MT6129D*/    /*MT6223~*/     #endif
/*MT6129D*/    /*MT6223~*/  }
/*MT6129D*/    #endif
/*MT6129D*/  #endif
/*MT6129D*/ #endif
/*MT6129D*/
/*MT6129D*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6129D*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x120982 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MT6129D*/    IMM_MODE_END(  );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_WindowOn( void )
/*MT6129D*/ {  }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_WindowOff( void )
/*MT6129D*/ {  }
/*MT6129D*/
#endif

#if IS_RF_MT6139B
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6139B*/ #ifdef RFVCO_SW_CONTROL
/* under construction !*/
/*MT6139B*/ #else
/* under construction !*/
/*MT6139B*/ #endif
/* under construction !*/
/* under construction !*/
/*MT6139B*/ #ifndef L1D_SIM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6139B*/ #endif
/* under construction !*/
/* under construction !*/
/*MT6139B*/ #ifndef  L1D_SIM
/*MT6139B*/  #ifndef RFVCO_SW_CONTROL
/*MT6139B*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6139B*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139B*/    /*MT6205*/       #else
/* under construction !*/
/*MT6139B*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6139B*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139B*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6139B*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219 || IS_CHIP_MT6227
/* under construction !*/
/*MT6139B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139B*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6139B*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6228 || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6139B*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139B*/    /*MT6228B~*/     #else
/* under construction !*/
/*MT6139B*/    /*MT6228B~*/     #endif
/* under construction !*/
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6225_AND_LATTER_VERSION
/* under construction !*/
/*MT6139B*/    /*MT6225~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139B*/    /*MT6225~*/     #else
/* under construction !*/
/*MT6139B*/    /*MT6225~*/     #endif
/* under construction !*/
/*MT6139B*/    #endif
/*MT6139B*/  #endif
/*MT6139B*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6139B*/ #ifndef  L1D_SIM
/*MT6139B*/  #ifndef RFVCO_SW_CONTROL
/*MT6139B*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6139B*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139B*/    /*MT6205*/       #else
/* under construction !*/
/*MT6139B*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6139B*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139B*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6139B*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6291 || IS_CHIP_MT6227
/* under construction !*/
/*MT6139B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139B*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6139B*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6228 || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6139B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139B*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6139B*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6225_AND_LATTER_VERSION
/* under construction !*/
/*MT6139B*/    /*MT6225~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139B*/    /*MT6225~*/     #else
/* under construction !*/
/*MT6139B*/    /*MT6225~*/     #endif
/* under construction !*/
/*MT6139B*/    #endif
/*MT6139B*/  #endif
/*MT6139B*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*MT6139C*/ #ifdef RFVCO_SW_CONTROL
/* under construction !*/
/*MT6139C*/ #else
/* under construction !*/
/*MT6139C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6139C*/ #ifndef L1D_SIM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6139C*/ #endif
/* under construction !*/
/* under construction !*/
/*MT6139C*/ #ifndef  L1D_SIM
/*MT6139C*/  #ifndef RFVCO_SW_CONTROL
/*MT6139C*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6139C*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139C*/    /*MT6205*/       #else
/* under construction !*/
/*MT6139C*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6139C*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139C*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6139C*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219 || IS_CHIP_MT6227
/* under construction !*/
/*MT6139C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139C*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6139C*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6228 || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6225_AND_LATTER_VERSION
/* under construction !*/
/*MT6139C*/    /*MT6225~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139C*/    /*MT6225~*/     #else
/* under construction !*/
/*MT6139C*/    /*MT6225~*/     #endif
/* under construction !*/
/*MT6139C*/    #endif
/*MT6139C*/  #endif
/*MT6139C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6139C*/ #ifndef  L1D_SIM
/*MT6139C*/  #ifndef RFVCO_SW_CONTROL
/*MT6139C*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6139C*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139C*/    /*MT6205*/       #else
/* under construction !*/
/*MT6139C*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6139C*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139C*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6139C*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219 || IS_CHIP_MT6227
/* under construction !*/
/*MT6139C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139C*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6139C*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6228 || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6139C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139C*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6139C*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6225_AND_LATTER_VERSION
/* under construction !*/
/*MT6139C*/    /*MT6225~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6139C*/    /*MT6225~*/     #else
/* under construction !*/
/*MT6139C*/    /*MT6225~*/     #endif
/* under construction !*/
/*MT6139C*/    #endif
/*MT6139C*/  #endif
/*MT6139C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*MT6139E*/ void  L1D_RF_PowerOn( void )
/*MT6139E*/ {
/*MT6139E*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6139E*/    IMM_SEND_BPI( 0x0000 );
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0024080 ); //CW0
/*MT6139E*/ #ifdef RFVCO_SW_CONTROL
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0008080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6139E*/ #else
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6139E*/ #endif
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x00E0809 ); //CW9: Power down AM & A DAC
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x000000A ); //CW10: Init AM code
/*MT6139E*/  //IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0002802 ); //CW2: Enter Stand-by mode
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0002002 ); //CW2: Enter Sleep mode
/*MT6139E*/ #ifndef L1D_SIM
/*MT6139E*/    if(l1d_rf.is_init)
/*MT6139E*/    {  /* for power on tx calibration, we program mt61xx to TX mode */
/*MT6139E*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0003002L );
/*MT6139E*/    }
/*MT6139E*/ #endif
/*MT6139E*/    IMM_MODE_END(  );
/*MT6139E*/
/*MT6139E*/ #ifndef  L1D_SIM
/*MT6139E*/  #ifndef RFVCO_SW_CONTROL
/*MT6139E*/    #if IS_CHIP_MT6205
/*MT6139E*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6139E*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6139E*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6139E*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6139E*/    /*MT6205*/       #else
/*MT6139E*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6139E*/    /*MT6205*/       #endif
/*MT6139E*/    /*MT6205*/    }
/*MT6139E*/    #endif
/*MT6139E*/  #endif
/*MT6139E*/ #endif
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_PowerOff( void )
/*MT6139E*/ {
/*MT6139E*/ #ifndef  L1D_SIM
/*MT6139E*/  #ifndef RFVCO_SW_CONTROL
/*MT6139E*/    #if IS_CHIP_MT6205
/*MT6139E*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6139E*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6139E*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6139E*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6139E*/    /*MT6205*/       #else
/*MT6139E*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6139E*/    /*MT6205*/       #endif
/*MT6139E*/    /*MT6205*/    }
/*MT6139E*/    #endif
/*MT6139E*/  #endif
/*MT6139E*/ #endif
/*MT6139E*/
/*MT6139E*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000002 ); /* MT61xx enters Sleep mode, turn off RF regulators */
/*MT6139E*/    IMM_MODE_END(  );
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_WindowOn( void )
/*MT6139E*/ {  }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_WindowOff( void )
/*MT6139E*/ {  }
/*MT6139E*/
#endif

#if IS_RF_MT6140A
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140A*/ #ifdef RFVCO_SW_CONTROL
/* under construction !*/
/*MT6140A*/ #else
/* under construction !*/
/*MT6140A*/ #endif
/* under construction !*/
/* under construction !*/
/*MT6140A*/ #ifndef L1D_SIM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140A*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140A*/ #ifndef  L1D_SIM
/*MT6140A*/  #ifndef RFVCO_SW_CONTROL
/*MT6140A*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6140A*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140A*/    /*MT6205*/       #else
/* under construction !*/
/*MT6140A*/    /*MT6205*/      #endif
/* under construction !*/
/*MT6140A*/    #endif
/*MT6140A*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6140A*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140A*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6140A*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6140A*/    #endif
/*MT6140A*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*MT6140A*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140A*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140A*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140A*/    #endif
/*MT6140A*/    #if IS_CHIP_MT6228_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6140A*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140A*/    /*MT6228B~*/     #else
/* under construction !*/
/*MT6140A*/    /*MT6228B~*/     #endif
/* under construction !*/
/*MT6140A*/    #endif
/*MT6140A*/  #endif
/*MT6140A*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140A*/ #ifndef  L1D_SIM
/*MT6140A*/  #ifndef RFVCO_SW_CONTROL
/*MT6140A*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6140A*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140A*/    /*MT6205*/       #else
/* under construction !*/
/*MT6140A*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6140A*/    #endif
/*MT6140A*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6140A*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140A*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6140A*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6140A*/    #endif
/*MT6140A*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*MT6140A*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140A*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140A*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140A*/    #endif
/*MT6140A*/    #if IS_CHIP_MT6228_AND_LATTER_VERSION  || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6140A*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140A*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140A*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140A*/    #endif
/*MT6140A*/  #endif
/*MT6140A*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*MT6140B*/ #ifdef RFVCO_SW_CONTROL
/* under construction !*/
/*MT6140B*/ #else
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
/*MT6140B*/ #ifndef L1D_SIM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140B*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140B*/ #ifndef  L1D_SIM
/*MT6140B*/  #ifndef RFVCO_SW_CONTROL
/*MT6140B*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6140B*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140B*/    /*MT6205*/       #else
/* under construction !*/
/*MT6140B*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6140B*/    #endif
/*MT6140B*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6140B*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140B*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6140B*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6140B*/    #endif
/*MT6140B*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*MT6140B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140B*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140B*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140B*/    #endif
/*MT6140B*/    #if IS_CHIP_MT6228_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6140B*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140B*/    /*MT6228B~*/     #else
/* under construction !*/
/*MT6140B*/    /*MT6228B~*/     #endif
/* under construction !*/
/*MT6140B*/    #endif
/*MT6140B*/  #endif
/*MT6140B*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140B*/ #ifndef  L1D_SIM
/*MT6140B*/  #ifndef RFVCO_SW_CONTROL
/*MT6140B*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6140B*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140B*/    /*MT6205*/       #else
/* under construction !*/
/*MT6140B*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6140B*/    #endif
/*MT6140B*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6140B*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140B*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6140B*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6140B*/    #endif
/*MT6140B*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*MT6140B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140B*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140B*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140B*/    #endif
/*MT6140B*/    #if IS_CHIP_MT6228_AND_LATTER_VERSION  || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6140B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140B*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140B*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140B*/    #endif
/*MT6140B*/  #endif
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
/*MT6140C*/ #ifdef RFVCO_SW_CONTROL
/* under construction !*/
/*MT6140C*/ #else
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
/*MT6140C*/ #ifndef L1D_SIM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140C*/ #endif
/* under construction !*/
/* under construction !*/
/*MT6140C*/ #ifndef  L1D_SIM
/*MT6140C*/  #ifndef RFVCO_SW_CONTROL
/*MT6140C*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6140C*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140C*/    /*MT6205*/       #else
/* under construction !*/
/*MT6140C*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6140C*/    #endif
/*MT6140C*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6140C*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140C*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6140C*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6140C*/    #endif
/*MT6140C*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*MT6140C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140C*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140C*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140C*/    #endif
/*MT6140C*/    #if IS_CHIP_MT6228_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6140C*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140C*/    /*MT6228B~*/     #else
/* under construction !*/
/*MT6140C*/    /*MT6228B~*/     #endif
/* under construction !*/
/*MT6140C*/    #endif
/*MT6140C*/  #endif
/*MT6140C*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6140C*/ #ifndef  L1D_SIM
/*MT6140C*/  #ifndef RFVCO_SW_CONTROL
/*MT6140C*/    #if IS_CHIP_MT6205
/* under construction !*/
/*MT6140C*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140C*/    /*MT6205*/       #else
/* under construction !*/
/*MT6140C*/    /*MT6205*/       #endif
/* under construction !*/
/*MT6140C*/    #endif
/*MT6140C*/    #if IS_CHIP_MT6218A
/* under construction !*/
/*MT6140C*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140C*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6140C*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6140C*/    #endif
/*MT6140C*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*MT6140C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140C*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140C*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140C*/    #endif
/*MT6140C*/    #if IS_CHIP_MT6228_AND_LATTER_VERSION  || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6140C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140C*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140C*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140C*/    #endif
/*MT6140C*/  #endif
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
#endif

#if IS_RF_MT6140D
/*MT6140D*/ unsigned long SDATA_TABLE[14]=
/*MT6140D*/ {
/*MT6140D*/    0x0004090,// 0:CW0  //BSI controlled mode switching & SYNCP=1
/*MT6140D*/    0x013F001,// 1:CW1
/*MT6140D*/    0x20823E2,// 2:CW2
/*MT6140D*/    0x07F3FF3,// 3:CW3
/*MT6140D*/    0x00A8714,// 4:CW4
/*MT6140D*/    0x00041F5,// 5:CW5
/*MT6140D*/    0x001D016,// 6:CW6
/*MT6140D*/    0x0001957,// 7:CW7
/*MT6140D*/    0x0FA0408,// 8:CW8
/*MT6140D*/    0x00E0409,// 9:CW9  //Disable AM&A DCOC //0x03E0409 :enable AM A DCOC
/*MT6140D*/    0x002040A,//10:CW10
/*MT6140D*/    0x200070B,//11:CW11
/*MT6140D*/    0x201370C,//12:CW12
/*MT6140D*/    0x000000F //13:CW15
/*MT6140D*/ };
/*MT6140D*/ void  L1D_RF_PowerOn( void )
/*MT6140D*/ {
/*MT6140D*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6140D*/    IMM_SEND_BPI( 0x0000 );
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0044090 ); //CW0
/*MT6140D*/ #ifdef RFVCO_SW_CONTROL
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0008090|(XO_CapID<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6140D*/ #else
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000090|(XO_CapID<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6140D*/ #endif
/*MT6140D*/    /* POR Start */
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[1] ); // 1:CW1
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[2] ); // 2:CW2,enter Sleep mode
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[3] ); // 3:CW3
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[4] ); // 4:CW4
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[5] ); // 5:CW5
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[6] ); // 6:CW6
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[7] ); // 7:CW7
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[8] ); // 8:CW8
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[9] ); // 9:CW9
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[10] );//10:CW10
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[11] );//11:CW11
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[12] );//12:CW12
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[13] );//13:CW15
/*MT6140D*/    /* POR End */
/*MT6140D*/ #ifndef L1D_SIM
/*MT6140D*/    if(l1d_rf.is_init)
/*MT6140D*/    {  /* for power on tx calibration, we program mt6140 to GSM TX mode */
/*MT6140D*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0003002L );
/*MT6140D*/    }
/*MT6140D*/ #endif
/*MT6140D*/    IMM_MODE_END(  );
/*MT6140D*/
/*MT6140D*/ #ifndef  L1D_SIM
/*MT6140D*/  #ifndef RFVCO_SW_CONTROL
/*MT6140D*/    #if IS_CHIP_MT6205
/*MT6140D*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6140D*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6140D*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6140D*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140D*/    /*MT6205*/       #else
/*MT6140D*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6140D*/    /*MT6205*/       #endif
/*MT6140D*/    /*MT6205*/    }
/*MT6140D*/    #endif
/*MT6140D*/    #if  0//IS_CHIP_MT6218A
/* under construction !*/
/*MT6140D*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140D*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6140D*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6140D*/    #endif
/*MT6140D*/    #if  0//IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140D*/    #endif
/*MT6140D*/    #if  0//IS_CHIP_MT6228_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6140D*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140D*/    /*MT6228B~*/     #else
/* under construction !*/
/*MT6140D*/    /*MT6228B~*/     #endif
/* under construction !*/
/*MT6140D*/    #endif
/*MT6140D*/  #endif
/*MT6140D*/ #endif
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_PowerOff( void )
/*MT6140D*/ {
/*MT6140D*/ #ifndef  L1D_SIM
/*MT6140D*/  #ifndef RFVCO_SW_CONTROL
/*MT6140D*/    #if IS_CHIP_MT6205
/*MT6140D*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6140D*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6140D*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6140D*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140D*/    /*MT6205*/       #else
/*MT6140D*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6140D*/    /*MT6205*/       #endif
/*MT6140D*/    /*MT6205*/    }
/*MT6140D*/    #endif
/*MT6140D*/    #if  0//IS_CHIP_MT6218A
/* under construction !*/
/*MT6140D*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140D*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6140D*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6140D*/    #endif
/*MT6140D*/    #if  0//IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140D*/    #endif
/*MT6140D*/    #if  0//IS_CHIP_MT6228_AND_LATTER_VERSION  || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140D*/    #endif
/*MT6140D*/  #endif
/*MT6140D*/ #endif
/*MT6140D*/
/*MT6140D*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000002 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MT6140D*/    IMM_MODE_END(  );
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_WindowOn( void )
/*MT6140D*/ {  }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_WindowOff( void )
/*MT6140D*/ {  }
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
/*CMOSEDGE*/ #ifndef L1D_SIM
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    #ifdef RFVCO_SW_CONTROL
/* under construction !*/
/*CMOSEDGE*/    #else
/* under construction !*/
/*CMOSEDGE*/    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/ #ifndef  L1D_SIM
/*CMOSEDGE*/  #ifndef RFVCO_SW_CONTROL
/*CMOSEDGE*/    #if IS_CHIP_MT6205
/* under construction !*/
/*CMOSEDGE*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6205*/       #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6205*/       #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/    #if  0//IS_CHIP_MT6218A
/* under construction !*/
/*CMOSEDGE*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6218A*/      #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6218A*/      #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/    #if  0//IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/    #if 0//IS_CHIP_MT6228_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*CMOSEDGE*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6228B~*/     #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6228B~*/     #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/  #endif
/*CMOSEDGE*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/ #ifndef  L1D_SIM
/*CMOSEDGE*/  #ifndef RFVCO_SW_CONTROL
/*CMOSEDGE*/    #if IS_CHIP_MT6205
/* under construction !*/
/*CMOSEDGE*/    /*MT6205*/       #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6205*/       #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6205*/       #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/    #if  0//IS_CHIP_MT6218A
/* under construction !*/
/*CMOSEDGE*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6218A*/      #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6218A*/      #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/    #if  0//IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/    #if  0//IS_CHIP_MT6228_AND_LATTER_VERSION  || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/  #endif
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
#endif

#if IS_RF_MTKSOC1T
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MTKSOC1T*/ #if IS_RF_MTKSOC1_A5
/* under construction !*/
/*MTKSOC1T*/ #else
/* under construction !*/
/*MTKSOC1T*/ #endif
/* under construction !*/
/*MTKSOC1T*/ #if IS_RF_MTKSOC1_A2 || IS_RF_MTKSOC1_A3 || IS_RF_MTKSOC1_A4
/* under construction !*/
/*MTKSOC1T*/ #else
/* under construction !*/
/*MTKSOC1T*/ #endif
/* under construction !*/
/*MTKSOC1T*/ #if IS_RF_MTKSOC1_A4
/* under construction !*/
/*MTKSOC1T*/ #else
/* under construction !*/
/*MTKSOC1T*/ #endif
/* under construction !*/
/*MTKSOC1T*/ #if IS_RF_MTKSOC1_A2 || IS_RF_MTKSOC1_A3 || IS_RF_MTKSOC1_A4
/* under construction !*/
/*MTKSOC1T*/ #else
/* under construction !*/
/*MTKSOC1T*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if IS_RF_MTKSOC1
/*MTKSOC1*/ #define RF_POR_NUM   (sizeof(SDATA_TABLE2)/sizeof(unsigned long)/2)
/*MTKSOC1*/ extern int L1D_Get_MT6253_SDATA_Index( void );
/*MTKSOC1*/ unsigned long SDATA_TABLE2[2][10]=
/*MTKSOC1*/ {
/*MTKSOC1*/    {  0x0070070,
/*MTKSOC1*/       0x05CC8AD,
/*MTKSOC1*/       0x061C0B0,
/*MTKSOC1*/       0x071B1DD,
/*MTKSOC1*/       0x0912541,
/*MTKSOC1*/       0x0AB6DBF,
/*MTKSOC1*/       0x101B581,
/*MTKSOC1*/       0x1595F0A,
/*MTKSOC1*/       0x1864820,
/*MTKSOC1*/       0x1A34006,
/*MTKSOC1*/    },
/*MTKSOC1*/    {  0x007007F,   // increase loopbandwidth to reduce RX frequency offset
/*MTKSOC1*/       0x05CC8AD,
/*MTKSOC1*/       0x061C0B0,
/*MTKSOC1*/       0x071B1DD,
/*MTKSOC1*/       0x0912141,   // turn off loopbandwidth modification scheme to reduce RX frequency offset
/*MTKSOC1*/       0x0AB6DBF,
/*MTKSOC1*/       0x101B581,
/*MTKSOC1*/       0x1595F0A,
/*MTKSOC1*/       0x1864820,
/*MTKSOC1*/       0x1A34006,
/*MTKSOC1*/    },
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_PowerOn( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    unsigned short i;
/*MTKSOC1*/    unsigned short BSI_num=0;
/*MTKSOC1*/    unsigned long *SDATA_TABLE = L1D_Get_MT6253_SDATA_Index() ? SDATA_TABLE2[1] : SDATA_TABLE2[0];
/*MTKSOC1*/
/*MTKSOC1*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MTKSOC1*/
/*MTKSOC1*/    /*SOR*/
/*MTKSOC1*/    if( l1d_rf.is_init )
/*MTKSOC1*/    {  IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x00F0030 );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MTKSOC1*/       BSI_num=RF_POR_NUM;
/*MTKSOC1*/    }
/*MTKSOC1*/    else if(!L1D_GCMachine_Done())
/*MTKSOC1*/    {  IMM_MODE_END(  );
/*MTKSOC1*/       return;
/*MTKSOC1*/    }
/*MTKSOC1*/    else
/*MTKSOC1*/    {  BSI_num=1;
/*MTKSOC1*/    }
/*MTKSOC1*/
/*MTKSOC1*/    /* POR Start */
/*MTKSOC1*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), (l1d_rf.AFC_data&0x1FFF)|0x0300000 ); //Set before AFC DAC value
/*MTKSOC1*/    SDATA_TABLE[0] = (SDATA_TABLE[0]&~(0x7F<<10)) | ((XO_CapID&0x7F)<<10);
/*MTKSOC1*/    for( i=0 ; i<BSI_num; i++)
/*MTKSOC1*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[i] );
/*MTKSOC1*/    /* POR End */
/*MTKSOC1*/    IMM_SEND_BPI( 0x0000 );
/*MTKSOC1*/    IMM_MODE_END(  );
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_PowerOff( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MTKSOC1*/    /* Don't turn off RF regulators because turning on LDO may disturbing 26MHz */
/*MTKSOC1*///  IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x1C0008c );
/*MTKSOC1*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0200000 );
/*MTKSOC1*/    IMM_MODE_END(  );
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_WindowOn( void )
/*MTKSOC1*/ {  }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_WindowOff( void )
/*MTKSOC1*/ {  }
/*MTKSOC1*/
#endif

#if IS_RF_MT6252RF
/*MT6252RF*/ #define RF_POR_NUM    (sizeof(SDATA_TABLE)/sizeof(unsigned long))
/*MT6252RF*/ #define RF_POR_NUM2   (sizeof(SDATA_TABLE2)/sizeof(unsigned long))
/*MT6252RF*/
/*MT6252RF*/ /* BSI control word in static digital block need to be modified after POR */
/*MT6252RF*/ #if IS_CHIP_MT6252_S00
/*MT6252RF*/ unsigned long SDATA_TABLE[] =
/*MT6252RF*/ {
/*MT6252RF*/     0x0D00000,  // CW13: by setting GLOBAL_CK_EN = 0 to turn off global clock
/*MT6252RF*/     0x04156A8,  // CW4 (change from 0x04154A8 to 0x04156A8)
/*MT6252RF*/     0x05280D4,  // CW5
/*MT6252RF*/     0x409E00F,  // CW64
/*MT6252RF*/     0x419C000,  // CW65
/*MT6252RF*/     0x6516F0A,  // CW101
/*MT6252RF*/     0x68B0820,  // CW104
/*MT6252RF*/     0x80E9400,  // CW128
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /* BSI control word in dynamic digital block need to be modified after wakeup */
/*MT6252RF*/ unsigned long SDATA_TABLE2[] =
/*MT6252RF*/ {
/*MT6252RF*/     0x1020F18,  // CW16 (change from 0x1020F14 to 0x1020F18)
/*MT6252RF*/     0x1500226,  // CW21
/*MT6252RF*/     0x0C0821D,  // CW12: ISO = 0 control word in staticic digital block
/*MT6252RF*/ };
/*MT6252RF*/ #else
/*MT6252RF*/ unsigned long SDATA_TABLE[] =
/*MT6252RF*/ {
/*MT6252RF*/     0x0D00100,  // CW13: by setting GLOBAL_CK_EN = 0 to turn off global clock
/*MT6252RF*/     0x04156A8,  // CW4
/*MT6252RF*/     0x05000D3,  // CW5
/*MT6252RF*/     0x409E00F,  // CW64
/*MT6252RF*/     0x419C000,  // CW65
/*MT6252RF*/     0x63D006A,  // CW99
/*MT6252RF*/     0x64000AA,  // CW100
/*MT6252RF*/     0x6516F0A,  // CW101
/*MT6252RF*/     0x68B0820,  // CW104
/*MT6252RF*/     0x80E9480,  // CW128
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /* BSI control word in dynamic digital block need to be modified after wakeup */
/*MT6252RF*/ unsigned long SDATA_TABLE2[] =
/*MT6252RF*/ {
/*MT6252RF*/     0x004A2A4,  // CW0
/*MT6252RF*/     0x0738429,  // CW7
/*MT6252RF*/     0x1010F11,  // CW16
/*MT6252RF*/     0x1104398,  // CW17
/*MT6252RF*/     0x1340000,  // CW19
/*MT6252RF*/     0x15102BC,  // CW21
/*MT6252RF*/     0x1657878,  // CW22
/*MT6252RF*/     0x18374C8,  // CW24
/*MT6252RF*/     0x1AA42BC,  // CW26
/*MT6252RF*/     0x1B57878,  // CW27
/*MT6252RF*/     0x1C374C8,  // CW28
/*MT6252RF*/     #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6252RF*/     0x1DF035C,  // CW29
/*MT6252RF*/     #else
/*MT6252RF*/     0x1DC0250,  // CW29
/*MT6252RF*/     #endif
/*MT6252RF*/     0x24FFDEA,  // CW36
/*MT6252RF*/     0x2500A6A,  // CW37
/*MT6252RF*/     0x26FF2C9,  // CW38
/*MT6252RF*/     0x27FE717,  // CW39
/*MT6252RF*/     0x28047A9,  // CW40
/*MT6252RF*/     0x2903D20,  // CW41
/*MT6252RF*/     0x2AF8CC1,  // CW42
/*MT6252RF*/     0x2BFA5F7,  // CW43
/*MT6252RF*/     0x2C05803,  // CW44
/*MT6252RF*/     0x2D03909,  // CW45
/*MT6252RF*/     0x2EFD488,  // CW46
/*MT6252RF*/     0x2FFF596,  // CW47
/*MT6252RF*/     0x3000E34,  // CW48
/*MT6252RF*/     0x31FFD37,  // CW49
/*MT6252RF*/     0x32FFFB6,  // CW50
/*MT6252RF*/     0x0C0821D,  // CW12: ISO = 0 control word in staticic digital block
/*MT6252RF*/ };
/*MT6252RF*/ #endif
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_PowerOn( void )
/*MT6252RF*/ {
/*MT6252RF*/    unsigned short i;
/*MT6252RF*/    unsigned short BSI_num = 0, BSI_num2 = 0;
/*MT6252RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6252RF*/
/*MT6252RF*/    if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6252RF*/    {
/*MT6252RF*/       if( l1d_rf.is_init )
/*MT6252RF*/       {
/*MT6252RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x008A220 );   // CW0: set SOR = 1 to reset SD
/*MT6252RF*/          BSI_num = RF_POR_NUM;
/*MT6252RF*/       }
/*MT6252RF*/
/*MT6252RF*/       BSI_num2 = RF_POR_NUM2;
/*MT6252RF*/ #if IS_CHIP_MT6252_S00
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x004A220 );      // CW0: set DYN_EN = 1 to turn on DD
/*MT6252RF*/ #else
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x004A2A4 );      // CW0: set DYN_EN = 1 to turn on DD
/*MT6252RF*/ #endif
/*MT6252RF*/       WAIT_TIME_QB(600);                                // wait at least 553 us
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0E81CB3 );      // CW14: set SOR_DD = 1 to reset DD
/*MT6252RF*/    }
/*MT6252RF*/
/*MT6252RF*/    if( !l1d_rf2.is_wakeup )
/*MT6252RF*/    {
/*MT6252RF*/       /* CW13: Turn on digital clock by setting GLOBAL_CK_EN = 1  */
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0D00300 );
/*MT6252RF*/
/*MT6252RF*/       /* CW57: Set previous AFC DAC value                         */
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), ( l1d_rf.AFC_data & 0x1FFF ) | 0x3900000 );
/*MT6252RF*/
/*MT6252RF*/       /* CW56: Set previous Cap ID value                          */
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), ( XO_CapID & 0x7F) | 0x3800000 );
/*MT6252RF*/
/*MT6252RF*/       /* CW13: Turn off digital clock by setting GLOBAL_CK_EN = 0 */
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0D00100 );
/*MT6252RF*/    }
/*MT6252RF*/
/*MT6252RF*/    for( i = 0 ; i < BSI_num; i++ )
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE[i] );
/*MT6252RF*/
/*MT6252RF*/    for( i = 0 ; i < BSI_num2; i++ )
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE2[i] );
/*MT6252RF*/
/*MT6252RF*/    IMM_SEND_BPI( 0x0000 );
/*MT6252RF*/    IMM_MODE_END(  );
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_PowerOff( void )
/*MT6252RF*/ {
/*MT6252RF*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6252RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0200000 );  // CW2: set mode = sleep mode
/*MT6252RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0C4821D );  // CW12: set ISO = 1
/*MT6252RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x000A220 );  // CW0: set DYN_EN = 0
/*MT6252RF*/    IMM_MODE_END(  );
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_WindowOn( void )
/*MT6252RF*/ {
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_WindowOff( void )
/*MT6252RF*/ {
/*MT6252RF*/ }
#endif

#if IS_RF_MT6261RF
/*MT6261RF*/ #define RF_POR_NUM    (sizeof(SDATA_TABLE)/sizeof(unsigned long))
/*MT6261RF*/ #define RF_POR_NUM2   (sizeof(SDATA_TABLE2)/sizeof(unsigned long))
/*MT6261RF*/
/*MT6261RF*/ /* BSI control word in static digital block need to be modified after POR */
/*MT6261RF*/ const unsigned long SDATA_TABLE[] = 
/*MT6261RF*/ {
/*MT6261RF*/    0x6324EC0,//Dummy to avoid build error,same as SDATA_TABLE2
/*MT6261RF*/ };
/*MT6261RF*/
/*MT6261RF*/ /* BSI control word in dynamic digital block need to be modified after wakeup */
/*MT6261RF*/ const unsigned long SDATA_TABLE2[] = 
/*MT6261RF*/ {
/*MT6261RF*/    0x3A90001,//Update 20140303,CW58 , 0x10001=>0x90001 , For TX ORFS/PE
/*MT6261RF*/    0x3B89DFC,//Update 20140303,CW59 , 0x80000=>0x89DFC , For TX ORFS/PE
/*MT6261RF*/    0x6192400,//Update 20140320,CW97 , For LB OBB
/*MT6261RF*/    0x6324EC0,//Update 20140320,CW99 , For LB OBB
/*MT6261RF*/ };
/*MT6261RF*/
/*MT6261RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6261RF*/ extern void L1D_PowerOn_CheckTime( unsigned char idx );
/*MT6261RF*/ #endif
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_PowerOn( void )
/*MT6261RF*/ {
/*MT6261RF*/    unsigned short i;
/*MT6261RF*/    unsigned short BSI_num = 0, BSI_num2 = 0;
/*MT6261RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6261RF*/    static unsigned short tq_count;
/*MT6261RF*/    unsigned short tq_count_current;
/*MT6261RF*/ #endif
/*MT6261RF*/
/*MT6261RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6261RF*/
/*MT6261RF*/    if( l1d_rf.is_init )
/*MT6261RF*/    {
/*MT6261RF*/       /* CW0: Set SOR = 1 to reset RF */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x00, POR_CW0 | 0x80000) );
/*MT6261RF*/       /* Wait for 4ms for DCXO calibration settling time. */
/*MT6261RF*/       WAIT_TIME_QB(4334);
/*MT6261RF*/
/*MT6261RF*/       BSI_num = RF_POR_NUM;
/*MT6261RF*/
/*MT6261RF*/       /* CW128: for DCS and PCS overlapped ARFCN to pass PvT  */
/*MT6261RF*/       /* 75 is timing boundary for ST2B. (QB_ST2B should be < 75) */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), L1D_RF_SetTX_BSI_CW( QB_ST2B, 75 ) );
/*MT6261RF*/    }
/*MT6261RF*/    BSI_num2 = RF_POR_NUM2;
/*MT6261RF*/
/*MT6261RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6261RF*/    /* RF power on stage 1 */
/*MT6261RF*/    if( !l1d_rf.is_power_on_stage_2 )
/*MT6261RF*/    {  /* CW0: set DYN_EN=1 to turn on DD */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x00, POR_CW0 | 0x40000) );  
/*MT6261RF*/    } 
/*MT6261RF*/
/*MT6261RF*/    if( l1d_rf.is_power_on_stage_1 )
/*MT6261RF*/    {  /* record the current TQ_COUNT and return */
/*MT6261RF*/       tq_count = HW_READ( TDMA_TQCNT );
/*MT6261RF*/       return;
/*MT6261RF*/    }
/*MT6261RF*/
/*MT6261RF*/    /* RF power on stage 2 */
/*MT6261RF*/    if( l1d_rf.is_power_on_stage_2 )
/*MT6261RF*/    {  /* decide how much time to wait */
/*MT6261RF*/       tq_count_current = HW_READ( TDMA_TQCNT );
/*MT6261RF*/       l1d_rf.power_on_stage2_enter = tq_count_current;
/*MT6261RF*/       L1D_PowerOn_CheckTime( 1 );
/*MT6261RF*/    }
/*MT6261RF*/ #else
/*MT6261RF*/    /* CW0: Set DYN_EN = 1 to turn on DD */
/*MT6261RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(   0, POR_CW0 | 0x40000) );
/*MT6261RF*/ #endif
/*MT6261RF*/
/*MT6261RF*/    /* CW12: Set ISO = 0 to disable the gating of control signals from DD to SD */
/*MT6261RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(  12, POR_CW12 & (~0x40000)) );
/*MT6261RF*/
/*MT6261RF*/    if( !l1d_rf2.is_wakeup )
/*MT6261RF*/    {
/*MT6261RF*/       /* CW57: Set previous AFC DAC value                         */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(  57, (POR_CW57&0xFE000) | (l1d_rf.AFC_data&0x1FFF)) );
/*MT6261RF*/
/*MT6261RF*/       /* CW56: Set previous Cap ID value                          */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(  56, (POR_CW56&0xFFFE0) | (XO_CapID&CRYSTAL_CAPID_RANGE)) );
/*MT6261RF*/    }
/*MT6261RF*/
/*MT6261RF*/    for( i = 0 ; i < BSI_num; i++ )
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_TABLE[i] );
/*MT6261RF*/
/*MT6261RF*/    for( i = 0 ; i < BSI_num2; i++ )
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_TABLE2[i] );
/*MT6261RF*/
/*MT6261RF*/    if( L1D_Check_SW_SecVersion() ) /* Update 20140415,TXPE solution for E1 version chip */
/*MT6261RF*/    {
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), 0x1028F29 ); /* CW16 0x28F29 */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), 0x1349400 ); /* CW19 0x49400 */
/*MT6261RF*/    }
/*MT6261RF*/    else /* Update 20140415,TXPE solution for E2 version chip */
/*MT6261RF*/    {
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), 0x0F00992 ); /* CW15 0x00992 */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), 0x113EA18 ); /* CW17 0x3EA18 */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), 0x24FEF03 ); /* CW36 0xFEF03 */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), 0x26FEA00 ); /* CW38 0xFEA00 */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), 0x2D2DA75 ); /* CW45 0x2DA75 */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), 0x3400000 ); /* CW52 0x00000 */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), 0x3501087 ); /* CW53 0x01087 */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), 0x3600000 ); /* CW54 0x00000 */
/*MT6261RF*/       /* SW workaround for first AB freqency error and phase error fail spec. problem.        */
/*MT6261RF*/       /* Turn on VCO when RF power on to avoid VCO frequency drift caused by VCO self-heating */
/*MT6261RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), 0x0212000 ); /* CW02: set TRX[1:0] as 0x2 */
/*MT6261RF*/    }
/*MT6261RF*/
/*MT6261RF*/    IMM_SEND_BPI( 0x0000 );
/*MT6261RF*/    IMM_MODE_END(  );
/*MT6261RF*/
/*MT6261RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6261RF*/    if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6261RF*/    {
/*MT6261RF*/       if( l1d_rf.is_power_on_stage_2 )
/*MT6261RF*/       {
/*MT6261RF*/          l1d_rf.power_on_stage2_leave = HW_READ( TDMA_TQCNT );
/*MT6261RF*/          L1D_PowerOn_CheckTime( 2 );
/*MT6261RF*/       }
/*MT6261RF*/       l1d_rf.is_power_on_stage_1   = 0;
/*MT6261RF*/       l1d_rf.is_power_on_stage_2   = 0;
/*MT6261RF*/       l1d_rf.power_on_stage2_enter = 0;
/*MT6261RF*/       l1d_rf.power_on_stage2_leave = 0;
/*MT6261RF*/    }
/*MT6261RF*/ #endif
/*MT6261RF*/ }
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_PowerOff( void )
/*MT6261RF*/ {
/*MT6261RF*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6261RF*/
/*MT6261RF*/ #if IS_32K_CRYSTAL_REMOVAL_SUPPORT
/*MT6261RF*/    {  //Set LPM fractional divider before RF power off
/*MT6261RF*/       extern unsigned long L1D_GetDCXOFreqLPM(void);
/*MT6261RF*/       unsigned long dcxo_frac = L1D_GetDCXOFreqLPM();
/*MT6261RF*/ 
/*MT6261RF*/       /* CW62 : Let RF enter sleep mode */
/*MT6261RF*/       if( !L1D_RF_Check_32K_XO_Status() )
/*MT6261RF*/       {  IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW( 62, ((dcxo_frac&0xFFF)<<8)|CRYSTAL_CAPID_RANGE) );  }
/*MT6261RF*/    }
/*MT6261RF*/ #endif
/*MT6261RF*/
/*MT6261RF*/    /* CW2  : Let RF enter sleep mode */
/*MT6261RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_IDLE );
/*MT6261RF*/    /* CW12 : Set ISO = 1 for gating of control signals from DD to SD */
/*MT6261RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW( 12, POR_CW12 | 0x40000)  );
/*MT6261RF*/    /* CW0  : Set DYN_EN = 0 to turn off DD */
/*MT6261RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(  0, POR_CW0  & (~0x40000)) );
/*MT6261RF*/    IMM_MODE_END(  );
/*MT6261RF*/
/*MT6261RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6261RF*/    l1d_rf.is_power_on_stage_1   = 0;
/*MT6261RF*/    l1d_rf.is_power_on_stage_2   = 0;
/*MT6261RF*/    l1d_rf.power_on_stage2_enter = 0;
/*MT6261RF*/    l1d_rf.power_on_stage2_leave = 0;
/*MT6261RF*/ #endif
/*MT6261RF*/ }
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_WindowOn( void )
/*MT6261RF*/ {
/*MT6261RF*/ }
/*MT6261RF*/
/*MT6261RF*/ void  L1D_RF_WindowOff( void )
/*MT6261RF*/ {
/*MT6261RF*/ }
#endif

#if IS_RF_MT6260RF
/*MT6260RF*/ #define RF_POR_NUM    (sizeof(SDATA_TABLE)/sizeof(unsigned long))
/*MT6260RF*/ #define RF_POR_NUM2   (sizeof(SDATA_TABLE2)/sizeof(unsigned long))
/*MT6260RF*/
/*MT6260RF*/ /* BSI control word in static digital block need to be modified after POR */
/*MT6260RF*/ const unsigned long SDATA_TABLE[] = 
/*MT6260RF*/ {
/*MT6260RF*/    0x03F84B7, //CW3     ,SD,Update 20130103,For OBB
/*MT6260RF*/    0x04D46A8, //CW4     ,SD,Update 20130103,For OBB
/*MT6260RF*/    0x05078C4, //CW5     ,SD,Update 20130103,For OBB
/*MT6260RF*/    0x3C12248, //CW60    ,SD,Update 20121214
/*MT6260RF*/    0x3F70750, //CW63    ,SD,Update 20121214
/*MT6260RF*/    0x408000E, //CW64    ,SD,Update 20130109
/*MT6260RF*/    0x636DB08, //CW99    ,SD,Update 20121214
/*MT6260RF*/    0x646DB78, //CW100   ,SD,Update 20121214
/*MT6260RF*/    0x6500004, //CW101   ,SD,Update 20121214
/*MT6260RF*/    0x6694960, //CW102   ,SD,Update 20130123
/*MT6260RF*/    0x6810842, //CW104   ,SD,Update 20130109
/*MT6260RF*/    0x6AF706A, //CW106   ,SD,Update 20130109
/*MT6260RF*/    0x6BBA800, //CW107   ,SD,Update 20121214
/*MT6260RF*/    0x813D600, //CW129   ,SD,Update 20130109
/*MT6260RF*/ };
/*MT6260RF*/
/*MT6260RF*/ /* BSI control word in dynamic digital block need to be modified after wakeup */
/*MT6260RF*/ const unsigned long SDATA_TABLE2[] = 
/*MT6260RF*/ {
/*MT6260RF*/    0x0E01C4F, //CW14    ,DD  ,Update 20121214
/*MT6260RF*/    0x0F00E72, //CW15    ,DD  ,Update 20121214
/*MT6260RF*/    0x4620CBE, //CW70    ,DIG ,2G RX AFE
/*MT6260RF*/    0x4704100, //CW71    ,DIG ,2G RX AFE
/*MT6260RF*/    0x48CD2A5, //CW72    ,DIG ,2G RX AFE
/*MT6260RF*/    0x4A05558, //CW74    ,DIG ,2G RX AFE
/*MT6260RF*/    0x4E0030C, //CW78    ,DIG ,2G RX AFE
/*MT6260RF*/    0x4F00200  //CW79    ,DIG ,2G RX AFE
/*MT6260RF*/ };
/*MT6260RF*/
/*MT6260RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6260RF*/ extern void L1D_PowerOn_CheckTime( unsigned char idx );
/*MT6260RF*/ #endif
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_PowerOn( void )
/*MT6260RF*/ {
/*MT6260RF*/    unsigned short i;
/*MT6260RF*/    unsigned short BSI_num = 0, BSI_num2 = 0;
/*MT6260RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6260RF*/    static unsigned short tq_count;
/*MT6260RF*/           unsigned short tq_count_current;
/*MT6260RF*/ #endif
/*MT6260RF*/
/*MT6260RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6260RF*/
/*MT6260RF*/    if( l1d_rf.is_init )  
/*MT6260RF*/    {  /* Do NOT set SD SOR when init. It may have problem in 32K removal scenario. */
/*MT6260RF*/       /* Since some 32K removal calibrations is done after the battery is on,      */
/*MT6260RF*/       /* it will reset 32K removal calibration state to set SD SOR when init.      */
/*MT6260RF*/ 
/*MT6260RF*/       BSI_num = RF_POR_NUM;
/*MT6260RF*/
/*MT6260RF*/       /* CW128: for DCS and PCS overlapped ARFCN to pass PvT  */
/*MT6260RF*/       /* 75 is timing boundary for ST2B. (QB_ST2B should be < 75) */
/*MT6260RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), L1D_RF_SetTX_BSI_CW( QB_ST2B, 75 ) );
/*MT6260RF*/    }
/*MT6260RF*/    BSI_num2 = RF_POR_NUM2;
/*MT6260RF*/
/*MT6260RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6260RF*/    /* RF power on stage 1 */
/*MT6260RF*/    if( !l1d_rf.is_power_on_stage_2 )
/*MT6260RF*/    {  /* CW0: set DYN_EN=1 to turn on DD */
/*MT6260RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x00, POR_CW0 | 0x40000) );  
/*MT6260RF*/    } 
/*MT6260RF*/
/*MT6260RF*/    if( l1d_rf.is_power_on_stage_1 )
/*MT6260RF*/    {  /* record the current TQ_COUNT and return */
/*MT6260RF*/       tq_count = HW_READ( TDMA_TQCNT );
/*MT6260RF*/       return;
/*MT6260RF*/    }
/*MT6260RF*/
/*MT6260RF*/    /* RF power on stage 2 */
/*MT6260RF*/    if( l1d_rf.is_power_on_stage_2 )
/*MT6260RF*/    {  /* decide how much time to wait */
/*MT6260RF*/       tq_count_current = HW_READ( TDMA_TQCNT );
/*MT6260RF*/       l1d_rf.power_on_stage2_enter = tq_count_current;
/*MT6260RF*/       L1D_PowerOn_CheckTime( 1 );
/*MT6260RF*/       /* If  stage 2 entering time later than TQ wrap , it will never wait enough time for DD settle   */
/*MT6260RF*/       /* So, add TQ_WRAP_COUNT to tq_count_current                                                     */
/*MT6260RF*/       tq_count_current = (tq_count_current<tq_count) ? (tq_count_current+5000) : tq_count_current;
/*MT6260RF*/       if( ((tq_count_current-tq_count)>0) && ((tq_count_current-tq_count)<543) )
/*MT6260RF*/       {  
/*MT6260RF*/          WAIT_TIME_QB( 543-(tq_count_current-tq_count) );  } // wait the remaining time
/*MT6260RF*/       }
/*MT6260RF*/    else
/*MT6260RF*/    {  /* wait at least 501 us */
/*MT6260RF*/       WAIT_TIME_QB(543);
/*MT6260RF*/    }
/*MT6260RF*/ #else
/*MT6260RF*/    /* CW0: Set DYN_EN = 1 to turn on DD */
/*MT6260RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x00, POR_CW0 | 0x40000) );
/*MT6260RF*/    /* wait at least 501 us */
/*MT6260RF*/    WAIT_TIME_QB(543); 
/*MT6260RF*/ #endif
/*MT6260RF*/
/*MT6260RF*/    /* No need to set SOR_DD since the reset of DD is done by HW POR after DD is turned on */
/*MT6260RF*/    //IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x0E, POR_CW14 | 0x80000) ); // CW14: Set SOR_DD = 1 to reset DD
/*MT6260RF*/
/*MT6260RF*/    /* CW12: Set ISO = 0 to disable the gating of control signals from DD to SD */
/*MT6260RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x0C, POR_CW12 & (~0x40000)) );
/*MT6260RF*/
/*MT6260RF*/    if( !l1d_rf2.is_wakeup )
/*MT6260RF*/    {
/*MT6260RF*/       /* CW57: Set previous AFC DAC value                         */
/*MT6260RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x39, (POR_CW57&0xFE000) | (l1d_rf.AFC_data&0x1FFF)) );
/*MT6260RF*/
/*MT6260RF*/       /* CW56: Set previous Cap ID value                          */
/*MT6260RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x38, (POR_CW56&0xFFF00) | (XO_CapID&0xFF)) );
/*MT6260RF*/    }
/*MT6260RF*/	 
/*MT6260RF*/    for( i = 0 ; i < BSI_num; i++ )
/*MT6260RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_TABLE[i] );
/*MT6260RF*/	 
/*MT6260RF*/    for( i = 0 ; i < BSI_num2; i++ )
/*MT6260RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_TABLE2[i] );
/*MT6260RF*/    
/*MT6260RF*/    IMM_SEND_BPI( 0x0000 );
/*MT6260RF*/    IMM_MODE_END(  );
/*MT6260RF*/ 
/*MT6260RF*/ #if IS_TEMP_COMP_TC_GAIN_SUPPORT
/*MT6260RF*/    if( l1d_rf.is_init )
/*MT6260RF*/    {  /* Initialize l1d_rf.thermo_adc_code_offset */
/*MT6260RF*/       L1D_RF_THADC_Set_Code_Offset();
/*MT6260RF*/       /* Initialize l1d_rf.thermo_adc_code and l1d_rf.k_cal */
/*MT6260RF*/       L1D_RF_THADC_KCAL_Init();
/*MT6260RF*/    #if IS_KCAL_COMP_TC_GAIN_SUPPORT
/*MT6260RF*/       /* Initialize l1d_rf.k_cal_comp */
/*MT6260RF*/       L1D_RF_KCAL_Get_Kcal_Comp_Value();   
/*MT6260RF*/    #endif
/*MT6260RF*/    }
/*MT6260RF*/ #endif
/*MT6260RF*/   
/*MT6260RF*/ #if IS_COSIM_ON_L1SIM_SUPPORT && IS_CHIP_MT6261
/*MT6260RF*/    /* Bypass in L1sim when IS_CHIP_MT6261 */
/*MT6260RF*/ #else
/*MT6260RF*/    /*MT6260 D2D interface APC control*/
/*MT6260RF*/    HW_WRITE(D2D_D_APC_AUX_CON0,0x0001);  /*D-die D2D f26m_apc_en enable  	   */
/*MT6260RF*/    HW_WRITE(D2D_A_APC_AUX_CON0,0x8000);  /*A-die D2D apc_en enable        	*/
/*MT6260RF*/    HW_READ (D2D_A_APC_AUX_CON0);         /*Dummy read for order confirm   	*/
/*MT6260RF*/    HW_WRITE(D2D_D_APC_AUX_CON0,0x8001);  /*D-die D2D apc_en enable        	*/
/*MT6260RF*/ #endif
/*MT6260RF*/
/*MT6260RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6260RF*/    if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6260RF*/    {
/*MT6260RF*/       if( l1d_rf.is_power_on_stage_2 )
/*MT6260RF*/       {
/*MT6260RF*/          l1d_rf.power_on_stage2_leave = HW_READ( TDMA_TQCNT );
/*MT6260RF*/          L1D_PowerOn_CheckTime( 2 );
/*MT6260RF*/       }
/*MT6260RF*/       l1d_rf.is_power_on_stage_1   = 0;
/*MT6260RF*/       l1d_rf.is_power_on_stage_2   = 0;
/*MT6260RF*/       l1d_rf.power_on_stage2_enter = 0;
/*MT6260RF*/       l1d_rf.power_on_stage2_leave = 0;
/*MT6260RF*/    }
/*MT6260RF*/ #endif
/*MT6260RF*/ }
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_PowerOff( void )
/*MT6260RF*/ {
/*MT6260RF*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6260RF*/
/*MT6260RF*/ #if IS_32K_CRYSTAL_REMOVAL_SUPPORT
/*MT6260RF*/    {  //Set LPM fractional divider before RF power off
/*MT6260RF*/       extern unsigned long L1D_GetDCXOFreqLPM(void);
/*MT6260RF*/       unsigned long dcxo_frac = L1D_GetDCXOFreqLPM();
/*MT6260RF*/ 
/*MT6260RF*/       /* CW62 : Let RF enter sleep mode */
/*MT6260RF*/       if( !L1D_RF_Check_32K_XO_Status() )
/*MT6260RF*/       {  IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x3E, ((dcxo_frac&0xFFF)<<8)|0xFF) );  }
/*MT6260RF*/    }
/*MT6260RF*/ #endif
/*MT6260RF*/
/*MT6260RF*/    /* CW2  : Let RF enter sleep mode */
/*MT6260RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_IDLE );
/*MT6260RF*/    /* CW12 : Set ISO = 1 for gating of control signals from DD to SD */
/*MT6260RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x0C, POR_CW12 | 0x40000) );
/*MT6260RF*/    /* CW0  : Set DYN_EN = 0 to turn off DD */
/*MT6260RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x00, POR_CW0 & (~0x40000)) );
/*MT6260RF*/    IMM_MODE_END(  );
/*MT6260RF*/
/*MT6260RF*/ #if IS_COSIM_ON_L1SIM_SUPPORT && IS_CHIP_MT6261
/*MT6260RF*/    /* Bypass in L1sim when IS_CHIP_MT6261 */
/*MT6260RF*/ #else
/*MT6260RF*/    /*MT6260 D2D interface APC control*/
/*MT6260RF*/    HW_WRITE(D2D_D_APC_AUX_CON0,0x0001);  /*D-die D2D apc_en disable       	*/
/*MT6260RF*/    HW_WRITE(D2D_A_APC_AUX_CON0,0x0000);  /*A-die D2D apc_en disable       	*/
/*MT6260RF*/    WAIT_TIME_QB(3);                      /*Wait 50T (26MHz) => Wait 3Qbit	*/
/*MT6260RF*/    HW_WRITE(D2D_D_APC_AUX_CON0,0x0000);  /*D-die D2D f26m_apc_en disable  	*/
/*MT6260RF*/ #endif
/*MT6260RF*/
/*MT6260RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6260RF*/    l1d_rf.is_power_on_stage_1   = 0;
/*MT6260RF*/    l1d_rf.is_power_on_stage_2   = 0;
/*MT6260RF*/    l1d_rf.power_on_stage2_enter = 0;
/*MT6260RF*/    l1d_rf.power_on_stage2_leave = 0;
/*MT6260RF*/ #endif
/*MT6260RF*/ }
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_WindowOn( void )
/*MT6260RF*/ {
/*MT6260RF*/ }
/*MT6260RF*/
/*MT6260RF*/ void  L1D_RF_WindowOff( void )
/*MT6260RF*/ {
/*MT6260RF*/ }
#endif

#if IS_RF_MT6250RF
/*MT6250RF*/ #define RF_POR_NUM    (sizeof(SDATA_TABLE)/sizeof(unsigned long))
/*MT6250RF*/ #define RF_POR_NUM2   (sizeof(SDATA_TABLE2)/sizeof(unsigned long))
/*MT6250RF*/
/*MT6250RF*/ /* BSI control word in static digital block need to be modified after POR */
/*MT6250RF*/ unsigned long SDATA_TABLE[] =
/*MT6250RF*/ {
/*MT6250RF*/  #if MT6250_RXIQ_DEBUG   
/*MT6250RF*/     0x408000F,  // CW 64: for output RXIQ signal
/*MT6250RF*/     0x6C3A600,  // CW108: for output RXIQ signal
/*MT6250RF*/  #else
/*MT6250RF*/     0x6C2A400,  // CW108: RXIF
/*MT6250RF*/  #endif
/*MT6250RF*/     0x04556A8,  // CW  4: SX-DFM
/*MT6250RF*/     0x6186850,  // CW 97: RX Gain
/*MT6250RF*/     0x62BCCA0,  // CW 98: RX Power
/*MT6250RF*/     0x6642160,  // CW102: RX FE
/*MT6250RF*/     0x6744430,  // CW103: RX FE
/*MT6250RF*/     0x6884210,  // CW104: RX FE
/*MT6250RF*/     0x691E03C,  // CW105: RX FE (need to change POR_CW105 definition in m12190.h if CW105 is modified)
/*MT6250RF*/     0x6AB6436,  // CW106: RXDIV OBB Mode Setting
/*MT6250RF*/ };
/*MT6250RF*/
/*MT6250RF*/ /* BSI control word in dynamic digital block need to be modified after wakeup */
/*MT6250RF*/ unsigned long SDATA_TABLE2[] =
/*MT6250RF*/ {
/*MT6250RF*/     0x03B84B7,  // CW 3: SX-DFM
/*MT6250RF*/     0x4300000,  // CW67:
/*MT6250RF*/     0x4400000,  // CW68:
/*MT6250RF*/     0x4508000,  // CW69:
/*MT6250RF*/     0x4620CBE,  // CW70:
/*MT6250RF*/     0x4704100,  // CW71:
/*MT6250RF*/     0x48CD2A5,  // CW72:
/*MT6250RF*/     0x4958F0F,  // CW73:
/*MT6250RF*/     0x4A05558,  // CW74:
/*MT6250RF*/     0x4B2C000,  // CW75:
/*MT6250RF*/     0x4C21C82,  // CW76:
/*MT6250RF*/     0x4D61882,  // CW77:
/*MT6250RF*/     0x4E0030C,  // CW78:
/*MT6250RF*/     0x4F00200,  // CW79:
/*MT6250RF*/ };
/*MT6250RF*/
/*MT6250RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6250RF*/ extern void L1D_PowerOn_CheckTime( unsigned char idx );
/*MT6250RF*/ #endif
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_PowerOn( void )
/*MT6250RF*/ {
/*MT6250RF*/    unsigned short i;
/*MT6250RF*/    unsigned short BSI_num = 0, BSI_num2 = 0;
/*MT6250RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6250RF*/    static unsigned short tq_count;
/*MT6250RF*/           unsigned short tq_count_current;
/*MT6250RF*/ #endif
/*MT6250RF*/
/*MT6250RF*/    if( !L1D_Check_SW_SecVersion() )
/*MT6250RF*/    {
/*MT6250RF*/       /* Set ABB_RSV_CON1[0] and ABB_RSV_CON1[4] as 1 to enable Die-Die 26M clock during TX. */
/*MT6250RF*/       unsigned short  d16;
/*MT6250RF*/       d16 = HW_READ( ABB_RSV_CON1 );
/*MT6250RF*/       HW_WRITE( ABB_RSV_CON1, d16 | 0x0001 );
/*MT6250RF*/       WAIT_TIME_QB(2);
/*MT6250RF*/       HW_WRITE( ABB_RSV_CON1, d16 | 0x0011 );
/*MT6250RF*/    }
/*MT6250RF*/
/*MT6250RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6250RF*/
/*MT6250RF*/    if( l1d_rf.is_init )  
/*MT6250RF*/    {  /* Do NOT set SD SOR when init. It may have problem in 32K removal scenario. */
/*MT6250RF*/       /* Since some 32K removal calibrations is done after the battery is on,      */
/*MT6250RF*/       /* it will reset 32K removal calibration state to set SD SOR when init.      */
/*MT6250RF*/       //IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x00, POR_CW0 | 0x80000) ); // CW0: Set SOR = 1 to reset SD
/*MT6250RF*/       BSI_num = RF_POR_NUM;
/*MT6250RF*/
/*MT6250RF*/       /* CW128: for DCS and PCS overlapped ARFCN to pass PvT  */
/*MT6250RF*/       /* 75 is timing boundary for ST2B. (QB_ST2B should be < 75) */
/*MT6250RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), L1D_RF_SetTX_BSI_CW( QB_ST2B, 75 ) );
/*MT6250RF*/    }
/*MT6250RF*/    BSI_num2 = RF_POR_NUM2;
/*MT6250RF*/
/*MT6250RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6250RF*/    /* RF power on stage 1 */
/*MT6250RF*/    if( !l1d_rf.is_power_on_stage_2 )
/*MT6250RF*/    {  IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x00, POR_CW0 | 0x40000) );  } // CW0: set DYN_EN=1 to turn on DD
/*MT6250RF*/
/*MT6250RF*/    if( l1d_rf.is_power_on_stage_1 )
/*MT6250RF*/    {  /* record the current TQ_COUNT and return */
/*MT6250RF*/       tq_count = HW_READ( TDMA_TQCNT );
/*MT6250RF*/       return;
/*MT6250RF*/    }
/*MT6250RF*/
/*MT6250RF*/    /* RF power on stage 2 */
/*MT6250RF*/    if( l1d_rf.is_power_on_stage_2 )
/*MT6250RF*/    {  /* decide how much time to wait */
/*MT6250RF*/       tq_count_current = HW_READ( TDMA_TQCNT );
/*MT6250RF*/       l1d_rf.power_on_stage2_enter = tq_count_current;
/*MT6250RF*/       L1D_PowerOn_CheckTime( 1 );
/*MT6250RF*/       if( ((tq_count_current-tq_count)>0) && ((tq_count_current-tq_count)<543) )
/*MT6250RF*/       {  WAIT_TIME_QB( 543-(tq_count_current-tq_count) );  } // wait the remaining time
/*MT6250RF*/    }
/*MT6250RF*/    else
/*MT6250RF*/    {
/*MT6250RF*/       WAIT_TIME_QB(543); // wait at least 501 us
/*MT6250RF*/    }
/*MT6250RF*/ #else
/*MT6250RF*/    /* CW0: Set DYN_EN = 1 to turn on DD */
/*MT6250RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x00, POR_CW0 | 0x40000) );
/*MT6250RF*/    WAIT_TIME_QB(543); // wait at least 501 us
/*MT6250RF*/ #endif
/*MT6250RF*/
/*MT6250RF*/    /* No need to set SOR_DD since the reset of DD is done by HW POR after DD is turned on */
/*MT6250RF*/    //IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x0E, POR_CW14 | 0x80000) ); // CW14: Set SOR_DD = 1 to reset DD
/*MT6250RF*/
/*MT6250RF*/    /* CW12: Set ISO = 0 to disable the gating of control signals from DD to SD */
/*MT6250RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x0C, POR_CW12 & (~0x40000)) );
/*MT6250RF*/
/*MT6250RF*/    if( !l1d_rf2.is_wakeup )
/*MT6250RF*/    {
/*MT6250RF*/       /* CW13: Turn on digital clock by setting GLOBAL_CK_EN = 1  */
/*MT6250RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x0D, POR_CW13 | 0x00200) );
/*MT6250RF*/
/*MT6250RF*/       /* CW57: Set previous AFC DAC value                         */
/*MT6250RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x39, (POR_CW57&0xFE000) | (l1d_rf.AFC_data&0x1FFF)) );
/*MT6250RF*/
/*MT6250RF*/       /* CW56: Set previous Cap ID value                          */
/*MT6250RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x38, (POR_CW56&0xFFF00) | (XO_CapID&0xFF)) );
/*MT6250RF*/
/*MT6250RF*/       if( !L1D_Check_SW_SecVersion() )
/*MT6250RF*/       {  /* CW13: Turn off digital clock by setting GLOBAL_CK_EN = 0 */
/*MT6250RF*/          //Do not turn off clock to solve the problem of missing TX bursts when frequency hopping is enabled for E1
/*MT6250RF*/          //IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x0D, POR_CW13 & (~0x00200)) );
/*MT6250RF*/       }
/*MT6250RF*/    }
/*MT6250RF*/
/*MT6250RF*/    for( i = 0 ; i < BSI_num; i++ )
/*MT6250RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_TABLE[i] );
/*MT6250RF*/
/*MT6250RF*/    for( i = 0 ; i < BSI_num2; i++ )
/*MT6250RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_TABLE2[i] );
/*MT6250RF*/
/*MT6250RF*/    if( L1D_Check_SW_SecVersion() )
/*MT6250RF*/    {
/*MT6250RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x4F, 0xC2400 ) );
/*MT6250RF*/       WAIT_TIME_QB(65);
/*MT6250RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x45, 0xE8000 ) );
/*MT6250RF*/       WAIT_TIME_QB(65);
/*MT6250RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x46, 0xE0CBE ) );
/*MT6250RF*/       WAIT_TIME_QB(65);
/*MT6250RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x48, 0xEF2A5 ) );
/*MT6250RF*/       WAIT_TIME_QB(65);
/*MT6250RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x4A, 0x45558 ) );
/*MT6250RF*/       WAIT_TIME_QB(65);
/*MT6250RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x4A, 0xC5558 ) );
/*MT6250RF*/       WAIT_TIME_QB(65);
/*MT6250RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x4A, 0x45558 ) );
/*MT6250RF*/    }
/*MT6250RF*/
/*MT6250RF*/    IMM_SEND_BPI( 0x0000 );
/*MT6250RF*/    IMM_MODE_END(  );
/*MT6250RF*/ 
/*MT6250RF*/ #if IS_TEMP_COMP_TC_GAIN_SUPPORT
/*MT6250RF*/    if( l1d_rf.is_init )
/*MT6250RF*/    {  /* Initialize l1d_rf.thermo_adc_code_offset */
/*MT6250RF*/       L1D_RF_THADC_Set_Code_Offset();
/*MT6250RF*/       /* Initialize l1d_rf.thermo_adc_code and l1d_rf.k_cal */
/*MT6250RF*/       L1D_RF_THADC_KCAL_Init();
/*MT6250RF*/    #if IS_KCAL_COMP_TC_GAIN_SUPPORT
/*MT6250RF*/       /* Initialize l1d_rf.k_cal_comp */
/*MT6250RF*/       L1D_RF_KCAL_Get_Kcal_Comp_Value();   
/*MT6250RF*/    #endif
/*MT6250RF*/    }
/*MT6250RF*/ #endif
/*MT6250RF*/
/*MT6250RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6250RF*/    if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6250RF*/    {
/*MT6250RF*/       if( l1d_rf.is_power_on_stage_2 )
/*MT6250RF*/       {
/*MT6250RF*/          l1d_rf.power_on_stage2_leave = HW_READ( TDMA_TQCNT );
/*MT6250RF*/          L1D_PowerOn_CheckTime( 2 );
/*MT6250RF*/       }
/*MT6250RF*/       l1d_rf.is_power_on_stage_1   = 0;
/*MT6250RF*/       l1d_rf.is_power_on_stage_2   = 0;
/*MT6250RF*/       l1d_rf.power_on_stage2_enter = 0;
/*MT6250RF*/       l1d_rf.power_on_stage2_leave = 0;
/*MT6250RF*/    }
/*MT6250RF*/ #endif
/*MT6250RF*/ }
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_PowerOff( void )
/*MT6250RF*/ {
/*MT6250RF*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6250RF*/
/*MT6250RF*/ #if IS_32K_CRYSTAL_REMOVAL_SUPPORT
/*MT6250RF*/    {  //Set LPM fractional divider before RF power off
/*MT6250RF*/       extern unsigned long L1D_GetDCXOFreqLPM(void);
/*MT6250RF*/       unsigned long dcxo_frac = L1D_GetDCXOFreqLPM();
/*MT6250RF*/
/*MT6250RF*/       if( !L1D_RF_Check_32K_XO_Status() )
/*MT6250RF*/       {  IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x3E, ((dcxo_frac&0xFFF)<<8)|0xFF) );  }
/*MT6250RF*/    }
/*MT6250RF*/ #endif
/*MT6250RF*/
/*MT6250RF*/    /* CW2: Let RF enter sleep mode */
/*MT6250RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_IDLE );
/*MT6250RF*/    /* CW12: Set ISO = 1 for gating of control signals from DD to SD */
/*MT6250RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x0C, POR_CW12 | 0x40000) );
/*MT6250RF*/    /* CW0: Set DYN_EN = 0 to turn off DD */
/*MT6250RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x00, POR_CW0 & (~0x40000)) );
/*MT6250RF*/    IMM_MODE_END(  );
/*MT6250RF*/
/*MT6250RF*/ #if IS_TDMA_TWO_STAGE_RF_POWERON_SUPPORT
/*MT6250RF*/    l1d_rf.is_power_on_stage_1   = 0;
/*MT6250RF*/    l1d_rf.is_power_on_stage_2   = 0;
/*MT6250RF*/    l1d_rf.power_on_stage2_enter = 0;
/*MT6250RF*/    l1d_rf.power_on_stage2_leave = 0;
/*MT6250RF*/ #endif
/*MT6250RF*/
/*MT6250RF*/    if( !L1D_Check_SW_SecVersion() )
/*MT6250RF*/    {
/*MT6250RF*/       /* Set ABB_RSV_CON1[0] and ABB_RSV_CON1[4] as 0 when we do not need Die-Die 26M clock since no TX. */
/*MT6250RF*/       unsigned short  d16;
/*MT6250RF*/       d16 = HW_READ( ABB_RSV_CON1 );
/*MT6250RF*/       HW_WRITE( ABB_RSV_CON1, d16 & (~0x0010) );
/*MT6250RF*/       WAIT_TIME_QB(2);
/*MT6250RF*/       HW_WRITE( ABB_RSV_CON1, d16 & (~0x0011) );
/*MT6250RF*/    }
/*MT6250RF*/
/*MT6250RF*/ }
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_WindowOn( void )
/*MT6250RF*/ {
/*MT6250RF*/ }
/*MT6250RF*/
/*MT6250RF*/ void  L1D_RF_WindowOff( void )
/*MT6250RF*/ {
/*MT6250RF*/ }
#endif

#if IS_RF_MT6256RF
/*MT6256RF*/ #define RF_POR_NUM    (sizeof(SDATA_TABLE) /sizeof(unsigned long))
/*MT6256RF*/ #define RF_POR_NUM2   (sizeof(SDATA_TABLE2)/sizeof(unsigned long))
/*MT6256RF*/
/*MT6256RF*/ #if IS_CHIP_MT6256_S00
/*MT6256RF*/ /* BSI control word in static digital block need to be modified after POR */
/*MT6256RF*/ unsigned long SDATA_TABLE[]=
/*MT6256RF*/ {
/*MT6256RF*/    0x6800000,  /* CW104: D6=0 ground hign band mixer MUX */
/*MT6256RF*/    0x80FF4D3,  /* CW128: */
/*MT6256RF*/    0x84088DB,  /* CW132: */
/*MT6256RF*/    0x8A01170,  /* CW138: */
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ /* BSI control word in dynamic digital block need to be modified after wakeup */
/*MT6256RF*/ unsigned long SDATA_TABLE2[]=
/*MT6256RF*/ {
/*MT6256RF*/    0x03C44B7,  /* CW3:   */
/*MT6256RF*/    0x0816013,  /* CW8:   */
/*MT6256RF*/    0x0C18230,  /* CW12: ISO=0 control word in staticic digital block */
/*MT6256RF*/    0x0F01462,  /* CW15:  */
/*MT6256RF*/    0x1041150,  /* CW16:  */
/*MT6256RF*/    0x14F7DBA,  /* CW20:  */
/*MT6256RF*/    0x15FFFFF,  /* CW21:  */
/*MT6256RF*/    0x16FBA01,  /* CW22:  */
/*MT6256RF*/    0x17FFF7D,  /* CW23:  */
/*MT6256RF*/    0x18F01FF,  /* CW24:  */
/*MT6256RF*/    0x1977DBA,  /* CW25:  */
/*MT6256RF*/    0x8369A25,  /* CW131: */
/*MT6256RF*/    0x890001F,  /* CW137: */
/*MT6256RF*/ };
/*MT6256RF*/ #else
/*MT6256RF*/ /* BSI control word in static digital block need to be modified after POR */
/*MT6256RF*/ unsigned long SDATA_TABLE[]=
/*MT6256RF*/ {
/*MT6256RF*/    #if IS_CHIP_MT6256_S01
/*MT6256RF*/    0x0454866,  /* CW4:                         */
/*MT6256RF*/    #else
/*MT6256RF*/    0x0454A66,  /* CW4:                         */
/*MT6256RF*/    #endif
/*MT6256RF*/    0x3F8BC86,  /* CW63:                        */
/*MT6256RF*/    0x651D3FA,  /* CW101:                       */
/*MT6256RF*/    0x8B00001,  /* CW139: boost GMSK HBTX power */
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ /* BSI control word in dynamic digital block need to be modified after wakeup */
/*MT6256RF*/ unsigned long SDATA_TABLE2[]=
/*MT6256RF*/ {
/*MT6256RF*/    0x0C18230,  /* CW12: ISO=0 control word in staticic digital block                     */
/*MT6256RF*/    0x1055D5A,  /* CW16: improve PE                                                       */
/*MT6256RF*/    0x1937DBA,  /* CW25: improve PE                                                       */
/*MT6256RF*/    0x2373038,  /* CW35: improve PE                                                       */
/*MT6256RF*/    0x8369825,  /* CW131: improve PE                                                      */
/*MT6256RF*/    0x419E000,  /* CW65: for reading back RF temperature                                  */
/*MT6256RF*/    0x4200001,  /* CW66: for reading back AUXOUT table                                    */
/*MT6256RF*/    0x8AA1170,  /* CW138: for triggering the temperature ADC ONLY at the TX mode, D[17]=1 */
/*MT6256RF*/ };
/*MT6256RF*/ #endif
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_PowerOn( void )
/*MT6256RF*/ {
/*MT6256RF*/    unsigned short i;
/*MT6256RF*/    unsigned short BSI_num=0, BSI_num2=0;
/*MT6256RF*/ #if IS_AST_B2S_SUPPORT
/*MT6256RF*/    int b32=0;
/*MT6256RF*/ #endif
/*MT6256RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6256RF*/
/*MT6256RF*/    if( l1d_rf.is_init )
/*MT6256RF*/    {
/*MT6256RF*/ #if IS_CHIP_MT6256_S00
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x102A0) );  //CW0: set SOR=1 to reset SD
/*MT6256RF*/ #else
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x18230) );  //CW0: set SOR=1 to reset SD
/*MT6256RF*/ #endif
/*MT6256RF*/       BSI_num = RF_POR_NUM;
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), L1D_RF_SetTX_BSI_CW( QB_ST2B, 150 ) );  //CW136: for DCS and PCS overlapped ARFCN to pass PvT */
/*MT6256RF*/    }
/*MT6256RF*/
/*MT6256RF*/    BSI_num2 = RF_POR_NUM2;
/*MT6256RF*/
/*MT6256RF*/ #if IS_CHIP_MT6256_S00
/*MT6256RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x502A0) );  //CW0: set DYN_EN=1 to turn on DD
/*MT6256RF*/ #else
/*MT6256RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x58230) );  //CW0: set DYN_EN=1 to turn on DD
/*MT6256RF*/ #endif
/*MT6256RF*/
/*MT6256RF*/    WAIT_TIME_QB(335);  //wait at least 310us
/*MT6256RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x0E, 0x80000) );  //CW14: set SOR_DD=1 to reset DD
/*MT6256RF*/
/*MT6256RF*/    if( !l1d_rf2.is_wakeup )
/*MT6256RF*/    {
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x84, 0x188D8)                );  //CW132: Enable to force to set AFC DAC in RX/TX mode
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x39, l1d_rf.AFC_data&0x1FFF) );  //CW57: Set previous AFC DAC value
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x38, XO_CapID&0xFF)          );  //CW56: Set previous Cap ID value
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x84, 0x088D8)                );  //CW132: Disable to force to set AFC DAC in RX/TX mode
/*MT6256RF*/    }
/*MT6256RF*/
/*MT6256RF*/    for( i=0 ; i<BSI_num; i++ )
/*MT6256RF*/    {  IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE[i] );  }
/*MT6256RF*/
/*MT6256RF*/    for( i=0 ; i<BSI_num2; i++ )
/*MT6256RF*/    {  IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE2[i] ); }
/*MT6256RF*/
/*MT6256RF*/ #if IS_AST_B2S_SUPPORT
/*MT6256RF*/
/*MT6256RF*/    if( !l1d_rf2.is_wakeup )          
/*MT6256RF*/    {
/*MT6256RF*/       IMM_SEND_BPI( 0x0100 ); //Switch SPI control to 2G
/*MT6256RF*/
/*MT6256RF*/       for(b32=0;b32<4;b32++)
/*MT6256RF*/       {
/*MT6256RF*/          HW_WRITE(AFC_EV(b32),0x2700);
/*MT6256RF*/       }
/*MT6256RF*/       b32=HW_READ(TDMA_EVTENA(0));
/*MT6256RF*/       HW_WRITE(TDMA_EVTENA(0),b32&0xFFFF0FFF);			
/*MT6256RF*/		   		
/*MT6256RF*/       HW_WRITE( AFC_VALUE, 0x0E100000 ); // set AFC Value   
/*MT6256RF*/       HW_WRITE( AFC_DAT(0), (l1d_rf.AFC_data&0x1FFF) );
/*MT6256RF*/       HW_WRITE( AFC_CON   , 0x0001 ); //immediate mode
/*MT6256RF*/       WAIT_TIME_QB(3);
/*MT6256RF*/       HW_WRITE( AFC_VALUE, 0x0E000000 ); // set AFC Value     
/*MT6256RF*/       HW_WRITE( AFC_DAT(0), (XO_CapID&0xFF) );
/*MT6256RF*/       HW_WRITE( AFC_CON   , 0x0001 ); //immediate mode
/*MT6256RF*/       WAIT_TIME_QB(3);
/*MT6256RF*/       HW_WRITE( AFC_CON   , 0x0000);  //event mode
/*MT6256RF*/       HW_WRITE( AFC_VALUE, 0x0E100000 ); // set AFC Value
/*MT6256RF*/    }
/*MT6256RF*/    IMM_SEND_BPI( 0x0000 ); //Switch SPI control to 3G
/*MT6256RF*/
/*MT6256RF*/ #else
/*MT6256RF*/    IMM_SEND_BPI( 0x0000 );
/*MT6256RF*/ #endif
/*MT6256RF*/
/*MT6256RF*/    IMM_MODE_END(  );
/*MT6256RF*/
/*MT6256RF*/    L1D_RF_TXPC_CL_AUXADC_POWERON();
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_PowerOff( void )
/*MT6256RF*/ {
/*MT6256RF*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6256RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x0C, 0x58230) );  //CW12: set ISO=1
/*MT6256RF*/ #if IS_CHIP_MT6256_S00
/*MT6256RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x102A0) );  //CW0: set DYN_EN=0
/*MT6256RF*/ #else
/*MT6256RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x18230) );  //CW0: set DYN_EN=0
/*MT6256RF*/ #endif
/*MT6256RF*/    IMM_MODE_END(  );
/*MT6256RF*/
/*MT6256RF*/    L1D_RF_TXPC_CL_AUXADC_POWEROFF();
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_WindowOn( void )
/*MT6256RF*/ {
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_WindowOff( void )
/*MT6256RF*/ {
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void L1D_RF_Switch_SPI_Control_to_3G( void )
/*MT6256RF*/ {
/*MT6256RF*/ #if IS_AST_B2S_SUPPORT
/*MT6256RF*/    extern void L1D_PowerManager( int );
/*MT6256RF*/
/*MT6256RF*/    L1D_PowerManager( 3 );
/*MT6256RF*/    L1D_RF_Init_BPI( );
/*MT6256RF*/    IMM_SEND_BPI( 0x0000 ); //send immedidate mode to switch SPI to 3G
/*MT6256RF*/ #endif
/*MT6256RF*/ }
#endif

#if IS_RF_MT6255RF
/*MT6255RF*/ #define RF_POR_NUM    (sizeof(SDATA_TABLE) /sizeof(unsigned long))
/*MT6255RF*/ #define RF_POR_NUM2   (sizeof(SDATA_TABLE2)/sizeof(unsigned long))
/*MT6255RF*/
/*MT6255RF*/ /* BSI control word in static digital block need to be modified after POR */
/*MT6255RF*/ const unsigned long SDATA_TABLE[] =
/*MT6255RF*/ {
/*MT6255RF*/    0x0454A66, /* CW4:  DFM Power */
/*MT6255RF*/    0x3F8BC86, /* CW63: VCO TCL */
/*MT6255RF*/    0x6181ABF, /* CW97: RX Power */
/*MT6255RF*/    0x625067A, /* CW98: RX FE */
/*MT6255RF*/    0x6B2C0F0, /* CW107: Blocker detection */
/*MT6255RF*/    0x8400FFA, /* CW132: TX EN */
/*MT6255RF*/ };
/*MT6255RF*/
/*MT6255RF*/ /* BSI control word in dynamic digital block need to be modified after wakeup */
/*MT6255RF*/ const unsigned long SDATA_TABLE2[] =
/*MT6255RF*/ {
/*MT6255RF*/    0x1055D5A, /* CW16: DFM LG */
/*MT6255RF*/    0x1917DBA, /* CW25: DFM LG */
/*MT6255RF*/    0x2373038, /* CW35: DFM LG */
/*MT6255RF*/ };
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_PowerOn( void )
/*MT6255RF*/ {
/*MT6255RF*/    unsigned short i;
/*MT6255RF*/    unsigned short BSI_num=0, BSI_num2=0;
/*MT6255RF*/ #if IS_AST_B2S_SUPPORT
/*MT6255RF*/    int b32=0;
/*MT6255RF*/ #endif
/*MT6255RF*/
/*MT6255RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6255RF*/
/*MT6255RF*/    if( l1d_rf.is_init )
/*MT6255RF*/    {
/*MT6255RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x18230) );   //CW0: set SOR=1 to reset SD
/*MT6255RF*/       BSI_num = RF_POR_NUM;
/*MT6255RF*/    }
/*MT6255RF*/
/*MT6255RF*/    BSI_num2 = RF_POR_NUM2;
/*MT6255RF*/
/*MT6255RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x58230) );      //CW0: set DYN_EN=1 to turn on DD
/*MT6255RF*/
/*MT6255RF*/    WAIT_TIME_QB(335);                                            //wait at least 310us
/*MT6255RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x0E, 0x80000) );      //CW14: set SOR_DD=1 to reset DD
/*MT6255RF*/
/*MT6255RF*/    if( !l1d_rf2.is_wakeup )
/*MT6255RF*/    {
/*MT6255RF*/       unsigned long cw132 = L1D_RF_SetTX_BSI_CW( QB_ST2B, 150 ); // MT6255RF enters TX mode in ST2B
/*MT6255RF*/
/*MT6255RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), cw132|(0x1<<18)                      );  //CW132: Enable to force to set AFC DAC in RX/TX mode
/*MT6255RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x39, l1d_rf.AFC_data&0x1FFF) );  //CW57:  Set previous AFC DAC value
/*MT6255RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x38, XO_CapID&0xFF)          );  //CW56:  Set previous Cap ID value
/*MT6255RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), cw132|(0x0<<18)                      );  //CW132: Disable to force to set AFC DAC in RX/TX mode
/*MT6255RF*/    }
/*MT6255RF*/
/*MT6255RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x0C, 0x18230) ); // CW12: ISO=0 control word in static digital block
/*MT6255RF*/
/*MT6255RF*/    for( i=0 ; i<BSI_num; i++ )
/*MT6255RF*/    {  IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE[i] );  }
/*MT6255RF*/
/*MT6255RF*/    for( i=0 ; i<BSI_num2; i++ )
/*MT6255RF*/    {  IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE2[i] ); }
/*MT6255RF*/
/*MT6255RF*/ #if IS_AST_B2S_SUPPORT
/*MT6255RF*/    if( !l1d_rf2.is_wakeup )
/*MT6255RF*/    {
/*MT6255RF*/       IMM_SEND_BPI( 0x0100 ); //Switch SPI control to 2G
/*MT6255RF*/
/*MT6255RF*/       for(b32=0;b32<4;b32++)
/*MT6255RF*/       {
/*MT6255RF*/          HW_WRITE(AFC_EV(b32),0x2700);
/*MT6255RF*/       }
/*MT6255RF*/       b32=HW_READ(TDMA_EVTENA(0));
/*MT6255RF*/       HW_WRITE(TDMA_EVTENA(0),b32&0xFFFF0FFF);
/*MT6255RF*/
/*MT6255RF*/       HW_WRITE( AFC_VALUE,   0x0E100000 );  // set AFC Value
/*MT6255RF*/       HW_WRITE( AFC_DAT(0),  (l1d_rf.AFC_data&0x1FFF) );
/*MT6255RF*/       HW_WRITE( AFC_CON,     0x0001 );      // immediate mode
/*MT6255RF*/       WAIT_TIME_QB(3);
/*MT6255RF*/       HW_WRITE( AFC_VALUE,   0x0E000000 );  // set AFC Value
/*MT6255RF*/       HW_WRITE( AFC_DAT(0),  (XO_CapID&0xFF) );
/*MT6255RF*/       HW_WRITE( AFC_CON,     0x0001 );      // immediate mode
/*MT6255RF*/       WAIT_TIME_QB(3);
/*MT6255RF*/       HW_WRITE( AFC_CON,     0x0000 );      // event mode
/*MT6255RF*/       HW_WRITE( AFC_VALUE,   0x0E100000 );  // set AFC Value
/*MT6255RF*/    }
/*MT6255RF*/    IMM_SEND_BPI( 0x0000 ); //Switch SPI control to 3G
/*MT6255RF*/
/*MT6255RF*/ #else
/*MT6255RF*/    IMM_SEND_BPI( 0x0000 );
/*MT6255RF*/ #endif
/*MT6255RF*/
/*MT6255RF*/    IMM_MODE_END(  );
/*MT6255RF*/
/*MT6255RF*/    L1D_RF_TXPC_CL_AUXADC_POWERON();
/*MT6255RF*/ }
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_PowerOff( void )
/*MT6255RF*/ {
/*MT6255RF*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6255RF*/
/*MT6255RF*/ #if IS_32K_CRYSTAL_REMOVAL_SUPPORT
/*MT6255RF*/    {  //Set LPM fractional divider before RF power off
/*MT6255RF*/       extern unsigned long L1D_GetDCXOFreqLPM(void);
/*MT6255RF*/       unsigned long dcxo_frac = L1D_GetDCXOFreqLPM();
/*MT6255RF*/
/*MT6255RF*/       if( !L1D_RF_Check_32K_XO_Status() )
/*MT6255RF*/       {  IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x4A, ((dcxo_frac&0xFFF)<<8)|0xFF) );  }
/*MT6255RF*/    }
/*MT6255RF*/ #endif
/*MT6255RF*/
/*MT6255RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x02, 0x10000) );  //CW2: set RF in sleep state
/*MT6255RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x0C, 0x58230) );  //CW12: set ISO=1
/*MT6255RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x18230) );  //CW0: set DYN_EN=0
/*MT6255RF*/    IMM_MODE_END(  );
/*MT6255RF*/
/*MT6255RF*/    L1D_RF_TXPC_CL_AUXADC_POWEROFF();
/*MT6255RF*/ }
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_WindowOn( void )
/*MT6255RF*/ {
/*MT6255RF*/ }
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_WindowOff( void )
/*MT6255RF*/ {
/*MT6255RF*/ }
/*MT6255RF*/
/*MT6255RF*/ void L1D_RF_Switch_SPI_Control_to_3G( void )
/*MT6255RF*/ {
/*MT6255RF*/ #if IS_AST_B2S_SUPPORT
/*MT6255RF*/    extern void L1D_PowerManager( int );
/*MT6255RF*/
/*MT6255RF*/    L1D_PowerManager( 3 );
/*MT6255RF*/    L1D_RF_Init_BPI( );
/*MT6255RF*/    IMM_SEND_BPI( 0x0000 ); //send immedidate mode to switch SPI to 3G
/*MT6255RF*/ #endif
/*MT6255RF*/ }
#endif

#if IS_RF_MT6251RF
/*MT6251RF*/ #define RF_POR_NUM    (sizeof(SDATA_TABLE)/sizeof(unsigned long))
/*MT6251RF*/ #define RF_POR_NUM2   (sizeof(SDATA_TABLE2)/sizeof(unsigned long))
/*MT6251RF*/
   #if IS_CHIP_MT6251_S00
/*MT6251RF*/ const unsigned long SDATA_TABLE[]=
/*MT6251RF*/ {
/*MT6251RF*/    0x6800000,  // CW104:for bias of high band mixer is not grounded
/*MT6251RF*/    0x6274662,  /* CW98: */
/*MT6251RF*/    0x03C44B7,  // CW3   for RF final setting
/*MT6251RF*/    0x6191ABF,  // CW97  for RF final setting
/*MT6251RF*/    0x6481280,  // CW100 for RF final setting
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ const unsigned long SDATA_TABLE2[]=
/*MT6251RF*/ {
/*MT6251RF*/    0x0C18230,  /* CW12: ISO=0 control word in static digital block */
/*MT6251RF*/    0x0816013,  /* CW8:  */
/*MT6251RF*/    0x0F01462,  /* CW15: */
/*MT6251RF*/    0x1041150,  /* CW16: */
/*MT6251RF*/    0x14F7DBA,  /* CW20: */
/*MT6251RF*/    0x15FFFFF,  /* CW21: */
/*MT6251RF*/    0x16FBA01,  /* CW22: */
/*MT6251RF*/    0x17FFF7D,  /* CW23: */
/*MT6251RF*/    0x18F01FF,  /* CW24: */
/*MT6251RF*/    0x1977DBA,  /* CW25: */
/*MT6251RF*/    0x8406FFA,  /* CW132:*/
/*MT6251RF*/    0x4200001,  /* CW66: for read auxout*/
/*MT6251RF*/ };
   #else /* For E2 chip */
/*MT6251RF*/ const unsigned long SDATA_TABLE[]=
/*MT6251RF*/ {
/*MT6251RF*/    0x6191ABF,  /* CW97 */
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ const unsigned long SDATA_TABLE2[]=
/*MT6251RF*/ {
/*MT6251RF*/    0x0C18230,  /* CW12 */ // ISO=0 control word in static digital block
/*MT6251RF*/    0x0058230,  /* CW0  */ // DYN_EN should be 1
/*MT6251RF*/    0x0455B66,  /* CW4  */
/*MT6251RF*/    0x1015D5A,  /* CW16 */
/*MT6251RF*/    0x12CFC10,  /* CW18 */
/*MT6251RF*/    0x15FFFFF,  /* CW21 */
/*MT6251RF*/    0x17FFF7D,  /* CW23 */
/*MT6251RF*/    0x1A9FFFF,  /* CW26 */
/*MT6251RF*/    0x1B90001,  /* CW27 */
/*MT6251RF*/    0x1C57ABC,  /* CW28 */
/*MT6251RF*/    0x1D0E064,  /* CW29 */
/*MT6251RF*/    0x1E96038,  /* CW30 */
/*MT6251RF*/    0x1F1912C,  /* CW31 */
/*MT6251RF*/    0x200E038,  /* CW32 */
/*MT6251RF*/    0x214B258,  /* CW33 */
/*MT6251RF*/    0x220E064,  /* CW34 */
/*MT6251RF*/    0x2339838,  /* CW35 */
/*MT6251RF*/    0x24FFD53,  /* CW36 */
/*MT6251RF*/    0x2500D57,  /* CW37 */
/*MT6251RF*/    0x26FEF11,  /* CW38 */
/*MT6251RF*/    0x27FE017,  /* CW39 */
/*MT6251RF*/    0x2805BCF,  /* CW40 */
/*MT6251RF*/    0x2904E49,  /* CW41 */
/*MT6251RF*/    0x2AF6C59,  /* CW42 */
/*MT6251RF*/    0x2BF8CAF,  /* CW43 */
/*MT6251RF*/    0x2C070C8,  /* CW44 */
/*MT6251RF*/    0x2D0490E,  /* CW45 */
/*MT6251RF*/    0x2EFC84C,  /* CW46 */
/*MT6251RF*/    0x2FFF2AA,  /* CW47 */
/*MT6251RF*/    0x3001232,  /* CW48 */
/*MT6251RF*/    0x31FFC6E,  /* CW49 */
/*MT6251RF*/    0x32FFFA2,  /* CW50 */
/*MT6251RF*/    0x3ECD480,  /* CW62 */
/*MT6251RF*/    0x6B6C0E0,  /* CW107 */
/*MT6251RF*/  //0x8406FFE,  /* CW132 */ // Note for not modify common code
/*MT6251RF*/    0x8580000,  /* CW133*/
/*MT6251RF*/    0x4200001,  /* CW66 */ // Read AUXOUT table
/*MT6251RF*/ };
   #endif
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_PowerOn( void )
/*MT6251RF*/ {
/*MT6251RF*/    unsigned short i;
/*MT6251RF*/    unsigned short BSI_num=0, BSI_num2=0;
/*MT6251RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6251RF*/
/*MT6251RF*/    if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6251RF*/    {
/*MT6251RF*/       if( l1d_rf.is_init )
/*MT6251RF*/       {
/*MT6251RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x00902A0 );   // CW0: set SOR=1 to reset SD
/*MT6251RF*/          BSI_num = RF_POR_NUM;
/*MT6251RF*/       }
/*MT6251RF*/    }
/*MT6251RF*/
/*MT6251RF*/    BSI_num2 = RF_POR_NUM2;
/*MT6251RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x00502A0 );      // CW0: set DYN_EN=1 to turn on DD
/*MT6251RF*/    WAIT_TIME_QB(272);                                // wait at least 250us
/*MT6251RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0E80000 );      // CW14: set SOR_DD=1 to reset DD
/*MT6251RF*/
/*MT6251RF*/    if( !l1d_rf2.is_wakeup )
/*MT6251RF*/    {
/*MT6251RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x8426FFA );
/*MT6251RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), (l1d_rf.AFC_data&0x1FFF)|0x3900000 );   // CW57: Set previous AFC DAC value
/*MT6251RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), (XO_CapID&0xFF)|0x3800000 );            // CW56: Set previous Cap ID value
/*MT6251RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x8406FFA );                            // CW132: releative to BFE TX timing
/*MT6251RF*/    }
/*MT6251RF*/
/*MT6251RF*/    for( i=0 ; i<BSI_num; i++ )
/*MT6251RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE[i] );
/*MT6251RF*/
/*MT6251RF*/    for( i=0 ; i<BSI_num2; i++ )
/*MT6251RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE2[i] );
/*MT6251RF*/
/*MT6251RF*/    IMM_SEND_BPI( 0x0000 );
/*MT6251RF*/    IMM_MODE_END(  );
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_PowerOff( void )
/*MT6251RF*/ {
/*MT6251RF*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6251RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0210000 );  // CW2: set mode = sleep mode
/*MT6251RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0C58230 );  // CW12: set ISO=1
/*MT6251RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x00102A0 );  // CW0: set DYN_EN=0
/*MT6251RF*/    IMM_MODE_END(  );
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_WindowOn( void )
/*MT6251RF*/ {
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_WindowOff( void )
/*MT6251RF*/ {
/*MT6251RF*/ }
#endif

#if IS_RF_SKY74045
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74045*/ #if defined(L1D_SIM)    // SXENA is used in dual mode RF conflict detection
/* under construction !*/
/*SKY74045*/ #endif                  // then we just need to do RF initialization once
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*AERO2*/ #ifndef AFCC
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
/*AERO2*/ #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*AERO2*/ #else
/* under construction !*/
/*AERO2*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO2*/ #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*AERO2*/ #else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif

#if IS_RF_AD6548
/*AD6548*/  #define INITIAL_REG0_RESET  0x00000000  /* Performs chip reset */
/*AD6548*/  #define INITIAL_REG0_NORST  0x00000080  /* No Reset performed */
/*AD6548*/  #define INITIAL_REG1        0x00000001|(XO_CapID<<8)
/*AD6548*/  #define INITIAL_REG5        0x00000105
/*AD6548*/  #define INITIAL_REG6        0x00291686
/*AD6548*/  #define INITIAL_REG29       0x0000001D
/*AD6548*/  #define INITIAL_REG31       0x0000001F
/*AD6548*/  #define PROG_POWER_CAL      0x00006384
/*AD6548*/  #define PROG_POWER_ON       0x00000184
/*AD6548*/  #define PROG_POWER_OFF      0x00000004
/*AD6548*/  #define PROG_CAL_BAND       0x00022F80
/*AD6548*/
/*AD6548*/  void  L1D_RF_PowerOn( void )
/*AD6548*/  {
/*AD6548*/     /* Turn Immediate Mode on*/
/*AD6548*/     IMM_MODE_BEGIN( IMMMASK_ALL );
/*AD6548*/
/*AD6548*/     /*Initialize pin value*/
/*AD6548*/     IMM_SEND_BPI( PDATA_INIT );
/*AD6548*/
/*AD6548*/  #if IS_BT_CO_CLOCK_HW_SUPPORT && IS_BT_COCLOCK_SUPPORT
/*AD6548*/     while ((HW_READ(SLEEP_SPI)&0x80)!= 0);
/*AD6548*/  #endif
/*AD6548*/
/*AD6548*/  #ifndef L1D_SIM
/*AD6548*/     if(l1d_rf.is_init)
/*AD6548*/     {
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG0_RESET ); /*Performs chip reset*/
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_ON );      /*Power on LDO1 & LDO2*/
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG5 );       /*BB gain 3dB*/
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG6 );       /*PLL Word*/
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG29 );      /*Test Register, initialize only*/
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG31 );      /*Test Register, initialize only*/
/*AD6548*/
/*AD6548*/        WAIT_TIME_QB(27);/* Wait 25 us after LDO1 and LDO2 on */
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_CAL ); /*Start auto calibration*/
/*AD6548*/
/*AD6548*/        WAIT_TIME_QB(27);/* Wait 25+25 us after LDO1 and LDO2 on */
/*AD6548*/
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_CAL_BAND );
/*AD6548*/
/*AD6548*/        WAIT_TIME_QB(4660);/* Wait 4.3ms for RF internal calibration done */
/*AD6548*/     }
/*AD6548*/  #endif
/*AD6548*/
/*AD6548*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG1 );  /* AFC_CAP */
/*AD6548*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_ON );
/*AD6548*/     IMM_MODE_END(  );/*Turn Immediate Mode off*/
/*AD6548*/  }
/*AD6548*/
/*AD6548*/  void  L1D_RF_PowerOff( void )
/*AD6548*/  {
/*AD6548*/     IMM_MODE_BEGIN( IMMMASK_BSI );
/*AD6548*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_OFF ); /* Sleep mode, turn off RF LDO1 and LDO2 */
/*AD6548*/     IMM_MODE_END(  );
/*AD6548*/  }
/*AD6548*/
/*AD6548*/  void  L1D_RF_WindowOn( void )
/*AD6548*/  {  }
/*AD6548*/
/*AD6548*/  void  L1D_RF_WindowOff( void )
/*AD6548*/  {  }
/*AD6548*/
/*AD6548*/  void  L1D_RF_CAP_Set( void )
/*AD6548*/  { /* Set calibrated AFC_CAP */
/*AD6548*/     IMM_MODE_BEGIN( IMMMASK_BSI );
/*AD6548*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG1 );
/*AD6548*/     IMM_MODE_END(  );
/*AD6548*/  }
/*AD6548*/
/*AD6548*/  void  L1D_RF_CAP_Clear( void )
/*AD6548*/  { /* Set AFC_CAP to 0 to speed up settling time*/
/*AD6548*/     IMM_MODE_BEGIN( IMMMASK_BSI );
/*AD6548*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x00000001 );
/*AD6548*/     IMM_MODE_END(  );
/*AD6548*/  }
/*AD6548*/
#endif

#if IS_RF_AD6546
/*AD6546*/  #define INITIAL_REG0_RESET  0x00000000  /*Performs chip reset */
/*AD6546*/  #define INITIAL_REG0_NORST  0x00000080  /*No Reset performed */
/*AD6546*/  #define INITIAL_REG1        0x00000001|(XO_CapID<<7)
/*AD6546*/  #define INITIAL_REG5        0x00000105
/*AD6546*/  #define INITIAL_REG6        0x00291686
   #if IS_HW_DISABLE_EPSK_TX_SUPPORT
/*AD6546*/  #define INITIAL_REG30       0x0084001E
   #else
/*AD6546*/  #define INITIAL_REG30       0x00081F9E
   #endif
/*AD6546*/  #define INITIAL_REG31       0x0003901f  /*ICP/2,TX PLL BW +12%,Fast lock enable,-6dB VGA intercept shift*/
/*AD6546*/  #define PROG_POWER_CAL      0x00006384
/*AD6546*/  #define PROG_POWER_ON       0x00000184
/*AD6546*/  #define PROG_POWER_OFF      0x00000004
/*AD6546*/  #define PROG_CAL_BAND       0x00002F80|(HIGH_BAND_PATH<<16)|((1-LOW_BAND_PATH)<<17)
/*AD6546*/
/*AD6546*/  void  L1D_RF_PowerOn( void )
/*AD6546*/  {
/*AD6546*/     /* Turn Immediate Mode on*/
/*AD6546*/     IMM_MODE_BEGIN( IMMMASK_ALL );
/*AD6546*/
/*AD6546*/     /*Initialize pin value*/
/*AD6546*/     IMM_SEND_BPI( PDATA_INIT );
/*AD6546*/
/*AD6546*/  #if IS_BT_CO_CLOCK_HW_SUPPORT && IS_BT_COCLOCK_SUPPORT
/*AD6546*/     while ((HW_READ(SLEEP_SPI)&0x80)!= 0);
/*AD6546*/  #endif
/*AD6546*/
/*AD6546*/  #ifndef L1D_SIM
/*AD6546*/     if(l1d_rf.is_init)
/*AD6546*/     {
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG0_RESET );   /*Performs chip reset */
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_ON );        /*Power on LDO1 & LDO2 */
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG5 );         /*BB gain 3dB */
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG6 );         /*Initial PLL Word ARFCN 62*/
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG30 );        /*Test Register, initialize only */
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG31 );        /*ICP/2,TX PLL BW +12%,Fast lock enable,-6dB VGA intercept shift*/
/*AD6546*/
/*AD6546*/        WAIT_TIME_QB(27);/* Wait 25 us after LDO1 and LDO2 on */
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_CAL ); /*Start auto calibration*/
/*AD6546*/
/*AD6546*/        WAIT_TIME_QB(27);/* Wait 25+25 us after LDO1 and LDO2 on */
/*AD6546*/
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_CAL_BAND );
/*AD6546*/
/*AD6546*/        WAIT_TIME_QB(4660);/* Wait 4.3ms for RF internal calibration done */
/*AD6546*/
/*AD6546*/     }
/*AD6546*/  #endif
/*AD6546*/
/*AD6546*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG1 );  /*AFC_CAP */
/*AD6546*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_ON );
/*AD6546*/     IMM_MODE_END(  );/*Turn Immediate Mode off*/
/*AD6546*/  }
/*AD6546*/
/*AD6546*/  void  L1D_RF_PowerOff( void )
/*AD6546*/  {
/*AD6546*/     IMM_MODE_BEGIN( IMMMASK_BSI );
/*AD6546*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_OFF ); /* Sleep mode, turn off RF LDO1 and LDO2 */
/*AD6546*/     IMM_MODE_END(  );
/*AD6546*/  }
/*AD6546*/
/*AD6546*/  void  L1D_RF_WindowOn( void )
/*AD6546*/  {  }
/*AD6546*/
/*AD6546*/  void  L1D_RF_WindowOff( void )
/*AD6546*/  {  }
/*AD6546*/
/*AD6546*/  void  L1D_RF_CAP_Set( void )
/*AD6546*/  { /* Set calibrated AFC_CAP */
/*AD6546*/     IMM_MODE_BEGIN( IMMMASK_BSI );
/*AD6546*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG1 );
/*AD6546*/     IMM_MODE_END(  );
/*AD6546*/  }
/*AD6546*/
/*AD6546*/  void  L1D_RF_CAP_Clear( void )
/*AD6546*/  { /* Set AFC_CAP to 0 to speed up settling time*/
/*AD6546*/     IMM_MODE_BEGIN( IMMMASK_BSI );
/*AD6546*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x00000001 );
/*AD6546*/     IMM_MODE_END(  );
/*AD6546*/  }
/*AD6546*/
#endif

#if IS_RF_MT6162
/*MT6162*/
/*MT6162*/  #include "intrCtrl.h"
/*MT6162*/
/*MT6162*/  /* CW[29]    : data bit; 1=>DFM data, 0=>control word */
/*MT6162*/  /* CW[28]    : read bit; 1=>read,     0=>write        */
/*MT6162*/  /* CW[27:20] : address                                */
/*MT6162*/  /* CW[19: 0] : data                                   */
/*MT6162*/
/*MT6162*/  /* for power up */
/*MT6162*/  #define INIT_DDC_RESET_SWPOR       0x0D000001L
/*MT6162*/  #define INIT_DDC_LDOCTR_DIGEN      0x0D120001L
/*MT6162*/  #define INIT_DDC_RESET_RELEASE     0x0D00003EL
/*MT6162*/  #define INIT_TX_LO_L               0x0B42C89FL /* for E1 and E2 */
/*MT6162*/  #define INIT_TX_LO_H               0x0B532723L /* for E1 and E2 */
/*MT6162*/  #define INIT_PDCADC_CONFIG         0x0B10EAA8L /* for E1 and E2 */
/*MT6162*/  #define INIT_CW10                  0x00A41150L /* for E1 and E2 */
/*MT6162*/  #define INIT_CW44                  0x02CFFFFFL /* for E1 and E2 */
/*MT6162*/  #define INIT_RX_ABB                0x08504100L /* for E1 and E2 */
/*MT6162*/  #define INIT_RX_GAIN_TEST          0x09031000L /* for E1 and E2 */
/*MT6162*/  #define INIT_GMSK_DATA             0x0A704D85L /* for E1 and E2 */
/*MT6162*/  #define INIT_TTG_TEST              0x09707000L /* for E1 and E2, for 3G use, TTG_CP_OW_EN=1 and TTG_CP_I_SEL=3 */
/*MT6162*/  #define INIT_TX_GAINWRITE          0x0A40FFFCL /* for E1 and E2, set the smallest gain */
/*MT6162*/  #define INIT_TX_BB_FILT_2G         0x0AC20948L /* for E1 and E2 */
/*MT6162*/  #define INIT_TX_GAINRF_2G          0x0C04A864L /* for E1 and E2 */
/*MT6162*/  #define INIT_SRX_LF_ADJUST         0x06747028L /* for E1 and E2 */
/*MT6162*/  #define INIT_SRX_CP_ADJUST         0x06800019L /* for E1 and E2 */
/*MT6162*/  #define INIT_GAINRF_LUT0           0x0C175320L /* only for E1 */
/*MT6162*/  #define INIT_GAINRF_LUT1           0x0C2CBA98L /* only for E1 */
/*MT6162*/  #define INIT_GAINRF_LUT2           0x0C30DDDDL /* only for E1 */
/*MT6162*/  #define INIT_CW03                  0x00340365L /* only for E1 */
/*MT6162*/  #define INIT_CW41                  0x02901495L /* only for E1 */
/*MT6162*/  #define INIT_CW42                  0x02A01425L /* only for E1 */
/*MT6162*/  #define INIT_SRX_GEN_TEST          0x06600000L /* only for E1 */
/*MT6162*/  #define INIT_SRX_VCO_CONFIG        0x06900D37L /* only for E1 */
/*MT6162*/  #define INIT_SRX_VCO_TEST          0x06A00770L /* only for E1 */
/*MT6162*/  #define INIT_STX_VCO_CONFIG        0x02731C00L /* only for E1 */
/*MT6162*/  #define INIT_CW14                  0x00EFFD53L /* only for E2 */
/*MT6162*/  #define INIT_CW15                  0x00F00D57L /* only for E2 */
/*MT6162*/  #define INIT_CW16                  0x010FEF11L /* only for E2 */
/*MT6162*/  #define INIT_CW17                  0x011FE017L /* only for E2 */
/*MT6162*/  #define INIT_CW18                  0x01205BCFL /* only for E2 */
/*MT6162*/  #define INIT_CW19                  0x01304E49L /* only for E2 */
/*MT6162*/  #define INIT_CW20                  0x014F6C59L /* only for E2 */
/*MT6162*/  #define INIT_CW21                  0x015F8CAFL /* only for E2 */
/*MT6162*/  #define INIT_CW22                  0x016070C8L /* only for E2 */
/*MT6162*/  #define INIT_CW23                  0x0170490EL /* only for E2 */
/*MT6162*/  #define INIT_CW24                  0x018FC84CL /* only for E2 */
/*MT6162*/  #define INIT_CW25                  0x019FF2AAL /* only for E2 */
/*MT6162*/  #define INIT_CW26                  0x01A01232L /* only for E2 */
/*MT6162*/  #define INIT_CW27                  0x01BFFC6EL /* only for E2 */
/*MT6162*/  #define INIT_CW28                  0x01CFFFA2L /* only for E2 */
/*MT6162*/  #define INIT_CW29                  0x01D00000L /* only for E2 */
/*MT6162*/  #define INIT_CW43                  0x02B9C00CL /* only for E2 */
/*MT6162*/  #define INIT_CW58                  0x03A39878L /* only for E2 */
/*MT6162*/  #define INIT_CW00_E1               0x000402A0L /* for E1 */
/*MT6162*/  #define INIT_CW00_E2               0x000402A8L /* for E2, increase the CP to increase Loop BW for freq error */
/*MT6162*/  #define INIT_SRX_VCOCAL_E1         0x065E0000L /* for E1, AFC enable */
/*MT6162*/  #define INIT_SRX_VCOCAL_E2         0x06560000L /* for E2, AFC enable */
/*MT6162*/  #define INIT_DCXO_CDAC_MASK        0x0E000000L /* for CapID */
/*MT6162*/
/*MT6162*/  #define INIT_REGISTER_NUM_E1       26
/*MT6162*/  #define INIT_REGISTER_NUM_E2       34
/*MT6162*/  unsigned long rfid_readback;
/*MT6162*/  const unsigned long SDATA_INIT_REGISTER_E1[INIT_REGISTER_NUM_E1]=
/*MT6162*/  {
/*MT6162*/     INIT_TX_LO_L,        INIT_TX_LO_H,        INIT_PDCADC_CONFIG,
/*MT6162*/     INIT_CW10,           INIT_CW44,           INIT_RX_ABB,
/*MT6162*/     INIT_RX_GAIN_TEST,   INIT_GMSK_DATA,      INIT_TTG_TEST,
/*MT6162*/     INIT_TX_BB_FILT_2G,  INIT_TX_GAINRF_2G,   INIT_TX_GAINWRITE,
/*MT6162*/     INIT_GAINRF_LUT0,    INIT_GAINRF_LUT1,    INIT_GAINRF_LUT2,
/*MT6162*/     INIT_CW00_E1,        INIT_CW03,           INIT_CW41,
/*MT6162*/     INIT_CW42,           INIT_SRX_GEN_TEST,   INIT_SRX_LF_ADJUST,
/*MT6162*/     INIT_SRX_CP_ADJUST,  INIT_SRX_VCO_CONFIG, INIT_SRX_VCO_TEST,
/*MT6162*/     INIT_STX_VCO_CONFIG, INIT_SRX_VCOCAL_E1,
/*MT6162*/  }; 
/*MT6162*/     
/*MT6162*/  const unsigned long SDATA_INIT_REGISTER_E2[INIT_REGISTER_NUM_E2]=
/*MT6162*/  {  
/*MT6162*/     INIT_TX_LO_L,        INIT_TX_LO_H,        INIT_PDCADC_CONFIG,
/*MT6162*/     INIT_CW10,           INIT_CW44,           INIT_RX_ABB,
/*MT6162*/     INIT_SRX_LF_ADJUST,  INIT_SRX_CP_ADJUST,  INIT_TX_BB_FILT_2G,
/*MT6162*/     INIT_TX_GAINRF_2G,   INIT_SRX_VCOCAL_E2,  INIT_RX_GAIN_TEST,
/*MT6162*/     INIT_GMSK_DATA,      INIT_TTG_TEST,       INIT_TX_GAINWRITE,
/*MT6162*/     INIT_CW00_E2,        INIT_CW14,           INIT_CW15,
/*MT6162*/     INIT_CW16,           INIT_CW17,           INIT_CW18,
/*MT6162*/     INIT_CW19,           INIT_CW20,           INIT_CW21,
/*MT6162*/     INIT_CW22,           INIT_CW23,           INIT_CW24,
/*MT6162*/     INIT_CW25,           INIT_CW26,           INIT_CW27,
/*MT6162*/     INIT_CW28,           INIT_CW29,           INIT_CW43,
/*MT6162*/     INIT_CW58,
/*MT6162*/  };
/*MT6162*/
/*MT6162*/  /* for power down */
/*MT6162*/  #define TX_MODE_CTRL_PWRDWN        0x0A100000L
/*MT6162*/  #define RX_MODE_PWRDWN             0x08100000L
/*MT6162*/  #define DDC_LDOCTR_IDLE            0x0D120000L
/*MT6162*/  #define DDC_RESET_RESET            0x0D000000L
/*MT6162*/  #define DDC_LDOCTR_DUPLEX_OFF      0x0D120001L
/*MT6162*/
/*MT6162*/  /* for baseband filter calibration */
/*MT6162*/  #define DDC_LDOCTR_RXFLTCAL        0x0D124101L
/*MT6162*/  #define RX_RCCAL_LPFCAL            0x084000EEL /* 0526 TzeYee updated, original setting=>0x084000E4L */
/*MT6162*/  #define RX_RCCAL_WRITEBACK_MASK    0x084002E4L
/*MT6162*/  #define DDC_LDOCTR_RXFLTCAL_OFF    0x0D120001L
/*MT6162*/
/*MT6162*/  /* for calibration readback */
/*MT6162*/  unsigned long lpfcap_readback;
/*MT6162*/
/*MT6162*/  extern void L1D_DM_Power_Control_Trace( char is_2g, char is_3g );
/*MT6162*/  void  L1D_RF_PowerOn( void )
/*MT6162*/  {  int i;
/*MT6162*/     unsigned long _savedMask;
/*MT6162*/     unsigned long ctrl, data;
/*MT6162*/              long addr;
/*MT6162*/
/*MT6162*/     /* Turn Immediate Mode on */
/*MT6162*/     if( IS_AFC_TRIGGER_BSI() )
/*MT6162*/     {  IMM_MODE_BEGIN( IMMMASK_BSI|IMMMASK_BPI );  }
/*MT6162*/     else
/*MT6162*/     {  IMM_MODE_BEGIN( IMMMASK_ALL );              }
/*MT6162*/
/*MT6162*/     if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6162*/     {
/*MT6162*/        if( l1d_rf.is_init )
/*MT6162*/        {
/*MT6162*/           L1D_PMU_VRF18Setting( 1 );                                   /* Enable VDD_18 (controlled by PMIC) */
/*MT6162*/           l1d_rf2.is_2g_on = 2;                                        /* Record the PMU step                */
/*MT6162*/           L1D_PMU_VRF28Setting( 1 );                                   /* Enable VDD_28 (controlled by PMIC) */
/*MT6162*/           l1d_rf2.is_2g_on = 4;                                        /* Record the PMU step                */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), INIT_DDC_RESET_SWPOR );      /* DDC_RESET_Reset */
/*MT6162*/           WAIT_TIME_QB( 300 );                                         /* wait for SW POR */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), INIT_DDC_LDOCTR_DIGEN );     /* DDC_LDOCTR_DigEn */
/*MT6162*/           WAIT_TIME_QB(55);                                            /* 50us, Wait T_LDO */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), INIT_DDC_RESET_RELEASE );    /* DDC_RESET_Release */
/*MT6162*/
/*MT6162*/           IMM_RECEIVE_BSI( SCTRL_IMOD(0,10), 0xEF, SCTRL_IMOD(0,20), &(rfid_readback) ); /* read back RFID */
/*MT6162*/           l1d_rf2.mt6162_rfid = (char) ( rfid_readback&0xFF );
/*MT6162*/
/*MT6162*/           if( L1D_RF_Get6162Version() == 1 )
/*MT6162*/           {  /* Set values into initialization registers for OH E1 */
/*MT6162*/              for( i=0; i<INIT_REGISTER_NUM_E1; i++ )
/*MT6162*/              {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_INIT_REGISTER_E1[i] );  }
/*MT6162*/           }
/*MT6162*/           else
/*MT6162*/           {  /* Set values into initialization registers for OH E2 */
/*MT6162*/              for( i=0; i<INIT_REGISTER_NUM_E2; i++ )
/*MT6162*/              {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_INIT_REGISTER_E2[i] );  }
/*MT6162*/              IMM_SEND_BSI( SCTRL_IMOD(0,30), L1D_RF_GetClockControl() );
/*MT6162*/           }
/*MT6162*/           l1d_rf2.is_2g_on = 1;                                        /* set 2G flag to notify 2G is ON */
/*MT6162*/           L1D_DM_Power_Control_Trace( 1, 2 );                          /* indicate the init state */
/*MT6162*/        }
/*MT6162*/        else
/*MT6162*/        {
/*MT6162*/ #if defined(__UMTS_RAT__)
/* under construction !*/
/*MT6162*/ #endif
/*MT6162*/           _savedMask = SaveAndSetIRQMask();                            /* disable interrupt */
/*MT6162*/           
/*MT6162*/ #if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6162*/ #endif
/*MT6162*/           {
/*MT6162*/              l1d_rf2.is_2g_on = 1;                                     /* set 2G flag to notify 2G is ON */
/*MT6162*/              L1D_DM_Power_Control_Trace( 1, 0 );                       /* indicate 2G is ON and 3G is OFF */
/*MT6162*/              RestoreIRQMask(_savedMask);                               /* enable interrupt */
/*MT6162*/              L1D_PMU_VRF18Setting( 1 );                                /* Enable VDD_18 (controlled by PMIC) */
/*MT6162*/              l1d_rf2.is_2g_on = 3;                                     /* Record the PMU step                */
/*MT6162*/              L1D_PMU_VRF28Setting( 1 );                                /* Enable VDD_28 (controlled by PMIC) */
/*MT6162*/              l1d_rf2.is_2g_on = 5;                                     /* Record the PMU step                */
/*MT6162*/              IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_RESET_RESET );        /* DDC_RESET_Reset */
/*MT6162*/              IMM_SEND_BSI( SCTRL_IMOD(0,30), INIT_DDC_LDOCTR_DIGEN );  /* DDC_LDOCTR_DigEn */
/*MT6162*/              WAIT_TIME_QB(55);                                         /* 50us, Wait T_LDO */
/*MT6162*/              IMM_SEND_BSI( SCTRL_IMOD(0,30), INIT_DDC_RESET_RELEASE ); /* DDC_RESET_Release */
/*MT6162*/
/*MT6162*/              if( L1D_RF_Get6162Version()==1 )
/*MT6162*/              {  /* Set values into initialization registers for OH E1 */
/*MT6162*/                 for( i=0; i<INIT_REGISTER_NUM_E1; i++ )
/*MT6162*/                 {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_INIT_REGISTER_E1[i] );  }
/*MT6162*/              }
/*MT6162*/              else
/*MT6162*/              {  /* Set values into initialization registers for OH E2 */
/*MT6162*/                 for( i=0; i<INIT_REGISTER_NUM_E2; i++ )
/*MT6162*/                 {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_INIT_REGISTER_E2[i] );  }
/*MT6162*/                 IMM_SEND_BSI( SCTRL_IMOD(0,30), L1D_RF_GetClockControl() );
/*MT6162*/              }
/*MT6162*/           }
/*MT6162*/        }
/*MT6162*/
/*MT6162*/
/*MT6162*/        if( l1d_rf.is_init )
/*MT6162*/        {
/*MT6162*/           /* Initial Calibration */
/*MT6162*/           L1D_RF_BASEBAND_FILTER_CAL();
/*MT6162*/        }
/*MT6162*/        else
/*MT6162*/        {
/*MT6162*/           /* Write back the LPFCAP[4:0] value to the RX_RCCAL(0x84) register */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), ((l1d_rf2.lpfcap&0x1F)<<10)|RX_RCCAL_WRITEBACK_MASK );
/*MT6162*/        }
/*MT6162*/     }
/*MT6162*/     else
/*MT6162*/     {
/*MT6162*/        ctrl = SCTRL_IMOD(0,30);
/*MT6162*/        data = (XO_CapID&0xFF)|INIT_DCXO_CDAC_MASK;
/*MT6162*/        HW_WRITE( BSI_CON, SCTRL_IMOD_MAIN );
/*MT6162*/        addr = (long)BSI_Dn_CON(103);
/*MT6162*/        HW_WRITE( (APBADDR)addr, ctrl );  addr += 4;
/*MT6162*/        HW_WRITE_BSI_DATA( addr, data );
/*MT6162*/        HW_DUMMY_READ_BSI_DATA( addr );
   #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H
/*MT6162*/        HW_WRITE( GSM_BSI_ACTUPT, 0x8067 ); /* update BSI_103 to the active buffer */
/*MT6162*/        HW_DUMMY_READ_BSI_DATA( addr );
   #endif
/*MT6162*/        HW_WRITE( BSI_CON, SCTRL_IMOD_SEND);
/*MT6162*/        WAIT_TIME_QB(IMM_BSI_WAIT_TIME_QB);
/*MT6162*/
/*MT6162*/        data = L1D_RF_GetClockControl();
/*MT6162*/        HW_WRITE( BSI_CON, SCTRL_IMOD_MAIN );
/*MT6162*/        addr = (long)BSI_Dn_CON(103);
/*MT6162*/        HW_WRITE( (APBADDR)addr, ctrl );  addr += 4;
/*MT6162*/        HW_WRITE_BSI_DATA( addr, data );
/*MT6162*/        HW_DUMMY_READ_BSI_DATA( addr );
   #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H
/*MT6162*/        HW_WRITE( GSM_BSI_ACTUPT, 0x8067 ); /* update BSI_103 to the active buffer */
/*MT6162*/        HW_DUMMY_READ_BSI_DATA( addr );
   #endif
/*MT6162*/        HW_WRITE( BSI_CON, SCTRL_IMOD_SEND );
/*MT6162*/        WAIT_TIME_QB( IMM_BSI_WAIT_TIME_QB );
/*MT6162*/
/*MT6162*/        addr = (long)BSI_Dn_CON(103);       /* set BSI_103 back to SCTRL_RESERVED */
/*MT6162*/        HW_WRITE( (APBADDR)addr, SCTRL_RESERVED );  addr += 4;
/*MT6162*/        HW_WRITE_BSI_DATA( addr, 0 );
/*MT6162*/     }
/*MT6162*/     /* Turn Immediate Mode off */
/*MT6162*/     IMM_MODE_END(  );
/*MT6162*/
/*MT6162*/     L1D_RF_TXPC_CL_AUXADC_POWERON();
/*MT6162*/  }
/*MT6162*/
/*MT6162*/  void  L1D_RF_PowerOff( void )
/*MT6162*/  {
/*MT6162*/     unsigned long _savedMask;
/*MT6162*/
/*MT6162*/     IMM_MODE_BEGIN( IMMMASK_BSI );                                 /* Turn Immediate Mode on */
/*MT6162*/
/*MT6162*/     if(1) //if( l1d_rf.is_sleep ) /* in the case of entering the sleep mode */
/*MT6162*/     {
/*MT6162*/ #if defined(__UMTS_RAT__)
/* under construction !*/
/*MT6162*/ #endif
/*MT6162*/        _savedMask = SaveAndSetIRQMask();                           /* disable interrupt */
/*MT6162*/        
/*MT6162*/ #if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6162*/ #endif
/*MT6162*/        {
/*MT6162*/           l1d_rf2.is_2g_on = 0;                                    /* clear 2G flag to notify 2G is OFF */
/*MT6162*/           L1D_DM_Power_Control_Trace( 0, 0 );                      /* indicate 2G is OFF and 3G is OFF */
/*MT6162*/           RestoreIRQMask(_savedMask);                              /* enable interrupt */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), TX_MODE_CTRL_PWRDWN );   /* TX_MODE_CTRL_PwrDwn */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), RX_MODE_PWRDWN );        /* RXMODE_PwrDwn */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_LDOCTR_IDLE );       /* DDC_LDOCTR, disable LDOs */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_RESET_RESET );       /* DDCCtrl_ResetDig */
/*MT6162*/           L1D_PMU_VRF18Setting( 0 );                               /* Disable VDD_18 (controlled by PMIC) */
/*MT6162*/           l1d_rf2.is_2g_on = 6;                                    /* Record the PMU step                 */
/*MT6162*/           L1D_PMU_VRF28Setting( 0 );                               /* Disable VDD_28 (controlled by PMIC) */
/*MT6162*/           l1d_rf2.is_2g_on = 8;                                    /* Record the PMU step                 */
/*MT6162*/        }
/*MT6162*/     }
/*MT6162*/     else
/*MT6162*/     {
/*MT6162*/        IMM_SEND_BSI( SCTRL_IMOD(0,30), TX_MODE_CTRL_PWRDWN );      /* TX_MODE_CTRL_PwrDwn */
/*MT6162*/        IMM_SEND_BSI( SCTRL_IMOD(0,30), RX_MODE_PWRDWN );           /* RXMODE_PwrDwn */
/*MT6162*/        /* In Meta, when 3G RF TOOL is selected, L1D_RF_PowerOff will be called */
/*MT6162*/        /* DDC_LDOCTR_Idle/DDC_RESET_reset turns off OH all function and initialized registers so 3G can't work */
/*MT6162*/        IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_LDOCTR_DUPLEX_OFF );    /* keep LDO in the digital state */
/*MT6162*/     }
/*MT6162*/
/*MT6162*/     IMM_MODE_END(  );                                              /* Turn Immediate Mode off */
/*MT6162*/
/*MT6162*/     L1D_RF_TXPC_CL_AUXADC_POWEROFF();
/*MT6162*/  }
/*MT6162*/
/*MT6162*/  void  L1D_RF_WindowOn( void )
/*MT6162*/  {  }
/*MT6162*/
/*MT6162*/  void  L1D_RF_WindowOff( void )
/*MT6162*/  {  }
/*MT6162*/
/*MT6162*/  void L1D_RF_BASEBAND_FILTER_CAL( void )
/*MT6162*/  {
/*MT6162*/     IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_LDOCTR_RXFLTCAL );         /* enable digital LDO and RX LDO */
/*MT6162*/     WAIT_TIME_QB( 55 );                                            /* 50us, Wait T_LDO */
/*MT6162*/     IMM_SEND_BSI( SCTRL_IMOD(0,30), RX_RCCAL_LPFCAL );             /* start the calibration */
/*MT6162*/     WAIT_TIME_QB( 44 );                                            /* 40us, Wait T_LPFCal*/
/*MT6162*/     IMM_RECEIVE_BSI( SCTRL_IMOD(0,10), 0x84, SCTRL_IMOD(0,20), &(lpfcap_readback) );
/*MT6162*/     l1d_rf2.lpfcap = (char)( (lpfcap_readback>>10) & 0x1F );
/*MT6162*/     IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_LDOCTR_RXFLTCAL_OFF );     /* turn off LDO */
/*MT6162*/  }
/*MT6162*/
#endif

