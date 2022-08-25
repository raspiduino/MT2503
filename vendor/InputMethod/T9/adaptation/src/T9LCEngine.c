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
 *    T9Engine.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 * Adaptation layer for T9 Core for Alphabetic & Phonetic ambiguous & multitap inputs
 * for T9 Version 7 and 7.4
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

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_T9__

#include "GlobalConstants.h"
#include "Fat_fs.h"
#include "Word_Engine.h"
#include "IMERes.h"     /* include for mmi_ime_mode_details_struct */
#include "ImeGprot.h"
#include "Imc_symbol.h"
#include "Imc_config.h"
#include "t9.h"
#include "t9awapi.h"
#include "wgui_inputs.h"

#if defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_T9_SM_CHINESE__)
#include "t9ccapi.h"
#endif /* defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_T9_SM_CHINESE__) */ 

#include "t9api.h"
#include "t9gen.h"

#ifdef __MMI_T9_MULTITAP__
#include "Multitap_engine.h"
#endif /* __MMI_T9_MULTITAP__ */

#include "Imc.h"

/*****************************************************************************
 * Define
 *****************************************************************************/

#if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__)
#define __T9_CHINESE
#endif /* defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */ 

/*****************************************************************************
 * Define
 *****************************************************************************/

#define MMI_MULTITAP_T9_PAGE_BUFFSIZE   (32 + 1)

#if defined(__MMI_IME_USER_DATABASE__)

#define MMI_IME_T9_UDB_SIZE (20 * 1024) /* 20k bytes (T9 recommended), if we don't turn on word completion
                                         * it should be 4k butes. It should be bigger than T9MINUDBDATABYTES */

#define MMI_IME_T9_CDB_SIZE (4 * 1024)  /* 4k bytes */

#define MMI_IME_USER_DATABASE_FILE_UDB        L"ime_udb.dat"
#define MMI_IME_USER_DATABASE_FILE_CDB        L"ime_cdb.dat"

#endif


/*****************************************************************************
 * Global variables
 *****************************************************************************/

#if !defined (__MMI_T9_V7_4__)
extern T9STATUS T9FARCALL T9LoadChnLdb(T9CCFieldInfo *pCCFieldInfo, T9ChineseData T9FARDATA *pT9CCLdbHeader);
extern T9UINT T9ReadLdbData(T9FieldInfo *pFieldInfo, T9U32 dwOffset, T9U8 *pbDst, T9UINT nSize);
#endif

/*****************************************************************************
 * Typedef
 *****************************************************************************/
typedef enum
{
    MMI_IME_T9_INIT_TYPE_ALPHABETIC = 0,
    MMI_IME_T9_INIT_TYPE_PHONETIC,
    MMI_IME_T9_INIT_TYPE_STROKE,
    MMI_IME_T9_INIT_TYPE_DIRECT,
    MMI_IME_T9_INIT_TYPE_MAX
} mmi_ime_t9_init_type_enum;

typedef union T9CCAWFieldInfo_u
{
#if defined __T9_CHINESE 
    T9CCFieldInfo CCFieldInfo;
#endif /* defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_T9_SM_CHINESE__) */    
    T9AWFieldInfo AWFieldInfo;
} T9CCAWFieldInfo;

typedef struct
{
    S32 input_mode;
    const T9MINOR *key_map_ptr;
    mmi_ime_t9_init_type_enum init_type;
    T9UINT nLdbNum;
    U32 required_keys;
    U32 symbol_keys;
    mmi_ime_get_spellings_funcptr get_spell_funcptr;
    mmi_ime_get_associates_funcptr get_assoc_funcptr;
    mmi_ime_get_candidates_funcptr get_cand_funcptr;
} mmi_ime_t9_mode_info_struct, *mmi_ime_t9_mode_info_struct_p;

typedef struct
{
#ifdef __MMI_T9_MULTITAP__
    T9SYMB              multitap_page[MMI_MULTITAP_T9_PAGE_BUFFSIZE];
    UI_character_type   multitap_string[MMI_MULTITAP_T9_PAGE_BUFFSIZE];
#endif /* __MMI_T9_MULTITAP__ */
    
    T9CCAWFieldInfo field_info;

#if defined(__MMI_IME_USER_DATABASE__)
    U16                udb_data[MMI_IME_T9_UDB_SIZE / 2];
    U16                cdb_data[MMI_IME_T9_CDB_SIZE / 2];
#endif

    T9SYMB              text_buff[MMI_IME_T9_MAX_TEXT_BUFFSIZE + 1];
    T9AuxType           aux_buff[MMI_IME_T9_MAX_TEXT_BUFFSIZE + 1];
} mmi_ime_t9_data_struct, *mmi_ime_t9_data_struct_p;

typedef struct
{
    mmi_ime_t9_data_struct data;
    const T9MINOR *key_map_ptr;
    mmi_ime_t9_mode_info_struct_p t9_mode_info;
    MMI_BOOL is_inited;
    U8 input_mode;
    U8 case_type;
} mmi_ime_t9_word_engine_struct, *mmi_ime_t9_word_engine_struct_p;

/*****************************************************************************
 * Typedef
 *****************************************************************************/
typedef T9MINOR(*mmi_ime_symb_conv_funcptr) (U8 symb_value, T9MINOR *symb_map);

/*****************************************************************************
 * Local Functions
 *****************************************************************************/

/* Utility functions */
static UI_character_type mmi_ime_t9_t9code_to_code(T9U8 t9code, S32 mode);

static void mmi_ime_t9_get_candidates(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr);

/* multitap functions */
static T9MINOR mmi_ime_t9_from_symb_to_t9key(U16 symb_key);

/* word functions */
static T9STATUS T9_handle_request(T9FieldInfo *field_info_ptr, T9Request *request_ptr);
static void mmi_ime_t9_change_candidates_case(mmi_ime_query_result_struct_p result_str);

#ifdef __T9_CHINESE
static MMI_BOOL mmi_ime_t9_init_stroke_chn(mmi_ime_t9_mode_info_struct_p t9_mode_info, mmi_ime_mode_details_struct *mode_detail_ptr);
static MMI_BOOL mmi_ime_t9_init_phonetic_chn(mmi_ime_t9_mode_info_struct_p t9_mode_info, mmi_ime_mode_details_struct *mode_detail_ptr);
#endif /* __T9_CHINESE */ 

static MMI_BOOL mmi_ime_t9_init_alphabetic(mmi_ime_t9_mode_info_struct_p t9_mode_info, mmi_ime_mode_details_struct *mode_detail_ptr);
static MMI_BOOL mmi_ime_t9_init_number(mmi_ime_t9_mode_info_struct_p t9_mode_info, mmi_ime_mode_details_struct *mode_detail_ptr);

static mmi_ime_t9_mode_info_struct_p mmi_ime_t9_get_mode_info(S32 input_mode);

/* Query functions */

static void mmi_ime_t9_get_candidates_alphabetic(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr);

static void mmi_ime_t9_get_associates(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr);

#if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__)
static void mmi_ime_t9_get_spellings_stroke(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr);
static void mmi_ime_t9_get_candidates_stroke(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr);
#endif /* defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */ /* #if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */

/* Simplified Chinese functions */
#if defined(__MMI_T9_SM_CHINESE__)

#if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
static void mmi_ime_t9_get_spellings_pinyin_multitap(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr);
#endif /* defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */ 

