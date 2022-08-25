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
 *    CstarEngine.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 * Adaptation layer for IME over CSTAR CORE for IME of Low Cost MMI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_CSTAR__

#include "GlobalConstants.h"
#include "gui_data_types.h"
#include "IMERes.h"

#include "ImeGprot.h"
#include "Word_engine.h"
#include "Imc_symbol.h"
#include "Imc_config.h"
#include "ImmProt.h"
#include "App_str.h"
#include "kmxime.h"
#include "wgui_inputs.h"

/*****************************************************************************
 * Global variables
 *****************************************************************************/

/*****************************************************************************
 * Define
*****************************************************************************/

/*****************************************************************************
 * Typedefs
 *****************************************************************************/

typedef struct
{
    S32 input_mode;
    const void **ldb_ptr;
    U32 required_keys;
    U32 symbol_keys;
    mmi_ime_get_spellings_funcptr get_spell_func;
    mmi_ime_get_associates_funcptr get_assoc_func;
    mmi_ime_get_candidates_funcptr get_cand_func;
} mmi_ime_cstar_mode_info_struct, *mmi_ime_cstar_mode_info_struct_p;

typedef struct
{
    KMX_IME_ENGINE cstar_engine;
    KMX_IME_ENGINE_INIT init_info;
    MMI_BOOL is_inited;
    mmi_ime_cstar_mode_info_struct_p curr_mode_info;
    S32 input_mode;
    U8 get_context;
    U8 case_type;
} mmi_ime_cstar_word_engine_struct, *mmi_ime_cstar_word_engine_struct_p;

/*****************************************************************************
 * Local functions
 *****************************************************************************/

/* Utility functions */

static const mmi_ime_cstar_mode_info_struct *mmi_ime_cstar_query_mode_info(S32 input_mode);
static void mmi_ime_cstar_change_candidates_case(mmi_ime_query_result_struct_p result_str);
static UI_character_type mmi_ime_cstar_char_to_upper(UI_character_type char_code);
static UI_character_type mmi_ime_cstar_char_to_lower(UI_character_type char_code);

/* Query functions */

#if defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__)
static void mmi_ime_cstar_get_associates_chinese( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* #if defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__) */

static void mmi_ime_cstar_get_associates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
static void mmi_ime_cstar_get_candidates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );

