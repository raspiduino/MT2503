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
/****************************************************************************
 *
 * Filename:
 * ---------
 *  vector_font_lang_memory_card_config.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  font config  file
 *
 * Author:
 * -------
 * 
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
#ifndef __VECTOR_FONT_LANG_MEMORY_CARD_CONFIG__
#define __VECTOR_FONT_LANG_MEMORY_CARD_CONFIG__

#include "MMI_features_lang_memory_card_config.h"

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__

/*memory card support language list dependance*/
#if defined(__MMI_LANG_SM_CHINESE_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_SM_CHINESE__)
    #undef __MMI_LANG_SM_CHINESE_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_TR_CHINESE_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_TR_CHINESE__)
    #undef __MMI_LANG_TR_CHINESE_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_AFRIKAANS_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_AFRIKAANS__)
    #undef __MMI_LANG_AFRIKAANS_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_ALBANIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_ALBANIAN__)
    #undef __MMI_LANG_ALBANIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_ARABIC_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_ARABIC__)
    #undef __MMI_LANG_ARABIC_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_ARMENIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_ARMENIAN__)
    #undef __MMI_LANG_ARMENIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_ASSAMESE_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_ASSAMESE__)
    #undef __MMI_LANG_ASSAMESE_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_AZERBAIJANI_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_AZERBAIJANI__)
    #undef __MMI_LANG_AZERBAIJANI_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_BASQUE_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_BASQUE__)
    #undef __MMI_LANG_BASQUE_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_BENGALI_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_BENGALI__)
    #undef __MMI_LANG_BENGALI_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_BULGARIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_BULGARIAN__)
    #undef __MMI_LANG_BULGARIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_CATALAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_CATALAN__)
    #undef __MMI_LANG_CATALAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_CA_FRENCH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_CA_FRENCH__)
    #undef __MMI_LANG_CA_FRENCH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_CROATIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_CROATIAN__)
    #undef __MMI_LANG_CROATIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_CZECH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_CZECH__)
    #undef __MMI_LANG_CZECH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_DANISH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_DANISH__)
    #undef __MMI_LANG_DANISH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_DUTCH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_DUTCH__)
    #undef __MMI_LANG_DUTCH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_ESTONIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_ESTONIAN__)
    #undef __MMI_LANG_ESTONIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_FILIPINO_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_FILIPINO__)
    #undef __MMI_LANG_FILIPINO_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_FINNISH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_FINNISH__)
    #undef __MMI_LANG_FINNISH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_FRENCH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_FRENCH__)
    #undef __MMI_LANG_FRENCH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_GALICIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_GALICIAN__)
    #undef __MMI_LANG_GALICIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_GEORGIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_GEORGIAN__)
    #undef __MMI_LANG_GEORGIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_GERMAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_GERMAN__)
    #undef __MMI_LANG_GERMAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_GREEK_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_GREEK__)
    #undef __MMI_LANG_GREEK_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_GUJARATI_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_GUJARATI__)
    #undef __MMI_LANG_GUJARATI_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_HAUSA_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_HAUSA__)
    #undef __MMI_LANG_HAUSA_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_HEBREW_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_HEBREW__)
    #undef __MMI_LANG_HEBREW_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_HINDI_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_HINDI__)
    #undef __MMI_LANG_HINDI_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_HK_CHINESE_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_HK_CHINESE__)
    #undef __MMI_LANG_HK_CHINESE_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_HUNGARIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_HUNGARIAN__)
    #undef __MMI_LANG_HUNGARIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_ICELANDIC_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_ICELANDIC__)
    #undef __MMI_LANG_ICELANDIC_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_IGBO_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_IGBO__)
    #undef __MMI_LANG_IGBO_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_INDONESIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_INDONESIAN__)
    #undef __MMI_LANG_INDONESIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_IRISH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_IRISH__)
    #undef __MMI_LANG_IRISH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_ITALIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_ITALIAN__)
    #undef __MMI_LANG_ITALIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_KANNADA_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_KANNADA__)
    #undef __MMI_LANG_KANNADA_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_KAZAKH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_KAZAKH__)
    #undef __MMI_LANG_KAZAKH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_KHMER_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_KHMER__)
    #undef __MMI_LANG_KHMER_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_LAO_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_LAO__)
    #undef __MMI_LANG_LAO_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_LATVIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_LATVIAN__)
    #undef __MMI_LANG_LATVIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_LITHUANIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_LITHUANIAN__)
    #undef __MMI_LANG_LITHUANIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_MACEDONIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_MACEDONIAN__)
    #undef __MMI_LANG_MACEDONIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_MALAYALAM_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_MALAYALAM__)
    #undef __MMI_LANG_MALAYALAM_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_MALAY_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_MALAY__)
    #undef __MMI_LANG_MALAY_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_MARATHI_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_MARATHI__)
    #undef __MMI_LANG_MARATHI_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_MOLDOVAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_MOLDOVAN__)
    #undef __MMI_LANG_MOLDOVAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_MYANMAR_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_MYANMAR__)
    #undef __MMI_LANG_MYANMAR_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_NORWEGIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_NORWEGIAN__)
    #undef __MMI_LANG_NORWEGIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_ORIYA_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_ORIYA__)
    #undef __MMI_LANG_ORIYA_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_PERSIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_PERSIAN__)
    #undef __MMI_LANG_PERSIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_POLISH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_POLISH__)
    #undef __MMI_LANG_POLISH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_PORTUGUESE_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_PORTUGUESE__)
    #undef __MMI_LANG_PORTUGUESE_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_PUNJABI_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_PUNJABI__)
    #undef __MMI_LANG_PUNJABI_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_ROMANIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_ROMANIAN__)
    #undef __MMI_LANG_ROMANIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_RUSSIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_RUSSIAN__)
    #undef __MMI_LANG_RUSSIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_SA_PORTUGUESE_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_SA_PORTUGUESE__)
    #undef __MMI_LANG_SA_PORTUGUESE_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_SA_SPANISH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_SA_SPANISH__)
    #undef __MMI_LANG_SA_SPANISH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_SERBIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_SERBIAN__)
    #undef __MMI_LANG_SERBIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_SESOTHO_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_SESOTHO__)
    #undef __MMI_LANG_SESOTHO_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_SLOVAK_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_SLOVAK__)
    #undef __MMI_LANG_SLOVAK_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_SLOVENIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_SLOVENIAN__)
    #undef __MMI_LANG_SLOVENIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_SPANISH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_SPANISH__)
    #undef __MMI_LANG_SPANISH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_SWAHILI_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_SWAHILI__)
    #undef __MMI_LANG_SWAHILI_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_SWEDISH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_SWEDISH__)
    #undef __MMI_LANG_SWEDISH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_TAGALOG_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_TAGALOG__)
    #undef __MMI_LANG_TAGALOG_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_TAMIL_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_TAMIL__)
    #undef __MMI_LANG_TAMIL_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_TELUGU_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_TELUGU__)
    #undef __MMI_LANG_TELUGU_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_THAI_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_THAI__)
    #undef __MMI_LANG_THAI_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_TURKISH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_TURKISH__)
    #undef __MMI_LANG_TURKISH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_UKRAINIAN_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_UKRAINIAN__)
    #undef __MMI_LANG_UKRAINIAN_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_UK_ENGLISH_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_UK_ENGLISH__)
    #undef __MMI_LANG_UK_ENGLISH_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_URDU_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_URDU__)
    #undef __MMI_LANG_URDU_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_VIETNAMESE_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_VIETNAMESE__)
    #undef __MMI_LANG_VIETNAMESE_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_XHOSA_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_XHOSA__)
    #undef __MMI_LANG_XHOSA_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_YORUBA_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_YORUBA__)
    #undef __MMI_LANG_YORUBA_MEMORY_CARD_SUPPORT__
#endif
#if defined(__MMI_LANG_ZULU_MEMORY_CARD_SUPPORT__) && !defined(__MMI_LANG_ZULU__)
    #undef __MMI_LANG_ZULU_MEMORY_CARD_SUPPORT__
#endif

#endif /*__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__*/

#endif /*__VECTOR_FONT_LANG_MEMORY_CARD_CONFIG__*/