#if defined(__MMI_T9_SMART_PHONETIC_INPUT__)
static void mmi_ime_t9_get_spellings_pinyin_smart( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* #if defined(__MMI_T9_SMART_PHONETIC_INPUT__) */

static void mmi_ime_t9_get_candidates_pinyin( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );

#endif /* #if defined(__MMI_T9_SM_CHINESE__) */

/* Traditional Chinese functions */
#if defined(__MMI_T9_TR_CHINESE__)

#if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
static void mmi_ime_t9_get_spellings_zhuyin_multitap( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* #if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */

#if (defined(__MMI_T9_SMART_PHONETIC_INPUT__) && defined(__MMI_T9_AMB_BPMF_INPUT__))
static void mmi_ime_t9_get_spellings_zhuyin_smart( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );
#endif /* (defined(__MMI_T9_SMART_PHONETIC_INPUT__) && defined(__MMI_T9_AMB_BPMF_INPUT__)) */

static void mmi_ime_t9_get_candidates_zhuyin( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr );

#endif /* #if defined(__MMI_T9_TR_CHINESE__) */

#if defined(__MMI_IME_USER_DATABASE__)

static FS_HANDLE mmi_ime_t9_open_file(PU16 path_name_ptr, PU16 file_name_ptr, MMI_BOOL is_create_always);

static void mmi_ime_t9_close_file(FS_HANDLE file_handle);

static U32 mmi_ime_t9_write_file(FS_HANDLE file_handle, PU16 data_ptr, U32 size_in_byte);

static U32 mmi_ime_t9_read_file(FS_HANDLE file_handle, PU16 data_ptr, U32 size_in_byte);

#endif

#ifdef __MMI_T9_MULTITAP__
static MMI_BOOL mmi_ime_multitap_vendor_valid_key_check( mmi_imc_symbol_key_enum sym);
static UI_string_type mmi_ime_multitap_vendor_get_string(S32 index);
#endif
/*****************************************************************************
 * Local variables
 *****************************************************************************/

/* Symbol keys mapping (by language) */
static const T9MINOR g_t9_keys_alphabetic[MMI_IMC_SYMB_KEY_MAX - MMI_IMC_SYMB_KEY_BASE] = 
{
    T9KEYAMBIGA,    /* MMI_IMC_SYMB_KEY_0 */
    T9KEYAMBIG1,    /* MMI_IMC_SYMB_KEY_1 */
    T9KEYAMBIG2,    /* MMI_IMC_SYMB_KEY_2 */
    T9KEYAMBIG3,    /* MMI_IMC_SYMB_KEY_3 */
    T9KEYAMBIG4,    /* MMI_IMC_SYMB_KEY_4 */
    T9KEYAMBIG5,    /* MMI_IMC_SYMB_KEY_5 */
    T9KEYAMBIG6,    /* MMI_IMC_SYMB_KEY_6 */
    T9KEYAMBIG7,    /* MMI_IMC_SYMB_KEY_7 */
    T9KEYAMBIG8,    /* MMI_IMC_SYMB_KEY_8 */
    T9KEYAMBIG9,    /* MMI_IMC_SYMB_KEY_9 */
    T9KEYNONE,      /* MMI_IMC_SYMB_KEY_STAR */
    T9KEYNONE,      /* MMI_IMC_SYMB_KEY_POUND */
};

#ifdef __MMI_T9_THAI__
static const T9MINOR g_t9_keys_thai[MMI_IMC_SYMB_KEY_MAX - MMI_IMC_SYMB_KEY_BASE] = 
{
    T9KEYAMBIGA,
    T9KEYAMBIG1,
    T9KEYAMBIG2,
    T9KEYAMBIG3,
    T9KEYAMBIG4,
    T9KEYAMBIG5,
    T9KEYAMBIG6,
    T9KEYAMBIG7,
    T9KEYAMBIG8,
    T9KEYAMBIG9,
    T9KEYAMBIGB,
    T9KEYAMBIGC,
};
#endif /* __MMI_T9_THAI__ */ 

#ifdef __T9_CHINESE

static const T9MINOR g_t9_keys_chinese[MMI_IMC_SYMB_KEY_MAX - MMI_IMC_SYMB_KEY_BASE] = 
{
    T9KEYAMBIGB,    /* IME_SYMB_KEY_0 */

    T9KEYAMBIG1,    /* MMI_IMC_SYMB_KEY_1 */
    T9KEYAMBIG2,    /* MMI_IMC_SYMB_KEY_2 */
    T9KEYAMBIG3,    /* MMI_IMC_SYMB_KEY_3 */
    T9KEYAMBIG4,    /* MMI_IMC_SYMB_KEY_4 */
    T9KEYAMBIG5,    /* MMI_IMC_SYMB_KEY_5 */
    T9KEYAMBIG6,    /* MMI_IMC_SYMB_KEY_6 */
    T9KEYAMBIG7,    /* MMI_IMC_SYMB_KEY_7 */
    T9KEYAMBIG8,    /* MMI_IMC_SYMB_KEY_8 */
    T9KEYAMBIG9,    /* MMI_IMC_SYMB_KEY_9 */

    T9KEYAMBIGA,    /* MMI_IMC_SYMB_KEY_STAR */
    T9KEYAMBIGC,    /* MMI_IMC_SYMB_KEY_POUND */
};

static const mmi_imc_symb_stroke_enum g_t9_keys_stroke[MMI_IMC_SYMB_KEY_MAX - MMI_IMC_SYMB_KEY_BASE] = 
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

#endif /* __T9_CHINESE */ 

/* Symbol code mapping, for query */
static const T9MINOR g_t9_codes_tone[MMI_IMC_SYMB_TONE_MAX - MMI_IMC_SYMB_TONE_BASE] = 
{
    0,              /* MMI_IMC_SYMB_TONE_NONE */
    T9KEYAMBIG1,    /* MMI_IMC_SYMB_TONE_1 */
    T9KEYAMBIG2,    /* MMI_IMC_SYMB_TONE_2 */
    T9KEYAMBIG3,    /* MMI_IMC_SYMB_TONE_3 */
    T9KEYAMBIG4,    /* MMI_IMC_SYMB_TONE_4 */
    T9KEYAMBIG5     /* MMI_IMC_SYMB_TONE_5 */
};

#ifdef __T9_CHINESE

static const T9MINOR g_t9_codes_stroke[MMI_IMC_SYMB_STROKE_MAX - MMI_IMC_SYMB_STROKE_BASE] = 
{
    T9KEYAMBIG6,    /* MMI_IMC_SYMB_STROKE_WILDCARD, */
    T9KEYAMBIG2,    /* MMI_IMC_SYMB_STROKE_DOWN, */
    T9KEYAMBIG4,    /* MMI_IMC_SYMB_STROKE_DOT, */
    0,              /* MMI_IMC_SYMB_STROKE_CURVED_HOOK, */
    T9KEYAMBIG1,    /* MMI_IMC_SYMB_STROKE_OVER, */
    T9KEYAMBIG5,    /* MMI_IMC_SYMB_STROKE_OVER_DOWN, */
    0,              /* MMI_IMC_SYMB_STROKE_DOWN_OVER, */
    T9KEYAMBIG3,    /* MMI_IMC_SYMB_STROKE_LEFT, */
    0,              /* MMI_IMC_SYMB_STROKE_OVER_DOWN_OVER, */
    0,              /* MMI_IMC_SYMB_STROKE_MORE, */
    0,              /* MMI_IMC_SYMB_STROKE_TURN, */
    0,              /* MMI_IMC_SYMB_STROKE_DOT_OR_LEFT, */
};

static const UI_character_type g_t9_unicodes_stroke[MMI_IMC_SYMB_STROKE_MAX - MMI_IMC_SYMB_STROKE_BASE] = 
{
    0xF000, /* MMI_IMC_SYMB_STROKE_WILDCARD, */
    0xF001, /* MMI_IMC_SYMB_STROKE_DOWN, */
    0xF002, /* MMI_IMC_SYMB_STROKE_DOT, */
    0,      /* MMI_IMC_SYMB_STROKE_CURVED_HOOK, */
    0xF004, /* MMI_IMC_SYMB_STROKE_OVER, */
    0xF005, /* MMI_IMC_SYMB_STROKE_OVER_DOWN, */
    0,      /* MMI_IMC_SYMB_STROKE_DOWN_OVER, */
    0xF007, /* MMI_IMC_SYMB_STROKE_LEFT, */
    0,      /* MMI_IMC_SYMB_STROKE_OVER_DOWN_OVER, */
    0,      /* MMI_IMC_SYMB_STROKE_MORE, */
    0,      /* MMI_IMC_SYMB_STROKE_TURN, */
    0,      /* MMI_IMC_SYMB_STROKE_DOT_OR_LEFT, */
};

#endif /* __T9_CHINESE */ /* #ifdef __T9_CHINESE */

#ifdef __MMI_T9_SM_CHINESE__

/* T9 use pinyin unicode (a-z) to query, not internal symbol code */
static const T9U8 g_t9_codes_pinyin[MMI_IMC_SYMB_PY_MAX - MMI_IMC_SYMB_PY_BASE] = 
{
    'a',    /* MMI_IMC_SYMB_PY_A */
    'b',    /* MMI_IMC_SYMB_PY_B */
    'c',    /* MMI_IMC_SYMB_PY_C */

    'd',    /* MMI_IMC_SYMB_PY_D */
    'e',    /* MMI_IMC_SYMB_PY_E */
    'f',    /* MMI_IMC_SYMB_PY_F */

    'g',    /* MMI_IMC_SYMB_PY_G */
    'h',    /* MMI_IMC_SYMB_PY_H */
    'i',    /* MMI_IMC_SYMB_PY_I */

    'j',    /* MMI_IMC_SYMB_PY_J */
    'k',    /* MMI_IMC_SYMB_PY_K */
    'l',    /* MMI_IMC_SYMB_PY_L */

    'm',    /* MMI_IMC_SYMB_PY_M */
    'n',    /* MMI_IMC_SYMB_PY_N */
    'o',    /* MMI_IMC_SYMB_PY_O */

    'p',    /* MMI_IMC_SYMB_PY_P */
    'q',    /* MMI_IMC_SYMB_PY_Q */
    'r',    /* MMI_IMC_SYMB_PY_R */
    's',    /* MMI_IMC_SYMB_PY_S */

    't',    /* MMI_IMC_SYMB_PY_T */
    'u',    /* MMI_IMC_SYMB_PY_U */
    'v',    /* MMI_IMC_SYMB_PY_V */

    'w',    /* MMI_IMC_SYMB_PY_W */
    'x',    /* MMI_IMC_SYMB_PY_X */
    'y',    /* MMI_IMC_SYMB_PY_Y */
    'z'     /* MMI_IMC_SYMB_PY_Z */
};
#endif /* #ifdef __MMI_T9_SM_CHINESE__ */

#ifdef __MMI_T9_TR_CHINESE__

static const UI_character_type g_t9_unicodes_zhuyin[MMI_IMC_SYMB_ZY_MAX - MMI_IMC_SYMB_ZY_B] = 
{
    0x3105, /* MMI_IMC_SYMB_ZY_B */
    0x3106, /* MMI_IMC_SYMB_ZY_P */
    0x3107, /* MMI_IMC_SYMB_ZY_M */
    0x3108, /* MMI_IMC_SYMB_ZY_F */
    0x3109, /* MMI_IMC_SYMB_ZY_D */
    0x310A, /* MMI_IMC_SYMB_ZY_T */
    0x310B, /* MMI_IMC_SYMB_ZY_N */
    0x310C, /* MMI_IMC_SYMB_ZY_L */
    0x310D, /* MMI_IMC_SYMB_ZY_G */
    0x310E, /* MMI_IMC_SYMB_ZY_K */
    0x310F, /* MMI_IMC_SYMB_ZY_H */
    0x3110, /* MMI_IMC_SYMB_ZY_J */
    0x3111, /* MMI_IMC_SYMB_ZY_Q */
    0x3112, /* MMI_IMC_SYMB_ZY_X */
    0x3113, /* MMI_IMC_SYMB_ZY_ZH */
    0x3114, /* MMI_IMC_SYMB_ZY_CH */
    0x3115, /* MMI_IMC_SYMB_ZY_SH */
    0x3116, /* MMI_IMC_SYMB_ZY_R */
    0x3117, /* MMI_IMC_SYMB_ZY_Z */
    0x3118, /* MMI_IMC_SYMB_ZY_C */
    0x3119, /* MMI_IMC_SYMB_ZY_S */
    0x311A, /* MMI_IMC_SYMB_ZY_A */
    0x311B, /* MMI_IMC_SYMB_ZY_O */
    0x311C, /* MMI_IMC_SYMB_ZY_E */
    0x311D, /* MMI_IMC_SYMB_ZY_EH */
    0x311E, /* MMI_IMC_SYMB_ZY_AI */
    0x311F, /* MMI_IMC_SYMB_ZY_EI */
    0x3120, /* MMI_IMC_SYMB_ZY_AU */
    0x3121, /* MMI_IMC_SYMB_ZY_OU */
    0x3122, /* MMI_IMC_SYMB_ZY_AN */
    0x3123, /* MMI_IMC_SYMB_ZY_EN */
    0x3124, /* MMI_IMC_SYMB_ZY_ANG */
    0x3125, /* MMI_IMC_SYMB_ZY_ENG */
    0x3126, /* MMI_IMC_SYMB_ZY_ER */
    0x3127, /* MMI_IMC_SYMB_ZY_I */
    0x3128, /* MMI_IMC_SYMB_ZY_U */
    0x3129  /* MMI_IMC_SYMB_ZY_IU */
};

static const T9U8 g_t9_codes_zhuyin[MMI_IMC_SYMB_ZY_MAX - MMI_IMC_SYMB_ZY_B] = 
{
    'b',    /* MMI_IMC_SYMB_ZY_B */
    'p',    /* MMI_IMC_SYMB_ZY_P */
    'm',    /* MMI_IMC_SYMB_ZY_M */
    'f',    /* MMI_IMC_SYMB_ZY_F */
    'd',    /* MMI_IMC_SYMB_ZY_D */
    't',    /* MMI_IMC_SYMB_ZY_T */
    'n',    /* MMI_IMC_SYMB_ZY_N */
    'l',    /* MMI_IMC_SYMB_ZY_L */
    'g',    /* MMI_IMC_SYMB_ZY_G */
    'k',    /* MMI_IMC_SYMB_ZY_K */
    'h',    /* MMI_IMC_SYMB_ZY_H */
    'j',    /* MMI_IMC_SYMB_ZY_J */
    'q',    /* MMI_IMC_SYMB_ZY_Q */
    'x',    /* MMI_IMC_SYMB_ZY_X */
    0xdf,   /* MMI_IMC_SYMB_ZY_ZH */
    0xe7,   /* MMI_IMC_SYMB_ZY_CH */
    0x9a,   /* MMI_IMC_SYMB_ZY_SH */
    'r',    /* MMI_IMC_SYMB_ZY_R */
    'z',    /* MMI_IMC_SYMB_ZY_Z */
    'c',    /* MMI_IMC_SYMB_ZY_C */
    's',    /* MMI_IMC_SYMB_ZY_S */
    'a',    /* MMI_IMC_SYMB_ZY_A */
    'o',    /* MMI_IMC_SYMB_ZY_O */
    'e',    /* MMI_IMC_SYMB_ZY_E */
    0xe9,   /* MMI_IMC_SYMB_ZY_EH */
    0xe4,   /* MMI_IMC_SYMB_ZY_AI */
    0xf6,   /* MMI_IMC_SYMB_ZY_EI */
    0xe5,   /* MMI_IMC_SYMB_ZY_AU */
    0xfd,   /* MMI_IMC_SYMB_ZY_OU */
    0xe3,   /* MMI_IMC_SYMB_ZY_AN */
    0xf5,   /* MMI_IMC_SYMB_ZY_EN */
    0xe2,   /* MMI_IMC_SYMB_ZY_ANG */
    0xf4,   /* MMI_IMC_SYMB_ZY_ENG */
    0xf8,   /* MMI_IMC_SYMB_ZY_ER */
    'i',    /* MMI_IMC_SYMB_ZY_I */
    'u',    /* MMI_IMC_SYMB_ZY_U */
    0xfc    /* MMI_IMC_SYMB_ZY_IU */
};
#endif /* #ifdef __MMI_T9_TR_CHINESE__ */

static const mmi_ime_t9_mode_info_struct g_mode_infos[] = 
{
#if defined(__MMI_T9_ENGLISH__)
    {   
        INPUT_MODE_MULTITAP_UPPERCASE_ABC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDEnglish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        INPUT_MODE_MULTITAP_LOWERCASE_ABC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDEnglish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        INPUT_MODE_SMART_UPPERCASE_ABC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDEnglish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        INPUT_MODE_SMART_LOWERCASE_ABC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDEnglish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic,
    },
#endif /* #if defined(__MMI_T9_ENGLISH__) */

#if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
    {   
        INPUT_MODE_TR_MULTITAP_BOPOMO,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        T9PIDChinese | T9SIDChineseTraditional,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        mmi_ime_t9_get_spellings_zhuyin_multitap,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_zhuyin
    },
#endif /* #if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */
  
#if (defined(__MMI_T9_SMART_PHONETIC_INPUT__) && defined(__MMI_T9_AMB_BPMF_INPUT__))
    {   
        INPUT_MODE_TR_BOPOMO,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        T9PIDChinese | T9SIDChineseTraditional,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS,
        mmi_ime_t9_get_spellings_zhuyin_smart,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_zhuyin
    },
#endif /* #if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__) */    
  
#if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)
    {
        INPUT_MODE_MULTITAP_PINYIN,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        T9PIDChinese | T9SIDChineseSimplified,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_1),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_1) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_pinyin_multitap,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_pinyin
    },
#endif /* #if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */

#if defined(__MMI_T9_TR_CHINESE__)
    {
        INPUT_MODE_TR_STROKE, 
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_STROKE,
        T9PIDChinese | T9SIDChineseTraditional,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_stroke,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_stroke
    },
#endif /* #if defined(__MMI_T9_TR_CHINESE__) */
    
#if defined (__MMI_LANG_SM_CHINESE__)

#if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__)
    {
        INPUT_MODE_SM_PINYIN,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_PHONETIC,
        T9PIDChinese | T9SIDChineseSimplified,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_1),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_1) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_pinyin_smart,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_pinyin
    },
