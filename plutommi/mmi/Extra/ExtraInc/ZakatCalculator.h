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
 *  ZakatCalculator.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines local enum, constant and prototypes for Zakat Calculator.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
**************************************************************/

#ifndef _MMI_ZAKAT_CALCULATOR_H
#define _MMI_ZAKAT_CALCULATOR_H

#include "MMI_features.h"

#ifdef __MMI_ZAKAT_CALCULATOR__

/* 
 * Define
 */

#define MMI_ZAKAT_COMMON_PERCENTAGE                             (0.025)
#define MMI_ZAKAT_BURIED_TREASURES_PERCENTAGE                   (0.15)
#define MMI_ZAKAT_BY_RAIN_WATER_PERCENTAGE                      (0.1)
#define MMI_ZAKAT_BY_IRRIGATION_PERCENTAGE                      (0.05)
#define MMI_ZAKAT_BY_BOTH_PERCENTAGE                            (0.075)
#define MMI_ZAKAT_GOLD_NISAB_GMS                                (85)
#define MMI_ZAKAT_SILVER_NISAB_GMS                              (595)
#define MMI_ZAKAT_CAMELS_NISAB                                  (5)
#define MMI_ZAKAT_COWS_NISAB                                    (30)
#define MMI_ZAKAT_COWS_NISAB_STEP                               (40)
#define MMI_ZAKAT_SHEEP_NISAB                                   (40)
#define MMI_ZAKAT_PAYABLE_MAX_SENTENCE_LENGTH                   (50)
#define MMI_ZAKAT_DESCRIPTION_MAX_SENTENCE_LENGTH               (100)
#define MMI_ZAKAT_DETAIL_MAX_SENTENCE_LENGTH                    (1024)/**/
#define MMI_ZAKAT_MAX_NUMBER_LENGTH                             (12)
#define MMI_ZAKAT_MAX_CALCULATE_RESULT_LENGTH                   (MMI_ZAKAT_MAX_NUMBER_LENGTH * 10)
#define MMI_ZAKAT_DATA_RECORD_TOTAL                             (27)
#define MMI_ZAKAT_INPUT_OPTIONS_COUNT                           (3)
#define MMI_ZAKAT_COMMON_INPUT_INLINE_ITEM_COUNT                (4)
#define MMI_ZAKAT_GOLD_SILVER_INPUT_INLINE_ITEM_COUNT           (8)
#define MMI_ZAKAT_24K_GOLD_SILVER_INPUT_INLINE_ITEM_COUNT       (6)
#define MMI_ZAKAT_NISAB_INLINE_ITEM_COUNT                       (4)
#define MMI_ZAKAT_SILVER_PRICE_INLINE_ITEM_COUNT                (2)
#define MMI_ZAKAT_MAIN_OPTIONS_ITEMS_COUNT                      (2)
#define MMI_ZAKAT_CALCULATION_OPTIONS_ITEMS_COUNT               (3)
#define MMI_ZAKAT_ASSETS_OPTIONS_ITEMS_COUNT                    (10)
#define MMI_ZAKAT_CATTLE_OPTIONS_ITEMS_COUNT                    (3)
#define MMI_ZAKAT_AGRICULTURE_OPTIONS_ITEMS_COUNT               (3)
#define MMI_ZAKAT_BULLION_CASH_OPTIONS_ITEMS_COUNT              (3)
#define MMI_ZAKAT_GOLD_OPTIONS_ITEMS_COUNT                      (4)
#define MMI_ZAKAT_DEDUCTIONS_OPTIONS_ITEMS_COUNT                (3)
#define MMI_ZAKAT_SETTINGS_OPTIONS_ITEMS_COUNT                  (2)
#define MMI_ZAKAT_MAX_DOUBLE                                    (999999999999.0)
#define MMI_ZAKAT_MIN_DOUBLE                                    (0.0000000001)
#define MMI_ZAKAT_2_YEAR_OLD_CAMEL_VALUE                        (40)
#define MMI_ZAKAT_3_YEAR_OLD_CAMEL_VALUE                        (50)
#define MMI_ZAKAT_1_YEAR_OLD_COW_VALUE                          (30)
#define MMI_ZAKAT_2_YEAR_OLD_COW_VALUE                          (40)
#define MMI_ZAKAT_DOUBLE_ADJUST                                 (0.0000000000005)

#define MMI_ZAKAT_VALID_INPUT                                   (1)
#define MMI_ZAKAT_INVALID_DOUBLE                                (-1)
#define MMI_ZAKAT_TOO_LARGE_RESULT                              (-2)
#define MMI_ZAKAT_TOO_SMALL_RESULT                              (-3)
#define MMI_ZAKAT_NO_INPUT                                      (-4)


/* 
 * Typedef
 */

