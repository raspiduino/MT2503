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
 *   idp_mem_def.h
 *
 * Project:
 * --------
 *	 All
 *
 * Description:
 * ------------
 *   Various constant for memory size computation
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
 * 11 29 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 05 27 2011 chelun.tsai
 * removed!
 * MT6526 E2 MDP driver.
 *
 * 01 07 2011 chrono.wu
 * removed!
 * .
 *
 * 12 20 2010 chrono.wu
 * removed!
 * .
 *
 * 11 29 2010 cm.huang
 * removed!
 * .
 *
 * 11 29 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_mem_def_h__
#define __idp_mem_def_h__

#include "drv_features_mdp.h"

#if defined(DRV_IDP_6238_SERIES)
#include <mt6238/idp_mem.h>
#endif // #if defined(DRV_IDP_6238_SERIES)

#if defined(DRV_IDP_6253_SERIES)
#include <mt6253/idp_mem.h>
#endif // #if defined(DRV_IDP_6253_SERIES)

#if defined(DRV_IDP_6252_SERIES)
#include <mt6252/idp_mem.h>
#endif // #if defined(DRV_IDP_6252_SERIES)

#if defined(DRV_IDP_6235_SERIES)
#include <mt6235/idp_mem.h>
#endif // #if defined(DRV_IDP_6235_SERIES)

#if defined(DRV_IDP_MT6236_SERIES)
#include <mt6236/idp_mem.h>
#endif // #if defined(DRV_IDP_MT6236_SERIES)

#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6276E2_SERIES) || defined(DRV_IDP_MT6256_E1_SERIES)
#include <mt6276/idp_mem.h>
#endif // #if defined(DRV_IDP_MT6276_SERIES)

#if defined(DRV_IDP_MT6256_E2_SERIES)
#include <mt6256_e2/idp_mem.h>
#endif // #if defined(DRV_IDP_MT6256_E2_SERIES)

#if defined(DRV_IDP_MT6255_SERIES)
#include <mt6255/idp_mem.h>
#endif // #if defined(DRV_IDP_MT6255_SERIES)
#endif // __idp_mem_def_h__