#endif /* #if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__) */
   #endif
    
#if defined(__MMI_T9_SM_CHINESE__)
    {
        INPUT_MODE_SM_STROKE,
        g_t9_keys_chinese,
        MMI_IME_T9_INIT_TYPE_STROKE,
        T9PIDChinese | T9SIDChineseSimplified,
        MMI_IME_REQUIRED_ALL_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_7) & (~MMI_IME_REQUIRED_KEY_8) & (~MMI_IME_REQUIRED_KEY_9) & (~MMI_IME_REQUIRED_KEY_0),
        mmi_ime_t9_get_spellings_stroke,
        mmi_ime_t9_get_associates,
        mmi_ime_t9_get_candidates_stroke
    },
#endif /* #if defined(__MMI_T9_TR_CHINESE__) */

#if defined(__MMI_T9_ARABIC__)
    {   
        INPUT_MODE_SMART_ARABIC,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDArabic,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_ARABIC__) */

#if defined(__MMI_T9_HEBREW__)
    {   
        INPUT_MODE_SMART_HEBREW,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHebrew,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_HEBREW__) */

#if defined(__MMI_T9_FRENCH__)
     {   
         INPUT_MODE_SMART_UPPERCASE_FRENCH,
         g_t9_keys_alphabetic,
         MMI_IME_T9_INIT_TYPE_ALPHABETIC,
         T9PIDFrench,
         MMI_IME_REQUIRED_ALL_KEYS,
         MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
         NULL,
         NULL,
         mmi_ime_t9_get_candidates_alphabetic
     },
     {   
         INPUT_MODE_SMART_LOWERCASE_FRENCH,
         g_t9_keys_alphabetic,
         MMI_IME_T9_INIT_TYPE_ALPHABETIC,
         T9PIDFrench,
         MMI_IME_REQUIRED_ALL_KEYS,
         MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
         NULL,
         NULL,
         mmi_ime_t9_get_candidates_alphabetic
     },
#endif /* #if defined(__MMI_T9_FRENCH__) */

#if defined(__MMI_T9_GERMAN__)
     {   
         INPUT_MODE_SMART_UPPERCASE_GERMAN,
         g_t9_keys_alphabetic,
         MMI_IME_T9_INIT_TYPE_ALPHABETIC,
         T9PIDGerman,
         MMI_IME_REQUIRED_ALL_KEYS,
         MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
         NULL,
         NULL,
         mmi_ime_t9_get_candidates_alphabetic
     },
     {   
         INPUT_MODE_SMART_LOWERCASE_GERMAN,
         g_t9_keys_alphabetic,
         MMI_IME_T9_INIT_TYPE_ALPHABETIC,
         T9PIDGerman,
         MMI_IME_REQUIRED_ALL_KEYS,
         MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
         NULL,
         NULL,
         mmi_ime_t9_get_candidates_alphabetic
     },
#endif /* #if defined(__MMI_T9_GERMAN__) */

#if defined(__MMI_T9_HINDI__)
    {   
        INPUT_MODE_SMART_HINDI,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDHindi,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_HINDI__) */


#if defined(__MMI_T9_INDONESIAN__)
    {   
        INPUT_MODE_SMART_UPPERCASE_INDONESIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIndonesian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        INPUT_MODE_SMART_LOWERCASE_INDONESIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDIndonesian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_INDONESIAN__) */

#if defined(__MMI_T9_ITALIAN__)
    {   
        INPUT_MODE_SMART_UPPERCASE_ITALIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDItalian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        INPUT_MODE_SMART_LOWERCASE_ITALIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDItalian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_ITALIAN__) */

#if defined(__MMI_T9_MALAY__)
    {   
        INPUT_MODE_SMART_UPPERCASE_MALAY,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMalay,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        INPUT_MODE_SMART_LOWERCASE_MALAY,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDMalay,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_MALAY__) */


#if defined(__MMI_T9_POLISH__)
    {   
        INPUT_MODE_SMART_UPPERCASE_POLISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPolish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        INPUT_MODE_SMART_LOWERCASE_POLISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPolish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_POLISH__) */

#if defined(__MMI_T9_PORTUGUESE__)
    {   
        INPUT_MODE_SMART_UPPERCASE_PORTUGUESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPortuguese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        INPUT_MODE_SMART_LOWERCASE_PORTUGUESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDPortuguese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_PORTUGUESE__) */

#if defined(__MMI_T9_ROMANIAN__)
    {   
        INPUT_MODE_SMART_UPPERCASE_ROMANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDRomanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        INPUT_MODE_SMART_LOWERCASE_ROMANIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDRomanian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_ROMANIAN__) */

#if defined(__MMI_T9_RUSSIAN__)
    {   
        INPUT_MODE_SMART_UPPERCASE_RUSSIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDRussian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        INPUT_MODE_SMART_LOWERCASE_RUSSIAN,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDRussian,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_RUSSIAN__) */

#if defined(__MMI_T9_SLOVAK__)
    {   
        INPUT_MODE_SMART_UPPERCASE_SLOVAK,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSlovak,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        INPUT_MODE_SMART_LOWERCASE_SLOVAK,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSlovak,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_SLOVAK__) */



#if defined(__MMI_T9_SPANISH__)
    {   
        INPUT_MODE_SMART_UPPERCASE_SPANISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSpanish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        INPUT_MODE_SMART_LOWERCASE_SPANISH,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDSpanish,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_SPANISH__) */



