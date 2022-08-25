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
 *    pfc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is point-to-point protocol framer coprocessor driver header file.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
  * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef PFC_HW_H
#define PFC_HW_H
/*add by RHR suggest Add*/ 
#include "reg_base.h"
/*add by RHR suggest Add*/ 

#if defined(MT6270A)
#define pfc_base     0xD0070000//0xB0070000//0x801f0000
#else
#define pfc_base     PFC_base//0xD0070000//0xB0070000//0x801f0000
#endif
#define PFC_START    pfc_base
#define PFC_CON      (pfc_base + 0x04)
#define PFC_PTC      (pfc_base + 0x08)
#define PFC_SADDR    (pfc_base + 0x10)
#define PFC_SRC      (pfc_base + 0x14)
#define PFC_USLEN    (pfc_base + 0x18)
#define PFC_DES      (pfc_base + 0x1C)
#define PFC_UDLEN    (pfc_base + 0x20)
#define PFC_INTEN    (pfc_base + 0x24)
#define PFC_STAT     (pfc_base + 0x28)
#define PFC_SDRAT    (pfc_base + 0x2C)
#define PFC_ACCM0    (pfc_base + 0x30)
#define PFC_ACCM1    (pfc_base + 0x34)
#define PFC_ACCM2    (pfc_base + 0x38)
#define PFC_ACCM3    (pfc_base + 0x3C)
#define PFC_ACCM4    (pfc_base + 0x40)
#define PFC_ACCM5    (pfc_base + 0x44)
#define PFC_ACCM6    (pfc_base + 0x48)
                                 
//PFC_START register
#define PFC_START_BIT  0x01
#define PFC_CLR        0x02
#define PFC_DSET7E     0x04
#define PFC_DF7E       0x08
#define PFC_ELASTS     0x10
#define PFC_ELASTD     0x20
#define PFC_WSTAT      0x40
#define PFC_RSTAT      0x80
#define PFC_M_SRC      0x100
#define PFC_M_SL       0x200
#define PFC_M_DES      0x400
#define PFC_M_DL       0x800
#define PFC_LL_EN      0x1000

#define PFC_START_INIT 0x7 //PFC_START_BIT | PFC_CLR | PFC_DSET7E

//PFC_CON register
#define PFC_ENC   0x1
#define PFC_ACFC  0x2
#define PFC_PFC   0x4
#define PFC_F32   0x8

//PFC_INTEN register
#define PFC_INTEN_BIT  0x1

//PFC_STAT register
#define PFC_OK             0x0
#define PFC_BUSY           0x1
#define PFC_WRITE_FULL     0x2
#define PFC_ZERO_LENGTH    0x3
#define PFC_FCS_ERROR      0x4
#define PFC_NOT_0X7E       0x5
#define PFC_ADR_CON_ERROR  0x6
#define PFC_INVALID        0x7
#define PFC_RESUME         0x8
#define PFC_PROTOCOL_ERROR 0x9

#define ACCM3_FLAG   0x4000 //ACCM3 bit 14
#define ACCM3_ESCAPE 0x2000 //ACCM3 bit 13

#define SADDR_SIZE  64

#define ACCM_ALL  0xFFFF
#endif //PFC_HW_H
