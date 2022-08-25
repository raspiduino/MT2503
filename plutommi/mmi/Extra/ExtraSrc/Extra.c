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
 * Extra.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements main menu screen of Extra applications.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_EXTRA_C
#define _MMI_EXTRA_C

/*  Include: MMI header file */

#include "MainMenuDef.h"
#include "ExtraDef.h"
#include "Calculator.h" /* for calculator */
#if (defined(__MMI_ZAKAT_CALCULATOR__) && !defined(__COSMOS_MMI_PACKAGE__))
#include "ZakatCalculator.h" /* for zakat calculator */
#endif
#include "unitconvertor.h"      /* for converters */


#include "SettingGprots.h"      /* for aphorism */
#include "SettingProt.h"
//#include "SimDetectionGexdcl.h"
#include "MessagesExDcl.h"
#include "PopulateRes.h"
#if defined (__MMI_CURRENCY_CONVERTER__)
#include "currencyconvertor.h"
#endif 
#if defined (__MMI_EBOOK_READER__)
#include "FileManagerGprot.h"
#include "EbookGprot.h"
#endif 
#ifdef __MMI_MESSAGES_CLUB__
#include "SATGProts.h"
#endif 
#ifdef __MMI_DICTIONARY__
#include "DictionaryMain.h"
#endif 
#if (defined(__MMI_STOPWATCH__) && !defined(__COSMOS_MMI_PACKAGE__))
#include "StopwatchGprot.h"
#endif
/* 
 * Define
 */
// #define APR_TEXT_CHARCTERS           3

/* 
 * Typedef 
 */

/* 
 * Local Variable
 */



/* 
 * Global Variable
 */
extern U16 gIndexIconsImageList[];

#if defined(__MMI_APHORISM__)
/* under construction !*/
#endif 

/* 
 * Global Function
 */




/*****************************************************************************
 * FUNCTION
 *  ExtraInit
 * DESCRIPTION
 *  Initialize each applications in Extra.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExtraInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* calucartor */

#if (defined(__MMI_STOPWATCH__) && !defined(__COSMOS_MMI_PACKAGE__))
        InitStopwatchApp();
#endif 


#if (defined(__MMI_ZAKAT_CALCULATOR__) && !defined(__COSMOS_MMI_PACKAGE__))
    mmi_zakat_init();
#endif
}

/*****************************************************************************
* FUNCTION
*  ExtraDeInit
* DESCRIPTION
*   Deinitialize each application of Extra
* PARAMETERS
*  None.
* RETURNS
*  None.
* GLOBALS AFFECTED
*  None
*****************************************************************************/
/*
 * void ExtraDeInit(void)
 * {  
 * #if defined(__MMI_CALENDAR__)
 * ClndrDeInit();
 * #endif
 * 
 * #if defined (__MMI_CALCULATOR__)
 * //CalcDeInit();
 * #endif
 * 
 * // currency converter (extended version) 
 * #if defined (__MMI_CURRENCY_CONVERTER__)
 * CconvDeInit();
 * #elif defined (__MMI_EXTENDED_CURRENCY_CONVERTER__)
 * //mmi_cconv_deinit();
 * #endif
 * 
 * #if defined (__MMI_UNIT_CONVERTER__) || defined(__MMI_EXTENDED_UNIT_CONVERTER__)
 * //UconvDeInit();
 * #endif
 * 
 * #if defined(__MMI_BMI__)
 * BmiDeInit();
 * #endif
 * 
 * #if defined(__MMI_MENSTRUAL__)
 * MensDeInit();
 * #endif
 * 
 * #if defined(__MMI_CALORIE__)
 * CaleDeInit();
 * #endif   
 * }
 */

#if defined(__MMI_APHORISM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_APHORISM__) */ 

#endif /* _MMI_EXTRA_C */ // #ifndef _MMI_EXTRA_C