#if defined (__MMI_CSTAR_STROKE_INPUT__)
static void mmi_ime_cstar_get_spellings_stroke( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
static void mmi_ime_cstar_get_candidates_stroke( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* __MMI_CSTAR_STROKE_INPUT__*/

/* Simplified Chinese functions */
#if defined(__MMI_CSTAR_SM_CHINESE__)

#if defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)
static void mmi_ime_cstar_get_spellings_pinyin_multitap(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* #if defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__) */
#if defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)
static void mmi_ime_cstar_get_spellings_pinyin_smart(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* #if defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__) */
static void mmi_ime_cstar_get_candidates_pinyin(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );

#endif /* #if defined(__MMI_CSTAR_SM_CHINESE__) */

/* Traditional Chinese functions */
#if defined(__MMI_CSTAR_TR_CHINESE__)

#if defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)
static void mmi_ime_cstar_get_spellings_zhuyin_multitap(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
static void mmi_ime_cstar_get_candidates_zhuyin(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* #if defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__) */

#endif /* #if defined(__MMI_CSTAR_TR_CHINESE__) */

//TODO Remove code for languages which are not supported in LCMMI
/*****************************************************************************
 * Local variables
 *****************************************************************************/

#if defined __MMI_CSTAR_STROKE_INPUT__

static const mmi_imc_symb_stroke_enum g_cstar_keys_stroke[MMI_IMC_SYMB_KEY_MAX - MMI_IMC_SYMB_KEY_BASE] = 
{
    0,                              /* MMI_IMC_SYMB_KEY_0 */
    MMI_IMC_SYMB_STROKE_OVER,       /* MMI_IMC_SYMB_KEY_1 */
    MMI_IMC_SYMB_STROKE_DOWN,       /* MMI_IMC_SYMB_KEY_2 */
    MMI_IMC_SYMB_STROKE_LEFT,       /* MMI_IMC_SYMB_KEY_3 */
    MMI_IMC_SYMB_STROKE_DOT,        /* MMI_IMC_SYMB_KEY_4 */
    MMI_IMC_SYMB_STROKE_OVER_DOWN,  /* MMI_IMC_SYMB_KEY_5 */
    MMI_IMC_SYMB_STROKE_WILDCARD,   /* MMI_IMC_SYMB_KEY_6 */
    0,                              /* MMI_IMC_SYMB_KEY_7 */
    0,                              /* MMI_IMC_SYMB_KEY_8 */
    0,                              /* MMI_IMC_SYMB_KEY_9 */
    0,                              /* MMI_IMC_SYMB_KEY_STAR */
    0                               /* MMI_IMC_SYMB_KEY_POUND */
};

static const char g_cstar_codes_stroke[MMI_IMC_SYMB_STROKE_MAX - MMI_IMC_SYMB_STROKE_BASE] = 
{
    KMX_STROKE_WILDCARD,    /* MMI_IMC_SYMB_STROKE_WILDCARD, */
    KMX_STROKE_SHU,         /* MMI_IMC_SYMB_STROKE_DOWN, */
    KMX_STROKE_DIAN,        /* MMI_IMC_SYMB_STROKE_DOT, */
    0,                      /* MMI_IMC_SYMB_STROKE_CURVED_HOOK, */
    KMX_STROKE_HENG,        /* MMI_IMC_SYMB_STROKE_OVER, */
    KMX_STROKE_ZHE,         /* MMI_IMC_SYMB_STROKE_OVER_DOWN, */
    0,                      /* MMI_IMC_SYMB_STROKE_DOWN_OVER, */
    KMX_STROKE_PIE,         /* MMI_IMC_SYMB_STROKE_LEFT, */
    0,                      /* MMI_IMC_SYMB_STROKE_OVER_DOWN_OVER, */
    0,                      /* MMI_IMC_SYMB_STROKE_MORE, */
    0,                      /* MMI_IMC_SYMB_STROKE_TURN, */
    0,                      /* MMI_IMC_SYMB_STROKE_DOT_OR_LEFT, */
};
#endif /*__MMI_CSTAR_STROKE_INPUT__*/

/* All input mode informations */
static const mmi_ime_cstar_mode_info_struct   g_mode_infos[] =
{
#if defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)
    {   
        INPUT_MODE_TR_MULTITAP_BOPOMO,
        &kmx_ldb_zhuyin_cizu,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        mmi_ime_cstar_get_spellings_zhuyin_multitap,
        mmi_ime_cstar_get_associates_chinese,
        mmi_ime_cstar_get_candidates_zhuyin
    },
#endif /* #if defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__) */

#if defined(__MMI_CSTAR_TR_CHINESE__) &&  defined (__MMI_CSTAR_STROKE_INPUT__)
    {
        INPUT_MODE_TR_STROKE, 
        &kmx_ldb_stroke_big5,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0), 
        mmi_ime_cstar_get_spellings_stroke,
        mmi_ime_cstar_get_associates_chinese,
        mmi_ime_cstar_get_candidates_stroke
    },
    
#endif /* #if defined(__MMI_CSTAR_TR_CHINESE__) */

#if defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)
    {
        INPUT_MODE_MULTITAP_PINYIN,
        &kmx_ldb_pinyin_danzi,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_1),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_1) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_cstar_get_spellings_pinyin_multitap,
        mmi_ime_cstar_get_associates_chinese,
        mmi_ime_cstar_get_candidates_pinyin
    },
#endif /* #if defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__) */

#if defined(__MMI_CSTAR_SM_CHINESE__) &&  defined (__MMI_CSTAR_STROKE_INPUT__)
    {
        INPUT_MODE_SM_STROKE,
        &kmx_ldb_stroke_gb2312,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0), 
        mmi_ime_cstar_get_spellings_stroke,
        mmi_ime_cstar_get_associates_chinese,
        mmi_ime_cstar_get_candidates_stroke 
    },
   
#endif /* #if defined(__MMI_CSTAR_TR_CHINESE__) */

#if defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)

    {
        INPUT_MODE_SM_PINYIN,
        &kmx_ldb_pinyin_danzi,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_1),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0) & (~MMI_IME_REQUIRED_KEY_1), /* 1 is magic key */
        mmi_ime_cstar_get_spellings_pinyin_smart,
        mmi_ime_cstar_get_associates_chinese,
        mmi_ime_cstar_get_candidates_pinyin
    },
#endif /* #if defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__) */



 #if defined(__MMI_CSTAR_ENGLISH__)
    {
     INPUT_MODE_SMART_UPPERCASE_ABC,
     &kmx_ldb_english,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
    {
     INPUT_MODE_SMART_LOWERCASE_ABC,
     &kmx_ldb_english,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
 #endif /* defined(__MMI_CSTAR_ENGLISH__) */ 

 #if defined(__MMI_CSTAR_HINGLISH__)
    {
     INPUT_MODE_SMART_UPPERCASE_HINGLISH,
     &kmx_ldb_hinglish,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},

    {
     INPUT_MODE_SMART_LOWERCASE_HINGLISH,
     &kmx_ldb_hinglish,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},

 #endif /* defined(__MMI_CSTAR_HINGLISH__) */ 

 #if defined(__MMI_CSTAR_HINDI__)
    {
     INPUT_MODE_SMART_HINDI,
     &kmx_ldb_hindi,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
#endif /* defined(__MMI_CSTAR_HINDI__) */

#if defined(__MMI_CSTAR_FRENCH__)
    {
     INPUT_MODE_SMART_UPPERCASE_FRENCH,
     &kmx_ldb_french,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
    {
     INPUT_MODE_SMART_LOWERCASE_FRENCH,
     &kmx_ldb_french,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
#endif /* defined(__MMI_CSTAR_FRENCH__) */

#if defined(__MMI_CSTAR_ITALIAN__)
    {
     INPUT_MODE_SMART_UPPERCASE_ITALIAN,
     &kmx_ldb_italian,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
    {
     INPUT_MODE_SMART_LOWERCASE_FRENCH,
     &kmx_ldb_french,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
 #endif /* defined(__MMI_CSTAR_ITALIAN__) */ 

 #if defined(__MMI_CSTAR_UKRAINIAN__)
    {
     INPUT_MODE_SMART_UPPERCASE_UKRAINIAN,
     &kmx_ldb_ukrainian,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
    {
     INPUT_MODE_SMART_LOWERCASE_FRENCH,
     &kmx_ldb_ukrainian,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
 #endif /* defined(__MMI_CSTAR_UKRAINIAN__) */ 

 #if defined(__MMI_CSTAR_GERMAN__)
    {
     INPUT_MODE_SMART_UPPERCASE_GERMAN,
     &kmx_ldb_german,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
    {
     INPUT_MODE_SMART_LOWERCASE_GERMAN,
     &kmx_ldb_german,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
#endif /* defined(__MMI_CSTAR_GERMAN__) */

 #if defined(__MMI_CSTAR_POLISH__)
    {
     INPUT_MODE_SMART_UPPERCASE_POLISH,
     &kmx_ldb_polish,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
    {
     INPUT_MODE_SMART_LOWERCASE_POLISH,
     &kmx_ldb_polish,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
 #endif /* defined(__MMI_CSTAR_POLISH__) */ 

 #if defined(__MMI_CSTAR_VIETNAMESE__)
    {
     INPUT_MODE_SMART_UPPERCASE_VIETNAMESE,
     &kmx_ldb_vietnamese,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
    {
     INPUT_MODE_SMART_LOWERCASE_VIETNAMESE,
     &kmx_ldb_vietnamese,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
 #endif /* defined(__MMI_CSTAR_VIETNAMESE__) */ 

 #if defined(__MMI_CSTAR_INDONESIAN__)
    {
     INPUT_MODE_SMART_UPPERCASE_INDONESIAN,
     &kmx_ldb_indonesian,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
    {
     INPUT_MODE_SMART_LOWERCASE_INDONESIAN,
     &kmx_ldb_indonesian,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},

 #endif /* defined(__MMI_CSTAR_INDONESIAN__) */

 #if defined(__MMI_CSTAR_TURKISH__)
    {
     INPUT_MODE_SMART_UPPERCASE_TURKISH,
     &kmx_ldb_turkish,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},
    {
     INPUT_MODE_SMART_LOWERCASE_TURKISH,
     &kmx_ldb_turkish,
     MMI_IME_REQUIRED_ALL_KEYS,
     MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
     NULL,
     mmi_ime_cstar_get_associates_alphabetic,
     mmi_ime_cstar_get_candidates_alphabetic},

 #endif /* defined(__MMI_CSTAR_TURKISH__) */ 

#if defined(__MMI_CSTAR_MALAY__)
{
        INPUT_MODE_SMART_UPPERCASE_MALAY,
        &kmx_ldb_malay,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_cstar_get_associates_alphabetic,
        mmi_ime_cstar_get_candidates_alphabetic
    },
    {
        INPUT_MODE_SMART_LOWERCASE_MALAY,
        &kmx_ldb_malay,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_cstar_get_associates_alphabetic,
        mmi_ime_cstar_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_CSTAR_MALAY__) */


#if defined(__MMI_CSTAR_ARABIC__)
{
        INPUT_MODE_SMART_ARABIC,
        &kmx_ldb_arabic,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_cstar_get_associates_alphabetic,
        mmi_ime_cstar_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_CSTAR_ARABIC__) */

#if defined(__MMI_CSTAR_PERSIAN__)
{
        INPUT_MODE_SMART_PERSIAN,
        &kmx_ldb_persian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_cstar_get_associates_alphabetic,
        mmi_ime_cstar_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_CSTAR_PERSIAN__) */


#if defined(__MMI_CSTAR_RUSSIAN__)
{
        INPUT_MODE_SMART_UPPERCASE_RUSSIAN,
        &kmx_ldb_russian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_cstar_get_associates_alphabetic,
        mmi_ime_cstar_get_candidates_alphabetic
    },
    {
        INPUT_MODE_SMART_LOWERCASE_RUSSIAN,
        &kmx_ldb_russian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_cstar_get_associates_alphabetic,
        mmi_ime_cstar_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_CSTAR_RUSSIAN__) */

#if defined(__MMI_CSTAR_CZECH__)
    {
        INPUT_MODE_SMART_UPPERCASE_CZECH,
        &kmx_ldb_czech,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_cstar_get_associates_alphabetic,
        mmi_ime_cstar_get_candidates_alphabetic
    },
    {
        INPUT_MODE_SMART_LOWERCASE_CZECH,
        &kmx_ldb_czech,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        mmi_ime_cstar_get_associates_alphabetic,
        mmi_ime_cstar_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_CSTAR_CZECH__) */

    {
        INPUT_MODE_MAX_NUM,
        0,
        0,
        0,
        NULL,
        NULL,
        NULL
    }
};

/*****************************************************************************
 * Local variables
 *****************************************************************************/

// The Cstar engine singleton
static mmi_ime_cstar_word_engine_struct    g_engine;
static const UI_character_type g_chinese_symbol_string[] = 
{
    0xff0c,
    0x3002,
    0x3001,
    0xff1a,
    0xff1b,
    0xff1f,
    0xff01,
    0x300a,
    0x300b,
    0x300e,
    0x300f,
    0x201c,
    0x201d,
    0xff08,
    0xff09,
    0x300c,
    0x300d,
    0x2018,
    0x2019,
    0xff0e,
    0xff1c,
    0xff1e,
    0xff5e,
    0xff3b,
    0xff3d,
    0x0020,
    0x0000
};

/*****************************************************************************
 *          Macros
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_towupper
 * DESCRIPTION
 *  Convert character to uppercase.
 * PARAMETERS
 *  wc      [IN]  Character to convert.
 * RETURNS
 *  Each of these routines converts a copy of wc, if possible, and returns the 
 *  result.
 *****************************************************************************/
U16 mmi_ime_word_toupper(U16 wc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Latin Basic        0x0000 ~ 0x007F */
    /* Latin-1            0x0080 ~ 0x00FF */
    /* Latin extend-A     0x0100 ~ 0x017F */
    /* Latin extend-B     0x0180 ~ 0x024F */
    /* Greek              0x0370 ~ 0x03FF */
    /* Cyrillic           0x0400 ~ 0x04FF */
    
    if ((wc >= 0x0061 && wc <= 0x007A) || /* Latin basic */
        (wc >= 0x00E0 && wc <= 0x00F6) || (wc >= 0x00F8 && wc <= 0x00FE) || /* Latin-1 */
        (wc >= 0x0430 && wc <= 0x044F) || /* Cyrillic */
        (wc >= 0x03B1 && wc <= 0x03C1) || (wc >= 0x03C3 && wc <= 0x03CA)) /* Greek */
    {
        return (wc - 0x0020);
    }
    else if (wc == 0x0103 || /* Latin extend-A */
             wc == 0x01A1 || wc == 0x01B0 || wc == 0x0188 || wc == 0x018C ||  /* Latin extend-B */
             wc == 0x0192 || wc == 0x01AC || wc == 0x01B9 || wc == 0x01F3) /* Latin extend-B */
    {
        return (wc - 0x0001);
    }
    else if (wc >= 0x0450 && wc <= 0x045f) /* Cyrillic */
    {
        return (wc - 0x50);
    }
    else if (wc == 0x0491) /* Cyrillic */
    {
        return 0x0490;
    }
    else if (wc >= 0x0100 && wc <= 0x0137 ||wc >= 0x014A && wc <= 0x0177 || /* Latin extend-A */
             wc >= 0x0182 && wc <= 0x0185 ||wc >= 0x0198 && wc <= 0x01A5 || /* Latin extend-B */
             wc >= 0x01DE && wc <= 0x01EF ||wc >= 0x01F8 && wc <= 0x01FF || /* Latin extend-B */
             wc >= 0x0222 && wc <= 0x0233) /* Latin extend-B */ 
    {
        if ((wc & 1) == 1) /* odd is small case */
            return wc - 1;
        else
            return wc;
    }
    else if (wc >= 0x0139 && wc <= 0x0148 || /* Latin extend-A */
             wc >= 0x0179 && wc <= 0x017E || wc >= 0x01B3 && wc <= 0x01B6 ||  /* Latin extend-B */
             wc >= 0x01CD && wc <= 0x01DC) /* Latin extend-B*/
    {
        if ((wc & 1) == 0) /* even is small case */
            return wc - 1;
        else
            return wc;
    }
    else
    {
        return wc;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_tolower
 * DESCRIPTION
 *  Convert character to lowercase.
 * PARAMETERS
 *  wc      [IN]  Character to convert.
 * RETURNS
 *  Each of these routines converts a copy of wc, if possible, and returns the 
 *  result.
 ****************************************************************************/
U16 mmi_ime_word_tolower(U16 wc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Latin Basic        0x0000 ~ 0x007F */
    /* Latin-1            0x0080 ~ 0x00FF */
    /* Latin extend-A     0x0100 ~ 0x017F */
    /* Latin extend-B     0x0180 ~ 0x024F */
    /* Greek              0x0370 ~ 0x03FF */
    /* Cyrillic           0x0400 ~ 0x04FF */
    
    if ((wc >= 0x0041 && wc <= 0x005A) || /* Latin basic */
        (wc >= 0x00C0 && wc <= 0x00D6) || (wc >= 0x00D8 && wc <= 0x00DE) || /* Latin-1 */
        (wc >= 0x0410 && wc <= 0x042F) || /* Cyrillic */
        (wc >= 0x0391 && wc <= 0x03A1) || (wc >= 0x03A3 && wc <= 0x03AA)) /* Greek */
    {
        return (wc + 0x0020);
    }
    else if (wc == 0x0102 || /* Latin extend-A */
             wc == 0x01A0 || wc == 0x01AF || wc == 0x0187 || wc == 0x018B ||  /* Latin extend-B */
             wc == 0x0191 || wc == 0x01AB || wc == 0x01B8 || wc == 0x01F2) /* Latin extend-B */
    {
        return (wc + 0x0001);
    }
    else if (wc >= 0x0400 && wc <= 0x040F) /* Cyrillic */
    {
        return (wc + 0x50);
    }
    else if (wc == 0x0490) /* Cyrillic */
    {
        return 0x0491;
    }
    else if (wc >= 0x0100 && wc <= 0x0137 || wc >= 0x014A && wc <= 0x0177 || /* Latin extend-A */
             wc >= 0x0182 && wc <= 0x0185 || wc >= 0x0198 && wc <= 0x01A5 || /* Latin extend-B */
             wc >= 0x01DE && wc <= 0x01EF || wc >= 0x01F8 && wc <= 0x01FF || /* Latin extend-B */
             wc >= 0x0222 && wc <= 0x0233) /* Latin extend-B */ 
    {
        if ((wc & 0x0001) == 0) /* odd is small case */
            return wc + 1;
        else
            return wc;
    }
    else if (wc >= 0x0139 && wc <= 0x0148 ||  /* Latin extend-A */
             wc >= 0x0179 && wc <= 0x017E ||wc >= 0x01B3 && wc <= 0x01B6 ||  /* Latin extend-B */
             wc >= 0x01CD && wc <= 0x01DC) /* Latin extend-B*/
    {
        if ((wc & 0x0001) == 1) /* even is small case */
            return wc + 1;
        else
            return wc;
    }
    else
    {
        return wc;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_init
 * DESCRIPTION
 * Initialize CSTAR Object
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_init( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset( &g_engine, 0, sizeof(mmi_ime_cstar_word_engine_struct) );
    g_engine.is_inited = MMI_TRUE;
    return g_engine.is_inited;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_deinit
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_deinit( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( MMI_FALSE != g_engine.is_inited )
    {
        memset( &g_engine, 0, sizeof(mmi_ime_cstar_word_engine_struct) );
        g_engine.is_inited = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_leave_current_mode
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void  mmi_ime_word_leave_current_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_engine.curr_mode_info = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_change_mode
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_change_mode(const mmi_ime_mode_details_struct * mode_details_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    S32                             ret_val = 0;
    mmi_ime_cstar_mode_info_struct_p      mode_info_ptr;
	S32 curr_mode = mmi_imm_get_current_input_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( MMI_FALSE == g_engine.is_inited )
        return MMI_FALSE;

    mode_info_ptr = (mmi_ime_cstar_mode_info_struct_p)mmi_ime_cstar_query_mode_info( curr_mode );

    g_engine.curr_mode_info = NULL;
    
    if ( NULL == mode_info_ptr )
        return MMI_FALSE;

    g_engine.init_info.database = *(mode_info_ptr->ldb_ptr);
    g_engine.init_info.flags = 0;

    g_engine.init_info.user_data = NULL;
    g_engine.init_info.user_data_size = 0;

    if (mode_details_ptr->flags & MMI_IME_PHONETIC)
    {
        #if defined (__MMI_CSTAR_TR_CHINESE__)
        if ((curr_mode== INPUT_MODE_TR_MULTITAP_BOPOMO)||(curr_mode== INPUT_MODE_TR_STROKE))
        {
            ret_val = (S32)kmx_zhuyin_initialize(&g_engine.cstar_engine, (const KMX_IME_ENGINE_INIT *)&g_engine.init_info);
        }
        else
	    #endif
		if ((curr_mode== INPUT_MODE_SM_PINYIN)||(curr_mode== INPUT_MODE_MULTITAP_PINYIN)||(curr_mode== INPUT_MODE_SM_STROKE))
        {
            ret_val = (S32)kmx_pinyin_initialize(&g_engine.cstar_engine, (const KMX_IME_ENGINE_INIT *)&g_engine.init_info);
        }
    }
    else if (mode_details_ptr->flags & MMI_IME_STROKE)
    {
        ret_val = (S32)kmx_stroke_initialize(&g_engine.cstar_engine, (const KMX_IME_ENGINE_INIT *)&g_engine.init_info);
    }
    else if (mode_details_ptr->flags & MMI_IME_ALPHABETIC)
    {
        ret_val = (S32)kmx_latin_initialize(&g_engine.cstar_engine, (const KMX_IME_ENGINE_INIT *)&g_engine.init_info);
    }

    if (ret_val == 0)
        return MMI_FALSE;
        g_engine.case_type = MMI_IME_WORD_CASE_DEFAULT;

    g_engine.curr_mode_info = mode_info_ptr; /* Append new input mode */
    g_engine.input_mode = mode_info_ptr->input_mode;
        
    return MMI_TRUE;
}   
 

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_is_valid_key
 * DESCRIPTION
 * PARAMETERS
 *  input_mode    [IN]    Input mode
 * RETURNS
 *  Is valid key for this input mode
 *****************************************************************************/
MMI_BOOL mmi_ime_word_is_valid_key( S32 input_mode, U16 key_code )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_cstar_mode_info_struct_p  mode_info_p;
    U32 required_key;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_info_p = (mmi_ime_cstar_mode_info_struct_p)mmi_ime_cstar_query_mode_info(input_mode);

    if (mode_info_p == NULL)
        return MMI_FALSE;

    required_key = mode_info_p->required_keys;
    
    switch(key_code)
    {
    case KEY_LSK:
    case KEY_RSK:
    case KEY_UP_ARROW:
    case KEY_DOWN_ARROW:
    case KEY_LEFT_ARROW:
    case KEY_RIGHT_ARROW:
        return MMI_TRUE;
    case KEY_0:
    case KEY_1:
    case KEY_2:
    case KEY_3:
    case KEY_4:
    case KEY_5:
    case KEY_6:
    case KEY_7:
    case KEY_8:
    case KEY_9:
        if (required_key & (MMI_IME_REQUIRED_KEY_0 << (key_code - KEY_0)))
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    case KEY_STAR:
        if (required_key & MMI_IME_REQUIRED_KEY_STAR)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    case KEY_POUND:
        if (required_key & MMI_IME_REQUIRED_KEY_POUND)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    default:
        return MMI_FALSE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_get_candidates
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_get_candidates( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result_ptr->result_cnt = 0;
    if (g_engine.curr_mode_info)
    {
        if ( NULL != g_engine.curr_mode_info->get_cand_func )
        {
            g_engine.curr_mode_info->get_cand_func( param_ptr, result_ptr);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_get_associates
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_get_associates( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result_ptr->result_cnt = 0;   
    if (g_engine.curr_mode_info)
    {
        if ( NULL != g_engine.curr_mode_info->get_assoc_func )
        {
            g_engine.curr_mode_info->get_assoc_func( param_ptr, result_ptr );
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_get_spellings
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_get_spellings( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result_ptr->result_cnt = 0;
    if (g_engine.curr_mode_info)
    {
        if ( NULL != g_engine.curr_mode_info->get_spell_func )
        {
            g_engine.curr_mode_info->get_spell_func( param_ptr, result_ptr );
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_symbol_to_code
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
UI_character_type mmi_ime_word_symbol_to_code(U16 symbol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (MMI_IMC_IS_SYMB_TONE(symbol))
    {
        switch (symbol)
        {
            case MMI_IMC_SYMB_TONE_1:
                return 0x02C9;
                
            case MMI_IMC_SYMB_TONE_2:
                return 0x02CA;
            case MMI_IMC_SYMB_TONE_3:
                return 0x02C7;
            case MMI_IMC_SYMB_TONE_4:
                return 0x02CB;
            case MMI_IMC_SYMB_TONE_5:
                return 0x02D9;
            default:
                ASSERT(0);
        }
    }
#if defined(__MMI_CSTAR_STROKE_INPUT__) 
    else if (MMI_IMC_IS_SYMB_STROKE(symbol))
    {
        switch(symbol)
        {
        case MMI_IMC_SYMB_STROKE_WILDCARD:
            return 0xF000;
            break;
            
        case MMI_IMC_SYMB_STROKE_DOWN:
            return 0xF001;
            break;
            
        case MMI_IMC_SYMB_STROKE_DOT:
            return 0xF002;
            break;
            
        case MMI_IMC_SYMB_STROKE_OVER:
            return 0xF004;
            break;
            
        case MMI_IMC_SYMB_STROKE_OVER_DOWN:
            return 0xF005;
            break;
            
        case MMI_IMC_SYMB_STROKE_LEFT:
            return 0xF007;
            break;
            
        default:
            return 0;
            break;
        }
    }
#endif /* defined(__MMI_CSTAR_STROKE_INPUT__) */
#if defined(__MMI_LANG_SM_CHINESE__)
    else if (MMI_IMC_IS_SYMB_PY(symbol))
    {
        return symbol - MMI_IMC_SYMB_PY_BASE + 'a';
    }
#endif /* #if defined(__MMI_LANG_SM_CHINESE__) */
#if defined(__MMI_LANG_TR_CHINESE__)
    else if (MMI_IMC_IS_SYMB_ZY(symbol))
    {
        return symbol - MMI_IMC_SYMB_ZY_BASE + 0x3105;
    }
#endif /* #if defined(__MMI_LANG_TR_CHINESE__) */

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_code_to_symbol
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
U16  mmi_ime_word_code_to_symbol(UI_character_type code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (code)
    {
    case 0x002D:
        return MMI_IMC_SYMB_TONE_1;
        
    case 0x02CA:
        return MMI_IMC_SYMB_TONE_2;
        
    case 0x02C7:
        return MMI_IMC_SYMB_TONE_3;
        
    case 0x02CB:
        return MMI_IMC_SYMB_TONE_4;
        
    case 0x02D9:
        return MMI_IMC_SYMB_TONE_5;
#if defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__)        
    case 0xF000:      
        return MMI_IMC_SYMB_STROKE_WILDCARD;
        
    case 0xF007:          
        return MMI_IMC_SYMB_STROKE_LEFT;
        
    case 0xF004:
        return MMI_IMC_SYMB_STROKE_OVER;
        
    case 0xF002:           
        return MMI_IMC_SYMB_STROKE_DOT;
        
    case 0xF001:  
        return MMI_IMC_SYMB_STROKE_DOWN;
        
    case 0xF005:      
        return MMI_IMC_SYMB_STROKE_OVER_DOWN;

#endif /* defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__) */        
    default:
#ifdef __MMI_CSTAR_SM_CHINESE__
        if (code >= 0x0061 && code <= 0x007A) 
        {
            return code - 0x0061 + MMI_IMC_SYMB_PY_BASE; /* mmi_imc_symbol_pinyin_enum */
        }
        else 
#endif /* __MMI_CSTAR_SM_CHINESE__ */
#ifdef __MMI_CSTAR_TR_CHINESE__
        if (code >= 0x3105 && code <= 0x3129)
        {
            return code - 0x3105 + MMI_IMC_SYMB_ZY_BASE; /* mmi_imc_symbol_bopomofo_enum */
        }
        else
#endif /* __MMI_CSTAR_TR_CHINESE__ */
        {
            return 0xFF;
        }
        break;
    }
    
    return 0xFF; 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_is_symbol_key
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL  mmi_ime_word_is_symbol_key( S32 input_mode, mmi_imc_key_custom_value key_code )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
          
    U32 symbol_keys = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input_mode == g_engine.curr_mode_info->input_mode)
    {
        symbol_keys = g_engine.curr_mode_info->symbol_keys;
    }
    
    switch(key_code)
    {
    case MMI_IMC_KEY_UP:
    case MMI_IMC_KEY_DOWN:
    case MMI_IMC_KEY_LEFT:
    case MMI_IMC_KEY_RIGHT:
    case MMI_IMC_KEY_CONFIRM: 
    case MMI_IMC_KEY_CANCEL: 
    case MMI_IMC_KEY_CLEAR: 
        return MMI_FALSE;
    case MMI_IMC_KEY_SYM_0:
    case MMI_IMC_KEY_SYM_1:
    case MMI_IMC_KEY_SYM_2:
    case MMI_IMC_KEY_SYM_3:
    case MMI_IMC_KEY_SYM_4:
    case MMI_IMC_KEY_SYM_5:
    case MMI_IMC_KEY_SYM_6:
    case MMI_IMC_KEY_SYM_7:
    case MMI_IMC_KEY_SYM_8:
    case MMI_IMC_KEY_SYM_9:
        if (symbol_keys & (MMI_IME_REQUIRED_KEY_0 << (key_code - MMI_IMC_KEY_SYM_0)))
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    case MMI_IMC_KEY_SYM_STAR:
        if (symbol_keys & MMI_IME_REQUIRED_KEY_STAR)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    case MMI_IMC_KEY_SYM_POUND:
        if (symbol_keys & MMI_IME_REQUIRED_KEY_POUND)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    default:
        return MMI_FALSE;
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_is_redical
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL  mmi_ime_word_is_redicals(UI_character_type key_code )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_is_wildcard
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_is_wildcard(UI_character_type code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (code == 0xF000)
    	return MMI_TRUE;
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_add_separator_to_candidate_buffer
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_add_separator_to_candidate_buffer(UI_character_type * destination_buffer, UI_character_type * source_buffer, S32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < num && source_buffer[i] != 0)
    {
        destination_buffer[j] = source_buffer[i];
        destination_buffer[j + 1] = 0; /* Default separator is '\0' */
        i++;
        j += 2;
    }

    destination_buffer[j] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_map_char_to_symbol
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_imc_symbol_key_enum mmi_ime_word_map_char_to_symbol(S32 input_mode, UI_character_type char_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_cstar_mode_info_struct_p      mode_info_ptr;
    unsigned short                        key_code;
    int                                   ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mode_info_ptr = (mmi_ime_cstar_mode_info_struct_p)mmi_ime_cstar_query_mode_info(input_mode);
    
    if ( NULL == mode_info_ptr )
        return MMI_IMC_SYMB_KEY_INVALID;

    ret = kmx_latin_query_key_map(*(mode_info_ptr->ldb_ptr), char_code, &key_code);

    if (!ret)
    {
        return MMI_IMC_SYMB_KEY_INVALID;
    }
    else
    {
        return (key_code + MMI_IMC_SYMB_KEY_BASE);
    }
}


#if defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_get_associates_chinese
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void  mmi_ime_cstar_get_associates_chinese( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned short buffer[KMX_MAX_ASSOCIATION_QUERY_BUFFER];
    int ret_val;
    S32 i, j, cnt;
    void * database;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT( NULL != param_ptr );
    
    if (param_ptr->pre_string[0] == 0)
    {
        return;
    }

#if defined(__MMI_CSTAR_SM_CHINESE__)
    if (g_engine.init_info.database == kmx_ldb_stroke_gb2312)
    {
        database = (void *)kmx_ldb_pinyin_danzi;
    }
    else 
#endif /* defined(__MMI_CSTAR_SM_CHINESE__) */
#if defined(__MMI_CSTAR_TR_CHINESE__)
    if (g_engine.init_info.database == kmx_ldb_stroke_big5)
    {
        database = (void *)kmx_ldb_zhuyin_cizu;
    }
    else
#endif /* defined(__MMI_CSTAR_TR_CHINESE__) */
    {
        database = (void *)g_engine.init_info.database;
    }
    
#if defined(__MMI_CSTAR_SM_CHINESE__)
    if (database != kmx_ldb_pinyin_danzi)
#endif /* defined(__MMI_CSTAR_SM_CHINESE__) */  
#if defined(__MMI_CSTAR_TR_CHINESE__)
    if (database != kmx_ldb_zhuyin_cizu)
#endif /* defined(__MMI_CSTAR_TR_CHINESE__) */
    {
        return;
    }
    
    ret_val = kmx_chinese_query_association((const void *)database,
                                            (unsigned short) param_ptr->pre_string[0],
                                            buffer,
                                            KMX_MAX_ASSOCIATION_QUERY_BUFFER);

    if (!ret_val)
    {
        return;
    }

    i = param_ptr->first_index;
    j = 0;
    cnt = 0;
    
    while(i < KMX_MAX_ASSOCIATION_QUERY_BUFFER - 1 && cnt < param_ptr->desired_cnt)
    {
        if (buffer[i] == 0 )
        {
            break;
        }
        
        result_ptr->result_buffer[j++] = (UI_character_type)buffer[i++];
        result_ptr->result_buffer[j++] = 0;
        cnt++;
    }

    result_ptr->result_cnt = cnt;
    
    if (cnt == param_ptr->desired_cnt)
    {
        if (i < KMX_MAX_ASSOCIATION_QUERY_BUFFER - 1)
        {
            if(buffer[i] != 0)
            {
                result_ptr->next_page = MMI_TRUE;
            }
            else
            {
                result_ptr->next_page = MMI_FALSE;
            }
        }
        else
        {
            result_ptr->next_page = MMI_FALSE;
        }
    }
    else
    {
        result_ptr->next_page = MMI_FALSE;
    }
}
#endif /* #if defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_get_associates_alphabetic
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void  mmi_ime_cstar_get_associates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_engine_get_char_info
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_engine_get_char_info(UI_character_type code, UI_string_type info_buffer, S32 buffer_size, S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_val = MMI_FALSE;
    S32 i=0;
#if defined(__MMI_CSTAR_SM_CHINESE__)
    KMX_CHAR_PINYIN  pinyin;
#endif
#if defined(__MMI_CSTAR_TR_CHINESE__)
    KMX_CHAR_ZHUYIN  zhuyin;
#endif
    char stroke_buffer[10];
    mmi_ime_cstar_mode_info_struct_p mode_info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mode)
    {
    #if defined (__MMI_CSTAR_TR_CHINESE__)
    case INPUT_MODE_TR_MULTITAP_BOPOMO:
    case INPUT_MODE_TR_STROKE:
    #endif
    case INPUT_MODE_MULTITAP_PINYIN:
    case INPUT_MODE_SM_PINYIN:
    case INPUT_MODE_SM_STROKE:
        mode_info_ptr = (mmi_ime_cstar_mode_info_struct_p)mmi_ime_cstar_query_mode_info(mode);
        break;

    default:
        return MMI_FALSE;
    }

    MMI_ASSERT(mode_info_ptr != NULL);

    g_engine.init_info.database = *(mode_info_ptr->ldb_ptr);
    g_engine.init_info.flags = 0;

    g_engine.init_info.user_data = NULL;
    g_engine.init_info.user_data_size = 0;
    
    switch(mode)
        {
        #if defined (__MMI_LANG_SM_CHINESE__)
        case INPUT_MODE_SM_PINYIN:
        case INPUT_MODE_MULTITAP_PINYIN	:	
        ret_val = (S32)kmx_pinyin_initialize(&g_engine.cstar_engine, (const KMX_IME_ENGINE_INIT *)&g_engine.init_info);
        break;
        case INPUT_MODE_SM_STROKE:
        ret_val = (S32)kmx_stroke_initialize(&g_engine.cstar_engine, (const KMX_IME_ENGINE_INIT *)&g_engine.init_info);
        break;
        #endif    
        #if defined   (__MMI_LANG_TR_CHINESE__)
        case INPUT_MODE_TR_MULTITAP_BOPOMO:	
        ret_val = (S32)kmx_zhuyin_initialize(&g_engine.cstar_engine, (const KMX_IME_ENGINE_INIT *)&g_engine.init_info);    
        break;
        case INPUT_MODE_TR_STROKE:
        ret_val = (S32)kmx_stroke_initialize(&g_engine.cstar_engine, (const KMX_IME_ENGINE_INIT *)&g_engine.init_info);
        break;
        #endif	
        }

    MMI_ASSERT(ret_val);
    
    switch(mode)
    {
    
#if defined(__MMI_CSTAR_TR_CHINESE__)

	case INPUT_MODE_TR_MULTITAP_BOPOMO:		
        ret_val = kmx_chinese_query_zhuyin(*(mode_info_ptr->ldb_ptr), code, &zhuyin);
        if (ret_val)
        {
            for (i = 0; i < zhuyin.length && i < buffer_size; i++)
            {
                info_buffer[i] = zhuyin.string[i];
            }
            info_buffer[i] = 0;
        }
#endif /* defined(__MMI_CSTAR_TR_CHINESE__) */
        break;
    case INPUT_MODE_MULTITAP_PINYIN:
    case INPUT_MODE_SM_PINYIN:

#if defined(__MMI_CSTAR_SM_CHINESE__)
        ret_val = kmx_chinese_query_pinyin(*(mode_info_ptr->ldb_ptr), code, &pinyin);
        if (ret_val)
        {
            for (i = 0; i < pinyin.length && i < buffer_size; i++)
            {
                info_buffer[i] = pinyin.string[i];
            }
            info_buffer[i] = 0;
        }
#endif /* defined(__MMI_CSTAR_SM_CHINESE__) */
        break;
   #if defined (__MMI_CSTAR_TR_CHINESE__)
    case INPUT_MODE_TR_STROKE:
   #endif		
    case INPUT_MODE_SM_STROKE:
#if defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__)
        ret_val = kmx_chinese_query_stroke(*(mode_info_ptr->ldb_ptr), code, stroke_buffer, 10);
        if (ret_val)
        {
            for (i = 0; stroke_buffer[i] && i < buffer_size; i++)
            {
                switch(stroke_buffer[i])
                {
                case KMX_STROKE_HENG:
                    info_buffer[i] = 0xF004;
                    break;
                    
                case KMX_STROKE_SHU:
                    info_buffer[i] = 0xF001;
                    break;
                    
                case KMX_STROKE_PIE:
                    info_buffer[i] = 0xF007;
                    break;
                    
                case KMX_STROKE_DIAN:
                    info_buffer[i] = 0xF002;
                    break;
                    
                case KMX_STROKE_ZHE:
                    info_buffer[i] = 0xF005;
                    break;
                    
                case KMX_STROKE_WILDCARD:
                    info_buffer[i] = 0xFF1F;
                    break;
                    
                default:
                    break;
                }
                
            }
            info_buffer[i] = 0;
        }
#endif /* defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__) */

        break;

    default:
        return MMI_FALSE;
        break;
    }

    if (ret_val)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_get_candidates_alphabetic
 * DESCRIPTION
 * fetch Alphabetic Candidates from Cstar Library
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void  mmi_ime_cstar_get_candidates_alphabetic( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned char input_string[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE];
    U16  i, j, k;
    int ret_val;
    unsigned short match_flags;
    KMX_LATIN_MATCH_RESULT match_result;
    const mmi_ime_mode_details_struct* curr_mode = mmi_imm_get_input_mode_array_item();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ASSERT( NULL != param_ptr );
    
    if ( 0 == param_ptr->elembuf_cnt )
        return;
    
    for (i = 0; i < param_ptr->elembuf_cnt; i++)
    {
        input_string[i] = param_ptr->elembuf_ptr[i] - MMI_IMC_SYMB_KEY_BASE + '0';
    }
    
    if (curr_mode->flags & MMI_IME_UPPERCASE)
    {
		match_flags = KMX_LATIN_UPPER_CASE;
		
    }

    else  
    {
		match_flags = KMX_LATIN_LOWER_CASE;
    }
    

    ret_val = kmx_latin_match(&g_engine.cstar_engine, 
                              NULL, 
                              (char*)input_string, 
                              param_ptr->elembuf_cnt, 
                              match_flags, 
                              param_ptr->first_index,
                              &match_result);

    if (!ret_val)
    { 
        return;
    
    }

    if (match_result.count < param_ptr->desired_cnt)
    {
        result_ptr->result_cnt = (U8)match_result.count;
        result_ptr->next_page = MMI_FALSE;
    }
    else if (match_result.count == param_ptr->desired_cnt )
    {
        result_ptr->result_cnt = (U8)match_result.count;
        
        if (match_result.more_available)
        {
            result_ptr->next_page = MMI_TRUE;
        }
        else
        {
            result_ptr->next_page = MMI_FALSE;
        }
    }
    else
    {
        result_ptr->result_cnt = param_ptr->desired_cnt;
        result_ptr->next_page = MMI_TRUE;
    }

    for (i = 0, k = 0; i < result_ptr->result_cnt; i++)
    {
        for (j = 0; j < match_result.table[i].length; j ++)
        {
            result_ptr->result_buffer[k++] = (UI_character_type)match_result.table[i].string[j];
        }
        
        result_ptr->result_buffer[k++] = 0;
    }
        

    
        
    if ( result_ptr->result_cnt > 0 )
    {
        /* adjust result case */
        mmi_ime_cstar_change_candidates_case(result_ptr);
    }
}

#if defined (__MMI_CSTAR_STROKE_INPUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_get_spellings_stroke
 * DESCRIPTION
 * fetch Stroke Compositions from Cstar Library
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void   mmi_ime_cstar_get_spellings_stroke( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  i;
    U8  symb;
    UI_string_type temp_str;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ASSERT( NULL != param_ptr );
    if ( 0 == param_ptr->elembuf_cnt )
        return;
    
    temp_str = result_ptr->result_buffer;
    
    for ( i = 0; i < param_ptr->elembuf_cnt; ++i )
    {
        symb = param_ptr->elembuf_ptr[i];
        if ( MMI_FALSE != MMI_IMC_IS_SYMB_KEY(symb) )
        {
            if (g_cstar_keys_stroke[symb - MMI_IMC_SYMB_KEY_BASE])
            {
                *temp_str = mmi_ime_word_symbol_to_code((U8)g_cstar_keys_stroke[symb - MMI_IMC_SYMB_KEY_BASE]);
                temp_str++;
            }
            else /* Invalid key */
            {
                i = 0;
                temp_str = result_ptr->result_buffer;
                break;
            }
        }
        else
        {
            i = 0;
            temp_str = result_ptr->result_buffer;
            break;
        }       
    }

    *temp_str = 0;

    result_ptr->result_cnt = i;
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_get_candidates_stroke
 * DESCRIPTION
 * fetch Stroke Candidates from Cstar Library
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void   mmi_ime_cstar_get_candidates_stroke( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char stroke_string[KMX_MAX_STROKE_LENGTH];
    S32 i;
    int ret_val;
    KMX_STROKE_MATCH_RESULT match_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ASSERT( NULL != param_ptr );
    
    if ( 0 == param_ptr->elembuf_cnt )
    {
        return;
    }
    if (param_ptr->elembuf_cnt == 1 && param_ptr->elembuf_ptr[0] == MMI_IMC_SYMB_KEY_7)
    {
        S32 cnt = 0;
        UI_character_type cand = NULL;
        for (cnt = 0; cnt <= param_ptr->desired_cnt & (cand = g_chinese_symbol_string[param_ptr->first_index + cnt]) != 0; cnt ++)
        {
            result_ptr->result_buffer[(cnt<<1)] = cand;
            result_ptr->result_buffer[(cnt<<1) + 1] = 0x00; 
        }
        if (cnt >= param_ptr->desired_cnt)
        {
            result_ptr->next_page = MMI_TRUE;
            result_ptr->result_cnt = param_ptr->desired_cnt;
        }
        else
        {
            result_ptr->next_page = MMI_FALSE;
            result_ptr->result_cnt = cnt;
        }

    }

    for(i = 0; i < param_ptr->elembuf_cnt; i++)
    {
        stroke_string[i] = g_cstar_codes_stroke[param_ptr->elembuf_ptr[i] - MMI_IMC_SYMB_STROKE_BASE];
    }
    
    stroke_string[i] = 0;
    
    ret_val = kmx_stroke_match(&g_engine.cstar_engine, 
                               stroke_string, 
                               (unsigned short)param_ptr->elembuf_cnt,
                               (unsigned short)param_ptr->first_index,
                               &match_result);

    if (!ret_val)
    {
        return;
    }

    if (match_result.count < param_ptr->desired_cnt)
    {
        result_ptr->result_cnt = (U8)match_result.count;
        result_ptr->next_page = MMI_FALSE;
    }
    else if (match_result.count == param_ptr->desired_cnt )
    {
        result_ptr->result_cnt = (U8)match_result.count;
        
        if (match_result.more_available)
        {
            result_ptr->next_page = MMI_TRUE;
        }
        else
        {
            result_ptr->next_page = MMI_FALSE;
        }
    }
    else
    {
        result_ptr->result_cnt = param_ptr->desired_cnt;
        result_ptr->next_page = MMI_TRUE;
    }

    mmi_ime_word_add_separator_to_candidate_buffer(result_ptr->result_buffer, (UI_character_type *)match_result.table, result_ptr->result_cnt);
}
#endif /*defined (__MMI_CSTAR_STROKE_INPUT__)*/

#if defined(__MMI_CSTAR_SM_CHINESE__)
#if defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_get_spellings_pinyin_multitap
 * DESCRIPTION
 * fetch Pinyin  Compositions from Cstar Library
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void   mmi_ime_cstar_get_spellings_pinyin_multitap( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U8          i;
    UI_string_type temp_str;
    U8          symb;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ASSERT( NULL != param_ptr );
    if ( 0 == param_ptr->elembuf_cnt )
        return;

    temp_str = result_ptr->result_buffer;
    
    for ( i = 0; i < param_ptr->elembuf_cnt; i++ )
    {
        symb = param_ptr->elembuf_ptr[i];
        if ( MMI_FALSE != MMI_IMC_IS_SYMB_PY( symb ) )
        {
            *temp_str = mmi_ime_word_symbol_to_code(symb);
            temp_str++;
        }
        else
        {
            i = 0;
            temp_str = result_ptr->result_buffer;
            break;
        }
    }

    *temp_str = 0;
    result_ptr->result_cnt = i;
}

#endif /* __MMI_CSTAR_MULTITAP_PHONETIC_INPUT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_get_candidates_pinyin
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_cstar_get_candidates_pinyin( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, k, j;
    char pinyin_string[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE];
    int ret_val;
    KMX_PINYIN_WORD_MATCH_RESULT    match_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ASSERT( NULL != param_ptr );
    
    if ( 0 == param_ptr->elembuf_cnt )
        return;
        
    if ( param_ptr->tone_value >= MMI_IMC_SYMB_TONE_1 && param_ptr->tone_value <= MMI_IMC_SYMB_TONE_5)
    {
        return;
    }
    
    for (i = 0; i < param_ptr->elembuf_cnt; i++)
    {
        pinyin_string[i] = mmi_ime_word_symbol_to_code(param_ptr->elembuf_ptr[i]); /* Cstar use unicode to query */
    }

    pinyin_string[i] = 0;

    ret_val = kmx_pinyin_match(&g_engine.cstar_engine, 
                               (const char *)pinyin_string,
                               (unsigned short)param_ptr->elembuf_cnt,
                               (unsigned short)param_ptr->first_index,
                               &match_result);

    if (!ret_val)
    {
        return;
    }

    if (match_result.count < param_ptr->desired_cnt)
    {
        result_ptr->result_cnt = (U8)match_result.count;
        result_ptr->next_page = MMI_FALSE;
    }
    else if (match_result.count == param_ptr->desired_cnt )
    {
        result_ptr->result_cnt = (U8)match_result.count;
        
        if (match_result.more_available)
        {
            result_ptr->next_page = MMI_TRUE;
        }
        else
        {
            result_ptr->next_page = MMI_FALSE;
        }
    }
    else
    {
        result_ptr->result_cnt = param_ptr->desired_cnt;
        result_ptr->next_page = MMI_TRUE;
    }

    for (i = 0, k = 0; i < result_ptr->result_cnt ; i++)
    {
        for (j = 0; j < match_result.table[i].length; j++)
        {
            result_ptr->result_buffer[k++] = (UI_character_type)match_result.table[i].string[j];
        }

        result_ptr->result_buffer[k++] = 0;
    }
}


#if defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_get_spellings_pinyin_smart
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_ime_cstar_get_spellings_pinyin_smart( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U16  i, j, k;
    char digit_string[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE];
    int ret_val;
    KMX_PINYIN_COMPOSITION     pinyin_composition;
    KMX_PINYIN_MATCH_RESULT     pinyin_match_result;
    KMX_PINYIN_WORD_MATCH_RESULT    word_match_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ASSERT( NULL != param_ptr );
    
    if ( 0 == param_ptr->elembuf_cnt )
        return;

    for (i = 0; i < param_ptr->elembuf_cnt; i++)
    {
        if (param_ptr->elembuf_ptr[i] == MMI_IMC_SYMB_KEY_0)
        {
            digit_string[i] = 0x20;
        }
        else
        {
            digit_string[i] = param_ptr->elembuf_ptr[i] - MMI_IMC_SYMB_KEY_BASE + '0';
        }
    }
    
    digit_string[i] = 0;
    
    ret_val = kmx_digit_pinyin_match(&g_engine.cstar_engine, 
                                     (const char *)digit_string,
                                     (unsigned short)param_ptr->elembuf_cnt,
                                     KMX_PINYIN_MATCH_INDEX_NONE,
                                     0,
                                     &pinyin_composition,
                                     &pinyin_match_result,
                                     &word_match_result);

    if (!ret_val || pinyin_match_result.count == 0)
    {
        return;
    }

    if ((U8)(pinyin_match_result.count - param_ptr->first_index) > param_ptr->desired_cnt)
    {
        result_ptr->result_cnt = param_ptr->desired_cnt;
        result_ptr->next_page = MMI_TRUE;
    }
    else
    {
        result_ptr->result_cnt = (U8)(pinyin_match_result.count - param_ptr->first_index);
        result_ptr->next_page = MMI_FALSE;
    }                                 

    for (i = 0, k = 0; i < result_ptr->result_cnt ; i++)
    {
        for (j = 0; j < pinyin_match_result.table[i + param_ptr->first_index].length; j++)
        {
            result_ptr->result_buffer[k++] = (UI_character_type)pinyin_match_result.table[i + param_ptr->first_index].string[j];
        }

        result_ptr->result_buffer[k++] = 0;
    }
}
#endif
#endif /* __MMI_CSTAR_SM_CHINESE__ */


#if defined(__MMI_CSTAR_TR_CHINESE__)
#if defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_get_spellings_zhuyin_multitap
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void   mmi_ime_cstar_get_spellings_zhuyin_multitap( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U8          i, symb;
    UI_string_type temp_str;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ASSERT( NULL != param_ptr );
    if ( 0 == param_ptr->elembuf_cnt )
        return;

    temp_str = result_ptr->result_buffer;
        
    for ( i = 0; i < param_ptr->elembuf_cnt; i++ )
    {
        symb = param_ptr->elembuf_ptr[i];
        if ( MMI_FALSE != MMI_IMC_IS_SYMB_ZY(symb) )
        {
            *temp_str = mmi_ime_word_symbol_to_code(symb);
            temp_str++;
        }
        else if (MMI_IMC_IS_SYMB_TONE(symb))
        {
            *temp_str = mmi_ime_word_symbol_to_code(symb);
            temp_str++;
        }
        else
        {
            i = 0;
            temp_str = result_ptr->result_buffer;
            break;
        }
    }
    
    *temp_str = 0;
    result_ptr->result_cnt = i;
}

#endif /* __MMI_CSTAR_MULTITAP_PHONETIC_INPUT__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_get_candidates_zhuyin
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void   mmi_ime_cstar_get_candidates_zhuyin( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, k, j;
    unsigned short zhuyin_string[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE];
    int ret_val;
    KMX_ZHUYIN_WORD_MATCH_RESULT    match_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ASSERT( NULL != param_ptr );
    
    if ( 0 == param_ptr->elembuf_cnt || param_ptr->elembuf_cnt > 3)
        return;
    
    for (i = 0; i < param_ptr->elembuf_cnt; i++)
    {
        zhuyin_string[i] = mmi_ime_word_symbol_to_code(param_ptr->elembuf_ptr[i]); /* Cstar use unicode to query */
    }

    if (param_ptr->tone_value != MMI_IMC_SYMB_TONE_NONE)
    {
        zhuyin_string[i] = mmi_ime_word_symbol_to_code(param_ptr->tone_value);
        zhuyin_string[i+1]=0;
        param_ptr->elembuf_cnt++;
    }
    else
    {
        zhuyin_string[i] = 0;
    }

    ret_val = kmx_zhuyin_match(&g_engine.cstar_engine, 
                               (const unsigned short *)zhuyin_string,
                               (unsigned short)param_ptr->elembuf_cnt,
                               (unsigned short)param_ptr->first_index,
                               &match_result);

    if (!ret_val)
    {
        return;
    }

    if (match_result.count < param_ptr->desired_cnt)
    {
        result_ptr->result_cnt = (U8)match_result.count;
        result_ptr->next_page = MMI_FALSE;
    }
    else if (match_result.count == param_ptr->desired_cnt )
    {
        result_ptr->result_cnt = (U8)match_result.count;
        
        if (match_result.more_available)
        {
            result_ptr->next_page = MMI_TRUE;
        }
        else
        {
            result_ptr->next_page = MMI_FALSE;
        }
    }
    else
    {
        result_ptr->result_cnt = param_ptr->desired_cnt;
        result_ptr->next_page = MMI_TRUE;
    }

    for (i = 0, k = 0; i < result_ptr->result_cnt ; i++)
    {
        for (j = 0; j < match_result.table[i].length; j++)
        {
            result_ptr->result_buffer[k++] = (UI_character_type)match_result.table[i].string[j];
        }
        result_ptr->result_buffer[k++] = 0;
    }
}


#endif /* defined(__MMI_CSTAR_TR_CHINESE__)*/

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_mode_info_struct
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static const mmi_ime_cstar_mode_info_struct * mmi_ime_cstar_query_mode_info( S32 input_mode )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U16  i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if ( input_mode >= INPUT_MODE_MAX_NUM )
        return NULL;
    
    for ( i = 0; g_mode_infos[i].input_mode != INPUT_MODE_MAX_NUM; ++i )
    {
        if ( g_mode_infos[i].input_mode == input_mode )
        {
            return &g_mode_infos[i];
        }
    }
    
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_char_to_upper
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static UI_character_type mmi_ime_cstar_char_to_upper(UI_character_type char_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (UI_character_type) mmi_ime_word_toupper((U16) char_code);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_char_to_lower
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static UI_character_type mmi_ime_cstar_char_to_lower(UI_character_type char_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (UI_character_type) mmi_ime_word_tolower((U16) char_code);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_change_candidates_case
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void  mmi_ime_cstar_change_candidates_case(mmi_ime_query_result_struct_p result_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_engine.case_type == MMI_IME_WORD_CASE_UPPER)
    {
        while (j < result_str->result_cnt)
        {
            result_str->result_buffer[i] = mmi_ime_cstar_char_to_upper(result_str->result_buffer[i]);
            i++;
            
            while (result_str->result_buffer[i])
            {
                result_str->result_buffer[i] = mmi_ime_cstar_char_to_upper(result_str->result_buffer[i]);
                i++;
            }
            i++;
            j++;
        }
    }

	else if (g_engine.case_type == MMI_IME_WORD_CASE_LOWER)
    {
        while (j < result_str->result_cnt)
        {
            result_str->result_buffer[i] = mmi_ime_cstar_char_to_lower(result_str->result_buffer[i]);
            i++;
            
            while (result_str->result_buffer[i])
            {
                result_str->result_buffer[i] = mmi_ime_cstar_char_to_lower(result_str->result_buffer[i]);
                i++;
            }
            i++;
            j++;
        }
    }
}






#endif /* #ifdef  __MMI_CSTAR__ */