typedef enum
{
    MMI_ZAKAT_CATTLE = 0,
    MMI_ZAKAT_CAMELS = MMI_ZAKAT_CATTLE,
    MMI_ZAKAT_COWS,
    MMI_ZAKAT_SHEEP,
    MMI_ZAKAT_AGRICULTURE,
    MMI_ZAKAT_BY_RAIN_WATER = MMI_ZAKAT_AGRICULTURE,
    MMI_ZAKAT_BY_IRRIGATION,
    MMI_ZAKAT_BY_BOTH,
    MMI_ZAKAT_BULLION_CASH,
    MMI_ZAKAT_GOLD = MMI_ZAKAT_BULLION_CASH,
    MMI_ZAKAT_24_CARAT_GMS = MMI_ZAKAT_BULLION_CASH,
    MMI_ZAKAT_22_CARAT_GMS,
    MMI_ZAKAT_22_CARAT_PRICE,
    MMI_ZAKAT_18_CARAT_GMS,
    MMI_ZAKAT_18_CARAT_PRICE,
    MMI_ZAKAT_OTHER_GOLD_GMS,
    MMI_ZAKAT_OTHER_GOLD_PRICE,
    MMI_ZAKAT_SILVER_GMS,
    MMI_ZAKAT_CASH,
    MMI_ZAKAT_BURIED_TREASURES,
    MMI_ZAKAT_MINERALS,
    MMI_ZAKAT_REVENUES,
    MMI_ZAKAT_COMMERCIAL_COMMODITIES,
    MMI_ZAKAT_BUSINESS,
    MMI_ZAKAT_DEBTS,
    MMI_ZAKAT_OTHERS,
    MMI_ZAKAT_DEDUCTIONS_PERSONAL_DEBTS,
    MMI_ZAKAT_DEDUCTIONS_BUSINESS,
    MMI_ZAKAT_DEDUCTIONS_OTHERS,
    MMI_ZAKAT_NISAB,
    MMI_ZAKAT_24_CARAT_PRICE = MMI_ZAKAT_NISAB,
    MMI_ZAKAT_SILVER_PRICE,
    MMI_ZAKAT_DATA_RECORD_COUNT
} mmi_zakat_data_record_enum;

typedef enum
{
    MMI_ZAKAT_COMMON_INPUT_CAP = 0,
    MMI_ZAKAT_COMMON_INPUT_INFO,
    MMI_ZAKAT_COMMON_DISP_CAP,
    MMI_ZAKAT_COMMON_DISP_INFO,
    MMI_ZAKAT_COMMON_COUNT
} mmi_zakat_common_inline_enum;

typedef enum
{
    MMI_ZAKAT_24K_GOLD_SILVER_INPUT_CAP = 0,
    MMI_ZAKAT_24K_GOLD_SILVER_INPUT_INFO,
    MMI_ZAKAT_24K_GOLD_SILVER_AMOUNT_CAP,
    MMI_ZAKAT_24K_GOLD_SILVER_AMOUNT_INFO,
    MMI_ZAKAT_24K_GOLD_SILVER_PAYABLE_CAP,
    MMI_ZAKAT_24K_GOLD_SILVER_PAYABLE_INFO,
    MMI_ZAKAT_24K_GOLD_SILVER_COUNT
} mmi_zakat_24K_gold_silver_inline_enum;

typedef enum
{
    MMI_ZAKAT_GOLD_GMS_CAP = 0,
    MMI_ZAKAT_GOLD_GMS_INFO,
    MMI_ZAKAT_GOLD_PRICE_CAP,
    MMI_ZAKAT_GOLD_PRICE_INFO,
    MMI_ZAKAT_GOLD_AMOUNT_CAP,
    MMI_ZAKAT_GOLD_AMOUNT_INFO,
    MMI_ZAKAT_GOLD_PAYABLE_CAP,
    MMI_ZAKAT_GOLD_PAYABLE_INFO,
    MMI_ZAKAT_GOLD_SILVER_COUNT
} mmi_zakat_gold_silver_inline_enum;

typedef enum
{
    MMI_ZAKAT_NISAB_GOLD_PRICE_CAP,
    MMI_ZAKAT_NISAB_GOLD_PRICE_INFO,
    MMI_ZAKAT_NISAB_SILVER_PRICE_CAP,
    MMI_ZAKAT_NISAB_SILVER_PRICE_INFO,
    MMI_ZAKAT_NISAB_COUNT
} mmi_zakat_nisab_inline_enum;

typedef enum
{
    MMI_ZAKAT_INITIALIZE,
    MMI_ZAKAT_CALCULATE,
    MMI_ZAKAT_RESET,
    MMI_ZAKAT_OPERATION_COUNT
} mmi_zakat_operation_enum;

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

extern void mmi_zakat_init(void);

#endif /* __MMI_ZAKAT_CALCULATOR__ */

#endif /* _MMI_ZAKAT_CALCULATOR_H */