#if defined(__MMI_T9_VIETNAMESE__)
    {   
        INPUT_MODE_SMART_UPPERCASE_VIETNAMESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDVietnamese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
    {   
        INPUT_MODE_SMART_LOWERCASE_VIETNAMESE,
        g_t9_keys_alphabetic,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDVietnamese,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_NUM_KEYS & (~MMI_IME_REQUIRED_KEY_0),
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_VIETNAMESE__) */

#if defined(__MMI_T9_THAI__)
    {   
        INPUT_MODE_SMART_THAI,
        g_t9_keys_thai,
        MMI_IME_T9_INIT_TYPE_ALPHABETIC,
        T9PIDThai,
        MMI_IME_REQUIRED_ALL_KEYS,
        MMI_IME_REQUIRED_ALL_KEYS,
        NULL,
        NULL,
        mmi_ime_t9_get_candidates_alphabetic
    },
#endif /* #if defined(__MMI_T9_THAI__) */

    {
        INPUT_MODE_MAX_NUM,
        NULL,
        MMI_IME_T9_INIT_TYPE_MAX,
        0xFFFF,
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

static mmi_ime_t9_word_engine_struct g_engine;


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_toupper
 * DESCRIPTION
 *  Convert character to uppercase.
 * PARAMETERS
 *  wc      [IN]        Character to convert.
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

    if ((wc >= 0x0061 && wc <= 0x007A) ||   /* Latin basic */
        (wc >= 0x00E0 && wc <= 0x00F6) || (wc >= 0x00F8 && wc <= 0x00FE) ||     /* Latin-1 */
        (wc >= 0x0430 && wc <= 0x044F) ||   /* Cyrillic */
        (wc >= 0x03B1 && wc <= 0x03C1) || (wc >= 0x03C3 && wc <= 0x03CA))       /* Greek */
    {
        return (wc - 0x0020);
    }
    else if (wc == 0x0103 ||    /* Latin extend-A */
             wc == 0x01A1 || wc == 0x01B0 || wc == 0x0188 || wc == 0x018C ||    /* Latin extend-B */
             wc == 0x0192 || wc == 0x01AC || wc == 0x01B9 || wc == 0x01F3)      /* Latin extend-B */
    {
        return (wc - 0x0001);
    }
    else if (wc >= 0x0450 && wc <= 0x045f)  /* Cyrillic */
    {
        return (wc - 0x50);
    }
    else if (wc == 0x0491)  /* Cyrillic */
    {
        return 0x0490;
    }
    else if (wc >= 0x0100 && wc <= 0x0137 || wc >= 0x014A && wc <= 0x0177 ||    /* Latin extend-A */
             wc >= 0x0182 && wc <= 0x0185 || wc >= 0x0198 && wc <= 0x01A5 ||    /* Latin extend-B */
             wc >= 0x01DE && wc <= 0x01EF || wc >= 0x01F8 && wc <= 0x01FF ||    /* Latin extend-B */
             wc >= 0x0222 && wc <= 0x0233)  /* Latin extend-B */
    {
        if ((wc & 1) == 1)  /* odd is small case */
            return wc - 1;
        else
            return wc;
    }
    else if (wc >= 0x0139 && wc <= 0x0148 ||    /* Latin extend-A */
             wc >= 0x0179 && wc <= 0x017E || wc >= 0x01B3 && wc <= 0x01B6 ||    /* Latin extend-B */
             wc >= 0x01CD && wc <= 0x01DC)      /* Latin extend-B */
    {
        if ((wc & 1) == 0)  /* even is small case */
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
 *  wc      [IN]        Character to convert.
 * RETURNS
 *  Each of these routines converts a copy of wc, if possible, and returns the
 *  result.
 *****************************************************************************/
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

    if ((wc >= 0x0041 && wc <= 0x005A) ||   /* Latin basic */
        (wc >= 0x00C0 && wc <= 0x00D6) || (wc >= 0x00D8 && wc <= 0x00DE) ||     /* Latin-1 */
        (wc >= 0x0410 && wc <= 0x042F) ||   /* Cyrillic */
        (wc >= 0x0391 && wc <= 0x03A1) || (wc >= 0x03A3 && wc <= 0x03AA))       /* Greek */
    {
        return (wc + 0x0020);
    }
    else if (wc == 0x0102 ||    /* Latin extend-A */
             wc == 0x01A0 || wc == 0x01AF || wc == 0x0187 || wc == 0x018B ||    /* Latin extend-B */
             wc == 0x0191 || wc == 0x01AB || wc == 0x01B8 || wc == 0x01F2)      /* Latin extend-B */
    {
        return (wc + 0x0001);
    }
    else if (wc >= 0x0400 && wc <= 0x040F)  /* Cyrillic */
    {
        return (wc + 0x50);
    }
    else if (wc == 0x0490)  /* Cyrillic */
    {
        return 0x0491;
    }
    else if (wc >= 0x0100 && wc <= 0x0137 || wc >= 0x014A && wc <= 0x0177 ||    /* Latin extend-A */
             wc >= 0x0182 && wc <= 0x0185 || wc >= 0x0198 && wc <= 0x01A5 ||    /* Latin extend-B */
             wc >= 0x01DE && wc <= 0x01EF || wc >= 0x01F8 && wc <= 0x01FF ||    /* Latin extend-B */
             wc >= 0x0222 && wc <= 0x0233)  /* Latin extend-B */
    {
        if ((wc & 0x0001) == 0) /* odd is small case */
            return wc + 1;
        else
            return wc;
    }
    else if (wc >= 0x0139 && wc <= 0x0148 ||    /* Latin extend-A */
             wc >= 0x0179 && wc <= 0x017E || wc >= 0x01B3 && wc <= 0x01B6 ||    /* Latin extend-B */
             wc >= 0x01CD && wc <= 0x01DC)      /* Latin extend-B */
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
 *  Initialize word engine object
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_engine.is_inited)
        return MMI_TRUE;

    memset(&g_engine, 0x0, sizeof(mmi_ime_t9_word_engine_struct));

    g_engine.is_inited = MMI_TRUE;
    g_engine.input_mode = INPUT_MODE_MAX_NUM;
#if defined(__MMI_IME_USER_DATABASE__)

    g_engine.is_inited = mmi_ime_word_load_user_database();
#endif

#ifdef __MMI_T9_MULTITAP__
    g_engine.is_inited = mmi_ime_multitap_init();
    MMI_ASSERT(g_engine.is_inited);
#endif
    return g_engine.is_inited;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_deinit
 * DESCRIPTION
 *  
 *  Denitialize word engine object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_word_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&g_engine, 0x0, sizeof(mmi_ime_t9_word_engine_struct));
    g_engine.input_mode = INPUT_MODE_MAX_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_leave_current_mode
 * DESCRIPTION
 *  Set current mode as Null
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_word_leave_current_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_engine.t9_mode_info = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_change_mode
 * DESCRIPTION
 *  Set Next Mode in engine
 * PARAMETERS
 *  mode_details_ptr        [IN]        
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_change_mode(const mmi_ime_mode_details_struct *mode_details_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL ret_val = MMI_FALSE;
    mmi_ime_t9_mode_info_struct_p mode_info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_engine.is_inited == MMI_FALSE)
        return MMI_FALSE;

    mode_info_ptr = mmi_ime_t9_get_mode_info(mmi_imm_get_current_input_mode());

    g_engine.t9_mode_info = NULL;

    if (NULL == mode_info_ptr)
        return MMI_FALSE;

    g_engine.t9_mode_info = mode_info_ptr;

    switch (mode_info_ptr->init_type)
    {
        case MMI_IME_T9_INIT_TYPE_ALPHABETIC:
            ret_val = mmi_ime_t9_init_alphabetic(mode_info_ptr, (mmi_ime_mode_details_struct*) mode_details_ptr);
            break;
    #ifdef __T9_CHINESE
        case MMI_IME_T9_INIT_TYPE_PHONETIC:
            ret_val = mmi_ime_t9_init_phonetic_chn(mode_info_ptr, (mmi_ime_mode_details_struct*) mode_details_ptr);
            break;

        case MMI_IME_T9_INIT_TYPE_STROKE:
            ret_val = mmi_ime_t9_init_stroke_chn(mode_info_ptr, (mmi_ime_mode_details_struct*) mode_details_ptr);
            break;
    #endif /* __T9_CHINESE */ 
        case MMI_IME_T9_INIT_TYPE_DIRECT:
            ret_val = mmi_ime_t9_init_number(mode_info_ptr, (mmi_ime_mode_details_struct*) mode_details_ptr);
            break;

        default:
            ret_val = MMI_FALSE;
            break;
    }

    if ((mode_details_ptr->flags & MMI_IME_UPPERCASE))
    {
        g_engine.case_type = MMI_IME_WORD_CASE_UPPER;
    }
    else if (mode_details_ptr->flags & MMI_IME_LOWERCASE)
    {
        g_engine.case_type = MMI_IME_WORD_CASE_LOWER;
    }
    else
    {
        g_engine.case_type = MMI_IME_WORD_CASE_DEFAULT;
    }

    if (ret_val == MMI_FALSE)
    {
        return MMI_FALSE;
    }

    g_engine.key_map_ptr = mode_info_ptr->key_map_ptr;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_get_spellings
 * DESCRIPTION
 *  Get Compositions
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_ime_word_get_spellings(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result_ptr->result_cnt = 0;

    if (g_engine.t9_mode_info)
    {
        if (NULL != g_engine.t9_mode_info->get_spell_funcptr)
        {
            g_engine.t9_mode_info->get_spell_funcptr(param_ptr, result_ptr);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_get_associates
 * DESCRIPTION
 *  Get Associates
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_ime_word_get_associates(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result_ptr->result_cnt = 0;

    if (g_engine.t9_mode_info)
    {
        if (NULL != g_engine.t9_mode_info->get_assoc_funcptr)
        {
            g_engine.t9_mode_info->get_assoc_funcptr(param_ptr, result_ptr);
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_get_candidates
 * DESCRIPTION
 *  Get Candidates
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_word_get_candidates(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    result_ptr->result_cnt = 0;

    if (g_engine.t9_mode_info)
    {
        if (NULL != g_engine.t9_mode_info->get_cand_funcptr)
        {
            g_engine.t9_mode_info->get_cand_funcptr(param_ptr, result_ptr);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_symbol_to_code
 * DESCRIPTION
 * PARAMETERS
 *  symbol      [IN]        
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
                return 0x002D;
            case MMI_IMC_SYMB_TONE_2:
                return 0x02CA;
            case MMI_IMC_SYMB_TONE_3:
                return 0x02C7;
            case MMI_IMC_SYMB_TONE_4:
                return 0x02CB;
            case MMI_IMC_SYMB_TONE_5:
                return 0x02D9;
            default:
                return 0;
        }
    }
#if defined __T9_CHINESE
    else if (MMI_IMC_IS_SYMB_STROKE(symbol))
    {
        return g_t9_unicodes_stroke[symbol - MMI_IMC_SYMB_STROKE_BASE];
    }
#endif /* defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */ 
#if defined(__MMI_T9_SM_CHINESE__)
    else if (MMI_IMC_IS_SYMB_PY(symbol))
    {
        return g_t9_codes_pinyin[symbol - MMI_IMC_SYMB_PY_BASE];
    }
#endif /* #if defined(__MMI_T9_SM_CHINESE__) */
#if defined(__MMI_T9_TR_CHINESE__)
    else if (MMI_IMC_IS_SYMB_ZY(symbol))
    {
        return g_t9_unicodes_zhuyin[symbol - MMI_IMC_SYMB_ZY_BASE];
    }
#endif /* #if defined(__MMI_T9_TR_CHINESE__) */
    else
    {
        return 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_code_to_symbol
 * DESCRIPTION
 * PARAMETERS
 *  code        [IN]        
 * RETURNS
 *****************************************************************************/
U16 mmi_ime_word_code_to_symbol(UI_character_type code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (code)
    {
#if defined __T9_CHINESE
        case 0xF000:
            return MMI_IMC_SYMB_STROKE_WILDCARD;

        case 0xF001:
            return MMI_IMC_SYMB_STROKE_DOWN;

        case 0xF002:
            return MMI_IMC_SYMB_STROKE_DOT;

        case 0xF004:
            return MMI_IMC_SYMB_STROKE_OVER;

        case 0xF005:
            return MMI_IMC_SYMB_STROKE_OVER_DOWN;

        case 0xF007:
            return MMI_IMC_SYMB_STROKE_LEFT;
#endif /* #if defined(__MMI_ZI_SM_CHINESE__) || defined(__MMI_ZI_TR_CHINESE__)   */        

        default:
    #ifdef __MMI_T9_SM_CHINESE__
            if (code >= 'a' && code <= 'z')
            {
                return code - 'a' + MMI_IMC_SYMB_PY_A;
            }
            else
    #endif /* __MMI_T9_SM_CHINESE__ */ 
        #ifdef __MMI_T9_TR_CHINESE__
            if (code >= 0x3105 && code <= 0x3129)
            {
                return code - 0x3105 + MMI_IMC_SYMB_ZY_B;
            }
        #endif /* __MMI_T9_TR_CHINESE__ */ 
            break;
    }

    return 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_add_separator_to_candidate_buffer
 * DESCRIPTION
 * PARAMETERS
 *  destination_buffer      [OUT]         
 *  source_buffer           [IN]         
 *  num                     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_word_add_separator_to_candidate_buffer(UI_character_type *destination_buffer, UI_character_type *source_buffer, S32 num)
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
        destination_buffer[j + 1] = 0;  /* Default separator is '\0' */
        i++;
        j += 2;
    }

    destination_buffer[j] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_is_valid_key
 * DESCRIPTION
 * PARAMETERS
 *  input_mode      [IN]        
 *  key_code        [IN]        
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_is_valid_key(S32 input_mode, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_t9_mode_info_struct_p mode_info_p;
    U32 required_key;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_info_p = mmi_ime_t9_get_mode_info(input_mode);

    if (mode_info_p == NULL)
        return MMI_FALSE;

    required_key = mode_info_p->required_keys;

    switch (key_code)
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
 *  mmi_ime_word_is_symbol_key
 * DESCRIPTION
 * PARAMETERS
 *  input_mode      [IN]        
 *  key_code        [IN]        
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_is_symbol_key(S32 input_mode, mmi_imc_key_custom_value key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (key_code)
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
            if (g_engine.t9_mode_info->symbol_keys & (MMI_IME_REQUIRED_KEY_0 << (key_code - MMI_IMC_KEY_SYM_0)))
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        case MMI_IMC_KEY_SYM_STAR:
            if (g_engine.t9_mode_info->symbol_keys & MMI_IME_REQUIRED_KEY_STAR)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        case MMI_IMC_KEY_SYM_POUND:
            if (g_engine.t9_mode_info->symbol_keys & MMI_IME_REQUIRED_KEY_POUND)
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
 *  mmi_ime_word_engine_get_char_info
 * DESCRIPTION
 * PARAMETERS
 *  code            [IN]        
 *  info_buffer     [IN]        
 *  buffer_size     [IN]        
 *  mode            [IN]        
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_engine_init_char_info( S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_t9_mode_info_struct_p mode_info_ptr;
    mmi_ime_mode_details_struct *mode_details_ptr;
    MMI_BOOL ret_val = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mode_details_ptr = (mmi_ime_mode_details_struct*) mmi_imm_get_desired_input_mode_array_item(mode);

    switch (mode)
    {
        case INPUT_MODE_SM_PINYIN:
        case INPUT_MODE_MULTITAP_PINYIN:
        case INPUT_MODE_SM_STROKE:
        case INPUT_MODE_TR_BOPOMO:
        case INPUT_MODE_TR_STROKE:
        case INPUT_MODE_TR_MULTITAP_BOPOMO:
            mode_info_ptr = mmi_ime_t9_get_mode_info(mode);
            break;
        default:
            return ;
            break;
    }

    MMI_ASSERT(mode_info_ptr != NULL);

    switch (mode_info_ptr->init_type)
    {
        case MMI_IME_T9_INIT_TYPE_ALPHABETIC:
            ret_val = mmi_ime_t9_init_alphabetic(mode_info_ptr, mode_details_ptr);
            break;
        #ifdef __T9_CHINESE
        case MMI_IME_T9_INIT_TYPE_PHONETIC:
            ret_val = mmi_ime_t9_init_phonetic_chn(mode_info_ptr, mode_details_ptr);
            break;

        case MMI_IME_T9_INIT_TYPE_STROKE:
            ret_val = mmi_ime_t9_init_stroke_chn(mode_info_ptr, mode_details_ptr);
            break;
#endif        
        case MMI_IME_T9_INIT_TYPE_DIRECT:
            ret_val = mmi_ime_t9_init_number(mode_info_ptr, mode_details_ptr);
            break;
        
        default:
            ret_val = MMI_FALSE;
            break;
    }

    MMI_ASSERT(ret_val);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_engine_get_char_info
 * DESCRIPTION
 * PARAMETERS
 *  code            [IN]        
 *  info_buffer     [IN]        
 *  buffer_size     [IN]        
 *  mode            [IN]        
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_engine_get_char_info(UI_character_type code, UI_string_type info_buffer, S32 buffer_size, S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type temp_string[2];
    T9STATUS sStatus;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    temp_string[0] = code;
    temp_string[1] = 0;

    switch (mode)
    {
     #ifdef __T9_CHINESE
        case INPUT_MODE_TR_MULTITAP_BOPOMO:
        case INPUT_MODE_TR_BOPOMO:
        case INPUT_MODE_MULTITAP_PINYIN:
        case INPUT_MODE_SM_PINYIN:
            sStatus = T9CCGetCharSpell(&g_engine.data.field_info.CCFieldInfo, temp_string, 0);
            break;
        case INPUT_MODE_SM_STROKE:
        case INPUT_MODE_TR_STROKE:
            sStatus = T9CCGetCharStrokes(&g_engine.data.field_info.CCFieldInfo, temp_string, 0);
            break;
    #endif /* __T9_CHINESE */ 
        default:
            return MMI_FALSE;
            break;
    }

#ifdef __T9_CHINESE
    if (sStatus == T9STATNONE)
    {
        while (g_engine.data.field_info.CCFieldInfo.pbSpellBuf[i])
        {
            info_buffer[i] = mmi_ime_t9_t9code_to_code(g_engine.data.field_info.CCFieldInfo.pbSpellBuf[i], mode);
            i++;
        }
        info_buffer[i] = 0;
    }
#endif /* __T9_CHINESE */ 

    if (sStatus == T9STATNONE)
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
 *  mmi_ime_word_is_redicals
 * DESCRIPTION
 * PARAMETERS
 *  key_code        [IN]        
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_is_redicals(UI_character_type key_code)
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
 *  code        [IN]        
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
 *  mmi_ime_t9_t9code_to_code
 * DESCRIPTION
 * PARAMETERS
 *  t9code      [IN]        
 *  mode        [IN]        
 * RETURNS
 *****************************************************************************/
static UI_character_type mmi_ime_t9_t9code_to_code(T9U8 t9code, S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mode)
    {
    #if defined (__MMI_LANG_SM_CHINESE__)
        case INPUT_MODE_MULTITAP_PINYIN:
        case INPUT_MODE_SM_PINYIN:
            return (UI_character_type) t9code;
            break;
    #endif /* defined (__MMI_LANG_SM_CHINESE__) */ 
    #ifdef __MMI_T9_TR_CHINESE__

        case INPUT_MODE_TR_MULTITAP_BOPOMO:
    #if (defined(__MMI_T9_SMART_PHONETIC_INPUT__) && defined(__MMI_T9_AMB_BPMF_INPUT__))
        case INPUT_MODE_TR_BOPOMO:
    #endif /* (defined(__MMI_T9_SMART_PHONETIC_INPUT__) && defined(__MMI_T9_AMB_BPMF_INPUT__)) */ 
            while (i < MMI_IMC_SYMB_ZY_MAX - MMI_IMC_SYMB_ZY_BASE)
            {
                if (g_t9_codes_zhuyin[i] == t9code)
                    break;
                i++;
            }

            if (g_t9_codes_zhuyin[i] == t9code)
            {
                return g_t9_unicodes_zhuyin[i];
            }
            else
            {
                return 0;
            }
            break;
    #endif /* __MMI_T9_TR_CHINESE__ */ 

        #ifdef __T9_CHINESE
        #if defined   (__MMI_LANG_TR_CHINESE__)
        case INPUT_MODE_TR_STROKE:
        #endif /* defined   (__MMI_LANG_TR_CHINESE__) */ 
        case INPUT_MODE_SM_STROKE:

            while (i < MMI_IMC_SYMB_STROKE_MAX - MMI_IMC_SYMB_STROKE_BASE)
            {
                if (g_t9_codes_stroke[i] == t9code)
                    break;
                i++;
            }

            if (g_t9_codes_stroke[i] == t9code)
            {
                return g_t9_unicodes_stroke[i];
            }
            else
            {
                return 0;
            }
            break;
        #endif /* __T9_CHINESE */ 

        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_mode_info
 * DESCRIPTION
 * PARAMETERS
 *  input_mode      [IN]        
 * RETURNS
 *****************************************************************************/
static mmi_ime_t9_mode_info_struct_p mmi_ime_t9_get_mode_info(S32 input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input_mode >= INPUT_MODE_MAX_NUM)
        return NULL;

    for (i = 0; g_mode_infos[i].input_mode != INPUT_MODE_MAX_NUM; ++i)
    {
        if (g_mode_infos[i].input_mode == input_mode)
            return (mmi_ime_t9_mode_info_struct_p) & g_mode_infos[i];
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_init_number
 * DESCRIPTION
 * PARAMETERS
 *  t9_mode_info        [IN]        
 *  mode_detail_ptr     [IN]         
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_ime_t9_init_number(mmi_ime_t9_mode_info_struct_p t9_mode_info, mmi_ime_mode_details_struct *mode_detail_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy function */

    return MMI_TRUE;
}

#ifdef __T9_CHINESE


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_init_stroke_chn
 * DESCRIPTION
 * PARAMETERS
 *  t9_mode_info        [IN]        
 *  mode_detail_ptr     [?]         
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_ime_t9_init_stroke_chn(mmi_ime_t9_mode_info_struct_p t9_mode_info, mmi_ime_mode_details_struct *mode_detail_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    T9STATUS sStatus;

    T9CCFieldInfo *pCCFieldInfo;
    mmi_ime_t9_data_struct_p pDataBuff;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sStatus = T9STATNONE;


    pDataBuff = &g_engine.data;
    pCCFieldInfo = &g_engine.data.field_info.CCFieldInfo;

    memset(pCCFieldInfo, 0, sizeof(T9CCFieldInfo));
#if defined __MMI_T9_V7_4__
    sStatus = T9CCInitialize( pCCFieldInfo, pDataBuff->text_buff, pDataBuff->aux_buff, MMI_IME_T9_MAX_TEXT_BUFFSIZE, 0,
                (T9HandleRequest_f)T9_handle_request, T9CCSELECTPAGEMAXSIZE, (T9CCLoadLdb_f)T9CCLoadLdb );
#else
    sStatus = T9CCInitialize(
                pCCFieldInfo,
                pDataBuff->text_buff,
                pDataBuff->aux_buff,
                MMI_IME_T9_MAX_TEXT_BUFFSIZE,
                0,
                (T9HandleRequest_f) T9_handle_request,
                MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE,
                (T9CCLoadLdb_f) T9LoadChnLdb);
#endif
    if (sStatus == T9STATNONE)
    {
        sStatus = T9CCSetLanguage(pCCFieldInfo, t9_mode_info->nLdbNum, NULL, NULL);
    }

    if (sStatus == T9STATNONE)
    {
        sStatus = T9CCSetDynCtxtFence(pCCFieldInfo, MMI_IME_DYNAMIC_CONTEXT_FENCE);
    }
    if (sStatus == T9STATNONE)
    {
        sStatus = T9CCSetDynCtxtSearchDepth(pCCFieldInfo, MMI_IME_DYNAMIC_CONTEXT_SEARCH_DEPTH);
    }
    if (sStatus == T9STATNONE)
    {
        sStatus = T9CCSetStrokeMode(pCCFieldInfo);
    }

    if (sStatus == T9STATNONE)
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
 *  mmi_ime_t9_init_phonetic_chn
 * DESCRIPTION
 * PARAMETERS
 *  t9_mode_info        [IN]        
 *  mode_detail_ptr     [IN]         
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_ime_t9_init_phonetic_chn( mmi_ime_t9_mode_info_struct_p t9_mode_info, mmi_ime_mode_details_struct *mode_detail_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    T9STATUS sStatus;

    T9CCFieldInfo *pCCFieldInfo;
    mmi_ime_t9_data_struct_p pDataBuff;
    mmi_ime_mode_details_struct *mode_details_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mode_details_ptr = (mmi_ime_mode_details_struct*) mmi_imm_get_input_mode_array_item();
    sStatus = T9STATNONE;

    pDataBuff = &g_engine.data;
    pCCFieldInfo = &g_engine.data.field_info.CCFieldInfo;
    
    memset(pCCFieldInfo, 0, sizeof(T9CCFieldInfo));
#if defined __MMI_T9_V7_4__
    sStatus = T9CCInitialize( pCCFieldInfo, pDataBuff->text_buff, pDataBuff->aux_buff, MMI_IME_T9_MAX_TEXT_BUFFSIZE, 0,
                    (T9HandleRequest_f)T9_handle_request, T9CCSELECTPAGEMAXSIZE, (T9CCLoadLdb_f)T9CCLoadLdb );
#else

    sStatus = T9CCInitialize(
                pCCFieldInfo,
                pDataBuff->text_buff,
                pDataBuff->aux_buff,
                MMI_IME_T9_MAX_TEXT_BUFFSIZE,
                0,
                (T9HandleRequest_f) T9_handle_request,
                MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE,
                (T9CCLoadLdb_f) T9LoadChnLdb);
#endif
    if (sStatus == T9STATNONE)
    {
        sStatus = T9CCSetLanguage(pCCFieldInfo, t9_mode_info->nLdbNum, NULL, NULL);
    }

    if (sStatus == T9STATNONE)
    {
        sStatus = T9CCSetDynCtxtFence(pCCFieldInfo, MMI_IME_DYNAMIC_CONTEXT_FENCE);
    }
    if (sStatus == T9STATNONE)
    {
        sStatus = T9CCSetDynCtxtSearchDepth(pCCFieldInfo, MMI_IME_DYNAMIC_CONTEXT_SEARCH_DEPTH);
    }
    if (sStatus == T9STATNONE)
    {
        if (!(mode_details_ptr->flags & MMI_SMART_MODE))    /* multitap pinyin or smart bopomofo */
        {
            if (sStatus == T9STATNONE)
            {
                sStatus = T9CCSetMultitapSpellMode(pCCFieldInfo);
            }
            if (sStatus == T9STATNONE)
            {
                sStatus = T9CCSetMultitapSelListUpdate(pCCFieldInfo);
            }
        }
        else if (mode_detail_ptr->flags & MMI_SMART_MODE)   /* smart pinyin or smart bopomofo */
        {
            if (sStatus == T9STATNONE)
            {
                sStatus = T9CCSetAmbigSpellMode(pCCFieldInfo);
            }
            if (sStatus == T9STATNONE)
            {
                sStatus = T9CCClrAutoSpell(pCCFieldInfo);
            }
        }
    }

    if (sStatus == T9STATNONE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* #ifdef __T9_CHINESE */

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_init_alphabetic
 * DESCRIPTION
 * PARAMETERS
 *  t9_mode_info        [IN]        
 *  mode_detail_ptr     [?]         
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_ime_t9_init_alphabetic(mmi_ime_t9_mode_info_struct_p t9_mode_info, mmi_ime_mode_details_struct *mode_detail_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    T9STATUS    sStatus = T9STATNONE;

    T9AWFieldInfo *pAWFieldInfo;
    mmi_ime_t9_data_struct_p pDataBuff;
    mmi_ime_mode_details_struct *mode_details_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mode_details_ptr = (mmi_ime_mode_details_struct*) mmi_imm_get_input_mode_array_item();

    sStatus = T9STATNONE;

    pDataBuff = &g_engine.data;
    pAWFieldInfo = &g_engine.data.field_info.AWFieldInfo;

    sStatus = T9AWInitialize(pAWFieldInfo, pDataBuff->text_buff, pDataBuff->aux_buff, MMI_IME_T9_MAX_TEXT_BUFFSIZE, 0, (T9HandleRequest_f) T9_handle_request, (T9ReadLdbData_f) T9ReadLdbData);
    if (sStatus == T9STATNONE)
    {
        sStatus = T9AWSetLanguage(pAWFieldInfo, t9_mode_info->nLdbNum, &pAWFieldInfo->G, NULL);
    }
    if (sStatus == T9STATNONE)
    {
        if (!(mode_details_ptr->flags & MMI_SMART_MODE))    /* multitap input method */
        {
            sStatus = T9AWSetMultitapMode(pAWFieldInfo);
        }
        else if (mode_detail_ptr->flags & MMI_SMART_MODE)   /* smart input method */
        {
            sStatus = T9AWClrMultitapMode(pAWFieldInfo);
        }
    }

    T9AWSetLdbCompletion(pAWFieldInfo);

#if defined(__MMI_IME_USER_DATABASE__)

    sStatus = T9AWUdbActivate(&g_engine.data.field_info.AWFieldInfo, 
                             (T9AWUdbInfo T9FARUDBPOINTER *)&g_engine.data.udb_data[0],
                             MMI_IME_T9_UDB_SIZE,
                             T9AWDEFAULTUDBFENCE,
                             T9SCUnicode);

    if (sStatus != T9STATNONE)
    {
        return sStatus;
    }

    sStatus = T9AWCdbActivate(&g_engine.data.field_info.AWFieldInfo, 
                             (T9AWCdbInfo T9FARUDBPOINTER *)&g_engine.data.cdb_data[0],
                             MMI_IME_T9_CDB_SIZE,
                             T9SCUnicode);

    if (sStatus != T9STATNONE)
    {
        return sStatus;
    }

#endif /* defined(__MMI_IME_USER_DATABASE__) */

    if (sStatus == T9STATNONE || sStatus == T9STAT_MT_STK_INCOMP)
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
 *  mmi_ime_t9_get_candidates_alphabetic
 * DESCRIPTION
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ime_t9_get_candidates_alphabetic(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9STATUS sStatus = T9STATERROR;
    S32 i, j;
    T9MINOR t9_key;
    T9UINT cnt = 0;
    UI_string_type temp_ptr;
    S32 can_len;
    U32 index_before_punct_entered = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(param_ptr != NULL || result_ptr != NULL);

    if (0 == param_ptr->elembuf_cnt)
        return;

    sStatus = T9AWClearBuffer(&g_engine.data.field_info.AWFieldInfo);

    if (sStatus != T9STATNONE)
    {
        return;
    }

    for (i = 0; i < param_ptr->elembuf_cnt; i++)
    {
        t9_key = mmi_ime_t9_from_symb_to_t9key(param_ptr->elembuf_ptr[i]);

        if (t9_key)
        {
            sStatus = T9HandleKey(&g_engine.data.field_info.AWFieldInfo.G, t9_key);
            if (sStatus != T9STATNONE)
            {
                #if defined(__MMI_IME_USER_DATABASE__)
                if (sStatus == T9STATNOWRD && param_ptr->first_index == 0)
                {
                    result_ptr->result_cnt = 1;
                    result_ptr->next_page = MMI_FALSE;
                    result_ptr->result_buffer[0] = MMI_IME_USER_DATABASE_NEW_WORD;
                    result_ptr->result_buffer[1] = 0;
                 }
                #endif
                return;
            }
        }
        else
        {
            return;
        }
    }

    sStatus = T9AWGetSLCount(&g_engine.data.field_info.AWFieldInfo, &cnt);

    if (sStatus != T9STATNONE)
    {
        return;
    }

    if (param_ptr->first_index >= cnt)
    {
        return;
    }

    for (i = 0; i < param_ptr->first_index; i++)
    {
        sStatus = T9HandleKey(&g_engine.data.field_info.AWFieldInfo.G, T9KEYNEXT);
    }

    temp_ptr = result_ptr->result_buffer;
    j = 0;

    while (j < param_ptr->desired_cnt && j < cnt - i)
    {
        //memcpy(temp_ptr, g_engine.data.field_info.AWFieldInfo.G.psTxtBuf, 
        //         g_engine.data.field_info.AWFieldInfo.G.nWordLen * sizeof(UI_character_type));
		/*the below check is to skip the adding of candidates if the buffer gets full*/
		if ((((param_ptr->elembuf_cnt * sizeof(UI_character_type))+2)*j ) > MMI_IMC_MAX_CANDIDATE_BUFFSIZE)
		break;
        memcpy(temp_ptr, g_engine.data.field_info.AWFieldInfo.G.psTxtBuf, param_ptr->elembuf_cnt * sizeof(UI_character_type));
        /* temp_ptr += g_engine.data.field_info.AWFieldInfo.G.nWordLen; */
        temp_ptr += param_ptr->elembuf_cnt;
        *temp_ptr = 0;
        temp_ptr++;

        T9HandleKey(&g_engine.data.field_info.AWFieldInfo.G, T9KEYNEXT);

        j++;
    }

    result_ptr->result_cnt = j;

    if (param_ptr->desired_cnt < cnt - i)
    {
        result_ptr->next_page = MMI_TRUE;
    }
    else
    {
        result_ptr->next_page = MMI_FALSE;
    }

    if (result_ptr->result_cnt > 0)
    {
        mmi_ime_t9_change_candidates_case(result_ptr);
    }

#if defined(__MMI_IME_USER_DATABASE__)
    if ( result_ptr->result_cnt == 0 )
    {
        result_ptr->result_cnt = 1;
        result_ptr->next_page = MMI_FALSE;
        result_ptr->result_buffer[0] = MMI_IME_USER_DATABASE_NEW_WORD;
        result_ptr->result_buffer[1] = 0;
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_associates
 * DESCRIPTION
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ime_t9_get_associates(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
#if defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_T9_SM_CHINESE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9STATUS sStatus = T9STATERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param_ptr != NULL || result_ptr != NULL);

    if (0 != g_engine.data.field_info.CCFieldInfo.nKeyBufLen)
    {
        sStatus = T9CCDelAllKeys(&g_engine.data.field_info.CCFieldInfo);
        if (T9STATNONE != sStatus)
        {
            return;
        }
    }

    if (0 != g_engine.data.field_info.CCFieldInfo.G.nBufLen)
    {
        sStatus = T9HandleKey(&g_engine.data.field_info.CCFieldInfo.G, T9KEYCLEAR);
        if (T9STATNONE != sStatus)
        {
            return;
        }
    }

    g_engine.data.field_info.CCFieldInfo.nSelectPageMax = param_ptr->desired_cnt;

    sStatus = T9AddExplicitChar(&g_engine.data.field_info.CCFieldInfo.G, param_ptr->pre_string[0]);

    if (sStatus != T9STATERROR)
    {
        mmi_ime_t9_get_candidates(param_ptr, result_ptr);
    }
#endif /* defined(__MMI_T9_TR_CHINESE__) || defined(__MMI_T9_SM_CHINESE__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_candidates
 * DESCRIPTION
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ime_t9_get_candidates(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9UINT first_index, first_part_size;
    T9STATUS sStatus = T9STATERROR;
    UI_character_type candidate_buffer[MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE + 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param_ptr != NULL || result_ptr != NULL);
#ifdef __T9_CHINESE
    first_index = (T9UINT) param_ptr->first_index;

    result_ptr->next_page = MMI_FALSE;

    while (first_index >= g_engine.data.field_info.CCFieldInfo.nSelectPageLen)
    {
        first_index = first_index - g_engine.data.field_info.CCFieldInfo.nSelectPageLen;

        sStatus = T9HandleKey(&g_engine.data.field_info.CCFieldInfo.G, T9KEYNEXT);

        if (T9STATNONE != sStatus)
        {
            return;
        }
    }

    first_part_size = g_engine.data.field_info.CCFieldInfo.nSelectPageLen - first_index;

    if (first_part_size > 0)
    {
        memcpy(candidate_buffer, &g_engine.data.field_info.CCFieldInfo.pwSelectPage[first_index], first_part_size * sizeof(UI_character_type)); /* Single char candidate */
    }

    if (first_part_size < g_engine.data.field_info.CCFieldInfo.nSelectPageMax)
    {
        if (!(g_engine.data.field_info.CCFieldInfo.wChineseState & T9CCSTATEMORE))
        {
            result_ptr->result_cnt = first_part_size;
            result_ptr->next_page = MMI_FALSE;
        }
        else
        {
            sStatus = T9HandleKey(&g_engine.data.field_info.CCFieldInfo.G, T9KEYNEXT);

            if (T9STATNONE != sStatus || 0 == g_engine.data.field_info.CCFieldInfo.nSelectPageLen)
            {
                result_ptr->result_cnt = first_part_size;
                result_ptr->next_page = MMI_FALSE;
            }

            if (g_engine.data.field_info.CCFieldInfo.nSelectPageLen >= g_engine.data.field_info.CCFieldInfo.nSelectPageMax - first_part_size)
            {
                memcpy(&candidate_buffer[first_part_size], g_engine.data.field_info.CCFieldInfo.pwSelectPage, (g_engine.data.field_info.CCFieldInfo.nSelectPageMax - first_part_size) * sizeof(UI_character_type));     /* Single char candidate */

                sStatus = T9HandleKey(&g_engine.data.field_info.CCFieldInfo.G, T9KEYNEXT);

                result_ptr->result_cnt = g_engine.data.field_info.CCFieldInfo.nSelectPageMax;

                if (g_engine.data.field_info.CCFieldInfo.wChineseState & T9CCSTATEMORE)
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
                memcpy(&candidate_buffer[first_part_size], g_engine.data.field_info.CCFieldInfo.pwSelectPage, g_engine.data.field_info.CCFieldInfo.nSelectPageLen * sizeof(UI_character_type)); /* Single char candidate */

                result_ptr->result_cnt = first_part_size + g_engine.data.field_info.CCFieldInfo.nSelectPageLen;

                result_ptr->next_page = MMI_FALSE;
            }
        }
    }
    else if (first_part_size == g_engine.data.field_info.CCFieldInfo.nSelectPageMax)
    {
        if (g_engine.data.field_info.CCFieldInfo.wChineseState & T9CCSTATEMORE)
        {
            result_ptr->result_cnt = g_engine.data.field_info.CCFieldInfo.nSelectPageMax;
            result_ptr->next_page = MMI_TRUE;
        }
        else
        {
            result_ptr->result_cnt = first_part_size;
            result_ptr->next_page = MMI_FALSE;
        }
    }

    if (result_ptr->result_cnt > 0)
    {
        mmi_ime_word_add_separator_to_candidate_buffer(result_ptr->result_buffer, candidate_buffer, result_ptr->result_cnt);
    }
#endif /* __T9_CHINESE */ 
}

#if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__)


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_stroke
 * DESCRIPTION
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_stroke(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 symb;
    UI_string_type temp_str;
    T9STATUS sStatus = T9STATERROR;
    T9MINOR t9_key;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param_ptr != NULL || result_ptr != NULL);

    if (0 == param_ptr->elembuf_cnt)
        return;

    temp_str = result_ptr->result_buffer;

    T9ResetTextBuf(&g_engine.data.field_info.CCFieldInfo.G, MMI_IME_T9_MAX_TEXT_BUFFSIZE);

    for (i = 0; i < param_ptr->elembuf_cnt; ++i)
    {
        symb = param_ptr->elembuf_ptr[i];
        t9_key = mmi_ime_t9_from_symb_to_t9key(symb);

        if (MMI_FALSE != MMI_IMC_IS_SYMB_KEY(symb))
        {
            if (t9_key)
            {
                sStatus = T9HandleKey(&g_engine.data.field_info.CCFieldInfo.G, t9_key);

                if (T9STATNONE != sStatus)
                {
                    return;
                }

                *temp_str = mmi_ime_word_symbol_to_code((U8) g_t9_keys_stroke[symb - MMI_IMC_SYMB_KEY_BASE]);
                temp_str++;
            }
            else    /* Invalid key */
            {
                return;
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
 *  mmi_ime_t9_get_candidates_stroke
 * DESCRIPTION
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ime_t9_get_candidates_stroke(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9STATUS sStatus = T9STATERROR;
    U8 i;
    U8 symb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param_ptr != NULL || result_ptr != NULL);

    T9ResetTextBuf(&g_engine.data.field_info.CCFieldInfo.G, MMI_IME_T9_MAX_TEXT_BUFFSIZE);

    for (i = 0; i < param_ptr->elembuf_cnt; ++i)
    {
        symb = param_ptr->elembuf_ptr[i];

        if (MMI_FALSE != MMI_IMC_IS_SYMB_STROKE(symb))
        {
            sStatus = T9HandleKey(&g_engine.data.field_info.CCFieldInfo.G, g_t9_codes_stroke[symb - MMI_IMC_SYMB_STROKE_BASE]);

            if (T9STATNONE != sStatus)
            {
                return;
            }
        }
        else
        {
            return;
        }
    }

    g_engine.data.field_info.CCFieldInfo.nSelectPageMax = param_ptr->desired_cnt;

    mmi_ime_t9_get_candidates(param_ptr, result_ptr);
}

#endif /* defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */ /* #if defined(__MMI_T9_SM_CHINESE__) || defined(__MMI_T9_TR_CHINESE__) */

#if defined(__MMI_T9_SM_CHINESE__)

#if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_pinyin_multitap
 * DESCRIPTION
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_pinyin_multitap(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    UI_string_type temp_str;
    U8 symb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(param_ptr != NULL || result_ptr != NULL);

    if (0 == param_ptr->elembuf_cnt)
        return;

    temp_str = result_ptr->result_buffer;

    for (i = 0; i < param_ptr->elembuf_cnt; i++)
    {
        symb = param_ptr->elembuf_ptr[i];
        if (MMI_FALSE != MMI_IMC_IS_SYMB_PY(symb))
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

#endif /* defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */ /* #if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */

#if defined(__MMI_T9_SMART_PHONETIC_INPUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_pinyin_smart
 * DESCRIPTION
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_pinyin_smart(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 ret_val;
    U8 i;
    U16 j;
    U8 k;
    T9STATUS status;
    T9MINOR key_val;
    T9U8 *buff_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_ASSERT(param_ptr != NULL || result_ptr != NULL);

    result_ptr->result_cnt = 0;

    if (MMI_FALSE == g_engine.is_inited)
        return;

    status = T9ResetTextBuf(&g_engine.data.field_info.CCFieldInfo.G, MMI_IME_T9_MAX_TEXT_BUFFSIZE);

    if (T9STATNONE != status)
    {
        /* add error */
        return;
    }

    for (i = 0; i < param_ptr->elembuf_cnt; i++)
    {
        key_val = mmi_ime_t9_from_symb_to_t9key(param_ptr->elembuf_ptr[i]);

        status = T9HandleKey(&g_engine.data.field_info.CCFieldInfo.G, key_val);
        if (T9STATNONE != status)
        {
            /* add error */
            return;
        }
    }

    status = T9CCGetSpell(&g_engine.data.field_info.CCFieldInfo);

    if (status != T9STATNONE)
        return;

    ret_val = g_engine.data.field_info.CCFieldInfo.bSpellMatchFromLdb;  /* Revise by UDB */

    if (0 == ret_val || param_ptr->first_index >= ret_val)
        return;

    /* calculate remaining candidates count */
    ret_val = ret_val - param_ptr->first_index;

    if (ret_val > param_ptr->desired_cnt)
    {
        ret_val = param_ptr->desired_cnt;
        result_ptr->next_page = MMI_TRUE;
    }
    else
    {
        result_ptr->next_page = MMI_FALSE;
    }

    result_ptr->result_cnt = ret_val;

    buff_ptr = g_engine.data.field_info.CCFieldInfo.pbSpellBuf;

    i = 0;
    j = 0;

    /* Go to the first character of the index of the spellings */
    while (buff_ptr[i] != '\0' && j < param_ptr->first_index)
    {
        if (buff_ptr[i++] == ' ')
        {
            j++;
        }
    }

    if (j == param_ptr->first_index)
    {
        k = 0;
        /* Copy the spelling buffer to  the result buffer */
        for (j = 0; buff_ptr[i] != '\0' && k < result_ptr->result_cnt;)
        {
            if (buff_ptr[i] == ' ')
            {
                result_ptr->result_buffer[j] = 0;
            }
            else
            {
                result_ptr->result_buffer[j] = mmi_ime_t9_t9code_to_code(buff_ptr[i], g_engine.t9_mode_info->input_mode);
            }

            j++;
            i++;

            if (buff_ptr[i] == ' ')
            {
                k++;
            }
        }
    }

    result_ptr->result_buffer[j] = 0;
}
#endif /* defined(__MMI_T9_SMART_PHONETIC_INPUT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_candidates_pinyin
 * DESCRIPTION
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ime_t9_get_candidates_pinyin(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9STATUS status;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(param_ptr != NULL || result_ptr != NULL);

	status = T9ResetTextBuf(&g_engine.data.field_info.CCFieldInfo.G, MMI_IME_T9_MAX_TEXT_BUFFSIZE);

    if (T9STATNONE != status)
    {
        /* add error */
        return;
    }

    for (i = 0; i < param_ptr->elembuf_cnt; i++)
    {
        if (MMI_IMC_IS_SYMB_PY(param_ptr->elembuf_ptr[i]))
        {
            status = T9CCAddExplicitSpellSym(&g_engine.data.field_info.CCFieldInfo, g_t9_codes_pinyin[param_ptr->elembuf_ptr[i] - MMI_IMC_SYMB_PY_BASE]);
        }
        else
        {
            return;
        }

        if (T9STATNONE != status)
        {
            /* add error */
            return;
        }
    }

	if (MMI_IMC_IS_SYMB_TONE(param_ptr->tone_value))
    {
        status = T9CCSetTone(&g_engine.data.field_info.CCFieldInfo, g_t9_codes_tone[param_ptr->tone_value - MMI_IMC_SYMB_TONE_BASE]);
    }

    if (T9STATNONE != status)
    {
        /* add error */
        return;
    }

    mmi_ime_t9_get_candidates(param_ptr, result_ptr);
}

#endif /* defined(__MMI_T9_SM_CHINESE__) */ 

#if defined(__MMI_T9_TR_CHINESE__)

#if defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_zhuyin_multitap
 * DESCRIPTION
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_zhuyin_multitap(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    UI_string_type temp_str;
    U8 symb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param_ptr != NULL || result_ptr != NULL);

    MMI_ASSERT(param_ptr != NULL || result_ptr != NULL);

    if (0 == param_ptr->elembuf_cnt)
        return;

    temp_str = result_ptr->result_buffer;

    for (i = 0; i < param_ptr->elembuf_cnt; i++)
    {
        symb = param_ptr->elembuf_ptr[i];
        if (MMI_FALSE != MMI_IMC_IS_SYMB_ZY(symb))
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
#endif /* defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__) */ 

#if (defined(__MMI_T9_SMART_PHONETIC_INPUT__) && defined(__MMI_T9_AMB_BPMF_INPUT__))


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_spellings_zhuyin_smart
 * DESCRIPTION
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ime_t9_get_spellings_zhuyin_smart(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret_val;
    U8 i;
    U16 j;
    U8 k;
    T9STATUS status;
    T9MINOR key_val;
    T9U8 *buff_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(param_ptr != NULL || result_ptr != NULL);

    result_ptr->result_cnt = 0;

    if (MMI_FALSE == g_engine.is_inited)
        return;

    status = T9ResetTextBuf(&g_engine.data.field_info.CCFieldInfo.G, MMI_IME_T9_MAX_TEXT_BUFFSIZE);

    if (T9STATNONE != status)
    {
        /* add error */
        return;
    }

    for (i = 0; i < param_ptr->elembuf_cnt; i++)
    {
        key_val = mmi_ime_t9_from_symb_to_t9key(param_ptr->elembuf_ptr[i]);

        status = T9HandleKey(&g_engine.data.field_info.CCFieldInfo.G, key_val);
        if (T9STATNONE != status)
        {
            /* add error */
            return;
        }
    }

    status = T9CCGetSpell(&g_engine.data.field_info.CCFieldInfo);

    if (status != T9STATNONE)
        return;

    ret_val = g_engine.data.field_info.CCFieldInfo.bSpellMatchFromLdb;  /* Revise by UDB */

    if (0 == ret_val || param_ptr->first_index >= ret_val)
        return;

    /* calculate remaining candidates count */
    ret_val = ret_val - param_ptr->first_index - 1;

    if (ret_val > param_ptr->desired_cnt)
    {
        ret_val = param_ptr->desired_cnt;
        result_ptr->next_page = MMI_TRUE;
    }
    else
    {
        result_ptr->next_page = MMI_FALSE;
    }

    result_ptr->result_cnt = ret_val;

    buff_ptr = g_engine.data.field_info.CCFieldInfo.pbSpellBuf;

    i = 0;
    j = 0;

    /* Go to the first character of the index of the spellings */
    while (buff_ptr[i] != '\0' && j < param_ptr->first_index)
    {
        if (buff_ptr[i++] == ' ')
        {
            j++;
        }
    }

    if (j == param_ptr->first_index)
    {
        k = 0;
        /* Copy the spelling buffer to  the result buffer */
        for (j = 0; buff_ptr[i] != '\0' && k < result_ptr->result_cnt;)
        {
            if (buff_ptr[i] == ' ')
            {
                result_ptr->result_buffer[j] = 0;
            }
            else
            {
                result_ptr->result_buffer[j] = mmi_ime_t9_t9code_to_code(buff_ptr[i], g_engine.input_mode);
            }

            j++;
            i++;

            if (buff_ptr[i] == ' ')
            {
                k++;
            }
        }
    }

    result_ptr->result_buffer[j] = 0;
}
#endif /* defined(__MMI_T9_SMART_PHONETIC_INPUT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_candidates_zhuyin
 * DESCRIPTION
 * PARAMETERS
 *  param_ptr       [IN]        
 *  result_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ime_t9_get_candidates_zhuyin(mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9STATUS status;
    S32 i;
    T9KEY tone_key = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param_ptr != NULL || result_ptr != NULL);

    status = T9AddExplicitChar(&g_engine.data.field_info.CCFieldInfo.G, 0x4e00);        /* Reset T9 internal symbol and key buffer */

    if (T9STATNONE != status)
    {
        /* add error */
        return;
    }

    for (i = 0; i < param_ptr->elembuf_cnt; i++)
    {
        if (MMI_IMC_IS_SYMB_ZY(param_ptr->elembuf_ptr[i]))
        {
            status = T9CCAddExplicitSpellSym(&g_engine.data.field_info.CCFieldInfo, g_t9_codes_zhuyin[param_ptr->elembuf_ptr[i] - MMI_IMC_SYMB_ZY_BASE]);
        }
        else if (i == param_ptr->elembuf_cnt - 1 && MMI_IMC_IS_SYMB_TONE(param_ptr->elembuf_ptr[i]))
        {
            tone_key = g_t9_codes_tone[param_ptr->elembuf_ptr[i] - MMI_IMC_SYMB_TONE_BASE];
        }
        else
        {
            return;
        }

        if (T9STATNONE != status)
        {
            /* add error */
            return;
        }
    }

    /* status = T9CCSpecifySpell(&g_engine.data.field_info.CCFieldInfo, 1); */

    if (tone_key)
    {
        status = T9CCSetTone(&g_engine.data.field_info.CCFieldInfo, tone_key);
    }

    if (T9STATNONE != status)
    {
        /* add error */
        return;
    }

    mmi_ime_t9_get_candidates(param_ptr, result_ptr);
}
#endif /* defined(__MMI_T9_TR_CHINESE__) */ 


/*****************************************************************************
 * FUNCTION
 *  T9_handle_request
 * DESCRIPTION
 * PARAMETERS
 *  field_info_ptr      [IN]     
 *  request_ptr         [IN]     
 * RETURNS
 *****************************************************************************/
T9STATUS T9_handle_request(T9FieldInfo *field_info_ptr, T9Request *request_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    T9STATUS status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (request_ptr->eType)
    {
        case T9REQMULTITAPSYM:
            status = T9STATNONE;
            break;

        default:
            status = T9STATNONE;
            break;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_from_symb_to_t9key
 * DESCRIPTION
 * PARAMETERS
 *  symb_key        [IN]        
 * RETURNS
 *****************************************************************************/
static T9MINOR mmi_ime_t9_from_symb_to_t9key(U16 symb_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_engine.key_map_ptr)
        return T9KEYNONE;

    if (symb_key >= MMI_IMC_SYMB_KEY_0 && symb_key <= MMI_IMC_SYMB_KEY_POUND)
    {
        return g_engine.key_map_ptr[symb_key - MMI_IMC_SYMB_KEY_BASE];
    }

    return T9KEYNONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_change_candidates_case
 * DESCRIPTION
 * PARAMETERS
 *  result_str      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ime_t9_change_candidates_case(mmi_ime_query_result_struct_p result_str)
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
            result_str->result_buffer[i] = (UI_character_type) mmi_ime_word_toupper((U16) result_str->result_buffer[i]);
            i++;

            while (result_str->result_buffer[i])
            {
                result_str->result_buffer[i] = (UI_character_type) mmi_ime_word_toupper((U16) result_str->result_buffer[i]);
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
            result_str->result_buffer[i] = (UI_character_type) mmi_ime_word_tolower((U16) result_str->result_buffer[i]);
            i++;

            while (result_str->result_buffer[i])
            {
                result_str->result_buffer[i] = (UI_character_type) mmi_ime_word_tolower((U16) result_str->result_buffer[i]);
                i++;
            }
            i++;
            j++;
        }
    }
}

#ifdef __MMI_T9_MULTITAP__

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_multitap_vendor_init
 * DESCRIPTION
 * Initialize T9 core for multitap input
 * PARAMETERS
 * RETURNS
 *****************************************************************************/


MMI_BOOL mmi_ime_multitap_vendor_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ime_word_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_multitap_vendor_deinit
 * DESCRIPTION
 * DEInitialize T9 core for multitap input(Dummy for now)
 * PARAMETERS
 * RETURNS
 *****************************************************************************/

void mmi_ime_multitap_vendor_deinit()
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
 *  mmi_ime_multitap_vendor_change_mode
 * DESCRIPTION
 * Changes input mode to t9 multitap mode
 * PARAMETERS
 * RETURNS
 *****************************************************************************/

MMI_BOOL mmi_ime_multitap_vendor_change_mode( const sIMEModeDetails *mode_details_ptr, U32 reserved )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_ime_word_change_mode( mode_details_ptr, reserved );
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_multitap_vendor_valid_key_check
 * DESCRIPTION
 * API to validate a key as a T9 multitap key
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_ime_multitap_vendor_valid_key_check( mmi_imc_symbol_key_enum sym)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ime_word_is_symbol_key(g_engine.input_mode, sym);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_multitap_vendor_get_string
 * DESCRIPTION
 * Returns string of characters mapped on Input T9 multitap key
 * PARAMETERS
 * RETURNS
 * UI_string_type  str_ptr to string mapped on input key for current input mode
 *****************************************************************************/

static UI_string_type mmi_ime_multitap_vendor_get_string(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    T9STATUS    status;
    T9MINOR     t9key;
    T9MINOR     ret_val;
    T9MINOR     i;
    UI_string_type  str_ptr;
    T9SYMB          *page_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    t9key = mmi_ime_t9_from_symb_to_t9key( index + MMI_IMC_SYMB_KEY_BASE);
    if ( t9key == T9KEYNONE )
        return NULL;
        
    page_ptr = g_engine.data.multitap_page;
    /* setting the case in which candidates are to be extracted */
    if( (g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_LOWER) || (g_engine.case_type ==MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER))
    {
        status = T9AWClrCapState( &g_engine.data.field_info.AWFieldInfo );
    }
    else if (g_engine.case_type == MMI_IME_WORD_CAPITAL_STATE_UPPER)
    {
        status = T9AWSetCapState( &g_engine.data.field_info.AWFieldInfo );
    }
    
    status = T9GetMultitapTable( &g_engine.data.field_info.AWFieldInfo.G, t9key, 1, MMI_MULTITAP_T9_PAGE_BUFFSIZE, page_ptr, &ret_val );

    if ( T9STATNONE != status )
        return NULL;

    str_ptr = g_engine.data.multitap_string;
/* to make sure space comes in multitap mode  on key 0*/
    if ( t9key == T9KEYAMBIGA && g_engine.input_mode != IMM_INPUT_MODE_MULTITAP_THAI)
    {
        str_ptr[0]  = (UI_character_type)0x20;
        for ( i = 1; i < ret_val+1; ++i )
        {
            str_ptr[i] = (UI_character_type)page_ptr[i-1];
        }
     }
    else
    {
        for ( i = 0; i < ret_val; ++i )
        {
            str_ptr[i] = (UI_character_type)page_ptr[i];
        }
    
    }
    str_ptr[i] = '\0';
    return str_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_multitap_vendor_query_key_check_function
 * DESCRIPTION
 * returns Fuction pointer which checks for an input mode   whether input MMI 
 * Key is a multitap key or not
 * returns key check function pointer for the current Multitap T9
 * PARAMETERS
 * mmi_imm_input_mode_enum Input Mode [IN] for which get_string function is needed
 * RETURNS
 * Pointer to function which checks input key being multitap key or not
 *****************************************************************************/

valid_key_check_func mmi_ime_multitap_vendor_query_key_check_function( mmi_imm_input_mode_enum input_mode )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_t9_mode_info_struct_p      mode_info_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( MMI_FALSE == g_engine.is_inited )
        return NULL;

    mode_info_ptr = (mmi_ime_t9_mode_info_struct_p)mmi_ime_t9_get_mode_info(input_mode);

    if (mode_info_ptr)
    {
        return mmi_ime_multitap_vendor_valid_key_check;
    }
    else
    {
       return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_multitap_vendor_get_string_func
 * DESCRIPTION
 * returns Fuction pointer which returns string for a given t9 multitap key
 * PARAMETERS
 * mmi_imm_input_mode_enum Input Mode [IN] for which get_string function is needed
 * RETURNS
 * Pointer to function which returns key string for input mmi key
 *****************************************************************************/

get_multitap_string mmi_ime_multitap_vendor_get_string_func( mmi_imm_input_mode_enum input_mode )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_t9_mode_info_struct_p      mode_info_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( MMI_FALSE == g_engine.is_inited )
        return NULL;
  
    mode_info_ptr = (mmi_ime_t9_mode_info_struct_p)mmi_ime_t9_get_mode_info(input_mode);

    if (mode_info_ptr)
    {
        return mmi_ime_multitap_vendor_get_string;
    }
    else
    {
        return NULL;
    }

}

#endif /* #ifdef __MMI_T9_MULTITAP__ */

#if defined(__MMI_MIXED_LANG_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_get_lang_ldb
 * DESCRIPTION
 * returns t9 ldb number corresponding to a writing language
 * PARAMETERS
 * mmi_imm_support_writing_lang_enum writing_lang
 * RETURNS
 *****************************************************************************/
T9UINT mmi_ime_t9_get_lang_ldb(mmi_imm_support_writing_lang_enum writing_lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U32 i =0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(writing_lang_ldb_map[i].writing_lang != NULL)
    {

        if(writing_lang_ldb_map[i].writing_lang == writing_lang)
            return writing_lang_ldb_map[i].ldb_num;
        else
            i++;
	
    }
    return NULL;
}

#endif

#if defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_SMART_FIRST_UPPERCASE__)
#endif /* #if defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_SMART_FIRST_UPPERCASE__) */

#if defined(__MMI_IME_USER_DATABASE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_add_new_word
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_ime_word_add_new_word_ret_value_enum mmi_ime_word_add_new_word(mmi_imm_input_mode_enum input_mode, UI_string_type str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_t9_mode_info_struct_p  mode_info_p;
    T9STATUS status;
    UI_character_type str_buf[MMI_IMC_MAX_PRE_STRING_LEN + 1];
    S32 i, str_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mode_info_p = (mmi_ime_t9_mode_info_struct_p)mmi_ime_t9_get_mode_info(input_mode);
    
    
    if (mode_info_p == NULL)
        return MMI_IME_WORD_ADD_NEW_WORD_FAILED;
    
    if (mode_info_p->init_type == MMI_IME_T9_INIT_TYPE_ALPHABETIC)
    {
        str_len = mmi_ucs2strlen((const S8 *)str_ptr);

        for (i = 0; i < str_len; i++)
        {
            str_buf[i] = mmi_towlower(str_ptr[i]);
        }
    
        str_buf[i] = 0;
        
        status = T9AWUdbScanBufForCustWords(&g_engine.data.field_info.AWFieldInfo, 
                                             (T9SYMB *)str_buf, 
                                             (T9MINOR)str_len);
        if ( T9STATNONE != status )
        {
            return MMI_IME_WORD_ADD_NEW_WORD_FAILED;
        }
        else
        {
            return MMI_IME_WORD_ADD_NEW_WORD_SUCCESS;
        }
    }
    else
    {
        return MMI_IME_WORD_ADD_NEW_WORD_FAILED;
    }
    
    


}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_update_word_frequency
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_ime_word_scan_and_add_new_words(UI_string_type str_ptr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, str_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	str_len = mmi_ucs2strlen((const S8 *)str_ptr);
	
	for (i = 0; i < str_len; i++)
	{
		str_ptr[i] = mmi_towlower(str_ptr[i]);
	}
    
	str_ptr[i] = 0;
	
	T9AWUdbScanBufForCustWords(&g_engine.data.field_info.AWFieldInfo, (T9SYMB *)str_ptr, (T9MINOR)str_len);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_update_word_frequency
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_update_word_frequency(mmi_imm_input_mode_enum input_mode, UI_string_type str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_t9_mode_info_struct_p  mode_info_p;
    T9STATUS status = T9STATNONE;
    T9UINT cnt = 0;
    S32 i, str_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mode_info_p = (mmi_ime_t9_mode_info_struct_p)mmi_ime_t9_get_mode_info(input_mode);
    

    if (mode_info_p == NULL)
	{
	    return MMI_FALSE;
	}
    
    if (mode_info_p->init_type == MMI_IME_T9_INIT_TYPE_ALPHABETIC)
    {
        status = T9AWGetSLCount(&g_engine.data.field_info.AWFieldInfo, &cnt);

        if (status != T9STATNONE)
        {
            return MMI_FALSE;
        }

        if (cnt > 0)
        {
            str_len = mmi_ucs2strlen((const S8 *) str_ptr);
            
            for (i = 0; i < cnt; i++)
            {
				/* Inform T9 we have confirmed this candidate by inject T9KEYSPACE */
                if (g_engine.data.field_info.AWFieldInfo.G.nWordLen != 0
					&& !mmi_ucs2nicmp((const S8 *) g_engine.data.field_info.AWFieldInfo.G.psTxtBuf, (const S8 *) str_ptr, str_len) 
                    && g_engine.data.field_info.AWFieldInfo.G.nWordLen + g_engine.data.field_info.AWFieldInfo.G.nComplLen == str_len)
                {
                    status = T9HandleKey(&g_engine.data.field_info.AWFieldInfo.G, T9KEYSPACE);
                    
                    if (status != T9STATNONE)
                    {
                        return MMI_FALSE;
                    }
                    else  
                    {
                        return MMI_TRUE;
                    }
                }
				else if (g_engine.data.field_info.AWFieldInfo.G.nWordLen == 0 
					     && !mmi_ucs2nicmp((const S8 *) (g_engine.data.field_info.AWFieldInfo.G.psTxtBuf + g_engine.data.field_info.AWFieldInfo.G.nCursor),  
						                   (const S8 *) str_ptr, str_len) 
                         && g_engine.data.field_info.AWFieldInfo.G.nComplLen == str_len) /* For next word prediction mode */
                {
                    status = T9HandleKey(&g_engine.data.field_info.AWFieldInfo.G, T9KEYSPACE);
                    
                    if (status != T9STATNONE)
                    {
                        return MMI_FALSE;
                    }
                    else  
                    {
					   return MMI_TRUE;
                    }
                }
                else
                {
                    status = T9HandleKey(&g_engine.data.field_info.AWFieldInfo.G, T9KEYNEXT);

                    if (status != T9STATNONE)
                    {
                        return MMI_FALSE;
                    }
                }
            }

            return MMI_FALSE;
        }
        else
        {
            return MMI_FALSE;
        }
    }

    if ( T9STATNONE != status )
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_load_user_database
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_load_user_database(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&g_engine.data.udb_data[0], 0, sizeof(U16) * MMI_IME_T9_UDB_SIZE / 2);   

    memset(&g_engine.data.cdb_data[0], 0, sizeof(U16) * MMI_IME_T9_CDB_SIZE / 2);   

    file_handle = mmi_ime_t9_open_file(MMI_IME_USER_DATABASE_PATH, MMI_IME_USER_DATABASE_FILE_UDB, MMI_TRUE);
    
    if (file_handle == -1)
        return MMI_FALSE;

    mmi_ime_t9_read_file(file_handle, &g_engine.data.udb_data[0], sizeof(U16) * MMI_IME_T9_UDB_SIZE / 2);
    
    mmi_ime_t9_close_file(file_handle);

    file_handle = mmi_ime_t9_open_file(MMI_IME_USER_DATABASE_PATH, MMI_IME_USER_DATABASE_FILE_CDB, MMI_TRUE);
    
    if (file_handle == -1)
        return MMI_FALSE;

    mmi_ime_t9_read_file(file_handle, &g_engine.data.cdb_data[0], sizeof(U16) * MMI_IME_T9_CDB_SIZE / 2);
    
    mmi_ime_t9_close_file(file_handle);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_save_user_database
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_ime_word_save_user_database(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_handle = mmi_ime_t9_open_file(MMI_IME_USER_DATABASE_PATH, MMI_IME_USER_DATABASE_FILE_UDB, MMI_TRUE);
    
    if (file_handle == -1)
        return MMI_FALSE;

    mmi_ime_t9_write_file(file_handle, &g_engine.data.udb_data[0], sizeof(U16) * MMI_IME_T9_UDB_SIZE / 2);
    mmi_ime_t9_close_file(file_handle);

    file_handle = mmi_ime_t9_open_file(MMI_IME_USER_DATABASE_PATH, MMI_IME_USER_DATABASE_FILE_CDB, MMI_TRUE);
    
    if (file_handle == -1)
        return MMI_FALSE;

    mmi_ime_t9_write_file(file_handle, &g_engine.data.cdb_data[0], sizeof(U16) * MMI_IME_T9_CDB_SIZE / 2);
    mmi_ime_t9_close_file(file_handle);

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_open_file
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
static FS_HANDLE mmi_ime_t9_open_file(PU16 path_name_ptr, PU16 file_name_ptr, MMI_BOOL is_create_always)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int ret_val;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != path_name_ptr);
    MMI_ASSERT(NULL != file_name_ptr);

    ret_val = FS_SetCurrentDir(path_name_ptr);
    if (ret_val < 0)
    {
        ret_val = FS_CreateDir(path_name_ptr);
        if (ret_val < 0 )
        {
            return -1;
        }
        ret_val = FS_SetCurrentDir(path_name_ptr);
        if (ret_val < 0)
        {
            return -1;
        }
    }

    FS_SetAttributes(file_name_ptr, FS_ATTR_ARCHIVE);

    /* try to open file */
    file_handle = FS_Open(file_name_ptr, FS_READ_WRITE | FS_ATTR_ARCHIVE);
    if (file_handle < 0)    /* failed to open existing file, or file not exists */
    {
        if (MMI_FALSE == is_create_always)
        {
            return -1;
        }

        /* try to create file */
        file_handle = FS_Open(file_name_ptr, FS_READ_WRITE | FS_CREATE_ALWAYS | FS_ATTR_ARCHIVE);
        if (file_handle < 0)
        {
            return -1;
        }
    }

    return file_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_close_file
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
static void mmi_ime_t9_close_file(FS_HANDLE file_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_handle < 0)
        return;

    FS_Close(file_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_write_file
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static U32 mmi_ime_t9_write_file(FS_HANDLE file_handle, PU16 data_ptr, U32 size_in_byte)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret_val;
    U32 writen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_handle < 0)
        return 0;

    writen = 0;
    ret_val = FS_Write(file_handle, (void*)data_ptr, size_in_byte, &writen);
    if (ret_val < 0)
        return 0;

    return writen;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_t9_read_file
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static U32 mmi_ime_t9_read_file(FS_HANDLE file_handle, PU16 data_ptr, U32 size_in_byte)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret_val;
    U32 readed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_handle < 0)
        return 0;

    readed = 0;
    ret_val = FS_Read(file_handle, (void*)data_ptr, size_in_byte, &readed);
    if (ret_val < 0)
        return 0;

    return readed;
}


#endif /* defined(__MMI_IME_USER_DATABASE__) */
#endif /* __MMI_T9__ */ /* #ifdef  __MMI_T9__ */

